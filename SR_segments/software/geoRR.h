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

void SR_geo_inner_function_glob(uint32_t w){  // new abstraction needs gate[w].funcbit->function array, and extent as >>howmany // depth and in speed loop
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      (*globalls_depth[glob>>8])(gate[w].matrix[19]);
      gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
    bitn=(gate[w].funcbit[gate[w].matrix[3]>>gate[w].extent])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_function_globoutside(uint32_t w){  // new abstraction needs gate[w].funcbit->function array, and extent as >>howmany // depth and outside speed loop
  HEADNADA;
  (*globalls_depth[glob>>8])(gate[w].matrix[19]);

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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

//0.0////////

void SR_geo_outer_R00(uint32_t w){  // set length // set length or could better be TYPE
  if (gate[w].changed==1) {
    RESETR; // added 21/12 only reset on change
    gate[w].changed=0;
  }
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_globalC; //
}

// REDO from here! - abstracts etc. from NN once tested

/* and list how they crossover

R00: above
R01: N02 - abstract
R02: N03 - abstract/depth
R03: Nxx - route in only

// abstract ^ route, route types, length, route functions

// also probs route vs cycle can work here... from CC

 */

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// start to draft globals - they gap last function except not probs of course - so we need to set speed and provide speed CV and CV2 for bits

/*
void (*globalls[20])(uint32_t depth)={resett, binaryN, binaryX, SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalbumpspd, SRRglobalbumpcv, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalsync, SRRglobalorder, SRRglobalbumpbit0, SRRglobalbumpbit1, SRRglobalbumpbit2, SRRglobalorderbumpS, SRRglobalorderbumpbit, SRRglobaltailset}; 
 */

// convert these to be mlre generic with function_glob // inner and outer also functiongapped_globs
void SR_geo_outer_Rtail(uint32_t w){ 
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=8<<8; //     //SRRglobaltailset(CVL[w]);
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside;
  }
}

void SR_geo_outer_Rorder(uint32_t w){
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    glob=7<<8;    //    SRRglobalorder(CVL[w]);
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_globoutside;  
  }
}

// but set should be in inner speed no? in some cases eg. binaryN
void SR_geo_outer_Rbinary(uint32_t w){
  if (gate[w].changed==0) {
    gate[w].matrix[1]=CV[w];// speed 
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
    // set global fixed or select... eg.
    //    binaryN(CVL[w]);
    glob=1<<8;
    gate[w].matrix[19]=CVL[w];
    gate[w].inner=SR_geo_inner_function_glob; // uses depth
  }
}

// also with DACfrom for [19] CV entry
