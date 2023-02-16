// NN new N top ADC:

/*

//1.0////////// try to follow geoCC but need new inners all with adc now... theroute in, adcparam, length -> all with probs of entry, switch of entry on strobe
// abstract ins/merge/prob of these...


also for RR:

- just route in, adc in, abstract in only
- some cycle probs but generally replace prob/switch of route vs cycle with route vs adc/abstract/dac
- probs below of func vs. route in
- runglers

///

- probs of x vs. y

NN: not so much about speeds?

- prob of adc/abstract vs. route // adc/abstract vs. adc/abstract^route

[ Q: adc/abstract vs. [adc/abstract ^ cycle] ? ]

- runglers with adc and abstract, what of route in?

////

older notes from geoN.h:

adc, abstracts and routes only

switches between these entries, abstracts as entry (no ADC)?

 */

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

// check? //??? inner abstract function, inner dacfunction, inner mixfunction and gapped versions of these with probabilities

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

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_noroutedacN(uint32_t w){  
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
    ADCin=gate[dacIN[daccount][w]].dac; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_norouteseldacN(uint32_t w){  
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
    ADCin=gate[gate[w].matrix[4]>>10].dac; // test 2 bits
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_noroutemixN(uint32_t w){  
  HEADNADA;
  float mult, pp;
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
    mult=mixer[gate[w].matrix[21]>>2]; // 10 bits - 0 is 1.0f so full dac
    pp=((float)(ADCin) *  (1.0f-mult)) + ((float)(gate[dacIN[daccount][w]].dac)*mult); // mix with param
    ADCin=(int)pp;
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_routemixN(uint32_t w){  
  HEADNADA;
  float mult, pp;
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
    mult=mixer[gate[w].matrix[4]>>2]; // 10 bits - 0 is 1.0f so full dac
    pp=((float)(ADCin) *  (1.0f-mult)) + ((float)(gate[dacIN[daccount][w]].dac)*mult); // mix with param
    ADCin=(int)pp;
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w);
    bitn^=binroutesel0(0,0,w); // theroute which is ... and routetype
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_dacspeed3xnorouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    //    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3selfnorouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3self(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    //    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3selfrouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3self(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    //    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w);
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3xrouteadcN(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    //    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w);
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_norouteabstractN(uint32_t w){  
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

    bitn=(*abstractbitsz_begin[gate[w].matrix[20]>>7])(gate[w].matrix[18], gate[w].matrix[5], w); 
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
    bitn=(*abstractbitsz_begin[gate[w].matrix[20]>>7])(gate[w].matrix[18], gate[w].matrix[5], w); 
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
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

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
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
	  ADCgeneric2; 
	  bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
	}
      
    else bitn=binroutesel0(0,0,w); // theroute which is ... and routetype
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probdacentry(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h/geoC.h
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
      ADCin=gate[dacIN[daccount][w]].dac;
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
	}
      
    else bitn=binroutesel0(0,0,w); // theroute which is ... and routetype
    
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

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[18], gate[w].matrix[5], w);
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

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
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
	  ADCgeneric2; 
	  bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
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
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 
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
    gate[w].fake=1;//
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    //    bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(gate[w].matrix[8], ADCin, w); 

    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rungnoroute(uint32_t w){  // no probability, no adc - this can be generic // no interp
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
    //    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


// OUTERS
////////////////////////////////////////////////////////////////////////////////////////////////
//0.0////////

void SR_geo_outer_N00(uint32_t w){ // set adctype // no route in
  if (gate[w].changed==1) {
    RESETN; // added 21/12 only reset on change
    gate[w].changed=0;
  }
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[7]=CVL[w]; // adctype
  //  gate[w].matrix[8]=CV[w]; // adccv //TEST // already inverted
  gate[w].inner=SR_geo_inner_norouteadcN; 
}

void SR_geo_outer_N01(uint32_t w){ // adcparam, or route but now no route in
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=CVL[w]; // adccv
      else gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_norouteadcN; 
}
}

void SR_geo_outer_N02(uint32_t w){ // abstract only - select function - reduced set of abstracts
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 
  gate[w].matrix[20]=CVL[w]; // 20 is now sel for abstract //18 would be depth // upto 23 now
  gate[w].inner=SR_geo_inner_norouteabstractN;
}
}

void SR_geo_outer_N03(uint32_t w){ // abstract only - depth
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  //  gate[w].matrix[20]=21<<7;// // TESTSEL
  gate[w].matrix[18]=CVL[w]; // 20 is now sel for abstract //18 would be depth
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

void SR_geo_outer_N11(uint32_t w){ // 1-prob of ADC entry or route entry  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<7; // invprobbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].inner=SR_geo_inner_probadcentry;//
}
}

void SR_geo_outer_N12(uint32_t w){ // set abstract CV // route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 
  gate[w].matrix[18]=CVL[w]; 
  gate[w].inner=SR_geo_inner_globalsabstractN; //
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

//2.0////////

// ***** INS N20// SR_geo_outer_C10 // just route in // type

// could have DACin - which dac - select!
void SR_geo_outer_N21(uint32_t w){ // CVL for length
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_noroutedacN; 
}
}

void SR_geo_outer_N22(uint32_t w){ // CVL for which DAC
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[4]=CVL[w]; // sel
  gate[w].inner=SR_geo_inner_norouteseldacN; 
}
}

// prob of dacin or route in TODO // dacin or adcin
/*void SR_geo_outer_N23(uint32_t w){ //prob of daC entry or route entry  - can run out easily
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<7; // invprobbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].inner=SR_geo_inner_probdacentry;//
}
}*/

// we can also mix dac and adcin...
void SR_geo_outer_N23(uint32_t w){ //
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[21]=CVL[w]; // mix
  gate[w].inner=SR_geo_inner_noroutemixN;
}
}

void SR_geo_outer_N23x(uint32_t w){ // now with route in
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[21]=CVL[w]; // mix
  gate[w].inner=SR_geo_inner_routemixN;
}
}

// own dac out and params???

// vary route in etc.. try to follow CC

// dacin. abstract in etc with varying speeds and strobe too!

//3.0////////

// 3.0 start to vary route functions? as geoCC with adc - depth as route function - different arrays of route functions or just stick with one and is always adc/abstract
// route function/route type xor, prob of xor adc/abstract always
// dacs into abstract depth etc

//4.0////////// draft runglers

/*
rungler1: osc1 or selected gapped/abstract with speed or depth from speedfrom dac
// can also be with adc in instead of abstract

// what are options... notes

speedfromdac/offsets // [fixed function eg osc1] // no route in
dac3/dac4 options    // adc NN only              // route in
some need 2xCV       // sel abstract            //  if route in -> sel route in function - depth or no depth
                     // gapped sel abstract     //  gapped route in function          


// we need more fixed runglers: 

speedcv, osc1speeddepth
adcs as below

and then generic ones 

what we have here?

N40: osc1 // spdfrac3 - gapped route in
// add no routes

N41: adc in // spdrac3 // depth for bits - gapped route in
// add no route

dacspeedCV/CVL section OK!:
N42: adc in - dacspeed CV/CVL, no route
N43: adc in - dacspeed CV/CVL, route
N50: adc in - dacspeedself, noroute
N51:                        route in///

to add from below but keep speedfunc as dac3 now:

with routes:
dac3//sel abstract// gapped route in 
dac3//abstract depth// gapped route
dac3//gapped abs//routefuncdepth

what we have in C50+? these are more generic, maybe re-work...

C50: speedsel, osc1
C51: gapped speedfunc, bitfuncsel, osc1
C52: gapped speedfunc, abstractsel
C53: depthcv - still leaves cv for bitfunc?


*/

// what are the options? select speed in, other fixed speedfuncs, what is gapped... no route in...
// speedsel, abstractsel, routesel, abstractcv, routecv

// combine osc1 depth and speed dont make much sense
void SR_geo_outer_N40(uint32_t w){ // fixed func1 (osc) and gapped func2
  if (gate[w].changed==0) {
    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].matrix[5]=CVL[w]; // cv for abstract -> osc1 can also be: dacfrom
    gate[w].matrix[20]=0<<7;// select osc1 from abstractbitz
    gate[w].funcbit=routebits_nodepth_typesz; // gap it!
    gate[w].extent=6;
    gate[w].inner=SR_geo_inner_rungC;
  }
}


// more fixed ones: speedcv, osc1speeddac // ROUTE IN, and then no route in:     gate[w].inner=SR_geo_inner_rungnoroute;
void SR_geo_outer_N40simple(uint32_t w){ // fixed func1 (osc) and gapped func2
  if (gate[w].changed==0) {
    gate[w].matrix[0]=0<<7; // basic speed
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[5]=gate[speedfrom[spdcount][w]].dac; // CV for osc1
    // package for gapped
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[9]=0<<7; // invprobbits
    gate[w].matrix[10]=CVL[w];

    gate[w].matrix[20]=0<<7;// select osc1 from abstractbitz
    gate[w].inner=SR_geo_inner_runggappedC;
  }
}

void SR_geo_outer_N40xxx(uint32_t w){ // gapped speed with 2x CV -- CVL is free???
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[speedfrom[spdcount][w]].dac;//gate[dacfrom[daccount][w]].dac; // for absstracts but should be spdfrom
    // package for gapped
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[9]=0<<7; // invprobbits
    gate[w].matrix[10]=CVL[w];
    //    gate[w].matrix[5]=CVL[w]; // cv for abstract -> osc1 can also be: dacfrom
    gate[w].matrix[20]=0<<7;// select osc1 from abstractbitz
    //    gate[w].funcbit=routebits_nodepth_typesz; // gap it!
    //    gate[w].extent=6;
    gate[w].inner=SR_geo_inner_runggappedC;
  }
}

// above with no route
void SR_geo_outer_N40x(uint32_t w){ // fixed func1 (osc) and gapped func2
  if (gate[w].changed==0) {
    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[3].dac; // 2nd speed cv2
    gate[w].matrix[5]=CVL[w]; // cv for abstract -> osc1 can also be: dacfrom - we swop these round
    gate[w].matrix[20]=0<<7;// select osc1 from abstractbitz
    gate[w].inner=SR_geo_inner_rungnoroute;
  }
}

void SR_geo_outer_N40xx(uint32_t w){ // fixed func1 (osc) and gapped func2 - swop CVs
  if (gate[w].changed==0) {
    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].matrix[4]=CVL[w]; //
    gate[w].matrix[10]=CVL[w];
    gate[w].matrix[20]=0<<7;// select osc1 from abstractbitz
    gate[w].matrix[9]=0<<7; // invprobbits
      
    //    gate[w].funcbit=routebits_nodepth_typesz; // gap it!
    //    gate[w].extent=6;
    gate[w].inner=SR_geo_inner_runggappedC;//SR_geo_inner_rungC; // we need to gap this for prob as we have a depth CV
  }
}

//above no route

// adc in with route in and speed - inner_functionN
void SR_geo_outer_N41(uint32_t w){ // adc in
  if (gate[w].changed==0) {
    gate[w].matrix[0]=5<<7; // tested // try fixed speed - spdfrac3    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=CVL[w]; // depth for bits
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].funcbit=routebits_depth_typesz; // we need to keep or gapped
    gate[w].extent=7;
    gate[w].inner=SR_geo_inner_functionN;
  }
}

// adc with no route in... SR_geo_inner_norouteadcN
void SR_geo_outer_N42(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].inner=SR_geo_inner_dacspeed3xnorouteadcN; 
  }
}

// repeat with route in
void SR_geo_outer_N43(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3xrouteadcN; // gapped route function
  }
}

// would be nice to be able to select where we get speedfrom - or have 4 options here... - our own speed? trial in new one // route // no route
void SR_geo_outer_N50(uint32_t w){ // spdfracdac3self
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3selfnorouteadcN; 
  }
}

void SR_geo_outer_N51(uint32_t w){ // spdfracdac3self route in
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3selfrouteadcN; 
  }
}

/*
this is in geoCC.h // unused so far:

void SR_geo_inner_rungC(uint32_t w){  // no probability, no adc - this can be generic // no interp
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// these ones below older:
C50: speedsel, osc1
C51: gapped speedfunc, bitfuncsel, osc1
C52: gapped speedfunc, abstractsel
C53: depthcv - still leaves cv for bitfunc?

void SR_geo_outer_C50(uint32_t w){ // redo speedfunc select with fixed func1 (osc) and gapped func2, gapped depth in both cases
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // tested
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
  gate[w].matrix[20]=0<<7;// select osc1 from abstractz
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_rungC;
  }
}

void SR_geo_outer_C51(uint32_t w){ // gapped speed, osc1 still fixed, sel func2
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[3]=CVL[w]; // function sel
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; //// also CV1 for func1 CV2 or gapped
  gate[w].matrix[20]=0<<7;// select osc1 from abstractz

  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_rungC;
  }
}

void SR_geo_outer_C52(uint32_t w){ // gapped speed, func1 sel, gapped func2
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped
  gate[w].matrix[20]=CVL[w];// cv sel from abstractz
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_rungC;
  }
}

void SR_geo_outer_C53(uint32_t w){ // gapped speed, gapped func1, gapped func2. depth CV (4)?
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv

  if (!(depth_routebits_typesz[gate[w].matrix[3]>>6])) SETROUTECV;    // if needs be set route
  gate[w].matrix[4]=CVL[w]; // always set depth -   //  gate[w].matrix[4]=CVL[w];// depth for both as they are switched... we can also swop these around for one more rungler below...  // and gap 4 or gap5?
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped
  
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_rungC;
  }
}

*/




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

///8.0 strobes+

 */


// what we find in geoN:

/*
geoN.h:


 */

// outer 80+ strobe

void SR_geo_outer_N80(uint32_t w){   // simple fixed strobe with adc entry only, select strobe func and ADC
  if (gate[w].changed==0) {
    gate[w].matrix[15]=0<<8;//  simple strobe
    gate[w].matrix[7]=CV[w]; // adc type // can also be depth for ADC //
    gate[w].matrix[8]=CVL[w];
    gate[w].inner=SR_geo_inner_str_functionN;
  }
}
