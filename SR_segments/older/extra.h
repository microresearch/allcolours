// notes/blobs from extractN.c // TODO: L, R, C

// template
/*
static inline uint32_t p(uint32_t depth, uint32_t in, uint32_t w){
  uint32_t x, tmp, bitrr, temp, bitn=0;
  
  return bitn;
}
*/

static inline uint32_t splice(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t val, tmp, bitn;
  tmp=31-(depth>>7); //5 bits
  if ((SRlength[dacfrom[daccount][w]]-tmp)<0) tmp=SRlength[dacfrom[daccount][w]];
  top=SRlength[dacfrom[daccount][w]]-tmp; // length-tmp as long as tmp is less than length
  val=gate[dacfrom[daccount][w]].Gshift_[w]&(masky[tmp]<<top);
  val=val>>top;
  gate[w].shift_^=val;  
  bitn=CYCl;

    }

static inline uint32_t zgsrroute(uint32_t depth, uint32_t in, uint32_t wh){
  uint32_t x, tmp, bitrr, temp, bitn=0;
  tmp=(gate[w].Gshift_[routeto[count][w]])&15;
  for (x=0;x<4;x++){
  if (tmp&0x01){
  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
  bitn^=bitrr;
  }
  tmp=tmp>>1;
    }
}
  
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
  
  void adcLcutfeedback86(uint8_t w){ //    //    TODO/TEST: *cut feedback between dacs 1 and 3 - eg. cut for CV count clk pulses/on off* STROBE

  tmp=(CVL[w]>>2); // 10 bits - how many bits works best?
  bitn^=ADC_(w,SRlength[w],86,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_); 
  //  BINROUTE_; // TODO: route in or not - 2 versions
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

	/////////////////////////////
	
	// from adcetc  
  case 4:  // special case for spaced bit entry depending on length
    // now with route in!
    *SR &=spacmask[length]; //cleared
    ADCtwo;
    k[reg]=k[reg]>>8; // we want 4 bits
    *SR+=(k[reg]&1)+((k[reg]&2)<<spacc[length][reg])+((k[reg]&4)<<spacc[length][1])+((k[reg]&8)<<spacc[length][2]);
    // testing route in of bits from gate[0].Gshift_[regg] or rather dac feedback
    k[reg]=(gate[regg].dac)>>8; 
    *SR^=(k[reg]&1)+((k[reg]&2)<<spacc[length][reg])+((k[reg]&4)<<spacc[length][1])+((k[reg]&8)<<spacc[length][2]);    
    // 4 bits goes in
    // no bt return
    bt=0;
    break;   

    /// lots more adc TODO from adcetc.c // wrap up

    // extract L, R -> what was left    
    /*
  //
  - logopx
  - probability of route X or route Y
  - ghosts
    */

    
