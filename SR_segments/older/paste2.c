// basic model
if (counter[w]>speed[w]){
    dactype[2]=0; // basic DAC out, others are fixed as basic

    counter[w]=0; 
    Gshift_[w][0]=shift_[w]; 
    Gshift_[w][1]=shift_[w]; 
    Gshift_[w][2]=shift_[w];
    Gshift_[w][3]=shift_[w]; 
      
    shift_[w]=shift_[w]<<1;
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    if (pulsins[w]!=0){
    xx=!(GPIOC->IDR & pulsins[w]); 
    bitn^=xx;
    }
    
    shift_[w]+=bitn;
    
    dac[w]=DAC_(w, SRlength[w], dactype[w],0); 

    tmp=(w<<1);
    if (bitn) *pulsoutLO[tmp]=pulsouts[tmp]; 
    else *pulsoutHI[tmp]=pulsouts[tmp];

    lengthbit=(SRlength[w]>>1);
    new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit; 
    if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;
    prev_stat[w]=new_stat;	
    tmp++;
    if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];
    else *pulsoutHI[tmp]=pulsouts[tmp];        
  }
  break; 


/*
TODO: prob modes below as/and basic INT modes

- probability modes for (DAC, DAC+CV comp to SR,countedclk), prob of bit in/inverted bit in,
  XOR bit in from->[routed//cycled//ADCorLFSR//pulseifwehave], prob of
  bitin OR loopback, prob of bitin or inverted loopback, prob of
  cycle, new bit from bits/from route -> how many? make this clearer:

SR is customSR or RSR(routed SR)

1. if SR<CV  // int mode
3. if SR<DAC+CV // int mode


2.if SR<DAC  // cv/int mode but keep as CV
4.if sr<CLKCNT // cv mode
XX
10+

1. invert cycling bit or not, pulsbit is ORed in (TM)
2. invert routedin bit or not, pulsbit is ORed in (TM)
3. mix of this?

////

3. new input (from pulsbit) or cycling bit (wiard and EN) - if we don't have pulsebit then route
4. new input (from route) or cycling bit - and OR in pulsebit if...

5. new input (from ADCtypeX) or cycling bit - in all cases or just for NSR? -  - maybe do inverted route bit in for others  // with route bit
6. new input (from ADCtypeX) or route in 
// how these match/repeat above when we don't have ADC ??? - maybe do inverted route bit in for others // with cycling bit

//DONE*3and4 from above with inverted cycling bit*

- and with reduced number of combined DAC/ADC options...


*/






case 3: 
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - LFSR 
    // L: route from/bits in/logic - pass on/OR
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DACequiv
    // R: route from/bits in/logic  - pass on/OR
    
  if (counter[w]>speed[w]){
    counter[w]=0; 
    // here we can set options
    dactype[2]=1; // equiv DAC out, others are fixed as basic
    //    logtable[4]={0,1,0,1}; we set L and R to 1 which is OR
    logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1;
    
    Gshift_[w][0]=shift_[w]; 
    Gshift_[w][1]=shift_[w]; 
    Gshift_[w][2]=shift_[w];
    Gshift_[w][3]=shift_[w]; // ghosts for l,c,r only but let's keep one spare
      
    //2.5-shifting of which bits <<
    shift_[w]=shift_[w]<<1;
  
    //3-what is routing for incoming SR bits, cycling bit
    // we have default route here
    // BUT for LFSR in we have another route
    if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=ADC_(w,SRlength[w],2,0); // XOR with LFSR
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }

    //4-what is incoming pulsin bit if any? - incoming pulse will always be ORed in
    if (pulsins[w]!=0){
    xx=!(GPIOC->IDR & pulsins[w]); 
    bitn=logop(bitn,xx,logtable[w]); // just for bits in
    }
    
    shift_[w]+=bitn;
    
    //6-DAC result for any purposes - do we output in main loop?
    dac[w]=DAC_(w, SRlength[w], dactype[w],0); 

    //7-pulses out if any
    // L, C and R have 2 clocks out, N has none    
    tmp=(w<<1);
    if (bitn) *pulsoutLO[tmp]=pulsouts[tmp]; // N is just B with always zero
    else *pulsoutHI[tmp]=pulsouts[tmp];

    // follow AC scheme but we do maybe do a divide down of another bit-sofar is same! - make GENERIC    
    lengthbit=(SRlength[w]>>1); // /2
    new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit; // so that is not just a simple divide down

    if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;
    prev_stat[w]=new_stat;	
    tmp++;
    if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];
    else *pulsoutHI[tmp]=pulsouts[tmp];        
  }// counterw
  break; // case 3
