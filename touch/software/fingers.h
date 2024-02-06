typedef struct layers_ {
  uint32_t rec_cnt;
  uint32_t rec_end;
  uint32_t play_cnt;
  uint32_t play_len;
  uint32_t (*speedsamp)(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples);
  void (*reclayer)(uint32_t value, uint32_t dacccount); // to add these
} layers;

    typedef struct listy_ { 
      uint32_t start;  
      uint32_t length;
      uint8_t layer;
    } playl;

    enum STATE {
      N,
      R,
      P,
      RP
    };

    typedef struct xx_ {
      enum STATE state; 
      uint32_t active;
      uint32_t masterL; // current layer
      uint32_t majormode[4];
      uint32_t minormode[4];
      uint32_t playspeed; // index into playreff
      uint32_t toggle, ttoggle;
      layers layer[2]; // rec layers count and functions for access
      playl playlist[120];// list of playbacks
      uint32_t playcnt; // for play of playlist
      uint32_t playcntr; // for rec of playlist
      uint32_t playfull; // how many elements in the playlist
      uint32_t overlaid; /// how we enter RP
      uint32_t lastmode;
      uint32_t play,rec;
      uint32_t sensi;
      uint32_t entryn, entryp, entryr, entryrp; // for resets
    } hands;

static hands fingers[8];

// so playlist is: playlist which has start, length, layer, playfull which is number of elements and playcnt which is our counter into these
