///////////////////////////////
//rec and play code
      //      ADC_SoftwareStartConv(ADC1);
      //      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits 7 bits=128
      // for frozen speed instead:
      speed=real[6]>>7; // 12 bits to 5 bits and speed is 4
      if (speed>31) speed=31;
      speed=32-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++;
	//	if ( !(GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]=0; 
	
	if (triggered[8]==1 && lasttriggered[8]==0) { // new trigger
	  tgr_cnt[8]=0;
	  lasttriggered[8]=1;
	}
	
	if (lasttriggered[8]==1) 	tgr_cnt[8]++;

	if (tgr_cnt[8]>TRG8){
	  triggered[8]=0;
	  lasttriggered[8]=0;
	}
      
	//play	
      
    	if (!(GPIOB->IDR & (1<<2)) && triggered[9]==0 && breaker[9]>BRK8) {
	  triggered[9]=1;
	  play^=1;
	  breaker[9]=0;
	}

	if ( (GPIOB->IDR & (1<<2)) && triggered[9]==0) breaker[9]++;
	//	if ( !(GPIOB->IDR & (1<<2)) && triggered[9]==0) breaker[9]=0; 
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	tmp=rec;
	if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
	if (tmp) play=0;
    }      


///////////////////////////////
/////// freezer code

	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	  if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) { // as is on GPIOC
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++;
	if ( !(GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]=0; 

	if (triggered[7]==1 && lasttriggered[7]==0) { // new trigger
	  tgr_cnt[7]=0;
	  lasttriggered[7]=1;
	}
	
	if (lasttriggered[7]==1) 	tgr_cnt[7]++;

	if (tgr_cnt[7]>TRG){
	  triggered[7]=0;
	  lasttriggered[7]=0;
	}	 	  
	} // daccount==7
  else
    {
	if (!(GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0 && breaker[daccount]>BRK) {
	  triggered[daccount]=1;
	  frozen[daccount]^=1;
	  breaker[daccount]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0) breaker[daccount]++; 
	if ( !(GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0) breaker[daccount]=0;
	
	if (triggered[daccount]==1 && lasttriggered[daccount]==0) { // new trigger
	  tgr_cnt[daccount]=0;
	  lasttriggered[daccount]=1;
	}
	
	if (lasttriggered[daccount]==1) 	tgr_cnt[daccount]++;

	if (tgr_cnt[daccount]>TRG){
	  triggered[daccount]=0;
	  lasttriggered[daccount]=0;
	}
    }

///////////////////////////////

if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;       freezern[0]=0;       frcount[0]=0; lastvalue[0]=values[0];
      play_cnt[1]=0;       freezern[1]=0;       frcount[1]=0; lastvalue[1]=values[1];
      play_cnt[2]=0;       freezern[2]=0;       frcount[2]=0; lastvalue[2]=values[2];
      play_cnt[3]=0;       freezern[3]=0;       frcount[3]=0; lastvalue[3]=values[3];
      play_cnt[4]=0;       freezern[4]=0;       frcount[4]=0; lastvalue[4]=values[4];
      play_cnt[5]=0;       freezern[5]=0;       frcount[5]=0; lastvalue[5]=values[5];
      play_cnt[6]=0;       freezern[6]=0;       frcount[6]=0; lastvalue[6]=values[6];
      play_cnt[7]=0;       freezern[7]=0;       frcount[7]=0; lastvalue[7]=values[7];
    }
    // take care of frozen/repeats - top bit is toggled and we just repeat last value...
    // we can re-use frcount and freezern as rec and play never happen at same time - and we zero them on entry
    if ( ((recordings[daccount][play_cnt[daccount]]) & (1<<15)) && freezern[daccount]==0  ){ // top bit is toggled
      freezern[daccount]=1;
      frcount[daccount]=0;
      target[daccount]=recordings[daccount][play_cnt[daccount]] - (1<15);
    }
	
    if (freezern[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    else { // freezern!
      if (play_cnt[daccount]==0) tmp=(recordings[daccount][6999]);
      else tmp=(recordings[daccount][play_cnt[daccount]-1]);
      values[daccount]=tmp;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
      if (freezern[daccount]==1){
	frcount[daccount]++;
	if (frcount[daccount]==target[daccount]) {
	  if (rec_cnt[daccount]==1) { // then just loop on freeze
	    frcount[daccount]=0;
	  }
	else {
	  freezern[daccount]=0;
	  play_cnt[daccount]++;
	  if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
	}
	}
      } // freezern
      else {
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
      }
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0;       freezern[0]=0;       frcount[0]=0;
      rec_cnt[1]=0;       freezern[1]=0;       frcount[1]=0;
      rec_cnt[2]=0;       freezern[2]=0;       frcount[2]=0;
      rec_cnt[3]=0;       freezern[3]=0;       frcount[3]=0;
      rec_cnt[4]=0;       freezern[4]=0;       frcount[4]=0;
      rec_cnt[5]=0;       freezern[5]=0;       frcount[5]=0;
      rec_cnt[6]=0;       freezern[6]=0;       frcount[6]=0;
      rec_cnt[7]=0;       freezern[7]=0;       frcount[7]=0;
    }
    // TODO: implement freeze:  marked by upper bit and value is length of repeat...
    if (frozen[daccount] && freezern[daccount==0]) {
      freezern[daccount]=1;  //toggle freezern[daccount] to signal we start
      frcount[daccount]=0;
      if (rec_cnt[daccount]==0) { // there is no previous value...
	recordings[daccount][0]=values[daccount];
	rec_cnt[daccount]=1;
	}
    }
    // and start counting until freeze goes to zero then write this counter to lower bits(make sure is not>max=32767 + toggle top bit
    if (freezern[daccount]){
      frcount[daccount]++;
      recordings[daccount][rec_cnt[daccount]]=frcount[daccount]+(1<<15);
      if (frozen[daccount]==0 || frcount[daccount]==32767){ // so there is a max frozen time?
	freezern[daccount]=0;
	frcount[daccount]=0;
	rec_cnt[daccount]++;
	if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
      }
    } // in freezern
    else { 
    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
    }

  } // if rec
  else lastrec=0;
    } // count32



/////////////////////////////

	/*			
	// this new version seems to work - TODO: implement for all

	if (!(GPIOB->IDR & (1<<10)) && triggered==0 && breaker>BRK) {
	  triggered=1;
	  rec^=1;
	  breaker=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered==0) breaker++; 
	
	if (triggered==1 && lasttriggered==0) { // new trigger
	  tgr_cnt[0]=0;
	  lasttriggered=1;
	}
	
	if (lasttriggered==1) 	tgr_cnt[0]++;

	if (tgr_cnt[0]>BRK){
	  triggered=0;
	  lasttriggered=0;
	}
	*/

	/*
	if (laststaterec!=newstaterec) tgr_cnt[0]=0;

    	if (tgr_cnt[0]>20){
	  if (newstaterec!=staterec){
	    staterec=newstaterec;
	    if (staterec==0) rec^=1;
	  }
	}
	
	laststaterec=newstaterec;	
	tgr_cnt[0]++;
	*/	

///////////////////////////////////////////////////////////////////////  
/*  if (rec) k=4095; // 2 6 and 10
      else k=0;
  
  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1);
  GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
  GPIOC->BSRRL=(0)<<13; //  write DAC bits 
    */


/*      if (!(GPIOC->IDR & (freezer[7]))) newstate[7]=1; 
      else newstate[7]=0;

      if (laststate[7]!=newstate[7]) tgr_cnt[7]=0;

    	if (tgr_cnt[7]>TGR){
	  if (newstate[7]!=state[7]){
	    state[7]=newstate[7];
	    if (state[7]==1) frozen[7]^=1;
	  }
	  }
	laststate[7]=newstate[7];	

	tgr_cnt[7]++;*/

      /*
      	if (!(GPIOB->IDR & (1<<10))) newstaterec=1; 
	else newstaterec=0;

	if (laststaterec!=newstaterec) tgr_rec=0;

    	if (tgr_rec>TGR){
	  if (newstaterec!=staterec){
	    staterec=newstaterec;
	    if (staterec==1) rec^=1;
	  }
	}
	
	laststaterec=newstaterec;	
	tgr_rec++;
      */


	/*	if (!(GPIOB->IDR & (1<<2))) newstateplay=1; 
	else newstateplay=0;

	if (laststateplay!=newstateplay) tgr_play=0;

    	if (tgr_play>TGR){
	  if (newstateplay!=stateplay){
	    stateplay=newstateplay;
	    if (stateplay==1) play^=1;
	  }
	}
	
	laststateplay=newstateplay;	
	tgr_play++;
	*/


	


  
  //////////////  TEST CODE
  
  // test central circles - all work but strong 50Hz so we need toggle and delay
  // others need to be larger with small gap!

  // FR1-7 on PB8-15, FR8 on PC4 (inverted ins from 40106 so low is on!)
  // swopped play and FR3
  //  - rec on PB2, play on PB4/swopped->, push on PB6
  // play and FR3 are swopped - FR3 was on PB10



// read
    //  GPIOC->BSRRL = 0b0000000000000000;       // write PC13/14/15  -> DAC8 which is v4 top right, 7 is v3 top left, 6 is v2 lower left, 5 is v1 lower right
  //  GPIOC->BSRRL = 0b1110000000000000;       // write PC13/14/15  -> DAC8 which is v4 top right, 7 is v3 top left, 6 is v2 lower left, 5 is v1 lower right
  //      GPIOC->BSRRL = 0b1000000000000000;      // now we want to test the VCAs-> lower bits so 1 is lower right
  //k=4095; // peak 6.6v      
  //DAC_SetChannel1Data(DAC_Align_12b_R, dacval[daccount]); // 1000/4096 * 3V3 == 0V8
  //      k=4095;
  // but Voltages are mixed up as ADC0 is not there


otherk++;
      if (otherk>16){
	otherk=0;
      k++;
      if (k>4095) k=0;
      }
      //      k=0;

      //            GPIOB->BSRRH =       0b0000000100000000;
      //	    GPIOB->BSRRL =       0b0000000100000000;
      //      delay();
      // flip-flop from PC8
      //      GPIOA->ODR ^= (1 << 5);      

      /*
      
      if (GPIOC->IDR & 0x0100){ // pin 8 
      if (flipped==0) {
	flipped=1;
	prev_state=0;
      }
	}
	else flipped=0;
	  
	if (flipped==1 && prev_state==0)
	  {
	  prev_state=1;
	  GPIOA->ODR ^= (1 << 5);
	  }
      */
      
      /// multiplex and DAC tests
            
      //    GPIOB->ODR = 0b0000000100000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    // Y1 is S1 on 4051 high which is 11 on 4051 which is pin PB8

      //      delay();
      //      delayy();
    
      // testing transistor switch of 4066 on and off
    //    GPIOB->ODR = 0b0000000100000000;  //PB8-13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    //    delayy();
    //    GPIOB->ODR = 0b0000000000000000;  //PB8-13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    //    delayy();
      

      //      EN_LOW1 on PC11 and sel1/2/3 on PC13/14/15

      // 5,6,7,8 DACs are voltages to test - tested and all fine but test sample and hold
      //      daccount=2;
      daccount=0;
      GPIOC->BSRRH = 0b1110100000000000;  // clear PC11 - clear pc11 and top bits -> low
      GPIOC->BSRRL = 0b000000000000000;       // write PC13/14/15  -> DAC8 which is v4 top right, 7 is v3 top left, 6 is v2 lower left, 5 is v1 lower right
      //      GPIOC->BSRRL=(daccount)<<13;
      //      GPIOC->BSRRL = 0b1000000000000000;      // now we want to test the VCAs-> lower bits so 1 is lower right
      //k=4095; // peak 6.6v      
      //DAC_SetChannel1Data(DAC_Align_12b_R, dacval[daccount]); // 1000/4096 * 3V3 == 0V8
      //      k=4095;
      ADC_SoftwareStartConv(ADC1);
      k=adc_buffer[1]>>4; // adc[1] is dac0, 3 is dac 1, 5 is dac 2, 7 is dac 3 - we can organise this in adc.c
      // but still question of bleed of adc0 into adc3 - check if is vice versa? seems in software as changed when re-org
      
      // TEST setting k to ADC1
      //        value =(float)adc_buffer[SELX]/65536.0f; 
      //dacval[daccount]=0;//adc_buffer[daccount]>>4; // 12 bits for DAC
      //      dacval[daccount]=4095;
      DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
      j = DAC_GetDataOutputValue (DAC_Channel_1);
      //      delay();
      //      daccount++;
      //      if (daccount==1) daccount=0;
      //      GPIOB->ODR = 0b0000000000000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
      //      DAC_SetChannel1Data(DAC_Align_12b_R, 4095-k); // 1000/4096 * 3V3 == 0V8
      //      j = DAC_GetDataOutputValue (DAC_Channel_1);
