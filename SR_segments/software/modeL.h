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

void Losc0(void){ // basic route in with oscillator
  uint8_t w=1;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],30,gate[w].trigger,dacfrom[count][1],gate[w].adcpar, &gate[w].shift_); // oscillator
    BINROUTE_;
    PULSIN_OR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


void Lmod(void){ // modulo route in SR
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

// TODO: just bump within a restricted range or array which make sense?
void Lbumproute0(void){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  uint8_t w=1;
  HEADN;
  if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {
  GSHIFT_;
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  if (gate[1].trigger) gate[1].route++;
  if (gate[1].route>15) gate[1].route=0;
  tmp=myroute[1][gate[1].route];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[1]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[1]=(gate[x].Gshift_[1]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void LDACroute0(void){ 
  uint8_t w=1;
  HEADN;
  if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {
  GSHIFT_;
  if (!strobey[1][mode[1]]) bitn|=gate[1].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[count][1]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[1]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[1]=(gate[x].Gshift_[1]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_; // with pulses
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

// intmodes

// prototype INTmode 0 no interpolation and no use of CV - cycles though
void Lint0(void){ 
  uint8_t w=1;
  HEAD;  
  count=0;
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTEANDCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}


void Lintroute0(void){ // CV: 4 bits for route in... other bits for logop
  uint8_t w=1;				       
  HEADN;  
  if (gate[1].trigger)      {
    GSHIFT_;
    tmp=255-(CV[1]>>4); // 8 bits
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

void LintselADC_63(void){ // use CV to select adc type: only those which don't use CV or strobe LIST:
  // we could also us top bits to do something with? 16 modes=4 bits, top bits logop/route?
  //0,1,2,3,4,5,6,7,8 - adc logical-22,23,25,26,27,30,63,64,65 to test - 27 dies out but...
  uint8_t choice[16]={0,1,2,3,4,5,6,7,8, 22, 23, 25, 26, 27, 30, 63};//leave off -inprogress 63,64,65 to test - TODO: expand this with new abstract and dac modes...
    // DAC inputs 25,26,27,71,72,73,74
  uint8_t w=1;				       
  HEADN;  
  if (gate[1].trigger)      {
    val=63-(CV[1]>>6); // 6 bits say
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],choice[val>>2],gate[w].trigger,dacfrom[count][1],gate[w].adcpar, &gate[w].shift_);
    val=(val&0x03);// lowest 2 bits for logop
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn=logop(bitn,bitrr,val);
  }
  tmp=tmp>>1;
    }			     
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
