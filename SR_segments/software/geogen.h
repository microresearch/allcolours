

/// new functions for prob - comparator
static inline uint32_t comp(uint32_t depth, uint32_t in, uint32_t wh){
  if (depth>in) return 1;
  else return 0;
}

//////////////////////////////////////////////////////////////////////////
// binroute_probabilities - fixed routes

static inline uint32_t binroutfixed_prob1R(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - prob of routed or cycling // route from R
  uint32_t bt=0, bitrr;
  if (depth<(LFSR_[wh]&4095)) {
    bt = (gate[3].Gshift_[wh]>>SRlength[3]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[3].Gshift_[wh]=(gate[3].Gshift_[wh]<<1)+bt;
  }
    else
    {
    bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01; 
    }
  return bt;
}

static inline uint32_t binroutfixed_prob1L(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - prob of routed or cycling // route from L
  uint32_t bt=0, bitrr;
    if (depth<(LFSR_[wh]&4095)) {
    bt = (gate[1].Gshift_[wh]>>SRlength[1]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[1].Gshift_[wh]=(gate[1].Gshift_[wh]<<1)+bt;
     }
    else
    {
      bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
    }
  return bt;
}

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

static inline uint32_t binroutfixed_prob2(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - // prob of inverting routed bit // fixed
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
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

static inline uint32_t binroutfixed_prob4(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - *routed vs [routed^cycling]* -- fixed
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  if (depth<(LFSR_[wh]&4095)) {
    bt^=(gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
  }
  return bt;
}

static inline uint32_t binroutfixed_prob1_nosh(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - prob of routed or cycling
  uint32_t bt=0, bitrr;
  if (depth<(LFSR_[wh]&4095)) {
  depth=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    //    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
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

static inline uint32_t binroutfixed_prob2_nosh(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - // prob of inverting routed bit // fixed
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    //    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  if (depth<(LFSR_[wh]&4095)) bt=!bt;
  return bt;
}

static inline uint32_t binroutfixed_prob3_nosh(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - prob of routed or cycling INV
  uint32_t bt=0, bitrr;
  if (depth<(LFSR_[wh]&4095)) {
  depth=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    //    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
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

static inline uint32_t binroutfixed_prob4_nosh(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - *routed vs [routed^cycling]* -- fixed
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    //    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  if (depth<(LFSR_[wh]&4095)) {
    bt^=(gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
  }
  return bt;
}

//////////////////////////////////////////////////////////////////////////
// tails

// tail which is flipflop at speed of modeR - could be faster to always do in modeR rather than re-calc spd. or just a flag//same thing but if w==3 slows
void fliptail(void){ //
  // we can also use other gate[w].flips or even move through these
  //  HEADNADA;
  uint32_t w=8;
  GSHIFTRED_;
  gate[8].shift_+=gate[3].flip;
  //  gate[8].shift_=LFSR_[0];
}

void basictail(void){ // tail here is basic 4th binroute at full speed
  HEADNADA;
  uint32_t w=8;
  GSHIFT_;
  tmp=binroute[count][2]; // was 2... routes from ? 8124=2 // not 3?
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

void succtail(void){
  uint32_t bt=0;
  static uint32_t xx=0;
  uint32_t w=8;
  GSHIFT_;
  if (xx>3) xx=0;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  gate[xx].Gshift_[w]=(gate[xx].Gshift_[w]<<1)+bt;
  xx++;
  gate[w].shift_+=bt;
}

void succtailback(void){
  uint32_t bt=0;
  static int32_t xx=0;
  uint32_t w=8;
  GSHIFT_;
  if (xx<0) xx=3;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  gate[xx].Gshift_[w]=(gate[xx].Gshift_[w]<<1)+bt;
  xx--;
  gate[w].shift_+=bt;
}

void tailN(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
  gate[0].Gshift_[w]=(gate[0].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void tailL(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01;
  gate[1].Gshift_[w]=(gate[1].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void tailR(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01;
  gate[3].Gshift_[w]=(gate[3].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void tailC(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01;
  gate[2].Gshift_[w]=(gate[2].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void basictailnos(void){ // tail here is basic 4th binroute at full speed
  HEADNADA;
  uint32_t w=8;
  GSHIFT_;
  tmp=binroute[count][2]; // was 2... routes from ? 8124=2 // not 3?
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      bitn^=bitrr;    
    }
    tmp=tmp>>1;
  }
  gate[w].shift_+=bitn;
}

void tailLnos(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01;
  gate[w].shift_+=bt;
}

void tailRnos(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01;
  gate[w].shift_+=bt;
}

void tailCnos(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01;
  gate[w].shift_+=bt;
}

void tailNnos(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
  //  gate[2].Gshift_[w]=(gate[2].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void succtailnos(void){
  uint32_t bt=0;
  static uint32_t xx=0;
  uint32_t w=8;
  GSHIFT_;
  if (xx>3) xx=0;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  xx++;
  gate[w].shift_+=bt;
}

void succtailbacknos(void){
  uint32_t bt=0;
  static int32_t xx=0;
  uint32_t w=8;
  GSHIFT_;
  if (xx<0) xx=3;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  xx--;
  gate[w].shift_+=bt;
}

void basictailinv(void){ // tail here is basic 4th binroute at full speed
  HEADNADA;
  uint32_t w=8;
  GSHIFT_;
  tmp=binroute[count][2]; // was 2... routes from ? 8124=2 // not 3?
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
      bitn^=bitrr;    
    }
    tmp=tmp>>1;
  }
  gate[w].shift_+=!bitn;
}

void succtailinv(void){
  uint32_t bt=0;
  static uint32_t xx=0;
  uint32_t w=8;
  GSHIFT_;
  if (xx>3) xx=0;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  gate[xx].Gshift_[w]=(gate[xx].Gshift_[w]<<1)+bt;
  xx++;
  gate[w].shift_+=!bt;
}

void succtailbackinv(void){
  uint32_t bt=0;
  static int32_t xx=0;
  uint32_t w=8;
  GSHIFT_;
  if (xx<0) xx=3;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  gate[xx].Gshift_[w]=(gate[xx].Gshift_[w]<<1)+bt;
  xx--;
  gate[w].shift_+=!bt;
}

void tailNinv(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
  gate[0].Gshift_[w]=(gate[0].Gshift_[w]<<1)+bt;
  gate[w].shift_+=!bt;
}

void tailLinv(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01;
  gate[1].Gshift_[w]=(gate[1].Gshift_[w]<<1)+bt;
  gate[w].shift_+=!bt;
}

void tailRinv(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01;
  gate[3].Gshift_[w]=(gate[3].Gshift_[w]<<1)+bt;
  gate[w].shift_+=!bt;
}

void tailCinv(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01;
  gate[2].Gshift_[w]=(gate[2].Gshift_[w]<<1)+bt;
  gate[w].shift_+=!bt;
}

void basictailnosinv(void){ // tail here is basic 4th binroute at full speed
  HEADNADA;
  uint32_t w=8;
  GSHIFT_;
  tmp=binroute[count][2]; // was 2... routes from ? 8124=2 // not 3?
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      bitn^=bitrr;    
    }
    tmp=tmp>>1;
  }
  gate[w].shift_+=!bitn;
}

void tailLnosinv(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01;
  gate[w].shift_+=!bt;
}

void tailRnosinv(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01;
  gate[w].shift_+=!bt;
}

void tailCnosinv(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01;
  gate[w].shift_+=!bt;
}

void tailNnosinv(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
  gate[w].shift_+=!bt;
}

void succtailnosinv(void){
  uint32_t bt=0;
  static uint32_t xx=0;
  uint32_t w=8;
  GSHIFT_;
  if (xx>3) xx=0;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  xx++;
  gate[w].shift_+=!bt;
}

void succtailbacknosinv(void){
  uint32_t bt=0;
  static int32_t xx=0;
  uint32_t w=8;
  GSHIFT_;
  if (xx<0) xx=3;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  xx--;
  gate[w].shift_+=!bt;
}

void tailXOR0(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01; 
  bt ^= (gate[0].Gshift_[w]>>SRlength[0]) & 0x01; 
  gate[w].shift_+=bt;
}

void tailXOR1(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01; 
  bt ^= (gate[0].Gshift_[w]>>SRlength[0]) & 0x01; 
  gate[w].shift_+=bt;
}

void tailOR(void){
  uint32_t bt=0;
  uint32_t w=8;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01; 
  bt |= (gate[0].Gshift_[w]>>SRlength[0]) & 0x01; 
  gate[w].shift_+=bt;
}


//////////////////////////////////////////////////////////////////////////
//1
//routes

static inline uint32_t binrout(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now // TODO: indie version
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

// DONE but lots of blanks... re-write so first one is bit and then after we have AND - so is not 2x AND
// flexible route...
static inline uint32_t binroutAND0(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... shared bits now // TODO: indie version - this one with AND
  uint32_t bt=0, bitrr, once=0;
  depth=depth>>8; // 12 bits to 4 bits
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    //    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bt=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
    if (depth&0x01 && x!=wh){  // never itself
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    //    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    if (once==0) bt=bitrr; // but that is always lowest one of the route... but only a difference with more than 2 routes or?
    else bt&=bitrr; 
    once++;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t binroutAND00(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel... GShift_
  uint32_t bt=0, bitrr, once=0;
  depth=depth>>8; // 12 bits to 4 bits
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshift_[wh]>>SRlength[8]) & 0x01; 
    //    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bt=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
    if (depth&0x01 && x!=wh){  // never itself
      bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; 
    //    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    if (once==0) bt=bitrr; // but that is always lowest one of the route... but only a difference with more than 2 routes or?
    else bt&=bitrr; 
    once++;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

// testing dual fixed routes - TODO: to also bump/move these locally and globally
// some routes don't work...
static inline uint32_t binroutAND1(uint32_t depth, uint32_t in, uint32_t wh){ // androutes dual routes...
  uint32_t bt=0, bitrr, once=0;
  depth=androutes[count][wh];
  for (uint8_t x=0;x<4;x++){
    if (depth&0x01){  
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    if (once==0) bt=bitrr; 
    else bt&=bitrr; 
    once++;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binroutAND11(uint32_t depth, uint32_t in, uint32_t wh){ // androutes dual routes... Gshift
  uint32_t bt=0, bitrr, once=0;
  depth=androutes[count][wh];
  for (uint8_t x=0;x<4;x++){
    if (depth&0x01){  
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; 
    //gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr; //we don't shift it as we dont want to run at speed
    if (once==0) bt=bitrr; 
    else bt&=bitrr; 
    once++;
  }
  depth=depth>>1;
  }
  return bt;
}


static inline uint32_t zjustcycle(uint32_t depth, uint32_t in, uint32_t wh){ // just cycle// no depth
  uint32_t bt;
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t zjusttail(uint32_t depth, uint32_t in, uint32_t wh){ // just tail// no depth
  uint32_t bt;
  bt = (gate[8].Gshift_[wh]>>SRlength[8]) & 0x01;// tail
  
  return bt;
}

static inline uint32_t zjusttailwithdepth(uint32_t depth, uint32_t in, uint32_t wh){ // just tail// with depth - how?
  uint32_t bt;
  float speed;
  speed=logspeed[depth>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  bt = (gate[8].Gshift_[8]>>SRlength[8]) & 0x01;// tail

  if(gate[wh].last_time<gate[wh].int_time) {
    bt|=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  return bt;
}

// TODO: adapt for binroute alts ??? what are these??
static inline uint32_t binroutfixed(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

// TODO: check binroutes: the route itself // type of binroute... binroutetypes[binroutetypecount][w];
/* 
routes: 
tmp=binroute[count][wh]|binary[wh];
tmp=myroute[w][gate[w].route]|binary[w];
depth=depth>>8; // 12 bits to 4 bits // but we do tail for that one too

each has one of  8: BINROUTE_, BINROUTESR_; BINROUTEalt_; BINROUTEZERO_; BINROUTESHARE_; BINROUTENOG_; BINROUTEtrig_; BINROUTEnoalt_;  // new one which just cycles and doesn't reset

so we have 24... do we want to fill all of those out!?
*/

// adding in ANDs and OR routes

//binroutfixedmy, binroutfixedmy, binroutmybumpS, binroutmycv
//eg. TODO: fill out
static inline uint32_t binroutfixedmyalt1(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute MY // no depth
  uint32_t bitn=0, bitrr, tmp, x;
  tmp=myroute[w][gate[w].route]|binary[w];
  BINROUTESRstrip_; // alts here TODO!
  return bitn;
}

static inline uint32_t binroutfixedmy(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute MY // no depth
  uint32_t bitn=0, bitrr, tmp, x;
  BINROUTEMY_;
  return bitn;
}

static inline uint32_t binroutfixedmyreset(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute MY // no depth
  uint32_t bitn=0, bitrr, tmp, x;
  gate[w].route=0;
  BINROUTEMY_;
  return bitn;
}


static inline uint32_t binroutmybumpS(uint32_t depth, uint32_t in, uint32_t w){   // bumping myroute STROBE // no depth
  uint32_t bitn=0, bitrr, tmp, x;
  if (gate[w].trigger) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;

  BINROUTEMY_;
  return bitn;
}

static inline uint32_t binroutmybumpbit(uint32_t depth, uint32_t in, uint32_t w){   // bumping myroute bits // no depth
  uint32_t bitn=0, bitrr, tmp, x;
  if (gate[dacfrom[daccount][w]].shift_) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;
  BINROUTEMY_;
  return bitn;
}

static inline uint32_t binroutmybumpbitt(uint32_t depth, uint32_t in, uint32_t w){   // bumping myroute bits // no depth
  uint32_t bitn=0, bitrr, tmp, x;
  if (gate[dacfrom[daccount][w]].Gshift_[w]) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;
  BINROUTEMY_;
  return bitn;
}

static inline uint32_t binroutmycv(uint32_t depth, uint32_t in, uint32_t w){   // CV->myroute so we can use DAC // depth
  uint32_t bitn=0, bitrr, tmp, x;
  gate[w].route=depth>>8; // 4 bits 0-16 routes TODO could be more
  BINROUTEMY_;
  return bitn;
}

static inline uint32_t binroutesel0(uint32_t depth, uint32_t in, uint32_t w){ // no depth
  uint32_t x, tmp, bitrr, bitn=0;
    uint32_t tmpp=binroutetypes[binroutetypecount][w];
    switch(tmpp){
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
    case 8:
      BINROUTEMY_;  // new one for local route
    break;
    default:
      BINROUTE_;
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
    case 1:
      BINROUTESRstrip_;
    break;
    case 2:
      BINROUTEaltstrip_;
    break;
    case 3:
      BINROUTEZEROstrip_;
    break;
    case 4:
      BINROUTESHAREstrip_;
    break;
    case 5:
      BINROUTENOGstrip_;
    break;
    case 6:
      BINROUTEtrigstrip_;
    break;
    case 7:
      BINROUTEnoaltstrip_;  // new one which just cycles and doesn't reset
    break;
    default:
      BINROUTEstrip_;
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
    case 8:
      BINROUTEMY_;  // new one for local route
    break;
    }
    return bitn;
}

static inline uint32_t binroutesel3(uint32_t depth, uint32_t in, uint32_t w){ // local route
  uint32_t x, tmp, bitrr, bitn=0;
    uint32_t tmpp=depth>>9; // 3 bits
  tmp=myroute[w][gate[w].route]|binary[w];
    switch(tmpp){
    case 1:
      BINROUTESRstrip_;
    break;
    case 2:
      BINROUTEaltstrip_;
    break;
    case 3:
      BINROUTEZEROstrip_;
    break;
    case 4:
      BINROUTESHAREstrip_;
    break;
    case 5:
      BINROUTENOGstrip_;
    break;
    case 6:
      BINROUTEtrigstrip_;
    break;
    case 7:
      BINROUTEnoaltstrip_;  // new one which just cycles and doesn't reset
    break;
    default:
      BINROUTEstrip_;
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

static inline uint32_t zbinroutfixed_noshift_transit(uint32_t depth, uint32_t in, uint32_t wh){ //  no depth
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint8_t lastone=0;
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (lastone!=bt) btt=1; // it was a transition 0-1 1-0
  lastone=bt;
  return btt;
}

static inline uint32_t zbinroutfixed_noshift_transitI(uint32_t depth, uint32_t in, uint32_t wh){ //  no depth
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint8_t lastone[4]={0,0,0,0};
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (lastone[wh]!=bt) btt=1; // it was a transition 0-1 1-0
  lastone[wh]=bt;
  return btt;
}

static inline uint32_t zbinroutfixed_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - no shift //  no depth
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    //    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t zbinroutfixedcycle_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // no depth
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  tmp=tmp|wh; // adds itself
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t zbinroutfixedI_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // no depth
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
    }
  return bt;
}

static inline uint32_t zbinroutfixedcycleI_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][wh]|binary[wh];
  tmp=tmp|wh; // add itself in
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
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

// copy GSR to another and keep there (so only on entry or on strobe...// to shared array) - could also be indie versions!
static inline uint32_t zcopyGSR(uint32_t depth, uint32_t in, uint32_t wh){
  static uint32_t sharey;
  uint32_t bt=0;
  if (gate[wh].changed==0) {
    sharey=gate[wh].Gshare_;
  }
  bt=(sharey>>(depth>>7)) & 0x01;
  sharey=(sharey<<1)+bt;
  return bt;
}

static inline uint32_t zcopyGSR_s(uint32_t depth, uint32_t in, uint32_t wh){ // strobe
  static uint32_t sharey;
  uint32_t bt=0;
  if (gate[wh].trigger) {
    sharey=gate[wh].Gshare_;
  }
  bt=(sharey>>(depth>>7)) & 0x01;
  sharey=(sharey<<1)+bt;
  return bt;
}

//////////////////////////////////////////////////////////////////////////
//3
// speeds - which can also be generic bit functions! and vice versa...
// speeds need to set helds[wh]

/* // unused as we can always hold speed
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
*/  

static inline uint32_t spdfrac(uint32_t depth, uint32_t in, uint32_t wh){ // for speed now with dac/interpol pulled out
  uint32_t bt=0;
  float speed;
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

static inline uint32_t spdfracend(uint32_t depth, uint32_t in, uint32_t wh){ // for speed now with dac/interpol pulled out // version with STOP on lowest
  uint32_t bt=0;
  float speed;
  speed=logspeed[depth>>2]; // 12 bits to 10 bits
  if (speed!=LOWEST){
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  if(gate[wh].last_time<gate[wh].int_time) {
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  }
  return bt;
}


//INx
static inline uint32_t spdfrac2(uint32_t depth, uint32_t in, uint32_t wh){ // we add depth and in //INx
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) tmp=depth;
  else tmp=depth%in;
  //  tmp=in+depth;
  //  if (tmp>4095) tmp=4095;
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

//INx
static inline uint32_t spdfrac3(uint32_t depth, uint32_t in, uint32_t wh){ // we add depth and in //INx
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  tmp=in+depth;
  if (tmp>4095) tmp=4095;
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

//INx
static inline uint32_t spdfrac4(uint32_t depth, uint32_t in, uint32_t wh){ // we add depth and in //INx
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  tmp=(depth>>2)-512;
  tmp+=(in>>2);  
  if (tmp<0) tmp=0;
  else if (tmp>1023) tmp=1023;

  speed=logspeed[tmp]; 
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

//INx
static inline uint32_t spdfracdac3(uint32_t depth, uint32_t in, uint32_t wh){ // depth is offset, in is constraint -- and speed from dac = gate[speedfrom[spdcount][w]].dac
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  tmp=gate[speedfrom[spdcount][wh]].dac%in;
  tmp+=depth;
  if (tmp>4095) tmp=4095;    

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

// strobe list: uint32_t (*speedfromstrobe[7])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebits, ztogglebitssh, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle};

static inline uint32_t strobe(uint32_t depth, uint32_t in, uint32_t wh){   // strobe - no depth
  uint32_t bt;
  bt=gate[wh].trigger;
  //  gate[wh].strobed=1; // we are in a mode which uses strobe - TODO: set to 0 in other potential speed modes
  return bt;
}

static inline uint32_t strobespdfrac(uint32_t depth, uint32_t in, uint32_t wh){ // for speed now with dac/interpol pulled out
  uint32_t bt=0;
  float speed;
  speed=logspeed[depth>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  if(gate[wh].last_time<gate[wh].int_time || gate[wh].trigger) {
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  return bt;
}

static inline uint32_t zstrobeBURST(uint32_t depth, uint32_t in, uint32_t wh){ // 
  uint32_t bt=0;

  if (gate[wh].trigger){
    train[wh]=1;
  }
  if (train[wh]!=0 && train[wh]< (4096-(depth))){
  train[wh]++;
  //  bitn^=ADC_(wh,SRlength[wh],0,gate[wh].trigger,dacfrom[daccount][wh],param[wh], &gate[wh].shift_);
  bt=1;
  }
  else {
    train[wh]=0;
  }
  return bt;
}


static inline uint32_t ztogglebits(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt[4]={0,0,0,0};
  if (gate[wh].trigger) bt[wh]=bt[wh]^1;
  return bt[wh];
}

// can also have shared toggles
static inline uint32_t ztogglebitssh(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt=0;//,0,0,0};
  if (gate[wh].trigger) bt=bt^1;
  return bt;
}

static inline uint32_t stroberoute(uint32_t depth, uint32_t in, uint32_t wh){   // strobe - no depth - bump on local route for speed
  uint32_t bitn=0, x, bt, tmp, bitrr;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[wh].trigger) localroute[wh]++;
  if (localroute[wh]>15) localroute[wh]=1;
  tmp=localroute[wh];
  BINROUTESRstrip_;
  bt=bitrr;
  //  gate[wh].strobed=1; // we are in a mode which uses strobe - TODO: set to 0 in other potential speed modes
  return bt;
}

static inline uint32_t strobezsuccbits_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // no use of depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x=0;
  if (x==wh) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;
  //  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  if (gate[wh].trigger) x++;
  return bt;
}

static inline uint32_t strobezsuccbitsI_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // no use of depth - we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x[4]={0};
  if (x[wh]==wh) x[wh]++;
  if (x[wh]>3) x[wh]=0;
  bt = (gate[x[wh]].Gshift_[0]>>SRlength[x[wh]]) & 0x01;
  //  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bt;
  if (gate[wh].trigger) x[wh]++;
  return bt;
}

// added more strobey fixed routes. to test
static inline uint32_t strzbinroutfixed_noshift_transit(uint32_t depth, uint32_t in, uint32_t wh){ //  no depth. strobe
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint8_t lastone=0;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[wh].trigger) localroute[wh]++;
  if (localroute[wh]>15) localroute[wh]=1;
  tmp=localroute[wh];
  
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (lastone!=bt) btt=1; // it was a transition 0-1 1-0
  lastone=bt;
  return btt;
}

static inline uint32_t strzbinroutfixed_noshift_transitI(uint32_t depth, uint32_t in, uint32_t wh){ //  no depth. strobe
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint8_t lastone[4]={0,0,0,0};
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[wh].trigger) localroute[wh]++;
  if (localroute[wh]>15) localroute[wh]=1;
  tmp=localroute[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (lastone[wh]!=bt) btt=1; // it was a transition 0-1 1-0
  lastone[wh]=bt;
  return btt;
}

static inline uint32_t strzbinroutfixed_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // fixed binroute from count - no shift //  no depth strobe
  uint32_t bt=0, bitrr, tmp;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[wh].trigger) localroute[wh]++;
  if (localroute[wh]>15) localroute[wh]=1;
  tmp=localroute[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    //    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t strzbinroutfixedI_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // no depth strobe
  uint32_t bt=0, bitrr, tmp;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[wh].trigger) localroute[wh]++;
  if (localroute[wh]>15) localroute[wh]=1;
  tmp=localroute[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
    }
  return bt;
}

//////////////////////////////////////////////////////////////////////////
//4
//generic bits

// zero/nada
static inline uint32_t zeros(uint32_t depth, uint32_t in, uint32_t wh){  // returns only zeroes
  return 0;
}

static inline uint32_t pzeros(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){  // returns only zeroes
  return 0;
}


// one - can also be for speeds or otherwise
static inline uint32_t ones(uint32_t depth, uint32_t in, uint32_t wh){ 
  return 1;
}

// top bit of clksr 
static inline uint32_t clksr(uint32_t depth, uint32_t in, uint32_t wh){  // but these still need set strobe bit but..
  uint32_t bt=0;
    depth=depth>>7; //  5 bits
  bt=(clksr_[wh]>>depth)&0x01;
  return bt;
}

// how could we cycle through clksr if it is not moving - we need gsr for them -clksrG_
static inline uint32_t clksrG(uint32_t depth, uint32_t in, uint32_t wh){ // depthi
  uint32_t bt=0;
  depth=depth>>7; //  5 bits
  bt=(clksrG_[wh]>>depth)&0x01;
  clksrG_[wh]=(clksrG_[wh]<<1)+bt; // this also changes patterns there
  return bt;
}

// try 8 bit cipher mode
//ADC/depth in comparator -> bits, clked/speed into GGSR which shifts along, on strobe GGSR copied to SR
static inline uint32_t cipher(uint32_t depth, uint32_t in, uint32_t wh){// uses depth
  uint32_t bt, k;
  //  uint32_t kw[4]={0,0,0,0};
  static uint32_t gs[4]={0,0,0,0};
  //  kw[wh]=depth;
  //  depth=(depth-2048)<<1;
  if (depth<in) bt=1; 
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

static inline uint32_t pcipher(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){
  uint32_t bt, k;
  //  uint32_t kw[4]={0,0,0,0};
  static uint32_t gs[4]={0,0,0,0};
  //  kw[wh]=depth;
  //  depth=(depth-2048)<<1;
  if (depth<in) bt=1; 
  else bt=0;
  
  // onto SR
  if (adv){
  GGGshift_[wh]=GGGshift_[wh]<<1;
  GGGshift_[wh]+=bt;
  }
  // on strobe copy to gs
  if (gate[wh].trigger || reset) gs[wh]=GGGshift_[wh];
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

static inline uint32_t flipflop(uint32_t depth, uint32_t in, uint32_t wh){  // so all share // NO DEPTH
  uint32_t bt;
  static uint32_t fl=0;
  fl^=1;
  bt=fl;
  return bt;
}

static inline uint32_t flipflopandroute(uint32_t depth, uint32_t in, uint32_t wh){  // so all share // NO DEPTH - but depth could be route
  uint32_t bt, bitrr;
  static uint32_t fl=0;
  fl^=1;
  bt=fl;
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

static inline uint32_t flipflopI(uint32_t depth, uint32_t in, uint32_t wh){  // so all share// NO DEPTH
  uint32_t bt;
  static uint32_t fl[4]={0,0,0,0};
  fl[wh]^=1;
  bt=fl[wh];
  return bt;
}


// generic in from gen.h

//four SRbits
static inline uint32_t zSRNbits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits as max 32
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

static inline uint32_t zprobbits(uint32_t depth, uint32_t in, uint32_t wh){   // PROBability mode
  uint32_t bt=0;
  if (depth>(LFSR_[wh]&4095)) bt=1; // changed direction
  return bt;
}

static inline uint32_t zownprobbits(uint32_t depth, uint32_t in, uint32_t wh){   // PROBability mode
  uint32_t bt=0;
  if (depth>(gate[wh].shift_&4095)) bt=1; // changed direction
  return bt;
}

static inline uint32_t zownGprobbits(uint32_t depth, uint32_t in, uint32_t wh){   // PROBability mode
  uint32_t bt=0;
  if (depth>(gate[wh].Gshift_[wh]&4095)) bt=1; // changed direction
  return bt;
}


static inline uint32_t zinvprobbits(uint32_t depth, uint32_t in, uint32_t wh){   // PROBability mode - other way round
  uint32_t bt=0;
  if (depth<(LFSR_[wh]&4095)) bt=1;
  return bt;
}

static inline uint32_t zsprobbits(uint32_t depth, uint32_t in, uint32_t wh){   // PROBability mode - other way round depends on strobe
  uint32_t bt=0;
  if (gate[wh].trigger) {
  if (depth>(LFSR_[wh]&4095)) bt=1;
    }
  else 
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

// but depth could also be param to advance x or shift on // as a probability also
static inline uint32_t zsuccbits(uint32_t depth, uint32_t in, uint32_t wh){   // no use of depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x=0; // shared
  if (x==wh) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bt;
  x++;
  return bt;
}

static inline uint32_t zsuccbitsprob(uint32_t depth, uint32_t in, uint32_t wh){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x=0;
  if (x==wh) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; 
  if (depth>(LFSR_[wh]&4095)) gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bt;
  x++;
  return bt;
}

// version without shift for speeds - but we need depth

static inline uint32_t zsuccbits_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x=0;
  if (x==wh) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;
  //  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  if (depth>(LFSR_[wh]&4095)) x++;
  return bt;
}

static inline uint32_t zsuccbitsI(uint32_t depth, uint32_t in, uint32_t wh){   // no use of depth - we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x[4]={0};
  if (x[wh]==wh) x[wh]++;
  if (x[wh]>3) x[wh]=0;
  bt = (gate[x[wh]].Gshift_[0]>>SRlength[x[wh]]) & 0x01;
  //  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bt;
  x[wh]++;
  return bt;
}

static inline uint32_t zsuccbitsI_noshift(uint32_t depth, uint32_t in, uint32_t wh){   // we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x[4]={0};
  if (x[wh]==wh) x[wh]++;
  if (x[wh]>3) x[wh]=0;
  bt = (gate[x[wh]].Gshift_[0]>>SRlength[x[wh]]) & 0x01;
  //  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bt;
  if (depth>(LFSR_[wh]&4095)) x[wh]++;
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
  static uint32_t lastbt=0,n=0;
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
  if (gate[wh].trigger) {
    depth=4095-depth;
    bc=depth;
  }
  if (bc<0) {
    bt=0;
    //    if (depth>0) bc=depth;
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
  //  bt=(LFSR_[wh]>>24)&0x01;
  //  bt=1;
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
  depth=depth>>7; // 5 bits
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

static inline uint32_t zcompbits(uint32_t depth, uint32_t in, uint32_t wh){  //INx we need 
  uint32_t bt;
  if (in>depth) bt=0; // which way round?
  else bt=1;
  return bt;
}

static inline uint32_t zpattern4bits(uint32_t depth, uint32_t in, uint32_t wh){ //INx
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

static inline uint32_t zpattern8bits(uint32_t depth, uint32_t in, uint32_t wh){ //INx
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

static inline uint32_t zpattern4bitsI(uint32_t depth, uint32_t in, uint32_t wh){ //INx
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

static inline uint32_t zpattern8bitsI(uint32_t depth, uint32_t in, uint32_t wh){ //INx
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

static inline uint32_t sigmadelta(uint32_t depth, uint32_t in, uint32_t wh){  // processor for any int/depth
  uint32_t bt=0;
  static int32_t integrator=0, oldValue=0;
  depth=4095-depth;
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

//////////////////////////////////////////////////////////////////////////
//5
//adc - these just become interpreters for IN values which can be adc! depth is control/CV

//uint32_t (*adcfromsd[20])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, cipher, zadcLBURST0};///  test cipher


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
    depth=depth>>7; // 5 bits
  if (bc>depth) {

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
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
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


static inline uint32_t zadcLBURST0(uint32_t depth, uint32_t in, uint32_t wh){ // 
  static uint32_t bt;

  if (gate[wh].trigger){
    train[wh]=1;
  }
  if (train[wh]!=0 && train[wh]< (1024-(depth>>2))){
  train[wh]++;
  //  bitn^=ADC_(wh,SRlength[wh],0,gate[wh].trigger,dacfrom[daccount][wh],param[wh], &gate[wh].shift_);
  bt=zadc4bits(0, in, wh);
  }
  else {
    train[wh]=0;
  }
  return bt;
}

static inline uint32_t zadccomp(uint32_t depth, uint32_t in, uint32_t wh){ // 
  uint32_t bt=0;
  if (in>depth) bt=1;
  return bt;
}

static inline uint32_t zadcxdouble(uint32_t depth, uint32_t in, uint32_t wh){ // max 12 bits
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
  bc--;
  return bt;
}

static inline uint32_t zadcxcut(uint32_t depth, uint32_t in, uint32_t wh){ // max 12 bits // strobe
  uint32_t bt, length;
  static uint32_t k, nn[4]={0,0,0,0};
  static int32_t n[4]={0,0,0,0} ;
  static uint32_t toggle[4]={0,0,0,0}, lastbt[4]={0,0,0,0}, lastin[4]={0,0,0,0};

  nn[wh]++;
  //    if (gate[wh].trigger) nn[wh]++;
    if (nn[wh]>depth){ 
	nn[wh]=0;
	toggle[wh]^=1;
      }
    length=SRlength[wh];
    if (length>11) length=11;

    if (n[wh]<0) {
      lastbt[wh]=(gate[dacfrom[daccount][wh]].dac)>>(11-length);
      lastin[wh]=in>>(11-length);
	n[wh]=length;
      }
      if (toggle[wh]) bt = (lastin[wh]>>n[wh])&0x01; // this means that MSB comes out first
      else bt = (lastbt[wh]>>n[wh])&0x01; // this means that MSB comes out first
    n[wh]--;    
    return bt;
}

// add and other ops - only issue is if depth and in are both the same dac = how to avoid this? different dacs?
static inline uint32_t zadc4bitsadd(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=depth+in;
      k=k>>8;
      k=k&15;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsaddmod(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=depth+in;
      k=k%4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsxor(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=depth^in;
      //      if (k>4095) k=4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsor(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=depth|in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsand(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=depth&in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsmodm(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in%depth;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4onecompbitsadd(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbitsadd(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in+depth;
      k=k>>8;
      k=k&15;
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

static inline uint32_t zadc4compbitsxor(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in^depth;
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

static inline uint32_t zadc4compbitsmodm(uint32_t depth, uint32_t in, uint32_t wh){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in%depth;
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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// adcs for prob or reset and/or hold

// prototype
static inline uint32_t zpadcx(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // max 12 bits
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
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadconebitsx(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){
  uint32_t bt;
  static uint32_t bc=31;
  static float integratorf=0.0f, oldvaluef=0.0f;
  float inb;
  depth=depth>>7; // 5 bits
  if (bc>depth || reset){
  inb=(float)(in);
  //  inb=inb-2048.0; //sounds better without this
  //  inb=inb+CVL[0]; // offset
  inb=inb/2048.0; // from 0 to 4095 but where is the middle? 2048

  integratorf+=(inb-oldvaluef);
  bc=0;
  }
  if (adv) bc++;
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

static inline uint32_t zpadcpadbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0 || reset) {
    k=in;
    depth=depth>>7; // 5 bits
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc12bits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 12,8,4  - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc8bits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      k=k>>4;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first - no depth!
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadceqbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0 || reset) {
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
    
    if (adv)  bc--;
  return bt;
}

static inline uint32_t zpadcenergybits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // equiv bits energy TODO: use this
  uint32_t bt;
  static int32_t bc=31;
  int32_t tmp;
  static uint32_t k;
    depth=depth>>7; // 5 bits
  if (bc>depth || reset) {

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
    if (adv) bc++;    
    return bt;
}

static inline uint32_t zpadc12compbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 12 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (bitwise) k=(~k)+1;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc8compbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 8 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (bitwise) k=(~k)+1;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4compbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadccompbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // variable depth 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset ) {
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
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc12onecompbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in;
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc8onecompbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 8 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
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
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4onecompbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadconecompbits(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // variable 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
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
  if (adv) bc--;
  return bt;
}


static inline uint32_t zpadcLBURST0(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // 
  static uint32_t bt;

  if (gate[wh].trigger || reset){
    train[wh]=1;
  }
  if (train[wh]!=0 && train[wh]< (1024-(depth>>2))){
    if (adv) train[wh]++;
  //  bitn^=ADC_(wh,SRlength[wh],0,gate[wh].trigger,dacfrom[daccount][wh],param[wh], &gate[wh].shift_);
  bt=zadc4bits(0, in, wh);
  }
  else {
    train[wh]=0;
  }
  return bt;
}

static inline uint32_t zpadccomp(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // 
  uint32_t bt=0;
  if (in>depth) bt=1;
  return bt;
}

static inline uint32_t zpadcxdouble(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  
    if (bc<0  || reset) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      k=in>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv){
  bc--;
  bc--;
  }
  return bt;
}

static inline uint32_t zpadcxcut(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // max 12 bits // strobe
  uint32_t bt, length;
  static uint32_t k, nn[4]={0,0,0,0};
  static int32_t n[4]={0,0,0,0} ;
  static uint32_t toggle[4]={0,0,0,0}, lastbt[4]={0,0,0,0}, lastin[4]={0,0,0,0};

  nn[wh]++;
  //    if (gate[wh].trigger) nn[wh]++;
    if (nn[wh]>depth  || reset){ 
	nn[wh]=0;
	toggle[wh]^=1;
      }
    length=SRlength[wh];
    if (length>11) length=11;

    if (n[wh]<0) {
      lastbt[wh]=(gate[dacfrom[daccount][wh]].dac)>>(11-length);
      lastin[wh]=in>>(11-length);
	n[wh]=length;
      }
      if (toggle[wh]) bt = (lastin[wh]>>n[wh])&0x01; // this means that MSB comes out first
      else bt = (lastbt[wh]>>n[wh])&0x01; // this means that MSB comes out first
      if (adv) n[wh]--;    
    return bt;
}

// add and other ops - only issue is if depth and in are both the same dac = how to avoid this? different dacs?
static inline uint32_t zpadc4bitsadd(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth+in;
      k=k>>8;
      k=k&15;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsaddmod(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth+in;
      k=k%4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsxor(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth^in;
      //      if (k>4095) k=4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsor(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth|in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsand(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth&in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsmodm(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in%depth;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4onecompbitsadd(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4compbitsadd(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4compbitsxor(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in^depth;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4compbitsmodm(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in%depth;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

/////////////////////////////////////////////////////////////////
// value functions
// return a value from bits (this is what dacs do)... process a value... generate a value (eg. from a route)
// but question is how many bits... always 12

//SRx determines route SRy to give value to determine route SRz to  ... value from route... ->  routevalue(routevalue(x,in,w),in,w) - how much depth
//followed by binroute
//single route or multiples
//try multiples...
// value from value
static inline uint32_t routevalue(uint32_t depth, uint32_t in, uint32_t wh){ //
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
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 4095; // 12 bits no shift
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt; // as a value 12 bits
}
  
/////////////////////////////////////////////////////////////////
// newer/ports from experiment.h

// vienna: divide into speedmode and bitmode
static inline uint32_t spdvienna(uint32_t depth, uint32_t in, uint32_t wh){ // //INx
  uint32_t bt=0, speedy;
  // say CVL as depth, CV as in
  uint32_t recurse=(7-(depth>>4))&3; // 2 bits
  if (recurse!=0){
    speedy=in+gate[others[wh][recurse-1]].dac; // can also be different versions such as modulus or mid version
    if (speedy>4095) speedy=4095;
  }
  else speedy=in;
  
  bt=spdfrac(speedy, in, wh);
  return bt;
}

static inline uint32_t viennabits(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t bt=0, tmp, tmpp, recurs, bitrr,x;
  // say CVL as depth as above - in is not used
  
  // 7 bits from mode/now CVL - 
  tmpp=127-(depth>>5); // 7 bits  
  if (tmpp>>6) recurs=1; // top bit
  
  if (recurs!=0 && wh==2){ // for C only  // why?
    tmpp|=(gate[others[wh][0]].shift_)&15;    
  }
  
  if (tmpp==0 && wh==2) { // SR5 is 8th which is outside these bits - for modeC only
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01;
    gate[wh].shift_ ^=gate[8].Gshare_;
    bt=bitrr;
  }
else
  {
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr; 
	bt=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
  }
  return bt;
}

//////////////// [+outside functions+] and ports from experiment.h - observation that most OUTSIDE functions should be paired with specific inside/bits

static uint32_t delayline[512]; //shared delay line
static uint32_t delaylineUN[4][512]; //UNshared delay line

static inline uint32_t delay_line_in(uint32_t depth, uint32_t wh){
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits[4]={0,0,0,0}; // 32 bits of bits
  // put into delay line - need index and bit index
  tmp=bits[wh]/32;
  tmpp=bits[wh]%32;
  delaylineUN[wh][tmp]&=bitmasky[tmpp];
  delaylineUN[wh][tmp]|=(depth<<(tmpp));
  bits[wh]++;
  if (bits[wh]>16383) bits[wh]=0;
}

static inline uint32_t delay_line_out(uint32_t depth, uint32_t wh){
  uint32_t bt=0, tmp;
  tmp=depth/32;
  bt=(delaylineUN[wh][tmp]>>(depth%32))&0x01;
  return bt;
}

uint32_t OUT_SRdelay_lineIN(uint32_t depth, uint32_t w){  // could also be shared version of this // we need delay_lineOUT to match
  uint32_t bitn, tmp,x, bitrr;
  BINROUTESR_; // or other forms
  delay_line_in(bitn,w);
  return 0;
}

uint32_t SRdelay_lineOUT(uint32_t depth, uint32_t in, uint32_t w){  // could also be shared version of this //XX  -- well cnt was shared so...
  static uint32_t cnt[4]={0,0,0,0};
  uint32_t bitn;
  bitn=delay_line_out(cnt[w],w); // or detach - length not used - this is our binroute
  cnt[w]++;
  if (cnt[w]>16383) cnt[w]=0;
  return bitn;
}

//////////////////////////////////////////////////////////////////////////
////// right hand functions which change things... what are the counts we use, where are our examples

///// global functions here from exp, they don't return bits // find these

static inline void binaryN(uint32_t depth){
  uint32_t tmp;
  // all counts need that extra or
  //  count=16; // sets to zero - but could also be ORed with route we already have as another version // count16 is  0,0,0,0, null routes... // but we set all counts the same so have a problem
  tmp=depth>>10;// 2 bits
  binary[0]=gate[tmp].shift_&15; // which SR? itself/runs out - binary will also need to be reset 
  binary[1]=(gate[tmp].shift_>>4)&15;
  binary[2]=(gate[tmp].shift_>>8)&15;
  binary[3]=(gate[tmp].shift_>>12)&15;
}

static inline void binaryX(uint32_t depth){
  uint32_t tmp;
  count=0; // reset... or should be oldroutecnt
  tmp=depth>>10; // 2 bits
  binary[0]=gate[tmp].shift_&15; // which SR? itself/runs out - binary will also need to be reset 
  binary[1]=(gate[tmp].shift_>>4)&15;
  binary[2]=(gate[tmp].shift_>>8)&15;
  binary[3]=(gate[tmp].shift_>>12)&15;
}

static inline void resett(uint32_t depth){ // resett // no depth
  RESETR;
}

/// add in master set of glob index into these with a fixed route
//// but then we still need depth - one sets glob, one does glob work and any other 
static inline uint32_t selectglob(uint32_t depth, uint32_t in, uint32_t wh){ // resett
  uint32_t bt;
  bt=binroutfixed(0,0,wh);
  glob=depth>>8; // 4 bits=16
  return bt;
}

static inline void SRRglobalbumpS(uint32_t depth){ // strobe only
  if (gate[3].trigger) // outside speed?
    {
      count++;
      if (count>15) count=0; // we have 16 so far, but can add more
      daccount++;
      if (daccount>15) daccount=0;
      spdcount++;
      if (spdcount>15) spdcount=0;
    }
}

// TODO: more singular variations of these
static inline void SRRglobalbumpbit0(uint32_t depth){ // nada but depth could be route
  if (gate[dacfrom[daccount][3]].shift_) // outside speed?
    {
      count++;
      if (count>15) count=0; // we have 16 so far, but can add more
      daccount++;
      if (daccount>15) daccount=0;
      spdcount++;
      if (spdcount>15) spdcount=0;
    }
}

static inline void SRRglobalbumpbit1(uint32_t depth){ // nada but depth could be route
  if (gate[dacfrom[daccount][3]].Gshift_[3]) // outside speed?
    {
      count++;
      if (count>15) count=0; // we have 16 so far, but can add more
      daccount++;
      if (daccount>15) daccount=0;
      spdcount++;
      if (spdcount>15) spdcount=0;
    }
}

static inline void SRRglobalbumpbit2(uint32_t depth){ // nada but depth AS route
  if (gate[depth>>10].Gshift_[3]) // outside speed?
    {
      count++;
      if (count>15) count=0; // we have 16 so far, but can add more
      daccount++;
      if (daccount>15) daccount=0;
      spdcount++;
      if (spdcount>15) spdcount=0;
    }
}


static inline void SRRglobalbumproute(uint32_t depth){ // strobe only
  if (gate[3].trigger) // outside speed?
    {
      count++;
      if (count>15) count=0; // we have 16 so far, but can add more
    }
}

static inline void SRRglobalbumpdac(uint32_t depth){ // strobe only
  if (gate[3].trigger) // outside speed?
    {
      daccount++;
      if (daccount>15) daccount=0; // we have 16 so far, but can add more
    }
}

static inline void SRRglobalbumpspd(uint32_t depth){ // strobe only
  if (gate[3].trigger) // outside speed?
    {
      spdcount++;
      if (spdcount>15) spdcount=0; // we have 16 so far, but can add more
    }
}

static inline void SRRglobalbumpcv(uint32_t depth){ // strobe only
  uint32_t tmp;
  if (gate[3].trigger) // outside speed?
    {
      tmp=depth>>8; ///4 bits
      count=tmp;
      daccount=tmp;
      spdcount=tmp;
      binroutetypecount=tmp;
    }
}

static inline void SRRglobalbumpcvn(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>8; ///4 bits
  count=tmp;
  daccount=tmp;
  spdcount=tmp;
  binroutetypecount=tmp;
}

static inline void SRRglobalbumpcvnroute(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>8; ///4 bits
  count=tmp;
}

static inline void SRRglobalbumpcvndac(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>8; ///4 bits
  daccount=tmp;
}

static inline void SRRglobalbumpcvnspd(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>8; ///4 bits
  spdcount=tmp;
}

static inline void SRRglobalbumpcvntype(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>8; ///4 bits
  binroutetypecount=tmp;
}

static inline void SRRglobalsync(uint32_t depth){ // nada no depth
  uint32_t tmp;
  spdcount=count;
  daccount=count;
  binroutetypecount=count;
}

// bump

static inline void SRRglobalorder(uint32_t depth){ // depth
  uint32_t tmp;
  ordercount=depth>>8; // 4 bits
}

static inline void SRRglobalorderbumpS(uint32_t depth){ // strobe no depth
  uint32_t tmp;
  if (gate[3].trigger)
    {
      ordercount++;
      if (ordercount>15) ordercount=0; // we have 16 so far, but can add more
    }
}

static inline void SRRglobalorderbumpbit(uint32_t depth){ // nada. depth can be route // no depth
  uint32_t tmp;
  if (gate[dacfrom[daccount][3]].shift_)
    {
      ordercount++;
      if (ordercount>15) ordercount=0; // we have 16 so far, but can add more
    }
}

// adding new functions 8/8 which can be for speed or bits or ported ones... // tails can also be these globals but maybe nice not to run these so fast

// tailbitsI, tailbitswithd, tailbitsIwithd

static inline uint32_t tailbits(uint32_t depth, uint32_t in, uint32_t wh){  // just bits from the tail [8] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
  gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
  bt^=bitrr;
  return bt;
}  

static inline uint32_t tailbitsI(uint32_t depth, uint32_t in, uint32_t wh){  // just bits from the tail [8] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[8].Gshift_[wh]>>SRlength[8]) & 0x01; 
  gate[8].Gshift_[wh]=(gate[8].Gshift_[wh]<<1)+bitrr;
  bt^=bitrr;
  return bt;
}  

static inline uint32_t tailbitswithd(uint32_t depth, uint32_t in, uint32_t wh){  // just bits from the tail [8] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[8].Gshare_>>(depth>>7)) & 0x01; 
  gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
  bt^=bitrr;
  return bt;
}  

static inline uint32_t tailbitsIwithd(uint32_t depth, uint32_t in, uint32_t wh){  // just bits from the tail [8] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[8].Gshift_[wh]>>(depth>>7)) & 0x01; 
  gate[8].Gshift_[wh]=(gate[8].Gshift_[wh]<<1)+bitrr;
  bt^=bitrr;
  return bt;
}  
