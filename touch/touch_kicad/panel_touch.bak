EESchema Schematic File Version 4
LIBS:touch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 780  3380 0    79   ~ 0
\n
Text Notes 7150 6290 0    118  ~ 0
For panel we have 4 sets of:\n\n       C- feedback out from jack\n       |\nA---VCA---B [B is also mix from B pad]\n       |\n       0-adc voltage for A->B VCA\n       |\n       o-freeze\n       |\n       O-adc voltage for insert\n       |\n       o-freeze\n\n\n\n\nPlus rec,play, push and pop!\n\nTouch pads are A, B, C(out) 2x voltage sun/mooncrescent for\n VCA and for voltage insert, and two freezes.\n\nHere all is plain pads. \n6x\nA- out from A\nB- in to Bmix\nC- out from jack\n1-adcX/divider\n2-adcX/for voltage/divider\n2xfreeze - plain pad/crescent+V
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 5F230F3E
P 960 3510
F 0 "J3" H 880 3285 50  0000 C CNN
F 1 "Conn_01x01" H 880 3376 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 960 3510 50  0001 C CNN
F 3 "~" H 960 3510 50  0001 C CNN
	1    960  3510
	-1   0    0    1   
$EndComp
Text GLabel 1210 3510 2    50   Input ~ 0
C1
Wire Wire Line
	1160 3510 1210 3510
Text Notes 780  3470 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5F231056
P 960 3675
F 0 "J4" H 880 3450 50  0000 C CNN
F 1 "Conn_01x01" H 880 3541 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 960 3675 50  0001 C CNN
F 3 "~" H 960 3675 50  0001 C CNN
	1    960  3675
	-1   0    0    1   
$EndComp
Text GLabel 1210 3675 2    50   Input ~ 0
B1
Wire Wire Line
	1160 3675 1210 3675
Text Notes 780  3745 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J5
U 1 1 5F233418
P 960 3825
F 0 "J5" H 880 3600 50  0000 C CNN
F 1 "Conn_01x01" H 880 3691 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 960 3825 50  0001 C CNN
F 3 "~" H 960 3825 50  0001 C CNN
	1    960  3825
	-1   0    0    1   
$EndComp
Text GLabel 1210 3825 2    50   Input ~ 0
IN1
Wire Wire Line
	1160 3825 1210 3825
Text Notes 2010 3635 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J9
U 1 1 5F233537
P 2155 3455
F 0 "J9" H 2075 3230 50  0000 C CNN
F 1 "Conn_01x01" H 2075 3321 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2155 3455 50  0001 C CNN
F 3 "~" H 2155 3455 50  0001 C CNN
	1    2155 3455
	-1   0    0    1   
$EndComp
Text GLabel 2405 3455 2    50   Input ~ 0
ADC0
Wire Wire Line
	2355 3455 2380 3455
Text Notes 2010 3850 0    79   ~ 0
\n
$Comp
L Device:R_Small R84
U 1 1 5F25FC69
P 2380 3555
F 0 "R84" H 2439 3601 50  0000 L CNN
F 1 "470K" H 2439 3510 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2380 3555 50  0001 C CNN
F 3 "~" H 2380 3555 50  0001 C CNN
	1    2380 3555
	1    0    0    -1  
$EndComp
Connection ~ 2380 3455
Wire Wire Line
	2380 3455 2405 3455
$Comp
L power:GND #PWR0124
U 1 1 5F25FD4B
P 2380 3690
F 0 "#PWR0124" H 2380 3440 50  0001 C CNN
F 1 "GND" H 2385 3517 50  0000 C CNN
F 2 "" H 2380 3690 50  0001 C CNN
F 3 "" H 2380 3690 50  0001 C CNN
	1    2380 3690
	1    0    0    -1  
$EndComp
Wire Wire Line
	2380 3655 2380 3690
$Comp
L Connector_Generic:Conn_01x01 J7
U 1 1 5F25FDA7
P 2005 3455
F 0 "J7" H 1925 3230 50  0000 C CNN
F 1 "Conn_01x01" H 1925 3321 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2005 3455 50  0001 C CNN
F 3 "~" H 2005 3455 50  0001 C CNN
	1    2005 3455
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0122
U 1 1 5F25FE64
P 1805 3420
F 0 "#PWR0122" H 1805 3270 50  0001 C CNN
F 1 "+3.3VA" H 1820 3593 50  0000 C CNN
F 2 "" H 1805 3420 50  0001 C CNN
F 3 "" H 1805 3420 50  0001 C CNN
	1    1805 3420
	1    0    0    -1  
$EndComp
Wire Wire Line
	1805 3420 1805 3455
Text Notes 2000 4290 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J8
U 1 1 5F2623C3
P 2145 4110
F 0 "J8" H 2065 3885 50  0000 C CNN
F 1 "Conn_01x01" H 2065 3976 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2145 4110 50  0001 C CNN
F 3 "~" H 2145 4110 50  0001 C CNN
	1    2145 4110
	-1   0    0    1   
$EndComp
Text GLabel 2395 4110 2    50   Input ~ 0
ADC1
Wire Wire Line
	2345 4110 2370 4110
Text Notes 2000 4505 0    79   ~ 0
\n
$Comp
L Device:R_Small R83
U 1 1 5F2623CD
P 2370 4210
F 0 "R83" H 2429 4256 50  0000 L CNN
F 1 "470K" H 2429 4165 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2370 4210 50  0001 C CNN
F 3 "~" H 2370 4210 50  0001 C CNN
	1    2370 4210
	1    0    0    -1  
$EndComp
Connection ~ 2370 4110
Wire Wire Line
	2370 4110 2395 4110
$Comp
L power:GND #PWR0123
U 1 1 5F2623D6
P 2370 4345
F 0 "#PWR0123" H 2370 4095 50  0001 C CNN
F 1 "GND" H 2375 4172 50  0000 C CNN
F 2 "" H 2370 4345 50  0001 C CNN
F 3 "" H 2370 4345 50  0001 C CNN
	1    2370 4345
	1    0    0    -1  
$EndComp
Wire Wire Line
	2370 4310 2370 4345
$Comp
L Connector_Generic:Conn_01x01 J6
U 1 1 5F2623DD
P 1995 4110
F 0 "J6" H 1915 3885 50  0000 C CNN
F 1 "Conn_01x01" H 1915 3976 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1995 4110 50  0001 C CNN
F 3 "~" H 1995 4110 50  0001 C CNN
	1    1995 4110
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0121
U 1 1 5F2623E4
P 1795 4075
F 0 "#PWR0121" H 1795 3925 50  0001 C CNN
F 1 "+3.3VA" H 1810 4248 50  0000 C CNN
F 2 "" H 1795 4075 50  0001 C CNN
F 3 "" H 1795 4075 50  0001 C CNN
	1    1795 4075
	1    0    0    -1  
$EndComp
Wire Wire Line
	1795 4075 1795 4110
Text Notes 3135 3595 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J12
U 1 1 5F263C71
P 3280 3415
F 0 "J12" H 3200 3190 50  0000 C CNN
F 1 "Conn_01x01" H 3200 3281 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3280 3415 50  0001 C CNN
F 3 "~" H 3280 3415 50  0001 C CNN
	1    3280 3415
	-1   0    0    1   
$EndComp
Text GLabel 3515 3415 2    50   Input ~ 0
F1
Wire Wire Line
	3480 3415 3515 3415
$Comp
L power:GND #PWR0125
U 1 1 5F270988
P 2930 3440
F 0 "#PWR0125" H 2930 3190 50  0001 C CNN
F 1 "GND" H 2935 3267 50  0000 C CNN
F 2 "" H 2930 3440 50  0001 C CNN
F 3 "" H 2930 3440 50  0001 C CNN
	1    2930 3440
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J10
U 1 1 5F263C78
P 3130 3415
F 0 "J10" H 3050 3190 50  0000 C CNN
F 1 "Conn_01x01" H 3050 3281 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3130 3415 50  0001 C CNN
F 3 "~" H 3130 3415 50  0001 C CNN
	1    3130 3415
	1    0    0    -1  
$EndComp
Wire Wire Line
	2930 3415 2930 3440
Text Notes 2725 3120 0    50   ~ 0
freeze is to GND\n
Text Notes 3140 4075 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J13
U 1 1 5F272F5C
P 3285 3895
F 0 "J13" H 3205 3670 50  0000 C CNN
F 1 "Conn_01x01" H 3205 3761 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3285 3895 50  0001 C CNN
F 3 "~" H 3285 3895 50  0001 C CNN
	1    3285 3895
	-1   0    0    1   
$EndComp
Text GLabel 3520 3895 2    50   Input ~ 0
F2
Wire Wire Line
	3485 3895 3520 3895
$Comp
L power:GND #PWR0126
U 1 1 5F272F65
P 2935 3920
F 0 "#PWR0126" H 2935 3670 50  0001 C CNN
F 1 "GND" H 2940 3747 50  0000 C CNN
F 2 "" H 2935 3920 50  0001 C CNN
F 3 "" H 2935 3920 50  0001 C CNN
	1    2935 3920
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J11
U 1 1 5F272F6B
P 3135 3895
F 0 "J11" H 3055 3670 50  0000 C CNN
F 1 "Conn_01x01" H 3055 3761 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3135 3895 50  0001 C CNN
F 3 "~" H 3135 3895 50  0001 C CNN
	1    3135 3895
	1    0    0    -1  
$EndComp
Wire Wire Line
	2935 3895 2935 3920
Text Notes 1535 1395 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J21
U 1 1 5F27451B
P 1680 1215
F 0 "J21" H 1600 990 50  0000 C CNN
F 1 "Conn_01x01" H 1600 1081 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1680 1215 50  0001 C CNN
F 3 "~" H 1680 1215 50  0001 C CNN
	1    1680 1215
	-1   0    0    1   
$EndComp
Text GLabel 1915 1215 2    50   Input ~ 0
Frec
Wire Wire Line
	1880 1215 1915 1215
$Comp
L power:GND #PWR0130
U 1 1 5F274524
P 1330 1240
F 0 "#PWR0130" H 1330 990 50  0001 C CNN
F 1 "GND" H 1335 1067 50  0000 C CNN
F 2 "" H 1330 1240 50  0001 C CNN
F 3 "" H 1330 1240 50  0001 C CNN
	1    1330 1240
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J17
U 1 1 5F27452A
P 1530 1215
F 0 "J17" H 1450 990 50  0000 C CNN
F 1 "Conn_01x01" H 1450 1081 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1530 1215 50  0001 C CNN
F 3 "~" H 1530 1215 50  0001 C CNN
	1    1530 1215
	1    0    0    -1  
$EndComp
Wire Wire Line
	1330 1215 1330 1240
Text Notes 1530 1730 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J19
U 1 1 5F274AA1
P 1675 1550
F 0 "J19" H 1595 1325 50  0000 C CNN
F 1 "Conn_01x01" H 1595 1416 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1675 1550 50  0001 C CNN
F 3 "~" H 1675 1550 50  0001 C CNN
	1    1675 1550
	-1   0    0    1   
$EndComp
Text GLabel 1910 1550 2    50   Input ~ 0
Fplay
Wire Wire Line
	1875 1550 1910 1550
$Comp
L power:GND #PWR0128
U 1 1 5F274AAA
P 1325 1575
F 0 "#PWR0128" H 1325 1325 50  0001 C CNN
F 1 "GND" H 1330 1402 50  0000 C CNN
F 2 "" H 1325 1575 50  0001 C CNN
F 3 "" H 1325 1575 50  0001 C CNN
	1    1325 1575
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J15
U 1 1 5F274AB0
P 1525 1550
F 0 "J15" H 1445 1325 50  0000 C CNN
F 1 "Conn_01x01" H 1445 1416 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1525 1550 50  0001 C CNN
F 3 "~" H 1525 1550 50  0001 C CNN
	1    1525 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1325 1550 1325 1575
Text Notes 1530 2020 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J20
U 1 1 5F274D93
P 1675 1840
F 0 "J20" H 1595 1615 50  0000 C CNN
F 1 "Conn_01x01" H 1595 1706 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1675 1840 50  0001 C CNN
F 3 "~" H 1675 1840 50  0001 C CNN
	1    1675 1840
	-1   0    0    1   
$EndComp
Text GLabel 1910 1840 2    50   Input ~ 0
Fpush
Wire Wire Line
	1875 1840 1910 1840
$Comp
L power:GND #PWR0129
U 1 1 5F274D9C
P 1325 1865
F 0 "#PWR0129" H 1325 1615 50  0001 C CNN
F 1 "GND" H 1330 1692 50  0000 C CNN
F 2 "" H 1325 1865 50  0001 C CNN
F 3 "" H 1325 1865 50  0001 C CNN
	1    1325 1865
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J16
U 1 1 5F274DA2
P 1525 1840
F 0 "J16" H 1445 1615 50  0000 C CNN
F 1 "Conn_01x01" H 1445 1706 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1525 1840 50  0001 C CNN
F 3 "~" H 1525 1840 50  0001 C CNN
	1    1525 1840
	1    0    0    -1  
$EndComp
Wire Wire Line
	1325 1840 1325 1865
Text Notes 1525 2355 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J18
U 1 1 5F274DAB
P 1670 2175
F 0 "J18" H 1590 1950 50  0000 C CNN
F 1 "Conn_01x01" H 1590 2041 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1670 2175 50  0001 C CNN
F 3 "~" H 1670 2175 50  0001 C CNN
	1    1670 2175
	-1   0    0    1   
$EndComp
Text GLabel 1905 2175 2    50   Input ~ 0
Fpop
Wire Wire Line
	1870 2175 1905 2175
$Comp
L power:GND #PWR0127
U 1 1 5F274DB4
P 1320 2200
F 0 "#PWR0127" H 1320 1950 50  0001 C CNN
F 1 "GND" H 1325 2027 50  0000 C CNN
F 2 "" H 1320 2200 50  0001 C CNN
F 3 "" H 1320 2200 50  0001 C CNN
	1    1320 2200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J14
U 1 1 5F274DBA
P 1520 2175
F 0 "J14" H 1440 1950 50  0000 C CNN
F 1 "Conn_01x01" H 1440 2041 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1520 2175 50  0001 C CNN
F 3 "~" H 1520 2175 50  0001 C CNN
	1    1520 2175
	1    0    0    -1  
$EndComp
Wire Wire Line
	1320 2175 1320 2200
Text Notes 1055 3190 0    118  ~ 0
[1]
Text Notes 4000 3655 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J45
U 1 1 5F283EF8
P 4145 3525
F 0 "J45" H 4065 3300 50  0000 C CNN
F 1 "Conn_01x01" H 4065 3391 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4145 3525 50  0001 C CNN
F 3 "~" H 4145 3525 50  0001 C CNN
	1    4145 3525
	-1   0    0    1   
$EndComp
Text GLabel 4395 3525 2    50   Input ~ 0
C2
Wire Wire Line
	4345 3525 4395 3525
Text Notes 4000 3745 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J46
U 1 1 5F283F02
P 4145 3690
F 0 "J46" H 4065 3465 50  0000 C CNN
F 1 "Conn_01x01" H 4065 3556 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4145 3690 50  0001 C CNN
F 3 "~" H 4145 3690 50  0001 C CNN
	1    4145 3690
	-1   0    0    1   
$EndComp
Text GLabel 4395 3690 2    50   Input ~ 0
B2
Wire Wire Line
	4345 3690 4395 3690
Text Notes 4000 4020 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J47
U 1 1 5F283F0C
P 4145 3840
F 0 "J47" H 4065 3615 50  0000 C CNN
F 1 "Conn_01x01" H 4065 3706 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4145 3840 50  0001 C CNN
F 3 "~" H 4145 3840 50  0001 C CNN
	1    4145 3840
	-1   0    0    1   
$EndComp
Text GLabel 4395 3840 2    50   Input ~ 0
IN2
Wire Wire Line
	4345 3840 4395 3840
Text Notes 5195 3650 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J62
U 1 1 5F283F16
P 5340 3470
F 0 "J62" H 5260 3245 50  0000 C CNN
F 1 "Conn_01x01" H 5260 3336 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5340 3470 50  0001 C CNN
F 3 "~" H 5340 3470 50  0001 C CNN
	1    5340 3470
	-1   0    0    1   
$EndComp
Text GLabel 5590 3470 2    50   Input ~ 0
ADC2
Wire Wire Line
	5540 3470 5565 3470
Text Notes 5195 3865 0    79   ~ 0
\n
$Comp
L Device:R_Small R101
U 1 1 5F283F20
P 5565 3570
F 0 "R101" H 5624 3616 50  0000 L CNN
F 1 "470K" H 5624 3525 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5565 3570 50  0001 C CNN
F 3 "~" H 5565 3570 50  0001 C CNN
	1    5565 3570
	1    0    0    -1  
$EndComp
Connection ~ 5565 3470
Wire Wire Line
	5565 3470 5590 3470
$Comp
L power:GND #PWR0209
U 1 1 5F283F29
P 5565 3705
F 0 "#PWR0209" H 5565 3455 50  0001 C CNN
F 1 "GND" H 5570 3532 50  0000 C CNN
F 2 "" H 5565 3705 50  0001 C CNN
F 3 "" H 5565 3705 50  0001 C CNN
	1    5565 3705
	1    0    0    -1  
$EndComp
Wire Wire Line
	5565 3670 5565 3705
$Comp
L Connector_Generic:Conn_01x01 J56
U 1 1 5F283F30
P 5190 3470
F 0 "J56" H 5110 3245 50  0000 C CNN
F 1 "Conn_01x01" H 5110 3336 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5190 3470 50  0001 C CNN
F 3 "~" H 5190 3470 50  0001 C CNN
	1    5190 3470
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0203
U 1 1 5F283F37
P 4990 3435
F 0 "#PWR0203" H 4990 3285 50  0001 C CNN
F 1 "+3.3VA" H 5005 3608 50  0000 C CNN
F 2 "" H 4990 3435 50  0001 C CNN
F 3 "" H 4990 3435 50  0001 C CNN
	1    4990 3435
	1    0    0    -1  
$EndComp
Wire Wire Line
	4990 3435 4990 3470
Text Notes 5185 4305 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J60
U 1 1 5F283F3F
P 5330 4125
F 0 "J60" H 5250 3900 50  0000 C CNN
F 1 "Conn_01x01" H 5250 3991 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5330 4125 50  0001 C CNN
F 3 "~" H 5330 4125 50  0001 C CNN
	1    5330 4125
	-1   0    0    1   
$EndComp
Text GLabel 5580 4125 2    50   Input ~ 0
ADC3
Wire Wire Line
	5530 4125 5555 4125
Text Notes 5185 4520 0    79   ~ 0
\n
$Comp
L Device:R_Small R99
U 1 1 5F283F49
P 5555 4225
F 0 "R99" H 5614 4271 50  0000 L CNN
F 1 "470K" H 5614 4180 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5555 4225 50  0001 C CNN
F 3 "~" H 5555 4225 50  0001 C CNN
	1    5555 4225
	1    0    0    -1  
$EndComp
Connection ~ 5555 4125
Wire Wire Line
	5555 4125 5580 4125
$Comp
L power:GND #PWR0207
U 1 1 5F283F52
P 5555 4360
F 0 "#PWR0207" H 5555 4110 50  0001 C CNN
F 1 "GND" H 5560 4187 50  0000 C CNN
F 2 "" H 5555 4360 50  0001 C CNN
F 3 "" H 5555 4360 50  0001 C CNN
	1    5555 4360
	1    0    0    -1  
$EndComp
Wire Wire Line
	5555 4325 5555 4360
$Comp
L Connector_Generic:Conn_01x01 J54
U 1 1 5F283F59
P 5180 4125
F 0 "J54" H 5100 3900 50  0000 C CNN
F 1 "Conn_01x01" H 5100 3991 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5180 4125 50  0001 C CNN
F 3 "~" H 5180 4125 50  0001 C CNN
	1    5180 4125
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0201
U 1 1 5F283F60
P 4980 4090
F 0 "#PWR0201" H 4980 3940 50  0001 C CNN
F 1 "+3.3VA" H 4995 4263 50  0000 C CNN
F 2 "" H 4980 4090 50  0001 C CNN
F 3 "" H 4980 4090 50  0001 C CNN
	1    4980 4090
	1    0    0    -1  
$EndComp
Wire Wire Line
	4980 4090 4980 4125
Text Notes 6320 3610 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J72
U 1 1 5F283F68
P 6465 3430
F 0 "J72" H 6385 3205 50  0000 C CNN
F 1 "Conn_01x01" H 6385 3296 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6465 3430 50  0001 C CNN
F 3 "~" H 6465 3430 50  0001 C CNN
	1    6465 3430
	-1   0    0    1   
$EndComp
Text GLabel 6700 3430 2    50   Input ~ 0
F3
Wire Wire Line
	6665 3430 6700 3430
$Comp
L power:GND #PWR0213
U 1 1 5F283F71
P 6115 3455
F 0 "#PWR0213" H 6115 3205 50  0001 C CNN
F 1 "GND" H 6120 3282 50  0000 C CNN
F 2 "" H 6115 3455 50  0001 C CNN
F 3 "" H 6115 3455 50  0001 C CNN
	1    6115 3455
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J66
U 1 1 5F283F77
P 6315 3430
F 0 "J66" H 6235 3205 50  0000 C CNN
F 1 "Conn_01x01" H 6235 3296 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6315 3430 50  0001 C CNN
F 3 "~" H 6315 3430 50  0001 C CNN
	1    6315 3430
	1    0    0    -1  
$EndComp
Wire Wire Line
	6115 3430 6115 3455
Text Notes 5910 3135 0    50   ~ 0
freeze is to GND\n
Text Notes 6325 4090 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J74
U 1 1 5F283F81
P 6470 3910
F 0 "J74" H 6390 3685 50  0000 C CNN
F 1 "Conn_01x01" H 6390 3776 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6470 3910 50  0001 C CNN
F 3 "~" H 6470 3910 50  0001 C CNN
	1    6470 3910
	-1   0    0    1   
$EndComp
Text GLabel 6705 3910 2    50   Input ~ 0
F4
Wire Wire Line
	6670 3910 6705 3910
$Comp
L power:GND #PWR0215
U 1 1 5F283F8A
P 6120 3935
F 0 "#PWR0215" H 6120 3685 50  0001 C CNN
F 1 "GND" H 6125 3762 50  0000 C CNN
F 2 "" H 6120 3935 50  0001 C CNN
F 3 "" H 6120 3935 50  0001 C CNN
	1    6120 3935
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J68
U 1 1 5F283F90
P 6320 3910
F 0 "J68" H 6240 3685 50  0000 C CNN
F 1 "Conn_01x01" H 6240 3776 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6320 3910 50  0001 C CNN
F 3 "~" H 6320 3910 50  0001 C CNN
	1    6320 3910
	1    0    0    -1  
$EndComp
Wire Wire Line
	6120 3910 6120 3935
Text Notes 4240 3205 0    118  ~ 0
[2]
Text Notes 780  5615 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J23
U 1 1 5F28521E
P 925 5485
F 0 "J23" H 845 5260 50  0000 C CNN
F 1 "Conn_01x01" H 845 5351 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 925 5485 50  0001 C CNN
F 3 "~" H 925 5485 50  0001 C CNN
	1    925  5485
	-1   0    0    1   
$EndComp
Text GLabel 1175 5485 2    50   Input ~ 0
C3
Wire Wire Line
	1125 5485 1175 5485
Text Notes 780  5705 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J24
U 1 1 5F285228
P 925 5650
F 0 "J24" H 845 5425 50  0000 C CNN
F 1 "Conn_01x01" H 845 5516 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 925 5650 50  0001 C CNN
F 3 "~" H 925 5650 50  0001 C CNN
	1    925  5650
	-1   0    0    1   
$EndComp
Text GLabel 1175 5650 2    50   Input ~ 0
B3
Wire Wire Line
	1125 5650 1175 5650
Text Notes 780  5980 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J25
U 1 1 5F285232
P 925 5800
F 0 "J25" H 845 5575 50  0000 C CNN
F 1 "Conn_01x01" H 845 5666 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 925 5800 50  0001 C CNN
F 3 "~" H 925 5800 50  0001 C CNN
	1    925  5800
	-1   0    0    1   
$EndComp
Text GLabel 1175 5800 2    50   Input ~ 0
IN3
Wire Wire Line
	1125 5800 1175 5800
Text Notes 1975 5610 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J34
U 1 1 5F28523C
P 2120 5430
F 0 "J34" H 2040 5205 50  0000 C CNN
F 1 "Conn_01x01" H 2040 5296 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2120 5430 50  0001 C CNN
F 3 "~" H 2120 5430 50  0001 C CNN
	1    2120 5430
	-1   0    0    1   
$EndComp
Text GLabel 2370 5430 2    50   Input ~ 0
ADC4
Wire Wire Line
	2320 5430 2345 5430
Text Notes 1975 5825 0    79   ~ 0
\n
$Comp
L Device:R_Small R96
U 1 1 5F285246
P 2345 5530
F 0 "R96" H 2404 5576 50  0000 L CNN
F 1 "470K" H 2404 5485 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2345 5530 50  0001 C CNN
F 3 "~" H 2345 5530 50  0001 C CNN
	1    2345 5530
	1    0    0    -1  
$EndComp
Connection ~ 2345 5430
Wire Wire Line
	2345 5430 2370 5430
$Comp
L power:GND #PWR0194
U 1 1 5F28524F
P 2345 5665
F 0 "#PWR0194" H 2345 5415 50  0001 C CNN
F 1 "GND" H 2350 5492 50  0000 C CNN
F 2 "" H 2345 5665 50  0001 C CNN
F 3 "" H 2345 5665 50  0001 C CNN
	1    2345 5665
	1    0    0    -1  
$EndComp
Wire Wire Line
	2345 5630 2345 5665
$Comp
L Connector_Generic:Conn_01x01 J30
U 1 1 5F285256
P 1970 5430
F 0 "J30" H 1890 5205 50  0000 C CNN
F 1 "Conn_01x01" H 1890 5296 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1970 5430 50  0001 C CNN
F 3 "~" H 1970 5430 50  0001 C CNN
	1    1970 5430
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR040
U 1 1 5F28525D
P 1770 5395
F 0 "#PWR040" H 1770 5245 50  0001 C CNN
F 1 "+3.3VA" H 1785 5568 50  0000 C CNN
F 2 "" H 1770 5395 50  0001 C CNN
F 3 "" H 1770 5395 50  0001 C CNN
	1    1770 5395
	1    0    0    -1  
$EndComp
Wire Wire Line
	1770 5395 1770 5430
Text Notes 1965 6265 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J33
U 1 1 5F285265
P 2110 6085
F 0 "J33" H 2030 5860 50  0000 C CNN
F 1 "Conn_01x01" H 2030 5951 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2110 6085 50  0001 C CNN
F 3 "~" H 2110 6085 50  0001 C CNN
	1    2110 6085
	-1   0    0    1   
$EndComp
Text GLabel 2360 6085 2    50   Input ~ 0
ADC5
Wire Wire Line
	2310 6085 2335 6085
Text Notes 1965 6480 0    79   ~ 0
\n
$Comp
L Device:R_Small R95
U 1 1 5F28526F
P 2335 6185
F 0 "R95" H 2394 6231 50  0000 L CNN
F 1 "470K" H 2394 6140 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2335 6185 50  0001 C CNN
F 3 "~" H 2335 6185 50  0001 C CNN
	1    2335 6185
	1    0    0    -1  
$EndComp
Connection ~ 2335 6085
Wire Wire Line
	2335 6085 2360 6085
$Comp
L power:GND #PWR0193
U 1 1 5F285278
P 2335 6320
F 0 "#PWR0193" H 2335 6070 50  0001 C CNN
F 1 "GND" H 2340 6147 50  0000 C CNN
F 2 "" H 2335 6320 50  0001 C CNN
F 3 "" H 2335 6320 50  0001 C CNN
	1    2335 6320
	1    0    0    -1  
$EndComp
Wire Wire Line
	2335 6285 2335 6320
$Comp
L Connector_Generic:Conn_01x01 J29
U 1 1 5F28527F
P 1960 6085
F 0 "J29" H 1880 5860 50  0000 C CNN
F 1 "Conn_01x01" H 1880 5951 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1960 6085 50  0001 C CNN
F 3 "~" H 1960 6085 50  0001 C CNN
	1    1960 6085
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR039
U 1 1 5F285286
P 1760 6050
F 0 "#PWR039" H 1760 5900 50  0001 C CNN
F 1 "+3.3VA" H 1775 6223 50  0000 C CNN
F 2 "" H 1760 6050 50  0001 C CNN
F 3 "" H 1760 6050 50  0001 C CNN
	1    1760 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1760 6050 1760 6085
Text Notes 3100 5570 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J41
U 1 1 5F28528E
P 3245 5390
F 0 "J41" H 3165 5165 50  0000 C CNN
F 1 "Conn_01x01" H 3165 5256 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3245 5390 50  0001 C CNN
F 3 "~" H 3245 5390 50  0001 C CNN
	1    3245 5390
	-1   0    0    1   
$EndComp
Text GLabel 3480 5390 2    50   Input ~ 0
F5
Wire Wire Line
	3445 5390 3480 5390
$Comp
L power:GND #PWR0197
U 1 1 5F285297
P 2895 5415
F 0 "#PWR0197" H 2895 5165 50  0001 C CNN
F 1 "GND" H 2900 5242 50  0000 C CNN
F 2 "" H 2895 5415 50  0001 C CNN
F 3 "" H 2895 5415 50  0001 C CNN
	1    2895 5415
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J37
U 1 1 5F28529D
P 3095 5390
F 0 "J37" H 3015 5165 50  0000 C CNN
F 1 "Conn_01x01" H 3015 5256 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3095 5390 50  0001 C CNN
F 3 "~" H 3095 5390 50  0001 C CNN
	1    3095 5390
	1    0    0    -1  
$EndComp
Wire Wire Line
	2895 5390 2895 5415
Text Notes 2690 5095 0    50   ~ 0
freeze is to GND\n
Text Notes 3105 6050 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J42
U 1 1 5F2852A7
P 3250 5870
F 0 "J42" H 3170 5645 50  0000 C CNN
F 1 "Conn_01x01" H 3170 5736 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3250 5870 50  0001 C CNN
F 3 "~" H 3250 5870 50  0001 C CNN
	1    3250 5870
	-1   0    0    1   
$EndComp
Text GLabel 3485 5870 2    50   Input ~ 0
F6
Wire Wire Line
	3450 5870 3485 5870
$Comp
L power:GND #PWR0198
U 1 1 5F2852B0
P 2900 5895
F 0 "#PWR0198" H 2900 5645 50  0001 C CNN
F 1 "GND" H 2905 5722 50  0000 C CNN
F 2 "" H 2900 5895 50  0001 C CNN
F 3 "" H 2900 5895 50  0001 C CNN
	1    2900 5895
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J38
U 1 1 5F2852B6
P 3100 5870
F 0 "J38" H 3020 5645 50  0000 C CNN
F 1 "Conn_01x01" H 3020 5736 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3100 5870 50  0001 C CNN
F 3 "~" H 3100 5870 50  0001 C CNN
	1    3100 5870
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 5870 2900 5895
Text Notes 1020 5165 0    118  ~ 0
[3]
Text Notes 3965 5630 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J48
U 1 1 5F2852C0
P 4110 5500
F 0 "J48" H 4030 5275 50  0000 C CNN
F 1 "Conn_01x01" H 4030 5366 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4110 5500 50  0001 C CNN
F 3 "~" H 4110 5500 50  0001 C CNN
	1    4110 5500
	-1   0    0    1   
$EndComp
Text GLabel 4360 5500 2    50   Input ~ 0
C4
Wire Wire Line
	4310 5500 4360 5500
Text Notes 3965 5720 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J49
U 1 1 5F2852CA
P 4110 5665
F 0 "J49" H 4030 5440 50  0000 C CNN
F 1 "Conn_01x01" H 4030 5531 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4110 5665 50  0001 C CNN
F 3 "~" H 4110 5665 50  0001 C CNN
	1    4110 5665
	-1   0    0    1   
$EndComp
Text GLabel 4360 5665 2    50   Input ~ 0
B4
Wire Wire Line
	4310 5665 4360 5665
Text Notes 3965 5995 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J50
U 1 1 5F2852D4
P 4110 5815
F 0 "J50" H 4030 5590 50  0000 C CNN
F 1 "Conn_01x01" H 4030 5681 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4110 5815 50  0001 C CNN
F 3 "~" H 4110 5815 50  0001 C CNN
	1    4110 5815
	-1   0    0    1   
$EndComp
Text GLabel 4360 5815 2    50   Input ~ 0
IN4
Wire Wire Line
	4310 5815 4360 5815
Text Notes 5160 5625 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J63
U 1 1 5F2852DE
P 5305 5445
F 0 "J63" H 5225 5220 50  0000 C CNN
F 1 "Conn_01x01" H 5225 5311 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5305 5445 50  0001 C CNN
F 3 "~" H 5305 5445 50  0001 C CNN
	1    5305 5445
	-1   0    0    1   
$EndComp
Text GLabel 5555 5445 2    50   Input ~ 0
ADC6
Wire Wire Line
	5505 5445 5530 5445
Text Notes 5160 5840 0    79   ~ 0
\n
$Comp
L Device:R_Small R102
U 1 1 5F2852E8
P 5530 5545
F 0 "R102" H 5589 5591 50  0000 L CNN
F 1 "470K" H 5589 5500 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5530 5545 50  0001 C CNN
F 3 "~" H 5530 5545 50  0001 C CNN
	1    5530 5545
	1    0    0    -1  
$EndComp
Connection ~ 5530 5445
Wire Wire Line
	5530 5445 5555 5445
$Comp
L power:GND #PWR0210
U 1 1 5F2852F1
P 5530 5680
F 0 "#PWR0210" H 5530 5430 50  0001 C CNN
F 1 "GND" H 5535 5507 50  0000 C CNN
F 2 "" H 5530 5680 50  0001 C CNN
F 3 "" H 5530 5680 50  0001 C CNN
	1    5530 5680
	1    0    0    -1  
$EndComp
Wire Wire Line
	5530 5645 5530 5680
$Comp
L Connector_Generic:Conn_01x01 J57
U 1 1 5F2852F8
P 5155 5445
F 0 "J57" H 5075 5220 50  0000 C CNN
F 1 "Conn_01x01" H 5075 5311 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5155 5445 50  0001 C CNN
F 3 "~" H 5155 5445 50  0001 C CNN
	1    5155 5445
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0204
U 1 1 5F2852FF
P 4955 5410
F 0 "#PWR0204" H 4955 5260 50  0001 C CNN
F 1 "+3.3VA" H 4970 5583 50  0000 C CNN
F 2 "" H 4955 5410 50  0001 C CNN
F 3 "" H 4955 5410 50  0001 C CNN
	1    4955 5410
	1    0    0    -1  
$EndComp
Wire Wire Line
	4955 5410 4955 5445
Text Notes 5150 6280 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J61
U 1 1 5F285307
P 5295 6100
F 0 "J61" H 5215 5875 50  0000 C CNN
F 1 "Conn_01x01" H 5215 5966 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5295 6100 50  0001 C CNN
F 3 "~" H 5295 6100 50  0001 C CNN
	1    5295 6100
	-1   0    0    1   
$EndComp
Text GLabel 5545 6100 2    50   Input ~ 0
ADC7
Wire Wire Line
	5495 6100 5520 6100
Text Notes 5150 6495 0    79   ~ 0
\n
$Comp
L Device:R_Small R100
U 1 1 5F285311
P 5520 6200
F 0 "R100" H 5579 6246 50  0000 L CNN
F 1 "470K" H 5579 6155 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5520 6200 50  0001 C CNN
F 3 "~" H 5520 6200 50  0001 C CNN
	1    5520 6200
	1    0    0    -1  
$EndComp
Connection ~ 5520 6100
Wire Wire Line
	5520 6100 5545 6100
$Comp
L power:GND #PWR0208
U 1 1 5F28531A
P 5520 6335
F 0 "#PWR0208" H 5520 6085 50  0001 C CNN
F 1 "GND" H 5525 6162 50  0000 C CNN
F 2 "" H 5520 6335 50  0001 C CNN
F 3 "" H 5520 6335 50  0001 C CNN
	1    5520 6335
	1    0    0    -1  
$EndComp
Wire Wire Line
	5520 6300 5520 6335
$Comp
L Connector_Generic:Conn_01x01 J55
U 1 1 5F285321
P 5145 6100
F 0 "J55" H 5065 5875 50  0000 C CNN
F 1 "Conn_01x01" H 5065 5966 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5145 6100 50  0001 C CNN
F 3 "~" H 5145 6100 50  0001 C CNN
	1    5145 6100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0202
U 1 1 5F285328
P 4945 6065
F 0 "#PWR0202" H 4945 5915 50  0001 C CNN
F 1 "+3.3VA" H 4960 6238 50  0000 C CNN
F 2 "" H 4945 6065 50  0001 C CNN
F 3 "" H 4945 6065 50  0001 C CNN
	1    4945 6065
	1    0    0    -1  
$EndComp
Wire Wire Line
	4945 6065 4945 6100
Text Notes 6285 5585 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J73
U 1 1 5F285330
P 6430 5405
F 0 "J73" H 6350 5180 50  0000 C CNN
F 1 "Conn_01x01" H 6350 5271 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6430 5405 50  0001 C CNN
F 3 "~" H 6430 5405 50  0001 C CNN
	1    6430 5405
	-1   0    0    1   
$EndComp
Text GLabel 6665 5405 2    50   Input ~ 0
F7
Wire Wire Line
	6630 5405 6665 5405
$Comp
L power:GND #PWR0214
U 1 1 5F285339
P 6080 5430
F 0 "#PWR0214" H 6080 5180 50  0001 C CNN
F 1 "GND" H 6085 5257 50  0000 C CNN
F 2 "" H 6080 5430 50  0001 C CNN
F 3 "" H 6080 5430 50  0001 C CNN
	1    6080 5430
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J67
U 1 1 5F28533F
P 6280 5405
F 0 "J67" H 6200 5180 50  0000 C CNN
F 1 "Conn_01x01" H 6200 5271 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6280 5405 50  0001 C CNN
F 3 "~" H 6280 5405 50  0001 C CNN
	1    6280 5405
	1    0    0    -1  
$EndComp
Wire Wire Line
	6080 5405 6080 5430
Text Notes 5875 5110 0    50   ~ 0
freeze is to GND\n
Text Notes 6290 6065 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J75
U 1 1 5F285349
P 6435 5885
F 0 "J75" H 6355 5660 50  0000 C CNN
F 1 "Conn_01x01" H 6355 5751 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6435 5885 50  0001 C CNN
F 3 "~" H 6435 5885 50  0001 C CNN
	1    6435 5885
	-1   0    0    1   
$EndComp
Text GLabel 6670 5885 2    50   Input ~ 0
F8
Wire Wire Line
	6635 5885 6670 5885
$Comp
L power:GND #PWR0216
U 1 1 5F285352
P 6085 5910
F 0 "#PWR0216" H 6085 5660 50  0001 C CNN
F 1 "GND" H 6090 5737 50  0000 C CNN
F 2 "" H 6085 5910 50  0001 C CNN
F 3 "" H 6085 5910 50  0001 C CNN
	1    6085 5910
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J69
U 1 1 5F285358
P 6285 5885
F 0 "J69" H 6205 5660 50  0000 C CNN
F 1 "Conn_01x01" H 6205 5751 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6285 5885 50  0001 C CNN
F 3 "~" H 6285 5885 50  0001 C CNN
	1    6285 5885
	1    0    0    -1  
$EndComp
Wire Wire Line
	6085 5885 6085 5910
Text Notes 4205 5180 0    118  ~ 0
[4]
$EndSCHEMATC
