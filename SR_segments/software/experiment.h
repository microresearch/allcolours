// 8/4/2022

// wheeling probability function
// but to make use of this we need next one to use incoming as prob of adc or route from top
// so needs some sync - is question across all of new idea of functions
void SRprobwheel(uint8_t w){ // new detached mode with prob wheel as generator only // for L
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w];
  bitn=ADC_(w,SRlength[w],113,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_);
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// eg. test this with basic modeN which uses binroute for loop or route in from top // for C - seems to workings
void dacNbinprob(uint8_t w){ 
  gate[w].dactype=0; gate[w].dacpar=param[w];
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    if (bitn){
      bitn=0;
      // route from 1
      bitrr = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
      gate[0].Gshift_[w]=(gate[0].Gshift_[w]<<1)+bitrr;
      bitn^=bitrr;
    }
    else
      {
	bitn=0;
	JUSTCYCLE_;
      }
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// no gshifts: adc0nog, SRR0nog, same as SR0nog and from modeC: dac67_4bitsNOGG - length has less to do
// do we have options to say strobe/toggle/prob in/out the gshifter? TODO:

// as: SR0nogstrobe, SR0nogtoggle, SRLprobnog, SRintprobnog DONE

void SR0nogstrobe(uint8_t w){ // basic route in no GSHIFT<< strobed
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (STR0) { // macro now for strobe/trigger
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void SR0nogtoggle(uint8_t w){ // basic route in no GSHIFT<< toggles
  HEAD;
  static uint8_t toggle[4]={0,0,0,0};
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (STR0){
      toggle[w]^=1;
    }
    if (toggle[w]) {
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// and finally prob from CVL - detached... - and can also be an intmode TODO

void SRLprobnog(uint8_t w){
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void SRintprobnog(uint8_t w){  // intmode
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    // HERE
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  } 
}

// don't move at all... xor etc one Sr against another....// and what does length do...
// trial

//*what elements can be used from delta sigma*
// signal input is binroute, subtract cycle bit and pass bits via integrator/comp
//trial - what other functions could be?? bit filter, logic?

void SRsigma(uint8_t w){ 
  HEAD;
  int32_t cycle;
  static int32_t integrator;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_;
  if (bitn) val=1;
  else val=-1;
  if (CYCl) cycle=1;
  else cycle=-1;
  
  integrator+=(val-cycle);
  if (integrator>0) bitn=1;
  else bitn=0;
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// unmoving XOR on strobe - parallel streams - we can have 4 unmoving copy across SRs - they are not SRs... 

/*
void noSRproto(uint8_t w){
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }
*/

// masks to do - but they are also not bitstreams...

// trial 12 bits of adc in 
void noSRadc(uint8_t w){
  HEAD; uint32_t k;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  ADCgeneric;
  if (SRlength[w]>11) k=k<<(SRlength[w]-11);
  gate[w].shift_=k;
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_^=tmp;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }

// and 12 bits out dac
void noSRdac(uint8_t w){ 
  HEAD;
  gate[w].dactype=69; gate[w].dacpar=param[w];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_;
    tmp=(gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]]);
    gate[w].shift_=tmp;
    BITN_AND_OUTVNOSHIFT_; 
    ENDER;
  }
  }
}

void noSRcopy(uint8_t w){ // copy in with mask of length
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  // copy mask of bits from inroute
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_=tmp;
  PULSIN_XOR;
  gate[w].shift_^=bitn; // where do we put pulse bits? - not much happening
  BITN_AND_OUTVNOSHIFT_;  
  ENDER;
  }
  }
  }


// parity plays

