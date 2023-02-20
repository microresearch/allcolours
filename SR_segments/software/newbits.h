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

uint32_t (*routebits_depth_typesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits, pSRmatch, pbitLcvsrroute, pstream, pSRLLbumproute, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, Zbinrout_strip, ZzsuccbitsIpp, Zzsuccbitspp, ZzsuccbitsIppin, Zzsuccbitsppin, pSRhold, pSRholdfromdac, Zbinroutfixed_probzero, NZbinroutfixed_probzero, pSR_recbinD_}; //  >>7 extent

uint32_t depth_routebits_depth_typesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

// 1/2 non-depth - fixed route now - checked no depth/depth 2/2
uint32_t (*routebits_nodepth_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, ZzbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pbitSRroutedoitD_, pSRbumprouteD_, pSRLLswopD_, /* */Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, ZzbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRshare, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1}; // 39 double 64 >>6 extent

uint32_t depth_routebits_nodepth_typesz[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 


// routebits/nostrobe/types - for strobe speeds

uint32_t (*routebits_nostrobe_depth_typesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, pSRmatch, pbitLcvsrroute, pstream, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, pSR_recbinD_, /**/Zbinroutor, Zviennabits}; //28 // extent is 7

uint32_t depth_routebits_nostrobe_depth_typesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

uint32_t (*routebits_nostrobe_nodepth_typesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSRshare, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pSR_recbin, /* 8*/Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle}; //11 // extent is 8 // 4 bits

uint32_t depth_routebits_nostrobe_nodepth_typesz[16]={0,0,0,0,  0,0,0,0, 0,0,0,0, 0,0,0,0};

uint32_t (*routebits_anystrobe_depth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprob, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRN15, pSRNwas15, pSRprobxortog, pSRprobxortogx, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, /**/zsuccbitsprob, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, triadexbits};// 21+11 - added pSR_layer1, layer2  pSR_layer2, pSR_reflect which have depth, no type, no strobe

uint32_t depth_routebits_anystrobe_depth_notypesz[16]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

uint32_t (*routebits_nostrobe_depth_notypesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprob, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRN15, pSRNwas15, pSR_layer1, triadexbits}; // 16 // extent is 8
// retest 14 and 15 above // pSRLcvSRmaskroute is good

uint32_t depth_routebits_nostrobe_depth_notypesz[16]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

uint32_t (*routebits_anystrobe_nodepth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, binrout_probXY2, binrout_probXY3, pbitSRroutelog, pbitSRroutelogxx, pSR32, pSRN62, pSRN22D_, pSRN21D_, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65, pSRshroute, pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_, /**/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, binroutAND0, binroutAND00, binrout_probXY2}; 

uint32_t depth_routebits_anystrobe_nodepth_notypesz[32]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};   

uint32_t (*routebits_nostrobe_nodepth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, binrout_probXY2, binrout_probXY3, pbitSRroutelog, pbitSRroutelogxx, pSR32, pSRN62, pSRN22D_, pSRN21D_, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65,  pbitSRroutelogxxD_, pSR32D_, pSRN22D_, pSRN21D_, pSRR32D_,  /**/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, binroutAND0, binroutAND00}; 

uint32_t depth_routebits_nostrobe_nodepth_notypesz[32]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};   


// abstractbits/strobe=all - these now all use depth - some use in
uint32_t (*abstractbitsz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq,  zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zsuccbitspp, zsuccbitsIpp, zsuccbits_noshift}; // 28 +4

uint32_t (*abstractbitsz_NN[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bitsfast, sigmadelta, osceqf,  osceqxf, zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsIf, zosceqbitsIxf, zosc1bitsIf, zlfsrbitsI, zflipbitsI, ztogglebits, zTMsimplebitsL, zTMsimplebits, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, /**/zosc1bits, sigmadelta, osceq,  zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle}; // 23+9 // tested


// some rejected can work for rungler: which? : zreturnbitsX, pSRN30X};
uint32_t (*abstractbits_forrung[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq,  zcountbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zreturnbits, pSRN30, zsuccbitspp, zsuccbitsIpp}; // 30 +2


// and which of these have strobe: none

// abstractbits/nostrobe

uint32_t (*abstractbits_nostrobez[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq, osceqx, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosceqbitsIx, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, /**/zosc1bits, sigmadelta, osceq, zprobbits, zlfsrbits};
