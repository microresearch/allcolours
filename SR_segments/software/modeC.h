// lowest modes as functions.... DAC output

/*
Characters: 

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


void Cnofrac0(void){
  gate[2].dactype=0; gate[2].dacpar=param[0];
  uint8_t w=2;
  HEAD;
  if (counter[2]>speed[2] && speed[2]!=1024){
    counter[2]=0;				
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  }
}

void C0(void){
  gate[2].dactype=0; gate[2].dacpar=param[0];
  DACOUT;
}

void C1(void){
  gate[2].dactype=1; gate[2].dacpar=param[0];
  DACOUT;
}

void C2(void){ // one bit audio - set beta with param so fix now as: 2048
  gate[2].dactype=2; gate[2].dacpar=2048;
  DACOUT;
}
