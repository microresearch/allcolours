// modeL as model but generic as possible

// *prob/STROBE for CLN: invert routed*
//                *routed vs cycling*
//		*routed vs [routed^cycling]*

// from modeN port in probs and electronotes for these...DONE

void Lintprob1(void){  // 1invert routed
  uint8_t w=1;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR; // before or after inversion
    if (((LFSR_[1] & 4095 ) < CV[1])) bitn=!bitn;
    BITN_AND_OUTVINT_; 
  } 
}

void Lintprob2(void){  
  uint8_t w=1;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[1] & 4095 ) > CV[1])){
      PULSIN_XOR; // here or at end?
      BINROUTE_;
      }
    else {
      JUSTCYCLE_;
    }
    BITN_AND_OUTVINT_; 
  } 
}

void Lintprob3(void){  
  uint8_t w=1;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[1] & 4095 ) < CV[1])){
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

void Lintprob5_0(void){ // electronotes draft0 // can also use incoming SR instead of LFSR
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  uint8_t w=1;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[1] & 4095 ) < CV[1])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[1]&255) & ((CV[1]>>4)&255)) == 255 ){
    
    tmp=255-(CV[1]>>4);
    if ( ( ( ((LFSR_[1]&1)>>0) + ((LFSR_[1]&4)>>1) + ((LFSR_[1]&32)>>3) + ((LFSR_[1]&262144)>>15) + ((LFSR_[1]&16384)>>10) + ((LFSR_[1]&131072)>>12) + ((LFSR_[1]&524288)>>13) + ((LFSR_[1]&2097152)>>14)) | tmp)==255){
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

void Lintprob6_0(void){ // INVERT - electronotes draft0 // use incoming SR instead of LFSR - also no route in *** // can be lfsr against shift also***
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  uint8_t w=1;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    //    if (((LFSR_[1] & 4095 ) < CV[1])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[1]&255) & ((CV[1]>>4)&255)) == 255 ){
    // LFSR_[1]->gate[inroute[count][1]].shift_
    tmp=255-(CV[1]>>4);
    if ( ( ( ((gate[inroute[count][1]].shift_&1)>>0) + ((gate[inroute[count][1]].shift_&4)>>1) + ((gate[inroute[count][1]].shift_&32)>>3) + ((gate[inroute[count][1]].shift_&262144)>>15) + ((gate[inroute[count][1]].shift_&16384)>>10) + ((gate[inroute[count][1]].shift_&131072)>>12) + ((gate[inroute[count][1]].shift_&524288)>>13) + ((gate[inroute[count][1]].shift_&2097152)>>14)) | tmp)==255){
      bitn=!bitn;
    }

    BITN_AND_OUTVINT_; 
  } 
}

void Lintprobdac1_0(void){ // example - as prob1 above but against DAC
  // prob is choice of ADC or ADC XOR routed in bit
  uint8_t w=1;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if ((gate[dacfrom[daccount][w]].dac)>CV[1]) {
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
void Ltempst(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    
    //    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// convert to tug/toggle

void Ltoggle1(void){
  uint8_t w=1; uint8_t prob;
  static uint8_t tug[4]={0};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) bitn=!bitn; 
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Ltoggle2(void){
  uint8_t w=1; uint8_t prob;
  static uint8_t tug[4]={0};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTE_;
    }
    else JUSTCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Ltoggle3(void){
  uint8_t w=1; uint8_t prob;
  static uint8_t tug[4]={0};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTE_;
    }
    else BINROUTEANDCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Ltoggle4(void){ // new one for ZERO entry
  uint8_t w=1; uint8_t prob;
  static uint8_t tug[4]={0};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTE_;
      PULSIN_XOR; // can also be inside/outside
    }
    else bitn=0;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Ltoggle5(void){ // new one for ZERO entry against binroute/cycling
  uint8_t w=1; uint8_t prob;
  static uint8_t tug[4]={0};
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTEANDCYCLE_;
      PULSIN_XOR; // can also be inside/outside
    }
    else bitn=0;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

////////////////////

void Lstrobe1(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    if (gate[w].trigger) bitn=!bitn; 
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Lstrobe2(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) {
      BINROUTE_;
    }
    else JUSTCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void Lstrobe3(void){
  uint8_t w=1; uint8_t prob;
  HEADL;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    if (gate[w].trigger) {
      BINROUTE_;
    }
    else BINROUTEANDCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

//////////////////////////////////////////////////////////////

/*
left side: LFSR, SRown,  
right side: CV, CV+DAC

LFSR<CV
  LFSR<DAC
LFSR<DAC+CV
  LFSR<ADC_buffer[12]

SRown<CV - own ghost SR: gate[w].Gshift_[w] 
  SRown<DAC
SRown<CV+DAC
  SRown<SRincoming
*/
// for 3x sets of options=12 which is too many - try them tho

//////////////////////////////////////////////////////////////

////// bits/options for probabilities:
/*
1ROUTED, 2RETURN, 3PULSBIT/whichcanbe0, 4NADA0 
for  modeN: 1ADCBIT, 2ROUTED, 3RETURN, 4NADA and inversion of first three: x bits XOR/OR/LOGOP x bits

X vs Y: options

1 vs 2, 3, 4, 2^1, 3^1, 3^2, 1^2^3 // and can be XOR or OR // and inv of each above - 7 options - how to make 8 1 vs 1 so no comp
2 vs 1, 3, 4, 
3 vs 1, 2, 4
4 vs 1, 2, 3

= 18 options/leaving out inv/xor/or options
*/

// first is 1,2,3 2 bits
// how to use bits to calculate... array... is now in draftspeed
/*    uint32_t options[4][24]={
      {1,3,3, 2,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 0,3,3},
      {0,3,3, 2,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 1,3,3},
      {0,3,3, 1,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 2,3,3},
      {0,3,3, 1,3,3, 2,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 3,3,3}
    };
*/

void Lintgenericprob0(void){ // TODO: can also be on trigger!
  uint8_t w=1;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADL;  

  if (gate[w].trigger)      {
    GSHIFT_;

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

void Lintgenericprobx(void){
  uint8_t w=1;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  uint32_t left[2]={0}; uint32_t right[2]={0};
  HEADL;  

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
    tmp=(bitn>>2)&1;
    tmpp=(bitn>>3)&1;
    bit=(bit>>4)*3;

    if (left[tmp]<right[tmpp]) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Lintgenericprobxxx(void){ // try to combine with 4 bits for route
  uint8_t w=1;
  uint32_t tmpp, bit, topbit, lower;
  uint32_t prob[4]={0};
  uint32_t left[2]={0}; uint32_t right[2]={0};
  HEADL;  

  if (gate[w].trigger)      {
    GSHIFT_;
    // 4 bits route+7 bits below = 11 bits = 
    // bit is 8 x 3 - 5 bits + 2 bits
    topbit=(gate[dacfrom[daccount][w]].dac&2047)>>7; // 4 bits from top for routings
    bit=topbit&127;
    lower=bit&0x03;
    tmp=(bitn>>2)&1;
    tmpp=(bitn>>3)&1;
    bit=(bit>>4)*3;

    for (x=0;x<4;x++){ 
      if ((topbit&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(topbit)&0x03);
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


void Lintgenericprobxx(void){ // uses CVL for bits
  uint8_t w=1;
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
    tmp=(bitn>>2)&1;
    tmpp=(bitn>>3)&1;
    bit=(bit>>4)*3;

    if (left[tmp]<right[tmpp]) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Lintgenericprob1(void){ // reverse so dac is prob and cv is bits
  uint8_t w=1;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADL;  

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

void Lintgenericprob2(void){ // adc[12] is prob and cv is bits
  uint8_t w=1;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADL;  

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

    tmp=adc_buffer[12]&4095; // this could also be selected by bits
    tmpp=gate[dacfrom[daccount][w]].dac&4095;

    if (tmp<tmpp) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

void Lgenericprobx(void){ // porting to strobe - ported to N
  uint8_t w=1;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADL;  

  if (speedf_[w]!=2.0f){ 
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
    ENDER;
} 
}


