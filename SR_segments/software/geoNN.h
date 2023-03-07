// NN new N top ADC:

// rework 23/2

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

// check? //??? inner abstract function, inner dacfunction, inner mixfunction and gapped versions of these with probabilities

void SR_geo_inner_norouteadcN(uint32_t w){  // new template
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3xnorouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3xxnorouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac34(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3xxrouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac34(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3xrouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}




void SR_geo_inner_adcprobzero(uint32_t w){  
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
      }
      else {
	bitn = 0;
      }
	  
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_adcprobzeronod(uint32_t w){  
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    if (!(*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
      }
      else {
	bitn = 0;
      }
	  
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcentry(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    
    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      if (w==3) bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
      else bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    }
      
    else bitn=binroutesel0(0,0,w); // theroute which is ... and routetype
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcentrynod(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    
    if ((*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    }
      
    else bitn=binroutesel0(0,0,w); // theroute which is ... and routetype
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcentryxor(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=binroutesel0(0,0,w); // theroute which is ... and routetype
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcentryxornod(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    if (!(*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=binroutesel0(0,0,w); // theroute which is ... and routetype
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcburst(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    
    if ((*probf_anystrobe_forNN_depth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    }      
    else bitn=binroutesel0(0,0,w); // theroute which is ... and routetype
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcentryxorX(uint32_t w){  
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcentryxorXnod(uint32_t w){  
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    if (!(*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rungnoroute(uint32_t w){  
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// prob of reset
void SR_geo_inner_probadcreset(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; 
	  bitn=(*padcfromsd[gate[w].matrix[7]>>6])(gate[w].matrix[8], ADCin, w, 1, 1); 
	}
    else
      {
	ADCgeneric2; 
	bitn=(*padcfromsd[gate[w].matrix[7]>>6])(gate[w].matrix[8], ADCin, w, 0, 1); 
      }    
    //    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// prob of advance 
void SR_geo_inner_probadcadvance(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
    ADCgeneric2;
    bitn=(*padcfromsd[gate[w].matrix[7]>>6])(gate[w].matrix[8], ADCin, w, 0, 1);
    }
    else
      {
	ADCgeneric2; 
	bitn=(*padcfromsd[gate[w].matrix[7]>>6])(gate[w].matrix[8], ADCin, w, 0, 0); 
      }
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_innerxorNN(uint32_t w){  // xor with fixed route
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ( (*speedfromcvforxor[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w) ^ zbinroutfixed_noshift(0,0,w) ){ // speedfunc xor with fromforxor->binroutfixed...
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rungN(uint32_t w){ 
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


// OUTERS
////////////////////////////////////////////////////////////////////////////////////////////////
//0.0//////// no routes in

// rework these for new adc scheme 23/2

void SR_geo_outer_N00(uint32_t w){ // set adctype // no route in
  if (gate[w].changed==1) {
    RESETN; // added 21/12 only reset on change
    gate[w].changed=0;
  }
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[7]=CVL[w]; // adctype
    gate[w].inner=SR_geo_inner_norouteadcN; 
}

void SR_geo_outer_N01(uint32_t w){ // set adc depth // fixed route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[8]=CVL[w]; // adc depth also for abstr//cats // but should also be mix
  gate[w].inner=SR_geo_inner_globalC; //
  }
}

void SR_geo_outer_N02(uint32_t w){ // set adc depth // fixed route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_globalC; //
  }
}

void SR_geo_outer_N03(uint32_t w){ // 1-prob of ADC entry or fixed route entry  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<6; // probbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probadcentry;// fixed as probbits and fixed entry
}
}

void SR_geo_outer_N03x(uint32_t w){ // 1-prob of ADC entry or fixed route entry  XOR
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<6; // probbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probadcentryxor;// fixed as probbits and fixed entry
}
}

//////////////
//1.0 params

// C10, C12, C13, C20 in that order

/////////////////////////////////////////
//// 2.0 - more probs
void SR_geo_outer_N20(uint32_t w){ // prob of entry of depthroute
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // Zbinrout_strip=0 checked
  gate[w].matrix[9]=0<<6; // select probfs - zprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w];
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 
  gate[w].inner=SR_geo_inner_probdepth; 
  }
}

void SR_geo_outer_N21(uint32_t w){ // prob of entry of depthroute XOR
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // Zbinrout_strip=0 checked
  gate[w].matrix[9]=0<<6; // select probfs - zprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w];
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 
  gate[w].inner=SR_geo_inner_probadcentryxorX; 
  }
}
// if we can rework advance and reset...
// advance
void SR_geo_outer_N22(uint32_t w){  // these are with last route in
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];

  gate[w].matrix[3]=0<<6; // Zbinrout_strip=0 checked
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 

  if ((gate[w].matrix[7]>>6)>23) { // we hit dacs or abstracts
  if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=CVL[w];
  else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=CVL[w]; // mix for dacs
  else gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_function; // 
    }
    else {
      gate[w].matrix[9]=0<<6;// 
      gate[w].matrix[10]=CVL[w];
      gate[w].inner=SR_geo_inner_probadcadvance; // advance
    }
  }
}

//reset
void SR_geo_outer_N23(uint32_t w){ 
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];

  gate[w].matrix[3]=0<<6; // Zbinrout_strip=0 checked
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 

  if ((gate[w].matrix[7]>>6)>23) {
  if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=CVL[w];
  else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=CVL[w]; // mix
  else gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_function; // 
    }
    else {
      gate[w].matrix[9]=0<<6;// 
      gate[w].matrix[10]=CVL[w];
      gate[w].inner=SR_geo_inner_probadcreset;
    }
  }
}

//3.0//////// route functions from CC
// C30->C33



//4.0////////// draft runglers for NN - how to place these in CC...

/*
rungler1: osc1 or selected gapped/abstract with speed or depth from speedfrom dac

- adc only// adc param
- select abstract
- depth abstract with route/no route
*/

//spdfrac, spdfrac, spdfracend, spdfracend, 4spdfrac1, 5spdfrac3, 6spdfrac4, spdfrac5
//- adc only// adc param or now prob route in//route cv
// adc in with prob of route in and speed - inner_functionN
void SR_geo_outer_N40(uint32_t w){ // adc in
  if (gate[w].changed==0) {
    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3/4
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[9]=0<<6; // probbits
    gate[w].matrix[10]=CVL[w]; // depth for prob
    
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=gate[dacfrom[daccount][w]].dac; 
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=gate[dacfrom[daccount][w]].dac;
    else gate[w].matrix[6]=gate[dacfrom[daccount][w]].dac;

    gate[w].inner=SR_geo_inner_probdepth;
  }
}

// select abstract/adc + route
void SR_geo_outer_N41(uint32_t w){ 
  if (gate[w].changed==0) {
    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3/4  
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[7]=CVL[w]; // sel abstract
    gate[w].inner=SR_geo_inner_rungN;
  }
}

// no route in but we did sel... 
void SR_geo_outer_N42(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3/4    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=CVL[w];
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=CVL[w]; // mix for dacs
    else gate[w].matrix[6]=CVL[w]; // length
    gate[w].inner=SR_geo_inner_rungnoroute;
  }
}

///++ trial add dac??? but what is CVL? // sel abstract
void SR_geo_outer_N43(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // spdfrac4 now
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[7]=CVL[w]; // sel abstract // 20 we like <<6
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=gate[dacfrom[daccount][w]].dac; 
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=gate[dacfrom[daccount][w]].dac;
    else gate[w].matrix[6]=gate[dacfrom[daccount][w]].dac;
    gate[w].inner=SR_geo_inner_rungnoroute;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// dacspeed runglers to keep! - and what of these with abstracts - to do in LL

// adc with no route in... SR_geo_inner_norouteadcN
void SR_geo_outer_N50(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=gate[dacfrom[daccount][w]].dac; 
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=gate[dacfrom[daccount][w]].dac;
    else gate[w].matrix[6]=gate[dacfrom[daccount][w]].dac;
    gate[w].inner=SR_geo_inner_dacspeed3xnorouteadcN; 
  }
}

// repeat with route in
void SR_geo_outer_N51(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=gate[dacfrom[daccount][w]].dac; 
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=gate[dacfrom[daccount][w]].dac;
    else gate[w].matrix[6]=gate[dacfrom[daccount][w]].dac;
    gate[w].inner=SR_geo_inner_dacspeed3xrouteadcN; // gapped route function
  }
}

// would be nice to be able to select where we get speedfrom - or have 4 options here... - our own speed? trial in new one // route // no route
void SR_geo_outer_N52(uint32_t w){ // spdfracdac31
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=gate[dacfrom[daccount][w]].dac; 
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=gate[dacfrom[daccount][w]].dac;
    else gate[w].matrix[6]=gate[dacfrom[daccount][w]].dac;
    gate[w].inner=SR_geo_inner_dacspeed3xxnorouteadcN; 
  }
}

void SR_geo_outer_N53(uint32_t w){ // spdfracdac31 route in
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=gate[dacfrom[daccount][w]].dac; 
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=gate[dacfrom[daccount][w]].dac;
    else gate[w].matrix[6]=gate[dacfrom[daccount][w]].dac;
    gate[w].inner=SR_geo_inner_dacspeed3xxrouteadcN; 
  }
}

// can have 3 other fixed speedfroms! but then doubled by route/no route?


/////////// final
// 153: final one is reset but what does CVL do there? last bit or prob
void SR_geo_outer_N153(uint32_t w){  // final all gapped reset
  if (gate[w].changed==1) {
    RESETN; 
    gate[w].changed=0;
  }
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].matrix[4]=CVL[w];
  gate[w].matrix[10]=CVL[w];
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
  gate[w].inner=SR_geo_inner_gappedfunction;
    }




