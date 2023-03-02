// geoRR - default speed as spdfracend?

/*

RR: routes, global, abstracts functions - prob of abstract vs route (as in ADC)

- follow rough scheme of NN but obviously without ADC!

- *DONEquestion if we slow down speed of geoRR so is half or quarter - 17, 18 octaves, to test. as seems a bit too fast*

on globals:

*We can also imagine slippage/attachment of settings in global modes eg. we have array of count daccount speeedcnt etc and we attach as in matrixp to these*

FOR GLOBAL rmodes:::
- *16 last global modes*
- *global modes all hold last function (eg. it could be abstract function)*

we need to sort following: depth/no depth, global dacfrom?// also speedfrom dac, setting of route/type (16 and 17). which arrays to use for functions//how these match*

////////////////////////////////



older from geoLR.h:

 */


//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

void SR_geo_inner_norouteabstractL(uint32_t w){  // new template
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
    bitn=(*abstractbitsz[gate[w].matrix[20]>>extent_abstractbits])(gate[w].matrix[5], gate[w].matrix[4], w); 
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
      (*globalls_depth[glob>>8])(gate[w].matrix[19]);
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_function_globoutside(uint32_t w){  
  HEADNADA;
  (*globalls_depth[glob>>8])(gate[w].matrix[19]); // but we need to hold strobed just do later

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// gapped globs - no depth for glob // inner and outer todo!
// globalls_nodepth[16]

void SR_geo_inner_gappedfunction_glob(uint32_t w){  // depth or cycle prob - glob has depth
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      (*globalls_depth[glob>>8])(gate[w].matrix[19]);
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
	//	bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
	bitn=(routebits_depth_typesz[gate[w].matrixX[12]>>extent_routebits_depth_typesz])(gate[w].matrixX[5], gate[w].matrixX[4], w);
      }
	  
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_gappedfunction_globoutside(uint32_t w){  // depth or cycle prob - no depth glob
  HEADNADA;
  (*globalls_nodepth[glob>>8])(0); // nodepth

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].strobed=1;
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
	//	bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
	bitn=(routebits_depth_typesz[gate[w].matrixX[12]>>extent_routebits_depth_typesz])(gate[w].matrixX[5], gate[w].matrixX[4], w);
      }
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

//0.0////////

void SR_geo_outer_R00(uint32_t w){  // set length // set length or could better be TYPE - route in
  if (gate[w].changed==1) {
    RESETR; // added 21/12 only reset on change also does RESETG global reset
    gate[w].changed=0;
  }
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_globalC; //
}

void SR_geo_outer_R01(uint32_t w){ //R01 abstract sel: no route
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[20]=CVL[w]; // abstract bits
  gate[w].inner=SR_geo_inner_norouteabstractL;
  }
}

void SR_geo_outer_R02(uint32_t w){ //R02 abstract depth: with route in
  if (gate[w].changed==0){
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[5]=CVL[w];
  gate[w].inner=SR_geo_inner_globalC; // now handles abstract bits
  }
}

void SR_geo_outer_R03(uint32_t w){ // R03 abstractL: void SR_geo_outer_N02(uint32_t w){ // 1-prob of ADC entry or fixed route entry  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<6; // probbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); 
  gate[w].inner=SR_geo_inner_probadcentry;// fixed as probbits and fixed entry
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
    glob=0<<8;
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_glob; // uses depth
  }
}

void SR_geo_outer_R121(uint32_t w){ // ordering
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=7<<8;
    gate[w].matrix[19]=CVL[w]; // 64 now...
    gate[w].inner=SR_geo_inner_function_globoutside;
  }
}

void SR_geo_outer_R122(uint32_t w){ // all counts changed
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=3<<8; // bumpcvn    
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside;
  }
}

void SR_geo_outer_R123(uint32_t w){ // tailset
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=8<<8; //     //SRRglobaltailset(CVL[w]);
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside;
  }
}

////130

//0binaryN, 1binaryX, 2SRRglobalbumpcv, 3SRRglobalbumpcvn, 4SRRglobalbumpcvnroute, 5SRRglobalbumpcvndac, 6SRRglobalbumpcvnspd, 7SRRglobalorder, 8SRRglobaltailset, 9binaryN, 10binaryX,

void SR_geo_outer_R130(uint32_t w){ //binaryX
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=1<<8;
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_glob; // uses depth
  }
}

void SR_geo_outer_R131(uint32_t w){ // SRRglobalbumpcvnroute
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=4<<8;
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside;
  }
}

void SR_geo_outer_R132(uint32_t w){ // SRRglobalbumpcvndac
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=5<<8;     
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside;
  }
}

void SR_geo_outer_R133(uint32_t w){ // SRRglobalbumpcvnspd
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=6<<8; //     //SRRglobaltailset(CVL[w]);
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside;
  }
}

//140

/*
4 fixed - CVL for nodepth globals: SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalbumpspd, SRRglobalbumpbit0, SRRglobalorderbumpS, SRRglobalorderbumpbit // 7

trig: bumpS, bumproute, bumpdac, bumpspd, globalorderbumpS, 
rest are DAC -> bit0, globalorderbumpbit

outside and we use CV

trigs!

*/

void SR_geo_outer_R140(uint32_t w){ // globalorderbumpS, 
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=9<<8; //     
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_globoutside;
  }
}

void SR_geo_outer_R141(uint32_t w){ // bumpS
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=1<<8; //     
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_globoutside;
  }
}

void SR_geo_outer_R142(uint32_t w){ // bumproute
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=2<<8; //     
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_globoutside;
  }
}

void SR_geo_outer_R143(uint32_t w){ // bumpdac
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=3<<8; //     
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_globoutside;
  }
}

//150+ 3 dac led depthies: bumpcvn, cvnroute, globalorder - so again we have free CV and use 

// SR_geo_inner_gappedfunction_glob
void SR_geo_outer_R150(uint32_t w){ // globalorder
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    glob=7<<8; //
    gate[w].matrix[19]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_glob;
  }
}

void SR_geo_outer_R151(uint32_t w){ // bumpcvn
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    glob=3<<8; //
    gate[w].matrix[19]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_glob;
  }
}

void SR_geo_outer_R152(uint32_t w){ // cvnroute
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
    glob=4<<8; //checked
    gate[w].matrix[19]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[10]=CVL[w];  
    gate[w].inner=SR_geo_inner_gappedfunction_glob;
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
  glob=4<<8; //checked
  gate[w].matrix[19]=CVL[w]; // for route
  //  gate[w].matrix[4]=CVL[w];
  //  gate[w].matrix[10]=CVL[w];  
  //  gate[w].inner=SR_geo_inner_gappedfunction;
  //  gate[w].inner=SR_geo_inner_globalC; //
  gate[w].inner=SR_geo_inner_function_globoutside;
}
