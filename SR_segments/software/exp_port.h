// additional ports from experiment.h, bit.h, prob.h

// TODO: extractL, R, N, C ???

// speedmodes from experiment/gen.h:
//uint32_t (*spdmodes[32])(uint32_t depth, uint8_t wh)={speedfracint, speedfrac, strobebits, binroutebits, binroutebits_noshift, binroutebits_noshift_transit, strobeint, probbits, TMsimplebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, compbits, compdacbits}; // just to test // second speedfrac is no interpol

// diff/to add/translate to geo world:

//zbinroutebits, zbinroutebits_noshift, zbinroutebits_noshift_transit, zprobbits, zTMsimplebits, osceq, zosc1bits, zonebits, zENbits, zENsbits, zcompbits, //compdacbits

// compared to from geogen.h:
//uint32_t (*speedfromsdd[32])(uint32_t depth, uint32_t in, uint32_t wh)={strobe, spdfrac2, spdfrac3, spdfrac, holdlspdfrac, strobe, ztogglebits, ones, clksrG, clksr,

// template
static inline uint32_t p(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
  
  return bitn;
}

// list here: pSR_binr, pSR_routeSRbits00, pSR_routeSRbits01, pSR_routeSRbits02, pSR_layer1, pSR_layer12, pSR_reflect, pSR_altbin1, pSR_insert_zero, pSR_probbin, pSR_recbin, pSRhold, pSRholdfromdac, pSRxorSR, pSRxorroutes, pSRaddroutes, pSRprobxortogx, pSRprobxortog, pSRmatch, pSRshare, pSRGswop, pSRshroute, pSRsigma, pbitSRroutelog, pbitSRroutelogxx, pbitLcvsrroute, pbitSRroutelogxxx, pbitSRroutedoit, pbitLSRroutexxxlog, pprobintprob1, pprobintprob2, pprobintprob3, pprobintprob5_0, pprobintprob6_0, pprobtoggle1, pprobtoggle2, pprobtoggle3, pprobtoggle4, pprobtoggle5, pprobstrobe1, pprobstrobe2, pprobstrobe3pstream

static inline uint32_t , pSR_binr(uint32_t depth, uint32_t in, uint32_t w){ // depth only
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  tmp=depth>>8; // top4 bits for routing itself
  tmpp=(depth>>5)&7; // lower 3 bits for binroute selection
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
    return bitn;
}

static inline uint32_t pSR_routeSRbits00(uint32_t depth, uint32_t in, uint32_t w){ // nada - can use depth as dacfrom - 2bits only
  uint32_t x, tmp, bitrr, temp, bitn=0;
  tmp=gate[dacfrom[count][w]].shift_&15; // lowest 4 bits
  BINROUTEstrip_; // also can be different types of binroute
  return bitn;  
}

static inline uint32_t pSR_routeSRbits01(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  tmp=depth>>8; // 4 bits
  bitrr=0;
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }
  tmp=bitrr;
  BINROUTEstrip_; // also can be different types of binroute
  return bitn;
}

static inline uint32_t pSR_routeSRbits02(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  tmp=depth>>8; // 4 bits
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
  return bitn;
}

static inline uint32_t pSR_layer1(uint32_t depth, uint32_t in, uint32_t w){ //depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  tmp=(depth>>8); // lowest 4 bits - but we could use 1 extra bit for 8th
  if (tmp==0 || ((depth>>7)&1)) { // SR5 is 8th which is outside these bits 
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
  return bitn;
}

static inline uint32_t pSR_layer12(uint32_t depth, uint32_t in, uint32_t w){ // nada, could use depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  //  tmp=(depth>>8); // lowest 4 bits - but we could use 1 extra bit for 8th
  tmp=gate[dacfrom[count][w]].shift_&15;
    if (tmp==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01;
    gate[w].shift_ ^=gate[8].Gshare_;
    bitn^=bitrr;
  }
    else {
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	bitn^=bitrr; // we need bitn for pulses
	gate[w].shift_ ^=gate[x].Gshift_[w];
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; // versions which just use SR and no gshift or don;t shift it
      }
      tmp=tmp>>1; // 4 bits
    }
    }
    // clear lowest bit
    gate[w].shift_&=invmasky[0];
  
  return bitn;
}

static inline uint32_t pSR_reflect(uint32_t depth, uint32_t in, uint32_t w){ // // nada. can also use depth for route
  uint32_t x, tmp, bitrr, temp, bitn=0;
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
  return bitn;
}

static inline uint32_t pSR_altbin1(uint32_t depth, uint32_t in, uint32_t w){ // nada. can also use depth for route
  uint32_t x, tmp, bitrr, temp, bitn=0;
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
  return bitn;
}

static inline uint32_t pSR_insert_zero(uint32_t depth, uint32_t in, uint32_t w){ // nada. can also use depth for route
  uint32_t x, tmp, bitrr, temp, bitn=0;
  BINROUTEZERO_;
  return bitn;
}

static inline uint32_t pSR_probbin(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  if (((LFSR_[w] & 4095 ) > depth)){   // this way round?
      BINROUTE_;
  }
  else {
    BINROUTEalt_;
  }
  return bitn;
}

static inline uint32_t pSR_recbin(uint32_t depth, uint32_t in, uint32_t w){ //depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  //  bitn=probbitsxortoggle(in,w); // ???
  bitn=binroutebits(depth,w); // how these layers can differ - 4 layers... 
  if (bitn){ 
    bitn=binroutebits(depth,w); 
  }
  if (bitn){
    bitn=binroutebits(depth,w);
  }
  if (bitn){
    bitn=binroutebits(depth,w);
  }
  return bitn;
}

static inline uint32_t pSRhold(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  //  bitn=probbitsxortoggle(in,w); // ????
  BINROUTE_;
  bitn=SRproc_hold(depth,bitn);
  return bitn;
}

static inline uint32_t pSRholdfromdac(uint32_t depth, uint32_t in, uint32_t w){ //depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  //  bitn=probbitsxortoggle(in,w);
  BINROUTE_;
  tmp=gate[dacfrom[count][w]].dac%(depth+1);
  bitn=SRproc_hold(tmp>>4,bitn);
  return bitn;
}

static inline uint32_t pSRxorSR(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    // 4 bits binroute
    tmpp=depth>>6; // 6 bits
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
  return bitn;
}

uint32_t xorroutes[4][2]={
  {3,2},
  {0,3},
  {1,3},
  {0,1}
};

static inline uint32_t pSRxorroutes(uint32_t depth, uint32_t in, uint32_t w){ // nada
  uint32_t x, tmp, bitrr, temp, bitn=0;
  if (gate[w].trigger){ 
  gate[w].shift_= (gate[xorroutes[w][0]].Gshift_[w]) ^ (gate[xorroutes[w][1]].Gshift_[w]); 
    // and we need bitn so shift
    bitn=CYCl;
    SHFT;
  }
  else
    {
      BINROUTE_; 
    }
  return bitn;
}

static inline uint32_t pSRaddroutes(uint32_t depth, uint32_t in, uint32_t w){// nada
  uint32_t x, tmp, bitrr, bitn=0;
  long temp;
  if (gate[w].trigger){ 
  temp = (gate[xorroutes[w][0]].Gshift_[w]) + (gate[xorroutes[w][1]].Gshift_[w]);
  gate[w].shift_=(temp&masky[SRlength_[w]]); //
  // and we need bitn so shift
  bitn=CYCl;
  SHFT;
  }
  else
    {
      BINROUTE_; 
    }  
  return bitn;
}

static inline uint32_t pSRprobxortogx(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  bitn=probbitsxortoggle(depth,w);
  BINROUTE_;
  return bitn;
}

static inline uint32_t pSRprobxortog(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
  bitn=probbitsxortoggle(depth,w);
  return bitn;
}

static inline uint32_t pSRmatch(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0, val;
  tmp=depth>>6; // 6 bits
  tmpp=masky[(tmp>>4)]; // top 2 bits
  if ( (gate[tmp&0x03].Gshift_[w]&tmpp)==(gate[((tmp&12)>>2)].Gshift_[w]&tmpp)) val=1;
  else val=0;
  BINROUTE_; // or not
  if (val) bitn=!bitn; // invert // or can be other op/choice... abstract out!
  return bitn;
}

static uint32_t sharedindexes[4]={0,0,0,0};
static uint32_t bufferd[1024];
static uint32_t head;

// tested in test3.c 22/4/2022
static inline uint32_t shared(uint32_t depth, uint8_t wh){ // nada ADC
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

static inline uint32_t pSRshare(uint32_t depth, uint32_t in, uint32_t w){ // nada
  uint32_t x, tmp, bitrr, temp, bitn=0;
  bitn^=shared(SRlength[w],w); // doesn't use length
  BINROUTE_; // or not
  return bitn;
}

static inline uint32_t pSRGswop(uint32_t depth, uint32_t in, uint32_t w){ // nada
  uint32_t x, tmp, bitrr, temp, bitn=0;
    BINROUTE_;
    if (gate[w].trigger) gate[w].shift_=gate[inroute[count][w]].Gshift_[w]; // could also be incoming one
    return bitn;
}

static inline uint32_t pSRshroute(uint32_t depth, uint32_t in, uint32_t w){ // nada
  uint32_t x, tmp, bitrr, temp, bitn=0;
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
  return bitn;
}

static inline uint32_t pSRsigma(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, val, bitrr, temp, bitn=0;
  int32_t cycle;
  static int32_t integrator;

  BINROUTE_;
  if (bitn) val=1;
  else val=-1;
  if (CYCl) cycle=1;
  else cycle=-1;
  
  integrator+=(val-cycle);
  if (integrator>0) bitn=1;
  else bitn=0;
  
  return bitn;
}

// from bit.c

static inline uint32_t pbitSRroutelog(uint32_t depth, uint32_t in, uint32_t w){ // nada
  uint32_t x, tmp, bitrr, temp, bitn=0;

    tmp=(SRFROM)&255; // 8 bits
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
  return bitn;
}

static inline uint32_t pbitSRroutelogxx(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  tmpp=(SRFROM)&3; // +2 bits //// dacfrom 8 bits (gate[dacfrom[daccount][w]].Gshift_[w])
  tmp=(gate[tmpp].Gshift_[w])&255; // 8 bits
    
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
  return bitn;
}

static inline uint32_t pbitLcvsrroute(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  uint32_t mmm=(63-depth>>6); // 6 bits // dacfrom 2 = total 6
  tmp=(mmm>>2) & (gate[mmm&3].Gshift_[w]) ; 
    for (x=0;x<4;x++){  // older version
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
  
  return bitn;
}

static inline uint32_t pbitSRroutelogxxx(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  static uint32_t lastdacfrom=0;
    tmpp=(gate[lastdacfrom].Gshift_[w])&3; // +2 bits //// dacfrom 8 bits (gate[dacfrom[daccount][w]].Gshift_[w])
    tmp=(gate[tmpp].Gshift_[w])&255; // 8 bits
    lastdacfrom=tmpp;
    
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
  return bitn;
}

static inline uint32_t pbitSRroutedoit(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, tmpp, bitn=0;

    tmp=(SRFROM)&63; // 4 bits route, 2 bits doit
    tmpp=tmp&0x03;
    tmp=tmp>>2;
    if (tmpp!=0){
    for (x=0;x<4;x++){  // older version
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    if (tmpp==2) RETURN;
    else if (tmpp==3){ // dacprob of inversion
      if ((LFSR_[w] & 4095 ) < (gate[dacfrom[daccount][w]].dac)) bitn^=1;
    }
    } // 1/2/3
    else RETURN;
  
  return bitn;
}

static inline uint32_t pbitLSRroutexxxlog(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;

    tmp=logopxxx((CVL[w]&255),(SRFROM)&255, (SRFROM>>8)&0x03); 
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
  return bitn;
}

// from prob

static inline uint32_t pprobintprob1(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
    BINROUTE_;
    if (((LFSR_[w] & 4095 ) < depth)) bitn=!bitn;
    return bitn;
}

static inline uint32_t pprobintprob2(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
    if (((LFSR_[w] & 4095 ) > depth)){
      BINROUTE_;
      }
    else {
      JUSTCYCLE_;
    }
  return bitn;
}

static inline uint32_t pprobintprob3(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
    if (((LFSR_[w] & 4095 ) < depth)){
    BINROUTE_;
    }
    else
      {
    BINROUTEANDCYCLE_;
      }
  return bitn;
}

static inline uint32_t pprobintprob5_0(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
  tmp=prub[depth>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255){
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
  return bitn;
}

static inline uint32_t pprobintprob6_0(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
  BINROUTE_;
  tmp=prub[depth>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255){    
      bitn=!bitn;
    }
  return bitn;
}

static inline uint32_t pprobtoggle1(uint32_t depth, uint32_t in, uint32_t w){ // nada...
  uint32_t x, tmp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    BINROUTE_;
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) bitn=!bitn; 
  return bitn;
}

static inline uint32_t pprobtoggle2(uint32_t depth, uint32_t in, uint32_t w){ // nada...
  uint32_t x, tmp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
  if (gate[w].trigger) tug[w]^=1;
  if (tug[w]) {
    BINROUTE_;
  }
    else JUSTCYCLE_;
  return bitn;
}

static inline uint32_t pprobtoggle3(uint32_t depth, uint32_t in, uint32_t w){ // nada...
  uint32_t x, tmp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTE_;
    }
    else BINROUTEANDCYCLE_;
  return bitn;
}

static inline uint32_t pprobtoggle4(uint32_t depth, uint32_t in, uint32_t w){ // nada...
  uint32_t x, tmp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTE_;
    }
    else bitn=0;
  return bitn;
}

static inline uint32_t pprobtoggle5(uint32_t depth, uint32_t in, uint32_t w){ // nada...
  uint32_t x, tmp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      BINROUTEANDCYCLE_;
    }
    else bitn=0;
  return bitn;
}

static inline uint32_t pprobstrobe1(uint32_t depth, uint32_t in, uint32_t w){ // nada...
  uint32_t x, tmp, bitrr, temp, bitn=0;
  BINROUTE_;
  if (gate[w].trigger) bitn=!bitn; 
  return bitn;
}

static inline uint32_t pprobstrobe2(uint32_t depth, uint32_t in, uint32_t w){ // nada...
  uint32_t x, tmp, bitrr, temp, bitn=0;
    if (gate[w].trigger) {
      BINROUTE_;
    }
    else JUSTCYCLE_;
  return bitn;
}

static inline uint32_t pprobstrobe3(uint32_t depth, uint32_t in, uint32_t w){ // nada...
  uint32_t x, tmp, bitrr, temp, bitn=0;
    if (gate[w].trigger) {
      BINROUTE_;
    }
    else BINROUTEANDCYCLE_;
  return bitn;
}

// from N // but to look closer at our adcs

static inline uint32_t pstream(uint32_t depth, uint32_t in, uint32_t w){ // all do ADC/ no depth or use depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  //  bitn^=adcpadbits(11);
  bitn^=adcpadbits(depth>>7); // 5 bits
  BINROUTE_;
  return bitn;
}
