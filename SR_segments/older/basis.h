/* for testing include here
  {adc0}, 
  {SR_speedx}, // SRX0 is basic route/xor
  {dac0}, 
  {SRX0}
*/

// streams for sequential entry of bits into each register - could also be 4 bits
// from modeN.h
void stream(uint8_t w){ // sequential 12 bit in - use also for L, R, N
  HEAD;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=adcpadbits(11);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLbinprob(uint8_t w){ // binroute in as prob of entry of new bit from adc or cycle
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  val=CVL[w]>>8; // 4 bits 
  ///////HERE
  BINROUTENOS_;
  if (bitn){
    bitn=(*adcbitstreams[val])(SRlength[w]);
    PULSIN_XOR;
  }
  else {
    JUSTCYCLE_;
    PULSIN_XOR;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void adcLabstractLD(uint8_t w){ // abstract modes with option now binroute or not - now with fixed length=depth so we have speed
  HEADSIN; // detach length
  uint32_t depth;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  tmp=CVL[w]>>6; // 4 bits + 2 now - 6 bits
  if (tmp&0x01)  bitn=(*abstractbitstreams[tmp>>2])(SRlength[w],w);
  else bitn=(*abstractbitstreamsI[tmp>>2])(SRlength[w],w);
  if (tmp&0x02){    
    BINROUTE_;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }


void adcLabstract(uint8_t w){ // abstract modes with option now binroute or not
  HEADSSINNADA;
  uint32_t depth;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  tmp=CVL[w]>>6; // 4 bits + 2 now - 6 bits
  depth=CV[w]; // 12-> 5 bits below
  if (tmp&0x01)  bitn=(*abstractbitstreams[tmp>>2])(depth,w);
  else bitn=(*abstractbitstreamsI[tmp>>2])(depth,w); // independent
  if (tmp&0x02){    
    BINROUTE_;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

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



#define ADCNOIN(X){				\
  HEAD;						\
  if (speedf_[w]!=LOWEST){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;			\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }
// no binroute in

void adc30(uint8_t w){ 
  //  ADCNOIN(30);
  //}
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[0].dac>>2)-(1023-(CV[w]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],29,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator // options?
    BITN_AND_OUTV_;
    ENDER;
  }
}



void SRnull(uint8_t w){ //
}

#define DACOUTX {				\
  HEADSIN;						\
  if (w==2 || speedf_[w]!=LOWEST){				\
    CVOPEN;							\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      bitn=bitn|gate[w].trigger;			\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}
// TEST with trigger above

#define ADCXORIN(X){				\
  HEAD;					\
  if (speedf_[w]!=LOWEST){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  BINROUTE_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }

// with sr not gsr
#define ADCXORINSR(X){				\
  HEAD;					\
  if (speedf_[w]!=LOWEST){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  BINROUTE_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }


#define ADCXORINNOINT(X){				\
  HEAD;					\
  if (speedf_[w]!=LOWEST){			\
  CVOPENNOINTERPOL;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }


void adc0(uint8_t w){ // basic ADC in with XOR route in
  ADCXORIN(0);
}

void adc85(uint8_t w){ // one bit comp 2000
  ADCXORIN(85);
}


void adc2(uint8_t w){ // one bit audio  
  ADCXORIN(2);
}

void adc0noint(uint8_t w){ // basic ADC in with XOR route in
  ADCXORINNOINT(0);
}


#define DACOUT {				\
  HEADC;						\
    CVOPEN;						\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
  }							\
}
/// now with HEADC

#define DACOUTNOINT {				\
  HEADC;						\
    CVOPENNOINTERPOL;						\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
  }							\
}

void dac0(uint8_t w){
  gate[w].dactype=0; gate[w].dacpar=param[w];
  DACOUT;
}

void dac0noint(uint8_t w){
  gate[w].dactype=0; gate[w].dacpar=param[w];
  DACOUTNOINT;
}

//trial 4 oct log here but messes up cv in
void SRX0(uint8_t w){ // basic route in XOR puls 
  HEAD;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void SRXC0(uint8_t w){ // basic route in XOR puls 
  HEADC;
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_; 
    ENDER;
  }
}


void SRX0sr(uint8_t w){ // basic route in XOR puls
  HEAD;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTESR_;
    BITN_AND_OUTV_; 
    ENDER;
  }
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

// dacdacmod0 without interpoll
void dacdacmod0noint(uint8_t w){
  HEAD;
  gate[w].dactype=0; gate[w].dacpar=param[w];
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeed[(gate[speedfrom[spdcount][w]].dac>>2)%cv];
  CVOPENDACNOINTERPOL;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //    BINROUTE_;
    bitn=osceqbits(CVL[w]>>8,w);
    BITN_AND_OUTV_;
    ENDER;
  }
}

void dac2(uint8_t w){ // one bit audio - set beta with param so fix now as: 2048
  gate[w].dactype=2; gate[w].dacpar=4096-CVL[w]; //     betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
  DACOUTX; // if we keep length same and use CVL
}

// is in experiment.h
/*
void newdac2(uint8_t w){ // one bit audio - run filter at full speed but output on speed
  HEAD;
  gate[w].dactype=2; gate[w].dacpar=4096-CVL[w]; //     betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
  val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger);
  if (w==2 || speedf_[w]!=LOWEST){
    CVOPEN;
    if (gate[w].last_time<gate[w].int_time)      {
      GSHIFT_;
      BINROUTE_;
      //      BITN_AND_OUTV_;
      BITN_AND_OUTNODAC2_; // no val business as we do that always
      ENDER;
    }
  }
}
*/

void SR5_feedback(uint8_t w){ // detached
  HEADSIN; // use CVL[w] for tail entry speed... // can also use as INTmode with speed as this speed...
  // tail trial1
  speedf_[8]=logspeed[CVL[w]>>2];
  uint8_t old=w;
  w=8;
  gate[w].dac = delay_buffer[w][1]; // no interpol so we have gate[8].dac as 5th tail
  gate[w].time_now += speedf_[w];
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // we want what would be/have been routed in // or alt routes or generator or... but how to select these - in strobe mode with 2 free CVs?
      tmp=binroute[count][old];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	  bitn^=bitrr;    
	}
	tmp=tmp>>1;
      }
    gate[w].shift_+=bitn;
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger);
    new_data(val,w);
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  // back to regular RSR - and we can have variation on this
  w=old;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void SR5_feedback_int(uint8_t w){ // detached
  HEADSIN; // use CVL[w] for tail entry speed... // can also use as INTmode with speed as this speed...
  // tail trial1
  uint8_t old;
  speedf_[8]=logspeed[CV[w]>>2];
  old=w;
  w=8;
  //  gate[w].dac = delay_buffer[w][1]; // no interpol so we have gate[8].dac as 5th tail
  gate[w].time_now += speedf_[w];
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // we want what would be/have been routed in // or alt routes or generator or... but how to select these - in strobe mode with 2 free CVs?
    tmp=binroute[count][4]; // regular route 4
    BINROUTEstrip_;
    gate[w].shift_+=bitn;
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  // back to regular RSR - and we can have variation on this
  w=old; // fixed17/5
  bitn=0;
  if (gate[w].trigger){ 
    GSHIFT_;
    //    BINROUTE_;
    tmp=CVL[w]>>8; // 4 bits
    if (tmp==0) tmp=w;
    BINROUTEstrip_;
    BITN_AND_OUTVINT_; // changed  
    ENDER;
  }
}

void SR5_feedback_intother(uint8_t w){ // detached - other way round so tail is conventional route
  HEADSIN; // use CVL[w] for tail entry speed... // can also use as INTmode with speed as this speed...
  // tail trial1
  uint8_t old;
  speedf_[8]=logspeed[CV[w]>>2];
  old=w;
  w=8;
  //  gate[w].dac = delay_buffer[w][1]; // no interpol so we have gate[8].dac as 5th tail
  gate[w].time_now += speedf_[w];
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // we want what would be/have been routed in // or alt routes or generator or... but how to select these - in strobe mode with 2 free CVs?
    tmp=CVL[w]>>8; // 4 bits
    if (tmp==0) tmp=w;
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	  bitn^=bitrr;    
	}
	tmp=tmp>>1;
      }
    gate[w].shift_+=bitn;
    //    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); // do we need that dac though
    //    new_data(val,w);
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  // back to regular RSR - and we can have variation on this
  w=old; // fixed17/5
  bitn=0;
  if (gate[w].trigger){ 
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; // changed  
    ENDER;
  }
}

void SRnone(uint8_t w){  // empty
}

void SRdac2only(uint8_t w){  // for tests
  gate[w].dac=DAC_(w, gate[w].shift_, SRlength[w], 2, CVL[w], gate[w].trigger);
}

// new


void adcLseladc0(uint8_t w){ //
  // DETACH LENGTH
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc1(uint8_t w){ //
  // DETACH LENGTH
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTEalt_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc2(uint8_t w){ //
  // DETACH LENGTH
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTEZERO_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc3(uint8_t w){ //
  // DETACH LENGTH
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTENOG_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc4(uint8_t w){ //
  // DETACH LENGTH
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTESR_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc5(uint8_t w){ //
  // DETACH LENGTH
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTESHARE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc6(uint8_t w){ //
  // DETACH LENGTH
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  //  NONE;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// adcLseladc0, adcLseladc1, adcLseladc2, adcLseladc3, adcLseladc4, adcLseladc5, adcLseladc6,
