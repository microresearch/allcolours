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

/*

- how that looks for inputs - what we compare to what?
- or we just have list of probs to make things easier...

- and for bits: bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;

*invert routed/bit*
*routed vs cycling// routed vs inverted cycling*
*routed vs [routed^cycling]*

 */

static inline uint32_t binroutfixed_prob1(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - prob of routed or cycling
  uint32_t bt=0, bitrr;
  if (depth<(LFSR_[wh]&4095)) {
  depth=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  }
  else
    {
    bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01; 
    }
  return bt;
}

static inline uint32_t binroutfixed_prob1R(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - prob of routed or cycling // route from R
  uint32_t bt=0, bitrr;
  if (depth<(LFSR_[wh]&4095)) {
    bitrr = (gate[3].Gshift_[wh]>>SRlength[3]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[3].Gshift_[wh]=(gate[3].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
    else
    {
    bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01; 
    }
  return bt;
}

static inline uint32_t binroutfixed_prob1L(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - prob of routed or cycling // route from R
  uint32_t bt=0, bitrr;
    if (depth<(LFSR_[wh]&4095)) {
    bitrr = (gate[1].Gshift_[wh]>>SRlength[1]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[1].Gshift_[wh]=(gate[1].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
     }
    else
    {
      bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
    }
  return bt;
}

static inline uint32_t binroutfixed_prob2(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - // prob of inverting routed bit
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
  if (depth<(LFSR_[wh]&4095)) bt=!bt;
  return bt;
}

static inline uint32_t binroutfixed_prob3(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - prob of routed or cycling INV
  uint32_t bt=0, bitrr;
  if (depth<(LFSR_[wh]&4095)) {
  depth=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  }
  else
    {
      bt = !((gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01); 
    }
  return bt;
}

static inline uint32_t binroutfixed_prob4(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - *routed vs [routed^cycling]*
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
  if (depth<(LFSR_[wh]&4095)) {
    bt^=(gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
  }
  return bt;
}

//////////////////////////////////////////////////////////////////////////
// tails
void basictail(void){ // tail here is basic 4th at full speed - not very exciting for major_vienna as just loops
  HEADNADA;
  uint32_t w=8;
  GSHIFT_;
  tmp=binroute[count][2];
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
      bitn^=bitrr;    
    }
    tmp=tmp>>1;
  }
  gate[w].shift_+=bitn;
}



//////////////////////////////////////////////////////////////////////////
//0
//lengths

static uint32_t held[4]={0,0,0,0}; // for length
static uint32_t helds[4]={0,0,0,0}; // for speed


// we can fork in processors here...

static inline uint32_t rlen(uint32_t depth, uint32_t wh){
  uint32_t bt=lookuplenall[depth>>7]; // 5 bits
  held[wh]=depth; // release hold for all lengths
  return bt; // bt is a value
}

static inline uint32_t nlen(uint32_t depth, uint32_t wh){
  return 0; // is just holder
}

// hold old [CVL/depth] length
static inline uint32_t holdlen(uint32_t depth, uint32_t wh){ // we don;t use depth as we just hold // can have same for speed...
  static uint32_t oldd[4]={0,0,0,0};
  if (held[wh]!=0) oldd[wh]=held[wh];
  held[wh]=0;  
  uint32_t bt=lookuplenall[oldd[wh]>>7]; // 5 bits
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

static inline uint32_t binroutfixed(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count
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

static inline uint32_t binroutesel0(uint32_t depth, uint32_t in, uint32_t w){
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

static inline uint32_t binroutesel1(uint32_t depth, uint32_t in, uint32_t w){ // depth is route
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

static inline uint32_t binroutesel2(uint32_t depth, uint32_t in, uint32_t w){ // depth is sel of type
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

static inline uint32_t binroutor(uint32_t depth, uint32_t in, uint32_t wh){ // 4 bits binroute ORed with selected 4 bits SR..
  uint32_t bt=0, bitrr, tmp;
  depth=depth>>6; // 12 bits to 6 bits
  // top 2 bits as SR select
  tmp=(depth>>4)&3;
  depth=depth| (gate[tmp].shift_&15);    
  depth=depth&15;
  
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

static inline uint32_t zsingleroutebits(uint32_t depth, uint32_t in, uint32_t wh){  // just route from 0-3 single route
  uint32_t bt=0, bitrr;
  depth=depth>>10; // 12 bits to 2 bits
    // deal with no route

  bitrr = (gate[depth].Gshare_>>SRlength[depth]) & 0x01; 
  gate[depth].Gshare_=(gate[depth].Gshare_<<1)+bitrr;
  bt=bitrr;
  
  return bt;
}

static inline uint32_t zbinrouteINVbits(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now
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
  bt=!bt;
  return bt;
}

static inline uint32_t zbinroutebits_noshift_transit(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now - no shift of GSR<<
  uint32_t btt=0,bt=0, bitrr;
  static uint8_t lastone;
  depth=depth>>8; // 12 bits to 4 bits
  // deal with no route
   if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  if (lastone!=bt) btt=1; // it was a transition 0-1 1-0
  lastone=bt;
  return btt;
}

static inline uint32_t zbinroutebits_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now - no shift of GSR<<
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  // deal with no route
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t zbinroutebitscycle(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  depth=depth|wh; // adds itself
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscyclestr(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  if (gate[wh].trigger) depth=depth|wh; // adds itself on strobe
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscycle_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  depth=depth|wh; // adds itself
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscyclestr_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  if (gate[wh].trigger) depth=depth|wh; // adds itself on strobe
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinrouteORbits(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt|=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinrouteANDbits(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt&=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinrouteSRbits(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... SR itself, no GSR 
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    //    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitsI(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshift_[wh]>>SRlength[8]) & 0x01; 
    gate[8].Gshift_[wh]=(gate[8].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t zbinroutebitsI_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshift_[wh]>>SRlength[8]) & 0x01; 
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t zbinroutebitscycleI_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  depth=depth|wh; // add itself in
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscyclestrI(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... cycle added on strobe!
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  //  depth=depth|wh; // add itself in
  if (gate[wh].trigger) depth=depth|wh; // adds itself
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

//////////////////////////////////////////////////////////////////////////
//3
//speeds - which can also be generic bit functions! and vice versa...
// also speeds need to set helds[wh]
static inline uint32_t lastspd(uint32_t depth, uint32_t in, uint32_t wh){ // lastspeed processor - no use of depth, no interpol
  uint32_t bt=0;
  static uint32_t counters[4]={0,0,0,0};
  counters[wh]++;
  if (counters[wh]>gate[wh].lastspeed){
    counters[wh]=0;
    bt=1;
  }
  return bt;
}
  

// hold old [CVL/depth] length
static inline uint32_t holdlspdfrac(uint32_t depth, uint32_t in, uint32_t wh){ // we don;t use depth as we just hold // can have same for speed...
  static uint32_t oldd[4]={0,0,0,0};
  uint32_t bt=0;
  float speed;

  if (helds[wh]!=0) oldd[wh]=helds[wh];
  helds[wh]=0;  
  speed=logspeed[oldd[wh]>>2]; // 12 bits to 10 bits
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

static inline uint32_t spdfrac(uint32_t depth, uint32_t in, uint32_t wh){ // for speed now with dac/interpol pulled out
  uint32_t bt=0;
  float speed;
  helds[wh]=depth;
  speed=logspeed[depth>>2]; // 12 bits to 10 bits
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
  if (in==0) tmp=depth;
  else tmp=depth%in;
  //  tmp=in+depth;
  //  if (tmp>4095) tmp=4095;
  helds[wh]=tmp;
  speed=logspeed[tmp>>2]; // 12 bits to 10 bits
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

static inline uint32_t spdfrac3(uint32_t depth, uint32_t in, uint32_t wh){ // depth is offset, in is constraint -- and speed from dac = gate[speedfrom[spdcount][w]].dac
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  tmp=gate[speedfrom[spdcount][wh]].dac%in;
  tmp+=depth;
  if (tmp>4095) tmp=4095;    

  helds[wh]=tmp;
  speed=logspeed[tmp>>2]; // 12 bits to 10 bits
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

// TODO: add in different spdfrac doubles:

/*

  tmpp=(CV[w]>>2)-512;
  cv=(gate[speedfrom[spdcount][w]].dac>>2) + tmpp;  
  if (cv<0) cv=0;
  else if (cv>1023) cv=1023;

*/


static inline uint32_t strobe(uint32_t depth, uint32_t in, uint32_t wh){   // strobe - no depth
  uint32_t bt;
  bt=gate[wh].trigger;
  return bt;
}

static inline uint32_t ztogglebits(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt[4]={0,0,0,0};
  if (gate[wh].trigger) bt[wh]=bt[wh]^1;
  return bt[wh];
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
  return 1;
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


uint32_t (*speedfromsdd[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksrG, clksr, strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG, strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG, spdfrac, spdfrac};
// but not interped // doubles up TODO more


static inline uint32_t speedselcvl(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt=0;
  bt=((*speedfromsdd[CVL[wh]>>7])(depth, in, wh));
  return bt;
  }

static inline uint32_t speedselcvm(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt=0;
  bt=((*speedfromsdd[CVM[wh]>>7])(depth, in, wh));
  return bt;
  }

static inline uint32_t speedseloldcvm(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt=0;
  bt=((*speedfromsdd[gate[wh].oldcvm>>7])(depth, in, wh));
  return bt;
  }

static inline uint32_t speedseloldcvl(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt=0;
  bt=((*speedfromsdd[gate[wh].oldcvm>>7])(depth, in, wh));
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

// generic in from gen.h

// top bit of clksr 
static inline uint32_t zSRclksr(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt=0;
  bt=(clksr_[wh]>>depth)&0x01;
  return bt;
}

// how could we cycle through clksr if it is not moving - we need gsr for them -clksrG_
static inline uint32_t zSRclksrG(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0;
  bt=(clksrG_[wh]>>depth)&0x01;
  clksrG_[wh]=(clksrG_[wh]<<1)+bt; // this also changes patterns there
  return bt;
}

//four SRbits
static inline uint32_t zSRNbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[0].Gshift_[wh]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

static inline uint32_t zSRLbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[1].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t zSRCbits(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[2].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t zSRRbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[3].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t zpulsebits(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  uint32_t bt=0;
  if (pulse[wh]){
    bt=!(GPIOC->IDR & pulsins[wh]);
  }
  return bt;
}

static inline uint32_t zprobbits(uint32_t depth, uint32_t in, uint32_t wh){   // PROBability mode
  uint32_t bt=0;
  if (depth<(LFSR_[wh]&4095)) bt=1;
  return bt;
}

static inline uint32_t zprobbitsxorstrobe(uint32_t depth, uint32_t in, uint32_t wh){   // PROBability mode xor strobe - can be more ops
  uint32_t bt=0;
  if (depth<(LFSR_[wh]&4095)) bt=1;
  bt=bt^gate[wh].trigger;
  return bt;
}

static inline uint32_t zprobbitsxortoggle(uint32_t depth, uint32_t in, uint32_t wh){   // PROBability mode xor strobe - can be more ops
  static uint32_t bt=0;
  if (gate[wh].trigger) bt=bt^1;
  if (depth<(LFSR_[wh]&4095)) bt^=1; // variations
  return bt;
}


// but depth could also be param to advance x or shift on
static inline uint32_t zsuccbits(uint32_t depth, uint32_t in, uint32_t wh){   // no use of depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x=0;
  if (x==wh) x++;
  if (x>3) x=0;
  bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - keep as option - see indie version
  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  bt^=bitrr;
  x++;
  return bt;
}

static inline uint32_t zsuccbitsI(uint32_t depth, uint32_t in, uint32_t wh){   // no use of depth - we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x[4]={0};
  if (x[wh]==wh) x[wh]++;
  if (x[wh]>3) x[wh]=0;
  bitrr = (gate[x[wh]].Gshift_[0]>>SRlength[x[wh]]) & 0x01; // if we have multiple same routes they always shift on same one - keep as option - see indie version
  //  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  bt^=bitrr;
  x[wh]++;
  return bt;
}
// depth can be length or param
static inline uint32_t zreturnbits(uint32_t depth, uint32_t in, uint32_t wh){   // returning but we need ref to itself SR//, and its length/ as depth - starts to look like adc_ functions now
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  //  bt=(*SR>>depth)& 0x01; // but return should be of ghost...   bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		
  bt = (gate[wh].Gshift_[wh]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

//inverted
static inline uint32_t zreturnnotbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  //  bt=(*SR>>depth)& 0x01; // but return should be of ghost...   bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		
  bt = !((gate[wh].Gshift_[wh]>>depth) & 0x01);		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

static inline uint32_t zosc1bits(uint32_t depth, uint32_t in, uint32_t wh){  
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

// we already have EN version
//WIARD versions - macro versions - inside themselves
//WIARD: noise/comp selects new input or loop back/inverted loop back (jumper)

//WIARD
static inline uint32_t zwiardbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh]|binary[wh];
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
  }
  return bt;
}

static inline uint32_t zwiardinvbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh]|binary[wh];
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01);
  }
  return bt;
}

static inline uint32_t zTMsimplebits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;				
  if (depth>(LFSR_[wh]&4095)) bt=!bt;
  return bt;
}

static inline uint32_t zonebits(uint32_t depth, uint32_t in, uint32_t wh){ // depth=0 resets --> ??? use strobe
  uint32_t bt;
  static int32_t bc=31;
  //  static uint32_t k;
  if (gate[wh].trigger) depth=0;  
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
static inline uint32_t zENbits(uint32_t prob, uint32_t in, uint32_t wh){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 

  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  prob=7-prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

// trying for a simpler version
static inline uint32_t zENsbits(uint32_t prob, uint32_t in, uint32_t wh){ 
  uint32_t bt, tmp;
  if ((LFSR_[wh]&4095)>prob) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t zENsroutedbits(uint32_t prob, uint32_t in, uint32_t wh){ 
  uint32_t bt, tmp;
  if ((gate[inroute[count][wh]].Gshift_[wh]&4095)<prob) bt=(gate[inroute[count][wh]].Gshift_[wh]>>SRlength[inroute[count][wh]])&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t zlfsrbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t k;
    bt = ((ADCshift_[wh] >> (lfsr_taps[depth][0])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][1])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][2])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][3]))) & 1u;
    ADCshift_[wh]=(ADCshift_[wh]<<1)+bt;
    if (ADCshift_[wh]==0) ADCshift_[wh]=0xff;
    return bt;
}

static inline uint32_t zllfsrbits(uint32_t depth, uint32_t in, uint32_t wh){ // no depth
  uint32_t bt;
  static uint32_t k;
  // out from lfsr at full speed
  bt=(LFSR_[wh]>>31)&0x01;
  return bt;
}


static inline uint32_t zflipbits(uint32_t depth, uint32_t in, uint32_t wh){  
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


static inline uint32_t zosceqbitsI(uint32_t depth, uint32_t in, uint32_t wh){   
  uint32_t bt;
  static int32_t n[4]={0};
  static int32_t nn[4]={0};
     if (n[wh]>depth) {
       bt=0;
       if (nn[wh]>=depth) { // so equal bits from 0 / length 0 = 101010
	 n[wh]=0;
       }
       nn[wh]++;
     } // n     
     else {
       bt=1;
       n[wh]++;
       nn[wh]=0;
     }         
     return bt;
}

static inline uint32_t zosc1bitsI(uint32_t depth, uint32_t in, uint32_t wh){  
  uint32_t bt;
  static uint32_t lastbt[4]={0};
  static uint32_t n[4]={0};
  if (n[wh]>depth)  {
    lastbt[wh]^=1;
    n[wh]=0;
  }
  n[wh]++;
  bt=lastbt[wh];
  return bt;
}

static inline uint32_t zTMsimplebitsI(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt,k;
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;				
  if (depth>(LFSR_[wh]&4095)) bt=!bt;
  return bt;
}

static inline uint32_t zwiardbitsI(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh]|binary[wh];
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
  }
  return bt;
}

static inline uint32_t zwiardinvbitsI(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh]|binary[wh];
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01);
  }
  return bt;
}

static inline uint32_t zonebitsI(uint32_t depth, uint32_t in, uint32_t wh){ // depth=0 resets
  uint32_t bt;
  static int32_t bc[4]={31};
  //  static uint32_t k;
  if (gate[wh].trigger) depth=0;  
  if (bc[wh]<0) {
    bt=0;
    if (depth>0) bc[wh]=depth;
  }
  else{
  bt = 1; // this means that MSB comes out first
  }
  bc[wh]--;
  return bt;
}

//EN: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)
static inline uint32_t zENbitsI(uint32_t prob, uint32_t in, uint32_t wh){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 

  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  prob=7-prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

// trying for a simpler version
static inline uint32_t zENsbitsI(uint32_t prob, uint32_t in, uint32_t wh){ 
  uint32_t bt, tmp;
  if ((LFSR_[wh]&4095)>prob) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
    //    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}


static inline uint32_t zlfsrbitsI(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t k;
    bt = ((ADCshift_[wh] >> (lfsr_taps[depth][0])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][1])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][2])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][3]))) & 1u;
    ADCshift_[wh]=(ADCshift_[wh]<<1)+bt;
    if (ADCshift_[wh]==0) ADCshift_[wh]=0xff;
    return bt;
}

static inline uint32_t zllfsrbitsI(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t k;
  // out from lfsr at full speed
  bt=(LFSR_[wh]>>31)&0x01;
  return bt;
}

static inline uint32_t zflipbitsI(uint32_t depth, uint32_t in, uint32_t wh){  
  uint32_t bt;
  static uint32_t n[4];
  depth=depth>>4; // 8 bits say
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01; // returnbits				
  if (n[wh]>depth)  {
    bt=!bt;
    n[wh]=0;
  }
  n[wh]++;
  return bt;
}

static inline uint32_t zcompbits(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt;
  if (in>depth) bt=1; // which way round?
  else bt=0;
  return bt;
}

static inline uint32_t zpattern4bits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    k=in&15;
  }
  if (nn>3){ // or count down
    nn=0;
  }
  bt=k>>nn;
  n++; nn++;
  return bt;
}

static inline uint32_t zpattern8bits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    k=in&255;
  }
  if (nn>7){ // or count down
    nn=0;
  }
  bt=k>>nn;
  n++; nn++;
  return bt;
}

static inline uint32_t zpattern4bitsI(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  if (n[wh]>depth){
    n[wh]=0;
    k[wh]=in&15;
  }
  if (nn[wh]>3){ // or count down
    nn[wh]=0;
  }
  bt=k[wh]>>nn[wh];
  n[wh]++; nn[wh]++;
  return bt;
}

static inline uint32_t zpattern8bitsI(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  if (n[wh]>depth){
    n[wh]=0;
    k[wh]=in&255;
  }
  if (nn[wh]>7){ // or count down
    nn[wh]=0;
  }
  bt=k[wh]>>nn[wh];
  n[wh]++; nn[wh]++;
  return bt;
}

//////////////////////////////////////////////////////////////////////////
//5
//adc - these just become interpreters for IN values which can be adc! depth is control/CV

// *TODO: new routeprobs to use//can also have adcprobs with depth -> prob of cycle, prob of hold last value etc... TRIAL in new geogen/adc*
// we either repeat each one, and then sel these or alter all so takes a reset and have these all as generic one
// eg. repeat below

static inline uint32_t zpadcx(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  
    if (bc<0 || reset) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      k=in>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

uint32_t (*adcfromsddprob[32])(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset)={zpadcx};

// how many CVs do we need for this? 3x - one for sel, prob and for depth 
static inline uint32_t probcvladcselcvm(uint32_t depth, uint32_t in, uint32_t wh){  // select adc using CVM, prob from CVL which leaves CV(speed)
  uint32_t bt, prob;
  if (CVL[wh]<(LFSR_[wh]&4095)) prob=1; // which way round
  else prob=0;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
  //   bt=(*adcfromsddprob[CVM[wh]>>7])(depth, in, wh, prob); // 5 bits
  bt=(*adcfromsddprob[0])(depth, in, wh, prob); // TESTING
  // test
  return bt;
}

// we can have fixed versions against dac 
static inline uint32_t probdacadcselcvm(uint32_t depth, uint32_t in, uint32_t wh){  // select adc using CVM, prob from CVL which leaves CV(speed)
  uint32_t bt, prob;
  if (gate[dacfrom[daccount][wh]].dac<(LFSR_[wh]&4095)) prob=1; // which way round
  else prob=0;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
  //   bt=(*adcfromsddprob[CVM[wh]>>7])(depth, in, wh, prob); // 5 bits
  bt=(*adcfromsddprob[0])(depth, in, wh, prob); // TESTING
  // test
  return bt;
}

//and also using trigger 
static inline uint32_t probtrigadcselcvm(uint32_t depth, uint32_t in, uint32_t wh){  // select adc using CVM, prob from CVL which leaves CV(speed)
  uint32_t bt, prob;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
  //   bt=(*adcfromsddprob[CVM[wh]>>7])(depth, in, wh, prob); // 5 bits
  bt=(*adcfromsddprob[0])(depth, in, wh, gate[wh].trigger); // TESTING
  // test
  return bt;
}


static inline uint32_t zadcx(uint32_t depth, uint32_t in, uint32_t wh){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  
    if (bc<0) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      k=in>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadconebitsx(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t bc=31;
  static float integratorf=0.0f, oldvaluef=0.0f;
  float inb;
  depth=depth>>7; // 5 bits
  if (bc>depth){
  inb=(float)(in);
  //  inb=inb-2048.0; //sounds better without this
  //  inb=inb+CVL[0]; // offset
  inb=inb/2048.0; // from 0 to 4095 but where is the middle? 2048

  integratorf+=(inb-oldvaluef);
  bc=0;
  }
  bc++;
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

static inline uint32_t zadconebitsxreset(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static uint32_t bc=31;
  static float integratorf=0.0f, oldvaluef=0.0f;
  float inb;
  depth=depth>>7; // 5 bits
  if (bc>depth){
  inb=(float)(in);
  //  inb=inb-2048.0; //sounds better without this
  //  inb=inb+CVL[0]; // offset
  inb=inb/2048.0; // from 0 to 4095 but where is the middle? 2048

  integratorf+=(inb-oldvaluef);
  bc=0;
  }
  if (gate[wh].trigger==1) integratorf=0.0f;
  bc++;
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

static inline uint32_t zadcpadbits(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    k=in;
    depth=depth>>7; // 5 bits
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc12bits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 12,8,4  - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc8bits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
      k=k>>4;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first - no depth!
  bc--;
  return bt;
}

static inline uint32_t zadc4bits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadceqbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    k=in;
    depth=depth>>7; // 5 bits
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

static inline uint32_t zadcenergybits(uint32_t depth, uint32_t in, uint32_t wh){ // equiv bits energy TODO: use this
  uint32_t bt;
  static int32_t bc=31;
  int32_t tmp;
  static uint32_t k;
  if (bc>depth) {
    depth=depth>>7; // 5 bits
      k=in;
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

static inline uint32_t zadc12compbits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 12 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
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

static inline uint32_t zadc8compbits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 8 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
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

static inline uint32_t zadc4compbits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
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

static inline uint32_t zadccompbits(uint32_t depth, uint32_t in, uint32_t wh){ // variable depth 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;//   k=ADC_GetConversionValue(ADC1)>>(11-depth)  is included
      depth=depth>>7; // 5 bits
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

static inline uint32_t zadc12onecompbits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
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

static inline uint32_t zadc8onecompbits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 8 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
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

static inline uint32_t zadc4onecompbits(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
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

static inline uint32_t zadconecompbits(uint32_t depth, uint32_t in, uint32_t wh){ // variable 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
      depth=depth>>7; // 5 bits
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

////// right hand functions which change things...
// just a test here - uses CVL to select bitfunc
// but can't be in generic

static inline uint32_t Rtest(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt=0, bitrr, tmp;
  // fixed binroute
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  // do changes using depth which can be CVL or...
  bitfunccnt=depth>>8; // 16 is 4 bits
  
  return bt;
}

///// global functions here from exp
void zSR_globalbin(uint8_t w){ // global binary route for modeR. can run out fast without pulsin
  HEADSIN;
  //  SRlength[w]=CVL[w]>>7; // 5 bits
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  count=16; // sets to zero - but could also be ORed with route we already have as another version
  tmp=(CVL[w]>>5)&3;
  binary[0]=gate[tmp].shift_&15; // which SR? itself/runs out - binary will also need to be reset 
  binary[1]=(gate[tmp].shift_>>4)&15;
  binary[2]=(gate[tmp].shift_>>8)&15;
  binary[3]=(gate[tmp].shift_>>12)&15;
  
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

uint32_t (*genericfuncs[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bits,        zosc1bits, sigmadelta, cipher, osceq, zpulsebits, zprobbits, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits}; // doubled up a bit to hit 64 //  TEST

static inline uint32_t gensel(uint32_t depth, uint32_t in, uint32_t wh){  // select from a generic list - depth is param and in is the selection
  // in is not used in generic functions...
  // so for rungler we use CVM as that IN=cvbitcomp
   uint32_t bt;
   bt=(*genericfuncs[in>>6])(depth, 0, wh); // 6 bits=64 generic functions to collect
   return bt;
}

uint32_t (*adcfromsdd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, 
zadccompbits}; // doubled up // TEST!

// do similar for dac and adc...
// need dacfunctions for wrap dac access
static inline uint32_t adcselcvl(uint32_t depth, uint32_t in, uint32_t wh){  // select adc using CVL
   uint32_t bt;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
   bt=(*adcfromsdd[CVL[wh]>>7])(depth, in, wh); // 5 bits
   return bt;
}

static inline uint32_t adcselcvm(uint32_t depth, uint32_t in, uint32_t wh){  // select adc using CVM
   uint32_t bt;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
   bt=(*adcfromsdd[CVM[wh]>>7])(depth, in, wh); // 5 bits
   return bt;
}

// start to wrap dac functions - there are 24!
static inline uint32_t ddac0(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 0, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac1(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 1, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac2(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 2, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac3(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 3, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac4(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 4, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac5(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 5, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac6(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 6, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac7(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 7, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac8(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 8, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac9(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 9, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac10(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 10, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac11(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 11, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac12(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 12, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac13(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 13, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac14(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 14, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac15(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 15, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac16(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 16, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac17(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 17, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac18(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 18, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac19(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 19, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac20(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 20, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac21(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 21, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac22(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 22, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac23(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 23, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac24(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 24, depth, gate[wh].trigger);
return val;
}

uint32_t (*dacfromsdd[32])(uint32_t depth, uint32_t wh)={ddac0, ddac1, ddac2, ddac3, ddac4, ddac5, ddac6, ddac7, ddac8, ddac9, ddac10, ddac11, ddac12, ddac13, ddac14, ddac15, ddac16, ddac17, ddac18, ddac19, ddac20, ddac21, ddac22, ddac23, ddac24, ddac0, ddac1, ddac2, ddac3, ddac4, ddac5, ddac6};


static inline uint32_t dacselcvl(uint32_t depth, uint32_t wh){  // select adc using CVL
   uint32_t bt;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
   bt=(*dacfromsdd[CVL[wh]>>7])(depth, wh); // 5 bits
   return bt;
}

static inline uint32_t dacselcvm(uint32_t depth, uint32_t wh){  // select adc using CVL
   uint32_t bt;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
   bt=(*dacfromsdd[CVM[wh]>>7])(depth, wh); // 5 bits
   return bt;
}


// new modifier functions

static inline uint32_t bitsmod(uint32_t depth, uint32_t wh){  // select adc using CVL
   uint32_t bt=0;
   gate[wh].shift_^=depth;
   return bt;
}
