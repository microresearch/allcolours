//- TODO: fill in and simplify geoC according to 16/16/16/16 modes

// CC: dactype and param, probs or route/etc, routes, speed mods as primary

extern void send_command(int command, void *message);
char buffx[10];

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

void SR_geo_inner_globalC(uint32_t w){  // fixed route only - no probability, no adc - this can be generic
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
    bitn=binroutesel0(0,0,w); // global route which is ... and routetype
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_routeC(uint32_t w){  // theroute
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
    bitn=binroutesel3(0,0,w); // theroute which is ... and routetype
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_function(uint32_t w){  // new abstraction needs gate[w].funcbit->function array, and extent as >>howmany
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
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_testdacasdepth(uint32_t w){  //
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe_noIN[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_function_strobexor(uint32_t w){ 
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w) ^ (*speedfromstrobe_nodepth[0<<8])(0,0,w))    { // speedfunc
    gate[w].fake=1;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed4(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac4(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}



void SR_geo_inner_str_function(uint32_t w){  // for strobe functions 
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

    if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=1;//
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].str_funcbit[gate[w].matrix[3]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_functionprob1(uint32_t w){ 
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
    if ((gate[w].matrix[3]>>gate[w].extent)<24) {// we use depth
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    else { // prob of cycle or in new version xor cycle...
      if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      }
      else {
	bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
      }
	  
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_functionprobzero(uint32_t w){  
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

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      }
      else {
	bitn = 0;
      }
	  
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probcycleC(uint32_t w){  // TESTY - using probfsins - ported in from speeds -> basic gapped cv binroute against justcycle! // unused so far
  // what cv we need: probfs: 9type,10comp... 11IN 3,4,5 is gapped...
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

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
  }
  else {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  }    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probcycleCnodepth(uint32_t w){  // TESTY - using probfsins - ported in from speeds -> basic gapped cv binroute against justcycle! // unused so far
  // what cv we need: probfs: 9type,10comp... 11IN 3,4,5 is gapped...
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

    if ((*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
  }
  else {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  }    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probcyclexorC(uint32_t w){  // TESTY - using probfsins - ported in from speeds -> basic gapped cv binroute against justcycle! // unused so far
  // what cv we need: probfs: 9type,10comp... 11IN 3,4,5 is gapped...
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

    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?

    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);	   // cycle bit
    }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probcyclexorinvC(uint32_t w){  // TESTY - using probfsins - ported in from speeds -> basic gapped cv binroute against justcycle! // unused so far
  // what cv we need: probfs: 9type,10comp... 11IN 3,4,5 is gapped...
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

    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?

    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=(!(gate[w].Gshift_[w]>>SRlength[w]) & 0x01);	   // cycle bit INV
    }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rungC(uint32_t w){  // no probability, no adc - this can be generic // no interp
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>9])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(*abstractbitsz[gate[w].matrix[12]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probnodepth(uint32_t w){  // draft for probs with no depth
  HEADNADA;
  uint32_t tmproute;
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

    if ((*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
        bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
  else {
    bitn=(gate[w].funcbit[gate[w].matrix[12]>>gate[w].extent])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
    gate[w].theroute=tmproute;
  }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probdepth(uint32_t w){  // draft for probs with depth
  HEADNADA;
  uint32_t tmproute;
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

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)) {
        bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
  else {
    tmproute=gate[w].theroute;
    gate[w].theroute=gate[w].altroute;
    bitn=(gate[w].funcbit[gate[w].matrix[12]>>gate[w].extent])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
    gate[w].theroute=tmproute;
  }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_gappedfunction(uint32_t w){  // depth or cycle prob
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
    if (gate[w].depths[gate[w].matrix[3]>>gate[w].extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*   
      gate[w].matrix[4]=CVL[w];
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    else { // prob of cycle or in new version xor cycle...
      gate[w].matrix[10]=CVL[w];
      if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      }
      else {
	bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
      }
	  
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_gappedfunction2(uint32_t w){  // depth or xor prob
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
    if (gate[w].depths[gate[w].matrix[3]>>gate[w].extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*   
      gate[w].matrix[4]=CVL[w];
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    else { // prob of cycle or in new version xor cycle...
      // set prob depth
      gate[w].matrix[10]=CVL[w];
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      if (!(*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn^= (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
      }
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}



void SR_geo_inner_null(uint32_t w){
  // nada
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

void SR_geo_outer_route(uint32_t w){  // fixed route // the most basic but no reset
  gate[w].matrix[0]=2<<7; // spdfracend with interpoll
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // speed
  gate[w].inner=SR_geo_inner_globalC; // global route
}

void SR_geo_outer_null(uint32_t w){  // nada
  gate[w].inner=SR_geo_inner_null; // global route
}


// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobeindex, 16type, 17route

//0.0////////

void SR_geo_outer_C00(uint32_t w){  // set dactype, spdfrac, fixed route // for NN: set ADCtype, LL/RR: length
  if (gate[w].changed==1) RESETC; // added 21/12 only reset on change 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[13]=CVL[w]; // dactype
  gate[w].inner=SR_geo_inner_routeC; // routetype/theroute so always at reset route/base global
}

void SR_geo_outer_C01(uint32_t w){ // prob2 - invert
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=14<<6; // NZbinroutfixed_prob2 - type/prob against LFSR and globflag // or 14 prob3? inv cycle
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function;
  }
}

void SR_geo_outer_C02(uint32_t w){ // prob1 - route vs cycle
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=12<<6; // NZbinroutfixed_prob1 - type/prob against LFSR and globflag
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function;
  }
}

void SR_geo_outer_C03(uint32_t w){ // prob4 - route vs. [route^cycle]
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=15<<6; // NZbinroutfixed_prob4 - type/prob against LFSR and globflag
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function;
  }
}

//1.0//////// route, dacparam, length, what else?

void SR_geo_outer_C10(uint32_t w){ // change type. route above depth - type doesn't change so much. esp not at high speeds
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  SETROUTETYPECV; 
  gate[w].inner=SR_geo_inner_routeC; // was depth route
  }
}

void SR_geo_outer_C11(uint32_t w){ // theroute/dacparam... theroute is now fixed
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[14]=CVL[w]; // set dacparam
  gate[w].inner=SR_geo_inner_routeC; // routetype/theroute
  }
}

void SR_geo_outer_C12(uint32_t w){ // theroute/length - length only notices at slower speeds
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_routeC; // routetype/theroute
  }
}

void SR_geo_outer_C13(uint32_t w){ // change route. gapped type // depth as route
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=63<<6; // Zbinrout_strip=63
  gate[w].matrix[4]=CVL[w];
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

//2.0//////// select function, cv->depth, repeat 2 probs now with changed function

void SR_geo_outer_C20(uint32_t w){ // change function. nodepth. types
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above // checked
  gate[w].depths=depth_routebits_nodepth_typesz;
  gate[w].inner=SR_geo_inner_function; 
  }
}

// routebits_anystrobe_nodepth_notypesz [32] (with depth as sel) // no depth: routebits_nodepth_typesz, routebits_anystrobe_nodepth_notypesz 
void SR_geo_outer_C21(uint32_t w){ // change function. nodepth no types
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_anystrobe_nodepth_notypesz;
  gate[w].extent=7; // 7 bits // checked 
  gate[w].depths=depth_routebits_anystrobe_nodepth_notypesz;
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C22(uint32_t w){ // sel function. array with depth...routebits_depth_typesz
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_depth_typesz; //routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=7; 
  gate[w].depths=depth_routebits_depth_typesz;
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C23(uint32_t w){ // depth - note depth will also leak into others with gapped depth like next one...
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_depth_typesz; //routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=7; // 6 bits above
  gate[w].depths=depth_routebits_depth_typesz;
  gate[w].inner=SR_geo_inner_function; 
  }
}

//3.0/////// 
//

void SR_geo_outer_C30(uint32_t w){ //  // notypes select
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // sel
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_anystrobe_depth_notypesz;
  gate[w].extent=8; // 
  gate[w].depths=depth_routebits_anystrobe_depth_notypesz;
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C31(uint32_t w){ // notypes. depth
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_anystrobe_depth_notypesz;
  gate[w].extent=8; // 
  gate[w].depths=depth_routebits_anystrobe_depth_notypesz;

  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C32(uint32_t w){ // draft gapped funcbit - if depthbit is 0 do prob
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__ CVL is in gappedfunction
  gate[w].inner=SR_geo_inner_gappedfunction; // this takes care of CVL for depth or for prob
  }
}

void SR_geo_outer_C33(uint32_t w){ // do prob anyways but different [ func [xor] func with cycle] 
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w];
  gate[w].inner=SR_geo_inner_probcyclexorC; 
  }
}


/*

also no use of dacs: depth as dacfrom, dacpar as dacfrom, length as dacfrom ///with depth used as dac - what we do with CV? use as length

4sets x4
- runglers/speed eg. spdfracdac3
- basic probs - last 3 we pulled out / gapped speed? see below...
- prob functions  / gapped speed?
- impose dacs or do that earlier

*/
	  
//4.0/////// rungler + speeds //  gapped funcs

void SR_geo_outer_C40(uint32_t w){ // basic rungler with gapped function
  if (gate[w].changed==0) {
    gate[w].matrix[0]=24<<7; //zbinrouteSRbits I hope // checked
    gate[w].matrix[1]=CV[w]; // depth as route in this case
    gate[w].matrix[4]=CVL[w];// depth
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    gate[w].inner=SR_geo_inner_function;
  }
}

void SR_geo_outer_C41(uint32_t w){   // dacspeeds fixed speedfunc
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=CVL[w];//speed2
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    gate[w].inner=SR_geo_inner_dacspeed3;
  }
}

void SR_geo_outer_C42(uint32_t w){   ////- draft /test speedmodes can have dac as depth (or cv plus dac etc) - *speedfromnostrobe_noIN* [32] // calc is in outer but new func in inner...
  int32_t in, tmp, depth;
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // changes all speeds
    in=gate[speedfrom[spdcount][w]].dac; // and other operations to trial
    depth=CV[w];
    /*

      2.   tmp=(in>>1)+(depth>>1);
      if (tmp>4095) tmp=4095;
      
      3.   tmp=(depth)-2048; // adapted for full bits
      tmp+=in;  
      if (tmp<0) tmp=0;
      else if (tmp>4095) tmp=4095;

      4,  tmp=in+depth;
      tmp=tmp&4095;

     */
    tmp=(depth)-2048; // adapted for full bits
    tmp+=in;  
    if (tmp<0) tmp=0;
    else if (tmp>4095) tmp=4095;

    gate[w].matrix[1]=tmp;
    gate[w].inner=SR_geo_inner_testdacasdepth;
  }
}

void SR_geo_outer_C43(uint32_t w){ // speed function select
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    gate[w].inner=SR_geo_inner_function; 
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 5.0 - generic probs with gapped speeds 

void SR_geo_outer_C50(uint32_t w){ // select prob function ??? but how when we cant feel difference
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[9]=CVL[w]; // select prob function
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho... 
  gate[w].inner=SR_geo_inner_probcycleC; 
  }
}

void SR_geo_outer_C51(uint32_t w){ // probzeroes
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].matrix[10]=CVL[w];
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...

  gate[w].inner=SR_geo_inner_functionprobzero;//
  }
}

void SR_geo_outer_C52(uint32_t w){ 
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[10]=CVL[w]; // probCV1
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_probcycleC; 
  }
}

void SR_geo_outer_C53(uint32_t w){ 
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].matrix[10]=CVL[w]; // probCV1
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_probcyclexorC; 
  }
}


// 6.0 
void SR_geo_outer_C60(uint32_t w){ // select prob function // also: probf_anystrobe_nodepth >>8 // 16
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[9]=CVL[w]; // select prob function
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_probcycleCnodepth; 
  }
}

// can select alt func for this prob -> 12][ SR_geo_inner_probnodepth
void SR_geo_outer_C61(uint32_t w){ 
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].matrix[12]=CVL[w]; // select alt prob function
  gate[w].inner=SR_geo_inner_probnodepth; 
  }
}

// back to full depths as we have sel and alt. cv as depth
void SR_geo_outer_C62(uint32_t w){ 
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[10]=CVL[w]; // prob depth CV1
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probdepth; 
  }
}

// 63???

// 7.0- dacfroms ???



/////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////

void SR_geo_outer_strobexor(uint32_t w){   // test strobexor
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // select spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].funcbit=routebits_nostrobe_depth_notypesz;   // we make sure function is NO STROBE!
    gate[w].extent=8; // checked!
    gate[w].depths=depth_routebits_nostrobe_depth_notypesz;
  
    gate[w].inner=SR_geo_inner_function_strobexor;
  }
}

// uses speedfromnostrobe_noIN array

void SR_geo_outer_strobegap(uint32_t w){   // test gapped strobe function // CV and CVL?
  if (gate[w].changed==0) {
    gate[w].matrix[3]=CVL[w]; // bit mode
    gate[w].matrix[4]=CV[w]; // depth

    gate[w].str_funcbit=routebits_nostrobe_depth_typesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=7; // checked!
    gate[w].str_depths=depth_routebits_nostrobe_depth_typesz;

    gate[w].inner=SR_geo_inner_str_function;
  }
}


/*
8.0, 9.0 10.0 11.0 -> strobe functions

see geo.c

first set is basic strobe speed functions maybe with routes at beginning 00... then more complex into probs with CV and CVL

we can also use CV-param and CVL-function select across various arrays and then gap array...

- *strobe function from below: prob (depth vs. in/LFSR) of route X(global/theroute) vs route Y(another depth) - so we need that function*

 */


/*

- prob re-workings/rework new functions for prob without depth/lfsr

*clean up probs. also some non-depth probs now have depth*
*checking probs and now we have issue as some are against LFSR__ which we filled in some route functions which had no depth (also some already use LFSR)...*
*or use opposing LFSRs as can't use same at same speed*

*if we have probs using depth is nice to have nodepth/route only functions // or if depth say for LFSR is fixed does that work? test//*

but we can always gap route and depth...

*also if we use CV for depth for prob, then we have free CVL depth for functions*

 */

// for strobe: - *do we have prob of route x vs route y* // depth for prob so... leaves what? for strobe modes only with prob on cv and cvl as x vs. theroute *TODO* how that works? do as special inner and depth // Zbinrout_strip is now for depth


