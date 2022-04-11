// 11/4/2022

/* bin

   tmp=binroute[count][w];
   for (x=0;x<4;x++){
   if (tmp&0x01){
   bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
   gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
   bitn^=bitrr;
   }
   tmp=tmp>>1;
  }

 */

// can we insert one wheel/SR in another - keep it running at last speed... embed it as our bitn

// attach, detach, embed of functions

// embed as bitn, as prob/decision

// what that would look like and how that could be translated into a story, how to embed/recurse as a structure/itself

/*

we would need to simplify speed... speed can also be a character of SR... speed as decision from SR/generator

speed as sequence of SR/ 1s and 0s

global speed...

genX:
if (genX){
gshift[w]
bitn=genX
}

towards most simple SR - work from inside or from inside...

void SRintprobnog(uint8_t w){  // intmode
  HEAD;  
  if (X)      {
    GSHIFT_;

    bitn=Y;
    PULSIN_XOR;

    BITN_AND_OUTVINT_; 
  } 
}

// gshift as part of generator, output as what?

-> abstractions of SRs aside from output - or vice versa... functions assigned to outputs

splitting and subjection of itself... so each element is abstracted out and able to be controlled by...

if (speed){
  if X gshift
  bitn=[ // generator selected--->
    if (speed){
      bitn=[ // generator
      ]
    }
  ]
}

if (speedfrom){
  gshift
  bitn=FROM?
  SR=IN?/WHERE?
  GSR=GSR? // recurse... but we lose params...

 */

// itself(uint32_t (*f)( uint32_t (*f)(RECURSE),uint32_t depth, uint8_t wh), uint32_t depth, uint32_t other, uint8_t wh)

// towards new prototype for itself as SR
static uint32_t itself(uint32_t (*f)(uint32_t depth, uint8_t wh), uint32_t (*g)(uint32_t depth, uint8_t wh), uint32_t depth, uint32_t other, uint8_t wh){   // PROBability mode
  uint32_t bt=0;
  if (f(depth,wh)){ // if itself...recur
      bt=g(other,wh);
    }
  return bt;
}

// wrap up eg.
void SRitself(uint8_t w){
uint8_t prob;
  HEADSSINNADA;
  CVOPEN;
  GSHIFT_;
    // CORE
  bitn=itself(osceqbits,binroutebits,CV[w], CVL[w], w); // but we would need additional 8 bits (4+4) to set each of these - from another SR!!!
  // abstractbitstreams[x], abstractbitstreams[y] 
  
  PULSIN_XOR; // place into SR function
  
  BITN_AND_OUTV_; // abstract out maybe
  ENDER;
}

//speedfrom?, bitfrom?

// vienna/generic was: 1bit speedfrom, [1bit adctype-fixed], 4 bits routein, 1bitprob_of_inv on param

// swop incoming gshift and shift
void SRGswop(uint8_t w){// swap over SRs on pulse in?!! or swop in only (can swop in previous SR or another?) 
uint8_t prob;
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // INSERT!
    BINROUTE_;
    //    if (gate[w].trigger) gate[w].shift_=gate[w].Gshift_[w]; // could also be incoming one
    if (gate[w].trigger) gate[w].shift_=gate[inroute[count][w]].Gshift_[w]; // could also be incoming one
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// 2 routes into one//XOR full TRY!
void noSRxorroutes(uint8_t w){ // XOR in with mask of lengths
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  // copy mask of bits from inroute
  tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
    gate[w].shift_^= (gate[x].Gshift_[w]&masky[SRlength[x]]);
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }	
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;  
  ENDER;
  }
  }
  }

// question of embeddings and numbers say of gshifts... also shared gshifts as an option... embed this one//as a generatorDONE

// new gshift for sharings: BINROUTESHARE_ and gate[x].Gshare_ -> only makes sense if we share routes or if there are functions to shift on shared routes... 
// eg. function to shift on shared route at speed as one SR or to insert into shared SR!
// try route from before one... or enforce shared routes
void SRshroute(uint8_t w){ // strobe could also shift on
  HEAD;
  int32_t mw;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  mw=w-1;
  //  if (mw<0) mw=3;
  tmp=binroute[count][w];
   for (x=0;x<4;x++){
   if (tmp&0x01){
   bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;
   gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
   if (gate[w].trigger) {
   bitrr = (gate[x].Gshare_>>SRlength[x]) & 0x01;
   gate[x].Gshare_=(gate[x].Gshare_<<1)+bitrr;
   }
   bitn^=bitrr;
   }
   tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }
  
///////////////////////////////////////////////////////////////////////////////////////////

// 8/4/2022

// wheeling probability function
// but to make use of this we need next one to use incoming as prob of adc or route from top
// so needs some sync - is question across all of new idea of functions
void SRprobwheel(uint8_t w){ // new detached mode with prob wheel as generator only // for L
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w];
  bitn=ADC_(w,SRlength[w],113,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_);
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// eg. test this with basic modeN which uses binroute for loop or route in from top // for C - seems to workings
void dacNbinprob(uint8_t w){ 
  gate[w].dactype=0; gate[w].dacpar=param[w];
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    if (bitn){
      bitn=0;
      // route from 1
      bitrr = (gate[0].Gshift_[w]>>SRlength[0]) & 0x01;
      gate[0].Gshift_[w]=(gate[0].Gshift_[w]<<1)+bitrr;
      bitn^=bitrr;
    }
    else
      {
	bitn=0;
	JUSTCYCLE_;
      }
    if (!strobey[w][mode[w]]) bitn|=gate[w].trigger;	
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// no gshifts: adc0nog, SRR0nog, same as SR0nog and from modeC: dac67_4bitsNOGG - length has less to do
// do we have options to say strobe/toggle/prob in/out the gshifter? TODO:

// as: SR0nogstrobe, SR0nogtoggle, SRLprobnog, SRintprobnog DONE

void SR0nogstrobe(uint8_t w){ // basic route in no GSHIFT<< strobed
  HEAD;
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (STR0) { // macro now for strobe/trigger
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void SR0nogtoggle(uint8_t w){ // basic route in no GSHIFT<< toggles
  HEAD;
  static uint8_t toggle[4]={0,0,0,0};
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    if (STR0){
      toggle[w]^=1;
    }
    if (toggle[w]) {
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// and finally prob from CVL - detached... - and can also be an intmode TODO
void SRLprobnog(uint8_t w){
  HEADSIN;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

void SRintprobnog(uint8_t w){  // intmode
  HEAD;  
  if (gate[w].trigger)      {
    GSHIFT_;
    // HERE
  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
    PULSIN_XOR;
    BITN_AND_OUTVINT_; 
  } 
}

// don't move at all... xor etc one Sr against another....// and what does length do...
// trial

//*what elements can be used from delta sigma*
// signal input is binroute, subtract cycle bit and pass bits via integrator/comp
//trial - what other functions could be?? bit filter, logic?

void SRsigma(uint8_t w){ 
  HEAD;
  int32_t cycle;
  static int32_t integrator;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_;
  if (bitn) val=1;
  else val=-1;
  if (CYCl) cycle=1;
  else cycle=-1;
  
  integrator+=(val-cycle);
  if (integrator>0) bitn=1;
  else bitn=0;
  PULSIN_XOR;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
  }

// unmoving XOR on strobe - parallel streams - we can have 4 unmoving copy across SRs - they are not SRs... 

/*
void noSRproto(uint8_t w){
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }
*/

// masks to do - but they are also not bitstreams... and we need a bitn for pulses or do a different pulse out
// DONE using   RETURN; TEST!

// trial 12 bits of adc in 
void noSRadc(uint8_t w){
  HEAD; uint32_t k;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  ADCgeneric;
  if (SRlength[w]>11) k=k<<(SRlength[w]-11);
  gate[w].shift_=k;
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_^=tmp;
  RETURN;
  BITN_AND_OUTVNOSHIFT_;
  ENDER;
  }
  }
  }

// and 12 bits out dac
void noSRdac(uint8_t w){ 
  HEAD;
  gate[w].dactype=69; gate[w].dacpar=param[w];
  if (speedf_[w]!=2.0f){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFTNOS_;
    tmp=(gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]]);
    gate[w].shift_=tmp;
    BITN_AND_OUTVNOSHIFT_; 
    ENDER;
  }
  }
}

void noSRcopy(uint8_t w){ // copy in with mask of length
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFTNOS_;
  // copy mask of bits from inroute
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_=tmp;
  PULSIN_XOR;
  gate[w].shift_^=bitn; // where do we put pulse bits? - not much happening
  RETURN;
  BITN_AND_OUTVNOSHIFT_;  
  ENDER;
  }
  }
  }

