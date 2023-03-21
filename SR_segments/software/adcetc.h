extern void send_command(int command, void *message);
char buffx[24];


static inline uint32_t countbits(uint32_t i)
{
  /*
  i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
  i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
  return (i * 0x01010101) >> 24;          // horizontal sum of bytes
  */
     return( countbts[i&0xFFFF] + countbts[i>>16] );
}

static inline uint32_t adcpadbits(uint32_t depth){ // TODO: eg. what happens if used consecutively... we have that in stream...  // how we could share same bits?
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
  bc--;
  return bt;
}

static inline uint16_t leaks(uint16_t x, uint16_t y, uint16_t prob, uint16_t who){ // try lazy, stickyt, leaky, decaying logic here... // who is new 20/9 for which SR we take logic from...
  //  static uint16_t timer=0;
  //  uint16_t z;
  // p as probability or time
  // keep track of how many times this is called (for each register/bit position) and flipit

  // or we can track bits recording their position for a certain lifespan
  // one bit per SR is tracked and lost... so would be leakNSR for example for that bit
  
  // but that is too deterministic... but if we share timers or if timer is across different speeds
  //  prob=1;
  // leaky XOR to test
  if (prob>31) prob=31;
  
  if (x^y==0) return 0;
  //  shift_registerR=(shift_registerR<<1)+z; // we are shifting left << so bit 31 is out last one
  if ((gate[who].shift_&masky[prob])==0) return 1;
  //  else if (rand()%prob==0) return 1;
  return 0;
  
  /*  timer++;
  if (timer>p){
    timer=0;
    d^=1;
    }*/
}

static inline uint16_t otherleaks(uint16_t x, uint16_t y, uint16_t prob, uint16_t who){
  if (prob>31) prob=31;
  
  if (x^y==0) return 0;
  if ((LFSR_[who]&masky[prob])==0) return 1;
  return 0;
}

// logop: 2 bits logopx: 2 bits, logopxxx operates on many bits 

//bitr=logop(bitr,bitrr,logopp[w]); // or other op TODO
// logop: 0-XOR, 1-OR, 2-&, 3leaks - 0,1,2,3
// this one can return just bitn 
static inline uint16_t logopx(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  // 
   if (type==3)  return (bita ^ bitaa);
   //  else if (type==1) return (bita | bitaa);
   else if (type==1) return (otherleaks(bita, bitaa,3,3));
  else if (type==0) return bita;
  else if (type==2) {return (bita ^ !bitaa);
    //    ty=otherleaks(bita, bitaa,3,3); // how to change this?
    //    return ty; // leaks using RSR as random // where we get 8 from...
  }
  return bita ^ bitaa; // default
}

static inline uint16_t logopxx(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  // 
  if (type==3)  return (bita | bitaa);
   //  else if (type==1) return (bita | bitaa);
   else if (type==1) return (bita & bitaa);
  else if (type==0) return (bita ^ bitaa);
  else if (type==2) {return (bita ^ !bitaa); //inv
    //    ty=otherleaks(bita, bitaa,3,3); // how to change this?
    //    return ty; // leaks using RSR as random // where we get 8 from...
  }
  return bita ^ bitaa; // default
}


//bitr=logop(bitr,bitrr,logopp[w]); // or other op TODO
// logop: 0-XOR, 1-OR, 2-&, 3leaks - 0,1,2,3
static inline uint16_t logop(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  if (type==0)  return (bita ^ bitaa);
  else if (type==1) return (bita);
  else if (type==2) return (bita ^ (!bitaa)); // same as inverted XOR
  else if (type==3) {
    ty=leaks(bita, bitaa,3,3);
    return ty; // leaks using RSR as random 
  }
  return bita ^ bitaa; // default
}

static inline uint16_t logopxxx(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
   if (type==3)  return (bita ^ bitaa);
   else if (type==1) return (bita | bitaa);
   else if (type==0) return ~(bita)&255; // 8 bits
  else if (type==2) {return (bita & bitaa);
    //    ty=otherleaks(bita, bitaa,3,3); // how to change this?
    //    return ty; // leaks using RSR as random // where we get 8 from...
  }
  return bita ^ bitaa; // default
}

uint32_t dacstrobe[32]={1,1,1,1, 1,0,0,1, 1,1,1,0, 1,1,1,1, 1,0,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1}; //if dac doesn't use strobe=1!? // checked 2/3

// 15/12/2022 - length changed to otherpar except where we change both - to be TESTED!!
//     val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].matrix[13]>>7, gate[w].matrix[14], gate[w].fake); 
static inline uint32_t DAC_(uint32_t wh, uint32_t shift, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t strobe){  // DAC is 12 bits
  uint32_t x=0;
  float f=0.0f;
  static uint32_t n[4]={0,0,0,0};
  static float SmoothData[4]={0.0, 0.0, 0.0, 0.0};
  static uint32_t lastout[4]={0,0,0,0};
  static uint32_t toggle[4]={0,0,0,0};
  static uint32_t mask[4]={0,0,0,0};

  float betaf=0.4f, mult,pp;
  int32_t rem;
  uint32_t y,tmp;
  
  switch(type){
    
  case 0: // length doesn't change much except at slow speeds - ADC x bits out - modded for new draft
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (otherpar==3){
      if ((shift&4)==4) x=4095; // changed 28/12
      else x=0;
    }
    else  x=( (shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar]; // doublecheck - fixed problem in shifts in resources 16/8
    break;
    
  case 1:// equivalent bit DAC for x bits - 3/11 - 32 bits max now
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=countbits(shift& masky[otherpar]); // lower length bits only
    y=divy[otherpar]; // added table for this 7/10 - updated for 32 bits
    x*=y;
    break;

  case 2: // as 0 but alt left shift
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (otherpar==3){
      if ((shift&4)==4) x=4095; // changed 28/12
      else x=0;
    }
    else  x=( (shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshiftalt[otherpar]; // doublecheck - fixed problem in shifts in resources 16/8
    break;

    
  case 3: // one bit audio but with beta as param  - sigma-delta
    // beta is now (6/12/2021) always param - just if is generated from cv or speed or ... betaf=0.4f is usual value
    // 0.4=par/4096.0
    //    if (otherpar>4096) otherpar=4096;
    otherpar=4096-otherpar;
    //    if (otherpar==0) otherpar=1;
    betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
    //    betaf=0.025;
    y=(shift >>length)&1;
    //    if (y==1) f=1.0f;
    //    else f=-1.0f;
    if (y==1) x=4095;
    else x=0;
    SmoothData[wh] = SmoothData[wh] - (betaf * (SmoothData[wh] - ((float)(x)))); //
    //    lastx[wh]=x;
    //SmoothData[wh]=f;
    //    f=(SmoothData[wh]*2048.0f)+2048.0f;
    //x=(int)f;
    x=(int)SmoothData[wh];
    break;

  case 4: //spacers
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x = (shift&0xFF)<<4; // just the lower 8 bits - no spacings
    if (otherpar>7){ // real length >8
      x = ((shift & 0x01) + ((shift>>pos[otherpar][1])&0x02) + ((shift>>pos[otherpar][2])&0x04) + ((shift>>pos[otherpar][3])&0x08) + ((shift>>pos[otherpar][4])&0x10) + ((shift>>pos[otherpar][5])&0x20) + ((shift>>pos[otherpar][6])&0x40) + ((shift>>pos[otherpar][7])&0x80))<<4;
      //       {0, 0, 1, 3, 6, 10, 15, 21} // for 32 bits = length=31 - check sense of this
    }
    break;

  case 5: // only output standard DAC on param->strobe/clock! so just maintain lastout S
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (strobe) {
      x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar];
      lastout[wh]=x;
    }
    else x=lastout[wh];
    break;

  case 6: // toggle to hold/release DAC
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (strobe) toggle[wh]^=1;
    if (toggle[wh]) {
      x=lastout[wh];
    }
    else {
      x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar];
      lastout[wh]=x;
    }      
    break;
    
  case 7: // 4 spaced bits out! equiv bits or not - in this case not
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x= ( ( (shift& (1<<lastspac[otherpar][0]))>>lastspacbac[otherpar][0]) + ((shift& (1<<lastspac[otherpar][1]))>>lastspacbac[otherpar][1]) + ((shift& (1<<lastspac[otherpar][2]))>>lastspacbac[otherpar][2]) + ((shift& (1<<lastspac[otherpar][3]))>>lastspacbac[otherpar][3]) )<<8; // 4 bits to 12 bits
    break;

  case 8: // 4 spaced bits out! equiv bits
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x= ( ((shift& (1<<lastspac[otherpar][0]))>>lastspacbac[otherpar][0]) + ((shift& (1<<lastspac[otherpar][1]))>>lastspacbac[otherpar][1]) + ((shift& (1<<lastspac[otherpar][2]))>>lastspacbac[otherpar][2]) + ((shift& (1<<lastspac[otherpar][3]))>>lastspacbac[otherpar][3]) ); 
    x=countbits(x)*1023;
    break;

  case 9: // one SR is sieved out over another? as DAC option. XOR as sieve? AND as mask! TODO
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar]; 
    x=x^(((gate[sieve[wh]].shift_ & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar]); // seived through previous SR
    break;

  case 10: // alt above
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar]; 
    x=x^(((gate[sieve[wh]].shift_ & masky[otherpar])>>(rightshift[otherpar]))<<leftshiftalt[otherpar]); // seived through previous SR
    break;

  case 11: //  one SR is sieved out over clksr for that sr. XOR as sieve?  - SKIPPED/retry instead of 11
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar]; 
    x=x^((clksr_[wh] & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar]; 
    break;

  case 12:// standard bit DAC for x bits     ///bitx length as other param rather than length:
    // but then we don't really use len? unless is cycle back
    // try now 21/12/2021 using length
    // bit length can also be CV - how to put this in as DAC is quite fixed in macro?
    otherpar=otherpar>>7; //5 bits
    rem=length-otherpar;
    if (rem<0) rem=0;
    x=((shift & masky[rem])>>(rightshift[rem]))<<leftshift[rem]; 
      break;

      // sequential DACs
  case 13: // we wait for length bits then output that many bits from the top of the SR (len bit) 
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;      
      x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar];
      lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 14: // alt we wait for length bits then output that many bits from the top of the SR (len bit)
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;      
      x=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshiftalt[otherpar];
      lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;
        
  case 15: // we wait for otherparam bits then output that many bits from the top of the SR (len bit)
    //    length=3; // is good to vary length AND otherpar AND speed - Cint12 does this
    // can also be x number of equiv bits TRY!
    otherpar=otherpar>>7; //5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;
      x=((shift & masky[length])>>(rightshift[length]))<<leftshift[length];
      lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 16:// par is mask on standard bit DAC for x bits
    //    if (wh<4 && length>3 && length<32) 
    // why (length)? to get down to 1 bit so could also have option for full bits!
    x=((shift & masky[length])>>(rightshift[length]))<<leftshift[length];
    x=x|(otherpar&4095);
      break;

  case 17:/// we record mask and use this to mask the regular DAC... - could also be other-than-standard DACs
    if (strobe) // we record the mask  S
	{
	  mask[wh]=Gshift__[otherpar>>10]; // or reg can be otherpar/SR
	  }
    x=((shift & masky[length])>>(rightshift[length]))<<leftshift[length];
    x=x|mask[wh];
    break;

  case 18:// standard bit DAC for x bits - new mode here
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;
    if (otherpar==3){
      if ((shift &4)==4) lastout[wh]=4095;
      else lastout[wh]=0;
    }
    else lastout[wh]=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshift[otherpar]; // we want 12 bits but is not really audible difference //Q of least bits
    }
    n[wh]++;
    x=lastout[wh];
    break;

  case 19:// alt standard bit DAC for x bits - new mode here
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) {
      n[wh]=0;
    if (otherpar==3){
      if ((shift &4)==4) lastout[wh]=4095;
      else lastout[wh]=0;
    }
    else lastout[wh]=((shift & masky[otherpar])>>(rightshift[otherpar]))<<leftshiftalt[otherpar]; // we want 12 bits but is not really audible difference //Q of least bits
    }
    n[wh]++;
    x=lastout[wh];
    break;
    
  case 20: // 22/3/2022 sliding bits.moving window - we have depth/length and where it is, wrap or not, shift or not
    // use detached length for length, and otherpar&31 for where it is, try no wrap
    // note: SRlength_[wh] or treat as full length/yes
    if (length>11) length=11;
    otherpar=otherpar>>7; //5 bits
    // topbits
    x=(shift&(masky[length]<<otherpar)); 
    // bottom bits
    tmp=(otherpar+length);
    if (tmp>31){
      tmp=tmp-31;
      y=shift&masky[tmp]; 
      x=x&4095;
      x=x>>(otherpar-tmp);
      tmp=11-(tmp);
      y=y<<tmp;
      x=x+y;
    }
    else { // working 
      tmp=11-(length);
      x=x>>otherpar;
      x=x<<tmp;
          }
    break;

  case 21: // fixed 12 bits in 2s complement back to our encoding - but we have no use for length - except perhaps // no length no otherpar
    // try delay
    // here is fixed length
    otherpar=otherpar>>7;
    if (n[wh]>otherpar) {
      n[wh]=0;      
      x=shift&masky[11]; // 12 bits
      if (x&(1<<11)) {
      x = x | ~((1 << 12)-1);
    }
    x=x+2048;
    lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 22: // fixed 12 bits in 2s complement back to our encoding - but we have no use for length - except perhaps
    // try delay
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) { // this could also be otherpar
      n[wh]=0;      
      x=shift&masky[11]; // 12 bits
      if (x&(1<<11)) {
      x = x | ~((1 << 12)-1);
    }
    lastout[wh]=x+2048;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 23: //  2s complement back to our encoding 
    // variable bits out
    // try delay or no delay
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) { // this could also be otherpar // either or...
      n[wh]=0;      
      x=shift&masky[otherpar]; // x bits
      if (x&(1<<otherpar)) {
	x = x | ~((1 << (otherpar+1))-1);
    }
      x=x+(1<<otherpar);
      // shift back to 12 bits...
      lastout[wh]=((x&masky[otherpar])>>rightshift[otherpar])<<leftshift[otherpar]; 
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 24: // fixed 12 bits in ONES complement back to our encoding - but we have no use for length - except perhaps
    // try delay
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) { // this could also be otherpar
      n[wh]=0;      
      x=shift&masky[11]; // 12 bits

      if (x&(1<<11)) {
	x=(~x);
	x&=masky[11];
	lastout[wh]=2048-x;
      }
      else lastout[wh]=x+2048;
    }
    x=lastout[wh]; // all above 2048
    n[wh]++;              
    break;

  case 25: //  ONEs complement back to our encoding 
    // variable bits out
    // try delay or no delay
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    if (n[wh]>otherpar) { // this could also be otherpar // either or... - but how do we get length AND otherpar // except detach speed...
      n[wh]=0;      
      x=shift&masky[otherpar]; // x bits
      if (x&(1<<otherpar)) {
	x=~x;
	x&=masky[otherpar];
	x=(1<<otherpar)-x;
    }
      else  x=x+(1<<otherpar);
      // shift back to 12 bits...
      lastout[wh]=((x&masky[otherpar])>>rightshift[otherpar])<<leftshift[otherpar]; 
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 26: //2s comp back in one go
    otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
    x=((shift>>rightshift[otherpar])<<leftshift[otherpar])&masky[11];
      if (x&(1<<11)) {
      x = x | ~((1 << 12)-1);
    }
    x=x+2048;
    break;

  case 27: // regular 12 bits in one go
      otherpar=lookuplenall[otherpar>>7]; // 12->5 bits
      x=((shift>>rightshift[otherpar])<<leftshift[otherpar])&masky[11];
    break;

  case 28: // mix own basic dac and dacfrom
    if (length==3){
      if ((shift&4)==4) x=4095; // changed 28/12
      else x=0;
    }
    else     x=( (shift & masky[length])>>(rightshift[length]))<<leftshift[length]; // doublecheck
    otherpar=4095-otherpar;
    mult=mixer[otherpar>>2]; // 10 bits - 0 is 1.0f so full dac
    pp=((float)(x) *  (1.0f-mult)) + ((float)(gate[dacfrom[daccount][wh]].dac)*mult); // mix with param
    x=(int)pp;
    break;
    
  case 29: // done
    otherpar=(otherpar>>6); //6 bits
    if (n[wh]>otherpar) {
      n[wh]=0;      
      x=((shift & masky[length])>>(rightshift[length]))<<leftshift[length];
      lastout[wh]=x;
    }
    x=lastout[wh];
    n[wh]++;              
    break;

  case 30: // straight 4 bit dac // no otherpar
    x=( (shift & masky[3])>>(rightshift[3]))<<leftshift[3];
    break;   

  case 31: // default for all other DACs - modded for new draft // no otherpar
    x=shift&4095;
    break;

    
    ///////
  } // switch    
  return x;
}



///////////////////////////////////////////////////////////////////////// 

#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 1000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void EXTI4_IRQHandler(void){ // working NSR 
  uint32_t tmp, tmpp;
  if (EXTI_GetITStatus(EXTI_Line4) != RESET) { // PC4
  intflag[0]=1; //NSR
  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
    
  if (EXTI_GetITStatus(EXTI_Line5) != RESET) { //RSR  PC5
    intflag[3]=1; //RSR
    EXTI_ClearITPendingBit(EXTI_Line5);
 }

  if (EXTI_GetITStatus(EXTI_Line6) != RESET) { //LSR PB6
    intflag[1]=1; //LSR
    EXTI_ClearITPendingBit(EXTI_Line6);
 } 

  if (EXTI_GetITStatus(EXTI_Line7) != RESET) {// CSR moved to PB7
    intflag[2]=1; //CSR
    EXTI_ClearITPendingBit(EXTI_Line7);
 } 
}

void TIM4_IRQHandler(void) 

{
  uint32_t temp;
  static uint32_t modecnt=0;
  //  volatile static uint16_t tmp;
  static uint32_t flipperr=0;
  
  TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 

  /*  
      tmp^=1;
      if (tmp) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
      else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */

  // map ADCs:

    // 0: nspd, 1: nlen, 2: nmode
    // 3: lspd, 4: llen, 5: lmode
    // 6: rspd, 7: rlen, 8: rmode // adc6 fixed hw
    // 9: cspd, 10: clen, 11: cmode

  // modes are NOT inverted!
  // maybe we can slow down modes
    modecnt++; 
    if (modecnt>256){ // 128: what is the speed of this? 2/1 measured as 10 Hz (so 20x second ok) 256 say
    /* // flipper is on fake clock for CC
    flipperr^=1;
    if (flipperr) GPIOB->BSRRH=clk_route_new[2]; // we get from tail
     else GPIOB->BSRRL=clk_route_new[2];
    */
      modecnt=0;
      
  //moden
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(temp+lastlastmoden+lastmoden)/3; 
  //  lastlastmoden=lastmoden;
  //  lastmoden=temp;
  mode[0]=mapping[temp>>2];
  if (lastmode[0]!=mode[0]) {
    gate[0].changed=1;
    gate[0].modes[gate[0].xx]=mode[0];
    gate[0].xx++;
    if (gate[0].xx>63) gate[0].xx=0;       
  }
  else gate[0].changed=0;
  lastmode[0]=mode[0];

   //  if (gate[0].changed){
  //  itoa(mode[0], buffx, 10);
  //  buffx[sizeof(buffx)+1]=" ";
  //  uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char)+1};
  //  send_command(0x05/* some interrupt ID */, m);
  //  }
  
  // modec
  ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(temp+lastlastmodec+lastmodec)/3; 
  //  lastlastmodec=lastmodec;
  //  lastmodec=temp;
  mode[2]=mapping[temp>>2];

  if (lastmode[2]!=mode[2]) {
    gate[2].changed=1;
    gate[2].modes[gate[2].xx]=mode[2];
    gate[2].xx++;
    if (gate[2].xx>63) gate[2].xx=0;       
  }
  else gate[2].changed=0;
  lastmode[2]=mode[2];

  // model
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(temp+lastlastmodel+lastmodel)/3; 
  //  lastlastmodel=lastmodel;
  //  lastmodel=temp;
  //  mode[1]=temp>>6;
  mode[1]=mapping[temp>>2];

  if (lastmode[1]!=mode[1]) {
    gate[1].changed=1;
    gate[1].modes[gate[1].xx]=mode[1];
    gate[1].xx++;
    if (gate[1].xx>63) gate[1].xx=0;       
  }
  else gate[1].changed=0;
  lastmode[1]=mode[1];

  // moder we dont record
  ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  //  temp=(temp+lastlastmoder+lastmoder)/3; 
  //  lastlastmoder=lastmoder;
  //  lastmoder=temp;
  mode[3]=mapping[temp>>2];

  if (lastmode[3]!=mode[3]) gate[3].changed=1; // bug fixed 28/1/
  else gate[3].changed=0;
  lastmode[3]=mode[3];
    }
  
  // speedn
  totn=totn-smoothn[nn];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothn[nn]=ADC_GetConversionValue(ADC1);
  totn+=smoothn[nn];
  nn++;
  if (nn>=SMOOTHINGS) nn=0;
  temp=totn/SMOOTHINGS;  
  CV[0]=4095-temp;

  // speedl
  totl=totl-smoothl[ll];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothl[ll]=ADC_GetConversionValue(ADC1);
  totl+=smoothl[ll];
  ll++;
  if (ll>=SMOOTHINGS) ll=0;
  temp=totl/SMOOTHINGS;
  CV[1]=4095-temp;
  
  // speedr
  totr=totr-smoothr[rr];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothr[rr]=ADC_GetConversionValue(ADC1);
  totr+=smoothr[rr];
  rr++;
  if (rr>=SMOOTHINGS) rr=0;
  temp=totr/SMOOTHINGS;  
  CV[3]=4095-temp;
    // speedc
  totc=totc-smoothc[cc];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_144Cycles); // was 10
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
   smoothc[cc]=ADC_GetConversionValue(ADC1);
    totc+=smoothc[cc];
    cc++;
    if (cc>=SMOOTHINGS) cc=0;
    temp=totc/SMOOTHINGS;
    CV[2]=4095-temp;

  
  // CVL0 NN
  totnn=totnn-smoothnn[nnn];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothnn[nnn]=ADC_GetConversionValue(ADC1);
  totnn+=smoothnn[nnn];
  nnn++;
  if (nnn>=SMOOTHINGS) nnn=0;
  temp=totnn/SMOOTHINGS;  
  CVL[0]=4095-temp;

  
  // CVL1 LL
  totll=totll-smoothll[lll];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothll[lll]=ADC_GetConversionValue(ADC1);
  totll+=smoothll[lll];
  lll++;
  if (lll>=SMOOTHINGS) lll=0;
  temp=totll/SMOOTHINGS;  
  CVL[1]=4095-temp;

  // CVL2 CC
  totcc=totcc-smoothcc[ccc];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  temp=ADC_GetConversionValue(ADC1);
  smoothcc[ccc]=ADC_GetConversionValue(ADC1);
  totcc+=smoothcc[ccc];
  ccc++;
  if (ccc>=SMOOTHINGS) ccc=0;
  temp=totcc/SMOOTHINGS;  
  CVL[2]=4095-temp;
  
  // CVL3 RR
  totrr=totrr-smoothrr[rrr];
  ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  smoothrr[rrr]=ADC_GetConversionValue(ADC1);
  totrr+=smoothrr[rrr];
  rrr++;
  if (rrr>=SMOOTHINGS) rrr=0;
  temp=totrr/SMOOTHINGS;  
  CVL[3]=4095-temp;

}
