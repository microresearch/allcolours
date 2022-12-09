/*
for L and R - R will have globals but otherwise they can share first sets of functions

3/11/2022: TODO: check all array access and <<7 <<6 etc

L-routes only and etc, R etc, abstracts, routes, and globals...

 */

// basic is: SR_geo_inner_noprob, SR_geo_inner_prob0 in geoC.h

void SR_geo_inner_etc(uint32_t w){  // no probability, no adc // tests for etc - 44! some don't use depth
  HEADNADA;
  if (interpfromnostrobe[gate[w].matrix[0]>>7]){ 
    gate[w].alpha = gate[w].time_now - (float)gate[w].int_time;
    gate[w].dac = ((float)delay_buffer[w][DELAY_SIZE-5] * gate[w].alpha) + ((float)delay_buffer[w][DELAY_SIZE-6] * (1.0f - gate[w].alpha));
    if (gate[w].dac>4095) gate[w].dac=4095;
  }
  else gate[w].dac = delay_buffer[w][1];

    if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1], gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    bitn^=(expetcbits_nostrobe[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geo_outer_testetc(uint32_t w){  // testings for etc
  gate[w].matrix[0]=0<<7; // spdfrac
  gate[w].matrix[1]=CV[w];//gate[dacfrom[daccount][w]].dac; //??? speed
  gate[w].matrix[3]=37<<7;  // xpetcbits_nostrobe[38]
  gate[w].matrix[4]=CVL[w]; //
   gate[w].matrix[6]=CVL[w]; // 
  gate[w].inner=SR_geo_inner_etc;
}

// to port below

// R_only
void SR_geomantic_innerRglob(uint32_t w){  // no adc, // for global Rmodes // TODO - also inner globsel with fastest speeds...
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*bitfromnostrobe[gate[w].matrix[3]>>6])(gate[w].matrix[4], gate[w].matrix[5], w); 

    (*globalls[glob])(gate[w].matrix[4]); // glob is index... which is set by master global function 31... set by outerglob
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innerRglobsel(uint32_t w){  // no adc, // for global Rmodes  - just select - 31 
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*bitfromsdR[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w);  // sdR is the one with selectglob at 31
    /// we don;t do the glob    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

void SR_geomantic_innerRglobselandset(uint32_t w){ // both select and set as we call from outer which uses dac for value
  HEADNADA;
  gate[w].dac = delay_buffer[w][1];
  //
  if ((*speedfromnostrobe[gate[w].matrix[0]>>7])(gate[w].matrix[1],gate[w].matrix[2], w)){ // speedfunc
    GSHIFT_;
    SRlength[w]=lookuplenall[gate[w].matrix[6]>>7]; // why it makes difference if this is before or after...
    
    bitn^=(*bitfromsdR[gate[w].matrix[3]>>7])(gate[w].matrix[4], gate[w].matrix[5], w); 

    (*globalls[glob])(gate[w].matrix[5]); // glob is index... which is set by master global function 31... set by outerglob // now matrix 5 is dacfrom 
    
    BITN_AND_OUTV_; 
    new_data(val,w);
    }
}

/// TRIAL for globals just to think through
void SR_geomantic_outerRglobset(uint32_t w){
  //    if (gate[w].changed==0) { // 1=change 0= no change
      gate[w].matrix[0]=3<<7; // spedfrom
      gate[w].matrix[1]=CV[w];
      gate[w].matrix[3]=31<<7;
      gate[w].matrix[4]=CVL[w];
      gate[w].inner=SR_geomantic_innerRglob;
      //    }
}  

void SR_geomantic_outerRglobsel(uint32_t w){
  //    if (gate[w].changed==0) { // 1=change 0= no change
      gate[w].matrix[0]=3<<7; // spedfrom
      gate[w].matrix[1]=CV[w];
      gate[w].matrix[3]=31<<7; // fixed route and glob setter
      gate[w].matrix[4]=CVL[w];
      gate[w].inner=SR_geomantic_innerRglobsel;
      //    }
}  

void SR_geomantic_outerRglobselandset(uint32_t w){ // select is CVL, depth for globsel is dac
  //    if (gate[w].changed==0) { // 1=change 0= no change
      gate[w].matrix[0]=3<<7; // spedfrom
      gate[w].matrix[1]=CV[w];
      gate[w].matrix[3]=31<<7; // fixed route and glob setter
      gate[w].matrix[4]=CVL[w];
      gate[w].matrix[5]=gate[dacfrom[daccount][w]].dac; // for the depth of the glob
      gate[w].inner=SR_geomantic_innerRglobselandset;
      //    }
}  


