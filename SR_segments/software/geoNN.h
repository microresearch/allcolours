/// INNER

// try with interpoll
void SR_geo_inner_noprobNN(uint32_t w){  // no probability, no adc - this can be generic
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);
    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_noprobfixeddepthNN(uint32_t w){  // no probability, no adc - this can be generic
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);
    bitn^=(*routebitsfixeddepth[gate[w].matrix[3]>>7])(binroute[count][w]|binary[w]<<8, gate[w].matrix[5], w); // there are 32 >>7
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_noprobnodNN(uint32_t w){  // no probability, no adc - this can be generic
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);
    bitn^=(*routebitsnod[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); // >>7 as 32
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_fixedNN(uint32_t w){  // fixed route only - no probability, no adc - this can be generic
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    //    bitn=(*routebits[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    bitn^=binroutfixed(0,0,w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_fixedprobNN(uint32_t w){  // fixed route only - prob if we have CV free from speed CV[w] speednoin==0
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    //    bitn^=(*routebits[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    if (speednoin[w]==1) bitn^=binroutfixed(0,0,w);
    else { // use CV for prob of bitn vs cycle...
      if (CV[0]<LFSR__[w])     bitn^= (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

/*
    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

      bitn^=(*routebits[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // so we can have some fixed - 4 is cycle
  }
  else {
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
 */

void SR_geo_inner_noprob_routeprobNN(uint32_t w){  // no probability, no adc - this can be generic - for routeprobarray
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsnostrobedepthprob[gate[w].matrix[3]>>8])(gate[w].matrix[4], gate[w].matrix[5], w); // 16 only
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// for binr and types
void SR_geo_inner_binrNN(uint32_t w){  // no probability, no adc - this can be generic
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
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsfortypes[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); // >>7 as 32
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


//*can we also have prob of a dac out aside from SR operations? - no interpoll*
void SR_geo_inner_probofdacoutNN(uint32_t w){  // no probability, no adc - this can be generic // no interpoll
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); //>>6 as 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)) gate[w].dac = delay_buffer[w][1];
    }
}

// NON!
/*
void SR_geo_inner_noprob_strobe(uint32_t w){   // no use of CV really as we don;t want as type
  HEADNADA;

    if ((*speedfromstrobe[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1];  
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}
*/

//- example of how we deal with strobe free up!? as prob 
void SR_geo_inner_prob_strobeNN(uint32_t w){  
  HEADNADA;

    if ((*speedfromstrobe[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1];  
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    if (usedstrobe[gate[w].matrix[15]>>7]) {
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

      bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);//?
    }
    else { // do prob thing as we have a CV
      if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

	bitn^=(*routebitsnostrobe[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // now with depth....
      }
      else {
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

	bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
      }
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_prob3_strobeNN(uint32_t w){ // as above but with strobe for speed to free up CV for prob
  HEADNADA;

  if ((*speedfromstrobenodepth[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1]; // dac moved inside strobe
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

      bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[dacfrom[daccount][w]].dac, gate[w].matrix[5], w); // only makes sense if matrix[4] was CV - to trial with probbits
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_prob1NN(uint32_t w){  // TESTY - using probfsins - ported in from speeds
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

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

      bitn^=(*routebits[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // so we can have some fixed - 4 is cycle
  }
  else {
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probcycleNN(uint32_t w){  // TESTY - using probfsins - ported in from speeds -> basic gapped cv binroute against justcycle!
  // what cv we need: probfs: 9type,10comp... 3,4,5 is gapped...
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

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

      bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // no fixed ones, all depth - gapped binroute [3]
  }
  else {
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsnod[1])(0,0, w); // justcycle
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_prob2NN(uint32_t w){  // TESTY - ported in using strobes/no depth
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

    if ((*probfstrobes[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

      bitn^=(*routebitsd[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// *thinking of meta-level of prob to use x or y param (eg. use DANN or CV or) -> further matrix ops*
// but to test prob3 we need cv for prob and cv for bit function ie. fixed route does nothing - we need 2 cvs...
// so we either have strobe speeds or strobe probs... test latter now
void SR_geo_inner_prob3NN(uint32_t w){
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[15]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfstrobes[gate[w].matrix[9]>>8])(gate[w].matrix[10], gate[w].matrix[11], w)){ //there are 16
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

      bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    tmp=daccount+1;
    if (tmp>15) tmp=0;
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[dacfrom[tmp][w]].dac, gate[w].matrix[5], w); // only makes sense if matrix[4] was CV - to trial with probbits
  } // we suggest using different dacfrom index... as they cannot be the same.
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// ported in from geomantic.h -> pair and test with outers

// from toport.h
void SR_geo_innerNOSNN(uint32_t w){   // GSHIFTNOS_; no shift // shift on tirgger or full speed
  HEADNADA;
  gate[w].dac = delay_buffer[w][1]; //TODO: or trigger
  //
  gate[w].shift_=gate[w].shift_<<1; 
  
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    GSHIFTNOS_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

//////////////////// trigger versions from toport.h but trigger/<<1 should not be a strobe mode

void SR_geo_innersplit1NN(uint32_t w){   // STROBE - not as strobe mode then where to place? instead of NOS above? UNUSED so far
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (gate[w].trigger) gate[w].shift_=gate[w].shift_<<1; 
  
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    GSHIFTNOS_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inner_split2NN(uint8_t w){  //strobe no mode UNUSED so far
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  if (gate[w].trigger){
    GSHIFT_;
  }
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
     SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inner_split3NN(uint8_t w){  //strobe - could be strobe mode? uses CV
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
  }
  if (gate[w].trigger){
     SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

///////////////////

void SR_geo_innerxorNN(uint32_t w){  // xor with fixed route - but we don't track cv???
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ( (*speedfromcvforxor[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w) ^ speedfromforxor[0](0,0,w) ){ // speedfunc xor with fromforxor->binroutfixed...
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rung0NN(uint32_t w){  // no probability, no adc - this can be generic // no interp
  HEADNADA;
  if ((*speedfromnosdac[gate[w].matrix[0]>>9])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    //    bitn^=(*routebitsfortypes[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*bitfromalldepth[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); //64 >>6
    bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done

    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rung1NN(uint32_t w){  // no prob // no adc -- run binrout fixed at full speed // no interp
  HEADNADA;
 
  bitn=binroutfixed(0,0,w);

  if ((*speedfromnosdac[gate[w].matrix[0]>>9])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].dac = delay_buffer[w][1];

    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);

    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done

    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

////////////////////////////////////////////////////////////////////////////////////
/// OUTERS

/*

dactype/dacpar
-speed: basic, select, speedfroms, strobe
-bits:
  routes: no depth.fixed -> prob
          strobes/no strobes
          prob - use [5]/in and/or always have in reserve as LFSR 
-prob: 

TODO/layout: 
00-fixedroute/fixedtype - set DANNtype or have cv prob for cycle/other noncv
01-depthroute/fixedtype
02-fixedroute/flextype
03-depthroute/flextype -> 2x CV? or type is global

gap for route, gap for type

->other types of binroute function// next set

dactype in 00
where we set dacparam

0-3
4-7
8-11
12-15

16-19
20-23
24-27
28-31

32-35
36-39
40-43
44-47

48-51
52-55
56-59
60-63

areas with associated gaps:

-dactypes/dacparams

-binroutes
-probs
-etc/esoteric bitmodes

speedL
-speedfroms1, double speeds -> //above bitmodes 
-splitspeeds2
-xor/orstrobes3 as part of strobes modes
-strobes4

-matrixp which includes all strobe etc...


*/

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobeindex
// 1/ puer... or which we start from?


/*
00-fixedroute/fixedtype - set DANNtype or have cv prob for cycle/other noncv
01-depthroute/fixedtype
02-fixedroute/flextype
03-depthroute/flextype -> 2x CV? so type is just l
*/

/* OR:
simpler begin arrays: 1st 16 to re-check...

0-DANNtype selected 
1-fixed route/change length
2-fixed route/prob of route or cycle
3-fixed route/prob of route XOR cycle

 */

void SR_geo_outer_NN00(uint32_t w){  // set dactype, spdfrac, fixed route // RESETR - no need for changed
  RESETR; 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[13]=CVL[w]; //
  gate[w].inner=SR_geo_inner_fixedNN;
}

void SR_geo_outer_NN01(uint32_t w){  // spdfrac, depth as route
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // depth 
  gate[w].matrix[4]=CVL[w]; // 
  gate[w].inner=SR_geo_inner_noprobNN;
  }
}

void SR_geo_outer_NN02(uint32_t w){  // spdfrac, fixed route, flextype
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=46<<6; // fixed/flextype = binroutesel2=46
  gate[w].matrix[4]=CVL[w]; //
  gate[w].inner=SR_geo_inner_noprobNN;
  }
  }

void SR_geo_outer_NN03(uint32_t w){  // spdfrac, depthroute, fixedtype->global
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=45<<6; // fixed/flextype = binroutesel1=45
  gate[w].matrix[4]=CVL[w]; //
  gate[w].inner=SR_geo_inner_noprobNN;
}
}

// dacparam as above 
void SR_geo_outer_NN10(uint32_t w){  // set dacparam, spdfrac, fixed route with global type
  if (gate[w].changed==0) { 
    gate[w].matrix[0]=0<<7; // spdfrac
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=9<<7; // sel0 
    gate[w].matrix[14]=CVL[w]; // into DANN_ otherpar which is 10 bits
    gate[w].inner=SR_geo_inner_noprobnodNN;
  }
}

// set dacpar as dacfrom length
void SR_geo_outer_NN11(uint32_t w){  // set dacparam, spdfrac, fixed route with global type
  if (gate[w].changed==0) { 
    gate[w].matrix[0]=0<<7; // spdfrac
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=9<<7; // sel0 
    gate[w].matrix[6]=CVL[w]; //length
    gate[w].matrix[14]=gate[dacfrom[daccount][w]].dac; // into DANN_ otherpar which is 10 bits
    gate[w].inner=SR_geo_inner_noprobnodNN;
  }
}

// keep length CV and gap depth as route
void SR_geo_outer_NN12(uint32_t w){  // spdfrac, depth as route
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // route as depth 
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_noprobNN;
}
}
  
// we pass fixed depth/as/route and select function -> length as dacfrom
void SR_geo_outer_NN13(uint32_t w){  
  if (gate[w].changed==0) {
    gate[w].matrix[0]=0<<7; // spdfrac
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=CVL[w]; 
    gate[w].matrix[6]=gate[dacfrom[daccount][w]].dac; 
    gate[w].inner=SR_geo_inner_noprobfixeddepthNN;
  }
}

//- start vary routes/new sel with IN as sel->SR_geo_inner_binr and 0<<8 there
void SR_geo_outer_NN20(uint32_t w){  // 
  if (gate[w].changed==0) { 
    gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<7; // select func
  //  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=CVL[w]; // IN selects type
  gate[w].inner=SR_geo_inner_binrNN; // 16 of these >>8 <<8
}
}

void SR_geo_outer_NN21(uint32_t w){  // as above with depth
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<7; // select func
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].inner=SR_geo_inner_binrNN; // 16 of these >>8 <<8
}
}
  
void SR_geo_outer_NN22(uint32_t w){  // as above with sel
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // select func
  gate[w].inner=SR_geo_inner_binrNN; // 16 of these >>8 <<8
}
}
  
void SR_geo_outer_NN23(uint32_t w){  // as above with length or we can also have dacfrom for depth
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; //depth
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_binrNN; // 16 of these >>8 <<8
}
}
  
// last set is full routes ///routebitsd[60] - gaps for speed function
void SR_geo_outer_NN30(uint32_t w){  // 
  if (gate[w].changed==0) { 
    //  gate[w].matrix[0]=0<<7; // spdfrac GAP!!!
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // select func
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].inner=SR_geo_inner_noprobNN; // 
}
}
  
void SR_geo_outer_NN31(uint32_t w){  // 
  if (gate[w].changed==0) { 
    //  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // select func
  gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; //depth
  gate[w].inner=SR_geo_inner_noprobNN; // 
}
}

void SR_geo_outer_NN32(uint32_t w){  // 
  if (gate[w].changed==0) {
    //    gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].inner=SR_geo_inner_noprobNN; // 
}
}

void SR_geo_outer_NN33(uint32_t w){  // 
  if (gate[w].changed==0) {
    //    gate[w].matrix[0]=0<<7; // spdfrac
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_noprobNN; // 
}
}

// speedfroms: set speedfrom mode, speed as cv, dac/swop - for fixed route, depth as route
//16
void SR_geo_outer_NN40(uint32_t w){  
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // set spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    //    gate[w].matrix[3]=0<<6; // fixedroute
    gate[w].inner=SR_geo_inner_fixedNN;
  }
}

 // DONE/TO_TEST: rework inner fixed for prob if we have CV from speed free
void SR_geo_outer_NN41(uint32_t w){  // swopped order of dac and CV - fixed route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // set spdfrom mode
    gate[w].matrix[1]=gate[speedfrom[spdcount][w]].dac; // SWOPPED order
    gate[w].matrix[2]=CV[w];// speed // if not the is prob
    gate[w].inner=SR_geo_inner_fixedprobNN;
  }
}

void SR_geo_outer_NN42(uint32_t w){  // gapped depth/route //+swop1
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // set spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[3]=0<<6; // depth as route
    gate[w].inner=SR_geo_inner_noprobNN;
  }
}

void SR_geo_outer_NN43(uint32_t w){  // gapped depth/route and bitmode //+swop2
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // set spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    //    gate[w].matrix[3]=0<<6; // depth as route
    gate[w].inner=SR_geo_inner_noprobNN;
  }
}
//20
// speedfrom xor
void SR_geo_outer_NN50(uint32_t w){  // which gaps/functions - but we have CVL used
  // what is appropriate speed function????
  gate[w].matrix[0]=CVL[w];
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but do we need 2nd cv???
  gate[w].inner=SR_geo_innerxorNN;
}  

//split speed= see toport.h
void SR_geo_outer_NN51(uint32_t w){  // which gaps/functions - but we have CVL used
  // what is appropriate speed function????
  gate[w].matrix[0]=CVL[w];
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but do we need 2nd cv???
  gate[w].inner=SR_geo_innerNOSNN;
}  

// and 2x runglers - speedgaps
void SR_geo_outer_NN52(uint32_t w){  // 
  if (gate[w].changed==0) { 
    //    gate[w].matrix[0]=0; // spcdfrac -> or set as DANNspeed one of which we have 6//
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[3]=0<<7; //1 fixed
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    gate[w].matrix[12]=20<<7; // OSNN for rung
    //    gate[w].dacpar=CVL[w]; // into DANN_ otherpar which is 10 bits
    gate[w].inner=SR_geo_inner_rung0NN;
  }
}

void SR_geo_outer_NN53(uint32_t w){  // 
  if (gate[w].changed==0) { 
    //    gate[w].matrix[0]=0; // spcdfrac 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[3]=20<<7; // OSNN for rung
    //    gate[w].dacpar=CVL[w]; // into DANN_ otherpar which is 10 bits
    gate[w].inner=SR_geo_inner_rung1NN; // is fixed route vs. other
  }
}

// probs1: 60,61,62,63

void SR_geo_outer_NN60(uint32_t w){  
  if (gate[w].changed==0) { 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
    //    gate[w].matrix[3]=1<<7;  // gap
    //    gate[w].matrix[4]=CVL[w]; // gap
    gate[w].matrix[9]=CVL[w]; // prob mode
    gate[w].matrix[10]=CVL[w]; //unused maybe
    gate[w].matrix[11]=CVL[w];// unused maybe
    gate[w].matrix[12]=5<<7; // altfuncindex - 5 is justcycle
     
    gate[w].inner=SR_geo_inner_prob3NN; // trial different prob functions - these use strobe
  }
}

void SR_geo_outer_NN61(uint32_t w){  // gaps
  if (gate[w].changed==0) { 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
    gate[w].matrix[9]=CVL[w]; // zprobbits
    gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[11]=CVL[w];// unused?
     
    gate[w].inner=SR_geo_inner_probofdacoutNN; // trial different prob functions
  }
}

void SR_geo_outer_NN62(uint32_t w){  
  if (gate[w].changed==0) { 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
    //    gate[w].matrix[9]=CVL[w]; // zprobbits // gappped
    gate[w].matrix[10]=CVL[w];//(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[11]=CVL[w];// unused?
     
    gate[w].inner=SR_geo_inner_probofdacoutNN; // trial different prob functions
  }
}

//- *probability in regular bitmodes is now vs. in and we pass LFSR to matrix[5] <(LFSR_[wh]&4095)// remember - but then we need to handle these - different sets... make example*
void SR_geo_outer_NN63(uint32_t w){  // eg. test routeprobs with IN [5] as LFSR - depth vs in
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  gate[w].matrix[4]=CVL[w]; //
  gate[w].matrix[5]=LFSR_[w]&4095; // vs LFSR - IN
  gate[w].inner=SR_geo_inner_noprob_routeprobNN; 
}
}

void SR_geo_outer_NN70(uint32_t w){  // can also have CV vs dacfrom
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  gate[w].matrix[3]=CVL[w];
  gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac);; //
  gate[w].matrix[5]=LFSR_[w]&4095; // vs LFSR - IN
  gate[w].inner=SR_geo_inner_noprob_routeprobNN; 
}
}

// classic prob we need selprobfunc, cvs for prob, cvs for bits, cvs for selfunc, selalt -> too many even with strobe
void SR_geo_outer_NN71(uint32_t w){  
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;

  gate[w].matrix[9]=CVL[w]; // select probfs - but we need 10 and 11 and 12?!
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac);; //
  //10 is prob vs lfsr/cv -> can be dacfrom
  //12 is alt - how we define this one? another gap - set as default!
  //3 is func - we have as gap
  // 4 and 5 cvs for bits - can be gaps
  gate[w].inner=SR_geo_inner_prob1NN; // recheck 
}
}

void SR_geo_outer_NN72(uint32_t w){  
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  //  gate[w].matrix[9]=CVL[w]; // select probfs - but we need 10 and 11 and 12?!
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac);; //
  //10 is prob vs lfsr/cv -> can be dacfrom
  gate[w].matrix[12]=CVL[w];
  //12 is alt - how we define this one? another gap - set as default!
  //3 is func - we have as gap
  // 4 and 5 cvs for bits - can be gaps
  gate[w].inner=SR_geo_inner_prob1NN; // recheck
}
}

void SR_geo_outer_NN73(uint32_t w){  
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  //  gate[w].matrix[9]=CVL[w]; // select probfs - but we need 10 and 11 and 12?!
  //  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac);; //
  //10 is prob vs lfsr/cv -> can be dacfrom
  gate[w].matrix[10]=CVL[w];
  //12 is alt - how we define this one? another gap - set as default!
  //3 is func - we have as gap
  // 4 and 5 cvs for bits - can be gaps
  gate[w].inner=SR_geo_inner_prob1NN; // recheck
}
}
// classical prob: SR_geo_inner_prob1 - how we get enough CV? 72setfunc, 73gapthere


/*
TODO:

where is strobe xor? SR_geo_innerxorS, SR_geo_innerorS (or) // splitspeed? split3?

1 strobes2 prob1 
2 
3 prob2 - fixed probs
4 2 splitspeed versions????
*/


// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobeindex
// first set is basic strobes

/*
- re-set bitfunc and CV - 

0 [3]=CVL[w] - all basic strobe 15=0
1 [4]=CVL[w]
2 [9]=CVL[w]
3 [12] altfuncindex
 */

/*
0fixed route. fixed strobe. always prob - SR_geo_inner_prob3_strobe
1unfixed route. fixed strobe. always prob - SR_geo_inner_prob3_strobe
2unfixed route. unfixed strobe. variable prob - SR_geo_inner_prob_strobe
3splitspeeds and others // ???
*/

// or these could all be fixed route ???

void SR_geo_outer_NN80(uint32_t w){   // set bitcv
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=0<<8; // strobed function
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=1<<6; // set bitfunc fixed
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    gate[w].matrix[9]=1<<7; // probbits - do as default
    gate[w].matrix[10]=CV[w]; // CV for prob
    //    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac;// unused here
    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob3_strobeNN; // optional prob if we have a free CV!
  }
}

void SR_geo_outer_NN81(uint32_t w){   // set length
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=0<<8; // strobed function
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    gate[w].matrix[6]=CVL[w]; 
    // prob stuff
    gate[w].matrix[9]=1<<7; // probbits - do as default
    gate[w].matrix[10]=CV[w]; // CV for prob
    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob3_strobeNN; // optional prob if we have a free CV!
  }
}

void SR_geo_outer_NN82(uint32_t w){   // set probfunc
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=0<<8; // strobed function
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[9]=CVL[w]; 
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    //    gate[w].matrix[9]=1<<7; // probbits - do as default
    gate[w].matrix[10]=CV[w]; // CV for prob
    gate[w].matrix[11]=gate[dacfrom[daccount][w]].dac;
    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob3_strobeNN; // optional prob if we have a free CV!
  }
}

void SR_geo_outer_NN83(uint32_t w){   // set altfunc
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=0<<8; // strobed function
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[12]=CVL[w]; 
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    //    gate[w].matrix[9]=1<<7; // probbits - do as default
    gate[w].matrix[10]=CV[w]; // CV for prob
    gate[w].matrix[11]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob3_strobeNN; // optional prob if we have a free CV!
  }
}

///////////////////////////


void SR_geo_outer_NNtestprobstrobe(uint32_t w){  // set dacparam, spdfrac, fixed route
  if (gate[w].changed==0) { 

    gate[w].matrix[15]=0<<7; // testing 
    gate[w].matrix[3]=1<<7; 
    gate[w].matrix[4]=CVL[w]; // cv for binr

    gate[w].matrix[9]=1<<7; // probbits 
    gate[w].matrix[10]=CV[w]; // CV for prob
    gate[w].matrix[11]=CVL[w];// for 9/comp
    gate[w].matrix[12]=5<<7; // altfuncindex - 5 is justcycle
     
    gate[w].inner=SR_geo_inner_prob3_strobeNN; // trial different prob functions
  }
}
