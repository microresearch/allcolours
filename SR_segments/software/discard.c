// sources: adc, dac, oscillator, clock?-return last strobe, impulses(TODO) - // add in different DACs, SR bits output
// but some of these are single bits so doesn't make sense

uint32_t fadc(void){
  uint32_t k;
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_3Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  k=ADC_GetConversionValue(ADC1);
  return k;
}

uint32_t fdac(void){
  uint32_t k;
  k=gate[3].dac;
  return k;
}

uint32_t (*fff[8])(void)={fadc, fdac};

// how we can start to abstract source out - but few sources...
static inline uint32_t bits(uint32_t depth, uint8_t func){ // max 12 bits // func is index into function array
  uint32_t bt;
  static int32_t bc=31;
  static uint32_t k;
  if (depth>11) depth=11; // max depth
    if (bc<0) {
      k=(*fff[func])(); // new 12 bits but only in case of adc/dac
      k=k>>(11-depth);
	bc=depth; // was 11
  }
    bt = (k>>bc)&0x01; // this means that MSB comes out first
    bc--;
    return bt;
}


/* // why we lost this?
// Nint70 - if we can change type of gate[3].dac in dac mixes 66,67,68 or pure dac ins (?)
void Nint70(void){
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    gate[3].dactype=15-(CV[0]>>8);     // 4 bits for type
    bitn=ADC_(0,SRlength[w],67,gate[w].trigger,3,gate[3].dac, &gate[w].shift_);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
*/

/*
void NLintprob084(void){ // own dac as comparator against DAC+CV 
  // can also detach length and have this as prob mode too - prob of cycle or ADC. prob of cycle or routein
  uint8_t w=0;				       
  HEADSINN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) > CVL[0])){   // thsi way round
    bitn=ADC_(0,SRlength[w],84,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);
    }
    else JUSTCYCLE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
*/


// try N0-N7 with ADCORIN() - these all fade out


  void Nor0(void){ 
  ADCORIN(0);
  }

  void Nor1(void){ 
  ADCORIN(1);
  }

  void Nor2(void){ 
  ADCORIN(2);
  }

  void Nor3(void){ 
  ADCORIN(3);
  }

  void Nor4(void){
  ADCORIN(4);
  }

  void Nor5(void){ 
  ADCORIN(5);
  }

  void Nor6(void){
  ADCORIN(6);
  }

  void Nor7(void){
  ADCORIN(7);
  }




void Ntestorxor1_0(void){ // lower bits of CVL select xor or or in  -- version 2 below makes more sense
  // speed is temp>>7 so 5 bits 0-31 so we want ((CVL[w]&64)>>6) 
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time){
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  
  if ((CVL[w]&64)>>6) {
    BINROUTEOR_;
  }
  else {
    BINROUTE_;
    }
  BITN_AND_OUTVN_;
  ENDER;
  }
}
}

void Ntestorxor2_0(void){ // - or have 2 sets of 0-31 for length or/xor
  // detach length
  uint8_t w=0;
  HEADSINN; // detach
  SRlength[w]=31-((CVL[w]>>6)%32);
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time){
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  if (((CVL[w]>>6)&32)==1) {
    BINROUTEOR_;
  }
  else {
    BINROUTE_;
    }
  BITN_AND_OUTVN_;
  ENDER;
  }
}
}


//  if (speedf_[0]==2.0f) speedf_[0]=LOWEST;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[which].dac>>2)]);

//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  // if (speedf__<LOWEST) speedf__=LOWEST;
  //  speedf__=1.0f;


// how we can OR in for route 0 - below but doesn't work so well
#define BINROUTE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }



// test logic for minor major modes
// say 4 major modes

// but how we can split modes?
major=mode[3]>>4; // from 64=6bits to 2 bits 

if (w!=3){
switch(major){
 case 0:
   // we do all modes for all except 3
   switch(mode[w]{ // or this would be a bit interpretation and we have no switch
       case 0:
	 break;
     }
   break;
     }
 }//major
 }//w!=3
 else {
   // w==3 modes
   switch(mode[3]){// here we have 16 (x4-64) minor modes for the right side...
   case 0: 
     break;
   }
 }//w==3




//unused
#define BINROUTEOR {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn|=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTELOGOP {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn=logop(bitn,bitrr,logtable[w]);			\
  }							\
  tmp=tmp>>1;						\
  }							\
  }


#define BINROUTEANDCYCLE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
    if ((tmp&0x01) || (x==w)){				\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define JUSTCYCLE {				\
  bitrr = (shift_[w]>>SRlength[w]) & 0x01;		\
  bitn^=bitrr;						\
  }


// if we go with singular defroute
#define BITNNN {								\
  bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;	\
  Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;		\
  }

//if w==3 count=0 means just to reset binroute when we are out of modes which altered it
// macro for alt routes for ADC and DAC
// try with binrouteOR
#define ADCDACETC1(X, Y){			\
  bitn=0;					\
  GSHIFT;						\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTEOR;						\
  }							\
  if (w==2)      {					\
  dactype[2]=Y;					\
  BINROUTE;						\
  }							\
}

#define ADCDACNOGS(X, Y){			\
  bitn=0;					\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTE;						\
  }							\
  if (w==2)      {					\
    dactype[2]=Y;					\
    BINROUTE;						\
  }							\
}

// we still specify type of DAC here but we leave
//  if (w==2)      {
//  BINROUTE; // TODO: substitute alt routes here for DAC. eg cycle, probability etc. 4x4 for 16-31
//  }
//  else {

// still we have DACtype here
#define ADCONLY(X, Y){						\
    bitn=0;							\
    dactype[2]=Y;						\
    if (w==3) count=0;						\
    GSHIFT;							\
    if (w==0)							\
  {								\
      bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
      BINROUTEOR;						\
  }								\
}

//// older

#define GSHIFT {				\
  counter[w]=0;					\
  Gshift_[w][0]=shift_[w];			\
  Gshift_[w][1]=shift_[w];			\
  Gshift_[w][2]=shift_[w];			\
  Gshift_[w][3]=shift_[w];			\
  shift_[w]=shift_[w]<<1;			\
}

#define GS(X) {					\
  Gshift_[X][0]=shift_[X];			\
  Gshift_[X][1]=shift_[X];			\
  Gshift_[X][2]=shift_[X];			\
  Gshift_[X][3]=shift_[X];			\
}


#define BITN_AND_OUT {						\
    shift_[w]+=bitn;						\
    dac[w]=DAC_(w, SRlength[w], dactype[w],dacpar,trigger[w]);	\
    tmp=(w<<1);							\
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}

// this one is for fractional speeds/interpol
#define BITN_AND_OUTV {				\
    shift_[w]+=bitn;						\
    val=DAC_(w, shift_[w], SRlength[w], dactype[w],dacpar,trigger[w]);	\
    tmp=(w<<1);							\
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}



    /*
  case 0: // ADc x bits out but only 12/8/4/2/1 bits
    if (length<8){ // 1 bit
      if ((shift_[reg]&(1<<length))==(1<<length)) x=4095;
      else x=0;
    }
    else x=(shift_[reg]&masky[length])>>newr[length])<<news[length];
    break;
    */
    /*
  case 0: // testing 12 bits out
    if (n[reg]>length) { // slow...
      n[reg]=0;
      //      nom[reg]=shift_[reg]&4095;
      nom[reg]=((shift_[reg]&masky[length])>>newr[length])<<news[length];
    }
    n[reg]++;
    x=nom[reg];
    break;
    */


    //    x=rand()%4095;
     /*
    if (length==3){
      if (shift_[reg]&4) x=4095;
      else x=0;
    }
    else     x=( (shift_[reg] & masky[length])>>(rightshift[length]))<<leftshift[length];
    */




void testNint(void){ // no interpolation
  uint8_t w=0;				       
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void testN(void){ // speed template
  uint8_t w=0;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVN_; // for no pulse out
    ENDER;
  }
  }
}


case 80: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(adc_buffer[12])>>(11-length);
	n[reg]=length;
    }
      bt = ((k>>n[reg])&0x01) ^ strobe; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 81: // equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      k=(adc_buffer[12]); //
      k=k/divy[length];
      n[reg]=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    bt ^= strobe;
    n[reg]++;    
    break;

  case 82: // variations on one bit audio - also phasey
    k=(adc_buffer[12]); // from 0 to 4095 but where is the middle? - also we do nothing here with length
    integrator+=(k-oldValue);
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
   bt ^= strobe;
   break;    

  case 83: // basic sequential length as in 0 but with padding if >11 bits **
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	k=(adc_buffer[12])>>(11-length);
	n[reg]=length;
      }
      else {
	k=(adc_buffer[12]);
	n[reg]=11;
      }
    }
    bt = ((k>>n[reg])&0x01) ^ strobe;;
    n[reg]--;    
    break;
    
  case 84: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k=(adc_buffer[12]);
	n[reg]=11;
    }
    bt = ((k>>n[reg])&0x01) ^ strobe; // top bit first
    n[reg]--;    
    break;

  case 85: // padded version of SR of bitsin
      if (n[reg]>length) {
	if (length<12) ADCshift_[reg]=(adc_buffer[12])>>(11-length); 
	else ADCshift_[reg]=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    n[reg]++;
    bt=((ADCshift_[reg]>>length)&0x01) ^ strobe;;
    ADCshift_[reg]=(ADCshift_[reg]<<1)+bt;
    break;
    
    


// from adcetc

// 0-31 (32)modes +1 INTmode
// arrange modes now as most important first...

   
   /*  case 63: // =- input regardless of length - this was same as 5 but MSB 
    // also try as MSB - now...
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k=(adc_buffer[12]);
	n[reg]=11;
    }
    bt = (k>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;
   */

   /*
  case 64: // was strobe mode for cycling bits a la TM - no input but now uses ADC input as probability! - cvmode
    bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    if (((LFSR_[reg] & 4095 ) < adc_buffer[12])){
      bt=!bt;// invert cycling bit
    }
    break;
   */    


// 18/1/22 but we don't use this
// more generic ADC_ in = so income is passed in function and can be LFSR so we have different handlings
static inline int ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR, uint32_t *income){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator=0.0f, oldValue=0.0f;
  static uint32_t k, lastbt=0; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  static uint8_t toggle=0, lc=0;
  uint32_t bt=0, bit=0;
  float inb;

  switch(type){
    
  case 0: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(*income)>>(11-length);
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
  }
}


    /* // LSB first
  case 0: // basic sequential length of upto 12 bits cycling in    
      if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length);
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01; // this means that LSB comes out first
    n[reg]++;    
    break;
    */


    /*
  case 2: // one bit audio input - can also change the 48??? - this one makes wierd phase effects
    n[reg]++;
  if (n[reg]>48) {
    k=(adc_buffer[12]); 
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;
    */
        


    /*
  case 2: // try with float but this is the same with phasings
    inb=(((float)adc_buffer[12])/2048.0f)-1.0f; // from 0 to 4095 but where is the middle?
    integrator+=(inb-oldValue);
   if(integrator>0.0f)
  {
     oldValue=1.0f;
     bt=1;
  }
   else
   {
      oldValue=-1.0f;
      bt=0;
   }   
   break;    
    */     

   /*      
  case 3: // basic sequential length as in 0 but with padding if >11 bits **
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else {
	  k=(adc_buffer[12]);//<<(length-11); // should be -11 // pads with 0s at the bottom LSB first
	  //	  k+=((k>>length-11)&masky[length-11]); // pad with a repeat?
	  //	  k+=padding[length-11]; // TESTY! - padding with 1s
	}
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
   */

   /*
  case 3: // basic sequential length as in 0 but with padding if >11 bits **
    // REVERSAL again doesn't change much
      if (n[reg]<0) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else {
	  k=(adc_buffer[12])<<(length-11); // should be -11 // pads with 0s at the bottom LSB first
	  // double up
	  //  k+=((k>>length-11)&masky[length-11]); // pad with a repeat?
	  //	  k+=padding[length-11]; // TESTY! - padding with 1s - doesn't change much
	}
	n[reg]=length;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;    
    break;
   */
   /*
  case 3: // basic sequential length of upto 12 bits cycling in MSB first    
        if (n[reg]<0) {
	  //	  k=pow(2,length)+1;
	  k++;
	  if (k>4095) k=0;
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
   */
   /*  case 3: // basic sequential length of upto 12 bits cycling in MSB first    
        if (n[reg]<0) {
	  k=adc_buffer[12];
	  n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
   */   



/* options here:
1. 9 bit speed +dac ->   speedf__=logspeed[(CV[0]&511)+(gate[whic].dac>>3)];

2. speed+dac with max:
cv=(CV[0]>>2)+(gate[3].dac>>2);
if (cv>1023) cv=1023;
speedf__=logspeed[cv];

3. DAC - (1024-speed) // so if speed is 0-fastest 
cv=(gate[3].dac>>2)-(1024-(CV[0]>>2));
if (cv<0) cv=0;
speedf__=logspeed[cv];

4. speed-dac
cv=(CV[0]>>2)-(gate[3].dac>>2)-
if (cv<0) cv=0;
speedf__=logspeed[cv];


5. DAC % speed we have below
 */

//  if (speedf_[0]==2.0f) speedf_[0]=0.000990f;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[speedfrom_[0]].dac>>2)]);
//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  //  if (speedf__<0.000990f) speedf__=0.000990f;
  //  speedf__=1.0f;
  //  speedf__=logspeed[(CV[0]>>3)+(gate[3].dac>>3)];


void trial(void){
  static uint32_t xxxx=0;
  xxxx^=1;
  if (xxxx) gate[2].dac = 4095;
  else gate[2].dac=0;
    //  gate[2].dac=100;
}

void trial2(void){
  gate[0].dac=0;
}





// from main


older: fast interrupt (TIM?) for all shift registers with counters,
interrupt for ADCs (TIM?), interrupt for pulsed SR, PWM for
default/normed clockings (set by speed pot)

or just one timer for all and run at max speed with counters

- ADC input schemes - number of bits, sigma/delta, bit equality (unary - no weighting) with x bits
- 4x pin interrupts, how many timers
- working with sigma delta ADC, DAC out, digital filter simulator and list first all possible modes and ways of operating
- clock from speed/cv, clock from external pulse, clock from other
  shift register // combos of thse so could be ext pulse AND/XOR/OR
  other shift reg or clocked speed pulse etc.
- bitdsp library borrowings?
- fakes, ghosts, SR_IN_SR, overlaps
- add artificial drift and dropped bits

Sigma/delta out as pulses and as DAC (low pass?)


/////

TODO: new notes, collect all notes, modes and speed/basic tests

Questions: how we use the 5 fake pulse outs normed to pulse ins: PB10-PB15 ! 

Newest PCB (14/5/2021) with new ADC(ADC12//on pin PC3) TESTED ALL FINE

9/7/2021: ADC in and DAC tested correctly with 11vPP for 0-4095

14/7/2021 - retested allFINE: 

all ADC ins: mode, spd and len x4

  // map ADCs: note all modes are inverted

  // 0: nspd, 1: nlen, 2: nmode
  // 3: lspd, 4: llen, 5: lmode
  // 6: rspd, 7: rlen, 8: rmode
  // 9: cspd, 10: , 11: cmode

/ pulse ins: PC7 is RSRIN, PC8 is LSRIN XDONE

/ interrupt ins: LSR, RSR, CSR, NSR -DONE / PWM outX, pulse outsXDONE

CSRCLKIN moved from PC3 to PB7

///

Newest PCB: all working 19/4 but we will need to re-work ADC entry -
test now with lower cap on say ADC0 - nspeedin c30->100pf//33k, removed cap (but leave on schematic)
and increased ADC speed, changed to continuous mode and we have a high
sample rate in 100kHZ
 
16/4/2021->19/4/2021:

- what needs testing? DAC outDONE, ADCs inDONE, 

- all pulses in //(and volts knob for ADC pulsed in: PC9->PC14-REDO)DONE

- pulses outDONE

TIM1-CH1 normings WORKING - so is TIM1 normed to top clock/NSR

----> could do with organizing all a bit better with arrays

///


TESTED/WORKING: ADC all tested, DAC out tested, pulses out all tested, TIM1-CH1 norming to top clock, volts knob/primitive ADC, pulse ins, interrupt pulse ins 

/////////

// copied over from TOUCH so we need to change ADCsDONE, DAC out is the same, add timers and change interrupt timing, add external interrupts, PWMS.

TODO: list our new I/O here, check interrupts and PWM

- general scheme of things

///// OLDER

Testing on STM32F446 NUCLEO. Prog header is same as TOUCH. STM is same as touch

This was copied from TOUCH so some things will need to change: 

But we can keep DAC on PA4


fast interrupt (TIM?) for all shift registers with counters, interrupt for ADCs (TIM?), interrupt for pulsed SR, PWM for default/normed clockings (set by speed pot)

I/O:

- pulse ins: PC3-5 + PB6 clkins(interrupts), PC7/8 pulsein, PC9-MSB, to PC14-LSB of 6 bits
- ADC 0-11 see adc.c
- DAC out PA4
- TIM1-CH1 drived normed top LFSR - and we need 2 extra internal timers! 
- 11 pulse outs: PB2,3,4,10,12,13,14 = 5 fakes and 6 real out + now we have changed for schematic: PA11=pulse6, PA12=pulse4, PC15=pulse5, PB15=pulse7

apparently there are 12x 16bit and 2x 32 bit timers (TIM2, TIM5) 

 */

/// Copied 23/2/2021 from TOUCH code...

/*
void TIM2_IRQHandler(void) {
  // flash on update event
  if (TIM2->SR & TIM_SR_UIF) GPIOA->ODR ^= (1 << 5);
   
  TIM2->SR = 0x0; // reset the status register
  }*/



// from draftspeed:



  // crash detect ++ 32/64 in main.c is 14KHz //and/or speed check...
  //    flipper^=1;
  //  if (param[0]>4090){
  //    if (flipper) GPIOB->BSRRH = (1)<<12;  // clear bits PB12 - left normed clock I think
  //    else   GPIOB->BSRRL=(1)<<12; //  write bits   
  //  }

    /* // we don't deal with CLKs now!  
    //TODO: ghostSRs for normed clks (with speed of these from what, from RDAC?)
  if (w==2 && counter[2]>speed[w] && speedfrom[2]==1){ // 2 is Cspeed - but we have a problem when Cspeed is from an interrupt as this is never generated...FIXED HERE
      counter[2]=0;
      flipper^=1;
      if (flipper) GPIOB->BSRRH = clk_route[clkr];  // clear bits of fake_one - clkr is 7 so all of them
      // or we can set L and R from an independent SR with only CSR as clocked from here
      else   GPIOB->BSRRL=clk_route[clkr]; //  write bits       
    }
  */


  /*
  if (time_now[w]>32768){
      int_time[w]=0; 
      time_now[w]-=32768.0f;
    }

  // fixed interpol
      alpha = time_now[w] - (float)int_time[w];
      dac[w] = ((float)delay_buffer[w][DELAY_SIZE-5] * alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - alpha)); // interpol but is just last and before last
      if (dac[w]>4095) dac[w]=4095;
      else if (dac[w]<0) dac[w]=0;
      //      dac[w]=lastdac[w];

  time_now[w] += speedf_[w];
  last_time[w] = int_time[w];
  int_time[w] = time_now[w];

  if(last_time[w]<int_time[w])      {
    // do all
    // test as a function pointer
    //    mode[w]=testmodes[w];
    //    val=(*dofunc[mode[w]])(w); // this seems to work
    //    val=(*gate[L].dofunc[0])(w);
    
    GSHIFT;


void Rnofrac0(void){
  uint8_t w=3;
  HEAD;
  if (counter[3]>speed[3] && speed[3]!=1024){
    counter[3]=0;			       
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  }
}


void Cnofrac0(void){
  gate[2].dactype=0; gate[2].dacpar=param[2];
  uint8_t w=2;
  HEAD;
  if (counter[2]>speed[2] && speed[2]!=1024){
    counter[2]=0;				
    GSHIFT_;
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  }
}

void Lnofrac0(void){
  uint8_t w=1;
  HEAD;
  if (counter[1]>speed[1] && speed[1]!=1024){
    counter[1]=0;				
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
    }
}

void Nnofrac0(void){
  uint8_t w=0;
  HEAD;
  if (counter[0]>speed[0] && speed[0]!=1024){
    counter[0]=0;			      
    GSHIFT_;
    bitn=ADC_(0,SRlength[0],0,gate[0].trigger,3,param[0], &gate[w].shift_);    
    BITN_AND_OUTVINT_; 
  }
}



    if (w==0){
      bitn=ADC_(0,SRlength[0],0,trigger[0],reggg,adcpar); 
    }
    BINROUTE;
    if (LR[w]){
      PULSIN_XOR;
    }
    BITN_AND_OUTV; // special version for this in macros.h  
    new_data(val,w);
    //    lastdac[w]=val;
    last_time[w] += 1;
    
  } // lasttime
  */


// worm speed

if (time_now>32768){
    int_time=0; 
    time_now-=32768.0f;
    }

alpha = time_now - (float)int_time;

outt = ((float)delay_buffer[DELAY_SIZE-5] * alpha) + ((float)delay_buffer[DELAY_SIZE-6] * (1.0f - alpha)); // interpol but is just last and before last
if (outt>LIMIN) outt=LIMIN;
 else if (outt<-LIMIN) outt=-LIMIN;
out[ii]=outt;

  time_now += factor;
  last_time = int_time;
  int_time = time_now;

while(last_time<int_time)      {
    doadc();
    int16_t val=getsample();
    new_data(val);
    last_time += 1;
  }
 }
}



//    dac[2]=(adc_buffer[12]);
    /*        k=(adc_buffer[12]); // from 0 to 4095 but where is the middle?
    integrator+=(k-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=4095;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   dac[2]=bt;
    */

    //    bt = ((ADCshift_[0] >> (lfsr_taps[SRlength[0]][0])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][1])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][2])) ^ (ADCshift_[0] >> (lfsr_taps[SRlength[0]][3]))) & 1u;
      //            bt^=1;
      //          if (rand()%4) bt^=1;

      //      ADCshift_[0]=(ADCshift_[0]<<1)+(bt&1);
      //      x=(((ADCshift_[0] & masky[SRlength[2]])<<8));//<<leftshift[SRlength[2]])&4095);//>>(rightshift[length]))<<leftshift[length];
      //      dac[2]=x;//(bt*4095);




// draft for INTmodes - - TODO: probability of advance on trigger using CV as prob
case 50:
  param[w]=adc_buffer[lookupadc[w]];
  if (trigger[w] && (shift_[LFSR[w]] & 4095) > (param[w] & 4095) ){ // or this could be based on a real: shift_[3] which we try here for better effect
    dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
    ADCDACETC1(0, 0);
    if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
      PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

// draft for CV with INT - where to place this? and we can't really use CV as param here!
case 49:
    if (counter[w]>speed[w] && speed[w]!=1024){
      if (trigger[w]){
	param[w]=adc_buffer[lookupadc[w]];// ??? use another param eg.
	dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
	ADCDACETC1(0, 0);
	if (LR[w]){
	//////////////////////////////////HERE!
	BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/////////////////////////////////////...
	PULSIN_XOR;
      } 
      BITN_AND_OUT;
    }
}
break;



/// intmodes

  case 24: // len is otherpar but there is no shift - OTHERPAR! 12 bits
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    otherpar=otherpar&31; // 5 bits
      if (n[reg]>otherpar) {
	k=adc_buffer[12]; //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
    
  case 25: // len is otherpar but there is shift from otherpar  - OTHERPAR! 12 bits
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
        otherpar=otherpar&31; // 5 bits
      if (n[reg]>otherpar) {
	if (otherpar<12) k=(adc_buffer[12])>>(11-otherpar); 
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 28:// ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) { 
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;
      }
    break;

    // we use otherpar to determine number of bits - equal or otherwise  - OTHERPAR! 12 bits
     // we can also use otherpar=CV or otherwise as padding, length of bits which is not LEN!
  case 29:   // as case 17: // basic sequential length as in 0 but with padding if >11 bist
    // maybe restrict otherpar
    otherpar=otherpar&31; // 5 bits
      if (n[reg]>length) {
	if (otherpar<12) {
	  k=(adc_buffer[12])>>(11-otherpar); //
	}
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 33: //  ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) { 
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;
      }
    else
      {
	bt=(shift_[reg]>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
      }
    break;

  case 34: // prob mode for cycling bits a la TM
    bt=(shift_[reg]>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    if ((LFSR_[reg] & 4095 ) < (otherpar&4095)) {
      bt=!bt;// invert cycling bit
    }
    break;
    ////////    
    // INT MODES ONLY FROM HERE ON! but these are just copies of some modes above!
     /*
  case 60: // INT // CV as comparator - for INT modes ONLY which don't use CV! can also be CV+DAC
    // we can also compare to: DAC, CV+DAC, to clksr_, to param - feed these into otherpar or have as options
     bt=0;
         if (adc_buffer[12]>adc_buffer[lookupadc[reg]]) bt=1; // can also be otherpar to make cleaner = then is same as mode 26!
     break;

  case 61:  // was case 6 //param[reg] seq input - what is size of param? /or we can also just feed in otherpar = CV in
    otherpar=otherpar>>7; // 5 bits
      if (length>11) length=11; //XXX12 bits or 8 bits
      if (n[reg]>length) {
	k=(otherpar])>>(11-length); 
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 63: // XOR or OR of case 4 - 1 bit oscillator and input bits  - OTHERPAR! 12 bits
  if (length>11) length=11;
      if (nnn[reg]>length) {
	k=(adc_buffer[12])>>(11-length); 
      nnn[reg]=0;
    }
    bt = (k>>nnn[reg])&0x01;
    nnn[reg]++;    

    otherpar=otherpar>>4; // how long? it should be?
     if (n[reg]>length) { // 0s
       bt|=0; // XOR TODO
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt|=1; // XOR TODO
       n[reg]++;
       nn[reg]=0;
     }         
     break;    
     */


     // TODO: CV+ADC as input for some of the INT modes perhaps
     // CV can modulus ADC input




case 15: // basic sequential length of upto 12 bits cycling in - leave out of cvmodes!!
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(otherpar)>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

// discard

  case 19: // sequential clksr in TESTED! - lose this one as we have 18 - clkbits in anyways
    if (n[reg]>length) {
      k=(clksr_[reg])>>(31-length); 
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;


/// strobes

  case 17: // basic sequential length of bits cycling in but zeroed by strobe
  if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    } 
     if (strobe) bt=0;
      else bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;


case 7:     // we accumulate bits onto a ghosted register
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { // strobe
      shift_[reg]&=invmasky[length]; // clear length bits
      shift_[reg]+=(ADCGshift_[reg]&masky[length]);
    }
    break;

  case 8:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa
    if (strobe) toggle^=1;

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      if (toggle) {// strobe
      bt = (k>>n[reg])&0x01;
      lastbt=bt;
      }
      else bt=lastbt;
    n[reg]++;    
    break;
    
  case 9:     // 2-we only cycle ADC on strobe/toggle  - or vice versa
        if (strobe) toggle^=1;
    if (length>11) length=11; //XXXmax12bits

  if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;

      if (toggle) {// strobe
    n[reg]++;    
      }
      break;

  case 10: // STROBE: 3-one bit entry
    if (strobe) toggle^=1;
    n[reg]++;
  if (n[reg]>50) {
    k=(adc_buffer[12]);
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   

   if (toggle) {
	lastbt=bt;
      }
      else bt=lastbt;
   break;

     case 11:// STROBE: run LFSR-ADCshift and output a bit - REGG!
       if (strobe) toggle^=1;
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;    
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

  case 12: // STROBE for other LFSR too - REGG!
    if (strobe) toggle^=1;
    bt = ((shift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (shift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;    
    break;

  case 13: // strobe moves up next LFSR ghostL tap - REGG!
    if (strobe){
      lc+=1; // or we can make this depend on...???
      if (lc>3) lc=1; 
	  ghost_tapsL[length][lc]+=1;
	  ghost_tapsL[length][lc]%=31;
	}           
    bt = ((shift_[regg] >> (ghost_tapsL[SRlength[regg]][0])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][1])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][2])) ^ (shift_[regg] >> (ghost_tapsL[SRlength[regg]][3]))) & 1u;    
    break;

  case 21: // padded case 8    // we accumulate bits onto a ghosted register **
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); 
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { 
      shift_[reg]&=invmasky[length]; // clear length bits
      shift_[reg]+=(ADCGshift_[reg]&masky[length]);
    }
    break;

  case 22:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa **
    if (strobe) toggle^=1;
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length);
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;
      if (toggle) {
    n[reg]++;    
      }
    break;



// TESTY: testing for simultaneous shifter - but what of modes where we hold back the gshift eg. modes: 37, 48, 49
   // we need to remove all gshifts also in ADC macros
   /*   
   if (w==0){
   if (new[0]){
     new[0]=0;
     GS(0);
   }
   if (new[1]){
     new[1]=0;
     GS(1);
   }
   if (new[2]){
     new[2]=0;
     GS(2);
   }
   if (new[3]){
     new[3]=0;
     GS(3);
   }   
   }
   */

    /*
    // trial for new update plan
  case 1: // for all just pass through - ADC NONE/pass, LR pass, DAC 0/pass
    if (counter[w]>speed[w] && speed[w]!=1024){
        counter[w]=0; new[w]=1;
	shift_[w]=shift_[w]<<1;
	dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC_
	dactype[2]=0;
	ADCDACNOGS(0, 0);
	if (LR[w]){
	BINROUTE;
	PULSIN_XOR;
	}
	BITN_AND_OUT;
    }
    break;
    */


/* // basic mode to test ADC/DAC modes with equiv LR modes
 
case x:
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; par=0; // for DAC
    logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1; // logic for ops
    GSHIFT;

    if (w==0)      {
    BITNNN;
    bitn^=ADC_(w,SRlength[w],2,0); // choose mode and params - can return 0 from adc for no effect
    }
    else
    {
    BITNNN;
    }
    PULSIN_LOGOP;    
    BITN_AND_OUT;
  }// counterw
  break; 
*/


// for this macro we need  dacpar=0/whatever for DAC and adcpar is for ADC - defined outside macro
// X is adc_type, Y is dac_type
#define MULTROUTE(X, Y) {			\
  bitn=0;					\
  dactype[2]=Y;					\
  GSHIFT;						\
  if (w==0)      bitn=ADC_(0,SRlength[0],X,trigger[w],reggg,adcpar);	\
  tmp=binroute[count][w];						\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  PULSIN_XOR;						\
  BITN_AND_OUT;						\
}
//pulsin_xor above would need an if (w==1 || w==3)


// how can we abstract these out a bit so is not so many...  - for CV modes just have a few examples of each and work more with strobes

9 prob mode 0 -invcycle with dac[dacroute]
10 prob mode 1 -invcycle with param 

as above but with routed in bits too

*invcycle is more like ADC mode if is without routein*

11 prob of bitin(which?) or loopback - dac
12 prob of bitin or loopback - param  

bitins: adc-0,pulse-1,3,routein-all

pulse
routein
routein_logop_pulse 

13 inverted versions of above
14

loaded/notloaded into cycling SR
15 incoming bit = routed in 
// w==0 adc in instead of puls below (xor with 0 - mode 28 for ADC we have - XOR against loop, routed in)
16 incoming bit = pulse in (1,3)
17 incoming bit = route/
18 incoming bit = route/pulse

all x2: 2.if SR<DAC  // cv/int mode 4.if sr<CLKCNT // cv mode - we need to trim this down

   - TM: prob of bit in/inverted bit in - above (ORed with incoming bit/s: routed, ADCed, pulsed)
   - others: prob of bitin or loopback 
   - prob of bitin or inverted loopback
   [-electro: incoming bit is loaded/not loaded into cycling SR]

+++ as above but with toggles or strobes

- do we already have strobe as incoming adc or not? YES as case 17



// need to catch it but this gives us false beats
      //      if (shift_[w]==0 || shift_[w]==FULL)     shift_[w]=0x01; 

  //  cogg[w][0]=0; // if we end up using these...
  //  cogg[w][1]=0;
  //  cogg[w][2]=0;
  //  cogg[w][3]=0;

  //2-where is the input bit from (LFSR, ADC type?)- can also be from another LFSR? ADC types we have in test2.c - or no inputbit
    //    bitn=0;
      /*
    if (inputbit[w]==0){ // LFSR from SR in LFSR[w]
      bitn = ((shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][0])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][1])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][2])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][3]))) & 1u; // we would use this in final...
    }
    else if (inputbit[w]==1) {// do input from type of ADC specified
      // static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type){ // here we use length as number of bits max is 12 bits
      bitn=ADC_(w,SRlength[w],adctype[w]);
    }
    else bitn=0;
      */



// flip PB4 to test interrupt on PB7 -> CSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  // flip PB4 to test interrupt on LSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  // flip PB4 to test interrupt on  RSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   



((longer&(0b1111111111111111111111111111111100000000000000000000000000000000+othermasky[31-srlength])>>(sh-shifter))); // so this seems to work

if (coggn==0)  {// unsure of this logic
    //     shift_registerl=(shift_registerl^masky[sl])+bitn;

    tmpt=(SRlengthn-(sl-1)); // again what if sl is longer than lengthn - this is key figure
    if (tmpt<(sl-1)) tmpt=(sl-1);
    shift_registerl=((shift_registerl<<1)^masky[sl]);
	shift_registerl+=((shift_registern&(othermasky[sl-1])>>tmpt)>>tmpt);
	shift_registerl+=(bitn<<(sl-1)); // but that bit needs to be empty
	}
  // COGGN should also be x bits across!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TODO-DONE TO TEST
  else {
    // then here we want sl x bits from the top masked in
    //    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    /*    tmpt=(SRlengthn-(coggn-1))-sl;
    if (tmpt<sl) tmpt=sl;
    shift_registerl=((shift_registerl<<1)^masky[sl])+(shift_registern&othermasky[sl])>>tmpt;
    */
    //    tmpt=(SRlengthn-(sl-1)); // again what if sl is longer than lengthn - this is key figure
    tmpt=(SRlengthn-(coggn-1))-sl;
    if (tmpt<sl) tmpt=sl;
    shift_registerl=((shift_registerl<<1)^masky[sl]);
    shift_registerl+=((shift_registern&(othermasky[sl])>>tmpt)>>tmpt);
    //    shift_registerl+=(bitn<<(sl-1)); // but that bit needs to be empty
    
  }


countern++;
  if (countern>=speedn){ 
    countern=0;
    // repeat x times
    sl=moden>>2;
    tmpp=0;
    for (x=0;x<sl;x++){
      bitn = (((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u); // 32 is 31, 29, 25, 24
      tmpp+=bitn<<x;
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    }
    coggn=0;
    bitn=tmpp;
  }
//  }
  
    // test pulse ins   // inpulse interrupts to attach are: CSR: PC3, NSR: PC4, RSR: PC5, LSR: PB6
    // PC7/8 pulsein (RSR-7/LSR-8), PC9-MCB, to PC14-LSB of 6 bits
    
    // test in gives out on PB4 - always inverted...
    //    if ((GPIOC->IDR & (1<<7)))  GPIOB->BSRRH = (1)<<4;  // clear bits PB4
    //    else   GPIOB->BSRRL=(1)<<4; //  write bits   
    //  if (k==0) k=4095;
    //  else k=0;
    //  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    //  ADC_SoftwareStartConv(ADC1);


//k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!

// OLD BITS DAC STUFF!!

  //  k=4095-k;
  //  k=rand()%4095;
  //  k++;
  //  if (k>4095) k=0;
  //    k=(((GPIOC->IDR & (1<<9)))<<11) + (((GPIOC->IDR & (1<<10)))<<9) + (((GPIOC->IDR & (1<<11)))<<7) + (((GPIOC->IDR & (1<<12)))<<5) + (((GPIOC->IDR & (1<<13)))<<3) + (((GPIOC->IDR & (1<<14)))<<1) ;//  - 2048;// probably easier way to do this
  // check each one
  //  k=((!(GPIOC->IDR & (1<<14)))<<11); //14 haas issues
  //  k=(1<<11); //puts us in middle
  //      k=4095; // with
	//  k=4000; // with R35 as 150k and R34 as 66.5k we have 4095 as -4.96 and 0 as 5.6k // 180k puts us opposite (-5.6) so we need like 160k
  // we leave buffer on DAC or these values change
  //  k=rand()%4095;




  // http://www.danbullard.com/dan/A_Sigma_Delta_ADC_Simulator_in_C.pdf
  // https://www.mikrocontroller.net/topic/293454

      
  // outPUT
  //DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  // j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

  //  if(ll)      GPIOB->BSRRH = (1)<<4;  // clear bits PB4
  //  else   GPIOB->BSRRL=(1)<<4; //  write bits 
  //  ll^=1;


RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // TEST - PC8 input from 40106 for freezing/rec/play etc. power it with 3.3v

  // led first
  //  GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output

  // internal DAC PA4 with multiplex with EN_LOW1 on PC11 and sel1/2/3 on PC13/14/15


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);



  // led first
  //  GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output


  //    io_config2 ();
    //DAC_Cmd( DAC_Channel_2, ENABLE);
    //    DAC_Cmd( DAC_Channel_1, ENABLE);

    // set enable=say 13 and 14 pin (active LOW) and pins for 4051: PB8,9,10

    /* TODO: testing for external DAC such as MPC492X (one or two DACs) - test with 4922

- setup SPI on SPI2 or SPI3 (SPI1 would conflict with ADC ins)
- communicate with DAC1 and test 
    */

	    /*
	    int main(void)
{
  // this is for flashing onboard LED LD2 on pin PA5

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // enable the clock to GPIOD
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // enable TIM2 clock
     
    GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output
     
    NVIC->ISER[0] |= 1<< (TIM2_IRQn); // enable the TIM2 IRQ
     
    TIM2->PSC = 0xff; // no prescaler, timer counts up in sync with the peripheral clock
    TIM2->DIER |= TIM_DIER_UIE; // enable update interrupt
    TIM2->ARR = 0xffff; // count to 1 (autoreload value 1)
    TIM2->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // autoreload on, counter enabled
    TIM2->EGR = 1; // trigger update event to reload timer registers
      
    while (1);
}
	    */


	          // test SPI comms - what message to send a value to the DAC1!?
      // from arduino code: https://github.com/michd/Arduino-MCP492X/blob/master/MCP492X.cpp
      //      value=k;
      
      //      delay();
      // flip-flop from PC8
      //      GPIOA->ODR ^= (1 << 5);      

      /*
      
      if (GPIOC->IDR & 0x0100){ // pin 8 
      if (flipped==0) {
	flipped=1;
	prev_state=0;
      }
	}
	else flipped=0;
	  
	if (flipped==1 && prev_state==0)
	  {
	  prev_state=1;
	  GPIOA->ODR ^= (1 << 5);
	  }
      */
      
      /// multiplex and DAC tests
            
      //    GPIOB->ODR = 0b0000000100000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    // Y1 is S1 on 4051 high which is 11 on 4051 which is pin PB8
      /*      otherk++;
      if (otherk>32){
	otherk=0;
      k++;
      if (k>4095) k=0;
      }*/
      //      k=0;
      //    DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
      //    j = DAC_GetDataOutputValue (DAC_Channel_1);
    //    delay();
    //    GPIOB->ODR = 0b0000000000000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    //    DAC_SetChannel1Data(DAC_Align_12b_R, 4095-k); // 1000/4096 * 3V3 == 0V8
    //    j = DAC_GetDataOutputValue (DAC_Channel_1);
    //    delay();

	        GPIO_InitTypeDef GPIO_InitStructure;
    
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

