// left hand functions
// check all for     strobey, PULSIN_XOR; and output pulses

// BINROUTE has strobey

/*

CVmodes: basics, prob modes entry/loopback, esoteric modes, << bumps, route from DAC, prob from DAC, what else?

DACmodes: basics, esoterics

INTmodes: route from CV, prob from CV, others?

- how we work with length param as it doesn't change so much?

*/

// TODO: check we have     PULSIN_XOR;!!!!!!!!!!!!!!1

// template
void LN(void){
  uint8_t w=1; uint8_t prob;
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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
  HEAD;
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

void LN35(void){ // TRIADEX 2 - TODO: version using CV or SR for these bits
  uint8_t w=1; uint8_t prob, bitnn, bitnnn, bitnnnn;
  HEAD;
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
  HEAD;
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







////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

void L0nog(void){ // basic route in no GSHIFT<<
  uint8_t w=1;
  HEAD;
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

void L3(void){ // test gshift on trigger
  uint8_t w=1;
  HEAD;
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

void L4(void){ // test gshift on trigger
  uint8_t w=1;
  HEAD;
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
  HEAD;
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
  PULSIN_XOR;
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
  PULSIN_XOR;
  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

void L32(void){ // multiple bits in as case 19 in draftdec
  uint8_t w=1;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    gate[w].shift_&=spacmask[SRlength[w]]; //cleared
    if (SRlength[defroute[w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
    }
    bitn=gate[w].shift_&1; // fixed this 29/12/2021
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger; 
    PULSIN_XOR;
    BITN_AND_OUTV_;
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
  if (speedf_[1]==2.0f) speedf_[1]=LOWEST;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// intmodes
// add in and check all probability modes

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
    PULSIN_XOR;
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
    PULSIN_XOR;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
