// modeL as model but generic as possible

/*
prob/STROBE for CLN: 1invert routed
                2routed vs cycling
		3routed vs [routed^cycling]
*/

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

void Lintgenericprob0(void){
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
    bit=gate[dacfrom[daccount][w]].dac&31; // 5 bits - could also be extra bits for logical ops
    lower=bit&0x03;
    bit=(bit>>2)*3;

    tmp=LFSR_[w]&4095;
    tmpp=4095-CV[w]; // which way round

    if (tmp<tmpp) bitn=prob[lower]; // lowest 2 bits
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
    bit=CV[w]&31; // 5 bits
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
    bit=CV[w]&31; // 5 bits
    lower=bit&0x03;
    bit=(bit>>2)*3;

    tmp=adc_buffer[12]&4095; // this could also be selected by bits
    tmpp=gate[dacfrom[daccount][w]].dac&4095;

    if (tmp<tmpp) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}

/// prob modes for N which split off length and select ADC
// can also comp to dac

/*
INTmodes:
LFSR<CV
LFSR<DAC
LFSR<DAC+CV
LFSR<ADC_buffer[12]

SRown<CV - own ghost SR: gate[w].Gshift_[w] 
SRown<DAC
SRown<CV_DAC
SRown<SRincoming
*/


void NLintprob1(void){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  uint8_t w=0;				       
  HEADSSINNADA; // we don;t need  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    if (((LFSR_[0] & 4095 ) > CV[0])){
      BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprobdac1(void){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  uint8_t w=0;				       
  HEADSSINNADA; // we don;t need  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    if (((DACFROM & 4095 ) > CV[0])){
      BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}


void NLintprob2(void){   // but is more flexible if is outside 
  // prob is choice of ADC or routed in bit only
  uint8_t w=0;				       
    HEADSSINNADA; ;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    }
    else
      {
    BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprob3(void){   // but is more flexible if is outside so we can change modes
  // - prob of invert or not routed in bit XOR/OR with ADC = same as invert ADC bit
  uint8_t w=0;				       
    HEADSSINNADA; ;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    if (((LFSR_[0] & 4095 ) > CV[0])){
    bitn=!bitn;
      }
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprob4(void){ // prob of adc/X/ORroute or just cycling - just for abstract modes
  uint8_t w=0;				       
    HEADSSINNADA; ;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprob5(void){ // electronotes draft0 // can also use incoming SR instead of LFSR
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  uint8_t w=0;				       
  HEADSSINNADA; ;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[0] & 4095 ) < CV[0])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[0]&255) & ((CV[0]>>4)&255)) == 255 ){
    
    tmp=255-(CV[0]>>4);
    if ( ( ( ((LFSR_[0]&1)>>0) + ((LFSR_[0]&4)>>1) + ((LFSR_[0]&32)>>3) + ((LFSR_[0]&262144)>>15) + ((LFSR_[0]&16384)>>10) + ((LFSR_[0]&131072)>>12) + ((LFSR_[0]&524288)>>13) + ((LFSR_[0]&2097152)>>14)) | tmp)==255){
    
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

