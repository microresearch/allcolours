EESchema Schematic File Version 4
LIBS:allcolours-cache
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
$Comp
L allcolours-rescue:D_Zener_Small-device-allcolours-rescue D5
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
L allcolours-rescue:D_Zener_Small-device-allcolours-rescue D4
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
L allcolours-rescue:GND-power-allcolours-rescue #PWR0101
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
L allcolours-rescue:MAX7490-MAX7490 U8
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
L allcolours-rescue:+5V-power-allcolours-rescue #PWR0100
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
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR095
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
L allcolours-rescue:GND-power-allcolours-rescue #PWR096
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
L allcolours-rescue:C-device-allcolours-rescue C38
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
Text Notes 3250 3350 0    60   ~ 0
HIGHPASS - in MODE 3!\n
Text Notes 6800 3950 0    60   ~ 0
input for lower 7490
$Comp
L allcolours-rescue:TL072-linear-allcolours-rescue U?
U 2 1 5B6FD0C0
P 7100 4600
AR Path="/5B6FD0C0" Ref="U?"  Part="2" 
AR Path="/5B6C330C/5B6FD0C0" Ref="U11"  Part="2" 
F 0 "U11" H 7441 4646 50  0000 L CNN
F 1 "TL072" H 7441 4555 50  0000 L CNN
F 2 "" H 7100 4600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 7100 4600 50  0001 C CNN
	2    7100 4600
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR?
U 1 1 5B6FD0C7
P 7000 4250
AR Path="/5B6FD0C7" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B6FD0C7" Ref="#PWR087"  Part="1" 
F 0 "#PWR087" H 7000 4100 50  0001 C CNN
F 1 "+12V" H 7000 4390 50  0000 C CNN
F 2 "" H 7000 4250 50  0000 C CNN
F 3 "" H 7000 4250 50  0000 C CNN
	1    7000 4250
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power-allcolours-rescue #PWR?
U 1 1 5B6FD0CD
P 7000 4950
AR Path="/5B6FD0CD" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B6FD0CD" Ref="#PWR088"  Part="1" 
F 0 "#PWR088" H 7000 4800 50  0001 C CNN
F 1 "-12VA" H 7000 5090 50  0000 C CNN
F 2 "" H 7000 4950 50  0000 C CNN
F 3 "" H 7000 4950 50  0000 C CNN
	1    7000 4950
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B6FD0D3
P 6500 4700
AR Path="/5B6FD0D3" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B6FD0D3" Ref="R47"  Part="1" 
F 0 "R47" V 6580 4700 50  0000 C CNN
F 1 "10K" V 6500 4700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6430 4700 50  0001 C CNN
F 3 "" H 6500 4700 50  0000 C CNN
	1    6500 4700
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B6FD0DA
P 7000 5150
AR Path="/5B6FD0DA" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B6FD0DA" Ref="R48"  Part="1" 
F 0 "R48" V 7080 5150 50  0000 C CNN
F 1 "2.7K" V 7000 5150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6930 5150 50  0001 C CNN
F 3 "" H 7000 5150 50  0000 C CNN
	1    7000 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	6650 4700 6750 4700
Wire Wire Line
	6850 5150 6850 5000
Wire Wire Line
	6850 5000 6750 5000
Wire Wire Line
	6750 5000 6750 4700
Connection ~ 6750 4700
Wire Wire Line
	6750 4700 6800 4700
Wire Wire Line
	7150 5150 7400 5150
Wire Wire Line
	7400 5150 7400 4600
$Comp
L allcolours-rescue:CP1_Small-device-allcolours-rescue C?
U 1 1 5B6FD0E9
P 7600 4600
AR Path="/5B6FD0E9" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B6FD0E9" Ref="C35"  Part="1" 
F 0 "C35" H 7610 4670 50  0000 L CNN
F 1 "10u" H 7610 4520 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 7600 4600 50  0001 C CNN
F 3 "" H 7600 4600 50  0000 C CNN
	1    7600 4600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7400 4600 7500 4600
Connection ~ 7400 4600
Wire Wire Line
	7000 4300 7000 4250
Wire Wire Line
	7000 4950 7000 4900
$Comp
L allcolours-rescue:CP1_Small-device-allcolours-rescue C?
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
L allcolours-rescue:R-device-allcolours-rescue R?
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
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B705C55
P 6200 1900
AR Path="/5B705C55" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B705C55" Ref="R57"  Part="1" 
F 0 "R57" V 6280 1900 50  0000 C CNN
F 1 "24K" V 6200 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6130 1900 50  0001 C CNN
F 3 "" H 6200 1900 50  0000 C CNN
	1    6200 1900
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B705C5C
P 6900 950
AR Path="/5B705C5C" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B705C5C" Ref="R61"  Part="1" 
F 0 "R61" V 6980 950 50  0000 C CNN
F 1 "24K" V 6900 950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6830 950 50  0001 C CNN
F 3 "" H 6900 950 50  0000 C CNN
	1    6900 950 
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C?
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
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
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
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
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
L allcolours-rescue:-12VA-power-allcolours-rescue #PWR?
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
L allcolours-rescue:+12V-power-allcolours-rescue #PWR?
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
	7200 1500 7325 1500
Wire Wire Line
	6800 1800 6800 1900
Wire Wire Line
	6800 1200 6750 1200
Wire Wire Line
	6500 1400 6550 1400
Text Notes 6050 1950 0    60   ~ 0
?
Wire Wire Line
	6550 1100 6550 1400
Connection ~ 6200 1600
Connection ~ 7050 1100
$Comp
L allcolours-rescue:TL072-linear-allcolours-rescue U?
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
Wire Wire Line
	7700 4600 7900 4600
Text Label 7900 4600 0    79   ~ 0
7490_IN_LOW
Wire Wire Line
	6350 4700 6200 4700
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
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7D3CA7
P 2550 4400
AR Path="/5B7D3CA7" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D3CA7" Ref="R52"  Part="1" 
F 0 "R52" V 2630 4400 50  0000 C CNN
F 1 "200K" V 2550 4400 50  0000 C CNN
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
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7D5D40
P 3550 3600
AR Path="/5B7D5D40" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D5D40" Ref="R53"  Part="1" 
F 0 "R53" V 3630 3600 50  0000 C CNN
F 1 "200K" V 3550 3600 50  0000 C CNN
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
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7D8C95
P 2550 4100
AR Path="/5B7D8C95" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D8C95" Ref="R51"  Part="1" 
F 0 "R51" V 2630 4100 50  0000 C CNN
F 1 "10K" V 2550 4100 50  0000 C CNN
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
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7DE33A
P 2400 4100
AR Path="/5B7DE33A" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7DE33A" Ref="R50"  Part="1" 
F 0 "R50" V 2480 4100 50  0000 C CNN
F 1 "200K" V 2400 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2330 4100 50  0001 C CNN
F 3 "" H 2400 4100 50  0000 C CNN
	1    2400 4100
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7DE3BC
P 2250 4100
AR Path="/5B7DE3BC" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7DE3BC" Ref="R49"  Part="1" 
F 0 "R49" V 2330 4100 50  0000 C CNN
F 1 "10K" V 2250 4100 50  0000 C CNN
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
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7EAA51
P 4650 4050
AR Path="/5B7EAA51" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAA51" Ref="R54"  Part="1" 
F 0 "R54" V 4730 4050 50  0000 C CNN
F 1 "10K" V 4650 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4580 4050 50  0001 C CNN
F 3 "" H 4650 4050 50  0000 C CNN
	1    4650 4050
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7EAB16
P 4800 4050
AR Path="/5B7EAB16" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAB16" Ref="R55"  Part="1" 
F 0 "R55" V 4880 4050 50  0000 C CNN
F 1 "200K" V 4800 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4730 4050 50  0001 C CNN
F 3 "" H 4800 4050 50  0000 C CNN
	1    4800 4050
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7EAB84
P 4950 4050
AR Path="/5B7EAB84" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAB84" Ref="R56"  Part="1" 
F 0 "R56" V 5030 4050 50  0000 C CNN
F 1 "10K" V 4950 4050 50  0000 C CNN
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
L allcolours-rescue:maxim_7400-all_colours U10
U 1 1 5B827130
P 3600 6000
F 0 "U10" H 3550 6147 60  0000 C CNN
F 1 "maxim_7400" H 3550 6041 60  0000 C CNN
F 2 "" H 3600 6000 60  0001 C CNN
F 3 "" H 3600 6000 60  0001 C CNN
	1    3600 6000
	1    0    0    -1  
$EndComp
Text Label 4400 6100 0    60   ~ 0
CLOCK
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR097
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
L allcolours-rescue:+5V-power-allcolours-rescue #PWR098
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
	4250 6200 4250 6650
Wire Wire Line
	2850 6650 3150 6650
Connection ~ 3150 6650
Wire Wire Line
	3150 6650 4250 6650
Wire Wire Line
	2900 6200 2900 6100
Wire Wire Line
	2900 6100 2600 6100
Text Label 2600 6100 2    60   ~ 0
7490_IN_LOW
$Comp
L allcolours-rescue:C-device-allcolours-rescue C36
U 1 1 5B836AA8
P 2350 6500
F 0 "C36" H 2375 6600 50  0000 L CNN
F 1 "100N" H 2375 6400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2388 6350 50  0001 C CNN
F 3 "" H 2350 6500 50  0000 C CNN
	1    2350 6500
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR094
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
L allcolours-rescue:+5V-power-allcolours-rescue #PWR093
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
L allcolours-rescue:C-device-allcolours-rescue C33
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
L allcolours-rescue:GND-power-allcolours-rescue #PWR090
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
L allcolours-rescue:+5V-power-allcolours-rescue #PWR089
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
L allcolours-rescue:C-device-allcolours-rescue C34
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
L allcolours-rescue:GND-power-allcolours-rescue #PWR092
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
L allcolours-rescue:+5V-power-allcolours-rescue #PWR091
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
L allcolours-rescue:C-device-allcolours-rescue C32
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
L allcolours-rescue:GND-power-allcolours-rescue #PWR086
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
L allcolours-rescue:+5V-power-allcolours-rescue #PWR085
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
L allcolours-rescue:C-device-allcolours-rescue C37
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
L allcolours-rescue:GND-power-allcolours-rescue #PWR099
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
Connection ~ 3150 5800
Wire Wire Line
	3150 5800 3150 5500
Text Label 4400 6400 0    60   ~ 0
7400_LP
$Comp
L allcolours-rescue:CP1_Small-device-allcolours-rescue C?
U 1 1 5B85D9A3
P 5825 3075
AR Path="/5B85D9A3" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B85D9A3" Ref="C40"  Part="1" 
F 0 "C40" H 5835 3145 50  0000 L CNN
F 1 "10u" H 5835 2995 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 5825 3075 50  0001 C CNN
F 3 "" H 5825 3075 50  0000 C CNN
	1    5825 3075
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B85D9A9
P 6125 3075
AR Path="/5B85D9A9" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B85D9A9" Ref="R60"  Part="1" 
F 0 "R60" V 6205 3075 50  0000 C CNN
F 1 "5.6K" V 6125 3075 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6055 3075 50  0001 C CNN
F 3 "" H 6125 3075 50  0000 C CNN
	1    6125 3075
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B85D9AF
P 5975 3375
AR Path="/5B85D9AF" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B85D9AF" Ref="R59"  Part="1" 
F 0 "R59" V 6055 3375 50  0000 C CNN
F 1 "24K" V 5975 3375 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5905 3375 50  0001 C CNN
F 3 "" H 5975 3375 50  0000 C CNN
	1    5975 3375
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B85D9B5
P 6675 2425
AR Path="/5B85D9B5" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B85D9B5" Ref="R62"  Part="1" 
F 0 "R62" V 6755 2425 50  0000 C CNN
F 1 "24K" V 6675 2425 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6605 2425 50  0001 C CNN
F 3 "" H 6675 2425 50  0000 C CNN
	1    6675 2425
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C?
U 1 1 5B85D9BB
P 6675 2575
AR Path="/5B85D9BB" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B85D9BB" Ref="C42"  Part="1" 
F 0 "C42" H 6700 2675 50  0000 L CNN
F 1 "18p" H 6700 2475 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6713 2425 50  0001 C CNN
F 3 "" H 6675 2575 50  0000 C CNN
	1    6675 2575
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5B85D9C1
P 5975 3575
AR Path="/5B85D9C1" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B85D9C1" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 5975 3325 50  0001 C CNN
F 1 "GND" H 5975 3425 50  0000 C CNN
F 2 "" H 5975 3575 50  0000 C CNN
F 3 "" H 5975 3575 50  0000 C CNN
	1    5975 3575
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5B85D9C7
P 6275 2875
AR Path="/5B85D9C7" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B85D9C7" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 6275 2625 50  0001 C CNN
F 1 "GND" H 6275 2725 50  0000 C CNN
F 2 "" H 6275 2875 50  0000 C CNN
F 3 "" H 6275 2875 50  0000 C CNN
	1    6275 2875
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power-allcolours-rescue #PWR?
U 1 1 5B85D9CD
P 6575 3375
AR Path="/5B85D9CD" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B85D9CD" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 6575 3225 50  0001 C CNN
F 1 "-12VA" H 6575 3515 50  0000 C CNN
F 2 "" H 6575 3375 50  0000 C CNN
F 3 "" H 6575 3375 50  0000 C CNN
	1    6575 3375
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR?
U 1 1 5B85D9D3
P 6525 2325
AR Path="/5B85D9D3" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B85D9D3" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 6525 2175 50  0001 C CNN
F 1 "+12V" H 6525 2465 50  0000 C CNN
F 2 "" H 6525 2325 50  0000 C CNN
F 3 "" H 6525 2325 50  0000 C CNN
	1    6525 2325
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 3075 5975 3075
Wire Wire Line
	5975 3075 5975 3225
Wire Wire Line
	5975 3575 5975 3525
Wire Wire Line
	6325 2425 6325 2575
Wire Wire Line
	6325 2575 6525 2575
Wire Wire Line
	6325 2425 6525 2425
Connection ~ 6325 2575
Wire Wire Line
	6825 2425 6825 2575
Wire Wire Line
	6825 2575 6975 2575
Wire Wire Line
	6975 2575 6975 2975
Wire Wire Line
	6975 2975 7250 2975
Wire Wire Line
	6575 3275 6575 3375
Wire Wire Line
	6575 2675 6525 2675
Wire Wire Line
	6275 2875 6325 2875
Text Notes 5825 3425 0    60   ~ 0
?
Wire Wire Line
	6325 2575 6325 2875
Connection ~ 5975 3075
Connection ~ 6825 2575
$Comp
L allcolours-rescue:TL072-linear-allcolours-rescue U?
U 2 1 5B85D9F0
P 6675 2975
AR Path="/5B85D9F0" Ref="U?"  Part="2" 
AR Path="/5B6C330C/5B85D9F0" Ref="U13"  Part="2" 
F 0 "U13" H 7016 3021 50  0000 L CNN
F 1 "TL072" H 7016 2930 50  0000 L CNN
F 2 "" H 6675 2975 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6675 2975 50  0001 C CNN
	2    6675 2975
	1    0    0    -1  
$EndComp
Connection ~ 6325 2875
Wire Wire Line
	6325 2875 6375 2875
Connection ~ 6975 2975
Wire Wire Line
	6275 3075 6375 3075
Wire Wire Line
	5725 3075 5525 3075
Text Label 5525 3075 2    60   ~ 0
7400_LP
Text Label 6200 4700 2    60   ~ 0
FILTER_IN
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C157BC2
P 2180 2530
AR Path="/5C157BC2" Ref="J?"  Part="1" 
AR Path="/5B6C330C/5C157BC2" Ref="J28"  Part="1" 
F 0 "J28" H 2260 2572 50  0000 L CNN
F 1 "filter_in" H 2260 2481 50  0000 L CNN
F 2 "" H 2180 2530 50  0001 C CNN
F 3 "~" H 2180 2530 50  0001 C CNN
	1    2180 2530
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-erthenvar M?
U 1 1 5C157BC9
P 1555 2480
AR Path="/5C157BC9" Ref="M?"  Part="1" 
AR Path="/5B6C330C/5C157BC9" Ref="M10"  Part="1" 
F 0 "M10" H 1228 2442 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1555 2480 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 1585 2630 20  0001 C CNN
F 3 "" H 1555 2480 60  0001 C CNN
	1    1555 2480
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5C16F471
P 2005 2380
AR Path="/5C16F471" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5C16F471" Ref="#PWR0133"  Part="1" 
F 0 "#PWR0133" H 2005 2130 50  0001 C CNN
F 1 "GND" H 2080 2430 50  0000 C CNN
F 2 "" H 2005 2380 50  0000 C CNN
F 3 "" H 2005 2380 50  0000 C CNN
	1    2005 2380
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 6100 3350 6100
Wire Wire Line
	2900 6200 3350 6200
Wire Wire Line
	2800 6300 3350 6300
Wire Wire Line
	3150 6400 3350 6400
Wire Wire Line
	3700 6400 4400 6400
Wire Wire Line
	3700 6300 4000 6300
Wire Wire Line
	3700 6200 4250 6200
Wire Wire Line
	3700 6100 4400 6100
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0134
U 1 1 5C09F49B
P 6675 4525
F 0 "#PWR0134" H 6675 4275 50  0001 C CNN
F 1 "GND" H 6675 4375 50  0000 C CNN
F 2 "" H 6675 4525 50  0000 C CNN
F 3 "" H 6675 4525 50  0000 C CNN
	1    6675 4525
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 4500 6675 4500
Wire Wire Line
	6675 4500 6675 4525
Wire Wire Line
	1855 2380 2005 2380
Wire Wire Line
	1855 2480 1905 2480
Wire Wire Line
	1905 2480 1905 2530
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C0D3788
P 7575 1800
AR Path="/5C0D3788" Ref="J?"  Part="1" 
AR Path="/5B6C330C/5C0D3788" Ref="J?"  Part="1" 
F 0 "J?" H 7655 1842 50  0000 L CNN
F 1 "7490_out" H 7655 1751 50  0000 L CNN
F 2 "" H 7575 1800 50  0001 C CNN
F 3 "~" H 7575 1800 50  0001 C CNN
	1    7575 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7325 1800 7375 1800
Wire Wire Line
	7325 1500 7325 1800
Connection ~ 7325 1500
Wire Wire Line
	7325 1500 7700 1500
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C0E5BE6
P 7450 3325
AR Path="/5C0E5BE6" Ref="J?"  Part="1" 
AR Path="/5B6C330C/5C0E5BE6" Ref="J?"  Part="1" 
F 0 "J?" H 7530 3367 50  0000 L CNN
F 1 "7400_out" H 7530 3276 50  0000 L CNN
F 2 "" H 7450 3325 50  0001 C CNN
F 3 "~" H 7450 3325 50  0001 C CNN
	1    7450 3325
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3325 7250 2975
Connection ~ 7250 2975
Wire Wire Line
	7250 2975 7475 2975
Wire Wire Line
	6750 850  6750 1200
Wire Wire Line
	6525 2325 6525 2425
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-erthenvar M?
U 1 1 5C110757
P 1555 3055
AR Path="/5C110757" Ref="M?"  Part="1" 
AR Path="/5B6C330C/5C110757" Ref="M?"  Part="1" 
F 0 "M?" H 1228 3017 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1555 3055 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 1585 3205 20  0001 C CNN
F 3 "" H 1555 3055 60  0001 C CNN
	1    1555 3055
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5C110B81
P 1955 2755
F 0 "#PWR?" H 1955 2505 50  0001 C CNN
F 1 "GND" H 1955 2605 50  0000 C CNN
F 2 "" H 1955 2755 50  0000 C CNN
F 3 "" H 1955 2755 50  0000 C CNN
	1    1955 2755
	1    0    0    -1  
$EndComp
Wire Wire Line
	1855 2955 1855 2755
Wire Wire Line
	1855 2755 1955 2755
Wire Wire Line
	1905 2530 1980 2530
Wire Wire Line
	1855 2680 2055 2680
Text Label 2055 2680 0    60   ~ 0
FILTER_IN
Text Label 1980 3255 0    60   ~ 0
CLOCK_IN
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C07F602
P 2180 3055
AR Path="/5C07F602" Ref="J?"  Part="1" 
AR Path="/5B6C330C/5C07F602" Ref="J?"  Part="1" 
F 0 "J?" H 2260 3097 50  0000 L CNN
F 1 "clock_in" H 2260 3006 50  0000 L CNN
F 2 "" H 2180 3055 50  0001 C CNN
F 3 "~" H 2180 3055 50  0001 C CNN
	1    2180 3055
	1    0    0    -1  
$EndComp
Wire Wire Line
	1855 3055 1980 3055
Wire Wire Line
	1855 3255 1980 3255
Wire Wire Line
	4750 4805 5065 4805
Text Label 5065 4805 0    60   ~ 0
CLOCK_IN
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C1B4D36
P 2155 1055
AR Path="/5C1B4D36" Ref="J?"  Part="1" 
AR Path="/5B6C330C/5C1B4D36" Ref="J?"  Part="1" 
F 0 "J?" H 2235 1097 50  0000 L CNN
F 1 "filter_in" H 2235 1006 50  0000 L CNN
F 2 "" H 2155 1055 50  0001 C CNN
F 3 "~" H 2155 1055 50  0001 C CNN
	1    2155 1055
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-erthenvar M?
U 1 1 5C1B4D3C
P 1530 1005
AR Path="/5C1B4D3C" Ref="M?"  Part="1" 
AR Path="/5B6C330C/5C1B4D3C" Ref="M?"  Part="1" 
F 0 "M?" H 1203 967 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1530 1005 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 1560 1155 20  0001 C CNN
F 3 "" H 1530 1005 60  0001 C CNN
	1    1530 1005
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5C1B4D42
P 1980 905
AR Path="/5C1B4D42" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5C1B4D42" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1980 655 50  0001 C CNN
F 1 "GND" H 2055 955 50  0000 C CNN
F 2 "" H 1980 905 50  0000 C CNN
F 3 "" H 1980 905 50  0000 C CNN
	1    1980 905 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1830 905  1980 905 
Wire Wire Line
	1830 1005 1880 1005
Wire Wire Line
	1880 1005 1880 1055
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-erthenvar M?
U 1 1 5C1B4D4B
P 1530 1580
AR Path="/5C1B4D4B" Ref="M?"  Part="1" 
AR Path="/5B6C330C/5C1B4D4B" Ref="M?"  Part="1" 
F 0 "M?" H 1203 1542 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1530 1580 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 1560 1730 20  0001 C CNN
F 3 "" H 1530 1580 60  0001 C CNN
	1    1530 1580
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5C1B4D51
P 1930 1280
F 0 "#PWR?" H 1930 1030 50  0001 C CNN
F 1 "GND" H 1930 1130 50  0000 C CNN
F 2 "" H 1930 1280 50  0000 C CNN
F 3 "" H 1930 1280 50  0000 C CNN
	1    1930 1280
	1    0    0    -1  
$EndComp
Wire Wire Line
	1830 1480 1830 1280
Wire Wire Line
	1830 1280 1930 1280
Wire Wire Line
	1880 1055 1955 1055
Wire Wire Line
	1830 1205 2030 1205
Text Label 2030 1205 0    60   ~ 0
7490_OUT
Text Label 1955 1780 0    60   ~ 0
7400_OUT
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C1B4D5D
P 2155 1580
AR Path="/5C1B4D5D" Ref="J?"  Part="1" 
AR Path="/5B6C330C/5C1B4D5D" Ref="J?"  Part="1" 
F 0 "J?" H 2235 1622 50  0000 L CNN
F 1 "clock_in" H 2235 1531 50  0000 L CNN
F 2 "" H 2155 1580 50  0001 C CNN
F 3 "~" H 2155 1580 50  0001 C CNN
	1    2155 1580
	1    0    0    -1  
$EndComp
Wire Wire Line
	1830 1580 1955 1580
Wire Wire Line
	1830 1780 1955 1780
Text Label 7700 1500 0    60   ~ 0
7490_OUT
Text Label 7475 2975 0    60   ~ 0
7400_OUT
Connection ~ 6525 2425
Wire Wire Line
	6525 2425 6525 2575
Connection ~ 6525 2575
Wire Wire Line
	6525 2575 6525 2675
$EndSCHEMATC
