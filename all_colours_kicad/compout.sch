EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 4650 1875 0    60   ~ 0
finger comparator (tested)
$Comp
L allcolours-rescue:R-device R70
U 1 1 5C03350E
P 4600 3225
F 0 "R70" V 4680 3225 50  0000 C CNN
F 1 "10K" V 4600 3225 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4530 3225 50  0001 C CNN
F 3 "" H 4600 3225 50  0000 C CNN
	1    4600 3225
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device R71
U 1 1 5C033515
P 4800 3375
F 0 "R71" V 4880 3375 50  0000 C CNN
F 1 "100K" V 4800 3375 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4730 3375 50  0001 C CNN
F 3 "" H 4800 3375 50  0000 C CNN
	1    4800 3375
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR0129
U 1 1 5C03351C
P 4950 3425
F 0 "#PWR0129" H 4950 3275 50  0001 C CNN
F 1 "+12V" H 4950 3565 50  0000 C CNN
F 2 "" H 4950 3425 50  0000 C CNN
F 3 "" H 4950 3425 50  0000 C CNN
	1    4950 3425
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power #PWR0131
U 1 1 5C033522
P 5200 2825
F 0 "#PWR0131" H 5200 2675 50  0001 C CNN
F 1 "-12VA" H 5200 2965 50  0000 C CNN
F 2 "" H 5200 2825 50  0000 C CNN
F 3 "" H 5200 2825 50  0000 C CNN
	1    5200 2825
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+12V-power #PWR0130
U 1 1 5C03352F
P 5200 2075
F 0 "#PWR0130" H 5200 1925 50  0001 C CNN
F 1 "+12V" H 5200 2215 50  0000 C CNN
F 2 "" H 5200 2075 50  0000 C CNN
F 3 "" H 5200 2075 50  0000 C CNN
	1    5200 2075
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 2775 5200 2825
Wire Wire Line
	4400 3075 4450 3075
Wire Wire Line
	4600 3075 4600 2575
Wire Wire Line
	4600 2575 5000 2575
Wire Wire Line
	4450 3225 4450 3075
Connection ~ 4450 3075
Wire Wire Line
	5600 2475 5800 2475
Text Notes 4500 3425 0    60   ~ 0
10K?
$Comp
L allcolours-rescue:D-device D14
U 1 1 5C033540
P 5950 2475
F 0 "D14" H 5950 2259 50  0000 C CNN
F 1 "1n914/4148" H 5950 2350 50  0000 C CNN
F 2 "" H 5950 2475 50  0001 C CNN
F 3 "" H 5950 2475 50  0001 C CNN
	1    5950 2475
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device R72
U 1 1 5C033547
P 6200 2625
F 0 "R72" V 6280 2625 50  0000 C CNN
F 1 "20K" V 6200 2625 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6130 2625 50  0001 C CNN
F 3 "" H 6200 2625 50  0000 C CNN
	1    6200 2625
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power #PWR0132
U 1 1 5C03354E
P 6200 2825
F 0 "#PWR0132" H 6200 2575 50  0001 C CNN
F 1 "GND" H 6200 2675 50  0000 C CNN
F 2 "" H 6200 2825 50  0000 C CNN
F 3 "" H 6200 2825 50  0000 C CNN
	1    6200 2825
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2475 6200 2475
Wire Wire Line
	6200 2825 6200 2775
Connection ~ 6200 2475
$Comp
L allcolours-rescue:GND-power #PWR0128
U 1 1 5C033557
P 4800 3575
F 0 "#PWR0128" H 4800 3325 50  0001 C CNN
F 1 "GND" H 4800 3425 50  0000 C CNN
F 2 "" H 4800 3575 50  0000 C CNN
F 3 "" H 4800 3575 50  0000 C CNN
	1    4800 3575
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 2175 5200 2075
Wire Wire Line
	4450 3075 4600 3075
Wire Wire Line
	6200 2475 6350 2475
$Comp
L allcolours-rescue:TL072-linear U14
U 1 1 5C033561
P 5300 2475
F 0 "U14" H 5641 2521 50  0000 L CNN
F 1 "TL072" H 5641 2430 50  0000 L CNN
F 2 "" H 5300 2475 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5300 2475 50  0001 C CNN
	1    5300 2475
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J22
U 1 1 5C033568
P 5250 3225
F 0 "J22" H 5330 3267 50  0000 L CNN
F 1 "Conn_01x01" H 5330 3176 50  0000 L CNN
F 2 "" H 5250 3225 50  0001 C CNN
F 3 "~" H 5250 3225 50  0001 C CNN
	1    5250 3225
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Conn_01x01-Connector J23
U 1 1 5C03356F
P 5250 3475
F 0 "J23" H 5330 3517 50  0000 L CNN
F 1 "Conn_01x01" H 5330 3426 50  0000 L CNN
F 2 "" H 5250 3475 50  0001 C CNN
F 3 "~" H 5250 3475 50  0001 C CNN
	1    5250 3475
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3425 4950 3475
Wire Wire Line
	4950 3475 5050 3475
Wire Wire Line
	4800 3575 4800 3525
Wire Wire Line
	4800 3225 5050 3225
Wire Wire Line
	4750 3225 4800 3225
Connection ~ 4800 3225
$Comp
L allcolours-rescue:Conn_01x01-Connector J20
U 1 1 5C03357C
P 4100 3225
F 0 "J20" H 4180 3267 50  0000 L CNN
F 1 "Conn_01x01" H 4180 3176 50  0000 L CNN
F 2 "" H 4100 3225 50  0001 C CNN
F 3 "~" H 4100 3225 50  0001 C CNN
	1    4100 3225
	-1   0    0    1   
$EndComp
Wire Wire Line
	4300 3225 4400 3225
Wire Wire Line
	4400 3225 4400 3075
$Comp
L allcolours-rescue:Conn_01x01-Connector J21
U 1 1 5C03358E
P 4600 2125
F 0 "J21" H 4680 2167 50  0000 L CNN
F 1 "Conn_01x01" H 4680 2076 50  0000 L CNN
F 2 "" H 4600 2125 50  0001 C CNN
F 3 "~" H 4600 2125 50  0001 C CNN
	1    4600 2125
	-1   0    0    1   
$EndComp
Wire Wire Line
	4800 2125 4800 2375
Wire Wire Line
	4800 2375 5000 2375
$EndSCHEMATC
