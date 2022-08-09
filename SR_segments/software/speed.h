void Ndacoffset0(void){
  uint8_t w=0;
  float speedf__;
  float mmm=(float)(1024-(CVL[0]>>2))/1024.0f;
  HEADSINN;
  tmp=(1024-(CV[0]>>2)) + (int)((float)(gate[dacfrom[daccount][0]].dac>>2)*mmm);
  if (tmp>1023) tmp=1023;
  speedf__=logspeed[tmp]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}


void Rdacadditself0(void){ // tested//trial itself as DAC - can also be other variants TODO
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[3].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacghostitself0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+((gate[3].Gshift_[routeto[count][3]])&511)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacghostincoming0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+((gate[3].Gshift_[inroute[count][3]])&511)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacseladd0(void){
  HEADR;
  uint8_t w=3;
  float speedf__;
  uint8_t whic=(CV[3]>>9)&3; //12 bits -> 2 bits
  speedf__=logspeed[(CV[3]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacadd0(void){
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[dacfrom[daccount][3]].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacminus0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[daccount][3]].dac>>2)-(1024-(CV[3]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacspeedminus0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)-(gate[dacfrom[daccount][3]].dac>>2); 
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacmod0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=((CV[3]>>2)+1); // modulo code
  speedf__=logspeed[(gate[dacfrom[daccount][3]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void RB0(void){// with oscillator
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)-(gate[dacfrom[daccount][3]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],30,gate[w].trigger,dacfrom[daccount][1],gate[w].adcpar, &gate[w].shift_); // oscillator
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}
