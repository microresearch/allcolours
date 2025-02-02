#include "stm32f10x_it.h"

/* SR/PWM modes in interrupts...

List of Shift Register modes = CV and pulse driven:

List of PWM modes now:

0-CV 
1-CV - SR CV/speed inverted

TODO: 

- selected low and high, CV and pulse modes

*CV_HF: 0, 1, 2, 3, 4, 7, 9, 23, 25, 26, 28, 29, 34, 35, 36, 41*
*CV_LF: 0, 1, 2, 3, 4, 7, 9, 23, 30, 32, 33, 34, 35, 37, 39, 40*

*PULSE_HF: 10, 11, 12, 13, 14, 15, 43, 44, 45, 48, 50, 52, 53, 56, 57, 58*
*PULSE_LF: 10, 11, 12, 13, 14, 15, 43, 44, 45, 47, 51, 52, 53, 56, 57, 58*

- function pointer/array speed test with main.c -> test below

*/

extern __IO uint16_t ADCBuffer[];
volatile uint32_t counterh=0, counter12h=0, counter12l=0,speedhh, speedll, counterl=0; // hfpulsecount, lfpulsecount;
volatile uint32_t modelpwm, modehpwm, modelsr=0, modehsr=0, hcount=0, lcount=0; // testing for modes
volatile uint8_t new_state[32], prev_state[32]={0}, flipped[32]={0}, new_statel[32], prev_statel[32]={0}, flippedl[32]={0}, probh, probl, togglel;
volatile uint32_t shift_registerh=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t shift_registerl=0xff; 
volatile uint32_t shift_registerx=0xff;
volatile uint32_t shift_registerxl=0xff;
volatile uint32_t SRlengthh=31, SRlengthl=31, hstack[4], lstack[4]; // length minus 1;
volatile uint32_t model, modeh, lengthbith=(1<<15), lengthbitl=(1<<15);
//volatile uint32_t lastspeedhh, lastspeedll;

void delay(unsigned long delay)
{
  while(delay) {
    delay--;
 asm("");
  }
}

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

void SysTick_Handler(void)
{
}

// for mode 13-electronotes = probh is not linear as we are interested in the number of bits set and not their position
// there are 8 positions which is 3 bits or we can make 16?
static uint32_t electroprob[8]={0, 3, 7, 15, 31, 63, 127, 255};

static uint32_t MASK[32]={4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294966785, 4294966275, 4294965255, 4294963215, 4294959135, 4294950975, 4294934655, 4294902015, 4294836735, 4294706175, 4294445055, 4293922815, 4292878335, 4290789375, 4286611455, 4278255615, 4261543935, 4228120575, 4161273855, 4027580415, 3760193535, 3225419775, 2155872255, 16777215};

static uint32_t SHIFT[32]={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; 

// log_gen:     print("%s," % int(1+(((starter*xyz)-312)/32))),

static uint16_t loggerdac[255]={312, 316, 320, 324, 329, 333, 338, 343, 347, 352, 357, 362, 367, 372, 377, 382, 387, 392, 398, 403, 409, 414, 420, 425, 431, 437, 443, 449, 455, 462, 468, 474, 481, 487, 494, 501, 507, 514, 521, 528, 536, 543, 550, 558, 566, 573, 581, 589, 597, 605, 613, 622, 630, 639, 648, 656, 665, 674, 684, 693, 702, 712, 722, 732, 742, 752, 762, 772, 783, 794, 804, 815, 826, 838, 849, 861, 872, 884, 896, 909, 921, 934, 946, 959, 972, 986, 999, 1013, 1026, 1040, 1055, 1069, 1084, 1098, 1113, 1129, 1144, 1160, 1175, 1191, 1208, 1224, 1241, 1258, 1275, 1292, 1310, 1328, 1346, 1364, 1383, 1402, 1421, 1440, 1460, 1480, 1500, 1520, 1541, 1562, 1583, 1605, 1627, 1649, 1671, 1694, 1717, 1741, 1764, 1788, 1813, 1838, 1863, 1888, 1914, 1940, 1966, 1993, 2020, 2048, 2076, 2104, 2133, 2162, 2191, 2221, 2251, 2282, 2313, 2345, 2377, 2409, 2442, 2475, 2509, 2543, 2578, 2613, 2649, 2685, 2721, 2759, 2796, 2834, 2873, 2912, 2952, 2992, 3033, 3074, 3116, 3158, 3202, 3245, 3289, 3334, 3380, 3426, 3472, 3520, 3568, 3616, 3666, 3716, 3766, 3818, 3870, 3923, 3976, 4030, 4085, 4141, 4197, 4254, 4312, 4371, 4431, 4491, 4552, 4615, 4677, 4741, 4806, 4871, 4938, 5005, 5073, 5142, 5213, 5284, 5356, 5429, 5503, 5578, 5654, 5731, 5809, 5888, 5968, 6050, 6132, 6216, 6300, 6386, 6473, 6562, 6651, 6742, 6834, 6927, 7021, 7117, 7214, 7312, 7412, 7513, 7615, 7719, 7824, 7931, 8039, 8149, 8260, 8372, 8486, 8602, 8719, 8838, 8959, 9081, 9205, 9330, 9457, 9586, 9717};

static uint16_t logger[1024]={312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 326, 327, 328, 329, 330, 331, 332, 333, 334, 336, 337, 338, 339, 340, 341, 343, 344, 345, 346, 347, 348, 350, 351, 352, 353, 354, 356, 357, 358, 359, 360, 362, 363, 364, 365, 367, 368, 369, 370, 372, 373, 374, 375, 377, 378, 379, 380, 382, 383, 384, 386, 387, 388, 390, 391, 392, 394, 395, 396, 398, 399, 400, 402, 403, 404, 406, 407, 409, 410, 411, 413, 414, 416, 417, 418, 420, 421, 423, 424, 425, 427, 428, 430, 431, 433, 434, 436, 437, 439, 440, 442, 443, 445, 446, 448, 449, 451, 452, 454, 455, 457, 458, 460, 462, 463, 465, 466, 468, 469, 471, 473, 474, 476, 477, 479, 481, 482, 484, 486, 487, 489, 491, 492, 494, 496, 497, 499, 501, 502, 504, 506, 507, 509, 511, 513, 514, 516, 518, 520, 521, 523, 525, 527, 528, 530, 532, 534, 536, 538, 539, 541, 543, 545, 547, 549, 550, 552, 554, 556, 558, 560, 562, 564, 566, 567, 569, 571, 573, 575, 577, 579, 581, 583, 585, 587, 589, 591, 593, 595, 597, 599, 601, 603, 605, 607, 609, 611, 613, 616, 618, 620, 622, 624, 626, 628, 630, 632, 635, 637, 639, 641, 643, 645, 648, 650, 652, 654, 656, 659, 661, 663, 665, 668, 670, 672, 674, 677, 679, 681, 684, 686, 688, 691, 693, 695, 698, 700, 702, 705, 707, 710, 712, 714, 717, 719, 722, 724, 727, 729, 732, 734, 737, 739, 742, 744, 747, 749, 752, 754, 757, 759, 762, 765, 767, 770, 772, 775, 778, 780, 783, 786, 788, 791, 794, 796, 799, 802, 804, 807, 810, 813, 815, 818, 821, 824, 826, 829, 832, 835, 838, 841, 843, 846, 849, 852, 855, 858, 861, 864, 867, 870, 872, 875, 878, 881, 884, 887, 890, 893, 896, 899, 903, 906, 909, 912, 915, 918, 921, 924, 927, 930, 934, 937, 940, 943, 946, 950, 953, 956, 959, 962, 966, 969, 972, 976, 979, 982, 986, 989, 992, 996, 999, 1002, 1006, 1009, 1013, 1016, 1020, 1023, 1026, 1030, 1033, 1037, 1040, 1044, 1048, 1051, 1055, 1058, 1062, 1065, 1069, 1073, 1076, 1080, 1084, 1087, 1091, 1095, 1098, 1102, 1106, 1110, 1113, 1117, 1121, 1125, 1129, 1132, 1136, 1140, 1144, 1148, 1152, 1156, 1160, 1163, 1167, 1171, 1175, 1179, 1183, 1187, 1191, 1195, 1199, 1204, 1208, 1212, 1216, 1220, 1224, 1228, 1232, 1237, 1241, 1245, 1249, 1253, 1258, 1262, 1266, 1271, 1275, 1279, 1283, 1288, 1292, 1297, 1301, 1305, 1310, 1314, 1319, 1323, 1328, 1332, 1337, 1341, 1346, 1350, 1355, 1360, 1364, 1369, 1373, 1378, 1383, 1387, 1392, 1397, 1402, 1406, 1411, 1416, 1421, 1426, 1430, 1435, 1440, 1445, 1450, 1455, 1460, 1465, 1470, 1475, 1480, 1485, 1490, 1495, 1500, 1505, 1510, 1515, 1520, 1525, 1531, 1536, 1541, 1546, 1551, 1557, 1562, 1567, 1573, 1578, 1583, 1589, 1594, 1599, 1605, 1610, 1616, 1621, 1627, 1632, 1638, 1643, 1649, 1655, 1660, 1666, 1671, 1677, 1683, 1688, 1694, 1700, 1706, 1711, 1717, 1723, 1729, 1735, 1741, 1747, 1753, 1758, 1764, 1770, 1776, 1782, 1788, 1795, 1801, 1807, 1813, 1819, 1825, 1831, 1838, 1844, 1850, 1856, 1863, 1869, 1875, 1882, 1888, 1894, 1901, 1907, 1914, 1920, 1927, 1933, 1940, 1946, 1953, 1960, 1966, 1973, 1980, 1986, 1993, 2000, 2007, 2013, 2020, 2027, 2034, 2041, 2048, 2055, 2062, 2069, 2076, 2083, 2090, 2097, 2104, 2111, 2118, 2126, 2133, 2140, 2147, 2155, 2162, 2169, 2177, 2184, 2191, 2199, 2206, 2214, 2221, 2229, 2236, 2244, 2251, 2259, 2267, 2274, 2282, 2290, 2298, 2305, 2313, 2321, 2329, 2337, 2345, 2353, 2361, 2369, 2377, 2385, 2393, 2401, 2409, 2417, 2426, 2434, 2442, 2450, 2459, 2467, 2475, 2484, 2492, 2501, 2509, 2518, 2526, 2535, 2543, 2552, 2561, 2569, 2578, 2587, 2595, 2604, 2613, 2622, 2631, 2640, 2649, 2658, 2667, 2676, 2685, 2694, 2703, 2712, 2721, 2731, 2740, 2749, 2759, 2768, 2777, 2787, 2796, 2806, 2815, 2825, 2834, 2844, 2853, 2863, 2873, 2883, 2892, 2902, 2912, 2922, 2932, 2942, 2952, 2962, 2972, 2982, 2992, 3002, 3012, 3023, 3033, 3043, 3053, 3064, 3074, 3085, 3095, 3105, 3116, 3127, 3137, 3148, 3158, 3169, 3180, 3191, 3202, 3212, 3223, 3234, 3245, 3256, 3267, 3278, 3289, 3301, 3312, 3323, 3334, 3346, 3357, 3368, 3380, 3391, 3403, 3414, 3426, 3437, 3449, 3461, 3472, 3484, 3496, 3508, 3520, 3532, 3544, 3556, 3568, 3580, 3592, 3604, 3616, 3629, 3641, 3653, 3666, 3678, 3691, 3703, 3716, 3728, 3741, 3754, 3766, 3779, 3792, 3805, 3818, 3831, 3844, 3857, 3870, 3883, 3896, 3909, 3923, 3936, 3949, 3963, 3976, 3989, 4003, 4017, 4030, 4044, 4058, 4071, 4085, 4099, 4113, 4127, 4141, 4155, 4169, 4183, 4197, 4211, 4226, 4240, 4254, 4269, 4283, 4298, 4312, 4327, 4342, 4356, 4371, 4386, 4401, 4416, 4431, 4446, 4461, 4476, 4491, 4506, 4522, 4537, 4552, 4568, 4583, 4599, 4615, 4630, 4646, 4662, 4677, 4693, 4709, 4725, 4741, 4757, 4773, 4790, 4806, 4822, 4838, 4855, 4871, 4888, 4904, 4921, 4938, 4954, 4971, 4988, 5005, 5022, 5039, 5056, 5073, 5090, 5108, 5125, 5142, 5160, 5177, 5195, 5213, 5230, 5248, 5266, 5284, 5301, 5319, 5337, 5356, 5374, 5392, 5410, 5429, 5447, 5465, 5484, 5503, 5521, 5540, 5559, 5578, 5597, 5615, 5635, 5654, 5673, 5692, 5711, 5731, 5750, 5770, 5789, 5809, 5829, 5848, 5868, 5888, 5908, 5928, 5948, 5968, 5988, 6009, 6029, 6050, 6070, 6091, 6111, 6132, 6153, 6174, 6195, 6216, 6237, 6258, 6279, 6300, 6322, 6343, 6365, 6386, 6408, 6430, 6451, 6473, 6495, 6517, 6539, 6562, 6584, 6606, 6629, 6651, 6674, 6696, 6719, 6742, 6765, 6787, 6810, 6834, 6857, 6880, 6903, 6927, 6950, 6974, 6997, 7021, 7045, 7069, 7093, 7117, 7141, 7165, 7189, 7214, 7238, 7263, 7287, 7312, 7337, 7362, 7387, 7412, 7437, 7462, 7487, 7513, 7538, 7564, 7590, 7615, 7641, 7667, 7693, 7719, 7745, 7772, 7798, 7824, 7851, 7877, 7904, 7931, 7958, 7985, 8012, 8039, 8066, 8094, 8121, 8149, 8176, 8204, 8232, 8260, 8288, 8316, 8344, 8372, 8401, 8429, 8458, 8486, 8515, 8544, 8573, 8602, 8631, 8661, 8690, 8719, 8749, 8779, 8808, 8838, 8868, 8898, 8928, 8959, 8989, 9020, 9050, 9081, 9112, 9142, 9173, 9205, 9236, 9267, 9299, 9330, 9362, 9393, 9425, 9457, 9489, 9521, 9554, 9586, 9619, 9651, 9684, 9717, 9750, 9783, 9816, 9849, 9883, 9916, 9950};

// logforSR could be a lot slower at one end - test/generate this! 2^14

static uint16_t logforSR[1024]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 31, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 37, 37, 38, 38, 39, 39, 39, 40, 40, 40, 41, 41, 42, 42, 43, 43, 43, 44, 44, 45, 45, 46, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 58, 58, 59, 59, 60, 60, 61, 62, 62, 63, 63, 64, 65, 65, 66, 67, 67, 68, 69, 69, 70, 71, 71, 72, 73, 73, 74, 75, 76, 76, 77, 78, 79, 79, 80, 81, 82, 82, 83, 84, 85, 86, 87, 87, 88, 89, 90, 91, 92, 93, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 117, 118, 119, 120, 121, 122, 124, 125, 126, 127, 128, 130, 131, 132, 133, 135, 136, 137, 139, 140, 141, 143, 144, 145, 147, 148, 150, 151, 153, 154, 155, 157, 158, 160, 162, 163, 165, 166, 168, 169, 171, 173, 174, 176, 178, 179, 181, 183, 185, 186, 188, 190, 192, 194, 196, 197, 199, 201, 203, 205, 207, 209, 211, 213, 215, 217, 219, 221, 224, 226, 228, 230, 232, 235, 237, 239, 241, 244, 246, 248, 251, 253, 256, 258, 260, 263, 265, 268, 271, 273, 276, 278, 281, 284, 287, 289, 292, 295, 298, 301, 303, 306, 309, 312, 315, 318, 321, 324, 327, 331, 334, 337, 340, 343, 347, 350, 353, 357, 360, 364, 367, 371, 374, 378, 381, 385, 389, 392, 396, 400, 404, 408, 412, 415, 419, 423, 428, 432, 436, 440, 444, 448, 453, 457, 461, 466, 470, 475, 479, 484, 488, 493, 498, 503, 507, 512, 517, 522, 527, 532, 537, 542, 548, 553, 558, 563, 569, 574, 580, 585, 591, 596, 602, 608, 614, 620, 625, 631, 637, 644, 650, 656, 662, 669, 675, 681, 688, 694, 701, 708, 715, 721, 728, 735, 742, 749, 756, 764, 771, 778, 786, 793, 801, 809, 816, 824, 832, 840, 848, 856, 864, 872, 881, 889, 898, 906, 915, 924, 932, 941, 950, 959, 968, 978, 987, 996, 1006, 1016, 1025, 1035, 1045, 1055, 1065, 1075, 1085, 1096, 1106, 1117, 1127, 1138, 1149, 1160, 1171, 1182, 1194, 1205, 1216, 1228, 1240, 1252, 1264, 1276, 1288, 1300, 1312, 1325, 1338, 1350, 1363, 1376, 1389, 1403, 1416, 1430, 1443, 1457, 1471, 1485, 1499, 1513, 1528, 1542, 1557, 1572, 1587, 1602, 1617, 1633, 1648, 1664, 1680, 1696, 1712, 1729, 1745, 1762, 1778, 1795, 1813, 1830, 1847, 1865, 1883, 1901, 1919, 1937, 1956, 1974, 1993, 2012, 2031, 2051, 2070, 2090, 2110, 2130, 2150, 2171, 2192, 2212, 2234, 2255, 2276, 2298, 2320, 2342, 2364, 2387, 2410, 2433, 2456, 2479, 2503, 2527, 2551, 2575, 2600, 2625, 2650, 2675, 2700, 2726, 2752, 2778, 2805, 2832, 2859, 2886, 2914, 2941, 2969, 2998, 3026, 3055, 3084, 3114, 3143, 3173, 3204, 3234, 3265, 3296, 3328, 3359, 3391, 3424, 3456, 3489, 3522, 3556, 3590, 3624, 3659, 3694, 3729, 3764, 3800, 3837, 3873, 3910, 3947, 3985, 4023, 4061, 4100, 4139, 4179, 4218, 4259, 4299, 4340, 4382, 4423, 4466, 4508, 4551, 4595, 4638, 4683, 4727, 4772, 4818, 4864, 4910, 4957, 5004, 5052, 5100, 5149, 5198, 5247, 5297, 5348, 5399, 5450, 5502, 5555, 5608, 5661, 5715, 5770, 5825, 5880, 5936, 5993, 6050, 6108, 6166, 6225, 6284, 6344, 6404, 6465, 6527, 6589, 6652, 6715, 6779, 6844, 6909, 6975, 7042, 7109, 7177, 7245, 7314, 7384, 7454, 7525, 7597, 7669, 7743, 7816, 7891, 7966, 8042, 8119, 8196, 8274, 8353, 8433, 8513, 8594, 8676, 8759, 8842, 8927, 9012, 9098, 9184, 9272, 9360, 9450, 9540, 9631, 9722, 9815, 9909, 10003, 10098, 10195, 10292, 10390, 10489, 10589, 10690, 10792, 10895, 10999, 11103, 11209, 11316, 11424, 11533, 11643, 11754, 11866, 11979, 12093, 12208, 12325, 12442, 12561, 12681, 12801, 12923, 13047, 13171, 13297, 13423, 13551, 13680, 13811, 13942, 14075, 14210, 14345, 14482, 14620, 14759, 14900, 15042, 15185, 15330, 15476, 15624, 15772, 15923, 16075, 16228, 16383};


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



// test for function pointers

/*
void CGS_one(void){  //->>>>>>>>>>>>>> 0- pulse clock in (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)
  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out

	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400)); // 0x0080 is clock bit in!
	else shift_registerh = (shift_registerh<<1) + (bith | (!(GPIOB->IDR & 0x0400))); 

	// shift register bits output - inverted on PC13 and 14;
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;  
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
}

void (*HF_TIM2_modes[8])(void)={CGS_one, CGS_one, CGS_one, CGS_one, CGS_one, CGS_one, CGS_one, CGS_one};
*/

// run with HF_TIM2_modes[modehsr]();


	void case_0(void){
	  uint8_t bitl;
      //->>>>>>>>>>>>>> 0- pulse (PB5) toggles loopback to OR with new input bit (PB6) /or just accept new input bit (CGS)
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out

      if (GPIOB->IDR & 0x0020) shift_registerl= (shift_registerl<<1) + (!(GPIOB->IDR & 0x0040)); // switched around for speed
      else shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); // PB5 and PB6
      // shift register bits output - inverted on PB13 and 14;
      	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PB13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PB14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;  
      	}
	
    void case_1(void){
      	  uint8_t bitl;
	//->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -
    
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + (!(GPIOB->IDR & 0x0040));
	else shift_registerl = (shift_registerl<<1) + ((bitl ^ !(GPIOB->IDR & 0x0040)));

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	}
    
      void case_2(void){
	uint8_t bitl;
	//->>>>>>>>>>>>>> 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR selected with counter and pulse
	lcount++;
	if (lcount>SRlengthl) lcount=0;
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 

	shift_registerl= (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040));

	if( !(GPIOB->IDR & 0x0020)) shift_registerl ^= (1<<lcount); // if we have pulse and lcount then flip that bit inside SR... rest all the same...

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	}
    
      void case_3(void){ //*
		uint8_t bitl;
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	}

      void case_4(void){
	uint8_t bitl;
	//->>>>>>>>>>>>>> 4- parity for loopback XOR is determined by pulsed bits in -> select bits with pulse and queue 
	lcount++;
	if (lcount>SRlengthl) lcount=0;
	if( !(GPIOB->IDR & 0x0020)) {
	  lstack[3]=lstack[2];
	  lstack[2]=lstack[1];
	  lstack[1]=lstack[0];
	  lstack[0]=lcount+1; // bump it on to the lstack
	}	  

	bitl= ((shift_registerl >> lstack[0]) ^ (shift_registerl >> lstack[1]) ^ (shift_registerl >> lstack[2]) ^ (shift_registerl >> lstack[3])) & 1u; // 32 is 31, 29, 25, 24
	shift_registerl= (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); // TESTY - to OR in new bit or not?

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	}

    void case_5(void){ // was 7
      	uint8_t bitl;
	//->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed Q of lengths?
	// no use of in bit
	// !note: swop l and h when port to low!
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -
	if (lcount>7) lcount=0;
	if( !(GPIOB->IDR & 0x0020)) probl^=(1<<lcount);
	lcount++;
	if (((probl | shift_registerl) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerh>>SRlengthl) & 0x01); // fixed for swop
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000; 
	}

    void case_6(void){ // was 9
      	uint8_t bitl;
	// 9- LFSR noise only with varying taps depending on length with new bit ORed in depending on pulse - for LF we can do mirroring!
	if (shift_registerl==0) shift_registerl=0xff; // catch it!
	bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;  
	}

    void case_7(void){ //was 23 -  experimental modes 23+ here and 32+ in pulses - TESTED/WORKING!
      	uint8_t bitl;
	// shifting the array of LFSR taps = ghost_tapsH on the high side
	// clock pulse shifts one selected by pulse 
	if (!(GPIOB->IDR & 0x0020)) lcount++;
	if (lcount>3) lcount=0;
	if (!(GPIOB->IDR & 0x0040)) {
	  ghost_tapsL[SRlengthl][lcount+1]+=1;
	  ghost_tapsL[SRlengthl][lcount+1]%=SRlengthl;
	}
	
	if (shift_registerl==0) shift_registerl=0xff; // catch it!
	bitl= ((shift_registerl >> (ghost_tapsL[SRlengthl][0])) ^ (shift_registerl >> (ghost_tapsL[SRlengthl][1])) ^ (shift_registerl >> (ghost_tapsL[SRlengthl][2])) ^ (shift_registerl >> (ghost_tapsL[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerl = (shift_registerl<<1) + bitl;
	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;  
	}

    void case_8(void){ // was 30
      	uint8_t bitl;
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)-> our 3 options if we have a bit 0x0020
	// - TESTED/WORKING!
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (!(GPIOB->IDR & 0x0020)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;
	}
	}

    void case_9(void){ // was 32
      	uint8_t bitl;
	// extra mode in which (both) pulse on is triggered by bitl but gated off by input bit or pulse - but do we need like a toggle?????
	//-BASE it on::: >>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	// - TESTED/WORKING!
	
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BSRR = 0b0100000000000000; 
	}

      void case_10(void){ // was 33 - and invert the above
		uint8_t bitl;
	// extra mode in which (both) pulse on is triggered by bitl but gated off by input bit or pulse - but do we need like a toggle?????
	//-BASE it on::: >>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	// - TESTED/WORKING!
	
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BSRR = 0b0010000000000000;  // clear PC13 else write one
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BSRR = 0b0100000000000000;  
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BRR = 0b0100000000000000; 
	}
	
    void case_11(void){ // was 34
      	uint8_t bitl;
	// extra modes use pulse or input bit as length of SR controller: see mode 42 below
	/// length thing	
	// - TESTED/WORKING!
	lcount++;
      if (lcount>31) lcount=4;
      if (!(GPIOB->IDR & 0x0020)) {
	SRlengthl=lcount;
	lengthbitl=(1<<(SRlengthl/2));
	}
      // as mode 3::::
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	}
	
    void case_12(void){ // was 35
      	uint8_t bitl;
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// can use input bit as length of either SR = here is regularSR
	// works well
	lcount++;
	if (lcount>31) lcount=4;
	if (!(GPIOB->IDR & 0x0020)) {
	  SRlengthl=lcount;
	  lengthbitl=(1<<(SRlengthl/2));
	}
	
	if (shift_registerxl==0) shift_registerxl=0xff; // catch it!
	//	bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	bitl= ((shift_registerxl >> 31) ^ (shift_registerxl >> 29) ^ (shift_registerxl >> 25) ^ (shift_registerxl >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerxl = (shift_registerxl<<1) + bitl; // could or with incoming as we don't use this TESTY: shift_registerxl = (shift_registerx<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl){ // calculate and output new bitl with void case_3 Turing Machine(void){
	  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);

	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}
	}

    void case_13(void){ // was 37
      	uint8_t bitl;
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// with input bit or'ed in
	if (shift_registerxl==0) shift_registerxl=0xff; // catch it!
	//	bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	bitl= ((shift_registerxl >> 31) ^ (shift_registerxl >> 29) ^ (shift_registerxl >> 25) ^ (shift_registerxl >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerxl = (shift_registerxl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl){ // calculate and output new bitl with void case_3 Turing Machine(void){

	  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);
	  
	
	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}
	}

    void case_14(void){ // was 39
      	uint8_t bitl;
	// as above but LFSR?
	// working/.tested
      if (!(GPIOB->IDR & 0x0020)) togglel^=1; 

	if (togglel)
	  {
	    if (shift_registerl==0) shift_registerl=0xff; // catch it!
	    bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	    shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040));  

	    if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	    else GPIOB->BSRR = 0b0010000000000000;  
	    if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	    else GPIOB->BSRR = 0b0100000000000000;
	  }
	}

    void case_15(void){ // was 40
      uint8_t tmp, bitl;
      // pulse in means a divide/flip flop
	// TESTED/WORKING but is only that divide on one bit..FIXED TESTED
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);
	
	new_statel[0]=bitl;
	if (prev_statel[0]==0 && new_statel[0]==1) flippedl[0]^=1;
	prev_statel[0]=new_statel[0];	

	if (shift_registerl & lengthbitl) new_statel[1]=1;
	else new_statel[1]=0;
	if (prev_statel[1]==1 && new_statel[1]==1) flippedl[1]^=1;
	prev_statel[1]=new_statel[1];	
	
	if (!(GPIOB->IDR & 0x0020)) {
	  bitl=flippedl[0];
	  tmp=flippedl[1];
	}
	else tmp=new_statel[1];
	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (tmp) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	}


      void case_0h(void){
	uint8_t bith;
	//->>>>>>>>>>>>>> 0- pulse clock in (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out
	
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400)); // 0x0080 is clock bit in!
	else shift_registerh = (shift_registerh<<1) + (bith | (!(GPIOB->IDR & 0x0400))); 

	// shift register bits output - inverted on PC13 and 14;
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;  
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	}

      void case_1h(void){
	uint8_t bith;
	//->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
    
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400));
	else shift_registerh = (shift_registerh<<1) + ((bith ^ !(GPIOB->IDR & 0x0400)));

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000; 
	}
    
      void case_2h(void){
	uint8_t bith;
	//->>>>>>>>>>>>>> 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR selected with counter and pulse
	hcount++;
	if (hcount>SRlengthh) hcount=0;
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 

	shift_registerh= (shift_registerh<<1) + (bith | !(GPIOB->IDR & 0x0400));

	if( !(GPIOB->IDR & 0x0080)) shift_registerh ^= (1<<hcount); // if we have pulse and hcount then flip that bit inside SR... rest all the same...

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000; 
	}
    
      void case_3h(void){ //*
	uint8_t bith;
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000; 
	}

      void case_4h(void){
	uint8_t bith;
	//->>>>>>>>>>>>>> 4- parity for loopback XOR is determined by pulsed bits in -> select bits with pulse and queue 
	hcount++;
	if (hcount>SRlengthh) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) {
	  hstack[3]=hstack[2];
	  hstack[2]=hstack[1];
	  hstack[1]=hstack[0];
	  hstack[0]=hcount+1; // bump it on to the hstack
	}	  

	bith= ((shift_registerh >> hstack[0]) ^ (shift_registerh >> hstack[1]) ^ (shift_registerh >> hstack[2]) ^ (shift_registerh >> hstack[3])) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh= (shift_registerh<<1) + (bith | !(GPIOB->IDR & 0x0400)); // TESTY - to OR in new bit or not?

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000; 
	}

      void case_5h(void){ // was 7
	uint8_t bith;
	//->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed Q of lengths?
	// no use of in bit
	// !note: swop l and h when port to low!
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	if (hcount>7) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) probh^=(1<<hcount);
	hcount++;
	if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>SRlengthl) & 0x01); 
	else shift_registerh = (shift_registerh<<1) + bith;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000; 
	else GPIOC->BSRR = 0b0100000000000000; 
	}

      void case_6h(void){  // was 9
	uint8_t bith;
	// 9- LFSR noise only with varying taps depending on length with new bit ORed in depending on pulse - for LF we can do mirroring!
	if (shift_registerh==0) shift_registerh=0xff; // catch it!
	bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;  
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000;  
	}

      void case_7h(void){ // was 23 --> experimental modes 23+ here and 32+ in pulses - TESTED/WORKING!
	uint8_t bith;
	// shifting the array of LFSR taps = ghost_tapsH on the high side
	// clock pulse shifts one selected by pulse 
	if (!(GPIOB->IDR & 0x0080)) hcount++;
	if (hcount>3) hcount=0;
	if (!(GPIOB->IDR & 0x0400)) {
	  ghost_tapsH[SRlengthh][hcount+1]+=1;
	  ghost_tapsH[SRlengthh][hcount+1]%=SRlengthh;
	}
	
	if (shift_registerh==0) shift_registerh=0xff; // catch it!
	bith= ((shift_registerh >> (ghost_tapsH[SRlengthh][0])) ^ (shift_registerh >> (ghost_tapsH[SRlengthh][1])) ^ (shift_registerh >> (ghost_tapsH[SRlengthh][2])) ^ (shift_registerh >> (ghost_tapsH[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh = (shift_registerh<<1) + bith;
	
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;  
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000;  
	}

      void case_8h(void){ // was 25
	uint8_t tmp, bith;
	// SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits - TESTED/WORKING!
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out
	shift_registerh = (shift_registerh<<1) + (bith | (!(GPIOB->IDR & 0x0400)));
	// do the loop back in
	if( !(GPIOB->IDR & 0x0080)) hcount++;
	if (hcount>SRlengthh) hcount=0;
	tmp = (shift_registerh>>hcount) & 0x01;
	// where to put that bit? XOR it with first bit
	if ( (shift_registerh & 0x01) ^ tmp) shift_registerh |= 0x01;// set the first bit
	else shift_registerh &= ~(0x01); // clear the first bit
	
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000; 
	}

      void case_9h(void){ // was 26
	uint8_t bith;
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// can use input bit as length of either SR
	// also can still use in clocking side of things
	// no use of input bit...
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with void case_3 Turing Machineh(void){

	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);
	  
	
	  if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOC->BSRR = 0b0010000000000000;  
	  if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOC->BSRR = 0b0100000000000000;
	}
	}

      void case_10h(void){ // was 28
	uint8_t bith;
	// Independent LFSR clocking regular SR (only in CV as speed) - as mode 26 but now we use 0x0080 bit also to see if we shift things...
	// no use of input bit... - TESTED/WORKING!
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith && !(GPIOB->IDR & 0x0080) ){ // calculate and output new bith with void case_3 Turing Machineh(void){

	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);
	  
	
	  if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOC->BSRR = 0b0010000000000000;  
	  if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOC->BSRR = 0b0100000000000000;
	}
	}

      void case_11h(void){ // was 29
	uint8_t bith;
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)-> our 3 options if we have a bit 0x0080
	// - TESTED/WORKING!
	if (!(GPIOB->IDR & 0x0080)){
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000;
	}
	}
	
      void case_12h(void){ // was 34
	uint8_t bith;
	// extra modes use pulse or input bit as length of SR controller: see mode 42 below
	/// length thing	
	// - TESTED/WORKING!
	hcount++;
      if (hcount>31) hcount=4;
      if (!(GPIOB->IDR & 0x0080)) {
	SRlengthh=hcount;
	lengthbith=(1<<(SRlengthh/2));
	}
      // as mode 3::::
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000; 
	}

	/////////////new /experimental
	
      void case_13h(void){ // was 35
	uint8_t bith;
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// can use input bit as length of either SR = here is regularSR
	// works well
	hcount++;
	if (hcount>31) hcount=4;
	if (!(GPIOB->IDR & 0x0080)) {
	  SRlengthh=hcount;
	  lengthbith=(1<<(SRlengthh/2));
	}
	
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with void case_3 Turing Machineh(void){
	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	  if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOC->BSRR = 0b0010000000000000;  
	  if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOC->BSRR = 0b0100000000000000;
	}
	}

      void case_14h(void){ // was 36
	uint8_t bith;
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// can use input bit as length of either SR = here is shift_regx
	// works ok not so interesting as 35
	uint8_t SRlengthx=31;
       	hcount++;
	if (hcount>31) hcount=4;
	if (!(GPIOB->IDR & 0x0080)) {
	  SRlengthx=hcount;
	}
	
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	bith= ((shift_registerx >> (lfsr_taps[SRlengthx][0])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][1])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][2])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][3]))) & 1u; // 32 is 31, 29, 25, 24
	//	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with void case_3 Turing Machineh(void){

	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);
	  
	  if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOC->BSRR = 0b0010000000000000;  
	  if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOC->BSRR = 0b0100000000000000;
	  }
	}

      void case_15h(void){ // was 41
	uint8_t bith;
	// pulse in means double a step..
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);

	if (!(GPIOB->IDR & 0x0080)) {
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);
	}
	
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000; 	
	}	


	void case_16(void){ // was 11 - leave in middle// MAYBE put this in middle of CV select mode for easy access TODO
      //->>>>>>>>>>>>>> CV selects length of SR which will stay with us .. -> LFSR here
	  uint8_t bitl;
	  uint32_t clvalue;	  
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      SRlengthl=31-(clvalue>>11);
      if (SRlengthl<4) SRlengthl=4;
      lengthbitl=(1<<(SRlengthl/2));
      if (shift_registerl==0) shift_registerl=0xff;
      bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
      shift_registerl = (shift_registerl<<1) + ((bitl | !(GPIOB->IDR & 0x0040))); // PB7 and PB10

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;  
      }

    void case_17(void){ // was 10
      	  uint8_t bitl;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit 
      lcount++;
      if (lcount>7) lcount=0;
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
      
      if((clvalue>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
      else shift_registerl = (shift_registerl<<1) + bitl;

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000; 
      }
      
    void case_18(void){ // was 12 - works fine with cv in
      	  uint8_t bitl;
	    uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      //->>>>>>>>>>>>>> NEW mode TESTY: entry of ADC in from CV into upper bits?
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out

      if (counter12l == 9){       // every 8 cycles
	counter12l=0;
	shift_registerl &= MASK[SRlengthl]; // MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
	shift_registerl +=(clvalue>>8)<<(SHIFT[SRlengthl]); 
      }
      counter12l++;

      shift_registerl=(shift_registerl<<1) + (bitl |  (!(GPIOB->IDR & 0x0040))); // cycle around and OR in pulse bit! TESTY!

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
      }

    void case_19(void){ // was 13
      	  uint8_t bitl;
	    uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // we do not use bit IN!
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -
      probl=clvalue>>13; // 3 bits now for electroprob array
      probl=electroprob[probl];

      if (((probl | shift_registerl) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerl>>SRlengthl) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerl = (shift_registerl<<1) + bitl;

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
      }

    void case_20(void){ // was 14 - could replace mode or one of these ???
      uint8_t bitl, numflips, x;
      uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      //->>>>>>>>>>>>>> uses CV as speed/flipflop/clock divider
      // pulse in inverts the cycling bit in a la Turing Machine - cycle bit or invert bit = thus we do use input bit
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
      //      origbitl=bitl;
      if (GPIOB->IDR & 0x0040) shift_registerl =  (shift_registerl<<1) + bitl;
      else shift_registerl = (shift_registerl<<1) + (!bitl);

      // flip flop: rising edge - if last was 0 and now is 1 then we trigger flip 1-0 or 0-1
      numflips=(clvalue>>12); //or 15-(clvalue>>12) if we wish it to go in the opposite direction
      new_statel[0]=bitl;
      if (prev_statel[0]==0 && new_statel[0]==1) flippedl[0]^=1;
      prev_statel[0]=new_statel[0];	

      for (x=1;x<numflips;x++){ 
	new_statel[x]=flippedl[x-1];
	if (prev_statel[x]==0 && new_statel[x]==1) flippedl[x]^=1;
	prev_statel[x]=new_statel[x];
      }
      if (numflips>0)	bitl=flippedl[numflips-1];

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;
      //      if (origbitl) GPIOB->BRR = 0b0100000000000000;  // original bitl 
      //      else GPIOB->BSRR = 0b0100000000000000;
      if (shift_registerl & lengthbitl) {
	if (bitl)	GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000;
      }
      }
	
    void case_21(void){ // was 15
      uint8_t bitl, numflips, x;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      //->>>>>>>>>>>>>> as mode 14=speed divider with XOR rungler: XOR out with input bit
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
      //      origbitl=bitl;
      shift_registerl = (shift_registerl<<1) + ((bitl) ^ (!(GPIOB->IDR & 0x0040)));

      numflips=(clvalue>>12); //or 15-(clvalue>>12) if we wish it to go in the opposite direction
      new_statel[0]=bitl;
      if (prev_statel[0]==0 && new_statel[0]==1) flippedl[0]^=1;
      prev_statel[0]=new_statel[0];	

      for (x=1;x<numflips;x++){ 
	new_statel[x]=flippedl[x-1];
	if (prev_statel[x]==0 && new_statel[x]==1) flippedl[x]^=1;
	prev_statel[x]=new_statel[x];
      }
      if (numflips>0)	bitl=flippedl[numflips-1];
      
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;
      if (shift_registerl & lengthbitl) {
	if (bitl)	GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;
      }
      //      if (origbitl) GPIOB->BRR = 0b0100000000000000;  // original bitl 
      //      else GPIOB->BSRR = 0b0100000000000000;
      }

    void case_22(void){ // was 43
      	  uint8_t bitl;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      // as above but other way round with CV for length and incoming bits for probability of TM
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -

      SRlengthl=31-(clvalue>>11);
      if (SRlengthl<4) SRlengthl=4;
      lengthbitl=(1<<(SRlengthl/2));

      if (lcount>7) lcount=0;
      if( !(GPIOB->IDR & 0x0040)) probl^=(1<<lcount);
      lcount++;
      
      if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + bitl;
      else shift_registerl = (shift_registerl<<1) + (!bitl);
      
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;  
      }
      
    void case_23(void){ // was 44
      	  uint8_t bitl;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      // as mode 10 
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 1st option of above... - *more maybe on LF side these ones*
      // - TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0040)){
	lcount++;
	if (lcount>7) lcount=0;
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
	if((clvalue>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000;
      }
	}

    void case_24(void){ // was 45
      	  uint8_t bitl;
	    uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 3rd option of above...
      	// - TESTED/WORKING!
      lcount++;
      if (lcount>7) lcount=0;
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
	if((clvalue>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (!(GPIOB->IDR & 0x0040)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000;
      }
	}

    void case_25(void){ // was 47
      	  uint8_t bitl;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      // *we could use CV to set length of pulse (say up to 128 which is 7 bits >> 9)*
      //->>>>>>>>>>>>>> as mode 14=speed divider with XOR rungler: XOR out with input bit
      	// - TESTED/WORKING! - not so exciting ....
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
      shift_registerl = (shift_registerl<<1) + ((bitl) ^ (!(GPIOB->IDR & 0x0040)));
      
	if (bitl) {
	  GPIOB->BRR = 0b0010000000000000; 
	  delay(clvalue>>9); // 64=10uS - short = lower voltage...
	  GPIOB->BSRR = 0b0010000000000000;  
	}
	  
	if (shift_registerl & lengthbitl) {
	  GPIOB->BRR = 0b0100000000000000;  
	  delay(clvalue>>9); // 64=10uS
	  GPIOB->BSRR = 0b0100000000000000;  
	  }
      }

    void case_26(void){ // was 51
      	  uint8_t bitl;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -
      probl=clvalue>>13; // 3 bits now for electroprob array
      probl=electroprob[probl];

      if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerh>>SRlengthh) & 0x01); 
      else shift_registerl = (shift_registerl<<1) + bitl;

      if (!(GPIOB->IDR & 0x0040)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000; 
      }
      }

    void case_27(void){ // was 52
      	  uint8_t bitl;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0040)){
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -
      probl=clvalue>>13; // 3 bits now for electroprob array
      probl=electroprob[probl];

      if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerh>>SRlengthh) & 0x01); 
      else shift_registerl = (shift_registerl<<1) + bitl;
      }
      
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
      }

    void case_28(void){ // was 53
      	  uint8_t bitl;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      // - after void case_25 - SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits
      // change and Re_test this - TESTED/working
      // loop bitl back in XOR at certain point?
	bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
	shift_registerl = (shift_registerl<<1);
	// do the loop back in
	lcount=clvalue>>11; // 5 bits - or(void){ lcount=(clvalue>>11)%(SRlengthl+1);
	if (bitl) shift_registerl ^= (1<<lcount);// set the xth bit
	shift_registerl ^= (!(GPIOB->IDR & 0x0040));
	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	}
	
    void case_29(void){ // was 56
      	  uint8_t bitl;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      // Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
      // can use CV as length of either SR = here is regularSR
      //       - TESTED/working
      SRlengthl=(clvalue>>11);
      if (SRlengthl<4) SRlengthl=4;
      lengthbitl=(1<<(SRlengthl/2));
	
	if (shift_registerxl==0) shift_registerxl=0xff; // catch it!
	//	bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	bitl= ((shift_registerxl >> 31) ^ (shift_registerxl >> 29) ^ (shift_registerxl >> 25) ^ (shift_registerxl >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerxl = (shift_registerxl<<1) + bitl; // could or with incoming as we don't use this TESTY: shift_registerxl = (shift_registerx<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl){ // calculate and output new bitl with void case_3 Turing Machine(void){
	  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);

	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}
	}

    void case_30(void){ // was 57
      uint8_t bitl, SRlengthx;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      // Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
      // can use CV as length of either SR = here is SRx
      //       - TESTED/working but not so satisfying for clvalue use

      SRlengthx=(clvalue>>11);
      if (SRlengthx<4) SRlengthx=4;
	
	if (shift_registerxl==0) shift_registerxl=0xff; // catch it!
	bitl= ((shift_registerxl >> (lfsr_taps_mirrored[SRlengthx][0])) ^ (shift_registerxl >> (lfsr_taps_mirrored[SRlengthx][1])) ^ (shift_registerxl >> (lfsr_taps_mirrored[SRlengthx][2])) ^ (shift_registerxl >> (lfsr_taps_mirrored[SRlengthx][3]))) & 1u; // 32 is 31, 29, 25, 24
	//	bitl= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerxl = (shift_registerxl<<1) + bitl; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl){ // calculate and output new bitl with void case_3 Turing Machine(void){
	  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);

	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}
	}

    void case_31(void){ // was 58 -  change the shifting amount - sort of works but not a great range and we need to take care of length
      uint8_t bitl, shifter;
	  uint32_t clvalue;
	  if (modelpwm==0) clvalue=65536-ADCBuffer[3];  
	  else clvalue=ADCBuffer[3];

      shifter=(clvalue>>11)%(SRlengthl+1);
      if (shifter==0) shifter=1;
      // TM here
      bitl = (shift_registerl>>(SRlengthl-(shifter-1))) & (shifter); // bits which would be shifted out  // 1 for length of 31
      if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<shifter) + bitl;
      else shift_registerl = (shift_registerl<<shifter) + (~bitl);

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;  
      }

    void case_16h(void){ // was 11 - leave in middle// MAYBE put this in middle of CV select mode for easy access TODO
    uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //->>>>>>>>>>>>>> CV selects length of SR which will stay with us .. -> LFSR here
      SRlengthh=31-(cvalue>>11);
      if (SRlengthh<4) SRlengthh=4;
      lengthbith=(1<<(SRlengthh/2));
      if (shift_registerh==0) shift_registerh=0xff;
      bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
      shift_registerh = (shift_registerh<<1) + ((bith | !(GPIOB->IDR & 0x0400))); // PB7 and PB10

      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000;  
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000; 
      else GPIOC->BSRR = 0b0100000000000000;  
      }

    void case_17h(void){ // was 10
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit 
      hcount++;
      if (hcount>7) hcount=0;
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out
      
      if((cvalue>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
      else shift_registerh = (shift_registerh<<1) + bith;

      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000; 
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000; 
      else GPIOC->BSRR = 0b0100000000000000; 
      }
      
    void case_18h(void){ // was 12 - works fine with cv in
    uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];

      //->>>>>>>>>>>>>> NEW mode TESTY: entry of ADC in from CV into upper bits?
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out

      if (counter12h == 9){       // every 8 cycles
	counter12h=0;
	shift_registerh &= MASK[SRlengthh]; // MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
	shift_registerh +=(cvalue>>8)<<(SHIFT[SRlengthh]); 
      }
      counter12h++;

      shift_registerh=(shift_registerh<<1) + (bith |  (!(GPIOB->IDR & 0x0400))); // cycle around and OR in pulse bit! TESTY!

      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000; 
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOC->BSRR = 0b0100000000000000; 
      }

    void case_19h(void){ // was 13
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // we do not use bit IN!
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
      probh=cvalue>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>SRlengthl) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;

      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000; 
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOC->BSRR = 0b0100000000000000; 
      }

    void case_20h(void){ // was 14 - could replace mode or one of these ???
      uint8_t bith, numflips, x;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //->>>>>>>>>>>>>> uses CV as speed/flipflop/clock divider
      // pulse in inverts the cycling bit in a la Turing Machine - cycle bit or invert bit = thus we do use input bit
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out
      //      origbith=bith;
      if (GPIOB->IDR & 0x0400) shift_registerh =  (shift_registerh<<1) + bith;
      else shift_registerh = (shift_registerh<<1) + (!bith);

      // flip flop: rising edge - if last was 0 and now is 1 then we trigger flip 1-0 or 0-1
      numflips=(cvalue>>12); //or 15-(cvalue>>12) if we wish it to go in the opposite direction
      new_state[0]=bith;
      if (prev_state[0]==0 && new_state[0]==1) flipped[0]^=1;
      prev_state[0]=new_state[0];	

      for (x=1;x<numflips;x++){ 
	new_state[x]=flipped[x-1];
	if (prev_state[x]==0 && new_state[x]==1) flipped[x]^=1;
	prev_state[x]=new_state[x];
      }
      if (numflips>0)	bith=flipped[numflips-1];

      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000;
      //      if (origbith) GPIOC->BRR = 0b0100000000000000;  // original bith 
      //      else GPIOC->BSRR = 0b0100000000000000;
      if (shift_registerh & lengthbith) {
	if (bith)	GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOC->BSRR = 0b0100000000000000;
      }
      }
	
    void case_21h(void){ // was 15
      uint8_t bith, numflips, x;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //->>>>>>>>>>>>>> as mode 14=speed divider with XOR rungler: XOR out with input bit
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out
      //      origbith=bith;
      shift_registerh = (shift_registerh<<1) + ((bith) ^ (!(GPIOB->IDR & 0x0400)));

      numflips=(cvalue>>12); //or 15-(cvalue>>12) if we wish it to go in the opposite direction
      new_state[0]=bith;
      if (prev_state[0]==0 && new_state[0]==1) flipped[0]^=1;
      prev_state[0]=new_state[0];	

      for (x=1;x<numflips;x++){ 
	new_state[x]=flipped[x-1];
	if (prev_state[x]==0 && new_state[x]==1) flipped[x]^=1;
	prev_state[x]=new_state[x];
      }
      if (numflips>0)	bith=flipped[numflips-1];
      
      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000;
      if (shift_registerh & lengthbith) {
	if (bith)	GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000;
      }
      //      if (origbith) GPIOC->BRR = 0b0100000000000000;  // original bith 
      //      else GPIOC->BSRR = 0b0100000000000000;
      }

    void case_22h(void){ // was 43
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      // as above but other way round with CV for length and incoming bits for probability of TM
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -

      SRlengthh=31-(cvalue>>11);
      if (SRlengthh<4) SRlengthh=4;
      lengthbith=(1<<(SRlengthh/2));

      if (hcount>7) hcount=0;
      if( !(GPIOB->IDR & 0x0400)) probh^=(1<<hcount);
      hcount++;
      
      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + bith;
      else shift_registerh = (shift_registerh<<1) + (!bith);
      
      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000;  
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000; 
      else GPIOC->BSRR = 0b0100000000000000;  
      }
      
    void case_23h(void){ // was 44
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      // as mode 10 
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 1st option of above... - *more maybe on LF side these ones*
      // - TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0400)){
	hcount++;
	if (hcount>7) hcount=0;
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out
	if((cvalue>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
	else shift_registerh = (shift_registerh<<1) + bith;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000; 
	else GPIOC->BSRR = 0b0100000000000000;
      }
	}

    void case_24h(void){ // was 45
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 3rd option of above...
      	// - TESTED/WORKING!
      hcount++;
      if (hcount>7) hcount=0;
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out
	if((cvalue>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
	else shift_registerh = (shift_registerh<<1) + bith;

	if (!(GPIOB->IDR & 0x0400)){
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000; 
	else GPIOC->BSRR = 0b0100000000000000;
      }
	}

    void case_25h(void){ // was 48
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //      	  extra mode in which pulse on is triggered by bitH but gated off by input bit or pulse
      // use mode 13 as example here:::
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      	// - TESTED/WORKING!
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
      probh=cvalue>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>SRlengthl) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;

      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else if (!(GPIOB->IDR & 0x0400)) GPIOC->BSRR = 0b0010000000000000; 
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else if (!(GPIOB->IDR & 0x0400)) GPIOC->BSRR = 0b0100000000000000; 
      }

    void case_26h(void){ // was 50
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0400)){
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
      probh=cvalue>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>SRlengthl) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;

      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000; 
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOC->BSRR = 0b0100000000000000; 
      }
      }

    void case_27h(void){ // was 52
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0400)){
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
      probh=cvalue>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>SRlengthl) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;
      }
      
      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000; 
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOC->BSRR = 0b0100000000000000; 
      }

    void case_28h(void){ // was 53
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      // - after void case_25 - SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits
      // change and Re_test this - TESTED/working
      // loop bith back in XOR at certain point?
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out
	shift_registerh = (shift_registerh<<1);
	// do the loop back in
	hcount=cvalue>>11; // 5 bits - orh(void){ hcount=(cvalue>>11)%(SRlengthh+1);
	if (bith) shift_registerh ^= (1<<hcount);// set the xth bit
	shift_registerh ^= (!(GPIOB->IDR & 0x0400));
	
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  
	else GPIOC->BSRR = 0b0100000000000000; 
	}
	
    void case_29h(void){ // was 56
        uint8_t bith;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      // Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
      // can use CV as length of either SR = here is regularSR
      //       - TESTED/working
      SRlengthh=(cvalue>>11);
      if (SRlengthh<4) SRlengthh=4;
      lengthbith=(1<<(SRlengthh/2));
	
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with void case_3 Turing Machineh(void){
	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	  if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOC->BSRR = 0b0010000000000000;  
	  if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOC->BSRR = 0b0100000000000000;
	}
	}

    void case_30h(void){ // was 57
      uint8_t bith, SRlengthx;
      uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      // Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
      // can use CV as length of either SR = here is SRx
      //       - TESTED/working but not so satisfying for cvalue use

      SRlengthx=(cvalue>>11);
      if (SRlengthx<4) SRlengthx=4;
	
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	bith= ((shift_registerx >> (lfsr_taps[SRlengthx][0])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][1])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][2])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][3]))) & 1u; // 32 is 31, 29, 25, 24
	//	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with void case_3 Turing Machineh(void){
	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	  if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOC->BSRR = 0b0010000000000000;  
	  if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOC->BSRR = 0b0100000000000000;
	}
	}

    void case_31h(void){ // was 58 -  change the shifting amount - sort of works but not a great range and we need to take care of length
      uint8_t bith, shifter;
    uint32_t cvalue;
    if (modehpwm==0) cvalue=65536-ADCBuffer[2];  // or modehpwm>1???TESTY!
    else cvalue=ADCBuffer[2];
      shifter=(cvalue>>11)%(SRlengthh+1);
      if (shifter==0) shifter=1;
      // TM here
      bith = (shift_registerh>>(SRlengthh-(shifter-1))) & (shifter); // bits which would be shifted out  // 1 for length of 31
      if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<shifter) + bith;
      else shift_registerh = (shift_registerh<<shifter) + (~bith);

      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000;  
      if (shift_registerh & lengthbith) GPIOC->BRR = 0b0100000000000000; 
      else GPIOC->BSRR = 0b0100000000000000;  
      }

void (*LF_TIM2_modes[16])(void)={case_0, case_1, case_2, case_3, case_4, case_5, case_6, case_7, case_8, case_9, case_10, case_11, case_12, case_13, case_14, case_15};
void (*HF_TIM2_modes[16])(void)={case_0h, case_1h, case_2h, case_3h, case_4h, case_5h, case_6h, case_7h, case_8h, case_9h, case_10h, case_11h, case_12h, case_13h, case_14h, case_15h};

void (*LF_INT_modes[16])(void)={case_16, case_17, case_18, case_19, case_20, case_21, case_22, case_23, case_24, case_25, case_26, case_27, case_28, case_29, case_30, case_31};
void (*HF_INT_modes[16])(void)={case_16h, case_17h, case_18h, case_19h, case_20h, case_21h, case_22h, case_23h, case_24h, case_25h, case_26h, case_27h, case_28h, case_29h, case_30h, case_31h};

void TIM2_IRQHandler(void){
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

  if (modelsr<16) {
    counterl++;
    if (counterl>speedll){
    counterl=0;
    LF_TIM2_modes[modelsr]();
    }
  }

  if (modehsr<16){
    counterh++;
    if (counterh>speedhh){
      counterh=0;
      HF_TIM2_modes[modehsr]();
    }
  }
}
    
void TIM4_IRQHandler(void){
  uint32_t speedh, speedl;
  // select modes, speeds and if necessary handle PWM depending on mode. Speed from main.c is 1KHz
  TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    
  model=ADCBuffer[1];
  modeh=ADCBuffer[0];

  // so we have 32 modes for hpwm and 2 modes for pwm - do we need smoothings ->
  // tested with blank and no smoothing is necessary  

  modehpwm=modeh>>15; // 1 bits remaining
  modehsr=31-(modeh>>10)%32; // 32 modes

  speedh=logger[ADCBuffer[2]>>6]; // 1024  = 10 bits -> could be less logger to make smoother?
  if (modehpwm==0) {     // invert the speedhh;
    speedhh=logforSR[1024-(ADCBuffer[2]>>6)]; // or recalculate from log? TESTY!
  }
  else  speedhh=logforSR[ADCBuffer[2]>>6]; // 1024 option = 10 bits log ->  could be less logger to make smoother? - could also be a lot slower at one end

  //  modelpwm=1; // TESTY! 
  modelpwm=model>>15; // 1 bits remaining
  modelsr=31-(model>>10)%32; // 32 modes

  speedl=logger[ADCBuffer[3]>>6]; // 1024  = 10 bits -> could be less logger to make smoother?
  if (modelpwm==0) {     // invert the speedhh;
    speedll=logforSR[1024-(ADCBuffer[3]>>6)]; // or recalculate from log? TESTY!
  }
  else  speedll=logforSR[ADCBuffer[3]>>6]; // 1024 option = 10 bits log ->  could be less logger to make smoother? - could also be a lot slower at one end
  
  TIM1->ARR = speedh;//period
  TIM1->CCR1 = speedh/2; // pulse  
  TIM3->ARR = speedl;//period
  TIM3->CCR1 = speedl/2; // pulse  

}

void EXTI9_5_IRQHandler(void){
  // LF and HF pulse in on falling edges

  uint32_t pending = EXTI->PR;

  // --------------------LF pulse modes
  if(pending & (1 << 5)) { // LF on 5 out on B
    EXTI->PR = 1 << 5; // clear pending flag, otherwise we'd get endless interrupts -!!!!!!!!!!!!!!!!!!!!!!!!!        // handle pin 5 here

    if (modelsr>15){
            LF_INT_modes[modelsr]();
    }
  }

  // --------------------HF Pulse modes 
  if(pending & (1 << 7)) { // HF on 7/out on C
    EXTI->PR = 1 << 7;        // handle pin 7 here

    if (modehsr>15){
      HF_INT_modes[modehsr]();
    }
  }
}
