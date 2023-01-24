// new arrays of bit functions - deprecate all doubles with no types, fixedroutes, and sel2 - all as marked in segmodes...  divide as to strobe/no strobe

////1 D, 2 R, 4 S (if needed) 8 IN?

// [integrate exp_ports below]

// routebits/strobe/alltypes

// routebits/nostrobe/alltypes

// routebits/strobe/types

ZbinroutR, ZbinroutorD, ZzbinrouteINVbitsR, ZzbinroutebitscycleR, zbinroutebitscyclestrIRS, ZflipflopandrouteR, ZpSRsigmaR, ZviennabitsD, ZzsuccbitsppD, ZzsuccbitsIppD, ZzwiardbitsD, ZzwiardinvbitsD, Zbinroutfixed_prob1D, Zbinroutfixed_prob2D, Zbinroutfixed_prob3D, Zbinroutfixed_prob4D, Zbinroutfixed_prob5D, Zbinrout_probXYD, Zbinrout_probXY1D, NZbinrout_probXYD, NZbinrout_probXY1D, NZbinroutfixed_prob1D, NZbinroutfixed_prob2D, NZbinroutfixed_prob3D, NZbinroutfixed_prob4D, NZzwiardbitsD, NZzwiardinvbitsD, binroutesel3R, NZzbinrouteINVbitsR, NZzbinroutebitscycleR, NZflipflopandrouteR, zbinroutmycvD, zbinroutorgapR, zzwiardbits2ID, zzwiardbitsID, zzwiardinvbitsID, zzsingleroutebitsD, zbinroutfixed_prob1R/D, zbinroutfixed_prob1LD, zbinroutmybumpS, zbinroutmybumpbit, zbinroutmybumpbitt, pSR_recbinR, pSRxorroutesSR, pSRaddroutesSR, pSRprobxortogxDS, pSRprobxortogxIDS, pSRmatchD, pSRshareR, pSRGswopSR, pSRsigmaRaboveanyways, pbitLcvsrrouteD, pstreamD, pSRDACroutestrobeSR, pSRLLbumprouteDS, pSRbumprouteSCCC, pSRN40RS, pSRN36RS, pSRN33cipherRS, pSRN33RS, pSRN13D, pSRRLLswopDS, pSRRbumproute0SXXX, pprobintprob3D, pprobintprob5_0D, pprobintprob6_0D, pprobtoggle1RS, pprobtoggleRS, pprobtoggle3RS, pprobtoggle4RS, pprobtoggleRS, pprobstrobe1RS, pprobstrobe2RS, pprobstrobe3RS, pSRN15D, pSRN8RS, pSRN7RS, pSRN6RS, pSRN5RS, pSRxorSRD, pbitSRroutedoitD, pSR_routeSRbits02R, pSR_routeSRbits01R, pSRRaccelghosts0R // 84 // how do we split
  
// routebits/nostrobe/types

// routebits/strobe/notypes

zsuccbitsprobD, zbinrouteORbitsR, zbinrouteANDbitsR, zbinrouteSRbitsR, zbinroutebitsI_noshiftR, zbinroutebitscycleI_noshiftR, zSRNbitsD, zSRLbitsD, zSRCbitsD, zSRRbitsD, zreturnbitsD,zreturnnotbitsD, zTMsimplebitsD, zpattern4bitsD, zpattern8bitsD, zpattern4bitsID, zpattern8bitsID, zcopyGSRD, zcopyGSR_sDS, zbinroutfixed_noshift_transitIR, tailbitswithdD, tailbitsIwithdD, tailbitswithdnosD, tailbitsIwithdnosD, binroutAND0R, binroutAND00R, binroutaltresetSR, binrout_probXY2D, binrout_probXY3D, pSR_layer1R, pSR_layer2R, pSR_reflectR, pSR_altbin1R, pSRholdR, pSRholdfromdacR, pSRshrouteR, pbitSRroutelogXXX, pbitSRroutelogxxXXX, pbitSRroutelogxxxXXX, pbitLSRroutexxxlogD, pSRLcvSRmaskrouteD, pSRLcvrouteD, pSR32XXX, pSRmodR, pSRNwas13RS, pSRN65RS, pSRN62R, pSRN30D, pSRN22XXX, pSRN21XXX, pSRN15XXX, pSRN12R, pSRN11R, pSRN10SR, pSRNwas15XXX // 28+26= 54
  
// routebits/nostrobe/notypes

// abstractbits/strobe=all - these now all use depth

uint32_t (*abstractbitsz[24])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, cipher, osceq, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zonebitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits};

//zosc1bitsD, sigmadeltaD, cipherDS, osceqD, zprobbitsD, zprobbitsxorstrobeDS, zprobbitsxortoggleDS, zonebitsDS, zlfsrbitsD, zllfsrbitsXXX, zflipbitsD, zosceqbitsID, zosc1bitsID, zonebitsIDS, zlfsrbitsID, zflipbitsID, zpattern4bitsD, zpattern8bitsD, zpattern4bitsID, zpattern8bitsID, flipflopD, flipflopID, ztogglebitsshDS, ztogglebitsDS}; // 24

// abstractbits/nostrobe

uint32_t (*abstractbits_nostrz[19])(uint32_t depth, uint32_t in, uint32_t wh)={zosc1bits, sigmadelta, osceq, zprobbits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zlfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, flipflop, flipflopI, ztogglebitssh, ztogglebits};

// allbits/strobe // would be 24+84+54=162...



// allbits/nostrobe

