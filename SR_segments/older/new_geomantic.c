// unused and check changes

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

