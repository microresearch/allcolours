// for new struct sets of modes:

/*
static uint32_t dactypecnt=0;
static uint32_t spdfunccnt=0;
static uint32_t lengthfunccnt=0;
static uint32_t adcfunccnt=0;
static uint32_t bitfunccnt=0;
static uint32_t extfunccnt=0;
static uint32_t outfunccnt=0;
static uint32_t gscnt=0;
static uint32_t outcnt=0;
*/

#define RESETR count=0; daccount=0; spdcount=0; binroutetypecount=0; binary[0]=0; binary[1]=0; binary[2]=0; binary[3]=0;

#define STR0 (gate[w].trigger)

#define CYCl ((gate[w].Gshift_[w]>>SRlength[w])& 0x01)

#define DACFROM (gate[dacfrom[daccount][w]].dac)

#define SRFROM (gate[dacfrom[daccount][w]].Gshift_[w])

#define RETURN bitn^=(gate[w].Gshift_[w]>>SRlength[w])& 0x01

#define SHFT     gate[w].shift_=gate[w].shift_<<1;

////////

#define LASTSPEED {				\
  gate[w].lastspeed=gate[w].countspeed;		\
  gate[w].countspeed=0;				\
  }

#define CLKSR {					\
  if (intflag[w]) {				\
  gate[w].trigger=1;				\
  intflag[w]=0;					\
  clksrG_[w]=clksr_[w];				\
  clksr_[w]=(clksr_[w]<<1)+1;						\
  }									\
  else  {								\
  gate[w].trigger=0;							\
  clksr_[w]=(clksr_[w]<<1);						\
  }									\
  clksr_[w]&=4095;							\
}

#define ADCone {					\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k[reg]=ADC_GetConversionValue(ADC1)>>(11-length);			\
  }

// TEST INVERSION  - was invrted but now not
#define ADCtwo {				\
    ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k[reg]=ADC_GetConversionValue(ADC1);					\
  }

#define ADCgeneric {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k=ADC_GetConversionValue(ADC1);					\
  }

#define ADCgeneric2 {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  ADCin=ADC_GetConversionValue(ADC1);					\
  }


#define ADCgeneric11 {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k=ADC_GetConversionValue(ADC1)>>(11-depth);				\
  }

#define CVOPEN {				\
    alpha = gate[w].time_now - (float)gate[w].int_time;			\
    gate[w].dac = ((float)delay_buffer[w][1] * alpha) + ((float)delay_buffer[w][0] * (1.0f - alpha)); \
    if (gate[w].dac>4095) gate[w].dac=4095;				\
    gate[w].time_now += speedf_[w];					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }

#define CVOPENNOINTERPOL {				\
    gate[w].dac = delay_buffer[w][1];					\
    gate[w].time_now += speedf_[w];					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }
// 1 is always the new data

// this one is used for DACspeed modes and others
#define CVOPENDAC {				\
    alpha = gate[w].time_now - (float)gate[w].int_time;			\
    gate[w].dac = ((float)delay_buffer[w][1] * alpha) + ((float)delay_buffer[w][0] * (1.0f - alpha)); \
    if (gate[w].dac>4095) gate[w].dac=4095;				\
    gate[w].time_now += speedf__;					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }

#define CVOPENDACNOINTERPOL {				\
    gate[w].dac = delay_buffer[w][1];					\
    gate[w].time_now += speedf__;					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }


// we cannot place this inside other macros! fixed 12/1/2021
// HEADN for modesN

//#define HEADN float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; gate[3].dactype=66; \

#define HEAD float alpha; int32_t tmp; uint32_t bitn=0, bitrr, val, x, xx, lengthbit=15, new_stat; SRlength[w]=SRlength_[w]; speedf_[w]=speedf[w]; \

#define HEADC float alpha; int32_t tmp; uint32_t bitn=0, bitrr, val, x, xx, lengthbit=15, new_stat; SRlength[w]=lookuplenall[CVL[w]>>7]; speedf_[w]=logspeed[CV[w]>>2];

// these ones are for NO SRlength - stays as is and we can use CVL 12 bits

#define HEADSIN float alpha; int32_t tmp; uint32_t bitn=0, bitrr, val, x, xx, lengthbit=15, new_stat; speedf_[w]=speedf[w]; \

// these ones are for no speed changes

#define HEADSSIN float alpha; int32_t tmp; uint32_t bitn=0, bitrr, val, x, xx, lengthbit=15, new_stat; SRlength[w]=SRlength_[w]; \

// and for NADA both the same
#define HEADSSINNADA float alpha; int32_t tmp; uint32_t bitn=0, bitrr, val, x, xx, lengthbit=15, new_stat; \

#define HEADNADA float alpha; int32_t tmp; uint32_t bitn=0, bitrr, val, x, xx, lengthbit=15, new_stat; \

//

#define ENDER {					\
  new_data(val,w);							\
  gate[w].time_now-=1.0f;						\
  gate[w].int_time=0;							\
  }

// redefining for struct - adding in count for lastspeed
#define GSHIFT_ {				\
    gate[w].reset[0]=1; gate[w].reset[1]=1; gate[w].reset[2]=1; gate[w].reset[3]=1; \
    gate[w].Gshift_[0]=gate[w].shift_;					\
    gate[w].Gshift_[1]=gate[w].shift_;			\
    gate[w].Gshift_[2]=gate[w].shift_;			\
    gate[w].Gshift_[3]=gate[w].shift_;			\
    gate[w].Gshift_[8]=gate[w].shift_;			\
    gate[w].Gshare_=gate[w].shift_;			\
    Gshift_[w]=gate[w].shift_&4095;			\
    gate[w].shift_=gate[w].shift_<<1;			\
    gate[w].countspeed++;				\
}

#define GSHIFTNOS_ {				\
    gate[w].reset[0]=1; gate[w].reset[1]=1; gate[w].reset[2]=1; gate[w].reset[3]=1; \
    gate[w].Gshift_[0]=gate[w].shift_;			\
    gate[w].Gshift_[1]=gate[w].shift_;			\
    gate[w].Gshift_[2]=gate[w].shift_;			\
    gate[w].Gshift_[3]=gate[w].shift_;			\
    gate[w].Gshift_[8]=gate[w].shift_;			\
    gate[w].Gshare_=gate[w].shift_;			\
    Gshift_[w]=gate[w].shift_&4095;			\
    gate[w].countspeed++;				\
}

#define JUSTCYCLE_ {					\
  bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		\
  bitn^=bitrr;						\
  }

#define BINROUTEalt_ {				\
    tmp=binroute[count][w]|binary[w];		\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
  if (gate[x].reset[w]){			\
  gate[x].reset[w]=0;				\
  gate[w].gsrcnt[x]=SRlength[x];		\
  }								\
    bitrr = (gate[x].Gshift_[w]>>gate[w].gsrcnt[x]) & 0x01;	\
    gate[w].gsrcnt[x]--;					\
    if (gate[w].gsrcnt[x]<0) gate[w].gsrcnt[x]=SRlength[x];	\
    bitn^=bitrr;						\
  }								\
  tmp=tmp>>1;							\
  }								\
  }

#define BINROUTEaltstrip_ {				\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
  if (gate[x].reset[w]){			\
  gate[x].reset[w]=0;				\
  gate[w].gsrcnt[x]=SRlength[x];		\
  }								\
    bitrr = (gate[x].Gshift_[w]>>gate[w].gsrcnt[x]) & 0x01;	\
    gate[w].gsrcnt[x]--;					\
    if (gate[w].gsrcnt[x]<0) gate[w].gsrcnt[x]=SRlength[x];	\
    bitn^=bitrr;						\
  }								\
  tmp=tmp>>1;							\
  }								\
  }

// was newgsr_nores
#define BINROUTEnoalt_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
    bitrr = (gate[x].Gshift_[w]>>gate[w].gsrcnt[x]) & 0x01;	\
    gate[w].gsrcnt[x]--;					\
    if (gate[w].gsrcnt[x]<0) gate[w].gsrcnt[x]=SRlength[x];	\
    bitn^=bitrr;						\
  }								\
  tmp=tmp>>1;							\
  }								\
  }


#define BINROUTEnoaltstrip_ {				\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
    bitrr = (gate[x].Gshift_[w]>>gate[w].gsrcnt[x]) & 0x01;	\
    gate[w].gsrcnt[x]--;					\
    if (gate[w].gsrcnt[x]<0) gate[w].gsrcnt[x]=SRlength[x];	\
    bitn^=bitrr;						\
  }								\
  tmp=tmp>>1;							\
  }								\
  }


#define BINROUTEZERO_ {			\
    tmp=binroute[count][w]|binary[w];		\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
  if (gate[x].reset[w]){				\
  bitrr = (gate[x].shift_>>SRlength[x]) & 0x01;		\
  gate[x].reset[w]=0;					\
  }							\
  else bitrr=0;						\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
}

#define BINROUTEZEROstrip_ {			\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
  if (gate[x].reset[w]){				\
  bitrr = (gate[x].shift_>>SRlength[x]) & 0x01;		\
  gate[x].reset[w]=0;					\
  }							\
  else bitrr=0;						\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
}

#define BINROUTE_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }
// pulled out:   if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
// added in binary[w] for global bitroute testings

// use tmp
#define BINROUTEstrip_ {				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }
// pulled out:   if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\


// same as binroute??????
#define BINROUTENOS_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }
// was no strobey

// for local routes
#define BINROUTEMY_ {				\
  tmp=myroute[w][gate[w].route]|binary[w];	\
  for (x=0;x<4;x++){				\
    if (tmp&0x01){					\
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;	\
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;	\
      bitn^=bitrr;					\
    }							\
    tmp=tmp>>1;						\
  }							\
}

// for local routes - but stripped they are all the same...
#define BINROUTEMYstrip_ {				\
  for (x=0;x<4;x++){				\
    if (tmp&0x01){					\
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;	\
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;	\
      bitn^=bitrr;					\
    }							\
    tmp=tmp>>1;						\
  }							\
}


// same more or less as BINROUTENOG_ but not with gshift
#define BINROUTESR_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].shift_>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTESRstrip_ {				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].shift_>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }


// shared binroute/gshift - only makes sense if we share routes or if there are functions to shift on...
#define BINROUTESHARE_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;		\
  gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTESHAREstrip_ {				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;		\
  gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }


// we don't cycle incoming ghost just get bits
#define BINROUTENOG_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;							\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }

#define BINROUTENOGstrip_ {				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;							\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }

#define BINROUTEtrig_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;							\
  if (gate[x].trigger) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;	\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTEtrigstrip_ {				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;							\
  if (gate[x].trigger) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;	\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTEOR_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn=bitn|bitrr;							\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }

#define BINROUTEORstrip_ {				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn=bitn|bitrr;							\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }

#define BINROUTEANDCYCLE_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){					\
    if (tmp&0x01 || (x==w)){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
    tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }


// only advance incomings
#define BINROUTEADV_ {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[1][mode[1]]) bitn=bitn|gate[1].trigger;	\
}

#define BINROUTEANDCYCLENOG_ {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
    if (tmp&0x01 || (x==w)){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;					\
  }							\
    tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }

#define BINROUTEORNOG_ {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  bitn|=bitrr;							\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }

#define PULSOUT {							\
    if (w!=0){								\
    tmp=(w<<1);								\
    if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];				\
    else *pulsoutHI[tmp]=pulsouts[tmp];				\
    lengthbit=(SRlength[w]>>1);					\
    new_stat=(gate[w].shift_ & (1<<lengthbit))>>lengthbit;		\
    if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;		\
    prev_stat[w]=new_stat;					\
    tmp++;							\
    if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];		\
    else *pulsoutHI[tmp]=pulsouts[tmp];				\
    }								\
}

//DAC_(uint32_t wh, uint32_t shift, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t strobe){  // DAC is 12 bits
// this one is for fractional speeds/interpol
// added pulsout macro to simplify 30/5/2022
#define BITN_AND_OUTV_ {						\
    PULSIN_XOR;								\
    gate[w].flip^=1;							\
    gate[w].shift_+=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    PULSOUT;								\
}
// added pulsin_xor

#define BITN_AND_OUTVgen_ {						\
    PULSIN_XOR;								\
    gate[w].shift_+=bitn;						\
    val=(*dacfunc[gate[w].func[dactypecnt][fdac]])(*CVlist[w][gate[w].cv[gate[w].cvcnt][cvdac]], w); \
    PULSOUT;								\
}


#define BITN_AND_OUTVXOR_ {						\
    gate[w].shift_^=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    PULSOUT;								\
}

// for local changes to dactype 
#define BITN_AND_OUTVDACT_ {						\
    gate[w].shift_+=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp, gate[w].dacpar, gate[w].trigger); \
    PULSOUT;								\
  }


#define BITN_AND_OUTVNOSHIFT_ {						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    PULSOUT;								\
  }

#define BITN_AND_OUTVINT_ {						\
    PULSIN_XOR;								\
    gate[w].shift_+=bitn;						\
    gate[w].dac=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    PULSOUT;								\
}

#define BITN_AND_OUTNODAC_ {						\
    PULSOUT;								\
}

#define BITN_AND_OUTNODAC2_ {						\
    PULSIN_XOR;								\
    gate[w].shift_+=bitn;							\
    PULSOUT;								\
  }


#define BITN_AND_OUTVINTNO_ {						\
    gate[w].dac=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    PULSOUT;								\
  }

// these all had     if (w==3) count=0; 10/1/2021				\

#define PULSIN_XOR {				\
  if (pulse[w]){				\
    xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn^=xx;					\
  }						\
  }

#define PULSIN_OR {				\
  if (pulse[w]){				\
    xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn|=xx;					\
  }						\
}

// prob is upto 32 // 5 bits
#define PULSIN_LEAK {				\
  if (pulse[w]){					\
    xx=!(GPIOC->IDR & pulsins[w]);			\
    bitn=otherleaks(bitn,xx,prob,w);			\
  }							\
}

// reverse 32 bits for tmpp - but how to reverse based on length - reverse lowest srlength bits ?
#define REV32 {				\
  tmpp = ((tmpp >> 1) & 0x55555555) | ((tmpp & 0x55555555) << 1);	\
  tmpp = ((tmpp >> 2) & 0x33333333) | ((tmpp & 0x33333333) << 2);	\
  tmpp = ((tmpp >> 4) & 0x0F0F0F0F) | ((tmpp & 0x0F0F0F0F) << 4);	\
  tmpp = ((tmpp >> 8) & 0x00FF00FF) | ((tmpp & 0x00FF00FF) << 8);	\
  tmpp = ( tmpp >> 16             ) | ( tmpp               << 16);	\
  }


//for INTmodes ???
#define CVin31 (31-(adc_buffer[lookupadc[w]]>>7)); 

