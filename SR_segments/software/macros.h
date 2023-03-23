#define SETROUTETYPECV {				\
  gate[w].matrix[16]=CVL[w];			\
  gate[w].routetype=CVL[w]>>9;			\
  }

#define TRIGGER (!(*clkins[w] & clkinpins[w]))

#define RESETTN {				\
  for (uint32_t y=0;y<22;y++){			\
  gate[0].matrix[y]=matrixNN[y];					\
  gate[0].matrixX[y]=matrixNN[y];					\
  gate[0].offset[y]=0;							\
}						\
  gate[w].routetype=gate[w].matrix[16]>>9;		\
}

#define RESETTL {				\
  for (uint32_t y=0;y<22;y++){			\
  gate[1].matrix[y]=matrixLL[y];					\
  gate[1].matrixX[y]=matrixLL[y];					\
  gate[1].offset[y]=0;							\
  }						\
  gate[w].routetype=gate[w].matrix[16]>>9;		\
}


#define RESETTC {				\
  for (uint32_t y=0;y<22;y++){			\
  gate[2].matrix[y]=matrixCC[y];					\
  gate[2].matrixX[y]=matrixCC[y];					\
  gate[2].offset[y]=0;							\
  }									\
  gate[w].routetype=gate[w].matrix[16]>>9;		\
  }

#define RESETTR {				\
  for (uint32_t y=0;y<22;y++){			\
  gate[3].matrix[y]=matrixRR[y];					\
  gate[3].matrixX[y]=matrixRR[y];					\
  gate[3].offset[y]=0;							\
}						\
  gate[w].routetype=gate[w].matrix[16]>>9;		\
}

#define RESETN binary[0]=0; gate[0].altroute=0; gate[0].funcbit=routebits_nodepth_typesz; gate[0].extent=6; gate[0].depths=depth_routebits_nodepth_typesz; gate[0].str_funcbit=routebits_nostrobe_depth_typesz; gate[0].str_extent=7; gate[0].str_depths=depth_routebits_nostrobe_depth_typesz; RESETTN;

#define RESETL binary[1]=0; gate[1].altroute=0; gate[1].funcbit=routebits_nodepth_typesz; gate[1].extent=6; gate[1].depths=depth_routebits_nodepth_typesz; gate[1].str_funcbit=routebits_nostrobe_depth_typesz; gate[1].str_extent=7; gate[1].str_depths=depth_routebits_nostrobe_depth_typesz; RESETTL;

#define RESETC binary[2]=0; gate[2].altroute=0; gate[2].funcbit=routebits_nodepth_typesz; gate[2].extent=6; gate[2].depths=depth_routebits_nodepth_typesz; gate[2].str_funcbit=routebits_nostrobe_depth_typesz; gate[2].str_extent=7; gate[2].str_depths=depth_routebits_nostrobe_depth_typesz; RESETTC;

#define RESETR binary[3]=0; gate[3].altroute=0; gate[3].funcbit=routebits_nodepth_typesz; gate[3].extent=6; gate[3].depths=depth_routebits_nodepth_typesz; gate[3].str_funcbit=routebits_nostrobe_depth_typesz; gate[3].str_extent=7; gate[3].str_depths=depth_routebits_nostrobe_depth_typesz; RESETTR; RESETG; count=0;

#define RESETG ordercount=0; daccount=0; spdcount=0; tailcount=0; binary[0]=0; binary[1]=0; binary[2]=0; binary[3]=0; 

#define STR0 (gate[w].trigger)

#define CYCl ((gate[w].Gshift_[w]>>SRlength[w])& 0x01)

#define DACFROM (gate[dacfrom[daccount][w]].dac)

#define SRFROM (gate[dacfrom[daccount][w]].Gshift_[w])

#define RETURN bitn^=(gate[w].Gshift_[w]>>SRlength[w])& 0x01

#define SHFT     gate[w].shift_=gate[w].shift_<<1;

////////

#define ADCgeneric {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k=ADC_GetConversionValue(ADC1);					\
  k=4095-k;								\
  ADCin=k;								\
  }

#define ADCgen {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  ADCin=ADC_GetConversionValue(ADC1);					\
  ADCin=4095-ADCin;								\
  }

#define ADCgenericsin {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  k=ADC_GetConversionValue(ADC1);					\
  k=4095-k;								\
  }

#define MIXin {								\
    ADCgenericsin;								\
    float mult=mixer[in>>2];						\
    float pp=((float)(k) *  (mult)) + ((float)(gate[dacIN[daccount][w]].dac)*(1.0f-mult)); \
    k=(int)pp;								\
    if (k>4095) k=4095;							\
    ADCin=k;								\
}

#define ADCgeneric2 {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); \
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  ADCin=ADC_GetConversionValue(ADC1);					\
  }

// we cannot place this inside other macros! fixed 12/1/2021
// HEADN for modesN

#define HEADNADA float alpha; int32_t tmp; uint32_t bitn=0, bitrr, val, x, xx, lengthbit=15, new_stat; \

#define HEADNADAT int32_t tmp; uint32_t bitn=0, bitrr, val, x, xx; \

#define GSHIFT_ {				\
    gate[w].reset[0]=1; gate[w].reset[1]=1; gate[w].reset[2]=1; gate[w].reset[3]=1; \
    gate[w].Gshift_[0]=gate[w].shift_;					\
    gate[w].Gshift_[1]=gate[w].shift_;			\
    gate[w].Gshift_[2]=gate[w].shift_;			\
    gate[w].Gshift_[3]=gate[w].shift_;			\
    gate[w].Gshift_[4]=gate[w].shift_;			\
    gate[w].Gshare_=gate[w].shift_;			\
    Gshift__[w]=gate[w].shift_&4095;			\
    gate[w].shift_=gate[w].shift_<<1;			\
}

#define GSHIFTNOS_ {				\
    gate[w].reset[0]=1; gate[w].reset[1]=1; gate[w].reset[2]=1; gate[w].reset[3]=1; \
    gate[w].Gshift_[0]=gate[w].shift_;			\
    gate[w].Gshift_[1]=gate[w].shift_;			\
    gate[w].Gshift_[2]=gate[w].shift_;			\
    gate[w].Gshift_[3]=gate[w].shift_;			\
    gate[w].Gshift_[4]=gate[w].shift_;			\
    gate[w].Gshare_=gate[w].shift_;			\
    Gshift_[w]=gate[w].shift_&4095;			\
}

#define BINROUTEalt_ {				\
    tmp=binroute[count][w]|binary[w];		\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
  if (gate[x].reset[w]){			\
  gate[x].reset[w]=0;				\
  gate[x].gsrcnt[w]=SRlength[x];		\
  }								\
    bitrr = (gate[x].Gshift_[w]>>gate[x].gsrcnt[w]) & 0x01;	\
    gate[x].gsrcnt[w]--;					\
    if (gate[x].gsrcnt[w]<0) gate[x].gsrcnt[w]=SRlength[x];	\
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
  gate[x].gsrcnt[w]=SRlength[x];		\
  }								\
    bitrr = (gate[x].Gshift_[w]>>gate[x].gsrcnt[w]) & 0x01;	\
    gate[x].gsrcnt[w]--;					\
    if (gate[x].gsrcnt[w]<0) gate[x].gsrcnt[w]=SRlength[x];	\
    bitn^=bitrr;						\
  }								\
  tmp=tmp>>1;							\
  }								\
  }

#define BINROUTEaltstrips_ {				\
  if (gate[x].reset[w]){			\
  gate[x].reset[w]=0;				\
  gate[x].gsrcnt[w]=SRlength[x];		\
  }								\
    bitn = (gate[x].Gshift_[w]>>gate[x].gsrcnt[w]) & 0x01;	\
    gate[x].gsrcnt[w]--;					\
    if (gate[x].gsrcnt[w]<0) gate[x].gsrcnt[w]=SRlength[x];	\
  }

#define BINROUTEnoalt_ {				\
    tmp=binroute[count][w]|binary[w];			\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
    bitrr = (gate[x].Gshift_[w]>>gate[x].gsrcnt[w]) & 0x01;	\
    gate[x].gsrcnt[w]--;					\
    if (gate[x].gsrcnt[w]<0) gate[x].gsrcnt[w]=SRlength[x];	\
    bitn^=bitrr;						\
  }								\
  tmp=tmp>>1;							\
  }								\
  }

#define BINROUTEnoaltstrip_ {				\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
    bitrr = (gate[x].Gshift_[w]>>gate[x].gsrcnt[w]) & 0x01;	\
    gate[x].gsrcnt[w]--;					\
    if (gate[x].gsrcnt[w]<0) gate[x].gsrcnt[w]=SRlength[x];	\
    bitn^=bitrr;						\
  }								\
  tmp=tmp>>1;							\
  }								\
  }

#define BINROUTEnoaltstrips_ {				\
    bitn = (gate[x].Gshift_[w]>>gate[x].gsrcnt[w]) & 0x01;	\
    gate[x].gsrcnt[w]--;					\
    if (gate[x].gsrcnt[w]<0) gate[x].gsrcnt[w]=SRlength[x];	\
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

// new one
#define BINROUTECYC_ {			\
    tmp=binroute[count][w]|binary[w];		\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
  if (gate[x].reset[w]){				\
  bitrr = (gate[x].shift_>>SRlength[x]) & 0x01;		\
  gate[x].reset[w]=0;					\
  }							\
  else {						\
    bitrr=((gate[w].Gshift_[w]>>SRlength[w])& 0x01);						\
  }							\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
}

#define BINROUTECYCstrip_ {			\
  for (x=0;x<4;x++){				\
  if (tmp&0x01){				\
  if (gate[x].reset[w]){				\
  bitrr = (gate[x].shift_>>SRlength[x]) & 0x01;		\
  gate[x].reset[w]=0;					\
  }							\
  else {						\
    bitrr=((gate[w].Gshift_[w]>>SRlength[w])& 0x01);						\
  }							\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
}

#define BINROUTECYCstrips_ {			\
  if (gate[x].reset[w]){				\
  bitn = (gate[x].shift_>>SRlength[x]) & 0x01;		\
  gate[x].reset[w]=0;					\
  }							\
  else {						\
    bitn=((gate[w].Gshift_[w]>>SRlength[w])& 0x01);						\
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

#define BINROUTEZEROstrips_ {			\
  if (gate[x].reset[w]){				\
  bitn = (gate[x].shift_>>SRlength[x]) & 0x01;		\
  gate[x].reset[w]=0;					\
  }							\
  else bitn=0;						\
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

#define BINROUTEstrips_ {				\
  bitn = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitn;		\
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

#define BINROUTESRstrips_ {				\
  bitn = (gate[x].shift_>>SRlength[x]) & 0x01;		\
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
  }

#define BINROUTESHAREstrips_ {				\
  bitn = (gate[x].Gshare_>>SRlength[x]) & 0x01;		\
  gate[x].Gshare_=(gate[x].Gshare_<<1)+bitn;		\
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
  }

#define BINROUTENOGstrip_ {				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;							\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTENOGstrips_ {				\
  bitn = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
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
// added pulsout macro to simplify 30/5/2022
// fixed clkin strobe 2/3/2023
#define BITN_AND_OUTV_ {						\
    PULSIN_XOR;								\
    gate[w].flip^=1;							\
    gate[w].shift_+=bitn;						\
    gate[w].lastest=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].matrix[13]>>7, gate[w].matrix[14], gate[w].trigger); \
    if (val>4095) val=4095;						\
    PULSOUT;								\
}

// strobed version so we don't need check - same as above now we removed strobe but no harm
#define BITN_AND_OUTVS_ {						\
    PULSIN_XOR;								\
    gate[w].flip^=1;							\
    gate[w].shift_+=bitn;						\
    gate[w].lastest=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].matrix[13]>>7, gate[w].matrix[14], gate[w].trigger); \
    if (val>4095) val=4095;						\
    PULSOUT;								\
}

// for MatrixX
#define BITN_AND_OUTVX_ {						\
    PULSIN_XOR;								\
    gate[w].flip^=1;							\
    gate[w].shift_+=bitn;						\
    gate[w].lastest=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].matrixX[13]>>7, gate[w].matrixX[14], gate[w].trigger); \
    if (val>4095) val=4095;						\
    PULSOUT;								\
}

// same now as above
#define BITN_AND_OUTVXS_ {						\
    PULSIN_XOR;								\
    gate[w].flip^=1;							\
    gate[w].shift_+=bitn;						\
    gate[w].lastest=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].matrixX[13]>>7, gate[w].matrixX[14], gate[w].trigger); \
    if (val>4095) val=4095;						\
    PULSOUT;								\
}

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

// reverse 32 bits for tmpp - but how to reverse based on length - reverse lowest srlength bits ?
#define REV32 {				\
  tmpp = ((tmpp >> 1) & 0x55555555) | ((tmpp & 0x55555555) << 1);	\
  tmpp = ((tmpp >> 2) & 0x33333333) | ((tmpp & 0x33333333) << 2);	\
  tmpp = ((tmpp >> 4) & 0x0F0F0F0F) | ((tmpp & 0x0F0F0F0F) << 4);	\
  tmpp = ((tmpp >> 8) & 0x00FF00FF) | ((tmpp & 0x00FF00FF) << 8);	\
  tmpp = ( tmpp >> 16             ) | ( tmpp               << 16);	\
  }

