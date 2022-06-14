/*

// for new geomantic abstraction: start again again with generics - this one for binroutes
//     [need better labelling scheme]

- for speeds/bits - return bits - for adc=bits: can be adc, dac (as input with adc style processing), or bits as for speed/bits - make more generic

but speed ones handle dac/interpol

- for length: return length/0-31 - could plug in other functions
// so length as seperate or as a re-processor...

merge all bits for speeds, for adc

how to label/categorise: 

- deal with a route
- abstract bit routines
- process a value
- deal with adc
- deal with dac but:

could we even abstract out further so adc/13 is depth input - but also look at adcs
and function is a processor of these to return bits

*/


//////////////////////////////////////////////////////////////////////////
//0
//lengths

static uint8_t held[4]={0,0,0,0};

// we can fork in processors here...

static inline uint32_t rlen(uint32_t depth, uint32_t wh){
  held[wh]=0; // release hold for all lengths
  uint32_t bt=lookuplenall[depth>>7]; // 5 bits
  return bt; // bt is a value
}

// hold old [CVL/depth] length
static inline uint32_t holdlen(uint32_t depth, uint32_t wh){
  static uint32_t oldd=0;
  if (held[wh]==0) oldd=depth;
  held[wh]=1;  
  uint32_t bt=lookuplenall[oldd>>7]; // 5 bits
  return bt; // bt is a value
}

//////////////////////////////////////////////////////////////////////////
//1
//routes

static inline uint32_t binrout(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t binroutfixed(uint32_t depth, uint32_t in, uint32_t wh){   // fixed
  uint32_t bt=0, bitrr;
  depth=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binroutesel0(uint32_t depth, uint32_t in, uint8_t w){
  uint32_t x, tmp, bitrr, bitn=0;
    uint32_t tmpp=binroutetypes[binroutetypecount][w];
    switch(tmpp){
    case 0:
      BINROUTE_;
    break;
    case 1:
      BINROUTESR_;
    break;
    case 2:
      BINROUTEalt_;
    break;
    case 3:
      BINROUTEZERO_;
    break;
    case 4:
      BINROUTESHARE_;
    break;
    case 5:
      BINROUTENOG_;
    break;
    case 6:
      BINROUTEtrig_;
    break;
    case 7:
      BINROUTEnoalt_;  // new one which just cycles and doesn't reset
    break;
    }
    return bitn;
}

static inline uint32_t binroutesel1(uint32_t depth, uint32_t in, uint8_t w){ // depth is route
  uint32_t x, tmp, bitrr, bitn=0;
  uint32_t tmpp=binroutetypes[binroutetypecount][w];
  depth=depth>>8; // 12 bits to 4 bits
  depth=depth|binary[w];
  // deal with no route
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bitn=bitrr;
  } else
    {
      tmp=depth;
    switch(tmpp){
    case 0:
      BINROUTE_;
    break;
    case 1:
      BINROUTESR_;
    break;
    case 2:
      BINROUTEalt_;
    break;
    case 3:
      BINROUTEZERO_;
    break;
    case 4:
      BINROUTESHARE_;
    break;
    case 5:
      BINROUTENOG_;
    break;
    case 6:
      BINROUTEtrig_;
    break;
    case 7:
      BINROUTEnoalt_;  // new one which just cycles and doesn't reset
    break;
    }
    }
    return bitn;
}

static inline uint32_t binroutesel2(uint32_t depth, uint32_t in, uint8_t w){ // depth is sel of type
  uint32_t x, tmp, bitrr, bitn=0;
  uint32_t tmpp=depth>>9; // 3 bits
    switch(tmpp){
    case 0:
      BINROUTE_;
    break;
    case 1:
      BINROUTESR_;
    break;
    case 2:
      BINROUTEalt_;
    break;
    case 3:
      BINROUTEZERO_;
    break;
    case 4:
      BINROUTESHARE_;
    break;
    case 5:
      BINROUTENOG_;
    break;
    case 6:
      BINROUTEtrig_;
    break;
    case 7:
      BINROUTEnoalt_;  // new one which just cycles and doesn't reset
    break;
    }
    return bitn;
}


//////////////////////////////////////////////////////////////////////////
//3
//speeds

static inline uint32_t spdfrac(uint32_t depth, uint32_t in, uint32_t wh){ // for speed now with dac/interpol pulled out
  uint32_t bt=0;
  float speed;
  speed=logspeedd[depth>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  if(gate[wh].last_time<gate[wh].int_time) {
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfrac2(uint32_t depth, uint32_t in, uint32_t wh){ // we add depth and in
  uint32_t bt=0;
  float speed;
  int32_t tmp;

  //  tmp=(depth>>2)-512;
  //  tmp+=(in>>2);  
  //  if (tmp<0) tmp=0;
  //  else if (tmp>1023) tmp=1023;
  if (depth==0) depth=1;
  tmp=in%depth;
  speed=logspeedd[tmp>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  if(gate[wh].last_time<gate[wh].int_time) {
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  return bt;
}

static inline uint32_t strobe(uint32_t depth, uint32_t in, uint32_t wh){   // strobe - no depth
  uint32_t bt;
  bt=gate[wh].trigger;
  return bt;
}

//////////////////////////////////////////////////////////////////////////
//4
//generic

// zero/nada
static inline uint32_t zeros(uint32_t depth, uint32_t in, uint32_t wh){  // returns only zeroes
  return 0;
}

// one - can also be for speeds or otherwise
static inline uint32_t ones(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt=1;
  return bt;
}

// top bit of clksr 
static inline uint32_t clksr(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt=0;
  bt=(clksr_[wh]>>depth)&0x01;
  return bt;
}

// how could we cycle through clksr if it is not moving - we need gsr for them -clksrG_
static inline uint32_t clksrG(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0;
  bt=(clksrG_[wh]>>depth)&0x01;
  clksrG_[wh]=(clksrG_[wh]<<1)+bt; // this also changes patterns there
  return bt;
}

static inline uint32_t sigmadelta(uint32_t depth, uint32_t in, uint32_t wh){  // processor for any int/depth
  uint32_t bt=0;
  static int32_t integrator=0, oldValue=0;
  
  integrator+=(depth-oldValue);
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
  return bt;
}

// try 8 bit cipher mode
//ADC/depth in comparator -> bits, clked/speed into GGSR which shifts along, on strobe GGSR copied to SR
static inline uint32_t cipher(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt, k;
  //  uint32_t kw[4]={0,0,0,0};
  static uint32_t gs[4]={0,0,0,0};
  //  kw[wh]=depth;
  //  depth=(depth-2048)<<1;
  if (depth>(2000)) bt=1; // we ignore depth - what it could be used for...
  else bt=0;
  
  // onto SR
  GGGshift_[wh]=GGGshift_[wh]<<1;
  GGGshift_[wh]+=bt;
  // on strobe copy to gs
  if (gate[wh].trigger) gs[wh]=GGGshift_[wh];
  bt=(gs[wh]>>8)&0x01; // how long?
  //  gs[wh]=gs[wh]<<1; // that one doesn't shift
  
  return bt;
}

static inline uint32_t osceq(uint32_t depth, uint32_t in, uint32_t wh){  // so all share
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

//////////////////////////////////////////////////////////////////////////
//5
//adc - these just become interpreters for depth values which can be adc!

static inline uint32_t adcx(uint32_t depth, uint32_t in, uint32_t wh){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      if (depth>11) depth=11; // max depth
      k=in>>(11-depth); //   k=ADC_GetConversionValue(ADC1)>>(11-depth); \
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

