// MACROS 

#define LOWER {					\
  sample= ((samples[lowerPosition]&4095) + (res * ((samples[upperPosition]&4095) - (samples[lowerPosition]&4095)))); \
  }


#define UPPER {								\
    sample= ((samples[lowerPosition]>>16) + (res * ((samples[upperPosition]>>16) - (samples[lowerPosition]>>16)))); \
    }

#define PSWOP {								\
  if (f[d].ttoggle && Theldon[d]==0){		\
  f[d].toggle^=1;						\
  f[d].masterL=f[d].toggle;			\
  f[d].ttoggle=0;						\
  ADDPLAYLISTSWOP;							\
  if ((P_options>>4)&1){						\
  tmpp=f[d].masterL^1;					\
  f[d].l[f[d].masterL].play_cnt=f[d].l[tmpp].play_cnt; \
  }									\
  }									\
  }

// no adding to layer
#define PSWOPP {								\
  if (f[d].ttoggle && Theldon[d]==0){		\
  f[d].toggle^=1;						\
  f[d].masterL=f[d].toggle;			\
  f[d].ttoggle=0;						\
  if ((P_options>>4)&1){						\
  tmpp=f[d].masterL^1;					\
  f[d].l[f[d].masterL].play_cnt=f[d].l[tmpp].play_cnt; \
  }									\
  }									\
  }

#define LAYERSWOP {				\
  if (f[d].ttoggle && Theldon[d]==0){	\
  f[d].toggle^=1;					\
  f[d].masterL=f[d].toggle;		\
  f[d].ttoggle=0;					\
  }								\
  }

#define LAYERSWOPRP {				\
  if (f[d].ttoggle && Theldon[d]==0){	\
  f[d].toggle^=1;					\
  f[d].masterL=f[d].toggle;		\
  f[d].ttoggle=0;					\
  if ((P_options>>4)&1){						\
  tmpp=f[d].masterL^1;					\
  f[d].l[f[d].masterL].play_cnt=f[d].l[tmpp].play_cnt; \
  }									\
  }									\
  }

#define ADDPLAYLIST {							\
if (f[d].l[f[d].masterL].othercnt>0) {	\
 f[d].playlist[f[d].playcntr].length=f[d].l[f[d].masterL].othercnt-f[d].playlist[f[d].playcntr].start; \
 f[d].playcntr++;						\
 f[d].playfull++;						\
 if (f[d].playcntr>PLAYFULLY) f[d].playcntr=0; \
 if (f[d].playfull>PLAYFULLY) f[d].playfull=PLAYFULLY; \
 f[d].playlist[f[d].playcntr].start=f[d].l[f[d].masterL].othercnt; \
 f[d].playlist[f[d].playcntr].l=f[d].masterL; \
 }									\
 }

#define ADDPLAYLISTSWOP {							\
    tmpp=f[d].masterL^1;					\
    if (f[d].l[tmp].othercnt>0) {			\
      f[d].playlist[f[d].playcntr].length=f[d].l[tmp].othercnt-f[d].playlist[f[d].playcntr].start; \
      f[d].playcntr++;					\
      f[d].playfull++;					\
      if (f[d].playcntr>PLAYFULLY) f[d].playcntr=0; \
      if (f[d].playfull>PLAYFULLY) f[d].playfull=PLAYFULLY; \
      f[d].playlist[f[d].playcntr].start=f[d].l[f[d].masterL].othercnt; \
      f[d].playlist[f[d].playcntr].l=f[d].masterL; \
    }									\
  }


#define ADDPLAYLISTRST {							\
if (f[d].l[f[d].masterL].othercnt>0) {	\
 f[d].playlist[f[d].playcntr].length=f[d].l[f[d].masterL].othercnt-f[d].playlist[f[d].playcntr].start; \
 f[d].playcntr++;						\
 f[d].playfull++;						\
 if (f[d].playcntr>PLAYFULLY) f[d].playcntr=0; \
 if (f[d].playfull>PLAYFULLY) f[d].playfull=PLAYFULLY; \
 f[d].playlist[f[d].playcntr].start=0; \
 f[d].playlist[f[d].playcntr].l=f[d].masterL; \
 }									\
 }


#define RECLAYER {				\
 f[d].l[autre].reclayer(tmp, d);		\
 if (f[d].l[autre].overend==0) f[d].l[autre].rec_end=f[d].l[autre].rec_cnt;	\
 f[d].l[autre].rec_cnt++;				\
 if (f[d].l[autre].rec_cnt>MAXREC) {			\
 f[d].l[autre].rec_cnt=0;				\
  f[d].l[autre].rec_end=MAXREC;\
 }						\
}

#define RECLAYERP {				\
    if (f[d].l[f[d].masterL].rec_end && (RP_options&1)) tmpp=f[d].l[f[d].masterL].rec_end; \
    else tmpp=MAXREC;							\
    f[d].l[autre].reclayer(tmp, d);		\
    if (f[d].l[autre].overend==0 && f[d].l[autre].overendd==0) f[d].l[autre].rec_end=f[d].l[autre].rec_cnt; \
    f[d].l[autre].rec_cnt++;				\
    if (f[d].l[autre].rec_cnt>=tmpp) {			\
      f[d].l[autre].rec_cnt=0;				\
      if (tmpp==MAXREC) f[d].l[autre].overend=1;	\
      else f[d].l[autre].overendd=1;			\
      f[d].l[autre].rec_end=tmpp;			\
    }									\
  }

#define RECLAYERPX {				\
    if (f[d].l[f[d].masterL].rec_end && (R_options&4)) tmpp=f[d].l[f[d].masterL].rec_end; \
    else tmpp=MAXREC;							\
    f[d].l[autre].reclayer(tmp, d);		\
    if (f[d].l[autre].overend==0 && f[d].l[autre].overendd==0) f[d].l[autre].rec_end=f[d].l[autre].rec_cnt; \
    f[d].l[autre].rec_cnt++;				\
    if (f[d].l[autre].rec_cnt>=tmpp) {			\
      f[d].l[autre].rec_cnt=0;				\
      if (tmpp==MAXREC) f[d].l[autre].overend=1;	\
      else f[d].l[autre].overendd=1;			\
      f[d].l[autre].rec_end=tmpp;			\
    }									\
  }

#define DOFREEZE {				\
 if (f[d].ttoggle)			\
   {						\
 lastvalue[d]=tmp;			\
 f[d].ttoggle=0;			\
   }						\
 else {									\
   if (tmp<lastvalue[d]) tmp=lastvalue[d];		\
 }									\
 }

#define RESETT {					\
    mode=0; rec=0; play=0;				\
    global_time=0;					\
    frozen[0]=0;					\
    frozen[1]=0;					\
    frozen[2]=0;					\
    frozen[3]=0;					\
    frozen[4]=0;					\
    frozen[5]=0;					\
    frozen[6]=0;					\
    frozen[7]=0;					\
    for (x=0;x<8;x++){					\
      for (y=0;y<MAXREC;y++){				\
	recordings[x][y]=0;				\
      }							\
    }							\
  }

// deal with playfull as a 0
#define RESETFRP {							\
  if (f[d].entryp==0){					\
    lastvalue[d]=0;						\
    f[d].l[0].play_cnt=0;				\
    f[d].l[1].play_cnt=0;				\
    f[d].entryp=1;						\
  }									\
  }

#define RESETFRN {							\
    if (f[d].entryn==0){					\
      lastvalue[d]=0;						\
      f[d].entryn=1;					\
    }									\
  }

#define RESETFRR {							\
    if (f[d].entryr==0){					\
      lastvalue[d]=0;						\
      f[d].rpp==0;						\
      f[d].l[0].play_cnt=0;				\
      f[d].l[1].play_cnt=0;				\
      f[d].l[0].rec_length=f[d].l[0].rec_end; \
      f[d].l[1].rec_length=f[d].l[1].rec_end; \
      f[d].l[0].rec_start=0;				\
      f[d].l[1].rec_start=0;				\
      f[d].entryr=1;					\
    }									\
  }

#define RESETFRRP {						\
    if (f[d].entryrp==0){				\
      f[d].entryrp=1;				\
    }								\
  }

#define TEST_TOGGLES {				  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	\
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	if (!(GPIOB->IDR & (1<<6))) {		\
	lasttriggered[10]=breaker[10];		\
	breaker[10]=0;				\
	if (heldon) helder++;			\
	}					\
	else {					  \
	breaker[10]++;				  \
	if (breaker[10]>1024) breaker[10]=1024;	  \
	if (helder>8 && breaker[10]>48) {heldon=0; newmode=1; modeheld=helder; helder=0;} \
	}					  \
	if (!(GPIOB->IDR & (1<<2))) {		\
	lasttriggered[9]=breaker[9];		\
	breaker[9]=0;				\
	}					\
	else {					  \
	breaker[9]++;				  \
	if (breaker[9]>1024) breaker[9]=1024;	  \
	}					  \
	if (!(GPIOB->IDR & (1<<10))) {		\
	lasttriggered[8]=breaker[8];		\
	breaker[8]=0;				\
	}					\
	else {					  \
	breaker[8]++;				  \
	if (breaker[8]>1024) breaker[8]=1024;	  \
	}					  \
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	if (lasttriggered[10]>BRK) {	\
	  lasttriggered[10]=0;				\
	  modetoggle^=1; \
	  heldon=1;	 \
	} \
	if (lasttriggered[9]>BRK) {	\
	  lasttriggered[9]=0;				\
	  togplay=1;					\
	}						\
	if (lasttriggered[8]>BRK) {	\
	  lasttriggered[8]=0;				\
	  togrec=1;		   \
	} \
}


#define TOGGLES {				  \
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	if (!(GPIOB->IDR & (1<<2))) {		\
	lasttriggered[9]=breaker[9];		\
	breaker[9]=0;				\
	}					\
	else {					  \
	breaker[9]++;				  \
	if (breaker[9]>1024) breaker[9]=1024;	  \
	}					  \
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	if (lasttriggered[9]>BRK) {	\
	  lasttriggered[9]=0;				\
	  togplay=1;					\
	}						\
	else togplay=0;					\
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	\
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	if (!(GPIOB->IDR & (1<<10))) {		\
	lasttriggered[8]=breaker[8];		\
	breaker[8]=0;				\
	}					\
	else {					  \
	breaker[8]++;				  \
	if (breaker[8]>1024) breaker[8]=1024;	  \
	}					  \
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	if (lasttriggered[8]>BRK) {	\
	  lasttriggered[8]=0;				\
	  togrec=1;		   \
	} \
	else togrec=0;				      \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	\
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	if (!(GPIOB->IDR & (1<<6))) {		\
	lasttriggered[10]=breaker[10];		\
	breaker[10]=0;				\
	if (heldon) helder++;			\
	}					\
	else {					  \
	breaker[10]++;				  \
	if (breaker[10]>1024) breaker[10]=1024;	  \
	if (helder>8 && breaker[10]>48) {heldon=0; newmode=1; modeheld=helder; helder=0;} \
	}					  \
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	if (lasttriggered[10]>BRK) {	\
	  lasttriggered[10]=0;				\
	  modetoggle^=1;				\
	  heldon=1;					\
	} \
	}

#define FREEZERS {					\
  if (d==7){							\
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				\
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			\
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			\
    GPIO_Init(GPIOC, &GPIO_InitStructure);				\
    GPIOC->BSRRL=(1)<<6;						\
    delay();								\
    if (!(GPIOC->IDR & (freezer[7]))) {					\
      lasttriggered[7]=breaker[7];					\
      breaker[7]=0;							\
      if (Theldon[7]) Thelder[7]++;					\
    }									\
    else {								\
      breaker[7]++;							\
      if (breaker[7]>1024) breaker[7]=1024;				\
      if (Thelder[7]>8 && breaker[7]>48) {Theldon[7]=0; Newtog[7]=1; Theld[7]=Thelder[7]; Thelder[7]=0;} \
    }									\
    GPIOC->BSRRH=(1)<<6;						\
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				\
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			\
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			\
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;			\
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			\
    GPIO_Init(GPIOC, &GPIO_InitStructure);				\
    if (lasttriggered[7]>BRKF) {						\
      f[7].ttoggle=1;						\
      lasttriggered[7]=0;						\
      Theldon[7]=1;							\
    }									\
  }									\
  else									\
    {									\
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				\
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			\
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			\
      GPIO_Init(GPIOC, &GPIO_InitStructure);				\
      GPIOC->BSRRL=(1)<<6;						\
      delay();								\
      if (!(GPIOB->IDR & (freezer[d]))) {			\
	lasttriggered[d]=breaker[d];			\
	breaker[d]=0;						\
	if (Theldon[d]) Thelder[d]++;			\
      }									\
      else {								\
	breaker[d]++;						\
	if (breaker[d]>1024) breaker[d]=1024;		\
	if (Thelder[d]>8 && breaker[d]>8) {Theldon[d]=0; Newtog[d]=1; Theld[d]=Thelder[d]; Thelder[d]=0;} \
	}					  \
	GPIOC->BSRRH=(1)<<6;						\
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;			\
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			\
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			\
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		\
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		\
	GPIO_Init(GPIOC, &GPIO_InitStructure);				\
	if (lasttriggered[d]>BRKF) {				\
	f[d].ttoggle=1;					\
	lasttriggered[d]=0;					\
	Theldon[d]=1;						\
	}								\
      }									\
    }

#define CTRL {					\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 1, ADC_SampleTime_480Cycles); \
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  control[0]=ADC_GetConversionValue(ADC1);				\
  control[0]=control[0]<<SENSESHIFTS[f[0].sensi];					\
  control[0]-=SENSEOFFSETS[f[0].sensi];						\
  if (control[0]<0) control[0]=0;						\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_480Cycles); \
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  control[1]=ADC_GetConversionValue(ADC1);				\
  control[1]=control[1]<<SENSESHIFTS[f[1].sensi];					\
  control[1]-=SENSEOFFSETS[f[1].sensi];						\
  if (control[1]<0) control[1]=0;					\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_480Cycles); \
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  control[2]=ADC_GetConversionValue(ADC1);				\
  control[2]=control[2]<<SENSESHIFTS[f[2].sensi];					\
  control[2]-=SENSEOFFSETS[f[2].sensi];						\
  if (control[2]<0) control[2]=0;					\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_480Cycles); \
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  control[3]=ADC_GetConversionValue(ADC1);				\
  control[3]=control[3]<<SENSESHIFTS[f[3].sensi];					\
  control[3]-=SENSEOFFSETS[f[3].sensi];						\
  if (control[3]<0) control[3]=0;					\
}

#define REALADC {						\
switch(d){						\
  case 0:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  real[0]=ADC_GetConversionValue(ADC1);					\
  if (real[0]>1023) real[0]=1023;					\
  reall[0]=real[0];							\
  real[0]=logval[(real[0])];						\
  break;								\
  case 1:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  real[1]=ADC_GetConversionValue(ADC1);				\
  if (real[1]>1023) real[1]=1023;					\
  reall[1]=real[1];							\
  real[1]=logval[(real[1])];						\
  break;								\
  case 2:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[2]=ADC_GetConversionValue(ADC1);					\
  if (real[2]>1023) real[2]=1023;					\
  reall[2]=real[2];							\
  real[2]=logval[(real[2])];						\
  break;								\
  case 3:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[3]=ADC_GetConversionValue(ADC1);				\
  if (real[3]>1023) real[3]=1023;					\
  reall[3]=real[3];							\
  real[3]=logval[(real[3])];						\
  break;								\
  case 4:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[4]=ADC_GetConversionValue(ADC1);				\
  real[4]=real[4]<<SENSESHIFTS[f[4].sensi];						\
  real[4]-=SENSEOFFSETS[f[4].sensi];							\
  if (real[4]<0) real[4]=0;					\
  if (real[4]>4095) real[4]=4095;					\
  break;							\
  case 5:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  real[5]=ADC_GetConversionValue(ADC1);				\
  real[5]=real[5]<<SENSESHIFTS[f[5].sensi];						\
  real[5]-=SENSEOFFSETS[f[5].sensi];							\
  if (real[5]<0) real[5]=0;					\
  if (real[5]>4095) real[5]=4095;					\
  break;								\
  case 6:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[6]=ADC_GetConversionValue(ADC1);					\
  real[6]=real[6]<<SENSESHIFTS[f[6].sensi];							\
  real[6]-=SENSEOFFSETS[f[6].sensi];								\
  if (real[6]<0) real[6]=0;						\
  if (real[6]>4095) real[6]=4095;					\
  reall[6]=real[6];							\
  break;								\
  case 7:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[7]=ADC_GetConversionValue(ADC1);				\
  real[7]=real[7]<<SENSESHIFTS[f[7].sensi];							\
  real[7]-=SENSEOFFSETS[f[7].sensi];								\
  if (real[7]<0) real[7]=0;						\
  if (real[7]>4095) real[7]=4095;					\
  break;								\
   }									\
}

#define DOSPEED {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_480Cycles); \
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  speed=ADC_GetConversionValue(ADC1);					\
  if (speed>1023) speed=1023;			\
  }

#define LASTPLAYFR {					\
    if (lastplay==0) {					\
      lastplay=1;					\
      play_cnt[0]=0.0f;					\
      play_cnt[1]=0.0f;					\
      play_cnt[2]=0.0f;					\
      play_cnt[3]=0.0f;					\
      play_cnt[4]=0.0f;					\
      play_cnt[5]=0.0f;					\
      play_cnt[6]=0.0f;					\
      play_cnt[7]=0.0f;					\
    frozen[0]=0;					\
    frozen[1]=0;					\
    frozen[2]=0;					\
    frozen[3]=0;					\
    frozen[4]=0;					\
    frozen[5]=0;					\
    frozen[6]=0;					\
    frozen[7]=0;					\
    }							\
  }

#define LASTPLAYCNT {					\
    if (lastplay==0) {					\
      lastplay=1;					\
      play_cnt[0]=0.0f;					\
      play_cnt[1]=0.0f;					\
      play_cnt[2]=0.0f;					\
      play_cnt[3]=0.0f;					\
      play_cnt[4]=0.0f;					\
      play_cnt[5]=0.0f;					\
      play_cnt[6]=0.0f;					\
      play_cnt[7]=0.0f;					\
      ownplay_cnt[0]=0.0f;					\
      ownplay_cnt[1]=0.0f;					\
      ownplay_cnt[2]=0.0f;					\
      ownplay_cnt[3]=0.0f;					\
      ownplay_cnt[4]=0.0f;					\
      ownplay_cnt[5]=0.0f;					\
      ownplay_cnt[6]=0.0f;					\
      ownplay_cnt[7]=0.0f;					\
    }							\
  }


#define LASTREC {					\
    if (lastrec==0) {					\
      lastrec=1;					\
      rec_cnt[0]=0;					\
      rec_cnt[1]=0;					\
      rec_cnt[2]=0;					\
      rec_cnt[3]=0;					\
      rec_cnt[4]=0;					\
      rec_cnt[5]=0;					\
      rec_cnt[6]=0;					\
      rec_cnt[7]=0;					\
      recminor=0;					\
    }							\
  }


// closest we get - bleed from one to next is minimal
// BSRRH is low, L is high
#define CLEARDAC {						\
      DAC_SetChannel1Data(DAC_Align_12b_R, 0);			\
      j = DAC_GetDataOutputValue (DAC_Channel_1);		\
  }

#define WRITEDAC {						\
  DAC_SetChannel1Data(DAC_Align_12b_R, values[d]);	\
  j = DAC_GetDataOutputValue (DAC_Channel_1);			\
  GPIOC->BSRRH = 1<<11;						\
  GPIOC->BSRRH |= 0b1110000000000000;				\
  GPIOC->BSRRL=(d)<<13;					\
  delay2();							\
  GPIOC->BSRRL = 1<<11;						\
  CLEARDAC;							\
}

#define WRITEDAC2 {						\
  GPIOC->BSRRL = 1<<11;						\
  DAC_SetChannel1Data(DAC_Align_12b_R, values[d]);	\
  j = DAC_GetDataOutputValue (DAC_Channel_1);			\
  GPIOC->BSRRH = 0b1110100000000000;				\
  GPIOC->BSRRL=(d)<<13;					\
}


#define TRIALTOGGLEX {				\
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	\
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	if (!(GPIOB->IDR & (1<<10))) {		\
	  rec=1;				  \
	}					  \
	else rec=0;				  \
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	}  

#define LSTREC {					\
    if (llrec==0) {					\
      llrec=1;						\
      rec_cnt[0]=0;					\
      rec_cnt[1]=0;					\
      rec_cnt[2]=0;					\
      rec_cnt[3]=0;					\
      rec_cnt[4]=0;					\
      rec_cnt[5]=0;					\
      rec_cnt[6]=0;					\
      rec_cnt[7]=0;					\
    }							\
  }

#define LSTRECPLAYD {					\
    if (llrec==0) {					\
      llrec=1;						\
      over_cnt[0]=0;					\
      over_cnt[1]=0;					\
      over_cnt[2]=0;					\
      over_cnt[3]=0;					\
      over_cnt[4]=0;					\
      over_cnt[5]=0;					\
      over_cnt[6]=0;					\
      over_cnt[7]=0;					\
      rec_cnt[0]=0;				\
      rec_cnt[1]=0;				\
      rec_cnt[2]=0;				\
      rec_cnt[3]=0;					\
      rec_cnt[4]=0;				\
      rec_cnt[5]=0;					\
      rec_cnt[6]=0;					\
      rec_cnt[7]=0;				\
      overminor=0;							\
    }							\
  }

