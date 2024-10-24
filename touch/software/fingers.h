#define MAXLODGE 24

typedef struct zonelr_ { 
  uint32_t start;
  uint32_t end; // loop point NOW
  uint32_t realend; // where we ended - if overlap then is end??? used in R and P
  uint32_t length;
  uint32_t lengthr; // desired length
  uint32_t flag; // used in R
  uint32_t offset;
  uint32_t added;
  uint32_t delay;
  uint32_t sil; // used in R
  uint32_t delcnt;
  float delcntt;
  uint32_t over;
  uint32_t bouncefrom; // lowest bit can be layer, rest is zone?
  uint32_t linkage; // linking to other layer
  uint32_t (*function)(uint32_t value);
} zonelr;

typedef struct zonelp_ { 
  uint32_t start;
  uint32_t end; // loop point
  uint32_t length;
  uint32_t realend; // where we ended - if overlap then is end??? used in R and P
  uint32_t offset;
  uint32_t added;
  uint32_t delay;
  uint32_t speedfrom; // lowest bit can be layer, rest is zone?
  uint32_t currentval;
  float delcnt;
  float delcntt;
  uint32_t linkage; // linking to other layer
  uint32_t (*function)(uint32_t value);
} zonelp;


typedef struct layersR_ {
  zonelr lodges[MAXLODGE]; // each layer has list of zones/lodges to record to // maybe sepera1te lodges from playback... why??? // 12 lodges - we need more
  uint32_t num_lodges;
  uint32_t rcnt;
  uint32_t ind; // we are in the layer
} layersr;

typedef struct layersP_ {
  zonelp lodges[MAXLODGE]; // each layer has list of zones/lodges to record to // maybe sepera1te lodges from playback... why??? // 12 lodges - we need more
  uint32_t num_lodges;
  uint32_t rcnt;
} layersp;

    enum STATE {
      NR,
      RP
    };

    typedef struct xx_ {
      enum STATE state; 
      uint32_t active, play, rec;
      uint32_t masterL[2]; // current layer 
      uint32_t majormode[2]; // these are now also for each state!
      uint32_t minormode[2][2]; // these are for each state! and for each layer
      uint32_t playspeed[2]; // index into speed arrays
      uint32_t ttoggle;
      layersr rl[2]; // rec layers 
      layersp pl[2]; // play layers // now we have 2 sets of layers with the lodges/zones
      uint32_t sensi;
      uint32_t entryr, entryrp; // for resets
      uint32_t leavep; // for function for leaving P mode
      uint32_t leaverr; // leaving R mode
      uint32_t leaverp;
      uint32_t entryd[2];
    } hands;

static hands f[8];

// so playlist is: playlist which has start, length, layer, playfull which is number of elements and playcnt which is our counter into these
