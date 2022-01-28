// left hand functions
// TODO: check we have     PULSIN_XOR;!!!!!!!!!!!!!! check all for     strobey, PULSIN_XOR; and output pulses

// BINROUTE has strobey already

/*

CVmodes: basics, prob modes entry/loopback, esoteric modes, << bumps, route from DAC, prob from DAC, what else?

DACmodes: basics, esoterics

INTmodes: route from CV, prob from CV, others?

- how we work with length param as it doesn't change so much?

*/



// template
void LN(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    
    //    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    //    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// port in from newmodes.c

void LN3(void){ // match newmodes numbers
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    prob=gate[w].shift_&31; // this seems to work somehow 8/12/2021
    PULSIN_LEAK; // try xor vs leak vs or... - uses prob as param
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN4(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTEANDCYCLE_;
    prob=gate[w].shift_&31; // this seems to work somehow 8/12/2021
    PULSIN_LEAK; // try xor vs leak vs or... - uses prob as param
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN5(void){ //00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) 
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    if (gate[w].trigger)	  bitrr=(gate[w].shift_>>SRlength[w]) & 0x01;
    else bitrr=!((gate[w].shift_>>SRlength[w]) & 0x01); 
    bitn|=bitrr;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN6(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger){
      BINROUTE_;
    }
    else {
      bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
    }
    PULSIN_XOR;

    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN7(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger){
      BINROUTE_;
    }
    else {
      bitn=!(gate[w].shift_>>SRlength[w]) & 0x01; 
    }	
    PULSIN_XOR;
    
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN8(void){
  uint8_t w=1; uint8_t prob; static uint8_t tug[4]={0};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]){
      BINROUTEANDCYCLE_;
    }
    else {
      bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
    }	
    PULSIN_XOR;
    
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// there is no 9 there
void LN10(void){ // **
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	if (gate[w].trigger) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1;
    }
    PULSIN_XOR;
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN11(void){
  uint8_t w=1; uint8_t prob; uint32_t tmpp;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
	tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  if (gate[w].trigger){
	    tmpp=gate[x].Gshift_[w];
	    REV32; // reverse 32 bits
	    tmpp=tmpp&othermasky[SRlength[x]]; // mask the top length bits
	    gate[x].Gshift_[w]=tmpp>>(31-SRlength[x]); // and shift 31-length bits
	  }
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; // 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }
      PULSIN_XOR;
      BITN_AND_OUTV_; 
      ENDER;
  }
  }
}

void LN12(void){       // XX - we XOR on STROBE our shift with the GHOST
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
  tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
    if (gate[w].trigger) gate[x].Gshift_[w]^=gate[w].shift_;
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    if (gate[w].trigger) 
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN13(void){ //00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ?? -- 9 below
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
	BINROUTE_;
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[count][w]].dac)){
	  bitrr=(gate[w].shift_>>SRlength[w]) & 0x01;
	}
	else bitrr=!((gate[w].shift_>>SRlength[w]) & 0x01); 
	bitn|=bitrr;
    PULSIN_XOR;
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN14(void){ //	01 2-BITIN or loopback
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[count][w]].dac)){
	  BINROUTE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}		//
	PULSIN_XOR;
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN15(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[count][w]].dac)){
	  BINROUTEANDCYCLE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}	
    PULSIN_XOR;
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN21(void){ // triadex inspired mode where we XOR in bits from the other SRs CASE 21
  uint8_t w=1; uint32_t bitnn, bitnnn; 
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    bitn = (gate[others[w][0]].Gshift_[w]>>SRlength[others[w][0]]) & 0x01; 
    gate[others[w][0]].Gshift_[w]=(gate[others[w][0]].Gshift_[w]<<1)+bitn;

    bitnn = (gate[others[w][1]].Gshift_[w]>>SRlength[others[w][1]]) & 0x01; 
    gate[others[w][1]].Gshift_[w]=(gate[others[w][1]].Gshift_[w]<<1)+bitnn;

    bitnnn = (gate[others[w][2]].Gshift_[w]>>SRlength[others[w][2]]) & 0x01; 
    gate[others[w][2]].Gshift_[w]=(gate[others[w][2]].Gshift_[w]<<1)+bitnnn;
    
    //    bitn^=((gate[w].shift_>>SRlength[w])& 0x01)^bitnn^bitnnn;
    bitn^=bitnn^bitnnn; 
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN22(void){// as above
  uint8_t w=1; uint8_t prob; uint32_t bitnn, bitnnn; 
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    bitn = (gate[others[w][0]].shift_>>SRlength[others[w][0]]) & 0x01;
    bitnn = (gate[others[w][1]].shift_>>SRlength[others[w][0]]) & 0x01;
    bitnnn = (gate[others[w][2]].shift_>>SRlength[others[w][0]]) & 0x01;

    //    bitn^=((gate[w].shift_>>SRlength[w])& 0x01)^bitnn^bitnnn;
    bitn^=bitnn^bitnnn; 
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN29(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    bitn=(gate[w].shift_>>SRlength[w])& 0x01;
    if ((LFSR_[w] & 4095 )<adc_buffer[12]) {
      bitn=bitn^1;
    }
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN30(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    bitn=(gate[w].shift_>>SRlength[w])& 0x01; 
    if ((gate[w].dac)<gate[dacfrom[count][w]].dac) { 
      bitn=bitn^1;
    }
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN33(void){    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_; // we dont shift our own SR
    // INSERT!
    GGGshift_[w]=GGGshift_[w]<<1;
    BINROUTE_;    
    PULSIN_XOR;
    GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    } 
    BITN_AND_OUTVNOSHIFT_;
    ENDER;
  }
  }
}

void LN34(void){    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)
  // with LOOP option
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_; // we dont shift our own SR
    // INSERT!
    tmp=(gate[w].shift_>>SRlength[w])& 0x01;
    gate[w].shift_+=tmp;
    
    GGGshift_[w]=GGGshift_[w]<<1;
    BINROUTE_;    
    PULSIN_XOR;
    GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    } 
    BITN_AND_OUTVNOSHIFT_;
    ENDER;
  }
  }
}

void LNsr35(void){ // TRIADEX 2 - try with SR...
  uint8_t w=1; uint8_t prob, bitnn, bitnnn, bitnnnn;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // SR: gate[dacfrom[count][1]].dac we need 3+5+3+5 bits=16 x2
    tmp=(gate[dacfrom[count][1]].dac);
    
    s[0]=(tmp>>29)&3; // select which one... 0,1,2,3 
    ss[0]=(tmp>>24)&31;

    s[1]=(tmp>>21)&3; // select which one... 0,1,2,3
    ss[1]=(tmp>>16)&31;

    s[2]=(tmp>>13)&3; // select which one... 0,1,2,3
    ss[2]=(tmp>>8)&31;

    s[3]=(tmp>>5)&3; // select which one... 0,1,2,3
    ss[3]=(tmp)&31;

    
    bitn = (gate[s[0]].shift_ >> ss[0]) & 0x01;
    bitnn = (gate[s[1]].shift_ >> ss[1]) & 0x01;
    bitnnn = (gate[s[2]].shift_ >> ss[2]) & 0x01; 	
    bitnnnn = (gate[s[3]].shift_ >> ss[3]) & 0x01; 
    
    bitn^=((gate[w].shift_>>SRlength[w])& 0x01)^bitnn^bitnnn^bitnnnn; 
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN35(void){ // TRIADEX 2 
  uint8_t w=1; uint8_t prob, bitnn, bitnnn, bitnnnn;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    s[0]=(param[0]>>5)&3; // select which one... 0,1,2,3
    ss[0]=param[0]%32; // 32 bits
    s[1]=(param[1]>>5)&3; // select which one... 0,1,2,3
    ss[1]=param[1]%32; // 32 bits
    s[2]=(param[2]>>5)&3; // select which one... 0,1,2,3
    ss[2]=param[2]%32; // 32 bits
    s[3]=(param[3]>>5)&3; // select which one... 0,1,2,3
    ss[3]=param[3]%32; // 32 bits

    bitn = (gate[s[0]].shift_ >> ss[0]) & 0x01;
    bitnn = (gate[s[1]].shift_ >> ss[1]) & 0x01;
    bitnnn = (gate[s[2]].shift_ >> ss[2]) & 0x01; 	
    bitnnnn = (gate[s[3]].shift_ >> ss[3]) & 0x01; 
    
    bitn^=((gate[w].shift_>>SRlength[w])& 0x01)^bitnn^bitnnn^bitnnnn; 
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


void LN36(void){ // pulse triggers exchange between ghost and real
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    // INSERT!
    if (gate[w].trigger==1) { // at start we place it...
      gate[w].shift_=gate[w].Gshift_[w];
    }
    GSHIFT_;
    BINROUTE_;    
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN38(void){// pass through or cycle is toggled by clkin bit
  uint8_t w=1; static uint8_t tug[4]={0};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) tug[w]^=1; // tuggle
    
    if (tug[w]) {
      bitn=(gate[w].shift_>>SRlength[w])& 0x01;  // cycle...
      if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    }
    else {
      BINROUTE_;
    }
    
    PULSIN_XOR;    
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN40(void){// swap over SRs on pulse in?!! or swop in only (can swop in previous SR or another?) 
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    if (gate[w].trigger) gate[w].shift_=gate[oppose[w]].shift_; // sieve is previous one but could be opposite one
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN42(void){ // - reverse direction of shift register - could be done on a toggle: >> and << and blank/fill in bitn/complicated
  uint8_t w=1; static uint8_t tug[4]={0};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    // INSERT!
    GSHIFTNOS_;
    
    if (gate[w].trigger) tug[w]^=1; // tuggle
    if (tug[w]){
      gate[w].shift_=gate[w].shift_<<1;
      BINROUTE_;
      PULSIN_OR; 
    BITN_AND_OUTV_; 
    }
    else //in reverse - can be defroute or revroute - 2 options but revroute doesn't seem to work so well
      {
	gate[w].shift_=gate[w].shift_>>1;
	bitn = (gate[inroute[count][w]].Gshift_[w] & 0x01); // just the lowest bit 
	PULSIN_OR;
	gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]>>1);
	gate[inroute[count][w]].Gshift_[w] &= ~(1UL << SRlength[inroute[count][w]]);
	gate[inroute[count][w]].Gshift_[w] += (bitn << SRlength[inroute[count][w]]);

	gate[w].shift_ &= ~(1UL << SRlength[w]);
	gate[w].shift_ +=(bitn << SRlength[w]);
	BITN_AND_OUTVNOSHIFT_; 
      }
    ENDER;
  }
  }
}

void LN46(void){ //- cycling array of ghosts toggle in/how to toggle out
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    PULSIN_XOR;    
    BITN_AND_OUTV_;
    
    Gshift_rev[w][Gshift_revcnt[w]]=gate[w].shift_; // record
    Gshift_revcnt[w]++;
    if (Gshift_revcnt[w]>255) Gshift_revcnt[w]=0;
    
    if (gate[w].trigger){
      gate[w].shift_=Gshift_rev[w][Gshift_revrevcnt[w]]; 
      Gshift_revrevcnt[w]++;
      if (Gshift_revrevcnt[w]>255) Gshift_revrevcnt[w]=0;
    }
    ENDER;
  }
  }
}


void LN48(void){ //  // GSR doesn't change (becomes a revenant) - only works when we enter this and then is shifted out
  //remake as ghost of ghost - can also be strobe which records this
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    if (gate[w].trigger)    GGGshift_[w]=gate[w].shift_;
    gate[w].Gshift_[0]=GGGshift_[w];
    gate[w].Gshift_[1]=GGGshift_[w];
    gate[w].Gshift_[2]=GGGshift_[w];
    gate[w].Gshift_[3]=GGGshift_[w];
    gate[w].shift_=gate[w].shift_<<1;

    BINROUTE_;
    PULSIN_XOR;    
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN50(void){ // GSR is masked in on trigger
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
    gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
    if (gate[w].trigger) gate[w].shift_&=gate[inroute[count][w]].Gshift_[w];
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN62(void){ // LFSR in routed in SRs
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
      tmp=binroute[count][w];
      for (x=0;x<4;x++){ 
      if (tmp&0x01){  
	bitrr = ((gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][0])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][1])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][2])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][3]))) & 1u;
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }
      
      if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
      PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LN65(void){// SR in SR with strobe as barrier? only for itself or for incoming/itself
  uint8_t w=1; uint8_t tmpt; static uint8_t cw=0;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
      cw++;
      if (cw>31) cw=0;
      if (gate[w].trigger) tmpt=cw;
      
      tmp=binroute[count][w]; 
      for (x=0;x<4;x++){ 
	if (tmp&0x01) {  
	    bitrr = (gate[x].Gshift_[w]>>tmpt) & 0x01; // or can just keep tmpt for this one and len of previous
	    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	    bitn^=bitrr;
	  }
      tmp=tmp>>1;
      }	
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void LNwas13(void){ //pulse changes which bit ofghostSR we access - pulse moves on bit
  // TODO: could also be CV
  uint8_t w=1; uint8_t prob; static uint8_t which[4]={};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    	if (gate[w].trigger) {
	    which[w]++;
	    if (which[w]>SRlength[w]) which[w]=0;
	  }

	  tmp=binroute[count][w];
	  for (x=0;x<4;x++){
	    if (tmp&0x01){
	      bitrr = (gate[x].Gshift_[w]>>which[w]) & 0x01;
	      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	      bitn^=bitrr;
	    }
	    tmp=tmp>>1;
	  }	  

	  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
	  PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Lno(void){
}

void LX0(void){ // basic route in XOR puls
  uint8_t w=1; 
  HEADL;
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

void L0(void){ // basic route in OR puls
  uint8_t w=1; 
  HEADL;
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


void L0nog(void){ // basic route in no GSHIFT<<
  uint8_t w=1;
  HEADL;
  if (speedf_[w]!=2.0f){ 
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

void L1(void){ // route and cycle
  uint8_t w=1;
  HEADL;
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
  HEADL;
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

void L3(void){ // test gshift on trigger
  uint8_t w=1;
  HEADL;
  if (gate[w].trigger) { // outside or inside loop?
    GSHIFT_;
  }
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void L4(void){ // test gshift on trigger inside loop
  uint8_t w=1;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  if (gate[w].trigger) { // outside or inside loop?
    GSHIFT_;
  }
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Losc0(void){ // basic route in with oscillator
  uint8_t w=1;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],30,gate[w].trigger,dacfrom[count][1],gate[w].adcpar, &gate[w].shift_); // oscillator
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Lmod(void){ // modulo route in SR
  uint8_t w=1;
  HEADL;
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
// where do we get that range from? start/end - need 2x CVs
void Lbumproute0(void){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  uint8_t w=1;
  HEADL;
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
  PULSIN_XOR;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void LDACroute0(void){ 
  uint8_t w=1;
  HEADL;
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
  PULSIN_XOR;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void LDACroutestrobe0(void){ // strobe decides if we change local routing table 
  uint8_t w=1;
  HEADL;
  if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {
  GSHIFT_;
  //  if (!strobey[1][mode[1]]) bitn|=gate[1].trigger;
  if (gate[1].trigger){
  tmp=gate[dacfrom[count][1]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[1]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[1]=(gate[x].Gshift_[1]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else BINROUTE_;
  PULSIN_XOR;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}


void L32(void){ // multiple bits in as case 19 in draftdec
  uint8_t w=1;
  HEADL;
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
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }    
  }
}


// testing multiple speeds using CVL:
/*
1. shifting/SR speed <<
2. GSR copy speed (own GSR) //copy on strobe? see 37 in newmodes - L3 in modeL - in/outside loop as optionsDONE
3. advance incoming GSR speed - slidings
4. DAC out speed  - slipping - this is main loop as we need interpol
*/

void Lmultiplespeed0_0(void){ // basic ADC in - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  uint8_t w=1;
  HEADSIN;

  if (gate[1].trigger) GSHIFTNOS_; // 1.gshift owns on trigger

  if (counter[1]>CVL[1]){ //2.advance incoming ghost
    counter[1]=0;
    BINROUTEADV_;
  }
    
  if (speedf_[w]!=2.0f){ // 3.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    gate[w].shift_=gate[w].shift_<<1; 
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

// variations on this below
void Lmultiplespeed1_0(void){ // basic ADC in - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  uint8_t w=1;
  HEADSIN;

  if (gate[1].trigger) BINROUTEADV_; //2.advance incoming ghost

  if (counter[1]>CVL[1]){ // 1.gshift owns on trigger
    counter[1]=0;
    GSHIFTNOS_; 
  }
    
  if (speedf_[w]!=2.0f){ // 3.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    gate[w].shift_=gate[w].shift_<<1; 
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

void Lmultiplespeed2_0(void){ // basic ADC in - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  uint8_t w=1;
  HEADSIN;

  if (gate[1].trigger) GSHIFT_; // 1.gshift owns on trigger - NOW WITH <<

  if (counter[1]>CVL[1]){ //2.advance incoming ghost
    counter[1]=0;
    BINROUTEADV_;
  }
    
  if (speedf_[w]!=2.0f){ // 3.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

void Lmultiplespeed3_0(void){ // basic ADC in - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  // no trigger advance
  uint8_t w=1;
  HEADSIN;

  //  if (gate[1].trigger) GSHIFT_; // 1.gshift owns on trigger - NOW WITH <<

  if (counter[1]>CVL[1]){ //2.advance incoming ghost
    counter[1]=0;
    BINROUTEADV_;
  }
    
  if (speedf_[w]!=2.0f){ // 3.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

// we can also have multiplespeeds that also use DAC and some don't need CVL in that case
void Lmultiplespeeddac0_0(void){ // basic ADC in - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  uint8_t w=1;
  HEADSIN;

  // for DAC:     gate[w].shift_=gate[w].shift_<<1; < gate[dacfrom[count][w]].dac
  if (counterl>gate[dacfrom[count][w]].dac){
    counterl=0; // COUNTERL - COUNTERR for letf and right TODO
    gate[w].shift_=gate[w].shift_<<1;
  }
  
  if (gate[1].trigger) GSHIFTNOS_; // 1.gshift owns on trigger

  if (counter[1]>CVL[1]){ //2.advance incoming ghost
    counter[1]=0;
    BINROUTEADV_;
  }
    
  if (speedf_[w]!=2.0f){ // 3.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

// version with DAC and speed so no CVL
void Lmultiplespeeddac1_0(void){ // basic ADC in - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  uint8_t w=1;
  HEADL;

  if (gate[1].trigger) GSHIFTNOS_; // 1.gshift owns on trigger

  if (counter[1]>gate[dacfrom[count][w]].dac){ //2.advance incoming ghost
    counter[1]=0;
    BINROUTEADV_;
  }
    
  if (speedf_[w]!=2.0f){ // 3.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    gate[w].shift_=gate[w].shift_<<1; 
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

// speed as probability (from?)
void Lprobcvspeed0(void){ 
  uint8_t w=1;
  HEADL;  
  count=0;
  if (((LFSR_[1] & 4095 ) > CV[1])){ 
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Lprobcvdacspeed0(void){ 
  uint8_t w=1;
  HEADL;  
  count=0;
  if ( (LFSR_[1] & 4095 ) < ((CV[1]>>1)+(gate[dacfrom[count][1]].dac>>1))) { //DAC etc also compared here
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Lprobmultiplespeed3_0(void){ // basic ADC in - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  // no trigger advance
  uint8_t w=1;
  HEADL;

  //  if (gate[1].trigger) GSHIFT_; // 1.gshift owns on trigger - NOW WITH <<

  if (((LFSR_[1] & 4095 ) > gate[dacfrom[count][1]].dac)){ //DAC 
    counter[1]=0;
    BINROUTEADV_;
  }
    
  if (speedf_[w]!=2.0f){ // 3.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

/*
*new sets of modes where we keep old length and use a new CVL for:*
*- prob and routings
*/

void LLprobroute0(void){ // CV: 4 bits for route in... other bits for logop
  uint8_t w=1;				       
  HEADSIN;  
 if (speedf_[1]!=2.0f){
  CVOPEN;
  if(gate[1].last_time<gate[1].int_time)      {

    GSHIFT_;
    tmp=255-(CVL[1]>>4); // 8 bits
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
    BITN_AND_OUTV_; // for pulse out
    ENDER;
  }
  } 
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// DAC speeds

// test - speedCV-speedDAC 
void Ldac0(void){
  uint8_t w=1;
  float speedf__;
  HEADL;
  if (speedf_[1]==2.0f) speedf_[1]=LOWEST;
  speedf__= (speedf_[1]-logspeed[1024-(gate[dacfrom[count][1]].dac>>2)]); // dacfrom
  if (speedf__<LOWEST) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// how to do offset and scale 0- CV[1] is offset, CVL[1] is scale...
// test - speedCV-speedDAC 
void Ldacoffset0(void){
  uint8_t w=1;
  float speedf__;
  float mmm=(float)(1024-(CVL[1]>>2))/1024.0f;
  HEADSIN;
  tmp=(1024-(CV[1]>>2)) + (int)((float)(gate[dacfrom[count][1]].dac>>2)*mmm);
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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// intmodes
// add in and check all probability modes

// prototype INTmode 0 no interpolation and no use of CV - cycles though
void Lint0(void){ 
  uint8_t w=1;
  HEADL;  
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
  HEADL;  
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
    PULSIN_XOR;
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void LintDACroute0(void){ // dacroute version with prob/CV deciding if we change table or not  ****
  uint8_t w=1;
  HEADL;
  GSHIFT_;
  if (gate[1].trigger){
    if (((LFSR_[1] & 4095 ) < CV[1])){  
  tmp=gate[dacfrom[count][1]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[1]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[1]=(gate[x].Gshift_[1]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
    }
  else BINROUTE_;
  
  PULSIN_XOR;
  BITN_AND_OUTVINT_; // with pulses

  }  
}



void LintselADC_63(void){ // use CV to select adc type: only those which don't use CV or strobe LIST:
  // we could also us top bits to do something with? 16 modes=4 bits, top bits logop/route?
  //0,1,2,3,4,5,6,7,8 - adc logical-22,23,25,26,27,30,63,64,65 to test - 27 dies out but...
  uint8_t choice[16]={0,1,2,3,4,5,6,7,8, 22, 23, 25, 26, 27, 30, 63};//leave off -inprogress 63,64,65 to test - TODO: expand this with new abstract and dac modes...
    // DAC inputs 25,26,27,71,72,73,74
  uint8_t w=1;				       
  HEADL;  
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
    PULSIN_XOR;
    BITN_AND_OUTVINT_;
  } 
}

// with split CVs for these bits

void LLNint35(void){ // TRIADEX 2 - TODO: version using CV or SR for these bits
  uint8_t w=1; uint8_t prob, bitnn, bitnnn, bitnnnn;
  HEADSIN;
  if (gate[1].trigger)      {
  GSHIFT_;
  // so we have CV[1] and CVL[1] for bits

  // INSERT!
  //  CV[1] - 3 bits 3 bits 3 bits 3 bits = 12 bits - cv is 12 bits - so maybe just pick from lowest 8
    s[0]=(CV[1]>>9)&3; // select which one... 0,1,2,3
    ss[0]=(CV[1]>>6)&3;
    s[1]=(CV[1]>>3)&3;
    ss[1]=CV[1]&3;

    s[2]=(CVL[1]>>9)&3; // select which one... 0,1,2,3
    ss[2]=(CVL[1]>>6)&3;
    s[3]=(CVL[1]>>3)&3;
    ss[3]=CVL[1]&3;
    
    bitn = (gate[s[0]].shift_ >> ss[0]) & 0x01;
    bitnn = (gate[s[1]].shift_ >> ss[1]) & 0x01;
    bitnnn = (gate[s[2]].shift_ >> ss[2]) & 0x01; 	
    bitnnnn = (gate[s[3]].shift_ >> ss[3]) & 0x01; 
    
    //    bitn^=((gate[w].shift_>>SRlength[w])& 0x01)^bitnn^bitnnn^bitnnnn;
    bitn^=bitnn^bitnnn^bitnnnn; 
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  }
}

