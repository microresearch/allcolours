// check all modes set type of dac?

#define DACOUT {				\
  HEAD;						\
  if (w==2 || speedf_[w]!=LOWEST){				\
    CVOPEN;						\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}

#define DACOUTNOV {				\
  HEAD;						\
  if (w==2 || speedf_[w]!=LOWEST){				\
    CVOPENNOINTERPOL;						\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;				\
      ENDER;						\
    }							\
  }							\
}


#define DACOUTGGG {				\
  HEAD;						\
  if (w==2 || speedf_[w]!=LOWEST){				\
    CVOPEN;						\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTENOG_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}


#define DACOUTX {				\
  HEADSIN;						\
  if (w==2 || speedf_[w]!=LOWEST){				\
    CVOPEN;						\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}


// no << in gshift
#define DACOUTNOG {				\
  HEAD;						\
  if (w==2 || speedf_[w]!=LOWEST){				\
    CVOPEN;						\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTENOG_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}

// 6/4
// say NLR can be generators into XOR (full mode) on CSR - DAC - can also be mix of logics and prob there...
// so we have routes in for 1,2,8=11
// 3 possible logics/or/prob - start with logic
// different dac options

void dacNLRin(uint8_t w){  // this one is just fixed XOR
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  tmp=11;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
 if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
   BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void dacNLRinlogic(uint8_t w){  // figure out bits for logic - also as possible strobe mode // logic can also be dac
  HEADSIN;
  uint8_t what=CVL[w]>>6; // 6 bits - 2 bits per NLC
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  tmp=11;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn=logopx(bitn,bitrr,what&0x03);
  }
  tmp=tmp>>1; what=what>>2;
    }			     
 if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
   BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

// probability of one stream vs other stream - say l vs r? or other options
void dacLRprob(uint8_t w){  
  HEADSIN;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;

  if (((LFSR_[w] & 4095 ) < CVL[w])) x=1;
  else x=3;

  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;

  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

// probability of one stream vs other stream - say l vs r? or other options
void dacLRprobxorN(uint8_t w){  // and XOR N in now...
  HEADSIN;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;

  if (((LFSR_[w] & 4095 ) < CVL[w])) x=1;
  else x=3;

  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;

  x=0;
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;

  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

// 1 2 8  merge/mix according to CVL 1 to 2 to 8 - can be other orders also...
// version for merge across 1,3,11 - also other logics
void dacNLRprobin(uint8_t w){  // this one is just fixed XOR
  HEADSIN; // detach
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  //  tmp=11; // 12 bits first 6 bits is
  if (((LFSR_[w] & 2047) > CVL[w])) tmp=1; 
  else tmp=2; 
  if (CVL[w]>2047){
    if (((LFSR_[w] & 2047) < (CVL[w]-2047))) tmp=8;
  }
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
 if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
   BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

// version for merge across 1,3,11 and inverted - also other logics
void dacNLRprobin1311(uint8_t w){  // this one is just fixed XOR
  HEADSIN; // detach
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  //  tmp=11; // 12 bits first 6 bits is
  if (((LFSR_[w] & 2047) > CVL[w])) tmp=1; 
  else tmp=3; 
  if (CVL[w]>2047){
    if (((LFSR_[w] & 2047) < (CVL[w]-2047))) tmp=11;
  }
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr; // where can we get logic from? max 6 bits 3x2bits logics... - so as an intmode detached we can do it
  }
  tmp=tmp>>1;
    }			     
 if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
   BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void dacLNLRin(uint8_t w){  // this one is just fixed XOR - detach length to pick our DAC
  HEADSIN;
  gate[w].dactype=CVL[w]>>8; // 16 so 4 bits
  gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  tmp=11;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
 if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
   BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}


// test adc in and dac out in one
void dacadc(uint8_t w){
  HEAD;				
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;				
  bitn=ADC_(w,SRlength[w],85,gate[w].trigger,dacfrom[daccount][w],CVL[w], &gate[w].shift_); // 85 so 1 bit from comparator
  BITN_AND_OUTV_; // pulses outs - was VN no pulses???
  ENDER;
  }
  }
}

// run through DAC modes with correct params set if necessary

void dacosc0(uint8_t w){ // test oscillator
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void dacLLswop(uint8_t w){ // swop in or logop SR - cv and cvl ***
  uint32_t lin, lout;
  HEADSSINNADA;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_; 
    if (gate[w].trigger) {
      lin=127-(CV[w]>>5); //7= 2 bits for whichone and start which can be 5
      lout=31-(CVL[w]>>7); // 5 bits for length
      // length of incoming - lout
      tmp=gate[lin&0x03].shift_>>(31-lout);
      gate[w].shift_^=(tmp<<(31-(lin>>2)));
      //gate[w].shift_=gate[oppose[w]].shift_; // sieve is previous one but could be opposite one
    }
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


// template for newmodes 
void dacN(uint8_t w){ 
  gate[w].dactype=0; gate[w].dacpar=param[w];
  HEAD;
  if (w==2 || speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void dacLBURST0(uint8_t w){ 
  // DETACH LENGTH
  HEADSIN;
  gate[w].dactype=0; gate[w].dacpar=param[w];

  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (gate[w].trigger){
    train[w]=1;
  }
  if (train[w]!=0 && train[w]< (1024-(CVL[w]>>2))){
  train[w]++;
    BINROUTE_;
  }
  else {
    train[w]=0;
    bitn=0;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

 // but we need vary length and otherpar
void dacL16slide(uint8_t w){   // DETACH SPEED
  gate[w].dactype=16; gate[w].dacpar=CV[w]>>7;
 HEADSSIN
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

//SRC: output from oscs or from SRN - select our input - route from...
// we want to use CVL to select which one we route from and type of dac?
// general purpose: what are variations?
void dacLrung0(uint8_t w){ // detached length
  HEADSIN;
  if (w==2 || speedf_[w]!=LOWEST){ // remove!
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  tmp=CVL[w]>>6;// 2 bits for route, 4 bits for DACtype = 6 bits
  gate[w].dactype=tmp>>2; gate[w].dacpar=param[w];
  GSHIFT_;
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  //  tmp=myroute[w][gate[w].route]; // route from N, L, or R = 3 options +itself = 0,1,2,3
  tmp=tmp&0x03; // 2 bits
  bitrr = (gate[tmp].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[tmp].Gshift_[w]=(gate[tmp].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;

  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void dacN17_0(uint8_t w){ 
  gate[w].dactype=0; gate[w].dacpar=param[w];
  HEAD;
  if (w==2 || speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    if (gate[w].trigger)	  bitrr=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
    else bitrr=!((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
    bitn=bitn|bitrr;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void dacN18_0(uint8_t w){ 
  static uint8_t tug[4]={0};
  gate[w].dactype=0; gate[w].dacpar=param[w];
  HEAD;
  if (w==2 || speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]){
      BINROUTEANDCYCLE_;
    }
    else {
      bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }	    
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


void dacLDACSEL0(uint8_t w){ // detached
  uint8_t mmm=CVL[w]>>8; // to 4 bits
  gate[w].dactype=mmm; gate[w].dacpar=param[w];
  DACOUTX;
}

void dacL12(uint8_t w){ // detached - interval DAC
  gate[w].dactype=12; gate[w].dacpar=31-(CVL[w]>>7);
  DACOUTX;
  //      GSHIFT_;					       
  //      BINROUTE_;				       
  //      BITN_AND_OUTVINT_;				   
}


void dacLDACSRSEL0(uint8_t w){
  uint8_t mmm=CVL[w]>>8; // to 4 bits
  gate[w].dactype=(mmm)&(DACFROM&15);
  gate[w].dacpar=param[w]; // other logical opps
  DACOUTX;
}


void dac0(uint8_t w){
  gate[w].dactype=0; gate[w].dacpar=param[w];
  DACOUT;
}

void dacnov0(uint8_t w){
  gate[w].dactype=0; gate[w].dacpar=param[w];
  DACOUTNOV;
}


void dac0nog(uint8_t w){
  gate[w].dactype=0; gate[w].dacpar=param[w];
  DACOUTNOG;
}

void dac1(uint8_t w){
  gate[w].dactype=1; gate[w].dacpar=param[w];
  DACOUT;
}

void dac2(uint8_t w){ // one bit audio - set beta with param so fix now as: 2048
  // dependent on speed
  gate[w].dactype=2; gate[w].dacpar=4096-CVL[w]; //     betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
  DACOUTX; // if we keep length same and use CVL
}

void dac3(uint8_t w){
  gate[w].dactype=3; gate[w].dacpar=param[w];
  DACOUT;
}

void dac4(uint8_t w){
  gate[w].dactype=4; gate[w].dacpar=param[w];
  DACOUT;
}

void dac5(uint8_t w){
  gate[w].dactype=5; gate[w].dacpar=param[w];
  DACOUT;
}

void dac6(uint8_t w){
  gate[w].dactype=6; gate[w].dacpar=param[w];
  DACOUT;
}

void dac7(uint8_t w){
  gate[w].dactype=7; gate[w].dacpar=param[w];
  DACOUT;
}

void dac8(uint8_t w){
  gate[w].dactype=8; gate[w].dacpar=param[w];
  DACOUT;
}

void dac9(uint8_t w){
  gate[w].dactype=9; gate[w].dacpar=param[w];
  DACOUT;
}

void dac10(uint8_t w){
  gate[w].dactype=10; gate[w].dacpar=param[w];
  DACOUT;
}

void dac11(uint8_t w){
  gate[w].dactype=11; gate[w].dacpar=param[w];
  DACOUT;
}

void dac12(uint8_t w){
  gate[w].dactype=12; gate[w].dacpar=param[w];
  DACOUT;
}

void dac13(uint8_t w){
  gate[w].dactype=13; gate[w].dacpar=param[w];
  DACOUT;
}

void dac14(uint8_t w){
  gate[w].dactype=14; gate[w].dacpar=param[w];
  DACOUT;
}

void dac15(uint8_t w){ // one bit audio with param as filter
  gate[w].dactype=2; gate[w].dacpar=4095-(param[w]&4095);
  DACOUT;
}

void dacreal15(uint8_t w){ 
  gate[w].dactype=15; gate[w].dacpar=4095-(param[w]&4095);
  DACOUT;
}


void dac17(uint8_t w){ // 12 bits audio from 2s complement
  gate[w].dactype=17; gate[w].dacpar=4095-(param[w]&4095);
  DACOUT;
}

void dac18(uint8_t w){ // 12 bits audio from 2s complement
  gate[w].dactype=18; gate[w].dacpar=4095-(param[w]&4095);
  DACOUT;
}

void dac19(uint8_t w){ // x bits audio from 2s complement
  gate[w].dactype=19; gate[w].dacpar=4095-(param[w]&4095);
  DACOUT;
}

void dac20(uint8_t w){ // 12 bits audio from ONEs complement
  gate[w].dactype=20; gate[w].dacpar=4095-(param[w]&4095);
  DACOUT;
}

void dac21(uint8_t w){ // x bits audio from ONEs complement
  gate[w].dactype=21; gate[w].dacpar=4095-(param[w]&4095);
  DACOUT;
}



void dac67_4bits(uint8_t w){ // stock 4 bit DAC - nothing to do with length!!!! TODO: use length PARAM as....
  gate[w].dactype=67; gate[w].dacpar=param[w];
  DACOUT;
}

void dac67_4bitsNOGG(uint8_t w){ // stock 4 bit DAC - nothing to do with length!!!! TODO: use length PARAM as....
  gate[w].dactype=67; gate[w].dacpar=param[w];
  DACOUTGGG;
}


void dac66(uint8_t w){ // default basic 4 bit dac
  gate[w].dactype=66; gate[w].dacpar=param[w];
  DACOUT;
}

void dac68(uint8_t w){ // default basic 4 bit dac with no timing
  gate[w].dactype=68; gate[w].dacpar=param[w];
  DACOUT;
}



void dactest(uint8_t w){ // for speed 1hz to 20hz triangle here...
  // but why do we lose it ????
  static uint32_t togg=0;
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  CVOPEN;
  if (gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    togg^=1;
    bitn=togg;
    BITN_AND_OUTV_; // with pulses
    ENDER;
  }
  }  

// TODO: just bump within a restricted range or array which make sense?
void dacbumproute0(uint8_t w){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  if (gate[w].trigger) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;
  tmp=myroute[w][gate[w].route];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void dacDACroute0(uint8_t w){ 
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][w]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
 if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
   BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void dacSRroute0(uint8_t w){ 
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][w]].Gshift_[w]&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void dac32(uint8_t w){ // multiple bits in as case 19 in draftdec
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    gate[w].shift_&=spacmask[SRlength[w]]; //cleared
    if (SRlength[inroute[count][w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0])) >>(lastspac[SRlength[inroute[count][w]]][0]))+ \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))          >> ((lastspac[SRlength[inroute[count][w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))         >>((lastspac[SRlength[inroute[count][w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))         >>((lastspac[SRlength[inroute[count][w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0]))>>(lastspac[SRlength[inroute[count][w]]][0])) + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[inroute[count][w]]][1]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[inroute[count][w]]][2]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[inroute[count][w]]][3])));
    }
    bitn=gate[w].shift_&1; // fixed this 29/12/2021
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }    
  }
}


///////////////////////////////////////////////////////////////////////////
// CV+DAC speed modes TODO:

void dacdacadditself0(uint8_t w){ // tested//trial itself as DAC - can also be other variants TODO
  HEAD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[w].dac>>3)];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacdacghostitself0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEAD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+((gate[w].Gshift_[routeto[count][w]])&511)];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacdacghostincoming0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEAD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+((gate[w].Gshift_[inroute[count][w]])&511)];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacdacseladd0(uint8_t w){
  HEAD;
  float speedf__;
  uint8_t whic=(CV[w]>>9)&3; //12 bits -> 2 bits
  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacdacadd0(uint8_t w){
  HEAD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[dacfrom[daccount][w]].dac>>3)];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacdacminus0(uint8_t w){
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[daccount][w]].dac>>2)-(1024-(CV[w]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacdacspeedminus0(uint8_t w){
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)-(gate[speedfrom[spdcount][w]].dac>>2); 
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacdacmod0(uint8_t w){
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeed[(gate[speedfrom[spdcount][w]].dac>>2)%cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacB0(uint8_t w){// with oscillator
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)-(gate[speedfrom[spdcount][w]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][1],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dacdacoffset0(uint8_t w){
  gate[w].dactype=0; gate[w].dacpar=param[w];
  float speedf__;
  float mmm=(float)(1024-(CVL[w]>>2))/1024.0f;
  HEADSSINNADA;
  tmp=(1024-(CV[w]>>2)) + (int)((float)(gate[speedfrom[spdcount][w]].dac>>2)*mmm);
  if (tmp>1023) tmp=1023;
  if (tmp<0) tmp=0;
  speedf__=logspeed[tmp]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// INTmodes

void dacint0(uint8_t w){ // INTmode 0 no interpolation and no use of CV
  gate[w].dactype=0; gate[w].dacpar=param[w];
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; // we have pulse out
  } 
}

void dacint12(uint8_t w){ // INTmode - 
  HEADSSINNADA;
  // trial length down to 0  
  SRlength[w]=31-(CVL[w]>>7);
  gate[w].dactype=12; gate[w].dacpar=31-(CV[w]>>7);
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; // we have pulse out
  } 
}


void dacintslide16(uint8_t w){ // window // speed is param// we need length so no detach
  gate[w].dactype=16; gate[w].dacpar=CV[w]>>7; // 5 bits
  HEADSSIN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; // we have pulse out
  } 
}

void dacintroute0(uint8_t w){ // CV: 4 bits for route in... other bits for logop
  HEAD;
    gate[w].dactype=0; gate[w].dacpar=param[w];
  if (gate[w].trigger)      {
    GSHIFT_;
    tmp=255-(CV[w]>>4); // 8 bits
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
    // no binroute needed
    BITN_AND_OUTVINT_; // for pulse out
  } 
}


// last intmode - select any DAC which doesn't use param/strobe:
// list of these: 0,1,2(gate[w].dacpar=2048;),3,6,7,8,11,15 = 9 mode - maybe reduce to 8 and have other bits for route
// so is 3 bits for choice and 4 for route = 7 bits total = 128
void dacintselDAC_63(uint8_t w){ 
  uint8_t choice[8]={0,1,2,3, 6,7,11,15};
  gate[w].dacpar=2048;
  HEAD;
  if (gate[w].trigger)      {
    val=127-(CV[w]>>5); // 7 bits say
    GSHIFT_;
    tmp=(val>>4); // 3 bits
    gate[w].dactype=choice[tmp];
    tmp=(val&15);// lowest 4 bits for routing
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	bitn^=bitrr;
  }
      tmp=tmp>>1;
    }			     
    BITN_AND_OUTVINT_; // pulse out
  } 
}

void dacLNint104(uint8_t w){ // let's try INT driven one for pulse train mode
  // INT triggers train of CV pulses at speed DAC - and can also be vice versa
  // INT can also start new train or let old one carry on (now it starts new train...)
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (gate[w].trigger)      {
    train[w]=1;
  }
  
  //  if (counter[w]>CV[1]){
  if (train[w]!=0){

    if (train[w]<(1024-(CV[w]>>2))){ // number of pulses
	if (counter[w]>(gate[dacfrom[count][w]].dac>>2) ){ // or another dac
	counter[w]=0;
	train[w]++;
	GSHIFT_;
	BINROUTE_;
	BITN_AND_OUTVINT_;    
      }
    }
  else train[w]=0; // train ran out
}
}

  void dacLNint105(uint8_t w){ // let's try INT driven one for pulse train mode
  // INT triggers train of CV pulses at speed DAC - and can also be vice versa
  // INT can also start new train or let old one carry on (now it starts new train...)
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (gate[w].trigger)      {
    train[w]=1;
  }
  
  //  if (counter[w]>CV[1]){
  if (train[w]!=0){
    if (train[w]<(gate[dacfrom[count][w]].dac>>2)){ // number of pulses
      if (counter[w]>((CV[w]>>2))){ // or another dac
	counter[w]=0;
	train[w]++;
	GSHIFT_;
	BINROUTE_;
	BITN_AND_OUTVINT_;    
      }
    }
  else train[w]=0; // train ran out
}
}

// with logop 
void dacNLRprobinINT1311(uint8_t w){  // this one is just fixed XOR
  HEADSIN; // detach length
  uint8_t logg;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  if (gate[w].trigger)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  if (((LFSR_[w] & 2047) > CVL[w])) tmp=1; 
  else tmp=3; 
  if (CVL[w]>2047){
    if (((LFSR_[w] & 2047) < (CVL[w]-2047))) tmp=11;
  }
  logg=CV[w]>>4; // 8 bits = 4x2 logic bits
  //  first 2 are fake - 0 for just XOR
  logg=logg&0b11111100;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn=logopxx(bitn,bitrr,logg&3); // where can we get logic from? max 6 bits 3x2bits logics... - so as an intmode detached we can do it
  }
  tmp=tmp>>1; logg=logg>>2;
    }			     
 if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
 BITN_AND_OUTVINT_; // with pulses
  }
}

//- can also use CV[w] for dac select
void dacNLRprobinINT1311seldac(uint8_t w){  // this one is just fixed XOR
  HEADSIN; // detach length
  uint8_t logg;
  gate[w].dactype=CV[w]>>8; gate[w].dacpar=4096; // 4 bits  
  if (gate[w].trigger)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  if (((LFSR_[w] & 2047) > CVL[w])) tmp=1; 
  else tmp=3; 
  if (CVL[w]>2047){
    if (((LFSR_[w] & 2047) < (CVL[w]-2047))) tmp=11;
  }
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1; 
    }			     
 if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
 BITN_AND_OUTVINT_; // with pulses
  }
}
