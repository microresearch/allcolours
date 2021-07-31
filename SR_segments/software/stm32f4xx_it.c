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

- DONEfix noise in DAC out (is from speed of ADC or DAC?, what speed can we aim for? - was smoothing of speed.

- do all speeds/modes and check feedback is working...
// new interrupt for these on TIM

- test out wheel for connection between SRs


- revisit LFSR and taps
- experiment with how sets of parallel SRs might sound -> CV

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

uint16_t modec, moden, model, moder;

uint16_t lastmodec, lastmoden, lastmodel, lastmoder;
uint16_t lastlastmodec, lastlastmoden, lastlastmodel, lastlastmoder;

volatile uint32_t shift_registern=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t shift_registerl=0xff;
volatile uint32_t shift_registerr=0xff;
volatile uint32_t shift_registerc=0xff; 

// ghosts, revenants
volatile uint32_t Gshift_registern=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t Gshift_registerl=0xff;
volatile uint32_t Gshift_registerr=0xff;
volatile uint32_t Gshift_registerc=0xff; 

volatile uint16_t bitn, bitl, bitr, bitc=0, bitnx;
volatile uint16_t speedn, speedl, speedr, speedc=0;

volatile uint16_t countern, counterl, counterr, counterc=0;
volatile uint16_t SRlengthn=31, SRlengthl=31, SRlengthr=31, SRlengthc=31, lengthbitn=15, Slengthbitl=15, lengthbitr=15, Slengthbitc=15;

// and also need counters for "cogs"
volatile uint32_t coggn, coggl, coggr, coggc=0;

// experimental parallel SR
uint32_t shift_registerpar[32]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
uint16_t reg[32]={0};

// from AC
static uint32_t electroprob[8]={0, 3, 7, 15, 31, 63, 127, 255};

static uint32_t bits[8]={1, 2, 4, 8, 16, 32, 64, 128};

static uint32_t MASK[32]={4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294966785, 4294966275, 4294965255, 4294963215, 4294959135, 4294950975, 4294934655, 4294902015, 4294836735, 4294706175, 4294445055, 4293922815, 4292878335, 4290789375, 4286611455, 4278255615, 4261543935, 4228120575, 4161273855, 4027580415, 3760193535, 3225419775, 2155872255, 16777215};

static uint32_t SHIFT[32]={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; 

static uint8_t bitsz[256]={0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

static uint32_t masky[32]={0,0,0, // we don't use

			   0b00000000000000000000000000001111,			  
			   0b00000000000000000000000000011111,			  
			   0b00000000000000000000000000111111,			  
			   0b00000000000000000000000001111111,			  
			   0b00000000000000000000000011111111,			  

			   0b00000000000000000000000111111111,			  
			   0b00000000000000000000001111111111,			  
			   0b00000000000000000000011111111111,			  
			   0b00000000000000000000111111111111,			  
			   
			   0b00000000000000000001111111111111,			  
			   0b00000000000000000011111111111111,			  
			   0b00000000000000000111111111111111,			  
			   0b00000000000000001111111111111111,			  
			   
			   0b00000000000000011111111111111111,			  
			   0b00000000000000111111111111111111,			  
			   0b00000000000001111111111111111111,			  
			   0b00000000000011111111111111111111,			  
			   
			   0b00000000000111111111111111111111,			  
			   0b00000000001111111111111111111111,			  
			   0b00000000011111111111111111111111,			  
			   0b00000000111111111111111111111111,			  
			   
			   0b00000001111111111111111111111111,			  
			   0b00000011111111111111111111111111,			  
			   0b00000111111111111111111111111111,			  
			   0b00001111111111111111111111111111,			  

			   0b00011111111111111111111111111111,			  
			   0b00111111111111111111111111111111,			  
			   0b01111111111111111111111111111111,			   
			   0b11111111111111111111111111111111,			   
};

// TODO: test much greater range of slow speeds!

static uint16_t logger[1024]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 32, 32, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 44, 44, 44, 45, 45, 45, 45, 46, 46, 46, 47, 47, 47, 48, 48, 48, 49, 49, 49, 50, 50, 50, 51, 51, 51, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 57, 57, 57, 58, 58, 59, 59, 59, 60, 60, 61, 61, 61, 62, 62, 63, 63, 64, 64, 64, 65, 65, 66, 66, 67, 67, 68, 68, 69, 69, 69, 70, 70, 71, 71, 72, 72, 73, 73, 74, 74, 75, 75, 76, 76, 77, 78, 78, 79, 79, 80, 80, 81, 81, 82, 82, 83, 84, 84, 85, 85, 86, 86, 87, 88, 88, 89, 89, 90, 91, 91, 92, 93, 93, 94, 94, 95, 96, 96, 97, 98, 98, 99, 100, 100, 101, 102, 102, 103, 104, 105, 105, 106, 107, 107, 108, 109, 110, 110, 111, 112, 113, 113, 114, 115, 116, 117, 117, 118, 119, 120, 121, 121, 122, 123, 124, 125, 126, 127, 127, 128, 129, 130, 131, 132, 133, 134, 135, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 161, 162, 163, 164, 165, 166, 167, 168, 170, 171, 172, 173, 174, 175, 177, 178, 179, 180, 181, 183, 184, 185, 186, 188, 189, 190, 192, 193, 194, 196, 197, 198, 200, 201, 202, 204, 205, 206, 208, 209, 211, 212, 214, 215, 216, 218, 219, 221, 222, 224, 225, 227, 229, 230, 232, 233, 235, 236, 238, 240, 241, 243, 245, 246, 248, 250, 251, 253, 255, 257, 258, 260, 262, 264, 265, 267, 269, 271, 273, 275, 276, 278, 280, 282, 284, 286, 288, 290, 292, 294, 296, 298, 300, 302, 304, 306, 308, 310, 312, 314, 317, 319, 321, 323, 325, 328, 330, 332, 334, 337, 339, 341, 343, 346, 348, 351, 353, 355, 358, 360, 363, 365, 368, 370, 373, 375, 378, 380, 383, 385, 388, 391, 393, 396, 399, 401, 404, 407, 410, 413, 415, 418, 421, 424, 427, 430, 433, 436, 439, 441, 444, 448, 451, 454, 457, 460, 463, 466, 469, 472, 476, 479, 482, 485, 489, 492, 495, 499, 502, 506, 509, 513, 516, 520, 523, 527, 530, 534, 537, 541, 545, 549, 552, 556, 560, 564, 567, 571, 575, 579, 583, 587, 591, 595, 599, 603, 607, 611, 616, 620, 624, 628, 632, 637, 641, 645, 650, 654, 659, 663, 668, 672, 677, 681, 686, 691, 695, 700, 705, 710, 715, 719, 724, 729, 734, 739, 744, 749, 754, 760, 765, 770, 775, 780, 786, 791, 796, 802, 807, 813, 818, 824, 830, 835, 841, 847, 852, 858, 864, 870, 876, 882, 888, 894, 900, 906, 912, 918, 925, 931, 937, 944, 950, 956, 963, 969, 976, 983, 989, 996, 1003, 1010, 1017, 1024};

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

static uint8_t ghost_tapsL[32][4] = { // left hand path
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

static uint8_t ghost_tapsR[32][4] = { // right hands path
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

uint16_t leaks(uint16_t d, uint16_t p){ // try lazy, stickyt, leaky, decaying logic here...
  static uint16_t timer=0;
  // keep track of how many times this is called and flip bit
  // but that is too deterministic...

  //
  
  /*  timer++;
  if (timer>p){
    timer=0;
    d^=1;
    }*/
}

void TIM4_IRQHandler(void) 
// HERE we do speed and modes

{
  uint32_t temp;
  volatile static uint16_t tmp;
  
  TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 

  /*  
      tmp^=1;
      if (tmp) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
      else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */

    // map ADCs: note all modes are inverted

    // 0: nspd, 1: nlen, 2: nmode
    // 3: lspd, 4: llen, 5: lmode
    // 6: rspd, 7: rlen, 8: rmode
    // 9: cspd, 10: clen, 11: cmode

  
  // speedn
  totn=totn-smoothn[nn];
  smoothn[nn]=adc_buffer[0];
  totn+=smoothn[nn];
  nn++;
  if (nn>=SMOOTHINGS) nn=0;
  temp=totn/SMOOTHINGS;  
  speedn=logger[temp>>2];

  //moden
  temp=(adc_buffer[11]+lastlastmoden+lastmoden)/3; //smoothing necessary for higher speeds - TEST!
  lastlastmoden=lastmoden;
  lastmoden=temp;
  moden=63-(temp>>6); // 64 modes = 6 bits  

  // speedl
  totl=totl-smoothl[ll];
  smoothl[ll]=adc_buffer[3];
  totl+=smoothl[ll];
  ll++;
  if (ll>=SMOOTHINGS) ll=0;
  temp=totl/SMOOTHINGS;  
  speedl=logger[temp>>2];

  
  // lens from 4 to 32
  SRlengthn=31-(adc_buffer[1]>>7); // 12 bits to 5 bits
  if (SRlengthn<4) SRlengthn=4;

  SRlengthl=31-(adc_buffer[4]>>7); // 12 bits to 5 bits
  if (SRlengthl<4) SRlengthl=4;

  SRlengthr=31-(adc_buffer[7]>>7); // 12 bits to 5 bits
  if (SRlengthr<4) SRlengthr=4;

  SRlengthc=31-(adc_buffer[10]>>7); // 12 bits to 5 bits
  if (SRlengthc<4) SRlengthc=4;
  


}

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  static volatile uint16_t k=0,ll=0, n=0, accum, cnt=0;
  static volatile int16_t integrator=0, oldValue=0, tmp=0;
  uint16_t j, bit, xx;
    //low pass test
  static float SmoothData=0.0;
  float LPF_Beta = 0.02; // 0<ß<1
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

  /*
  k=(adc_buffer[12]); // now 12 bits only 
  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  */  

  // time PB4 with period=9 prescaler=8 we have 300KHz
  //  tmp^=1;
  //  if (tmp) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
  //  else   GPIOB->BSRRL=(1)<<4; //  write bits   

  /// TODO: test wheels across speeds and lengths of basic SRs
  // top one resets cycling/circling counter which wheels through SR
  // TESTED but sanity check lengths...
  
  countern++;
  if (countern>=speedn){
    countern=0;
    // do NSR - LFSR
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    shift_registern+= bitn | bitl;    
    coggn=0;
  }

  counterl++;
  if (counterl>=speedl){
    counterl=0;
    // do LSR - input from shift_registern
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerl=(shift_registerl<<1)+tmp;
  }
  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  }    

  // test output for now from l:
  tmp=((shift_registerl & masky[SRlengthl])>>(SRlengthl-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  
  
  // TEST SINGLE counter for sketches below...
  //  counterc++;
  //  if (counterc>=speedc){
  //    counterc=0;

  ///////////////////////////////////////////////////////
    // TODO: try parallel SRs with few bits, delay of different bits (but how to assign these - testing with bits in)
    // delay would be different lengths
    ///////////////////////////////////////////////////////
    /*
    k=(adc_buffer[12])>>4; // 8 bits

    if (k<64) tmp=1;
    else if (k<128) tmp=3;
    else if (k<192) tmp=7; // these values can also shift
    else tmp=15;
    k=tmp;
    tmp=0;    
    for (xx=0;xx<4;xx++){
      if (!(GPIOB->IDR & (1<<7))){
	reg[xx]++; // reg could also be from cv if we are pulse driven
      }
      if (reg[xx]>SRlengthn) reg[xx]=SRlengthn-1; 
      bitn=(shift_registerpar[xx]>>(SRlengthn-reg[xx]))&0x01; // bit shifted out
      //      shift_registerpar[xx]=(shift_registerpar[xx]<<1)+(((k>>xx)&0x01)^bitn); // with feeddbacks which could also be selected by pulse
      shift_registerpar[xx]=(shift_registerpar[xx]<<1)+((k>>xx)&0x01); // we are shifting left << so bit 31 is out last one
      if (bitn) tmp+=1023; // 4 possible bitns 4095/4=
    }

    // and potential feedback of those bits
    
    DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

    */
    
    ///////////////////////////////////////////////////////
    // sketch two-headed SR
    ///////////////////////////////////////////////////////
    //    SRlengthn=11;
    // one length transition seems to kill it...
    // shift left one reg
    /*
    bitn = ((shift_registerpar[0] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    shift_registerpar[0]=shift_registerpar[0]<<1; // we are shifting left << so bit 31 is out last one
    shift_registerpar[0]+= bitn;

    // right other reg
    
//    bitn = ((shift_registerpar[1] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[1] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[1] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[1] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24

    bitn = ((shift_registerpar[1] >> (SRlengthn-lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[1] >> (SRlengthn-lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[1] >> (SRlengthn-lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[1] >> (SRlengthn-lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // to handle length we need to do something about top bit which would otherwise shift down in!
    shift_registerpar[1]&= ~(1<<(SRlengthn+1));
    shift_registerpar[1]=shift_registerpar[1]>>1 | (bitn<<SRlengthn); //    lfsr = (lfsr >> 1) | (bit << 15);
    // glue half of one to the other?, merge or other bit ops and one/other
    shift_registerpar[2]=shift_registerpar[1] ^ shift_registerpar[0]; // tried with xor and and workings! and is good...
    if (shift_registerpar[0]==0)     shift_registerpar[0]=0xff;
    if (shift_registerpar[1]==0)     shift_registerpar[1]=0xff;

    tmp= ( (shift_registerpar[2]&1) + (shift_registerpar[2]&(1<<1)) + (shift_registerpar[2]&(1<<2)) + (shift_registerpar[2]&(1<<3)))<<8; 
    DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
    */
    
    // another approach with same SR

    /*
        bitn = ((shift_registerpar[0] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    shift_registerpar[0]=shift_registerpar[0]<<1; // we are shifting left << so bit 31 is out last one
    shift_registerpar[0]+= bitn;
    
    // right other reg
    
    bitn = ((shift_registerpar[0] >> (SRlengthn-lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (SRlengthn-lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (SRlengthn-lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (SRlengthn-lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24

    shift_registerpar[0]=shift_registerpar[0]>>1 | (bitn<<SRlengthn); //    lfsr = (lfsr >> 1) | (bit << 15);

    // extra shift or nothing happens
    // this shift could depend on CSR bit for example but quite often this dies out...
        
    if (!(GPIOB->IDR & (1<<7))){
      bitn = ((shift_registerpar[0] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    shift_registerpar[0]=shift_registerpar[0]<<1; // we are shifting left << so bit 31 is out last one
    shift_registerpar[0]+= bitn;
    }
       else {
    bitn = ((shift_registerpar[0] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    shift_registerpar[0]=shift_registerpar[0]>>1 | (bitn<<SRlengthn); //    lfsr = (lfsr >> 1) | (bit << 15);
    }
    
    tmp= ( (shift_registerpar[0]&1) + (shift_registerpar[0]&(1<<1)) + (shift_registerpar[0]&(1<<2)) + (shift_registerpar[0]&(1<<3)))<<8; 
    DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
    */
    
    ///////////////////////////////////////////////////////
    // test for parallell SR in top NSR
    // - feed data into top of parallel LFSRs, data read out from all bit outs: test for 12 bits, 12 parallel streams
    // - runs quite slowly so maybe ditch...
    ///////////////////////////////////////////////////////
    
    //    SRlengthn=12;
    /*
    k=(adc_buffer[12]); // now 12 bits only    
    tmp=0;
    for (xx=0;xx<12;xx++){

    bitn = ((shift_registerpar[xx] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[xx] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[xx] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[xx] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24

    //    bitn=leaks(bitn,8);
    
    shift_registerpar[xx]=shift_registerpar[xx]<<1; // we are shifting left << so bit 31 is out last one
    // test with say clkin on CSR PB7 as toggling which bit goes in!
    // is inverted I guess ???
    if (!(GPIOB->IDR & (1<<7)))    shift_registerpar[xx]+= bitn;
    else shift_registerpar[xx]+=(k>>xx)&0x01;
    tmp+=(bitn<<xx);
    }
    
    DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
    */    

  ///////////////////////////////////////////////////////
  // test with SR in SR for digital filter simulator - works with simple pass through
  // how we could simplify with more arrays, masks?
  // how we can substitute leaky logic for logic ops

  // 4 bits go into NSR as in original AC and are shifted
  // can also be feedback so is micro-SR in largerSR
    //  k=(adc_buffer[12])>>8;//+tmp)>>8; // now 12 bits only -> 4 bits
  // copy into ghost reg so we can feedback bits if we like

    //    k=(adc_buffer[12])>>8; // 4 bits // 8 bits

    /*  if (k<64) tmp=1;
  else if (k<128) tmp=3;
  else if (k<192) tmp=7; // these values can also shift
  else tmp=15;
  k=tmp;
  */

    /*
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
    */
  /////

  
    ///////////////////////////////////////////////////////
  // test for x(say 4) ADC bits in spaced out, feed through and DAC out, to lead towards digital filter simulation
  // not really working but kind of interesting - question is order of bits, also return of bits

  // sr in sr, parallel SR, feedback as bits or as addition into ADC in from DAC

    // try with different lengths
  /*
  if (cnt==4){
  k=(adc_buffer[12])>>8; // now 12 bits only -> 4 bits
  // test using moden as comparator in: adc_buffer[2]
  // but we can also use 4 bits and work like that
  // shifting these values, or spacings of these values...
  //  if (k<64) tmp=1;
//  else if (k<128) tmp=3;
//  else if (k<192) tmp=7; // these values can also shift
//  else tmp=15;
//  k=tmp;


  // comparator just outputs high if above level.
 
  if (k>(adc_buffer[2]>>8)) k=4094;
  
  cnt=0;
  // out - question is what is order of first bit? and return of bits
  }
  
  // how to do as 4 independent bits ie. number of bits is the important thing - more about dac out from this one as is same no?
  
  bitn = (shift_registern>>SRlengthn) & 0x01; // bit which would be shifted out
  shift_registern=(shift_registern<<1); // here or later?
  shift_registern+=((k&(1<<cnt))>>cnt);// ^ bitc; or internal feedback of bits on bits...
  shift_registern^=(shift_registerc&masky[SRlengthc]); // other kinds of logical opps but we need to mask for length
  // how do we mask for length?
  
// older not workings 
// try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
//  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
// put the 4 bits in
//  shift_registern += ((k&0x01) + ((k&0x02)<<7) + ((k&0x04)<<14) + ((k&0x08)<<21)); // would be 0 8-1 16-2 24-3 -
// without clearing bits is interesting also we can have other options like delay of some bits which would happen anyways
// eg. sample and then put bit in one by one
  
  // pass to shiftregl
  
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
  shift_registerl=(shift_registerl<<1)+bitn;

  // pass to shiftregc
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out - but we never use it so length effects nothing
  shift_registerc=(shift_registerc<<1)+bitl;

  // output based on SRlengthc or we can just accumulate bitc
  
  //  tmp= ( (shift_registerc&1) + (shift_registerc&(1<<1)) + (shift_registerc&(1<<2)) + (shift_registerc&(1<<3)))<<8; // olde one
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8;
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

  //    } // close of speedc FOR TEST sketches
 
    
}
