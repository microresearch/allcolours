//////////////////////////////////////////////////////////////////////////
// abstract GENERATORS... adc ones are in adcetc.h

// some don't use depth, how to deal with this? can also be more INVERTED

// try 8 bit cipher mode
//ADC in comparator -> bits, clked/speed into GGSR which shifts along, on strobe GGSR copied to SR
static inline uint32_t cipherbits(uint32_t depth, uint8_t wh){
  uint32_t bt, k;
  uint32_t kw[4]={0,0,0,0};
  static uint32_t gs[4]={0,0,0,0};
  ADCgeneric;
  kw[wh]=k;
  //  depth=(depth-2048)<<1;
  if (kw[wh]>(2000)) bt=1; // we ignore depth - what it could be used for...
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

// can also be other comps eg. dac. how we could stack this up and why this is a generator, can also be shared across all...
// shared and unsured adcs...

//four SRbits
static inline uint32_t SRNbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[0].Gshift_[wh]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

static inline uint32_t SRLbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[1].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t SRCbits(uint32_t depth, uint8_t wh){ 
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[2].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t SRRbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[3].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t strobebits(uint32_t depth, uint8_t wh){   // strobe - no depth
  uint32_t bt;
  bt=gate[wh].trigger;
  return bt;
}

static inline uint32_t togglebits(uint32_t depth, uint8_t wh){   // toggle - no depth
  static uint32_t bt=0;
  if (gate[wh].trigger) bt=bt^1;
  return bt;
}

static inline uint32_t pulsebits(uint32_t depth, uint8_t wh){   // toggle - no depth
  static uint32_t bt=0;
  if (pulse[wh]){
    bt=!(GPIOC->IDR & pulsins[wh]);
  }
  return bt;
}

static inline uint32_t probbits(uint32_t depth, uint8_t wh){   // PROBability mode
  uint32_t bt=0;
  if (depth<(LFSR_[wh]&4095)) bt=1;
  return bt;
}

// but depth could also be param to advance x or shift on
static inline uint32_t succbits(uint32_t depth, uint8_t wh){   // no use of depth - we route from each sr in turn
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

static inline uint32_t succbitsI(uint32_t depth, uint8_t wh){   // no use of depth - we route from each sr in turn - independent version
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

static inline uint32_t binroutebits(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
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

static inline uint32_t binrouteORbits(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
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

static inline uint32_t binrouteANDbits(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
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

static inline uint32_t binrouteSRbits(uint32_t depth, uint8_t wh){   // depth as routesel... SR itself, no GSR 
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

// depth can be length or param
static inline uint32_t returnbits(uint32_t depth, uint8_t wh){   // returning but we need ref to itself SR//, and its length/ as depth - starts to look like adc_ functions now
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  //  bt=(*SR>>depth)& 0x01; // but return should be of ghost...   bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		
  bt = (gate[wh].Gshift_[wh]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

//inverted
static inline uint32_t returnnotbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  //  bt=(*SR>>depth)& 0x01; // but return should be of ghost...   bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		
  bt = !((gate[wh].Gshift_[wh]>>depth) & 0x01);		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

//abstract: oscbits, osc1bits-also questions of static patterns, TM bits, onebits, ENbits, Ensbits
// could also have fixed one set of oscbits eg. osceqbits
// what else.... more on static patterns from dac or adc

// non-independent ones
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

// we already have EN version
//WIARD versions - macro versions - inside themselves
//WIARD: noise/comp selects new input or loop back/inverted loop back (jumper)

//WIARD
static inline uint32_t wiardbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh];
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

static inline uint32_t wiardinvbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh];
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

static inline uint32_t TMsimplebits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;				
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
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t ENsroutedbits(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  if ((gate[inroute[count][wh]].Gshift_[wh]&4095)<prob) bt=(gate[inroute[count][wh]].Gshift_[wh]>>SRlength[inroute[count][wh]])&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t compbits(uint32_t depth, uint8_t wh){ // what happens when is called successively?
  uint32_t bt;
  uint32_t k;
  ADCgeneric;
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdacbits(uint32_t depth, uint8_t wh){ // runs out in loop
  uint32_t bt;
  uint32_t k;
  //  ADCgeneric;
  k=(gate[defdac].dac); // we fix on dac[3] 
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdaccbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  uint32_t k;
  ADCgeneric;
  if (k>(gate[defdac].dac)) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t pattern4bits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    k=gate[defdac].shift_&15;
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
    k=gate[defdac].shift_&255;
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

static inline uint32_t llfsrbits(uint32_t depth, uint8_t wh){ // no depth
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

uint32_t (*altabstractbitstreams[16])(uint32_t depth, uint8_t wh)={TMsimplebits, probbits, binroutebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, compbits, compdacbits, compdaccbits, pattern4bits, pattern8bits, patternadcbits, succbits, flipbits};

uint32_t (*abstractbitstreamslong[32])(uint32_t depth, uint8_t wh)={binroutebits, binrouteSRbits, binrouteANDbits, binrouteORbits, returnbits, returnnotbits, probbits, succbits, wiardbits, wiardinvbits, osceqbits, osc1bits, onebits, ENbits, ENsbits, ENsroutedbits, TMsimplebits, compbits, compdacbits, compdaccbits, pattern4bits, pattern8bits, patternadcbits, lfsrbits, llfsrbits, flipbits, strobebits, togglebits, }; // 28 so far // we want 32=5 bits


// probbits, succbits, wiardbits, wiardinvbits and some independent versions --> maybe expand to 31 

/////////////////////////////////////////// INDEPENDENT ones

static inline uint32_t binroutebitsI(uint32_t depth, uint8_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
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

static inline uint32_t osceqbitsI(uint32_t depth, uint8_t wh){  
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

static inline uint32_t osc1bitsI(uint32_t depth, uint8_t wh){  
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

static inline uint32_t TMsimplebitsI(uint32_t depth, uint8_t wh){
  uint32_t bt,k;
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;				
  //  ADCgeneric;
  if (depth>(LFSR_[wh]&4095)) bt=!bt;
  return bt;
}

static inline uint32_t wiardbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh];
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

static inline uint32_t wiardinvbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh];
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

static inline uint32_t onebitsI(uint32_t depth, uint8_t wh){ // depth=0 resets
  uint32_t bt;
  static int32_t bc[4]={31};
  //  static uint32_t k;
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
static inline uint32_t ENbitsI(uint32_t prob, uint8_t wh){ 
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
static inline uint32_t ENsbitsI(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  if ((LFSR_[wh]&4095)<prob) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
    //    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t compbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  ADCgeneric;
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdacbitsI(uint32_t depth, uint8_t wh){ // runs out in loop
  uint32_t bt;
  static uint32_t k;
  //  ADCgeneric;
  k=(gate[defdac].dac); 
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdaccbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  ADCgeneric;
  if (k>(gate[defdac].dac)) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t pattern4bitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  if (n[wh]>depth){
    n[wh]=0;
    k[wh]=gate[defdac].shift_&15;
  }
  if (nn[wh]>3){ // or count down
    nn[wh]=0;
  }
  bt=k[wh]>>nn[wh];
  n[wh]++; nn[wh]++;
  return bt;
}

static inline uint32_t patternadcbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  if (n[wh]>depth){
    n[wh]=0;
    //    ADCgeneric;
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); 
  ADC_SoftwareStartConv(ADC1);						
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  k[wh]=ADC_GetConversionValue(ADC1)>>8;				   
  //  k[wh]=k[wh]>>8;
  }
  if (nn[wh]>3){ // or count down
    nn[wh]=0;
  }
  bt=k[wh]>>nn[wh];
  n[wh]++; nn[wh]++;
  return bt;
}


static inline uint32_t pattern8bitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  if (n[wh]>depth){
    n[wh]=0;
    k[wh]=gate[defdac].shift_&255;
  }
  if (nn[wh]>7){ // or count down
    nn[wh]=0;
  }
  bt=k[wh]>>nn[wh];
  n[wh]++; nn[wh]++;
  return bt;
}

static inline uint32_t lfsrbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
    bt = ((ADCshift_[wh] >> (lfsr_taps[depth][0])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][1])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][2])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][3]))) & 1u;
    ADCshift_[wh]=(ADCshift_[wh]<<1)+bt;
    if (ADCshift_[wh]==0) ADCshift_[wh]=0xff;
    return bt;
}

static inline uint32_t llfsrbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  // out from lfsr at full speed
  bt=(LFSR_[wh]>>31)&0x01;
  return bt;
}


static inline uint32_t flipbitsI(uint32_t depth, uint8_t wh){  
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

uint32_t (*abstractbitstreamsI[16])(uint32_t depth, uint8_t wh)={binroutebitsI, osceqbitsI, osc1bitsI, onebitsI, ENbitsI, ENsbitsI, TMsimplebitsI, compbitsI, compdacbitsI, compdaccbitsI, pattern4bitsI, pattern8bitsI, patternadcbitsI, lfsrbitsI, llfsrbitsI, flipbitsI};

