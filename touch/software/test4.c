#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "resources.h"
#define PLAYFULLY 119 // length of playlist in fingers.h
#include "fingers.h"

//gcc test4.c -otest -lm -std=gnu99

#define MAXREC 1280

//  lodgep=f[0].l[0].lodges; // can be passed in - but need to pass both layers
//  printf("testl: %d \n", lodgep[0].delcnt); 
// TODO: trial function passing in lodges (but lodges is after layers...)
// f[d].l[0].lodges[x].delcnt - pass in both


void reclodge(layers *rec, uint32_t d, uint32_t value, uint32_t layerval, uint32_t R_options){ // pass in the p/layers
  uint32_t x, y, tmpx, tmpxx, lay;
  // tape 0 lower
  for (x=0;x<rec[f[d].masterL[0]].num_lodges;x++){
    if (rec[f[d].masterL[0]].lodges[x].flag==0)
      {
      rec[f[d].masterL[0]].lodges[x].delcnt++;
    if (rec[f[d].masterL[0]].lodges[x].delcnt>=rec[f[d].masterL[0]].lodges[x].offset && (rec[f[d].masterL[0]].lodges[x].delcnt<=(rec[f[d].masterL[0]].lodges[x].offset+rec[f[d].masterL[0]].lodges[x].end-rec[f[d].masterL[0]].lodges[x].start))) {     
      tmpx=rec[f[d].masterL[0]].lodges[x].cnt+rec[f[d].masterL[0]].lodges[x].start;
      if (rec[f[d].masterL[0]].lodges[x].over==0) rec[f[d].masterL[0]].lodges[x].realend=tmpx+1; //**
      
      if (tmpx>rec[f[d].masterL[0]].lodges[x].end) { // now we want final delay before we start again
	rec[f[d].masterL[0]].lodges[x].realend=rec[f[d].masterL[0]].lodges[x].end;
	tmpx=rec[f[d].masterL[0]].lodges[x].start;
	rec[f[d].masterL[0]].lodges[x].cnt=0;
	rec[f[d].masterL[0]].lodges[x].over=1;
	}
      //      tmpxx=overlayx(value, (recordings[d][tmpx]&BOTS), (R_options>>2)&3); 
      //      reclayerlower(tmpxx, tmpx, d);
      printf("write loge %d tmpx %d delcnt %d del %d realend %d\n",x, tmpx, f[d].rl[0].lodges[x].delcnt, f[d].rl[0].lodges[x].delay, f[d].rl[0].lodges[x].realend);
      rec[f[d].masterL[0]].lodges[x].cnt++;
      //      rec[f[d].masterL[0]].lodges[x].reallen++;
    }
        else     {
      printf("del %d\n",f[d].rl[0].lodges[x].delcnt);
    }
      }
    if (rec[f[d].masterL[0]].lodges[x].delcnt>=(rec[f[d].masterL[0]].lodges[x].offset+rec[f[d].masterL[0]].lodges[x].end+rec[f[d].masterL[0]].lodges[x].delay-rec[f[d].masterL[0]].lodges[x].start)) rec[f[d].masterL[0]].lodges[x].delcnt=0;
  }
}

#define LOWVAL 10

// trial add zones on press TODO: still needs some work // also to simulate
uint32_t R_addlodges(uint32_t d, uint32_t V_options, uint32_t R_options, uint32_t inval){
  uint32_t tmp, tmpp, other, tmpx, last;
  static uint32_t in[8]={0,0,0,0, 0,0,0,0};
  static uint32_t entry[8]={0,0,0,0, 0,0,0,0};

  tmp=inval;
  
  if (tmp>LOWVAL) { // start recording
    in[d]=1;
    if (entry[d]==0){
    f[d].rl[f[d].masterL[0]].num_lodges+=1;
    printf("lodges add: total %d\n", f[d].rl[f[d].masterL[0]].num_lodges);
    if (f[d].rl[f[d].masterL[0]].num_lodges>MAXLODGE) f[d].rl[f[d].masterL[0]].num_lodges=1;
    if (f[d].rl[f[d].masterL[0]].num_lodges==1){ // first lodge
      printf("first");
      f[d].rl[f[d].masterL[0]].lodges[0].cnt=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delcnt=0;
      //      f[d].rl[f[d].masterL[0]].lodges[0].start=0;
      f[d].rl[f[d].masterL[0]].lodges[0].offset=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delay=0; // looping???
      f[d].rl[f[d].masterL[0]].lodges[0].end=MAXREC;
      //      f[d].rl[f[d].masterL[0]].lodges[0].flag=1;
    } // first lodge
    else {
      tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].cnt=0;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delcnt=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+1; ;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].start=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+1; 
      f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+1; ; // start right away
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delay=0; // to come later
      f[d].rl[f[d].masterL[0]].lodges[tmpx].end=MAXREC; // to come later
      f[d].rl[f[d].masterL[0]].lodges[tmpx-1].flag=1; // stop the last one TODO: remember to reset
      // but we need to delay the previous until we are done...
      //      f[d].rl[f[d].masterL[0]].lodges[tmpx-1].delay=MAXREC; // so prev will now be delayed // put on hold as we write to the new one
    }
    entry[d]=1;
    } // entry
    reclodge(f[d].rl, d, tmp, tmpp, R_options);
  } // above val
    else {
      // low value but did we leave recording
      if (in[d]==1){ // we were recording so set end point of last one and add all delays
	tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1; // lodge we just left
	//	f[d].rl[f[d].masterL[0]].lodges[tmpx].delcnt=0;
	f[d].rl[f[d].masterL[0]].lodges[tmpx].end=f[d].rl[f[d].masterL[0]].lodges[tmpx].realend;
	//	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend;  // previous end
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[f[d].masterL[0]].lodges[x].delay+=(f[d].rl[f[d].masterL[0]].lodges[tmpx].realend-f[d].rl[f[d].masterL[0]].lodges[tmpx].start+1); // FIX!
	}
	in[d]=0; entry[d]=0;
      }
    }  
  return tmp;
}


// straight add of lodges on each new rec
uint32_t R_addlodgesx(uint32_t d, uint32_t V_options, uint32_t R_options){ // each succesive rec mode adds one zone
  uint32_t tmp, tmpp, other, tmpx;
  if (f[d].entryr==0){ // includes reset now
    // what to reset?    
    //    lastvalue[d]=0;
    f[d].entryr=1;
    f[d].leaver=1;
    f[d].entryd=0;
    //    f[d].ind=0;
    f[d].rl[f[d].masterL[0]].ind=0;
  }
  //  LAYERSWOPR;
  //  tmp=livevalue(d, V_options);
  // CTRL is second value
  //  f[d].ind=1; // recording
  f[d].rl[f[d].masterL[0]].ind=1;

    if (f[d].entryd==0){
    f[d].rl[f[d].masterL[0]].num_lodges+=1;
    if (f[d].rl[f[d].masterL[0]].num_lodges>MAXLODGE) f[d].rl[f[d].masterL[0]].num_lodges=1;
    if (f[d].rl[f[d].masterL[0]].num_lodges==1){ // first lodge
      f[d].rl[f[d].masterL[0]].lodges[0].cnt=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delcnt=0;
      f[d].pl[f[d].masterL[0]].lodges[0].delcntt=0;
      //      f[d].rl[f[d].masterL[0]].lodges[0].start=0;
      f[d].rl[f[d].masterL[0]].lodges[0].offset=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delay=0; // looping???
      f[d].rl[f[d].masterL[0]].lodges[0].end=MAXREC; 
    } // first lodge
    else {
      tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].cnt=0;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delcnt=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+1; // doesn't matter
      f[d].pl[f[d].masterL[0]].lodges[tmpx].delcntt=f[d].pl[f[d].masterL[0]].lodges[tmpx-1].delcntt;
      printf("here x %d delcntt %f \n", tmpx, f[d].pl[f[d].masterL[0]].lodges[tmpx].delcntt);
      f[d].rl[f[d].masterL[0]].lodges[tmpx].start=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend+1; 
      f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+1; // start right away
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delay=0; // to come later
      f[d].rl[f[d].masterL[0]].lodges[tmpx].end=MAXREC; // to come later
      f[d].rl[f[d].masterL[0]].lodges[tmpx-1].flag=1; // stop the last one TODO: remember to reset
    }
    f[d].entryd=1;
    } // entry
    reclodge(f[d].rl, d, tmp, tmpp, R_options);
  return tmp;
}

void R_addlodges_leave(uint32_t d){
  uint32_t tmpx;
  // if we were recording then close it...
      if (    f[d].rl[f[d].masterL[0]].ind==1){ // we were recording so set end point of last one and add all delays
	tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1; // lodge we just left
	f[d].rl[f[d].masterL[0]].lodges[tmpx].end=f[d].rl[f[d].masterL[0]].lodges[tmpx].realend;
	//	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend;  // previous end
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[f[d].masterL[0]].lodges[x].delay+=(f[d].rl[f[d].masterL[0]].lodges[tmpx].realend-f[d].rl[f[d].masterL[0]].lodges[tmpx].start+1); // FIX!
	}
	//	f[d].ind=0;
	f[d].rl[f[d].masterL[0]].ind=0;
      }
      f[d].leaver=0;
}

uint32_t playlodge(float speed1, float speed2, uint32_t d, uint32_t P_options){ // pass in the p/layers
  uint32_t x, y, tmpx, tmpxx, lay;
  uint32_t sample=0;
  // tape 0 lowerP
  for (x=0;x<f[d].pl[f[d].masterL[1]].num_lodges;x++){
    //    printf("here\n");
    if (f[d].pl[f[d].masterL[1]].lodges[x].delcntt>=f[d].pl[f[d].masterL[1]].lodges[x].offset && (f[d].pl[f[d].masterL[1]].lodges[x].delcntt<=(f[d].pl[f[d].masterL[1]].lodges[x].offset+f[d].pl[f[d].masterL[1]].lodges[x].realend-f[d].pl[f[d].masterL[1]].lodges[x].start)-1)) {     
      tmpx=f[d].pl[f[d].masterL[1]].lodges[x].cntt+f[d].pl[f[d].masterL[1]].lodges[x].start;
      f[d].pl[f[d].masterL[1]].lodges[x].cntt+=speed1;

      if (tmpx>((f[d].pl[f[d].masterL[1]].lodges[x].realend-1))) { // now we want final delay before we start again
	tmpx=tmpx-f[d].pl[f[d].masterL[1]].lodges[x].realend;
	//	tmpx=f[d].pl[f[d].masterL[1]].lodges[x].start;
	f[d].pl[f[d].masterL[1]].lodges[x].cntt=tmpx+speed1;
	tmpx=tmpx+f[d].pl[f[d].masterL[1]].lodges[x].start;

      }
      if (tmpx>=MAXREC) tmpx=MAXREC-1;
      //      sample=overlayx(recordings[d][tmpx]&BOTS, sample, (P_options>>5)&3); // deal with overlap
      printf("play: x %d tmpx %d tmpxx %d cntt %f delcntt %f del0 %f start %d end %d delay %d\n", x, tmpx, tmpxx, f[d].pl[f[d].masterL[1]].lodges[x].cntt, f[d].pl[f[d].masterL[1]].lodges[x].delcntt, f[d].pl[f[d].masterL[1]].lodges[0].delcntt, f[d].pl[f[d].masterL[1]].lodges[x].start, f[d].pl[f[d].masterL[1]].lodges[x].realend, f[d].pl[f[d].masterL[1]].lodges[x].delay);
	    
    } //XX
    //    else printf("xxx delcnt0 %f \n", f[d].pl[f[d].masterL[1]].lodges[0].delcntt);
    if (f[d].pl[f[d].masterL[1]].lodges[x].delcntt>=(f[d].pl[f[d].masterL[1]].lodges[x].offset+f[d].pl[f[d].masterL[1]].lodges[x].realend+f[d].pl[f[d].masterL[1]].lodges[x].delay-f[d].pl[f[d].masterL[1]].lodges[x].start)-1) f[d].pl[f[d].masterL[1]].lodges[x].delcntt-=(f[d].pl[f[d].masterL[1]].lodges[x].offset+f[d].pl[f[d].masterL[1]].lodges[x].realend+f[d].pl[f[d].masterL[1]].lodges[x].delay-f[d].pl[f[d].masterL[1]].lodges[x].start);
    else f[d].pl[f[d].masterL[1]].lodges[x].delcntt+=speed1;
  }
  return sample;  
}


uint32_t R_addlodges_silence(uint32_t d, uint32_t V_options, uint32_t R_options, uint32_t val){ // add zones on press and offset is silence
  uint32_t tmp, tmpp, other, tmpx;
  if (f[d].entryr==0){ // includes reset now
    // what to reset?    
    //    lastvalue[d]=0;
    f[d].entryr=1;
    f[d].leaver=1;
    f[d].entryd=0;
    f[d].rl[0].ind=0;
    f[d].rl[1].ind=0;
    f[d].rl[0].rcnt=0;
    f[d].rl[1].rcnt=0;
  }
  
  //  LAYERSWOPR;
  //  tmp=livevalue(d, V_options);
  tmp=val;
  // CTRL is second value
  f[d].rl[f[d].masterL[0]].rcnt++;
  printf("rcnt %d\n",f[d].rl[f[d].masterL[0]].rcnt);
  if (tmp>LOWVAL) { // start recording
    f[d].rl[f[d].masterL[0]].ind=1;
    if (f[d].entryd==0){
    f[d].rl[f[d].masterL[0]].num_lodges+=1;
    if (f[d].rl[f[d].masterL[0]].num_lodges>MAXLODGE) f[d].rl[f[d].masterL[0]].num_lodges=1;
    if (f[d].rl[f[d].masterL[0]].num_lodges==1){ // first lodge
      f[d].rl[f[d].masterL[0]].lodges[0].cnt=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delcnt=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delcntt=0; // this is for when we copy to playzones
      //      f[d].rl[f[d].masterL[0]].lodges[0].start=0;
      f[d].rl[f[d].masterL[0]].lodges[0].offset=0;
      f[d].rl[f[d].masterL[0]].lodges[0].delay=0; // looping???
      f[d].rl[f[d].masterL[0]].lodges[0].flag=0; 
      f[d].rl[f[d].masterL[0]].lodges[0].end=MAXREC; 
    } // first lodge
    else {
      tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].cnt=0;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].flag=0; 
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delcnt=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+1;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].delcntt=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].delcntt;
      f[d].rl[f[d].masterL[0]].lodges[tmpx].start=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend; 
      f[d].rl[f[d].masterL[0]].lodges[tmpx].sil=f[d].rl[f[d].masterL[0]].rcnt;
      printf("sil %d\n",f[d].rl[f[d].masterL[0]].lodges[tmpx].sil);
      //      f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].offset)+f[d].rl[f[d].masterL[0]].rcnt; // add silence if any...
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
      f[d].rl[f[d].masterL[0]].rcnt=0;
      tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1; // lodge we just left
      printf("xtmpx %d\n",tmpx);
      f[d].rl[f[d].masterL[0]].lodges[tmpx].end=f[d].rl[f[d].masterL[0]].lodges[tmpx].realend;
      //if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend;  // previous end
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[f[d].masterL[0]].lodges[x].delay+=(f[d].rl[f[d].masterL[0]].lodges[tmpx].realend-f[d].rl[f[d].masterL[0]].lodges[tmpx].start+1)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil;
	}
	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=((f[d].rl[f[d].masterL[0]].lodges[tmpx-1].offset)+f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil-(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].start); // this is for playback
	f[d].rl[f[d].masterL[0]].ind=0; f[d].entryd=0;
      }
    }  
  return tmp;
}


void main(void){
  int32_t x;
    uint32_t dacc=0, samples[1024];
  // setup list of lodges and test them
  // testing delay DONE
  f[0].rl[0].num_lodges=0;
  /*
  f[0].rl[0].lodges[0].delcnt=0;
  f[0].rl[0].lodges[0].delay=3;
  f[0].rl[0].lodges[0].offset=0;
  f[0].rl[0].lodges[0].delcnt=0;
  f[0].rl[0].lodges[0].cnt=0;
  f[0].rl[0].lodges[0].start=10;
  f[0].rl[0].lodges[0].end=32;
  */
  //      f[0].pl[f[0].masterL[0]].lodges[x].start=f[0].rl[f[0].masterL[0]].lodges[x].start;  
  f[0].masterL[0]=0;
  f[0].masterL[1]=0;  
  f[0].rl[f[0].masterL[0]].lodges[x].start=0;
  
  for (x=0;x<MAXLODGE; x++){
    f[0].rl[0].lodges[x].flag=0;
    f[0].pl[0].lodges[x].delcntt=0.0f;
  }

  for (x=0;x<16;x++){
    R_addlodges_silence(0, 0, 0, x);
  }
  R_addlodges_silence(0, 0, 0, 0);

  /*
  for (x=6;x<19;x++){
    R_addlodges_silence(0, 0, 0, x);
  }
  R_addlodges_silence(0, 0, 0, 0);
  */
  
  //  for (x=0;x<70;x++){
    //  reclodge(0,66,0,0);
  //    reclodgex(f[0].rl[0].lodges, f[0].l[1].lodges, 0, 66, 0, 0);
  //  }

  // test pointer to lodges

  //  zonel *lodgep;
  //  lodgep=f[0].l[0].lodges; // can be passed in - but need to pass both layers
  //  printf("testl: %d \n", lodgep[0].delcnt); 
// TODO: trial function passing in lodges (but lodges is after layers...)
// f[d].l[0].lodges[x].delcnt - pass in both
  
  // TODO: test adding to playlist - or new playlist scheme of zones///
    //uint32_t playlodge(layers *play, layers *tousel, float speed1, float speed2, uint32_t d, uint32_t P_options){ // pass in the p/layers
  /*
    for (x=0;x<13;x++){
      playlodge(f[0].pl, f[0].rl, 1.0f, 1.0f, 0, 0);      
  }
  */
    // add
  /*
  for (x=0;x<20;x++){
    R_addlodges_silence(0, 0, 0, x);
  }
  R_addlodges_silence(0, 0, 0, 0);
  */
  
    for (x=0;x<f[0].rl[f[0].masterL[0]].num_lodges;x++){
      printf("no: %d offset: %d start: %d end: %d delay: %d flag %d fulldel %d \n", x, f[0].rl[f[0].masterL[0]].lodges[x].offset, f[0].rl[f[0].masterL[0]].lodges[x].start, f[0].rl[f[0].masterL[0]].lodges[x].end, f[0].rl[f[0].masterL[0]].lodges[x].delay,   f[0].rl[0].lodges[x].flag, (f[0].rl[f[0].masterL[0]].lodges[x].offset+f[0].rl[f[0].masterL[0]].lodges[x].realend+f[0].rl[f[0].masterL[0]].lodges[x].delay-f[0].rl[f[0].masterL[0]].lodges[x].start));
  }
  
  
  // why that works depending on where we enter???
  //  f[0].rl[f[0].masterL[1]].lodges[0].delay+=5; // length of 1
  //    f[0].rl[f[0].masterL[1]].lodges[1].delay+=5;
  //  f[0].pl[f[0].masterL[1]].lodges[0].cntt-=5;

    

  // reset
    /*
  for (x=0;x<3;x++){
    f[0].pl[f[0].masterL[1]].lodges[x].delcntt=0;
    f[0].pl[f[0].masterL[1]].lodges[x].cntt=0;
  }
*/

    // copy in and play...

        f[0].pl[f[0].masterL[1]].num_lodges=f[0].rl[f[0].masterL[1]].num_lodges;
    for (x=0;x<f[0].rl[f[0].masterL[1]].num_lodges;x++){
      f[0].pl[f[0].masterL[1]].lodges[x].delcntt=f[0].rl[f[0].masterL[0]].lodges[x].delcntt;
      f[0].pl[f[0].masterL[1]].lodges[x].offset=f[0].rl[f[0].masterL[0]].lodges[x].offset;
      f[0].pl[f[0].masterL[1]].lodges[x].delay=f[0].rl[f[0].masterL[0]].lodges[x].delay;
      f[0].pl[f[0].masterL[1]].lodges[x].start=f[0].rl[f[0].masterL[0]].lodges[x].start;
      f[0].pl[f[0].masterL[1]].lodges[x].realend=f[0].rl[f[0].masterL[0]].lodges[x].realend;
    }
    
    for (x=0;x<20;x++){
      playlodge(1.0f, 1.0f, 0, 0);      
  }


      for (x=0;x<32;x++){
    R_addlodges_silence(0, 0, 0, x);
  }
  R_addlodges_silence(0, 0, 0, 0);

        for (x=0;x<32;x++){
    R_addlodges_silence(0, 0, 0, x);
  }
  R_addlodges_silence(0, 0, 0, 0);

    // copy in and play...

        f[0].pl[f[0].masterL[1]].num_lodges=f[0].rl[f[0].masterL[1]].num_lodges;
    for (x=0;x<f[0].rl[f[0].masterL[1]].num_lodges;x++){
      f[0].pl[f[0].masterL[0]].lodges[x].delcntt=f[0].rl[f[0].masterL[0]].lodges[x].delcntt;
      f[0].pl[f[0].masterL[0]].lodges[x].offset=f[0].rl[f[0].masterL[0]].lodges[x].offset;
      f[0].pl[f[0].masterL[0]].lodges[x].delay=f[0].rl[f[0].masterL[0]].lodges[x].delay;
      f[0].pl[f[0].masterL[0]].lodges[x].start=f[0].rl[f[0].masterL[0]].lodges[x].start;
      f[0].pl[f[0].masterL[0]].lodges[x].realend=f[0].rl[f[0].masterL[0]].lodges[x].realend;
    }

    for (x=0;x<f[0].rl[f[0].masterL[0]].num_lodges;x++){
      printf("no: %d offset: %d start: %d end: %d delay: %d flag %d fulldel %d \n", x, f[0].rl[f[0].masterL[0]].lodges[x].offset, f[0].rl[f[0].masterL[0]].lodges[x].start, f[0].rl[f[0].masterL[0]].lodges[x].end, f[0].rl[f[0].masterL[0]].lodges[x].delay,   f[0].rl[0].lodges[x].flag,  (f[0].rl[f[0].masterL[0]].lodges[x].offset+f[0].rl[f[0].masterL[0]].lodges[x].realend+f[0].rl[f[0].masterL[0]].lodges[x].delay-f[0].rl[f[0].masterL[0]].lodges[x].start));
  }

    

    for (x=0;x<400;x++){
      playlodge(2.0f, 1.0f, 0, 0);      
  }

     
}
