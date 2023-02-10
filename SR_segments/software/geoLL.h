// geoLL

/*

LL: routes as primary, speeds 0 follows CC but add extra rungler!

older from geoLR.h:

L-routes only and etc, R etc, abstracts, routes, and globals...

prime rungler territory

but much following CC so far - unless we can extend runglers...

 */

//////////////////////////////////////////////////////////////////////////////////////////////////////
/// INNER

// from geoCC so far ++

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OUTER

//0.0////////

void SR_geo_outer_L00(uint32_t w){  // set length
  if (gate[w].changed==1) RESETL; // added 21/12 only reset on change 
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];// speed
  gate[w].matrix[6]=CVL[w]; // length
  gate[w].inner=SR_geo_inner_routeC; // routetype/theroute so always at reset route/base global
}

// next follow CC

// next 16 follows geoCC but we need different runglers


