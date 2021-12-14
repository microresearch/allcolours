const uint16_t logval[1024]  __attribute__ ((section (".flash"))) = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 37, 37, 37, 38, 38, 38, 39, 39, 39, 40, 40, 40, 41, 41, 41, 42, 42, 42, 43, 43, 43, 44, 44, 45, 45, 45, 46, 46, 46, 47, 47, 48, 48, 48, 49, 49, 50, 50, 51, 51, 51, 52, 52, 53, 53, 54, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66, 67, 67, 68, 68, 69, 69, 70, 71, 71, 72, 72, 73, 73, 74, 75, 75, 76, 77, 77, 78, 79, 79, 80, 81, 81, 82, 83, 83, 84, 85, 85, 86, 87, 87, 88, 89, 90, 90, 91, 92, 93, 93, 94, 95, 96, 97, 97, 98, 99, 100, 101, 101, 102, 103, 104, 105, 106, 107, 108, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 138, 139, 140, 141, 142, 143, 145, 146, 147, 148, 149, 151, 152, 153, 154, 156, 157, 158, 160, 161, 162, 164, 165, 166, 168, 169, 170, 172, 173, 175, 176, 178, 179, 180, 182, 183, 185, 186, 188, 190, 191, 193, 194, 196, 197, 199, 201, 202, 204, 206, 207, 209, 211, 213, 214, 216, 218, 220, 221, 223, 225, 227, 229, 231, 233, 235, 236, 238, 240, 242, 244, 246, 248, 250, 252, 255, 257, 259, 261, 263, 265, 267, 269, 272, 274, 276, 278, 281, 283, 285, 288, 290, 292, 295, 297, 300, 302, 305, 307, 310, 312, 315, 317, 320, 323, 325, 328, 331, 333, 336, 339, 342, 344, 347, 350, 353, 356, 359, 362, 365, 368, 371, 374, 377, 380, 383, 386, 389, 392, 396, 399, 402, 405, 409, 412, 415, 419, 422, 426, 429, 433, 436, 440, 443, 447, 451, 454, 458, 462, 466, 470, 473, 477, 481, 485, 489, 493, 497, 501, 505, 509, 514, 518, 522, 526, 531, 535, 539, 544, 548, 553, 557, 562, 566, 571, 576, 580, 585, 590, 595, 600, 605, 610, 615, 620, 625, 630, 635, 640, 645, 651, 656, 661, 667, 672, 678, 683, 689, 694, 700, 706, 712, 717, 723, 729, 735, 741, 747, 753, 760, 766, 772, 778, 785, 791, 798, 804, 811, 817, 824, 831, 838, 844, 851, 858, 865, 872, 879, 887, 894, 901, 909, 916, 924, 931, 939, 946, 954, 962, 970, 978, 986, 994, 1002, 1010, 1018, 1027, 1035, 1044, 1052, 1061, 1069, 1078, 1087, 1096, 1105, 1114, 1123, 1132, 1141, 1151, 1160, 1170, 1179, 1189, 1198, 1208, 1218, 1228, 1238, 1248, 1258, 1269, 1279, 1290, 1300, 1311, 1321, 1332, 1343, 1354, 1365, 1376, 1388, 1399, 1410, 1422, 1433, 1445, 1457, 1469, 1481, 1493, 1505, 1518, 1530, 1542, 1555, 1568, 1581, 1593, 1606, 1620, 1633, 1646, 1660, 1673, 1687, 1701, 1715, 1729, 1743, 1757, 1771, 1786, 1800, 1815, 1830, 1845, 1860, 1875, 1890, 1906, 1921, 1937, 1953, 1969, 1985, 2001, 2018, 2034, 2051, 2067, 2084, 2101, 2119, 2136, 2153, 2171, 2189, 2206, 2224, 2243, 2261, 2279, 2298, 2317, 2336, 2355, 2374, 2393, 2413, 2433, 2453, 2473, 2493, 2513, 2534, 2554, 2575, 2596, 2618, 2639, 2661, 2682, 2704, 2726, 2749, 2771, 2794, 2816, 2839, 2863, 2886, 2910, 2933, 2957, 2981, 3006, 3030, 3055, 3080, 3105, 3131, 3156, 3182, 3208, 3234, 3261, 3287, 3314, 3341, 3368, 3396, 3424, 3452, 3480, 3508, 3537, 3566, 3595, 3624, 3654, 3684, 3714, 3744, 3775, 3805, 3837, 3868, 3899, 3931, 3963, 3996, 4028, 4061, 4095};





/*
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
	delay(); // seems to work with delay

	if (!(GPIOB->IDR & (1<<6))) {
	  triggered[10]=1; // finger OFF is HIGH, finger ON is low
	  lasttriggered[10]=breaker[10];
	  breaker[10]=0;
	}
	else breaker[10]++;

	GPIOC->BSRRH=(1)<<6; //  LOW!

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	delay();
	
	if (triggered[10] && lasttriggered[10]>BRK8) { // 0 
	  mode^=1; // TEST
	}

	// for testing!
			
	GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
       	if (mode)     DAC_SetChannel1Data(DAC_Align_12b_R, 2048); // 1000/4096 * 3V3 == 0V8
	else     DAC_SetChannel1Data(DAC_Align_12b_R, 0); // 1000/4096 * 3V3 == 0V8  // FINGER DOWN!
	j = DAC_GetDataOutputValue (DAC_Channel_1);
	GPIOC->BSRRL=(daccount)<<13; //  write DAC bits
    	    daccount++;
	    if (daccount==8) {
	      daccount=0;
	      count++;
	      	    }
	
*/



GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
	delay(); // seems to work with delay

	trigd=0;
	for (j=0;j<8;j++){
	  if (!(GPIOB->IDR & (1<<6))) trigd++; // finger OFF is HIGH, finger ON is low
	//	else trigd=1; // finger on
		}
		if (trigd>3) trigd=1;
	
	GPIOC->BSRRH=(1)<<6; //  LOW!

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	delay();

	if (trigd==1 && triggered[10]==0) triggered[10]=1;
	
	if (!trigd && triggered[10]==1) breaker[10]++;  // finger OFF
	if (trigd && triggered[10]==1) breaker[10]=0; // finger ON
	
	if (breaker[10]>BRK8) { // 0 
	  breaker[10]=0;
	  triggered[10]=0;
	  mode+=1;
	  if (mode>=MAXMODES) mode=0;
	  //	  	  mode^=1; // TEST
	}

	// for testing!
	/*		
	GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
       	if (mode)     DAC_SetChannel1Data(DAC_Align_12b_R, 2048); // 1000/4096 * 3V3 == 0V8
	else     DAC_SetChannel1Data(DAC_Align_12b_R, 0); // 1000/4096 * 3V3 == 0V8  // FINGER DOWN!
	j = DAC_GetDataOutputValue (DAC_Channel_1);
	GPIOC->BSRRL=(daccount)<<13; //  write DAC bits
    	    daccount++;
	    if (daccount==8) {
	      daccount=0;
	      count++;
	      	    }
	*/


/////////////////////// toggle template


      // toggle PC6 to send high trigger and read finger
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
	delay(); // seems to work with delay
      
            if ((GPIOB->IDR & (1<<8))) trigd=1; // finger on - low out = high in
            else trigd=0; // finger off
	    
	    GPIOC->BSRRH=(1)<<6; //  LOW!

	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	    //	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_Init(GPIOC, &GPIO_InitStructure);
	    delay();

	    // how to get this as toggle!
	    
	    if (trigd==1 && triggered[0]==0) triggered[0]=1;

	    if (!trigd && triggered[0]==1) breaker[0]++;  // finger off
           if (trigd && triggered[0]==1) breaker[0]=0; // finger on or 50hz

	    if (breaker[0]>BRK8) { // 0 
	      //	      rec^=1;
	      frozen[0]^=1; // test code 30/09/2021
	      breaker[0]=0;
	      triggered[0]=0;
	    }


///////////////////////////////



case 1: // basic mode 0 with speed also decreasing
  
	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;
      play_cnt[1]=0;
      play_cnt[2]=0;
      play_cnt[3]=0;
      play_cnt[4]=0;
      play_cnt[5]=0;
      play_cnt[6]=0;
      play_cnt[7]=0;
    }

    values[daccount]=(recordings[daccount][play_cnt[daccount]]) & 4095;  // ignore top bits
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>4); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>127) speed=127;
      speed=128-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
    break; // mode 1

    case 2: // 2 - basic mode 0 with overlay as midpoint thing - what of speed?
	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;
      play_cnt[1]=0;
      play_cnt[2]=0;
      play_cnt[3]=0;
      play_cnt[4]=0;
      play_cnt[5]=0;
      play_cnt[6]=0;
      play_cnt[7]=0;
    }

    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      //      values[daccount]+=real[daccount]; // to take to the midpoint so 4096/2=2048 is mid
      midder=values[daccount]+real[daccount]-2048;     
      if (midder<0) midder=0;
      if (midder>4095) midder=4095;
      values[daccount]=midder;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
    break;// mode 2      

    case 3: // 3 - basic mode 0 with overlay as modulo (so these are all the same) - what of speed?
	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;
      play_cnt[1]=0;
      play_cnt[2]=0;
      play_cnt[3]=0;
      play_cnt[4]=0;
      play_cnt[5]=0;
      play_cnt[6]=0;
      play_cnt[7]=0;
    }

    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      values[daccount]=values[daccount]%4096;
      //     if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
    break; // mode 3      

    case 4: // RECCCC
      /* with freezers as recording, stopping recording the additions which
	 then play back alongside temp additions (and as above variations -> speed, midpoint, modulo)
	 record sets back to original with freezing as possible
	 play returns to no playback but can still record additions ???
      */
	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
	if (frozen[daccount]==0 || play==1) {
	  ADC_SoftwareStartConv(ADC1);
	  //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	  real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	}

  if (play){
    if (lastplay==0) {     // is it a new play?
      // we need to undo freezers
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; frozen[0]=0; added[0]=0;
      play_cnt[1]=0; frozen[1]=0; added[1]=0;
      play_cnt[2]=0; frozen[2]=0; added[2]=0;
      play_cnt[3]=0; frozen[3]=0; added[3]=0;
      play_cnt[4]=0; frozen[4]=0; added[4]=0;
      play_cnt[5]=0; frozen[5]=0; added[5]=0;
      play_cnt[6]=0; frozen[6]=0; added[6]=0;
      play_cnt[7]=0; frozen[7]=0; added[7]=0;
    }

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits;

    // in play if frozen then add the value to the recording
    // otherwise nothing - but only do this once even if we are still here....
    if (frozen[daccount] && added[daccount]==0){
      recordings[daccount][play_cnt[daccount]]+=real[daccount];
      if (recordings[daccount][play_cnt[daccount]]>4095) recordings[daccount][play_cnt[daccount]]=4095;
      added[daccount]=1;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    added[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  // if we come out of recording we need to undo the freezers
  else {
    if (lastrec==1) {
      frozen[0]=0;
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
    lastrec=0;
  }
  } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
    break; // mode 4  

    case 5: // as RECC overlay but with speed lowered
      /* with freezers as recording, stopping recording the additions which
	 then play back alongside temp additions (and as above variations -> speed, midpoint, modulo)
	 record sets back to original with freezing as possible
	 play returns to no playback but can still record additions ???
      */
	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
	if (frozen[daccount]==0 || play==1) {
	  ADC_SoftwareStartConv(ADC1);
	  //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	  real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	}

  if (play){
    if (lastplay==0) {     // is it a new play?
      // we need to undo freezers
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; frozen[0]=0; added[0]=0;
      play_cnt[1]=0; frozen[1]=0; added[1]=0;
      play_cnt[2]=0; frozen[2]=0; added[2]=0;
      play_cnt[3]=0; frozen[3]=0; added[3]=0;
      play_cnt[4]=0; frozen[4]=0; added[4]=0;
      play_cnt[5]=0; frozen[5]=0; added[5]=0;
      play_cnt[6]=0; frozen[6]=0; added[6]=0;
      play_cnt[7]=0; frozen[7]=0; added[7]=0;
    }

        if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits;

    // in play if frozen then add the value to the recording
    // otherwise nothing - but only do this once even if we are still here....
    if (frozen[daccount] && added[daccount]==0){
      recordings[daccount][play_cnt[daccount]]+=real[daccount];
      if (recordings[daccount][play_cnt[daccount]]>4095) recordings[daccount][play_cnt[daccount]]=4095;
      added[daccount]=1;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    added[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  // if we come out of recording we need to undo the freezers
  else {
    if (lastrec==1) {
      frozen[0]=0;
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
    lastrec=0;
  }
  } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>4); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>127) speed=127;
      speed=128-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
      break; // mode 5

    case 6: // as mode 4 (regular speed) with overlay as midpoint
      /* with freezers as recording, stopping recording the additions which
	 then play back alongside temp additions (and as above variations -> speed, midpoint, modulo)
	 record sets back to original with freezing as possible
	 play returns to no playback but can still record additions ???
      */
	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
	if (frozen[daccount]==0 || play==1) {
	  ADC_SoftwareStartConv(ADC1);
	  //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	  real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	}

  if (play){
    if (lastplay==0) {     // is it a new play?
      // we need to undo freezers
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; frozen[0]=0; added[0]=0;
      play_cnt[1]=0; frozen[1]=0; added[1]=0;
      play_cnt[2]=0; frozen[2]=0; added[2]=0;
      play_cnt[3]=0; frozen[3]=0; added[3]=0;
      play_cnt[4]=0; frozen[4]=0; added[4]=0;
      play_cnt[5]=0; frozen[5]=0; added[5]=0;
      play_cnt[6]=0; frozen[6]=0; added[6]=0;
      play_cnt[7]=0; frozen[7]=0; added[7]=0;
    }

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095; // ignore top bits

    // in play if frozen then add the value to the recording
    // otherwise nothing - but only do this once even if we are still here....
    if (frozen[daccount] && added[daccount]==0){
      //      recordings[daccount][play_cnt[daccount]]+=real[daccount];

      midder=recordings[daccount][play_cnt[daccount]]+real[daccount]-2048;     
      if (midder<0) midder=0;
      if (midder>4095) midder=4095;
      recordings[daccount][play_cnt[daccount]]=midder;
      
      //      if (recordings[daccount][play_cnt[daccount]]>4095) recordings[daccount][play_cnt[daccount]]=4095;
      added[daccount]=1;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    added[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  // if we come out of recording we need to undo the freezers
  else {
    if (lastrec==1) {
      frozen[0]=0;
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
    lastrec=0;
  }
  } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      midder=values[daccount]+real[daccount]-2048;     
      if (midder<0) midder=0;
      if (midder>4095) midder=4095;
      values[daccount]=midder;
      //      values[daccount]+=real[daccount];
      //      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
      break; // mode 6

    case 7: // as 4 but with modulo
      /* with freezers as recording, stopping recording the additions which
	 then play back alongside temp additions (and as above variations -> speed, midpoint, modulo)
	 record sets back to original with freezing as possible
	 play returns to no playback but can still record additions ???
      */
	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
	if (frozen[daccount]==0 || play==1) {
	  ADC_SoftwareStartConv(ADC1);
	  //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	  real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	}

  if (play){
    if (lastplay==0) {     // is it a new play?
      // we need to undo freezers
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; frozen[0]=0; added[0]=0;
      play_cnt[1]=0; frozen[1]=0; added[1]=0;
      play_cnt[2]=0; frozen[2]=0; added[2]=0;
      play_cnt[3]=0; frozen[3]=0; added[3]=0;
      play_cnt[4]=0; frozen[4]=0; added[4]=0;
      play_cnt[5]=0; frozen[5]=0; added[5]=0;
      play_cnt[6]=0; frozen[6]=0; added[6]=0;
      play_cnt[7]=0; frozen[7]=0; added[7]=0;
    }

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095; // ignore top bits;

    // in play if frozen then add the value to the recording
    // otherwise nothing - but only do this once even if we are still here....
    if (frozen[daccount] && added[daccount]==0){
      recordings[daccount][play_cnt[daccount]]+=real[daccount];
      recordings[daccount][play_cnt[daccount]]=recordings[daccount][play_cnt[daccount]]%4096;
      //            values[daccount]+=real[daccount];
      //      values[daccount]=values[daccount]%4096;
      added[daccount]=1;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    added[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  // if we come out of recording we need to undo the freezers
  else {
    if (lastrec==1) {
      frozen[0]=0;
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
    lastrec=0;
  }
  } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      //      values[daccount]+=real[daccount];
      //      if (values[daccount]>4095) values[daccount]=4095;
      values[daccount]+=real[daccount];
      values[daccount]=values[daccount]%4096;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
    break; // mode 7

    case 8:
      ///8 - press freeze and plays back for that section the last x seconds (so always recording) - how do we determine the x seconds? (next freeze sets that?)
      //       [ but how does this operate when we enter this mode from nothing and freeze - start recording on entry and max will be length]
      // question is if we loop - so continue recording in a loop even if we play back...
      // what does rec do : (play deals with playback)
      // rec button could reset everything
      
      // if we just entered start recording and continue
      if (lastmode!=mode){ // assign lastmode in other modes
	rec=1;
	starter[0]=0; ender[0]=7000;	
	starter[1]=0; ender[1]=7000;	
	starter[2]=0; ender[2]=7000;	
	starter[3]=0; ender[3]=7000;	
	starter[4]=0; ender[4]=7000;	
	starter[5]=0; ender[5]=7000;	
	starter[6]=0; ender[6]=7000;	
	starter[7]=0; ender[7]=7000;	
      }
	/////// TOGGLING for freezers	
      // in this case freezer=1 sets start point, 0 sets end point for each one... in starter and ender...
      // for playback

      if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  if (frozen[7]==1) {
	    starter[7]=rec_cnt[7];
	    play_cnt[7]=rec_cnt[7];
	  }
	  else ender[7]=rec_cnt[7];
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	  if (frozen[daccount]==1) {
	    starter[daccount]=rec_cnt[daccount];
	    play_cnt[daccount]=rec_cnt[daccount];
	  }
	  else ender[daccount]=rec_cnt[daccount];
	  breaker[daccount]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0) breaker[daccount]++; 

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
	// this runs always at full speed!
	
      ADC_SoftwareStartConv(ADC1);
      real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left

  if (play){

    values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>ender[daccount]) play_cnt[daccount]=starter[daccount];
    }
  } // if play

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are always recording 

    recordings[daccount][rec_cnt[daccount]]=real[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs

      // in this case what does rec do?
      
      /*            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
	if (triggered[8]==1 && lasttriggered[8]==0) { // new trigger
	  tgr_cnt[8]=0;
	  lasttriggered[8]=1;
	}
	
	if (lasttriggered[8]==1) 	tgr_cnt[8]++;

	if (tgr_cnt[8]>TRG8){
	  triggered[8]=0;
	  lasttriggered[8]=0;
	}
      */
	//play	
      
    	if (!(GPIOB->IDR & (1<<2)) && triggered[9]==0 && breaker[9]>BRK8) {
	  triggered[9]=1;
	  play^=1;
	  breaker[9]=0;
	}

	if ( (GPIOB->IDR & (1<<2)) && triggered[9]==0) breaker[9]++; 
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      	
	//    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
	//    if (rec) play=0;
    }
    lastmode=8;      
      break; // mode 8

    case 20:
      /* 20 - each voltage changes speed of that specific playback section and
	 we use freeze, unfreeze to record those changes, overlays also only
	 for VCA and for speed. speeds for each sample are set in top 5 or 6 bits?
	 
	 - so is speed for VCA and voltage for each section
	 - rec and non-playback is all as usual (freeze is freeze)
	 - playback mode - speed changes for each section (overlay also), freeze to rec, unfreeze to stop rec...

	 - speed say is 1-64 so 5 bits... (always plus one in case there are zeroes)

      */

	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  recsp[7]=frozen[7];
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	  recsp[daccount]=frozen[daccount];
	  breaker[daccount]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0) breaker[daccount]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0 || play==1) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; recsp[0]=0;
      play_cnt[1]=0; recsp[1]=0;
      play_cnt[2]=0; recsp[2]=0;
      play_cnt[3]=0; recsp[3]=0;
      play_cnt[4]=0; recsp[4]=0;
      play_cnt[5]=0; recsp[5]=0;
      play_cnt[6]=0; recsp[6]=0;
      play_cnt[7]=0; recsp[7]=0;
    } // lastplay

    uint16_t speeder[8]={4,5,6,7,4,5,6,7};
    // if we are recording speed then do it here - we need to know what pairs have what?
    // ie. which is control mapping to which - 4,5,6,7 -> 0,1,2,3 I guess - test this!
      ADC_SoftwareStartConv(ADC1);
      // speed is for 2x daccounts - how to handle...
      speed=(adc_buffer[speeder[daccount]]>>5); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>64) speed=64;
      speed=64-(speed); //4 bits=16 256/16=

    if (recsp[daccount]) {
      recordings[daccount][play_cnt[daccount]]=(recordings[daccount][play_cnt[daccount]]&4095)+(speed<<10); // top 5 bits
     }
    else { // we have speed already    
    speed+=((recordings[daccount][play_cnt[daccount]])>>10)+1; // top 5 bits - question of overlay?
    }
    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else {
    lastplay=0;
    if (lastplay==1) { // we just left play
      frozen[0]=0; // we don't want freezers still on...
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
  }
    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      if (daccount<4) {
	values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
      }
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      /*
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      */
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
            
    break; // mode 20

    // THIS ONE TO TEST
    
    case 12:// - freezers reverse the last section for playback, and can overlay (no freeze allowed tho) 
      //[ so in rec and non-playback freeze also freezes]
	/////// TOGGLING for freezers	- use recsp for the reverse or not
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  if (play==0) frozen[7]^=1;
	  else recsp[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	  if (play==0) frozen[daccount]^=1;
	  else recsp[daccount]^=1;
	  breaker[daccount]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0) breaker[daccount]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0 || play==1) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<2;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    if (real[daccount]>4095) real[daccount]=4095;
    //    real[daccount]=4095;
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; recsp[0]=0;
      play_cnt[1]=0; recsp[1]=0;
      play_cnt[2]=0; recsp[2]=0;
      play_cnt[3]=0; recsp[3]=0;
      play_cnt[4]=0; recsp[4]=0;
      play_cnt[5]=0; recsp[5]=0;
      play_cnt[6]=0; recsp[6]=0;
      play_cnt[7]=0; recsp[7]=0;
    }

    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095; // ignore top bits
    
    if ((count%speed)==0){ // speed goes from 1 to X what
      if (recsp[daccount]==0) play_cnt[daccount]++;
      else {
	if (play_cnt[daccount]==0) play_cnt[daccount]= rec_cnt[daccount]+1;
	play_cnt[daccount]--;
	    }	
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else
    {
    lastplay=0;
    /*    if (lastplay==1) { // we just left play
      frozen[0]=0; // we don't want freezers still on...
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
      }*/
    }
    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }
      break; // mode 12

    case 16: // freezers free/detach that section or start playback again in that section... again with overlays (what then does play button do?)
      //[ play button plays them all!] - so play starts off the process
      // in rec or no-play freeze works as always
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  if (play==0) frozen[7]^=1;
	  else recsp[7]^=1; // so recsp is for on off of individual plays
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

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
	  if (play==0) frozen[daccount]^=1;
	  else recsp[daccount]^=1;
	  breaker[daccount]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0) breaker[daccount]++; 

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
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0 || play==1) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<2;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    if (real[daccount]>4095) real[daccount]=4095;
    //    real[daccount]=4095;
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; recsp[0]=0;
      play_cnt[1]=0; recsp[1]=0;
      play_cnt[2]=0; recsp[2]=0;
      play_cnt[3]=0; recsp[3]=0;
      play_cnt[4]=0; recsp[4]=0;
      play_cnt[5]=0; recsp[5]=0;
      play_cnt[6]=0; recsp[6]=0;
      play_cnt[7]=0; recsp[7]=0;
    }
    // if recsp==1 then we detach that one and stop playback
    if (recsp[daccount]==0){
    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095; // ignore top bits    
    if ((count%speed)==0){ // speed goes from 1 to X what
      play_cnt[daccount]++;
      if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
    }
    else values[daccount]=0; // this is what is added
  } // if play
  else
    {
    lastplay=0;
    /*    if (lastplay==1) { // we just left play
      frozen[0]=0; // we don't want freezers still on...
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
      }*/
    }
    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
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
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    }      

      break; // mode 16

    case 23: // mode to test freeze timings on middle and freeze pads // BRK8
      // testing new freeze/trigger code on FR1

      // pc6 is new trigger OUT pin!
      
      
   GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    //    values[daccount]=4095; // TESTY
   //   if (frozen[daccount]) values[daccount]=4095;
   //   if (rec) values[daccount]=4095;
   //   else values[daccount]=0;
      if (rec){
    ADC_SoftwareStartConv(ADC1);
                values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
     values[daccount]=adc_buffer[daccount];// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
       if (values[daccount]>4095) values[daccount]=4095;
          }
   
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits


    
    //    daccount++;
    //    if (daccount==8) {
      daccount=4;
      //      count++;

      // now we attached 1->15 to outside of first - 1->8 - attached from r49 right hand side but how to test bleed...
      // test toggling of 1->15
      // with this code and no pullup seems to work as we handle both cases...

      // toggle PC6 to send high trigger and read finger
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
      //      delay();
      
            if ((GPIOB->IDR & (1<<8))) trigd=1; // finger on - low out = high in
            else trigd=0; // finger off
	    
	    GPIOB->BSRRH=(1)<<6; //  LOW!

            if (!(GPIOB->IDR & (1<<8))) trigd=1; // finger on - low out = high in 0 this is rec
            else trigd=0; // finger off

	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	    //	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_Init(GPIOC, &GPIO_InitStructure);
	    delay();

	    // how to get this as toggle!
	    
	    if (trigd==1 && triggered[0]==0) triggered[0]=1;

	    if (!trigd && triggered[0]==1) breaker[0]++;  // finger off
           if (trigd && triggered[0]==1) breaker[0]=0; // finger on or 50hz

	    if (breaker[8]>BRK8) { // 0 
	      rec^=1;
	      breaker[8]=0;
	      triggered[8]=0;
	    }

	      
	    

      	  
      // test rec button - works fine with TRG8 as 8 and BRK8 as 60!
      /*      
//      if ((GPIOB->IDR & (1<<8))) {
 //	triggered[8]=1;
//      }

      if (!(GPIOB->IDR & (1<<8)) && triggered[8]==1) breaker[8]++;  // finger off
      //      if ( (GPIOB->IDR & (1<<8)) && triggered[8]==1) breaker[8]=0; // finger on or 50hz

      if (breaker[8]>BRK8) { // 0 
	rec^=1;
	breaker[8]=0;
	triggered[8]=0;
	}*/
      //      delay();
      //      GPIOB->BSRRH=(1)<<15; //  LOW!
      

      /*
	
	if (triggered[8]==1 && lasttriggered[8]==0) { // new trigger
	  tgr_cnt[8]=0;
	  lasttriggered[8]=1;
	}
	
		if (lasttriggered[8]==1) 	tgr_cnt[8]++;

	if (tgr_cnt[8]>TRG8){
	  triggered[8]=0;
	  lasttriggered[8]=0;
	  }
	*/      
	    //  }
    break; /// end of TEST button mode 23      



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
