EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
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
L allcolours-rescue:D_Zener_Small-device D5
U 1 1 5B6E5322
P 4750 4950
F 0 "D5" V 4704 5018 50  0000 L CNN
F 1 "zen?" V 4650 5050 50  0000 L CNN
F 2 "" V 4750 4950 50  0001 C CNN
F 3 "" V 4750 4950 50  0001 C CNN
	1    4750 4950
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:D_Zener_Small-device D4
U 1 1 5B6E5329
P 4750 4700
F 0 "D4" V 4704 4768 50  0000 L CNN
F 1 "zen?" V 4795 4768 50  0000 L CNN
F 2 "" V 4750 4700 50  0001 C CNN
F 3 "" V 4750 4700 50  0001 C CNN
	1    4750 4700
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR0101
U 1 1 5B6E5330
P 4750 5100
F 0 "#PWR0101" H 4750 4850 50  0001 C CNN
F 1 "GND" H 4750 4950 50  0000 C CNN
F 2 "" H 4750 5100 50  0000 C CNN
F 3 "" H 4750 5100 50  0000 C CNN
	1    4750 5100
	1    0    0    -1  
$EndComp
$Comp
L MAX7490:MAX7490 U8
U 1 1 5B6E5336
P 3550 4450
F 0 "U8" H 3550 5165 50  0000 C CNN
F 1 "MAX7490-check width" H 3550 5074 50  0000 C CNN
F 2 "MODULE" H 3550 4450 50  0001 C CNN
F 3 "DOCUMENTATION" H 3550 4450 50  0001 C CNN
	1    3550 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 5150 2800 4850
Wire Wire Line
	4300 4700 4350 4700
Wire Wire Line
	4350 4700 4350 5150
Wire Wire Line
	4350 5150 2800 5150
Wire Wire Line
	4750 4850 4750 4800
Connection ~ 4750 4800
$Comp
L allcolours-rescue:+5V-power #PWR0100
U 1 1 5B6E5344
P 4750 4550
F 0 "#PWR0100" H 4750 4400 50  0001 C CNN
F 1 "+5V" H 4850 4600 50  0000 C CNN
F 2 "" H 4750 4550 50  0001 C CNN
F 3 "" H 4750 4550 50  0001 C CNN
	1    4750 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 5100 4750 5050
Wire Wire Line
	4750 4600 4750 4550
Wire Wire Line
	4750 4800 5000 4800
$Comp
L allcolours-rescue:+5V-power #PWR095
U 1 1 5B6E534D
P 2600 4850
F 0 "#PWR095" H 2600 4700 50  0001 C CNN
F 1 "+5V" H 2615 5023 50  0000 C CNN
F 2 "" H 2600 4850 50  0001 C CNN
F 3 "" H 2600 4850 50  0001 C CNN
	1    2600 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 4850 2650 4850
Connection ~ 2800 4850
Wire Wire Line
	2800 4850 2800 4800
$Comp
L allcolours-rescue:GND-power #PWR096
U 1 1 5B6E5356
P 2750 4700
F 0 "#PWR096" H 2750 4450 50  0001 C CNN
F 1 "GND" H 2750 4750 50  0000 C CNN
F 2 "" H 2750 4700 50  0000 C CNN
F 3 "" H 2750 4700 50  0000 C CNN
	1    2750 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4700 2800 4700
Wire Wire Line
	2650 4850 2650 4600
Wire Wire Line
	2650 4600 2800 4600
Connection ~ 2650 4850
Wire Wire Line
	2650 4850 2800 4850
$Comp
L allcolours-rescue:C-device C38
U 1 1 5B6E5361
P 4500 4750
F 0 "C38" H 4525 4850 50  0000 L CNN
F 1 "100N" H 4525 4650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4538 4600 50  0001 C CNN
F 3 "" H 4500 4750 50  0000 C CNN
	1    4500 4750
	-1   0    0    1   
$EndComp
Wire Wire Line
	4300 4600 4450 4600
Wire Wire Line
	4500 4900 4500 5050
Wire Wire Line
	4500 5050 4750 5050
Connection ~ 4750 5050
Wire Wire Line
	5000 4800 5000 4950
Text Notes 3250 3350 0    60   ~ 0
HIGHPASS - in MODE 3!\nor should it be bandpass
Text Notes 1550 1000 0    60   ~ 0
input for lower 7490
$Comp
L allcolours-rescue:TL072-linear U?
U 2 1 5B6FD0C0
P 1850 1650
AR Path="/5B6FD0C0" Ref="U?"  Part="2" 
AR Path="/5B6C330C/5B6FD0C0" Ref="U11"  Part="2" 
F 0 "U11" H 2191 1696 50  0000 L CNN
F 1 "TL072" H 2191 1605 50  0000 L CNN
F 2 "" H 1850 1650 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 1850 1650 50  0001 C CNN
	2    1850 1650
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR?
U 1 1 5B6FD0C7
P 1750 1300
AR Path="/5B6FD0C7" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B6FD0C7" Ref="#PWR087"  Part="1" 
F 0 "#PWR087" H 1750 1150 50  0001 C CNN
F 1 "+12V" H 1750 1440 50  0000 C CNN
F 2 "" H 1750 1300 50  0000 C CNN
F 3 "" H 1750 1300 50  0000 C CNN
	1    1750 1300
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR?
U 1 1 5B6FD0CD
P 1750 2000
AR Path="/5B6FD0CD" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B6FD0CD" Ref="#PWR088"  Part="1" 
F 0 "#PWR088" H 1750 1850 50  0001 C CNN
F 1 "-12VA" H 1750 2140 50  0000 C CNN
F 2 "" H 1750 2000 50  0000 C CNN
F 3 "" H 1750 2000 50  0000 C CNN
	1    1750 2000
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B6FD0D3
P 1250 1750
AR Path="/5B6FD0D3" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B6FD0D3" Ref="R47"  Part="1" 
F 0 "R47" V 1330 1750 50  0000 C CNN
F 1 "10K" V 1250 1750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1180 1750 50  0001 C CNN
F 3 "" H 1250 1750 50  0000 C CNN
	1    1250 1750
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B6FD0DA
P 1750 2200
AR Path="/5B6FD0DA" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B6FD0DA" Ref="R48"  Part="1" 
F 0 "R48" V 1830 2200 50  0000 C CNN
F 1 "2.7K" V 1750 2200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1680 2200 50  0001 C CNN
F 3 "" H 1750 2200 50  0000 C CNN
	1    1750 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 1750 1500 1750
Wire Wire Line
	1600 2200 1600 2050
Wire Wire Line
	1600 2050 1500 2050
Wire Wire Line
	1500 2050 1500 1750
Connection ~ 1500 1750
Wire Wire Line
	1500 1750 1550 1750
Wire Wire Line
	1900 2200 2150 2200
Wire Wire Line
	2150 2200 2150 1650
$Comp
L allcolours-rescue:CP1_Small-device C?
U 1 1 5B6FD0E9
P 2350 1650
AR Path="/5B6FD0E9" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B6FD0E9" Ref="C35"  Part="1" 
F 0 "C35" H 2360 1720 50  0000 L CNN
F 1 "10u" H 2360 1570 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 2350 1650 50  0001 C CNN
F 3 "" H 2350 1650 50  0000 C CNN
	1    2350 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2150 1650 2250 1650
Connection ~ 2150 1650
Text Notes 2325 3700 0    60   ~ 0
value?
Wire Wire Line
	1750 1350 1750 1300
Wire Wire Line
	1750 2000 1750 1950
$Comp
L allcolours-rescue:CP1_Small-device C?
U 1 1 5B705C47
P 6050 1600
AR Path="/5B705C47" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B705C47" Ref="C39"  Part="1" 
F 0 "C39" H 6060 1670 50  0000 L CNN
F 1 "10u" H 6060 1520 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 6050 1600 50  0001 C CNN
F 3 "" H 6050 1600 50  0000 C CNN
	1    6050 1600
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B705C4E
P 6350 1600
AR Path="/5B705C4E" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B705C4E" Ref="R58"  Part="1" 
F 0 "R58" V 6430 1600 50  0000 C CNN
F 1 "5.6K" V 6350 1600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6280 1600 50  0001 C CNN
F 3 "" H 6350 1600 50  0000 C CNN
	1    6350 1600
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B705C55
P 6200 1900
AR Path="/5B705C55" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B705C55" Ref="R57"  Part="1" 
F 0 "R57" V 6280 1900 50  0000 C CNN
F 1 "39K" V 6200 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6130 1900 50  0001 C CNN
F 3 "" H 6200 1900 50  0000 C CNN
	1    6200 1900
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B705C5C
P 6900 950
AR Path="/5B705C5C" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B705C5C" Ref="R61"  Part="1" 
F 0 "R61" V 6980 950 50  0000 C CNN
F 1 "39K" V 6900 950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6830 950 50  0001 C CNN
F 3 "" H 6900 950 50  0000 C CNN
	1    6900 950 
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:C-device C?
U 1 1 5B705C63
P 6900 1100
AR Path="/5B705C63" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B705C63" Ref="C41"  Part="1" 
F 0 "C41" H 6925 1200 50  0000 L CNN
F 1 "18p" H 6925 1000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6938 950 50  0001 C CNN
F 3 "" H 6900 1100 50  0000 C CNN
	1    6900 1100
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR?
U 1 1 5B705C6A
P 6200 2100
AR Path="/5B705C6A" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B705C6A" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 6200 1850 50  0001 C CNN
F 1 "GND" H 6200 1950 50  0000 C CNN
F 2 "" H 6200 2100 50  0000 C CNN
F 3 "" H 6200 2100 50  0000 C CNN
	1    6200 2100
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR?
U 1 1 5B705C70
P 6500 1400
AR Path="/5B705C70" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B705C70" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 6500 1150 50  0001 C CNN
F 1 "GND" H 6500 1250 50  0000 C CNN
F 2 "" H 6500 1400 50  0000 C CNN
F 3 "" H 6500 1400 50  0000 C CNN
	1    6500 1400
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR?
U 1 1 5B705C77
P 6800 1900
AR Path="/5B705C77" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B705C77" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 6800 1750 50  0001 C CNN
F 1 "-12VA" H 6800 2040 50  0000 C CNN
F 2 "" H 6800 1900 50  0000 C CNN
F 3 "" H 6800 1900 50  0000 C CNN
	1    6800 1900
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR?
U 1 1 5B705C7D
P 6750 850
AR Path="/5B705C7D" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B705C7D" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 6750 700 50  0001 C CNN
F 1 "+12V" H 6750 990 50  0000 C CNN
F 2 "" H 6750 850 50  0000 C CNN
F 3 "" H 6750 850 50  0000 C CNN
	1    6750 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1600 6200 1600
Wire Wire Line
	6200 1600 6200 1750
Wire Wire Line
	6200 2100 6200 2050
Wire Wire Line
	6550 950  6550 1100
Wire Wire Line
	6550 1100 6750 1100
Wire Wire Line
	6550 950  6750 950 
Connection ~ 6550 1100
Wire Wire Line
	7050 950  7050 1100
Wire Wire Line
	7050 1100 7200 1100
Wire Wire Line
	7200 1100 7200 1500
Wire Wire Line
	7200 1500 7700 1500
Wire Wire Line
	6800 1800 6800 1900
Wire Wire Line
	6800 1200 6750 1200
Wire Wire Line
	6750 1200 6750 1100
Wire Wire Line
	6500 1400 6550 1400
Text Notes 5950 -100 0    60   ~ 0
out from 7490 - these values adapted from 3.3v - 12v schema\nso might need to be changed
Text Notes 6050 1950 0    60   ~ 0
?
Wire Wire Line
	6550 1100 6550 1400
Connection ~ 6200 1600
Connection ~ 6750 950 
Wire Wire Line
	6750 950  6750 850 
Connection ~ 6750 1100
Wire Wire Line
	6750 1100 6750 950 
Connection ~ 7050 1100
$Comp
L allcolours-rescue:TL072-linear U?
U 1 1 5B705C9B
P 6900 1500
AR Path="/5B705C9B" Ref="U?"  Part="2" 
AR Path="/5B6C330C/5B705C9B" Ref="U13"  Part="1" 
F 0 "U13" H 7241 1546 50  0000 L CNN
F 1 "TL072" H 7241 1455 50  0000 L CNN
F 2 "" H 6900 1500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6900 1500 50  0001 C CNN
	1    6900 1500
	1    0    0    -1  
$EndComp
Connection ~ 6550 1400
Wire Wire Line
	6550 1400 6600 1400
Connection ~ 7200 1500
Wire Wire Line
	6500 1600 6600 1600
Text GLabel 5300 4950 2    118  Input ~ 0
PWM_OUT
Wire Wire Line
	5000 4800 5000 4650
Wire Wire Line
	5000 4650 5200 4650
Connection ~ 5000 4800
Wire Wire Line
	5000 4950 5300 4950
Text Notes 7300 900  0    197  ~ 0
2x for HP and LP
Wire Wire Line
	2450 1650 2650 1650
Text Label 2650 1650 0    79   ~ 0
7490_IN_LOW
Wire Wire Line
	1100 1750 950  1750
Text GLabel 7700 1500 2    197  Input ~ 0
7490_OUT_HP
Text GLabel 5200 4650 2    118  Input ~ 0
7490_CLOCK
Text Notes 5050 4500 0    118  ~ 0
from comparator\n
Text Notes 5450 5200 0    118  ~ 0
direct from avr
Text Notes 5100 5750 0    118  ~ 0
same clock or?
Wire Wire Line
	4300 4500 4450 4500
Wire Wire Line
	4450 4500 4450 4600
Connection ~ 4450 4600
Wire Wire Line
	4450 4600 4500 4600
Wire Wire Line
	4500 4600 4550 4600
Connection ~ 4500 4600
Text Label 4550 4600 0    60   ~ 0
COM
Wire Wire Line
	2800 4500 2650 4500
Text Label 2650 4500 0    60   ~ 0
COM
Wire Wire Line
	4300 4800 4400 4800
Wire Wire Line
	4400 4800 4400 5250
Connection ~ 4400 4800
Wire Wire Line
	4400 4800 4750 4800
Text Label 4400 5250 0    60   ~ 0
CLOCK
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B7D3CA7
P 2550 4400
AR Path="/5B7D3CA7" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D3CA7" Ref="R52"  Part="1" 
F 0 "R52" V 2630 4400 50  0000 C CNN
F 1 "R1" V 2550 4400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2480 4400 50  0001 C CNN
F 3 "" H 2550 4400 50  0000 C CNN
	1    2550 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 4400 2800 4400
Wire Wire Line
	2400 4400 2250 4400
Text Label 2250 4400 2    60   ~ 0
7490_IN_LOW
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B7D5D40
P 3550 3600
AR Path="/5B7D5D40" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D5D40" Ref="R53"  Part="1" 
F 0 "R53" V 3630 3600 50  0000 C CNN
F 1 "R1" V 3550 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3480 3600 50  0001 C CNN
F 3 "" H 3550 3600 50  0000 C CNN
	1    3550 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 4300 2700 3950
Wire Wire Line
	2700 3600 3400 3600
Wire Wire Line
	3700 3600 4500 3600
Wire Wire Line
	4500 3600 4500 4400
Wire Wire Line
	4500 4400 4300 4400
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B7D8C95
P 2550 4100
AR Path="/5B7D8C95" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D8C95" Ref="R51"  Part="1" 
F 0 "R51" V 2630 4100 50  0000 C CNN
F 1 "R2" V 2550 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2480 4100 50  0001 C CNN
F 3 "" H 2550 4100 50  0000 C CNN
	1    2550 4100
	-1   0    0    1   
$EndComp
Wire Wire Line
	2700 4300 2800 4300
Wire Wire Line
	2550 3950 2700 3950
Connection ~ 2700 3950
Wire Wire Line
	2700 3950 2700 3600
Wire Wire Line
	2550 4250 2650 4250
Wire Wire Line
	2650 4250 2650 4350
Wire Wire Line
	2650 4350 2700 4350
Wire Wire Line
	2700 4350 2700 4400
Connection ~ 2700 4400
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B7DE33A
P 2400 4100
AR Path="/5B7DE33A" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7DE33A" Ref="R50"  Part="1" 
F 0 "R50" V 2480 4100 50  0000 C CNN
F 1 "R3" V 2400 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2330 4100 50  0001 C CNN
F 3 "" H 2400 4100 50  0000 C CNN
	1    2400 4100
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B7DE3BC
P 2250 4100
AR Path="/5B7DE3BC" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7DE3BC" Ref="R49"  Part="1" 
F 0 "R49" V 2330 4100 50  0000 C CNN
F 1 "R4" V 2250 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2180 4100 50  0001 C CNN
F 3 "" H 2250 4100 50  0000 C CNN
	1    2250 4100
	-1   0    0    1   
$EndComp
Wire Wire Line
	5950 1600 5750 1600
Text Label 5750 1600 2    60   ~ 0
7490_HP
Wire Wire Line
	4300 4300 4550 4300
Text Label 4650 4300 0    60   ~ 0
7490_HP
Wire Wire Line
	2800 4100 2800 3850
Wire Wire Line
	2800 3850 2400 3850
Wire Wire Line
	2400 3850 2400 3950
Wire Wire Line
	2800 4200 2750 4200
Wire Wire Line
	2750 4200 2750 3750
Wire Wire Line
	2750 3750 2250 3750
Wire Wire Line
	2250 3750 2250 3950
Wire Wire Line
	2250 4250 2400 4250
Wire Wire Line
	2400 4250 2550 4250
Connection ~ 2400 4250
Connection ~ 2550 4250
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B7EAA51
P 4650 4050
AR Path="/5B7EAA51" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAA51" Ref="R54"  Part="1" 
F 0 "R54" V 4730 4050 50  0000 C CNN
F 1 "R2" V 4650 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4580 4050 50  0001 C CNN
F 3 "" H 4650 4050 50  0000 C CNN
	1    4650 4050
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B7EAB16
P 4800 4050
AR Path="/5B7EAB16" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAB16" Ref="R55"  Part="1" 
F 0 "R55" V 4880 4050 50  0000 C CNN
F 1 "R3" V 4800 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4730 4050 50  0001 C CNN
F 3 "" H 4800 4050 50  0000 C CNN
	1    4800 4050
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B7EAB84
P 4950 4050
AR Path="/5B7EAB84" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAB84" Ref="R56"  Part="1" 
F 0 "R56" V 5030 4050 50  0000 C CNN
F 1 "R4" V 4950 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4880 4050 50  0001 C CNN
F 3 "" H 4950 4050 50  0000 C CNN
	1    4950 4050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4650 4200 4800 4200
Wire Wire Line
	4950 4200 4800 4200
Connection ~ 4800 4200
Wire Wire Line
	4500 4400 4650 4400
Wire Wire Line
	4650 4400 4650 4350
Wire Wire Line
	4650 4350 4800 4350
Wire Wire Line
	4800 4350 4800 4200
Connection ~ 4500 4400
Wire Wire Line
	4550 4300 4550 3900
Wire Wire Line
	4550 3900 4650 3900
Connection ~ 4550 4300
Wire Wire Line
	4550 4300 4650 4300
Wire Wire Line
	4300 4200 4450 4200
Wire Wire Line
	4450 4200 4450 3850
Wire Wire Line
	4450 3850 4800 3850
Wire Wire Line
	4800 3850 4800 3900
Wire Wire Line
	4950 3900 4950 3800
Wire Wire Line
	4950 3800 4350 3800
Wire Wire Line
	4350 3800 4350 4100
Wire Wire Line
	4350 4100 4300 4100
Text Notes 3100 5500 0    60   ~ 0
7400 for low pass
$Comp
L all_colours:maxim_7400 U10
U 1 1 5B827130
P 3600 6000
F 0 "U10" H 3550 6147 60  0000 C CNN
F 1 "maxim_7400" H 3550 6041 60  0000 C CNN
F 2 "" H 3600 6000 60  0001 C CNN
F 3 "" H 3600 6000 60  0001 C CNN
	1    3600 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 6100 4400 6100
Text Label 4400 6100 0    60   ~ 0
CLOCK
$Comp
L allcolours-rescue:GND-power #PWR097
U 1 1 5B82ACD0
P 2800 6300
F 0 "#PWR097" H 2800 6050 50  0001 C CNN
F 1 "GND" H 2800 6150 50  0000 C CNN
F 2 "" H 2800 6300 50  0000 C CNN
F 3 "" H 2800 6300 50  0000 C CNN
	1    2800 6300
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power #PWR098
U 1 1 5B82AD0B
P 2850 6650
F 0 "#PWR098" H 2850 6500 50  0001 C CNN
F 1 "+5V" H 2865 6823 50  0000 C CNN
F 2 "" H 2850 6650 50  0001 C CNN
F 3 "" H 2850 6650 50  0001 C CNN
	1    2850 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 6400 3150 6650
Wire Wire Line
	3900 6200 4250 6200
Wire Wire Line
	4250 6200 4250 6650
Wire Wire Line
	2850 6650 3150 6650
Connection ~ 3150 6650
Wire Wire Line
	3150 6650 4250 6650
Wire Wire Line
	3150 6200 2900 6200
Wire Wire Line
	2900 6200 2900 6100
Wire Wire Line
	2900 6100 2600 6100
Text Label 2600 6100 2    60   ~ 0
7490_IN_LOW
$Comp
L allcolours-rescue:C-device C36
U 1 1 5B836AA8
P 2350 6500
F 0 "C36" H 2375 6600 50  0000 L CNN
F 1 "100N" H 2375 6400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2388 6350 50  0001 C CNN
F 3 "" H 2350 6500 50  0000 C CNN
	1    2350 6500
	-1   0    0    1   
$EndComp
Wire Wire Line
	3150 6300 2800 6300
$Comp
L allcolours-rescue:GND-power #PWR094
U 1 1 5B83A4B5
P 2350 6700
F 0 "#PWR094" H 2350 6450 50  0001 C CNN
F 1 "GND" H 2350 6550 50  0000 C CNN
F 2 "" H 2350 6700 50  0000 C CNN
F 3 "" H 2350 6700 50  0000 C CNN
	1    2350 6700
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power #PWR093
U 1 1 5B83A4F2
P 2350 6300
F 0 "#PWR093" H 2350 6150 50  0001 C CNN
F 1 "+5V" H 2365 6473 50  0000 C CNN
F 2 "" H 2350 6300 50  0001 C CNN
F 3 "" H 2350 6300 50  0001 C CNN
	1    2350 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 6300 2350 6350
Wire Wire Line
	2350 6650 2350 6700
$Comp
L allcolours-rescue:C-device C33
U 1 1 5B841AB5
P 1900 6500
F 0 "C33" H 1925 6600 50  0000 L CNN
F 1 "100N" H 1925 6400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1938 6350 50  0001 C CNN
F 3 "" H 1900 6500 50  0000 C CNN
	1    1900 6500
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR090
U 1 1 5B841ABB
P 1900 6700
F 0 "#PWR090" H 1900 6450 50  0001 C CNN
F 1 "GND" H 1900 6550 50  0000 C CNN
F 2 "" H 1900 6700 50  0000 C CNN
F 3 "" H 1900 6700 50  0000 C CNN
	1    1900 6700
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power #PWR089
U 1 1 5B841AC1
P 1900 6300
F 0 "#PWR089" H 1900 6150 50  0001 C CNN
F 1 "+5V" H 1915 6473 50  0000 C CNN
F 2 "" H 1900 6300 50  0001 C CNN
F 3 "" H 1900 6300 50  0001 C CNN
	1    1900 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6300 1900 6350
Wire Wire Line
	1900 6650 1900 6700
$Comp
L allcolours-rescue:C-device C34
U 1 1 5B845936
P 2150 5000
F 0 "C34" H 2175 5100 50  0000 L CNN
F 1 "100N" H 2175 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2188 4850 50  0001 C CNN
F 3 "" H 2150 5000 50  0000 C CNN
	1    2150 5000
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR092
U 1 1 5B84593C
P 2150 5200
F 0 "#PWR092" H 2150 4950 50  0001 C CNN
F 1 "GND" H 2150 5050 50  0000 C CNN
F 2 "" H 2150 5200 50  0000 C CNN
F 3 "" H 2150 5200 50  0000 C CNN
	1    2150 5200
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power #PWR091
U 1 1 5B845942
P 2150 4800
F 0 "#PWR091" H 2150 4650 50  0001 C CNN
F 1 "+5V" H 2165 4973 50  0000 C CNN
F 2 "" H 2150 4800 50  0001 C CNN
F 3 "" H 2150 4800 50  0001 C CNN
	1    2150 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 4800 2150 4850
Wire Wire Line
	2150 5150 2150 5200
$Comp
L allcolours-rescue:C-device C32
U 1 1 5B84594A
P 1700 5000
F 0 "C32" H 1725 5100 50  0000 L CNN
F 1 "100N" H 1725 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1738 4850 50  0001 C CNN
F 3 "" H 1700 5000 50  0000 C CNN
	1    1700 5000
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR086
U 1 1 5B845950
P 1700 5200
F 0 "#PWR086" H 1700 4950 50  0001 C CNN
F 1 "GND" H 1700 5050 50  0000 C CNN
F 2 "" H 1700 5200 50  0000 C CNN
F 3 "" H 1700 5200 50  0000 C CNN
	1    1700 5200
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power #PWR085
U 1 1 5B845956
P 1700 4800
F 0 "#PWR085" H 1700 4650 50  0001 C CNN
F 1 "+5V" H 1715 4973 50  0000 C CNN
F 2 "" H 1700 4800 50  0001 C CNN
F 3 "" H 1700 4800 50  0001 C CNN
	1    1700 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4800 1700 4850
Wire Wire Line
	1700 5150 1700 5200
$Comp
L allcolours-rescue:C-device C37
U 1 1 5B84A5AB
P 2950 5650
F 0 "C37" H 2975 5750 50  0000 L CNN
F 1 "100N" H 2975 5550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2988 5500 50  0001 C CNN
F 3 "" H 2950 5650 50  0000 C CNN
	1    2950 5650
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR099
U 1 1 5B84A6E3
P 2950 5850
F 0 "#PWR099" H 2950 5600 50  0001 C CNN
F 1 "GND" H 2950 5700 50  0000 C CNN
F 2 "" H 2950 5850 50  0000 C CNN
F 3 "" H 2950 5850 50  0000 C CNN
	1    2950 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 6100 3150 5800
Wire Wire Line
	3150 5500 2950 5500
Wire Wire Line
	2950 5800 2950 5850
Wire Wire Line
	4000 6300 4000 5800
Wire Wire Line
	4000 5800 3150 5800
Wire Wire Line
	3900 6300 4000 6300
Connection ~ 3150 5800
Wire Wire Line
	3150 5800 3150 5500
Wire Wire Line
	3900 6400 4400 6400
Text Label 4400 6400 0    60   ~ 0
7400_LP
$Comp
L allcolours-rescue:CP1_Small-device C?
U 1 1 5B85D9A3
P 6350 3350
AR Path="/5B85D9A3" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B85D9A3" Ref="C40"  Part="1" 
F 0 "C40" H 6360 3420 50  0000 L CNN
F 1 "10u" H 6360 3270 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 6350 3350 50  0001 C CNN
F 3 "" H 6350 3350 50  0000 C CNN
	1    6350 3350
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B85D9A9
P 6650 3350
AR Path="/5B85D9A9" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B85D9A9" Ref="R60"  Part="1" 
F 0 "R60" V 6730 3350 50  0000 C CNN
F 1 "5.6K" V 6650 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6580 3350 50  0001 C CNN
F 3 "" H 6650 3350 50  0000 C CNN
	1    6650 3350
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B85D9AF
P 6500 3650
AR Path="/5B85D9AF" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B85D9AF" Ref="R59"  Part="1" 
F 0 "R59" V 6580 3650 50  0000 C CNN
F 1 "39K" V 6500 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6430 3650 50  0001 C CNN
F 3 "" H 6500 3650 50  0000 C CNN
	1    6500 3650
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device R?
U 1 1 5B85D9B5
P 7200 2700
AR Path="/5B85D9B5" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B85D9B5" Ref="R62"  Part="1" 
F 0 "R62" V 7280 2700 50  0000 C CNN
F 1 "39K" V 7200 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7130 2700 50  0001 C CNN
F 3 "" H 7200 2700 50  0000 C CNN
	1    7200 2700
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:C-device C?
U 1 1 5B85D9BB
P 7200 2850
AR Path="/5B85D9BB" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B85D9BB" Ref="C42"  Part="1" 
F 0 "C42" H 7225 2950 50  0000 L CNN
F 1 "18p" H 7225 2750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7238 2700 50  0001 C CNN
F 3 "" H 7200 2850 50  0000 C CNN
	1    7200 2850
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR?
U 1 1 5B85D9C1
P 6500 3850
AR Path="/5B85D9C1" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B85D9C1" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 6500 3600 50  0001 C CNN
F 1 "GND" H 6500 3700 50  0000 C CNN
F 2 "" H 6500 3850 50  0000 C CNN
F 3 "" H 6500 3850 50  0000 C CNN
	1    6500 3850
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR?
U 1 1 5B85D9C7
P 6800 3150
AR Path="/5B85D9C7" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B85D9C7" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 6800 2900 50  0001 C CNN
F 1 "GND" H 6800 3000 50  0000 C CNN
F 2 "" H 6800 3150 50  0000 C CNN
F 3 "" H 6800 3150 50  0000 C CNN
	1    6800 3150
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR?
U 1 1 5B85D9CD
P 7100 3650
AR Path="/5B85D9CD" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B85D9CD" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 7100 3500 50  0001 C CNN
F 1 "-12VA" H 7100 3790 50  0000 C CNN
F 2 "" H 7100 3650 50  0000 C CNN
F 3 "" H 7100 3650 50  0000 C CNN
	1    7100 3650
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR?
U 1 1 5B85D9D3
P 7050 2600
AR Path="/5B85D9D3" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B85D9D3" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 7050 2450 50  0001 C CNN
F 1 "+12V" H 7050 2740 50  0000 C CNN
F 2 "" H 7050 2600 50  0000 C CNN
F 3 "" H 7050 2600 50  0000 C CNN
	1    7050 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3350 6500 3350
Wire Wire Line
	6500 3350 6500 3500
Wire Wire Line
	6500 3850 6500 3800
Wire Wire Line
	6850 2700 6850 2850
Wire Wire Line
	6850 2850 7050 2850
Wire Wire Line
	6850 2700 7050 2700
Connection ~ 6850 2850
Wire Wire Line
	7350 2700 7350 2850
Wire Wire Line
	7350 2850 7500 2850
Wire Wire Line
	7500 2850 7500 3250
Wire Wire Line
	7500 3250 8000 3250
Wire Wire Line
	7100 3550 7100 3650
Wire Wire Line
	7100 2950 7050 2950
Wire Wire Line
	7050 2950 7050 2850
Wire Wire Line
	6800 3150 6850 3150
Text Notes 6350 3700 0    60   ~ 0
?
Wire Wire Line
	6850 2850 6850 3150
Connection ~ 6500 3350
Connection ~ 7050 2700
Wire Wire Line
	7050 2700 7050 2600
Connection ~ 7050 2850
Wire Wire Line
	7050 2850 7050 2700
Connection ~ 7350 2850
$Comp
L allcolours-rescue:TL072-linear U?
U 2 1 5B85D9F0
P 7200 3250
AR Path="/5B85D9F0" Ref="U?"  Part="2" 
AR Path="/5B6C330C/5B85D9F0" Ref="U13"  Part="2" 
F 0 "U13" H 7541 3296 50  0000 L CNN
F 1 "TL072" H 7541 3205 50  0000 L CNN
F 2 "" H 7200 3250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 7200 3250 50  0001 C CNN
	2    7200 3250
	1    0    0    -1  
$EndComp
Connection ~ 6850 3150
Wire Wire Line
	6850 3150 6900 3150
Connection ~ 7500 3250
Wire Wire Line
	6800 3350 6900 3350
Text Notes 7600 2650 0    197  ~ 0
2x for HP and LP
Text GLabel 8000 3250 2    197  Input ~ 0
7400_OUT_LP
Wire Wire Line
	6250 3350 6050 3350
Text Label 6050 3350 2    60   ~ 0
7400_LP
Text Label 950  1750 2    60   ~ 0
FILTER_IN
Text Notes 6500 4850 0    60   ~ 0
will comp interfere with pwm?
Text Notes 925  2475 0    60   ~ 0
filter in path normalized to 4053 switched noise in TODO
$EndSCHEMATC
