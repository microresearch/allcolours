// draftdec/theone/extramodes

//DONE
// Gshift_[x][w] becomes gate[x].Gshift_[w]
// shift_[w] becomes gate[w].shift_


// from draftdec

//3
BINROUTE_;
prob=gate[w].shift_&31; // this seems to work somehow 8/12/2021
PULSIN_LEAK; // try xor vs leak vs or... - uses prob as param

//4
      BINROUTEANDCYCLE_;
      prob=gate[w].shift_&31; // this seems to work somehow 8/12/2021
      PULSIN_LEAK; // try xor vs leak vs or... - uses prob as param

//5
//00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) 
	BINROUTE_;
	if (gate[w].trigger)	  bitrr=(gate[w].shift_>>SRlength[w]) & 0x01;
	else bitrr=!((gate[w].shift_>>SRlength[w]) & 0x01); 
	bitn|=bitrr;
	PULSIN_XOR;

/// here
//6
	if (gate[w].trigger){
	  BINROUTE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}
	PULSIN_XOR;

//7
	if (gate[w].trigger){
	  BINROUTE_;
	}
	else {
	  bitn=!(gate[w].shift_>>SRlength[w]) & 0x01; 
	}	
	PULSIN_XOR;
    

//8
	if (gate[w].trigger) tug[w]^=1;
	if (tug[w]){
	  BINROUTEANDCYCLE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}	
	PULSIN_XOR;

//10
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  if (gate[w].trigger) gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }
	PULSIN_XOR;

//11
	tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  if (gate[w].trigger){
	    tmpp=gate[x].Gshift_[w];
	    REV32; // reverse 32 bits
	    tmpp=tmpp&othermasky[SRlength[x]]; // mask the top length bits
	    gate[x].Gshift_[w]=tmpp>>(31-SRlength[x]); // and shift 31-length bits
	  }
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; // 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }
	PULSIN_XOR;

//12
      // XX - we XOR on STROBE our shift with the GHOST
  tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
    if (gate[w].trigger) gate[x].Gshift_[w]^=gate[w].shift_;
    bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01;
    if (gate[w].trigger) 
      gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
	PULSIN_XOR;

//13
//00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ?? -- 9 below
	BINROUTE_;
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[count][w]].dac)){
	  bitrr=(gate[w].shift_>>SRlength[w]) & 0x01;
	}
	else bitrr=!((gate[w].shift_>>SRlength[w]) & 0x01); 
	bitn|=bitrr;
    PULSIN_XOR;

//14
//	01 2-BITIN or loopback
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[count][w]].dac)){
	  BINROUTE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}		//
	PULSIN_XOR;

//15
	if (((LFSR_[w] & 4095 ) < gate[dacfrom[count][w]].dac)){
	  BINROUTEANDCYCLE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}	
    PULSIN_XOR;
////here
//17 for modeC
// 1st trigger=prob 00 TM
	BINROUTE_;
	if (gate[w].trigger)	  bitrr=(gate[w].shift_>>SRlength[w]) & 0x01;
	else bitrr=!((gate[w].shift_>>SRlength[w]) & 0x01); 
	bitn|=bitrr;

//18 for mode C
//2nd trigger=prob 11 ENOTES 
if (gate[w].trigger) tug[w]^=1;
	if (tug[w]){
	  BINROUTEANDCYCLE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}	
///here
// 4x4 DAC modes
  /*
1-cycle and route 16 below
2-2x strobe=prob from below
3
4-4 bit shuffle
  
00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ??
01 2-BITIN or loopback
   [10 3-INV of above]
11 4- BITIN or not into cycling
  */

// from theone: copy in and transform

  case 10: // probability mode 0: TM cycling bit
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycling bit or not, pulsbit is ORed in (TM)

    if (gate[w].trigger==1){
      dactype[2]=0;

      GSHIFT;
      
      bitn=(gate[w].shift_>>SRlength[w])& 0x01;
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 11: // probability mode 1: TM routein bit
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert routed-in-bit or not, pulsbit is ORed in (TM)

    if (gate[w].trigger==1){ 
      dactype[2]=0; 

      GSHIFT;

      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
            
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) {
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 12: // probability mode 2: TM routein/and cycle
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycle+routed-in-bit or not, pulsbit is ORed in (TM)

    if (gate[w].trigger==1){ 
      dactype[2]=0;

      GSHIFT;
        
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 13: // probability mode 3: Wiard/EN new input from pulsebit
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //3. new input (from pulsbit) or cycling bit (wiard and EN)  - if we don't have pulsebit then route
    
    if (gate[w].trigger==1){
      dactype[2]=0;

      GSHIFT;
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
      bitn=(gate[w].shift_>>SRlength[w])& 0x01; 
      }
      else
	{
	  if (pulsins[w]!=0) bitn=!(GPIOC->IDR & pulsins[w]); //LR have pulsins
	  else { // if we don't use pulseins
	    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
	  }	  	  
	}      
      BITN_AND_OUT;
    }
    break; 

  case 14: // probability mode 4: wiard/en
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //4. new input (from route) or cycling bit - and OR in pulsebit if...    
    if (gate[w].trigger==1){ 
      dactype[2]=0; 

      GSHIFT;
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
      bitn=(gate[w].shift_>>SRlength[w])& 0x01; 
      }
      else{
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 15: // probability mode 5 for ADC - TODO:match with other LRC modes!
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //4. new input (from route/ADC) or cycling bit - and OR in pulsebit if...
    /// or in case of w==0 NSR we have ADC/LFSR in depending on type - but THIS is not extra to mode 14 as it will simply repeat those except for NSR
    // but now we change this so is inverted routing bit
    if (gate[w].trigger==1){ 
      dactype[2]=0; // basic DAC out

      GSHIFT;      
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) {
      bitn=(gate[w].shift_>>SRlength[w])& 0x01; //cycling bit XOR in     
      }
      else{
	if (w==0){
	  bitn=ADC_(w,SRlength[w],0,0,0,0);
	}
	else
	  {
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
	bitn^=1;
	  }
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 16: // probability mode 6
    //1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //6. new input (from ADCtypeX) or route in     
    // how these match/repeat above when we don't have ADC ??? - maybe do inverted route bit in for others // with cycling bit
    
    if (gate[w].trigger==1){
      dactype[2]=0; 

      GSHIFT;      
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) {
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
      }
      else{
	if (w==0){
	  bitn=ADC_(w,SRlength[w],0,0,0,0); 
	}
	else
	  {
	    bitn=(!(gate[w].shift_>>SRlength[w])) & 0x01; 
 	  }
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 
    
  case 17: // probability mode: 7
    // if SR<DAC+CV // int mode from 10-16 repeat with sr<adc+dac[2]
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycling bit or not, pulsbit is ORed in (TM)

    if (gate[w].trigger==1){
      dactype[2]=0;

      GSHIFT;      

      bitn=(gate[w].shift_>>SRlength[w])& 0x01;
      tmpt=gate[dacfrom[count][w]].dac-(4095-adc_buffer[lookupadc[w]]);
      if (tmpt<0) tmpt=0; // or just add them      
      if ((LFSR_[w] & 4095 )<tmpt) {
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 18: // probability mode
    //    LFSR<DAC
    // first for CV modes and prob - copy of 17 which is copy of 10
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycling bit or not, pulsbit is ORed in (TM)

    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      

    bitn=(gate[w].shift_>>SRlength[w])& 0x01;
    if ((LFSR_[w] & 4095 )<gate[dacfrom[count][w]].dac) {
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 19: // probability mode
    // first for CV modes and prob - copy of 17 which is copy of 10
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycling bit or not, pulsbit is ORed in (TM)

    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      

    bitn=(gate[w].shift_>>SRlength[w])& 0x01;

      if ((LFSR_[w] & 4095 )<param[w]) { 
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 20: //as case 3 but for INT modes and with test ADC 11 mode in! CV as comparator
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - LFSR 
    // L: route from/bits in/logic - pass on/OR
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DACequiv
    // R: route from/bits in/logic  - pass on/OR

    if (gate[w].trigger==1){ 
      dactype[2]=0; 
      logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1;
    
      GSHIFT;
    
      if (w==0){
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
	bitn^=ADC_(w,SRlength[w],11,0,0,0); // XOR with LFSR
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }
    PULSIN_LOGOP;    
    BITN_AND_OUT;          
    }// counterw
  break; 

/// here

  case 21: // triadex inspired mode where we XOR in bits from the other SRs
    // but which bits and do we use static SR or shift ghostSRs round...
    // try ghosted SRs...
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic

    GSHIFT;

    // gate[w].Gshift_[0]
    
    bitn = (gate[others[w][0]].Gshift_[w]>>SRlength[others[w][0]]) & 0x01; 
    gate[others[w][0]].Gshift_[w]=(Gshift_[others[w][0]][w]<<1)+bitn;
    //////
    bitnn = (gate[others[w][1]][w]>>SRlength[others[w][1]]) & 0x01; 
    Gshift_[others[w][1]][w]=(Gshift_[others[w][1]][w]<<1)+bitnn;

    bitnnn = (Gshift_[others[w][2]][w]>>SRlength[others[w][2]]) & 0x01; 
    Gshift_[others[w][2]][w]=(Gshift_[others[w][2]][w]<<1)+bitnnn;

    bitn^=((gate[w].shift_>>SRlength[w])& 0x01)^bitnn^bitnnn; 

    PULSIN_XOR;
    BITN_AND_OUT;
  }// counterw
  break; 

///here

  case 22: // triadex inspired mode where we XOR in bits from the other SRs
    // but which bits and do we use static SR or shift ghostSRs round...
    // this one with static SR!
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      
  
    bitn = (gate[others[w][0]].shift_>>SRlength[others[w][0]]) & 0x01; 
    bitnn = (shift_[others[w][1]]>>SRlength[others[w][1]]) & 0x01; 
    bitnnn = (shift_[others[w][2]]>>SRlength[others[w][2]]) & 0x01; 
    bitn^=((gate[w].shift_>>SRlength[w])& 0x01)^bitnn^bitnnn; 

    PULSIN_XOR;
    BITN_AND_OUT;
    }// counterw
  break; 

  case 23: // pass on but trigger bumps on default route
    // can also be multiple routes in/change to binary routing table
    
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic

    if (gate[w].trigger){
      ourroute[w]++;
      if (ourroute[w]>3) ourroute[w]=0;
    }
    
    GSHIFT;
    bitn = (Gshift_[ourroute[w]][w]>>SRlength[ourroute[w]]) & 0x01; 
    Gshift_[ourroute[w]][w]=(Gshift_[ourroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    BITN_AND_OUT;
  }// counterw
  break; 

  case 24: // can also be multiple routes in/change to binary routing table
    // first implementation of multiple routing table
          if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic

    if (gate[w].trigger){ // bump up binary routing table which is route[]
      route[w]++;
      if (route[w]>15) route[w]=0; // 15 is all routes, 8,4,2,1
    }
    
    GSHIFT;

    // work with the binary routing table
    bitn=0;
    tmp=route[w]; // route can also be another SR!
    // if route to ourself then is cycling bit but we still need to cycle <<1 above!
    for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	bitn^=bitrr;//logop(bitn,bitrr,logopp[w]); // but what if we want different logical opps for each?
    }
    tmp=tmp>>1;
    }
    
    PULSIN_XOR;
    BITN_AND_OUT;
  }// counterw
  break; 

  case 25: // can also be multiple routes in/change to binary routing table
    // implementation of multiple routing table
    // this is an INT mode with CV as the routing table
    // table is 4 bits but we can have DAC selection on extra 2 bits for all SRs
    // how this works with ADC in or we don't route that one - default route in...
    // and use bits to select types there... TRY THIS

    if (gate[w].trigger){ 

      tmpp=adc_buffer[lookupadc[w]]>>4; // this can also be RSR DAC! 12 bits down to 6 bits - 9/11 add 2 bits for logopps

      GSHIFT;      
      bitn=0;
      tmp=tmpp&15; // bottom 4 bits 
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	bitn=logop(bitn,bitrr,(tmpp>>6)&3); // but what if we want different logical opps for each?
	//	bitn|=bitrr;

    }
    tmp=tmp>>1;
    }

    PULSIN_XOR;
    gate[w].shift_+=bitn;  
    gate[w].dac=DAC_(w, SRlength[w], (tmpp>>4)&3,param[w],gate[w].trigger); // all DACTypes changed here - top bits
    PULSOUT;
  }// counterw
  break; 

  case 26: // multiple routes in/change to binary routing table
    // implementation of multiple routing table - CV mode with dacrouted dac as source for table...
    // could also be bits from plain SR TODO
      if (counter[w]>speed[w] && speed[w]!=1024){
	//      tmpp=gate[dacfrom[count][w]].dac>>4; 
	tmpp=shift_[dacroute[w]]&255; // 8 bits - we can also interpret bits as single ones... we just seem to use 6 bits here
      GSHIFT;      
      bitn=0;
      tmp=tmpp&15; // bottom 4 bits 
      for (x=0;x<4;x++){ //unroll?
	if (tmp&0x01){  
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	  //	  bitn^=bitrr;//logop(bitn,bitrr,logopp[w]); // but what if we want different logical opps for each?
	  bitn=logop(bitn,bitrr,(tmpp>>6)&3); // but what if we want different logical opps for each?
	}
	tmp=tmp>>1;
    }

      PULSIN_XOR;
      gate[w].shift_+=bitn;
      gate[w].dac=DAC_(w, SRlength[w], (tmpp>>4)&3,param[w],gate[w].trigger); // all DACTypes changed here - top bits
      PULSOUT;
      }// counterw
      break; 

  case 27:     // w==0 4 bit adc entry on adc_ mode 13
    // we need to cycle in at spac points from routed one...
    
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=6; // others are fixed as basic - but should be 4 bits spaced dac out = 5/6 6 for equiv bits
    
    GSHIFT;      

    if (w==0){ // do our adc 4 bits in mode 13
      ADC_(0,SRlength[0],13,0,0,0); // pulls in bits 
    }
    else
      { // we need to extract the advanced bits from the last one
	// shift_registerl += (((shift_registern&(1<<7))>>7) + ((shift_registern&(1<<15))>>7) + ((shift_registern&(1<<23))>>7) + ((shift_registern&(1<<31))>>7));
	gate[w].shift_&=spacmask[SRlength[w]]; //cleared
	
	if (SRlength[defroute[w]]>=SRlength[w]){ // need to >> 
	  //	  tmp=(SRlength[defroute[w]]>>2)-(SRlength[w]>>2); // /4
	  gate[w].shift_+=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
	  }
	  else // shift up <<
	    {
	      gate[w].shift_+=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			   ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
	    }

	PULSIN_XOR;    
      }
    bitn=gate[w].shift_&1;
    gate[w].shift_+=bitn;				
    gate[w].dac=DAC_(w, SRlength[w], dactype[w],param[w],gate[w].trigger); 
    PULSOUT;
    }
  break; 

  case 28:     // w==0 4 bit adc entry on adc_ mode 13 - pass on 4 bits - this one with feedback into ADC/NSR 0
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=6; // others are fixed as basic - but should be 4 bits spaced dac out = 5/6 6 for equiv bits

    GSHIFT;      

    if (w==0){ // do our adc 4 bits in mode 13
      ADC_(0,SRlength[0],13,0,0,0); // pulls in bits 
      // we want to xor bits back in;;
	if (SRlength[defroute[w]]>=SRlength[w]){ // need to >> 
	  //	  tmp=(SRlength[defroute[w]]>>2)-(SRlength[w]>>2); // /4
	  gate[w].shift_^=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
	  }
	  else // shift up <<
	    {
	      gate[w].shift_^=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			   ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
	    }

    }
    else
      { // we need to extract the advanced bits from the last one
	// shift_registerl += (((shift_registern&(1<<7))>>7) + ((shift_registern&(1<<15))>>7) + ((shift_registern&(1<<23))>>7) + ((shift_registern&(1<<31))>>7));
	gate[w].shift_&=spacmask[SRlength[w]]; //cleared
	
	if (SRlength[defroute[w]]>=SRlength[w]){ // need to >> 
	  //	  tmp=(SRlength[defroute[w]]>>2)-(SRlength[w]>>2); // /4
	  gate[w].shift_+=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
	  }
	  else // shift up <<
	    {
	      gate[w].shift_+=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			   ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
	    }

      }
    PULSIN_XOR;
    
    bitn=shift_[0]&1;
    gate[w].shift_+=bitn;			        
    gate[w].dac=DAC_(w, SRlength[w], dactype[w],param[w],gate[w].trigger); 
    PULSOUT;
    }
  break;
  
  /////////////////////////////////////////////////////////////////////////
  /// new modes testings from 2/11/2021+
  /////////////////////////////////////////////////////////////////////////
/// here

case 29: // copy of 19 trial for ADC in probablity modes - adc_buffer[12] 12 bits
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    
    GSHIFT;
    
    bitn=(gate[w].shift_>>SRlength[w])& 0x01;
    if ((LFSR_[w] & 4095 )<adc_buffer[12]) {
      bitn=bitn^1;
    }
    PULSIN_OR;
    BITN_AND_OUT;
  }
  break; 

  case 30:    //    ownDAC<DAC
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      
    bitn=(gate[w].shift_>>SRlength[w])& 0x01; 
    if ((gate[w].dac)<gate[dacfrom[count][w]].dac) { 
      bitn=bitn^1;
    }
    PULSIN_OR;
    BITN_AND_OUT;
  }
    break; 


  case 33: // strobe case withOUT looping option

    
    GSHIFT;      
    GGGshift_[w]=GGGshift_[w]<<1;
    
bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; // replace with binroute
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
//binroute etc

    GGGshift_[w]+=bitn;

    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(GGGshift_&masky[SRlength[w]]);// to check again
    }

    PULSOUT;
    gate[w].dac=DAC_(w, SRlength[w], dactype[w],param[w],gate[w].trigger);
    
    }// counterw
  break; 

  
  case 34: // strobe case with looping option
    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    GSHIFT;      
    gate[w].shift_=gate[w].shift_<<1;

    tmp=(gate[w].shift_>>SRlength[w])& 0x01;
    gate[w].shift_+=tmp;
    
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    
    gate[w].shift_+=bitn;
   
    if (gate[w].trigger==1) { // strobe
      gate[w].shift_&=invmasky[SRlength[w]]; 
      gate[w].shift_+=(gate[w].shift_&masky[SRlength[w]]);
    }

    PULSOUT;
    gate[w].dac=DAC_(w, SRlength[w], dactype[w],param[w],gate[w].trigger);
    }// counterw
  break; 


  case 35: // TRIADEX 2
    //    - triadex: we could use params from clkins as indicator of which bits from which SR to parity-in
// also use cv fdor this
    // so table would be for 4 bits from 4x maxSRlength=32*4=128 (ignore lengths)
    //    bt = ((shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;

      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      
     // convert to param - just not sure how many bits param will have - depends?
    s[0]=(param[0]>>5)&3; // select which one... 0,1,2,3
    ss[0]=param[0]%32; // 32 bits
    s[1]=(param[1]>>5)&3; // select which one... 0,1,2,3
    ss[1]=param[1]%32; // 32 bits
    s[2]=(param[2]>>5)&3; // select which one... 0,1,2,3
    ss[2]=param[2]%32; // 32 bits
    s[3]=(param[3]>>5)&3; // select which one... 0,1,2,3
    ss[3]=param[3]%32; // 32 bits

    bitn = (gate[s[0]].shift_ >> ss[0]) & 0x01;
    bitnn = (gate[s[1]].shift_ >> ss[1]) & 0x01;
    bitnnn = (gate[s[2]].shift_ >> ss[2]) & 0x01; 	
    bitnnnn = (gate[s[3]].shift_ >> ss[3]) & 0x01; 
    
    bitn^=((gate[w].shift_>>SRlength[w])& 0x01)^bitnn^bitnnn^bitnnnn; 

    PULSIN_XOR;
    BITN_AND_OUT;
    }// counterw
  break; 

  case 36: // pulse triggers exchange between ghost and real
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    if (gate[w].trigger==1) { // at start we place it...
      gate[w].shift_=gate[w].Gshift_[w];
    }
    
    GSHIFT;      
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    BITN_AND_OUT;
    }// counterw
  break; 

//HERE!

  case 38: // pass through or cycle is toggled by clkin bit
    // this can also be for ADC - toggle entry of ADC bit or pass through/cycle
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=9; // test the sieve 

    GSHIFT;      

    if (gate[w].trigger) tug[w]^=1; // tuggle
    
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  // route in
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
    if (tug[w]) bitn=(gate[w].shift_>>SRlength[w])& 0x01;  // cycle...

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }// counterw
  break;

  /* // this only works to add dac[3] - so not very useful
  case 39:
    // additive DACs into DAC2 - except 2 itself? is this done here though?
    // = multiple DACs - but how we do this as a single mode (add/sub/wrap other DACS, additive DAC into DAC[2])
    // how could this work as a mode... we do dac[w] here so we don't want to add all...
    // and what if all modes are set to this... mode[w] i am dac out and add all...
    //    if (w==0) dac[2]=0; // ???

    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0;
    
    GSHIFT;      
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    
    gate[w].shift_+=bitn;

    PULSOUT;    
    dac[2]+=DAC_(w, SRlength[w], dactype[w],param[w],gate[w].trigger); // additive DAC - TODO: could also be modulus dacs
    dac[2]=dac[2]&4095;
    
    }// counterw    
    break;
  */
  
  case 40: // swap over SRs on pulse in?!! or swop in only (can swop in previous SR or another?) 
    // do regular pass through and then swop with previous on trigger
//    par=g; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      dactype[2]=13; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;
    
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

      if (gate[w].trigger) gate[w].shift_=shift_[oppose[w]]; // sieve is previous one but could be opposite one
      
      PULSIN_XOR;
      BITN_AND_OUT;
    }// counterw
    break; 

  case 41: //  TM in TM: from it.c seems to use 2x comparators - one - INTMODE
	   //  for inv of cycling bit, one for inv of incoming bit (so
	   //  could be CV and DAC comped to LFSR/DAC)
    if (gate[w].trigger==1){
      dactype[2]=0;

      GSHIFT;
      
      bitn=(gate[w].shift_>>SRlength[w])& 0x01; 
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { // cycling bit
	bitn^=1;
      }

      bitnn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitnn;  
      
      if ((LFSR_[w] & 4095 )<gate[dacfrom[count][w]].dac) {
	bitnn^=1;
      }
      bitn|=bitnn;
      
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 42: // - reverse direction of shift register - could be done on a toggle: >> and << and blank/fill in bitn/complicated
    // simple feed through/pass on based on case 0 - we reverse GSR
    // OPTIONS: devroute or revroute and also maybe just reverse incoming GSR and not itself
    
    par=0; 
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      counter[w]=0;
      gate[w].Gshift_[0]=gate[w].shift_;
      gate[w].Gshift_[1]=gate[w].shift_;
      gate[w].Gshift_[2]=gate[w].shift_;
      gate[w].Gshift_[3]=gate[w].shift_;

    if (gate[w].trigger) tug[w]^=1; // tuggle
    if (tug[w]){
      gate[w].shift_=gate[w].shift_<<1;
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
    PULSIN_OR; 
    BITN_AND_OUT;
    }
    else //in reverse - can be defroute or revroute - 2 options but revroute doesn't seem to work so well
      {
	gate[w].shift_=gate[w].shift_>>1;
	bitn = (Gshift_[defroute[w]][w] & 0x01); // just the lowest bit 
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]>>1);
	Gshift_[defroute[w]][w] &= ~(1UL << SRlength[defroute[w]]);
	Gshift_[defroute[w]][w] += (bitn << SRlength[defroute[w]]);
	PULSIN_OR;
	gate[w].shift_ &= ~(1UL << SRlength[w]);
	gate[w].shift_ +=(bitn << SRlength[w]);
	gate[w].dac=DAC_(w, SRlength[w], dactype[w],par,gate[w].trigger);	
      }
    PULSOUT;
    }// counterw
    break; 
    ////
/*
case 43: // reverse of case 1 - cycle round only - not so exciting...
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic
    counter[w]=0;
    gate[w].shift_[0]=gate[w].shift_;
    gate[w].shift_[1]=gate[w].shift_;
    gate[w].shift_[2]=gate[w].shift_;
    gate[w].shift_[3]=gate[w].shift_;

    if (gate[w].trigger) tug[w]^=1; // tuggle
    if (tug[w]){
      gate[w].shift_=gate[w].shift_<<1;
      bitn=(gate[w].shift_>>SRlength[w])& 0x01; //cycling bit
      PULSIN_OR; 
      BITN_AND_OUT;
    }
    else //in reverse 
      {
	bitn=gate[w].shift_&0x01; // lowest bit
	gate[w].shift_=gate[w].shift_>>1;
	PULSIN_OR;
	gate[w].shift_ &= ~(1UL << SRlength[w]);
	gate[w].shift_ +=(bitn << SRlength[w]);
	gate[w].dac=DAC_(w, SRlength[w], dactype[w],par,gate[w].trigger);	
      }
    PULSOUT;
    }// counterw
    break; 
*/
  case 44: // reverse of case 2 - feed in and cycle round
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic
    counter[w]=0;
    gate[w].shift_[0]=gate[w].shift_;
    gate[w].shift_[1]=gate[w].shift_;
    gate[w].shift_[2]=gate[w].shift_;
    gate[w].shift_[3]=gate[w].shift_;

    if (gate[w].trigger) tug[w]^=1; // tuggle
    if (tug[w]){
      gate[w].shift_=gate[w].shift_<<1;
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 
      PULSIN_OR; 
      BITN_AND_OUT;
    }
    else //in reverse 
      {
	bitn = (Gshift_[defroute[w]][w] & 0x01); // just the lowest bit 
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]>>1);
	Gshift_[defroute[w]][w] &= ~(1UL << SRlength[defroute[w]]);
	Gshift_[defroute[w]][w] += (bitn << SRlength[defroute[w]]);

	bitn^=gate[w].shift_&0x01; // lowest bit
	gate[w].shift_=gate[w].shift_>>1;
	
	PULSIN_OR;
	gate[w].shift_ &= ~(1UL << SRlength[w]);
	gate[w].shift_ +=(bitn << SRlength[w]);
	gate[w].dac=DAC_(w, SRlength[w], dactype[w],par,gate[w].trigger);	
      }
    PULSOUT;
    }// counterw
    break; 

  case 45: // - PROBABILITY to reverse direction of shift register - could be done on a toggle: >> and << and blank/fill in bitn/complicated
    // simple feed through/pass on based on case 0 - we reverse GSR
    // OPTIONS: devroute or revroute and also maybe just reverse incoming GSR and not itself
    par=0; 
    if (gate[w].trigger==1){
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      counter[w]=0;
      gate[w].shift_[0]=gate[w].shift_;
      gate[w].shift_[1]=gate[w].shift_;
      gate[w].shift_[2]=gate[w].shift_;
      gate[w].shift_[3]=gate[w].shift_;

      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
      gate[w].shift_=gate[w].shift_<<1;
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
    PULSIN_OR; 
    BITN_AND_OUT;
    }
    else //in reverse - can be defroute or revroute - 2 options but revroute doesn't seem to work so well
      {
	gate[w].shift_=gate[w].shift_>>1;
	bitn = (Gshift_[defroute[w]][w] & 0x01); // just the lowest bit 
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]>>1);
	Gshift_[defroute[w]][w] &= ~(1UL << SRlength[defroute[w]]);
	Gshift_[defroute[w]][w] += (bitn << SRlength[defroute[w]]);
	PULSIN_OR;
	gate[w].shift_ &= ~(1UL << SRlength[w]);
	gate[w].shift_ +=(bitn << SRlength[w]);
	gate[w].dac=DAC_(w, SRlength[w], dactype[w],par,gate[w].trigger);	
      }
    PULSOUT;
    }// counterw
    break; 

/// here!

  case 46: //- cycling array of ghosts toggle in/how to toggle out
//could be keep recording into array and on INT we cycle through (XOR/OR in pass through) until we get to last recorded of max x
//uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0};

    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    GSHIFT;      

      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 
      PULSIN_XOR;    
      BITN_AND_OUT;
      
      Gshift_rev[w][Gshift_revcnt[w]]=gate[w].shift_; // record
      Gshift_revcnt[w]++;
      if (Gshift_revcnt[w]>255) Gshift_revcnt[w]=0;

      if (gate[w].trigger){
      gate[w].shift_=Gshift_rev[w][Gshift_revrevcnt[w]]; 
      Gshift_revrevcnt[w]++;
      if (Gshift_revrevcnt[w]>255) Gshift_revrevcnt[w]=0;
      }      
  }// counterw
  break;

case 47: // GSR runs at CV speed in INT mode (try)
  // or vice versa NOW - GSR is on trigger
  bitn=0;
  if (gate[w].trigger==1){
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
  }

  if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0;
      GSHIFT;      

      bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }
    break;

  case 48: // GSR doesn't change (becomes a revenant) 
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    //    GSHIFT;      
    gate[w].shift_=gate[w].shift_<<1;
  
    bitn = (gate[defroute[w]].gshift_[w]>>SRlength[defroute[w]]) & 0x01; 
    gate[defroute[w]].gshift_[w]=(gate[defroute[w]].gshift_[w]<<1)+bitn;  
    bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }// counterw
  break;

  case 49: // GSR doesn't change (becomes a revenant) on TOGGLE
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    if (gate[w].trigger) tug[w]^=1; // tuggle
    if (tug[w]){
        GSHIFT;
    }
    else    gate[w].shift_=gate[w].shift_<<1;
  
    bitn = (gate[defroute[w]].gshift_[w]>>SRlength[defroute[w]]) & 0x01; 
    gate[defroute[w]].gshift_[w]=(gate[defroute[w]].gshift_[w]<<1)+bitn;  
    bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
    }// counterw
  break;

  case 50: // GSR is masked in on trigger
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    GSHIFT;
    // do we do bitn even if is ANDed in
    bitn = (gate[defroute[w]].gshift_[w]>>SRlength[defroute[w]]) & 0x01; 
    gate[defroute[w]].gshift_[w]=(gate[defroute[w]].gshift_[w]<<1)+bitn;  
    //    bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 
    if (gate[w].trigger) gate[w].shift_&=gate[defroute[w]].gshift_[w];

    PULSIN_XOR;    
    BITN_AND_OUT;    
    }// counterw
  break;

///here
  case 51: // GSR only moves on trigger - not so exciting
  bitn=0;

  if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0;
      GSHIFT;      

      if (gate[w].trigger==1){
	bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
	gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
      }
      bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }
    break;

  case 52: // GSR double move on trigger in and out of main loop
    if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0;
      GSHIFT;      

      if (gate[w].trigger==1){
	bitnn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
	gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitnn;  
      }
      
      bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
      gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
      //      bitn^=bitnn;
      //      bitn^=(gate[w].shift_>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }
    break;

  case 53: // just for TRIALs with other ADC/DAC options...  XXX INT TRIGGER!!!
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - experiment with ADCs
    // L: route from/bits in/logic - pass on/OR
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DACequiv
    // R: route from/bits in/logic  - pass on/OR

    if (gate[w].trigger==1){
    dactype[2]=0; 
    logtable[0]=0; logtable[1]=0; logtable[2]=0; logtable[3]=0;
    GSHIFT;
      
    if (w==0){// w below can be zeroed...
      bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01;
      gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;
      tmp=lookuplenall[(adc_buffer[lookupadc[w]]>>7)];// // 12 bits to 5 bits 
      bitn^=ADC_(w,SRlength[w],29,0,0,tmp); // otherpar for length from 12 -> 5 bits
    }
    else
      {
    bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
    gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
      }

    PULSIN_LOGOP;    
    BITN_AND_OUT;    
      }// counterw
  break; 
    
  case 54: // as 14 but now SR comped to adc
    // probability mode 4: wiard/en
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //4. new input (from route) or cycling bit - and OR in pulsebit if...    
    if (gate[w].trigger==1){ 
      dactype[2]=0; 

      GSHIFT;
      
      if ((gate[w].shift_ & 4095 )<adc_buffer[lookupadc[w]]) { // can be another routed SR.
      bitn=(gate[w].shift_>>SRlength[w])& 0x01; 
      }
      else{
	bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01;  
	gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 55: // as 14 but now SR comped to next SR
    // probability mode 4: wiard/en
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //4. new input (from route) or cycling bit - and OR in pulsebit if...    
    //    if (gate[w].trigger==1){ 
  if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0; 

      GSHIFT;
      
      if ((gate[w].shift_ & 4095 )< (shift_[inroute[count][w]] & 4095) ) { // can be other routed SRs
      bitn=(gate[w].shift_>>SRlength[w])& 0x01; 
      }
      else{
	bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01;  
	gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 56:
    // this one adds probability and logopx
    // was 26 but use for experimenting with routings
    // multiple routes in/change to binary routing table
    // implementation of multiple routing table - CV mode with dacrouted dac as source for table...
    // could also be bits from plain SR TODO
      if (counter[w]>speed[w] && speed[w]!=1024){
	tmpp=shift_[dacroute[w]]&255; // 8 bits - we use 8 bits
	GSHIFT;      
	bitn=0;
	// 2 bits for singular routes
	tmp=tmpp&3;
	bitn = (Gshift_[tmp][w]>>SRlength[tmp]) & 0x01; 
	Gshift_[tmp][w]=(Gshift_[tmp][w]<<1)+bitn;  
	// 2 bits or more for probability
	tmp=(tmpp>>2)&3;
	// LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
	// prob of cycling bit let's say or ADC bit in or...
	// prob of change to routes
	if (probableCV(w,tmp)){
	  tmp=(tmpp>>4)&3; // 2 bits for logopx
	  bitn=logopx(bitn, ((gate[w].shift_>>SRlength[w])& 0x01), tmp);  // just put in cycling bit or we can XOR in etc... could be logic bits now to test
	}
	
      PULSIN_XOR;
      gate[w].shift_+=bitn;
      // 2 bits for DAC
      gate[w].dac=DAC_(w, SRlength[w], (tmpp>>6)&3,param[w],gate[w].trigger); // all DACTypes changed here - top bits
      PULSOUT;
      }// counterw
      break; 

  case 57: // as 56 but try with CV
    // was 26 but use for experimenting with routings
    // multiple routes in/change to binary routing table
    // implementation of multiple routing table - CV mode with dacrouted dac as source for table...
    // could also be bits from plain SR TODO
    //      if (counter[w]>speed[w] && speed[w]!=1024){
        if (gate[w].trigger==1){ 
	  tmpp=adc_buffer[lookupadc[w]]>>4; // this can also be RSR DAC! 12 bits down to 6 bits - 9/11 add 2 bits for logopps
	  
	GSHIFT;      
	bitn=0;
	// 2 bits for singular routes
	tmp=tmpp&3;
	bitn = (Gshift_[tmp][w]>>SRlength[tmp]) & 0x01; 
	Gshift_[tmp][w]=(Gshift_[tmp][w]<<1)+bitn;  
	// 2 bits or more for probability
	tmp=(tmpp>>2)&3;
	// LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
	// prob of cycling bit let's say or ADC bit in or...
	// prob of change to routes
	if (probableCV(w,tmp)){// do
	  tmp=(tmpp>>4)&3; // 2 bits for logopp
	  bitn=logopx(bitn, ((gate[w].shift_>>SRlength[w])& 0x01), tmp);  // just put in cycling bit or we can XOR in etc... could be logic bits now to test
	}
	
      PULSIN_XOR;
      gate[w].shift_+=bitn;
      // 2 bits for DAC
      gate[w].dac=DAC_(w, SRlength[w], (tmpp>>6)&3,param[w],gate[w].trigger); // all DACTypes changed here - top bits
      PULSOUT;
      }// counterw
      break; 

  case 58: // try for generic probability mode...
    // what is generic TMetc functions for prob: invert cycling bit, 
    // 4 bits for routings, 2 bits prob to modify routings (in what way?), 2 bits logic, fixed DAC
    dactype[2]=0; // basic DAC out    
    tmpp=0b11000101; // test bits for this SR 

    if (counter[w]>speed[w] && speed[w]!=1024){
	GSHIFT;      
	bitn=0;
	tmp=(tmpp>>6)&3; // top 2 bits for probability
	if (probableCV(w,tmp)){
	  tmpp &= ~(1 << w); // eg. remove loopback = clear bit w
	}

	// how we deal with modes for ADC and DAC here
	
      tmp=tmpp&15; // bottom 4 bits 
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	xx=(tmpp>>4)&3;
	bitn=logop(bitn,bitrr,xx); // but what if we want different logical opps for each?
	//bitn^=bitrr;
    }
    tmp=tmp>>1;
      }	
      PULSIN_XOR;
      BITN_AND_OUT;
      PULSOUT;
      }// counterw
      break; 

  case 59: // NEW generic routing mode including ADC - replaces mode 9
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    

      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 

      if (w==3) {//change the global route - trigger[3] bumps the route up
	if (trigger[3]) count++;
	if (count>7) count=0;
      }      // TODO: in other w==3 modes we can set count to 0 or fix it somewhere else
      
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	//	xx=(tmpp>>4)&3;
	//	bitn=logop(bitn,bitrr,xx); // but what if we want different logical opps for each?
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 

  case 60: // as generic routing but testing use of MACRO with arguments
    if (counter[w]>speed[w] && speed[w]!=1024){
    par=0; parr=0;     // for this macro we need   par=0/or whatever for DAC outside and parr is for ADC 
    MULTROUTE(0, 0);     // X is adc_type, Y is dac_type
  }
    break;

  case 61: // as generic routing but testing use of MACRO with arguments - speedCV but complimented by trigger
    if (counter[w]>speed[w] && speed[w]!=1024){
      if (gate[w].trigger){
    par=0; parr=0;     // for this macro we need   par=0/or whatever for DAC outside and parr is for ADC 
    MULTROUTE(0, 0);     // X is adc_type, Y is dac_type, REGG is where to take from for adc
      }
  }
    break;
//here
    ////// modes from it.c but not using coggn so tricky
  case 62: // LFSR in routed in SRs
    // NEW generic routing mode including ADC - replaces mode 9
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    

      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 
      if (w==3) count=0; // default route
      
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = ((gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][0])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][1])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][2])) ^ (gate[x].Gshift_[w] >> (lfsr_taps[SRlength[x]][3]))) & 1u;
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 

  case 63: // NEW generic routing mode including ADC - replaces mode 9 - as 59 but no bump
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
        if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
    
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    

      if (w==3) count=0; // reset count/route
      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 
      
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	//	xx=(tmpp>>4)&3;
	//	bitn=logop(bitn,bitrr,xx); // but what if we want different logical opps for each?
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 

  case 64:// as 63 but we try INTmode with CV changing length of incoming routes
    // NEW generic routing mode including ADC - replaces mode 9 - as 59 but no bump
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    if (gate[w].trigger){ // adc_buffer[lookupadc[w]]    
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    

      if (w==3) count=0; // reset count/route
      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 

      tmpp=31-(CV[1]>>7);// 5 bits for length    
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (gate[x].Gshift_[w]>>tmpp) & 0x01; // or other logical opp for multiple bits/accum
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	//	xx=(tmpp>>4)&3;
	//	bitn=logop(bitn,bitrr,xx); // but what if we want different logical opps for each?
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 
    
  case 65: // SR in SR with strobe as barrier? only for itself or for incoming/itself
    // NEW generic routing mode including ADC - replaces mode 9 - as 59 but no bump
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      cw++;
      if (cw>31) cw=0;
      if (gate[w].trigger) tmpt=cw;
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    

      if (w==3) count=0; // reset count/route
      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 
      
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
	if (tmp&0x01 || x==w){   // if we want self-feedback in route whatever...
	  bitrr = (gate[x].Gshift_[w]>>tmpt) & 0x01; // or can just keep tmpt for this one and len of previous
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 

  case 66: // SR in SR with strobe as barrier? only for itself or for incoming/itself - variation on above
    // NEW generic routing mode including ADC - replaces mode 9 - as 59 but no bump
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      cw++;
      if (cw>31) cw=0;
      if (gate[w].trigger) tmpt=cw;
      dactype[2]=0;
      GSHIFT;    

      if (w==3) count=0; // reset count/route
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 
      
      tmp=binroute[count][w]; 
      for (x=0;x<4;x++){ 
	if (w==x){
	  bitrr = (gate[x].Gshift_[w]>>tmpt) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
	else if (tmp&0x01){
	  bitrr = (gate[x].Gshift_[w]>>SRlength[x]) & 0x01; 
	gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<1)+bitrr; 
	bitn^=bitrr;
      }
	
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 
    
    
  case 67: // trial for shifter1
    // NEW generic routing mode including ADC - replaces mode 9 - as 59 but no bump
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    //        if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
    if (gate[w].trigger){
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      //      GSHIFT;    
      tmpp=CVin; //31-(adc_buffer[lookupadc[w]]>>7); // 5 bits for length only
      counter[w]=0;
      gate[w].shift_[0]=gate[w].shift_;
      gate[w].shift_[1]=gate[w].shift_;
      gate[w].shift_[2]=gate[w].shift_;
      gate[w].shift_[3]=gate[w].shift_;
      gate[w].shift_=gate[w].shift_<<tmpp;
      
      if (w==3) count=0; // reset count/route
      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 
      
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){
	if (tmpp>SRlength[x]) tmpp=SRlength[x];
	if (tmpp!=0){
	  bitrr=(gate[x].Gshift_[w]&(othermasky[tmpp]>>(31-SRlength[x])))>>(SRlength[x]-(tmpp-1));
	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<tmpp)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	bitn^=bitrr;
	}
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 

  case 68: // trial for shifter1 - overlap - we just XOR in the Gshift bits but don't move gshift
    // NEW generic routing mode including ADC - replaces mode 9 - as 59 but no bump
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    //        if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
    if (gate[w].trigger){
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    
      tmpp=CVin; //31-(adc_buffer[lookupadc[w]]>>7); // 5 bits for length only
      
      if (w==3) count=0; // reset count/route
      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 
      
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){
	if (tmpp>SRlength[x]) tmpp=SRlength[x];
	if (tmpp!=0){
	  bitrr=(gate[x].Gshift_[w]&(othermasky[tmpp]>>(31-SRlength[x])))>>(SRlength[x]-(tmpp-1));
	  //	  gate[x].Gshift_[w]=(gate[x].Gshift_[w]<<tmpp)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	bitn^=bitrr;
	}
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	//	BITN_AND_OUT;
    gate[w].shift_^=bitn;
    gate[w].dac=DAC_(w, SRlength[w], dactype[w],par,gate[w].trigger); 
    PULSOUT;	
    }// counterw
    break; 

    
    

    
    /////////////////////////////////////////////////////////////////////////
    /// extra experimental cases // tested
    /////////////////////////////////////////////////////////////////////////
  case 104:  // let's try INT driven one for pulse train mode
  // INT triggers train of CV pulses at speed DAC - and can also be vice versa
    // INT can also start new train or let old one carry on (now it starts new train...)
    if (gate[w].trigger==1){ 
      train[w]=1; // we can use train as counter      
    }
    if (train[w]!=0 && train[w]<(speed[w]+1)){ // number of pulses
      // do train so first we need speed counter
      if (counter[w]>gate[dacfrom[count][w]].dac){ // or another dac
	train[w]++;
	// from DACR now but can be dacfrom!
	counter[w]=0;
	// now we can do any kind of SR, but guess makes sense for NSR to be LFSR or so???
	// so we borrow some from mode 3
	dactype[2]=0; // basic DAC out
    
	GSHIFT;

	if (w==0){
	  bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01;  
      gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
      bitn^=ADC_(w,SRlength[w],2,0,0,0); // XOR with LFSR
    }
    else
      {
    bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
    gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
      }

    PULSIN_XOR;    
    BITN_AND_OUT;    
      }
    }
    else train[w]=0; // train ran out
    break;
    ///////////
  case 105:// this is the vice versa of the above
    // let's try INT driven one for pulse train mode
  // INT triggers train of CV pulses at speed DAC - and can also be vice versa
    // INT can also start new train or let old one carry on (now it starts new train...)
    if (gate[w].trigger==1){ 
      train[w]=1; // we can use train as counter      
    }
    if (train[w]!=0 && train[w]<gate[dacroute[count][w]].dac){ // number of pulses
      // do train so first we need speed counter
        if (counter[w]>speed[w] && speed[w]!=1024){ // or another dac
	train[w]++;
	dactype[2]=0; // basic DAC out    
	GSHIFT;
	if (w==0){
      bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01;  
      gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
      bitn^=ADC_(w,SRlength[w],2,0,0,0); // XOR with lFSR
    }
    else
      {
    bitn = (gate[inroute[count][w]].Gshift_[w]>>SRlength[inroute[count][w]]) & 0x01; 
    gate[inroute[count][w]].Gshift_[w]=(gate[inroute[count][w]].Gshift_[w]<<1)+bitn;  
      }

	PULSIN_XOR;    
	BITN_AND_OUT;    
      }
    }
    else train[w]=0; // train ran out

// extramodes

// DONE: Gshift_[x][w] becomes gate[x].gate[w].shift_
// gate[w].shift_ becomes gate[w].shift_

/*
  case 333: // TEST mode - with new cumulative/adding mode which joins in previous SR 26/11 from notebook/pages
    // not sure if this makes sense
    // alts are also:
    // -[ copy as enter mode - we need to flag this and also store length of routed in reg we copied]
    // - length as overlap?
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(0, 0);
      if (LR[w]){
      //	  BINROUTE_; // fill in L and R modes here - BINROUTE_ is standard routings
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].gate[w].shift_>>SRlength[x]) & 0x01;
	  //	      gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr;
	  gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1) + ((gate[w].shift_>>SRlength[w]) & 0x01);
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }	  
      /////...
PULSIN_XOR;
    } 
BITN_AND_OUT;
  }
    break;

  case 334: // TEST mode as 333 but with strobe
     // - in strobe copy routed GSR to GGSR and then cycle through with/without shift back in? so they form one long SR now
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
	  ADCDACETC1(0, 0);
      if (LR[w]){
	  //	  BINROUTE_; // fill in L and R modes here - BINROUTE_ is standard routings
	  if (gate[w].trigger) { 
	    tmp=binroute[count][w];
	    for (x=0;x<4;x++){
	      if (tmp&0x01){
		storedlength[x][w]=SRlength[x];
		gate[x].gate[w].shift_=gate[x].gate[w].shift_;
		bitrr = (gate[x].gate[w].shift_>>SRlength[x]) & 0x01;
		gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1) + ((gate[w].shift_>>SRlength[w]) & 0x01);
		bitn^=bitrr;
	    }
	    tmp=tmp>>1;
	  }
	  }
	  else
	    { // but we must have had a trigger to fill GGshift
	  tmp=binroute[count][w];
	  for (x=0;x<4;x++){
	    if (tmp&0x01){
	      bitrr = (gate[x].gate[w].shift_>>storedlength[x][w]) & 0x01;
	      //	      gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr;
	      gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1) + ((gate[w].shift_>>SRlength[w]) & 0x01);
	      bitn^=bitrr;
	    }
	    tmp=tmp>>1;
	  }	  
	    }
	  /////...
  PULSIN_XOR;
     } 
 BITN_AND_OUT;
  }
    break;
*/

// from extramodes.c 

// was 15

	// 4x4 bits prob of routing in GSR  so we need 4 probs of x bits?
	tmp=LFSR_[w]; tmpp=shift_[LFSR[w]]; // try with CV too
	for (x=0;x<4;x++){
	  if ((tmp&255)<(tmpp&255)){// replace with 12 bits /4 = 3 bits prob = 7 (LFSR_[w] & 4095 ) < (shift_[LFSR[w]] & 4095)
	  bitrr = (gate[x].gate[w].shift_>>SRlength[x]) & 0x01;
	  gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>8; tmpp=tmpp>>8;
	}	


// was 14

	//- probability of advancing a GSR - strobe version we have above in 3 (commented out)DONE
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (gate[x].gate[w].shift_>>SRlength[x]) & 0x01;
	  if ((LFSR_[w] & 4095 ) < (gate[LFSR[w]].dac)) gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
	}	


// was 13

	//      BINROUTE_; // TODO: fill in L and R modes here - BINROUTE_ is standard routings
	///	- TODO: mode in which pulse changes which bit ofghostSR we access - pulse moves on bit
	// can also be change access bit but not cycling bit! TODO!
	
	// also cycling bit version     if ((tmp&0x01) || (x==w)){ 
	if (gate[w].trigger) {
	    which[w]++;
	    if (which[w]>SRlength[w]) which[w]=0;
	  }

	  tmp=binroute[count][w];
	  for (x=0;x<4;x++){
	    if (tmp&0x01){
	      bitrr = (gate[x].gate[w].shift_>>which[w]) & 0x01;
	      gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr;
	      bitn^=bitrr;
	    }
	    tmp=tmp>>1;
	  }	  
      /////////////////////////////////////...

// was 11

	if (gate[w].trigger) tug[w]^=1;
	if (tug[w]){
	  BINROUTE_;
	}
	else bitn=!((gate[w].shift_>>SRlength[w]) & 0x01); 
	
      /////////////////////////////////////...



// was 10

      //////////////////////////////////HERE!
	// trial these with strobe - 01 BITIN or loopback
	if (gate[w].trigger) tug[w]^=1;
	if (tug[w]){
	  BINROUTE_;
	}
	else bitn=((gate[w].shift_>>SRlength[w]) & 0x01); 
	/////////////////////////////////////...



// was 9

	// trial these with strobe - 00 invert bit here
	BINROUTE_;
	if (gate[w].trigger) tug[w]^=1;
	if (tug[w])	  bitrr=(gate[w].shift_>>SRlength[w]) & 0x01;
	else bitrr=!((gate[w].shift_>>SRlength[w]) & 0x01); 
	bitn|=bitrr;
	
      /////////////////////////////////////...



// was 8
      //////////////////////////////////HERE!
	// as above but without toggle...
	if (gate[w].trigger){
	BINROUTEANDCYCLE_;	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}	
      /////////////////////////////////////...


// was 7
      //////////////////////////////////HERE!
	// trial toggle/tug of above: entry of routed or not (into cycling). and just xor puls in...
	if (gate[w].trigger) tug[w]^=1;
	if (tug[w]){
	  BINROUTEANDCYCLE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}	
      /////////////////////////////////////...	


// was 6

      //////////////////////////////////HERE!
      //      BINROUTE_; // TODO: fill in L and R modes here - BINROUTE_ is standard routings
	/*
// USED
      // XX - we XOR on STROBE our shift with the GHOST
  tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
    if (gate[w].trigger) gate[x].gate[w].shift_^=gate[w].shift_;
    bitrr = (gate[x].gate[w].shift_>>SRlength[x]) & 0x01;
    if (gate[w].trigger) 
      gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
	*/
	// - basic prob mode of entry of routed or not (into cycling). and just xor puls in...
	if (gate[LFSR[w]].dac) < (param[w] & 4095)){
	  BINROUTEANDCYCLE_;
	}
	else {
	  bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
	}

	/////////////////////////////////////...


/* draft prob modes for trigger:

00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ?? -- 9 below

BINROUTE_;
if (gate[w].trigger)	  bitrr=(gate[w].shift_>>SRlength[w]) & 0x01;
else bitrr=!((gate[w].shift_>>SRlength[w]) & 0x01); 
bitn|=bitrr;

01 2-BITIN or loopback

if (gate[w].trigger){
BINROUTE_;
}
else {
bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
}	

10 3-INV of above

if (gate[w].trigger){
BINROUTE_;
}
else {
bitn=!(gate[w].shift_>>SRlength[w]) & 0x01; 
}	

//11 4- BITIN or not into cycling

if (gate[w].trigger){
BINROUTEANDCYCLE_;
}
else {
bitn=(gate[w].shift_>>SRlength[w]) & 0x01; 
}	



     */

// was 5

//////////////////////////////////HERE!
	/*
// USED!
      // XX = strobe reverses ghostSR in - can also use same algo to reverse our own SR
      // is it fast enough? or just have one route in
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  if (gate[w].trigger){
	    tmpp=gate[x].gate[w].shift_;
	    REV32; // reverse 32 bits
	    tmpp=tmpp&othermasky[SRlength[x]]; // mask the top length bits
	    gate[x].gate[w].shift_=tmpp>>(31-SRlength[x]); // and shift 31-length bits
	  }
	  bitrr = (gate[x].gate[w].shift_>>SRlength[x]) & 0x01;
	  gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr; // 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
	} */   
      /////////////////////////////////////...
	// next set of generic bit options - this time for probabilities
	/*
	  00 1-TM invert cycling bit - OR with BITIN (OR *(routed^pulse)*) // OR (routedORpulse) ??
	  01 2-BITIN or loopback
	  10 3-INV of above
	  11 4- BITIN or not into cycling
	  
	  - so is 2 bits for type of prob
	  - BITN is routed / routed XOR puls so is 1 bit
	  - where we get prob is 2 bits let's say = 5 bits = 32
	*/
	BINROUTE_;
	
      bitrr = (gate[w].shift_>>SRlength[w]) & 0x01; 

      tmpp=shift_[dacfrom[count][w]]&31; // 5 bits
      if ((tmpp>>4)&1) {
	PULSIN_XOR;
      }

      if (tmpp==0){ 	  // invert cycling bit and OR with bitn
	if (otherprobableCV(w, ((tmpp>>2&0x03)))) {
	  bitn |= !(bitrr);
	  }
	else bitn |=bitrr;	
      }
      else if (tmpp&1){ // BITN or loopback
	if (!otherprobableCV(w, ((tmpp>>2&0x03)))) {
	  bitn=bitrr;
	}
      }
      else if (tmpp&2){ // BITN or INV loopback
	if (!otherprobableCV(w, ((tmpp>>2&0x03)))) {
	  bitn=!bitrr;
	}
      }
	else if (tmpp&3) { // 4- BITIN or not into cycling
	if (otherprobableCV(w, ((tmpp>>2&0x03)))) {
	  bitn=bitrr^bitn;
	}
	else bitn=bitrr;
	}	


// was 4

//////////////////////////////////HERE!
      //      BINROUTE_; // TODO: fill in L and R modes here - BINROUTE_ is standard routings
      /////////////////////////////////////...
	/*
      // XX = strobe fixes length       
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  if (gate[w].trigger) storedlength[x][w]=SRlength[x];
	  bitrr = (gate[x].gate[w].shift_>>storedlength[x][w]) & 0x01;
	  gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }
	*/
      ///////////////////////
	// trial of generic bit options - bits from which SR, from param etc.
	// route in and logop bits:
	// 1111 4 route in bits x 3 logopx = 2 bits per... 0, none, 1, xor, 2or, 3inv XOR = 8 bits = 255 too much for CV
	tmp=shift_[dacfrom[count][w]]&255; // 8 bits - we can also interpret bits as single ones... we just seem to use 6 bits here
	for (x=0;x<4;x++){ 
	  if ((tmp&0x03) !=0){  
	    bitrr = (gate[x].gate[w].shift_>>SRlength[x]) & 0x01; 
	    gate[x].gate[w].shift_=(gate[x].gate[w].shift_<<1)+bitrr; 
	    bitn=logopx(bitn,bitrr,(tmp)&0x03); 
	  }
	  tmp=tmp>>2; // 4 bits
	}




