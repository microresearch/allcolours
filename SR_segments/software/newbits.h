// arrays of bit functions:

/*

- list arrays:

ANYstrobes:
routebits_depth_typezs 
routebits_nodepth_typesz
routebits_anystrobe_depth_notypesz is same as: routebits_nostrobe_depth_notypesz if we leave out new ones...
routebits_anystrobe_nodepth_notypesz

NOstrobes - for strobe speeds:
routebits_nostrobe_depth_typesz
routebits_nostrobe_depth_notypesz
routebits_nostrobe_nodepth_typesz
routebits_nostrobe_nodepth_notypesz

+ merged arrays now:
routebits_anystrobe_notypesz

routebits_nostrobe_nodepth - all types
routebits_nostrobe_depth - all types
routebits_nostrobe_typesz - all depths


all use depth but do we need signalling array...
abstractbitsz
abstractbitsz_forrung
abstractbits_nostrobez

 */

uint32_t (*routebits_depth_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, Zbinrout_probXY, Zbinrout_probXY1, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits, pSRmatch, pbitLcvsrroute, pstream, pSRLLbumproute, pSRN13, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, Zzsuccbitspp, ZzsuccbitsppS_, ZzsuccbitsIpp, Zzsuccbitsppin, ZzsuccbitsppS_in, ZzsuccbitsIppin, pSRhold, pSRholdfromdac, Zbinroutfixed_probzero, NZbinroutfixed_probzero, pSR_recbinD_, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zbinroutsplitxor1, /**/Zbinrout_strip, Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, Zbinrout_probXY, Zbinrout_probXY1, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits}; //  45/// + 19 // extent >>6 now! checked 22/2

uint32_t depth_routebits_depth_typesz[64]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

#define extent_routebits_depth_typesz 6

// 1/2 non-depth - fixed route now - checked no depth/depth 2/2
uint32_t (*routebits_nodepth_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, ZzbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pbitSRroutedoitD_, pSRbumprouteD_, pSRLLswopD_, /**/Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, ZzbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, zbinroutmybumpSalt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRGswop, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3}; // 39 double 64 >>6 extent

uint32_t depth_routebits_nodepth_typesz[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 

#define extent_routebits_nodepth_typesz 6

uint32_t (*routebits_anystrobe_depth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprobd, zsuccbitspp, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIppd, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, pSRprobxortog, pSRprobxortogx, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, binrout_probXY2, binrout_probXY3, Zcyclesplit, zTMsimplebitsL, zTMsimplebits, pSRN30};//32

uint32_t depth_routebits_anystrobe_depth_notypesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

#define extent_routebits_anystrobe_depth_notypesz 7

uint32_t (*routebits_anystrobe_nodepth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN62, pSRN22D_, pSRN21D_, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65, pSRshroute, pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_, Zlast, zjustcycle, /**/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, binroutAND0, binroutAND00, pbitSRroutelogD_}; 

uint32_t depth_routebits_anystrobe_nodepth_notypesz[32]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};   

#define extent_routebits_anystrobe_nodepth_notypesz 7

// merged above - depth and no depth
uint32_t (*routebits_anystrobe_notypesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={zTMsimplebitsL, zTMsimplebits, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIppd, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRNwas15, pSRprobxortog, pSRprobxortogx, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, binrout_probXY2, binrout_probXY3, Zcyclesplit, /*x*/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN62, pSRN22D_, pSRN21D_, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65, pSRshroute, pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_, Zlast, zjustcycle, /**/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, binroutAND0, binroutAND00, pbitSRroutelogD_};

#define extent_routebits_anystrobe_notypesz 6

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// routebits/nostrobe/types - for strobe speeds

uint32_t (*routebits_nostrobe_depth_typesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, ZbinroutsplitxorXX, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, pSRmatch, pbitLcvsrroute, pstream, pSRN15, pSRxorSR, pSR_recbin};

uint32_t depth_routebits_nostrobe_depth_typesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

#define extent_routebits_nostrobe_depth_typesz 7

uint32_t (*routebits_nostrobe_nodepth_typesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pSR_recbin, /*8*/Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute}; 

uint32_t depth_routebits_nostrobe_nodepth_typesz[16]={0,0,0,0,  0,0,0,0, 0,0,0,0, 0,0,0,0};

#define extent_routebits_nostrobe_nodepth_typesz 8

uint32_t (*routebits_nostrobe_depth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zTMsimplebitsL, zTMsimplebits, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIpp, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRNwas15, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, binrout_probXY2, binrout_probXY3, Zcyclesplit, /**/zTMsimplebitsL, zTMsimplebits};

uint32_t depth_routebits_nostrobe_depth_notypesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

#define extent_routebits_nostrobe_depth_notypesz 7

uint32_t (*routebits_nostrobe_nodepth_notypesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN62, pSRN22D_, pSRN21D_, pbitSRroutelogxxD_, Zlast, zjustcycle};

uint32_t depth_routebits_nostrobe_nodepth_notypesz[16]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};   

#define extent_routebits_nostrobe_nodepth_notypesz 8

// merges
uint32_t (*routebits_nostrobe_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, ZbinroutsplitxorXX, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, pSRmatch, pbitLcvsrroute, pstream, pSRN15, pSRxorSR, pSR_recbin, /**/Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pSR_recbin, /*44*/Zbinrout_strip, Zbinroutor, ZbinroutsplitxorXX, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1};

#define extent_routebits_nostrobe_typesz 6

uint32_t (*routebits_nostrobe_depth[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, ZbinroutsplitxorXX, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, pSRmatch, pbitLcvsrroute, pstream, pSRN15, pSRxorSR, pSR_recbin, /*x*/zTMsimplebitsL, zTMsimplebits, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIppd, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRNwas15, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, binrout_probXY2, binrout_probXY3, Zcyclesplit, /**/zTMsimplebitsL, zTMsimplebits};

#define extent_routebits_nostrobe_depth 6

uint32_t (*routebits_nostrobe_nodepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0, pSR_recbin, /**/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN62, pSRN22D_, pSRN21D_, pbitSRroutelogxxD_, Zlast, zjustcycle, /**/Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits};

#define extent_routebits_nostrobe_nodepth 7

/////////////////////////////////////////////////////////  

// abstractbits/strobe=all - these now all use depth - some use IN
uint32_t (*abstractbitsz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq,  zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebitsL, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zsuccbitspp, zsuccbitsIpp, zsuccbits_noshift}; // 28 +4

#define extent_abstractbits 7

//uint32_t (*abstractbitsz_NN[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bitsfast, sigmadelta, osceqf,  osceqxf, zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsIf, zosceqbitsIxf, zosc1bitsIf, zlfsrbitsI, zflipbitsI, ztogglebits, zTMsimplebitsL, zTMsimplebits, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, /**/zosc1bits, sigmadelta, osceq,  zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle}; // 23+9 // tested

// some rejected can work for rungler: which? : zreturnbitsX, pSRN30X};
uint32_t (*abstractbits_forrung[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq,  zcountbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, ztogglebitssh, ztogglebits, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zreturnbits, pSRN30, zsuccbitspp, zsuccbitsIpp}; // 30 +2

// abstractbits/nostrobe
//uint32_t (*abstractbits_nostrobez[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq, osceqx, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosceqbitsIx, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zTMsimplebitsL, zTMsimplebits, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIppd, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zreturnnotbits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, pSRN30};
//zcountbits, zcountbitsI
