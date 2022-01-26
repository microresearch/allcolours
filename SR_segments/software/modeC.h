// lowest modes as functions.... DAC output

/*

arrange also a bit better in adcetc with order and strobes in

CVmodes: 16xDAC could be reduced, followed by 4x4 DAC modes below, XOR/OR in to test, speeds << >>

DACmodes: 16 - 4x4 as above or???

INTmodes: 16 - CV as param

other ideas: other dac outs, mix of dac outs, add dacs, modulo

*/



// TODO: we need to focus on what length does and cut down number of DAC modes...
// in draftdec.c 16DAC followed by
// 4x4 DAC modes
  /*
1-cycle and route 16 below
2-2x strobe=prob from below
3
4-4 bit shuffle
  
00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ??
01 2-BITIN or loopback
   [10 3-INV of above]
11 4- BITIN or not into cycling

what are the next 16x LR modes
  */

// other possibles: bigger shifts in, speed bumps


#define DACOUT {				\
  uint8_t w=2;					\
  float alpha;								\
  uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat;	\
  if (speedf_[2]!=2.0f){						\
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
  float alpha;								\
  uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat;	\
  if (speedf_[2]!=2.0f){						\
    CVOPEN;						\
    if (gate[2].last_time<gate[2].int_time)      {	\
      GSHIFT_;						\
      BINROUTENOG_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}


// run through DAC modes with correct params set if necessary

void Cosc0(void){ // test oscillator
  uint8_t w=2;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(2,SRlength[w],30,gate[w].trigger,dacfrom[count][2],gate[w].adcpar, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// template for newmodes 
void CN(void){ 
  uint8_t w=2;
  gate[2].dactype=0; gate[2].dacpar=param[2];
  HEAD;
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

void CN17_0(void){ 
  uint8_t w=2;
  gate[2].dactype=0; gate[2].dacpar=param[2];
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    if (gate[w].trigger)	  bitrr=(gate[w].shift_>>SRlength[w]) & 0x01;
    else bitrr=!((gate[w].shift_>>SRlength[w]) & 0x01); 
    bitn|=bitrr;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void CN18_0(void){ 
  uint8_t w=2; static uint8_t tug[4]={0};
  gate[2].dactype=0; gate[2].dacpar=param[2];
  HEAD;
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
      bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
    }	    
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void C0(void){
  gate[2].dactype=0; gate[2].dacpar=param[2];
  DACOUT;
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
  gate[2].dactype=2; gate[2].dacpar=2048;
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

void C67(void){ // stock 4 bit DAC
  gate[2].dactype=67; gate[2].dacpar=4095-(param[2]&4095);
  DACOUT;
}

void C66(void){ // default basic dac
  gate[2].dactype=66; gate[2].dacpar=4095-(param[2]&4095);
  DACOUT;
}




// TODO: just bump within a restricted range or array which make sense?
void Cbumproute0(void){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  uint8_t w=2;
  HEADN;
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
  HEADN;
  if (speedf_[2]!=2.0f){
  CVOPEN;
  if(gate[2].last_time<gate[2].int_time)      {
  GSHIFT_;
  if (!strobey[2][mode[2]]) bitn|=gate[2].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[count][2]].dac&15;
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

void C32(void){ // multiple bits in as case 19 in draftdec
  uint8_t w=2;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    gate[w].shift_&=spacmask[SRlength[w]]; //cleared
    if (SRlength[defroute[w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
    }
    bitn=gate[w].shift_&1; // fixed this 29/12/2021
    if (!strobey[2][mode[2]]) bitn|=gate[2].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }    
  }
}


///////////////////////////////////////////////////////////////////////////
// CV+DAC speed modes TODO:

// INTmodes

void Cint0(void){ // INTmode 0 no interpolation and no use of CV
  uint8_t w=2;				       
  gate[2].dactype=0; gate[2].dacpar=param[2];
  HEAD;  
  if (gate[2].trigger)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; // we have pulse out
  } 
}

void Cintroute0(void){ // CV: 4 bits for route in... other bits for logop
  uint8_t w=2;				       
  HEADN;  
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
  HEAD;
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
