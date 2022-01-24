// TOP modes as functions.... ADC/other inputs

/*

 *Some modes should not have any route in - in DACspeeds no DAC in maybe*

Pin down to basic ADC ins, strobe ADC ins, abstract ins and reduce a bit

CVmodes: 16 or 16x2 (OR/XOR) or 32x1 and select on casebycase (all logical ones as XOR maybe, others as mix of OR and XOR)

logical modes: 22-31 which can also have prob of loopback and entry

///maybe no DAC modes in N/C: DACmodes 16: test top bits as selecting which DAC

INTmodes 16 or 32 maybe: use CV as param

///we can also double some of these with OR/XOR

+ across all prob of feedback in ...

*/

// TODO: cut down number of ADC modes so we can have speed bumps maybe
// OR for analogue modes and XOR for digital modes (trial but easily dies on OR!)

#define ADCORIN(X){				\
  uint8_t w=0;					\
  HEADN;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[count][0],param[0], &gate[0].shift_);	\
  BINROUTEOR_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }

// added strobe in binroute
#define ADCXORIN(X){				\
  uint8_t w=0;					\
  HEADN;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[0].last_time<gate[0].int_time)      {	\
  GSHIFT_;								\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[count][0],param[0], &gate[0].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }

#define ADCXORIN_NOROUTE(X){				\
  uint8_t w=0;					\
  HEADN;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[0].last_time<gate[0].int_time)      {	\
  GSHIFT_;								\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[count][0],param[0], &gate[0].shift_);	\
  if (!strobey[0][mode[0]]) bitn|=gate[0].trigger;			\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }




#define ADCXORINdac(X){				\
  uint8_t w=0;					\
  HEADN;						\
  if (speedf_[w]!=2.0f){				\
  CVOPEN;					\
  if(gate[0].last_time<gate[0].int_time)      {	\
  GSHIFT_;								\
  tmp=gate[dacfrom[count][0]].dac;					\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[count][0],tmp, &gate[0].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }

#define ADCXORINdacitself(X){				\
  uint8_t w=0;					\
  HEADN;						\
  if (speedf_[w]!=2.0f){				\
  CVOPEN;					\
  if(gate[0].last_time<gate[0].int_time)      {	\
  GSHIFT_;								\
  tmp=gate[0].dac;					\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[count][0],tmp, &gate[0].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }


// now without any binroute



void Nnoroute0(void){ // basic ADC in with no route in
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    //    BINROUTEOR_;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

// TODO: label these

// 0-31 are all ADC modes XORIN with CVspeed
// TODO: test faster modes and ORin
// templates for 

// 0-7 is basic 8 modes

void N0(void){ // basic ADC in with XOR route in
  ADCXORIN(0);
}

void N1(void){ // equivalent bits
  ADCXORIN(1);
}

void N2(void){ // one bit audio
  ADCXORIN(2);
}

void N3(void){ 
  ADCXORIN(3);
}

void N4(void){ // spaced 4 bits in but we need to route DAC in differently - this is done now in adc_ mode 4
  ADCXORIN(4);
}

void N5(void){ 
  ADCXORIN(5);
}

void N6(void){
  ADCXORIN(6);
}

void N7(void){
  ADCXORIN(7);
}

// try N0-N7 with ADCORIN() - these all fade out

/*
  void Nor0(void){ 
  ADCORIN(0);
  }

  void Nor1(void){ 
  ADCORIN(1);
  }

  void Nor2(void){ 
  ADCORIN(2);
  }

  void Nor3(void){ 
  ADCORIN(3);
  }

  void Nor4(void){
  ADCORIN(4);
  }

  void Nor5(void){ 
  ADCORIN(5);
  }

  void Nor6(void){
  ADCORIN(6);
  }

  void Nor7(void){
  ADCORIN(7);
  }
*/

//////////////////////////////////////////////////

void N8(void){ 
  ADCXORIN(8);
}

void N9(void){
  ADCXORIN(9);
}

void N10(void){
  ADCXORIN(10);
}

void N11(void){ 
  ADCXORIN(11);
}

void N12(void){
  ADCXORIN(12);
}

void N13(void){
  ADCXORIN(13);
}

void N14(void){ 
  ADCXORIN(14);
}

void N15(void){
  ADCXORIN(15);
}

void N16(void){
  ADCXORIN(16);
}

void N17(void){ 
  ADCXORIN(17);
}

void N18(void){
  ADCXORIN(18);
}

void N19(void){ 
  ADCXORIN(19);
}

void N20(void){ // comparator mode with clock as param[0] always
  ADCXORIN(20);
}

void N75(void){ // comparator mode with other dac as param
  ADCXORIN_NOROUTE(75);
}

void N76(void){ // comparator mode with OWN dac as param
  ADCXORIN(76);
}

void N21(void){
  ADCXORIN(21);
}

void N81(void){ // 4 bits in
  ADCXORIN(81);
}



// 22->31 = no ADC IN just LFSR/DAC etc

// which of these could be using a DAC as parameter?

//22-no param, 23/no, 24strobe, 25-27 dac entry, 28strobe, 29-otherpar so can use, 30 1010, 31strobe, 34par
// leaves 29, 34 for dac - TODO in adcetcDONE

void N77(void){ // dac oscillator
  ADCXORIN(77);
}

void N78(void){ // dac oscillator
  ADCXORIN(78);
}

void N79(void){ // dac oscillator swopped
  ADCXORIN(77);
}

void N80(void){ // dac oscillator swopped
  ADCXORIN(78);
}


void N22(void){ 
  ADCXORIN(22);
}

void N23(void){
  ADCXORIN(23);
}

void N24(void){ 
  ADCXORIN(24);
}

void N25(void){
  ADCXORIN(25);
}

void N26(void){
  ADCXORIN(26);
}

void N27(void){ // testing no route in for DAC as we use DAC
  ADCXORIN_NOROUTE(27);
}

void N28(void){ 
  ADCXORIN(28);
}

void N29(void){ // 1 bit oscillator
  ADCXORIN(29);
}

void N30(void){
  ADCXORIN(30);
}

void N31(void){ 
  ADCXORIN(31);
}

// add modes

void N101(void){ // test speed double/skip sample
  ADCXORIN(101);
}

// no adc
void N64(void){ // // was strobe mode for cycling bits a la TM - no input but now uses ADC input as probability! - cvmode
  ADCXORIN(64);
}

// no adc
void N65(void){ // was strobe mode for cycling bits a la TM - no input but now uses otherpar as probability! - can be intmode and cvmode
  ADCXORIN(65);
}

// adc in
void N66(void){ // mixes with dac
  ADCXORINdac(66);
}

// adc in
void N67(void){ // mixes with dac
  ADCXORINdac(67);
}

// adc in
void N68(void){ // mixes with dac
  ADCXORINdac(68);
}

// -  new ADC modes: 71, 72, 73, 74 
void N71(void){ // dac in equivalent bits: we don't need limit on number of bits
  ADCXORIN_NOROUTE(71);
}

void N72(void){  // dac in basic sequential length as in 0 but with padding if >11 bits **
  ADCXORIN(72);
}

void N73(void){  // dac in special case for spaced bit entry depending on length
  ADCXORIN(73);
}

void N74(void){ // dac in basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
  ADCXORIN(74);
}

// maybe these work best in L/R modes
// TODO: just bump within a restricted range or array which make sense?
void Nbumproute0(void){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[count][0],param[0], &gate[0].shift_);
  // no strobe bit in
  //  BINROUTE_; // new routing in here.
  if (gate[0].trigger) gate[0].route++;
  if (gate[0].route>15) gate[0].route=0;
  tmp=myroute[0][gate[0].route];
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTVN_;
  ENDER;
  }
  }  
}

void Nghostroute0(void){ // but which ghost? our own moved on by 1? so here is default of 1...
  // so what we route int
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[count][0],param[0], &gate[0].shift_);
  if (!strobey[0][mode[0]]) bitn|=gate[0].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=(gate[0].Gshift_[routeto[count][0]])&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTVN_;
  ENDER;
  }
  }  
}

void NDACroute0(void){ 
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[count][0],param[0], &gate[0].shift_);
  if (!strobey[0][mode[0]]) bitn|=gate[0].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[count][0]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTVN_;
  ENDER;
  }
  }  
}



void N32(void){ // multiple bits in as case 19 in draftdec
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //  bitn=ADC_(0,SRlength[0],4,trigger[0],reggg,adcpar); // this is now adc mode 4 - we don't use bitn and do spacmask in adc
    bitn=ADC_(0,SRlength[w],4,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    if (SRlength[defroute[w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			((gate[defroute[w]].shift_&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
    }
    BITN_AND_OUTVN_;
    ENDER;
  }    
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CV and DAC modes - move these to LR!
/*

refine and figure out dac modes as dac is too fast

 */

// DONE: top bits of CV/speed select which DAC to take from - implement and test this, but we need access to bits/CV and smoothed
// but for ADC in is probably best just to have fixed DAC as 3

// so far we have 7 modes and all just use adc mode 0 so this needs to be trimmed - DAC modes also more suited for abstract modes
// can also have BINROUTE in or not???

void Ndacadditself0(void){ // tested//trial itself as DAC - can also be other variants TODO
  HEADN;
  uint8_t w=0;
  float speedf__;
  speedf__=logspeed[(CV[0]&511)+(gate[0].dac>>3)];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacghostitself0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADN;
  uint8_t w=0;
  float speedf__;
  speedf__=logspeed[(CV[0]&511)+((gate[0].Gshift_[routeto[count][0]])&511)];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacghostincoming0(void){ // own ghost from next 1 - could also select incoming ghost which would be: gate[3].Gshift_[0]//gate[x].Gshift_[w]
  HEADN;
  uint8_t w=0;
  float speedf__;
  speedf__=logspeed[(CV[0]&511)+((gate[0].Gshift_[inroute[count][0]])&511)];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}



void Ndacseladd0(void){
  HEADN;
  uint8_t w=0;
  float speedf__;
  uint8_t whic=(CV[0]>>9)&3; //12 bits -> 2 bits
  //  if (speedf_[0]==2.0f) speedf_[0]=0.000990f;
  //  speedf__= (speedf_[0]-logspeed[1023-(gate[which].dac>>2)]);
  speedf__=logspeed[(CV[0]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit
//  speedf__= logspeed[1023-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
//  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  // if (speedf__<0.000990f) speedf__=0.000990f;
  //  speedf__=1.0f;
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacadd0(void){
  HEADN;
  uint8_t w=0;
  float speedf__;
  speedf__=logspeed[(CV[0]&511)+(gate[dacfrom[count][0]].dac>>3)];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacaddmax0(void){ // REMOVE?
  HEADN;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(CV[0]>>2)+(gate[dacfrom[count][0]].dac>>2);
  if (cv>1023) cv=1023;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacminus0(void){
  HEADN;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[count][0]].dac>>2)-(1024-(CV[0]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacspeedminus0(void){
  HEADN;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(CV[0]>>2)-(gate[dacfrom[count][0]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacmod0(void){
  HEADN;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=((CV[0]>>2)+1); // modulo code
  speedf__=logspeed[(gate[dacfrom[count][0]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=0.000990f;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void NB0(void){// with oscillator
  HEAD;
  count=0;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(CV[0]>>2)-(gate[dacfrom[count][0]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=0.000990f;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],30,gate[w].trigger,dacfrom[count][0],gate[w].adcpar, &gate[w].shift_); // oscillator
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INTMODES

// there are only 16... and we want also abstract adc in/prob modes so we need to reduce prob modes
// reduced adc modes and some abstract

void Nint0(void){ // INTmode 0 no interpolation and no use of CV
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// intmodes which use speedCV - CV[0] - 12 bits smoothed
// these are otherparmodes: 17,18,19,21,22 (20 and 29 we have here) - check range of params as can be quite small for size
// 17:?,18:&31,19:&31,21:>>2

void Nintcomp20(void){ //CV comparator //  case 20: // otherpar as comparator - 10 bits standard here // now 12 bits  - OTHERPAR! 12 bits
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],20,gate[w].trigger,dacfrom[count][0],(4095-CV[0]), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint17(void){ //  case 17: // otherpar as timed adc entry
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],17,gate[w].trigger,dacfrom[count][0],(CV[0]>>4), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint18(void){ //  case 18: // otherpar as 
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],18,gate[w].trigger,dacfrom[count][0],31-(CV[0]>>7), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint19(void){ //  case 19: // otherpar as 
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],19,gate[w].trigger,dacfrom[count][0],31-(CV[0]>>7), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint21(void){ //  case 21: // otherpar as 
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],21,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}


void Nintosc29(void){//  case 29:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],29,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintosc34(void){//  case 34:// // 1 bit oscillator - train of length 0 bits followed by y 1 bits  - OTHERPAR! 12 bits
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],34,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}


// prob instead of strobe: 12,13,14,15,16 -> re-worked in ADC_ as 35-39 TESTING/DONE->

void Nint35(void){//  case 35
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],35,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint36(void){//  case 36
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],36,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint37(void){//  case 37
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],37,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint38(void){//  case 38
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],38,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint39(void){//  case 39
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],39,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// no adc in
void Nint65(void){// TEST - was strobe mode for cycling bits a la TM - no input but now uses otherpar as probability! - can be intmode and cvmode
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],65,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// adc in
void Nint66(void){ // mod // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],66,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// adc in
void Nint67(void){ // as above add // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],67,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// adc in
void Nint68(void){ // mod // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],68,gate[w].trigger,dacfrom[count][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

/* // why we lost this?
// Nint70 - if we can change type of gate[3].dac in dac mixes 66,67,68 or pure dac ins (?)
void Nint70(void){
  uint8_t w=0;				       
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    gate[3].dactype=15-(CV[0]>>8);     // 4 bits for type
    bitn=ADC_(0,SRlength[w],67,gate[w].trigger,3,gate[3].dac, &gate[w].shift_);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
*/

// now using ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR, uint32_t *income)
// generic one with 7 modes so all is outside - and we can use 3 bits to select the type of adc_ 7 bits total
// so there can be 3 versions with different additives 71,72,73
// ****
void Nint71(void){
  uint8_t w=0;				       
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    gate[dacfrom[count][1]].dactype=15-(CV[0]>>8);     // 4 top bits for type
    tmp=adc_buffer[12]+gate[dacfrom[count][0]].dac; // additive can be otherwise
    if (tmp>4095) tmp=4095;
    bitn=ADCg_(0, SRlength[0], (7-(7&(CV[0]>>5))), &gate[0].shift_, tmp);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case but could be
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint72(void){ // as above but how can we do mix of adc/dac according to CV, but then we lose CV
  uint8_t w=0; float pp,mult;			       
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    gate[dacfrom[count][0]].dactype=15-(CV[0]&15); // lowest bits
    // leaves us (CV[0]>>4)&255 to play with
    mult=1.0f/(float)(((CV[0]>>4)&255)+1.0f);
    pp=(float)adc_buffer[12]+((float)(gate[dacfrom[count][0]].dac)*mult); // mix with param
    //    pp=(float)(adc_buffer[12]*(1.0f-mult)+((float)(gate[3].dac)*mult); // mix with param - optional
    tmp=(int)pp;
    if (tmp>4095) tmp=4095;
    bitn=ADCg_(0, SRlength[0], 0 , &gate[0].shift_, tmp);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case but could be
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}




// what other bits we could have?

void Nintroute0(void){ // CV: 4 bits for route in... other bits for logop
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    // TESTY!
    tmp=255-(CV[0]>>4); // 8 bits
    for (x=0;x<4;x++){ 
      if ((tmp&0x03) !=0){ // should be fine so we have 01, 10, 11 as 3 logical ops 
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn=logopx(bitn,bitrr,(tmp)&0x03);
	//	bitn=logopx(bitn,bitrr, 2); 
      }
      tmp=tmp>>2; // 4 bits
    }
    // no binroute needed
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

//// TESTIN PROGRESS
// last mode of intmodes -63
void NintselADC_63(void){ // use CV to select adc type: only those which don't use CV or strobe LIST:
  // we could also us top bits to do something with? 16 modes=4 bits, top bits logop/route?
  //0,1,2,3,4,5,6,7,8 - adc logical-22,23,25,26,27,30,63,64,65 to test - 27 dies out but...
  uint8_t choice[16]={0,1,2,3,4,5,6,7,8, 22, 23, 25, 26, 27, 30, 63};//leave off -inprogress 63,64,65 to test - TODO: expand this with new abstract and dac modes...
  uint8_t w=0;				       
  HEADN;  
  if (gate[0].trigger)      {
    val=63-(CV[0]>>6); // 6 bits say
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],choice[val>>2],gate[w].trigger,dacfrom[count][0],gate[w].adcpar, &gate[w].shift_);
    val=(val&0x03);// lowest 2 bits for logop
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn=logop(bitn,bitrr,val);
  }
  tmp=tmp>>1;
    }			     
    BITN_AND_OUTNINT_; // for no pulse out
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


void Nintprob33(void){ // case 33: where prob of CHOICE of ADC bit or cycling bit - so prob is in ADC_
  // but is more flexible if is outside so we can change modes TODO-below
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],33,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    BINROUTE_; // XOR route in?
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintprob1_0(void){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    }
    else
      {
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintprob2_0(void){   // but is more flexible if is outside 
  // prob is choice of ADC or routed in bit only
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    }
    else
      {
	//    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,3,CV[0], &gate[w].shift_); 
    BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintprob3_0(void){   // but is more flexible if is outside so we can change modes
  // - prob of invert or not routed in bit XOR/OR with ADC = same as invert ADC bit
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    bitn=!bitn;
    BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintprob4_0(void){ // prob of adc/X/ORroute or just cycling
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintprobdac1_0(void){ // example - as prob1 above but against DAC3
  // prob is choice of ADC or ADC XOR routed in bit
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if ((gate[3].dac)<CV[0]) {
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    }
    else
      {
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[count][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
