// for new geomantic abstraction: start again again with generics - this one for binroutes
//     [need better labelling scheme]

/*

- how that looks for inputs - what we compare to what?
- or we just have list of probs to make things easier...

- and for bits: bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;

*invert routed/bit*
*routed vs cycling// routed vs inverted cycling*
*routed vs [routed^cycling]*

 */


/*

- for speeds/bits - return bits - for adc=bits: can be adc, dac (as input with adc style processing), or bits as for speed/bits - make more generic

but speed ones handle dac/interpol

- for length: return length/0-31 - could plug in other functions
// so length as seperate or as a re-processor...

merge all bits for speeds, for adc

how to label/categorise: 

- deal with a route
- abstract bit routines
- process a value
- deal with adc
- deal with dac but:

could we even abstract out further so adc/13 is depth input - but also look at adcs
and function is a processor of these to return bits

return a value from bits (this is what dacs do)... process a value... generate a value (eg. from a route)

value to bits (adc)
bits to values (dac)

*/  

// generic probability to test for adapted rungler in // unused
static inline uint32_t genericprob(uint32_t cv, uint32_t against, uint32_t bit1, uint32_t bit2){
  if (cv>against) return bit1;
  else return bit2;
}



uint32_t funcmax[64][13]={
  {8,2,17,61,23, 11,11,11,11,11,11,11,11}, // maximum value if x>funcmax... // update these as we add more functions
};

uint32_t funcN[64][13]={
  //  {1,1,1,0,0, 5,0,6,0,6,8,0,0}, // first set is from geomantic.h with test of dacmix!
      {2,0,1,59,0, 5,6,6,0,6,8,6,7}, // for rungler with speed from R
};

uint32_t funcL[64][13]={
  //    {1,1,0,2,0, 5,0,6,0,6,0,1,0},
    {2,0,0,59,0, 5,6,6,0,6,0,6,7}, // rung2
};

uint32_t funcC[64][13]={
  //  {1,1,0,2,1, 5,0,6,0,6,0,1,0},
  {1,0,0,60,1, 5,0,6,7,0,0,4,0}, // rung - speed from cv, route from R //
};


uint32_t funcR[64][13]={
  {2,1,0,61,0, 5,6,6,0,0,0,1,0}, // route from L, speed from N
};


// counts for maps eg. routes, dacfrom, lengthfrom...
// maps below... for routes
// uint32_t *countfield[8]={&count, &daccount, &spdcount, &adccount, &dactcount, &binroutetypecount, &lengthcount};

// for functions we need to have: 

// speedfunccnt, dactypecnt, lengthfunccnt, adcfunccnt, bitfunccnt ///are indexes
// cvcount

uint32_t *funcfield[8]={&dactypecnt, &spdfunccnt, &lengthfunccnt, &adcfunccnt, &bitfunccnt, &cvcount}; // only 6 there

// TODO: versions of this...
// possibly more generic with grid of CV, CVL, DAC[x] which we index from table and pass to speedfrom/bitfroms etc????

// we already have: uint32_t *CVlist[4][16]={
//  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &gate[0].Gshift_[0], &clksr_[0]}, // etc
// so we can also index with dacfrom 0-3 as first ones
// ... but Gshift is 32 bits and clksr we don't use...

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
  {3,3,3,1}, // was 3,3,3,1
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

uint32_t daccv[64][4]={ 
  {0,0,0,0}, // 
};


uint32_t adccv[64][4]={ 
  {6,6,6,6}, 
};

uint32_t adccvv[64][4]={ // this is adc itself IN
  {7,0,0,0}, 
};

uint32_t bitcv[64][4]={ 
  {5,5,5,5}, // CVL for tests now = 5,5,5,5
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
    gate[w].dacpar=*CVlist[w][daccv[cvcount][w]];
    if (lengthfunc[lengthfunccnt][w]!=0){ // so function 0 null should just hold length
    SRlength[w]=(*lengthfromsd[lengthfunc[lengthfunccnt][w]])(*CVlist[w][lengthcv[cvcount][w]],w); // lengthfunc
    }
    GSHIFT_;  // replace with types of gshift - gshiftfuncs...
    // CORE
    if (adccvv[cvcount][w]==8){ // real ADC
      ADCgeneric2; // input into shared one..
    }
    bitn=(*adcfromsd[adcfunc[adcfunccnt][w]])(4095-(*CVlist[w][adccv[cvcount][w]]), *CVlist[w][adccvv[cvcount][w]],w); // extra param which is INPUT - inverted?
    bitn^=(*bitfromsd[bitfunc[bitfunccnt][w]])(*CVlist[w][bitcv[cvcount][w]], *CVlist[w][bitcvv[cvcount][w]],w); // extra param for comparators?
    // ENDCORE
    //    if (strobey) bitn|=gate[w].trigger;	 // extra bits in if necessary or is another function
    BITN_AND_OUTV_; // pulsin is in there
    new_data(val,w);
}  
}

/*
from CVM-12 bits-> spdfunc, lengthfunc, adcfrom, bitfrom, dactype

or CVM can be xxxfuncnct - how we organise this?

// 

 */

void SR_geomanticx(uint8_t w){  // for alternative arrays... working now
  HEADNADA;
  if (interp[gate[w].func[spdfunccnt][fspeed]]){ // gate[w].func[spdfunccnt][fspeed]

    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
   if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  CLKSR; // new macro deals with intflag outside speed
  if ((*speedfromsd[gate[w].func[spdfunccnt][fspeed]])(*CVlist[w][gate[w].func[cvcount][cvspeed]],*CVlist[w][gate[w].func[cvcount][cvspeedmod]], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    gate[w].dactype=gate[w].func[dactypecnt][fdac]; // question of dactypes which need param/cv also
    gate[w].dacpar=*CVlist[w][gate[w].func[cvcount][cvdac]];

    
    if (gate[w].func[lengthfunccnt][flength]!=0){ // so function 0 null should just hold length
    SRlength[w]=(*lengthfromsd[gate[w].func[lengthfunccnt][flength]])(*CVlist[w][gate[w].func[cvcount][cvlength]],w); // lengthfunc
    }
    GSHIFT_;  // replace with types of gshift - gshiftfuncs...
    // CORE
    
    if (gate[w].func[cvcount][cvadcIN]==8){ // real ADC
    ADCgeneric2; // input into shared one..
    }
    bitn=(*adcfromsd[gate[w].func[adcfunccnt][fadc]])(4095-(*CVlist[w][gate[w].func[cvcount][cvadc]]), *CVlist[w][gate[w].func[cvcount][cvadcIN]],w); // invert?
    bitn^=(*bitfromsd[gate[w].func[bitfunccnt][fbit]])(*CVlist[w][gate[w].func[cvcount][cvbit]], *CVlist[w][gate[w].func[cvcount][cvbitcomp]],w);
    // ENDCORE
    //    if (strobey) bitn|=gate[w].trigger;	 // extra bits in if necessary or is another function
    BITN_AND_OUTV_; // pulsin is in there
    new_data(val,w);
}  
}


//enum refs {fspeed, flength, fadc, fbit, fdac, cvspeed, cvspeedmod, cvlength, cvdac, cvadc, cvadcIN,  cvbit, cvbitcomp};

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



//prev groups

adcdraft0, adcdraft1, adcLparallel, adcLparallel2, adcLdraft2, adcnoroute0, adc0nog, adcorxor0, adcbumproute0, adcbumproutebin0, adcghostroute0, adcDACroute0, adcSRroute0, adcbin1_0, adcLCVDACroute, adcmultiplespeednew0, adcLdoublelength, adcLflip, adcLbinrstr, adcLbitprob, adcspeedstream, adcbinspeedstream, binspeedcycle, binnospeedcycle, adcLabstract, adcLabstractNOG, adcLabstractI, adcLabstractQIN, adcLTMinTM, adcLabstractTM, adcLFROM, adcLpattern95, adcLpatternbin95, adcLtm101, adcLtm102, adcLtm103, adcLtm104, adcLtm105, adcLcomp20, adcLsub92, adcLsplice100, adcLBURST0, adcLseladc, adcLcutfeedback86, adcLseladc1, adcLseladc2, adcLseladc5th, adcLseladcdac5th, adcdacmod5th, adcLpulse89, adcLSRlengthsel, adcLSRlengthsel0, adcLLswop0, adcgenericprobx, adcdacadditself0, adcdacghostitself0, adcdacghostincoming0, adcdacseladd0, adcdacseloffosc, adcdacseloffosc2, adcLrung0, adcLrung1, adcLrung2, adcrung0, adcdacadd0, adcdacaddmax0, adcdacminus0, adcdacspeedminus0, adcdacmod0, adcdacB0, adcdacoffset0, adcLdacadc, SR_binr_adc0, adc_overonebit, adcone_bitreset, adc0_newgsr, ADCovers, ADCoverss, ADCoversss, ADCoverssss, ADChold, ADCholdcycle, ADCnoisecmp, adccipher, adccipher2, noSRadc, adcLrung0, adcLrung1, adcLrung2, adcrung0, adcdacadd0, adcdacaddmax0, adcdacminus0, adcdacspeedminus0, adcdacmod0, adcdacB0, adcdacoffset0, adcLdacadc, SR_binr_adc0, adc_overonebit, adcone_bitreset, adc0_newgsr, ADCovers, ADCoverss, ADCoversss, ADCoverssss, ADChold, ADCholdcycle, ADCnoisecmp, adccipher, adccipher2, noSRadc

SR_cvbits, SRdacplusminus, SR_binr_fixed, SR_binr, SR_binr_dac0, SR_routeSRbits00, SR_routeSRbits01, SR_routeSRbits02, SR_layer12, SR_reflect, SR_altbin1, SR_binspdx, SR_insert_zero, SR_insert_zero_dac2, SRdelay_lineIN, SRintodel, SR_probbin, SRX0_newgsr, SRX0_newgsr_nores, SRholdspd, SRownspd, SR_recbin, SR_splitx, SRhold, SRholdfromdac, SRothers, SR_genspeed2, SR_genspeed3, SRghost, SRghostlatch, SRxorSR, SRxorroutes, SRaddroutes, SR_vienna, SR_switchspeed, SR_selspeed, SRprobxortog, SRprobxortogx, SRmatch, SRshare, abstractoutinterpolnoshift, abstractoutinterpol, abstractoutinterpolroute, abstractoutinterpolrung, SRmultiplespeednewdac0, SRmultiplespeednewdac, noSRdelay_line, SRdelay_lineSH, SRdelay_lineSH2, SRdelay_line, SRpattern_unshare, SRLdecaying, SRGswop, noSRselxorroutes, SRprobwheel, dacNbinprob, SRLprobnog, SRsigma, SRshiftQ1, SRsuccroute, SRNwas14, SRNprob, SRNwas15, SRN3, SRN4, SRN5, SRN6, SRN7, SRN8, SRN10, SRN11, SRN12, SRN13, SRN14, SRN15, SRN21, SRN22, SRN29, SRN30, SRN33, SRN33cipher, SRN34, SRNsr35, SRN35, SRN36, SRN38, SRN40, SRLLswop, SRN42, SRN46, SRN48, SRN50, SRN62, SRN65, SRNwas13, SRno, SR0, SR0nog, SR1, SR2, SR3, SR4, SRosc, SRmod, SRbumproute, SRLLbumproute, SRDACroute, SRSRroute, SR32, SRmultiplespeednew, SRmultiplespeed0, SRmultiplespeed1, SRmultiplespeed2


              dacNLRin, dacNLRinlogic, dacLRprob, dacLRprobxorN, dacNLRprobin1311, dacLNLRin, dacadc, dacosc0, dacLLswop, dacN, dacLBURST0, dacL16slide, dacLrung0, dacN17_0, dacN18_0, dacLDACSEL0, dacL12, dacLDACSRSEL0, dac0, dacnov0, dac0nog, dac1, dac3, dac4, dac5, dac6, dac7, dac8, dac9, dac10, dac11, dac12, dac13, dac14, dac15, dacreal15, dac17, dac18, dac19, dac20, dac21, dac67_4bits, dac67_4bitsNOGG, dac66, dac68, dacbumproute0, dacDACroute0, dacSRroute0, dac32, dacdacadditself0, dacdacghostitself0, dacdacghostincoming0, dacdacseladd0, dacdacadd0, dacdacminus0, dacdacspeedminus0, dacdacmod0, dacB0, dacdacoffset0, dacbus, dacbusothers, dacbusothers_clk, dacbusothers_sr, dacbusothers_own, noSRdac, noSRdac2sRLxor, SR_cvbits, SRdacplusminus, SR_binr_fixed, SR_binr, SR_binr_dac0, SR_routeSRbits00, SR_routeSRbits01, SR_routeSRbits02, SR_layer12, SR_reflect, SR_altbin1, SR_binspdx, SR_insert_zero, SR_insert_zero_dac2, SRdelay_lineIN, SRintodel, SR_probbin, SRX0_newgsr, SRX0_newgsr_nores, SRholdspd, SRownspd, SR_recbin, SR_splitx, SRhold, SRholdfromdac, SRothers, SR_clksrG, SR_clksr, SR_genspeed2, SR_genspeed3, SRghost, SRghostlatch, SRxorSR, SRxorroutes, SRaddroutes, SR_vienna, SR_switchspeed, SR_selspeed, SRprobxortog, SRprobxortogx, SRmatch, SRshare, abstractoutinterpolnoshift, abstractoutinterpol, abstractoutinterpolroute, abstractoutinterpolrung, SRmultiplespeednewdac0

  SR_cvbits, SRdacplusminus, SR_binr_fixed, SR_binr, SR_binr_dac0, SR_routeSRbits00, SR_routeSRbits01, SR_routeSRbits02, SR_layer12, SR_reflect, SR_altbin1, SR_binspdx, SR_insert_zero, SR_insert_zero_dac2, SRdelay_lineIN, SRintodel, SR_probbin, SRX0_newgsr, SRX0_newgsr_nores, SRholdspd, SRownspd, SR_recbin, SR_splitx, SRhold, SRholdfromdac, SRothers, SR_clksrG, SR_clksr, SR_genspeed2, SR_genspeed3, SRghost, SRghostlatch, SRxorSR, SRxorroutes, SRaddroutes, SR_vienna, SR_switchspeed, SR_selspeed, SRprobxortog, SRprobxortogx, SRmatch, SRshare, abstractoutinterpolnoshift, abstractoutinterpol, abstractoutinterpolroute, abstractoutinterpolrung, SRmultiplespeednewdac0, noSRdelay_line, SRdelay_line



// 15 octaves now
const float slowerlog[1024]  __attribute__ ((section (".flash"))) = {1.000000f, 0.989888f, 0.979878f, 0.969970f, 0.960161f, 0.950452f, 0.940841f, 0.931328f, 0.921910f, 0.912588f, 0.903360f, 0.894225f, 0.885183f, 0.876232f, 0.867371f, 0.858600f, 0.849918f, 0.841324f, 0.832816f, 0.824395f, 0.816059f, 0.807807f, 0.799638f, 0.791552f, 0.783548f, 0.775625f, 0.767782f, 0.760018f, 0.752333f, 0.744725f, 0.737195f, 0.729740f, 0.722361f, 0.715056f, 0.707826f, 0.700668f, 0.693583f, 0.686570f, 0.679627f, 0.672755f, 0.665952f, 0.659218f, 0.652552f, 0.645953f, 0.639421f, 0.632955f, 0.626555f, 0.620219f, 0.613948f, 0.607739f, 0.601594f, 0.595511f, 0.589489f, 0.583528f, 0.577627f, 0.571786f, 0.566005f, 0.560281f, 0.554616f, 0.549007f, 0.543456f, 0.537960f, 0.532521f, 0.527136f, 0.521805f, 0.516529f, 0.511306f, 0.506135f, 0.501017f, 0.495951f, 0.490936f, 0.485972f, 0.481058f, 0.476193f, 0.471378f, 0.466611f, 0.461893f, 0.457222f, 0.452599f, 0.448022f, 0.443492f, 0.439007f, 0.434568f, 0.430174f, 0.425824f, 0.421518f, 0.417255f, 0.413036f, 0.408860f, 0.404725f, 0.400633f, 0.396581f, 0.392571f, 0.388602f, 0.384672f, 0.380782f, 0.376932f, 0.373120f, 0.369347f, 0.365612f, 0.361915f, 0.358256f, 0.354633f, 0.351047f, 0.347497f, 0.343983f, 0.340505f, 0.337062f, 0.333653f, 0.330280f, 0.326940f, 0.323634f, 0.320361f, 0.317122f, 0.313915f, 0.310741f, 0.307598f, 0.304488f, 0.301409f, 0.298361f, 0.295344f, 0.292358f, 0.289401f, 0.286475f, 0.283578f, 0.280711f, 0.277872f, 0.275062f, 0.272281f, 0.269528f, 0.266802f, 0.264104f, 0.261434f, 0.258790f, 0.256173f, 0.253583f, 0.251018f, 0.248480f, 0.245967f, 0.243480f, 0.241018f, 0.238581f, 0.236169f, 0.233780f, 0.231416f, 0.229076f, 0.226760f, 0.224467f, 0.222197f, 0.219950f, 0.217726f, 0.215524f, 0.213345f, 0.211188f, 0.209052f, 0.206938f, 0.204846f, 0.202774f, 0.200724f, 0.198694f, 0.196685f, 0.194696f, 0.192727f, 0.190779f, 0.188849f, 0.186940f, 0.185049f, 0.183178f, 0.181326f, 0.179492f, 0.177677f, 0.175881f, 0.174102f, 0.172342f, 0.170599f, 0.168874f, 0.167166f, 0.165476f, 0.163803f, 0.162146f, 0.160507f, 0.158883f, 0.157277f, 0.155686f, 0.154112f, 0.152554f, 0.151011f, 0.149484f, 0.147973f, 0.146476f, 0.144995f, 0.143529f, 0.142078f, 0.140641f, 0.139219f, 0.137811f, 0.136417f, 0.135038f, 0.133672f, 0.132321f, 0.130983f, 0.129658f, 0.128347f, 0.127049f, 0.125765f, 0.124493f, 0.123234f, 0.121988f, 0.120754f, 0.119533f, 0.118325f, 0.117128f, 0.115944f, 0.114771f, 0.113611f, 0.112462f, 0.111325f, 0.110199f, 0.109085f, 0.107982f, 0.106890f, 0.105809f, 0.104739f, 0.103680f, 0.102631f, 0.101593f, 0.100566f, 0.099549f, 0.098543f, 0.097546f, 0.096560f, 0.095583f, 0.094617f, 0.093660f, 0.092713f, 0.091775f, 0.090847f, 0.089929f, 0.089019f, 0.088119f, 0.087228f, 0.086346f, 0.085473f, 0.084609f, 0.083753f, 0.082906f, 0.082068f, 0.081238f, 0.080417f, 0.079603f, 0.078798f, 0.078002f, 0.077213f, 0.076432f, 0.075659f, 0.074894f, 0.074137f, 0.073387f, 0.072645f, 0.071910f, 0.071183f, 0.070464f, 0.069751f, 0.069046f, 0.068347f, 0.067656f, 0.066972f, 0.066295f, 0.065625f, 0.064961f, 0.064304f, 0.063654f, 0.063010f, 0.062373f, 0.061742f, 0.061118f, 0.060500f, 0.059888f, 0.059283f, 0.058683f, 0.058090f, 0.057502f, 0.056921f, 0.056345f, 0.055776f, 0.055212f, 0.054653f, 0.054101f, 0.053554f, 0.053012f, 0.052476f, 0.051945f, 0.051420f, 0.050900f, 0.050385f, 0.049876f, 0.049372f, 0.048872f, 0.048378f, 0.047889f, 0.047405f, 0.046925f, 0.046451f, 0.045981f, 0.045516f, 0.045056f, 0.044600f, 0.044149f, 0.043703f, 0.043261f, 0.042823f, 0.042390f, 0.041962f, 0.041537f, 0.041117f, 0.040702f, 0.040290f, 0.039883f, 0.039479f, 0.039080f, 0.038685f, 0.038294f, 0.037907f, 0.037523f, 0.037144f, 0.036768f, 0.036396f, 0.036028f, 0.035664f, 0.035303f, 0.034946f, 0.034593f, 0.034243f, 0.033897f, 0.033554f, 0.033215f, 0.032879f, 0.032547f, 0.032217f, 0.031892f, 0.031569f, 0.031250f, 0.030934f, 0.030621f, 0.030312f, 0.030005f, 0.029702f, 0.029401f, 0.029104f, 0.028810f, 0.028518f, 0.028230f, 0.027945f, 0.027662f, 0.027382f, 0.027105f, 0.026831f, 0.026560f, 0.026291f, 0.026026f, 0.025762f, 0.025502f, 0.025244f, 0.024989f, 0.024736f, 0.024486f, 0.024238f, 0.023993f, 0.023751f, 0.023510f, 0.023273f, 0.023037f, 0.022804f, 0.022574f, 0.022346f, 0.022120f, 0.021896f, 0.021674f, 0.021455f, 0.021238f, 0.021024f, 0.020811f, 0.020601f, 0.020392f, 0.020186f, 0.019982f, 0.019780f, 0.019580f, 0.019382f, 0.019186f, 0.018992f, 0.018800f, 0.018610f, 0.018422f, 0.018235f, 0.018051f, 0.017868f, 0.017688f, 0.017509f, 0.017332f, 0.017156f, 0.016983f, 0.016811f, 0.016641f, 0.016473f, 0.016306f, 0.016142f, 0.015978f, 0.015817f, 0.015657f, 0.015498f, 0.015342f, 0.015187f, 0.015033f, 0.014881f, 0.014731f, 0.014582f, 0.014434f, 0.014288f, 0.014144f, 0.014001f, 0.013859f, 0.013719f, 0.013580f, 0.013443f, 0.013307f, 0.013172f, 0.013039f, 0.012907f, 0.012777f, 0.012648f, 0.012520f, 0.012393f, 0.012268f, 0.012144f, 0.012021f, 0.011899f, 0.011779f, 0.011660f, 0.011542f, 0.011425f, 0.011310f, 0.011195f, 0.011082f, 0.010970f, 0.010859f, 0.010749f, 0.010641f, 0.010533f, 0.010427f, 0.010321f, 0.010217f, 0.010114f, 0.010011f, 0.009910f, 0.009810f, 0.009711f, 0.009612f, 0.009515f, 0.009419f, 0.009324f, 0.009230f, 0.009136f, 0.009044f, 0.008952f, 0.008862f, 0.008772f, 0.008684f, 0.008596f, 0.008509f, 0.008423f, 0.008338f, 0.008253f, 0.008170f, 0.008087f, 0.008005f, 0.007924f, 0.007844f, 0.007765f, 0.007686f, 0.007609f, 0.007532f, 0.007456f, 0.007380f, 0.007306f, 0.007232f, 0.007159f, 0.007086f, 0.007015f, 0.006944f, 0.006873f, 0.006804f, 0.006735f, 0.006667f, 0.006600f, 0.006533f, 0.006467f, 0.006401f, 0.006337f, 0.006273f, 0.006209f, 0.006146f, 0.006084f, 0.006023f, 0.005962f, 0.005902f, 0.005842f, 0.005783f, 0.005724f, 0.005666f, 0.005609f, 0.005552f, 0.005496f, 0.005441f, 0.005386f, 0.005331f, 0.005277f, 0.005224f, 0.005171f, 0.005119f, 0.005067f, 0.005016f, 0.004965f, 0.004915f, 0.004865f, 0.004816f, 0.004767f, 0.004719f, 0.004671f, 0.004624f, 0.004577f, 0.004531f, 0.004485f, 0.004440f, 0.004395f, 0.004351f, 0.004307f, 0.004263f, 0.004220f, 0.004177f, 0.004135f, 0.004093f, 0.004052f, 0.004011f, 0.003970f, 0.003930f, 0.003890f, 0.003851f, 0.003812f, 0.003774f, 0.003735f, 0.003698f, 0.003660f, 0.003623f, 0.003587f, 0.003550f, 0.003514f, 0.003479f, 0.003444f, 0.003409f, 0.003374f, 0.003340f, 0.003307f, 0.003273f, 0.003240f, 0.003207f, 0.003175f, 0.003143f, 0.003111f, 0.003079f, 0.003048f, 0.003017f, 0.002987f, 0.002957f, 0.002927f, 0.002897f, 0.002868f, 0.002839f, 0.002810f, 0.002782f, 0.002754f, 0.002726f, 0.002698f, 0.002671f, 0.002644f, 0.002617f, 0.002591f, 0.002565f, 0.002539f, 0.002513f, 0.002488f, 0.002462f, 0.002438f, 0.002413f, 0.002389f, 0.002364f, 0.002340f, 0.002317f, 0.002293f, 0.002270f, 0.002247f, 0.002224f, 0.002202f, 0.002180f, 0.002158f, 0.002136f, 0.002114f, 0.002093f, 0.002072f, 0.002051f, 0.002030f, 0.002010f, 0.001989f, 0.001969f, 0.001949f, 0.001929f, 0.001910f, 0.001891f, 0.001872f, 0.001853f, 0.001834f, 0.001815f, 0.001797f, 0.001779f, 0.001761f, 0.001743f, 0.001725f, 0.001708f, 0.001691f, 0.001674f, 0.001657f, 0.001640f, 0.001623f, 0.001607f, 0.001591f, 0.001575f, 0.001559f, 0.001543f, 0.001527f, 0.001512f, 0.001497f, 0.001481f, 0.001466f, 0.001452f, 0.001437f, 0.001422f, 0.001408f, 0.001394f, 0.001380f, 0.001366f, 0.001352f, 0.001338f, 0.001325f, 0.001311f, 0.001298f, 0.001285f, 0.001272f, 0.001259f, 0.001246f, 0.001234f, 0.001221f, 0.001209f, 0.001197f, 0.001185f, 0.001173f, 0.001161f, 0.001149f, 0.001137f, 0.001126f, 0.001115f, 0.001103f, 0.001092f, 0.001081f, 0.001070f, 0.001059f, 0.001049f, 0.001038f, 0.001027f, 0.001017f, 0.001007f, 0.000997f, 0.000987f, 0.000977f, 0.000967f, 0.000957f, 0.000947f, 0.000938f, 0.000928f, 0.000919f, 0.000909f, 0.000900f, 0.000891f, 0.000882f, 0.000873f, 0.000864f, 0.000856f, 0.000847f, 0.000838f, 0.000830f, 0.000822f, 0.000813f, 0.000805f, 0.000797f, 0.000789f, 0.000781f, 0.000773f, 0.000765f, 0.000757f, 0.000750f, 0.000742f, 0.000735f, 0.000727f, 0.000720f, 0.000713f, 0.000705f, 0.000698f, 0.000691f, 0.000684f, 0.000677f, 0.000670f, 0.000664f, 0.000657f, 0.000650f, 0.000644f, 0.000637f, 0.000631f, 0.000624f, 0.000618f, 0.000612f, 0.000606f, 0.000600f, 0.000593f, 0.000587f, 0.000582f, 0.000576f, 0.000570f, 0.000564f, 0.000558f, 0.000553f, 0.000547f, 0.000542f, 0.000536f, 0.000531f, 0.000525f, 0.000520f, 0.000515f, 0.000510f, 0.000504f, 0.000499f, 0.000494f, 0.000489f, 0.000484f, 0.000479f, 0.000475f, 0.000470f, 0.000465f, 0.000460f, 0.000456f, 0.000451f, 0.000447f, 0.000442f, 0.000438f, 0.000433f, 0.000429f, 0.000424f, 0.000420f, 0.000416f, 0.000412f, 0.000407f, 0.000403f, 0.000399f, 0.000395f, 0.000391f, 0.000387f, 0.000383f, 0.000379f, 0.000376f, 0.000372f, 0.000368f, 0.000364f, 0.000361f, 0.000357f, 0.000353f, 0.000350f, 0.000346f, 0.000343f, 0.000339f, 0.000336f, 0.000333f, 0.000329f, 0.000326f, 0.000323f, 0.000319f, 0.000316f, 0.000313f, 0.000310f, 0.000307f, 0.000303f, 0.000300f, 0.000297f, 0.000294f, 0.000291f, 0.000288f, 0.000286f, 0.000283f, 0.000280f, 0.000277f, 0.000274f, 0.000271f, 0.000269f, 0.000266f, 0.000263f, 0.000261f, 0.000258f, 0.000255f, 0.000253f, 0.000250f, 0.000248f, 0.000245f, 0.000243f, 0.000240f, 0.000238f, 0.000235f, 0.000233f, 0.000231f, 0.000228f, 0.000226f, 0.000224f, 0.000221f, 0.000219f, 0.000217f, 0.000215f, 0.000213f, 0.000210f, 0.000208f, 0.000206f, 0.000204f, 0.000202f, 0.000200f, 0.000198f, 0.000196f, 0.000194f, 0.000192f, 0.000190f, 0.000188f, 0.000186f, 0.000184f, 0.000183f, 0.000181f, 0.000179f, 0.000177f, 0.000175f, 0.000174f, 0.000172f, 0.000170f, 0.000168f, 0.000167f, 0.000165f, 0.000163f, 0.000162f, 0.000160f, 0.000158f, 0.000157f, 0.000155f, 0.000154f, 0.000152f, 0.000151f, 0.000149f, 0.000147f, 0.000146f, 0.000145f, 0.000143f, 0.000142f, 0.000140f, 0.000139f, 0.000137f, 0.000136f, 0.000135f, 0.000133f, 0.000132f, 0.000131f, 0.000129f, 0.000128f, 0.000127f, 0.000125f, 0.000124f, 0.000123f, 0.000122f, 0.000120f, 0.000119f, 0.000118f, 0.000117f, 0.000116f, 0.000114f, 0.000113f, 0.000112f, 0.000111f, 0.000110f, 0.000109f, 0.000108f, 0.000107f, 0.000105f, 0.000104f, 0.000103f, 0.000102f, 0.000101f, 0.000100f, 0.000099f, 0.000098f, 0.000097f, 0.000096f, 0.000095f, 0.000094f, 0.000093f, 0.000092f, 0.000091f, 0.000091f, 0.000090f, 0.000089f, 0.000088f, 0.000087f, 0.000086f, 0.000085f, 0.000084f, 0.000083f, 0.000083f, 0.000082f, 0.000081f, 0.000080f, 0.000079f, 0.000079f, 0.000078f, 0.000077f, 0.000076f, 0.000075f, 0.000075f, 0.000074f, 0.000073f, 0.000072f, 0.000072f, 0.000071f, 0.000070f, 0.000070f, 0.000069f, 0.000068f, 0.000067f, 0.000067f, 0.000066f, 0.000065f, 0.000065f, 0.000064f, 0.000063f, 0.000063f, 0.000062f, 0.000062f, 0.000061f, 0.000060f, 0.000060f, 0.000059f, 0.000058f, 0.000058f, 0.000057f, 0.000057f, 0.000056f, 0.000056f, 0.000055f, 0.000054f, 0.000054f, 0.000053f, 0.000053f, 0.000052f, 0.000052f, 0.000051f, 0.000051f, 0.000050f, 0.000050f, 0.000049f, 0.000049f, 0.000048f, 0.000048f, 0.000047f, 0.000047f, 0.000046f, 0.000046f, 0.000045f, 0.000045f, 0.000044f, 0.000044f, 0.000044f, 0.000043f, 0.000043f, 0.000042f, 0.000042f, 0.000041f, 0.000041f, 0.000041f, 0.000040f, 0.000040f, 0.000039f, 0.000039f, 0.000039f, 0.000038f, 0.000038f, 0.000037f, 0.000037f, 0.000037f, 0.000036f, 0.000036f, 0.000036f, 0.000035f, 0.000035f, 0.000034f, 0.000034f, 0.000034f, 0.000033f, 0.000033f, 0.000033f, 0.000032f, 0.000032f, 0.000032f, 2.0f, 2.0f, 2.0f, 2.0f};

// 0.000032f, 0.000032f, 0.000032f, 0.000032f};
// , 2.0f, 2.0f, 2.0f, 2.0f};

const float oct4log[1024]={1.000000f, 0.997293f, 0.994594f, 0.991902f, 0.989218f, 0.986540f, 0.983870f, 0.981207f, 0.978551f, 0.975903f, 0.973261f, 0.970627f, 0.968000f, 0.965380f, 0.962767f, 0.960161f, 0.957563f, 0.954971f, 0.952386f, 0.949809f, 0.947238f, 0.944674f, 0.942117f, 0.939567f, 0.937024f, 0.934488f, 0.931959f, 0.929436f, 0.926921f, 0.924412f, 0.921910f, 0.919415f, 0.916926f, 0.914445f, 0.911970f, 0.909501f, 0.907040f, 0.904585f, 0.902136f, 0.899695f, 0.897260f, 0.894831f, 0.892409f, 0.889994f, 0.887585f, 0.885183f, 0.882787f, 0.880397f, 0.878015f, 0.875638f, 0.873268f, 0.870905f, 0.868547f, 0.866197f, 0.863852f, 0.861514f, 0.859182f, 0.856857f, 0.854538f, 0.852225f, 0.849918f, 0.847618f, 0.845324f, 0.843036f, 0.840754f, 0.838478f, 0.836209f, 0.833946f, 0.831689f, 0.829438f, 0.827193f, 0.824954f, 0.822721f, 0.820494f, 0.818273f, 0.816059f, 0.813850f, 0.811647f, 0.809450f, 0.807260f, 0.805075f, 0.802896f, 0.800723f, 0.798555f, 0.796394f, 0.794238f, 0.792089f, 0.789945f, 0.787807f, 0.785675f, 0.783548f, 0.781427f, 0.779312f, 0.777203f, 0.775100f, 0.773002f, 0.770910f, 0.768823f, 0.766742f, 0.764667f, 0.762597f, 0.760533f, 0.758475f, 0.756422f, 0.754375f, 0.752333f, 0.750297f, 0.748266f, 0.746241f, 0.744221f, 0.742206f, 0.740198f, 0.738194f, 0.736196f, 0.734204f, 0.732216f, 0.730235f, 0.728258f, 0.726287f, 0.724321f, 0.722361f, 0.720406f, 0.718456f, 0.716511f, 0.714572f, 0.712638f, 0.710709f, 0.708786f, 0.706867f, 0.704954f, 0.703046f, 0.701143f, 0.699245f, 0.697353f, 0.695465f, 0.693583f, 0.691706f, 0.689834f, 0.687967f, 0.686105f, 0.684248f, 0.682396f, 0.680549f, 0.678707f, 0.676870f, 0.675038f, 0.673211f, 0.671389f, 0.669571f, 0.667759f, 0.665952f, 0.664149f, 0.662352f, 0.660559f, 0.658771f, 0.656988f, 0.655210f, 0.653437f, 0.651668f, 0.649904f, 0.648145f, 0.646391f, 0.644641f, 0.642897f, 0.641157f, 0.639421f, 0.637691f, 0.635965f, 0.634243f, 0.632527f, 0.630815f, 0.629107f, 0.627405f, 0.625707f, 0.624013f, 0.622324f, 0.620640f, 0.618960f, 0.617285f, 0.615614f, 0.613948f, 0.612286f, 0.610629f, 0.608976f, 0.607328f, 0.605684f, 0.604045f, 0.602410f, 0.600779f, 0.599153f, 0.597532f, 0.595914f, 0.594301f, 0.592693f, 0.591089f, 0.589489f, 0.587893f, 0.586302f, 0.584715f, 0.583133f, 0.581555f, 0.579980f, 0.578411f, 0.576845f, 0.575284f, 0.573727f, 0.572174f, 0.570625f, 0.569081f, 0.567541f, 0.566005f, 0.564473f, 0.562945f, 0.561421f, 0.559902f, 0.558386f, 0.556875f, 0.555368f, 0.553865f, 0.552365f, 0.550870f, 0.549379f, 0.547893f, 0.546410f, 0.544931f, 0.543456f, 0.541985f, 0.540518f, 0.539055f, 0.537596f, 0.536141f, 0.534690f, 0.533243f, 0.531799f, 0.530360f, 0.528925f, 0.527493f, 0.526065f, 0.524641f, 0.523221f, 0.521805f, 0.520393f, 0.518985f, 0.517580f, 0.516179f, 0.514782f, 0.513389f, 0.511999f, 0.510613f, 0.509231f, 0.507853f, 0.506478f, 0.505108f, 0.503741f, 0.502377f, 0.501017f, 0.499661f, 0.498309f, 0.496960f, 0.495615f, 0.494274f, 0.492936f, 0.491602f, 0.490271f, 0.488944f, 0.487621f, 0.486301f, 0.484985f, 0.483672f, 0.482363f, 0.481058f, 0.479756f, 0.478457f, 0.477162f, 0.475871f, 0.474583f, 0.473298f, 0.472017f, 0.470740f, 0.469465f, 0.468195f, 0.466928f, 0.465664f, 0.464403f, 0.463147f, 0.461893f, 0.460643f, 0.459396f, 0.458153f, 0.456913f, 0.455676f, 0.454443f, 0.453213f, 0.451986f, 0.450763f, 0.449543f, 0.448326f, 0.447112f, 0.445902f, 0.444695f, 0.443492f, 0.442291f, 0.441094f, 0.439901f, 0.438710f, 0.437523f, 0.436338f, 0.435157f, 0.433980f, 0.432805f, 0.431634f, 0.430465f, 0.429300f, 0.428138f, 0.426979f, 0.425824f, 0.424671f, 0.423522f, 0.422376f, 0.421232f, 0.420092f, 0.418955f, 0.417821f, 0.416690f, 0.415563f, 0.414438f, 0.413316f, 0.412197f, 0.411082f, 0.409969f, 0.408860f, 0.407753f, 0.406649f, 0.405549f, 0.404451f, 0.403356f, 0.402265f, 0.401176f, 0.400090f, 0.399007f, 0.397927f, 0.396850f, 0.395776f, 0.394705f, 0.393637f, 0.392571f, 0.391509f, 0.390449f, 0.389392f, 0.388338f, 0.387287f, 0.386239f, 0.385194f, 0.384151f, 0.383111f, 0.382074f, 0.381040f, 0.380009f, 0.378980f, 0.377955f, 0.376932f, 0.375912f, 0.374894f, 0.373879f, 0.372868f, 0.371858f, 0.370852f, 0.369848f, 0.368847f, 0.367849f, 0.366853f, 0.365860f, 0.364870f, 0.363882f, 0.362898f, 0.361915f, 0.360936f, 0.359959f, 0.358985f, 0.358013f, 0.357044f, 0.356078f, 0.355114f, 0.354153f, 0.353194f, 0.352238f, 0.351285f, 0.350334f, 0.349386f, 0.348440f, 0.347497f, 0.346557f, 0.345619f, 0.344683f, 0.343750f, 0.342820f, 0.341892f, 0.340967f, 0.340044f, 0.339124f, 0.338206f, 0.337290f, 0.336377f, 0.335467f, 0.334559f, 0.333653f, 0.332750f, 0.331850f, 0.330952f, 0.330056f, 0.329163f, 0.328272f, 0.327383f, 0.326497f, 0.325613f, 0.324732f, 0.323853f, 0.322977f, 0.322102f, 0.321231f, 0.320361f, 0.319494f, 0.318629f, 0.317767f, 0.316907f, 0.316049f, 0.315194f, 0.314341f, 0.313490f, 0.312641f, 0.311795f, 0.310951f, 0.310110f, 0.309270f, 0.308433f, 0.307598f, 0.306766f, 0.305936f, 0.305108f, 0.304282f, 0.303458f, 0.302637f, 0.301818f, 0.301001f, 0.300186f, 0.299374f, 0.298563f, 0.297755f, 0.296949f, 0.296146f, 0.295344f, 0.294545f, 0.293748f, 0.292953f, 0.292160f, 0.291369f, 0.290580f, 0.289794f, 0.289009f, 0.288227f, 0.287447f, 0.286669f, 0.285893f, 0.285119f, 0.284348f, 0.283578f, 0.282811f, 0.282045f, 0.281282f, 0.280520f, 0.279761f, 0.279004f, 0.278249f, 0.277496f, 0.276745f, 0.275996f, 0.275249f, 0.274504f, 0.273761f, 0.273020f, 0.272281f, 0.271544f, 0.270809f, 0.270076f, 0.269345f, 0.268616f, 0.267889f, 0.267164f, 0.266441f, 0.265720f, 0.265000f, 0.264283f, 0.263568f, 0.262854f, 0.262143f, 0.261434f, 0.260726f, 0.260020f, 0.259317f, 0.258615f, 0.257915f, 0.257217f, 0.256520f, 0.255826f, 0.255134f, 0.254443f, 0.253755f, 0.253068f, 0.252383f, 0.251700f, 0.251018f, 0.250339f, 0.249661f, 0.248986f, 0.248312f, 0.247640f, 0.246969f, 0.246301f, 0.245634f, 0.244970f, 0.244307f, 0.243645f, 0.242986f, 0.242328f, 0.241672f, 0.241018f, 0.240366f, 0.239715f, 0.239066f, 0.238419f, 0.237774f, 0.237131f, 0.236489f, 0.235849f, 0.235210f, 0.234574f, 0.233939f, 0.233306f, 0.232674f, 0.232044f, 0.231416f, 0.230790f, 0.230165f, 0.229542f, 0.228921f, 0.228302f, 0.227684f, 0.227067f, 0.226453f, 0.225840f, 0.225229f, 0.224619f, 0.224011f, 0.223405f, 0.222800f, 0.222197f, 0.221596f, 0.220996f, 0.220398f, 0.219801f, 0.219206f, 0.218613f, 0.218021f, 0.217431f, 0.216843f, 0.216256f, 0.215671f, 0.215087f, 0.214505f, 0.213924f, 0.213345f, 0.212768f, 0.212192f, 0.211617f, 0.211045f, 0.210474f, 0.209904f, 0.209336f, 0.208769f, 0.208204f, 0.207641f, 0.207079f, 0.206518f, 0.205959f, 0.205402f, 0.204846f, 0.204291f, 0.203738f, 0.203187f, 0.202637f, 0.202089f, 0.201542f, 0.200996f, 0.200452f, 0.199910f, 0.199368f, 0.198829f, 0.198291f, 0.197754f, 0.197219f, 0.196685f, 0.196153f, 0.195622f, 0.195092f, 0.194564f, 0.194038f, 0.193512f, 0.192989f, 0.192466f, 0.191945f, 0.191426f, 0.190908f, 0.190391f, 0.189876f, 0.189362f, 0.188849f, 0.188338f, 0.187828f, 0.187320f, 0.186813f, 0.186307f, 0.185803f, 0.185300f, 0.184799f, 0.184299f, 0.183800f, 0.183302f, 0.182806f, 0.182311f, 0.181818f, 0.181326f, 0.180835f, 0.180346f, 0.179858f, 0.179371f, 0.178885f, 0.178401f, 0.177918f, 0.177437f, 0.176956f, 0.176478f, 0.176000f, 0.175523f, 0.175048f, 0.174575f, 0.174102f, 0.173631f, 0.173161f, 0.172692f, 0.172225f, 0.171759f, 0.171294f, 0.170830f, 0.170368f, 0.169907f, 0.169447f, 0.168988f, 0.168531f, 0.168075f, 0.167620f, 0.167166f, 0.166714f, 0.166262f, 0.165812f, 0.165364f, 0.164916f, 0.164470f, 0.164025f, 0.163581f, 0.163138f, 0.162696f, 0.162256f, 0.161817f, 0.161379f, 0.160942f, 0.160507f, 0.160072f, 0.159639f, 0.159207f, 0.158776f, 0.158346f, 0.157918f, 0.157490f, 0.157064f, 0.156639f, 0.156215f, 0.155792f, 0.155370f, 0.154950f, 0.154530f, 0.154112f, 0.153695f, 0.153279f, 0.152864f, 0.152450f, 0.152038f, 0.151626f, 0.151216f, 0.150807f, 0.150399f, 0.149991f, 0.149585f, 0.149181f, 0.148777f, 0.148374f, 0.147973f, 0.147572f, 0.147173f, 0.146774f, 0.146377f, 0.145981f, 0.145586f, 0.145192f, 0.144799f, 0.144407f, 0.144016f, 0.143626f, 0.143237f, 0.142850f, 0.142463f, 0.142078f, 0.141693f, 0.141310f, 0.140927f, 0.140546f, 0.140165f, 0.139786f, 0.139408f, 0.139030f, 0.138654f, 0.138279f, 0.137904f, 0.137531f, 0.137159f, 0.136788f, 0.136417f, 0.136048f, 0.135680f, 0.135313f, 0.134946f, 0.134581f, 0.134217f, 0.133854f, 0.133491f, 0.133130f, 0.132770f, 0.132410f, 0.132052f, 0.131695f, 0.131338f, 0.130983f, 0.130628f, 0.130275f, 0.129922f, 0.129570f, 0.129220f, 0.128870f, 0.128521f, 0.128173f, 0.127826f, 0.127480f, 0.127135f, 0.126791f, 0.126448f, 0.126106f, 0.125765f, 0.125424f, 0.125085f, 0.124746f, 0.124409f, 0.124072f, 0.123736f, 0.123401f, 0.123067f, 0.122734f, 0.122402f, 0.122071f, 0.121740f, 0.121411f, 0.121082f, 0.120754f, 0.120427f, 0.120102f, 0.119776f, 0.119452f, 0.119129f, 0.118807f, 0.118485f, 0.118164f, 0.117844f, 0.117526f, 0.117207f, 0.116890f, 0.116574f, 0.116258f, 0.115944f, 0.115630f, 0.115317f, 0.115005f, 0.114693f, 0.114383f, 0.114073f, 0.113765f, 0.113457f, 0.113150f, 0.112843f, 0.112538f, 0.112233f, 0.111930f, 0.111627f, 0.111325f, 0.111023f, 0.110723f, 0.110423f, 0.110124f, 0.109826f, 0.109529f, 0.109233f, 0.108937f, 0.108642f, 0.108348f, 0.108055f, 0.107762f, 0.107471f, 0.107180f, 0.106890f, 0.106600f, 0.106312f, 0.106024f, 0.105737f, 0.105451f, 0.105165f, 0.104881f, 0.104597f, 0.104314f, 0.104032f, 0.103750f, 0.103469f, 0.103189f, 0.102910f, 0.102631f, 0.102354f, 0.102076f, 0.101800f, 0.101525f, 0.101250f, 0.100976f, 0.100703f, 0.100430f, 0.100158f, 0.099887f, 0.099617f, 0.099347f, 0.099078f, 0.098810f, 0.098543f, 0.098276f, 0.098010f, 0.097745f, 0.097480f, 0.097216f, 0.096953f, 0.096691f, 0.096429f, 0.096168f, 0.095908f, 0.095648f, 0.095389f, 0.095131f, 0.094874f, 0.094617f, 0.094361f, 0.094105f, 0.093851f, 0.093597f, 0.093343f, 0.093091f, 0.092839f, 0.092587f, 0.092337f, 0.092087f, 0.091838f, 0.091589f, 0.091341f, 0.091094f, 0.090847f, 0.090602f, 0.090356f, 0.090112f, 0.089868f, 0.089625f, 0.089382f, 0.089140f, 0.088899f, 0.088658f, 0.088418f, 0.088179f, 0.087940f, 0.087702f, 0.087465f, 0.087228f, 0.086992f, 0.086757f, 0.086522f, 0.086288f, 0.086054f, 0.085821f, 0.085589f, 0.085357f, 0.085126f, 0.084896f, 0.084666f, 0.084437f, 0.084208f, 0.083980f, 0.083753f, 0.083526f, 0.083300f, 0.083075f, 0.082850f, 0.082626f, 0.082402f, 0.082179f, 0.081957f, 0.081735f, 0.081514f, 0.081293f, 0.081073f, 0.080854f, 0.080635f, 0.080417f, 0.080199f, 0.079982f, 0.079765f, 0.079549f, 0.079334f, 0.079119f, 0.078905f, 0.078692f, 0.078479f, 0.078266f, 0.078054f, 0.077843f, 0.077633f, 0.077422f, 0.077213f, 0.077004f, 0.076795f, 0.076588f, 0.076380f, 0.076174f, 0.075967f, 0.075762f, 0.075557f, 0.075352f, 0.075148f, 0.074945f, 0.074742f, 0.074540f, 0.074338f, 0.074137f, 0.073936f, 0.073736f, 0.073536f, 0.073337f, 0.073139f, 0.072941f, 0.072744f, 0.072547f, 0.072350f, 0.072155f, 0.071959f, 0.071764f, 0.071570f, 0.071377f, 0.071183f, 0.070991f, 0.070799f, 0.070607f, 0.070416f, 0.070225f, 0.070035f, 0.069846f, 0.069657f, 0.069468f, 0.069280f, 0.069092f, 0.068905f, 0.068719f, 0.068533f, 0.068347f, 0.068163f, 0.067978f, 0.067794f, 0.067611f, 0.067428f, 0.067245f, 0.067063f, 0.066882f, 0.066701f, 0.066520f, 0.066340f, 0.066160f, 0.065981f, 0.065803f, 0.065625f, 0.065447f, 0.065270f, 0.065093f, 0.064917f, 0.064741f, 0.064566f, 0.064391f, 0.064217f, 0.064043f, 0.063870f, 0.063697f, 0.063525f, 0.063353f, 0.063181f, 0.063010f, 0.062840f, 0.062670f, 0.062500f};


// but all abstractbitstreams use depth: so can pass in others not just cv... how to abstract this eg. so we can use dacfrom...
uint32_t (*bitfroms[32])(uint8_t wh)={Gbinroute}; // add in funcs which use also binroutetypecount

//uint32_t (*speedfroms[32])(uint8_t wh)={sadcfracint, sadcfrac, sdacfrac, sdacfracint, sstrobe, sstrobeint, sbinroute, sprob, sprobdac, sclksr}; // sycycle also... // expand for dacs etc...

    //    bitn=ADC_(w,SRlength[w], whichadc[adctypecnt][w],bitn,dacfrom[daccount][w],param[w], &gate[w].shift_); // as adc functions or as bitfuncs????

// now for length
static inline uint32_t lcvl(uint8_t wh){ 
  uint32_t bt=lookuplenall[CVL[wh]>>7]; // 5 bits
  return bt;
}



/*
// for manual binroute
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
*/



uint32_t neworder[4]={3,2,1,0}; // order backwards

uint32_t neworders[24][4]={
  {0,1,2,3},
  {0,1,3,2},
  {0,2,1,3},
  {0,2,3,1},
  {0,3,1,2},
  {0,3,2,1},
  {1,2,3,0},
  {1,2,0,3},
  {1,3,2,0},
  {1,3,0,2},
  {1,0,2,3},
  {1,0,3,2},
  {2,3,0,1},
  {2,3,1,0},
  {2,0,1,3},
  {2,0,3,1},
  {2,1,3,0},
  {2,1,0,3},
  {3,0,1,2},
  {3,0,2,1},
  {3,1,2,0},
  {3,1,0,2},
  {3,2,1,0},
  {3,2,0,1}  
};


static inline uint32_t adc4bits_unshare(uint32_t depth, uint8_t wh){ // use wh too so matches other gens
  uint32_t bt, k;
  static uint32_t fast=0, khh;
  static int32_t bc[4]={0,0,0,0};
  static uint32_t kh[4]={0,0,0,0};

  // run at fastest - but all of them are running this! 
  if (fast>3){  
  ADCgeneric;
  khh=k>>8;
  fast=0;
  }
  fast++;
  
  if (bc[wh]<0) {
    kh[wh]=khh;
    bc[wh]=3; 
  }
  bt = (kh[wh]>>bc[wh])&0x01; // this means that MSB comes out first
  bc[wh]--;
  return bt;
}


// was speed.h

void Ndacoffset0(void){
  uint8_t w=0;
  float speedf__;
  float mmm=(float)(1024-(CVL[0]>>2))/1024.0f;
  HEADSINN;
  tmp=(1024-(CV[0]>>2)) + (int)((float)(gate[dacfrom[daccount][0]].dac>>2)*mmm);
  if (tmp>1023) tmp=1023;
  speedf__=logspeed[tmp]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}


void Rdacadditself0(void){ // tested//trial itself as DAC - can also be other variants TODO
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[3].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacghostitself0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+((gate[3].Gshift_[routeto[count][3]])&511)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacghostincoming0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+((gate[3].Gshift_[inroute[count][3]])&511)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacseladd0(void){
  HEADR;
  uint8_t w=3;
  float speedf__;
  uint8_t whic=(CV[3]>>9)&3; //12 bits -> 2 bits
  speedf__=logspeed[(CV[3]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacadd0(void){
  HEADR;
  uint8_t w=3;
  float speedf__;
  speedf__=logspeed[(CV[3]&511)+(gate[dacfrom[daccount][3]].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacminus0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[daccount][3]].dac>>2)-(1024-(CV[3]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacspeedminus0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)-(gate[dacfrom[daccount][3]].dac>>2); 
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Rdacmod0(void){
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=((CV[3]>>2)+1); // modulo code
  speedf__=logspeed[(gate[dacfrom[daccount][3]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void RB0(void){// with oscillator
  HEADR;
  uint8_t w=3;
  int32_t cv;
  float speedf__;
  cv=(CV[3]>>2)-(gate[dacfrom[daccount][3]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],30,gate[w].trigger,dacfrom[daccount][1],gate[w].adcpar, &gate[w].shift_); // oscillator
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// sources: adc, dac, oscillator, clock?-return last strobe, impulses(TODO) - // add in different DACs, SR bits output
// but some of these are single bits so doesn't make sense

uint32_t fadc(void){
  uint32_t k;
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_3Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  k=ADC_GetConversionValue(ADC1);
  return k;
}

uint32_t fdac(void){
  uint32_t k;
  k=gate[3].dac;
  return k;
}

uint32_t (*fff[8])(void)={fadc, fdac};

// how we can start to abstract source out - but few sources...
static inline uint32_t bits(uint32_t depth, uint8_t func){ // max 12 bits // func is index into function array
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (depth>11) depth=11; // max depth
    if (bc<0) {
      k=(*fff[func])(); // new 12 bits but only in case of adc/dac
      k=k>>(11-depth);
	bc=depth; // was 11
  }
    bt = (k>>bc)&0x01; // this means that MSB comes out first
    bc--;
    return bt;
}


/* // why we lost this?
// Nint70 - if we can change type of gate[3].dac in dac mixes 66,67,68 or pure dac ins (?)
void Nint70(void){
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    gate[3].dactype=15-(CV[0]>>8);     // 4 bits for type
    bitn=ADC_(0,SRlength[w],67,gate[w].trigger,3,gate[3].dac, &gate[w].shift_);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
*/

/*
void NLintprob084(void){ // own dac as comparator against DAC+CV 
  // can also detach length and have this as prob mode too - prob of cycle or ADC. prob of cycle or routein
  uint8_t w=0;				       
  HEADSINN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) > CVL[0])){   // thsi way round
    bitn=ADC_(0,SRlength[w],84,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);
    }
    else JUSTCYCLE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
*/


// try N0-N7 with ADCORIN() - these all fade out


  void Nor0(void){ 
  ADCORIN(0);
  }

  void Nor1(void){ 
  ADCORIN(1);
  }

  void Nor2(void){ 
  ADCORIN(2);
  }

  void Nor3(void){ 
  ADCORIN(3);
  }

  void Nor4(void){
  ADCORIN(4);
  }

  void Nor5(void){ 
  ADCORIN(5);
  }

  void Nor6(void){
  ADCORIN(6);
  }

  void Nor7(void){
  ADCORIN(7);
  }




void Ntestorxor1_0(void){ // lower bits of CVL select xor or or in  -- version 2 below makes more sense
  // speed is temp>>7 so 5 bits 0-31 so we want ((CVL[w]&64)>>6) 
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time){
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  
  if ((CVL[w]&64)>>6) {
    BINROUTEOR_;
  }
  else {
    BINROUTE_;
    }
  BITN_AND_OUTVN_;
  ENDER;
  }
}
}

void Ntestorxor2_0(void){ // - or have 2 sets of 0-31 for length or/xor
  // detach length
  uint8_t w=0;
  HEADSINN; // detach
  SRlength[w]=31-((CVL[w]>>6)%32);
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time){
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  if (((CVL[w]>>6)&32)==1) {
    BINROUTEOR_;
  }
  else {
    BINROUTE_;
    }
  BITN_AND_OUTVN_;
  ENDER;
  }
}
}


//  if (speedf_[0]==2.0f) speedf_[0]=LOWEST;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[which].dac>>2)]);

//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  // if (speedf__<LOWEST) speedf__=LOWEST;
  //  speedf__=1.0f;


// how we can OR in for route 0 - below but doesn't work so well
#define BINROUTE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }



// test logic for minor major modes
// say 4 major modes

// but how we can split modes?
major=mode[3]>>4; // from 64=6bits to 2 bits 

if (w!=3){
switch(major){
 case 0:
   // we do all modes for all except 3
   switch(mode[w]{ // or this would be a bit interpretation and we have no switch
       case 0:
	 break;
     }
   break;
     }
 }//major
 }//w!=3
 else {
   // w==3 modes
   switch(mode[3]){// here we have 16 (x4-64) minor modes for the right side...
   case 0: 
     break;
   }
 }//w==3




//unused
#define BINROUTEOR {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn|=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTELOGOP {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn=logop(bitn,bitrr,logtable[w]);			\
  }							\
  tmp=tmp>>1;						\
  }							\
  }


#define BINROUTEANDCYCLE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
    if ((tmp&0x01) || (x==w)){				\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define JUSTCYCLE {				\
  bitrr = (shift_[w]>>SRlength[w]) & 0x01;		\
  bitn^=bitrr;						\
  }


// if we go with singular defroute
#define BITNNN {								\
  bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;	\
  Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;		\
  }

//if w==3 count=0 means just to reset binroute when we are out of modes which altered it
// macro for alt routes for ADC and DAC
// try with binrouteOR
#define ADCDACETC1(X, Y){			\
  bitn=0;					\
  GSHIFT;						\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTEOR;						\
  }							\
  if (w==2)      {					\
  dactype[2]=Y;					\
  BINROUTE;						\
  }							\
}

#define ADCDACNOGS(X, Y){			\
  bitn=0;					\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTE;						\
  }							\
  if (w==2)      {					\
    dactype[2]=Y;					\
    BINROUTE;						\
  }							\
}

// we still specify type of DAC here but we leave
//  if (w==2)      {
//  BINROUTE; // TODO: substitute alt routes here for DAC. eg cycle, probability etc. 4x4 for 16-31
//  }
//  else {

// still we have DACtype here
#define ADCONLY(X, Y){						\
    bitn=0;							\
    dactype[2]=Y;						\
    if (w==3) count=0;						\
    GSHIFT;							\
    if (w==0)							\
  {								\
      bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
      BINROUTEOR;						\
  }								\
}

//// older

#define GSHIFT {				\
  counter[w]=0;					\
  Gshift_[w][0]=shift_[w];			\
  Gshift_[w][1]=shift_[w];			\
  Gshift_[w][2]=shift_[w];			\
  Gshift_[w][3]=shift_[w];			\
  shift_[w]=shift_[w]<<1;			\
}

#define GS(X) {					\
  Gshift_[X][0]=shift_[X];			\
  Gshift_[X][1]=shift_[X];			\
  Gshift_[X][2]=shift_[X];			\
  Gshift_[X][3]=shift_[X];			\
}


#define BITN_AND_OUT {						\
    shift_[w]+=bitn;						\
    dac[w]=DAC_(w, SRlength[w], dactype[w],dacpar,trigger[w]);	\
    tmp=(w<<1);							\
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}

// this one is for fractional speeds/interpol
#define BITN_AND_OUTV {				\
    shift_[w]+=bitn;						\
    val=DAC_(w, shift_[w], SRlength[w], dactype[w],dacpar,trigger[w]);	\
    tmp=(w<<1);							\
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}



    /*
  case 0: // ADc x bits out but only 12/8/4/2/1 bits
    if (length<8){ // 1 bit
      if ((shift_[reg]&(1<<length))==(1<<length)) x=4095;
      else x=0;
    }
    else x=(shift_[reg]&masky[length])>>newr[length])<<news[length];
    break;
    */
    /*
  case 0: // testing 12 bits out
    if (n[reg]>length) { // slow...
      n[reg]=0;
      //      nom[reg]=shift_[reg]&4095;
      nom[reg]=((shift_[reg]&masky[length])>>newr[length])<<news[length];
    }
    n[reg]++;
    x=nom[reg];
    break;
    */


    //    x=rand()%4095;
     /*
    if (length==3){
      if (shift_[reg]&4) x=4095;
      else x=0;
    }
    else     x=( (shift_[reg] & masky[length])>>(rightshift[length]))<<leftshift[length];
    */




void testNint(void){ // no interpolation
  uint8_t w=0;				       
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void testN(void){ // speed template
  uint8_t w=0;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVN_; // for no pulse out
    ENDER;
  }
  }
}


case 80: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(adc_buffer[12])>>(11-length);
	n[reg]=length;
    }
      bt = ((k>>n[reg])&0x01) ^ strobe; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 81: // equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      k=(adc_buffer[12]); //
      k=k/divy[length];
      n[reg]=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    bt ^= strobe;
    n[reg]++;    
    break;

  case 82: // variations on one bit audio - also phasey
    k=(adc_buffer[12]); // from 0 to 4095 but where is the middle? - also we do nothing here with length
    integrator+=(k-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }
   bt ^= strobe;
   break;    

  case 83: // basic sequential length as in 0 but with padding if >11 bits **
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	k=(adc_buffer[12])>>(11-length);
	n[reg]=length;
      }
      else {
	k=(adc_buffer[12]);
	n[reg]=11;
      }
    }
    bt = ((k>>n[reg])&0x01) ^ strobe;;
    n[reg]--;    
    break;
    
  case 84: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k=(adc_buffer[12]);
	n[reg]=11;
    }
    bt = ((k>>n[reg])&0x01) ^ strobe; // top bit first
    n[reg]--;    
    break;

  case 85: // padded version of SR of bitsin
      if (n[reg]>length) {
	if (length<12) ADCshift_[reg]=(adc_buffer[12])>>(11-length); 
	else ADCshift_[reg]=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    n[reg]++;
    bt=((ADCshift_[reg]>>length)&0x01) ^ strobe;;
    ADCshift_[reg]=(ADCshift_[reg]<<1)+bt;
    break;
    
    


// from adcetc

// 0-31 (32)modes +1 INTmode
// arrange modes now as most important first...

   
   /*  case 63: // =- input regardless of length - this was same as 5 but MSB 
    // also try as MSB - now...
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k=(adc_buffer[12]);
	n[reg]=11;
    }
    bt = (k>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;
   */

   /*
  case 64: // was strobe mode for cycling bits a la TM - no input but now uses ADC input as probability! - cvmode
    bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    if (((LFSR_[reg] & 4095 ) < adc_buffer[12])){
      bt=!bt;// invert cycling bit
    }
    break;
   */    


// 18/1/22 but we don't use this
// more generic ADC_ in = so income is passed in function and can be LFSR so we have different handlings
static inline int ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR, uint32_t *income){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator=0.0f, oldValue=0.0f;
  static uint32_t k, lastbt=0; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  static uint8_t toggle=0, lc=0;
  uint32_t bt=0, bit=0;
  float inb;

  switch(type){
    
  case 0: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(*income)>>(11-length);
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
  }
}


    /* // LSB first
  case 0: // basic sequential length of upto 12 bits cycling in    
      if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length);
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01; // this means that LSB comes out first
    n[reg]++;    
    break;
    */


    /*
  case 2: // one bit audio input - can also change the 48??? - this one makes wierd phase effects
    n[reg]++;
  if (n[reg]>48) {
    k=(adc_buffer[12]); 
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;
    */
        


    /*
  case 2: // try with float but this is the same with phasings
    inb=(((float)adc_buffer[12])/2048.0f)-1.0f; // from 0 to 4095 but where is the middle?
    integrator+=(inb-oldValue);
   if(integrator>0.0f)
  {
     oldValue=1.0f;
     bt=1;
  }
   else
   {
      oldValue=-1.0f;
      bt=0;
   }   
   break;    
    */     

   /*      
  case 3: // basic sequential length as in 0 but with padding if >11 bits **
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else {
	  k=(adc_buffer[12]);//<<(length-11); // should be -11 // pads with 0s at the bottom LSB first
	  //	  k+=((k>>length-11)&masky[length-11]); // pad with a repeat?
	  //	  k+=padding[length-11]; // TESTY! - padding with 1s
	}
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
   */

   /*
  case 3: // basic sequential length as in 0 but with padding if >11 bits **
    // REVERSAL again doesn't change much
      if (n[reg]<0) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else {
	  k=(adc_buffer[12])<<(length-11); // should be -11 // pads with 0s at the bottom LSB first
	  // double up
	  //  k+=((k>>length-11)&masky[length-11]); // pad with a repeat?
	  //	  k+=padding[length-11]; // TESTY! - padding with 1s - doesn't change much
	}
	n[reg]=length;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;    
    break;
   */
   /*
  case 3: // basic sequential length of upto 12 bits cycling in MSB first    
        if (n[reg]<0) {
	  //	  k=pow(2,length)+1;
	  k++;
	  if (k>4095) k=0;
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
   */
   /*  case 3: // basic sequential length of upto 12 bits cycling in MSB first    
        if (n[reg]<0) {
	  k=adc_buffer[12];
	  n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
   */   



/* options here:
1. 9 bit speed +dac ->   speedf__=logspeed[(CV[0]&511)+(gate[whic].dac>>3)];

2. speed+dac with max:
cv=(CV[0]>>2)+(gate[3].dac>>2);
if (cv>1023) cv=1023;
speedf__=logspeed[cv];

3. DAC - (1024-speed) // so if speed is 0-fastest 
cv=(gate[3].dac>>2)-(1024-(CV[0]>>2));
if (cv<0) cv=0;
speedf__=logspeed[cv];

4. speed-dac
cv=(CV[0]>>2)-(gate[3].dac>>2)-
if (cv<0) cv=0;
speedf__=logspeed[cv];


5. DAC % speed we have below
 */

//  if (speedf_[0]==2.0f) speedf_[0]=0.000990f;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[speedfrom_[0]].dac>>2)]);
//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  //  if (speedf__<0.000990f) speedf__=0.000990f;
  //  speedf__=1.0f;
  //  speedf__=logspeed[(CV[0]>>3)+(gate[3].dac>>3)];


void trial(void){
  static uint32_t xxxx=0;
  xxxx^=1;
  if (xxxx) gate[2].dac = 4095;
  else gate[2].dac=0;
    //  gate[2].dac=100;
}

void trial2(void){
  gate[0].dac=0;
}





// from main


older: fast interrupt (TIM?) for all shift registers with counters,
interrupt for ADCs (TIM?), interrupt for pulsed SR, PWM for
default/normed clockings (set by speed pot)

or just one timer for all and run at max speed with counters

- ADC input schemes - number of bits, sigma/delta, bit equality (unary - no weighting) with x bits
- 4x pin interrupts, how many timers
- working with sigma delta ADC, DAC out, digital filter simulator and list first all possible modes and ways of operating
- clock from speed/cv, clock from external pulse, clock from other
  shift register // combos of thse so could be ext pulse AND/XOR/OR
  other shift reg or clocked speed pulse etc.
- bitdsp library borrowings?
- fakes, ghosts, SR_IN_SR, overlaps
- add artificial drift and dropped bits

Sigma/delta out as pulses and as DAC (low pass?)


/////

TODO: new notes, collect all notes, modes and speed/basic tests

Questions: how we use the 5 fake pulse outs normed to pulse ins: PB10-PB15 ! 

Newest PCB (14/5/2021) with new ADC(ADC12//on pin PC3) TESTED ALL FINE

9/7/2021: ADC in and DAC tested correctly with 11vPP for 0-4095

14/7/2021 - retested allFINE: 

all ADC ins: mode, spd and len x4

  // map ADCs: note all modes are inverted

  // 0: nspd, 1: nlen, 2: nmode
  // 3: lspd, 4: llen, 5: lmode
  // 6: rspd, 7: rlen, 8: rmode
  // 9: cspd, 10: , 11: cmode

/ pulse ins: PC7 is RSRIN, PC8 is LSRIN XDONE

/ interrupt ins: LSR, RSR, CSR, NSR -DONE / PWM outX, pulse outsXDONE

CSRCLKIN moved from PC3 to PB7

///

Newest PCB: all working 19/4 but we will need to re-work ADC entry -
test now with lower cap on say ADC0 - nspeedin c30->100pf//33k, removed cap (but leave on schematic)
and increased ADC speed, changed to continuous mode and we have a high
sample rate in 100kHZ
 
16/4/2021->19/4/2021:

- what needs testing? DAC outDONE, ADCs inDONE, 

- all pulses in //(and volts knob for ADC pulsed in: PC9->PC14-REDO)DONE

- pulses outDONE

TIM1-CH1 normings WORKING - so is TIM1 normed to top clock/NSR

----> could do with organizing all a bit better with arrays

///


TESTED/WORKING: ADC all tested, DAC out tested, pulses out all tested, TIM1-CH1 norming to top clock, volts knob/primitive ADC, pulse ins, interrupt pulse ins 

/////////

// copied over from TOUCH so we need to change ADCsDONE, DAC out is the same, add timers and change interrupt timing, add external interrupts, PWMS.

TODO: list our new I/O here, check interrupts and PWM

- general scheme of things

///// OLDER

Testing on STM32F446 NUCLEO. Prog header is same as TOUCH. STM is same as touch

This was copied from TOUCH so some things will need to change: 

But we can keep DAC on PA4


fast interrupt (TIM?) for all shift registers with counters, interrupt for ADCs (TIM?), interrupt for pulsed SR, PWM for default/normed clockings (set by speed pot)

I/O:

- pulse ins: PC3-5 + PB6 clkins(interrupts), PC7/8 pulsein, PC9-MSB, to PC14-LSB of 6 bits
- ADC 0-11 see adc.c
- DAC out PA4
- TIM1-CH1 drived normed top LFSR - and we need 2 extra internal timers! 
- 11 pulse outs: PB2,3,4,10,12,13,14 = 5 fakes and 6 real out + now we have changed for schematic: PA11=pulse6, PA12=pulse4, PC15=pulse5, PB15=pulse7

apparently there are 12x 16bit and 2x 32 bit timers (TIM2, TIM5) 

 */

/// Copied 23/2/2021 from TOUCH code...

/*
void TIM2_IRQHandler(void) {
  // flash on update event
  if (TIM2->SR & TIM_SR_UIF) GPIOA->ODR ^= (1 << 5);
   
  TIM2->SR = 0x0; // reset the status register
  }*/



// from draftspeed:



  // crash detect ++ 32/64 in main.c is 14KHz //and/or speed check...
  //    flipper^=1;
  //  if (param[0]>4090){
  //    if (flipper) GPIOB->BSRRH = (1)<<12;  // clear bits PB12 - left normed clock I think
  //    else   GPIOB->BSRRL=(1)<<12; //  write bits   
  //  }

    /* // we don't deal with CLKs now!  
    //TODO: ghostSRs for normed clks (with speed of these from what, from RDAC?)
  if (w==2 && counter[2]>speed[w] && speedfrom[2]==1){ // 2 is Cspeed - but we have a problem when Cspeed is from an interrupt as this is never generated...FIXED HERE
      counter[2]=0;
      flipper^=1;
      if (flipper) GPIOB->BSRRH = clk_route[clkr];  // clear bits of fake_one - clkr is 7 so all of them
      // or we can set L and R from an independent SR with only CSR as clocked from here
      else   GPIOB->BSRRL=clk_route[clkr]; //  write bits       
    }
  */


  /*
  if (time_now[w]>32768){
      int_time[w]=0; 
      time_now[w]-=32768.0f;
    }

  // fixed interpol
      alpha = time_now[w] - (float)int_time[w];
      dac[w] = ((float)delay_buffer[w][DELAY_SIZE-5] * alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - alpha)); // interpol but is just last and before last
      if (dac[w]>4095) dac[w]=4095;
      else if (dac[w]<0) dac[w]=0;
      //      dac[w]=lastdac[w];

  time_now[w] += speedf_[w];
  last_time[w] = int_time[w];
  int_time[w] = time_now[w];

  if(last_time[w]<int_time[w])      {
    // do all
    // test as a function pointer
    //    mode[w]=testmodes[w];
    //    val=(*dofunc[mode[w]])(w); // this seems to work
    //    val=(*gate[L].dofunc[0])(w);
    
    GSHIFT;


void Rnofrac0(void){
  uint8_t w=3;
  HEAD;
  if (counter[3]>speed[3] && speed[3]!=1024){
    counter[3]=0;			       
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  }
}


void Cnofrac0(void){
  gate[2].dactype=0; gate[2].dacpar=param[2];
  uint8_t w=2;
  HEAD;
  if (counter[2]>speed[2] && speed[2]!=1024){
    counter[2]=0;				
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  }
}

void Lnofrac0(void){
  uint8_t w=1;
  HEAD;
  if (counter[1]>speed[1] && speed[1]!=1024){
    counter[1]=0;				
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
    }
}

void Nnofrac0(void){
  uint8_t w=0;
  HEAD;
  if (counter[0]>speed[0] && speed[0]!=1024){
    counter[0]=0;			      
    GSHIFT_;
    bitn=ADC_(0,SRlength[0],0,gate[0].trigger,3,param[0], &gate[w].shift_);    
    BITN_AND_OUTVINT_; 
  }
}



    if (w==0){
      bitn=ADC_(0,SRlength[0],0,trigger[0],reggg,adcpar); 
    }
    BINROUTE;
    if (LR[w]){
      PULSIN_XOR;
    }
    BITN_AND_OUTV; // special version for this in macros.h  
    new_data(val,w);
    //    lastdac[w]=val;
    last_time[w] += 1;
    
  } // lasttime
  */


// worm speed

if (time_now>32768){
    int_time=0; 
    time_now-=32768.0f;
    }

alpha = time_now - (float)int_time;

outt = ((float)delay_buffer[DELAY_SIZE-5] * alpha) + ((float)delay_buffer[DELAY_SIZE-6] * (1.0f - alpha)); // interpol but is just last and before last
if (outt>LIMIN) outt=LIMIN;
 else if (outt<-LIMIN) outt=-LIMIN;
out[ii]=outt;

  time_now += factor;
  last_time = int_time;
  int_time = time_now;

while(last_time<int_time)      {
    doadc();
    int16_t val=getsample();
    new_data(val);
    last_time += 1;
  }
 }
}



//    dac[2]=(adc_buffer[12]);
    /*        k=(adc_buffer[12]); // from 0 to 4095 but where is the middle?
    integrator+=(k-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=4095;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   dac[2]=bt;
    */

    //    bt = ((ADCshift_[0] >> (lfsr_taps[SRlength[0]][0])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][1])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][2])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][3]))) & 1u;
      //            bt^=1;
      //          if (rand()%4) bt^=1;

      //      ADCshift_[0]=(ADCshift_[0]<<1)+(bt&1);
      //      x=(((ADCshift_[0] & masky[SRlength[2]])<<8));//<<leftshift[SRlength[2]])&4095);//>>(rightshift[length]))<<leftshift[length];
      //      dac[2]=x;//(bt*4095);




// draft for INTmodes - - TODO: probability of advance on trigger using CV as prob
case 50:
  param[w]=adc_buffer[lookupadc[w]];
  if (trigger[w] && (shift_[LFSR[w]] & 4095) > (param[w] & 4095) ){ // or this could be based on a real: shift_[3] which we try here for better effect
    dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
    ADCDACETC1(0, 0);
    if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
      PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

// draft for CV with INT - where to place this? and we can't really use CV as param here!
case 49:
    if (counter[w]>speed[w] && speed[w]!=1024){
      if (trigger[w]){
	param[w]=adc_buffer[lookupadc[w]];// ??? use another param eg.
	dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
	ADCDACETC1(0, 0);
	if (LR[w]){
	//////////////////////////////////HERE!
	BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/////////////////////////////////////...
	PULSIN_XOR;
      } 
      BITN_AND_OUT;
    }
}
break;



/// intmodes

  case 24: // len is otherpar but there is no shift - OTHERPAR! 12 bits
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    otherpar=otherpar&31; // 5 bits
      if (n[reg]>otherpar) {
	k=adc_buffer[12]; //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
    
  case 25: // len is otherpar but there is shift from otherpar  - OTHERPAR! 12 bits
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
        otherpar=otherpar&31; // 5 bits
      if (n[reg]>otherpar) {
	if (otherpar<12) k=(adc_buffer[12])>>(11-otherpar); 
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 28:// ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) { 
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;
      }
    break;

    // we use otherpar to determine number of bits - equal or otherwise  - OTHERPAR! 12 bits
     // we can also use otherpar=CV or otherwise as padding, length of bits which is not LEN!
  case 29:   // as case 17: // basic sequential length as in 0 but with padding if >11 bist
    // maybe restrict otherpar
    otherpar=otherpar&31; // 5 bits
      if (n[reg]>length) {
	if (otherpar<12) {
	  k=(adc_buffer[12])>>(11-otherpar); //
	}
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 33: //  ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) { 
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;
      }
    else
      {
	bt=(shift_[reg]>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
      }
    break;

  case 34: // prob mode for cycling bits a la TM
    bt=(shift_[reg]>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) {
      bt=!bt;// invert cycling bit
    }
    break;
    ////////    
    // INT MODES ONLY FROM HERE ON! but these are just copies of some modes above!
     /*
  case 60: // INT // CV as comparator - for INT modes ONLY which don't use CV! can also be CV+DAC
    // we can also compare to: DAC, CV+DAC, to clksr_, to param - feed these into otherpar or have as options
     bt=0;
         if (adc_buffer[12]>adc_buffer[lookupadc[reg]]) bt=1; // can also be otherpar to make cleaner = then is same as mode 26!
     break;

  case 61:  // was case 6 //param[reg] seq input - what is size of param? /or we can also just feed in otherpar = CV in
    otherpar=otherpar>>7; // 5 bits
      if (length>11) length=11; //XXX12 bits or 8 bits
      if (n[reg]>length) {
	k=(otherpar])>>(11-length); 
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 63: // XOR or OR of case 4 - 1 bit oscillator and input bits  - OTHERPAR! 12 bits
  if (length>11) length=11;
      if (nnn[reg]>length) {
	k=(adc_buffer[12])>>(11-length); 
      nnn[reg]=0;
    }
    bt = (k>>nnn[reg])&0x01;
    nnn[reg]++;    

    otherpar=otherpar>>4; // how long? it should be?
     if (n[reg]>length) { // 0s
       bt|=0; // XOR TODO
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt|=1; // XOR TODO
       n[reg]++;
       nn[reg]=0;
     }         
     break;    
     */


     // TODO: CV+ADC as input for some of the INT modes perhaps
     // CV can modulus ADC input




case 15: // basic sequential length of upto 12 bits cycling in - leave out of cvmodes!!
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(otherpar)>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

// discard

  case 19: // sequential clksr in TESTED! - lose this one as we have 18 - clkbits in anyways
    if (n[reg]>length) {
      k=(clksr_[reg])>>(31-length); 
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;


/// strobes

  case 17: // basic sequential length of bits cycling in but zeroed by strobe
  if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    } 
     if (strobe) bt=0;
      else bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;


case 7:     // we accumulate bits onto a ghosted register
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { // strobe
      shift_[reg]&=invmasky[length]; // clear length bits
      shift_[reg]+=(ADCGshift_[reg]&masky[length]);
    }
    break;

  case 8:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa
    if (strobe) toggle^=1;

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      if (toggle) {// strobe
      bt = (k>>n[reg])&0x01;
      lastbt=bt;
      }
      else bt=lastbt;
    n[reg]++;    
    break;
    
  case 9:     // 2-we only cycle ADC on strobe/toggle  - or vice versa
        if (strobe) toggle^=1;
    if (length>11) length=11; //XXXmax12bits

  if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;

      if (toggle) {// strobe
    n[reg]++;    
      }
      break;

  case 10: // STROBE: 3-one bit entry
    if (strobe) toggle^=1;
    n[reg]++;
  if (n[reg]>50) {
    k=(adc_buffer[12]);
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   

   if (toggle) {
	lastbt=bt;
      }
      else bt=lastbt;
   break;

     case 11:// STROBE: run LFSR-ADCshift and output a bit - REGG!
       if (strobe) toggle^=1;
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;    
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

  case 12: // STROBE for other LFSR too - REGG!
    if (strobe) toggle^=1;
    bt = ((shift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;    
    break;

  case 13: // strobe moves up next LFSR ghostL tap - REGG!
    if (strobe){
      lc+=1; // or we can make this depend on...???
      if (lc>3) lc=1; 
	  ghost_tapsL[length][lc]+=1;
	  ghost_tapsL[length][lc]%=31;
	}           
    bt = ((shift_[regg] >> (ghost_tapsL[SRlength[regg]][0])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][1])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][2])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][3]))) & 1u;    
    break;

  case 21: // padded case 8    // we accumulate bits onto a ghosted register **
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); 
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { 
      shift_[reg]&=invmasky[length]; // clear length bits
      shift_[reg]+=(ADCGshift_[reg]&masky[length]);
    }
    break;

  case 22:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa **
    if (strobe) toggle^=1;
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length);
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;
      if (toggle) {
    n[reg]++;    
      }
    break;



// TESTY: testing for simultaneous shifter - but what of modes where we hold back the gshift eg. modes: 37, 48, 49
   // we need to remove all gshifts also in ADC macros
   /*   
   if (w==0){
   if (new[0]){
     new[0]=0;
     GS(0);
   }
   if (new[1]){
     new[1]=0;
     GS(1);
   }
   if (new[2]){
     new[2]=0;
     GS(2);
   }
   if (new[3]){
     new[3]=0;
     GS(3);
   }   
   }
   */

    /*
    // trial for new update plan
  case 1: // for all just pass through - ADC NONE/pass, LR pass, DAC 0/pass
    if (counter[w]>speed[w] && speed[w]!=1024){
        counter[w]=0; new[w]=1;
	shift_[w]=shift_[w]<<1;
	dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC_
	dactype[2]=0;
	ADCDACNOGS(0, 0);
	if (LR[w]){
	BINROUTE;
	PULSIN_XOR;
	}
	BITN_AND_OUT;
    }
    break;
    */


/* // basic mode to test ADC/DAC modes with equiv LR modes
 
case x:
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; par=0; // for DAC
    logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1; // logic for ops
    GSHIFT;

    if (w==0)      {
    BITNNN;
    bitn^=ADC_(w,SRlength[w],2,0); // choose mode and params - can return 0 from adc for no effect
    }
    else
    {
    BITNNN;
    }
    PULSIN_LOGOP;    
    BITN_AND_OUT;
  }// counterw
  break; 
*/


// for this macro we need  dacpar=0/whatever for DAC and adcpar is for ADC - defined outside macro
// X is adc_type, Y is dac_type
#define MULTROUTE(X, Y) {			\
  bitn=0;					\
  dactype[2]=Y;					\
  GSHIFT;						\
  if (w==0)      bitn=ADC_(0,SRlength[0],X,trigger[w],reggg,adcpar);	\
  tmp=binroute[count][w];						\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  PULSIN_XOR;						\
  BITN_AND_OUT;						\
}
//pulsin_xor above would need an if (w==1 || w==3)


// how can we abstract these out a bit so is not so many...  - for CV modes just have a few examples of each and work more with strobes

9 prob mode 0 -invcycle with dac[dacroute]
10 prob mode 1 -invcycle with param 

as above but with routed in bits too

*invcycle is more like ADC mode if is without routein*

11 prob of bitin(which?) or loopback - dac
12 prob of bitin or loopback - param  

bitins: adc-0,pulse-1,3,routein-all

pulse
routein
routein_logop_pulse 

13 inverted versions of above
14

loaded/notloaded into cycling SR
15 incoming bit = routed in 
// w==0 adc in instead of puls below (xor with 0 - mode 28 for ADC we have - XOR against loop, routed in)
16 incoming bit = pulse in (1,3)
17 incoming bit = route/
18 incoming bit = route/pulse

all x2: 2.if SR<DAC  // cv/int mode 4.if sr<CLKCNT // cv mode - we need to trim this down

   - TM: prob of bit in/inverted bit in - above (ORed with incoming bit/s: routed, ADCed, pulsed)
   - others: prob of bitin or loopback 
   - prob of bitin or inverted loopback
   [-electro: incoming bit is loaded/not loaded into cycling SR]

+++ as above but with toggles or strobes

- do we already have strobe as incoming adc or not? YES as case 17



// need to catch it but this gives us false beats
      //      if (shift_[w]==0 || shift_[w]==FULL)     shift_[w]=0x01; 

  //  cogg[w][0]=0; // if we end up using these...
  //  cogg[w][1]=0;
  //  cogg[w][2]=0;
  //  cogg[w][3]=0;

  //2-where is the input bit from (LFSR, ADC type?)- can also be from another LFSR? ADC types we have in test2.c - or no inputbit
    //    bitn=0;
      /*
    if (inputbit[w]==0){ // LFSR from SR in LFSR[w]
      bitn = ((shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][0])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][1])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][2])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][3]))) & 1u; // we would use this in final...
    }
    else if (inputbit[w]==1) {// do input from type of ADC specified
      // static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type){ // here we use length as number of bits max is 12 bits
      bitn=ADC_(w,SRlength[w],adctype[w]);
    }
    else bitn=0;
      */



// flip PB4 to test interrupt on PB7 -> CSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  // flip PB4 to test interrupt on LSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  // flip PB4 to test interrupt on  RSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   



((longer&(0b1111111111111111111111111111111100000000000000000000000000000000+othermasky[31-srlength])>>(sh-shifter))); // so this seems to work

if (coggn==0)  {// unsure of this logic
    //     shift_registerl=(shift_registerl^masky[sl])+bitn;

    tmpt=(SRlengthn-(sl-1)); // again what if sl is longer than lengthn - this is key figure
    if (tmpt<(sl-1)) tmpt=(sl-1);
    shift_registerl=((shift_registerl<<1)^masky[sl]);
	shift_registerl+=((shift_registern&(othermasky[sl-1])>>tmpt)>>tmpt);
	shift_registerl+=(bitn<<(sl-1)); // but that bit needs to be empty
	}
  // COGGN should also be x bits across!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TODO-DONE TO TEST
  else {
    // then here we want sl x bits from the top masked in
    //    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    /*    tmpt=(SRlengthn-(coggn-1))-sl;
    if (tmpt<sl) tmpt=sl;
    shift_registerl=((shift_registerl<<1)^masky[sl])+(shift_registern&othermasky[sl])>>tmpt;
    */
    //    tmpt=(SRlengthn-(sl-1)); // again what if sl is longer than lengthn - this is key figure
    tmpt=(SRlengthn-(coggn-1))-sl;
    if (tmpt<sl) tmpt=sl;
    shift_registerl=((shift_registerl<<1)^masky[sl]);
    shift_registerl+=((shift_registern&(othermasky[sl])>>tmpt)>>tmpt);
    //    shift_registerl+=(bitn<<(sl-1)); // but that bit needs to be empty
    
  }


countern++;
  if (countern>=speedn){ 
    countern=0;
    // repeat x times
    sl=moden>>2;
    tmpp=0;
    for (x=0;x<sl;x++){
      bitn = (((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u); // 32 is 31, 29, 25, 24
      tmpp+=bitn<<x;
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    }
    coggn=0;
    bitn=tmpp;
  }
//  }
  
    // test pulse ins   // inpulse interrupts to attach are: CSR: PC3, NSR: PC4, RSR: PC5, LSR: PB6
    // PC7/8 pulsein (RSR-7/LSR-8), PC9-MCB, to PC14-LSB of 6 bits
    
    // test in gives out on PB4 - always inverted...
    //    if ((GPIOC->IDR & (1<<7)))  GPIOB->BSRRH = (1)<<4;  // clear bits PB4
    //    else   GPIOB->BSRRL=(1)<<4; //  write bits   
    //  if (k==0) k=4095;
    //  else k=0;
    //  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    //  ADC_SoftwareStartConv(ADC1);


//k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!

// OLD BITS DAC STUFF!!

  //  k=4095-k;
  //  k=rand()%4095;
  //  k++;
  //  if (k>4095) k=0;
  //    k=(((GPIOC->IDR & (1<<9)))<<11) + (((GPIOC->IDR & (1<<10)))<<9) + (((GPIOC->IDR & (1<<11)))<<7) + (((GPIOC->IDR & (1<<12)))<<5) + (((GPIOC->IDR & (1<<13)))<<3) + (((GPIOC->IDR & (1<<14)))<<1) ;//  - 2048;// probably easier way to do this
  // check each one
  //  k=((!(GPIOC->IDR & (1<<14)))<<11); //14 haas issues
  //  k=(1<<11); //puts us in middle
  //      k=4095; // with
	//  k=4000; // with R35 as 150k and R34 as 66.5k we have 4095 as -4.96 and 0 as 5.6k // 180k puts us opposite (-5.6) so we need like 160k
  // we leave buffer on DAC or these values change
  //  k=rand()%4095;




  // http://www.danbullard.com/dan/A_Sigma_Delta_ADC_Simulator_in_C.pdf
  // https://www.mikrocontroller.net/topic/293454

      
  // outPUT
  //DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  // j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

  //  if(ll)      GPIOB->BSRRH = (1)<<4;  // clear bits PB4
  //  else   GPIOB->BSRRL=(1)<<4; //  write bits 
  //  ll^=1;


RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // TEST - PC8 input from 40106 for freezing/rec/play etc. power it with 3.3v

  // led first
  //  GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output

  // internal DAC PA4 with multiplex with EN_LOW1 on PC11 and sel1/2/3 on PC13/14/15


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);



  // led first
  //  GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output


  //    io_config2 ();
    //DAC_Cmd( DAC_Channel_2, ENABLE);
    //    DAC_Cmd( DAC_Channel_1, ENABLE);

    // set enable=say 13 and 14 pin (active LOW) and pins for 4051: PB8,9,10

    /* TODO: testing for external DAC such as MPC492X (one or two DACs) - test with 4922

- setup SPI on SPI2 or SPI3 (SPI1 would conflict with ADC ins)
- communicate with DAC1 and test 
    */

	    /*
	    int main(void)
{
  // this is for flashing onboard LED LD2 on pin PA5

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // enable the clock to GPIOD
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // enable TIM2 clock
     
    GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output
     
    NVIC->ISER[0] |= 1<< (TIM2_IRQn); // enable the TIM2 IRQ
     
    TIM2->PSC = 0xff; // no prescaler, timer counts up in sync with the peripheral clock
    TIM2->DIER |= TIM_DIER_UIE; // enable update interrupt
    TIM2->ARR = 0xffff; // count to 1 (autoreload value 1)
    TIM2->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // autoreload on, counter enabled
    TIM2->EGR = 1; // trigger update event to reload timer registers
      
    while (1);
}
	    */


	          // test SPI comms - what message to send a value to the DAC1!?
      // from arduino code: https://github.com/michd/Arduino-MCP492X/blob/master/MCP492X.cpp
      //      value=k;
      
      //      delay();
      // flip-flop from PC8
      //      GPIOA->ODR ^= (1 << 5);      

      /*
      
      if (GPIOC->IDR & 0x0100){ // pin 8 
      if (flipped==0) {
	flipped=1;
	prev_state=0;
      }
	}
	else flipped=0;
	  
	if (flipped==1 && prev_state==0)
	  {
	  prev_state=1;
	  GPIOA->ODR ^= (1 << 5);
	  }
      */
      
      /// multiplex and DAC tests
            
      //    GPIOB->ODR = 0b0000000100000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    // Y1 is S1 on 4051 high which is 11 on 4051 which is pin PB8
      /*      otherk++;
      if (otherk>32){
	otherk=0;
      k++;
      if (k>4095) k=0;
      }*/
      //      k=0;
      //    DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
      //    j = DAC_GetDataOutputValue (DAC_Channel_1);
    //    delay();
    //    GPIOB->ODR = 0b0000000000000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    //    DAC_SetChannel1Data(DAC_Align_12b_R, 4095-k); // 1000/4096 * 3V3 == 0V8
    //    j = DAC_GetDataOutputValue (DAC_Channel_1);
    //    delay();

	        GPIO_InitTypeDef GPIO_InitStructure;
    
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

