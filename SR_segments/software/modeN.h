// see now Nmode.org

// but this is more generic adc modes for use by alll...

// *re-check strobey(binroute always has)X, pulsins_NONE HERE!, pulsouts_NONE DONE
//check: adcpar is null, replaced with 0


#define ADCORIN(X){				\
  HEADD;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  BINROUTEOR_;								\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }

// special one!
#define ADCORXORIN(X){				\
  HEADSIND;					\
  if (speedf_[w]!=2.0f){			\
    SRlength[w]=lookuplenall[((CVL[w]>>6)%32)];		\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  if (((CVL[w]>>6)&32)==32) {						\
    BINROUTEOR_;							\
  }									\
  else {								\
    BINROUTE_;								\
  }									\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }

// added strobe in binroute
#define ADCXORIN(X){				\
  HEADD;					\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }

#define ADCXORINBIN(X){				\
  HEADD;					\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  BINROUTENOS_;								\
  bitn=ADC_(w,SRlength[w],X,bitn,dacfrom[daccount][w],param[w], &gate[w].shift_); \
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }


#define ADCXORINX(X){				\
  HEADD;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTVNOSHIFT_;							\
  ENDER;								\
  }									\
  }									\
  }

/*
#define ADCSTREAMXORIN(X) {			\
  HEADD;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=(*bitstreams[w])(X);						\
  BINROUTE_;								\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }
*/

#define ADCXORINNOG(X){				\
  HEADD;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  BINROUTENOG_;								\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }

#define ADCXORIN_NOROUTE(X){				\
  HEADD;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);	\
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;			\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }

#define ADCXORINdac(X){				\
  HEADD;						\
  if (speedf_[w]!=2.0f){				\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  tmp=gate[dacfrom[daccount][w]].dac;					\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }

// not used?
#define ADCXORINdacitself(X){				\
  HEADD;						\
  if (speedf_[w]!=2.0f){				\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  tmp=gate[w].dac;					\
  bitn^=ADC_(w,SRlength[w],X,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTV_;							\
  ENDER;								\
  }									\
  }									\
  }

// this one for ones which use strobe and cv
// no strobes, nor otherpar (as that is CV or we need to free up a CV)
uint32_t adclist[32]={0,1,2,3,4,5,6,7,8,22,23,25,26,27,30,68,71,72,73,74,75,76,77,78,79,80,81,82,1010,22,23,25};

// longer sel with strobes and cv but we can only access this from detached CV/speed and length
// we have CV (speed) and CVL (length) - one is param, other is sel so
// so length or speed can be from DAC only or is detached
uint8_t seladc[63]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,75,76,21,81,82,77,78,79,80,22,23,24,25,26,27,28,29,30,31,101,64,65,66,67,68,71,72,73,74, 0,1,2,3,4,5,6,7,25,26,27,29,30}; //6 bits
// padded out to 64 with favoured ones - not used so far! - also many new modes since then

// have longer list of 64 with no strobes/no otherpar

// check where we use these and expand them!

uint8_t parammodes[16]={17,18,19,20, 21,22,29,33, 34,35,37,38, 39,66,67,68}; // preferred modes with param[w] as param

uint8_t modes16[16]={0,1,2,3,4,6,101,32,82,75,81,28,29,30,79,80}; // choose again maybe temp list TODO

uint8_t dacmodes[16]={25,26,27,71,72,73,74,75,  77,78,79,80,86,88,91,105};

uint8_t strobemodes[16]={8,9,10,11, 12,13,14,15, 16,24,28,31, 87,96,98,99};
// exclude ones which use otherpar here: 86, 89, 95, 100 - but we could use dac for otherpar

// what are new modes since we made these lists? beyond 82/101 -> 84->112

//25,26,27,71,72,73,74,  also mixes of DAC/ADC in adcetc and in modeN to port from INTmodes/DONE  =7  - we need more
// 75 dac as comp, 77,78,79,daccontrolsosc, 86cutfeedback, 88cv>dac, 91?, 105TM

// new stream test

/*
void adc0S(uint8_t w){ // basic ADC in with XOR route in
  ADCSTREAMXORIN(4);
}
*/

// streams for sequential entry of bits into each register

void stream(uint8_t w){ // sequential 12 bit in - use also for L, R, N
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=adcpadbits(11);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

//////////////////////////////////////
// how to draft new experimental mode from notebook 25/3/2022 - that we want full speed mirror

// not so exciting now - as we can't run full speed feedback as feedback is in slower part
// unless run all at fullspeed and copy at slower all but is not the same... TRY!

void adcdraft0(uint8_t w){
  HEADD;
  // run at full speed adc/shift but no gshift - but what about binroute as this one becomes own binroute//mise en abyme
  // eg. basic operation - but does it need its own speed sets?
  gate[w].gshift_=gate[w].gshift_<<1;
  bitn^=adcpadbits(11);
  BINROUTE_;
  gate[w].gshift_+=bitn;
  
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  gate[w].shift_=gate[w].gshift_; /// that one has shift
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// as we can't combine copy of gshift and entry of new bits as we used to have above
void adcdraft1(uint8_t w){
  HEADD;
  gate[w].gshift_=gate[w].gshift_<<1;
  bitn^=adcpadbits(11);
  gate[w].gshift_+=bitn;
  bitn = (gate[w].gshift_>>SRlength[w]) & 0x01; // length can also be independent

  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=adcpadbits(SRlength[w]); // if is just case of bitn we can don't need to copy full register... but
  bitn^=ADC_(w,SRlength[w],3,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BINROUTE_; // route in gshift or insert/mix in ??? but we still need to slow it down...
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// how to run 2 parallel SR (ADC and DAC at different speeds) - but what is the speed of the combinings (faster dictates or just have 2 options)
// also option to slide against each other... or just have final bitn merge - we need param for slide???? which we don't have...
// but what of binroute in?
// also detached for 2nd speed
void adcLparallel(uint8_t w){ //
  int32_t top; static uint32_t lastbitn=0;
  w=4;
  HEADSIND;
  speedf_[w]=logspeed[(CVL[w]>>2)]; // logspeed is already inverted
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  lastbitn=dacpadbits(4); // can be other functions also
  //  BITN_AND_OUTV_; 
  ENDER;
  }
  }
  w=0;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=adcpadbits(4);
  bitn^=lastbitn;
  BITN_AND_OUTV_; 
  ENDER;
  }
  }  
}

void adcLparallel2(uint8_t w){ //
  int32_t top; static uint32_t lastbitn=0;
  HEADSIND;
  w=4;
  speedf_[w]=logspeed[(CVL[w]>>2)]; // logspeed is already inverted
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  lastbitn=adcpadbits(4); // can be other functions also
  //  BITN_AND_OUTV_; 
  ENDER;
  }
  }
  w=0;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=adcpadbits(4);
  BINROUTE_;
  bitn^=lastbitn;
  BITN_AND_OUTV_; 
  ENDER;
  }
  }  
}



//??TODO:
// or eg. NSR and RSR slide against each other with offset, no BINroute
// well RSR slides into NSR
void adcLdraft2(uint8_t w){ // detach
  int32_t top;
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
}

//

//////////////////////////// other models

void adcoroute0(uint8_t w){ // basic ADC in with no route in
  ADCXORIN_NOROUTE(0);
}

void adc0nog(uint8_t w){ // basic ADC in with XOR route in and no gshifting <<
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
  HEADD;
  if (speedf_[w]==2.0f) speedf_[w]=LOWEST;
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_; // no shift
  bitn^=ADC_(w,SRlength[w],97,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  //  BINROUTE_; // or no route in here
  BITN_AND_OUTVNOSHIFT_; // no shift
  ENDER;
  }
  else {
    // route in and shift
    GSHIFT_;
    BINROUTEANDCYCLE_; // or we can try with no route in so peters out, or with circular route
    // JUSTCYCLE_
    gate[w].shift_+=bitn;
  }
}

void adc98adcordac(uint8_t w){ // only pull in on speed otherwise route 
  HEADD;
  if (speedf_[w]==2.0f) speedf_[w]=LOWEST;
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_; // no shift
  bitn^=ADC_(w,SRlength[w],98,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  //  BINROUTE_; // or no route in here
  BITN_AND_OUTVNOSHIFT_; // no shift
  ENDER;
  }
  else {
    // route in and shift
    GSHIFT_;
    BINROUTEANDCYCLE_; // or we can try with no route in so peters out, or with circular route
    // JUSTCYCLE_
    gate[w].shift_+=bitn;
  }
}

void adc32(uint8_t w){ // multiple bits in as case 19 in draftdec // ***
  HEADD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //  bitn^=ADC_(w,SRlength[w],4,trigger[w],reggg,adcpar); // this is now adc mode 4 - we don't use bitn and do spacmask in adc
    bitn^=ADC_(w,SRlength[w],4,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    if (SRlength[inroute[count][w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][w])) >>(lastspac[SRlength[inroute[count][w]]][w]))+ \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))          >> ((lastspac[SRlength[inroute[count][w]]][1]) - spacc[SRlength[w]][w]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))         >>((lastspac[SRlength[inroute[count][w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))         >>((lastspac[SRlength[inroute[count][w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][w]))>>(lastspac[SRlength[inroute[count][w]]][w])) + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))<< ((spacc[SRlength[w]][w]) - lastspac[SRlength[inroute[count][w]]][1]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[inroute[count][w]]][2]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[inroute[count][w]]][3])));
    }
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_; // no pulse ins/outs
    ENDER;
  }    
  }
}

void adc1010(uint8_t w){ // test speed double/skip sample
  ADCXORIN(1010);
}

//////////////////////////////////////////////////
// abstracts

void adc28(uint8_t w){ 
  ADCXORIN(28);
}

void adc29(uint8_t w){ // 1 bit oscillator
  ADCXORIN(29);
}

void adc30(uint8_t w){
  ADCXORIN(30);
}

// TODO: can also be other abstract modes (but how to select these), can detach and select strobemodes
void adcflip(uint8_t w){ // full speed 1/0 flipflop and fake strobe - TODO: fake strobe can also be used for other strobe modes...
  static uint32_t flipflop=0;
  flipflop^=1;
  gate[w].trigger=flipflop;
  ADCXORIN(28);
}

//////////////////////////////////////////////////

// no adc
void adcnone(uint8_t w){ //no adc at ALL
  ADCXORIN(64);
}

void adcnonenone(uint8_t w){ //no adc at ALL no routein
  ADCXORIN_NOROUTE(64);
}


void adc8(uint8_t w){ 
  ADCXORIN(8);
}

void adc9(uint8_t w){
  ADCXORIN(9);
}

void adc10(uint8_t w){
  ADCXORIN(10);
}

void adc11(uint8_t w){ 
  ADCXORIN(11);
}

void adc12(uint8_t w){
  ADCXORIN(12);
}

void adc13(uint8_t w){
  ADCXORIN(13);
}

void adc14(uint8_t w){ 
  ADCXORIN(14);
}

void adc15(uint8_t w){
  ADCXORIN(15);
}

void adc16(uint8_t w){
  ADCXORIN(16);
}

void adc17(uint8_t w){ 
  ADCXORIN(17);
}

void adc18(uint8_t w){
  ADCXORIN(18); // otherpar?
}

void adc19(uint8_t w){ 
  ADCXORIN(19);
}

void adc20(uint8_t w){ // comparator mode with clock as param[w] always
  ADCXORIN(20);
}

void adc75(uint8_t w){ // comparator mode with other dac as param // ***
  ADCXORIN_NOROUTE(75);
}

void adc76(uint8_t w){ // comparator mode with OWN dac as param 
  ADCXORIN(76);
}

void adc21(uint8_t w){
  ADCXORIN(21);
}

void adc81_4bits(uint8_t w){ // 4 bits in *** - no length effect so we can detach///
  //    ADCXORIN_NOROUTE(81);
      ADCXORIN(81);
}

void adc87_4bits_strobein(uint8_t w){ // 4 bits in *** STROBE
  //  ADCXORIN_NOROUTE(81);
    ADCXORIN(87);
}

void adc82(uint8_t w){ // comparator as incoming bit ***
  ADCXORIN_NOROUTE(82);
}

// DAC etc

void adc77(uint8_t w){ // dac oscillator
  ADCXORIN(77);
}

void adc78(uint8_t w){ // dac oscillator
  ADCXORIN(78);
}

void adc79(uint8_t w){ // dac oscillator swopped
  ADCXORIN(77);
}

void adc80(uint8_t w){ // dac oscillator swopped
  ADCXORIN(78);
}

void adc22(uint8_t w){ 
  ADCXORIN(22);
}

void adc23(uint8_t w){
  ADCXORIN(23);
}

void adc24(uint8_t w){ 
  ADCXORIN(24);
}

void adc25(uint8_t w){
  ADCXORIN(25);
}

void adc26(uint8_t w){
  ADCXORIN(26);
}

void adc27(uint8_t w){ // testing no route in for DAC as we use DAC
  ADCXORIN_NOROUTE(27);
}

void adc31(uint8_t w){ 
  ADCXORIN(31);
}

///////////////////////////////////////////

//DACS:

// adc in
void adc66(uint8_t w){ // mixes with dac
  ADCXORINdac(66);
}

// adc in
void adc67(uint8_t w){ // mixes with dac
  ADCXORINdac(67);
}

// adc in
void adc68(uint8_t w){ // mixes with dac
  ADCXORINdac(68);
}

// -  new ADC modes: 71, 72, 73, 74 
void adc71(uint8_t w){ // dac in equivalent bits: we don't need limit on number of bits
  ADCXORIN_NOROUTE(71);
}

void adc72(uint8_t w){  // dac in basic sequential length as in 0 but with padding if >11 bits **
  ADCXORIN(72);
}

void adc73(uint8_t w){  // dac in special case for spaced bit entry depending on length
  ADCXORIN(73);
}

void adc74(uint8_t w){ // dac in basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
  ADCXORIN(74);
}

void adc96(uint8_t w){ // strobe 4 bits straight in - no bt in any case
  ADCXORINX(96); // we dont add bt but do shift - BITN_AND_OUTVOSHIFT
}

void adc108(uint8_t w){ // adc fixed 12 bits with 2s complement
  ADCXORIN(108);
}

void adc109(uint8_t w){ // adc with 2s complement
  ADCXORIN(109);
}

void adc110(uint8_t w){ // adc fixed 12 bits with ONEs complement
  ADCXORIN(110);
}

void adc111(uint8_t w){ // adc  with ONEs complement
  ADCXORIN(111);
}

void adc112(uint8_t w){ // dac  with ONEs complement
  ADCXORIN(112);
}



//////////////////////////////////////////////////////////////////////////////////////////////////ROUTE MODES

// maybe these work best in L/R modes
// TODO: just bump within a restricted range or array which make sense?
void adcbumproute0(uint8_t w){ // trigger bumps up our local route - add one to this (what value) - gate[w].route
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }  
}

//TODO: could also use trigger for ADC in
void adcbumproutebin0(uint8_t w){ // incoming binroute bumps up our local route - add one to this (what value) - gate[w].route
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }  
}


void adcghostroute0(uint8_t w){ // but which ghost? our own moved on by 1? so here is default of 1...
  // so what we route int
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }  
}

void adcDACroute0(uint8_t w){ 
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }  
}

void adcSRroute0(uint8_t w){ 
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }  
}

void adcDACroutestrobe0(uint8_t w){ // dacroute with strobe
  // strobe can also select adc in, or choose adc/routed
  HEADD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }  
}

//////////////////////////////////////////////////////////////////////////////////////////////////STROBEE MODES

/*
STROBE PROB MODES - could also be toggles
STROBE - 1invert ADC BIT - XOR/OR routed
       - 2ADC BIT vs routed - NONE
       - 3ADC BIT vs [ADC/xor/or/routed] - NONE
*/

// TODO/detached strobes with sel but need to choose which ones... or sel bits
/* generic sets:

- bits for choice of adc: 4 bits = 16 options
- bits for trigger we have 6 options: maybe 4 options and split; 2 bits 

 */

void adcstrobe1_0(uint8_t w){ 
  HEADD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (gate[w].trigger) bitn=!bitn;
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}

void adcbin1_0(uint8_t w){ 
  HEADD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    val=bitn;
    bitn=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (val) bitn=!bitn;
   BITN_AND_OUTV_;
    ENDER;
  }
  }
}

void adcstrobe2_0(uint8_t w){ // basic ADC in - strobe= bitn or route
  HEADD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (gate[w].trigger)    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    else BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}

void adcstrobe3_0(uint8_t w){ // basic ADC in - see above table - 3ADC BIT vs [ADC/xor/or/routed] - NONE
  HEADD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (gate[w].trigger) BINROUTE_; // or vice versa
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}

// and this set is additionally only for abstract ADCs in
// which can include DACs in... 22-31

/*
  4- ADC bits vs RETURNbit - XOR/OR routed
  5- ADC bits vs [routed/xor/or/RETURbit]
  6- ADCBIT xor routed vs returnbit
*/

//////////// detached strobes=x modes

void adcLstrobe1(uint8_t w){ 
  uint8_t bits, bitss;
  HEADSIND; // detach length
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
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
    ENDER;
  }
  }
}

void adcLstrobe2(uint8_t w){ // 2nd version covering abstract modes and returns - check adc selection TODO
  uint8_t bits, bitss;
  HEADSIND; // detach length
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
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
    ENDER;
  }
  }
}

void adcstrobe4_29(uint8_t w){ 
  HEADD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],29,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    if (gate[w].trigger) JUSTCYCLE_;
    BINROUTE_; 
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}


void adcstrobe5_29(uint8_t w){ 
  HEADD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (!gate[w].trigger) bitn^=ADC_(w,SRlength[w],29,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    else {
      BINROUTEANDCYCLE_;
    }
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}

void adcstrobe6_29(uint8_t w){  // 6- ADCBIT xor routed vs returnbit
  HEADD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (!gate[w].trigger) { bitn^=ADC_(w,SRlength[w],29,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
      BINROUTE_;
    }
    else JUSTCYCLE_;
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// detached modes:  modes ++
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// - if CV>DAC - entry of new bit from [ADC, route or cycle] XOR cycle/route etc... - use what for this choice of route - detached
// using 88 in adcetc.h and with otherpar as new bit

void adcLCVDACroute(uint8_t w){ // CV: 4 bits for route in...
  // 
  uint32_t tmpp=0, which;				       
  HEADSIND;  
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
}

// ported/porting from modeL - but no adc selection possible
void adcmultiplespeednew0(uint8_t w){ // NO LENGTH - try 4 speeds as above - multiple versions of this // this one is ****
  // can we have bits to select combinations for the 4 options splitspeed???
  // trigger: 1,2,3,4 2 bits
  // counter1: 2 bits
  //counterd: 2 bits - but all can only do one...
  //speedf (does interpol but can have no interpol version with BITN_AND_OUTVINT_) 
  
  HEADSIND; // detach length

  if (gate[w].trigger) GSHIFTNOS_; // 2.copy gshift on trigger

  if (counter[w]>gate[dacfrom[daccount][w]].dac){ //3.advance incoming ghost
    counter[w]=0;
    BINROUTEADV_;
  }

  if (counterd[w]> CVL[w]){
      counterd[w]=0;
    gate[w].shift_=gate[w].shift_<<1; // 1. shifter
  }
  
  if (speedf_[w]!=2.0f){ // 4.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    //    gate[w].shift_=gate[w].shift_<<1; // but no shift makes odd with add... anyways
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);
    BINROUTENOG_; // no gshifty
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}

void adcLdoublelength(uint8_t w){   // DETACH LENGTH
  uint8_t tmplength;
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    tmplength=63-(CVL[w]>>6); // 0-63=6bits

    if (tmplength<32) { // as usual
      if (tmplength<3) tmplength=3;
      SRlength[w]=tmplength;
      GSHIFT_;
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
      gate[w].extrashift_=gate[w].extrashift_<<1;

      SRlength[w]=tmplength-32; // fixed 18/3
      gate[w].extrashift_+=gate[w].shift_>>31; // top bit shift in
      gate[w].shift_=gate[w].shift_<<1;

      bitn^=ADC_(w,SRlength[w],81,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // use 4 bits in!
      BINROUTE_;      
    }
    
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

/*
void adcLproto(uint8_t w){
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }
*/

// TODO: can also be other abstract modes (but how to select these), can detach and select strobemodes
/*
void adcflip(uint8_t w){ // full speed 1/0 flipflop and fake strobe - TODO: fake strobe can also be used for other strobe modes...
  static uint32_t flipflop=0;
  flipflop^=1;
  gate[w].trigger=flipflop;
  ADCXORIN(28);
}
*/
void adcLflip(uint8_t w){ // select strobemode (we have 20 but just 16 now) - as above
  HEADSIND;
  static uint32_t flipflop=0;
  flipflop^=1;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  bitn^=ADC_(w,SRlength[w],strobemodes[CVL[w]>>8],flipflop,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }


void adcLstrobe(uint8_t w){ // select strobemode (we have 20 but just 16 now)
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  bitn^=ADC_(w,SRlength[w],strobemodes[CVL[w]>>8],gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void adcLbinrstr(uint8_t w){ // route in as strobe: select strobemode (we have 20 but just 16 now)
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTENOS_;
  bitn=ADC_(w,SRlength[w],strobemodes[CVL[w]>>8],bitn,dacfrom[daccount][w],param[w], &gate[w].shift_);
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }



/// exp mode - some of these are more like route modes - which decide route rather than ADCs
// so we could use in LSR
void adcLbitprob(uint8_t w){
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  tmp=CVL[w];
  val=ADC_(w,SRlength[w],113,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_);
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
  ENDER;
  }
  }
  }

// TODO: can be different adc generators>independent ones... - abstract ones would need extra param which we don't have - unless we strobe
void adcLbinprob(uint8_t w){ // binroute in as prob of entry of new bit from adc or cycle
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
  }

// do as a INTmode with 2 params//
void adcintbinprob(uint8_t w){ // INTmode 0 no interpolation and no use of CV
  HEADSSINNADAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    val=CVL[w]>>8; // 4 bits 
  ///////HERE
  BINROUTENOS_;
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
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  BINROUTENOS_;
  if (bitn)      {
    bitn=0;
    GSHIFT_;
    JUSTCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
    ENDER;
  }
  }
  }
}

// or binroute is only bit in speedcycle

void binnospeedcycle(uint8_t w){ // no speed set
  HEADSIN;
  BINROUTENOS_;
  if (bitn)      {
    bitn=0;
    GSHIFT_;
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
  HEADSSINNADAD;
  uint32_t depth;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  tmp=CVL[w]>>6; // 4 bits + 2 now - 6 bits
  depth=CV[w]; // 12-> 5 bits below
  if (tmp&0x01)  bitn=(*abstractbitstreams[tmp>>2])(depth,w);
  else bitn=(*abstractbitstreamsI[tmp>>2])(depth,w);
  if (tmp&0x02){    
    BINROUTE_;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void adcLabstractNOG(uint8_t w){ // abstract modes with option now binroute or not - no bitoruteGshift option
  HEADSSINNADAD;
  uint32_t depth;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
  }


void adcLabstractLD(uint8_t w){ // abstract modes with option now binroute or not - now with length=depth so we have speed
  HEADSIND;
  uint32_t depth;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  ///////HERE
  tmp=CVL[w]>>6; // 4 bits + 2 now - 6 bits
  if (tmp&0x01)  bitn=(*abstractbitstreams[tmp>>2])(SRlength[w],w);
  else bitn=(*abstractbitstreamsI[tmp>>2])(SRlength[w],w);
  if (tmp&0x02){    
    BINROUTE_;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// independent abstract modes now
void adcLabstractI(uint8_t w){ // just to test abstract modes - could be used but we lose speed and wastes bits - detached both
  HEADSSINNADAD;
  uint32_t depth;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w]>>8; // 4 bits
  depth=CV[w]; // 12-> 5 bits below
  bitn=(*abstractbitstreamsI[tmp])(depth,w);
  BINROUTE_; // or not?
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void adcLabstractQIN(uint8_t w){ // abstract modes select IN? again we lose speed and bits
  HEADSSINNADAD;
  uint32_t depth;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
  }

//*eg. stream->selectTM, WIARD, EN - stream can also be probability 1 or 0 yes/no -> and we should record our probs/anydecisions to play back!*
//  bt = (gate[reg].Gshift_[reg]>>length) & 0x01; 
//    if (k[reg]>(LFSR_[reg]&4095)) bt=!bt;
// also has TM in TM as we have that mode in altabstract - could also run just with that and free up one CV!
void adcLTMinTM(uint8_t w){ // abstract modes select IN? again we lose speed and bits DETACH length - TM in TM
  HEADSIND;
  uint32_t depth;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
  }

void adcLabstractTM(uint8_t w){ // abstract modes select IN? again we lose speed and bits DETACH BOTH
  HEADSSINNADAD;
  uint32_t depth;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
  }

////////////////////////////////////////

void adcLFROM(uint8_t w){  // FROM? - we use both params - can also be detached strobe modeTODO
  HEADSSINNADAD;
  uint32_t depth, tmpp;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
  }


void adcLmix0(uint8_t w){
  float pp,mult;
  uint32_t k;
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  mult=mixer[CVL[w]>>2]; // 10 bits - 0 is 1.0f so full dac
  //    mult=0.0f;
  ADCgeneric;
  pp=(float)(k *  (1.0f-mult)) + ((float)(gate[2].dac)*mult); // mix with param
  //    //    pp=(float)(adc_buffer[12]*(1.0f-mult)+((float)(gate[3].dac)*mult); // mix with param - optional
  tmp=(int)pp;
  if (tmp>4095) tmp=4095;
  bitn^=ADCg_(0, SRlength[w], 7 , &gate[w].shift_, tmp);  //??? 4 bits for type  66=modulo, 67=add, 68=and
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void adcLmix1(uint8_t w){
  float pp,mult;
  uint32_t k;
  uint32_t tmpp;
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
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
  ENDER;
  }
  }
  }


void adcLpattern95(uint8_t w){   // DETACH LENGTH and select one of 16 patterns insert on strobe
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>8); //4 bits
  bitn^=ADC_(w,SRlength[w],95,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_); 
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLpatternbin95(uint8_t w){   // DETACH LENGTH and select one of 16 patterns insert on strobe
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_;
  tmp=(CVL[w]>>8); //4 bits
  bitn=ADC_(w,SRlength[w],95,bitn,dacfrom[daccount][w],tmp, &gate[w].shift_); 
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}



void adcLtm101(uint8_t w){   // DETACH LENGTH and use CVL for classic TM
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],101,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_; // route in or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLtm102(uint8_t w){   // DETACH LENGTH and use CVL for classic TM
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],102,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_; // route in or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLtm103(uint8_t w){   // DETACH LENGTH and use CVL for classic TM
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],103,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_; // route in or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLtm104(uint8_t w){   // DETACH LENGTH and TM in TM
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],104,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_; // route in or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLtm105(uint8_t w){   // DETACH LENGTH and use CVL for classic TM with DAC
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],105,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  //  BINROUTE_; // route in or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}



void adcLcomp20(uint8_t w){   // DETACH LENGTH - comparator 12 bits
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],20,gate[w].trigger,dacfrom[daccount][w],CVL[w], &gate[w].shift_); 
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLsub92(uint8_t w){   // DETACH LENGTH - subtract 12 bits
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],92,gate[w].trigger,dacfrom[daccount][w],4095-CVL[w], &gate[w].shift_); 
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLsplice100(uint8_t w){   // DETACH LENGTH - splice in 4 bits at position
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],100,gate[w].trigger,dacfrom[daccount][w],31-(CVL[w]>>7), &gate[w].shift_); 
  BINROUTE_;
  BITN_AND_OUTV_;//OSHIFT_; //  ADCXORINX(96); // we dont add bt but do shift - BITN_AND_OUTVOSHIFT
  ENDER;
  }
  }
}




/* bursts of DACin/ADCin to spawn/seed feedback - so trigger
  means CV length of ADC bits in, no trigger is ROUTEin at otherCV
  speed, or all at cv speed
*/
void adcLBURST0(uint8_t w){ 
  // DETACH LENGTH
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (gate[w].trigger){
    train[w]=1;
  }
  if (train[w]!=0 && train[w]< (1024-(CVL[w]>>2))){
  train[w]++;
  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  }
  else {
    train[w]=0;
    BINROUTE_;
  }
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc(uint8_t w){ // select ADC 0-31 ***
  // DETACH LENGTH
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLcutfeedback86(uint8_t w){ //    //    TODO/TEST: *cut feedback between dacs 1 and 3 - eg. cut for CV count clk pulses/on off* STROBE
  // DETACH LENGTH
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>2); // 10 bits - how many bits works best?
  bitn^=ADC_(w,SRlength[w],86,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_); 
  //  BINROUTE_; // TODO: route in or not - 2 versions
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc1(uint8_t w){ // select ADC 0-63 - preferred modes with param[w] as param   // DETACH LENGTH
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=(CVL[w]>>6); // 6 bits = 64 or we can have a list of preferred modes TODO !!!
  bitn^=ADC_(w,SRlength[w],seladc[tmp],gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladc2(uint8_t w){ // speed from cv, cvl as type and dac as param   // DETACH LENGTH
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],parammodes[CVL[w]>>8],gate[w].trigger,dacfrom[daccount][w], gate[dacfrom[daccount][w]].dac, &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

////////////////////////////////
//5th tails - trials
void adcLseladc5th(uint8_t w){ // speed from cv, cvl as type and TAIL5 as param   // DETACH LENGTH - parammodes
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],parammodes[CVL[w]>>8],gate[w].trigger,8, gate[8].dac, &gate[w].shift_);  // or vice versa and route in 8/5th tail
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLseladcdac5th(uint8_t w){ // speed from cv, cvl as type and TAIL5 as param   // DETACH LENGTH - dacmodes
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],dacmodes[CVL[w]>>8],gate[w].trigger,8, gate[8].dac, &gate[w].shift_);  // or vice versa and route in 8/5th tail
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// trial for dacspeed from 8
void adcdacmod5th(uint8_t w){ // was adcdacmod0
  HEADD;
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeed[(gate[8].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);  // detach and select TODO
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}


////////////////////////////////////

void adcLpulse89(uint8_t w){ // test 89 impulse  // DETACH LENGTH
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn^=ADC_(w,SRlength[w],89,gate[w].trigger,dacfrom[daccount][w], CVL[w]>>2, &gate[w].shift_); // or we can use adcchoice to fill in
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}


void adcLSRlengthsel(uint8_t w){ //use other SR bits to determine length of SR, eg. can be modded or...*   // DETACH LENGTH
  // in this case we select ADC as above and use SR as length 
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {

    tmp=gate[dacfrom[daccount][w]].shift_&31;    
    SRlength[w]=lookuplenall[tmp]; // 5 bits

    GSHIFT_;
  tmp=(CVL[w]>>7); // 5 bits = 32
  bitn^=ADC_(w,SRlength[w],tmp,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  //  BINROUTE_; // with or without route in
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

// adc0
void adcLSRlengthsel0(uint8_t w){ //use other SR bits to determine length of SR, eg. can be modded or...*   // DETACH LENGTH
  HEADSIND;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {

    tmp=gate[dacfrom[daccount][w]].shift_&15;    
    SRlength[w]=lookuplenall[tmp%((CVL[w]>>7)+1)]; // 5 bits
    //    SRlength[w]=lookuplenall[CVL[w]>>7]; // 5 bits
    GSHIFT_;

  bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_); // or we can use adcchoice to fill in
  //  BINROUTE_; // with or without route in // ***
  if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void adcLLswop0(uint8_t w){ // swop in or logop SR - cv and cvl- not so good for Nmode   // DETACH LENGTH/SPEED
  uint32_t lin, lout;
  HEADSSINNADAD;

  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
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
    ENDER;
  }
  }
}



void adcgenericprobx(uint8_t w){ // porting to strobe - ported to N - detach CVL - length to select ADC // DETACH LENGTH
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADSIND;  

  if (speedf_[w]!=2.0f){ 
    CVOPEN;

    GSHIFT_;
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
    ENDER;
} 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CV and DAC modes - move these to LR! ??? how many? 12 here
/*

refine and figure out dac modes as dac is too fast

 */

// so far we have 7 modes and all just use adc mode 0 so this needs to be trimmed - DAC modes also more suited for abstract modes
// can also have BINROUTE in or not???

void adcdacadditself0(uint8_t w){ // tested//trial itself as DAC - can also be other variants TODO
  HEADD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[w].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacghostitself0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[w]//gate[x].Gshift_[w]
  HEADD;
  float speedf__;
  speedf__=logspeedd[(CV[w]&511)+((gate[w].Gshift_[routeto[count][w]])&511)];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacghostincoming0(uint8_t w){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[w]//gate[x].Gshift_[w]
  HEADD;
  float speedf__;
  speedf__=logspeedd[(CV[w]&511)+((gate[w].Gshift_[inroute[count][w]])&511)];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}


// DONE: top bits of CV/speed select which DAC to take from - implement and test this, but we need access to bits/CV and smoothed
// but for ADC in is probably best just to have fixed DAC as 3

void adcdacseladd0(uint8_t w){
  HEADD;
  float speedf__;
  uint8_t whic=(CV[w]>>9)&3; //12 bits -> 2 bits
  speedf__=logspeedd[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// what of +- and centre so is not just all add... so -2048
void adcdacseloffosc(uint8_t w){ // ADC_ is offset, and cv is amount of dac / TEST! or vice versa as we have no knob for adc_
  HEADD;
  float speedf__;
  //  uint8_t whic=(CV[w]>>9)&3; //12 bits -> 2 bits
  int32_t off;
  tmp=(gate[3].dac)%(4095-CV[w]);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  off=(2048-ADC_GetConversionValue(ADC1));
  tmp+=off;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeedd[tmp];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);  // 1  bit oscillator
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacseloffosc2(uint8_t w){ // ADC_ is offset, and cv is amount of dac / TEST! or vice versa as we have no knob for adc_HERE
  HEADD;
  float speedf__;
  //  uint8_t whic=(CV[w]>>9)&3; //12 bits -> 2 bits
  int32_t off;

  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  tmp=(gate[3].dac)%(ADC_GetConversionValue(ADC1));
  off=(2048-CV[w]);
  tmp+=off;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeedd[tmp];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_);  // 1  bit oscillator
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

//SRN: speed from SRR, data from SRL - new route XOR with loopback: rung
void adcLrung0(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL
  HEADSSIND;
  float speedf__;
  int32_t off;

  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  tmp=(gate[3].dac)%(ADC_GetConversionValue(ADC1));
  off=(2048-CV[w]);
  tmp+=off;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeedd[tmp];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=CVL[w]>>8;
    bitn^=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,2, param[w], &gate[w].shift_);  // from leftDAC
    //    BINROUTE_; // did have this but try now with:
    JUSTCYCLE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcLrung1(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL
  HEADSSIND;
  float speedf__;
  int32_t off;

  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  tmp=(gate[3].dac)%(ADC_GetConversionValue(ADC1));
  off=(2048-CV[w]);
  tmp+=off;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeedd[tmp];
  //  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    tmp=CVL[w]>>8;
    bitn^=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,2, param[w], &gate[w].shift_);  // from leftDAC
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
  HEADSSIND;
  float speedf__;
  //  uint8_t whic=(CV[w]>>9)&3; //12 bits -> 2 bits
  int32_t off;

  tmp=(gate[1].dac)%(CVL[w]); // now speed from L and data from C as that is usual route
  off=(2048-CV[w]);
  tmp+=off;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeed[tmp];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,2, param[w], &gate[w].shift_);  // adc in or not
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

// no DETACH. speed is from left side...
// what are all variations of rung! for each side
void adcrung0(uint8_t w){ // rung: use CVL[w]>>8 to select 1 of 16type DAC input from SRL
  HEADD;
  float speedf__;
  int32_t off;

  ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles);
  ADC_SoftwareStartConv(ADC1);
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
  tmp=(gate[1].dac)%(ADC_GetConversionValue(ADC1));
  off=(2048-CV[w]);
  tmp+=off;
  tmp=tmp>>2; // 10 bits
  if (tmp>1023) tmp=1023;
    //  speedf__=logspeed[(CV[w]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  speedf__=logspeed[tmp];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //    tmp=CVL[w]>>8;
    //    bitn^=ADC_(w,SRlength[w],dacmodes[tmp],gate[w].trigger,2, param[w], &gate[w].shift_);  // from leftDAC
    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}


void adcdacadd0(uint8_t w){
  HEADD;
  float speedf__;
  speedf__=logspeed[(CV[w]&511)+(gate[speedfrom[spdcount][w]].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacaddmax0(uint8_t w){ // REMOVE?
  HEADD;
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)+(gate[speedfrom[spdcount][w]].dac>>2);
  if (cv>1023) cv=1023;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacminus0(uint8_t w){
  HEADD;
  int32_t cv;
  float speedf__;
  cv=(gate[speedfrom[spdcount][w]].dac>>2)-(1024-(CV[w]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacspeedminus0(uint8_t w){
  HEADD;
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)-(gate[speedfrom[spdcount][w]].dac>>2); 
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacmod0(uint8_t w){
  HEADD;
  int32_t cv;
  float speedf__;
  cv=((CV[w]>>2)+1); // modulo code
  speedf__=logspeed[(gate[speedfrom[spdcount][w]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w], param[w], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacB0(uint8_t w){// with oscillator
  HEADD;
  int32_t cv;
  float speedf__;
  cv=(CV[w]>>2)-(gate[speedfrom[spdcount][w]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcdacoffset0(uint8_t w){
  float speedf__;
  float mmm=(float)(1024-(CVL[w]>>2))/1024.0f;
  HEADSIND;
  tmp=(1024-(CV[w]>>2)) + (int)((float)(gate[speedfrom[spdcount][w]].dac>>2)*mmm);
  if (tmp>1023) tmp=1023;
  speedf__=logspeed[tmp]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void adcLdacadc(uint8_t w){ // speed is from dac, use cv to select type and cvl as parameter - but just for param modes
  // or as intmode: variations of this
  HEADSSINNADAD;
  int32_t cv;
  float speedf__;
  cv=(gate[speedfrom[spdcount][w]].dac>>2);
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],parammodes[CV[w]>>8],gate[w].trigger,dacfrom[daccount][w], CVL[w], &gate[w].shift_); // 4 bits
    // what of some modes where we have 4095-CV[w] - should this be in adc or live with it
    //    BINROUTE_;
    if (!strobey[w][mode[w]]) bitn=bitn|gate[w].trigger; // ??
    BITN_AND_OUTV_;
    ENDER;
  }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INTMODES - here there are: 44

// there are only 16... and we want also abstract adc in/prob modes so we need to reduce prob modes
// reduced adc modes and some abstract

void adcint0(uint8_t w){ // INTmode 0 no interpolation and no use of CV
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

// intmodes which use speedCV - CV[w] - 12 bits smoothed
// these are otherparmodes: 17,18,19,21,22 (20 and 29 we have here) - check range of params as can be quite small for size
// 17:?,18:&31,19:&31,21:>>2



void adcintcomp20(uint8_t w){ //CV comparator //  case 20: // CVotherpar as comparator - 10 bits standard here // now 12 bits  - OTHERPAR! 12 bits
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],20,gate[w].trigger,dacfrom[daccount][w],(4095-CV[w]), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcintsub92(uint8_t w){ //subtract CV //  case 92: 
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],92,gate[w].trigger,dacfrom[daccount][w],(4095-CV[w]), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}


void adcint17(uint8_t w){ //  case 17: // otherpar as timed adc entry
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],17,gate[w].trigger,dacfrom[daccount][w],(CV[w]>>4), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcint18(uint8_t w){ //  case 18: // otherpar as CV
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],18,gate[w].trigger,dacfrom[daccount][w],31-(CV[w]>>7), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcint19(uint8_t w){ //  case 19: // otherpar as CV
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],19,gate[w].trigger,dacfrom[daccount][w],31-(CV[w]>>7), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcint32(uint8_t w){ //  case 32-new tests - adc xor with dac: // otherpar as CV
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],32,gate[w].trigger,dacfrom[daccount][w],31-(CV[w]>>7), &gate[w].shift_); 
    //    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcint21(uint8_t w){ //  case 21 oscillator: // otherpar as CV - REDONE TEST - detach
  HEADSIND;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,CVL[w]>>2,21,gate[w].trigger,dacfrom[daccount][w],CV[w]>>2, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}


void adcintosc29(uint8_t w){//  case 29:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits DETACH NOW
  // or we freeze length as odd to have both tied together
  HEADSIND;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,(CVL[w]>>2),29,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);  // changing lengths to use CVL
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcintosc34(uint8_t w){//  case 34:// // 1 bit oscillator - train of length 0 bits followed by y 1 bits  - OTHERPAR! 12 bits
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],34,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}


// prob instead of strobe: 12,13,14,15,16 -> re-worked in ADC_ as 35-39 TESTING/DONE->

void adcint35(uint8_t w){//  case 35
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],35,gate[w].trigger,dacfrom[daccount][w],4095-CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcint36(uint8_t w){//  case 36
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],36,gate[w].trigger,dacfrom[daccount][w],4095-CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcint37(uint8_t w){//  case 37
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],37,gate[w].trigger,dacfrom[daccount][w],4095-CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcint38(uint8_t w){//  case 38
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],38,gate[w].trigger,dacfrom[daccount][w],4095-CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcint39(uint8_t w){//  case 39
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],39,gate[w].trigger,dacfrom[daccount][w],4095-CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

// no adc in
void adcint65(uint8_t w){// was strobe mode for cycling bits a la TM - no input but now uses otherpar as probability! - is also as int65 now...
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],65,gate[w].trigger,dacfrom[daccount][w],4095-CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

// adc in
void adcint66(uint8_t w){ // mod // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[w]* intmodes
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],66,gate[w].trigger,dacfrom[daccount][w],4095-CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

// adc in
void adcint67(uint8_t w){ // as above add // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[w]* intmodes
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],67,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

// adc in
void adcint68(uint8_t w){ // mod // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[w]* intmodes
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],68,gate[w].trigger,dacfrom[daccount][w],4095-CV[w], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

// now using ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR, uint32_t *income)
// generic one with 7 modes so all is outside - and we can use 3 bits to select the type of adc_ 7 bits total
// so there can be 3 versions with different additives 71,72,73
// ****
// now 3 bits type, 2 bits which
void adcint71(uint8_t w){
  uint32_t k;
  uint8_t tmpp;				       
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    gate[dacfrom[daccount][w]].dactype=15-(CV[w]>>8);     // 4 top bits for type 0- was [1] why? and where we set this back
    tmpp=(CV[w]>>10); // 2 bits;
    //    tmp=adc_buffer[12]+gate[tmpp].dac; // additive can be otherwise
    ADCgeneric;
    tmp=k%gate[3].dac; // was + but not always working
    if (tmp>4095) tmp=4095;
        bitn^=ADCg_(0, SRlength[w], (7-(7&(CV[w]>>7))), &gate[w].shift_, tmp);  // 4 bits for type  66=modulo, 67=add, 68=and ???
    //    bitn^=ADCg_(0, SRlength[w], 0, &gate[w].shift_, tmp);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case but could be
    BITN_AND_OUTVINT_; 
  } 
}

void adcint72(uint8_t w){ // as above but how can we do mix of adc/dac according to CV, but then we lose CV - also for detached modes TODO
  float pp,mult;
  uint32_t k;
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    gate[dacfrom[daccount][w]].dactype=15-(CV[w]&15); // lowest bits
    // leaves us (CV[w]>>4)&255 to play with
    //    tmp=CV[w]&3;
    //    mult=1.0f/((float)(CV[w]>>8)+1.0f); // changed 24/2 - maybe as LOOKUP TODO
        mult=mixer[CV[w]>>2]; // 10 bits - 0 is 1.0f so full dac
    //    mult=0.0f;
    ADCgeneric;
    pp=(float)(k *  (1.0f-mult)) + ((float)(gate[2].dac)*mult); // mix with param
    //    //    pp=(float)(adc_buffer[12]*(1.0f-mult)+((float)(gate[3].dac)*mult); // mix with param - optional
    tmp=(int)pp;
    if (tmp>4095) tmp=4095;
    bitn^=ADCg_(0, SRlength[w], 7 , &gate[w].shift_, tmp);  //??? 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case but could be
    BITN_AND_OUTVINT_; 
  } 
}

// now mix using DAC[3] as mixer... what to do with rest of CV? this can also be for detached modes - CV used
void adcint72dacmix(uint8_t w){ // as above but how can we do mix of adc/dac according to CV, but then we lose CV - also for detached modes TODO
  // 2 bits for dacsel, 4 bits for which ADCg
  float pp,mult; uint32_t tmpp;
  uint32_t k;
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    gate[dacfrom[daccount][w]].dactype=15-(CV[w]&15); // lowest bits
    // leaves us (CV[w]>>4)&255 to play with
    tmpp=(CV[w]>>6);
    tmp=tmpp&0x03;
    //    mult=1.0f/(float)((gate[tmp].dac)+1.0f); // but if we use 3 below... anyways
    mult=mixer[gate[tmp].dac>>2];
    ADCgeneric;
    //    pp=(float)k+((float)(gate[tmp].dac)*mult); // mix with param
    pp=((float)(k)*(1.0f-mult)) + ((float)(gate[3].dac)*mult); // mix with param - optional
    tmp=(int)pp;
    if (tmp>4095) tmp=4095;
    bitn^=ADCg_(0, SRlength[w], tmpp>>3 , &gate[w].shift_, tmp);  //??? 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case but could be
    BITN_AND_OUTVINT_; 
  } 
}

void adcint84(uint8_t w){ // own dac as comparator against DAC+CV // ***
  // can also detach length and have this as prob mode too
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],84,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    JUSTCYCLE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcLintprob184(uint8_t w){ // own dac as comparator against DAC+CV // ***
  // can also detach length and have this as prob mode too - prob of cycle or ADC. prob of cycle or routein
  HEADSIND;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],84,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);
    if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
    }
    else JUSTCYCLE_;
    BITN_AND_OUTVINT_; 
  } 
}

///////////////////////////////////
// generators - can also be for detached modes
void adcintone(uint8_t w){ // intmode for onebitadc with speed as depth/delay // tested
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    bitn^=ADC_(w,SRlength[w],84,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);
    bitn^=adconebits(CV[w]); // 0-31 5 bits or more >>7 TEST/try
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcintEN(uint8_t w){ // intmode for Electronotes generator
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    bitn^=ADC_(w,SRlength[w],84,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);
    bitn^=ENbits(CV[w],w); // 0-31 5 bits or more >>7 TEST/try
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcintsEN(uint8_t w){ // intmode for simpler Electronotes generator
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    bitn^=ADC_(w,SRlength[w],84,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);
    bitn^=ENsbits(CV[w],w); // 0-31 5 bits or more >>7 TEST/try
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}


// what other bits we could have?
void adcintroute0(uint8_t w){ // CV: 4 bits for route in... other bits for logop
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    // TESTY!
    tmp=255-(CV[w]>>4); // 8 bits
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
    // no binroute needed
    BITN_AND_OUTVINT_; 
  } 
}

// use CVL freed up for probability of bitn entry...
void adcLintroute0(uint8_t w){ // CV: 4 bits for route in... other bits for logop
  HEADSIND; // fixed 24/2  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[w] & 4095 ) < CVL[w])){ // prob of bit in - could also be DAc
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);
    }
    // TESTY!
    tmp=255-(CV[w]>>4); // 8 bits
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
    // no binroute needed
    BITN_AND_OUTVINT_; 
  } 
}


void adcintselADC1(uint8_t w){ // parammodes speed from trigger, cv for selectadc, detach length for param or param as dac
  HEADSIND;  
  if (gate[w].trigger)      {
    val=63-(CV[w]>>6); // 6 bits say
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],parammodes[val>>2],gate[w].trigger,dacfrom[daccount][w],CVL[w], &gate[w].shift_);
    val=(val&0x03);// lowest 2 bits for logop
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=logop(bitn,bitrr,val);
  }
  tmp=tmp>>1;
    }			     
    BITN_AND_OUTVINT_; 
  } 
}

void adcintselADC2(uint8_t w){ // speed from trigger, cv for selectadc, detach length for param or param as dac
  HEADD;  
  if (gate[w].trigger)      {
    val=63-(CV[w]>>6); // 6 bits say
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],parammodes[val>>2],gate[w].trigger,dacfrom[daccount][w],gate[dacfrom[daccount][w]].dac, &gate[w].shift_);
    val=(val&0x03);// lowest 2 bits for logop
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=logop(bitn,bitrr,val);
  }
  tmp=tmp>>1;
    }			     
    BITN_AND_OUTVINT_; 
  } 
}


void adcintselADC_63(uint8_t w){ // use CV to select adc type: only those which don't use CV or strobe LIST:
  // we could also us top bits to do something with? 16 modes=4 bits, top bits logop/route?
  //0,1,2,3,4,5,6,7,8 - adc logical-22,23,25,26,27,30,63,64,65 to test - 27 dies out but...
  //  uint8_t choice[16]={0,1,2,3,4,5,6,7,8, 22, 23, 25, 26, 27, 30, 63};//leave off -inprogress 63,64,65 to test - TODO: expand this with new abstract and dac modes...
  HEADD;  
  if (gate[w].trigger)      {
    val=63-(CV[w]>>6); // 6 bits say
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],modes16[val>>2],gate[w].trigger,dacfrom[daccount][w],0, &gate[w].shift_);
    val=(val&0x03);// lowest 2 bits for logop
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=logop(bitn,bitrr,val);
  }
  tmp=tmp>>1;
    }			     
    BITN_AND_OUTVINT_; 
  } 
}





/* 

probability modes for basic ADCs: [what are basic ADCs?]

check against:

prob modes for ADC/ignore cycling - but some below do use cycling:

- invert ADC bit -and- xor/or in routed - prob3
- invert [ADC/xor/or/routed) 

- select ADC bit in or routed in - prob2
- select ADC bit in or [ADC/xor/or/routed)  - prob1

- select ADC bit in or INVrouted in
- select ADC bit in or INV[ADC/xor/or/routed)  

- prob33 is entry of cycling/ADC - finally XOR with routed in

*prob can also be against DAC rather than LFSR - but always CV against - other prob options in non-int modes*

- check also against prob instead of strobe 35, 36, 37, 38, 39 - these are seperate

other CV driven modes: mix/xor/whatever cv and incoming ADC - in basic modes, CV as routein



*/

/*
void adcintprob33(uint8_t w){ // case 33: where prob of CHOICE of ADC bit or cycling bit - so prob is in ADC_
  // but is more flexible if is outside so we can change modes TODO-below
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],33,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_; // XOR route in?
    BITN_AND_OUTVINT_; 
  } 
}
*/

void adcintprob1_0(uint8_t w){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[w] & 4095 ) < CV[w])){
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    }
    else
      {
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}

void adcintprob2_0(uint8_t w){   // but is more flexible if is outside 
  // prob is choice of ADC or routed in bit only
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);
    if (((LFSR_[w] & 4095 ) > CV[w])){
    BINROUTE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}

void adcintprob3_0(uint8_t w){   // but is more flexible if is outside so we can change modes
  // - prob of invert or not routed in bit XOR/OR with ADC = same as invert ADC bit
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[w] & 4095 ) < CV[w])){
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    bitn=!bitn;
    BINROUTE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}

void adcintprob4_22(uint8_t w){ // prob of adc/X/ORroute or just cycling - just for abstract modes
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[w] & 4095 ) < CV[w])){
    bitn^=ADC_(w,SRlength[w],22,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}

void adcintprob5_0(uint8_t w){ // electronotes draft0 // can also use incoming SR instead of LFSR
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[w] & 4095 ) < CV[w])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[w]&255) & ((CV[w]>>4)&255)) == 255 ){
    
    //    tmp=255-(CV[w]>>4);
    //    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&262144)>>15) + ((LFSR_[w]&16384)>>10) + ((LFSR_[w]&131072)>>12) + ((LFSR_[w]&524288)>>13) + ((LFSR_[w]&2097152)>>14)) | tmp)==255)
    tmp=prub[CV[w]>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255)
      {
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
    BITN_AND_OUTVINT_; 
  } 
}

void adcintprob6_0(uint8_t w){ // electronotes draft0 // use incoming SR instead of LFSR - also no route in *** // can be lfsr against shift also***
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[w] & 4095 ) < CV[w])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[w]&255) & ((CV[w]>>4)&255)) == 255 ){
    // LFSR_[w]->gate[inroute[count][w]].shift_
    //    tmp=255-(CV[w]>>4);
    //    if ( ( ( ((gate[inroute[count][w]].shift_&1)>>0) + ((gate[inroute[count][w]].shift_&4)>>1) + ((gate[inroute[count][w]].shift_&32)>>3) + ((gate[inroute[count][w]].shift_&262144)>>15) + ((gate[inroute[count][w]].shift_&16384)>>10) + ((gate[inroute[count][w]].shift_&131072)>>12) + ((gate[inroute[count][w]].shift_&524288)>>13) + ((gate[inroute[count][w]].shift_&2097152)>>14)) | tmp)==255)
    tmp=prub[CV[w]>>9];
    if ( ( ( ((gate[inroute[count][w]].shift_&1)>>0) + ((gate[inroute[count][w]].shift_&4)>>1) + ((gate[inroute[count][w]].shift_&32)>>3) + ((gate[inroute[count][w]].shift_&16384)>>11) + ((gate[inroute[count][w]].shift_&131072)>>13) + ((gate[inroute[count][w]].shift_&524288)>>14) + ((gate[inroute[count][w]].shift_&2097152)>>15) + ((gate[inroute[count][w]].shift_&8388608)>>16)) | tmp)==255)

      {
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    //    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
    BITN_AND_OUTVINT_; 
  } 
}


void adcintprob7_0(uint8_t w){ // electronotes draft0 - ADC or ROUTEIN
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  HEADD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[w] & 4095 ) < CV[w])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[w]&255) & ((CV[w]>>4)&255)) == 255 ){
    
    //    tmp=255-(CV[w]>>4);
    //    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&262144)>>15) + ((LFSR_[w]&16384)>>10) + ((LFSR_[w]&131072)>>12) + ((LFSR_[w]&524288)>>13) + ((LFSR_[w]&2097152)>>14)) | tmp)==255){
    tmp=prub[CV[w]>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255)
    {
    bitn^=ADC_(w,SRlength[w],0,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    //    BINROUTE_;
    }
    else
      {
	BINROUTE_;
	}
    BITN_AND_OUTVINT_; 
  } 
}

void adcintprobdac1_0(uint8_t w){ // example - as prob1 above but against DAC3
  // prob is choice of ADC or ADC XOR routed in bit
  HEADSIND; // detached fixed 24/2  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    if ((gate[dacfrom[daccount][w]].dac)>CV[w]) {
    BINROUTE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}

// generic prob ported from probability.h
void adcintgenericprob30(uint8_t w){
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADD;  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=ADC_(w,SRlength[w],30,gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);; // route
    prob[1]=bitn; // route
    prob[2]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[3]=0;
    
    // bit is 8 x 3 - 5 bits
    bit=gate[dacfrom[daccount][w]].dac&31; // 5 bits - could also be extra bits for logical ops
    lower=bit&0x03;
    bit=(bit>>2)*3;

    tmp=LFSR_[w]&4095;
    tmpp=CV[w]; // which way round

    if (tmp<tmpp) bitn^=prob[lower]; // lowest 2 bits
    else bitn^=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; 
  } 
}

// generic prob ported from probability.h
void adcLintgenericprob(uint8_t w){ // detach length and use to select ADC
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADSSINNADAD; // we don;t need  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_; 
    prob[0]=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);; // route
    prob[1]=bitn; // route
    prob[2]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[3]=0;
    
    // bit is 8 x 3 - 5 bits
    bit=gate[dacfrom[daccount][w]].dac&31; // 5 bits - could also be extra bits for logical ops
    lower=bit&0x03;
    bit=(bit>>2)*3;

    tmp=LFSR_[w]&4095;
    tmpp=CV[w]; // which way round

    if (tmp<tmpp) bitn^=prob[lower]; // lowest 2 bits
    else bitn^=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; 
  } 
}

void adcLintgenericprobx(uint8_t w){ // TODO: can also be on trigger as CV strobe mode
  // can also reverse so dac is prob and cv is bits
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  uint32_t left[2]={0}; uint32_t right[2]={0};
  HEADSSINNADAD;  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_);; // route
    prob[1]=bitn; // route
    prob[2]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[3]=0;

    left[0]=LFSR_[w]&4095; left[1]=gate[w].Gshift_[w]&4095; 
    right[0]=4095-CV[w]; right[1]=right[w]+(gate[dacfrom[daccount][w]].dac&4095);
    if (right[1]>4095) right[1]=4095;
    // bit is 8 x 3 - 5 bits + 2 bits
    bit=gate[dacfrom[daccount][w]].dac&127; // 2+5 bits //- could also be extra bits for logical ops
    lower=bit&0x03;
    tmp=(bit>>2)&1; // fixed
    tmpp=(bit>>3)&1;
    bit=(bit>>4)*3;

    if (left[tmp]<right[tmpp]) bitn^=prob[lower]; // lowest 2 bits
    else bitn^=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}


/// prob modes for N which split off length and select ADC - ONLY FOR MODEN
// can also comp to dac

void adcLintprob1(uint8_t w){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  HEADSSINNADAD; // we don;t need  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    if (((LFSR_[w] & 4095 ) > CV[w])){
      BINROUTE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}

void adcLintprobdac1(uint8_t w){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  HEADSSINNADAD; // we don;t need  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    if (((DACFROM & 4095 ) > CV[w])){
      BINROUTE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}


void adcLintprob2(uint8_t w){   // but is more flexible if is outside 
  // prob is choice of ADC or routed in bit only
    HEADSSINNADAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[w] & 4095 ) < CV[w])){
    bitn^=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    }
    else
      {
    BINROUTE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}

void adcLintprob3(uint8_t w){   // but is more flexible if is outside so we can change modes
  // - prob of invert or not routed in bit XOR/OR with ADC = same as invert ADC bit
    HEADSSINNADAD;
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn^=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    if (((LFSR_[w] & 4095 ) > CV[w])){
    bitn=!bitn;
      }
    BINROUTE_;
    BITN_AND_OUTVINT_; 
  } 
}

void adcLintprob4(uint8_t w){ // prob of adc/X/ORroute or just cycling - just for abstract modes
  HEADSSINNADAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[w] & 4095 ) < CV[w])){
    bitn^=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
      }
    BITN_AND_OUTVINT_; 
  } 
}

void adcLintprob5(uint8_t w){ // electronotes draft0 // can also use incoming SR instead of LFSR
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  HEADSSINNADAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[w] & 4095 ) < CV[w])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[w]&255) & ((CV[w]>>4)&255)) == 255 ){
    
    /*    tmp=255-(CV[w]>>4);
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&262144)>>15) + ((LFSR_[w]&16384)>>10) + ((LFSR_[w]&131072)>>12) + ((LFSR_[w]&524288)>>13) + ((LFSR_[w]&2097152)>>14)) | tmp)==255)
    */
    tmp=prub[CV[w]>>9];
    if ( ( ( ((LFSR_[w]&1)>>0) + ((LFSR_[w]&4)>>1) + ((LFSR_[w]&32)>>3) + ((LFSR_[w]&16384)>>11) + ((LFSR_[w]&131072)>>13) + ((LFSR_[w]&524288)>>14) + ((LFSR_[w]&2097152)>>15) + ((LFSR_[w]&8388608)>>16)) | tmp)==255)
{
    bitn^=ADC_(w,SRlength[w],(adclist[CVL[w]>>7]),gate[w].trigger,dacfrom[daccount][w],CV[w], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
    BITN_AND_OUTVINT_; 
  } 
}

