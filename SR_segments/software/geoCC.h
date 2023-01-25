//- TODO: fill in and simplify geoC according to 16/16/16/16 modes

extern void send_command(int command, void *message);


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

void SR_geo_inner_testfunctionC(uint32_t w){  // test our full 81 functions
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
    bitn=(*routebits_typesz[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64 // some use IN?
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_test(uint32_t w){  // test flip flop and also new abstraction - need to >>7 stored
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


// TODO test prob CV - choose simplest prob and test against CV // also just to re-acquaint with probs...
// probfsins[32] >>7
/*
zprobbits(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode
  uint32_t bt=0;
  if (depth>LFSR__[w]) bt=1; // changed direction
  return bt;
}
*/

void SR_geo_inner_probz(uint32_t w){  // re-acquaint basic probability function
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
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7];

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){ // 1 is zprobbits which is against LFSR
      bitn=(*routebits_typesz[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); 
  }
  else {
    bitn=(*routebits_typesz[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_prob_strobez(uint32_t w){  // straight strobe and prob - includes fixed routes // from geoc.h
  HEADNADA;

    if ((*speedfromstrobe[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=1;
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1];  
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 
      if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	//	bitn=(*routebitsnostrobe[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // TODO: update those routebits
	bitn=0;
      }
      else {
       	bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
      }

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
//eg. 00: myroutereset, 01: global route 02: prob of... etc...

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobeindex, 16type, 17route

// should this be global (which can change... or local which is itself reset)
// TODO: change to local...
void SR_geo_outer_C00(uint32_t w){  // set dactype, spdfrac, fixed route // RESETR - no need for changed
  if (gate[w].changed==1) RESETC; // added 21/12 only reset on change 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[13]=CVL[w]; // dactype
  gate[w].inner=SR_geo_inner_routeC; // fixedtype/theroute
}

void SR_geo_outer_C01(uint32_t w){ 
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[14]=CVL[w]; // set dacparam
  gate[w].inner=SR_geo_inner_globalC; // fixedtype/globalroute
  }
}

char buffx[10];

void SR_geo_outer_testfunctions(uint32_t w){
  uint32_t mod;
  static uint32_t oldmod=1;
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  // gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[1]=0; // top speed
  //  gate[w].matrix[3]=7<<6; //6 bits = 64 functions // max 81 functions to test
  gate[w].matrix[4]=CVL[w];
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;  // IN
  mod=(CV[w]>>6)+63;

  gate[w].matrix[3]=(mod)<<6;

  if (mod!=oldmod){
  itoa(mod, buffx, 10);
  uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char) - 1 };
  send_command(0x05/* some interrupt ID */, m);
  }
  oldmod=mod;
  

  if (depth_routebits_typesz[gate[w].matrix[3]>>6]) gate[w].matrix[4]=CVL[w]; // bit cv
  else SETROUTECV; // 
  gate[w].inner=SR_geo_inner_testfunctionC; 
  }
}

// function to test 1v/oct - flipflop
void SR_geo_outer_testvoct(uint32_t w){  
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=20<<7; // flipflop
  gate[w].matrix[4]=CVL[w]; // bit cv
  gate[w].matrix[5]=0; // >IN
  gate[w].funcbit=abstractbitsz;
  gate[w].extent=7; // 5 bits above
  gate[w].inner=SR_geo_inner_test; // also test genericise the function
  }
}

// re-acquaint with prob but we want CV prob with strobe now
void SR_geo_outer_testprob(uint32_t w){ 
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; //Zbinrout with default route
  gate[w].matrix[9]=1<<7;//zprobbits vs LFSR
  gate[w].matrix[10]=CVL[w]; // probability vs..
  gate[w].matrix[12]=3<<6;//altfunction
  
  //  gate[w].matrix[4]=CVL[w]; // bit cv
  gate[w].inner=SR_geo_inner_probz; 
  }
}

void SR_geo_outer_testprobstr(uint32_t w){
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<8; // strobe
  //  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=1<<6; //Zbinrout with default route
  gate[w].matrix[9]=1<<7;//zprobbits vs LFSR
  gate[w].matrix[10]=CV[w]; // probability vs..
  
  //  gate[w].matrix[4]=CVL[w]; // bit cv
  gate[w].inner=SR_geo_inner_prob_strobez;
  }
}


// TODO: fill some first 16 modes fixed probs????
