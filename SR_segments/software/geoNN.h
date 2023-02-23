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

void SR_geo_inner_dacspeed3selfnorouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3self(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3selfrouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3self(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
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



void SR_geo_inner_routeadcN(uint32_t w){  
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
    bitn^=binroutesel0(0,0,w); // theroute which is ... and routetype
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_globaladcN(uint32_t w){  
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
    bitn^=binroutesel0(0,0,w); // theroute which is ... and routetype
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
      bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    }
      
    else bitn=binroutesel0(0,0,w); // theroute which is ... and routetype
    
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
    
    if ((*probf_anystrobe_forNN_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
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

void SR_geo_inner_probadcentryX(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
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
      bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    }
      
    else bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcentryxorX(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
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
      //      bitn^=binroutesel3(0,0,w); // theroute which is ... and routetype
      bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_functionN(uint32_t w){  
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
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// strobe for testings
//    ADCgeneric2; 
//    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
// TODO: strobe with route, generic strobe/gapped, strobe with just adc, strobe with prob of entry of route

void SR_geo_inner_str_functionN(uint32_t w){  // for strobe functions 
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc    
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rungnoroute(uint32_t w){  // no probability, no adc - this can be generic // no interp
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
	  bitn=(*padcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w, 1, 1); 
	}
    else
      {
	ADCgeneric2; 
	bitn=(*padcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w, 0, 1); 
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

    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; 
	  bitn=(*padcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w, 0, 1);
	}
    else
      {
	ADCgeneric2; 
	bitn=(*padcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w, 0, 0); 
      }
    
    //    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
	
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_innerxorNN(uint32_t w){  // xor with fixed route - but we don't track cv??? means what?
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ( (*speedfromcvforxor[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w) ^ speedfromforxor[0](0,0,w) ){ // speedfunc xor with fromforxor->binroutfixed...
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
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

void SR_geo_outer_N01(uint32_t w){ // adcparam, or route but now no route in
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  // depth on 8 and mix on 21 but mix has 8 as well as param anyways
  if (inall_depth[gate[w].matrix[6]>>6]==1) gate[w].matrix[8]=CVL[w];
  else if (inall_depth[gate[w].matrix[6]>>6]==2) gate[w].matrix[21]=CVL[w]; // mix
  else gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_norouteadcN; 
}
}

void SR_geo_outer_N02(uint32_t w){ // set adc type[CV] // fixed route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[7]=CVL[w]; // adctype
  gate[w].inner=SR_geo_inner_globaladcN; //
  }
}

void SR_geo_outer_N03(uint32_t w){ // 1-prob of ADC entry or fixed route entry  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<6; // invprobbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probadcentry;//
}
}

//// 1.0

//// 2.0

//3.0////////

// 3.0 start to vary route functions? as geoCC with adc - depth as route function - different arrays of route functions or just stick with one and is always adc/abstract
// route function/route type xor, prob of xor adc/abstract always
// dacs into abstract depth etc




//4.0////////// draft runglers for NN - how to place these in CC...

/*
rungler1: osc1 or selected gapped/abstract with speed or depth from speedfrom dac

- adc only// adc param
- select abstract
- depth abstract with route/no route
*/

//- adc only// adc param or now prob route in//route cv
// adc in with prob of route in and speed - inner_functionN
void SR_geo_outer_N40(uint32_t w){ // adc in
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac1
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[9]=0<<6; // invprobbits
    gate[w].matrix[10]=CVL[w]; // depth for prob
    
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_probadcentryX;
  }
}

// select abstract/adc + route
void SR_geo_outer_N41(uint32_t w){ 
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac3    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    //    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped 5 is also for abstractbits
    gate[w].matrix[20]=CVL[w]; // sel abstract
    gate[w].inner=SR_geo_inner_rungC;
  }
}

// no route in but we did sel... 
void SR_geo_outer_N42(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac3    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; //
    gate[w].matrix[5]=CVL[w];
    gate[w].inner=SR_geo_inner_rungnoroute;
  }
}

///++ trial add dac??? but what is CVL? // sel abstract
void SR_geo_outer_N43(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=4<<7; // spdfrac1 now
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped 5 is also for abstractbits
    gate[w].matrix[4]=gate[dacfromopp[daccount][w]].dac;
    gate[w].matrix[20]=CVL[w]; // sel abstract // 20 we like
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
    gate[w].inner=SR_geo_inner_dacspeed3xnorouteadcN; 
  }
}

// repeat with route in
void SR_geo_outer_N51(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3xrouteadcN; // gapped route function
  }
}

// would be nice to be able to select where we get speedfrom - or have 4 options here... - our own speed? trial in new one // route // no route
void SR_geo_outer_N52(uint32_t w){ // spdfracdac3self
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3selfnorouteadcN; 
  }
}

void SR_geo_outer_N53(uint32_t w){ // spdfracdac3self route in
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3selfrouteadcN; 
  }
}

// can have 3 other fixed speedfroms! but then doubled by route/no route?

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// next

// switches against dacs, against strobes and toggles 
// abstracts... ADC or abstract - slide across gate[x].funcbit and extent - in prob etc.
// do we use dac in?

/* probs

CC, LL:
- entry vs. zero
- entry vs. cycle
- entry vs [entry^cycle]
- depthroute vs. fixedroute - strobe one as we need 2x depth

don't gap abstract and adc 

- adc/abstract vs. zero
- adc/abstract vs. route in
- adc/abstract vs. [adc/abstract ^ routein]

try these:

- adc/abstract vs. cycle
- adc/abstract vs. [route in ^ cycle]

no prob:
adc ^ abstract
adc only
route in only
abstract only

///8.0 strobes+

 */


// what we find in geoN:

/*
geoN.h:


 */

// outer 80+ strobe

void SR_geo_outer_N80(uint32_t w){   // simple fixed strobe with adc entry only, select strobe func and ADC type/param
  if (gate[w].changed==0) {
    gate[w].matrix[15]=0<<8;//  simple strobe
    gate[w].matrix[7]=CV[w]; // adc type // can also be depth for ADC //
    gate[w].matrix[8]=CVL[w]; // adc param
    gate[w].inner=SR_geo_inner_str_functionN;
  }
}

////////////////////////////////// tests and trials



// trial these again from NN: - with or without route in!
void SR_geo_outer_Ntestprobreset(uint32_t w){  
  if (gate[w].changed==0) { // 1=change 0= no change
  gate[w].matrix[0]=1<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  //  gate[w].matrix[3]=1<<7; // fixed route
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  gate[w].matrix[7]=0<<7;//CVL[w]; // set adc - 0 is zeroes // 18 and 19 need triggersa
  gate[w].matrix[9]=0<<6;// 
  gate[w].matrix[10]=CVL[w]; 
  gate[w].inner=SR_geo_inner_probadcreset;
  }
}

void SR_geo_outer_Ntestprobadvance(uint32_t w){  
  if (gate[w].changed==0) { // 1=change 0= no change
  gate[w].matrix[0]=1<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  //  gate[w].matrix[3]=1<<7; // fixed route
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  gate[w].matrix[7]=0<<7;//CVL[w]; // set adc - 0 is zeroes // 18 and 19 need triggersa
  gate[w].matrix[9]=0<<6;// 
  gate[w].matrix[10]=CVL[w]; 
  gate[w].inner=SR_geo_inner_probadcadvance;
  }
}

// test speed xor
void SR_geo_outer_speedxorN(uint32_t w){  // which gaps/functions - but we have CVL used
  gate[w].matrix[0]=CVL[w];   // what is appropriate speed function????
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but do we need 2nd cv???
  gate[w].inner=SR_geo_innerxorNN;
}  

// trial bursts/probf_anystrobe_forNN_depth[16] - prob of x entry vs y entry eg as 03 above
void SR_geo_outer_Nadcburst(uint32_t w){ // 2-prob of abstract entry or route entry
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=8<<7; // trial  bursts
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].inner=SR_geo_inner_probadcburst;// adcburst abstractburst
}
}



