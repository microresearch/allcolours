EESchema Schematic File Version 4
LIBS:touch-cache
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
Text Notes 640  1160 0    118  ~ 0
Two versions - one just with edge connector for own conns, other with jacks:\n\nFor each of 6 elements we have 4x jacks - A, B and C (out/feedback) and E which is voltage out!
Text Notes 860  1870 0    79   ~ 0
Edge conns: 24x +GND
Text Notes 6640 1710 0    79   ~ 0
24x jacks
$Comp
L Connector_Generic:Conn_01x25 J22
U 1 1 5F28E8EF
P 1445 3380
F 0 "J22" H 1365 1955 50  0000 C CNN
F 1 "Conn_01x25" H 1365 2046 50  0000 C CNN
F 2 "" H 1445 3380 50  0001 C CNN
F 3 "~" H 1445 3380 50  0001 C CNN
	1    1445 3380
	-1   0    0    1   
$EndComp
Wire Wire Line
	1645 2180 1685 2180
Wire Wire Line
	1645 2280 1685 2280
Wire Wire Line
	1645 2380 1685 2380
Wire Wire Line
	1645 2480 1685 2480
Wire Wire Line
	1645 2580 1685 2580
Wire Wire Line
	1645 2680 1685 2680
Wire Wire Line
	1645 2780 1685 2780
Wire Wire Line
	1645 2880 1685 2880
Wire Wire Line
	1645 2980 1685 2980
Wire Wire Line
	1645 3080 1685 3080
Wire Wire Line
	1645 3180 1685 3180
Wire Wire Line
	1645 3280 1685 3280
Wire Wire Line
	1645 3380 1685 3380
Wire Wire Line
	1645 3480 1685 3480
Wire Wire Line
	1645 3580 1685 3580
Wire Wire Line
	1645 3680 1685 3680
Wire Wire Line
	1645 3780 1685 3780
Wire Wire Line
	1645 3880 1685 3880
Wire Wire Line
	1645 3980 1685 3980
Wire Wire Line
	1645 4080 1685 4080
Wire Wire Line
	1645 4180 1685 4180
Wire Wire Line
	1645 4280 1685 4280
Wire Wire Line
	1645 4380 1685 4380
Wire Wire Line
	1645 4480 1685 4480
$Comp
L power:GND #PWR0131
U 1 1 5F28EA46
P 1720 4580
F 0 "#PWR0131" H 1720 4330 50  0001 C CNN
F 1 "GND" H 1725 4407 50  0000 C CNN
F 2 "" H 1720 4580 50  0001 C CNN
F 3 "" H 1720 4580 50  0001 C CNN
	1    1720 4580
	1    0    0    -1  
$EndComp
Wire Wire Line
	1645 4580 1720 4580
Text GLabel 1685 2180 2    43   Input ~ 0
v1
Text GLabel 1685 2280 2    43   Input ~ 0
v2
Text GLabel 1685 2380 2    43   Input ~ 0
v3
Text GLabel 1685 2480 2    43   Input ~ 0
v4
Text GLabel 1685 2580 2    43   Input ~ 0
v5
Text GLabel 1685 2680 2    43   Input ~ 0
v6
Text GLabel 1685 2780 2    43   Input ~ 0
IN1
Text GLabel 1685 2880 2    43   Input ~ 0
IN2
Text GLabel 1685 2980 2    43   Input ~ 0
IN3
Text GLabel 1685 3080 2    43   Input ~ 0
IN4
Text GLabel 1685 3180 2    43   Input ~ 0
IN5
Text GLabel 1685 3280 2    43   Input ~ 0
IN6
Text GLabel 1685 3380 2    43   Input ~ 0
OUT1
Text GLabel 1685 3480 2    43   Input ~ 0
OUT2
Text GLabel 1685 3580 2    43   Input ~ 0
OUT3
Text GLabel 1685 3680 2    43   Input ~ 0
OUT4
Text GLabel 1685 3780 2    43   Input ~ 0
OUT5
Text GLabel 1685 3880 2    43   Input ~ 0
OUT6
Text GLabel 1685 3980 2    43   Input ~ 0
C1
Text GLabel 1685 4080 2    43   Input ~ 0
C2
Text GLabel 1685 4180 2    43   Input ~ 0
C3
Text GLabel 1685 4280 2    43   Input ~ 0
C4
Text GLabel 1685 4380 2    43   Input ~ 0
C5
Text GLabel 1685 4480 2    43   Input ~ 0
C6
$EndSCHEMATC
