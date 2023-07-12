///new layout

         case X: 
	    /*
	    */
	  FREEZERS;
          REALADC;
	  // 4 states: play, rec, overlay, nada
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
	  }
	  
	  if ((!overlaid) && play && ender[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } 
	  
	  ///// recordings
	  if ((!overlaid) && rec){ // we are recording // on entry but not 2nd time
	      LASTREC; // reset all only on entering
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
	    else lastrec=0;
	    
	    // overlay
	    if (overlaid){
	      LSTRECPLAY;
	      lastmode=1;
	      // playback and record overlap
	      // TODO: different kinds of overlay
	      speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);  // see older cases 9/10 TODO!
	      values[daccount]+=real[daccount]; // could depend on freeze
	      if (values[daccount]>4095) values[daccount]=4095;
	      // try different versions for minormodes? also see 9/10
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	      }
	    }
	    else llrec=0;
	    
	    // nada
	    if (rec==0 && play==0 && overlaid==0) {
	      values[daccount]=(real[daccount]);
	      lastmode=0;
	    }
	    break; ///// 



// basic layout of case
          case X: 
	  FREEZERS;
          REALADC;
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	  break; ///// 


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

	  
