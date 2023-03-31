uint32_t (*routebits_depth_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, Zbinrout_probXY, Zbinrout_probXY1, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, zbinroutmycvalt, zbinroutorgap, zzsingleroutebits, pSRmatch, pbitLcvsrroute, pstream, pSRLLbumproute, pSRN13, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, Zzsuccbitspp, ZzsuccbitsppS_, ZzsuccbitsIpp, Zzsuccbitsppin, ZzsuccbitsppS_in, ZzsuccbitsIppin, pSRhold, pSRholdfromdac, Zbinroutfixed_probzero, NZbinroutfixed_probzero, pSR_recbinD_, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zbinroutsplitxor1, /**/Zbinrout_strip, Zbinroutor, Zviennabits, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, Zbinrout_probXY, Zbinrout_probXY1, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinrout_stripSTR, Zbinrout_stripTOG, NZbinroutfixed_prob1STR, NZbinroutfixed_prob1TOG};

uint32_t depth_routebits_depth_typesz[64]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

#define extent_routebits_depth_typesz 6

// 1/2 non-depth - fixed route now - checked no depth/depth 2/2
uint32_t (*routebits_nodepth_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, pSRGswop, pSR_routeSRbits02, pSR_routeSRbits01, /**/Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, ZpSRsigma, Zzsuccbits, ZzsuccbitsI, pSRGswop, pSR_routeSRbits02, pSR_routeSRbits01, /*str*/ZzbinroutebitscyclestrI, zbinroutmybumpSalt, pSRxorroutes, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pSRN8, pSRN7, pSRN6, pSRbumprouteD_, pSRLLswopD_, ZzbinroutebitscyclestrI, zbinroutmybumpSalt, pSRxorroutes, pSRDACroutestrobe, pSRN40, pSRN36, pSRN33cipher, pSRN33, pprobtoggle1, pprobtoggle2, pprobtoggle4, ZzbinroutebitscyclestrI, zbinroutmybumpSalt, pSRxorroutes, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, ZbinroutSTR, ZbinroutTOG, pprobtoggle1, pprobtoggle2}; 

uint32_t depth_routebits_nodepth_typesz[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 

#define extent_routebits_nodepth_typesz 6

uint32_t (*routebits_anystrobe_depth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprobd, zsuccbitspp, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIppd, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, binrout_probXY2, binrout_probXY3, Zcyclesplit, zTMsimplebitsL, zTMsimplebits, pSRN30, pSRprobxortogx, zcopyGSR_s};//32 + zTMsimplebitsLSTR, zTMsimplebitsLTOG, zTMsimplebitsSTR, zTMsimplebitsTOG

uint32_t depth_routebits_anystrobe_depth_notypesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

#define extent_routebits_anystrobe_depth_notypesz 7

uint32_t (*routebits_anystrobe_nodepth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN62, pSRN22D_, pSRN21D_, Zlast, zjustcycle, /**/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65, pSRshroute, pSRprobxortogxID_, zjustcycleSTR, zjustcycleTOG}; 

uint32_t depth_routebits_anystrobe_nodepth_notypesz[32]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};   

#define extent_routebits_anystrobe_nodepth_notypesz 7

// merged above - depth and no depth
uint32_t (*routebits_anystrobe_notypesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={zTMsimplebitsL, zTMsimplebits, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIppd, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRNwas15, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, binrout_probXY2, binrout_probXY3, Zcyclesplit, /*x*/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN62, pSRN22D_, pSRN21D_, Zlast, zjustcycle, /**/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, binroutAND0, binroutAND00, pbitSRroutelogD_, zTMsimplebitsL, zTMsimplebits, pSRprobxortogx, pSRN12, pSRN11, binroutaltreset, pSRNwas13, pSRN10, pSRN65, pSRshroute, pSRprobxortogxID_, zcopyGSR_s};

#define extent_routebits_anystrobe_notypesz 6

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// routebits/nostrobe/types - for strobe speeds

uint32_t (*routebits_nostrobe_depth_typesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, ZbinroutsplitxorXX, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, pSRmatch, pbitLcvsrroute, pSR_recbinD_, pSRN15, pSRxorSR, pstream};

uint32_t depth_routebits_nostrobe_depth_typesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

#define extent_routebits_nostrobe_depth_typesz 7

uint32_t (*routebits_nostrobe_nodepth_typesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_routeSRbits02, pSR_routeSRbits01, /*8*/Zbinrout, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, pSR_routeSRbits02}; 

uint32_t depth_routebits_nostrobe_nodepth_typesz[16]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};

#define extent_routebits_nostrobe_nodepth_typesz 8

uint32_t (*routebits_nostrobe_depth_notypesz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zTMsimplebitsL, zTMsimplebits, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIpp, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRNwas15, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, binrout_probXY2, binrout_probXY3, Zcyclesplit, /**/zTMsimplebitsL, zTMsimplebits};

uint32_t depth_routebits_nostrobe_depth_notypesz[32]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

#define extent_routebits_nostrobe_depth_notypesz 7

uint32_t (*routebits_nostrobe_nodepth_notypesz[16])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN62, pSRN22D_, pSRN21D_, pbitSRroutelogxxD_, Zlast, zjustcycle};

uint32_t depth_routebits_nostrobe_nodepth_notypesz[16]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};   

#define extent_routebits_nostrobe_nodepth_notypesz 8

// merges
uint32_t (*routebits_nostrobe_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, ZbinroutsplitxorXX, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, pSRmatch, pbitLcvsrroute, pstream, pSRN15, pSRxorSR, pSR_recbinD_, /**/Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_routeSRbits02, pSR_routeSRbits01, pSR_recbinD_, /*44*/Zbinrout_strip, Zbinroutor, ZbinroutsplitxorXX, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1};

#define extent_routebits_nostrobe_typesz 6

uint32_t (*routebits_nostrobe_depth[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout_strip, Zbinroutor, ZbinroutsplitxorXX, Zbinroutsplit, Zbinroutsplitprob, Zbinroutsplitprob1, Zbinroutsplitprob2, Zbinroutsplitxor, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, zbinroutmycvalt, zbinroutorgap, pSRmatch, pbitLcvsrroute, pstream, pSRN15, pSRxorSR, pSR_recbinD_, /*x*/zTMsimplebitsL, zTMsimplebits, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIppd, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zbinrouteSRbits, pSR_altbin1, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSRN30, pSRNwas15, pSR_layer1, pSR_layer2, pSR_reflect, triadexbits, binrout_probXY2, binrout_probXY3, Zcyclesplit, /**/zTMsimplebitsL, zTMsimplebits};

#define extent_routebits_nostrobe_depth 6

uint32_t (*routebits_nostrobe_nodepth[32])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, zbinroutmybumpbitalt, zbinroutmybumpbittalt, pSR_routeSRbits02, pSR_routeSRbits01, /**/zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinrouteORbits, tailbits, tailbitsnos, binroutAND0, binroutAND00, pbitSRroutelogD_, pbitSRroutelogxxD_, pSR32D_, pSRN62, pSRN22D_, pSRN21D_, pbitSRroutelogxxD_, Zlast, zjustcycle, /**/Zbinrout, Zbinrouteforalt, Zbinrouteforaltalt, ZzbinrouteINVbits, Zbinrout, Zbinrouteforalt};

#define extent_routebits_nostrobe_nodepth 7

/////////////////////////////////////////////////////////  IN all for adc/NN

uint32_t (*inall[64])(uint32_t depth, uint32_t in, uint32_t wh)={zadcx, zadconebitsx, zadcpadbits, zadc8bits, zadc4bits, zadc4bitssplit, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadconecompbits, zadcxdouble, zadc4bitsadd, zadc4bitsaddmod, zadc4bitsxor, zadc4bitsor, zadc4bitsand, zadc4bitsmodm, zadc4compbitsadd, zadc4compbitsxor, zadc4compbitsmodm, zadc4onecompbitsadd, /*23*/zadcxdac, zadconebitsxdac, zadcpadbitsdac, zadc8bitsdac, zadc4bitsdac, zadc4bitssplitdac, zadcenergybitsdac, zadc12compbitsdac, zadc8compbitsdac, zadc4compbitsdac, zadccompbitsdac, zadconecompbitsdac, zadcxdoubledac, zadc4bitsadddac, zadc4bitsaddmoddac, zadc4bitsxordac, zadc4bitsordac, zadc4bitsanddac, zadc4bitsmodmdac, zadc4compbitsadddac, zadc4compbitsxordac, zadc4compbitsmodmdac, zadc4onecompbitsadddac, /*23*/zosc1bitsfastA, sigmadeltaA, osceqfA, osceqxfA, zcountbitsA, zcountbitsIA, zprobbitsA, zlfsrbitsA, zllfsrbitsA, zflipbitsA, zosceqbitsIfA, zosceqbitsIxfA, zosc1bitsIfA, zlfsrbitsIA, zTMsimplebitsLA, NZbinroutfixed_prob1A, zsuccbitsIppdA, zflipbitsIA/*18*/}; 

// - adding to inall for NN: zTMsimplebits and also prob of route in/cycle: Zbinroutfixed_prob1...

uint32_t inall_depth[64]={1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /*23dac*/2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, /*18abstract*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};// 64checked 

// abstractbits/strobe=all - these now all use depth - some use IN
uint32_t (*abstractbitsz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bitsfast, sigmadelta, osceq,  zcountbits, zcountbitsI, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bits, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zTMsimplebitsL, zTMsimplebitsL, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zsuccbitspp, zsuccbitsIpp, zsuccbits_noshift, zprobbitsxorstrobe, zprobbitsxortoggle, ztogglebitssh, ztogglebits}; // 28 +4

uint32_t (*abstractbitsz_nostr[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bitsfast, sigmadelta, osceq,  zcountbits, zcountbitsI, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bits, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zsuccbitspp, zsuccbitsIpp, zsuccbits_noshift, ztemplateBURSTflip, /**/zosc1bitsI, sigmadelta, osceq}; // added templateburst=28<<7

#define extent_abstractbits 7

//uint32_t (*abstractbitsz_NN[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bitsfast, sigmadelta, osceqf,  osceqxf, zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsIf, zosceqbitsIxf, zosc1bitsIf, zlfsrbitsI, zflipbitsI, ztogglebits, zTMsimplebitsL, zTMsimplebits, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, /**/zosc1bits, sigmadelta, osceq,  zcountbits, zcountbitsI, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle}; // 23+9 // tested

// some rejected can work for rungler: which? : zreturnbitsX, pSRN30X};
uint32_t (*abstractbits_forrung[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bitsfast, sigmadelta, osceq,  zcountbits, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bits, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zTMsimplebitsL, zTMsimplebits, zsuccbitsprob, zreturnnotbits, zTMsimplebits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, zreturnbits, pSRN30, zsuccbitspp, zsuccbitsIpp, zprobbitsxorstrobe, zprobbitsxortoggle, ztogglebitssh, ztogglebits}; // 30 +2

// abstractbits/nostrobe
//uint32_t (*abstractbits_nostrobez[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq, osceqx, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosceqbitsIx, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zTMsimplebitsL, zTMsimplebits, zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIppd, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zreturnnotbits, pSRLcvSRmaskroute, pSRLcvroute, pSRNwas15, pSRN30};
//zcountbits, zcountbitsI
