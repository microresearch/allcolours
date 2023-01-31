// new arrays of bit functions:
// + routes:  match array of a 1 to signal depth, else set route. not obv. for abstractbits

// routebits/allstrobe/types

uint32_t (*routebits_typesz[64])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, NZzwiardbits, NZzwiardinvbits, zbinroutmycv, zbinroutorgap, zzwiardbits2I, zzsingleroutebits,  zbinroutmybumpS, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortogxI, pSRmatch, pSRshare, pSRGswop, pbitLcvsrroute, pstream, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN13, pSRRLLswop, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN15, pSRN8, pSRN7, pSRN6, pSRN5, pSRxorSR, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0}; // trimmed so doesn't match those below

uint32_t depth_routebits_typesz[64]={0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0}; // checked

// for depth array above
//  ZbinroutR, ZbinroutorD, ZzbinrouteINVbitsR, ZzbinroutebitscycleR, zbinroutebitscyclestrIRS, ZflipflopandrouteR, ZpSRsigmaR, ZviennabitsD, ZzsuccbitsppD, ZzsuccbitsIppD, NZbinrout_probXYD, NZbinrout_probXY1D, NZbinroutfixed_prob1D, NZbinroutfixed_prob2D, NZbinroutfixed_prob3D, NZbinroutfixed_prob4D, NZzwiardbitsD, NZzwiardinvbitsD, zbinroutmycvD, zbinroutorgapR, zzwiardbits2ID, zzsingleroutebitsD, zbinroutmybumpS, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbinR, pSRxorroutesSR, pSRaddroutesSR, pSRprobxortogxDS, pSRprobxortogxIDS, pSRmatchD, pSRshareR, pSRGswopSR, pbitLcvsrrouteD, pstreamD, pSRDACroutestrobeSR, pSRLLbumprouteDS, pSRbumprouteDS, pSRN40RS, pSRN36RS, pSRN33cipherRS, pSRN33RS, pSRN13D, pSRRLLswopDS, pprobintprob3D, pprobintprob5_0D, pprobintprob6_0D, pprobtoggle1RS, pprobtoggleRS, pprobtoggle3RS, pprobtoggle4RS, pprobtoggleRS, pprobstrobe1RS, pprobstrobe2RS, pprobstrobe3RS, pSRN15D, pSRN8RS, pSRN7RS, pSRN6RS, pSRN5RS, pSRxorSRD, pSR_routeSRbits02R, pSR_routeSRbits01R, pSRRaccelghosts0R // 64

// pull out ones which could be used for prob - even though have shift// or we can remove shift:

//  ZbinroutR, ZzbinrouteINVbitsR, ZzbinroutebitscycleR, zbinroutebitscyclestrIRS, ZflipflopandrouteR, ZpSRsigmaR, zbinroutorgapR, zbinroutmybumpS, zbinroutmybumpbitR, zbinroutmybumpbittR, pSR_recbinR, pSRxorroutesSR, pSRaddroutesSR, pSRshareR, pSRGswopSR, pSRDACroutestrobeSR, pSRN40RS, pSRN36RS, pSRN33cipherRS, pSRN33RS, pprobtoggle1RS, pprobtoggleRS, pprobtoggle3RS, pprobtoggle4RS, pprobtoggleRS, pprobstrobe1RS, pprobstrobe2RS, pprobstrobe3RS, pSRN8RS, pSRN7RS, pSRN6RS, pSRN5RS, pSR_routeSRbits02R, pSR_routeSRbits01R, // [34] 

// deal later with strobe ones, and ones which we added depth to // do we have a list of those: no types: zjustcycle, tailbitsInos, tailbitsnos, tailbitsI, zjusttail // justcycle we have as prob already

// strobes: 

// routebits/juststrobe/types TODO:

uint32_t (*routebits_onlystrobe_typesz[27])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebitscyclestrI, zbinroutmybumpS, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortogxI, pSRGswop, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRRLLswop, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN8, pSRN7, pSRN6, pSRN5}; // 27 (27+51=78)

uint32_t depth_routebits_juststrobe_typesz[27]={0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// for depth array above
//zbinroutebitscyclestrIRS, zbinroutmybumpS, pSRxorroutesSR, pSRaddroutesSR, pSRprobxortogxDS, pSRprobxortogxIDS, pSRGswopSR, pSRDACroutestrobeSR, pSRLLbumprouteDS, pSRbumprouteDS, pSRN40RS, pSRN36RS, pSRN33cipherRS, pSRN33RS, pSRRLLswopDS, pprobtoggle1RS, pprobtoggleRS, pprobtoggle3RS, pprobtoggle4RS, pprobtoggleRS, pprobstrobe1RS, pprobstrobe2RS, pprobstrobe3RS, pSRN8RS, pSRN7RS, pSRN6RS, pSRN5RS

// routebits/nostrobe/types

uint32_t (*routebits_nostrobe_typesz[49])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zzwiardbits, Zzwiardinvbits, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, NZzwiardbits, NZzwiardinvbits, zbinroutmycv, zbinroutorgap, zzwiardbits2I, Nzzwiardbits2I, zzwiardbitsI, zzwiardinvbitsI, zzsingleroutebits, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbin, pSRmatch, pSRshare, pbitLcvsrroute, pstream, pSRN13, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pSRN15, pSRxorSR, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0}; 

uint32_t depth_routebits_nostrobe_typesz[49]={0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};

// for depth array above
//ZbinroutR, ZbinroutorD, ZzbinrouteINVbitsR, ZzbinroutebitscycleR, ZflipflopandrouteR, ZpSRsigmaR, ZviennabitsD, ZzsuccbitsppD, ZzsuccbitsIppD, ZzwiardbitsD, ZzwiardinvbitsD, Zbinroutfixed_prob1D, Zbinroutfixed_prob2D, Zbinroutfixed_prob3D, Zbinroutfixed_prob4D, Zbinroutfixed_prob5D, Zbinrout_probXYD, Zbinrout_probXY1D, NZbinrout_probXYD, NZbinrout_probXY1D, NZbinroutfixed_prob1D, NZbinroutfixed_prob2D, NZbinroutfixed_prob3D, NZbinroutfixed_prob4D, NZzwiardbitsD, NZzwiardinvbitsD, zbinroutmycvD, zbinroutorgapR, zzwiardbits2ID, Nzzwiardbits2ID, zzwiardbitsID, zzwiardinvbitsID, zzsingleroutebitsD, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbinR, pSRmatchD, pSRshareR, pbitLcvsrrouteD, pstreamD, pSRN13D, pprobintprob3D, pprobintprob5_0D, pprobintprob6_0D, pSRN15D, pSRxorSR-D, pSR_routeSRbits02R, pSR_routeSRbits01R, pSRRaccelghosts0R

// routebits/strobe/notypes

uint32_t (*routebits_anystrobe_notypesz[55])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprob, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zreturnbits, zreturnnotbits, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zcopyGSR, zcopyGSR_s, zbinroutfixed_noshift_transitI, tailbitswithd, tailbitsIwithd, tailbitswithdnos, tailbitsIwithdnos, binroutAND0, binroutAND00, binroutaltreset, binrout_probXY2, binrout_probXY3, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSRhold, pSRholdfromdac, pSRshroute, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRmod, pSRNwas13, pSRN65, pSRN62, pSRN30, pSRN22, pSRN21, pSRN15, pSRN12, pSRN11, pSRN10, pSRNwas15}; // 55

uint32_t depth_routebits_anystrobe_notypesz[55]={1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1};

// for depth array above
// zsuccbitsprobD, zbinrouteORbitsR, zbinrouteANDbitsR, zbinrouteSRbitsR, zbinroutebitsI_noshiftR, zbinroutebitscycleI_noshiftR, zSRNbitsD, zSRLbitsD, zSRCbitsD, zSRRbitsD, zreturnbitsD, zreturnnotbitsD, zTMsimplebitsD, zpattern4bitsD, zpattern8bitsD, zpattern4bitsID, zpattern8bitsID, zcopyGSRD, zcopyGSR_sDS, zbinroutfixed_noshift_transitIR, tailbitswithdD, tailbitsIwithdD, tailbitswithdnosD, tailbitsIwithdnosD, binroutAND0R, binroutAND00R, binroutaltresetSR, binrout_probXY2D, binrout_probXY3D, pSR_layer1R, pSR_layer2R, pSR_reflectR, pSR_altbin1R, pSRholdR, pSRholdfromdacR, pSRshrouteR, pbitSRroutelogXXX, pbitSRroutelogxxXXX, pbitSRroutelogxxxXXX, pbitLSRroutexxxlogD, pSRLcvSRmaskrouteD, pSRLcvrouteD, pSR32XXX, pSRmodR, pSRNwas13RS, pSRN65RS, pSRN62R, pSRN30D, pSRN22XXX, pSRN21XXX, pSRN15XXX, pSRN12R, pSRN11R, pSRN10SR, pSRNwas15XXX // 55 XXX as depth/1
  
// routebits/nostrobe/notypes

uint32_t (*routebits_nostrobe_notypesz[49])(uint32_t depth, uint32_t in, uint32_t wh)={zsuccbitsprob, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zreturnbits, zreturnnotbits, zTMsimplebits, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, zcopyGSR, zbinroutfixed_noshift_transitI, tailbitswithd, tailbitsIwithd, tailbitswithdnos, tailbitsIwithdnos, binroutAND0, binroutAND00, binrout_probXY2, binrout_probXY3, pSR_layer1, pSR_layer2, pSR_reflect, pSR_altbin1, pSRhold, pSRholdfromdac, pSRshroute, pbitSRroutelog, pbitSRroutelogxx, pbitSRroutelogxxx, pbitLSRroutexxxlog, pSRLcvSRmaskroute, pSRLcvroute, pSR32, pSRN62, pSRN30, pSRN22, pSRN21, pSRN15, pSRN12, pSRN11, pSRNwas15};

uint32_t depth_routebits_nostrobe_notypesz[49]={1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1};

// for depth array above
// zsuccbitsprobD, zbinrouteORbitsR, zbinrouteANDbitsR, zbinrouteSRbitsR, zbinroutebitsI_noshiftR, zbinroutebitscycleI_noshiftR, zSRNbitsD, zSRLbitsD, zSRCbitsD, zSRRbitsD, zreturnbitsD,zreturnnotbitsD, zTMsimplebitsD, zpattern4bitsD, zpattern8bitsD, zpattern4bitsID, zpattern8bitsID, zcopyGSRD, zbinroutfixed_noshift_transitIR, tailbitswithdD, tailbitsIwithdD, tailbitswithdnosD, tailbitsIwithdnosD, binroutAND0R, binroutAND00R, binrout_probXY2D, binrout_probXY3D, pSR_layer1R, pSR_layer2R, pSR_reflectR, pSR_altbin1R, pSRholdR, pSRholdfromdacR, pSRshrouteR, pbitSRroutelogXXX, pbitSRroutelogxxXXX, pbitSRroutelogxxxXXX, pbitLSRroutexxxlogD, pSRLcvSRmaskrouteD, pSRLcvrouteD, pSR32XXX, pSRN62R, pSRN30D, pSRN22XXX, pSRN21XXX, pSRN15XXX, pSRN12R, pSRN11R, pSRNwas15XXX // 48 XXX as depth/1

  
// abstractbits/strobe=all - these now all use depth - some use in

uint32_t (*abstractbitsz[32])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, cipher, osceq,  zcountbits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits, /*dd */ zosc1bits, sigmadelta, cipher, osceq,  zcountbits, zprobbits, zprobbitsxorstrobe }; // double to 32 on dd

// abstractbits/nostrobe

uint32_t (*abstractbits_nostrobez[19])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits};
