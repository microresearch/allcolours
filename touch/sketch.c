// TO FIND PATTERNS

typedef struct layers_ {
  uint32_t rec_cnt;
  uint32_t rec_end;
  uint32_t rec_start;
  uint32_t rec_length;
  uint32_t rec_fraglength;
  float play_cnt;
  uint32_t othercnt; // running playlists
  float cnt; // for new speedsample
  uint32_t (*speedsamp[4])(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples);
  void (*reclayer)(uint32_t value, uint32_t dacccount); // to add these
  uint32_t (*accessreclayer)(uint32_t daccount);
  uint32_t (*accessplaylayer)(uint32_t daccount);
} layers;


//ADC: zooms through start and end (at each press start, next press start) zoom/stop and playback is bounced to other layer... trigger swops layers
tmp=livevalue(d, V_options);
LAYERSWOPRP; 
if (control[whichctrl[d]]>32){ // setting of a zone 
  speed=control[whichctrl[d]]>>2;
  if (f[d].rpp==0) f[d].rpp=1; // set start //rpp is state machine 
  if (f[d].rpp==2) f[d].rpp=3;
  values[d]=f[d].l[f[d].masterL].speedsamp[2](playreff[f[d].playspeed][speed], f[d].l[f[d].masterL].rec_end, 0, f[d].l[f[d].masterL].rec_end, d, recordings[d]);
  if (f[d].rpp==1) { // set the start
    f[d].l[f[d].masterL].rec_start=f[d].l[f[d].masterL].play_cnt;
  }
  else { // set the end
    if (f[d].l[f[d].masterL].play_cnt>f[d].l[f[d].masterL].rec_start) f[d].l[f[d].masterL].rec_length=f[d].l[f[d].masterL].play_cnt-f[d].l[f[d].masterL].rec_start;
    else f[d].l[f[d].masterL].rec_length=(f[d].l[f[d].masterL].rec_end-f[d].l[f[d].masterL].play_cnt)+f[d].l[f[d].masterL].rec_start;
  }
  values[d]=overlay(tmp, values[d], (P_options>>2)&3); 
 }
 else { // control released...
   values[d]=f[d].l[f[d].masterL].speedsamp[2](1.0f, f[d].l[f[d].masterL].rec_length, f[d].l[f[d].masterL].rec_start, f[d].l[f[d].masterL].rec_end, d, recordings[d]);
   values[d]=overlay(tmp, values[d], (P_options>>2)&3); // and write this to other layer
   tmp=values[d];
   autre=f[d].masterL^1;
   RECLAYERPX; //DONE/to test//TODO: what is limit for that one!? we keep on adding // how else? overlayx opts, RECEND opts as per RP below!
   if (f[d].rpp==3) f[d].rpp=0;
   else if (f[d].rpp==1) f[d].rpp=2; // set end // when do we set to 0
 }
break;

// RP generic

tmp=livevalue(d, V_options); 
LAYERSWOPRP;
speed=control[whichctrl[d]]>>2;
autre=f[d].masterL^1; // opposite...
values[d]=f[d].l[f[d].masterL].speedsamp[0](playreff[f[d].playspeed][speed], f[d].l[f[d].masterL].rec_end, 0, f[d].l[f[d].masterL].rec_end, d, recordings[d]); // as per play above for mode 0** would be playlist in playlist modes
values[d]=overlay(tmp, values[d], (P_options>>2)&3); // types of live overlay - is also recorded
tmp=overlayx(values[d], f[d].l[autre].accessreclayer(d), (RP_options>>1)&3);
//RECLAYERP; // now with RP_options bit 1 as toggling rec_end - test live toggling // ???TODO: also we could reset rec_cnt to 0 - when??????
if (RP_options&8){ // option to stop rec on not playing...
  RECLAYERP;
 }

