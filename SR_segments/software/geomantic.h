// TODO: start to test and sort all grouped functions here, new groups, see exp_port.h, and 
// eg. different types of speed, routes as speed, types of bit functions: routes, abstracts etc.  - all need length of 32 let's say

// 1. speeds

uint32_t (*speedfromnostrobe[27])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitscycle_noshift, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zprobbits, zTMsimplebits, zTMsimplebitsI, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna};// add to these from below

uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift};

uint32_t (*speedfromstrobe[5])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebits, ztogglebitssh, clksrG, clksr}; // there can be more which use trigger to say advance local route for speed etc...
// maybe split into 2x speeds, basics with indies, more route based, more prob based, more abstract

uint32_t (*speedfromnew[37])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, spdfrac, spdfrac4, spdfracdac3, spdfracend, ztogglebits, ztogglebitssh, clksrG, clksr, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zprobbits, zTMsimplebits, zTMsimplebitsI, osceq, zosc1bits, zosc1bitsI, zonebits, zonebitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna}; // 38 // 2x spdfrac for interpoll

// TODO: altspeeds: , // to add: other bitfromsd, more probbits

uint32_t unused[32]={1,0,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,1,1,0, 0,0,0,0};// matches speedfromnew to free up CV[w] - needs TODO be adjusted as we change above one - in which modes we use this?

uint8_t interp[32]={0,1,1,0,0,0,0,0,0,0,0,0,0,0}; // TODO match with interp//////// but depends on which speedfrom we use! - not used so far

// adc

uint32_t (*adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits};/// 

// new prob ones: probcvladcselcvm, probdacadcsel, probtrigadcsel -> more work on these...

// do we have probability of entry of adc or not, also prob of moving adc along? to add these here, and also more generic adcs: internal adcprobs are in geogen.h

// bits // can divide into further: abstract, includesprob, routings - which ones rely on other SRs!
uint32_t (*bitfromsd[77])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, binrout, binroutfixed, binroutor, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4,  viennabits, tailbits, flipflop, flipflopandroute, flipflopI, zjusttail, zcopyGSR, zcopyGSR_s, ztogglebitssh, ztogglebits};//  - how many can we have - different sets...
// SRdelay_lineOUT??? needs it input pair?

// we are missing: binroutesel0, 1,2,3 and we add new binroutes for locals: binroutfixedmy, binroutfixedmy, binroutmybumpS, binroutmycv, binroutmybumpbit, binroutmybumpbitt //can be more...
// also more variations of binroutes and probs // what variations of probs???

//check
uint32_t (*bitfromnostrobe[64])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, binrout, binroutfixed, binroutor, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zosc1bits, sigmadelta, cipher, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4,  viennabits, tailbits, flipflop, flipflopandroute, flipflopI, zjusttail, zcopyGSR};

// test for global set businessDONE GLOBALONE only this:
uint32_t (*bitfromsdR[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, binrout, binroutfixed, binroutor, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, selectglob};

uint32_t (*abstractbits[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zosc1bits, sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits}; //29 so far // also includes some strobes

uint32_t (*routebits[45])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutor, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, viennabits, tailbits, flipflopandroute, zjusttail, zcopyGSR, zcopyGSR_s}; // 45 so far so need to divide down ...

uint32_t (*expetcbits[80])(uint32_t depth, uint32_t in, uint32_t wh)={pSR_binr, pSR_routeSRbits00, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer12, pSR_reflect, pSR_altbin1, pSR_insert_zero, pSR_probbin, pSR_recbin, pSRhold, pSRholdfromdac, pSRxorSR, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortog, pSRmatch, pSRshare, pSRGswop, pSRshroute, pSRsigma, pbitSRroutelog, pbitSRroutelogxx, pbitLcvsrroute, pbitSRroutelogxxx, pbitSRroutedoit, pbitLSRroutexxxlog, pprobintprob1, pprobintprob2, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pstream, pSRBITMIX, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRmod, pSRNwas13, pSRN65, pSRN62, pSRLLswop, pSRN40, pSRN38, pSRN36, pSRNsr35, pSRN33cipher, pSRN33, pSRN30, pSRN22, pSRN21, pSRN15, pSRN14, pSRN13, pSRN12, pSRN11, pSRN10, pSRN8, pSRN7, pSRN6, pSRN5, pSRN3, pSRNwas15, pSRRLLswop, pSRRaccelghosts0, pSRRbumproute0, pSRR32}; // 80 there are... // form exp_port including exp, bit, prob, L, and R

// prob // regular probs vs. LFSR, depth<in, abstract bit functions, SR bits, routes... what do we need to add?

uint32_t (*probf[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, ones, zinvprobbits, zprobbits, zsprobbits, strobe, binrout, binroutfixed, comp, ztogglebits, ztogglebitssh, zownprobbits, zownGprobbits}; // prob functions and what these can be: eg. ones always selects alt - add assorted strobes/toggles, other bit ops

// tails
void (*dotail[64])(void)= {fliptail, basictail};
// what more of these can be? as they run at full speed...

// global opps
void (*globalls[32])(uint32_t depth)={resett, binaryN, binaryX, SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalbumpspd, SRRglobalbumpcv, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalsync, SRRglobalorder, SRRglobalbumpcvntype, SRRglobalbumpbit0, SRRglobalbumpbit1, SRRglobalbumpbit2, SRRglobalorderbumpS, SRRglobalorderbumpbit, SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalbumpspd, SRRglobalbumpcv, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalsync, SRRglobalorder, SRRglobalbumpS}; // only 20 so far // 32 filled

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

void SR_geomantic_innerorS(uint32_t w){  // no prob // or strobe
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

void SR_geomantic_innernoadcrung(uint32_t w){  // for generic rungler - route XOR function - has two functions
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn=(*bitfromsd[gate[w].matrix[12]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); // problem is same CVs
    
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

void SR_geomantic_innernoadcsplitbinr(uint32_t w){  // no prob // no adc -- run binrout fixed at full speed
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  bitn=binroutfixed(0,0,w);
  
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
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

void SR_geomantic_inneradcp(uint32_t w){  // ADC only - prob for bitn
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    
    if ((*probf[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn^=(*bitfromnostrobe[gate[w].matrix[12]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// example of how to set this up for say strobe adc entry
//gate[w].matrix[9]=5; // strobe // only
void SR_geomantic_inneradcpP(uint32_t w){  // ADC only - prob for adc itself
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if ((*probf[gate[w].matrix[9]>>7])(gate[w].matrix[10], gate[w].matrix[11], w)){
	  ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
	  bitn=(*adcfromsd[gate[w].matrix[7]>>7])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
	}
      
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


// R_only
void SR_geomantic_innerRglob(uint32_t w){  // no adc, // for global Rmodes // TODO - also inner globsel with fastest speeds...
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*bitfromsd[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); 

    (*globalls[glob])(gate[w].matrix[4]); // glob is index... which is set by master global function 31... set by outerglob
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innerRglobsel(uint32_t w){  // no adc, // for global Rmodes  - just select - 31 
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*bitfromsdR[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);  // sdR is the one with selectglob at 31
    /// we don;t do the glob    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innerRglobselandset(uint32_t w){ // both select and set as we call from outer which uses dac for value
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*bitfromsdR[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); 

    (*globalls[glob])(gate[w].matrix[5]); // glob is index... which is set by master global function 31... set by outerglob // now matrix 5 is dacfrom 
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


////////////////////////////////////////////////////////////////////////////////
//OUTERS
////////////////////////////////////////////////////////////////////////////////

//what we can use in outer modes:  &nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[x], &CVL[x], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[x], &param[x], &Gshift_[8] // TAIL!

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
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

void SR_geomantic_outerS0(uint32_t w){  // sets to 0//plain strobe
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

//// TRIAL
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
void SR_geomantic_outer1detach(uint32_t w){ 
  gate[w].matrix[0]=*gate[w].matrixp[0]; // if we want live value or don't set it/just ignore it for last value // and if is not set?
  // or we can say set gate[w].matrix[0]=CVL[w] temporarily; or a fixed value...
}

/// TRIAL for globals just to think through
void SR_geomantic_outerRglobset(uint32_t w){
  //    if (gate[w].changed==0) { // 1=change 0= no change
      gate[w].matrix[0]=3<<7; // spedfrom
      gate[w].matrix[1]=CV[w];
      gate[w].matrix[3]=31<<7;
      gate[w].matrix[4]=CVL[w];
      gate[w].inner=SR_geomantic_innerRglob;
      //    }
}  

void SR_geomantic_outerRglobsel(uint32_t w){
  //    if (gate[w].changed==0) { // 1=change 0= no change
      gate[w].matrix[0]=3<<7; // spedfrom
      gate[w].matrix[1]=CV[w];
      gate[w].matrix[3]=31<<7; // fixed route and glob setter
      gate[w].matrix[4]=CVL[w];
      gate[w].inner=SR_geomantic_innerRglobsel;
      //    }
}  

void SR_geomantic_outerRglobselandset(uint32_t w){ // select is CVL, depth for globsel is dac
  //    if (gate[w].changed==0) { // 1=change 0= no change
      gate[w].matrix[0]=3<<7; // spedfrom
      gate[w].matrix[1]=CV[w];
      gate[w].matrix[3]=31<<7; // fixed route and glob setter
      gate[w].matrix[4]=CVL[w];
      gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // for the depth of the glob
      gate[w].inner=SR_geomantic_innerRglobselandset;
      //    }
}  

/// test setting of dactype and dacpar for modeC


//// TRIAL2 - moving gaps if we have some kind of binary matrix - or ternary // how? - trial this possible copy in!?
//// but can this be more elegant? we change single set of matrices (could also be inside gate[w] then is back to older matrix idea...
//// but could be 2 dimensions

uint32_t fixedvalues[4][13]={ //  values - but x value means no change... say 4096
  {0},
};

uint32_t *fixedmatrix[4][13]={ // for tests below but is just one matrix and we need multiples... 3d array
  {&CVL[0], &gate[0].matrix[1], &fixedvalues[0][2]}, // &gate[0].matrix[1] - which would keep it the same
};

static inline void setgap(uint32_t wh, uint32_t which){
  fixedmatrix[wh][which]=&gate[wh].matrix[which]; // stays how it was... so that is a gap 
}

static inline void setfixed(uint32_t wh, uint32_t which, uint32_t val){
  // fixed value say 0
  fixedvalues[wh][which]=val; // first 0 is SR, second is matrix position...
  fixedmatrix[wh][which]=&fixedvalues[wh][which]; // can we wrap that up somehow? inline setfixed
}

void SR_geomantic_matrixcopy(uint32_t w){
  uint32_t x, y;
  //  gate[w].matrix[x]= // can be a fixed value, CVL[w], &CVL[w]/matrixp, or unchanged gap
  // so we can make gaps in matrices by setting eg.
  setgap(1,0);
  setfixed(0,0,0);
  
  for (x=0;x<13;x++){
    gate[w].matrixp[x]=fixedmatrix[w][x]; 
    gate[w].matrix[x]=(*gate[w].matrixp[x]); // how we deal with fixed values?
  }
}


// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
// 8/8/2022 testing strobe and fake pulses/normed pulses in caput000.c
void SR_geomantic_outer_test(uint32_t w){  // set up so we can test different functions eg. now try different speedfuncs
  if (gate[w].changed==0) { // 1=change 0= no change
  gate[w].matrix[0]=3<<7;// 0 was strobe // CVL[w]>>7;// 5 bits is 32 //2 bits //speedFUNC
  if (unused[gate[w].matrix[0]]) {
    gate[w].matrix[9]=3<<7; // probbits as we can now use CV
    gate[w].matrix[10]=CV[w];
    gate[w].matrix[12]=8<<7; // altfuncindex
  }
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
  gate[w].matrix[3]=CVL[w]; // 5 bits fo first 32 
  gate[w].matrix[4]=CV[w]; 
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[7]=1; //adcfromsd zadcx
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as
  //  gate[w].matrix[9]=0; // no probs

  gate[w].inner=SR_geomantic_inner;
}

/* // revise from above! in many ways
void SR_geomantic_innerADCprob(uint8_t w){  // ADC only so only call from 0
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // CAN just be for w==0
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]])(4095-gate[w].matrix[6], ADCin, w); // now is length as we use 8 for prob!
      if (gate[w].matrix[8]<(LFSR_[w]&4095)) { // way round?
	bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
      }
      else bitn=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
    else {  
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    }
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innerNOS(uint8_t w){   // GSHIFTNOS_; no shift
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFTNOS_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      //      bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); // fill in regg as 3 and adcpar needs changes, length too or???
      bitn=(*adcfromsd[gate[w].matrix[7]])(gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too
    }
    
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// what other inners could be? split speeds for adc, different GSHIFTs and OUTs, inner stack interpreter..., recur?, can also be different lookups!
// also splits as top speeds but add in interpoll maybe...
void SR_geomantic_inner_split1(uint8_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  if (gate[w].trigger){
    GSHIFT_;
  }
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
     SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      //      bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); // fill in regg as 3 and adcpar needs changes, length too or???
      bitn=(*adcfromsd[gate[w].matrix[7]])(gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too
    }
    
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inner_split2(uint8_t w){  
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
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
        
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inner_split3(uint8_t w){  // can also have OUTSIDE Func in... top
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
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}
*/

/*

// what split speeds could be...

outer: on strobe/full speed/ adc, gshift

thus:

out: strobe: gshift, adc, gshift and adc full: gshift, adc, gshift and adc 
inner: nogs, noadc, noadc/gs full: nogs, noadc, noadc/gs

 */
