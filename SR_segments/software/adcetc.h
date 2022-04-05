/// from here
static inline uint32_t countbits(uint32_t i)
{
    return( countbts[i&0xFFFF] + countbts[i>>16] );
}


static inline uint8_t probableCV(uint32_t reg, uint32_t type){
  // LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
  // prob of cycling bit let's say or ADC bit in or...
  switch(type){
  case 0:
    if ((LFSR_[reg] & 4095 )< (shift_[reg]& 4095))      return 1;
    break;
  case 1:
    if ((LFSR_[reg] & 4095 )< (shift_[dacfrom[daccount][reg]] & 4095))      return 1;
    break;
  case 2:
    if ((shift_[reg] & 4095 )< (shift_[dacfrom[daccount][reg]] & 4095))      return 1;
    break;
  case 3:
    if ((LFSR_[reg] & 4095 ) < (param[reg] & 4095))      return 1;
    break;
  }    
  return 0;
}

static inline uint8_t otherprobableCV(uint32_t reg, uint32_t type){ // this one is 2 bits
  // LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
  // prob of cycling bit let's say or ADC bit in or...
  switch(type){
  case 0:
    if ((LFSR_[reg] & 4095 )< (shift_[reg]& 4095))      return 1;
    break;
  case 1:
    if ((LFSR_[reg] & 4095 )< (shift_[dacfrom[daccount][reg]] & 4095))      return 1;
    break;
  case 2:
    if ((LFSR_[reg] & 4095 ) < (param[reg] & 4095))      return 1;
    break;
  }    
  return 0;
}



// 19/1/22 return of more generic ADC_ in = so income is passed in function and can be DAC+ADC etc so we have different handlings
// 7 modes
static inline int ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t *SR, uint32_t income){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator=0.0f, oldValue=0.0f;
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

  case 2: // variations on one bit audio - also phasey
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

#define ADCone {					\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k[reg]=ADC_GetConversionValue(ADC1)>>(11-length);			\
  }


// TEST INVERSION
#define ADCtwo {				\
    ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k[reg]=4095-ADC_GetConversionValue(ADC1);					\
  }


#define ADCgeneric {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k=ADC_GetConversionValue(ADC1);					\
  }

#define ADCgeneric11 {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k=ADC_GetConversionValue(ADC1)>>(11-depth);				\
  }
  

//////////////////////////////////////////////////////////////////////////
// TODO: fill in all possible generators: eg. new abstract ones, binroute and return...
// options also include if we add in gshift or just shift out etc.

static inline uint32_t binroutebits(uint32_t depth, uint8_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - keep as option
    gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

// depth can be length or param
static inline uint32_t returnbits(uint32_t depth, uint8_t wh){   // returning but we need ref to itself SR//, and its length/ as depth - starts to look like adc_ functions now
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  //  bt=(*SR>>depth)& 0x01; // but return should be of ghost...   bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		
  bt = (gate[wh].Gshift_[wh]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

//abstract: oscbits, osc1bits-also questions of static patterns, TM bits, onebits, ENbits, Ensbits
// could also have fixed one set of oscbits eg. osceqbits
// what else.... more on static patterns from dac or adc

static inline uint32_t osceqbits(uint32_t depth, uint8_t wh){  
  uint32_t bt;
  static int32_t n=0,nn=0;
     if (n>depth) {
       bt=0;
       if (nn>=depth) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
       bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t oscbits(uint32_t depth, uint32_t depthh){ // 2 params so can't fit 
  uint32_t bt;
  static int32_t n=0,nn=0;
     if (n>depth) {
       bt=0;
       if (nn>=depthh) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
       bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t osc1bits(uint32_t depth, uint8_t wh){  
  uint32_t bt;
  static uint32_t lastbt,n;
  if (n>depth)  {
    lastbt^=1;
    n=0;
  }
  n++;
  bt=lastbt;
  return bt;
}

// depth is length of seq, rndd is LFSR or DAC, par is CVx - so we have 2xCV
static inline uint32_t TMbits(uint32_t depth, uint32_t seq, uint32_t rndd, uint32_t par){  // for TM in TM, return inv or loop bits
  uint32_t bt;
  bt=(seq>>depth)&0x01;
  if (par>rndd) bt=!bt;
  return bt;
}

static inline uint32_t TMsimplebits(uint32_t depth, uint8_t wh){
  uint32_t bt,k;
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;				
  //  ADCgeneric;
  if (depth>(LFSR_[wh]&4095)) bt=!bt;
  return bt;
}

static inline uint32_t onebits(uint32_t depth, uint8_t wh){ // depth=0 resets
  uint32_t bt;
  static int32_t bc=31;
  //  static uint32_t k;
  if (bc<0) {
    bt=0;
    if (depth>0) bc=depth;
  }
  else{
  bt = 1; // this means that MSB comes out first
  }
  bc--;
  return bt;
}

//EN: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)
static inline uint32_t ENbits(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 

  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  prob=prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

// trying for a simpler version
static inline uint32_t ENsbits(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  if ((LFSR_[wh]&4095)<prob) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
    //    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t compbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  ADCgeneric;
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdacbits(uint32_t depth, uint8_t wh){ // runs out in loop
  uint32_t bt;
  static uint32_t k;
  //  ADCgeneric;
  k=(gate[3].dac); 
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdaccbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  ADCgeneric;
  if (k>(gate[3].dac)) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t pattern4bits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    k=gate[3].shift_&15;
  }
  if (nn>3){ // or count down
    nn=0;
  }
  bt=k>>nn;
  n++; nn++;
  return bt;
}

static inline uint32_t patternadcbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    ADCgeneric;
    k=k>>8;
  }
  if (nn>3){ // or count down
    nn=0;
  }
  bt=k>>nn;
  n++; nn++;
  return bt;
}


static inline uint32_t pattern8bits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    k=gate[3].shift_&255;
  }
  if (nn>7){ // or count down
    nn=0;
  }
  bt=k>>nn;
  n++; nn++;
  return bt;
}

static inline uint32_t lfsrbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
    bt = ((ADCshift_[wh] >> (lfsr_taps[depth][0])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][1])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][2])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][3]))) & 1u;
    ADCshift_[wh]=(ADCshift_[wh]<<1)+bt;
    if (ADCshift_[wh]==0) ADCshift_[wh]=0xff;
    return bt;
}

static inline uint32_t llfsrbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  // out from lfsr at full speed
  bt=(LFSR_[wh]>>31)&0x01;
  return bt;
}


static inline uint32_t flipbits(uint32_t depth, uint8_t wh){  
  uint32_t bt;
  static uint32_t lastbt,n;
  depth=depth>>4; // 8 bits say
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01; // returnbits				
  if (n>depth)  {
    bt=!bt;
    n=0;
  }
  n++;
  return bt;
}


uint32_t (*abstractbitstreams[16])(uint32_t depth, uint8_t wh)={binroutebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, TMsimplebits, compbits, compdacbits, compdaccbits, pattern4bits, pattern8bits, patternadcbits, lfsrbits, llfsrbits, flipbits};

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

static inline uint32_t adcpadbits(uint32_t depth){ 
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

static inline uint32_t adc12bits(uint32_t depth){ // fixed 12,8,4
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

static inline uint32_t adc8bits(uint32_t depth){ // fixed 12,8,4
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>4;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t adc4bits(uint32_t depth){ // fixed 12,8,4
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

static inline uint32_t adconebits(uint32_t depth){ // depth is ignored or could be parameter for how often we sampleTODO/DONE
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  static float integratorf=0.0f, oldvaluef=0.0f;
  static float inb;
  if (bc>depth){
  ADCgeneric;
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

static inline uint32_t adc8compbits(uint32_t depth){ // fixed 8 bits 2s complement
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

static inline uint32_t adc4compbits(uint32_t depth){ // fixed 4 bits 2s complement
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

static inline uint32_t adc12onecompbits(uint32_t depth){ // fixed 12 bits 1s complement
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

static inline uint32_t adc8onecompbits(uint32_t depth){ // fixed 8 bits 1s complement
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

static inline uint32_t adc4onecompbits(uint32_t depth){ // fixed 12 bits 1s complement
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
uint32_t (*adcbitstreams[16])(uint32_t depth)={adcxbits, adcpadbits, adc12bits, adc8bits, adc4bits, adconebits, adceqbits, adcenergybits, adc12compbits, adc8compbits, adc4compbits, adccompbits, adc12onecompbits, adc8onecompbits, adc4onecompbits, adconecompbits};

//DACs

static inline uint32_t dacxbits(uint32_t depth){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    k=(gate[3].dac)>>(11-depth);
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
    k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
    k=(gate[3].dac); 
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
    k=(gate[3].dac); 
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
    k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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
      k=(gate[3].dac); 
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

// 10/12/21 - changes to SR in place now for draftspeed.c
static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator[4]={0.0f}, oldvalue[4]={0.0f};
  static uint32_t k[4]={0}, lastbt[4]={0}; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  //  static uint8_t lc=0;
  static uint32_t toggle[4]={0,0,0,0};
  uint32_t bt=0;
  int32_t tmp=0;
  float integratorf=0.0, oldvaluef=0.0, inb; // shared across all adc
  
  switch(type){    

  default:
    bt=0;
    break;
    // TODO: all to new scheme for adc_buffer
  case 0: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCone;
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 1: // equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      ADCtwo;
      k[reg]=k[reg]/divy[length];
      n[reg]=0;
    }
    if (k[reg]!=0) {
      bt=1;
      k[reg]--;
    }
    else bt=0;
    n[reg]++;    
    break;

    /*
  case 2: // variations on one bit audio - also phasey
    //  n[reg]++;
	//	if (n[reg]>48) { // try changing value?
	//	  n[reg]=0;
    k[reg]=(adc_buffer[12]); // from 0 to 4095 but where is the middle? - also we do nothing here with length
    //	}
    integrator[reg]+=(k[reg]-oldvalue[reg]);
   if(integrator[reg]>2048)
  {
     oldvalue[reg]=4095;
     bt=1;
  }
   else
   {
      oldvalue[reg]=0;
      bt=0;
   }   
   break;    
    */

  case 2: // try with float but this is the same with phasings
    ADCtwo;
    inb=(((float)k[reg])/2048.0f)-1.0f; // from 0 to 4095 but where is the middle? 2048
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
   break;    
   
  case 3: // basic sequential length as in 0 but with padding of zeroes if >11 bits 
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	ADCone; 	//	k[reg]=(adc_buffer[12])>>(11-length);
	n[reg]=length;
      }
      else {
	ADCtwo;
	k[reg]=k[reg]<<(length-11); // 21/3 - pad out
	n[reg]=length; // padded with zeroes then - 14/3/2022
      }
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 4:  // special case for spaced bit entry depending on length
    // now with route in!
    *SR &=spacmask[length]; //cleared
    ADCtwo;
    k[reg]=k[reg]>>8; // we want 4 bits
    *SR+=(k[reg]&1)+((k[reg]&2)<<spacc[length][0])+((k[reg]&4)<<spacc[length][1])+((k[reg]&8)<<spacc[length][2]);
    // testing route in of bits from gate[0].Gshift_[regg] or rather dac feedback
    k[reg]=(gate[regg].dac)>>8; 
    *SR^=(k[reg]&1)+((k[reg]&2)<<spacc[length][0])+((k[reg]&4)<<spacc[length][1])+((k[reg]&8)<<spacc[length][2]);    
    // 4 bits goes in
    // no bt return
    bt=0;
    break;   
    
  case 5: // basic sequential length of 12 bits cycling in 
    if (n[reg]<0) { // 12 bits
      ADCtwo;
      n[reg]=11;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 6: // basic sequential length of 
    if (n[reg]<0) { // 8 bits
      ADCtwo;
      k[reg]=k[reg]>>4;
      n[reg]=7;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 7: // basic sequential length of
    if (n[reg]<0) { // 4 bits
      ADCtwo;
      k[reg]=(k[reg]>>6); // 4 bits - but works best 6 bits
      //      if (k[reg]==0) k[reg]=3;
      //      else k[reg]=0;
      //      k[reg]=0;
      n[reg]=3;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    //    if (rand()%128==1) bt=0;
    //    else bt=1;
    n[reg]--;    
    break;
    
  case 8: // try keep cycling adc with new entry on toggle or strobe STROBE
    if (strobe) toggle[reg]^=1;
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	if (toggle[reg]) {
	    ADCone;
	  }
      }
      else {
	if (toggle[reg]) {
	    ADCtwo;
	  }
      }
	n[reg]=length; // padded with zeroes then - 14/3/2022
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

    
  case 9: //  STROBEnow strobe - was! ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    // testing now for msb out 
    if (strobe) { 
      if (length>11) length=11;
      //      if (n[reg]>length) {
            if (n[reg]<0) {
	      ADCone;
	      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;
      }
    else
      {
	//	bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it - or is always 0
	bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
      }
    break;

  case 10: // basic sequential length of bits cycling in but zeroed by strobe STROBE
    if (length>11) length=11; //XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    } 
     if (strobe) bt=0;
      else bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 11: // padded case 8    // we accumulate bits onto a ghosted register ** STROBE
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt - but how can we fix that
    //      if (n[reg]>length) {
          if (n[reg]<0) {
	    ADCtwo;
	if (length<12) k[reg]=(k[reg])>>(11-length); 
	else k[reg]=(k[reg])<<(length-11);
	n[reg]=0;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { 
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    //bt=0; // leave orf
    break;
    
  case 12:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa ** STROBE
    if (strobe) toggle[reg]^=1;
      if (n[reg]<0) {
	ADCtwo;
	if (length<12) k[reg]=(k[reg])>>(11-length);
	else k[reg]=(k[reg])<<(length-11);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01;
      if (toggle[reg]) {
    n[reg]--;    
      }
    break;

  case 13:     // we accumulate bits onto a ghosted register STROBE
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { // strobe
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    bt=0;
    break;

  case 14:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa STROBE
    if (strobe) toggle[reg]^=1;

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    }
      if (toggle[reg]) {// strobe
      bt = (k[reg]>>n[reg])&0x01;
      lastbt[reg]=bt;
      }
      else bt=lastbt[reg];
    n[reg]--;    
    break;
    
  case 15:     // 2-we only cycle ADC on strobe/toggle  - or vice versa STROBE
        if (strobe) toggle[reg]^=1;
    if (length>11) length=11; //XXXmax12bits

  if (n[reg]<0) {
    ADCone;
      n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01;

      if (toggle[reg]) {// strobe
    n[reg]--;    
      }
      break;

  case 16: // STROBE: 3-one bit entry STROBE
    if (strobe) toggle[reg]^=1;
    ADCtwo;
    integrator[reg]+=(k[reg]-oldvalue[reg]);
   if(integrator[reg]>2048)
  {
     oldvalue[reg]=4095;
     bt=1;
  }
   else
   {
      oldvalue[reg]=0;
      bt=0;
   }       
   if (toggle[reg]) {
	lastbt[reg]=bt;
      }
      else bt=lastbt[reg];
   break;

  case 17: // cycling on otherpar length - otherpar is length within length
    otherpar=otherpar&31;
    if (otherpar<3) otherpar=3; //21/3
    
    if (n[reg]>otherpar) {
      ADCtwo;
      if (length<12) {
	ADCshift_[reg]=(k[reg])>>(11-length); 
      }
      else ADCshift_[reg]=(k[reg])<<(length-11);

      n[reg]=0;
    }
    n[reg]++;
    bt=(ADCshift_[reg]>>length)&0x01; // top bit
    ADCshift_[reg]=(ADCshift_[reg]<<1)+bt;
    break;

    // new mode using adc_bits
  case 18: 
    otherpar=otherpar&31; // 5 bits
    if (otherpar<3) otherpar=3;
    bt=adceqbits(otherpar);
    break;

    // new mode tested using adcpadbits
  case 19:  
    // maybe restrict otherpar
    // try with MSB or loads 0s after shift
    // doesn't work if length shorter than otherpar
    otherpar=otherpar&31; // 5 bits
    if (otherpar<3) otherpar=3;
    bt=adcpadbits(otherpar);
    break;
    ///////////////////////////////////////
    
  case 20: // otherpar as comparator - 10 bits standard here // now 12 bits  - OTHERPAR! 12 bits
     bt=0;
     ADCtwo;
     if (k[reg]>(otherpar&4095)) bt=1;
     break;

  case 21:     // use as test for bit match WORKING use length
    bt=adcpadbits(4); // try fix depth here of 4
    tmp=oscbits(otherpar,length);
    bt&=tmp;
    break;    

  case 32:     // use as test for bit match with DAC
    bt=adcpadbits(otherpar); // try fix depth here of 4
    tmp=dacpadbits(otherpar);
    bt^=tmp;
    break;    

     // 22->31 = no ADC IN just LFSR/DAC etc abstract
     
  case 22: // LFSR runs on own SR so not true LFSR - REGG! no param
    bt = ((*SR >> (lfsr_taps[SRlength[regg]][0])) ^ (*SR >> (lfsr_taps[SRlength[regg]][1])) ^ (*SR >> (lfsr_taps[SRlength[regg]][2])) ^ (*SR >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    break;

  case 23:// run true LFSR-ADCshift and output a bit  - REGG!
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
    
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

  case 24: // strobe switches direction of LFSR - REGG!  STROBE
    //      case 7:// run LFSR-ADCshift and output a bit - again if we don't use redirection of regg then ...
    if (strobe) toggle[reg]^=1;
    if (toggle[reg]){
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
    }
    else {
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]>>1)+(bt<<31);
    }
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

    // 25->27 are DAC entry which can go to 0
    
  case 25: // gate[regg].dac seq input 
      if (length>11) length=11;
      if (n[reg]<0) {
	k[reg]=(gate[regg].dac)>>(11-length);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
        
  case 26: // one bit audio input from DAC
    k[reg]=gate[regg].dac; // from 0 to 4095 but where is the middle? - also we do nothing here with length
    integrator[reg]+=(k[reg]-oldvalue[reg]);
   if(integrator[reg]>2048)
  {
     oldvalue[reg]=4095;
     bt=1;
  }
   else
   {
      oldvalue[reg]=0;
      bt=0;
   }   
   break;    
   
  case 27: // as 8 - gate[regg].dac seq input     // padded length version ** - REGG!
    if (n[reg]<0) {
      if (length<12) k[reg]=(gate[regg].dac)>>(11-length); 
      else k[reg]=(gate[regg].dac)<<(length-11 );
      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;
    
  case 28: // clkbit as bits in STROBE STROBE
    bt=strobe;
    break;

  case 29:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=0;
       if (nn[reg]>=otherpar) { // so equal bits from 0 / length 0 = 101010
	 n[reg]=0;
       }
       nn[reg]++;
     } // n[reg]
     
     else {
       bt=1;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 30: // osc - 3/12/2021 - 101010 clock at speed - ultrasonic at fastest speeds
    // TODO: but is same more or less as static bit pattern which could be imposed at intervals
    lastbt[reg]^=1;
    bt=lastbt[reg];
    break;

  case 31: // strobe mode for cycling bits a la TM - no input
    //    bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    	bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (strobe){
      bt=!bt;// invert cycling bit
    }
    break;
    /*
  case 32: // In progress  test mode for spaced sequential entry of 12 bits
      if (n[reg]>length) {
	if (length<12) k[reg]=(adc_buffer[12])>>(11-length); // fill so no spacings
	else {
	  // try for reverse
	  k[reg]=(adc_buffer[12]); // below for LSB first so reverse for MSB
	  k[reg]=(k[reg]&0x01) + ((k[reg]&space[length-11][0])<<spaceshift[0][length-11]) + ((k[reg]&space[1][length-11])<<spaceshift[1][length-11]) + \
	    ((k[reg]&space[2][length-11])<<spaceshift[2][length-11]) + ((k[reg]&space[3][length-11])<<spaceshift[3][length-11]) + \
	    ((k[reg]&space[4][length-11])<<spaceshift[4][length-11]) + ((k[reg]&space[5][length-11])<<spaceshift[5][length-11]) + \
	    ((k[reg]&space[6][length-11])<<spaceshift[6][length-11]) + ((k[reg]&space[7][length-11])<<spaceshift[7][length-11]) + \
	    ((k[reg]&space[8][length-11])<<spaceshift[8][length-11]) + ((k[reg]&space[9][length-11])<<spaceshift[9][length-11]) + \
	    ((k[reg]&space[10][length-11])<<spaceshift[10][length-11]) + ((k[reg]&space[11][length-11])<<spaceshift[11][length-11]);
	}
	n[reg]=0;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]++;    
    break;
    */
  case 33: //  was 9 back to ADC - was! ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...    
    // testing now for msb out
    if (((LFSR_[reg] & 4095 ) < otherpar)){
      if (length>11) length=11;
      //      if (n[reg]>length) {
            if (n[reg]<0) {
	      ADCone;
	      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;
      }
    else
      {
	//	bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it or is always 0!
	bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
      }
    break;

  case 34:// swapped // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=1;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=0;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

// prob instead of strobe: 12,13,14,15,16 -> re-work NOW/here in ADC_
//     if (((LFSR_[reg] & 4095 ) < otherpar)){
     
  case 35:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa **
      if (n[reg]<0) {
	ADCtwo;
	if (length<12) k[reg]=(k[reg])>>(11-length);
	else k[reg]=(k[reg])<<(length-11);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01;
     if (((LFSR_[reg] & 4095 ) < otherpar)){
    n[reg]--;    
      }
    break;

  case 36:     // we accumulate bits onto a ghosted register
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

     if (((LFSR_[reg] & 4095 ) < otherpar)){
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    bt=0;
    break;

  case 37:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    }
     if (((LFSR_[reg] & 4095 ) < otherpar)){
      bt = (k[reg]>>n[reg])&0x01;
      lastbt[reg]=bt;
      }
      else bt=lastbt[reg];
    n[reg]--;    
    break;
    
  case 38:     // 2-we only cycle ADC on strobe/toggle  - or vice versa

    if (length>11) length=11; //XXXmax12bits

  if (n[reg]<0) {
    ADCone;
      n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01;

     if (((LFSR_[reg] & 4095 ) < otherpar)){
    n[reg]--;    
      }
      break;

  case 39: // STROBE: 3-one bit entry
    ADCtwo;
    integrator[reg]+=(k[reg]-oldvalue[reg]);
   if(integrator[reg]>2048)
  {
     oldvalue[reg]=4095;
     bt=1;
  }
   else
   {
      oldvalue[reg]=0;
      bt=0;
   }   

   if (((LFSR_[reg] & 4095 ) < otherpar)){
	lastbt[reg]=bt;
      }
      else bt=lastbt[reg];
   break;

    /////////////////////// add modes

  case 66: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCtwo;
	k[reg]=(k[reg]%otherpar)>>(11-length);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 67: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCtwo;
	tmp=k[reg]+otherpar;
	if (tmp>4095) tmp=0;
	k[reg]=(tmp)>>(11-length); // now we have 12 bits
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 68: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCtwo;
	k[reg]=(k[reg]&otherpar)>>(11-length);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 71: // dac in equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      k[reg]=(gate[regg].dac); 
      k[reg]=k[reg]/divy[length];
      n[reg]=0;
    }
    if (k[reg]!=0) {
      bt=1;
      k[reg]--;
    }
    else bt=0;
    n[reg]++;    
    break;

  case 72: // dac in basic sequential length as in 0 but with padding if >11 bits **
    // as above but closer to 5
    // also try as MSB - now...
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	k[reg]=(gate[regg].dac)>>(11-length);
	n[reg]=length;
      }
      else {
	//	ADctwo;
	k[reg]=(gate[regg].dac);
	n[reg]=11;
      }
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 73:  // dac in special case for spaced bit entry depending on length
    *SR &=spacmask[length]; //cleared
    k[reg]=(gate[regg].dac)>>8; // we want 4 bits
    *SR+=(k[reg]&1)+((k[reg]&2)<<spacc[length][0])+((k[reg]&4)<<spacc[length][1])+((k[reg]&8)<<spacc[length][2]);
    // 4 bits goes in
    // no bt return
    bt=0;
    break;   
    
  case 74: // dac in basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
        ////// full length regardless of len    
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k[reg]=(gate[regg].dac);
	n[reg]=11;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 75: // other dac as comparator 
     bt=0;
     ADCtwo;
     if ((k[reg])>((gate[regg].dac))) bt=1;
     break;

  case 76: // own dac as comparator 
     bt=0;
     ADCtwo;
     if (k[reg]>((gate[0].dac))) bt=1;
     break;

  case 77:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - DAC- OTHERPAR! 12 bits
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=(gate[regg].dac); // test also as own dac
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=0;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=1;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 78:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - DAC- OWN DAC
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=(gate[regg].dac); // test also as own dac
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=0;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=1;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 79:// swopped as 34 // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - DAC- OTHERPAR! 12 bits
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=(gate[regg].dac); // test also as own dac
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=1;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=0;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 80:// swopped as 34 // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - DAC- OWN DAC
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=(gate[regg].dac); // test also as own dac
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=1;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=0;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 81: // basic 4 bits in
    // try new ADC scheme
      if (n[reg]<0) {
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
	ADC_SoftwareStartConv(ADC1);
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	k[reg]=ADC_GetConversionValue(ADC1)>>8;
	//		k[reg]=1; // testing for a repeated pattern - could be prob of a grab... SR wheel in SR
	n[reg]=3;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
    break;
    
  case 82: // how we could use entry bit as comparator - but then we don't want any binroute
     bt=0;
     tmp = (gate[inroute[count][0]].Gshift_[0]>>SRlength[inroute[count][0]]) & 0x01;
     tmp=tmp<<11; // upto 2048
     ADCtwo;
     if (k[reg]> tmp) bt=1;
     break;
    
  case 1010: // speed bump based on 0 skip bits
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCone;
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;
      n[reg]--;
    break;

    //TRY: cycling bit XOR with --> [DACout from own/other SR vs. comparator=CV/DAC/DAC+CV/CLKCNT???]*

  case 84: // own dac as comparator against DAC+CV
    tmp=gate[0].dac-(otherpar);
    if (tmp<0) tmp=0;
     bt=0;
     ADCtwo;
     if (k[reg]>tmp) bt=1;
     break;

  case 85: // comp at 2048 middle...
    ADCtwo
      if (k[reg]>2048) bt=1;
      else bt=0;
    break;

  case 86: // gate[regg].dac seq input ->     //    TODO: *cut feedback - eg. cut for CV count clk pulses/on off*
    //count clk pulses, compare to CV
    // originally swicthed between dacs but that doesn't work so well without input
    if (strobe) nn[reg]++;
    if (nn[reg]>otherpar){ // range of otherpar?
	nn[reg]=0;
	toggle[reg]^=1;
      }
    // changed 26/2 for instant change
    if (length>11) length=11;
      if (n[reg]<0) {
	//	k[reg]=(gate[regg].dac)>>(11-length); // switch between dac 3 and dac 1
	lastbt[reg]=(gate[3].dac)>>(11-length); // switch between dac 3 and dac 1
	//k[reg]=(gate[1].dac)>>(11-length); // switch between dac 3 and dac 1
	ADCone; // adc
	n[reg]=length;
      }
      if (toggle[reg]) bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      else bt = (lastbt[reg]>>n[reg])&0x01; // this means that MSB comes out first
      //      bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 87: // basic 4 bits in - grab into SR on STROBE 
    // changed for toggle 26/2
    if (strobe) toggle[reg]^=1;
 
    if (n[reg]<0) {  // can also be if (n[reg]<0 || toggle[reg])
      if (toggle[reg]){
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
	ADC_SoftwareStartConv(ADC1);
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	k[reg]=ADC_GetConversionValue(ADC1)>>8;
      }
	n[reg]=3;
      }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
    break;

  case 88: // - if CV>DAC - entry of new bit from [ADC, route or cycle] XOR cycle/route etc... - use what for this choice of route - detached
    // see modeN.h
     bt=0;
     ADCtwo;
     if ((k[reg])>((gate[regg].dac))) { 
       if (otherpar==255){ // then we 4 bits in of adc
      if (n[reg]<0) {
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
	ADC_SoftwareStartConv(ADC1);
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	k[reg]=ADC_GetConversionValue(ADC1)>>8;
	n[reg]=3;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
       }
	 else       bt=otherpar;
     }
     break;

  case 89: // kind of impulses no ADC in - uses strobe so noINT - must be DETACHED...
    if (strobe) bt=onebits(otherpar,reg);
    else bt=onebits(0,reg);
    break;

  case 90: // trial for 0v = 0 bits - equiv energy
        if (n[reg]>length) {
      ADCtwo;
      tmp=k[reg]-2048;
      k[reg]=abs(tmp);
      k[reg]=k[reg]/divy[length];
      n[reg]=0;
    }
    if (k[reg]!=0) {
      bt=1;
      k[reg]--;
    }
    else bt=0;
    n[reg]++;    
    break;

  case 91:     // use as test for bit match with DAC
    bt=adcpadbits(4); // try fix depth here of 4
    tmp=dacpadbits(otherpar);
    if (tmp) 	bt = (gate[reg].Gshift_[reg]>>length) & 0x01; //bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it - or is always 0 
    break;    

    // different encodings but all are so far 12 bits in and ignoring depth and length, other encodings
    
  case 92: // basic sequential length of 12 bits cycling in with subtract of otherpar (max 12 bits)
    if (n[reg]<0) { // 12 bits
      ADCtwo;
      tmp=k[reg]-otherpar;
      if (tmp<0) k[reg]=0;
      else k[reg]=tmp;
      n[reg]=11;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 93: // basic sequential length of x bits cycling in with -2048
    if (n[reg]<0) { // trial 8 bits which is really 7 bits
      ADCtwo;
      k[reg]=k[reg]>>4;// 8 bits
      tmp=k[reg]-127;
      if (tmp<0) k[reg]=0;
      else k[reg]=tmp;
      //      k[reg]=abs(tmp);
      n[reg]=6;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 94: // basic sequential length of 12 bits cycling in with -2048 // abs
    if (n[reg]<0) { 
      ADCtwo;
      k[reg]=k[reg]>>7;
      tmp=k[reg]-15;
      k[reg]=abs(tmp);
      n[reg]=3;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 95: // basic 4 bits pattern in - grab into SR on STROBE
    // but we need different patterns - detach
    //    if (strobe) toggle[reg]=1;
 
    if (n[reg]<0 || strobe){
      if (strobe){
	otherpar=otherpar&15;
	k[reg]=pattern[otherpar];
	//	k[reg]=0b1010;
      }
	n[reg]=3;
      }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
    break;

  case 96: // trial of straight x bits in on strobe/... 4 bits
    if (strobe){
      // mask in
      *SR&=invmasky[3]; // clear length bits
      ADCtwo;
      *SR+=k[reg]>>8; // top 4 bits
    } // no bt
    bt=0;
    break;    

  case 97: // 4 bits straight 
    *SR&=invmasky[3]; // clear length bits
    ADCtwo;
    *SR+=k[reg]>>8; // top 4 bits
    bt=0;
    break;    

  case 98: // 4 bits straight - toggle selects adc or dac...
    if (strobe) toggle[reg]^=1;
    *SR&=invmasky[3]; // clear length bits
    
    if (toggle[reg]){
    ADCtwo;
    *SR+=k[reg]>>8; // top 4 bits
    }
    else {
      *SR+=gate[regg].dac>>8; // top 4 bits
    }
    bt=0;
    break;    

  case 99: // switch SR on toggle between adc and dac - 4 bits
    if (strobe) toggle[reg]^=1;
     if (n[reg]<0){
      if (toggle[reg]){
	ADCtwo;
	k[reg]=k[reg]>>8; // 4 bits
      }
      else {
	k[reg]=gate[regg].dac>>8; // 4 bits
      }
	n[reg]=3;
      }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
    break;

  case 100: // sliding splice in of x bits at position y on strobe - as in 96
    // so either 2 params or we just slide in 4 bits - trial here - otherpar and we don't use length
    if (strobe){
      // mask in
      *SR&=movemasky[otherpar]; // clear length bits
      ADCtwo;
      *SR+=(k[reg]>>8)<<otherpar; // top 4 bits - we can also try other logops in and obviously no mask in those cases
    } // no bt
    bt=0;
    break;    

    // variations on this - and can also be used for other SRs
    // variations: trial with adc bits in also (AND as in addition)-, in modeN with/without route, dac+otherpar, just dac, all comp options
  case 101: // exact Turing machine - add otherpar and ADC and compare noise to this for loop or not
    ADCtwo;
    k[reg]+=otherpar; // CVL is also knob+CV so we have 2 CVs
    if (k[reg]>4095) k[reg]=4095;
    //    bt=(*SR>>length)& 0x01;
    bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (k[reg]>(LFSR_[reg]&4095)) bt=!bt;
    break;

  case 102: // with bits in from adc - exact Turing machine - add otherpar and ADC and compare noise to this for loop or not //***
    // bits OR/add in can be before or after the inversion
    //    bt=(*SR>>length)& 0x01;
    bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (otherpar>(LFSR_[reg]&4095)) bt=!bt;
    bt|=adcpadbits(length);
    break;

    // inv of incomings
  case 103: // with bits in from adc - exact Turing machine - add otherpar and ADC and compare noise to this for loop or not
    ADCtwo;
    k[reg]+=otherpar; // CVL is also knob+CV so we have 2 CVs
    // bits AND/add in can be before or after the inversion
    bt=adcpadbits(length);
    if (otherpar>(LFSR_[reg]&4095)) bt=!bt;
    break;

    //TM in TM:    static inline uint32_t TMbits(uint32_t depth, uint32_t seq, uint32_t rndd, uint32_t par){  // for TM in TM, return inv or loop bits
  case 104:
    // select sequence for TM in TM - we can choose just to use bt from loop or loop it back in
    // these kind of recursive modes which interrupt themselves... eg. feedback before we have feedback decided at faster speed
    // how many CV? depth=length, position to get seq, par is parameter. = 3x so we use ADC_ for parameter, but leaves 2x cv we don't have
    // so fix length ???
    ADCtwo;
    tmp=otherpar>>7; // 5 bits is our offset
    //    length=31-(tmp+length); //length is fixed if we detach
    bt=*SR&(masky[length]<<tmp); /// our seq
    bt=bt>>tmp;
    if ((length+tmp)>31){
      length=31-tmp;
    }
    bt=TMbits(length, bt, LFSR_[reg]&4095, k[reg]);
    // pull in adcbits
    bt|=adcpadbits(length);
    break;

  case 105: // exact Turing machine - add otherpar and DAC and compare noise to this for loop or not
    tmp=otherpar; // CVL is also knob+CV so we have 2 CVs - we don't need to deatch and can use CV here 
    tmp+=gate[dacfrom[daccount][0]].dac;
    if (tmp>4095) tmp=4095;
    //    bt=(*SR>>length)& 0x01;
    bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (tmp>(LFSR_[reg]&4095)) bt=!bt;
    break;

  case 106: // exact Turing machine - add otherpar and DAC and compare noise to this for loop or not
    ADCtwo;
    tmp=k[reg]; // CVL is also knob+CV so we have 2 CVs - we don't need to deatch and can use CV here 
    tmp+=gate[dacfrom[daccount][0]].dac;
    if (tmp>4095) tmp=4095;
    //    bt=(*SR>>length)& 0x01;
    bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (tmp>(LFSR_[reg]&4095)) bt=!bt;
    break;
    
  case 107:
    // osc1bits
    bt=osc1bits(length,reg);
    break;

  case 108:
    // 2scompadcbits - always 12
    bt=adc12compbits(length);
    break;

  case 109:
    // 2scompadcbits - 
    bt=adccompbits(length); // can also be otherpar for depth
    break;

  case 110:
    /// ones compliment - always 12 bits
    bt=adc12onecompbits(length); 
    break;

  case 111:
    /// ones compliment
    bt=adconecompbits(length); // can also be otherpar for depth adconecompbits
    break;

  case 112:
    /// 2 complimentDAC - now with mix
    bt=daccompbits(length); // can also be otherpar for depth adconecompbits
    bt|=adccompbits(length); // can also be otherpar for depth
    break;


    ///////////////////////
  } // switch
  return bt;
}

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

//0-15 so 16 modes
static inline uint32_t DAC_(uint32_t wh, uint32_t shift, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t strobe){  // DAC is 12 bits
  int32_t x=0;
  static uint32_t n[4]={0,0,0,0};
  static uint32_t nom[4]={0,0,0,0};
  static float SmoothData[4]={0.0, 0.0, 0.0, 0.0};
  static uint32_t lastout[4]={0,0,0,0};
  static uint32_t toggle[4]={0,0,0,0};
  float betaf=0.4f;
  int32_t rem;
  uint32_t y,tmp;
  
  switch(type){

  case 666: // null case for testings
    x=0;
    break;
    
  case 66: // default for all other DACs - modded for new draft
    x=( (shift & masky[length])>>(rightshift[length]))<<leftshift[length];
    //    x=shift_[reg]&4095;
    break;

  case 67: // 4 bit DAC aside from length - try now with delay
    if (n[wh]>3) {
      n[wh]=0;      
      x=( (shift & masky[3])>>(rightshift[3]))<<leftshift[3];
      lastout[wh]=x;
    }
    x=lastout[wh];
    //    x=0;
    n[wh]++;              
    break;

  case 68: // straight 4 bit dac
    x=( (shift & masky[3])>>(rightshift[3]))<<leftshift[3];
    break;    

    
  case 0: // length doesn't change much except at slow speeds - ADC x bits out - modded for new draft
    if (length==3){
      if ((shift&4)==4) x=4095; // changed 28/12
      else x=0;
    }
        else     x=( (shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; // doublecheck
    //    else  x=( (shift & masky[length])>>(rightshift[length]))<<leftshift[length];
    //    else x=(shift&4095);

    break;
    
  case 1:// equivalent bit DAC for x bits - 3/11 - 32 bits max now
    x=countbits(shift &masky[length]); // lower length bits only
    y=divy[length]; // added table for this 7/10 - updated for 32 bits
    x*=y;
    if (x>4095) x=4095;
    break;

  case 2: // one bit audio but with beta as param
    // beta is now (6/12/2021) always param - just if is generated from cv or speed or ... betaf=0.4f is usual value
    // 0.4=par/4096.0
    if (otherpar==0) otherpar=1;
    if (otherpar>4096) otherpar=4096;
    betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
    y=(shift >>length)&1;
    if (y==1) x=4095;
    else x=0;
    SmoothData[wh] = SmoothData[wh] - (betaf * (SmoothData[wh] - x));
    x=(int)SmoothData[wh];
    break;

  case 3: //spacers 
    x = (shift&0xFF)<<4; // just the lower 8 bits - no spacings
    if (length>7){ // real length >8
      x = ((shift & 0x01) + ((shift>>pos[length][1])&0x02) + ((shift>>pos[length][2])&0x04) + ((shift>>pos[length][3])&0x08) + ((shift>>pos[length][4])&0x10) + ((shift>>pos[length][5])&0x20) + ((shift>>pos[length][6])&0x40) + ((shift>>pos[length][7])&0x80))<<4;
      //       {0, 0, 1, 3, 6, 10, 15, 21} // for 32 bits = length=31 - check sense of this
    }
    break;

  case 4: // only output standard DAC on param->strobe/clock! so just maintain lastout
    if (strobe) {
      x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
      lastout[wh]=x;
    }
    else x=lastout[wh];
    break;

  case 5: // toggle to hold/release DAC
    if (strobe) toggle[wh]^=1;
    if (toggle[wh]) {
      x=lastout[wh];
    }
    else {
      x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
      lastout[wh]=x;
    }      
    break;

  case 6: // 4 spaced bits out! equiv bits or not - in this case not
    x= ( ( (shift& (1<<lastspac[length][0]))>>lastspacbac[length][0]) + ((shift& (1<<lastspac[length][1]))>>lastspacbac[length][1]) + ((shift& (1<<lastspac[length][2]))>>lastspacbac[length][2]) + ((shift& (1<<lastspac[length][3]))>>lastspacbac[length][3]) )<<8; // 4 bits to 12 bits
    break;

  case 7: // 4 spaced bits out! equiv bits
    x= ( ((shift& (1<<lastspac[length][0]))>>lastspacbac[length][0]) + ((shift& (1<<lastspac[length][1]))>>lastspacbac[length][1]) + ((shift& (1<<lastspac[length][2]))>>lastspacbac[length][2]) + ((shift& (1<<lastspac[length][3]))>>lastspacbac[length][3]) ); 
    x=countbts[x]*1023;
    if (x>4095) x=4095;
    break;

  case 8: // one SR is sieved out over another? as DAC option. XOR as sieve? AND as mask! TODO
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; 
    x=x^(((gate[sieve[wh]].shift_ & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]); // seived through previous SR
    break;

  case 9: //  one SR is sieved out over clksr for that sr. XOR as sieve?  - SKIPPED/retry instead of 11
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; 
    x=x^((clksr_[wh] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; 
    break;

  case 10:// standard bit DAC for x bits     ///bitx length as other param rather than length:
    // but then we don't really use len? unless is cycle back
    // try now 21/12/2021 using length
    // bit length can also be CV - how to put this in as DAC is quite fixed in macro?
    otherpar=otherpar&31; //5 bits
    rem=length-otherpar;
    if (rem<0) rem=0;
    x=((shift & masky[rem])>>(rightshift[rem]))<<leftshift[rem]; 
      break;

      // sequential DACs
  case 11: // we wait for length bits then output that many bits from the top of the SR (len bit) - not really working
    if (n[wh]>length) {
      n[wh]=0;      
      x=((shift & masky[length])>>(rightshift[length]))<<leftshift[length];
      lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 12: // we wait for otherparam bits then output that many bits from the top of the SR (len bit)
    //    length=3; // is good to vary length AND otherpar AND speed - Cint12 does this
    // can also be x number of equiv bits TRY!
    otherpar=otherpar&31; //5 bits
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

  case 13:// par is mask on standard bit DAC for x bits
    //    if (wh<4 && length>3 && length<32) 
    // why (length-3)? to get down to 1 bit so could also have option for full bits!
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
    x=x|(otherpar&4095);
      break;

  case 14:/// we record mask and use this to mask the regular DAC... - could also be other-than-standard DACs
    if (strobe) // we record the mask 
	{
	  mask[wh]=(otherpar&4095); // or reg can be otherpar/SR
	  }
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
    x=x|mask[wh];
    break;

    //    // case 15 was as case 2 but with param for filter - and now always has param

  case 15:// standard bit DAC for x bits - new mode here

    if (n[wh]>length) {
      n[wh]=0;
    if (length==3){
      if ((shift &4)==4) x=4095;
      else nom[wh]=0;
    }
    else nom[wh]=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; // we want 12 bits but is not really audible difference //Q of least bits
    }
    n[wh]++;
    x=nom[wh];
    break;

  case 16: // 22/3/2022 sliding bits.moving window - we have depth/length and where it is, wrap or not, shift or not
    // use detached length for length, and otherpar&31 for where it is, try no wrap
    // note: SRlength_[wh] or treat as full length/yes
    if (length>11) length=11;
    otherpar=otherpar&31; //5 bits
    // topbits
    x=shift&(masky[length]<<otherpar); 
    // bottom bit   
    tmp=(otherpar+length);
    if (tmp>31){
      tmp=tmp-31;
      y=shift&masky[tmp]; //       tmp=(otherpar+length)-31;
      x=x>>(otherpar-tmp);
      x=x+y;
    }
    else x=x>>otherpar;
    break;

  case 17: // fixed 12 bits in 2s complement back to our encoding - but we have no use for length - except perhaps
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

  case 18: // fixed 12 bits in 2s complement back to our encoding - but we have no use for length - except perhaps
    // try delay
    if (n[wh]>length) { // this could also be otherpar
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

  case 19: //  2s complement back to our encoding 
    // variable bits out
    // try delay or no delay
    if (n[wh]>length) { // this could also be otherpar // either or...
      n[wh]=0;      
      x=shift&masky[length]; // x bits
      if (x&(1<<length)) {
	x = x | ~((1 << (length+1))-1);
    }
      x=x+(1<<length);
      // shift back to 12 bits...
      lastout[wh]=((x&masky[length])>>rightshift[length])<<leftshift[length]; 
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 20: // fixed 12 bits in ONES complement back to our encoding - but we have no use for length - except perhaps
    // try delay
    if (n[wh]>length) { // this could also be otherpar
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

  case 21: //  ONEs complement back to our encoding 
    // variable bits out
    // try delay or no delay
    if (n[wh]>length) { // this could also be otherpar // either or... - but how do we get length AND otherpar // except detach speed...
      n[wh]=0;      
      x=shift&masky[length]; // x bits
      if (x&(1<<length)) {
	x=~x;
	x&=masky[length];
	x=(1<<length)-x;
    }
      else  x=x+(1<<length);
      // shift back to 12 bits...
      lastout[wh]=((x&masky[length])>>rightshift[length])<<leftshift[length]; 
    }
    x=lastout[wh];
    n[wh]++;              
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
  param[0]=counter_[0];
  counter_[0]=0;
  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
  uint32_t tmp, tmpp;
  uint16_t j, bit, xx, x;
  uint32_t lengthbitl=15, new_statl, new_statr,new_statc, lengthbitc=15, lengthbitr=15; // for 2nd bit on lsr, rsr and csr
    
  if (EXTI_GetITStatus(EXTI_Line5) != RESET) { //RSR  
    intflag[3]=1; //RSR
    param[3]=counter_[3];
      counter_[3]=0;
    EXTI_ClearITPendingBit(EXTI_Line5);
 }

  if (EXTI_GetITStatus(EXTI_Line6) != RESET) { //LSR
    intflag[1]=1; //LSR
    param[1]=counter_[1];
    counter_[1]=0;
    EXTI_ClearITPendingBit(EXTI_Line6);
 } 

  if (EXTI_GetITStatus(EXTI_Line7) != RESET) {// CSR
    intflag[2]=1; //CSR
    param[2]=counter_[2];
    counter_[2]=0;
    EXTI_ClearITPendingBit(EXTI_Line7);
 } 
}

void TIM4_IRQHandler(void) 

{
  uint32_t temp;
  //  volatile static uint16_t tmp;

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
  /// TODO TEST->fixed for new ADC scheme  
  //moden
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(adc_buffer[2]+lastlastmoden+lastmoden)/3; 
  temp=(temp+lastlastmoden+lastmoden)/3; 
  lastlastmoden=lastmoden;
  lastmoden=temp;
  mode[0]=(temp>>6); // 64 modes = 6 bits  

  // modec
  ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(adc_buffer[11]+lastlastmodec+lastmodec)/3;
  temp=(temp+lastlastmodec+lastmodec)/3; 
  lastlastmodec=lastmodec;
  lastmodec=temp;
  mode[2]=(temp>>6); // 64 modes = 6 bits  

  // model
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  temp=(temp+lastlastmodel+lastmodel)/3; 
  //  temp=(adc_buffer[5]+lastlastmodel+lastmodel)/3; 
  lastlastmodel=lastmodel;
  lastmodel=temp;
  mode[1]=(temp>>6); // 64 modes = 6 bits  

  // moder
  ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(adc_buffer[8]+lastlastmoder+lastmoder)/3;
  temp=(temp+lastlastmoder+lastmoder)/3; 
  lastlastmoder=lastmoder;
  lastmoder=temp;
  mode[3]=(temp>>6); // 64 modes = 6 bits  
  
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
  CV[0]=temp;
  speedf[0]=logspeed[temp>>2];
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
  CV[1]=temp;
  speedf[1]=logspeed[temp>>2];
  
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
  CV[3]=temp;
  speedf[3]=logspeed[temp>>2];
  
    // speedc
  totc=totc-smoothc[cc];
  //  smoothc[cc]=adc_buffer[9];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothc[cc]=ADC_GetConversionValue(ADC1);

  totc+=smoothc[cc];
  cc++;
  if (cc>=SMOOTHINGS) cc=0;
  temp=totc/SMOOTHINGS;  
  CV[2]=temp;
  speedf[2]=logspeed[temp>>2];
  
  // lens from 4 to 32 - 8/11/2021 we reversed the list to save some time!

  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(adc_buffer[1]);
  CVL[0]=temp;
  temp=temp>>7; // 12 bits to 5 bits
  SRlength_[0]=lookuplenall[temp];

  //temp=(adc_buffer[4]);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);

  CVL[1]=temp;
  temp=temp>>7; 
  SRlength_[1]=lookuplenall[temp];
  //  SRlength_[1]=31;
  //  temp=(adc_buffer[7]);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  CVL[3]=temp;
  temp=temp>>7; 
  SRlength_[3]=lookuplenall[temp];
  
  //temp=(adc_buffer[10]);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  CVL[2]=temp;
  temp=temp>>7; 
  SRlength_[2]=lookuplenall[temp];
}
