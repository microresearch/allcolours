uint32_t orderings[64][15]={ // orderings - first is length
  {4,0,1,2,3},
  {5,0,0,1,2,3},
  {6,0,0,0,1,2,3},
  {7,0,0,0,0,1,2,3},
  {8,0,0,0,0,0,1,2,3},
  {9,0,0,0,0,0,0,1,2,3},
  {10,0,0,0,0,0,0,0,1,2,3},
  {11,0,0,0,0,0,0,0,0,1,2,3},
  {12,0,0,0,0,0,0,0,0,0,1,2,3},
  {13,0,0,0,0,0,0,0,0,0,0,1,2,3},
  {14,0,0,0,0,0,0,0,0,0,0,0,1,2,3},
  {4,3,2,1,0},
  {5,3,3,2,1,0},
  {6,3,3,3,2,1,0},
  {7,3,3,3,3,2,1,0},
  {8,3,3,3,3,3,2,1,0},
  {8,0,0,1,1,2,2,3,3},
  {12,0,0,0,1,1,1,2,2,2,3,3,3},
  {6,0,1,0,1,2,3},
  {8,0,1,0,1,0,1,2,3},
  {10,0,1,0,1,0,1,0,1,2,3},
  {12,0,1,0,1,0,1,0,1,0,1,2,3},
  {5,0,1,1,2,3},
  {6,0,1,1,1,2,3},
  {7,0,1,1,1,1,2,3},
  {8,0,1,1,1,1,1,2,3},
  {5,0,1,2,2,3},
  {6,0,1,2,2,2,3},
  {7,0,1,2,2,2,2,3},
  {8,0,1,2,2,2,2,2,3},
  {5,0,1,2,3,3},
  {6,0,1,2,3,3,3},
  {7,0,1,2,3,3,3,3},
  {8,0,1,2,3,3,3,3,3},
  {6,0,0,1,1,2,3},
  {7,0,0,1,1,2,2,3},
  {10,0,0,0,1,1,1,2,2,2,3},  
  {6,0,0,1,2,2,3},
  {7,0,0,1,2,2,2,3},
  {9,0,0,0,1,2,2,2,2,3},
  {11,0,0,0,0,1,2,2,2,2,2,3},
  {6,0,1,0,2,0,3},
  {10,0,1,0,1,0,2,0,2,0,3},
  {6,0,1,2,1,2,3},
  {8,0,1,2,1,2,1,2,3},
  {10,0,1,2,1,2,1,2,1,2,3},
  {12,0,1,2,1,2,1,2,1,2,1,2,3},
  {14,0,1,2,1,2,1,2,1,2,1,2,1,2,3},
  {6,0,1,2,3,2,3},
  {8,0,1,2,3,2,3,2,3},
  {10,0,1,2,3,2,3,2,3,2,3},
  {6,0,1,2,3,1,3},  
  {6,3,2,2,1,1,0},
  {6,3,3,2,1,1,0},
  {7,3,3,2,2,1,1,0},
  {8,3,3,2,2,1,1,0,0},
  {4,1,0,3,2},
  {4,1,3,0,2},
  {4,3,0,2,1},
  {5,1,0,0,3,2},
  {6,1,0,0,3,2,3},
  {7,3,2,1,0,0,0,0},
  {8,3,2,1,0,0,0,0,0},
  {7,3,2,1,1,0,0,0},
}; // 64

// can also have array of binary or singular routing tables to work through:
// these could also be 4x4 = 16 bit values... as maybe easier to decode...
uint32_t binroute[32][4]={ // add more routes, also what seq change of routes makes sense now we have 16 routes
    {8,1,2,4}, // new default: 8 1 2 4 // default was 8121 // now we have full route 8124
    {4,1,8,2}, // good
    {4,1,10,1},
    {0,1,3,1}, // no route in on 1
    {8,1,1,2}, // from below and below changed 8,1,1,6 replace in alts
    {0,1,10,1},
    {4,1,10,1},
    {10,4,1,4},
    {8,1,2,4}, // route in one big circle
    {2,5,10,4},
    {9,3,6,9}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
    {1,2,4,8}, // only loop - this is what is added to get loop too for prob
    {8,1,2,2}, // as defroutee 3/0/1/1
    {8,1,1,6}, // as altroute 3/0/0/1
    {8,9,1,2}, // bounce L and R back and forth
    {8,1,2,5}, // others
    {2,4,8,1}, // reverse round route
    {1,1,1,1},    // was drop all routes but why?
    {8,1,1,1},
    {2,8,2,1},
    {4,4,8,1},
    {8,8,8,1},
    {10,5,10,5},
    {6,9,9,6},
    {10,13,2,3},
    {10,5,2,1},
    {10,5,2,9},
    {10,5,2,9},
    {10,13,2,11},  
    {10,5,10,13},
    {10,5,10,5},
    {0,1,2,4},  // swop to end    
}; 

/* new routes to replace some of first - and fill alts below
4,1,10,1
0,1,3,1
8,1,1,2// we had so...

0,1,10,1
4,1,10,1
10,4,1,4
 */

uint32_t altbinroute[32][4]={ // for probs - can be more like double route but trial first one and fill in rest TODO
  {10,5,10,5},
  {6,9,9,6},
  {14,5,11,5}, //toreplace
  {14,5,3,1},
  {14,9,1,3},
  {10,5,10,5},
  {14,5,11,5}, 
  {14,5,11,5},
  {10,5,10,5},
  {0,1,2,4},
  {9,9,10,9},
  {2,4,8,8},
  {10,13,2,3},
  {14,9,9,7}, //xxdone
  {14,9,1,5},
  {10,5,10,5},
  {10,5,10,5},
  {8,1,2,4},
  {14,1,1,1},
  {10,13,2,3},  
  {12,4,11,5},
  {8,8,8,7},  
  {8,1,2,4}, // new default: 8 1 2 4 // default was 8121 // now we have full route 8124
  {4,1,8,2},
  {8,1,2,2}, // notexpanding
  {8,1,2,1}, // notexpanding
  {8,1,2,8}, // expanding
    {8,1,2,9}, // expanding
    {8,1,2,11}, // expanding
    {8,1,2,12}, // expanding
    {8,1,2,4}, // route in one big circle
  {2,5,10,4}, // // swop with end
};

uint8_t inroute[32][4]={ // who we have main incoming route from 0-3 - from above
        {3,0,1,2}, // default 8121 // now 8124
	{3,0,3,2},
	{3,0,1,1}, // expanding
	{3,0,1,2}, // expanding
	{3,0,1,3}, // expanding
	{3,0,1,3}, // expanding
	{3,0,1,1}, // expanding
	{3,0,1,2}, // expanding
	{3,0,1,2}, // route in one big circle	
	{0,0,1,2},
	{3,2,2,0}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
	{0,1,2,3}, // only loop - this is what is added to get loop too for prob
	{3,0,1,1}, // as defroutee 3/0/1/1
	{3,0,0,1}, // as altroute 3/0/0/1
	{3,3,0,1}, // bounce L and R back and forth
	{3,0,1,2}, // others
	{1,2,3,0}, // reverse round route
    {0,0,0,0},    // drop all routes
    {3,0,0,0},
    {1,3,1,0},
    {2,3,3,0},
    {3,3,3,0},
    {3,1,1,0},
    {2,3,0,3},
    {3,2,1,0},
    {3,2,1,0},
    {3,2,1,0},
    {3,2,1,0},
    {3,2,1,0},  
    {3,2,1,0},
    {3,2,1,0},
    {1,2,1,0},
}; 

uint32_t dacfrom[16][4]={ // TODO and needs to match lengthy of binroute TEST!  and also relate to binroute // or use different count
  {3,3,3,0}, // default
  {1,3,1,1}, // new one for rungling 24/1/2022
  {3,0,1,2}, // from latest notebook prev ones: 3,0,1,2
  {0,1,2,3}, // itself

  {3,2,1,0}, // reverse
  {3,3,3,3},
  {2,2,2,2},
  {1,1,1,1},

  {3,3,1,1},
  {1,1,3,3},
  {2,3,0,1}, // opposites
  {1,0,3,2},

  {1,2,3,0}, // nexts 
  {3,2,1,0}, /// rev
  {1,3,1,1},
  {1,3,1,1}
};

uint32_t dacfromopp[16][4]={ // TODO and needs to match lengthy of binroute TEST!  and also relate to binroute // or use different count
  {1,1,1,2}, // default
  {3,1,3,2}, // new one for rungling 24/1/2022
  {1,2,3,0}, // from latest notebook prev ones: 3,0,1,2
  {2,3,0,1}, // itself

  {1,0,3,2}, // reverse
  {1,1,1,1},
  {0,0,0,0},
  {3,3,3,3},

  {1,1,3,2},
  {3,3,1,1},
  {0,1,2,0}, // opposites
  {3,2,1,0},

  {3,0,1,2}, // nexts
  {1,0,3,2}, /// rev
  {3,1,3,2},
  {3,1,3,2}
};

uint32_t strobefrom[4]={3,0,1,0};// strobe from previous almost

uint32_t dacIN[16][4]={ // for dac into ADC - only really interested in first route in which must be different
  {2,3,3,1}, // default
  {3,3,1,1}, // new one for rungling 24/1/2022
  {2,0,1,2}, // from latest notebook prev ones: 3,0,1,2
  {3,1,2,3}, // itself

  {2,2,1,0}, // reverse
  {2,3,3,3},
  {3,2,2,2},
  {2,1,1,1},

  {2,3,1,1},
  {2,1,3,3},
  {1,3,0,1}, // opposites
  {2,0,3,2},

  {3,2,3,0}, // nexts
  {1,2,1,0}, /// rev
  {3,0,0,0},
  {2,3,1,0}
};

uint32_t speedfrom[16][4]={ // now for speedfrom just copied from above! TODO: changing: synced speeds...
  {1,3,1,0}, // default for rungler
  {3,0,0,0}, // synced...
  {1,3,1,1}, // synced...
  {2,2,3,2}, // synced...

  {3,3,3,3}, // synced...
  {0,1,2,3}, // itself...??? just for change
  {2,2,0,0}, // was 1,3,1,1 -new one for rungling 24/1/2022
  {3,0,1,2}, // from latest notebook prev ones: 3,0,1,2

  {2,3,0,0},
  {3,3,1,1},
  {1,2,3,3},
  {2,3,0,1}, // opposites

  {1,0,3,2},
  {1,2,3,0}, // nexts
  {3,2,1,0}, /// rev
  {1,3,3,1}
};

// can also have lists for each one to bump along
uint8_t myroute[4][16]={
  {8, 4, 2, 1,  9, 5, 3, 1,  2, 4, 8, 1,  3, 5, 9, 1},
  {1, 8, 4, 2,  3, 10, 6, 2,  4, 8, 1, 2,  6, 10, 3, 2},
  {2, 1, 8, 4,  6, 5, 12, 4,  8, 1, 2, 4,  12, 5, 6, 4},
  {4, 2, 1, 8,  12, 10, 9, 8,  1, 2, 4, 8,  9, 10, 12, 8}
};
