uint8_t dacmodes[16]={25,26,27,71,72,73,74,75,  77,78,79,80,86,88,91,105};

/*

For rungler modes - collect here and permute (python)

runglers:

adc/gen     adc/gen  - routein or not (from z/zz) // type of binroute
x           y
spdfrom z   spdfrom z 
         |
         z - cycling or not - spdfrom x, routefrom y and vice versa - OUT?
         |
         zz - processor routed from z,x or y // type of binroute - speed of? independent/from [] - this should be OUT so re-think

routing options:

x and y speedfrom z, z speedfrom x or y

table:

we should have it so that R is z

N, L are x and y - they need somehow to agree on this
R is z
C is zz as this should be out now!

spdroute: 

N- spdfrom C routefrom - optional z/zz - type of gen/adc
L-         C           - optional z/zz - type of gen/adc
C-         NorL        - NorL-dep on spdfrom/cycle? - type of dac
R-         CV/C,NorL?  - C,NorL/ - type of processor/tail

routing is really for 3: constraint: 2 share/have spdrom other one, other has speedfrom one/datafromother

spdfrom is single value but if we use just bits we can have multiple routes - bit versions with advanced routing

*again rungler model:*

x y head
\ / 
 z body
 |
zz tail R

x: genX, spdfrom z + offset // optional route in from zz
y: genX, spdfrom z + own offset // optional route in from zz
z: route in from x, spd from y + own offset // optional route in from zz- OUT?, it cycles
zz: tail. process of z and feedback to x, y or z.

translate into own setup:

x: N - spdfromC+CV offset, gen-CVL(param?), route in or not from R? (1 bit)  
y: L - spdfromC+CV offset, gen-CVL(param?), route in or not from R? (1 bit)  
z: C - spdfromL+CV offset, route in from x, route in or not from R? (1 bit)  
zz: R - tail/processor: CVL

+ extra tail

how we have routing in version already here?

xy is LR, z is N (uses ADC as mod for spd), C is daclrung0 - just choose route in from these and dacout/type

SR\Rrung0: L/R speed from N, OSC
SR\Rrungs: some same/just changes in speed - add new speed mod thing:

DONE:try with CV as -+ offset

make table for routings/speedfrom here... 

q of generators with cv for select and cv for param

new +/- for speed:

tmpp=(CV[w]>>2)-512; // so from -512 to 512 - same as we have already
cv=(gate[speedfrom[spdcount][w]].dac>>2) + tmpp;  

types of speedmod: %mod/range and offset = 2x CV for that one otherwise...

bit driven rungler - speedfrom bits
independent runglers - double themselves - 2 heads

*/

// for head/permutations but this is not very flexible:

// adc/gen // routein or not from z/zz // is type important
// speedfrom- N, L or C - to match/table?

//uint32_t rung[4]={

void SRrunghead0N(uint8_t w){ // for N
  HEADNADA; // we can also have own type of dac but only for speed one N
  tmp=CVL[w]>>8;// 4 bits for DACtype - excess bits
  gate[w].dactype=tmp; gate[w].dacpar=param[w];
 
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)-(gate[3].dac>>2);// fixed as R=3
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    bitn=adc4bits_unshare(11,w); // from exp
    // routein from R or not? yes try
    //    tmp=4; // route now from C -> 4
    //    BINROUTEstrip_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRrunghead0L(uint8_t w){ // for L 
  HEADNADA; 
  // use CVL for prob
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)-(gate[3].dac>>2);// fixed as R=3
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
        bitn=adc4bits_unshare(11,w); // from exp
    // routein from R or not? yes try
    //    tmp=4; // route now from C -> 4
	if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round?
	  tmp=4;
        BINROUTEstrip_;
	}
    BITN_AND_OUTV_;
    ENDER;
  }
}

//N, L are x and y - they need somehow to agree on this
//R is z
//C is zz as this should be out now! route from R=8 - could also be process like delay here. dactype here...
void SRrungout(uint8_t w){ // 
  HEADSIN;
  CVOPEN; // CVOPENNOINTERPOL
  if(gate[w].last_time<gate[w].int_time)      {
    tmp=CVL[w]>>8;// 4 bits for DACtype - excess bits
    gate[w].dactype=tmp; gate[w].dacpar=param[w];
    
  GSHIFT_;
  tmp=8; // route from R which is body
  BINROUTEstrip_; 
  BITN_AND_OUTV_;
  ENDER;
  }
}

// better if we take dac from one down so speed is not so plain...
// so R would be body now
void SRrungbody0(uint8_t w){ // body on R 
  HEADSIN;
  float speedf__;
  int32_t off;
  tmp=(gate[0].dac)%CV[w]; // speed from N
  //  off=(CV[w]-2048);
  //  tmp+=off;
  //  if (tmp<0) tmp=0;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;

  speedf__=logspeedd[tmp];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=10; // route from left and cycle we are 8=r
    BINROUTEstrip_; 
    BITN_AND_OUTV_;
    ENDER;
  }
}

// C is now route in to out


//////////////////// previous

// from modeN.h

//SRN: speed from SRR, data from SRL - new route XOR with loopback: rung - body!
void adcLrung0(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL
  HEADNADA;
  float speedf__;
  int32_t off;

  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); // this is the ADC?
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  tmp=(gate[3].dac)%(ADC_GetConversionValue(ADC1)); // ADC for mod - speedfrom R
  off=(2048-CV[w]); // CV for offset
  tmp+=off; // off is -2048 to 2048
  if (tmp<0) tmp=0;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeedd[tmp];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=CVL[w]>>8; // CVL for dacmode
    bitn=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,1, param[w], &gate[w].shift_);  // from leftDAC - was 2
    //    tmp=2; // route from left
    //    BINROUTEstrip_; // did have this but try now with:
    JUSTCYCLE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcLrung1(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL
  HEADSSIN;
  float speedf__;
  int32_t off;

  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  tmp=(gate[3].dac)%(ADC_GetConversionValue(ADC1));
  off=(2048-CV[w]);
  tmp+=off;
  if (tmp<0) tmp=0;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeedd[tmp];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=CVL[w]>>8;
    bitn^=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,1, param[w], &gate[w].shift_);  // from leftDAC
    BINROUTE_; // did have this but try now with:
    //    JUSTCYCLE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// one variation would be just route in SRL as dataTODO, and use CVL for modulus in dacspeed
// then can use ADC bit in
void adcLrung2(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL
  HEADSSIN;
  float speedf__;
  //  uint8_t whic=(CV[w]>>9)&3; //12 bits -> 2 bits
  int32_t off;

  tmp=(gate[1].dac)%(CVL[w]); // now speed from L and data from C as that is usual route
  off=(2048-CV[w]);
  tmp+=off;
  if (tmp<0) tmp=0;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeed[tmp];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,1, param[w], &gate[w].shift_);  // adc in or not
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// no DETACH. speed is from left side...
// what are all variations of rung! for each side
void adcrung0(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL
  HEAD;
  float speedf__;
  int32_t off;

  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  tmp=(gate[1].dac)%(ADC_GetConversionValue(ADC1));
  off=(2048-CV[w]);
  tmp+=off;
  if (tmp<0) tmp=0;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeed[tmp];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //    tmp=CVL[w]>>8;
    //    bitn^=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,1, param[w], &gate[w].shift_);  // from leftDAC
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// from  model:

//SRL, SRR: speed from SRN: (both run OSC with no binroute)
// variations of the: all above for different speed ops, different oscillators (but some need params), use CVL to select speed ops and osc

void SRrung0(uint8_t w){// with oscillator - speedminus we use here
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)-(gate[0].dac>>2);// fixed as gate[0]
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRrung1(uint8_t w){// with oscillator - other minus
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2)); // other minus
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRrung2(uint8_t w){// with oscillator - mod
  HEAD;
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeed[(gate[0].dac>>2)%cv]; // mod
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRrung3(uint8_t w){// with oscillator - add
  HEAD;
  int32_t cv;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[0].dac>>3)]; // add
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// 2bits speed ops, how many oscs we have...

  /* what are speed ops? 

  speedf__=logspeed[(gate[0].dac>>2)%cv]; // mod
  cv=(CV[w]>>2)-(gate[0].dac>>2);  speedf__ = logspeed[cv] // minus
  speedf__=logspeed[(CV[w]&511)+(gate[0].dac>>3)]; // add
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2)); // other minus
*/

// oscs: 21adcandsharedbitsotherpar, 29otherpar, 28strobe, 30osc, 31tm, 34osc/otherpar, 77oscdac, 78oscdac, 79oscdac, 80oscdac, 89impulses/strobe/otherpar, 95otherpar/patterns, 107osc1bits +3: 19.adcpadbits, 18adcbits, 22lfsr
uint8_t oscmode[16]={107,21,29,28, 30,31,34,77,  78,79,80,89, 95,19,18,22};

void SRLrung0(uint8_t w){// DETACHED> with oscillator
  HEADSIN;
  int32_t cv;
  float speedf__;
  //  cv=(CV[w]>>2)-(gate[0].dac>>2);
  //  if (cv<0) cv=0;
  // 2 bits speed ops...
  tmp=CVL[w]>>6; //2+4 bits = 6 bits
  // top bits
  if (tmp&16){
    cv=((CV[w]>>2)+1); // modulo code
    speedf__=logspeed[(gate[0].dac>>2)%cv]; // mod
  }
  else if (tmp&32){
  cv=(CV[w]>>2)-(gate[0].dac>>2);
  if (cv<0) cv=0;
  speedf__ = logspeed[cv]; // minus
  }
  else if (tmp&48){
  speedf__=logspeed[(CV[w]&511)+(gate[0].dac>>3)]; // add
  }
  else {
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2)); // other minus
  if (cv<0) cv=0;
  speedf__ = logspeed[cv]; 
  }

  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=tmp>>2;
    bitn=ADC_(w,SRlength[w],oscmode[tmp],gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// from moder.h - check if is same as above

//SRL, SRR: speed from SRN: (both run OSC with no binroute) - is as RB0 above
void SRRrung0(uint8_t w){// with oscillator
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2));
  if (cv<0) cv=0;
  speedf__=logspeedd[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRrung1(uint8_t w){// with oscillator - other minus - but is same as above
  HEAD;
  int32_t cv;
  float speedf__;
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2)); // other minus
  if (cv<0) cv=0;
  speedf__=logspeedd[cv];
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRrung2(uint8_t w){// with oscillator - mod
  HEAD;
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeedd[(gate[0].dac>>2)%cv]; // mod
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(1,SRlength[w],30,gate[w].trigger,dacfrom[daccount][1],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void SRRrung3(uint8_t w){// with oscillator - add
  HEAD;
  int32_t cv;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[0].dac>>3)]; // add
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}


void SRRLrung0(uint8_t w){// DETACHED> with oscillator
  HEADSIN;
  int32_t cv;
  float speedf__;
  //  cv=(CV[1]>>2)-(gate[0].dac>>2);
  //  if (cv<0) cv=0;
  // 2 bits speed ops...
  tmp=CVL[w]>>6; //2+4 bits = 6 bits
  // top bits
  if (tmp&16){
    cv=((CV[w]>>2)+1); // modulo code
    speedf__=logspeed[(gate[0].dac>>2)%cv]; // mod
  }
  else if (tmp&32){
  cv=(CV[w]>>2)-(gate[0].dac>>2);
  if (cv<0) cv=0;
  speedf__ = logspeed[cv]; // minus
  }
  else if (tmp&48){
  speedf__=logspeed[(CV[w]&511)+(gate[0].dac>>3)]; // add
  }
  else {
  cv=(gate[0].dac>>2)-(1024-(CV[w]>>2)); // other minus
  if (cv<0) cv=0;
  speedf__ = logspeed[cv]; 
  }

  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=tmp>>2;
    bitn=ADC_(w,SRlength[w],oscmode[tmp],gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    //    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// from modec.h

//SRC: output from oscs or from SRN - select our input - route from...
// we want to use CVL to select which one we route from and type of dac?
// general purpose: what are variations?
void dacLrung0(uint8_t w){ // detached length
  HEADSIN;
  tmp=CVL[w]>>6;// 2 bits for route, 4 bits for DACtype = 6 bits
  gate[w].dactype=tmp>>2; gate[w].dacpar=param[w];
  if (w==2 || speedf_[w]!=2.0f){ // remove!
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  //  tmp=myroute[w][gate[w].route]; // route from N, L, or R = 3 options +itself = 0,1,2,3
  tmp=tmp&0x03; // 2 bits
  bitrr = (gate[tmp].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[tmp].Gshift_[w]=(gate[tmp].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;

  BITN_AND_OUTV_; // with pulses
  ENDER;
  }
  }  
}

