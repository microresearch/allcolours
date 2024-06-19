#define MAXLODGE 24

typedef struct zonel_ { 
  uint32_t start;
  uint32_t end; // loop point
  uint32_t realend; // where we ended - if overlap then is end???
  //  uint32_t reallen;
  uint32_t flag;
  uint32_t cnt;
  uint32_t over; // overrun - need to reset this at some point
  uint32_t offset;
  uint32_t delay;
  uint32_t sil;
  uint32_t delcnt;
  float cntt; // for playback fractions
  float delcntt;
  float speed;
  uint32_t linkage; // linking to other layer
} zonel;

typedef struct layers_ {
  zonel lodges[MAXLODGE]; // each layer has list of zones/lodges to record to // maybe sepera1te lodges from playback... why??? // 12 lodges - we need more
  uint32_t num_lodges;
  uint32_t rcnt;
  uint32_t ind; // in the layer
} layers;

    enum STATE {
      N,
      R,
      P,
      RP
    };

    typedef struct xx_ {
      enum STATE state; 
      uint32_t active;
      uint32_t masterLP; // current layer - but can also be for R and P
      uint32_t masterLR; // current layer - but can also be for R and P
      uint32_t minormode[4]; // these are for each state!
      uint32_t majormode[4]; // these are now also for each state!
      uint32_t playspeed; // index into speed arrays
      uint32_t toggle, ttoggle;
      layers rl[2]; // rec layers 
      layers pl[2]; // play layers // now we have 2 sets of layers with the lodges/zones
      uint32_t lastmode;
      uint32_t play,rec;
      uint32_t sensi;
      uint32_t entryn, entryp, entryr, entryrp; // for resets
      uint32_t leavep; // for function for leaving P mode
      uint32_t leaver; // leaving R mode
      uint32_t leaverp;
      uint32_t entryd;
    } hands;

static hands f[8];

// so playlist is: playlist which has start, length, layer, playfull which is number of elements and playcnt which is our counter into these
