#include "stm32f10x_it.h"
#include <stdlib.h>

/* 

These are the SR/PWM modes in interrupts...

List of Shift Register modes = CV and pulse driven:

List of PWM modes now:


- TODO: DAC modes:

 interpol 32-47 *CV)
 spacings 48-63 (pulse)


*/

#define SMOOTHINGS 512 // 128? we can hold 65536 of our 16 bit ADC values...

extern __IO uint16_t ADCBuffer[];
volatile uint32_t speedh, speedl, counterh=0, counter12h=0, counter12l=0,speedhh, speedll, counterl=0;
volatile uint32_t modelsr=0, modehsr=0, hcount=0, lcount=0; 
volatile uint8_t new_state[32], prev_state[32]={0}, flipped[32]={0}, new_statel[32], prev_statel[32]={0}, flippedl[32]={0}, probh, probl, togglel;
volatile uint8_t new_stath, prev_stath=0, flipdh=0, new_statl, prev_statl=0, flipdl=0, goinguph=1, goingupl=1;
volatile uint32_t shift_registerh=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t shift_registerl=0xff; 
volatile uint32_t shift_registerx=0xff;
volatile uint32_t shift_registerxl=0xff;
volatile uint32_t hstack[4], lstack[4]; // length minus 1;
volatile uint32_t model, modeh; 
volatile uint32_t bith=0, bitl=0;
volatile uint32_t lastspeedhh, lastspeedll, lastmodeh, lastmodel;
volatile uint32_t targeth=8000<16, interh=1<<16, whereh=312<<16; // for interpol
volatile uint32_t targetl=8000<16, interl=1<<16, wherel=312<<16; // for interpol

// for new smoothings
uint32_t ll=0, totl=0, smoothl[SMOOTHINGS];
uint32_t hh=0, toth=0, smoothh[SMOOTHINGS];


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

static uint32_t bits[8]={1, 2, 4, 8, 16, 32, 64, 128};

static uint32_t MASK[32]={4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294966785, 4294966275, 4294965255, 4294963215, 4294959135, 4294950975, 4294934655, 4294902015, 4294836735, 4294706175, 4294445055, 4293922815, 4292878335, 4290789375, 4286611455, 4278255615, 4261543935, 4228120575, 4161273855, 4027580415, 3760193535, 3225419775, 2155872255, 16777215};

static uint32_t SHIFT[32]={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; 

// log_gen:     print("%s," % int(1+(((starter*xyz)-312)/32))),

static uint16_t logger[1024]={312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 326, 327, 328, 329, 330, 331, 332, 333, 334, 336, 337, 338, 339, 340, 341, 343, 344, 345, 346, 347, 348, 350, 351, 352, 353, 354, 356, 357, 358, 359, 360, 362, 363, 364, 365, 367, 368, 369, 370, 372, 373, 374, 375, 377, 378, 379, 380, 382, 383, 384, 386, 387, 388, 390, 391, 392, 394, 395, 396, 398, 399, 400, 402, 403, 404, 406, 407, 409, 410, 411, 413, 414, 416, 417, 418, 420, 421, 423, 424, 425, 427, 428, 430, 431, 433, 434, 436, 437, 439, 440, 442, 443, 445, 446, 448, 449, 451, 452, 454, 455, 457, 458, 460, 462, 463, 465, 466, 468, 469, 471, 473, 474, 476, 477, 479, 481, 482, 484, 486, 487, 489, 491, 492, 494, 496, 497, 499, 501, 502, 504, 506, 507, 509, 511, 513, 514, 516, 518, 520, 521, 523, 525, 527, 528, 530, 532, 534, 536, 538, 539, 541, 543, 545, 547, 549, 550, 552, 554, 556, 558, 560, 562, 564, 566, 567, 569, 571, 573, 575, 577, 579, 581, 583, 585, 587, 589, 591, 593, 595, 597, 599, 601, 603, 605, 607, 609, 611, 613, 616, 618, 620, 622, 624, 626, 628, 630, 632, 635, 637, 639, 641, 643, 645, 648, 650, 652, 654, 656, 659, 661, 663, 665, 668, 670, 672, 674, 677, 679, 681, 684, 686, 688, 691, 693, 695, 698, 700, 702, 705, 707, 710, 712, 714, 717, 719, 722, 724, 727, 729, 732, 734, 737, 739, 742, 744, 747, 749, 752, 754, 757, 759, 762, 765, 767, 770, 772, 775, 778, 780, 783, 786, 788, 791, 794, 796, 799, 802, 804, 807, 810, 813, 815, 818, 821, 824, 826, 829, 832, 835, 838, 841, 843, 846, 849, 852, 855, 858, 861, 864, 867, 870, 872, 875, 878, 881, 884, 887, 890, 893, 896, 899, 903, 906, 909, 912, 915, 918, 921, 924, 927, 930, 934, 937, 940, 943, 946, 950, 953, 956, 959, 962, 966, 969, 972, 976, 979, 982, 986, 989, 992, 996, 999, 1002, 1006, 1009, 1013, 1016, 1020, 1023, 1026, 1030, 1033, 1037, 1040, 1044, 1048, 1051, 1055, 1058, 1062, 1065, 1069, 1073, 1076, 1080, 1084, 1087, 1091, 1095, 1098, 1102, 1106, 1110, 1113, 1117, 1121, 1125, 1129, 1132, 1136, 1140, 1144, 1148, 1152, 1156, 1160, 1163, 1167, 1171, 1175, 1179, 1183, 1187, 1191, 1195, 1199, 1204, 1208, 1212, 1216, 1220, 1224, 1228, 1232, 1237, 1241, 1245, 1249, 1253, 1258, 1262, 1266, 1271, 1275, 1279, 1283, 1288, 1292, 1297, 1301, 1305, 1310, 1314, 1319, 1323, 1328, 1332, 1337, 1341, 1346, 1350, 1355, 1360, 1364, 1369, 1373, 1378, 1383, 1387, 1392, 1397, 1402, 1406, 1411, 1416, 1421, 1426, 1430, 1435, 1440, 1445, 1450, 1455, 1460, 1465, 1470, 1475, 1480, 1485, 1490, 1495, 1500, 1505, 1510, 1515, 1520, 1525, 1531, 1536, 1541, 1546, 1551, 1557, 1562, 1567, 1573, 1578, 1583, 1589, 1594, 1599, 1605, 1610, 1616, 1621, 1627, 1632, 1638, 1643, 1649, 1655, 1660, 1666, 1671, 1677, 1683, 1688, 1694, 1700, 1706, 1711, 1717, 1723, 1729, 1735, 1741, 1747, 1753, 1758, 1764, 1770, 1776, 1782, 1788, 1795, 1801, 1807, 1813, 1819, 1825, 1831, 1838, 1844, 1850, 1856, 1863, 1869, 1875, 1882, 1888, 1894, 1901, 1907, 1914, 1920, 1927, 1933, 1940, 1946, 1953, 1960, 1966, 1973, 1980, 1986, 1993, 2000, 2007, 2013, 2020, 2027, 2034, 2041, 2048, 2055, 2062, 2069, 2076, 2083, 2090, 2097, 2104, 2111, 2118, 2126, 2133, 2140, 2147, 2155, 2162, 2169, 2177, 2184, 2191, 2199, 2206, 2214, 2221, 2229, 2236, 2244, 2251, 2259, 2267, 2274, 2282, 2290, 2298, 2305, 2313, 2321, 2329, 2337, 2345, 2353, 2361, 2369, 2377, 2385, 2393, 2401, 2409, 2417, 2426, 2434, 2442, 2450, 2459, 2467, 2475, 2484, 2492, 2501, 2509, 2518, 2526, 2535, 2543, 2552, 2561, 2569, 2578, 2587, 2595, 2604, 2613, 2622, 2631, 2640, 2649, 2658, 2667, 2676, 2685, 2694, 2703, 2712, 2721, 2731, 2740, 2749, 2759, 2768, 2777, 2787, 2796, 2806, 2815, 2825, 2834, 2844, 2853, 2863, 2873, 2883, 2892, 2902, 2912, 2922, 2932, 2942, 2952, 2962, 2972, 2982, 2992, 3002, 3012, 3023, 3033, 3043, 3053, 3064, 3074, 3085, 3095, 3105, 3116, 3127, 3137, 3148, 3158, 3169, 3180, 3191, 3202, 3212, 3223, 3234, 3245, 3256, 3267, 3278, 3289, 3301, 3312, 3323, 3334, 3346, 3357, 3368, 3380, 3391, 3403, 3414, 3426, 3437, 3449, 3461, 3472, 3484, 3496, 3508, 3520, 3532, 3544, 3556, 3568, 3580, 3592, 3604, 3616, 3629, 3641, 3653, 3666, 3678, 3691, 3703, 3716, 3728, 3741, 3754, 3766, 3779, 3792, 3805, 3818, 3831, 3844, 3857, 3870, 3883, 3896, 3909, 3923, 3936, 3949, 3963, 3976, 3989, 4003, 4017, 4030, 4044, 4058, 4071, 4085, 4099, 4113, 4127, 4141, 4155, 4169, 4183, 4197, 4211, 4226, 4240, 4254, 4269, 4283, 4298, 4312, 4327, 4342, 4356, 4371, 4386, 4401, 4416, 4431, 4446, 4461, 4476, 4491, 4506, 4522, 4537, 4552, 4568, 4583, 4599, 4615, 4630, 4646, 4662, 4677, 4693, 4709, 4725, 4741, 4757, 4773, 4790, 4806, 4822, 4838, 4855, 4871, 4888, 4904, 4921, 4938, 4954, 4971, 4988, 5005, 5022, 5039, 5056, 5073, 5090, 5108, 5125, 5142, 5160, 5177, 5195, 5213, 5230, 5248, 5266, 5284, 5301, 5319, 5337, 5356, 5374, 5392, 5410, 5429, 5447, 5465, 5484, 5503, 5521, 5540, 5559, 5578, 5597, 5615, 5635, 5654, 5673, 5692, 5711, 5731, 5750, 5770, 5789, 5809, 5829, 5848, 5868, 5888, 5908, 5928, 5948, 5968, 5988, 6009, 6029, 6050, 6070, 6091, 6111, 6132, 6153, 6174, 6195, 6216, 6237, 6258, 6279, 6300, 6322, 6343, 6365, 6386, 6408, 6430, 6451, 6473, 6495, 6517, 6539, 6562, 6584, 6606, 6629, 6651, 6674, 6696, 6719, 6742, 6765, 6787, 6810, 6834, 6857, 6880, 6903, 6927, 6950, 6974, 6997, 7021, 7045, 7069, 7093, 7117, 7141, 7165, 7189, 7214, 7238, 7263, 7287, 7312, 7337, 7362, 7387, 7412, 7437, 7462, 7487, 7513, 7538, 7564, 7590, 7615, 7641, 7667, 7693, 7719, 7745, 7772, 7798, 7824, 7851, 7877, 7904, 7931, 7958, 7985, 8012, 8039, 8066, 8094, 8121, 8149, 8176, 8204, 8232, 8260, 8288, 8316, 8344, 8372, 8401, 8429, 8458, 8486, 8515, 8544, 8573, 8602, 8631, 8661, 8690, 8719, 8749, 8779, 8808, 8838, 8868, 8898, 8928, 8959, 8989, 9020, 9050, 9081, 9112, 9142, 9173, 9205, 9236, 9267, 9299, 9330, 9362, 9393, 9425, 9457, 9489, 9521, 9554, 9586, 9619, 9651, 9684, 9717, 9750, 9783, 9816, 9849, 9883, 9916, 9950};


static uint16_t lf_logger[1024]={500, 501, 503, 505, 506, 508, 510, 511, 513, 515, 517, 518, 520, 522, 524, 526, 527, 529, 531, 533, 535, 536, 538, 540, 542, 544, 546, 547, 549, 551, 553, 555, 557, 559, 561, 562, 564, 566, 568, 570, 572, 574, 576, 578, 580, 582, 584, 586, 588, 590, 592, 594, 596, 598, 600, 602, 604, 606, 608, 610, 612, 614, 616, 618, 621, 623, 625, 627, 629, 631, 633, 635, 638, 640, 642, 644, 646, 649, 651, 653, 655, 657, 660, 662, 664, 666, 669, 671, 673, 675, 678, 680, 682, 685, 687, 689, 692, 694, 696, 699, 701, 703, 706, 708, 711, 713, 716, 718, 720, 723, 725, 728, 730, 733, 735, 738, 740, 743, 745, 748, 750, 753, 755, 758, 761, 763, 766, 768, 771, 774, 776, 779, 781, 784, 787, 789, 792, 795, 798, 800, 803, 806, 808, 811, 814, 817, 819, 822, 825, 828, 831, 833, 836, 839, 842, 845, 848, 851, 853, 856, 859, 862, 865, 868, 871, 874, 877, 880, 883, 886, 889, 892, 895, 898, 901, 904, 907, 910, 913, 916, 920, 923, 926, 929, 932, 935, 938, 942, 945, 948, 951, 954, 958, 961, 964, 968, 971, 974, 977, 981, 984, 987, 991, 994, 997, 1001, 1004, 1008, 1011, 1015, 1018, 1021, 1025, 1028, 1032, 1035, 1039, 1042, 1046, 1049, 1053, 1057, 1060, 1064, 1067, 1071, 1075, 1078, 1082, 1086, 1089, 1093, 1097, 1100, 1104, 1108, 1112, 1116, 1119, 1123, 1127, 1131, 1135, 1138, 1142, 1146, 1150, 1154, 1158, 1162, 1166, 1170, 1174, 1178, 1182, 1186, 1190, 1194, 1198, 1202, 1206, 1210, 1214, 1218, 1222, 1227, 1231, 1235, 1239, 1243, 1248, 1252, 1256, 1260, 1265, 1269, 1273, 1277, 1282, 1286, 1291, 1295, 1299, 1304, 1308, 1313, 1317, 1322, 1326, 1331, 1335, 1340, 1344, 1349, 1353, 1358, 1362, 1367, 1372, 1376, 1381, 1386, 1390, 1395, 1400, 1405, 1409, 1414, 1419, 1424, 1429, 1433, 1438, 1443, 1448, 1453, 1458, 1463, 1468, 1473, 1478, 1483, 1488, 1493, 1498, 1503, 1508, 1513, 1519, 1524, 1529, 1534, 1539, 1544, 1550, 1555, 1560, 1566, 1571, 1576, 1582, 1587, 1592, 1598, 1603, 1609, 1614, 1619, 1625, 1631, 1636, 1642, 1647, 1653, 1658, 1664, 1670, 1675, 1681, 1687, 1692, 1698, 1704, 1710, 1716, 1721, 1727, 1733, 1739, 1745, 1751, 1757, 1763, 1769, 1775, 1781, 1787, 1793, 1799, 1805, 1811, 1817, 1823, 1830, 1836, 1842, 1848, 1855, 1861, 1867, 1874, 1880, 1886, 1893, 1899, 1906, 1912, 1919, 1925, 1932, 1938, 1945, 1951, 1958, 1965, 1971, 1978, 1985, 1991, 1998, 2005, 2012, 2019, 2025, 2032, 2039, 2046, 2053, 2060, 2067, 2074, 2081, 2088, 2095, 2102, 2109, 2117, 2124, 2131, 2138, 2146, 2153, 2160, 2167, 2175, 2182, 2190, 2197, 2204, 2212, 2219, 2227, 2235, 2242, 2250, 2257, 2265, 2273, 2280, 2288, 2296, 2304, 2312, 2319, 2327, 2335, 2343, 2351, 2359, 2367, 2375, 2383, 2391, 2399, 2408, 2416, 2424, 2432, 2440, 2449, 2457, 2465, 2474, 2482, 2490, 2499, 2507, 2516, 2524, 2533, 2542, 2550, 2559, 2568, 2576, 2585, 2594, 2603, 2611, 2620, 2629, 2638, 2647, 2656, 2665, 2674, 2683, 2692, 2701, 2711, 2720, 2729, 2738, 2748, 2757, 2766, 2776, 2785, 2795, 2804, 2814, 2823, 2833, 2842, 2852, 2862, 2871, 2881, 2891, 2901, 2911, 2920, 2930, 2940, 2950, 2960, 2970, 2980, 2991, 3001, 3011, 3021, 3031, 3042, 3052, 3062, 3073, 3083, 3094, 3104, 3115, 3125, 3136, 3146, 3157, 3168, 3179, 3189, 3200, 3211, 3222, 3233, 3244, 3255, 3266, 3277, 3288, 3299, 3311, 3322, 3333, 3344, 3356, 3367, 3379, 3390, 3401, 3413, 3425, 3436, 3448, 3460, 3471, 3483, 3495, 3507, 3519, 3531, 3543, 3555, 3567, 3579, 3591, 3603, 3615, 3628, 3640, 3652, 3665, 3677, 3690, 3702, 3715, 3727, 3740, 3753, 3765, 3778, 3791, 3804, 3817, 3830, 3843, 3856, 3869, 3882, 3895, 3908, 3922, 3935, 3948, 3962, 3975, 3989, 4002, 4016, 4029, 4043, 4057, 4071, 4084, 4098, 4112, 4126, 4140, 4154, 4168, 4182, 4197, 4211, 4225, 4240, 4254, 4268, 4283, 4297, 4312, 4327, 4341, 4356, 4371, 4386, 4400, 4415, 4430, 4445, 4461, 4476, 4491, 4506, 4521, 4537, 4552, 4568, 4583, 4599, 4614, 4630, 4646, 4661, 4677, 4693, 4709, 4725, 4741, 4757, 4773, 4789, 4806, 4822, 4838, 4855, 4871, 4888, 4904, 4921, 4938, 4955, 4971, 4988, 5005, 5022, 5039, 5056, 5073, 5091, 5108, 5125, 5143, 5160, 5178, 5195, 5213, 5231, 5248, 5266, 5284, 5302, 5320, 5338, 5356, 5374, 5392, 5411, 5429, 5448, 5466, 5485, 5503, 5522, 5541, 5559, 5578, 5597, 5616, 5635, 5654, 5674, 5693, 5712, 5732, 5751, 5771, 5790, 5810, 5830, 5849, 5869, 5889, 5909, 5929, 5949, 5969, 5990, 6010, 6030, 6051, 6071, 6092, 6113, 6133, 6154, 6175, 6196, 6217, 6238, 6259, 6281, 6302, 6323, 6345, 6366, 6388, 6410, 6431, 6453, 6475, 6497, 6519, 6541, 6563, 6586, 6608, 6631, 6653, 6676, 6698, 6721, 6744, 6767, 6790, 6813, 6836, 6859, 6882, 6906, 6929, 6953, 6976, 7000, 7024, 7047, 7071, 7095, 7119, 7144, 7168, 7192, 7217, 7241, 7266, 7290, 7315, 7340, 7365, 7390, 7415, 7440, 7465, 7491, 7516, 7542, 7567, 7593, 7619, 7644, 7670, 7696, 7723, 7749, 7775, 7801, 7828, 7854, 7881, 7908, 7935, 7962, 7989, 8016, 8043, 8070, 8098, 8125, 8153, 8180, 8208, 8236, 8264, 8292, 8320, 8348, 8377, 8405, 8434, 8462, 8491, 8520, 8549, 8578, 8607, 8636, 8665, 8695, 8724, 8754, 8784, 8813, 8843, 8873, 8903, 8934, 8964, 8994, 9025, 9056, 9086, 9117, 9148, 9179, 9210, 9242, 9273, 9304, 9336, 9368, 9399, 9431, 9463, 9495, 9528, 9560, 9592, 9625, 9658, 9690, 9723, 9756, 9789, 9823, 9856, 9889, 9923, 9957, 9990, 10024, 10058, 10093, 10127, 10161, 10196, 10230, 10265, 10300, 10335, 10370, 10405, 10440, 10476, 10511, 10547, 10583, 10619, 10655, 10691, 10727, 10764, 10800, 10837, 10874, 10910, 10947, 10985, 11022, 11059, 11097, 11134, 11172, 11210, 11248, 11286, 11325, 11363, 11402, 11440, 11479, 11518, 11557, 11596, 11636, 11675, 11715, 11755, 11795, 11835, 11875, 11915, 11956, 11996, 12037, 12078, 12119, 12160, 12201, 12242, 12284, 12326, 12368, 12409, 12452, 12494, 12536, 12579, 12622, 12664, 12707, 12750, 12794, 12837, 12881, 12924, 12968, 13012, 13056, 13101, 13145, 13190, 13235, 13279, 13325, 13370, 13415, 13461, 13506, 13552, 13598, 13644, 13691, 13737, 13784, 13831, 13877, 13925, 13972, 14019, 14067, 14115, 14162, 14210, 14259, 14307, 14356, 14404, 14453, 14502, 14552, 14601, 14650, 14700, 14750, 14800, 14850, 14901, 14951, 15002, 15053, 15104, 15155, 15207, 15258, 15310, 15362, 15414, 15467, 15519, 15572, 15625, 15678, 15731, 15784, 15838, 15891, 15945, 16000};

// logforSR could be a lot slower at one end - test/generate this! 2^14

static uint32_t slower_even_logforSR[1024]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 23, 23, 23, 23, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 27, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 31, 31, 31, 32, 32, 32, 33, 33, 34, 34, 34, 35, 35, 36, 36, 37, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 48, 48, 49, 49, 50, 50, 51, 52, 52, 53, 54, 54, 55, 55, 56, 57, 58, 58, 59, 60, 60, 61, 62, 62, 63, 64, 65, 65, 66, 67, 68, 69, 69, 70, 71, 72, 73, 74, 75, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 98, 99, 100, 101, 102, 103, 105, 106, 107, 108, 110, 111, 112, 114, 115, 116, 118, 119, 120, 122, 123, 125, 126, 128, 129, 131, 132, 134, 135, 137, 138, 140, 142, 143, 145, 147, 148, 150, 152, 154, 156, 157, 159, 161, 163, 165, 167, 169, 171, 173, 175, 177, 179, 181, 183, 185, 187, 190, 192, 194, 196, 199, 201, 203, 206, 208, 210, 213, 215, 218, 220, 223, 226, 228, 231, 234, 236, 239, 242, 245, 247, 250, 253, 256, 259, 262, 265, 268, 272, 275, 278, 281, 284, 288, 291, 294, 298, 301, 305, 308, 312, 316, 319, 323, 327, 331, 334, 338, 342, 346, 350, 354, 358, 363, 367, 371, 375, 380, 384, 389, 393, 398, 402, 407, 412, 417, 421, 426, 431, 436, 441, 447, 452, 457, 462, 468, 473, 479, 484, 490, 495, 501, 507, 513, 519, 525, 531, 537, 543, 550, 556, 563, 569, 576, 582, 589, 596, 603, 610, 617, 624, 631, 639, 646, 654, 661, 669, 677, 685, 693, 701, 709, 717, 725, 734, 742, 751, 760, 768, 777, 786, 795, 805, 814, 823, 833, 843, 852, 862, 872, 882, 893, 903, 914, 924, 935, 946, 957, 968, 979, 990, 1002, 1014, 1025, 1037, 1049, 1061, 1074, 1086, 1099, 1111, 1124, 1137, 1151, 1164, 1177, 1191, 1205, 1219, 1233, 1247, 1262, 1276, 1291, 1306, 1321, 1337, 1352, 1368, 1384, 1400, 1416, 1432, 1449, 1466, 1483, 1500, 1518, 1535, 1553, 1571, 1589, 1608, 1626, 1645, 1664, 1683, 1703, 1723, 1743, 1763, 1783, 1804, 1825, 1846, 1867, 1889, 1911, 1933, 1956, 1978, 2001, 2024, 2048, 2072, 2096, 2120, 2145, 2169, 2195, 2220, 2246, 2272, 2298, 2325, 2352, 2379, 2407, 2434, 2463, 2491, 2520, 2549, 2579, 2609, 2639, 2670, 2700, 2732, 2763, 2795, 2828, 2861, 2894, 2927, 2961, 2996, 3030, 3065, 3101, 3137, 3173, 3210, 3247, 3285, 3323, 3362, 3400, 3440, 3480, 3520, 3561, 3602, 3644, 3686, 3729, 3772, 3816, 3860, 3905, 3950, 3996, 4042, 4089, 4136, 4184, 4233, 4282, 4331, 4382, 4432, 4484, 4536, 4588, 4641, 4695, 4750, 4805, 4860, 4917, 4974, 5031, 5090, 5149, 5208, 5269, 5330, 5391, 5454, 5517, 5581, 5646, 5711, 5777, 5844, 5912, 5981, 6050, 6120, 6191, 6263, 6335, 6409, 6483, 6558, 6634, 6711, 6789, 6867, 6947, 7027, 7109, 7191, 7275, 7359, 7444, 7530, 7618, 7706, 7795, 7885, 7977, 8069, 8163, 8257, 8353, 8450, 8548, 8647, 8747, 8848, 8951, 9055, 9160, 9266, 9373, 9482, 9591, 9703, 9815, 9929, 10044, 10160, 10278, 10397, 10517, 10639, 10763, 10887, 11013, 11141, 11270, 11401, 11533, 11666, 11802, 11938, 12077, 12217, 12358, 12501, 12646, 12793, 12941, 13091, 13243, 13396, 13551, 13708, 13867, 14028, 14190, 14355, 14521, 14689, 14859, 15032, 15206, 15382, 15560, 15740, 15923, 16107, 16294, 16483, 16674, 16867, 17062, 17260, 17460, 17662, 17867, 18074, 18283, 18495, 18709, 18926, 19145, 19367, 19592, 19819, 20048, 20281, 20516, 20753, 20994, 21237, 21483, 21732, 21984, 22238, 22496, 22757, 23020, 23287, 23557, 23830, 24106, 24385, 24668, 24953, 25243, 25535, 25831, 26130, 26433, 26739, 27049, 27362, 27679, 28000, 28324, 28653, 28985, 29320, 29660, 30004, 30351, 30703, 31059, 31418, 31782, 32151, 32523, 32900, 33281, 33667, 34057, 34451, 34851, 35254, 35663, 36076, 36494, 36917, 37344, 37777, 38215, 38657, 39105, 39558, 40017, 40480, 40949, 41424, 41904, 42389, 42880, 43377, 43880, 44388, 44902, 45422, 45949, 46481, 47019, 47564, 48115, 48673, 49237, 49807, 50384, 50968, 51558, 52156, 52760, 53371, 53989, 54615, 55248, 55888, 56535, 57190, 57853, 58523, 59201, 59887, 60581, 61283, 61993, 62711, 63437, 64172, 64916, 65668, 66429, 67198, 67977, 68764, 69561, 70367, 71182, 72007, 72841, 73685, 74539, 75402, 76276, 77159, 78053, 78958, 79872, 80798, 81734, 82681, 83639, 84608, 85588, 86579, 87582, 88597, 89623, 90662, 91712, 92775, 93849, 94937, 96037, 97149, 98275, 99413, 100565, 101730, 102909, 104101, 105307, 106527, 107761, 109010, 110272, 111550, 112842, 114150, 115472, 116810, 118163, 119532, 120917, 122318, 123735, 125168, 126619, 128085, 129569, 131071};


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

void TIM2_IRQHandler(void){

  uint32_t tmp;
  uint32_t spl=312;// sph=312;
  static uint32_t SRlengthx=31, SRlengthl=31, lengthbitl=(1<<15), SRlengthh=31, lengthbith=(1<<15);
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

  // INTERPOLATE for high side modes 32->47
  if (modehsr>31 && modehsr<48){
  if (goinguph==1){ // 
    // increase whereh
    whereh+=interh;
    tmp=(whereh>>16);
    if (tmp>=(targeth>>16)) goinguph=2;
    TIM1->ARR =tmp;
    TIM1->CCR1 =tmp/2; // pulse width
  }

  if (goinguph==0){
    // decrease whereh
    whereh-=interh;
    tmp=(whereh>>16);
    if (tmp<=(targeth>>16)) goinguph=2;
    TIM1->ARR =tmp;
    TIM1->CCR1 =tmp/2; // pulse width
  }
  }

  // test NEW interpol on low side
  /*
  // interh=1<<16;
  //  whereh=312<<16;
  if (goingupl==1){ // 
    // increase wherel
    wherel+=interl;
    tmp=(wherel>>16);
    if (tmp>=(targetl>>16)) goingupl=2;
    TIM3->ARR =tmp;
    TIM3->CCR1 =tmp/2; // pulse width
  }

  if (goingupl==0){
    // decrease wherel
    wherel-=interl;
    tmp=(wherel>>16);
    if (tmp<=(targetl>>16)) goingupl=2;
    TIM3->ARR =tmp;
    TIM3->CCR1 =tmp/2; // pulse width
  }
  */
  
  
  ////////////////////////////////////////////->>>    /// low side
  //*CV_LF: 0, 1, 2, 3, 4, 7, 9, 23, 30, 32, 33, 34, 35, 37, 39, 40*
 
  counterl++;
  if (counterl>speedll){
    counterl=0;
  
    switch(modelsr){ // use mirrored taps also!
    case 0:
      //->>>>>>>>>>>>>> 0- pulse (PB5) toggles loopback to OR with new input bit (PB6) /or just accept new input bit (CGS)
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      if (GPIOB->IDR & 0x0020) shift_registerl= (shift_registerl<<1) + (!(GPIOB->IDR & 0x0040)); // switched around for speed
      else shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); // PB5 and PB6
      	
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PB13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PB14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000;  
      break;
	
    case 1: 
	//->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out -
    
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + (!(GPIOB->IDR & 0x0040));
	else shift_registerl = (shift_registerl<<1) + ((bitl ^ !(GPIOB->IDR & 0x0040)));

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	break;
    
      case 2: 
	//->>>>>>>>>>>>>> 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR selected with counter and pulse
	lcount++;
	if (lcount>31) lcount=0;
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 

	shift_registerl= (shift_registerl<<1) + (bitl ^ !(GPIOB->IDR & 0x0040));

	//	if( !(GPIOB->IDR & 0x0020))	  shift_registerl &= (1<<lcount); // if we have pulse and lcount then flip that bit inside SR... rest all the same...
	if( !(GPIOB->IDR & 0x0020)) shift_registerxl ^= (1<<lcount); // if we have pulse and lcount then flip that bit inside SR... rest all the same...
	shift_registerl ^= shift_registerxl;

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 	
	break;
    
      case 3: //* 
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;
	break;

      case 4: 
	//->>>>>>>>>>>>>> 4- parity for loopback XOR is determined by pulsed bits in -> select bits with pulse and queue 
	lcount++;
	if (lcount>31) lcount=0;
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
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;
	break;

    case 5: // was 7
	//->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed Q of lengths?
	// no use of in bit
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out -
	if (lcount>7) lcount=0;
	if( !(GPIOB->IDR & 0x0020)) probl^=(1<<lcount);
	lcount++;
	if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerh>>31) & 0x01); // fixed for swop
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000;
	break;

    case 6: // was 9
	// 9- LFSR noise only with varying taps depending on length with new bit ORed in depending on pulse - for LF we can do mirroring!
	if (shift_registerl==0) shift_registerl=0xff; // catch it!
	bitl= ((shift_registerl >> (lfsr_taps_mirrored[31][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;  
	break;

    case 7: //was 23 -  experimental modes 23+ here and 32+ in pulses - TESTED/WORKING!
	// shifting the array of LFSR taps = ghost_tapsH on the high side
	// clock pulse shifts one selected by pulse 
	if (!(GPIOB->IDR & 0x0020)) lcount++;
	if (lcount>3) lcount=0;
	if (!(GPIOB->IDR & 0x0040)) {
	  ghost_tapsL[31][lcount+1]+=1;
	  ghost_tapsL[31][lcount+1]%=31;
	}
	
	if (shift_registerl==0) shift_registerl=0xff; // catch it!
	bitl= ((shift_registerl >> (ghost_tapsL[31][0])) ^ (shift_registerl >> (ghost_tapsL[31][1])) ^ (shift_registerl >> (ghost_tapsL[31][2])) ^ (shift_registerl >> (ghost_tapsL[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerl = (shift_registerl<<1) + bitl;
	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;  
	break;

    case 8: // was 30
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)-> our 3 options if we have a bit 0x0020
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (!(GPIOB->IDR & 0x0020)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;
	}
	break;

    case 9: // was 32
	// extra mode in which (both) pulse on is triggered by bitl but gated off by input bit or pulse - but do we need like a toggle?????
	//-BASE it on::: >>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	// - TESTED/WORKING!
	
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BSRR = 0b0100000000000000;
	break;

      case 10: // was 33 - and invert the above
	// extra mode in which (both) pulse on is triggered by bitl but gated off by input bit or pulse - but do we need like a toggle?????
	//-BASE it on::: >>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	// - TESTED/WORKING!
	
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BSRR = 0b0010000000000000;  // clear PC13 else write one
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BSRR = 0b0100000000000000;  
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BRR = 0b0100000000000000;
	break;
	
    case 11: // was 34
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
	break;
	
    case 12: // was 35
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

	if (bitl){ // calculate and output new bitl with case 3 Turing Machine:
	  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);

	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}
	break;

    case 13: // was 37
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// with input bit or'ed in
	if (shift_registerxl==0) shift_registerxl=0xff; // catch it!
	//	bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	bitl= ((shift_registerxl >> 31) ^ (shift_registerxl >> 29) ^ (shift_registerxl >> 25) ^ (shift_registerxl >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerxl = (shift_registerxl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl){ // calculate and output new bitl with case 3 Turing Machine:

	  bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);
	  
	
	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}
	break;

    case 14: // was 39
	// as above but LFSR?
	// working/.tested
      if (!(GPIOB->IDR & 0x0020)) togglel^=1; 

	if (togglel)
	  {
	    if (shift_registerl==0) shift_registerl=0xff; // catch it!
	    bitl= ((shift_registerl >> (lfsr_taps_mirrored[31][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	    shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040));  

	    if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	    else GPIOB->BSRR = 0b0010000000000000;  
	    if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	    else GPIOB->BSRR = 0b0100000000000000;
	  }
	break;

    case 15: // was 40
	// pulse in means a divide/flip flop
	// TESTED/WORKING but is only that divide on one bit..FIXED TESTED
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);
	
	new_statel[0]=bitl;
	if (prev_statel[0]==0 && new_statel[0]==1) flippedl[0]^=1;
	prev_statel[0]=new_statel[0];	

	if (shift_registerl & (1<<15)) new_statel[1]=1;
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
	break;

	////////////////////////
	/// DAC modes LF side
	////////////////////////
	
    case 32:
      //->>>>>>>>>>>>>> 0- pulse (PB5) toggles loopback to OR with new input bit (PB6) /or just accept new input bit (CGS)
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      if (GPIOB->IDR & 0x0020) shift_registerl= (shift_registerl<<1) + (!(GPIOB->IDR & 0x0040)); // switched around for speed
      else shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); // PB5 and PB6
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PB13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PB14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000;  

      spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;
	
    case 33: 
	//->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out -
    
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + (!(GPIOB->IDR & 0x0040));
	else shift_registerl = (shift_registerl<<1) + ((bitl ^ !(GPIOB->IDR & 0x0040)));

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;
    
    case 34: 
	//->>>>>>>>>>>>>> 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR selected with counter and pulse - fixed
	lcount++;
	if (lcount>31) lcount=0;
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 

	shift_registerl= (shift_registerl<<1) + (bitl ^ !(GPIOB->IDR & 0x0040));

	if( !(GPIOB->IDR & 0x0020)) shift_registerxl ^= (1<<lcount); // if we have pulse and lcount then flip that bit inside SR... rest all the same...
	shift_registerl ^= shift_registerxl;
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;
    
    case 35: //* 
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 36: 
	//->>>>>>>>>>>>>> 4- parity for loopback XOR is determined by pulsed bits in -> select bits with pulse and queue 
	lcount++;
	if (lcount>31) lcount=0;
	if( !(GPIOB->IDR & 0x0020)) {
	  lstack[3]=lstack[2];
	  lstack[2]=lstack[1];
	  lstack[1]=lstack[0];
	  lstack[0]=lcount+1; // bump it on to the lstack
	}	  

	bitl= ((shift_registerl >> lstack[0]) ^ (shift_registerl >> lstack[1]) ^ (shift_registerl >> lstack[2]) ^ (shift_registerl >> lstack[3])) & 1u; // 32 is 31, 29, 25, 24
	shift_registerl= (shift_registerl<<1) + (bitl ^ !(GPIOB->IDR & 0x0040)); // TESTY - to OR in new bit or not?

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 37: // was 7
	//->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed Q of lengths?
	// no use of in bit
	// !note: swop l and h when port to low!
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out -
	if (lcount>7) lcount=0;
	if( !(GPIOB->IDR & 0x0020)) probl^=(1<<lcount);
	lcount++;
	if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerh>>31) & 0x01); // fixed for swop
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000;

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 38: // was 9
	// 9- LFSR noise only with varying taps depending on length with new bit ORed in depending on pulse - for LF we can do mirroring!
	if (shift_registerl==0) shift_registerl=0xff; // catch it!
	bitl= ((shift_registerl >> (lfsr_taps_mirrored[31][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;  

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 39: //was 23 -  experimental modes 23+ here and 32+ in pulses - TESTED/WORKING!
	// shifting the array of LFSR taps = ghost_tapsH on the high side
	// clock pulse shifts one selected by pulse 
	if (!(GPIOB->IDR & 0x0020))
	  {
	    lcount++;
	    if (lcount>3) lcount=0;
	    //	if (!(GPIOB->IDR & 0x0040)) {
	    ghost_tapsL[31][lcount+1]+=1;
	    ghost_tapsL[31][lcount+1]%=31;
	  }
	
	if (shift_registerl==0) shift_registerl=0xff; // catch it!
	bitl= ((shift_registerl >> (ghost_tapsL[31][0])) ^ (shift_registerl >> (ghost_tapsL[31][1])) ^ (shift_registerl >> (ghost_tapsL[31][2])) ^ (shift_registerl >> (ghost_tapsL[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerl = (shift_registerl<<1) + bitl;

	if (!(GPIOB->IDR & 0x0040)) {
	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;  

	if (flippedl[0]==0) {
	    flippedl[0]=1;
	    prev_statel[0]=0;
	  }
	}
	else flippedl[0]=0;
	  
	if (flippedl[0]==1 && prev_statel[0]==0)
	  {
	  prev_statel[0]=1;
	  spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	  TIM3->ARR =spl;
	  TIM3->CCR1 = spl/2; // pulse width
	  }
	  break;

    case 40: // was 30
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)-> our 3 options if we have a bit 0x0020
	// - TESTED/WORKING!
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (!(GPIOB->IDR & 0x0020)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;
	}

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

	    case 41: // was 32
	// extra mode in which (both) pulse on is triggered by bitl but gated off by input bit or pulse - but do we need like a toggle?????
	//-BASE it on::: >>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	// - TESTED/WORKING!
	
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BSRR = 0b0100000000000000;

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;
	
    case 42: // was 33 - and invert the above
	// extra mode in which (both) pulse on is triggered by bitl but gated off by input bit or pulse - but do we need like a toggle?????
	//-BASE it on::: >>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	// - TESTED/WORKING!
	
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	else shift_registerl = (shift_registerl<<1) + (!bitl);

	if (bitl) GPIOB->BSRR = 0b0010000000000000;  // clear PC13 else write one
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BSRR = 0b0100000000000000;  
	else if (!(GPIOB->IDR & 0x0040)) GPIOB->BRR = 0b0100000000000000;

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;
	
    case 43: // was 34
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

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;
	
    case 44: // was 35
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

	if (bitl){ // calculate and output new bitl with case 3 Turing Machine:
	  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);

	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 45: // was 37
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// with input bit or'ed in
	if (shift_registerxl==0) shift_registerxl=0xff; // catch it!
	//	bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	bitl= ((shift_registerxl >> 31) ^ (shift_registerxl >> 29) ^ (shift_registerxl >> 25) ^ (shift_registerxl >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerxl = (shift_registerxl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl){ // calculate and output new bitl with case 3 Turing Machine:

	  bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0020) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);
	  
	
	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 46: // was 39
	// as above but LFSR?
      if (!(GPIOB->IDR & 0x0020)) togglel^=1; 

      if (togglel)
	  {
	    if (shift_registerl==0) shift_registerl=0xff; // catch it!
	    bitl= ((shift_registerl >> (lfsr_taps_mirrored[31][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	    shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040));  

	    if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	    else GPIOB->BSRR = 0b0010000000000000;  
	    if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	    else GPIOB->BSRR = 0b0100000000000000;
	  }

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 47: // test all replace 15 TESTY!
	// pulse in means we shift the logic operator
	if( !(GPIOB->IDR & 0x0020)) {
	lcount++;
	if (lcount>3) lcount=0;
	}
	
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 

	// logic ops
	
	if (lcount==0) shift_registerl= (shift_registerl<<1) + !(bitl | !(GPIOB->IDR & 0x0040));
	else if (lcount==1) shift_registerl= (shift_registerl<<1) + (bitl ^ !(GPIOB->IDR & 0x0040));
	else if (lcount==2) shift_registerl= (shift_registerl<<1) + !(bitl ^ !(GPIOB->IDR & 0x0040));
	else shift_registerl= (shift_registerl<<1) + (bitl & !(GPIOB->IDR & 0x0040));

	// testing for divide down

	new_statl=bitl;
	if (prev_statl==0 && new_statl==1) flipdl^=1;
	prev_statl=new_statl;	
	if (flipdl) GPIOB->BRR = 0b0010000000000000;  
	else GPIOB->BSRR = 0b0010000000000000;

	if (bitl) GPIOB->BRR = 0b0100000000000000;   // this is top one!
	else GPIOB->BSRR = 0b0100000000000000;

	targetl=(8503-(shift_registerl&0x1FFF))<<16;
	if (wherel>=targetl) {
	  goingupl=0; // decrease
	  interl=(wherel-targetl)/(speedll+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goingupl=1; // increase
	  interl=(targetl-wherel)/(speedll+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	
	// testing equal weightings
	//	tmp=bitsz[shift_registerl&0xff]+bitsz[(shift_registerl>>8)&0xff];
	//	tmp*=576; 
	//	spl=9464-tmp;
	
	//	spl=312+(shift_registerl&0x1FFF); // 0x0fff = 4095 which is 10 bits 0x7fff is 32767 which is 15 bits
	//	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	//	TIM3->ARR =spl;
	//	TIM3->CCR1 = spl/2; // pulse width
	break;
	
	// /END of LF SR side/..................................................................................................................    
    }
    //  }
  }
  
  //..........................................
    ////////////////////////////////////////////->>>    /// high side
//  if (modehsr<32){

  counterh++;
    if (counterh>speedhh){
      counterh=0;

      // *CV_HF: 0, 1, 2, 3, 4, 7, 9, 23, 25, 26, 28, 29, 34, 35, 36, 41*
      
      switch(modehsr){	 // SWITCH approach
      case 0:
	//->>>>>>>>>>>>>> 0- pulse clock in (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400)); // 0x0080 is clock bit in!
	else shift_registerh = (shift_registerh<<1) + (bith | (!(GPIOB->IDR & 0x0400))); 

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;

      case 1: 
	//->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
    
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400));
	else shift_registerh = (shift_registerh<<1) + ((bith ^ !(GPIOB->IDR & 0x0400)));

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;
    
      case 2: 
	//->>>>>>>>>>>>>> 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR selected with counter and pulse
	hcount++;
	if (hcount>31) hcount=0;
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 

	shift_registerh= (shift_registerh<<1) + (bith ^ !(GPIOB->IDR & 0x0400));

	//	if( !(GPIOB->IDR & 0x0080)) shift_registerh ^= (1<<hcount); // if we have pulse and hcount then flip that bit inside SR... rest all the same...
	if( !(GPIOB->IDR & 0x0080)) shift_registerx ^= (1<<hcount); // if we have pulse and lcount then flip that bit inside SR... rest all the same...
	shift_registerh ^= shift_registerx;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;
    
      case 3: //* 
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
		break;

      case 4: 
	//->>>>>>>>>>>>>> 4- parity for loopback XOR is determined by pulsed bits in -> select bits with pulse and queue 
	hcount++;
	if (hcount>31) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) {
	  hstack[3]=hstack[2];
	  hstack[2]=hstack[1];
	  hstack[1]=hstack[0];
	  hstack[0]=hcount+1; // bump it on to the hstack
	}	  

	bith= ((shift_registerh >> hstack[0]) ^ (shift_registerh >> hstack[1]) ^ (shift_registerh >> hstack[2]) ^ (shift_registerh >> hstack[3])) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh= (shift_registerh<<1) + ((bith) | !(GPIOB->IDR & 0x0400)); 
		
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;

      case 5: // was 7
	//->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed Q of lengths?
	// no use of in bit

	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
	if (hcount>7) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) probh^=(1<<hcount);
	hcount++;
	if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>31) & 0x01); 
	else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;

      case 6:  // was 9
	// 9- LFSR noise only with varying taps depending on length with new bit ORed in depending on pulse - for LF we can do mirroring!
	if (shift_registerh==0) shift_registerh=0xff; // catch it!
	bith= ((shift_registerh >> (lfsr_taps[31][0])) ^ (shift_registerh >> (lfsr_taps[31][1])) ^ (shift_registerh >> (lfsr_taps[31][2])) ^ (shift_registerh >> (lfsr_taps[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
  	break;

      case 7: // was 23 --> experimental modes 23+ here and 32+ in pulses - TESTED/WORKING!
	// shifting the array of LFSR taps = ghost_tapsH on the high side
	// clock pulse shifts one selected by pulse 
	if (!(GPIOB->IDR & 0x0080)) hcount++;
	if (hcount>3) hcount=0;
	if (!(GPIOB->IDR & 0x0400)) {
	  ghost_tapsH[31][hcount+1]+=1;
	  ghost_tapsH[31][hcount+1]%=31;
	}
	
	if (shift_registerh==0) shift_registerh=0xff; // catch it!
	bith= ((shift_registerh >> (ghost_tapsH[31][0])) ^ (shift_registerh >> (ghost_tapsH[31][1])) ^ (shift_registerh >> (ghost_tapsH[31][2])) ^ (shift_registerh >> (ghost_tapsH[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh = (shift_registerh<<1) + bith;
	
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
  	break;

      case 8: // was 25
	// SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits - TESTED/WORKING!
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	shift_registerh = (shift_registerh<<1) + (bith | (!(GPIOB->IDR & 0x0400)));
	// do the loop back in
	if( !(GPIOB->IDR & 0x0080)) hcount++;
	if (hcount>31) hcount=0;
	tmp = (shift_registerh>>hcount) & 0x01;
	// where to put that bit? XOR it with first bit
	if ( (shift_registerh & 0x01) ^ tmp) shift_registerh |= 0x01;// set the first bit
	else shift_registerh &= ~(0x01); // clear the first bit
	
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;

      case 9: // was 26
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// can use input bit as length of either SR
	// also can still use in clocking side of things
	// no use of input bit...
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[31][0])) ^ (shift_registerh >> (lfsr_taps[31][1])) ^ (shift_registerh >> (lfsr_taps[31][2])) ^ (shift_registerh >> (lfsr_taps[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with case 3 Turing Machine:

	  bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}
	break;

      case 10: // was 28
	// Independent LFSR clocking regular SR (only in CV as speed) - as mode 26 but now we use 0x0080 bit also to see if we shift things...
	// no use of input bit... - TESTED/WORKING!
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[31][0])) ^ (shift_registerh >> (lfsr_taps[31][1])) ^ (shift_registerh >> (lfsr_taps[31][2])) ^ (shift_registerh >> (lfsr_taps[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith && !(GPIOB->IDR & 0x0080) ){ // calculate and output new bith with case 3 Turing Machine:

	  bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	  // divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}
	break;

      case 11: // was 29
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)-> our 3 options if we have a bit 0x0080
	// - TESTED/WORKING!
	if (!(GPIOB->IDR & 0x0080)){
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}
	break;
	
      case 12: // was 34
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

	// divide down
	new_stath=(shift_registerh & (1<<lengthbith))>>lengthbith; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;

      case 13: // was 35
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

	if (bith){ // calculate and output new bith with case 3 Turing Machine:
	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<lengthbith))>>lengthbith; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}
	break;

      case 14: // was 36
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// can use input bit as length of either SR = here is shift_regx
	// works ok not so interesting as 35
       	hcount++;
	if (hcount>31) hcount=4;
	if (!(GPIOB->IDR & 0x0080)) {
	  SRlengthx=hcount;
	}
	
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	bith= ((shift_registerx >> (lfsr_taps[SRlengthx][0])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][1])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][2])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][3]))) & 1u; // 32 is 31, 29, 25, 24
	//	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with case 3 Turing Machine:
	  bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);
	  
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	  }
	break;
	
      case 15: // test all replace 15 TESTY!
	// pulse in means we shift the logic operator
	if( !(GPIOB->IDR & 0x0080)) {
	hcount++;
	if (hcount>3) hcount=0;
	}
	
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 

	// logic ops
	if (hcount==0) shift_registerh= (shift_registerh<<1) + !(bith | !(GPIOB->IDR & 0x0400));
	else if (hcount==1) shift_registerh= (shift_registerh<<1) + (bith ^ !(GPIOB->IDR & 0x0400));
	else if (hcount==2) shift_registerh= (shift_registerh<<1) + !(bith ^ !(GPIOB->IDR & 0x0400));
	else shift_registerh= (shift_registerh<<1) + (bith & !(GPIOB->IDR & 0x0400));
	
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;
	
	///////////////////
	// DAC modes HF side - interpol
	///////////////////
	//	/TODO:
      case 32:
	//->>>>>>>>>>>>>> 0- pulse clock in (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400)); // 0x0080 is clock bit in!
	else shift_registerh = (shift_registerh<<1) + (bith | (!(GPIOB->IDR & 0x0400))); 

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 33: 
	//->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
    
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400));
	else shift_registerh = (shift_registerh<<1) + ((bith ^ !(GPIOB->IDR & 0x0400)));

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;
    
      case 34: 
	//->>>>>>>>>>>>>> 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR selected with counter and pulse
	hcount++;
	if (hcount>31) hcount=0;
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 

	shift_registerh= (shift_registerh<<1) + (bith ^ !(GPIOB->IDR & 0x0400));

	//	if( !(GPIOB->IDR & 0x0080)) shift_registerh ^= (1<<hcount); // if we have pulse and hcount then flip that bit inside SR... rest all the same...
	if( !(GPIOB->IDR & 0x0080)) shift_registerx ^= (1<<hcount); // if we have pulse and lcount then flip that bit inside SR... rest all the same...
	shift_registerh ^= shift_registerx;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;
    
      case 35: //* 
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 36: 
	//->>>>>>>>>>>>>> 4- parity for loopback XOR is determined by pulsed bits in -> select bits with pulse and queue 
	hcount++;
	if (hcount>31) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) {
	  hstack[3]=hstack[2];
	  hstack[2]=hstack[1];
	  hstack[1]=hstack[0];
	  hstack[0]=hcount+1; // bump it on to the hstack
	}	  

	bith= ((shift_registerh >> hstack[0]) ^ (shift_registerh >> hstack[1]) ^ (shift_registerh >> hstack[2]) ^ (shift_registerh >> hstack[3])) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh= (shift_registerh<<1) + (bith | !(GPIOB->IDR & 0x0400)); // TESTY - to OR in new bit or not?

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 37: // was 7
	//->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed Q of lengths?
	// no use of in bit
	// !note: swop l and h when port to low!
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
	if (hcount>7) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) probh^=(1<<hcount);
	hcount++;
	if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>31) & 0x01); 
	else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 38:  // was 9
	// 9- LFSR noise only with varying taps depending on length with new bit ORed in depending on pulse - for LF we can do mirroring!
	if (shift_registerh==0) shift_registerh=0xff; // catch it!
	bith= ((shift_registerh >> (lfsr_taps[31][0])) ^ (shift_registerh >> (lfsr_taps[31][1])) ^ (shift_registerh >> (lfsr_taps[31][2])) ^ (shift_registerh >> (lfsr_taps[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
  
	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 39: // was 23 --> experimental modes 23+ here and 32+ in pulses - TESTED/WORKING!
	// shifting the array of LFSR taps = ghost_tapsH on the high side
	// clock pulse shifts one selected by pulse
	// modded so that pulse toggles PWM on/off can also be for pulse
	if (!(GPIOB->IDR & 0x0400))
	  {
	    hcount++;
	    if (hcount>3) hcount=0;
	    //if (!(GPIOB->IDR & 0x0400)) {
	    ghost_tapsH[31][hcount+1]+=1;
	    ghost_tapsH[31][hcount+1]%=31;
	  }
	    
	if (shift_registerh==0) shift_registerh=0xff; // catch it!
	bith= ((shift_registerh >> (ghost_tapsH[31][0])) ^ (shift_registerh >> (ghost_tapsH[31][1])) ^ (shift_registerh >> (ghost_tapsH[31][2])) ^ (shift_registerh >> (ghost_tapsH[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh = (shift_registerh<<1) + bith;
	
	if (!(GPIOB->IDR & 0x0080)) { //trigger toggle just once

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	if (flipped[0]==0) {
	    flipped[0]=1;
	    prev_state[0]=0;
	  }
	}
	else flipped[0]=0;
	  
	if (flipped[0]==1 && prev_state[0]==0)
	  {
	  prev_state[0]=1;

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	}
	break;

      case 40: // was 25
	// SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits - TESTED/WORKING!2
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	shift_registerh = (shift_registerh<<1) + (bith | (!(GPIOB->IDR & 0x0400)));
	// do the loop back in
	if( !(GPIOB->IDR & 0x0080)) hcount++;
	if (hcount>31) hcount=0;
	tmp = (shift_registerh>>hcount) & 0x01;
	// where to put that bit? XOR it with first bit
	if ( (shift_registerh & 0x01) ^ tmp) shift_registerh |= 0x01;// set the first bit
	else shift_registerh &= ~(0x01); // clear the first bit
	
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 41: // was 26
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// can use input bit as length of either SR
	// also can still use in clocking side of things
	// no use of input bit...
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[31][0])) ^ (shift_registerh >> (lfsr_taps[31][1])) ^ (shift_registerh >> (lfsr_taps[31][2])) ^ (shift_registerh >> (lfsr_taps[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with case 3 Turing Machine:

	  bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0080) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	  // divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}
	
	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 42: // was 28
	// Independent LFSR clocking regular SR (only in CV as speed) - as mode 26 but now we use 0x0080 bit also to see if we shift things...
	// no use of input bit... - TESTED/WORKING!
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[31][0])) ^ (shift_registerh >> (lfsr_taps[31][1])) ^ (shift_registerh >> (lfsr_taps[31][2])) ^ (shift_registerh >> (lfsr_taps[31][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith && !(GPIOB->IDR & 0x0080) ){ // calculate and output new bith with case 3 Turing Machine:

	  bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);
	  
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 43: // was 29
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (**no extra input bit is used)-> our 3 options if we have a bit 0x0080
	// - TESTED/WORKING!
	if (!(GPIOB->IDR & 0x0080)){
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;
	
      case 44: // was 34
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

	// divide down
	new_stath=(shift_registerh & (1<<lengthbith))>>lengthbith; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 45: // was 35
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

	if (bith){ // calculate and output new bith with case 3 Turing Machine:
	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<lengthbith))>>lengthbith; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;

      case 46: // was 36
	// Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
	// can use input bit as length of either SR = here is shift_regx
	// works ok not so interesting as 35
       	hcount++;
	if (hcount>31) hcount=4;
	if (!(GPIOB->IDR & 0x0080)) {
	  SRlengthx=hcount;
	}
	
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	bith= ((shift_registerx >> (lfsr_taps[SRlengthx][0])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][1])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][2])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][3]))) & 1u; // 32 is 31, 29, 25, 24
	//	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with case 3 Turing Machine:

	  bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);
	  
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	  }

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	break;
	
      case 47: // test all replace 15 TESTY!
	// pulse in means we shift the logic operator
	if( !(GPIOB->IDR & 0x0080)) {
	hcount++;
	if (hcount>3) hcount=0;
	}
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	// logic ops
	if (hcount==0) shift_registerh= (shift_registerh<<1) + !(bith | !(GPIOB->IDR & 0x0400));
	else if (hcount==1) shift_registerh= (shift_registerh<<1) + (bith ^ !(GPIOB->IDR & 0x0400));
	else if (hcount==2) shift_registerh= (shift_registerh<<1) + !(bith ^ !(GPIOB->IDR & 0x0400));
	else shift_registerh= (shift_registerh<<1) + (bith & !(GPIOB->IDR & 0x0400));
	
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}
	
	// To test equal weightings: so each bit is the same value - count number of bits - say for 16 bits
	//	tmp=bitsz[shift_registerh&0xff]+bitsz[(shift_registerh>>8)&0xff]+bitsz[(shift_registerh>>16)&0xff]+bitsz[(shift_registerh>>24)&0xff]; // now 32 bits
	//	tmp*=288; // was 576 for 16 bits now 576/2=288
	//	sph=9464-tmp;
	//	sph=1335-(shift_registerh&0x03FF); // or we can use different ranges - calculate these:
	// 8191+312=8503
	//	0x0FFF = 4095+312=4407, 0x07FF 2047+312=2359, 0x03FF 1023+312=1335, 0x01FF 511+312=823, 0x00FF 255+312=567
	//	TIM1->ARR =sph;
	//	TIM1->CCR1 = sph/2; // pulse width
		break;       
      }
      // /END of HF SR side/..................................................................................................................    
      //    }
  }
}
  
void TIM4_IRQHandler(void){
  uint32_t temp;
  // select modes, speeds and if necessary handle PWM depending on mode. Speed from main.c is 1KHz
  TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
  
  temp=(((ADCBuffer[0]>>10)+lastmodeh)/2); //smoothing necessary for higher speeds
  lastmodeh=temp;
  //  modehsr=63-(temp); // for a new total of 64 modes=6bits - no modehpwm - REVERSED or we reverse in cases
  modehsr=47; // TESTING all modes on H side 47 is exp mode for now 
  
  // 0-15 is pwmX
  // 16-31 is pulseX
  // 32-47 is pwm/DAC - maybe add mode which only updates pwm on pulse instead of say
  // 48 to 63 is pulse/DAC

  toth=toth-smoothh[hh];
  smoothh[hh]=ADCBuffer[2];
  toth+=smoothh[hh];
  hh++;
  if (hh>=SMOOTHINGS) hh=0;
  temp=toth/SMOOTHINGS;  

  speedh=logger[temp>>6]; // 1024  = 10 bits -> could be less logger to make smoother?
  speedhh=slower_even_logforSR[temp>>6]; // 1024 option = 10 bits log ->  could be less logger to make smoother? - could also be a lot slower at one end - TESTY even slower
  
  temp=(((ADCBuffer[1]>>10)+lastmodel)/2); //smoothing necessary for higher speeds - TEST!
  lastmodel=temp;
  //  modelsr=63-(temp); // for a new total of 64 modes=6bits - no modehpwm - REVERSED or we reverse in cases
  modelsr=0; // TESTING!
  
  totl=totl-smoothl[ll];
  smoothl[ll]=ADCBuffer[3];
  totl+=smoothl[ll];
  ll++;
  if (ll>=SMOOTHINGS) ll=0;
  temp=totl/SMOOTHINGS;  
  
  speedl=lf_logger[temp>>6]; // 1024  = 10 bits -> could be less logger to make smoother?
  speedll=slower_even_logforSR[temp>>6]; // 1024 option = 10 bits log ->  could be less logger to make smoother? - could also be a lot slower at one end
  
  if (modehsr<32) {
    TIM1->ARR = speedh;//period
    TIM1->CCR1 = speedh/2; // pulse
  }
  
  if (modelsr<32) {
    TIM3->ARR = speedl;//period
    TIM3->CCR1 = speedl/2; // pulse  
  }  
}


void EXTI9_5_IRQHandler(void){
  // LF and HF pulse in on falling edges

  uint8_t x, numflips, shifter;
  uint8_t bith, bitl;
  uint32_t pending = EXTI->PR;
  uint32_t SRlengthx=31, SRlengthl, SRlengthh, lengthbitl, lengthbith;
  uint32_t spl, sph;

  // --------------------LF pulse modes
  if(pending & (1 << 5)) { // LF on 5 out on B
    EXTI->PR = 1 << 5; // clear pending flag, otherwise we'd get endless interrupts -!!!!!!!!!!!!!!!!!!!!!!!!!        // handle pin 5 here

    // ported from HF and tested
    switch(modelsr){
    case 16: // was 11 - leave in middle// MAYBE put this in middle of CV select mode for easy access TODO
      //->>>>>>>>>>>>>> CV selects length of SR which will stay with us .. -> LFSR here
      SRlengthl=31-(ADCBuffer[3]>>11);
      if (SRlengthl<4) SRlengthl=4;
      lengthbitl=(1<<(SRlengthl/2));
      if (shift_registerl==0) shift_registerl=0xff;
      bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
      shift_registerl = (shift_registerl<<1) + ((bitl | !(GPIOB->IDR & 0x0040))); // PB7 and PB10

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;  
      break;

    case 17: // was 10
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit 
      lcount++;
      if (lcount>7) lcount=0;
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
      
      if((ADCBuffer[3]>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
      else shift_registerl = (shift_registerl<<1) + bitl;

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;
      break;
      
    case 18: // was 12 - works fine with cv in - was 8 - extra DAC modes
      //->>>>>>>>>>>>>> NEW mode TESTY: entry of ADC in from CV into upper bits?
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      if (counter12l > 7){       // every 8 cycles
	counter12l=0;
	shift_registerl &= MASK[31]; // MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
	shift_registerl +=(ADCBuffer[3]>>8)<<(SHIFT[31]);  // tested and this makes sense on test.c
      }
      counter12l++;

      shift_registerl=(shift_registerl<<1) + (bitl |  (!(GPIOB->IDR & 0x0040))); // cycle around and OR in pulse bit! TESTY!

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000;
      break;

    case 19: // was 13
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // we do not use bit IN!
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out -
      probl=ADCBuffer[3]>>13; // 3 bits now for electroprob array
      probl=electroprob[probl];

      if (((probl | shift_registerl) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerl>>31) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerl = (shift_registerl<<1) + bitl;

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000;
      break;

    case 20: // was 14 - could replace mode or one of these ???
      //->>>>>>>>>>>>>> uses CV as speed/flipflop/clock divider
      // pulse in inverts the cycling bit in a la Turing Machine - cycle bit or invert bit = thus we do use input bit
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
      if (GPIOB->IDR & 0x0040) shift_registerl =  (shift_registerl<<1) + bitl;
      else shift_registerl = (shift_registerl<<1) + (!bitl);

      // flip flop: rising edge - if last was 0 and now is 1 then we trigger flip 1-0 or 0-1
      numflips=(ADCBuffer[3]>>12); //or 15-(ADCBuffer[3]>>12) if we wish it to go in the opposite direction
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
      if (shift_registerl & (1<<15)) {
	if (bitl)	GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000;
      }
      break;

    case 21: // was 15 replace by case 56
      //->>>>>>>>>>>>>> as mode 14=speed divider with XOR rungler: XOR out with input bit
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
      shift_registerl = (shift_registerl<<1) + ((bitl) ^ (!(GPIOB->IDR & 0x0040)));

      numflips=(ADCBuffer[3]>>12); //or 15-(ADCBuffer[3]>>12) if we wish it to go in the opposite direction
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
      if (shift_registerl & (1<<15)) {
	if (bitl)	GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;
      }
      break;
      
    case 22: // was 43
      // as above but other way round with CV for length and incoming bits for probability of TM
      SRlengthl=31-(ADCBuffer[3]>>11);
      if (SRlengthl<4) SRlengthl=4;
      lengthbitl=(1<<(SRlengthl/2));

      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -

      if (lcount>7) lcount=0;
      if( !(GPIOB->IDR & 0x0040)) probl^=(1<<lcount);
      lcount++;
      
      if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + bitl;
      else shift_registerl = (shift_registerl<<1) + (!bitl);
      
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;  
      break;
	      
    case 23: // was 44
      // as mode 10 
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 1st option of above... - *more maybe on LF side these ones*
      // - TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0040)){
	lcount++;
	if (lcount>7) lcount=0;
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
	if((ADCBuffer[3]>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000;
      }
      break;

        case 24: // was 45 to be replaced by case 62
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 3rd option of above...
      	// - TESTED/WORKING!
      lcount++;
      if (lcount>7) lcount=0;
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
	if((ADCBuffer[3]>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (!(GPIOB->IDR & 0x0040)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000;
      }
	break;
      
      
    case 25: // was 47
      // *we could use CV to set length of pulse (say up to 128 which is 7 bits >> 9)*
      //->>>>>>>>>>>>>> as mode 14=speed divider with XOR rungler: XOR out with input bit
      	// - TESTED/WORKING! - not so exciting ....
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
      shift_registerl = (shift_registerl<<1) + ((bitl) ^ (!(GPIOB->IDR & 0x0040)));
      
	if (bitl) {
	  GPIOB->BRR = 0b0010000000000000; 
	  delay(ADCBuffer[3]>>9); // 64=10uS - short = lower voltage...
	  GPIOB->BSRR = 0b0010000000000000;  
	}
	  
	if (shift_registerl & (1<<15)) {
	  GPIOB->BRR = 0b0100000000000000;  
	  delay(ADCBuffer[3]>>9); // 64=10uS
	  GPIOB->BSRR = 0b0100000000000000;  
	  }
	break;

    case 26: // was 51
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out -
      probl=ADCBuffer[3]>>13; // 3 bits now for electroprob array
      probl=electroprob[probl];

      if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerh>>31) & 0x01); 
      else shift_registerl = (shift_registerl<<1) + bitl;

      if (!(GPIOB->IDR & 0x0040)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000; 
      }
      break;

    case 27: // was 52
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0040)){
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out -
      probl=ADCBuffer[3]>>13; // 3 bits now for electroprob array
      probl=electroprob[probl];

      if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerh>>31) & 0x01); 
      else shift_registerl = (shift_registerl<<1) + bitl;
      }
      
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
      break;

    case 28: // was 53
      // - after case 25 - SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits
      // change and Re_test this - TESTED/working
      // loop bitl back in XOR at certain point?
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
	shift_registerl = (shift_registerl<<1);
	// do the loop back in
	lcount=ADCBuffer[3]>>11; // 5 bits - or: lcount=(ADCBuffer[3]>>11)%(SRlengthl+1);
	if (bitl) shift_registerl ^= (1<<lcount);// set the xth bit
	shift_registerl ^= (!(GPIOB->IDR & 0x0040));
	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000; 
	break;
	
    case 29: // was 56
      // Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
      // can use CV as length of either SR = here is regularSR
      //       - TESTED/working
      SRlengthl=(ADCBuffer[3]>>11);
      if (SRlengthl<4) SRlengthl=4;
      lengthbitl=(1<<(SRlengthl/2));
	
	if (shift_registerxl==0) shift_registerxl=0xff; // catch it!
	//	bitl= ((shift_registerl >> (lfsr_taps_mirrored[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps_mirrored[SRlengthl][3]))) & 1u; // 32 is 31, 29, 25, 24
	bitl= ((shift_registerxl >> 31) ^ (shift_registerxl >> 29) ^ (shift_registerxl >> 25) ^ (shift_registerxl >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerxl = (shift_registerxl<<1) + bitl; // could or with incoming as we don't use this TESTY: shift_registerxl = (shift_registerx<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl){ // calculate and output new bitl with case 3 Turing Machine:
	  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);

	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}
	break;

    case 30: // was 57
      // Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
      // can use CV as length of either SR = here is SRx
      //       - TESTED/working but not so satisfying for ADCBuffer[3] use
      SRlengthx=(ADCBuffer[3]>>11);
      if (SRlengthx<4) SRlengthx=4;
	
	if (shift_registerxl==0) shift_registerxl=0xff; // catch it!
	bitl= ((shift_registerxl >> (lfsr_taps_mirrored[SRlengthx][0])) ^ (shift_registerxl >> (lfsr_taps_mirrored[SRlengthx][1])) ^ (shift_registerxl >> (lfsr_taps_mirrored[SRlengthx][2])) ^ (shift_registerxl >> (lfsr_taps_mirrored[SRlengthx][3]))) & 1u; // 32 is 31, 29, 25, 24
	//	bitl= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerxl = (shift_registerxl<<1) + bitl; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bitl | !(GPIOB->IDR & 0x0040)); 

	if (bitl){ // calculate and output new bitl with case 3 Turing Machine:
	  bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<1) + bitl;
	  else shift_registerl = (shift_registerl<<1) + (!bitl);

	  if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	  else GPIOB->BSRR = 0b0010000000000000;  
	  if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	  else GPIOB->BSRR = 0b0100000000000000;
	}
	break;

    case 31: // was 58 -  change the shifting amount 
      shifter=(ADCBuffer[3]>>11);
      if (shifter==0) shifter=1;
      // TM here
      bitl = (shift_registerl>>(31-(shifter-1))) & (shifter); // bits which would be shifted out  // 1 for length of 31
      if (GPIOB->IDR & 0x0040) shift_registerl = (shift_registerl<<shifter) + bitl;
      else shift_registerl = (shift_registerl<<shifter) + (~bitl);

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;  
      break;

      /////
      //// LF DAC modes
      ///.......
      
    case 48: // was 10
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit 
      lcount++;
      if (lcount>7) lcount=0;
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
      
      if((ADCBuffer[3]>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
      else shift_registerl = (shift_registerl<<1) + bitl;

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;

      spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;
      
    case 49: // was 12 - works fine with cv in - was 8 - extra DAC modes
      //->>>>>>>>>>>>>> NEW mode TESTY: entry of ADC in from CV into upper bits?
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      if (counter12l > 7){       // every 8 cycles
	counter12l=0;
	shift_registerl &= MASK[31]; // MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
	shift_registerl +=(ADCBuffer[3]>>8)<<(SHIFT[31]);  // tested and this makes sense on test.c
      }
      counter12l++;

      shift_registerl=(shift_registerl<<1) + (bitl |  (!(GPIOB->IDR & 0x0040))); // cycle around and OR in pulse bit! TESTY!

      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000;

      spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;
      
    case 50: // was 43
      // as above but other way round with CV for length and incoming bits for probability of TM
      SRlengthl=31-(ADCBuffer[3]>>11);
      if (SRlengthl<4) SRlengthl=4;
      lengthbitl=(1<<(SRlengthl/2));

      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -

      if (lcount>7) lcount=0;
      if( !(GPIOB->IDR & 0x0040)) probl^=(1<<lcount);
      lcount++;
      
      if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + bitl;
      else shift_registerl = (shift_registerl<<1) + (!bitl);
      
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000;  
      if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000; 
      else GPIOB->BSRR = 0b0100000000000000;

      spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;
	      
    case 51: // was 44
      // as mode 10 
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 1st option of above... - *more maybe on LF side these ones*
      // - TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0040)){
	lcount++;
	if (lcount>7) lcount=0;
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
	if((ADCBuffer[3]>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000;
      }
      // PWM could be inside }

      spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;

    case 52: // was 45
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 3rd option of above...
      	// - TESTED/WORKING!
      lcount++;
      if (lcount>7) lcount=0;
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
	if((ADCBuffer[3]>>(8+lcount))&1) shift_registerl = (shift_registerl<<1) + (!bitl); // or we could & with input bit - TO TEST!
	else shift_registerl = (shift_registerl<<1) + bitl;

	if (!(GPIOB->IDR & 0x0040)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000; 
	else GPIOB->BSRR = 0b0100000000000000;
      }
      // PWM could be inside }

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 53: // was 47
      // *we could use CV to set length of pulse (say up to 128 which is 7 bits >> 9)*
      //->>>>>>>>>>>>>> as mode 14=speed divider with XOR rungler: XOR out with input bit
      	// - TESTED/WORKING! - not so exciting ....
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
      shift_registerl = (shift_registerl<<1) + ((bitl) ^ (!(GPIOB->IDR & 0x0040)));
      
	if (bitl) {
	  GPIOB->BRR = 0b0010000000000000; 
	  delay(ADCBuffer[3]>>9); // 64=10uS - short = lower voltage...
	  GPIOB->BSRR = 0b0010000000000000;  
	}
	  
	if (shift_registerl & (1<<15)) {
	  GPIOB->BRR = 0b0100000000000000;  
	  delay(ADCBuffer[3]>>9); // 64=10uS
	  GPIOB->BSRR = 0b0100000000000000;  
	  }

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 54: // was 51
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out -
      probl=ADCBuffer[3]>>13; // 3 bits now for electroprob array
      probl=electroprob[probl];

      if (((probl | shift_registerh) & 0xff ) == 0xff) shift_registerl = (shift_registerl<<1) + ((shift_registerh>>31) & 0x01); 
      else shift_registerl = (shift_registerl<<1) + bitl;

      if (!(GPIOB->IDR & 0x0040)){
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000; 
      }
      // PWM could be inside }

      spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;

    case 55: // was 53
      // - after case 25 - SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits
      // change and Re_test this - TESTED/working
      // loop bitl back in XOR at certain point?
	bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
	shift_registerl = (shift_registerl<<1);
	// do the loop back in
	lcount=ADCBuffer[3]>>11; // 5 bits - or: lcount=(ADCBuffer[3]>>11)%(SRlengthl+1);
	if (bitl) shift_registerl ^= (1<<lcount);// set the xth bit
	shift_registerl ^= (!(GPIOB->IDR & 0x0040));
	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOB->BSRR = 0b0010000000000000; 
	if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  
	else GPIOB->BSRR = 0b0100000000000000;

	spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
	TIM3->ARR =spl;
	TIM3->CCR1 = spl/2; // pulse width
	break;

    case 56: // - TEST CASE FOR new ADC/DAC modes...
      //this version works fine and we could also use 0x0040 to choose recycle or not
      //->>>>>>>>>>>>>> NEW mode TESTY: entry of ADC in from CV into upper bits?
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      // TESTY - put 4 bits in at 4 points and take out at 4 points 
      if (counter12l > 7){       // every 8 cycles
	counter12l=0;
	//	shift_registerl &= MASK[31]; // MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
	//	shift_registerl +=(ADCBuffer[3]>>8)<<(SHIFT[31]);  // tested and this makes sense on test.c
	shift_registerl +=(ADCBuffer[3]>>8);  // tested and this makes sense on test.c
	//	shift_registerl &=(ADCBuffer[3]>>8);
      }
      counter12l++;
      
      //      shift_registerl=(shift_registerl<<1) + (bitl |  (!(GPIOB->IDR & 0x0040))); // cycle around and OR in pulse bit! TESTY! - or no recycle
      if (GPIOB->IDR & 0x0040) shift_registerl =  (shift_registerl<<1) + bitl;
      else shift_registerl=(shift_registerl<<1);
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
	
      spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;

    case 57: // - TEST CASE FOR new ADC/DAC modes...
      // shift in bits one by one use probl as storage

      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
      counter12l++;
      if (counter12l > 7){       // every 8 cycles
	counter12l=0;
	// store the full bit or take successive bits
	probl=(ADCBuffer[3]>>8); // probl is 8 bits
	}
      
      // shift that new bit in (or this could depend on 0x400 for recycles
      if (GPIOB->IDR & 0x0040) shift_registerl =  (shift_registerl<<1) + bitl;
      else shift_registerl=(shift_registerl<<1) + ((probl&bits[counter12l])>>counter12l);

      
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
	
      spl=8503-(shift_registerl&0x1FFF); // or we can use different ranges
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;
     
    case 58: // TEST CASE FOR new ADC/DAC modes...
      // put say 4 or 8 bits in at intervals - no recycle so far - works so far!
      // and DAC out is at later intervals
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      shift_registerl &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 4 bits in
      probl=(ADCBuffer[3]>>12); // 4 bits
      shift_registerl += ( (probl&0x01) + ((probl&0x02)<<7) + ((probl&0x04)<<14) + ((probl&0x08)<<21)); // would be 0 8-1 16-2 24-3

      shift_registerl=(shift_registerl<<1);// + bitl;
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
	
      spl= (((shift_registerl&(1<<7))>>7) + ((shift_registerl&(1<<15))>>14) + ((shift_registerl&(1<<23))>>21) + ((shift_registerl&(1<<31))>>28))<<6; // this one from test.c tested... so that is 4 bits <<4 to 10 bits = 1024 11 is 2048 12 is 4096
// keeps it high!

      spl=1336-spl; // try 312+1024=1336- 312+2048=2360
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width	
      break;

    case 59: // TEST CASE FOR new ADC/DAC modes...
      // put say 4 or 8 bits in at intervals
      // ** cycle the SR
      // and DAC out is at later intervals
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      shift_registerl &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 4 bits in
      probl=(ADCBuffer[3]>>12); // 4 bits
      shift_registerl += ( ((probl&0x01)^bitl) + ((probl&0x02)<<7) + ((probl&0x04)<<14) + ((probl&0x08)<<21)); // would be 0 8-1 16-2 24-3

      shift_registerl=(shift_registerl<<1);// + bitl; // can be with or without extra incoming bit
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
	
      spl= (((shift_registerl&(1<<7))>>7) + ((shift_registerl&(1<<15))>>14) + ((shift_registerl&(1<<23))>>21) + ((shift_registerl&(1<<31))>>28))<<7; // this one from test.c tested...

      spl=2360-spl; // try 312+1024=1336- 312+2048=2360
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;

    case 60: // TEST CASE FOR new ADC/DAC modes...
      // put say 4 or 8 bits in at intervals
      // ** SR with incoming bit
      // and DAC out is at later intervals
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      shift_registerl &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 4 bits in
      probl=(ADCBuffer[3]>>12); // 4 bits
      shift_registerl += ( ((probl&0x01)^(!(GPIOB->IDR & 0x0040))) + ((probl&0x02)<<7) + ((probl&0x04)<<14) + ((probl&0x08)<<21)); // would be 0 8-1 16-2 24-3

      shift_registerl=(shift_registerl<<1);// + bitl; // can be with or without extra incoming bit
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
	
      // no extract those 4 bits from the last slots bits 32, 24, 16 and 8, shift these and then << say 4 bits
      //	  spl= (((shift_registerl&(1<<8))>>8) + ((shift_registerl&(1<<16))>>15) + ((shift_registerl&(1<<24))>>22) + ((shift_registerl&(1<<32))>>29))<<4;

      spl= (((shift_registerl&(1<<7))>>7) + ((shift_registerl&(1<<15))>>14) + ((shift_registerl&(1<<23))>>21) + ((shift_registerl&(1<<31))>>28))<<7; // this one from test.c tested...
      spl=2360-spl;
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;

    case 61: // TEST CASE FOR new ADC/DAC modes...      
      // let's try for 8 bits
      // check logic of this one after 3 bit shifts in test.c -> tested with one mistake fixed
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      // try for 8 bits in at 3 bits intervals
      shift_registerl &= 0b11101110111011101110111011101110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 8 bits in
      probl=(ADCBuffer[3]>>8); // 8 bits
      shift_registerl += (  ((probl&0x01)) + ((probl&0x02)<<3) + ((probl&0x04)<<6) + ((probl&0x08)<<9) + ((probl&0x10)<<12) + ((probl&0x20)<<15) + ((probl&0x40)<<18) + ((probl&0x80)<<21) );

      shift_registerl=(shift_registerl<<1);// + bitl; // can be with or without extra incoming bit
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 

      spl= (((shift_registerl&(1<<3))>>3) + ((shift_registerl&(1<<7))>>6) + ((shift_registerl&(1<<11))>>9) + ((shift_registerl&(1<<15))>>12) + ((shift_registerl&(1<<19))>>15) +((shift_registerl&(1<<23))>>18) +((shift_registerl&(1<<27))>>21) +((shift_registerl&(1<<31))>>24))<<4; // this one from test.c tested...
      spl=4408-spl; // 12 bits=4096+312=4408
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;

    case 62: // TEST CASE FOR new ADC/DAC modes...
      // try and use incoming bit to shift 4 bits in lstack - working now
	lcount++;
      // but can go over - max we want now is 27
	if (lcount>27) lcount=0;
	if( !(GPIOB->IDR & 0x0040)) {
	  lstack[3]=lstack[2];
	  lstack[2]=lstack[1];
	  lstack[1]=lstack[0];
	  lstack[0]=lcount+1; // bump it on to the lstack
	}	  
      
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      // we need a new mask
      //      shift_registerl &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      shift_registerl &= ~ (((0x01)<< lstack[0]) + ((0x02)<<lstack[1]) + ((0x04)<<lstack[2]) + ((0x08)<<lstack[3]));
      // put the 4 bits in
      probl=(ADCBuffer[3]>>12); // 4 bits
      shift_registerl += ( ((probl&0x01)<< lstack[0]) + ((probl&0x02)<<lstack[1]) + ((probl&0x04)<<lstack[2]) + ((probl&0x08)<<lstack[3])); // would be 0 8-1 16-2 24-3

      shift_registerl=(shift_registerl<<1) + bitl; // leave this as bitl
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 
	
      spl= (((shift_registerl&(1<<7))>>7) + ((shift_registerl&(1<<15))>>14) + ((shift_registerl&(1<<23))>>21) + ((shift_registerl&(1<<31))>>28))<<7; // this one from test.c tested...
      spl=2360-spl;
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;

    case 63: // TEST CASE FOR new ADC/DAC modes...
	    // try and use incoming bit to shift 4 bits in lstack - working now
	    // same as above but now we do for the output bits - maybe not so interesting as just effects the DAC! seems oks!
	lcount++;

	if (lcount>28) lcount=0;
	if( !(GPIOB->IDR & 0x0040)) {
	  lstack[3]=lstack[2];
	  lstack[2]=lstack[1];
	  lstack[1]=lstack[0];
	  lstack[0]=lcount+1; // bump it on to the lstack
	}	  
      
      bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      shift_registerl &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 4 bits in
      probl=(ADCBuffer[3]>>12); // 4 bits
      //      shift_registerl += ( ((probl&0x01)<< lstack[0]) + ((probl&0x02)<<lstack[1]) + ((probl&0x04)<<lstack[2]) + ((probl&0x08)<<lstack[3])); // would be 0 8-1 16-2 24-3
      shift_registerl += ( ((probl&0x01)^bitl) + ((probl&0x02)<<7) + ((probl&0x04)<<14) + ((probl&0x08)<<21)); // would be 0 8-1 16-2 24-3

      shift_registerl=(shift_registerl<<1) + bitl;
      if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOB->BSRR = 0b0010000000000000; 
      if (shift_registerl & (1<<15)) GPIOB->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
      else GPIOB->BSRR = 0b0100000000000000; 	

      spl= ( (shift_registerl&(1<<lstack[0])) + (shift_registerl&(1<<lstack[1])) + (shift_registerl&(1<<lstack[2])) + (shift_registerl&(1<<lstack[3])) ); // this one from test.c tested... - or we space out a bit
      spl+=312;
      TIM3->ARR =spl;
      TIM3->CCR1 = spl/2; // pulse width
      break;
    }       /// end of LF modes
  }

  // --------------------HF Pulse modes 
  if(pending & (1 << 7)) { // HF on 7/out on C
    EXTI->PR = 1 << 7;        // handle pin 7 here

//*PULSE_HF: 10, 11, 12, 13, 14, 15, 43, 44, 45, 48, 50, 52, 53, 56, 57, 58*
    
    switch(modehsr){
    case 16: // was 11 - leave in middle// MAYBE put this in middle of CV select mode for easy access TODO
      //->>>>>>>>>>>>>> CV selects length of SR which will stay with us .. -> LFSR here
      SRlengthh=31-(ADCBuffer[2]>>11);
      if (SRlengthh<4) SRlengthh=4;
      lengthbith=(1<<(SRlengthh/2));
      if (shift_registerh==0) shift_registerh=0xff;
      bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
      shift_registerh = (shift_registerh<<1) + ((bith | !(GPIOB->IDR & 0x0400))); // PB7 and PB10

	// divide down
	new_stath=(shift_registerh & (1<<lengthbith))>>lengthbith; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      break;
      
    case 17: // was 10
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit 
      hcount++;
      if (hcount>7) hcount=0;
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
      
      if((ADCBuffer[2]>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
      else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      break;
      
    case 18: // was 12 - works fine with cv in  TEST CASE FOR new ADC/DAC modes...
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      if (counter12h > 7){       // every 8 cycles
	counter12h=0;
	shift_registerh &= MASK[31]; // MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
	shift_registerh +=(ADCBuffer[2]>>8)<<(SHIFT[31]);  // tested and this makes sense on test.c
      }
      counter12h++;
      
      shift_registerh=(shift_registerh<<1) + (bith |  (!(GPIOB->IDR & 0x0400))); // cycle around and OR in pulse bit! TESTY! - or no recycle
      shift_registerh=(shift_registerh<<1) + (bith);

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;
     
    case 19: // was 13
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // we do not use bit IN!
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
      probh=ADCBuffer[2]>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>31) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      break;
            
    case 20: // was 14 - could replace mode or one of these ???
      //->>>>>>>>>>>>>> uses CV as speed/flipflop/clock divider
      // pulse in inverts the cycling bit in a la Turing Machine - cycle bit or invert bit = thus we do use input bit
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
      //      origbith=bith;
      if (GPIOB->IDR & 0x0400) shift_registerh =  (shift_registerh<<1) + bith;
      else shift_registerh = (shift_registerh<<1) + (!bith);

      // flip flop: rising edge - if last was 0 and now is 1 then we trigger flip 1-0 or 0-1
      numflips=(ADCBuffer[2]>>12); //or 15-(ADCBuffer[2]>>12) if we wish it to go in the opposite direction
      new_state[0]=bith;
      if (prev_state[0]==0 && new_state[0]==1) flipped[0]^=1;
      prev_state[0]=new_state[0];	

      for (x=1;x<numflips;x++){ 
	new_state[x]=flipped[x-1];
	if (prev_state[x]==0 && new_state[x]==1) flipped[x]^=1;
	prev_state[x]=new_state[x];
      }
      if (numflips>0)	bith=flipped[numflips-1];

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;
            
      
    case 21: // was 15
      //->>>>>>>>>>>>>> as mode 14=speed divider with XOR rungler: XOR out with input bit
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
      shift_registerh = (shift_registerh<<1) + ((bith) ^ (!(GPIOB->IDR & 0x0400)));

      numflips=(ADCBuffer[2]>>12); //or 15-(ADCBuffer[2]>>12) if we wish it to go in the opposite direction
      new_state[0]=bith;
      if (prev_state[0]==0 && new_state[0]==1) flipped[0]^=1;
      prev_state[0]=new_state[0];	

      for (x=1;x<numflips;x++){ 
	new_state[x]=flipped[x-1];
	if (prev_state[x]==0 && new_state[x]==1) flipped[x]^=1;
	prev_state[x]=new_state[x];
      }
      if (numflips>0)	bith=flipped[numflips-1];
      // no divider - check this one      
      if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000;
      if (shift_registerh & (1<<15)) {
	if (bith)	GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000;
      }
      break;

    case 22: // was 43
      // as above but other way round with CV for length and incoming bits for probability of TM
      SRlengthh=31-(ADCBuffer[2]>>11);
      if (SRlengthh<4) SRlengthh=4;
      lengthbith=(1<<(SRlengthh/2));
      
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -

      if (hcount>7) hcount=0;
      if( !(GPIOB->IDR & 0x0400)) probh^=(1<<hcount);
      hcount++;
      
      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + bith;
      else shift_registerh = (shift_registerh<<1) + (!bith);
      
	// divide down
	new_stath=(shift_registerh & (1<<lengthbith))>>lengthbith; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      break;
      
    case 23: // was 44
      // as mode 10 
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 1st option of above... - *more maybe on LF side these ones*
      // - TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0400)){
	hcount++;
	if (hcount>7) hcount=0;
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	if((ADCBuffer[2]>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
	else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      }
      break;

          case 24: // was 45 swaps into case 62:
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 3rd option of above...
      	// - TESTED/WORKING!
      hcount++;
      if (hcount>7) hcount=0;
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	if((ADCBuffer[2]>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
	else shift_registerh = (shift_registerh<<1) + bith;

	if (!(GPIOB->IDR & 0x0400)){
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      }
      break;
     
    case 25: // was 48
      //      	  extra mode in which pulse on is triggered by bitH but gated off by input bit or pulse
      // use mode 13 as example here:::
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      	// - TESTED/WORKING!
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
      probh=ADCBuffer[2]>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>31) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;

      	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	break;
      
    case 26: // was 50
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0400)){
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
      probh=ADCBuffer[2]>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>31) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      }
      break;

    case 27: // was 52
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0400)){
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
      probh=ADCBuffer[2]>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>31) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;
      }
      
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      break;

    case 28: // was 53
      // - after case 25 - SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits
      // change and Re_test this - TESTED/working
      // loop bith back in XOR at certain point?
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	shift_registerh = (shift_registerh<<1);
	// do the loop back in
	hcount=ADCBuffer[2]>>11; // 5 bits - or: hcount=(ADCBuffer[2]>>11)%(31+1);
	if (bith) shift_registerh ^= (1<<hcount);// set the xth bit
	shift_registerh ^= (!(GPIOB->IDR & 0x0400));
	
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	break;
	
    case 29: // was 56
      // Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
      // can use CV as length of either SR = here is regularSR
      //       - TESTED/working
      SRlengthh=(ADCBuffer[2]>>11);
      if (SRlengthh<4) SRlengthh=4;
      lengthbith=(1<<(SRlengthh/2));
	
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	//	bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with case 3 Turing Machine:
	  bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<lengthbith))>>lengthbith; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	}
	break;

    case 30: // was 57
      // Independent LFSR clocking regular SR (only in CV as speed) - TESTED/WORKING!
      // can use CV as length of either SR = here is SRx
      //       - TESTED/working but not so satisfying for ADCBuffer[2] use

      SRlengthx=(ADCBuffer[2]>>11);
      if (SRlengthx<4) SRlengthx=4;
	
	if (shift_registerx==0) shift_registerx=0xff; // catch it!
	bith= ((shift_registerx >> (lfsr_taps[SRlengthx][0])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][1])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][2])) ^ (shift_registerx >> (lfsr_taps[SRlengthx][3]))) & 1u; // 32 is 31, 29, 25, 24
	//	bith= ((shift_registerx >> 31) ^ (shift_registerx >> 29) ^ (shift_registerx >> 25) ^ (shift_registerx >> 24)) & 1u; // 32 is 31, 29, 25, 24
	shift_registerx = (shift_registerx<<1) + bith; // could or with incoming as we don't use this TESTY: shift_registerx = (shift_registerx<<1) + (bith | !(GPIOB->IDR & 0x0400)); 

	if (bith){ // calculate and output new bith with case 3 Turing Machine:
	  bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out 
	  if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<1) + bith;
	  else shift_registerh = (shift_registerh<<1) + (!bith);

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

	}
	break;

    case 31: // was 58 -  change the shifting amount - working
      shifter=(ADCBuffer[2]>>11);
      if (shifter==0) shifter=1;
      // TM here
      bith = (shift_registerh>>(31-(shifter-1))) & (shifter); // bits which would be shifted out  // 1 for length of 31
      if (GPIOB->IDR & 0x0400) shift_registerh = (shift_registerh<<shifter) + bith;
      else shift_registerh = (shift_registerh<<shifter) + (~bith);

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      break;

      /////////////////
      //// HF DAC modes
      ///....
      
    case 48: // was 10
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit 
      hcount++;
      if (hcount>7) hcount=0;
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
      
      if((ADCBuffer[2]>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
      else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;

    case 49: // was 12 - works fine with cv in  TEST CASE FOR new ADC/DAC modes...
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      if (counter12h > 7){       // every 8 cycles
	counter12h=0;
	shift_registerh &= MASK[31]; // MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
	shift_registerh +=(ADCBuffer[2]>>8)<<(SHIFT[31]);  // tested and this makes sense on test.c
      }
      counter12h++;
      
      shift_registerh=(shift_registerh<<1) + (bith |  (!(GPIOB->IDR & 0x0400))); // cycle around and OR in pulse bit! TESTY! - or no recycle
      shift_registerh=(shift_registerh<<1) + (bith);

      // divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;
      
    case 50: // was 43
      // as above but other way round with CV for length and incoming bits for probability of TM
      SRlengthh=31-(ADCBuffer[2]>>11);
      if (SRlengthh<4) SRlengthh=4;
      lengthbith=(1<<(SRlengthh/2));
      
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -

      if (hcount>7) hcount=0;
      if( !(GPIOB->IDR & 0x0400)) probh^=(1<<hcount);
      hcount++;
      
      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + bith;
      else shift_registerh = (shift_registerh<<1) + (!bith);
      
	// divide down
	new_stath=(shift_registerh & (1<<lengthbith))>>lengthbith; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	
      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;
      
    case 51: // was 44
      // as mode 10 
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 1st option of above... - *more maybe on LF side these ones*
      // - TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0400)){
	hcount++;
	if (hcount>7) hcount=0;
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	if((ADCBuffer[2]>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
	else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      }
      // PWM could be inside }
      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;

    case 52: // was 45
      //->>>>>>>>>>>>>> entry into SR from CV - TM = no input bit = 3rd option of above...
      	// - TESTED/WORKING!
      hcount++;
      if (hcount>7) hcount=0;
	bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
	if((ADCBuffer[2]>>(8+hcount))&1) shift_registerh = (shift_registerh<<1) + (!bith); // or we could & with input bit - TO TEST!
	else shift_registerh = (shift_registerh<<1) + bith;

	if (!(GPIOB->IDR & 0x0400)){
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

      }
      // PWM could be inside }

	// INTERPOL TEST
	targeth=(4407-(shift_registerh&0x0FFF))<<16;
	if (whereh>=targeth) {
	  goinguph=0; // decrease
	  interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}	  
	else {
	  goinguph=1; // increase
	  interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
	}

	break;

    case 53: // was 48
      //      	  extra mode in which pulse on is triggered by bitH but gated off by input bit or pulse
      // use mode 13 as example here:::
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      	// - TESTED/WORKING!
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
      probh=ADCBuffer[2]>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>31) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      
      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;

    case 54: // was 50
      //->>>>>>>>>>>>>> Electronotes: CV selects which bits to set to 1 = chance of change
      // TESTED/WORKING!
      if (!(GPIOB->IDR & 0x0400)){
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out -
      probh=ADCBuffer[2]>>13; // 3 bits now for electroprob array
      probh=electroprob[probh];

      if (((probh | shift_registerl) & 0xff ) == 0xff) shift_registerh = (shift_registerh<<1) + ((shift_registerl>>31) & 0x01); // new bits enter from shiftregleft - 0xff was looker[7]
      else shift_registerh = (shift_registerh<<1) + bith;

	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      }
      
      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;
      
    case 55: // was 53
      // - after case 25 - SR loops within SR at certain points?/sizes determined by CV or pulses in = basic SR of OR with incoming bits
      // change and Re_test this - TESTED/working
      // loop bith back in XOR at certain point?
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
      shift_registerh = (shift_registerh<<1);
      // do the loop back in
      hcount=ADCBuffer[2]>>11; // 5 bits - or: hcount=(ADCBuffer[2]>>11)%(31+1);
      if (bith) shift_registerh ^= (1<<hcount);// set the xth bit
      shift_registerh ^= (!(GPIOB->IDR & 0x0400));
	
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
      
      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;

    case 56: // - TEST CASE FOR new ADC/DAC modes...
	  //this version works fine and we could also use 0x0400 to choose recycle or not
      //->>>>>>>>>>>>>> NEW mode TESTY: entry of ADC in from CV into upper bits?
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      // TESTY - put 4 bits in at 4 points and take out at 4 points 
      if (counter12h > 7){       // every 8 cycles
	counter12h=0;
	//	shift_registerh &= MASK[31]; // MASK is the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
	//	shift_registerh +=(ADCBuffer[2]>>8)<<(SHIFT[31]);  // tested and this makes sense on test.c
	shift_registerh +=(ADCBuffer[2]>>8);  // tested and this makes sense on test.c
	//	shift_registerh &=(ADCBuffer[2]>>8);
      }
      counter12h++;
      //      shift_registerh=(shift_registerh<<1) + (bith |  (!(GPIOB->IDR & 0x0400))); // cycle around and OR in pulse bit! TESTY! - or no recycle
      if (GPIOB->IDR & 0x0400) shift_registerh =  (shift_registerh<<1) + bith;
      else shift_registerh=(shift_registerh<<1);

      // divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	
      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;

    case 57: // - TEST CASE FOR new ADC/DAC modes...
      // shift in bits one by one use probh as storage

      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out
      counter12h++;
      if (counter12h > 7){       // every 8 cycles
	counter12h=0;
	// store the full bit or take successive bits
	probh=(ADCBuffer[2]>>8); // probh is 8 bits
	}
      
      //      shift_registerh=(shift_registerh<<1) + (bith |  (!(GPIOB->IDR & 0x0400))); // cycle around and OR in pulse bit! TESTY! - or no recycle
      //      if (GPIOB->IDR & 0x0400) shift_registerh =  (shift_registerh<<1) + bith;
      //      else shift_registerh=(shift_registerh<<1);

      // shift that new bit in (or this could depend on 0x400 for recycles
      if (GPIOB->IDR & 0x0400) shift_registerh =  (shift_registerh<<1) + bith;
      else shift_registerh=(shift_registerh<<1) + ((probh&bits[counter12h])>>counter12h);

      // divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	
      sph=8503-(shift_registerh&0x1FFF); // or we can use different ranges
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;
     
    case 58: // TEST CASE FOR new ADC/DAC modes...
      // put say 4 or 8 bits in at intervals - no recycle so far - works so far!
      // and DAC out is at later intervals
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      shift_registerh &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 4 bits in
      probh=(ADCBuffer[2]>>12); // 4 bits
      shift_registerh += ( (probh&0x01) + ((probh&0x02)<<7) + ((probh&0x04)<<14) + ((probh&0x08)<<21)); // would be 0 8-1 16-2 24-3


      shift_registerh=(shift_registerh<<1);// + bith;
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	
      sph= (((shift_registerh&(1<<7))>>7) + ((shift_registerh&(1<<15))>>14) + ((shift_registerh&(1<<23))>>21) + ((shift_registerh&(1<<31))>>28))<<6; // this one from test.c tested... so that is 4 bits <<4 to 10 bits = 1024 11 is 2048 12 is 4096

      // keeps it high!
      sph=1336-sph; // try 312+1024=1336- 312+2048=2360
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width	
      break;

    case 59: // TEST CASE FOR new ADC/DAC modes...
      // put say 4 or 8 bits in at intervals
      // ** cycle the SR
      // and DAC out is at later intervals
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      shift_registerh &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 4 bits in
      probh=(ADCBuffer[2]>>12); // 4 bits
      shift_registerh += ( ((probh&0x01)^bith) + ((probh&0x02)<<7) + ((probh&0x04)<<14) + ((probh&0x08)<<21)); // would be 0 8-1 16-2 24-3
      shift_registerh=(shift_registerh<<1);// + bith; // can be with or without extra incoming bit

      // divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	
      sph= (((shift_registerh&(1<<7))>>7) + ((shift_registerh&(1<<15))>>14) + ((shift_registerh&(1<<23))>>21) + ((shift_registerh&(1<<31))>>28))<<7; // this one from test.c tested...
      sph=2360-sph; // try 312+1024=1336- 312+2048=2360
      //      sph+=312;
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;

    case 60: // TEST CASE FOR new ADC/DAC modes...
      // put say 4 or 8 bits in at intervals
      // ** SR with incoming bit
      // and DAC out is at later intervals
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      shift_registerh &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 4 bits in
      probh=(ADCBuffer[2]>>12); // 4 bits
      shift_registerh += ( ((probh&0x01)^(!(GPIOB->IDR & 0x0400))) + ((probh&0x02)<<7) + ((probh&0x04)<<14) + ((probh&0x08)<<21)); // would be 0 8-1 16-2 24-3

      shift_registerh=(shift_registerh<<1);// + bith; // can be with or without extra incoming bit
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	
	  // no extract those 4 bits from the last slots bits 32, 24, 16 and 8, shift these and then << say 4 bits
	  //	  sph= (((shift_registerh&(1<<8))>>8) + ((shift_registerh&(1<<16))>>15) + ((shift_registerh&(1<<24))>>22) + ((shift_registerh&(1<<32))>>29))<<4;
      sph= (((shift_registerh&(1<<7))>>7) + ((shift_registerh&(1<<15))>>14) + ((shift_registerh&(1<<23))>>21) + ((shift_registerh&(1<<31))>>28))<<7; // this one from test.c tested...
      sph=2360-sph;
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;
      
    case 61: // TEST CASE FOR new ADC/DAC modes...      
      // let's try for 8 bits
      // check logic of this one after 3 bit shifts in test.c -> tested with one mistake fixed
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      // try for 8 bits in at 3 bits intervals
      shift_registerh &= 0b11101110111011101110111011101110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 8 bits in
      probh=(ADCBuffer[2]>>8); // 8 bits
      shift_registerh += (  ((probh&0x01)) + ((probh&0x02)<<3) + ((probh&0x04)<<6) + ((probh&0x08)<<9) + ((probh&0x10)<<12) + ((probh&0x20)<<15) + ((probh&0x40)<<18) + ((probh&0x80)<<21) );

      shift_registerh=(shift_registerh<<1);// + bith; // can be with or without extra incoming bit

      // divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

      sph= (((shift_registerh&(1<<3))>>3) + ((shift_registerh&(1<<7))>>6) + ((shift_registerh&(1<<11))>>9) + ((shift_registerh&(1<<15))>>12) + ((shift_registerh&(1<<19))>>15) +((shift_registerh&(1<<23))>>18) +((shift_registerh&(1<<27))>>21) +((shift_registerh&(1<<31))>>24))<<4; // this one from test.c tested...
      sph=4408-sph; // 12 bits=4096+312=4408
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;

    case 62: // TEST CASE FOR new ADC/DAC modes...
      // try and use incoming bit to shift 4 bits in hstack - working now
	hcount++;
      // but can go over - max we want now is 27
	if (hcount>27) hcount=0;
	if( !(GPIOB->IDR & 0x0400)) {
	  hstack[3]=hstack[2];
	  hstack[2]=hstack[1];
	  hstack[1]=hstack[0];
	  hstack[0]=hcount+1; // bump it on to the hstack
	}	  
      
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      // we need a new mask
      //      shift_registerh &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      shift_registerh &= ~ (((0x01)<< hstack[0]) + ((0x02)<<hstack[1]) + ((0x04)<<hstack[2]) + ((0x08)<<hstack[3]));
      // put the 4 bits in
      probh=(ADCBuffer[2]>>12); // 4 bits
      shift_registerh += ( ((probh&0x01)<< hstack[0]) + ((probh&0x02)<<hstack[1]) + ((probh&0x04)<<hstack[2]) + ((probh&0x08)<<hstack[3])); // would be 0 8-1 16-2 24-3

      shift_registerh=(shift_registerh<<1) + bith; // leave this as bith

      // divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	
	
      sph= (((shift_registerh&(1<<7))>>7) + ((shift_registerh&(1<<15))>>14) + ((shift_registerh&(1<<23))>>21) + ((shift_registerh&(1<<31))>>28))<<7; // this one from test.c tested...
      sph=2360-sph;
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;

    case 63: // TEST CASE FOR new ADC/DAC modes...
	    // try and use incoming bit to shift 4 bits in hstack - working now
	    // same as above but now we do for the output bits - maybe not so interesting as just effects the DAC! seems oks!
	hcount++;

	if (hcount>28) hcount=0;
	if( !(GPIOB->IDR & 0x0400)) {
	  hstack[3]=hstack[2];
	  hstack[2]=hstack[1];
	  hstack[1]=hstack[0];
	  hstack[0]=hcount+1; // bump it on to the hstack
	}	  
      
      bith = (shift_registerh>>31) & 0x01; // bit which would be shifted out

      // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
      shift_registerh &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
      // put the 4 bits in
      probh=(ADCBuffer[2]>>12); // 4 bits
      //      shift_registerh += ( ((probh&0x01)<< hstack[0]) + ((probh&0x02)<<hstack[1]) + ((probh&0x04)<<hstack[2]) + ((probh&0x08)<<hstack[3])); // would be 0 8-1 16-2 24-3
      shift_registerh += ( ((probh&0x01)) + ((probh&0x02)<<7) + ((probh&0x04)<<14) + ((probh&0x08)<<21)); // would be 0 8-1 16-2 24-3

      shift_registerh=(shift_registerh<<1) + bith;
	// divide down
	new_stath=(shift_registerh & (1<<15))>>15; // so that is not just a simple divide down
	if (prev_stath==0 && new_stath==1) flipdh^=1;
	prev_stath=new_stath;	
	if (flipdh) GPIOC->BRR = 0b0010000000000000;  
	else GPIOC->BSRR = 0b0010000000000000;

	if (bith) GPIOC->BRR = 0b0100000000000000;   // this is top one!
	else GPIOC->BSRR = 0b0100000000000000;	

      sph= ( (shift_registerh&(1<<hstack[0])) + (shift_registerh&(1<<hstack[1])) + (shift_registerh&(1<<hstack[2])) + (shift_registerh&(1<<hstack[3])) ); // this one from test.c tested... - or we space out a bit
      sph+=312;
      TIM1->ARR =sph;
      TIM1->CCR1 = sph/2; // pulse width
      break;
    }       /// end of HF modes
  }  
}
