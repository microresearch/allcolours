// right hand functions

// **REMEMBER to set count=0 in relevant modes

/*

and global set routes, set which dacs is dac for adc, set fake clkins

CVmodes: basics, prob modes entry/loopback, esoteric modes, << bumps, route from DAC, prob from DAC

DACmodes: basics, esoterics

INTmodes: route from CV, prob from CV, others? + change global routes, fake clks, use as DAC, entry of adc/non-adc bits from top

above, different kinds of DAC out

*/

// CV modes

void R0(void){ // basic route in
  uint8_t w=3;
  count=0;
  HEAD;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    BINROUTE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

void R1(void){ // route and cycle
  uint8_t w=3;
  count=0;
  HEAD;
  if (speedf_[3]!=2.0f){ 
  CVOPEN;
  if(gate[3].last_time<gate[3].int_time)      {
    GSHIFT_;
    BINROUTEANDCYCLE_;
    PULSIN_XOR;
    BITN_AND_OUTV_; 
    ENDER;
  }
  }
}

// for CV modes add in bump up global routes, SR as global routing table

// DACspeed modes?


// INTmodes - start to prototype bit modes
// INTmodes: route from CV, prob from CV, others? + change global routes, fake clks, use as DAC, entry of adc/non-adc bits from top

// what bits we have again?

// routing table is x long, and for raw routing we would need 4x4=16 bits (also in global routing macros we only use:
//  tmp=binroute[count][w] but this could change with condition
