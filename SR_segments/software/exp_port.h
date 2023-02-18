/* no depth versions

pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_, pbitSRroutelogD_, pbitSRroutelogxxD_, pbitSRroutelogxxxD_, pbitSRroutedoitD_, pSR32D_, pSRbumprouteD_, pSRLLswopD_, pSRN22D_, pSRN21D_, pSRR32D_ // 12

// pSRprobxortogD_, pSRprobxortogxID_, pSRprobxortogID_

 */


// additional ports from experiment.h, bit.h, prob.h

// these from gen.h
static inline uint32_t probbitsxortoggle(uint32_t depth, uint8_t wh){   // PROBability mode xor strobe - can be more ops - can also be indie version
  static uint32_t bt=0;
  if (gate[wh].trigger) bt=bt^1;
  if (depth<LFSR__[wh]) bt^=1; // variations
  return bt;
}

static inline uint32_t probbitsxortoggleI(uint32_t depth, uint8_t wh){   // PROBability mode xor strobe - can be more ops - can also be indie version
  static uint32_t bt[4]={0,0,0,0};
  if (gate[wh].trigger) bt[wh]=bt[wh]^1;
  if (depth<LFSR__[wh]) bt[wh]^=1; // variations
  return bt[wh];
}

static inline uint32_t probbitsxortoggleD_(uint32_t depth, uint8_t wh){   // PROBability mode xor strobe - can be more ops - can also be indie version
  static uint32_t bt=0;
  if (gate[wh].trigger) bt=bt^1;
  return bt;
}

static inline uint32_t probbitsxortoggleID_(uint32_t depth, uint8_t wh){   // PROBability mode xor strobe - can be more ops - can also be indie version
  static uint32_t bt[4]={0,0,0,0};
  if (gate[wh].trigger) bt[wh]=bt[wh]^1;
  return bt[wh];
}


static inline uint32_t binroutebits(uint32_t depth, uint8_t w){   // depth as routesel... shared bits now // USED only in SRrecbin here....
  uint32_t bitn=0, bitrr, x, tmp, tmpp;
  //    depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  depth=binroute[count][w]|binary[w];
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bitn^=bitrr;
  } else
    {
      tmpp=gate[w].routetype;
      tmp=depth;
      ROUTETYPE_;      
    }
  return bitn;
}

static inline uint32_t binroutebitsD_(uint32_t depth, uint8_t w){   // depth as routesel... shared bits now // USED only in SRrecbin here....
  uint32_t bitn=0, bitrr, x, tmp, tmpp;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  //.  depth=binroute[count][w]|binary[w];
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bitn^=bitrr;
  } else
    {
      tmpp=gate[w].routetype;
      tmp=depth;
      ROUTETYPE_;      
    }
  return bitn;
}


//- holder function - hold bits for /depth/ time - which bits? - this is more of a processor though...
// delay line or hold until new value we can take
static inline uint32_t SRproc_hold(uint32_t depth, uint32_t bit){ 
  static uint32_t bt=0;
  static uint32_t cxnt=0, top=0;
  cxnt++;
  if (cxnt>top){
    top=(depth>>2);
    bt=bit;
    cxnt=0;
  }
  return bt;
}

//////////////////////////// start of real functions
static inline uint32_t pSR_routeSRbits01(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  //  tmp=depth>>8; // 4 bits
  //  tmp=gate[w].theroute;
  tmp=binroute[count][w]|binary[w]; 

  bitrr=0;

  if (tmp==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bitn=bitrr;
  } else
    {
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }
    }
  tmp=bitrr;
  //  BINROUTEstrip_; // also can be different types of binroute
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t pSR_routeSRbits02(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  //  tmp=depth>>8; // 4 bits
  //    tmp=gate[w].theroute;
    tmp=binroute[count][w]|binary[w]; 
  bitrr=0;
    if (tmp==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bitn=bitrr;
  } else
    {
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }
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
  //  BINROUTEstrip_; // also can be different types of binroute
  tmpp=gate[w].routetype;
  ROUTETYPE_;

  return bitn;
}

static inline uint32_t pSR_layer1(uint32_t depth, uint32_t in, uint32_t w){ //depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
    tmp=(depth>>8); // lowest 4 bits - but we could use 1 extra bit for 8th
  //    depth=gate[w].theroute;
  //    tmp=binroute[count][w]|binary[w]; 
  
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

static inline uint32_t pSR_layer2(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
      tmp=(depth>>8); //
  //    tmp=gate[w].theroute;
  //    tmp=binroute[count][w]|binary[w]; 
  //  tmp=gate[dacfrom[count][w]].shift_&15;
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

static inline uint32_t pSR_reflect(uint32_t depth, uint32_t in, uint32_t w){ // // depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  //  tmp=binroute[count][w];
  tmp=(depth>>8); //
  //      tmp=gate[w].theroute;
  //  tmp=binroute[count][w]|binary[w]; 
  if (tmp==0) tmp=(1<<w);
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

static inline uint32_t pSR_altbin1(uint32_t depth, uint32_t in, uint32_t w){ // use depth for route
  uint32_t x, tmp, bitrr, temp, bitn=0;
  //  tmp=binroute[count][w];
    tmp=(depth>>8);
    tmp=15-tmp;
    //    tmp=gate[w].theroute;

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

static inline uint32_t pSR_recbin(uint32_t depth, uint32_t in, uint32_t w){ //depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
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

static inline uint32_t pSR_recbinD_(uint32_t depth, uint32_t in, uint32_t w){ //depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  bitn=binroutebitsD_(depth,w); // how these layers can differ - 4 layers... 
  if (bitn){ 
    bitn=binroutebitsD_(depth,w); 
  }
  if (bitn){
    bitn=binroutebitsD_(depth,w);
  }
  if (bitn){
    bitn=binroutebitsD_(depth,w);
  }
  return bitn;
}

static inline uint32_t pSRhold(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  //  BINROUTE_;
  //  tmp=gate[w].theroute;
  tmp=binroute[count][w]|binary[w]; 

  tmpp=gate[w].routetype;
  ROUTETYPE_;

  bitn=SRproc_hold(depth,bitn);
  return bitn;
}

static inline uint32_t pSRholdfromdac(uint32_t depth, uint32_t in, uint32_t w){ //depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  //  BINROUTE_;
  //  tmp=gate[w].theroute;
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;

  tmp=gate[dacfrom[count][w]].dac%(depth+1);
  bitn=SRproc_hold(tmp>>4,bitn);
  return bitn;
}

static inline uint32_t pSRxorSR(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    // 4 bits binroute
    temp=depth>>6; // 6 bits
    tmp=(temp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    tmpp=gate[w].routetype;
    ROUTETYPE_;  

    // 2 top bits add XOR route
    x=temp>>4;
    ROUTETYPES_;
    return bitn;
}

uint32_t xorroutes[4][2]={
  {3,2},
  {0,3},
  {1,3},
  {0,1}
};

static inline uint32_t pSRxorroutes(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmp, bitrr, temp, tmpp, bitn=0;
  gate[w].strobed=1;
  if (gate[w].trigger){ 
  gate[w].shift_= (gate[xorroutes[w][0]].Gshift_[w]) ^ (gate[xorroutes[w][1]].Gshift_[w]); 
    // and we need bitn so shift
    bitn=CYCl;
    SHFT;
  }
  else
    {
      //      BINROUTE_;
      tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
      ROUTETYPE_;
    }
  return bitn;
}

static inline uint32_t pSRaddroutes(uint32_t depth, uint32_t in, uint32_t w){// STROBE - can use depth/routecv for route
  uint32_t x, tmp, tmpp, bitrr, bitn=0;
  long temp;
    gate[w].strobed=1;
  if (gate[w].trigger){ 
  temp = (gate[xorroutes[w][0]].Gshift_[w]) + (gate[xorroutes[w][1]].Gshift_[w]);
  gate[w].shift_=(temp&masky[SRlength_[w]]); //
  // and we need bitn so shift
  bitn=CYCl;
  SHFT;
  }
  else
    {
      //      BINROUTE_;
      tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
      ROUTETYPE_;
    }  
  return bitn;
}

static inline uint32_t pSRprobxortogx(uint32_t depth, uint32_t in, uint32_t w){ // depth -//STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  bitn=probbitsxortoggle(depth,w);
  //  BINROUTE_;
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t pSRprobxortog(uint32_t depth, uint32_t in, uint32_t w){ //STROBE and depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  gate[w].strobed=1;
  bitn=probbitsxortoggle(depth,w);
  return bitn;
}

static inline uint32_t pSRprobxortogD_(uint32_t depth, uint32_t in, uint32_t w){ //STROBE and depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  gate[w].strobed=1;
  bitn=probbitsxortoggleD_(depth,w);
  return bitn;
}

static inline uint32_t pSRprobxortogxID_(uint32_t depth, uint32_t in, uint32_t w){ // depth -//STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  gate[w].strobed=1;
  bitn=probbitsxortoggleID_(depth,w);
  //  BINROUTE_;
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;

  return bitn;
}

static inline uint32_t pSRprobxortogID_(uint32_t depth, uint32_t in, uint32_t w){ //STROBE and depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  gate[w].strobed=1;
  bitn=probbitsxortoggleID_(depth,w);
  return bitn;
}


static inline uint32_t pSRmatch(uint32_t depth, uint32_t in, uint32_t w){ // depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0, val;
  tmp=63-(depth>>6); // 6 bits
  tmpp=masky[(tmp>>4)]; // top 2 bits
  if ( (gate[tmp&0x03].Gshift_[w]&tmpp)==(gate[((tmp&12)>>2)].Gshift_[w]&tmpp)) val=1;
  else val=0;
  tmpp=gate[w].routetype;
  ROUTETYPE_;

  //  BINROUTE_; // or not
  if (val) bitn=!bitn; // invert // or can be other op/choice... abstract out!
  return bitn;
}

static uint32_t sharedindexes[4]={0,0,0,0};
static uint32_t bufferd[1024];
static uint32_t head;

// tested in test3.c 22/4/2022
static inline uint32_t shared(uint8_t wh){ // ADC for pSRshare below 
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

static inline uint32_t pSRshare(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  bitn^=shared(w); 
  //  BINROUTE_; // or not
  tmp=binroute[count][w]|binary[w]; 

  tmpp=gate[w].routetype;
  ROUTETYPE_;  
  return bitn;
}

static inline uint32_t pSRGswop(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  //    BINROUTE_;
  gate[w].strobed=1;
  tmp=binroute[count][w]|binary[w]; 

  tmpp=gate[w].routetype;
  ROUTETYPE_;  
  if (gate[w].trigger) gate[w].shift_=gate[inroute[count][w]].Gshift_[w]; // could also be incoming one
  return bitn;
}

static inline uint32_t pSRshroute(uint32_t depth, uint32_t in, uint32_t w){ // nada STROBE
  uint32_t x, tmp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    tmp=binroute[count][w]|binary[w]; 

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
  uint32_t x, tmpp, tmp, val, bitrr, temp, bitn=0;
  int32_t cycle;
  static int32_t integrator;

  //  BINROUTE_;
  tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
    ROUTETYPE_;  
  
  if (bitn) val=1;
  else val=-1;
  if (CYCl) cycle=1;
  else cycle=-1;
  
  integrator+=(val-cycle);
  if (integrator>0) bitn=1;
  else bitn=0;
  
  return bitn;
}

static inline uint32_t ZpSRsigma(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, tmpp, val, bitrr, temp, bitn=0;
  int32_t cycle;
  static int32_t integrator;

  //  BINROUTE_;
  //  tmpp=in>>9; // or in can be route // 3 bits
  tmpp=gate[w].routetype;
  tmp=binroute[count][w]|binary[w]; 

  ROUTETYPE_;
  

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

static inline uint32_t pbitSRroutelog(uint32_t depth, uint32_t in, uint32_t w){ // depth
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
    if (LFSR__[w] < depth) bitn^=1;
    return bitn;
}

static inline uint32_t pbitSRroutelogxx(uint32_t depth, uint32_t in, uint32_t w){// depth
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
    if (LFSR__[w] < depth) bitn^=1;
  return bitn;
}

static inline uint32_t pbitSRroutelogD_(uint32_t depth, uint32_t in, uint32_t w){ // depth
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

static inline uint32_t pbitSRroutelogxxD_(uint32_t depth, uint32_t in, uint32_t w){// depth
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
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  uint32_t mmm=(depth>>6); // 6 bits // dacfrom 2 = total 6
  tmp=((mmm>>2) ^ (gate[mmm&3].Gshift_[w]))&3 ; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t pbitSRroutelogxxx(uint32_t depth, uint32_t in, uint32_t w){ // depth
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

static inline uint32_t pbitSRroutedoit(uint32_t depth, uint32_t in, uint32_t w){// depth
  uint32_t x, tmp, bitrr, temp, tmpp, bitn=0;

  //  tmp=(SRFROM)&63; // 4 bits route, 2 bits doit
   tmp=(gate[0].Gshift_[w])&63;
    temp=tmp&0x03;
    tmp=tmp>>2;
    if (temp!=0){
      tmpp=gate[w].routetype;
      ROUTETYPE_;  
    if (temp==2) RETURN;
    else if (temp==3){ // dacprob of inversion
      if (LFSR__[w] < depth) bitn^=1;
    }
    } // 1/2/3
    else RETURN;
  
  return bitn;
}

static inline uint32_t pbitSRroutelogxxxD_(uint32_t depth, uint32_t in, uint32_t w){ // depth
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

static inline uint32_t pbitSRroutedoitD_(uint32_t depth, uint32_t in, uint32_t w){// depth
  uint32_t x, tmp, bitrr, temp, tmpp, bitn=0;

  //    tmp=(SRFROM)&63; // 4 bits route, 2 bits doit
  tmp=(gate[0].Gshift_[w])&63;
  temp=tmp&0x03; // lowest 2 bits
    tmp=tmp>>2;
    if (temp!=0){
      tmpp=gate[w].routetype;
      ROUTETYPE_;  
    if (temp==2) RETURN;
    else if (temp==3){ // dacprob of inversion
      bitn^=1;
    }
    } // 1/2/3 temp==0;
    else RETURN;
  
  return bitn;
}


static inline uint32_t pbitLSRroutexxxlog(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;

    tmp=logopxxx((depth&255),(SRFROM)&255, (SRFROM>>8)&0x03); 
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

// from N // but to look closer at our adcs

static inline uint32_t pstream(uint32_t depth, uint32_t in, uint32_t w){ // all do ADC//depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  //  bitn^=adcpadbits(11);
  bitn^=adcpadbits(depth>>7); // 5 bits
  //  BINROUTE_;
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;  
  
  return bitn;
}

///////////////////////

// experimental port of L and R 

// C: dac, N: adc to check through...

/// extracted from R but we skipped some ghost manipulations

static inline uint32_t pSRBITMIX(uint32_t depth, uint32_t in, uint32_t w){//depth and in and we use dac so is a tough one
  uint32_t x, tmp, bitrr, temp, bitn=0;
  float mixer;
  tmp=(depth>>4); // 8 bits
    mixer=1.0f/((float)(in>>4)+1.0f);
    mixer*=(float)(gate[dacfrom[daccount][w]].dac>>4);
    // how to mix with DAC using CVL - gate[dacfrom[daccount][w]].dac
    tmp+=(int)mixer;
    if (tmp>255) tmp=255;
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
static inline uint32_t pSRLcvSRmaskroute(uint32_t depth, uint32_t in, uint32_t w){//depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  tmp=((depth>>4)) ^ DACFROM; // other logics // 8 bits
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
    // no binroute needed  
  return bitn;
  }

static inline uint32_t pSRLcvroute(uint32_t depth, uint32_t in, uint32_t w){//depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
    tmp=(depth>>4); // 8 bits
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
    // no binroute needed  
  return bitn;
}

static inline uint32_t pSR32(uint32_t depth, uint32_t in, uint32_t w){// depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
    gate[w].shift_&=spacmask[SRlength[w]]; //cleared
    if (SRlength[inroute[count][w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0])) >>(lastspac[SRlength[inroute[count][w]]][0]))+ \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))          >> ((lastspac[SRlength[inroute[count][w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))         >>((lastspac[SRlength[inroute[count][w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))         >>((lastspac[SRlength[inroute[count][w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0]))>>(lastspac[SRlength[inroute[count][w]]][0])) + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[inroute[count][w]]][1]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[inroute[count][w]]][2]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[inroute[count][w]]][3])));
    }
    bitn=gate[w].shift_&1; // fixed this 29/12/2021
    if (LFSR__[w] < depth) bitn^=1;
  return bitn;
  }

static inline uint32_t pSR32D_(uint32_t depth, uint32_t in, uint32_t w){// depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
    gate[w].shift_&=spacmask[SRlength[w]]; //cleared
    if (SRlength[inroute[count][w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0])) >>(lastspac[SRlength[inroute[count][w]]][0]))+ \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))          >> ((lastspac[SRlength[inroute[count][w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))         >>((lastspac[SRlength[inroute[count][w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))         >>((lastspac[SRlength[inroute[count][w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0]))>>(lastspac[SRlength[inroute[count][w]]][0])) + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[inroute[count][w]]][1]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[inroute[count][w]]][2]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[inroute[count][w]]][3])));
    }
    bitn=gate[w].shift_&1; // fixed this 29/12/2021
  return bitn;
  }

static inline uint32_t pSRDACroutestrobe(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  gate[w].strobed=1;
  if (gate[w].trigger){
  tmp=gate[dacfrom[daccount][w]].dac&15;
  tmpp=gate[w].routetype;
  ROUTETYPE_;  

  }
  else {
    //    BINROUTE_;
    tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
    ROUTETYPE_;  
  }
  return bitn;
}

static inline uint32_t pSRLLbumproute(uint32_t depth, uint32_t in, uint32_t w){//STROBE//depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  tmp=(depth>>8);
  gate[w].strobed=1;
  tmpp=(in>>8);
  if (tmp<=tmpp){
  if (gate[w].trigger) gate[w].route++;
  if (gate[w].route>tmpp) gate[w].route=tmp;
  }
  else
    {
  if (gate[w].trigger) gate[w].route--;
  if (gate[w].route<tmpp) gate[w].route=tmp;
    }
  
  tmp=myroute[w][gate[w].route];
  tmpp=gate[w].routetype;
  ROUTETYPE_;    
  return bitn;
}

static inline uint32_t pSRbumproute(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
  if (gate[w].trigger) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;
  tmp=myroute[w][gate[w].route];
  tmpp=gate[w].routetype;
  ROUTETYPE_;  
  if (LFSR__[w] < depth) bitn^=1;
  return bitn;
}

static inline uint32_t pSRbumprouteD_(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
  if (gate[w].trigger) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;
  tmp=myroute[w][gate[w].route];
  tmpp=gate[w].routetype;
  ROUTETYPE_;  
  return bitn;
}

static inline uint32_t pSRmod(uint32_t depth, uint32_t in, uint32_t w){//
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  tmp=binroute[count][w]|binary[w]; 

  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;    
  gate[w].shift_=gate[w].shift_%gate[x].Gshift_[w];
  }
  tmp=tmp>>1;
  }
  return bitn;
}

static inline uint32_t pSRNwas13(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, bitrr, temp, bitn=0;
  uint8_t prob; static uint8_t which[4]={};
  gate[w].strobed=1;
  if (gate[w].trigger) {
    which[w]++;
    if (which[w]>SRlength[w]) which[w]=0;
	  }
  tmp=binroute[count][w]|binary[w]; 

	  for (x=0;x<4;x++){
	    if (tmp&0x01){
	      bitrr = (gate[x].Gshift_[w]>>which[w]) & 0x01;
	      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	      bitn^=bitrr;
	    }
	    tmp=tmp>>1;
	  }	  
  return bitn;
}

static inline uint32_t pSRN65(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, bitrr, temp, bitn=0;
  static uint8_t tmpt; static uint8_t cw=0;
    gate[w].strobed=1;
      cw++;
      if (cw>31) cw=0;
      if (gate[w].trigger) tmpt=cw;
      
      //      tmp=binroute[count][w];
      tmp=binroute[count][w]|binary[w]; 

      for (x=0;x<4;x++){ 
	if (tmp&0x01) {  
	    bitrr = (gate[x].Gshift_[w]>>tmpt) & 0x01; // or can just keep tmpt for this one and len of previous
	    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	    bitn^=bitrr;
	  }
      tmp=tmp>>1;
      }	
  return bitn;
}

static inline uint32_t pSRN62(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
  //      tmp=binroute[count][w];
  tmp=binroute[count][w]|binary[w]; 

      for (x=0;x<4;x++){ 
      if (tmp&0x01){  
	bitrr = ((gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][0])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][1])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][2])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][3]))) & 1u;
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }
  return bitn;
}

static inline uint32_t pSRLLswop(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
    gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
    if (gate[w].trigger) gate[w].shift_&=gate[inroute[count][w]].Gshift_[w];
    if (LFSR__[w] < depth) bitn^=1;
  return bitn;
}

static inline uint32_t pSRLLswopD_(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
    gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
    if (gate[w].trigger) gate[w].shift_&=gate[inroute[count][w]].Gshift_[w];
  return bitn;
}

static inline uint32_t pSRN40(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
  //    BINROUTE_;
  tmpp=gate[w].routetype;
  tmp=binroute[count][w]|binary[w]; 

  ROUTETYPE_;  
  if (gate[w].trigger) gate[w].shift_=gate[oppose[w]].shift_; // sieve is previous one but could be opposite one  
  return bitn;
}

  static inline uint32_t pSRN36(uint32_t depth, uint32_t in, uint32_t w){//STROBE
    uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
      uint8_t prob;
      gate[w].strobed=1;
    if (gate[w].trigger==1) { // at start we place it...
      gate[w].shift_=gate[w].Gshift_[w];
    }
    GSHIFT_;
    //    BINROUTE_;    
    tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
    ROUTETYPE_;  
    }
  
static inline uint32_t pSRN33cipher(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    tmp=(gate[w].Gshift_[w]>>SRlength[w])& 0x01;
    gate[w].shift_+=tmp;
    
    GGGshift_[w]=GGGshift_[w]<<1;
    //    BINROUTE_;
    tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
  ROUTETYPE_;  

    
    GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    }   
  return bitn;
}

static inline uint32_t pSRN33(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    GGGshift_[w]=GGGshift_[w]<<1;
    //    BINROUTE_;
    tmp=binroute[count][w]|binary[w]; 

	tmpp=gate[w].routetype;
	ROUTETYPE_;  
    
	GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    }
    bitn=CYCl;  
  return bitn;
}

static inline uint32_t pSRN22D_(uint32_t depth, uint32_t in, uint32_t w){//depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  uint8_t prob; uint32_t bitnn, bitnnn; 
  bitn = (gate[others[w][0]].shift_>>SRlength[others[w][0]]) & 0x01;
  bitnn = (gate[others[w][1]].shift_>>SRlength[others[w][1]]) & 0x01;
  bitnnn = (gate[others[w][2]].shift_>>SRlength[others[w][2]]) & 0x01;

    //    bitn^=((gate[w].Gshift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn;
    bitn^=bitnn^bitnnn;
  return bitn;
}

static inline uint32_t pSRN21D_(uint32_t depth, uint32_t in, uint32_t w){// depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
  uint8_t prob; uint32_t bitnn, bitnnn; 
    bitn = (gate[others[w][0]].Gshift_[w]>>SRlength[others[w][0]]) & 0x01; 
    gate[others[w][0]].Gshift_[w]=(gate[others[w][0]].Gshift_[w]<<1)+bitn;

    bitnn = (gate[others[w][1]].Gshift_[w]>>SRlength[others[w][1]]) & 0x01; 
    gate[others[w][1]].Gshift_[w]=(gate[others[w][1]].Gshift_[w]<<1)+bitnn;

    bitnnn = (gate[others[w][2]].Gshift_[w]>>SRlength[others[w][2]]) & 0x01; 
    gate[others[w][2]].Gshift_[w]=(gate[others[w][2]].Gshift_[w]<<1)+bitnnn;
    
    //    bitn^=((gate[w].Gshift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn;
    bitn^=bitnn^bitnnn;
  return bitn;
}

static inline uint32_t pSRN13(uint32_t depth, uint32_t in, uint32_t w){//added depth
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  //	BINROUTE_;
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;  

  
  if (LFSR__[w]<depth){
    bitrr=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  else bitrr=!((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
  bitn=bitn|bitrr;  
  return bitn;
}

static inline uint32_t pSRN12(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    tmp=binroute[count][w]|binary[w]; 

  for (x=0;x<4;x++){
  if (tmp&0x01){
    if (gate[w].trigger) gate[x].Gshift_[w]^=gate[w].shift_;
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    if (gate[w].trigger) 
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }  
  return bitn;
}

static inline uint32_t pSRN11(uint32_t depth, uint32_t in, uint32_t w){//STROBE
    uint32_t x, tmp, bitrr, temp, tmpp, bitn=0;
      gate[w].strobed=1;
      //	tmp=binroute[count][w];
      tmp=binroute[count][w]|binary[w]; 

      for (x=0;x<4;x++){
	if (tmp&0x01){
	  if (gate[w].trigger){
	    tmpp=gate[x].Gshift_[w];
	    REV32; // reverse 32 bits
	    tmpp=tmpp&othermasky[SRlength[x]]; // mask the top length bits
	    gate[x].Gshift_[w]=tmpp>>(31-SRlength[x]); // and shift 31-length bits
	  }
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; // 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }  
  return bitn;
}

static inline uint32_t pSRN10(uint32_t depth, uint32_t in, uint32_t w){//STROBE//no depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    //    tmp=binroute[count][w];
  tmp=binroute[count][w]|binary[w]; 

    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	if (gate[w].trigger) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1;
    }  
  return bitn;
}

static inline uint32_t pSRNwas15(uint32_t depth, uint32_t in, uint32_t w){ //depth
    uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    // was15 4x4 bits prob of routing in GSR  so we need 4 probs of x bits?
	tmp=LFSR__[w];
	tmpp=4095-depth; // try with CV too
	for (x=0;x<4;x++){
	  if ((tmp&255)<(tmpp&255)){// replace with 12 bits /4 = 3 bits prob = 7 (LFSR_[w] & 4095 ) < (shift_[LFSR[w]] & 4095)
	    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	    bitn^=bitrr;
	}
	tmp=tmp>>8; tmpp=tmpp>>8;
	}	
  return bitn;
  }

// from R

static inline uint32_t pSRRLLswop(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0, lin, lout;
  //  BINROUTE_;
    gate[w].strobed=1;
  tmp=binroute[count][w]|binary[w]; 
    tmpp=gate[w].routetype;
    ROUTETYPE_;  

   
    if (gate[w].trigger) {
      lin=127-(depth>>5); //7= 2 bits for whichone and start which can be 5
      lout=31-(in>>7); // 5 bits for length
      // length of incoming - lout
      tmp=gate[lin&0x03].shift_>>(31-lout);
      gate[w].shift_^=(tmp<<(31-(lin>>2)));
      //gate[w].shift_=gate[oppose[w]].shift_; // sieve is previous one but could be opposite one
    }
  return bitn;
}

static inline uint32_t pSRRaccelghosts0(uint32_t depth, uint32_t in, uint32_t w){ /// no depth
  uint32_t x, tmp, tmpp, bitrr, bitn=0;
    for (x=0;x<4;x++){     
      bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;  // gshifts FOR 0 including our own
      gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    }
    for (x=0;x<4;x++){     
      bitrr = (gate[x].Gshift_[1]>>SRlength[x]) & 0x01;  
      gate[x].Gshift_[1]=(gate[x].Gshift_[1]<<1)+bitrr;
    }
    for (x=0;x<4;x++){     
      bitrr = (gate[x].Gshift_[2]>>SRlength[x]) & 0x01;  
      gate[x].Gshift_[2]=(gate[x].Gshift_[2]<<1)+bitrr;
    }
        
    //    BINROUTE_;
    tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
    ROUTETYPE_;
    return bitn;
}

// deprecate
static inline uint32_t pSRRbumproute0(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  //  BINROUTE_; // new routing in here.
    gate[w].strobed=1;
  if (gate[w].trigger) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;
  tmp=myroute[w][gate[w].route];

    tmpp=gate[w].routetype;
  ROUTETYPE_;  
  return bitn;
}

static inline uint32_t pSRR32D_(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t x, tmp, bitrr, temp, bitn=0;

  gate[w].shift_&=spacmask[SRlength[w]]; //cleared
    if (SRlength[inroute[count][w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0])) >>(lastspac[SRlength[inroute[count][w]]][0]))+ \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))          >> ((lastspac[SRlength[inroute[count][w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))         >>((lastspac[SRlength[inroute[count][w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))         >>((lastspac[SRlength[inroute[count][w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0]))>>(lastspac[SRlength[inroute[count][w]]][0])) + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[inroute[count][w]]][1]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[inroute[count][w]]][2]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[inroute[count][w]]][3])));
    }
    bitn=gate[w].shift_&1; // fixed this 29/12/2021
  return bitn;
}


///////////////////

// question if these repeat what we have - as anyways they can be done using prob but is more compact here

static inline uint32_t pprobintprob3(uint32_t depth, uint32_t in, uint32_t w){//depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    if (LFSR__[w]<depth){
      //    BINROUTE_;
    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
      tmpp=gate[w].routetype;
      ROUTETYPE_;  
    }
    else
      {
	//    BINROUTEANDCYCLE_;
    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
      tmp=tmp|(1<<w);
      tmpp=gate[w].routetype;
      ROUTETYPE_;  
      }
  return bitn;
}

static inline uint32_t pprobintprob5_0(uint32_t depth, uint32_t in, uint32_t w){//depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  tmp=prub[depth>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255){
      //    BINROUTE_;
    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
      tmpp=gate[w].routetype;
      ROUTETYPE_;  

    }
    else
      {
	JUSTCYCLE_;
	}
  return bitn;
}

static inline uint32_t pprobintprob6_0(uint32_t depth, uint32_t in, uint32_t w){//depth
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  //  BINROUTE_;
tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
  tmpp=gate[w].routetype;
  ROUTETYPE_;  

  tmp=prub[depth>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255){    
      bitn=!bitn;
    }
  return bitn;
}

////keep

static inline uint32_t pprobtoggle1(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    gate[w].strobed=1;
  //    BINROUTE_;
    //tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
    ROUTETYPE_;  
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) bitn=!bitn; 
  return bitn;
}

static inline uint32_t pprobtoggle2(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    gate[w].strobed=1;
  if (gate[w].trigger) tug[w]^=1;
  if (tug[w]) {
    //    BINROUTE_;
    //  tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
    ROUTETYPE_;  

  }
    else JUSTCYCLE_;
  return bitn;
}

static inline uint32_t pprobtoggle3(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    gate[w].strobed=1;
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      //      BINROUTE_;
      //    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
      ROUTETYPE_;        
    }
    else {
      //      BINROUTEANDCYCLE_;
      //    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
  tmp=binroute[count][w]|binary[w]; 

      tmp=tmp|(1<<w);
      tmpp=gate[w].routetype;
      ROUTETYPE_;  

    }
  return bitn;
}

static inline uint32_t pprobtoggle4(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    gate[w].strobed=1;
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      //      BINROUTE_;
      //    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
      ROUTETYPE_;  
    }
    else bitn=0;
  return bitn;
}

static inline uint32_t pprobtoggle5(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  static uint8_t tug[4]={0};
    gate[w].strobed=1;
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]) {
      //      BINROUTEANDCYCLE_;
      //    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

      tmp=tmp|(1<<w);
      tmpp=gate[w].routetype;
      ROUTETYPE_;  
    }
    else bitn=0;
  return bitn;
}

static inline uint32_t pprobstrobe1(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
  //  BINROUTE_;
    gate[w].strobed=1;
    //tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
  ROUTETYPE_;  
  if (gate[w].trigger) bitn=!bitn; 
  return bitn;
}

static inline uint32_t pprobstrobe2(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmp, tmpp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    if (gate[w].trigger) {
      //      BINROUTE_;
      //    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
      ROUTETYPE_;  
    }
    else JUSTCYCLE_;
  return bitn;
}

static inline uint32_t pprobstrobe3(uint32_t depth, uint32_t in, uint32_t w){ // STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    if (gate[w].trigger) {
      //     BINROUTE_;
      //    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
    ROUTETYPE_;  
    }
    else {
      //tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
  tmp=binroute[count][w]|binary[w]; 

      tmp=tmp|(1<<w);
      tmpp=gate[w].routetype;
      ROUTETYPE_;  
      //      BINROUTEANDCYCLE_;
    }
  return bitn;
}

static inline uint32_t pSRN30(uint32_t depth, uint32_t in, uint32_t w){// added depth
  uint32_t x, tmp, bitrr, temp, bitn=0;
    bitn=(gate[w].Gshift_[w]>>SRlength[w])& 0x01; 
    if ((gate[w].dac)<depth) { 
      bitn=bitn^1;
    }  
  return bitn;
}

static inline uint32_t pSRN15(uint32_t depth, uint32_t in, uint32_t w){// added depth but is simple
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  if (LFSR__[w] < depth){
    //    BINROUTEANDCYCLE_;
tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
  tmp=tmp|(1<<w);
  tmpp=gate[w].routetype;
  ROUTETYPE_;  
	}
  else {
    bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
  }	  
  return bitn;
}

static inline uint32_t pSRN8(uint32_t depth, uint32_t in, uint32_t w){//STROBE/
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  uint8_t prob; static uint8_t tug[4]={0};
  gate[w].strobed=1;
    if (gate[w].trigger) tug[w]^=1;
    if (tug[w]){
      //      BINROUTEANDCYCLE_;
      //    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmp=tmp|(1<<w);
    tmpp=gate[w].routetype;
    ROUTETYPE_;  
    }
    else {
      bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }	  
  return bitn;
}

static inline uint32_t pSRN7(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    if (gate[w].trigger){
      //      BINROUTE_;
      //    tmp=binroute[count][w]|binary[w]; 
// was tmp=binroute[count][w]|binary[w];
tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
      ROUTETYPE_;  
    }
    else {
      bitn=!(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }	  
  return bitn;
}

static inline uint32_t pSRN6(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
    gate[w].strobed=1;
    if (gate[w].trigger){
      //      BINROUTE_;
      tmp=binroute[count][w]|binary[w]; 

    tmpp=gate[w].routetype;
    ROUTETYPE_;  
    }
    else {
      bitn=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }  
  return bitn;
}

static inline uint32_t pSRN5(uint32_t depth, uint32_t in, uint32_t w){//STROBE
  uint32_t x, tmpp, tmp, bitrr, temp, bitn=0;
  //    BINROUTE_;
    gate[w].strobed=1;
   tmp=binroute[count][w]|binary[w]; 
      
    tmpp=gate[w].routetype;
    ROUTETYPE_;  
    if (gate[w].trigger)	  bitrr=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
    else bitrr=!((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
    bitn=bitn|bitrr;  
  return bitn;
}

