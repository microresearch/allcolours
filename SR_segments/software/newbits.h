// new arrays of bit functions:
// + routes:  match array of a 1 to signal depth, else set route. not obv. for abstractbits

// routebits/allstrobe/types
// ignore this one - but is only one we use so far - use for fixed stuff ok
uint32_t (*routebits_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycv, zbinroutorgap, zzsingleroutebits,  zbinroutmybumpSalt, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortogxID_, pSRmatch, pSRshare, pSRGswop, pbitLcvsrroute, pstream, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN13, pSRRLLswop, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN15, pSRN8, pSRN7, pSRN6, pSRN5, pSRxorSR, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, /**/ Zbinrout, Zbinroutor, Zbinrout_strip}; 

uint32_t depth_routebits_typesz[64]={0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1}; // IF WE USE: re-check if we use it... and exp_port we now remove depths mark as D_ DONE but not in above

// for depth array above
//  ZbinroutR, ZbinroutorD, ZzbinrouteINVbitsR, ZzbinroutebitscycleR, zbinroutebitscyclestrIRS, ZflipflopandrouteR, ZpSRsigmaR, ZviennabitsD, ZzsuccbitsppD, ZzsuccbitsIppD, NZbinrout_probXYD, NZbinrout_probXY1D, NZbinroutfixed_prob1D, NZbinroutfixed_prob2D, NZbinroutfixed_prob3D, NZbinroutfixed_prob4D, zbinroutmycvD, zbinroutorgapD, zzsingleroutebitsD, zbinroutmybumpS/R, zbinroutmybumpbitR, zbinroutmybumpbittR, pSR_recbinR, pSRxorroutesSR, pSRaddroutesSR, pSRprobxortogxDS, pSRprobxortogxIDS, pSRmatchD, pSRshareR, pSRGswopSR, pbitLcvsrrouteD, pstreamD, pSRDACroutestrobeSR, pSRLLbumprouteDS, pSRbumprouteDS, pSRN40RS, pSRN36RS, pSRN33cipherRS, pSRN33RS, pSRN13D, pSRRLLswopDS, pprobintprob3D, pprobintprob5_0D, pprobintprob6_0D, pprobtoggle1RS, pprobtoggle2RS, pprobtoggle3RS, pprobtoggle4RS, pprobtoggle5RS, pprobstrobe1RS, pprobstrobe2RS, pprobstrobe3RS, pSRN15D, pSRN8RS, pSRN7RS, pSRN6RS, pSRN5RS, pSRxorSRD, pSR_routeSRbits02R, pSR_routeSRbits01R, pSRRaccelghosts0R, ZbinroutR, ZbinroutorD, Zbinrout_stripR // 64

// join the nodepth and depth we have below for: // check types in all: remove no types: pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_, pbitSRroutelogD_, pbitSRroutelogxxD_, pbitSRroutelogxxxD_, pSR32D_, pSRN22D_, pSRN21D_, pSRR32D_
// DEP
uint32_t (*routebits_typeszz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits, pSRmatch, pbitLcvsrroute, pstream, pSRLLbumproute, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, ZzsuccbitsIpp, Zzsuccbitspp, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pbitSRroutedoitD_, pSRbumprouteD_, pSRLLswopD_, /* */ Zbinrout_strip, Zbinroutor}; // first 24 have depth, rest not! - check depth/nodepth doubles
// but is 9 too long?

// 1/2 non-depth - fixed route now - checked no depth/depth 2/2
uint32_t (*routebits_nodepth_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, ZzbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pbitSRroutedoitD_, pSRbumprouteD_, pSRLLswopD_, /* */ Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, ZzbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4}; // 39 double 64 >>6 extent

uint32_t depth_routebits_nodepth_typesz[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 

// 1/2 pull out those with depth now... but no bumps except cv, and no poorly added depths - checked 2/2 
uint32_t (*routebits_depth_typesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits, pSRmatch, pbitLcvsrroute, pstream, pSRLLbumproute, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, Zbinrout_strip, ZzsuccbitsIpp, Zzsuccbitspp, pSRhold, pSRholdfromdac, Zbinroutfixed_probzero, NZbinroutfixed_probzero,  /**/Zbinroutor, Zviennabits, NZbinroutfixed_prob1, NZbinroutfixed_prob2}; // 24 now  >>7 extent

uint32_t depth_routebits_depth_typesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

// pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_

// unused
uint32_t (*routebits_onlystrobe_typesz[25])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitscyclestrI, zbinroutmybumpS, pSRxorroutes, pSRaddroutes, pSRGswop, pSRDACroutestrobe, pSRLLbumproute, pSRbumprouteD_, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRRLLswop, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5};

uint32_t depth_routebits_juststrobe_typesz[25]={0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};  //redo if needed ever

//////////////////////HERE after to fix - if we use these at all - but yes nostrobe we will use, and notypes
// unused?
// routebits/nostrobe/types
// for strobe speeds pls - we need to divide this up too!
uint32_t (*routebits_nostrobe_typesz[41])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycv, zbinroutorgap, zzsingleroutebits, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbin, pSRmatch, pSRshare, pbitLcvsrroute, pstream, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0}; // reorder for depths

//uint32_t depth_routebits_nostrobe_typesz[41]={0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};

// for depth array above
//ZbinroutR, ZbinroutorD, ZzbinrouteINVbitsR, ZzbinroutebitscycleR, ZflipflopandrouteR, ZpSRsigmaR, ZviennabitsD, ZzsuccbitsppD, ZzsuccbitsIppD, Zbinroutfixed_prob1D, Zbinroutfixed_prob2D, Zbinroutfixed_prob3D, Zbinroutfixed_prob4D, Zbinroutfixed_prob5D, Zbinrout_probXYD, Zbinrout_probXY1D, NZbinrout_probXYD, NZbinrout_probXY1D, NZbinroutfixed_prob1D, NZbinroutfixed_prob2D, NZbinroutfixed_prob3D, NZbinroutfixed_prob4D, zbinroutmycvD, zbinroutorgapR, zzsingleroutebitsD, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbinR, pSRmatchD, pSRshareR, pbitLcvsrrouteD, pstreamD, pSRN13D, pprobintprob3D, pprobintprob5_0D, pprobintprob6_0D, pSRN15D, pSRxorSR-D, pSR_routeSRbits02R, pSR_routeSRbits01R, pSRRaccelghosts0R

// routebits/strobe/notypes

// these have depth and no types: pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_, pbitSRroutelogD_, pbitSRroutelogxxD_, pbitSRroutelogxxxD_, pSR32D_, pSRN22D_, pSRN21D_, pSRR32D_

// or divide to depth/no depth
uint32_t (*routebits_anystrobe_depth_notypesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprob, zreturnnotbits, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRN15, pSRNwas15}; // is same as nostrobe

//nodepth/*16d*/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, binrout_probXY2, binrout_probXY3, pSR_layer1, pSR_layer2, pSR_reflect, pSRshroute, pbitSRroutelog, pbitSRroutelogxx, pSR32, pSRN62, pSRN22, pSRN21, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65 /*41*/}; 

uint32_t depth_routebits_anystrobe_depth_notypesz[16]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  
// routebits/nostrobe/notypes

// for strobe speeds
uint32_t (*routebits_nostrobe_depth_notypesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprob, zreturnnotbits, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRN15, pSRNwas15}; // extent is 8

///no depth /*16d*/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, binrout_probXY2, binrout_probXY3, pSR_layer1, pSR_layer2, pSR_reflect, pSRshroute, pbitSRroutelog, pbitSRroutelogxx, pSR32, pSRN62, pSRN22, pSRN21, pSRN12, pSRN11 /**/}; //37

// redo ordering for depth first

uint32_t depth_routebits_nostrobe_depth_notypesz[16]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  
// abstractbits/strobe=all - these now all use depth - some use in
uint32_t (*abstractbitsz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq,  zcountbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, /* */ zosc1bits, sigmadelta, osceq,  zcountbits}; // 28 +4

// some rejected can work for rungler: which? : zreturnbitsX, pSRN30X};
uint32_t (*abstractbits_forrung[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq,  zcountbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zreturnbits, pSRN30, /* */ zosc1bits, sigmadelta}; // 30 +2


// and which of these have strobe: none

// abstractbits/nostrobe

uint32_t (*abstractbits_nostrobez[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, /* */ zosc1bits, sigmadelta, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits};
