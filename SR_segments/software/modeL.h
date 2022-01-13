// left hand functions

/*

CVmodes: basics, prob modes entry/loopback, esoteric modes, << bumps, route from DAC, prob from DAC, what else?

DACmodes: basics, esoterics

INTmodes: route from CV, prob from CV, others?

*/


void Lnofrac0(void){
  uint8_t w=1;
  HEAD;
  if (counter[1]>speed[1] && speed[1]!=1024){
    counter[1]=0;				
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
    }
}

void Lno(void){
}

void L0(void){ // basic route in
  uint8_t w=1;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void L1(void){ // route and cycle
  uint8_t w=1;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTEANDCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void L2(void){ // test double/bump speed/sr on trigger
  uint8_t w=1;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    if (gate[w].trigger) {
      BINROUTE_;
    }
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// test - speedCV-speedDAC 
void Ldac0(void){
  uint8_t w=1;
  float speedf__;
  if (speedf_[1]==2.0f) speedf_[1]=0.000990f;
    speedf__= (speedf_[1]-logspeed[1024-(gate[speedfrom_[1]].dac>>2)]);
//  speedf__= logspeed[1024-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[1];
  //  if (speedf__>1.0f) speedf__=1.0f;
  if (speedf__<0.0000990f) speedf__=0.0000990f;
  //  speedf__=1.0f;
  HEAD;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}
