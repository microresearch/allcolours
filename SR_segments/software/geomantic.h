// 1. speeds - divide into strobe and non strobe - reserve xor ones...

/*
list these:

speedfromnostrobe
speedfromnosdac

speedfromforxor[5] -> so far we just use this as fixed [0] so no need to expand...
speedfromcvforxor

speedfromstrobe
speedfromstrobenodepth

 */

// 6/2/ all use depth
uint32_t (*speedfromnostrobe[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfracend, spdfracend, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zcompbits, spdvienna, spdvienna2, spdvienna3, spdvienna4, zprobbits, zTMsimplebits, zTMsimplebits, osceq, zosc1bits, zENbits, zENbitsI,  zENsbits, zENsbitsI, sigmadelta, zbinrouteSRbits, zwiardnotinvbits, zwiardnotinvbitsL, zsuccbitsI_noshiftd, zSRNbits, zsprobbits, zcountbits, zcountbitsI}; // 31!! 2x spdfrac and spdfracend for interpoll //  checked for depths and tested 6/2

uint32_t (*speedfromnostrobe_noIN[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfracend, spdfracend, spdfrac2, spdfrac3, spdfrac4, spdfrac5, zprobbits, zTMsimplebitsL, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI, zENsbits, zENsbitsI, sigmadelta, zbinrouteSRbits, zwiardnotinvbitsL, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbits_noshiftd, zsuccbitsIpp, zsuccbitsI_noshiftd, zSRNbits, zsprobbits, zcountbits, zcountbitsI, spdfrac};

uint32_t interpfromnostrobe[32]={1,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}; // TODO match with speedfromnostrobe

uint32_t speednoin[36]={0,0,0,0, 1,1,1,1, 1,1,1,0, 0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0}; // in the above which ones use IN -> dacfrom

uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift}; 

uint32_t (*speedfromcvforxor[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbits, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zcompbits, zosc1bits, sigmadelta, cipher, spdvienna, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, spdfrac2, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbits, zTMsimplebits};// no strobes, no routes and only CV ones... doubled up

// DEP
uint32_t (*speedfromstrobe[16])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, strobespdfrac, ztogglebits, ztogglebitssh, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift};

uint32_t usedstrobe[32]={0,1,0,0, 1,1,1,1, 1,0,0,0, 0,0,0,0, 0,1,0,0, 1,1,1,1, 1,0,0,0, 0,0,0,0}; // for strobes - 1 if they use depth... // doubled

// new
uint32_t (*speedfromstrobe_depth[16])(uint32_t depth, uint32_t in, uint32_t wh)={strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle}; // 6  add xor with speed = where was? as insides?

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

//#include "bitsn.h" // for bits and routes

#include "newbits.h" // for bits and routes

// 4. probs
/*

probf_anystrobe_depth
probf_anystrobe_nodepth

probf_nostrobe_depth

 */

uint32_t (*probf_anystrobe_depth[64])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdvienna, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, ztogglebits, ztogglebitssh, zbinroutebits_noshiftd, zbinroutebits_noshift_transitd, zbinroutebitsI_noshiftd, zbinrouteSRbitsd, zsuccbitsI_noshiftd, zsuccbits_noshiftd, /**/zinvprobbits, zprobbits, zsprobbits, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta};//41 _.63
// use IN: spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, compbits, spdvienna

uint32_t (*probf_anystrobe_depth_noin[32])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zownprobbits, zownGprobbits, spdfrac, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, sigmadelta, spdvienna, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, ztogglebits, ztogglebitssh, zbinroutebits_noshiftd, zbinrouteSRbitsd, zsuccbitsI_noshiftd}; // 35 -3

uint32_t (*probf_anystrobe_nodepth[16])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, strobe, ztogglebitsnod, ztogglebitsshnod, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift}; // >>8

uint32_t (*probf_nostrobe_depth[33])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdvienna, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, zbinroutebits_noshiftd, zbinroutebits_noshift_transitd, zbinroutebitsI_noshiftd, zbinrouteSRbitsd, zsuccbitsI_noshiftd, zsuccbits_noshiftd}; // 33

// maybe ignore
uint32_t (*probf_nostrobe_nodepth[10])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbits, zsuccbitsI, zsuccbits_noshiftnod, zsuccbitsI_noshiftnod}; // 10
										
//////// ignore below...

// redo non depth -> nod//DONE 31/1/2023 with extra shifters
uint32_t (*probfstrobes_nodepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebitsnod, ztogglebitsshnod, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, strobezsuccbits_shift, strobezsuccbitsI_shift, strzbinroutfixed_shift_transit, strzbinroutfixed_shift_transitI, strzbinroutfixed_shift, strzbinroutfixedI_shift, strobe, ztogglebitsnod, ztogglebitsshnod, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, strobezsuccbits_shift, strobezsuccbitsI_shift, strzbinroutfixed_shift_transit, strzbinroutfixed_shift_transitI, strzbinroutfixed_shift, strzbinroutfixedI_shift}; // new one doubled up

// with depths - unused so far - check
uint32_t (*probfstrobesdepth[7])(uint32_t depth, uint32_t in, uint32_t wh)={zsprobbits, strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle}; 


// all use depth/no strobe some use IN - see below - check as matches nodepth
//DEP
uint32_t (*probfsins[32])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits}; // all use depth // updated with speed // no strobes = // which of probfsins use IN: spdfrac2,3,4,spdfracdac3, zosc2bitsI, compbits, spdvienna - always set an IN// CHECK TODO

// DEP
uint32_t (*probfsin_nodepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zbinrouteSRbits, zjusttail, zsuccbitsI_noshift, zsuccbits_noshift, zjustcycle, Zzsuccbits, ZzsuccbitsI, Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, ZpSRsigma, zbinroutorgap, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pSRN8, pSRN7, pSRN6, pSRN5, pSR_routeSRbits02, pSR_routeSRbits01}; 

uint32_t (*probfsinsstrobed[39])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits,  strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle}; // all use depth // updated with speed // added strobes with depth

// which of probfsins use IN: spdfrac2,3,4,spdfracdac3, zosc2bitsI, compbits, spdvienna - always set an IN// CHECK TODO - CVL[11]

// this is for final 4 in geoC - no INs and use depth for route so maybe re-make some... can also be used further...
uint32_t (*probfdepthnoin[32])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zbinroutebits_noshiftd, zbinroutebits_noshift_transitd, zbinroutebitsI_noshiftd, zownprobbits, zownGprobbits, spdfrac, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, sigmadelta, zbinrouteSRbitsd, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshiftd, zsuccbits_noshiftd, zSRNbits,  strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, zprobbits}; // all use depth // updated with speed // added strobes with depth

//how we can mix prob from strobes/no depth with prob which uses depth ??? what to use optional depth as/// length? do as 64=
uint32_t (*probfsinsstrobeall[64])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zsprobbits, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits,  strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, zsprobbits, strobespdfrac,  strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixedI_noshift, strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift};

uint32_t unuseddepth[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1,1,1,1, 1,1,1,1,  1,1,1,1,  1,1,1,1,  1,1,1,1,  1,1,1}; 

uint32_t (*probfsinnostrobe[33])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zownprobbits, zownGprobbits, spdfrac, spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc2bitsI, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdvienna, zbinrouteSRbits, zwiardinvbits, zjusttailwithdepth, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits}; // all use depth // updated with speed

// from routes: pull out ones which could be used for prob - even though have shift// or we can remove shift:

// strobes above: zbinroutebitscyclestrIRS, pSRxorroutesSR, pSRaddroutesSR, pSRGswopSR, pSRDACroutestrobeSR, pSRN40RS, pSRN36RS, pSRN33cipherRS, pSRN33RS, pprobtoggle1RS, pprobtoggleRS, pprobtoggle3RS, pprobtoggle4RS, pprobtoggleRS, pprobstrobe1RS, pprobstrobe2RS, pprobstrobe3RS, pSRN8RS, pSRN7RS, pSRN6RS, pSRN5RS [21]

//uint32_t (*probfstrobes[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift,  strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, strobe, ztogglebits, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift}; // doubled

// 5. tails
void (*dotail[32])(void)= {fliptail, basictail, succtail, succtailback, tailC, tailL, tailR, tailN, basictailnos, succtailnos, succtailbacknos, tailCnos, tailLnos, tailRnos, tailNnos, basictailinv, succtailinv, succtailbackinv, tailCinv, tailLinv, tailRinv, tailNinv, basictailnosinv, succtailnosinv, succtailbacknosinv, tailCnosinv, tailLnosinv, tailRnosinv, tailNnosinv, tailXOR0, tailXOR1, tailOR}; // 1 is basictail. default

// 6. global opps - add those which operate on various global flags, and orderings (we have no?)
void (*globalls[20])(uint32_t depth)={resett, binaryN, binaryX, SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalbumpspd, SRRglobalbumpcv, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalsync, SRRglobalorder, SRRglobalbumpbit0, SRRglobalbumpbit1, SRRglobalbumpbit2, SRRglobalorderbumpS, SRRglobalorderbumpbit, SRRglobaltailset}; 
