//// comment/ catalogue...

/*
older:

- processors: hold bits, bits to value, value to bits and independent versions
- speedgens with no params and default routes: sadcfrac, sdacfrac, sstrobe, sstrobeint, sbinroute, scycle, sprob, sprobdac, sclksr
- generators: depth, wh

- independent generators - so no shared stuff

 */

//////////////////////////////////////////////////////////////////////////

static inline uint32_t Gbinroute(uint32_t depth, uint8_t w){   // depth as routesel... shared bits now
  uint32_t x, tmp, bitrr, bitn=0;
    uint32_t tmpp=binroutetypes[binroutetypecount][w];
    switch(tmpp){
    case 0:
      BINROUTE_;
    break;
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
      BINROUTEtrig_;
    break;
    case 7:
      BINROUTEnoalt_;  // new one which just cycles and doesn't reset
    break;
    }
    return bitn;
}

//////////////////////////////////////////////////////////////////////////
// lengths

static uint8_t held[4]={0,0,0,0};

static inline uint32_t rlen(uint32_t depth, uint8_t wh){
  held[wh]=0; // release hold
  uint32_t bt=lookuplenall[depth>>7]; // 5 bits
  return bt; // bt is a value
}

// hold old [CVL/depth] length
static inline uint32_t holdlen(uint32_t depth, uint8_t wh){
  static uint32_t oldd=0;
  if (held[wh]==0) oldd=depth;
  held[wh]=1;  
  uint32_t bt=lookuplenall[oldd>>7]; // 5 bits
  return bt; // bt is a value

}

//////////////////////////////////////////////////////////////////////////
// abstract GENERATORS... adc ones are in adcetc.h
// some don't use depth, how to deal with this? can also be more INVERTED ones!

///////////////////////////////////////////////
// PROCESSORS - but need to be shared 

// low pass for values, depth is betaf, bit is value
static inline uint32_t SRproc_lp(uint32_t depth, uint32_t bit, uint8_t w){ 
  float betaf, inb, SmoothData[4]={0.0,0.0,0.0,0.0};
    betaf=(float)(depth)/4096.0f; // between 0 and 1?
    //betaf=0.1f;
    SmoothData[w] = SmoothData[w] - (betaf * (SmoothData[w]-(float)(bit))); //
    inb=SmoothData[w];
    return bit;
}


//- holder function - hold bits for /depth/ time - which bits? - this is more of a processor though...
// delay line or hold until new value we can take
static inline uint32_t SRproc_hold(uint32_t depth, uint32_t bit){ 
  static uint32_t bt=0;
  static uint32_t cnt=0, top=0;
  cnt++;
  if (cnt>top){
    top=depth;
    bt=bit;
    cnt=0;
  }
  return bt;
}

// real delay line, bit enters and we furnish bit at depth x - shared version - we have in experiment.h but there uses binroute
static inline uint32_t SRproc_delay(uint32_t depth, uint32_t bit){  
  static uint32_t delayline[128]; //shared delay line
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits; // 32 bits of bits

  // extract from delay line (12 bits=4095)
  depth=bits+depth;
  if (depth>=4095) depth-=4095;
  tmp=depth/32;
  bitrr=(delayline[tmp]>>(depth%32))&0x01;

  // put into delay line - need index and bit index
  tmp=bits/32;
  tmpp=bits%32;
  delayline[tmp]&=bitmasky[tmpp];
  delayline[tmp]|=(bit<<(tmpp));
  bits++;
  if (bits>4095) bits=0;

  return bitrr;
}
  
// delay line for values - shared...
static inline uint32_t SRproc_delayvals(uint32_t depth, uint32_t bit){  
  static uint32_t delayline[128]; //shared delay line
  uint32_t bt=0, bitrr, tmp, tmpp;
  static uint32_t bits; // 32 bits of bits

  // extract from delay line (12 bits=4095)
  depth=bits+depth;
  if (depth>=128) depth-=128;
  bitrr=delayline[depth];

  // put into delay line
  delayline[bits]=bit;
  bits++;
  if (bits>127) bits=0;

  return bitrr;
}

// bits to value
static inline uint32_t SRproc_accum(uint32_t depth, uint32_t bit){ 
  static uint32_t bt=0, cc=0, final;
  cc++;
  if (cc>depth) {
    final=bt;
    cc=0;
    bt=0;
  }
  if (bit) {
    bt++;
  }
  return final; // returns last final value
}

// value to bits - depth is value to shift out, bit is length - runs until new bits needed
static inline uint32_t SRproc_bits(uint32_t depth, uint32_t bit){ 
  static int32_t cc=0;
  uint32_t bt;
  static uint32_t bits;
  bt=(bits>>cc)&0x01;
  cc--;
  if (cc<0) {
    cc=bit;
    bits=depth;
  }
  return bt; // returns a bit
}

// independent versions of these as they share values...

static inline uint32_t SRproc_holdI(uint32_t depth, uint32_t bit, uint8_t wh){ 
  static uint32_t bt[4]={0,0,0,0};
  static uint32_t cnt[4]={0,0,0,0};
  static uint32_t top[4]={0,0,0,0};

  cnt[wh]++;
  if (cnt[wh]>top[wh]){
    top[wh]=depth;
    bt[wh]=bit;
    cnt[wh]=0;
  }
  return bt[wh];
}

// bits to value
static inline uint32_t SRproc_accumI(uint32_t depth, uint32_t bit, uint8_t wh){ 
  static uint32_t bt[4]={0,0,0,0}, cc[4]={0,0,0,0}, final[4];
  cc[wh]++;
  if (cc[wh]>depth) {
    final[wh]=bt[wh];
    cc[wh]=0;
    bt[wh]=0;
  }
  if (bit) {
    bt[wh]++;
  }
  return final[wh]; // returns last final value
}

static inline uint32_t SRproc_bitsI(uint32_t depth, uint32_t bit, uint8_t wh){ 
  static int32_t cc[4]={0,0,0,0};
  uint32_t bt;
  static uint32_t bits[4]={0,0,0,0};
  bt=(bits[wh]>>cc[wh])&0x01;
  cc[wh]--;
  if (cc[wh]<0) {
    cc[wh]=bit;
    bits[wh]=depth;
  }
  return bt; // returns a bit
}

////////////////////////////////////////////////////////////// GENS
// speedgens with no params, just wh and use default routes

// rework so is with depth eg.
static inline uint32_t adcfrac(uint32_t depth, uint8_t wh){ 
  uint32_t bt=0;
  float speed;
  speed=logspeedd[depth>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  if(gate[wh].last_time<gate[wh].int_time) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  return bt;
}


//////////////////////////////////////////////////////////////

static inline uint32_t sadcfrac(uint8_t wh){ 
  uint32_t bt=0;
  float speed;
  speed=logspeedd[CV[wh]>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  if(gate[wh].last_time<gate[wh].int_time) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  return bt;
}

static inline uint32_t sadcfracint(uint8_t w){  // interpol/dacout is inside now
  uint32_t bt=0;
  float speed;
  speed=logspeedd[CV[w]>>2]; // 12 bits to 10 bits

  gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
  gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
  if (gate[w].dac>4095) gate[w].dac=4095;
  
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


// sadcfrac with stoppage - this is the only one what needs it
static inline uint32_t sadcfracstop(uint8_t wh){ 
  uint32_t bt=0;
  float speed;
  speed=logspeed[CV[wh]>>2]; // 12 bits to 10 bits
  if (wh==2 || speed!=2.0f){ 
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  if(gate[wh].last_time<gate[wh].int_time) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  }
  return bt;
}

static inline uint32_t sdacfrac(uint8_t wh){ // variations where we temper the dac
  uint32_t bt=0;
  float speed;
  speed=logspeedd[gate[speedfrom[count][wh]].dac>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;

  if(gate[wh].last_time<gate[wh].int_time) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  return bt;
}

static inline uint32_t sdacfracint(uint8_t wh){ // variations where we temper the dac
  uint32_t bt=0;
  float speed;
  speed=logspeedd[gate[speedfrom[count][wh]].dac>>2]; // 12 bits to 10 bits
  gate[wh].alpha = gate[wh].time_now - (float)gate[wh].int_time;
  gate[wh].dac = ((float)delay_buffer[wh][DELAY_SIZE-5] * gate[wh].alpha) + ((float)delay_buffer[wh][DELAY_SIZE-6] * (1.0f - gate[wh].alpha));
  if (gate[wh].dac>4095) gate[wh].dac=4095;

  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;

  if(gate[wh].last_time<gate[wh].int_time) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  return bt;
}


static inline uint32_t sstrobe(uint8_t wh){   // strobe - no depth
  uint32_t bt;
  bt=gate[wh].trigger;
  gate[wh].dac = delay_buffer[wh][1];
  return bt;
}

static inline uint32_t sstrobeint(uint8_t wh){
  uint32_t bt=0;
  static float speed;
  //  speed=logspeedd[depth>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  gate[wh].lastest++;
  if(gate[wh].trigger) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    speed=1.0f/(float)gate[wh].lastest; 
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
    gate[wh].lastest=0;
  }
  return bt;
}

static inline uint32_t sbinroute(uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr, depth;
  depth=binroute[count][wh]|binary[wh];

  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  gate[wh].dac = delay_buffer[wh][1];
  return bt;
}

static inline uint32_t sbinroute0(uint8_t w){   // depth as routesel... shared bits now
  uint32_t bitn=0, bitrr, tmp,x;
  tmp=binroute[count][w]|binary[w];
  BINROUTESRstrip_;
  gate[w].dac = delay_buffer[w][1];
  return bitn;
}

static inline uint32_t sbinroute1(uint8_t w){   // depth as routesel... shared bits now
  uint32_t bitn=0, bitrr, tmp,x;
  tmp=binroute[count][w]|binary[w];
  BINROUTEaltstrip_;
  return bitn;
}

static inline uint32_t sbinroute2(uint8_t w){   // depth as routesel... shared bits now
  uint32_t bitn=0, bitrr, tmp,x;
  tmp=binroute[count][w]|binary[w];
  BINROUTEZEROstrip_;
  return bitn;
}

static inline uint32_t sbinroute3(uint8_t w){   // depth as routesel... shared bits now
  uint32_t bitn=0, bitrr, tmp,x;
  tmp=binroute[count][w]|binary[w];
  BINROUTESHAREstrip_;
  return bitn;
}

static inline uint32_t sbinroute4(uint8_t w){   // depth as routesel... shared bits now
  uint32_t bitn=0, bitrr, tmp,x;
  tmp=binroute[count][w]|binary[w];
  BINROUTENOGstrip_;
  return bitn;
}

static inline uint32_t sbinroute5(uint8_t w){   // depth as routesel... shared bits now
  uint32_t bitn=0, bitrr, tmp,x;
  tmp=binroute[count][w]|binary[w];
  BINROUTEtrigstrip_;
  return bitn;
}

static inline uint32_t sbinroute6(uint8_t w){   // depth as routesel... shared bits now
  uint32_t bitn=0, bitrr, tmp,x;
  tmp=binroute[count][w]|binary[w];
  BINROUTEnoaltstrip_;  // new one which just cycles and doesn't reset
  return bitn;
}

static inline uint32_t scycle(uint8_t wh){   // itself/cycle
  uint32_t bt=0;
  bt=((gate[wh].Gshift_[wh]>>SRlength[wh])& 0x01);
  return bt;
}

static inline uint32_t sprob(uint8_t wh){   // PROBability mode - against LFSR - uses cv
  uint32_t bt=0;
  if (CV[wh]<(LFSR_[wh]&4095)) bt=1;
  gate[wh].dac = delay_buffer[wh][1];
  return bt;
}

static inline uint32_t sprobdac(uint8_t wh){   // PROBability mode - against DAC  - uses cv
  uint32_t bt=0;
  if (CV[wh]<gate[dacfrom[count][wh]].dac) bt=1;
  gate[wh].dac = delay_buffer[wh][1];
  return bt;
}

static inline uint32_t sclksr(uint8_t wh){ 
  uint32_t bt=0;
  bt=(clksr_[wh]>>SRlength[wh])&0x01;
  gate[wh].dac = delay_buffer[wh][1];
  return bt;
}


////////////////////////////////////////////////////////////// GENS

//template
static inline uint32_t SRttt(uint32_t depth, uint8_t wh){  // 
  uint32_t bt=0;
  return bt;
}

// zero/nada
static inline uint32_t SRzero(uint32_t depth, uint8_t wh){  // returns only zeroes
  uint32_t bt=0;
  return bt;
}

// one - can also be for speeds or otherwise
static inline uint32_t SRone(uint32_t depth, uint8_t wh){ 
  uint32_t bt=1;
  return bt;
}

static inline uint32_t Sone(uint8_t wh){
  uint32_t bt=1;
  return bt;
}


// top bit of clksr 
static inline uint32_t SRclksr(uint32_t depth, uint8_t wh){ 
  uint32_t bt=0;
  bt=(clksr_[wh]>>depth)&0x01;
  return bt;
}

// how could we cycle through clksr if it is not moving - we need gsr for them -clksrG_
static inline uint32_t SRclksrG(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  bt=(clksrG_[wh]>>depth)&0x01;
  clksrG_[wh]=(clksrG_[wh]<<1)+bt; // this also changes patterns there
  return bt;
}

static inline uint32_t SRsigmadelta(uint32_t depth, uint8_t wh){  // processor for any int/depth
  uint32_t bt=0;
  static int32_t integrator=0, oldValue=0;
  
  integrator+=(depth-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
  return bt;
}

// replacing embedded speed... in new abstractions...
static inline uint32_t speedfrac(uint32_t depth, uint8_t wh){ // depth is speed - can be dacspeed but for now we dont do ==2/stoppage - trial with stopps
  uint32_t bt=0;
  float speed;
  speed=slowerlog[depth>>2]; // 12 bits to 10 bits
  if (speed!=2.0f){
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;

  if(gate[wh].last_time<gate[wh].int_time) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  }
  return bt;
}

static inline uint32_t speedfracint(uint32_t depth, uint8_t wh){ // depth is speed - can be dacspeed but for now we dont do ==2/stoppage - trial with stopps
  uint32_t bt=0;
  float speed;
  speed=slowerlog[depth>>2]; // 12 bits to 10 bits
  if (speed!=2.0f){
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;

  gate[wh].alpha = gate[wh].time_now - (float)gate[wh].int_time;
  gate[wh].dac = ((float)delay_buffer[wh][DELAY_SIZE-5] * gate[wh].alpha) + ((float)delay_buffer[wh][DELAY_SIZE-6] * (1.0f - gate[wh].alpha));
  if (gate[wh].dac>4095) gate[wh].dac=4095;
  
  if(gate[wh].last_time<gate[wh].int_time) {
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  }
  return bt;
}

static inline uint32_t speedfracnoint(uint32_t depth, uint8_t wh){ // depth is speed - can be dacspeed but for now we dont do ==2/stoppage - trial with stopps
  uint32_t bt=0;
  float speed;
  speed=slowerlog[depth>>2]; // 12 bits to 10 bits
  if (speed!=2.0f){
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  gate[wh].dac = delay_buffer[wh][1];
  
  if(gate[wh].last_time<gate[wh].int_time) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
  }
  }
  return bt;
}

static inline uint32_t strobeint(uint32_t depth, uint8_t wh){ // kind of works...
  uint32_t bt=0;
  static float speed;
  //  speed=logspeedd[depth>>2]; // 12 bits to 10 bits
  gate[wh].time_now += speed;
  gate[wh].last_time = gate[wh].int_time;
  gate[wh].int_time = gate[wh].time_now;
  gate[wh].lastest++;
  if(gate[wh].trigger) {
    gate[wh].dac = delay_buffer[wh][1];
    bt=1; // move on
    speed=1.0f/(float)gate[wh].lastest; 
    gate[wh].time_now-=1.0f;
    gate[wh].int_time=0;
    gate[wh].lastest=0;
  }
  return bt;
}

// try 8 bit cipher mode
//ADC in comparator -> bits, clked/speed into GGSR which shifts along, on strobe GGSR copied to SR
static inline uint32_t cipherbits(uint32_t depth, uint8_t wh){
  uint32_t bt, k;
  uint32_t kw[4]={0,0,0,0};
  static uint32_t gs[4]={0,0,0,0};
  ADCgeneric;
  kw[wh]=k;
  //  depth=(depth-2048)<<1;
  if (kw[wh]>(2000)) bt=1; // we ignore depth - what it could be used for...
  else bt=0;
  
  // onto SR
  GGGshift_[wh]=GGGshift_[wh]<<1;
  GGGshift_[wh]+=bt;
  // on strobe copy to gs
  if (gate[wh].trigger) gs[wh]=GGGshift_[wh];
  bt=(gs[wh]>>8)&0x01; // how long?
  //  gs[wh]=gs[wh]<<1; // that one doesn't shift
  
  return bt;
}

// can also be other comps eg. dac. how we could stack this up and why this is a generator, can also be shared across all...
// shared and unsured adcs...

//four SRbits
static inline uint32_t SRNbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[0].Gshift_[wh]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

static inline uint32_t SRLbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[1].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t SRCbits(uint32_t depth, uint8_t wh){ 
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[2].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t SRRbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  bt = (gate[3].Gshift_[wh]>>depth) & 0x01;
  return bt;
}

static inline uint32_t strobebits(uint32_t depth, uint8_t wh){   // strobe - no depth
  uint32_t bt;
  bt=gate[wh].trigger;
  return bt;
}

static inline uint32_t togglebits(uint32_t depth, uint8_t wh){   // toggle - no depth
  static uint32_t bt=0;
  if (gate[wh].trigger) bt=bt^1;
  return bt;
}

static inline uint32_t pulsebits(uint32_t depth, uint8_t wh){   // toggle - no depth
  uint32_t bt=0;
  if (pulse[wh]){
    bt=!(GPIOC->IDR & pulsins[wh]);
  }
  return bt;
}

static inline uint32_t probbits(uint32_t depth, uint8_t wh){   // PROBability mode
  uint32_t bt=0;
  if (depth<(LFSR_[wh]&4095)) bt=1;
  return bt;
}

static inline uint32_t probbitsxorstrobe(uint32_t depth, uint8_t wh){   // PROBability mode xor strobe - can be more ops
  uint32_t bt=0;
  if (depth<(LFSR_[wh]&4095)) bt=1;
  bt=bt^gate[wh].trigger;
  return bt;
}

static inline uint32_t probbitsxortoggle(uint32_t depth, uint8_t wh){   // PROBability mode xor strobe - can be more ops
  static uint32_t bt=0;
  if (gate[wh].trigger) bt=bt^1;
  if (depth<(LFSR_[wh]&4095)) bt^=1; // variations
  return bt;
}


// but depth could also be param to advance x or shift on
static inline uint32_t succbits(uint32_t depth, uint8_t wh){   // no use of depth - we route from each sr in turn
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x=0;
  if (x==wh) x++;
  if (x>3) x=0;
  bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - keep as option - see indie version
  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  bt^=bitrr;
  x++;
  return bt;
}

static inline uint32_t succbitsI(uint32_t depth, uint8_t wh){   // no use of depth - we route from each sr in turn - independent version
  // include itself or not
  uint32_t bt=0, bitrr;
  static uint8_t x[4]={0};
  if (x[wh]==wh) x[wh]++;
  if (x[wh]>3) x[wh]=0;
  bitrr = (gate[x[wh]].Gshift_[0]>>SRlength[x[wh]]) & 0x01; // if we have multiple same routes they always shift on same one - keep as option - see indie version
  //  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  bt^=bitrr;
  x[wh]++;
  return bt;
}

static inline uint32_t binroutebits(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t singleroutebits(uint32_t depth, uint8_t wh){  // just route from 0-3 single route
  uint32_t bt=0, bitrr;
  depth=depth>>10; // 12 bits to 2 bits
    // deal with no route

  bitrr = (gate[depth].Gshare_>>SRlength[depth]) & 0x01; 
  gate[depth].Gshare_=(gate[depth].Gshare_<<1)+bitrr;
  bt=bitrr;
  
  return bt;
}

static inline uint32_t binrouteINVbits(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    gate[8].Gshare_=(gate[8].Gshare_<<1)+bitrr;
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  bt=!bt;
  return bt;
}

static inline uint32_t binroutebits_noshift_transit(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now - no shift of GSR<<
  uint32_t btt=0,bt=0, bitrr;
  static uint8_t lastone;
  depth=depth>>8; // 12 bits to 4 bits
  // deal with no route
   if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  if (lastone!=bt) btt=1; // it was a transition 0-1 1-0
  lastone=bt;
  return btt;
}

static inline uint32_t binroutebits_noshift(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now - no shift of GSR<<
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  // deal with no route
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01; 
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t binroutebitscycle(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  depth=depth|wh; // adds itself
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binroutebitscyclestr(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  if (gate[wh].trigger) depth=depth|wh; // adds itself on strobe
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binroutebitscycle_noshift(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  depth=depth|wh; // adds itself
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binroutebitscyclestr_noshift(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
    // deal with no route
  if (gate[wh].trigger) depth=depth|wh; // adds itself on strobe
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binrouteORbits(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt|=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binrouteANDbits(uint32_t depth, uint8_t wh){   // depth as routesel... shared bits now
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01; 
    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt&=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binrouteSRbits(uint32_t depth, uint8_t wh){   // depth as routesel... SR itself, no GSR 
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
    //    gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

// depth can be length or param
static inline uint32_t returnbits(uint32_t depth, uint8_t wh){   // returning but we need ref to itself SR//, and its length/ as depth - starts to look like adc_ functions now
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  //  bt=(*SR>>depth)& 0x01; // but return should be of ghost...   bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		
  bt = (gate[wh].Gshift_[wh]>>depth) & 0x01;		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

//inverted
static inline uint32_t returnnotbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0;
  depth=depth>>7; // 5 bits
  //  bt=(*SR>>depth)& 0x01; // but return should be of ghost...   bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		
  bt = !((gate[wh].Gshift_[wh]>>depth) & 0x01);		// or   bt = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;				
  return bt;
}

//abstract: oscbits, osc1bits-also questions of static patterns, TM bits, onebits, ENbits, Ensbits
// could also have fixed one set of oscbits eg. osceqbits
// what else.... more on static patterns from dac or adc

// non-independent ones
static inline uint32_t osceqbits(uint32_t depth, uint8_t wh){  // so all share
  uint32_t bt;
  static int32_t n=0,nn=0;
     if (n>depth) {
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

static inline uint32_t oscbits(uint32_t depth, uint32_t depthh){ // 2 params so can't fit 
  uint32_t bt;
  static int32_t n=0,nn=0;
     if (n>depth) {
       bt=0;
       if (nn>=depthh) { // so equal bits from 0 / length 0 = 101010
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

static inline uint32_t osc1bits(uint32_t depth, uint8_t wh){  
  uint32_t bt;
  static uint32_t lastbt,n;
  if (n>depth)  {
    lastbt^=1;
    n=0;
  }
  n++;
  bt=lastbt;
  return bt;
}

// depth is length of seq, rndd is LFSR or DAC, par is CVx - so we have 2xCV
static inline uint32_t TMbits(uint32_t depth, uint32_t seq, uint32_t rndd, uint32_t par){  // for TM in TM, return inv or loop bits
  uint32_t bt;
  bt=(seq>>depth)&0x01;
  if (par>rndd) bt=!bt;
  return bt;
}

// we already have EN version
//WIARD versions - macro versions - inside themselves
//WIARD: noise/comp selects new input or loop back/inverted loop back (jumper)

//WIARD
static inline uint32_t wiardbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh]|binary[wh];
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
  }
  return bt;
}

static inline uint32_t wiardinvbits(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh]|binary[wh];
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01);
  }
  return bt;
}

static inline uint32_t TMsimplebits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;				
  if (depth>(LFSR_[wh]&4095)) bt=!bt;
  return bt;
}

static inline uint32_t onebits(uint32_t depth, uint8_t wh){ // depth=0 resets --> ??? use strobe
  uint32_t bt;
  static int32_t bc=31;
  //  static uint32_t k;
  if (gate[wh].trigger) depth=0;  
  if (bc<0) {
    bt=0;
    if (depth>0) bc=depth;
  }
  else{
  bt = 1; // this means that MSB comes out first
  }
  bc--;
  return bt;
}

//EN: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)
static inline uint32_t ENbits(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 

  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  prob=7-prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

// trying for a simpler version
static inline uint32_t ENsbits(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  if ((LFSR_[wh]&4095)>prob) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t ENsroutedbits(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  if ((gate[inroute[count][wh]].Gshift_[wh]&4095)<prob) bt=(gate[inroute[count][wh]].Gshift_[wh]>>SRlength[inroute[count][wh]])&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t compbits(uint32_t depth, uint8_t wh){ // what happens when is called successively?
  uint32_t bt;
  uint32_t k;
  ADCgeneric;
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdacbits(uint32_t depth, uint8_t wh){ // runs out in loop
  uint32_t bt;
  uint32_t k;
  //  ADCgeneric;
  k=(gate[defdac].dac); // we fix on dac[3] 
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdaccbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  uint32_t k;
  ADCgeneric;
  if (k>(gate[defdac].dac)) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t pattern4bits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    k=gate[defdac].shift_&15;
  }
  if (nn>3){ // or count down
    nn=0;
  }
  bt=k>>nn;
  n++; nn++;
  return bt;
}

static inline uint32_t patternadcbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    ADCgeneric;
    k=k>>8;
  }
  if (nn>3){ // or count down
    nn=0;
  }
  bt=k>>nn;
  n++; nn++;
  return bt;
}


static inline uint32_t pattern8bits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k,n,nn;
  //grab 4 bits pattern every depth
  if (n>depth){
    n=0;
    k=gate[defdac].shift_&255;
  }
  if (nn>7){ // or count down
    nn=0;
  }
  bt=k>>nn;
  n++; nn++;
  return bt;
}

static inline uint32_t lfsrbits(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
    bt = ((ADCshift_[wh] >> (lfsr_taps[depth][0])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][1])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][2])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][3]))) & 1u;
    ADCshift_[wh]=(ADCshift_[wh]<<1)+bt;
    if (ADCshift_[wh]==0) ADCshift_[wh]=0xff;
    return bt;
}

static inline uint32_t llfsrbits(uint32_t depth, uint8_t wh){ // no depth
  uint32_t bt;
  static uint32_t k;
  // out from lfsr at full speed
  bt=(LFSR_[wh]>>31)&0x01;
  return bt;
}


static inline uint32_t flipbits(uint32_t depth, uint8_t wh){  
  uint32_t bt;
  static uint32_t lastbt,n;
  depth=depth>>4; // 8 bits say
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01; // returnbits				
  if (n>depth)  {
    bt=!bt;
    n=0;
  }
  n++;
  return bt;
}

// to compare with these...
//uint32_t (*spdmodes[16])(uint32_t depth, uint8_t wh)={speedfrac, speedfrac, strobebits, binroutebits, binroutebits_noshift, binroutebits_noshift_transit, strobeint, probbits, TMsimplebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, compbits, compdacbits}; // just to test // second speedfrac is no interpol


uint32_t (*abstractbitstreams[16])(uint32_t depth, uint8_t wh)={binroutebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, TMsimplebits, compbits, compdacbits, compdaccbits, pattern4bits, pattern8bits, patternadcbits, lfsrbits, llfsrbits, flipbits};

uint32_t (*altabstractbitstreams[16])(uint32_t depth, uint8_t wh)={TMsimplebits, probbits, binroutebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, compbits, compdacbits, compdaccbits, pattern4bits, pattern8bits, patternadcbits, succbits, flipbits};

uint32_t (*abstractbitstreamslong[32])(uint32_t depth, uint8_t wh)={binroutebits, binroutebitscycle, binrouteSRbits, binrouteANDbits, binrouteORbits, returnbits, returnnotbits, probbits, probbitsxorstrobe, probbitsxortoggle, succbits, wiardbits, wiardinvbits, osceqbits, osc1bits, onebits, ENbits, ENsbits, ENsroutedbits, TMsimplebits, compbits, compdacbits, compdaccbits, pattern4bits, pattern8bits, patternadcbits, lfsrbits, llfsrbits, flipbits, strobebits, togglebits, cipherbits}; 

/////////////////////////////////////////// INDEPENDENT ones

static inline uint32_t binroutebitsI(uint32_t depth, uint8_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshift_[wh]>>SRlength[8]) & 0x01; 
    gate[8].Gshift_[wh]=(gate[8].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t binroutebitsI_noshift(uint32_t depth, uint8_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  if (depth==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshift_[wh]>>SRlength[8]) & 0x01; 
    bt^=bitrr;
  } else
    {
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  depth=depth>>1;
  }
    }
  return bt;
}

static inline uint32_t binroutebitscycleI_noshift(uint32_t depth, uint8_t wh){   // depth as routesel...
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  depth=depth|wh; // add itself in
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t binroutebitscyclestrI(uint32_t depth, uint8_t wh){   // depth as routesel... cycle added on strobe!
  uint32_t bt=0, bitrr;
  depth=depth>>8; // 12 bits to 4 bits
  //  depth=depth|wh; // add itself in
  if (gate[wh].trigger) depth=depth|wh; // adds itself
  for (uint8_t x=0;x<4;x++){
  if (depth&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  depth=depth>>1;
  }
  return bt;
}

static inline uint32_t osceqbitsI(uint32_t depth, uint8_t wh){   
  uint32_t bt;
  static int32_t n[4]={0};
  static int32_t nn[4]={0};
     if (n[wh]>depth) {
       bt=0;
       if (nn[wh]>=depth) { // so equal bits from 0 / length 0 = 101010
	 n[wh]=0;
       }
       nn[wh]++;
     } // n     
     else {
       bt=1;
       n[wh]++;
       nn[wh]=0;
     }         
     return bt;
}

static inline uint32_t osc1bitsI(uint32_t depth, uint8_t wh){  
  uint32_t bt;
  static uint32_t lastbt[4]={0};
  static uint32_t n[4]={0};
  if (n[wh]>depth)  {
    lastbt[wh]^=1;
    n[wh]=0;
  }
  n[wh]++;
  bt=lastbt[wh];
  return bt;
}

static inline uint32_t TMsimplebitsI(uint32_t depth, uint8_t wh){
  uint32_t bt,k;
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;				
  //  ADCgeneric;
  if (depth>(LFSR_[wh]&4095)) bt=!bt;
  return bt;
}

static inline uint32_t wiardbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh]|binary[wh];
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; // if we have multiple same routes they always shift on same one - ind version
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;
  }
  return bt;
}

static inline uint32_t wiardinvbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bitrr, tmp;
  if (depth>(LFSR_[wh]&4095)){
  for (uint8_t x=0;x<4;x++){
    tmp=binroute[count][wh]|binary[wh];
  if (tmp&0x01){
    bitrr = (gate[x].Gshift_[wh]>>SRlength[x]) & 0x01; 
    gate[x].Gshift_[wh]=(gate[x].Gshift_[wh]<<1)+bitrr;
    bt^=bitrr;
  }
  tmp=tmp>>1;
  }
  }
  else {
    bt = !((gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01);
  }
  return bt;
}

static inline uint32_t onebitsI(uint32_t depth, uint8_t wh){ // depth=0 resets
  uint32_t bt;
  static int32_t bc[4]={31};
  //  static uint32_t k;
  if (gate[wh].trigger) depth=0;  
  if (bc[wh]<0) {
    bt=0;
    if (depth>0) bc[wh]=depth;
  }
  else{
  bt = 1; // this means that MSB comes out first
  }
  bc[wh]--;
  return bt;
}

//EN: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)
static inline uint32_t ENbitsI(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  // 1 3 6 10 15 18 20 22 but we have wider bits - 1,3,6,14,17,19,21,23
  // if all as switches are 1... 

  //      prob=prob>>9; // was 8 bits - well there are only 8 switches which is 3 bits +0 9 options
  prob=7-prub[prob>>9]; // prob is 5 bits - we want 3. prub is 3 bits
    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

// trying for a simpler version
static inline uint32_t ENsbitsI(uint32_t prob, uint8_t wh){ 
  uint32_t bt, tmp;
  if ((LFSR_[wh]&4095)>prob) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
    //    if ( ( ( ((LFSR_[wh]&1)>>0) + ((LFSR_[wh]&4)>>1) + ((LFSR_[wh]&32)>>3) + ((LFSR_[wh]&16384)>>11) + ((LFSR_[wh]&131072)>>13) + ((LFSR_[wh]&524288)>>14) + ((LFSR_[wh]&2097152)>>15) + ((LFSR_[wh]&8388608)>>16)) | prob)==255) bt=(LFSR_[wh]>>24)&0x01; // in schematic is XOR of 17,22,23,24
  else   bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01;	   // cycle bit
  return bt;
}

static inline uint32_t compbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  ADCgeneric;
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdacbitsI(uint32_t depth, uint8_t wh){ // runs out in loop
  uint32_t bt;
  static uint32_t k;
  //  ADCgeneric;
  k=(gate[defdac].dac); 
  if (k>depth) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t compdaccbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  ADCgeneric;
  if (k>(gate[defdac].dac)) bt=1;
  else bt=0;
  return bt;
}

static inline uint32_t pattern4bitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  if (n[wh]>depth){
    n[wh]=0;
    k[wh]=gate[defdac].shift_&15;
  }
  if (nn[wh]>3){ // or count down
    nn[wh]=0;
  }
  bt=k[wh]>>nn[wh];
  n[wh]++; nn[wh]++;
  return bt;
}

static inline uint32_t patternadcbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  if (n[wh]>depth){
    n[wh]=0;
    //    ADCgeneric;
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); 
  ADC_SoftwareStartConv(ADC1);						
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  k[wh]=ADC_GetConversionValue(ADC1)>>8;				   
  //  k[wh]=k[wh]>>8;
  }
  if (nn[wh]>3){ // or count down
    nn[wh]=0;
  }
  bt=k[wh]>>nn[wh];
  n[wh]++; nn[wh]++;
  return bt;
}


static inline uint32_t pattern8bitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k[4],n[4],nn[4];
  //grab 4 bits pattern every depth
  if (n[wh]>depth){
    n[wh]=0;
    k[wh]=gate[defdac].shift_&255;
  }
  if (nn[wh]>7){ // or count down
    nn[wh]=0;
  }
  bt=k[wh]>>nn[wh];
  n[wh]++; nn[wh]++;
  return bt;
}

static inline uint32_t lfsrbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
    bt = ((ADCshift_[wh] >> (lfsr_taps[depth][0])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][1])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][2])) ^ (ADCshift_[wh] >> (lfsr_taps[depth][3]))) & 1u;
    ADCshift_[wh]=(ADCshift_[wh]<<1)+bt;
    if (ADCshift_[wh]==0) ADCshift_[wh]=0xff;
    return bt;
}

static inline uint32_t llfsrbitsI(uint32_t depth, uint8_t wh){
  uint32_t bt;
  static uint32_t k;
  // out from lfsr at full speed
  bt=(LFSR_[wh]>>31)&0x01;
  return bt;
}


static inline uint32_t flipbitsI(uint32_t depth, uint8_t wh){  
  uint32_t bt;
  static uint32_t n[4];
  depth=depth>>4; // 8 bits say
  bt = (gate[wh].Gshift_[wh]>>SRlength[wh]) & 0x01; // returnbits				
  if (n[wh]>depth)  {
    bt=!bt;
    n[wh]=0;
  }
  n[wh]++;
  return bt;
}

uint32_t (*abstractbitstreamsI[16])(uint32_t depth, uint8_t wh)={binroutebitsI, osceqbitsI, osc1bitsI, onebitsI, ENbitsI, ENsbitsI, TMsimplebitsI, compbitsI, compdacbitsI, compdaccbitsI, pattern4bitsI, pattern8bitsI, patternadcbitsI, lfsrbitsI, llfsrbitsI, flipbitsI};


