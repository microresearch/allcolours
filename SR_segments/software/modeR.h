// right hand functions

/*

CVmodes: basics, prob modes entry/loopback, esoteric modes, << bumps, route from DAC, prob from DAC

DACmodes: basics, esoterics

INTmodes: route from CV, prob from CV, others? + change global routes, fake clks, use as DAC, enry of non-adc bits from

above, different kinds of DAC out

*/


void Rnofrac0(void){
  uint8_t w=3;
  HEAD;
  if (counter[3]>speed[3] && speed[3]!=1024){
    counter[3]=0;			       
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  }
}


void R0(void){ // basic route in
  uint8_t w=3;
  HEAD;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void R1(void){ // route and cycle
  uint8_t w=3;
  HEAD;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    BINROUTEANDCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

