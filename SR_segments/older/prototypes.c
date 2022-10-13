//generic structure for each/late modes

dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
ADCDACETC1(8, 8); // ADCETC has GSHIFT - not all modes have gshift
if (LR[w]){ 
//BINROUTE; - this is replaced by LR mode function 
PULSIN_XOR;
} 
BITN_AND_OUT; // for all
}

//// with expansion below

//#define ADCDACETC1(X, Y){			

// all together

//generic structure for each/late modes

dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
bitn=0;
GSHIFT;

if (w==0)      {
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar); // fill in
  tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
  bitn|=bitrr;
  }
  tmp=tmp>>1;
  }

 }
 else if (w==2)      { // added else to expansion
  dactype[2]=Y;
  BINROUTE;
  }
}

 else if (LR[w]){ 
  //BINROUTE; - this is replaced by LR mode function 
  PULSIN_XOR;
 } 
BITN_AND_OUT; // for all
}


//BINROUTE
tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
  }



#define GSHIFT {				\
  counter[w]=0;					\
  Gshift_[w][0]=shift_[w];			\
  Gshift_[w][1]=shift_[w];			\
  Gshift_[w][2]=shift_[w];			\
  Gshift_[w][3]=shift_[w];			\
  shift_[w]=shift_[w]<<1;			\
}

#define BITN_AND_OUT {				\
    shift_[w]+=bitn;					\
    dac[w]=DAC_(w, SRlength[w], dactype[w],dacpar,trigger[w]);	\
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
  if (pulsins[w]!=0){				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn^=xx;					\
  }						\
  }

#define PULSIN_OR {				\
  if (pulsins[w]!=0){				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn|=xx;					\
  }						\
}

#define PULSIN_LOGOP {				\
    if (pulsins[w]!=0){				\
      xx=!(GPIOC->IDR & pulsins[w]);		\
      bitn=logop(bitn,xx,logtable[w]);		\
    }						\
}


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

// reverse 32 bits for tmp - but how to reverse based on length - reverse lowest srlength bits ?
#define RETMPERSEE {				\
  tmp = ((tmp >> 1) & 0x55555555) | ((tmp & 0x55555555) << 1);	\
  tmp = ((tmp >> 2) & 0x33333333) | ((tmp & 0x33333333) << 2);	\
  tmp = ((tmp >> 4) & 0x0F0F0F0F) | ((tmp & 0x0F0F0F0F) << 4);	\
  tmp = ((tmp >> 8) & 0x00FF00FF) | ((tmp & 0x00FF00FF) << 8);	\
  tmp = ( tmp >> 16             ) | ( tmp               << 16);	\
  }

#define BINROUTE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTEOR {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
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
  bitrr = (shift_[w]>>SRlength[x]) & 0x01;		\
  bitn^=bitrr;						\
  }


// if we go with singular defroute
#define BITNNN {								\
  bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;	\
  Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;		\
  }

//if w==3 count=0 means just to reset binroute when we are out of modes which altered it
// macro for alt routes for ADC and DAC
#define ADCDACETC1(X, Y){			\
  bitn=0;					\
  dactype[2]=Y;					\
  if (w==3) count=0;					\
  GSHIFT;						\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTE;						\
  }							\
  if (w==2)      {					\
  BINROUTE;						\
  }							\
  else {						\
}
// follow with else{ }

// we still specify type of DAC here but we leave
//  if (w==2)      {
//  BINROUTE; // TODO: substitute alt routes here for DAC. eg cycle, probability etc. 4x4 for 16-31
//  }
//  else {

// still we have DACtype here
#define ADCONLY(X, Y){			\
  bitn=0;					\
  dactype[2]=Y;					\
  if (w==3) count=0;					\
  GSHIFT;						\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTE;						\
  }							\
}
