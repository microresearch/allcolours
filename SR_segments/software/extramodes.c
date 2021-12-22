// test logic for minor major modes
// say 4 major modes

// but how we can split modes?
major=mode[3]>>4; // from 64=6bits to 2 bits 

if (w!=3){
switch(major){
 case 0:
   // we do all modes for all except 3
   switch(mode[w]{ // or this would be a bit interpretation and we have no switch
       case 0:
	 break;
     }
   break;
     }
 }//major
 }//w!=3
 else {
   // w==3 modes
   switch(mode[3]){// here we have 16 (x4-64) minor modes for the right side...
   case 0: 
     break;
   }
 }//w==3



  case 333: // TEST mode - with new cumulative/adding mode which joins in previous SR 26/11 from notebook/pages
    // not sure if this makes sense
    // alts are also:
    // -[ copy as enter mode - we need to flag this and also store length of routed in reg we copied]
    // - length as overlap?
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(0, 0);
      if (LR[w]){
      //	  BINROUTE; // fill in L and R modes here - BINROUTE is standard routings
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  //	      Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
	  Gshift_[x][w]=(Gshift_[x][w]<<1) + ((shift_[w]>>SRlength[w]) & 0x01);
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
	  //	  BINROUTE; // fill in L and R modes here - BINROUTE is standard routings
	  if (trigger[w]) { 
	    tmp=binroute[count][w];
	    for (x=0;x<4;x++){
	      if (tmp&0x01){
		storedlength[x][w]=SRlength[x];
		GGshift_[x][w]=Gshift_[x][w];
		bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
		GGshift_[x][w]=(Gshift_[x][w]<<1) + ((shift_[w]>>SRlength[w]) & 0x01);
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
	      bitrr = (GGshift_[x][w]>>storedlength[x][w]) & 0x01;
	      //	      Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
	      GGshift_[x][w]=(GGshift_[x][w]<<1) + ((shift_[w]>>SRlength[w]) & 0x01);
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


// was 15

	// 4x4 bits prob of routing in GSR  so we need 4 probs of x bits?
	tmp=LFSR_[w]; tmpp=shift_[LFSR[w]]; // try with CV too
	for (x=0;x<4;x++){
	  if ((tmp&255)<(tmpp&255)){// replace with 12 bits /4 = 3 bits prob = 7 (LFSR_[w] & 4095 ) < (shift_[LFSR[w]] & 4095)
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>8; tmpp=tmpp>>8;
	}	


// was 14

	//- probability of advancing a GSR - strobe version we have above in 3 (commented out)DONE
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  if ((LFSR_[w] & 4095 ) < (shift_[LFSR[w]] & 4095)) Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
	}	


// was 13

	//      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	///	- TODO: mode in which pulse changes which bit ofghostSR we access - pulse moves on bit
	// can also be change access bit but not cycling bit! TODO!
	
	// also cycling bit version     if ((tmp&0x01) || (x==w)){ 
	if (trigger[w]) {
	    which[w]++;
	    if (which[w]>SRlength[w]) which[w]=0;
	  }

	  tmp=binroute[count][w];
	  for (x=0;x<4;x++){
	    if (tmp&0x01){
	      bitrr = (Gshift_[x][w]>>which[w]) & 0x01;
	      Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
	      bitn^=bitrr;
	    }
	    tmp=tmp>>1;
	  }	  
      /////////////////////////////////////...


// was 12

	//////////////////////////////////HERE!
	// trial of non-adc style entry and pass on here;;
	// which modes of ADC_?: 5:LFSR, 30:1bitOSC, 32: clock
	reggg=w; adcpar=param[w];
	// can also bump up type in list with a trigger[w] TODO/TEST - here we just select from 5 and 32 as 30 used param
	if (trigger[w]) tug[w]^=1;
	bitn=ADC_(w,SRlength[w],ADCLR[tug[w]],trigger[w],reggg,adcpar);  //5,30,32 as selections - 32 maybe not so interesting
	BINROUTE;


// was 11

	if (trigger[w]) tug[w]^=1;
	if (tug[w]){
	  BINROUTE;
	}
	else bitn=!((shift_[w]>>SRlength[w]) & 0x01); 
	
      /////////////////////////////////////...



// was 10

      //////////////////////////////////HERE!
	// trial these with strobe - 01 BITIN or loopback
	if (trigger[w]) tug[w]^=1;
	if (tug[w]){
	  BINROUTE;
	}
	else bitn=((shift_[w]>>SRlength[w]) & 0x01); 
	/////////////////////////////////////...



// was 9

	// trial these with strobe - 00 invert bit here
	BINROUTE;
	if (trigger[w]) tug[w]^=1;
	if (tug[w])	  bitrr=(shift_[w]>>SRlength[w]) & 0x01;
	else bitrr=!((shift_[w]>>SRlength[w]) & 0x01); 
	bitn|=bitrr;
	
      /////////////////////////////////////...



// was 8
      //////////////////////////////////HERE!
	// as above but without toggle...
	if (trigger[w]){
	BINROUTEANDCYCLE;	}
	else {
	  bitn=(shift_[w]>>SRlength[w]) & 0x01; 
	}	
      /////////////////////////////////////...


// was 7
      //////////////////////////////////HERE!
	// trial toggle/tug of above: entry of routed or not (into cycling). and just xor puls in...
	if (trigger[w]) tug[w]^=1;
	if (tug[w]){
	  BINROUTEANDCYCLE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[w]) & 0x01; 
	}	
      /////////////////////////////////////...	


// was 6

      //////////////////////////////////HERE!
      //      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/*
// USED
      // XX - we XOR on STROBE our shift with the GHOST
  tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
    if (trigger[w]) Gshift_[x][w]^=shift_[w];
    bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
    if (trigger[w]) 
      Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
	*/
	// - basic prob mode of entry of routed or not (into cycling). and just xor puls in...
	if ((LFSR_[w] & 4095 ) < (param[w] & 4095)){
	  BINROUTEANDCYCLE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[w]) & 0x01; 
	}

	/////////////////////////////////////...


/* draft prob modes for trigger:

00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ?? -- 9 below

BINROUTE;
if (trigger[w])	  bitrr=(shift_[w]>>SRlength[w]) & 0x01;
else bitrr=!((shift_[w]>>SRlength[w]) & 0x01); 
bitn|=bitrr;

01 2-BITIN or loopback

if (trigger[w]){
BINROUTE;
}
else {
bitn=(shift_[w]>>SRlength[w]) & 0x01; 
}	

10 3-INV of above

if (trigger[w]){
BINROUTE;
}
else {
bitn=!(shift_[w]>>SRlength[w]) & 0x01; 
}	

//11 4- BITIN or not into cycling

if (trigger[w]){
BINROUTEANDCYCLE;
}
else {
bitn=(shift_[w]>>SRlength[w]) & 0x01; 
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
	  if (trigger[w]){
	    tmpp=Gshift_[x][w];
	    REV32; // reverse 32 bits
	    tmpp=tmpp&othermasky[SRlength[x]]; // mask the top length bits
	    Gshift_[x][w]=tmpp>>(31-SRlength[x]); // and shift 31-length bits
	  }
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; // 
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
	BINROUTE;
	
      bitrr = (shift_[w]>>SRlength[w]) & 0x01; 

      tmpp=shift_[dacroute[w]]&31; // 5 bits
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
      //      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
	/*
      // XX = strobe fixes length       
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  if (trigger[w]) storedlength[x][w]=SRlength[x];
	  bitrr = (Gshift_[x][w]>>storedlength[x][w]) & 0x01;
	  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }
	*/
      ///////////////////////
	// trial of generic bit options - bits from which SR, from param etc.
	// route in and logop bits:
	// 1111 4 route in bits x 3 logopx = 2 bits per... 0, none, 1, xor, 2or, 3inv XOR = 8 bits = 255 too much for CV
	tmp=shift_[dacroute[w]]&255; // 8 bits - we can also interpret bits as single ones... we just seem to use 6 bits here
	for (x=0;x<4;x++){ 
	  if ((tmp&0x03) !=0){  
	    bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; 
	    Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	    bitn=logopx(bitn,bitrr,(tmp)&0x03); 
	  }
	  tmp=tmp>>2; // 4 bits
	}



// was 3-USED
/*
      // exp mode just for trial - XX - strobe advances/freezes incoming GHOSTSR
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  if (trigger[w]) Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
	}
	*/
