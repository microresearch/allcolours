//- TODO: fill in and simplify geoC according to 16/16/16/16 modes

// CC: dactype and param, probs or route/etc, routes, speed mods as primary

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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

void SR_geo_outer_route(uint32_t w){  // fixed route // the most basic but no reset
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // speed
  gate[w].inner=SR_geo_inner_globalC; // global route
}

// list modes.
//eg. 00: myroutereset, 01: global route 02: prob of... etc...-> probs to later

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobeindex, 16type, 17route

void SR_geo_outer_C00(uint32_t w){  // set dactype, spdfrac, fixed route 
  if (gate[w].changed==1) RESETC; // added 21/12 only reset on change 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[13]=CVL[w]; // dactype
  gate[w].inner=SR_geo_inner_routeC; // routetype/theroute 
}

void SR_geo_outer_C01(uint32_t w){ // globalroute/dacparam...
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[14]=CVL[w]; // set dacparam
  gate[w].inner=SR_geo_inner_globalC; // routetype/but globalroute
  }
}

void SR_geo_outer_C02(uint32_t w){ // change type. theroute
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // zbinrout - with theroute 
  //  gate[w].matrix[4]=CVL[w]; //
  SETROUTETYPECV;
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; // also test genericise the function
  }
}

void SR_geo_outer_C03(uint32_t w){ // change route. gapped type
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // zbinrout - with theroute 
  //  gate[w].matrix[4]=CVL[w]; //
  SETROUTECV;
  gate[w].funcbit=routebits_typesz;
  gate[w].extent=6; // 6 bits above
  gate[w].inner=SR_geo_inner_function; // also test genericise the function
  }
}
// 0 above
// check geoC
// 1- length, dacpar as dacfrom, length as dacfrom, depth is dac - what we do with CV?
// 2- probs with types and routes...? fixed function
/* probs
01 prob eg. of inversion=prob1=5
02 fixed vs. cycle prob - as function:  prob2=33
03 fixed vs. [fixed XOR cycle prob] - as function: prob4=35
04 ????

*/

// 3- select function//length, dacpar, depth is dac (but what of in?) // what of 


