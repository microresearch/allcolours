// 1. speeds - divide into strobe and non strobe - reserve xor ones...

// we need 32 only
uint32_t (*speedfromnostrobe[34])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfracend, spdfracend, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob3_nosh, binroutfixed_prob4_nosh}; // 2x spdfrac and spdfracend for interpoll

// can't include itself in nosh at end so this one is for modeC - geoC
uint32_t (*speedfromnostrobenoend[34])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zinvprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, binroutfixed_prob1_nosh, binroutfixed_prob2_nosh, binroutfixed_prob4_nosh, zSRNbits, zprobbits, zsprobbits}; // 2x spdfrac for interpoll

uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift}; 

uint32_t (*speedfromcvforxor[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbits, zTMsimplebits};// no strobes, no routes and only CV ones... doubled up

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

// maybe have parallel probf sans. strobe, zeroes, ones and only depth/cv based!!! no IN?
uint32_t (*probfsins[32])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, zosc1bits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits}; // all use depth // updated with speed

// based on strobe speeds - no depths - how to have more???
uint32_t (*probfstrobes[16])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift};

// with depths
uint32_t (*probfstrobesdepth[6])(uint32_t depth, uint32_t in, uint32_t wh)={strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle}; 

// tails
void (*dotail[32])(void)= {fliptail, basictail, succtail, succtailback, tailC, tailL, tailR, tailN, basictailnos, succtailnos, succtailbacknos, tailCnos, tailLnos, tailRnos, tailNnos, basictailinv, succtailinv, succtailbackinv, tailCinv, tailLinv, tailRinv, tailNinv, basictailnosinv, succtailnosinv, succtailbacknosinv, tailCnosinv, tailLnosinv, tailRnosinv, tailNnosinv, tailXOR0, tailXOR1, tailOR};

// global opps
void (*globalls[21])(uint32_t depth)={resett, binaryN, binaryX, SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalbumpspd, SRRglobalbumpcv, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalsync, SRRglobalorder, SRRglobalbumpcvntype, SRRglobalbumpbit0, SRRglobalbumpbit1, SRRglobalbumpbit2, SRRglobalorderbumpS, SRRglobalorderbumpbit, SRRglobaltailset}; 
