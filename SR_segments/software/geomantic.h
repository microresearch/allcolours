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
uint32_t (*adcfromsd[32])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, zadcx, zadconebitsx, zadconebitsxreset, zadcpadbits, zadc12bits, zadc8bits, zadc4bits, zadceqbits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadc12onecompbits, zadc8onecompbits, zadc4onecompbits, zadconecompbits, adcselcvm, adcselcvl, probcvladcselcvm, probdacadcsel}; 

uint32_t (*dacfunc[32])(uint32_t depth, uint32_t wh)={ddac0, ddac1, ddac2, ddac3, ddac4, ddac5, ddac6, ddac7, ddac8, ddac9, ddac10, ddac11, ddac12, ddac13, ddac14, ddac15, ddac16, ddac17, ddac18, ddac19, ddac20, ddac21, ddac22, ddac23, ddac24, dacselcvl, dacselcvm};

//4bits
uint32_t (*bitfromsd[66])(uint32_t depth, uint32_t in, uint32_t wh)={zeros, binrout, binroutfixed, binroutor, zsingleroutebits, zbinrouteINVbits, zbinroutebits_noshift_transit, zbinroutebits_noshift, zbinroutebitscycle, zbinroutebitscyclestr, zbinroutebitscycle_noshift, zbinroutebitscyclestr_noshift, zbinrouteORbits, zbinrouteANDbits, zbinrouteSRbits, zbinroutebitsI, zbinroutebitsI_noshift, zbinroutebitscycleI_noshift, zbinroutebitscyclestrI, zosc1bits, sigmadelta, cipher, osceq, zSRclksr, zSRclksrG, zSRNbits, zSRLbits, zSRCbits, zSRRbits, zpulsebits, zprobbits, zprobbitsxorstrobe, zprobbitsxortoggle, zsuccbits, zsuccbitsI, zreturnbits, zreturnnotbits, zosc1bits, zwiardbits, zwiardinvbits, zTMsimplebits, zonebits, zlfsrbits, zllfsrbits, zflipbits, zosceqbitsI, zosc1bitsI, zTMsimplebitsI, zwiardbitsI, zwiardinvbitsI, zonebitsI, zlfsrbitsI, zllfsrbitsI, zflipbitsI, zpattern4bits, zpattern8bits, zpattern4bitsI, zpattern8bitsI, Rtest, gensel, binroutfixed_prob1R, binroutfixed_prob1L, binroutfixed_prob2, binroutfixed_prob3, binroutfixed_prob4, SRdelay_lineOUT}; // 

//5newfunc
uint32_t (*newfunc[32])(uint32_t depth, uint32_t wh)={zero, bitsmod, cvmod}; //


uint32_t *CVlist[4][19]={
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &CVM[0], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[0], &param[0], &Gshift_[8], &gate[0].oldcv, &gate[0].oldcvl, &gate[0].oldcvm},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &CVM[1], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[1], &param[1], &Gshift_[8], &gate[1].oldcv, &gate[1].oldcvl, &gate[1].oldcvm},
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[2], &CVL[2], &CVM[2], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[2], &param[2], &Gshift_[8], &gate[2].oldcv, &gate[2].oldcvl, &gate[2].oldcvm},
  
  {&nulll, &gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[3], &CVL[3], &CVM[3], &ADCin, &Gshift_[0], &Gshift_[1], &Gshift_[2], &Gshift_[3], &clksr_[3], &param[3], &Gshift_[8], &gate[3].oldcv, &gate[3].oldcvl, &gate[3].oldcvm}
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
  //  BITN_AND_OUTVgen_;
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

/*
void SR_geomanticxx(uint8_t w){  
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
*/

/*

new geomantic _ what we can simplify it to...

1.remove outside, gshift, think about length ops (how?), [newfunc and par?]

//// we had 8 functions

1outside - we can combine speed and general
2speedfrom
3lengthfrom X we use param for length // length from SR
4gshifts -> what they are. as switch or...
5param (do length here)
6adc - now if we have adc
7bitfrom **
8outs - ???? leave for moment as fixed...

simple model -. no param as this should be another SR  - tail maybe as param SR!

processors for SRs:

value->bits (adc) // valtobits
bits-> value (dac od SRx) // bitstoval

//paramx/length=bitstoval>>xx

//maybe we should head to 8 bits as standard for all - but speed is 10 bits, etc.... so maybe leave as is/open/recheck ADCs // leave for now but...

return to only: speedfrom, bitfrom

2.attach function on entry into new function counter (stack of these)

what stack does - stack overwrites oldest when full  - see test.c (and when is empty?)

function counter for all functions//

*/

typedef uint32_t (* funcy)(uint32_t depth, uint32_t in, uint32_t wh); // use this to simplify matters

typedef struct pair_ {
  uint32_t* cv1;
  uint32_t* cv2;
    } pair;

#define SIZEY 64 

// how to make more generic? we can also think about descending/ascending through a stack of functions which don't differentiate speed, bit etc...
//

// how to do all as one stack ?? length, end and gshift??? stack in modes.h
/*
typedef struct stack_ {
  uint32_t* bitcv1;
  uint32_t* bitcv2;
  uint32_t* speedcv1;
  uint32_t* speedcv2;
  uint32_t (*bit)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t (*speedfrom)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t bitindexy;
} stack;

// so all will share index - is that ok?!

*/


/// new template with push, pop, peek
void pushspeed(uint32_t index, uint32_t w){ // we just push index
  //  
  //  gate[w].stacky[gate[w].stackindex].speedfrom= speedfromsd[index]; // TESTING new scheme
  gate[w].speedfrom[gate[w].speedfromindex] = speedfromsd[index];
  gate[w].speedfromindex = (gate[w].speedfromindex + 1) % SIZEY;
}

void pushspeedcv(uint32_t *cv1, uint32_t *cv2, uint32_t w){
  gate[w].speedfromcv1[gate[w].speedcvindex] = cv1;
  gate[w].speedfromcv2[gate[w].speedcvindex] = cv2;
  gate[w].speedcvindex = (gate[w].speedcvindex + 1) % SIZEY;  
}

funcy peekspeed(uint32_t w){ // returns a function
  uint32_t ed=(gate[w].speedfromindex - 1 + SIZEY) % SIZEY;
  return gate[w].speedfrom[ed];
}

funcy popspeed(uint32_t w){ // returns a function // but what if there is no function?
  gate[w].speedfromindex=(gate[w].speedfromindex - 1 + SIZEY) % SIZEY;
  return gate[w].speedfrom[gate[w].speedfromindex];
}

pair peekspeedcv(uint32_t w){ //returns two pointers
  pair cvs;
  uint32_t ed=(gate[w].speedcvindex - 1 + SIZEY) % SIZEY;
  cvs.cv1=gate[w].speedfromcv1[ed];
  cvs.cv2=gate[w].speedfromcv2[ed];
  return cvs;
} 

void pushbit(uint32_t index, uint32_t w){ // we just push index
  gate[w].bit[gate[w].bitindex] = bitfromsd[index]; 
  gate[w].bitindexy=index;
  gate[w].bitindex = (gate[w].bitindex + 1) % SIZEY;
}

funcy peekbit(uint32_t w){ // returns a function
  uint32_t ed=(gate[w].bitindex - 1 + SIZEY) % SIZEY;
  return gate[w].bit[ed];
}

pair peekbitcv(uint32_t w){ //returns two pointers
  pair cvs;
  uint32_t ed=(gate[w].bitcvindex - 1 + SIZEY) % SIZEY;
  cvs.cv1=gate[w].bitcv1[ed];
  cvs.cv2=gate[w].bitcv2[ed];
  return cvs;
} 

void pushbitcv(uint32_t *cv1, uint32_t *cv2, uint32_t w){
  gate[w].bitcv1[gate[w].bitcvindex] = cv1;
  gate[w].bitcv2[gate[w].bitcvindex] = cv2;
  gate[w].bitcvindex = (gate[w].bitcvindex + 1) % SIZEY;  
}

uint32_t cvpair[64][2]={ // pairs of CVs which we index into 
  {5,6}, // eg. CV and CVL
  {5,6}, // eg. CV and CVL
  {5,6}, // eg. CV and CVL
};

uint32_t (*speedff[4])(uint32_t depth, uint32_t in, uint32_t wh)={spdfrac2,spdfrac2,spdfrac2,spdfrac2}; // why did we need to initialise this?

uint32_t (*bitff[8])(uint32_t depth, uint32_t in, uint32_t wh)={binroutfixed,binroutfixed,binroutfixed,binroutfixed,binroutfixed,binroutfixed,binroutfixed,binroutfixed}; 

uint32_t lengthindexindex[64]={6,6,6,6,6,6,6,6}; // index into CVlist which matches function index into bitfunction array -- 6 is CVL[w]
uint32_t GSlist[64]={0,0,0,0}; // matching GS types for function index
uint32_t OUTlist[64]={0,0,0,0}; // matching OUT types for function index 

// INSIDE // OUTSIDE functions
// INSIDE flips inside IN to OUTSIDE

// need to take care of which adc and which dac!
void SR_geomanticxxx(uint8_t w){  // with stacks - we push these all in init/caput000 - seems to be working // how to make more generic!
  HEADNADA;
  static pair cvs[4];
  static pair bitcvs[8];
  
  // where do we get that speedfunc and CV indexes from - from a modeR which can allow local changes or change/move from matrices...
  // but why do we have stack... as is all fixed in this change here?
  
  if (gate[w].changedspeed){ 
    //pushspeed(gate[w].speedfunc, w);
    speedff[w]=peekspeed(w);
    gate[w].changedspeed=0;
  }

  // attach 2x cv pointers which should be a pair - again abstract out how we arrive at these - 2 uint32_t pointers - lookup for these
  if (gate[w].changedspeedcv){ 
    //pushspeedcv(CVlist[w][cvpair[gate[w].speedcv][0]], CVlist[w][cvpair[gate[w].speedcv][1]], w);
    cvs[w]=peekspeedcv(w);
    gate[w].changedspeedcv=0;
  }
  
  // does it need interpol?
  if (interp[gate[w].speedfunc]){ // gate[w].func[spdfunccnt][fspeed]
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
   if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];
  
  // do speed
    if ((*speedff[w])(*(cvs[w].cv1), *(cvs[w].cv2), w)){
    LASTSPEED; // new macro to deal with lastspeed 16/6

    switch (GSlist[gate[w].bitindexy])
      {
      case 0:
	GSHIFT_;
	break;
      case 1:
	GSHIFTNOS_;
	break;
      }
	
    // CORE   
    if (w==0){ // real ADC - TESTY - how we will handle adc across all
      ADCgeneric2; // input into shared one..
      // and do ADC
      bitn=(*adcfromsd[gate[w].adcindex])(4095-(*CVlist[w][gate[w].adccvindex]), ADCin, w); // how do we select adc and its CV! // not in stack but index: for cvs too
    }
    
    // BITN
    if (gate[w].changedbit){
    //    pushbit(gate[w].bitfunc, w); // pushes chosen function onto indexy to match length etc...
      bitff[w]=peekbit(w);
      gate[w].lengthindex=lengthindexindex[gate[w].bitindexy];  // there are 64 bitfuncs - but how we access bitfunc
      gate[w].changedbit=0;
  }

    // deal with length too - length is lengthindex[stackindexfrombitfunctionbelow]
    SRlength[w]=lookuplenall[(*CVlist[w][gate[w].lengthindex])>>7];
   
    // and now we need our CVs
    if (gate[w].changedbitcv){ 
    //pushspeedcv(CVlist[w][cvpair[gate[w].speedcv][0]], CVlist[w][cvpair[gate[w].speedcv][1]], w);
    bitcvs[w]=peekbitcv(w);
    gate[w].changedbitcv=0;
  }
    
    bitn^=(*bitff[w])(*bitcvs[w].cv1, *bitcvs[w].cv2, w); // fix CVs
    // ENDCORE // what are possible OUTs? with/without DAC and     gate[w].shift_+=bitn; - we can use switch here
      switch (OUTlist[gate[w].bitindexy])
      {
      case 0:
	BITN_AND_OUTV_; // revert to this one which does not used dacfunc but gate[w].dactype which we need to set... where? TODO!
	break;
      case 1:
	BITN_AND_OUTVXOR_;
      case 2:
	BITN_AND_OUTVNOSHIFT_; // no bitn in!
	break;
      }

      new_data(val,w);
    }
}
