// 20/4/2022

//TODO::
// still todo experiment with shared bits
// cut all routes // open close route bit with clock/toggle
// see    (*moodsfuncs[0])(www, &moodsw[0]);  below - but no interpol there... -> re-work that with  what we have here for interpol


// DONE:
// rungler in rungler but split across - is this not what we have with abstracted out versions below
// how we define independent rungler: as below IN=binroute and spdfrom=binroute but it has cycle...

//*abstract out interpol and strobe*
// start with basic function exposed

void base(uint8_t w){ // basic template
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_; 
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}

/*
- interpol is function of dac - ignore for now then fill in

// why we have dac outside of any movement
    alpha = gate[w].time_now - (float)gate[w].int_time; // we put alpha into SR struct and into speedfrac
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;				\

vs. for no inter
    gate[w].dac = delay_buffer[w][1];

for no inter we can be inside speed//otherwise outside...

later inside speed:

    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger);
    new_data(val,w); // puts val into [1]
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;

- fractional speed as external
    new_data(val,w);
    gate[w].time_now += speedf_[w];
    gate[w].last_time = gate[w].int_time;
    gate[w].int_time = gate[w].time_now;
 */

static inline uint32_t speedfrac(uint32_t depth, uint8_t wh){ // depth is speed - can be dacspeed but for now we dont do ==2/stoppage
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

// strobe we have as: strobebits // binroute: binroutebits

// define spdmodes
uint32_t (*spdmodes[16])(uint32_t depth, uint8_t wh)={speedfrac, strobebits, binroutebits};

// for first one we have one param for fixed spdmodes, second one uses 2nd for route

// we would ideally need 4 params: spdmode/depth, in/depth
// if we have major mode idea then we would use minor mode as spdmode/in (how? - as combos?) and CVs as depths
// how many bits? 4 bits here for spdmodes, 4 for in, depth varies in bits... (eg. can be 4 bits too for binroute)

// but the nice to have split so is not all these for LRCN//// how to do????
// also as binroute for spd tends to run at audio rates...

// options: speed from strobe - no int, from dac or CV - interpol/no_interpol, from bits - no int = 1,2,3,4 options
// what we don't have is freezespeed, nor copy of speedf_ but we can do that - otherwise is working!
void abstractoutinterpol(uint8_t w){ 
  HEAD;
  uint8_t spdfrom=2, interpol=0; // how we set/unset interpol bit
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpol)   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    BINROUTE_;
    // do dac for non-interpols
    if (!interpol){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// binroute and spdroute from routes and recursion - this one does this! but recursion is tricky without clock injection

// add in binroute
// but problem is if both run binroute - each instance is not independent even with I as indep. as is same w!
void abstractoutinterpolroute(uint8_t w){ 
  HEADNADA;
  uint8_t spdfrom=2, interpol=0; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpol)   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    bitn=binroutebitsI(CVL[w],w); // independent from shared one above - 
    // do dac for non-interpols
    if (!interpol){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// rungler version for rung in rung across all -> with cycle/cycle on strobe
void abstractoutinterpolrung(uint8_t w){ 
  HEADNADA;
  uint8_t spdfrom=2, interpol=0; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpol)   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    bitn=binroutebitscyclestrI(CVL[w], w); // independent from shared one above - cycle on strobe
    // do dac for non-interpols
    if (!interpol){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}


// 19/4/2022

//+gens->bitspeed (do we not have that?): yes as adcspeedstream in modeN.h but still we need to improve generators+

///////////......

// *** how to take characteristics and split these across SRs while keeping some structure... code to write/chop code, multiple opposing speeds...

// look again bitdsp and parallel bit processings

/// trigger oversamples (at speed)
// how do we oversample - run twice at speed...
// run twice but if we are slow others would have to wait... so just run twice...

// these can also be selecting different types of ADC and detached...
void ADCovers(uint8_t w){ 
  HEAD;
  // 2nd round - was inside loop - fix << though
  if (gate[w].trigger){
  gate[w].shift_=gate[w].shift_<<1;
  bitn=adcpadbits(SRlength[w]);
  gate[w].shift_+=bitn;
  }

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadbits(SRlength[w]);
  BINROUTE_; // or not! 
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void ADCoverss(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEAD;

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadbits(SRlength[w]);

  if (gate[w].trigger){
  gate[w].shift_+=bitn;
  gate[w].shift_=gate[w].shift_<<1;
  bitn=adcpadbits(SRlength[w]);
  }
    
  BINROUTE_; // keep bin
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// or go for 2 identical samples in
// almost like sample and hold
void ADCoversss(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEAD;

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadbits(SRlength[w]);

  if (gate[w].trigger){
  gate[w].shift_+=bitn;
  gate[w].shift_=gate[w].shift_<<1;
  //  bitn=adcpadbits(SRlength[w]);
  }
  // so same bitn will come in
  BINROUTE_; // keep bin
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// same but outside so we need new adc for sample and hold-like also
static inline uint32_t adcpadholdbits(uint32_t depth, uint8_t reset){ // TODO: eg. what happens if used consecutively... we have that in stream...  // how we could share same bits?
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
  if (reset) bc--;
  return bt;
}

void ADCoverssss(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEADD;

  if (gate[w].trigger){
  gate[w].shift_=gate[w].shift_<<1;
  bitn=adcpadholdbits(SRlength[w], 0); // doesn't advance
  gate[w].shift_+=bitn;
  }
  
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadholdbits(SRlength[w],1);  // that one advances things so above trigger own is same bit - or vice versa
  BINROUTE_; // 
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// start with sample and holds on trigger...
void ADChold(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  
  if(gate[w].last_time<gate[w].int_time)      {
    /*
    if (gate[w].trigger)  { // we could also hold binroute by not advancing GSRs - holdings
      GSHIFTNOS_; 
    }
    else
      {
	GSHIFT_;
      }
  */
    GSHIFT_;
    bitn=adcpadholdbits(SRlength[w], (!gate[w].trigger)); // trigger will hold it...
    BINROUTE_; 
    BITN_AND_OUTV_;
    ENDER;
  }
  }
  }

// other sample and hold with revolving bits on hold...
static inline uint32_t adcpadholdcyclebits(uint32_t depth, uint8_t reset){ // TODO: eg. what happens if used consecutively... we have that in stream...  // how we could share same bits?
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  static uint8_t oldreset=1;
    if (reset) oldreset=0;

  if (bc<0) {
    if (oldreset){
      ADCgeneric; 
    }
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
    oldreset=1;
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

void ADCholdcycle(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=adcpadholdcyclebits(SRlength[w], (gate[w].trigger)); // trigger will hold it
    BINROUTE_; 
    BITN_AND_OUTV_;
    ENDER;
  }
  }
  }

////////////////////////////////////////////////////////////////////////////

// TODO: ADC noise comp and select new generators,
// ADC noise comp:   if (((LFSR_[w] & 4095 ) > k)){  = not so exciting
void ADCnoisecmp(uint8_t w){  // for top modeN
  //  HEADSIN;
  HEADSSINNADA; // or do as strobe
  uint32_t k;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ADCgeneric;  
  if (((LFSR_[w] & 4095 ) > k)){   // this way round?
    // select gen and input
    bitn=(*abstractbitstreams[CVL[w]>>8])(CV[w],w); // oops need 2 CVs - 4 bits for first one - leaves 2 bits spare...
  }
  else
    {
      JUSTCYCLE_; // no length/speed - is a bit odd - discards bits
    }
  //  BINROUTE_; // or not! could use excess bits?
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

 // or do as strobe
void ADCnoisecmpSTROBE(uint8_t w){  // for top modeN
  //  HEADSIN;
  HEADSSINNADA;
  uint32_t k;
  if (gate[w].trigger)      {
  GSHIFT_;
  ADCgeneric;  
  if (((LFSR_[w] & 4095 ) > k)){   // this way round?
    // select gen and input
    bitn=(*abstractbitstreams[CVL[w]>>8])(CV[w],w); // oops need 2 CVs - 4 bits for first one - leaves 2 bits spare...
  }
  else
    {
      JUSTCYCLE_; // no length/speed - is a bit odd - discards bits
    }
  //BINROUTE_; // or not! could use excess bits?
  BITN_AND_OUTVINT_;
  }
}

  
// 18/4/2022

// TODO: more multiple speeds
/// *TODO: dacspeed and internal speed slip against each other: gshift and... see multiple speeds where we have dac but not as core speed*

void SRmultiplespeednewdac0(uint8_t w){ // - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  HEADSSIN;
  float speedf__;
  
  if (gate[w].trigger) GSHIFTNOS_; // // 1.copy gshift on trigger// sans <<

  if (counter[w]>CV[w]){ //2.advance incoming ghost on speed
    counter[w]=0;
    BINROUTEADV_;
  }

  speedf__=logspeedd[gate[speedfrom[spdcount][w]].dac>>2]; // that's 10 bits only - can also have scaling by CV 
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    gate[w].shift_=gate[w].shift_<<1; 
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// more variations on this! - 4 speeds, cv, cvl, strobe, dac
// break down into:

/*
from modeL.h
x. shifting/SR speed << in all below we don't split this except new - can be part of dac or in gshift

1. GSR copy speed (own GSR) //copy on strobe? see 37 in newmodes - L3 in modeL - in/outside loop as optionsDONE
2. advance incoming GSR speed - slidings
3. DAC out speed  - slipping - this is main loop as we need interpol
 */

// 4 independent speeds. 5 options: NONE (as in shift is taken up elseehere) CV, CVL, trigger, DAC = 2 bits each, collapse 1.shifter = 6 bits but select will use one CVL
/* we have so far in model.h:
SRmultiplespeednew: T:1, DAC: 2, CVL:<<x, CV: 3 
speed0: T:1, CVL: 2, CV: 3
1: T:2, CVL: 1, CV: 3
2: T:1<<, CVL: 2, CV: 3
3: CVL: 2, CV: 3
dac0: T: 1, DAC: <<x, CVL: 2, CV: 3
dac1: T: 1, DAC: 2, CV: 3
multspeed0: T: 1, CVL: 2, CV: 3
multspeed1: T: 2, CVL: 2, CV: 3 
2: T: 1<<, CVL: 2, CV: 3
3: CVL: 2, CV: 3
speeddac0: T: 1, DAC: <<x, CVL: 2, CV: 3
 
newdac0 above: T: 1, CV: 2, DAC: 3<<
newdac below: T: 1, CV: 2, CVL: <<x, DAC: 3

what options to be done:

 */

void SRmultiplespeednewdac(uint8_t w){ // NO LENGTH - try 4 speeds as above - multiple versions of this // this one is ****
  
  HEADSIN; // detach length
  float speedf__;

  if (gate[w].trigger) GSHIFTNOS_; // 2.copy gshift on trigger

  if (counter[w]>CV[w]){ //3.advance incoming ghost
    counter[w]=0;
    BINROUTEADV_;
  }

  if (counterd[w]> CVL[w]){
      counterd[w]=0;
    gate[w].shift_=gate[w].shift_<<1; // 1. shifter
  }
  
  speedf__=logspeedd[gate[speedfrom[spdcount][w]].dac>>2]; // that's 10 bits only - can also have scaling by CV 
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    //    gate[w].shift_=gate[w].shift_<<1; // but no shift makes odd with add... anyways
    BINROUTENOG_; 
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

/* what do we have of: operations on whole register/across registers? -noSR series

eg. noSRxorroutes: XOR with mask of incoming lengths... of routes in - which now we have as prob in = can also be sel routes and logic DONE below

*/

// circular buffer - borrowed from delay_line - can also have all options for this such as cycle/entry/prob etc...
// what is model for those permutations - where?

void noSRdelay_line(uint8_t w){ 
  HEAD;
  static uint32_t counter[4]={0,0,0,0}; // shared // unshared counter
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  //  bitn^=delay_line_shared(CVL[w],w); // or detach - length not used - this is our binroute
  BINROUTE_; // generators/prob/other routes/
  PULSIN_XOR;
  gate[w].shift_&=bitmasky[counter[w]];
  gate[w].shift_|=(bitn<<counter[w]);
  counter[w]++;
  if (counter[w]>SRlength[w]) counter[w]=0;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
}

// catalogue possible ins?

// delay line - large array and we write single bits into that circular buffer - 12 bits 4095 bits delay=128
// but then buffer is not a shift reg
// length=delay
// what is incoming bit? - route in - others?

uint32_t delayline[128]; //shared delay line
uint32_t delaylineUN[4][128]; //UNshared delay line

static inline uint32_t delay_line_shared(uint32_t depth, uint8_t wh){ // share counter and delay line
  // what other options are there?
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits; // 32 bits of bits
  tmp=binroute[count][wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  // extract from delay line (12 bits=4095)
  depth=bits+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delayline[tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits/32;
  tmpp=bits%32;
  delayline[tmp]&=bitmasky[tmpp];
  delayline[tmp]|=(bt<<(tmpp));
  bits++;
  if (bits>4095) bits=0;

  return bitrr;
}

static inline uint32_t delay_line_shared2(uint32_t depth, uint8_t wh){ // there are independent counters and shared line
  // what other options are there?
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits[4]; // 32 bits of bits
  tmp=binroute[count][wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  // extract from delay line (12 bits=4095)
  depth=bits[wh]+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delayline[tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits[wh]/32;
  tmpp=bits[wh]%32;
  delayline[tmp]&=bitmasky[tmpp];
  delayline[tmp]|=(bt<<(tmpp));
  bits[wh]++;
  if (bits[wh]>4095) bits[wh]=0;

  return bitrr;
}

static inline uint32_t delay_line_shared3(uint32_t depth, uint8_t wh){ // there is a shared counter and indie lines
  // what other options are there?
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits; // 32 bits of bits
  tmp=binroute[count][wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  // extract from delay line (12 bits=4095)
  depth=bits+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delaylineUN[wh][tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits/32;
  tmpp=bits%32;
  delaylineUN[wh][tmp]&=bitmasky[tmpp];
  delaylineUN[wh][tmp]|=(bt<<(tmpp));
  bits++;
  if (bits>4095) bits=0;
  return bitrr;
}


static inline uint32_t delay_line_unshared(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits[4]; // 32 bits of bits
  tmp=binroute[count][wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  
  // extract from delay line (12 bits=4095)
  depth=bits[wh]+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delaylineUN[wh][tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits[wh]/32;
  tmpp=bits[wh]%32;
  delaylineUN[wh][tmp]&=bitmasky[tmpp];
  delaylineUN[wh][tmp]|=(bt<<(tmpp));
  bits[wh]++;
  if (bits[wh]>4095) bits[wh]=0;

  return bitrr;
}

void SRdelay_lineSH(uint8_t w){ 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=delay_line_shared(CVL[w],w); // or detach - length not used - this is our binroute
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SRdelay_lineSH2(uint8_t w){ 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=delay_line_shared2(CVL[w],w); // or detach - length not used - this is our binroute
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SRdelay_line(uint8_t w){ 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=delay_line_unshared(CVL[w],w); // or detach - length not used - this is our binroute
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


// 15/4/2022

 //uint32_t patt[32]={0b1010, 0b1010, 0b1010, 0b1010, 0b11001100, 0b11001100, 0b11001100, 0b11001100, 0b111000111000, 0b111000111000, 0b111000111000, 0b111000111000, 0b1111000011110000, 0b1111000011110000, 0b1111000011110000, 0b1111000011110000, 0b11111000001111100000, 0b11111000001111100000, 0b11111000001111100000, 0b11111000001111100000, 0b111111000000111111000000, 0b111111000000111111000000, 0b111111000000111111000000, 0b111111000000111111000000, 0b1111111000000011111110000000, 0b1111111000000011111110000000, 0b1111111000000011111110000000, 0b1111111000000011111110000000, 0b11111111000000001111111100000000, 0b11111111000000001111111100000000, 0b11111111000000001111111100000000, 0b11111111000000001111111100000000};

// same bits out from generators - generic or shared clock
static inline uint32_t pattern_unshare(uint32_t depth, uint8_t wh){
  uint32_t bt, k;
  static uint32_t fast=0, khh;
  static int32_t bc[4]={0,0,0,0};
  static uint32_t kh[4]={0,0,0,0};
  
  if (bc[wh]<0) {
    kh[wh]=0b1010; // pattern also from dac but then looks like independent generators - better with fixed length
    bc[wh]=3; // we can also use length 
  }
  bt = (kh[wh]>>bc[wh])&0x01; // this means that MSB comes out first
  bc[wh]--;
  return bt;
}

void SRpattern_unshare(uint8_t w){ // sequential 12 bit in - use also for L, R, N
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=pattern_unshare(SRlength[w],w); // or detach - length not used
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}
// mods: usual, 


// chance of prob decay (flip) as it advances down SR... - older bits...* initial chance of decay/flip
// older ones more likely to flip...
/*
from bitdsp:
// + `type == 1` -- set a bit's value to low 
// + `type == 2` -- flip bit
// + `type == 3` -- set a bit's value to high

process sequence of bits

for (x=SRlength;x>0;x--)
if (highestprob) flipbitx
highestprob-lessens
 */

void SRLdecaying(uint8_t w){
  HEADSIN;
  int tt, dec;
  uint32_t highestprob=4095;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_;
  dec=(4096/SRlength[w]);
  for (tt=SRlength[w];tt>0;tt--){
    //    if (highestprob) flipbitx
    //highestprob-lessens
    if ( (LFSR_[w] & highestprob) > CVL[w]) {
	gate[w].shift_^=(1<<tt); // flips
      }
      highestprob=highestprob-dec;      
  }
  
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }
// works fine for slower approaches...

// DONE: eg. what happens if used consecutively... we have that in stream...  // how we could share same bits?
// question of counting bits... ie. if we want to share same bit who counts them down... (last caller but how do we know that?)

static inline uint32_t adc4bits_unshare(uint32_t depth, uint8_t wh){ // use wh too so matches other gens
  uint32_t bt, k;
  static uint32_t fast=0, khh;
  static int32_t bc[4]={0,0,0,0};
  static uint32_t kh[4]={0,0,0,0};
  
  if (bc[wh]<0) {
    ADCgeneric;
    kh[wh]=k>>8;
    bc[wh]=3; 
  }
  bt = (kh[wh]>>bc[wh])&0x01; // this means that MSB comes out first
  bc[wh]--;
  return bt;
}
// also question split between generator and modeX.h - question of wrapping, autowraps?
// it becomes:

void stream4_unshare(uint8_t w){ // sequential 12 bit in - use also for L, R, N
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=adc4bits_unshare(11,w);
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}
// always variations: binroute, shift or not...
// but also what happens if we unshare across dacs, any sequential output

//////////////////////////////////////////////////////////

// cipher generator now in gen.h to use for adc [4094]

// more like cipher entering SR
void adccipher(uint8_t w){ // generator is contained so is different to one below which can have binroute inside
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  bitn^=cipherbits(CVL[w], w); // not using depth
  BINROUTE_; // or not!
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }
// variations TODO: binroute or not, prob of binroute/cycle, use prob as speed, use strobe as speed and prob as trigger, or if on L or R, pulse as trigger
// thinking about how variations become submodes...

// 8 bit CIPHER for adc/trad modes
void adccipher2(uint8_t w){    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)
uint8_t prob;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_; // we dont shift our own SR

    GGGshift_[w]=GGGshift_[w]<<1;
    BINROUTE_; // here binroute is in different place or not - to above
    bitn^=ADC_(w,SRlength[w],85,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
    PULSIN_XOR; // not for adc ignore
    GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    } 
    bitn=CYCl;
    BITN_AND_OUTVNOSHIFT_;
    ENDER;
  }
  }
}
// variations such as: binroute or not. timing of binroute 


// 14/4/2022

// slide 2 bitstreams against each others? how to chain bitstreams but
// again we lose parameters, how we can imagine leaving behind a chain
// of parameters - key Q is params and organisation/streams

/*
bitn=logiq((*abstractbitstreams[val])(CV[w],w),(*abstractbitstreams[val2])(CVL[w],w)) 

4 params is too much... and that sliding can be each SR... 

*/

// 13/14/4/2022

// speedfrom, prob, incoming, final bit(pulsin) as 4 functions numbered - gridlike...
// but question is again lack of params...

/*

void recurse(void (*f)(void)){ // but again we would have to have: recurse(void (*f)(void (*f)(void (*f)(void (*f)(void (*f)(void))))) etc...
printf("x");
f();
}

recurse(recurse); 

 */

// attempting more generic - so we can define a mode within grid of functions, plug in parameters, and logic
// or SRitselftry2 is a function too eg:
// func(uint8_t w, moods *mode) - but can we pass in structure itself - as doesn;t know itself
// but we could pull that out into function array

typedef struct moods_ { //
  //  void (*func)(uint8_t w, moods *mode);
  uint8_t gsfr;
  uint8_t spdfr;
  uint8_t probfr;
  uint8_t incfr;
  uint8_t incor;
  uint8_t last;
  uint32_t *par0, *par1, *par2, *par3, *par4;
  uint8_t (*logic)(uint8_t bit1, uint8_t bit2);
} moods;

uint8_t XOR_(uint8_t bit1, uint8_t bit2){
  uint8_t res;
  res=bit1^bit2;
  return res;
}

//
////... SRitselftry2(0, &moodsw[0]);
//
static moods moodsw[64]={ // unused...
  {0,0,0,0,0,0, CV,CV,CV,CV,CV, XOR_}, // test - frs are refs to array, but problem is pars - as refs to CV[w] or gate[w].dac --
}; // how to do refs to dacs
// WE would need to change that ref... so is owndac[w] across all files... TODO? if we decide


// so each mode is defined by 5x5bits (decision functions 1,0), 5 CV sources (DAC or CV), and one logic function (say: AND, XOR, leak, OR)
// where does this get us?

// how can we combine decison functions logically? a chain of... but this would be another function??
// more of a model which is about bitstreamds and combinations of bitstreams

/*

  if (stream1){  // spd
  gate[w].shift_=gate[w].shift_<<stream0
    if (stream2){ // prob
      bitn=stream3; // in?
    }
    else
      { 
	bitn=stream4; // inor?
      }
  bitn=mode->logic(bitn, stream5); // pulsin
}

// how that can be split across multiples...

 */

// but this has no interpol - 20/4/2022
void SRitselftry2(uint8_t w, moods *mode){ // pass in structure - 
  HEADSSINNADA; // detach depending on what/
  if (abstractbitstreamslong[mode->spdfr](mode->par1[w], w)){  // spd - for intmodes we can lose this // moved speed UP
  GSHIFTNOS_;
  /// CORE
  gate[w].shift_=gate[w].shift_<<(abstractbitstreamslong[mode->gsfr](mode->par0[w], w));
    if (abstractbitstreamslong[mode->probfr](mode->par2[w], w)){ // prob
      bitn=abstractbitstreamslong[mode->incfr](mode->par3[w], w); // what?
    }
    else
      { 
	bitn=abstractbitstreamslong[mode->par3[w]](mode->par3[w], w); // or?
      }
  
  bitn=mode->logic(bitn, abstractbitstreamslong[mode->last](mode->par4[w], w)); 
  ///  
  BITN_AND_OUTVINT_; // abstract out maybe
  ENDER;
  }
}

void (*moodsfuncs[64])(uint8_t w, moods *mode)={SRitselftry2}; // list of functions and then we can call for example    (*dofunc[www][mode[www]])(www);

//   (*moodsfuncs[0])(www, &moodsw[0]); // mode=0


void SRitselftryagain(uint8_t w, uint8_t gsfr, uint8_t spdfr, uint8_t probfr, uint8_t incfr, uint8_t incor, uint8_t last, uint32_t *par0, uint32_t *par1, uint32_t *par2, uint32_t *par3, uint32_t *par4, uint8_t (*logic)(uint8_t bit1, uint8_t bit2) ){
uint8_t prob;
 HEADSSINNADA; // detach depending on what/
  if (abstractbitstreamslong[spdfr](par1[w], w)){  // spd - for intmodes we can losee this - moved up
 CVOPEN;
  GSHIFTNOS_;
  /// CORE
  gate[w].shift_=gate[w].shift_<<(abstractbitstreamslong[gsfr](par0[w], w)); // gshift or not
    if (abstractbitstreamslong[probfr](par2[w], w)){ // prob
      bitn=abstractbitstreamslong[incfr](par3[w], w); // what?
    }
    else
      { 
	bitn=abstractbitstreamslong[par3[w]](par3[w], w); // or?
      }
  bitn=logic(bitn, abstractbitstreamslong[last](par4[w], w)); 
  BITN_AND_OUTV_; // abstract out maybe
  ENDER;
  }
}

// 12/4/2022

// itself/loopback as route or decision?
// how to break down further as set of functions or options so is not such monolithic functions??? eg. what clkbit does, pulsin_xor
// guess as sets of bits again...

// if [if x bitfrom X] bitfrom X // else?

// if x source y or z - plug in generators - just as example to think on

static uint32_t itself2(uint32_t (*f)(uint32_t depth, uint8_t wh), uint32_t (*g)(uint32_t depth, uint8_t wh), uint32_t (*h)(uint32_t depth, uint8_t wh), uint32_t depth, uint8_t wh){   // or extra param for g(param,wh)???
  uint32_t bt=0;
  if (f(depth,wh)){ // if itself...recur
      bt=g(depth,wh);
    }
  else bt=h(depth,wh);
  return bt;
}

// if (itself2(func[x],func[y],func[z],CV[0],w)) itself2...;

// do we clk/strobe as generator, toggle generator...??? do we have this? - DONE

// 11/4/2022

/* bin

   tmp=binroute[count][w];
   for (x=0;x<4;x++){
   if (tmp&0x01){
   bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
   gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
   bitn^=bitrr;
   }
   tmp=tmp>>1;
  }

 */

// can we insert one wheel/SR in another - keep it running at last speed... embed it as our bitn

// attach, detach, embed of functions

// embed as bitn, as prob/decision

// what that would look like and how that could be translated into a story, how to embed/recurse as a structure/itself

/*

we would need to simplify speed... speed can also be a character of SR... speed as decision from SR/generator

speed as sequence of SR/ 1s and 0s

global speed...

genX:
if (genX){
gshift[w]
bitn=genX
}

towards most simple SR - work from inside or from inside out

void SRintprobnog(uint8_t w){  // intmode
  HEAD;  
  if (X)      {
    GSHIFT_;

    bitn=Y;
    PULSIN_XOR;

    BITN_AND_OUTVINT_; 
  } 
}

// gshift as part of generator, output as what?

-> abstractions of SRs aside from output - or vice versa... functions assigned to outputs

splitting and subjection of itself... so each element is abstracted out and able to be controlled by...

if (speed){
  if X gshift
  bitn=[ // generator selected--->
    if (speed){
      bitn=[ // generator
      ]
    }
  ]
}

if (speedfrom){
  gshift
  bitn=FROM?
  SR=IN?/WHERE?
  GSR=GSR? // recurse... but we lose params...

 */

// itself(uint32_t (*f)( uint32_t (*f)(RECURSE),uint32_t depth, uint8_t wh), uint32_t depth, uint32_t other, uint8_t wh)

// towards new prototype for itself as SR
static uint32_t itself(uint32_t (*f)(uint32_t depth, uint8_t wh), uint32_t (*g)(uint32_t depth, uint8_t wh), uint32_t depth, uint32_t other, uint8_t wh){   // PROBability mode
  uint32_t bt=0;
  if (f(depth,wh)){ // if itself...recur
      bt=g(other,wh);
    }
  return bt;
}

// wrap up eg.
void SRitself(uint8_t w){
uint8_t prob;
  HEADSSINNADA;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
    // CORE
  bitn=itself(osceqbits,binroutebits,CV[w], CVL[w], w); // but we would need additional 8 bits (4+4) to set each of these - from another SR!!!
  // abstractbitstreams[x], abstractbitstreams[y] 
  
  PULSIN_XOR; // place into SR function
  
  BITN_AND_OUTV_; // abstract out maybe
  ENDER;
  }
  }
}
  
//speedfrom?, bitfrom?

// vienna/generic was: 1bit speedfrom, [1bit adctype-fixed], 4 bits routein, 1bitprob_of_inv on param

// swop incoming gshift and shift
void SRGswop(uint8_t w){// swap over SRs on pulse in?!! or swop in only (can swop in previous SR or another?) 
uint8_t prob;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    //    if (gate[w].trigger) gate[w].shift_=gate[w].Gshift_[w]; // could also be incoming one
    if (gate[w].trigger) gate[w].shift_=gate[inroute[count][w]].Gshift_[w]; // could also be incoming one
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// 2 routes into one//XOR full TRY!
void noSRxorroutes(uint8_t w){ // XOR in 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  // copy mask of bits from inroute
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round?
    
    GSHIFTNOS_;
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
    if (tmp&0x01){ // use length for something else? prob?
      gate[w].shift_^= (gate[x].Gshift_[w]); // or length of that mask is another parameter - strobe mode - but that length doesnt do much except stop
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;   // dont add in bitn
  }
  else
    {
      GSHIFT_;
      JUSTCYCLE_;
      PULSIN_XOR;
      BITN_AND_OUTV_;
    }
  ENDER;
  }
  }
  }

// // 2 routes into one//XOR full TRY! - select route and logic - 6 bits
void noSRselxorroutes(uint8_t w){ // XOR in
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  // copy mask of bits from inroute
    GSHIFTNOS_;
    tmp=CVL[w]>>8; // 
    for (x=0;x<4;x++){
    if (tmp&0x01){ 
      gate[w].shift_^= (gate[x].Gshift_[w]); // but length doesnt do much except stop
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    //    bitn^=bitrr; // lowest 2 bits for logic
    bitn=logop(bitn,bitrr,(CVL[w]>>6)&3);
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;   // dont add in bitn
  ENDER;
  }
  }
}

// question of embeddings and numbers say of gshifts... also shared gshifts as an option... embed this one//as a generatorDONE

// new gshift for sharings: BINROUTESHARE_ and gate[x].Gshare_ -> only makes sense if we share routes or if there are functions to shift on shared routes... 
// eg. function to shift on shared route at speed as one SR or to insert into shared SR!
// try route from before one... or enforce shared routes
void SRshroute(uint8_t w){ // strobe could also shift on
  HEAD;
  int32_t mw;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  mw=w-1;
  //  if (mw<0) mw=3;
  tmp=binroute[count][w];
   for (x=0;x<4;x++){
   if (tmp&0x01){
   bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;
   gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
   if (gate[w].trigger) {
   bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;
   gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
   }
   bitn^=bitrr;
   }
   tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }
  
///////////////////////////////////////////////////////////////////////////////////////////

// 8/4/2022

// wheeling probability function
// but to make use of this we need next one to use incoming as prob of adc or route from top
// so needs some sync - is question across all of new idea of functions
void SRprobwheel(uint8_t w){ // new detached mode with prob wheel as generator only // for L
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w];
  bitn=ADC_(w,SRlength[w],113,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_);
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// eg. test this with basic modeN which uses binroute for loop or route in from top // for C - seems to workings
void dacNbinprob(uint8_t w){ 
  gate[w].dactype=0; gate[w].dacpar=param[w];
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    if (bitn){
      bitn=0;
      // route from 1
      bitrr = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
      gate[0].Gshift_[w]=(gate[0].Gshift_[w]<<1)+bitrr;
      bitn^=bitrr;
    }
    else
      {
	bitn=0;
	JUSTCYCLE_;
      }
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// no gshifts: adc0nog, SRR0nog, same as SR0nog and from modeC: dac67_4bitsNOGG - length has less to do
// do we have options to say strobe/toggle/prob in/out the gshifter? TODO:

// as: SR0nogstrobe, SR0nogtoggle, SRLprobnog, SRintprobnog DONE

void SR0nogstrobe(uint8_t w){ // basic route in no GSHIFT<< strobed
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (STR0) { // macro now for strobe/trigger
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void SR0nogtoggle(uint8_t w){ // basic route in no GSHIFT<< toggles
  HEAD;
  static uint8_t toggle[4]={0,0,0,0};
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (STR0){
      toggle[w]^=1;
    }
    if (toggle[w]) {
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// and finally prob from CVL - detached... - and can also be an intmode TODO
void SRLprobnog(uint8_t w){
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void SRintprobnog(uint8_t w){  // intmode
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    // HERE
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  } 
}

// don't move at all... xor etc one Sr against another....// and what does length do...
// trial

//*what elements can be used from delta sigma*
// signal input is binroute, subtract cycle bit and pass bits via integrator/comp
//trial - what other functions could be?? bit filter, logic?

void SRsigma(uint8_t w){ 
  HEAD;
  int32_t cycle;
  static int32_t integrator;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_;
  if (bitn) val=1;
  else val=-1;
  if (CYCl) cycle=1;
  else cycle=-1;
  
  integrator+=(val-cycle);
  if (integrator>0) bitn=1;
  else bitn=0;
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// unmoving XOR on strobe - parallel streams - we can have 4 unmoving copy across SRs - they are not SRs... 

/*
void noSRproto(uint8_t w){
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }
*/

// masks to do - but they are also not bitstreams... and we need a bitn for pulses or do a different pulse out
// DONE using   RETURN; TEST!

// trial 12 bits of adc in 
void noSRadc(uint8_t w){
  HEAD; uint32_t k;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  ADCgeneric;
  k=k>>(leftshift[SRlength[w]])<<rightshift[SRlength[w]]; // fill length
  gate[w].shift_=k;
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_^=tmp;
  RETURN;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }

//- 2s complement and others for noSRadc
void noSRadc2s(uint8_t w){
  HEAD; uint32_t k;
  uint32_t bt, bitwise;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  ADCgeneric;
  if (k<2048) bitwise=1;
  else bitwise=0;
  k=abs(k-2048);
  if (bitwise) k=(~k)+1;
  k=k>>(leftshift[SRlength[w]])<<rightshift[SRlength[w]]; // fill length
  gate[w].shift_=k;
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_^=tmp;
  RETURN;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }

// and 12 bits out dac
void noSRdac(uint8_t w){ 
  HEAD;
  gate[w].dactype=23; gate[w].dacpar=param[w];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_;
    tmp=(gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]]);
    gate[w].shift_=tmp;
    BITN_AND_OUTVNOSHIFT_; 
    ENDER;
  }
  }
}

void noSRdac2s(uint8_t w){ 
  HEAD;
  gate[w].dactype=22; gate[w].dacpar=param[w];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_;
    tmp=(gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]]);
    gate[w].shift_=tmp;
    BITN_AND_OUTVNOSHIFT_; 
    ENDER;
  }
  }
}

void noSRdac2sRLxor(uint8_t w){  // xor of left and right
  HEAD;
  gate[w].dactype=22; gate[w].dacpar=param[w];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_;
    tmp=(gate[1].Gshift_[w]&masky[SRlength[1]]);
    gate[w].shift_=tmp^(gate[3].Gshift_[w]&masky[SRlength[3]]);
    BITN_AND_OUTVNOSHIFT_; 
    ENDER;
  }
  }
}

void noSRcopy(uint8_t w){ // copy in with mask of length
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  // copy mask of bits from inroute
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_=tmp;
  PULSIN_XOR;
  gate[w].shift_^=bitn; // where do we put pulse bits? - not much happening
  RETURN;
  BITN_AND_OUTVNOSHIFT_;  
  ENDER;
  }
  }
  }

