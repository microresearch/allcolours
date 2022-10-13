void SRNwas14(uint8_t w){ 	//- probability of advancing a GSR - strobe version we have above in 3 (commented out)DONE

    // INSERT!
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  if ((LFSR_[w] & 4095 ) < (gate[dacfrom[daccount][w]].dac)) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
	}	

      if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
      PULSIN_XOR;
      BITN_AND_OUTV_;

void SRNwas15(uint8_t w){

    // INSERT!
    // was15 4x4 bits prob of routing in GSR  so we need 4 probs of x bits?
	tmp=LFSR_[w]; tmpp=gate[dacfrom[daccount][w]].shift_; // try with CV too
	for (x=0;x<4;x++){
	  if ((tmp&255)<(tmpp&255)){// replace with 12 bits /4 = 3 bits prob = 7 (LFSR_[w] & 4095 ) < (shift_[LFSR[w]] & 4095)
	    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	    bitn^=bitrr;
	}
	tmp=tmp>>8; tmpp=tmpp>>8;
	}	
    
        if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
        PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN3(uint8_t w){ // match newmodes numbers

    // INSERT!
    BINROUTE_;
    prob=gate[w].shift_&31; // this seems to work somehow 8/12/2021
    PULSIN_LEAK; // try xor vs leak vs or... - uses prob as param
    BITN_AND_OUTV_;


void SRN5(uint8_t w){ //00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse)

    // INSERT!
    BINROUTE_;
    if (gate[w].trigger)	  bitrr=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
    else bitrr=!((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
    bitn=bitn|bitrr;
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN6(uint8_t w){

    // INSERT!
    if (gate[w].trigger){
      BINROUTE_;
    }
    else {
      bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN7(uint8_t w){

    // INSERT!
    if (gate[w].trigger){
      BINROUTE_;
    }
    else {
      bitn=!(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }	
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN8(uint8_t w){

    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]){
      BINROUTEANDCYCLE_;
    }
    else {
      bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
      if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    }	
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN10(uint8_t w){ // **

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
    
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN11(uint8_t w){

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
      if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
      BITN_AND_OUTV_;

void SRN12(uint8_t w){       // XX - we XOR on STROBE our shift with the GHOST

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
    
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN13(uint8_t w){ //00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ?? -- 9 below

    // INSERT!
	BINROUTE_;
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[daccount][w]].dac)){
	  bitrr=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
	}
	else bitrr=!((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
	bitn=bitn|bitrr;
    PULSIN_XOR;
    
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN14(uint8_t w){ //	01 2-BITIN or loopback

    // INSERT!
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[daccount][w]].dac)){
	  BINROUTE_;
	}
	else {
	  bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
	}		//
	PULSIN_XOR;
    
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN15(uint8_t w){

    // INSERT!
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[daccount][w]].dac)){
	  BINROUTEANDCYCLE_;
	}
	else {
	  bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
	}	
    PULSIN_XOR;
    
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN21(uint8_t w){ // triadex inspired mode where we XOR in bits from the other SRs CASE 21

    // INSERT!
    bitn = (gate[others[w][0]].Gshift_[w]>>SRlength[others[w][0]]) & 0x01; 
    gate[others[w][0]].Gshift_[w]=(gate[others[w][0]].Gshift_[w]<<1)+bitn;

    bitnn = (gate[others[w][1]].Gshift_[w]>>SRlength[others[w][1]]) & 0x01; 
    gate[others[w][1]].Gshift_[w]=(gate[others[w][1]].Gshift_[w]<<1)+bitnn;

    bitnnn = (gate[others[w][2]].Gshift_[w]>>SRlength[others[w][2]]) & 0x01; 
    gate[others[w][2]].Gshift_[w]=(gate[others[w][2]].Gshift_[w]<<1)+bitnnn;
    
    //    bitn^=((gate[w].Gshift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn;
    bitn^=bitnn^bitnnn; 
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN22(uint8_t w){// as above

    // INSERT!
    bitn = (gate[others[w][0]].shift_>>SRlength[others[w][0]]) & 0x01;
    bitnn = (gate[others[w][1]].shift_>>SRlength[others[w][1]]) & 0x01;
    bitnnn = (gate[others[w][2]].shift_>>SRlength[others[w][2]]) & 0x01;

    //    bitn^=((gate[w].Gshift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn;
    bitn^=bitnn^bitnnn; 
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN29(uint8_t w){

    // INSERT!
    bitn=(gate[w].Gshift_[w]>>SRlength[w])& 0x01;
    ADCgeneric;
    if ((LFSR_[w] & 4095 )<k) { // TODO: fixED DONE
      bitn=bitn^1;
    }
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN30(uint8_t w){

    // INSERT!
    bitn=(gate[w].Gshift_[w]>>SRlength[w])& 0x01; 
    if ((gate[w].dac)<gate[dacfrom[daccount][w]].dac) { 
      bitn=bitn^1;
    }
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; 
    BITN_AND_OUTV_;

void SRN33(uint8_t w){    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)

    // INSERT!
    GGGshift_[w]=GGGshift_[w]<<1;
    BINROUTE_;    
    GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    }
    bitn=CYCl;
    PULSIN_XOR;
    BITN_AND_OUTVNOSHIFT_;

void SRN33cipher(uint8_t w){  //just copy in on strobe - so is more like 4094 storage register/out

    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    } 
    bitn=CYCl;
    PULSIN_XOR;
    BITN_AND_OUTVNOSHIFT_;

void SRN34(uint8_t w){    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)

    // INSERT!
    tmp=(gate[w].Gshift_[w]>>SRlength[w])& 0x01;
    gate[w].shift_+=tmp;
    
    GGGshift_[w]=GGGshift_[w]<<1;
    BINROUTE_;    
    GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    } 
    PULSIN_XOR;
    BITN_AND_OUTVNOSHIFT_;

void SRNsr35(uint8_t w){ // TRIADEX 2 - try with SR...

    // SR: gate[dacfrom[daccount][1]].dac we need 3+5+3+5 bits=16 x2
    tmp=(gate[dacfrom[daccount][w]].dac);
    
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
    
    bitn^=((gate[w].Gshift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn^bitnnnn; 
    
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN35(uint8_t w){ // TRIADEX 2

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
    
    bitn^=((gate[w].Gshift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn^bitnnnn; 
    
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN36(uint8_t w){ // pulse triggers exchange between ghost and real

    }
    GSHIFT_;
    BINROUTE_;    
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN38(uint8_t w){// pass through or cycle is toggled by clkin bit

    // INSERT!
    if (gate[w].trigger) tug[w]^=1; // tuggle
    
    if (tug[w]) {
      bitn=(gate[w].Gshift_[w]>>SRlength[w])& 0x01;  // cycle...
      if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    }
    else {
      BINROUTE_;
    }
    
    PULSIN_XOR;    
    BITN_AND_OUTV_;

void SRN40(uint8_t w){// swap over SRs on pulse in?!! or swop in only (can swop in previous SR or another?)

    // INSERT!
    BINROUTE_;
    if (gate[w].trigger) gate[w].shift_=gate[oppose[w]].shift_; // sieve is previous one but could be opposite one
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRLLswop(uint8_t w){ // swop in or logop SR - cv and cvl ***

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



void SRN50(uint8_t w){ // GSR is masked in on trigger

    // INSERT!
    bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
    gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
    if (gate[w].trigger) gate[w].shift_&=gate[inroute[count][w]].Gshift_[w];
    
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN62(uint8_t w){ // LFSR in routed in SRs

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
      
      PULSIN_XOR;
    BITN_AND_OUTV_;

void SRN65(uint8_t w){// SR in SR with strobe as barrier? only for itself or for incoming/itself

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
    
    PULSIN_XOR;
    BITN_AND_OUTV_;

void SRNwas13(uint8_t w){ //pulse changes which bit ofghostSR we access - pulse moves on bit

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

	  PULSIN_XOR;
    BITN_AND_OUTV_;



void SRmod(uint8_t w){ // modulo route in SR

  
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;  
    // we modulo our SR with routed ins
    // INSERT!
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

void SRbumproute(uint8_t w){ // trigger bumps up our local route - add one to this (what value) - gate[0].route

  // no strobe bit in
  //  BINROUTE_; // new routing in here.
      // INSERT!
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

void SRLLbumproute(uint8_t w){ // trigger bumps up our local route - add one to this (what value) - gate[0].route - DETACH ALL

  // no strobe bit in
  //  BINROUTE_; // new routing in here.
      // INSERT!
  tmp=(CV[w]>>8);
  tmpp=(CVL[w]>>8);
  if (tmp<=tmpp){
  if (gate[w].trigger) gate[w].route++;
  if (gate[w].route>tmpp) gate[w].route=tmp;
  }
  else
    {
  if (gate[w].trigger) gate[w].route--;
  if (gate[w].route<tmpp) gate[w].route=tmp;
    }
  
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


void SRDACroutestrobe(uint8_t w){ // strobe decides if we change local routing table

  //  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
      // INSERT!
  if (gate[w].trigger){
  tmp=gate[dacfrom[daccount][w]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else BINROUTE_;
  PULSIN_XOR;
  BITN_AND_OUTV_; // with pulses

void SR32(uint8_t w){ // multiple bits in as case 19 in draftdec
    // INSERT!
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


void SRLcvroute(uint8_t w){ // CV: 4 bits for route in... other bits for logop
    // INSERT!
    tmp=255-(CVL[w]>>4); // 8 bits
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


void SRLcvSRmaskroute(uint8_t w){ // CV: 4 bits for route in... other bits for logop
    // INSERT!
    tmp=(255-(CVL[w]>>4)) & DACFROM; // other logics // 8 bits
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


void SRBITMIX(uint8_t w){ // NO LENGTH NOR SPEEDS //- TODO: how to mix between CV control of bits and SR/DAC control - as we need 2 CVs (mix and CV) - detach both (in CV mode or one in intmode)
    // INSERT!
    tmp=255-(CV[w]>>4); // 8 bits
    mixer=1.0f/((float)(CVL[w]>>4)+1.0f);
    mixer*=(float)(gate[dacfrom[daccount][w]].dac>>4);
    // how to mix with DAC using CVL - gate[dacfrom[daccount][w]].dac
    tmp+=(int)mixer;
    if (tmp>255) tmp=255;
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
    PULSIN_XOR;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

