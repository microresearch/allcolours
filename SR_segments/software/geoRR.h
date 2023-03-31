// geoRR 

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER


void SR_geo_inner_rungnorouteA(uint32_t w){  
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_function_glob(uint32_t w){  
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      (*globalls_depth[glob])(gate[w].matrix[19]);
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_function_globoutside(uint32_t w){  
  HEADNADA;
  (*globalls_depth[glob])(gate[w].matrix[19]); 

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
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_gappedfunction_glob(uint32_t w){  // depth or cycle prob - glob has depth
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      (*globalls_depth[glob])(gate[w].matrix[19]);
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    if (gate[w].depths[gate[w].matrix[3]>>gate[w].extent]) {// we use depth // *if (!depth_routebits_nostrobe_notypesz[gate[w].matrix[3]>>7])*   
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    }
    else { // prob of cycle or in new version xor cycle...
        if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
      }
	  
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_gappedfunction_globoutside(uint32_t w){  // depth or cycle prob - no depth glob
  HEADNADA;
  (*globalls_nodepth[glob])(0); // nodepth so strobe later

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
      bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
    }
    else { // prob of cycle or in new version xor cycle...
        if ((*probf_anystrobe_depth[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); 
      }
      else {
	bitn=(*abstractbitsz[gate[w].matrix[20]>>7])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done
    }
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

//0.0////////

void SR_geo_outer_R00(uint32_t w){  // set TYPE
  if (gate[w].changed==1) {
    RESETR; // added 21/12 only reset on change
    gate[w].changed=0;
  }
  gate[w].matrix[0]=3<<7; // spdfracend
  gate[w].matrix[1]=CV[w];// speed
  SETROUTETYPECV;
  gate[w].inner=SR_geo_inner_globalC; // routetype/theroute so always at reset route/base global
}

void SR_geo_outer_R01(uint32_t w){ //R01 abstract sel: no route
  if (gate[w].changed==0){
  gate[w].matrix[0]=3<<7; // spdfracend
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[20]=CVL[w]; // abstract bits
  gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_norouteadcN;
  }
}

void SR_geo_outer_R02(uint32_t w){ //R02 abstract depth: with no route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=3<<7; // spdfracend
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[5]=CVL[w];
  gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_norouteadcN;
  //  gate[w].inner=SR_geo_inner_globalC; // now handles abstract bits
  }
}

void SR_geo_outer_R03(uint32_t w){ // R03 abstractL: void SR_geo_outer_N02(uint32_t w){ // 1-prob of ADC entry or fixed entry  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=3<<7; // spdfracend
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<6; // probbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probadcentry;// fixed as probbits and fixed entry
  }
}

// alt for older as we set length later... prob 1 route against cycle
void SR_geo_outer_R10(uint32_t w){  //leave as
  if (gate[w].changed==0){
  gate[w].matrix[0]=3<<7; // spdfracend
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=5<<6; // NZbinroutfixed_prob1 - type/prob against LFSR and globflag - checked for new array
  gate[w].matrix[4]=CVL[w]; 
  gate[w].funcbit=routebits_depth_typesz;
  gate[w].extent=extent_routebits_depth_typesz; 
  gate[w].inner=SR_geo_inner_function;
  }
}

// abstract depth from dac on RR  - where to fill in -c13 in both cases!// both?*
void SR_geo_outer_R13(uint32_t w){ // set abstract type from CVL and depth from dacfrom // fixed route in or no route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=3<<7; // spdfracend
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[20]=CVL[w]; //abstract type
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac);
  gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_norouteadcN;
  }
}

///// runglers which differ from LL as they have no route in
void SR_geo_outer_R52(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac4    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; //
    gate[w].matrix[5]=CVL[w];
    gate[w].inner=SR_geo_inner_rungnorouteA;
  }
}

///++ trial add dac??? but what is CVL? // sel abstract
void SR_geo_outer_R53(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=4<<7; // spdfrac1 now
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped 5 is also for abstractbits
    gate[w].matrix[4]=gate[dacfromopp[daccount][w]].dac;
    gate[w].matrix[20]=CVL[w]; // sel abstract // 20 we like
    gate[w].inner=SR_geo_inner_rungnorouteA;
  }
}

// R60, L60, R62, L63

// abstract with no route in... SR_geo_inner_norouteadcN // convert to abstract - but we need to have selected that above
void SR_geo_outer_R60(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac);
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped ???
    gate[w].inner=SR_geo_inner_dacspeed3xnorouteabstractL; 
  }
}

void SR_geo_outer_R62(uint32_t w){ // spdfracdac3
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3_1_norouteabstractL; 
  }
}

void SR_geo_outer_R63(uint32_t w){ // spdfracdac31
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=(gate[dacfromopp[daccount][w]].dac); 
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3_3_norouteabstractL; 
  }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////
// 12.0+

//0binaryN, 1binaryX, 2SRRglobalbumpcv, 3SRRglobalbumpcvn, 4SRRglobalbumpcvnroute, 5SRRglobalbumpcvndac, 6SRRglobalbumpcvnspd, 7SRRglobalorder, 8SRRglobaltailset, 9binaryN, 10binaryX,

void SR_geo_outer_R120(uint32_t w){ //binaryN
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=0;
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_glob; // uses depth place inside as depends on SR
  }
}

void SR_geo_outer_R121(uint32_t w){ // ordering
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=7;
    gate[w].matrix[19]=CVL[w]; 
    gate[w].inner=SR_geo_inner_function_globoutside;  // outside speed
  }
}

void SR_geo_outer_R122(uint32_t w){ // all counts changed
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=3; // bumpcvn    
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside; // outside speed
  }
}

void SR_geo_outer_R123(uint32_t w){ // tailset
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=8; //     //SRRglobaltailset(CVL[w]);
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside; // outside speed
  }
}

////130

//0binaryN, 1binaryX, 2SRRglobalbumpcv, 3SRRglobalbumpcvn, 4SRRglobalbumpcvnroute, 5SRRglobalbumpcvndac, 6SRRglobalbumpcvnspd, 7SRRglobalorder, 8SRRglobaltailset, 9binaryN, 10binaryX,

void SR_geo_outer_R130(uint32_t w){ //binaryX
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=1;
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_glob; // uses depth  inside
  }
}

void SR_geo_outer_R131(uint32_t w){ // SRRglobalbumpcvnroute
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=4;
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside; // outside speed
  }
}

void SR_geo_outer_R132(uint32_t w){ // SRRglobalbumpcvndac
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=5;     
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside; // outside speed
  }
}

void SR_geo_outer_R133(uint32_t w){ // SRRglobalbumpcvnspd
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=6; //     
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside; // outside speed
  }
}

//140

/*
outside and we use CV so gapped - STROBES: all outside!
*/

void SR_geo_outer_R140(uint32_t w){ // globalorderbumpS, 
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=3; //     
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];
    gate[w].matrix[11]=(gate[dacfromopp[daccount][w]].dac);
    gate[w].inner=SR_geo_inner_gappedfunction_globoutside; // outside speed
  }
}

void SR_geo_outer_R141(uint32_t w){ // bumpS
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=0; //     
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];
    gate[w].matrix[11]=(gate[dacfromopp[daccount][w]].dac);
    gate[w].inner=SR_geo_inner_gappedfunction_globoutside; // outside speed
  }
}

void SR_geo_outer_R142(uint32_t w){ // bumproute
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=1; //     
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];
    gate[w].matrix[11]=(gate[dacfromopp[daccount][w]].dac);
    gate[w].inner=SR_geo_inner_gappedfunction_globoutside; // outside speed no depth
  }
}

void SR_geo_outer_R143(uint32_t w){ // bumpdac
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=2; //     
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];
    gate[w].matrix[11]=(gate[dacfromopp[daccount][w]].dac);
    gate[w].inner=SR_geo_inner_gappedfunction_globoutside; // outside speed no depth
  }
}

//150+ 3 dac led depthies: bumpcvn, cvnroute, globalorder - so again we have free CV and use - inside speedYES

// SR_geo_inner_gappedfunction_glob
void SR_geo_outer_R150(uint32_t w){ // globalorder
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    glob=7; //
    gate[w].matrix[19]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];    
    gate[w].inner=SR_geo_inner_gappedfunction_glob;  // inside speed depth
  }
}

void SR_geo_outer_R151(uint32_t w){ // bumpcvn
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    glob=3; //
    gate[w].matrix[19]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_glob;  // inside speed depth
  }
}

void SR_geo_outer_R152(uint32_t w){ // cvnroute
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    glob=4; //checked
    gate[w].matrix[19]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_glob;  // inside speed depth
  }
}

//finally
void SR_geo_outer_R153(uint32_t w){  // final all gapped reset - with just route reset...
    if (gate[w].changed==1) {
      RESETG; // now doesn't reset count but does reset binary
      gate[w].changed=0;
      }
    gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  glob=4; //checked
  gate[w].matrix[19]=CVL[w]; // for route
  gate[w].inner=SR_geo_inner_function_globoutside; // outside speed
}

// //4x arrays 64 long match each function C00->C64!
void (*geo_inners[3][64])(uint32_t w)={ // RR doesn't call it
  {SR_geo_inner_globalC, SR_geo_inner_globalC, SR_geo_inner_globalC, SR_geo_inner_probadcentry,  SR_geo_inner_globalC, SR_geo_inner_globalC, SR_geo_inner_routeabstractR, SR_geo_inner_function,  /*20*/SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_probadcadvance, SR_geo_inner_probadcreset,  SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_gappedfunctionC, /*40*/SR_geo_inner_rungC, SR_geo_inner_probabstractentryX, SR_geo_inner_rungnoroute, SR_geo_inner_rungnoroute,  SR_geo_inner_dacspeed3xnorouteadcN, SR_geo_inner_dacspeed3xrouteadcN, SR_geo_inner_dacspeed3xnorouteadcN, SR_geo_inner_dacspeed3xrouteadcN,  SR_geo_inner_probabstractentryX, SR_geo_inner_rungC, SR_geo_inner_rungC, SR_geo_inner_rungC, /*c70*/SR_geo_inner_gappedfunction, SR_geo_inner_function, SR_geo_inner_probdepthx, SR_geo_inner_probdepthx, /*80*/SR_geo_inner_str_functionN, SR_geo_inner_str_function, SR_geo_inner_str_function, SR_geo_inner_str_probfunction,  SR_geo_inner_str_functionN, SR_geo_inner_str_gappedfunction, SR_geo_inner_str_gappedfunction, SR_geo_inner_str_function2,  SR_geo_inner_str_gappedfunction, SR_geo_inner_str_function, SR_geo_inner_function_strobexor, SR_geo_inner_function_strobexor,  SR_geo_inner_str_probfunction, SR_geo_inner_str_probfunction, SR_geo_inner_str_probfunctionalt, SR_geo_inner_str_probfunction, /*120*/SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX,  SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS,  SR_geo_inner_probdepthdepthS, SR_geo_inner_matrixreduceX, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS}, // matches NN-done
 
  {SR_geo_inner_globalC, SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_functionprobzero, SR_geo_inner_globalC, SR_geo_inner_function,  /*20*/SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_function,  SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_gappedfunctionC, SR_geo_inner_probcyclexorC, /*40*/SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_gappedfunction, SR_geo_inner_gappedfunctionrung, SR_geo_inner_probabstractentryX, SR_geo_inner_rungC, SR_geo_inner_rungC, SR_geo_inner_rungC, SR_geo_inner_dacspeed3xrouteabstractL, SR_geo_inner_dacspeed3_1_routeabstractL, SR_geo_inner_dacspeed3_3_routeabstractL, SR_geo_inner_dacspeed3_4_routeabstractL, /*c60*/SR_geo_inner_probcycleCnodepth, SR_geo_inner_probcyclexorCnodepth, SR_geo_inner_probnodepth, SR_geo_inner_probdepth, /*80*/SR_geo_inner_str_functionN, SR_geo_inner_str_function, SR_geo_inner_str_function, SR_geo_inner_str_probfunction,  SR_geo_inner_str_functionN, SR_geo_inner_str_gappedfunction, SR_geo_inner_str_gappedfunction, SR_geo_inner_str_function2,  SR_geo_inner_str_gappedfunction, SR_geo_inner_str_function, SR_geo_inner_function_strobexor, SR_geo_inner_function_strobexor,  SR_geo_inner_str_probfunction, SR_geo_inner_str_probfunction, SR_geo_inner_str_probfunctionalt, SR_geo_inner_str_probfunction, /*120*/SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX,  SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS,  SR_geo_inner_probdepthdepthS, SR_geo_inner_matrixreduceX, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS}, // matches LL0-done
  
  {SR_geo_inner_globalC, SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_globalC, SR_geo_inner_globalC, SR_geo_inner_globalC, SR_geo_inner_function,  /*20*/SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_function,  SR_geo_inner_function, SR_geo_inner_function, SR_geo_inner_gappedfunctionC, SR_geo_inner_probcyclexorC, /*40*/SR_geo_inner_function, SR_geo_inner_gappedfunction, SR_geo_inner_dacspeed3, SR_geo_inner_testdacasdepth,  SR_geo_inner_probcycleC, SR_geo_inner_functionprobzero, SR_geo_inner_probcycleC, SR_geo_inner_probcyclexorC,  SR_geo_inner_probcycleCnodepth, SR_geo_inner_probcyclexorCnodepth, SR_geo_inner_probnodepth, SR_geo_inner_probdepth, SR_geo_inner_gappedfunction, SR_geo_inner_function, SR_geo_inner_probdepthx, SR_geo_inner_probdepthx, /*80*/SR_geo_inner_str_functionN, SR_geo_inner_str_function, SR_geo_inner_str_function, SR_geo_inner_str_probfunction,  SR_geo_inner_str_functionN, SR_geo_inner_str_gappedfunction, SR_geo_inner_str_gappedfunction, SR_geo_inner_str_function2,  SR_geo_inner_str_gappedfunction, SR_geo_inner_str_function, SR_geo_inner_function_strobexor, SR_geo_inner_function_strobexor,  SR_geo_inner_str_probfunction, SR_geo_inner_str_probfunction, SR_geo_inner_str_probfunctionalt, SR_geo_inner_str_probfunction, /*120*/SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX, SR_geo_inner_str_probfunctionX,  SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_str_probfunctionXX, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS,  SR_geo_inner_probdepthdepthS, SR_geo_inner_matrixreduceX, SR_geo_inner_probdepthdepthS, SR_geo_inner_probdepthdepthS}, // matches CC-done
};


void SR_geomantic_matrixcopyX(uint32_t w){ 
  uint32_t x;
  for (x=0;x<22;x++){
    gate[w].matrixX[x]=(*(gate[w].matrixp[x]));
    gate[w].matrix[x]=(*(gate[w].matrixp[x]));
  }
}

//spdfrom slides across - inner in outer also as a kind of model to go further with...
void SR_geo_outer_C153(uint32_t w){
  static uint32_t who[3]={0,0,0};
    if (gate[w].changed==0) {
      if (spdfracxxx(CV[w], 0, w)){ 
      who[w]++;
      if (who[w]>63) who[w]=0;
    }
    SR_geomantic_matrixcopyX(w);
    gate[w].matrix[6]=CVL[w]; //
    //    gate[w].routetype=gate[w].matrix[16]>>9; // fixed!
    gate[w].inner=geo_inners[w][gate[w].modes[who[w]]];
    }
}

