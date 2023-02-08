void SR_geo_outer_N10dd(uint32_t w){ //10: change routetype-global
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  SETROUTETYPECV;
  gate[w].inner=SR_geo_inner_globaladcN;
  }
}

void SR_geo_outer_N11dd(uint32_t w){ // route. not global
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  SETROUTECV;
  gate[w].inner=SR_geo_inner_routeadcN;
  }
}

void SR_geo_outer_N12dd(uint32_t w){ // adccv 
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  if (adcfromsd_depth[gate[w].matrix[7]>>7]) gate[w].matrix[8]=CVL[w]; // adccv
      else gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_routeadcN; // routetype/theroute so always at reset route/base global
}
}

void SR_geo_outer_N13dd(uint32_t w){ // length only
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_routeadcN; // routetype/theroute so always at reset route/base global
}
}


void SR_geo_outer_N02dd(uint32_t w){ // 1-prob of ADC entry or route entry  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<7; // invprobbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].inner=SR_geo_inner_probadcentry;//
}
}

void SR_geo_outer_N03dd(uint32_t w){ // 2-prob of ADC entry or route entry/XOR
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];
  gate[w].matrix[9]=0<<7; // invprobbits
  gate[w].matrix[10]=CVL[w]; // depth for prob
  gate[w].inner=SR_geo_inner_probadcentryxor;//
}
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


static inline uint32_t pSRBITMIX(uint32_t depth, uint32_t in, uint32_t w){//depth and in and we use dac so is a tough one
  uint32_t x, tmp, bitrr, temp, bitn=0;
  float mixer;
  tmp=255-(depth>>4); // 8 bits
    mixer=1.0f/((float)(in>>4)+1.0f);
    mixer*=(float)(gate[dacfrom[daccount][w]].dac>>4);
    // how to mix with DAC using CVL - gate[dacfrom[daccount][w]].dac
    tmp+=(int)mixer;
    if (tmp>255) tmp=255;
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
  return bitn;
  }



// DEP for divided versions
//uint32_t (*routebits_nostrobe_typesz[41])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRmatch, pSRshare, pbitLcvsrroute, pstream, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0}; // reorder for depths


// unused
//uint32_t (*routebits_onlystrobe_typesz[25])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitscyclestrI, zbinroutmybumpS, pSRxorroutes, pSRaddroutes, pSRGswop, pSRDACroutestrobe, pSRLLbumproute, pSRbumprouteD_, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRRLLswop, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5};

uint32_t depth_routebits_juststrobe_typesz[25]={0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};  //redo if needed ever



// alt geoCC:


void SR_geo_outer_C21(uint32_t w){ // change function. nodepth // gapped nodepth with prob of cycle
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above
  gate[w].depths=depth_routebits_nodepth_typesz;
  
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
  gate[w].depths=depth_routebits_nodepth_typesz;
  
  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_probcyclexorC; 
  }
}

void SR_geo_outer_C23(uint32_t w){ // change function. nodepth // gapped nodepth with prob of cycleXORinv
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above
  gate[w].depths=depth_routebits_nodepth_typesz;

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_probcyclexorinvC; 
  }
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

void SR_geo_outer_C20crash(uint32_t w){ // slur test crash
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=128<<7;//
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

// start again: depth, nodepth and full/mix


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

void SR_geo_outer_C30dd(uint32_t w){ // change function. don't care on depth or not
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

// should this not be with gapped prob? below
void SR_geo_outer_C30ddd(uint32_t w){ // sel function. array sans depth...routebits_nodepth_typesz
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // function  select
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz; //routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; 
  }
}

void SR_geo_outer_C31maybe(uint32_t w){ // gapped nodepth array with xor prob LFSR
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_nodepth_typesz;//routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_functionprobx1; // 
  }
}

void SR_geo_outer_C31dd(uint32_t w){ // new inner function. now new function for depth as param <24 and > is prob function of xor cycle
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_functionprob1; // 
  }
}

void SR_geo_outer_C32dd(uint32_t w){ // change function.  // dac on depth
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

// 2/2 or could be new function array... such as routebits_anystrobe_notypesz
void SR_geo_outer_C33dd(uint32_t w){ // new inner function. now new function for depth as param <24 and > is prob function of xor cycle // dacpar 
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


// we already have EN version
//WIARD versions - macro versions - inside themselves
//WIARD: noise/comp selects new input or loop back/inverted loop back (jumper)

//WIARD
static inline uint32_t zwiardbits(uint32_t depth, uint32_t in, uint32_t w){ //global
  uint32_t bt=0, bitrr, tmp;
  if (depth>in){
    if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w]; 
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bt;
}

static inline uint32_t zwiardinvbits(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if (depth<in){
    if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w]; 
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bt;
}



static inline uint32_t zwiardbitsI(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if (depth>in){
    if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w]; 
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bt;
}

static inline uint32_t zwiardbits2I(uint32_t depth, uint32_t in, uint32_t w){ //global
  uint32_t bt=0, bitrr, tmp;
  if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w];
  
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  if (depth<in){
  bt ^= (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bt;
}

static inline uint32_t Zzwiardinvbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  if (depth>in){
      if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; 
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else {
    bitn = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bitn;
}

static inline uint32_t zzwiardbits2I(uint32_t depth, uint32_t in, uint32_t w){ //global
  uint32_t bitn=0, x, bitrr, tmp, tmpp;
  if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w];
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  if (depth<in){
  bitn ^= (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bitn;
}

static inline uint32_t Nzzwiardbits2I(uint32_t depth, uint32_t in, uint32_t w){ //global
  uint32_t bitn=0, x, bitrr, tmp, tmpp;
  if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w];
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  if (depth<LFSR__[w]){
  bitn ^= (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bitn;
}

static inline uint32_t zzwiardinvbitsI(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bitn=0, bitrr, tmp, tmpp, x;
  if (depth>in){
    if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w]; 
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
    else {
    bitn = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bitn;
}

static inline uint32_t zzwiardbitsI(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  if (depth>in){
    if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w]; 
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else {
  bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bitn;
}

static inline uint32_t Zzwiardbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  if (depth>in){
    if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; 
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else {
  bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bitn;
}


static inline uint32_t zwiardinvbitsI(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if (depth>in){
    if (gate[w].globflag) tmp=binroute[count][w]|binary[w]; else tmp=gate[w].theroute; // was tmp=binroute[count][w]|binary[w]; 
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bt;
}



/*
*that ghost or double can also be generator and function - own feedback and loopback - like the GSR and maybe could replace it ???????what_means*
*what this means: that we associate each SR with a GSR function*
*/

// TODO:   gate[wh].strobed=1; in all strobe functions including speeds...



/// new functions for prob - comparator
/*
static inline uint32_t comp(uint32_t depth, uint32_t in, uint32_t wh){
  if (depth>in) return 1;
  else return 0;
}
*/

// ... retest slur - how? set as 0 - if changed change speed - DONE // works
/*
void SR_geo_outer_testslur0(uint32_t w){  
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=0;// speed
  gate[w].matrix[13]=CVL[w]; //
  gate[w].inner=SR_geo_inner_fixed;
}
}
  
void SR_geo_outer_testslur(uint32_t w){  
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[13]=CVL[w]; //
  gate[w].inner=SR_geo_inner_fixed;
}
}

void SR_geo_outer_testslur1(uint32_t w){ // gappy  
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac 
  gate[w].matrix[13]=CVL[w]; //
  gate[w].inner=SR_geo_inner_fixed;
}
}
*/

///////////////// MATRIXP

/// matrixp ops to port
// 11/8 - trial but we need extra pointers for the CVs so can attach and detach - extra work and matrix... dual matrices for pointers and values
void SR_geomantic_outer1attach(uint32_t w){ 
  // eg.
  gate[w].matrixp[0]=&CVL[w];
  gate[w].matrix[0]=CVL[w];// 5 bits is 32 //2 bits //speedFUNC // or can be // gate[w].matrix[0]=*gate[w].matrixp[0];
  // but other values are not>>7 so should that not be shifted to interpreter
  // can also be like: gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac+CVL[w])&4095
  // or gate[w].matrix[10]=(*bitfromsd[xxx])(blah)
}

// so this would pair with: 
void SR_geomantic_outer1detach(uint32_t w){  // is not really a detach
  gate[w].matrix[0]=*gate[w].matrixp[0]; // if we want live value or don't set it/just ignore it for last value // and if is not set?
  // or we can say set gate[w].matrix[0]=CVL[w] temporarily; or a fixed value...
}

//// TRIAL2 - moving gaps if we have some kind of binary matrix - or ternary // how? - trial this possible copy in!?
//// but can this be more elegant? we change single set of matrices (could also be inside gate[w] then is back to older matrix idea...
//// but could be 2 dimensions

uint32_t fixedvalues[4][15]={ //  values - but x value means no change... say 4096 
  {0},
};

// do we need this? - add extras for dactype, dacpar 
uint32_t *fixedmatrix[4][15]={ // for tests below but is just one matrix and we need multiples... 3d array - do we need as 3d?
  {&CVL[0], &gate[0].matrix[1], &fixedvalues[0][2]}, // &gate[0].matrix[1] - which would keep it the same - examples here...
}; 

// add in LFSR but that is many bits - or reduce bitsDONE
uint32_t *fixedvars[4][20]={ // 
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &Gshift_[8], &LFSR__[0], &LFSR__[1], &LFSR__[2], &LFSR__[3]},
};

static inline void setgap(uint32_t wh, uint32_t which){
  fixedmatrix[wh][which]=&gate[wh].matrix[which]; // stays how it was... so that is a gap 
}

static inline void setgapz(uint32_t wh, uint32_t which){ // new version which keeps ghost also why we need extra step of above, also doesn't set gap twice
  static uint32_t oldgap[4]={0,0,0,0};
  if (which!=oldgap[wh]){
    gate[wh].matrixp[oldgap[wh]]=gate[wh].matrixpG[oldgap[wh]];//    // TODO/TEST: filling in old gaps - something in there to progress from!
    gate[wh].matrixpG[which]=gate[wh].matrixp[which]; 
    gate[wh].matrixp[which]=&gate[wh].matrix[which];
  }
  oldgap[wh]=which;
}

static inline void setfixed(uint32_t wh, uint32_t which, uint32_t val){
  fixedvalues[wh][which]=val; 
  fixedmatrix[wh][which]=&fixedvalues[wh][which]; 
}

static inline void setfixedz(uint32_t wh, uint32_t which, uint32_t val){
  fixedvalues[wh][which]=val; 
  gate[wh].matrixp[which]=&fixedvalues[wh][which]; 
}

static inline void setvar(uint32_t wh, uint32_t which, uint32_t val){ // set to variable such as CV, CVL etc...
  fixedmatrix[wh][which]=fixedvars[wh][which];
}

static inline void setvarz(uint32_t wh, uint32_t which, uint32_t val){ // set to variable such as CV, CVL etc...
  gate[wh].matrixp[which]=fixedvars[wh][which];
}

static inline void setvargapz(uint32_t wh, uint32_t which){ // new version which keeps ghost also why we need extra step of above, also doesn't set gap twice
  static uint32_t oldgap[4]={0,0,0,0};
  if (which!=oldgap[wh]){
    gate[wh].matrixp[oldgap[wh]]=gate[wh].matrixpG[oldgap[wh]];//    // TODO/TEST: filling in old gaps - something in there to progress from!
    gate[wh].matrixpG[which]=gate[wh].matrixp[which]; 
    gate[wh].matrixp[which]=fixedvars[wh][which];
  }
  oldgap[wh]=which;
}

// question is if we need fixedmatrix or just set matrixp to fixedvalues if needed - for the gap
// moving gaps - or SR as gaps over... what is the gap the leftover
// gate[wh].matrixp[which]=&gate[wh].matrix[which]; // old value

// but for gap do we not need to retain what was there so like gate[wh].matrixpG - ghost?

void SR_geomantic_matrixcopy(uint32_t w){
  uint32_t x, y;
  //  gate[w].matrix[x]= // can be a fixed value, CVL[w], &CVL[w]/matrixp, or unchanged gap
  // so we can make gaps in matrices by setting eg.
  setgap(1,0);
  setfixed(0,0,0);
  
  for (x=0;x<15;x++){
    gate[w].matrixp[x]=fixedmatrix[w][x]; 
    gate[w].matrix[x]=(*gate[w].matrixp[x]); // how we deal with fixed values?
  }
  // set gate[w].inner
}

void SR_geomantic_matrixcopyz(uint32_t w){
  uint32_t x, y;
  //  gate[w].matrix[x]= // can be a fixed value, CVL[w], &CVL[w]/matrixp, or unchanged gap
  // so we can make gaps in matrices by setting eg.
  setgapz(1,0); // but do not set old gap - in gap
  setfixedz(0,0,0);
  
  for (x=0;x<15;x++){
    gate[w].matrix[x]=(*gate[w].matrixp[x]); // how we deal with fixed values?
  }
  // set gate[w].inner
}


//- phase out use of this one
//uint32_t (*probf[14])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, ones, zinvprobbits, zprobbits, zsprobbits, strobe, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, comp, ztogglebits, ztogglebitssh, zownprobbits, zownGprobbits}; // prob functions and what these can be: eg. ones always selects alt - add other bit ops, changed binrouts to non-shift // testings!


// not to use
uint32_t unused[32]={1,0,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,1,1,0, 0,0,0,0}; // for strobes

// not to use...//
uint32_t (*speedfromnew[46])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, spdfrac, spdfrac4, spdfracdac3, spdfracend, ztogglebits, ztogglebitssh, clksrG, clksr, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zprobbits, zinvprobbits, zsprobbits, zTMsimplebits, osceq, zosc1bits, zonebits, zonebitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zbinrouteSRbits, zwiardbits, zwiardinvbits, zjusttail, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob3_nosh, binroutfixed_prob4_nosh};  



// DEPRECATE bitfromsd
//uint32_t (*bitfromsd[98])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutor, binroutAND0, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitspp, zsuccbitsI, zsuccbitsIpp, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4,  viennabits, tailbits, flipflop, flipflopandroute, flipflopI, zjusttail, zcopyGSR, zcopyGSR_s, ztogglebitssh, ztogglebits, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitsnos, tailbitsI, tailbitswithd, tailbitsIwithd, tailbitsInos, tailbitswithdnos, tailbitsIwithdnos, binroutesel0, binroutesel1, binroutesel2, binroutesel3, binroutesel4, binroutfixedmy, binroutfixedmyreset, binroutmybumpS, binroutmycv, binroutmybumpbit, binroutmybumpbitt, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3};

//uint32_t interpfromnew[32]={0,1,1,0,0,0,0,0,0,0,0,0,0,0}; // TODO match with speedfromnew and make more


//uint32_t interpfromnostrobenoend[32]={1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}; // TODO match with speedfromnostrobe


// can't include itself in nosh at end so this one is for modeC - geoC
/*
uint32_t (*speedfromnostrobenoend[34])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zinvprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob4_nosh, zSRNbits, zprobbits, zsprobbits}; // 2x spdfrac for interpoll
*/



// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
// towards generic rungler
void SR_geomantic_outer_rung1(uint32_t w){ 
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  gate[w].matrix[0]=6<<7; // 6=spdfracdac3 4=spdfrac4
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; 
  gate[w].matrix[2]=CVL[w];//gate[dacfrom[daccount][w]].dac; 
  gate[w].matrix[3]=66<<7; //flipflop
  // would be nice to have full speed outer of binroute and inner is flipflop
  // now with 2 arrays as we have >>7 TODO!
  gate[w].inner=SR_geomantic_innernoadcsplitbinr;
}




//SRRglobalbumpcv, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalsync, SRRglobalorder, SRRglobalbumpS

  //

////////////////////////////////////////////////////////////////////////////////
//INNERS --- (before OUTER as we point to them)
////////////////////////////////////////////////////////////////////////////////

// leave details such as interpol etc out so we can just try minimal and fill in details 
// divide as adc/nonadc // this is our basic PROTOTYPE TODO
void SR_geomantic_inner(uint32_t w){  // no prob
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innerS(uint32_t w){  // no prob // also to divide as to adc/no adc
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromstrobe[gate[w].matrix[0]>>7])(0, 0, w)){ // speedfunc - but strobes use no params so matrix 1 and 2 are freed - assign from external
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); 
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innerxorS(uint32_t w){  // no prob // xor strobe
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ( (*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w) ^ gate[w].trigger){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innerorS(uint32_t w){  // no prob // OR strobe
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ( (*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w) | gate[w].trigger){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innertestt(uint32_t w){  // test expetcbits
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    bitn^=(*expetcbits[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innernoadcp(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if ((*probf[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn^=(*bitfromsd[gate[w].matrix[12]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geomantic_inneradc(uint32_t w){  // no prob - but this should be done in outers
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innernoadc(uint32_t w){  // no prob
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


// new version with prob on outside/bitn
void SR_geomantic_innernadcp(uint32_t w){  // both adc and no adc
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if (w==0){ // real ADC - TESTY - how we will handle adc across all - maybe remove
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    if ((*probf[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn^=(*bitfromsd[gate[w].matrix[12]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}



////////////////////////////////////////////////////////////////////////////////
//OUTERS
////////////////////////////////////////////////////////////////////////////////

//what we can use in outer modes:  &nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[x], &CVL[x], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[x], &param[x], &Gshift_[8] // TAIL!

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar
void SR_geomantic_outer(uint32_t w){  // do as array of functions // keep this as works oddly with default 3 bitfunc=2 which is binroutfixed
  gate[w].matrix[0]=CVL[w];// 5 bits is 32 //2 bits //speedFUNC
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //???
  gate[w].matrix[2]=CVL[w];//gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[4]=CVL[w]; // unused in case2: binroutfixed // but used by altfunc ???
  gate[w].matrix[6]=CVL[w]; //length
  gate[w].matrix[10]=CVL[w];
  // rest is unchanged but we need to set/reset a default - so we will have a reset function
  //  if (w==0) { // set adc in adcfromsd
  gate[w].matrix[8]=CVL[w]; // was 4095- but we shift that to the ADC

  gate[w].inner=SR_geomantic_inner;
}  

void SR_geomantic_outerS0(uint32_t w){  // sets to 0//plain strobe // not to use // or use only with prob
  gate[w].matrix[0]=0;// eg. 1<<7 // CVL[w];// 5 bits is 32 //2 bits //speedFUNC - this is fixed here...
  //  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  //  gate[w].matrix[2]=CVL[w];//gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[4]=CV[w]; // 
  gate[w].matrix[6]=CVL[w]; //length
  gate[w].matrix[10]=CVL[w];
  // rest is unchanged but we need to set/reset a default - so we will have a reset function
  //  if (w==0) { // set adc in adcfromsd
  gate[w].matrix[8]=CVL[w]; // was 4095- but we shift that to the ADC

  gate[w].inner=SR_geomantic_innerS;
}  


// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
// 8/8/2022 testing strobe and fake pulses/normed pulses in caput000.c
void SR_geomantic_outer_test(uint32_t w){  // set up so we can test different functions eg. now try different speedfuncs
  if (gate[w].changed==0) { // 1=change 0= no change

    if (unused[gate[w].matrix[0]]) {
    gate[w].matrix[9]=3<<7; // probbits as we can now use CV
    gate[w].matrix[10]=CV[w];
    gate[w].matrix[12]=8<<7; // altfuncindex
  }

    gate[w].matrix[0]=3<<7;// 0 was strobe // CVL[w]>>7;// 5 bits is 32 //2 bits //speedFUNC
    gate[w].matrix[1]=CV[w];//
    gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
    gate[w].matrix[3]=2<<7; // fixed route
    //  gate[w].matrix[4]=CVL[w]; // unused in case2: bintroutfixed // but used by altfunc
    gate[w].matrix[6]=CVL[w]; //length
    gate[w].matrix[8]=CVL[w]; // length for adc same as
    //  gate[w].matrix[10]=CVL[w];
    // rest is unchanged but we need to set/reset a default - so we will have a reset function
    //  if (w==0) { // set adc in adcfromsd
    //  gate[w].matrix[8]=CVL[w]; // was 4095- but we shift that to the ADC

    gate[w].inner=SR_geomantic_innernoadcp; // prob one
    }
}  

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
void SR_geomantic_outer_testT1(uint32_t w){  // to start to check transition between fixed and unfixed. so this fixes say speedfunc. but is bitn
  
  if (gate[w].changed==0) { // 1=change 0= no change
    gate[w].matrix[0]=CVL[w];// 5 bits is 32 //2 bits //speedFUNC
    
    if (unused[gate[w].matrix[0]]) {
      gate[w].matrix[9]=3<<7; // probbits as we can use CV
      gate[w].matrix[10]=CV[w];
      gate[w].matrix[12]=8<<7; // altfuncindex
      gate[w].inner=SR_geomantic_innernoadcp; // prob one
  }
  else  gate[w].inner=SR_geomantic_innernoadc; // no prob
  
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[3]=2<<7; // fixed route/binrout
  //  gate[w].matrix[4]=CVL[w]; // unused in case2: bintroutfixed // but used by altfunc
  gate[w].matrix[6]=CVL[w]; //length
    }
}  

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
void SR_geomantic_outer_testT2(uint32_t w){  // to start to check transition between fixed and unfixed. this one doesn't set 0/speedmode
  if (gate[w].changed==0) { // 1=change 0= no change

    gate[w].matrix[10]=CV[w]; // we keep this for probcv (if we have free Cv left over) but prob/index is set elsewhere and function...
    
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[3]=2<<7; // fixed route/binrout
  //  gate[w].matrix[4]=CVL[w]; // unused in case2: bintroutfixed // but used by altfunc
  gate[w].matrix[6]=CVL[w]; //length

  gate[w].inner=SR_geomantic_innernoadcp; // prob one
    }
}  

void SR_geomantic_outer_testT3(uint32_t w){  // to start to check transition between fixed and unfixed. set speedmode to... ONEs
  if (gate[w].changed==0) { // 1=change 0= no change
    gate[w].matrix[0]=7<<7; // ones for test
    gate[w].matrix[10]=CV[w]; // we keep this for probcv (if we have free Cv left over) but prob/index is set elsewhere and function...
    
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[3]=2<<7; // fixed route/binrout
  //  gate[w].matrix[4]=CVL[w]; // unused in case2: bintroutfixed // but used by altfunc
  gate[w].matrix[6]=CVL[w]; //length

  gate[w].inner=SR_geomantic_innernoadcp; // prob one
    }
}  

/* try to define basic outers for:
- basic binroute/pass in: binr below...

- classic TM and other SR - prob modes: - binr with probability// fixed length

- runglers

[later: which ones still resetr, and/or set all params/cvs with no gaps, and distinguish cv and no cv]
*/

void SR_geomantic_outer_binr(uint32_t w){ // test just simplest binroute in/spdfrac // with NO RESETR
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  ///  RESETR; // but could this not be on changed! only? - put in resetr one
  
  gate[w].matrix[0]=3<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=2<<7; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[9]=0<<7; // no probs

  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  
  gate[w].inner=SR_geomantic_inner;
}

void SR_geomantic_outer_and(uint32_t w){  // TESTING! now test with binroutAND0! =
  // what is appropriate speed function????
  gate[w].matrix[0]=3<<7;// eg. 1<<7 // CVL[w];// 5 bits is 32 //2 bits //speedFUNC - this is fixed here...
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  //  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[3]=4<<7; // fixed route was 2 - now trial new AND with CVL // AND1 doesn't use depth so we can have length
  gate[w].matrix[4]=CVL[w]; //  just keep for tests
   gate[w].matrix[6]=CVL[w]; //length
  //  gate[w].matrix[10]=CVL[w];
  // rest is unchanged but we need to set/reset a default - so we will have a reset function
  //  if (w==0) { // set adc in adcfromsd
  //  gate[w].matrix[8]=CVL[w]; // was 4095minus but we shift that to the ADC

  gate[w].inner=SR_geomantic_inner;
}  

void SR_geomantic_outer_OSC(uint32_t w){  // TESTING! for trials with 
  // what is appropriate speed function????
  gate[w].matrix[0]=3<<7;// eg. 1<<7 // CVL[w];// 5 bits is 32 //2 bits //speedFUNC - this is fixed here...
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  //  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[3]=22<<7; // OSCillator is 22 // TRY!
   gate[w].matrix[4]=CVL[w]; // 
  //    gate[w].matrix[6]=CVL[w]; //length
  //  gate[w].matrix[10]=CVL[w];
  // rest is unchanged but we need to set/reset a default - so we will have a reset function
  //  if (w==0) { // set adc in adcfromsd
  //  gate[w].matrix[8]=CVL[w]; // was 4095minus but we shift that to the ADC

  gate[w].inner=SR_geomantic_inner;
}  

void SR_geomantic_outer_binrRESETR(uint32_t w){ // test just simplest binroute in/spdfrac // with RESETR
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  ///  RESETR; // but could this not be on changed! only? - put in resetr one
  
  gate[w].matrix[0]=3<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=2<<7; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[9]=0<<7; // no probs

  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  
  gate[w].inner=SR_geomantic_inner;
}


void SR_geomantic_outer_testtS(uint32_t w){ // TESTexpetcbits // strobe so we can use CV and CVL
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  ///  RESETR; // but could this not be on changed! only? - put in resetr one
  
  gate[w].matrix[0]=0<<7; // spdfrac //trial as strobe
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=CVL[w];//1<<7; // testing: 0-10 ok, test each further
  gate[w].matrix[4]=CV[w]; 
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[9]=0<<7; // no probs

  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  
  gate[w].inner=SR_geomantic_innertestt;
}


// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
void SR_geomantic_outer_binrp(uint32_t w){ // binr with probability of: cycle // what are other prob modes we have
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  gate[w].matrix[0]=3<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=5<<7; // binroutfixed_prob1
  gate[w].matrix[4]=CVL[w]; // prob builtin

  gate[w].inner=SR_geomantic_inner;
}

void SR_geomantic_outer_binrpp(uint32_t w){ // binr with probability of: cycle // more flexible as "real" probability - what those gaps could be?
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  gate[w].matrix[0]=3<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=3<<7; // binroutfixed
  //  gate[w].matrix[4]=CVL[w]; // prob
  gate[w].matrix[9]=3<<7; // probbits as we can use CV
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac+CVL[w])&4095; // detach this too // or rather one new form of re-attachment - we can also use value functions here!! // another layer of attach/detach
  gate[w].matrix[12]=4<<7; // altfuncindex - now for justcycle // no cv needed
  
  gate[w].inner=SR_geomantic_innernoadcp;
}


/* how to define a rungler as depends on routing - options: rungler for route as we have it, rungler with specific sets of modes, generic rungler (what did we have for that?)

see rungler.h

x: genX, spdfrom z + own offset // optional route in from zz
y: genX, spdfrom z + own offset // optional route in from same zz

z: route in from x, spd from y + own offset // optional route in from zz- OUT?, it cycles
zz: tail. process of z and feedback to x, y or z.

N- spdfrom C routefrom - optional z/zz - type of gen/adc
L-         C           - optional z/zz - type of gen/adc
C-         NorL        - NorL-dep on spdfrom/cycle? - type of dac
R-         CV/C,NorL?  - C,NorL/ - type of processor/tail

spdfrom=2,2,0,? // for basic binroutes TODO: match all counts and routes but these can also slip

generic is: binr/function, spdfrom/shared or from someone we give spd to! recipricol - spdfrom and route matching and that's it

*/


// try most basic oscbits and fixed

// from rungler.h
/* // 1248NLCR
uint32_t otherrungspd[2][4]={
{2,1,2,1}, // L,N,L,N
{8,8,8,2} //  R<R<R,L
};

uint32_t otherrungroute[2][4]={
{4,8,8,2},
{2,4,1,4}
};

// translate to our new scheme - we have  inner rung option above // but we need to gain from this translation
void SRrunggenericbits(uint8_t w){  
  HEADNADA; //
  tmp=(CVL[w]>>6)&3;
  if (binroutebitsI(otherrungspd[tmp&1][w]<<8,w) | gate[w].trigger){ // 2<<8 is L // SPEED
      GSHIFT_;
      bitn=binroutebitsI(otherrungroute[tmp>>1][w]<<8,w); // bits from N // FUNCTION - fixed routes from rungroute
      bitn^=(*abstractbitstreamsI[CVL[w]>>8])(CV[w],w);  // option for adc in here or? // top 4 bits - includes also binroutebits ?? ALT function
      BITN_AND_OUTVINT_;
      }
}
*/

void SR_geomantic_outer_bitchangeS(uint32_t w){ // test just simplest binroute in/spdfrac
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  gate[w].matrix[0]=0<<7; // strobe
  //  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=CVL[w]; // 5 bits for first 32 
  gate[w].matrix[4]=CV[w]; 
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[7]=1; //adcfromsd zadcx
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as
  //  gate[w].matrix[9]=0; // no probs

  gate[w].inner=SR_geomantic_inner;
}

// new ORs and XORs also in new_geo

void SR_geomantic_innerxor(uint32_t w){  // xor with fixed route - but we don't track cv
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ( (*speedfromcvforxor[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w) ^ speedfromforxor[0](0,0,w) ){ // speedfunc xor with fromforxor->binroutfixed...
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); // as this can also be strobe
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// {0speedfrom/indexbinroutAND0, , 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}


void SR_geomantic_outerxor(uint32_t w){  
  // what is appropriate speed function????
  gate[w].matrix[0]=2<<7;// eg. 1<<7 // CVL[w];// 5 bits is 32 //2 bits //speedFUNC - this is fixed here...
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  gate[w].matrix[3]=4<<7; // fixed route was 2 - now trial new AND with CVL
  // gate[w].matrix[4]=CVL[w]; // 
    gate[w].matrix[6]=CVL[w]; //length
  //  gate[w].matrix[10]=CVL[w];
  // rest is unchanged but we need to set/reset a default - so we will have a reset function
  //  if (w==0) { // set adc in adcfromsd
  //  gate[w].matrix[8]=CVL[w]; // was 4095minus but we shift that to the ADC

  gate[w].inner=SR_geomantic_innerxor;
}  

/*
void SR_geomantic_outerxor(uint32_t w){ // test just simplest binroute in/spdfrac // with NO RESETR
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  ///  RESETR; // but could this not be on changed! only? - put in resetr one
  
  gate[w].matrix[0]=4<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=2<<7; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[9]=0<<7; // no probs

  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  
  gate[w].inner=SR_geomantic_innerxor;
  }*/




// from new_geomantic.c

void nSR_geomantic_innernoadcp(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if ((*probf[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn^=(*bitfromsd[gate[w].matrix[12]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// this is our generic one... - make changes for adc/dac
void nSR_geomantic_outer_test(uint32_t w){  // set up so we can test different functions eg. now try different speedfuncs
  if (gate[w].changed==0) { // 1=change 0= no change

    if (unused[gate[w].matrix[0]]) {
    gate[w].matrix[9]=3<<7; // probbits as we can now use CV
    gate[w].matrix[10]=CV[w];
    gate[w].matrix[12]=8<<7; // altfuncindex
  }

    gate[w].matrix[0]=3<<7;// 0 was strobe // CVL[w]>>7;// 5 bits is 32 //2 bits //speedFUNC
    gate[w].matrix[1]=CV[w];//
    gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
    gate[w].matrix[3]=2<<7; // fixed route
    //  gate[w].matrix[4]=CVL[w]; // unused in case2: bintroutfixed // but used by altfunc
    gate[w].matrix[6]=CVL[w]; //length
    gate[w].matrix[8]=CVL[w]; // length for adc same as
    //  gate[w].matrix[10]=CVL[w];
    // rest is unchanged but we need to set/reset a default - so we will have a reset function
    //  if (w==0) { // set adc in adcfromsd
    //  gate[w].matrix[8]=CVL[w]; // was 4095- but we shift that to the ADC

    gate[w].inner=nSR_geomantic_innernoadcp; // prob one
    }
}

// trial for xor of speeds:
// we can xor: strobes with any non-strobe which uses cv, fixedroutes with any non-route which uses cv - so 2 sets - how we fix each/// or stay fixed...
// first case is already in: SR_geomantic_innerxorS
// second case... speedfromfixedforxor uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift}; // unsued so far

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ADC
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// reserve basic one for top ADC, modeN 
void nSR_geomantic_inner_adc(uint32_t w){  // no prob - but this should be done in outers
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void nSR_geomantic_outer_adc(uint32_t w){ // spdfrac and adc in - adc is set in 000 as default...
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  ///  RESETR; // but could this not be on changed! only? - put in resetr one
  
  gate[w].matrix[0]=3<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=2<<7; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[9]=0<<7; // no probs

  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  
  gate[w].inner=nSR_geomantic_inner_adc;
}



// 10/12/21 - changes to SR in place now for draftspeed.c
static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator[4]={0}, oldvalue[4]={0};
  static int32_t k[4]={0};
  static uint32_t lastbt[4]={0,0,0,0}; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  //  static uint8_t lc=0;
  static uint32_t toggle[4]={0,0,0,0};
  uint32_t bt=0;
  int32_t tmp=0;
  static float integratorf=0.0, oldvaluef=0.0; // was not static
  float inb; // shared across all adc
  
  switch(type){    

  default:
    bt=0;
    break;
    // TODO: all to new scheme for adc_buffer
  case 0: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCone;
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 1: // equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      ADCtwo;
      k[reg]=k[reg]/divy[length];
      n[reg]=0;
    }
    if (k[reg]!=0) {
      bt=1;
      k[reg]--;
    }
    else bt=0;
    n[reg]++;    
    break;

    /*
  case 2: // variations on one bit audio - also phasey
    //  n[reg]++;
	//	if (n[reg]>48) { // try changing value?
	//	  n[reg]=0;
    k[reg]=(adc_buffer[12]); // from 0 to 4095 but where is the middle? - also we do nothing here with length
    //	}
    integrator[reg]+=(k[reg]-oldvalue[reg]);
   if(integrator[reg]>2048)
  {
     oldvalue[reg]=4095;
     bt=1;
  }
   else
   {
      oldvalue[reg]=0;
      bt=0;
   }   
   break;    
    */

  case 2: // try with float but this is the same with phasings - and we need to make independent! TODO! sigma-delta
    ADCtwo;
    //    inb=(((float)k[reg])/2048.0f)-1.0f; // from 0 to 4095 but where is the middle? 2048
    k[reg]=k[reg]-2048;
    inb=(((float)k[reg])/2047.0f); // from 0 to 4095 but where is the middle? 2048

    integratorf+=(inb-oldvaluef);
    if(integratorf>0.0f)
      {
	oldvaluef=1.0f;
	bt=1;
      }
    else
      {
	oldvaluef=-1.0f;
	bt=0;
      }   
    break;    
   
  case 3: // basic sequential length as in 0 but with padding of zeroes if >11 bits 
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	ADCone; 	//	k[reg]=(adc_buffer[12])>>(11-length);
	n[reg]=length;
      }
      else {
	ADCtwo;
	k[reg]=k[reg]<<(length-11); // 21/3 - pad out
	n[reg]=length; // padded with zeroes then - 14/3/2022
      }
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 4:  // special case for spaced bit entry depending on length
    // now with route in!
    *SR &=spacmask[length]; //cleared
    ADCtwo;
    k[reg]=k[reg]>>8; // we want 4 bits
    *SR+=(k[reg]&1)+((k[reg]&2)<<spacc[length][reg])+((k[reg]&4)<<spacc[length][1])+((k[reg]&8)<<spacc[length][2]);
    // testing route in of bits from gate[0].Gshift_[regg] or rather dac feedback
    k[reg]=(gate[regg].dac)>>8; 
    *SR^=(k[reg]&1)+((k[reg]&2)<<spacc[length][reg])+((k[reg]&4)<<spacc[length][1])+((k[reg]&8)<<spacc[length][2]);    
    // 4 bits goes in
    // no bt return
    bt=0;
    break;   
    
  case 5: // basic sequential length of 12 bits cycling in 
    if (n[reg]<0) { // 12 bits
      ADCtwo;
      n[reg]=11;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 6: // basic sequential length of 
    if (n[reg]<0) { // 8 bits
      ADCtwo;
      k[reg]=k[reg]>>4;
      n[reg]=7;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 7: // basic sequential length of
    if (n[reg]<0) { // 4 bits
      ADCtwo;
      k[reg]=(k[reg]>>6); // 4 bits - but works best 6 bits
      //      if (k[reg]==0) k[reg]=3;
      //      else k[reg]=0;
      //      k[reg]=0;
      n[reg]=3;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    //    if (rand()%128==1) bt=0;
    //    else bt=1;
    n[reg]--;    
    break;
    
  case 8: // try keep cycling adc with new entry on toggle or strobe STROBE
    if (strobe) toggle[reg]^=1;
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	if (toggle[reg]) {
	    ADCone;
	  }
      }
      else {
	if (toggle[reg]) {
	    ADCtwo;
	  }
      }
	n[reg]=length; // padded with zeroes then - 14/3/2022
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

    
  case 9: //  STROBEnow strobe - was! ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    // testing now for msb out 
    if (strobe) { 
      if (length>11) length=11;
      //      if (n[reg]>length) {
            if (n[reg]<0) {
	      ADCone;
	      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;
      }
    else
      {
	//	bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it - or is always 0
	bt = (gate[reg].shift_>>length) & 0x01; 
      }
    break;

  case 10: // basic sequential length of bits cycling in but zeroed by strobe STROBE
    if (length>11) length=11; //XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    } 
     if (strobe) bt=0;
      else bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 11: // padded case 8    // we accumulate bits onto a ghosted register ** STROBE
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt - but how can we fix that
    //      if (n[reg]>length) {
          if (n[reg]<0) {
	    ADCtwo;
	if (length<12) k[reg]=(k[reg])>>(11-length); 
	else k[reg]=(k[reg])<<(length-11);
	n[reg]=0;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { 
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    //bt=0; // leave orf
    break;
    
  case 12:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa ** STROBE
    if (strobe) toggle[reg]^=1;
      if (n[reg]<0) {
	ADCtwo;
	if (length<12) k[reg]=(k[reg])>>(11-length);
	else k[reg]=(k[reg])<<(length-11);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01;
      if (toggle[reg]) {
    n[reg]--;    
      }
    break;

  case 13:     // we accumulate bits onto a ghosted register STROBE
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { // strobe
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    bt=0;
    break;

  case 14:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa STROBE
    if (strobe) toggle[reg]^=1;

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    }
      if (toggle[reg]) {// strobe
      bt = (k[reg]>>n[reg])&0x01;
      lastbt[reg]=bt;
      }
      else bt=lastbt[reg];
    n[reg]--;    
    break;
    
  case 15:     // 2-we only cycle ADC on strobe/toggle  - or vice versa STROBE
        if (strobe) toggle[reg]^=1;
    if (length>11) length=11; //XXXmax12bits

  if (n[reg]<0) {
    ADCone;
      n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01;

      if (toggle[reg]) {// strobe
    n[reg]--;    
      }
      break;

  case 16: // STROBE: 3-one bit entry STROBE - sigma-delta
    if (strobe) toggle[reg]^=1;
    ADCtwo;
    integrator[reg]+=(k[reg]-oldvalue[reg]);
   if(integrator[reg]>2048)
  {
     oldvalue[reg]=4095;
     bt=1;
  }
   else
   {
      oldvalue[reg]=0;
      bt=0;
   }       
   if (toggle[reg]) {
	lastbt[reg]=bt;
      }
      else bt=lastbt[reg];
   break;

  case 17: // cycling on otherpar length - otherpar is length within length
    otherpar=otherpar&31;
    if (otherpar<3) otherpar=3; //21/3
    
    if (n[reg]>otherpar) {
      ADCtwo;
      if (length<12) {
	ADCshift_[reg]=(k[reg])>>(11-length); 
      }
      else ADCshift_[reg]=(k[reg])<<(length-11);

      n[reg]=0;
    }
    n[reg]++;
    bt=(ADCshift_[reg]>>length)&0x01; // top bit
    ADCshift_[reg]=(ADCshift_[reg]<<1)+bt;
    break;

    // new mode using adc_bits
  case 18: 
    otherpar=otherpar&31; // 5 bits
    if (otherpar<3) otherpar=3;
    bt=adceqbits(otherpar);
    break;

    // new mode tested using adcpadbits
  case 19:  
    // maybe restrict otherpar
    // try with MSB or loads 0s after shift
    // doesn't work if length shorter than otherpar
    otherpar=otherpar&31; // 5 bits
    if (otherpar<3) otherpar=3;
    bt=adcpadbits(otherpar);
    break;
    ///////////////////////////////////////
    
  case 20: // otherpar as comparator - 10 bits standard here // now 12 bits  - OTHERPAR! 12 bits
     bt=0;
     ADCtwo;
     if (k[reg]>(otherpar&4095)) bt=1;
     break;

  case 21:     // use as test for bit match WORKING use length
    bt=adcpadbits(4); // try fix depth here of 4
    tmp=oscbits(otherpar,length);
    bt&=tmp;
    break;    

  case 32:     // use as test for bit match with DAC
    bt=adcpadbits(otherpar); // try fix depth here of 4
    tmp=dacpadbits(otherpar);
    bt^=tmp;
    break;    

     // 22->31 = no ADC IN just LFSR/DAC etc abstract
     
  case 22: // LFSR runs on own SR so not true LFSR - REGG! no param
    bt = ((*SR >> (lfsr_taps[SRlength[regg]][0])) ^ (*SR >> (lfsr_taps[SRlength[regg]][1])) ^ (*SR >> (lfsr_taps[SRlength[regg]][2])) ^ (*SR >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    break;

  case 23:// run true LFSR-ADCshift and output a bit  - REGG!
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
    
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

  case 24: // strobe switches direction of LFSR - REGG!  STROBE
    //      case 7:// run LFSR-ADCshift and output a bit - again if we don't use redirection of regg then ...
    if (strobe) toggle[reg]^=1;
    if (toggle[reg]){
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
    }
    else {
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]>>1)+(bt<<31);
    }
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

    // 25->27 are DAC entry which can go to 0
    
  case 25: // gate[regg].dac seq input 
      if (length>11) length=11;
      if (n[reg]<0) {
	k[reg]=(gate[regg].dac)>>(11-length);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
        
  case 26: // one bit audio input from DAC  - sigma-delta
    k[reg]=gate[regg].dac; // from 0 to 4095 but where is the middle? - also we do nothing here with length
    integrator[reg]+=(k[reg]-oldvalue[reg]);
   if(integrator[reg]>2048)
  {
     oldvalue[reg]=4095;
     bt=1;
  }
   else
   {
      oldvalue[reg]=0;
      bt=0;
   }   
   break;    
   
  case 27: // as 8 - gate[regg].dac seq input     // padded length version ** - REGG!
    if (n[reg]<0) {
      if (length<12) k[reg]=(gate[regg].dac)>>(11-length); 
      else k[reg]=(gate[regg].dac)<<(length-11 );
      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;
    
  case 28: // clkbit as bits in STROBE STROBE
    bt=strobe;
    break;

  case 29:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=0;
       if (nn[reg]>=otherpar) { // so equal bits from 0 / length 0 = 101010
	 n[reg]=0;
       }
       nn[reg]++;
     } // n[reg]
     
     else {
       bt=1;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 30: // osc - 3/12/2021 - 101010 clock at speed - ultrasonic at fastest speeds
    // TODO: but is same more or less as static bit pattern which could be imposed at intervals
    lastbt[reg]^=1;
    bt=lastbt[reg];
    break;

  case 31: // strobe mode for cycling bits a la TM - no input
    //    bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    	bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (strobe){
      bt=!bt;// invert cycling bit
    }
    break;
    /*
  case 32: // In progress  test mode for spaced sequential entry of 12 bits
      if (n[reg]>length) {
	if (length<12) k[reg]=(adc_buffer[12])>>(11-length); // fill so no spacings
	else {
	  // try for reverse
	  k[reg]=(adc_buffer[12]); // below for LSB first so reverse for MSB
	  k[reg]=(k[reg]&0x01) + ((k[reg]&space[length-11][0])<<spaceshift[0][length-11]) + ((k[reg]&space[1][length-11])<<spaceshift[1][length-11]) + \
	    ((k[reg]&space[2][length-11])<<spaceshift[2][length-11]) + ((k[reg]&space[3][length-11])<<spaceshift[3][length-11]) + \
	    ((k[reg]&space[4][length-11])<<spaceshift[4][length-11]) + ((k[reg]&space[5][length-11])<<spaceshift[5][length-11]) + \
	    ((k[reg]&space[6][length-11])<<spaceshift[6][length-11]) + ((k[reg]&space[7][length-11])<<spaceshift[7][length-11]) + \
	    ((k[reg]&space[8][length-11])<<spaceshift[8][length-11]) + ((k[reg]&space[9][length-11])<<spaceshift[9][length-11]) + \
	    ((k[reg]&space[10][length-11])<<spaceshift[10][length-11]) + ((k[reg]&space[11][length-11])<<spaceshift[11][length-11]);
	}
	n[reg]=0;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]++;    
    break;
    */
  case 33: //  was 9 back to ADC - was! ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...    
    // testing now for msb out
    if (((LFSR_[reg] & 4095 ) < otherpar)){
      if (length>11) length=11;
      //      if (n[reg]>length) {
            if (n[reg]<0) {
	      ADCone;
	      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;
      }
    else
      {
	//	bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it or is always 0!
	bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
      }
    break;

  case 34:// swapped // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=1;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=0;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

// prob instead of strobe: 12,13,14,15,16 -> re-work NOW/here in ADC_
//     if (((LFSR_[reg] & 4095 ) < otherpar)){
     
  case 35:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa **
      if (n[reg]<0) {
	ADCtwo;
	if (length<12) k[reg]=(k[reg])>>(11-length);
	else k[reg]=(k[reg])<<(length-11);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01;
     if (((LFSR_[reg] & 4095 ) < otherpar)){
    n[reg]--;    
      }
    break;

  case 36:     // we accumulate bits onto a ghosted register
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

     if (((LFSR_[reg] & 4095 ) < otherpar)){
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    bt=0;
    break;

  case 37:     // 1-we keep on cycling ADC bits but only enter new bit on prob - or vice versa
    if (length>11) length=11; //XXXmax12bits
      if (n[reg]<0) {
	ADCone;
      n[reg]=length;
    }
     if (((LFSR_[reg] & 4095 ) < otherpar)){
      bt = (k[reg]>>n[reg])&0x01;
      lastbt[reg]=bt;
      }
      else bt=lastbt[reg];
    n[reg]--;    
    break;
    
  case 38:     // 2-we only cycle ADC on prob  - or vice versa

    if (length>11) length=11; //XXXmax12bits

  if (n[reg]<0) {
    ADCone;
      n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01;

     if (((LFSR_[reg] & 4095 ) < otherpar)){
    n[reg]--;    
      }
      break;

  case 39: // prob: 3-one bit entry  - sigma-delta
    ADCtwo;
    integrator[reg]+=(k[reg]-oldvalue[reg]);
   if(integrator[reg]>2048)
  {
     oldvalue[reg]=4095;
     bt=1;
  }
   else
   {
      oldvalue[reg]=0;
      bt=0;
   }   

   if (((LFSR_[reg] & 4095 ) < otherpar)){
	lastbt[reg]=bt;
      }
      else bt=lastbt[reg];
   break;

    /////////////////////// add modes

  case 66: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCtwo;
	k[reg]=(k[reg]%otherpar)>>(11-length);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 67: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCtwo;
	tmp=k[reg]+otherpar;
	if (tmp>4095) tmp=0;
	k[reg]=(tmp)>>(11-length); // now we have 12 bits
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 68: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCtwo;
	k[reg]=(k[reg]&otherpar)>>(11-length);
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 71: // dac in equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      k[reg]=(gate[regg].dac); 
      k[reg]=k[reg]/divy[length];
      n[reg]=0;
    }
    if (k[reg]!=0) {
      bt=1;
      k[reg]--;
    }
    else bt=0;
    n[reg]++;    
    break;

  case 72: // dac in basic sequential length as in 0 but with padding if >11 bits **
    // as above but closer to 5
    // also try as MSB - now...
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	k[reg]=(gate[regg].dac)>>(11-length);
	n[reg]=length;
      }
      else {
	//	ADctwo;
	k[reg]=(gate[regg].dac);
	n[reg]=11;
      }
    }
    bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 73:  // dac in special case for spaced bit entry depending on length
    *SR &=spacmask[length]; //cleared
    k[reg]=(gate[regg].dac)>>8; // we want 4 bits
    *SR+=(k[reg]&1)+((k[reg]&2)<<spacc[length][0])+((k[reg]&4)<<spacc[length][1])+((k[reg]&8)<<spacc[length][2]);
    // 4 bits goes in
    // no bt return
    bt=0;
    break;   
    
  case 74: // dac in basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
        ////// full length regardless of len    
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k[reg]=(gate[regg].dac);
	n[reg]=11;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 75: // other dac as comparator 
     bt=0;
     ADCtwo;
     if ((k[reg])>((gate[regg].dac))) bt=1;
     break;

  case 76: // own dac as comparator 
     bt=0;
     ADCtwo;
     if (k[reg]>((gate[reg].dac))) bt=1;
     break;

  case 77:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - DAC- OTHERPAR! 12 bits
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=(gate[regg].dac); // test also as own dac
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=0;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=1;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 78:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - DAC- OWN DAC
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=(gate[regg].dac); // test also as own dac
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=0;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=1;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 79:// swopped as 34 // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - DAC- OTHERPAR! 12 bits
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=(gate[regg].dac); // test also as own dac
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=1;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=0;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 80:// swopped as 34 // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - DAC- OWN DAC
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=(gate[regg].dac); // test also as own dac
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=1;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=0;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 81: // basic 4 bits in
    // try new ADC scheme
      if (n[reg]<0) {
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
	ADC_SoftwareStartConv(ADC1);
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	k[reg]=ADC_GetConversionValue(ADC1)>>8;
	//		k[reg]=1; // testing for a repeated pattern - could be prob of a grab... SR wheel in SR
	n[reg]=3;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
    break;
    
  case 82: // how we could use entry bit as comparator - but then we don't want any binroute
     bt=0;
     tmp = (gate[inroute[count][reg]].Gshift_[reg]>>SRlength[inroute[count][reg]]) & 0x01;
     tmp=tmp<<11; // upto 2048
     ADCtwo;
     if (k[reg]> tmp) bt=1;
     break;
    
  case 1010: // speed bump based on 0 skip bits
      if (length>11) length=11;
      if (n[reg]<0) {
	ADCone;
	n[reg]=length;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;
      n[reg]--;
    break;

    //TRY: cycling bit XOR with --> [DACout from own/other SR vs. comparator=CV/DAC/DAC+CV/CLKCNT???]*

  case 84: // own dac as comparator against DAC+CV
    tmp=gate[reg].dac-(otherpar);
    if (tmp<0) tmp=0;
     bt=0;
     ADCtwo;
     if (k[reg]>tmp) bt=1;
     break;

  case 85: // comp at 2048 middle... is not middle for unipolar - 2000 works
    ADCtwo
      if (k[reg]>2000) bt=1; // was 2048
      else bt=0;
    break;

  case 86: // gate[regg].dac seq input ->     //    TODO: *cut feedback - eg. cut for CV count clk pulses/on off*
    //count clk pulses, compare to CV
    // originally swicthed between dacs but that doesn't work so well without input
    if (strobe) nn[reg]++;
    if (nn[reg]>otherpar){ // range of otherpar?
	nn[reg]=0;
	toggle[reg]^=1;
      }
    // changed 26/2 for instant change
    if (length>11) length=11;
      if (n[reg]<0) {
	//	k[reg]=(gate[regg].dac)>>(11-length); // switch between dac 3 and dac 1
	lastbt[reg]=(gate[3].dac)>>(11-length); // switch between dac 3 and dac 1
	//k[reg]=(gate[1].dac)>>(11-length); // switch between dac 3 and dac 1
	ADCone; // adc
	n[reg]=length;
      }
      if (toggle[reg]) bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      else bt = (lastbt[reg]>>n[reg])&0x01; // this means that MSB comes out first
      //      bt = (k[reg]>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 87: // basic 4 bits in - grab into SR on STROBE 
    // changed for toggle 26/2
    if (strobe) toggle[reg]^=1;
 
    if (n[reg]<0) {  // can also be if (n[reg]<0 || toggle[reg])
      if (toggle[reg]){
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
	ADC_SoftwareStartConv(ADC1);
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	k[reg]=ADC_GetConversionValue(ADC1)>>8;
      }
	n[reg]=3;
      }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
    break;

  case 88: // - if CV>DAC - entry of new bit from [ADC, route or cycle] XOR cycle/route etc... - use what for this choice of route - detached
    // see modeN.h
     bt=0;
     ADCtwo;
     if ((k[reg])>((gate[regg].dac))) { 
       if (otherpar==255){ // then we 4 bits in of adc
      if (n[reg]<0) {
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
	ADC_SoftwareStartConv(ADC1);
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	k[reg]=ADC_GetConversionValue(ADC1)>>8;
	n[reg]=3;
    }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
       }
	 else       bt=otherpar;
     }
     break;

  case 89: // kind of impulses no ADC in - uses strobe so noINT - must be DETACHED...
    if (strobe) bt=onebits(otherpar,reg);
    else bt=onebits(0,reg);
    break;

  case 90: // trial for 0v = 0 bits - equiv energy
        if (n[reg]>length) {
      ADCtwo;
      tmp=k[reg]-2048;
      k[reg]=abs(tmp);
      k[reg]=k[reg]/divy[length];
      n[reg]=0;
    }
    if (k[reg]!=0) {
      bt=1;
      k[reg]--;
    }
    else bt=0;
    n[reg]++;    
    break;

  case 91:     // use as test for bit match with DAC
    bt=adcpadbits(4); // try fix depth here of 4
    tmp=dacpadbits(otherpar);
    if (tmp) 	bt = (gate[reg].Gshift_[reg]>>length) & 0x01; //bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it - or is always 0 
    break;    

    // different encodings but all are so far 12 bits in and ignoring depth and length, other encodings
    
  case 92: // basic sequential length of 12 bits cycling in with subtract of otherpar (max 12 bits)
    if (n[reg]<0) { // 12 bits
      ADCtwo;
      tmp=k[reg]-otherpar;
      if (tmp<0) k[reg]=0;
      else k[reg]=tmp;
      n[reg]=11;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 93: // basic sequential length of x bits cycling in with -2048
    if (n[reg]<0) { // trial 8 bits which is really 7 bits
      ADCtwo;
      k[reg]=k[reg]>>4;// 8 bits
      tmp=k[reg]-127;
      if (tmp<0) k[reg]=0;
      else k[reg]=tmp;
      //      k[reg]=abs(tmp);
      n[reg]=6;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 94: // basic sequential length of 12 bits cycling in with -2048 // abs
    if (n[reg]<0) { 
      ADCtwo;
      k[reg]=k[reg]>>7;
      tmp=k[reg]-15;
      k[reg]=abs(tmp);
      n[reg]=3;
    }
    bt = (k[reg]>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 95: // basic 4 bits pattern in - grab into SR on STROBE
    // but we need different patterns - detach
    //    if (strobe) toggle[reg]=1;
 
    if (n[reg]<0 || strobe){
      if (strobe){
	otherpar=otherpar&15;
	k[reg]=pattern[otherpar];
	//	k[reg]=0b1010;
      }
	n[reg]=3;
      }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
    break;

  case 96: // trial of straight x bits in on strobe/... 4 bits
    if (strobe){
      // mask in
      *SR&=invmasky[3]; // clear length bits
      ADCtwo;
      *SR+=k[reg]>>8; // top 4 bits
    } // no bt
    bt=0;
    break;    

  case 97: // 4 bits straight 
    *SR&=invmasky[3]; // clear length bits
    ADCtwo;
    *SR+=k[reg]>>8; // top 4 bits
    bt=0;
    break;    

  case 98: // 4 bits straight - toggle selects adc or dac...
    if (strobe) toggle[reg]^=1;
    *SR&=invmasky[3]; // clear length bits
    
    if (toggle[reg]){
    ADCtwo;
    *SR+=k[reg]>>8; // top 4 bits
    }
    else {
      *SR+=gate[regg].dac>>8; // top 4 bits
    }
    bt=0;
    break;    

  case 99: // switch SR on toggle between adc and dac - 4 bits
    if (strobe) toggle[reg]^=1;
     if (n[reg]<0){
      if (toggle[reg]){
	ADCtwo;
	k[reg]=k[reg]>>8; // 4 bits
      }
      else {
	k[reg]=gate[regg].dac>>8; // 4 bits
      }
	n[reg]=3;
      }
      bt = (k[reg]>>n[reg])&0x01; // this means that MSB comes out first
      n[reg]--;    
    break;

  case 100: // sliding splice in of x bits at position y on strobe - as in 96
    // so either 2 params or we just slide in 4 bits - trial here - otherpar and we don't use length
    if (strobe){
      // mask in
      *SR&=movemasky[otherpar]; // clear length bits
      ADCtwo;
      *SR+=(k[reg]>>8)<<otherpar; // top 4 bits - we can also try other logops in and obviously no mask in those cases
    } // no bt
    bt=0;
    break;    

    // variations on this - and can also be used for other SRs
    // variations: trial with adc bits in also (AND as in addition)-, in modeN with/without route, dac+otherpar, just dac, all comp options
  case 101: // exact Turing machine - add otherpar and ADC and compare noise to this for loop or not
    ADCtwo;
    k[reg]+=otherpar; // CVL is also knob+CV so we have 2 CVs
    if (k[reg]>4095) k[reg]=4095;
    //    bt=(*SR>>length)& 0x01;
    bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (k[reg]>(LFSR_[reg]&4095)) bt=!bt;
    break;

  case 102: // with bits in from adc - exact Turing machine - add otherpar and ADC and compare noise to this for loop or not //***
    // bits OR/add in can be before or after the inversion
    //    bt=(*SR>>length)& 0x01;
    bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (otherpar>(LFSR_[reg]&4095)) bt=!bt;
    bt|=adcpadbits(length);
    break;

    // inv of incomings
  case 103: // with bits in from adc - exact Turing machine - add otherpar and ADC and compare noise to this for loop or not
    ADCtwo;
    k[reg]+=otherpar; // CVL is also knob+CV so we have 2 CVs
    // bits AND/add in can be before or after the inversion
    bt=adcpadbits(length);
    if (otherpar>(LFSR_[reg]&4095)) bt=!bt;
    break;

    //TM in TM:    static inline uint32_t TMbits(uint32_t depth, uint32_t seq, uint32_t rndd, uint32_t par){  // for TM in TM, return inv or loop bits
  case 104:
    // select sequence for TM in TM - we can choose just to use bt from loop or loop it back in
    // these kind of recursive modes which interrupt themselves... eg. feedback before we have feedback decided at faster speed
    // how many CV? depth=length, position to get seq, par is parameter. = 3x so we use ADC_ for parameter, but leaves 2x cv we don't have
    // so fix length ???
    ADCtwo;
    tmp=otherpar>>7; // 5 bits is our offset
    //    length=31-(tmp+length); //length is fixed if we detach
    bt=*SR&(masky[length]<<tmp); /// our seq
    bt=bt>>tmp;
    if ((length+tmp)>31){
      length=31-tmp;
    }
    bt=TMbits(length, bt, LFSR_[reg]&4095, k[reg]);
    // pull in adcbits
    bt|=adcpadbits(length);
    break;

  case 105: // exact Turing machine - add otherpar and DAC and compare noise to this for loop or not
    tmp=otherpar; // CVL is also knob+CV so we have 2 CVs - we don't need to deatch and can use CV here 
    tmp+=gate[dacfrom[daccount][reg]].dac;
    if (tmp>4095) tmp=4095;
    //    bt=(*SR>>length)& 0x01;
    bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (tmp>(LFSR_[reg]&4095)) bt=!bt;
    break;

  case 106: // exact Turing machine - add otherpar and DAC and compare noise to this for loop or not
    ADCtwo;
    tmp=k[reg]; // CVL is also knob+CV so we have 2 CVs - we don't need to deatch and can use CV here 
    tmp+=gate[dacfrom[daccount][reg]].dac;
    if (tmp>4095) tmp=4095;
    //    bt=(*SR>>length)& 0x01;
    bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
    if (tmp>(LFSR_[reg]&4095)) bt=!bt;
    break;
    
  case 107:
    // osc1bits
    bt=osc1bits(length,reg);
    break;

  case 108:
    // 2scompadcbits - always 12
    bt=adc12compbits(length);
    break;

  case 109:
    // 2scompadcbits - 
    bt=adccompbits(length); // can also be otherpar for depth
    break;

  case 110:
    /// ones compliment - always 12 bits
    bt=adc12onecompbits(length); 
    break;

  case 111:
    /// ones compliment
    bt=adconecompbits(length); // can also be otherpar for depth adconecompbits
    break;

  case 112:
    /// 2 complimentDAC - now with mix
    bt=daccompbits(length); // can also be otherpar for depth adconecompbits
    bt|=adccompbits(length); // can also be otherpar for depth
    break;
    
  case 113: // would be nice to run/slip this at another speed to what is used for...how
    // cycling of probbits into SR and strobe/toggle freezes/unfreezes this
    if (strobe) toggle[reg]^=1;
    if (toggle[reg]){
      bt=probbits(otherpar,reg);
      ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
    }
    else {
      bt=(ADCshift_[regg]>>31)&0x1;
      ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
    }

  case 114: // try with float but this is the same with phasings - and we need to make independent! TODO!
    // for unipolar 0-248
    ADCtwo;
    //    inb=(((float)k[reg])/2048.0f)-1.0f; // from 0 to 4095 but where is the middle? 2048
    k[reg]=k[reg]-1024;
    inb=(((float)k[reg])/1024.0f); // from 0 to 4095 but where is the middle? 2048
    if (inb>1.0f) inb=1.0f;
    
    integratorf+=(inb-oldvaluef);
    if(integratorf>0.0f)
      {
	oldvaluef=1.0f;
	bt=1;
      }
    else
      {
	oldvaluef=-1.0f;
	bt=0;
      }   
    break;    

    
    ///////////////////////
  } // switch
  return bt;
}



#define BITN_AND_OUTVgen_ {						\
    PULSIN_XOR;								\
    gate[w].shift_+=bitn;						\
    val=(*dacfunc[gate[w].func[dactypecnt][fdac]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvdac]], w); \
    PULSOUT;								\
}



// bump/change globalroutes and other counts: 
/*
static uint32_t count=0; // for route
static uint32_t daccount=0; // for dacfrom
static uint32_t spdcount=0; // for spdfrom
static uint32_t tailcount=0; // for tail choice UNUSED
static uint32_t binroutetypecount=0; // for type of binroute - used in some geogens here

 */

/*
static inline uint32_t (uint32_t depth, uint32_t in, uint32_t wh){
}
*/



// new prob ones: probcvladcselcvm, probdacadcsel, probtrigadcsel -> more work on these...

// TODO; check probability of entry of adc or not: SR_geomantic_inneradcpP
// prob of moving adc along, prob of a reset (above but needs work)
// to add these here, and also more generic adcs: internal adcprobs are in geogen.h



// check length
uint32_t (*genericfuncs[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bits,        zosc1bits, sigmadelta, cipher, osceq, zprobbits, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zwiardbits, zwiardinvbits, zreturnnotbits, zosc1bits, zosc1bits}; // doubled up a bit to hit 64 //  TEST

static inline uint32_t gensel(uint32_t depth, uint32_t in, uint32_t wh){  // select from a generic list - depth is param and in is the selection
  // in is not used in generic functions...
  // so for rungler we use CVM as that IN=cvbitcomp
   uint32_t bt;
   bt=(*genericfuncs[in>>6])(depth, 0, wh); // 6 bits=64 generic functions to collect
   return bt;
}


static inline uint32_t bitsmod(uint32_t depth, uint32_t wh){   // was cvbits
   uint32_t bt=0;
   gate[wh].shift_^=depth;
   return bt;
}

static inline uint32_t zero(uint32_t depth, uint32_t wh){  
  //   uint32_t bt=0;
   return 0;
}



uint32_t (*adcfromsddprob[32])(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv)={zpadcx};
// how many CVs do we need for this? 3x - one for sel, prob and for depth

static inline uint32_t probcvladcselcvm(uint32_t depth, uint32_t in, uint32_t wh){  // select adc using CVM, prob from CVL which leaves CV(speed)
  uint32_t bt, prob;
  if (CVM[wh]<(LFSR_[wh]&4095)) prob=1; // which way round
  else prob=0;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
  //   bt=(*adcfromsddprob[CVM[wh]>>7])(depth, in, wh, prob); // 5 bits
  bt=(*adcfromsddprob[0])(depth, in, wh, prob, 1); // TESTING
  // test
  return bt;
}

// we can have fixed versions against dac 
static inline uint32_t probdacadcsel(uint32_t depth, uint32_t in, uint32_t wh){  // select adc using CVM, prob from CVL which leaves CV(speed)
  uint32_t bt, prob;
  if (gate[dacfrom[daccount][wh]].dac<(LFSR_[wh]&4095)) prob=1; // which way round
  else prob=0;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
  //   bt=(*adcfromsddprob[CVM[wh]>>7])(depth, in, wh, prob); // 5 bits
  bt=(*adcfromsddprob[0])(depth, in, wh, prob, 1); // TESTING
  // test
  return bt;
}

//and also using trigger 
static inline uint32_t probtrigadcsel(uint32_t depth, uint32_t in, uint32_t wh){  // select adc using CVM, prob from CVL which leaves CV(speed)
  uint32_t bt, prob;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
  //   bt=(*adcfromsddprob[CVM[wh]>>7])(depth, in, wh, prob); // 5 bits
  bt=(*adcfromsddprob[0])(depth, in, wh, gate[wh].trigger, 1); // TESTING
  // test
  return bt;
}




//uint32_t (*adcfromsdd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits,  zadccompbits}; // doubled up // TEST!

/////////////////////////////////////////////////////////////////
// new modifier functions - generate value for gate[x].par or just intervene 
/*
uint32_t *newCVlist[4][16]={
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &CVM[0], &ADCin, &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &gate[0].oldcv, &gate[0].oldcvl, &gate[0].oldcvm},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &CVM[1], &ADCin, &Gshift_[0], &Gshift_[2], &Gshift_[3], &clksr_[1], &param[1], &gate[1].oldcv, &gate[1].oldcvl, &gate[1].oldcvm},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &CVM[2], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[3], &clksr_[2], &param[2], &gate[2].oldcv, &gate[2].oldcvl, &gate[2].oldcvm},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &CVM[3], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &clksr_[3], &param[3], &gate[3].oldcv, &gate[3].oldcvl, &gate[3].oldcvm}
};
*/

/*
static inline uint32_t cvmod(uint32_t depth, uint32_t wh){  
  // 19 in cvlist -> 16 in new cvlist
  uint32_t bt=*newCVlist[wh][depth>>8];// 4 bits=16
  //  uint32_t bt=*newCVlist[wh][0];// 4 bits=16
  return bt;
}
*/


typedef struct modes_ { // what we need: function, strobey, interpoll, inner_function?, detach?, 
  uint32_t strobey;
  uint32_t interpoll;
  //  uint32_t detachlen;
  uint32_t detachspeed;
  void (*func)(uint8_t w, uint32_t strobey, uint32_t detachlen, uint32_t  detachspeed, uint32_t interpoll, uint32_t (*innerfunc)(uint8_t w));
  uint32_t (*innerfunc)(uint8_t w);
} modez; 


typedef struct stack_ {
  uint32_t (*speedfrom)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t* speedcv1;
  uint32_t* speedcv2;
  uint32_t (*bit)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t* bitcv1;
  uint32_t* bitcv2;
  uint32_t* lencv;
  uint32_t bitindexy; // bit index for reference
  uint32_t speedindexy; // speed index
} stack;

// what can be removed from here?


//  uint32_t (*bit[64])(uint32_t depth, uint32_t in, uint32_t wh);
  //  uint32_t (*speedfrom[64])(uint32_t depth, uint32_t in, uint32_t wh);
  //  stack stacky[64]; // full stack


// global count for sync=glob   tmp=depth>>8; ///4 bits


// just a test here - uses CVL to select bitfunc
// but can't be in generic

static inline uint32_t Rtest(uint32_t depth, uint32_t in, uint32_t wh){ 
  uint32_t bt=0, bitrr, tmp;
  // fixed binroute
  tmp=binroute[count][wh]|binary[wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  // do changes using depth which can be CVL or...
  bitfunccnt=depth>>8; // 16 is 4 bits
  
  return bt;
}



/*


* plan


for calibration use unipolar out/gnded from Quad slope

CODE: modes? normed clocks, how fast we can run?

basic speed and new CV hardware tests, MANUAL

*20Kz fastest dac speed with 32/16 divider...*

signals are inverted so unipolar 0-5v is from 0-2048 values and bipolar -5 to 5v is 0-4095

-2.5 to +2 is 1024 to 1024+2048 = 3072

/////////////////////////////////////////////////////////

- implement sketch of all modes as below with DAC and ADC options
- check all pulsins, outs and clks/clk norm functions
- test/play
- tweaks for slower speed, CLK norms, what else? how we handle one bit audio filter?


settle speeds and test new voltage/CV scheme: what is Hz for 16 octaves slowest and fastest? 0.25 Hz to 16KHz

older notes:
- thinking on scale/speeds - at the moment we have 0-5v CV input and
  covers 2^10 - so 10 octaves...we want say 13 or 14 octaves - 0.1Hz
  to 5K for 14 octaves/doublings


can we have knob covering this and 0-10v as 1v/OCT

100k instead of 200k for -10v and 33k in loop - as in Tides! (and can we adjust/scale input cv)

// 14 octs in 1024 =73 per octave =140K of cv in maybe approx... (for 730 max)

http://lushprojects.com/circuitjs/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgoqoQFMBaMMAKACVwU9wwURCALDz5UIA2lEkwELAIYgUCQp24DsfXt27Zo2EAx16w8ePpgnMkBMQQoU4-Bkgoyk4yZYAnFcIX5foiaQ7D4C3MTKYVIg4vrG0dJeodxoqtxUTvAsAO5+3Mx8isoFUElF-EJqfIKSKLhwLADGCkog6jHt7VQC0JlB-WCMxPoovVZkxC4RkMRqkOTmkKy55SXlNcErrTXlUZstkSn+ezkHMSmtXadVbXw3G9ftNTeapQDmZ2ACQuWpUo8aLgxCI+YIAe0kG3OhHI8UWcDIhCUilqkmwLAhYCQULUCCQSHhMwwSMIKIgGiQ6KAA

or 100k cv in, 23k feedback, and -10v is 70k
*/

/// cleaning caput000


uint32_t funccmax[64][9]={
  {8,2,17,61,23}, // maximum value if x>funcmax... // update these as we add more functions
};

uint32_t cvmax[64][10]={
  {19,19,19,19,19,19,19,19,19,19}, // update for max number of cv options
};


//fspeed, flength, fadc, fbit, fdac,  fnew, fout, gs, out // fnew is parameter function // fout outside
//1       2        3     4     5     6     7     8   9

//basic but remeove adc
//out and fout mixed up in comments

//{1, 1, 1, 2, 0, 0, 0, 0, 0}, //['spdfrac2', 'rlen', 'zadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero']
//{5, 0, 6, 0, 0, 8, 0, 0, 0, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null']
/*
uint32_t funcNN[64][9]={
  {1, 1, 21, 2, 0, 0, 0, 0, 0}, //['spdfrac2', 'rlen', 'zadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero']
  {1,1,18,2, 0,0,0,0,0}, //  - 18 is select adc with CVM // 20 is new prob test on CVL select on CVM
  {2,0,18,0, 0,0,0,0,0},
};

uint32_t funcLL[64][9]={
  {1, 1, 0, 2, 0, 2, 0, 0, 0}, //['spdfrac2', 'rlen', 'noadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero'] // altering some
  {1,1,0,1, 0,0,0,0,0}, // 
  {2,0,0,59,0,0,0,0,0},
};

uint32_t funcCC[64][9]={
  //  {1,1,0,2,1, 5,0,6,0,6,0,1,0},
  {1, 1, 0, 2, 0, 0, 0, 0, 0}, //['spdfrac2', 'rlen', 'noadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero'] // altered for delaylineIn and OUT
  {1,1,0,1, 26,0,0,0,0}, //  - 11 is select speed with CVM 26 dac with cvm
  {1,1,0,60, 0,0,0,0,0}, // rung - speed from cv, route from R //
};

uint32_t funcRR[64][9]={
  {1, 1, 0, 2, 0, 0, 0, 0, 0}, //['spdfrac2', 'rlen', 'noadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero']
  {1,1,0,1, 0,0,0,0,0}, // 
  {2,1,0,61,0,0,0,0,0}, // route from L, speed from N
};
*/
// cvspeed, cvspeedmod, cvlength, cvdac, cvadc, cvadcIN,  cvbit, cvbitcomp, cvnew, cvout
// 1        2            3         4      5       6        7      8          9      10  

// 0 null 1 0dac 2 1dac 3 2dac 4 3dac 5 CV 6 CVL 7 CVM 8 ADCin 9 Gs0 10 Gs1 11 Gs2 12 Gs3 13 clksr_ 14 param 15 par 16 oldcv 17 oldcvl 18 oldcvm
/*
uint32_t cvNN[64][10]={
  {5, 0, 6, 0, 6, 8, 0, 0, 0, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null']
  {5,0,6,0,6,8, 0,0,0,0}, // 8 is ADC itself IN
  {5,6,6,0,6,8,6,7,0,0},
};

uint32_t cvLL[64][10]={
  {15, 0, 6, 0, 0, 0, 0, 0, 7, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null'] // altering some
  {5,0,6,0,6,0,4,0,0,0},
  {5,6,6,0,6,0,6,7,0,0}, // rung2 but modded...
};

uint32_t cvCC[64][10]={
  //{1,1,0,2,1, 5,0,6,0,6,0,1,0},
  {5, 0, 6, 0, 0, 0, 0, 0, 0, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null']
  {5,0,6,7, 6,0,7,0,0,0},
  {5,0,6,7, 0,0,4,0,0,0}, // rung - speed from cv, route from R //
};

uint32_t cvRR[64][10]={
  {5, 0, 6, 0, 0, 0, 0, 0, 0, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null']
  {5,1,6,0,6, 0,7,7,0,0},
  {5,6,6,0,0, 0,1,0,0,0}, // route from L, speed from N
};
*/

//static uint32_t cvcount=0; // for type of CV

// would be nice to have 8 so is 3 bits - logic? logiccount

//uint32_t *countfield[8]={&count, &daccount, &spdcount, &adctypecount, &dactypecount, &binroutetypecount};

//uint32_t *funcfield[8]={&dactypecnt, &spdfuncnt, &lengthfunccnt, &adctypecnt, &bitfunccnt}; // only 5 there


uint32_t options[4][24]={
      {1,3,3, 2,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 0,3,3},
      {0,3,3, 2,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 1,3,3},
      {0,3,3, 1,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 2,3,3},
      {0,3,3, 1,3,3, 2,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 3,3,3}
    };

// extra files to check...


//#include "modeN.h"
//#include "modeL.h"
//#include "modeR.h"
//#include "modeC.h"
//#include "probability.h" // probability modes

//#include "basis.h" // basics from commented ones just to speed up tests
//#include "experiment.h" // more functional modes - can also shift some things here... trials
//#include "bit.h" // bitmodes but some are still in modeL
//#include "rungler.h"



// how many groups
#define GROUP 14 // for 16

  //re-test all new for crash  {adc2, adc0, adc0, SRminor_vienna, SRrunggenericbitsadcX, SRrunghead0NX, adcLrung0-fixed18/6, adcLrung1fixed, adcLrung2fixed,   adcrung0fixed, adcLbinprobX, noSRadc2sX, noSRadc2sX, adcLabstractLDX, stream4_unshareX, streamX}, //128

 /* 
void (*funcgroups[4][128])(uint8_t w)=
{
    {adc2, adc0, adc0, SRminor_vienna, SRrunggenericbitsadc, SRrunghead0N, adcLrung0, adcLrung1, adcLrung2,   adcrung0, adcLbinprob, noSRadc2s, noSRadc2s, adcLabstractLD, stream4_unshare, stream}, //128
  //    {adc2, adc0, adc2, adc0,  adc2,   adc0, adc2, adc0,adc2,  adc0,adc2, adc0, adc2, adc0, adc2, adc0},
  
  {SRX0, SRX0, SR_layer1, SRminor_vienna, SRrunggenericbitsgenopp, SRrunghead0L, SRrung0,   SRrung1,   SRrung2, SRrung3,  adcLbinprob, SRshroute, noSRcopy, adcLabstractLD, stream4_unshare, stream},  // 128

  {newdac2, dac0, dac0, SRminor_vienna, SRrunggenericbits, SRrungout, dacLrung0, dacLrung0, dacNLRin, dacNLRinlogic, adcLbinprob, dac2, noSRdac2s, dacNLRprobin,   stream4_unshare, stream}, 
  
  {SRX0, SRX0, SR5_feedback, SRminor_vienna, SRrunggenericbitsgen, SRrungbody0, SRRrung0, SRRrung1, SRRrung2, SRRrung3,     adcLbinprob, SRX0,     SRX0, adcLabstractLD, stream4_unshare, stream} //64 
}; // 13 so far -- to add more for lisbon - select at random from 50 - how to do from cards...
*/  
// card for each = 16 possibles... we need 50! - q of slidings - we can slide +-64 except modeR cannot slide so should be most generic

 /*
- how else we can express matrices which makes sense - to match up:

as array for each side:

eg. speed, length, bit FUNCS, adc, which dac // them CV indices

thus:
*/

// collect modes: Lmultiplespeednew // tag modesx modex
/*void (*dofunc[4][64])(uint8_t w)=
{
  {SR_geomantic}, 
  {SR_geomantic}, 
  {SR_geomantic}, 
  {SR_globalbin}
};
*/
  /*  
  for (x=0;x<64;x++){
    for (y=0;y<9;y++){
      gate[0].func[x][y]=funcNN[x][y];
      gate[1].func[x][y]=funcLL[x][y];
      gate[2].func[x][y]=funcCC[x][y];
      gate[3].func[x][y]=funcRR[x][y];
    }
  }

  for (x=0;x<64;x++){
    for (y=0;y<10;y++){
      gate[0].cv[x][y]=cvNN[x][y];
      gate[1].cv[x][y]=cvLL[x][y];
      gate[2].cv[x][y]=cvCC[x][y];
      gate[3].cv[x][y]=cvRR[x][y];
    }
  }
  */


    // tests for stack
    //  pushspeed(3, x); // spdfrac
    //  pushspeedcv(CVlist[x][cvpair[0][0]], CVlist[x][cvpair[0][1]], x);
  // trial functions with length

  //   0:zeros 1:binrout 2:binroutfixed 3:binroutor 4:zsingleroutebits 5:zbinrouteINVbits 6:zbinroutebits_noshift_transit 7:zbinroutebits_noshift 8:zbinroutebitscycle 9:zbinroutebitscyclestr 10:zbinroutebitscycle_noshift 11:zbinroutebitscyclestr_noshift 12:zbinrouteORbits 13:zbinrouteANDbits 14:zbinrouteSRbits 15:zbinroutebitsI 16:zbinroutebitsI_noshift 17:zbinroutebitscycleI_noshift 18:zbinroutebitscyclestrI 19:zosc1bits 20:sigmadelta 21:cipher 22:osceq 23:zSRclksr 24:zSRclksrG 25:zSRNbits 26:zSRLbits 27:zSRCbits 28:zSRRbits 29:zpulsebits 30:zprobbits 31:zprobbitsxorstrobe 32:zprobbitsxortoggle 33:zsuccbits 34:zsuccbitsI 35:zreturnbits 36:zreturnnotbits 37:zosc1bits 38:zwiardbits 39:zwiardinvbits 40:zTMsimplebits 41:zonebits 42:zlfsrbits 43:zllfsrbits 44:zflipbits 45:zosceqbitsI 46:zosc1bitsI 47:zTMsimplebitsI 48:zwiardbitsI 49:zwiardinvbitsI 50:zonebitsI 51:zlfsrbitsI 52:zllfsrbitsI 53:zflipbitsI 54:zpattern4bits 55:zpattern8bits 56:zpattern4bitsI 57:zpattern8bitsI 58:Rtest 59:gensel 60:binroutfixed_prob1R 61:binroutfixed_prob1L 62:binroutfixed_prob2 63:binroutfixed_prob3 64:binroutfixed_prob4 65:SRdelay_lineOUT

    //  pushbit(28, x);  //2: fixed binroute
    //  pushbitcv(CVlist[x][0], CVlist[x][0], x);

  /* 
  www++;
 
  if (www>3) {
    www=0;
    resetz=1;
    (*dotail[tailcount])(); // or this is 5th [www==4] www  - can also be seperate case...
  }
  */

  
  // testing
//  spdfunccnt=cvcount=dactypecnt=lengthfunccnt=adcfunccnt=bitfunccnt=glob;

  // where are these used and is too long as counts every time
  //      counter[4]++; counter[5]++; counter[6]++;

 //SR_geomantic_outer(www); // now this one sets inner function

  //  if (www==3) (*dotail[tailcount])(); // or this is 5th [www==4] www  - can also be seperate case...
  
  // genericLFSR for all probability modes


void testnull(void){
}

uint32_t testmodes[4]={0,0,0,0};



//////////////////////////////////////////////////////////////////////////
// new geomantic functions abstracted
//////////////////////////////////////////////////////////////////////////

// gshifts
static inline uint32_t gshift0(uint32_t w){ 
  GSHIFT_;
  return 0;
}

static inline uint32_t gshiftNOS(uint32_t w){ 
  GSHIFTNOS_;
  return 0;
}

static inline uint32_t gshiftnull(uint32_t w){
  return 0;
}

// what other gshifts there are: only noshift of own SR //GSHIFTNOS_// - so we have 3 options

// split speeds
// temp:  static inline uint32_t OUT_temp(uint32_t depth, uint8_t wh){
static inline uint32_t OUT_splitx(uint32_t depth, uint32_t w){
  int32_t tmp; uint32_t bitn, bitrr, val, x, xx, lengthbit=15, new_stat;
  if (!sbinroute(others[w][0])) { // inversion to avoid running out
      GSHIFTNOS_; // 2.copy gshift on trigger // gate[XX].Gshift[w]&0x01...
    }

  if (!sbinroute(others[w][1])) { //3.advance incoming ghost
    BINROUTEADV_;
  }

  if (!sbinroute(others[w][2])) {
    gate[w].shift_=gate[w].shift_<<1; // 1. shifter
  }

}

static inline uint32_t IN_splitx(uint32_t depth, uint32_t w){ // matches above and must match outfunction     BITN_AND_OUTVXOR_;
  int32_t tmp; uint32_t bitn, bitrr, val, x, xx, lengthbit=15, new_stat;
    BINROUTENOG_; // or not
    return bitn;
}  


static inline uint32_t OUT_zero(uint32_t depth, uint32_t w){ 
  return 0;
}

static inline uint32_t OUT_adc_overonebit(uint8_t w){ // oversample one bit
  uint8_t bt;
  bt=adconebitsx();
  return bt;
}

//////////////////////////////////////////////////////////////////////////
// DACOUT : as generic bits->value
// start to wrap dac functions - there are 24!
// static inline uint32_t DAC_(uint32_t wh, uint32_t shift, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t strobe){  // DAC is 12 bits
// length could also be generic so is just a processor

static inline uint32_t BVddac0(uint32_t depth, uint32_t in, uint32_t wh){ // version for any 12 bit IN value -> bits
  uint32_t val;
  val=DAC_(wh, in, SRlength[wh], 0, depth, gate[wh].trigger);
  return val;
}

static inline uint32_t ddac0(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 0, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac1(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 1, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac2(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 2, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac3(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 3, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac4(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 4, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac5(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 5, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac6(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 6, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac7(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 7, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac8(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 8, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac9(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 9, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac10(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 10, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac11(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 11, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac12(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 12, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac13(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 13, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac14(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 14, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac15(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 15, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac16(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 16, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac17(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 17, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac18(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 18, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac19(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 19, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac20(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 20, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac21(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 21, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac22(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 22, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac23(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 23, depth, gate[wh].trigger);
return val;
}

static inline uint32_t ddac24(uint32_t depth, uint32_t wh){
  uint32_t val;
  val=DAC_(wh, gate[wh].shift_, SRlength[wh], 24, depth, gate[wh].trigger);
return val;
}

uint32_t (*dacfromsdd[32])(uint32_t depth, uint32_t wh)={ddac0, ddac1, ddac2, ddac3, ddac4, ddac5, ddac6, ddac7, ddac8, ddac9, ddac10, ddac11, ddac12, ddac13, ddac14, ddac15, ddac16, ddac17, ddac18, ddac19, ddac20, ddac21, ddac22, ddac23, ddac24, ddac0, ddac1, ddac2, ddac3, ddac4, ddac5, ddac6};


static inline uint32_t dacselcvl(uint32_t depth, uint32_t wh){  // select adc using CVL
   uint32_t bt;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
   bt=(*dacfromsdd[CVL[wh]>>7])(depth, wh); // 5 bits
   return bt;
}

static inline uint32_t dacselcvm(uint32_t depth, uint32_t wh){  // select adc using CVL
   uint32_t bt;
   // *adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)
   bt=(*dacfromsdd[CVM[wh]>>7])(depth, wh); // 5 bits
   return bt;
}




//eg. outer function: on functionchange select speedfrom using CVL, speedcv is CV, bitin is unchanged, bitcv is unchanged, lencv is unchanged...
// but not ON functionchange we set... as we need CV and to change speedfrom but can be variations:

// 5/8/2022 adding prob/bit




//static uint8_t strobed[4]={0,0,0,0};



/*
latest geomantic:

- CVM more as attaching parameters and functions... but how...// matrix of fixings rather than a stack


     // entry into new modes

how that works... mode as an interpreter...

execution of a matrix that is changed by CVM and feedback onto that matrix... can also be a stack though or...

CVM can only be a meta/mode selector - but then we can't use CV, or CVL as these are part of internals...

unless they get fixed...

//or or modeR CVM - in 4 sections for attachments (also using strobe)... but again we can't use CVL or CV

////

matrix is maybe just values -> indexes and values, no pointers eg.

as array, speedfunc, cv1, cv2, bitin, cv1, cv2, len

gate[w].matrix[0] etc...

{speedfrom/index, speedcv1, speedcv2, bit/index, bitcv1, bitcv2, lencv}

so body is interpreter here - each has an inner and an outer function (what speed does outer run at?) ghost and ghost

could also hold adc there?

and we choose functions to change these: for example copy a matrix to this one - according to what do we choose?  problem is to repeatedly do this...

can also apply a function to a value...

again how to seperate INT/EXT?

4x16 as key ... geomantic figures

*/

// 16 inner x 4 outer??? or vice versa

// trial INNER/OUTER - but for now is just another matrix op/array/could also be stack so we need to do more inside it! it does allow us to leave elements remaining...
// we could have stack with index an mark unchanging as what? - as top bit of 32 bits


// list of functions:

///TODO: still to add some which got left out... // left out from where?

// routes: binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI,

// speeds: spdfrac, spdfrac2, strobe, ones, clksr, clksrG

// bits: sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI,

// zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits

//1speed 
// now with depth/CV

/// we need to list/catalogue: ADCs, speeds, bits of various descriptions... // overlap/overlay of bits and speeds

// that catalogues can also be kind of matrices, with holes and exceptions... used by different interpreters eg. speedfromnostrobe, speedfromabstract, speedfromroutes

//uint32_t (*speedfromsdd[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksrG, clksr, strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG, strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG, spdfrac, spdfrac}; // is in geogen.h


uint32_t (*metain[64])(uint8_t w, uint32_t mood)={itself};    

 void (*SRgeo_inner[4][64])(uint32_t w)=
{
{SR_geomantic_inneradc},
{SR_geomantic_innernoadc},
{SR_geomantic_innernoadc},
{SR_geomantic_innernoadc}
};


//uint32_t inindex=(*metain[mode[www]])(www, mode[www]); // - functions which generate indices
 uint32_t inindex=0;
 // (*SRgeo_inner[www][inindex])(www); // different indexes for this 
 // SR_geomantic_inner(www); 


// from latest geomantic.h and geogen

//////////////////////////////////////////////////////////////////////////
// speedsels


static inline uint32_t speedselcvl(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt=0;
  bt=((*speedfromsdd[CVL[wh]>>7])(depth, in, wh));
  return bt;
  }

static inline uint32_t speedselcvm(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt=0;
  bt=((*speedfromsdd[CVM[wh]>>7])(depth, in, wh));
  return bt;
  }

/*
static inline uint32_t speedseloldcvm(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth 
  static uint32_t bt=0;
  bt=((*speedfromsdd[gate[wh].oldcvm>>7])(depth, in, wh));
  return bt;
  }

static inline uint32_t speedseloldcvl(uint32_t depth, uint32_t in, uint32_t wh){   // toggle - no depth
  static uint32_t bt=0;
  bt=((*speedfromsdd[gate[wh].oldcvm>>7])(depth, in, wh));
  return bt;
  }
*/


//////////////////////////////////////////////////////////////////////////
//0
//lengths


// we can fork in processors here... ???

static inline uint32_t rlen(uint32_t depth, uint32_t wh){
  uint32_t bt=lookuplenall[depth>>7]; // 5 bits
  return bt; // bt is a value
}

static inline uint32_t nlen(uint32_t depth, uint32_t wh){
  return 0; // is just holder
}

// hold old [CVL/depth] length
static inline uint32_t holdlen(uint32_t depth, uint32_t wh){ // we don;t use depth as we just hold // can have same for speed...
  static uint32_t oldd[4]={0,0,0,0};
  if (held[wh]!=0) oldd[wh]=held[wh];
  held[wh]=0;  
  uint32_t bt=lookuplenall[oldd[wh]>>7]; // 5 bits
  return bt; // bt is a value
}


//0function outside speed
uint32_t (*outside[32])(uint32_t depth, uint32_t wh)={OUT_zero, OUT_SRdelay_lineIN}; // delay bin needs to match with delay out, or shared delay lines...

//0.5gshift
uint32_t (*gshifts[32])(uint32_t wh)={gshift0, gshiftnull};

uint32_t (*dacfunc[32])(uint32_t depth, uint32_t wh)={ddac0, ddac1, ddac2, ddac3, ddac4, ddac5, ddac6, ddac7, ddac8, ddac9, ddac10, ddac11, ddac12, ddac13, ddac14, ddac15, ddac16, ddac17, ddac18, ddac19, ddac20, ddac21, ddac22, ddac23, ddac24, dacselcvl, dacselcvm};

//2length IGNORE!
uint32_t (*lengthfromsd[32])(uint32_t depth, uint32_t wh)={nlen, rlen, holdlen}; // we only have 2 functions here so far - nlen is null/hold, what other functions



//5newfunc
//uint32_t (*newfunc[32])(uint32_t depth, uint32_t wh)={zero, bitsmod, cvmod}; //

/*
uint32_t *CVlist[4][22]={ // TAIL is &Gshift_[8] // add in statics for adc, dac and length
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &CVM[0], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &Gshift_[8], &gate[0].oldcv, &gate[0].oldcvl, &gate[0].oldcvm, &gate[0].adctype, &gate[0].dactype, &SRlength[0]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &CVM[1], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[1], &param[1], &Gshift_[8], &gate[1].oldcv, &gate[1].oldcvl, &gate[1].oldcvm, &gate[1].adctype, &gate[1].dactype, &SRlength[1]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &CVM[2], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[2], &param[2], &Gshift_[8], &gate[2].oldcv, &gate[2].oldcvl, &gate[2].oldcvm, &gate[2].adctype, &gate[2].dactype, &SRlength[2]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &CVM[3], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[3], &param[3], &Gshift_[8], &gate[3].oldcv, &gate[3].oldcvl, &gate[3].oldcvm, &gate[3].adctype, &gate[3].dactype, &SRlength[3]}
};

  // 0,    1             2             3             4             5       6        7            8           9         10     11 -> 19

// 0 null 1 0dac 2 1dac 3 2dac 4 3dac 5 CV 6 CVL 7 CVM 8 ADCin 9 Gs0 10 Gs1 11 Gs2 12 Gs3 13 clksr_ 14 param 15 par 16 oldcv 17 oldcvl 18 oldcvm


// TODO: but this over-rides dacfrom - alternative would be to index as CVlist[dacfrom[w]+1] !!!

//......
// TODO: but these become more like groups now - question is if we have in SR individual array of speedfuncs etc. with own count in
// and we can sync and shift these counts....

// then each would need ref into 4 functions +dac5 + 6 sets of CV???? = 10 or 11 counters each...

enum refs {fspeed, flength, fadc, fbit, fdac, fnew, fout, gs, out}; // 9
enum cvs {cvspeed, cvspeedmod, cvlength, cvdac, cvadc, cvadcIN,  cvbit, cvbitcomp, cvnew, cvout}; //10

// out functions
static inline uint32_t vgen(uint32_t bitn, uint32_t w){
  int32_t tmp; uint32_t xx,val,lengthbit=15, new_stat;
  //  BITN_AND_OUTVgen_;
  return val;
}

//    BITN_AND_OUTVXOR_;
static inline uint32_t vxor(uint32_t bitn, uint32_t w){
  int32_t tmp; uint32_t val, xx, lengthbit=15, new_stat;
  BITN_AND_OUTVXOR_;
  return val;
}

//6 out
uint32_t (*outs[32])(uint32_t bitn, uint32_t wh)={vgen, vxor};

/*
void SR_geomanticxx(uint8_t w){  
  static uint32_t oldspdfunccnt;
  HEADNADA;
  if (interp[gate[w].func[spdfunccnt][fspeed]]){ // gate[w].func[spdfunccnt][fspeed]
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
   if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  CLKSR; // new macro deals with intflag outside speed

      // moved up TODO: - wrap in macro 
    if (gate[w].cvcnt!=gate[w].oldcvcnt || spdfunccnt!=oldspdfunccnt ){ // we have a CV change // can be other changes or strobe or.... ??? 
      gate[w].oldcv=CV[w];
      gate[w].oldcvl=CVL[w];
      gate[w].oldcvm=CVM[w];
    }
    gate[w].oldcvcnt=gate[w].cvcnt;
    oldspdfunccnt=spdfunccnt;

    // function outside speed...
    bitn=(*outside[gate[w].func[outfunccnt][fout]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvout]],w);
    
  if ((*speedfromsd[gate[w].func[spdfunccnt][fspeed]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvspeed]],*CVlist[w][gate[w].cv[gate[w].cvcnt][cvspeedmod]], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    
    if (gate[w].func[lengthfunccnt][flength]!=0){ // so function 0 null should just hold length
    SRlength[w]=(*lengthfromsd[gate[w].func[lengthfunccnt][flength]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvlength]],w); // lengthfunc - not many?
    }

    //GSHIFT_;
    //(*gshifts[0])(w);
    (*gshifts[gate[w].func[gscnt][gs]])(w);

    // CORE
    
    if (gate[w].cv[gate[w].cvcnt][cvadcIN]==8){ // real ADC
    ADCgeneric2; // input into shared one..
    }

    // 5/7/2022 added in new function//which can generate a param but also modify SR...
    // param needs to have pointer in struct = par
    // 26/7 eg. par can select one of cvs and copy value
    
    gate[w].par=(*newfunc[gate[w].func[extfunccnt][fnew]])(4095-(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvnew]]), w); // invert?
    bitn^=(*adcfromsd[gate[w].func[adcfunccnt][fadc]])(4095-(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvadc]]), *CVlist[w][gate[w].cv[gate[w].cvcnt][cvadcIN]],w); // invert?
    bitn^=(*bitfromsd[gate[w].func[bitfunccnt][fbit]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvbit]], *CVlist[w][gate[w].cv[gate[w].cvcnt][cvbitcomp]],w);
    // ENDCORE
    //    if (strobey) bitn|=gate[w].trigger;	 // extra bits in if necessary or is another function
    //BITN_AND_OUTVgen_; // pulsin is in there - added new DAC - but we need alter     gate[w].shift_+=bitn; function in there/
    //final bitnout
    //
    val=(*outs[0])(bitn, w); //(*outs[gate[w].func[outcnt][out]])(bitn, w);
    new_data(val,w);
    }
  }
*/

/*

new geomantic _ what we can simplify it to...

1.remove outside, gshift, think about length ops (how?), [newfunc and par?]

//// we had 8 functions

1outside - we can combine speed and general
2speedfrom
3lengthfrom X we use param for length // length from SR
4gshifts -> what they are. as switch or...
5param (do length here)
6adc - now if we have adc
7bitfrom **
8outs - ???? leave for moment as fixed...

simple model -. no param as this should be another SR  - tail maybe as param SR!

processors for SRs:

value->bits (adc) // valtobits
bits-> value (dac od SRx) // bitstoval

//paramx/length=bitstoval>>xx

//maybe we should head to 8 bits as standard for all - but speed is 10 bits, etc.... so maybe leave as is/open/recheck ADCs // leave for now but...

return to only: speedfrom, bitfrom

2.attach function on entry into new function counter (stack of these)

what stack does - stack overwrites oldest when full  - see test.c (and when is empty?)

function counter for all functions//

*/

typedef uint32_t (* funcy)(uint32_t depth, uint32_t in, uint32_t wh); // use this to simplify matters

typedef struct pair_ {
  uint32_t* cv1;
  uint32_t* cv2;
    } pair;

#define SIZEY 64 

// how to make more generic? we can also think about descending/ascending through a stack of functions which don't differentiate speed, bit etc...
//

// how to do all as one stack ?? length, end and gshift??? stack in modes.h
/*
typedef struct stack_ {
  uint32_t* bitcv1;
  uint32_t* bitcv2;
  uint32_t* speedcv1;
  uint32_t* speedcv2;
  uint32_t (*bit)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t (*speedfrom)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t bitindexy;
} stack;

// so all will share index - is that ok?!

*/

/// new template with push, pop, peek
void pushspeed(uint32_t index, uint32_t w){ // we just push index
  //  
  //  gate[w].stacky[gate[w].stackindex].speedfrom= speedfromsd[index]; // TESTING new scheme
  gate[w].speedfrom[gate[w].speedfromindex] = speedfromsd[index];
  gate[w].speedfromindex = (gate[w].speedfromindex + 1) % SIZEY;
}

void pushspeedcv(uint32_t *cv1, uint32_t *cv2, uint32_t w){
  gate[w].speedfromcv1[gate[w].speedcvindex] = cv1;
  gate[w].speedfromcv2[gate[w].speedcvindex] = cv2;
  gate[w].speedcvindex = (gate[w].speedcvindex + 1) % SIZEY;  
}

funcy peekspeed(uint32_t w){ // returns a function
  uint32_t ed=(gate[w].speedfromindex - 1 + SIZEY) % SIZEY;
  return gate[w].speedfrom[ed];
}

funcy popspeed(uint32_t w){ // returns a function // but what if there is no function?
  gate[w].speedfromindex=(gate[w].speedfromindex - 1 + SIZEY) % SIZEY;
  return gate[w].speedfrom[gate[w].speedfromindex];
}

pair peekspeedcv(uint32_t w){ //returns two pointers
  pair cvs;
  uint32_t ed=(gate[w].speedcvindex - 1 + SIZEY) % SIZEY;
  cvs.cv1=gate[w].speedfromcv1[ed];
  cvs.cv2=gate[w].speedfromcv2[ed];
  return cvs;
} 

void pushbit(uint32_t index, uint32_t w){ // we just push index
  gate[w].bit[gate[w].bitindex] = bitfromsd[index]; 
  gate[w].bitindexy=index;
  gate[w].bitindex = (gate[w].bitindex + 1) % SIZEY;
}

funcy peekbit(uint32_t w){ // returns a function
  uint32_t ed=(gate[w].bitindex - 1 + SIZEY) % SIZEY;
  return gate[w].bit[ed];
}

pair peekbitcv(uint32_t w){ //returns two pointers
  pair cvs;
  uint32_t ed=(gate[w].bitcvindex - 1 + SIZEY) % SIZEY;
  cvs.cv1=gate[w].bitcv1[ed];
  cvs.cv2=gate[w].bitcv2[ed];
  return cvs;
} 

void pushbitcv(uint32_t *cv1, uint32_t *cv2, uint32_t w){
  gate[w].bitcv1[gate[w].bitcvindex] = cv1;
  gate[w].bitcv2[gate[w].bitcvindex] = cv2;
  gate[w].bitcvindex = (gate[w].bitcvindex + 1) % SIZEY;  
}

uint32_t cvpair[64][2]={ // pairs of CVs which we index into 
  {5,6}, // eg. CV and CVL
  {5,6}, // eg. CV and CVL
  {5,6}, // eg. CV and CVL
};

uint32_t (*speedff[4])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2,spdfrac2,spdfrac2,spdfrac2}; // why did we need to initialise this?

uint32_t (*bitff[8])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed,binroutfixed,binroutfixed,binroutfixed,binroutfixed,binroutfixed,binroutfixed,binroutfixed}; 

uint32_t lengthindexindex[64]={6,6,6,6,6,6,6,6}; // index into CVlist which matches function index into bitfunction array -- 6 is CVL[w]
uint32_t GSlist[64]={0,0,0,0}; // matching GS types for function index
uint32_t OUTlist[64]={0,0,0,0}; // matching OUT types for function index 

// INSIDE // OUTSIDE functions
// INSIDE flips inside IN to OUTSIDE

// need to take care of which adc and which dac!
void SR_geomanticxxx(uint8_t w){  // with stacks - we push these all in init/caput000 - seems to be working // how to make more generic!
  HEADNADA;
  static pair cvs[4];
  static pair bitcvs[8];
  
  // where do we get that speedfunc and CV indexes from - from a modeR which can allow local changes or change/move from matrices...
  // but why do we have stack... as is all fixed in this change here?
  
  if (gate[w].changedspeed){ 
    //pushspeed(gate[w].speedfunc, w); // pushes as test now in caput000
    speedff[w]=peekspeed(w);
    gate[w].changedspeed=0;
  }

  // attach 2x cv pointers which should be a pair - again abstract out how we arrive at these - 2 uint32_t pointers - lookup for these
  if (gate[w].changedspeedcv){ 
    //pushspeedcv(CVlist[w][cvpair[gate[w].speedcv][0]], CVlist[w][cvpair[gate[w].speedcv][1]], w);
    cvs[w]=peekspeedcv(w);
    gate[w].changedspeedcv=0;
  }
  
  // does it need interpol?
  if (interp[gate[w].speedfunc]){ // gate[w].func[spdfunccnt][fspeed]
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
   if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];
  
  // do speed
    if ((*speedff[w])(*(cvs[w].cv1), *(cvs[w].cv2), w)){
    LASTSPEED; // new macro to deal with lastspeed 16/6

    switch (GSlist[gate[w].bitindexy])
      {
      case 0:
	GSHIFT_;
	break;
      case 1:
	GSHIFTNOS_;
	break;
      }
	
    // CORE   
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one..
      // and do ADC
      bitn=(*adcfromsd[gate[w].adcindex])(4095-(*CVlist[w][gate[w].adccvindex]), ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too
    }
    
    // BITN
    if (gate[w].changedbit){
    //    pushbit(gate[w].bitfunc, w); // pushes chosen function onto indexy to match length etc...
      bitff[w]=peekbit(w);
      gate[w].lengthindex=lengthindexindex[gate[w].bitindexy];  // there are 64 bitfuncs - but how we access bitfunc
      gate[w].changedbit=0;
  }

    // deal with length too - length is lengthindex[stackindexfrombitfunctionbelow]
    SRlength[w]=lookuplenall[(*CVlist[w][gate[w].lengthindex])>>7];
   
    // and now we need our CVs
    if (gate[w].changedbitcv){ 
    //pushspeedcv(CVlist[w][cvpair[gate[w].speedcv][0]], CVlist[w][cvpair[gate[w].speedcv][1]], w);
    bitcvs[w]=peekbitcv(w);
    gate[w].changedbitcv=0;
  }
    
    bitn^=(*bitff[w])(*bitcvs[w].cv1, *bitcvs[w].cv2, w); // fix CVs
    // ENDCORE // what are possible OUTs? with/without DAC and     gate[w].shift_+=bitn; - we can use switch here
      switch (OUTlist[gate[w].bitindexy])
      {
      case 0:
	BITN_AND_OUTV_; // revert to this one which does not used dacfunc but gate[w].dactype which we need to set... where? TODO!
	break;
      case 1:
	BITN_AND_OUTVXOR_;
      case 2:
	BITN_AND_OUTVNOSHIFT_; // no bitn in!
	break;
      }

      new_data(val,w);
    }
}

//unused below!

  /*
typedef struct stack_ {
  uint32_t (*speedfrom)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t* speedcv1;
  uint32_t* speedcv2;
  uint32_t (*bit)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t* bitcv1;
  uint32_t* bitcv2;
  uint32_t* lencv;
  uint32_t bitindexy;
  uint32_t speedindexy;
} stack;
  */

//   {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &CVM[0], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &Gshift_[8], &gate[0].oldcv, &gate[0].oldcvl, &gate[0].oldcvm, &gate[0].adctype, &gate[0].dactype, &SRlength[0]},
// example // copy to stacky in caput000 
/*

stack stackNN[64]={ //unused and we can't copy or...
  {&spdfrac, &CV[0], &nulll, &binroutfixed, &CVL[0], &nulll, &SRlength[0], 2, 3}, // values and pointers, or even just names of function pointers so we don't lookup ... but speedindex is function index for interpoll lookup eg. spdfrac=3
};

// we need to alter to fix adc/dac parameters and selections // in stack or not
void SR_geomanticxxxx(uint8_t w){  // non-stack version with reduced index (but we use stacky as structure)
  // gate[w].stacky[gate[w].stackindex].speedfrom
  HEADNADA;
  
  // does it need interpol?
  if (interp[gate[w].stacky[gate[w].stackindex].speedindexy]){ // gate[w].func[spdfunccnt][fspeed] // bitindexy is not speedfunc
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
   if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];
  
  // do speed
    if ((*gate[w].stacky[gate[w].stackindex].speedfrom)(*(gate[w].stacky[gate[w].stackindex].speedcv1), *(gate[w].stacky[gate[w].stackindex].speedcv2), w)){
    LASTSPEED; // new macro to deal with lastspeed 16/6

    switch (GSlist[gate[w].stacky[gate[w].stackindex].bitindexy])
      {
      case 0:
	GSHIFT_;
	break;
      case 1:
	GSHIFTNOS_;
	break;
      }
	
    // CORE   
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      // TODO: adctype= // adcpar=
      ADCgeneric2; // input into shared one..
      //            bitn=(*gate[w].stacky[gate[w].stackindex].adcfunc)(4095-(*gate[w].stacky[gate[w].stackindex].adccv), ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too
      bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); // fill in regg as 3 and adcpar needs changes, length too or???
    }
    
    // deal with length too - length is lengthindex[stackindexfrombitfunctionbelow]
    SRlength[w]=lookuplenall[(*gate[w].stacky[gate[w].stackindex].lencv)>>7];
       
    bitn^=(*gate[w].stacky[gate[w].stackindex].bit)(*gate[w].stacky[gate[w].stackindex].bitcv1, *gate[w].stacky[gate[w].stackindex].bitcv2, w); // fix CVs
    // ENDCORE // what are possible OUTs? with/without DAC and     gate[w].shift_+=bitn; - we can use switch here - dac is now just dactype but where can we set this?
    // TODO: dactype= // dacpar=
      switch (OUTlist[gate[w].stacky[gate[w].stackindex].bitindexy])
      {
      case 0:
	BITN_AND_OUTV_; // revert to this one which does not used dacfunc but gate[w].dactype, dacpar which we need to set... where? TODO!
	break;
      case 1:
	BITN_AND_OUTVXOR_;
      case 2:
	BITN_AND_OUTVNOSHIFT_; // no bitn in!
	break;
      }

      new_data(val,w);
    }
}

*/


/* from segmodes

discard basic 64x64x64x64 modes with some overlap for other models...

double/ghost tail - how to do this without slowing down...

basis:
[adc/gen types/params -> bit in/prob]
speed/from
length/from
binroute/type/from -> bit in/prob
[dac out/types/interpoll]

from: CV, CVL, DAC1-4, (ADC), CLKSR/strobe, generators/which need params themselves (5th tail as further param)

prob/bitin is: CVvsDACx, CVvsLFSR, DACvsLFSR, strobe

- basic routing modes: type of binroute, permutations below,
- interpol is only for dac/ int/noint across all modes?
- leave speed. length at previous values. eg. early modes can set these quite easily

602 modes extracted: some are duplicates across L and R, also some templates etc... still...

64x4=256! 4x16=64

*what are models to choose from // for major minor modes:*

1-new geomantic/generic model

2-dacbus?  // how?

3-generic vienna model: redo with interpoll (also if this is for major/minor modes how does RSR fit with reduced bits of course?, then RSR is more like tail)

4-abstractions: list these? but still have param shortage...

5-expanded rungler model with different options and switched routings TODO

6-mishmash here: bitmodes, probmodes, recursions, esoteric modes
minor/major modes,

7-bitmodes

8-?

ghost/tails - where do we use these?

layers/hold/detach, 
modes initiate streams (below), 
all as bits and functions/gens, 

what are probable/possible recursions? of dac/sr onto ANY parameter, of dac/sr onto choice of parameter, of dac/sr onto parameter of function outputing parameter...

SR is function, SR recurs... smaller loops eg. N->L->N->C->R->N

** modeN

- too many ADC modes, how do we deal with functions and options for CV ins/params...

param from cv, dac, clkspd/clk:

eg. 

void adc95(uint8_t w){ // strobe toggle in - otherpar selects pattern which is now dac driven - 4 bits
  param[w]=gate[dacfrom[daccount][w]].Gshift_[w]>>8;
  ADCXORIN(95); 
}

standard routing - is no route in option itself or from modeR?

type of adc, type of route in!

type of adc: lists we have, type of param

also use abstract generators here...

** modeC

- no stoppage
- how many dac/options

** modeR

- null mode - 0 out = SRRnada

** LLLRRRetc

speed as CV:
[LEN,   ROUTE]
1 ['DACx', 'genCV']
2 ['DACx', 'CV']
3 ['CV', 'fixed']
4 ['fixed', 'CV']
5 ['genCV', 'fixed']
6 ['CV', 'DACx']
7 ['genCV', 'DACx']
8 ['fixed', 'genCV']

xx[LEN,   ROUTE]
1 ['CV', 'fixed']
2 ['DACx', 'CV']
3 ['fixed', 'CV']
4 ['CV', 'DACx']


genCV uses CV driven gen (which one? as we just have one CV so is fixed gen or no options: to generate route, eg. binroute)

genCV needs to generate 4 bits for route, 5 bits for len

+ type of binroute: 8 options =8x8=64!

always too many options and if we go for major/minor is too fixed...

also for abstract bitstreams we need cv to select and cv/dac as param...



 */

// for new geomantic abstraction: start again again with generics - this one for binroutes
//     [need better labelling scheme]

/*

- how that looks for inputs - what we compare to what?
- or we just have list of probs to make things easier...

- and for bits: bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;

*invert routed/bit*
*routed vs cycling// routed vs inverted cycling*
*routed vs [routed^cycling]*

 */


/*

- for speeds/bits - return bits - for adc=bits: can be adc, dac (as input with adc style processing), or bits as for speed/bits - make more generic

but speed ones handle dac/interpol

- for length: return length/0-31 - could plug in other functions
// so length as seperate or as a re-processor...

merge all bits for speeds, for adc

how to label/categorise: 

- deal with a route
- abstract bit routines
- process a value
- deal with adc
- deal with dac but:

could we even abstract out further so adc/13 is depth input - but also look at adcs
and function is a processor of these to return bits

return a value from bits (this is what dacs do)... process a value... generate a value (eg. from a route)

value to bits (adc)
bits to values (dac)

*/  

// generic probability to test for adapted rungler in // unused
static inline uint32_t genericprob(uint32_t cv, uint32_t against, uint32_t bit1, uint32_t bit2){
  if (cv>against) return bit1;
  else return bit2;
}



uint32_t funcmax[64][13]={
  {8,2,17,61,23, 11,11,11,11,11,11,11,11}, // maximum value if x>funcmax... // update these as we add more functions
};

uint32_t funcN[64][13]={
  //  {1,1,1,0,0, 5,0,6,0,6,8,0,0}, // first set is from geomantic.h with test of dacmix!
      {2,0,1,59,0, 5,6,6,0,6,8,6,7}, // for rungler with speed from R
};

uint32_t funcL[64][13]={
  //    {1,1,0,2,0, 5,0,6,0,6,0,1,0},
    {2,0,0,59,0, 5,6,6,0,6,0,6,7}, // rung2
};

uint32_t funcC[64][13]={
  //  {1,1,0,2,1, 5,0,6,0,6,0,1,0},
  {1,0,0,60,1, 5,0,6,7,0,0,4,0}, // rung - speed from cv, route from R //
};


uint32_t funcR[64][13]={
  {2,1,0,61,0, 5,6,6,0,0,0,1,0}, // route from L, speed from N
};


// counts for maps eg. routes, dacfrom, lengthfrom...
// maps below... for routes
// uint32_t *countfield[8]={&count, &daccount, &spdcount, &adccount, &dactcount, &binroutetypecount, &lengthcount};

// for functions we need to have: 

// speedfunccnt, dactypecnt, lengthfunccnt, adcfunccnt, bitfunccnt ///are indexes
// cvcount

uint32_t *funcfield[8]={&dactypecnt, &spdfunccnt, &lengthfunccnt, &adcfunccnt, &bitfunccnt, &cvcount}; // only 6 there

// TODO: versions of this...
// possibly more generic with grid of CV, CVL, DAC[x] which we index from table and pass to speedfrom/bitfroms etc????

// we already have: uint32_t *CVlist[4][16]={
//  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &gate[0].Gshift_[0], &clksr_[0]}, // etc
// so we can also index with dacfrom 0-3 as first ones
// ... but Gshift is 32 bits and clksr we don't use...

//1speed 
uint32_t speedfunc[64][4]={ 
{1,1,1,1}, // 
};

//2length
uint32_t lengthfunc[64][4]={ // these need to return a value 3->31
{1,1,1,0}, // 
};

//3adc
uint32_t adcfunc[64][4]={ 
{1,0,0,0}, // 
};

//4bits
uint32_t bitfunc[64][4]={  //  below just to test things 16 so far - but problem is it can select itself out of the equation unless all are there...
  {3,3,3,1}, // was 3,3,3,1
{3,3,4,1},
{3,3,5,1},
{3,3,6,1},

{3,3,7,1},
{3,3,8,1},
{3,3,9,1},
{3,3,10,1},

{3,3,11,1},
{3,3,12,1},
{3,3,13,1},
{3,3,14,1},

{3,3,15,1},
{3,3,16,1},
{3,3,17,1},
{3,3,18,1},
};
//......//

uint32_t whichdac[64][4]={ // some dacs use param/cv??? which -> 10,12,13,14,16
{0,0,0,0},
};

// binroutetypes is in tables.h for now

// just for speedfrom and bitfrom maybe or...
// so we need index into this list eg.

// TEST: should cvcount be for all - so is gridlike
// 4x4 - geomantic figures - now we have 6 sets here
//  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &ADCin, &Gshift_[3], &clksr_[3], &param[3]}
//   0,        1             2             3             4             5       6        7            8           9         10

uint32_t speedcvin[64][4]={ 
  {5,5,5,5}, // all CV
  {4,1,1,1}, // default - these next are from speedfrom
  {1,1,1,1}, // synced...
  {2,2,2,2}, // synced...
  {3,3,3,3}, // synced...
  {4,4,4,4}, // synced...
  {1,2,3,4}, // itself...

};

uint32_t speedcv[64][4]={ 
  {0,0,0,0}, // this is the modifier
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
};

uint32_t lengthcv[64][4]={ 
  {6,6,6,6}, // all appropriate CVL  
};

uint32_t daccv[64][4]={ 
  {0,0,0,0}, // 
};


uint32_t adccv[64][4]={ 
  {6,6,6,6}, 
};

uint32_t adccvv[64][4]={ // this is adc itself IN
  {7,0,0,0}, 
};

uint32_t bitcv[64][4]={ 
  {5,5,5,5}, // CVL for tests now = 5,5,5,5
  {4,4,4,2}, // default - brought in from dacfrom and incremented
  {2,4,2,2}, // new one for rungling 24/1/2022
  {4,1,2,3}, // from latest notebook prev ones: 3,0,1,2
  {1,2,3,4}, // itself
  {4,3,2,1}, // reverse
  {4,4,4,4},
  {3,3,3,3},
  {2,2,2,2},
  {4,4,2,2},
  {2,2,4,4},
  {3,4,1,2}, // opposites
  {2,1,4,3},
  {2,3,4,1}, // nexts
  {4,3,2,1}, /// rev
  {2,4,2,2},
  {2,4,2,2}
};

uint32_t bitcvv[64][4]={ // for comparator functions
  {0,0,0,0}
};

// speedfunccnt, dactypecnt, lengthfunccnt, adcfunccnt, butfunccnt are indexes
// cvcount

// as prototype with modeR global functions but this one can also be adapted... eg. changes of gshift etc...
// also versions with individual entries in and length etc. as just staying static...
// also use some with index as CVlist[dacfrom[w]+1] !!!
void SR_geomantic(uint8_t w){  // working now for basics
  HEADNADA;
  if (interp[speedfunc[spdfunccnt][w]]){   // pulled out interp:
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  CLKSR; // new macro deals with intflag outside speed
  if ((*speedfromsd[speedfunc[spdfunccnt][w]])(*CVlist[w][speedcvin[cvcount][w]],*CVlist[w][speedcv[cvcount][w]], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    gate[w].dactype=whichdac[dactypecnt][w]; // question of dactypes which need param/cv also
    gate[w].dacpar=*CVlist[w][daccv[cvcount][w]];
    if (lengthfunc[lengthfunccnt][w]!=0){ // so function 0 null should just hold length
    SRlength[w]=(*lengthfromsd[lengthfunc[lengthfunccnt][w]])(*CVlist[w][lengthcv[cvcount][w]],w); // lengthfunc
    }
    GSHIFT_;  // replace with types of gshift - gshiftfuncs...
    // CORE
    if (adccvv[cvcount][w]==8){ // real ADC
      ADCgeneric2; // input into shared one..
    }
    bitn=(*adcfromsd[adcfunc[adcfunccnt][w]])(4095-(*CVlist[w][adccv[cvcount][w]]), *CVlist[w][adccvv[cvcount][w]],w); // extra param which is INPUT - inverted?
    bitn^=(*bitfromsd[bitfunc[bitfunccnt][w]])(*CVlist[w][bitcv[cvcount][w]], *CVlist[w][bitcvv[cvcount][w]],w); // extra param for comparators?
    // ENDCORE
    //    if (strobey) bitn|=gate[w].trigger;	 // extra bits in if necessary or is another function
    BITN_AND_OUTV_; // pulsin is in there
    new_data(val,w);
}  
}

/*
from CVM-12 bits-> spdfunc, lengthfunc, adcfrom, bitfrom, dactype

or CVM can be xxxfuncnct - how we organise this?

// 

 */

void SR_geomanticx(uint8_t w){  // for alternative arrays... working now
  HEADNADA;
  if (interp[gate[w].func[spdfunccnt][fspeed]]){ // gate[w].func[spdfunccnt][fspeed]

    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
   if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  CLKSR; // new macro deals with intflag outside speed
  if ((*speedfromsd[gate[w].func[spdfunccnt][fspeed]])(*CVlist[w][gate[w].func[cvcount][cvspeed]],*CVlist[w][gate[w].func[cvcount][cvspeedmod]], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    gate[w].dactype=gate[w].func[dactypecnt][fdac]; // question of dactypes which need param/cv also
    gate[w].dacpar=*CVlist[w][gate[w].func[cvcount][cvdac]];

    
    if (gate[w].func[lengthfunccnt][flength]!=0){ // so function 0 null should just hold length
    SRlength[w]=(*lengthfromsd[gate[w].func[lengthfunccnt][flength]])(*CVlist[w][gate[w].func[cvcount][cvlength]],w); // lengthfunc
    }
    GSHIFT_;  // replace with types of gshift - gshiftfuncs...
    // CORE
    
    if (gate[w].func[cvcount][cvadcIN]==8){ // real ADC
    ADCgeneric2; // input into shared one..
    }
    bitn=(*adcfromsd[gate[w].func[adcfunccnt][fadc]])(4095-(*CVlist[w][gate[w].func[cvcount][cvadc]]), *CVlist[w][gate[w].func[cvcount][cvadcIN]],w); // invert?
    bitn^=(*bitfromsd[gate[w].func[bitfunccnt][fbit]])(*CVlist[w][gate[w].func[cvcount][cvbit]], *CVlist[w][gate[w].func[cvcount][cvbitcomp]],w);
    // ENDCORE
    //    if (strobey) bitn|=gate[w].trigger;	 // extra bits in if necessary or is another function
    BITN_AND_OUTV_; // pulsin is in there
    new_data(val,w);
}  
}


//enum refs {fspeed, flength, fadc, fbit, fdac, cvspeed, cvspeedmod, cvlength, cvdac, cvadc, cvadcIN,  cvbit, cvbitcomp};

/*

GRID? which needs to occupy CV and CVL

speedfroms:
whichdac:
lengthsfroms:
whichadc:
bitfromsd:
bitcv:

how to line up?

 */

/*
- what the sixteen rmodes could be to manipulate these counts: list what we manipulate here and what needs to stay in groups and 
  what can change independently

// uint32_t *countfield[8]={&count, &daccount, &spdcount, &adccount, &dactcount, &binroutetypecount, &lengthcount}; // do we use all of these?
// uint32_t *funcfield[8]={&dactypecnt, &spdfunccnt, &lengthfunccnt, &adctypecnt, &bitfunccnt}; // only 5 there

// countfield is routings, funcfield always needs to match in uses of CV - or could double up?

- we have some below. resetall is on last stop! 63

we have 8 counts we can shift independently with setall below which is clocked by strobe...
or we can have 8 functions for select...

we can bump on all, just one set/group, with strobe, with cv

binary manipulations we have below (one)

also advanced and more recursion of SR (which?) on to groups eg. we can use another speedfrom to bump on counts

 */



//prev groups

adcdraft0, adcdraft1, adcLparallel, adcLparallel2, adcLdraft2, adcnoroute0, adc0nog, adcorxor0, adcbumproute0, adcbumproutebin0, adcghostroute0, adcDACroute0, adcSRroute0, adcbin1_0, adcLCVDACroute, adcmultiplespeednew0, adcLdoublelength, adcLflip, adcLbinrstr, adcLbitprob, adcspeedstream, adcbinspeedstream, binspeedcycle, binnospeedcycle, adcLabstract, adcLabstractNOG, adcLabstractI, adcLabstractQIN, adcLTMinTM, adcLabstractTM, adcLFROM, adcLpattern95, adcLpatternbin95, adcLtm101, adcLtm102, adcLtm103, adcLtm104, adcLtm105, adcLcomp20, adcLsub92, adcLsplice100, adcLBURST0, adcLseladc, adcLcutfeedback86, adcLseladc1, adcLseladc2, adcLseladc5th, adcLseladcdac5th, adcdacmod5th, adcLpulse89, adcLSRlengthsel, adcLSRlengthsel0, adcLLswop0, adcgenericprobx, adcdacadditself0, adcdacghostitself0, adcdacghostincoming0, adcdacseladd0, adcdacseloffosc, adcdacseloffosc2, adcLrung0, adcLrung1, adcLrung2, adcrung0, adcdacadd0, adcdacaddmax0, adcdacminus0, adcdacspeedminus0, adcdacmod0, adcdacB0, adcdacoffset0, adcLdacadc, SR_binr_adc0, adc_overonebit, adcone_bitreset, adc0_newgsr, ADCovers, ADCoverss, ADCoversss, ADCoverssss, ADChold, ADCholdcycle, ADCnoisecmp, adccipher, adccipher2, noSRadc, adcLrung0, adcLrung1, adcLrung2, adcrung0, adcdacadd0, adcdacaddmax0, adcdacminus0, adcdacspeedminus0, adcdacmod0, adcdacB0, adcdacoffset0, adcLdacadc, SR_binr_adc0, adc_overonebit, adcone_bitreset, adc0_newgsr, ADCovers, ADCoverss, ADCoversss, ADCoverssss, ADChold, ADCholdcycle, ADCnoisecmp, adccipher, adccipher2, noSRadc

SR_cvbits, SRdacplusminus, SR_binr_fixed, SR_binr, SR_binr_dac0, SR_routeSRbits00, SR_routeSRbits01, SR_routeSRbits02, SR_layer12, SR_reflect, SR_altbin1, SR_binspdx, SR_insert_zero, SR_insert_zero_dac2, SRdelay_lineIN, SRintodel, SR_probbin, SRX0_newgsr, SRX0_newgsr_nores, SRholdspd, SRownspd, SR_recbin, SR_splitx, SRhold, SRholdfromdac, SRothers, SR_genspeed2, SR_genspeed3, SRghost, SRghostlatch, SRxorSR, SRxorroutes, SRaddroutes, SR_vienna, SR_switchspeed, SR_selspeed, SRprobxortog, SRprobxortogx, SRmatch, SRshare, abstractoutinterpolnoshift, abstractoutinterpol, abstractoutinterpolroute, abstractoutinterpolrung, SRmultiplespeednewdac0, SRmultiplespeednewdac, noSRdelay_line, SRdelay_lineSH, SRdelay_lineSH2, SRdelay_line, SRpattern_unshare, SRLdecaying, SRGswop, noSRselxorroutes, SRprobwheel, dacNbinprob, SRLprobnog, SRsigma, SRshiftQ1, SRsuccroute, SRNwas14, SRNprob, SRNwas15, SRN3, SRN4, SRN5, SRN6, SRN7, SRN8, SRN10, SRN11, SRN12, SRN13, SRN14, SRN15, SRN21, SRN22, SRN29, SRN30, SRN33, SRN33cipher, SRN34, SRNsr35, SRN35, SRN36, SRN38, SRN40, SRLLswop, SRN42, SRN46, SRN48, SRN50, SRN62, SRN65, SRNwas13, SRno, SR0, SR0nog, SR1, SR2, SR3, SR4, SRosc, SRmod, SRbumproute, SRLLbumproute, SRDACroute, SRSRroute, SR32, SRmultiplespeednew, SRmultiplespeed0, SRmultiplespeed1, SRmultiplespeed2


              dacNLRin, dacNLRinlogic, dacLRprob, dacLRprobxorN, dacNLRprobin1311, dacLNLRin, dacadc, dacosc0, dacLLswop, dacN, dacLBURST0, dacL16slide, dacLrung0, dacN17_0, dacN18_0, dacLDACSEL0, dacL12, dacLDACSRSEL0, dac0, dacnov0, dac0nog, dac1, dac3, dac4, dac5, dac6, dac7, dac8, dac9, dac10, dac11, dac12, dac13, dac14, dac15, dacreal15, dac17, dac18, dac19, dac20, dac21, dac67_4bits, dac67_4bitsNOGG, dac66, dac68, dacbumproute0, dacDACroute0, dacSRroute0, dac32, dacdacadditself0, dacdacghostitself0, dacdacghostincoming0, dacdacseladd0, dacdacadd0, dacdacminus0, dacdacspeedminus0, dacdacmod0, dacB0, dacdacoffset0, dacbus, dacbusothers, dacbusothers_clk, dacbusothers_sr, dacbusothers_own, noSRdac, noSRdac2sRLxor, SR_cvbits, SRdacplusminus, SR_binr_fixed, SR_binr, SR_binr_dac0, SR_routeSRbits00, SR_routeSRbits01, SR_routeSRbits02, SR_layer12, SR_reflect, SR_altbin1, SR_binspdx, SR_insert_zero, SR_insert_zero_dac2, SRdelay_lineIN, SRintodel, SR_probbin, SRX0_newgsr, SRX0_newgsr_nores, SRholdspd, SRownspd, SR_recbin, SR_splitx, SRhold, SRholdfromdac, SRothers, SR_clksrG, SR_clksr, SR_genspeed2, SR_genspeed3, SRghost, SRghostlatch, SRxorSR, SRxorroutes, SRaddroutes, SR_vienna, SR_switchspeed, SR_selspeed, SRprobxortog, SRprobxortogx, SRmatch, SRshare, abstractoutinterpolnoshift, abstractoutinterpol, abstractoutinterpolroute, abstractoutinterpolrung, SRmultiplespeednewdac0

  SR_cvbits, SRdacplusminus, SR_binr_fixed, SR_binr, SR_binr_dac0, SR_routeSRbits00, SR_routeSRbits01, SR_routeSRbits02, SR_layer12, SR_reflect, SR_altbin1, SR_binspdx, SR_insert_zero, SR_insert_zero_dac2, SRdelay_lineIN, SRintodel, SR_probbin, SRX0_newgsr, SRX0_newgsr_nores, SRholdspd, SRownspd, SR_recbin, SR_splitx, SRhold, SRholdfromdac, SRothers, SR_clksrG, SR_clksr, SR_genspeed2, SR_genspeed3, SRghost, SRghostlatch, SRxorSR, SRxorroutes, SRaddroutes, SR_vienna, SR_switchspeed, SR_selspeed, SRprobxortog, SRprobxortogx, SRmatch, SRshare, abstractoutinterpolnoshift, abstractoutinterpol, abstractoutinterpolroute, abstractoutinterpolrung, SRmultiplespeednewdac0, noSRdelay_line, SRdelay_line



// 15 octaves now
const float slowerlog[1024]  __attribute__ ((section (".flash"))) = {1.000000f, 0.989888f, 0.979878f, 0.969970f, 0.960161f, 0.950452f, 0.940841f, 0.931328f, 0.921910f, 0.912588f, 0.903360f, 0.894225f, 0.885183f, 0.876232f, 0.867371f, 0.858600f, 0.849918f, 0.841324f, 0.832816f, 0.824395f, 0.816059f, 0.807807f, 0.799638f, 0.791552f, 0.783548f, 0.775625f, 0.767782f, 0.760018f, 0.752333f, 0.744725f, 0.737195f, 0.729740f, 0.722361f, 0.715056f, 0.707826f, 0.700668f, 0.693583f, 0.686570f, 0.679627f, 0.672755f, 0.665952f, 0.659218f, 0.652552f, 0.645953f, 0.639421f, 0.632955f, 0.626555f, 0.620219f, 0.613948f, 0.607739f, 0.601594f, 0.595511f, 0.589489f, 0.583528f, 0.577627f, 0.571786f, 0.566005f, 0.560281f, 0.554616f, 0.549007f, 0.543456f, 0.537960f, 0.532521f, 0.527136f, 0.521805f, 0.516529f, 0.511306f, 0.506135f, 0.501017f, 0.495951f, 0.490936f, 0.485972f, 0.481058f, 0.476193f, 0.471378f, 0.466611f, 0.461893f, 0.457222f, 0.452599f, 0.448022f, 0.443492f, 0.439007f, 0.434568f, 0.430174f, 0.425824f, 0.421518f, 0.417255f, 0.413036f, 0.408860f, 0.404725f, 0.400633f, 0.396581f, 0.392571f, 0.388602f, 0.384672f, 0.380782f, 0.376932f, 0.373120f, 0.369347f, 0.365612f, 0.361915f, 0.358256f, 0.354633f, 0.351047f, 0.347497f, 0.343983f, 0.340505f, 0.337062f, 0.333653f, 0.330280f, 0.326940f, 0.323634f, 0.320361f, 0.317122f, 0.313915f, 0.310741f, 0.307598f, 0.304488f, 0.301409f, 0.298361f, 0.295344f, 0.292358f, 0.289401f, 0.286475f, 0.283578f, 0.280711f, 0.277872f, 0.275062f, 0.272281f, 0.269528f, 0.266802f, 0.264104f, 0.261434f, 0.258790f, 0.256173f, 0.253583f, 0.251018f, 0.248480f, 0.245967f, 0.243480f, 0.241018f, 0.238581f, 0.236169f, 0.233780f, 0.231416f, 0.229076f, 0.226760f, 0.224467f, 0.222197f, 0.219950f, 0.217726f, 0.215524f, 0.213345f, 0.211188f, 0.209052f, 0.206938f, 0.204846f, 0.202774f, 0.200724f, 0.198694f, 0.196685f, 0.194696f, 0.192727f, 0.190779f, 0.188849f, 0.186940f, 0.185049f, 0.183178f, 0.181326f, 0.179492f, 0.177677f, 0.175881f, 0.174102f, 0.172342f, 0.170599f, 0.168874f, 0.167166f, 0.165476f, 0.163803f, 0.162146f, 0.160507f, 0.158883f, 0.157277f, 0.155686f, 0.154112f, 0.152554f, 0.151011f, 0.149484f, 0.147973f, 0.146476f, 0.144995f, 0.143529f, 0.142078f, 0.140641f, 0.139219f, 0.137811f, 0.136417f, 0.135038f, 0.133672f, 0.132321f, 0.130983f, 0.129658f, 0.128347f, 0.127049f, 0.125765f, 0.124493f, 0.123234f, 0.121988f, 0.120754f, 0.119533f, 0.118325f, 0.117128f, 0.115944f, 0.114771f, 0.113611f, 0.112462f, 0.111325f, 0.110199f, 0.109085f, 0.107982f, 0.106890f, 0.105809f, 0.104739f, 0.103680f, 0.102631f, 0.101593f, 0.100566f, 0.099549f, 0.098543f, 0.097546f, 0.096560f, 0.095583f, 0.094617f, 0.093660f, 0.092713f, 0.091775f, 0.090847f, 0.089929f, 0.089019f, 0.088119f, 0.087228f, 0.086346f, 0.085473f, 0.084609f, 0.083753f, 0.082906f, 0.082068f, 0.081238f, 0.080417f, 0.079603f, 0.078798f, 0.078002f, 0.077213f, 0.076432f, 0.075659f, 0.074894f, 0.074137f, 0.073387f, 0.072645f, 0.071910f, 0.071183f, 0.070464f, 0.069751f, 0.069046f, 0.068347f, 0.067656f, 0.066972f, 0.066295f, 0.065625f, 0.064961f, 0.064304f, 0.063654f, 0.063010f, 0.062373f, 0.061742f, 0.061118f, 0.060500f, 0.059888f, 0.059283f, 0.058683f, 0.058090f, 0.057502f, 0.056921f, 0.056345f, 0.055776f, 0.055212f, 0.054653f, 0.054101f, 0.053554f, 0.053012f, 0.052476f, 0.051945f, 0.051420f, 0.050900f, 0.050385f, 0.049876f, 0.049372f, 0.048872f, 0.048378f, 0.047889f, 0.047405f, 0.046925f, 0.046451f, 0.045981f, 0.045516f, 0.045056f, 0.044600f, 0.044149f, 0.043703f, 0.043261f, 0.042823f, 0.042390f, 0.041962f, 0.041537f, 0.041117f, 0.040702f, 0.040290f, 0.039883f, 0.039479f, 0.039080f, 0.038685f, 0.038294f, 0.037907f, 0.037523f, 0.037144f, 0.036768f, 0.036396f, 0.036028f, 0.035664f, 0.035303f, 0.034946f, 0.034593f, 0.034243f, 0.033897f, 0.033554f, 0.033215f, 0.032879f, 0.032547f, 0.032217f, 0.031892f, 0.031569f, 0.031250f, 0.030934f, 0.030621f, 0.030312f, 0.030005f, 0.029702f, 0.029401f, 0.029104f, 0.028810f, 0.028518f, 0.028230f, 0.027945f, 0.027662f, 0.027382f, 0.027105f, 0.026831f, 0.026560f, 0.026291f, 0.026026f, 0.025762f, 0.025502f, 0.025244f, 0.024989f, 0.024736f, 0.024486f, 0.024238f, 0.023993f, 0.023751f, 0.023510f, 0.023273f, 0.023037f, 0.022804f, 0.022574f, 0.022346f, 0.022120f, 0.021896f, 0.021674f, 0.021455f, 0.021238f, 0.021024f, 0.020811f, 0.020601f, 0.020392f, 0.020186f, 0.019982f, 0.019780f, 0.019580f, 0.019382f, 0.019186f, 0.018992f, 0.018800f, 0.018610f, 0.018422f, 0.018235f, 0.018051f, 0.017868f, 0.017688f, 0.017509f, 0.017332f, 0.017156f, 0.016983f, 0.016811f, 0.016641f, 0.016473f, 0.016306f, 0.016142f, 0.015978f, 0.015817f, 0.015657f, 0.015498f, 0.015342f, 0.015187f, 0.015033f, 0.014881f, 0.014731f, 0.014582f, 0.014434f, 0.014288f, 0.014144f, 0.014001f, 0.013859f, 0.013719f, 0.013580f, 0.013443f, 0.013307f, 0.013172f, 0.013039f, 0.012907f, 0.012777f, 0.012648f, 0.012520f, 0.012393f, 0.012268f, 0.012144f, 0.012021f, 0.011899f, 0.011779f, 0.011660f, 0.011542f, 0.011425f, 0.011310f, 0.011195f, 0.011082f, 0.010970f, 0.010859f, 0.010749f, 0.010641f, 0.010533f, 0.010427f, 0.010321f, 0.010217f, 0.010114f, 0.010011f, 0.009910f, 0.009810f, 0.009711f, 0.009612f, 0.009515f, 0.009419f, 0.009324f, 0.009230f, 0.009136f, 0.009044f, 0.008952f, 0.008862f, 0.008772f, 0.008684f, 0.008596f, 0.008509f, 0.008423f, 0.008338f, 0.008253f, 0.008170f, 0.008087f, 0.008005f, 0.007924f, 0.007844f, 0.007765f, 0.007686f, 0.007609f, 0.007532f, 0.007456f, 0.007380f, 0.007306f, 0.007232f, 0.007159f, 0.007086f, 0.007015f, 0.006944f, 0.006873f, 0.006804f, 0.006735f, 0.006667f, 0.006600f, 0.006533f, 0.006467f, 0.006401f, 0.006337f, 0.006273f, 0.006209f, 0.006146f, 0.006084f, 0.006023f, 0.005962f, 0.005902f, 0.005842f, 0.005783f, 0.005724f, 0.005666f, 0.005609f, 0.005552f, 0.005496f, 0.005441f, 0.005386f, 0.005331f, 0.005277f, 0.005224f, 0.005171f, 0.005119f, 0.005067f, 0.005016f, 0.004965f, 0.004915f, 0.004865f, 0.004816f, 0.004767f, 0.004719f, 0.004671f, 0.004624f, 0.004577f, 0.004531f, 0.004485f, 0.004440f, 0.004395f, 0.004351f, 0.004307f, 0.004263f, 0.004220f, 0.004177f, 0.004135f, 0.004093f, 0.004052f, 0.004011f, 0.003970f, 0.003930f, 0.003890f, 0.003851f, 0.003812f, 0.003774f, 0.003735f, 0.003698f, 0.003660f, 0.003623f, 0.003587f, 0.003550f, 0.003514f, 0.003479f, 0.003444f, 0.003409f, 0.003374f, 0.003340f, 0.003307f, 0.003273f, 0.003240f, 0.003207f, 0.003175f, 0.003143f, 0.003111f, 0.003079f, 0.003048f, 0.003017f, 0.002987f, 0.002957f, 0.002927f, 0.002897f, 0.002868f, 0.002839f, 0.002810f, 0.002782f, 0.002754f, 0.002726f, 0.002698f, 0.002671f, 0.002644f, 0.002617f, 0.002591f, 0.002565f, 0.002539f, 0.002513f, 0.002488f, 0.002462f, 0.002438f, 0.002413f, 0.002389f, 0.002364f, 0.002340f, 0.002317f, 0.002293f, 0.002270f, 0.002247f, 0.002224f, 0.002202f, 0.002180f, 0.002158f, 0.002136f, 0.002114f, 0.002093f, 0.002072f, 0.002051f, 0.002030f, 0.002010f, 0.001989f, 0.001969f, 0.001949f, 0.001929f, 0.001910f, 0.001891f, 0.001872f, 0.001853f, 0.001834f, 0.001815f, 0.001797f, 0.001779f, 0.001761f, 0.001743f, 0.001725f, 0.001708f, 0.001691f, 0.001674f, 0.001657f, 0.001640f, 0.001623f, 0.001607f, 0.001591f, 0.001575f, 0.001559f, 0.001543f, 0.001527f, 0.001512f, 0.001497f, 0.001481f, 0.001466f, 0.001452f, 0.001437f, 0.001422f, 0.001408f, 0.001394f, 0.001380f, 0.001366f, 0.001352f, 0.001338f, 0.001325f, 0.001311f, 0.001298f, 0.001285f, 0.001272f, 0.001259f, 0.001246f, 0.001234f, 0.001221f, 0.001209f, 0.001197f, 0.001185f, 0.001173f, 0.001161f, 0.001149f, 0.001137f, 0.001126f, 0.001115f, 0.001103f, 0.001092f, 0.001081f, 0.001070f, 0.001059f, 0.001049f, 0.001038f, 0.001027f, 0.001017f, 0.001007f, 0.000997f, 0.000987f, 0.000977f, 0.000967f, 0.000957f, 0.000947f, 0.000938f, 0.000928f, 0.000919f, 0.000909f, 0.000900f, 0.000891f, 0.000882f, 0.000873f, 0.000864f, 0.000856f, 0.000847f, 0.000838f, 0.000830f, 0.000822f, 0.000813f, 0.000805f, 0.000797f, 0.000789f, 0.000781f, 0.000773f, 0.000765f, 0.000757f, 0.000750f, 0.000742f, 0.000735f, 0.000727f, 0.000720f, 0.000713f, 0.000705f, 0.000698f, 0.000691f, 0.000684f, 0.000677f, 0.000670f, 0.000664f, 0.000657f, 0.000650f, 0.000644f, 0.000637f, 0.000631f, 0.000624f, 0.000618f, 0.000612f, 0.000606f, 0.000600f, 0.000593f, 0.000587f, 0.000582f, 0.000576f, 0.000570f, 0.000564f, 0.000558f, 0.000553f, 0.000547f, 0.000542f, 0.000536f, 0.000531f, 0.000525f, 0.000520f, 0.000515f, 0.000510f, 0.000504f, 0.000499f, 0.000494f, 0.000489f, 0.000484f, 0.000479f, 0.000475f, 0.000470f, 0.000465f, 0.000460f, 0.000456f, 0.000451f, 0.000447f, 0.000442f, 0.000438f, 0.000433f, 0.000429f, 0.000424f, 0.000420f, 0.000416f, 0.000412f, 0.000407f, 0.000403f, 0.000399f, 0.000395f, 0.000391f, 0.000387f, 0.000383f, 0.000379f, 0.000376f, 0.000372f, 0.000368f, 0.000364f, 0.000361f, 0.000357f, 0.000353f, 0.000350f, 0.000346f, 0.000343f, 0.000339f, 0.000336f, 0.000333f, 0.000329f, 0.000326f, 0.000323f, 0.000319f, 0.000316f, 0.000313f, 0.000310f, 0.000307f, 0.000303f, 0.000300f, 0.000297f, 0.000294f, 0.000291f, 0.000288f, 0.000286f, 0.000283f, 0.000280f, 0.000277f, 0.000274f, 0.000271f, 0.000269f, 0.000266f, 0.000263f, 0.000261f, 0.000258f, 0.000255f, 0.000253f, 0.000250f, 0.000248f, 0.000245f, 0.000243f, 0.000240f, 0.000238f, 0.000235f, 0.000233f, 0.000231f, 0.000228f, 0.000226f, 0.000224f, 0.000221f, 0.000219f, 0.000217f, 0.000215f, 0.000213f, 0.000210f, 0.000208f, 0.000206f, 0.000204f, 0.000202f, 0.000200f, 0.000198f, 0.000196f, 0.000194f, 0.000192f, 0.000190f, 0.000188f, 0.000186f, 0.000184f, 0.000183f, 0.000181f, 0.000179f, 0.000177f, 0.000175f, 0.000174f, 0.000172f, 0.000170f, 0.000168f, 0.000167f, 0.000165f, 0.000163f, 0.000162f, 0.000160f, 0.000158f, 0.000157f, 0.000155f, 0.000154f, 0.000152f, 0.000151f, 0.000149f, 0.000147f, 0.000146f, 0.000145f, 0.000143f, 0.000142f, 0.000140f, 0.000139f, 0.000137f, 0.000136f, 0.000135f, 0.000133f, 0.000132f, 0.000131f, 0.000129f, 0.000128f, 0.000127f, 0.000125f, 0.000124f, 0.000123f, 0.000122f, 0.000120f, 0.000119f, 0.000118f, 0.000117f, 0.000116f, 0.000114f, 0.000113f, 0.000112f, 0.000111f, 0.000110f, 0.000109f, 0.000108f, 0.000107f, 0.000105f, 0.000104f, 0.000103f, 0.000102f, 0.000101f, 0.000100f, 0.000099f, 0.000098f, 0.000097f, 0.000096f, 0.000095f, 0.000094f, 0.000093f, 0.000092f, 0.000091f, 0.000091f, 0.000090f, 0.000089f, 0.000088f, 0.000087f, 0.000086f, 0.000085f, 0.000084f, 0.000083f, 0.000083f, 0.000082f, 0.000081f, 0.000080f, 0.000079f, 0.000079f, 0.000078f, 0.000077f, 0.000076f, 0.000075f, 0.000075f, 0.000074f, 0.000073f, 0.000072f, 0.000072f, 0.000071f, 0.000070f, 0.000070f, 0.000069f, 0.000068f, 0.000067f, 0.000067f, 0.000066f, 0.000065f, 0.000065f, 0.000064f, 0.000063f, 0.000063f, 0.000062f, 0.000062f, 0.000061f, 0.000060f, 0.000060f, 0.000059f, 0.000058f, 0.000058f, 0.000057f, 0.000057f, 0.000056f, 0.000056f, 0.000055f, 0.000054f, 0.000054f, 0.000053f, 0.000053f, 0.000052f, 0.000052f, 0.000051f, 0.000051f, 0.000050f, 0.000050f, 0.000049f, 0.000049f, 0.000048f, 0.000048f, 0.000047f, 0.000047f, 0.000046f, 0.000046f, 0.000045f, 0.000045f, 0.000044f, 0.000044f, 0.000044f, 0.000043f, 0.000043f, 0.000042f, 0.000042f, 0.000041f, 0.000041f, 0.000041f, 0.000040f, 0.000040f, 0.000039f, 0.000039f, 0.000039f, 0.000038f, 0.000038f, 0.000037f, 0.000037f, 0.000037f, 0.000036f, 0.000036f, 0.000036f, 0.000035f, 0.000035f, 0.000034f, 0.000034f, 0.000034f, 0.000033f, 0.000033f, 0.000033f, 0.000032f, 0.000032f, 0.000032f, 2.0f, 2.0f, 2.0f, 2.0f};

// 0.000032f, 0.000032f, 0.000032f, 0.000032f};
// , 2.0f, 2.0f, 2.0f, 2.0f};

const float oct4log[1024]={1.000000f, 0.997293f, 0.994594f, 0.991902f, 0.989218f, 0.986540f, 0.983870f, 0.981207f, 0.978551f, 0.975903f, 0.973261f, 0.970627f, 0.968000f, 0.965380f, 0.962767f, 0.960161f, 0.957563f, 0.954971f, 0.952386f, 0.949809f, 0.947238f, 0.944674f, 0.942117f, 0.939567f, 0.937024f, 0.934488f, 0.931959f, 0.929436f, 0.926921f, 0.924412f, 0.921910f, 0.919415f, 0.916926f, 0.914445f, 0.911970f, 0.909501f, 0.907040f, 0.904585f, 0.902136f, 0.899695f, 0.897260f, 0.894831f, 0.892409f, 0.889994f, 0.887585f, 0.885183f, 0.882787f, 0.880397f, 0.878015f, 0.875638f, 0.873268f, 0.870905f, 0.868547f, 0.866197f, 0.863852f, 0.861514f, 0.859182f, 0.856857f, 0.854538f, 0.852225f, 0.849918f, 0.847618f, 0.845324f, 0.843036f, 0.840754f, 0.838478f, 0.836209f, 0.833946f, 0.831689f, 0.829438f, 0.827193f, 0.824954f, 0.822721f, 0.820494f, 0.818273f, 0.816059f, 0.813850f, 0.811647f, 0.809450f, 0.807260f, 0.805075f, 0.802896f, 0.800723f, 0.798555f, 0.796394f, 0.794238f, 0.792089f, 0.789945f, 0.787807f, 0.785675f, 0.783548f, 0.781427f, 0.779312f, 0.777203f, 0.775100f, 0.773002f, 0.770910f, 0.768823f, 0.766742f, 0.764667f, 0.762597f, 0.760533f, 0.758475f, 0.756422f, 0.754375f, 0.752333f, 0.750297f, 0.748266f, 0.746241f, 0.744221f, 0.742206f, 0.740198f, 0.738194f, 0.736196f, 0.734204f, 0.732216f, 0.730235f, 0.728258f, 0.726287f, 0.724321f, 0.722361f, 0.720406f, 0.718456f, 0.716511f, 0.714572f, 0.712638f, 0.710709f, 0.708786f, 0.706867f, 0.704954f, 0.703046f, 0.701143f, 0.699245f, 0.697353f, 0.695465f, 0.693583f, 0.691706f, 0.689834f, 0.687967f, 0.686105f, 0.684248f, 0.682396f, 0.680549f, 0.678707f, 0.676870f, 0.675038f, 0.673211f, 0.671389f, 0.669571f, 0.667759f, 0.665952f, 0.664149f, 0.662352f, 0.660559f, 0.658771f, 0.656988f, 0.655210f, 0.653437f, 0.651668f, 0.649904f, 0.648145f, 0.646391f, 0.644641f, 0.642897f, 0.641157f, 0.639421f, 0.637691f, 0.635965f, 0.634243f, 0.632527f, 0.630815f, 0.629107f, 0.627405f, 0.625707f, 0.624013f, 0.622324f, 0.620640f, 0.618960f, 0.617285f, 0.615614f, 0.613948f, 0.612286f, 0.610629f, 0.608976f, 0.607328f, 0.605684f, 0.604045f, 0.602410f, 0.600779f, 0.599153f, 0.597532f, 0.595914f, 0.594301f, 0.592693f, 0.591089f, 0.589489f, 0.587893f, 0.586302f, 0.584715f, 0.583133f, 0.581555f, 0.579980f, 0.578411f, 0.576845f, 0.575284f, 0.573727f, 0.572174f, 0.570625f, 0.569081f, 0.567541f, 0.566005f, 0.564473f, 0.562945f, 0.561421f, 0.559902f, 0.558386f, 0.556875f, 0.555368f, 0.553865f, 0.552365f, 0.550870f, 0.549379f, 0.547893f, 0.546410f, 0.544931f, 0.543456f, 0.541985f, 0.540518f, 0.539055f, 0.537596f, 0.536141f, 0.534690f, 0.533243f, 0.531799f, 0.530360f, 0.528925f, 0.527493f, 0.526065f, 0.524641f, 0.523221f, 0.521805f, 0.520393f, 0.518985f, 0.517580f, 0.516179f, 0.514782f, 0.513389f, 0.511999f, 0.510613f, 0.509231f, 0.507853f, 0.506478f, 0.505108f, 0.503741f, 0.502377f, 0.501017f, 0.499661f, 0.498309f, 0.496960f, 0.495615f, 0.494274f, 0.492936f, 0.491602f, 0.490271f, 0.488944f, 0.487621f, 0.486301f, 0.484985f, 0.483672f, 0.482363f, 0.481058f, 0.479756f, 0.478457f, 0.477162f, 0.475871f, 0.474583f, 0.473298f, 0.472017f, 0.470740f, 0.469465f, 0.468195f, 0.466928f, 0.465664f, 0.464403f, 0.463147f, 0.461893f, 0.460643f, 0.459396f, 0.458153f, 0.456913f, 0.455676f, 0.454443f, 0.453213f, 0.451986f, 0.450763f, 0.449543f, 0.448326f, 0.447112f, 0.445902f, 0.444695f, 0.443492f, 0.442291f, 0.441094f, 0.439901f, 0.438710f, 0.437523f, 0.436338f, 0.435157f, 0.433980f, 0.432805f, 0.431634f, 0.430465f, 0.429300f, 0.428138f, 0.426979f, 0.425824f, 0.424671f, 0.423522f, 0.422376f, 0.421232f, 0.420092f, 0.418955f, 0.417821f, 0.416690f, 0.415563f, 0.414438f, 0.413316f, 0.412197f, 0.411082f, 0.409969f, 0.408860f, 0.407753f, 0.406649f, 0.405549f, 0.404451f, 0.403356f, 0.402265f, 0.401176f, 0.400090f, 0.399007f, 0.397927f, 0.396850f, 0.395776f, 0.394705f, 0.393637f, 0.392571f, 0.391509f, 0.390449f, 0.389392f, 0.388338f, 0.387287f, 0.386239f, 0.385194f, 0.384151f, 0.383111f, 0.382074f, 0.381040f, 0.380009f, 0.378980f, 0.377955f, 0.376932f, 0.375912f, 0.374894f, 0.373879f, 0.372868f, 0.371858f, 0.370852f, 0.369848f, 0.368847f, 0.367849f, 0.366853f, 0.365860f, 0.364870f, 0.363882f, 0.362898f, 0.361915f, 0.360936f, 0.359959f, 0.358985f, 0.358013f, 0.357044f, 0.356078f, 0.355114f, 0.354153f, 0.353194f, 0.352238f, 0.351285f, 0.350334f, 0.349386f, 0.348440f, 0.347497f, 0.346557f, 0.345619f, 0.344683f, 0.343750f, 0.342820f, 0.341892f, 0.340967f, 0.340044f, 0.339124f, 0.338206f, 0.337290f, 0.336377f, 0.335467f, 0.334559f, 0.333653f, 0.332750f, 0.331850f, 0.330952f, 0.330056f, 0.329163f, 0.328272f, 0.327383f, 0.326497f, 0.325613f, 0.324732f, 0.323853f, 0.322977f, 0.322102f, 0.321231f, 0.320361f, 0.319494f, 0.318629f, 0.317767f, 0.316907f, 0.316049f, 0.315194f, 0.314341f, 0.313490f, 0.312641f, 0.311795f, 0.310951f, 0.310110f, 0.309270f, 0.308433f, 0.307598f, 0.306766f, 0.305936f, 0.305108f, 0.304282f, 0.303458f, 0.302637f, 0.301818f, 0.301001f, 0.300186f, 0.299374f, 0.298563f, 0.297755f, 0.296949f, 0.296146f, 0.295344f, 0.294545f, 0.293748f, 0.292953f, 0.292160f, 0.291369f, 0.290580f, 0.289794f, 0.289009f, 0.288227f, 0.287447f, 0.286669f, 0.285893f, 0.285119f, 0.284348f, 0.283578f, 0.282811f, 0.282045f, 0.281282f, 0.280520f, 0.279761f, 0.279004f, 0.278249f, 0.277496f, 0.276745f, 0.275996f, 0.275249f, 0.274504f, 0.273761f, 0.273020f, 0.272281f, 0.271544f, 0.270809f, 0.270076f, 0.269345f, 0.268616f, 0.267889f, 0.267164f, 0.266441f, 0.265720f, 0.265000f, 0.264283f, 0.263568f, 0.262854f, 0.262143f, 0.261434f, 0.260726f, 0.260020f, 0.259317f, 0.258615f, 0.257915f, 0.257217f, 0.256520f, 0.255826f, 0.255134f, 0.254443f, 0.253755f, 0.253068f, 0.252383f, 0.251700f, 0.251018f, 0.250339f, 0.249661f, 0.248986f, 0.248312f, 0.247640f, 0.246969f, 0.246301f, 0.245634f, 0.244970f, 0.244307f, 0.243645f, 0.242986f, 0.242328f, 0.241672f, 0.241018f, 0.240366f, 0.239715f, 0.239066f, 0.238419f, 0.237774f, 0.237131f, 0.236489f, 0.235849f, 0.235210f, 0.234574f, 0.233939f, 0.233306f, 0.232674f, 0.232044f, 0.231416f, 0.230790f, 0.230165f, 0.229542f, 0.228921f, 0.228302f, 0.227684f, 0.227067f, 0.226453f, 0.225840f, 0.225229f, 0.224619f, 0.224011f, 0.223405f, 0.222800f, 0.222197f, 0.221596f, 0.220996f, 0.220398f, 0.219801f, 0.219206f, 0.218613f, 0.218021f, 0.217431f, 0.216843f, 0.216256f, 0.215671f, 0.215087f, 0.214505f, 0.213924f, 0.213345f, 0.212768f, 0.212192f, 0.211617f, 0.211045f, 0.210474f, 0.209904f, 0.209336f, 0.208769f, 0.208204f, 0.207641f, 0.207079f, 0.206518f, 0.205959f, 0.205402f, 0.204846f, 0.204291f, 0.203738f, 0.203187f, 0.202637f, 0.202089f, 0.201542f, 0.200996f, 0.200452f, 0.199910f, 0.199368f, 0.198829f, 0.198291f, 0.197754f, 0.197219f, 0.196685f, 0.196153f, 0.195622f, 0.195092f, 0.194564f, 0.194038f, 0.193512f, 0.192989f, 0.192466f, 0.191945f, 0.191426f, 0.190908f, 0.190391f, 0.189876f, 0.189362f, 0.188849f, 0.188338f, 0.187828f, 0.187320f, 0.186813f, 0.186307f, 0.185803f, 0.185300f, 0.184799f, 0.184299f, 0.183800f, 0.183302f, 0.182806f, 0.182311f, 0.181818f, 0.181326f, 0.180835f, 0.180346f, 0.179858f, 0.179371f, 0.178885f, 0.178401f, 0.177918f, 0.177437f, 0.176956f, 0.176478f, 0.176000f, 0.175523f, 0.175048f, 0.174575f, 0.174102f, 0.173631f, 0.173161f, 0.172692f, 0.172225f, 0.171759f, 0.171294f, 0.170830f, 0.170368f, 0.169907f, 0.169447f, 0.168988f, 0.168531f, 0.168075f, 0.167620f, 0.167166f, 0.166714f, 0.166262f, 0.165812f, 0.165364f, 0.164916f, 0.164470f, 0.164025f, 0.163581f, 0.163138f, 0.162696f, 0.162256f, 0.161817f, 0.161379f, 0.160942f, 0.160507f, 0.160072f, 0.159639f, 0.159207f, 0.158776f, 0.158346f, 0.157918f, 0.157490f, 0.157064f, 0.156639f, 0.156215f, 0.155792f, 0.155370f, 0.154950f, 0.154530f, 0.154112f, 0.153695f, 0.153279f, 0.152864f, 0.152450f, 0.152038f, 0.151626f, 0.151216f, 0.150807f, 0.150399f, 0.149991f, 0.149585f, 0.149181f, 0.148777f, 0.148374f, 0.147973f, 0.147572f, 0.147173f, 0.146774f, 0.146377f, 0.145981f, 0.145586f, 0.145192f, 0.144799f, 0.144407f, 0.144016f, 0.143626f, 0.143237f, 0.142850f, 0.142463f, 0.142078f, 0.141693f, 0.141310f, 0.140927f, 0.140546f, 0.140165f, 0.139786f, 0.139408f, 0.139030f, 0.138654f, 0.138279f, 0.137904f, 0.137531f, 0.137159f, 0.136788f, 0.136417f, 0.136048f, 0.135680f, 0.135313f, 0.134946f, 0.134581f, 0.134217f, 0.133854f, 0.133491f, 0.133130f, 0.132770f, 0.132410f, 0.132052f, 0.131695f, 0.131338f, 0.130983f, 0.130628f, 0.130275f, 0.129922f, 0.129570f, 0.129220f, 0.128870f, 0.128521f, 0.128173f, 0.127826f, 0.127480f, 0.127135f, 0.126791f, 0.126448f, 0.126106f, 0.125765f, 0.125424f, 0.125085f, 0.124746f, 0.124409f, 0.124072f, 0.123736f, 0.123401f, 0.123067f, 0.122734f, 0.122402f, 0.122071f, 0.121740f, 0.121411f, 0.121082f, 0.120754f, 0.120427f, 0.120102f, 0.119776f, 0.119452f, 0.119129f, 0.118807f, 0.118485f, 0.118164f, 0.117844f, 0.117526f, 0.117207f, 0.116890f, 0.116574f, 0.116258f, 0.115944f, 0.115630f, 0.115317f, 0.115005f, 0.114693f, 0.114383f, 0.114073f, 0.113765f, 0.113457f, 0.113150f, 0.112843f, 0.112538f, 0.112233f, 0.111930f, 0.111627f, 0.111325f, 0.111023f, 0.110723f, 0.110423f, 0.110124f, 0.109826f, 0.109529f, 0.109233f, 0.108937f, 0.108642f, 0.108348f, 0.108055f, 0.107762f, 0.107471f, 0.107180f, 0.106890f, 0.106600f, 0.106312f, 0.106024f, 0.105737f, 0.105451f, 0.105165f, 0.104881f, 0.104597f, 0.104314f, 0.104032f, 0.103750f, 0.103469f, 0.103189f, 0.102910f, 0.102631f, 0.102354f, 0.102076f, 0.101800f, 0.101525f, 0.101250f, 0.100976f, 0.100703f, 0.100430f, 0.100158f, 0.099887f, 0.099617f, 0.099347f, 0.099078f, 0.098810f, 0.098543f, 0.098276f, 0.098010f, 0.097745f, 0.097480f, 0.097216f, 0.096953f, 0.096691f, 0.096429f, 0.096168f, 0.095908f, 0.095648f, 0.095389f, 0.095131f, 0.094874f, 0.094617f, 0.094361f, 0.094105f, 0.093851f, 0.093597f, 0.093343f, 0.093091f, 0.092839f, 0.092587f, 0.092337f, 0.092087f, 0.091838f, 0.091589f, 0.091341f, 0.091094f, 0.090847f, 0.090602f, 0.090356f, 0.090112f, 0.089868f, 0.089625f, 0.089382f, 0.089140f, 0.088899f, 0.088658f, 0.088418f, 0.088179f, 0.087940f, 0.087702f, 0.087465f, 0.087228f, 0.086992f, 0.086757f, 0.086522f, 0.086288f, 0.086054f, 0.085821f, 0.085589f, 0.085357f, 0.085126f, 0.084896f, 0.084666f, 0.084437f, 0.084208f, 0.083980f, 0.083753f, 0.083526f, 0.083300f, 0.083075f, 0.082850f, 0.082626f, 0.082402f, 0.082179f, 0.081957f, 0.081735f, 0.081514f, 0.081293f, 0.081073f, 0.080854f, 0.080635f, 0.080417f, 0.080199f, 0.079982f, 0.079765f, 0.079549f, 0.079334f, 0.079119f, 0.078905f, 0.078692f, 0.078479f, 0.078266f, 0.078054f, 0.077843f, 0.077633f, 0.077422f, 0.077213f, 0.077004f, 0.076795f, 0.076588f, 0.076380f, 0.076174f, 0.075967f, 0.075762f, 0.075557f, 0.075352f, 0.075148f, 0.074945f, 0.074742f, 0.074540f, 0.074338f, 0.074137f, 0.073936f, 0.073736f, 0.073536f, 0.073337f, 0.073139f, 0.072941f, 0.072744f, 0.072547f, 0.072350f, 0.072155f, 0.071959f, 0.071764f, 0.071570f, 0.071377f, 0.071183f, 0.070991f, 0.070799f, 0.070607f, 0.070416f, 0.070225f, 0.070035f, 0.069846f, 0.069657f, 0.069468f, 0.069280f, 0.069092f, 0.068905f, 0.068719f, 0.068533f, 0.068347f, 0.068163f, 0.067978f, 0.067794f, 0.067611f, 0.067428f, 0.067245f, 0.067063f, 0.066882f, 0.066701f, 0.066520f, 0.066340f, 0.066160f, 0.065981f, 0.065803f, 0.065625f, 0.065447f, 0.065270f, 0.065093f, 0.064917f, 0.064741f, 0.064566f, 0.064391f, 0.064217f, 0.064043f, 0.063870f, 0.063697f, 0.063525f, 0.063353f, 0.063181f, 0.063010f, 0.062840f, 0.062670f, 0.062500f};


// but all abstractbitstreams use depth: so can pass in others not just cv... how to abstract this eg. so we can use dacfrom...
uint32_t (*bitfroms[32])(uint8_t wh)={Gbinroute}; // add in funcs which use also binroutetypecount

//uint32_t (*speedfroms[32])(uint8_t wh)={sadcfracint, sadcfrac, sdacfrac, sdacfracint, sstrobe, sstrobeint, sbinroute, sprob, sprobdac, sclksr}; // sycycle also... // expand for dacs etc...

    //    bitn=ADC_(w,SRlength[w], whichadc[adctypecnt][w],bitn,dacfrom[daccount][w],param[w], &gate[w].shift_); // as adc functions or as bitfuncs????

// now for length
static inline uint32_t lcvl(uint8_t wh){ 
  uint32_t bt=lookuplenall[CVL[wh]>>7]; // 5 bits
  return bt;
}



/*
// for manual binroute
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
*/



uint32_t neworder[4]={3,2,1,0}; // order backwards

uint32_t neworders[24][4]={
  {0,1,2,3},
  {0,1,3,2},
  {0,2,1,3},
  {0,2,3,1},
  {0,3,1,2},
  {0,3,2,1},
  {1,2,3,0},
  {1,2,0,3},
  {1,3,2,0},
  {1,3,0,2},
  {1,0,2,3},
  {1,0,3,2},
  {2,3,0,1},
  {2,3,1,0},
  {2,0,1,3},
  {2,0,3,1},
  {2,1,3,0},
  {2,1,0,3},
  {3,0,1,2},
  {3,0,2,1},
  {3,1,2,0},
  {3,1,0,2},
  {3,2,1,0},
  {3,2,0,1}  
};


static inline uint32_t adc4bits_unshare(uint32_t depth, uint8_t wh){ // use wh too so matches other gens
  uint32_t bt, k;
  static uint32_t fast=0, khh;
  static int32_t bc[4]={0,0,0,0};
  static uint32_t kh[4]={0,0,0,0};

  // run at fastest - but all of them are running this! 
  if (fast>3){  
  ADCgeneric;
  khh=k>>8;
  fast=0;
  }
  fast++;
  
  if (bc[wh]<0) {
    kh[wh]=khh;
    bc[wh]=3; 
  }
  bt = (kh[wh]>>bc[wh])&0x01; // this means that MSB comes out first
  bc[wh]--;
  return bt;
}


// was speed.h

void Ndacoffset0(void){
  uint8_t w=0;
  float speedf__;
  float mmm=(float)(1024-(CVL[0]>>2))/1024.0f;
  HEADSINN;
  tmp=(1024-(CV[0]>>2)) + (int)((float)(gate[dacfrom[daccount][0]].dac>>2)*mmm);
  if (tmp>1023) tmp=1023;
  speedf__=logspeed[tmp]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}


void Rdacadditself0(void){ // tested//trial itself as DAC - can also be other variants TODO
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[3].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacghostitself0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+((gate[3].Gshift_[routeto[count][3]])&511)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacghostincoming0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+((gate[3].Gshift_[inroute[count][3]])&511)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacseladd0(void){
  HEADR;
  uint8_t w=3;
  float speedf__;
  uint8_t whic=(CV[3]>>9)&3; //12 bits -> 2 bits
  speedf__=logspeed[(CV[3]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacadd0(void){
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[dacfrom[daccount][3]].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacminus0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[daccount][3]].dac>>2)-(1024-(CV[3]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacspeedminus0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)-(gate[dacfrom[daccount][3]].dac>>2); 
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacmod0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=((CV[3]>>2)+1); // modulo code
  speedf__=logspeed[(gate[dacfrom[daccount][3]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void RB0(void){// with oscillator
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)-(gate[dacfrom[daccount][3]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],30,gate[w].trigger,dacfrom[daccount][1],gate[w].adcpar, &gate[w].shift_); // oscillator
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// sources: adc, dac, oscillator, clock?-return last strobe, impulses(TODO) - // add in different DACs, SR bits output
// but some of these are single bits so doesn't make sense

uint32_t fadc(void){
  uint32_t k;
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_3Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  k=ADC_GetConversionValue(ADC1);
  return k;
}

uint32_t fdac(void){
  uint32_t k;
  k=gate[3].dac;
  return k;
}

uint32_t (*fff[8])(void)={fadc, fdac};

// how we can start to abstract source out - but few sources...
static inline uint32_t bits(uint32_t depth, uint8_t func){ // max 12 bits // func is index into function array
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (depth>11) depth=11; // max depth
    if (bc<0) {
      k=(*fff[func])(); // new 12 bits but only in case of adc/dac
      k=k>>(11-depth);
	bc=depth; // was 11
  }
    bt = (k>>bc)&0x01; // this means that MSB comes out first
    bc--;
    return bt;
}


/* // why we lost this?
// Nint70 - if we can change type of gate[3].dac in dac mixes 66,67,68 or pure dac ins (?)
void Nint70(void){
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    gate[3].dactype=15-(CV[0]>>8);     // 4 bits for type
    bitn=ADC_(0,SRlength[w],67,gate[w].trigger,3,gate[3].dac, &gate[w].shift_);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
*/

/*
void NLintprob084(void){ // own dac as comparator against DAC+CV 
  // can also detach length and have this as prob mode too - prob of cycle or ADC. prob of cycle or routein
  uint8_t w=0;				       
  HEADSINN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) > CVL[0])){   // thsi way round
    bitn=ADC_(0,SRlength[w],84,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);
    }
    else JUSTCYCLE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
*/


// try N0-N7 with ADCORIN() - these all fade out


  void Nor0(void){ 
  ADCORIN(0);
  }

  void Nor1(void){ 
  ADCORIN(1);
  }

  void Nor2(void){ 
  ADCORIN(2);
  }

  void Nor3(void){ 
  ADCORIN(3);
  }

  void Nor4(void){
  ADCORIN(4);
  }

  void Nor5(void){ 
  ADCORIN(5);
  }

  void Nor6(void){
  ADCORIN(6);
  }

  void Nor7(void){
  ADCORIN(7);
  }




void Ntestorxor1_0(void){ // lower bits of CVL select xor or or in  -- version 2 below makes more sense
  // speed is temp>>7 so 5 bits 0-31 so we want ((CVL[w]&64)>>6) 
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time){
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  
  if ((CVL[w]&64)>>6) {
    BINROUTEOR_;
  }
  else {
    BINROUTE_;
    }
  BITN_AND_OUTVN_;
  ENDER;
  }
}
}

void Ntestorxor2_0(void){ // - or have 2 sets of 0-31 for length or/xor
  // detach length
  uint8_t w=0;
  HEADSINN; // detach
  SRlength[w]=31-((CVL[w]>>6)%32);
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time){
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  if (((CVL[w]>>6)&32)==1) {
    BINROUTEOR_;
  }
  else {
    BINROUTE_;
    }
  BITN_AND_OUTVN_;
  ENDER;
  }
}
}


//  if (speedf_[0]==2.0f) speedf_[0]=LOWEST;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[which].dac>>2)]);

//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  // if (speedf__<LOWEST) speedf__=LOWEST;
  //  speedf__=1.0f;


// how we can OR in for route 0 - below but doesn't work so well
#define BINROUTE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }



// test logic for minor major modes
// say 4 major modes

// but how we can split modes?
major=mode[3]>>4; // from 64=6bits to 2 bits 

if (w!=3){
switch(major){
 case 0:
   // we do all modes for all except 3
   switch(mode[w]{ // or this would be a bit interpretation and we have no switch
       case 0:
	 break;
     }
   break;
     }
 }//major
 }//w!=3
 else {
   // w==3 modes
   switch(mode[3]){// here we have 16 (x4-64) minor modes for the right side...
   case 0: 
     break;
   }
 }//w==3




//unused
#define BINROUTEOR {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn|=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTELOGOP {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn=logop(bitn,bitrr,logtable[w]);			\
  }							\
  tmp=tmp>>1;						\
  }							\
  }


#define BINROUTEANDCYCLE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
    if ((tmp&0x01) || (x==w)){				\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define JUSTCYCLE {				\
  bitrr = (shift_[w]>>SRlength[w]) & 0x01;		\
  bitn^=bitrr;						\
  }


// if we go with singular defroute
#define BITNNN {								\
  bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;	\
  Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;		\
  }

//if w==3 count=0 means just to reset binroute when we are out of modes which altered it
// macro for alt routes for ADC and DAC
// try with binrouteOR
#define ADCDACETC1(X, Y){			\
  bitn=0;					\
  GSHIFT;						\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTEOR;						\
  }							\
  if (w==2)      {					\
  dactype[2]=Y;					\
  BINROUTE;						\
  }							\
}

#define ADCDACNOGS(X, Y){			\
  bitn=0;					\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTE;						\
  }							\
  if (w==2)      {					\
    dactype[2]=Y;					\
    BINROUTE;						\
  }							\
}

// we still specify type of DAC here but we leave
//  if (w==2)      {
//  BINROUTE; // TODO: substitute alt routes here for DAC. eg cycle, probability etc. 4x4 for 16-31
//  }
//  else {

// still we have DACtype here
#define ADCONLY(X, Y){						\
    bitn=0;							\
    dactype[2]=Y;						\
    if (w==3) count=0;						\
    GSHIFT;							\
    if (w==0)							\
  {								\
      bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
      BINROUTEOR;						\
  }								\
}

//// older

#define GSHIFT {				\
  counter[w]=0;					\
  Gshift_[w][0]=shift_[w];			\
  Gshift_[w][1]=shift_[w];			\
  Gshift_[w][2]=shift_[w];			\
  Gshift_[w][3]=shift_[w];			\
  shift_[w]=shift_[w]<<1;			\
}

#define GS(X) {					\
  Gshift_[X][0]=shift_[X];			\
  Gshift_[X][1]=shift_[X];			\
  Gshift_[X][2]=shift_[X];			\
  Gshift_[X][3]=shift_[X];			\
}


#define BITN_AND_OUT {						\
    shift_[w]+=bitn;						\
    dac[w]=DAC_(w, SRlength[w], dactype[w],dacpar,trigger[w]);	\
    tmp=(w<<1);							\
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}

// this one is for fractional speeds/interpol
#define BITN_AND_OUTV {				\
    shift_[w]+=bitn;						\
    val=DAC_(w, shift_[w], SRlength[w], dactype[w],dacpar,trigger[w]);	\
    tmp=(w<<1);							\
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}



    /*
  case 0: // ADc x bits out but only 12/8/4/2/1 bits
    if (length<8){ // 1 bit
      if ((shift_[reg]&(1<<length))==(1<<length)) x=4095;
      else x=0;
    }
    else x=(shift_[reg]&masky[length])>>newr[length])<<news[length];
    break;
    */
    /*
  case 0: // testing 12 bits out
    if (n[reg]>length) { // slow...
      n[reg]=0;
      //      nom[reg]=shift_[reg]&4095;
      nom[reg]=((shift_[reg]&masky[length])>>newr[length])<<news[length];
    }
    n[reg]++;
    x=nom[reg];
    break;
    */


    //    x=rand()%4095;
     /*
    if (length==3){
      if (shift_[reg]&4) x=4095;
      else x=0;
    }
    else     x=( (shift_[reg] & masky[length])>>(rightshift[length]))<<leftshift[length];
    */




void testNint(void){ // no interpolation
  uint8_t w=0;				       
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void testN(void){ // speed template
  uint8_t w=0;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVN_; // for no pulse out
    ENDER;
  }
  }
}


case 80: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(adc_buffer[12])>>(11-length);
	n[reg]=length;
    }
      bt = ((k>>n[reg])&0x01) ^ strobe; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 81: // equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      k=(adc_buffer[12]); //
      k=k/divy[length];
      n[reg]=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    bt ^= strobe;
    n[reg]++;    
    break;

  case 82: // variations on one bit audio - also phasey
    k=(adc_buffer[12]); // from 0 to 4095 but where is the middle? - also we do nothing here with length
    integrator+=(k-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }
   bt ^= strobe;
   break;    

  case 83: // basic sequential length as in 0 but with padding if >11 bits **
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	k=(adc_buffer[12])>>(11-length);
	n[reg]=length;
      }
      else {
	k=(adc_buffer[12]);
	n[reg]=11;
      }
    }
    bt = ((k>>n[reg])&0x01) ^ strobe;;
    n[reg]--;    
    break;
    
  case 84: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k=(adc_buffer[12]);
	n[reg]=11;
    }
    bt = ((k>>n[reg])&0x01) ^ strobe; // top bit first
    n[reg]--;    
    break;

  case 85: // padded version of SR of bitsin
      if (n[reg]>length) {
	if (length<12) ADCshift_[reg]=(adc_buffer[12])>>(11-length); 
	else ADCshift_[reg]=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    n[reg]++;
    bt=((ADCshift_[reg]>>length)&0x01) ^ strobe;;
    ADCshift_[reg]=(ADCshift_[reg]<<1)+bt;
    break;
    
    


// from adcetc

// 0-31 (32)modes +1 INTmode
// arrange modes now as most important first...

   
   /*  case 63: // =- input regardless of length - this was same as 5 but MSB 
    // also try as MSB - now...
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k=(adc_buffer[12]);
	n[reg]=11;
    }
    bt = (k>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;
   */

   /*
  case 64: // was strobe mode for cycling bits a la TM - no input but now uses ADC input as probability! - cvmode
    bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    if (((LFSR_[reg] & 4095 ) < adc_buffer[12])){
      bt=!bt;// invert cycling bit
    }
    break;
   */    


// 18/1/22 but we don't use this
// more generic ADC_ in = so income is passed in function and can be LFSR so we have different handlings
static inline int ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR, uint32_t *income){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator=0.0f, oldValue=0.0f;
  static uint32_t k, lastbt=0; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  static uint8_t toggle=0, lc=0;
  uint32_t bt=0, bit=0;
  float inb;

  switch(type){
    
  case 0: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(*income)>>(11-length);
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
  }
}


    /* // LSB first
  case 0: // basic sequential length of upto 12 bits cycling in    
      if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length);
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01; // this means that LSB comes out first
    n[reg]++;    
    break;
    */


    /*
  case 2: // one bit audio input - can also change the 48??? - this one makes wierd phase effects
    n[reg]++;
  if (n[reg]>48) {
    k=(adc_buffer[12]); 
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;
    */
        


    /*
  case 2: // try with float but this is the same with phasings
    inb=(((float)adc_buffer[12])/2048.0f)-1.0f; // from 0 to 4095 but where is the middle?
    integrator+=(inb-oldValue);
   if(integrator>0.0f)
  {
     oldValue=1.0f;
     bt=1;
  }
   else
   {
      oldValue=-1.0f;
      bt=0;
   }   
   break;    
    */     

   /*      
  case 3: // basic sequential length as in 0 but with padding if >11 bits **
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else {
	  k=(adc_buffer[12]);//<<(length-11); // should be -11 // pads with 0s at the bottom LSB first
	  //	  k+=((k>>length-11)&masky[length-11]); // pad with a repeat?
	  //	  k+=padding[length-11]; // TESTY! - padding with 1s
	}
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
   */

   /*
  case 3: // basic sequential length as in 0 but with padding if >11 bits **
    // REVERSAL again doesn't change much
      if (n[reg]<0) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else {
	  k=(adc_buffer[12])<<(length-11); // should be -11 // pads with 0s at the bottom LSB first
	  // double up
	  //  k+=((k>>length-11)&masky[length-11]); // pad with a repeat?
	  //	  k+=padding[length-11]; // TESTY! - padding with 1s - doesn't change much
	}
	n[reg]=length;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;    
    break;
   */
   /*
  case 3: // basic sequential length of upto 12 bits cycling in MSB first    
        if (n[reg]<0) {
	  //	  k=pow(2,length)+1;
	  k++;
	  if (k>4095) k=0;
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
   */
   /*  case 3: // basic sequential length of upto 12 bits cycling in MSB first    
        if (n[reg]<0) {
	  k=adc_buffer[12];
	  n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
   */   



/* options here:
1. 9 bit speed +dac ->   speedf__=logspeed[(CV[0]&511)+(gate[whic].dac>>3)];

2. speed+dac with max:
cv=(CV[0]>>2)+(gate[3].dac>>2);
if (cv>1023) cv=1023;
speedf__=logspeed[cv];

3. DAC - (1024-speed) // so if speed is 0-fastest 
cv=(gate[3].dac>>2)-(1024-(CV[0]>>2));
if (cv<0) cv=0;
speedf__=logspeed[cv];

4. speed-dac
cv=(CV[0]>>2)-(gate[3].dac>>2)-
if (cv<0) cv=0;
speedf__=logspeed[cv];


5. DAC % speed we have below
 */

//  if (speedf_[0]==2.0f) speedf_[0]=0.000990f;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[speedfrom_[0]].dac>>2)]);
//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  //  if (speedf__<0.000990f) speedf__=0.000990f;
  //  speedf__=1.0f;
  //  speedf__=logspeed[(CV[0]>>3)+(gate[3].dac>>3)];


void trial(void){
  static uint32_t xxxx=0;
  xxxx^=1;
  if (xxxx) gate[2].dac = 4095;
  else gate[2].dac=0;
    //  gate[2].dac=100;
}

void trial2(void){
  gate[0].dac=0;
}





// from main


older: fast interrupt (TIM?) for all shift registers with counters,
interrupt for ADCs (TIM?), interrupt for pulsed SR, PWM for
default/normed clockings (set by speed pot)

or just one timer for all and run at max speed with counters

- ADC input schemes - number of bits, sigma/delta, bit equality (unary - no weighting) with x bits
- 4x pin interrupts, how many timers
- working with sigma delta ADC, DAC out, digital filter simulator and list first all possible modes and ways of operating
- clock from speed/cv, clock from external pulse, clock from other
  shift register // combos of thse so could be ext pulse AND/XOR/OR
  other shift reg or clocked speed pulse etc.
- bitdsp library borrowings?
- fakes, ghosts, SR_IN_SR, overlaps
- add artificial drift and dropped bits

Sigma/delta out as pulses and as DAC (low pass?)


/////

TODO: new notes, collect all notes, modes and speed/basic tests

Questions: how we use the 5 fake pulse outs normed to pulse ins: PB10-PB15 ! 

Newest PCB (14/5/2021) with new ADC(ADC12//on pin PC3) TESTED ALL FINE

9/7/2021: ADC in and DAC tested correctly with 11vPP for 0-4095

14/7/2021 - retested allFINE: 

all ADC ins: mode, spd and len x4

  // map ADCs: note all modes are inverted

  // 0: nspd, 1: nlen, 2: nmode
  // 3: lspd, 4: llen, 5: lmode
  // 6: rspd, 7: rlen, 8: rmode
  // 9: cspd, 10: , 11: cmode

/ pulse ins: PC7 is RSRIN, PC8 is LSRIN XDONE

/ interrupt ins: LSR, RSR, CSR, NSR -DONE / PWM outX, pulse outsXDONE

CSRCLKIN moved from PC3 to PB7

///

Newest PCB: all working 19/4 but we will need to re-work ADC entry -
test now with lower cap on say ADC0 - nspeedin c30->100pf//33k, removed cap (but leave on schematic)
and increased ADC speed, changed to continuous mode and we have a high
sample rate in 100kHZ
 
16/4/2021->19/4/2021:

- what needs testing? DAC outDONE, ADCs inDONE, 

- all pulses in //(and volts knob for ADC pulsed in: PC9->PC14-REDO)DONE

- pulses outDONE

TIM1-CH1 normings WORKING - so is TIM1 normed to top clock/NSR

----> could do with organizing all a bit better with arrays

///


TESTED/WORKING: ADC all tested, DAC out tested, pulses out all tested, TIM1-CH1 norming to top clock, volts knob/primitive ADC, pulse ins, interrupt pulse ins 

/////////

// copied over from TOUCH so we need to change ADCsDONE, DAC out is the same, add timers and change interrupt timing, add external interrupts, PWMS.

TODO: list our new I/O here, check interrupts and PWM

- general scheme of things

///// OLDER

Testing on STM32F446 NUCLEO. Prog header is same as TOUCH. STM is same as touch

This was copied from TOUCH so some things will need to change: 

But we can keep DAC on PA4


fast interrupt (TIM?) for all shift registers with counters, interrupt for ADCs (TIM?), interrupt for pulsed SR, PWM for default/normed clockings (set by speed pot)

I/O:

- pulse ins: PC3-5 + PB6 clkins(interrupts), PC7/8 pulsein, PC9-MSB, to PC14-LSB of 6 bits
- ADC 0-11 see adc.c
- DAC out PA4
- TIM1-CH1 drived normed top LFSR - and we need 2 extra internal timers! 
- 11 pulse outs: PB2,3,4,10,12,13,14 = 5 fakes and 6 real out + now we have changed for schematic: PA11=pulse6, PA12=pulse4, PC15=pulse5, PB15=pulse7

apparently there are 12x 16bit and 2x 32 bit timers (TIM2, TIM5) 

 */

/// Copied 23/2/2021 from TOUCH code...

/*
void TIM2_IRQHandler(void) {
  // flash on update event
  if (TIM2->SR & TIM_SR_UIF) GPIOA->ODR ^= (1 << 5);
   
  TIM2->SR = 0x0; // reset the status register
  }*/



// from draftspeed:



  // crash detect ++ 32/64 in main.c is 14KHz //and/or speed check...
  //    flipper^=1;
  //  if (param[0]>4090){
  //    if (flipper) GPIOB->BSRRH = (1)<<12;  // clear bits PB12 - left normed clock I think
  //    else   GPIOB->BSRRL=(1)<<12; //  write bits   
  //  }

    /* // we don't deal with CLKs now!  
    //TODO: ghostSRs for normed clks (with speed of these from what, from RDAC?)
  if (w==2 && counter[2]>speed[w] && speedfrom[2]==1){ // 2 is Cspeed - but we have a problem when Cspeed is from an interrupt as this is never generated...FIXED HERE
      counter[2]=0;
      flipper^=1;
      if (flipper) GPIOB->BSRRH = clk_route[clkr];  // clear bits of fake_one - clkr is 7 so all of them
      // or we can set L and R from an independent SR with only CSR as clocked from here
      else   GPIOB->BSRRL=clk_route[clkr]; //  write bits       
    }
  */


  /*
  if (time_now[w]>32768){
      int_time[w]=0; 
      time_now[w]-=32768.0f;
    }

  // fixed interpol
      alpha = time_now[w] - (float)int_time[w];
      dac[w] = ((float)delay_buffer[w][DELAY_SIZE-5] * alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - alpha)); // interpol but is just last and before last
      if (dac[w]>4095) dac[w]=4095;
      else if (dac[w]<0) dac[w]=0;
      //      dac[w]=lastdac[w];

  time_now[w] += speedf_[w];
  last_time[w] = int_time[w];
  int_time[w] = time_now[w];

  if(last_time[w]<int_time[w])      {
    // do all
    // test as a function pointer
    //    mode[w]=testmodes[w];
    //    val=(*dofunc[mode[w]])(w); // this seems to work
    //    val=(*gate[L].dofunc[0])(w);
    
    GSHIFT;


void Rnofrac0(void){
  uint8_t w=3;
  HEAD;
  if (counter[3]>speed[3] && speed[3]!=1024){
    counter[3]=0;			       
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  }
}


void Cnofrac0(void){
  gate[2].dactype=0; gate[2].dacpar=param[2];
  uint8_t w=2;
  HEAD;
  if (counter[2]>speed[2] && speed[2]!=1024){
    counter[2]=0;				
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  }
}

void Lnofrac0(void){
  uint8_t w=1;
  HEAD;
  if (counter[1]>speed[1] && speed[1]!=1024){
    counter[1]=0;				
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
    }
}

void Nnofrac0(void){
  uint8_t w=0;
  HEAD;
  if (counter[0]>speed[0] && speed[0]!=1024){
    counter[0]=0;			      
    GSHIFT_;
    bitn=ADC_(0,SRlength[0],0,gate[0].trigger,3,param[0], &gate[w].shift_);    
    BITN_AND_OUTVINT_; 
  }
}



    if (w==0){
      bitn=ADC_(0,SRlength[0],0,trigger[0],reggg,adcpar); 
    }
    BINROUTE;
    if (LR[w]){
      PULSIN_XOR;
    }
    BITN_AND_OUTV; // special version for this in macros.h  
    new_data(val,w);
    //    lastdac[w]=val;
    last_time[w] += 1;
    
  } // lasttime
  */


// worm speed

if (time_now>32768){
    int_time=0; 
    time_now-=32768.0f;
    }

alpha = time_now - (float)int_time;

outt = ((float)delay_buffer[DELAY_SIZE-5] * alpha) + ((float)delay_buffer[DELAY_SIZE-6] * (1.0f - alpha)); // interpol but is just last and before last
if (outt>LIMIN) outt=LIMIN;
 else if (outt<-LIMIN) outt=-LIMIN;
out[ii]=outt;

  time_now += factor;
  last_time = int_time;
  int_time = time_now;

while(last_time<int_time)      {
    doadc();
    int16_t val=getsample();
    new_data(val);
    last_time += 1;
  }
 }
}



//    dac[2]=(adc_buffer[12]);
    /*        k=(adc_buffer[12]); // from 0 to 4095 but where is the middle?
    integrator+=(k-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=4095;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   dac[2]=bt;
    */

    //    bt = ((ADCshift_[0] >> (lfsr_taps[SRlength[0]][0])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][1])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][2])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][3]))) & 1u;
      //            bt^=1;
      //          if (rand()%4) bt^=1;

      //      ADCshift_[0]=(ADCshift_[0]<<1)+(bt&1);
      //      x=(((ADCshift_[0] & masky[SRlength[2]])<<8));//<<leftshift[SRlength[2]])&4095);//>>(rightshift[length]))<<leftshift[length];
      //      dac[2]=x;//(bt*4095);




// draft for INTmodes - - TODO: probability of advance on trigger using CV as prob
case 50:
  param[w]=adc_buffer[lookupadc[w]];
  if (trigger[w] && (shift_[LFSR[w]] & 4095) > (param[w] & 4095) ){ // or this could be based on a real: shift_[3] which we try here for better effect
    dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
    ADCDACETC1(0, 0);
    if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
      PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

// draft for CV with INT - where to place this? and we can't really use CV as param here!
case 49:
    if (counter[w]>speed[w] && speed[w]!=1024){
      if (trigger[w]){
	param[w]=adc_buffer[lookupadc[w]];// ??? use another param eg.
	dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
	ADCDACETC1(0, 0);
	if (LR[w]){
	//////////////////////////////////HERE!
	BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/////////////////////////////////////...
	PULSIN_XOR;
      } 
      BITN_AND_OUT;
    }
}
break;



/// intmodes

  case 24: // len is otherpar but there is no shift - OTHERPAR! 12 bits
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    otherpar=otherpar&31; // 5 bits
      if (n[reg]>otherpar) {
	k=adc_buffer[12]; //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
    
  case 25: // len is otherpar but there is shift from otherpar  - OTHERPAR! 12 bits
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
        otherpar=otherpar&31; // 5 bits
      if (n[reg]>otherpar) {
	if (otherpar<12) k=(adc_buffer[12])>>(11-otherpar); 
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 28:// ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) { 
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;
      }
    break;

    // we use otherpar to determine number of bits - equal or otherwise  - OTHERPAR! 12 bits
     // we can also use otherpar=CV or otherwise as padding, length of bits which is not LEN!
  case 29:   // as case 17: // basic sequential length as in 0 but with padding if >11 bist
    // maybe restrict otherpar
    otherpar=otherpar&31; // 5 bits
      if (n[reg]>length) {
	if (otherpar<12) {
	  k=(adc_buffer[12])>>(11-otherpar); //
	}
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 33: //  ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) { 
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;
      }
    else
      {
	bt=(shift_[reg]>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
      }
    break;

  case 34: // prob mode for cycling bits a la TM
    bt=(shift_[reg]>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) {
      bt=!bt;// invert cycling bit
    }
    break;
    ////////    
    // INT MODES ONLY FROM HERE ON! but these are just copies of some modes above!
     /*
  case 60: // INT // CV as comparator - for INT modes ONLY which don't use CV! can also be CV+DAC
    // we can also compare to: DAC, CV+DAC, to clksr_, to param - feed these into otherpar or have as options
     bt=0;
         if (adc_buffer[12]>adc_buffer[lookupadc[reg]]) bt=1; // can also be otherpar to make cleaner = then is same as mode 26!
     break;

  case 61:  // was case 6 //param[reg] seq input - what is size of param? /or we can also just feed in otherpar = CV in
    otherpar=otherpar>>7; // 5 bits
      if (length>11) length=11; //XXX12 bits or 8 bits
      if (n[reg]>length) {
	k=(otherpar])>>(11-length); 
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 63: // XOR or OR of case 4 - 1 bit oscillator and input bits  - OTHERPAR! 12 bits
  if (length>11) length=11;
      if (nnn[reg]>length) {
	k=(adc_buffer[12])>>(11-length); 
      nnn[reg]=0;
    }
    bt = (k>>nnn[reg])&0x01;
    nnn[reg]++;    

    otherpar=otherpar>>4; // how long? it should be?
     if (n[reg]>length) { // 0s
       bt|=0; // XOR TODO
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt|=1; // XOR TODO
       n[reg]++;
       nn[reg]=0;
     }         
     break;    
     */


     // TODO: CV+ADC as input for some of the INT modes perhaps
     // CV can modulus ADC input




case 15: // basic sequential length of upto 12 bits cycling in - leave out of cvmodes!!
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(otherpar)>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

// discard

  case 19: // sequential clksr in TESTED! - lose this one as we have 18 - clkbits in anyways
    if (n[reg]>length) {
      k=(clksr_[reg])>>(31-length); 
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;


/// strobes

  case 17: // basic sequential length of bits cycling in but zeroed by strobe
  if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    } 
     if (strobe) bt=0;
      else bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;


case 7:     // we accumulate bits onto a ghosted register
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { // strobe
      shift_[reg]&=invmasky[length]; // clear length bits
      shift_[reg]+=(ADCGshift_[reg]&masky[length]);
    }
    break;

  case 8:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa
    if (strobe) toggle^=1;

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      if (toggle) {// strobe
      bt = (k>>n[reg])&0x01;
      lastbt=bt;
      }
      else bt=lastbt;
    n[reg]++;    
    break;
    
  case 9:     // 2-we only cycle ADC on strobe/toggle  - or vice versa
        if (strobe) toggle^=1;
    if (length>11) length=11; //XXXmax12bits

  if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;

      if (toggle) {// strobe
    n[reg]++;    
      }
      break;

  case 10: // STROBE: 3-one bit entry
    if (strobe) toggle^=1;
    n[reg]++;
  if (n[reg]>50) {
    k=(adc_buffer[12]);
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   

   if (toggle) {
	lastbt=bt;
      }
      else bt=lastbt;
   break;

     case 11:// STROBE: run LFSR-ADCshift and output a bit - REGG!
       if (strobe) toggle^=1;
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;    
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

  case 12: // STROBE for other LFSR too - REGG!
    if (strobe) toggle^=1;
    bt = ((shift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;    
    break;

  case 13: // strobe moves up next LFSR ghostL tap - REGG!
    if (strobe){
      lc+=1; // or we can make this depend on...???
      if (lc>3) lc=1; 
	  ghost_tapsL[length][lc]+=1;
	  ghost_tapsL[length][lc]%=31;
	}           
    bt = ((shift_[regg] >> (ghost_tapsL[SRlength[regg]][0])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][1])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][2])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][3]))) & 1u;    
    break;

  case 21: // padded case 8    // we accumulate bits onto a ghosted register **
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); 
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { 
      shift_[reg]&=invmasky[length]; // clear length bits
      shift_[reg]+=(ADCGshift_[reg]&masky[length]);
    }
    break;

  case 22:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa **
    if (strobe) toggle^=1;
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length);
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;
      if (toggle) {
    n[reg]++;    
      }
    break;



// TESTY: testing for simultaneous shifter - but what of modes where we hold back the gshift eg. modes: 37, 48, 49
   // we need to remove all gshifts also in ADC macros
   /*   
   if (w==0){
   if (new[0]){
     new[0]=0;
     GS(0);
   }
   if (new[1]){
     new[1]=0;
     GS(1);
   }
   if (new[2]){
     new[2]=0;
     GS(2);
   }
   if (new[3]){
     new[3]=0;
     GS(3);
   }   
   }
   */

    /*
    // trial for new update plan
  case 1: // for all just pass through - ADC NONE/pass, LR pass, DAC 0/pass
    if (counter[w]>speed[w] && speed[w]!=1024){
        counter[w]=0; new[w]=1;
	shift_[w]=shift_[w]<<1;
	dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC_
	dactype[2]=0;
	ADCDACNOGS(0, 0);
	if (LR[w]){
	BINROUTE;
	PULSIN_XOR;
	}
	BITN_AND_OUT;
    }
    break;
    */


/* // basic mode to test ADC/DAC modes with equiv LR modes
 
case x:
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; par=0; // for DAC
    logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1; // logic for ops
    GSHIFT;

    if (w==0)      {
    BITNNN;
    bitn^=ADC_(w,SRlength[w],2,0); // choose mode and params - can return 0 from adc for no effect
    }
    else
    {
    BITNNN;
    }
    PULSIN_LOGOP;    
    BITN_AND_OUT;
  }// counterw
  break; 
*/


// for this macro we need  dacpar=0/whatever for DAC and adcpar is for ADC - defined outside macro
// X is adc_type, Y is dac_type
#define MULTROUTE(X, Y) {			\
  bitn=0;					\
  dactype[2]=Y;					\
  GSHIFT;						\
  if (w==0)      bitn=ADC_(0,SRlength[0],X,trigger[w],reggg,adcpar);	\
  tmp=binroute[count][w];						\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  PULSIN_XOR;						\
  BITN_AND_OUT;						\
}
//pulsin_xor above would need an if (w==1 || w==3)


// how can we abstract these out a bit so is not so many...  - for CV modes just have a few examples of each and work more with strobes

9 prob mode 0 -invcycle with dac[dacroute]
10 prob mode 1 -invcycle with param 

as above but with routed in bits too

*invcycle is more like ADC mode if is without routein*

11 prob of bitin(which?) or loopback - dac
12 prob of bitin or loopback - param  

bitins: adc-0,pulse-1,3,routein-all

pulse
routein
routein_logop_pulse 

13 inverted versions of above
14

loaded/notloaded into cycling SR
15 incoming bit = routed in 
// w==0 adc in instead of puls below (xor with 0 - mode 28 for ADC we have - XOR against loop, routed in)
16 incoming bit = pulse in (1,3)
17 incoming bit = route/
18 incoming bit = route/pulse

all x2: 2.if SR<DAC  // cv/int mode 4.if sr<CLKCNT // cv mode - we need to trim this down

   - TM: prob of bit in/inverted bit in - above (ORed with incoming bit/s: routed, ADCed, pulsed)
   - others: prob of bitin or loopback 
   - prob of bitin or inverted loopback
   [-electro: incoming bit is loaded/not loaded into cycling SR]

+++ as above but with toggles or strobes

- do we already have strobe as incoming adc or not? YES as case 17



// need to catch it but this gives us false beats
      //      if (shift_[w]==0 || shift_[w]==FULL)     shift_[w]=0x01; 

  //  cogg[w][0]=0; // if we end up using these...
  //  cogg[w][1]=0;
  //  cogg[w][2]=0;
  //  cogg[w][3]=0;

  //2-where is the input bit from (LFSR, ADC type?)- can also be from another LFSR? ADC types we have in test2.c - or no inputbit
    //    bitn=0;
      /*
    if (inputbit[w]==0){ // LFSR from SR in LFSR[w]
      bitn = ((shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][0])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][1])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][2])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][3]))) & 1u; // we would use this in final...
    }
    else if (inputbit[w]==1) {// do input from type of ADC specified
      // static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type){ // here we use length as number of bits max is 12 bits
      bitn=ADC_(w,SRlength[w],adctype[w]);
    }
    else bitn=0;
      */



// flip PB4 to test interrupt on PB7 -> CSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  // flip PB4 to test interrupt on LSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  // flip PB4 to test interrupt on  RSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   



((longer&(0b1111111111111111111111111111111100000000000000000000000000000000+othermasky[31-srlength])>>(sh-shifter))); // so this seems to work

if (coggn==0)  {// unsure of this logic
    //     shift_registerl=(shift_registerl^masky[sl])+bitn;

    tmpt=(SRlengthn-(sl-1)); // again what if sl is longer than lengthn - this is key figure
    if (tmpt<(sl-1)) tmpt=(sl-1);
    shift_registerl=((shift_registerl<<1)^masky[sl]);
	shift_registerl+=((shift_registern&(othermasky[sl-1])>>tmpt)>>tmpt);
	shift_registerl+=(bitn<<(sl-1)); // but that bit needs to be empty
	}
  // COGGN should also be x bits across!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TODO-DONE TO TEST
  else {
    // then here we want sl x bits from the top masked in
    //    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    /*    tmpt=(SRlengthn-(coggn-1))-sl;
    if (tmpt<sl) tmpt=sl;
    shift_registerl=((shift_registerl<<1)^masky[sl])+(shift_registern&othermasky[sl])>>tmpt;
    */
    //    tmpt=(SRlengthn-(sl-1)); // again what if sl is longer than lengthn - this is key figure
    tmpt=(SRlengthn-(coggn-1))-sl;
    if (tmpt<sl) tmpt=sl;
    shift_registerl=((shift_registerl<<1)^masky[sl]);
    shift_registerl+=((shift_registern&(othermasky[sl])>>tmpt)>>tmpt);
    //    shift_registerl+=(bitn<<(sl-1)); // but that bit needs to be empty
    
  }


countern++;
  if (countern>=speedn){ 
    countern=0;
    // repeat x times
    sl=moden>>2;
    tmpp=0;
    for (x=0;x<sl;x++){
      bitn = (((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u); // 32 is 31, 29, 25, 24
      tmpp+=bitn<<x;
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    }
    coggn=0;
    bitn=tmpp;
  }
//  }
  
    // test pulse ins   // inpulse interrupts to attach are: CSR: PC3, NSR: PC4, RSR: PC5, LSR: PB6
    // PC7/8 pulsein (RSR-7/LSR-8), PC9-MCB, to PC14-LSB of 6 bits
    
    // test in gives out on PB4 - always inverted...
    //    if ((GPIOC->IDR & (1<<7)))  GPIOB->BSRRH = (1)<<4;  // clear bits PB4
    //    else   GPIOB->BSRRL=(1)<<4; //  write bits   
    //  if (k==0) k=4095;
    //  else k=0;
    //  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    //  ADC_SoftwareStartConv(ADC1);


//k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!

// OLD BITS DAC STUFF!!

  //  k=4095-k;
  //  k=rand()%4095;
  //  k++;
  //  if (k>4095) k=0;
  //    k=(((GPIOC->IDR & (1<<9)))<<11) + (((GPIOC->IDR & (1<<10)))<<9) + (((GPIOC->IDR & (1<<11)))<<7) + (((GPIOC->IDR & (1<<12)))<<5) + (((GPIOC->IDR & (1<<13)))<<3) + (((GPIOC->IDR & (1<<14)))<<1) ;//  - 2048;// probably easier way to do this
  // check each one
  //  k=((!(GPIOC->IDR & (1<<14)))<<11); //14 haas issues
  //  k=(1<<11); //puts us in middle
  //      k=4095; // with
	//  k=4000; // with R35 as 150k and R34 as 66.5k we have 4095 as -4.96 and 0 as 5.6k // 180k puts us opposite (-5.6) so we need like 160k
  // we leave buffer on DAC or these values change
  //  k=rand()%4095;




  // http://www.danbullard.com/dan/A_Sigma_Delta_ADC_Simulator_in_C.pdf
  // https://www.mikrocontroller.net/topic/293454

      
  // outPUT
  //DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  // j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

  //  if(ll)      GPIOB->BSRRH = (1)<<4;  // clear bits PB4
  //  else   GPIOB->BSRRL=(1)<<4; //  write bits 
  //  ll^=1;


RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // TEST - PC8 input from 40106 for freezing/rec/play etc. power it with 3.3v

  // led first
  //  GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output

  // internal DAC PA4 with multiplex with EN_LOW1 on PC11 and sel1/2/3 on PC13/14/15


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);



  // led first
  //  GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output


  //    io_config2 ();
    //DAC_Cmd( DAC_Channel_2, ENABLE);
    //    DAC_Cmd( DAC_Channel_1, ENABLE);

    // set enable=say 13 and 14 pin (active LOW) and pins for 4051: PB8,9,10

    /* TODO: testing for external DAC such as MPC492X (one or two DACs) - test with 4922

- setup SPI on SPI2 or SPI3 (SPI1 would conflict with ADC ins)
- communicate with DAC1 and test 
    */

	    /*
	    int main(void)
{
  // this is for flashing onboard LED LD2 on pin PA5

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // enable the clock to GPIOD
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // enable TIM2 clock
     
    GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output
     
    NVIC->ISER[0] |= 1<< (TIM2_IRQn); // enable the TIM2 IRQ
     
    TIM2->PSC = 0xff; // no prescaler, timer counts up in sync with the peripheral clock
    TIM2->DIER |= TIM_DIER_UIE; // enable update interrupt
    TIM2->ARR = 0xffff; // count to 1 (autoreload value 1)
    TIM2->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // autoreload on, counter enabled
    TIM2->EGR = 1; // trigger update event to reload timer registers
      
    while (1);
}
	    */


	          // test SPI comms - what message to send a value to the DAC1!?
      // from arduino code: https://github.com/michd/Arduino-MCP492X/blob/master/MCP492X.cpp
      //      value=k;
      
      //      delay();
      // flip-flop from PC8
      //      GPIOA->ODR ^= (1 << 5);      

      /*
      
      if (GPIOC->IDR & 0x0100){ // pin 8 
      if (flipped==0) {
	flipped=1;
	prev_state=0;
      }
	}
	else flipped=0;
	  
	if (flipped==1 && prev_state==0)
	  {
	  prev_state=1;
	  GPIOA->ODR ^= (1 << 5);
	  }
      */
      
      /// multiplex and DAC tests
            
      //    GPIOB->ODR = 0b0000000100000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    // Y1 is S1 on 4051 high which is 11 on 4051 which is pin PB8
      /*      otherk++;
      if (otherk>32){
	otherk=0;
      k++;
      if (k>4095) k=0;
      }*/
      //      k=0;
      //    DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
      //    j = DAC_GetDataOutputValue (DAC_Channel_1);
    //    delay();
    //    GPIOB->ODR = 0b0000000000000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    //    DAC_SetChannel1Data(DAC_Align_12b_R, 4095-k); // 1000/4096 * 3V3 == 0V8
    //    j = DAC_GetDataOutputValue (DAC_Channel_1);
    //    delay();

	        GPIO_InitTypeDef GPIO_InitStructure;
    
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

