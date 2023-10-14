         case X: 
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=real[6]>>2; 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	    if (overlaid){
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=real[6]>>2; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);  // see older cases 9/10 TODO!
	      values[daccount]+=real[daccount]; 
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	      }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	  ///////////////////////////////////////////
	case 666: // speed test ONLY
	  GPIOC->BSRRH = 0b1110100000000000;		       
	  DAC_SetChannel1Data(DAC_Align_12b_R, val);
	  j = DAC_GetDataOutputValue (DAC_Channel_1);		
	  GPIOC->BSRRL=(daccount)<<13;
	  //	  CLEARDAC;
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	  if (val==0) val=4095;
	  else val=0;
	  }
	  break;

	  
	  ///////////////////////////
	case 666: // speed test ONLY 166.7Hz
	  GPIOC->BSRRH = 0b1110100000000000;		       
	  DAC_SetChannel1Data(DAC_Align_12b_R, val);
	  j = DAC_GetDataOutputValue (DAC_Channel_1);		
	  GPIOC->BSRRL=(daccount)<<13; // multiplex
	  //CLEARDAC; // why we remove this but is there on writedac - timing?
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	  if (val==0) val=4095;
	  else val=0;
	  }
	  //	  RESETT; // all resets... drops us to 15Hz so we lose 1/30th second... on full reset
	  //	  RESET0; // one reset... drops to 142Hz so not so bad... 
	  break;

	  
