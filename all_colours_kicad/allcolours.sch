EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 900  2100 0    60   ~ 0
bc547c cbe
Text Notes 850  850  0    60   ~ 0
yusynth noise source x2
$Comp
L allcolours-rescue:CP1_Small-device C4
U 1 1 59679B9B
P 1650 1600
F 0 "C4" H 1660 1670 50  0000 L CNN
F 1 "47u" H 1660 1520 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 1650 1600 50  0001 C CNN
F 3 "" H 1650 1600 50  0000 C CNN
	1    1650 1600
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR02
U 1 1 59679C7C
P 1650 2100
F 0 "#PWR02" H 1650 1850 50  0001 C CNN
F 1 "GND" H 1650 1950 50  0000 C CNN
F 2 "" H 1650 2100 50  0000 C CNN
F 3 "" H 1650 2100 50  0000 C CNN
	1    1650 2100
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R1
U 1 1 59679C98
P 1450 1200
F 0 "R1" V 1530 1200 50  0000 C CNN
F 1 "47K" V 1450 1200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1380 1200 50  0001 C CNN
F 3 "" H 1450 1200 50  0000 C CNN
	1    1450 1200
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R5
U 1 1 59679D11
P 2100 850
F 0 "R5" V 2180 850 50  0000 C CNN
F 1 "22R" V 2100 850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2030 850 50  0001 C CNN
F 3 "" H 2100 850 50  0000 C CNN
	1    2100 850 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R6
U 1 1 5967A041
P 2100 1200
F 0 "R6" V 2180 1200 50  0000 C CNN
F 1 "10K" V 2100 1200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2030 1200 50  0001 C CNN
F 3 "" H 2100 1200 50  0000 C CNN
	1    2100 1200
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R2
U 1 1 5967A047
P 1800 1350
F 0 "R2" V 1880 1350 50  0000 C CNN
F 1 "150K" V 1800 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1730 1350 50  0001 C CNN
F 3 "" H 1800 1350 50  0000 C CNN
	1    1800 1350
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:CP1_Small-device C1
U 1 1 5967A107
P 950 1150
F 0 "C1" H 960 1220 50  0000 L CNN
F 1 "47u" H 960 1070 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 950 1150 50  0001 C CNN
F 3 "" H 950 1150 50  0000 C CNN
	1    950  1150
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR01
U 1 1 5967A401
P 950 1350
F 0 "#PWR01" H 950 1100 50  0001 C CNN
F 1 "GND" H 950 1200 50  0000 C CNN
F 2 "" H 950 1350 50  0000 C CNN
F 3 "" H 950 1350 50  0000 C CNN
	1    950  1350
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR04
U 1 1 5967A89B
P 2250 700
F 0 "#PWR04" H 2250 550 50  0001 C CNN
F 1 "+12V" H 2250 840 50  0000 C CNN
F 2 "" H 2250 700 50  0000 C CNN
F 3 "" H 2250 700 50  0000 C CNN
	1    2250 700 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R11
U 1 1 5967CC22
P 2700 1450
F 0 "R11" V 2780 1450 50  0000 C CNN
F 1 "33k" V 2700 1450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2630 1450 50  0001 C CNN
F 3 "" H 2700 1450 50  0000 C CNN
	1    2700 1450
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:CP1_Small-device C5
U 1 1 5967E5DC
P 2400 1450
F 0 "C5" H 2410 1520 50  0000 L CNN
F 1 "10u" H 2410 1370 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 2400 1450 50  0001 C CNN
F 3 "" H 2400 1450 50  0000 C CNN
	1    2400 1450
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR09
U 1 1 5967EA5F
P 2800 1250
F 0 "#PWR09" H 2800 1000 50  0001 C CNN
F 1 "GND" H 2800 1100 50  0000 C CNN
F 2 "" H 2800 1250 50  0000 C CNN
F 3 "" H 2800 1250 50  0000 C CNN
	1    2800 1250
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR013
U 1 1 5967EB4D
P 3200 1000
F 0 "#PWR013" H 3200 850 50  0001 C CNN
F 1 "+12V" H 3200 1140 50  0000 C CNN
F 2 "" H 3200 1000 50  0000 C CNN
F 3 "" H 3200 1000 50  0000 C CNN
	1    3200 1000
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR014
U 1 1 5967F1D3
P 3200 1700
F 0 "#PWR014" H 3200 1550 50  0001 C CNN
F 1 "-12VA" H 3200 1840 50  0000 C CNN
F 2 "" H 3200 1700 50  0000 C CNN
F 3 "" H 3200 1700 50  0000 C CNN
	1    3200 1700
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device C6
U 1 1 596804D2
P 3500 950
F 0 "C6" H 3525 1050 50  0000 L CNN
F 1 "10p" H 3525 850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3538 800 50  0001 C CNN
F 3 "" H 3500 950 50  0000 C CNN
	1    3500 950 
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:7805 U9
U 1 1 5968B83B
P 9800 5025
F 0 "U9" H 9950 4829 50  0000 C CNN
F 1 "7805" H 9800 5225 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 9800 5025 50  0001 C CNN
F 3 "" H 9800 5025 50  0000 C CNN
	1    9800 5025
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR041
U 1 1 5968B92C
P 9200 4925
F 0 "#PWR041" H 9200 4775 50  0001 C CNN
F 1 "+12V" H 9200 5065 50  0000 C CNN
F 2 "" H 9200 4925 50  0000 C CNN
F 3 "" H 9200 4925 50  0000 C CNN
	1    9200 4925
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR045
U 1 1 5968B9D9
P 9800 5375
F 0 "#PWR045" H 9800 5125 50  0001 C CNN
F 1 "GND" H 9800 5225 50  0000 C CNN
F 2 "" H 9800 5375 50  0000 C CNN
F 3 "" H 9800 5375 50  0000 C CNN
	1    9800 5375
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:C-device C12
U 1 1 5968BE3D
P 9400 5125
F 0 "C12" H 9425 5225 50  0000 L CNN
F 1 "100N" H 9425 5025 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 9438 4975 50  0001 C CNN
F 3 "" H 9400 5125 50  0000 C CNN
	1    9400 5125
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:CP1_Small-device C13
U 1 1 5968BF2C
P 9400 5425
F 0 "C13" H 9410 5495 50  0000 L CNN
F 1 "10u" H 9410 5345 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 9400 5425 50  0001 C CNN
F 3 "" H 9400 5425 50  0000 C CNN
	1    9400 5425
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:C-device C15
U 1 1 5968C026
P 10250 5125
F 0 "C15" H 10275 5225 50  0000 L CNN
F 1 "100N" H 10275 5025 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 10288 4975 50  0001 C CNN
F 3 "" H 10250 5125 50  0000 C CNN
	1    10250 5125
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:CP1_Small-device C14
U 1 1 5968C101
P 10050 5325
F 0 "C14" H 10060 5395 50  0000 L CNN
F 1 "10u" H 10060 5245 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 10050 5325 50  0001 C CNN
F 3 "" H 10050 5325 50  0000 C CNN
	1    10050 5325
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:C-device C9
U 1 1 5968DE2C
P 600 1700
F 0 "C9" H 625 1800 50  0000 L CNN
F 1 "100N" H 625 1600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 638 1550 50  0001 C CNN
F 3 "" H 600 1700 50  0000 C CNN
	1    600  1700
	-1   0    0    1   
$EndComp
Text Notes 6000 600  0    60   ~ 0
finger comparator (tested) - for filter clock
Text Notes 7000 8700 0    60   ~ 0
OLDER:\n- 5v supply\n- 3x tr noise sources buffered and seperate power buses sep with res and decoupled\n- s/h and voltage controlled clocks - clock for 7400 and clocks for s/h\n- comparators -s/h also uses comparator\n- prototype areas + jumpers\n- 7400\n- in and out (buffers?)
$Comp
L allcolours-rescue:R-device R26
U 1 1 5967E495
P 5950 1100
F 0 "R26" V 6030 1100 50  0000 C CNN
F 1 "10K" V 5950 1100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5880 1100 50  0001 C CNN
F 3 "" H 5950 1100 50  0000 C CNN
	1    5950 1100
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device R24
U 1 1 5967E681
P 5700 1250
F 0 "R24" V 5780 1250 50  0000 C CNN
F 1 "100K" V 5700 1250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5630 1250 50  0001 C CNN
F 3 "" H 5700 1250 50  0000 C CNN
	1    5700 1250
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR024
U 1 1 5967EB3B
P 5700 1500
F 0 "#PWR024" H 5700 1250 50  0001 C CNN
F 1 "GND" H 5700 1350 50  0000 C CNN
F 2 "" H 5700 1500 50  0000 C CNN
F 3 "" H 5700 1500 50  0000 C CNN
	1    5700 1500
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R27
U 1 1 5967F385
P 5950 1950
F 0 "R27" V 6030 1950 50  0000 C CNN
F 1 "10K" V 5950 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5880 1950 50  0001 C CNN
F 3 "" H 5950 1950 50  0000 C CNN
	1    5950 1950
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device R28
U 1 1 5967F51F
P 6150 2100
F 0 "R28" V 6230 2100 50  0000 C CNN
F 1 "100K" V 6150 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6080 2100 50  0001 C CNN
F 3 "" H 6150 2100 50  0000 C CNN
	1    6150 2100
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR027
U 1 1 5967FDD2
P 6300 2150
F 0 "#PWR027" H 6300 2000 50  0001 C CNN
F 1 "+12V" H 6300 2290 50  0000 C CNN
F 2 "" H 6300 2150 50  0000 C CNN
F 3 "" H 6300 2150 50  0000 C CNN
	1    6300 2150
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR030
U 1 1 59680F55
P 6550 1550
F 0 "#PWR030" H 6550 1400 50  0001 C CNN
F 1 "-12VA" H 6550 1690 50  0000 C CNN
F 2 "" H 6550 1550 50  0000 C CNN
F 3 "" H 6550 1550 50  0000 C CNN
	1    6550 1550
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device R23
U 1 1 59682456
P 5600 1800
F 0 "R23" V 5680 1800 50  0000 C CNN
F 1 "10K" V 5600 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5530 1800 50  0001 C CNN
F 3 "" H 5600 1800 50  0000 C CNN
	1    5600 1800
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR029
U 1 1 59682D0C
P 6550 800
F 0 "#PWR029" H 6550 650 50  0001 C CNN
F 1 "+12V" H 6550 940 50  0000 C CNN
F 2 "" H 6550 800 50  0000 C CNN
F 3 "" H 6550 800 50  0000 C CNN
	1    6550 800 
	1    0    0    -1  
$EndComp
Text Notes 8150 4825 0    60   ~ 0
euro_conn
$Comp
L allcolours-rescue:CONN_02X05 P4
U 1 1 596B8735
P 8350 5175
F 0 "P4" H 8350 5475 50  0000 C CNN
F 1 "CONN_02X05" H 8350 4875 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05_Pitch2.54mm" H 8350 3975 50  0001 C CNN
F 3 "" H 8350 3975 50  0000 C CNN
	1    8350 5175
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR043
U 1 1 596B9C7E
P 7950 4925
F 0 "#PWR043" H 7950 4775 50  0001 C CNN
F 1 "+12V" H 7950 5065 50  0000 C CNN
F 2 "" H 7950 4925 50  0000 C CNN
F 3 "" H 7950 4925 50  0000 C CNN
	1    7950 4925
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR044
U 1 1 596BB6E9
P 8000 5425
F 0 "#PWR044" H 8000 5275 50  0001 C CNN
F 1 "-12VA" H 8000 5565 50  0000 C CNN
F 2 "" H 8000 5425 50  0000 C CNN
F 3 "" H 8000 5425 50  0000 C CNN
	1    8000 5425
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR047
U 1 1 596A64CD
P 8800 5175
F 0 "#PWR047" H 8800 4925 50  0001 C CNN
F 1 "GND" H 8800 5025 50  0000 C CNN
F 2 "" H 8800 5175 50  0000 C CNN
F 3 "" H 8800 5175 50  0000 C CNN
	1    8800 5175
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R21
U 1 1 596A1808
P 3850 1350
F 0 "R21" V 3930 1350 50  0000 C CNN
F 1 "1K" V 3850 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3780 1350 50  0001 C CNN
F 3 "" H 3850 1350 50  0000 C CNN
	1    3850 1350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1250 1900 1650 1900
Wire Wire Line
	1650 1900 1650 2100
Wire Wire Line
	2100 1900 2100 1800
Connection ~ 1650 1900
Wire Wire Line
	950  1050 1450 1050
Wire Wire Line
	950  1350 950  1250
Wire Wire Line
	1450 1350 1450 1600
Wire Wire Line
	1450 1600 1550 1600
Wire Wire Line
	1750 1600 1800 1600
Wire Wire Line
	1800 1600 1800 1500
Connection ~ 1450 1050
Wire Wire Line
	2100 1050 2100 1000
Wire Wire Line
	2100 1350 2100 1400
Wire Wire Line
	1800 1200 1950 1200
Wire Wire Line
	1950 1200 1950 1400
Wire Wire Line
	1950 1400 2100 1400
Wire Wire Line
	2100 700  2250 700 
Wire Wire Line
	2500 1450 2550 1450
Wire Wire Line
	2850 1450 2900 1450
Wire Wire Line
	2800 1250 3000 1250
Wire Wire Line
	3200 1050 3200 1000
Wire Wire Line
	3200 1650 3200 1700
Wire Wire Line
	2900 1450 2900 1150
Wire Wire Line
	2900 1150 3250 1150
Connection ~ 2900 1450
Wire Wire Line
	3250 1150 3250 950 
Wire Wire Line
	3250 950  3350 950 
Connection ~ 3250 1150
Wire Wire Line
	9200 4975 9250 4975
Wire Wire Line
	9200 4975 9200 4925
Wire Wire Line
	9800 5275 9800 5325
Wire Wire Line
	10200 4975 10400 4975
Wire Wire Line
	9250 4975 9250 5125
Connection ~ 9250 4975
Wire Wire Line
	9250 5425 9300 5425
Connection ~ 9250 5125
Wire Wire Line
	9550 5425 9500 5425
Wire Wire Line
	9550 5125 9550 5325
Wire Wire Line
	9550 5325 9800 5325
Connection ~ 9800 5325
Connection ~ 9550 5325
Wire Wire Line
	9900 5325 9900 5125
Wire Wire Line
	9900 5125 10100 5125
Connection ~ 9900 5325
Wire Wire Line
	10400 5325 10150 5325
Wire Wire Line
	10400 4975 10400 5125
Connection ~ 10400 5125
Wire Wire Line
	6550 1500 6550 1550
Wire Wire Line
	5700 1500 5700 1400
Wire Wire Line
	6100 1100 6150 1100
Connection ~ 5700 1100
Wire Wire Line
	5750 1800 5800 1800
Wire Wire Line
	5950 1800 5950 1300
Wire Wire Line
	5950 1300 6350 1300
Wire Wire Line
	5800 1950 5800 1800
Connection ~ 5800 1800
Wire Wire Line
	8100 5075 8100 5175
Connection ~ 8100 5175
Wire Wire Line
	8100 5175 8600 5175
Wire Wire Line
	8600 5075 8600 5175
Connection ~ 8600 5175
Wire Wire Line
	8100 4975 8600 4975
Wire Wire Line
	8000 5375 8100 5375
Wire Wire Line
	7950 4925 8100 4925
Wire Wire Line
	8100 4925 8100 4975
Wire Wire Line
	8000 5425 8000 5375
Connection ~ 8100 5375
Wire Wire Line
	2300 1450 2150 1450
Wire Wire Line
	2150 1450 2150 1350
Wire Wire Line
	2150 1350 2100 1350
Wire Wire Line
	6950 1200 7150 1200
Wire Wire Line
	4000 1350 4100 1350
Text Notes 5850 2150 0    60   ~ 0
10K?
$Comp
L allcolours-rescue:D-device D6
U 1 1 5A8DC0DA
P 7300 1200
F 0 "D6" H 7300 984 50  0000 C CNN
F 1 "1n914/4148" H 7300 1075 50  0000 C CNN
F 2 "" H 7300 1200 50  0001 C CNN
F 3 "" H 7300 1200 50  0001 C CNN
	1    7300 1200
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device R37
U 1 1 5A8DC4EE
P 7550 1350
F 0 "R37" V 7630 1350 50  0000 C CNN
F 1 "20K" V 7550 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7480 1350 50  0001 C CNN
F 3 "" H 7550 1350 50  0000 C CNN
	1    7550 1350
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR033
U 1 1 5A8DC5E6
P 7550 1550
F 0 "#PWR033" H 7550 1300 50  0001 C CNN
F 1 "GND" H 7550 1400 50  0000 C CNN
F 2 "" H 7550 1550 50  0000 C CNN
F 3 "" H 7550 1550 50  0000 C CNN
	1    7550 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 1200 7550 1200
Wire Wire Line
	7550 1550 7550 1500
Connection ~ 7550 1200
$Comp
L allcolours-rescue:GND-power #PWR03
U 1 1 5ABC8F42
P 6150 2300
F 0 "#PWR03" H 6150 2050 50  0001 C CNN
F 1 "GND" H 6150 2150 50  0000 C CNN
F 2 "" H 6150 2300 50  0000 C CNN
F 3 "" H 6150 2300 50  0000 C CNN
	1    6150 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 900  6550 800 
$Sheet
S 3950 7150 2050 550 
U 5AD5ACBB
F0 "Sheet5AD5ACBA" 60
F1 "file5AD5ACBA.sch" 60
$EndSheet
Text Notes 4400 7550 0    236  ~ 0
MICRO
Wire Wire Line
	1650 1900 2100 1900
Wire Wire Line
	1450 1050 2100 1050
Wire Wire Line
	2900 1450 3000 1450
Wire Wire Line
	3250 1150 3350 1150
Wire Wire Line
	9250 4975 9350 4975
Wire Wire Line
	9250 5125 9250 5425
Wire Wire Line
	9800 5325 9800 5375
Wire Wire Line
	9800 5325 9900 5325
Wire Wire Line
	9550 5325 9550 5425
Wire Wire Line
	9900 5325 9950 5325
Wire Wire Line
	10400 5125 10400 5325
Wire Wire Line
	5700 1100 5800 1100
Wire Wire Line
	5800 1800 5950 1800
Wire Wire Line
	8100 5175 8100 5275
Wire Wire Line
	8600 5175 8750 5175
Wire Wire Line
	8600 5175 8600 5275
Wire Wire Line
	8100 5375 8600 5375
Wire Wire Line
	7550 1200 7700 1200
$Comp
L allcolours-rescue:Conn_01x01-Connector J1
U 1 1 5B6FF2C7
P 1825 4825
F 0 "J1" H 1905 4867 50  0000 L CNN
F 1 "Conn_01x01" H 1905 4776 50  0000 L CNN
F 2 "" H 1825 4825 50  0001 C CNN
F 3 "~" H 1825 4825 50  0001 C CNN
	1    1825 4825
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:TL072-linear U1
U 2 1 5B6FD3B3
P 3300 1350
F 0 "U1" H 3641 1396 50  0000 L CNN
F 1 "TL072" H 3641 1305 50  0000 L CNN
F 2 "" H 3300 1350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3300 1350 50  0001 C CNN
	2    3300 1350
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:TL072-linear U6
U 1 1 5B6FE02A
P 6650 1200
F 0 "U6" H 6991 1246 50  0000 L CNN
F 1 "TL072" H 6991 1155 50  0000 L CNN
F 2 "" H 6650 1200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6650 1200 50  0001 C CNN
	1    6650 1200
	1    0    0    -1  
$EndComp
Text Notes 2125 4325 0    60   ~ 0
finger oscillator\n
$Comp
L allcolours-rescue:40106-Logic_CMOS_4000 U2
U 1 1 5B6D0CC1
P 2475 4825
F 0 "U2" H 2475 4975 50  0000 C CNN
F 1 "40106" H 2475 4625 50  0000 C CNN
F 2 "" H 2475 4825 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2475 4825 50  0001 C CNN
	1    2475 4825
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R19
U 1 1 5B6D0DB7
P 2475 4525
F 0 "R19" V 2555 4525 50  0000 C CNN
F 1 "10K" V 2475 4525 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2405 4525 50  0001 C CNN
F 3 "" H 2475 4525 50  0000 C CNN
	1    2475 4525
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:C-device C8
U 1 1 5B6D10B1
P 2175 5075
F 0 "C8" H 2200 5175 50  0000 L CNN
F 1 "1N" H 2200 4975 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2213 4925 50  0001 C CNN
F 3 "" H 2175 5075 50  0000 C CNN
	1    2175 5075
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J7
U 1 1 5B6D14A4
P 1825 4975
F 0 "J7" H 1905 5017 50  0000 L CNN
F 1 "Conn_01x01" H 1905 4926 50  0000 L CNN
F 2 "" H 1825 4975 50  0001 C CNN
F 3 "~" H 1825 4975 50  0001 C CNN
	1    1825 4975
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR021
U 1 1 5B6D1528
P 2025 5025
F 0 "#PWR021" H 2025 4775 50  0001 C CNN
F 1 "GND" H 2025 4875 50  0000 C CNN
F 2 "" H 2025 5025 50  0000 C CNN
F 3 "" H 2025 5025 50  0000 C CNN
	1    2025 5025
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR023
U 1 1 5B6D159D
P 2175 5275
F 0 "#PWR023" H 2175 5025 50  0001 C CNN
F 1 "GND" H 2175 5125 50  0000 C CNN
F 2 "" H 2175 5275 50  0000 C CNN
F 3 "" H 2175 5275 50  0000 C CNN
	1    2175 5275
	1    0    0    -1  
$EndComp
Wire Wire Line
	2025 4825 2175 4825
Wire Wire Line
	2175 4825 2175 4525
Wire Wire Line
	2175 4525 2325 4525
Connection ~ 2175 4825
Wire Wire Line
	2625 4525 2775 4525
Wire Wire Line
	2775 4525 2775 4825
Wire Wire Line
	2175 4825 2175 4925
Wire Wire Line
	2025 4975 2025 5025
Wire Wire Line
	2175 5275 2175 5225
$Comp
L allcolours-rescue:PWR_FLAG-power #FLG02
U 1 1 5B6F6A22
P 9350 4825
F 0 "#FLG02" H 9350 4900 50  0001 C CNN
F 1 "PWR_FLAG" H 9350 4999 50  0000 C CNN
F 2 "" H 9350 4825 50  0001 C CNN
F 3 "" H 9350 4825 50  0001 C CNN
	1    9350 4825
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:PWR_FLAG-power #FLG01
U 1 1 5B6F6BB5
P 8750 5025
F 0 "#FLG01" H 8750 5100 50  0001 C CNN
F 1 "PWR_FLAG" H 8750 5199 50  0000 C CNN
F 2 "" H 8750 5025 50  0001 C CNN
F 3 "" H 8750 5025 50  0001 C CNN
	1    8750 5025
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 5175 8750 5025
Connection ~ 8750 5175
Wire Wire Line
	8750 5175 8800 5175
Wire Wire Line
	9350 4975 9350 4825
Connection ~ 9350 4975
Wire Wire Line
	9350 4975 9400 4975
$Comp
L allcolours-rescue:+5V-power #PWR062
U 1 1 5B726638
P 10500 4925
F 0 "#PWR062" H 10500 4775 50  0001 C CNN
F 1 "+5V" H 10515 5098 50  0000 C CNN
F 2 "" H 10500 4925 50  0001 C CNN
F 3 "" H 10500 4925 50  0001 C CNN
	1    10500 4925
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 4975 10500 4975
Wire Wire Line
	10500 4975 10500 4925
Connection ~ 10400 4975
$Comp
L allcolours-rescue:TL072-linear U5
U 1 1 5B6C90C4
P 3225 4925
F 0 "U5" H 3566 4971 50  0000 L CNN
F 1 "TL072" H 3566 4880 50  0000 L CNN
F 2 "" H 3225 4925 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3225 4925 50  0001 C CNN
	1    3225 4925
	1    0    0    -1  
$EndComp
Wire Wire Line
	2775 4825 2925 4825
Connection ~ 2775 4825
$Comp
L allcolours-rescue:+12V-power #PWR034
U 1 1 5B6D8ACD
P 3125 4575
F 0 "#PWR034" H 3125 4425 50  0001 C CNN
F 1 "+12V" H 3125 4715 50  0000 C CNN
F 2 "" H 3125 4575 50  0000 C CNN
F 3 "" H 3125 4575 50  0000 C CNN
	1    3125 4575
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR035
U 1 1 5B6D8B44
P 3125 5275
F 0 "#PWR035" H 3125 5125 50  0001 C CNN
F 1 "-12VA" H 3125 5415 50  0000 C CNN
F 2 "" H 3125 5275 50  0000 C CNN
F 3 "" H 3125 5275 50  0000 C CNN
	1    3125 5275
	-1   0    0    1   
$EndComp
Wire Wire Line
	3125 4575 3125 4625
Wire Wire Line
	3125 5225 3125 5275
$Comp
L allcolours-rescue:+12V-power #PWR05
U 1 1 5B6F02C7
P 600 1500
F 0 "#PWR05" H 600 1350 50  0001 C CNN
F 1 "+12V" H 600 1640 50  0000 C CNN
F 2 "" H 600 1500 50  0000 C CNN
F 3 "" H 600 1500 50  0000 C CNN
	1    600  1500
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR06
U 1 1 5B6F03A2
P 600 1900
F 0 "#PWR06" H 600 1750 50  0001 C CNN
F 1 "-12VA" H 600 2040 50  0000 C CNN
F 2 "" H 600 1900 50  0000 C CNN
F 3 "" H 600 1900 50  0000 C CNN
	1    600  1900
	-1   0    0    1   
$EndComp
Wire Wire Line
	600  1500 600  1550
Wire Wire Line
	600  1850 600  1900
Wire Wire Line
	2925 5025 2925 5475
Wire Wire Line
	2925 5475 3525 5475
Wire Wire Line
	3525 5475 3525 4925
$Sheet
S 2550 7300 950  300 
U 5B6C330C
F0 "Sheet5B6C330B" 60
F1 "allcolfilter.sch" 60
$EndSheet
Text Notes 2800 7550 0    118  ~ 0
FILTER\n
$Comp
L allcolours-rescue:POT_TRIM-device RV1
U 1 1 5B70AE2B
P 3500 1150
F 0 "RV1" V 3293 1150 50  0000 C CNN
F 1 "1M" V 3550 1000 50  0000 C CNN
F 2 "" H 3500 1150 50  0001 C CNN
F 3 "" H 3500 1150 50  0001 C CNN
	1    3500 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 1350 3650 1350
Wire Wire Line
	3500 1300 3650 1300
Wire Wire Line
	3650 1300 3650 1350
Connection ~ 3650 1350
Wire Wire Line
	3650 1350 3700 1350
Wire Wire Line
	3650 1150 3650 1300
Connection ~ 3650 1300
Wire Wire Line
	3650 1150 3650 950 
Connection ~ 3650 1150
Text Notes 900  4000 0    60   ~ 0
bc547c cbe
Text Notes 850  2750 0    60   ~ 0
yusynth noise source x2
$Comp
L allcolours-rescue:CP1_Small-device C11
U 1 1 5B715E2B
P 1650 3500
F 0 "C11" H 1660 3570 50  0000 L CNN
F 1 "47u" H 1660 3420 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 1650 3500 50  0001 C CNN
F 3 "" H 1650 3500 50  0000 C CNN
	1    1650 3500
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR031
U 1 1 5B715E31
P 1650 4000
F 0 "#PWR031" H 1650 3750 50  0001 C CNN
F 1 "GND" H 1650 3850 50  0000 C CNN
F 2 "" H 1650 4000 50  0000 C CNN
F 3 "" H 1650 4000 50  0000 C CNN
	1    1650 4000
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R3
U 1 1 5B715E37
P 1450 3100
F 0 "R3" V 1530 3100 50  0000 C CNN
F 1 "47K" V 1450 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1380 3100 50  0001 C CNN
F 3 "" H 1450 3100 50  0000 C CNN
	1    1450 3100
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R30
U 1 1 5B715E3D
P 2100 2750
F 0 "R30" V 2180 2750 50  0000 C CNN
F 1 "22R" V 2100 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2030 2750 50  0001 C CNN
F 3 "" H 2100 2750 50  0000 C CNN
	1    2100 2750
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R31
U 1 1 5B715E43
P 2100 3100
F 0 "R31" V 2180 3100 50  0000 C CNN
F 1 "10K" V 2100 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2030 3100 50  0001 C CNN
F 3 "" H 2100 3100 50  0000 C CNN
	1    2100 3100
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R29
U 1 1 5B715E49
P 1800 3250
F 0 "R29" V 1880 3250 50  0000 C CNN
F 1 "150K" V 1800 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1730 3250 50  0001 C CNN
F 3 "" H 1800 3250 50  0000 C CNN
	1    1800 3250
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:CP1_Small-device C7
U 1 1 5B715E4F
P 950 3050
F 0 "C7" H 960 3120 50  0000 L CNN
F 1 "47u" H 960 2970 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 950 3050 50  0001 C CNN
F 3 "" H 950 3050 50  0000 C CNN
	1    950  3050
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR019
U 1 1 5B715E55
P 950 3250
F 0 "#PWR019" H 950 3000 50  0001 C CNN
F 1 "GND" H 950 3100 50  0000 C CNN
F 2 "" H 950 3250 50  0000 C CNN
F 3 "" H 950 3250 50  0000 C CNN
	1    950  3250
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR032
U 1 1 5B715E5B
P 2250 2600
F 0 "#PWR032" H 2250 2450 50  0001 C CNN
F 1 "+12V" H 2250 2740 50  0000 C CNN
F 2 "" H 2250 2600 50  0000 C CNN
F 3 "" H 2250 2600 50  0000 C CNN
	1    2250 2600
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R32
U 1 1 5B715E61
P 2700 3350
F 0 "R32" V 2780 3350 50  0000 C CNN
F 1 "33k" V 2700 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2630 3350 50  0001 C CNN
F 3 "" H 2700 3350 50  0000 C CNN
	1    2700 3350
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:CP1_Small-device C22
U 1 1 5B715E67
P 2400 3350
F 0 "C22" H 2410 3420 50  0000 L CNN
F 1 "10u" H 2410 3270 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 2400 3350 50  0001 C CNN
F 3 "" H 2400 3350 50  0000 C CNN
	1    2400 3350
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR038
U 1 1 5B715E6D
P 2800 3150
F 0 "#PWR038" H 2800 2900 50  0001 C CNN
F 1 "GND" H 2800 3000 50  0000 C CNN
F 2 "" H 2800 3150 50  0000 C CNN
F 3 "" H 2800 3150 50  0000 C CNN
	1    2800 3150
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR039
U 1 1 5B715E73
P 3200 2900
F 0 "#PWR039" H 3200 2750 50  0001 C CNN
F 1 "+12V" H 3200 3040 50  0000 C CNN
F 2 "" H 3200 2900 50  0000 C CNN
F 3 "" H 3200 2900 50  0000 C CNN
	1    3200 2900
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR040
U 1 1 5B715E79
P 3200 3600
F 0 "#PWR040" H 3200 3450 50  0001 C CNN
F 1 "-12VA" H 3200 3740 50  0000 C CNN
F 2 "" H 3200 3600 50  0000 C CNN
F 3 "" H 3200 3600 50  0000 C CNN
	1    3200 3600
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device C23
U 1 1 5B715E7F
P 3500 2850
F 0 "C23" H 3525 2950 50  0000 L CNN
F 1 "10p" H 3525 2750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3538 2700 50  0001 C CNN
F 3 "" H 3500 2850 50  0000 C CNN
	1    3500 2850
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device R33
U 1 1 5B715E86
P 3850 3250
F 0 "R33" V 3930 3250 50  0000 C CNN
F 1 "1K" V 3850 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3780 3250 50  0001 C CNN
F 3 "" H 3850 3250 50  0000 C CNN
	1    3850 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1250 3800 1650 3800
Wire Wire Line
	1650 3800 1650 4000
Wire Wire Line
	2100 3800 2100 3700
Connection ~ 1650 3800
Wire Wire Line
	950  2950 1450 2950
Wire Wire Line
	950  3250 950  3150
Wire Wire Line
	1450 3250 1450 3500
Wire Wire Line
	1450 3500 1550 3500
Wire Wire Line
	1750 3500 1800 3500
Wire Wire Line
	1800 3500 1800 3400
Connection ~ 1450 2950
Wire Wire Line
	2100 2950 2100 2900
Wire Wire Line
	2100 3250 2100 3300
Wire Wire Line
	1800 3100 1950 3100
Wire Wire Line
	1950 3100 1950 3300
Wire Wire Line
	1950 3300 2100 3300
Wire Wire Line
	2100 2600 2250 2600
Wire Wire Line
	2500 3350 2550 3350
Wire Wire Line
	2850 3350 2900 3350
Wire Wire Line
	2800 3150 3000 3150
Wire Wire Line
	3200 2950 3200 2900
Wire Wire Line
	3200 3550 3200 3600
Wire Wire Line
	2900 3350 2900 3050
Wire Wire Line
	2900 3050 3250 3050
Connection ~ 2900 3350
Wire Wire Line
	3250 3050 3250 2850
Wire Wire Line
	3250 2850 3350 2850
Connection ~ 3250 3050
Wire Wire Line
	2300 3350 2150 3350
Wire Wire Line
	2150 3350 2150 3250
Wire Wire Line
	2150 3250 2100 3250
Wire Wire Line
	1650 3800 2100 3800
Wire Wire Line
	1450 2950 2100 2950
Wire Wire Line
	2900 3350 3000 3350
Wire Wire Line
	3250 3050 3350 3050
$Comp
L allcolours-rescue:TL072-linear U1
U 1 1 5B715EB0
P 3300 3250
F 0 "U1" H 3641 3296 50  0000 L CNN
F 1 "TL072" H 3641 3205 50  0000 L CNN
F 2 "" H 3300 3250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3300 3250 50  0001 C CNN
	1    3300 3250
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:POT_TRIM-device RV2
U 1 1 5B715EB6
P 3500 3050
F 0 "RV2" V 3293 3050 50  0000 C CNN
F 1 "1M" V 3550 2900 50  0000 C CNN
F 2 "" H 3500 3050 50  0001 C CNN
F 3 "" H 3500 3050 50  0001 C CNN
	1    3500 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 3250 3650 3250
Wire Wire Line
	3500 3200 3650 3200
Wire Wire Line
	3650 3200 3650 3250
Connection ~ 3650 3250
Wire Wire Line
	3650 3250 3700 3250
Wire Wire Line
	3650 3050 3650 3200
Connection ~ 3650 3200
Wire Wire Line
	3650 3050 3650 2850
Connection ~ 3650 3050
Connection ~ 1450 3500
Connection ~ 1800 3500
Connection ~ 2100 2950
Connection ~ 2100 3250
Connection ~ 2100 3300
Connection ~ 8100 4975
$Comp
L allcolours-rescue:Conn_01x01-Connector J14
U 1 1 5B723C7A
P 9900 1300
F 0 "J14" H 9980 1342 50  0000 L CNN
F 1 "Conn_01x01" H 9980 1251 50  0000 L CNN
F 2 "" H 9900 1300 50  0001 C CNN
F 3 "~" H 9900 1300 50  0001 C CNN
	1    9900 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3525 4925 3675 4925
Connection ~ 3525 4925
$Comp
L allcolours-rescue:Conn_01x01-Connector J12
U 1 1 5B6B93E8
P 6600 1950
F 0 "J12" H 6680 1992 50  0000 L CNN
F 1 "Conn_01x01" H 6680 1901 50  0000 L CNN
F 2 "" H 6600 1950 50  0001 C CNN
F 3 "~" H 6600 1950 50  0001 C CNN
	1    6600 1950
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J13
U 1 1 5B6B991E
P 6600 2200
F 0 "J13" H 6680 2242 50  0000 L CNN
F 1 "Conn_01x01" H 6680 2151 50  0000 L CNN
F 2 "" H 6600 2200 50  0001 C CNN
F 3 "~" H 6600 2200 50  0001 C CNN
	1    6600 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2150 6300 2200
Wire Wire Line
	6300 2200 6400 2200
Wire Wire Line
	6150 2300 6150 2250
Wire Wire Line
	6150 1950 6400 1950
Wire Wire Line
	6100 1950 6150 1950
Connection ~ 6150 1950
$Comp
L allcolours-rescue:Conn_01x01-Connector J10
U 1 1 5B6D8CC3
P 5450 1950
F 0 "J10" H 5530 1992 50  0000 L CNN
F 1 "Conn_01x01" H 5530 1901 50  0000 L CNN
F 2 "" H 5450 1950 50  0001 C CNN
F 3 "~" H 5450 1950 50  0001 C CNN
	1    5450 1950
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 1950 5750 1950
Wire Wire Line
	5750 1950 5750 1800
Connection ~ 5750 1800
$Comp
L erthenvar:AUDIO-JACKERTHENVAR M6
U 1 1 5B6CCB33
P 10000 1050
F 0 "M6" H 9673 1012 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 10000 1050 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 10030 1200 20  0001 C CNN
F 3 "" H 10000 1050 60  0001 C CNN
	1    10000 1050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 3250 4100 3250
$Comp
L allcolours-rescue:Conn_01x01-Connector J8
U 1 1 5B6E23D7
P 1825 5975
F 0 "J8" H 1905 6017 50  0000 L CNN
F 1 "Conn_01x01" H 1905 5926 50  0000 L CNN
F 2 "" H 1825 5975 50  0001 C CNN
F 3 "~" H 1825 5975 50  0001 C CNN
	1    1825 5975
	-1   0    0    1   
$EndComp
Text Notes 2125 5475 0    60   ~ 0
finger oscillator\n
$Comp
L allcolours-rescue:R-device R25
U 1 1 5B6E23E4
P 2475 5675
F 0 "R25" V 3025 5725 50  0000 C CNN
F 1 "10K" V 2475 5675 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2405 5675 50  0001 C CNN
F 3 "" H 2475 5675 50  0000 C CNN
	1    2475 5675
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:C-device C10
U 1 1 5B6E23EA
P 2175 6225
F 0 "C10" H 2200 6325 50  0000 L CNN
F 1 "1N" H 2200 6125 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2213 6075 50  0001 C CNN
F 3 "" H 2175 6225 50  0000 C CNN
	1    2175 6225
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J9
U 1 1 5B6E23F0
P 1825 6125
F 0 "J9" H 1905 6167 50  0000 L CNN
F 1 "Conn_01x01" H 1905 6076 50  0000 L CNN
F 2 "" H 1825 6125 50  0001 C CNN
F 3 "~" H 1825 6125 50  0001 C CNN
	1    1825 6125
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR022
U 1 1 5B6E23F6
P 2025 6175
F 0 "#PWR022" H 2025 5925 50  0001 C CNN
F 1 "GND" H 2025 6025 50  0000 C CNN
F 2 "" H 2025 6175 50  0000 C CNN
F 3 "" H 2025 6175 50  0000 C CNN
	1    2025 6175
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR025
U 1 1 5B6E23FC
P 2175 6425
F 0 "#PWR025" H 2175 6175 50  0001 C CNN
F 1 "GND" H 2175 6275 50  0000 C CNN
F 2 "" H 2175 6425 50  0000 C CNN
F 3 "" H 2175 6425 50  0000 C CNN
	1    2175 6425
	1    0    0    -1  
$EndComp
Wire Wire Line
	2025 5975 2175 5975
Wire Wire Line
	2175 5975 2175 5675
Wire Wire Line
	2175 5675 2325 5675
Connection ~ 2175 5975
Wire Wire Line
	2625 5675 2775 5675
Wire Wire Line
	2775 5675 2775 5975
Wire Wire Line
	2175 5975 2175 6075
Wire Wire Line
	2025 6125 2025 6175
Wire Wire Line
	2175 6425 2175 6375
$Comp
L allcolours-rescue:TL072-linear U5
U 2 1 5B6E240B
P 3225 6075
F 0 "U5" H 3566 6121 50  0000 L CNN
F 1 "TL072" H 3566 6030 50  0000 L CNN
F 2 "" H 3225 6075 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3225 6075 50  0001 C CNN
	2    3225 6075
	1    0    0    -1  
$EndComp
Wire Wire Line
	2775 5975 2925 5975
$Comp
L allcolours-rescue:+12V-power #PWR036
U 1 1 5B6E2413
P 3125 5725
F 0 "#PWR036" H 3125 5575 50  0001 C CNN
F 1 "+12V" H 3125 5865 50  0000 C CNN
F 2 "" H 3125 5725 50  0000 C CNN
F 3 "" H 3125 5725 50  0000 C CNN
	1    3125 5725
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR037
U 1 1 5B6E2419
P 3125 6425
F 0 "#PWR037" H 3125 6275 50  0001 C CNN
F 1 "-12VA" H 3125 6565 50  0000 C CNN
F 2 "" H 3125 6425 50  0000 C CNN
F 3 "" H 3125 6425 50  0000 C CNN
	1    3125 6425
	-1   0    0    1   
$EndComp
Wire Wire Line
	3125 5725 3125 5775
Wire Wire Line
	3125 6375 3125 6425
Wire Wire Line
	2925 6175 2925 6625
Wire Wire Line
	2925 6625 3525 6625
Wire Wire Line
	3525 6625 3525 6075
Wire Wire Line
	3525 6075 3675 6075
Connection ~ 3525 6075
Text Notes 8650 650  0    60   ~ 0
enumerate outs depending on panel and prima materia\n
Text GLabel 7700 1200 2    60   Input ~ 0
7490_CLOCK
$Comp
L erthenvar:AUDIO-JACKERTHENVAR M5
U 1 1 5B723263
P 5100 900
F 0 "M5" H 5106 1119 45  0000 C CNN
F 1 "AUDIO-JACKERTHENVAR" H 5100 900 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 5130 1050 20  0001 C CNN
F 3 "" H 5100 900 60  0001 C CNN
	1    5100 900 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J11
U 1 1 5B739301
P 5950 850
F 0 "J11" H 6030 892 50  0000 L CNN
F 1 "Conn_01x01" H 6030 801 50  0000 L CNN
F 2 "" H 5950 850 50  0001 C CNN
F 3 "~" H 5950 850 50  0001 C CNN
	1    5950 850 
	-1   0    0    1   
$EndComp
$Comp
L erthenvar:AUDIO-JACKERTHENVAR M4
U 1 1 5B7393F3
P 5050 1600
F 0 "M4" H 5056 1819 45  0000 C CNN
F 1 "AUDIO-JACKERTHENVAR" H 5050 1600 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 5080 1750 20  0001 C CNN
F 3 "" H 5050 1600 60  0001 C CNN
	1    5050 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 850  6150 1100
Connection ~ 6150 1100
Wire Wire Line
	6150 1100 6350 1100
Wire Wire Line
	5400 1100 5700 1100
Wire Wire Line
	5350 1800 5450 1800
$Comp
L allcolours-rescue:GND-power #PWR059
U 1 1 5B759EF5
P 5550 800
F 0 "#PWR059" H 5550 550 50  0001 C CNN
F 1 "GND" H 5550 650 50  0000 C CNN
F 2 "" H 5550 800 50  0000 C CNN
F 3 "" H 5550 800 50  0000 C CNN
	1    5550 800 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR051
U 1 1 5B759F96
P 5500 1500
F 0 "#PWR051" H 5500 1250 50  0001 C CNN
F 1 "GND" H 5500 1350 50  0000 C CNN
F 2 "" H 5500 1500 50  0000 C CNN
F 3 "" H 5500 1500 50  0000 C CNN
	1    5500 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 800  5550 800 
Wire Wire Line
	5350 1500 5500 1500
Text Notes 5325 2750 0    60   ~ 0
primitive envelope say x2
$Comp
L allcolours-rescue:C-device C24
U 1 1 5B7FB454
P 5425 3900
F 0 "C24" H 5450 4000 50  0000 L CNN
F 1 "1N" H 5450 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5463 3750 50  0001 C CNN
F 3 "" H 5425 3900 50  0000 C CNN
	1    5425 3900
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:C-device C25
U 1 1 5B7FB5A7
P 6275 3650
F 0 "C25" H 6300 3750 50  0000 L CNN
F 1 "100N" H 6125 3550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6313 3500 50  0001 C CNN
F 3 "" H 6275 3650 50  0000 C CNN
	1    6275 3650
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device C26
U 1 1 5B7FB6C7
P 6475 3650
F 0 "C26" H 6500 3750 50  0000 L CNN
F 1 "100N" H 6225 3550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6513 3500 50  0001 C CNN
F 3 "" H 6475 3650 50  0000 C CNN
	1    6475 3650
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR061
U 1 1 5B7FBAC7
P 6375 3800
F 0 "#PWR061" H 6375 3550 50  0001 C CNN
F 1 "GND" H 6375 3650 50  0000 C CNN
F 2 "" H 6375 3800 50  0000 C CNN
F 3 "" H 6375 3800 50  0000 C CNN
	1    6375 3800
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR060
U 1 1 5B7FBB58
P 5975 4150
F 0 "#PWR060" H 5975 3900 50  0001 C CNN
F 1 "GND" H 5975 4000 50  0000 C CNN
F 2 "" H 5975 4150 50  0000 C CNN
F 3 "" H 5975 4150 50  0000 C CNN
	1    5975 4150
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R34
U 1 1 5B7FC09F
P 5625 3750
F 0 "R34" V 5705 3750 50  0000 C CNN
F 1 "1M" V 5625 3750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5555 3750 50  0001 C CNN
F 3 "" H 5625 3750 50  0000 C CNN
	1    5625 3750
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R35
U 1 1 5B7FC242
P 5975 3100
F 0 "R35" V 6055 3100 50  0000 C CNN
F 1 "33K" V 5975 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5905 3100 50  0001 C CNN
F 3 "" H 5975 3100 50  0000 C CNN
	1    5975 3100
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device D1
U 1 1 5B7FDD26
P 5975 3500
F 0 "D1" H 5975 3400 50  0000 C CNN
F 1 "1n4148" H 5975 3650 50  0000 C CNN
F 2 "" H 5975 3500 50  0001 C CNN
F 3 "" H 5975 3500 50  0001 C CNN
	1    5975 3500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5975 3250 5975 3300
Wire Wire Line
	5975 3650 5975 3700
Wire Wire Line
	5575 3900 5625 3900
Wire Wire Line
	5675 3900 5625 3900
Connection ~ 5625 3900
Text Label 5125 3900 2    60   ~ 0
SIG_IN0
Wire Wire Line
	5975 2950 5725 2950
Wire Wire Line
	5975 3300 6475 3300
Wire Wire Line
	6475 3300 6475 3500
Connection ~ 5975 3300
Wire Wire Line
	5975 3300 5975 3350
Wire Wire Line
	5975 3650 6125 3650
Wire Wire Line
	6125 3650 6125 3500
Wire Wire Line
	6125 3500 6275 3500
Connection ~ 5975 3650
Wire Wire Line
	6275 3800 6375 3800
Wire Wire Line
	6375 3800 6475 3800
Connection ~ 6375 3800
Wire Wire Line
	5975 4150 5975 4100
$Comp
L allcolours-rescue:+12V-power #PWR056
U 1 1 5B86A760
P 5625 3500
F 0 "#PWR056" H 5625 3350 50  0001 C CNN
F 1 "+12V" H 5625 3640 50  0000 C CNN
F 2 "" H 5625 3500 50  0000 C CNN
F 3 "" H 5625 3500 50  0000 C CNN
	1    5625 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5625 3600 5625 3500
Wire Wire Line
	6475 3300 6700 3300
Connection ~ 6475 3300
$Sheet
S 525  6925 1900 850 
U 5BAC374C
F0 "Sheet5BAC374B" 60
F1 "ouroboros.sch" 60
$EndSheet
Text Notes 875  7375 0    197  ~ 0
ouroboros\n
$Comp
L allcolours-rescue:Q_NPN_BEC-device Q1
U 1 1 5BB1D990
P 1250 1700
F 0 "Q1" V 1578 1700 50  0000 C CNN
F 1 "Q_NPN_BEC" V 1487 1700 50  0000 C CNN
F 2 "" H 1450 1800 50  0001 C CNN
F 3 "" H 1250 1700 50  0001 C CNN
	1    1250 1700
	0    -1   -1   0   
$EndComp
Connection ~ 1450 1600
$Comp
L allcolours-rescue:Q_NPN_BEC-device Q5
U 1 1 5BB3A98F
P 2000 1600
F 0 "Q5" H 2191 1646 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2191 1555 50  0000 L CNN
F 2 "" H 2200 1700 50  0001 C CNN
F 3 "" H 2000 1600 50  0001 C CNN
	1    2000 1600
	1    0    0    -1  
$EndComp
Connection ~ 1800 1600
Connection ~ 2100 1400
$Comp
L allcolours-rescue:Q_NPN_BEC-device Q3
U 1 1 5BB3BE45
P 1250 3600
F 0 "Q3" V 1578 3600 50  0000 C CNN
F 1 "Q_NPN_BEC" V 1487 3600 50  0000 C CNN
F 2 "" H 1450 3700 50  0001 C CNN
F 3 "" H 1250 3600 50  0001 C CNN
	1    1250 3600
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device Q6
U 1 1 5BB3C040
P 2000 3500
F 0 "Q6" H 2191 3546 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2191 3455 50  0000 L CNN
F 2 "" H 2200 3600 50  0001 C CNN
F 3 "" H 2000 3500 50  0001 C CNN
	1    2000 3500
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device Q7
U 1 1 5BB3C268
P 5875 3900
F 0 "Q7" H 6066 3946 50  0000 L CNN
F 1 "Q_NPN_BEC" H 6066 3855 50  0000 L CNN
F 2 "" H 6075 4000 50  0001 C CNN
F 3 "" H 5875 3900 50  0001 C CNN
	1    5875 3900
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:C-device C43
U 1 1 5C020573
P 650 3325
F 0 "C43" H 675 3425 50  0000 L CNN
F 1 "100N" H 675 3225 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 688 3175 50  0001 C CNN
F 3 "" H 650 3325 50  0000 C CNN
	1    650  3325
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR0110
U 1 1 5C020579
P 650 3125
F 0 "#PWR0110" H 650 2975 50  0001 C CNN
F 1 "+12V" H 650 3265 50  0000 C CNN
F 2 "" H 650 3125 50  0000 C CNN
F 3 "" H 650 3125 50  0000 C CNN
	1    650  3125
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR0111
U 1 1 5C02057F
P 650 3525
F 0 "#PWR0111" H 650 3375 50  0001 C CNN
F 1 "-12VA" H 650 3665 50  0000 C CNN
F 2 "" H 650 3525 50  0000 C CNN
F 3 "" H 650 3525 50  0000 C CNN
	1    650  3525
	-1   0    0    1   
$EndComp
Wire Wire Line
	650  3125 650  3175
Wire Wire Line
	650  3475 650  3525
$Comp
L allcolours-rescue:C-device C44
U 1 1 5C02A9C9
P 900 5475
F 0 "C44" H 925 5575 50  0000 L CNN
F 1 "100N" H 925 5375 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 938 5325 50  0001 C CNN
F 3 "" H 900 5475 50  0000 C CNN
	1    900  5475
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR0112
U 1 1 5C02A9CF
P 900 5275
F 0 "#PWR0112" H 900 5125 50  0001 C CNN
F 1 "+12V" H 900 5415 50  0000 C CNN
F 2 "" H 900 5275 50  0000 C CNN
F 3 "" H 900 5275 50  0000 C CNN
	1    900  5275
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR0113
U 1 1 5C02A9D5
P 900 5675
F 0 "#PWR0113" H 900 5525 50  0001 C CNN
F 1 "-12VA" H 900 5815 50  0000 C CNN
F 2 "" H 900 5675 50  0000 C CNN
F 3 "" H 900 5675 50  0000 C CNN
	1    900  5675
	-1   0    0    1   
$EndComp
Wire Wire Line
	900  5275 900  5325
Wire Wire Line
	900  5625 900  5675
$Comp
L 4xxx:40106 U2
U 2 1 5C035A2D
P 2475 5975
F 0 "U2" H 2500 6125 50  0000 C CNN
F 1 "40106" H 2500 6050 50  0000 C CNN
F 2 "" H 2475 5975 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2475 5975 50  0001 C CNN
	2    2475 5975
	1    0    0    -1  
$EndComp
Connection ~ 2775 5975
Text GLabel 4100 1350 2    60   Input ~ 0
NOISE_OUT1
Text GLabel 4100 3250 2    60   Input ~ 0
NOISE_OUT2
$Comp
L allcolours-rescue:Conn_01x01-Connector J?
U 1 1 5C0A53C5
P 3875 4925
F 0 "J?" H 3955 4967 50  0000 L CNN
F 1 "Conn_01x01" H 3955 4876 50  0000 L CNN
F 2 "" H 3875 4925 50  0001 C CNN
F 3 "~" H 3875 4925 50  0001 C CNN
	1    3875 4925
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J?
U 1 1 5C0A5553
P 3875 6075
F 0 "J?" H 3955 6117 50  0000 L CNN
F 1 "Conn_01x01" H 3955 6026 50  0000 L CNN
F 2 "" H 3875 6075 50  0001 C CNN
F 3 "~" H 3875 6075 50  0001 C CNN
	1    3875 6075
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J?
U 1 1 5C0AFBEE
P 5000 3900
F 0 "J?" H 5080 3942 50  0000 L CNN
F 1 "Conn_01x01" H 5080 3851 50  0000 L CNN
F 2 "" H 5000 3900 50  0001 C CNN
F 3 "~" H 5000 3900 50  0001 C CNN
	1    5000 3900
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J?
U 1 1 5C0AFD8E
P 5525 2950
F 0 "J?" H 5605 2992 50  0000 L CNN
F 1 "Conn_01x01" H 5605 2901 50  0000 L CNN
F 2 "" H 5525 2950 50  0001 C CNN
F 3 "~" H 5525 2950 50  0001 C CNN
	1    5525 2950
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J?
U 1 1 5C0AFE76
P 6900 3300
F 0 "J?" H 6980 3342 50  0000 L CNN
F 1 "Conn_01x01" H 6980 3251 50  0000 L CNN
F 2 "" H 6900 3300 50  0001 C CNN
F 3 "~" H 6900 3300 50  0001 C CNN
	1    6900 3300
	1    0    0    -1  
$EndComp
Connection ~ 6700 3300
Wire Wire Line
	6700 3300 6725 3300
Wire Wire Line
	5200 3900 5275 3900
$Comp
L allcolours-rescue:C-device C?
U 1 1 5C0C5B81
P 5450 5650
F 0 "C?" H 5475 5750 50  0000 L CNN
F 1 "1N" H 5475 5550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5488 5500 50  0001 C CNN
F 3 "" H 5450 5650 50  0000 C CNN
	1    5450 5650
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:C-device C?
U 1 1 5C0C5B87
P 6300 5400
F 0 "C?" H 6325 5500 50  0000 L CNN
F 1 "100N" H 6150 5300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6338 5250 50  0001 C CNN
F 3 "" H 6300 5400 50  0000 C CNN
	1    6300 5400
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device C?
U 1 1 5C0C5B8D
P 6500 5400
F 0 "C?" H 6525 5500 50  0000 L CNN
F 1 "100N" H 6250 5300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6538 5250 50  0001 C CNN
F 3 "" H 6500 5400 50  0000 C CNN
	1    6500 5400
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR?
U 1 1 5C0C5B93
P 6400 5550
F 0 "#PWR?" H 6400 5300 50  0001 C CNN
F 1 "GND" H 6400 5400 50  0000 C CNN
F 2 "" H 6400 5550 50  0000 C CNN
F 3 "" H 6400 5550 50  0000 C CNN
	1    6400 5550
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR?
U 1 1 5C0C5B99
P 6000 5900
F 0 "#PWR?" H 6000 5650 50  0001 C CNN
F 1 "GND" H 6000 5750 50  0000 C CNN
F 2 "" H 6000 5900 50  0000 C CNN
F 3 "" H 6000 5900 50  0000 C CNN
	1    6000 5900
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5C0C5B9F
P 5650 5500
F 0 "R?" V 5730 5500 50  0000 C CNN
F 1 "1M" V 5650 5500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5580 5500 50  0001 C CNN
F 3 "" H 5650 5500 50  0000 C CNN
	1    5650 5500
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5C0C5BA5
P 6000 4850
F 0 "R?" V 6080 4850 50  0000 C CNN
F 1 "33K" V 6000 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5930 4850 50  0001 C CNN
F 3 "" H 6000 4850 50  0000 C CNN
	1    6000 4850
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device D?
U 1 1 5C0C5BAB
P 6000 5250
F 0 "D?" H 6000 5150 50  0000 C CNN
F 1 "1n4148" H 6000 5400 50  0000 C CNN
F 2 "" H 6000 5250 50  0001 C CNN
F 3 "" H 6000 5250 50  0001 C CNN
	1    6000 5250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 5000 6000 5050
Wire Wire Line
	6000 5400 6000 5450
Wire Wire Line
	5600 5650 5650 5650
Wire Wire Line
	5700 5650 5650 5650
Connection ~ 5650 5650
Text Label 5150 5650 2    60   ~ 0
SIG_IN0
Wire Wire Line
	6000 4700 5750 4700
Wire Wire Line
	6000 5050 6500 5050
Wire Wire Line
	6500 5050 6500 5250
Connection ~ 6000 5050
Wire Wire Line
	6000 5050 6000 5100
Wire Wire Line
	6000 5400 6150 5400
Wire Wire Line
	6150 5400 6150 5250
Wire Wire Line
	6150 5250 6300 5250
Connection ~ 6000 5400
Wire Wire Line
	6300 5550 6400 5550
Wire Wire Line
	6400 5550 6500 5550
Connection ~ 6400 5550
Wire Wire Line
	6000 5900 6000 5850
$Comp
L allcolours-rescue:+12V-power #PWR?
U 1 1 5C0C5BC4
P 5650 5250
F 0 "#PWR?" H 5650 5100 50  0001 C CNN
F 1 "+12V" H 5650 5390 50  0000 C CNN
F 2 "" H 5650 5250 50  0000 C CNN
F 3 "" H 5650 5250 50  0000 C CNN
	1    5650 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 5350 5650 5250
Wire Wire Line
	6500 5050 6725 5050
Connection ~ 6500 5050
$Comp
L allcolours-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0C5BCD
P 5900 5650
F 0 "Q?" H 6091 5696 50  0000 L CNN
F 1 "Q_NPN_BEC" H 6091 5605 50  0000 L CNN
F 2 "" H 6100 5750 50  0001 C CNN
F 3 "" H 5900 5650 50  0001 C CNN
	1    5900 5650
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J?
U 1 1 5C0C5BD3
P 5025 5650
F 0 "J?" H 5105 5692 50  0000 L CNN
F 1 "Conn_01x01" H 5105 5601 50  0000 L CNN
F 2 "" H 5025 5650 50  0001 C CNN
F 3 "~" H 5025 5650 50  0001 C CNN
	1    5025 5650
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J?
U 1 1 5C0C5BD9
P 5550 4700
F 0 "J?" H 5630 4742 50  0000 L CNN
F 1 "Conn_01x01" H 5630 4651 50  0000 L CNN
F 2 "" H 5550 4700 50  0001 C CNN
F 3 "~" H 5550 4700 50  0001 C CNN
	1    5550 4700
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J?
U 1 1 5C0C5BDF
P 6925 5050
F 0 "J?" H 7005 5092 50  0000 L CNN
F 1 "Conn_01x01" H 7005 5001 50  0000 L CNN
F 2 "" H 6925 5050 50  0001 C CNN
F 3 "~" H 6925 5050 50  0001 C CNN
	1    6925 5050
	1    0    0    -1  
$EndComp
Connection ~ 6725 5050
Wire Wire Line
	6725 5050 6750 5050
Wire Wire Line
	5225 5650 5300 5650
$EndSCHEMATC
