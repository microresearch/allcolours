// 14/6/2022 moved to geomantic.h

// list of functions:

///TODO: still to add some which got left out...

// routes: binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI,

// speeds: holdlspdfrac, spdfrac, spdfrac2, strobe, ones, clksr, clksrG

// bits: sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI,

// zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits

//1speed 
// now with depth/CV
uint32_t (*speedfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG}; // one interp, next not - see interp below... interp is extracted...
//0 is strobe
// TODO match with interp////////
uint8_t interp[32]={0,1,0,0,0,0,0,0,0,0,0,0,0,0};

//2length
uint32_t (*lengthfromsd[32])(uint32_t depth, uint32_t wh)={nlen, rlen}; // we only have 2 functions here so far

//3adc
uint32_t (*adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits}; 

//4bits
uint32_t (*bitfromsd[59])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, Rtest}; // add in funcs which use also binroutetypecount - this one with depth from variable CV

// counts for maps eg. routes, dacfrom, lengthfrom...
// maps below... for routes
// uint32_t *countfield[8]={&count, &daccount, &spdcount, &adccount, &dactcount, &binroutetypecount, &lengthcount};

// for functions we need to have: 

// speedfunccnt, dactypecnt, lengthfunccnt, adcfunccnt, butfunccnt ///are indexes
// cvcount

uint32_t *funcfield[8]={&dactypecnt, &spdfunccnt, &lengthfunccnt, &adcfunccnt, &bitfunccnt, &cvcount}; // only 6 there

// TODO: versions of this...
// possibly more generic with grid of CV, CVL, DAC[x] which we index from table and pass to speedfrom/bitfroms etc????

// we already have: uint32_t *CVlist[4][16]={
//  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &gate[0].Gshift_[0], &clksr_[0]}, // etc
// so we can also index with dacfrom 0-3 as first ones
// ... but Gshift is 32 bits and clksr we don't use...

uint32_t *CVlist[4][16]={
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &ADCin, &Gshift_[0], &clksr_[0], &param[0]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &ADCin, &Gshift_[1], &clksr_[1], &param[1]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &ADCin, &Gshift_[2], &clksr_[2], &param[2]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &ADCin, &Gshift_[3], &clksr_[3], &param[3]}
  // 0,    1             2             3             4             5       6        7            8           9         10
}; // DONE: how to remedy/gshift - only thing would be a copy of lowest 12 bits &4095: DONE in macro!

// TODO: but this over-rides dacfrom - alternative would be to index as CVlist[dacfrom[w]+1] !!!

//......
// TODO: but these become more like groups now - question is if we have in SR individual array of speedfuncs etc. with own count in
// and we can sync and shift these counts....

// then each would need ref into 4 functions +dac5 + 6 sets of CV???? = 10 or 11 counters each...

//1speed 
uint32_t speedfunc[64][4]={ 
{1,1,1,1}, // 
};

//2length
uint32_t lengthfunc[64][4]={ // these need to return a value 3->31
{1,1,1,0}, // 
};

//3adc
uint32_t adcfunc[64][4]={ 
{1,0,0,0}, // 
};

//4bits
uint32_t bitfunc[64][4]={  //  below just to test things 16 so far - but problem is it can select itself out of the equation unless all are there...
{3,3,3,1},
{3,3,4,1},
{3,3,5,1},
{3,3,6,1},

{3,3,7,1},
{3,3,8,1},
{3,3,9,1},
{3,3,10,1},

{3,3,11,1},
{3,3,12,1},
{3,3,13,1},
{3,3,14,1},

{3,3,15,1},
{3,3,16,1},
{3,3,17,1},
{3,3,18,1},
};
//......//

uint32_t whichdac[64][4]={ // some dacs use param/cv??? which -> 10,12,13,14,16
{0,0,0,0},
};

// binroutetypes is in tables.h for now

// just for speedfrom and bitfrom maybe or...
// so we need index into this list eg.

// TEST: should cvcount be for all - so is gridlike
// 4x4 - geomantic figures - now we have 6 sets here
//  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &ADCin, &Gshift_[3], &clksr_[3], &param[3]}
//   0,        1             2             3             4             5       6        7            8           9         10

uint32_t speedcvin[64][4]={ 
  {5,5,5,5}, // all CV
  {4,1,1,1}, // default - these next are from speedfrom
  {1,1,1,1}, // synced...
  {2,2,2,2}, // synced...
  {3,3,3,3}, // synced...
  {4,4,4,4}, // synced...
  {1,2,3,4}, // itself...

};

uint32_t speedcv[64][4]={ 
  {0,0,0,0}, // this is the modifier
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
  {5,5,5,5}, // all CV
};

uint32_t lengthcv[64][4]={ 
  {6,6,6,6}, // all appropriate CVL  
};

uint32_t adccv[64][4]={ 
  {6,6,6,6}, 
};

uint32_t adccvv[64][4]={ // this is adc itself IN
  {7,0,0,0}, 
};

uint32_t bitcv[64][4]={ 
  {1,1,4,6}, // CVL for tests now 
  {4,4,4,2}, // default - brought in from dacfrom and incremented
  {2,4,2,2}, // new one for rungling 24/1/2022
  {4,1,2,3}, // from latest notebook prev ones: 3,0,1,2
  {1,2,3,4}, // itself
  {4,3,2,1}, // reverse
  {4,4,4,4},
  {3,3,3,3},
  {2,2,2,2},
  {4,4,2,2},
  {2,2,4,4},
  {3,4,1,2}, // opposites
  {2,1,4,3},
  {2,3,4,1}, // nexts
  {4,3,2,1}, /// rev
  {2,4,2,2},
  {2,4,2,2}
};

uint32_t bitcvv[64][4]={ // for comparator functions
  {0,0,0,0}
};

// speedfunccnt, dactypecnt, lengthfunccnt, adcfunccnt, butfunccnt are indexes
// cvcount

// as prototype with modeR global functions but this one can also be adapted... eg. changes of gshift etc...
// also versions with individual entries in and length etc. as just staying static...
// also use some with index as CVlist[dacfrom[w]+1] !!!
void SR_geomantic(uint8_t w){  // working now for basics
  HEADNADA;
  if (interp[speedfunc[spdfunccnt][w]]){   // pulled out interp:
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  CLKSR; // new macro deals with intflag outside speed
  if ((*speedfromsd[speedfunc[spdfunccnt][w]])(*CVlist[w][speedcvin[cvcount][w]],*CVlist[w][speedcv[cvcount][w]], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    gate[w].dactype=whichdac[dactypecnt][w]; // question of dactypes which need param/cv also
    if (lengthfunc[lengthfunccnt][w]!=0){ // so function 0 null should just hold length
    SRlength[w]=(*lengthfromsd[lengthfunc[lengthfunccnt][w]])(*CVlist[w][lengthcv[cvcount][w]],w); // lengthfunc
    }
    GSHIFT_;  // replace with types of gshift - gshiftfuncs...
    // CORE
    if (adccvv[cvcount][w]==7){ // real ADC
    ADCgeneric2; // input into shared one..
    }
    bitn=(*adcfromsd[adcfunc[adcfunccnt][w]])(*CVlist[w][adccv[cvcount][w]], *CVlist[w][adccvv[cvcount][w]],w); // extra param which is INPUT
    bitn^=(*bitfromsd[bitfunc[bitfunccnt][w]])(*CVlist[w][bitcv[cvcount][w]], *CVlist[w][bitcvv[cvcount][w]],w); // extra param for comparators?
    // ENDCORE
    //    if (strobey) bitn|=gate[w].trigger;	 // extra bits in if necessary or is another function
    BITN_AND_OUTV_; // pulsin is in there
    new_data(val,w);
}  
}

/*

GRID? which needs to occupy CV and CVL

speedfroms:
whichdac:
lengthsfroms:
whichadc:
bitfromsd:
bitcv:

how to line up?

 */

/*
- what the sixteen rmodes could be to manipulate these counts: list what we manipulate here and what needs to stay in groups and 
  what can change independently

// uint32_t *countfield[8]={&count, &daccount, &spdcount, &adccount, &dactcount, &binroutetypecount, &lengthcount}; // do we use all of these?
// uint32_t *funcfield[8]={&dactypecnt, &spdfunccnt, &lengthfunccnt, &adctypecnt, &bitfunccnt}; // only 5 there

// countfield is routings, funcfield always needs to match in uses of CV - or could double up?

- we have some below. resetall is on last stop! 63

we have 8 counts we can shift independently with setall below which is clocked by strobe...
or we can have 8 functions for select...

we can bump on all, just one set/group, with strobe, with cv

binary manipulations we have below (one)

also advanced and more recursion of SR (which?) on to groups eg. we can use another speedfrom to bump on counts

 */
