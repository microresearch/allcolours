// left hand functions

/*

CVmodes: basics, prob modes entry/loopback, esoteric modes, << bumps, route from DAC, prob from DAC, what else?

DACmodes: basics, esoterics

INTmodes: route from CV, prob from CV, others?

- how we work with length param as it doesn't change so much?

*/

// TODO: check we have     PULSIN_XOR;!!!!!!!!!!!!!!1


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
    PULSIN_OR;
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

void Lmod(void){ // modulo route in 
  uint8_t w=1;
  HEAD;
  if (speedf_[1]!=2.0f){ 
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {
    GSHIFT_;
    //    BINROUTE_;
    if (!strobey[1][mode[1]]) bitn|=gate[1].trigger;  
    // we modulo our SR with routed ins
  tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;    
  gate[w].shift_=gate[w].shift_%gate[x].Gshift_[w];
  }
  tmp=tmp>>1;
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
  speedf__= (speedf_[1]-logspeed[1024-(gate[dacfrom[count][1]].dac>>2)]); // dacfrom
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
