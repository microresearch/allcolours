// depth/no depth has changed... some also use IN (eg. binroutfixed_prob1, 2 etc)

// strobe/no strobe depth/no depth routed/abstract

/*

abstract: strobe/depth, no strobe/depth, strobe/no depth, no strobe/no depth, routed: strobe/depth, no strobe/depth, strobe/no depth, no strobe/no depth,

// if we use strobe for speed we don't want it for bits, otherwise we dont care... hence just nostrobe

 */

/*

list arrays here:

bitfromalldepth bitfromnostrobenodepth bitfromnostrobe bitfromnostrobedepth

abstractbits abstractbitsnostrobe

routebits routebitsd routebitsnod routebitsnostrobenod routebitsnostrobe routebitsnostrobedepth routebitsfortypes routebitsfixeddepth routebitsnostrobedepthprob

bitfromsdR

expetcbits expetcbits_nostrobe

 */

/*
// bitfromalldepth: these are routes and bits which can't use types [47]:

zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zosc1bits, sigmadelta, cipher, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zreturnbits, zreturnnotbits, zTMsimplebits, zonebits, zlfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zcopyGSR, zcopyGSR_s, ztogglebitssh, ztogglebits, zbinroutfixed_noshift_transitI, tailbitswithd, tailbitsIwithd, tailbitswithdnos, tailbitsIwithdnos, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, binrout_probXY2, binrout_probXY3

and from nodepth:

zjustcycle, zllfsrbits, tailbitsInos, tailbitsnos, tailbitsI, flipflop, flipflopI, zjusttail,

fixed for types: zbinroutfixedmy, zbinroutmybumpS, zbinroutmybumpbit, zbinroutmybumpbitt,

REWORK from exp_port!

uint32_t (*expetcbits[64])(uint32_t depth, uint32_t in, uint32_t wh)={pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRhold, pSRholdfromdac, pSRxorSR, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortog, pSRprobxortogxI, pSRprobxortogI, pSRmatch, pSRshare, pSRGswop, pSRshroute, pbitSRroutelog, pbitSRroutelogxx, pbitLcvsrroute, pbitSRroutelogxxx, pbitLSRroutexxxlog, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pstream, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRmod, pSRNwas13, pSRN65, pSRN62, pSRLLswop, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN30, pSRN22, pSRN21, pSRN15, pSRN12, pSRN11, pSRN10, pSRN8, pSRN7, pSRN6, pSRN5, pSRNwas15, pSRRLLswop, pSRRaccelghosts0, pSRRbumproute0, pSRR32, pSRN13, pSRN30, pbitSRroutedoit, pSRN15}; // from exp_port including exp, bit, prob, L, and R


*/

/////////////////

uint32_t (*bitfromalldepth[82])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutI, binroutor, binroutAND0, binroutorg, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbitspp, zsuccbitsIpp, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zwiardbits2I, zwiardbitsI, zwiardinvbitsI, zTMsimplebits, zonebits, zlfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, viennabits, zcopyGSR, zcopyGSR_s, ztogglebitssh, ztogglebits, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitswithd, tailbitsIwithd, tailbitswithdnos, tailbitsIwithdnos, binroutesel1, binroutesel2, binroutesel3, binroutesel4, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3}; // too big but do we need to cut?

uint32_t (*bitfromnostrobenodepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed, zjustcycle, binroutorgap, zsuccbits, zsuccbitsI, zllfsrbits, tailbitsInos, tailbitsnos, tailbitsI, flipflop, flipflopandroute, flipflopI, zjusttail, zbinroutfixedmy, zbinroutmybumpS, zbinroutmybumpbit, zbinroutmybumpbitt, binroutesel0S, binroutesel4S, pSRshare, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSR32, pSRmod, pSRN62, pSRN22, pSRN21, pSRNwas15, pSRR32};

uint32_t (*bitfromnostrobe[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutI, binroutor, binroutAND0, zjustcycle, binroutorg, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zosc1bits, sigmadelta, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zprobbits, zsuccbits, zsuccbitspp, zsuccbitsI, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, viennabits, flipflop, flipflopandroute, flipflopI, zcopyGSR, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, pSRLcvroute, pSR_routeSRbits01, pSR_routeSRbits02};

uint32_t (*bitfromnostrobedepth[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutI, binroutor, binroutAND0, binroutorg, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zosc1bits, sigmadelta, osceq, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbitspp, zsuccbitsIpp, zprobbits, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, zlfsrbits, zflipbits, zflipbitsI, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, viennabits, zcopyGSR, binrout_probXY, binrout_probXY1, flipflopandroute, pSRLcvroute, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRxorSR, pbitLcvsrroute};

// how get more abstracts??? patternbits uses IN!
uint32_t (*abstractbits[24])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, cipher, osceq, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits}; // includes some strobes

uint32_t (*abstractbitsnostrobe[18])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, cipher, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI};

//////////////////////////////////////////////////////////////////////////////////////////////////////////// ROUTEBITS

// routes which take fixed as in global and use depth/ no depth ???new ones which could take myroute which is set elsewhere

// all
uint32_t (*routebits[79])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutI, binroutor, binroutAND0, binroutorg, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbits, zsuccbitspp, zsuccbitsI, zsuccbitsIpp, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zwiardbits2I, zwiardbitsI, zwiardinvbitsI, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, viennabits, tailbits, flipflopandroute, zjusttail, zcopyGSR, zcopyGSR_s, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitsnos, tailbitsI, tailbitswithd, tailbitsIwithd, tailbitsInos, tailbitswithdnos, tailbitsIwithdnos, binroutesel0, binroutesel1, binroutesel2, binroutesel3, binroutesel4, zbinroutfixedmy, zbinroutfixedmyreset, zbinroutmybumpS, zbinroutmycv, zbinroutmybumpbit, zbinroutmybumpbitt, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3}; // how to get down to 64!? -> remove those with no depth - keep special case for fixed one...how? just as fixed in inners in geoC-> binroutfixed

uint32_t (*routebitsd[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutI, binroutor, binroutorg, binroutAND0, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbitspp, zsuccbitsIpp, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, viennabits, flipflopandroute, zcopyGSR, zcopyGSR_s, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitsIwithd, tailbitswithdnos, binroutesel1, binroutesel2, binroutesel3, binroutesel4, zbinroutmybumpS, zbinroutmycv, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binroutaltreset, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, pSRLcvroute, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1};

// no depth - but can we have strobe? why not
uint32_t (*routebitsnod[32])(uint32_t depth, uint32_t in, uint32_t wh)={zjustcycle, binroutfixed, zsuccbits, zsuccbitsI, tailbits, zjusttail, tailbitsnos, tailbitsI, tailbitsInos, binroutesel0, zbinroutfixedmy, zbinroutfixedmyreset, zbinroutmybumpbit, zbinroutmybumpbitt, zbinroutmybumpS, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSR32, pSRmod, pSRN62, pSRN22, pSRN21, pSRNwas15, pSRRaccelghosts0, pSRR32, pSRaddroutes, pSRxorroutes, pSRshroute, pSRsigma, pSRDACroutestrobe};

// what are route bits which do use strobe? zbinroutebitscyclestr, zbinroutebitscyclestr_noshift, zbinroutebitscyclestrI, binroutmybumpS, zcopyGSR_s, binroutaltreset, pSRDACroutestrobe

uint32_t (*routebitsnostrobenod[32])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed, zjustcycle, binroutorgap, zsuccbits, zsuccbitsI, tailbits, zjusttail, tailbitsnos, tailbitsI, tailbitsInos, binroutesel0, zbinroutfixedmy, zbinroutfixedmyreset, zbinroutmybumpbit, zbinroutmybumpbitt, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSR32, pSRmod, pSRN62, pSRN22, pSRN21, pSRNwas15, pSRRaccelghosts0, pSRR32, pSRaddroutes, pSRxorroutes, pSRshroute, pSRsigma, binroutfixed};

uint32_t (*routebitsnostrobe[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutI, binroutor, binroutorg, binroutAND0, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbits, zsuccbitspp, zsuccbitsIpp, zsuccbitsI, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, viennabits, flipflopandroute, zjusttail, zcopyGSR, zsuccbitsprob, zbinroutfixed_noshift_transitI, tailbitsnos, tailbitsI, tailbitsIwithd, tailbitsInos, tailbitswithdnos, tailbitsIwithdnos, binroutesel0S, binroutesel1S, binroutesel2S, binroutesel3S, binroutesel4S, zbinroutfixedmy, zbinroutfixedmyreset, zbinroutmycv, zbinroutmybumpbit, zbinroutmybumpbitt, binroutAND0, binroutAND00, binroutAND1, binroutAND11};

uint32_t (*routebitsnostrobedepth[64])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutI, binroutor, binroutorg, binroutAND0, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zsuccbitspp, zsuccbitsIpp, zsuccbitsprob, zreturnbits, zreturnnotbits, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, viennabits, zcopyGSR, zbinroutfixed_noshift_transitI, tailbitsIwithd, tailbitswithdnos, zbinroutmycv, binroutesel1, binroutesel2, binroutesel3, binroutAND0, binroutAND00, binroutAND1, binroutAND11, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, pSRLcvroute, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRxorSR, pbitLcvsrroute, pSRLcvSRmaskroute};

// NO LONGER_depth/routes which could be passed fixed depth for route: well binroutorg uses depth
uint32_t (*routebitsfixeddepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutI, binroutorg, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, binroutesel1, binroutAND0, binroutAND00, binroutaltreset, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSRLLbumproute, pSR_recbin, binrout, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscycle_noshift}; // some have strobe - some doubled // some fixed as ere no depth // none accepts depth as all now ROUTE

// vs IN!
uint32_t (*routebitsnostrobedepthprob[32])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed_prob1, zsuccbitspp, zsuccbitsIpp, zsuccbitsprob, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, binrout_probXY, binrout_probXY1, binrout_probXY2, binrout_probXY3, binroutfixed_prob1, zsuccbitspp, zsuccbitsIpp, zsuccbitsprob, zwiardbits, zwiardinvbits, zTMsimplebits, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, binroutfixed_prob5, binrout_probXY, binrout_probXY1}; // doubled up for safety


//////////////////////////////////////////////////// FOR TYPES

// new ones for extra matrix route // and type in some cases - check - how types and this differ??? not all have types
uint32_t (*routebitsnodepthmatrix[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, binrout, binroutI, ZzbinrouteINVbits, Zzbinroutebitscycle, binroutAND0, binroutAND00, binroutesel1, binroutesel1S, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, ZzbinroutebitscyclestrI, flipflopandroute, Zflipflopandroute, routevalue, zbinrouteORbits, binroutaltreset, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect};// can also add pSR_altbin1, pSRLLbumproute, pSR_recbin, and zbinroutfixed, zbinroutorg, zbinroutorgap

uint32_t (*routebitsfortypes[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, zbinroutfixed, zbinroutorg, zbinroutorgap, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zzwiardbits, Zzwiardinvbits, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, NZzwiardbits, NZzwiardinvbits, zzwiardbits2I, zzwiardbitsI}; // can be added: zzwiardinvbitsI, zzsuccbitsprob, zbinroutfixedfixed, zzsingleroutebits, zbinroutfixed_prob1R, zbinroutfixed_prob1L
// note that only first 7 use depth as route except or, rest either have single routes (the route or global) or do prob - these probs DO NOT use IN [5] as we use that for type! but we change soon type to be locally set... not set by IN -> but also repeats

uint32_t setroute[32]={0,1,1,0,1, 0,0,0,0,0, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1}; // new array if we need to set route above/// also means no depth
// - if 0 we set route

// all of first 7 - use new matrix below: ZbinroutX, Zbinroutor, ZzbinrouteINVbitsX, ZzbinroutebitscycleX, zbinroutebitscyclestrIX, ZflipflopandrouteX, ZpSRsigmaX

uint32_t (*routebitsfortypesdepth[27])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zzwiardbits, Zzwiardinvbits, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, NZzwiardbits, NZzwiardinvbits}; // as above with no doublings

uint32_t (*routebitsfortypesdepthnoroute[20])(uint32_t depth, uint32_t in, uint32_t wh)={Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zzwiardbits, Zzwiardinvbits, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, NZzwiardbits, NZzwiardinvbits}; // all have fixed routes global or otherwise

//ignore//uint32_t (*routebitsfortypesnodepth[7])(uint32_t depth, uint32_t in, uint32_t wh)={binroutesel2, binroutesel3, Zzsuccbits, ZzsuccbitsI, NZzbinrouteINVbits, NZzbinroutebitscycle, NZflipflopandroute};

// includes last no depths
uint32_t (*routebitsfortypesALL[34])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zzwiardbits, Zzwiardinvbits, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, NZzwiardbits, NZzwiardinvbits, binroutesel2, binroutesel3, Zzsuccbits, ZzsuccbitsI, NZzbinrouteINVbits, NZzbinroutebitscycle, NZflipflopandroute};

// compile list of routebitsfortypes which can be passed depth as route NO!
uint32_t (*routebitsfortypesfixeddepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, Zzsuccbitspp, ZzbinroutebitscyclestrI, ZpSRsigma, Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, Zzsuccbitspp, ZpSRsigma, Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, Zzsuccbitspp, Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, Zzsuccbitspp, ZzbinroutebitscyclestrI, Zbinrout, ZpSRsigma, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, Zzsuccbitspp, ZzbinroutebitscyclestrI, ZpSRsigma}; // all multiplied as there are only 7

//////////////////////////////////////////
// global set businessDONE GLOBALONEs use only this - build up to 32 with selectglob as last... line up with others TODO
uint32_t (*bitfromsdR[32])(uint32_t depth, uint32_t in, uint32_t wh)={binrout, binroutfixed, binroutI, binroutor, binroutAND0, zjustcycle, binroutfixed_prob1, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zprobbits, zonebits, zSRNbits, zSRLbits, zSRCbits, zSRRbits, selectglob};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// classify these for strobe, depth - see below... we don't use them in geoC, but in L, R
uint32_t (*expetcbits[64])(uint32_t depth, uint32_t in, uint32_t wh)={pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRhold, pSRholdfromdac, pSRxorSR, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortog, pSRprobxortogxI, pSRprobxortogI, pSRmatch, pSRshare, pSRGswop, pSRshroute, pbitSRroutelog, pbitSRroutelogxx, pbitLcvsrroute, pbitSRroutelogxxx, pbitLSRroutexxxlog, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pstream, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRmod, pSRNwas13, pSRN65, pSRN62, pSRLLswop, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN30, pSRN22, pSRN21, pSRN15, pSRN12, pSRN11, pSRN10, pSRN8, pSRN7, pSRN6, pSRN5, pSRNwas15, pSRRLLswop, pSRRaccelghosts0, pSRRbumproute0, pSRR32, pSRN13, pSRN30, pbitSRroutedoit, pSRN15}; // from exp_port including exp, bit, prob, L, and R

// fixing/adding from exp_port now with types and global/local/route // some set routes:
uint32_t (*zexpetcbits[41])(uint32_t depth, uint32_t in, uint32_t wh)={pSR_recbin, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortogxI, pSRmatch, pSRshare, pSRGswop, pSRsigma, pbitLcvsrroute, pstream, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN13, pSRRLLswop, pSRRbumproute0, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN15, pSRN8, pSRN7, pSRN6, pSRN5, pSRxorSR, pbitSRroutedoit, pSR_routeSRbits02, pSR_routeSRbits01}; // recommmend: pSRRbumproute0(20), 


/*so from above what we have with no types is: (and we default to global/local routes:

pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSRhold, pSRholdfromdac, pSRshroute, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRmod, pSRNwas13, pSRN65, pSRN62, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN30, pSRN22, pSRN21, pSRN15, pSRN12, pSRN11, pSRN10, pSRNwas15, pSRRLLswop, pSRRaccelghosts0, pSRR32, pSRN13, pSRN30};

 */

// no strobes:
uint32_t (*expetcbits_nostrobe[32])(uint32_t depth, uint32_t in, uint32_t wh)={pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRhold, pSRholdfromdac, pSRxorSR, pSRmatch, pSRshare, pbitSRroutelog, pbitSRroutelogxx, pbitLcvsrroute, pbitSRroutelogxxx, pbitLSRroutexxxlog, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pstream, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRmod, pSRN62, pSRN22, pSRN21, pSRN15, pSRNwas15, pSRRaccelghosts0, pSRR32};

// 32.33???35

// exp_port: nearly all are routey ones: depth is almost route: pSRLcvroute, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSR_recbin, pSRxorSR, pbitLcvsrroute, pSRLcvSRmaskroute

// other routey: pSRhold, pSRholdfromdac, pSRmatch, pbitSRroutedoit, pSRN13 other routey/strobe: pSRprobxortogx(str), pSRprobxortog, pSRprobxortogxI, pSRprobxortogI, pSRLLbumproute nod, strobe: pSRaddroutes, pSRxorroutes, pSRshroute, pSRsigma, pSRDACroutestrobe, pSRbumproute, pSRNwas13, pSRN65, pSRLLswop, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN12, pSRN11, pSRN10, pSRRLLswop, pSRRbumproute0, nod, no strobe: pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSR32**, pSRmod, pSRN62, pSRN22, pSRN21, pSRNwas15, pSRRaccelghosts0, pSRR32

// others still have some route: pSRshare, pSRGswop?strobe, pstream


/// pSRBITMIX uses depth and in so where to place this???? leave prob and rest for now

// abstracts: pSRprobxortog, pSRprobxortogI (use strobe)
