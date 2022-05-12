typedef struct heavens_ { // fill out with trigger, routes, types, bits and other attributes,,,
  uint32_t trigger;  
  uint32_t adctype, adcpar;
  uint32_t dactype, dacpar;
  uint32_t Gshift_[9];
  uint32_t Gshare_;
  uint32_t shift_;
  uint32_t gshift_;
  uint32_t extrashift_;
  uint32_t lastdac; // speed stuff
  uint32_t dac;
  int32_t route;
  float time_now;
  uint32_t lastest;
  float alpha;
  long last_time;
  long int_time;
  uint32_t delay[512]; // 128x32 bits=4096 // 512=16384
  uint32_t delcnt;
  uint32_t paramx; // for param holds - could be more than one param...
  uint32_t changed;
  uint32_t reset[4];
  int32_t gsrcnt[4];
  uint32_t latch;
  uint32_t index;
} heavens;

typedef struct modes_ { // what we need: function, strobey, interpoll, inner_function?, detach?, 
  uint32_t strobey;
  uint32_t interpoll;
  uint32_t detachlen;
  uint32_t detachspeed;
  void (*func)(uint8_t w, uint32_t strobey, uint32_t detachlen, uint32_t  detachspeed, uint32_t interpoll, uint32_t (*innerfunc)(uint8_t w));
  uint32_t (*innerfunc)(uint8_t w);
} modez; 
