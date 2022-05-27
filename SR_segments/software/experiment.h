// TODO: deal with PULSIN_XOR!

// enlarge - 4096 bits=128x32 // say for 4x4096=512 4x4096=16384
static uint32_t delayline[512]; //shared delay line
static uint32_t delaylineUN[4][512]; //UNshared delay line

// define spdmodes - need to think which ones work... and maybe expand with new binroutes to 32 // 5 bits
uint32_t (*spdmodes[16])(uint32_t depth, uint8_t wh)={speedfrac, speedfrac, strobebits, binroutebits, binroutebits_noshift, binroutebits_noshift_transit, strobeint, probbits, TMsimplebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, compbits, compdacbits}; // just to test // second speedfrac is no interpol

// added new binroutes in gen.h also new speedfracint puts dac into mode
// where do we use sadcfrac?

// 2x speedfrac - one interpol, one no interpol
uint8_t interpoll[16]={1,0,0,0,0,0,1,0, 0,0,0,0, 0,0,0,0};// match above - strobeint=interpol=6

// 25/5/2022

// // TODO: or can be CV and CVL and we select binroutes and probs - x bits -

// route/type/prob for each bit but then question is wasted bits for 0 routes or single routes in...

/* matrix?
routes: 1 1 1 1
type: 0non,1gsr,2sr,3alt - 2 bits per route
= 8 bits 0-255 - try take from SR

all is bits//cv into SRetc

*/

// 1binroute_/2binroutesr_/3binroutealt/4zeroes/5shared/6nos-noshift, 7trigger, 8newaltone-noreset


//TODO: modeR manipulations: for spdcount(speedfrom), count(binroute), daccount(dacfrom) - also used for lengthfrom
/*
R- set of global routes eg. cut all routes on strobe, sync routes, bump routes etc. // what do we have already in modeR.h:

void SRRstroberoute // zero global/cut all routes on trigger
void SRRglobalbump0 // bump dacroute and binroute
void SRRglobaldac0 // dac as global route table or could be SR as route bits but we need to fix that

we need: sync counts/routes, count/route from which dac/sr?, CV/CVL
*/

// bump all spdcount, count and daccount at once on strobe
// intmode: 2 from CV, CVL, one from dac
// bump each one on strobe

// can we do spdcount and daccount also with binary?

void SR_globalbin(uint8_t w){ // global binary route for modeR. can run out fast without pulsin
  HEADSIN;
  SRlength[w]=CVL[w]>>7; // 5 bits
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  count=16; // sets to zero
  tmp=(CVL[w]>>5)&3;
  binary[0]=gate[tmp].shift_&15; // which SR? itself/runs out - binary will also need to be reset 
  binary[1]=(gate[tmp].shift_>>4)&15;
  binary[2]=(gate[tmp].shift_>>8)&15;
  binary[3]=(gate[tmp].shift_>>12)&15;
  
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// 24/5/2022

void SR_cvbits(uint8_t w){ //- if we treat all as bits then some CV should go into SRs as a mask - function for this
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_; // type of binroute
  gate[w].shift_^=CVL[w];
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// check how many bits we can hit - 6 or 7 bits is max unless is more continuous
void SR_testbits(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  if ( (CVL[w]>>5)!=16){ // 6 bitsYES, 7 bitsalmost, 8clicks  
    BINROUTE_;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// trial +- dacspeed - so we have 0-1024 10 bits and 512 is mid 0 less is minus more is plus and clip
void SRdacplusminus(uint8_t w){
  HEAD;
  int32_t cv, tmpp;
  float speedf__;
  tmpp=(CV[w]>>2)-512;
  cv=(gate[speedfrom[spdcount][w]].dac>>2) + tmpp;  
  if (cv<0) cv=0;
  else if (cv>1023) cv=1023;
  speedf__=logspeedd[cv]; // no stop
  CVOPENDACNOINTERPOL; // or with interpoll
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// what if each routed in bit has different binroute options: again q of each route as a layer but needs ghost of its straightforward layer
// ie. if we have a chain of routes then all they do is route, we need split for each
// could this be the 00 0 of the active/passive geomantics

// bit with x different options - 4 bits in, 3 bits per bit is too much, even 2 bits for different opts???

// trial select of different binroutes and routings with 7 bits
// TODO: or can be CV and CVL and we select binroutes and probs - x bits

// 1binroute_/2binroutesr_/3binroutealt/4zeroes/5shared/6nos-noshift, 7trigger, 8newaltone-noreset


void SR_binr_fixed(uint8_t w){ // fixed route but we have 3 bits for selection only??? // prob= // or sel per bit...
  HEADSIN;  
  uint32_t tmpp;
  gate[w].dactype=0; gate[w].dacpar=param[w];

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=binroute[count][w];
  SRlength[w]=lookuplenall[CVL[w]>>7]; // top 5 bits as length
  tmpp=(CVL[w]>>4)&7; // next 3 bits for binroute selection
    switch(tmpp){
    case 0:
    BINROUTEstrip_;
    break;
    case 1:
    BINROUTESRstrip_;
    break;
    case 2:
    BINROUTEaltstrip_;
    break;
    case 3:
    BINROUTEZEROstrip_;
    break;
    case 4:
    BINROUTESHAREstrip_;
    break;
    case 5:
    BINROUTENOGstrip_;
    break;
    case 6:
    BINROUTEtrigstrip_;
    break;
    case 7:
      BINROUTEnoaltstrip_;  // new one which just cycles and doesn't reset
    break;
    }

  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// or just use regular binroute options
void SR_binr(uint8_t w){ // 
  HEADSIN;
  uint32_t tmpp;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w]>>8; // top4 bits for routing itself
  tmpp=(CVL[w]>>5)&7; // lower 3 bits for binroute selection
    switch(tmpp){
    case 0:
    BINROUTEstrip_;
    break;
    case 1:
    BINROUTESRstrip_;
    break;
    case 2:
    BINROUTEaltstrip_;
    break;
    case 3:
    BINROUTEZEROstrip_;
    break;
    case 4:
    BINROUTESHAREstrip_;
    break;
    case 5:
    BINROUTENOGstrip_;
    break;
    case 6:
    BINROUTEtrigstrip_;
    break;
    case 7:
      BINROUTEnoaltstrip_;  // new one which just cycles and doesn't reset
    break;
    }

  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SR_binr_dac0(uint8_t w){ // same as above with dac=0
  HEADSIN;  
  uint32_t tmpp;
  gate[w].dactype=0; gate[w].dacpar=param[w];

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w]>>8; // top4 bits for routing itself
  tmpp=(CVL[w]>>5)&7; // lower 3 bits for binroute selection
    switch(tmpp){
    case 0:
    BINROUTEstrip_;
    break;
    case 1:
    BINROUTESRstrip_;
    break;
    case 2:
    BINROUTEaltstrip_;
    break;
    case 3:
    BINROUTEZEROstrip_;
    break;
    case 4:
    BINROUTESHAREstrip_;
    break;
    case 5:
    BINROUTENOGstrip_;
    break;
    case 6:
    BINROUTEtrigstrip_;
    break;
    case 7:
      BINROUTEnoaltstrip_;  // new one which just cycles and doesn't reset
    break;
    }

  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SR_binr_adc0(uint8_t w){ // same as above with adc=0
  HEADSIN;  
  uint32_t tmpp;
  gate[w].dactype=0; gate[w].dacpar=param[w];

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  tmp=binroute[count][w]

  tmp=CVL[w]>>8; // top4 bits for routing itself
  tmpp=(CVL[w]>>5)&7; // lower 3 bits for binroute selection
  bitn=ADC_(w,4,0,0,dacfrom[daccount][w],param[w], &gate[w].shift_);  
  switch(tmpp){
    case 0:
    BINROUTEstrip_;
    break;
    case 1:
    BINROUTESRstrip_;
    break;
    case 2:
    BINROUTEaltstrip_;
    break;
    case 3:
    BINROUTEZEROstrip_;
    break;
    case 4:
    BINROUTESHAREstrip_;
    break;
    case 5:
    BINROUTENOGstrip_;
    break;
    case 6:
    BINROUTEtrigstrip_;
    break;
    case 7:
      BINROUTEnoaltstrip_;  // new one which just cycles and doesn't reset
    break;
    }

  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


// last new modes: route from SR [4 bits]: route in can be 4 bits from one SR (shifting)// hold from GSR and shift on strobe is also option

void SR_routeSRbits00(uint8_t w){ // fixed SR for route bits: gate[dacfrom[count][w]].Gshift_[w]
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=gate[dacfrom[count][w]].shift_&15; // lowest 4 bits
  BINROUTEstrip_; // also can be different types of binroute
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SR_routeSRbits01(uint8_t w){ //CVL chooses SR for route bits (only 4 SRs so 2 bits, or we route in/xor a 4 bit route)
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w]>>8; // 4 bits
  bitrr=0;
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }
  tmp=bitrr;
  BINROUTEstrip_; // also can be different types of binroute
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SR_routeSRbits02(uint8_t w){ //CV chooses SR for route bits for SR for route bits
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w]>>8; // 4 bits
  bitrr=0;
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }
  tmp=bitrr;
  bitrr=0;
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }

  tmp=bitrr;
  BINROUTEstrip_; // also can be different types of binroute
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}



// 17/5/2022
// *how we could have layers rather than routes: routein is xor sieve and we can choose routes (q of route 0)...*
// so select route in from CVL
void SR_layer1(uint8_t w){ // also use extra bits
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>8); // lowest 4 bits - but we could use 1 extra bit for 8th
  if (tmp==0 || ((CVL[w]>>7)&1)) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01;
    gate[w].shift_ ^=gate[8].Gshare_;
    bitn^=bitrr;
    }

    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	bitn^=bitrr; // we need bitn for pulses
	gate[w].shift_ ^=gate[x].Gshift_[w];
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; // versions which just use SR and no gshift or don;t shift it
      }
      tmp=tmp>>1; // 4 bits
    }
    // clear lowest bit
    gate[w].shift_&=invmasky[0];
    BITN_AND_OUTV_; // version with own bitn add
    ENDER;
  }
  }
}

void SR_layer12(uint8_t w){ // also use extra bits - use sr for this one instaed of CVL
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  tmp=(CVL[w]>>8); // lowest 4 bits - but we could use 1 extra bit for 8th
  tmp=gate[dacfrom[count][w]].shift_&15;
    if (tmp==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01;
    gate[w].shift_ ^=gate[8].Gshare_;
    bitn^=bitrr;
  }
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	bitn^=bitrr; // we need bitn for pulses
	gate[w].shift_ ^=gate[x].Gshift_[w];
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; // versions which just use SR and no gshift or don;t shift it
      }
      tmp=tmp>>1; // 4 bits
    }
    // clear lowest bit
    gate[w].shift_&=invmasky[0];

    BITN_AND_OUTV_; // version with own bitn add    
    ENDER;
  }
  }
}

//- *trial faster one bit audio (no float) - we had this...
// try adjust mid point for sigma/delta/
void adc_onebitmidnof(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=adconebitsmid(CVL[w]>>1,w);
  bitn=adconebitsmidnof(CVL[w]>>1,w);
  //  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


// 16/5/2022
//- length from dac/lengthfrom also: speedfrom, routefrom, lengthfrom, logicfrom 
void SRX0_len(uint8_t w){ // basic route in XOR puls 
  HEADSIN;
  //  speedf_[w]=0.5f;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    SRlength[w]=lookuplenall[(dacfrom[daccount][w]>>7)];//%(CVL[w]>>7)]; // 32 is 5 bits or use CVL for something
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}


// 14/5/2022
/// try also oversample in draftspeed/ adcnull do nothing - no good

void adcnull(uint8_t w){ 
}

static inline void adcallone(uint8_t w){ // null
  uint32_t bitn;
  GSHIFT_;
    bitn=adconebitsx();
    gate[w].shift_+=bitn;
}

// try adjust mid point for sigma/delta/
void adc_onebitmid(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  bitn=adconebitsmid(CVL[w]>>1,w);
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// 13/5/2022

// try for oversample - run 1 bit at full speed...
void adc_overonebit(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  bitn=adconebitsx();
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// some alt binroutes

// reflect - sr cycles in opposite direction with incoming bitn from gshift or... >>
void SR_reflect(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
	bitn^=gate[w].localGSR[x]&0x01;
	gate[w].localGSR[x]=(gate[w].localGSR[x]>>1)+(bitrr<<SRlength[x]);
      }
      tmp=tmp>>1; // 4 bits
    }

  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

//eg. we keep cycling in until we finish one length and there is a reset
void SR_altbin1(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=binroute[count][w];
    for (x=0;x<4;x++){
      if (tmp&0x01){  
	if (gate[w].gsrcnt[x]<0){
	  gate[w].gsrcnt[x]=SRlength[x];
	  
	  if (gate[x].reset[w]){
	    gate[w].localGSR[x]=gate[x].Gshift_[w];
	    gate[x].reset[w]=0;
	  }
	}
	bitrr = (gate[w].localGSR[x]>>gate[w].gsrcnt[x]) & 0x01;
	gate[w].gsrcnt[x]--;
	bitn^=bitrr;
      }
    tmp=tmp>>1;
    }
  
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

//maybe new GSHIFT_ with selective updates - can also be mask (from where?) - not so exciting
void adc0_altgshift(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    //  GSHIFT_;
    
    gate[w].Gshift_[0]=gate[w].shift_ & clksr_[w];
    gate[w].Gshift_[1]=gate[w].shift_ & clksr_[w];
    gate[w].Gshift_[2]=gate[w].shift_ & clksr_[w];
    gate[w].Gshift_[3]=gate[w].shift_ & clksr_[w];
    
    gate[w].reset[0]=1; gate[w].reset[1]=1; gate[w].reset[2]=1; gate[w].reset[3]=1;
    gate[w].Gshare_=gate[w].shift_;
    gate[w].shift_=gate[w].shift_<<1;
    
    
  //  bitn=probbitsxortoggle(CVL[w],w);
    bitn=ADC_(w,SRlength[w],0,bitn,dacfrom[daccount][w],param[w], &gate[w].shift_);  
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// 12/5/2022
// if we are slower than route in: delay line, intercepted value, overlap?
// if we are faster: same as we have, cycle gsr or just hold sr value

// only advance if one of routed in advances (caught if is zero or only itself)
void SR_binspdx(uint8_t w){ // TODO: make use of CV here - just a trial model
  HEAD;
  CVOPENNOINTERPOL;
  if(gate[inroute[count][w]].reset[w])
    {
      gate[inroute[count][w]].reset[w]=0;
      GSHIFT_;
      BINROUTE_;
      BITN_AND_OUTV_;
      ENDER;
    }
}
  
// further if we are faster then insert a zero sample
void SR_insert_zero(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  //  BINROUTE_;
  // route in and deal with reset gate[w].reset[0]=1;
  BINROUTEZERO_;
  
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SR_insert_zero_dac2(uint8_t w){ // 
  HEADSIN;
  gate[w].dactype=2; gate[w].dacpar=4096-CVL[w]; //     betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
  if (speedf_[w]!=2.0f){
  CVOPENNOINTERPOL;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  //  BINROUTE_;
  // route in and deal with reset gate[w].reset[0]=1;
  tmp=binroute[count][w];   
  for (x=0;x<4;x++){
    if (tmp&0x01){
      if (gate[x].reset[w]){
      bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
      gate[x].reset[w]=0;
      }
      else bitrr=0;
      bitn^=bitrr;
    }
    tmp=tmp>>1; // 4 bits
    }
  
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// 11/5/2022
static inline uint32_t delay_line_in(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits[4]; // 32 bits of bits
  // put into delay line - need index and bit index
  tmp=bits[wh]/32;
  tmpp=bits[wh]%32;
  delaylineUN[wh][tmp]&=bitmasky[tmpp];
  delaylineUN[wh][tmp]|=(depth<<(tmpp));
  bits[wh]++;
  if (bits[wh]>16383) bits[wh]=0;
}

static inline uint32_t delay_line_out(uint32_t depth, uint8_t wh){
  uint32_t bt=0, tmp;
  tmp=depth/32;
  bt=(delaylineUN[wh][tmp]>>(depth%32))&0x01;
  return bt;
}

// incoming always into circular delay line and we pick these off at speed...
// what are other options for incoming-> in or outside speed...

// if we are slower than route in: delay line, intercepted value, overlap?
// if we are faster: same as we have, cycle gsr or just hold sr value

void SRdelay_lineIN(uint8_t w){  // could also be shared version of this
  HEADSIN;
  static uint32_t cnt=0;
  BINROUTESR_; // or other forms
  delay_line_in(bitn,w);

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=delay_line_out(cnt,w); // or detach - length not used - this is our binroute
  cnt++;
  if (cnt>16383) cnt=0;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// other option is previous into delay_line and then we pickup from last counter - but then modes need to agree or always write into delay// too complex
// so each SR has a buffer... or 4 sets of buffers???
// for basic routing say one buffer and count

void SRintodel(uint8_t w){ // 
  HEAD;
  uint32_t tmpp;
  
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_; // or not
  // fill bitn into delay and advance delcnt
  // put into delay line - need index and bit index
  tmp=gate[w].delcnt/32;
  tmpp=gate[w].delcnt%32;
  gate[w].delay[tmp]&=bitmasky[tmpp];
  gate[w].delay[tmp]|=(bitn<<(tmpp));
  gate[w].delcnt++;
  if (gate[w].delcnt>16383) gate[w].delcnt=0;  
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// needs own delcnt
void SRfromdel(uint8_t w){ // null unfinished
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn^=
  //  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


// 10/5/2022

// prob for 2 sorts of binroute/or toggle between the two
void SR_probbin(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round?
      BINROUTE_;
  }
  else {
    BINROUTEalt_;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


// bitdsp resetting thing: adconebitsreset(uint32_t depth, uint8_t w) - but that adds w which other gens in adcetc don't have...
// test it here
void adcone_bitreset(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adconebitsreset(CVL[w],w);
  BINROUTE_; // with binroute disturbs one bit audio but...
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// 9/5/2022

// check slowest speed
void SRspeedtest(uint8_t w){ // null
  static uint32_t tgg=0;
  HEADSIN;
  speedf_[w]=logspeedd[CV[w]>>2]; // 10 bits
  //  speedf_[w]=slowerlog[CV[w]>>2]; // 10 bits
  gate[w].time_now += speedf_[w];
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;

  if(gate[w].last_time<gate[w].int_time)      {
    tgg^=1;
    if (tgg==1) gate[w].dac=4095;
    else gate[w].dac=0;
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;	

  }
}

// 6/5/2022
//- try alt gshift which keeps intact gsr (cycle through but we need to signal reset)
// [as gsr as we have it can be destructive if we change lengths]
/*
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
*/

void SRX0_newgsr(uint8_t w){ // basic route in XOR puls
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPENNOINTERPOL;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_; // resets added to macro 9/5/2022
    BINROUTEalt_;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// can also  be variation where we don't use reset//keep cycling... show all gsr options, gsr of gsr etc...
// 
void SRX0_newgsr_nores(uint8_t w){ // basic route in XOR puls
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPENNOINTERPOL;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_; // resets added to macro 9/5/2022
    tmp=binroute[count][w];
    for (x=0;x<4;x++){ 
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>gate[w].gsrcnt[x]) & 0x01; 
	gate[w].gsrcnt[x]--;
	if (gate[w].gsrcnt[x]<0) gate[w].gsrcnt[x]=SRlength[x];
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }

    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// and now for adc
void adc0_newgsr(uint8_t w){ // basic route in XOR pulse and ADC0
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPENNOINTERPOL;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_; // resets added to macro 9/5/2022
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
    tmp=binroute[count][w];
    for (x=0;x<4;x++){ 
      if (tmp&0x01){
	if (gate[x].reset[w]){
	  gate[x].reset[w]=0;
	  gate[w].gsrcnt[x]=SRlength[x];
	}
	bitrr = (gate[x].Gshift_[w]>>gate[w].gsrcnt[x]) & 0x01; 
	gate[w].gsrcnt[x]--;
	if (gate[w].gsrcnt[x]<0) gate[w].gsrcnt[x]=SRlength[x];
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// 4/5/2022

// processors for values eg. holds of speeds... SRproc_hold(uint32_t depth, uint32_t bit){  // bit=value, depth=how long
void SRholdspd(uint8_t w){ // sample and hold on speed
  HEADNADA;
  speedf_[w]=logspeedd[SRproc_hold(CVL[w]<<2, CV[w])>>2]; // detached
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
}

// trial own bits inverted to speed - not so successful with binroute...
void SRownspd(uint8_t w){ // use of CV[w] as binroute
  HEAD;
  tmp=scycle(w);
  if (gate[w].trigger) tmp=!tmp; 
  if (tmp){
  GSHIFT_;
  //  BINROUTE_;
  bitn=binroutebits(CV[w],w);
  PULSIN_XOR;
  BITN_AND_OUTVINT_;
  }
}


// 3/5/2022
// how can we deal with idea of:
/*
1-if [x] bitfrom[y1] 
2-if [if [x] bitfrom[y1]] bitfrom[y2]
3-if [if [if [x] bitfrom[y]] bitfrom[y]] bitfrom[y]
4-if [if [if [if [x] bitfrom[y]] bitfrom[y]] bitfrom[y]] bitfrom[y]

just as logical oppp - AND of bitfroms - needs some variations - calls new bits in action...

layered binroutes... 

if (sbinroute(others[w][0])) bitn=sbinroute(others[w][1]);
if (bitn) bitn=sbinroute(others[w][2]);
if (bitn) bitn=binroutebits(uint32_t depth, uint8_t wh)			       

//or pass down in cycle.

if bitfromC bitn=binroutebits... or generator...

*/
// trial - untie routes...? - layers from geomantic cards...
void SR_recbin(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  bitn=binroutebits(CVL[w],w); // how these layers can differ - 4 layers... 
  if (bitn){ 
    bitn=binroutebits(CVL[w],w); 
  }
  if (bitn){
    bitn=binroutebits(CVL[w],w);
  }
  if (bitn){
    bitn=binroutebits(CVL[w],w);
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


// routes in as elements of split speeds - sbinroute
void SR_splitx(uint8_t w){ // 3 params for spdfrom, length, spdmode // + 2 for bitn// =5params//// +2 for prob
  HEAD;
  uint32_t tmpp;
  uint8_t spdfrom=0;  // fixed as usual speed
  //  SRlength[w]=PARAM2?; // length is CVL
   
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (!sbinroute(others[w][0])) { // inversion to avoid running out
      GSHIFTNOS_; // 2.copy gshift on trigger // gate[XX].Gshift[w]&0x01...
    }

  if (!sbinroute(others[w][1])) { //3.advance incoming ghost
    BINROUTEADV_;
  }

  if (!sbinroute(others[w][2])) {
    gate[w].shift_=gate[w].shift_<<1; // 1. shifter
  }

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }
  
  if (spdmodes[spdfrom](CV[w],w)){ 
    //    bitn=abstractbitstreamslong[PARAM4?](PARAM5?,w); // without even getting into prob
    BINROUTENOG_; // or not

    PULSIN_XOR;
    BITN_AND_OUTVXOR_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// trial static inline uint32_t SRproc_hold(uint32_t depth, uint8_t bit){
void SRhold(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  bitn=SRproc_hold(CVL[w]>>4,bitn);
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SRholdfromdac(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  tmp=gate[dacfrom[count][w]].dac%(CVL[w]+1);
  bitn=SRproc_hold(tmp>>4,bitn);

  ENDER;
  }
  }
}


// 2/5/2022

// TODO: spd from 1/theothers, routefrom 2/theothers, prob/logic from 3/theothers...
// spdfrom->gate[others[w][0]].dac
// but then where do bits actually come from...??? and what do we use CVs for...
// generic spdfrom_binroute[x]
// spd as bits or as value/dac
// trial as bits - binroutebits

void SRothers(uint8_t w){ // length could also be as value/probability against 
  HEAD;
  tmp=CV[w]>>6; // 3x 2 bits =6
  if (singleroutebits((tmp&3)<<10, w)){ //speed
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  // BINROUTE_;
  if (singleroutebits(((tmp&12)>>2)<<10, w)){ //prob
    bitn=singleroutebits(((tmp&48)>>4)<<10, w); // route
			 }
    else {
      JUSTCYCLE_;
      bitn=!bitn; /// added so runs better
    }
  PULSIN_XOR;
  BITN_AND_OUTVINT_;
    }
    }
// variations - would be nice with 4 layers... 4x2 8 bits though...


// trial of dacbus... modeC manipulates this mix...
// straight route in so we need params for who to add and maybe type of dac
void dacbus(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>6; // 6 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp>>2, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if ((tmp>>4)!=w) val+=gate[tmp>>4].dac; //other dac... // how change modes for other dacs... or not - but which dac - and not itself
    if (val>4095) val=4095;
    BITN_AND_OUTNODAC_;
    ENDER;
  }
  }
}
// variation1 - possible 4 layers of dacs... itself, 1, 2, 3 - how to stack... // 2 bits... // strobe bumps up
// others[4][3]={ all but itself
void dacbusothers(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>5; // 7 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp>>3, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if ((tmp>>4)&1) val+=gate[others[w][0]].dac; // 3 bits - TODO: try also shift out clkbits - any set of 3 bits
    if ((tmp>>5)&1) val+=gate[others[w][1]].dac;
    if ((tmp>>6)) val+=gate[others[w][2]].dac; 
    //    if (val>4095) val=4095;
    // or
    val=val%4095;
    BITN_AND_OUTNODAC_;
    ENDER;
  }
  }
}

// using the others clkbits
void dacbusothers_clk(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>8; // 4 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if (clksrG_[others[w][0]]&1) val+=gate[others[w][0]].dac; // 3 bits - TODO: try also shift out clkbits - any set of 3 bits
    if (clksrG_[others[w][1]]&1) val+=gate[others[w][1]].dac;
    if (clksrG_[others[w][2]]&1) val+=gate[others[w][2]].dac; 
    //    if (val>4095) val=4095;
    // or
    val=val%4095;
    BITN_AND_OUTNODAC_;
    ENDER;
  }
  }
}

void dacbusothers_sr(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>8; // 4 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if (gate[others[w][0]].shift_&1) val+=gate[others[w][0]].dac; // 3 bits - TODO: try also shift out clkbits - any set of 3 bits
    if (gate[others[w][1]].shift_&1) val+=gate[others[w][1]].dac;
    if (gate[others[w][2]].shift_&1) val+=gate[others[w][2]].dac; 
    //    if (val>4095) val=4095;
    // or
    val=val%4095;
    BITN_AND_OUTNODAC_;
    ENDER;
  }
  }
}

void dacbusothers_own(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>6; // 6 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp>>2, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if (gate[tmp>>4].shift_&1) val+=gate[others[w][0]].dac; // 3 bits - TODO: try also shift out clkbits - any set of 3 bits
    if ((gate[tmp>>4].shift_>>1)&1) val+=gate[others[w][1]].dac;
    if ((gate[tmp>>4].shift_>>2)&1) val+=gate[others[w][2]].dac; 
    //    if (val>4095) val=4095;
    // or
    val=val%4095;
    BITN_AND_OUTNODAC_;
    ENDER;
  }
  }
}


// 28/4/2022

// for speedfrom what options we have:
// [gens=strobe/prob/clksr/DACs/binroute->which route?]
// in speedfrac we have depth as CV[w] or dac/speedfrom... but we could make specific functions... - prob is special case but we can use CV[w] against ???
// against DAC, against LFSR

// speeds with no params....
// as functions: 
uint32_t (*speedfroms[8])(uint8_t wh)={sadcfrac, sdacfrac, sstrobe, sstrobeint, sbinroute, sprob, sprobdac, sclksr}; // sycycle also...
uint8_t interpolll[8]={1,1,0,1, 0,0,0,0}; // new one to match above
uint8_t freecv[8]={0,1,1,1, 1,0,0,1}; 

// new template following this:
void SR_speedx(uint8_t w){ // using speedfroms and CV[w] in fracs and probs.. otherwise not... so we can free it check freecv above
  HEAD;
  uint32_t tmpp;
  uint8_t spdfrom=1; // fixed 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test
  if (interpolll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }


  if (speedfroms[spdfrom](w)){ 
    GSHIFT_;
    if (freecv[spdfrom]) // do what with it? eg. route/ or use as probability
      {
	bitn=binroutebits(CV[w],w);
		 }
    else {
    BINROUTE_; // or not
    }
    // do dac for non-interpols
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// test SRclksrG ghosts
void SR_clksrG(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=SRclksrG(SRlength[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// test SRclksr
void SR_clksr(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=SRclksr(SRlength[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


// 27/4/2022

//- *hold/perform last function with frozen params but change say length as CVL?*
// how??? - how do we enter? is more a case of freezing last param which was CVL and using for length
// what means last function?

// so we would need paramx[w] 
// doesn't make sense as we have it....
// we need to freeze on entry // but unfreeze on exit/change... marked in SR...
void SR_genspeed2(uint8_t w){
  HEAD;
  uint32_t par;
  if (gate[w].changed) gate[w].paramx=CVL[w]; // if we want -  but only on entry // this can also be on trigger - try below
  // or freeze for length
  SRlength[w]=lookuplenall[CVL[w]>>7];
  uint8_t spdfrom=gate[w].paramx>>7; // 5 bits 
  gate[w].dactype=0; gate[w].dacpar=param[w]; 

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }

  if (spdmodes[spdfrom](CV[w],w)){
    GSHIFT_;
    // ACTION!
    bitn=abstractbitstreamslong[spdfrom](CV[w],w); // without even getting into prob
    //    BINROUTE_; // how to chain in binroutebits (and param for that)

    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

void SR_genspeed3(uint8_t w){ // working now
  HEAD;
  uint32_t par;
  if (gate[w].trigger) gate[w].paramx=CVL[w]; // if we want -  but only on entry // this can also be on trigger - try below
  // or freeze for length
  SRlength[w]=lookuplenall[CVL[w]>>7];
  uint8_t spdfrom=gate[w].paramx>>8; // 4 bits 
  gate[w].dactype=0; gate[w].dacpar=param[w]; 

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }


  if (spdmodes[spdfrom](CV[w],w)){
    GSHIFT_;
    // ACTION!
    //    bitn=abstractbitstreamslong[spdfrom](CV[w],w); // without even getting into prob
    BINROUTE_; // how to chain in binroutebits (and param for that)

    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// towards generic sets of functions but...

// *[how to abstract bit choice of DACs, CVL, CV, SR raw, past SR, clksr_, with masks for 12 bits?, tails... more pointers?]*
uint32_t *CVlist[4][16]={
  {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[0], &CVL[0], &gate[0].Gshift_[0], &clksr_[0]},
    {&gate[0].dac, &gate[1].dac, &gate[2].dac, &gate[3].dac, &CV[1], &CVL[1], &gate[0].Gshift_[1], &clksr_[1]}
};

// test this with binroutebits TESTED!
void SR_test(uint8_t w){ // null
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=binroutebits(*CVlist[w][5],w);
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

/*
- store previous SR value (every time or...), rotating store, also what happened to our longer storage? // dac value or whole SR
past state of all SRs (5th tail doubled)

previous dac, previous bit, previous SR - what to do with these...

longer storage was: Gshift_rev: used in: void SRN46(uint8_t w){ //- cycling array of ghosts toggle in/how to toggle out // return????
- but wastes so much as change is one bit ...

delayline would make more sense and bitn goes in - shared delayline or otherwise... - sketch this out
*/

void SRghost(uint8_t w){ // needs something as CVL seems not do much
  HEADSIN;
  uint32_t tmpp,depth;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;

  // trial here with strobe as revenant but from where?
  //  if (gate[w].trigger){
    depth=gate[w].index+CVL[w];
    if (depth>=4095) depth-=4095;
    tmp=depth/32;
    bitn=(gate[w].delay[tmp]>>(depth%32))&0x01;
    //  }

  BINROUTE_; // or not
  //   // always write or only on strobe
  // if always then goes into OUTV_ below...
  ///  gate[w].delay and index
  if (gate[w].trigger){
  tmp=gate[w].index/32;
  tmpp=gate[w].index%32;
  gate[w].delay[tmp]&=bitmasky[tmpp];
  gate[w].delay[tmp]|=(bitn<<(tmpp));
  gate[w].index++;
  if (gate[w].index>4095) gate[w].index=0;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SRghostlatch(uint8_t w){ // needs something as CVL seems not do much - added in latch to test
  HEADSIN;
  uint32_t tmpp,depth;
  if (gate[w].trigger) gate[w].latch=1;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;

  // trial here with strobe as revenant but from where?
  //  if (gate[w].trigger){
    depth=gate[w].index+CVL[w];
    if (depth>=4095) depth-=4095;
    tmp=depth/32;
    bitn=(gate[w].delay[tmp]>>(depth%32))&0x01;
    //  }

  BINROUTE_; // or not
  //   // always write or only on strobe
  // if always then goes into OUTV_ below...
  ///  gate[w].delay and index
  if (gate[w].latch){
    gate[w].latch=0;
  tmp=gate[w].index/32;
  tmpp=gate[w].index%32;
  gate[w].delay[tmp]&=bitmasky[tmpp];
  gate[w].delay[tmp]|=(bitn<<(tmpp));
  gate[w].index++;
  if (gate[w].index>4095) gate[w].index=0;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// lots of options for multiple streams and addition/xor
// also from bitdsp add 2 streams - part of stream/SR with/out carry or inc carry...
// binroute of the carry... carry is one bit over length<<1
/* // from bitDSP.lib
           s_out = xor(rint(c_in), xor(rint(x1), rint(x2)));
           c_out = (rint(c_in) & xor(rint(x1), rint(x2))) | 
      (rint(x1) & rint(x2));

= simpler carry is an AND
*/

// 2 routes into one//XOR full TRY!

// trial 2 other routes (select=4 bits) XORed=added 
// same more or less as binroute with extra 2 bits XOR in 

void SRxorSR(uint8_t w){
  HEADSIN;
  uint32_t tmpp;
  uint8_t spdfrom=0; //set.choose - here is frac
  gate[w].dactype=0; gate[w].dacpar=param[w]; 

  if (interpoll[spdfrom])   { 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }


  if (spdmodes[spdfrom](CV[w],w)){
    GSHIFT_;
    // 4 bits binroute
    tmpp=CVL[w]>>6; // 6 bits
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    // 2 top bits add XOR route
    tmpp=tmpp>>4;
    bitrr = (gate[tmpp].Gshift_[w]>>SRlength[tmpp]) & 0x01; 
    gate[tmpp].Gshift_[w]=(gate[tmpp].Gshift_[w]<<1)+bitrr; 
    bitn^=bitrr;

    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

uint32_t xorroutes[4][2]={
  {3,2},
  {0,3},
  {1,3},
  {0,1}
};
// or bitstream//sel=4or5bits decides if we XOR/add (1bit) in 2 streams which become this one TRIAL
// streamx=streamy+streamz // streamx=streamy^streamz // - how we select those and we need a bitn for pulses - or they are fixed..
// simpler trial version
void SRxorroutes(uint8_t w){ // XOR in 
  HEAD; 
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  // copy mask of bits from inroute
  if (gate[w].trigger){ 
    
    GSHIFTNOS_; 
    gate[w].shift_= (gate[xorroutes[w][0]].Gshift_[w]) ^ (gate[xorroutes[w][1]].Gshift_[w]); 
    // and we need bitn so shift
    bitn=CYCl;
    SHFT;
    BITN_AND_OUTV_;
  }
  else
    {
      GSHIFT_;
      BINROUTE_; 
      BITN_AND_OUTV_;
    }
  ENDER;
  }
  }
  }

void SRaddroutes(uint8_t w){ // how to add without overflow - long
  HEAD;
  long temp;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  // copy mask of bits from inroute
  if (gate[w].trigger){ 
    
    GSHIFTNOS_; 
    temp = (gate[xorroutes[w][0]].Gshift_[w]) + (gate[xorroutes[w][1]].Gshift_[w]);
    gate[w].shift_=(temp&masky[SRlength_[w]]); //
    // and we need bitn so shift
    bitn=CYCl;
    SHFT;
    BITN_AND_OUTV_;   
  }
  else
    {
      GSHIFT_;
      BINROUTE_; 
      BITN_AND_OUTV_;
    }
  ENDER;
  }
  }
  }

// also variations of these...
// we have this one which is XOR another route into our own...
/*
void noSRxorroutes(uint8_t w){ // XOR in // null
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  // copy mask of bits from inroute
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round?
    
    GSHIFTNOS_; // why is no copy? to avoid ???
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
    if (tmp&0x01){ // use length for something else? prob?
      gate[w].shift_^= (gate[x].Gshift_[w]); // or length of that mask is another parameter - strobe mode - but that length doesnt do much except stop
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;   // dont add in bitn
  }
  else
    {
      GSHIFT_;
      JUSTCYCLE_; // or could be BINROUTE
      PULSIN_XOR;
      BITN_AND_OUTV_;
    }
  ENDER;
  }
  }
  }
*/


// 26/4/2022
// no major modes on R/maybe - but how we can achieve eg. vienna-like modes (6/12 bits)
// what was vienna scheme again?
/*
6 bits/64 modes: 1 1 1 1 1 1 - in original was from CV
- top bit/speedfrom (strobe or CV - if strobe then use CV as param...
- 4 bits routing in
- 1 bit do prob of inversion
*/
void SR_vienna(uint8_t w){  
  HEADSIN; // detach length
  uint32_t tmpp, tmppp;
  uint8_t spdfrom; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test
  // 6 bits from CV or DAC
  tmpp=CVL[w]>>6; // detached length
  if (tmpp>>5) // top bit
    {
    spdfrom=2; // strobe
    tmppp=CV[w]; // from CV/speed
    }
  else {
    spdfrom=0; // fractional speed.
    tmppp=param[w]; // param from clock
  }
    
  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }

  if (spdmodes[spdfrom](CV[w],w)){  // we dont use CV for strobe
    GSHIFT_;
    // bitn opp can be inserted... eg. LFSR
    // XX
    // 4 bits for route
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }

    // and prob thing
    /*
    doit[w]=(mode[w]>>4)&0x01; // top bit maybe
    if (doit[w] && dac[whichdoit[w]]<param) bitn^=1; //     if (tmp<adc_buffer[0]) bitn^=1; - 12 bits TO TEST!
    */
    if ((tmpp>>4)&0x01) {
      if (gate[dacfrom[count][w]].dac<tmppp) bitn^=1;
	}
      
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}



// switch by CV between CVspeed and strobe speed
// or could be simple prob/bit switch. - new twist of if (bitstream) spdfrom=
// but we run out of CVs- 1speed, CVL-selectbitstream, param for bitstream... - which now is dac - heading in new direction/abstract furtherTODO!
// and think of length
// also how prob is extracted into bitsfrom - how to chain bitsfrom: eg.  bitsprob decides spdfrom of bitsotherprob entry of bitsmode etc...
// bit chain IS the 4 SRs in some configuration?
void SR_switchspeed(uint8_t w){  
  HEADSIN;
  uint32_t tmpp;
  uint8_t spdfrom; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test
  tmp=CVL[w]>>7; // 5 bits 
  tmpp=abstractbitstreamslong[tmp](CV[w],w);
  if (tmpp) spdfrom=0; // alternatives
  else spdfrom=2;
  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](gate[speedfrom[spdcount][w]].dac,w)){ // replace CV[w] with dac?
    GSHIFT_;
    BINROUTE_; // or not
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

//uint32_t (*spdmodes[16])(uint32_t depth, uint8_t wh)={speedfrac, speedfrac, strobebits, binroutebits, binroutebits_noshift, binroutebits_noshift_transit, strobeint, probbits, TMsimplebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, compbits, compdacbits}; // just to test - tested
// how many more could we use?

//select spdmode - select our speedmode with CV/L?
void SR_selspeed(uint8_t w){ // TEST!
  HEADSIN;
  uint32_t tmpp;
  uint8_t spdfrom; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test
  spdfrom=CVL[w]>>7; // 4 bits 16 ops - could be more... trial... // tested // now try abstract // was 4 bits
  //  spdfrom=11;
  if (interpoll[spdfrom])   { // and if we don't use CV?
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  //  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w]
  if (abstractbitstreamslong[spdfrom](CV[w],w)){ // testing was just spdmodes and 4 bits/16 operations
    GSHIFT_;
    BINROUTE_; // or not
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// 25/4/2022

// xortoggle-PROBability mode xor strobe in gen.h
void SRprobxortog(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (probbitsxortoggle(CVL[w],w)) {
      BINROUTE_; // or not
    }
    else
      {
	JUSTCYCLE_;
      }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// other version of above
void SRprobxortogx(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

/// how to do interpol for non-frac modes... AGAIN these need speed being copied over for necessary modes
void SR_strobeint(uint8_t w){ // testing - not sure... this is generic one as all we have is spdfrom=6 /// try other spdmodes here
  HEAD;
  uint32_t tmpp;
  uint8_t spdfrom=8;  // strobeint
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    GSHIFT_;
    BINROUTE_; // or not
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// pattern match bitstream from bitdsp: if pattern of length matches then flip bit eg... as gen?
// match lower parts of lengthx, from 2 other SRs (4 bits) - flip incoming bit if match
// so is either as strobe or detached/// CVL // but where we get length cv? or use 2 bits length <<1 and 4 comp
void SRmatch(uint8_t w){ // pattern matcher - could be longer pattern
  HEADSIN;
  uint32_t tmpp;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w]>>6; // 6 bits
  tmpp=masky[(tmp>>4)]; // top 2 bits
  if ( (gate[tmp&0x03].Gshift_[w]&tmpp)==(gate[((tmp&12)>>2)].Gshift_[w]&tmpp)) val=1;
  else val=0;
  BINROUTE_; // or not
  if (val) bitn=!bitn; // invert // or can be other op/choice... abstract out!
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// abstract out for different spdmodes eg. strobe here...
void SRmatch_strobe(uint8_t w){ // testing - we free length and use spd for sel
  HEAD;
  uint32_t tmpp;
  uint8_t spdfrom=2;  // strobe
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    GSHIFT_;
    tmp=CV[w]>>8; // 4 bits
    tmpp=masky[31-(CV[w]>>7)]; // 5 bits - could also be double match with tmpp as no/mask
    if ( (gate[tmp&0x03].Gshift_[w]&tmpp)==(gate[(tmp>>2)].Gshift_[w]&tmpp)) val=1;
    else val=0;
    BINROUTE_; // or not
    if (val) bitn=!bitn; // invert // or can be other op/choice... abstract out!

    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// 22/4/2022

// think about abstractions and grids///printing maybes....
// slides and splits - grids of modes and params/values and entry of SRs into these...
// shall we look again at rung in rungler

// RSR master mode: cut all routes // open close route bit with clock/toggle

// uses count to set binroute to 16 // only for right hand side - we had/have this in modeR: SRRstroberoute
void SRRcutallroutes(uint8_t w){  
  HEAD;
  if (gate[w].trigger) count=16; // placed outside speed
  else count=0;

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SRRtoggcutallroutes(uint8_t w){ // toggle version of above
  HEAD;
  static uint8_t toggle=0;
  if (gate[w].trigger) toggle^=1;

  if (toggle) count=16; // placed outside speed
  else count=0;

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// can also have prob and binroute/generator versions but these run in SR speed itself
// again how to generalise that kind of structure
void SRRbinrcutallroutes(uint8_t w){  
  HEADSIN; // we use CVl for param in
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;

  if (binroutebitsI(CVL[w],w)) count=16; // placed inside speed
  else count=0;
  
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// 21/4/2022

// experiment with shared bits
// define - so generator accesses a bit (X) and shares that with next caller of that bit

static uint32_t sharedindexes[4]={0,0,0,0};
static uint32_t bufferd[1024];
static uint32_t head;

// tested in test3.c 22/4/2022
static inline uint32_t shared(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  static int32_t bc=31;
  static uint32_t k;

  sharedindexes[wh]++;

  if (resetz==1){
    head++;
    if (head>1023) head=0;

    // new bit - can also be passed to other generators
    if (bc<0) {
      ADCgeneric;
      k=k>>8;
      bc=3; 
    }
    bt = (k>>bc)&0x01; // this means that MSB comes out first
    bc--;
    
    bufferd[head]=bt;
    resetz=0; 
  }

  if (sharedindexes[wh]>1024) sharedindexes[wh]=0;
  bt=bufferd[sharedindexes[wh]];
  return bt;
}

void SRshare(uint8_t w){ // shared bits
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=shared(SRlength[w],w); // doesn't use length
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// see    (*moodsfuncs[0])(www, &moodsw[0]);  below - but no interpol there... -> re-work that with  what we have here for interpol
// MOVED it up here...

// attempting more generic - so we can define a mode within grid of functions, plug in parameters, and logic
// or SRitselftry2 is a function too eg:
// func(uint8_t w, moods *mode) - but can we pass in structure itself - as doesn;t know itself
// but we could pull that out into function array like so:

//void (*moodsfuncs[64])(uint8_t w, moods *mode)={SRitselftry2}; // list of functions and then we can call for example    (*dofunc[www][mode[www]])(www);
//   (*moodsfuncs[0])(www, &moodsw[0]); // mode=0

typedef struct moods_ { //
  //  void (*func)(uint8_t w, moods *mode);
  uint8_t gsfr;
  uint8_t spdfr;
  uint8_t probfr;
  uint8_t incfr;
  uint8_t incor;
  uint8_t last;
  uint32_t *par0, *par1, *par2, *par3, *par4; // to add in for length also
  uint8_t (*logic)(uint8_t bit1, uint8_t bit2);
} moods;

uint8_t XOR_(uint8_t bit1, uint8_t bit2){
  uint8_t res;
  res=bit1^bit2;
  return res;
}

//
////... SRitselftry2(0, &moodsw[0]);
//
static moods moodsw[64]={ // unused...
  {0,0,0,0,0,0, CV,CV,CV,CV,CV, XOR_}, // test - frs are refs to array, but problem is pars - as refs to CV[w] or gate[w].dac --
}; // how to do refs to dacs
// WE would need to change that ref... so is owndac[w] across all files... TODO? if we decide

// so each mode is defined by 5x5bits (decision functions 1,0), 5 CV sources (DAC or CV), and one logic function (say: AND, XOR, leak, OR)
// where does this get us?

// how can we combine decison functions logically? a chain of... but this would be another function??
// more of a model which is about bitstreams and combinations of bitstreams

/*

  if (stream1){  // spd
  gate[w].shift_=gate[w].shift_<<stream0 // in or outside
    if (stream2){ // prob
      bitn=stream3; // in?
    }
    else
      { 
	bitn=stream4; // inor?
      }
  bitn=mode->logic(bitn, stream5); // pulsin
}

// how that can be split across multiples...

 */

// but this has no interpol - 20/4/2022 -adding now!/21/4
void SRitselftry2(uint8_t w, moods *mode){ // pass in structure - // null
  HEADNADA; // detach depending on what/
  uint8_t interpol=0; // resolve this - figure out from spdfrom bits

  if (interpol)   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  
  if (abstractbitstreamslong[mode->spdfr](mode->par1[w], w)){  // spd - for intmodes we can lose this // moved speed UP
  GSHIFTNOS_;
  /// CORE
  gate[w].shift_=gate[w].shift_<<(abstractbitstreamslong[mode->gsfr](mode->par0[w], w)); // is this within outer spd? we could have different versions
    if (abstractbitstreamslong[mode->probfr](mode->par2[w], w)){ // prob
      bitn=abstractbitstreamslong[mode->incfr](mode->par3[w], w); // what?
    }
    else
      { 
	bitn=abstractbitstreamslong[mode->par3[w]](mode->par3[w], w); // or?
      }
  
  bitn=mode->logic(bitn, abstractbitstreamslong[mode->last](mode->par4[w], w)); 
  ///  
    if (!interpol){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTVNOSHIFT_; // part of interpol - val=DAC but fits for all - now without +bitn
    new_data(val,w);
  }
}

// earlier abstraction
// question is how to avoid running same functions twice in abstractbitstreams-> unless we want to
// also here we have 5 parameters

// still thinking on some kind of grid!

/*
void SRitselftry2(uint8_t w, moods *mode){ // pass in structure - null
  HEADSSINNADA; // detach depending on what/
  if (abstractbitstreamslong[mode->spdfr](mode->par1[w], w)){  // spd - for intmodes we can lose this // moved speed UP
  GSHIFTNOS_;
  /// CORE
  gate[w].shift_=gate[w].shift_<<(abstractbitstreamslong[mode->gsfr](mode->par0[w], w)); // is this within outer spd? we could have different versions
    if (abstractbitstreamslong[mode->probfr](mode->par2[w], w)){ // prob
      bitn=abstractbitstreamslong[mode->incfr](mode->par3[w], w); // what?
    }
    else
      { 
	bitn=abstractbitstreamslong[mode->par3[w]](mode->par3[w], w); // or?
      }
  
  bitn=mode->logic(bitn, abstractbitstreamslong[mode->last](mode->par4[w], w)); 
  ///  
  BITN_AND_OUTVINT_; // abstract out maybe
  ENDER;
  }
}
*/


// further look into abstraction here
// have we not just shifted it into spdmodes above arrays of function calls in calls...

void abstract(uint8_t w){  // was abstractoutinterpolroute null
  HEADNADA;
  uint8_t spdfrom=2; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core operation
    // we need a bitn for potential pulsouts
    // what we do with bitn or GSR...

    // we have 4 sliding speeds: GSRcopyin, <<SR, <<GSR, binroute/dac
    // now these are all in spdfrom/mode 
    GSHIFTNOS_;
    gate[w].shift_=gate[w].shift_<<1;
    // bt= //
    // << appropriate GSR(s)
    /* // simple SR

    GSHIFT_; //-> copy to GSR and shift <<SR as 2 sep ops
    bitn=binroutebitsI(CVL[w],w); // seperate speed of dac and <<GSR
    gate[w].shift_+=bitn;						\
    */

    /* delayline noSR
       GSHIFTNOS_;
    
       BINROUTE_; // generators/prob/other routes/
       PULSIN_XOR;
       gate[w].shift_&=bitmasky[counter[w]];
       gate[w].shift_|=(bitn<<counter[w]);
       counter[w]++;
       if (counter[w]>SRlength[w]) counter[w]=0;
     */

    /*noSR noSRxorroutes
    GSHIFTNOS_;
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
    if (tmp&0x01){ // use length for something else? prob?
      gate[w].shift_^= (gate[x].Gshift_[w]); // or length of that mask is another parameter - strobe mode - but that length doesnt do much except stop
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;

     */
    
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTVNOSHIFT_; // part of interpol - val=DAC but fits for all - now without +bitn
    new_data(val,w);
  }
}

// // from below,,,, we need to lose << on GSR to slow things down... 
// doesn't slow much -> problem is that series of 1s will trigger - we need transition
// but that doesn;t work for say fractionals (also if strobe is held we keep on)...
// try in gen - slower is DONE...

// version with no << GSR for incoming speed // and only on a transition - that one slows down but is not so exciting
void abstractoutinterpolnoshift(uint8_t w){ 
  HEADNADA;
  uint8_t spdfrom=4;  // spdfrom 3 is noshift, 4 is that one but only on a change
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    bitn=binroutebitsI(CVL[w], w); // independent from shared one above - cycle on strobe
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// 20/4/2022

// DONE:
// rungler in rungler but split across - is this not what we have with abstracted out versions below
// how we define independent rungler: as below IN=binroute and spdfrom=binroute but it has cycle...

//*abstract out interpol and strobe*
// start with basic function exposed

void base(uint8_t w){ // basic template // null
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_; 
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}

// for first one we have one param for fixed spdmodes, second one uses 2nd for route

// we would ideally need 4 params: spdmode/depth, in/depth
// if we have major mode idea then we would use minor mode as spdmode/in (how? - as combos?) and CVs as depths
// how many bits? 4 bits here for spdmodes, 4 for in, depth varies in bits... (eg. can be 4 bits too for binroute)

// but the nice to have split so is not all these for LRCN//// how to do????
// also as binroute for spd tends to run at audio rates...

// we need to lose << on GSR to slow things down... try this 21/4

// options: speed from strobe - no int, from dac or CV - interpol/no_interpol, from bits - no int = 1,2,3,4 options
// what we don't have is freezespeed, nor copy of speedf_ but we can do that - otherwise is working!
void abstractoutinterpol(uint8_t w){ 
  HEAD;
  uint8_t spdfrom=2; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    BINROUTE_;
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// binroute and spdroute from routes and recursion - this one does this! but recursion is tricky without clock injection

// add in binroute
// but problem is if both run binroute - each instance is not independent even with I as indep. as is same w!
void abstractoutinterpolroute(uint8_t w){ 
  HEADNADA;
  uint8_t spdfrom=2;
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    bitn=binroutebitsI(CVL[w],w); // independent from shared one above - 
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// rungler version for rung in rung across all -> with cycle/cycle on strobe
void abstractoutinterpolrung(uint8_t w){ 
  HEADNADA;
  uint8_t spdfrom=2; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    bitn=binroutebitscyclestrI(CVL[w], w); // independent from shared one above - cycle on strobe
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// 19/4/2022

//+gens->bitspeed (do we not have that?): yes as adcspeedstream in modeN.h but still we need to improve generators+

///////////......

// *** how to take characteristics and split these across SRs while keeping some structure... code to write/chop code, multiple opposing speeds...

// look again bitdsp and parallel bit processings

/// trigger oversamples (at speed)
// how do we oversample - run twice at speed...
// run twice but if we are slow others would have to wait... so just run twice...

// these can also be selecting different types of ADC and detached...
void ADCovers(uint8_t w){ 
  HEAD;
  // 2nd round - was inside loop - fix << though
  if (gate[w].trigger){
  gate[w].shift_=gate[w].shift_<<1;
  bitn=adcpadbits(SRlength[w]);
  gate[w].shift_+=bitn;
  }

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadbits(SRlength[w]);
  BINROUTE_; // or not! 
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void ADCoverss(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEAD;

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadbits(SRlength[w]);

  if (gate[w].trigger){
  gate[w].shift_+=bitn;
  gate[w].shift_=gate[w].shift_<<1;
  bitn=adcpadbits(SRlength[w]);
  }
    
  BINROUTE_; // keep bin
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// or go for 2 identical samples in
// almost like sample and hold
void ADCoversss(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEAD;

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadbits(SRlength[w]);

  if (gate[w].trigger){
  gate[w].shift_+=bitn;
  gate[w].shift_=gate[w].shift_<<1;
  //  bitn=adcpadbits(SRlength[w]);
  }
  // so same bitn will come in
  BINROUTE_; // keep bin
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// same but outside so we need new adc for sample and hold-like also
static inline uint32_t adcpadholdbits(uint32_t depth, uint8_t reset){ // TODO: eg. what happens if used consecutively... we have that in stream...  // how we could share same bits?
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    ADCgeneric; 
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (reset) bc--;
  return bt;
}

void ADCoverssss(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEAD;

  if (gate[w].trigger){
  gate[w].shift_=gate[w].shift_<<1;
  bitn=adcpadholdbits(SRlength[w], 0); // doesn't advance
  gate[w].shift_+=bitn;
  }
  
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadholdbits(SRlength[w],1);  // that one advances things so above trigger own is same bit - or vice versa
  BINROUTE_; // 
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// start with sample and holds on trigger...
void ADChold(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  
  if(gate[w].last_time<gate[w].int_time)      {
    /*
    if (gate[w].trigger)  { // we could also hold binroute by not advancing GSRs - holdings
      GSHIFTNOS_; 
    }
    else
      {
	GSHIFT_;
      }
  */
    GSHIFT_;
    bitn=adcpadholdbits(SRlength[w], (!gate[w].trigger)); // trigger will hold it...
    BINROUTE_; 
    BITN_AND_OUTV_;
    ENDER;
  }
  }
  }

// other sample and hold with revolving bits on hold...
static inline uint32_t adcpadholdcyclebits(uint32_t depth, uint8_t reset){ // TODO: eg. what happens if used consecutively... we have that in stream...  // how we could share same bits?
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  static uint8_t oldreset=1;
    if (reset) oldreset=0;

  if (bc<0) {
    if (oldreset){
      ADCgeneric; 
    }
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
    oldreset=1;
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

void ADCholdcycle(uint8_t w){   // 2nd round - was inside loop - fix << though 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=adcpadholdcyclebits(SRlength[w], (gate[w].trigger)); // trigger will hold it
    BINROUTE_; 
    BITN_AND_OUTV_;
    ENDER;
  }
  }
  }

////////////////////////////////////////////////////////////////////////////

// TODO: ADC noise comp and select new generators,
// ADC noise comp:   if (((LFSR_[w] & 4095 ) > k)){  = not so exciting
void ADCnoisecmp(uint8_t w){  // for top modeN
  //  HEADSIN;
  HEADSSINNADA; // or do as strobe
  uint32_t k;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ADCgeneric;  
  if (((LFSR_[w] & 4095 ) > k)){   // this way round?
    // select gen and input
    bitn=(*abstractbitstreams[CVL[w]>>8])(CV[w],w); // oops need 2 CVs - 4 bits for first one - leaves 2 bits spare...
  }
  else
    {
      JUSTCYCLE_; // no length/speed - is a bit odd - discards bits
    }
  //  BINROUTE_; // or not! could use excess bits?
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

 // or do as strobe
void ADCnoisecmpSTROBE(uint8_t w){  // for top modeN
  //  HEADSIN;
  HEADSSINNADA;
  uint32_t k;
  if (gate[w].trigger)      {
  GSHIFT_;
  ADCgeneric;  
  if (((LFSR_[w] & 4095 ) > k)){   // this way round?
    // select gen and input
    bitn=(*abstractbitstreams[CVL[w]>>8])(CV[w],w); // oops need 2 CVs - 4 bits for first one - leaves 2 bits spare...
  }
  else
    {
      JUSTCYCLE_; // no length/speed - is a bit odd - discards bits
    }
  //BINROUTE_; // or not! could use excess bits?
  BITN_AND_OUTVINT_;
  }
}

  
// 18/4/2022

// TODO: more multiple speeds
/// *TODO: dacspeed and internal speed slip against each other: gshift and... see multiple speeds where we have dac but not as core speed*

void SRmultiplespeednewdac0(uint8_t w){ // - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  HEADSSIN;
  float speedf__;
  
  if (gate[w].trigger) GSHIFTNOS_; // // 1.copy gshift on trigger// sans <<

  if (counter[w]>CV[w]){ //2.advance incoming ghost on speed
    counter[w]=0;
    BINROUTEADV_;
  }

  speedf__=logspeedd[gate[speedfrom[spdcount][w]].dac>>2]; // that's 10 bits only - can also have scaling by CV 
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    gate[w].shift_=gate[w].shift_<<1; 
    BINROUTENOG_; // no gshifty
    BITN_AND_OUTV_;
    ENDER;
  }
}

// more variations on this! - 4 speeds, cv, cvl, strobe, dac
// break down into:

/*
from modeL.h
x. shifting/SR speed << in all below we don't split this except new - can be part of dac or in gshift

1. GSR copy speed (own GSR) //copy on strobe? see 37 in newmodes - L3 in modeL - in/outside loop as optionsDONE
2. advance incoming GSR speed - slidings
3. DAC out speed  - slipping - this is main loop as we need interpol
 */

// 4 independent speeds. 5 options: NONE (as in shift is taken up elseehere) CV, CVL, trigger, DAC = 2 bits each, collapse 1.shifter = 6 bits but select will use one CVL
/* we have so far in model.h:
SRmultiplespeednew: T:1, DAC: 2, CVL:<<x, CV: 3 
speed0: T:1, CVL: 2, CV: 3
1: T:2, CVL: 1, CV: 3
2: T:1<<, CVL: 2, CV: 3
3: CVL: 2, CV: 3
dac0: T: 1, DAC: <<x, CVL: 2, CV: 3
dac1: T: 1, DAC: 2, CV: 3
multspeed0: T: 1, CVL: 2, CV: 3
multspeed1: T: 2, CVL: 2, CV: 3 
2: T: 1<<, CVL: 2, CV: 3
3: CVL: 2, CV: 3
speeddac0: T: 1, DAC: <<x, CVL: 2, CV: 3
 
newdac0 above: T: 1, CV: 2, DAC: 3<<
newdac below: T: 1, CV: 2, CVL: <<x, DAC: 3

what options to be done:

 */

void SRmultiplespeednewdac(uint8_t w){ // NO LENGTH - try 4 speeds as above - multiple versions of this // this one is ****
  
  HEADSIN; // detach length
  float speedf__;

  if (gate[w].trigger) GSHIFTNOS_; // 2.copy gshift on trigger

  if (counter[w]>CV[w]){ //3.advance incoming ghost
    counter[w]=0;
    BINROUTEADV_;
  }

  if (counterd[w]> CVL[w]){
      counterd[w]=0;
    gate[w].shift_=gate[w].shift_<<1; // 1. shifter
  }
  
  speedf__=logspeedd[gate[speedfrom[spdcount][w]].dac>>2]; // that's 10 bits only - can also have scaling by CV 
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    //    gate[w].shift_=gate[w].shift_<<1; // but no shift makes odd with add... anyways
    BINROUTENOG_; 
    PULSIN_XOR;
    BITN_AND_OUTVXOR_;
    ENDER;
  }
}

/* what do we have of: operations on whole register/across registers? -noSR series

eg. noSRxorroutes: XOR with mask of incoming lengths... of routes in - which now we have as prob in = can also be sel routes and logic DONE below

*/

// circular buffer - borrowed from delay_line - can also have all options for this such as cycle/entry/prob etc...
// what is model for those permutations - where?

void noSRdelay_line(uint8_t w){ 
  HEAD;
  static uint32_t counter[4]={0,0,0,0}; // shared // unshared counter
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  //  bitn^=delay_line_shared(CVL[w],w); // or detach - length not used - this is our binroute
  BINROUTE_; // generators/prob/other routes/
  PULSIN_XOR;
  gate[w].shift_&=bitmasky[counter[w]];
  gate[w].shift_|=(bitn<<counter[w]);
  counter[w]++;
  if (counter[w]>SRlength[w]) counter[w]=0;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
}

// catalogue possible ins?

// delay line - large array and we write single bits into that circular buffer - 12 bits 4095 bits delay=128
// but then buffer is not a shift reg
// length=delay
// what is incoming bit? - route in - others?
static inline uint32_t delay_line_shared(uint32_t depth, uint8_t wh){ // share counter and delay line
  // what other options are there?
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits; // 32 bits of bits
  tmp=binroute[count][wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  // extract from delay line (12 bits=4095)
  depth=bits+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delayline[tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits/32;
  tmpp=bits%32;
  delayline[tmp]&=bitmasky[tmpp];
  delayline[tmp]|=(bt<<(tmpp));
  bits++;
  if (bits>4095) bits=0;

  return bitrr;
}

static inline uint32_t delay_line_shared2(uint32_t depth, uint8_t wh){ // there are independent counters and shared line
  // what other options are there?
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits[4]; // 32 bits of bits
  tmp=binroute[count][wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  // extract from delay line (12 bits=4095)
  depth=bits[wh]+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delayline[tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits[wh]/32;
  tmpp=bits[wh]%32;
  delayline[tmp]&=bitmasky[tmpp];
  delayline[tmp]|=(bt<<(tmpp));
  bits[wh]++;
  if (bits[wh]>4095) bits[wh]=0;

  return bitrr;
}

static inline uint32_t delay_line_shared3(uint32_t depth, uint8_t wh){ // there is a shared counter and indie lines
  // what other options are there?
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits; // 32 bits of bits
  tmp=binroute[count][wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  // extract from delay line (12 bits=4095)
  depth=bits+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delaylineUN[wh][tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits/32;
  tmpp=bits%32;
  delaylineUN[wh][tmp]&=bitmasky[tmpp];
  delaylineUN[wh][tmp]|=(bt<<(tmpp));
  bits++;
  if (bits>4095) bits=0;
  return bitrr;
}


static inline uint32_t delay_line_unshared(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits[4]; // 32 bits of bits
  tmp=binroute[count][wh];
  for (uint8_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  
  // extract from delay line (12 bits=4095)
  depth=bits[wh]+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delaylineUN[wh][tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits[wh]/32;
  tmpp=bits[wh]%32;
  delaylineUN[wh][tmp]&=bitmasky[tmpp];
  delaylineUN[wh][tmp]|=(bt<<(tmpp));
  bits[wh]++;
  if (bits[wh]>4095) bits[wh]=0;

  return bitrr;
}

void SRdelay_lineSH(uint8_t w){ 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=delay_line_shared(CVL[w],w); // or detach - length not used - this is our binroute
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SRdelay_lineSH2(uint8_t w){ 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=delay_line_shared2(CVL[w],w); // or detach - length not used - this is our binroute
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SRdelay_line(uint8_t w){ 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=delay_line_unshared(CVL[w],w); // or detach - length not used - this is our binroute
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


// 15/4/2022

 //uint32_t patt[32]={0b1010, 0b1010, 0b1010, 0b1010, 0b11001100, 0b11001100, 0b11001100, 0b11001100, 0b111000111000, 0b111000111000, 0b111000111000, 0b111000111000, 0b1111000011110000, 0b1111000011110000, 0b1111000011110000, 0b1111000011110000, 0b11111000001111100000, 0b11111000001111100000, 0b11111000001111100000, 0b11111000001111100000, 0b111111000000111111000000, 0b111111000000111111000000, 0b111111000000111111000000, 0b111111000000111111000000, 0b1111111000000011111110000000, 0b1111111000000011111110000000, 0b1111111000000011111110000000, 0b1111111000000011111110000000, 0b11111111000000001111111100000000, 0b11111111000000001111111100000000, 0b11111111000000001111111100000000, 0b11111111000000001111111100000000};

// same bits out from generators - generic or shared clock
static inline uint32_t pattern_unshare(uint32_t depth, uint8_t wh){
  uint32_t bt, k;
  static uint32_t fast=0, khh;
  static int32_t bc[4]={0,0,0,0};
  static uint32_t kh[4]={0,0,0,0};
  
  if (bc[wh]<0) {
    kh[wh]=0b1010; // pattern also from dac but then looks like independent generators - better with fixed length
    bc[wh]=3; // we can also use length 
  }
  bt = (kh[wh]>>bc[wh])&0x01; // this means that MSB comes out first
  bc[wh]--;
  return bt;
}

void SRpattern_unshare(uint8_t w){ // sequential 12 bit in - use also for L, R, N
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=pattern_unshare(SRlength[w],w); // or detach - length not used
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}
// mods: usual, 


// chance of prob decay (flip) as it advances down SR... - older bits...* initial chance of decay/flip
// older ones more likely to flip...
/*
from bitdsp:
// + `type == 1` -- set a bit's value to low 
// + `type == 2` -- flip bit
// + `type == 3` -- set a bit's value to high

process sequence of bits

for (x=SRlength;x>0;x--)
if (highestprob) flipbitx
highestprob-lessens
 */

void SRLdecaying(uint8_t w){
  HEADSIN;
  int tt, dec;
  uint32_t highestprob=4095;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_;
  dec=(4096/SRlength[w]);
  for (tt=SRlength[w];tt>0;tt--){
    //    if (highestprob) flipbitx
    //highestprob-lessens
    if ( (LFSR_[w] & highestprob) > CVL[w]) {
	gate[w].shift_^=(1<<tt); // flips
      }
      highestprob=highestprob-dec;      
  }
  
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }
// works fine for slower approaches...

// DONE: eg. what happens if used consecutively... we have that in stream...  // how we could share same bits?
// question of counting bits... ie. if we want to share same bit who counts them down... (last caller but how do we know that?)

static inline uint32_t adc4bits_unshare(uint32_t depth, uint8_t wh){ // use wh too so matches other gens
  uint32_t bt, k;
  static uint32_t fast=0, khh;
  static int32_t bc[4]={0,0,0,0};
  static uint32_t kh[4]={0,0,0,0};
  
  if (bc[wh]<0) {
    ADCgeneric;
    kh[wh]=k>>8;
    bc[wh]=3; 
  }
  bt = (kh[wh]>>bc[wh])&0x01; // this means that MSB comes out first
  bc[wh]--;
  return bt;
}
// also question split between generator and modeX.h - question of wrapping, autowraps?
// it becomes:

void stream4_unshare(uint8_t w){ // sequential 12 bit in - use also for L, R, N
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=adc4bits_unshare(11,w);
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}
// always variations: binroute, shift or not...
// but also what happens if we unshare across dacs, any sequential output

//////////////////////////////////////////////////////////

// cipher generator now in gen.h to use for adc [4094]

// more like cipher entering SR
void adccipher(uint8_t w){ // generator is contained so is different to one below which can have binroute inside
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  bitn^=cipherbits(CVL[w], w); // not using depth
  BINROUTE_; // or not!
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }
// variations TODO: binroute or not, prob of binroute/cycle, use prob as speed, use strobe as speed and prob as trigger, or if on L or R, pulse as trigger
// thinking about how variations become submodes...

// 8 bit CIPHER for adc/trad modes
void adccipher2(uint8_t w){    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)
uint8_t prob;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_; // we dont shift our own SR

    GGGshift_[w]=GGGshift_[w]<<1;
    BINROUTE_; // here binroute is in different place or not - to above
    bitn^=ADC_(w,SRlength[w],85,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
    PULSIN_XOR; // not for adc ignore
    GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    } 
    bitn=CYCl;
    BITN_AND_OUTVNOSHIFT_;
    ENDER;
  }
  }
}
// variations such as: binroute or not. timing of binroute 


// 14/4/2022

// slide 2 bitstreams against each others? how to chain bitstreams but
// again we lose parameters, how we can imagine leaving behind a chain
// of parameters - key Q is params and organisation/streams

/*
bitn=logiq((*abstractbitstreams[val])(CV[w],w),(*abstractbitstreams[val2])(CVL[w],w)) 

4 params is too much... and that sliding can be each SR... 

*/

// 13/14/4/2022

// speedfrom, prob, incoming, final bit(pulsin) as 4 functions numbered - gridlike...
// but question is again lack of params...

/*

void recurse(void (*f)(void)){ // but again we would have to have: recurse(void (*f)(void (*f)(void (*f)(void (*f)(void (*f)(void))))) etc...
printf("x");
f();
}

recurse(recurse); 

 */


/*
void SRitselftryagain(uint8_t w, uint8_t gsfr, uint8_t spdfr, uint8_t probfr, uint8_t incfr, uint8_t incor, uint8_t last, uint32_t *par0, uint32_t *par1, uint32_t *par2, uint32_t *par3, uint32_t *par4, uint8_t (*logic)(uint8_t bit1, uint8_t bit2) ){
uint8_t prob;
 HEADSSINNADA; // detach depending on what/
  if (abstractbitstreamslong[spdfr](par1[w], w)){  // spd - for intmodes we can losee this - moved up
 CVOPEN;
  GSHIFTNOS_;
  /// CORE
  gate[w].shift_=gate[w].shift_<<(abstractbitstreamslong[gsfr](par0[w], w)); // shift or not
    if (abstractbitstreamslong[probfr](par2[w], w)){ // prob
      bitn=abstractbitstreamslong[incfr](par3[w], w); // what?
    }
    else
      { 
	bitn=abstractbitstreamslong[par3[w]](par3[w], w); // or?
      }
  bitn=logic(bitn, abstractbitstreamslong[last](par4[w], w)); 
  BITN_AND_OUTV_; // abstract out maybe
  ENDER;
  }
}
*/

// 12/4/2022

// itself/loopback as route or decision?
// how to break down further as set of functions or options so is not such monolithic functions??? eg. what clkbit does, pulsin_xor
// guess as sets of bits again...

// if [if x bitfrom X] bitfrom X // else?

// if x source y or z - plug in generators - just as example to think on
/*
static uint32_t itself2(uint32_t (*f)(uint32_t depth, uint8_t wh), uint32_t (*g)(uint32_t depth, uint8_t wh), uint32_t (*h)(uint32_t depth, uint8_t wh), uint32_t depth, uint8_t wh){   // or extra param for g(param,wh)???
  uint32_t bt=0;
  if (f(depth,wh)){ // if itself...recur
      bt=g(depth,wh);
    }
  else bt=h(depth,wh);
  return bt;
}
*/

// if (itself2(func[x],func[y],func[z],CV[0],w)) itself2...;

// do we clk/strobe as generator, toggle generator...??? do we have this? - DONE

// 11/4/2022

/* bin

   tmp=binroute[count][w];
   for (x=0;x<4;x++){
   if (tmp&0x01){
   bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
   gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
   bitn^=bitrr;
   }
   tmp=tmp>>1;
  }

 */

// can we insert one wheel/SR in another - keep it running at last speed... embed it as our bitn

// attach, detach, embed of functions

// embed as bitn, as prob/decision

// what that would look like and how that could be translated into a story, how to embed/recurse as a structure/itself

/*

we would need to simplify speed... speed can also be a character of SR... speed as decision from SR/generator

speed as sequence of SR/ 1s and 0s

global speed...

genX:
if (genX){
gshift[w]
bitn=genX
}

towards most simple SR - work from inside or from inside out

void SRintprobnog(uint8_t w){  // intmode
  HEAD;  
  if (X)      {
    GSHIFT_;

    bitn=Y;
    PULSIN_XOR;

    BITN_AND_OUTVINT_; 
  } 
}

// gshift as part of generator, output as what?

-> abstractions of SRs aside from output - or vice versa... functions assigned to outputs

splitting and subjection of itself... so each element is abstracted out and able to be controlled by...

if (speed){
  if X gshift
  bitn=[ // generator selected--->
    if (speed){
      bitn=[ // generator
      ]
    }
  ]
}

if (speedfrom){
  gshift
  bitn=FROM?
  SR=IN?/WHERE?
  GSR=GSR? // recurse... but we lose params...

 */

// itself(uint32_t (*f)( uint32_t (*f)(RECURSE),uint32_t depth, uint8_t wh), uint32_t depth, uint32_t other, uint8_t wh)

// towards new prototype for itself as SR
static uint32_t itself(uint32_t (*f)(uint32_t depth, uint8_t wh), uint32_t (*g)(uint32_t depth, uint8_t wh), uint32_t depth, uint32_t other, uint8_t wh){   // PROBability mode
  uint32_t bt=0;
  if (f(depth,wh)){ // if itself...recur
      bt=g(other,wh);
    }
  return bt;
}

// wrap up eg.
void SRitself(uint8_t w){ // null
uint8_t prob;
  HEADSSINNADA;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
    // CORE
  bitn=itself(osceqbits,binroutebits,CV[w], CVL[w], w); // but we would need additional 8 bits (4+4) to set each of these - from another SR!!!
  // abstractbitstreams[x], abstractbitstreams[y]   
  BITN_AND_OUTV_; // abstract out maybe
  ENDER;
  }
  }
}
  
//speedfrom?, bitfrom?

// vienna/generic was: 1bit speedfrom, [1bit adctype-fixed], 4 bits routein, 1bitprob_of_inv on param

// swop incoming gshift and shift
void SRGswop(uint8_t w){// swap over SRs on pulse in?!! or swop in only (can swop in previous SR or another?) 
uint8_t prob;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    //    if (gate[w].trigger) gate[w].shift_=gate[w].Gshift_[w]; // could also be incoming one
    if (gate[w].trigger) gate[w].shift_=gate[inroute[count][w]].Gshift_[w]; // could also be incoming one
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// 2 routes into one//XOR full TRY!
void noSRxorroutes(uint8_t w){ // XOR in 
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  // copy mask of bits from inroute
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round?
    
    GSHIFTNOS_; // why is no copy?
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
    if (tmp&0x01){ // use length for something else? prob?
      gate[w].shift_^= (gate[x].Gshift_[w]); // or length of that mask is another parameter - strobe mode - but that length doesnt do much except stop
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;   // dont add in bitn
  }
  else
    {
      GSHIFT_;
      JUSTCYCLE_; // or could be BINROUTE
      BITN_AND_OUTV_;
    }
  ENDER;
  }
  }
  }

// // 2 routes into one//XOR full TRY! - select route and logic - 6 bits
void noSRselxorroutes(uint8_t w){ // XOR in
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  // copy mask of bits from inroute
    GSHIFTNOS_; // why no copy?
    tmp=CVL[w]>>8; // 
    for (x=0;x<4;x++){
    if (tmp&0x01){ 
      gate[w].shift_^= (gate[x].Gshift_[w]); // but length doesnt do much except stop - xor itself is a 0 too
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
      //    bitn^=bitrr; // lowest 2 bits for logic
      bitn=logop(bitn,bitrr,(CVL[w]>>6)&3);
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;   // dont add in bitn
  ENDER;
  }
  }
}

// question of embeddings and numbers say of gshifts... also shared gshifts as an option... embed this one//as a generatorDONE

// new gshift for sharings: BINROUTESHARE_ and gate[x].Gshare_ -> only makes sense if we share routes or if there are functions to shift on shared routes... 
// eg. function to shift on shared route at speed as one SR or to insert into shared SR!
// try route from before one... or enforce shared routes
void SRshroute(uint8_t w){ // strobe could also shift on
  HEAD;
  int32_t mw;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  mw=w-1;
  //  if (mw<0) mw=3;
  tmp=binroute[count][w];
   for (x=0;x<4;x++){
   if (tmp&0x01){
   bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;
   gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
   if (gate[w].trigger) {
   bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;
   gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
   }
   bitn^=bitrr;
   }
   tmp=tmp>>1;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }
  
///////////////////////////////////////////////////////////////////////////////////////////

// 8/4/2022

// wheeling probability function
// but to make use of this we need next one to use incoming as prob of adc or route from top
// so needs some sync - is question across all of new idea of functions
void SRprobwheel(uint8_t w){ // new detached mode with prob wheel as generator only // for L
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w];
  bitn=ADC_(w,SRlength[w],113,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_);
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// eg. test this with basic modeN which uses binroute for loop or route in from top // for C - seems to workings
void dacNbinprob(uint8_t w){ 
  gate[w].dactype=0; gate[w].dacpar=param[w];
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    if (bitn){
      bitn=0;
      // route from 1
      bitrr = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
      gate[0].Gshift_[w]=(gate[0].Gshift_[w]<<1)+bitrr;
      bitn^=bitrr;
    }
    else
      {
	bitn=0;
	JUSTCYCLE_;
      }
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// no gshifts: adc0nog, SRR0nog, same as SR0nog and from modeC: dac67_4bitsNOGG - length has less to do
// do we have options to say strobe/toggle/prob in/out the gshifter? TODO:

// as: SR0nogstrobe, SR0nogtoggle, SRLprobnog, SRintprobnog DONE

void SR0nogstrobe(uint8_t w){ // basic route in no GSHIFT<< strobed
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (STR0) { // macro now for strobe/trigger
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void SR0nogtoggle(uint8_t w){ // basic route in no GSHIFT<< toggles
  HEAD;
  static uint8_t toggle[4]={0,0,0,0};
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (STR0){
      toggle[w]^=1;
    }
    if (toggle[w]) {
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// and finally prob from CVL - detached... - and can also be an intmode TODO
void SRLprobnog(uint8_t w){
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void SRintprobnog(uint8_t w){  // intmode
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    // HERE
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  } 
}

// don't move at all... xor etc one Sr against another....// and what does length do...
// trial

//*what elements can be used from delta sigma*
// signal input is binroute, subtract cycle bit and pass bits via integrator/comp
//trial - what other functions could be?? bit filter, logic?

void SRsigma(uint8_t w){ 
  HEAD;
  int32_t cycle;
  static int32_t integrator;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_;
  if (bitn) val=1;
  else val=-1;
  if (CYCl) cycle=1;
  else cycle=-1;
  
  integrator+=(val-cycle);
  if (integrator>0) bitn=1;
  else bitn=0;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// unmoving XOR on strobe - parallel streams - we can have 4 unmoving copy across SRs - they are not SRs... 

/*
void noSRproto(uint8_t w){
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }
*/

// masks to do - but they are also not bitstreams... and we need a bitn for pulses or do a different pulse out
// DONE using   RETURN; TEST!

// trial 12 bits of adc in 
void noSRadc(uint8_t w){
  HEAD; uint32_t k;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  ADCgeneric;
  k=k>>(leftshift[SRlength[w]])<<rightshift[SRlength[w]]; // fill length
  gate[w].shift_=k;
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_^=tmp;
  RETURN;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }

//- 2s complement and others for noSRadc
void noSRadc2s(uint8_t w){
  HEAD; uint32_t k;
  uint32_t bt, bitwise;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  ADCgeneric;
  if (k<2048) bitwise=1;
  else bitwise=0;
  k=abs(k-2048);
  if (bitwise) k=(~k)+1;
  k=k>>(leftshift[SRlength[w]])<<rightshift[SRlength[w]]; // fill length
  gate[w].shift_=k;
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_^=tmp;
  RETURN;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }

// and 12 bits out dac
void noSRdac(uint8_t w){ 
  HEAD;
  gate[w].dactype=23; gate[w].dacpar=param[w];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_;
    tmp=(gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]]);
    gate[w].shift_=tmp;
    BITN_AND_OUTVNOSHIFT_; 
    ENDER;
  }
  }
}

void noSRdac2s(uint8_t w){ 
  HEAD;
  gate[w].dactype=22; gate[w].dacpar=param[w];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_;
    tmp=(gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]]);
    gate[w].shift_=tmp;
    BITN_AND_OUTVNOSHIFT_; 
    ENDER;
  }
  }
}

void noSRdac2sRLxor(uint8_t w){  // xor of left and right
  HEAD;
  gate[w].dactype=22; gate[w].dacpar=param[w];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_;
    tmp=(gate[1].Gshift_[w]&masky[SRlength[1]]);
    gate[w].shift_=tmp^(gate[3].Gshift_[w]&masky[SRlength[3]]);
    BITN_AND_OUTVNOSHIFT_; 
    ENDER;
  }
  }
}

void noSRcopy(uint8_t w){ // copy in with mask of length
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  // copy mask of bits from inroute
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_=tmp;
  gate[w].shift_^=bitn; // where do we put pulse bits? - not much happening
  RETURN;
  BITN_AND_OUTVNOSHIFT_;  
  ENDER;
  }
  }
  }

