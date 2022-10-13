/// basics - copy 0 to gshifts so no route in but still we can run for dacs
// we need to zero counts in some modes... except global ones here

// a set of global counts for spd, route, dac which don;t reset to zero ...

void SRRLLswop(uint8_t w){ // swop in or logop SR - cv and cvl ***
  uint32_t lin, lout;
  HEADSSINNADA;

  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    if (gate[w].trigger) {
      lin=127-(CV[w]>>5); //7= 2 bits for whichone and start which can be 5
      lout=31-(CVL[w]>>7); // 5 bits for length
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
void SRR0(uint8_t w){ 
  HEAD;
  if (speedf_[w]!=LOWEST){ 
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

// no << gshift
void SRR0nog(uint8_t w){ 
  HEAD;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTENOG_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void SRRnada(uint8_t w){  // no route in. nada
   HEAD;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=0;
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void SRR1(uint8_t w){ // route and cycle
  HEAD;
  if (speedf_[w]!=LOWEST){ 
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

void SRRmod(uint8_t w){ // modulo route in 
  HEAD;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
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

void SRRosc0(uint8_t w){ // basic route in with oscillator
  HEAD;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_; //
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


void SRRaccelghosts0(uint8_t w){ // route in // exp mode to accelerate/bump on all ghosts except own - could also select which ones for intmode
  HEAD;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
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

///////////////////////////////// GLOBAL ROUTE modes
// for CV modes add in bump up global routes, SR as global routing table

void SRRstroberoute(uint8_t w){ // kill all routes
  HEAD;
  
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_; // we still keep our route in?
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }

  if (gate[w].trigger) // or could be toggle to hold it
    {
      count=16; // no routes...
    }
  else count=0; // basic route
}


void SRRglobalbump0(uint8_t w){ // bump dacroute and binroute  // what of spdcount
  HEAD;

  if (gate[w].trigger) // outside speed?
    {
      count++;
      if (count>15) count=0; // we have 16 so far, but can add more
      daccount=count;
    }
    
  if (speedf_[w]!=LOWEST){ 
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

void SRRglobaldac0(uint8_t w){ // dac as global route table 
  HEAD;
  if (speedf_[w]!=LOWEST){ 
    CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    count=(gate[w].dac)>>8; // 4 bits now    from ITSELF
    daccount=(gate[w].dac>>4)&15;
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
void SRRbumproute0(uint8_t w){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  HEAD;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  PULSIN_XOR;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void SRRDACroute0(uint8_t w){ 
  HEAD;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  PULSIN_XOR;
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void SRRSRroute0(uint8_t w){ 
  HEAD;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
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
  PULSIN_XOR;
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}


void SRR32(uint8_t w){ // multiple bits in as case 19 in draftdec
  HEAD;
  if (speedf_[w]!=LOWEST){ 
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
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }    
  }
}

///// thinking on bit modes

void SRRBITlengthdac(uint8_t w){ 
  uint32_t bits;
  HEAD;  
 if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {

    bits=SRFROM&255; // length is 5 bits, dactype can be from 3 to 5 bits
    SRlength[w]=lookuplenall[bits&31]; // 5 bits
    tmp=(bits>>5); // 3 bits
    GSHIFT_;

    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp
    ENDER;
  }
  } 
}

void SRRLBITlengthdac(uint8_t w){ // detach length and just have dactype 
  uint32_t bits;
  HEADSIN;  
 if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {

    bits=CVL[w]>>4; // 8 bits - length is 5 bits, dactype can be from 3 to 5 bits
    SRlength[w]=lookuplenall[bits&31]; // 5 bits
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

void SRRdacoffset0(uint8_t w){
  float speedf__;
  float mmm=(float)(1024-(CVL[w]>>2))/1024.0f;
  HEADSIN;
  tmp=(1024-(CV[w]>>2)) + (int)((float)(gate[speedfrom[spdcount][w]].dac>>2)*mmm);
  if (tmp>1023) tmp=1023;
  if (tmp<0) tmp=0;
  speedf__=logspeed[tmp]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRdacadditself0(uint8_t w){ // tested//trial itself as DAC - can also be other variants TODO
  HEAD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[w].dac>>3)];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRdacghostitself0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[w].Gshift_[0]//gate[x].Gshift_[w]
  HEAD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+((gate[w].Gshift_[1])&511)];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRdacseladd0(uint8_t w){
  HEAD;
  float speedf__;
  uint8_t whic=(CV[w]>>9)&3; //12 bits -> 2 bits
  //  if (speedf_[0]==2.0f) speedf_[0]=LOWEST;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[which].dac>>2)]);
  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit
//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  // if (speedf__<LOWEST) speedf__=LOWEST;
  //  speedf__=1.0f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRdacadd0(uint8_t w){
  HEAD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[speedfrom[spdcount][w]].dac>>3)];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRdacmod(uint8_t w){
  HEAD;
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeed[(gate[speedfrom[spdcount][w]].dac>>2)%cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRB0(uint8_t w){// with oscillator
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[speedfrom[spdcount][w]].dac>>2)-(1024-(CV[w]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_; // no route in now
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

//SRL, SRR: speed from SRN: (both run OSC with no binroute) - is as RB0 above
void SRRrung0(uint8_t w){// with oscillator
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRrung1(uint8_t w){// with oscillator - other minus - but is same as above
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2)); // other minus
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRrung2(uint8_t w){// with oscillator - mod
  HEAD;
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeed[(gate[0].dac>>2)%cv]; // mod
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

void SRRrung3(uint8_t w){// with oscillator - add
  HEAD;
  int32_t cv;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[0].dac>>3)]; // add
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}


void SRRLrung0(uint8_t w){// DETACHED> with oscillator
  HEADSIN;
  int32_t cv;
  float speedf__;
  //  cv=(CV[1]>>2)-(gate[0].dac>>2);
  //  if (cv<0) cv=0;
  // 2 bits speed ops...
  tmp=CVL[w]>>6; //2+4 bits = 6 bits
  // top bits
  if (tmp&16){
    cv=((CV[w]>>2)+1); // modulo code
    speedf__=logspeed[(gate[0].dac>>2)%cv]; // mod
  }
  else if (tmp&32){
  cv=(CV[w]>>2)-(gate[0].dac>>2);
  if (cv<0) cv=0;
  speedf__ = logspeed[cv]; // minus
  }
  else if (tmp&48){
  speedf__=logspeed[(CV[w]&511)+(gate[0].dac>>3)]; // add
  }
  else {
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2)); // other minus
  if (cv<0) cv=0;
  speedf__ = logspeed[cv]; 
  }

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=tmp>>2;
    bitn=ADC_(w,SRlength[w],oscmode[tmp],gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}



void SRRdacminus0(uint8_t w){
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[speedfrom[spdcount][w]].dac>>2)-(1024-(CV[w]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRdacspeedminus0(uint8_t w){
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)-(gate[speedfrom[spdcount][w]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRdacmod0(uint8_t w){
  HEAD;
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeed[(gate[speedfrom[spdcount][w]].dac>>2)%cv];
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
void SRRint0(uint8_t w){ 
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void SRRglobalint0(uint8_t w){ // now use 8 bits - 4 for each count and daccount->dacfrom - can we use 8 bits from CV?
  HEADSIN;
  if (gate[w].trigger)      {
    count=CV[w]>>8; //16 is 4 bits - we could have more - 
    daccount=(CVL[w]>>4)&15;
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void SRRaccelint0(uint8_t w){ // TESTING but...
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_; // testing or?
    //    gate[w].shift_=gate[w].shift_<<1;    
    tmp=CV[w]; // 12 bits 
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

void SRRintroute0(uint8_t w){ // CV: 4 bits for route in... other bits for logop
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    tmp=255-(CV[w]>>4); // 8 bits
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

void SRRintselADC_63(uint8_t w){ // use CV to select adc type: only those which don't use CV or strobe LIST: also select logop for routein // ***
  // we could also us top bits to do something with? 16 modes=4 bits, top bits logop/route?
  //0,1,2,3,4,5,6,7,8 - adc logical-22,23,25,26,27,30,63,64,65 to test - 27 dies out but...
  uint8_t choice[16]={0,1,2,3,4,5,6,7,8, 22, 23, 25, 26, 27, 30, 63};//leave off -inprogress 63,64,65 to test - TODO: expand this with new abstract and dac modes...
  //TODO: expand also with 
    // DAC inputs 25,26,27,71,72,73,74
  HEAD;  
  if (gate[w].trigger)      {
    val=63-(CV[w]>>6); // 6 bits say
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],choice[val>>2],gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_);
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 5th tail/head - 9th SR - [8]
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///... what other models there could be?

void SR5_feedback(uint8_t w){ // detached
  HEADSIN; // use CVL[w] for tail entry speed... // can also use as INTmode with speed as this speed...
  // tail trial1
  uint8_t old;
  speedf_[8]=logspeed[CVL[w]>>2];
  old=w;
  w=8;
  //  gate[w].dac = delay_buffer[w][1]; // no interpol so we have gate[8].dac as 5th tail
  gate[w].time_now += speedf_[w];
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // we want what would be/have been routed in
      tmp=binroute[count][old];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	  bitn^=bitrr;    
	}
	tmp=tmp>>1;
      }
    gate[w].shift_+=bitn;
    //    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); // do we need that dac?
    new_data(val,w);
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  // back to regular RSR - and we can have variation on this
  w=old; 
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


