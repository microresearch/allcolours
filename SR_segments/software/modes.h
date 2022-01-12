typedef struct heavens_ { // fill out with trigger, routes, types, bits and other attributes,,,
  uint32_t trigger;  
  uint32_t adctype, adcpar;
  uint32_t dactype, dacpar;
  uint32_t Gshift_[4];
  uint32_t shift_;
  uint32_t lastdac; // speed stuff
  uint32_t dac;
  float time_now;
  long last_time;
  long int_time;
} heavens;


