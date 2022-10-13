
void dacNLRinlogic(uint8_t w){  // figure out bits for logic - also as possible strobe mode // logic can also be dac

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

void dacLRprob(uint8_t w){


  if (((LFSR_[w] & 4095 ) < CVL[w])) x=1;
  else x=3;

  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;

  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_; // with pulses

void dacLRprobxorN(uint8_t w){  // and XOR N in now...


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

void dacNLRprobin(uint8_t w){  // this one is just fixed XOR

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

void dacNLRprobin1311(uint8_t w){  // this one is just fixed XOR

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

void dacLNLRin(uint8_t w){  // this one is just fixed XOR - detach length to pick our DAC

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

void dacadc(uint8_t w){

  bitn=ADC_(w,SRlength[w],85,gate[w].trigger,dacfrom[daccount][w],CVL[w], &gate[w].shift_); // 85 so 1 bit from comparator
  BITN_AND_OUTV_; // pulses outs - was VN no pulses???

void dacosc0(uint8_t w){ // test oscillator

    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    BITN_AND_OUTV_;

void dacLLswop(uint8_t w){ // swop in or logop SR - cv and cvl ***

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

void dacN(uint8_t w){

    // INSERT!
    
    BITN_AND_OUTV_;

void dacLBURST0(uint8_t w){

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

void dacL16slide(uint8_t w){   // DETACH SPEED

  BINROUTE_;
  BITN_AND_OUTV_;

void dacLrung0(uint8_t w){ // detached length

  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  //  tmp=myroute[w][gate[w].route]; // route from N, L, or R = 3 options +itself = 0,1,2,3
  tmp=tmp&0x03; // 2 bits
  bitrr = (gate[tmp].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[tmp].Gshift_[w]=(gate[tmp].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;

  BITN_AND_OUTV_; // with pulses

void dacN17_0(uint8_t w){

    // INSERT!
    BINROUTE_;
    if (gate[w].trigger)	  bitrr=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
    else bitrr=!((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
    bitn=bitn|bitrr;
    BITN_AND_OUTV_;

void dacN18_0(uint8_t w){

    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]){
      BINROUTEANDCYCLE_;
    }
    else {
      bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }	    
    BITN_AND_OUTV_;

void dacLDACSEL0(uint8_t w){ // detached

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

void dacbumproute0(uint8_t w){ // trigger bumps up our local route - add one to this (what value) - gate[0].route

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

void dacDACroute0(uint8_t w){

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

void dacSRroute0(uint8_t w){

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

void dac32(uint8_t w){ // multiple bits in as case 19 in draftdec

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

void dacdacadditself0(uint8_t w){ // tested//trial itself as DAC - can also be other variants TODO

    BINROUTE_;
    BITN_AND_OUTV_;

void dacdacghostitself0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;

void dacdacghostincoming0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;

void dacdacseladd0(uint8_t w){

    BINROUTE_;
    BITN_AND_OUTV_;

void dacdacadd0(uint8_t w){

    BINROUTE_;
    BITN_AND_OUTV_;

void dacdacminus0(uint8_t w){

    BINROUTE_;
    BITN_AND_OUTV_;

void dacdacspeedminus0(uint8_t w){

    BINROUTE_;
    BITN_AND_OUTV_;

void dacdacmod0(uint8_t w){

    BINROUTE_;
    BITN_AND_OUTV_;

void dacB0(uint8_t w){// with oscillator

    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][1],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;

void dacdacoffset0(uint8_t w){

    BINROUTE_;
    BITN_AND_OUTV_;

  
