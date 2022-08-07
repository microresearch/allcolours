// 14/6/2022 moved to geomantic.h

// list of functions:

///TODO: still to add some which got left out...

// routes: binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI,

// speeds: holdlspdfrac, spdfrac, spdfrac2, strobe, ones, clksr, clksrG

// bits: sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI,

// zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits

//0function outside speed
uint32_t (*outside[32])(uint32_t depth, uint32_t wh)={OUT_zero, OUT_SRdelay_lineIN}; // delay bin needs to match with delay out, or shared delay lines...

//0.5gshift
uint32_t (*gshifts[32])(uint32_t wh)={gshift0, gshiftnull};

//1speed 
// now with depth/CV
uint32_t (*speedfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, spdfracend, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG, speedselcvl, speedselcvm}; // one interp, next not - see interp below... interp is extracted... add in binroutes

// 5,6,8,9 dont work-> all to do with trigger!

//0 is strobe
// TODO match with interp////////
uint8_t interp[32]={0,1,1,0,0,0,0,0,0,0,0,0,0,0};

//2length IGNORE!
uint32_t (*lengthfromsd[32])(uint32_t depth, uint32_t wh)={nlen, rlen, holdlen}; // we only have 2 functions here so far - nlen is null/hold, what other functions

//3adc
uint32_t (*adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, adcselcvm, adcselcvl, probcvladcselcvm, probdacadcsel}; 

uint32_t (*dacfunc[32])(uint32_t depth, uint32_t wh)={ddac0, ddac1, ddac2, ddac3, ddac4, ddac5, ddac6, ddac7, ddac8, ddac9, ddac10, ddac11, ddac12, ddac13, ddac14, ddac15, ddac16, ddac17, ddac18, ddac19, ddac20, ddac21, ddac22, ddac23, ddac24, dacselcvl, dacselcvm};

//4bits
uint32_t (*bitfromsd[66])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, Rtest, gensel, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, SRdelay_lineOUT}; // viennabits 

//5newfunc
//uint32_t (*newfunc[32])(uint32_t depth, uint32_t wh)={zero, bitsmod, cvmod}; //

/*
uint32_t *CVlist[4][22]={ // TAIL is &Gshift_[8] // add in statics for adc, dac and length
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &CVM[0], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &Gshift_[8], &gate[0].oldcv, &gate[0].oldcvl, &gate[0].oldcvm, &gate[0].adctype, &gate[0].dactype, &SRlength[0]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &CVM[1], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[1], &param[1], &Gshift_[8], &gate[1].oldcv, &gate[1].oldcvl, &gate[1].oldcvm, &gate[1].adctype, &gate[1].dactype, &SRlength[1]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &CVM[2], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[2], &param[2], &Gshift_[8], &gate[2].oldcv, &gate[2].oldcvl, &gate[2].oldcvm, &gate[2].adctype, &gate[2].dactype, &SRlength[2]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &CVM[3], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[3], &param[3], &Gshift_[8], &gate[3].oldcv, &gate[3].oldcvl, &gate[3].oldcvm, &gate[3].adctype, &gate[3].dactype, &SRlength[3]}
};
*/
  // 0,    1             2             3             4             5       6        7            8           9         10     11 -> 19

// 0 null 1 0dac 2 1dac 3 2dac 4 3dac 5 CV 6 CVL 7 CVM 8 ADCin 9 Gs0 10 Gs1 11 Gs2 12 Gs3 13 clksr_ 14 param 15 par 16 oldcv 17 oldcvl 18 oldcvm

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

/// we need to list/catalogue: ADCs, speeds, bits of various descriptions... // overlap/overlay of bits and speeds

// that catalogues can also be kind of matrices, with holes and exceptions... used by different interpreters eg. speedfromnostrobe, speedfromabstract, speedfromroutes

//uint32_t (*speedfromsdd[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksrG, clksr, strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG, strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG, spdfrac, spdfrac};

uint32_t (*speedfromnostrobe[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac, holdlspdfrac, ones};//

uint32_t (*speedfromnew[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksrG, clksr, zbinroutebits_noshift, zbinroutebits_noshift_transit, zprobbits, zTMsimplebits, osceq, zosc1bits, zonebits, zENbits, zENsbits, zcompbits, zosc1bits, sigmadelta, cipher, osceq, zpulsebits, zprobbits, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, spdfrac}; //21+11
// also indie versions

// trial INNER/OUTER - but for now is just another matrix op/array/could also be stack so we need to do more inside it! it does allow us to leave elements remaining...
// we could have stack with index an mark unchanging as what? - as top bit of 32 bits

// INNER
// leave details such as interpol etc out so we can just try minimal and fill in details 
// divide as adc/nonadc
void SR_geomantic_inner(uint32_t w){  // no prob
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

//eg. outer function: on functionchange select speedfrom using CVL, speedcv is CV, bitin is unchanged, bitcv is unchanged, lencv is unchanged...
// but not ON functionchange we set... as we need CV and to change speedfrom but can be variations:

// 5/8/2022 adding prob/bit
// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv, 11altfuncindex}
void SR_geomantic_outer(uint32_t w){  // do as array of functions // keep this as works oddly with default 3 bitfunc=2 which is binroutfixed
  gate[w].matrix[0]=CVL[w]>>7;// 5 bits is 32 //2 bits //speedFUNC
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //???
  gate[w].matrix[2]=CVL[w];//gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[4]=CVL[w]; // unused in case2: bintroutfixed // but used by altfunc
  gate[w].matrix[6]=CVL[w]; //length
  gate[w].matrix[10]=CVL[w];
  // rest is unchanged but we need to set/reset a default - so we will have a reset function
  //  if (w==0) { // set adc in adcfromsd
  gate[w].matrix[8]=CVL[w]; // was 4095- but we shift that to the ADC

  //can we select and call inner from here... or just use a macro so is inlined... then starts to look again like a function
  // and that is not detachment... so we just set function eg. so that it persists or can be re-attached/detached
  gate[w].inner=SR_geomantic_inner;

}  

void SR_geomantic_outer_binr(uint32_t w){ // test just simplest binroute in/spdfrac
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  gate[w].matrix[0]=3; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=2; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[7]=1; //adcfromsd zadcx
  gate[w].matrix[8]=CVL[w]; // length
  gate[w].matrix[9]=0; // no probs
}

void SR_geomantic_inneradc(uint32_t w){  // no prob - but this should be done in outers
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
    bitn=(*adcfromsd[gate[w].matrix[7]])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innernoadc(uint32_t w){  // no prob
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}


uint32_t (*probf[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, ones, zinvprobbits, zprobbits, zsprobbits, strobe, binrout, binroutfixed, comp}; // prob functions and what these can be: eg. ones always selects alt
// regular probs vs. LFSR, depth<in, bit functions, SR bits, routes... what do we need to add

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
// new version with prob
void SR_geomantic_innernadcp(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

    if (w==0){ // real ADC - TESTY - how we will handle adc across all - maybe remove
      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    }
    
    if ((*probf[gate[w].matrix[9]])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn^=(*bitfromsd[gate[w].matrix[12]])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inneradcp(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...

      ADCgeneric2; // input into shared one... not if we use ADC_ - this should really be a function so we can have prob...
      bitn=(*adcfromsd[gate[w].matrix[7]])(4095-gate[w].matrix[8], ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too // adc could also be DAC in? how?
    
    if ((*probf[gate[w].matrix[9]])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn^=(*bitfromsd[gate[w].matrix[12]])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innernoadcp(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    if ((*probf[gate[w].matrix[9]])(gate[w].matrix[10], gate[w].matrix[11], w)){
    bitn^=(*bitfromsd[gate[w].matrix[12]])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
  else {
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
  }
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

/* // revise from above!
void SR_geomantic_innerADCprob(uint8_t w){  // ADC only so only call from 0
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
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
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
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
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
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
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
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
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc -speedfromsdd!
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
