void SRINquestion0(uint8_t w){ // NO LENGTH NOR SPEEDS - length is now bits, speed is now cv for - we use strobe here!

    // CVL as bits CV as prob
    tmp=CVL[w]>>8; // 4 bits?
    tmpp=tmp&3;
    if (tmpp==0){// strobe
      if (gate[w].trigger) {
	BINROUTE_;
      }
      else
	{
	JUSTCYCLE_;
	}
    }
    else if (tmpp==1){ // toggle
      if (gate[w].trigger) toggle^=1;
      if (toggle) {
	BINROUTE_; // could use extra bits for route
      }
      else {
	JUSTCYCLE_;
      }
    }
    else if (tmpp==2) { //bits from + 2 bits from
      bit=(tmp>>2)&3;
      if ( (gate[bit].Gshift_[w]>>SRlength[bit]) & 0x01) {
	BINROUTE_; // could use extra bits for route
      }
      else {
	JUSTCYCLE_;
      }      
    }
    else { // deal with probability - how many bits do we have? 2 so is all 4 bits long
      bit=(tmp>>2)&3;

      tmp=(bit)&1;
      tmpp=(bit>>1)&1;

      left[0]=LFSR_[w]&4095; left[1]=gate[w].Gshift_[w]&4095; 
      right[0]=4095-CV[w]; right[1]=right[0]+(gate[dacfrom[daccount][w]].dac&4095);

      if (left[tmp]<right[tmpp]) 	{ // could use one bit to invert?
	BINROUTE_;
      }
      else {
	JUSTCYCLE_;
      }
    }
    
    PULSIN_XOR;
    BITN_AND_OUTV_;

void probintprob1(uint8_t w){  // 1invert routed

    BINROUTE_;
    PULSIN_XOR; // before or after inversion
    if (((LFSR_[w] & 4095 ) < CV[w])) bitn=!bitn;
    BITN_AND_OUTVINT_; 
  } 
}

void probintprob2(uint8_t w){  // route or cycling
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[w] & 4095 ) > CV[w])){
      BINROUTE_;
      }
    else {
      JUSTCYCLE_;
    }
    PULSIN_XOR; // here or at end?
    BITN_AND_OUTVINT_; 
  } 
}

void probintprob3(uint8_t w){  // routed vs routed_cycling
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[w] & 4095 ) < CV[w])){
    BINROUTE_;
    }
    else
      {
    BINROUTEANDCYCLE_;
      }
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  } 
}

void probintprob5_0(uint8_t w){ // electronotes draft0 // can also use incoming SR instead of LFSR
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[w] & 4095 ) < CV[w])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[w]&255) & ((CV[w]>>4)&255)) == 255 ){
    tmp=prub[CV[w]>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255){

    
    //    tmp=255-(CV[w]>>4);
    //    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&262144)>>15) + ((LFSR_[w]&16384)>>10) + ((LFSR_[w]&131072)>>12) + ((LFSR_[w]&524288)>>13) + ((LFSR_[w]&2097152)>>14)) | tmp)==255){
    PULSIN_XOR;
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
    BITN_AND_OUTVINT_; 
  } 
}

void probintprob6_0(uint8_t w){ // INVERT - electronotes draft0 // use incoming SR instead of LFSR - also no route in *** // can be lfsr against shift also***
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    //    if (((LFSR_[1] & 4095 ) < CV[1])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[1]&255) & ((CV[1]>>4)&255)) == 255 ){
    // LFSR_[1]->gate[inroute[count][1]].shift_
    //    tmp=255-(CV[w]>>4);
    //    if ( ( ( ((gate[inroute[count][w]].shift_&1)>>0) + ((gate[inroute[count][w]].shift_&4)>>1) + ((gate[inroute[count][w]].shift_&32)>>3) + ((gate[inroute[count][w]].shift_&262144)>>15) + ((gate[inroute[count][w]].shift_&16384)>>10) + ((gate[inroute[count][w]].shift_&131072)>>12) + ((gate[inroute[count][w]].shift_&524288)>>13) + ((gate[inroute[count][w]].shift_&2097152)>>14)) | tmp)==255){
    tmp=prub[CV[w]>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255){    
      bitn=!bitn;
    }

    BITN_AND_OUTVINT_; 
  } 
}

void probintprobdac1_0(uint8_t w){ // example - as prob1 above but against DAC
  // prob is choice of ADC or ADC XOR routed in bit
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if ((gate[dacfrom[daccount][w]].dac)>CV[w]) {
    BINROUTE_;
    PULSIN_XOR;
    }
    else {
      JUSTCYCLE_;
    }
    BITN_AND_OUTVINT_; 
  } 
}

///

// strobes in modeL/CV modes

// template 
void probtempst(uint8_t w){
uint8_t prob;
  HEAD;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_;

void probtoggle1(uint8_t w){

    // INSERT!
    BINROUTE_;
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) bitn=!bitn; 
    PULSIN_XOR;
    BITN_AND_OUTV_;

void probtoggle2(uint8_t w){

    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTE_;
    }
    else JUSTCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;

void probtoggle3(uint8_t w){

    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTE_;
    }
    else BINROUTEANDCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;

void probtoggle4(uint8_t w){ // new one for ZERO entry

    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTE_;
      PULSIN_XOR; // can also be inside/outside
    }
    else bitn=0;
    BITN_AND_OUTV_;

void probtoggle5(uint8_t w){ // new one for ZERO entry against binroute/cycling

    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTEANDCYCLE_;
      PULSIN_XOR; // can also be inside/outside
    }
    else bitn=0;
    BITN_AND_OUTV_;

void probstrobe1(uint8_t w){

    // INSERT!
    BINROUTE_;
    if (gate[w].trigger) bitn=!bitn; 
    PULSIN_XOR;
    BITN_AND_OUTV_;

void probstrobe2(uint8_t w){

    // INSERT!
    if (gate[w].trigger) {
      BINROUTE_;
    }
    else JUSTCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;

void probstrobe3(uint8_t w){

    // INSERT!
    if (gate[w].trigger) {
      BINROUTE_;
    }
    else BINROUTEANDCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;

void probintgenericprob0(uint8_t w){ // TODO: can also be on trigger!


    BINROUTE_;
    prob[0]=bitn; // route
    prob[1]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[2]=!(GPIOC->IDR & pulsins[w]); // pulse but this is not in C - we don't use generic mode there
    prob[3]=0;
    
    // bit is 8 x 3 - 5 bits
    bit=gate[dacfrom[daccount][w]].dac&31; // 5 bits - could also be extra bits for logical ops - can also be SRFROM
    lower=bit&0x03;
    bit=(bit>>2)*3;

    tmp=LFSR_[w]&4095;
    tmpp=4095-CV[w]; // which way round

    if (tmp<tmpp) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

//left side: LFSR, SRown - could also have SRany but...  
//right side: CV, CV+DAC

void probintgenericprobx(uint8_t w){
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  uint32_t left[2]={0}; uint32_t right[2]={0};
  HEAD;  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=bitn; // route
    prob[1]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[2]=!(GPIOC->IDR & pulsins[w]); // pulse but this is not in C - we don't use generic mode there
    prob[3]=0;

    left[0]=LFSR_[w]&4095; left[1]=gate[w].Gshift_[w]&4095; 
    right[0]=4095-CV[w]; right[1]=right[0]+(gate[dacfrom[daccount][w]].dac&4095);
    if (right[1]>4095) right[1]=4095;
    // bit is 8 x 3 - 5 bits + 2 bits
    bit=gate[dacfrom[daccount][w]].dac&127; // 2+5 bits //- could also be extra bits for logical ops
    lower=bit&0x03;
    tmp=(bit>>2)&1;
    tmpp=(bit>>3)&1; // fixed
    bit=(bit>>4)*3;

    if (left[tmp]<right[tmpp]) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void probLintgenericprobx(uint8_t w){ // as above but use CVL to select dacfrom/2 bits and mask 
  uint32_t tmpp, bit, lower, other;
  uint32_t prob[4]={0};
  uint32_t left[2]={0}; uint32_t right[2]={0};
  HEAD;  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=bitn; // route
    prob[1]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[2]=!(GPIOC->IDR & pulsins[w]); 
    prob[3]=0;

    other=CVL[1]>>3; // 7 bits plus 2 bits = 9 bits
    
    left[0]=LFSR_[w]&4095; left[1]=gate[w].Gshift_[w]&4095; 
    right[0]=4095-CV[w]; right[1]=right[0]+(gate[other&0x03].dac&4095);
    if (right[1]>4095) right[1]=4095;
    // bit is 8 x 3 - 5 bits + 2 bits
    bit=(gate[other&0x03].dac&127) & (other>>2); // 2+5 bits //- could also be extra bits for logical ops
    lower=bit&0x03;
    tmp=(bit>>2)&1;
    tmpp=(bit>>3)&1; // fixed
    bit=(bit>>4)*3;

    if (left[tmp]<right[tmpp]) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}


void probintgenericprobxxx(uint8_t w){ // try to combine with 4 bits for route
  uint32_t tmpp, bit, topbit, lower;
  uint32_t prob[4]={0};
  uint32_t left[2]={0}; uint32_t right[2]={0};
  HEAD;  

  if (gate[w].trigger)      {
    GSHIFT_;
    // 4 bits route+7 bits below = 11 bits = 
    // bit is 8 x 3 - 5 bits + 2 bits
    topbit=(gate[dacfrom[daccount][w]].dac&2047);
    bit=topbit&127;// 7 bits now
    lower=bit&0x03;
    tmp=(bit>>2)&1; // fixed
    tmpp=(bit>>3)&1;
    bit=(bit>>4)*3;

    topbit=topbit>>7; // 4 bits from top for routings
    for (x=0;x<4;x++){ 
      if ((topbit&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopxxx(bitn,bitrr,(topbit)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      topbit=topbit>>2; // 4 bits
    }
    
    prob[0]=bitn; // route
    prob[1]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[2]=!(GPIOC->IDR & pulsins[w]); // pulse but this is not in C - we don't use generic mode there
    prob[3]=0;

    left[0]=LFSR_[w]&4095; left[1]=gate[w].Gshift_[w]&4095; 
    right[0]=4095-CV[w]; right[1]=right[0]+(gate[dacfrom[daccount][w]].dac&4095);
    if (right[1]>4095) right[1]=4095;

    if (left[tmp]<right[tmpp]) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}


void probintgenericprobxx(uint8_t w){ // uses CVL for bits
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  uint32_t left[2]={0}; uint32_t right[2]={0};
  HEADSSINNADA; // detach all  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=bitn; // route
    prob[1]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[2]=!(GPIOC->IDR & pulsins[w]); // pulse but this is not in C - we don't use generic mode there
    prob[3]=0;

    left[0]=LFSR_[w]&4095; left[1]=gate[w].Gshift_[w]&4095; 
    right[0]=4095-CV[w]; right[1]=right[0]+(gate[dacfrom[daccount][w]].dac&4095);
    if (right[1]>4095) right[1]=4095;
    // bit is 8 x 3 - 5 bits + 2 bits
    bit=CVL[0]&127; // 2+5 bits //- could also be extra bits for logical ops
    lower=bit&0x03;
    tmp=(bit>>2)&1; // fixed
    tmpp=(bit>>3)&1;
    bit=(bit>>4)*3;

    if (left[tmp]<right[tmpp]) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void probintgenericprob1(uint8_t w){ // reverse so dac is prob and cv is bits
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEAD;  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=bitn; // route
    prob[1]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[2]=!(GPIOC->IDR & pulsins[w]); // pulse but this is not in C - we don't use generic mode there
    prob[3]=0;
    
    // bit is 8 x 3 - 5 bits
    //    bit=gate[dacfrom[daccount][w]].dac&31; // 5 bits
    bit=CV[w]>>7; // 5 bits
    lower=bit&0x03;
    bit=(bit>>2)*3;

    tmp=LFSR_[w]&4095; // this could also be selected by bits
    tmpp=gate[dacfrom[daccount][w]].dac&4095;

    if (tmp<tmpp) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void probintgenericprob2(uint8_t w){ // adc[12] is prob and cv is bits
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEAD;  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=bitn; // route
    prob[1]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[2]=!(GPIOC->IDR & pulsins[w]); // pulse but this is not in C - we don't use generic mode there
    prob[3]=0;
    
    // bit is 8 x 3 - 5 bits
    //    bit=gate[dacfrom[daccount][w]].dac&31; // 5 bits
    bit=CV[w]>>7; // 5 bits
    lower=bit&0x03;
    bit=(bit>>2)*3;

    //    tmp=adc_buffer[12]&4095; // this could also be selected by bits - TODO_FIX!
    tmpp=gate[dacfrom[daccount][w]].dac&4095;

    if (tmp<tmpp) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void probgenericprobx(uint8_t w){ // porting to strobe - ported to N
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEAD;  

  if (speedf_[w]!=LOWEST){ 
    CVOPEN;

    GSHIFT_;
    BINROUTE_;
    prob[0]=bitn; // route
    prob[1]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[2]=!(GPIOC->IDR & pulsins[w]); // pulse but this is not in C - we don't use generic mode there
    prob[3]=0;

    // bit is 8 x 3 - 5 bits + 2 bits
    bit=gate[dacfrom[daccount][w]].dac&31; 
    lower=bit&0x03;
    bit=(bit>>2)*3;

    if (gate[w].trigger) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
        BITN_AND_OUTV_;

	
