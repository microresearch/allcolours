// lowest modes as functions.... DAC output

/*

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
  uint32_t bitn, bitrr, tmp, val, x, xx, lengthbit=15, new_stat;	\
  if (speedf_[w]!=2.0f){						\
    CVOPEN;						\
    if (gate[w].last_time<gate[w].int_time)      {	\
      GSHIFT_;						\
      BINROUTE_;					\
      BITN_AND_OUTV_;					\
      ENDER;						\
    }							\
  }							\
}

// run through DAC modes with correct params set if necessary

void C0(void){
  gate[2].dactype=0; gate[2].dacpar=param[2];
  DACOUT;
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
