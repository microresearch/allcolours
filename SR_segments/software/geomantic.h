// 1. speeds

// 6/2/ all use depth
uint32_t (*speedfromnostrobe[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfracend, spdfracend, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zcompbits, spdvienna, spdvienna2, spdvienna3, spdvienna4, zprobbits, zTMsimplebits, zTMsimplebits, osceq, zosc1bits, zENbits, zENbitsI,  zENsbits, zENsbitsI, sigmadelta, zbinrouteSRbits, zwiardnotinvbits, zwiardnotinvbitsL, zsuccbitsI_noshiftd, zSRNbits, zsprobbits, zcountbits, zcountbitsI}; // 31!! 2x spdfrac and spdfracend for interpoll //  checked for depths and tested 6/2

uint32_t (*speedfromnostrobe_noIN[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfracend, spdfracend, spdfrac2, spdfrac3, spdfrac4, spdfrac5, zprobbits, zTMsimplebitsL, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI, zENsbits, zENsbitsI, sigmadelta, zbinrouteSRbits, zwiardnotinvbitsL, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbits_noshiftd, zsuccbitsIpp, zsuccbitsI_noshiftd, zSRNbits, zsprobbits, zcountbits, zcountbitsI, spdfrac};

uint32_t interpfromnostrobe[32]={1,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}; // TODO match with speedfromnostrobe

uint32_t speednoin[36]={0,0,0,0, 1,1,1,1, 1,1,1,0, 0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0}; // in the above which ones use IN -> dacfrom

uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift}; 

uint32_t (*speedfromcvforxor[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbits, zTMsimplebits};// no strobes, no routes and only CV ones... doubled up

// new
uint32_t (*speedfromstrobe_depth[16])(uint32_t depth, uint32_t in, uint32_t wh)={strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, /**/strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, /**/strobespdfrac, zstrobeBURST, clksrG, clksr}; // 6  add xor with speed = where was? as insides?

uint32_t (*speedfromstrobe_nodepth[16])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, /**/strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift};

// 2. adc

uint32_t (*adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zadcx, zadcx, zadconebitsx, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, cipher, zadcLBURST0, zadccomp, zadcxdouble, zadcxcut, zadc4bitsadd,  zadc4bitsaddmod, zadc4bitsxor, zadc4bitsor, zadc4bitsand, zadc4bitsmodm, zadc4compbitsadd, zadc4compbitsxor, zadc4compbitsmodm, zadc4onecompbitsadd};

uint32_t adcfromsd_depth[32]={1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

//for above
//{zeros, zadcxD, zadconebitsxD, zadcpadbitsD, zadc12bits, zadc8bits, zadc4bits, zadceqbitsD, zadcenergybitsD, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbitsD, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbitsD, cipherD, zadcLBURST0D, zadccompD, zadcxdoubleD, zadcxcutD, zadc4bitsaddD,  zadc4bitsaddmodD, zadc4bitsxorD, zadc4bitsorD, zadc4bitsandD, zadc4bitsmodmD, zadc4compbitsaddD, zadc4compbitsxorD, zadc4compbitsmodmD, zadc4onecompbitsaddD};

// with extra vars for reset and advance for probability
uint32_t (*padcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv)={zpadcx, zpadcx, zpadconebitsx, zpadcpadbits, zpadc12bits, zpadc8bits, zpadc4bits, zpadceqbits, zpadcenergybits, zpadc12compbits, zpadc8compbits, zpadc4compbits, zpadccompbits, zpadc12onecompbits, zpadc8onecompbits, zpadc4onecompbits, zpadconecompbits, pcipher, zpadcLBURST0, zpadccomp, zpadcxdouble, zpadcxcut, zpadc4bitsadd,  zpadc4bitsaddmod, zpadc4bitsxor, zpadc4bitsor, zpadc4bitsand, zpadc4bitsmodm, zpadc4compbitsadd, zpadc4compbitsxor, zpadc4compbitsmodm, zpadc4onecompbitsadd};

/////////////////////////
// 3. bits/routes and see list there

#include "newbits.h" // for bits and routes

// 4. probs

uint32_t (*probf_anystrobe_depth[64])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdvienna, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, ztogglebits, ztogglebitssh, zbinroutebits_noshiftd, zbinroutebits_noshift_transitd, zbinroutebitsI_noshiftd, zbinrouteSRbitsd, zsuccbitsI_noshiftd, zsuccbits_noshiftd, /**/zinvprobbits, zprobbits, zsprobbits, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta};//41 _.63
// use IN: spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, compbits, spdvienna

uint32_t (*probf_anystrobe_depth_noin[32])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zownprobbits, zownGprobbits, spdfrac, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, sigmadelta, spdvienna, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, ztogglebits, ztogglebitssh, zbinroutebits_noshiftd, zbinrouteSRbitsd, zsuccbitsI_noshiftd}; // 35 -3

uint32_t (*probf_anystrobe_nodepth[16])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, strobe, ztogglebitsnod, ztogglebitsshnod, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift}; // >>8

uint32_t (*probf_nostrobe_depth[33])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdvienna, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, zbinroutebits_noshiftd, zbinroutebits_noshift_transitd, zbinroutebitsI_noshiftd, zbinrouteSRbitsd, zsuccbitsI_noshiftd, zsuccbits_noshiftd}; // 33

// maybe ignore
uint32_t (*probf_nostrobe_nodepth[16])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbits, zsuccbitsI, zsuccbits_noshiftnod, zsuccbitsI_noshiftnod, /**/zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth}; // 10
										

// 5. tails
void (*dotail[32])(void)= {fliptail, basictail, succtail, succtailback, tailC, tailL, tailR, tailN, basictailnos, succtailnos, succtailbacknos, tailCnos, tailLnos, tailRnos, tailNnos, basictailinv, succtailinv, succtailbackinv, tailCinv, tailLinv, tailRinv, tailNinv, basictailnosinv, succtailnosinv, succtailbacknosinv, tailCnosinv, tailLnosinv, tailRnosinv, tailNnosinv, tailXOR0, tailXOR1, tailOR}; // 1 is basictail. default

// 6. global opps - add those which operate on various global flags, and orderings (we have no?)
void (*globalls[20])(uint32_t depth)={resett, binaryN, binaryX, SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalbumpspd, SRRglobalbumpcv, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalsync, SRRglobalorder, SRRglobalbumpbit0, SRRglobalbumpbit1, SRRglobalbumpbit2, SRRglobalorderbumpS, SRRglobalorderbumpbit, SRRglobaltailset}; 
