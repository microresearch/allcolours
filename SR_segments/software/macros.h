// for new struct sets of modes:

#define STR0 (gate[w].trigger)

#define CYCl ((gate[w].Gshift_[w]>>SRlength[w])& 0x01)

#define DACFROM (gate[dacfrom[daccount][w]].dac)

#define SRFROM (gate[dacfrom[daccount][w]].Gshift_[w])

#define RETURN (bitn^=(gate[w].Gshift_[w]>>SRlength[w])& 0x01) 

#define CVOPEN {				\
    alpha = gate[w].time_now - (float)gate[w].int_time;			\
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - alpha)); \
    if (gate[w].dac>4095) gate[w].dac=4095;				\
    else if (gate[w].dac<0) gate[w].dac=0;				\
    gate[w].time_now += speedf_[w];					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }

#define CVOPENNOINTERPOL {				\
    alpha = gate[w].time_now - (float)gate[w].int_time;			\
    gate[w].dac = delay_buffer[w][1];					\
    gate[w].time_now += speedf_[w];					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }

// this one is used for DACspeed modes and others
#define CVOPENDAC {				\
    alpha = gate[w].time_now - (float)gate[w].int_time;			\
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - alpha)); \
    if (gate[w].dac>4095) gate[w].dac=4095;				\
    else if (gate[w].dac<0) gate[w].dac=0;				\
    gate[w].time_now += speedf__;					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }

// we cannot place this inside other macros! fixed 12/1/2021
// HEADN for modesN

//#define HEADN float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; gate[3].dactype=66; \

#define HEAD float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; SRlength[w]=SRlength_[w]; speedf_[w]=speedf[w]; \

#define HEADD float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; SRlength[w]=SRlength_[w]; speedf_[w]=speedf[w]; PULSIN_XOR; \

// these ones are for NO SRlength - stays as is and we can use CVL 12 bits

#define HEADSIN float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; speedf_[w]=speedf[w]; \

#define HEADSIND float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; speedf_[w]=speedf[w]; PULSIN_XOR; \

// these ones are for no speed changes

#define HEADSSIN float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; SRlength[w]=SRlength_[w]; \

#define HEADSSIND float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; SRlength[w]=SRlength_[w]; PULSIN_XOR; \

// and for NADA
#define HEADSSINNADA float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; \
  
#define HEADSSINNADAD float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; PULSIN_XOR; \



//

#define ENDER {					\
    new_data(val,w);				\
    gate[w].time_now-=1.0f;			\
    gate[w].int_time=0;				\
  }


// redefining for struct

#define GSHIFT_ {				\
    gate[w].Gshift_[0]=gate[w].shift_;			\
    gate[w].Gshift_[1]=gate[w].shift_;			\
    gate[w].Gshift_[2]=gate[w].shift_;			\
    gate[w].Gshift_[3]=gate[w].shift_;			\
    gate[w].Gshift_[8]=gate[w].shift_;			\
    gate[w].Gshare_=gate[w].shift_;			\
    gate[w].shift_=gate[w].shift_<<1;			\
}

#define GSHIFTNOS_ {				\
    gate[w].Gshift_[0]=gate[w].shift_;			\
    gate[w].Gshift_[1]=gate[w].shift_;			\
    gate[w].Gshift_[2]=gate[w].shift_;			\
    gate[w].Gshift_[3]=gate[w].shift_;			\
    gate[w].Gshift_[8]=gate[w].shift_;			\
    gate[w].Gshare_=gate[w].shift_;			\
}


#define JUSTCYCLE_ {					\
  bitrr = (gate[w].Gshift_[w]>>SRlength[w]) & 0x01;		\
  bitn^=bitrr;						\
  }


#define BINROUTE_ {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }

// shared binroute/gshift - only makes sense if we share routes or if there are functions to shift on...
#define BINROUTESHARE_ {				\
  tmp=binroute[count][w];				\
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


#define BINROUTENOS_ {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn^=bitrr;					\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

// we don't cycle incoming ghost just get bits
#define BINROUTENOG_ {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;							\
  }							\
  tmp=tmp>>1;						\
  }							\
  if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	\
  }

#define BINROUTEOR_ {				\
  tmp=binroute[count][w];				\
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
  tmp=binroute[count][w];				\
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

//DAC_(uint32_t wh, uint32_t shift, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t strobe){  // DAC is 12 bits
// this one is for fractional speeds/interpol
#define BITN_AND_OUTV_ {						\
    gate[w].shift_+=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    tmp=(w<<1);								\
    if (w!=0){								\
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

// for local changes to dactype 
#define BITN_AND_OUTVDACT_ {						\
    gate[w].shift_+=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp, gate[w].dacpar, gate[w].trigger); \
    tmp=(w<<1);								\
    if (w!=0){								\
      if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];				\
      else *pulsoutHI[tmp]=pulsouts[tmp];				\
      lengthbit=(SRlength[w]>>1);					\
      new_stat=(gate[w].shift_ & (1<<lengthbit))>>lengthbit;		\
      if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;			\
    prev_stat[w]=new_stat;					\
    tmp++;							\
    if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];		\
    else *pulsoutHI[tmp]=pulsouts[tmp];				\
    }								\
}


#define BITN_AND_OUTVNOSHIFT_ {						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    tmp=(w<<1);								\
    if (w!=0){								\
    if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];			\
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


// for pulse outs
#define BITN_AND_OUTVINT_ {						\
    gate[w].shift_+=bitn;						\
    gate[w].dac=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    tmp=(w<<1);								\
    if (w!=0){								\
    if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];			\
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

#define BITN_AND_OUTVINTNO_ {						\
    gate[w].dac=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    tmp=(w<<1);								\
    if (w!=0){								\
    if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];			\
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

