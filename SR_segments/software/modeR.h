void RLLswop(void){ // swop in or logop SR - cv and cvl ***
  uint8_t w=3; uint32_t lin, lout;
  HEADSSINNADA;

  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    if (gate[w].trigger) {
      lin=127-(CV[3]>>5); //7= 2 bits for whichone and start which can be 5
      lout=31-(CVL[3]>>7); // 5 bits for length
      // length of incoming - lout
      tmp=gate[lin&0x03].shift_>>(31-lout);
      gate[w].shift_^=(tmp<<(31-(lin>>2)));
      //gate[w].shift_=gate[oppose[w]].shift_; // sieve is previous one but could be opposite one
    }
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


// basic route in prototype
void R0(void){ 
  uint8_t w=3;
  HEADR;
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

// no << gshift
void R0nog(void){ 
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    BINROUTENOG_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Rnoggg(void){ // we don't add back in result of gshift TEST
  uint8_t w=3; 
  HEADR;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTENOGGG_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


void Rnada(void){ 
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    bitn=0;
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void R1(void){ // route and cycle
  uint8_t w=3;
  HEADR;
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

void Rmod(void){ // modulo route in 
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    //    BINROUTE_;
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
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Rosc0(void){ // basic route in with oscillator
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(3,SRlength[w],30,gate[w].trigger,dacfrom[daccount][3],0, &gate[w].shift_); // oscillator
    //    BINROUTE_; //
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


void Raccelghosts0(void){ // route in // exp mode to accelerate/bump on all ghosts except own - could also select which ones for intmode
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    // bump up ALL except own gshifts or can be others missing eg. except for 0
    for (x=0;x<4;x++){     
      bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;  // gshifts FOR 0 including our own
      gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    }
    for (x=0;x<4;x++){     
      bitrr = (gate[x].Gshift_[1]>>SRlength[x]) & 0x01;  
      gate[x].Gshift_[1]=(gate[x].Gshift_[1]<<1)+bitrr;
    }
    for (x=0;x<4;x++){     
      bitrr = (gate[x].Gshift_[2]>>SRlength[x]) & 0x01;  
      gate[x].Gshift_[2]=(gate[x].Gshift_[2]<<1)+bitrr;
    }
        
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// for CV modes add in bump up global routes, SR as global routing table

void Rglobalbump0(void){ // bump dacroute and binroute 
  uint8_t w=3;
  HEADRN;

  if (gate[3].trigger) // outside speed?
    {
      count++;
      if (count>15) count=0; // we have 16 so far, but can add more
      daccount=count;
    }
    
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

void Rglobaldac0(void){ // dac as global route table or could be SR as route bits but we need to fix that
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){ 
    CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    count=(gate[3].dac)>>8; // 4 bits now    from ITSELF
    daccount=(gate[3].dac>>4)&15;
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// TODO: just bump within a restricted range or array which make sense?
// locals
void Rbumproute0(void){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
  GSHIFT_;
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  if (gate[3].trigger) gate[3].route++;
  if (gate[3].route>15) gate[3].route=0;
  tmp=myroute[3][gate[3].route];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[3]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[3]=(gate[x].Gshift_[3]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }
  PULSIN_XOR;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void RDACroute0(void){ 
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
  GSHIFT_;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][3]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[3]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[3]=(gate[x].Gshift_[3]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }
  PULSIN_XOR;
  if (!strobey[3][mode[3]]) bitn=bitn|gate[3].trigger;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void RSRroute0(void){ 
  uint8_t w=3;
  HEADR;
  if (speedf_[3]!=2.0f){
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
  GSHIFT_;
  if (!strobey[3][mode[3]]) bitn=bitn|gate[3].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][3]].Gshift_[3]&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[3]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[3]=(gate[x].Gshift_[3]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }
  PULSIN_XOR;
  if (!strobey[3][mode[3]]) bitn=bitn|gate[3].trigger;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}


void R32(void){ // multiple bits in as case 19 in draftdec
  uint8_t w=3;
  HEADR;
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
    if (!strobey[3][mode[3]]) bitn=bitn|gate[3].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }    
  }
}

///// thinking on bit modes

void RBITlengthdac(void){ 
  uint8_t w=3;
  uint32_t bits;
  HEADR;  
 if (speedf_[3]!=2.0f){
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {

    bits=SRFROM&255; // length is 5 bits, dactype can be from 3 to 5 bits
    SRlength[3]=lookuplenall[bits&31]; // 5 bits
    tmp=(bits>>5); // 3 bits
    GSHIFT_;

    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp
    ENDER;
  }
  } 
}

void RLBITlengthdac(void){ // detach length and just have dactype 
  uint8_t w=3;
  uint32_t bits;
  HEADSINR;  
 if (speedf_[3]!=2.0f){
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {

    bits=CVL[3]>>4; // 8 bits - length is 5 bits, dactype can be from 3 to 5 bits
    SRlength[3]=lookuplenall[bits&31]; // 5 bits
    tmp=(bits>>5); // 3 bits
    GSHIFT_;

    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp
    ENDER;
  }
  } 
}


/////////////////////////////////////////////////////////////////////////
// DACspeed modes?

void Rdacoffset0(void){
  uint8_t w=3;
  float speedf__;
  float mmm=(float)(1024-(CVL[3]>>2))/1024.0f;
  HEADSINR;
  tmp=(1024-(CV[3]>>2)) + (int)((float)(gate[speedfrom[spdcount][3]].dac>>2)*mmm);
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
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Rdacghostitself0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+((gate[3].Gshift_[1])&511)];
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

void Rdacseladd0(void){
  HEADR;
  uint8_t w=3;
  float speedf__;
  uint8_t whic=(CV[3]>>9)&3; //12 bits -> 2 bits
  //  if (speedf_[0]==2.0f) speedf_[0]=LOWEST;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[which].dac>>2)]);
  speedf__=logspeed[(CV[3]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit
//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  // if (speedf__<LOWEST) speedf__=LOWEST;
  //  speedf__=1.0f;
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

void Rdacadd0(void){
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[speedfrom[spdcount][3]].dac>>3)];
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

void Rdacmod(void){
  HEADR;
  uint8_t w=1;
  int32_t cv;
  float speedf__;
  cv=((CV[3]>>2)+1); // modulo code
  speedf__=logspeed[(gate[speedfrom[spdcount][3]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void RB0(void){// with oscillator
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(gate[speedfrom[spdcount][3]].dac>>2)-(1024-(CV[3]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(3,SRlength[w],30,gate[w].trigger,dacfrom[daccount][3],0, &gate[w].shift_); // oscillator
    //    BINROUTE_; // no route in now
    if (!strobey[3][mode[3]]) bitn=bitn|gate[3].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

//SRL, SRR: speed from SRN: (both run OSC with no binroute) - is as RB0 above
void Rrung0(void){// with oscillator
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(gate[0].dac>>2)-(1024-(CV[3]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(3,SRlength[w],30,gate[w].trigger,dacfrom[daccount][3],0, &gate[w].shift_); // oscillator
    //    BINROUTE_; // no route in now
    if (!strobey[3][mode[3]]) bitn=bitn|gate[3].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Rrung1(void){// with oscillator - other minus
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(gate[0].dac>>2)-(1024-(CV[3]>>2)); // other minus
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(3,SRlength[w],30,gate[w].trigger,dacfrom[daccount][3],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Rrung2(void){// with oscillator - mod
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=((CV[3]>>2)+1); // modulo code
  speedf__=logspeed[(gate[0].dac>>2)%cv]; // mod
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],30,gate[w].trigger,dacfrom[daccount][1],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Rrung3(void){// with oscillator - add
  HEADL;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[0].dac>>3)]; // add
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(3,SRlength[w],30,gate[w].trigger,dacfrom[daccount][3],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}


void RLrung0(void){// DETACHED> with oscillator
  HEADSINR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  //  cv=(CV[1]>>2)-(gate[0].dac>>2);
  //  if (cv<0) cv=0;
  // 2 bits speed ops...
  tmp=CVL[3]>>6; //2+4 bits = 6 bits
  // top bits
  if (tmp&16){
    cv=((CV[3]>>2)+1); // modulo code
    speedf__=logspeed[(gate[0].dac>>2)%cv]; // mod
  }
  else if (tmp&32){
  cv=(CV[3]>>2)-(gate[0].dac>>2);
  if (cv<0) cv=0;
  speedf__ = logspeed[cv]; // minus
  }
  else if (tmp&48){
  speedf__=logspeed[(CV[3]&511)+(gate[0].dac>>3)]; // add
  }
  else {
  cv=(gate[0].dac>>2)-(1024-(CV[3]>>2)); // other minus
  if (cv<0) cv=0;
  speedf__ = logspeed[cv]; 
  }

  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=tmp>>2;
    bitn=ADC_(3,SRlength[w],oscmode[tmp],gate[w].trigger,dacfrom[daccount][3],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}



void Rdacminus0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(gate[speedfrom[spdcount][3]].dac>>2)-(1024-(CV[3]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
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

void Rdacspeedminus0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)-(gate[speedfrom[spdcount][3]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
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

void Rdacmod0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=((CV[3]>>2)+1); // modulo code
  speedf__=logspeed[(gate[speedfrom[spdcount][3]].dac>>2)%cv];
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

/////////////////////////////////////////////////////////////////
// INTmodes - start to prototype bit modes

// prototype INTmode 0 no interpolation and no use of CV
void Rint0(void){ 
  uint8_t w=3;
  HEADR;  
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Rglobalint0(void){ // now use 8 bits - 4 for each count and daccount->dacfrom
  uint8_t w=3;				       
  HEADRN;
  if (gate[w].trigger)      {
    count=CV[3]>>8; //16 is 4 bits - we could have more
    daccount=(CV[3]>>4)&15;
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Raccelint0(void){ // TESTING but...
  uint8_t w=3;				       
  HEADR;  
  if (gate[w].trigger)      {
    GSHIFT_; // testing or?
    //    gate[3].shift_=gate[3].shift_<<1;    
    tmp=CV[3]; // 12 bits 
    for (xx=0;xx<3;xx++){
      for (x=0;x<4;x++){
	if (tmp&0x01){
	bitrr = (gate[x].Gshift_[xx]>>SRlength[x]) & 0x01;  // gshifts FOR 0 including our own
	gate[x].Gshift_[xx]=(gate[x].Gshift_[xx]<<1)+bitrr;
	}
	tmp=tmp>>1;
      }
    }
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

////

void Rintroute0(void){ // CV: 4 bits for route in... other bits for logop
  uint8_t w=3;				       
  HEADR;  
  if (gate[3].trigger)      {
    GSHIFT_;
    tmp=255-(CV[3]>>4); // 8 bits
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
  PULSIN_XOR;
  BITN_AND_OUTVINT_; // for pulse out
  } 
}

void RintselADC_63(void){ // use CV to select adc type: only those which don't use CV or strobe LIST: also select logop for routein // ***
  // we could also us top bits to do something with? 16 modes=4 bits, top bits logop/route?
  //0,1,2,3,4,5,6,7,8 - adc logical-22,23,25,26,27,30,63,64,65 to test - 27 dies out but...
  uint8_t choice[16]={0,1,2,3,4,5,6,7,8, 22, 23, 25, 26, 27, 30, 63};//leave off -inprogress 63,64,65 to test - TODO: expand this with new abstract and dac modes...
  //TODO: expand also with 
    // DAC inputs 25,26,27,71,72,73,74
  uint8_t w=3;				       
  HEADR;  
  if (gate[3].trigger)      {
    val=63-(CV[3]>>6); // 6 bits say
    GSHIFT_;
    bitn=ADC_(3,SRlength[w],choice[val>>2],gate[w].trigger,dacfrom[daccount][3],0, &gate[w].shift_);
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
    PULSIN_XOR;
    BITN_AND_OUTVINT_;
  } 
}


// INTmodes: global route from CV, prob from CV, others? + change global routes, fake clks, use as DAC, entry of adc/non-adc bits from top

/* // what bits we have again?///////////////////////////////////////////

dactype=4x4 bits = 16 bits (reduce to 3 bits each = 12 bits)

route=4 bits, what we do=2 bits, logops=2 bits, probability=2bits

eg.what we do
0-looping only/aka return only!
1-pass on only - straight through
2-pass on and return bitx

5 bits: 1 1 1 1 1 1
- top bit/speed
- 4 bits routing in
- 1 bit prob of inversion

incoming bit bits summary (3 bits) - eg. prob of: + type of prob (2 bits)
- routed in 
- cycled 
- inversion of routed
- inv cycles
- cycle and route
- inv of cycle and route
[can be more options eg. adc in]

route in and logop bits:
1111 4 route in bits x 3 logops = 2 bits per... 0, none, 1, xor, 2or, 3leak = 8 bits = 255 too much for CV
 
00 1-TM invert cycling bit - OR with BITIN (OR *(routed^pulse)*) // OR (routedORpulse) ??
01 2-BITIN or loopback
10 3-INV of above
11 4- BITIN or not into cycling


 */


// routing table is x long, and for raw routing we would need 4x4=16 bits but in global routing macros we only use:
//  if (!whorl) tmp=binroute[count][w] //but this could change with condition ???
//  else tmp=(wholeroute&routemask[w])>>routeshift[w]


