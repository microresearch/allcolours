/// from here
static inline uint32_t countbits(uint32_t i)
{
    return( countbts[i&0xFFFF] + countbts[i>>16] );
}

/*
static inline uint8_t probableCV(uint32_t reg, uint32_t type){
  // LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
  // prob of cycling bit let's say or ADC bit in or...
  switch(type){
  case 0:
    if ((LFSR_[reg] & 4095 )< (shift_[reg]& 4095))      return 1;
    break;
  case 1:
    if ((LFSR_[reg] & 4095 )< (shift_[defroute[reg]] & 4095))      return 1;
    break;
  case 2:
    if ((shift_[reg] & 4095 )< (shift_[defroute[reg]] & 4095))      return 1;
    break;
  case 3:
    if ((LFSR_[reg] & 4095 ) < (param[reg] & 4095))      return 1;
    break;
  }    
  return 0;
}

static inline uint8_t otherprobableCV(uint32_t reg, uint32_t type){ // this one is 2 bits
  // LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
  // prob of cycling bit let's say or ADC bit in or...
  switch(type){
  case 0:
    if ((LFSR_[reg] & 4095 )< (shift_[reg]& 4095))      return 1;
    break;
  case 1:
    if ((LFSR_[reg] & 4095 )< (shift_[defroute[reg]] & 4095))      return 1;
    break;
  case 2:
    if ((LFSR_[reg] & 4095 ) < (param[reg] & 4095))      return 1;
    break;
  }    
  return 0;
}
*/


// 0-31 (32)modes +1 INTmode
// arrange modes now as most important first...


// 18/1/22
// more generic ADC_ in = so income is passed in function and can be LFSR so we have different handlings
static inline int ADCg_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR, uint32_t *income){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator=0.0f, oldValue=0.0f;
  static uint32_t k, lastbt=0; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  static uint8_t toggle=0, lc=0;
  uint32_t bt=0, bit=0;
  float inb;

  switch(type){
    
  case 0: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(*income)>>(11-length);
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
  }
}
  
// 10/12/21 - changes to SR in place now for draftspeed.c

static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar, uint32_t *SR){
  static int32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator=0.0f, oldValue=0.0f;
  static uint32_t k, lastbt=0; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  static uint8_t toggle=0, lc=0;
  uint32_t bt=0, tmp=0;
  float inb;

  
  switch(type){
    /* // LSB first
  case 0: // basic sequential length of upto 12 bits cycling in    
      if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length);
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01; // this means that LSB comes out first
    n[reg]++;    
    break;
    */

    
  case 0: // basic sequential length of upto 12 bits cycling in MSB first    
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(adc_buffer[12])>>(11-length);
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 1: // equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      k=(adc_buffer[12]); //
      k=k/divy[length];
      n[reg]=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    n[reg]++;    
    break;

    /*
  case 2: // one bit audio input - can also change the 48??? - this one makes wierd phase effects
    n[reg]++;
  if (n[reg]>48) {
    k=(adc_buffer[12]); 
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;
    */
        
  case 2: // variations on one bit audio - also phasey
    k=(adc_buffer[12]); // from 0 to 4095 but where is the middle? - also we do nothing here with length
    integrator+=(k-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;    


    /*
  case 2: // try with float but this is the same with phasings
    inb=(((float)adc_buffer[12])/2048.0f)-1.0f; // from 0 to 4095 but where is the middle?
    integrator+=(inb-oldValue);
   if(integrator>0.0f)
  {
     oldValue=1.0f;
     bt=1;
  }
   else
   {
      oldValue=-1.0f;
      bt=0;
   }   
   break;    
    */     

   /*      
  case 3: // basic sequential length as in 0 but with padding if >11 bits **
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else {
	  k=(adc_buffer[12]);//<<(length-11); // should be -11 // pads with 0s at the bottom LSB first
	  //	  k+=((k>>length-11)&masky[length-11]); // pad with a repeat?
	  //	  k+=padding[length-11]; // TESTY! - padding with 1s
	}
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
   */


  case 3: // basic sequential length as in 0 but with padding if >11 bits **
    // as above but closer to 5
    // also try as MSB - now...
    if (n[reg]<0) { // 12 bits
      if (length<12) {
	k=(adc_buffer[12])>>(11-length);
	n[reg]=length;
      }
      else {
	k=(adc_buffer[12]);
	n[reg]=11;
      }
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;    
    break;

   /*
  case 3: // basic sequential length as in 0 but with padding if >11 bits **
    // REVERSAL again doesn't change much
      if (n[reg]<0) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else {
	  k=(adc_buffer[12])<<(length-11); // should be -11 // pads with 0s at the bottom LSB first
	  // double up
	  //  k+=((k>>length-11)&masky[length-11]); // pad with a repeat?
	  //	  k+=padding[length-11]; // TESTY! - padding with 1s - doesn't change much
	}
	n[reg]=length;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;    
    break;
   */
   /*
  case 3: // basic sequential length of upto 12 bits cycling in MSB first    
        if (n[reg]<0) {
	  //	  k=pow(2,length)+1;
	  k++;
	  if (k>4095) k=0;
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
   */
   /*  case 3: // basic sequential length of upto 12 bits cycling in MSB first    
        if (n[reg]<0) {
	  k=adc_buffer[12];
	  n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
   */   

  case 4:  // special case for spaced bit entry depending on length
    *SR &=spacmask[length]; //cleared
    k=(adc_buffer[12])>>8; // we want 4 bits
    *SR+=(k&1)+((k&2)<<spacc[length][0])+((k&4)<<spacc[length][1])+((k&8)<<spacc[length][2]);
    // 4 bits goes in
    // no bt return
    bt=0;
    break;   
    
  case 5: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
        ////// full length regardless of len    
      if (n[reg]>11) {
	k=adc_buffer[12];
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 6: // timed version of SR bitsin -
    //    if (length>11) length=11;
    if (n[reg]) {
      if (length>11){
      ADCshift_[reg]=(adc_buffer[12]<<(length-11));
      }
      else ADCshift_[reg]=(adc_buffer[12]);
    n[reg]=0;
    }
    n[reg]++;
    bt=(ADCshift_[reg]>>length)&0x01;
    ADCshift_[reg]=(ADCshift_[reg]<<1)+bt;
    break;

  case 7: // timed version of SR bitsin - reversed
    //if (length>11) length=11;
    if (n[reg]>length) {
      if (length>11){
	ADCshift_[reg]=(adc_buffer[12]<<(length-11));
      }
      else ADCshift_[reg]=(adc_buffer[12]);
      //    ADCshift_[reg]=(adc_buffer[12]);
    n[reg]=0;
    }
    n[reg]++;
    bt=(ADCshift_[reg]&(1<<length));
    // clear bit
    ADCshift_[reg]&=~(1<<length);	
    ADCshift_[reg]=(ADCshift_[reg]>>1)+bt;
    break;

  case 8: // padded version of SR of bitsin
      if (n[reg]>length) {
	if (length<12) ADCshift_[reg]=(adc_buffer[12])>>(11-length); 
	else ADCshift_[reg]=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    n[reg]++;
    bt=(ADCshift_[reg]>>length)&0x01;
    ADCshift_[reg]=(ADCshift_[reg]<<1)+bt;
    break;
    ///
    
  case 9: //  now strobe - was! ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    // testing now for msb out 
    if (strobe) { 
      if (length>11) length=11;
      //      if (n[reg]>length) {
            if (n[reg]<0) {
	      k=(adc_buffer[12])>>(11-length); //
	      n[reg]=length;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;
      }
    else
      {
	bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
      }
    break;

  case 10: // basic sequential length of bits cycling in but zeroed by strobe
    if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    } 
     if (strobe) bt=0;
      else bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 11: // padded case 8    // we accumulate bits onto a ghosted register **
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt - but how can we fix that
    //      if (n[reg]>length) {
          if (n[reg]<0) {
	if (length<12) k=(adc_buffer[12])>>(11-length); 
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { 
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    //bt=0; // leave orf
    break;
    
  case 12:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa **
    if (strobe) toggle^=1;
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length);
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;
      if (toggle) {
    n[reg]++;    
      }
    break;

  case 13:     // we accumulate bits onto a ghosted register
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { // strobe
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    bt=0;
    break;

  case 14:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa
    if (strobe) toggle^=1;

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      if (toggle) {// strobe
      bt = (k>>n[reg])&0x01;
      lastbt=bt;
      }
      else bt=lastbt;
    n[reg]++;    
    break;
    
  case 15:     // 2-we only cycle ADC on strobe/toggle  - or vice versa
        if (strobe) toggle^=1;
    if (length>11) length=11; //XXXmax12bits

  if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;

      if (toggle) {// strobe
    n[reg]++;    
      }
      break;

  case 16: // STROBE: 3-one bit entry
    if (strobe) toggle^=1;
    n[reg]++;
  if (n[reg]>50) {
    k=(adc_buffer[12]);
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   

   if (toggle) {
	lastbt=bt;
      }
      else bt=lastbt;
   break;

  case 17: // timed version from otherpar
    //    if (length>11) length=11;
    //    otherpar+=32;
    otherpar+=3;
    if (n[reg]>otherpar) {
      //      ADCshift_[reg]=(adc_buffer[12])>>(31-length);
      if (length<12) {
	ADCshift_[reg]=(adc_buffer[12])>>(11-length); 
      }
      else ADCshift_[reg]=(adc_buffer[12])<<(length-11);

      n[reg]=0;
    }
    n[reg]++;
    bt=(ADCshift_[reg]>>length)&0x01;
    ADCshift_[reg]=(ADCshift_[reg]<<1)+bt;
    break;

    
  case 18: // len is otherpar but there is shift from otherpar  - OTHERPAR! 12 bits
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
        otherpar=otherpar&31; // 5 bits
      if (n[reg]>otherpar) {
	if (otherpar<12) k=(adc_buffer[12])>>(11-otherpar); 
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

    // we use otherpar to determine number of bits - equal or otherwise  - OTHERPAR! 12 bits
     // we can also use otherpar=CV or otherwise as padding, length of bits which is not LEN!
  case 19:   // as case 17: // basic sequential length as in 0 but with padding if >11 bist
    // maybe restrict otherpar
    // try with MSB or loads 0s after shift
    // doesn't work if length shorter than otherpar
    otherpar=otherpar&31; // 5 bits
    if (length<otherpar) length=otherpar;
      if (n[reg]<0) {
	if (otherpar<12) {
	  k=(adc_buffer[12])>>(11-otherpar); //
	}
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=length;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;    
    break;

  case 20: // otherpar as comparator - 10 bits standard here // now 12 bits  - OTHERPAR! 12 bits
     bt=0;
     if ((adc_buffer[12])>(otherpar&4095)) bt=1;
     break;

  case 21: // XOR or OR of case 4 - 1 bit oscillator and input bits  - OTHERPAR! 12 bits
  if (length>11) length=11;
      if (nnn[reg]>length) {
	k=(adc_buffer[12])>>(11-length); 
      nnn[reg]=0;
    }
    bt = (k>>nnn[reg])&0x01;
    nnn[reg]++;    

    otherpar=otherpar>>2; // how long? it should be?
     if (n[reg]>length) { // 0s
       bt|=0; // XOR TODO
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt|=1; // XOR TODO
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

     // 22->31 = no ADC IN just LFSR/DAC etc
     
  case 22: // LFSR runs on own SR so not true LFSR - REGG!
    bt = ((*SR >> (lfsr_taps[SRlength[regg]][0])) ^ (*SR >> (lfsr_taps[SRlength[regg]][1])) ^ (*SR >> (lfsr_taps[SRlength[regg]][2])) ^ (*SR >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    break;

  case 23:// run true LFSR-ADCshift and output a bit  - REGG!
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
    
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

  case 24: // incoming bit switches direction of LFSR - REGG! 
    //      case 7:// run LFSR-ADCshift and output a bit - again if we don't use redirection of regg then ...
    if (strobe) toggle^=1;
    if (toggle){
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]<<1)+bt;
    }
    else {
    bt = ((ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][0])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][1])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][2])) ^ (ADCshift_[regg] >> (lfsr_taps[SRlength[regg]][3]))) & 1u;
    ADCshift_[regg]=(ADCshift_[regg]>>1)+(bt<<31);
    }
    if (ADCshift_[regg]==0) ADCshift_[regg]=0xff;
    break;

  case 25: // gate[regg].dac seq input  - REGG!
    if (length>11) length=11; 
      if (n[reg]>length) {
	k=(gate[regg].dac)>>(11-length);
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
        
  case 26: // one bit audio input from DAC  - REGG!
    //    n[reg]++;
    //  if (n[reg]>50) {
    k=gate[regg].dac;
    //    n[reg]=0;
    //  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;

  case 27: // case 5 - gate[regg].dac seq input     // padded length version ** - REGG!
    if (n[reg]>length) {
      if (length<12) k=(gate[regg].dac)>>(11-length); 
      else k=(gate[regg].dac)<<(length-11 );
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
    
  case 28: // clkbit as bits in
    bt=strobe;
    break;

  case 29:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=0;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=1;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 30: // 3/12/2021 - 101010 clock at speed - ultrasonic at fastest speeds
    lastbt^=1;
    bt=lastbt;
    break;

  case 31: // strobe mode for cycling bits a la TM - no input
    bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    if (strobe){
      bt=!bt;// invert cycling bit
    }
    break;

  case 32: // In progress  test mode for spaced sequential entry of 12 bits
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); // fill so no spacings
	else {
	  // try for reverse
	  k=(adc_buffer[12]); // below for LSB first so reverse for MSB
	  k=(k&0x01) + ((k&space[length-11][0])<<spaceshift[0][length-11]) + ((k&space[1][length-11])<<spaceshift[1][length-11]) + \
	    ((k&space[2][length-11])<<spaceshift[2][length-11]) + ((k&space[3][length-11])<<spaceshift[3][length-11]) + \
	    ((k&space[4][length-11])<<spaceshift[4][length-11]) + ((k&space[5][length-11])<<spaceshift[5][length-11]) + \
	    ((k&space[6][length-11])<<spaceshift[6][length-11]) + ((k&space[7][length-11])<<spaceshift[7][length-11]) + \
	    ((k&space[8][length-11])<<spaceshift[8][length-11]) + ((k&space[9][length-11])<<spaceshift[9][length-11]) + \
	    ((k&space[10][length-11])<<spaceshift[10][length-11]) + ((k&space[11][length-11])<<spaceshift[11][length-11]);
	}
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 33: //  was 9 back to ADC - was! ADC prob mode using otherpar - 10 bits in this case  - OTHERPAR! 12 bits - else is returning bit
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...    
    // testing now for msb out
    if (((LFSR_[reg] & 4095 ) < otherpar)){
      if (length>11) length=11;
      //      if (n[reg]>length) {
            if (n[reg]<0) {
	      k=(adc_buffer[12])>>(11-length); //
	      n[reg]=length;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]--;
      }
    else
      {
	bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
      }
    break;

  case 34:// swapped // 1 bit oscillator - train of length 1 bits followed by y 0 bits  - OTHERPAR! 12 bits
    // otherpar can also be CV for INTmodes - was 4
    // can also be other way round
    otherpar=otherpar>>2; // how long? it should be? 10 or 8 bits?
     if (n[reg]>length) {
       bt=1;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=0;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

// prob instead of strobe: 12,13,14,15,16 -> re-work NOW/here in ADC_
//     if (((LFSR_[reg] & 4095 ) < otherpar)){
     
  case 35:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa **
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length);
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;
     if (((LFSR_[reg] & 4095 ) < otherpar)){
    n[reg]++;    
      }
    break;

  case 36:     // we accumulate bits onto a ghosted register
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

     if (((LFSR_[reg] & 4095 ) < otherpar)){
      *SR&=invmasky[length]; // clear length bits
      *SR+=(ADCGshift_[reg]&masky[length]);
    }
    bt=0;
    break;

  case 37:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
     if (((LFSR_[reg] & 4095 ) < otherpar)){
      bt = (k>>n[reg])&0x01;
      lastbt=bt;
      }
      else bt=lastbt;
    n[reg]++;    
    break;
    
  case 38:     // 2-we only cycle ADC on strobe/toggle  - or vice versa

    if (length>11) length=11; //XXXmax12bits

  if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;

     if (((LFSR_[reg] & 4095 ) < otherpar)){
    n[reg]++;    
      }
      break;

  case 39: // STROBE: 3-one bit entry
    n[reg]++;
  if (n[reg]>50) {
    k=(adc_buffer[12]);
    n[reg]=0;
  }
  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   

   if (((LFSR_[reg] & 4095 ) < otherpar)){
	lastbt=bt;
      }
      else bt=lastbt;
   break;

    /////////////////////// add modes
   
  case 63: // =- input regardless of length
    // also try as MSB - now...
    if (n[reg]<0) { // 12 bits = can also be 8 bits or less
	k=(adc_buffer[12]);
	n[reg]=11;
    }
    bt = (k>>n[reg])&0x01; // top bit first
    n[reg]--;    
    break;

  case 64: // was strobe mode for cycling bits a la TM - no input but now uses ADC input as probability! - cvmode
    bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
    if (((LFSR_[reg] & 4095 ) < adc_buffer[12])){
      bt=!bt;// invert cycling bit
    }
    break;
    
  case 65: // was strobe mode for cycling bits a la TM - no input but now uses otherpar as probability! - can be intmode and cvmode
    bt=(*SR>>length)& 0x01; //cycling bit but what if we are already cycling then just inverts it
     if (((LFSR_[reg] & 4095 ) < otherpar)){
      bt=!bt;// invert cycling bit
    }
    break;

  case 66: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(adc_buffer[12]%otherpar)>>(11-length);
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 67: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	tmp=adc_buffer[12]+otherpar;
	if (tmp>4095) tmp=0;
	k=(tmp)>>(11-length); // now we have 12 bits
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;

  case 68: // basic sequential length of upto 12 bits cycling in MSB first -> ADC intmode various mixes of ADC incoming plus/modulo/etc/XOR CV[0]* intmodes
      if (length>11) length=11;
      if (n[reg]<0) {
	k=(adc_buffer[12]&otherpar)>>(11-length);
	n[reg]=length;
    }
      bt = (k>>n[reg])&0x01; // this means that MSB comes out first
    n[reg]--;    
    break;
    
    
    
   
    ///////////////////////
  } // switch
  return bt;
}

static inline uint16_t leaks(uint16_t x, uint16_t y, uint16_t prob, uint16_t who){ // try lazy, stickyt, leaky, decaying logic here... // who is new 20/9 for which SR we take logic from...
  //  static uint16_t timer=0;
  //  uint16_t z;
  // p as probability or time
  // keep track of how many times this is called (for each register/bit position) and flipit

  // or we can track bits recording their position for a certain lifespan
  // one bit per SR is tracked and lost... so would be leakNSR for example for that bit
  
  // but that is too deterministic... but if we share timers or if timer is across different speeds
  //  prob=1;
  // leaky XOR to test
  if (prob>31) prob=31;
  
  if (x^y==0) return 0;
  //  shift_registerR=(shift_registerR<<1)+z; // we are shifting left << so bit 31 is out last one
  if ((gate[who].shift_&masky[prob])==0) return 1;
  //  else if (rand()%prob==0) return 1;
  return 0;
  
  /*  timer++;
  if (timer>p){
    timer=0;
    d^=1;
    }*/
}

static inline uint16_t otherleaks(uint16_t x, uint16_t y, uint16_t prob, uint16_t who){
  if (prob>31) prob=31;
  
  if (x^y==0) return 0;
  if ((LFSR_[who]&masky[prob])==0) return 1;
  return 0;
}



//bitr=logop(bitr,bitrr,logopp[w]); // or other op TODO
// logop: 0-XOR, 1-OR, 2-&, 3leaks - 0,1,2,3
// this one can return just bitn 
static inline uint16_t logopx(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  // 
   if (type==3)  return (bita ^ bitaa);
   //  else if (type==1) return (bita | bitaa);
   else if (type==1) return (otherleaks(bita, bitaa,3,3));
  else if (type==0) return bita;
  else if (type==2) {return (bita ^ !bitaa);
    //    ty=otherleaks(bita, bitaa,3,3); // how to change this?
    //    return ty; // leaks using RSR as random // where we get 8 from...
  }
  return bita ^ bitaa; // default
}

//bitr=logop(bitr,bitrr,logopp[w]); // or other op TODO
// logop: 0-XOR, 1-OR, 2-&, 3leaks - 0,1,2,3
static inline uint16_t logop(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  if (type==0)  return (bita ^ bitaa);
  else if (type==1) return (bita);
  else if (type==2) return (bita ^ (!bitaa)); // same as inverted XOR
  else if (type==3) {
    ty=leaks(bita, bitaa,3,3);
    return ty; // leaks using RSR as random 
  }
  return bita ^ bitaa; // default
}

//0-15 so 16 modes
static inline uint32_t DAC_(uint32_t shift, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t strobe){  // DAC is 12 bits
  uint32_t x=0;
  static uint32_t n[4]={0,0,0,0};
  static uint32_t nom[4]={0,0,0,0};
  static float SmoothData[4]={0.0, 0.0, 0.0, 0.0};
  static uint32_t lastout=0;
  static uint8_t toggle=0;
  float betaf=0.4f;
  int32_t rem, reg;
  uint32_t y;
  
  switch(type){

  case 666: // null case for testings
    x=0;
    break;
    
  case 66: // default for all other DACs - modded for new draft
    x=( (shift & masky[length])>>(rightshift[length]))<<leftshift[length];
    //    x=shift_[reg]&4095;
    break;
        
  case 0: // length doesn't change much except at slow speeds - ADC x bits out - modded for new draft
    if (length==3){
      if ((shift&4)==4) x=4095; // changed 28/12
      else x=0;
    }
    //    else     x=( (shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; // doublecheck
    else  x=( (shift & masky[length])>>(rightshift[length]))<<leftshift[length];
    //    else x=(shift_[reg]&masky[length])&4095;

    break;


    /*
  case 0: // ADc x bits out but only 12/8/4/2/1 bits
    if (length<8){ // 1 bit
      if ((shift_[reg]&(1<<length))==(1<<length)) x=4095;
      else x=0;
    }
    else x=(shift_[reg]&masky[length])>>newr[length])<<news[length];
    break;
    */
    /*
  case 0: // testing 12 bits out
    if (n[reg]>length) { // slow...
      n[reg]=0;
      //      nom[reg]=shift_[reg]&4095;
      nom[reg]=((shift_[reg]&masky[length])>>newr[length])<<news[length];
    }
    n[reg]++;
    x=nom[reg];
    break;
    */
    
  case 33:// standard bit DAC for x bits - new mode here

    if (n[reg]>length) {
      n[reg]=0;
    if (length==3){
      if ((shift &4)==4) x=4095;
      else nom[reg]=0;
    }
    else nom[reg]=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; // we want 12 bits but is not really audible difference //Q of least bits
    }
    n[reg]++;
    x=nom[reg];

    //    x=rand()%4095;
     /*
    if (length==3){
      if (shift_[reg]&4) x=4095;
      else x=0;
    }
    else     x=( (shift_[reg] & masky[length])>>(rightshift[length]))<<leftshift[length];
    */
    break;

  case 1:// equivalent bit DAC for x bits - 3/11 - 32 bits max now
    x=countbits(shift &masky[length]); // lower length bits only
    y=divy[length]; // added table for this 7/10 - updated for 32 bits
    x*=y;
    if (x>4095) x=4095;
    break;

  case 2: // one bit audio but with beta as param
    // beta is now (6/12/2021) always param - just if is generated from cv or speed or ... betaf=0.4f is usual value
    // 0.4=par/4096.0
    if (otherpar==0) otherpar=1;
    if (otherpar>4096) otherpar=4096;
    betaf=(float)(otherpar)/4096.0f; // between 0 and 1?
    y=(shift >>length)&1;
    if (y==1) x=4095;
    else x=0;
    SmoothData[reg] = SmoothData[reg] - (betaf * (SmoothData[reg] - x));
    x=(int)SmoothData[reg];
    break;

  case 3: //spacers 
    x = (shift&0xFF)<<4; // just the lower 8 bits - no spacings
    if (length>7){ // real length >8
      x = ((shift & 0x01) + ((shift>>pos[length][1])&0x02) + ((shift>>pos[length][2])&0x04) + ((shift>>pos[length][3])&0x08) + ((shift>>pos[length][4])&0x10) + ((shift>>pos[length][5])&0x20) + ((shift>>pos[length][6])&0x40) + ((shift>>pos[length][7])&0x80))<<4;
      //       {0, 0, 1, 3, 6, 10, 15, 21} // for 32 bits = length=31 - check sense of this
    }
    break;

  case 4: // only output standard DAC on param->strobe/clock! so just maintain lastout
    if (strobe) {
      x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
      lastout=x;
    }
    else x=lastout;
    break;

  case 5: // toggle to hold/release DAC
    if (strobe) toggle^=1;
    if (toggle) {
      x=lastout;
    }
    else {
      x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
      lastout=x;
    }      
    break;

  case 6: // 4 spaced bits out! equiv bits or not - in this case not
    x= ( ( (shift& (1<<lastspac[length][0]))>>lastspacbac[length][0]) + ((shift& (1<<lastspac[length][1]))>>lastspacbac[length][1]) + ((shift& (1<<lastspac[length][2]))>>lastspacbac[length][2]) + ((shift& (1<<lastspac[length][3]))>>lastspacbac[length][3]) )<<8; // 4 bits to 12 bits
    break;

  case 7: // 4 spaced bits out! equiv bits
    x= ( ((shift& (1<<lastspac[length][0]))>>lastspacbac[length][0]) + ((shift& (1<<lastspac[length][1]))>>lastspacbac[length][1]) + ((shift& (1<<lastspac[length][2]))>>lastspacbac[length][2]) + ((shift& (1<<lastspac[length][3]))>>lastspacbac[length][3]) ); 
    x=countbts[x]*1023;
    if (x>4095) x=4095;
    break;

  case 8: // one SR is sieved out over another? as DAC option. XOR as sieve? AND as mask! TODO
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; 
    x=x^(((gate[sieve[reg]].shift_ & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]); // seived through previous SR
    break;

  case 9: //  one SR is sieved out over clksr for that sr. XOR as sieve?  - SKIPPED/retry instead of 11
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; 
    x=x^((clksr_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; 
    break;

  case 10:// standard bit DAC for x bits     ///bitx length as other param rather than length:
    // but then we don't really use len? unless is cycle back
    // try now 21/12/2021 using length
    // bit length can also be CV - how to put this in as DAC is quite fixed in macro?
    otherpar=otherpar&31; //5 bits
    rem=length-otherpar;
    if (rem<0) rem=0;
    x=((shift & masky[rem])>>(rightshift[rem]))<<leftshift[rem]; 
      break;

      // sequential DACs
  case 11: // we wait for length bits then output that many bits from the top of the SR (len bit) - not really working
    if (n[reg]>length) {
      n[reg]=0;      
      x=((shift & masky[length])>>(rightshift[length]))<<leftshift[length];
      lastout=x;
    }
    x=lastout;
    n[reg]++;              
    break;

  case 12: // we wait for otherparam bits then output that many bits from the top of the SR (len bit)
    otherpar=otherpar&31; //5 bits
    if (n[reg]>otherpar) {
      n[reg]=0;
      x=((shift & masky[length])>>(rightshift[length]))<<leftshift[length];
      lastout=x;
    }
    x=lastout;
    n[reg]++;              
    break;

  case 13:// par is mask on standard bit DAC for x bits
    //    if (reg<4 && length>3 && length<32) 
    // why (length-3)? to get down to 1 bit so could also have option for full bits!
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
    x|=(otherpar&4095);
      break;

  case 14:/// we record mask and use this to mask the regular DAC... - could also be other-than-standard DACs
    if (strobe) // we record the mask 
	{
	  mask[reg]=(otherpar&4095); // or reg can be otherpar/SR
	  }
    x=((shift & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
    x|=mask[reg];
    break;

    // case 15 was as case 2 but with param for filter - and now always has param
    
    ///////
  } // switch    
  return x;
}



///////////////////////////////////////////////////////////////////////// 

#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 1000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void EXTI4_IRQHandler(void){ // working NSR 
  uint32_t tmp, tmpp;
if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
  intflag[0]=1; //NSR
  param[0]=counter_[0];
  counter_[0]=0;
  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
  uint32_t tmp, tmpp;
  uint16_t j, bit, xx, x;
  uint32_t lengthbitl=15, new_statl, new_statr,new_statc, lengthbitc=15, lengthbitr=15; // for 2nd bit on lsr, rsr and csr
    
  if (EXTI_GetITStatus(EXTI_Line5) != RESET) { //RSR  
    intflag[3]=1; //RSR
    param[3]=counter_[3];
      counter_[3]=0;
    EXTI_ClearITPendingBit(EXTI_Line5);
 }

  if (EXTI_GetITStatus(EXTI_Line6) != RESET) { //LSR
    intflag[1]=1; //LSR
    param[1]=counter_[1];
    counter_[1]=0;
    EXTI_ClearITPendingBit(EXTI_Line6);
 } 

  if (EXTI_GetITStatus(EXTI_Line7) != RESET) {// CSR
    intflag[2]=1; //CSR
    param[2]=counter_[2];
    counter_[2]=0;
    EXTI_ClearITPendingBit(EXTI_Line7);
 } 
}

void TIM4_IRQHandler(void) 

{
  uint32_t temp;
  volatile static uint16_t tmp;

  TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 

  /*  
      tmp^=1;
      if (tmp) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
      else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */

  // map ADCs:

    // 0: nspd, 1: nlen, 2: nmode
    // 3: lspd, 4: llen, 5: lmode
    // 6: rspd, 7: rlen, 8: rmode // adc6 fixed hw
    // 9: cspd, 10: clen, 11: cmode

  // modes are NOT inverted!
  
  //moden
  temp=(adc_buffer[2]+lastlastmoden+lastmoden)/3; 
  lastlastmoden=lastmoden;
  lastmoden=temp;
  mode[0]=(temp>>6); // 64 modes = 6 bits  

  // modec
  temp=(adc_buffer[11]+lastlastmodec+lastmodec)/3; 
  lastlastmodec=lastmodec;
  lastmodec=temp;
  mode[2]=(temp>>6); // 64 modes = 6 bits  

  // model
  temp=(adc_buffer[5]+lastlastmodel+lastmodel)/3; 
  lastlastmodel=lastmodel;
  lastmodel=temp;
  mode[1]=(temp>>6); // 64 modes = 6 bits  

  // moder
  temp=(adc_buffer[8]+lastlastmoder+lastmoder)/3; 
  lastlastmoder=lastmoder;
  lastmoder=temp;
  mode[3]=(temp>>6); // 64 modes = 6 bits  
  
  // speedn
  totn=totn-smoothn[nn];
  smoothn[nn]=adc_buffer[0];
  totn+=smoothn[nn];
  nn++;
  if (nn>=SMOOTHINGS) nn=0;
  temp=totn/SMOOTHINGS;  
  CV[0]=temp;
  speedf_[0]=logspeed[temp>>2];
  
  // speedl
  totl=totl-smoothl[ll];
  smoothl[ll]=adc_buffer[3];
  totl+=smoothl[ll];
  ll++;
  if (ll>=SMOOTHINGS) ll=0;
  temp=totl/SMOOTHINGS;  
  CV[1]=temp;
  speedf_[1]=logspeed[temp>>2];
  
  // speedr
  totr=totr-smoothr[rr];
  smoothr[rr]=adc_buffer[6];
  totr+=smoothr[rr];
  rr++;
  if (rr>=SMOOTHINGS) rr=0;
  temp=totr/SMOOTHINGS;  
  CV[3]=temp;
  speedf_[3]=logspeed[temp>>2];
  
    // speedc
  totc=totc-smoothc[cc];
  smoothc[cc]=adc_buffer[9];
  totc+=smoothc[cc];
  cc++;
  if (cc>=SMOOTHINGS) cc=0;
  temp=totc/SMOOTHINGS;  
  CV[2]=temp;
  speedf_[2]=logspeed[temp>>2];
  
  // lens from 4 to 32 - 8/11/2021 we reversed the list to save some time!

  temp=(adc_buffer[1]>>7); // 12 bits to 5 bits 
  SRlength[0]=lookuplenall[temp];
  //  SRlength[0]=11; // TESTY

  temp=(adc_buffer[4]>>7); // 12 bits to 5 bits 
  SRlength[1]=lookuplenall[temp];

  temp=(adc_buffer[7]>>7); // 12 bits to 5 bits 
  SRlength[3]=lookuplenall[temp];

  temp=(adc_buffer[10]>>7); // 12 bits to 5 bits 
  SRlength[2]=lookuplenall[temp];
}
