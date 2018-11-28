EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 1275 1025 0    60   ~ 0
finger comparator for clock in / shift reg\n
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C03350E
P 1675 2525
F 0 "R?" V 1755 2525 50  0000 C CNN
F 1 "10K" V 1675 2525 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1605 2525 50  0001 C CNN
F 3 "" H 1675 2525 50  0000 C CNN
	1    1675 2525
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C033515
P 1875 2675
F 0 "R?" V 1955 2675 50  0000 C CNN
F 1 "100K" V 1875 2675 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1805 2675 50  0001 C CNN
F 3 "" H 1875 2675 50  0000 C CNN
	1    1875 2675
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C03351C
P 2025 2725
F 0 "#PWR?" H 2025 2575 50  0001 C CNN
F 1 "+12V" H 2025 2865 50  0000 C CNN
F 2 "" H 2025 2725 50  0000 C CNN
F 3 "" H 2025 2725 50  0000 C CNN
	1    2025 2725
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:-12VA-power #PWR?
U 1 1 5C033522
P 2275 2125
F 0 "#PWR?" H 2275 1975 50  0001 C CNN
F 1 "-12VA" H 2275 2265 50  0000 C CNN
F 2 "" H 2275 2125 50  0000 C CNN
F 3 "" H 2275 2125 50  0000 C CNN
	1    2275 2125
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C03352F
P 2275 1375
F 0 "#PWR?" H 2275 1225 50  0001 C CNN
F 1 "+12V" H 2275 1515 50  0000 C CNN
F 2 "" H 2275 1375 50  0000 C CNN
F 3 "" H 2275 1375 50  0000 C CNN
	1    2275 1375
	1    0    0    -1  
$EndComp
Wire Wire Line
	2275 2075 2275 2125
Wire Wire Line
	1475 2375 1525 2375
Wire Wire Line
	1675 2375 1675 1875
Wire Wire Line
	1675 1875 2075 1875
Wire Wire Line
	1525 2525 1525 2375
Connection ~ 1525 2375
Wire Wire Line
	2675 1775 2875 1775
Text Notes 1575 2725 0    60   ~ 0
10K?
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5C033540
P 3025 1775
F 0 "D?" H 3025 1559 50  0000 C CNN
F 1 "1n914/4148" H 3025 1650 50  0000 C CNN
F 2 "" H 3025 1775 50  0001 C CNN
F 3 "" H 3025 1775 50  0001 C CNN
	1    3025 1775
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C033547
P 3275 1925
F 0 "R?" V 3355 1925 50  0000 C CNN
F 1 "20K" V 3275 1925 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3205 1925 50  0001 C CNN
F 3 "" H 3275 1925 50  0000 C CNN
	1    3275 1925
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C03354E
P 3275 2125
F 0 "#PWR?" H 3275 1875 50  0001 C CNN
F 1 "GND" H 3275 1975 50  0000 C CNN
F 2 "" H 3275 2125 50  0000 C CNN
F 3 "" H 3275 2125 50  0000 C CNN
	1    3275 2125
	1    0    0    -1  
$EndComp
Wire Wire Line
	3175 1775 3275 1775
Wire Wire Line
	3275 2125 3275 2075
Connection ~ 3275 1775
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C033557
P 1875 2875
F 0 "#PWR?" H 1875 2625 50  0001 C CNN
F 1 "GND" H 1875 2725 50  0000 C CNN
F 2 "" H 1875 2875 50  0000 C CNN
F 3 "" H 1875 2875 50  0000 C CNN
	1    1875 2875
	1    0    0    -1  
$EndComp
Wire Wire Line
	2275 1475 2275 1375
Wire Wire Line
	1525 2375 1675 2375
Wire Wire Line
	3275 1775 3425 1775
$Comp
L allcolours_analogue-rescue:TL072-linear U?
U 1 1 5C033561
P 2375 1775
F 0 "U?" H 2716 1821 50  0000 L CNN
F 1 "TL072" H 2716 1730 50  0000 L CNN
F 2 "" H 2375 1775 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2375 1775 50  0001 C CNN
	1    2375 1775
	1    0    0    -1  
$EndComp
Wire Wire Line
	2025 2725 2025 2775
Wire Wire Line
	2025 2775 2125 2775
Wire Wire Line
	1875 2875 1875 2825
Wire Wire Line
	1875 2525 2125 2525
Wire Wire Line
	1825 2525 1875 2525
Connection ~ 1875 2525
Wire Wire Line
	1875 1425 1875 1675
Wire Wire Line
	1875 1675 2075 1675
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BFEF160
P 1675 1425
F 0 "J?" H 1595 1200 50  0000 C CNN
F 1 "Conn_01x01" H 1595 1291 50  0000 C CNN
F 2 "" H 1675 1425 50  0001 C CNN
F 3 "" H 1675 1425 50  0001 C CNN
	1    1675 1425
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BFEF20A
P 1275 2375
F 0 "J?" H 1195 2150 50  0000 C CNN
F 1 "Conn_01x01" H 1195 2241 50  0000 C CNN
F 2 "" H 1275 2375 50  0001 C CNN
F 3 "" H 1275 2375 50  0001 C CNN
	1    1275 2375
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BFEF28C
P 2325 2525
F 0 "J?" H 2405 2567 50  0000 L CNN
F 1 "Conn_01x01" H 2405 2476 50  0000 L CNN
F 2 "" H 2325 2525 50  0001 C CNN
F 3 "" H 2325 2525 50  0001 C CNN
	1    2325 2525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BFEF2E6
P 2325 2775
F 0 "J?" H 2405 2817 50  0000 L CNN
F 1 "Conn_01x01" H 2405 2726 50  0000 L CNN
F 2 "" H 2325 2775 50  0001 C CNN
F 3 "" H 2325 2775 50  0001 C CNN
	1    2325 2775
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BFEF31E
P 3625 1775
F 0 "J?" H 3705 1817 50  0000 L CNN
F 1 "Conn_01x01" H 3705 1726 50  0000 L CNN
F 2 "" H 3625 1775 50  0001 C CNN
F 3 "" H 3625 1775 50  0001 C CNN
	1    3625 1775
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C044F71
P 5100 2600
F 0 "R?" V 5180 2600 50  0000 C CNN
F 1 "10K" V 5100 2600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5030 2600 50  0001 C CNN
F 3 "" H 5100 2600 50  0000 C CNN
	1    5100 2600
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C044F77
P 5300 2750
F 0 "R?" V 5380 2750 50  0000 C CNN
F 1 "100K" V 5300 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5230 2750 50  0001 C CNN
F 3 "" H 5300 2750 50  0000 C CNN
	1    5300 2750
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C044F7D
P 5450 2800
F 0 "#PWR?" H 5450 2650 50  0001 C CNN
F 1 "+12V" H 5450 2940 50  0000 C CNN
F 2 "" H 5450 2800 50  0000 C CNN
F 3 "" H 5450 2800 50  0000 C CNN
	1    5450 2800
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:-12VA-power #PWR?
U 1 1 5C044F83
P 5700 2200
F 0 "#PWR?" H 5700 2050 50  0001 C CNN
F 1 "-12VA" H 5700 2340 50  0000 C CNN
F 2 "" H 5700 2200 50  0000 C CNN
F 3 "" H 5700 2200 50  0000 C CNN
	1    5700 2200
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C044F89
P 5700 1450
F 0 "#PWR?" H 5700 1300 50  0001 C CNN
F 1 "+12V" H 5700 1590 50  0000 C CNN
F 2 "" H 5700 1450 50  0000 C CNN
F 3 "" H 5700 1450 50  0000 C CNN
	1    5700 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 2150 5700 2200
Wire Wire Line
	4900 2450 4950 2450
Wire Wire Line
	5100 2450 5100 1950
Wire Wire Line
	5100 1950 5500 1950
Wire Wire Line
	4950 2600 4950 2450
Connection ~ 4950 2450
Wire Wire Line
	6100 1850 6300 1850
Text Notes 5000 2800 0    60   ~ 0
10K?
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5C044F97
P 6450 1850
F 0 "D?" H 6450 1634 50  0000 C CNN
F 1 "1n914/4148" H 6450 1725 50  0000 C CNN
F 2 "" H 6450 1850 50  0001 C CNN
F 3 "" H 6450 1850 50  0001 C CNN
	1    6450 1850
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C044FAC
P 5300 2950
F 0 "#PWR?" H 5300 2700 50  0001 C CNN
F 1 "GND" H 5300 2800 50  0000 C CNN
F 2 "" H 5300 2950 50  0000 C CNN
F 3 "" H 5300 2950 50  0000 C CNN
	1    5300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 1550 5700 1450
Wire Wire Line
	4950 2450 5100 2450
$Comp
L allcolours_analogue-rescue:TL072-linear U?
U 1 1 5C044FB5
P 5800 1850
F 0 "U?" H 6141 1896 50  0000 L CNN
F 1 "TL072" H 6141 1805 50  0000 L CNN
F 2 "" H 5800 1850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5800 1850 50  0001 C CNN
	1    5800 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2800 5450 2850
Wire Wire Line
	5450 2850 5550 2850
Wire Wire Line
	5300 2950 5300 2900
Wire Wire Line
	5300 2600 5550 2600
Wire Wire Line
	5250 2600 5300 2600
Connection ~ 5300 2600
Wire Wire Line
	5300 1500 5300 1750
Wire Wire Line
	5300 1750 5500 1750
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C044FC3
P 5100 1500
F 0 "J?" H 5020 1275 50  0000 C CNN
F 1 "Conn_01x01" H 5020 1366 50  0000 C CNN
F 2 "" H 5100 1500 50  0001 C CNN
F 3 "" H 5100 1500 50  0001 C CNN
	1    5100 1500
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C044FC9
P 4700 2450
F 0 "J?" H 4620 2225 50  0000 C CNN
F 1 "Conn_01x01" H 4620 2316 50  0000 C CNN
F 2 "" H 4700 2450 50  0001 C CNN
F 3 "" H 4700 2450 50  0001 C CNN
	1    4700 2450
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C044FCF
P 5750 2600
F 0 "J?" H 5830 2642 50  0000 L CNN
F 1 "Conn_01x01" H 5830 2551 50  0000 L CNN
F 2 "" H 5750 2600 50  0001 C CNN
F 3 "" H 5750 2600 50  0001 C CNN
	1    5750 2600
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C044FD5
P 5750 2850
F 0 "J?" H 5830 2892 50  0000 L CNN
F 1 "Conn_01x01" H 5830 2801 50  0000 L CNN
F 2 "" H 5750 2850 50  0001 C CNN
F 3 "" H 5750 2850 50  0001 C CNN
	1    5750 2850
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C044FDB
P 6875 1850
F 0 "J?" H 6955 1892 50  0000 L CNN
F 1 "Conn_01x01" H 6955 1801 50  0000 L CNN
F 2 "" H 6875 1850 50  0001 C CNN
F 3 "" H 6875 1850 50  0001 C CNN
	1    6875 1850
	1    0    0    -1  
$EndComp
Text Notes 4875 950  0    60   ~ 0
finger comparator for shift reg inputs x4\n
Wire Wire Line
	6600 1850 6675 1850
$EndSCHEMATC
