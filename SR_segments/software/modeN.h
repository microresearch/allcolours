// TOP modes as functions.... ADC/other inputs

/*

CVmodes: 16x2 (OR/XOR) or 32x1 and select on casebycase (all logical ones as XOR maybe)

DACmodes: test top bits as selecting which DAC

INTmodes: use CV as param: list

+ across all prob of feedback in ...

*/

// TODO: cut down number of ADC modes so we can have speed bumps maybe
// OR for analogue modes and XOR for digital modes (trial but easily dies on OR!)


void testNint(void){ // no interpolation
  uint8_t w=0;				       
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void testN(void){ // speed template
  uint8_t w=0;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],gate[w].adctype,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVN_; // for no pulse out
    ENDER;
  }
  }
}

#define ADCORIN(X){				\
  uint8_t w=0;					\
  HEAD;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn=ADC_(0,SRlength[w],X,gate[w].trigger,3,param[0], &gate[w].shift_);	\
  BINROUTEOR_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }

#define ADCXORIN(X){				\
  uint8_t w=0;					\
  HEAD;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn=ADC_(0,SRlength[w],X,gate[w].trigger,3,param[0], &gate[w].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }

void Nnofrac0(void){
  uint8_t w=0;
  HEAD;
  if (counter[0]>speed[0] && speed[0]!=1024){
    counter[0]=0;			      
    GSHIFT_;
    bitn=ADC_(0,SRlength[0],0,gate[0].trigger,3,param[0], &gate[w].shift_);    
    BITN_AND_OUTVINT_; 
  }
}

void Nnoroute0(void){ // basic ADC in with no route in
  uint8_t w=0;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,3, param[0], &gate[w].shift_); 
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

void N4(void){
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

void N20(void){
  ADCXORIN(20);
}

void N21(void){
  ADCXORIN(21);
}

// 22->31 = no ADC IN just LFSR/DAC etc

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

void N27(void){ 
  ADCXORIN(27);
}

void N28(void){ 
  ADCXORIN(28);
}

void N29(void){
  ADCXORIN(29);
}

void N30(void){
  ADCXORIN(30);
}

void N31(void){ 
  ADCXORIN(31);
}


void N32(void){ // multiple bits in as case 19 in draftdec
  uint8_t w=0;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //  bitn=ADC_(0,SRlength[0],4,trigger[0],reggg,adcpar); // this is now adc mode 4 - we don't use bitn and do spacmask in adc
    bitn=ADC_(0,SRlength[w],4,gate[w].trigger,3, param[0], &gate[w].shift_); 
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

/// CV and ADC modes
/*
- now if we add speeds then it gets faster!

refine and figure out dac modes as dac is too fast

speedf__[0]= (speedf_[0]+logspeed[1024-(dac[speedfrom_[w]]>>2)])
if (speedf__[0]>1.0f) speedf__[0]=1.0f;

 */

// TODO: top bits select which DAC to take from

void Ndac0(void){
  uint8_t w=0;
  float speedf__;
  if (speedf_[0]==2.0f) speedf_[0]=0.000990f;
  //  speedf__= (speedf_[0]-logspeed[1024-(gate[speedfrom_[0]].dac>>2)]);
//  speedf__= logspeed[1024-(gate[speedfrom_[0]].dac>>2)];
//  speedf__=(speedf_[0] -((4095-gate[speedfrom_[0]].dac)/4095.0f));
  speedf__=speedf_[0];
  //  if (speedf__>1.0f) speedf__=1.0f;
  if (speedf__<0.000990f) speedf__=0.000990f;
  //  speedf__=1.0f;
  HEAD;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,3, param[0], &gate[w].shift_); 
    //    BINROUTEOR_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}
  
/// INTMODES

void Nint0(void){ // INTmode 0 no interpolation
  uint8_t w=0;				       
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,3,gate[w].adcpar, &gate[w].shift_); // fill in INT types! what are these
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}


