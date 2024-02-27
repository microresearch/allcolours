typedef struct layers_ {
  uint32_t rec_cnt;
  uint32_t rec_end;
  uint32_t rec_start;
  uint32_t rec_otherend;
  uint32_t overend;
  uint32_t overendd;
  float spdd;
  float play_cnt;
  uint32_t play_len;
  uint32_t othercnt; // running playlists
  float cnt; // for new speedsample
  uint32_t (*speedsamp[4])(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples);
  void (*reclayer)(uint32_t value, uint32_t dacccount); // to add these
  uint32_t (*accessreclayer)(uint32_t daccount);
  uint32_t (*accessplaylayer)(uint32_t daccount);
} layers;

    typedef struct listy_ { 
      uint32_t start;  
      uint32_t length;
      uint32_t layer;
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
      uint32_t majormode; 
      uint32_t minormode[4]; // these are for each state!
      uint32_t playspeed; // index into playreff
      uint32_t toggle, ttoggle;
      layers layer[2]; // rec layers count and functions for access
      playl playlist[PLAYFULLY+1];// list of playbacks
      uint32_t playcnt; // for play of playlist
      uint32_t playcntr; // for rec of playlist
      uint32_t playfull; // how many elements in the playlist
      uint32_t overlaid; /// how we enter RP
      uint32_t lastmode;
      uint32_t play,rec;
      uint32_t sensi;
      uint32_t entryn, entryp, entryr, entryrp; // for resets
      uint32_t leavep; // for adding to playlist when we leave P
      uint32_t rpp; // for state in always rec mode
    } hands;

static hands fingers[8];

// so playlist is: playlist which has start, length, layer, playfull which is number of elements and playcnt which is our counter into these
