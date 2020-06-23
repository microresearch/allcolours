EESchema Schematic File Version 4
LIBS:touch-cache
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
Text Notes 1950 1060 0    60   ~ 0
euro_conn
$Comp
L allcolours_analogue-rescue:CONN_02X05-allcolours-rescue P1
U 1 1 5C3AA485
P 2150 1410
F 0 "P1" H 2150 1710 50  0000 C CNN
F 1 "CONN_02X05" H 2150 1110 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05_Pitch2.54mm" H 2150 210 50  0001 C CNN
F 3 "" H 2150 210 50  0000 C CNN
	1    2150 1410
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR02
U 1 1 5C3AA48C
P 1395 1100
F 0 "#PWR02" H 1395 950 50  0001 C CNN
F 1 "+12V" H 1395 1225 50  0000 C CNN
F 2 "" H 1395 1100 50  0000 C CNN
F 3 "" H 1395 1100 50  0000 C CNN
	1    1395 1100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR03
U 1 1 5C3AA492
P 2600 1410
F 0 "#PWR03" H 2600 1160 50  0001 C CNN
F 1 "GND" H 2600 1260 50  0000 C CNN
F 2 "" H 2600 1410 50  0000 C CNN
F 3 "" H 2600 1410 50  0000 C CNN
	1    2600 1410
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1410 2400 1410
Wire Wire Line
	2400 1310 2400 1410
Connection ~ 2400 1410
Wire Wire Line
	1900 1210 2400 1210
Wire Wire Line
	1900 1160 1900 1210
Wire Wire Line
	2400 1410 2400 1510
$Comp
L power:-12V #PWR01
U 1 1 5C3AA4A4
P 1315 1645
F 0 "#PWR01" H 1315 1745 50  0001 C CNN
F 1 "-12V" H 1330 1818 50  0000 C CNN
F 2 "" H 1315 1645 50  0001 C CNN
F 3 "" H 1315 1645 50  0001 C CNN
	1    1315 1645
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 1410 2600 1410
$Comp
L allcolours_analogue-rescue:CP1_Small-device C1
U 1 1 5C3AA4AB
P 1325 1285
F 0 "C1" H 1335 1355 50  0000 L CNN
F 1 "10u" H 1335 1205 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D4.0mm_P1.50mm" H 1325 1285 50  0001 C CNN
F 3 "" H 1325 1285 50  0000 C CNN
	1    1325 1285
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:CP1_Small-device C2
U 1 1 5C3AA4B4
P 1775 1635
F 0 "C2" H 1785 1705 50  0000 L CNN
F 1 "10u" H 1785 1555 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D4.0mm_P1.50mm" H 1775 1635 50  0001 C CNN
F 3 "" H 1775 1635 50  0000 C CNN
	1    1775 1635
	1    0    0    -1  
$EndComp
$Comp
L Device:D D2
U 1 1 5C3AA4BD
P 1545 1160
F 0 "D2" H 1545 1376 50  0000 C CNN
F 1 "1N5158" H 1545 1285 50  0000 C CNN
F 2 "Diodes_ThroughHole:D_A-405_P10.16mm_Horizontal" H 1545 1160 50  0001 C CNN
F 3 "~" H 1545 1160 50  0001 C CNN
	1    1545 1160
	1    0    0    -1  
$EndComp
Wire Wire Line
	1395 1100 1395 1125
$Comp
L Device:D D1
U 1 1 5C3AA4C8
P 1465 1610
F 0 "D1" H 1465 1394 50  0000 C CNN
F 1 "1N5158" H 1465 1485 50  0000 C CNN
F 2 "Diodes_ThroughHole:D_A-405_P10.16mm_Horizontal" H 1465 1610 50  0001 C CNN
F 3 "~" H 1465 1610 50  0001 C CNN
	1    1465 1610
	-1   0    0    1   
$EndComp
Wire Wire Line
	1315 1610 1315 1635
Wire Wire Line
	1325 1185 1325 1125
Wire Wire Line
	1325 1125 1395 1125
Wire Wire Line
	1695 1160 1900 1160
Connection ~ 1395 1125
Wire Wire Line
	1395 1125 1395 1160
Wire Wire Line
	1325 1385 1325 1415
Wire Wire Line
	1325 1415 1775 1415
Wire Wire Line
	1775 1735 1385 1735
Wire Wire Line
	1385 1735 1385 1635
Wire Wire Line
	1385 1635 1315 1635
Connection ~ 1315 1635
Wire Wire Line
	1315 1635 1315 1645
Wire Wire Line
	1900 1310 1900 1410
Wire Wire Line
	1900 1410 1775 1410
Wire Wire Line
	1775 1410 1775 1415
Connection ~ 1900 1410
Wire Wire Line
	1900 1410 1900 1510
Connection ~ 1775 1415
Wire Wire Line
	1775 1415 1775 1535
Wire Wire Line
	1615 1610 1900 1610
Connection ~ 1900 1210
Connection ~ 1900 1610
Wire Wire Line
	1900 1610 2400 1610
Text Notes 1390 2250 0    79   ~ 0
3.3v power for STM!
$Comp
L power:+9V #PWR0101
U 1 1 5F714501
P 1635 2590
F 0 "#PWR0101" H 1635 2440 50  0001 C CNN
F 1 "+9V" H 1650 2763 50  0000 C CNN
F 2 "" H 1635 2590 50  0001 C CNN
F 3 "" H 1635 2590 50  0001 C CNN
	1    1635 2590
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U16
U 1 1 5F7145BF
P 2040 2590
F 0 "U16" H 2040 2832 50  0000 C CNN
F 1 "LM1117-3.3" H 2040 2741 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 2040 2590 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 2040 2590 50  0001 C CNN
	1    2040 2590
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR0102
U 1 1 5F714687
P 2040 2950
F 0 "#PWR0102" H 2040 2700 50  0001 C CNN
F 1 "GND" H 2040 2800 50  0000 C CNN
F 2 "" H 2040 2950 50  0000 C CNN
F 3 "" H 2040 2950 50  0000 C CNN
	1    2040 2950
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:CP1_Small-device C30
U 1 1 5F71469E
P 1685 2690
F 0 "C30" H 1695 2760 50  0000 L CNN
F 1 "10u" H 1695 2610 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D4.0mm_P1.50mm" H 1685 2690 50  0001 C CNN
F 3 "" H 1685 2690 50  0000 C CNN
	1    1685 2690
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:CP1_Small-device C31
U 1 1 5F714819
P 2380 2690
F 0 "C31" H 2390 2760 50  0000 L CNN
F 1 "10u" H 2390 2610 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D4.0mm_P1.50mm" H 2380 2690 50  0001 C CNN
F 3 "" H 2380 2690 50  0000 C CNN
	1    2380 2690
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 5F7149A4
P 2435 2590
F 0 "#PWR0103" H 2435 2440 50  0001 C CNN
F 1 "+3.3V" H 2450 2763 50  0000 C CNN
F 2 "" H 2435 2590 50  0001 C CNN
F 3 "" H 2435 2590 50  0001 C CNN
	1    2435 2590
	1    0    0    -1  
$EndComp
Wire Wire Line
	2340 2590 2380 2590
Wire Wire Line
	2380 2590 2435 2590
Connection ~ 2380 2590
Wire Wire Line
	1630 2590 1635 2590
Connection ~ 1635 2590
Wire Wire Line
	1635 2590 1685 2590
Wire Wire Line
	1685 2590 1740 2590
Connection ~ 1685 2590
Wire Wire Line
	1685 2790 1685 2915
Wire Wire Line
	1685 2915 2040 2915
Wire Wire Line
	2040 2890 2040 2915
Wire Wire Line
	2040 2915 2380 2915
Wire Wire Line
	2380 2915 2380 2790
Connection ~ 2040 2915
Wire Wire Line
	2040 2915 2040 2950
$EndSCHEMATC
