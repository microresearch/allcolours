
#define DACOUT {				\
  uint8_t w=2;					\
  HEADC;						\
  if (speedf_[2]!=2.0f){				\
    CVOPEN;						\
    if (gate[2].last_time<gate[2].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}

#define DACOUTNOV {				\
  uint8_t w=2;					\
  HEADC;						\
  if (speedf_[2]!=2.0f){				\
    CVOPENNOINTERPOL;					\
    if (gate[2].last_time<gate[2].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;				\
      ENDER;						\
    }							\
  }							\
}


#define DACOUTGGG {				\
  uint8_t w=2;					\
  HEADC;						\
  if (speedf_[2]!=2.0f){				\
    CVOPEN;						\
    if (gate[2].last_time<gate[2].int_time)      {	\
      GSHIFT_;						\
      BINROUTENOGGG_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}


#define DACOUTX {				\
  uint8_t w=2;					\
  HEADSINC;						\
  if (speedf_[2]!=2.0f){				\
    CVOPEN;						\
    if (gate[2].last_time<gate[2].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}


// no << in gshift
#define DACOUTNOG {				\
  uint8_t w=2;					\
  HEADC;						\
  if (speedf_[2]!=2.0f){				\
    CVOPEN;						\
    if (gate[2].last_time<gate[2].int_time)      {	\
      GSHIFT_;						\
      BINROUTENOG_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}


// test adc in and dac out in one
void Cadc(void){
  uint8_t w=2;
  HEADC;				
  gate[2].dactype=0; gate[2].dacpar=param[2];
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[2].last_time<gate[2].int_time)      {
  GSHIFT_;				
  bitn=ADC_(2,SRlength[2],85,gate[2].trigger,dacfrom[daccount][2],param[2], &gate[2].shift_); // 85 so 1 bit from comparator
  BITN_AND_OUTV_; // pulses outs - was VN no pulses???
  ENDER;
  }
  }
}

// run through DAC modes with correct params set if necessary

void Cosc0(void){ // test oscillator
  uint8_t w=2;
  HEADC;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(2,SRlength[w],30,gate[w].trigger,dacfrom[daccount][2],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void CLLswop(void){ // swop in or logop SR - cv and cvl ***
  uint8_t w=2; uint32_t lin, lout;
  HEADSSINNADA;
    gate[2].dactype=0; gate[2].dacpar=param[2];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_; 
    if (gate[w].trigger) {
      lin=127-(CV[2]>>5); //7= 2 bits for whichone and start which can be 5
      lout=31-(CVL[2]>>7); // 5 bits for length
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
void CN(void){ 
  uint8_t w=2;
  gate[2].dactype=0; gate[2].dacpar=param[2];
  HEADC;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void CLBURST0(void){ 
  // DETACH LENGTH
  uint8_t w=2;
  HEADSINC;
  gate[2].dactype=0; gate[2].dacpar=param[2];

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[2].last_time<gate[2].int_time)      {
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
void CL16slide(void){   // DETACH SPEED
  uint8_t w=2;
  gate[2].dactype=16; gate[2].dacpar=CV[2]>>7;
 HEADSSINC
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[2].last_time<gate[2].int_time)      {
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
void CLrung0(void){ // detached length
  uint8_t w=2;
  HEADSINC;
  tmp=CVL[2]>>6;// 2 bits for route, 4 bits for DACtype = 6 bits
  gate[2].dactype=tmp>>2; gate[2].dacpar=param[2];
  if (speedf_[2]!=2.0f){
  CVOPEN;
  if(gate[2].last_time<gate[2].int_time)      {
  GSHIFT_;
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  //  tmp=myroute[2][gate[2].route]; // route from N, L, or R = 3 options +itself = 0,1,2,3
  tmp=tmp&0x03; // 2 bits
  bitrr = (gate[tmp].Gshift_[2]>>SRlength[x]) & 0x01;
  gate[tmp].Gshift_[2]=(gate[tmp].Gshift_[2]<<1)+bitrr;
  bitn^=bitrr;

  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void CN17_0(void){ 
  uint8_t w=2;
  gate[2].dactype=0; gate[2].dacpar=param[2];
  HEADC;
  if (speedf_[w]!=2.0f){ 
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

void CN18_0(void){ 
  uint8_t w=2; static uint8_t tug[4]={0};
  gate[2].dactype=0; gate[2].dacpar=param[2];
  HEADC;
  if (speedf_[w]!=2.0f){ 
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


void CLDACSEL0(void){ // detached
  uint8_t w=2;
  uint8_t mmm=CVL[2]>>8; // to 4 bits
  gate[2].dactype=mmm; gate[2].dacpar=param[2];
  DACOUTX;
}

void CL12(void){ // detached - interval DAC
  HEADSINC;
  uint8_t w=2;
  gate[2].dactype=12; gate[2].dacpar=31-(CVL[2]>>7);
  DACOUTX;
  //      GSHIFT_;					       
  //      BINROUTE_;				       
  //      BITN_AND_OUTVINT_;				   
}


void CLDACSRSEL0(void){
  uint8_t w=2;
  uint8_t mmm=CVL[2]>>8; // to 4 bits
  gate[2].dactype=(mmm)&(DACFROM&15);
  gate[2].dacpar=param[2]; // other logical opps
  DACOUTX;
}


void C0(void){
  gate[2].dactype=0; gate[2].dacpar=param[2];
  DACOUT;
}

void Cnov0(void){
  gate[2].dactype=0; gate[2].dacpar=param[2];
  DACOUTNOV;
}


void C0nog(void){
  gate[2].dactype=0; gate[2].dacpar=param[2];
  DACOUTNOG;
}

void C1(void){
  gate[2].dactype=1; gate[2].dacpar=param[2];
  DACOUT;
}

void C2(void){ // one bit audio - set beta with param so fix now as: 2048
  // dependent on speed
  gate[2].dactype=2; gate[2].dacpar=4096-CVL[2]; //     betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
  DACOUT;
}

void C3(void){
  gate[2].dactype=3; gate[2].dacpar=param[2];
  DACOUT;
}

void C4(void){
  gate[2].dactype=4; gate[2].dacpar=param[2];
  DACOUT;
}

void C5(void){
  gate[2].dactype=5; gate[2].dacpar=param[2];
  DACOUT;
}

void C6(void){
  gate[2].dactype=6; gate[2].dacpar=param[2];
  DACOUT;
}

void C7(void){
  gate[2].dactype=7; gate[2].dacpar=param[2];
  DACOUT;
}

void C8(void){
  gate[2].dactype=8; gate[2].dacpar=param[2];
  DACOUT;
}

void C9(void){
  gate[2].dactype=9; gate[2].dacpar=param[2];
  DACOUT;
}

void C10(void){
  gate[2].dactype=10; gate[2].dacpar=param[2];
  DACOUT;
}

void C11(void){
  gate[2].dactype=11; gate[2].dacpar=param[2];
  DACOUT;
}

void C12(void){
  gate[2].dactype=12; gate[2].dacpar=param[2];
  DACOUT;
}

void C13(void){
  gate[2].dactype=13; gate[2].dacpar=param[2];
  DACOUT;
}

void C14(void){
  gate[2].dactype=14; gate[2].dacpar=param[2];
  DACOUT;
}

void C15(void){ // one bit audio with param as filter
  gate[2].dactype=2; gate[2].dacpar=4095-(param[2]&4095);
  DACOUT;
}

void Creal15(void){ 
  gate[2].dactype=15; gate[2].dacpar=4095-(param[2]&4095);
  DACOUT;
}


void C17(void){ // 12 bits audio from 2s complement
  gate[2].dactype=17; gate[2].dacpar=4095-(param[2]&4095);
  DACOUT;
}

void C18(void){ // 12 bits audio from 2s complement
  gate[2].dactype=18; gate[2].dacpar=4095-(param[2]&4095);
  DACOUT;
}

void C19(void){ // x bits audio from 2s complement
  gate[2].dactype=19; gate[2].dacpar=4095-(param[2]&4095);
  DACOUT;
}



void C67_4bits(void){ // stock 4 bit DAC - nothing to do with length!!!! TODO: use length PARAM as....
  gate[2].dactype=67; gate[2].dacpar=param[2];
  DACOUT;
}

void C67_4bitsNOGG(void){ // stock 4 bit DAC - nothing to do with length!!!! TODO: use length PARAM as....
  gate[2].dactype=67; gate[2].dacpar=param[2];
  DACOUTGGG;
}


void C66(void){ // default basic 4 bit dac
  gate[2].dactype=66; gate[2].dacpar=param[2];
  DACOUT;
}

void C68(void){ // default basic 4 bit dac with no timing
  gate[2].dactype=68; gate[2].dacpar=param[2];
  DACOUT;
}



void Ctest(void){ // for speed 1hz to 20hz triangle here...
  // but why do we lose it ????
  uint8_t w=2;
  static uint32_t togg=0;
  HEADC;
  gate[2].dactype=0; gate[2].dacpar=param[2];
  CVOPEN;
  if (gate[2].last_time<gate[2].int_time)      {
    GSHIFT_;
    togg^=1;
    bitn=togg;
    BITN_AND_OUTV_; // with pulses
    ENDER;
  }
  }  

// TODO: just bump within a restricted range or array which make sense?
void Cbumproute0(void){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  uint8_t w=2;
  HEADC;
  gate[2].dactype=0; gate[2].dacpar=param[2];
  if (speedf_[2]!=2.0f){
  CVOPEN;
  if(gate[2].last_time<gate[2].int_time)      {
  GSHIFT_;
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  if (gate[2].trigger) gate[2].route++;
  if (gate[2].route>15) gate[2].route=0;
  tmp=myroute[2][gate[2].route];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[2]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[2]=(gate[x].Gshift_[2]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void CDACroute0(void){ 
  uint8_t w=2;
  HEADC;
  if (speedf_[2]!=2.0f){
  CVOPEN;
  if(gate[2].last_time<gate[2].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][2]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[2]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[2]=(gate[x].Gshift_[2]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
 if (!strobey[2][mode[2]]) bitn=bitn|gate[2].trigger;
   BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void CSRroute0(void){ 
  uint8_t w=2;
  HEADC;
  if (speedf_[2]!=2.0f){
  CVOPEN;
  if(gate[2].last_time<gate[2].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][2]].Gshift_[2]&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[2]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[2]=(gate[x].Gshift_[2]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  if (!strobey[2][mode[2]]) bitn=bitn|gate[2].trigger;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void C32(void){ // multiple bits in as case 19 in draftdec
  uint8_t w=2;
  HEADC;
  if (speedf_[w]!=2.0f){ 
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
    if (!strobey[2][mode[2]]) bitn=bitn|gate[2].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }    
  }
}


///////////////////////////////////////////////////////////////////////////
// CV+DAC speed modes TODO:

void Cdacadditself0(void){ // tested//trial itself as DAC - can also be other variants TODO
  HEADC;
  uint8_t w=2;
  float speedf__;
  speedf__=logspeed[(CV[2]&511)+(gate[2].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Cdacghostitself0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADC;
  uint8_t w=2;
  float speedf__;
  speedf__=logspeed[(CV[2]&511)+((gate[2].Gshift_[routeto[count][2]])&511)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Cdacghostincoming0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADC;
  uint8_t w=2;
  float speedf__;
  speedf__=logspeed[(CV[2]&511)+((gate[2].Gshift_[inroute[count][2]])&511)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Cdacseladd0(void){
  HEADC;
  uint8_t w=2;
  float speedf__;
  uint8_t whic=(CV[2]>>9)&3; //12 bits -> 2 bits
  speedf__=logspeed[(CV[2]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Cdacadd0(void){
  HEADC;
  uint8_t w=2;
  float speedf__;
  speedf__=logspeed[(CV[2]&511)+(gate[dacfrom[daccount][2]].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Cdacminus0(void){
  HEADC;
  uint8_t w=2;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[daccount][2]].dac>>2)-(1024-(CV[2]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Cdacspeedminus0(void){
  HEADC;
  uint8_t w=2;
  int32_t cv;
  float speedf__;
  cv=(CV[2]>>2)-(gate[dacfrom[daccount][2]].dac>>2); 
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Cdacmod0(void){
  HEADC;
  uint8_t w=2;
  int32_t cv;
  float speedf__;
  cv=((CV[2]>>2)+1); // modulo code
  speedf__=logspeed[(gate[dacfrom[daccount][2]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void CB0(void){// with oscillator
  HEADC;
  uint8_t w=2;
  int32_t cv;
  float speedf__;
  cv=(CV[2]>>2)-(gate[dacfrom[daccount][2]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],30,gate[w].trigger,dacfrom[daccount][1],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Cdacoffset0(void){
  uint8_t w=2;
  float speedf__;
  float mmm=(float)(1024-(CVL[2]>>2))/1024.0f;
  HEADSSINNADA;
  tmp=(1024-(CV[2]>>2)) + (int)((float)(gate[dacfrom[daccount][2]].dac>>2)*mmm);
  if (tmp>1023) tmp=1023;
  speedf__=logspeed[tmp]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// INTmodes

void Cint0(void){ // INTmode 0 no interpolation and no use of CV
  uint8_t w=2;				       
  gate[2].dactype=0; gate[2].dacpar=param[2];
  HEADC;  
  if (gate[2].trigger)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; // we have pulse out
  } 
}

void Cint12(void){ // INTmode - 
  uint8_t w=2;				       
  HEADSSINNADA;
  // trial length down to 0  
  SRlength[2]=31-(CVL[2]>>7);
  gate[2].dactype=12; gate[2].dacpar=31-(CV[2]>>7);
  if (gate[2].trigger)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; // we have pulse out
  } 
}


void Cintslide16(void){ // window // speed is param// we need length so no detach
  uint8_t w=2;				       
  gate[2].dactype=16; gate[2].dacpar=CV[2]>>7; // 5 bits
  HEADSSINC;  
  if (gate[2].trigger)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; // we have pulse out
  } 
}

void Cintroute0(void){ // CV: 4 bits for route in... other bits for logop
  uint8_t w=2;				       
  HEADC;  
  if (gate[2].trigger)      {
    GSHIFT_;
    tmp=255-(CV[2]>>4); // 8 bits
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
// list of these: 0,1,2(gate[2].dacpar=2048;),3,6,7,8,11,15 = 9 mode - maybe reduce to 8 and have other bits for route
// so is 3 bits for choice and 4 for route = 7 bits total = 128
void CintselDAC_63(void){ 
  uint8_t choice[8]={0,1,2,3, 6,7,11,15};
  gate[2].dacpar=2048;
  uint8_t w=2;				       
  HEADC;
  if (gate[2].trigger)      {
    val=127-(CV[2]>>5); // 7 bits say
    GSHIFT_;
    tmp=(val>>4); // 3 bits
    gate[2].dactype=choice[tmp];
    tmp=(val&15);// lowest 4 bits for routing
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[2]>>SRlength[x]) & 0x01;
	gate[x].Gshift_[2]=(gate[x].Gshift_[2]<<1)+bitrr;
	bitn^=bitrr;
  }
      tmp=tmp>>1;
    }			     
    BITN_AND_OUTVINT_; // pulse out
  } 
}

void CLNint104(void){ // let's try INT driven one for pulse train mode
  // INT triggers train of CV pulses at speed DAC - and can also be vice versa
  // INT can also start new train or let old one carry on (now it starts new train...)
  uint8_t w=2;
  HEADC;  
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

  void CLNint105(void){ // let's try INT driven one for pulse train mode
  // INT triggers train of CV pulses at speed DAC - and can also be vice versa
  // INT can also start new train or let old one carry on (now it starts new train...)
  uint8_t w=2;
  HEADC;  
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
