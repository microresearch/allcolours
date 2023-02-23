// geoLL

// can have some abstract runglers from NN here...

/*

LL: routes as primary, speeds 0 follows CC but add extra rungler!

older from geoLR.h:

L-routes only and etc, R etc, abstracts, routes, and globals...

prime rungler territory

but much following CC so far - unless we can extend runglers...

 */

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

// allfrom geoCC so far ++

void SR_geo_inner_gappedfunctionrung(uint32_t w){  // depth or cycle prob
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
	bitn=(routebits_depth_typesz[gate[w].matrixX[12]>>extent_routebits_depth_typesz])(gate[w].matrixX[5], gate[w].matrixX[4], w);
      }	  
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

/// rework for abstract

void SR_geo_inner_dacspeed3xnorouteabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3x(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[18], gate[w].matrix[5], w); // abstractbits_forrung[32]
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3selfnorouteabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3self(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[18], gate[w].matrix[5], w); // abstractbits_forrung[32]
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_dacspeed3selfrouteabstractL(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (spdfracdac3self(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[18], gate[w].matrix[5], w); // abstractbits_forrung[32]
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
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
    bitn=(*abstractbits_forrung[gate[w].matrix[20]>>7])(gate[w].matrix[18], gate[w].matrix[5], w); // abstractbits_forrung[32]
    bitn^=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

//0.0////////

void SR_geo_outer_L00(uint32_t w){  // set length or could better be TYPE
  if (gate[w].changed==1) {
    RESETL; // added 21/12 only reset on change
    gate[w].changed=0;
  }
    
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_globalC; // routetype/theroute so always at reset route/base global
}

// next follow CC

// 4 simple bit as clkfrom runglers:
//rungler2: route in, clkfrom speedfrom SR
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
    gate[w].matrix[0]=24<<7; //always
    gate[w].matrix[1]=gate[dacfrom[daccount][w]].dac; 
    gate[w].matrix[3]=CVL[w];// selfunction <<6//
    gate[w].matrix[4]=CV[w];
    gate[w].matrix[10]=CV[w];  
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__ 
    gate[w].inner=SR_geo_inner_gappedfunction; // as we have depth here
  }
}

void SR_geo_outer_L43(uint32_t w){ // select function/gapped array - fixed route function in the inner
  if (gate[w].changed==0) {
    gate[w].matrix[3]=CVL[w];// selfunction
    gate[w].matrix[4]=CV[w];
    gate[w].matrix[10]=CV[w];  
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    gate[w].matrix[9]=0<<6; // select probfs - zinvprobbits here against LFSR__
    gate[w].inner=SR_geo_inner_gappedfunctionrung; // as we have depth here
  }
}

// TEST!
///////////////////////////////////////////////////////////////////////////////////
// add other type of abstract runglers... from NN now
// select abstract + route
void SR_geo_outer_L50(uint32_t w){ 
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac3    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    //    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped 5 is also for abstractbits
    gate[w].matrix[20]=CVL[w]; // sel abstract
    gate[w].inner=SR_geo_inner_rungC;
  }
}

// no route in but we did sel... 
void SR_geo_outer_L51(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=6<<7; // tested // try fixed speed - spdfrac3    
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; //
    gate[w].matrix[5]=CVL[w];
    gate[w].inner=SR_geo_inner_rungnoroute;
  }
}

///++ trial add dac??? but what is CVL? // sel abstract
void SR_geo_outer_L52(uint32_t w){  // no route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=4<<7; // spdfrac1 now
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped 5 is also for abstractbits
    gate[w].matrix[4]=gate[dacfromopp[daccount][w]].dac;
    gate[w].matrix[20]=CVL[w]; // sel abstract // 20 we like
    gate[w].inner=SR_geo_inner_rungnoroute;
  }
}

/// to convert

// adc with no route in... SR_geo_inner_norouteadcN // convert to abstract - but we need to have selected that
void SR_geo_outer_L60(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].inner=SR_geo_inner_dacspeed3xnorouteadcN; 
  }
}

// repeat with route in
void SR_geo_outer_L61(uint32_t w){ // dacspeed3x
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3xrouteadcN; // gapped route function
  }
}

// would be nice to be able to select where we get speedfrom - or have 4 options here... - our own speed? trial in new one // route // no route
void SR_geo_outer_L62(uint32_t w){ // spdfracdac3self
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3selfnorouteadcN; 
  }
}

void SR_geo_outer_L63(uint32_t w){ // spdfracdac3self route in
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed cv1
    gate[w].matrix[2]=CVL[w];//gate[speedfrom[spdcount][w]].dac; // 2nd speed cv2
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // CV2 or gapped
    gate[w].inner=SR_geo_inner_dacspeed3selfrouteadcN; 
  }
}
