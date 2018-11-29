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
L allcolours_analogue-rescue:R-device R77
U 1 1 5C03350E
P 1675 2525
F 0 "R77" V 1755 2525 50  0000 C CNN
F 1 "10K" V 1675 2525 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1605 2525 50  0001 C CNN
F 3 "" H 1675 2525 50  0000 C CNN
	1    1675 2525
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R78
U 1 1 5C033515
P 1875 2675
F 0 "R78" V 1955 2675 50  0000 C CNN
F 1 "100K" V 1875 2675 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1805 2675 50  0001 C CNN
F 3 "" H 1875 2675 50  0000 C CNN
	1    1875 2675
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR0138
U 1 1 5C03351C
P 2025 2725
F 0 "#PWR0138" H 2025 2575 50  0001 C CNN
F 1 "+12V" H 2025 2865 50  0000 C CNN
F 2 "" H 2025 2725 50  0000 C CNN
F 3 "" H 2025 2725 50  0000 C CNN
	1    2025 2725
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:-12VA-power #PWR0140
U 1 1 5C033522
P 2275 2125
F 0 "#PWR0140" H 2275 1975 50  0001 C CNN
F 1 "-12VA" H 2275 2265 50  0000 C CNN
F 2 "" H 2275 2125 50  0000 C CNN
F 3 "" H 2275 2125 50  0000 C CNN
	1    2275 2125
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR0139
U 1 1 5C03352F
P 2275 1375
F 0 "#PWR0139" H 2275 1225 50  0001 C CNN
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
L allcolours_analogue-rescue:D-device D15
U 1 1 5C033540
P 3025 1775
F 0 "D15" H 3025 1559 50  0000 C CNN
F 1 "1n914/4148" H 3025 1650 50  0000 C CNN
F 2 "" H 3025 1775 50  0001 C CNN
F 3 "" H 3025 1775 50  0001 C CNN
	1    3025 1775
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R79
U 1 1 5C033547
P 3275 1925
F 0 "R79" V 3355 1925 50  0000 C CNN
F 1 "20K" V 3275 1925 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3205 1925 50  0001 C CNN
F 3 "" H 3275 1925 50  0000 C CNN
	1    3275 1925
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR0141
U 1 1 5C03354E
P 3275 2125
F 0 "#PWR0141" H 3275 1875 50  0001 C CNN
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
L allcolours_analogue-rescue:GND-power #PWR0137
U 1 1 5C033557
P 1875 2875
F 0 "#PWR0137" H 1875 2625 50  0001 C CNN
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
L allcolours_analogue-rescue:TL072-linear U16
U 1 1 5C033561
P 2375 1775
F 0 "U16" H 2716 1821 50  0000 L CNN
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
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J42
U 1 1 5BFEF160
P 1675 1425
F 0 "J42" H 1595 1200 50  0000 C CNN
F 1 "Conn_01x01" H 1595 1291 50  0000 C CNN
F 2 "" H 1675 1425 50  0001 C CNN
F 3 "" H 1675 1425 50  0001 C CNN
	1    1675 1425
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J41
U 1 1 5BFEF20A
P 1275 2375
F 0 "J41" H 1195 2150 50  0000 C CNN
F 1 "Conn_01x01" H 1195 2241 50  0000 C CNN
F 2 "" H 1275 2375 50  0001 C CNN
F 3 "" H 1275 2375 50  0001 C CNN
	1    1275 2375
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J43
U 1 1 5BFEF28C
P 2325 2525
F 0 "J43" H 2405 2567 50  0000 L CNN
F 1 "Conn_01x01" H 2405 2476 50  0000 L CNN
F 2 "" H 2325 2525 50  0001 C CNN
F 3 "" H 2325 2525 50  0001 C CNN
	1    2325 2525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J44
U 1 1 5BFEF2E6
P 2325 2775
F 0 "J44" H 2405 2817 50  0000 L CNN
F 1 "Conn_01x01" H 2405 2726 50  0000 L CNN
F 2 "" H 2325 2775 50  0001 C CNN
F 3 "" H 2325 2775 50  0001 C CNN
	1    2325 2775
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J45
U 1 1 5BFEF31E
P 3625 1775
F 0 "J45" H 3705 1817 50  0000 L CNN
F 1 "Conn_01x01" H 3705 1726 50  0000 L CNN
F 2 "" H 3625 1775 50  0001 C CNN
F 3 "" H 3625 1775 50  0001 C CNN
	1    3625 1775
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:-12VA-power #PWR0143
U 1 1 5C044F83
P 5700 2200
F 0 "#PWR0143" H 5700 2050 50  0001 C CNN
F 1 "-12VA" H 5700 2340 50  0000 C CNN
F 2 "" H 5700 2200 50  0000 C CNN
F 3 "" H 5700 2200 50  0000 C CNN
	1    5700 2200
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR0142
U 1 1 5C044F89
P 5700 1450
F 0 "#PWR0142" H 5700 1300 50  0001 C CNN
F 1 "+12V" H 5700 1590 50  0000 C CNN
F 2 "" H 5700 1450 50  0000 C CNN
F 3 "" H 5700 1450 50  0000 C CNN
	1    5700 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 2150 5700 2200
Wire Wire Line
	6100 1850 6300 1850
$Comp
L allcolours_analogue-rescue:D-device D16
U 1 1 5C044F97
P 6450 1850
F 0 "D16" H 6450 1634 50  0000 C CNN
F 1 "1n914/4148" H 6450 1725 50  0000 C CNN
F 2 "" H 6450 1850 50  0001 C CNN
F 3 "" H 6450 1850 50  0001 C CNN
	1    6450 1850
	-1   0    0    1   
$EndComp
Wire Wire Line
	5700 1550 5700 1450
$Comp
L allcolours_analogue-rescue:TL072-linear U16
U 2 1 5C044FB5
P 5800 1850
F 0 "U16" H 6141 1896 50  0000 L CNN
F 1 "TL072" H 6141 1805 50  0000 L CNN
F 2 "" H 5800 1850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5800 1850 50  0001 C CNN
	2    5800 1850
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J46
U 1 1 5C044FC3
P 5250 1750
F 0 "J46" H 5170 1525 50  0000 C CNN
F 1 "Conn_01x01" H 5170 1616 50  0000 C CNN
F 2 "" H 5250 1750 50  0001 C CNN
F 3 "" H 5250 1750 50  0001 C CNN
	1    5250 1750
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J47
U 1 1 5C044FC9
P 5250 1950
F 0 "J47" H 5170 1725 50  0000 C CNN
F 1 "Conn_01x01" H 5170 1816 50  0000 C CNN
F 2 "" H 5250 1950 50  0001 C CNN
F 3 "" H 5250 1950 50  0001 C CNN
	1    5250 1950
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J48
U 1 1 5C044FDB
P 6875 1850
F 0 "J48" H 6955 1892 50  0000 L CNN
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
Wire Wire Line
	5450 1750 5500 1750
Wire Wire Line
	5450 1950 5500 1950
$EndSCHEMATC
