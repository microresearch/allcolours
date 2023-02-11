// geoRR - default speed as spdfracend?

/*

RR: routes, global, abstracts functions - prob of abstract vs route (as in ADC)

- follow rough scheme of NN but obviously without ADC!

- *DONEquestion if we slow down speed of geoRR so is half or quarter - 17, 18 octaves, to test. as seems a bit too fast*

on globals:

*We can also imagine slippage/attachment of settings in global modes eg. we have array of count daccount speeedcnt etc and we attach as in matrixp to these*

FOR GLOBAL rmodes:::
- *16 last global modes*
- *global modes all hold last function (eg. it could be abstract function)*
*REMOVE: where do we set globflag - in globals, set off/xon event*

*REMOVE: we need to sort following: global flag (gate[w].globflag)/routes, use of IN flag (gate[w].in), depth/no depth, global dacfrom?// also speedfrom dac, setting of route/type (16 and 17). which arrays to use for functions//how these match*

// if we are still using IN flag^^^ NO! dispose of...

////////////////////////////////



older from geoLR.h:

 */


//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

//0.0////////

void SR_geo_outer_R00(uint32_t w){  // set length
  if (gate[w].changed==1) {
    RESETR; // added 21/12 only reset on change
    gate[w].changed=0;
  }
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_globalC; //
}

// REDO from here! - abstracts etc. from NN once tested

/* and list how they crossover

R00: above
R01: N02 - abstract
R02: N03 - abstract/depth
R03: Nxx - route in only

// abstract ^ route, route types, length, route functions

// also probs route vs cycle can work here... from CC


 */

