EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
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
L allcolours-rescue:Crystal-device-allcolours-rescue Y1
U 1 1 5AD5C1D8
P 9975 3285
F 0 "Y1" V 9929 3416 50  0000 L CNN
F 1 "16 MHz" V 9975 3235 50  0000 L CNN
F 2 "Crystals:Crystal_SMD_HC49-SD" H 9975 3285 50  0001 C CNN
F 3 "" H 9975 3285 50  0001 C CNN
	1    9975 3285
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C18
U 1 1 5AD5C1D9
P 10225 3435
F 0 "C18" V 9973 3435 50  0000 C CNN
F 1 "22pf" V 10064 3435 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 10263 3285 50  0001 C CNN
F 3 "" H 10225 3435 50  0001 C CNN
	1    10225 3435
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R13
U 1 1 5AD5C1DC
P 9735 4240
F 0 "R13" V 9539 4240 50  0000 C CNN
F 1 "10K" V 9630 4240 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 9735 4240 50  0001 C CNN
F 3 "" H 9735 4240 50  0001 C CNN
	1    9735 4240
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR042
U 1 1 5AD5C1DD
P 10275 1200
F 0 "#PWR042" H 10275 950 50  0001 C CNN
F 1 "GND" H 10275 1200 50  0000 C CNN
F 2 "" H 10275 1200 50  0001 C CNN
F 3 "" H 10275 1200 50  0001 C CNN
	1    10275 1200
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR026
U 1 1 5AD5C1DE
P 9935 4240
F 0 "#PWR026" H 9935 4090 50  0001 C CNN
F 1 "+5V" H 9950 4413 50  0000 C CNN
F 2 "" H 9935 4240 50  0001 C CNN
F 3 "" H 9935 4240 50  0001 C CNN
	1    9935 4240
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C19
U 1 1 5AD5C1DF
P 10225 3135
F 0 "C19" V 9973 3135 50  0000 C CNN
F 1 "22pf" V 10064 3135 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 10263 2985 50  0001 C CNN
F 3 "" H 10225 3135 50  0001 C CNN
	1    10225 3135
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C3
U 1 1 5AD5C1E4
P 9575 1575
F 0 "C3" V 9323 1575 50  0000 C CNN
F 1 "100N" V 9414 1575 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 9613 1425 50  0001 C CNN
F 3 "" H 9575 1575 50  0001 C CNN
	1    9575 1575
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:CONN_01X06-allcolours-rescue J4
U 1 1 5AD5C290
P 10525 1450
F 0 "J4" H 10603 1491 50  0000 L CNN
F 1 "PROGRAM" H 10625 1600 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 10525 1450 50  0001 C CNN
F 3 "" H 10525 1450 50  0001 C CNN
	1    10525 1450
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR028
U 1 1 5AD5C291
P 10475 3435
F 0 "#PWR028" H 10475 3185 50  0001 C CNN
F 1 "GND" H 10475 3435 50  0000 C CNN
F 2 "" H 10475 3435 50  0001 C CNN
F 3 "" H 10475 3435 50  0001 C CNN
	1    10475 3435
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR046
U 1 1 5AD5C297
P 10125 1800
F 0 "#PWR046" H 10125 1650 50  0001 C CNN
F 1 "+5V" H 10125 1900 50  0000 C CNN
F 2 "" H 10125 1800 50  0001 C CNN
F 3 "" H 10125 1800 50  0001 C CNN
	1    10125 1800
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:L-device-allcolours-rescue L1
U 1 1 5AD5DF93
P 9010 2195
F 0 "L1" H 9063 2241 50  0000 L CNN
F 1 "L" H 9063 2150 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 9010 2195 50  0001 C CNN
F 3 "" H 9010 2195 50  0001 C CNN
	1    9010 2195
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q2
U 1 1 5B6A4D24
P 1250 1375
F 0 "Q2" H 1441 1421 50  0000 L CNN
F 1 "MMBT3904" H 900 1225 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1450 1475 50  0001 C CNN
F 3 "" H 1250 1375 50  0001 C CNN
	1    1250 1375
	1    0    0    -1  
$EndComp
Text Notes 745  320  0    118  ~ 0
pulses out x4 (2xLF 2xHF)\ninverted - 5v out?
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R9
U 1 1 5B6A6373
P 900 1375
F 0 "R9" V 704 1375 50  0000 C CNN
F 1 "10K" V 795 1375 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 900 1375 50  0001 C CNN
F 3 "" H 900 1375 50  0001 C CNN
	1    900  1375
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R10
U 1 1 5B6A6444
P 1350 1025
F 0 "R10" H 1291 979 50  0000 R CNN
F 1 "4.7K" H 1291 1070 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 1350 1025 50  0001 C CNN
F 3 "" H 1350 1025 50  0001 C CNN
	1    1350 1025
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR017
U 1 1 5B6A65ED
P 1350 1625
F 0 "#PWR017" H 1350 1375 50  0001 C CNN
F 1 "GND" H 1355 1452 50  0000 C CNN
F 2 "" H 1350 1625 50  0001 C CNN
F 3 "" H 1350 1625 50  0001 C CNN
	1    1350 1625
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR016
U 1 1 5B6B2B70
P 1350 875
F 0 "#PWR016" H 1350 725 50  0001 C CNN
F 1 "+12V" H 1365 1048 50  0000 C CNN
F 2 "" H 1350 875 50  0001 C CNN
F 3 "" H 1350 875 50  0001 C CNN
	1    1350 875 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1375 1050 1375
Wire Wire Line
	1350 1175 1350 1160
Wire Wire Line
	1350 925  1350 875 
Wire Wire Line
	1350 1625 1350 1575
Wire Wire Line
	800  1375 650  1375
Text Notes 3585 195  0    118  ~ 0
pulses in - 4x - 2x LF 2x HF inc. 1each clock in\ninverted
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q4
U 1 1 5B703499
P 3975 1475
F 0 "Q4" H 4166 1521 50  0000 L CNN
F 1 "MMBT3904" H 3625 1325 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4175 1575 50  0001 C CNN
F 3 "" H 3975 1475 50  0001 C CNN
	1    3975 1475
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R17
U 1 1 5B7034FD
P 3575 1475
F 0 "R17" V 3379 1475 50  0000 C CNN
F 1 "100K" V 3470 1475 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3575 1475 50  0001 C CNN
F 3 "" H 3575 1475 50  0001 C CNN
	1    3575 1475
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R22
U 1 1 5B703589
P 4075 1125
F 0 "R22" H 4016 1079 50  0000 R CNN
F 1 "10K" H 4016 1170 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 4075 1125 50  0001 C CNN
F 3 "" H 4075 1125 50  0001 C CNN
	1    4075 1125
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR057
U 1 1 5B7057B2
P 4075 975
F 0 "#PWR057" H 4075 825 50  0001 C CNN
F 1 "+5V" H 4090 1148 50  0000 C CNN
F 2 "" H 4075 975 50  0001 C CNN
F 3 "" H 4075 975 50  0001 C CNN
	1    4075 975 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR058
U 1 1 5B705850
P 4075 1725
F 0 "#PWR058" H 4075 1475 50  0001 C CNN
F 1 "GND" H 4080 1552 50  0000 C CNN
F 2 "" H 4075 1725 50  0001 C CNN
F 3 "" H 4075 1725 50  0001 C CNN
	1    4075 1725
	1    0    0    -1  
$EndComp
Wire Wire Line
	3475 1475 3375 1475
Wire Wire Line
	3675 1475 3725 1475
Wire Wire Line
	4075 1275 4075 1225
Wire Wire Line
	4075 1025 4075 975 
Wire Wire Line
	4075 1725 4075 1675
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR054
U 1 1 5B6DA115
P 2460 7075
F 0 "#PWR054" H 2460 6925 50  0001 C CNN
F 1 "+12V" H 2475 7248 50  0000 C CNN
F 2 "" H 2460 7075 50  0001 C CNN
F 3 "" H 2460 7075 50  0001 C CNN
	1    2460 7075
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C21
U 1 1 5B6DA15E
P 2460 7225
F 0 "C21" H 2368 7179 50  0000 R CNN
F 1 "100nF" H 2368 7270 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 2460 7225 50  0001 C CNN
F 3 "" H 2460 7225 50  0001 C CNN
	1    2460 7225
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR055
U 1 1 5B6DA1F8
P 2460 7375
F 0 "#PWR055" H 2460 7125 50  0001 C CNN
F 1 "GND" H 2465 7202 50  0000 C CNN
F 2 "" H 2460 7375 50  0001 C CNN
F 3 "" H 2460 7375 50  0001 C CNN
	1    2460 7375
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R18
U 1 1 5B6E51C6
P 2410 6875
F 0 "R18" V 2214 6875 50  0000 C CNN
F 1 "1K" V 2305 6875 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2410 6875 50  0001 C CNN
F 3 "" H 2410 6875 50  0001 C CNN
	1    2410 6875
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR049
U 1 1 5B6E533D
P 1560 6775
F 0 "#PWR049" H 1560 6525 50  0001 C CNN
F 1 "GND" H 1565 6602 50  0000 C CNN
F 2 "" H 1560 6775 50  0001 C CNN
F 3 "" H 1560 6775 50  0001 C CNN
	1    1560 6775
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R16
U 1 1 5B6E538E
P 1810 7425
F 0 "R16" V 1715 7425 50  0000 C CNN
F 1 "20K" V 1895 7435 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1810 7425 50  0001 C CNN
F 3 "" H 1810 7425 50  0001 C CNN
	1    1810 7425
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R15
U 1 1 5B6E59E3
P 1410 6975
F 0 "R15" V 1214 6975 50  0000 C CNN
F 1 "10K" V 1305 6975 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1410 6975 50  0001 C CNN
F 3 "" H 1410 6975 50  0001 C CNN
	1    1410 6975
	0    1    1    0   
$EndComp
Wire Wire Line
	4075 1275 4325 1275
Connection ~ 4075 1275
Text Label 4325 1275 1    60   ~ 0
PULSE_IN1
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R20
U 1 1 5B6EA141
P 3725 1625
F 0 "R20" H 3666 1579 50  0000 R CNN
F 1 "33K" H 3666 1670 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 3725 1625 50  0001 C CNN
F 3 "" H 3725 1625 50  0001 C CNN
	1    3725 1625
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR053
U 1 1 5B6EA26C
P 3725 1775
F 0 "#PWR053" H 3725 1525 50  0001 C CNN
F 1 "GND" H 3730 1602 50  0000 C CNN
F 2 "" H 3725 1775 50  0001 C CNN
F 3 "" H 3725 1775 50  0001 C CNN
	1    3725 1775
	1    0    0    -1  
$EndComp
Wire Wire Line
	3725 1525 3725 1475
Connection ~ 3725 1475
Wire Wire Line
	3725 1475 3775 1475
Wire Wire Line
	3725 1775 3725 1725
Wire Wire Line
	1510 6975 1560 6975
Wire Wire Line
	1560 6775 1660 6775
Wire Wire Line
	1710 7425 1560 7425
Wire Wire Line
	1560 7425 1560 6975
Connection ~ 1560 6975
Wire Wire Line
	1560 6975 1660 6975
Wire Wire Line
	1910 7425 2260 7425
Wire Wire Line
	2260 7425 2260 6875
Wire Wire Line
	2260 6875 2310 6875
Wire Wire Line
	2510 6875 2660 6875
Wire Wire Line
	2460 7375 2460 7325
Wire Wire Line
	2460 7075 2460 7125
$Comp
L allcolours-rescue:D_Zener_Small-device-allcolours-rescue D2
U 1 1 5B790D75
P 8000 1450
F 0 "D2" V 8046 1382 50  0000 R CNN
F 1 "zen?" V 7955 1382 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" V 8000 1450 50  0001 C CNN
F 3 "https://en.wikipedia.org/wiki/Zener_diode" V 8000 1450 50  0001 C CNN
	1    8000 1450
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R44
U 1 1 5B790F30
P 8000 1200
F 0 "R44" V 7804 1200 50  0000 C CNN
F 1 "470R" V 7895 1200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 8000 1200 50  0001 C CNN
F 3 "" H 8000 1200 50  0001 C CNN
	1    8000 1200
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C29
U 1 1 5B791632
P 8250 1450
F 0 "C29" V 7998 1450 50  0000 C CNN
F 1 "100N" V 8089 1450 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 8288 1300 50  0001 C CNN
F 3 "" H 8250 1450 50  0001 C CNN
	1    8250 1450
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:-12VA-power-allcolours-rescue #PWR073
U 1 1 5B7920A5
P 8000 1050
F 0 "#PWR073" H 8000 900 50  0001 C CNN
F 1 "-12VA" H 8015 1223 50  0000 C CNN
F 2 "" H 8000 1050 50  0001 C CNN
F 3 "" H 8000 1050 50  0001 C CNN
	1    8000 1050
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR074
U 1 1 5B792187
P 8000 1600
F 0 "#PWR074" H 8000 1350 50  0001 C CNN
F 1 "GND" H 8005 1427 50  0000 C CNN
F 2 "" H 8000 1600 50  0001 C CNN
F 3 "" H 8000 1600 50  0001 C CNN
	1    8000 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 1100 8000 1050
Wire Wire Line
	8000 1350 8000 1300
Wire Wire Line
	8000 1300 8250 1300
Connection ~ 8000 1300
Wire Wire Line
	8000 1550 8000 1600
Wire Wire Line
	8000 1600 8250 1600
Connection ~ 8000 1600
Wire Wire Line
	8250 1300 8500 1300
Connection ~ 8250 1300
Text Label 8500 1300 0    60   ~ 0
AREF_-10
Text Notes 4170 6015 0    118  ~ 0
CV IN  x3 =speedl, speedh, mode=just_pot\n ADD POTS
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U7
U 1 1 5B77CFF8
P 5745 6590
F 0 "U7" H 6086 6636 50  0000 L CNN
F 1 "MCP6002-xSN" H 5745 6490 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 5745 6590 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5745 6590 50  0001 C CNN
	1    5745 6590
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR066
U 1 1 5B77CFFE
P 5645 6940
F 0 "#PWR066" H 5645 6690 50  0001 C CNN
F 1 "GND" H 5780 6885 50  0000 C CNN
F 2 "" H 5645 6940 50  0001 C CNN
F 3 "" H 5645 6940 50  0001 C CNN
	1    5645 6940
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR065
U 1 1 5B77D004
P 5645 6240
F 0 "#PWR065" H 5645 6090 50  0001 C CNN
F 1 "+5V" H 5660 6413 50  0000 C CNN
F 2 "" H 5645 6240 50  0001 C CNN
F 3 "" H 5645 6240 50  0001 C CNN
	1    5645 6240
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R38
U 1 1 5B77D00A
P 5295 6690
F 0 "R38" V 5099 6690 50  0000 C CNN
F 1 "100K" V 5200 6610 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5295 6690 50  0001 C CNN
F 3 "" H 5295 6690 50  0001 C CNN
	1    5295 6690
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R39
U 1 1 5B77D010
P 5695 7140
F 0 "R39" V 5615 7270 50  0000 C CNN
F 1 "100K" V 5745 7335 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5695 7140 50  0001 C CNN
F 3 "" H 5695 7140 50  0001 C CNN
	1    5695 7140
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R36
U 1 1 5B77D016
P 5145 7140
F 0 "R36" V 4949 7140 50  0000 C CNN
F 1 "200K" V 5040 7140 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5145 7140 50  0001 C CNN
F 3 "" H 5145 7140 50  0001 C CNN
	1    5145 7140
	0    1    1    0   
$EndComp
Wire Wire Line
	5645 6290 5645 6240
Wire Wire Line
	5395 6690 5445 6690
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR064
U 1 1 5B77D02A
P 5395 6490
F 0 "#PWR064" H 5395 6240 50  0001 C CNN
F 1 "GND" H 5400 6317 50  0000 C CNN
F 2 "" H 5395 6490 50  0001 C CNN
F 3 "" H 5395 6490 50  0001 C CNN
	1    5395 6490
	1    0    0    -1  
$EndComp
Wire Wire Line
	5395 6490 5445 6490
Wire Wire Line
	5645 6940 5645 6890
Wire Wire Line
	5395 7140 5595 7140
Connection ~ 5395 6690
Wire Wire Line
	5795 7140 6045 7140
Wire Wire Line
	6045 7140 6045 6590
Wire Wire Line
	6045 6590 6345 6590
Connection ~ 6045 6590
Wire Wire Line
	5245 7140 5395 7140
Connection ~ 5395 7140
Wire Wire Line
	5095 6690 5195 6690
Wire Wire Line
	5045 7140 4895 7140
Text Label 4895 7140 2    60   ~ 0
AREF_-10
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C27
U 1 1 5B77D048
P 5695 7340
F 0 "C27" V 5750 7460 50  0000 C CNN
F 1 "1nF" V 5810 7345 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 5695 7340 50  0001 C CNN
F 3 "" H 5695 7340 50  0001 C CNN
	1    5695 7340
	0    1    1    0   
$EndComp
Wire Wire Line
	5395 7140 5395 7340
Wire Wire Line
	5395 7340 5595 7340
Wire Wire Line
	5795 7340 6045 7340
Wire Wire Line
	6045 7340 6045 7140
Connection ~ 6045 7140
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C28
U 1 1 5B77D053
P 6540 6990
F 0 "C28" H 6448 6944 50  0000 R CNN
F 1 "100nF" H 6448 7035 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 6540 6990 50  0001 C CNN
F 3 "" H 6540 6990 50  0001 C CNN
	1    6540 6990
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR068
U 1 1 5B77D059
P 6540 6840
F 0 "#PWR068" H 6540 6690 50  0001 C CNN
F 1 "+5V" H 6555 7013 50  0000 C CNN
F 2 "" H 6540 6840 50  0001 C CNN
F 3 "" H 6540 6840 50  0001 C CNN
	1    6540 6840
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR069
U 1 1 5B77D05F
P 6540 7140
F 0 "#PWR069" H 6540 6890 50  0001 C CNN
F 1 "GND" H 6545 6967 50  0000 C CNN
F 2 "" H 6540 7140 50  0001 C CNN
F 3 "" H 6540 7140 50  0001 C CNN
	1    6540 7140
	1    0    0    -1  
$EndComp
Wire Wire Line
	6540 7090 6540 7140
Wire Wire Line
	6540 6840 6540 6890
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR081
U 1 1 5B70FF88
P 8760 2145
F 0 "#PWR081" H 8760 1995 50  0001 C CNN
F 1 "+5V" H 8775 2318 50  0000 C CNN
F 2 "" H 8760 2145 50  0001 C CNN
F 3 "" H 8760 2145 50  0001 C CNN
	1    8760 2145
	1    0    0    -1  
$EndComp
Wire Wire Line
	8760 2345 8760 2145
Wire Wire Line
	8860 2345 8860 2195
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR084
U 1 1 5B74B1A0
P 9575 1825
F 0 "#PWR084" H 9575 1575 50  0001 C CNN
F 1 "GND" H 9575 1825 50  0000 C CNN
F 2 "" H 9575 1825 50  0001 C CNN
F 3 "" H 9575 1825 50  0001 C CNN
	1    9575 1825
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR083
U 1 1 5B74B51F
P 9575 1275
F 0 "#PWR083" H 9575 1125 50  0001 C CNN
F 1 "+5V" H 9590 1448 50  0000 C CNN
F 2 "" H 9575 1275 50  0001 C CNN
F 3 "" H 9575 1275 50  0001 C CNN
	1    9575 1275
	1    0    0    -1  
$EndComp
Wire Wire Line
	9575 1725 9575 1765
Wire Wire Line
	9575 1425 9575 1390
Wire Wire Line
	9975 3135 9825 3135
Wire Wire Line
	10075 3135 9975 3135
Connection ~ 9975 3135
Wire Wire Line
	10075 3435 9975 3435
Wire Wire Line
	10475 3435 10375 3435
Wire Wire Line
	10375 3135 10375 3435
Connection ~ 10375 3435
Text Label 10070 4190 0    60   ~ 0
RESET
Wire Wire Line
	10125 1800 10325 1800
Wire Wire Line
	10325 1800 10325 1700
Wire Wire Line
	10275 1200 10325 1200
Wire Wire Line
	10325 1300 10325 1350
Wire Wire Line
	10325 1350 10125 1350
Text Label 10125 1350 0    60   ~ 0
SCK
Wire Wire Line
	10325 1400 10125 1400
Text Label 10125 1400 0    60   ~ 0
MISO
Wire Wire Line
	10325 1500 10125 1500
Text Label 10125 1500 0    60   ~ 0
MOSI
Wire Wire Line
	10325 1600 10125 1600
Text Label 10125 1600 0    60   ~ 0
RESET
Wire Wire Line
	9545 3640 9645 3640
Text Label 9645 3640 0    60   ~ 0
P1_OUT
Wire Wire Line
	9545 3740 9645 3740
Text Label 9645 3740 0    60   ~ 0
P2_OUT
Wire Wire Line
	9545 3840 9645 3840
Text Label 9645 3840 0    60   ~ 0
P3_OUT
Wire Wire Line
	9545 3940 9645 3940
Text Label 9645 3940 0    60   ~ 0
P4_OUT
Wire Wire Line
	9545 4040 9645 4040
Wire Wire Line
	9545 4440 9645 4440
Text Label 9645 4440 0    60   ~ 0
PULSE_IN1
Wire Wire Line
	9545 4540 9645 4540
Text Label 9645 4540 0    60   ~ 0
PULSE_IN2
Text Label 9630 4640 0    60   ~ 0
PULSE_IN3
Text Label 9600 4740 0    60   ~ 0
PULSE_IN4
Wire Wire Line
	9160 2195 9160 2345
$Comp
L MCU_Microchip_ATmega:ATmega168-20AU U4
U 1 1 5C169913
P 8945 3940
F 0 "U4" H 8940 2825 50  0000 C CNN
F 1 "ATmega168-20AU" H 8860 3245 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 8945 3940 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2545-8-bit-AVR-Microcontroller-ATmega48-88-168_Datasheet.pdf" H 8945 3940 50  0001 C CNN
	1    8945 3940
	1    0    0    -1  
$EndComp
Text GLabel 9615 2840 2    79   Input ~ 0
PWM_OUT_HF
Wire Wire Line
	9545 2840 9615 2840
Text Label 8290 2940 2    60   ~ 0
CV_IN1
Text Label 8290 3040 2    60   ~ 0
CV_IN2
Wire Wire Line
	9545 4140 9645 4140
Wire Wire Line
	9545 4640 9630 4640
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR082
U 1 1 5C2C7A40
P 8945 5485
F 0 "#PWR082" H 8945 5235 50  0001 C CNN
F 1 "GND" H 8950 5312 50  0000 C CNN
F 2 "" H 8945 5485 50  0001 C CNN
F 3 "" H 8945 5485 50  0001 C CNN
	1    8945 5485
	1    0    0    -1  
$EndComp
Wire Wire Line
	8945 5440 8945 5485
Wire Wire Line
	8945 2345 8945 2440
Wire Wire Line
	8760 2345 8860 2345
Connection ~ 8860 2345
Wire Wire Line
	8860 2345 8945 2345
Wire Wire Line
	9045 2440 9045 2345
Wire Wire Line
	9045 2345 9160 2345
$Comp
L allcolours-rescue:C-device-allcolours-rescue C2
U 1 1 5C34BB85
P 7810 2850
F 0 "C2" V 7558 2850 50  0000 C CNN
F 1 "100N" V 7649 2850 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 7848 2700 50  0001 C CNN
F 3 "" H 7810 2850 50  0001 C CNN
	1    7810 2850
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR080
U 1 1 5C34BD39
P 7810 3060
F 0 "#PWR080" H 7810 2810 50  0001 C CNN
F 1 "GND" H 7810 3060 50  0000 C CNN
F 2 "" H 7810 3060 50  0001 C CNN
F 3 "" H 7810 3060 50  0001 C CNN
	1    7810 3060
	1    0    0    -1  
$EndComp
Wire Wire Line
	7810 2700 8345 2700
Wire Wire Line
	8345 2700 8345 2740
Wire Wire Line
	7810 3000 7810 3060
Wire Wire Line
	8290 2940 8345 2940
Wire Wire Line
	8290 3040 8345 3040
Wire Wire Line
	9545 3340 9825 3340
Wire Wire Line
	9825 3340 9825 3135
Wire Wire Line
	9545 3440 9975 3440
Wire Wire Line
	9975 3440 9975 3435
Connection ~ 9975 3435
Wire Wire Line
	9545 4240 9585 4240
Text Label 9605 3040 0    60   ~ 0
MOSI
Wire Wire Line
	9545 3140 9605 3140
Text Label 9605 3140 0    60   ~ 0
MISO
Wire Wire Line
	9545 3240 9605 3240
Text Label 9605 3240 0    60   ~ 0
SCK
$Comp
L allcolours-rescue:C-device-allcolours-rescue C30
U 1 1 5C4F3990
P 9380 1575
F 0 "C30" V 9128 1575 50  0000 C CNN
F 1 "100N" V 9219 1575 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 9418 1425 50  0001 C CNN
F 3 "" H 9380 1575 50  0001 C CNN
	1    9380 1575
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C31
U 1 1 5C4F3ABC
P 9795 1565
F 0 "C31" V 9543 1565 50  0000 C CNN
F 1 "100N" V 9634 1565 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 9833 1415 50  0001 C CNN
F 3 "" H 9795 1565 50  0001 C CNN
	1    9795 1565
	-1   0    0    1   
$EndComp
Wire Wire Line
	9380 1425 9535 1425
Wire Wire Line
	9535 1425 9535 1390
Wire Wire Line
	9535 1390 9575 1390
Connection ~ 9575 1390
Wire Wire Line
	9575 1390 9575 1275
Wire Wire Line
	9575 1390 9795 1390
Wire Wire Line
	9795 1390 9795 1415
Wire Wire Line
	9380 1725 9505 1725
Wire Wire Line
	9505 1725 9505 1765
Wire Wire Line
	9505 1765 9575 1765
Connection ~ 9575 1765
Wire Wire Line
	9575 1765 9575 1825
Wire Wire Line
	9575 1765 9795 1765
Wire Wire Line
	9795 1765 9795 1715
Wire Wire Line
	9835 4240 9935 4240
Wire Wire Line
	9585 4240 9585 4190
Wire Wire Line
	9585 4190 10070 4190
Connection ~ 9585 4240
Wire Wire Line
	9585 4240 9635 4240
Text Notes 8705 745  0    118  ~ 0
add micro controlled led
Wire Wire Line
	9545 2740 9650 2740
Text GLabel 9860 3040 2    118  Input ~ 0
PWM_OUT_LF
Wire Wire Line
	9545 3040 9860 3040
Text Notes -1905 6455 0    157  ~ 0
PWM out x2 lf is filtered, hf is fast 4392
Wire Wire Line
	9545 4740 9600 4740
Wire Wire Line
	9545 4840 9600 4840
Wire Wire Line
	9545 4940 9600 4940
Wire Wire Line
	9545 5040 9600 5040
Wire Wire Line
	9545 5140 9600 5140
Text Label 9645 4140 0    79   ~ 0
CV_IN3
$Comp
L Device:R_POT RV?
U 1 1 5D2C66BC
P 4725 6445
F 0 "RV?" H 4655 6491 50  0000 R CNN
F 1 "R_POT" H 4655 6400 50  0000 R CNN
F 2 "" H 4725 6445 50  0001 C CNN
F 3 "~" H 4725 6445 50  0001 C CNN
	1    4725 6445
	1    0    0    -1  
$EndComp
Text Label 4725 6240 2    60   ~ 0
AREF_-10
Wire Wire Line
	4725 6240 4725 6295
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5D2CAEA0
P 4725 6635
F 0 "#PWR?" H 4725 6385 50  0001 C CNN
F 1 "GND" H 4730 6462 50  0000 C CNN
F 2 "" H 4725 6635 50  0001 C CNN
F 3 "" H 4725 6635 50  0001 C CNN
	1    4725 6635
	1    0    0    -1  
$EndComp
Wire Wire Line
	4875 6910 4875 6445
Wire Wire Line
	5395 6910 5395 7140
Wire Wire Line
	5395 6690 5395 6910
Connection ~ 5395 6910
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5D2CADCC
P 5295 6910
F 0 "R?" V 5099 6910 50  0000 C CNN
F 1 "200K" V 5190 6910 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5295 6910 50  0001 C CNN
F 3 "" H 5295 6910 50  0001 C CNN
	1    5295 6910
	0    1    1    0   
$EndComp
Wire Wire Line
	4875 6910 5195 6910
Wire Wire Line
	4725 6595 4725 6635
Text Notes 4655 7390 0    157  ~ 0
0-5v\n
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5D2E2867
P 1610 1280
F 0 "R?" H 1551 1234 50  0000 R CNN
F 1 "3.3K" H 1551 1325 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 1610 1280 50  0001 C CNN
F 3 "" H 1610 1280 50  0001 C CNN
	1    1610 1280
	1    0    0    -1  
$EndComp
Wire Wire Line
	1345 1160 1350 1160
Connection ~ 1350 1160
Wire Wire Line
	1350 1160 1350 1125
Wire Wire Line
	1345 1155 1610 1155
Wire Wire Line
	1610 1155 1610 1180
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5D2F0083
P 1610 1410
F 0 "#PWR?" H 1610 1160 50  0001 C CNN
F 1 "GND" H 1615 1237 50  0000 C CNN
F 2 "" H 1610 1410 50  0001 C CNN
F 3 "" H 1610 1410 50  0001 C CNN
	1    1610 1410
	1    0    0    -1  
$EndComp
Wire Wire Line
	1610 1380 1610 1410
Wire Wire Line
	1610 1155 1720 1155
Connection ~ 1610 1155
Wire Wire Line
	1210 6975 1310 6975
$Comp
L Device:Opamp_Dual_Generic U?
U 1 1 5D3B432B
P 1960 6875
AR Path="/5D3B432B" Ref="U?"  Part="1" 
AR Path="/5AD5ACBB/5D3B432B" Ref="U?"  Part="1" 
F 0 "U?" H 1960 7242 50  0000 C CNN
F 1 "Opamp_Dual_Generic" H 1960 7151 50  0000 C CNN
F 2 "" H 1960 6875 50  0001 C CNN
F 3 "~" H 1960 6875 50  0001 C CNN
	1    1960 6875
	1    0    0    -1  
$EndComp
Text Notes 2660 6665 0    118  ~ 0
MAX4392
Connection ~ 2260 6875
Text Notes 1355 3200 0    118  ~ 0
4 bit DAC x2
$EndSCHEMATC
