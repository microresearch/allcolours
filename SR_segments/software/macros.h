// for new struct sets of modes:

#define CVOPEN {				\
    if (gate[w].time_now>32768){				\
      gate[w].int_time=0;					\
      gate[w].time_now-=32768.0f;				\
    }									\
    alpha = gate[w].time_now - (float)gate[w].int_time;			\
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - alpha)); \
    if (gate[w].dac>4095) gate[w].dac=4095;				\
    else if (gate[w].dac<0) gate[w].dac=0;				\
    gate[w].time_now += speedf_[w];					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }

#define CVOPENNOINTERPOL {				\
    if (gate[w].time_now>32768){				\
      gate[w].int_time=0;					\
      gate[w].time_now-=32768.0f;				\
    }									\
    alpha = gate[w].time_now - (float)gate[w].int_time;			\
    gate[w].dac = delay_buffer[w][1];					\
    if (gate[w].dac>4095) gate[w].dac=4095;				\
    else if (gate[w].dac<0) gate[w].dac=0;				\
    gate[w].time_now += speedf_[w];					\
    gate[w].last_time = gate[w].int_time;				\
    gate[w].int_time = gate[w].time_now;				\
  }

// this one is used for DACspeed modes
#define CVOPENDAC {				\
    if (gate[w].time_now>32768){				\
      gate[w].int_time=0;					\
      gate[w].time_now-=32768.0f;				\
    }									\
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

#define HEADN float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; gate[3].dactype=66; \

#define HEAD float alpha; uint32_t bitn=0, bitrr, tmp, val, x, xx, lengthbit=15, new_stat; \

#define ENDER {					\
    new_data(val,w);				\
    gate[w].last_time += 1;			\
  }


// redefining for struct

#define GSHIFT_ {				\
    gate[w].Gshift_[0]=gate[w].shift_;			\
    gate[w].Gshift_[1]=gate[w].shift_;			\
    gate[w].Gshift_[2]=gate[w].shift_;			\
    gate[w].Gshift_[3]=gate[w].shift_;			\
    gate[w].shift_=gate[w].shift_<<1;			\
}

#define JUSTCYCLE_ {					\
  bitrr = (gate[w].shift_>>SRlength[w]) & 0x01;		\
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
  }



#define BINROUTEOR_ {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;		\
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;		\
  bitn|=bitrr;							\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

//DAC_(uint32_t wh, uint32_t shift, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t strobe){  // DAC is 12 bits
// this one is for fractional speeds/interpol
#define BITN_AND_OUTV_ {						\
    gate[w].shift_+=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    tmp=(w<<1);								\
    if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];			\
    else *pulsoutHI[tmp]=pulsouts[tmp];				\
    lengthbit=(SRlength[w]>>1);					\
    new_stat=(gate[w].shift_ & (1<<lengthbit))>>lengthbit;		\
    if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;		\
    prev_stat[w]=new_stat;					\
    tmp++;							\
    if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];		\
    else *pulsoutHI[tmp]=pulsouts[tmp];				\
}

#define BITN_AND_OUTVINT_ {						\
    gate[w].shift_+=bitn;						\
    gate[w].dac=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
    tmp=(w<<1);								\
    if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];			\
    else *pulsoutHI[tmp]=pulsouts[tmp];				\
    lengthbit=(SRlength[w]>>1);					\
    new_stat=(gate[w].shift_ & (1<<lengthbit))>>lengthbit;		\
    if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;		\
    prev_stat[w]=new_stat;					\
    tmp++;							\
    if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];		\
    else *pulsoutHI[tmp]=pulsouts[tmp];				\
}


#define BITN_AND_OUTVN_ {						\
    gate[w].shift_+=bitn;						\
    val=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
}

// for int modes as no interpol
#define BITN_AND_OUTNINT_ {						\
    gate[w].shift_+=bitn;						\
    gate[w].dac=DAC_(w, gate[w].shift_, SRlength[w], gate[w].dactype, gate[w].dacpar, gate[w].trigger); \
}

#define PULSOUT_ {				  \
  tmp=(w<<1);					  \
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(gate[w].shift_ & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}

// these all had     if (w==3) count=0; 10/1/2021				\

#define PULSIN_XOR {				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn^=xx;					\
  }

#define PULSIN_OR {				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn|=xx;					\
}

// prob is upto 32 // 5 bits
#define PULSIN_LEAK {				\
    xx=!(GPIOC->IDR & pulsins[w]);			\
    bitn=otherleaks(bitn,xx,prob,w);			\
}


#define PULSIN_LOGOP {				\
      xx=!(GPIOC->IDR & pulsins[w]);		\
      bitn=logop(bitn,xx,logtable[w]);		\
}

// reverse 32 bits for tmpp - but how to reverse based on length - reverse lowest srlength bits ?
#define REV32 {				\
  tmpp = ((tmpp >> 1) & 0x55555555) | ((tmpp & 0x55555555) << 1);	\
  tmpp = ((tmpp >> 2) & 0x33333333) | ((tmpp & 0x33333333) << 2);	\
  tmpp = ((tmpp >> 4) & 0x0F0F0F0F) | ((tmpp & 0x0F0F0F0F) << 4);	\
  tmpp = ((tmpp >> 8) & 0x00FF00FF) | ((tmpp & 0x00FF00FF) << 8);	\
  tmpp = ( tmpp >> 16             ) | ( tmpp               << 16);	\
  }

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


//for INTmodes ???
#define CVin31 (31-(adc_buffer[lookupadc[w]]>>7)); 

