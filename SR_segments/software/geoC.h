/*

For lower mode C: 16x4 modes

3/11/2022: TODO: check all array access and <<7 <<6 etc

- fill in gaps/sketch out... 11/10/2022
-  basic inner x4
-  set DAC, set dacparam, what else needs to be set...

// dactype, dacpar, {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, // for probs: 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}


- no endfrac/ending for modeC 
- no abstract modes

geomantic figures:

1- via


16- populus

odd symmetrics:

+                  -
1 - puer            14 - puella 
2 - laetitia        8  - tristitia // alien, pagan, outside, black death
3 - caput draconis/head  13 - cauda draconis/tails
4 - albus           7  - rubeus

even symmetrics:

5 - via/route              16 - populus
6 - amissio          15 - acquisito
9 - fortuna minor    12 - fortuna major
10- carcer // prison/locked  11 - conjunctio/joining

but what is ordering?

 */

/// INNER

// try with interpoll
void SR_geo_inner_noprobC(uint32_t w){  // no probability, no adc - this can be generic
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
    bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// test list of route arrays
uint32_t (**routetest[64])(uint32_t depth, uint32_t in, uint32_t wh)={routebitsd}; // all need to be same length

void SR_geo_inner_noprobTEST(uint32_t w){  // test for array of 
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
    //    bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    bitn=(*routetest[0][gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_noprobfixeddepthC(uint32_t w){  // no probability, no adc - this can be generic
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
    bitn=(*routebitsfixeddepth[gate[w].matrix[3]>>7])( (binroute[count][w]|binary[w])<<8, gate[w].matrix[5], w); // there are 32 >>7 // <<8 fixed here 13/12
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_noprobnodC(uint32_t w){  // no probability, no adc - this can be generic
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
    bitn=(*routebitsnod[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); // >>7 as 32
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_fixedC(uint32_t w){  // fixed route only - no probability, no adc - this can be generic
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
    //    bitn=(*routebits[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    //    bitn=binroutfixed(0,0,w); // but we could set type?
    bitn=binroutesel0(0,0,w); // now uses routetype
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_fixedprobC(uint32_t w){  // fixed route only - prob if we have CV free from speed CV[w] speednoin==0
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
    //    bitn=(*routebits[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    if (speednoin[w]==1) bitn=binroutfixed(0,0,w);
    else { // use CV for prob of bitn vs cycle...
      if (CV[0]<LFSR__[w])     bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

/*
    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*routebits[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // so we can have some fixed - 4 is cycle
  }
  else {
    bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
 */

void SR_geo_inner_noprob_routeprobC(uint32_t w){  // no probability, no adc - this can be generic - for routeprobarray
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
    bitn=(*routebitsnostrobedepthprob[gate[w].matrix[3]>>8])(gate[w].matrix[4], gate[w].matrix[5], w); // 16 only
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// for binr and types
void SR_geo_inner_binrC(uint32_t w){  // no probability, no adc - this can be generic
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
    bitn=(*routebitsfortypes[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); // >>7 as 32
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

/*

catalogue probs:

SR_geo_inner_probofdacoutC: probfsins

strobespeeds: // checked
SR_geo_inner_prob_ifstrobeC: probfsinnostrobe
SR_geo_inner_prob_strobeC: probfsinnostrobe
SR_geo_inner_prob_strobedepthC: probfsinnostrobe
SR_geo_inner_prob3_strobeC: probfsinnostrobe

others:
SR_geo_inner_prob1C: probfsins
SR_geo_inner_proballC: probfsinsstrobeall - new one
SR_geo_inner_prob2C: probfstrobes - probfromstrobes
SR_geo_inner_prob3C: probfstrobes

 */

//*can we also have prob of a dac out aside from SR operations? - no interpoll*
void SR_geo_inner_probofdacoutC(uint32_t w){  // no probability, no adc - this can be generic // no interpoll
  HEADNADA;
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); //>>6 as 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)) gate[w].dac = delay_buffer[w][1];
    }
}

// NON!
/*
void SR_geo_inner_noprob_strobe(uint32_t w){   // no use of CV really as we don;t want as type
  HEADNADA;

    if ((*speedfromstrobe[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1];  
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}
*/

//- example of how we deal with strobe free up!? as prob 
void SR_geo_inner_prob_ifstrobeC(uint32_t w){  // UNUSED? so far - can be fixed routes
  HEADNADA;

    if ((*speedfromstrobe[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=1;      
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1];  
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    if (usedstrobe[gate[w].matrix[15]>>7]) {
      bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);//?
    }
    else { // do prob thing as we have a CV
      if ((*probfsinnostrobe[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(*routebitsnostrobe[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // now with depth....
      }
      else {
	bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
      }
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_prob_strobeC(uint32_t w){  // straight strobe and prob - includes fixed routes
  HEADNADA;

    if ((*speedfromstrobe[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=1;
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1];  
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
      if ((*probfsinnostrobe[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(*routebitsnostrobe[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // now with depth....
      }
      else {
	bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
      }

      BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_prob_strobedepthC(uint32_t w){  // straight strobe and prob - includes fixed routes
  HEADNADA;

    if ((*speedfromstrobe[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=1;
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1];  
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
      if ((*probfsinnostrobe[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	bitn=(*routebitsnostrobe[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // now with depth....
      }
      else {
	bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
      }

      BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// prob of use of CV or use of dacfrom!
void SR_geo_inner_prob3_strobeC(uint32_t w){ // as above but with strobe for speed to free up CV for prob
  HEADNADA;

  if ((*speedfromstrobenodepth[gate[w].matrix[15]>>8])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
          gate[w].fake=1;
    GSHIFT_;
    gate[w].dac = delay_buffer[w][1]; // dac moved inside strobe
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfsinnostrobe[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[dacfrom[daccount][w]].dac, gate[w].matrix[5], w); // only makes sense if matrix[4] was CV - to trial with probbits
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_prob1C(uint32_t w){  // TESTY - using probfsins - ported in from speeds
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

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*routebits[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // so we can have some fixed - 4 is cycle
  }
  else {
    bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

//how we can mix prob from strobes/no depth with prob which uses depth ??? what to use optional depth as/// length? do as 64=
//uint32_t (*probfsinsstrobeall[64])
void SR_geo_inner_proballC(uint32_t w){  // TESTY - using all inc strobe UNUSED SO FAR!
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
    if (unuseddepth[gate[w].matrix[9]>>6]) SRlength[w]=lookuplenall[gate[w].matrix[10]>>7]; // use CV or whatever as depth if unused

    if ((*probfsinsstrobeall[gate[w].matrix[9]>>6])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*routebits[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // so we can have some fixed - 4 is cycle
  }
  else {
    bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


void SR_geo_inner_probcycleC(uint32_t w){  // TESTY - using probfsins - ported in from speeds -> basic gapped cv binroute against justcycle! // unused so far
  // what cv we need: probfs: 9type,10comp... 11IN 3,4,5 is gapped...
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

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
      bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // no fixed ones, all depth - gapped binroute [3]
  }
  else {
    bitn=(*routebitsnod[0])(0,0, w); // justcycle is 0! fixed
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_prob2C(uint32_t w){  // TESTY - ported in using strobes/no depth
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

    if ((*probfstrobes[gate[w].matrix[9]>>8])(0, 0, w)){ // no depth needed
    bitn=(*routebitsnostrobe[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// meta-level of prob to use x or y param (eg. use DAC or CV or) -> further matrix ops*
// but to test prob3 we need cv for prob and cv for bit function ie. fixed route does nothing - we need 2 cvs...
// so we either have strobe speeds or strobe probs... test latter now
void SR_geo_inner_prob3C(uint32_t w){
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[15]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfstrobes[gate[w].matrix[9]>>8])(0, 0, w)){ //there are 16 - no depth/in
    bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
  else {
    tmp=daccount+1;
    if (tmp>15) tmp=0;
    bitn=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[dacfrom[tmp][w]].dac, gate[w].matrix[5], w); // only makes sense if matrix[4] was CV - to trial with probbits
  } // we suggest using different dacfrom index... as they cannot be the same.
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// ported in from geomantic.h -> pair and test with outers

// from toport.h
void SR_geo_innerNOSC(uint32_t w){   // GSHIFTNOS_; no shift // shift on tirgger or full speed
  HEADNADA;
  gate[w].dac = delay_buffer[w][1]; //TODO: or trigger
  //
  gate[w].shift_=gate[w].shift_<<1; 
  
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    GSHIFTNOS_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

//////////////////// trigger versions from toport.h but trigger/<<1 should not be a strobe mode

void SR_geo_innersplit1C(uint32_t w){   // STROBE - not as strobe mode then where to place? instead of NOS above? UNUSED so far
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

  if (gate[w].trigger) gate[w].shift_=gate[w].shift_<<1; 
  
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    GSHIFTNOS_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inner_split2C(uint32_t w){  //strobe no mode UNUSED so far
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  if (gate[w].trigger){
    GSHIFT_;
  }
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
     SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inner_split3C(uint32_t w){  //strobe - could be strobe mode? uses CV UNUSED so far
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    //    gate[w].fake=gate[w].trigger;
    GSHIFT_;
  }
  if (gate[w].trigger){
     SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

///////////////////

void SR_geo_innerxorC(uint32_t w){  // xor with fixed route - but we don't track cv???
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ( (*speedfromcvforxor[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w) ^ speedfromforxor[0](0,0,w) ){ // speedfunc xor with fromforxor->binroutfixed...
    gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn=(*routebitsd[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rung0C(uint32_t w){  // no probability, no adc - this can be generic // no interp
  HEADNADA;
  if ((*speedfromnosdac[gate[w].matrix[0]>>9])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].fake=gate[w].trigger;
    gate[w].dac = delay_buffer[w][1];
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    //    bitn^=(*routebitsfortypes[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    bitn=(*bitfromalldepth[gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); //64 >>6
    bitn^=(*routebitsnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done

    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_rung1C(uint32_t w){  // no prob // no adc -- run binrout fixed at full speed // no interp
  HEADNADA;
  
  bitn=binroutfixed(0,0,w);

  if ((*speedfromnosdac[gate[w].matrix[0]>>9])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    gate[w].dac = delay_buffer[w][1];
    gate[w].fake=gate[w].trigger;
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[5], gate[w].matrix[4], w); // problem is same CVs - or switch round//done

    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// 16/12 draft list of inners;;;   void (*inner)(uint32_t w);
void (*SRinnersC[64])(uint32_t w)={SR_geo_inner_fixedC}; // testy

////////////////////////////////////////////////////////////////////////////////////
/// OUTERS

/*

dactype/dacpar
-speed: basic, select, speedfroms, strobe
-bits:
  routes: no depth.fixed -> prob
          strobes/no strobes
          prob - use [5]/in and/or always have in reserve as LFSR 
-prob: 

TODO/layout: 
00-fixedroute/fixedtype - set DACtype or have cv prob for cycle/other noncv
01-depthroute/fixedtype
02-fixedroute/flextype
03-depthroute/flextype -> 2x CV? or type is global // TODO: or is gapped?

gap for route, gap for type

->other types of binroute function// next set

dactype in 00
where we set dacparam

areas with associated gaps:

-dactypes/dacparams

-binroutes
-probs

speedL
-speedfroms1, double speeds -> //above bitmodes 
-splitspeeds2
-xor/orstrobes3 as part of strobes modes
-strobes4

-matrixp which includes all strobe etc...


*/

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobeindex
// 1/ puer... or which we start from?

void SR_geo_outer_route(uint32_t w){  // fixed route // the most basic but no reset
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // speed
  //  gate[w].inner=SR_geo_inner_fixedC; // totally fixed 
  gate[w].inner=SRinnersC[0]; // totally fixed - test this ref also // testy - as above
}

////// generic test codes

//- DAC we need to write test codes- test CVL as otherpar for each of DACtypes and fixed length(short and longest to see how compares) - write test code...
void SR_geo_outer_testDAC(uint32_t w){  // test new DAC code
  RESETC; 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[13]=16<<7; //dactype
  gate[w].matrix[14]=(gate[dacfrom[daccount][w]].dac);//CVL[w]; // into DAC_ otherpar which is 12 bits???
  gate[w].matrix[6]=31<<7; //length as 31 now - // also we could have CVL for both length and otherpar (or invert one against the other)
  gate[w].inner=SR_geo_inner_fixedC;
}

void SR_geo_outer_testOR(uint32_t w){  // tests for binroutorg 3: bitrouteorgap - swop in routebitsd
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=3<<6; // binroutorg
  gate[w].matrix[4]=CVL[w]; // 
  gate[w].inner=SR_geo_inner_noprobC;
  }
}

// prob5 is 36   if (depth<in) { // in as LFSR
void SR_geo_outer_testprob5(uint32_t w){  
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=36<<6; // prob5
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].matrix[5]=LFSR__[w];
  gate[w].inner=SR_geo_inner_noprobC;
  }
}

//void SR_geo_inner_probcycleC(uint32_t w){  // TESTY - using probfsins - ported in from speeds -> basic gapped cv binroute against justcycle! // unused so far
// what cv we need: probfs: 9type,10comp... 11IN 3,4,5 is gapped...
void SR_geo_outer_testprobcycle(uint32_t w){
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6;
  gate[w].matrix[4]=2<<8; // default route from 2L

  gate[w].matrix[9]=0<<7; // select probfs - but we need 10 and 11 and 12?!
  //  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac);; //
  gate[w].matrix[10]=CVL[w]; // probCV1
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac); // CV2 for those which use IN     
  gate[w].inner=SR_geo_inner_probcycleC; 
}
}

void SR_geo_outer_testroutearray(uint32_t w){  // CV1
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6;
  gate[w].matrix[4]=2<<8; // default route from 2L
  gate[w].inner=SR_geo_inner_noprobTEST;
  }
}


/*

former:
00-fixedroute/fixedtype - set DACtype or have cv prob for cycle/other noncv
01-depthroute/fixedtype
02-fixedroute/flextype
03-depthroute/flextype -> 2x CV? so type is just l ???
*/

/* OR:
simpler begin arrays: 1st 16 to re-check...

1. binroute fixed (change length/dac/adc)
2. depth as route only
3. fixed vs. cycle prob
4. fixed vs. [fixed XOR cycle prob]

// note that these probs are in bit functions: Zbinroutfixed_prob1 (fixedor), Zbinroutfixed_prob4 (fixedxor) -> these have types on IN though

aka:

1. binroute fixed (change length/dac/adc)
2. depth as route only
3. fixed vs. cycle prob
4. fixed vs. fixed XOR cycle prob

next set:
1/5. depth gapped for 3.4. depth as route vs...
2/6.

 */

/* 12/2022+
// review//

first 16 as we have now - routes: types and route, probs of xroute vs. yroute

00 fixed route - set dactype
01 depth as route
02 flexible type
03 fixedtype/asglobal/gap - depth as route!

10 fixed route/global type/ set dacparam
11 dacparam as dac
12 length Cv gap route as depth
13 select function/length as dacfrom - NOTE:could leave length gapped... 

20 CVL type/in ->routebitsfortypes
21 CVL depth
22 function
23 length

30 gaps for speed function - but where is that set (ahead)? routebitsd // routefunc // gap depth
31 depth is dac
32 CVL depth
33 CVL length

4, 5, 6, 7: next 16

8, 9, 10, 11: 16 - strobe

12, 13, 14, 15: last 16


 */
//////////////////////////////////////////

void SR_geo_outer_C00(uint32_t w){  // set dactype, spdfrac, fixed route // RESETR - no need for changed
  if (gate[w].changed==1) RESETC; // added 21/12 only reset on change 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[13]=CVL[w]; //
  gate[w].inner=SR_geo_inner_fixedC;
}

void SR_geo_outer_C01(uint32_t w){  // spdfrac, depth as route
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // depth as route
  gate[w].matrix[4]=CVL[w]; // 
  gate[w].inner=SR_geo_inner_noprobC; //routebitsd
  }
}

void SR_geo_outer_C02(uint32_t w){  // spdfrac, fixed route/global, flextype
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=46<<6; // fixed/flextype = binroutesel2=46
  gate[w].matrix[4]=CVL[w]; //
  gate[w].inner=SR_geo_inner_noprobC;
  }
  }

void SR_geo_outer_C03(uint32_t w){  // spdfrac, depthroute, fixedtype->global
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=45<<6; // fixed/flextype = binroutesel1=45
  gate[w].matrix[4]=CVL[w]; //
  gate[w].inner=SR_geo_inner_noprobC;
}
}

// dacparam as above 
void SR_geo_outer_C10(uint32_t w){  // set dacparam, spdfrac, fixed route with default type
  if (gate[w].changed==0) { 
    gate[w].matrix[0]=0<<7; // spdfrac
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=9<<7; // sel0 
    gate[w].matrix[14]=CVL[w]; // into DAC_ otherpar which is 12 bits
    gate[w].inner=SR_geo_inner_noprobnodC;
  }
}

// set dacpar as dacfrom length
void SR_geo_outer_C11(uint32_t w){  // set dacparam, spdfrac, fixed route with default type
  if (gate[w].changed==0) { 
    gate[w].matrix[0]=0<<7; // spdfrac
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=9<<7; // sel0 
    gate[w].matrix[6]=CVL[w]; //length
    gate[w].matrix[14]=gate[dacfrom[daccount][w]].dac; // into DAC_ otherpar which is 12 bits
    gate[w].inner=SR_geo_inner_noprobnodC;
  }
}

// keep length CV and gap depth as route
void SR_geo_outer_C12(uint32_t w){  // spdfrac, depth as route
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<6; // route as depth 
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_noprobC;
}
}
  
// we pass fixed depth/as/route and select function -> length as dacfrom
void SR_geo_outer_C13(uint32_t w){  
  if (gate[w].changed==0) {
    gate[w].matrix[0]=0<<7; // spdfrac
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=CVL[w]; 
    gate[w].matrix[6]=gate[dacfrom[daccount][w]].dac; 
    gate[w].inner=SR_geo_inner_noprobfixeddepthC;
  }
}

//- start vary routes/new sel with IN as sel->SR_geo_inner_binr and 0<<8 there
void SR_geo_outer_C20(uint32_t w){  // 
  if (gate[w].changed==0) { 
    gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<7; // select func
  gate[w].matrix[4]=2<<8;//CVL[w]; // depth
  //  gate[w].matrix[5]=CVL[w]; // IN selects type
  //  gate[w].routetype=CVL[w]>>9; // new type SELECT!!!
  // replacing with
  SETROUTETYPE=CVL[w]; // newer
  gate[w].inner=SR_geo_inner_binrC; // 16 of these >>8 <<8
}
}

void SR_geo_outer_C21(uint32_t w){  // as above with depth
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=0<<7; // select func
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].inner=SR_geo_inner_binrC; // 16 of these >>8 <<8
}
}
  
void SR_geo_outer_C22(uint32_t w){  // as above with selfunction
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // select func
  gate[w].inner=SR_geo_inner_binrC; // 16 of these >>8 <<8
}
}
  
void SR_geo_outer_C23(uint32_t w){  // as above with length or we can also have dacfrom for depth
  if (gate[w].changed==0) { 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; //depth
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_binrC; // 16 of these >>8 <<8
}
}
  
// last set is full routes ///routebitsd[60] - gaps for speed function
void SR_geo_outer_C30(uint32_t w){  // 
  if (gate[w].changed==0) { 
    //  gate[w].matrix[0]=0<<7; // spdfrac GAP!!!
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // select func
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].inner=SR_geo_inner_noprobC; // 
}
}
  
void SR_geo_outer_C31(uint32_t w){  // 
  if (gate[w].changed==0) { 
    //  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[3]=CVL[w]; // select func
  gate[w].matrix[4]=gate[dacfrom[daccount][w]].dac; //depth
  gate[w].inner=SR_geo_inner_noprobC; // 
}
}

void SR_geo_outer_C32(uint32_t w){  // 
  if (gate[w].changed==0) {
    //    gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[4]=CVL[w]; // depth
  gate[w].inner=SR_geo_inner_noprobC; // 
}
}

void SR_geo_outer_C33(uint32_t w){  // 
  if (gate[w].changed==0) {
    //    gate[w].matrix[0]=0<<7; // spdfrac
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_noprobC; // 
}
}

// speedfroms: set speedfrom mode, speed as cv, dac/swop - for fixed route, depth as route
//16
void SR_geo_outer_C40(uint32_t w){  
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // set spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    //    gate[w].matrix[3]=0<<6; // fixedroute
    gate[w].inner=SR_geo_inner_fixedC;
  }
}

 // DONE/TO_TEST: rework inner fixed for prob if we have CV from speed free
void SR_geo_outer_C41(uint32_t w){  // swopped order of dac and CV - fixed route
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // set spdfrom mode
    gate[w].matrix[1]=gate[speedfrom[spdcount][w]].dac; // SWOPPED order
    gate[w].matrix[2]=CV[w];// speed // if not the is prob
    gate[w].inner=SR_geo_inner_fixedprobC;
  }
}

void SR_geo_outer_C42(uint32_t w){  // gapped depth/route //+swop1
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // set spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[3]=0<<6; // depth as route
    gate[w].inner=SR_geo_inner_noprobC;
  }
}

void SR_geo_outer_C43(uint32_t w){  // gapped depth/route and bitmode //+swop2
  if (gate[w].changed==0) {
    gate[w].matrix[0]=CVL[w]; // set spdfrom mode
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    //    gate[w].matrix[3]=0<<6; // depth as route
    gate[w].inner=SR_geo_inner_noprobC;
  }
}
//20
// speedfrom xor
void SR_geo_outer_C50(uint32_t w){  // which gaps/functions - but we have CVL used
  // what is appropriate speed function????
  gate[w].matrix[0]=CVL[w];
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but do we need 2nd cv???
  gate[w].inner=SR_geo_innerxorC;
}  

//split speed= see toport.h
void SR_geo_outer_C51(uint32_t w){  // which gaps/functions - but we have CVL used
  // what is appropriate speed function????
  gate[w].matrix[0]=CVL[w];
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; // 1 and 2 we don't use and CV is free
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but do we need 2nd cv???
  gate[w].inner=SR_geo_innerNOSC;
}  

// and 2x runglers - speedgaps
void SR_geo_outer_C52(uint32_t w){  // 
  if (gate[w].changed==0) { 
    //    gate[w].matrix[0]=0; // spcdfrac -> or set as DACspeed one of which we have 6//
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[3]=0<<7; //1 fixed
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    gate[w].matrix[12]=20<<7; // OSC for rung
    //    gate[w].dacpar=CVL[w]; // into DAC_ otherpar which is 10 bits
    gate[w].inner=SR_geo_inner_rung0C;
  }
}

void SR_geo_outer_C53(uint32_t w){  // 
  if (gate[w].changed==0) { 
    //    gate[w].matrix[0]=0; // spcdfrac 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac; // 2nd speed cv
    gate[w].matrix[4]=CVL[w];
    gate[w].matrix[3]=19<<7; // OSC for rung - for that array is 19
    //    gate[w].dacpar=CVL[w]; // into DAC_ otherpar which is 10 bits
    gate[w].inner=SR_geo_inner_rung1C; // is fixed route vs. other
  }
}

// probs1: 60,61,62,63

void SR_geo_outer_C60(uint32_t w){  // prob from strobes only, no depth
  if (gate[w].changed==0) { 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
    //    gate[w].matrix[3]=1<<7;  // gap
    //    gate[w].matrix[4]=CVL[w]; // gap
    gate[w].matrix[9]=CVL[w]; // prob mode
    //    gate[w].matrix[10]=CVL[w]; //unused 
    //    gate[w].matrix[11]=CVL[w];// unused 
    gate[w].matrix[12]=5<<7; // altfuncindex - 5 is justcycle
     
    gate[w].inner=SR_geo_inner_prob2C; // trial different prob functions - these use strobe - could be 3C // no use of cv[11]
  }
}

void SR_geo_outer_C61(uint32_t w){  // gaps
  if (gate[w].changed==0) { 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
    gate[w].matrix[9]=CVL[w];  // ????
    gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[11]=LFSR__[w];// used... but is also bits???
     
    gate[w].inner=SR_geo_inner_probofdacoutC; // can use IN -> 11...
  }
}

void SR_geo_outer_C62(uint32_t w){  
  if (gate[w].changed==0) { 
    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
    //    gate[w].matrix[9]=CVL[w]; // zprobbits // gappped
    gate[w].matrix[10]=CVL[w];//
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    gate[w].inner=SR_geo_inner_probofdacoutC; // 
  }
}

//- *probability in regular bitmodes is now vs. in and we pass LFSR to matrix[5] <(LFSR_[wh]&4095)// remember - but then we need to handle these - different sets... make example*
void SR_geo_outer_C63(uint32_t w){  // eg. test routeprobs with IN [5] as LFSR - depth vs in
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  gate[w].matrix[4]=CVL[w]; //
  gate[w].matrix[5]=LFSR_[w]&4095; // vs LFSR - IN
  gate[w].inner=SR_geo_inner_noprob_routeprobC;// different kind of prob 
}
}

void SR_geo_outer_C70(uint32_t w){  // can also have CV vs dacfrom
  if (gate[w].changed==0) {
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  gate[w].matrix[3]=CVL[w];
  gate[w].matrix[4]=(gate[dacfrom[daccount][w]].dac);; //
  gate[w].matrix[5]=LFSR_[w]&4095; // vs LFSR - IN
  gate[w].inner=SR_geo_inner_noprob_routeprobC; // different kind of prob 
}
}

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobeindex
// problem for prob is we have:
/*
[9] type
[10] CV1
[11] CV2 which should not be fixed/CV
[12] altfunc 
 */


// TODO: check prob gaps
/* 71->

 */

// where do we set [11]??? TOFIX
// classic prob we need selprobfunc, cvs for prob, cvs for bits, cvs for selfunc, selalt -> too many even with strobe
void SR_geo_outer_C71(uint32_t w){  // TYPE of PROB
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // bitcv2

  gate[w].matrix[9]=CVL[w]; // select probfs - but we need 10 and 11 and 12?!
  gate[w].matrix[10]=gate[dacfrom[daccount][w]].dac; //
  gate[w].matrix[11]=gate[dacfromopp[daccount][w]].dac; //
  gate[w].inner=SR_geo_inner_prob1C; 
}
}

void SR_geo_outer_C72(uint32_t w){  // altfunc
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  //  gate[w].matrix[9]=CVL[w]; // select probfs - but we need 10 and 11 and 12?!
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; //bit-cv2
  gate[w].matrix[10]=gate[dacfrom[daccount][w]].dac; // prob-cv1
  gate[w].matrix[11]=gate[dacfromopp[daccount][w]].dac; //
  //10 is prob vs lfsr/cv -> can be dacfrom
  gate[w].matrix[12]=CVL[w];
  gate[w].inner=SR_geo_inner_prob1C; 
}
}

void SR_geo_outer_C73(uint32_t w){  // CV1
  if (gate[w].changed==0) { 
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[speedfrom[spdcount][w]].dac;//
  //  gate[w].matrix[9]=CVL[w]; // select probfs - but we need 10 and 11 and 12?!
  //  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac);; //
  gate[w].matrix[10]=CVL[w]; // probCV1
  gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);; // CV2 for those which use IN     
  gate[w].inner=SR_geo_inner_prob1C; 
}
}
// classic prob: SR_geo_inner_prob1 - how we get enough CV? 72setfunc, 73gapthere


/*
TODO:

// splitspeed? split3?

1 strobes2 prob1 
2 
3 prob2 - fixed probs
4 2 splitspeed versions????


strobe with optional prob

*/


// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobeindex
// first set is basic strobes

/*
- re-set bitfunc and CV - 

0 [3]=CVL[w] 
1 [4]=CVL[w]
2 [9]=CVL[w]
3 [12] altfuncindex
 */

/*
SR_geo_inner_prob_ifstrobeC - variable prob
SR_geo_inner_prob_strobeC - always prob includes fixed routes

0fixed route. fixed strobe. always prob - 
1unfixed route. fixed strobe. always prob
2fixed route. unfixed strobe. variable prob - SR_geo_inner_prob_ifstrobe

etc????

void SR_geo_inner_prob_strobeC(uint32_t w){  // straight strobe and prob - includes fixed routes
void SR_geo_inner_prob_strobedepthC(uint32_t w){  // straight strobe and prob - includes fixed routes
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// STROBES

// fixed route - prob of cycle CV against DAC 
void SR_geo_outer_C80(uint32_t w){ 
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=0<<8; // strobed function
    //    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=1<<6; // set bitfunc fixed
    //    gate[w].matrix[4]=CVL[w]; // fixed
    //    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    gate[w].matrix[9]=1<<7; // probbits - do as default
    gate[w].matrix[10]=CV[w]; // CVL for prob
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob_strobeC; 
  }
}

//1unfixed route. fixed strobe. always prob
// route as depth, routefunction with depth
void SR_geo_outer_C81(uint32_t w){
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=0<<8; // strobed function
    //    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=0<<6; // set bitfunc for depth
    gate[w].matrix[4]=CVL[w]; // depth
    //    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    gate[w].matrix[9]=1<<7; // probbits - do as default
    gate[w].matrix[10]=CV[w]; // CV for prob
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob_strobeC; 
  }
}

// as above but start to change bitfunc and make sure uses depth // not necessarily so as CV/.depth is gapped anyways and used
void SR_geo_outer_C82(uint32_t w){
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=0<<8; // strobed function
    //    gate[w].matrix[1]=CV[w];// speed
    gate[w].matrix[3]=CVL[w]; // set bitfunc 
    //    gate[w].matrix[4]=CVL[w]; // depth is gapped
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    gate[w].matrix[9]=1<<7; // probbits - do as default
    gate[w].matrix[10]=CV[w]; // CV for prob
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob_strobeC;
  }
}

// as above but start to change altfuncindex
void SR_geo_outer_C83(uint32_t w){
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=0<<8; // strobed function
    //    gate[w].matrix[1]=CV[w];// speed
    //    gate[w].matrix[3]=CVL[w]; // set bitfunc for depth
    //    gate[w].matrix[4]=CVL[w]; // depth is gapped
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    gate[w].matrix[9]=1<<7; // probbits - do as default
    gate[w].matrix[10]=CV[w]; // CV for prob
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    gate[w].matrix[12]=CVL[w];//4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob_strobeC;
  }
}

// we still have to deal with different strobe functions and type of prob 
// start to change strobe function then we have optional prob to deal with as some use CV
//void SR_geo_inner_prob_ifstrobeC

// start with different strobe functions some of which use CV, so we have to set that and optional prob
// fixed route
void SR_geo_outer_C90(uint32_t w){
  if (gate[w].changed==0) { 
    gate[w].matrix[15]=CVL[w]; 
    gate[w].matrix[1]=CV[w];// speed if used
    gate[w].matrix[3]=1<<6;// fixed route
    //    gate[w].matrix[4]=CVL[w]; // depth is gapped
    //    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    //    gate[w].matrix[9]=1<<7; // probbits - do as default gaps
    gate[w].matrix[10]=CV[w]; // CV for prob if used
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    //    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob_ifstrobeC; // optional prob
  }
}

// depth as route vs gapped
void SR_geo_outer_C91(uint32_t w){
  if (gate[w].changed==0) { 
    //    gate[w].matrix[15]=CVL[w]; // gapped
    gate[w].matrix[1]=CV[w];// speed if used
    gate[w].matrix[3]=0<<6; // depth as route
    gate[w].matrix[4]=CVL[w]; // depth
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    //    gate[w].matrix[9]=1<<7; // probbits - do as default gaps
    gate[w].matrix[10]=CV[w]; // CV for prob if used
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    //    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob_ifstrobeC; // optional prob
  }
}

// type of bin vs gapped
void SR_geo_outer_C92(uint32_t w){
  if (gate[w].changed==0) { 
    //    gate[w].matrix[15]=CVL[w]; // gapped
    gate[w].matrix[1]=CV[w];// speed if used
    gate[w].matrix[3]=CVL[w]; 
    //    gate[w].matrix[4]=CVL[w]; // depth
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    //    gate[w].matrix[9]=1<<7; // probbits - do as default gaps
    gate[w].matrix[10]=CV[w]; // CV for prob if used
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    //    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob_ifstrobeC; // optional prob
  }
}

// probtype
void SR_geo_outer_C93(uint32_t w){
  if (gate[w].changed==0) { 
    //    gate[w].matrix[15]=CVL[w]; // gapped
    gate[w].matrix[1]=CV[w];// speed if used
    //    gate[w].matrix[3]=CVL[w]; 
    //    gate[w].matrix[4]=CVL[w]; // depth
    gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
    //    gate[w].matrix[6]=CVL[w]; //length
    // prob stuff
    gate[w].matrix[9]=CVL[w]; 
    gate[w].matrix[10]=CV[w]; // CV for prob if used
    gate[w].matrix[11]=(gate[dacfrom[daccount][w]].dac);
    //    gate[w].matrix[12]=4<<7; // altfuncindex - 4 is cycle

    gate[w].inner=SR_geo_inner_prob_ifstrobeC; // optional prob
  }
}


/* CVL sets/param:

- type of strobe
- type of bin
- bin param
- altfuncindex
- probtype
 */

// type of prob finally 100

///////////////////////////

/*
void SR_geo_outer_Ctestprobstrobe(uint32_t w){  // set dacparam, spdfrac, fixed route
  if (gate[w].changed==0) { 

    gate[w].matrix[15]=0<<7; // testing 
    gate[w].matrix[3]=1<<7; 
    gate[w].matrix[4]=CVL[w]; // cv for binr

    gate[w].matrix[9]=1<<7; // probbits 
    gate[w].matrix[10]=CV[w]; // CV for prob
    gate[w].matrix[11]=CVL[w];// for 9/comp // 11 is IN
    gate[w].matrix[12]=5<<7; // altfuncindex - 5 is justcycle
     
    gate[w].inner=SR_geo_inner_prob3_strobeC; // trial different prob functions
  }
}
*/

// and prob with dac and strobe would lose CV>?

/*

1 matrixp, moving gaps //no esoteric binops in geoC
2
3
4

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

uint32_t fixedvalues[4][16]={ //  values - but x value means no change... say 4096 
  {0},
};

uint32_t fixed=0, gap=0;

uint32_t *fixedvars[4][20]={ // 
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &Gshift_[8], &LFSR__[0], &LFSR__[1], &LFSR__[2], &LFSR__[3], &fixed, &gap},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[1], &param[1], &Gshift_[8], &LFSR__[0], &LFSR__[1], &LFSR__[2], &LFSR__[3], &fixed, &gap},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[2], &param[2], &Gshift_[8], &LFSR__[0], &LFSR__[1], &LFSR__[2], &LFSR__[3], &fixed, &gap},
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[3], &param[3], &Gshift_[8], &LFSR__[0], &LFSR__[1], &LFSR__[2], &LFSR__[3], &fixed, &gap},
};

// 2 sets arrays/// eg. // but we need mult dimensions as these match mode descriptions
//eg. for above C01
uint32_t matrixpp[18]={18, 4, 18, 18,  5, 18, 18, 18,  18,18,18,18, 18,18,18,18, 5,5}; // eg.. not matched to: fixed, CVL, gap, fixed, CV
uint32_t matrixvv[18]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,25<<7,0, 0,0}; // fixed values			 

void SR_geomantic_matrixmode(uint32_t w){ 
  uint32_t x, y;
  
  for (x=0;x<18;x++){
    gate[w].matrixp[x]=fixedvars[w][matrixpp[x]]; // sets mode
    if (gate[w].matrixp[x]==&fixed){
      fixedvalues[w][x]=matrixvv[x]; 
      gate[w].matrixp[x]=&fixedvalues[w][x]; 
    }
    else if (gate[w].matrixp[x]==&gap){
      gate[w].matrixp[x]=&gate[w].matrix[x]; 
    }
    gate[w].matrix[x]=*(gate[w].matrixp[x]); 
  }
  // set gate[w].inner
}




// sets gap with last matrix value
static inline void setgapz(uint32_t wh, uint32_t which){ // new version which keeps ghost - also doesn't set gap twice
  static uint32_t oldgap[4]={0,0,0,0};
  if (which!=oldgap[wh]){
    gate[wh].matrixp[oldgap[wh]]=gate[wh].matrixpG[oldgap[wh]];//    // TODO/TEST: filling in old gaps - something in there to progress from! - return old gap to what it was?
    gate[wh].matrixpG[which]=gate[wh].matrixp[which]; 
    gate[wh].matrixp[which]=&gate[wh].matrix[which]; // last value...
  }
  oldgap[wh]=which;
}

static inline void setfixedz(uint32_t wh, uint32_t which, uint32_t val){
  fixedvalues[wh][which]=val; 
  gate[wh].matrixp[which]=&fixedvalues[wh][which]; 
}

static inline void setvarz(uint32_t wh, uint32_t which, uint32_t var){ // set to variable such as CV, CVL etc...
  gate[wh].matrixp[which]=fixedvars[wh][var];
}

static inline void setfixedandcopyz(uint32_t wh, uint32_t which, uint32_t val){
  fixedvalues[wh][which]=val; 
  gate[wh].matrixp[which]=&fixedvalues[wh][which]; 
  gate[wh].matrix[which]=val; 
}

static inline void setvarandcopyz(uint32_t wh, uint32_t which, uint32_t var){ // set to variable such as CV, CVL etc...
  gate[wh].matrixp[which]=fixedvars[wh][var];
  gate[wh].matrix[which]=*(fixedvars[wh][var]); 
}

static inline void setvargapz(uint32_t wh, uint32_t which, uint32_t var){ // sets gap with one of fixedvars - is not really a gap?
  static uint32_t oldgap[4]={0,0,0,0};
  if (which!=oldgap[wh]){
    gate[wh].matrixp[oldgap[wh]]=gate[wh].matrixpG[oldgap[wh]];//    // TODO/TEST: filling in old gaps - something in there to progress from!
    gate[wh].matrixpG[which]=gate[wh].matrixp[which]; 
    gate[wh].matrixp[which]=fixedvars[wh][var];
  }
  oldgap[wh]=which;
}

// but this copies everything...
void SR_geomantic_matrixcopyz(uint32_t w){ 
  uint32_t x, y;
  
  for (x=0;x<18;x++){
    gate[w].matrix[x]=*(gate[w].matrixp[x]); 
  }
  // set gate[w].inner
}

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobespd}
void SR_geo_outer_C01matrixp(uint32_t w){  // spdfrac, depth as route // not working as is it necessary to fill all gaps...?
  if (gate[w].changed==0) {
    setfixedz(w,0,0);     //  gate[w].matrix[0]=0<<7; // spdfrac
    setvarz(w,1,4); //    gate[w].matrix[1]=CV[w];// speed
    setfixedz(w,3,0); //  gate[w].matrix[3]=0<<6; // depth as route
    setvarz(w,4,5); //    gate[w].matrix[4]=CVL[w]; 

    setfixedz(w,13,0); // dactype
    setfixedz(w,6,0); // length=31

    //    setfixedz(w,14,0); 
    //setvarz(w,14,5); // CVL
    
    SR_geomantic_matrixcopyz(w);
    gate[w].inner=SR_geo_inner_noprobC; //routebitsd

    //and if we have inner as also part of matrixp (inc to 17)
    //gate[w].inner=SRinnersC[gate[w].matrix[16]>>7]; // 5 bits    
  }
}

// trial with set and copy
void SR_geo_outer_C01matrixxp(uint32_t w){  // spdfrac, depth as route // not working as is it necessary to fill all gaps...?
  if (gate[w].changed==0) { 
    setfixedandcopyz(w,0,0);     //  gate[w].matrix[0]=0<<7; // spdfrac
    setvarandcopyz(w,1,4); //    gate[w].matrix[1]=CV[w];// speed
    setfixedandcopyz(w,3,0); //  gate[w].matrix[3]=0<<6; // depth as route
    setvarandcopyz(w,4,5); //    gate[w].matrix[4]=CVL[w]; 
    
    gate[w].inner=SR_geo_inner_noprobC; //routebitsd
  }
}

void SR_geo_outer_C01matrixpp(uint32_t w){  // spdfrac, depth as route
  if (gate[w].changed==0) { 
    SR_geomantic_matrixmode(w);
    gate[w].inner=SR_geo_inner_noprobC; //routebitsd

    //and if we have inner as also part of matrixp (inc to 17)
    //gate[w].inner=SRinnersC[gate[w].matrix[16]>>7]; // 5 bits    
  }
}

// testing no inners, just abstraction

// fill in
//uint32_t (**routetest[64])(uint32_t depth, uint32_t in, uint32_t wh)={routebitsd}; // all need to be same length // we have above

uint32_t (**speedtest[64])(uint32_t depth, uint32_t in, uint32_t wh)={}; // all need to be same length

uint32_t (**probtest[64])(uint32_t depth, uint32_t in, uint32_t wh)={}; // all need to be same length

/* questions of how it could handle:

- prob of dacout // as prob is only dealing with bits - unless we can set a flag
- use of probs if we don;t use CVL

- what else?


 */

// if we extend matrixp for functions to length of 22

void SR_geo_outer_C01matrixpp_abstracted(uint32_t w){  // spdfrac, depth as route
  HEADNADA;
  
  if (gate[w].changed==0) { 
    SR_geomantic_matrixmode(w);

    // interpolation set by previous speedfunc TODO
    if (gate[w].interp){
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    // speed
    if ((*speedtest[gate[w].matrix[18]][gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      if (gate[w].matrix[18]>5) gate[w].fake=gate[w].trigger; // how we decide this? if is a strobespeed mode or not /- strobe speeds are all >x
      else gate[w].fake=1;      
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; 

    if ((*probtest[gate[w].matrix[19]][gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){ // we need probf which just gives 0!
      bitn=(*routetest[gate[w].matrix[20]][gate[w].matrix[12]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); 
  }
  else {
    bitn=(*routetest[gate[w].matrix[21]][gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
  }
  }
}

/* expansions/slippages

- catalogue inners:

basic inners: interp/non, strobe/no strobe, probfs

// find way to abstract for each one

more complex: where we decide based on flags such as use of CV

eg. cut down for no interp - index in matrixp/matrix for speedfuncarray and bitnarray 17 and 18!

void SR_geo_inner_slips(uint32_t w){  // test for array of 
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];

    if ((*speedtest[gate[w].matrix[17]][gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
      gate[w].fake=gate[w].trigger;
      GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    bitn=(*routetest[gate[w].matrix[18]][gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); // >>6 as there are 64
  
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


 */
