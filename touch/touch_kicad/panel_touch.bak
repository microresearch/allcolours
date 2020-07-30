EESchema Schematic File Version 4
LIBS:touch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 940  1190 0    79   ~ 0
\n
Text Notes 8375 7925 0    118  ~ 0
For panel we have 6 sets of:\n\n       C- feedback out from jack\n       |\nA---VCA---B [B is also mix from B pad]\n       |\n       0-adc voltage for A->B VCA\n       |\n       o-freeze\n       |\n       O-adc voltage for insert\n       |\n       o-freeze\n\n\n\n\nPlus rec,play, push and pop!\n\nTouch pads are A, B, C(out) 2x voltage sun/mooncrescent for VCA and for voltage insert, and two freezes.\n\nHere all is plain pads. \n6x\nA- out from A\nB- in to Bmix\nC- out from jack\n1-adcX/divider\n2-adcX/for voltage/divider\n2xfreeze - plain pad/crescent+V
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 5F230F3E
P 1085 1060
F 0 "J3" H 1005 835 50  0000 C CNN
F 1 "Conn_01x01" H 1005 926 50  0000 C CNN
F 2 "" H 1085 1060 50  0001 C CNN
F 3 "~" H 1085 1060 50  0001 C CNN
	1    1085 1060
	-1   0    0    1   
$EndComp
Text GLabel 1335 1060 2    50   Input ~ 0
C1
Wire Wire Line
	1285 1060 1335 1060
Text Notes 940  1280 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5F231056
P 1085 1225
F 0 "J4" H 1005 1000 50  0000 C CNN
F 1 "Conn_01x01" H 1005 1091 50  0000 C CNN
F 2 "" H 1085 1225 50  0001 C CNN
F 3 "~" H 1085 1225 50  0001 C CNN
	1    1085 1225
	-1   0    0    1   
$EndComp
Text GLabel 1335 1225 2    50   Input ~ 0
B1
Wire Wire Line
	1285 1225 1335 1225
Text Notes 940  1555 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J5
U 1 1 5F233418
P 1085 1375
F 0 "J5" H 1005 1150 50  0000 C CNN
F 1 "Conn_01x01" H 1005 1241 50  0000 C CNN
F 2 "" H 1085 1375 50  0001 C CNN
F 3 "~" H 1085 1375 50  0001 C CNN
	1    1085 1375
	-1   0    0    1   
$EndComp
Text GLabel 1335 1375 2    50   Input ~ 0
IN1
Wire Wire Line
	1285 1375 1335 1375
Text Notes 2135 1185 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J9
U 1 1 5F233537
P 2280 1005
F 0 "J9" H 2200 780 50  0000 C CNN
F 1 "Conn_01x01" H 2200 871 50  0000 C CNN
F 2 "" H 2280 1005 50  0001 C CNN
F 3 "~" H 2280 1005 50  0001 C CNN
	1    2280 1005
	-1   0    0    1   
$EndComp
Text GLabel 2530 1005 2    50   Input ~ 0
ADC0
Wire Wire Line
	2480 1005 2505 1005
Text Notes 2135 1400 0    79   ~ 0
\n
$Comp
L Device:R_Small R84
U 1 1 5F25FC69
P 2505 1105
F 0 "R84" H 2564 1151 50  0000 L CNN
F 1 "470K" H 2564 1060 50  0000 L CNN
F 2 "" H 2505 1105 50  0001 C CNN
F 3 "~" H 2505 1105 50  0001 C CNN
	1    2505 1105
	1    0    0    -1  
$EndComp
Connection ~ 2505 1005
Wire Wire Line
	2505 1005 2530 1005
$Comp
L power:GND #PWR0124
U 1 1 5F25FD4B
P 2505 1240
F 0 "#PWR0124" H 2505 990 50  0001 C CNN
F 1 "GND" H 2510 1067 50  0000 C CNN
F 2 "" H 2505 1240 50  0001 C CNN
F 3 "" H 2505 1240 50  0001 C CNN
	1    2505 1240
	1    0    0    -1  
$EndComp
Wire Wire Line
	2505 1205 2505 1240
$Comp
L Connector_Generic:Conn_01x01 J7
U 1 1 5F25FDA7
P 2130 1005
F 0 "J7" H 2050 780 50  0000 C CNN
F 1 "Conn_01x01" H 2050 871 50  0000 C CNN
F 2 "" H 2130 1005 50  0001 C CNN
F 3 "~" H 2130 1005 50  0001 C CNN
	1    2130 1005
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0122
U 1 1 5F25FE64
P 1930 970
F 0 "#PWR0122" H 1930 820 50  0001 C CNN
F 1 "+3.3VA" H 1945 1143 50  0000 C CNN
F 2 "" H 1930 970 50  0001 C CNN
F 3 "" H 1930 970 50  0001 C CNN
	1    1930 970 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1930 970  1930 1005
Text Notes 2125 1840 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J8
U 1 1 5F2623C3
P 2270 1660
F 0 "J8" H 2190 1435 50  0000 C CNN
F 1 "Conn_01x01" H 2190 1526 50  0000 C CNN
F 2 "" H 2270 1660 50  0001 C CNN
F 3 "~" H 2270 1660 50  0001 C CNN
	1    2270 1660
	-1   0    0    1   
$EndComp
Text GLabel 2520 1660 2    50   Input ~ 0
ADC1
Wire Wire Line
	2470 1660 2495 1660
Text Notes 2125 2055 0    79   ~ 0
\n
$Comp
L Device:R_Small R83
U 1 1 5F2623CD
P 2495 1760
F 0 "R83" H 2554 1806 50  0000 L CNN
F 1 "470K" H 2554 1715 50  0000 L CNN
F 2 "" H 2495 1760 50  0001 C CNN
F 3 "~" H 2495 1760 50  0001 C CNN
	1    2495 1760
	1    0    0    -1  
$EndComp
Connection ~ 2495 1660
Wire Wire Line
	2495 1660 2520 1660
$Comp
L power:GND #PWR0123
U 1 1 5F2623D6
P 2495 1895
F 0 "#PWR0123" H 2495 1645 50  0001 C CNN
F 1 "GND" H 2500 1722 50  0000 C CNN
F 2 "" H 2495 1895 50  0001 C CNN
F 3 "" H 2495 1895 50  0001 C CNN
	1    2495 1895
	1    0    0    -1  
$EndComp
Wire Wire Line
	2495 1860 2495 1895
$Comp
L Connector_Generic:Conn_01x01 J6
U 1 1 5F2623DD
P 2120 1660
F 0 "J6" H 2040 1435 50  0000 C CNN
F 1 "Conn_01x01" H 2040 1526 50  0000 C CNN
F 2 "" H 2120 1660 50  0001 C CNN
F 3 "~" H 2120 1660 50  0001 C CNN
	1    2120 1660
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0121
U 1 1 5F2623E4
P 1920 1625
F 0 "#PWR0121" H 1920 1475 50  0001 C CNN
F 1 "+3.3VA" H 1935 1798 50  0000 C CNN
F 2 "" H 1920 1625 50  0001 C CNN
F 3 "" H 1920 1625 50  0001 C CNN
	1    1920 1625
	1    0    0    -1  
$EndComp
Wire Wire Line
	1920 1625 1920 1660
Text Notes 3260 1145 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J12
U 1 1 5F263C71
P 3405 965
F 0 "J12" H 3325 740 50  0000 C CNN
F 1 "Conn_01x01" H 3325 831 50  0000 C CNN
F 2 "" H 3405 965 50  0001 C CNN
F 3 "~" H 3405 965 50  0001 C CNN
	1    3405 965 
	-1   0    0    1   
$EndComp
Text GLabel 3640 965  2    50   Input ~ 0
F1
Wire Wire Line
	3605 965  3640 965 
$Comp
L power:GND #PWR0125
U 1 1 5F270988
P 3055 990
F 0 "#PWR0125" H 3055 740 50  0001 C CNN
F 1 "GND" H 3060 817 50  0000 C CNN
F 2 "" H 3055 990 50  0001 C CNN
F 3 "" H 3055 990 50  0001 C CNN
	1    3055 990 
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J10
U 1 1 5F263C78
P 3255 965
F 0 "J10" H 3175 740 50  0000 C CNN
F 1 "Conn_01x01" H 3175 831 50  0000 C CNN
F 2 "" H 3255 965 50  0001 C CNN
F 3 "~" H 3255 965 50  0001 C CNN
	1    3255 965 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3055 965  3055 990 
Text Notes 2850 670  0    50   ~ 0
freeze is to GND\n
Text Notes 1095 630  0    50   ~ 0
EXAMPLE for each x6
Text Notes 3260 1805 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J13
U 1 1 5F272F5C
P 3405 1625
F 0 "J13" H 3325 1400 50  0000 C CNN
F 1 "Conn_01x01" H 3325 1491 50  0000 C CNN
F 2 "" H 3405 1625 50  0001 C CNN
F 3 "~" H 3405 1625 50  0001 C CNN
	1    3405 1625
	-1   0    0    1   
$EndComp
Text GLabel 3640 1625 2    50   Input ~ 0
F2
Wire Wire Line
	3605 1625 3640 1625
$Comp
L power:GND #PWR0126
U 1 1 5F272F65
P 3055 1650
F 0 "#PWR0126" H 3055 1400 50  0001 C CNN
F 1 "GND" H 3060 1477 50  0000 C CNN
F 2 "" H 3055 1650 50  0001 C CNN
F 3 "" H 3055 1650 50  0001 C CNN
	1    3055 1650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J11
U 1 1 5F272F6B
P 3255 1625
F 0 "J11" H 3175 1400 50  0000 C CNN
F 1 "Conn_01x01" H 3175 1491 50  0000 C CNN
F 2 "" H 3255 1625 50  0001 C CNN
F 3 "~" H 3255 1625 50  0001 C CNN
	1    3255 1625
	1    0    0    -1  
$EndComp
Wire Wire Line
	3055 1625 3055 1650
Text Notes 10130 1420 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J21
U 1 1 5F27451B
P 10275 1240
F 0 "J21" H 10195 1015 50  0000 C CNN
F 1 "Conn_01x01" H 10195 1106 50  0000 C CNN
F 2 "" H 10275 1240 50  0001 C CNN
F 3 "~" H 10275 1240 50  0001 C CNN
	1    10275 1240
	-1   0    0    1   
$EndComp
Text GLabel 10510 1240 2    50   Input ~ 0
Frec
Wire Wire Line
	10475 1240 10510 1240
$Comp
L power:GND #PWR0130
U 1 1 5F274524
P 9925 1265
F 0 "#PWR0130" H 9925 1015 50  0001 C CNN
F 1 "GND" H 9930 1092 50  0000 C CNN
F 2 "" H 9925 1265 50  0001 C CNN
F 3 "" H 9925 1265 50  0001 C CNN
	1    9925 1265
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J17
U 1 1 5F27452A
P 10125 1240
F 0 "J17" H 10045 1015 50  0000 C CNN
F 1 "Conn_01x01" H 10045 1106 50  0000 C CNN
F 2 "" H 10125 1240 50  0001 C CNN
F 3 "~" H 10125 1240 50  0001 C CNN
	1    10125 1240
	1    0    0    -1  
$EndComp
Wire Wire Line
	9925 1240 9925 1265
Text Notes 10125 1755 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J19
U 1 1 5F274AA1
P 10270 1575
F 0 "J19" H 10190 1350 50  0000 C CNN
F 1 "Conn_01x01" H 10190 1441 50  0000 C CNN
F 2 "" H 10270 1575 50  0001 C CNN
F 3 "~" H 10270 1575 50  0001 C CNN
	1    10270 1575
	-1   0    0    1   
$EndComp
Text GLabel 10505 1575 2    50   Input ~ 0
Fplay
Wire Wire Line
	10470 1575 10505 1575
$Comp
L power:GND #PWR0128
U 1 1 5F274AAA
P 9920 1600
F 0 "#PWR0128" H 9920 1350 50  0001 C CNN
F 1 "GND" H 9925 1427 50  0000 C CNN
F 2 "" H 9920 1600 50  0001 C CNN
F 3 "" H 9920 1600 50  0001 C CNN
	1    9920 1600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J15
U 1 1 5F274AB0
P 10120 1575
F 0 "J15" H 10040 1350 50  0000 C CNN
F 1 "Conn_01x01" H 10040 1441 50  0000 C CNN
F 2 "" H 10120 1575 50  0001 C CNN
F 3 "~" H 10120 1575 50  0001 C CNN
	1    10120 1575
	1    0    0    -1  
$EndComp
Wire Wire Line
	9920 1575 9920 1600
Text Notes 10125 2045 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J20
U 1 1 5F274D93
P 10270 1865
F 0 "J20" H 10190 1640 50  0000 C CNN
F 1 "Conn_01x01" H 10190 1731 50  0000 C CNN
F 2 "" H 10270 1865 50  0001 C CNN
F 3 "~" H 10270 1865 50  0001 C CNN
	1    10270 1865
	-1   0    0    1   
$EndComp
Text GLabel 10505 1865 2    50   Input ~ 0
Fpush
Wire Wire Line
	10470 1865 10505 1865
$Comp
L power:GND #PWR0129
U 1 1 5F274D9C
P 9920 1890
F 0 "#PWR0129" H 9920 1640 50  0001 C CNN
F 1 "GND" H 9925 1717 50  0000 C CNN
F 2 "" H 9920 1890 50  0001 C CNN
F 3 "" H 9920 1890 50  0001 C CNN
	1    9920 1890
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J16
U 1 1 5F274DA2
P 10120 1865
F 0 "J16" H 10040 1640 50  0000 C CNN
F 1 "Conn_01x01" H 10040 1731 50  0000 C CNN
F 2 "" H 10120 1865 50  0001 C CNN
F 3 "~" H 10120 1865 50  0001 C CNN
	1    10120 1865
	1    0    0    -1  
$EndComp
Wire Wire Line
	9920 1865 9920 1890
Text Notes 10120 2380 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J18
U 1 1 5F274DAB
P 10265 2200
F 0 "J18" H 10185 1975 50  0000 C CNN
F 1 "Conn_01x01" H 10185 2066 50  0000 C CNN
F 2 "" H 10265 2200 50  0001 C CNN
F 3 "~" H 10265 2200 50  0001 C CNN
	1    10265 2200
	-1   0    0    1   
$EndComp
Text GLabel 10500 2200 2    50   Input ~ 0
Fpop
Wire Wire Line
	10465 2200 10500 2200
$Comp
L power:GND #PWR0127
U 1 1 5F274DB4
P 9915 2225
F 0 "#PWR0127" H 9915 1975 50  0001 C CNN
F 1 "GND" H 9920 2052 50  0000 C CNN
F 2 "" H 9915 2225 50  0001 C CNN
F 3 "" H 9915 2225 50  0001 C CNN
	1    9915 2225
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J14
U 1 1 5F274DBA
P 10115 2200
F 0 "J14" H 10035 1975 50  0000 C CNN
F 1 "Conn_01x01" H 10035 2066 50  0000 C CNN
F 2 "" H 10115 2200 50  0001 C CNN
F 3 "~" H 10115 2200 50  0001 C CNN
	1    10115 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9915 2200 9915 2225
$EndSCHEMATC
