// NN new N top ADC:

/*

NN: not so much about speeds?

- prob of adc/abstract vs. route // adc/abstract vs. adc/abstract^route

[ Q: adc/abstract vs. [adc/abstract ^ cycle] ? ]

- runglers with adc and abstract, what of route in?

////

older notes from geoN.h:

adc, abstracts and routes only

switches between these entries, abstracts as entry (no ADC)?

// Q of IN as dac:  TODO: we need different DAC from dacfrom as DAC for ADC input eg. dacIN

ADCin=gate[dacIN[daccount][w]].dac; // test


 */

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

void SR_geo_inner_norouteadcN(uint32_t w){  // no probability, WITH adc, with interpoll
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

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_norouteabstractN(uint32_t w){  // no probability, WITH adc, with interpoll
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

    bitn=(*abstractbitsz_begin[gate[w].matrix[17]>>7])(gate[w].matrix[18], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_globalsabstractN(uint32_t w){  
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
    bitn=(*abstractbitsz_begin[gate[w].matrix[17]>>7])(gate[w].matrix[18], gate[w].matrix[5], w); 
    bitn^=binroutesel0(0,0,w); // theroute which is ... and routetype
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

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
    bitn^=binroutesel3(0,0,w); // theroute which is ... and routetype
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

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
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

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; 
	  bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
	}
      
    else bitn=binroutesel3(0,0,w); // theroute which is ... and routetype
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probabstractentry(uint32_t w){ 
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

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*abstractbitsz[gate[w].matrix[17]>>7])(gate[w].matrix[18], gate[w].matrix[5], w);
    }
    else bitn=binroutesel3(0,0,w); // theroute which is ... and routetype
    
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

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
    if (!(*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=binroutesel3(0,0,w); // theroute which is ... and routetype
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

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; 
	  bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
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

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
    if (!(*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
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
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// OUTERS
////////////////////////////////////////////////////////////////////////////////////////////////
//0.0////////

void SR_geo_outer_N00(uint32_t w){ // set adctype // no route in
  if (gate[w].changed==1) RESETN; // added 21/12 only reset on change 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[7]=CVL[w]; // adctype
  //  gate[w].matrix[8]=CVL[w]; // adccv //TEST
  gate[w].inner=SR_geo_inner_norouteadcN; // routetype/theroute so always at reset route/base global
}

void SR_geo_outer_N01(uint32_t w){ // adcparam, or route but now no route in
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=CVL[w]; // adccv
      else gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_norouteadcN; // routetype/theroute so always at reset route/base global
}
}

void SR_geo_outer_N02(uint32_t w){ // abstract only - select function - reduced set of abstracts
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 
  gate[w].matrix[17]=CVL[w]; // 17 is now sel for abstract //18 would be depth // upto 23 now
  gate[w].inner=SR_geo_inner_norouteabstractN;
}
}

void SR_geo_outer_N03(uint32_t w){ // abstract only - depth
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  //  gate[w].matrix[17]=21<<7;// // TESTSEL
  gate[w].matrix[18]=CVL[w]; // 17 is now sel for abstract //18 would be depth
  gate[w].inner=SR_geo_inner_norouteabstractN;
}
}

//1.0////////
void SR_geo_outer_N10(uint32_t w){ // set adc type[CV] // route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[7]=CVL[w]; // adctype
  //  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=CVL[w]; // adccv
  //      else gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_globaladcN; //
  }
}

void SR_geo_outer_N11(uint32_t w){ // set abstract CV // route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 
  gate[w].matrix[18]=CVL[w]; 
  gate[w].inner=SR_geo_inner_globalsabstractN; //
  }
}

void SR_geo_outer_N12(uint32_t w){ // 1-prob of ADC entry or route entry  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<7; // invprobbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].inner=SR_geo_inner_probadcentry;//
}
}

void SR_geo_outer_N13(uint32_t w){ // 2-prob of abstract entry or route entry
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<7; // invprobbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].inner=SR_geo_inner_probabstractentry;//
}
}

// 9/2/2023 UPTO HERE!!!! changed

// 20 route functions? as geoCC with adc - depth as route function - different arrays of route functions or just stick with one and is always adc/abstract
// route function/route type xor, prob of xor adc/abstract always
// dacs into abstract depth etc

//2.0////////

void SR_geo_outer_N20(uint32_t w){ // change function. theroute
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_functionN; 
  }
}

void SR_geo_outer_N21(uint32_t w){ // gapped function. set depth/route
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=CVL[w]; // depth
  else SETROUTECV;
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_functionN; 
  }
}

void SR_geo_outer_N22(uint32_t w){ // prob/depth of adc vs gapped function
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 - or we gap this?
  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // CV2 for those which use IN     
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probadcentryX;
}
}

void SR_geo_outer_N23(uint32_t w){ // prob/depth of adc vs gapped functionXOR
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 - or we gap this?
  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // CV2 for those which use IN     
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probadcentryxorX;//
}
}

//3.0////////
// as is - too noisy... 2x no route in, 2 prob as above - we need

void SR_geo_outer_N30(uint32_t w){ // dac. adcpar/depth as adctype
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[7]=CVL[w]; // adctype

  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac); // adccv
      else gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac); // length
  gate[w].inner=SR_geo_inner_norouteadcN; // routetype/theroute so always at reset route/base global
}
}

void SR_geo_outer_N31(uint32_t w){ // // dac length/ cv adcpar - but length can be dac as we see above...// 2 cases or trial on adctype
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];

  if (adcfromsd_depth[gate[w].matrix[7]>>7])
    {
      gate[w].matrix[8]=CVL[w];
      gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac); // length
    }
  else {
    gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac); // length - same as above in these cases
    gate[w].matrix[7]=CVL[w]; // adctype
  }
  gate[w].inner=SR_geo_inner_norouteadcN; // routetype/theroute so always at reset route/base global
}
}

void SR_geo_outer_N32(uint32_t w){ // prob/depth of adc vs gapped function // // dac. adcpar/depth prob
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2

  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac); // adccv
      else gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac); // length

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // CV2 for those which use IN     
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probadcentryX;
}
}

void SR_geo_outer_N33(uint32_t w){ // prob/depth of adc vs gapped functionXOR // dac. cvdepth/depth prob
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 - or we gap this?
  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=CVL[w]; // adccv
      else gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac); //CVL[w]; // probCV1
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // CV2 for those which use IN     
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probadcentryxorX;//
}
}

//// older

void SR_geo_outer_N30x(uint32_t w){ // dac-length. depth-cv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=CVL[w]; // depth
  else SETROUTECV;  
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2
  gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac); // length
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_functionN; 
  }
}

void SR_geo_outer_N31x(uint32_t w){ // dac-adcpar. depth-cv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=CVL[w]; // depth
  else SETROUTECV;  
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2

  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac); // adccv
  else gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac); // length

  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_functionN; 
  }
}

void SR_geo_outer_N32x(uint32_t w){ // dac-depth. adcpar-cv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); // depth
  else SETROUTEDAC;  
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2

  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=CVL[w]; // adccv
      else gate[w].matrix[6]=CVL[w]; // length

  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_functionN; 
  }
}

void SR_geo_outer_N33x(uint32_t w){ // dac-depth. length-cv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); // depth
  else SETROUTEDAC;  
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_functionN; 
  }
}

// next 16

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

 */


// what we find in geoN:

/*
geoN.h:


 */

//1.0////////// try to follow geoCC but need new inners all with adc now... theroute in, adcparam, length -> all with probs of entry, switch of entry on strobe
// abstract ins/merge/prob of these...
