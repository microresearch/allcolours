// 1. speeds
    
// 6/2/ all use depth
uint32_t (*speedfromnostrobe[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfracend, spdfracend, spdfrac1, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, zcompbitsS_, spdviennaS_, spdvienna2, spdvienna3, spdvienna4, zprobbitsS_, zTMsimplebitsS_, zTMsimplebitsLS_, osceqS_, zosc1bitsS_, zENbitsS_, zENbitsIS_,  zENsbitsS_, zENsbitsIS_, sigmadeltaS_, zbinrouteSRbitsS_, zSRBURSTflipS_, zwiardnotinvbitsS_, zwiardnotinvbitsLS_, zsuccbitsI_noshiftdS_, zSRNbitsS_, zcountbitsS_, zcountbitsIS_}; 

uint32_t (*speedfromnostrobe_noIN[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac, spdfrac, spdfracend, spdfracend, zprobbitsS_, zTMsimplebitsLS_, osceqS_, zosc1bitsS_, zosc1bitsIS_, zENbitsS_, zENbitsIS_, zENsbitsS_, zENsbitsIS_, sigmadeltaS_, zbinrouteSRbitsS_, zwiardnotinvbitsLS_, zsuccbitsppS_, zsuccbitsprobS_, zsuccbits_noshiftS_, zsuccbitsI_noshiftS_, zsuccbits_noshiftdS_, zsuccbitsIppS_, zsuccbitsI_noshiftdS_, zSRNbitsS_, zsprobbits, zcountbitsS_, zcountbitsIS_, zSRBURSTflipS_, ztemplateBURSTflipS_, /*29*/spdfrac, spdfrac, spdfracend}; 

uint32_t interpfromnostrobe[32]={1,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}; // matched with speedfromnostrobe and noIN above

//uint32_t speednoin[36]={0,0,0,0, 1,1,1,1, 1,1,1,0, 0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0}; // in the above which ones use IN -> dacfrom

//uint32_t (*speedfromforxor[5])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutfixed_noshift, zbinroutfixed_noshift_transit, zbinroutfixedcycle_noshift, zbinroutfixedI_noshift, zbinroutfixedcycleI_noshift}; 

uint32_t (*speedfromcvforxor[32])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac1, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend, zprobbitsS_, zTMsimplebitsLS_, osceqS_, zosc1bitsS_, zosc1bitsIS_, zENbitsS_, zENbitsIS_,  zENsbitsS_, zENsbitsIS_, zcompbitsS_, zosc1bitsS_, sigmadeltaS_, cipherforspeed, spdviennaS_, zwiardinvbitsS_, zjusttailwithdepthS_, zsuccbitsI_noshiftS_, zsuccbits_noshiftS_, /**/zSRBURSTflipS_, ztemplateBURSTflipS_, spdfrac1, spdfrac3, spdfrac4, spdfracdac3, spdfrac, spdfracend};// no strobes, no routes and only CV ones... doubled up --- but cipher has strobe?

// new for strobes
uint32_t (*speedfromstrobe_depth[16])(uint32_t depth, uint32_t in, uint32_t wh)={strobespdfrac, zprobbitsxorstrobe, zprobbitsxortoggle, zstrobeBURST, zstrobeBURST1, zstrobeBURST2, zstrobeBURST3flip, strobespdfrac, /**/strobespdfrac, zprobbitsxorstrobe, zprobbitsxortoggle, zstrobeBURST, zstrobeBURST1, zstrobeBURST2, zstrobeBURST3flip, strobespdfrac};

uint32_t (*speedfromstrobe_nodepth[16])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebitsnod, ztogglebitsshnod, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, /**/strobe, ztogglebitsnod, ztogglebitsshnod, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift};

// merge these 2 if we dont care about depth
uint32_t (*speedfromstrobe_all[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, ztogglebitsnod, ztogglebitssh, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift, /**/strobe, ztogglebitsnod, ztogglebitsshnod, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, /**/strobespdfrac, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, /**/zstrobeBURST, zstrobeBURST1, zstrobeBURST2, zstrobeBURST3flip}; // >>7

// 2. adc

// with extra vars for reset and advance for probability
uint32_t (*padcfromsd[64])(uint32_t depth, uint32_t in, uint32_t wh, uint32_t reset, uint32_t adv)={zpadcx, zpadcx, zpadconebitsx, zpadcpadbits, zpadc12bits, zpadc8bits, zpadc4bits, zpadceqbits, zpadcenergybits, zpadc12compbits, zpadc8compbits, zpadc4compbits, zpadccompbits, zpadc12onecompbits, zpadc8onecompbits, zpadc4onecompbits, zpadconecompbits, pcipher, zpadcLBURST0, zpadccomp, zpadcxdouble, zpadcxcut, zpadc4bitsadd,  zpadc4bitsaddmod, zpadc4bitsxor, zpadc4bitsor, zpadc4bitsand, zpadc4bitsmodm, zpadc4compbitsadd, zpadc4compbitsxor, zpadc4compbitsmodm, zpadc4onecompbitsadd, zpadcx, zpadcx, zpadconebitsx, zpadcpadbits, zpadc12bits, zpadc8bits, zpadc4bits, zpadceqbits, zpadcenergybits, zpadc12compbits, zpadc8compbits, zpadc4compbits, zpadccompbits, zpadc12onecompbits, zpadc8onecompbits, zpadc4onecompbits, zpadconecompbits, pcipher, zpadcLBURST0, zpadccomp, zpadcxdouble, zpadcxcut, zpadc4bitsadd,  zpadc4bitsaddmod, zpadc4bitsxor, zpadc4bitsor, zpadc4bitsand, zpadc4bitsmodm, zpadc4compbitsadd, zpadc4compbitsxor, zpadc4compbitsmodm, zpadc4onecompbitsadd}; // 64 tested

/////////////////////////
// 3. bits/routes and see list there

#include "newbits.h" // for bits and routes

// 4. probs

uint32_t (*probf_anystrobe_depth[64])(uint32_t depth, uint32_t in, uint32_t wh)={zprobbits, zinvprobbits, zownprobbits, zownGprobbits, spdfracx, spdfracP_, spdfrac1P_, spdfrac3P_, spdfrac4P_, spdfrac5P_, spdfracdac3P_, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc1bitsslow, zosc1bitsIslow, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdviennaP_, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, zSRBURSTflip, ztemplateBURSTflip, zcountbits, zcountbitsI, zbinroutebits_noshiftd, zbinroutebits_noshift_transitd, zbinroutebitsI_noshiftd, zbinrouteSRbits, zsuccbitsI_noshiftd, zsuccbits_noshiftd, zwiardinvbits, /**/zinvprobbits, zprobbits, zownprobbits, zownGprobbits, spdfracP_, spdfrac1P_, spdfrac3P_, spdfrac4P_, spdfrac5P_, spdfracdac3P_, zTMsimplebits, osceq, /**/zsprobbits, strobespdfracP_, zstrobeBURST, zstrobeBURST1, zstrobeBURST2, zstrobeBURST3flip, zstrobeBURSTinv, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, ztogglebits, ztogglebitssh};
// use IN: spdfrac2, spdfrac3, spdfrac4, spdfrac5, spdfracdac3, compbits, spdvienna, ztemplateBURSTflip
//
uint32_t (*probf_anystrobe_forNN_depth[16])(uint32_t depth, uint32_t in, uint32_t wh)={zprobbits, zinvprobbits, osceq, zosc1bits, zosc1bitsI, zosc1bitsslow, zosc1bitsIslow, zSRBURSTflip, ztemplateBURSTflip, zcountbitsI, zsprobbits, zstrobeBURST, zstrobeBURST1, zstrobeBURST2, zstrobeBURST3flip, zstrobeBURSTinv}; // 16 >>8 // tested 18/2/23

uint32_t (*probf_anystrobe_depth_noin[32])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zownprobbits, zownGprobbits, spdfracP_, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc1bitsslow, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, sigmadelta, spdviennaP_, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, zbinroutebits_noshiftd, zbinrouteSRbits, zsuccbitsI_noshiftd, zsprobbits, strobespdfracP_, zstrobeBURST, clksrG, clksr, zprobbitsxorstrobe, zprobbitsxortoggle, ztogglebits, ztogglebitssh};

uint32_t (*probf_anystrobe_nodepth[16])(uint32_t depth, uint32_t in, uint32_t wh)={zbinroutebits_noshift, zbinroutebits_noshift_transit, zbinroutebitsI_noshift, zjusttail, zbinroutebits_noshift, zbinroutebits_noshift_transit, strobe, ztogglebitsnod, ztogglebitsshnod, stroberoute, strobezsuccbits_noshift, strobezsuccbitsI_noshift, strzbinroutfixed_noshift_transit, strzbinroutfixed_noshift_transitI, strzbinroutfixed_noshift, strzbinroutfixedI_noshift}; // >>8 

uint32_t (*probf_nostrobe_depth[32])(uint32_t depth, uint32_t in, uint32_t wh)={zinvprobbits, zprobbits, zownprobbits, zownGprobbits, spdfracP_, spdfrac1P_, spdfrac3P_, spdfrac4P_, spdfrac5P_, spdfracdac3P_, zTMsimplebits, osceq, zosc1bits, zosc1bitsI, zosc1bitsslow, zENbits, zENbitsI,  zENsbits, zENsbitsI, zENsroutedbits, zcompbits, sigmadelta, spdviennaP_, zsuccbitsI_noshift, zsuccbits_noshift, zSRNbits, zbinroutebits_noshiftd, zbinroutebits_noshift_transitd, zbinroutebitsI_noshiftd, zbinrouteSRbits, zsuccbitsI_noshiftd, zsuccbits_noshift}; // 32

// 5. tails
void (*dotail[32])(void)= {sever, fliptail, basictail, succtail, succtailback, tailC, tailL, tailR, tailN, basictailnos, succtailnos, succtailbacknos, tailCnos, tailLnos, tailRnos, tailNnos, basictailinv, succtailinv, succtailbackinv, tailCinv, tailLinv, tailRinv, tailNinv, basictailnosinv, succtailnosinv, succtailbacknosinv, tailCnosinv, tailLnosinv, tailRnosinv, tailNnosinv, tailXOR0, tailXOR1}; // 1 is basictail. default >>7

void (*globalls_depth[16])(uint32_t depth)={binaryN, binaryX, SRRglobalbumpcvn, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd, SRRglobalorder, SRRglobaltailset, /**/binaryN, binaryX, SRRglobalbumpcvn, SRRglobalbumpcvn, SRRglobalbumpcvnroute, SRRglobalbumpcvndac, SRRglobalbumpcvnspd};

void (*globalls_nodepth[4])(uint32_t depth)={SRRglobalbumpS, SRRglobalbumproute, SRRglobalbumpdac, SRRglobalorderbumpS}; 

