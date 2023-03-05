//- TODO: fill in and simplify geoC according to 16/16/16/16 modes

// CC: dactype and param, probs or route/etc, routes, speed mods as primary

//extern void send_command(int command, void *message);
//char buffx[10];

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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7];
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    else if (w==3) bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
    bitn^=binroutesel0(0,0,w); // global route which is ... and routetype
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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7];
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_function_strobexor(uint32_t w){ 
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w) ^ (*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0,0,w))    { // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7];
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed4(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac4x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc/
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_str_function(uint32_t w){  // for strobe functions  - but here we do just in nor in^bit
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7];
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    bitn^=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTVS_; 
    new_data(val,w);
    }
}

// just changes for NN
void SR_geo_inner_str_functionN(uint32_t w){  // for strobe functions  - but here we do just in nor in^bit
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7];
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    else bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTVS_; 
    new_data(val,w);
    }
}

void SR_geo_inner_str_function2(uint32_t w){  // for strobe functions  speedfromstrobe_depth >>8
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_depth[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    bitn^=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTVS_; 
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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	bitn = 0;
      }
	  
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_functionproblast(uint32_t w){  
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
      if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
      else bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	bitn = gate[w].lastest;
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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
  }
  else {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  }    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probroutes(uint32_t w){ 
  // what cv we need: probfs: 9type,10comp... 11IN 3,4,5 is gapped...
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
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=Zbinrouteforalt(gate[w].matrix[4], gate[w].matrix[5], w); 
  }
  else {
    bitn^=Zbinrouteforaltalt(gate[w].matrix[4], gate[w].matrix[5], w); 
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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    if ((*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(0,0, w)){
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
  }
  else {
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    else if (w==3) bitn=(*abstractbitsz[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); 
    else bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit    
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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 

    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      if (w==0)     bitn^=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix
      else if (w==3) bitn=(*abstractbitsz[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); 
      else bitn^=((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);	   // cycle bit
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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 

    if (!(*probf_anystrobe_nodepth[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){
      if (w==0) bitn^=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
      else bitn^=((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);	   // cycle bit
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
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 

    if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=(!(gate[w].Gshift_[w]>>SRlength[w]) & 0x01);	   // cycle bit INV
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rungC(uint32_t w){ 
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    bitn=(*abstractbitsz[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probnodepth(uint32_t w){  // draft for probs with no depth
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
        bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
  else {
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    else if (w==3) bitn=(*abstractbitsz[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); 
    else bitn=(routebits_nodepth_typesz[gate[w].matrix[12]>>extent_routebits_nodepth_typesz])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped - fix now so is different
  }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probdepthnodepth(uint32_t w){  // draft for probs with no depth alt
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
        bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
  else {
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    else bitn=(routebits_nodepth_typesz[gate[w].matrix[12]>>extent_routebits_nodepth_typesz])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped - fix now so is different
  }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probdepth(uint32_t w){  // draft for probs with depth
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

    if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)) {
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
  else {
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
    else if (w==3) bitn=(*abstractbitsz[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); 
    else bitn=(routebits_depth_typesz[gate[w].matrix[12]>>extent_routebits_nodepth_typesz])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped - fix now so is different
    // what alts there could be - but this is good as default
  }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// for matrixP ops!
void SR_geo_inner_probdepthdepthS(uint32_t w){  // draft for probs with depth WE SET STROBE - uses matrixX! 
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrixX[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrixX[0]>>7])(gate[w].matrixX[1], gate[w].matrixX[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrixX[6]>>7]; 

    if (!(*probf_anystrobe_depth[gate[w].matrixX[9]>>6])(gate[w].matrixX[10], gate[w].matrixX[11], w)) {
      bitn=(gate[w].funcbit[gate[w].matrixX[3]>>gate[w].extent])(gate[w].matrixX[4], gate[w].matrixX[5], w);
    }
  else {
    if (w==0) bitn=(*inall[gate[w].matrixX[7]>>6])(gate[w].matrixX[8], gate[w].matrixX[21], w);  // fixed
    else bitn=(routebits_depth_typesz[gate[w].matrixX[12]>>extent_routebits_depth_typesz])(gate[w].matrixX[5], gate[w].matrixX[4], w);
    // what alternatives could be? routebits_anystrobe_notypezs // depth and no depth mixed
    // or routebits_nodepth_typesz
  }
    gate[w].strobed=1;
    BITN_AND_OUTVX_; 
    new_data(val,w);
    }
}

// NN only 
void SR_geo_inner_probdepthdepthSN(uint32_t w){  // draft for probs with depth WE SET STROBE - uses matrixX! 
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrixX[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrixX[0]>>7])(gate[w].matrixX[1], gate[w].matrixX[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrixX[6]>>7]; 

    if (!(*probf_anystrobe_depth[gate[w].matrixX[9]>>6])(gate[w].matrixX[10], gate[w].matrixX[11], w)) {
      bitn=(gate[w].funcbit[gate[w].matrixX[3]>>gate[w].extent])(gate[w].matrixX[4], gate[w].matrixX[5], w);
    }
  else {
    if (w==0) bitn=(*inall[gate[w].matrixX[7]>>6])(gate[w].matrixX[8], gate[w].matrixX[21], w);  // fixed
    bitn^=(routebits_depth_typesz[gate[w].matrixX[12]>>extent_routebits_depth_typesz])(gate[w].matrixX[5], gate[w].matrixX[4], w);
    // what alternatives could be? routebits_anystrobe_notypezs // depth and no depth mixed
    // or routebits_nodepth_typesz
  }
    gate[w].strobed=1;
    BITN_AND_OUTVX_; 
    new_data(val,w);
    }
}


void SR_geo_inner_probdepthdepthSS(uint32_t w){  // draft for probs with depth WE SET STROBE - uses matrixX! 
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrixX[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrixX[0]>>7])(gate[w].matrixX[1], gate[w].matrixX[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrixX[6]>>7]; 

    if (!(*probf_anystrobe_depth[gate[w].matrixX[9]>>6])(gate[w].matrixX[10], gate[w].matrixX[11], w)) {
      bitn=(gate[w].funcbit[gate[w].matrixX[3]>>gate[w].extent])(gate[w].matrixX[4], gate[w].matrixX[5], w);
    }
  else {
    if (w==0) bitn=(*inall[gate[w].matrixX[7]>>6])(gate[w].matrixX[8], gate[w].matrixX[21], w);  // fixed
    else bitn=(routebits_anystrobe_notypesz[gate[w].matrixX[12]>>extent_routebits_anystrobe_notypesz])(gate[w].matrixX[5], gate[w].matrixX[4], w);
    // what alternatives could be? routebits_anystrobe_notypezs // depth and no depth mixed
    // or routebits_nodepth_typesz
  }
    gate[w].strobed=1;
    BITN_AND_OUTVX_; 
    new_data(val,w);
    }
}

// for matrixP
void SR_geo_inner_str_probfunctionX(uint32_t w){  // generic prob 	// routebits_nostrobe_depth_notypesz >>8
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_all[gate[w].matrixX[15]>>7])(gate[w].matrixX[1], gate[w].matrixX[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrixX[6]>>7]; 
          if ((*probf_nostrobe_depth[gate[w].matrixX[9]>>7])(gate[w].matrixX[10], gate[w].matrixX[11], w)){
	    bitn=(gate[w].str_funcbit[gate[w].matrixX[17]>>gate[w].str_extent])(gate[w].matrixX[4], gate[w].matrixX[5], w); 
          }
          else {
	    if (w==0)     bitn=(*inall[gate[w].matrixX[7]>>6])(gate[w].matrixX[8], gate[w].matrixX[21], w);  /// WHICH WAY round?
	    else bitn=(routebits_nostrobe_depth[gate[w].matrixX[12]>>extent_routebits_nostrobe_depth])(gate[w].matrixX[5], gate[w].matrixX[4], w); // swopped
	// what are alternatives for this:  routebits_nostrobe_nodepth 64 - all types
	  }	  
    BITN_AND_OUTVXS_; 
    new_data(val,w);
    }
}

// just differs for w==0
void SR_geo_inner_str_probfunctionXX(uint32_t w){  // generic prob 	// routebits_nostrobe_depth_notypesz >>8
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_all[gate[w].matrixX[15]>>7])(gate[w].matrixX[1], gate[w].matrixX[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrixX[6]>>7]; 
          if ((*probf_nostrobe_depth[gate[w].matrixX[9]>>7])(gate[w].matrixX[10], gate[w].matrixX[11], w)){
	    bitn=(gate[w].str_funcbit[gate[w].matrixX[17]>>gate[w].str_extent])(gate[w].matrixX[4], gate[w].matrixX[5], w); 
          }
          else {
	    if (w==0) {
	      bitn=(gate[w].str_funcbit[gate[w].matrixX[17]>>gate[w].str_extent])(gate[w].matrixX[4], gate[w].matrixX[5], w); 
	      bitn^=(*inall[gate[w].matrixX[7]>>6])(gate[w].matrixX[8], gate[w].matrixX[21], w);  /// WHICH WAY round?
	    }
	    else bitn=(routebits_nostrobe_depth[gate[w].matrixX[12]>>extent_routebits_nostrobe_depth])(gate[w].matrixX[5], gate[w].matrixX[4], w); // swopped
	// what are alternatives for this:  routebits_nostrobe_nodepth 64 - all types
	  }	  
    BITN_AND_OUTVXS_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probdepthx(uint32_t w){  // draft for probs with depth NOIN
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

    if (!(*probf_anystrobe_depth_noin[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)) {
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
  else {
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    else bitn=(routebits_depth_typesz[gate[w].matrix[12]>>extent_routebits_nodepth_typesz])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped - fix now so is different
    // can be alts...
  }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_gappedfunction(uint32_t w){  // depth or alt
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
    if (w==0)     bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix

    if (gate[w].depths[gate[w].matrix[3]>>gate[w].extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*   
      bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    }
    else { 
        if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	bitn^=(routebits_depth_typesz[gate[w].matrix[12]>>extent_routebits_depth_typesz])(gate[w].matrix[5], gate[w].matrix[4], w);
      }
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_gappedfunctionC(uint32_t w){  // depth or alt
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
    if (gate[w].depths[gate[w].matrix[3]>>gate[w].extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*
      if (w==0)     bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix
      bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    }
    else { 
        if (!(*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	if (w==0)     bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix // prob of entry
	else bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
      }
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_str_gappedfunction(uint32_t w){  // depth or cycle prob
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7];
    if (w==0)     bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);  /// new one with mix

    if (gate[w].str_depths[gate[w].matrix[17]>>gate[w].str_extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*   
      bitn^=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    }
    else { 
      if (!(*probf_nostrobe_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn^=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	bitn^=(routebits_nostrobe_depth[gate[w].matrix[12]>>extent_routebits_nostrobe_depth])(gate[w].matrix[5], gate[w].matrix[4], w);
      }	  
    }
    BITN_AND_OUTVS_; 
    new_data(val,w);
    }
}

void SR_geo_inner_str_probfunction(uint32_t w){  // generic prob 	// routebits_nostrobe_depth_notypesz >>8
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
      if (!(*probf_nostrobe_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
	else if (w==3) bitn=(*abstractbitsz_nostr[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); 
	else	bitn=(routebits_nostrobe_depth[gate[w].matrix[12]>>extent_routebits_nostrobe_depth])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
      }	  
      BITN_AND_OUTVS_; 
      new_data(val,w);
    }
}

void SR_geo_inner_str_probfunctionalt(uint32_t w){  // generic prob 	//routebits_nostrobe_depth_typesz >>7
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if ((*speedfromstrobe_nodepth[gate[w].matrix[15]>>8])(0, 0, w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
      if (!(*probf_nostrobe_depth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w);
	else if (w==3) bitn=(*abstractbitsz_nostr[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); 
	else bitn=(routebits_nostrobe_nodepth[gate[w].matrix[12]>>extent_routebits_nostrobe_nodepth])(gate[w].matrix[5], gate[w].matrix[4], w); // swopped
      }	  
      BITN_AND_OUTVS_; 
      new_data(val,w);
    }
}

void SR_geo_inner_null(uint32_t w){
  // nada
}

void SR_geo_innerxorC(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ( (*speedfromcvforxor[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w) ^ zbinroutfixed_noshift(0,0,w) ){ // speedfunc xor with fromforxor->binroutfixed...
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    if (w==0) bitn=(*inall[gate[w].matrix[7]>>6])(gate[w].matrix[8], gate[w].matrix[21], w); 
    else bitn=(gate[w].str_funcbit[gate[w].matrix[17]>>gate[w].str_extent])(gate[w].matrix[4], gate[w].matrix[5], w); 

    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

void SR_geo_outer_route(uint32_t w){  // fixed route // the most basic but no reset
  gate[w].matrix[0]=2<<7; // spdfracend with interpoll
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // speed
  gate[w].inner=SR_geo_inner_globalC; // global route
}

void SR_geo_outer_null(uint32_t w){  // nada
  gate[w].inner=SR_geo_inner_null;
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
  gate[w].matrix[13]=CVL[w]; // dactype = 13 /5,6,17 are strobed
  gate[w].inner=SR_geo_inner_globalC; // routetype/theroute so always at reset route/base global
}

void SR_geo_outer_C01(uint32_t w){ // prob2 - invert
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=6<<6; // NZbinroutfixed_prob2 - type/prob against LFSR and globflag // or 14 prob3? inv cycle - checked for new array and is 6
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz;
  gate[w].inner=SR_geo_inner_function;
  }
}

void SR_geo_outer_C02(uint32_t w){ // prob1 - route vs cycle
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=5<<6; // NZbinroutfixed_prob1 - type/prob against LFSR and globflag - checked for new array
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 
  gate[w].inner=SR_geo_inner_function;
  }
}

void SR_geo_outer_C03(uint32_t w){ // prob4 - route vs. [route^cycle]
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=8<<6; // NZbinroutfixed_prob4 - type/prob against LFSR and globflag
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 
  gate[w].inner=SR_geo_inner_function;
  }
}

//1.0//////// route, dacparam, length, what else?

void SR_geo_outer_C10(uint32_t w){ // change type.
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  SETROUTETYPECV; 
  gate[w].inner=SR_geo_inner_globalC; // was depth route
  }
}

void SR_geo_outer_C11(uint32_t w){ // dacparam... 
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
  gate[w].matrix[3]=0<<6; // Zbinrout_strip=0 checked
  gate[w].matrix[4]=CVL[w];
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 
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
  gate[w].extent=extent_routebits_nodepth_typesz; 
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
  gate[w].extent=extent_routebits_anystrobe_nodepth_notypesz; 
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
  gate[w].extent=extent_routebits_depth_typesz; 
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
  gate[w].extent=extent_routebits_depth_typesz; //
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
  gate[w].matrix[3]=CVL[w]; // sel function
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_anystrobe_depth_notypesz;
  gate[w].extent=extent_routebits_anystrobe_depth_notypesz; //7 
  gate[w].depths=depth_routebits_anystrobe_depth_notypesz;
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C31(uint32_t w){ // notypes. depth
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[4]=CVL[w]; // depth ok
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_anystrobe_depth_notypesz;
  gate[w].extent=extent_routebits_anystrobe_depth_notypesz; // 
  gate[w].depths=depth_routebits_anystrobe_depth_notypesz;
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C32(uint32_t w){ // draft gapped funcbit - if depthbit is 0 do prob of cycle
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].matrix[9]=0<<6; // select probfs - zprobbits here against LFSR__
  gate[w].matrix[4]=CVL[w];
  gate[w].matrix[10]=CVL[w];  
  gate[w].inner=SR_geo_inner_gappedfunctionC; // 24/2 
  }
}

void SR_geo_outer_C33(uint32_t w){ // do prob anyways but different [ func [xor] func with cycle] 
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].matrix[9]=0<<6; // select probfs - zprobbits here against LFSR__
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
    gate[w].matrix[0]=24<<7; //zbinrouteSRbits checked
    gate[w].matrix[1]=CV[w]; // depth as route in this case
    gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    gate[w].inner=SR_geo_inner_gappedfunction;
  }
}

void SR_geo_outer_C41(uint32_t w){   // dacspeed3 as fixed speedfunc .. 
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=CVL[w];//speed2
    gate[w].matrix[5]=(gate[speedfrom[spdcount][w]].dac); // cv2
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

void SR_geo_outer_C50(uint32_t w){ // select prob function ??? but how when we cant feel difference - set halfway //cycle
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[9]=CVL[w]; // select prob function
  //  gate[w].matrix[10]=CVL[w];
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho... 
  gate[w].inner=SR_geo_inner_probcycleC; 
  }
}

void SR_geo_outer_C51(uint32_t w){ // probzeroes with depth
   if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].matrix[10]=CVL[w]; // prob depth
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_functionprobzero;//
  }
}

void SR_geo_outer_C52(uint32_t w){ // probcycle with depth
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].matrix[10]=CVL[w];// prob depth 28<<6; // TODO:test all of these: 5->10, 24, 28
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_probcycleC; 
  }
}

void SR_geo_outer_C53(uint32_t w){  //probcyclexor with depth
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].matrix[10]=CVL[w]; // probCV1
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_probcyclexorC; 
  }
}

 
// 6.0 prob functions  for NN too -> 80
void SR_geo_outer_C60(uint32_t w){ // select prob function // also: probf_anystrobe_nodepth >>8 // 16
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[9]=CVL[w]; // select prob function
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_probcycleCnodepth; 
  }
}

void SR_geo_outer_C61(uint32_t w){ // select prob function // also: probf_anystrobe_nodepth >>8 // 16
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[9]=CVL[w]; // select prob function
  gate[w].inner=SR_geo_inner_probcyclexorCnodepth; 
  }
}

// can select alt func for this prob -> 12][ SR_geo_inner_probnodepth
void SR_geo_outer_C62(uint32_t w){ 
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  if (w==0) gate[w].matrix[8]=CVL[w]; // select alt prob function or if cv==0
  else if (w==3) gate[w].matrix[20]=CVL[w];
  else gate[w].matrix[12]=CVL[w]; 
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

    //    gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__ gap that
    gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); 
    gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac); 
    gate[w].inner=SR_geo_inner_gappedfunction; // 
  }
}

void SR_geo_outer_C71(uint32_t w){ // gapped speedfunc. gapped func. dac for length // or if w==0
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[3]=CVL[w]; // select function or could be depth
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    if (w==0) gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac);  // adccv
    else gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac);  // length
    gate[w].inner=SR_geo_inner_function; // 
  }
}

void SR_geo_outer_C72(uint32_t w){ // as above but cv sel of alt function
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  if (w==0) gate[w].matrix[8]=CVL[w];
  else gate[w].matrix[12]=CVL[w]; // select alt
  gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac);  // length
  gate[w].inner=SR_geo_inner_probdepthx; 
  }
}

// dac as prob depth
void SR_geo_outer_C73(uint32_t w){ // prob with depth
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2  
  gate[w].matrix[9]=CVL[w]; // select function
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probdepthx; 
  }
}

// 8.0 strobes

void SR_geo_outer_C80(uint32_t w){   // simple fixed strobe with sel bitfunc and depth: routebits_nostrobe_depth_typesz >>7
  if (gate[w].changed==0) {
    gate[w].matrix[15]=0<<8;//  simple strobe
    if (w==0) {
      gate[w].matrix[8]=CVL[w]; // depth for adc/abstract
      gate[w].matrix[7]=CV[w]; // adc/abstract mode
    }
    else {
      gate[w].matrix[4]=CVL[w]; // depth
      gate[w].matrix[17]=CV[w]; // bit mode
    }
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2

    
    gate[w].str_funcbit=routebits_nostrobe_depth_typesz;   // we make sure function is NO STROBE!
    gate[w].str_extent=extent_routebits_nostrobe_depth_typesz;
    gate[w].str_depths=depth_routebits_nostrobe_depth_typesz;

    gate[w].inner=SR_geo_inner_str_functionN; // just changes for NN solo
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
    gate[w].str_extent=extent_routebits_nostrobe_depth_notypesz;
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
    gate[w].str_extent=extent_routebits_nostrobe_nodepth_typesz;
    gate[w].str_depths=depth_routebits_nostrobe_nodepth_typesz;

    gate[w].inner=SR_geo_inner_str_function;
  }
}

// for routebits_nostrobe_nodepth_notypesz >>7 - new strobe prob func
void SR_geo_outer_C83(uint32_t w){   //
  if (gate[w].changed==0) {
    gate[w].matrix[15]=0<<8;//  simple strobe
    gate[w].matrix[17]=CV[w]; // bit mode - test one at a time
    //    gate[w].str_funcbit=routebits_nostrobe_nodepth_notypesz;   // we make sure function is NO STROBE!
    //    gate[w].str_extent=extent_routebits_nostrobe_nodepth_notypesz;
    //    gate[w].str_depths=depth_routebits_nostrobe_nodepth_notypesz;
    gate[w].matrix[9]=0; // invprobbits // gapped probs
    gate[w].matrix[10]=CVL[w];
    gate[w].inner=SR_geo_inner_str_probfunction;
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
    //    gate[w].str_funcbit=routebits_nostrobe_nodepth_typesz;   // we make sure function is NO STROBE!
    //    gate[w].str_extent=extent_routebits_nostrobe_nodepth_typesz;
    //    gate[w].str_depths=depth_routebits_nostrobe_nodepth_typesz;
    gate[w].inner=SR_geo_inner_str_function;
  }
}

void SR_geo_outer_C91(uint32_t w){   // routes with depth and gapped strobe speed 
  if (gate[w].changed==0) {
    gate[w].matrix[17]=CV[w];
    gate[w].matrix[4]=CVL[w];
    
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2

    //    gate[w].str_funcbit=routebits_nostrobe_depth_typesz;   // we make sure function is NO STROBE!
    //    gate[w].str_extent=extent_routebits_nostrobe_depth_typesz;
    //    gate[w].str_depths=depth_routebits_nostrobe_depth_typesz;
    
    gate[w].inner=SR_geo_inner_str_function;
  }
}

void SR_geo_outer_C92(uint32_t w){   // // routes with depth and gapped strobe speed // c92 length and depth 
  if (gate[w].changed==0) {
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2

    if (w==0) gate[w].matrix[8]=CV[w]; // adccv
    else gate[w].matrix[6]=CV[w]; // length

    //    gate[w].str_funcbit=routebits_nostrobe_depth_typesz;   // we make sure function is NO STROBE!
    //    gate[w].str_extent=extent_routebits_nostrobe_depth_typesz;
    //    gate[w].str_depths=depth_routebits_nostrobe_depth_typesz;
    
    gate[w].inner=SR_geo_inner_str_function;
  }
}

// // select strobe speed function with depth and gap function // not so XXXXX
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
    //    gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__ // or gapped
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

void SR_geo_outer_C102(uint32_t w){   // strobexor with gapped/fixed strobe
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // select spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    // other funcs or just gap it?
    //    gate[w].funcbit=routebits_nostrobe_depth_notypesz;   // we make sure function is NO STROBE!
    //    gate[w].extent=extent_routebits_nostrobe_depth_notypesz; 
    //    gate[w].depths=depth_routebits_nostrobe_depth_notypesz;
    //    gate[w].matrix[15]=0; // fixed strobe   or gap it
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
    //    gate[w].extent=extent_routebits_nostrobe_depth_notypesz; // checked!
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
    // first func is gapped
    gate[w].matrix[10]=CVL[w]; // depth
    if (w==0)  gate[w].matrix[8]=CV[w]; 
    else if (w==3) gate[w].matrix[5]=CV[w];
    else gate[w].matrix[12]=CV[w]; // select func2 which is fixed as with depth  but not in NN case
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
    if (w==0) gate[w].matrix[8]=(gate[dacfromopp[daccount][w]].dac); // cv1/cv2
    else gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); // cv1/cv2
    // first func is gapped
    gate[w].matrix[9]=CVL[w]; // selprob
    gate[w].matrix[5]=CV[w]; // cv1/cv2
    gate[w].inner=SR_geo_inner_str_probfunction; // and SR_geo_inner_str_probfunctionalt as diff 2nd array
  }
} 

void SR_geo_outer_C112(uint32_t w){  //alt probfunction
  if (gate[w].changed==0) {
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv1/cv2
    gate[w].matrix[17]=CV[w]; // bitfunc in strobe case
    gate[w].matrix[10]=CVL[w]; // depth of prob
    gate[w].inner=SR_geo_inner_str_probfunctionalt; // and SR_geo_inner_str_probfunctionalt as diff 2nd array
  }
} 

void SR_geo_outer_C113(uint32_t w){  // alt
  if (gate[w].changed==0) {
    //    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv1/cv2 gap it
    // first func is gapped
    gate[w].matrix[4]=CV[w]; 
    gate[w].matrix[10]=CVL[w]; // depth probf
    gate[w].inner=SR_geo_inner_str_probfunctionalt; // and SR_geo_inner_str_probfunctionalt as diff 2nd array
  }
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////
// start with matrixp strobe modes

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobespd, 16troutetype, 17 route->now strobe function index}, 18 is abstract CV, 19 is now glob, 20 is now abstract index, 21 is mix

uint32_t fixed=0, gap=0;

// cut to 16 here and we don't use fixed/gap // lose param
// and these all need to be 12 bit versions
uint32_t *fixedvars[4][16]={ //was 20 
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &ADCin, &Gshift__[0], &Gshift__[1], &Gshift__[2], &Gshift__[3], &clksr__[0], &Gshift__[8], &LFSR__[0], &LFSR__[1], &LFSR__[2]},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &ADCin, &Gshift__[0], &Gshift__[1], &Gshift__[2], &Gshift__[3], &clksr__[1], &Gshift__[8], &LFSR__[0], &LFSR__[1], &LFSR__[2]},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &ADCin, &Gshift__[0], &Gshift__[1], &Gshift__[2], &Gshift__[3], &clksr__[2], &Gshift__[8], &LFSR__[0], &LFSR__[1], &LFSR__[2]},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &ADCin, &Gshift__[0], &Gshift__[1], &Gshift__[2], &Gshift__[3], &clksr__[3], &Gshift__[8], &LFSR__[0], &LFSR__[1], &LFSR__[2]},
};

// fixed 21/2/2023


// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobespd, 16troutetype, 17 route->now strobe function index}, 18 is abstract CV, 19 is now glob, 20 is now abstract index, 21 is mix


uint32_t *map;
uint32_t maparrayCCS[16]={6, 13, 14, 16, 15, 1, 2, 17, 4, 5, 9, 10, 11, 12, 15, 1}; // strobes
uint32_t maparrayCCSA[16]={6, 15, 1, 2, 17, 4, 5, 9, 10, 11, 12, 15, 7, 8, 20, 21};// 16

uint32_t maparrayCC[16]= {6, 13, 14, 16, 0, 1, 2, 3, 4, 5, 9, 10, 11, 12, 0, 1}; 
uint32_t maparrayCCA[16]= {6, 16, 0, 1, 2, 3, 4, 5, 9, 10, 11, 12, 7, 8, 20, 21};// 16

// and for LL as same as CC

void SR_geomantic_matrixcopyz(uint32_t w){ 
  uint32_t x;
  for (x=0;x<22;x++){
    gate[w].matrixX[x]=*(gate[w].matrixp[x]); 
  }
}

void SR_geomantic_matrixcopyoffsetz(uint32_t w){ 
  uint32_t x;
  for (x=0;x<22;x++){
      gate[w].matrixX[x]=(*(gate[w].matrixp[x]))+gate[w].offset[x]; // how we set this offset
      if (gate[w].matrixX[x]>4095) gate[w].matrixX[x]=4095; // clip
  }
}

static inline void setfixedz(uint32_t wh, uint32_t which, uint32_t val){ // fixed value like 1024
  gate[wh].matrix[which]=val; 
  gate[wh].matrixp[which]=&gate[wh].matrix[which]; 
}

static inline void setfixedvarz(uint32_t wh, uint32_t which, uint32_t var){ // sets fixed value at var var
  gate[wh].matrix[which]=*fixedvars[wh][var];
  gate[wh].matrixp[which]=&gate[wh].matrix[which]; 
}

static inline void setvarz(uint32_t wh, uint32_t which, uint32_t var){ // plain set across all
  gate[wh].matrixp[which]=fixedvars[wh][var]; 
}

static inline void setgapz(uint32_t wh, uint32_t layer, uint32_t which){ 
  if (which!=gate[wh].oldgap[layer]){
    gate[wh].matrix[which]=gate[wh].matrixX[which]; // value
    gate[wh].matrixp[which]=&gate[wh].matrix[which]; // pointer
  }
  gate[wh].oldgap[layer]=which;
}

static inline void setvargapzbleed(uint32_t wh, uint32_t layer, uint32_t which, uint32_t var){ // bleeds values across but obscures any attachments
  if (which!=gate[wh].oldgap[layer]){
    gate[wh].matrixp[gate[wh].oldgap[layer]]=gate[wh].matrixpG[gate[wh].oldgap[layer]];
    gate[wh].matrixpG[which]=gate[wh].matrixp[which]; // previous  
    gate[wh].matrixp[which]=fixedvars[wh][var]; // new one
    gate[wh].matrix[which]=*gate[wh].matrixp[which];
  }
  gate[wh].oldgap[layer]=which;
}

//////////////////////////////////////////

// resett=1 is bleed... 2 is attach - seems to work
static inline void setvargapz(uint32_t wh, uint32_t layer, uint32_t which, uint32_t var, uint32_t resset){ // sets gap with one of fixedvars - tested in test2.c
  //  if (resset==2) gate[wh].oldgap[layer]=22; //never hits 22
  
  if (which!= gate[wh].oldgap[layer]){// only if we want a new one not to reset the same one...
    gate[wh].matrixp[gate[wh].oldgap[layer]]=gate[wh].matrixpG[gate[wh].oldgap[layer]];
    gate[wh].matrixpG[which]=gate[wh].matrixp[which]; // previous  
    gate[wh].matrixp[which]=fixedvars[wh][var]; // new one
      if (resset==1){ //set back
	gate[wh].matrix[which]=*gate[wh].matrixp[which]; // was fixedvalues which matrixp points to
      }
  }
      else if (gate[wh].matrixp[gate[wh].oldgap[layer]]!=fixedvars[wh][var]){
      gate[wh].matrixp[which]=fixedvars[wh][var]; // new one
      if (resset==1){ //set back
	gate[wh].matrix[which]=*gate[wh].matrixp[which];
      }
      }
  gate[wh].oldgap[layer]=which;
}


// would be nice to set gapz etc - catalogue what we had from discard and here
/*

/////////

setgapz.
setvarz- just attach... CV and CVL
setfixedvars - set value from eg. CVL etc...

120: strobe: set to CV, CVL, gshift, dacfrom (as we have)
130: strobe: CV to CVL XY, set gap, bleed of XY, empty one
140: nostr: set triggered cnt to CVL, to dacfrom, dacfrom chosen is set to CV, on trigger and dacfrom set to CV
150: nostr, CV to CVL XY, SR bits set, gaps from SR bits, then 153 final reset

 */

// CV attach using CVL with  model here ???

void SR_geo_outer_C120(uint32_t w){ // CV/CVL  
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCSA;
    else map=maparrayCCS;
    setvargapzbleed(w, 3, map[(CV[w]>>8)], CVL[w]>>8);  // or vargapz
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_str_probfunctionX; 
  }
}

void SR_geo_outer_C121(uint32_t w){ // all layers
  uint32_t tmp;
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCSA;
    else map=maparrayCCS;
    tmp=CV[w]>>8;// 4 bits 16 layers
    setvargapz(w, tmp, map[tmp], CVL[w]>>8, 0); //CVL is var...
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_str_probfunctionX; 
  }
}

void SR_geo_outer_C122(uint32_t w){ //SR_geomantic_matrixcopyoffsetz
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCSA;
    else map=maparrayCCS;
    gate[w].offset[map[CV[w]>>8]]=CVL[w];
    SR_geomantic_matrixcopyoffsetz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_str_probfunctionX; 
  }
}

//empty one
void SR_geo_outer_C123x(uint32_t w){   
  if (gate[w].changed==0) {
    SR_geomantic_matrixcopyoffsetz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_str_probfunctionX; 
  }
}

// becomes
void SR_geo_outer_C123(uint32_t w){ // CV/CVL  
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCSA;
    else map=maparrayCCS;
    setvargapz(w, 3, map[(CV[w]>>8)], CVL[w]>>8,0);  // or vargapz
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_str_probfunctionX; 
  }
}


//setfixedvarz cv cvl
void SR_geo_outer_C130(uint32_t w){   
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCSA;
    else map=maparrayCCS;
    setfixedvarz(w, map[(CV[w]>>8)], CVL[w]>>8); 		   
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_str_probfunctionXX; 
  }
}

void SR_geo_outer_C131(uint32_t w){   
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCSA;
    else map=maparrayCCS;
    setvarz(w, map[(CV[w]>>8)], CVL[w]>>8); 		   
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_str_probfunctionXX; 
  }
}

// 1010101 from SR sets matrixp to CV/CVL chosen fixedvar - probably better as strobe
void SR_geo_outer_C132(uint32_t w){ 
  if (gate[w].changed==0) {
    uint32_t x;
    uint32_t tmp=(gate[dacfrom[daccount][w]].shift_)&0b1111111111111111;
    if (w==0) map=maparrayCCSA;
    else map=maparrayCCS;

    for (x=0;x<16;x++){
      setfixedvarz(w,map[x],CV[w]>>8); // can also be others - sets value at x in CV[w] chosen param       
    }
    SR_geomantic_matrixcopyz(w); // or offset?
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_str_probfunctionXX;
  }
}

// gapz
void SR_geo_outer_C133(uint32_t w){  // // can also be gaps and 2 processes against each other
  if (gate[w].changed==0) {
    uint32_t x;
    uint32_t tmp=(gate[dacfrom[daccount][w]].shift_)&0b1111111111111111;
    if (w==0) map=maparrayCCSA;
    else map=maparrayCCS;

    for (x=0;x<16;x++){
      setgapz(w, 0, map[x]);
    }
      // and then do CV, CVL on top - could also be setvarz
      setfixedvarz(w, maparrayCC[(CV[w]>>8)], CVL[w]>>8); 		   
      SR_geomantic_matrixcopyz(w); // or offset?
      gate[w].routetype=gate[w].matrixX[16]>>9;
      gate[w].inner=SR_geo_inner_str_probfunctionXX;
  }
}

/////////////////////////////
// CV speeds

// CV attach using CVL
void SR_geo_outer_C140(uint32_t w){   // if trigger then bleed 
  if (gate[w].changed==0) {
    // what event we can trigger on and what to release 0,1 or 2
    if (w==0) map=maparrayCCA;
    else map=maparrayCC;

    setvargapz(w, 0, map[(CVL[w]>>8)], 4, gate[w].trigger); // CV
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_probdepthdepthS;//SR_geo_inner_gappedfunction;// S sets strobe
  }
}

void SR_geo_outer_C141(uint32_t w){   // if trigger then bleed // CVL attach using CV
  if (gate[w].changed==0) {
    // what event we can trigger on and what to release 0,1 or 2
    if (w==0) map=maparrayCCA;
    else map=maparrayCC;

    setvargapz(w, 1, map[(CV[w]>>8)], 5, gate[w].trigger); // CVL
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_probdepthdepthS;//SR_geo_inner_gappedfunction;// S sets strobe
  }
}

// test further layerings // GSHIFT attach
void SR_geo_outer_C142(uint32_t w){   // if trigger then bleed 
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCA;
    else map=maparrayCC;

    if (map[(CVL[w]>>8)]==1){ // speedcv
    setvargapz(w, 2, map[(CV[w]>>8)], 7+speedfrom[spdcount][w], gate[w].trigger);  // speedfrom
    }
    else {
    setvargapz(w, 2, map[(CV[w]>>8)], 7+dacfrom[daccount][w], gate[w].trigger);  // gshift
    }
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_probdepthdepthS;
  }
}

//cv/cvl version - seems work fine
void SR_geo_outer_C143(uint32_t w){   // if trigger then bleed 
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCA;
    else map=maparrayCC;
    setvargapz(w, 3, map[(CV[w]>>8)], CVL[w]>>8, gate[w].trigger); 
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_probdepthdepthS;
  }
}

//layers as sep functions we have but also can be in one - see notes // as bleed/no bleed/triggers bleed
void SR_geo_outer_C150(uint32_t w){   // no trigger
  uint32_t tmp;
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCA;
    else map=maparrayCC;
    tmp=CV[w]>>8;// 4 bits 16 layers
    setvargapz(w, tmp, map[tmp], CVL[w]>>8, 0); //CVL is var...
    SR_geomantic_matrixcopyz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_probdepthdepthSN;
  }
}

//SR_geomantic_matrixcopyoffsetz
void SR_geo_outer_C151(uint32_t w){   // trial offset
  if (gate[w].changed==0) {
    if (w==0) map=maparrayCCA;
    else map=maparrayCC;
    gate[w].offset[map[CV[w]>>8]]=CVL[w];
    SR_geomantic_matrixcopyoffsetz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_probdepthdepthSN;//SR_geo_inner_gappedfunction;// S sets strobe
  }
}

// blank here to make use of CV/CVL unattended? 133
void SR_geo_outer_C152(uint32_t w){
  if (gate[w].changed==0) {
    SR_geomantic_matrixcopyoffsetz(w);
    gate[w].routetype=gate[w].matrixX[16]>>9;
    gate[w].inner=SR_geo_inner_probdepthdepthSN;//SR_geo_inner_gappedfunction;// S sets strobe
  }
}

////////////////////////////////////////////////////////////////////////

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

// prob of last remaining: SR_geo_inner_functionproblast(uint32_t w)
void SR_geo_outer_Cplast(uint32_t w){ // problast - probf_anystrobe_depth // routebits_nodepth_typesz default 0
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv 
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].matrix[9]=5<<6; // spdfracP_
  gate[w].matrix[10]=CVL[w]; // prob depth
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // do any use IN? yes spdfrac versions - should have basic prob vs in tho...
  gate[w].inner=SR_geo_inner_functionproblast;//
  }
}

