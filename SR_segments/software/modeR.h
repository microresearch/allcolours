// right hand functions

// **REMEMBER to set count=0 in relevant modes // TODO: check we have     PULSIN_XOR;!!!!!!!!!!!!!!1

/*

and global set routes, set which dacs is dac for adc, set fake clkins

CVmodes: basics, prob modes entry/loopback, esoteric modes, << bumps, route from DAC, prob from DAC

DACmodes: basics, esoterics

INTmodes: route from CV, prob from CV, others? + change global routes, fake clks, use as DAC, entry of adc/non-adc bits from top

above, different kinds of DAC out

*/


// CV modes

// basic route in prototype
void R0(void){ 
  uint8_t w=3;
  count=0;
  HEAD;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_OR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void R1(void){ // route and cycle
  uint8_t w=3;
  count=0;
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

void Rmod(void){ // modulo route in 
  uint8_t w=3;
  count=0;
  HEAD;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;  
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

void Raccelghosts0(void){ // route in // exp mode to accelerate/bump on all ghosts except own - could also select which ones for intmode
  uint8_t w=3;
  count=0;
  HEAD;
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

void Rglobalbump0(void){ 
  uint8_t w=3;
  //  count=0;
  HEAD;

  if (gate[3].trigger) // outside speed?
    {
      count++;
      if (count>15) count=0; // we have 16 so far, but can add more
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
  //  count=0;
  HEAD;
  if (speedf_[3]!=2.0f){ 
    CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    count=(gate[3].dac)>>8; // 4 bits now    from ITSELF
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


// DACspeed modes?

/*

refine and figure out dac modes as dac is too fast

 */

// DONE: top bits of CV/speed select which DAC to take from - implement and test this, but we need access to bits/CV and smoothed

// which DAC we use? our own? dac1 left side for right?

// so far we have 7 modes and all just use adc mode 0 so this needs to be trimmed - DAC modes also more suited for abstract modes
// can also have BINROUTE in or not???

void Rdacadditself0(void){ // tested//trial itself as DAC - can also be other variants TODO
  HEAD;
  count=0;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[3].dac>>3)];
  if (speedf__==2.0f) speedf__=0.000990f;
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
  HEAD;
  count=0;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+((gate[3].Gshift_[1])&511)];
  if (speedf__==2.0f) speedf__=0.000990f;
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
  HEAD;
  count=0;
  uint8_t w=3;
  float speedf__;
  uint8_t whic=(CV[3]>>9)&3; //12 bits -> 2 bits
  //  if (speedf_[0]==2.0f) speedf_[0]=0.000990f;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[which].dac>>2)]);
  speedf__=logspeed[(CV[3]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit
//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  // if (speedf__<0.000990f) speedf__=0.000990f;
  //  speedf__=1.0f;
  if (speedf__==2.0f) speedf__=0.000990f;
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
  HEAD;
  count=0;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[dacfrom[count][3]].dac>>3)];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Rdacaddmax0(void){ // REMOVE?
  HEAD;
  count=0;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)+(gate[dacfrom[count][3]].dac>>2);
  if (cv>1023) cv=1023;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Rdacminus0(void){
  HEAD;
  count=0;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[count][3]].dac>>2)-(1024-(CV[3]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=0.000990f;
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
  HEAD;
  count=0;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)-(gate[dacfrom[count][3]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=0.000990f;
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
  HEAD;
  count=0;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=((CV[3]>>2)+1); // modulo code
  speedf__=logspeed[(gate[dacfrom[count][3]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}



// INTmodes - start to prototype bit modes

// prototype INTmode 0 no interpolation and no use of CV
void Rint0(void){ 
  uint8_t w=3;
  HEAD;  
  count=0;
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Rglobalint0(void){ 
  uint8_t w=3;				       
  HEAD;
  //  count=0;
  if (gate[w].trigger)      {
    count=CV[3]>>8; //16 is 4 bits - we could have more
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Raccelint0(void){ // TESTING but...
  uint8_t w=3;				       
  HEAD;  
  count=0;
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

// INTmodes: route from CV, prob from CV, others? + change global routes, fake clks, use as DAC, entry of adc/non-adc bits from top

/* // what bits we have again?///////////////////////////////////////////


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


