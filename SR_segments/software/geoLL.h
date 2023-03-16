// geoLL
//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

// allfrom geoCC so far ++

void SR_geo_inner_gappedfunctionrung(uint32_t w){
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (zbinrouteSRbitsfixed(0,0,w)){
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
	bitn=(routebits_depth_typesz[gate[w].matrix[12]>>extent_routebits_depth_typesz])(gate[w].matrix[5], gate[w].matrix[4], w);
      }	  
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3xnorouteabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // abstractbits_forrung[32]
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3_1_norouteabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac31(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // abstractbits_forrung[32]
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3_1_routeabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac31(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // abstractbits_forrung[32]
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3_3_routeabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac33(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // abstractbits_forrung[32]
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3_4_routeabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac34(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // abstractbits_forrung[32]
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3_3_norouteabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac33(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // abstractbits_forrung[32]
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3xrouteabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // abstractbits_forrung[32]
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

//0.0////////

void SR_geo_outer_L00(uint32_t w){  // set TYPE
  if (gate[w].changed==1) {
    RESETL; // added 21/12 only reset on change
    gate[w].changed=0;
  }
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  SETROUTETYPECV;
  gate[w].inner=SR_geo_inner_globalC; // routetype/theroute so always at reset route/base global
}

// we need L10 to replace C10 ??? NZbinroutfixed_prob3 - route against inv cycle
void SR_geo_outer_L10(uint32_t w){ // prob3
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=7<<6; // NZbinroutfixed_prob3
  gate[w].matrix[4]=CVL[w]; //
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 
  gate[w].inner=SR_geo_inner_function;
  }
}

void SR_geo_outer_L11(uint32_t w){ // probzero
  if (gate[w].changed==0) {
    gate[w].matrix[0]=0<<7;
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[9]=0; // probbits
    gate[w].matrix[3]=0; // zbinr
    gate[w].matrix[10]=CVL[w];

    gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
    gate[w].extent=extent_routebits_nodepth_typesz; 
    gate[w].depths=depth_routebits_nodepth_typesz;
    gate[w].inner=SR_geo_inner_functionprobzero; // gapped
  }
}

// 4 simple bit as clkfrom runglers:
// L40 from C40

void SR_geo_outer_L41(uint32_t w){ // select function/gapped array
  if (gate[w].changed==0) {
    gate[w].matrix[0]=24<<7; //always  zbinrouteSRbits
    gate[w].matrix[1]=CV[w]; //route
    gate[w].matrix[3]=CVL[w];// selfunction
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    gate[w].inner=SR_geo_inner_function; // gapped
  }
}

// route in from dacfrom frees up CV for depth and sel - innergapped // this one can die out!
void SR_geo_outer_L42(uint32_t w){ // select function/gapped array
  if (gate[w].changed==0) {
    gate[w].matrix[0]=24<<7; //always zbinrouteSRbitsS_
    gate[w].matrix[1]=gate[dacfrom[daccount][w]].dac;  // route
    gate[w].matrix[3]=CVL[w];// selfunction <<6//
    gate[w].matrix[4]=CV[w];
    gate[w].matrix[10]=CV[w];
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    gate[w].matrix[9]=0<<6; // select probfs - zprobbits here against LFSR__ 
    gate[w].inner=SR_geo_inner_gappedfunction; // as we have depth here
  }
}

// zbinrouteSRbitsfixed on the inside
void SR_geo_outer_L43(uint32_t w){ // select function/gapped array - fixed route function in the inner
  if (gate[w].changed==0) {
    gate[w].matrix[3]=CVL[w];// selfunction
    gate[w].matrix[4]=CV[w];
    gate[w].matrix[10]=CV[w];  
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    gate[w].matrix[9]=0<<6; // select probfs - zprobbits here against LFSR__
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    gate[w].inner=SR_geo_inner_gappedfunctionrung; // as we have depth here 
  }
}

// TEST!
///////////////////////////////////////////////////////////////////////////////////
// add other type of abstract runglers... from NN now

// abstract in with prob of route in and speed - inner_functionN
void SR_geo_outer_L50(uint32_t w){ // abstract in
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac4
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[9]=0<<6; // probbits
    gate[w].matrix[10]=CVL[w]; // depth for prob
    if (w==0) {//gate[w].matrix[8]=gate[dacfromopp[daccount][w]].dac;
      if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac);
      else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=(gate[dacfrom[daccount][w]].dac);
      else gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2 or gapped
    }
    else gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2 or gapped
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    gate[w].inner=SR_geo_inner_probabstractentryX;
  }
}

// select abstract + route
void SR_geo_outer_L51(uint32_t w){ 
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac4    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    if (w==0) {
      gate[w].matrix[7]=CVL[w];
      if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac);
      else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=(gate[dacfrom[daccount][w]].dac);
      else gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); 
    }
    else
      {
	gate[w].matrix[5]=gate[dacfromopp[daccount][w]].dac; // CV2 or gapped
	gate[w].matrix[20]=CVL[w]; // sel abstract
      }
    gate[w].inner=SR_geo_inner_rungC;
  }
}

void SR_geo_outer_L52(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac4    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    if (w==0){
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=CVL[w];
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=CVL[w]; // mix for dacs
    else gate[w].matrix[5]=CVL[w]; 
    }
    else
      {
    gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; //
    gate[w].matrix[5]=CVL[w];
      }
    gate[w].inner=SR_geo_inner_rungC;
  }
}

///++ trial add dac??? but what is CVL? // sel abstract
void SR_geo_outer_L53(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=4<<7; // spdfrac1 now
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2

    if (w==0){
    gate[w].matrix[7]=CVL[w]; // sel abstract // 20 we like
    if (inall_depth[gate[w].matrix[7]>>6]==1) gate[w].matrix[8]=(gate[dacfrom[daccount][w]].dac);
    else if (inall_depth[gate[w].matrix[7]>>6]==2) gate[w].matrix[21]=(gate[dacfrom[daccount][w]].dac);
    else gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); 
    }
    else
      {
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped 5 is also for abstractbits
    gate[w].matrix[4]=gate[dacfromopp[daccount][w]].dac;
    gate[w].matrix[20]=CVL[w]; // sel abstract // 20 we like
    }
    gate[w].inner=SR_geo_inner_rungC;
  }
}

void SR_geo_outer_L60(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3xrouteabstractL; // gapped route function
  }
}

void SR_geo_outer_L61(uint32_t w){ // speedroute from top
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3_1_routeabstractL; 
  }
}

// would be nice to be able to select where we get speedfrom - or have 4 options here... - our own speed? trial in new one // route // no route
void SR_geo_outer_L62(uint32_t w){ // spdfracdac3
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac);
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3_3_routeabstractL; 
  }
}

void SR_geo_outer_L63(uint32_t w){ // spdfracdac3
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3_4_routeabstractL; 
  }
}


