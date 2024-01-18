// list code discard 21/11

#define MAXFING 120

typedef struct listy_ { 
  uint32_t start[MAXFING];  
  uint32_t end[MAXFING];
  uint32_t glstart[MAXFING];  
  uint32_t glend[MAXFING];
} hands;

static hands fingers[8];
static uint32_t howmanyfingers[8]={0,0,0,0, 0,0,0,0};

inline static void remove_reclist(uint32_t count){
  uint32_t x;
  for (x=0;x<howmanyfingers[count];x++){
    if (x>0) {
      fingers[count].start[x-1]=fingers[count].start[x];
      fingers[count].glstart[x-1]=fingers[count].glstart[x];
      fingers[count].end[x-1]=fingers[count].end[x];
      fingers[count].end[x-1]=fingers[count].glend[x];
    }
  }
}


if (overlap[daccount]){ // we hit the end so start removing as we overrun them
		if (howmanyfingers[daccount]>0 && rec_cnt[daccount]>fingers[daccount].end[0]) {
		  remove_reclist(daccount);
		}
	      }
	      if (overlap[daccount]&&howmanyfingers[daccount]==0) fingers[daccount].end[howmanyfingers[daccount]]=MAXREC;
	      else fingers[daccount].end[howmanyfingers[daccount]]=rec_cnt[daccount]; 
	      fingers[daccount].glend[howmanyfingers[daccount]]=global_time;

// and in macro reset:
      if (howmanyfingers[daccount]>0) howmanyfingers[daccount]++;	\
      if (howmanyfingers[daccount]>MAXFING) howmanyfingers[daccount]=0;	\
      fingers[daccount].glstart[howmanyfingers[daccount]]=global_time;	\
      fingers[daccount].start[howmanyfingers[daccount]]=rec_cnt[daccount];	
\

// for 78// now 0
/*
	     *Instead of new mode 77: rec started during play is overlay (play started during rec is also overlay?)
	     so we have 4 states:
	     - NADA
	     - rec/resets start of reccount, stop
	     - play
	     - rec+play: OVERLAY! stop rec: stops overlay, carries on playing// stop play: into NADA... (so are there 2 ways out?)
	     // or should stop play just revert to rec with no overlay// and reset on entry // but there is no entry as we are there, so carries on/extends.. ?
	     // *question of stop play returning to bare reset rec - which it shouldn't*

	     TODO:
	     - add doubling up of rec...DONE
	     - implement all minormodes - see new_modes.org
	    */



case 0: // 6/6/2023 - now with minor mode adjustments
	  // 21/6/2023 - we shifted these <<1 to make way for sensitivity
	  // 24/6 - get rid of sensitivity
	  minormode=0;
	  REALADC;
	  FREEZERS;

	  if (play==0) {
	  if (frozen[daccount]==0) lastvalue[daccount]=real[daccount];
	  else real[daccount]=lastvalue[daccount];// frozen
	  }
	  
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    //	    if (!(minormode&16)) {
	      LASTPLAY;
	      //	    }
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;

	    if (minormode&4) { // speed as real or recorded
	      if (minormode&64){ // freeze just freezes speed and not real
		if (frozen[6]==0) {
		  lastspeedd=(lastspeed>>2)+(real[6]>>2);
		  if (lastspeedd>1023) lastspeedd=1023;
	      }
	      }
		else { // freeze freezes real only and not speed
		if (frozen[6]==0) {
		  lastvalue[6]=real[6];
		}
		else {
		  real[6]=lastvalue[6];
		  lastspeedd=(lastspeed>>2)+(real[6]>>2);
		  if (lastspeedd>1023) lastspeedd=1023;
		}
		}
		speed=lastspeedd;
	    } // &4
	  else {
	    if (minormode&64){ // freeze just freezes speed and not real
	      if (frozen[6]==0) lastspeedd=real[6];
	    }
	    else // freeze freezes real only and not speed
	      {
		if (frozen[6]==0) {
		  lastvalue[6]=real[6];
		  lastspeedd=real[6];
		}
		else {
		  lastspeedd=reall[6];
		  real[6]=lastvalue[6];
		}
	      }
	      speed=lastspeedd>>2; // 24/4 // 25/4 now 12 to 10 bits
	  }

	    //	    minormode=64;
	    if (minormode&128){	    // freeze stops playback
	    if (frozen[daccount]==0) {
	      if (minormode&2) values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    }
	    //	    else values[daccount]=lastvalue[daccount]; // NON?
	    } // &64
	    else { // freeze just holds overlap
	      if (minormode&2) values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);

	      if (frozen[daccount]==0) lastvalue[daccount]=real[daccount];
	      else real[daccount]=lastvalue[daccount];// frozen
	    }
	    
	    if (daccount==6) lastspeed=values[6];

	    // types of overlap: where we just overlap if is above, where we add...
	    
	    	    values[daccount]+=real[daccount];
	    //	    if (minormode&8){
	    //	    	    values[daccount]=values[daccount]%4096;
	    //	    }
	    //	    else {
	    	    if (values[daccount]>4095) values[daccount]=4095;
		    //	    values[daccount]=4095;
	      //	    }	    
	  } // if play // end playback
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]); 
	    //	    values[daccount]=4095;
	  } 
    
	  ///// recordings
	    if (rec){ // we are recording
	      //     if (!(minormode&32)) {
	      LASTREC; // reset all
	      //	      }
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

	  ////////////////////////////////////////////
	  // adding 6/6 - but these will need to be changed for minormode scheme

	  //	  2) overlay on next rec only (with/without reset - so without reset overlay would carry on from end of last rec...)
	  //	       if no reset then this changes length of rec/play
	  // but to overlay we need to play
          case 1: 
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY; // reset bits
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]); // speed bits
	    values[daccount]+=real[daccount]; // overlap bits
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset bits // *add no-reset opts*
	      if (modechanged) {
		modechanged=0;
		// rec all new until we stop first one
		first=1;
	      }		
	      if (first==1) recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      else {
		recordings[daccount][rec_cnt[daccount]]+=real[daccount];
		if (recordings[daccount][rec_cnt[daccount]]>4095) recordings[daccount][rec_cnt[daccount]]=4095;
		// also overlay bits but we need to play
		speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
		values[daccount]=recordings[daccount][rec_cnt[daccount]]; // no speed
	      }
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      first=0;
	    }       
	  break; ///// 

	  /// 7/6
	case 2: // FIXED speed - add in other modifiers TODO
	  // fixed speeds and slower fixed rec//// modifiers used here for rec and speed dividers
	  // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, no speed
	  // dividers can be out of sync also
	  // interesting to add in rec overlay
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	    tmp=minormode&3;
o
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    //	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    values[daccount]=speedsample(0.0625, rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]=speedsample(speeddivisor[tmp], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  recsp[daccount]++;
	  recspeed=speeddiv[tmp]; // TESTY was 16 fixed 1/16 speed=0.0625
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      if (recsp[daccount]>=recspeed){
		recsp[daccount]=0;
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 3: //3) how to set length of play - at moment just plays until recend... freeze sets end of play... // but next play will reset that to recend
	  ///this will need different modifiers for freeze almost
	  // Test start of play... start then end... 
	  // modifier 64 for overlay/rec
	  // add modifiers also to seperate recspeed and rec voltage on [6] - so one is full length or not
	  FREEZERS;
          REALADC;
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    if (ender[daccount]>=starter[daccount]) lengg=ender[daccount]-starter[daccount];
	    else lengg=(rec_cnt[daccount]-starter[daccount])+ender[daccount]; // wrap
	    if (lengg<1) lengg=1;
	    values[daccount]=speedsamplestart(logfast[speed], lengg, starter[daccount], daccount, recordings[daccount]);

	    if (frozen[daccount]){
	      // we need two states for start and end setting
	      if (firsty[daccount]==0) {
		starter[daccount]=(int)(play_cnt[daccount]);
		firsty[daccount]=1;
		}
	    } // unfrozen
	    else if (firsty[daccount]==1)
	      {
		ender[daccount]=(int)(play_cnt[daccount]);
		firsty[daccount]=0;
	      }

	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	    //	    minormode=64; // TESTY!
	    tmp=((int)play_cnt[daccount])+starter[daccount];
	    if (tmp>rec_cnt[daccount]) tmp=rec_cnt[daccount];
	    if (minormode&64) recordings[daccount][tmp]=values[daccount]; // record overlay! // that minormode might change!!! TESTY!
	    
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
	      starter[daccount]=0;
	      ender[daccount]=rec_cnt[daccount];
	      if (rec_cnt[daccount]>MAXREC) {
		ender[daccount]=MAXREC;
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }      
	  break; ///// 
	  

	  //*TODO: freeze as additive. holds level on next freeze rather than releasing - is this more of a minimode: =freeze behaviours*
	  // not really additive but just not releasing
	  // but we do need 
	case 4: // need to do for playback but just test concept here
	  // works ok but is quite different 
	  FREEZERS;
          REALADC;

	  /*
	    2 bits: types of freeze:
	    - regular: hold release
	    - toggle lastvalue always as below
	    + extra bit for overlap/no overlap
	   */
	  
	  if (play==0){
	    	  if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
		  else {
		    if (real[daccount]<lastvalue[daccount])		    real[daccount]=lastvalue[daccount];// overlap option as minor mode
		    //		    real[daccount]=lastvalue[daccount];// no overlap
	  }
	  }
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

	  //	  *looped rec/overlay: or rec starts that loop/play, and stops, and play just plays back/no recorded overlay, how do we reset? we start rec again*
	  //what do we do about length tho? stops on rec off
	  // or more rec is regular rec. rec off is overlay same size, play is just play
          case 5: 
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
	  else { // no play so in looppy mode
	    lastplay=0;
	    play=0;
	    
	    ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      // no overlay
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec==0
	    else { // no reset and we keep on overlaying up to lastlastrec or MAXREC is overlap
	      lastrec=0;
	      if (overlap[daccount]) ender[daccount]=MAXREC;
	      // TODO: different kinds of overlay
	      speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]); 
	      values[daccount]+=real[daccount];
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	      }
	    }
	  }
	  break; ///// 

	  ////////////////////////////////////////////
	  ///*TODO: draft basic case 0 with state dependent minormodes*
	  // and basic modes on no rec/play
	case 6: // 6/6/2023 - now with minor mode adjustments
	  // 21/6/2023 - we shifted these <<1 to make way for sensitivity
	  REALADC;
	  FREEZERS;

	  //	  baseminor=4; // TESTED fine
	    // deal with types of freezer in basemode bits 2 and 4
	    if (baseminor&2){ // hold and release
	      if (baseminor&4){ //overlap
		if (freezetoggle[daccount]) {
		  lastvalue[daccount]=real[daccount];
		  freezetoggle[daccount]=0;
		}
		else {
		  if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];// overlap option as minor mode
		}
	      } // &4
	      else {
		if (freezetoggle[daccount]) {
		  lastvalue[daccount]=real[daccount];
		  freezetoggle[daccount]=0;
		}
		else {
		  real[daccount]=lastvalue[daccount];// frozen
		}		  
	      }
	    } //&2
	    else {
	      if (baseminor&4){
		if (frozen[daccount]==0) lastvalue[daccount]=real[daccount];
		else {
		  if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];// overlap option as minor mode
		}
	      } //&4
	      else {
		if (frozen[daccount]==0) lastvalue[daccount]=real[daccount];
		else real[daccount]=lastvalue[daccount];// frozen
	      }
	    }
	
	  
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    if (!(playminor&1)) { //reset
	      LASTPLAY;
	    }
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;

	    if (playminor&4) { // speed as recorded
	      if (playminor&16){ // freeze just freezes speed and not real // add in freezes
		if (frozen[6]==0) {
		  lastspeedd=(lastspeed>>2)+(real[6]>>2); // lastspeed is recorded
		  if (lastspeedd>1023) lastspeedd=1023;
		}
		real[6]=reall[6];
	      }
	      else { // freeze freezes real only and not speed
		// we already freeze real so just keep speed running
		  lastspeedd=(lastspeed>>2)+(reall[6]>>2); // lastspeed is recorded
		  if (lastspeedd>1023) lastspeedd=1023;
	      }
	    } // &4
	    else { // speed as real
	      if (playminor&16){ // freeze just freezes speed and not real // add in freezes
 		if (frozen[6]==0) {		
		lastspeedd=reall[6]>>2;
		}
		real[6]=reall[6];
	      }
	      else // freeze freezes real only and not speed
		{
		  // we already freeze real so just keep speed running
		  lastspeedd=reall[6]>>2;
		}
	    }
	    
	    speed=lastspeedd; 
	    
	    //	    playminor=64;
	    if (playminor&32){	    // freeze stops playback
	      if (frozen[daccount]==0) {
		if (playminor&2) values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
		else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      }
	      real[daccount]=reall[daccount]; // no freeze there...
	    } // &32
	    else { // freeze just holds overlap 
	      if (playminor&2) values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      // we already have freeze above
	    }
	    
	    if (daccount==6) lastspeed=values[6];

	    values[daccount]+=real[daccount];
	    if (playminor&8){
	      values[daccount]=values[daccount]%4096;
	    }
	    else {
	      if (values[daccount]>4095) values[daccount]=4095;
	    }	    
	  } // if play // end playback // NO PLAYBACK
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]); 
	  } 
    
	  ///// recordings // deal with speed
	  tmp=recminor&3;
	  recsp[daccount]++;
	  recspeed=speeddiv[tmp]; // TESTY was 16 fixed 1/16 speed=0.0625

	  if (rec){ // we are recording
	      if (!(recminor&1)) {
	      LASTREC; // reset all
	      }
	      if (recsp[daccount]>recspeed){
		recsp[daccount]=0;
		recordings[daccount][rec_cnt[daccount]]=real[daccount];
		rec_cnt[daccount]++;
		if (rec_cnt[daccount]>MAXREC) {
		  rec_cnt[daccount]=0;
		  overlap[daccount]=1;
		}
	    } 
	  } // if rec // NO RECORDING
	    else {
	      lastrec=0;
	    }
	    break; ///// 

	  ////////////////////////////////////////////
	case 7: // new base test mode
	  //- play freezes = regular voltage freeze as above, stop play and overlays, freeze play and overlays 

	  REALADC;
	  FREEZERS;

	  if (play==0){
	  if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	  }
	  
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	      LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    speed=0;
	    //	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);

	    // 
	    // options for freezes and overlays:
	    // -stop/start playback and different overlays
	    /*	    if (frozen[daccount]==0) { // means we need to unfreeze when we enter or is no play
		values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      }
	    */
	    // -toggle/hold playback voltage and different overlays
	    
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    /*
	    if (freezetoggle[daccount]) {
	      lastvalue[daccount]=values[daccount];
	      freezetoggle[daccount]=0;
	    }
	    else values[daccount]=lastvalue[daccount];
	    */
	    // -hold/release ^^
	    /*
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    if (frozen[daccount]==0) {
	      lastvalue[daccount]=values[daccount];
	    }
	      else values[daccount]=lastvalue[daccount];// frozen
	    */
	    // -hold overlay voltage as above with regular overlay

	  // TODO: types of overlays
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play // end playback
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]); 
	    //	    values[daccount]=4095;
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

	    /////////////////////////////////////////////

	    // new test modes: 77+ 4/7/2023+
	    // no freeze or minor modes stuff yet

	case 77: // DEPRECATE
	    /*enter mode:
	      [usual no rec/no play - but not if we have been recording??!]
	      [rec] - start recording with no overlay[so erases]. overlay when we reach end and loop back

	      [rec/end] - sets length of overlay/segment and keeps recording overlay - but we need to playback!
	      
	      [play]- plays back with live overlay
	      [play]- no play: stops all playback 

	      - how to distinguish no play /from/ no play/no rec/end-overlay?

	    // if we leave play directly into rec we want it to be the first rec only???
	    */
	  FREEZERS;
          REALADC;
	  // 4 states: play, rec, overlay, nada	  

	  if (play && ender[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	    overlaid=0;
	  } 
	  else lastplay=0;
	  
	  ///// recordings
	    if (rec){ // we are recording // on entry but not 2nd time
	      LASTREC; // reset all only on entering
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
	      LSTREC;
	      // playback and record overlap
	      // TODO: different kinds of overlay
	      speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]); 
	      values[daccount]+=real[daccount];
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	      }
	    }
	    else llrec=0;
	    
	    // nada
	    if (rec==0 && play==0 && overlaid==0) values[daccount]=(real[daccount]);
	    //	    if (overlaid) values[daccount]=4095;
	    
	    break; ///// 

	case 78: 
	    /*
	     *Instead of new mode 77: rec started during play is overlay* (play started during rec is also overlay?)
	     so we have 4 states:
	     - NADA
	     - rec/resets start of reccount, stop
	     - play
	     - rec+play: OVERLAY! stop rec: stops overlay, carries on playing// stop play: into NADA... (so are there 2 ways out?)
	     // or should stop play just revert to rec with no overlay// and reset on entry // but there is no entry as we are there, so carries on/extends.. ?
	     // *question of stop play returning to bare reset rec*
	    */

	  FREEZERS;
          REALADC;
	  // manage 4 states: play, rec, overlay, nada
	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;
	  // if we leave overlaid via. exit from play
	  if (lastmode==1 && play==0) {
	    rec=0; 
	    lastmode=0;
	  }

	  // play
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
	    } 
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
	      /*
		9: looped rec and overlay. always rec. peak overlay, fast speed: recordings[daccount][rec_cnt[daccount]]=values[daccount]; [values also adds real but is different as speed dependent]
		10: looped rec and overlay- different rec scheme. slower speed: recordings[daccount][rec_cnt[daccount]]+=real[daccount]; // we just add overlay, not add it to played back!
	      */
	      // this version is odd if we increase speed as only adds to where we are in play_cnt
	      //	      recordings[daccount][(int)play_cnt[daccount]]=values[daccount];
	       // alt unsynced version
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	      }
	    }
	    else llrec=0;
	    
	    // nada
	    if (rec==0 && play==0 && overlaid==0) {
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]); 

	    lastmode=0;
	    }
	    break; ///// 

	    /////////////

	case 79: // as 78 but: POSSIBLY DEP
	    /*
	     *MODEX:local mode with different lengths but can repeat to full length with different overlays...*
	     simply= *play as looped, re-record/overlay is getting up to full length. any variations on this?*
	     // but not so simple as we want to play that overlay the next time round ... so is not just a loop...
	     // one speed looping for rec, the other playing overlay
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
	  
	  if ((!overlaid) && play && ender[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } 
	  
	  ///// recordings
	  if ((!overlaid) && rec){ // we are recording // on entry but not 2nd time
	      LASTREC; // reset all only on entering
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
	  if (overlaid){ // we reset to play_cnt though
	    LSTRECPLAY;
	      // playback and record overlap
	      // TODO: different kinds of overlay
	      speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);  // see older cases 9/10 TODO!
	      values[daccount]+=real[daccount]; // could depend on freeze
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];

	      // other process - bit where this starts from - also reset
	      // this only makes sense once we are through it all once! TODO! otherwise values are as they are...
	      // see first_round[daccount]==2 code!
	      values[daccount]=speedsamplelop(speed, MAXREC, daccount, recordings[daccount]);  // we need to set play_cnt_lop[] to play_cnt[] also for this one!
	      
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    }
	    else llrec=0;
	    
	    // nada
	    if (rec==0 && play==0 && overlaid==0) values[daccount]=(real[daccount]);
	    break; /////
	    
	    /////////////////////////////////////////////

	case 80: // as 77 but islands - updated with leaving rec+play
	  /*
	    - *MODEX: overlay: we want to be able to overlay only one section of playback (and this section is fixed? how?) for each section?*

	    [start------------end] - according to rec...
	    [------][xxxxx][-----]
	    no play  play   no play
	    [   [freeze/freeze]  ]       

	    // start with play - default is enter play // reset freeze - if freeze then set start of island, unfreeze set end

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
	    LASTPLAYFR; // this also resets starter and enderr
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;

	    if (freezetoggle[daccount]){
	      if (frozen[daccount]) starter[daccount]=(int)play_cnt[daccount];
	      else {
		enderr[daccount]=(int)play_cnt[daccount];
		      }
	      freezetoggle[daccount]=0;
	  }
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    lengg=ender[daccount]-starter[daccount]; // ender is always bigger
	    if (lengg<1) lengg=1;
	    if (enderr[daccount]<starter[daccount]){
	      // dont play in gap between ender and starter
	      if ( ((int)play_cnt[daccount]<enderr[daccount]) || ((int)play_cnt[daccount]>starter[daccount]) )
		{
		  values[daccount]=speedsamplestart(logfast[speed], lengg, starter[daccount], daccount, recordings[daccount]);
		  values[daccount]+=real[daccount];
		  if (values[daccount]>4095) values[daccount]=4095;
		}
	      else {
		values[daccount]=speedsamplestart(logfast[speed], lengg, starter[daccount], daccount, recordings[daccount]);
		values[daccount]=real[daccount];
	      }
	    } else // starter is less than enderr
	      {
	    if ((int)play_cnt[daccount]<enderr[daccount]) {
	      values[daccount]=speedsamplestart(logfast[speed], lengg, starter[daccount], daccount, recordings[daccount]);
	      values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else {
	      values[daccount]=speedsamplestart(logfast[speed], lengg, starter[daccount], daccount, recordings[daccount]);
	      values[daccount]=real[daccount];
	    }
	      }
	    
	  } 
	  
	  ///// recordings // freeze is just freeze
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
	    
	    // overlay // just detach play/and/rec or just rec so we overlay only island
	    if (overlaid){
	      LSTRECPLAY;
	      lastmode=1;
	      // playback and record overlap
	      // TODO: different kinds of overlay
	      if (freezetoggle[daccount]){
		if (frozen[daccount]) starter[daccount]=(int)play_cnt[daccount];
		else {
		  enderr[daccount]=(int)play_cnt[daccount];
		}
		freezetoggle[daccount]=0;
	      }
	    
	      speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);  // see older cases 9/10 TODO!
	      values[daccount]+=real[daccount]; // could depend on freeze
	      if (values[daccount]>4095) values[daccount]=4095;
	      if (enderr[daccount]<starter[daccount]){
		if ( (rec_cnt[daccount]<enderr[daccount]) || (rec_cnt[daccount]>starter[daccount]) ) 	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      }
	      else
		{
		  if (rec_cnt[daccount]> starter[daccount] && rec_cnt[daccount]<enderr[daccount]) 	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
		}
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	      }
	    }
	    else llrec=0;
	    
	    // nada
	    if (rec==0 && play==0 && overlaid==0) values[daccount]=(real[daccount]);
	    break; ///// 

	    /////////////

         case 81: 
	    /*
	     *MODEX: or it could also be the original and we make all overlays in top bits, freeze/unfreeze toggles between the two for each!!*
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
	      // overlay is recorded in top bits - so we need to record first from bottom and then just top!
	      // how do we know if we have completed first round - we start at play_cnt and keep going.. 2nd time we hit it or??
	      // first_round[daccount]=2; // we go past ender and then past play_cnt we started with...

	      if (first_round[daccount]!=2 || frozen[daccount]==0) values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);  // see older cases 9/10 TODO!
	      else values[daccount]=speedsampletop(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		
	      values[daccount]+=real[daccount]; // could depend on freeze
	      if (values[daccount]>4095) values[daccount]=4095;
	      // try different versions for minormodes? also see 9/10
	      recordings[daccount][rec_cnt[daccount]]=(values[daccount]<<16); // top bits only
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
		first_round[daccount]=1;
	      }
	      if (first_round[daccount]==1 && (rec_cnt[daccount]>lastplayspot[daccount])) first_round[daccount]=2;
	    }
	    else llrec=0;
	    
	    // nada
	    if (rec==0 && play==0 && overlaid==0) {
	      values[daccount]=(real[daccount]);
	      lastmode=0;
	    }
	    break; ///// 
	    /////////////////////////////////////////////
	    
	case 101:
	  REALADC;
	  values[daccount]=(real[daccount]);
	  break;
	    /////////////////////////////////////////////
	    
	case 8: // now changing speed and slower fixed rec////
	  // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, no speed
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    values[daccount]=speedsample(0.0625, rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  recsp[daccount]++;
	  //	  recspeed=real[6]>>6; // gets faster for higher values
	  recspeed=8; // TESTY was 16 fixed 1/16 speed=0.0625
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      if (recsp[daccount]>recspeed){
		recsp[daccount]=0;
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 9: // looped recording and overlay - so it is always playing/recording - 
	  // rec and play length held change start and end points
	  // or they could just operate as start rec, start play...???
	  // could also be fixed speed
	  // 2 diff versions or more
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  ////
	  LASTREC; // reset all
	  LASTPLAY;
	  RECLONG; // lastlastrec stores reclong which just increments itself 
	  RECPLAY;
	  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits

	  endpoint=MAXREC-lastlastplay;
	  if (endpoint<lastlastrec) {
	    lastlastplay=0;
	    endpoint=MAXREC;
	  }
	  
	  if (lastlastrec>endpoint) lastlastrec=0;
	  lengg=endpoint-lastlastrec;
	  if (lengg<1) lengg=1;
	  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	  values[daccount]=speedsamplestart(logfast[speed], lengg, lastlastrec, daccount, recordings[daccount]); 
	  values[daccount]+=real[daccount];
	  if (values[daccount]>4095) values[daccount]=4095;
	  recordings[daccount][rec_cnt[daccount]]=values[daccount];
	  rec_cnt[daccount]++;
	  if (rec_cnt[daccount]>endpoint) {
	    rec_cnt[daccount]=lastlastrec;
	    }
	  break; ///// 

	case 10: // start on looped recording and overlay - so it is always playing/recording - 
	  // 2nd version with different recordings scheme
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  ////
	  LASTREC; // reset all
	  LASTPLAY;
	  RECLONG; // lastlastrec stores reclong which just increments itself 
	  RECPLAY;

	  endpoint=MAXREC-lastlastplay;
	  if (endpoint<lastlastrec) {
	    lastlastplay=0;
	    endpoint=MAXREC;
	  }
	  
	  if (lastlastrec>endpoint) lastlastrec=0;
	  lengg=endpoint-lastlastrec;
	  if (lengg<1) lengg=1;
	  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	  values[daccount]=speedsamplestart(logspeed[speed], lengg, lastlastrec, daccount, recordings[daccount]); 
	  values[daccount]+=real[daccount];
	  if (values[daccount]>4095) values[daccount]=4095;
	  recordings[daccount][rec_cnt[daccount]]+=real[daccount];
	  if (recordings[daccount][rec_cnt[daccount]]>4095) recordings[daccount][rec_cnt[daccount]]=4095;
	  rec_cnt[daccount]++;
	  if (rec_cnt[daccount]>endpoint) {
	    rec_cnt[daccount]=lastlastrec;
	    }
	  break; ///// 

	case 11: // trial record speed - tap top freeze to record speed as top voltage, tap to stop rec...
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || daccount==6 ) { // freeze always holds except in case of 6TOP
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAYCNT;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    speed+=(ownspeedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]))>>2;
	    if (speed>1023) speed=1023; // or modulus
	    if (frozen[6]==1){ // we record the speed
	      where=(int)ownplay_cnt[6];
	      	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(real[6]<<16); // top 16 bits are speed -- overwrites last speed
	      //	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(speed<<18); // top 16 bits are speed <<18 as we shifted // ALT to above
	    }
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording - we need to reset speeds at top but they will be overwritten...
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

	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break;

	case 12: // trial record speed - tap top freeze to record speed as top voltage, tap to stop rec...
	  // freeze stops rec/playback and starts again...
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || daccount==6 ) { // freeze always holds except in case of 6TOP
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAYCNT;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    if (frozen[6]==1){ // we record the speed and play it back...
	      speed+=(ownspeedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]))>>2; // returns own speed
	      if (speed>1023) speed=1023; // or modulus or if >
	      where=(int)ownplay_cnt[6];
	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(speed<<18); // top 16 bits are speed
	      }
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording - we need to reset speeds at top but they will be overwritten...
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

	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break;

	  //- 13, 14, 15: global/detach mode... rec and play as usual:
	  // 13 - freeze overdubs a section in playback mode
	  //to overdub a section only-freeze, to free/detach/pull a section out of playback, re-attach // can this be on same mode?
          case 13: 
	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]); // TESTY logfast
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
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
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;

	    if (frozen[daccount]){ // overdub start and stop but must overdub where we are as in playcnt
	      recordings[daccount][(int)play_cnt[daccount]]=values[daccount];
	    }
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; ///// 

	case 14: // not overdub but just record new
	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]); // TESTY logfast
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
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
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;

	    if (frozen[daccount]){ // overdub start and stop but must overdub where we are as in playcnt
	    values[daccount]=real[daccount];
	    recordings[daccount][(int)play_cnt[daccount]]=values[daccount];
	    }
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; ///// 

	  
	case 15: // see above. just detach that section from playback...
	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY; // reset
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]); // TESTY logfast
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
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
	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	      if (frozen[daccount]==0) { 
		values[daccount]+=real[daccount];
		if (values[daccount]>4095) values[daccount]=4095;
	      }
	      else values[daccount]=real[daccount];
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; ///// 

	case 16: // trial for slew of touch outside
	  // so fixed speed and slew from [6] global
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  /// slew our real - so target is whenever we hit target...
	  
	  speedy=1.0f/((real[6]>>2)+1.0f);
	  //	  speedy=0.001f;

	    result[daccount] = ((float)target[daccount] * alpha[daccount]) + ((float)starty[daccount] * (1.0f - alpha[daccount])); // interpol but is just last and before last
	    alpha[daccount]+=speedy;
	    if (alpha[daccount]>1.0f) alpha[daccount]=1.0f;
	    
	    //	    if (target[daccount]==starty[daccount]) target[daccount]=real[daccount];
	    
	    if (target[daccount]>=starty[daccount] && result[daccount]>=target[daccount]) {
	    starty[daccount]=target[daccount]; // present value
	    target[daccount]=real[daccount];
	    alpha[daccount]=0.0f;
	    }
	    else if (target[daccount]<=starty[daccount] && result[daccount]<=target[daccount]) {
	    starty[daccount]=target[daccount];
	    target[daccount]=real[daccount];
	    alpha[daccount]=0.0f;
	    }

	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=result[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=result[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	    }
	  else {
	    values[daccount]=(result[daccount]); 
	  }
	  break; ///// 

	  // global: freezer shifts start of each particular section towards the end
	case 17: 
	  REALADC;
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    RECFREEZE;
	    if (starter[daccount]>=rec_cnt[daccount]) starter[daccount]=0;
	    lengg=rec_cnt[daccount]-starter[daccount];
	    if (lengg<1) lengg=1;
	    values[daccount]=speedsamplestart(logfast[speed], lengg, starter[daccount], daccount, recordings[daccount]); 
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
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
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; ///// 


	case 19: // as 0 but if we are in playback mode, freeze holds playback/rec voltage...
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || play) { // as we don;t want freeze in play 
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    if (frozen[daccount]==0) {
	      values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      lastvalue[daccount]=values[daccount];
	    }
	    else values[daccount]=lastvalue[daccount];
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

	case 20: // as 19 above but different kind of freeze... speed still moves on samples...
	  // as 0 but if we are in playback mode, freeze holds playback/rec voltage... 
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || play) { // as we don;t want freeze in play 
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    if (!frozen[daccount]) lastvalue[daccount]=values[daccount];

	    if (frozen[daccount]) values[daccount]=lastvalue[daccount]; // 
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
	    
	case 21: // as 0 but no reset of rec_cnt
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
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
	      //	      LASTREC; // reset all
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

	case 22: // - slew which doesn't wait until target - TODO:how to do rise and fall independent speeds??
	  // so fixed speed and slew from [6] global
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
	  
	  speedy=1.0f/((real[6]>>2)+1.0f); // 0 is fastest
	  //	  speedy=1.0f-speedy; invert
	  //	  speedy=0.001f;
	  //	  speedy=0.01f;

	    result[daccount] = ((float)target[daccount] * alpha[daccount]) + ((float)starty[daccount] * (1.0f - alpha[daccount])); // interpol but is just last and before last
	    alpha[daccount]+=speedy;
	    if (alpha[daccount]>1.0f) alpha[daccount]=1.0f;
	    
	    //	    if (target[daccount]==starty[daccount]) target[daccount]=real[daccount];

	    if (target[daccount]>=starty[daccount]) { // we are going up//
	      if ((result[daccount]>=target[daccount]) || (real[daccount]<target[daccount])){
	    starty[daccount]=result[daccount]; // present value
	    alpha[daccount]=0.0f;
	    target[daccount]=real[daccount];
	      }
	    }
	    else { // going down
	      if ((result[daccount]<=target[daccount]) || (real[daccount]>target[daccount])){
	    starty[daccount]=result[daccount]; // present value
	    alpha[daccount]=0.0f;
	    target[daccount]=real[daccount];
	      }
	    }

	    /*
	    if ((target[daccount]>=starty[daccount] && result[daccount]>=target[daccount]) || (target[daccount]<=starty[daccount] && result[daccount]<=target[daccount])) {
	    starty[daccount]=result[daccount]; // present value
	    alpha[daccount]=0.0f;
	    target[daccount]=real[daccount];
	    }
	    */

	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=result[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=result[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(result[daccount]); 
	  }
	  break; ///// 

          case 23:
	    // - overlay mirror: all follow say lowest/bottom voltage [4] but add own 
	    //  overlay (live and/or in recording/playback - what makes sense
	    //  here) + rec/speed versions of this
	    //and variations on this eg. all voltages only, all VCA, all

	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
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
	    if (daccount==4) values[daccount]=(real[daccount]);
	    else {
	      values[daccount]=(real[4]+real[daccount]);
	      if (values[daccount]>4095) values[daccount]=4095;
	    }
	  }

	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      if (daccount!=4) {
		real[daccount]+=(real[4]);
	      if (real[daccount]>4095) real[daccount]=4095;
	    }

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
	  break; /////23

          case 24:
	    //this one: freeze just plays back with own overlay the previous section ADC (does not copy), unfreeze reverts to own record...
	    /////- global and local: freeze copies previous section ADC - copy as we play back into rec buffer, unfreeze just stops this process

	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    if (frozen[daccount]) {
	      values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[previousone[daccount]]); // all cnts are same in globals
	    }
	    else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
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
	  break; ///// 24

	case 25:
	    //- global and local: freeze copies previous section ADC - copy as we play back into rec buffer, unfreeze just stops this process

	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    if (frozen[daccount]) {
	      values[daccount]=speedsamplecopy(logfast[speed], rec_cnt[daccount], daccount, recordings[previousone[daccount]], recordings[daccount]); // all cnts are same in globals
	    }
	    else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
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
	  break; /////25 

          case 26:
	    // - these also suggest another mode which overlays the previous one on playback - so adds the 2 recs...
	    //this one: freeze just plays back with own overlay the previous section ADC (does not copy), unfreeze reverts to own record...
	    /////- global and local: freeze copies previous section ADC - copy as we play back into rec buffer, unfreeze just stops this process

	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    if (frozen[daccount]) {
	      values[daccount]+=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[previousone[daccount]]); // all cnts are same in globals
	    }
	    else 
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
	  break; /////26
	  
	  //////////////////////////////////////////////////////
	  //////////////////////////////////////////////////////
	  
	  // starty of LOCAL modes...
	case 30: // 
	  // alt logic - rec and play just reset counters as soon as hit
	  // overlay is peak
	  /*	  
		  freeze: record, tap again: playback
		  
		  play: global stop/start all playback (also sync)...
		  rec: global rec (nada if we are already in rec)...
	  */
	  FREEZERS;
	  REALADC;

	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once
	  if (togrec){ 
	    LASTREC;
	  }
	  else {
	    lastrec=0;
	      }

	  if (togplay){
	    LASTPLAY;
	  }
	  else {
	    lastplay=0;
	      }

	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 
	  
	  /// start on local modes - freeze is toggle rec/play
	case 31: // basic mode with NO freezers, record and play and overlay with freeze/unfreeze of all, no speed changes at all...
	  // rec and play overrides ... does this logic make sense as we can have play and rec at same time?
	  // overlay is peak
	  /*	  
		  freeze: record, tap again: playback
		  
		  play: global stop/start all playback (also sync)...
		  rec: global rec (nada if we are already in rec)...
	  */
	  FREEZERS;
	  REALADC;

	  if (frozen[daccount]) { // rec on freezer
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once
	  if (rec){ 
	    LASTREC;
	  }
	  else {
	    lastrec=0;
	      }

	  if (play){
	    LASTPLAY;
	  }
	  else {
	    lastplay=0;
	      }

	  // playback
	  if ((play || playb[daccount]) && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  
	  ///// recordings
	    if (rec || recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if ((play || playb[daccount]) && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 


	case 33: // as 30 but - *rec freezes all, play resets all counters*
	  // alt logic - rec and play just reset counters as soon as hit
	  // overlay is peak
	  /*	  
		  freeze: record, tap again: playback
		  
		  play: global stop/start all playback (also sync)...
		  rec: global rec (nada if we are already in rec)...
	  */
	  FREEZERS;
	  if (rec==0){ // global freezer
	  REALADC;
	  }
	  
	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once

	  if (togplay){
	    LASTPLAY;
	    LASTREC
	  }
	  else {
	    lastplay=0;
	    lastrec=0;
	      }

	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 34: // as 33 but rec holds playback: as 30 but - *rec freezes all, play resets all counters*
	  FREEZERS;
	  REALADC;
	  
	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once

	  if (togplay){
	    LASTPLAY;
	    LASTREC
	  }
	  else {
	    lastplay=0;
	    lastrec=0;
	      }
	  
	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    if (rec==0){
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	    lastvalue[daccount]=values[daccount];
	    }
	    else values[daccount]=lastvalue[daccount];	    
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 35: // alt hold as 34 above 
	  FREEZERS;
	  REALADC;
	  
	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once

	  if (togplay){
	    LASTPLAY;
	    LASTREC
	  }
	  else {
	    lastplay=0;
	    lastrec=0;
	      }
	  
	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	    lastvalue[daccount]=values[daccount];

	    if (rec) values[daccount]=lastvalue[daccount];	    
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	  
	  ///////////////////////
	  //////////////////////

	case 666: // speed test ONLY 166.7Hz // on 413 now we have 190+Hz with divider... 1.5Khz for each run through = 3kHz
	  //	  values[daccount]=val;
	  /* 
	  daccount=4;
	  GPIOC->BSRRH = 0b1110100000000000;		       
	  DAC_SetChannel1Data(DAC_Align_12b_R, val);
	  j = DAC_GetDataOutputValue (DAC_Channel_1);		
	  GPIOC->BSRRL=(daccount)<<13; // multiplex
	  */
	  //CLEARDAC; // why we remove this but is there on writedac - timing
	  //	  if (daccount==4){
	  if (values[daccount]==0) values[daccount]=4095;
	  else values[daccount]=0;
	  //	  }
	  //	  else values[daccount]=4095;
	  
	  //if (val==0) val=4095;
	  //	  else val=0;

	  //	  	  }
	  //	  RESETT; // all resets... drops us to 15Hz so we lose 1/30th second... on full reset
	  //	  RESET0; // one reset... drops to 142Hz so not so bad... 
	  break;

	case 667:
	  if (daccount==4){
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		values[daccount]=4095;
		rec_cnt[daccount]=0;
	      }
	      else values[daccount]=0;
	  }		
	  break;
	  
	case 777: // tests of all toggles! rec, play, mode and freeze
	  FREEZERS;
	  if (modetoggle) {  // frozen[daccount] //modetoggle // rec is fine...
	    values[4]=4095;
	  }
	  else values[4]=0;
	  break; /////

	case 778: // for hold timing tests below:
	  //	  if (baseminor==4) 	  {
	  //	    testting^=1; // testy
	  //	    baseminor=0;
	  //	  }
	  if (testting) { 
	    values[4]=4095;
	  }
	  else values[4]=0;
	  
	  //	  values[4]=baseminor*10;
	  break; /////

	case 779:
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; 
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(GPIOC, &GPIO_InitStructure);
	  GPIOC->BSRRL=(1)<<6;
	  delay();
	  if (!(GPIOB->IDR & (1<<6))) {	       
	    values[4]=4095;
	}
	else {
	  values[4]=0;
	}
	break; ////


	case 780: // test basic following 
	  FREEZERS;
          REALADC;
	  values[daccount]=(real[daccount]); 
	  break; ///// 

	
	} // end of modes switch

	//////////////////////////////
		
//	if (testting) values[daccount]=4095; // TESTY
//	else values[daccount]=0; // TESTY
