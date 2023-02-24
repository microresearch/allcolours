/// from here
static inline uint32_t countbits(uint32_t i)
{
  /*
  i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
  i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
  return (i * 0x01010101) >> 24;          // horizontal sum of bytes
  */
     return( countbts[i&0xFFFF] + countbts[i>>16] );
}
  



static inline uint8_t probableCV(uint32_t reg, uint32_t type){
  // LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
  // prob of cycling bit let's say or ADC bit in or...
  switch(type){  case 0:
    if ((LFSR_[reg] & 4095 )< (gate[reg].shift_& 4095))      return 1;
    break;
  case 1:
    if ((LFSR_[reg] & 4095 )< (gate[dacfrom[daccount][reg]].shift_ & 4095))      return 1;
    break;
  case 2:
    if ((gate[reg].shift_ & 4095 )< (gate[dacfrom[daccount][reg]].shift_ & 4095))      return 1;
    break;
  case 3:
    //    if ((LFSR_[reg] & 4095 ) < (param[reg] & 4095))      return 1;
    break;
  }    
  return 0;
}

static inline uint8_t otherprobableCV(uint32_t reg, uint32_t type){ // this one is 2 bits
  // LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
  // prob of cycling bit let's say or ADC bit in or...
  switch(type){
  case 0:
    if ((LFSR_[reg] & 4095 )< (gate[reg].shift_& 4095))      return 1;
    break;
  case 1:
    if ((LFSR_[reg] & 4095 )< (gate[dacfrom[daccount][reg]].shift_ & 4095))      return 1;
    break;
  case 2:
    //    if ((LFSR_[reg] & 4095 ) < (param[reg] & 4095))      return 1;
    break;
  }    
  return 0;
}

// 19/1/22 return of more generic ADC_ in = so income is passed in function and can be DAC+ADC etc so we have different handlings
// 7 modes
static inline int ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t *SR, uint32_t income){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator=0, oldValue=0;
  static uint32_t k;//, lastbt[4]={0}; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  //  static uint8_t lc=0;
  uint32_t bt=0, bit=0;

  switch(type){
  case 0: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(income)>>(11-length);
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 1: // equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      k=(income); //
      k=k/divy[length];
      n[reg]=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    n[reg]++;    
    break;

  case 2: // variations on one bit audio - also phasey - sigma-delta - FIX 
    k=(income); // from 0 to 4095 but where is the middle? - also we do nothing here with length
    integrator+=(k-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;    

  case 3: // basic sequential length as in 0 but with padding if >11 bits **
    // as above but closer to 5
    // also try as MSB - now...
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	k=(income)>>(11-length);
	n[reg]=length;
      }
      else {
	k=(income);
	n[reg]=length; // changed 14/3/2022
      }
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 4:  // special case for spaced bit entry depending on length
    *SR &=spacmask[length]; //cleared
    k=(income)>>8; // we want 4 bits
    *SR+=(k&1)+((k&2)<<spacc[length][0])+((k&4)<<spacc[length][1])+((k&8)<<spacc[length][2]);
    // 4 bits goes in
    // no bt return
    bt=0;
    break;   
    
  case 5: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc... // ***
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k=(income);
	n[reg]=11;
    }
    bt = (k>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 6: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc... // ***
    if (n[reg]<0) { // 8 bits
	k=(income>>4);
	n[reg]=7;
    }
    bt = (k>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 7: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc... // ***
    if (n[reg]<0) { // 4 bits
	k=(income>>8);
	n[reg]=3;
    }
    bt = (k>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;
  }
  return bt;
}
  
///////////////////////////////////////////
/*
16 encoders without comparator

- maximum 12 bits 1
- padded any number of bits 2
- fixed number of bits: 12,8,4 345
- one bit encoding 6
- equivalent bits 7

- energy equivalent bits (abs value) 8
- fixed 12 bits 2s complement: can also be 8,4 //9.10.11
- variable depth 2s comp //12
- fixed 12 bits 1s complement: can also be 8,4 //13/14/15
- variable depth 1s comp 16
*/


// port so is always with wh even if we don't used it so is compatible with abstracts
static inline uint32_t adcxbitsx(uint32_t depth, uint8_t wh){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      if (depth>11) depth=11; // max depth
      ADCgeneric11; //   k=ADC_GetConversionValue(ADC1)>>(11-depth)  is included
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t noadc(uint32_t depth, uint8_t wh){
  return 0;  
}

// what are variations on this? - for padding (x bits treated as y bits):
// restrict to 12 bits (can also be x bits fixed), pad to x bits, always static number of bits
static inline uint32_t adcxbits(uint32_t depth){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      if (depth>11) depth=11; // max depth
      ADCgeneric11; //   k=ADC_GetConversionValue(ADC1)>>(11-depth)  is included
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adcpadbits(uint32_t depth){ // TODO: eg. what happens if used consecutively... we have that in stream...  // how we could share same bits?
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    ADCgeneric; 
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adc12bits(uint32_t depth){ // fixed 12,8,4  - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric; 
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adc8bits(uint32_t depth){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>4;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first - no depth!
  bc--;
  return bt;
}

static inline uint32_t adc4bits(uint32_t depth){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

/*
    k[reg]=k[reg]-2048;
    inb=(((float)k[reg])/2047.0f); // from 0 to 4095 but where is the middle? 2048

    integratorf+=(inb-oldvaluef);
    if(integratorf>0.0f)
      {
	oldvaluef=1.0f;
	bt=1;
      }
    else
      {
	oldvaluef=-1.0f;
	bt=0;
	*/
// but why does this sound different to one above from adc_ - as one above lost static float so was just inb as plus minus/comparator
// which works ok
static inline uint32_t adconebits(uint32_t depth){ // depth is ignored or could be parameter for how often we sampleTODO/DONE  - sigma-delta
  uint32_t bt;
  static int32_t bc=31;
  int32_t k; // fixed 10/5
  static float integratorf=0.0f, oldvaluef=0.0f;
  static float inb;
  if (bc>depth){
  ADCgeneric;
  //  inb=(((float)k)/2048.0f)-1.0f; // from 0 to 4095 but where is the middle?
  k=k-2048;
  inb=(((float)k)/2047.0f); // from 0 to 4095 but where is the middle? 2048

  bc=0;
  }
  integratorf+=(inb-oldvaluef);

  if(integratorf>0.0f)
  {
     oldvaluef=1.0f;
     bt=1;
  }
   else
   {
      oldvaluef=-1.0f;
      bt=0;
   }
    bc++;
  return bt;
}

#define GAIN 0.5f

static inline uint32_t adconebitsx(void){ // depth is ignored or could be parameter for how often we sampleTODO/DONE  - sigma-delta - no depth!
  uint32_t bt, k;
  static float integratorf=0.0f, oldvaluef=0.0f;
  float inb;
  ADCgeneric;
  //  k=2048.0f;
  inb=(float)(k);
  //  inb=inb-2048.0; //sounds better without this
  //  inb=inb+CVL[0]; // offset
  inb=inb/2048.0; // from 0 to 4095 but where is the middle? 2048

  integratorf+=(inb-oldvaluef);
  //  integratorf=inb;
  
  if(integratorf>0.0)
      {
	oldvaluef=1.0;
	bt=1;
      }
  else
    {
      oldvaluef=-1.0;
      bt=0;
    }
  return bt;
}

static inline uint32_t adconebitsmid(uint32_t depth, uint8_t w){ // set midpoint NO! IGNORE
  uint32_t bt, k;
  static float integratorf=0.0f, oldvaluef=0.0f;
  static float inb;

    ADCgeneric;
    inb=(float)k;
    inb=inb-(float)depth;
    inb=inb/2047.0f; // from 0 to 4095 but where is the middle? 2048
  
    integratorf+=(inb-(oldvaluef));
    
    if(integratorf>0.0f)
      {
	oldvaluef=1.0f;
     bt=1;
  }
   else
   {
      oldvaluef=-1.0f;
      bt=0;
   }
  return bt;
}

static inline uint32_t adconebitsmidnof(uint32_t depth, uint8_t w){ // set midpoint
  uint32_t bt;
  int32_t k;
  static signed long integrator=0, oldValue=0;
  
  ADCgeneric;
  k=k-depth;
  integrator+=(k-oldValue);
  if(integrator>0)
  {
    oldValue=2048;
    bt=1;
  }
   else
   {
     oldValue=-2048;
     bt=0;
   }   
  return bt;
}

static inline uint32_t adconebitsreset(uint32_t depth, uint8_t w){ // depth is ignored or could be parameter for how often we sampleTODO/DONE  - sigma-delta
  uint32_t bt;
  static int32_t bc=31;
  int32_t k;
  static float integratorf=0.0f, oldvaluef=0.0f;
  static float inb, SmoothData[9]={0.0f,0.0f,0.0f,0.0f};
  //float gg=(float)depth/1024.0f;
    if (bc>depth){
    ADCgeneric;
    // try lowpass on k
    /*
    betaf=(float)(depth)/4096.0f; // between 0 and 1?
    //betaf=0.1f;
    SmoothData[w] = SmoothData[w] - (betaf * (SmoothData[w]-(float)(k))); //
    inb=SmoothData[w];
    */
    inb=(float)k;
    //k=2048;
    //  inb=(((float)k)/2048.0f)-1.0f; // from 0 to 4095 but where is the middle?
    inb=inb-2048.0f;
    inb=inb/2047.0f; // from 0 to 4095 but where is the middle? 2048
    //inb=0.0f;
    bc=0;
    }
    if (gate[w].trigger==1) integratorf=0.0f;
  
  
  integratorf+=(inb-(oldvaluef));
  // test clipping
  //  if (integratorf>2.0f) integratorf=2.0f;
  //  else if (integratorf<=-2.0f) integratorf=-2.0f;
  
  if(integratorf>0.0f)
  {
     oldvaluef=1.0f;
     bt=1;
  }
   else
   {
      oldvaluef=-1.0f;
      bt=0;
   }
    bc++;
  return bt;
}


static inline uint32_t adceqbits(uint32_t depth){
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    ADCgeneric;
    if (depth>31) depth=31; // and if depth is higher?
    k=k/divy[depth];
    bc=depth;
  }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    
  bc--;
  return bt;
}

static inline uint32_t adcenergybits(uint32_t depth){ // equiv bits energy TODO: use this
  uint32_t bt;
  static int32_t bc=31;
  int32_t tmp;
  static uint32_t k;
  if (bc>depth) {
      ADCgeneric;
      tmp=k-2048;
      k=abs(tmp);
      k=k/divy[depth];
      bc=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    bc++;    
    return bt;
}

static inline uint32_t adc12compbits(uint32_t depth){ // fixed 12 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric; 
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (bitwise) k=(~k)+1;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adc8compbits(uint32_t depth){ // fixed 8 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (bitwise) k=(~k)+1;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adc4compbits(uint32_t depth){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adccompbits(uint32_t depth){ // variable depth 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric; //   k=ADC_GetConversionValue(ADC1)>>(11-depth)  is included
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 
      
      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;
	  k=abs(k-(1<<depth));
      if (bitwise) k=(~k)+1;
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adc12onecompbits(uint32_t depth){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric; 
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adc8onecompbits(uint32_t depth){ // fixed 8 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric; 
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adc4onecompbits(uint32_t depth){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>8;
      if (k<16) bitwise=1;
      else bitwise=0;
      k=abs(k-16);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adconecompbits(uint32_t depth){ // variable 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric; 
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 

      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;

      k=abs(k-(1<<depth));
      if (k==0) k=1;
      if (bitwise) k=(~k);
      //     bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

// could even be list of functions here - how we integrate...
uint32_t (*adcbitstreams[16])(uint32_t depth)={adcxbits, adcpadbits, adc12bits, adc8bits, adc4bits, adconebits, adceqbits, adcenergybits, adc12compbits, adc8compbits, adc4compbits, adccompbits, adc12onecompbits, adc8onecompbits, adc4onecompbits, adconecompbits}; // which ones use depth parameter

//DACs

static inline uint32_t dacxbits(uint32_t depth){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    k=(gate[defdac].dac)>>(11-depth);
    if (depth>11) depth=11; // max depth
    bc=depth;
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dacpadbits(uint32_t depth){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    //    ADCgeneric; 
    k=(gate[defdac].dac); 
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dac12bits(uint32_t depth){ // fixed 12,8,4
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dac8bits(uint32_t depth){ // fixed 12,8,4
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      k=k>>4;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dac4bits(uint32_t depth){ // fixed 12,8,4
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t daconebits(uint32_t depth){ // depth is ignored or could be parameter for how often we sampleTODO/DONE
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  static float integratorf=0.0f, oldvaluef=0.0f;
  static float inb;
  if (bc>depth){
    //  ADCgeneric;
    k=(gate[defdac].dac); 
  inb=(((float)k)/2048.0f)-1.0f; // from 0 to 4095 but where is the middle?
  bc=0;
  }
  integratorf+=(inb-oldvaluef);

  if(integratorf>0.0f)
  {
     oldvaluef=1.0f;
     bt=1;
  }
   else
   {
      oldvaluef=-1.0f;
      bt=0;
   }
    bc++;
  return bt;
}

static inline uint32_t daceqbits(uint32_t depth){
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    //    ADCgeneric;
    k=(gate[defdac].dac); 
    if (depth>31) depth=31; // and if depth is higher?
    k=k/divy[depth];
    bc=depth;
  }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    
  bc--;
  return bt;
}

static inline uint32_t dacenergybits(uint32_t depth){ // equiv bits energy TODO: use this
  uint32_t bt;
  static int32_t bc=31;
  int32_t tmp;
  static uint32_t k;
  if (bc>depth) {
    //      ADCgeneric;
    k=(gate[defdac].dac); 
      tmp=k-2048;
      k=abs(tmp);
      k=k/divy[depth];
      bc=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    bc++;    
    return bt;
}

static inline uint32_t dac12compbits(uint32_t depth){ // fixed 12 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (bitwise) k=(~k)+1;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dac8compbits(uint32_t depth){ // fixed 8 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (bitwise) k=(~k)+1;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dac4compbits(uint32_t depth){ // fixed 4 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t daccompbits(uint32_t depth){ // variable depth 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric; //   k=ADC_GetConversionValue(ADC1)>>(11-depth)  is included
      k=(gate[defdac].dac); 
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 
      
      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;
	  k=abs(k-(1<<depth));
      if (bitwise) k=(~k)+1;
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dac12onecompbits(uint32_t depth){ // fixed 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dac8onecompbits(uint32_t depth){ // fixed 8 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t dac4onecompbits(uint32_t depth){ // fixed 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      k=k>>8;
      if (k<16) bitwise=1;
      else bitwise=0;
      k=abs(k-16);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t daconecompbits(uint32_t depth){ // variable 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      //      ADCgeneric;
      k=(gate[defdac].dac); 
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 

      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;

      k=abs(k-(1<<depth));
      if (k==0) k=1;
      if (bitwise) k=(~k);
      //     bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

// could even be list of functions here - how we integrate...
uint32_t (*dacbitstreams[16])(uint32_t depth)={dacxbits, dacpadbits, dac12bits, dac8bits, dac4bits, daconebits, daceqbits, dacenergybits, dac12compbits, dac8compbits, dac4compbits, daccompbits, dac12onecompbits, dac8onecompbits, dac4onecompbits, daconecompbits};


//////////////xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


static inline uint16_t leaks(uint16_t x, uint16_t y, uint16_t prob, uint16_t who){ // try lazy, stickyt, leaky, decaying logic here... // who is new 20/9 for which SR we take logic from...
  //  static uint16_t timer=0;
  //  uint16_t z;
  // p as probability or time
  // keep track of how many times this is called (for each register/bit position) and flipit

  // or we can track bits recording their position for a certain lifespan
  // one bit per SR is tracked and lost... so would be leakNSR for example for that bit
  
  // but that is too deterministic... but if we share timers or if timer is across different speeds
  //  prob=1;
  // leaky XOR to test
  if (prob>31) prob=31;
  
  if (x^y==0) return 0;
  //  shift_registerR=(shift_registerR<<1)+z; // we are shifting left << so bit 31 is out last one
  if ((gate[who].shift_&masky[prob])==0) return 1;
  //  else if (rand()%prob==0) return 1;
  return 0;
  
  /*  timer++;
  if (timer>p){
    timer=0;
    d^=1;
    }*/
}

static inline uint16_t otherleaks(uint16_t x, uint16_t y, uint16_t prob, uint16_t who){
  if (prob>31) prob=31;
  
  if (x^y==0) return 0;
  if ((LFSR_[who]&masky[prob])==0) return 1;
  return 0;
}

// logop: 2 bits logopx: 2 bits, logopxxx operates on many bits 

//bitr=logop(bitr,bitrr,logopp[w]); // or other op TODO
// logop: 0-XOR, 1-OR, 2-&, 3leaks - 0,1,2,3
// this one can return just bitn 
static inline uint16_t logopx(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  // 
   if (type==3)  return (bita ^ bitaa);
   //  else if (type==1) return (bita | bitaa);
   else if (type==1) return (otherleaks(bita, bitaa,3,3));
  else if (type==0) return bita;
  else if (type==2) {return (bita ^ !bitaa);
    //    ty=otherleaks(bita, bitaa,3,3); // how to change this?
    //    return ty; // leaks using RSR as random // where we get 8 from...
  }
  return bita ^ bitaa; // default
}

static inline uint16_t logopxx(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  // 
  if (type==3)  return (bita | bitaa);
   //  else if (type==1) return (bita | bitaa);
   else if (type==1) return (bita & bitaa);
  else if (type==0) return (bita ^ bitaa);
  else if (type==2) {return (bita ^ !bitaa); //inv
    //    ty=otherleaks(bita, bitaa,3,3); // how to change this?
    //    return ty; // leaks using RSR as random // where we get 8 from...
  }
  return bita ^ bitaa; // default
}


//bitr=logop(bitr,bitrr,logopp[w]); // or other op TODO
// logop: 0-XOR, 1-OR, 2-&, 3leaks - 0,1,2,3
static inline uint16_t logop(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  if (type==0)  return (bita ^ bitaa);
  else if (type==1) return (bita);
  else if (type==2) return (bita ^ (!bitaa)); // same as inverted XOR
  else if (type==3) {
    ty=leaks(bita, bitaa,3,3);
    return ty; // leaks using RSR as random 
  }
  return bita ^ bitaa; // default
}

static inline uint16_t logopxxx(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
   if (type==3)  return (bita ^ bitaa);
   else if (type==1) return (bita | bitaa);
   else if (type==0) return ~(bita)&255; // 8 bits
  else if (type==2) {return (bita & bitaa);
    //    ty=otherleaks(bita, bitaa,3,3); // how to change this?
    //    return ty; // leaks using RSR as random // where we get 8 from...
  }
  return bita ^ bitaa; // default
}

uint32_t dacstrobe[32]={1,1,1,1, 1,0,0,1, 1,1,1,1, 1,1,1,1, 1,0,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1}; //if dac doesn't use strobe=1!?

// 15/12/2022 - length changed to otherpar except where we change both - to be TESTED!!
//     val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].matrix[13]>>7, gate[w].matrix[14], gate[w].fake); 
static inline uint32_t DAC_(uint32_t wh, uint32_t shift, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t strobe){  // DAC is 12 bits
  uint32_t x=0;
  float f=0.0f;
  static uint32_t n[9]={0,0,0,0,0,0,0,0,0};
  static uint32_t nom[9]={0,0,0,0};
  static float SmoothData[9]={0.0, 0.0, 0.0, 0.0};
  //  static float lastx[4]={0.0, 0.0, 0.0, 0.0};
  static uint32_t lastout[9]={0,0,0,0,0,0,0,0,0};
  static uint32_t toggle[9]={0,0,0,0};
  static uint32_t mask[4]={0,0,0,0};

  float betaf=0.4f, mult,pp;
  int32_t rem;
  uint32_t y,tmp;

// if we use otherpar as length we need to add:
// otherpar=lookuplenall[otherpar>>7]; // 12->5 bits

// strobed=5, 
  
  switch(type){

  case 666: // null case for testings
    x=0;
    break;
    
  case 0: // length doesn't change much except at slow speeds - ADC x bits out - modded for new draft
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (otherpar==3){
      if ((shift&4)==4) x=4095; // changed 28/12
      else x=0;
    }
    else     x=( (shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3]; // doublecheck - fixed problem in shifts in resources 16/8
    break;
    
  case 1:// equivalent bit DAC for x bits - 3/11 - 32 bits max now
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=countbits(shift& masky[otherpar]); // lower length bits only
    y=divy[otherpar]; // added table for this 7/10 - updated for 32 bits
    x*=y;
    break;

  case 2: // as 0 but alt
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (otherpar==3){
      if ((shift&4)==4) x=4095; // changed 28/12
      else x=0;
    }
    else  x=( (shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshiftalt[otherpar-3]; // doublecheck - fixed problem in shifts in resources 16/8
    break;

    
  case 3: // one bit audio but with beta as param  - sigma-delta
    // beta is now (6/12/2021) always param - just if is generated from cv or speed or ... betaf=0.4f is usual value
    // 0.4=par/4096.0
    //    if (otherpar>4096) otherpar=4096;
    //    otherpar=4096-otherpar;
    if (otherpar==0) otherpar=1;
    betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
    //    betaf=0.025;
    y=(shift >>length)&1;
    //    if (y==1) f=1.0f;
    //    else f=-1.0f;
    if (y==1) x=4095;
    else x=0;
    SmoothData[wh] = SmoothData[wh] - (betaf * (SmoothData[wh] - ((float)(x)))); //
    //    lastx[wh]=x;
    //SmoothData[wh]=f;
    //    f=(SmoothData[wh]*2048.0f)+2048.0f;
    //x=(int)f;
    x=(int)SmoothData[wh];
    break;

  case 4: //spacers
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x = (shift&0xFF)<<4; // just the lower 8 bits - no spacings
    if (otherpar>7){ // real length >8
      x = ((shift & 0x01) + ((shift>>pos[otherpar][1])&0x02) + ((shift>>pos[otherpar][2])&0x04) + ((shift>>pos[otherpar][3])&0x08) + ((shift>>pos[otherpar][4])&0x10) + ((shift>>pos[otherpar][5])&0x20) + ((shift>>pos[otherpar][6])&0x40) + ((shift>>pos[otherpar][7])&0x80))<<4;
      //       {0, 0, 1, 3, 6, 10, 15, 21} // for 32 bits = length=31 - check sense of this
    }
    break;

  case 5: // only output standard DAC on param->strobe/clock! so just maintain lastout S
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    gate[wh].strobed=1;
    if (strobe) {
      x=((shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3];
  //  x=((shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3];
      lastout[wh]=x;
    }
    else x=lastout[wh];
    break;

  case 6: // toggle to hold/release DAC
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    gate[wh].strobed=1;
    if (strobe) toggle[wh]^=1;
    if (toggle[wh]) {
      x=lastout[wh];
    }
    else {
      x=((shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3];
      lastout[wh]=x;
    }      
    break;
    
  case 7: // 4 spaced bits out! equiv bits or not - in this case not
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x= ( ( (shift& (1<<lastspac[otherpar][0]))>>lastspacbac[otherpar][0]) + ((shift& (1<<lastspac[otherpar][1]))>>lastspacbac[otherpar][1]) + ((shift& (1<<lastspac[otherpar][2]))>>lastspacbac[otherpar][2]) + ((shift& (1<<lastspac[otherpar][3]))>>lastspacbac[otherpar][3]) )<<8; // 4 bits to 12 bits
    break;

  case 8: // 4 spaced bits out! equiv bits
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x= ( ((shift& (1<<lastspac[otherpar][0]))>>lastspacbac[otherpar][0]) + ((shift& (1<<lastspac[otherpar][1]))>>lastspacbac[otherpar][1]) + ((shift& (1<<lastspac[otherpar][2]))>>lastspacbac[otherpar][2]) + ((shift& (1<<lastspac[otherpar][3]))>>lastspacbac[otherpar][3]) ); 
    x=countbits(x)*1023;
    break;

  case 9: // one SR is sieved out over another? as DAC option. XOR as sieve? AND as mask! TODO
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=((shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3]; 
    x=x^(((gate[sieve[wh]].shift_ & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3]); // seived through previous SR
    break;

  case 10: // alt above
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=((shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3]; 
    x=x^(((gate[sieve[wh]].shift_ & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshiftalt[otherpar-3]); // seived through previous SR
    break;

  case 11: //  one SR is sieved out over clksr for that sr. XOR as sieve?  - SKIPPED/retry instead of 11
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=((shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3]; 
    x=x^((clksr_[wh] & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3]; 
    break;

  case 12:// standard bit DAC for x bits     ///bitx length as other param rather than length:
    // but then we don't really use len? unless is cycle back
    // try now 21/12/2021 using length
    // bit length can also be CV - how to put this in as DAC is quite fixed in macro?
    otherpar=otherpar>>7; //5 bits
    rem=length-otherpar;
    if (rem<0) rem=0;
    x=((shift & masky[rem])>>(rightshift[rem]))<<leftshift[rem]; 
      break;

      // sequential DACs
  case 13: // we wait for length bits then output that many bits from the top of the SR (len bit) 
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;      
      x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar];
      lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 14: // alt we wait for length bits then output that many bits from the top of the SR (len bit)
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;      
      x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshiftalt[otherpar];
      lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;
        
  case 15: // we wait for otherparam bits then output that many bits from the top of the SR (len bit)
    //    length=3; // is good to vary length AND otherpar AND speed - Cint12 does this
    // can also be x number of equiv bits TRY!
    otherpar=otherpar>>7; //5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;
      x=((shift & masky[length])>>(rightshift[length]))<<leftshift[length];
      //      length=1;
      //      x=(shift & masky[length])<<11;
      lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 16:// par is mask on standard bit DAC for x bits
    //    if (wh<4 && length>3 && length<32) 
    // why (length-3)? to get down to 1 bit so could also have option for full bits!
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
    x=x|(otherpar&4095);
      break;

  case 17:/// we record mask and use this to mask the regular DAC... - could also be other-than-standard DACs
    gate[wh].strobed=1;
    if (strobe) // we record the mask  S
	{
	  mask[wh]=Gshift__[otherpar>>10]; // or reg can be otherpar/SR
	  }
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
    x=x|mask[wh];
    break;

    //    // case 15 was as case 2 but with
    //   param for filter - and now always has param

  case 18:// standard bit DAC for x bits - new mode here
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;
    if (otherpar==3){
      if ((shift &4)==4) nom[wh]=4095;
      else nom[wh]=0;
    }
    else nom[wh]=((shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshift[otherpar-3]; // we want 12 bits but is not really audible difference //Q of least bits
    }
    n[wh]++;
    x=nom[wh];
    break;

  case 19:// alt standard bit DAC for x bits - new mode here
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;
    if (otherpar==3){
      if ((shift &4)==4) nom[wh]=4095;
      else nom[wh]=0;
    }
    else nom[wh]=((shift & masky[otherpar-3])>>(rightshift[otherpar-3]))<<leftshiftalt[otherpar-3]; // we want 12 bits but is not really audible difference //Q of least bits
    }
    n[wh]++;
    x=nom[wh];
    break;
    
  case 20: // 22/3/2022 sliding bits.moving window - we have depth/length and where it is, wrap or not, shift or not
    // use detached length for length, and otherpar&31 for where it is, try no wrap
    // note: SRlength_[wh] or treat as full length/yes
    if (length>11) length=11;
    otherpar=otherpar>>7; //5 bits
    // topbits
    x=(shift&(masky[length]<<otherpar)); 
    // bottom bits
    tmp=(otherpar+length);
    if (tmp>31){
      tmp=tmp-31;
      y=shift&masky[tmp]; 
      x=x&4095;
      x=x>>(otherpar-tmp);
      tmp=11-(tmp);
      y=y<<tmp;
      x=x+y;
    }
    else { // working 
      tmp=11-(length);
      x=x>>otherpar;
      x=x<<tmp;
          }
    break;

  case 21: // fixed 12 bits in 2s complement back to our encoding - but we have no use for length - except perhaps // no length no otherpar
    // try delay
    // here is fixed length
    if (n[wh]>11) {
      n[wh]=0;      
      x=shift&masky[11]; // 12 bits
      if (x&(1<<11)) {
      x = x | ~((1 << 12)-1);
    }
    x=x+2048;
    lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 22: // fixed 12 bits in 2s complement back to our encoding - but we have no use for length - except perhaps
    // try delay
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) { // this could also be otherpar
      n[wh]=0;      
      x=shift&masky[11]; // 12 bits
      if (x&(1<<11)) {
      x = x | ~((1 << 12)-1);
    }
    lastout[wh]=x+2048;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 23: //  2s complement back to our encoding 
    // variable bits out
    // try delay or no delay
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) { // this could also be otherpar // either or...
      n[wh]=0;      
      x=shift&masky[otherpar]; // x bits
      if (x&(1<<otherpar)) {
	x = x | ~((1 << (otherpar+1))-1);
    }
      x=x+(1<<otherpar);
      // shift back to 12 bits...
      lastout[wh]=((x&masky[otherpar])>>rightshift[otherpar])<<leftshift[otherpar]; 
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 24: // fixed 12 bits in ONES complement back to our encoding - but we have no use for length - except perhaps
    // try delay
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) { // this could also be otherpar
      n[wh]=0;      
      x=shift&masky[11]; // 12 bits

      if (x&(1<<11)) {
	x=(~x);
	x&=masky[11];
	lastout[wh]=2048-x;
      }
      else lastout[wh]=x+2048;
    }
    x=lastout[wh]; // all above 2048
    n[wh]++;              
    break;

  case 25: //  ONEs complement back to our encoding 
    // variable bits out
    // try delay or no delay
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) { // this could also be otherpar // either or... - but how do we get length AND otherpar // except detach speed...
      n[wh]=0;      
      x=shift&masky[otherpar]; // x bits
      if (x&(1<<otherpar)) {
	x=~x;
	x&=masky[otherpar];
	x=(1<<otherpar)-x;
    }
      else  x=x+(1<<otherpar);
      // shift back to 12 bits...
      lastout[wh]=((x&masky[otherpar])>>rightshift[otherpar])<<leftshift[otherpar]; 
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 26: //2s comp back in one go
    //      x=shift&masky[11]; // 12 bits but we want the top 12 bits of length
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=((shift>>rightshift[otherpar])<<leftshift[otherpar])&masky[11];
      if (x&(1<<11)) {
      x = x | ~((1 << 12)-1);
    }
    x=x+2048;
    break;

  case 27: // regular 12 bits in one go
      otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
      x=((shift>>rightshift[otherpar])<<leftshift[otherpar])&masky[11];
    break;

  case 28: // mix own basic dac and dacfrom
    if (length==3){
      if ((shift&4)==4) x=4095; // changed 28/12
      else x=0;
    }
    else     x=( (shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; // doublecheck
    otherpar=4095-otherpar;
    //    if (otherpar>4095) otherpar=4095;
    mult=mixer[otherpar>>2]; // 10 bits - 0 is 1.0f so full dac
    pp=((float)(x) *  (1.0f-mult)) + ((float)(gate[dacfrom[daccount][wh]].dac)*mult); // mix with param
    x=(int)pp;
    break;
    
  case 29: // default for all other DACs - modded for new draft // no otherpar
    //    x=( (shift & masky[length])>>(rightshift[length]))<<leftshift[length];
        x=shift&4095;
    break;

  case 30: // 4 bit DAC aside from length - try now with delay // no otherpar
      x=( (shift & masky[3])>>(rightshift[3]))<<leftshift[3];
    break;

  case 31: // straight 4 bit dac // no otherpar
    x=( (shift & masky[3])>>(rightshift[3]))<<leftshift[3];
    break;   
 
    ///////
  } // switch    
  return x;
}



///////////////////////////////////////////////////////////////////////// 

#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 1000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void EXTI4_IRQHandler(void){ // working NSR 
  uint32_t tmp, tmpp;
if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
  intflag[0]=1; //NSR
  //  param[0]=counter_[0];
  //  counter_[0]=0;
  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
  uint32_t tmp, tmpp;
  uint16_t j, bit, xx, x;
  uint32_t lengthbitl=15, new_statl, new_statr,new_statc, lengthbitc=15, lengthbitr=15; // for 2nd bit on lsr, rsr and csr
    
  if (EXTI_GetITStatus(EXTI_Line5) != RESET) { //RSR  
    intflag[3]=1; //RSR
    //    param[3]=counter_[3];
    //      counter_[3]=0;
    EXTI_ClearITPendingBit(EXTI_Line5);
 }

  if (EXTI_GetITStatus(EXTI_Line6) != RESET) { //LSR
    intflag[1]=1; //LSR
    //    param[1]=counter_[1];
    //    counter_[1]=0;
    EXTI_ClearITPendingBit(EXTI_Line6);
 } 

  if (EXTI_GetITStatus(EXTI_Line7) != RESET) {// CSR
    intflag[2]=1; //CSR
    //    param[2]=counter_[2];
    //    counter_[2]=0;
    EXTI_ClearITPendingBit(EXTI_Line7);
 } 
}

void TIM4_IRQHandler(void) 

{
  uint32_t temp;
  static uint32_t modecnt=0;
  //  volatile static uint16_t tmp;
  static uint32_t flipperr=0;
  
  TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 

  /*  
      tmp^=1;
      if (tmp) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
      else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */

  // map ADCs:

    // 0: nspd, 1: nlen, 2: nmode
    // 3: lspd, 4: llen, 5: lmode
    // 6: rspd, 7: rlen, 8: rmode // adc6 fixed hw
    // 9: cspd, 10: clen, 11: cmode

  // modes are NOT inverted!
  // maybe we can slow down modes
    modecnt++; 
    if (modecnt>64){ // 128: what is the speed of this? 2/1 measured as 10 Hz (so 20x second ok)
    /* // flipper is on fake clock for CC
    flipperr^=1;
    if (flipperr) GPIOB->BSRRH=clk_route_new[2]; // we get from tail
     else GPIOB->BSRRL=clk_route_new[2];
    */
      modecnt=0;
      //    }
      
  //moden
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(adc_buffer[2]+lastlastmoden+lastmoden)/3; 
  temp=temp;
  temp=(temp+lastlastmoden+lastmoden)/3; 
  lastlastmoden=lastmoden;
  lastmoden=temp;
  //  CVM[0]=temp;    
  mode[0]=temp>>6; 
  if (lastmode[0]!=mode[0]) gate[0].changed=1;
  else gate[0].changed=0;
  lastmode[0]=mode[0];
  
  // modec
  ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(adc_buffer[11]+lastlastmodec+lastmodec)/3;
  temp=temp;
  temp=(temp+lastlastmodec+lastmodec)/3; 
  lastlastmodec=lastmodec;
  lastmodec=temp;
  //  CVM[2]=temp;
  mode[2]=temp>>6;
  //    mode[2]=(temp>>6); 
  if (lastmode[2]!=mode[2]) gate[2].changed=1; 
  else gate[2].changed=0;
  lastmode[2]=mode[2];

  // model
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  temp=(temp+lastlastmodel+lastmodel)/3; 
  //  temp=(adc_buffer[5]+lastlastmodel+lastmodel)/3; 
  temp=temp;
  lastlastmodel=lastmodel;
  lastmodel=temp;
  //  CVM[1]=temp;
  mode[1]=temp>>6; 
  if (lastmode[1]!=mode[1]) gate[1].changed=1;
  else gate[1].changed=0;
  lastmode[1]=mode[1];

  // moder
  ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(adc_buffer[8]+lastlastmoder+lastmoder)/3;
  temp=temp;
  temp=(temp+lastlastmoder+lastmoder)/3; 
  lastlastmoder=lastmoder;
  lastmoder=temp;
  //  CVM[3]=temp;
  mode[3]=temp>>6; 
  if (lastmode[3]!=mode[3]) gate[3].changed=1; // bug fixed 28/1/
  else gate[3].changed=0;
  lastmode[3]=mode[3];
    }
  
  // speedn
  totn=totn-smoothn[nn];
  //  smoothn[nn]=adc_buffer[0];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothn[nn]=ADC_GetConversionValue(ADC1);
  totn+=smoothn[nn];
  nn++;
  if (nn>=SMOOTHINGS) nn=0;
  temp=totn/SMOOTHINGS;  
  CV[0]=4095-temp;
  //  speedf[0]=logspeed[temp>>2]; // was logspeed
  //  speedf_[0]=0.1f;
  
  // speedl
  
  totl=totl-smoothl[ll];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothl[ll]=ADC_GetConversionValue(ADC1);
  //  smoothl[ll]=adc_buffer[3];
  totl+=smoothl[ll];
  ll++;
  if (ll>=SMOOTHINGS) ll=0;
  temp=totl/SMOOTHINGS;
  //  CV[1]=4095-ADC_GetConversionValue(ADC1);
  CV[1]=4095-temp;
  //  speedf[1]=logspeed[temp>>2];
  
  // speedr
  totr=totr-smoothr[rr];
  //  smoothr[rr]=adc_buffer[6];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothr[rr]=ADC_GetConversionValue(ADC1);
  totr+=smoothr[rr];
  rr++;
  if (rr>=SMOOTHINGS) rr=0;
  temp=totr/SMOOTHINGS;  
  CV[3]=4095-temp;
  //  speedf[3]=logspeed20[temp>>2]; // 20 octaves - slowest one
  
    // speedc
  totc=totc-smoothc[cc];
  //  smoothc[cc]=adc_buffer[9];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_144Cycles); // was 10
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothc[cc]=ADC_GetConversionValue(ADC1);

  totc+=smoothc[cc];
  cc++;
  if (cc>=SMOOTHINGS) cc=0;
  temp=totc/SMOOTHINGS;  
  CV[2]=4095-temp;
  //  speedf[2]=logspeed[temp>>2];
  
  // lens from 4 to 32 - 8/11/2021 we reversed the list to save some time!

  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(adc_buffer[1]);
  CVL[0]=4095-temp;
  temp=temp>>7; // 12 bits to 5 bits
  SRlength_[0]=lookuplenall[temp];

  //temp=(adc_buffer[4]);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  CVL[1]=4095-temp;
  temp=temp>>7; 
  SRlength_[1]=lookuplenall[temp];

  ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  CVL[3]=4095-temp;
  temp=temp>>7; 
  SRlength_[3]=lookuplenall[temp];
  
  //temp=(adc_buffer[10]);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  CVL[2]=4095-temp;
  temp=temp>>7; 
  SRlength_[2]=lookuplenall[temp]; // TODO: take speed and lens out so we can detach easier
}
