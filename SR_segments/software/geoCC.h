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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_functionprob1(uint32_t w){  // new abstraction needs gate[w].funcbit->function array, and extent as >>howmany
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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    if ((gate[w].matrix[3]>>gate[w].extent)<24) {// we use depth
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    else { // prob of cycle or in new version xor cycle...
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

void SR_geo_inner_functionprob2(uint32_t w){  // new abstraction needs gate[w].funcbit->function array, and extent as >>howmany
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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    if ((gate[w].matrix[3]>>gate[w].extent)<24) {// we use depth
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    }
    else { // prob of cycle or in new version xor cycle...
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?

      if (!(*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn ^= (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
    }
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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?

    if (!(*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?

    if (!(*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn^=(!(gate[w].Gshift_[w]>>SRlength[w]) & 0x01);	   // cycle bit INV
    }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_probofdacoutC(uint32_t w){  // no probability, no adc - this can be generic // no interpoll
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    if ((*probfdepthnoin[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)) gate[w].dac = delay_buffer[w][1]; 
    }
}

void SR_geo_inner_rungC(uint32_t w){  // no probability, no adc - this can be generic // no interp
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>9])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    bitn=(*abstractbitsz[gate[w].matrix[12]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probusesstrobe(uint32_t w){  // draft for probs with strobe - and adapt for others
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

    if ((*probfstrobes_nodepth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){ // strobes_ no depth
      //      bitn=(*routebits[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); 
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

    if ((*probfsin_nodepth[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){ // no depth
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

    if ((*probfdepthnoin[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){ // no depth
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

// change type/globalroute
void SR_geo_outer_C01dep(uint32_t w){ // globalroute/set routetype // alt: could be another prob and save setting for later
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  SETROUTETYPECV;
  gate[w].inner=SR_geo_inner_globalC; // routetype/but globalroute
  }
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

void SR_geo_outer_C10dep(uint32_t w){ // change route. gapped type // alt: just local route change but then... other function
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // zbinrout - with theroute 
  SETROUTECV;
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C11dep(uint32_t w){ // change type. theroute // alt: type from earlier
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // zbinrout - with theroute 
  //  gate[w].matrix[4]=CVL[w]; //
  SETROUTETYPECV;
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C10(uint32_t w){ // change type. route above depth
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=63<<6; // zbinrout_strip=63
  SETROUTETYPECV; // but no type on zero route
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

// 2/1/23 - for 2.0 we can have different function arrays and gap array itself... but then what of depth????

void SR_geo_outer_C20dep(uint32_t w){ // change function. 
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_depth_typesz;//[32] >>7 now
  gate[w].extent=7; // 5 bits [32]
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C21dep(uint32_t w){ // gapped function. set depth/route
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=CVL[w]; // depth
  else SETROUTECV;
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C22dep(uint32_t w){ // prob/depth of gapped function vs. cycle
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 - or we gap this?
  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // CV2 for those which use IN     
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probcycleC; 
}
}

void SR_geo_outer_C23dep(uint32_t w){ // gapped function vs. [gapped XOR cycle]
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 - or we gap this?
  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // CV2 for those which use IN     
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probcyclexorC; 
}
}

// start again: depth, nodepth and full/mix

void SR_geo_outer_C20(uint32_t w){ // change function. nodepth
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C21(uint32_t w){ // change function. nodepth // gapped nodepth with prob of cycle
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_probcycleC; 
  }
}

void SR_geo_outer_C22(uint32_t w){ // change function. nodepth // gapped nodepth with prob of cycleXOR
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_probcyclexorC; 
  }
}

void SR_geo_outer_C23(uint32_t w){ // change function. nodepth // gapped nodepth with prob of cycleXOR
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_probcyclexorinvC; 
  }
}

///

//3.0/////// WAS:use of dacs: depth/route as dacfrom, dacpar as dacfrom, length as dacfrom, function as dacfrom? ///depth is dac - what we do with CV? use as length
//

void SR_geo_outer_C30dep(uint32_t w){ // dac-length. depth-cv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=CVL[w]; // depth
  else SETROUTECV;  
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2
  gate[w].matrix[6]=(gate[dacfrom[daccount][w]].dac); // length
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C31dep(uint32_t w){ // dac-dacpar. depth-cv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=CVL[w]; // depth
  else SETROUTECV;  
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2
  gate[w].matrix[14]=(gate[dacfrom[daccount][w]].dac); // dacpar
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C32dep(uint32_t w){ // dac-depth. dacpar-cv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); // depth
  else SETROUTEDAC;  
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2
  gate[w].matrix[14]=CVL[w]; // dacpar
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C33dep(uint32_t w){ // dac-depth. length-cv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); // depth
  else SETROUTEDAC;  
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C30(uint32_t w){ // change function. don't care on depth or not
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C31(uint32_t w){ // new inner function. now new function for depth as param <24 and > is prob function of xor cycle
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  //  gate[w].matrix[3]=24<<6;
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_functionprob1; // 
  }
}

void SR_geo_outer_C32(uint32_t w){ // change function.  // dac on depth
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select

  gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac); // depth
  gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac); // depth // probCV1
  
  gate[w].funcbit=routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_functionprob2; 
  }
}

void SR_geo_outer_C33(uint32_t w){ // new inner function. now new function for depth as param <24 and > is prob function of xor cycle // dacpar
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  //  gate[w].matrix[3]=24<<6;
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].matrix[14]=(gate[dacfrom[daccount][w]].dac); // dacpar

  gate[w].inner=SR_geo_inner_functionprob1; // 
  }
}

// rewriting up to here.... check speeds and runglers, simplify probs and test all!!
// also we need to use routebits_anystrobe_notypesz

//4.0/////// speed funcs

void SR_geo_outer_C40(uint32_t w){ // speed function select
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // tested
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C41(uint32_t w){ // 41: bitfunc with gapped speedfunc
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[3]=CVL[w]; // bitfunc
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C42(uint32_t w){ // 42: depth/route ^^^ with gapped speedfunc
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  if (depth_routebits_typesz[gate[w].matrix[3]>>6])  gate[w].matrix[4]=CVL[w]; // depth
  else SETROUTECV;  
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C43(uint32_t w){ // length or we can throw in dacdepth
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[6]=CVL[w];// length
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

//5.0 runglers

void SR_geo_outer_C50(uint32_t w){ // redo speedfunc select with fixed func1 (osc) and gapped func2, gapped depth in both cases
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // tested
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
  gate[w].matrix[12]=0<<7;// select osc1 from abstractz
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
  gate[w].matrix[12]=0<<7;// select osc1 from abstractz

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
  gate[w].matrix[12]=CVL[w];// cv sel from abstractz
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

// draft generic prob cvspeed probs: prob of funcX vs funcY (Cv for select each, depth)
void SR_geo_outer_C60(uint32_t w){ // gapped speed. prob is from strobe so we can select alt function with CVL
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  // 4 and 5 are CVs swopped for probs
  // 3 and 12 are alt functions
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped
  gate[w].matrix[12]=CVL[w]; // alt function
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probusesstrobe;
  }
}

void SR_geo_outer_C61(uint32_t w){ // gapped speed. select probfs
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  // 4 and 5 are CVs swopped for probs
  // 3 and 12 are alt functions
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped
  gate[w].matrix[9]=CVL[w]; // probfs
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probusesstrobe;
  }
}

void SR_geo_outer_C62(uint32_t w){ // gapped speed. prob is from strobe so we can select depth with CVL! gapped first route
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  // 4 and 5 are CVs swopped for probs
  // 3 and 12 are alt functions
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped
  //  gate[w].matrix[12]=CVL[w];

  if (!(depth_routebits_typesz[gate[w].matrix[12]>>6])) gate[w].altroute=CVL[w]>>8;    // if needs be set altroute
  gate[w].matrix[4]=CVL[w]; // always set depth

  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probusesstrobe;
  }
}

// trial now with prob with no depths (some strobe) -> probfsin_nodepth
void SR_geo_outer_C63(uint32_t w){ // gapped speed. prob is no depth so we can select alt function with CVL
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  // 4 and 5 are CVs swopped for probs
  // 3 and 12 are alt functions
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped
  gate[w].matrix[9]=CVL[w]; // probfs - check <45 
  //  gate[w].matrix[12]=CVL[w]; // alt function TESTY
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probnodepth;
  }
}

// 7.0 more prob//splits/complex - what we have left: prob of dac out, depth probs against dac... - see how this works...
// probfdepthnoin // prob against dacfrom: [10]
// altfunc, probfunc, as above - see how it goes...
void SR_geo_outer_C70(uint32_t w){ // gapped speed. prob alt function with CVL
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  // 4 and 5 are CVs swopped for probs
  // 3 and 12 are alt functions
  //  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped
  gate[w].matrix[10]=gate[dacfrom[daccount][w]].dac;
  gate[w].matrix[12]=CVL[w]; // alt function
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probdepth;
  }
}

void SR_geo_outer_C71(uint32_t w){ // gapped speed. select func
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  // 4 and 5 are CVs swopped for probs
  // 3 and 12 are alt functions
  //  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped
  gate[w].matrix[9]=CVL[w]; // probfs

  gate[w].matrix[10]=gate[dacfrom[daccount][w]].dac;
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probdepth;
  }
}

void SR_geo_outer_C72(uint32_t w){ // gapped speed. select depth/route
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  // 4 and 5 are CVs swopped for probs
  // 3 and 12 are alt functions
  //  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2// also CV1 for func1 or gapped

  if (!(depth_routebits_typesz[gate[w].matrix[12]>>6])) gate[w].altroute=CVL[w]>>8;    // if needs be set altroute
  gate[w].matrix[4]=CVL[w]; // always set depth

  gate[w].matrix[10]=gate[dacfrom[daccount][w]].dac;
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probdepth;
  }
}

//dep dacout prob
void SR_geo_outer_C73(uint32_t w){ // test prob of dac out with gapped [9]//select prob function
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2 - or we gap this?
  ///  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__ - gapped now so we need ones with depth
  gate[w].matrix[10]=CVL[w]; // probCV1
  //  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // CV2 for those which use IN     
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_probofdacoutC;
}
}

/////////////////////////
/*
8.0, 9.0 10.0 11.0 -> strobe functions

see geo.c

first set is basic strobe speed functions maybe with routes at beginning 00... then more complex into probs with CV and CVL

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


