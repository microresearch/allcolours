EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2040 920  0    60   ~ 0
finger comparator
$Comp
L allcolours_analogue-rescue:R-device R77
U 1 1 5C03350E
P 1675 2525
F 0 "R77" V 1755 2525 50  0000 C CNN
F 1 "10K" V 1675 2525 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1605 2525 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" V 1805 2675 50  0001 C CNN
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
F 2 "Diodes_SMD:D_SOD-323" H 3025 1775 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" V 3205 1925 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-8-N" H 2375 1775 50  0001 C CNN
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
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J42
U 1 1 5BFEF160
P 1675 1425
F 0 "J42" H 1595 1200 50  0000 C CNN
F 1 "compin1" H 1595 1291 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1675 1425 50  0001 C CNN
F 3 "" H 1675 1425 50  0001 C CNN
	1    1675 1425
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J41
U 1 1 5BFEF20A
P 1275 2375
F 0 "J41" H 1195 2150 50  0000 C CNN
F 1 "compin2" H 1195 2241 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1275 2375 50  0001 C CNN
F 3 "" H 1275 2375 50  0001 C CNN
	1    1275 2375
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J43
U 1 1 5BFEF28C
P 2325 2525
F 0 "J43" H 2405 2567 50  0000 L CNN
F 1 "compin3" H 2405 2476 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2325 2525 50  0001 C CNN
F 3 "" H 2325 2525 50  0001 C CNN
	1    2325 2525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J44
U 1 1 5BFEF2E6
P 2325 2775
F 0 "J44" H 2405 2817 50  0000 L CNN
F 1 "+12v" H 2405 2726 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2325 2775 50  0001 C CNN
F 3 "" H 2325 2775 50  0001 C CNN
	1    2325 2775
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J45
U 1 1 5BFEF31E
P 3625 1775
F 0 "J45" H 3705 1817 50  0000 L CNN
F 1 "compout" H 3705 1726 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3625 1775 50  0001 C CNN
F 3 "" H 3625 1775 50  0001 C CNN
	1    3625 1775
	1    0    0    -1  
$EndComp
Text Notes 4875 950  0    60   ~ 0
finger comparator for shift reg inputs x4\n
$Comp
L allcolours_analogue-rescue:R-device R84
U 1 1 5C03F920
P 1965 1825
F 0 "R84" V 2045 1825 50  0000 C CNN
F 1 "100K" V 1965 1825 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1895 1825 50  0001 C CNN
F 3 "" H 1965 1825 50  0000 C CNN
	1    1965 1825
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR0180
U 1 1 5C03F926
P 1965 2025
F 0 "#PWR0180" H 1965 1775 50  0001 C CNN
F 1 "GND" H 1965 1875 50  0000 C CNN
F 2 "" H 1965 2025 50  0000 C CNN
F 3 "" H 1965 2025 50  0000 C CNN
	1    1965 2025
	1    0    0    -1  
$EndComp
Wire Wire Line
	1965 2025 1965 1975
Connection ~ 1965 1675
Wire Wire Line
	1965 1675 2075 1675
Wire Wire Line
	1875 1675 1965 1675
$Comp
L allcolours_analogue-rescue:+12V-power #PWR0181
U 1 1 5C040607
P 6145 1245
F 0 "#PWR0181" H 6145 1095 50  0001 C CNN
F 1 "+12V" H 6145 1385 50  0000 C CNN
F 2 "" H 6145 1245 50  0000 C CNN
F 3 "" H 6145 1245 50  0000 C CNN
	1    6145 1245
	1    0    0    -1  
$EndComp
Wire Wire Line
	6145 1945 6145 1995
Wire Wire Line
	5545 1745 5620 1745
Wire Wire Line
	6545 1645 6745 1645
$Comp
L allcolours_analogue-rescue:D-device D1
U 1 1 5C040615
P 6895 1645
F 0 "D1" H 6895 1429 50  0000 C CNN
F 1 "1n914/4148" H 6895 1520 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 6895 1645 50  0001 C CNN
F 3 "" H 6895 1645 50  0001 C CNN
	1    6895 1645
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R87
U 1 1 5C04061B
P 7145 1795
F 0 "R87" V 7225 1795 50  0000 C CNN
F 1 "20K" V 7145 1795 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7075 1795 50  0001 C CNN
F 3 "" H 7145 1795 50  0000 C CNN
	1    7145 1795
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR0182
U 1 1 5C040621
P 7145 1995
F 0 "#PWR0182" H 7145 1745 50  0001 C CNN
F 1 "GND" H 7145 1845 50  0000 C CNN
F 2 "" H 7145 1995 50  0000 C CNN
F 3 "" H 7145 1995 50  0000 C CNN
	1    7145 1995
	1    0    0    -1  
$EndComp
Wire Wire Line
	7045 1645 7145 1645
Wire Wire Line
	7145 1995 7145 1945
Connection ~ 7145 1645
Wire Wire Line
	6145 1345 6145 1245
Wire Wire Line
	7145 1645 7295 1645
$Comp
L allcolours_analogue-rescue:TL072-linear U16
U 2 1 5C040633
P 6245 1645
F 0 "U16" H 6586 1691 50  0000 L CNN
F 1 "TL072" H 6586 1600 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 6245 1645 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6245 1645 50  0001 C CNN
	2    6245 1645
	1    0    0    -1  
$EndComp
Wire Wire Line
	5745 1295 5745 1545
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J37
U 1 1 5C040640
P 5545 1295
F 0 "J37" H 5465 1070 50  0000 C CNN
F 1 "compsr1" H 5465 1161 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5545 1295 50  0001 C CNN
F 3 "" H 5545 1295 50  0001 C CNN
	1    5545 1295
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R86
U 1 1 5C04065E
P 5835 1695
F 0 "R86" V 5915 1695 50  0000 C CNN
F 1 "100K" V 5835 1695 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5765 1695 50  0001 C CNN
F 3 "" H 5835 1695 50  0000 C CNN
	1    5835 1695
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR0183
U 1 1 5C040664
P 5835 1895
F 0 "#PWR0183" H 5835 1645 50  0001 C CNN
F 1 "GND" H 5835 1745 50  0000 C CNN
F 2 "" H 5835 1895 50  0000 C CNN
F 3 "" H 5835 1895 50  0000 C CNN
	1    5835 1895
	1    0    0    -1  
$EndComp
Wire Wire Line
	5835 1895 5835 1845
Connection ~ 5835 1545
Wire Wire Line
	5835 1545 5945 1545
Wire Wire Line
	5745 1545 5835 1545
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J36
U 1 1 5C041772
P 5345 1745
F 0 "J36" H 5265 1520 50  0000 C CNN
F 1 "compsr1" H 5265 1611 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5345 1745 50  0001 C CNN
F 3 "" H 5345 1745 50  0001 C CNN
	1    5345 1745
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R85
U 1 1 5C041B22
P 5620 1895
F 0 "R85" V 5700 1895 50  0000 C CNN
F 1 "100K" V 5620 1895 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5550 1895 50  0001 C CNN
F 3 "" H 5620 1895 50  0000 C CNN
	1    5620 1895
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR0184
U 1 1 5C041B28
P 5620 2095
F 0 "#PWR0184" H 5620 1845 50  0001 C CNN
F 1 "GND" H 5620 1945 50  0000 C CNN
F 2 "" H 5620 2095 50  0000 C CNN
F 3 "" H 5620 2095 50  0000 C CNN
	1    5620 2095
	1    0    0    -1  
$EndComp
Wire Wire Line
	5620 2095 5620 2045
Connection ~ 5620 1745
Wire Wire Line
	5620 1745 5945 1745
Text GLabel 7295 1645 2    60   Input ~ 0
SR1
$Comp
L power:-12V #PWR0185
U 1 1 5C142D64
P 2275 2125
F 0 "#PWR0185" H 2275 2225 50  0001 C CNN
F 1 "-12V" H 2290 2298 50  0000 C CNN
F 2 "" H 2275 2125 50  0001 C CNN
F 3 "" H 2275 2125 50  0001 C CNN
	1    2275 2125
	-1   0    0    1   
$EndComp
$Comp
L power:-12V #PWR0186
U 1 1 5C142DE2
P 6145 1995
F 0 "#PWR0186" H 6145 2095 50  0001 C CNN
F 1 "-12V" H 6160 2168 50  0000 C CNN
F 2 "" H 6145 1995 50  0001 C CNN
F 3 "" H 6145 1995 50  0001 C CNN
	1    6145 1995
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR018
U 1 1 5C159C53
P 6145 2565
F 0 "#PWR018" H 6145 2415 50  0001 C CNN
F 1 "+12V" H 6145 2705 50  0000 C CNN
F 2 "" H 6145 2565 50  0000 C CNN
F 3 "" H 6145 2565 50  0000 C CNN
	1    6145 2565
	1    0    0    -1  
$EndComp
Wire Wire Line
	6145 3265 6145 3315
Wire Wire Line
	5545 3065 5620 3065
Wire Wire Line
	6545 2965 6745 2965
$Comp
L allcolours_analogue-rescue:D-device D3
U 1 1 5C159C5C
P 6895 2965
F 0 "D3" H 6895 2749 50  0000 C CNN
F 1 "1n914/4148" H 6895 2840 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 6895 2965 50  0001 C CNN
F 3 "" H 6895 2965 50  0001 C CNN
	1    6895 2965
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R107
U 1 1 5C159C62
P 7145 3115
F 0 "R107" V 7225 3115 50  0000 C CNN
F 1 "20K" V 7145 3115 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7075 3115 50  0001 C CNN
F 3 "" H 7145 3115 50  0000 C CNN
	1    7145 3115
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR030
U 1 1 5C159C68
P 7145 3315
F 0 "#PWR030" H 7145 3065 50  0001 C CNN
F 1 "GND" H 7145 3165 50  0000 C CNN
F 2 "" H 7145 3315 50  0000 C CNN
F 3 "" H 7145 3315 50  0000 C CNN
	1    7145 3315
	1    0    0    -1  
$EndComp
Wire Wire Line
	7045 2965 7145 2965
Wire Wire Line
	7145 3315 7145 3265
Connection ~ 7145 2965
Wire Wire Line
	6145 2665 6145 2565
Wire Wire Line
	7145 2965 7295 2965
$Comp
L allcolours_analogue-rescue:TL072-linear U19
U 1 1 5C159C73
P 6245 2965
F 0 "U19" H 6586 3011 50  0000 L CNN
F 1 "TL072" H 6586 2920 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 6245 2965 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6245 2965 50  0001 C CNN
	1    6245 2965
	1    0    0    -1  
$EndComp
Wire Wire Line
	5745 2615 5745 2865
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J61
U 1 1 5C159C7A
P 5545 2615
F 0 "J61" H 5465 2390 50  0000 C CNN
F 1 "compsr2" H 5465 2481 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5545 2615 50  0001 C CNN
F 3 "" H 5545 2615 50  0001 C CNN
	1    5545 2615
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R104
U 1 1 5C159C80
P 5835 3015
F 0 "R104" V 5915 3015 50  0000 C CNN
F 1 "100K" V 5835 3015 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5765 3015 50  0001 C CNN
F 3 "" H 5835 3015 50  0000 C CNN
	1    5835 3015
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR011
U 1 1 5C159C86
P 5835 3215
F 0 "#PWR011" H 5835 2965 50  0001 C CNN
F 1 "GND" H 5835 3065 50  0000 C CNN
F 2 "" H 5835 3215 50  0000 C CNN
F 3 "" H 5835 3215 50  0000 C CNN
	1    5835 3215
	1    0    0    -1  
$EndComp
Wire Wire Line
	5835 3215 5835 3165
Connection ~ 5835 2865
Wire Wire Line
	5835 2865 5945 2865
Wire Wire Line
	5745 2865 5835 2865
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J58
U 1 1 5C159C90
P 5345 3065
F 0 "J58" H 5265 2840 50  0000 C CNN
F 1 "compsr2" H 5265 2931 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5345 3065 50  0001 C CNN
F 3 "" H 5345 3065 50  0001 C CNN
	1    5345 3065
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R101
U 1 1 5C159C96
P 5620 3215
F 0 "R101" V 5700 3215 50  0000 C CNN
F 1 "100K" V 5620 3215 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5550 3215 50  0001 C CNN
F 3 "" H 5620 3215 50  0000 C CNN
	1    5620 3215
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR06
U 1 1 5C159C9C
P 5620 3415
F 0 "#PWR06" H 5620 3165 50  0001 C CNN
F 1 "GND" H 5620 3265 50  0000 C CNN
F 2 "" H 5620 3415 50  0000 C CNN
F 3 "" H 5620 3415 50  0000 C CNN
	1    5620 3415
	1    0    0    -1  
$EndComp
Wire Wire Line
	5620 3415 5620 3365
Connection ~ 5620 3065
Wire Wire Line
	5620 3065 5945 3065
Text GLabel 7295 2965 2    60   Input ~ 0
SR2
$Comp
L power:-12V #PWR019
U 1 1 5C159CA6
P 6145 3315
F 0 "#PWR019" H 6145 3415 50  0001 C CNN
F 1 "-12V" H 6160 3488 50  0000 C CNN
F 2 "" H 6145 3315 50  0001 C CNN
F 3 "" H 6145 3315 50  0001 C CNN
	1    6145 3315
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR022
U 1 1 5C15A75E
P 6145 4010
F 0 "#PWR022" H 6145 3860 50  0001 C CNN
F 1 "+12V" H 6145 4150 50  0000 C CNN
F 2 "" H 6145 4010 50  0000 C CNN
F 3 "" H 6145 4010 50  0000 C CNN
	1    6145 4010
	1    0    0    -1  
$EndComp
Wire Wire Line
	6145 4710 6145 4760
Wire Wire Line
	5545 4510 5620 4510
Wire Wire Line
	6545 4410 6745 4410
$Comp
L allcolours_analogue-rescue:D-device D5
U 1 1 5C15A767
P 6895 4410
F 0 "D5" H 6895 4194 50  0000 C CNN
F 1 "1n914/4148" H 6895 4285 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 6895 4410 50  0001 C CNN
F 3 "" H 6895 4410 50  0001 C CNN
	1    6895 4410
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R108
U 1 1 5C15A76D
P 7145 4560
F 0 "R108" V 7225 4560 50  0000 C CNN
F 1 "20K" V 7145 4560 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7075 4560 50  0001 C CNN
F 3 "" H 7145 4560 50  0000 C CNN
	1    7145 4560
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR031
U 1 1 5C15A773
P 7145 4760
F 0 "#PWR031" H 7145 4510 50  0001 C CNN
F 1 "GND" H 7145 4610 50  0000 C CNN
F 2 "" H 7145 4760 50  0000 C CNN
F 3 "" H 7145 4760 50  0000 C CNN
	1    7145 4760
	1    0    0    -1  
$EndComp
Wire Wire Line
	7045 4410 7145 4410
Wire Wire Line
	7145 4760 7145 4710
Connection ~ 7145 4410
Wire Wire Line
	6145 4110 6145 4010
Wire Wire Line
	7145 4410 7295 4410
$Comp
L allcolours_analogue-rescue:TL072-linear U19
U 2 1 5C15A77E
P 6245 4410
F 0 "U19" H 6586 4456 50  0000 L CNN
F 1 "TL072" H 6586 4365 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 6245 4410 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6245 4410 50  0001 C CNN
	2    6245 4410
	1    0    0    -1  
$EndComp
Wire Wire Line
	5745 4060 5745 4310
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J62
U 1 1 5C15A785
P 5545 4060
F 0 "J62" H 5465 3835 50  0000 C CNN
F 1 "compsr3" H 5465 3926 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5545 4060 50  0001 C CNN
F 3 "" H 5545 4060 50  0001 C CNN
	1    5545 4060
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R105
U 1 1 5C15A78B
P 5835 4460
F 0 "R105" V 5915 4460 50  0000 C CNN
F 1 "100K" V 5835 4460 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5765 4460 50  0001 C CNN
F 3 "" H 5835 4460 50  0000 C CNN
	1    5835 4460
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR014
U 1 1 5C15A791
P 5835 4660
F 0 "#PWR014" H 5835 4410 50  0001 C CNN
F 1 "GND" H 5835 4510 50  0000 C CNN
F 2 "" H 5835 4660 50  0000 C CNN
F 3 "" H 5835 4660 50  0000 C CNN
	1    5835 4660
	1    0    0    -1  
$EndComp
Wire Wire Line
	5835 4660 5835 4610
Connection ~ 5835 4310
Wire Wire Line
	5835 4310 5945 4310
Wire Wire Line
	5745 4310 5835 4310
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J59
U 1 1 5C15A79B
P 5345 4510
F 0 "J59" H 5265 4285 50  0000 C CNN
F 1 "compsr3" H 5265 4376 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5345 4510 50  0001 C CNN
F 3 "" H 5345 4510 50  0001 C CNN
	1    5345 4510
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R102
U 1 1 5C15A7A1
P 5620 4660
F 0 "R102" V 5700 4660 50  0000 C CNN
F 1 "100K" V 5620 4660 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5550 4660 50  0001 C CNN
F 3 "" H 5620 4660 50  0000 C CNN
	1    5620 4660
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR07
U 1 1 5C15A7A7
P 5620 4860
F 0 "#PWR07" H 5620 4610 50  0001 C CNN
F 1 "GND" H 5620 4710 50  0000 C CNN
F 2 "" H 5620 4860 50  0000 C CNN
F 3 "" H 5620 4860 50  0000 C CNN
	1    5620 4860
	1    0    0    -1  
$EndComp
Wire Wire Line
	5620 4860 5620 4810
Connection ~ 5620 4510
Wire Wire Line
	5620 4510 5945 4510
Text GLabel 7295 4410 2    60   Input ~ 0
SR3
$Comp
L power:-12V #PWR023
U 1 1 5C15A7B1
P 6145 4760
F 0 "#PWR023" H 6145 4860 50  0001 C CNN
F 1 "-12V" H 6160 4933 50  0000 C CNN
F 2 "" H 6145 4760 50  0001 C CNN
F 3 "" H 6145 4760 50  0001 C CNN
	1    6145 4760
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR026
U 1 1 5C15A7B7
P 6145 5330
F 0 "#PWR026" H 6145 5180 50  0001 C CNN
F 1 "+12V" H 6145 5470 50  0000 C CNN
F 2 "" H 6145 5330 50  0000 C CNN
F 3 "" H 6145 5330 50  0000 C CNN
	1    6145 5330
	1    0    0    -1  
$EndComp
Wire Wire Line
	6145 6030 6145 6080
Wire Wire Line
	5545 5830 5620 5830
Wire Wire Line
	6545 5730 6745 5730
$Comp
L allcolours_analogue-rescue:D-device D7
U 1 1 5C15A7C0
P 6895 5730
F 0 "D7" H 6895 5514 50  0000 C CNN
F 1 "1n914/4148" H 6895 5605 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 6895 5730 50  0001 C CNN
F 3 "" H 6895 5730 50  0001 C CNN
	1    6895 5730
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R109
U 1 1 5C15A7C6
P 7145 5880
F 0 "R109" V 7225 5880 50  0000 C CNN
F 1 "20K" V 7145 5880 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7075 5880 50  0001 C CNN
F 3 "" H 7145 5880 50  0000 C CNN
	1    7145 5880
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR032
U 1 1 5C15A7CC
P 7145 6080
F 0 "#PWR032" H 7145 5830 50  0001 C CNN
F 1 "GND" H 7145 5930 50  0000 C CNN
F 2 "" H 7145 6080 50  0000 C CNN
F 3 "" H 7145 6080 50  0000 C CNN
	1    7145 6080
	1    0    0    -1  
$EndComp
Wire Wire Line
	7045 5730 7145 5730
Wire Wire Line
	7145 6080 7145 6030
Connection ~ 7145 5730
Wire Wire Line
	6145 5430 6145 5330
Wire Wire Line
	7145 5730 7295 5730
$Comp
L allcolours_analogue-rescue:TL072-linear U20
U 1 1 5C15A7D7
P 6245 5730
F 0 "U20" H 6586 5776 50  0000 L CNN
F 1 "TL072" H 6586 5685 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 6245 5730 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6245 5730 50  0001 C CNN
	1    6245 5730
	1    0    0    -1  
$EndComp
Wire Wire Line
	5745 5380 5745 5630
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J63
U 1 1 5C15A7DE
P 5545 5380
F 0 "J63" H 5465 5155 50  0000 C CNN
F 1 "compsr4" H 5465 5246 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5545 5380 50  0001 C CNN
F 3 "" H 5545 5380 50  0001 C CNN
	1    5545 5380
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R106
U 1 1 5C15A7E4
P 5835 5780
F 0 "R106" V 5915 5780 50  0000 C CNN
F 1 "100K" V 5835 5780 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5765 5780 50  0001 C CNN
F 3 "" H 5835 5780 50  0000 C CNN
	1    5835 5780
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR015
U 1 1 5C15A7EA
P 5835 5980
F 0 "#PWR015" H 5835 5730 50  0001 C CNN
F 1 "GND" H 5835 5830 50  0000 C CNN
F 2 "" H 5835 5980 50  0000 C CNN
F 3 "" H 5835 5980 50  0000 C CNN
	1    5835 5980
	1    0    0    -1  
$EndComp
Wire Wire Line
	5835 5980 5835 5930
Connection ~ 5835 5630
Wire Wire Line
	5835 5630 5945 5630
Wire Wire Line
	5745 5630 5835 5630
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J60
U 1 1 5C15A7F4
P 5345 5830
F 0 "J60" H 5265 5605 50  0000 C CNN
F 1 "compsr4" H 5265 5696 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5345 5830 50  0001 C CNN
F 3 "" H 5345 5830 50  0001 C CNN
	1    5345 5830
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R103
U 1 1 5C15A7FA
P 5620 5980
F 0 "R103" V 5700 5980 50  0000 C CNN
F 1 "100K" V 5620 5980 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5550 5980 50  0001 C CNN
F 3 "" H 5620 5980 50  0000 C CNN
	1    5620 5980
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR010
U 1 1 5C15A800
P 5620 6180
F 0 "#PWR010" H 5620 5930 50  0001 C CNN
F 1 "GND" H 5620 6030 50  0000 C CNN
F 2 "" H 5620 6180 50  0000 C CNN
F 3 "" H 5620 6180 50  0000 C CNN
	1    5620 6180
	1    0    0    -1  
$EndComp
Wire Wire Line
	5620 6180 5620 6130
Connection ~ 5620 5830
Wire Wire Line
	5620 5830 5945 5830
Text GLabel 7295 5730 2    60   Input ~ 0
SR4
$Comp
L power:-12V #PWR027
U 1 1 5C15A80A
P 6145 6080
F 0 "#PWR027" H 6145 6180 50  0001 C CNN
F 1 "-12V" H 6160 6253 50  0000 C CNN
F 2 "" H 6145 6080 50  0001 C CNN
F 3 "" H 6145 6080 50  0001 C CNN
	1    6145 6080
	-1   0    0    1   
$EndComp
$EndSCHEMATC
