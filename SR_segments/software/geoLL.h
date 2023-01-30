// geoLL

/*

LL: routes as primary, speeds

older from geoLR.h:

L-routes only and etc, R etc, abstracts, routes, and globals...


 */

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

// from geoCC so far ++

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

//0.0////////

void SR_geo_outer_L00(uint32_t w){  // set length
  if (gate[w].changed==1) RESETL; // added 21/12 only reset on change 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_routeC; // routetype/theroute so always at reset route/base global
}

// change type/globalroute
void SR_geo_outer_L01(uint32_t w){ // globalroute/set routetype
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  SETROUTETYPECV;
  gate[w].inner=SR_geo_inner_globalC; // routetype/but globalroute
  }
}

void SR_geo_outer_L02(uint32_t w){ // prob1 - route vs cycle
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

void SR_geo_outer_L03(uint32_t w){ // prob4 - route vs. [route^cycle]
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

//1.0////////

void SR_geo_outer_L10(uint32_t w){ // change route. gapped type
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

void SR_geo_outer_L11(uint32_t w){ // change type. theroute
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  SETROUTETYPECV;
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_L12(uint32_t w){ // theroute/ - set dacparam but we won't likely notice
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[14]=CVL[w]; // set dacparam and set xx
  gate[w].inner=SR_geo_inner_routeC; // routetype/theroute
  }
}

void SR_geo_outer_L13(uint32_t w){ // theroute/length
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_routeC; // routetype/theroute
  }
}

//2.0//////// select function, cv->depth, repeat 2 probs now with changed function

void SR_geo_outer_L20(uint32_t w){ // change function. theroute
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_L21(uint32_t w){ // gapped function. set depth/route
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

void SR_geo_outer_L22(uint32_t w){ // prob/depth of gapped function vs. cycle
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

void SR_geo_outer_L23(uint32_t w){ // gapped function vs. [gapped XOR cycle]
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

//3.0/////// use of dacs: depth/route as dacfrom, dacpar as dacfrom, length as dacfrom, function as dacfrom? ///depth is dac - what we do with CV? use as length

void SR_geo_outer_L30(uint32_t w){ // dac-length. depth-cv
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

void SR_geo_outer_L31(uint32_t w){ // dac-dacpar. depth-cv
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

void SR_geo_outer_L32(uint32_t w){ // dac-depth. dacpar-cv
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

void SR_geo_outer_L33(uint32_t w){ // dac-depth. length-cv
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

// next 16 follows geoCC


