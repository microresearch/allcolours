EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BD18BA3
P 2050 2200
AR Path="/5BD18BA3" Ref="C?"  Part="1" 
AR Path="/5BD09509/5BD18BA3" Ref="C19"  Part="1" 
F 0 "C19" H 2075 2300 50  0000 L CNN
F 1 "1N" H 2075 2100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2088 2050 50  0001 C CNN
F 3 "" H 2050 2200 50  0000 C CNN
	1    2050 2200
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BD18BAA
P 2900 1950
AR Path="/5BD18BAA" Ref="C?"  Part="1" 
AR Path="/5BD09509/5BD18BAA" Ref="C20"  Part="1" 
F 0 "C20" H 2925 2050 50  0000 L CNN
F 1 "100N" H 2750 1850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2938 1800 50  0001 C CNN
F 3 "" H 2900 1950 50  0000 C CNN
	1    2900 1950
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BD18BB1
P 3100 1950
AR Path="/5BD18BB1" Ref="C?"  Part="1" 
AR Path="/5BD09509/5BD18BB1" Ref="C21"  Part="1" 
F 0 "C21" H 3125 2050 50  0000 L CNN
F 1 "100N" H 2850 1850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3138 1800 50  0001 C CNN
F 3 "" H 3100 1950 50  0000 C CNN
	1    3100 1950
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD18BB8
P 3000 2100
AR Path="/5BD18BB8" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD18BB8" Ref="#PWR036"  Part="1" 
F 0 "#PWR036" H 3000 1850 50  0001 C CNN
F 1 "GND" H 3000 1950 50  0000 C CNN
F 2 "" H 3000 2100 50  0000 C CNN
F 3 "" H 3000 2100 50  0000 C CNN
	1    3000 2100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD18BBE
P 2600 2450
AR Path="/5BD18BBE" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD18BBE" Ref="#PWR035"  Part="1" 
F 0 "#PWR035" H 2600 2200 50  0001 C CNN
F 1 "GND" H 2600 2300 50  0000 C CNN
F 2 "" H 2600 2450 50  0000 C CNN
F 3 "" H 2600 2450 50  0000 C CNN
	1    2600 2450
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BD18BC4
P 2250 2050
AR Path="/5BD18BC4" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD18BC4" Ref="R14"  Part="1" 
F 0 "R14" V 2330 2050 50  0000 C CNN
F 1 "1M" V 2250 2050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2180 2050 50  0001 C CNN
F 3 "" H 2250 2050 50  0000 C CNN
	1    2250 2050
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BD18BCB
P 2600 1400
AR Path="/5BD18BCB" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD18BCB" Ref="R15"  Part="1" 
F 0 "R15" V 2680 1400 50  0000 C CNN
F 1 "33K" V 2600 1400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2530 1400 50  0001 C CNN
F 3 "" H 2600 1400 50  0000 C CNN
	1    2600 1400
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BD18BD2
P 2600 1800
AR Path="/5BD18BD2" Ref="D?"  Part="1" 
AR Path="/5BD09509/5BD18BD2" Ref="D13"  Part="1" 
F 0 "D13" H 2600 1700 50  0000 C CNN
F 1 "1n4148" H 2600 1950 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 2600 1800 50  0001 C CNN
F 3 "" H 2600 1800 50  0001 C CNN
	1    2600 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2600 1550 2600 1600
Wire Wire Line
	2600 1950 2600 2000
Wire Wire Line
	2200 2200 2250 2200
Wire Wire Line
	2300 2200 2250 2200
Connection ~ 2250 2200
Wire Wire Line
	1750 2200 1900 2200
Wire Wire Line
	2600 1600 3100 1600
Wire Wire Line
	3100 1600 3100 1800
Connection ~ 2600 1600
Wire Wire Line
	2600 1600 2600 1650
Wire Wire Line
	2600 1950 2750 1950
Wire Wire Line
	2750 1950 2750 1800
Wire Wire Line
	2750 1800 2900 1800
Connection ~ 2600 1950
Wire Wire Line
	2900 2100 3000 2100
Wire Wire Line
	3000 2100 3100 2100
Connection ~ 3000 2100
Wire Wire Line
	2600 2450 2600 2400
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD18BEE
P 2250 1800
AR Path="/5BD18BEE" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD18BEE" Ref="#PWR034"  Part="1" 
F 0 "#PWR034" H 2250 1650 50  0001 C CNN
F 1 "+12V" H 2250 1940 50  0000 C CNN
F 2 "" H 2250 1800 50  0000 C CNN
F 3 "" H 2250 1800 50  0000 C CNN
	1    2250 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1900 2250 1800
Wire Wire Line
	3100 1600 3350 1600
Connection ~ 3100 1600
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD18BF9
P 2500 2200
AR Path="/5BD18BF9" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD18BF9" Ref="Q15"  Part="1" 
F 0 "Q15" H 2691 2246 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2691 2155 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2700 2300 50  0001 C CNN
F 3 "" H 2500 2200 50  0001 C CNN
	1    2500 2200
	1    0    0    -1  
$EndComp
Text Notes 2900 1350 0    60   ~ 0
envelope\n
Text Notes 5215 925  0    197  ~ 0
logic xor
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD11FA8
P 7550 2710
AR Path="/5BD11FA8" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD11FA8" Ref="Q23"  Part="1" 
F 0 "Q23" H 7741 2756 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7741 2665 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7750 2810 50  0001 C CNN
F 3 "" H 7550 2710 50  0001 C CNN
	1    7550 2710
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD11FAE
P 7550 3285
AR Path="/5BD11FAE" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD11FAE" Ref="Q24"  Part="1" 
F 0 "Q24" H 7741 3331 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7741 3240 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7750 3385 50  0001 C CNN
F 3 "" H 7550 3285 50  0001 C CNN
	1    7550 3285
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD12CDF
P 7200 2710
AR Path="/5AD5ACBB/5BD12CDF" Ref="R?"  Part="1" 
AR Path="/5BD12CDF" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD12CDF" Ref="R31"  Part="1" 
F 0 "R31" V 7004 2710 50  0000 C CNN
F 1 "10K" V 7095 2710 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7200 2710 50  0001 C CNN
F 3 "" H 7200 2710 50  0001 C CNN
	1    7200 2710
	0    1    -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD12DB7
P 7200 3285
AR Path="/5AD5ACBB/5BD12DB7" Ref="R?"  Part="1" 
AR Path="/5BD12DB7" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD12DB7" Ref="R32"  Part="1" 
F 0 "R32" V 7004 3285 50  0000 C CNN
F 1 "10K" V 7095 3285 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7200 3285 50  0001 C CNN
F 3 "" H 7200 3285 50  0001 C CNN
	1    7200 3285
	0    1    -1   0   
$EndComp
Wire Wire Line
	7300 2710 7350 2710
Wire Wire Line
	7300 3285 7350 3285
Wire Wire Line
	7650 2910 7650 3085
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD14C85
P 7650 2385
AR Path="/5AD5ACBB/5BD14C85" Ref="#PWR?"  Part="1" 
AR Path="/5BD14C85" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD14C85" Ref="#PWR052"  Part="1" 
F 0 "#PWR052" H 7650 2235 50  0001 C CNN
F 1 "+12V" H 7665 2558 50  0000 C CNN
F 2 "" H 7650 2385 50  0001 C CNN
F 3 "" H 7650 2385 50  0001 C CNN
	1    7650 2385
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD14CD5
P 7650 3810
AR Path="/5AD5ACBB/5BD14CD5" Ref="#PWR?"  Part="1" 
AR Path="/5BD14CD5" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD14CD5" Ref="#PWR053"  Part="1" 
F 0 "#PWR053" H 7650 3560 50  0001 C CNN
F 1 "GND" H 7655 3637 50  0000 C CNN
F 2 "" H 7650 3810 50  0001 C CNN
F 3 "" H 7650 3810 50  0001 C CNN
	1    7650 3810
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD15856
P 6200 3660
AR Path="/5BD15856" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD15856" Ref="Q21"  Part="1" 
F 0 "Q21" H 6391 3706 50  0000 L CNN
F 1 "Q_NPN_BEC" H 6391 3615 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 6400 3760 50  0001 C CNN
F 3 "" H 6200 3660 50  0001 C CNN
	1    6200 3660
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD1585C
P 6200 4235
AR Path="/5BD1585C" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD1585C" Ref="Q22"  Part="1" 
F 0 "Q22" H 6391 4281 50  0000 L CNN
F 1 "Q_NPN_BEC" H 6391 4190 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 6400 4335 50  0001 C CNN
F 3 "" H 6200 4235 50  0001 C CNN
	1    6200 4235
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD15862
P 5850 3660
AR Path="/5AD5ACBB/5BD15862" Ref="R?"  Part="1" 
AR Path="/5BD15862" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD15862" Ref="R27"  Part="1" 
F 0 "R27" V 5654 3660 50  0000 C CNN
F 1 "10K" V 5745 3660 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5850 3660 50  0001 C CNN
F 3 "" H 5850 3660 50  0001 C CNN
	1    5850 3660
	0    1    -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD15868
P 5850 4235
AR Path="/5AD5ACBB/5BD15868" Ref="R?"  Part="1" 
AR Path="/5BD15868" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD15868" Ref="R28"  Part="1" 
F 0 "R28" V 5654 4235 50  0000 C CNN
F 1 "10K" V 5745 4235 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5850 4235 50  0001 C CNN
F 3 "" H 5850 4235 50  0001 C CNN
	1    5850 4235
	0    1    -1   0   
$EndComp
Wire Wire Line
	5950 3660 6000 3660
Wire Wire Line
	5950 4235 6000 4235
Wire Wire Line
	6300 3860 6300 4035
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD15871
P 6300 3160
AR Path="/5AD5ACBB/5BD15871" Ref="#PWR?"  Part="1" 
AR Path="/5BD15871" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD15871" Ref="#PWR050"  Part="1" 
F 0 "#PWR050" H 6300 3010 50  0001 C CNN
F 1 "+12V" H 6425 3210 50  0000 C CNN
F 2 "" H 6300 3160 50  0001 C CNN
F 3 "" H 6300 3160 50  0001 C CNN
	1    6300 3160
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD160A5
P 6175 1685
AR Path="/5BD160A5" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD160A5" Ref="Q19"  Part="1" 
F 0 "Q19" H 6366 1731 50  0000 L CNN
F 1 "Q_NPN_BEC" H 6366 1640 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 6375 1785 50  0001 C CNN
F 3 "" H 6175 1685 50  0001 C CNN
	1    6175 1685
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD160AB
P 6175 2260
AR Path="/5BD160AB" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD160AB" Ref="Q20"  Part="1" 
F 0 "Q20" H 6366 2306 50  0000 L CNN
F 1 "Q_NPN_BEC" H 6366 2215 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 6375 2360 50  0001 C CNN
F 3 "" H 6175 2260 50  0001 C CNN
	1    6175 2260
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD160B1
P 5825 1685
AR Path="/5AD5ACBB/5BD160B1" Ref="R?"  Part="1" 
AR Path="/5BD160B1" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD160B1" Ref="R25"  Part="1" 
F 0 "R25" V 5629 1685 50  0000 C CNN
F 1 "10K" V 5720 1685 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5825 1685 50  0001 C CNN
F 3 "" H 5825 1685 50  0001 C CNN
	1    5825 1685
	0    1    -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD160B7
P 5825 2260
AR Path="/5AD5ACBB/5BD160B7" Ref="R?"  Part="1" 
AR Path="/5BD160B7" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD160B7" Ref="R26"  Part="1" 
F 0 "R26" V 5629 2260 50  0000 C CNN
F 1 "10K" V 5720 2260 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5825 2260 50  0001 C CNN
F 3 "" H 5825 2260 50  0001 C CNN
	1    5825 2260
	0    1    -1   0   
$EndComp
Wire Wire Line
	5925 1685 5975 1685
Wire Wire Line
	5925 2260 5975 2260
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD160C0
P 6275 1360
AR Path="/5AD5ACBB/5BD160C0" Ref="#PWR?"  Part="1" 
AR Path="/5BD160C0" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD160C0" Ref="#PWR048"  Part="1" 
F 0 "#PWR048" H 6275 1210 50  0001 C CNN
F 1 "+12V" H 6290 1533 50  0000 C CNN
F 2 "" H 6275 1360 50  0001 C CNN
F 3 "" H 6275 1360 50  0001 C CNN
	1    6275 1360
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD17170
P 6275 2635
AR Path="/5AD5ACBB/5BD17170" Ref="R?"  Part="1" 
AR Path="/5BD17170" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD17170" Ref="R29"  Part="1" 
F 0 "R29" V 6079 2635 50  0000 C CNN
F 1 "1K" V 6170 2635 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6275 2635 50  0001 C CNN
F 3 "" H 6275 2635 50  0001 C CNN
	1    6275 2635
	1    0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD17339
P 6300 4535
AR Path="/5AD5ACBB/5BD17339" Ref="#PWR?"  Part="1" 
AR Path="/5BD17339" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD17339" Ref="#PWR051"  Part="1" 
F 0 "#PWR051" H 6300 4285 50  0001 C CNN
F 1 "GND" H 6305 4362 50  0000 C CNN
F 2 "" H 6300 4535 50  0001 C CNN
F 3 "" H 6300 4535 50  0001 C CNN
	1    6300 4535
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD17384
P 6275 2785
AR Path="/5AD5ACBB/5BD17384" Ref="#PWR?"  Part="1" 
AR Path="/5BD17384" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD17384" Ref="#PWR049"  Part="1" 
F 0 "#PWR049" H 6275 2535 50  0001 C CNN
F 1 "GND" H 6280 2612 50  0000 C CNN
F 2 "" H 6275 2785 50  0001 C CNN
F 3 "" H 6275 2785 50  0001 C CNN
	1    6275 2785
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD173EF
P 7650 3635
AR Path="/5AD5ACBB/5BD173EF" Ref="R?"  Part="1" 
AR Path="/5BD173EF" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD173EF" Ref="R33"  Part="1" 
F 0 "R33" V 7454 3635 50  0000 C CNN
F 1 "1K" V 7545 3635 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7650 3635 50  0001 C CNN
F 3 "" H 7650 3635 50  0001 C CNN
	1    7650 3635
	1    0    0    1   
$EndComp
Wire Wire Line
	7650 3485 7650 3535
Wire Wire Line
	7650 3735 7650 3810
Wire Wire Line
	6275 2460 6275 2485
Wire Wire Line
	6275 2735 6275 2785
Wire Wire Line
	6300 4435 6300 4535
Wire Wire Line
	7650 2385 7650 2510
Wire Wire Line
	6275 1360 6275 1435
Wire Wire Line
	6275 2485 6850 2485
Wire Wire Line
	7100 2485 7100 2710
Connection ~ 6275 2485
Wire Wire Line
	6275 2485 6275 2535
Wire Wire Line
	6450 1435 6450 2060
Wire Wire Line
	6275 1885 6850 1885
Wire Wire Line
	6850 1885 6850 2485
Connection ~ 6850 2485
Wire Wire Line
	6850 2485 7100 2485
Wire Wire Line
	5725 2260 5550 2260
Wire Wire Line
	5550 2260 5550 4235
Wire Wire Line
	5550 4235 5750 4235
Wire Wire Line
	5700 1685 5700 3660
Wire Wire Line
	5700 3660 5750 3660
Wire Wire Line
	5700 1685 5725 1685
Wire Wire Line
	5700 3660 5275 3660
Connection ~ 5700 3660
Wire Wire Line
	5550 4235 5275 4235
Connection ~ 5550 4235
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD25B50
P 6300 3310
AR Path="/5AD5ACBB/5BD25B50" Ref="R?"  Part="1" 
AR Path="/5BD25B50" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD25B50" Ref="R30"  Part="1" 
F 0 "R30" V 6104 3310 50  0000 C CNN
F 1 "1K" V 6195 3310 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6300 3310 50  0001 C CNN
F 3 "" H 6300 3310 50  0001 C CNN
	1    6300 3310
	1    0    0    1   
$EndComp
Wire Wire Line
	6300 3160 6300 3210
Wire Wire Line
	6300 3410 6300 3435
Wire Wire Line
	6300 3435 7100 3435
Wire Wire Line
	7100 3435 7100 3285
Connection ~ 6300 3435
Wire Wire Line
	6300 3435 6300 3460
Wire Wire Line
	7650 3535 7925 3535
Connection ~ 7650 3535
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BD2B236
P 8125 3535
AR Path="/5AD5ACBB/5BD2B236" Ref="J?"  Part="1" 
AR Path="/5BD2B236" Ref="J?"  Part="1" 
AR Path="/5BD09509/5BD2B236" Ref="J17"  Part="1" 
F 0 "J17" H 8045 3310 50  0000 C CNN
F 1 "XOR OUT" H 8045 3401 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 8125 3535 50  0001 C CNN
F 3 "~" H 8125 3535 50  0001 C CNN
	1    8125 3535
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BD2B3EA
P 5075 3660
AR Path="/5AD5ACBB/5BD2B3EA" Ref="J?"  Part="1" 
AR Path="/5BD2B3EA" Ref="J?"  Part="1" 
AR Path="/5BD09509/5BD2B3EA" Ref="J15"  Part="1" 
F 0 "J15" H 4995 3435 50  0000 C CNN
F 1 "XOR IN" H 4995 3526 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5075 3660 50  0001 C CNN
F 3 "~" H 5075 3660 50  0001 C CNN
	1    5075 3660
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BD2B4A8
P 5075 4235
AR Path="/5AD5ACBB/5BD2B4A8" Ref="J?"  Part="1" 
AR Path="/5BD2B4A8" Ref="J?"  Part="1" 
AR Path="/5BD09509/5BD2B4A8" Ref="J16"  Part="1" 
F 0 "J16" H 4995 4010 50  0000 C CNN
F 1 "XOR IN" H 4995 4101 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5075 4235 50  0001 C CNN
F 3 "~" H 5075 4235 50  0001 C CNN
	1    5075 4235
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C157F1D
P 1550 2200
AR Path="/5AD5ACBB/5C157F1D" Ref="J?"  Part="1" 
AR Path="/5C157F1D" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C157F1D" Ref="J55"  Part="1" 
F 0 "J55" H 1470 1975 50  0000 C CNN
F 1 "ENV SIG" H 1470 2066 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1550 2200 50  0001 C CNN
F 3 "~" H 1550 2200 50  0001 C CNN
	1    1550 2200
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C15816D
P 2350 1250
AR Path="/5AD5ACBB/5C15816D" Ref="J?"  Part="1" 
AR Path="/5C15816D" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C15816D" Ref="J56"  Part="1" 
F 0 "J56" H 2270 1025 50  0000 C CNN
F 1 "ENV IN" H 2270 1116 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2350 1250 50  0001 C CNN
F 3 "~" H 2350 1250 50  0001 C CNN
	1    2350 1250
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C15828C
P 3550 1600
AR Path="/5AD5ACBB/5C15828C" Ref="J?"  Part="1" 
AR Path="/5C15828C" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C15828C" Ref="J57"  Part="1" 
F 0 "J57" H 3470 1375 50  0000 C CNN
F 1 "ENV OUT" H 3470 1466 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3550 1600 50  0001 C CNN
F 3 "~" H 3550 1600 50  0001 C CNN
	1    3550 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1250 2600 1250
Wire Wire Line
	6275 2060 6450 2060
Wire Wire Line
	6275 1435 6450 1435
Connection ~ 6275 1435
Wire Wire Line
	6275 1435 6275 1485
$EndSCHEMATC
