
void SR_binr(uint8_t w){ //

  tmp=CVL[w]>>8; // top4 bits for routing itself
  tmpp=(CVL[w]>>5)&7; // lower 3 bits for binroute selection
    switch(tmpp){
    case 0:
    BINROUTEstrip_;
    break;
    case 1:
    BINROUTESRstrip_;
    break;
    case 2:
    BINROUTEaltstrip_;
    break;
    case 3:
    BINROUTEZEROstrip_;
    break;
    case 4:
    BINROUTESHAREstrip_;
    break;
    case 5:
    BINROUTENOGstrip_;
    break;
    case 6:
    BINROUTEtrigstrip_;
    break;
    case 7:
      BINROUTEnoaltstrip_;  // new one which just cycles and doesn't reset
    break;
    }

  BITN_AND_OUTV_;


void SR_routeSRbits00(uint8_t w){ // fixed SR for route bits: gate[dacfrom[count][w]].Gshift_[w]

  tmp=gate[dacfrom[count][w]].shift_&15; // lowest 4 bits
  BINROUTEstrip_; // also can be different types of binroute
  BITN_AND_OUTV_;

void SR_routeSRbits01(uint8_t w){ //CVL chooses SR for route bits (only 4 SRs so 2 bits, or we route in/xor a 4 bit route)

  tmp=CVL[w]>>8; // 4 bits
  bitrr=0;
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }
  tmp=bitrr;
  BINROUTEstrip_; // also can be different types of binroute
  BITN_AND_OUTV_;

void SR_routeSRbits02(uint8_t w){ //CV chooses SR for route bits for SR for route bits

  tmp=CVL[w]>>8; // 4 bits
  bitrr=0;
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }
  tmp=bitrr;
  bitrr=0;
  for (x=0;x<4;x++){
    if (tmp&0x01){
      bitrr ^= (gate[x].shift_)&15; 
    }
    tmp=tmp>>1; // 4 bits
  }

  tmp=bitrr;
  BINROUTEstrip_; // also can be different types of binroute
  BITN_AND_OUTV_;

void SR_layer1(uint8_t w){ // also use extra bits

  tmp=(CVL[w]>>8); // lowest 4 bits - but we could use 1 extra bit for 8th
  if (tmp==0 || ((CVL[w]>>7)&1)) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01;
    gate[w].shift_ ^=gate[8].Gshare_;
    bitn^=bitrr;
    }

    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	bitn^=bitrr; // we need bitn for pulses
	gate[w].shift_ ^=gate[x].Gshift_[w];
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; // versions which just use SR and no gshift or don;t shift it
      }
      tmp=tmp>>1; // 4 bits
    }
    // clear lowest bit
    gate[w].shift_&=invmasky[0];
    BITN_AND_OUTV_; // version with own bitn add

void SR_layer12(uint8_t w){ // also use extra bits - use sr for this one instaed of CVL

  //  tmp=(CVL[w]>>8); // lowest 4 bits - but we could use 1 extra bit for 8th
  tmp=gate[dacfrom[count][w]].shift_&15;
    if (tmp==0) { // SR5 is 8th which is outside these bits 
    bitrr = (gate[8].Gshare_>>SRlength[8]) & 0x01;
    gate[w].shift_ ^=gate[8].Gshare_;
    bitn^=bitrr;
  }
    else {
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	bitn^=bitrr; // we need bitn for pulses
	gate[w].shift_ ^=gate[x].Gshift_[w];
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; // versions which just use SR and no gshift or don;t shift it
      }
      tmp=tmp>>1; // 4 bits
    }
    }
    // clear lowest bit
    gate[w].shift_&=invmasky[0];

    BITN_AND_OUTV_; // version with own bitn add

void SR_reflect(uint8_t w){ //

    tmp=binroute[count][w];
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
	bitn^=gate[w].localGSR[x]&0x01;
	gate[w].localGSR[x]=(gate[w].localGSR[x]>>1)+(bitrr<<SRlength[x]);
      }
      tmp=tmp>>1; // 4 bits
    }

  BITN_AND_OUTV_;

void SR_altbin1(uint8_t w){ //

  tmp=binroute[count][w];
    for (x=0;x<4;x++){
      if (tmp&0x01){  
	if (gate[w].gsrcnt[x]<0){
	  gate[w].gsrcnt[x]=SRlength[x];
	  
	  if (gate[x].reset[w]){
	    gate[w].localGSR[x]=gate[x].Gshift_[w];
	    gate[x].reset[w]=0;
	  }
	}
	bitrr = (gate[w].localGSR[x]>>gate[w].gsrcnt[x]) & 0x01;
	gate[w].gsrcnt[x]--;
	bitn^=bitrr;
      }
    tmp=tmp>>1;
    }
  
  BITN_AND_OUTV_;

void adc0_altgshift(uint8_t w){ // NON

    
    gate[w].Gshift_[0]=gate[w].shift_ & clksr_[w];
    gate[w].Gshift_[1]=gate[w].shift_ & clksr_[w];
    gate[w].Gshift_[2]=gate[w].shift_ & clksr_[w];
    gate[w].Gshift_[3]=gate[w].shift_ & clksr_[w];
    
    gate[w].reset[0]=1; gate[w].reset[1]=1; gate[w].reset[2]=1; gate[w].reset[3]=1;
    gate[w].Gshare_=gate[w].shift_;
    gate[w].shift_=gate[w].shift_<<1;
    
    
  //  bitn=probbitsxortoggle(CVL[w],w);
    bitn=ADC_(w,SRlength[w],0,bitn,dacfrom[daccount][w],param[w], &gate[w].shift_);  
  BINROUTE_;
  BITN_AND_OUTV_;


void SR_insert_zero(uint8_t w){ //

  //  bitn=probbitsxortoggle(CVL[w],w);
  //  BINROUTE_;
  // route in and deal with reset gate[w].reset[0]=1;
  BINROUTEZERO_;
  
  BITN_AND_OUTV_;

void SR_insert_zero_dac2(uint8_t w){ // non

  //  bitn=probbitsxortoggle(CVL[w],w);
  //  BINROUTE_;
  // route in and deal with reset gate[w].reset[0]=1;
  tmp=binroute[count][w];   
  for (x=0;x<4;x++){
    if (tmp&0x01){
      if (gate[x].reset[w]){
      bitrr = (gate[x].shift_>>SRlength[x]) & 0x01; 
      gate[x].reset[w]=0;
      }
      else bitrr=0;
      bitn^=bitrr;
    }
    tmp=tmp>>1; // 4 bits
    }
  
  BITN_AND_OUTV_;


void SR_probbin(uint8_t w){ //

  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round?
      BINROUTE_;
  }
  else {
    BINROUTEalt_;
  }
  BITN_AND_OUTV_;

void adcone_bitreset(uint8_t w){ // NON

  bitn=adconebitsreset(CVL[w],w);
  BINROUTE_; // with binroute disturbs one bit audio but...
  BITN_AND_OUTV_;


// trial - untie routes...? - layers from geomantic cards...
void SR_recbin(uint8_t w){ // ????
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  bitn=binroutebits(CVL[w],w); // how these layers can differ - 4 layers... 
  if (bitn){ 
    bitn=binroutebits(CVL[w],w); 
  }
  if (bitn){
    bitn=binroutebits(CVL[w],w);
  }
  if (bitn){
    bitn=binroutebits(CVL[w],w);
  }
  BITN_AND_OUTV_;


// trial static inline uint32_t SRproc_hold(uint32_t depth, uint8_t bit){
void SRhold(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  bitn=SRproc_hold(CVL[w]>>4,bitn);
  BITN_AND_OUTV_;

void SRholdfromdac(uint8_t w){ //

  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  tmp=gate[dacfrom[count][w]].dac%(CVL[w]+1);
  bitn=SRproc_hold(tmp>>4,bitn);

void SRothers(uint8_t w){ // length could also be as value/probability against

  //  bitn=probbitsxortoggle(CVL[w],w);
  // BINROUTE_;
  if (singleroutebits(((tmp&12)>>2)<<10, w)){ //prob
    bitn=singleroutebits(((tmp&48)>>4)<<10, w); // route
			 }
    else {
      JUSTCYCLE_;
      bitn=!bitn; /// added so runs better
    }
  PULSIN_XOR;
  BITN_AND_OUTVINT_;
    }
    }
// variations - would be nice with 4 layers... 4x2 8 bits though...


// trial of dacbus... modeC manipulates this mix...
// straight route in so we need params for who to add and maybe type of dac
void dacbus(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>6; // 6 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp>>2, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if ((tmp>>4)!=w) val+=gate[tmp>>4].dac; //other dac... // how change modes for other dacs... or not - but which dac - and not itself
    if (val>4095) val=4095;
    BITN_AND_OUTNODAC_;

void dacbusothers(uint8_t w){ //

    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>5; // 7 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp>>3, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if ((tmp>>4)&1) val+=gate[others[w][0]].dac; // 3 bits - TODO: try also shift out clkbits - any set of 3 bits
    if ((tmp>>5)&1) val+=gate[others[w][1]].dac;
    if ((tmp>>6)) val+=gate[others[w][2]].dac; 
    //    if (val>4095) val=4095;
    // or
    val=val%4095;
    BITN_AND_OUTNODAC_;

void dacbusothers_clk(uint8_t w){ //

    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>8; // 4 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if (clksrG_[others[w][0]]&1) val+=gate[others[w][0]].dac; // 3 bits - TODO: try also shift out clkbits - any set of 3 bits
    if (clksrG_[others[w][1]]&1) val+=gate[others[w][1]].dac;
    if (clksrG_[others[w][2]]&1) val+=gate[others[w][2]].dac; 
    //    if (val>4095) val=4095;
    // or
    val=val%4095;
    BITN_AND_OUTNODAC_;

void dacbusothers_sr(uint8_t w){ //

    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>8; // 4 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if (gate[others[w][0]].shift_&1) val+=gate[others[w][0]].dac; // 3 bits - TODO: try also shift out clkbits - any set of 3 bits
    if (gate[others[w][1]].shift_&1) val+=gate[others[w][1]].dac;
    if (gate[others[w][2]].shift_&1) val+=gate[others[w][2]].dac; 
    //    if (val>4095) val=4095;
    // or
    val=val%4095;
    BITN_AND_OUTNODAC_;

void dacbusothers_own(uint8_t w){ //

    BINROUTE_;
    gate[w].shift_+=bitn;
    tmp=CVL[w]>>6; // 6 bits
    gate[w].dacpar=param[w];
    val=DAC_(w, gate[w].shift_, SRlength[w], tmp>>2, gate[w].dacpar, gate[w].trigger); // modes = 4 bits but some rely on length
    if (gate[tmp>>4].shift_&1) val+=gate[others[w][0]].dac; // 3 bits - TODO: try also shift out clkbits - any set of 3 bits
    if ((gate[tmp>>4].shift_>>1)&1) val+=gate[others[w][1]].dac;
    if ((gate[tmp>>4].shift_>>2)&1) val+=gate[others[w][2]].dac; 
    //    if (val>4095) val=4095;
    // or
    val=val%4095;
    BITN_AND_OUTNODAC_;

void SR_speedx(uint8_t w){ // using speedfroms and CV[w] in fracs and probs.. otherwise not... so we can free it check freecv above //null

    if (freecv[spdfrom]) // do what with it? eg. route/ or use as probability
      {
	bitn=binroutebits(CV[w],w);
		 }
    else {
    BINROUTE_; // or not
    }
    // do dac for non-interpols
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}
*/

// test SRclksrG ghosts
void SR_clksrG(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=SRclksrG(SRlength[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;

void SR_clksr(uint8_t w){ //

  bitn=SRclksr(SRlength[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;

void SR_genspeed2(uint8_t w){

    // ACTION!
    bitn=abstractbitstreamslong[spdfrom](CV[w],w); // without even getting into prob
    //    BINROUTE_; // how to chain in binroutebits (and param for that)

    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

void SR_genspeed3(uint8_t w){ // working now
  HEAD;
  uint32_t par;
  if (gate[w].trigger) gate[w].paramx=CVL[w]; // if we want -  but only on entry // this can also be on trigger - try below
  // or freeze for length
  SRlength[w]=lookuplenall[CVL[w]>>7];
  uint8_t spdfrom=gate[w].paramx>>8; // 4 bits 
  gate[w].dactype=0; gate[w].dacpar=param[w]; 

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }


  if (spdmodes[spdfrom](CV[w],w)){
    GSHIFT_;
    // ACTION!
    //    bitn=abstractbitstreamslong[spdfrom](CV[w],w); // without even getting into prob
    BINROUTE_; // how to chain in binroutebits (and param for that)

    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

SRghost
  // trial here with strobe as revenant but from where?
  //  if (gate[w].trigger){
    depth=gate[w].index+CVL[w];
    if (depth>=4095) depth-=4095;
    tmp=depth/32;
    bitn=(gate[w].delay[tmp]>>(depth%32))&0x01;
    //  }

  BINROUTE_; // or not
  //   // always write or only on strobe
  // if always then goes into OUTV_ below...
  ///  gate[w].delay and index
  if (gate[w].trigger){
  tmp=gate[w].index/32;
  tmpp=gate[w].index%32;
  gate[w].delay[tmp]&=bitmasky[tmpp];
  gate[w].delay[tmp]|=(bitn<<(tmpp));
  gate[w].index++;
  if (gate[w].index>4095) gate[w].index=0;
  }
  BITN_AND_OUTV_;

void SRghostlatch(uint8_t w){ // needs something as CVL seems not do much - added in latch to test


  // trial here with strobe as revenant but from where?
  //  if (gate[w].trigger){
    depth=gate[w].index+CVL[w];
    if (depth>=4095) depth-=4095;
    tmp=depth/32;
    bitn=(gate[w].delay[tmp]>>(depth%32))&0x01;
    //  }

  BINROUTE_; // or not
  //   // always write or only on strobe
  // if always then goes into OUTV_ below...
  ///  gate[w].delay and index
  if (gate[w].latch){
    gate[w].latch=0;
  tmp=gate[w].index/32;
  tmpp=gate[w].index%32;
  gate[w].delay[tmp]&=bitmasky[tmpp];
  gate[w].delay[tmp]|=(bitn<<(tmpp));
  gate[w].index++;
  if (gate[w].index>4095) gate[w].index=0;
  }
  BITN_AND_OUTV_;

void SRxorSR(uint8_t w){

    // 4 bits binroute
    tmpp=CVL[w]>>6; // 6 bits
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }
    // 2 top bits add XOR route
    tmpp=tmpp>>4;
    bitrr = (gate[tmpp].Gshift_[w]>>SRlength[tmpp]) & 0x01; 
    gate[tmpp].Gshift_[w]=(gate[tmpp].Gshift_[w]<<1)+bitrr; 
    bitn^=bitrr;

    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

uint32_t xorroutes[4][2]={
  {3,2},
  {0,3},
  {1,3},
  {0,1}
};
// or bitstream//sel=4or5bits decides if we XOR/add (1bit) in 2 streams which become this one TRIAL
// streamx=streamy+streamz // streamx=streamy^streamz // - how we select those and we need a bitn for pulses - or they are fixed..
// simpler trial version
void SRxorroutes(uint8_t w){ // XOR in 
  HEAD; 
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  // copy mask of bits from inroute
  if (gate[w].trigger){ 
    
    GSHIFTNOS_; 
    gate[w].shift_= (gate[xorroutes[w][0]].Gshift_[w]) ^ (gate[xorroutes[w][1]].Gshift_[w]); 
    // and we need bitn so shift
    bitn=CYCl;
    SHFT;
    BITN_AND_OUTV_;
  }
  else
    {
      GSHIFT_;
      BINROUTE_; 
      BITN_AND_OUTV_;
    }

void SRaddroutes(uint8_t w){ // how to add without overflow - long

    temp = (gate[xorroutes[w][0]].Gshift_[w]) + (gate[xorroutes[w][1]].Gshift_[w]);
    gate[w].shift_=(temp&masky[SRlength_[w]]); //
    // and we need bitn so shift
    bitn=CYCl;
    SHFT;
    BITN_AND_OUTV_;   
  }
  else
    {
      GSHIFT_;
      BINROUTE_; 
      BITN_AND_OUTV_;
    }

void noSRxorroutes(uint8_t w){ // XOR in // null

    tmp=binroute[count][w];
    for (x=0;x<4;x++){
    if (tmp&0x01){ // use length for something else? prob?
      gate[w].shift_^= (gate[x].Gshift_[w]); // or length of that mask is another parameter - strobe mode - but that length doesnt do much except stop
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;   // dont add in bitn
  }
  else
    {
      GSHIFT_;
      JUSTCYCLE_; // or could be BINROUTE
      PULSIN_XOR;
      BITN_AND_OUTV_;
    }

void SR_vienna(uint8_t w){  

    // bitn opp can be inserted... eg. LFSR
    // XX
    // 4 bits for route
    tmp=(tmpp&15); // lowest 4 bits - other logical ops - logops from bits - noisy as CV noise
    for (x=0;x<4;x++){
      if (tmp&0x01){
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
      tmp=tmp>>1; // 4 bits
    }

    // and prob thing
    /*
    doit[w]=(mode[w]>>4)&0x01; // top bit maybe
    if (doit[w] && dac[whichdoit[w]]<param) bitn^=1; //     if (tmp<adc_buffer[0]) bitn^=1; - 12 bits TO TEST!
    */
    if ((tmpp>>4)&0x01) {
      if (gate[dacfrom[count][w]].dac<tmppp) bitn^=1;
	}
      
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}



// switch by CV between CVspeed and strobe speed
// or could be simple prob/bit switch. - new twist of if (bitstream) spdfrom=
// but we run out of CVs- 1speed, CVL-selectbitstream, param for bitstream... - which now is dac - heading in new direction/abstract furtherTODO!
// and think of length
// also how prob is extracted into bitsfrom - how to chain bitsfrom: eg.  bitsprob decides spdfrom of bitsotherprob entry of bitsmode etc...
// bit chain IS the 4 SRs in some configuration?
void SR_switchspeed(uint8_t w){  
  HEADSIN;
  uint32_t tmpp;
  uint8_t spdfrom; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test
  tmp=CVL[w]>>7; // 5 bits 
  tmpp=abstractbitstreamslong[tmp](CV[w],w);
  if (tmpp) spdfrom=0; // alternatives
  else spdfrom=2;
  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](gate[speedfrom[spdcount][w]].dac,w)){ // replace CV[w] with dac?
    GSHIFT_;
    BINROUTE_; // or not
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

//uint32_t (*spdmodes[16])(uint32_t depth, uint8_t wh)={speedfrac, speedfrac, strobebits, binroutebits, binroutebits_noshift, binroutebits_noshift_transit, strobeint, probbits, TMsimplebits, osceqbits, osc1bits, onebits, ENbits, ENsbits, compbits, compdacbits}; // just to test - tested
// how many more could we use?

//select spdmode - select our speedmode with CV/L?
void SR_selspeed(uint8_t w){ // TEST!
  HEADSIN;
  uint32_t tmpp;
  uint8_t spdfrom; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test
  spdfrom=CVL[w]>>7; // 4 bits 16 ops - could be more... trial... // tested // now try abstract // was 4 bits
  //  spdfrom=11;
  if (interpoll[spdfrom])   { // and if we don't use CV?
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  //  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w]
  if (abstractbitstreamslong[spdfrom](CV[w],w)){ // testing was just spdmodes and 4 bits/16 operations
    GSHIFT_;
    BINROUTE_; // or not
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// 25/4/2022

// xortoggle-PROBability mode xor strobe in gen.h
void SRprobxortog(uint8_t w){ // 
  HEADSIN;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  if (probbitsxortoggle(CVL[w],w)) {
      BINROUTE_; // or not
    }
    else
      {
	JUSTCYCLE_;
      }
  BITN_AND_OUTV_;

void SRprobxortogx(uint8_t w){ //

  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;

void SR_strobeint(uint8_t w){ // testing - not sure... this is generic one as all we have is spdfrom=6 /// try other spdmodes here

    BINROUTE_; // or not
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// pattern match bitstream from bitdsp: if pattern of length matches then flip bit eg... as gen?
// match lower parts of lengthx, from 2 other SRs (4 bits) - flip incoming bit if match
// so is either as strobe or detached/// CVL // but where we get length cv? or use 2 bits length <<1 and 4 comp
void SRmatch(uint8_t w){ // pattern matcher - could be longer pattern
  HEADSIN;
  uint32_t tmpp;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  tmp=CVL[w]>>6; // 6 bits
  tmpp=masky[(tmp>>4)]; // top 2 bits
  if ( (gate[tmp&0x03].Gshift_[w]&tmpp)==(gate[((tmp&12)>>2)].Gshift_[w]&tmpp)) val=1;
  else val=0;
  BINROUTE_; // or not
  if (val) bitn=!bitn; // invert // or can be other op/choice... abstract out!
  BITN_AND_OUTV_;

void SRmatch_strobe(uint8_t w){ // testing - we free length and use spd for sel

    tmp=CV[w]>>8; // 4 bits
    tmpp=masky[31-(CV[w]>>7)]; // 5 bits - could also be double match with tmpp as no/mask
    if ( (gate[tmp&0x03].Gshift_[w]&tmpp)==(gate[(tmp>>2)].Gshift_[w]&tmpp)) val=1;
    else val=0;
    BINROUTE_; // or not
    if (val) bitn=!bitn; // invert // or can be other op/choice... abstract out!

    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// 22/4/2022

// think about abstractions and grids///printing maybes....
// slides and splits - grids of modes and params/values and entry of SRs into these...
// shall we look again at rung in rungler

// RSR master mode: cut all routes // open close route bit with clock/toggle

// uses count to set binroute to 16 // only for right hand side - we had/have this in modeR: SRRstroberoute
void SRRcutallroutes(uint8_t w){  
  HEAD;
  if (gate[w].trigger) count=16; // placed outside speed
  else count=0;

  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  BINROUTE_; // or not
  BITN_AND_OUTV_;

void SRRtoggcutallroutes(uint8_t w){ // toggle version of above

  BINROUTE_; // or not
  BITN_AND_OUTV_;

void SRRbinrcutallroutes(uint8_t w){


  if (binroutebitsI(CVL[w],w)) count=16; // placed inside speed
  else count=0;
  
  BINROUTE_; // or not
  BITN_AND_OUTV_;

void SRshare(uint8_t w){ // shared bits

  bitn^=shared(SRlength[w],w); // doesn't use length
  BINROUTE_; // or not
  BITN_AND_OUTV_;

//void (*moodsfuncs[64])(uint8_t w, moods *mode)={SRitselftry2}; // list of functions and then we can call for example    (*dofunc[www][mode[www]])(www);

  /// CORE
  gate[w].shift_=gate[w].shift_<<(abstractbitstreamslong[mode->gsfr](mode->par0[w], w)); // is this within outer spd? we could have different versions
    if (abstractbitstreamslong[mode->probfr](mode->par2[w], w)){ // prob
      bitn=abstractbitstreamslong[mode->incfr](mode->par3[w], w); // what?
    }
    else
      { 
	bitn=abstractbitstreamslong[mode->par3[w]](mode->par3[w], w); // or?
      }
  
  bitn=mode->logic(bitn, abstractbitstreamslong[mode->last](mode->par4[w], w)); 
  ///  
    if (!interpol){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTVNOSHIFT_; // part of interpol - val=DAC but fits for all - now without +bitn
    new_data(val,w);
  }
}

// earlier abstraction
// question is how to avoid running same functions twice in abstractbitstreams-> unless we want to
// also here we have 5 parameters

// still thinking on some kind of grid!

/*
void SRitselftry2(uint8_t w, moods *mode){ // pass in structure - null
  HEADSSINNADA; // detach depending on what/
  if (abstractbitstreamslong[mode->spdfr](mode->par1[w], w)){  // spd - for intmodes we can lose this // moved speed UP
  GSHIFTNOS_;
  /// CORE
  gate[w].shift_=gate[w].shift_<<(abstractbitstreamslong[mode->gsfr](mode->par0[w], w)); // is this within outer spd? we could have different versions
    if (abstractbitstreamslong[mode->probfr](mode->par2[w], w)){ // prob
      bitn=abstractbitstreamslong[mode->incfr](mode->par3[w], w); // what?
    }
    else
      { 
	bitn=abstractbitstreamslong[mode->par3[w]](mode->par3[w], w); // or?
      }
  
  bitn=mode->logic(bitn, abstractbitstreamslong[mode->last](mode->par4[w], w)); 
  ///  
  BITN_AND_OUTVINT_; // abstract out maybe

void abstract(uint8_t w){  // was abstractoutinterpolroute null

    gate[w].shift_=gate[w].shift_<<1;
    // bt= //
    // << appropriate GSR(s)
    /* // simple SR

    GSHIFT_; //-> copy to GSR and shift <<SR as 2 sep ops
    bitn=binroutebitsI(CVL[w],w); // seperate speed of dac and <<GSR
    gate[w].shift_+=bitn;						\
    */

    /* delayline noSR
       GSHIFTNOS_;
    
       BINROUTE_; // generators/prob/other routes/
       PULSIN_XOR;
       gate[w].shift_&=bitmasky[counter[w]];
       gate[w].shift_|=(bitn<<counter[w]);
       counter[w]++;
       if (counter[w]>SRlength[w]) counter[w]=0;
     */

    /*noSR noSRxorroutes
    GSHIFTNOS_;
    tmp=binroute[count][w];
    for (x=0;x<4;x++){
    if (tmp&0x01){ // use length for something else? prob?
      gate[w].shift_^= (gate[x].Gshift_[w]); // or length of that mask is another parameter - strobe mode - but that length doesnt do much except stop
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;

     */
    
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTVNOSHIFT_; // part of interpol - val=DAC but fits for all - now without +bitn
    new_data(val,w);
  }
}

// // from below,,,, we need to lose << on GSR to slow things down... 
// doesn't slow much -> problem is that series of 1s will trigger - we need transition
// but that doesn;t work for say fractionals (also if strobe is held we keep on)...
// try in gen - slower is DONE...

// version with no << GSR for incoming speed // and only on a transition - that one slows down but is not so exciting
void abstractoutinterpolnoshift(uint8_t w){ 
  HEADNADA;
  uint8_t spdfrom=4;  // spdfrom 3 is noshift, 4 is that one but only on a change
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    bitn=binroutebitsI(CVL[w], w); // independent from shared one above - cycle on strobe
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// 20/4/2022

// DONE:
// rungler in rungler but split across - is this not what we have with abstracted out versions below
// how we define independent rungler: as below IN=binroute and spdfrom=binroute but it has cycle...

//*abstract out interpol and strobe*
// start with basic function exposed

void base(uint8_t w){ // basic template // null
  HEAD;
  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    BINROUTE_; 
    BITN_AND_OUTV_;

void abstractoutinterpol(uint8_t w){

    BINROUTE_;
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// binroute and spdroute from routes and recursion - this one does this! but recursion is tricky without clock injection

// add in binroute
// but problem is if both run binroute - each instance is not independent even with I as indep. as is same w!
void abstractoutinterpolroute(uint8_t w){ 
  HEADNADA;
  uint8_t spdfrom=2;
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    bitn=binroutebitsI(CVL[w],w); // independent from shared one above - 
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// rungler version for rung in rung across all -> with cycle/cycle on strobe
void abstractoutinterpolrung(uint8_t w){ 
  HEADNADA;
  uint8_t spdfrom=2; 
  gate[w].dactype=0; gate[w].dacpar=param[w]; // test

  if (interpoll[spdfrom])   {
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  if (spdmodes[spdfrom](CV[w],w)){ // replace CV[w] 
    // core
    GSHIFT_;
    bitn=binroutebitscyclestrI(CVL[w], w); // independent from shared one above - cycle on strobe
    // do dac for non-interpols
    if (!interpoll[spdfrom]){
    gate[w].dac = delay_buffer[w][1];
    }
    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

// 19/4/2022

//+gens->bitspeed (do we not have that?): yes as adcspeedstream in modeN.h but still we need to improve generators+

///////////......

// *** how to take characteristics and split these across SRs while keeping some structure... code to write/chop code, multiple opposing speeds...

// look again bitdsp and parallel bit processings

/// trigger oversamples (at speed)
// how do we oversample - run twice at speed...
// run twice but if we are slow others would have to wait... so just run twice...

// these can also be selecting different types of ADC and detached...
void ADCovers(uint8_t w){ 
  HEAD;
  // 2nd round - was inside loop - fix << though
  if (gate[w].trigger){
  gate[w].shift_=gate[w].shift_<<1;
  bitn=adcpadbits(SRlength[w]);
  gate[w].shift_+=bitn;
  }

  if (speedf_[w]!=LOWEST){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  bitn=adcpadbits(SRlength[w]);
  BINROUTE_; // or not! 
  BITN_AND_OUTV_;

void ADCoverss(uint8_t w){   // 2nd round - was inside loop - fix << though

  bitn=adcpadbits(SRlength[w]);

  if (gate[w].trigger){
  gate[w].shift_+=bitn;
  gate[w].shift_=gate[w].shift_<<1;
  bitn=adcpadbits(SRlength[w]);
  }
    
  BINROUTE_; // keep bin
  BITN_AND_OUTV_;

void ADCoversss(uint8_t w){   // 2nd round - was inside loop - fix << though

  bitn=adcpadbits(SRlength[w]);

  if (gate[w].trigger){
  gate[w].shift_+=bitn;
  gate[w].shift_=gate[w].shift_<<1;
  //  bitn=adcpadbits(SRlength[w]);
  }
  // so same bitn will come in
  BINROUTE_; // keep bin
  BITN_AND_OUTV_;

void ADCoverssss(uint8_t w){   // 2nd round - was inside loop - fix << though

  bitn=adcpadholdbits(SRlength[w],1);  // that one advances things so above trigger own is same bit - or vice versa
  BINROUTE_; // 
  BITN_AND_OUTV_;

void ADChold(uint8_t w){   // 2nd round - was inside loop - fix << though

    }
    else
      {
	GSHIFT_;
      }
  */
    GSHIFT_;
    bitn=adcpadholdbits(SRlength[w], (!gate[w].trigger)); // trigger will hold it...
    BINROUTE_; 
    BITN_AND_OUTV_;

void ADCholdcycle(uint8_t w){   // 2nd round - was inside loop - fix << though

    bitn^=adcpadholdcyclebits(SRlength[w], (gate[w].trigger)); // trigger will hold it
    BINROUTE_; 
    BITN_AND_OUTV_;

void ADCnoisecmp(uint8_t w){  // for top modeN

  ADCgeneric;  
  if (((LFSR_[w] & 4095 ) > k)){   // this way round?
    // select gen and input
    bitn=(*abstractbitstreams[CVL[w]>>8])(CV[w],w); // oops need 2 CVs - 4 bits for first one - leaves 2 bits spare...
  }
  else
    {
      JUSTCYCLE_; // no length/speed - is a bit odd - discards bits
    }
  //  BINROUTE_; // or not! could use excess bits?
  BITN_AND_OUTV_;

void ADCnoisecmpSTROBE(uint8_t w){  // for top modeN

  ADCgeneric;  
  if (((LFSR_[w] & 4095 ) > k)){   // this way round?
    // select gen and input
    bitn=(*abstractbitstreams[CVL[w]>>8])(CV[w],w); // oops need 2 CVs - 4 bits for first one - leaves 2 bits spare...
  }
  else
    {
      JUSTCYCLE_; // no length/speed - is a bit odd - discards bits
    }
  //BINROUTE_; // or not! could use excess bits?
  BITN_AND_OUTVINT_;
  }
}

  
// 18/4/2022

// TODO: more multiple speeds
/// *TODO: dacspeed and internal speed slip against each other: gshift and... see multiple speeds where we have dac but not as core speed*

void SRmultiplespeednewdac0(uint8_t w){ // - NO LENGTH - speeds of gshift, incoming gsr and bits/dac
  HEADSSIN;
  float speedf__;
  
  if (gate[w].trigger) GSHIFTNOS_; // // 1.copy gshift on trigger// sans <<

  if (counter[w]>CV[w]){ //2.advance incoming ghost on speed
    counter[w]=0;
    BINROUTEADV_;
  }

  speedf__=logspeed[gate[speedfrom[spdcount][w]].dac>>2]; // that's 10 bits only - can also have scaling by CV 
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    gate[w].shift_=gate[w].shift_<<1; 
    BINROUTENOG_; // no gshifty
    BITN_AND_OUTV_;

void SRmultiplespeednewdac(uint8_t w){ // NO LENGTH - try 4 speeds as above - multiple versions of this // this one is ****


  if (counter[w]>CV[w]){ //3.advance incoming ghost
    counter[w]=0;
    BINROUTEADV_;
  }

  if (counterd[w]> CVL[w]){
      counterd[w]=0;
    gate[w].shift_=gate[w].shift_<<1; // 1. shifter
  }
  
  speedf__=logspeed[gate[speedfrom[spdcount][w]].dac>>2]; // that's 10 bits only - can also have scaling by CV 
  CVOPENDAC;
  if(gate[w].last_time<gate[w].int_time)      {
    //    gate[w].shift_=gate[w].shift_<<1; // but no shift makes odd with add... anyways
    BINROUTENOG_; 
    PULSIN_XOR;
    BITN_AND_OUTVXOR_;

void noSRdelay_line(uint8_t w){

  //  bitn^=delay_line_shared(CVL[w],w); // or detach - length not used - this is our binroute
  BINROUTE_; // generators/prob/other routes/
  PULSIN_XOR;
  gate[w].shift_&=bitmasky[counter[w]];
  gate[w].shift_|=(bitn<<counter[w]);
  counter[w]++;
  if (counter[w]>SRlength[w]) counter[w]=0;
  BITN_AND_OUTVNOSHIFT_;

void SRdelay_lineSH(uint8_t w){

  bitn^=delay_line_shared(CVL[w],w); // or detach - length not used - this is our binroute
  BITN_AND_OUTV_;

void SRdelay_lineSH2(uint8_t w){

  bitn^=delay_line_shared2(CVL[w],w); // or detach - length not used - this is our binroute
  BITN_AND_OUTV_;

void SRdelay_line(uint8_t w){

  bitn^=delay_line_unshared(CVL[w],w); // or detach - length not used - this is our binroute
  BITN_AND_OUTV_;

void SRpattern_unshare(uint8_t w){ // sequential 12 bit in - use also for L, R, N

  bitn^=pattern_unshare(SRlength[w],w); // or detach - length not used
  BINROUTE_; // or not
  BITN_AND_OUTV_;

void SRLdecaying(uint8_t w){

  BINROUTE_;
  dec=(4096/SRlength[w]);
  for (tt=SRlength[w];tt>0;tt--){
    //    if (highestprob) flipbitx
    //highestprob-lessens
    if ( (LFSR_[w] & highestprob) > CVL[w]) {
	gate[w].shift_^=(1<<tt); // flips
      }
      highestprob=highestprob-dec;      
  }
  
  BITN_AND_OUTV_;

void stream4_unshare(uint8_t w){ // sequential 12 bit in - use also for L, R, N

  bitn^=adc4bits_unshare(11,w);
  BINROUTE_; // or not
  BITN_AND_OUTV_;

void adccipher(uint8_t w){ // generator is contained so is different to one below which can have binroute inside

  ///////HERE
  bitn^=cipherbits(CVL[w], w); // not using depth
  BINROUTE_; // or not!
  BITN_AND_OUTV_;

void adccipher2(uint8_t w){    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)


    GGGshift_[w]=GGGshift_[w]<<1;
    BINROUTE_; // here binroute is in different place or not - to above
    bitn^=ADC_(w,SRlength[w],85,gate[w].trigger,dacfrom[daccount][w],param[w], &gate[w].shift_);
    PULSIN_XOR; // not for adc ignore
    GGGshift_[w]+=bitn;
    
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_[w]&masky[SRlength[w]]);// to check again
    } 
    bitn=CYCl;
    BITN_AND_OUTVNOSHIFT_;

void recurse(void (*f)(void)){ // but again we would have to have: recurse(void (*f)(void (*f)(void (*f)(void (*f)(void (*f)(void))))) etc...

  /// CORE
  gate[w].shift_=gate[w].shift_<<(abstractbitstreamslong[gsfr](par0[w], w)); // shift or not
    if (abstractbitstreamslong[probfr](par2[w], w)){ // prob
      bitn=abstractbitstreamslong[incfr](par3[w], w); // what?
    }
    else
      { 
	bitn=abstractbitstreamslong[par3[w]](par3[w], w); // or?
      }
  bitn=logic(bitn, abstractbitstreamslong[last](par4[w], w)); 
  BITN_AND_OUTV_; // abstract out maybe

void SRintprobnog(uint8_t w){  // intmode


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
void SRitself(uint8_t w){ // null
uint8_t prob;
  HEADSSINNADA;
  if (speedf_[w]!=LOWEST){ 
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
    // CORE
  bitn=itself(osceqbits,binroutebits,CV[w], CVL[w], w); // but we would need additional 8 bits (4+4) to set each of these - from another SR!!!
  // abstractbitstreams[x], abstractbitstreams[y]   
  BITN_AND_OUTV_; // abstract out maybe

void SRGswop(uint8_t w){// swap over SRs on pulse in?!! or swop in only (can swop in previous SR or another?)

    // INSERT!
    BINROUTE_;
    //    if (gate[w].trigger) gate[w].shift_=gate[w].Gshift_[w]; // could also be incoming one
    if (gate[w].trigger) gate[w].shift_=gate[inroute[count][w]].Gshift_[w]; // could also be incoming one
    BITN_AND_OUTV_;

void noSRxorroutes(uint8_t w){ // XOR in

    tmp=binroute[count][w];
    for (x=0;x<4;x++){
    if (tmp&0x01){ // use length for something else? prob?
      gate[w].shift_^= (gate[x].Gshift_[w]); // or length of that mask is another parameter - strobe mode - but that length doesnt do much except stop
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;   // dont add in bitn
  }
  else
    {
      GSHIFT_;
      JUSTCYCLE_; // or could be BINROUTE
      BITN_AND_OUTV_;
    }

void noSRselxorroutes(uint8_t w){ // XOR in

    tmp=CVL[w]>>8; // 
    for (x=0;x<4;x++){
    if (tmp&0x01){ 
      gate[w].shift_^= (gate[x].Gshift_[w]); // but length doesnt do much except stop - xor itself is a 0 too
      bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
      //    bitn^=bitrr; // lowest 2 bits for logic
      bitn=logop(bitn,bitrr,(CVL[w]>>6)&3);
  }
  tmp=tmp>>1;
  }
  PULSIN_XOR;
  BITN_AND_OUTVNOSHIFT_;   // dont add in bitn

void SRshroute(uint8_t w){ // strobe could also shift on

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
  BITN_AND_OUTV_;

void SRprobwheel(uint8_t w){ // new detached mode with prob wheel as generator only // for L

  tmp=CVL[w];
  bitn=ADC_(w,SRlength[w],113,gate[w].trigger,dacfrom[daccount][w],tmp, &gate[w].shift_);
  BITN_AND_OUTV_;

void dacNbinprob(uint8_t w){

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

void SR0nogstrobe(uint8_t w){ // basic route in no GSHIFT<< strobed

    if (STR0) { // macro now for strobe/trigger
      BINROUTENOG_;
    }
    else
      {
	BINROUTE_;
      }
    BITN_AND_OUTV_;

void SR0nogtoggle(uint8_t w){ // basic route in no GSHIFT<< toggles

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
    BITN_AND_OUTV_;

void SRLprobnog(uint8_t w){

  if (((LFSR_[w] & 4095 ) > CVL[w])){   // this way round
    BINROUTE_;
  }
  else {
    BINROUTENOG_;
  }
  BITN_AND_OUTV_;

void SRintprobnog(uint8_t w){  // intmode

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
  if (speedf_[w]!=LOWEST){
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
  BITN_AND_OUTV_;

void noSRproto(uint8_t w){ // null

  BITN_AND_OUTVNOSHIFT_;

void noSRadc(uint8_t w){

  ADCgeneric;
  k=k>>(leftshift[SRlength[w]])<<rightshift[SRlength[w]]; // fill length
  gate[w].shift_=k;
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_^=tmp;
  RETURN;
  BITN_AND_OUTVNOSHIFT_;

void noSRadc2s(uint8_t w){

  ADCgeneric;
  if (k<2048) bitwise=1;
  else bitwise=0;
  k=abs(k-2048);
  if (bitwise) k=(~k)+1;
  k=k>>(leftshift[SRlength[w]])<<rightshift[SRlength[w]]; // fill length
  gate[w].shift_=k;
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_^=tmp;
  RETURN;
  BITN_AND_OUTVNOSHIFT_;

void noSRdac(uint8_t w){

    tmp=(gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]]);
    gate[w].shift_=tmp;
    BITN_AND_OUTVNOSHIFT_;

void noSRdac2s(uint8_t w){

    tmp=(gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]]);
    gate[w].shift_=tmp;
    BITN_AND_OUTVNOSHIFT_;

void noSRdac2sRLxor(uint8_t w){  // xor of left and right

    tmp=(gate[1].Gshift_[w]&masky[SRlength[1]]);
    gate[w].shift_=tmp^(gate[3].Gshift_[w]&masky[SRlength[3]]);
    BITN_AND_OUTVNOSHIFT_;

void noSRcopy(uint8_t w){ // copy in with mask of length

  // copy mask of bits from inroute
  tmp=gate[inroute[count][w]].Gshift_[w]&masky[SRlength[w]];
  gate[w].shift_=tmp;
  gate[w].shift_^=bitn; // where do we put pulse bits? - not much happening
  RETURN;
  BITN_AND_OUTVNOSHIFT_;

  
