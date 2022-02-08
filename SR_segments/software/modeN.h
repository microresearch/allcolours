// *re-check strobeyX, pulsins_NONE HERE!, pulsouts_NONE DONE
//check: adcpar is null, replaced with 0

// TOP modes as functions.... ADC/other inputs
// check all for strobey: binroutes have strobey


/*

re-thinking 7/2/2022

CV modes: 
0-7: basic ADC ins and some abstract ones - reduce... // Noroute0, N0nog, N0, N1, N2, N3, N4, N6 optional N101 is nice, N32*** N82, N75, N81
8-15; abstract ones - q of loopback/entry - strobe modes? // 

abstract only: 28,29,30
using dac: 25,26,27, 66,67,68,69,71,72,73,74, 77,79,80 - maybe one detached mode just for these

strobe route modes
strobe general adc modes

other route modes


15-31: detached modes TODO: detached strobe modes



DAC+CV: 32-39: no route in (choice of dacfrom)
40-47: routeins/probs of routeins etc.
[but maybe not for all modeLetc?]

no route ins, some detached

INT: 48-63

intmodes - which use CV as param
                 use CV as ADC select, can also be detachment here 


[less routings]
choice of adc
probability of entry of adc, of route in etc...

////////////////////////////////////////////////////////////////////////


 *Some modes should not have any route in - in DACspeeds no DAC in maybe*

Pin down to basic ADC ins, strobe ADC ins, abstract ins and reduce a bit

CVmodes: 16 or 16x2 (OR/XOR) or 32x1 and select on casebycase (all logical ones as XOR maybe, others as mix of OR and XOR)

logical modes: 22-31 which can also have prob of loopback and entry

///maybe no DAC modes in N/C: DACmodes 16: test top bits as selecting which DAC

INTmodes 16 or 32 maybe: use CV as param

///we can also double some of these with OR/XOR

+ across all prob of feedback in ...

*/

#define ADCORIN(X){				\
  uint8_t w=0;					\
  HEADN;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);	\
  BINROUTEOR_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }

#define ADCORXORIN(X){				\
  uint8_t w=0;					\
  HEADSINN;					\
  if (speedf_[w]!=2.0f){			\
    SRlength[w]=lookuplenall[((CVL[w]>>6)%32)];		\
  CVOPEN;					\
  if(gate[w].last_time<gate[w].int_time)      {	\
  GSHIFT_;								\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);	\
  if (((CVL[w]>>6)&32)==32) {						\
    BINROUTEOR_;							\
  }									\
  else {								\
    BINROUTE_;								\
  }									\
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
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }

#define ADCXORINNOG(X){				\
  uint8_t w=0;					\
  HEADN;						\
  if (speedf_[w]!=2.0f){			\
  CVOPEN;					\
  if(gate[0].last_time<gate[0].int_time)      {	\
  GSHIFT_;								\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);	\
  BINROUTENOG_;								\
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
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);	\
  if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;			\
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
  tmp=gate[dacfrom[daccount][0]].dac;					\
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[daccount][0],tmp, &gate[0].shift_);	\
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
  bitn=ADC_(0,SRlength[0],X,gate[0].trigger,dacfrom[daccount][0],tmp, &gate[0].shift_);	\
  BINROUTE_;								\
  BITN_AND_OUTVN_;							\
  ENDER;								\
  }									\
  }									\
  }

// longer sel with strobes and cv but we can only access this from detached CV/speed and length
// we have CV (speed) and CVL (length) - one is param, other is sel so
// so length or speed can be from DAC only
uint8_t seladc[63]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,75,76,21,81,82,77,78,79,80,22,23,24,25,26,27,28,29,30,31,101,64,65,66,67,68,71,72,73,74, 0,1,2,3,4,5,6,7,25,26,27,29,30};
// padded out to 64 with favoured ones

uint8_t parammodes[16]={17,18,19,20, 21,22,29,33, 34,35,37,38, 39,66,67,68};

uint8_t modes16[16]={0,1,2,3,4,6,101,32,82,75,81,28,29,30,79,80}; // choose again maybe temp list TODO

// list for dacmodes! TODO!

// prob or/xor/route
void Norxor0(void){ // split length / or / xor // DETACH LENGTH - could be nice also select adc type
ADCORXORIN(0);
}

void N0(void){ // basic ADC in with XOR route in
  ADCXORIN(0);
}

void Noroute0(void){ // basic ADC in with no route in
  ADCXORIN_NOROUTE(0);
}

void N0nog(void){ // basic ADC in with XOR route in and no gshifting <<
  ADCXORINNOG(0);
}

void N1(void){ // equivalent bits
  ADCXORIN(1);
}

void N2(void){ // one bit audio
  ADCXORIN(2);
}

void N3(void){ // basic sequential length as in 0 but with padding if >11 bits  
  ADCXORIN(3);
}

void N4(void){ // spaced 4 bits in but we need to route DAC in differently - this is done now in adc_ mode 4
  ADCXORIN(4);
}

void N5(void){ // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...//NON
  ADCXORIN(5);
}

void N6(void){ // padded version of SR of bitsin
  ADCXORIN(6);
}

void N7(void){ // // timed version of SR bitsin - is MSB first- //NON
  ADCXORIN(7);
}

void N32(void){ // multiple bits in as case 19 in draftdec // ***
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    //  bitn=ADC_(0,SRlength[0],4,trigger[0],reggg,adcpar); // this is now adc mode 4 - we don't use bitn and do spacmask in adc
    bitn=ADC_(0,SRlength[w],4,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    if (SRlength[inroute[count][w]]>=SRlength[w]){
    gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0])) >>(lastspac[SRlength[inroute[count][w]]][0]))+ \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))          >> ((lastspac[SRlength[inroute[count][w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))         >>((lastspac[SRlength[inroute[count][w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))         >>((lastspac[SRlength[inroute[count][w]]][3]) - spacc[SRlength[w]][2]))); 
  }
  else // shift up <<
    {
      gate[w].shift_ |=(((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][0]))>>(lastspac[SRlength[inroute[count][w]]][0])) + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[inroute[count][w]]][1]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[inroute[count][w]]][2]))  + \
			((gate[inroute[count][w]].shift_&(1<<lastspac[SRlength[inroute[count][w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[inroute[count][w]]][3])));
    }
  if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
  BITN_AND_OUTVN_; // no pulse ins/outs
    ENDER;
  }    
  }
}


void N101(void){ // test speed double/skip sample
  ADCXORIN(101);
}

//////////////////////////////////////////////////
// abstracts

void N28(void){ 
  ADCXORIN(28);
}

void N29(void){ // 1 bit oscillator
  ADCXORIN(29);
}

void N30(void){
  ADCXORIN(30);
}

//////////////////////////////////////////////////

// no adc
void N64(void){ //no adc at ALL
  ADCXORIN(64);
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

void N20(void){ // comparator mode with clock as param[0] always
  ADCXORIN(20);
}

void N75(void){ // comparator mode with other dac as param // ***
  ADCXORIN_NOROUTE(75);
}

void N76(void){ // comparator mode with OWN dac as param 
  ADCXORIN(76);
}

void N21(void){
  ADCXORIN(21);
}

void N81(void){ // 4 bits in ***
  ADCXORIN(81);
}

void N82(void){ // comparator as incoming bit ***
  ADCXORIN_NOROUTE(82);
}

// DAC etc

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

void N31(void){ 
  ADCXORIN(31);
}

///////////////////////////////////////////

//DACS:

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

//////////////////////////////////////////////////////////////////////////////////////////////////ROUTE MODES

// maybe these work best in L/R modes
// TODO: just bump within a restricted range or array which make sense?
void Nbumproute0(void){ // trigger bumps up our local route - add one to this (what value) - gate[0].route
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
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
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
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
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][0]].dac&15;
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

void NSRroute0(void){ 
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][0]].Gshift_[0]&15;
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

void NDACroutestrobe0(void){ // dacroute with strobe
  // strobe can also select adc in, or choose adc/routed
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_);
  //  if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
  //  BINROUTE_; // new routing in here.
  tmp=gate[dacfrom[daccount][0]].dac&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[0]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[0]=(gate[x].Gshift_[0]<<1)+bitrr;
  if (gate[0].trigger) bitn^=bitrr;
  }
  tmp=tmp>>1;
    }			     
  BITN_AND_OUTVN_;
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

void NLstrobe1(void){ 
  uint8_t w=0, bits, bitss;
  HEADSINN; // detach length
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitss=CVL[0]>>6; // 6 bits
    bits=bitss&3; // 2 bits
    if (bits==0){    
    if (gate[w].trigger) bitn=!bitn;
    bitn=ADC_(0,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    BINROUTE_;
    }

    if (bits==1){    
    if (gate[w].trigger)    bitn=ADC_(0,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    else BINROUTE_;
    }

    if (bits==2){    
    bitn=ADC_(0,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    if (gate[w].trigger) BINROUTE_; // or vice versa
    }

    if (bits==3){    
    bitn=ADC_(0,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    if (gate[w].trigger) JUSTCYCLE_;
    }

    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

void Nstrobe1_0(void){ 
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    if (gate[w].trigger) bitn=!bitn;
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

void Nstrobe2_0(void){ // basic ADC in - strobe= bitn or route
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (gate[w].trigger)    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    else BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

void Nstrobe3_0(void){ // basic ADC in - see above table - 3ADC BIT vs [ADC/xor/or/routed] - NONE
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    if (gate[w].trigger) BINROUTE_; // or vice versa
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

// and this set is additionally only for abstract ADCs in
// which can include DACs in... 22-31

/*
  4- ADC bits vs RETURNbit - XOR/OR routed
  5- ADC bits vs [routed/xor/or/RETURNbit]
  6- ADCBIT xor routed vs returnbit
*/

void NLstrobe2(void){ // 2nd version covering abstract modes and returns - check adc selection TODO
  uint8_t w=0, bits, bitss;
  HEADSINN; // detach length
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitss=CVL[0]>>6; // 6 bits
    bits=bitss&3; // 2 bits
    if (bits==0){    
    bitn=ADC_(0,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    if (gate[w].trigger) JUSTCYCLE_;
    BINROUTE_; 
    }

    if (bits==1){    
    if (!gate[w].trigger) bitn=ADC_(0,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    else {
      BINROUTEANDCYCLE_;
    }
    }

    if (bits==2){    
    if (!gate[w].trigger) { bitn=ADC_(0,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
      BINROUTE_;
    }
    else JUSTCYCLE_;
    }

    if (bits==3){    // new one
          bitn=ADC_(0,SRlength[w],modes16[bitss>>2],gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
	  if (!gate[w].trigger) bitn=!bitn;
	  BINROUTEANDCYCLE_;
    }

    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}


void Nstrobe4_29(void){ 
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],29,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    if (gate[w].trigger) JUSTCYCLE_;
    BINROUTE_; 
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

void Nstrobe5_29(void){ 
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (!gate[w].trigger) bitn=ADC_(0,SRlength[w],29,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    else {
      BINROUTEANDCYCLE_;
    }
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

void Nstrobe6_29(void){  // 6- ADCBIT xor routed vs returnbit
  uint8_t w=0;
  HEADN;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (!gate[w].trigger) { bitn=ADC_(0,SRlength[w],29,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
      BINROUTE_;
    }
    else JUSTCYCLE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// detached modes
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ported/porting from modeL - but no adc selection possible
void Nmultiplespeednew0(void){ // NO LENGTH - try 4 speeds as above - multiple versions of this // this one is ****
  uint8_t w=0; // can we have bits to select combinations for the 4 options splitspeed???
  // trigger: 1,2,3,4 2 bits
  // counter1: 2 bits
  //counterd: 2 bits - but all can only do one...
  //speedf (does interpol but can have no interpol version with BITN_AND_OUTVINT_) 
  
  HEADSINN; // detach length

  if (gate[0].trigger) GSHIFTNOS_; // 2.copy gshift on trigger

  if (counter[0]>gate[dacfrom[daccount][w]].dac){ //3.advance incoming ghost
    counter[0]=0;
    BINROUTEADV_;
  }

  if (counterd[0]> CVL[0]){
      counterd[0]=0;
    gate[w].shift_=gate[w].shift_<<1; // 1. shifter
  }
  
  if (speedf_[w]!=2.0f){ // 4.main DAC
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    //    gate[w].shift_=gate[w].shift_<<1; // but no shift makes odd with add... anyways
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_);
    BINROUTENOG_; // no gshifty
    PULSIN_XOR;
    BITN_AND_OUTV_;
    ENDER;
  }
  }
}


/* bursts of DACin/ADCin to spawn/seed feedback - so trigger
  means CV length of ADC bits in, no trigger is ROUTEin at otherCV
  speed, or all at cv speed
*/
void NLBURST0(void){ 
  // DETACH LENGTH
  uint8_t w=0;
  HEADSINN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  if (gate[w].trigger){
    train[w]=1;
  }
  if (train[w]!=0 && train[w]< (1024-(CVL[0]>>2))){
  train[w]++;
  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_); // or we can use adcchoice to fill in
  }
  else {
    train[w]=0;
    BINROUTE_;
  }
  BITN_AND_OUTVN_;
  ENDER;
  }
  }
}

void NLseladc(void){ // select ADC 0-31 ***
  // DETACH LENGTH
  uint8_t w=0;
  HEADSINN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  tmp=(CVL[0]>>7); // 5 bits = 32 or we can have a list of preferred modes TODO !!!
  bitn=ADC_(0,SRlength[0],tmp,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_); // or we can use adcchoice to fill in
  BINROUTE_;
  BITN_AND_OUTVN_;
  ENDER;
  }
  }
}

void NLseladc1(void){ // select ADC 0-63 - preferred modes with param[0] as param   // DETACH LENGTH
  uint8_t w=0;
  HEADSINN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  tmp=(CVL[0]>>6); // 6 bits = 64 or we can have a list of preferred modes TODO !!!
  bitn=ADC_(0,SRlength[0],parammodes[tmp],gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_); // or we can use adcchoice to fill in
  BINROUTE_;
  BITN_AND_OUTVN_;
  ENDER;
  }
  }
}


void NLseladc2(void){ // speed from cv, cvl as type and dac as param   // DETACH LENGTH
  uint8_t w=0;
  HEADSINN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {
  GSHIFT_;
  bitn=ADC_(0,SRlength[0],parammodes[CVL[0]>>8],gate[0].trigger,dacfrom[daccount][0], gate[dacfrom[daccount][0]].dac, &gate[0].shift_); // or we can use adcchoice to fill in
  BINROUTE_;
  BITN_AND_OUTVN_;
  ENDER;
  }
  }
}

void NLSRlengthsel(void){ //use other SR bits to determine length of SR, eg. can be modded or...*   // DETACH LENGTH
  // in this case we select ADC as above and use SR as length 
  uint8_t w=0;
  HEADSINN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {

    tmp=gate[dacfrom[daccount][0]].shift_&31;    
    SRlength[0]=lookuplenall[tmp]; // 5 bits

    GSHIFT_;
  tmp=(CVL[0]>>7); // 5 bits = 32
  bitn=ADC_(0,SRlength[0],tmp,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_); // or we can use adcchoice to fill in
  //  BINROUTE_; // with or without route in
  if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
  BITN_AND_OUTVN_;
  ENDER;
  }
  }
}

// adc0
void NLSRlengthsel0(void){ //use other SR bits to determine length of SR, eg. can be modded or...*   // DETACH LENGTH
  uint8_t w=0;
  HEADSINN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[0].last_time<gate[0].int_time)      {

    tmp=gate[dacfrom[daccount][0]].shift_&15;    
    SRlength[0]=lookuplenall[tmp%((CVL[0]>>7)+1)]; // 5 bits
    //    SRlength[0]=lookuplenall[CVL[0]>>7]; // 5 bits
    GSHIFT_;

  bitn=ADC_(0,SRlength[0],0,gate[0].trigger,dacfrom[daccount][0],param[0], &gate[0].shift_); // or we can use adcchoice to fill in
  //  BINROUTE_; // with or without route in // ***
  if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
  BITN_AND_OUTVN_;
  ENDER;
  }
  }
}

void NLLswop0(void){ // swop in or logop SR - cv and cvl- not so good for Nmode   // DETACH LENGTH/SPEED
  uint8_t w=0; uint32_t lin, lout;
  HEADSSINNADA;

  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    BINROUTE_; 
    if (gate[w].trigger) {
      lin=127-(CV[0]>>5); //7= 2 bits for whichone and start which can be 5
      lout=31-(CVL[0]>>7); // 5 bits for length
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

void Ngenericprobx(void){ // porting to strobe - ported to N - detach CVL - length to select ADC // DETACH LENGTH
  uint8_t w=0;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADSINN;  

  if (speedf_[w]!=2.0f){ 
    CVOPEN;

    GSHIFT_;
    BINROUTE_;
    prob[0]=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);; // route
    prob[1]=bitn; // route
    prob[2]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[3]=0;

    // bit is 8 x 3 - 5 bits + 2 bits
    bit=gate[dacfrom[daccount][w]].dac&31; 
    lower=bit&0x03;
    bit=(bit>>2)*3;

    if (gate[w].trigger) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
        BITN_AND_OUTV_; 
    ENDER;
} 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CV and DAC modes - move these to LR! ???
/*

refine and figure out dac modes as dac is too fast

 */

// so far we have 7 modes and all just use adc mode 0 so this needs to be trimmed - DAC modes also more suited for abstract modes
// can also have BINROUTE in or not???

void Ndacadditself0(void){ // tested//trial itself as DAC - can also be other variants TODO
  HEADN;
  uint8_t w=0;
  float speedf__;
  speedf__=logspeed[(CV[0]&511)+(gate[0].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
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
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
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
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTVN_;
    ENDER;
  }
}


// DONE: top bits of CV/speed select which DAC to take from - implement and test this, but we need access to bits/CV and smoothed
// but for ADC in is probably best just to have fixed DAC as 3

void Ndacseladd0(void){
  HEADN;
  uint8_t w=0;
  float speedf__;
  uint8_t whic=(CV[0]>>9)&3; //12 bits -> 2 bits
  speedf__=logspeed[(CV[0]&511)+(gate[whic].dac>>3)]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacadd0(void){
  HEADN;
  uint8_t w=0;
  float speedf__;
  speedf__=logspeed[(CV[0]&511)+(gate[dacfrom[daccount][0]].dac>>3)];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacaddmax0(void){ // REMOVE?
  HEADN;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(CV[0]>>2)+(gate[dacfrom[daccount][0]].dac>>2);
  if (cv>1023) cv=1023;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacminus0(void){
  HEADN;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[daccount][0]].dac>>2)-(1024-(CV[0]>>2));
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void Ndacspeedminus0(void){
  HEADN;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(CV[0]>>2)-(gate[dacfrom[daccount][0]].dac>>2); 
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
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
  speedf__=logspeed[(gate[dacfrom[daccount][0]].dac>>2)%cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0], param[0], &gate[w].shift_); 
    //    BINROUTE_;
    if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger;
    BITN_AND_OUTVN_;
    ENDER;
  }
}

void NB0(void){// with oscillator
  HEADN;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(CV[0]>>2)-(gate[dacfrom[daccount][0]].dac>>2);
  if (cv<0) cv=0;
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;  
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],30,gate[w].trigger,dacfrom[daccount][0],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void Ndacoffset0(void){
  uint8_t w=0;
  float speedf__;
  float mmm=(float)(1024-(CVL[0]>>2))/1024.0f;
  HEADSINN;
  tmp=(1024-(CV[0]>>2)) + (int)((float)(gate[dacfrom[daccount][0]].dac>>2)*mmm);
  if (tmp>1023) tmp=1023;
  speedf__=logspeed[tmp]; // 9 bits + 9 to 10 bits - we still have one bit - must  be outside...
  if (speedf__==2.0f) speedf__=LOWEST;

  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],30,gate[w].trigger,dacfrom[daccount][0],0, &gate[w].shift_); // oscillator
    BINROUTE_;
    BITN_AND_OUTV_;
    ENDER;
  }
}

void NLdacadc(void){ // speed is from dac, use cv to select type and cvl as parameter - but just for param modes
  // or as intmode: variations of this
  HEADSSINNADA;
  uint8_t w=0;
  int32_t cv;
  float speedf__;
  cv=(gate[dacfrom[daccount][0]].dac>>2);
  speedf__=logspeed[cv];
  if (speedf__==2.0f) speedf__=LOWEST;
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],parammodes[CV[0]>>8],gate[w].trigger,dacfrom[daccount][0], CVL[0], &gate[w].shift_); // 4 bits
    // what of some modes where we have 4095-CV[0] - should this be in adc or live with it
    //    BINROUTE_;
    if (!strobey[0][mode[0]]) bitn=bitn|gate[0].trigger; // ??
    BITN_AND_OUTVN_;
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
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],0, &gate[w].shift_); 
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
    bitn=ADC_(0,SRlength[w],20,gate[w].trigger,dacfrom[daccount][0],(4095-CV[0]), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint17(void){ //  case 17: // otherpar as timed adc entry
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],17,gate[w].trigger,dacfrom[daccount][0],(CV[0]>>4), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint18(void){ //  case 18: // otherpar as 
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],18,gate[w].trigger,dacfrom[daccount][0],31-(CV[0]>>7), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint19(void){ //  case 19: // otherpar as 
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],19,gate[w].trigger,dacfrom[daccount][0],31-(CV[0]>>7), &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint21(void){ //  case 21: // otherpar as 
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],21,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}


void Nintosc29(void){//  case 29:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],29,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintosc34(void){//  case 34:// // 1 bit oscillator - train of length 0 bits followed by y 1 bits  - OTHERPAR! 12 bits
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],34,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
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
    bitn=ADC_(0,SRlength[w],35,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint36(void){//  case 36
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],36,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint37(void){//  case 37
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],37,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint38(void){//  case 38
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],38,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint39(void){//  case 39
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],39,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// no adc in
void Nint65(void){// was strobe mode for cycling bits a la TM - no input but now uses otherpar as probability! - is also as int65 now...
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],65,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
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
    bitn=ADC_(0,SRlength[w],66,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
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
    bitn=ADC_(0,SRlength[w],67,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
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
    bitn=ADC_(0,SRlength[w],68,gate[w].trigger,dacfrom[daccount][0],4095-CV[0], &gate[w].shift_); 
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// now using ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR, uint32_t *income)
// generic one with 7 modes so all is outside - and we can use 3 bits to select the type of adc_ 7 bits total
// so there can be 3 versions with different additives 71,72,73
// ****
// now 3 bits type, 2 bits which
void Nint71(void){
  uint8_t w=0, tmpp;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    gate[dacfrom[daccount][0]].dactype=15-(CV[0]>>8);     // 4 top bits for type 0- was [1] why? and where we set this back
    tmpp=(CV[0]>>10); // 2 bits;
    tmp=adc_buffer[12]+gate[tmpp].dac; // additive can be otherwise
    if (tmp>4095) tmp=4095;
    bitn=ADCg_(0, SRlength[0], (7-(7&(CV[0]>>7))), &gate[0].shift_, tmp);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case but could be
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint72(void){ // as above but how can we do mix of adc/dac according to CV, but then we lose CV
  uint8_t w=0; float pp,mult;			       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    gate[dacfrom[daccount][0]].dactype=15-(CV[0]&15); // lowest bits
    // leaves us (CV[0]>>4)&255 to play with
    tmp=(CV[0]>>2)&3;
    mult=1.0f/(float)(((CV[0]>>4)&255)+1.0f);
    pp=(float)adc_buffer[12]+((float)(gate[tmp].dac)*mult); // mix with param
    //    pp=(float)(adc_buffer[12]*(1.0f-mult)+((float)(gate[3].dac)*mult); // mix with param - optional
    tmp=(int)pp;
    if (tmp>4095) tmp=4095;
    bitn=ADCg_(0, SRlength[0], 0 , &gate[0].shift_, tmp);  // 4 bits for type  66=modulo, 67=add, 68=and
    //BINROUTE_; // no route in in this case but could be
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nint84(void){ // own dac as comparator against DAC+CV // ***
  // can also detach length and have this as prob mode too
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],84,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    JUSTCYCLE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprob184(void){ // own dac as comparator against DAC+CV // ***
  // can also detach length and have this as prob mode too - prob of cycle or ADC. prob of cycle or routein
  uint8_t w=0;				       
  HEADSINN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],84,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);
    if (((LFSR_[0] & 4095 ) > CVL[0])){   // this way round
    BINROUTE_;
    }
    else JUSTCYCLE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// what other bits we could have?

void Nintroute0(void){ // CV: 4 bits for route in... other bits for logop
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
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

// use CVL freed up for probability of bitn entry...
void NLintroute0(void){ // CV: 4 bits for route in... other bits for logop
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CVL[0])){ // prob of bit in - could also be DAc
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);
    }
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


void NintselADC1(void){ // parammodes speed from trigger, cv for selectadc, detach length for param or param as dac
  uint8_t w=0;				       
  HEADSINN;  
  if (gate[0].trigger)      {
    val=63-(CV[0]>>6); // 6 bits say
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],parammodes[val>>2],gate[w].trigger,dacfrom[daccount][0],CVL[0], &gate[w].shift_);
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

void NintselADC2(void){ // speed from trigger, cv for selectadc, detach length for param or param as dac
  uint8_t w=0;				       
  HEADN;  
  if (gate[0].trigger)      {
    val=63-(CV[0]>>6); // 6 bits say
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],parammodes[val>>2],gate[w].trigger,dacfrom[daccount][0],gate[dacfrom[daccount][0]].dac, &gate[w].shift_);
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


void NintselADC_63(void){ // use CV to select adc type: only those which don't use CV or strobe LIST:
  // we could also us top bits to do something with? 16 modes=4 bits, top bits logop/route?
  //0,1,2,3,4,5,6,7,8 - adc logical-22,23,25,26,27,30,63,64,65 to test - 27 dies out but...
  uint8_t choice[16]={0,1,2,3,4,5,6,7,8, 22, 23, 25, 26, 27, 30, 63};//leave off -inprogress 63,64,65 to test - TODO: expand this with new abstract and dac modes...
  uint8_t w=0;				       
  HEADN;  
  if (gate[0].trigger)      {
    val=63-(CV[0]>>6); // 6 bits say
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],choice[val>>2],gate[w].trigger,dacfrom[daccount][0],0, &gate[w].shift_);
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

/*
void Nintprob33(void){ // case 33: where prob of CHOICE of ADC bit or cycling bit - so prob is in ADC_
  // but is more flexible if is outside so we can change modes TODO-below
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],33,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_; // XOR route in?
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}
*/

void Nintprob1_0(void){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    }
    else
      {
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
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
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);
    if (((LFSR_[0] & 4095 ) > CV[0])){
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
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    bitn=!bitn;
    BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintprob4_22(void){ // prob of adc/X/ORroute or just cycling - just for abstract modes
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],22,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintprob5_0(void){ // electronotes draft0 // can also use incoming SR instead of LFSR
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[0] & 4095 ) < CV[0])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[0]&255) & ((CV[0]>>4)&255)) == 255 ){
    
    tmp=255-(CV[0]>>4);
    if ( ( ( ((LFSR_[0]&1)>>0) + ((LFSR_[0]&4)>>1) + ((LFSR_[0]&32)>>3) + ((LFSR_[0]&262144)>>15) + ((LFSR_[0]&16384)>>10) + ((LFSR_[0]&131072)>>12) + ((LFSR_[0]&524288)>>13) + ((LFSR_[0]&2097152)>>14)) | tmp)==255){
    
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void Nintprob6_0(void){ // electronotes draft0 // use incoming SR instead of LFSR - also no route in *** // can be lfsr against shift also***
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[0] & 4095 ) < CV[0])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[0]&255) & ((CV[0]>>4)&255)) == 255 ){
    // LFSR_[0]->gate[inroute[count][0]].shift_
    tmp=255-(CV[0]>>4);
    if ( ( ( ((gate[inroute[count][0]].shift_&1)>>0) + ((gate[inroute[count][0]].shift_&4)>>1) + ((gate[inroute[count][0]].shift_&32)>>3) + ((gate[inroute[count][0]].shift_&262144)>>15) + ((gate[inroute[count][0]].shift_&16384)>>10) + ((gate[inroute[count][0]].shift_&131072)>>12) + ((gate[inroute[count][0]].shift_&524288)>>13) + ((gate[inroute[count][0]].shift_&2097152)>>14)) | tmp)==255){
    
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    //    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}


void Nintprob7_0(void){ // electronotes draft0 - ADC or ROUTEIN
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  uint8_t w=0;				       
  HEADN;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[0] & 4095 ) < CV[0])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[0]&255) & ((CV[0]>>4)&255)) == 255 ){
    
    tmp=255-(CV[0]>>4);
    if ( ( ( ((LFSR_[0]&1)>>0) + ((LFSR_[0]&4)>>1) + ((LFSR_[0]&32)>>3) + ((LFSR_[0]&262144)>>15) + ((LFSR_[0]&16384)>>10) + ((LFSR_[0]&131072)>>12) + ((LFSR_[0]&524288)>>13) + ((LFSR_[0]&2097152)>>14)) | tmp)==255){
    
    bitn=ADC_(0,SRlength[w],0,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    //    BINROUTE_;
    }
    else
      {
	BINROUTE_;
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
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    if ((gate[dacfrom[daccount][w]].dac)>CV[0]) {
    BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// generic prob ported from probability.h
void Nintgenericprob30(void){
  uint8_t w=0;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADL;  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=ADC_(0,SRlength[w],30,gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);; // route
    prob[1]=bitn; // route
    prob[2]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[3]=0;
    
    // bit is 8 x 3 - 5 bits
    bit=gate[dacfrom[daccount][w]].dac&31; // 5 bits - could also be extra bits for logical ops
    lower=bit&0x03;
    bit=(bit>>2)*3;

    tmp=LFSR_[w]&4095;
    tmpp=CV[w]; // which way round

    if (tmp<tmpp) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

// generic prob ported from probability.h
void NLintgenericprob(void){ // detach length and use to select ADC
  uint8_t w=0;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  HEADSSINNADA; // we don;t need  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_; 
    prob[0]=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);; // route
    prob[1]=bitn; // route
    prob[2]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[3]=0;
    
    // bit is 8 x 3 - 5 bits
    bit=gate[dacfrom[daccount][w]].dac&31; // 5 bits - could also be extra bits for logical ops
    lower=bit&0x03;
    bit=(bit>>2)*3;

    tmp=LFSR_[w]&4095;
    tmpp=CV[w]; // which way round

    if (tmp<tmpp) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintgenericprobx(void){ // TODO: can also be on trigger as CV strobe mode
  // can also reverse so dac is prob and cv is bits
  uint8_t w=0;
  uint32_t tmpp, bit, lower;
  uint32_t prob[4]={0};
  uint32_t left[2]={0}; uint32_t right[2]={0};
  HEADSSINNADA;  

  if (gate[w].trigger)      {
    GSHIFT_;

    BINROUTE_;
    prob[0]=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_);; // route
    prob[1]=bitn; // route
    prob[2]=gate[w].Gshift_[w]>>SRlength[w]; // ret
    prob[3]=0;

    left[0]=LFSR_[w]&4095; left[1]=gate[w].Gshift_[w]&4095; 
    right[0]=4095-CV[w]; right[1]=right[0]+(gate[dacfrom[daccount][w]].dac&4095);
    if (right[1]>4095) right[1]=4095;
    // bit is 8 x 3 - 5 bits + 2 bits
    bit=gate[dacfrom[daccount][w]].dac&127; // 2+5 bits //- could also be extra bits for logical ops
    lower=bit&0x03;
    tmp=(bit>>2)&1; // fixed
    tmpp=(bit>>3)&1;
    bit=(bit>>4)*3;

    if (left[tmp]<right[tmpp]) bitn=prob[lower]; // lowest 2 bits
    else bitn=prob[options[lower][bit]] ^prob[options[lower][(bit+1)]]^prob[options[lower][(bit+2)]];
    BITN_AND_OUTVINT_; // for pulse out
  } 
}


/// prob modes for N which split off length and select ADC - ONLY FOR MODEN
// can also comp to dac

void NLintprob1(void){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  uint8_t w=0;				       
  HEADSSINNADA; // we don;t need  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    if (((LFSR_[0] & 4095 ) > CV[0])){
      BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprobdac1(void){   // but is more flexible if is outside so we can change modes
  // prob is choice of ADC or ADC XOR routed in bit
  uint8_t w=0;				       
  HEADSSINNADA; // we don;t need  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    if (((DACFROM & 4095 ) > CV[0])){
      BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}


void NLintprob2(void){   // but is more flexible if is outside 
  // prob is choice of ADC or routed in bit only
  uint8_t w=0;				       
    HEADSSINNADA; ;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    }
    else
      {
    BINROUTE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprob3(void){   // but is more flexible if is outside so we can change modes
  // - prob of invert or not routed in bit XOR/OR with ADC = same as invert ADC bit
  uint8_t w=0;				       
    HEADSSINNADA; ;  
  if (gate[w].trigger)      {
    GSHIFT_;
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    if (((LFSR_[0] & 4095 ) > CV[0])){
    bitn=!bitn;
      }
    BINROUTE_;
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprob4(void){ // prob of adc/X/ORroute or just cycling - just for abstract modes
  uint8_t w=0;				       
    HEADSSINNADA; ;  
  if (gate[w].trigger)      {
    GSHIFT_;
    if (((LFSR_[0] & 4095 ) < CV[0])){
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
      }
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

void NLintprob5(void){ // electronotes draft0 // can also use incoming SR instead of LFSR
  // 8 switches - bits ANDed with bits 1, 3, 6, 19, 15, 18, 20, 22
  // switches have 256 options
  uint8_t w=0;				       
  HEADSSINNADA; ;  
  if (gate[w].trigger)      {
    GSHIFT_;
    //    if (((LFSR_[0] & 4095 ) < CV[0])){ // ((SR/LFSR & (CV) )== 4095)
    //    if ( ((LFSR_[0]&255) & ((CV[0]>>4)&255)) == 255 ){
    
    tmp=255-(CV[0]>>4);
    if ( ( ( ((LFSR_[0]&1)>>0) + ((LFSR_[0]&4)>>1) + ((LFSR_[0]&32)>>3) + ((LFSR_[0]&262144)>>15) + ((LFSR_[0]&16384)>>10) + ((LFSR_[0]&131072)>>12) + ((LFSR_[0]&524288)>>13) + ((LFSR_[0]&2097152)>>14)) | tmp)==255){
    
    bitn=ADC_(0,SRlength[w],(adclist[CVL[0]>>7]),gate[w].trigger,dacfrom[daccount][0],CV[0], &gate[w].shift_); 
    BINROUTE_;
    }
    else
      {
	JUSTCYCLE_;
	}
    BITN_AND_OUTNINT_; // for no pulse out
  } 
}

