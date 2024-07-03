#include "stdio.h"
#include <time.h>
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "resources.h"
#define PLAYFULLY 119 // length of playlist in fingers.h
#include "fingers.h"

//gcc test4.c -otest -lm -std=gnu99

#define MAXREC 1280
#define LOWVAL 10

// add in _silence, playlodge and reclodge

uint32_t lastvalue[8], real[8];

inline static float mod0(float value, uint32_t length)
{
  while ((int)value > (length-1)){
        value -= length;
	//	printf("val %f length %d\n", value, length);
  }
    return value;
}


void reclodge(layers *rec, uint32_t d, uint32_t value, uint32_t layerval, uint32_t R_options){ // pass in the p/layers
  uint32_t x, y, tmpx, tmpxx, swoptype;
  //  swoptype=(R_options[0]|R_options[1])&1;
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
	printf("x %d tmpx %d\n", x, tmpx);      
      if (rec[0].lodges[x].over==0) rec[0].lodges[x].realend=tmpx; //**
      else rec[0].lodges[x].overcnt=tmpx;

      if (swoptype=0){ // swop values only
	if (f[d].masterL[0]==0){
	  //	tmpxx=overlayx(value, (recordings[d][tmpx]&TOP), (R_options[0])&3);
      }
	      else {
		//	tmpxx=overlayx(layerval, (recordings[d][tmpx]&TOP), (R_options[0])&3);
	      }	
	//       reclayerlower(tmpxx, tmpx, d);
      }
      else { // swop layers
	if (f[d].masterL[0]==0){
	  //	tmpxx=overlayx(value, (recordings[d][tmpx]&TOP), (R_options[0])&3);
	  //	reclayerlower(tmpxx, tmpx, d);
	}
	else {
	  //	  tmpxx=overlayx(value, (recordings[d][tmpx]>>16), (R_options[0])&3); // fixed
	  //	  reclayerupper(tmpxx, tmpx, d); 
	}
      }
      }   
      rec[0].lodges[x].delcnt+=1;
      if (rec[0].lodges[x].delcnt>=(rec[0].lodges[x].offset+rec[0].lodges[x].end+rec[0].lodges[x].delay-rec[0].lodges[x].start)){
	if (rec[0].lodges[x].delcnt>MAXREC){
	  rec[0].lodges[x].realend=MAXREC;
	  rec[0].lodges[x].over=1;
	}
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
      
      if (rec[1].lodges[x].over==0) rec[1].lodges[x].realend=tmpx; //**
      else rec[1].lodges[x].overcnt=tmpx;

      if (swoptype=0){ // swop values only
	if (f[d].masterL[0]==0){
	  //	  tmpxx=overlayx(layerval, (recordings[d][tmpx]>>16), (R_options[1])&3); // fixed
	}
	else {
	  //	  tmpxx=overlayx(value, (recordings[d][tmpx]>>16), (R_options[1])&3); // fixed
	      }	
	//	reclayerupper(tmpxx, tmpx, d);
      }
      else { // swop layers
	if (f[d].masterL[0]==0){
	  //	  tmpxx=overlayx(layerval, (recordings[d][tmpx]>>16), (R_options[1])&3); // fixed
	  //	  reclayerupper(tmpxx, tmpx, d); 
	}
	else {
	  //	  tmpxx=overlayx(layerval, (recordings[d][tmpx]&TOP), (R_options[1])&3); // fixed
	  //	  reclayerlower(tmpxx, tmpx, d); 
	}
      }
      }   
      rec[1].lodges[x].delcnt+=1;
      if (rec[1].lodges[x].delcnt>=(rec[1].lodges[x].offset+rec[1].lodges[x].end+rec[1].lodges[x].delay-rec[1].lodges[x].start)){
	if (rec[1].lodges[x].delcnt>MAXREC){
	  rec[1].lodges[x].realend=MAXREC;
	  rec[1].lodges[x].over=1;
	}
	rec[1].lodges[x].delcnt=0;  
      }
    }
  }
}

void playlodge(float speed1, float speed2, uint32_t d, uint32_t P_options, uint32_t* res){ // pass in the p/layers // pass out via res our 2 values
  uint32_t x, y, tmpx, tmpxx, lay;
  uint32_t sample[2]={0,0};
  /// first layer
  for (x=0;x<f[d].pl[0].num_lodges;x++){
    f[d].pl[0].lodges[x].delcntt=mod0(f[d].pl[0].lodges[x].delcntt+speed1, (f[d].pl[0].lodges[x].offset+f[d].pl[0].lodges[x].realend+f[d].pl[0].lodges[x].delay-f[d].pl[0].lodges[x].start));
  }
  
    for (x=0;x<f[d].pl[0].num_lodges;x++){
      if (f[d].pl[0].lodges[x].delcntt>=f[d].pl[0].lodges[x].offset && (f[d].pl[0].lodges[x].delcntt<=(f[d].pl[0].lodges[x].offset+f[d].pl[0].lodges[x].realend-f[d].pl[0].lodges[x].start))) {     // ***

	if (f[d].pl[0].lodges[x].offset>=(f[d].pl[0].lodges[x].offset-f[d].pl[0].lodges[x].start)){
	    tmpx=((f[d].pl[0].lodges[x].delcntt)-(f[d].pl[0].lodges[x].offset-f[d].pl[0].lodges[x].start));
	  }
	  else {
	    tmpx=((f[d].pl[0].lodges[x].delcntt)+(f[d].pl[0].lodges[x].start-f[d].pl[0].lodges[x].offset));
	  }
	
	if (tmpx>=MAXREC) tmpx=MAXREC-1;
	//	sample[0]=overlayx(recordings[d][tmpx]&TOP, sample[0], (P_options[0]>>5)&3); // deal with overlap of zones in one layer DONE
            }
    }
    // second layer:
  for (x=0;x<f[d].pl[1].num_lodges;x++){
    f[d].pl[1].lodges[x].delcntt=mod0(f[d].pl[1].lodges[x].delcntt+speed1, (f[d].pl[1].lodges[x].offset+f[d].pl[1].lodges[x].realend+f[d].pl[1].lodges[x].delay-f[d].pl[1].lodges[x].start));
  }
  
    for (x=0;x<f[d].pl[1].num_lodges;x++){
      if (f[d].pl[1].lodges[x].delcntt>=f[d].pl[1].lodges[x].offset && (f[d].pl[1].lodges[x].delcntt<=(f[d].pl[1].lodges[x].offset+f[d].pl[1].lodges[x].realend-f[d].pl[1].lodges[x].start))) {     // ***

	if (f[d].pl[1].lodges[x].offset>=(f[d].pl[1].lodges[x].offset-f[d].pl[1].lodges[x].start)){
	    tmpx=((f[d].pl[1].lodges[x].delcntt)-(f[d].pl[1].lodges[x].offset-f[d].pl[1].lodges[x].start));
	  }
	  else {
	    tmpx=((f[d].pl[1].lodges[x].delcntt)+(f[d].pl[1].lodges[x].start-f[d].pl[1].lodges[x].offset));
	  }
	
	if (tmpx>=MAXREC) tmpx=MAXREC-1;
	//	sample[1]=overlayx(recordings[d][tmpx]>>16, sample[1], (P_options[1]>>5)&3); // top layer
            }
    }

    if (f[d].masterL[1]==0){
    res[0]=sample[0];
    res[1]=sample[1];
    }
    else {
    res[1]=sample[0];
    res[0]=sample[1];
    }
}


// TODO: needs two layers???
uint32_t R_addlodges_silence(uint32_t d, uint32_t V_options, uint32_t R_options, uint32_t tmp){ // add zones on press and offset is silence
  uint32_t tmpp, other, tmpx;
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
  
  //  LAYERSWOPR;
  //  tmp=real[d];
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
      f[d].rl[f[d].masterL[0]].lodges[0].offset=0;//f[d].rl[f[d].masterL[0]].rcnt; as we start recording now
      f[d].rl[f[d].masterL[0]].lodges[0].delay=0; // looping???
      f[d].rl[f[d].masterL[0]].lodges[0].flag=0;
      f[d].rl[f[d].masterL[0]].lodges[0].sil=f[d].rl[f[d].masterL[0]].rcnt;
      printf("sil %d\n", f[d].rl[f[d].masterL[0]].lodges[0].sil);
      f[d].rl[f[d].masterL[0]].rcnt=0;
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
    //    printf("aqui\n");
        reclodge(f[d].rl, d, tmp, tmpp, R_options);
  } // above val
  else { 
    // low value but did we leave recording
    // in our test code we never enter
    if (f[d].rl[f[d].masterL[0]].ind==1){ // we were recording so set end point of last one and add all delays
    printf("leave\n");
      tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1; // lodge we just left
      //      f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=((f[d].rl[f[d].masterL[0]].lodges[tmpx-1].offset)+f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil-(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].start); 
      f[d].rl[f[d].masterL[0]].lodges[tmpx].end=f[d].rl[f[d].masterL[0]].lodges[tmpx].realend;
	//	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend;  // previous end
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[f[d].masterL[0]].lodges[x].delay+=(f[d].rl[f[d].masterL[0]].lodges[tmpx].realend-f[d].rl[f[d].masterL[0]].lodges[tmpx].start+1)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil;
	  if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil-(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].start); 
	  else f[d].rl[f[d].masterL[0]].lodges[0].offset=f[d].rl[f[d].masterL[0]].lodges[0].sil;
	  
	f[d].rl[f[d].masterL[0]].ind=0; f[d].entryd=0;
	f[d].rl[f[d].masterL[0]].rcnt=0;
	}
    }
  }
  return tmp;
}

void R_addlodges_leave_silence(uint32_t d){
  uint32_t tmpx;
  // if we were recording then close it...
      if (f[d].rl[f[d].masterL[0]].ind==1){ // we were recording so set end point of last one and add all delays
	tmpx=f[d].rl[f[d].masterL[0]].num_lodges-1; // lodge we just left
	f[d].rl[f[d].masterL[0]].lodges[tmpx].end=f[d].rl[f[d].masterL[0]].lodges[tmpx].realend;
	//	f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=((f[d].rl[f[d].masterL[0]].lodges[tmpx-1].offset)+f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil-(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].start); 
	//	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend;  // previous end
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[f[d].masterL[0]].lodges[x].delay+=(f[d].rl[f[d].masterL[0]].lodges[tmpx].realend-f[d].rl[f[d].masterL[0]].lodges[tmpx].start+1); // FIXed!
	}
	if (tmpx!=0) f[d].rl[f[d].masterL[0]].lodges[tmpx].offset=(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].realend)+f[d].rl[f[d].masterL[0]].lodges[tmpx].sil-(f[d].rl[f[d].masterL[0]].lodges[tmpx-1].start);
		else f[d].rl[f[d].masterL[0]].lodges[0].offset=f[d].rl[f[d].masterL[0]].lodges[0].sil;
	f[d].rl[f[d].masterL[0]].ind=0;
      }
      f[d].leaver=0;
}


void main(void){
  int32_t x;

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
  ////////////
  f[0].entryd=0;  
  for (x=0;x<20;x++){
    R_addlodges_silence(0, 0, 0, x);
  }
  //  R_addlodges_silence(0, 0, 0, 0);
  f[0].entryd=0;

  R_addlodges_leave_silence(0);
  
  for (x=0;x<20;x++){
    R_addlodges_silence(0, 0, 0, x);
  }
  f[0].entryd=0;
  R_addlodges_leave_silence(0);

  
    for (x=0;x<f[0].rl[f[0].masterL[0]].num_lodges;x++){
      printf("no: %d offset: %d start: %d realend: %d delay: %d flag %d fulldel %d \n", x, f[0].rl[f[0].masterL[0]].lodges[x].offset, f[0].rl[f[0].masterL[0]].lodges[x].start, f[0].rl[f[0].masterL[0]].lodges[x].realend, f[0].rl[f[0].masterL[0]].lodges[x].delay,   f[0].rl[0].lodges[x].flag, (f[0].rl[f[0].masterL[0]].lodges[x].offset+f[0].rl[f[0].masterL[0]].lodges[x].realend+f[0].rl[f[0].masterL[0]].lodges[x].delay-f[0].rl[f[0].masterL[0]].lodges[x].start));
  }

  
}
