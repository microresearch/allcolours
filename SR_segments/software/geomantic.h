// 1. speeds - divide into strobe and non strobe - reserve xor ones...

// we need 32 only
uint32_t (*speedfromnostrobe[34])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfracend, spdfracend, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob3_nosh, binroutfixed_prob4_nosh}; // 2x spdfrac and spdfracend for interpoll

// can't include itself in nosh at end so this one is for modeC - geoC
uint32_t (*speedfromnostrobenoend[34])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zinvprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob4_nosh, zSRNbits, zprobbits, zsprobbits}; // 2x spdfrac for interpoll

uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift}; 

uint32_t (*speedfromcvforxor[24])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift};// no strobes, no routes and only CV ones...

// do any of these use depth? strobespdfrac, burst, clksrG, clksr, zprobbits...
uint32_t (*speedfromstrobe[16])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, strobespdfrac, ztogglebits, ztogglebitssh, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift}; 
// we could have more if we use depth - we have xor with speed in inners here below, but we could use depth more??? or just double????

uint32_t usedstrobe[16]={0,1,0,0, 1,1,1,1, 1,0,0,0, 0,0,0,0}; // for strobes - 1 if they use depth...

uint32_t (*speedfromstrobenodepth[10])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift}; 

// not to use...//
uint32_t (*speedfromnew[46])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, spdfrac, spdfrac4, spdfracdac3, spdfracend, ztogglebits, ztogglebitssh, clksrG, clksr, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zprobbits, zinvprobbits, zsprobbits, zTMsimplebits, osceq, zosc1bits, zonebits, zonebitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zbinrouteSRbits, zwiardbits, zwiardinvbits, zjusttail, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob3_nosh, binroutfixed_prob4_nosh};  

// not to use
uint32_t unused[32]={1,0,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,1,1,0, 0,0,0,0}; // for strobes

//uint32_t interpfromnew[32]={0,1,1,0,0,0,0,0,0,0,0,0,0,0}; // TODO match with speedfromnew and make more

uint32_t interpfromnostrobe[32]={1,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}; // TODO match with speedfromnostrobe

uint32_t interpfromnostrobenoend[32]={1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}; // TODO match with speedfromnostrobe

// adc

uint32_t (*adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, cipher, zadcLBURST0, zadccomp, zadcxdouble, zadcxcut, zadc4bitsadd,  zadc4bitsaddmod, zadc4bitsxor, zadc4bitsor, zadc4bitsand, zadc4bitsmodm, zadc4compbitsadd, zadc4compbitsxor, zadc4compbitsmodm, zadc4onecompbitsadd};

// with extra vars for reset and advance for probability
uint32_t (*padcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv)={pzeros, zpadcx, zpadconebitsx, zpadcpadbits, zpadc12bits, zpadc8bits, zpadc4bits, zpadceqbits, zpadcenergybits, zpadc12compbits, zpadc8compbits, zpadc4compbits, zpadccompbits, zpadc12onecompbits, zpadc8onecompbits, zpadc4onecompbits, zpadconecompbits, pcipher, zpadcLBURST0, zpadccomp, zpadcxdouble, zpadcxcut, zpadc4bitsadd,  zpadc4bitsaddmod, zpadc4bitsxor, zpadc4bitsor, zpadc4bitsand, zpadc4bitsmodm, zpadc4compbitsadd, zpadc4compbitsxor, zpadc4compbitsmodm, zpadc4onecompbitsadd};

/////////////////////////

#include "bitsn.h"

// probs - phase out use of this one
uint32_t (*probf[14])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, ones, zinvprobbits, zprobbits, zsprobbits, strobe, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, comp, ztogglebits, ztogglebitssh, zownprobbits, zownGprobbits}; // prob functions and what these can be: eg. ones always selects alt - add other bit ops, changed binrouts to non-shift // testings!

// maybe have parallel probf sans. strobe, zeroes, ones and only depth/cv based!!!
uint32_t (*probfsins[32])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits}; // all use depth // updated with speed

// based on strobe speeds - no depths - how to have more???
uint32_t (*probfstrobes[10])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift};

// with depths
uint32_t (*probfstrobesdepth[6])(uint32_t depth, uint32_t in, uint32_t wh)={strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle}; 

// tails
void (*dotail[32])(void)= {fliptail, basictail, succtail, succtailback, tailC, tailL, tailR, tailN, basictailnos, succtailnos, succtailbacknos, tailCnos, tailLnos, tailRnos, tailNnos, basictailinv, succtailinv, succtailbackinv, tailCinv, tailLinv, tailRinv, tailNinv, basictailnosinv, succtailnosinv, succtailbacknosinv, tailCnosinv, tailLnosinv, tailRnosinv, tailNnosinv, tailXOR0, tailXOR1, tailOR};

// global opps
void (*globalls[21])(uint32_t depth)={resett, binaryN, binaryX, SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalbumpspd, SRRglobalbumpcv, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalsync, SRRglobalorder, SRRglobalbumpcvntype, SRRglobalbumpbit0, SRRglobalbumpbit1, SRRglobalbumpbit2, SRRglobalorderbumpS, SRRglobalorderbumpbit, SRRglobaltailset}; 

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
void SR_geomantic_outer1detach(uint32_t w){  // is not really a detach???
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


//////////////

//// TRIAL2 - moving gaps if we have some kind of binary matrix - or ternary // how? - trial this possible copy in!?
//// but can this be more elegant? we change single set of matrices (could also be inside gate[w] then is back to older matrix idea...
//// but could be 2 dimensions

uint32_t fixedvalues[4][15]={ //  values - but x value means no change... say 4096 ???
  {0},
};

// do we need this? - add extras for dactype, dacpar 
uint32_t *fixedmatrix[4][15]={ // for tests below but is just one matrix and we need multiples... 3d array - do we need as 3d?
  {&CVL[0], &gate[0].matrix[1], &fixedvalues[0][2]}, // &gate[0].matrix[1] - which would keep it the same - examples here...
}; 

uint32_t *fixedvars[4][16]={ // 
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &Gshift_[8]},
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

// question is if we need fixedmatrix or just set matrixp to fixedvalues if needed - for the gap???
// moving gaps - or SR as gaps over... what is the gap??? the leftover
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
  //  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
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
