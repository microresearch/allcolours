#include <unistd.h>   
#include <sys/types.h>                                                          
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <string.h>                                                             
#include <sys/time.h>                                                           
#include <dirent.h>                                                             
#include <limits.h>  
#include <errno.h> 
#include <stdlib.h>
#include <stdio.h>

//static unsigned char buffer[1024*8*1300];

void printbits(unsigned char bitz){
  int x,y;
  unsigned char bitt,cc;
    cc=1;
  for (y=0;y<8;y++){
    if ((bitz&cc)!=0) bitt=1;
    else bitt=0;
    cc=cc<<1;
    //    printf("%d",bitt);
  }
}

#define MAX (1024*1326*8)
#define MAXP (1024*1326)
#define MAXPP (1024*1326/4) // 8x4 =32 bits

unsigned char shifter(unsigned char *buffer){
  int x, tmp, last;
    for (x=0;x<MAX;x++){
      tmp=buffer[x];
      buffer[x]=last;
      last=tmp;
      //      printf("%d", last);
    }
    buffer[0]=last; //cycling
    return last;
  }

int main(void)
{

// read in file test1.bmp and convert to binary array of size x
  char *buffer, *buffer2, *buffer3;

  unsigned char bufferp[MAXP];
  unsigned int bufferx[MAXPP];
  unsigned int bufferxx[MAXPP];
  unsigned int bufferes[MAXPP];
  
  buffer=( char*)malloc(sizeof(  char)*MAX);
  buffer2=( char*)malloc(sizeof(  char)*MAX);
  buffer3=( char*)malloc(sizeof(  char)*MAX);
  
  FILE *sfile;
  int cnt=0, cntt=0;
  unsigned char ch,ff=0;
  int x,y;
  unsigned char bitt,cc;
  unsigned char shift[4]={0,8,16,24};

  sfile=fopen("test2.bmp", "r");

  //  read(sfile,buffer,1);
  
  for (x=0;x<MAXP;x++){
    ch = fgetc(sfile);
    // ch to binary and into array
    //    printbits(ch);
    //    if (x>134){ // skip first
      // bytes into 32 bits
      bufferx[cnt]+=ch<<shift[ff];
      ff++;
      if (ff>3) {
	ff=0;
	cnt++;
      }
    }
  //  }
    
  
  printf("zise %d\n\n", cnt);

  unsigned char last=0, tmp, carry;

  // we need other processes here... small cycles of bits of x length
  // how we can do 4 srs.. diff speeds...x
  /*  
  for (y=0;y<4;y++){  
    shifter(buffer);
  }
  */

  /*
 - we want to shift buffer then enter shifted bit into buffer2, simulate with speeds what we have of entry one into another
 

  unsigned char bitn;
  int speed1=0;
  for (x=0;x<MAX;x++){
    if (y>speed1){
    bitn=shifter(buffer);
    speed1=0;
    }
    speed1++;
  buffer2[0]=buffer2[0]^bitn;
  bitn=shifter(buffer2);
  }
*/ 

  unsigned int shifter[4], shifted, xx;
  unsigned char coynt=0;
  unsigned char speed=4;
  // how to shift one bit right and cycle array
  for (y=0;y<(MAX);y++){ // MAX or MAXP
    if (coynt>speed){
      coynt=0;
  for (x=0;x<MAXPP;x++){
    shifted=(bufferx[x]<<1);
    shifter[0]=(shifted&255) +carry; // bottom byte
    shifter[1]=(shifted>>8)&255;
    shifter[2]=(shifted>>16)&255;
    shifter[3]=(shifted>>24)&255;    
    carry=(bufferx[x]&(1<<31))>>31; // top bit
    bufferx[x]=shifter[0]+(shifter[1]<<8)+(shifter[2]<<16)+(shifter[3]<<24);	  
	  }
    }
    coynt++;
  // bufferxx uses carry
  for (x=0;x<MAXPP;x++){
    shifted=(bufferxx[x]<<1);
    shifter[0]=(shifted&255) +carry; // bottom byte
    shifter[1]=(shifted>>8)&255;
    shifter[2]=(shifted>>16)&255;
    shifter[3]=(shifted>>24)&255;    
    carry=(bufferxx[x]&(1<<31))>>31; // top bit
    bufferxx[x]=shifter[0]+(shifter[1]<<8)+(shifter[2]<<16)+(shifter[3]<<24);	  
	  }
  }
    
  cnt=0; cntt=0;
// convert back to file and save as test2

  for (x=0;x<MAXPP;x++){
      // get four bits out
      for (y=0;y<4;y++){
	tmp=(bufferxx[x]>>shift[y])&255;
	bufferp[cnt]=tmp;
	cnt++;
      //printf("%d ", tmp);
      }
    }

    // open test2, save file
    
    FILE *ssfile;
    ssfile=fopen("test2", "w");

    for (x=0;x<MAXP;x++){
      fputc(bufferp[x], ssfile);
    };

    fflush(ssfile);
    
  // Closing the file
  fclose(sfile);
  fclose(ssfile);

  
}
