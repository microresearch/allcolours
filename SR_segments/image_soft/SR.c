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


int main(void)
{

// read in file test1.bmp and convert to binary array of size x
  char *buffer;

#define MAX (1024*1000*8)
#define MAXP (1024*1000)

  unsigned char bufferp[MAXP];
  
  buffer=( char*)malloc(sizeof(  char)*MAX);
  FILE *sfile;
  int cnt=0, cntt=0;
  unsigned char ch;
  int x,y;
  unsigned char bitt,cc;


  sfile=fopen("test2.bmp", "r");

  //  read(sfile,buffer,1);
  
  for (x=0;x<MAXP;x++){
    ch = fgetc(sfile);
    // ch to binary and into array
    //    printbits(ch);
    cc=1;
    for (y=0;y<8;y++){ // lowest bit first
      if ((ch&(1<<y))==(1<<y)) bitt=1;
      else bitt=0;
      buffer[cnt++]=bitt;
      cc=cc<<1;
    }
  }
  
  printf("zise %d\n\n", cnt);

  unsigned char last=0, tmp, carry;

  // we need other processes here... small cycles of bits of x length
  // how we can do 4 srs.. diff speeds...x
  
  for (y=0;y<11;y++){  
// shift left and feed back x times
//    last=0; 
    for (x=0;x<MAX;x++){
      tmp=buffer[x];
      buffer[x]=last;
      last=tmp;
      //      printf("%d", last);
    }
    buffer[0]=last;
  }

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
