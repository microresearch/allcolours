void bitSRroutelog(uint8_t w){ // SR: 4 bits for route in... other bits for logop

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

void bitSRroutelogxx(uint8_t w){ // SR: 4 bits for route in... other bits for logop - try changing srfrom

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

void bitLcvsrroute(uint8_t w){ // simpler routing and cv also selects dacfrom as well as maskings

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

void bitSRroutelogxxx(uint8_t w){ // recursive use of dacfrom SR: 4 bits for route in... other bits for logop - try changing srfrom

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

void bitSRroutedoit(uint8_t w){ // SR: 4 bits for route in, doit options and prob of inversion

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

void bitLSRlen(uint8_t w){

    tmpp=(CVL[w]>>6)&0x03;
    tmp=gate[tmpp].shift_&31;    
    SRlength[w]=lookuplenall[tmp]; // 5 bits

    tmp=(CVL[w]>>8); // 4 bits
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

void bitSRlen(uint8_t w){

    tmp=gate[dacfrom[daccount][w]].shift_&31;
    tmp=tmp&(31-(CVL[w]>>7));// 5 bits
    SRlength[w]=lookuplenall[tmp]; // 5 bits
    BINROUTE_; // or route and cycle
    PULSIN_XOR;
    BITN_AND_OUTV_;

void bitLDACSEL0(uint8_t w){

    BINROUTE_; // cycle etc... - could be more complex here as we have spare bits - so could even route in
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp

void bitLcvtyperoute(uint8_t w){ // CVL sets temporary local dactype - now with routings - 8 bits

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

void bitLBITdactyperoute(uint8_t w){ // CVL and dacfrom set temporary local dactype - now with routings - 8 bits

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

void bitLBITlengthdactype(uint8_t w){ //sets length and dactype - so we have spare CV to logop in

    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVDACT_; // for pulse out and local dactype in tmp

void bitLSRroutexxxlog(uint8_t w){ // SR: 4 bits for route in... 8 other bits for logop PLUS logopxxx for maskings

    tmp=logopxxx((CVL[w]&255),(SRFROM)&255, (SRFROM>>8)&0x03); 
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

    
