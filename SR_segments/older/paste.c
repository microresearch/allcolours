// code for basic pass through so for testing ideas/brainstorming
// bug here with passing on bitn but let's keep it

countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;
  }

  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerl=(shift_registerl<<1)+tmp;
  }
  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  coggl=0;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  else {
    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggl++;
  if (coggl>(SRlengthl+1)) coggl=0;
  coggc=0;
  
  //  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  tmp=((shift_registerc & masky[SRlengthc-3])>>(rightshift[SRlengthc-3]))<<leftshift[SRlengthc-3]; // we want 12 bits but is not really audible difference - updated...

  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  else {
    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerr=(shift_registerr<<1)+tmp;
  }
  coggc++;
  if (coggc>(SRlengthc+1)) coggc=0;
  coggr=0;
  }    
