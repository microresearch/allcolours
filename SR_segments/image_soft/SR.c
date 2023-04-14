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

// was 1024*1326

#define MAX (276872*8)
#define MAXP (276872)


unsigned char shifter(unsigned char *buffer, unsigned char *orig){
  int x, tmp, last;
    for (x=0;x<MAX;x++){
      tmp=buffer[x];
      buffer[x]=last;//^orig[x];
      last=tmp;
      //      printf("%d", last);
    }
    buffer[0]=last; //cycling

    for (x=0;x<MAX;x++){
      orig[x]=buffer[x];
    }
    return last;
  }

int main(void)
{

// read in file test1.bmp and convert to binary array of size x
  char *buffer, *buffer2, *buffer3;

  unsigned char bufferp[MAXP];

  buffer=( char*)malloc(sizeof(  char)*MAX);
  buffer2=( char*)malloc(sizeof(  char)*MAX);
  buffer3=( char*)malloc(sizeof(  char)*MAX);
  
  FILE *sfile;
  int cnt=0, cntt=0;
  unsigned char ch;
  int x,y;
  unsigned char bitt,cc;


  sfile=fopen("test.wav", "r");

  //  read(sfile,buffer,1);
  
  for (x=0;x<MAXP;x++){
    ch = fgetc(sfile);
    // ch to binary and into array
    //    printbits(ch);
    //    if (x>134){
    cc=1;
    for (y=0;y<8;y++){ // lowest bit first
      if ((ch&(1<<y))==(1<<y)) bitt=1;
      else bitt=0;
      buffer[cnt]=bitt;
      buffer2[cnt++]=bitt;
      cc=cc<<1;
      //    }
    }
  }
  
  printf("zise %d\n\n", cnt);

  unsigned char last=0, tmp, carry;

  // we need other processes here... small cycles of bits of x length
  // how we can do 4 srs.. diff speeds...x
    
    for (y=0;y<3;y++){  
    shifter(buffer, buffer2);
  }
  
  /*
 - we want to shift buffer then enter shifted bit into buffer2, simulate with speeds what we have of entry one into another
   */
  unsigned char bitn;
  int speed1=0;
  /*
  for (x=0;x<MAX;x++){
    //    printf("round %d \n",x);
    if (y>speed1){
    bitn=shifter(buffer);
    y=0;
    }
    y++;
  buffer2[0]=buffer2[0]^bitn;
  bitn=shifter(buffer2);
  }
  */  

  cnt=0; cntt=0;
// convert back to file and save as test2
    for (x=0;x<MAXP;x++){
      tmp=0;
      for (y=0;y<8;y++){ // lowest bit first ???
	if (buffer[cntt++]&1) tmp+=(1<<y);
      }
      bufferp[x]=tmp;      
      //printf("%d ", tmp);
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
