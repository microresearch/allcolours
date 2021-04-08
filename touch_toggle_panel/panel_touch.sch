EESchema Schematic File Version 4
LIBS:touch_panel-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 11410 6235 0    118  ~ 0
For panel we have 4 sets of:\n\n       C- feedback out from jack\n       |\nA---VCA---B [B is also mix from B pad]\n       |\n       0-adc voltage for A->B VCA\n       |\n       o-freeze\n       |\n       O-adc voltage for insert\n       |\n       o-freeze\n\n\n\n\nPlus rec,play, push/pop!\n\nTouch pads are A, B, C(out) 2x voltage sun/mooncrescent for\n VCA and for voltage insert, and two freezes.\n\nHere all is plain pads. \n6x\nA- out from A\nB- in to Bmix\nC- out from jack\n1-adcX/divider\n2-adcX/for voltage/divider\n2xfreeze - plain pad/crescent+V
Text Notes 965  1235 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J9
U 1 1 5F27451B
P 1110 1055
F 0 "J9" H 1030 830 50  0000 C CNN
F 1 "Conn_01x01" H 1030 921 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1110 1055 50  0001 C CNN
F 3 "~" H 1110 1055 50  0001 C CNN
	1    1110 1055
	-1   0    0    1   
$EndComp
Text GLabel 1345 1055 2    50   Input ~ 0
F1
Wire Wire Line
	1310 1055 1345 1055
Text Notes 960  1570 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J7
U 1 1 5F274AA1
P 1105 1390
F 0 "J7" H 1025 1165 50  0000 C CNN
F 1 "Conn_01x01" H 1025 1256 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1105 1390 50  0001 C CNN
F 3 "~" H 1105 1390 50  0001 C CNN
	1    1105 1390
	-1   0    0    1   
$EndComp
Text GLabel 1340 1390 2    50   Input ~ 0
F2
Wire Wire Line
	1305 1390 1340 1390
Text Notes 960  1860 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J8
U 1 1 5F274D93
P 1105 1680
F 0 "J8" H 1025 1455 50  0000 C CNN
F 1 "Conn_01x01" H 1025 1546 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1105 1680 50  0001 C CNN
F 3 "~" H 1105 1680 50  0001 C CNN
	1    1105 1680
	-1   0    0    1   
$EndComp
Text GLabel 1340 1680 2    50   Input ~ 0
F3
Wire Wire Line
	1305 1680 1340 1680
Text Notes 1690 1240 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 606F46DC
P 1835 1060
F 0 "J3" H 1755 835 50  0000 C CNN
F 1 "Conn_01x01" H 1755 926 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1835 1060 50  0001 C CNN
F 3 "~" H 1835 1060 50  0001 C CNN
	1    1835 1060
	-1   0    0    1   
$EndComp
Text GLabel 2070 1060 2    50   Input ~ 0
F4
Wire Wire Line
	2035 1060 2070 1060
Text Notes 1685 1575 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J1
U 1 1 606F46E6
P 1830 1395
F 0 "J1" H 1750 1170 50  0000 C CNN
F 1 "Conn_01x01" H 1750 1261 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1830 1395 50  0001 C CNN
F 3 "~" H 1830 1395 50  0001 C CNN
	1    1830 1395
	-1   0    0    1   
$EndComp
Text GLabel 2065 1395 2    50   Input ~ 0
F5
Wire Wire Line
	2030 1395 2065 1395
Text Notes 1685 1865 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J2
U 1 1 606F46F0
P 1830 1685
F 0 "J2" H 1750 1460 50  0000 C CNN
F 1 "Conn_01x01" H 1750 1551 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1830 1685 50  0001 C CNN
F 3 "~" H 1830 1685 50  0001 C CNN
	1    1830 1685
	-1   0    0    1   
$EndComp
Text GLabel 2065 1685 2    50   Input ~ 0
F6
Wire Wire Line
	2030 1685 2065 1685
Text Notes 2370 1235 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J6
U 1 1 606F4811
P 2515 1055
F 0 "J6" H 2435 830 50  0000 C CNN
F 1 "Conn_01x01" H 2435 921 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2515 1055 50  0001 C CNN
F 3 "~" H 2515 1055 50  0001 C CNN
	1    2515 1055
	-1   0    0    1   
$EndComp
Text GLabel 2750 1055 2    50   Input ~ 0
F7
Wire Wire Line
	2715 1055 2750 1055
Text Notes 2365 1570 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 606F481B
P 2510 1390
F 0 "J4" H 2430 1165 50  0000 C CNN
F 1 "Conn_01x01" H 2430 1256 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2510 1390 50  0001 C CNN
F 3 "~" H 2510 1390 50  0001 C CNN
	1    2510 1390
	-1   0    0    1   
$EndComp
Text GLabel 2745 1390 2    50   Input ~ 0
F8
Wire Wire Line
	2710 1390 2745 1390
Text Notes 2365 1860 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J5
U 1 1 606F4825
P 2510 1680
F 0 "J5" H 2430 1455 50  0000 C CNN
F 1 "Conn_01x01" H 2430 1546 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2510 1680 50  0001 C CNN
F 3 "~" H 2510 1680 50  0001 C CNN
	1    2510 1680
	-1   0    0    1   
$EndComp
Text GLabel 2745 1680 2    50   Input ~ 0
F9
Wire Wire Line
	2710 1680 2745 1680
Text Notes 2985 1215 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J12
U 1 1 606F4931
P 3130 1035
F 0 "J12" H 3050 810 50  0000 C CNN
F 1 "Conn_01x01" H 3050 901 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3130 1035 50  0001 C CNN
F 3 "~" H 3130 1035 50  0001 C CNN
	1    3130 1035
	-1   0    0    1   
$EndComp
Text GLabel 3365 1035 2    50   Input ~ 0
F10
Wire Wire Line
	3330 1035 3365 1035
Text Notes 2980 1550 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J10
U 1 1 606F493B
P 3125 1370
F 0 "J10" H 3045 1145 50  0000 C CNN
F 1 "Conn_01x01" H 3045 1236 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3125 1370 50  0001 C CNN
F 3 "~" H 3125 1370 50  0001 C CNN
	1    3125 1370
	-1   0    0    1   
$EndComp
Text GLabel 3360 1370 2    50   Input ~ 0
F11
Wire Wire Line
	3325 1370 3360 1370
Text Notes 2980 1840 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J11
U 1 1 606F4945
P 3125 1660
F 0 "J11" H 3045 1435 50  0000 C CNN
F 1 "Conn_01x01" H 3045 1526 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3125 1660 50  0001 C CNN
F 3 "~" H 3125 1660 50  0001 C CNN
	1    3125 1660
	-1   0    0    1   
$EndComp
Text GLabel 3360 1660 2    50   Input ~ 0
GND
Wire Wire Line
	3325 1660 3360 1660
$Comp
L Connector_Generic:Conn_02x06_Odd_Even J13
U 1 1 606F4E27
P 4405 2050
F 0 "J13" H 4455 2467 50  0000 C CNN
F 1 "Conn_02x06_Odd_Even" H 4455 2376 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x06_Pitch2.54mm_SMD" H 4405 2050 50  0001 C CNN
F 3 "~" H 4405 2050 50  0001 C CNN
	1    4405 2050
	1    0    0    -1  
$EndComp
Text GLabel 4180 1850 0    50   Input ~ 0
F1
Wire Wire Line
	4180 1850 4205 1850
Wire Wire Line
	4180 1950 4205 1950
Wire Wire Line
	4180 2050 4205 2050
Wire Wire Line
	4180 2150 4205 2150
Wire Wire Line
	4180 2250 4205 2250
Wire Wire Line
	4180 2350 4205 2350
Text GLabel 4180 1950 0    50   Input ~ 0
F2
Text GLabel 4180 2050 0    50   Input ~ 0
F3
Text GLabel 4180 2150 0    50   Input ~ 0
F4
Text GLabel 4180 2250 0    50   Input ~ 0
F5
Text GLabel 4180 2350 0    50   Input ~ 0
F6
Text GLabel 4730 1850 2    50   Input ~ 0
F7
Wire Wire Line
	4705 1850 4730 1850
Wire Wire Line
	4705 1950 4730 1950
Wire Wire Line
	4705 2050 4730 2050
Wire Wire Line
	4705 2150 4730 2150
Wire Wire Line
	4705 2250 4730 2250
Wire Wire Line
	4705 2350 4730 2350
Text GLabel 4730 2150 2    50   Input ~ 0
F10
Text GLabel 4730 2250 2    50   Input ~ 0
F11
Text GLabel 4730 2350 2    50   Input ~ 0
GND
Text GLabel 4730 1950 2    50   Input ~ 0
F8
Text GLabel 4730 2050 2    50   Input ~ 0
F9
$EndSCHEMATC
