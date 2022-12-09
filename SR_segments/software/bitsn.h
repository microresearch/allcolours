// strobe/no strobe
// depth/no depth
// routed/abstract

// to include: zwiardbits2I, zwiardbitsI, zwiardinvbitsI (depth and in) and check....

/*

abstract: strobe/depth, no strobe/depth, strobe/no depth, no strobe/no depth, 
routed: strobe/depth, no strobe/depth, strobe/no depth, no strobe/no depth, 

// if we use strobe for speed we don't want it for bits, otherwise we dont care... hence just nostrobe

 */

/*

list arrays here:

bitfromalldepth
bitfromnostrobenodepth
bitfromnostrobe
bitfromnostrobedepth

abstractbits
abstractbitsnostrobe

routebits
routebitsd
routebitsnod
routebitsnostrobenod
routebitsnostrobe
routebitsnostrobedepth
routebitsfortypes
routebitsfixeddepth
routebitsnostrobedepthprob

bitfromsdR

expetcbits
expetcbits_nostrobe

 */

uint32_t (*bitfromalldepth[78])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutor, binroutAND0, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbitspp, zsuccbitsIpp, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4,  viennabits, zcopyGSR, zcopyGSR_s, ztogglebitssh, ztogglebits, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitswithd, tailbitsIwithd, tailbitswithdnos, tailbitsIwithdnos, binroutesel1, binroutesel2, binroutesel3, binroutesel4, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3}; // too big but do we need to cut?

uint32_t (*bitfromnostrobenodepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed, zjustcycle, zsuccbits, zsuccbitsI, zllfsrbits, tailbits, tailbitsInos, tailbitsnos, tailbitsI, flipflop, flipflopandroute, flipflopI, zjusttail, binroutfixedmy, binroutmybumpS, binroutmycv, binroutmybumpbit, binroutmybumpbitt, binroutesel0S, binroutesel4S, pSRshare, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSR32, pSRmod, pSRN62, pSRN22, pSRN21, pSRNwas15, pSRR32}; 

uint32_t (*bitfromnostrobe[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutor, binroutAND0, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zosc1bits, sigmadelta, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zprobbits, zsuccbits, zsuccbitspp, zsuccbitsI, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4,  viennabits, tailbits, flipflop, flipflopandroute, flipflopI, zjusttail, zcopyGSR, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, pSRLcvroute, pSR_routeSRbits01,  pSR_routeSRbits02}; 

uint32_t (*bitfromnostrobedepth[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutor, binroutAND0, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zosc1bits, sigmadelta, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbitspp, zsuccbitsIpp, zprobbits, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zlfsrbits, zflipbits, zflipbitsI, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4,  viennabits, zcopyGSR, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, flipflopandroute, pSRLcvroute, pSR_routeSRbits01,  pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRxorSR, pbitLcvsrroute}; 

// how get more abstracts??? patternbits uses IN!
uint32_t (*abstractbits[24])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, cipher, osceq, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits}; // includes some strobes

uint32_t (*abstractbitsnostrobe[18])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, cipher, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI}; 

uint32_t (*routebits[74])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutor, binroutAND0, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbits, zsuccbitspp, zsuccbitsI, zsuccbitsIpp, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4,  viennabits, tailbits, flipflopandroute, zjusttail, zcopyGSR, zcopyGSR_s, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitsnos, tailbitsI, tailbitswithd, tailbitsIwithd, tailbitsInos, tailbitswithdnos, tailbitsIwithdnos, binroutesel0, binroutesel1, binroutesel2, binroutesel3, binroutesel4, binroutfixedmy, binroutfixedmyreset, binroutmybumpS, binroutmycv, binroutmybumpbit, binroutmybumpbitt, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3}; // how to get down to 64!? -> remove those with no depth - keep special case for fixed one...how? just as fixed in inners in geoC-> binroutfixed

uint32_t (*routebitsd[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutor, binroutAND0, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbitspp, zsuccbitsIpp, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, viennabits, flipflopandroute, zcopyGSR, zcopyGSR_s, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitswithd, tailbitsIwithd, tailbitswithdnos, tailbitsIwithdnos, binroutesel1, binroutesel2, binroutesel3, binroutesel4, binroutmybumpS, binroutmycv, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, pSRLcvroute, pSR_routeSRbits01,  pSR_routeSRbits02, pSR_layer1}; 

// no depth - but can we have strobe? why not
uint32_t (*routebitsnod[32])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed, zjustcycle, zsuccbits, zsuccbitsI, tailbits, zjusttail, tailbitsnos, tailbitsI, tailbitsInos, binroutesel0, binroutfixedmy, binroutfixedmyreset, binroutmybumpbit, binroutmybumpbitt, binroutmybumpS, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSR32, pSRmod, pSRN62, pSRN22, pSRN21, pSRNwas15, pSRRaccelghosts0, pSRR32, pSRaddroutes, pSRxorroutes, pSRshroute, pSRsigma, pSRDACroutestrobe};

// what are route bits which do use strobe? zbinroutebitscyclestr, zbinroutebitscyclestr_noshift, zbinroutebitscyclestrI, binroutmybumpS, zcopyGSR_s, binroutaltreset, pSRDACroutestrobe

uint32_t (*routebitsnostrobenod[32])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed, zjustcycle, zsuccbits, zsuccbitsI, tailbits, zjusttail, tailbitsnos, tailbitsI, tailbitsInos, binroutesel0, binroutfixedmy, binroutfixedmyreset, binroutmybumpbit, binroutmybumpbitt, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSR32, pSRmod, pSRN62, pSRN22, pSRN21, pSRNwas15, pSRRaccelghosts0, pSRR32, pSRaddroutes, pSRxorroutes, pSRshroute, pSRsigma, binroutfixed, zjustcycle};

uint32_t (*routebitsnostrobe[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutor, binroutAND0, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbits, zsuccbitspp, zsuccbitsIpp, zsuccbitsI, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, viennabits, tailbits, flipflopandroute, zjusttail, zcopyGSR, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitsnos, tailbitsI, tailbitswithd, tailbitsIwithd, tailbitsInos, tailbitswithdnos, tailbitsIwithdnos, binroutesel0S, binroutesel1S, binroutesel2S, binroutesel3S, binroutesel4S, binroutfixedmy, binroutfixedmyreset, binroutmycv, binroutmybumpbit, binroutmybumpbitt, binroutAND0, binroutAND00, binroutAND1, binroutAND11};

uint32_t (*routebitsnostrobedepth[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutor, binroutAND0, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbitspp, zsuccbitsIpp, zsuccbitsprob, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, viennabits, zcopyGSR, zbinroutfixed_noshift_transitI, tailbitswithd, tailbitsIwithd, tailbitswithdnos, tailbitsIwithdnos, binroutmycv, binroutesel1, binroutesel2, binroutesel3, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, pSRLcvroute, pSR_routeSRbits01,  pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRxorSR, pbitLcvsrroute, pSRLcvSRmaskroute};

// simpler range which can have types... binrout already has sel1 - re-check in as type!
uint32_t (*routebitsfortypes[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zzwiardbits, Zzwiardinvbits, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinrout_probXY, Zbinrout_probXY1, Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zzwiardbits, Zzwiardinvbits, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinrout_probXY, Zbinrout_probXY1};
// note that only first 4 use depth as route, rest either have single routes or do prob - these probs DO NOT use IN [5] as we use that for type!
// Zsuccbits and ZsuccbitsI don't use depth! so we removed...

// depth/routes which could be passed fixed depth:
uint32_t (*routebitsfixeddepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, binroutesel1, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, pSR_routeSRbits01,  pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSRLLbumproute, pSR_recbin, binrout, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle}; // some have strobe - some doubled

// vs IN!
uint32_t (*routebitsnostrobedepthprob[32])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed_prob1, zsuccbitspp, zsuccbitsIpp, zsuccbitsprob, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, binroutfixed_prob1, zsuccbitspp, zsuccbitsIpp, zsuccbitsprob, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3}; // doubled up for safety

//////////////////////////////////////////
// global set businessDONE GLOBALONEs use only this - build up to 32 with selectglob as last...
uint32_t (*bitfromsdR[32])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutor, binroutAND0, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zprobbits, zonebits, zSRNbits, zSRLbits, zSRCbits, zSRRbits, selectglob};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// classify these for strobe, depth - see below... we don't use them in geoC, but in L, R
uint32_t (*expetcbits[64])(uint32_t depth, uint32_t in, uint32_t wh)={pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRhold, pSRholdfromdac, pSRxorSR, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortog, pSRprobxortogxI, pSRprobxortogI, pSRmatch, pSRshare, pSRGswop, pSRshroute, pbitSRroutelog, pbitSRroutelogxx, pbitLcvsrroute, pbitSRroutelogxxx, pbitLSRroutexxxlog, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pstream, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRmod, pSRNwas13, pSRN65, pSRN62, pSRLLswop, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN30, pSRN22, pSRN21, pSRN15, pSRN12, pSRN11, pSRN10, pSRN8, pSRN7, pSRN6, pSRN5, pSRNwas15, pSRRLLswop, pSRRaccelghosts0, pSRRbumproute0, pSRR32, pSRN13, pSRN30, pbitSRroutedoit, pSRN15}; // from exp_port including exp, bit, prob, L, and R 

// no strobes:
uint32_t (*expetcbits_nostrobe[32])(uint32_t depth, uint32_t in, uint32_t wh)={pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRhold, pSRholdfromdac, pSRxorSR, pSRmatch, pSRshare, pbitSRroutelog, pbitSRroutelogxx, pbitLcvsrroute, pbitSRroutelogxxx, pbitLSRroutexxxlog, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pstream, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRmod, pSRN62, pSRN22, pSRN21, pSRN15, pSRNwas15, pSRRaccelghosts0, pSRR32}; 

// 32.33???35

// exp_port: nearly all are routey ones:
// depth is almost route: pSRLcvroute, pSR_routeSRbits01,  pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRxorSR, pbitLcvsrroute, pSRLcvSRmaskroute

// other routey: pSRhold, pSRholdfromdac, pSRmatch, pbitSRroutedoit, pSRN13
// other routey/strobe: pSRprobxortogx(str), pSRprobxortog, pSRprobxortogxI, pSRprobxortogI, pSRLLbumproute
// nod, strobe: pSRaddroutes, pSRxorroutes, pSRshroute, pSRsigma, pSRDACroutestrobe, pSRbumproute, pSRNwas13, pSRN65, pSRLLswop, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN12, pSRN11, pSRN10, pSRRLLswop, pSRRbumproute0, 
// nod, no strobe: pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSR32**, pSRmod, pSRN62, pSRN22, pSRN21, pSRNwas15, pSRRaccelghosts0, pSRR32

// others still have some route: pSRshare, pSRGswop?strobe, pstream


/// pSRBITMIX uses depth and in so where to place this???? leave prob and rest for now

// abstracts: pSRprobxortog, pSRprobxortogI (use strobe)
