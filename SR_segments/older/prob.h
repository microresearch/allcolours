/*
prob/STROBE for CLN: 1invert routed
                2routed vs cycling
		3routed vs [routed^cycling]

- pulsebit is often 0 so...
*/

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
      JUSTCYCLE;
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

