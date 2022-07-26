// 14/6/2022 moved to geomantic.h

// list of functions:

///TODO: still to add some which got left out...

// routes: binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI,

// speeds: holdlspdfrac, spdfrac, spdfrac2, strobe, ones, clksr, clksrG

// bits: sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI,

// zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits

//0function outside speed
uint32_t (*outside[32])(uint32_t depth, uint32_t wh)={OUT_zero, OUT_SRdelay_lineIN}; // delay bin needs to match with delay out, or shared delay lines...

//0.5gshift
uint32_t (*gshifts[32])(uint32_t wh)={gshift0, gshiftnull};

//1speed 
// now with depth/CV
uint32_t (*speedfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksr, clksrG, speedselcvl, speedselcvm, speedseloldcvl, speedseloldcvm}; // one interp, next not - see interp below... interp is extracted... add in binroutes

// 5,6,8,9 dont work-> all to do with trigger!

//0 is strobe
// TODO match with interp////////
uint8_t interp[32]={0,1,1,0,0,0,0,0,0,0,0,0,0,0};

//2length
uint32_t (*lengthfromsd[32])(uint32_t depth, uint32_t wh)={nlen, rlen, holdlen}; // we only have 2 functions here so far - nlen is null/hold, what other functions

//3adc
uint32_t (*adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, adcselcvm, adcselcvl, probcvladcselcvm, probdacadcselcvm}; 

uint32_t (*dacfunc[32])(uint32_t depth, uint32_t wh)={ddac0, ddac1, ddac2, ddac3, ddac4, ddac5, ddac6, ddac7, ddac8, ddac9, ddac10, ddac11, ddac12, ddac13, ddac14, ddac15, ddac16, ddac17, ddac18, ddac19, ddac20, ddac21, ddac22, ddac23, ddac24, dacselcvl, dacselcvm};

//4bits
uint32_t (*bitfromsd[66])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, Rtest, gensel, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, SRdelay_lineOUT}; // 

//5newfunc
uint32_t (*newfunc[32])(uint32_t depth, uint32_t wh)={zero, bitsmod, cvmod}; //


uint32_t *CVlist[4][19]={
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &CVM[0], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &gate[0].par, &gate[0].oldcv, &gate[0].oldcvl, &gate[0].oldcvm},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &CVM[1], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[1], &param[1], &gate[1].par, &gate[1].oldcv, &gate[1].oldcvl, &gate[1].oldcvm},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &CVM[2], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[2], &param[2], &gate[2].par, &gate[2].oldcv, &gate[2].oldcvl, &gate[2].oldcvm},
  
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &CVM[3], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[3], &param[3], &gate[3].par, &gate[3].oldcv, &gate[3].oldcvl, &gate[3].oldcvm}
};
  // 0,    1             2             3             4             5       6        7            8           9         10     11 -> 19

// 0 null 1 0dac 2 1dac 3 2dac 4 3dac 5 CV 6 CVL 7 CVM 8 ADCin 9 Gs0 10 Gs1 11 Gs2 12 Gs3 13 clksr_ 14 param 15 par 16 oldcv 17 oldcvl 18 oldcvm

// TODO: but this over-rides dacfrom - alternative would be to index as CVlist[dacfrom[w]+1] !!!

//......
// TODO: but these become more like groups now - question is if we have in SR individual array of speedfuncs etc. with own count in
// and we can sync and shift these counts....

// then each would need ref into 4 functions +dac5 + 6 sets of CV???? = 10 or 11 counters each...

enum refs {fspeed, flength, fadc, fbit, fdac, fnew, fout, gs, out}; // 9
enum cvs {cvspeed, cvspeedmod, cvlength, cvdac, cvadc, cvadcIN,  cvbit, cvbitcomp, cvnew, cvout}; //10

// out functions
static inline uint32_t vgen(uint32_t bitn, uint32_t w){
  int32_t tmp; uint32_t xx,val,lengthbit=15, new_stat;
  BITN_AND_OUTVgen_;
  return val;
}

//    BITN_AND_OUTVXOR_;
static inline uint32_t vxor(uint32_t bitn, uint32_t w){
  int32_t tmp; uint32_t val, xx, lengthbit=15, new_stat;
  BITN_AND_OUTVXOR_;
  return val;
}

//6 out
uint32_t (*outs[32])(uint32_t bitn, uint32_t wh)={vgen, vxor};
  
void SR_geomanticxx(uint8_t w){  // for split func/cv
  static uint32_t oldspdfunccnt;
  HEADNADA;
  if (interp[gate[w].func[spdfunccnt][fspeed]]){ // gate[w].func[spdfunccnt][fspeed]

    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
   if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

  CLKSR; // new macro deals with intflag outside speed

      // moved up TODO: - wrap in macro 
    if (gate[w].cvcnt!=gate[w].oldcvcnt || spdfunccnt!=oldspdfunccnt ){ // we have a CV change // can be other changes or strobe or.... ??? 
      gate[w].oldcv=CV[w];
      gate[w].oldcvl=CVL[w];
      gate[w].oldcvm=CVM[w];
    }
    gate[w].oldcvcnt=gate[w].cvcnt;
    oldspdfunccnt=spdfunccnt;

    // function outside speed...
    bitn=(*outside[gate[w].func[outfunccnt][fout]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvout]],w);
    
  if ((*speedfromsd[gate[w].func[spdfunccnt][fspeed]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvspeed]],*CVlist[w][gate[w].cv[gate[w].cvcnt][cvspeedmod]], w)){ // speedfunc
    LASTSPEED; // new macro to deal with lastspeed 16/6
    
    if (gate[w].func[lengthfunccnt][flength]!=0){ // so function 0 null should just hold length
    SRlength[w]=(*lengthfromsd[gate[w].func[lengthfunccnt][flength]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvlength]],w); // lengthfunc - not many?
    }

    //GSHIFT_;
    //(*gshifts[0])(w);
    (*gshifts[gate[w].func[gscnt][gs]])(w);

    // CORE
    
    if (gate[w].cv[gate[w].cvcnt][cvadcIN]==8){ // real ADC
    ADCgeneric2; // input into shared one..
    }

    // 5/7/2022 added in new function//which can generate a param but also modify SR...
    // param needs to have pointer in struct = par
    // 26/7 eg. par can select one of cvs and copy value
    
    gate[w].par=(*newfunc[gate[w].func[extfunccnt][fnew]])(4095-(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvnew]]), w); // invert?
    
    bitn^=(*adcfromsd[gate[w].func[adcfunccnt][fadc]])(4095-(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvadc]]), *CVlist[w][gate[w].cv[gate[w].cvcnt][cvadcIN]],w); // invert?
    bitn^=(*bitfromsd[gate[w].func[bitfunccnt][fbit]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvbit]], *CVlist[w][gate[w].cv[gate[w].cvcnt][cvbitcomp]],w);
    // ENDCORE
    //    if (strobey) bitn|=gate[w].trigger;	 // extra bits in if necessary or is another function
    //BITN_AND_OUTVgen_; // pulsin is in there - added new DAC - but we need alter     gate[w].shift_+=bitn; function in there/
    //final bitnout
    //
    val=(*outs[0])(bitn, w); //(*outs[gate[w].func[outcnt][out]])(bitn, w);
    new_data(val,w);
    }
  }

