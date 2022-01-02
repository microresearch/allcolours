//for INTmodes
#define CVin31 (31-(adc_buffer[lookupadc[w]]>>7)); 


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

#define BITN_AND_OUT {				\
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
    val=DAC_(w, SRlength[w], dactype[w],dacpar,trigger[w]);	\
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


#define PULSOUT {				  \
  tmp=(w<<1);					  \
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


#define PULSIN_XOR {				\
  if (w==3) count=0;				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn^=xx;					\
  }

#define PULSIN_OR {				\
    if (w==3) count=0;				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn|=xx;					\
}

// prob is upto 32 // 5 bits
#define PULSIN_LEAK {				\
    if (w==3) count=0;				\
    xx=!(GPIOC->IDR & pulsins[w]);			\
    bitn=otherleaks(bitn,xx,prob,w);			\
}


#define PULSIN_LOGOP {				\
    if (w==3) count=0;				\
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

