// think all here is needed so far////
typedef struct heavens_ { 
  uint32_t trigger;
  uint32_t flip;
  uint32_t strobed; // set this when we need fake strobe...  
  uint32_t Gshift_[9];
  uint32_t localGSR[9];
  uint32_t Gshare_;
  uint32_t shift_;
  uint32_t gshift_;
  uint32_t dac;
  uint32_t lastest;
  float alpha;
  long last_time;
  long int_time;
  float time_now;
  float time_nowp;
  long last_timep;
  long int_timep;
  float time_nowx;
  long last_timex;
  long int_timex;
  float time_nowxx;
  long last_timexx;
  long int_timexx;
  uint32_t changed;
  uint32_t reset[9];
  int32_t gsrcnt[9];
  uint32_t route;
  uint32_t interp;
  uint32_t theroute;
  uint32_t altroute;
  uint32_t routetype;
  uint32_t lastspeed;
  uint32_t countspeed;
  uint32_t matrix[23];
  uint32_t matrixX[23];
  uint32_t *matrixp[23]; // +1 for reset
  uint32_t *matrixpG[23];
  uint32_t offset[23];
  uint32_t oldgap[16]; // 16 layers
  float *logspeed; 
  float lowest;
  void (*inner)(uint32_t w);
  uint32_t (**funcbit)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t *depths; // which use depths
  uint32_t extent; // for >><< of the funcbit array...  
  uint32_t (**str_funcbit)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t *str_depths; // which use depths
  uint32_t str_extent; // for >><< of the funcbit array...  
} heavens;

