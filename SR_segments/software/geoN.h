/*

For upper mode N: 16x4 modes

adc, abstracts and routes only

3/11/2022: TODO: check all array access and <<7 <<6 etc

11/10/2022

- test basic adc selection DONE
- INNERS: adc with prob of input, of reset and of move along/hold DONE

// TODO: we need different DAC from dacfrom as DAC for ADC input eg. dacIN

ADCin=gate[dacIN[daccount][w]].dac; // test

but this needs to be in inner functioin where we do adc

// ADDin strobe of ADC in from toport,h

void SR_geomantic_inner_split2(uint8_t w){  //strobe
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  if (gate[w].trigger){
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      //      bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); // fill in regg as 3 and adcpar needs changes, length too or???
      bitn=(*adcfromsd[gate[w].matrix[7]])(gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too
    }

  }
  if ((*speedfromnostrobe[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
        
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inner_split3(uint8_t w){  // can also have OUTSIDE Func in... top // strobe
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  if (gate[w].trigger){
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    GSHIFT_;
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      //      bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); // fill in regg as 3 and adcpar needs changes, length too or???
      bitn=(*adcfromsd[gate[w].matrix[7]])(gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too
    }

  }
  if ((*speedfromnostrobe[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

 */

/// INNER - TODO:redo bitfromsd!

void SR_geo_inner_noprobadc(uint32_t w){  // no probability, WITH adc, with interpoll
  HEADNADA;
  //

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?

    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadc(uint32_t w){  // probability, WITH adc, with interpoll
  HEADNADA;
  //

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn^=(*bitfromnostrobe[gate[w].matrix[12]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    //    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

/*
void SR_geo_inner_noprobdacin(uint32_t w){  // no probability, dacin, with interpoll - not so exciting
  HEADNADA;
  //

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    ADCgeneric2; 
    bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // problem is same CV as for DAC below? unless we forego incoming bit

    ADCin=gate[dacIN[daccount][w]].dac;
    bitn^=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 

    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}
*/

/// TODO: prob of reset, prob of advance:-> padcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv - strobe is part of probability function anyways

//  prob of entry:
void SR_geo_inner_probadcentry(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2;
	  bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w);
    }
      
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}



// can also be prob of entry or bitn?
void SR_geo_inner_probadcentryor(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];


  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; 
	  bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
	}
      
    else bitn=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_inner_probadcentryxor(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];


  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; 
	  bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); 
	}
      
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


// prob of reset
void SR_geo_inner_probadcreset(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; 
	  bitn=(*padcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w, 1, 1); 
	}
    else
      {
	ADCgeneric2; 
	bitn=(*padcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w, 0, 1); 
      }
    
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// prob of advance
void SR_geo_inner_probadcadvance(uint32_t w){  // ADC only - prob for adc itself - from geomantic.h
  HEADNADA;

  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probfsins[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; 
	  bitn=(*padcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w, 0, 1);
	}
    else
      {
	ADCgeneric2; 
	bitn=(*padcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w, 0, 0); 
      }
    
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


////////////////////////////////////////////////////////////////////////////////////
/// OUTER

//uint32_t (*adcfromsd[23])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, cipher, zadcLBURST0, zadccomp, zadcxdouble, zadcxcut}; // all tested but too few

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar

void SR_geo_outer_N11(uint32_t w){ // spdfrac and adc in - adc is set in caput000 as default...
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  ///  RESETR; // but could this not be on changed! only? - put in resetr one
  
  gate[w].matrix[0]=1<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=1<<7; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[8]=CVL[w];//gate[dacfrom[daccount][w]].dac; // depth/length for adc same as length
  gate[w].matrix[7]=1<<7;//CVL[w]; // set adc - 0 is zeroes // 18 and 19 need triggersa
  
  gate[w].inner=SR_geo_inner_noprobadc;
}

/*
void SR_geo_outer_Ndac(uint32_t w){ // spdfrac and - test DACin
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  ///  RESETR; // but could this not be on changed! only? - put in resetr one
  
  gate[w].matrix[0]=1<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=2<<7; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  gate[w].matrix[7]=1<<7;//CVL[w]; // set adc - 0 is zeroes // 18 and 19 need triggersa
  
  gate[w].inner=SR_geo_inner_noprobdacin;
}
*/

/*
add in probs of entry, reset etc... // these can also be triggers or toggles -> this is set in the prob function // can also have DAC ins for these ADCs or a mix of these

// SR_geo_inner_probadcentry, SR_geo_inner_probadcentryor, SR_geo_inner_probadcreset, SR_geo_inner_probadcadvance

uint32_t (*probfsins[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, ones, zinvprobbits, zprobbits, zsprobbits, strobe, binrout, binroutfixed, comp, ztogglebits, ztogglebitssh, zownprobbits, zownGprobbits}; // prob functions and what these can be: eg. ones always selects alt - add assorted strobes/toggles, other bit ops

TODO - lose probf

 */


// there is also construction ????
void SR_geo_outer_Ntestprobentry(uint32_t w){  
  if (gate[w].changed==0) { // 1=change 0= no change
  gate[w].matrix[0]=1<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=1<<7; // fixed route=2
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  gate[w].matrix[7]=1<<7;//CVL[w]; // set adc - 0 is zeroes // 18 and 19 need triggersa
  gate[w].matrix[9]=3<<7;// 3 is classic prob // 5 is strobe!
  gate[w].matrix[10]=CVL[w]; 
  gate[w].inner=SR_geo_inner_probadcentry;
  }
}

void SR_geo_outer_Ntestprobentryor(uint32_t w){  
  if (gate[w].changed==0) { // 1=change 0= no change
  gate[w].matrix[0]=1<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=1<<7; // fixed route
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  gate[w].matrix[7]=1<<7;//CVL[w]; // set adc - 0 is zeroes // 18 and 19 need triggersa
  gate[w].matrix[9]=3<<7;// 3 is classic prob // 5 is strobe!
  gate[w].matrix[10]=CVL[w]; 
  gate[w].inner=SR_geo_inner_probadcentryor;
  }
}

void SR_geo_outer_Ntestprobentryreset(uint32_t w){  
  if (gate[w].changed==0) { // 1=change 0= no change
  gate[w].matrix[0]=1<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=1<<7; // fixed route
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  gate[w].matrix[7]=1<<7;//CVL[w]; // set adc - 0 is zeroes // 18 and 19 need triggersa
  gate[w].matrix[9]=3<<7;// 3 is classic prob // 5 is strobe!
  gate[w].matrix[10]=CVL[w]; 
  gate[w].inner=SR_geo_inner_probadcreset;
  }
}


void SR_geo_outer_Ntestprobentryadvance(uint32_t w){  
  if (gate[w].changed==0) { // 1=change 0= no change
  gate[w].matrix[0]=1<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=1<<7; // fixed route
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  gate[w].matrix[7]=1<<7;//CVL[w]; // set adc - 0 is zeroes // 18 and 19 need triggersa
  gate[w].matrix[9]=3<<7;// 3 is classic prob // 5 is strobe!
  gate[w].matrix[10]=CVL[w]; 
  gate[w].inner=SR_geo_inner_probadcadvance;
  }
}

