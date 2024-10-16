void stream(uint8_t w){ // sequential 12 bit in - use also for L, R, N

  bitn^=adcpadbits(11);
  BINROUTE_;
  BITN_AND_OUTV_;

void adcdraft0(uint8_t w){

  // eg. basic operation - but does it need its own speed sets?
  gate[w].gshift_=gate[w].gshift_<<1;
  bitn^=adcpadbits(11);
  BINROUTE_;
  gate[w].gshift_+=bitn;
  
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  gate[w].shift_=gate[w].gshift_; /// that one has shift
  BITN_AND_OUTV_;

void adcdraft1(uint8_t w){

  bitn^=adcpadbits(11);
  gate[w].gshift_+=bitn;
  bitn = (gate[w].gshift_>>SRlength[w]) & 0x01; // length can also be independent

  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=adcpadbits(SRlength[w]); // if is just case of bitn we can don't need to copy full register... but
  bitn^=ADC_(w,SRlength[w],3,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BINROUTE_; // route in gshift or insert/mix in ??? but we still need to slow it down...
  BITN_AND_OUTV_;

void adcLparallel(uint8_t w){ //

  lastbitn=dacpadbits(4); // can be other functions also
  //  BITN_AND_OUTV_;

void adcLparallel2(uint8_t w){ //

  lastbitn=adcpadbits(4); // can be other functions also
  //  BITN_AND_OUTV_;

void adcLdraft2(uint8_t w){ // detach

  tmp=31-(CVL[w]>>7); //5 bits
  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); 
  gate[w].shift_+=bitn;				\
  // slide in using CVL/tmp as amount from top of GSR
  if ((SRlength[dacfrom[daccount][w]]-tmp)<0) tmp=SRlength[dacfrom[daccount][w]];
  top=SRlength[dacfrom[daccount][w]]-tmp; // length-tmp as long as tmp is less than length
  val=gate[dacfrom[daccount][w]].Gshift_[w]&(masky[tmp]<<top);
  val=val>>top;
  gate[w].shift_^=val;  
  BITN_AND_OUTVNOSHIFT_;

void adcnoroute0(uint8_t w){ // basic ADC in with no route in

  ADCXORINNOG(0);
}

// cv selects length and  or/xor/route
void adcorxor0(uint8_t w){ // split length / or / xor // DETACH LENGTH - could be nice also select adc type
ADCORXORIN(0);
}

//////////////////////////////////////
// basic ADC type  modes
//////////////////////////////////////

void adc0(uint8_t w){ // basic ADC in with XOR route in
  ADCXORIN(0);
}

void adc1(uint8_t w){ // equivalent bits
  ADCXORIN(1);
}

void adc2(uint8_t w){ // one bit audio
  ADCXORIN(2);
}

void adc114(uint8_t w){ // one bit audio - unipolar
  ADCXORIN(114);
}


void adc2no(uint8_t w){ // one bit audio
  ADCXORIN_NOROUTE(2);
}


void adc3(uint8_t w){ // basic sequential length as in 0 but with padding if >11 bits  
  ADCXORIN(3);
}

void adc4(uint8_t w){ // spaced 4 bits in but we need to route DAC in differently - this is done now in adc_ mode 4
  ADCXORIN(4);
}

void adc5(uint8_t w){ // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...//NON
  ADCXORIN(5);
}

void adc6(uint8_t w){ // padded version of SR of bitsin
  ADCXORIN(6);
}

void adc7(uint8_t w){ // // timed version of SR bitsin - is MSB first- //NON
  ADCXORIN(7);
  //  ADCXORIN_NOROUTE(7);
}

void adc90equiv(uint8_t w){ // equiv energy
  ADCXORIN(90);
  //  ADCXORIN_NOROUTE(7);
}

void adc91sw(uint8_t w){ // use dac for input or loop
  ADCXORIN_NOROUTE(91);
}

void adc93(uint8_t w){ // - 2048
  ADCXORIN(93);
}

void adc94(uint8_t w){ // abs - 2048
  ADCXORIN(94);
}

void adc106(uint8_t w){ // cv
  ADCXORIN(106);
}

void adc99(uint8_t w){ // strobe switches between adc and dac but did we not have this already?
  ADCXORIN_NOROUTE(99);
}

void adc95(uint8_t w){ // strobe toggle in - otherpar selects pattern which is now dac driven - 4 bits
  param[w]=gate[dacfrom[daccount][w]].Gshift_[w]>>8;
  ADCXORIN(95); 
}

// not really working
void adc95bins(uint8_t w){ // strobe toggle in - otherpar selects pattern which is now dac driven - 4 bits - now binroute as strobe in macro!
  param[w]=gate[dacfrom[daccount][w]].Gshift_[w]>>8;
  ADCXORINBIN(95); 
}

void adc97only(uint8_t w){ // only pull in on speed otherwise route // ***
  HEAD;
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_; // no shift
  bitn^=ADC_(w,SRlength[w],97,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  //  BINROUTE_; // or no route in here
  BITN_AND_OUTVNOSHIFT_; // no shift

void adc98adcordac(uint8_t w){ // only pull in on speed otherwise route

  bitn^=ADC_(w,SRlength[w],98,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  //  BINROUTE_; // or no route in here
  BITN_AND_OUTVNOSHIFT_; // no shift

void adc32(uint8_t w){ // multiple bits in as case 19 in draftdec // ***

    //  bitn^=ADC_(w,SRlength[w],4,trigger[w],reggg,adcpar); // this is now adc mode 4 - we don't use bitn and do spacmask in adc
    bitn^=ADC_(w,SRlength[w],4,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    if (SRlength[inroute[count][w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[inroute[count][w]].Gshift_[w]&(1<<lastspac[SRlength[inroute[count][w]]][w])) >>(lastspac[SRlength[inroute[count][w]]][w]))+ \
		      ((gate[inroute[count][w]].Gshift_[w]&(1<<lastspac[SRlength[inroute[count][w]]][1]))          >> ((lastspac[SRlength[inroute[count][w]]][1]) - spacc[SRlength[w]][w]))  + \
		      ((gate[inroute[count][w]].Gshift_[w]&(1<<lastspac[SRlength[inroute[count][w]]][2]))         >>((lastspac[SRlength[inroute[count][w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[inroute[count][w]].Gshift_[w]&(1<<lastspac[SRlength[inroute[count][w]]][3]))         >>((lastspac[SRlength[inroute[count][w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[inroute[count][w]].Gshift_[w]&(1<<lastspac[SRlength[inroute[count][w]]][w]))>>(lastspac[SRlength[inroute[count][w]]][w])) + \
			((gate[inroute[count][w]].Gshift_[w]&(1<<lastspac[SRlength[inroute[count][w]]][1]))<< ((spacc[SRlength[w]][w]) - lastspac[SRlength[inroute[count][w]]][1]))  + \
			((gate[inroute[count][w]].Gshift_[w]&(1<<lastspac[SRlength[inroute[count][w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[inroute[count][w]]][2]))  + \
			((gate[inroute[count][w]].Gshift_[w]&(1<<lastspac[SRlength[inroute[count][w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[inroute[count][w]]][3])));
    }
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_; // no pulse ins/outs

void adc1010(uint8_t w){ // test speed double/skip sample

  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  if (gate[w].trigger) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;
  tmp=myroute[w][gate[w].route];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_;

void adcbumproutebin0(uint8_t w){ // incoming binroute bumps up our local route - add one to this (what value) - gate[w].route

  BINROUTENOS_; 
  if (bitn) gate[w].route++;
  if (gate[w].route>15) gate[w].route=0;
  tmp=myroute[w][gate[w].route];
  bitn=0;
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  if (gate[w].trigger) bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_;

void adcghostroute0(uint8_t w){ // but which ghost? our own moved on by 1? so here is default of 1...

  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=(gate[w].Gshift_[routeto[count][w]])&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_;

void adcDACroute0(uint8_t w){

  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  if (!strobey[w][mode[w]]) bitn =bitn|gate[w].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][w]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_;

void adcSRroute0(uint8_t w){

  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][w]].Gshift_[w]&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_;

void adcDACroutestrobe0(uint8_t w){ // dacroute with strobe

  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  //  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][w]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  if (gate[w].trigger) bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTV_;

void adcstrobe1_0(uint8_t w){

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (gate[w].trigger) bitn=!bitn;
    BINROUTE_;
    BITN_AND_OUTV_;

void adcbin1_0(uint8_t w){

    BINROUTE_;
    val=bitn;
    bitn=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (val) bitn=!bitn;
   BITN_AND_OUTV_;

void adcstrobe2_0(uint8_t w){ // basic ADC in - strobe= bitn or route

    if (gate[w].trigger)    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    else BINROUTE_;
    BITN_AND_OUTV_;

void adcstrobe3_0(uint8_t w){ // basic ADC in - see above table - 3ADC BIT vs [ADC/xor/or/routed] - NONE

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
o    if (gate[w].trigger) BINROUTE_; // or vice versa
    BITN_AND_OUTV_;

void adcLstrobe1(uint8_t w){

    bitss=CVL[w]>>6; // 6 bits
    bits=bitss&3; // 2 bits
    if (bits==0){    
    if (gate[w].trigger) bitn=!bitn;
    bitn^=ADC_(w,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    BINROUTE_;
    }

    if (bits==1){    
    if (gate[w].trigger)    bitn^=ADC_(w,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    else BINROUTE_;
    }

    if (bits==2){    
    bitn^=ADC_(w,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (gate[w].trigger) BINROUTE_; // or vice versa
    }

    if (bits==3){    
    bitn^=ADC_(w,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (gate[w].trigger) JUSTCYCLE_;
    }

    BITN_AND_OUTV_;

void adcLstrobe2(uint8_t w){ // 2nd version covering abstract modes and returns - check adc selection TODO

    bitss=CVL[w]>>6; // 6 bits
    bits=bitss&3; // 2 bits
    if (bits==0){    
    bitn^=ADC_(w,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (gate[w].trigger) JUSTCYCLE_;
    BINROUTE_; 
    }

    if (bits==1){    
    if (!gate[w].trigger) bitn^=ADC_(w,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    else {
      BINROUTEANDCYCLE_;
    }
    }

    if (bits==2){    
    if (!gate[w].trigger) { bitn^=ADC_(w,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
      BINROUTE_;
    }
    else JUSTCYCLE_;
    }

    if (bits==3){    // new one
          bitn^=ADC_(w,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
	  if (!gate[w].trigger) bitn=!bitn;
	  BINROUTEANDCYCLE_;
    }

    BITN_AND_OUTV_;

void adcstrobe4_29(uint8_t w){

    bitn^=ADC_(w,SRlength[w],29,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (gate[w].trigger) JUSTCYCLE_;
    BINROUTE_; 
    BITN_AND_OUTV_;

void adcstrobe5_29(uint8_t w){

    if (!gate[w].trigger) bitn^=ADC_(w,SRlength[w],29,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    else {
      BINROUTEANDCYCLE_;
    }
    BITN_AND_OUTV_;

void adcstrobe6_29(uint8_t w){  // 6- ADCBIT xor routed vs returnbit

    if (!gate[w].trigger) { bitn^=ADC_(w,SRlength[w],29,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
      BINROUTE_;
    }
    else JUSTCYCLE_;
    BITN_AND_OUTV_;

void adcLCVDACroute(uint8_t w){ // CV: 4 bits for route in...

  // CVL->choose tmpp which can be ADC (access?) otherpar=0means adcin 1, route 4 bits, cycle 1, XOR cycle/route 1 
  // figure out CVL 12 bits
  which=CVL[w]>>6; // try 6 bits
  if (which==0) tmpp=255; // means use ADC
  else if (which==1) tmpp=(gate[w].Gshift_[w]>>SRlength[w])& 0x01;  // use cycling bit
  else
    { // 4 bits for route 1 bit for xor cycle or not
      if (which&0x02==2) val=1;
      else val=0;
      tmp=which>>2; // 1st two bits skipped... leaves 4 bits for route
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	  tmpp^=bitrr;
	}
	tmp=tmp>>1;
      }
      if (val==1) tmpp^=(gate[w].Gshift_[w]>>SRlength[w])& 0x01;  // use cycling bit - will also zero itself on own route in
    }
  
  bitn^=ADC_(w,SRlength[w],88,gate[w].trigger,dacfrom[daccount][w],tmpp, &gate[w].shift_); 
  //  no binroute here
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_;

void adcmultiplespeednew0(uint8_t w){ // NO LENGTH - try 4 speeds as above - multiple versions of this // this one is ****


  if (counter[w]>gate[dacfrom[daccount][w]].dac){ //3.advance incoming ghost
    counter[w]=0;
    BINROUTEADV_;
  }

  if (counterd[w]> CVL[w]){
      counterd[w]=0;
    gate[w].shift_=gate[w].shift_<<1; // 1. shifter
  }
  
  if (speedf_[w]!=LOWEST){ // 4.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    //    gate[w].shift_=gate[w].shift_<<1; // but no shift makes odd with add... anyways
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    BINROUTENOG_; // no gshifty
    BITN_AND_OUTV_;

void adcLdoublelength(uint8_t w){   // DETACH LENGTH

      bitn^=ADC_(w,SRlength[w],81,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // use 4 bits in!
      BINROUTE_;
  }
    else {
      // we add extension at top which we shift into: extrashift_  //   gate[w].shift_+=bitn;
      // but gshift will be this top bit with appropriate reduced length
      gate[w].Gshift_[0]=gate[w].extrashift_;
      gate[w].Gshift_[1]=gate[w].extrashift_;
      gate[w].Gshift_[2]=gate[w].extrashift_;
      gate[w].Gshift_[3]=gate[w].extrashift_;
      gate[w].Gshift_[8]=gate[w].extrashift_;
      gate[w].Gshare_=gate[w].shift_;
      gate[w].extrashift_=gate[w].extrashift_<<1;

      SRlength[w]=tmplength-32; // fixed 18/3
      gate[w].extrashift_+=gate[w].shift_>>31; // top bit shift in
      gate[w].shift_=gate[w].shift_<<1;

      bitn^=ADC_(w,SRlength[w],81,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // use 4 bits in!
      BINROUTE_;      
    }
    
  BITN_AND_OUTV_;

void adcLproto(uint8_t w){// null

  ///////HERE
  BITN_AND_OUTV_;

void adcflip(uint8_t w){ // full speed 1/0 flipflop and fake strobe - TODO: fake strobe can also be used for other strobe modes...// null

  ///////HERE
  bitn^=ADC_(w,SRlength[w],strobemodes[CVL[w]>>8],flipflop,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLstrobe(uint8_t w){ // select strobemode (we have 20 but just 16 now)

  ///////HERE
  bitn^=ADC_(w,SRlength[w],strobemodes[CVL[w]>>8],gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLbinrstr(uint8_t w){ // route in as strobe: select strobemode (we have 20 but just 16 now)

  BINROUTENOS_;
  bitn=ADC_(w,SRlength[w],strobemodes[CVL[w]>>8],bitn,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BITN_AND_OUTV_;

void adcLbitprob(uint8_t w){

  ///////HERE
  tmp=CVL[w];
  val=ADC_(w,SRlength[w],113,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_); // prob generator
  if (val){
    //  BINROUTE_;
    bitn=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
    PULSIN_XOR;
  }
  else
    {
      //      JUSTCYCLE_;
      BINROUTE_;
      PULSIN_XOR;
    }  
  BITN_AND_OUTV_;

void adcLbinprob(uint8_t w){ // binroute in as prob of entry of new bit from adc or cycle

  val=CVL[w]>>8; // 4 bits 
  ///////HERE
  BINROUTENOS_;
  if (bitn){
    bitn=(*adcbitstreams[val])(SRlength[w]);
    PULSIN_XOR;
  }
  else {
    JUSTCYCLE_;
    PULSIN_XOR;
  }
  BITN_AND_OUTV_;

void adcintbinprob(uint8_t w){

    val=CVL[w]>>8; // 4 bits 
  ///////HERE
    BINROUTENOS_; // bit from route in
  if (bitn){
    bitn=(*abstractbitstreams[val])(CV[w],w);
    PULSIN_XOR;
  }
  else {
    bitn=0;
    JUSTCYCLE_; 
    PULSIN_XOR;
  }
    BITN_AND_OUTVINT_; 
  } 
}

// another without route in decision
void adcintabstract(uint8_t w){ 
  HEADSSINNADA;  // length is detached or not
  if (gate[w].trigger)      {
    GSHIFT_;
    val=CVL[w]>>8; // 4 bits 
    bitn=(*abstractbitstreams[val])(CV[w],w);
    //    BINROUTE_; // or not
    BITN_AND_OUTVINT_; 
  } 
}

// testing - detach speed and length as we get speed from bitstream
void adcspeedstream(uint8_t w){ 
  HEADSSINNADA;
  val=CVL[w]>>8; // 4 bits 
  bitn=(*abstractbitstreams[val])(CV[w],w); 
  if (bitn)      {
    bitn=0; // or we mix in that bit
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  } 
}

//other way round - detach speed and length as we get speed from bitstream
void adcbinspeedstream(uint8_t w){ // would be nice to be able to slow down binroute in//so all slower
  // but we lost speed for streams select
  HEADSSINNADA;
  BINROUTENOS_; 
  if (bitn)      {
    GSHIFT_;
    val=CVL[w]>>8; // 4 bits 
    bitn=(*abstractbitstreams[val])(CV[w],w);
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  } 
}

void adcbinspeedstreamINT(uint8_t w){ // would be nice to be able to slow down binroute in//so all slower INTMODE
  // but we lost speed for streams select
  HEADSSINNADA;
  BINROUTENOS_; 
  if (bitn & gate[w].trigger)      {
    GSHIFT_;
    val=CVL[w]>>8; // 4 bits 
    bitn=(*abstractbitstreams[val])(CV[w],w);
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  } 
}

void binspeedcycle(uint8_t w){ // but what do we do with speed then? - run binroute at speed
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  BINROUTENOS_;
  if (bitn)      {
    bitn=0;
    GSHIFT_;
    JUSTCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_;

void binnospeedcycle(uint8_t w){ // no speed set

    JUSTCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  }
}

// versions with/without binroute, with/without addin to gshift in binroute: BINROUTENOG_
// versions with independent modes

// those ones could be further bits above: binroute/nobin // if so: gshiftadd/not // indmode or not

/*
binroute/nobin

binroute/binroutessansadd

+ 1 bit indmode = 2 or 3 bits
*/
//

// versions with length=depth

void adcLabstract(uint8_t w){ // abstract modes with option now binroute or not
  HEADSSINNADA;
  uint32_t depth;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  tmp=CVL[w]>>6; // 4 bits + 2 now - 6 bits
  depth=CV[w]; // 12-> 5 bits below
  if (tmp&0x01)  bitn=(*abstractbitstreams[tmp>>2])(depth,w);
  else bitn=(*abstractbitstreamsI[tmp>>2])(depth,w); // independent
  if (tmp&0x02){    
    BINROUTE_;
  }
  BITN_AND_OUTV_;

void adcLabstractNOG(uint8_t w){ // abstract modes with option now binroute or not - no bitoruteGshift option

  ///////HERE
  tmp=CVL[w]>>6; // 4 bits + 2 now - 6 bits
  depth=CV[w]; // 12-> 5 bits below
  if (tmp&0x01)  bitn=(*abstractbitstreams[tmp>>2])(depth,w);
  else bitn=(*abstractbitstreamsI[tmp>>2])(depth,w);
  if (tmp&0x02){    
    BINROUTE_;
  }
  else {
    BINROUTENOG_
  }
  BITN_AND_OUTV_;

void adcLabstractLD(uint8_t w){ // abstract modes with option now binroute or not - now with fixed length=depth so we have speed

  ///////HERE
  tmp=CVL[w]>>6; // 4 bits + 2 now - 6 bits
  if (tmp&0x01)  bitn=(*abstractbitstreams[tmp>>2])(SRlength[w],w);
  else bitn=(*abstractbitstreamsI[tmp>>2])(SRlength[w],w);
  if (tmp&0x02){    
    BINROUTE_;
  }
  BITN_AND_OUTV_;

void adcLabstractI(uint8_t w){ // just to test abstract modes - could be used but we lose speed and wastes bits - detached both

  tmp=CVL[w]>>8; // 4 bits
  depth=CV[w]; // 12-> 5 bits below
  bitn=(*abstractbitstreamsI[tmp])(depth,w);
  BINROUTE_; // or not?
  BITN_AND_OUTV_;

void adcLabstractQIN(uint8_t w){ // abstract modes select IN? again we lose speed and bits

  ///////HERE
  tmp=CVL[w]>>8; // 4 bits
  //  tmp=0;
  depth=CV[w]; // 12-> 5 bits below
  tmp=(*abstractbitstreams[tmp])(depth,w);
  if (tmp){
  BINROUTE_;
  }
  else
    {
      JUSTCYCLE_;
    }
  BITN_AND_OUTV_;

void adcLTMinTM(uint8_t w){ // abstract modes select IN? again we lose speed and bits DETACH length - TM in TM

  ///////HERE
  //  val=CVL[w]>>8; // 4 bits - but we could have 31 options
  //  tmp=0;
  depth=CVL[w]; // 12-> 5 bits below
  BINROUTE_;
  tmp=TMsimplebits(depth,w); // or indie version?
  if (tmp){
    bitn=!bitn;
  }
  BITN_AND_OUTV_;

void adcLabstractTM(uint8_t w){ // abstract modes select IN? again we lose speed and bits DETACH BOTH

  ///////HERE
  val=CVL[w]>>8; // 4 bits - but we could have 31 options
  //  tmp=0;
  depth=CV[w]; // 12-> 5 bits below
  BINROUTE_;
  tmp=(*altabstractbitstreams[val])(depth,w);
  if (tmp){
    bitn=!bitn;
  }
  BITN_AND_OUTV_;

void adcLFROM(uint8_t w){  // FROM? - we use both params - can also be detached strobe modeTODO

  ///////HERE
  tmp=CVL[w]>>6; // 6 bits: type/route = 4 bits // adc/dac/abstract/route = 2 bits
  depth=CV[w]; // 12-> 5 bits below
  tmpp=tmp&3; //1st 2 bits
  
  if (tmpp==0){
    // FROM adcins
    bitn=(*adcbitstreams[tmp>>2])(depth>>7);
  }
  else if (tmpp==1){
    bitn=(*dacbitstreams[tmp>>2])(depth>>7);
  }
  else if (tmpp==3){
    bitn=(*abstractbitstreams[tmp>>2])(depth,w);
  }
  else {
    // use route in from tmp
    tmp=tmp>>2;
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }
  }
  // binroute or not 

  
  BITN_AND_OUTV_;

void adcLmix0(uint8_t w){

  mult=mixer[CVL[w]>>2]; // 10 bits - 0 is 1.0f so full dac
  //    mult=0.0f;
  ADCgeneric;
  pp=(float)(k *  (1.0f-mult)) + ((float)(dacfrom[daccount][w]].dac)*mult); // mix with param
  //    //    pp=(float)(adc_buffer[12]*(1.0f-mult)+((float)(gate[3].dac)*mult); // mix with param - optional
  tmp=(int)pp;
  if (tmp>4095) tmp=4095;
  bitn^=ADCg_(0, SRlength[w], 7 , &gate[w].shift_, tmp);  //??? 4 bits for type  66=modulo, 67=add, 68=and
  BITN_AND_OUTV_;

void adcLmix1(uint8_t w){

  tmpp=(CVL[w]>>6);
  tmp=tmpp&0x03;
  //    mult=1.0f/(float)((gate[tmp].dac)+1.0f); // but if we use 3 below... anyways
  mult=mixer[gate[tmp].dac>>2];
  ADCgeneric;
  //    pp=(float)k+((float)(gate[tmp].dac)*mult); // mix with param
  pp=((float)(k)*(1.0f-mult)) + ((float)(gate[3].dac)*mult); // mix with param - optional
  tmp=(int)pp;
  if (tmp>4095) tmp=4095;
  bitn^=ADCg_(0, SRlength[w], tmpp>>3 , &gate[w].shift_, tmp);  //??? 4 bits for type  66=modulo, 67=add, 68=and
  BITN_AND_OUTV_;

void adcLpattern95(uint8_t w){   // DETACH LENGTH and select one of 16 patterns insert on strobe

  tmp=(CVL[w]>>8); //4 bits
  bitn^=ADC_(w,SRlength[w],95,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_); 
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLpatternbin95(uint8_t w){   // DETACH LENGTH and select one of 16 patterns insert on strobe

  BINROUTE_;
  tmp=(CVL[w]>>8); //4 bits
  bitn=ADC_(w,SRlength[w],95,bitn,dacfrom[daccount][w],tmp, &gate[w].shift_); 
  BITN_AND_OUTV_;

void adcLtm101(uint8_t w){   // DETACH LENGTH and use CVL for classic TM

  bitn^=ADC_(w,SRlength[w],101,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_; // route in or not
  BITN_AND_OUTV_;

void adcLtm102(uint8_t w){   // DETACH LENGTH and use CVL for classic TM

  bitn^=ADC_(w,SRlength[w],102,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_; // route in or not
  BITN_AND_OUTV_;

void adcLtm103(uint8_t w){   // DETACH LENGTH and use CVL for classic TM

  bitn^=ADC_(w,SRlength[w],103,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_; // route in or not
  BITN_AND_OUTV_;

void adcLtm104(uint8_t w){   // DETACH LENGTH and TM in TM

  bitn^=ADC_(w,SRlength[w],104,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_; // route in or not
  BITN_AND_OUTV_;

void adcLtm105(uint8_t w){   // DETACH LENGTH and use CVL for classic TM with DAC

  bitn^=ADC_(w,SRlength[w],105,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  //  BINROUTE_; // route in or not
  BITN_AND_OUTV_;

void adcLcomp20(uint8_t w){   // DETACH LENGTH - comparator 12 bits

  bitn^=ADC_(w,SRlength[w],20,gate[w].trigger,dacfrom[daccount][w],CVL[w], &gate[w].shift_); 
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLsub92(uint8_t w){   // DETACH LENGTH - subtract 12 bits

  bitn^=ADC_(w,SRlength[w],92,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLsplice100(uint8_t w){   // DETACH LENGTH - splice in 4 bits at position

  bitn^=ADC_(w,SRlength[w],100,gate[w].trigger,dacfrom[daccount][w],31-(CVL[w]>>7), &gate[w].shift_); 
  BINROUTE_;
  BITN_AND_OUTV_;//OSHIFT_; //  ADCXORINX(96); // we dont add bt but do shift - BITN_AND_OUTVOSHIFT

void adcLBURST0(uint8_t w){

  if (gate[w].trigger){
    train[w]=1;
  }
  if (train[w]!=0 && train[w]< (1024-(CVL[w]>>2))){
  train[w]++;
  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  }
  else {
    train[w]=0;
    BINROUTE_;
  }
  BITN_AND_OUTV_;

void adcLseladc(uint8_t w){ // select ADC 0-31 ***

  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BINROUTE_; // 
  BITN_AND_OUTV_;

void adcLcutfeedback86(uint8_t w){ //    //    TODO/TEST: *cut feedback between dacs 1 and 3 - eg. cut for CV count clk pulses/on off* STROBE

  tmp=(CVL[w]>>2); // 10 bits - how many bits works best?
  bitn^=ADC_(w,SRlength[w],86,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_); 
  //  BINROUTE_; // TODO: route in or not - 2 versions
  BITN_AND_OUTV_;

void adcLseladc1(uint8_t w){ // select ADC 0-63 - preferred modes with param[w] as param   // DETACH LENGTH

  tmp=(CVL[w]>>6); // 6 bits = 64 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],seladc[tmp],gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLseladc2(uint8_t w){ // speed from cv, cvl as type and dac as param   // DETACH LENGTH

  bitn^=ADC_(w,SRlength[w],parammodes[CVL[w]>>8],gate[w].trigger,dacfrom[daccount][w], gate[dacfrom[daccount][w]].dac, &gate[w].shift_);
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLseladc5th(uint8_t w){ // speed from cv, cvl as type and TAIL5 as param   // DETACH LENGTH - parammodes

  bitn^=ADC_(w,SRlength[w],parammodes[CVL[w]>>8],gate[w].trigger,8, gate[8].dac, &gate[w].shift_);  // or vice versa and route in 8/5th tail
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLseladcdac5th(uint8_t w){ // speed from cv, cvl as type and TAIL5 as param   // DETACH LENGTH - dacmodes

  bitn^=ADC_(w,SRlength[w],dacmodes[CVL[w]>>8],gate[w].trigger,8, gate[8].dac, &gate[w].shift_);  // or vice versa and route in 8/5th tail
  BINROUTE_;
  BITN_AND_OUTV_;

void adcdacmod5th(uint8_t w){ // was adcdacmod0

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);  // detach and select TODO
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcLpulse89(uint8_t w){ // test 89 impulse  // DETACH LENGTH

  bitn^=ADC_(w,SRlength[w],89,gate[w].trigger,dacfrom[daccount][w], CVL[w]>>2, &gate[w].shift_);
  BINROUTE_;
  BITN_AND_OUTV_;

void adcLSRlengthsel(uint8_t w){ //use other SR bits to determine length of SR, eg. can be modded or...*   // DETACH LENGTH

  tmp=(CVL[w]>>7); // 5 bits = 32
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  //  BINROUTE_; // with or without route in
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_;

void adcLSRlengthsel0(uint8_t w){ //use other SR bits to determine length of SR, eg. can be modded or...*   // DETACH LENGTH


  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  //  BINROUTE_; // with or without route in // ***
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_;

void adcLLswop0(uint8_t w){ // swop in or logop SR - cv and cvl- not so good for Nmode   // DETACH LENGTH/SPEED

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    BINROUTE_; 
    if (gate[w].trigger) {
      lin=127-(CV[w]>>5); //7= 2 bits for whichone and start which can be 5
      lout=31-(CVL[w]>>7); // 5 bits for length
      // length of incoming - lout
      tmp=gate[lin&0x03].shift_>>(31-lout);
      gate[w].shift_^=(tmp<< (31-(lin>>2)));// + (rin<<(31-(lin>>2))) );
      //gate[w].shift_=gate[oppose[w]].shift_; // sieve is previous one but could be opposite one
      }
    BITN_AND_OUTV_;

void adcgenericprobx(uint8_t w){ // porting to strobe - ported to N - detach CVL - length to select ADC // DETACH LENGTH

    BINROUTE_;
    prob[0]=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);; // route
    prob[1]=bitn; // route
    prob[2]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[3]=0;

    // bit is 8 x 3 - 5 bits + 2 bits
    bit=gate[dacfrom[daccount][w]].dac&31; 
    lower=bit&0x03;
    bit=(bit>>2)*3;

    if (gate[w].trigger) bitn^=prob[lower]; // lowest 2 bits
    else bitn^=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
        BITN_AND_OUTV_;

void adcdacadditself0(uint8_t w){ // tested//trial itself as DAC - can also be other variants TODO

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTV_;

void adcdacghostitself0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[w]//gate[x].Gshift_[w]

  //
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTV_;

void adcdacghostincoming0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[w]//gate[x].Gshift_[w]

  //
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTV_;

void adcdacseladd0(uint8_t w){

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcdacseloffosc(uint8_t w){ // ADC_ is offset, and cv is amount of dac / TEST! or vice versa as we have no knob for adc_

    bitn^=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);  // 1  bit oscillator
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcdacseloffosc2(uint8_t w){ // ADC_ is offset, and cv is amount of dac / TEST! or vice versa as we have no knob for adc_HERE

    bitn^=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);  // 1  bit oscillator
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcLrung0(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL

    tmp=CVL[w]>>8;
    bitn^=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,2, param[w], &gate[w].shift_);  // from leftDAC but is now dacC
    //    BINROUTE_; // did have this but try now with:
    JUSTCYCLE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcLrung1(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL

    tmp=CVL[w]>>8;
    bitn^=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,2, param[w], &gate[w].shift_);  // from leftDAC - should be 1 fixed 26/5
    BINROUTE_; // did have this but try now with:
    //    JUSTCYCLE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcLrung2(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,2, param[w], &gate[w].shift_);  // adc in or not
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcrung0(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL

    //    tmp=CVL[w]>>8;
    //    bitn^=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,2, param[w], &gate[w].shift_);  // from leftDAC
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcdacadd0(uint8_t w){

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcdacaddmax0(uint8_t w){ // REMOVE?

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcdacminus0(uint8_t w){

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcdacspeedminus0(uint8_t w){

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcdacmod0(uint8_t w){

    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;

void adcdacB0(uint8_t w){// with oscillator could use CVL also?
void adcintcomp20(uint8_t w){ //CV comparator //  case 20: // CVotherpar as comparator - 10 bits standard here // now 12 bits  - OTHERPAR! 12 bits

  
    bitn^=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;

void adcdacoffset0(uint8_t w){

    bitn^=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;

void adcLdacadc(uint8_t w){ // speed is from dac, use cv to select type and cvl as parameter - but just for param modes

    bitn^=ADC_(w,SRlength[w],parammodes[CV[w]>>8],gate[w].trigger,dacfrom[daccount][w], CVL[w], &gate[w].shift_); // 4 bits
    // what of some modes where we have 4095-CV[w] - should this be in adc or live with it
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; // ??
    BITN_AND_OUTV_;

