typedef struct zonel_ { 
  uint32_t start;
  uint32_t length;
  uint32_t end; // loop point
  uint32_t cnt;
  uint32_t rcnt;
} zonel;

typedef struct layers_ {
  float play_cnt;
  float cnt; // for new speedsample
  zonel lodges[5]; // each layer has list of zones/lodges to record to
  uint32_t num_lodges;
} layers;

    typedef struct listy_ { 
      uint32_t start;
      uint32_t length;
      uint32_t end;
      uint32_t l; // layer
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
      uint32_t minormode[4]; // these are for each state!
      uint32_t majormode[4]; // these are now also for each state!
      uint32_t playspeed; // index into speed arrays
      uint32_t toggle, ttoggle;
      layers l[2]; // rec layers count and functions for access
      playl playlist[PLAYFULLY+1];// list of playbacks
      uint32_t playcnt; // for index into playlist as we play
      uint32_t playcntr; // for index into playlist as we add to it
      uint32_t playfull; // how many elements in the playlist
      uint32_t lastmode;
      uint32_t play,rec;
      uint32_t sensi;
      uint32_t entryn, entryp, entryr, entryrp; // for resets
      uint32_t leavep; // for adding to playlist when we leave P
      uint32_t rpp; // for state in always recording mode
      uint32_t playlistm; // if we are adding to the playlist
      uint32_t playlistp; // if we are playing the playlist
    } hands;

static hands f[8];

// so playlist is: playlist which has start, length, layer, playfull which is number of elements and playcnt which is our counter into these
