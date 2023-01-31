// think all here is needed so far////
typedef struct heavens_ { 
  uint32_t trigger;
  uint32_t flip;
  uint32_t strobed; // set this when we need fake strobe...  
  //  uint32_t adctype, adcpar;
  //  uint32_t dactype, dacpar;
  uint32_t Gshift_[9];
  uint32_t localGSR[9];
  uint32_t Gshare_;
  uint32_t shift_;
  uint32_t gshift_;
  uint32_t extrashift_;
  uint32_t dac;
  float time_now;
  uint32_t lastest;
  float alpha;
  long last_time;
  long int_time;
  //uint32_t delay[512]; // 128x32 bits=4096 // 512=16384
  uint32_t changed;
  uint32_t reset[9];
  int32_t gsrcnt[9];
  uint32_t route;
  uint32_t interp;
  uint32_t in;
  uint32_t fake; // fake trigger
  uint32_t globflag; // global or local route!
  uint32_t theroute;
  uint32_t altroute;
  uint32_t routetype;
  uint32_t lastspeed;
  uint32_t countspeed;
  //  uint32_t stackindex;
  uint32_t matrix[18];
  uint32_t *matrixp[18];
  uint32_t *matrixpG[18];
  uint32_t extent; // for >><< of the funcbit array...
  float *logspeed; // poin
  float lowest;
  void (*inner)(uint32_t w);
  uint32_t (**funcbit)(uint32_t depth, uint32_t in, uint32_t wh);
} heavens;

