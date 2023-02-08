// new arrays of bit functions:
// + routes:  match array of a 1 to signal depth, else set route. not obv. for abstractbits

/*

- list arrays:

routebits_depth_typezs
routebits_nodepth_typesz

 routebits_nostrobe_depth_typesz
 routebits_nostrobe_nodepth_typesz

routebits_anystrobe_depth_notypesz is same as: routebits_nostrobe_depth_notypesz if we leave out new ones...

routebits_anystrobe_nodepth_notypesz
 routebits_nostrobe_nodepth_notypesz

all use depth but do we need signalling array...
abstractbitsz
abstractbitsz_forrung
abstractbits_nostrobez

 */


// routebits/allstrobe/types
// ignore this one - but is only one we use so far - use for fixed stuff ok
uint32_t (*routebits_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycv, zbinroutorgap, zzsingleroutebits,  zbinroutmybumpSalt, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortogxID_, pSRmatch, pSRshare, pSRGswop, pbitLcvsrroute, pstream, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN13, pSRRLLswop, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN15, pSRN8, pSRN7, pSRN6, pSRN5, pSRxorSR, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, /**/ Zbinrout, Zbinroutor, Zbinrout_strip}; 

uint32_t depth_routebits_typesz[64]={0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1};

// DEP
uint32_t (*routebits_typeszz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits, pSRmatch, pbitLcvsrroute, pstream, pSRLLbumproute, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, ZzsuccbitsIpp, Zzsuccbitspp, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pbitSRroutedoitD_, pSRbumprouteD_, pSRLLswopD_, /* */ Zbinrout_strip, Zbinroutor}; // first 24 have depth, rest not! - check depth/nodepth doubles

// 1/2 pull out those with depth now... but no bumps except cv, and no poorly added depths - checked 2/2 
uint32_t (*routebits_depth_typesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits, pSRmatch, pbitLcvsrroute, pstream, pSRLLbumproute, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, Zbinrout_strip, ZzsuccbitsIpp, Zzsuccbitspp, pSRhold, pSRholdfromdac, Zbinroutfixed_probzero, NZbinroutfixed_probzero, pSR_recbinD_, /**/Zviennabits, NZbinroutfixed_prob1, NZbinroutfixed_prob2}; // 24 now  >>7 extent

uint32_t depth_routebits_depth_typesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

// 1/2 non-depth - fixed route now - checked no depth/depth 2/2
uint32_t (*routebits_nodepth_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, ZzbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pbitSRroutedoitD_, pSRbumprouteD_, pSRLLswopD_, /* */ Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, ZzbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4}; // 39 double 64 >>6 extent

uint32_t depth_routebits_nodepth_typesz[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 


// routebits/nostrobe/types - for strobe speeds

uint32_t (*routebits_nostrobe_depth_typesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinroutor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, pSRmatch, pbitLcvsrroute, pstream, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, pSR_recbinD_, /**/Zbinroutor, Zviennabits, Zzsuccbitspp}; //28 // extent is 7

uint32_t depth_routebits_nostrobe_depth_typesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

uint32_t (*routebits_nostrobe_nodepth_typesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSRshare, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pSR_recbin, /* 8*/Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt}; //11 // extent is 8 // 4 bits

uint32_t depth_routebits_nostrobe_nodepth_typesz[16]={0,0,0,0,  0,0,0,0, 0,0,0,0, 0,0,0,0};

// routebits/strobe/notypes

// these have depth and no types: strobe: pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_,
/// no strobe: pbitSRroutelogD_, pbitSRroutelogxxD_, pbitSRroutelogxxxD_, pSR32D_, pSRN22D_, pSRN21D_, pSRR32D_

// or divide to depth/no depth
uint32_t (*routebits_anystrobe_depth_notypesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprob, zreturnnotbits, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRN15, pSRNwas15}; // is same as nostrobe

uint32_t depth_routebits_anystrobe_depth_notypesz[16]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
  
// routebits/nostrobe/notypes

// for strobe speeds - same as above
uint32_t (*routebits_nostrobe_depth_notypesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprob, zreturnnotbits, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRN15, pSRNwas15}; // extent is 8

uint32_t depth_routebits_nostrobe_depth_notypesz[16]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

uint32_t (*routebits_anystrobe_nodepth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, binrout_probXY2, binrout_probXY3, pSR_layer1, pSR_layer2, pSR_reflect, pbitSRroutelog, pbitSRroutelogxx, pSR32, pSRN62, pSRN22, pSRN21, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65, pSRshroute, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00}; 

uint32_t depth_routebits_anystrobe_nodepth_notypesz[32]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};   

uint32_t (*routebits_nostrobe_nodepth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, binrout_probXY2, binrout_probXY3, pSR_layer1, pSR_layer2, pSR_reflect, pbitSRroutelog, pbitSRroutelogxx, pSR32, pSRN62, pSRN22, pSRN21, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, binrout_probXY2}; 

uint32_t depth_routebits_nostrobe_nodepth_notypesz[32]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};   


// abstractbits/strobe=all - these now all use depth - some use in
uint32_t (*abstractbitsz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq,  zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zsuccbitspp, zsuccbitsIpp, zsuccbits_noshift}; // 28 +4

// some rejected can work for rungler: which? : zreturnbitsX, pSRN30X};
uint32_t (*abstractbits_forrung[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq,  zcountbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zreturnbits, pSRN30, zsuccbitspp, zsuccbitsIpp}; // 30 +2


// and which of these have strobe: none

// abstractbits/nostrobe

uint32_t (*abstractbits_nostrobez[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, /**/zosc1bits, sigmadelta, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits};
