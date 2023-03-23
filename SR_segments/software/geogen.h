// new macro for binroutetypes - tmpp is type, tmp is route
#define ROUTETYPE_ {				\
    switch(tmpp){				\
    case 1:					\
    BINROUTESRstrip_;				\
    break;					\
    case 2:					\
    BINROUTEaltstrip_;				\
    break;					\
    case 3:					\
    BINROUTEZEROstrip_;				\
    break;					\
    case 4:					\
    BINROUTESHAREstrip_;			\
    break;					\
    case 5:					\
    BINROUTENOGstrip_;				\
    break;					\
    case 6:					\
    BINROUTECYCstrip_;				\
    break;					\
    case 7:					\
    BINROUTEnoaltstrip_;			\
    break;					\
    default:					\
    BINROUTEstrip_;				\
    }						\
     }

// strips is all cycles??? - for succbits
#define ROUTETYPES_ {				\
  switch(tmpp){					\
    case 1:					\
    BINROUTESRstrips_;				\
    break;					\
    case 2:					\
    BINROUTEaltstrips_;				\
    break;					\
    case 3:					\
    BINROUTEZEROstrips_;			\
    break;					\
    case 4:					\
    BINROUTESHAREstrips_;			\
    break;					\
    case 5:					\
    BINROUTENOGstrips_;				\
    break;					\
    case 6:					\
    BINROUTECYCstrips_;				\
    break;					\
    case 7:					\
    BINROUTEnoaltstrips_;			\
    break;					\
    default:					\
    BINROUTEstrips_;				\
    }						\
     }

////////////////////////////////////////////////////////////////////////// 13/2/2023
//TRIADEX: use of different parity switches - do we still have this?
// bits go into parity from say all SR with diff functions = 4x 32 bits = 4 selectors of 128 bits or we use CV CVL (depth and IN) so is just 2!
// so we have 2 selectors - each is 128 so select one of SR/shiftr to shift out bit x and ^
uint32_t triadexbits(uint32_t depth, uint32_t in, uint32_t w){   
  uint32_t x,bitn=0, bitrr, tmpp,tmp;
  depth=depth>>5; // 7 bits left
  tmp=depth>>5;// 2 top bits for which SR
  tmpp=depth&31;// // 5 lower bits for the bit 
  bitn=(gate[tmp].shift_>>tmpp)&0x01;

  in=in>>5; // 7 bits left
  tmp=in>>5;// 2 top bits for which SR
  tmpp=in&31;// // 5 lower bits for the bit 
  bitn^=(gate[tmp].shift_>>tmpp)&0x01;
  return bitn;
}

////////////////////////////////////////////////////////////////////////// 25/10/2022 - // adding 13/12/2022
// basic binroutes with depth and in for route in and routetypes...

 uint32_t ZzbinrouteINVbits(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now NO LONGER USES DEPTH
  uint32_t x,bitn=0, bitrr, tmpp,tmp;
  depth=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  tmp=depth;
  ROUTETYPE_;
  bitn=!bitn;
  return bitn;
}

static inline uint32_t Zzbinroutebitscycle(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now
  uint32_t x, tmp, tmpp, bitn=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  tmp=depth|(1<<w); // adds itself
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t Zflipflopandroute(uint32_t depth, uint32_t in, uint32_t w){  // so all share // DEPTH
  uint32_t bitn, bitrr, x, tmp, tmpp;
  static uint32_t fl=0;
  fl=fl^1;
  bitn=fl;
  tmpp=gate[w].routetype;
  tmp=binroute[count][w]|binary[w]; 
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t Zbinrout(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  depth=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  tmp=depth;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t ZbinroutSTR(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  depth=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  tmp=depth;
  ROUTETYPE_;
  bitn^=TRIGGER;
  return bitn;
}

static inline uint32_t ZbinroutTOG(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  static uint8_t tug[4]={0};
  tug[w]^=gate[w].trigger;  
  depth=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  tmp=depth;
  ROUTETYPE_;
  bitn^=tug[w];
  return bitn;
}

static inline uint32_t Zbinrouteforalt(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  depth=binroute[count][w]; 
  tmpp=gate[w].routetype;
  tmp=depth;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t Zbinrouteforaltalt(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  tmp=altbinroute[count][w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t Zbinrout_strip(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  depth=depth>>8; // 4 bits
  tmpp=gate[w].routetype;
  if (depth==0) {
        tmp=binroute[count][w]|binary[w];  
  } else
    {
      tmp=depth;
    }
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t Zbinrout_stripSTR(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  depth=depth>>8; // 4 bits
  tmpp=gate[w].routetype;
  if (depth==0) {
        tmp=binroute[count][w]|binary[w];  
  } else
    {
      tmp=depth;
    }
  ROUTETYPE_;
  bitn^=TRIGGER;
  return bitn;
}

static inline uint32_t Zbinrout_stripTOG(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  static uint8_t tug[4]={0};
  tug[w]^=gate[w].trigger;  
  depth=depth>>8; // 4 bits
  tmpp=gate[w].routetype;
  if (depth==0) {
        tmp=binroute[count][w]|binary[w];  
  } else
    {
      tmp=depth;
    }
  ROUTETYPE_;
  bitn^=tug[w];
  return bitn;
}

// these ones are different in terms of use of depth
static inline uint32_t Zbinroutor(uint32_t depth, uint32_t in, uint32_t w){ // 4 bits binroute ORed with selected 4 bits SR.. // try to mod for generic routes
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  depth=depth>>6; // 12 bits to 6 bits
  // top 2 bits as SR select
  tmp=(depth>>4)&3;
  depth=depth| (gate[tmp].shift_&15);    
  depth=depth&15;
    // deal with no route
    if (depth==0) { 
      tmp=binroute[count][w]|binary[w];	  
    } else
  {
      tmp=depth;
  }
      tmpp=gate[w].routetype;
      ROUTETYPE_;
  return bitn;
}

static inline uint32_t Zviennabits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bitn=0, tmp, tmpp, recurs, bitrr,x;
  // 7 bits from mode/now CVL - 
  tmpp=127-(depth>>5); // 7 bits  
  if (tmpp>>6) recurs=1; // top bit
  
  if (recurs!=0 && w==2){ // for C only  // why?
    tmpp|=(gate[others[w][0]].shift_)&15;    
  }
  
  if (tmpp==0 && w==2) {// - for modeC only
    tmp=binroute[count][w]|binary[w]; 
  }
else
  {
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
  }
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  return bitn;
}

//type and depth: 
static inline uint32_t Zzsuccbitspp(uint32_t depth, uint32_t in, uint32_t w){   // depth // with TYPE
  // include itself or not
  uint32_t bitn=0, bitrr, tmpp;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  if ((depth>>4)>(LFSR__[w]>>4)) x++;
  return bitn;
}

static inline uint32_t Zzsuccbitsppin(uint32_t depth, uint32_t in, uint32_t w){   // depth // with TYPE with in
  // include itself or not
  uint32_t bitn=0, bitrr, tmpp;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  if ((depth>>4)>(in>>4)) x++;
  return bitn;
}

static inline uint32_t ZzsuccbitsppS_(uint32_t depth, uint32_t in, uint32_t w){   // depth // with TYPE
  // include itself or not
  uint32_t bitn=0, bitrr, tmpp;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  if ((depth>>4)>(LFSR__[w]>>4)) x++;
  return bitn;
}

static inline uint32_t ZzsuccbitsppS_in(uint32_t depth, uint32_t in, uint32_t w){   // depth // with TYPE
  // include itself or not
  uint32_t bitn=0, bitrr, tmpp;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  if ((depth>>4)>(in>>4)) x++;
  return bitn;
}

/// depth and type: Zzsuccbitspp, ZzsuccbitsppS_, ZzsuccbitsIpp, Zzsuccbitsppin, ZzsuccbitsppS_in, ZzsuccbitsIppin

static inline uint32_t ZzsuccbitsIpp(uint32_t depth, uint32_t in, uint32_t w){   // depth // with TYPE
  // include itself or not
  uint32_t x, tmpp, bitn=0, bitrr;
  static uint32_t xx[4]={0};
  if (xx[w]==w) xx[w]++;
  if (xx[w]>3) xx[w]=0;
  x=xx[w];
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  if ((depth>>4)>(LFSR__[w]>>4)) xx[w]++;
  return bitn;
}

static inline uint32_t ZzsuccbitsIppin(uint32_t depth, uint32_t in, uint32_t w){   // depth // with TYPE with in
  // include itself or not
  uint32_t x, tmpp, bitn=0, bitrr;
  static uint32_t xx[4]={0};
  if (xx[w]==w) xx[w]++;
  if (xx[w]>3) xx[w]=0;
  x=xx[w];
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  if ((depth>>4)>(in>>4)) xx[w]++;
  return bitn;
}

/////////////////////////////////
// succbits grouped here - no depth
static inline uint32_t Zzsuccbits(uint32_t depth, uint32_t in, uint32_t w){   // no depth - we route from each sr in turn // with TYPE
  // include itself or not
  uint32_t bitn=0, bitrr, tmpp;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  x++;
  return bitn;
}

static inline uint32_t ZzsuccbitsI(uint32_t depth, uint32_t in, uint32_t w){   // no depth - we route from each sr in turn - independent version // with TYPE
  // include itself or not
  uint32_t x, tmpp, bitn=0, bitrr;
  static uint32_t xx[4]={0};
  if (xx[w]==w) xx[w]++;
  if (xx[w]>3) xx[w]=0;
  x=xx[w];
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  xx[w]++;
  return bitn;
}

static inline uint32_t Zbinrout_probXY(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  tmp=binroute[count][w]|binary[w];
  if ((depth>>4)<(in>>4)) tmp=tmp^15;
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t NZbinrout_probXY(uint32_t depth, uint32_t in, uint32_t w){  // was RD
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  tmp=binroute[count][w]|binary[w];
  if ((depth>>4)<(LFSR_[w])) tmp=tmp^15;
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t Zbinrout_probXY1(uint32_t depth, uint32_t in, uint32_t w){   
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  if ((depth>>4)<(in>>4)){
    tmp=binroute[count][w]|binary[w];
  }
  else {
    tmp=gate[dacfrom[daccount][w]].dac>>8;//|binary[w];    
    if (tmp==0) { 
      tmp=binroute[count][w]|binary[w];    
    } 
  }
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t NZbinrout_probXY1(uint32_t depth, uint32_t in, uint32_t w){   // was RD
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  //  if (depth<(LFSR__[w]>>4)) {
  if ((depth>>4)<((LFSR__[w]>>4))){
    tmp=binroute[count][w]|binary[w];
  }
  else {
    tmp=gate[dacfrom[daccount][w]].dac>>8;//|binary[w];    
    if (tmp==0) { 
      tmp=binroute[count][w]|binary[w];
    }
  }
  tmpp=gate[w].routetype;
    ROUTETYPE_;
  return bitn;
}

static inline uint32_t Zbinroutfixed_probzero(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed vs zeroes
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  if ((depth>>4)>(in>>4)) {
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
      bitn = 0;
    }
  return bitn;
}

static inline uint32_t NZbinroutfixed_probzero(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed vs zeroes
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  if ((depth>>4)<((LFSR__[w]>>4))){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
      bitn = 0;
    }
  return bitn;
}

static inline uint32_t Zbinroutfixed_prob1(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  //  if ((depth>>4)<(in>>4)) {
  if ((depth>>4)<(in>>4)){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  return bitn;
}

static inline uint32_t NZbinroutfixed_prob1(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  //  if (depth<(LFSR__[w]>>4)) {
  if ((depth>>4)<((LFSR__[w]>>4))){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  return bitn;
}

//A has ADCgen to update ADCin
static inline uint32_t NZbinroutfixed_prob1A(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  ADCgen;
  if ((depth>>4)<((LFSR__[w]>>4))){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  return bitn;
}

static inline uint32_t Zbinroutfixed_prob1STR(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  //  if ((depth>>4)<(in>>4)) {
  if ((depth>>4)<(in>>4)){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  bitn^=TRIGGER;
  return bitn;
}

static inline uint32_t NZbinroutfixed_prob1STR(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  //  if (depth<(LFSR__[w]>>4)) {
  if ((depth>>4)<((LFSR__[w]>>4))){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  bitn^=TRIGGER;
  return bitn;
}

//

static inline uint32_t Zbinroutfixed_prob1TOG(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  static uint8_t tug[4]={0};
  tug[w]^=gate[w].trigger;  
  if ((depth>>4)<(in>>4)){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
    bitn^=tug[w];
  return bitn;
}

static inline uint32_t NZbinroutfixed_prob1TOG(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  static uint8_t tug[4]={0};
  tug[w]^=TRIGGER;  

  //  if (depth<(LFSR__[w]>>4)) {
  if ((depth>>4)<((LFSR__[w]>>4))){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  bitn^=tug[w];
  return bitn;
}


static inline uint32_t Zbinroutfixed_prob2(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - // prob of inverting routed bit // fixed
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  tmp=binroute[count][w]|binary[w];
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  if ((depth>>4)<(in>>4)) bitn=!bitn;
  return bitn;
}

static inline uint32_t NZbinroutfixed_prob2(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - // prob of inverting routed bit // fixed // was RD
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  tmp=binroute[count][w]|binary[w];
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  if ((depth>>4)<(LFSR__[w]>>4)) bitn=!bitn;
  return bitn;
}

static inline uint32_t Zbinroutfixed_prob3(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - prob of routed or cycling INV
  uint32_t bitn=0, bitrr, x, tmp, tmpp;
  if ((depth>>4)<(in>>4)) {
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
      bitn = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
    }
  return bitn;
}

static inline uint32_t NZbinroutfixed_prob3(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - prob of routed or cycling INV
  uint32_t bitn=0, bitrr, x, tmp, tmpp;
  if ((depth>>4)<(LFSR__[w]>>4)) {
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else
    {
      bitn = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
    }
  return bitn;
}

static inline uint32_t Zbinroutfixed_prob4(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - *routed vs [routed^cycling]* -- fixed
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  tmp=binroute[count][w]|binary[w];
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  if ((depth>>4)<(in>>4)) {
    bitn^=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bitn;
}

static inline uint32_t NZbinroutfixed_prob4(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - *routed vs [routed^cycling]* -- fixed
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  tmp=binroute[count][w]|binary[w];
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  if ((depth>>4)>(LFSR__[w]>>4)) {
    bitn^=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bitn;
}

static inline uint32_t Zbinroutfixed_prob5(uint32_t depth, uint32_t in, uint32_t w){   // new prob 8/12 of theroute vs binroute RD ->
  uint32_t bitn=0, bitrr, tmp, x, tmpp;
  tmpp=gate[w].routetype;
  if ((depth>>4)<(LFSR__[w]>>4)) {
  tmp=binroute[count][w]|binary[w];
  }
  else tmp=in>>8;
  if (tmp==0) { 
    tmp=binroute[count][w]|binary[w];
  }
  ROUTETYPE_;
  return bitn;
}

/* NZ/Z
prob1: route vs cycle
prob2: inv routed bit
prob3: route vs inv cycle
prob4: routed vs [routed^cycling]
prob5: in as route vs fixed route
 */

static inline uint32_t zwiardinvbits(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if ((depth>>4)<(in>>4)){
    tmp=binroute[count][w]|binary[w]; 
    for (uint32_t x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
	bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bt;
}

static inline uint32_t zwiardinvbitsS_(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if ((depth>>4)<(in>>4)){
    tmp=binroute[count][w]|binary[w]; 
    for (uint32_t x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
	bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }

  return bt;
}

static inline uint32_t zwiardinvbitsL(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if ((depth>>4)<(LFSR__[w]>>4)){
    tmp=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bt;
}

static inline uint32_t zwiardnotinvbits(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if ((depth>>4)<(in>>4)){
    tmp=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = ((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bt;
}


static inline uint32_t zwiardnotinvbitsL(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if ((depth>>4)<(LFSR__[w]>>4)){
    tmp=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = ((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bt;
}

static inline uint32_t zwiardnotinvbitsS_(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if ((depth>>4)<(in>>4)){
    tmp=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = ((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bt;
}

static inline uint32_t zwiardnotinvbitsLS_(uint32_t depth, uint32_t in, uint32_t w){//global
  uint32_t bt=0, bitrr, tmp;
  if ((depth>>4)<(LFSR__[w]>>4)){
    tmp=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = ((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bt;
}

//////////////////////////////////////////////////////////////////////////

static inline uint32_t NZzwiardbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  if ((depth>>4)>(LFSR__[w]>>4)){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else {
  bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bitn;
}

static inline uint32_t NZzwiardinvbits(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bitn=0, bitrr, x, tmpp, tmp;
  if ((depth>>4)>(LFSR__[w]>>4)){
    tmp=binroute[count][w]|binary[w];
    tmpp=gate[w].routetype;
    ROUTETYPE_;
  }
  else {
    bitn = !((gate[w].Gshift_[w]>>SRlength[w]) & 0x01);
  }
  return bitn;
}

static inline uint32_t binrout_probXY2(uint32_t depth, uint32_t in, uint32_t w){   // //global
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][w]|binary[w];
  for (uint32_t x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
      if ((depth>>4)<(LFSR__[w]>>4)) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
      bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t binrout_probXY3(uint32_t depth, uint32_t in, uint32_t w){   // can be more of these!! //global
  uint32_t x, bt=0, bitrr, tmp, bitn=0;
  tmp=binroute[count][w]|binary[w];
  if ((depth>>4)<(LFSR__[w]>>4)) {
      BINROUTEalt_;
  }
  else
    {
      BINROUTEZERO_;
    }
  return bitn;
}

//////////////////////////////////////////////////////////////////////////
// binroute_probabilities - fixed routes

static inline uint32_t binroutfixed_prob1R(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling // route from R
  uint32_t bt=0, bitrr;
  if ((depth>>4)<(LFSR__[w]>>4)) {
    bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[3].Gshift_[w]=(gate[3].Gshift_[w]<<1)+bt;
  }
    else
    {
    bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  return bt;
}

static inline uint32_t binroutfixed_prob1L(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling // route from L
  uint32_t bt=0, bitrr;
    if ((depth>>4)<(LFSR__[w]>>4)) {
    bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[1].Gshift_[w]=(gate[1].Gshift_[w]<<1)+bt;
     }
    else
    {
      bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
    }
  return bt;
}

static inline uint32_t zbinroutfixed_prob1R(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling // route from R
  uint32_t bitn=0, tmpp, x, bitrr;
  if ((depth>>4)<(LFSR__[w]>>4)) {
    x=3;
    tmpp=gate[w].routetype;
    ROUTETYPES_;    
  }
    else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  return bitn;
}

static inline uint32_t zbinroutfixed_prob1L(uint32_t depth, uint32_t in, uint32_t w){   // prob of routed or cycling // route from R
  uint32_t bitn=0, tmpp, x, bitrr;
  if ((depth>>4)<(LFSR__[w]>>4)) {
    x=1;
    tmpp=gate[w].routetype;
    ROUTETYPES_;    
  }
    else
    {
    bitn = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; 
    }
  return bitn;
}

//////////////////////////////////////////////////////////////////////////
// tails

// tail which is flipflop at speed of modeR - could be faster to always do in modeR rather than re-calc spd. or just a flag//same thing but if w==3 slows
void fliptail(void){ //
  // we can also use other gate[w].flips or even move through these
  //  HEADNADA;
  uint32_t w=4;
  GSHIFT_;//RED_;
  gate[4].shift_+=gate[3].flip;
}

// replace flip with - tail as cut off segment repeats/sides
// on entry copy reg and just circulate
void sever(void){ 
  uint32_t w=4;
  HEADNADAT;
  static uint32_t sharey=0xffff;
  GSHIFT_;
  if (gate[3].changed==1) { // but changed stays 
    sharey=gate[3].Gshare_;    
      }
  bitn=(sharey>>SRlength[w]) & 0x01;
  sharey=(sharey<<1)+bitn;
  gate[4].shift_+=bitn;  
}

void basictail(void){ // tail here is basic 4th binroute at full speed // now 2ndn//left side
  uint32_t w=4;
  HEADNADAT;
  GSHIFT_;
  tmp=binroute[count][2]; // was 2... routes from ? 8124=2 // not 3?
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
      bitn^=bitrr;    
    }
    tmp=tmp>>1;
  }
  gate[w].shift_+=bitn;
}

void succtail(void){
  uint32_t bt=0;
  static uint32_t xx=0;
  uint32_t w=4;
  GSHIFT_;
  if (xx>3) xx=0;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  gate[xx].Gshift_[w]=(gate[xx].Gshift_[w]<<1)+bt;
  xx++;
  gate[w].shift_+=bt;
}

void succtailback(void){
  uint32_t bt=0;
  static int32_t xx=0;
  uint32_t w=4;
  GSHIFT_;
  if (xx<0) xx=3;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  gate[xx].Gshift_[w]=(gate[xx].Gshift_[w]<<1)+bt;
  xx--;
  gate[w].shift_+=bt;
}

void tailN(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
  gate[0].Gshift_[w]=(gate[0].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void tailL(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01;
  gate[1].Gshift_[w]=(gate[1].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void tailR(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01;
  gate[3].Gshift_[w]=(gate[3].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void tailC(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01;
  gate[2].Gshift_[w]=(gate[2].Gshift_[w]<<1)+bt;
  gate[w].shift_+=bt;
}

void basictailnos(void){ // tail here is basic 4th binroute at full speed
  uint32_t w=4;
  HEADNADAT;
  GSHIFT_;
  tmp=binroute[count][2]; // was 2... routes from ? 8124=2 // not 3?
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      bitn^=bitrr;    
    }
    tmp=tmp>>1;
  }
  gate[w].shift_+=bitn;
}

void tailLnos(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01;
  gate[w].shift_+=bt;
}

void tailRnos(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01;
  gate[w].shift_+=bt;
}

void tailCnos(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01;
  gate[w].shift_+=bt;
}

void tailNnos(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
  gate[w].shift_+=bt;
}

void succtailnos(void){
  uint32_t bt=0;
  static uint32_t xx=0;
  uint32_t w=4;
  GSHIFT_;
  if (xx>3) xx=0;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  xx++;
  gate[w].shift_+=bt;
}

void succtailbacknos(void){
  uint32_t bt=0;
  static int32_t xx=0;
  uint32_t w=4;
  GSHIFT_;
  if (xx<0) xx=3;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  xx--;
  gate[w].shift_+=bt;
}

void basictailinv(void){ // tail here is basic 4th binroute at full speed
  uint32_t w=4;
  HEADNADAT;
  GSHIFT_;
  tmp=binroute[count][2]; // was 2... routes from ? 8124=2 // not 3?
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
      bitn^=bitrr;    
    }
    tmp=tmp>>1;
  }
  gate[w].shift_+=!bitn;
}

void succtailinv(void){
  uint32_t bt=0;
  static uint32_t xx=0;
  uint32_t w=4;
  GSHIFT_;
  if (xx>3) xx=0;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  gate[xx].Gshift_[w]=(gate[xx].Gshift_[w]<<1)+bt;
  xx++;
  gate[w].shift_+=!bt;
}

void succtailbackinv(void){
  uint32_t bt=0;
  static int32_t xx=0;
  uint32_t w=4;
  GSHIFT_;
  if (xx<0) xx=3;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  gate[xx].Gshift_[w]=(gate[xx].Gshift_[w]<<1)+bt;
  xx--;
  gate[w].shift_+=!bt;
}

void tailNinv(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
  gate[0].Gshift_[w]=(gate[0].Gshift_[w]<<1)+bt;
  gate[w].shift_+=!bt;
}

void tailLinv(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01;
  gate[1].Gshift_[w]=(gate[1].Gshift_[w]<<1)+bt;
  gate[w].shift_+=!bt;
}

void tailRinv(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01;
  gate[3].Gshift_[w]=(gate[3].Gshift_[w]<<1)+bt;
  gate[w].shift_+=!bt;
}

void tailCinv(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01;
  gate[2].Gshift_[w]=(gate[2].Gshift_[w]<<1)+bt;
  gate[w].shift_+=!bt;
}

void basictailnosinv(void){ // tail here is basic 4th binroute at full speed
  uint32_t w=4;
  HEADNADAT;
  GSHIFT_;
  tmp=binroute[count][2]; // was 2... routes from ? 8124=2 // not 3?
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      bitn^=bitrr;    
    }
    tmp=tmp>>1;
  }
  gate[w].shift_+=!bitn;
}

void tailLnosinv(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01;
  gate[w].shift_+=!bt;
}

void tailRnosinv(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01;
  gate[w].shift_+=!bt;
}

void tailCnosinv(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01;
  gate[w].shift_+=!bt;
}

void tailNnosinv(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
  gate[w].shift_+=!bt;
}

void succtailnosinv(void){
  uint32_t bt=0;
  static uint32_t xx=0;
  uint32_t w=4;
  GSHIFT_;
  if (xx>3) xx=0;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  xx++;
  gate[w].shift_+=!bt;
}

void succtailbacknosinv(void){
  uint32_t bt=0;
  static int32_t xx=0;
  uint32_t w=4;
  GSHIFT_;
  if (xx<0) xx=3;
  bt = (gate[xx].Gshift_[w]>>SRlength[xx]) & 0x01;
  xx--;
  gate[w].shift_+=!bt;
}

void tailXOR0(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[3].Gshift_[w]>>SRlength[3]) & 0x01; 
  bt ^= (gate[0].Gshift_[w]>>SRlength[0]) & 0x01; 
  gate[w].shift_+=bt;
}

void tailXOR1(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[2].Gshift_[w]>>SRlength[2]) & 0x01; 
  bt ^= (gate[0].Gshift_[w]>>SRlength[0]) & 0x01; 
  gate[w].shift_+=bt;
}

void tailOR(void){
  uint32_t bt=0;
  uint32_t w=4;
  GSHIFT_;
  bt = (gate[1].Gshift_[w]>>SRlength[1]) & 0x01; 
  bt ^= (gate[0].Gshift_[w]>>SRlength[0]) & 0x01; 
  gate[w].shift_+=bt;
}


//////////////////////////////////////////////////////////////////////////
//1
//routes

static inline uint32_t binrout(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now 
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
    for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binroutI(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel -> indie version
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
    for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
    }
  return bt;
}

static inline uint32_t binroutAND0(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now // 
  uint32_t bt=0, bitrr, once=0;
  depth=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
    if (depth&0x01 && x!=w){  // never itself
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    if (once==0) bt=bitrr; // but that is always lowest one of the route... but only a difference with more than 2 routes or?
    else bt&=bitrr; 
    once++;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binroutAND00(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... GShift_ indie version
  uint32_t bt=0, bitrr, once=0;
  depth=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
    if (depth&0x01 && x!=w){  // never itself
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    if (once==0) bt=bitrr; // but that is always lowest one of the route... but only a difference with more than 2 routes or?
    else bt&=bitrr; 
    once++;
  }
  depth=depth>>1;
  }
  return bt;
}


static inline uint32_t zjustcycle(uint32_t depth, uint32_t in, uint32_t w){ // just cycle// no depth
  uint32_t bt;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t zjustcycleSTR(uint32_t depth, uint32_t in, uint32_t w){ // just cycle// no depth
  uint32_t bt;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  bt^=TRIGGER;
  return bt;
}

static inline uint32_t zjustcycleTOG(uint32_t depth, uint32_t in, uint32_t w){ // just cycle// no depth
  uint32_t bt;
  static uint8_t tug[4]={0};
  tug[w]^=gate[w].trigger;  
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  bt^=tug[w];
  return bt;
}

static inline uint32_t zjusttail(uint32_t depth, uint32_t in, uint32_t w){ // just tail// no depth
  uint32_t bt;
  bt = (gate[4].Gshift_[w]>>SRlength[4]) & 0x01;// tail
  return bt;
}

static inline uint32_t zjusttailwithdepthS_(uint32_t depth, uint32_t in, uint32_t w){ // just tail// with depth - how?
  uint32_t bt;
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  bt = (gate[4].Gshift_[4]>>SRlength[4]) & 0x01;// tail

  if(gate[w].last_time<gate[w].int_time) {
    bt|=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }

  return bt;
}

static inline uint32_t zbinroutfixed(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count //global
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t binroutfixed(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count //global
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][w]|binary[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t binroutaltreset(uint32_t depth, uint32_t in, uint32_t w){   // STROBE resets alt binroute
  uint32_t bt=0, bitrr, tmp, x;
  tmp=binroute[count][w]|binary[w]; 
  for (x=0;x<4;x++){
  if (tmp&0x01){
  if (gate[w].trigger){
  gate[w].gsrcnt[x]=SRlength[x];
  }
    bitrr = (gate[x].Gshift_[w]>>gate[w].gsrcnt[x]) & 0x01;
    gate[w].gsrcnt[x]--;
    if (gate[w].gsrcnt[x]<0) gate[w].gsrcnt[x]=SRlength[x];
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t zbinroutmycvalt(uint32_t depth, uint32_t in, uint32_t w){   // CV->myroute so we can use DAC // depth
  uint32_t bitn=0, bitrr, tmp, tmpp, x;
  if ((depth>>4)<(LFSR__[w]>>4))  gate[w].altroute++;
  if (gate[w].altroute>15) gate[w].altroute=1;
  tmp=gate[w].altroute;
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t zbinroutmybumpSalt(uint32_t depth, uint32_t in, uint32_t w){   // bumping myroute STROBE // route
  uint32_t bitn=0, bitrr, tmp, tmpp, x;
  if (gate[w].trigger) gate[w].altroute++;
  if (gate[w].altroute>15) gate[w].altroute=1;
  tmp=gate[w].altroute;
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t zbinroutmybumpbitalt(uint32_t depth, uint32_t in, uint32_t w){   // bumping myroute bits // no depth
  uint32_t bitn=0, bitrr, tmp, tmpp, x;
  if (gate[dacfrom[daccount][w]].shift_&0x01) gate[w].altroute++;
  if (gate[w].altroute>15) gate[w].altroute=1;
  tmp=gate[w].altroute;
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t zbinroutmybumpbittalt(uint32_t depth, uint32_t in, uint32_t w){   // bumping myroute bits // no depth
  uint32_t bitn=0, bitrr, tmp, tmpp, x;
  if (gate[dacfrom[daccount][w]].Gshift_[w]) gate[w].altroute++;
  if (gate[w].altroute>15) gate[w].altroute=1;
  tmp=gate[w].altroute;
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t binroutesel0(uint32_t depth, uint32_t in, uint32_t w){ // no depth, no in
  uint32_t x, tmp, bitrr, bitn=0;
  uint32_t tmpp=gate[w].routetype;
    switch(tmpp){
    case 1:
      BINROUTESR_;
    break;
    case 2:
      BINROUTEalt_;
    break;
    case 3:
      BINROUTEZERO_;
    break;
    case 4:
      BINROUTESHARE_;
    break;
    case 5:
      BINROUTENOG_;
    break;
    case 6:
      BINROUTECYC_;
    break;
    case 7:
      BINROUTEnoalt_;  // new one which just cycles and doesn't reset
    break;
    default:
      BINROUTE_;
    }
    return bitn;
}

static inline uint32_t binroutor(uint32_t depth, uint32_t in, uint32_t w){ // 4 bits binroute ORed with selected 4 bits SR..
  uint32_t bt=0, bitrr, tmp;
  depth=depth>>6; // 12 bits to 6 bits
  // top 2 bits as SR select
  tmp=(depth>>4)&3;
  depth=depth| (gate[tmp].shift_&15);    
  depth=depth&15;
  
  if (depth==0) { 
    bitrr = (gate[4].Gshare_>>SRlength[4]) & 0x01; 
    gate[4].Gshare_=(gate[4].Gshare_<<1)+bitrr;
    bt^=bitrr;
  } else
    {
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t zsingleroutebits(uint32_t depth, uint32_t in, uint32_t w){  // just route from 0-3 single route
  uint32_t bt=0, bitrr;
  depth=depth>>10; // 12 bits to 2 bits
    // deal with no route
  if (depth==0) { 
    bitrr = (gate[4].Gshare_>>SRlength[4]) & 0x01; 
    gate[4].Gshare_=(gate[4].Gshare_<<1)+bitrr;
    bt^=bitrr;
  } else
    {
  bitrr = (gate[depth].Gshift_[w]>>SRlength[depth]) & 0x01; 
  gate[depth].Gshift_[w]=(gate[depth].Gshift_[w]<<1)+bitrr;
  bt=bitrr;
    }
  return bt;
}

static inline uint32_t zzsingleroutebits(uint32_t depth, uint32_t in, uint32_t w){  // just route from 0-3 single route
  uint32_t bitn=0, bitrr, x, tmpp;
  depth=depth>>10; // 12 bits to 2 bits
  if (depth==0) depth=4;
  x=depth;
  tmpp=gate[w].routetype;
  ROUTETYPES_;
  return bitn;
}

static inline uint32_t zbinrouteINVbits(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  bt=!bt;
  return bt;
}

static inline uint32_t zbinroutebits_noshift_transit(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now - no shift of GSR<<
  uint32_t btt=0,bt=0, bitrr;
  static uint32_t lastone[4];
  depth=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  if (lastone[w]!=bt) btt=1; // it was a transition 0-1 1-0
  lastone[w]=bt;
  return btt;
}

static inline uint32_t zbinroutebits_noshift_transitd(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now - no shift of GSR<<
  uint32_t btt=0,bt=0, bitrr;
  static uint32_t lastone[4];
  depth=depth>>8;
   if (depth==0) { 
    bitrr = (gate[4].shift_>>SRlength[4]) & 0x01; 
    bt^=bitrr;
   } else
    {
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  if (lastone[w]!=bt) btt=1; // it was a transition 0-1 1-0
  lastone[w]=bt;
  return btt;
}

static inline uint32_t zbinroutebits_noshift(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now - no shift of GSR<<
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t ztemplateBURSTflip(uint32_t depth, uint32_t in, uint32_t w){ // uses IN
  uint32_t bt=0, tmp;
  static uint32_t btt[5]={0,0,0,0,0};
  depth=4095-depth;
  if (LFSR__[w]>in){ 
    train[w]=0;
    btt[w]^=1;
    }
  if (train[w]< (depth)){
  train[w]++;
  }
  else {
    train[w]=0;
    btt[w]^=1;
  }
  return btt[w];
}

static inline uint32_t zSRBURSTflip(uint32_t depth, uint32_t in, uint32_t w){ // 
  uint32_t bt=0, bitrr, tmp;
  static uint32_t btt[5]={0,0,0,0,0};
  depth=4095-depth;
  tmp=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (bt){
    train[w]=0;
    btt[w]^=1;
  }
  if (train[w]< (depth>>4)){
  train[w]++;
  //  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  }
  else {
    train[w]=0;
    btt[w]^=1;
  }
  return btt[w];
}

static inline uint32_t ztemplateBURSTflipS_(uint32_t depth, uint32_t in, uint32_t w){ // uses IN
  uint32_t bt=0, tmp;
  static uint32_t btt[5]={0,0,0,0,0};
  depth=4095-depth;
  if (LFSR__[w]>in){ // condition?
    train[w]=0;
    btt[w]^=1;
    }
  if (train[w]< (depth)){
  train[w]++;
  }
  else {
    train[w]=0;
    btt[w]^=1;
  }
  return btt[w];
}

static inline uint32_t zSRBURSTflipS_(uint32_t depth, uint32_t in, uint32_t w){ // 
  uint32_t bt=0, bitrr, tmp;
  static uint32_t btt[5]={0,0,0,0,0};
  depth=4095-depth;
  tmp=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (bt){
    train[w]=0;
    btt[w]^=1;
  }
  if (train[w]< (depth>>4)){
  train[w]++;
  }
  else {
    train[w]=0;
    btt[w]^=1;
  }
  return btt[w];
}

static inline uint32_t zbinroutebits_noshiftd(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now - no shift of GSR<<
  uint32_t bt=0, bitrr;
  depth=depth>>8;
  if (depth==0) { 
    bitrr = (gate[4].shift_>>SRlength[4]) & 0x01; 
    bt^=bitrr;    
  } else
    {
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t zbinroutfixed_noshift_transit(uint32_t depth, uint32_t in, uint32_t w){ //  no depth //global
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint32_t lastone=0;
  tmp=binroute[count][w]|binary[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  if (lastone!=bt) btt=1; // it was a transition 0-1 1-0
  lastone=bt;
  return btt;
}

static inline uint32_t zbinroutfixed_noshift_transitI(uint32_t depth, uint32_t in, uint32_t w){ //  no depth //global
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint32_t lastone[4]={0,0,0,0};
  tmp=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  if (lastone[w]!=bt) btt=1; // it was a transition 0-1 1-0
  lastone[w]=bt;
  return btt;
}

static inline uint32_t zbinroutfixed_noshift(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - no shift //  no depth//global
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][w]|binary[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t zbinroutfixedI_noshift(uint32_t depth, uint32_t in, uint32_t w){   // no depth//global
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][w]|binary[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
    }
  return bt;
}

static inline uint32_t zbinroutfixedcycle_noshift(uint32_t depth, uint32_t in, uint32_t w){   // no depth //global
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][w]|binary[w];
  tmp=tmp|(1<<w); // adds itself
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t zbinroutfixedcycleI_noshift(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel...//global
  uint32_t bt=0, bitrr, tmp;
  tmp=binroute[count][w]|binary[w];
  tmp=tmp|(1<<w); // add itself in
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscycle(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  depth=depth|(1<<w); // adds itself
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscyclestr(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  if (gate[w].trigger) depth=depth|(1<<w); // adds itself on strobe
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscycle_noshift(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  depth=depth|(1<<w); // adds itself
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscyclestr_noshift(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  if (gate[w].trigger) depth=depth|(1<<w); // adds itself on strobe
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinrouteORbits(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt|=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinrouteANDbits(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 

    for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt&=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinrouteSRbits(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... SR itself, no GSR 
  uint32_t bt=0, bitrr;
  depth=depth>>8;
  if (depth==0) { 
    bitrr = (gate[4].shift_>>SRlength[4]) & 0x01; 
    bt^=bitrr;    
  } else
    {
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t zbinrouteSRbitsS_(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... SR itself, no GSR 
  uint32_t bt=0, bitrr;
  depth=depth>>8;
  if (depth==0 || depth==(1<<w)) { 
    bitrr = (gate[4].Gshift_[w]>>SRlength[4]) & 0x01; 
    bt=bitrr;
  } else
    {
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }

  return bt;
}

static inline uint32_t zbinroutebitsI_noshiftd(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8;
  if (depth==0) { 
    bitrr = (gate[4].shift_>>SRlength[4]) & 0x01; 
    bt^=bitrr;
  } else
    {
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t zbinrouteSRbitsfixed(uint32_t depth, uint32_t in, uint32_t w){   
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w];
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitsI_noshift(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutebitscycleI_noshift(uint32_t depth, uint32_t in, uint32_t w){   // can also be depth version
  uint32_t bt=0, bitrr;
  depth=binroute[count][w]|binary[w]; 
  depth=depth|(1<<w); // add itself in
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t ZzbinroutebitscyclestrI(uint32_t depth, uint32_t in, uint32_t w){   // depth as routesel... cycle added on strobe!
  uint32_t x, bt=0, bitrr, tmp, tmpp, bitn=0;
  depth=binroute[count][w]|binary[w]; 
    if (gate[w].trigger) depth=depth|(1<<w); // adds itself
    tmpp=gate[w].routetype;
    tmp=depth;
    ROUTETYPE_;
    return bitn;
}

// copy GSR to another and keep there (so only on entry or on strobe...// to shared array) - could also be indie versions!
static inline uint32_t zcopyGSR(uint32_t depth, uint32_t in, uint32_t w){
  static uint32_t sharey;
  uint32_t bt=0, x;
  x=depth>>10; // 2 bits 
  if (gate[w].changed==1) { // but changed stays a while....
    sharey=gate[x].Gshare_; // which one to copy?
  }
  bt=(sharey>>SRlength[x]) & 0x01;
  sharey=(sharey<<1)+bt;
  return bt;
}

static inline uint32_t zcopyGSR_s(uint32_t depth, uint32_t in, uint32_t w){ // strobe
  static uint32_t sharey;
  uint32_t bt=0, x;
  x=depth>>10; // 2 bits 
  if (gate[w].trigger) {
    sharey=gate[x].Gshare_;
  }
  bt=(sharey>>SRlength[x]) & 0x01;
  sharey=(sharey<<1)+bt;
  return bt;
}

//////////////////////////////////////////////////////////////////////////
// adding 8/12/2022: -> theroute OR global, depth OR global, also we can have one gapped... with new theroute
// TODO: also indie versions and typed versions - to test

// binroutorg, binroutgap, bitrouteorgap

static inline uint32_t binroutorg(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  depth=depth|binroute[count][w]|binary[w]; 
  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutorg(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bitn=0, x, tmpp, tmp, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  depth=depth|binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  tmp=depth;
  ROUTETYPE_;
  return bitn;
}

static inline uint32_t binroutorgap(uint32_t depth, uint32_t in, uint32_t w){// now uses depth
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 4 bits 
  depth|=binroute[count][w];
    for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t zbinroutorgap(uint32_t depth, uint32_t in, uint32_t w){  // no depth
  uint32_t bitn=0, x, tmp, tmpp, bitrr;
  depth=depth>>8;
  depth=depth|binroute[count][w];
  tmpp=gate[w].routetype;
  tmp=depth;
  ROUTETYPE_;
  return bitn;
}

//////////////////////////////////////////////////////////////////////////
//3 speeds

static inline uint32_t spdfrac(uint32_t depth, uint32_t in, uint32_t w){ // for speed now with dac/interpol pulled out
  uint32_t bt=0;
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfracx(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt=0;
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  gate[w].time_nowx += speed;
  gate[w].last_timex = gate[w].int_timex;
  gate[w].int_timex = gate[w].time_nowx;
  if(gate[w].last_timex<gate[w].int_timex) {
    bt=1; // move on
    gate[w].time_nowx-=1.0f;
    gate[w].int_timex=0;
  }
  return bt;
}

static inline uint32_t spdfracxx(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt=0;
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  gate[w].time_nowxx += speed;
  gate[w].last_timexx = gate[w].int_timexx;
  gate[w].int_timexx = gate[w].time_nowxx;
  if(gate[w].last_timexx<gate[w].int_timexx) {
    bt=1; // move on
    gate[w].time_nowxx-=1.0f;
    gate[w].int_timexx=0;
  }
  return bt;
}

static inline uint32_t spdfracxxx(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt=0;
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  gate[w].time_nowxxx += speed;
  gate[w].last_timexxx = gate[w].int_timexxx;
  gate[w].int_timexxx = gate[w].time_nowxxx;
  if(gate[w].last_timexxx<gate[w].int_timexxx) {
    bt=1; // move on
    gate[w].time_nowxxx-=1.0f;
    gate[w].int_timexxx=0;
  }
  return bt;
}

static inline uint32_t spdfracP_(uint32_t depth, uint32_t in, uint32_t w){ 
  static uint32_t bt[5]={0,0,0,0,0};
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  gate[w].time_nowp += speed;
  gate[w].last_timep = gate[w].int_timep;
  gate[w].int_timep = gate[w].time_nowp;
  if(gate[w].last_timep<gate[w].int_timep) {
    bt[w]^=1;
    gate[w].time_nowp-=1.0f;
    gate[w].int_timep=0;
  }
  return bt[w];
}

static inline uint32_t spdfracend(uint32_t depth, uint32_t in, uint32_t w){  // version with STOP on lowest
  uint32_t bt=0;
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  if (speed>LOWEST || w==2){ // or w==2 means no END for geoC ended... 
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  }
  return bt;
}

//INx
static inline uint32_t spdfrac2(uint32_t depth, uint32_t in, uint32_t w){ // depth%in
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=depth%in;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfrac1(uint32_t depth, uint32_t in, uint32_t w){ // depth%in
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  tmp=in+depth;
  if (tmp>4095) tmp=4095;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfrac1P_(uint32_t depth, uint32_t in, uint32_t w){ // depth%in
  static uint32_t bt[5]={0,0,0,0,0};
  float speed;
  int32_t tmp;
  tmp=in+depth;
  if (tmp>4095) tmp=4095;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_nowp += speed;
  gate[w].last_timep = gate[w].int_timep;
  gate[w].int_timep = gate[w].time_nowp;
  if(gate[w].last_timep<gate[w].int_timep) {
    bt[w]^=1; // move on
    gate[w].time_nowp-=1.0f;
    gate[w].int_timep=0;
  }
  return bt[w];
}

//INx
static inline uint32_t spdfrac3(uint32_t depth, uint32_t in, uint32_t w){ // we add depth and in //INx
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  tmp=(in>>1)+(depth>>1);
  if (tmp>4095) tmp=4095;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfrac3P_(uint32_t depth, uint32_t in, uint32_t w){ // we add depth and in //INx
  static uint32_t bt[5]={0,0,0,0,0};
  float speed;
  int32_t tmp;
  tmp=(in>>1)+(depth>>1);
  if (tmp>4095) tmp=4095;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_nowp += speed;
  gate[w].last_timep = gate[w].int_timep;
  gate[w].int_timep = gate[w].time_nowp;
  if(gate[w].last_timep<gate[w].int_timep) {
    bt[w]^=1; // move on
    gate[w].time_nowp-=1.0f;
    gate[w].int_timep=0;
  }
  return bt[w];
}

//INx
static inline uint32_t spdfrac5(uint32_t depth, uint32_t in, uint32_t w){ // we add depth and in //INx modulus
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  tmp=in+depth;
  tmp=tmp&4095;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfrac5P_(uint32_t depth, uint32_t in, uint32_t w){ // we add depth and in //INx modulus
  static uint32_t bt[5]={0,0,0,0,0};
  float speed;
  int32_t tmp;
  tmp=in+depth;
  tmp=tmp&4095;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_nowp += speed;
  gate[w].last_timep = gate[w].int_timep;
  gate[w].int_timep = gate[w].time_nowp;
  if(gate[w].last_timep<gate[w].int_timep) {
    bt[w]^=1; // move on
    gate[w].time_nowp-=1.0f;
    gate[w].int_timep=0;
  }
  return bt[w];
}

//INx
static inline uint32_t spdfrac4(uint32_t depth, uint32_t in, uint32_t w){ // add both halfway
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  tmp=(depth>>2)-512;
  tmp+=(in>>2);  
  if (tmp<0) tmp=0;
  else if (tmp>1023) tmp=1023;
  speed=logspeed18[tmp]; 
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfrac4P_(uint32_t depth, uint32_t in, uint32_t w){ // add both halfway
  static uint32_t bt[5]={0,0,0,0,0};
  float speed;
  int32_t tmp;
  tmp=(depth>>2)-512;
  tmp+=(in>>2);  
  if (tmp<0) tmp=0;
  else if (tmp>1023) tmp=1023;
  speed=logspeed18[tmp]; 
  gate[w].time_nowp += speed;
  gate[w].last_timep = gate[w].int_timep;
  gate[w].int_timep = gate[w].time_nowp;
  if(gate[w].last_timep<gate[w].int_timep) {
    bt[w]^=1; // move on
    gate[w].time_nowp-=1.0f;
    gate[w].int_timep=0;
  }
  return bt[w];
}

//INx
static inline uint32_t spdfracdac3(uint32_t depth, uint32_t in, uint32_t w){ // depth is offset, in is constraint -- and speed from dacfrom
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=gate[dacfrom[daccount][w]].dac%in; //changed
  tmp+=depth;
  if (tmp>4095) tmp=4095;    
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfracdac3P_(uint32_t depth, uint32_t in, uint32_t w){ // depth is offset, in is constraint -- and speed from dacfrom
  static uint32_t bt[5]={0,0,0,0,0};
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=gate[dacfromopp[count][w]].dac%(in); //changed
  tmp+=depth;
  if (tmp>4095) tmp=4095;    
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_nowp += speed;
  gate[w].last_timep = gate[w].int_timep;
  gate[w].int_timep = gate[w].time_nowp;
  if(gate[w].last_timep<gate[w].int_timep) {
    bt[w]^=1; // move on
    gate[w].time_nowp-=1.0f;
    gate[w].int_timep=0;
  }
  return bt[w];
}

static inline uint32_t spdfracdac3x(uint32_t depth, uint32_t in, uint32_t w){ // depth is offset, in is constraint -- and speed from speedfrom
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=gate[speedfrom[spdcount][w]].dac%(in); //changed
  tmp+=depth;
  if (tmp>4095) tmp=4095;    

  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfracdac31(uint32_t depth, uint32_t in, uint32_t w){ // depth is offset, in is constraint -- and speed from speedfrom
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=gate[0].dac%(in); //changedx
  tmp+=depth;
  if (tmp>4095) tmp=4095;    
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfracdac33(uint32_t depth, uint32_t in, uint32_t w){ // depth is offset, in is constraint -- and speed from speedfrom
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=gate[2].dac%(in); //changedx
  tmp+=depth;
  if (tmp>4095) tmp=4095;    
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfracdac34(uint32_t depth, uint32_t in, uint32_t w){ // depth is offset, in is constraint -- and speed from speedfrom
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=gate[3].dac%(in); //changedx
  tmp+=depth;
  if (tmp>4095) tmp=4095;    
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfracdac4(uint32_t depth, uint32_t in, uint32_t w){ // depth is offset, in is constraint -- and speed from dacfrom
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=(gate[dacfrom[daccount][w]].dac%in)-(in>>1); // in/2 int32_t tmp
  tmp+=depth;
  if (tmp>4095) tmp=4095;    
  if (tmp<0) tmp=0;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t spdfracdac4x(uint32_t depth, uint32_t in, uint32_t w){ // depth is offset, in is constraint -- and speed from speedfrom
  uint32_t bt=0;
  float speed;
  int32_t tmp;
  if (in==0) in=1;
  tmp=(gate[speedfrom[spdcount][w]].dac%in)-(in>>1); // in/2 int32_t tmp
  tmp+=depth;
  if (tmp>4095) tmp=4095;    
  if (tmp<0) tmp=0;
  speed=logspeed18[tmp>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

/////////////
// strobe speeds

static inline uint32_t strobe(uint32_t depth, uint32_t in, uint32_t w){   // strobe - no depth
  uint32_t bt;
  bt=gate[w].trigger;
  return bt;
}

static inline uint32_t strobespdfrac(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt=0;
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  gate[w].time_now += speed;
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;
  if(gate[w].last_time<gate[w].int_time || gate[w].trigger) {
    bt=1; // move on
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;
  }
  return bt;
}

static inline uint32_t strobespdfracP_(uint32_t depth, uint32_t in, uint32_t w){ 
  static uint32_t bt[5]={0,0,0,0,0};
  float speed;
  speed=logspeed18[depth>>2]; // 12 bits to 10 bits
  gate[w].time_nowp += speed;
  gate[w].last_timep = gate[w].int_timep;
  gate[w].int_timep = gate[w].time_nowp;
  if(gate[w].last_timep<gate[w].int_timep || gate[w].trigger) {
    bt[w]^=1; // move on
    gate[w].time_nowp-=1.0f;
    gate[w].int_timep=0;
  }
  return bt[w];
}

static inline uint32_t zstrobeBURST(uint32_t depth, uint32_t in, uint32_t w){ // 
  uint32_t bt=0;
  depth=4097-depth;
  if (gate[w].trigger){
    train[w]=1;
  }
  if (train[w]!=0 && train[w]< (depth)){
  train[w]++;
  bt=1;
  }
  else {
    train[w]=0;
  }
  return bt;
}

static inline uint32_t zstrobeBURSTinv(uint32_t depth, uint32_t in, uint32_t w){ // 
  uint32_t bt=0;
    depth=4097-depth;
  if (gate[w].trigger){
    train[w]=1;
  }
  if (train[w]!=0 && train[w]< (depth)){
  train[w]++;
  }
  else {
    train[w]=0;
    bt=1;
  }
  return bt;
}

static inline uint32_t zstrobeBURST1(uint32_t depth, uint32_t in, uint32_t w){ // non indie burst
  uint32_t bt=0;
  static uint32_t tren;
    depth=4097-depth;
  if (gate[w].trigger){
    tren=1;
  }
  if (tren!=0 && tren< (depth)){
  tren++;
  bt=1;
  }
  else {
    tren=0;
  }
  return bt;
}

static inline uint32_t zstrobeBURST2(uint32_t depth, uint32_t in, uint32_t w){ // hold depth
  uint32_t bt=0;
  static uint32_t dd[4];
    depth=4097-depth;
  if (gate[w].trigger){
    train[w]=1;
    dd[w]=depth;
  }
  if (train[w]!=0 && train[w]< (dd[w])){
  train[w]++;
  bt=1;
  }
  else {
    train[w]=0;
  }
  return bt;
}

static inline uint32_t zstrobeBURST3flip(uint32_t depth, uint32_t in, uint32_t w){ // var - faster ones
  static uint32_t bt[5]={0,0,0,0,0};
  depth=4095-depth;
  depth=depth>>4;
  if (gate[w].trigger){
    train[w]=0;
    bt[w]^=1;
  }
  if (train[w]<(depth)){
  train[w]++;
  }
  else {
    train[w]=0;
  bt[w]^=1;
  }
  return bt[w];
}

static inline uint32_t ztogglebits(uint32_t depth, uint32_t in, uint32_t w){   // toggle
  static uint32_t bt[4]={0,0,0,0};
  if (gate[w].trigger && ((depth>>4)<(LFSR__[w]>>4)) ) bt[w]=bt[w]^1;
  return bt[w];
}

static inline uint32_t ztogglebitsnod(uint32_t depth, uint32_t in, uint32_t w){   // toggle
  static uint32_t bt[4]={0,0,0,0};
  if (gate[w].trigger) bt[w]=bt[w]^1;
  return bt[w];
}

static inline uint32_t ztogglebitssh(uint32_t depth, uint32_t in, uint32_t w){   // toggle // shared toggles
  static uint32_t bt=0;//,0,0,0};
  if (gate[w].trigger && ((depth>>4)<(LFSR__[w]>>4))) bt=bt^1;
  return bt;
}

static inline uint32_t ztogglebitsshnod(uint32_t depth, uint32_t in, uint32_t w){   // toggle
  static uint32_t bt=0;//,0,0,0};
  if (gate[w].trigger) bt=bt^1;
  return bt;
}

static inline uint32_t stroberoute(uint32_t depth, uint32_t in, uint32_t w){   // strobe - no depth - bump on local route for speed
  uint32_t bitn=0, x, bt, tmp, bitrr;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  BINROUTESRstrip_;
  bt=bitrr;
  return bt;
}

static inline uint32_t strzbinroutfixed_noshift_transit(uint32_t depth, uint32_t in, uint32_t w){ //  no depth. strobe
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint32_t lastone=0;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (lastone!=bt) btt=1; // it was a transition 0-1 1-0
  lastone=bt;
  return btt;
}

static inline uint32_t strzbinroutfixed_shift_transit(uint32_t depth, uint32_t in, uint32_t w){ //  no depth. strobe
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint32_t lastone=0;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (lastone!=bt) btt=1; // it was a transition 0-1 1-0
  lastone=bt;
  return btt;
}


static inline uint32_t strzbinroutfixed_noshift_transitI(uint32_t depth, uint32_t in, uint32_t w){ //  no depth. strobe
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint32_t lastone[4]={0,0,0,0};
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (lastone[w]!=bt) btt=1; // it was a transition 0-1 1-0
  lastone[w]=bt;
  return btt;
}

static inline uint32_t strzbinroutfixed_shift_transitI(uint32_t depth, uint32_t in, uint32_t w){ //  no depth. strobe
  uint32_t btt=0,bt=0, bitrr, tmp;
  static uint32_t lastone[4]={0,0,0,0};
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }

  if (lastone[w]!=bt) btt=1; // it was a transition 0-1 1-0
  lastone[w]=bt;
  return btt;
}

static inline uint32_t strzbinroutfixed_noshift(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - no shift //  no depth strobe
  uint32_t bt=0, bitrr, tmp;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t strzbinroutfixed_shift(uint32_t depth, uint32_t in, uint32_t w){   // fixed binroute from count - no shift //  no depth strobe
  uint32_t bt=0, bitrr, tmp;
  static uint32_t localroute[4]={1,1,1,1};
  if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  return bt;
}

static inline uint32_t strzbinroutfixedI_noshift(uint32_t depth, uint32_t in, uint32_t w){   // no depth strobe
  uint32_t bt=0, bitrr, tmp;
  static uint32_t localroute[4]={1,1,1,1};
    if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  tmp=tmp>>1;
    }
  return bt;
}

static inline uint32_t strzbinroutfixedI_shift(uint32_t depth, uint32_t in, uint32_t w){   // no depth strobe
  uint32_t bt=0, bitrr, tmp;
  static uint32_t localroute[4]={1,1,1,1};
    if (gate[w].trigger) localroute[w]++;
  if (localroute[w]>15) localroute[w]=1;
  tmp=localroute[w];
  for (uint32_t x=0;x<4;x++){
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
    }
  return bt;
}

//////////////////////////////////////////////////////////////////////////
//4
//generic bits

// zero/nada
static inline uint32_t zeros(uint32_t depth, uint32_t in, uint32_t w){  // returns only zeroes
  return 0;
}

static inline uint32_t pzeros(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){  // returns only zeroes
  return 0;
}


// one - can also be for speeds or otherwise
static inline uint32_t ones(uint32_t depth, uint32_t in, uint32_t w){ 
  return 1;
}

// top bit of clksr 
static inline uint32_t clksr(uint32_t depth, uint32_t in, uint32_t w){  // but these still need set strobe bit but..
  uint32_t bt=0;
  depth=depth>>7; //  5 bits
  bt=(clksr_[w]>>depth)&0x01;
  return bt;
}

// how could we cycle through clksr if it is not moving - we need gsr for them -clksrG_
static inline uint32_t clksrG(uint32_t depth, uint32_t in, uint32_t w){ // depthi
  uint32_t bt=0;
  depth=depth>>7; //  5 bits
  bt=(clksrG_[w]>>depth)&0x01;
  clksrG_[w]=(clksrG_[w]<<1)+bt; // this also changes patterns there
  return bt;
}

// try 8 bit cipher mode
//ADC/depth in comparator -> bits, clked/speed into GGSR which shifts along, on strobe GGSR copied to SR
static inline uint32_t cipher(uint32_t depth, uint32_t in, uint32_t w){// uses depth
  uint32_t bt, k; uint32_t newd;
  static uint32_t gs[4]={0,0,0,0};
  newd=1024+(depth>>2);//2048;//+(512-(depth>>2)); // fixed 20/2/2023
    
  if (newd<in) bt=1; 
  else bt=0;
  
  // onto SR
  GGGshift_[w]=GGGshift_[w]<<1;
  GGGshift_[w]+=bt;
  // on strobe copy to gs
  if (gate[w].trigger) gs[w]=GGGshift_[w];
  bt=(gs[w]>>8)&0x01; // how long?
  
  return bt;
}

static inline uint32_t cipherforspeed(uint32_t depth, uint32_t in, uint32_t w){// uses depth
  uint32_t bt, k;
  //  uint32_t kw[4]={0,0,0,0};
  static uint32_t gs[4]={0,0,0,0};
  
  if ((depth>>4)<(LFSR__[w]>>4)) bt=1; 
  else bt=0;
  
  // onto SR
  GGGshift_[w]=GGGshift_[w]<<1;
  GGGshift_[w]+=bt;
  // on strobe copy to gs
  if (gate[w].trigger) gs[w]=GGGshift_[w];
  bt=(gs[w]>>8)&0x01; // how long?
  return bt;
}

static inline uint32_t pcipher(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){
  uint32_t bt, k;
  //  uint32_t kw[4]={0,0,0,0};
  static uint32_t gs[4]={0,0,0,0};
    if ((depth>>4)<(in>>4)) bt=1; 
  else bt=0;
  
  // onto SR
  if (adv){
  GGGshift_[w]=GGGshift_[w]<<1;
  GGGshift_[w]+=bt;
  }
  // on strobe copy to gs
  if (gate[w].trigger || reset) gs[w]=GGGshift_[w];
  bt=(gs[w]>>8)&0x01; // how long?
  return bt;
}

static inline uint32_t osceq(uint32_t depth, uint32_t in, uint32_t w){  // so all share
  uint32_t bt;
  static int32_t n=0,nn=0;
  depth=4095-depth;
     if (n>depth) {
       bt=0;
       if (nn>=in) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
       bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t osceqx(uint32_t depth, uint32_t in, uint32_t w){  // so all share
  uint32_t bt;
  static int32_t n=0,nn=0;
  depth=4095-depth;
     if (n>in) {
       bt=0;
       if (nn>=depth) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
       bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t osceqS_(uint32_t depth, uint32_t in, uint32_t w){  // so all share
  uint32_t bt;
  static int32_t n=0,nn=0;
  depth=4095-depth;
     if (n>depth) {
       bt=0;
       if (nn>=in) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
          bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t osceqf(uint32_t depth, uint32_t in, uint32_t w){  // so all share
  uint32_t bt;
  static int32_t n=0,nn=0;
  depth=4095-depth;
  depth=depth>>4;
  in=in>>4;
     if (n>depth) {
       bt=0;
       if (nn>=in) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
       bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t osceqxf(uint32_t depth, uint32_t in, uint32_t w){  // so all share
  uint32_t bt;
  static int32_t n=0,nn=0;
  depth=4095-depth;
  depth=depth>>4;
  in=in>>4;
     if (n>in) {
       bt=0;
       if (nn>=depth) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
       bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t osceqfA(uint32_t depth, uint32_t in, uint32_t w){  // so all share
  uint32_t bt;
  static int32_t n=0,nn=0;
  ADCgen;
  depth=4095-depth;
  depth=depth>>4;
  in=in>>4;
     if (n>depth) {
       bt=0;
       if (nn>=in) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
       bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t osceqxfA(uint32_t depth, uint32_t in, uint32_t w){  // so all share
  uint32_t bt;
  static int32_t n=0,nn=0;
  ADCgen;
  depth=4095-depth;
  depth=depth>>4;
  in=in>>4;
     if (n>in) {
       bt=0;
       if (nn>=depth) { // so equal bits from 0 / length 0 = 101010
	 n=0;
       }
       nn++;
     } // n     
     else {
       bt=1;
       n++;
       nn=0;
     }         
     return bt;
}

static inline uint32_t flipflop(uint32_t depth, uint32_t in, uint32_t w){  // so all share // 
  uint32_t bt;
  static uint32_t fl=0;
  //if ((depth>>4)>(in>>4)) fl^=1;
  fl^=1;
  bt=fl;
  return bt;
}

static inline uint32_t flipflopandroute(uint32_t depth, uint32_t in, uint32_t w){  // so all share // DEPTH
  uint32_t bt, bitrr;
  static uint32_t fl=0;
  fl^=1;
  bt=fl;
  depth=binroute[count][w]|binary[w]; 

  for (uint32_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}



// generic in from gen.h

//four SRbits
static inline uint32_t zSRNbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits as max 32
  bt = (gate[0].Gshift_[w]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

static inline uint32_t zSRNbitsS_(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits as max 32
  bt = (gate[0].Gshift_[w]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				

  return bt;
}

static inline uint32_t zSRLbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[1].Gshift_[w]>>depth) & 0x01;
  return bt;
}

static inline uint32_t zSRCbits(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[2].Gshift_[w]>>depth) & 0x01;
  return bt;
}

static inline uint32_t zSRRbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[3].Gshift_[w]>>depth) & 0x01;
  return bt;
}

static inline uint32_t zprobbits(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode
  uint32_t bt=0;
  if ((depth>>4)<(LFSR__[w]>>4)) bt=1;
  //bt=1;
  return bt;
}

static inline uint32_t zprobbitsA(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode
  uint32_t bt=0;
  ADCgen;
  if ((depth>>4)<(LFSR__[w]>>4)) bt=1;
  return bt;
}

static inline uint32_t zprobbitsS_(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode
  uint32_t bt=0;
  if ((depth>>4)>(LFSR__[w]>>4)) {
    bt=1;
  }
  return bt;
}

static inline uint32_t zownprobbits(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode
  uint32_t bt=0;
  if ((depth>>4)>(gate[w].shift_&255)) bt=1; // changed direction
  return bt;
}

static inline uint32_t zownGprobbits(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode
  uint32_t bt=0;
  if ((depth>>4)>(gate[w].Gshift_[w]&255)) bt=1; // changed direction
  return bt;
}

static inline uint32_t zinvprobbits(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode - other way round
  uint32_t bt=0;
  if ((depth>>4)>(LFSR__[w]>>4)) bt=1;
  return bt;
}

static inline uint32_t zsprobbits(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode - other way round depends on strobe
  uint32_t bt=0;
    if (gate[w].trigger) {
    if ((depth>>4)>(LFSR__[w]>>4)) bt=1;
    }
  else 
    if ((depth>>4)<(LFSR__[w]>>4)) bt=1;
  return bt;
}

static inline uint32_t zprobbitsxorstrobe(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode xor strobe - can be more ops
  uint32_t bt=0;
      if ((depth>>4)<(LFSR__[w]>>4)) bt=1;
    bt=bt^gate[w].trigger;
  return bt;
}

static inline uint32_t zprobbitsxorstrobeA(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode xor strobe - can be more ops
  uint32_t bt=0;
  ADCgen;
      if ((depth>>4)<(LFSR__[w]>>4)) bt=1;
    bt=bt^gate[w].trigger;
  return bt;
}

static inline uint32_t zprobbitsxortoggle(uint32_t depth, uint32_t in, uint32_t w){   // PROBability mode xor strobe - can be more ops
  static uint32_t bt[5]={0,0,0,0,0};
    if (gate[w].trigger) bt[w]^=1;
  if ((depth>>4)<(LFSR__[w]>>4)) bt[w]^=1;
  return bt[w];
}

// succ. no depth: zsuccbits, zsuccbitsI, zsuccbits_noshiftnod, zsuccbitsI_noshiftnod
// succ. depth: 

// zsuccbitspp, zsuccbitsprob, zsuccbits_noshift, zsuccbitsI_noshift, zsuccbitsIpp, zsuccbitsppd, zsuccbitsprobd, zsuccbits_noshiftd, zsuccbitsI_noshiftd, zsuccbitsIppd

static inline uint32_t zsuccbitspp(uint32_t depth, uint32_t in, uint32_t w){   // depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bt;
  if ((depth>>4)>(in>>4)) x++;
  return bt;
}

static inline uint32_t zsuccbitsppd(uint32_t depth, uint32_t in, uint32_t w){   // depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bt;
  if ((depth>>4)>(LFSR__[w]>>4)) x++;
  return bt;
}

static inline uint32_t zsuccbitsppS_(uint32_t depth, uint32_t in, uint32_t w){   // depth - we route from each sr in turn // for speed
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bt;
  if ((depth>>4)>(in>>4)) x++;

  return bt;
}

static inline uint32_t zsuccbitsprob(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
  if ((depth>>4)>(in>>4)) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bt;
  x++;
  return bt;
}

static inline uint32_t zsuccbitsprobd(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
  if ((depth>>4)>(LFSR__[w]>>4)) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bt;
  x++;
  return bt;
}

static inline uint32_t zsuccbitsprobS_(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
  if ((depth>>4)>(in>>4)) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bt;
  x++;
  return bt;
}

// version without shift for speeds - but we need depth
static inline uint32_t zsuccbits_noshift(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].shift_>>SRlength[x]) & 0x01;
  if ((depth>>4)<(in>>4)) x++;
  return bt;
}

static inline uint32_t zsuccbits_noshiftd(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].shift_>>SRlength[x]) & 0x01;
  if ((depth>>4)>(LFSR__[w]>>4)) x++;
  return bt;
}

static inline uint32_t zsuccbits_noshiftS_(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].shift_>>SRlength[x]) & 0x01;
  if ((depth>>4)<(in>>4)) x++;

  return bt;
}

static inline uint32_t zsuccbits_noshiftdS_(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].shift_>>SRlength[x]) & 0x01;
  if ((depth>>4)<(LFSR__[w]>>4)) x++;

  return bt;
}

static inline uint32_t zsuccbitsI_noshift(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].shift_>>SRlength[x[w]]) & 0x01;
  if ((depth>>4)>(in>>4)) x[w]++;
  return bt;
}

static inline uint32_t zsuccbitsI_noshiftS_(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].shift_>>SRlength[x[w]]) & 0x01;
  if ((depth>>4)>(in>>4)) x[w]++;

  return bt;
}

static inline uint32_t zsuccbitsI_noshiftd(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].shift_>>SRlength[x[w]]) & 0x01;
  if ((depth>>4)>(LFSR__[w]>>4)) x[w]++;
  return bt;
}

static inline uint32_t zsuccbitsI_noshiftdS_(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0; // needed
  bt = (gate[x[w]].shift_>>SRlength[x[w]]) & 0x01;
  if ((depth>>4)>(LFSR__[w]>>4)) x[w]++;

  return bt;
}

static inline uint32_t zsuccbitsIpp(uint32_t depth, uint32_t in, uint32_t w){   // depth 
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].Gshift_[w]>>SRlength[x[w]]) & 0x01;
  if ((depth>>4)>(in>>4)) x[w]++;
  return bt;
}

static inline uint32_t zsuccbitsIppd(uint32_t depth, uint32_t in, uint32_t w){   // depth 
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].Gshift_[w]>>SRlength[x[w]]) & 0x01;
  if ((depth>>4)>(LFSR__[w]>>4)) x[w]++;
  return bt;
}

static inline uint32_t zsuccbitsIppdA(uint32_t depth, uint32_t in, uint32_t w){   // depth 
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  ADCgen;
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].Gshift_[w]>>SRlength[x[w]]) & 0x01;
  if ((depth>>4)>(LFSR__[w]>>4)) x[w]++;
  return bt;
}

static inline uint32_t zsuccbitsIppS_(uint32_t depth, uint32_t in, uint32_t w){   // depth 
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].Gshift_[w]>>SRlength[x[w]]) & 0x01;
  if ((depth>>4)>(in>>4)) x[w]++;
  return bt;
}

///////////////// no types, no depth

static inline uint32_t zsuccbits(uint32_t depth, uint32_t in, uint32_t w){   // no use of depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0; // shared
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bt;
  x++;
  return bt;
}

static inline uint32_t zsuccbits_noshiftnod(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].shift_>>SRlength[x]) & 0x01;
  x++;
  return bt;
}

static inline uint32_t zsuccbitsI_noshiftnod(uint32_t depth, uint32_t in, uint32_t w){   // we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].shift_>>SRlength[x[w]]) & 0x01;
  x[w]++;
  return bt;
}

static inline uint32_t zsuccbitsI(uint32_t depth, uint32_t in, uint32_t w){   // no use of depth - we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].Gshift_[w]>>SRlength[x[w]]) & 0x01;
  x[w]++;
  return bt;
}

static inline uint32_t strobezsuccbits_noshift(uint32_t depth, uint32_t in, uint32_t w){   // no use of depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].shift_>>SRlength[x]) & 0x01;
  if (gate[w].trigger) x++;
  return bt;
}

static inline uint32_t strobezsuccbits_shift(uint32_t depth, uint32_t in, uint32_t w){   // no use of depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x=0;
  if (x==w) x++;
  if (x>3) x=0;
  bt = (gate[x].Gshare_>>SRlength[x]) & 0x01;
  gate[x].Gshare_=(gate[x].Gshare_<<1)+bt;

  if (gate[w].trigger) x++;
  return bt;
}

static inline uint32_t strobezsuccbitsI_noshift(uint32_t depth, uint32_t in, uint32_t w){   // no use of depth - we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].shift_>>SRlength[x[w]]) & 0x01;
  if (gate[w].trigger) x[w]++;
  return bt;
}

static inline uint32_t strobezsuccbitsI_shift(uint32_t depth, uint32_t in, uint32_t w){   // no use of depth - we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint32_t x[4]={0};
  if (x[w]==w) x[w]++;
  if (x[w]>3) x[w]=0;
  bt = (gate[x[w]].Gshare_>>SRlength[x[w]]) & 0x01;
  gate[x[w]].Gshare_=(gate[x[w]].Gshare_<<1)+bt;
  
  if (gate[w].trigger) x[w]++;
  return bt;
}

//////////////////

// depth can be length or param
static inline uint32_t zreturnbits(uint32_t depth, uint32_t in, uint32_t w){   // returning but we need ref to itself SR//, and its length/ as depth - starts to look like adc_ functions now
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[w].Gshift_[w]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

//inverted
static inline uint32_t zreturnnotbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = !((gate[w].Gshift_[w]>>depth) & 0x01);		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

static inline uint32_t zosc1bits(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt=0,n=0;
  depth=4095-depth;
  if (n>depth)  {
    lastbt^=1;
    n=0;
  }
  n++;
  bt=lastbt;
  return bt;
}

static inline uint32_t zosc1bitsS_(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt=0,n=0;
  depth=4095-depth;
  if (n>depth)  {
    lastbt^=1;
    n=0;
  }
  n++;
  bt=lastbt;
  return bt;
}

static inline uint32_t zosc1bitsfast(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt=0,n=0;
  depth=4095-depth;
  depth=depth>>4;
  if (n>depth)  {
    lastbt^=1;
    n=0;
  }
  n++;
  bt=lastbt;
  return bt;
}

static inline uint32_t zosc1bitsfastA(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt=0,n=0;
  ADCgen;
  depth=4095-depth;
  depth=depth>>4;
  if (n>depth)  {
    lastbt^=1;
    n=0;
  }
  n++;
  bt=lastbt;
  return bt;
}

static inline uint32_t zosc1bitsslow(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt=0,n=0;
  depth=4095-depth;
  depth=depth<<4;
  if (n>depth)  {
    lastbt^=1;
    n=0;
  }
  n++;
  bt=lastbt;
  return bt;
}

// new one - count up to depth
static inline uint32_t zcountbits(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t flop=0, n=0, nn=0;
  depth=4095-depth;
  if (n>depth)  {
    n=0;
  }
  // we want n number of flops output
  if (nn>n){
    nn=0;
    flop^=1;
    n++;
  }
  bt=flop;
  nn++; 
  return bt;
}

static inline uint32_t zcountbitsI(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t flop[4]={0,0,0,0}, n[4]={0,0,0,0}, nn[4]={0,0,0,0};
  depth=4095-depth;
  if (n[w]>depth)  {
    n[w]=0;
  }
  // we want n number of flops output
  if (nn[w]>n[w]){
    nn[w]=0;
    flop[w]^=1;
    n[w]++;
  }
  bt=flop[w];
  nn[w]++; 
  return bt;
}

static inline uint32_t zcountbitsA(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t flop=0, n=0, nn=0;
  ADCgen;
  depth=4095-depth;
  if (n>depth)  {
    n=0;
  }
  // we want n number of flops output
  if (nn>n){
    nn=0;
    flop^=1;
    n++;
  }
  bt=flop;
  nn++; 
  return bt;
}

static inline uint32_t zcountbitsIA(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t flop[4]={0,0,0,0}, n[4]={0,0,0,0}, nn[4]={0,0,0,0};
  ADCgen;
  depth=4095-depth;
  if (n[w]>depth)  {
    n[w]=0;
  }
  // we want n number of flops output
  if (nn[w]>n[w]){
    nn[w]=0;
    flop[w]^=1;
    n[w]++;
  }
  bt=flop[w];
  nn[w]++; 
  return bt;
}

static inline uint32_t zcountbitsS_(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t flop=0, n=0, nn=0;
  depth=4095-depth;
  if (n>depth)  {
    n=0;
  }
  // we want n number of flops output
  if (nn>n){
    nn=0;
    flop^=1;
    n++;
  }
  bt=flop;
  nn++; 
  return bt;
}

static inline uint32_t zcountbitsIS_(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t flop[4]={0,0,0,0}, n[4]={0,0,0,0}, nn[4]={0,0,0,0};
  depth=4095-depth;
  if (n[w]>depth)  {
    n[w]=0;
  }
  // we want n number of flops output
  if (nn[w]>n[w]){
    nn[w]=0;
    flop[w]^=1;
    n[w]++;
  }
  bt=flop[w];
  nn[w]++; 
  return bt;
}

static inline uint32_t zTMsimplebits(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(in>>4)) bt=!bt;
  return bt;
}

static inline uint32_t zTMsimplebitsLA(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  ADCgen;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(LFSR__[w]>>4)) bt=!bt;
  return bt;
}

static inline uint32_t zTMsimplebitsL(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(LFSR__[w]>>4)) bt=!bt;
  return bt;
}

static inline uint32_t zTMsimplebitsSTR(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(in>>4)) bt=!bt;
  bt^=gate[w].trigger;
  return bt;
}

static inline uint32_t zTMsimplebitsLSTR(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(LFSR__[w]>>4)) bt=!bt;
  bt^=gate[w].trigger;
  return bt;
}

static inline uint32_t zTMsimplebitsTOG(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static uint8_t tug[4]={0};
  tug[w]^=gate[w].trigger;  
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(in>>4)) bt=!bt;
  bt^=tug[w];
  return bt;
}

static inline uint32_t zTMsimplebitsLTOG(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static uint8_t tug[4]={0};
  tug[w]^=gate[w].trigger;  
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(LFSR__[w]>>4)) bt=!bt;
  bt^=tug[w];
  return bt;
}

static inline uint32_t zTMsimplebitsS_(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(in>>4)) bt=!bt;
  return bt;
}

static inline uint32_t zTMsimplebitsLS_(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  if ((depth>>4)>(LFSR__[w]>>4)) bt=!bt;

  return bt;
}

static inline uint32_t zonebits(uint32_t depth, uint32_t in, uint32_t w){ // depth=0 resets --> ??? use strobe STROBE and depth
  uint32_t bt;
  static int32_t bc=31;
    if (gate[w].trigger) {
    depth=depth>>2;
    bc=depth;
  }
  if (bc<0) {
    bt=0;
    //    bc=depth;
  }
  else{
  bt = 1; // this means that MSB comes out first
  }
  bc--;
  return bt;
}

//EN: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)
static inline uint32_t zENbits(uint32_t prob, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 
  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  //    prob=7-prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
  prob=prob>>4; //8 bits
  prob=255-prob;
      if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | prob)==255) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
    else   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  //  bt=(LFSR_[w]>>24)&0x01;
  //  bt=1;
  return bt;
}

//EN: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)
static inline uint32_t zENbitsI(uint32_t prob, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 

  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  //  prob=7-prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
  prob=prob>>4;
  prob=255-prob;
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | prob)==255) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = !(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  return bt;
}

//EN: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)
static inline uint32_t zENbitsS_(uint32_t prob, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 
  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  //    prob=7-prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
  prob=prob>>4; //8 bits
  prob=255-prob;
      if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | prob)==255) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
    else   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
      //  bt=(LFSR_[w]>>24)&0x01;
  //  bt=1;
  return bt;
}

//EN: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)
static inline uint32_t zENbitsIS_(uint32_t prob, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 

  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  //  prob=7-prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
  prob=prob>>4;
  prob=255-prob;
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | prob)==255) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = !(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
    return bt;
}

static inline uint32_t zENsbits(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  if ((LFSR__[w]>>4)>(depth>>4)) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t zENsbitsS_(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  if ((LFSR__[w]>>4)>(depth>>4)) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit

  return bt;
}

static inline uint32_t zENsroutedbits(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  if ((gate[inroute[count][w]].Gshift_[w]&255)<(depth>>4)) bt=(gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]])&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t zlfsrbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt;
  static uint32_t k;
  depth=depth>>7; // 5 bits
  bt = ((ADCshift_[w] >> (lfsr_taps[depth][0])) ^ (ADCshift_[w] >> (lfsr_taps[depth][1])) ^ (ADCshift_[w] >> (lfsr_taps[depth][2])) ^ (ADCshift_[w] >> (lfsr_taps[depth][3]))) & 1u;
  ADCshift_[w]=(ADCshift_[w]<<1)+bt;
  if (ADCshift_[w]==0) ADCshift_[w]=0xff;
  return bt;
}

static inline uint32_t zllfsrbits(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  // out from lfsr at full speed
  bt=(LFSR_[w]>>31)&0x01;
  if ((depth>>4)<(LFSR__[w]>>4)) bt=((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
  return bt;
}

static inline uint32_t zlfsrbitsA(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt;
  static uint32_t k;
  ADCgen;
  depth=depth>>7; // 5 bits
  bt = ((ADCshift_[w] >> (lfsr_taps[depth][0])) ^ (ADCshift_[w] >> (lfsr_taps[depth][1])) ^ (ADCshift_[w] >> (lfsr_taps[depth][2])) ^ (ADCshift_[w] >> (lfsr_taps[depth][3]))) & 1u;
  ADCshift_[w]=(ADCshift_[w]<<1)+bt;
  if (ADCshift_[w]==0) ADCshift_[w]=0xff;
  return bt;
}

static inline uint32_t zllfsrbitsA(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  // out from lfsr at full speed
  ADCgen;
  bt=(LFSR_[w]>>31)&0x01;
  if ((depth>>4)<(LFSR__[w]>>4)) bt=((gate[w].Gshift_[w]>>SRlength[w]) & 0x01); 
  return bt;
}

static inline uint32_t zflipbits(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt,n;
  depth=depth>>4; // 8 bits say
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; // returnbits				
  if (n>depth)  {
    bt=!bt;
    n=0;
  }
  n++;
  return bt;
}

static inline uint32_t zflipbitsA(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt,n;
  ADCgen;
  depth=depth>>4; // 8 bits say
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; // returnbits				
  if (n>depth)  {
    bt=!bt;
    n=0;
  }
  n++;
  return bt;
}

static inline uint32_t zosceqbitsI(uint32_t depth, uint32_t in, uint32_t w){   
  uint32_t bt;
  static int32_t n[4]={0};
  static int32_t nn[4]={0};
  depth=4095-depth;
  in=4095-in;
     if (n[w]>depth) {
       bt=0;
       if (nn[w]>=in) { // so equal bits from 0 / length 0 = 101010
	 n[w]=0;
       }
       nn[w]++;
     } // n     
     else {
       bt=1;
       n[w]++;
       nn[w]=0;
     }         
     return bt;
}

static inline uint32_t zosceqbitsIx(uint32_t depth, uint32_t in, uint32_t w){   // swopped dpeth and in
  uint32_t bt;
  static int32_t n[4]={0};
  static int32_t nn[4]={0};
  depth=4095-depth;
  in=4095-in;
  if (n[w]>in) {
       bt=0;
       if (nn[w]>=depth) { // so equal bits from 0 / length 0 = 101010
	 n[w]=0;
       }
       nn[w]++;
     } // n     
     else {
       bt=1;
       n[w]++;
       nn[w]=0;
     }         
     return bt;
}
     
static inline uint32_t zosc1bitsI(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt[4]={0};
  static uint32_t n[4]={0};
  depth=4095-depth;
  if (n[w]>depth)  {
    lastbt[w]^=1;
    n[w]=0;
  }
  n[w]++;
  bt=lastbt[w];
  return bt;
}

static inline uint32_t zosc1bitsIS_(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt[4]={0};
  static uint32_t n[4]={0};
  depth=4095-depth;
  if (n[w]>depth)  {
    lastbt[w]^=1;
    n[w]=0;
  }
  n[w]++;
  bt=lastbt[w];

  return bt;
}

static inline uint32_t zosceqbitsIf(uint32_t depth, uint32_t in, uint32_t w){   
  uint32_t bt;
  static int32_t n[4]={0};
  static int32_t nn[4]={0};
  depth=depth>>4;
  in=in>>4;
     if (n[w]>depth) {
       bt=0;
       if (nn[w]>=in) { // so equal bits from 0 / length 0 = 101010
	 n[w]=0;
       }
       nn[w]++;
     } // n     
     else {
       bt=1;
       n[w]++;
       nn[w]=0;
     }         
     return bt;
}

static inline uint32_t zosceqbitsIfA(uint32_t depth, uint32_t in, uint32_t w){   
  uint32_t bt;
  static int32_t n[4]={0};
  static int32_t nn[4]={0};
  ADCgen;
  depth=depth>>4;
  in=in>>4;
     if (n[w]>depth) {
       bt=0;
       if (nn[w]>=in) { // so equal bits from 0 / length 0 = 101010
	 n[w]=0;
       }
       nn[w]++;
     } // n     
     else {
       bt=1;
       n[w]++;
       nn[w]=0;
     }         
     return bt;
}

static inline uint32_t zosceqbitsIxf(uint32_t depth, uint32_t in, uint32_t w){   // swopped dpeth and in
  uint32_t bt;
  static int32_t n[4]={0};
  static int32_t nn[4]={0};
  depth=depth>>4;
  in=in>>4;
     if (n[w]>in) {
       bt=0;
       if (nn[w]>=depth) { // so equal bits from 0 / length 0 = 101010
	 n[w]=0;
       }
       nn[w]++;
     } // n     
     else {
       bt=1;
       n[w]++;
       nn[w]=0;
     }         
     return bt;
}

static inline uint32_t zosceqbitsIxfA(uint32_t depth, uint32_t in, uint32_t w){   // swopped dpeth and in
  uint32_t bt;
  static int32_t n[4]={0};
  static int32_t nn[4]={0};
  ADCgen;
  depth=depth>>4;
  in=in>>4;

     if (n[w]>in) {
       bt=0;
       if (nn[w]>=depth) { // so equal bits from 0 / length 0 = 101010
	 n[w]=0;
       }
       nn[w]++;
     } // n     
     else {
       bt=1;
       n[w]++;
       nn[w]=0;
     }         
     return bt;
}

static inline uint32_t zosc1bitsIf(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt[4]={0};
  static uint32_t n[4]={0};
  depth=4095-depth;
  depth=depth>>4;

  if (n[w]>depth)  {
    lastbt[w]^=1;
    n[w]=0;
  }
  n[w]++;
  bt=lastbt[w];
  return bt;
}

static inline uint32_t zosc1bitsIfA(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt[4]={0};
  static uint32_t n[4]={0};
  ADCgen;
  depth=4095-depth;
  depth=depth>>4;

  if (n[w]>depth)  {
    lastbt[w]^=1;
    n[w]=0;
  }
  n[w]++;
  bt=lastbt[w];
  return bt;
}

static inline uint32_t zosc1bitsIslow(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t lastbt[4]={0};
  static uint32_t n[4]={0};
  depth=4095-depth;
  depth=depth<<4;
  if (n[w]>depth)  {
    lastbt[w]^=1;
    n[w]=0;
  }
  n[w]++;
  bt=lastbt[w];
  return bt;
}

static inline uint32_t zonebitsI(uint32_t depth, uint32_t in, uint32_t w){ // depth=0 resets STROBE
  uint32_t bt;
  static int32_t bc[4]={31};
    if (gate[w].trigger) depth=0;  
  if (bc[w]<0) {
    bt=0;
    if (depth>0) bc[w]=depth;
  }
  else{
  bt = 1; // this means that MSB comes out first
  }
  bc[w]--;
  return bt;
}

static inline uint32_t zENsbitsI(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  if ((LFSR__[w]>>4)>(depth>>4)) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
    //    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | prob)==255) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t zENsbitsIS_(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt, tmp;
  if ((LFSR__[w]>>4)>(depth>>4)) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
    //    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | prob)==255) bt=(LFSR_[w]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;	   // cycle bit

  return bt;
}

static inline uint32_t zlfsrbitsI(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt;
  depth=depth>>7;// how many?lfsr_taps[32][4]
  //  depth=31-depth;
    bt = ((ADCshift_[w] >> (lfsr_taps[depth][0])) ^ (ADCshift_[w] >> (lfsr_taps[depth][1])) ^ (ADCshift_[w] >> (lfsr_taps[depth][2])) ^ (ADCshift_[w] >> (lfsr_taps[depth][3]))) & 1u;
    ADCshift_[w]=(ADCshift_[w]<<1)+bt;
    if (ADCshift_[w]==0) ADCshift_[w]=0xff;
    return bt;
}

static inline uint32_t zflipbitsI(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t n[4];
  depth=depth>>4; // 8 bits say
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; // returnbits				
  if (n[w]>depth)  {
    bt=!bt;
    n[w]=0;
  }
  n[w]++;
  return bt;
}

static inline uint32_t zlfsrbitsIA(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt;
  ADCgen;
  depth=depth>>7;// how many?lfsr_taps[32][4]
  //  depth=31-depth;
    bt = ((ADCshift_[w] >> (lfsr_taps[depth][0])) ^ (ADCshift_[w] >> (lfsr_taps[depth][1])) ^ (ADCshift_[w] >> (lfsr_taps[depth][2])) ^ (ADCshift_[w] >> (lfsr_taps[depth][3]))) & 1u;
    ADCshift_[w]=(ADCshift_[w]<<1)+bt;
    if (ADCshift_[w]==0) ADCshift_[w]=0xff;
    return bt;
}

static inline uint32_t zflipbitsIA(uint32_t depth, uint32_t in, uint32_t w){  
  uint32_t bt;
  static uint32_t n[4];
  ADCgen;
  depth=depth>>4; // 8 bits say
  bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01; // returnbits				
  if (n[w]>depth)  {
    bt=!bt;
    n[w]=0;
  }
  n[w]++;
  return bt;
}

static inline uint32_t zcompbits(uint32_t depth, uint32_t in, uint32_t w){  //INx we need 
  uint32_t bt;
  if (in<depth) bt=0; // which way round?
  else bt=1;
  return bt;
}

static inline uint32_t zcompbitsS_(uint32_t depth, uint32_t in, uint32_t w){  //INx we need 
  uint32_t bt;
  if (in<depth) bt=0; // which way round?
  else {
    bt=1;
  }
  return bt;
}

static inline uint32_t zpattern4bits(uint32_t depth, uint32_t in, uint32_t w){ //INx
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  depth=4095-depth;
  if (n>depth){
    n=0;nn=0;
    k=in&15;
  }
  if (nn>3){ // or count down
    nn=0;
  }
  bt=(k>>nn)&1;
  n++; nn++;
  return bt;
}

static inline uint32_t zpattern8bits(uint32_t depth, uint32_t in, uint32_t w){ //INx
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  depth=4095-depth;
  if (n>depth){
    n=0;nn=0;
    k=in&255;
  }
  if (nn>7){ // or count down
    nn=0;
  }
  bt=(k>>nn)&1;
  n++; nn++;
  return bt;
}

static inline uint32_t zpattern4bitsI(uint32_t depth, uint32_t in, uint32_t w){ //INx
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  depth=4095-depth;
  if (n[w]>depth){
    n[w]=0; nn[w]=0;
    k[w]=in&15;
  }
  if (nn[w]>3){ // or count down
    nn[w]=0;
  }
  bt=(k[w]>>nn[w])&1;
  n[w]++; nn[w]++;
  return bt;
}

static inline uint32_t zpattern8bitsI(uint32_t depth, uint32_t in, uint32_t w){ //INx
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
    depth=4095-depth;
  if (n[w]>depth){
    n[w]=0; nn[w]=0;
    k[w]=in&255;
  }
  if (nn[w]>7){ // or count down
    nn[w]=0;
  }
  bt=(k[w]>>nn[w])&1;
  n[w]++; nn[w]++;
  return bt;
}

static inline uint32_t sigmadelta(uint32_t depth, uint32_t in, uint32_t w){  // processor for any int/depth
  uint32_t bt=0;
  static int32_t integrator[4]={0,0,0,0}, oldValue[4]={0,0,0,0};
  integrator[w]+=(depth-oldValue[w]);
   if(integrator[w]>2048)
  {
     oldValue[w]=4095;
     bt=1;
  }
   else
   {
      oldValue[w]=0;
      bt=0;
   }   
  return bt;
}

static inline uint32_t sigmadeltaA(uint32_t depth, uint32_t in, uint32_t w){  // processor for any int/depth
  uint32_t bt=0;
  static int32_t integrator[4]={0,0,0,0}, oldValue[4]={0,0,0,0};
  ADCgen;
  integrator[w]+=(depth-oldValue[w]);
   if(integrator[w]>2048)
  {
     oldValue[w]=4095;
     bt=1;
  }
   else
   {
      oldValue[w]=0;
      bt=0;
   }   
  return bt;
}

static inline uint32_t sigmadeltaS_(uint32_t depth, uint32_t in, uint32_t w){  // processor for any int/depth
  uint32_t bt=0;
  static int32_t integrator[4]={0,0,0,0}, oldValue[4]={0,0,0,0};
  integrator[w]+=(depth-oldValue[w]);
   if(integrator[w]>2048)
  {
     oldValue[w]=4095;
     bt=1;
   }
   else
   {
      oldValue[w]=0;
      bt=0;
   }   
  return bt;
}

//////////////////////////////////////////////////////////////////////////
//5 ADCs

//uint32_t (*inall[64])(uint32_t depth, uint32_t in, uint32_t wh)={zadcx, zadcx, zadconebitsx, zadcpadbits, zadc8bits, zadc4bits, zadcenergybits, zadc12compbits, zadc8compbits, zadc4compbits, zadccompbits, zadconecompbits, zadcLBURST0, zadcxdouble, zadc4bitsadd,  zadc4bitsaddmod, zadc4bitsxor, zadc4bitsor, zadc4bitsand, zadc4bitsmodm, zadc4compbitsadd, zadc4compbitsxor, zadc4compbitsmodm, zadc4onecompbitsadd/*24*/}; // double up for dacmix/macro

static inline uint32_t zadcx(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      ADCgeneric; 
      k=k>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

/* // when depth=0;
      ADCgeneric;
      k=k>>11; 
      bt = k&0x01; // this means that MSB comes out first
*/

static inline uint32_t zadcxdac(uint32_t depth, uint32_t in, uint32_t w){ // max 12 bits // new template for adcs - in is now mixer
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      MIXin;
      k=k>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadconebitsx(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt,k;
  static uint32_t bc=31;
  static float integratorf=0.0f, oldvaluef=0.0f;
  float inb;
  depth=depth>>7; // 5 bits
  if (bc>depth){
    ADCgeneric;
    inb=(float)(k);
  inb=inb/4096.0f;
  integratorf+=(inb-oldvaluef);
  bc=0;
  }
  bc++;
  if(integratorf>0.0)
      {
	oldvaluef=1.0;
	bt=1;
      }
  else
    {
      oldvaluef=-1.0;
      bt=0;
    }
  return bt;
}

static inline uint32_t zadconebitsxdac(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt,k;
  static uint32_t bc=31;
  static float integratorf=0.0f, oldvaluef=0.0f;
  float inb;
  depth=depth>>7; // 5 bits
  if (bc>depth){
    ADCgeneric;								
    float mult=mixer[in>>2];						
    inb=((float)(k) *  (1.0f-mult)) + ((float)(gate[dacIN[daccount][w]].dac)*mult); 
    inb=inb/4096.0f;
  integratorf+=(inb-oldvaluef);
  bc=0;
  }
  bc++;
  if(integratorf>0.0)
      {
	oldvaluef=1.0;
	bt=1;
      }
  else
    {
      oldvaluef=-1.0;
      bt=0;
    }
  return bt;
}

static inline uint32_t zadcpadbits(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    ADCgeneric;
    depth=depth>>7; // 5 bits
    if (depth<12) k=k>>(11-depth);
    else {
      k=k<<(depth-11);
    }
    bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadcpadbitsdac(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0) {
    MIXin;
    depth=depth>>7; // 5 bits
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc12bits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12,8,4  - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc8bits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>4;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first - no depth!
  bc--;
  return bt;
}

static inline uint32_t zadc8bitsdac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=k>>4;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first - no depth!
  bc--;
  return bt;
}

static inline uint32_t zadc4bits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitssplit(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31, bb;
  static uint32_t k;
  depth=4095-depth;
  if (spdfracx(depth, in, w)){
    if (bc<0) {
      ADCgeneric;
      k=k>>8;
      bc=3; 
  }
  bb = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  }
  return bb;
}

static inline uint32_t zadc4bitsin(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      k=in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsdac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitssplitdac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31, bb;
  static uint32_t k;
  depth=4095-depth;
  if (spdfracx(depth, in, w)){
    if (bc<0) {
      MIXin;
      k=k>>8;
      bc=3; 
  }
  bb = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  }
  return bb;
}


static inline uint32_t zadceqbits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt;
  static int32_t bc=31;
  static int32_t k;
  if (bc<0) {
    ADCgeneric;
    depth=depth>>7; // 5 bits
    //    if (depth>31) depth=31; // and if depth is higher?
    k=k/divy[depth];
    bc=depth;
  }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
  bc--;
  return bt;
}

static inline uint32_t zadcenergybits(uint32_t depth, uint32_t in, uint32_t w){ // equiv bits energy TODO: use this
  uint32_t bt;
  static int32_t bc=31;
  int32_t tmp;
  static int32_t k;
    depth=depth>>7; // 5 bits
    depth=31-depth;
    if (bc>depth) {
      ADCgeneric;
      tmp=k-2048;
      k=abs(tmp);
      k=k/divy[depth];
      bc=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    bc++;    
    return bt;
}

static inline uint32_t zadcenergybitsdac(uint32_t depth, uint32_t in, uint32_t w){ // equiv bits energy TODO: use this
  uint32_t bt;
  static int32_t bc=31;
  int32_t tmp;
  static uint32_t k;
    depth=depth>>7; // 5 bits
    depth=31-depth;
    if (bc>depth) {
      MIXin;
      tmp=k-2048;
      k=abs(tmp);
      k=k/divy[depth];
      bc=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    bc++;    
    return bt;
}

static inline uint32_t zadc12compbits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (bitwise) k=(~k)+1;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc8compbits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 8 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (bitwise) k=(~k)+1;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadccompbits(uint32_t depth, uint32_t in, uint32_t w){ // variable depth 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      depth=depth>>7; // 5 bits
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 
      
      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;
      k=abs(k-(1<<depth));
      if (bitwise) k=(~k)+1;
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc12compbitsdac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (bitwise) k=(~k)+1;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc8compbitsdac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 8 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (bitwise) k=(~k)+1;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbitsdac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadccompbitsdac(uint32_t depth, uint32_t in, uint32_t w){ // variable depth 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      depth=depth>>7; // 5 bits
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 
      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;
	  k=abs(k-(1<<depth));
      if (bitwise) k=(~k)+1;
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

////

static inline uint32_t zadc12onecompbits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc8onecompbits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 8 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4onecompbits(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadconecompbits(uint32_t depth, uint32_t in, uint32_t w){ // variable 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      depth=depth>>7; // 5 bits
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 

      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;

      k=abs(k-(1<<depth));
      if (k==0) k=1;
      if (bitwise) k=(~k);
      //     bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadconecompbitsdac(uint32_t depth, uint32_t in, uint32_t w){ // variable 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      depth=depth>>7; // 5 bits
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 

      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;

      k=abs(k-(1<<depth));
      if (k==0) k=1;
      if (bitwise) k=(~k);
      //     bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}


static inline uint32_t zadcLBURST0dac(uint32_t depth, uint32_t in, uint32_t w){ // 
  static uint32_t bt,k;
  if (gate[w].trigger){
    train[w]=1;
  }
  if (train[w]!=0 && train[w]< (1024-(depth>>2))){
  train[w]++;
  //  bitn^=ADC_(wh,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  bt=zadc4bitsdac(0, 0, w);
  }
  else {
    train[w]=0;
  }
  return bt;
}

static inline uint32_t zadccomp(uint32_t depth, uint32_t in, uint32_t w){ // 
  uint32_t bt=0,k;
  ADCgeneric;
  if (k>depth) bt=1;
  return bt;
}

static inline uint32_t zadcxdouble(uint32_t depth, uint32_t in, uint32_t w){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      ADCgeneric;
      k=k>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  bc--;
  return bt;
}

static inline uint32_t zadcxdoubledac(uint32_t depth, uint32_t in, uint32_t w){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  
    if (bc<0) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      MIXin;
      k=k>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  bc--;
  return bt;
}

static inline uint32_t zadcxcut(uint32_t depth, uint32_t in, uint32_t w){ // max 12 bits // strobe
  uint32_t bt, length;
  static uint32_t k, nn[4]={0,0,0,0};
  static int32_t n[4]={0,0,0,0} ;
  static uint32_t toggle[4]={0,0,0,0}, lastbt[4]={0,0,0,0}, lastin[4]={0,0,0,0};

  nn[w]++;
    if (nn[w]>depth){ 
	nn[w]=0;
	toggle[w]^=1;
      }
    length=SRlength[w];
    if (length>11) length=11;

    if (n[w]<0) {
      ADCgeneric;
      lastbt[w]=(gate[dacfrom[daccount][w]].dac)>>(11-length);
      lastin[w]=k>>(11-length);
	n[w]=length;
      }
      if (toggle[w]) bt = (lastin[w]>>n[w])&0x01; // this means that MSB comes out first
      else bt = (lastbt[w]>>n[w])&0x01; // this means that MSB comes out first
    n[w]--;    
    return bt;
}

// add and other ops - only issue is if depth and in are both the same dac = how to avoid this? different dacs?
static inline uint32_t zadc4bitsadd(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=depth+k;
      k=k>>8;
      k=k&15;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsaddmod(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=depth+k;
      k=k%4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsxor(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=depth^k;
      //      if (k>4095) k=4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsor(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k|depth;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsand(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  depth=~depth;
  //  if (depth==(4095-(31<<7))) depth=15<<7;
    if (bc<0) {
      ADCgeneric;
      k=depth&k;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsmodm(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  //    if (depth==(4095-(31<<7))) depth=31<<7;

  if (bc<0) {
    ADCgeneric;
      k=k+depth;
      k=k>>8;
      k=k%256;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4onecompbitsadd(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbitsadd(uint32_t depth, uint32_t in, uint32_t w){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbitsxor(uint32_t depth, uint32_t in, uint32_t w){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      ADCgeneric;
      k=k^depth;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbitsmodm(uint32_t depth, uint32_t in, uint32_t w){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
  //      if (depth==(4095-(31<<7))) depth=31<<7;

    if (bc<0) {
      ADCgeneric;
      k=k+depth;
      k=k>>8;
      k=k%256;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

////////

static inline uint32_t zadc4bitsadddac(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=depth+k;
      k=k>>8;
      k=k&15;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsaddmoddac(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=depth+k;
      k=k%4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsxordac(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=depth^k;
      //      if (k>4095) k=4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsordac(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=k|depth;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsanddac(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  depth=~depth;

  //  if (depth==(4095-(31<<7))) depth=15<<7;
    if (bc<0) {
      MIXin;
      k=depth&k;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4bitsmodmdac(uint32_t depth, uint32_t in, uint32_t w){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  //    if (depth==(4095-(31<<7))) depth=31<<7;

  if (bc<0) {
      MIXin;
      k=k+depth;
      k=k>>8;
      k=k%256;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4onecompbitsadddac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=k+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbitsadddac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=k+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbitsxordac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0) {
      MIXin;
      k=k^depth;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

static inline uint32_t zadc4compbitsmodmdac(uint32_t depth, uint32_t in, uint32_t w){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
  //      if (depth==(4095-(31<<7))) depth=31<<7;

    if (bc<0) {
      MIXin;
      k=k+depth;
      k=k>>8;
      k=k%256;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  bc--;
  return bt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// adcs for prob or reset and/or hold

static inline uint32_t zpadcx(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      k=in>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadconebitsx(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){
  uint32_t bt;
  static uint32_t bc=31;
  static float integratorf=0.0f, oldvaluef=0.0f;
  float inb;
  depth=depth>>7; // 5 bits
  if (bc>depth || reset){
  inb=(float)(in);
  inb=inb/2048.0; // from 0 to 4095 but where is the middle? 2048

  integratorf+=(inb-oldvaluef);
  bc=0;
  }
  if (adv) bc++;
  if(integratorf>0.0)
      {
	oldvaluef=1.0;
	bt=1;
      }
  else
    {
      oldvaluef=-1.0;
      bt=0;
    }
  return bt;
}

static inline uint32_t zpadcpadbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0 || reset) {
    k=in;
    depth=depth>>7; // 5 bits
    if (depth<12) k=k>>(11-depth);
    else k=k<<(depth-11);
    bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc12bits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 12,8,4  - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc8bits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      k=k>>4;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first - no depth!
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 12,8,4 - no depth!
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadceqbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (bc<0 || reset) {
    k=in;
    depth=depth>>7; // 5 bits
    if (depth>31) depth=31; // and if depth is higher?
    k=k/divy[depth];
    bc=depth;
  }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    
    if (adv)  bc--;
  return bt;
}

static inline uint32_t zpadcenergybits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // equiv bits energy TODO: use this
  uint32_t bt;
  static int32_t bc=31;
  int32_t tmp;
  static uint32_t k;
    depth=depth>>7; // 5 bits
  if (bc>depth || reset) {

      k=in;
      tmp=k-2048;
      k=abs(tmp);
      k=k/divy[depth];
      bc=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    if (adv) bc++;    
    return bt;
}

static inline uint32_t zpadc12compbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 12 bits 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (bitwise) k=(~k)+1;
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc8compbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 8 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (bitwise) k=(~k)+1;
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4compbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset) {
      k=in;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadccompbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // variable depth 2s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0 || reset ) {
      k=in;//   k=ADC_GetConversionValue(ADC1)>>(11-depth)  is included
      depth=depth>>7; // 5 bits
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 
      
      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;
	  k=abs(k-(1<<depth));
      if (bitwise) k=(~k)+1;
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc12onecompbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in;
      if (k<2048) bitwise=1;
      else bitwise=0;
      k=abs(k-2048);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc8onecompbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 8 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in;
      k=k>>4;
      if (k<128) bitwise=1;
      else bitwise=0;
      k=abs(k-128);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=7; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4onecompbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadconecompbits(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // variable 12 bits 1s complement
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in;
      depth=depth>>7; // 5 bits
      if (depth<12) k=k>>(11-depth);
      else k=k<<(depth-11);
      bc=depth; 

      if (k<(1<<depth)) bitwise=1;
      else bitwise=0;

      k=abs(k-(1<<depth));
      if (k==0) k=1;
      if (bitwise) k=(~k);
      //     bc=11; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadcLBURST0(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // 
  static uint32_t bt;
  if (gate[w].trigger || reset){
    train[w]=1;
  }
  if (train[w]!=0 && train[w]< (1024-(depth>>2))){
    if (adv) train[w]++;
    bt=zadc4bitsin(0, in, w); // this does not have adc
  }
  else {
    train[w]=0;
  }
  return bt;
}

///???
static inline uint32_t zpadccomp(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // 
  uint32_t bt=0;
  if (in>depth) bt=1;
  return bt;
}

static inline uint32_t zpadcxdouble(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // max 12 bits
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  
    if (bc<0  || reset) {
      depth=depth>>7; // 5 bits
      if (depth>11) depth=11; // max depth
      k=in>>(11-depth); 
      bc=depth; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv){
  bc--;
  bc--;
  }
  return bt;
}

static inline uint32_t zpadcxcut(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // max 12 bits // strobe
  uint32_t bt, length;
  static uint32_t k, nn[4]={0,0,0,0};
  static int32_t n[4]={0,0,0,0} ;
  static uint32_t toggle[4]={0,0,0,0}, lastbt[4]={0,0,0,0}, lastin[4]={0,0,0,0};

  nn[w]++;
  //    if (gate[w].trigger) nn[w]++;
    if (nn[w]>depth  || reset){ 
	nn[w]=0;
	toggle[w]^=1;
      }
    length=SRlength[w];
    if (length>11) length=11;

    if (n[w]<0) {
      lastbt[w]=(gate[dacfrom[daccount][w]].dac)>>(11-length);
      lastin[w]=in>>(11-length);
	n[w]=length;
      }
      if (toggle[w]) bt = (lastin[w]>>n[w])&0x01; // this means that MSB comes out first
      else bt = (lastbt[w]>>n[w])&0x01; // this means that MSB comes out first
      if (adv) n[w]--;    
    return bt;
}

// add and other ops - only issue is if depth and in are both the same dac = how to avoid this? different dacs?
static inline uint32_t zpadc4bitsadd(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth+in;
      k=k>>8;
      k=k&15;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsaddmod(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth+in;
      k=k%4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsxor(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth^in;
      //      if (k>4095) k=4095;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsor(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=depth|in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsand(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  depth=~depth;
    if (bc<0  || reset) {
      k=depth&in;
      k=k>>8;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4bitsmodm(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ 
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in+depth;
      k=k>>8;
      k=k%256;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4onecompbitsadd(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 12 bits 1s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (k==0) k=1;      
      if (bitwise) k=(~k);
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4compbitsadd(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in+depth;
      k=k>>8;
      k=k&15;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4compbitsxor(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in^depth;
      k=k>>8;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

static inline uint32_t zpadc4compbitsmodm(uint32_t depth, uint32_t in, uint32_t w, uint32_t reset, uint32_t adv){ // fixed 4 bits 2s complement - no depth!
  uint32_t bt, bitwise;
  static int32_t bc=31;
  static uint32_t k;
    if (bc<0  || reset) {
      k=in+depth;
      k=k>>8;
      k=k%256;
      if (k<8) bitwise=1;
      else bitwise=0;
      k=abs(k-8);
      if (bitwise) k=(~k)+1;
      bc=3; 
  }
  bt = (k>>bc)&0x01; // this means that MSB comes out first
  if (adv) bc--;
  return bt;
}

/////////////////////////////////////////////////////////////////
// newer/ports from experiment.h

// vienna: divide into speedmode and bitmode
static inline uint32_t spdviennaP_(uint32_t depth, uint32_t in, uint32_t w){ // //INx
  uint32_t bt=0, speedy;
  // say CVL as depth, CV as in
  uint32_t recurse=depth>>10; // 2 bits
  if (recurse!=0){
    speedy=(in>>1)+(gate[others[w][recurse-1]].dac>>1); // can also be different versions such as modulus or mid version
    if (speedy>4095) speedy=4095;
  }
  else speedy=in;
  
  bt=spdfracP_(speedy, in, w);
  return bt;
}

static inline uint32_t spdviennaS_(uint32_t depth, uint32_t in, uint32_t w){ // //INx
  uint32_t bt=0, speedy;
  // say CVL as depth, CV as in
  uint32_t recurse=depth>>10; // 2 bits
  if (recurse!=0){
    speedy=(in>>1)+(gate[others[w][recurse-1]].dac>>1); // can also be different versions such as modulus or mid version
    if (speedy>4095) speedy=4095;
  }
  else speedy=in;
  bt=spdfrac(speedy, in, w);
  return bt;
}

static inline uint32_t spdvienna2(uint32_t depth, uint32_t in, uint32_t w){ // //INx
  uint32_t bt=0, speedy;
  // say CVL as depth, CV as in
  //  depth=4095-depth;  
  uint32_t recurse=(7-(depth>>4))&3; // 2 bits
  if (recurse!=0){
    if (in==0) speedy=depth;  else speedy=gate[others[w][recurse-1]].dac%in;
  }
  else speedy=in;
  bt=spdfrac(speedy, in, w);
  return bt;
}

static inline uint32_t spdvienna3(uint32_t depth, uint32_t in, uint32_t w){ // //INx
  uint32_t bt=0, speedy;
  // say CVL as depth, CV as in
  //  depth=4095-depth;
  uint32_t recurse=(7-(depth>>4))&3; // 2 bits
  if (recurse!=0){
    speedy=in+gate[others[w][recurse-1]].dac;
    speedy=speedy%4095;
  }
  else speedy=in;
  bt=spdfrac(speedy, in, w);

  return bt;
}

static inline uint32_t spdvienna4(uint32_t depth, uint32_t in, uint32_t w){ // //INx
  int32_t bt=0, speedy;
  // say CVL as depth, CV as in
  //  depth=4095-depth;
  uint32_t recurse=(7-(depth>>4))&3; // 2 bits
  if (recurse!=0){
  speedy=(gate[others[w][recurse-1]].dac)-2048; // adapted for full bits
  speedy+=in;  
  if (speedy<0) speedy=0;
  else if (speedy>4095) speedy=4095;
  }
  else speedy=in;
  bt=spdfrac(speedy, in, w);
  return bt;
}

static inline uint32_t viennabits(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t bt=0, tmp, tmpp, recurs, bitrr,x;
  // say CVL as depth as above - in is not used
  
  // 7 bits from mode/now CVL - 
  tmpp=127-(depth>>5); // 7 bits  
  if (tmpp>>6) recurs=1; // top bit
  
  if (recurs!=0 && w==2){ // for C only  // why?
    tmpp|=(gate[others[w][0]].shift_)&15;    
  }
  
  if (tmpp==0 && w==2) { //- for modeC only
    bitrr = (gate[4].Gshare_>>SRlength[4]) & 0x01;
    gate[w].shift_ ^=gate[4].Gshare_;
    bt=bitrr;
  }
else
  {
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bt=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
  }
  return bt;
}

//////////////////////////////////////////////////////////////////////////
////// right hand functions which change things... what are the counts we use, where are our examples

///// global functions here from exp, they don't return bits // find these

static inline void binaryN(uint32_t depth){
  uint32_t tmp, n, nn, nnn;
  // all counts need that extra or
  //  count=16; // sets to zero - but could also be ORed with route we already have as another version // count16 is  0,0,0,0, null routes... // but we set all counts the same so have a problem
  depth=depth>>10;// 2 bits
  binary[0]=gate[tmp].shift_&15; // which SR? itself/runs out - binary will also need to be reset 
  binary[1]=(gate[tmp].shift_>>4)&15;
  binary[2]=(gate[tmp].shift_>>8)&15;
  binary[3]=(gate[tmp].shift_>>12)&15;
}

static inline void binaryX(uint32_t depth){
  uint32_t tmp;
  count=0; // reset
  tmp=depth>>10; // 2 bits
  binary[0]=gate[tmp].shift_&15; // which SR? itself/runs out - binary will also need to be reset 
  binary[1]=(gate[tmp].shift_>>4)&15;
  binary[2]=(gate[tmp].shift_>>8)&15;
  binary[3]=(gate[tmp].shift_>>12)&15;
}

static inline void resett(uint32_t depth){ // resett // no depth
    RESETG;
}

static inline void SRRglobalbumpS(uint32_t depth){ // strobe only
  if (gate[3].trigger) // outside speed?
    {
      count++;
      if (count>31) count=0; 
      daccount++;
      if (daccount>15) daccount=0;
      spdcount++;
      if (spdcount>15) spdcount=0;
    }
}

static inline void SRRglobalbumproute(uint32_t depth){ // strobe only
  if (gate[3].trigger) // outside speed?
    {
      count++;
      if (count>31) count=0; 
    }
}

static inline void SRRglobalbumpdac(uint32_t depth){ // strobe only
  if (gate[3].trigger) // outside speed?
    {
      daccount++;
      if (daccount>15) daccount=0; 
    }
}

static inline void SRRglobalbumpspd(uint32_t depth){ // strobe only
  if (gate[3].trigger) // outside speed?
    {
      spdcount++;
      if (spdcount>15) spdcount=0; 
    }
}

static inline void SRRglobalbumpcv(uint32_t depth){ // strobe only // unused
  uint32_t tmp;
  if (gate[3].trigger) // outside speed?
    {
      tmp=depth>>7; ///5 bits
      count=tmp;
      daccount=tmp>>1;
      spdcount=tmp>>1;
    }
}

static inline void SRRglobalbumpcvn(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>7; ///5 bits
  count=tmp;
  daccount=tmp>>1;
  spdcount=tmp>>1;
}

static inline void SRRglobalbumpcvnroute(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>7; ///5 bits
  count=tmp;
}

static inline void SRRglobalbumpcvndac(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>8; ///4 bits
  daccount=tmp;
}

static inline void SRRglobalbumpcvnspd(uint32_t depth){ // depth
  uint32_t tmp;
  tmp=depth>>8; ///4 bits
  spdcount=tmp;
}

static inline void SRRglobalsync(uint32_t depth){ // nada no depth
  uint32_t tmp;
  spdcount=count;
  daccount=count;
}

static inline void SRRglobaltailset(uint32_t depth){
  uint32_t tmp;
  tmp=depth>>7; ///5 bits
  tailcount=tmp;  
}

// bump

static inline void SRRglobalorder(uint32_t depth){ // depth
  uint32_t tmp;
  ordercount=depth>>6; // now 6 bits - 64
}

static inline void SRRglobalorderbumpS(uint32_t depth){ // strobe no depth
  uint32_t tmp;
  if (gate[3].trigger)
    {
      ordercount++;
      if (ordercount>63) ordercount=0; 
    }
}

static inline void SRRglobalorderbumpbit(uint32_t depth){ // nada. depth can be route // no depth
  uint32_t tmp;
  if (gate[dacfrom[daccount][3]].shift_)
    {
      ordercount++;
      if (ordercount>63) ordercount=0; 
    }
}

static inline uint32_t tailbits(uint32_t depth, uint32_t in, uint32_t w){  // just bits from the tail [4] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[4].Gshare_>>SRlength[4]) & 0x01; 
  gate[4].Gshare_=(gate[4].Gshare_<<1)+bitrr;
  bt^=bitrr;
  return bt;
}  

static inline uint32_t tailbitsnos(uint32_t depth, uint32_t in, uint32_t w){  // just bits from the tail [4] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[4].Gshare_>>SRlength[4]) & 0x01; 
  bt^=bitrr;
  return bt;
}  

static inline uint32_t tailbitsI(uint32_t depth, uint32_t in, uint32_t w){  // just bits from the tail [4] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[4].Gshift_[w]>>SRlength[4]) & 0x01; 
  gate[4].Gshift_[w]=(gate[4].Gshift_[w]<<1)+bitrr;
  bt^=bitrr;
  return bt;
}  

static inline uint32_t tailbitsInos(uint32_t depth, uint32_t in, uint32_t w){  // just bits from the tail [4] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[4].Gshift_[w]>>SRlength[4]) & 0x01; 
  bt^=bitrr;
  return bt;
}

static inline uint32_t tailbitswithd(uint32_t depth, uint32_t in, uint32_t w){  // just bits from the tail [4] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[4].Gshare_>>(depth>>7)) & 0x01; 
  gate[4].Gshare_=(gate[4].Gshare_<<1)+bitrr;
  bt^=bitrr;
  return bt;
}  

static inline uint32_t tailbitswithdnos(uint32_t depth, uint32_t in, uint32_t w){  // just bits from the tail [4] // shared version // no depth, no in // or use depth as (& 1<<(depth>>7))
  uint32_t bt=0, bitrr;
  bitrr = (gate[4].Gshare_>>(depth>>7)) & 0x01; 
  bt^=bitrr;
  return bt;
}  

//// new splits etc:

// just out last value
static inline uint32_t Zlast(uint32_t depth, uint32_t in, uint32_t w){   // 
  return gate[w].lastest;
}
  
static inline uint32_t Zbinroutsplit(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  static uint32_t bbb[5]={0,0,0,0};
  if (spdfracx(depth, in, w)){
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  bbb[w]=bitn;
  }
  return bbb[w];
}

// also we need a cycle split
static inline uint32_t Zcyclesplit(uint32_t depth, uint32_t in, uint32_t w){   // no types
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  static uint32_t bbb[5]={0,0,0,0};
  depth=4095-depth;
  if (spdfracx(depth, in, w)){
    bbb[w]=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bbb[w];
}

// fixed prob of same split speed route vs. cycle - depth as prob. leaves in //   
static inline uint32_t Zbinroutsplitprob(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  static uint32_t bbb[5]={0,0,0,0};
  if ((in>>4)>(LFSR__[w]>>4)){
  if (spdfracx(depth, in, w)){
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  bbb[w]=bitn;
    }
  else {
    bbb[w]=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  }
  return bbb[w];
}

// fixed prob of fixed speed route vs. cyclesplit
static inline uint32_t Zbinroutsplitprob1(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0, bbb;
  static uint32_t bob[5]={0,0,0,0};
  if ((in>>4)>(LFSR__[w]>>4)){
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  bbb=bitn;
  }
  else {
  if (spdfracx(depth, in, w)){
    bob[w]=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  bbb=bob[w];
  }
  return bbb;
}

// and vice versa
static inline uint32_t Zbinroutsplitprob2(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0, bbb;
  static uint32_t bob[5]={0,0,0,0};
  if ((in>>4)>(LFSR__[w]>>4)){
  if (spdfracx(depth, in, w)){
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  bob[w]=bitn;
  }
  bbb=bob[w];
  }
  else {
    bbb=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  return bbb;
}

static inline uint32_t Zbinroutsplitxor(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0, bbb;
  static uint32_t bob[5]={0,0,0,0};
  if (spdfracx(depth, in, w)){
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  bob[w]=bitn;
  }
  bbb=bob[w];
  bbb^=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  return bbb;
}

// and vice versa
static inline uint32_t Zbinroutsplitxor1(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0, bbb;
  static uint32_t bob[5]={0,0,0,0};
  if (spdfracx(depth, in, w)){
  bob[w]=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  bbb=bob[w]^bitn;
  return bbb;
}

// and seperate speeds for strobe and CVL or... but then we need extra spdfracs?
static inline uint32_t  ZbinroutsplitxorXX(uint32_t depth, uint32_t in, uint32_t w){   // 
  uint32_t bitrr, tmp, tmpp, x, bitn=0;
  static uint32_t bob[5]={0,0,0,0};
  static uint32_t bbb[5]={0,0,0,0};
  if (spdfracx(depth, in, w)){
  bob[w]=(gate[w].Gshift_[w]>>SRlength[w]) & 0x01;
  }
  if (spdfracxx(in, depth, w)){
  tmp=binroute[count][w]|binary[w]; 
  tmpp=gate[w].routetype;
  ROUTETYPE_;
  bbb[w]=bitn;
  }
  tmp=bbb[w]^bob[w];
  return tmp;
}
