// new arrays of bit functions:
// + routes:  match array of a 1 to signal depth, else set route. not obv. for abstractbits

// routebits/allstrobe/types

uint32_t (*routebits_typesz[78])(uint32_t depth, uint32_t in, uint32_t wh)={Zbinrout, Zbinroutor, ZzbinrouteINVbits, Zzbinroutebitscycle, zbinroutebitscyclestrI, Zflipflopandroute, ZpSRsigma, Zviennabits, Zzsuccbitspp, ZzsuccbitsIpp, Zzwiardbits, Zzwiardinvbits, Zbinroutfixed_prob1, Zbinroutfixed_prob2, Zbinroutfixed_prob3, Zbinroutfixed_prob4, Zbinroutfixed_prob5, Zbinrout_probXY, Zbinrout_probXY1, NZbinrout_probXY, NZbinrout_probXY1, NZbinroutfixed_prob1, NZbinroutfixed_prob2, NZbinroutfixed_prob3, NZbinroutfixed_prob4, NZzwiardbits, NZzwiardinvbits, NZzbinrouteINVbits, NZzbinroutebitscycle, NZflipflopandroute, zbinroutmycv, zbinroutorgap, zzwiardbits2I, zzwiardbitsI, zzwiardinvbitsI, zzsingleroutebits,  zbinroutmybumpS, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbin, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortogxI, pSRmatch, pSRshare, pSRGswop, pbitLcvsrroute, pstream, pSRDACroutestrobe, pSRLLbumproute, pSRbumproute, pSRN40, pSRN36, pSRN33cipher, pSRN33, pSRN13, pSRRLLswop, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3, pSRN15, pSRN8, pSRN7, pSRN6, pSRN5, pSRxorSR, pSR_routeSRbits02, pSR_routeSRbits01, pSRRaccelghosts0}; // 78 // how do we reduce? - select again exp_port all...

uint32_t depth_routebits_typesz[78]={0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1,  1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0};

// for array
//  ZbinroutR, ZbinroutorD, ZzbinrouteINVbitsR, ZzbinroutebitscycleR, zbinroutebitscyclestrIRS, ZflipflopandrouteR, ZpSRsigmaR, ZviennabitsD, ZzsuccbitsppD, ZzsuccbitsIppD, ZzwiardbitsD, ZzwiardinvbitsD, Zbinroutfixed_prob1D, Zbinroutfixed_prob2D, Zbinroutfixed_prob3D, Zbinroutfixed_prob4D, Zbinroutfixed_prob5D, Zbinrout_probXYD, Zbinrout_probXY1D, NZbinrout_probXYD, NZbinrout_probXY1D, NZbinroutfixed_prob1D, NZbinroutfixed_prob2D, NZbinroutfixed_prob3D, NZbinroutfixed_prob4D, NZzwiardbitsD, NZzwiardinvbitsD, NZzbinrouteINVbitsR, NZzbinroutebitscycleR, NZflipflopandrouteR, zbinroutmycvD, zbinroutorgapR, zzwiardbits2ID, zzwiardbitsID, zzwiardinvbitsID, zzsingleroutebitsD, zbinroutmybumpS, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbinR, pSRxorroutesSR, pSRaddroutesSR, pSRprobxortogxDS, pSRprobxortogxIDS, pSRmatchD, pSRshareR, pSRGswopSR, pbitLcvsrrouteD, pstreamD, pSRDACroutestrobeSR, pSRLLbumprouteDS, pSRbumprouteDS, pSRN40RS, pSRN36RS, pSRN33cipherRS, pSRN33RS, pSRN13D, pSRRLLswopDS, pprobintprob3D, pprobintprob5_0D, pprobintprob6_0D, pprobtoggle1RS, pprobtoggleRS, pprobtoggle3RS, pprobtoggle4RS, pprobtoggleRS, pprobstrobe1RS, pprobstrobe2RS, pprobstrobe3RS, pSRN15D, pSRN8RS, pSRN7RS, pSRN6RS, pSRN5RS, pSRxorSRD, pSR_routeSRbits02R, pSR_routeSRbits01R, pSRRaccelghosts0R // 78

// routebits/juststrobe/types TODO:

//zbinroutebitscyclestrIRS, zbinroutmybumpS, pSRxorroutesSR, pSRaddroutesSR, pSRprobxortogxDS, pSRprobxortogxIDS, pSRGswopSR, pSRDACroutestrobeSR, pSRLLbumprouteDS, pSRbumprouteDS, pSRN40RS, pSRN36RS, pSRN33cipherRS, pSRN33RS, pSRRLLswopDS, pprobtoggle1RS, pprobtoggleRS, pprobtoggle3RS, pprobtoggle4RS, pprobtoggleRS, pprobstrobe1RS, pprobstrobe2RS, pprobstrobe3RS, pSRN8RS, pSRN7RS, pSRN6RS, pSRN5RS // 27 (27+51=78)

// routebits/nostrobe/types

// ZbinroutR, ZbinroutorD, ZzbinrouteINVbitsR, ZzbinroutebitscycleR, ZflipflopandrouteR, ZpSRsigmaR, ZviennabitsD, ZzsuccbitsppD, ZzsuccbitsIppD, ZzwiardbitsD, ZzwiardinvbitsD, Zbinroutfixed_prob1D, Zbinroutfixed_prob2D, Zbinroutfixed_prob3D, Zbinroutfixed_prob4D, Zbinroutfixed_prob5D, Zbinrout_probXYD, Zbinrout_probXY1D, NZbinrout_probXYD, NZbinrout_probXY1D, NZbinroutfixed_prob1D, NZbinroutfixed_prob2D, NZbinroutfixed_prob3D, NZbinroutfixed_prob4D, NZzwiardbitsD, NZzwiardinvbitsD, NZzbinrouteINVbitsR, NZzbinroutebitscycleR, NZflipflopandrouteR, zbinroutmycvD, zbinroutorgapR, zzwiardbits2ID, zzwiardbitsID, zzwiardinvbitsID, zzsingleroutebitsD, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbinR, pSRmatchD, pSRshareR, pbitLcvsrrouteD, pstreamD, pSRN13D, pprobintprob3D, pprobintprob5_0D, pprobintprob6_0D, pSRN15D, pSRxorSRD, pSR_routeSRbits02R, pSR_routeSRbits01R, pSRRaccelghosts0R // 51
  
// routebits/strobe/notypes

// zsuccbitsprobD, zbinrouteORbitsR, zbinrouteANDbitsR, zbinrouteSRbitsR, zbinroutebitsI_noshiftR, zbinroutebitscycleI_noshiftR, zSRNbitsD, zSRLbitsD, zSRCbitsD, zSRRbitsD, zreturnbitsD,zreturnnotbitsD, zTMsimplebitsD, zpattern4bitsD, zpattern8bitsD, zpattern4bitsID, zpattern8bitsID, zcopyGSRD, zcopyGSR_sDS, zbinroutfixed_noshift_transitIR, tailbitswithdD, tailbitsIwithdD, tailbitswithdnosD, tailbitsIwithdnosD, binroutAND0R, binroutAND00R, binroutaltresetSR, binrout_probXY2D, binrout_probXY3D, pSR_layer1R, pSR_layer2R, pSR_reflectR, pSR_altbin1R, pSRholdR, pSRholdfromdacR, pSRshrouteR, pbitSRroutelogXXX, pbitSRroutelogxxXXX, pbitSRroutelogxxxXXX, pbitLSRroutexxxlogD, pSRLcvSRmaskrouteD, pSRLcvrouteD, pSR32XXX, pSRmodR, pSRNwas13RS, pSRN65RS, pSRN62R, pSRN30D, pSRN22XXX, pSRN21XXX, pSRN15XXX, pSRN12R, pSRN11R, pSRN10SR, pSRNwas15XXX // 54
  
// routebits/nostrobe/notypes

// zsuccbitsprobD, zbinrouteORbitsR, zbinrouteANDbitsR, zbinrouteSRbitsR, zbinroutebitsI_noshiftR, zbinroutebitscycleI_noshiftR, zSRNbitsD, zSRLbitsD, zSRCbitsD, zSRRbitsD, zreturnbitsD,zreturnnotbitsD, zTMsimplebitsD, zpattern4bitsD, zpattern8bitsD, zpattern4bitsID, zpattern8bitsID, zcopyGSRD, zbinroutfixed_noshift_transitIR, tailbitswithdD, tailbitsIwithdD, tailbitswithdnosD, tailbitsIwithdnosD, binroutAND0R, binroutAND00R, binrout_probXY2D, binrout_probXY3D, pSR_layer1R, pSR_layer2R, pSR_reflectR, pSR_altbin1R, pSRholdR, pSRholdfromdacR, pSRshrouteR, pbitSRroutelogXXX, pbitSRroutelogxxXXX, pbitSRroutelogxxxXXX, pbitLSRroutexxxlogD, pSRLcvSRmaskrouteD, pSRLcvrouteD, pSR32XXX, pSRN62R, pSRN30D, pSRN22XXX, pSRN21XXX, pSRN15XXX, pSRN12R, pSRN11R, pSRNwas15XXX // 48

  
// abstractbits/strobe=all - these now all use depth - some use in

uint32_t (*abstractbitsz[24])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, cipher, osceq, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits};

//zosc1bitsD, sigmadeltaD, cipherDS, osceqD, zprobbitsD, zprobbitsxorstrobeDS, zprobbitsxortoggleDS, zonebitsDS, zlfsrbitsD, zllfsrbitsXXX, zflipbitsD, zosceqbitsID, zosc1bitsID, zonebitsIDS, zlfsrbitsID, zflipbitsID, zpattern4bitsD, zpattern8bitsD, zpattern4bitsID, zpattern8bitsID, flipflopD, flipflopID, ztogglebitsshDS, ztogglebitsDS}; // 24

// abstractbits/nostrobe

uint32_t (*abstractbits_nostrz[19])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits};
