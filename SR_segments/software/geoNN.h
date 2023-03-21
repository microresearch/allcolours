// N: N0-3, C10,12,13,22, N20-23, C30-33, N40-N53, L50-51, C60-63 C80-153

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

void SR_geo_inner_norouteadcN(uint32_t w){
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
    bitn=(*abstractbitsz[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_norouteadcNN(uint32_t w){
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
    ADCgeneric2; 

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  bitn=(*padcfromsd[gate[w].matrix[7]>>6])(gate[w].matrix[8], ADCin, w, 1, 1); 
	}
    else
      {
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
    ADCgeneric2; 
    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn=(*padcfromsd[gate[w].matrix[7]>>6])(gate[w].matrix[8], ADCin, w, 0, 1);
    }
    else
      {
	bitn=(*padcfromsd[gate[w].matrix[7]>>6])(gate[w].matrix[8], ADCin, w, 0, 0); 
      }
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probabstractentryX(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
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
      if (w==0)     bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix
      else bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done      
    }
    else bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// OUTERS
////////////////////////////////////////////////////////////////////////////////////////////////
//0.0//////// 

// 

void SR_geo_outer_N00(uint32_t w){ // set adctype // route in
  if (gate[w].changed==1) {
    RESETN; // added 21/12 only reset on change
    gate[w].changed=0;
  }
  gate[w].matrix[0]=0<<7; // spdfrac - /with or no interpol
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[7]=CVL[w]; // adctype
  gate[w].inner=SR_geo_inner_globalC;//
}

void SR_geo_outer_N01(uint32_t w){ // set adc depth // no route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];      
  if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=CVL[w];
  else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=CVL[w]; // mix for dacs
  else gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_globalC; //norouteadcNN;//
  }
}

void SR_geo_outer_N02(uint32_t w){ // set adc type from CVL and depth from dacfrom // fixed route in 
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[7]=CVL[w]; // adctype 
  if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac);
  else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=(gate[dacfrom[daccount][w]].dac); // mix for dacs
  else gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac); // length
  gate[w].inner=SR_geo_inner_globalC; //
  }
}

void SR_geo_outer_N03(uint32_t w){ // 1-prob of ADC entry or fixed route entry  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=1<<6; // invprobbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].inner=SR_geo_inner_probadcentry;// fixed as probbits and fixed entry SR_geo_inner_adcprobzero
}
}

//////////////
//1.0 params

// C10, C12, N13, C20 in that order
void SR_geo_inner_routeabstractR(uint32_t w){ 
  HEADNADA;

  // always is
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;

    if (spdfrac(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbitsz[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w);
    bitn^=binroutesel0(0,0,w); // global route which is ... and routetype
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

//*N13 - potential adc in mode - adcin as depth and all abstract choices// route in
void SR_geo_outer_N13(uint32_t w){
  uint32_t k;
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[20]=CVL[w]; // select abstract bits only
  ADCgeneric;
  gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].matrix[5]=k;
  gate[w].inner=SR_geo_inner_routeabstractR;
  }
}

/////////////////////////////////////////
// advance
void SR_geo_outer_N22(uint32_t w){  // these are with last route in
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[3]=0<<6; // Zbinrout_strip=0 checked
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 

  if ((gate[w].matrix[7]>>6)>22) { // we hit dacs or abstracts
  if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=CVL[w];
  else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=CVL[w]; // mix for dacs
  else gate[w].matrix[4]=CVL[w];
  gate[w].inner=SR_geo_inner_function; // 
    }
  else { // less than 23
      gate[w].matrix[9]=1<<6; 
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
  if ((gate[w].matrix[7]>>6)>22) { // dacs or abstracts
  if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=CVL[w];
  else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=CVL[w]; // mix
  else gate[w].matrix[4]=CVL[w];
  gate[w].inner=SR_geo_inner_function; // 
    }
  else { // less than 23
      gate[w].matrix[9]=1<<6;// 
      gate[w].matrix[10]=CVL[w];
      gate[w].inner=SR_geo_inner_probadcreset;
    }
  }
}

//3.0//////// route functions from CC
// C30->C33

//4.0////////// NN runglers - gapped functions

void SR_geo_outer_N40(uint32_t w){ 
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w];//5<<7; // tested // try fixed speed - spdfrac3/4  
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].inner=SR_geo_inner_rungC;
  }
}

void SR_geo_outer_N41(uint32_t w){ // adc in
  if (gate[w].changed==0) {
    //    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3/4
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[9]=0<<6; // probbits
    gate[w].matrix[10]=CVL[w]; // depth for prob
    
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=gate[dacfrom[daccount][w]].dac; 
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=gate[dacfrom[daccount][w]].dac;
    else gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac;

    gate[w].inner=SR_geo_inner_probabstractentryX;
  }
}

// no route in but we did sel... // gapped speeds
void SR_geo_outer_N42(uint32_t w){  // no route
  if (gate[w].changed==0) {
    //    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3/4    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=CVL[w];
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=CVL[w];
    else gate[w].matrix[6]=CVL[w]; // length
    gate[w].inner=SR_geo_inner_rungnoroute;
  }
}

void SR_geo_outer_N43(uint32_t w){  // no route
  if (gate[w].changed==0) {
    //    gate[w].matrix[0]=6<<7; // spdfrac4 now
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
//// dacspeed runglers 

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
    else gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac;
    gate[w].inner=SR_geo_inner_dacspeed3xrouteadcN; // gapped route function
  }
}


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
    else gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac;
    gate[w].inner=SR_geo_inner_dacspeed3xxrouteadcN; 
  }
}
