/*

<--------------+-------^-------+-------<
               |       |       |       |
               |       |       |       |
               +-------+       +-------+

0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  1  1  1  1  1  1  1  1  1  1  1  1  1  1  
0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  1  1  1  1  1  1  1  1  1  1  1  1  1  
0  0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  1  1  1  1  1  1  1  1  1  1  1  1  
0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  1  1  1  1  1  1  1  1  1  1  1  
0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  1  1  0  0  0  0  0  0  0  0  0  0  
0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  1  1  0  0  0  0  0  0  0  0  0  
1  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  1  0  0  1  1  1  1  0  1  1  
1  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  1  0  0  1  1  1  1  0  1  
0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  0  1  0  1  
0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  0  1  0  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  0  1  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  0  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  
0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  1  1  1  0  0  0  0  1  1  1  1  1  1  1  0  0  
1  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0  1  1  1  1  0  1  0  
1  0  0  0  0  0  0  0  1  0  1  1  1  1  1  1  1  1  1  1  1  0  0  0  1  1  0  0  0  0  1  0  
1  0  0  0  0  0  0  0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0  1  1  1  1  0  
1  0  0  0  0  0  0  0  0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0  1  1  1  1  

TODO:

// from late July 2021 test sketches which show directions rather than full framework

- fix noise in DAC out (is from speed of ADC or DAC?, what speed can we aim for?

  */ 

//#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "adc.h"

/////////////////////
extern __IO uint16_t adc_buffer[12];

#define MAXVALUE 4095
#define SMOOTHINGS 512 // we can hold 65536 of our 16 bit ADC values...speed
uint32_t cc=0, totc=0, smoothc[SMOOTHINGS];
uint32_t ll=0, totl=0, smoothl[SMOOTHINGS];
uint32_t rr=0, totr=0, smoothr[SMOOTHINGS];
uint32_t nn=0, totn=0, smoothn[SMOOTHINGS];

volatile uint32_t shift_registern=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t shift_registerl=0xff;
volatile uint32_t shift_registerr=0xff;
volatile uint32_t shift_registerc=0xff; 

// ghosts, revenants
volatile uint32_t Gshift_registern=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t Gshift_registerl=0xff;
volatile uint32_t Gshift_registerr=0xff;
volatile uint32_t Gshift_registerc=0xff; 

volatile uint32_t bitn, bitl, bitr, bitc=0;
volatile uint32_t moden, model, moder, modec=0;
volatile uint32_t speedn, speedl, speedr, speedc=0;
volatile uint32_t countern, counterl, counterr, counterc=0;
volatile uint32_t SRlengthn=31, SRlengthl=31, SRlengthr=31, SRlengthx=31, lengthbitn=15, Slengthbitl=15, lengthbitr=15, Slengthbitc=15;

// and also need counters for "cogs"
volatile uint32_t coggn, coggl, coggr, coggc=0;

// experimental parallel SR
uint32_t shift_registerpar[32]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

// from AC
static uint32_t electroprob[8]={0, 3, 7, 15, 31, 63, 127, 255};

static uint32_t bits[8]={1, 2, 4, 8, 16, 32, 64, 128};

static uint32_t MASK[32]={4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294966785, 4294966275, 4294965255, 4294963215, 4294959135, 4294950975, 4294934655, 4294902015, 4294836735, 4294706175, 4294445055, 4293922815, 4292878335, 4290789375, 4286611455, 4278255615, 4261543935, 4228120575, 4161273855, 4027580415, 3760193535, 3225419775, 2155872255, 16777215};

static uint32_t SHIFT[32]={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; 

static uint8_t bitsz[256]={0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

// array for taps
// eg. 32-bit Galois LFSR with taps at 32, 30, 26, 25. Sequence length is 4294967295. 0 is a lock-up state.  -- minus one here - 31, 29, 25, 24
// bith= ((shift_registerh >> 31) ^ (shift_registerh >> 29) ^ (shift_registerh >> 25) ^ (shift_registerh >> 24)) & 1u; // 32 is 31, 29, 25, 24
// from: http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf
// and reworked for length in test.c -> not so if we revert to basic code...
// note that we can have 2 mirrored with [n, A, B, C] -> [n, n-C, n-B, n-A] - maybe for LF to hF!

static uint8_t lfsr_taps[32][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {3, 2, 0, 0},
        {4, 3, 2, 1},
        {5, 4, 2, 1},
        {6, 5, 4, 3},
        {7, 5, 4, 3},
        {8, 7, 5, 4},
        {9, 8, 6, 5},
        {10, 9, 8, 6},
        {11, 10, 7, 5},
        {12, 11, 9, 8},
        {13, 12, 10, 8},
        {14, 13, 12, 10},
        {15, 13, 12, 10},
        {16, 15, 14, 13},
        {17, 16, 15, 12},
        {18, 17, 16, 13},
        {19, 18, 15, 13},
        {20, 19, 18, 15},
        {21, 18, 17, 16},
        {22, 21, 19, 17},
        {23, 22, 20, 19},
        {24, 23, 22, 21},
        {25, 24, 23, 19},
        {26, 25, 24, 21},
        {27, 26, 23, 21},
        {28, 27, 26, 24},
        {29, 28, 25, 23},
        {30, 29, 28, 27},
        {31, 29, 25, 24},
  };

static uint8_t ghost_tapsH[32][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {3, 2, 0, 0},
        {4, 3, 2, 1},
        {5, 4, 2, 1},
        {6, 5, 4, 3},
        {7, 5, 4, 3},
        {8, 7, 5, 4},
        {9, 8, 6, 5},
        {10, 9, 8, 6},
        {11, 10, 7, 5},
        {12, 11, 9, 8},
        {13, 12, 10, 8},
        {14, 13, 12, 10},
        {15, 13, 12, 10},
        {16, 15, 14, 13},
        {17, 16, 15, 12},
        {18, 17, 16, 13},
        {19, 18, 15, 13},
        {20, 19, 18, 15},
        {21, 18, 17, 16},
        {22, 21, 19, 17},
        {23, 22, 20, 19},
        {24, 23, 22, 21},
        {25, 24, 23, 19},
        {26, 25, 24, 21},
        {27, 26, 23, 21},
        {28, 27, 26, 24},
        {29, 28, 25, 23},
        {30, 29, 28, 27},
        {31, 29, 25, 24},
  };


static uint8_t lfsr_taps_mirrored[32][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {3, 2, 2, 0},
        {4, 2, 1, 0},
        {5, 3, 2, 0},
        {6, 2, 1, 0},
        {7, 3, 2, 1},
        {8, 3, 2, 0},
        {9, 3, 2, 0},
        {10, 3, 1, 0},
        {11, 5, 3, 0},
        {12, 3, 2, 0},
        {13, 4, 2, 0},
        {14, 3, 1, 0},
        {15, 4, 2, 1},
        {16, 2, 1, 0},
        {17, 4, 1, 0},
        {18, 4, 1, 0},
        {19, 5, 3, 0},
        {20, 4, 1, 0},
        {21, 4, 3, 2},
        {22, 4, 2, 0},
        {23, 3, 2, 0},
        {24, 2, 1, 0},
        {25, 5, 1, 0},
        {26, 4, 1, 0},
        {27, 5, 3, 0},
        {28, 3, 1, 0},
        {29, 5, 3, 0},
        {30, 2, 1, 0},
        {31, 6, 5, 1},
	 };

static uint8_t ghost_tapsL[32][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {3, 2, 2, 0},
        {4, 2, 1, 0},
        {5, 3, 2, 0},
        {6, 2, 1, 0},
        {7, 3, 2, 1},
        {8, 3, 2, 0},
        {9, 3, 2, 0},
        {10, 3, 1, 0},
        {11, 5, 3, 0},
        {12, 3, 2, 0},
        {13, 4, 2, 0},
        {14, 3, 1, 0},
        {15, 4, 2, 1},
        {16, 2, 1, 0},
        {17, 4, 1, 0},
        {18, 4, 1, 0},
        {19, 5, 3, 0},
        {20, 4, 1, 0},
        {21, 4, 3, 2},
        {22, 4, 2, 0},
        {23, 3, 2, 0},
        {24, 2, 1, 0},
        {25, 5, 1, 0},
        {26, 4, 1, 0},
        {27, 5, 3, 0},
        {28, 3, 1, 0},
        {29, 5, 3, 0},
        {30, 2, 1, 0},
        {31, 6, 5, 1},
	 };

static uint16_t logger[1024]={312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 326, 327, 328, 329, 330, 331, 332, 333, 334, 336, 337, 338, 339, 340, 341, 343, 344, 345, 346, 347, 348, 350, 351, 352, 353, 354, 356, 357, 358, 359, 360, 362, 363, 364, 365, 367, 368, 369, 370, 372, 373, 374, 375, 377, 378, 379, 380, 382, 383, 384, 386, 387, 388, 390, 391, 392, 394, 395, 396, 398, 399, 400, 402, 403, 404, 406, 407, 409, 410, 411, 413, 414, 416, 417, 418, 420, 421, 423, 424, 425, 427, 428, 430, 431, 433, 434, 436, 437, 439, 440, 442, 443, 445, 446, 448, 449, 451, 452, 454, 455, 457, 458, 460, 462, 463, 465, 466, 468, 469, 471, 473, 474, 476, 477, 479, 481, 482, 484, 486, 487, 489, 491, 492, 494, 496, 497, 499, 501, 502, 504, 506, 507, 509, 511, 513, 514, 516, 518, 520, 521, 523, 525, 527, 528, 530, 532, 534, 536, 538, 539, 541, 543, 545, 547, 549, 550, 552, 554, 556, 558, 560, 562, 564, 566, 567, 569, 571, 573, 575, 577, 579, 581, 583, 585, 587, 589, 591, 593, 595, 597, 599, 601, 603, 605, 607, 609, 611, 613, 616, 618, 620, 622, 624, 626, 628, 630, 632, 635, 637, 639, 641, 643, 645, 648, 650, 652, 654, 656, 659, 661, 663, 665, 668, 670, 672, 674, 677, 679, 681, 684, 686, 688, 691, 693, 695, 698, 700, 702, 705, 707, 710, 712, 714, 717, 719, 722, 724, 727, 729, 732, 734, 737, 739, 742, 744, 747, 749, 752, 754, 757, 759, 762, 765, 767, 770, 772, 775, 778, 780, 783, 786, 788, 791, 794, 796, 799, 802, 804, 807, 810, 813, 815, 818, 821, 824, 826, 829, 832, 835, 838, 841, 843, 846, 849, 852, 855, 858, 861, 864, 867, 870, 872, 875, 878, 881, 884, 887, 890, 893, 896, 899, 903, 906, 909, 912, 915, 918, 921, 924, 927, 930, 934, 937, 940, 943, 946, 950, 953, 956, 959, 962, 966, 969, 972, 976, 979, 982, 986, 989, 992, 996, 999, 1002, 1006, 1009, 1013, 1016, 1020, 1023, 1026, 1030, 1033, 1037, 1040, 1044, 1048, 1051, 1055, 1058, 1062, 1065, 1069, 1073, 1076, 1080, 1084, 1087, 1091, 1095, 1098, 1102, 1106, 1110, 1113, 1117, 1121, 1125, 1129, 1132, 1136, 1140, 1144, 1148, 1152, 1156, 1160, 1163, 1167, 1171, 1175, 1179, 1183, 1187, 1191, 1195, 1199, 1204, 1208, 1212, 1216, 1220, 1224, 1228, 1232, 1237, 1241, 1245, 1249, 1253, 1258, 1262, 1266, 1271, 1275, 1279, 1283, 1288, 1292, 1297, 1301, 1305, 1310, 1314, 1319, 1323, 1328, 1332, 1337, 1341, 1346, 1350, 1355, 1360, 1364, 1369, 1373, 1378, 1383, 1387, 1392, 1397, 1402, 1406, 1411, 1416, 1421, 1426, 1430, 1435, 1440, 1445, 1450, 1455, 1460, 1465, 1470, 1475, 1480, 1485, 1490, 1495, 1500, 1505, 1510, 1515, 1520, 1525, 1531, 1536, 1541, 1546, 1551, 1557, 1562, 1567, 1573, 1578, 1583, 1589, 1594, 1599, 1605, 1610, 1616, 1621, 1627, 1632, 1638, 1643, 1649, 1655, 1660, 1666, 1671, 1677, 1683, 1688, 1694, 1700, 1706, 1711, 1717, 1723, 1729, 1735, 1741, 1747, 1753, 1758, 1764, 1770, 1776, 1782, 1788, 1795, 1801, 1807, 1813, 1819, 1825, 1831, 1838, 1844, 1850, 1856, 1863, 1869, 1875, 1882, 1888, 1894, 1901, 1907, 1914, 1920, 1927, 1933, 1940, 1946, 1953, 1960, 1966, 1973, 1980, 1986, 1993, 2000, 2007, 2013, 2020, 2027, 2034, 2041, 2048, 2055, 2062, 2069, 2076, 2083, 2090, 2097, 2104, 2111, 2118, 2126, 2133, 2140, 2147, 2155, 2162, 2169, 2177, 2184, 2191, 2199, 2206, 2214, 2221, 2229, 2236, 2244, 2251, 2259, 2267, 2274, 2282, 2290, 2298, 2305, 2313, 2321, 2329, 2337, 2345, 2353, 2361, 2369, 2377, 2385, 2393, 2401, 2409, 2417, 2426, 2434, 2442, 2450, 2459, 2467, 2475, 2484, 2492, 2501, 2509, 2518, 2526, 2535, 2543, 2552, 2561, 2569, 2578, 2587, 2595, 2604, 2613, 2622, 2631, 2640, 2649, 2658, 2667, 2676, 2685, 2694, 2703, 2712, 2721, 2731, 2740, 2749, 2759, 2768, 2777, 2787, 2796, 2806, 2815, 2825, 2834, 2844, 2853, 2863, 2873, 2883, 2892, 2902, 2912, 2922, 2932, 2942, 2952, 2962, 2972, 2982, 2992, 3002, 3012, 3023, 3033, 3043, 3053, 3064, 3074, 3085, 3095, 3105, 3116, 3127, 3137, 3148, 3158, 3169, 3180, 3191, 3202, 3212, 3223, 3234, 3245, 3256, 3267, 3278, 3289, 3301, 3312, 3323, 3334, 3346, 3357, 3368, 3380, 3391, 3403, 3414, 3426, 3437, 3449, 3461, 3472, 3484, 3496, 3508, 3520, 3532, 3544, 3556, 3568, 3580, 3592, 3604, 3616, 3629, 3641, 3653, 3666, 3678, 3691, 3703, 3716, 3728, 3741, 3754, 3766, 3779, 3792, 3805, 3818, 3831, 3844, 3857, 3870, 3883, 3896, 3909, 3923, 3936, 3949, 3963, 3976, 3989, 4003, 4017, 4030, 4044, 4058, 4071, 4085, 4099, 4113, 4127, 4141, 4155, 4169, 4183, 4197, 4211, 4226, 4240, 4254, 4269, 4283, 4298, 4312, 4327, 4342, 4356, 4371, 4386, 4401, 4416, 4431, 4446, 4461, 4476, 4491, 4506, 4522, 4537, 4552, 4568, 4583, 4599, 4615, 4630, 4646, 4662, 4677, 4693, 4709, 4725, 4741, 4757, 4773, 4790, 4806, 4822, 4838, 4855, 4871, 4888, 4904, 4921, 4938, 4954, 4971, 4988, 5005, 5022, 5039, 5056, 5073, 5090, 5108, 5125, 5142, 5160, 5177, 5195, 5213, 5230, 5248, 5266, 5284, 5301, 5319, 5337, 5356, 5374, 5392, 5410, 5429, 5447, 5465, 5484, 5503, 5521, 5540, 5559, 5578, 5597, 5615, 5635, 5654, 5673, 5692, 5711, 5731, 5750, 5770, 5789, 5809, 5829, 5848, 5868, 5888, 5908, 5928, 5948, 5968, 5988, 6009, 6029, 6050, 6070, 6091, 6111, 6132, 6153, 6174, 6195, 6216, 6237, 6258, 6279, 6300, 6322, 6343, 6365, 6386, 6408, 6430, 6451, 6473, 6495, 6517, 6539, 6562, 6584, 6606, 6629, 6651, 6674, 6696, 6719, 6742, 6765, 6787, 6810, 6834, 6857, 6880, 6903, 6927, 6950, 6974, 6997, 7021, 7045, 7069, 7093, 7117, 7141, 7165, 7189, 7214, 7238, 7263, 7287, 7312, 7337, 7362, 7387, 7412, 7437, 7462, 7487, 7513, 7538, 7564, 7590, 7615, 7641, 7667, 7693, 7719, 7745, 7772, 7798, 7824, 7851, 7877, 7904, 7931, 7958, 7985, 8012, 8039, 8066, 8094, 8121, 8149, 8176, 8204, 8232, 8260, 8288, 8316, 8344, 8372, 8401, 8429, 8458, 8486, 8515, 8544, 8573, 8602, 8631, 8661, 8690, 8719, 8749, 8779, 8808, 8838, 8868, 8898, 8928, 8959, 8989, 9020, 9050, 9081, 9112, 9142, 9173, 9205, 9236, 9267, 9299, 9330, 9362, 9393, 9425, 9457, 9489, 9521, 9554, 9586, 9619, 9651, 9684, 9717, 9750, 9783, 9816, 9849, 9883, 9916, 9950};

///////////////////////////////////////////////////////////////////////// 

#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 1000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

// TEST: inpulse interrupts to attach are: CSR: PC3nowPB7, NSR: PC4, RSR: PC5, LSR: PB6

void EXTI4_IRQHandler(void){ // working NSR
  static uint16_t flipper=0;
if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
  
  // flip PB4 to test interrupt on NSR PC4
    flipper^=1;
    //    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    //    else   GPIOB->BSRRL=(1)<<4; //  write bits   
  
  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
  // added PB7 now for CSRCLKIN CSR which moved from PC3!!!

  static uint16_t flipper=0;
if (EXTI_GetITStatus(EXTI_Line5) != RESET) {

  // CSR: PC3->now PB7, NSR: PC4, RSR: PC5, LSR: PB6
  
  // flip PB4 to test interrupt on  RSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   
  
  EXTI_ClearITPendingBit(EXTI_Line5);
 }

 if (EXTI_GetITStatus(EXTI_Line6) != RESET) {

  // flip PB4 to test interrupt on LSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  EXTI_ClearITPendingBit(EXTI_Line6);
 } 

  if (EXTI_GetITStatus(EXTI_Line7) != RESET) {

  // flip PB4 to test interrupt on PB7 -> CSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  EXTI_ClearITPendingBit(EXTI_Line7);
 } 

}

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  static volatile uint16_t k=0,ll=0, n=0, accum, cnt=4;
  static volatile int16_t integrator=0, oldValue=0, tmp=0;
  uint16_t j, bit;
  uint32_t temp;
    //low pass test
  static float SmoothData=0.0;
  float LPF_Beta = 0.02; // 0<ß<1
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

  // noise test of dac/adc - noise was jitter from speed I think
  // how to test if feedback works (but we are inverted ???) SEEMS WORK

  /*
  k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!
  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  */
  // time PB4 with period=9 prescaler=8 we have 300KHz
  //  tmp^=1;
  //  if (tmp) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
  //  else   GPIOB->BSRRL=(1)<<4; //  write bits   

  
  
    // TODO 16/7/2021: test simple delta/sigma ADC and DAC (first bits say on PB4 then low pass) out
    // concept works fine...DONE

    // map ADCs: note all modes are inverted

    // 0: nspd, 1: nlen, 2: nmode
    // 3: lspd, 4: llen, 5: lmode
    // 6: rspd, 7: rlen, 8: rmode
    // 9: cspd, 10: , 11: cmode

  // test speed for all - from cspd
  
  // but we need smoothings or we get jitter noise
  // from AC
  counterc++;
  
  totn=totn-smoothn[nn];
  smoothn[nn]=adc_buffer[9];
  totn+=smoothn[nn];
  nn++;
  if (nn>=SMOOTHINGS) nn=0;
  temp=totn/SMOOTHINGS;  
  //  speedn=logger[temp>>2]; // 12  bits now to 10 bits // 1024  = 10 bits -> could be less logger to make smoother?
  speedn=temp>>2;
  
  if (counterc>speedn){
    counterc=0;
  
  ///////////////////////////////////////////////////////
  // test with SR in SR for digital filter simulator - works with simple pass through
  // how we could simplify with more arrays, masks?
  // how we can substitute leaky logic for logic ops

  // 4 bits go into NSR as in original AC and are shifted
  // can also be feedback so is micro-SR in largerSR
    //  k=(adc_buffer[12])>>8;//+tmp)>>8; // now 12 bits only -> 4 bits
  // copy into ghost reg so we can feedback bits if we like
    k=(adc_buffer[12])>>8; // 4 bits // 8 bits
    //  k++;
    //  if (k>31) k=0;
  /*  if (k<64) tmp=1;
  else if (k<128) tmp=3;
  else if (k<192) tmp=7; // these values can also shift
  else tmp=15;
  k=tmp;
  */
  
  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in
  shift_registern += ((k&0x01) + ((k&0x02)<<7) + ((k&0x04)<<14) + ((k&0x08)<<21)); // would be 0 8-1 16-2 24-3 -
  shift_registern=(shift_registern<<1); // here or later/earlier?
  
  // 4 bits into LSR
  shift_registerl &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in there
  // test feeding back some of the bits
    shift_registerl += (((shift_registern&(1<<7))>>7) + ((shift_registern&(1<<15))>>7) + ((shift_registern&(1<<23))>>7) + ((shift_registern&(1<<31))>>7));
  //    shift_registerl += (((shift_registern&(1<<7))>>7) ^ ((shift_registerl&(1<<7))>>7)  ) + (((shift_registern&(1<<15))>>7) ^ ((shift_registerl&(1<<15))>>7)) + (((shift_registern&(1<<23))>>7) ^ ((shift_registerl&(1<<23))>>7)) + (((shift_registern&(1<<31))>>7) ^ ((shift_registerl&(1<<31))>>7));

  shift_registerl=(shift_registerl<<1); // here or later/earlier?
  
  // 4 bits into CSR and out
  shift_registerc &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in there
  shift_registerc += (((shift_registerl&(1<<7))>>7) + ((shift_registerl&(1<<15))>>7) + ((shift_registerl&(1<<23))>>7) + ((shift_registerl&(1<<31))>>7));
  shift_registerc=(shift_registerc<<1); // here or later/earlier?

  // output it! 
  //  tmp=rand()%4095;
  // four basic bits to output - same as above
  tmp= (((shift_registerc&(1<<7))>>7) + ((shift_registerc&(1<<15))>>14) + ((shift_registerc&(1<<23))>>21) + ((shift_registerc&(1<<31))>>28))<<8;
  // just the number of bits is important
  //tmp=bitsz[tmp]*1024;
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

  /////
    } // close of speedc
  //  */
  
  ///////////////////////////////////////////////////////
  // test for parallell SR in top NSR
  ///////////////////////////////////////////////////////

  
    ///////////////////////////////////////////////////////
  // test for x(say 4) ADC bits in spaced out, feed through and DAC out, to lead towards digital filter simulation
  // not really working but kind of interesting - question is order of bits, also return of bits

  // sr in sr, parallel SR, feedback as bits or as addition into ADC in from DAC
  /*
  if (cnt==4){
  k=(adc_buffer[12])>>8; // now 12 bits only -> 4 bits
  cnt=0;
  // out - question is what is order of first bit? and return of bits
  }
  */
  /*  // can also be just 4 simple bits eg.
  k=(adc_buffer[12])>>4; // 8 bits
  if (k<64) tmp=1;
  else if (k<128) tmp=3;
  else if (k<192) tmp=7; // these values can also shift
  else tmp=15;

  // how to do as 4 independent bits ie. number of bits is the important thing - more about dac out from this one as is same no?
  */
  /*
  bitn = (shift_registern>>31) & 0x01; // bit which would be shifted out
  shift_registern=(shift_registern<<1); // here or later?
  shift_registern+=((k&(1<<cnt))>>cnt);// ^ bitc;
  */
  /* // older not workings
  // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in
  shift_registern += ((k&0x01) + ((k&0x02)<<7) + ((k&0x04)<<14) + ((k&0x08)<<21)); // would be 0 8-1 16-2 24-3 -
  // without clearing bits is interesting also we can have other options like delay of some bits which would happen anyways
  // eg. sample and then put bit in one by one
  */
  
  // pass to shiftregl
  /*
  bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
  shift_registerl=(shift_registerl<<1)+bitn;

  // pass to shiftregc
  bitc = (shift_registerc>>31) & 0x01; // bit which would be shifted out
  shift_registerc=(shift_registerc<<1)+bitl;

  tmp= ( (shift_registerc&1) + (shift_registerc&(1<<1)) + (shift_registerc&(1<<2)) + (shift_registerc&(1<<3)))<<8; 
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
 
  
  cnt++;
  */
  
  // and output
  //  tmp= (((shift_registerc&(1<<7))>>7) + ((shift_registerc&(1<<15))>>14) + ((shift_registerc&(1<<23))>>21) + ((shift_registerc&(1<<31))>>28))<<8; // much further bits  // msb first
  //  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
 //  tmp= (((shift_registerc&(1<<7))>>4) + ((shift_registerc&(1<<15))>>13) + ((shift_registerc&(1<<23))>>22) + ((shift_registerc&(1<<31))>>31))<<8; // much further bits
      
  ///////////////////////////////////////////////////////

    
  /* 
  //test for sigma/delta
    
  n++;
  if (n>50) {
    k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!
    n=0;
  }

  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     //     GPIOB->BSRRL=(1)<<4; //  write bits 
     bit=4095;
  }
   else
   {
      oldValue=0;
      //      GPIOB->BSRRH = (1)<<4;  // clear bits PB4
      bit=0;
   }
  
   // low pass to our DAC!
   SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit));
   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

  */
   
}
