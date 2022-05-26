// template/s

void SRxxx(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=2.0f){
    CVOPEN; // CVOPENNOINTERPOL
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn^=
  BINROUTE_; // or not
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}

void SRxxxx(uint8_t w){
  HEAD;
  uint32_t tmpp;
  uint8_t spdfrom=0; //set.choose - here is frac
  gate[w].dactype=0; gate[w].dacpar=param[w]; 

  if (interpoll[spdfrom])   { // place in spdmodes TODO
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }
  
  if (spdmodes[spdfrom](CV[w],w)){
    GSHIFT_;
    // bitn=
    BINROUTE_; // or not

    BITN_AND_OUTV_; // part of interpol - val=DAC but fits for all
    new_data(val,w);
  }
}

void SR_xx_xx(uint8_t w){ // 
  HEAD;
  if (speedf_[w]!=2.0f){
  CVOPEN;
  if(gate[w].last_time<gate[w].int_time)      {
  GSHIFT_;
  //  bitn=probbitsxortoggle(CVL[w],w);
  BINROUTE_;
  BITN_AND_OUTV_;
  ENDER;
  }
  }
}




// towards new minimal template which handles most conditions eg. interpol/none, detachment
/*
1.new gshift/old gshift // we always need to reset
2.all dacs interpol/no interpol
3.frozen or not - is that an option? or just keep with lowest frozen and slow speeds - or no freeze on NSR/out
4.use of clk/pulsin-xor
5.clean up so less macros and is a bit more general - also between interpol/direct dac access
6.detachment of CVs - take out of adcetc///
7.anything else to add in, eg., recording modes, last values etc...
8.clkbit, other params

so for our modes we can also define strobey - pull out of binroute and place where?

mode grid needs:
function, strobey, interpoll, inner_function?, detach?, 

*/

// breaking down again into subfunctions, how these can be more spread out...
// 16 spdmodes with associated interpool yes/no
/*
static modez newmodes[128]={ // then call mode by number
  {0,0,0,0, SRx_x, innertest}
};
(*newmodes[choice].func)(www, newmodes[choice].strobey, newmodes[choice].detachlen, newmodes[choice].detachspeed, newmodes[choice].interpoll, newmodes[choice].innerfunc);   
*/

/*
 think of access to eg. pointer or value... eg. for spdmode

if (spdpnt) val=*spdpntr;
else val=spdval;

*/

// we can also sub in speedfroms and other generators -> more generic
void SRx_x(uint8_t w, uint32_t strobey, uint32_t detachlen, uint32_t  detachspeed, uint32_t interpoll, uint32_t (*innerfunc)(uint8_t w)){
  HEADNADA;
  if (detachlen) SRlength_[w]=lookuplenall[CVL[w]>>7]; // can be detached...
  if (detachspeed) speedf_[w]=slowerlog[CV[w]>>2]; // or we could look at list of for each mode/// different speedlogs (fractional...)
  if (w==2 || speedf_[w]!=2.0f){ // ignored if we don't have the stop... and if we are modec
    // interpol or not
    if (interpoll)   { // but interpoll only makes sense for 2 modes... which are in speedfrom
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else {
    gate[w].dac = delay_buffer[w][1];
    }

    gate[w].time_now += speedf_[w]; // this is in necessary speedfrom for frac speeds
    gate[w].last_time = gate[w].int_time;
    gate[w].int_time = gate[w].time_now;

    if(gate[w].last_time<gate[w].int_time)      {
    GSHIFT_;
    // CORE - types of binroute// new macro is BINROUTEalt_;
    bitn=(*innerfunc)(w);//   (*dofunc[www][mode[www]])(www); --> innerfunc passed params if needed? and if we have CV...
    if (strobey) bitn|=gate[w].trigger;	 // or
    BITN_AND_OUTV_; 
    ENDER;
  }    
  }
}

uint32_t innertest(uint8_t w){
  uint32_t bitn=0, tmp, x, bitrr;
  BINROUTE_;
  return bitn;
}


