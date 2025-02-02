uint32_t playlodge(float speed1, uint32_t d, uint32_t lay, uint32_t* P_options){ 
  uint32_t x, y, tmpx, tmpxx, ff;
  uint32_t sample=0;

    for (x=0;x<f[d].pl[lay].num_lodges;x++){
    f[d].pl[lay].lodges[x].delcntt=mod0(f[d].pl[lay].lodges[x].delcntt+speed1, (f[d].pl[lay].lodges[x].offset+f[d].pl[lay].lodges[x].length+f[d].pl[lay].lodges[x].delay));
  }

    for (x=0;x<f[d].pl[lay].num_lodges;x++){
      if (f[d].pl[lay].lodges[x].delcntt>=f[d].pl[lay].lodges[x].offset && (f[d].pl[lay].lodges[x].delcntt<=(f[d].pl[lay].lodges[x].offset+f[d].pl[lay].lodges[x].length))) {
	if ((f[d].pl[lay].lodges[x].start+f[d].pl[lay].lodges[x].length)>MAXREC) ff=(MAXREC-f[d].pl[lay].lodges[x].start);
	else ff=f[d].pl[lay].lodges[x].length;
	tmpx=f[d].pl[lay].lodges[x].delcnt+f[d].pl[lay].lodges[x].start;
	if (tmpx>=MAXREC) tmpx=MAXREC-1;
	f[d].pl[lay].lodges[x].delcnt=mod0(f[d].pl[lay].lodges[x].delcnt+speed1, ff);

	if (lay==0) {
	  sample=overlayx(recordings[d][tmpx]&TOP, sample, (P_options[0]>>5)&3); // deal with overlap of zones in one layer DONE
	  f[d].pl[lay].lodges[x].currentval=recordings[d][tmpx]&TOP; // currentval
	}
	else {
	  sample=overlayx(recordings[d][tmpx]>>16, sample, (P_options[0]>>5)&3); // top layer
	  f[d].pl[lay].lodges[x].currentval=recordings[d][tmpx]>>16; // currentval
	}
      }
        }
    return sample;
}


inline static void changemode(uint32_t dacc){
  f[dacc].majormode[f[dacc].state]++;
  if (f[dacc].majormode[f[dacc].state]>MAXMODE[f[dacc].state]) f[dacc].majormode[f[dacc].state]=0;
  f[dacc].ttoggle=0;
  f[dacc].play=0;					
  f[dacc].rec=0;
  f[dacc].state=N; // NADA  
  // TODO: what else we need to reset here
}

	    else if (modeheld>SOFTRESET && modeheld<FULLRESET){
	      if (f[0].active) resets(0);
	      if (f[1].active) resets(1);
	      if (f[2].active) resets(2);
	      if (f[3].active) resets(3);
	      if (f[4].active) resets(4);
	      if (f[5].active) resets(5);
	      if (f[6].active) resets(6);
	      if (f[7].active) resets(7);
	    }
	else if (modeheld>LONGMODE && modeheld<SOFTRESET) { // increment major mode if active
	  modeheld=0;
	  if (f[0].active) changemode(0);
	  if (f[1].active) changemode(1);
	  if (f[2].active) changemode(2);
	  if (f[3].active) changemode(3);
	  if (f[4].active) changemode(4);
	  if (f[5].active) changemode(5);
	  if (f[6].active) changemode(6);
	  if (f[7].active) changemode(7);
	}	
	else if (modeheld<LONGMODE){ //inc minor mode 
	  modeheld=0;
	  // if state==0 inc just 0
	  // ==1 inc depends on masterL[0]
	  if (f[0].active) {
	    if (f[0].state==0) f[0].minormode[0][0]++;
	    else if (f[0].state==1) f[0].minormode[f[0].masterL[0]][f[0].state]++;
	    else if (f[0].state==2) f[0].minormode[f[0].masterL[1]][f[0].state]++;
	    else if (f[0].state==3) f[0].minormode[f[0].masterL[2]][f[0].state]++;
	    }
	  if (f[1].active) {
	    if (f[1].state==0) f[1].minormode[0][0]++;
	    else if (f[1].state==1) f[1].minormode[f[1].masterL[0]][f[1].state]++;
	    else if (f[1].state==2) f[1].minormode[f[1].masterL[1]][f[1].state]++;
	    else if (f[1].state==3) f[1].minormode[f[1].masterL[2]][f[1].state]++;
	    }
	  if (f[2].active) {
	    if (f[2].state==0) f[2].minormode[0][0]++;
	    else if (f[2].state==1) f[2].minormode[f[2].masterL[0]][f[2].state]++;
	    else if (f[2].state==2) f[2].minormode[f[2].masterL[1]][f[2].state]++;
	    else if (f[2].state==3) f[2].minormode[f[2].masterL[2]][f[2].state]++;
	    }
	  if (f[3].active) {
	    if (f[3].state==0) f[3].minormode[0][0]++;
	    else if (f[3].state==1) f[3].minormode[f[3].masterL[0]][f[3].state]++;
	    else if (f[3].state==2) f[3].minormode[f[3].masterL[1]][f[3].state]++;
	    else if (f[3].state==3) f[1].minormode[f[3].masterL[2]][f[3].state]++;
	    }
	  if (f[4].active) {
	    if (f[4].state==0) f[4].minormode[0][0]++;
	    else if (f[4].state==1) f[4].minormode[f[4].masterL[0]][f[4].state]++;
	    else if (f[4].state==2) f[4].minormode[f[4].masterL[1]][f[4].state]++;
	    else if (f[4].state==3) f[4].minormode[f[4].masterL[2]][f[4].state]++;
	    }
	  if (f[5].active) {
	    if (f[5].state==0) f[5].minormode[0][0]++;
	    else if (f[5].state==1) f[5].minormode[f[5].masterL[0]][f[5].state]++;
	    else if (f[5].state==2) f[5].minormode[f[5].masterL[1]][f[5].state]++;
	    else if (f[5].state==3) f[5].minormode[f[5].masterL[2]][f[5].state]++;
	    }
	  if (f[6].active) {
	    if (f[6].state==0) f[6].minormode[0][0]++;
	    else if (f[6].state==1) f[6].minormode[f[6].masterL[0]][f[6].state]++;
	    else if (f[6].state==2) f[6].minormode[f[6].masterL[1]][f[6].state]++;
	    else if (f[6].state==3) f[6].minormode[f[6].masterL[2]][f[6].state]++;
	    }
	  if (f[7].active) {
	    if (f[7].state==0) f[7].minormode[0][0]++;
	    else if (f[7].state==1) f[7].minormode[f[7].masterL[0]][f[7].state]++;
	    else if (f[7].state==2) f[7].minormode[f[7].masterL[1]][f[7].state]++;
	    else if (f[7].state==3) f[7].minormode[f[7].masterL[2]][f[7].state]++;
	    }
	}

	} // newmode


// togplay and togrec	   
	if (f[d].active){
	  if (togplay) f[d].play^=1;
	  if (togrec) f[d].rec^=1;

	  if (f[d].lastmode==1 && f[d].play==0) { // if we leave RP via. exit from P we are not left in R
	    f[d].state=N;
	    f[d].rec=0; // added
	}
	else {
	// logic of states now
	  if (f[d].rec && f[d].play){
	    if (f[d].rl[f[d].masterL[0]].num_lodges>0){ // if we have a zone recorded
	      f[d].state=RP;
	  }
	    else {
	      f[d].state=R; // nothing to play
	      f[d].play=0; // added 2/7/2024
	    }
	  }
	  else if (f[d].rec)	f[d].state=R;
	  else if (f[d].play && (f[d].rl[f[d].masterL[0]].num_lodges>0)) f[d].state=P;
	  else f[d].state=N;
	}
	f[d].lastmode=0;
	} // end of active



	// REC: 
	if (f[d].state==R){
	  LAYERSWOPR;
	  values[d]=(*Rfunc[f[d].majormode[R]])(d, V_options, R_options);
	} // end REC
	else {
	  if (f[d].leaver){ 
	    (*Rfunc_leave[f[d].majormode[R]])(d);
	  }
	  f[d].entryr=0;
	}

	//	if (error) values[d]=4095;


uint32_t playlodge(float speed1, uint32_t d, uint32_t lay, uint32_t* P_options){ 
  uint32_t x, y, tmpx, tmpxx;
  uint32_t sample=0;
  /// first layer
  for (x=0;x<f[d].pl[lay].num_lodges;x++){
    f[d].pl[lay].lodges[x].delcntt=mod0(f[d].pl[lay].lodges[x].delcntt+speed1, (f[d].pl[lay].lodges[x].offset+f[d].pl[lay].lodges[x].realend+f[d].pl[lay].lodges[x].delay-f[d].pl[lay].lodges[x].start));
  }
  
    for (x=0;x<f[d].pl[lay].num_lodges;x++){
      if (f[d].pl[lay].lodges[x].delcntt>=f[d].pl[lay].lodges[x].offset && (f[d].pl[lay].lodges[x].delcntt<=(f[d].pl[lay].lodges[x].offset+f[d].pl[lay].lodges[x].realend-f[d].pl[lay].lodges[x].start))) {     // ***

	if (f[d].pl[lay].lodges[x].offset>=(f[d].pl[lay].lodges[x].offset-f[d].pl[lay].lodges[x].start)){
	    tmpx=((f[d].pl[lay].lodges[x].delcntt)-(f[d].pl[lay].lodges[x].offset-f[d].pl[lay].lodges[x].start));
	  }
	  else {
	    tmpx=((f[d].pl[lay].lodges[x].delcntt)+(f[d].pl[lay].lodges[x].start-f[d].pl[lay].lodges[x].offset));
	  }
	
	if (tmpx>=MAXREC) tmpx=MAXREC-1;

	if (lay==0) sample=overlayx(recordings[d][tmpx]&TOP, sample, (P_options[0]>>5)&3); // deal with overlap of zones in one layer DONE
	else sample=overlayx(recordings[d][tmpx]>>16, sample, (P_options[0]>>5)&3); // top layer
            }
    }
    return sample;
}



if (masterL==0){
	  tmpxx=overlayx(value, (recordings[d][tmpx]&TOP), (R_options[0])&3); // overlayRP?
      }
	      else {
	tmpxx=overlayx(layerval, (recordings[d][tmpx]&TOP), (R_options[0])&3);
	      }	
       reclayerlower(tmpxx, tmpx, d);
      }



// for CTRL and/or CTRL layer
inline static uint32_t overlay(uint32_t ctrl, uint32_t value, uint32_t over){ 
  uint32_t tmpp;
  int32_t subs; float nn;
 	    if (over==0){ //usual - now swopped for >
	      if (value>ctrl) tmpp=value; // only if is more than
	      else tmpp=ctrl;
	    }
	    else if (over==1){ 
	      tmpp=ctrl+value;
	      if (tmpp>TOP) tmpp=TOP; // as we store full value...
	    }
	    else if (over==2){ // mod
	      tmpp=ctrl+value;
	      tmpp=tmpp%4096;
	    }
	    else if (over==3){ // subtract live and do abs...
	      subs=value-ctrl;
	      tmpp=abs(subs);
	    }
	    else if (over==4){	    //add VCA/float thing /// but need more bits and more options
	    nn=ctrl/4095.0;
	    nn*=(float)value;
	    tmpp=(uint32_t)nn;
	    }
	    else if (over==5){	    //add VCA/float thing /// but need more bits and more options -> 3 bits=8 options...  +2 - mask/threshold!?
	      ctrl=4095-ctrl;
	      nn=ctrl/4095.0;
	      nn*=(float)value;
	      tmpp=(uint32_t)nn;
	    }
	    else if (over==6){ // 	      //	      - mask/threshold
	      if (ctrl>THRESH) tmpp=value;
		else tmpp=0;
	    }
	    else { 	      //	      - invert/threshold
	      if (ctrl>THRESH) tmpp=4095-value;
	    }
	    return tmpp;
}

// TODO: smear or smudge of values on entry into threshold...
inline static uint32_t overlayRP(uint32_t ctrl, uint32_t value, uint32_t over){ // 3 bits - ctrl is live value and value is recorded
 uint32_t tmpp;
  int32_t subs; float nn;
 	    if (over==1){ //usual - now swopped for >
	      if (value>ctrl) tmpp=value; // only if is more than
	      else tmpp=ctrl;
	    }
	    else if (over==0){ 
	      tmpp=ctrl+value;
	      if (tmpp>TOP) tmpp=TOP; // as we store full value...
	    }
	    else if (over==2){ // mod
	      tmpp=ctrl+value;
	      tmpp=tmpp%4096;
	    }
	    else if (over==3){ // subtract live and do abs... doesn't seem work... 
	      subs=value-ctrl;
	      tmpp=abs(subs);
	    }
	    else if (over==4){	    //add VCA/float thing /// but need more bits and more options
	    nn=ctrl/4095.0;
	    nn*=(float)value;
	    tmpp=(uint32_t)nn;
	    }
	    else if (over==5){	    //add VCA/float thing /// but need more bits and more options -> 3 bits=8 options...  +2 - mask/threshold!?
	      ctrl=4095-ctrl;
	      nn=ctrl/4095.0;
	      nn*=(float)value;
	      tmpp=(uint32_t)nn;
	    }
	    else if (over==6){ // 	      //	      - mask/threshold
	      if (ctrl>THRESH) tmpp=value;
		else tmpp=0;
	    }
	    else { 	      //	      - invert/threshold
	      //	      if (ctrl>THRESH) tmpp=4095-value;
	      //SOLO - overwrite
	      tmpp=ctrl;
	    }
	    return tmpp;
}



// FIX as above...
//TODO: linkage and attachment, does each lodge/zone have a function attached?
// genericise difference from reclodge - uses overlayRP
// and we shouldn't rewrite realend! no option to extend here... and there is no flag!
void reclodgeRP(layers *rec, uint32_t d, uint32_t value, uint32_t layerval, uint32_t* R_options, uint32_t* RP_options, uint32_t* res){ 
  uint32_t x, y, tmpx, tmpxx, swoptype, sample[2];
  swoptype=(RP_options[0]|RP_options[1])&1;
  // tape 0 lower
  for (x=0;x<rec[0].num_lodges;x++){
    if (rec[0].lodges[x].flag==0) {

      if (rec[0].lodges[x].delcnt>=rec[0].lodges[x].offset && (rec[0].lodges[x].delcnt<=(rec[0].lodges[x].offset+rec[0].lodges[x].end-rec[0].lodges[x].start))) {

	if (rec[0].lodges[x].offset>=(rec[0].lodges[x].offset-rec[0].lodges[x].start)){
	    tmpx=((rec[0].lodges[x].delcnt)-(rec[0].lodges[x].offset-rec[0].lodges[x].start));
	  }
	  else {
	    tmpx=((rec[0].lodges[x].delcnt)+(rec[0].lodges[x].start-rec[0].lodges[x].offset));
	  }
      
	//      if (rec[0].lodges[x].over==0) rec[0].lodges[x].realend=tmpx; //**
	//      else rec[0].lodges[x].overcnt=tmpx;

      if (swoptype=0){ // swop values only
	if (f[d].masterL[2]==0){
	  tmpxx=overlayRP(value, (recordings[d][tmpx]&TOP), (RP_options[0]>>2)&7);
	}
	else {
	  tmpxx=overlayRP(layerval, (recordings[d][tmpx]&TOP), (RP_options[0]>>2)&7);
	      }	
       reclayerlower(tmpxx, tmpx, d);
      }
      else { // swop layers
	if (f[d].masterL[2]==0){
	tmpxx=overlayRP(value, (recordings[d][tmpx]&TOP), (RP_options[0]>>2)&7);
	reclayerlower(tmpxx, tmpx, d);
	}
	else {
	  tmpxx=overlayRP(value, (recordings[d][tmpx]>>16), (RP_options[0]>>2)&7); // fixed
	  reclayerupper(tmpxx, tmpx, d); 
	}
      }
      sample[0]=tmpxx; // last one
      }
      rec[0].lodges[x].delcnt+=1;
      if (rec[0].lodges[x].delcnt>=(rec[0].lodges[x].offset+rec[0].lodges[x].end+rec[0].lodges[x].delay-rec[0].lodges[x].start)){
	//	if (rec[0].lodges[x].delcnt>MAXREC){
	//	  rec[0].lodges[x].realend=MAXREC;
	//	  rec[0].lodges[x].over=1;
	//	}
	rec[0].lodges[x].delcnt=0;  
      }
    }
  }
  // other layer
  for (x=0;x<rec[1].num_lodges;x++){
    if (rec[1].lodges[x].flag==0) {

      if (rec[1].lodges[x].delcnt>=rec[1].lodges[x].offset && (rec[1].lodges[x].delcnt<=(rec[1].lodges[x].offset+rec[1].lodges[x].end-rec[1].lodges[x].start))) {

	if (rec[1].lodges[x].offset>=(rec[1].lodges[x].offset-rec[1].lodges[x].start)){
	    tmpx=((rec[1].lodges[x].delcnt)-(rec[1].lodges[x].offset-rec[1].lodges[x].start));
	  }
	  else {
	    tmpx=((rec[1].lodges[x].delcnt)+(rec[1].lodges[x].start-rec[1].lodges[x].offset));
	  }
      
	//      if (rec[1].lodges[x].over==0) rec[1].lodges[x].realend=tmpx; //**
	//      else rec[1].lodges[x].overcnt=tmpx;

      if (swoptype=0){ // swop values only
	if (f[d].masterL[2]==0){
	  tmpxx=overlayRP(layerval, (recordings[d][tmpx]>>16), (RP_options[1]>>2)&7); // fixed
	}
	else {
	  tmpxx=overlayRP(value, (recordings[d][tmpx]>>16), (RP_options[1]>>2)&7); // fixed
	      }	
	reclayerupper(tmpxx, tmpx, d);
      }
      else { // swop layers
	if (f[d].masterL[2]==0){
	tmpxx=overlayRP(layerval, (recordings[d][tmpx]>>16), (RP_options[1]>>2)&7);
	reclayerupper(tmpxx, tmpx, d);
	}
	else {
	  tmpxx=overlayRP(layerval, (recordings[d][tmpx]&TOP), (RP_options[1]>>2)&7); // fixed
	  reclayerlower(tmpxx, tmpx, d); 
	}
      }
      sample[1]=tmpxx; // last one as no overlay here...
      }
      rec[1].lodges[x].delcnt+=1;
      if (rec[1].lodges[x].delcnt>=(rec[1].lodges[x].offset+rec[1].lodges[x].end+rec[1].lodges[x].delay-rec[1].lodges[x].start)){
      //	if (rec[1].lodges[x].delcnt>MAXREC){
      //	  rec[1].lodges[x].realend=MAXREC;
      //	  rec[1].lodges[x].over=1;
      //	}
	rec[1].lodges[x].delcnt=0;  
      }
    }
  }
    if (f[d].masterL[2]==0){
    res[0]=sample[0];
    res[1]=sample[1];
    }
    else {
    res[1]=sample[0];
    res[0]=sample[1];
    }

}



void R_addlodges_leave_silence(uint32_t d){
  uint32_t tmpx;
  // if we were recording then close it...
      if (f[d].rl[f[d].masterL[0]].ind==1){ // we were recording so set end point of last one and add all delays
	tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1; // lodge we just left
	f[d].rl[f[d].masterL[0]].lodges[tmpx].end=f[d].rl[f[d].masterL[0]].lodges[tmpx].realend;
	//	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend;  // previous end
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[f[d].masterL[0]].lodges[x].delay+=(f[d].rl[f[d].masterL[0]].lodges[tmpx].realend-f[d].rl[f[d].masterL[0]].lodges[tmpx].start+1); // FIXed!
	}
	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=((f[d].rl[f[d].masterL[0]].lodges[tmpx-1].offset)+f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil-(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].start); 
	f[d].rl[f[d].masterL[0]].ind=0;
      }
      f[d].leaver=0;
}

// TODO: R_addlodges version but offset is silence between - first zone starts right away...
/*
// run counter on entry into function
// that becomes offset but we need to update delcnt too ???
 */

// TODO: needs two layers???
uint32_t R_addlodges_silence(uint32_t d, uint32_t V_options, uint32_t* R_options){ // add zones on press and offset is silence
  uint32_t tmp, tmpp, other, tmpx;
  if (f[d].entryr==0){ // includes reset now
    // what to reset?    
    lastvalue[d]=0;
    f[d].entryr=1;
    f[d].leaver=1;
    f[d].entryd=0;
    f[d].rl[0].ind=0;
    f[d].rl[1].ind=0;
    f[d].rl[0].rcnt=0;
    f[d].rl[1].rcnt=0;
  }
  
  LAYERSWOPR;
  tmp=real[d];
  // CTRL is second value
  f[d].rl[f[d].masterL[0]].rcnt++;
  if (tmp>LOWVAL) { // start recording
    f[d].rl[f[d].masterL[0]].ind=1;
    if (f[d].entryd==0){
    f[d].rl[f[d].masterL[0]].num_lodges+=1;
    if (f[d].rl[f[d].masterL[0]].num_lodges>MAXLODGE) f[d].rl[f[d].masterL[0]].num_lodges=1;
    if (f[d].rl[f[d].masterL[0]].num_lodges==1){ // first lodge
      f[d].rl[f[d].masterL[0]].lodges[0].overcnt=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delcnt=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delcntt=0; // this is for when we copy to playzones
      f[d].rl[f[d].masterL[0]].lodges[0].start=0;
      f[d].rl[f[d].masterL[0]].lodges[0].offset=0; //f[d].rl[f[d].masterL[0]].rcnt; // we need to start now in realtime
      f[d].rl[f[d].masterL[0]].lodges[0].delay=0; // looping???
      f[d].rl[f[d].masterL[0]].lodges[0].flag=0;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].sil=0;
      f[d].rl[f[d].masterL[0]].lodges[0].end=MAXREC; 
    } // first lodge
    else {
      tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].overcnt=0;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].flag=0; 
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delcnt=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+1;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delcntt=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].delcntt;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].start=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend+1;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].sil=f[d].rl[f[d].masterL[0]].rcnt;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+1;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delay=0; // to come later
      f[d].rl[f[d].masterL[0]].lodges[tmpx].end=MAXREC; // to come later
      f[d].rl[f[d].masterL[0]].lodges[tmpx-1].flag=1; // stop the last one TODO: remember to reset
    }
    f[d].entryd=1;
    } // entry
    reclodge(f[d].rl, d, tmp, tmpp, R_options);
  } // above val
  else { 
      // low value but did we leave recording
    if (f[d].rl[f[d].masterL[0]].ind==1){ // we were recording so set end point of last one and add all delays
      tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1; // lodge we just left
      //   f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=((f[d].rl[f[d].masterL[0]].lodges[tmpx-1].offset)+f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil-(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].start); 
      f[d].rl[f[d].masterL[0]].lodges[tmpx].end=f[d].rl[f[d].masterL[0]].lodges[tmpx].realend;
	//	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend;  // previous end
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[f[d].masterL[0]].lodges[x].delay+=(f[d].rl[f[d].masterL[0]].lodges[tmpx].realend-f[d].rl[f[d].masterL[0]].lodges[tmpx].start+1)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil;
	  //	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=((f[d].rl[f[d].masterL[0]].lodges[tmpx-1].offset)+f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil-(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].start); 

	f[d].rl[f[d].masterL[0]].ind=0; f[d].entryd=0;
	f[d].rl[f[d].masterL[0]].rcnt=0;
	}
    }
  }
  return tmp;
}


uint32_t x, y, tmpx, tmpxx, lay;
    // tape 0 lower   
  for (x=0;x<rec[f[d].masterL[0]].num_lodges;x++){
    rec[f[d].masterL[0]].lodges[x].delcnt+=1;
      if (rec[f[d].masterL[0]].lodges[x].delcnt>rec[f[d].masterL[0]].lodges[x].end){
      rec[f[d].masterL[0]].lodges[x].delcnt=0;  
      }

    if (rec[f[d].masterL[0]].lodges[x].delcnt>=rec[f[d].masterL[0]].lodges[x].offset && (rec[f[d].masterL[0]].lodges[x].delcnt<=(rec[f[d].masterL[0]].lodges[x].offset+rec[f[d].masterL[0]].lodges[x].end-rec[f[d].masterL[0]].lodges[x].start))) {

	if (rec[f[d].masterL[0]].lodges[x].offset>=(rec[f[d].masterL[0]].lodges[x].offset-rec[f[d].masterL[0]].lodges[x].start)){
	    tmpx=((rec[f[d].masterL[0]].lodges[x].delcnt)-(rec[f[d].masterL[0]].lodges[x].offset-rec[f[d].masterL[0]].lodges[x].start));
	  }
	  else {
	    tmpx=((rec[f[d].masterL[0]].lodges[x].delcnt)+(rec[f[d].masterL[0]].lodges[x].start-rec[f[d].masterL[0]].lodges[x].offset));
	  }
      tmpxx=overlayRP(value, (recordings[d][tmpx]&TOP), (RP_options)&7); // OVERLAY
      reclayerlower(tmpxx, tmpx, d);
    }
  }
  // other layer
  lay=f[d].masterL[0]^1; 
  for (x=0;x<rec[lay].num_lodges;x++){
    rec[lay].lodges[x].delcnt+=1;
      if (rec[lay].lodges[x].delcnt>rec[lay].lodges[x].end){
      rec[lay].lodges[x].delcnt=0;  
      }

    if (rec[lay].lodges[x].delcnt>=rec[lay].lodges[x].offset && (rec[lay].lodges[x].delcnt<=(rec[lay].lodges[x].offset+rec[lay].lodges[x].end-rec[lay].lodges[x].start))) {

	if (rec[lay].lodges[x].offset>=(rec[lay].lodges[x].offset-rec[lay].lodges[x].start)){
	    tmpx=((rec[lay].lodges[x].delcnt)-(rec[lay].lodges[x].offset-rec[lay].lodges[x].start));
	  }
	  else {
	    tmpx=((rec[lay].lodges[x].delcnt)+(rec[lay].lodges[x].start-rec[lay].lodges[x].offset));
	  }
	tmpxx=overlayRP(value, (recordings[d][tmpx]&TOP), (RP_options)&7); // OVERLAY
	reclayerupper(tmpxx, tmpx, d);
    }
  }
 
}


tmpxx=overlayRP(value, (recordings[d][tmpx]&TOP), (RP_options)&7); // OVERLAY

//TODO: linkage and attachment, does each lodge/zone have a function attached?
void reclodge(layers *rec, uint32_t d, uint32_t value, uint32_t layerval, uint32_t R_options){ // pass in the p/layers
  uint32_t x, y, tmpx, tmpxx, lay;
  float speed1=1.0f;
  // tape 0 lower
  for (x=0;x<rec[f[d].masterL[0]].num_lodges;x++){
  if (rec[f[d].masterL[0]].lodges[x].flag==0)
    {
    f[d].rl[f[d].masterL[0]].lodges[x].delcnt=mod0(f[d].rl[f[d].masterL[0]].lodges[x].delcnt+speed1, (f[d].rl[f[d].masterL[0]].lodges[x].offset+f[d].rl[f[d].masterL[0]].lodges[x].realend+f[d].rl[f[d].masterL[0]].lodges[x].delay-f[d].rl[f[d].masterL[0]].lodges[x].start));
  }
  }
  
  for (x=0;x<rec[f[d].masterL[0]].num_lodges;x++){
      if (rec[f[d].masterL[0]].lodges[x].flag==0)
    if (rec[f[d].masterL[0]].lodges[x].delcnt>=rec[f[d].masterL[0]].lodges[x].offset && (rec[f[d].masterL[0]].lodges[x].delcnt<=(rec[f[d].masterL[0]].lodges[x].offset+rec[f[d].masterL[0]].lodges[x].end-rec[f[d].masterL[0]].lodges[x].start))) {

	if (f[d].rl[f[d].masterL[0]].lodges[x].offset>=(f[d].rl[f[d].masterL[0]].lodges[x].offset-f[d].rl[f[d].masterL[0]].lodges[x].start)){
	    tmpx=((f[d].rl[f[d].masterL[0]].lodges[x].delcntt)-(f[d].rl[f[d].masterL[0]].lodges[x].offset-f[d].rl[f[d].masterL[0]].lodges[x].start));
	  }
	  else {
	    tmpx=((f[d].rl[f[d].masterL[0]].lodges[x].delcntt)+(f[d].rl[f[d].masterL[0]].lodges[x].start-f[d].rl[f[d].masterL[0]].lodges[x].offset));
	  }
	if (tmpx>=MAXREC) tmpx=MAXREC-1;
      
      if (rec[f[d].masterL[0]].lodges[x].over==0) rec[f[d].masterL[0]].lodges[x].realend=tmpx; //**

      if (f[d].masterL[0]==0) {
	tmpxx=overlayx(value, (recordings[d][tmpx]&TOP), (R_options>>2)&3);
	reclayerlower(tmpxx, tmpx, d);
      }
	      else {
		tmpxx=overlayx(value, (recordings[d][tmpx]>>16), (R_options>>2)&3); // fixed
		reclayerupper(tmpxx, tmpx, d); 
	      }	
    }
  }
}

  //// -> reclodge

  //  uint32_t playlodge(float speed1, float speed2, uint32_t d, uint32_t P_options){ // pass in the p/layers
  uint32_t x, y, tmpx, tmpxx, lay;
  for (x=0;x<f[d].pl[f[d].masterL[1]].num_lodges;x++){
    f[d].pl[f[d].masterL[1]].lodges[x].delcntt=mod0(f[d].pl[f[d].masterL[1]].lodges[x].delcntt+speed1, (f[d].pl[f[d].masterL[1]].lodges[x].offset+f[d].pl[f[d].masterL[1]].lodges[x].realend+f[d].pl[f[d].masterL[1]].lodges[x].delay-f[d].pl[f[d].masterL[1]].lodges[x].start));
  }
  
    for (x=0;x<f[d].pl[f[d].masterL[1]].num_lodges;x++){
  
      if (f[d].pl[f[d].masterL[1]].lodges[x].delcntt>=f[d].pl[f[d].masterL[1]].lodges[x].offset && (f[d].pl[f[d].masterL[1]].lodges[x].delcntt<=(f[d].pl[f[d].masterL[1]].lodges[x].offset+f[d].pl[f[d].masterL[1]].lodges[x].realend-f[d].pl[f[d].masterL[1]].lodges[x].start))) {     // ***

	//		tmpx=f[d].pl[f[d].masterL[1]].lodges[x].cntt+f[d].pl[f[d].masterL[1]].lodges[x].start;
	if (f[d].pl[f[d].masterL[1]].lodges[x].offset>=(f[d].pl[f[d].masterL[1]].lodges[x].offset-f[d].pl[f[d].masterL[1]].lodges[x].start)){
	    tmpx=((f[d].pl[f[d].masterL[1]].lodges[x].delcntt)-(f[d].pl[f[d].masterL[1]].lodges[x].offset-f[d].pl[f[d].masterL[1]].lodges[x].start));
	  }
	  else {
	    tmpx=((f[d].pl[f[d].masterL[1]].lodges[x].delcntt)+(f[d].pl[f[d].masterL[1]].lodges[x].start-f[d].pl[f[d].masterL[1]].lodges[x].offset));
	  }
	
	if (tmpx>=MAXREC) tmpx=MAXREC-1;
	if (f[d].masterL[1]==0) sample=overlayx(recordings[d][tmpx]&TOP, sample, (P_options>>5)&3); // deal with overlap of zones in one layer DONE
	else sample=overlayx(recordings[d][tmpx]>>16, sample, (P_options>>5)&3); // top layer
      
    } 
    }
}

  
  // opposite layer...
  lay=f[d].masterL[0]^1; 
  for (x=0;x<f[d].rl[lay].num_lodges;x++){
  if (rec[lay].lodges[x].flag==0){
    rec[lay].lodges[x].delcnt++;
    if (rec[lay].lodges[x].delcnt>=rec[lay].lodges[x].offset && (rec[lay].lodges[x].delcnt<=(rec[lay].lodges[x].offset+rec[lay].lodges[x].end-rec[lay].lodges[x].start))) {     
      tmpx=rec[lay].lodges[x].cnt+rec[lay].lodges[x].start;
      if (rec[lay].lodges[x].over==0) rec[lay].lodges[x].realend=tmpx; // fixed
      if (tmpx>rec[lay].lodges[x].end) { // now we want final delay before we start again
	rec[lay].lodges[x].realend=rec[lay].lodges[x].end;
	tmpx=rec[lay].lodges[x].start;
	rec[lay].lodges[x].cnt=0;
	rec[lay].lodges[x].over=1;
    }
      if (lay==0) {
      tmpxx=overlayx(layerval, (recordings[d][tmpx]&TOP), (R_options>>2)&3); 
      reclayerlower(tmpxx, tmpx, d);
      }
      else {
      tmpxx=overlayx(layerval, (recordings[d][tmpx]>>16), (R_options>>2)&3); // fixed
      reclayerupper(tmpxx, tmpx, d); 
      }	
      rec[lay].lodges[x].cnt++;
    }
  }
    if (rec[lay].lodges[x].delcnt>=(rec[lay].lodges[x].offset+rec[lay].lodges[x].end+rec[lay].lodges[x].delay-rec[lay].lodges[x].start)) rec[lay].lodges[x].delcnt=0;
  }
}

//TODO: linkage and attachment, does each lodge/zone have a function attached?
// this one uses 
void reclodgeRP(layers *rec, uint32_t d, uint32_t value, uint32_t layerval, uint32_t RP_options){ // pass in the p/layers
  uint32_t x, y, tmpx, tmpxx, lay;
  // tape 0 lower
  for (x=0;x<rec[f[d].masterL[0]].num_lodges;x++){
  if (rec[f[d].masterL[0]].lodges[x].flag==0)
    {
    rec[f[d].masterL[0]].lodges[x].delcnt++; 
    if (rec[f[d].masterL[0]].lodges[x].delcnt>=rec[f[d].masterL[0]].lodges[x].offset && (rec[f[d].masterL[0]].lodges[x].delcnt<=(rec[f[d].masterL[0]].lodges[x].offset+rec[f[d].masterL[0]].lodges[x].end-rec[f[d].masterL[0]].lodges[x].start))) {     
      tmpx=rec[f[d].masterL[0]].lodges[x].cnt+rec[f[d].masterL[0]].lodges[x].start;
      if (rec[f[d].masterL[0]].lodges[x].over==0) rec[f[d].masterL[0]].lodges[x].realend=tmpx+1; 
      if (tmpx>rec[f[d].masterL[0]].lodges[x].end) { // now we want final delay before we start again
	rec[f[d].masterL[0]].lodges[x].realend=rec[f[d].masterL[0]].lodges[x].end;
	tmpx=rec[f[d].masterL[0]].lodges[x].start;
	rec[f[d].masterL[0]].lodges[x].cnt=0;
	rec[f[d].masterL[0]].lodges[x].over=1;
    }
      tmpxx=overlayRP(value, (recordings[d][tmpx]&TOP), (RP_options)&7); // OVERLAY
      reclayerlower(tmpxx, tmpx, d);
      rec[f[d].masterL[0]].lodges[x].cnt++;
    }
  }
    if (rec[f[d].masterL[0]].lodges[x].delcnt>=(rec[f[d].masterL[0]].lodges[x].offset+rec[f[d].masterL[0]].lodges[x].end+rec[f[d].masterL[0]].lodges[x].delay-rec[f[d].masterL[0]].lodges[x].start)) rec[f[d].masterL[0]].lodges[x].delcnt=0;
  }
  // opposite layer...
  lay=f[d].masterL[0]^1; 
  for (x=0;x<f[d].rl[lay].num_lodges;x++){
  if (rec[lay].lodges[x].flag==0){
    rec[lay].lodges[x].delcnt++;
    if (rec[lay].lodges[x].delcnt>=rec[lay].lodges[x].offset && (rec[lay].lodges[x].delcnt<=(rec[lay].lodges[x].offset+rec[lay].lodges[x].end-rec[lay].lodges[x].start))) {     
      tmpx=rec[lay].lodges[x].cnt+rec[lay].lodges[x].start;
      if (rec[lay].lodges[x].over==0) rec[lay].lodges[x].realend=tmpx; // fixed
      if (tmpx>rec[lay].lodges[x].end) { // now we want final delay before we start again
	rec[lay].lodges[x].realend=rec[lay].lodges[x].end;
	tmpx=rec[lay].lodges[x].start;
	rec[lay].lodges[x].cnt=0;
	rec[lay].lodges[x].over=1;
    }
      tmpxx=overlay(layerval, (recordings[d][tmpx]>>16), (RP_options)&7); // OVERLAY
      reclayerupper(tmpxx, tmpx, d); // fixed! as was lower by mistake
      rec[lay].lodges[x].cnt++;
    }
  }
    if (rec[lay].lodges[x].delcnt>=(rec[lay].lodges[x].offset+rec[lay].lodges[x].end+rec[lay].lodges[x].delay-rec[lay].lodges[x].start)) rec[lay].lodges[x].delcnt=0;
  }
}

////

uint32_t RP_basic(uint32_t d, uint32_t V_options, uint32_t P_options, uint32_t R_options, uint32_t RP_options){
  uint32_t pp, other, tmpp, tmp;
  if (f[d].entryrp==0){
    f[d].leaverp=1;
    f[d].entryrp=1;
    }
  // handle play
  float speedy=playreff[f[d].playspeed[f[d].masterL[1]]][(control[whichctrl[d]]>>2)]; 
  tmp=real[d];
  //  pp=speedsampleplay(speedy, d, 0, d, recordings[d]); // last two d can be access to others...
  tmp=overlay(tmp, pp, (P_options>>3)&3); // live overlay on playback 
  other=f[d].masterL[1]^1; // swoppage

  f[d].rl[other].num_lodges=1;
  f[d].rl[f[d].masterL[1]].num_lodges=1;
  if (f[d].rl[other].lodges[0].realend && (RP_options&2)) f[d].rl[other].lodges[0].end=f[d].rl[other].lodges[0].realend;
  else f[d].rl[other].lodges[0].end=MAXREC; // option of rec_end

  if (RP_options&1){ // option to stop rec on not playing...
    //  reclodgex(d, tmp, other, R_options);
  }
  //  else 	if (speedy!=0.0f) reclodgex(d, tmp, other, R_options); // default is to stop
  return tmp;  
}


inline static uint32_t livevalue(uint32_t which, uint32_t opt){ // ???? or keep inversion...
  uint32_t tmpp, subs, overoverlay;
  // options for live value - eg. add global from top (and type of overlays), (sensitivity is already in macros)
  if (which!=6) tmpp=real[6]; // top voltage - value at the end
  // 6 syncs to 4 lowest
  else tmpp=real[4];
  
  overoverlay=(opt>>1)&3;
  if (overoverlay==0) tmpp=real[which];
  else if (overoverlay==2){ //usual - now swopped for >
    if (real[which]>tmpp) tmpp=real[which]; // only if is more than
  }
  else if (overoverlay==3){ 
    tmpp+=real[which];
    //    if (tmpp>4095) tmpp=4095; // ??
    if (tmpp>BOTS) tmpp=BOTS; // as we store full value...	    
  }
  else if (overoverlay==1){ // invert 
    tmpp=4095-real[which];
    }
  return tmpp;
}


switch(f[d].majormode[R]){
	  case 0:
	  case 1:
	    tmp=livevalue(d, V_options);
	    LAYERSWOP;
	    autre=f[d].masterL;
	    RECLAYER; // autre is our layer for the macro  
	    autre=f[d].masterL^1;
	    tmp=overlay(control[whichctrl[d]], tmp, R_options&3); // overlay of CTRL
	    values[d]=tmp;
	    RECLAYER;
	    break;
	  case 2: //ADC: zooms through start and end (at each press start, next press start) zoom/stop and playback is bounced to other layer... trigger swops layers
	    tmp=livevalue(d, V_options);
	    LAYERSWOPRP; 
	    if (control[whichctrl[d]]>32){ 
	      speed=control[whichctrl[d]]>>2;
	      if (f[d].rpp==0) f[d].rpp=1; // set start
	      if (f[d].rpp==2) f[d].rpp=3;
	      //	      values[d]=f[d].l[f[d].masterL].speedsamp(playreff[f[d].playspeed][speed], f[d].l[f[d].masterL].rec_end, 0, f[d].l[f[d].masterL].rec_end, d, recordings[d]);
	      if (f[d].rpp==1) { // set the start
		f[d].l[f[d].masterL].rec_start=f[d].l[f[d].masterL].play_cnt;
	      }
	      else { // set the end
		if (f[d].l[f[d].masterL].play_cnt>f[d].l[f[d].masterL].rec_start) f[d].l[f[d].masterL].rec_length=f[d].l[f[d].masterL].play_cnt-f[d].l[f[d].masterL].rec_start;
		else f[d].l[f[d].masterL].rec_length=(f[d].l[f[d].masterL].rec_end-f[d].l[f[d].masterL].play_cnt)+f[d].l[f[d].masterL].rec_start;
	      }
	      values[d]=overlay(tmp, values[d], (P_options>>2)&3); 
	    }
	    else { // released...
	      //		values[d]=f[d].l[f[d].masterL].speedsamp(1.0f, f[d].l[f[d].masterL].rec_length, f[d].l[f[d].masterL].rec_start, f[d].l[f[d].masterL].rec_end, d, recordings[d]);
		values[d]=overlay(tmp, values[d], (P_options>>2)&3); // and write this to other layer
		tmp=values[d];
		autre=f[d].masterL^1;
		RECLAYERPX; //DONE/to test//TODO: what is limit for that one!? we keep on adding // how else? overlayx opts, RECEND opts as per RP below!
	      if (f[d].rpp==3) f[d].rpp=0;
     	      else if (f[d].rpp==1) f[d].rpp=2; // set end // when do we set to 0
	    }
	    break;
	  } // end switch

	  switch(f[d].majormode[RP]){
	  case 0:
	  case 1:
	  f[d].lastmode=1; // in this case!
	  LAYERSWOPRP;
	  tmp=livevalue(d, V_options); 
	  speed=control[whichctrl[d]]>>2;
	  autre=f[d].masterL^1; // opposite...
	  //	  values[d]=f[d].l[f[d].masterL].speedsamp(playreff[f[d].playspeed][speed], f[d].l[f[d].masterL].rec_end, 0, f[d].l[f[d].masterL].rec_end, d, recordings[d]); // as per play above for mode 0** would be playlist in playlist modes
	  values[d]=overlay(tmp, values[d], (P_options>>2)&3); // types of live overlay - is also recorded
	  tmp=overlayx(values[d], f[d].l[autre].accessreclayer(d), (RP_options>>1)&3);
	  //RECLAYERP; // now with RP_options bit 1 as toggling rec_end - test live toggling // ???TODO: also we could reset rec_cnt to 0 - when??????
	  if (RP_options&8){ // option to stop rec on not playing...
	    RECLAYERP;
	  }
	  else 	  if (speed!=0.0f) RECLAYERP; // default is to stop
	  break;
	  case 2: // matching R://ADC: zooms through start and end (at each press start, next press start) zoom/stop and playback is bounced to other layer... trigger swops layers
	    // but what happens here
	  break;
	  }


//(recordings[d][f[d].layer[1].rec_cnt]&4095); // lower
//

void reclayerupper(uint32_t value, uint32_t d){
  recordings[d][f[d].l[1].rec_cnt]=(recordings[d][f[d].l[1].rec_cnt]&4095)+(value<<16);
}

void reclayerlower(uint32_t value, uint32_t d){
  recordings[d][f[d].l[0].rec_cnt]=(recordings[d][f[d].l[0].rec_cnt]&TOPS)+(value);
}


//(recordings[d][f[d].layer[1].rec_cnt]&4095); // lower
//

void reclayerupper(uint32_t value, uint32_t d){
  recordings[d][f[d].l[1].rec_cnt]=(recordings[d][f[d].l[1].rec_cnt]&4095)+(value<<16);
}

void reclayerlower(uint32_t value, uint32_t d){
  recordings[d][f[d].l[0].rec_cnt]=(recordings[d][f[d].l[0].rec_cnt]&TOPS)+(value);
}

inline static uint32_t accessplaylayerupper(uint32_t d){
  uint32_t value=(recordings[d][(int)f[d].l[1].play_cnt])>>16; 
  return value;
}

inline static uint32_t accessplaylayerlower(uint32_t d){
  uint32_t value=(recordings[d][(int)f[d].l[0].play_cnt])&4095; 
  return value;
}

inline static uint32_t accessreclayerupper(uint32_t d){
  uint32_t value=(recordings[d][f[d].l[1].rec_cnt])>>16; 
  return value;
}



inline static uint32_t accessreclayerlower(uint32_t d){
  uint32_t value=(recordings[d][f[d].l[0].rec_cnt])&4095; 
  return value;
}


// 000

// adding to playlist
inline static float mod0N(float value, float start, float ending, float length, uint32_t d, uint32_t layer) // new one with start and ending/loop point
{
  static uint32_t lengthed;
  lengthed=0;
  while (value > (ending-1)){ // wrapping
    value -= ending;
  }
  while (f[d].l[layer].cnt>(length-1)){
    f[d].l[layer].cnt-=length;
    ADDPLAYLIST;
    lengthed=1;
    }
  if (lengthed) {
    value=f[d].l[layer].cnt+start;
  }
  return value;
}

inline static float mod0NN(float value, float start, float ending, float length, uint32_t d, uint32_t layer) // new one with start and ending/loop point
{
  static uint32_t lengthed;
  uint32_t tmpp;
  lengthed=0;
  while (value > (ending-1)){
    value -= ending;
    }
    tmpp=f[d].l[layer].cnt;
    if ((tmpp+1)>(length-1)){
    tmpp-=length;
    //    value=start+tmpp;
  if (lengthed) {
    value=tmpp+start;
  }
    }
  return value;
}

inline static float mod0(float value, float length) // basic one
{
  while (value > (length-1))
        value -= length;
    return value;
}

inline static float mod0XX(float value, float length, uint32_t d)
{
  while (value > (length-1)){
        value -= length;
    // get next in list
  f[d].playcnt+=1; 
  if (f[d].playcnt>=f[d].playfull) f[d].playcnt=0;
  length=f[d].playlist[f[d].playcnt].length;
  }
    return value;
}

inline static float mod00(float value, float length, uint32_t d)
{
  uint32_t tmp=f[d].playcnt;
  while (value > (length-1)) {
        value -= length;
	tmp+=1;
	if (tmp>f[d].playfull) tmp=0;
	length=f[d].playlist[tmp].length;
  }
  return value;
}

inline static float mod0X(float value, float length, uint32_t d) // adds to playlist 
{
  while (value > (length-1)){
    value -= length;
    ADDPLAYLISTRST;
    f[d].l[f[d].masterL].cnt=0;
  }
  return value;
}

inline static uint32_t speedsampleplay(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition, layer=0;
  float sample;
  lengthy=f[dacc].playlist[f[dacc].playcnt].length;
  end=f[dacc].playlist[f[dacc].playcnt].end;
  start=f[dacc].playlist[f[dacc].playcnt].start;
  layer=f[dacc].playlist[f[dacc].playcnt].l;

  f[dacc].l[layer].play_cnt=mod0(f[dacc].l[layer].play_cnt+speedy, start, end, lengthy, dacc);
  lowerPosition = (int)f[dacc].l[layer].play_cnt;
  upperPosition = mod00(lowerPosition + 1, lengthy, dacc); // wrap... or entry into next in list?
  int32_t res=(f[dacc].l[layer].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  if (layer==0){  
    LOWER;
  }
  else {
    UPPER;
  }
  return (uint32_t)sample;
}




// new one for wrap - no playlist yet
// inline static float mod0n(float value, float start, float ending, float length, uint32_t dacc) // new one with start and ending/loop point
// wrapping version - end is topmost(rec_end), length is how long, start is start - so can wrap round end...
inline static uint32_t speedsamplelowerW(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
    uint32_t lowerPosition, upperPosition;
    float sample;
    f[dacc].l[0].cnt+=speedy;
    f[dacc].l[0].play_cnt=mod0N(f[dacc].l[0].play_cnt+speedy, start, end, lengthy, dacc, 0);
    lowerPosition = (int)f[dacc].l[0].play_cnt;
    upperPosition = mod0NN(lowerPosition + 1, start, end, lengthy, dacc, 0);
   int32_t res=(f[dacc].l[0].play_cnt - (float)lowerPosition);
   if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
   if (upperPosition>=MAXREC) upperPosition=0;
    LOWER;
  return (uint32_t)sample;
}

inline static uint32_t speedsampleupperW(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
    uint32_t lowerPosition, upperPosition;
    float sample;
    f[dacc].l[1].cnt+=speedy;
    f[dacc].l[1].play_cnt=mod0N(f[dacc].l[1].play_cnt+speedy, start, end, lengthy, dacc, 1);
    lowerPosition = (int)f[dacc].l[1].play_cnt;
    upperPosition = mod0NN(lowerPosition + 1, start, end, lengthy, dacc, 1);
    int32_t res=(f[dacc].l[1].play_cnt - (float)lowerPosition);
    if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
    if (upperPosition>=MAXREC) upperPosition=0;
    UPPER;
    return (uint32_t)sample;
}

// no add but do read from playlist - no layers as layer is in the list // TODO: deal with wrap on end

// nada to do with playlist
inline static uint32_t speedsamplelowerN(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  float sample;
  f[dacc].l[0].play_cnt=mod0(f[dacc].l[0].play_cnt+speedy, lengthy);
  lowerPosition = (int)f[dacc].l[0].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy); // wrap... or entry into next in list?
  int32_t res=(f[dacc].l[0].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  LOWER;
  return (uint32_t)sample;
}

inline static uint32_t speedsampleupperN(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  float sample;
  f[dacc].l[1].play_cnt=mod0(f[dacc].l[1].play_cnt+speedy, lengthy);
  lowerPosition = (int)f[dacc].l[1].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy);
  int32_t res=(f[dacc].l[1].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  UPPER;
  return (uint32_t)sample;
}



// 3 sets of speedsamplelower/upper: add to playlist, read from playlist, no add/no read from

// this one here is add to playlist
inline static uint32_t speedsamplelower(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  float sample;
  f[dacc].l[0].othercnt+=speedy; // fixed - to test!
  f[dacc].l[0].play_cnt=mod0X(f[dacc].l[0].play_cnt+speedy, lengthy, dacc);
  lowerPosition = (int)f[dacc].l[0].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy); // wrap... or entry into next in list?
  int32_t res=(f[dacc].l[0].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  LOWER;
  return (uint32_t)sample;
}

inline static uint32_t speedsampleupper(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  float sample;
  f[dacc].l[1].othercnt+=speedy;
  f[dacc].l[1].play_cnt=mod0X(f[dacc].l[1].play_cnt+speedy, lengthy, dacc);
  lowerPosition = (int)f[dacc].l[1].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy);
  int32_t res=(f[dacc].l[1].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  UPPER;
  return (uint32_t)sample;
}

void speedsample(float speedy, uint32_t layer){
  uint32_t lowerPosition, upperPosition;
  uint32_t lengthy=playlist[playcnt].length;
  uint32_t start=playlist[playcnt].start;
  //printf("p:%d",playcnt);
  //  printf(" %d ,", start+(int)play_cnt_[layer]);
  othercnt[layer]++;
  //  if (othercnt[layer]>REC_END) othercnt[layer]=0;
  //  play_cnt_[layer]=mod0X(play_cnt_[layer]+speedy, lengthy, start);
  lengthy=playlist[playcnt].length;//???
  
    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt_[layer];
  //  upperPosition = mod0XX(lowerPosition + 1, lengthy);

  //  return (int)play_cnt;// + playlist[playcnt].start;
  return;
}


float mod0X(float value, float length, uint32_t start)
{
  uint32_t tmp, tmplen, tmpval;
  modded=0;
  while (value > (length-1)){ // we are ahead - get next in list
  value -= length; //0

    if (othercnt[0]>0) {
    playlist[playcntr].length=othercnt[0]-playlist[playcntr].start;
    //    printf("pp: %d xx:%d\n",playcntr, playlist[playcntr].length );
    playcntr++; // ignore zero length
    playfull++;
    playlist[playcntr].start=0;
    //    playlist[playcntr].length=REC_END-othercnt[0];
    }

  
    // get next in list
    playcnt+=1; 
    if (playcnt>=playfull) playcnt=0;
      length=playlist[playcnt].length;
    // add to list
  //  if (othercnt[0]>0) {
    //    playcntr++; 
    //    playfull++;
    //    if (playfull>=120) playfull=119;
    //    if (playcntr>=120) playcntr=119;
    //    playlist[playcntr].length=othercnt[0];
    //    playlist[playcntr].start=start; 
  //  }
  othercnt[0]=0;
   //   printf("playcnt: %d\n", playcnt);
  }
    return value;
}

float mod0XX(float value, float length)
{
  uint32_t tmp, tmplen, tmpval;
  tmp=playcnt;

  while (value > (length-1)){ // we are ahead
    value -= length; //0
    // get next in list
    //    tmp+=1;
    //    if (tmp>playfull) tmp=0;
    //    length=playlist[tmp].length;
  }
    return value;
}



spd=(float)control[whichctrl[daccount]]/10240.0;
	  fingers[daccount].layer[fingers[daccount].masterL].spdd+=spd;
	  fingers[daccount].layer[fingers[daccount].masterL].spdd-=0.02f; // inertia
	  if (fingers[daccount].layer[fingers[daccount].masterL].spdd<0.0) fingers[daccount].layer[fingers[daccount].masterL].spdd=0.0;
	  if (fingers[daccount].layer[fingers[daccount].masterL].spdd>8.0) fingers[daccount].layer[fingers[daccount].masterL].spdd=8.0;
	  if (fingers[daccount].layer[fingers[daccount].masterL].rec_end) values[daccount]=  fingers[daccount].layer[fingers[daccount].masterL].speedsamp[0](fingers[daccount].layer[fingers[daccount].masterL].spdd, fingers[daccount].layer[fingers[daccount].masterL].rec_end, 0, daccount, recordings[daccount]);  // start is always 0 TESTY??? RECEND is our length


float mod0X(float value, float length, uint32_t dacc)
{
  while (value > (length-1)){ // we are ahead
    value -= length; //0
    // get next in list
    fingers[dacc].playcnt+=1;
    if (fingers[dacc].playcnt>fingers[dacc].playfull) fingers[dacc].playcnt=0;
    fingers[dacc].playcntr+=1;
    if (fingers[dacc].playcntr>118) fingers[dacc].playcntr=0;
    //    printf("//playcnt %d playcntr %d len %d //",playcnt, playcntr, playlist[playcntr].length);
    length=fingers[dacc].playlist[fingers[dacc].playcnt].length;
  }
    return value;
}

float mod0XX(float value, float length, uint32_t dacc)
{
  uint32_t tmp;
  tmp=fingers[dacc].playcnt;

  while (value > (length-1)){ // we are ahead
    value -= length; //0
    // get next in list
    tmp+=1;
    if (tmp>fingers[dacc].playfull) tmp=0;
    length=fingers[dacc].playlist[tmp].length;
  }
    return value;
}


// TODO: we need to resolve layers and also start... also to resolve adding when we swop layers
// TODO: completely change!
inline static uint32_t speedsample_playlist(float speedy, uint32_t dacc, uint32_t *samples, uint32_t start, uint32_t layerr){ // for both lower and upper? TODO!
  uint32_t lowerPosition, upperPosition;
  float sample;
  uint32_t lengthy=fingers[dacc].playlist[fingers[dacc].playcnt].length;

  
  fingers[dacc].layer[layerr].play_cnt=mod0X(fingers[dacc].layer[layerr].play_cnt+speedy, lengthy, dacc);
  lengthy=fingers[dacc].playlist[fingers[dacc].playcnt].length;

    //  Find surrounding integer table positions
  lowerPosition = (int)  fingers[dacc].layer[layerr].play_cnt;
  upperPosition = mod0XX(lowerPosition + 1, lengthy, dacc);

  // test addings
  fingers[dacc].playlist[fingers[dacc].playcntr+1].length=(int)fingers[dacc].layer[layerr].play_cnt+1;
  fingers[dacc].playlist[fingers[dacc].playcntr+1].start=start; // ????
  fingers[dacc].playlist[fingers[dacc].playcntr+1].layer=layerr;
  fingers[dacc].playfull=fingers[dacc].playcntr;

  start=fingers[dacc].playlist[fingers[dacc].playcnt].start;
  layerr=fingers[dacc].playlist[fingers[dacc].playcnt].layer;
  int32_t res=(fingers[dacc].layer[layerr].play_cnt - (float)lowerPosition);

  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;

  if (layerr==0) {
  sample= ((samples[lowerPosition]&4095) + 
		 (res *
		  ((samples[upperPosition]&4095) - (samples[lowerPosition]&4095))));
  }
  else
    {
  sample= ((samples[lowerPosition]>>16) + 
		 (res *
		  ((samples[upperPosition]>>16) - (samples[lowerPosition]>>16)))); 
    }
  return (uint32_t)sample;
}



if (fingers[daccount].playfull==0) {					\
    fingers[daccount].playlist.start[0]=0;				\
    fingers[daccount].playlist.length[0]=fingers[daccount].layer[fingers[daccount].masterL].rec_end; \
    fingers[daccount].playlist.layer[0]=fingers[daccount].masterL;	\
    fingers[daccount].playcnt=0;					\
    }									\
    else {								\
    fingers[daccount].playfull+=1;					\
    if (fingers[daccount].playfull>119) fingers[daccount].playfull=1;	\
    fingers[daccount].playcnt=1;					\
    };									\
    if (fingers[daccount].playfull>119) fingers[daccount].playfull=1;	\


case 32:
	  // as mode 30?XX but we reset rec_cnt once...
	  // basic mode with NO freezers, record and play and overlay with freeze/unfreeze of all, no speed changes at all...
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
	    if (!lastrecy[daccount]){
	    rec_cnt[daccount]=1; // just once...
	    }
	    lastrecy[daccount]=0;
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    lastrecy[daccount]=1;
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

		//		itoa(rec_cnt[daccount], buffx, 10);
		//		uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char) - 1 };
		//		send_command(0x05/* some interrupt ID */, m);
		



	case 7: // TEST for local speeds on each voltage - so we don't add any values there 
	  // doesn't work so well as global as some have no contents
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    // speed depends on real how we treat it!
	    if (daccount>3) { // 4,5,6,7 voltages
	    speed=real[daccount]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    }
	    else {
	      speed=reall[daccount]; // 10 bits
	    }
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
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
	    if (play==0)	    values[daccount]=(real[daccount]); 
	    
	  break; ///// 


case 5: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage from lower up
	  // with only speed upwards
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

case 5: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage from lower up
	  // with only speed upwards
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

	  // NON!
	case 6: // speed with rec slow down
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
	    //	    values[daccount]=speedsample(logslow[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  recsp[daccount]++;
	  //	  recspeed=real[6]>>6; // gets faster for higher values
	  recspeed=16; // TESTY fixed
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


// NON!
	case 4: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage gets slower
	  /// speed lowering as case 2
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    speed=1;
	    //	    values[daccount]=speedsample(logslow[speed], rec_cnt[daccount], daccount, recordings[daccount]);
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


//	    values[daccount]=speedsample(speed, rec_cnt[daccount], recordings[daccount]);
// no filtering and we can't slow down here
// unused
uint32_t upspeedsample(uint32_t speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){
  uint32_t value;
  // test construction in most basic mode
  /*
  value=(samples[play_cnt[dacc]])&4095;  // ignore top bits
	      play_cnt[dacc]++;
	      if (play_cnt[dacc]>lengthy) play_cnt[dacc]=0; // but what if we overlap then play full...
  */
  // speedy is 1-32 ---> 1 is basic speed.
  speedy+=1;
  play_cnt[dacc]+=(float)speedy;
  if (play_cnt[dacc]>lengthy) play_cnt[dacc]=0.0f;
  value=(samples[(int)(play_cnt[dacc])])&4095;  // ignore top bits
  return value;
}

// latest PCB now April 2021:

// 13/4/2021: toggling and freezing implemented, all hardware tested and working...

/*
TODO:

- basic recording mode, how we handle freezes and length

- different modes to list out and implement for record and playback

//NOTES 14/4:

STM32F446RETx: 128KB memory. so if we have 2bytes for each cell x8 = 16 per step at 1 KHz

say we use 8k for other variables =120,000 remaining

7500 steps for each max = 7.5 seconds at 1KHz (fastest)

75 seconds at 100Hz

- run at max speed and record at slower speed

//

10/2/2020 - start to set up TIM2 interrupt

26/1/2020 - new code base for testing on latest PCB -> note on pcb PROG HEADER we swop last 2 gnd and swdio 

// test fixed DAC outs to voltages out and to VCAs.

// test ADCs in from pads to voltages out an VCAs.

// test FR1-8 inputs, rec, play and push

- implement recording, playback and any logic/scalings

- internal DAC PA4 with multiplex with EN_LOW1 on PC11 and sel1/2/3 on PC13/14/15

- ADC0-3 on PA0/1/2/3
- ADC5-7 on PA5/6/7
- ADC4 on PC0

- rec on PB2, play on PB4, push on PB6
- FR1-7 on PB8-15, FR8 on PC4 (inverted ins from 40106 so low is on!)

On PCB panel (clockwise): 
- top one(3): ADC5 and ADC4, F6 and F5 (is adc5top or 4 the one for VCA?)
- 4: ADC7 and ADC6, F8, F7
- 1: ADC1, ADC0, F1, F2
- 2: AS+DC3, ADC2, F3, F4

/////////////////////////////////////////////////////////////

New note - now we will use onboard DAC as we only use 12x ADC

Testing on STM32F446 NUCLEO

For new touch module/own touch things: 

- read from say 12x ADC and output signals on DAC - which will be multiplexed
- so we need input ADC and eventually toggle input pins for rec/play with, output address and enable for 4051  

- first steps: ADC inputs, DAC output (should be on PA4 (DAC_OUT1) which is marked A2 on lower left of board!

but we can only have 15 ADC ins as one doubles up as DAC!

// PROGRESS: now DAC seems to work...

// ADCs, output pins, input pins...

refs:  https://stackoverflow.com/questions/45718493/stm32-f446re-simple-dac-output-what-am-i-missing

https://csserver.evansville.edu/~blandfor/Engr101/NucleoBoardUserManual.pdf

// TODO: testing for external DAC such as MPC492X (one or two DACs) - tested with 4922

- setup SPI on SPI2 or SPI3 (SPI1 would conflict with ADC ins)
- communicate with DAC1 and test - SPI seems to be working now with enable to +V and schematic as in: 

http://community.axoloti.com/t/gpio-i-o-example-dac-mcp4x22-spi/134

MOSI is on PB5, SCK is on PB3, CS is on PA15

 */

/*
void TIM2_IRQHandler(void) {
  // flash on update event
  if (TIM2->SR & TIM_SR_UIF) GPIOA->ODR ^= (1 << 5);
   
  TIM2->SR = 0x0; // reset the status register
  }*/


/*

- problems with speeds and aliasing so need to rewrite code without 32 steps-TODO: how to handle slow downs and speed ups?

14/12/21: TODO: we need to stop rec and play and all freezers if we change mode!

Q of linear or exponential scales... at the moment is all linear...

//problems with speeds and aliasing so need to rewrite code without 32 steps


24/4/2023

///////////////////older

20/12+ - see notes.org for changes

14/12: put in modechanging clearance into macro TOGGLE - still needs to be TESTED!

13/12: changes to freeze/toggle logic which seem to work well, new macrosDONE

6/12: try new freeze/toggle logics - working better so test for freezings, tested but try with other fingers before we put into TOGGLE MACRO TODO!

2/12: re-check freeze etc.logic as seems odd - was wrong way round so corrected but still not 100% as needs release

2/11: we have bleed on voltages - small but present and how can we fix this?

18/10: on mode change should we stop rec/playback as this will change reading of data (only in some cases).DONE in macro 14/12

14/10: filled in mode 0 to test all

13/10: TODO: code in freezers, mode switch and rec/play with simple case 0 and test!

11/10: TODO: simplify code sections and test all freezers, rec, mode, playback (basic mode)

- what are our modes and where are these defined? in it.c

Revisiting 30 Sept:

- 30/9 tests: 2 and 3 not closing: 3 was adc issue which fixed
   somehow, 2 still bleeds at 60mV, we adjusted TIM2 slower to get rid
   of bleed across VCAs (why now?), still to test new freeze
   functionality...also got rid of bitshift as was loud (to check on
   scope), maybe try different resistor values for closings, testing
   first freeze and seems to work


//////////////////////////

TODO: August 30+ 2021:

- new PCB - we have trig on PC6 which needs to go high only when we sense any of trigs (freezers, rec, play, mode)

- basic operations of VCA and voltage with new board (also now we have low pass in hardware)
- new freezer/trig code and test all

think it is in mode23 but we need to change the output pin here!

- figure out modes, timings, log etc.
*/
