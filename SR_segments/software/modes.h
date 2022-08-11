typedef struct stack_ {
  uint32_t (*speedfrom)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t* speedcv1;
  uint32_t* speedcv2;
  uint32_t (*bit)(uint32_t depth, uint32_t in, uint32_t wh);
  uint32_t* bitcv1;
  uint32_t* bitcv2;
  uint32_t* lencv;
  uint32_t bitindexy; // bit index for reference
  uint32_t speedindexy; // speed index
} stack;

// what can be removed from here?
typedef struct heavens_ { // fill out with trigger, routes, types, bits and other attributes,,,
  uint32_t trigger;
  uint32_t flip;
  uint32_t strobed; // set this when we need fake strobe...  
  uint32_t adctype, adcpar;
  uint32_t dactype, dacpar;
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
  uint32_t delay[512]; // 128x32 bits=4096 // 512=16384
  uint32_t changed;
  uint32_t reset[4];
  int32_t gsrcnt[4];
  uint32_t latch;
  uint32_t route;
  uint32_t index;
  uint32_t lastspeed;
  uint32_t countspeed;
  //  uint32_t (*bit[64])(uint32_t depth, uint32_t in, uint32_t wh);
  //  uint32_t (*speedfrom[64])(uint32_t depth, uint32_t in, uint32_t wh);
  //  stack stacky[64]; // full stack
  uint32_t stackindex;
  uint32_t matrix[13];
  uint32_t *matrixp[13];
  void (*inner)(uint32_t w);
} heavens;

typedef struct modes_ { // what we need: function, strobey, interpoll, inner_function?, detach?, 
  uint32_t strobey;
  uint32_t interpoll;
  //  uint32_t detachlen;
  uint32_t detachspeed;
  void (*func)(uint8_t w, uint32_t strobey, uint32_t detachlen, uint32_t  detachspeed, uint32_t interpoll, uint32_t (*innerfunc)(uint8_t w));
  uint32_t (*innerfunc)(uint8_t w);
} modez; 
