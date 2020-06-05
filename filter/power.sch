EESchema Schematic File Version 4
LIBS:filter-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3225 2225 0    60   ~ 0
euro_conn
$Comp
L allcolours_analogue-rescue:CONN_02X05-allcolours-rescue P1
U 1 1 5C3AA485
P 3425 2575
F 0 "P1" H 3425 2875 50  0000 C CNN
F 1 "CONN_02X05" H 3425 2275 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05_Pitch2.54mm" H 3425 1375 50  0001 C CNN
F 3 "" H 3425 1375 50  0000 C CNN
	1    3425 2575
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR039
U 1 1 5C3AA48C
P 2670 2265
F 0 "#PWR039" H 2670 2115 50  0001 C CNN
F 1 "+12V" H 2670 2390 50  0000 C CNN
F 2 "" H 2670 2265 50  0000 C CNN
F 3 "" H 2670 2265 50  0000 C CNN
	1    2670 2265
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR040
U 1 1 5C3AA492
P 3875 2575
F 0 "#PWR040" H 3875 2325 50  0001 C CNN
F 1 "GND" H 3875 2425 50  0000 C CNN
F 2 "" H 3875 2575 50  0000 C CNN
F 3 "" H 3875 2575 50  0000 C CNN
	1    3875 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	3175 2575 3675 2575
Wire Wire Line
	3675 2475 3675 2575
Connection ~ 3675 2575
Wire Wire Line
	3175 2375 3675 2375
Wire Wire Line
	3175 2325 3175 2375
Connection ~ 3175 2775
Wire Wire Line
	3675 2575 3675 2675
Wire Wire Line
	3175 2775 3675 2775
Connection ~ 3175 2375
$Comp
L power:-12V #PWR038
U 1 1 5C3AA4A4
P 2590 2810
F 0 "#PWR038" H 2590 2910 50  0001 C CNN
F 1 "-12V" H 2605 2983 50  0000 C CNN
F 2 "" H 2590 2810 50  0001 C CNN
F 3 "" H 2590 2810 50  0001 C CNN
	1    2590 2810
	-1   0    0    1   
$EndComp
Wire Wire Line
	3675 2575 3875 2575
$Comp
L allcolours_analogue-rescue:CP1_Small-device C23
U 1 1 5C3AA4AB
P 2600 2450
F 0 "C23" H 2610 2520 50  0000 L CNN
F 1 "10u" H 2610 2370 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 2600 2450 50  0001 C CNN
F 3 "" H 2600 2450 50  0000 C CNN
	1    2600 2450
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:CP1_Small-device C22
U 1 1 5C3AA4B4
P 3050 2800
F 0 "C22" H 3060 2870 50  0000 L CNN
F 1 "10u" H 3060 2720 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 3050 2800 50  0001 C CNN
F 3 "" H 3050 2800 50  0000 C CNN
	1    3050 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:D D3
U 1 1 5C3AA4BD
P 2820 2325
F 0 "D3" H 2820 2541 50  0000 C CNN
F 1 "1N5158" H 2820 2450 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-123" H 2820 2325 50  0001 C CNN
F 3 "~" H 2820 2325 50  0001 C CNN
	1    2820 2325
	1    0    0    -1  
$EndComp
Wire Wire Line
	2670 2265 2670 2290
$Comp
L Device:D D2
U 1 1 5C3AA4C8
P 2740 2775
F 0 "D2" H 2740 2559 50  0000 C CNN
F 1 "1N5158" H 2740 2650 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-123" H 2740 2775 50  0001 C CNN
F 3 "~" H 2740 2775 50  0001 C CNN
	1    2740 2775
	-1   0    0    1   
$EndComp
Wire Wire Line
	2590 2775 2590 2800
Wire Wire Line
	2600 2350 2600 2290
Wire Wire Line
	2600 2290 2670 2290
Wire Wire Line
	2970 2325 3175 2325
Wire Wire Line
	2890 2775 3175 2775
Connection ~ 2670 2290
Wire Wire Line
	2670 2290 2670 2325
Wire Wire Line
	2600 2550 2600 2580
Wire Wire Line
	2600 2580 3050 2580
Wire Wire Line
	3050 2900 2660 2900
Wire Wire Line
	2660 2900 2660 2800
Wire Wire Line
	2660 2800 2590 2800
Connection ~ 2590 2800
Wire Wire Line
	2590 2800 2590 2810
Wire Wire Line
	3175 2475 3175 2575
Wire Wire Line
	3175 2575 3050 2575
Wire Wire Line
	3050 2575 3050 2580
Connection ~ 3175 2575
Wire Wire Line
	3175 2575 3175 2675
Connection ~ 3050 2580
Wire Wire Line
	3050 2580 3050 2700
$EndSCHEMATC
