// 14/6/2022 moved to geomantic.h

// pull in from tables also and 000

// 6/6/2022
// pulling in from abstraction.h for testing:
// grids as follows

//1speed 
// now with depth/CV
uint32_t (*speedfromsd[32])(uint32_t depth, uint8_t wh)={adcfrac};

//2length
uint32_t (*lengthfromsd[32])(uint32_t depth, uint8_t wh)={rlen}; 

//3adc
uint32_t (*adcfromsd[32])(uint32_t depth, uint8_t wh)={noadc, adcxbitsx}; 

//4bits
uint32_t (*bitfromsd[32])(uint32_t depth, uint8_t wh)={osceqbits, binroutebits}; // add in funcs which use also binroutetypecount - this one with depth from variable CV

// counts for maps eg. routes, dacfrom, lengthfrom...
// maps below... for routes
// uint32_t *countfield[8]={&count, &daccount, &spdcount, &adccount, &dactcount, &binroutetypecount, &lengthcount};

// for functions we need to have: 

uint32_t *funcfield[8]={&dactypecnt, &spdfunccnt, &lengthfunccnt, &adcfunccnt, &bitfunccnt}; // only 5 there

// TODO: versions of this...
// possibly more generic with grid of CV, CVL, DAC[x] which we index from table and pass to speedfrom/bitfroms etc????

// we already have: uint32_t *CVlist[4][16]={
//  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &gate[0].Gshift_[0], &clksr_[0]}, // etc
// so we can also index with dacfrom 0-3 as first ones
// ... but Gshift is 32 bits and clksr we don't use...

uint32_t *CVlist[4][16]={
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &Gshift_[0], &clksr_[0], &param[0]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &Gshift_[1], &clksr_[1], &param[1]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &Gshift_[2], &clksr_[2], &param[2]},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &Gshift_[3], &clksr_[3], &param[3]}
  // 0,    1             2             3             4             5       6        7            8           9   
}; // DONE: how to remedy/gshift - only thing would be a copy of lowest 12 bits &4095: DONE in macro!

// TODO: but this over-rides dacfrom - alternative would be to index as CVlist[dacfrom[w]] !!!

//......
//1speed 
uint32_t speedfunc[64][4]={ 
{0,0,0,0}, // 
};

//2length
uint32_t lengthfunc[64][4]={ // these need to return a value 3->31
{0,0,0,0}, // 
};

//3adc
uint32_t adcfunc[64][4]={ 
{0,0,0,0}, // 
};

//4bits
uint32_t bitfunc[64][4]={ 
{1,1,1,1}, // 
};
//......

uint32_t whichdac[64][4]={ // some dacs use param/cv??? which -> 10,12,13,14,16
{0,0,0,0},
};

// binroutetypes is in tables.h for now

// just for speedfrom and bitfrom maybe or...
// so we need index into this list eg.

// should cvcount be for all - so is gridlike

uint32_t speedcv[64][4]={ 
  {5,5,5,5}, // all appropriate CV
};

uint32_t lengthcv[64][4]={ 
  {6,6,6,6}, // all appropriate CVL
};

uint32_t adccv[64][4]={ 
  {6,6,1,6}, // 0 is for nulll=0 == no depth used!
};

uint32_t bitcv[64][4]={ 
  {6,6,1,6}, // 0 is for nulll=0 == no depth used!
};

/// reworking for adjustable CVs - TODO: adc as a function also...

// as prototype with modeR global functions but this one can also be adapted... eg. changes of gshift etc...
void SR_geomantic(uint8_t w){  // working now for basics
  HEADNADA;
  if ((*speedfromsd[speedfunc[spdfunccnt][w]])(*CVlist[w][speedcv[cvcount][w]],w)){ // speedfunc
    CLKSR; // new macro deals with intflag within speed
    gate[w].dactype=whichdac[dactypecnt][w]; // question of dactypes which need param/cv also
    SRlength[w]=(*lengthfromsd[lengthfunc[lengthfunccnt][w]])(*CVlist[w][lengthcv[cvcount][w]],w); // lengthfunc
    GSHIFT_;  // replace with types of gshift - gshiftfuncs...
    // CORE
    bitn=(*adcfromsd[adcfunc[adcfunccnt][w]])(*CVlist[w][adccv[cvcount][w]],w); // trial this! seems to work
    bitn^=(*bitfromsd[bitfunc[bitfunccnt][w]])(*CVlist[w][bitcv[cvcount][w]],w); // trial this! seems to work
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
