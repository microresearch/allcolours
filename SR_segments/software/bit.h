/*

notes: DACfrom 0-3, mix of DACs?, CV, CV +/xor/AND DAcfrom 0-3

// fill in bit modes here - for modeL then expand then port

using sr rather than dac

we can add masks (eg. CV by either detaching SRlength, or as INTmodes)

CVL - from length
CV - from speed

detaches
INTmodes

*/

//- route and logop - 8 bits + 2 from other dac: LSRroutelogxx and LSRroutelogxxx
void LSRroutelog(void){ // SR: 4 bits for route in... other bits for logop
  uint8_t w=1;				       
  HEADL;  
 if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {

    GSHIFT_;
    tmp=(SRFROM)&255; // 8 bits
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
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; // for pulse out
    ENDER;
  }
  } 
}

void LSRroutelogxx(void){ // SR: 4 bits for route in... other bits for logop - try changing srfrom
  uint8_t w=1, tmpp;
  HEADL;  
 if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {

    GSHIFT_;
    tmpp=(SRFROM)&3; // +2 bits //// dacfrom 8 bits (gate[dacfrom[daccount][w]].Gshift_[w])
    tmp=(gate[tmpp].Gshift_[w])&255; // 8 bits
    
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
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; // for pulse out
    ENDER;
  }
  } 
}

void LLcvsrroute(void){ // simpler routing and cv also selects dacfrom as well as maskings
  uint8_t w=1;
  HEADSINL;
  uint32_t mmm=(63-(CVL[1]>>6)); // 6 bits // dacfrom 2 = total 6

  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=(mmm>>2) & (gate[mmm&3].Gshift_[w]) ; 
    for (x=0;x<4;x++){  // older version
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}


void LSRroutelogxxx(void){ // recursive use of dacfrom SR: 4 bits for route in... other bits for logop - try changing srfrom
  uint8_t w=1, tmpp;
  static uint32_t lastdacfrom=0;
  HEADL;  
 if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {

    GSHIFT_;
    tmpp=(gate[lastdacfrom].Gshift_[w])&3; // +2 bits //// dacfrom 8 bits (gate[dacfrom[daccount][w]].Gshift_[w])
    tmp=(gate[tmpp].Gshift_[w])&255; // 8 bits
    lastdacfrom=tmpp;
    
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
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; // for pulse out
    ENDER;
  }
  } 
}

/*
4 bits route/logopp=x unless option 0

- what we do
0-looping only/aka return only!
1-pass on only - straight through
2-pass on and return bitx
3-use dacprob
*/
  
void LSRroutedoit(void){ // SR: 4 bits for route in, doit options and prob of inversion
  // can have bits from CV/SR/ and CV also for prob... but...
  uint8_t w=1, tmpp;				       
  HEADL;  
 if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {

    GSHIFT_;
    tmp=(SRFROM)&63; // 4 bits route, 2 bits doit
    tmpp=tmp&0x03;
    tmp=tmp>>2;
    if (tmpp!=0){
    for (x=0;x<4;x++){  // older version
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    if (tmpp==2) RETURN;
    else if (tmpp==3){ // dacprob of inversion
      if ((LFSR_[w] & 4095 ) < (gate[dacfrom[daccount][w]].dac)) bitn^=1;
    }
    } // 1/2/3
    else RETURN;
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; // for pulse out
    ENDER;
  }
  } 
}

//- length and CVL for route - can also be select of SRs for one/both//
void LLSRlen(void){ 
  uint8_t w=1, tmpp; 
  HEADSINL; // so we have CVL free for
  // to select DACfrom and route///
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmpp=(CVL[1]>>6)&0x03;
    tmp=gate[tmpp].shift_&31;    
    SRlength[1]=lookuplenall[tmp]; // 5 bits

    tmp=(CVL[1]>>8); // 4 bits
    //
    // XOR/AND
    tmp^=(gate[tmpp].shift_&15);
    
    for (x=0;x<4;x++){ 
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// basic route and AND length CV with standard SR
void LSRlen(void){ 
  uint8_t w=1; 
  HEADSINL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {    
    GSHIFT_;
    tmp=gate[dacfrom[daccount][1]].shift_&31;
    tmp=tmp&(31-(CVL[1]>>7));// 5 bits
    SRlength[1]=lookuplenall[tmp]; // 5 bits
    BINROUTE_; // or route and cycle
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// just add here

void LLDACSEL0(void){ 
  HEADSINL;
  uint32_t mmm=CVL[1]>>8; // to 4 bits
  gate[1].dactype=mmm; gate[1].dacpar=param[1];

}

void LLBITdactype(void){ // CVL and dacfrom set temporary local dactype
  uint8_t w=1;
  HEADSINL;
  uint32_t mmm=CVL[1]>>8; // to 4 bits
  tmp=(mmm)&(SRFROM&15); // dactype
  gate[1].dacpar=param[1]; 
    if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_; // cycle etc... - could be more complex here as we have spare bits - so could even route in
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp
    ENDER;
  }
  }
}

void LLcvtyperoute(void){ // CVL sets temporary local dactype - now with routings - 8 bits
  uint8_t w=1;
  HEADSINL;
  uint32_t mmm=(255-(CVL[1]>>4)); // 12 bits to 8 bits
  gate[1].dacpar=param[1]; 
    if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=(mmm&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){  // older version
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    
    tmp=(mmm>>4);//&(SRFROM&15); // tmp is dactype
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp
    ENDER;
  }
  }
}

void LLBITdactyperoute(void){ // CVL and dacfrom set temporary local dactype - now with routings - 8 bits
  uint8_t w=1;
  HEADSINL;
  uint32_t mmm=(255-(CVL[1]>>4)); // 12 bits to 8 bits
  gate[1].dacpar=param[1]; 
    if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=((mmm&15)&(SRFROM&15)); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){  // older version
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    
    tmp=(mmm>>4)&(SRFROM&15); // tmp is dactype
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp
    ENDER;
  }
  }
}


void LLBITlengthdactype(void){ //sets length and dactype - so we have spare CV to logop in
  uint8_t w=1;
  uint32_t bits;
  HEADSINL;  
 if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {

    bits=(CVL[1]>>4) ^ (SRFROM&255); // length is 5 bits, dactype can be from 3 to 5 bits
    SRlength[1]=lookuplenall[bits&31]; // 5 bits - length
    tmp=(bits>>5); // 3 bits - dactype
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp
    ENDER;
  }
  } 
}

// recursions we think about - use logopxxx for above = 2 bits - cv logop sr incoming

void LLSRroutexxxlog(void){ // SR: 4 bits for route in... 8 other bits for logop PLUS logopxxx for maskings
  uint8_t w=1;				       
  HEADSINL;  
 if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {

    GSHIFT_;
    tmp=logopxxx((CVL[1]&255),(SRFROM)&255, (SRFROM>>8)&0x03); 
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
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; // for pulse out
    ENDER;
  }
  } 
}
