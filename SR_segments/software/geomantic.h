// TODO: start to test and sort all grouped functions here, new groups, see exp_port.h, and 
//

// speeds

uint32_t (*speedfromnostrobe[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac, spdfracend, ones};//

uint32_t (*speedfromnew[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, spdfracend, strobe, ztogglebits, ones, clksrG, clksr, zbinroutebits_noshift, zbinroutebits_noshift_transit, zprobbits, zTMsimplebits, osceq, zosc1bits, zonebits, zENbits, zENsbits, zcompbits, zosc1bits, sigmadelta, cipher, osceq, spdfrac, zprobbits, zsuccbits, zsuccbitsI, zreturnbits, spdfrac, zosc1bits, spdfrac}; //21+11 = 32 now // fix/add extras for extra spdfrac gaps
// also indie versions, other binroutes which don't shift... other bitfromsd

uint32_t unused[32]={1,0,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,1,1,0, 0,0,0,0};// matches speedfromnew to free up CV[w]

uint32_t (*speedfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, spdfracend, strobe, ztogglebits, ones, clksr, clksrG}; // one interp, next not - see interp below... interp is extracted... add in binroutes // retest--->5,6,8,9 dont work-> all to do with trigger! // spdfracend = 4 which is stopping version on LOWEST

uint8_t interp[32]={0,1,1,0,0,0,0,0,0,0,0,0,0,0}; // TODO match with interp//////// but depends on which speedfrom we use!

// adc

uint32_t (*adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits};/// ???///, adcselcvm, adcselcvl, probcvladcselcvm, probdacadcsel}; // add to these

//uint32_t (*adcfromsdd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits}; // doubled up // TEST!

// bits // can divide into further: abstract, includesprob, routings - which ones rely on other SRs!
uint32_t (*bitfromsd[69])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, binrout, binroutfixed, binroutor, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, Rtest, gensel, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4,  viennabits, tailbits};//  - how many can we have - different sets...
// SRdelay_lineOUT??? needs it input pair?

uint32_t (*expetcbits[43])(uint32_t depth, uint32_t in, uint32_t wh)={pSR_binr, pSR_routeSRbits00, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer12, pSR_reflect, pSR_altbin1, pSR_insert_zero, pSR_probbin, pSR_recbin, pSRhold, pSRholdfromdac, pSRxorSR, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortog, pSRmatch, pSRshare, pSRGswop, pSRshroute, pSRsigma, pbitSRroutelog, pbitSRroutelogxx, pbitLcvsrroute, pbitSRroutelogxxx, pbitSRroutedoit, pbitLSRroutexxxlog, pprobintprob1, pprobintprob2, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pstream}; // 43 there are...

// prob // regular probs vs. LFSR, depth<in, bit functions, SR bits, routes... what do we need to add

uint32_t (*probf[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, ones, zinvprobbits, zprobbits, zsprobbits, strobe, binrout, binroutfixed, comp}; // prob functions and what these can be: eg. ones always selects alt

////////////////////////////////////////////////////////////////////////////////
//INNERS --- (before OUTER as we point to them)
////////////////////////////////////////////////////////////////////////////////

// leave details such as interpol etc out so we can just try minimal and fill in details 
// divide as adc/nonadc
void SR_geomantic_inner(uint32_t w){  // no prob
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
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

void SR_geomantic_innernoadcp(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
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

void SR_geomantic_innernoadcrung(uint32_t w){  // for generic rungler - route XOR function
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*bitfromsd[gate[w].matrix[12]])(gate[w].matrix[4], gate[w].matrix[5], w);
    bitn^=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w); // problem is same CVs
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_inneradc(uint32_t w){  // no prob - but this should be done in outers
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
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
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn=(*bitfromsd[gate[w].matrix[3]])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

// new version with prob
void SR_geomantic_innernadcp(uint32_t w){  
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
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
  if ((*speedfromnew[gate[w].matrix[0]])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
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

////////////////////////////////////////////////////////////////////////////////
//OUTERS
////////////////////////////////////////////////////////////////////////////////

//what we can use in outer modes:  &nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[x], &CVL[x], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[x], &param[x], &Gshift_[8]
// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
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

  gate[w].inner=SR_geomantic_inner;
}  


// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
// 8/8/2022 testing strobe and fake pulses/normed pulses in caput000.c
void SR_geomantic_outer_test(uint32_t w){  // set up so we can test different functions eg. now try different speedfuncs
  if (gate[w].changed==0) { // 1=change 0= no change
  gate[w].matrix[0]=3;// 0 was strobe // CVL[w]>>7;// 5 bits is 32 //2 bits //speedFUNC
  if (unused[gate[w].matrix[0]]) {
    gate[w].matrix[9]=3; // probbits as we can now use CV
    gate[w].matrix[10]=CV[w];
    gate[w].matrix[12]=8; // altfuncindex
  }
  gate[w].matrix[1]=CV[w];//
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[3]=2; // fixed route
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
    gate[w].matrix[0]=CVL[w]>>7;// 5 bits is 32 //2 bits //speedFUNC
    
    if (unused[gate[w].matrix[0]]) {
      gate[w].matrix[9]=3; // probbits as we can use CV
      gate[w].matrix[10]=CV[w];
      gate[w].matrix[12]=8; // altfuncindex
      gate[w].inner=SR_geomantic_innernoadcp; // prob one
  }
  else  gate[w].inner=SR_geomantic_innernoadc; // no prob
  
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[3]=2; // fixed route/binrout
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
  gate[w].matrix[3]=2; // fixed route/binrout
  //  gate[w].matrix[4]=CVL[w]; // unused in case2: bintroutfixed // but used by altfunc
  gate[w].matrix[6]=CVL[w]; //length

  gate[w].inner=SR_geomantic_innernoadcp; // prob one
    }
}  

void SR_geomantic_outer_testT3(uint32_t w){  // to start to check transition between fixed and unfixed. set speedmode to... ONEs
  if (gate[w].changed==0) { // 1=change 0= no change
    gate[w].matrix[0]=7; // ones for test
    gate[w].matrix[10]=CV[w]; // we keep this for probcv (if we have free Cv left over) but prob/index is set elsewhere and function...
    
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[2]=gate[dacfrom[daccount][w]].dac; // but we need 2nd cv
  gate[w].matrix[3]=2; // fixed route/binrout
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

void SR_geomantic_outer_binr(uint32_t w){ // test just simplest binroute in/spdfrac
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  gate[w].matrix[0]=3; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=2; // fixed route
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].matrix[9]=0; // no probs

  gate[w].matrix[8]=CVL[w]; // length for adc same as
  
  gate[w].inner=SR_geomantic_inner;
}

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
void SR_geomantic_outer_binrp(uint32_t w){ // binr with probability of: cycle // what are other prob modes we have
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  gate[w].matrix[0]=3; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=5; // binroutfixed_prob1
  gate[w].matrix[4]=CVL[w]; // prob -

  gate[w].inner=SR_geomantic_inner;
}

void SR_geomantic_outer_binrpp(uint32_t w){ // binr with probability of: cycle // more flexible as "real" probability - what those gaps could be?
  //  uint32_t matrixNN[12]={0,0,0, 2,0,0, 31<<7, 1,0, 0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
  gate[w].matrix[0]=3; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=3; // binroutfixed
  //  gate[w].matrix[4]=CVL[w]; // prob
  gate[w].matrix[9]=3; // probbits as we can use CV
  gate[w].matrix[10]=(gate[dacfrom[daccount][w]].dac+CVL[w])&4095; // detach this too // or rather one new form of re-attachment - we can also use value functions here!! // another layer of attach/detach
  gate[w].matrix[12]=4; // altfuncindex - now for justcycle // no cv needed

  gate[w].inner=SR_geomantic_innernoadcp;
}


/* how to define a rungler as depends on routing - options: rungler for route as we have it, rungler with specific sets of modes, generic rungler (what did we have for that?)

see rungler.h

x: genX, spdfrom z + offset // optional route in from zz
y: genX, spdfrom z + own offset // optional route in from zz
z: route in from x, spd from y + own offset // optional route in from zz- OUT?, it cycles
zz: tail. process of z and feedback to x, y or z.

N- spdfrom C routefrom - optional z/zz - type of gen/adc
L-         C           - optional z/zz - type of gen/adc
C-         NorL        - NorL-dep on spdfrom/cycle? - type of dac
R-         CV/C,NorL?  - C,NorL/ - type of processor/tail

makes more for 4,4,1,2

*/

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
  gate[w].matrix[0]=0; // strobe
  //  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=CVL[w]>>7; // 5 bits fo first 32 
  gate[w].matrix[4]=CV[w]; 
  gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac;
  //  gate[w].matrix[6]=CVL[w]; // length
  //  gate[w].matrix[7]=1; //adcfromsd zadcx
  //  gate[w].matrix[8]=CVL[w]; // length for adc same as
  //  gate[w].matrix[9]=0; // no probs

  gate[w].inner=SR_geomantic_inner;
}

/* // revise from above!
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
