// test functions include also debug function

extern void send_command(int command, void *message);

void SR_geo_outer_testabstracts(uint32_t w){ // change function. don't care on depth or nots
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=36<<7; // function  select
  gate[w].matrix[4]=CVL[w];
  gate[w].matrix[5]=(gate[dacfromopp[daccount][w]].dac); // cv2
  gate[w].funcbit=abstractbitsz; // max 39
  gate[w].extent=7; // 
  gate[w].inner=SR_geo_inner_function; 
  }
}

// - *test new prob <24 funcs with top speed and CV as sel*
void SR_geo_outer_test24(uint32_t w){ // new inner function. now new function for depth as param <24 and > is prob function of xor cycle
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  //  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[1]=0;
  gate[w].matrix[3]=CV[w]; // select
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=(gate[dacfrom[daccount][w]].dac); // cv2
  gate[w].funcbit=routebits_typeszz; //new one // alts: routebits_nodepth_typesz[64] >>6 extent and routebits_depth_typesz[32]  >>7 extent // trial these
  gate[w].extent=6; // 6 bits above

  gate[w].matrix[9]=0<<7; // select probfs - zinvprobbits here against LFSR__
  gate[w].matrix[10]=CVL[w]; // probCV1

  gate[w].inner=SR_geo_inner_functionprob1; // 
  }
}

void SR_geo_inner_testfunctionC(uint32_t w){  // test our full 64 functions
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

void SR_geo_inner_test(uint32_t w){  // new abstraction
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
	bitn=(*routebitsnostrobe[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // TODO: update those routebits
	//	bitn=0;
      }
      else {
       	bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
      }

      BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


char buffx[10];

void SR_geo_outer_probofdacout(uint32_t w){  // gaps
  if (gate[w].changed==0) { 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
    gate[w].matrix[9]=0<<7;//CVL[w];  // ????
    gate[w].matrix[10]=CVL[w];//(gate[dacfrom[daccount][w]].dac);
    //    gate[w].matrix[11]=LFSR__[w];// used... but is also bits???
     
    gate[w].inner=SR_geo_inner_probofdacoutC; // can use IN -> 11...
  }
}

void SR_geo_outer_testfunctions(uint32_t w){
  uint32_t mod;
  static uint32_t oldmod=1;
  if (gate[w].changed==0) {
  gate[w].matrix[0]=0<<7; // spdfrac
  // gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[1]=0; // top speed
  //  gate[w].matrix[3]=7<<6; //6 bits = 64 functions // max 81 functions to test
  //  gate[w].matrix[4]=CVL[w];
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;  // IN
  gate[w].matrix[3]=CV[w];

  //  =(mod)<<6;

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
