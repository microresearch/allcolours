
uint32_t binroutetypes[64][4]={
{0,0,0,0},
};


// can also have array of binary or singular routing tables to work through:
// these could also be 4x4 = 16 bit values... as maybe easier to decode...
uint32_t binroute[17][4]={ // add more routes, also what seq change of routes makes sense now we have 16 routes
    {8,1,2,4}, // new default: 8 1 2 4 // default was 8121 // now we have full route 8124
  //  {0,0,1,0}, //  test
	{8,1,2,2}, // notexpanding
	{8,1,2,1}, // notexpanding
	{8,1,2,8}, // expanding
	{8,1,2,9}, // expanding
	{8,1,2,11}, // expanding
	{8,1,2,12}, // expanding
	{8,1,2,4}, // route in one big circle

	{0,1,2,4},
	{9,3,6,9}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
	{1,2,4,8}, // only loop - this is what is added to get loop too for prob
	{8,1,2,2}, // as defroutee 3/0/1/1
	{8,1,1,2}, // as altroute 3/0/0/1
	{8,9,1,2}, // bounce L and R back and forth
	{8,1,2,5}, // others
    {2,4,8,1}, // reverse round route
    {0,0,0,0} // drop all routes
}; // TODO: add 8,1,1,1 and different expansions so could be 32 of these

uint32_t inroute[16][4]={ // who we have main incoming route from 0-3 - from above
        {3,0,1,2}, // default 8121 // now 8124
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
}; // TODO: add 8,1,1,1 and different expansions so could be 32 of these

uint32_t routeto[16][4]={ // as above but who we route TO! and as single routes - first one/major
  {1,2,2,0}, // default 8121
  {1,2,2,0}, // expanding
  {1,2,3,0}, // expanding ok
  {1,2,2,0}, // expanding
  {1,2,2,0}, // expanding
  {1,2,2,0}, // expanding
  {1,2,2,0}, // expanding
  {1,2,3,0}, // route in one big circle
  {1,2,3,3},
  {1,2,2,1}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
  {0,1,2,3}, // only loop - this is what is added to get loop too for prob
  {1,2,3,0}, // as defroutee 3/0/1/1
  {1,3,2,0}, // as altroute 3/0/0/1
  {1,4,3,0}, // bounce L and R back and forth
  {1,3,3,0}, // others
  {3,0,1,2}, // reverse round route
}; 

uint32_t dacfrom[16][4]={ // TODO and needs to match lengthy of binroute TEST!  and also relate to binroute // or use different count
  {3,3,3,1}, // default
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

uint32_t speedfrom[16][4]={ // now for speedfrom just copied from above! TODO: changing: synced speeds...
  {3,0,0,0}, // default
  {0,0,0,0}, // synced...
  {1,1,1,1}, // synced...
  {2,2,2,2}, // synced...
  {3,3,3,3}, // synced...
  {0,1,2,3}, // itself...
  /*  
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
  {1,3,1,1}*/
};


// can also have lists for each one to bump along
uint32_t myroute[4][16]={
  {8, 4, 2, 1,  9, 5, 3, 1,  2, 4, 8, 1,  3, 5, 9, 1},
  {1, 8, 4, 2,  3, 10, 6, 2,  4, 8, 1, 2,  6, 10, 3, 2},
  {2, 1, 8, 4,  6, 5, 12, 4,  8, 1, 2, 4,  12, 5, 6, 4},
  {4, 2, 1, 8,  12, 10, 9, 8,  1, 2, 4, 8,  9, 10, 12, 8}
};

//uint32_t binroutex[8]={4632, 38457, 33825, 8728, 8472, 8600, 21016, 6210}; // above routes generated by test.c as sets of 4 bits values with first route as lowest 

uint32_t singroute[4][4]={ // singular table for single routes - old prob modes
  {3,0,1,0},
  {3,0,1,1},
  {3,0,0,1},
  {3,0,2,1}
};