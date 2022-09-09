// try to take and revise from geomantic.h
// 4x16 generic outer modes (sans adc/dac) and then make these for adc/dac/globalR, L

/*
1- fixed 4: speedfracend and most simple cases
2- 
3
4

1- open
2
3
4

1- strobe
2
3
4

1- matrix/stack/globals
2
3
4

 */

// lists of functions/ all should be 32 TODO:

// 1. speeds
uint32_t (*speedfromnostrobe[36])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitscycle_noshift, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zbinrouteSRbits, zwiardbits, zwiardinvbits, zjusttail, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob3_nosh, binroutfixed_prob4_nosh};

uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift}; 

uint32_t (*speedfromcvforxor[25])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zwiardbits, zwiardinvbits, zjusttail, zsuccbitsI_noshift, zsuccbits_noshift};// no strobes, no routes and only CV ones...

uint32_t (*speedfromstrobe[7])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebits, ztogglebitssh, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle}; // there can be more which use trigger to say advance local route for speed etc...

uint32_t (*speedfromnew[46])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, spdfrac, spdfrac4, spdfracdac3, spdfracend, ztogglebits, ztogglebitssh, clksrG, clksr, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zprobbits, zinvprobbits, zsprobbits, zTMsimplebits, osceq, zosc1bits, zonebits, zonebitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zbinrouteSRbits, zwiardbits, zwiardinvbits, zjusttail, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob3_nosh, binroutfixed_prob4_nosh};  // 2x spdfrac for interpoll
// TODO: divide into altspeeds, // maybe split into 2x speeds, basics with indies, more route based, more prob based, more abstract

// mark where we don't use depth
uint32_t unused[32]={1,0,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,1,1,0, 0,0,0,0};// matches speedfromnew to free up CV[w] - needs TODO be adjusted as we change above one - in which modes we use this?

uint8_t interp[32]={0,1,1,0,0,0,0,0,0,0,0,0,0,0}; // TODO match with interp//////// but depends on which speedfrom we use! - not used so far

// testings

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

// this is our generic one... - make changes for adc/dac
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

// trial for xor of speeds:
// we can xor: strobes with any non-strobe which uses cv, fixedroutes with any non-route which uses cv - so 2 sets - how we fix each/// or stay fixed...
// first case is already in: SR_geomantic_innerxorS
// second case... speedfromfixedforxor uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift}; // unsued so far

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ADC
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// reserve basic one for top ADC, modeN 
void SR_geomantic_inner_adc(uint32_t w){  // no prob - but this should be done in outers
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

void SR_geomantic_outer_adc(uint32_t w){ // spdfrac and adc in - adc is set in 000 as default...
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  ///  RESETR; // but could this not be on changed! only? - put in resetr one
  
  gate[w].matrix[0]=3<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=2<<7; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[9]=0<<7; // no probs

  gate[w].matrix[8]=CVL[w]; // length for adc same as length
  
  gate[w].inner=SR_geomantic_inner_adc;
}
