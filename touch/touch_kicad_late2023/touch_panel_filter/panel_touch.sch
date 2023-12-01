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
Text Notes 805  2180 0    79   ~ 0
\n
Text Notes 11410 6235 0    118  ~ 0
For panel we have 4 sets of:\n\n       C- feedback out from jack\n       |\nA---VCA---B [B is also mix from B pad]\n       |\n       0-adc voltage for A->B VCA\n       |\n       o-freeze\n       |\n       O-adc voltage for insert\n       |\n       o-freeze\n\n\n\n\nPlus rec,play, push/pop!\n\nTouch pads are A, B, C(out) 2x voltage sun/mooncrescent for\n VCA and for voltage insert, and two freezes.\n\nHere all is plain pads. \n6x\nA- out from A\nB- in to Bmix\nC- out from jack\n1-adcX/divider\n2-adcX/for voltage/divider\n2xfreeze - plain pad/crescent+V
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5F230F3E
P 985 2310
F 0 "J4" H 905 2085 50  0000 C CNN
F 1 "Conn_01x01" H 905 2176 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 985 2310 50  0001 C CNN
F 3 "~" H 985 2310 50  0001 C CNN
	1    985  2310
	-1   0    0    1   
$EndComp
Text GLabel 1235 2310 2    50   Input ~ 0
C1
Wire Wire Line
	1185 2310 1235 2310
Text Notes 805  2270 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J5
U 1 1 5F231056
P 985 2475
F 0 "J5" H 905 2250 50  0000 C CNN
F 1 "Conn_01x01" H 905 2341 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 985 2475 50  0001 C CNN
F 3 "~" H 985 2475 50  0001 C CNN
	1    985  2475
	-1   0    0    1   
$EndComp
Text GLabel 1235 2475 2    50   Input ~ 0
B1
Wire Wire Line
	1185 2475 1235 2475
Text Notes 805  2545 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J6
U 1 1 5F233418
P 985 2625
F 0 "J6" H 905 2400 50  0000 C CNN
F 1 "Conn_01x01" H 905 2491 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 985 2625 50  0001 C CNN
F 3 "~" H 985 2625 50  0001 C CNN
	1    985  2625
	-1   0    0    1   
$EndComp
Text GLabel 1235 2625 2    50   Input ~ 0
IN1
Wire Wire Line
	1185 2625 1235 2625
Text Notes 2035 2435 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J17
U 1 1 5F233537
P 2180 2255
F 0 "J17" H 2100 2030 50  0000 C CNN
F 1 "Conn_01x01" H 2100 2121 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2180 2255 50  0001 C CNN
F 3 "~" H 2180 2255 50  0001 C CNN
	1    2180 2255
	-1   0    0    1   
$EndComp
Text GLabel 2430 2255 2    50   Input ~ 0
ADC0
Wire Wire Line
	2380 2255 2405 2255
Text Notes 2035 2650 0    79   ~ 0
\n
$Comp
L Device:R_Small R4
U 1 1 5F25FC69
P 2405 2355
F 0 "R4" H 2464 2401 50  0000 L CNN
F 1 "470K" H 2464 2310 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2405 2355 50  0001 C CNN
F 3 "~" H 2405 2355 50  0001 C CNN
	1    2405 2355
	1    0    0    -1  
$EndComp
Connection ~ 2405 2255
Wire Wire Line
	2405 2255 2430 2255
$Comp
L power:GND #PWR08
U 1 1 5F25FD4B
P 2405 2490
F 0 "#PWR08" H 2405 2240 50  0001 C CNN
F 1 "GND" H 2410 2317 50  0000 C CNN
F 2 "" H 2405 2490 50  0001 C CNN
F 3 "" H 2405 2490 50  0001 C CNN
	1    2405 2490
	1    0    0    -1  
$EndComp
Wire Wire Line
	2405 2455 2405 2490
$Comp
L Connector_Generic:Conn_01x01 J13
U 1 1 5F25FDA7
P 2030 2255
F 0 "J13" H 1950 2030 50  0000 C CNN
F 1 "Conn_01x01" H 1950 2121 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2030 2255 50  0001 C CNN
F 3 "~" H 2030 2255 50  0001 C CNN
	1    2030 2255
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR04
U 1 1 5F25FE64
P 1830 2220
F 0 "#PWR04" H 1830 2070 50  0001 C CNN
F 1 "+3.3VA" H 1845 2393 50  0000 C CNN
F 2 "" H 1830 2220 50  0001 C CNN
F 3 "" H 1830 2220 50  0001 C CNN
	1    1830 2220
	1    0    0    -1  
$EndComp
Wire Wire Line
	1830 2220 1830 2255
Text Notes 2025 3090 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J16
U 1 1 5F2623C3
P 2170 2910
F 0 "J16" H 2090 2685 50  0000 C CNN
F 1 "Conn_01x01" H 2090 2776 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2170 2910 50  0001 C CNN
F 3 "~" H 2170 2910 50  0001 C CNN
	1    2170 2910
	-1   0    0    1   
$EndComp
Text GLabel 2420 2910 2    50   Input ~ 0
ADC1
Wire Wire Line
	2370 2910 2395 2910
Text Notes 2025 3305 0    79   ~ 0
\n
$Comp
L Device:R_Small R3
U 1 1 5F2623CD
P 2395 3010
F 0 "R3" H 2454 3056 50  0000 L CNN
F 1 "470K" H 2454 2965 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2395 3010 50  0001 C CNN
F 3 "~" H 2395 3010 50  0001 C CNN
	1    2395 3010
	1    0    0    -1  
$EndComp
Connection ~ 2395 2910
Wire Wire Line
	2395 2910 2420 2910
$Comp
L power:GND #PWR07
U 1 1 5F2623D6
P 2395 3145
F 0 "#PWR07" H 2395 2895 50  0001 C CNN
F 1 "GND" H 2400 2972 50  0000 C CNN
F 2 "" H 2395 3145 50  0001 C CNN
F 3 "" H 2395 3145 50  0001 C CNN
	1    2395 3145
	1    0    0    -1  
$EndComp
Wire Wire Line
	2395 3110 2395 3145
$Comp
L Connector_Generic:Conn_01x01 J12
U 1 1 5F2623DD
P 2020 2910
F 0 "J12" H 1940 2685 50  0000 C CNN
F 1 "Conn_01x01" H 1940 2776 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2020 2910 50  0001 C CNN
F 3 "~" H 2020 2910 50  0001 C CNN
	1    2020 2910
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR03
U 1 1 5F2623E4
P 1820 2875
F 0 "#PWR03" H 1820 2725 50  0001 C CNN
F 1 "+3.3VA" H 1835 3048 50  0000 C CNN
F 2 "" H 1820 2875 50  0001 C CNN
F 3 "" H 1820 2875 50  0001 C CNN
	1    1820 2875
	1    0    0    -1  
$EndComp
Wire Wire Line
	1820 2875 1820 2910
$Comp
L Connector_Generic:Conn_01x01 J24
U 1 1 5F263C71
P 3305 2215
F 0 "J24" H 3225 1990 50  0000 C CNN
F 1 "Conn_01x01" H 3225 2081 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3305 2215 50  0001 C CNN
F 3 "~" H 3305 2215 50  0001 C CNN
	1    3305 2215
	-1   0    0    1   
$EndComp
Text GLabel 3540 2215 2    50   Input ~ 0
F1
Wire Wire Line
	3505 2215 3540 2215
Text Notes 2750 1920 0    50   ~ 0
freeze is to NOT to GND\n\n
Text Notes 3165 2875 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J25
U 1 1 5F272F5C
P 3310 2695
F 0 "J25" H 3230 2470 50  0000 C CNN
F 1 "Conn_01x01" H 3230 2561 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3310 2695 50  0001 C CNN
F 3 "~" H 3310 2695 50  0001 C CNN
	1    3310 2695
	-1   0    0    1   
$EndComp
Text GLabel 3545 2695 2    50   Input ~ 0
F2
Wire Wire Line
	3510 2695 3545 2695
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
Frec
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
Fplay
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
Fpush
Wire Wire Line
	1305 1680 1340 1680
Text Notes 1080 1990 0    118  ~ 0
[1]
Text Notes 4025 2455 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J29
U 1 1 5F283EF8
P 4170 2325
F 0 "J29" H 4090 2100 50  0000 C CNN
F 1 "Conn_01x01" H 4090 2191 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4170 2325 50  0001 C CNN
F 3 "~" H 4170 2325 50  0001 C CNN
	1    4170 2325
	-1   0    0    1   
$EndComp
Text GLabel 4420 2325 2    50   Input ~ 0
C2
Wire Wire Line
	4370 2325 4420 2325
Text Notes 4025 2545 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J30
U 1 1 5F283F02
P 4170 2490
F 0 "J30" H 4090 2265 50  0000 C CNN
F 1 "Conn_01x01" H 4090 2356 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4170 2490 50  0001 C CNN
F 3 "~" H 4170 2490 50  0001 C CNN
	1    4170 2490
	-1   0    0    1   
$EndComp
Text GLabel 4420 2490 2    50   Input ~ 0
B2
Wire Wire Line
	4370 2490 4420 2490
Text Notes 4025 2820 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J31
U 1 1 5F283F0C
P 4170 2640
F 0 "J31" H 4090 2415 50  0000 C CNN
F 1 "Conn_01x01" H 4090 2506 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4170 2640 50  0001 C CNN
F 3 "~" H 4170 2640 50  0001 C CNN
	1    4170 2640
	-1   0    0    1   
$EndComp
Text GLabel 4420 2640 2    50   Input ~ 0
IN2
Wire Wire Line
	4370 2640 4420 2640
Text Notes 5220 2450 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J39
U 1 1 5F283F16
P 5365 2270
F 0 "J39" H 5285 2045 50  0000 C CNN
F 1 "Conn_01x01" H 5285 2136 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5365 2270 50  0001 C CNN
F 3 "~" H 5365 2270 50  0001 C CNN
	1    5365 2270
	-1   0    0    1   
$EndComp
Text GLabel 5615 2270 2    50   Input ~ 0
ADC2
Wire Wire Line
	5565 2270 5590 2270
Text Notes 5220 2665 0    79   ~ 0
\n
$Comp
L Device:R_Small R8
U 1 1 5F283F20
P 5590 2370
F 0 "R8" H 5649 2416 50  0000 L CNN
F 1 "470K" H 5649 2325 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5590 2370 50  0001 C CNN
F 3 "~" H 5590 2370 50  0001 C CNN
	1    5590 2370
	1    0    0    -1  
$EndComp
Connection ~ 5590 2270
Wire Wire Line
	5590 2270 5615 2270
$Comp
L power:GND #PWR020
U 1 1 5F283F29
P 5590 2505
F 0 "#PWR020" H 5590 2255 50  0001 C CNN
F 1 "GND" H 5595 2332 50  0000 C CNN
F 2 "" H 5590 2505 50  0001 C CNN
F 3 "" H 5590 2505 50  0001 C CNN
	1    5590 2505
	1    0    0    -1  
$EndComp
Wire Wire Line
	5590 2470 5590 2505
$Comp
L Connector_Generic:Conn_01x01 J35
U 1 1 5F283F30
P 5215 2270
F 0 "J35" H 5135 2045 50  0000 C CNN
F 1 "Conn_01x01" H 5135 2136 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5215 2270 50  0001 C CNN
F 3 "~" H 5215 2270 50  0001 C CNN
	1    5215 2270
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR016
U 1 1 5F283F37
P 5015 2235
F 0 "#PWR016" H 5015 2085 50  0001 C CNN
F 1 "+3.3VA" H 5030 2408 50  0000 C CNN
F 2 "" H 5015 2235 50  0001 C CNN
F 3 "" H 5015 2235 50  0001 C CNN
	1    5015 2235
	1    0    0    -1  
$EndComp
Wire Wire Line
	5015 2235 5015 2270
Text Notes 5210 3105 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J38
U 1 1 5F283F3F
P 5355 2925
F 0 "J38" H 5275 2700 50  0000 C CNN
F 1 "Conn_01x01" H 5275 2791 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5355 2925 50  0001 C CNN
F 3 "~" H 5355 2925 50  0001 C CNN
	1    5355 2925
	-1   0    0    1   
$EndComp
Text GLabel 5605 2925 2    50   Input ~ 0
ADC3
Wire Wire Line
	5555 2925 5580 2925
Text Notes 5210 3320 0    79   ~ 0
\n
$Comp
L Device:R_Small R7
U 1 1 5F283F49
P 5580 3025
F 0 "R7" H 5639 3071 50  0000 L CNN
F 1 "470K" H 5639 2980 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5580 3025 50  0001 C CNN
F 3 "~" H 5580 3025 50  0001 C CNN
	1    5580 3025
	1    0    0    -1  
$EndComp
Connection ~ 5580 2925
Wire Wire Line
	5580 2925 5605 2925
$Comp
L power:GND #PWR019
U 1 1 5F283F52
P 5580 3160
F 0 "#PWR019" H 5580 2910 50  0001 C CNN
F 1 "GND" H 5585 2987 50  0000 C CNN
F 2 "" H 5580 3160 50  0001 C CNN
F 3 "" H 5580 3160 50  0001 C CNN
	1    5580 3160
	1    0    0    -1  
$EndComp
Wire Wire Line
	5580 3125 5580 3160
$Comp
L Connector_Generic:Conn_01x01 J34
U 1 1 5F283F59
P 5205 2925
F 0 "J34" H 5125 2700 50  0000 C CNN
F 1 "Conn_01x01" H 5125 2791 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5205 2925 50  0001 C CNN
F 3 "~" H 5205 2925 50  0001 C CNN
	1    5205 2925
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR015
U 1 1 5F283F60
P 5005 2890
F 0 "#PWR015" H 5005 2740 50  0001 C CNN
F 1 "+3.3VA" H 5020 3063 50  0000 C CNN
F 2 "" H 5005 2890 50  0001 C CNN
F 3 "" H 5005 2890 50  0001 C CNN
	1    5005 2890
	1    0    0    -1  
$EndComp
Wire Wire Line
	5005 2890 5005 2925
Text Notes 6345 2410 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J46
U 1 1 5F283F68
P 6490 2230
F 0 "J46" H 6410 2005 50  0000 C CNN
F 1 "Conn_01x01" H 6410 2096 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6490 2230 50  0001 C CNN
F 3 "~" H 6490 2230 50  0001 C CNN
	1    6490 2230
	-1   0    0    1   
$EndComp
Text GLabel 6725 2230 2    50   Input ~ 0
F3
Wire Wire Line
	6690 2230 6725 2230
Text Notes 6350 2890 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J47
U 1 1 5F283F81
P 6495 2710
F 0 "J47" H 6415 2485 50  0000 C CNN
F 1 "Conn_01x01" H 6415 2576 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6495 2710 50  0001 C CNN
F 3 "~" H 6495 2710 50  0001 C CNN
	1    6495 2710
	-1   0    0    1   
$EndComp
Text GLabel 6730 2710 2    50   Input ~ 0
F4
Wire Wire Line
	6695 2710 6730 2710
Text Notes 4265 2005 0    118  ~ 0
[2]
Text Notes 805  4415 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J1
U 1 1 5F28521E
P 950 4285
F 0 "J1" H 870 4060 50  0000 C CNN
F 1 "Conn_01x01" H 870 4151 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 950 4285 50  0001 C CNN
F 3 "~" H 950 4285 50  0001 C CNN
	1    950  4285
	-1   0    0    1   
$EndComp
Text GLabel 1200 4285 2    50   Input ~ 0
C3
Wire Wire Line
	1150 4285 1200 4285
Text Notes 805  4505 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J2
U 1 1 5F285228
P 950 4450
F 0 "J2" H 870 4225 50  0000 C CNN
F 1 "Conn_01x01" H 870 4316 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 950 4450 50  0001 C CNN
F 3 "~" H 950 4450 50  0001 C CNN
	1    950  4450
	-1   0    0    1   
$EndComp
Text GLabel 1200 4450 2    50   Input ~ 0
B3
Wire Wire Line
	1150 4450 1200 4450
Text Notes 805  4780 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 5F285232
P 950 4600
F 0 "J3" H 870 4375 50  0000 C CNN
F 1 "Conn_01x01" H 870 4466 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 950 4600 50  0001 C CNN
F 3 "~" H 950 4600 50  0001 C CNN
	1    950  4600
	-1   0    0    1   
$EndComp
Text GLabel 1200 4600 2    50   Input ~ 0
IN3
Wire Wire Line
	1150 4600 1200 4600
Text Notes 2000 4410 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J15
U 1 1 5F28523C
P 2145 4230
F 0 "J15" H 2065 4005 50  0000 C CNN
F 1 "Conn_01x01" H 2065 4096 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2145 4230 50  0001 C CNN
F 3 "~" H 2145 4230 50  0001 C CNN
	1    2145 4230
	-1   0    0    1   
$EndComp
Text GLabel 2395 4230 2    50   Input ~ 0
ADC4
Wire Wire Line
	2345 4230 2370 4230
Text Notes 2000 4625 0    79   ~ 0
\n
$Comp
L Device:R_Small R2
U 1 1 5F285246
P 2370 4330
F 0 "R2" H 2429 4376 50  0000 L CNN
F 1 "470K" H 2429 4285 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2370 4330 50  0001 C CNN
F 3 "~" H 2370 4330 50  0001 C CNN
	1    2370 4330
	1    0    0    -1  
$EndComp
Connection ~ 2370 4230
Wire Wire Line
	2370 4230 2395 4230
$Comp
L power:GND #PWR06
U 1 1 5F28524F
P 2370 4465
F 0 "#PWR06" H 2370 4215 50  0001 C CNN
F 1 "GND" H 2375 4292 50  0000 C CNN
F 2 "" H 2370 4465 50  0001 C CNN
F 3 "" H 2370 4465 50  0001 C CNN
	1    2370 4465
	1    0    0    -1  
$EndComp
Wire Wire Line
	2370 4430 2370 4465
$Comp
L Connector_Generic:Conn_01x01 J11
U 1 1 5F285256
P 1995 4230
F 0 "J11" H 1915 4005 50  0000 C CNN
F 1 "Conn_01x01" H 1915 4096 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1995 4230 50  0001 C CNN
F 3 "~" H 1995 4230 50  0001 C CNN
	1    1995 4230
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR02
U 1 1 5F28525D
P 1795 4195
F 0 "#PWR02" H 1795 4045 50  0001 C CNN
F 1 "+3.3VA" H 1810 4368 50  0000 C CNN
F 2 "" H 1795 4195 50  0001 C CNN
F 3 "" H 1795 4195 50  0001 C CNN
	1    1795 4195
	1    0    0    -1  
$EndComp
Wire Wire Line
	1795 4195 1795 4230
Text Notes 1990 5065 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J14
U 1 1 5F285265
P 2135 4885
F 0 "J14" H 2055 4660 50  0000 C CNN
F 1 "Conn_01x01" H 2055 4751 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2135 4885 50  0001 C CNN
F 3 "~" H 2135 4885 50  0001 C CNN
	1    2135 4885
	-1   0    0    1   
$EndComp
Text GLabel 2385 4885 2    50   Input ~ 0
ADC5
Wire Wire Line
	2335 4885 2360 4885
Text Notes 1990 5280 0    79   ~ 0
\n
$Comp
L Device:R_Small R1
U 1 1 5F28526F
P 2360 4985
F 0 "R1" H 2419 5031 50  0000 L CNN
F 1 "470K" H 2419 4940 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2360 4985 50  0001 C CNN
F 3 "~" H 2360 4985 50  0001 C CNN
	1    2360 4985
	1    0    0    -1  
$EndComp
Connection ~ 2360 4885
Wire Wire Line
	2360 4885 2385 4885
$Comp
L power:GND #PWR05
U 1 1 5F285278
P 2360 5120
F 0 "#PWR05" H 2360 4870 50  0001 C CNN
F 1 "GND" H 2365 4947 50  0000 C CNN
F 2 "" H 2360 5120 50  0001 C CNN
F 3 "" H 2360 5120 50  0001 C CNN
	1    2360 5120
	1    0    0    -1  
$EndComp
Wire Wire Line
	2360 5085 2360 5120
$Comp
L Connector_Generic:Conn_01x01 J10
U 1 1 5F28527F
P 1985 4885
F 0 "J10" H 1905 4660 50  0000 C CNN
F 1 "Conn_01x01" H 1905 4751 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1985 4885 50  0001 C CNN
F 3 "~" H 1985 4885 50  0001 C CNN
	1    1985 4885
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR01
U 1 1 5F285286
P 1785 4850
F 0 "#PWR01" H 1785 4700 50  0001 C CNN
F 1 "+3.3VA" H 1800 5023 50  0000 C CNN
F 2 "" H 1785 4850 50  0001 C CNN
F 3 "" H 1785 4850 50  0001 C CNN
	1    1785 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1785 4850 1785 4885
Text Notes 3125 4370 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J22
U 1 1 5F28528E
P 3270 4190
F 0 "J22" H 3190 3965 50  0000 C CNN
F 1 "Conn_01x01" H 3190 4056 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3270 4190 50  0001 C CNN
F 3 "~" H 3270 4190 50  0001 C CNN
	1    3270 4190
	-1   0    0    1   
$EndComp
Text GLabel 3505 4190 2    50   Input ~ 0
F5
Wire Wire Line
	3470 4190 3505 4190
Text Notes 3130 4850 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J23
U 1 1 5F2852A7
P 3275 4670
F 0 "J23" H 3195 4445 50  0000 C CNN
F 1 "Conn_01x01" H 3195 4536 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3275 4670 50  0001 C CNN
F 3 "~" H 3275 4670 50  0001 C CNN
	1    3275 4670
	-1   0    0    1   
$EndComp
Text GLabel 3510 4670 2    50   Input ~ 0
F6
Wire Wire Line
	3475 4670 3510 4670
Text Notes 1045 3965 0    118  ~ 0
[3]
Text Notes 3990 4430 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J26
U 1 1 5F2852C0
P 4135 4300
F 0 "J26" H 4055 4075 50  0000 C CNN
F 1 "Conn_01x01" H 4055 4166 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4135 4300 50  0001 C CNN
F 3 "~" H 4135 4300 50  0001 C CNN
	1    4135 4300
	-1   0    0    1   
$EndComp
Text GLabel 4385 4300 2    50   Input ~ 0
C4
Wire Wire Line
	4335 4300 4385 4300
Text Notes 3990 4520 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J27
U 1 1 5F2852CA
P 4135 4465
F 0 "J27" H 4055 4240 50  0000 C CNN
F 1 "Conn_01x01" H 4055 4331 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4135 4465 50  0001 C CNN
F 3 "~" H 4135 4465 50  0001 C CNN
	1    4135 4465
	-1   0    0    1   
$EndComp
Text GLabel 4385 4465 2    50   Input ~ 0
B4
Wire Wire Line
	4335 4465 4385 4465
Text Notes 3990 4795 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J28
U 1 1 5F2852D4
P 4135 4615
F 0 "J28" H 4055 4390 50  0000 C CNN
F 1 "Conn_01x01" H 4055 4481 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4135 4615 50  0001 C CNN
F 3 "~" H 4135 4615 50  0001 C CNN
	1    4135 4615
	-1   0    0    1   
$EndComp
Text GLabel 4385 4615 2    50   Input ~ 0
IN4
Wire Wire Line
	4335 4615 4385 4615
Text Notes 5185 4425 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J37
U 1 1 5F2852DE
P 5330 4245
F 0 "J37" H 5250 4020 50  0000 C CNN
F 1 "Conn_01x01" H 5250 4111 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5330 4245 50  0001 C CNN
F 3 "~" H 5330 4245 50  0001 C CNN
	1    5330 4245
	-1   0    0    1   
$EndComp
Text GLabel 5580 4245 2    50   Input ~ 0
ADC6
Wire Wire Line
	5530 4245 5555 4245
Text Notes 5185 4640 0    79   ~ 0
\n
$Comp
L Device:R_Small R6
U 1 1 5F2852E8
P 5555 4345
F 0 "R6" H 5614 4391 50  0000 L CNN
F 1 "470K" H 5614 4300 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5555 4345 50  0001 C CNN
F 3 "~" H 5555 4345 50  0001 C CNN
	1    5555 4345
	1    0    0    -1  
$EndComp
Connection ~ 5555 4245
Wire Wire Line
	5555 4245 5580 4245
$Comp
L power:GND #PWR018
U 1 1 5F2852F1
P 5555 4480
F 0 "#PWR018" H 5555 4230 50  0001 C CNN
F 1 "GND" H 5560 4307 50  0000 C CNN
F 2 "" H 5555 4480 50  0001 C CNN
F 3 "" H 5555 4480 50  0001 C CNN
	1    5555 4480
	1    0    0    -1  
$EndComp
Wire Wire Line
	5555 4445 5555 4480
$Comp
L Connector_Generic:Conn_01x01 J33
U 1 1 5F2852F8
P 5180 4245
F 0 "J33" H 5100 4020 50  0000 C CNN
F 1 "Conn_01x01" H 5100 4111 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5180 4245 50  0001 C CNN
F 3 "~" H 5180 4245 50  0001 C CNN
	1    5180 4245
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR014
U 1 1 5F2852FF
P 4980 4210
F 0 "#PWR014" H 4980 4060 50  0001 C CNN
F 1 "+3.3VA" H 4995 4383 50  0000 C CNN
F 2 "" H 4980 4210 50  0001 C CNN
F 3 "" H 4980 4210 50  0001 C CNN
	1    4980 4210
	1    0    0    -1  
$EndComp
Wire Wire Line
	4980 4210 4980 4245
Text Notes 5175 5080 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J36
U 1 1 5F285307
P 5320 4900
F 0 "J36" H 5240 4675 50  0000 C CNN
F 1 "Conn_01x01" H 5240 4766 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5320 4900 50  0001 C CNN
F 3 "~" H 5320 4900 50  0001 C CNN
	1    5320 4900
	-1   0    0    1   
$EndComp
Text GLabel 5570 4900 2    50   Input ~ 0
ADC7
Wire Wire Line
	5520 4900 5545 4900
Text Notes 5175 5295 0    79   ~ 0
\n
$Comp
L Device:R_Small R5
U 1 1 5F285311
P 5545 5000
F 0 "R5" H 5604 5046 50  0000 L CNN
F 1 "470K" H 5604 4955 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5545 5000 50  0001 C CNN
F 3 "~" H 5545 5000 50  0001 C CNN
	1    5545 5000
	1    0    0    -1  
$EndComp
Connection ~ 5545 4900
Wire Wire Line
	5545 4900 5570 4900
$Comp
L power:GND #PWR017
U 1 1 5F28531A
P 5545 5135
F 0 "#PWR017" H 5545 4885 50  0001 C CNN
F 1 "GND" H 5550 4962 50  0000 C CNN
F 2 "" H 5545 5135 50  0001 C CNN
F 3 "" H 5545 5135 50  0001 C CNN
	1    5545 5135
	1    0    0    -1  
$EndComp
Wire Wire Line
	5545 5100 5545 5135
$Comp
L Connector_Generic:Conn_01x01 J32
U 1 1 5F285321
P 5170 4900
F 0 "J32" H 5090 4675 50  0000 C CNN
F 1 "Conn_01x01" H 5090 4766 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5170 4900 50  0001 C CNN
F 3 "~" H 5170 4900 50  0001 C CNN
	1    5170 4900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR013
U 1 1 5F285328
P 4970 4865
F 0 "#PWR013" H 4970 4715 50  0001 C CNN
F 1 "+3.3VA" H 4985 5038 50  0000 C CNN
F 2 "" H 4970 4865 50  0001 C CNN
F 3 "" H 4970 4865 50  0001 C CNN
	1    4970 4865
	1    0    0    -1  
$EndComp
Wire Wire Line
	4970 4865 4970 4900
$Comp
L Connector_Generic:Conn_01x01 J44
U 1 1 5F285330
P 6455 4205
F 0 "J44" H 6375 3980 50  0000 C CNN
F 1 "Conn_01x01" H 6375 4071 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6455 4205 50  0001 C CNN
F 3 "~" H 6455 4205 50  0001 C CNN
	1    6455 4205
	-1   0    0    1   
$EndComp
Text GLabel 6690 4205 2    50   Input ~ 0
F7
Wire Wire Line
	6655 4205 6690 4205
Text Notes 6315 4865 0    79   ~ 0
\n
$Comp
L Connector_Generic:Conn_01x01 J45
U 1 1 5F285349
P 6460 4685
F 0 "J45" H 6380 4460 50  0000 C CNN
F 1 "Conn_01x01" H 6380 4551 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6460 4685 50  0001 C CNN
F 3 "~" H 6460 4685 50  0001 C CNN
	1    6460 4685
	-1   0    0    1   
$EndComp
Text GLabel 6695 4685 2    50   Input ~ 0
F8
Wire Wire Line
	6660 4685 6695 4685
Text Notes 4230 3980 0    118  ~ 0
[4]
Text Notes 2315 1090 0    79   ~ 16
Add header for this: F,Fplay, push =3+ GND, 3.3V =5+\nFor each of the 4= 3signals, 2adc, 2 freeze = 7x4=28+5=33\n\nSL 2X20G SMD2,54 2x20pol.-SMD-Stiftleiste, gerade, RM 2,54
Wire Wire Line
	6145 2710 6145 2735
$Comp
L Connector_Generic:Conn_01x01 J43
U 1 1 5F283F90
P 6345 2710
F 0 "J43" H 6265 2485 50  0000 C CNN
F 1 "Conn_01x01" H 6265 2576 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6345 2710 50  0001 C CNN
F 3 "~" H 6345 2710 50  0001 C CNN
	1    6345 2710
	1    0    0    -1  
$EndComp
Wire Wire Line
	6110 4685 6110 4710
$Comp
L Connector_Generic:Conn_01x01 J41
U 1 1 5F285358
P 6310 4685
F 0 "J41" H 6230 4460 50  0000 C CNN
F 1 "Conn_01x01" H 6230 4551 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6310 4685 50  0001 C CNN
F 3 "~" H 6310 4685 50  0001 C CNN
	1    6310 4685
	1    0    0    -1  
$EndComp
Wire Wire Line
	6105 4205 6105 4230
$Comp
L Connector_Generic:Conn_01x01 J40
U 1 1 5F28533F
P 6305 4205
F 0 "J40" H 6225 3980 50  0000 C CNN
F 1 "Conn_01x01" H 6225 4071 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6305 4205 50  0001 C CNN
F 3 "~" H 6305 4205 50  0001 C CNN
	1    6305 4205
	1    0    0    -1  
$EndComp
Text Notes 6310 4385 0    79   ~ 0
\n
Wire Wire Line
	2925 4670 2925 4695
$Comp
L Connector_Generic:Conn_01x01 J19
U 1 1 5F2852B6
P 3125 4670
F 0 "J19" H 3045 4445 50  0000 C CNN
F 1 "Conn_01x01" H 3045 4536 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3125 4670 50  0001 C CNN
F 3 "~" H 3125 4670 50  0001 C CNN
	1    3125 4670
	1    0    0    -1  
$EndComp
Wire Wire Line
	2920 4190 2920 4215
$Comp
L Connector_Generic:Conn_01x01 J18
U 1 1 5F28529D
P 3120 4190
F 0 "J18" H 3040 3965 50  0000 C CNN
F 1 "Conn_01x01" H 3040 4056 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3120 4190 50  0001 C CNN
F 3 "~" H 3120 4190 50  0001 C CNN
	1    3120 4190
	1    0    0    -1  
$EndComp
Text Notes 2715 3895 0    50   ~ 0
freeze is to GND\n
Text Notes 5935 1935 0    50   ~ 0
freeze is to GND\n
Wire Wire Line
	6140 2230 6140 2255
$Comp
L Connector_Generic:Conn_01x01 J42
U 1 1 5F283F77
P 6340 2230
F 0 "J42" H 6260 2005 50  0000 C CNN
F 1 "Conn_01x01" H 6260 2096 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 6340 2230 50  0001 C CNN
F 3 "~" H 6340 2230 50  0001 C CNN
	1    6340 2230
	1    0    0    -1  
$EndComp
Wire Wire Line
	2960 2695 2960 2720
$Comp
L Connector_Generic:Conn_01x01 J21
U 1 1 5F272F6B
P 3160 2695
F 0 "J21" H 3080 2470 50  0000 C CNN
F 1 "Conn_01x01" H 3080 2561 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3160 2695 50  0001 C CNN
F 3 "~" H 3160 2695 50  0001 C CNN
	1    3160 2695
	1    0    0    -1  
$EndComp
Wire Wire Line
	2955 2215 2955 2240
$Comp
L Connector_Generic:Conn_01x01 J20
U 1 1 5F263C78
P 3155 2215
F 0 "J20" H 3075 1990 50  0000 C CNN
F 1 "Conn_01x01" H 3075 2081 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3155 2215 50  0001 C CNN
F 3 "~" H 3155 2215 50  0001 C CNN
	1    3155 2215
	1    0    0    -1  
$EndComp
Text Notes 3160 2395 0    79   ~ 0
\n
Text Notes 1600 1340 0    50   ~ 10
These are now to +3.3v which is on central circle!
Text Notes 1225 3360 0    50   ~ 10
central circle is +3,3V
$Comp
L power:+3.3VA #PWR028
U 1 1 5F9A15F1
P 9285 3350
F 0 "#PWR028" H 9285 3200 50  0001 C CNN
F 1 "+3.3VA" H 9300 3523 50  0000 C CNN
F 2 "" H 9285 3350 50  0001 C CNN
F 3 "" H 9285 3350 50  0001 C CNN
	1    9285 3350
	1    0    0    -1  
$EndComp
Text GLabel 8370 3950 0    50   Input ~ 0
Frec
Text GLabel 8360 3750 0    50   Input ~ 0
Fplay
Text GLabel 8960 3850 2    50   Input ~ 0
Fpush
Text GLabel 8360 3850 0    50   Input ~ 0
ADC0
Text GLabel 8375 4050 0    50   Input ~ 0
IN1
Text GLabel 8365 3550 0    50   Input ~ 0
B1
Text GLabel 8360 4150 0    50   Input ~ 0
C1
Text GLabel 8370 3450 0    50   Input ~ 0
ADC1
$Comp
L power:+3.3VA #PWR027
U 1 1 5F99A0A0
P 8235 3350
F 0 "#PWR027" H 8235 3200 50  0001 C CNN
F 1 "+3.3VA" H 8250 3523 50  0000 C CNN
F 2 "" H 8235 3350 50  0001 C CNN
F 3 "" H 8235 3350 50  0001 C CNN
	1    8235 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR030
U 1 1 5F99A34B
P 8350 3250
F 0 "#PWR030" H 8350 3000 50  0001 C CNN
F 1 "GND" H 8355 3077 50  0000 C CNN
F 2 "" H 8350 3250 50  0001 C CNN
F 3 "" H 8350 3250 50  0001 C CNN
	1    8350 3250
	1    0    0    -1  
$EndComp
Text GLabel 8380 3150 0    50   Input ~ 0
F2
Text GLabel 8370 4250 0    50   Input ~ 0
F1
Text GLabel 8365 4650 0    50   Input ~ 0
IN4
Text GLabel 8365 4350 0    50   Input ~ 0
F7
$Comp
L power:GND #PWR031
U 1 1 5F99B4A6
P 8350 4450
F 0 "#PWR031" H 8350 4200 50  0001 C CNN
F 1 "GND" H 8355 4277 50  0000 C CNN
F 2 "" H 8350 4450 50  0001 C CNN
F 3 "" H 8350 4450 50  0001 C CNN
	1    8350 4450
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR029
U 1 1 5F99C13B
P 8255 4550
F 0 "#PWR029" H 8255 4400 50  0001 C CNN
F 1 "+3.3VA" H 8270 4723 50  0000 C CNN
F 2 "" H 8255 4550 50  0001 C CNN
F 3 "" H 8255 4550 50  0001 C CNN
	1    8255 4550
	1    0    0    -1  
$EndComp
Text GLabel 8380 4750 0    50   Input ~ 0
ADC7
Text GLabel 8375 4850 0    50   Input ~ 0
ADC6
Text GLabel 8945 4850 2    50   Input ~ 0
C4
Text GLabel 8945 4750 2    50   Input ~ 0
B4
Text GLabel 8945 4650 2    50   Input ~ 0
F8
$Comp
L power:GND #PWR034
U 1 1 5F99DC43
P 9230 4550
F 0 "#PWR034" H 9230 4300 50  0001 C CNN
F 1 "GND" H 9235 4377 50  0000 C CNN
F 2 "" H 9230 4550 50  0001 C CNN
F 3 "" H 9230 4550 50  0001 C CNN
	1    9230 4550
	1    0    0    -1  
$EndComp
Text GLabel 8930 4450 2    50   Input ~ 0
F5
$Comp
L power:+3.3VA #PWR033
U 1 1 5F99E200
P 9205 4350
F 0 "#PWR033" H 9205 4200 50  0001 C CNN
F 1 "+3.3VA" H 9220 4523 50  0000 C CNN
F 2 "" H 9205 4350 50  0001 C CNN
F 3 "" H 9205 4350 50  0001 C CNN
	1    9205 4350
	1    0    0    -1  
$EndComp
Text GLabel 8930 4250 2    50   Input ~ 0
IN3
Text GLabel 8950 4050 2    50   Input ~ 0
ADC4
Text GLabel 8965 3950 2    50   Input ~ 0
C3
Text GLabel 8955 3750 2    50   Input ~ 0
B3
Text GLabel 8950 4150 2    50   Input ~ 0
ADC5
Text GLabel 8940 3650 2    50   Input ~ 0
F6
$Comp
L power:GND #PWR032
U 1 1 5F9A14A4
P 9155 3550
F 0 "#PWR032" H 9155 3300 50  0001 C CNN
F 1 "GND" H 9160 3377 50  0000 C CNN
F 2 "" H 9155 3550 50  0001 C CNN
F 3 "" H 9155 3550 50  0001 C CNN
	1    9155 3550
	1    0    0    -1  
$EndComp
Text GLabel 8935 3450 2    50   Input ~ 0
F4
Text GLabel 8945 3250 2    50   Input ~ 0
ADC3
Text GLabel 8940 3150 2    50   Input ~ 0
ADC2
Text GLabel 8930 3050 2    50   Input ~ 0
B2
Text GLabel 8935 2950 2    50   Input ~ 0
C2
Text GLabel 8375 2950 0    50   Input ~ 0
IN2
Text GLabel 8365 3050 0    50   Input ~ 0
F3
Wire Wire Line
	8375 2950 8405 2950
Wire Wire Line
	8365 3050 8405 3050
Wire Wire Line
	8380 3150 8405 3150
Wire Wire Line
	8350 3250 8405 3250
Wire Wire Line
	8235 3350 8405 3350
Wire Wire Line
	8370 3450 8405 3450
Wire Wire Line
	8365 3550 8405 3550
Wire Wire Line
	8200 3650 8405 3650
Wire Wire Line
	8360 3750 8405 3750
Wire Wire Line
	8360 3850 8405 3850
Wire Wire Line
	8370 3950 8405 3950
Wire Wire Line
	8375 4050 8405 4050
Wire Wire Line
	8905 3350 9285 3350
Wire Wire Line
	8905 3450 8935 3450
Wire Wire Line
	8905 3550 9155 3550
Wire Wire Line
	8905 3650 8940 3650
Wire Wire Line
	8905 3750 8955 3750
Wire Wire Line
	8905 3850 8960 3850
Wire Wire Line
	8905 3950 8965 3950
Wire Wire Line
	8905 4050 8950 4050
Wire Wire Line
	8905 4150 8950 4150
Wire Wire Line
	8905 4250 8930 4250
Wire Wire Line
	8360 4150 8405 4150
Wire Wire Line
	8370 4250 8405 4250
Wire Wire Line
	8365 4350 8405 4350
Wire Wire Line
	8350 4450 8405 4450
Wire Wire Line
	8255 4550 8405 4550
Wire Wire Line
	8365 4650 8405 4650
Wire Wire Line
	8380 4750 8405 4750
Wire Wire Line
	8375 4850 8405 4850
Wire Wire Line
	8905 4850 8945 4850
Wire Wire Line
	8905 4750 8945 4750
Wire Wire Line
	8905 4650 8945 4650
Wire Wire Line
	8905 4550 9230 4550
Wire Wire Line
	8905 4450 8930 4450
Wire Wire Line
	8905 4350 9205 4350
Wire Wire Line
	8905 2950 8935 2950
Wire Wire Line
	8905 3050 8930 3050
Wire Wire Line
	8905 3150 8940 3150
Wire Wire Line
	8905 3250 8945 3250
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J48
U 1 1 5F99E64E
P 8605 3950
F 0 "J48" H 8655 5067 50  0000 C CNN
F 1 "Conn_02x20_Counter_Clockwise" H 8655 4976 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x20_Pitch2.54mm_SMD" H 8605 3950 50  0001 C CNN
F 3 "~" H 8605 3950 50  0001 C CNN
	1    8605 3950
	1    0    0    1   
$EndComp
Text GLabel 8200 3650 0    50   Input ~ 0
TRIG
Text GLabel 2955 2240 0    50   Input ~ 0
TRIG
Text GLabel 2960 2720 0    50   Input ~ 0
TRIG
Text GLabel 6140 2255 0    50   Input ~ 0
TRIG
Text GLabel 6145 2735 0    50   Input ~ 0
TRIG
Text GLabel 6105 4230 0    50   Input ~ 0
TRIG
Text GLabel 6110 4710 0    50   Input ~ 0
TRIG
Text GLabel 2920 4215 0    50   Input ~ 0
TRIG
Text GLabel 2925 4695 0    50   Input ~ 0
TRIG
$EndSCHEMATC
