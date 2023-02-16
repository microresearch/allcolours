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

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w) ^ (*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0,0,w))    { // speedfunc
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

  if (spdfracdac4x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc/
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

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
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

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
    gate[w].fake=1;//
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_str_function2(uint32_t w){  // for strobe functions  speedfromstrobe_depth >>8
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_depth[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=1;//
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_str_probcycleC(uint32_t w){  // for strobe - 
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[0]>>8])(0,0, w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    if ((*probf_nostrobe_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
  }
  else {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
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

void SR_geo_inner_probcycleC(uint32_t w){ 
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

void SR_geo_inner_probcycleCnodepth(uint32_t w){  
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

    if ((*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(0,0, w)){
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
  }
  else {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  }    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probcyclexorC(uint32_t w){  
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

    if (!(*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);	   // cycle bit
    }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probcyclexorCnodepth(uint32_t w){  
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

void SR_geo_inner_probcyclexorinvC(uint32_t w){  
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

void SR_geo_inner_runggappedC(uint32_t w){  // no probability, no adc - this can be generic // no interp
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
    // deal with the gap
    if (gate[w].depths[gate[w].matrix[3]>>gate[w].extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*   
      bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    else { // prob of cycle or in new version xor cycle...
        if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      }
      else {
	bitn^= (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
      }
    }
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
    //    bitn=(gate[w].funcbit[gate[w].matrix[12]>>gate[w].extent])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped - fix now so is different
    bitn=(routebits_nodepth_typesz[gate[w].matrix[12]>>6])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped - fix now so is different
    //    - XXroutebits_nodepth_typesz <<6 [64] = C20
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
    //    bitn=(gate[w].funcbit[gate[w].matrix[12]>>gate[w].extent])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
    bitn=(routebits_nodepth_typesz[gate[w].matrix[12]>>6])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped - fix now so is different
  }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probdepthx(uint32_t w){  // draft for probs with depth NOIN
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

    if ((*probf_anystrobe_depth_noin[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)) {
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
  else {
    //    bitn=(gate[w].funcbit[gate[w].matrix[12]>>gate[w].extent])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
    bitn=(routebits_nodepth_typesz[gate[w].matrix[12]>>6])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped - fix now so is different
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

void SR_geo_inner_gappedfunctionS(uint32_t w){  // depth or cycle prob
  HEADNADA;
  gate[w].strobed=1;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=1;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    if (gate[w].depths[gate[w].matrix[3]>>gate[w].extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*   
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


void SR_geo_inner_str_gappedfunction(uint32_t w){  // depth or cycle prob
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  //    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    if (gate[w].str_depths[gate[w].matrix[17]>>gate[w].str_extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*   
      bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    else { // prob of cycle or in new version xor cycle...
      if ((*probf_nostrobe_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      }
      else {
	bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
      }	  
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_str_probfunction(uint32_t w){  // generic prob 	// routebits_nostrobe_depth_notypesz >>8
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
      if ((*probf_nostrobe_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      }
      else {
	//	bitn=(gate[w].str_funcbit[gate[w].matrix[12]>>gate[w].str_extent])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
	bitn=(routebits_nostrobe_depth_notypesz[gate[w].matrix[12]>>8])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
      }	  
      BITN_AND_OUTV_; 
      new_data(val,w);
    }
}

void SR_geo_inner_str_probfunctionalt(uint32_t w){  // generic prob 	//routebits_nostrobe_depth_typesz >>7
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
      if ((*probf_nostrobe_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      }
      else {
	//	bitn=(gate[w].str_funcbit[gate[w].matrix[12]>>gate[w].str_extent])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
	bitn=(routebits_nostrobe_depth_typesz[gate[w].matrix[12]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
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
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    else { // prob of cycle or in new version xor cycle...
      // set prob depth
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
      if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
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
  if (gate[w].changed==1) 
    {
    RESETC; // added 21/12 only reset on change
    gate[w].changed=0;
  }
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[13]=CVL[w]; // dactype
  gate[w].inner=SR_geo_inner_globalC; // routetype/theroute so always at reset route/base global
}

void SR_geo_outer_C01(uint32_t w){ // prob2 - invert
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=6<<7; // NZbinroutfixed_prob2 - type/prob against LFSR and globflag // or 14 prob3? inv cycle - checked for new array and is 6
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=7; // 7 bits above
  gate[w].inner=SR_geo_inner_function;
  }
}

void SR_geo_outer_C02(uint32_t w){ // prob1 - route vs cycle
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=5<<7; // NZbinroutfixed_prob1 - type/prob against LFSR and globflag - checked for new array
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=7; 
  gate[w].inner=SR_geo_inner_function;
  }
}

void SR_geo_outer_C03(uint32_t w){ // prob4 - route vs. [route^cycle]
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=8<<7; // NZbinroutfixed_prob4 - type/prob against LFSR and globflag
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=7; 
  gate[w].inner=SR_geo_inner_function;
  }
}

//1.0//////// route, dacparam, length, what else?

void SR_geo_outer_C10(uint32_t w){ // change type. route above depth - type doesn't change so much. esp not at high speeds
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  SETROUTETYPECV; 
  gate[w].inner=SR_geo_inner_globalC; // was depth route
  }
}

void SR_geo_outer_C11(uint32_t w){ // dacparam... theroute is now fixed
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[14]=CVL[w]; // set dacparam
  gate[w].inner=SR_geo_inner_globalC; 
  }
}

void SR_geo_outer_C12(uint32_t w){ // length - length only notices at slower speeds
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_globalC; 
  }
}

void SR_geo_outer_C13(uint32_t w){ // change route. gapped type // depth as route
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=22<<7; // Zbinrout_strip=22 checked
  gate[w].matrix[4]=CVL[w];
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=7; 
  gate[w].inner=SR_geo_inner_function; 
  }
}

//2.0//////// select functions, cv->depth

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
  gate[w].matrix[3]=CVL[w]; // function  select routebits_depth_typesz[32] 20 is good!
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
  gate[w].extent=7; // 
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
  gate[w].extent=7; // 
  gate[w].depths=depth_routebits_anystrobe_depth_notypesz;

  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C32(uint32_t w){ // draft gapped funcbit - if depthbit is 0 do prob
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[4]=CVL[w];
  gate[w].matrix[10]=CVL[w];  
  gate[w].inner=SR_geo_inner_gappedfunction; // 
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

4sets x4
- runglers/speed eg. spdfracdac3
- basic probs - last 3 we pulled out / gapped speed? see below...
- prob functions  / gapped speed?
- impose dacs or do that earlier

*/
	  
//4.0/////// rungler + speeds //  gapped funcs

void SR_geo_outer_C40(uint32_t w){ // basic rungler with gapped route function
  if (gate[w].changed==0) {
    gate[w].matrix[0]=24<<7; //zbinrouteSRbits I hope 
    gate[w].matrix[1]=CV[w]; // depth as route in this case
    gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    gate[w].inner=SR_geo_inner_gappedfunction;
  }
}

void SR_geo_outer_C41(uint32_t w){   // dacspeeds fixed speedfunc .. could be dacspeed4 and speedfrom vesrions...
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
  gate[w].matrix[10]=CVL[w];
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho... 
  gate[w].inner=SR_geo_inner_probcycleC; 
  }
}

void SR_geo_outer_C51(uint32_t w){ // probzeroes
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].matrix[10]=CVL[w]; // prob depth
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


// 6.0 prob functions 
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

void SR_geo_outer_C61(uint32_t w){ // select prob function // also: probf_anystrobe_nodepth >>8 // 16
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[9]=CVL[w]; // select prob function
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_probcyclexorCnodepth; 
  }
}

// can select alt func for this prob -> 12][ SR_geo_inner_probnodepth
void SR_geo_outer_C62(uint32_t w){ 
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
void SR_geo_outer_C63(uint32_t w){ // prob with depth
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[10]=CVL[w]; // prob depth CV1
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probdepth; 
  }
}

// 7.0- TODO: dacfroms - can also be placed after probs - gapped all but selectors - or shift earlier...
// depth as dacfrom /// depth for bits, for prob - then CVL as selectors: speed, bits, prob, altprobfunc
// gapped bitfuncs
void SR_geo_outer_C70(uint32_t w){ // gapped speedfunc. dac for depth...
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[3]=CVL[w]; // select function
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2

    gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__
    gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); 
    gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac); 
    gate[w].inner=SR_geo_inner_gappedfunction; // 
  }
}

void SR_geo_outer_C71(uint32_t w){ // gapped speedfunc. dac for length
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[3]=CVL[w]; // select function or could be depth
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac);  // length
    gate[w].inner=SR_geo_inner_function; // 
  }
}

// 52, 53 - dac as probs x2 ?? generic probs or cvl as sel??
// dac as prob - but we don't want to go against IN - need new array there - CVL as sel probf_anystrobe_depth_noin >>7 [32]
void SR_geo_outer_C73(uint32_t w){ // prob with depth
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[9]=CVL[w]; // select
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probdepthx; 
  }
}

void SR_geo_outer_C72(uint32_t w){ // as above but cv sel of alt function
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[12]=CVL[w]; // select alt
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probdepthx; 
  }
}


///////////////////////// 80 90 100 110
// 8.0 strobes

void SR_geo_outer_C80(uint32_t w){   // simple fixed strobe with sel bitfunc and depth: routebits_nostrobe_depth_typesz >>7
  if (gate[w].changed==0) {
    gate[w].matrix[15]=0<<8;//  simple strobe
    gate[w].matrix[17]=CV[w]; // bit mode
    gate[w].matrix[4]=CVL[w]; // depth
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  
    gate[w].str_funcbit=routebits_nostrobe_depth_typesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=7; // checked!
    gate[w].str_depths=depth_routebits_nostrobe_depth_typesz;

    gate[w].inner=SR_geo_inner_str_function;
  }
}

// we also have TYPE, length 

void SR_geo_outer_C81(uint32_t w){   // simple fixed strobe with sel bitfunc and depth: routebits_nostrobe_depth_notypesz >>8
  if (gate[w].changed==0) {
    gate[w].matrix[15]=0<<8;//  simple strobe
    gate[w].matrix[17]=CV[w]; // bit mode - test one at a time
    gate[w].matrix[4]=CVL[w]; // depth
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  
    gate[w].str_funcbit=routebits_nostrobe_depth_notypesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=8; // checked!
    gate[w].str_depths=depth_routebits_nostrobe_depth_notypesz;

    gate[w].inner=SR_geo_inner_str_function;
  }
}

//routebits_nostrobe_nodepth_typesz >>8 //  TYPE
void SR_geo_outer_C82(uint32_t w){   //
  if (gate[w].changed==0) {
    gate[w].matrix[15]=0<<8;//  simple strobe
    gate[w].matrix[17]=CV[w]; // bit mode - test one at a time
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    SETROUTETYPECV; 
    gate[w].str_funcbit=routebits_nostrobe_nodepth_typesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=8; // checked!
    gate[w].str_depths=depth_routebits_nostrobe_nodepth_typesz;

    gate[w].inner=SR_geo_inner_str_function;
  }
}

// for routebits_nostrobe_nodepth_notypesz >>7 - new strobe prob func
void SR_geo_outer_C83(uint32_t w){   //
  if (gate[w].changed==0) {
    gate[w].matrix[15]=0<<8;//  simple strobe
    gate[w].matrix[17]=CV[w]; // bit mode - test one at a time
    gate[w].str_funcbit=routebits_nostrobe_nodepth_notypesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=7; // checked!
    gate[w].str_depths=depth_routebits_nostrobe_nodepth_notypesz;

    gate[w].matrix[9]=0;
    gate[w].matrix[10]=CVL[w];
    
    gate[w].inner=SR_geo_inner_str_probcycleC;
  }
}

////////////////
//9.0

// select strobe speed function with no depth
void SR_geo_outer_C90(uint32_t w){   // 
  if (gate[w].changed==0) {
    gate[w].matrix[15]=CVL[w];// speed func
    gate[w].matrix[17]=CV[w]; // bit mode
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    // what is bitfunc?
    gate[w].str_funcbit=routebits_nostrobe_nodepth_typesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=8; // checked!
    gate[w].str_depths=depth_routebits_nostrobe_nodepth_typesz;
    
    gate[w].inner=SR_geo_inner_str_function;
  }
}

void SR_geo_outer_C91(uint32_t w){   // // routes with depth and gapped strobe speed 91
  if (gate[w].changed==0) {
    gate[w].matrix[17]=CV[w];
    gate[w].matrix[4]=CVL[w];
    
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2

    gate[w].str_funcbit=routebits_nostrobe_depth_typesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=7; // checked!
    gate[w].str_depths=depth_routebits_nostrobe_depth_typesz;
    
    gate[w].inner=SR_geo_inner_str_function;
  }
}

void SR_geo_outer_C92(uint32_t w){   // // routes with depth and gapped strobe speed // c92 length and depth 
  if (gate[w].changed==0) {
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    gate[w].matrix[6]=CV[w]; // length

    gate[w].str_funcbit=routebits_nostrobe_depth_typesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=7; // checked!
    gate[w].str_depths=depth_routebits_nostrobe_depth_typesz;
    
    gate[w].inner=SR_geo_inner_str_function;
  }
}

// // select strobe speed function with depth and gap function
void SR_geo_outer_C93(uint32_t w){   // speedfromstrobe_depth >>8
  if (gate[w].changed==0) {
    gate[w].matrix[15]=CVL[w]; // select
    gate[w].matrix[1]=CV[w]; // speed
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    gate[w].inner=SR_geo_inner_str_function2;
  }
}

// 10.0
// or throw in dacfrom depth and length here...
void SR_geo_outer_C100(uint32_t w){   // depth
  if (gate[w].changed==0) {
    gate[w].matrix[15]=CVL[w];// speed func
    gate[w].matrix[17]=CV[w]; // bit mode
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    // gapped func
    gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__
    gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); 
    gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac); 

    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

void SR_geo_outer_C101(uint32_t w){   // length
  if (gate[w].changed==0) {
    gate[w].matrix[15]=CVL[w];// speed func
    gate[w].matrix[17]=CV[w]; // bit mode
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac);     // length
    // gapped func
    gate[w].inner=SR_geo_inner_str_function;
  }
}

void SR_geo_outer_C102(uint32_t w){   // strobexor with fixed strobe
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // select spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    // other funcs or just gap it?
    //    gate[w].funcbit=routebits_nostrobe_depth_notypesz;   // we make sure function is NO STROBE!
    //    gate[w].extent=8; // checked!
    //    gate[w].depths=depth_routebits_nostrobe_depth_notypesz;
    gate[w].matrix[15]=0; // fixed strobe  
    gate[w].inner=SR_geo_inner_function_strobexor;
  }
} 

void SR_geo_outer_C103(uint32_t w){   // strobexor with var strobe
  if (gate[w].changed==0) {
    //    gate[w].matrix[0]=CVL[w]; // select spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    // other funcs or just gap it?
    //    gate[w].funcbit=routebits_nostrobe_depth_notypesz;   // we make sure function is NO STROBE!
    //    gate[w].extent=8; // checked!
    //    gate[w].depths=depth_routebits_nostrobe_depth_notypesz;
    gate[w].matrix[15]=CVL[w]; // strobe  func sel
    gate[w].inner=SR_geo_inner_function_strobexor;
  }
} 

// // 11.0 strobes including wider probs/probfunctions - how we organise CV/CVL// strobe with no depth
// prob mode, prob depth... CV CVL
void SR_geo_outer_C110(uint32_t w){  
  if (gate[w].changed==0) {
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv1/cv2
    // other funcs or just gap it?
    //    gate[w].str_funcbit=routebits_nostrobe_depth_typesz;   // we make sure function is NO STROBE!
    //    gate[w].str_extent=7; // checked!
    //    gate[w].str_depths=depth_routebits_nostrobe_depth_typesz;
    // first func is gapped
    gate[w].matrix[10]=CVL[w]; // selcv
    gate[w].matrix[12]=CV[w]; // select func2 which is fixed as with depth  
    // for prob we have:
    /*    [9]: selprob
	  [10]: depth
	  [17]: func1 vs [can be no depth] 
	  [12]: func2    [has depth]

	  with [4] and [5] as CVs for each swopped...
    
     */
    gate[w].inner=SR_geo_inner_str_probfunction; // and SR_geo_inner_str_probfunctionalt as diff 2nd array
  }
} 

void SR_geo_outer_C111(uint32_t w){  
  if (gate[w].changed==0) {
    gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); // cv1/cv2
    // first func is gapped
    gate[w].matrix[9]=CVL[w]; // selprob
    gate[w].matrix[5]=CV[w]; // cv1/cv2
    gate[w].inner=SR_geo_inner_str_probfunction; // and SR_geo_inner_str_probfunctionalt as diff 2nd array
  }
} 

void SR_geo_outer_C112(uint32_t w){  //alt
  if (gate[w].changed==0) {
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv1/cv2
    gate[w].matrix[10]=CVL[w]; // depth
    gate[w].inner=SR_geo_inner_str_probfunctionalt; // and SR_geo_inner_str_probfunctionalt as diff 2nd array
  }
} 

void SR_geo_outer_C113(uint32_t w){  // alt
  if (gate[w].changed==0) {
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv1/cv2
    // first func is gapped
    gate[w].matrix[4]=CVL[w]; 
    gate[w].matrix[10]=CV[w]; // depth
    gate[w].inner=SR_geo_inner_str_probfunctionalt; // and SR_geo_inner_str_probfunctionalt as diff 2nd array
  }
} 

// 120, 130, 140, 15 ends 153

////////////////////////////////////////////////////////////////////////////////////////////////////////
// last 16 are matrixp ops to try to sketch out... 4x4 below
// start with matrixp strobe modes

uint32_t fixedvalues[4][16]={ //  
  {0},
};

uint32_t fixed=0, gap=0;

// cut to 16 here and we don't use fixed/gap // lose param
// and these all need to be 12 bit versions
uint32_t *fixedvars[4][16]={ //was 20 
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &ADCin, &Gshift__[0], &Gshift__[1], &Gshift__[2], &Gshift__[3], &clksr__[0], &Gshift__[8], &LFSR__[0], &LFSR__[1], &LFSR__[2]},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &ADCin, &Gshift__[0], &Gshift__[1], &Gshift__[2], &Gshift__[3], &clksr__[1], &Gshift__[8], &LFSR__[0], &LFSR__[1], &LFSR__[2]},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &ADCin, &Gshift__[0], &Gshift__[1], &Gshift__[2], &Gshift__[3], &clksr__[2], &Gshift__[8], &LFSR__[0], &LFSR__[1], &LFSR__[2]},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &ADCin, &Gshift__[0], &Gshift__[1], &Gshift__[2], &Gshift__[3], &clksr__[3], &Gshift__[8], &LFSR__[0], &LFSR__[1], &LFSR__[2]},
};

uint32_t maparrayCCS[16]={3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 3, 4, 5}; // for strobed
uint32_t maparrayCC[16]={0,  1, 2, 3, 4, 5,    6, 9, 10, 11, 12, 13, 14, 16, 0, 1}; // unstrobed

void SR_geomantic_matrixcopyz(uint32_t w){ 
  uint32_t x;
  for (x=0;x<22;x++){
    if (gate[w].set[x]) gate[w].matrix[x]=*(gate[w].matrixp[x]); 
  }
}

void SR_geomantic_matrixcopyfixz(uint32_t w){ 
  uint32_t x;
  for (x=0;x<22;x++){
    if (gate[w].set[x]) gate[w].matrix[x]=*(gate[w].matrixp[x]);
    else gate[w].matrixp[x]=&gate[w].matrix[x];// fixed one
  }
}

static inline void setvargapz(uint32_t wh, uint32_t which, uint32_t var){ // sets gap with one of fixedvars - is not really a gap? tested in test2.c yes it just sets one
  static uint32_t oldgap[4]={2,2,2,2};
  if (which!=oldgap[wh]){// only if we want a new one not to reset the same one...
    gate[wh].matrixp[oldgap[wh]]=gate[wh].matrixpG[oldgap[wh]];//
    gate[wh].matrixpG[which]=gate[wh].matrixp[which]; // previous  
    gate[wh].matrixp[which]=fixedvars[wh][var]; // new one
    gate[wh].set[which]=1;
  }
  oldgap[wh]=which;
}

// we need a different version - if we are in same matrixp but want to change it
static inline void setvargapzz(uint32_t wh, uint32_t which, uint32_t var){ // sets gap with one of fixedvars - is not really a gap? tested in test2.c yes it just sets one
  static uint32_t oldgap[4]={2,2,2,2};
    if (which!=oldgap[wh]){// only if we want a new one not to reset the same one...
    gate[wh].matrixp[oldgap[wh]]=gate[wh].matrixpG[oldgap[wh]];//
    gate[wh].matrixpG[which]=gate[wh].matrixp[which]; // previous  
    gate[wh].matrixp[which]=fixedvars[wh][var]; // new one
    gate[wh].set[which]=1;
  }
    else if (gate[wh].matrixp[oldgap[wh]]!=fixedvars[wh][var]){
    gate[wh].matrixp[which]=fixedvars[wh][var]; // new one
    gate[wh].set[which]=1;
    }
  oldgap[wh]=which;
}

static inline void setgapz(uint32_t wh, uint32_t which){ 
  static uint32_t oldgap[4]={1,1,1,1};
  if (which!=oldgap[wh]){
    gate[wh].matrixp[which]=&gate[wh].matrix[which]; // last value...
  }
  oldgap[wh]=which;
}

static inline void setvargapzbleed(uint32_t wh, uint32_t which, uint32_t var){ // bleeds values across but obscures any attachments
  static uint32_t oldgap[4]={1,1,1,1};
  if (which!=oldgap[wh]){
    gate[wh].matrixp[oldgap[wh]]=&gate[wh].matrix[oldgap[wh]];// fixed one
    gate[wh].matrixp[which]=fixedvars[wh][var]; // new one
    gate[wh].set[which]=1;
  }
  oldgap[wh]=which;
}

static inline void setvarz(uint32_t wh, uint32_t which, uint32_t var){ // plain set
  gate[wh].matrixp[which]=fixedvars[wh][var]; // new one
  gate[wh].set[which]=1;
}

////////12.0

void SR_geo_outer_C120(uint32_t w){   // strobe // slide across and set to CVL
  if (gate[w].changed==0) {
    setvargapz(w, maparrayCCS[(CV[w]>>8)], 5); // 5 is CVL
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

// set to CV with CVL,
void SR_geo_outer_C121(uint32_t w){   // strobe // slide across and set to CV
  if (gate[w].changed==0) {
    setvargapz(w, maparrayCCS[(CVL[w]>>8)], 4); // 4 is CV
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

//  122. set to gshift dacfrom
void SR_geo_outer_C122(uint32_t w){   // strobe // slide across and set to dacfrom // what do we do with CVL though - this can still be attached from the previous?
  if (gate[w].changed==0) {
    setvargapz(w, maparrayCCS[(CV[w]>>8)], 7+dacfrom[daccount][w]); // gshift starts from 7 
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

// dacfrom set to
void SR_geo_outer_C123(uint32_t w){   // strobe // slide across and set to dacfrom // what do we do with CVL though - this can still be attached from the previous?
  if (gate[w].changed==0) {
    setvargapz(w, maparrayCCS[(CV[w]>>8)], dacfrom[daccount][w]); // dacfrom starts from 0
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

// 13.0

void SR_geo_outer_C130(uint32_t w){   // set CV to CVL 
  if (gate[w].changed==0) {
    // set matrixp from CV and CVL
    setvarz(w, maparrayCCS[(CV[w]>>8)], CVL[w]>>8); // 4 bits
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

void SR_geo_outer_C131(uint32_t w){   // set gap - tested!
  if (gate[w].changed==0) {
    setgapz(w, maparrayCCS[(CV[w]>>8)]);
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

// bleeding one as 130 CV and CVL
void SR_geo_outer_C132(uint32_t w){   // set CV to CVL 
  if (gate[w].changed==0) {
    // set matrixp from CV and CVL
    setvargapzbleed(w, maparrayCCS[(CV[w]>>8)], CVL[w]>>8); // 4 bits
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

// empty one for CV, CVL uses if any...
void SR_geo_outer_C133(uint32_t w){ 
  if (gate[w].changed==0) {
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_str_gappedfunction;
  }
}

// 140+ CVspeed so we need different mapping: maparrayCC
/*
 - we cant use CV to set, so what stategies do we have?

- use of trigger to increment a local counter  - bit just means we bump on so not so exciting
- use of SR as a mask or increment too
 */

void SR_geo_outer_C140(uint32_t w){  //if we just use here then don;t need indie version
  static uint32_t cnnnt=0;
  if (gate[w].changed==0) {
    if (gate[w].trigger) {
      cnnnt++;
      if (cnnnt>15) cnnnt=0;
    }
    setvargapz(w, maparrayCC[cnnnt], 5); // 5 is CVL
    SR_geomantic_matrixcopyz(w);
    // keep speed feels bit odd as we do set this
    gate[w].matrix[1]=CV[w];
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_gappedfunctionS; // for strobed set we need
  }
}

void SR_geo_outer_C141(uint32_t w){   // dacfrom set
  static uint32_t cnnnt=0;
  if (gate[w].changed==0) {
    if (gate[w].trigger) {
      cnnnt++;
      if (cnnnt>15) cnnnt=0;
    }    
    setvargapz(w, maparrayCCS[cnnnt], dacfrom[daccount][w]); // gshift starts from 7
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_gappedfunctionS;
  }
}

// can just copy from strobes but can have different functions // 

void SR_geo_outer_C142(uint32_t w){   // dacfrom set by SR
  static uint32_t cnnnt=0;
  if (gate[w].changed==0) {
    cnnnt=gate[dacfromopp[daccount][w]].dac>>8; // 4
    setvargapz(w, maparrayCCS[cnnnt], 4); // CV
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_gappedfunction;
  }
}

void SR_geo_outer_C143(uint32_t w){   // dacfrom set trigger and mask
  static uint32_t cnnnt=0;
  if (gate[w].changed==0) {
    if (gate[w].trigger) {
      if (gate[dacfromopp[daccount][w]].shift_&0x01) cnnnt++;
      if (cnnnt>15) cnnnt=0;
    }    
    setvargapzz(w, maparrayCCS[cnnnt], CV[w]>>8); 
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_gappedfunctionS;
  }
}

// 150 - we can also have CV and CVL in non-strobe - 

void SR_geo_outer_C150(uint32_t w){   // set CV to CVL 
  if (gate[w].changed==0) {
    // set matrixp from CV and CVL
    setvargapzz(w, maparrayCCS[(CV[w]>>8)], CVL[w]>>8); // 4 bits
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_gappedfunction;
  }
}

// 151 - SR bits are set to CV or CVL defined...
void SR_geo_outer_C151(uint32_t w){
  uint32_t x, tmp,tmpp;
  if (gate[w].changed==0) {
    tmpp=gate[dacfrom[daccount][w]].shift_;
    for (x=0;x<16;x++){
      tmp=tmpp&0x01;
      if (tmp) {
	gate[w].matrixp[x]=&gate[w].matrix[x];
	gate[w].set[x]=1;
      }
      tmpp=tmpp>>1;
    }
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_gappedfunction;
  }
}

// 152 SR bits are gaps in matrixp
void SR_geo_outer_C152(uint32_t w){
  uint32_t x, tmp,tmpp;
  if (gate[w].changed==0) {
    tmpp=gate[dacfrom[daccount][w]].shift_;
    for (x=0;x<16;x++){
      tmp=tmpp&0x01;
      if (tmp) {
	gate[w].matrixp[x]=&gate[w].matrix[x];
	gate[w].set[x]=1;
      }
      tmpp=tmpp>>1;
    }
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrix[16]>>9;
    gate[w].inner=SR_geo_inner_gappedfunction;
  }
}



/* 

no strobe: 

// also we can have nets which are placed over settings and influence which ones we set...

// matrices also from SR, and set copied from SR - how to organise?

 */

// 153: final one is reset but what does CVL do there? last bit or prob
void SR_geo_outer_C153(uint32_t w){  // final all gapped reset
  if (gate[w].changed==1) {
    RESETC; 
    gate[w].changed=0;
  }
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].matrix[4]=CVL[w];
  gate[w].matrix[10]=CVL[w];  
  gate[w].inner=SR_geo_inner_gappedfunction;
    }
