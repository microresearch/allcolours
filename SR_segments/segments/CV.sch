EESchema Schematic File Version 4
LIBS:segments-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 1 1 5F8F146E
P 3545 1150
AR Path="/5F88C158/5F8F146E" Ref="U?"  Part="1" 
AR Path="/5E933887/5F8F146E" Ref="U?"  Part="1" 
AR Path="/5F8E1429/5F8F146E" Ref="U9"  Part="1" 
F 0 "U9" H 3600 1290 50  0000 L CNN
F 1 "MCP6002" H 3545 1050 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 3545 1150 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 3545 1150 50  0001 C CNN
	1    3545 1150
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F1475
P 3445 1500
AR Path="/5F88C158/5F8F1475" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F1475" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F1475" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 3445 1250 50  0001 C CNN
F 1 "GND" H 3580 1445 50  0000 C CNN
F 2 "" H 3445 1500 50  0001 C CNN
F 3 "" H 3445 1500 50  0001 C CNN
	1    3445 1500
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F8F147B
P 3095 1250
AR Path="/5F88C158/5F8F147B" Ref="R?"  Part="1" 
AR Path="/5E933887/5F8F147B" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F8F147B" Ref="R62"  Part="1" 
F 0 "R62" V 3180 1065 50  0000 C CNN
F 1 "100K" V 3000 1170 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3095 1250 50  0001 C CNN
F 3 "" H 3095 1250 50  0001 C CNN
	1    3095 1250
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F8F1482
P 3495 1700
AR Path="/5F88C158/5F8F1482" Ref="R?"  Part="1" 
AR Path="/5E933887/5F8F1482" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F8F1482" Ref="R70"  Part="1" 
F 0 "R70" V 3415 1830 50  0000 C CNN
F 1 "66.5K" V 3545 1895 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3495 1700 50  0001 C CNN
F 3 "" H 3495 1700 50  0001 C CNN
	1    3495 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	3445 850  3445 800 
Wire Wire Line
	3195 1250 3245 1250
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F148B
P 3195 1050
AR Path="/5F88C158/5F8F148B" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F148B" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F148B" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 3195 800 50  0001 C CNN
F 1 "GND" H 3200 877 50  0000 C CNN
F 2 "" H 3195 1050 50  0001 C CNN
F 3 "" H 3195 1050 50  0001 C CNN
	1    3195 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3195 1050 3245 1050
Wire Wire Line
	3445 1500 3445 1450
Wire Wire Line
	3195 1700 3395 1700
Wire Wire Line
	3595 1700 3845 1700
Wire Wire Line
	3845 1700 3845 1150
Connection ~ 3195 1700
Wire Wire Line
	2895 1250 2995 1250
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F8F1498
P 3495 1900
AR Path="/5F88C158/5F8F1498" Ref="C?"  Part="1" 
AR Path="/5E933887/5F8F1498" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F8F1498" Ref="C30"  Part="1" 
F 0 "C30" V 3550 2020 50  0000 C CNN
F 1 "1nF" V 3610 1905 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 3495 1900 50  0001 C CNN
F 3 "" H 3495 1900 50  0001 C CNN
	1    3495 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	3195 1700 3195 1900
Wire Wire Line
	3195 1900 3395 1900
Wire Wire Line
	3595 1900 3845 1900
Wire Wire Line
	3845 1900 3845 1700
Connection ~ 3845 1700
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F8F14A4
P 1545 1235
AR Path="/5F88C158/5F8F14A4" Ref="C?"  Part="1" 
AR Path="/5E933887/5F8F14A4" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F8F14A4" Ref="C29"  Part="1" 
F 0 "C29" H 1453 1189 50  0000 R CNN
F 1 "100N" H 1453 1280 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 1545 1235 50  0001 C CNN
F 3 "" H 1545 1235 50  0001 C CNN
	1    1545 1235
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F14AB
P 1545 1385
AR Path="/5F88C158/5F8F14AB" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F14AB" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F14AB" Ref="#PWR099"  Part="1" 
F 0 "#PWR099" H 1545 1135 50  0001 C CNN
F 1 "GND" H 1550 1212 50  0000 C CNN
F 2 "" H 1545 1385 50  0001 C CNN
F 3 "" H 1545 1385 50  0001 C CNN
	1    1545 1385
	1    0    0    -1  
$EndComp
Wire Wire Line
	1545 1335 1545 1385
Wire Wire Line
	1545 1085 1545 1135
$Comp
L Device:R_POT nsrspeed?
U 1 1 5F8F14B3
P 2525 1005
AR Path="/5F88C158/5F8F14B3" Ref="nsrspeed?"  Part="1" 
AR Path="/5E933887/5F8F14B3" Ref="nsrspeed?"  Part="1" 
AR Path="/5F8E1429/5F8F14B3" Ref="nsrspeed1"  Part="1" 
F 0 "nsrspeed1" H 2455 1051 50  0000 R CNN
F 1 "10K" H 2455 960 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 2525 1005 50  0001 C CNN
F 3 "~" H 2525 1005 50  0001 C CNN
	1    2525 1005
	1    0    0    -1  
$EndComp
Wire Wire Line
	2525 800  2525 855 
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F14BB
P 2525 1195
AR Path="/5F88C158/5F8F14BB" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F14BB" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F14BB" Ref="#PWR0100"  Part="1" 
F 0 "#PWR0100" H 2525 945 50  0001 C CNN
F 1 "GND" H 2530 1022 50  0000 C CNN
F 2 "" H 2525 1195 50  0001 C CNN
F 3 "" H 2525 1195 50  0001 C CNN
	1    2525 1195
	1    0    0    -1  
$EndComp
Wire Wire Line
	2675 1470 2675 1005
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F8F14C2
P 3095 1470
AR Path="/5F88C158/5F8F14C2" Ref="R?"  Part="1" 
AR Path="/5E933887/5F8F14C2" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F8F14C2" Ref="R63"  Part="1" 
F 0 "R63" V 3175 1485 50  0000 C CNN
F 1 "200K" V 2990 1470 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3095 1470 50  0001 C CNN
F 3 "" H 3095 1470 50  0001 C CNN
	1    3095 1470
	0    1    1    0   
$EndComp
Wire Wire Line
	2675 1470 2995 1470
Wire Wire Line
	2525 1155 2525 1195
Text Notes 905  5170 0    157  ~ 0
0-5v in
Text GLabel 2525 800  0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 5F8F14CD
P 3445 800
AR Path="/5F88C158/5F8F14CD" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F14CD" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F14CD" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 3445 650 50  0001 C CNN
F 1 "+3.3V" H 3460 973 50  0000 C CNN
F 2 "" H 3445 800 50  0001 C CNN
F 3 "" H 3445 800 50  0001 C CNN
	1    3445 800 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5F8F14D3
P 1545 1085
AR Path="/5F88C158/5F8F14D3" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F14D3" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F14D3" Ref="#PWR098"  Part="1" 
F 0 "#PWR098" H 1545 935 50  0001 C CNN
F 1 "+3.3V" H 1560 1258 50  0000 C CNN
F 2 "" H 1545 1085 50  0001 C CNN
F 3 "" H 1545 1085 50  0001 C CNN
	1    1545 1085
	1    0    0    -1  
$EndComp
Text GLabel 2895 1250 1    79   Input ~ 0
NSPEED_IN
Wire Wire Line
	3845 1150 4035 1150
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 1 1 5F8F14DC
P 5850 1180
AR Path="/5F88C158/5F8F14DC" Ref="U?"  Part="2" 
AR Path="/5E933887/5F8F14DC" Ref="U?"  Part="2" 
AR Path="/5F8E1429/5F8F14DC" Ref="U11"  Part="1" 
F 0 "U11" H 5905 1320 50  0000 L CNN
F 1 "MCP6002" H 5850 1080 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5850 1180 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5850 1180 50  0001 C CNN
	1    5850 1180
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F14E3
P 5750 1530
AR Path="/5F88C158/5F8F14E3" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F14E3" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F14E3" Ref="#PWR0125"  Part="1" 
F 0 "#PWR0125" H 5750 1280 50  0001 C CNN
F 1 "GND" H 5885 1475 50  0000 C CNN
F 2 "" H 5750 1530 50  0001 C CNN
F 3 "" H 5750 1530 50  0001 C CNN
	1    5750 1530
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F8F14E9
P 5400 1280
AR Path="/5F88C158/5F8F14E9" Ref="R?"  Part="1" 
AR Path="/5E933887/5F8F14E9" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F8F14E9" Ref="R74"  Part="1" 
F 0 "R74" V 5450 1140 50  0000 C CNN
F 1 "100K" V 5305 1200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5400 1280 50  0001 C CNN
F 3 "" H 5400 1280 50  0001 C CNN
	1    5400 1280
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F8F14F0
P 5800 1730
AR Path="/5F88C158/5F8F14F0" Ref="R?"  Part="1" 
AR Path="/5E933887/5F8F14F0" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F8F14F0" Ref="R82"  Part="1" 
F 0 "R82" V 5720 1860 50  0000 C CNN
F 1 "66.5K" V 5850 1925 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5800 1730 50  0001 C CNN
F 3 "" H 5800 1730 50  0001 C CNN
	1    5800 1730
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 880  5750 830 
Wire Wire Line
	5500 1280 5550 1280
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F14F9
P 5500 1080
AR Path="/5F88C158/5F8F14F9" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F14F9" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F14F9" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 5500 830 50  0001 C CNN
F 1 "GND" H 5505 907 50  0000 C CNN
F 2 "" H 5500 1080 50  0001 C CNN
F 3 "" H 5500 1080 50  0001 C CNN
	1    5500 1080
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 1080 5550 1080
Wire Wire Line
	5750 1530 5750 1480
Wire Wire Line
	5500 1730 5700 1730
Wire Wire Line
	5900 1730 6150 1730
Wire Wire Line
	6150 1730 6150 1180
Connection ~ 5500 1730
Wire Wire Line
	5200 1280 5300 1280
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F8F1506
P 5800 1930
AR Path="/5F88C158/5F8F1506" Ref="C?"  Part="1" 
AR Path="/5E933887/5F8F1506" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F8F1506" Ref="C34"  Part="1" 
F 0 "C34" V 5855 2050 50  0000 C CNN
F 1 "1nF" V 5915 1935 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 5800 1930 50  0001 C CNN
F 3 "" H 5800 1930 50  0001 C CNN
	1    5800 1930
	0    1    1    0   
$EndComp
Wire Wire Line
	5500 1730 5500 1930
Wire Wire Line
	5500 1930 5700 1930
Wire Wire Line
	5900 1930 6150 1930
Wire Wire Line
	6150 1930 6150 1730
Connection ~ 6150 1730
$Comp
L Device:R_POT nlen?
U 1 1 5F8F1512
P 4830 1035
AR Path="/5F88C158/5F8F1512" Ref="nlen?"  Part="1" 
AR Path="/5E933887/5F8F1512" Ref="nlen?"  Part="1" 
AR Path="/5F8E1429/5F8F1512" Ref="nlen1"  Part="1" 
F 0 "nlen1" H 4760 1081 50  0000 R CNN
F 1 "10K" H 4760 990 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 4830 1035 50  0001 C CNN
F 3 "~" H 4830 1035 50  0001 C CNN
	1    4830 1035
	1    0    0    -1  
$EndComp
Wire Wire Line
	4830 830  4830 885 
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F151A
P 4830 1225
AR Path="/5F88C158/5F8F151A" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F151A" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F151A" Ref="#PWR0116"  Part="1" 
F 0 "#PWR0116" H 4830 975 50  0001 C CNN
F 1 "GND" H 4835 1052 50  0000 C CNN
F 2 "" H 4830 1225 50  0001 C CNN
F 3 "" H 4830 1225 50  0001 C CNN
	1    4830 1225
	1    0    0    -1  
$EndComp
Wire Wire Line
	4980 1500 4980 1035
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F8F1521
P 5400 1500
AR Path="/5F88C158/5F8F1521" Ref="R?"  Part="1" 
AR Path="/5E933887/5F8F1521" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F8F1521" Ref="R75"  Part="1" 
F 0 "R75" V 5475 1495 50  0000 C CNN
F 1 "200K" V 5295 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5400 1500 50  0001 C CNN
F 3 "" H 5400 1500 50  0001 C CNN
	1    5400 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	4980 1500 5300 1500
Wire Wire Line
	4830 1185 4830 1225
Text GLabel 4830 830  0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 5F8F152B
P 5750 830
AR Path="/5F88C158/5F8F152B" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F152B" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F152B" Ref="#PWR0124"  Part="1" 
F 0 "#PWR0124" H 5750 680 50  0001 C CNN
F 1 "+3.3V" H 5765 1003 50  0000 C CNN
F 2 "" H 5750 830 50  0001 C CNN
F 3 "" H 5750 830 50  0001 C CNN
	1    5750 830 
	1    0    0    -1  
$EndComp
Text GLabel 5200 1280 1    79   Input ~ 0
NLEN_IN
Wire Wire Line
	6150 1180 6340 1180
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F8F15D2
P 975 1235
AR Path="/5F88C158/5F8F15D2" Ref="C?"  Part="1" 
AR Path="/5E933887/5F8F15D2" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F8F15D2" Ref="C28"  Part="1" 
F 0 "C28" H 883 1189 50  0000 R CNN
F 1 "100N" H 883 1280 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 975 1235 50  0001 C CNN
F 3 "" H 975 1235 50  0001 C CNN
	1    975  1235
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F15D9
P 975 1385
AR Path="/5F88C158/5F8F15D9" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F15D9" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F15D9" Ref="#PWR097"  Part="1" 
F 0 "#PWR097" H 975 1135 50  0001 C CNN
F 1 "GND" H 980 1212 50  0000 C CNN
F 2 "" H 975 1385 50  0001 C CNN
F 3 "" H 975 1385 50  0001 C CNN
	1    975  1385
	1    0    0    -1  
$EndComp
Wire Wire Line
	975  1335 975  1385
Wire Wire Line
	975  1085 975  1135
$Comp
L power:+3.3V #PWR?
U 1 1 5F8F15E1
P 975 1085
AR Path="/5F88C158/5F8F15E1" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F15E1" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F15E1" Ref="#PWR096"  Part="1" 
F 0 "#PWR096" H 975 935 50  0001 C CNN
F 1 "+3.3V" H 990 1258 50  0000 C CNN
F 2 "" H 975 1085 50  0001 C CNN
F 3 "" H 975 1085 50  0001 C CNN
	1    975  1085
	1    0    0    -1  
$EndComp
Wire Wire Line
	3195 1250 3195 1470
Wire Wire Line
	5500 1280 5500 1500
Connection ~ 3195 1250
Connection ~ 3195 1470
Wire Wire Line
	3195 1470 3195 1700
Connection ~ 3845 1150
Connection ~ 5500 1280
Connection ~ 5500 1500
Wire Wire Line
	5500 1500 5500 1730
Connection ~ 6150 1180
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 1 1 5F909C58
P 3645 2930
AR Path="/5F88C158/5F909C58" Ref="U?"  Part="1" 
AR Path="/5E933887/5F909C58" Ref="U?"  Part="1" 
AR Path="/5F8E1429/5F909C58" Ref="U10"  Part="1" 
F 0 "U10" H 3700 3070 50  0000 L CNN
F 1 "MCP6002" H 3645 2830 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 3645 2930 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 3645 2930 50  0001 C CNN
	1    3645 2930
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F909C5F
P 3545 3280
AR Path="/5F88C158/5F909C5F" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909C5F" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909C5F" Ref="#PWR0113"  Part="1" 
F 0 "#PWR0113" H 3545 3030 50  0001 C CNN
F 1 "GND" H 3680 3225 50  0000 C CNN
F 2 "" H 3545 3280 50  0001 C CNN
F 3 "" H 3545 3280 50  0001 C CNN
	1    3545 3280
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F909C65
P 3195 3030
AR Path="/5F88C158/5F909C65" Ref="R?"  Part="1" 
AR Path="/5E933887/5F909C65" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F909C65" Ref="R66"  Part="1" 
F 0 "R66" V 3280 2845 50  0000 C CNN
F 1 "100K" V 3100 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3195 3030 50  0001 C CNN
F 3 "" H 3195 3030 50  0001 C CNN
	1    3195 3030
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F909C6C
P 3595 3480
AR Path="/5F88C158/5F909C6C" Ref="R?"  Part="1" 
AR Path="/5E933887/5F909C6C" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F909C6C" Ref="R72"  Part="1" 
F 0 "R72" V 3515 3610 50  0000 C CNN
F 1 "66.5K" V 3645 3675 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3595 3480 50  0001 C CNN
F 3 "" H 3595 3480 50  0001 C CNN
	1    3595 3480
	0    1    1    0   
$EndComp
Wire Wire Line
	3545 2630 3545 2580
Wire Wire Line
	3295 3030 3345 3030
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F909C75
P 3295 2830
AR Path="/5F88C158/5F909C75" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909C75" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909C75" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 3295 2580 50  0001 C CNN
F 1 "GND" H 3300 2657 50  0000 C CNN
F 2 "" H 3295 2830 50  0001 C CNN
F 3 "" H 3295 2830 50  0001 C CNN
	1    3295 2830
	1    0    0    -1  
$EndComp
Wire Wire Line
	3295 2830 3345 2830
Wire Wire Line
	3545 3280 3545 3230
Wire Wire Line
	3295 3480 3495 3480
Wire Wire Line
	3695 3480 3945 3480
Wire Wire Line
	3945 3480 3945 2930
Connection ~ 3295 3480
Wire Wire Line
	2995 3030 3095 3030
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F909C82
P 3595 3680
AR Path="/5F88C158/5F909C82" Ref="C?"  Part="1" 
AR Path="/5E933887/5F909C82" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F909C82" Ref="C32"  Part="1" 
F 0 "C32" V 3650 3800 50  0000 C CNN
F 1 "1nF" V 3710 3685 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 3595 3680 50  0001 C CNN
F 3 "" H 3595 3680 50  0001 C CNN
	1    3595 3680
	0    1    1    0   
$EndComp
Wire Wire Line
	3295 3480 3295 3680
Wire Wire Line
	3295 3680 3495 3680
Wire Wire Line
	3695 3680 3945 3680
Wire Wire Line
	3945 3680 3945 3480
Connection ~ 3945 3480
$Comp
L Device:R_POT nsrspeed?
U 1 1 5F909C8E
P 2625 2785
AR Path="/5F88C158/5F909C8E" Ref="nsrspeed?"  Part="1" 
AR Path="/5E933887/5F909C8E" Ref="nsrspeed?"  Part="1" 
AR Path="/5F8E1429/5F909C8E" Ref="lsrspeed3"  Part="1" 
F 0 "lsrspeed3" H 2555 2831 50  0000 R CNN
F 1 "10K" H 2555 2740 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 2625 2785 50  0001 C CNN
F 3 "~" H 2625 2785 50  0001 C CNN
	1    2625 2785
	1    0    0    -1  
$EndComp
Wire Wire Line
	2625 2580 2625 2635
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F909C96
P 2625 2975
AR Path="/5F88C158/5F909C96" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909C96" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909C96" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 2625 2725 50  0001 C CNN
F 1 "GND" H 2630 2802 50  0000 C CNN
F 2 "" H 2625 2975 50  0001 C CNN
F 3 "" H 2625 2975 50  0001 C CNN
	1    2625 2975
	1    0    0    -1  
$EndComp
Wire Wire Line
	2775 3250 2775 2785
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F909C9D
P 3195 3250
AR Path="/5F88C158/5F909C9D" Ref="R?"  Part="1" 
AR Path="/5E933887/5F909C9D" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F909C9D" Ref="R67"  Part="1" 
F 0 "R67" V 3275 3265 50  0000 C CNN
F 1 "200K" V 3090 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3195 3250 50  0001 C CNN
F 3 "" H 3195 3250 50  0001 C CNN
	1    3195 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	2775 3250 3095 3250
Wire Wire Line
	2625 2935 2625 2975
Text GLabel 2625 2580 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 5F909CA7
P 3545 2580
AR Path="/5F88C158/5F909CA7" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909CA7" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909CA7" Ref="#PWR0112"  Part="1" 
F 0 "#PWR0112" H 3545 2430 50  0001 C CNN
F 1 "+3.3V" H 3560 2753 50  0000 C CNN
F 2 "" H 3545 2580 50  0001 C CNN
F 3 "" H 3545 2580 50  0001 C CNN
	1    3545 2580
	1    0    0    -1  
$EndComp
Text GLabel 2995 3030 1    79   Input ~ 0
LSPEED_IN
Wire Wire Line
	3945 2930 4135 2930
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 1 1 5F909CB0
P 5950 2960
AR Path="/5F88C158/5F909CB0" Ref="U?"  Part="2" 
AR Path="/5E933887/5F909CB0" Ref="U?"  Part="2" 
AR Path="/5F8E1429/5F909CB0" Ref="U12"  Part="1" 
F 0 "U12" H 6005 3100 50  0000 L CNN
F 1 "MCP6002" H 5950 2860 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5950 2960 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5950 2960 50  0001 C CNN
	1    5950 2960
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F909CB7
P 5850 3310
AR Path="/5F88C158/5F909CB7" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909CB7" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909CB7" Ref="#PWR0129"  Part="1" 
F 0 "#PWR0129" H 5850 3060 50  0001 C CNN
F 1 "GND" H 5985 3255 50  0000 C CNN
F 2 "" H 5850 3310 50  0001 C CNN
F 3 "" H 5850 3310 50  0001 C CNN
	1    5850 3310
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F909CBD
P 5500 3060
AR Path="/5F88C158/5F909CBD" Ref="R?"  Part="1" 
AR Path="/5E933887/5F909CBD" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F909CBD" Ref="R78"  Part="1" 
F 0 "R78" V 5550 2920 50  0000 C CNN
F 1 "100K" V 5405 2980 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5500 3060 50  0001 C CNN
F 3 "" H 5500 3060 50  0001 C CNN
	1    5500 3060
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F909CC4
P 5900 3510
AR Path="/5F88C158/5F909CC4" Ref="R?"  Part="1" 
AR Path="/5E933887/5F909CC4" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F909CC4" Ref="R84"  Part="1" 
F 0 "R84" V 5820 3640 50  0000 C CNN
F 1 "66.5K" V 5950 3705 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5900 3510 50  0001 C CNN
F 3 "" H 5900 3510 50  0001 C CNN
	1    5900 3510
	0    1    1    0   
$EndComp
Wire Wire Line
	5850 2660 5850 2610
Wire Wire Line
	5600 3060 5650 3060
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F909CCD
P 5600 2860
AR Path="/5F88C158/5F909CCD" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909CCD" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909CCD" Ref="#PWR0122"  Part="1" 
F 0 "#PWR0122" H 5600 2610 50  0001 C CNN
F 1 "GND" H 5605 2687 50  0000 C CNN
F 2 "" H 5600 2860 50  0001 C CNN
F 3 "" H 5600 2860 50  0001 C CNN
	1    5600 2860
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2860 5650 2860
Wire Wire Line
	5850 3310 5850 3260
Wire Wire Line
	5600 3510 5800 3510
Wire Wire Line
	6000 3510 6250 3510
Wire Wire Line
	6250 3510 6250 2960
Connection ~ 5600 3510
Wire Wire Line
	5300 3060 5400 3060
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F909CDA
P 5900 3710
AR Path="/5F88C158/5F909CDA" Ref="C?"  Part="1" 
AR Path="/5E933887/5F909CDA" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F909CDA" Ref="C36"  Part="1" 
F 0 "C36" V 5955 3830 50  0000 C CNN
F 1 "1nF" V 6015 3715 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 5900 3710 50  0001 C CNN
F 3 "" H 5900 3710 50  0001 C CNN
	1    5900 3710
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 3510 5600 3710
Wire Wire Line
	5600 3710 5800 3710
Wire Wire Line
	6000 3710 6250 3710
Wire Wire Line
	6250 3710 6250 3510
Connection ~ 6250 3510
$Comp
L Device:R_POT nlen?
U 1 1 5F909CE6
P 4930 2815
AR Path="/5F88C158/5F909CE6" Ref="nlen?"  Part="1" 
AR Path="/5E933887/5F909CE6" Ref="nlen?"  Part="1" 
AR Path="/5F8E1429/5F909CE6" Ref="llen3"  Part="1" 
F 0 "llen3" H 4860 2861 50  0000 R CNN
F 1 "10K" H 4860 2770 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 4930 2815 50  0001 C CNN
F 3 "~" H 4930 2815 50  0001 C CNN
	1    4930 2815
	1    0    0    -1  
$EndComp
Wire Wire Line
	4930 2610 4930 2665
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F909CEE
P 4930 3005
AR Path="/5F88C158/5F909CEE" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909CEE" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909CEE" Ref="#PWR0118"  Part="1" 
F 0 "#PWR0118" H 4930 2755 50  0001 C CNN
F 1 "GND" H 4935 2832 50  0000 C CNN
F 2 "" H 4930 3005 50  0001 C CNN
F 3 "" H 4930 3005 50  0001 C CNN
	1    4930 3005
	1    0    0    -1  
$EndComp
Wire Wire Line
	5080 3280 5080 2815
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F909CF5
P 5500 3280
AR Path="/5F88C158/5F909CF5" Ref="R?"  Part="1" 
AR Path="/5E933887/5F909CF5" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F909CF5" Ref="R79"  Part="1" 
F 0 "R79" V 5575 3275 50  0000 C CNN
F 1 "200K" V 5395 3280 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5500 3280 50  0001 C CNN
F 3 "" H 5500 3280 50  0001 C CNN
	1    5500 3280
	0    1    1    0   
$EndComp
Wire Wire Line
	5080 3280 5400 3280
Wire Wire Line
	4930 2965 4930 3005
Text GLabel 4930 2610 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 5F909CFF
P 5850 2610
AR Path="/5F88C158/5F909CFF" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909CFF" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909CFF" Ref="#PWR0128"  Part="1" 
F 0 "#PWR0128" H 5850 2460 50  0001 C CNN
F 1 "+3.3V" H 5865 2783 50  0000 C CNN
F 2 "" H 5850 2610 50  0001 C CNN
F 3 "" H 5850 2610 50  0001 C CNN
	1    5850 2610
	1    0    0    -1  
$EndComp
Text GLabel 5300 3060 1    79   Input ~ 0
LLEN_IN
Wire Wire Line
	6250 2960 6440 2960
Wire Wire Line
	3295 3030 3295 3250
Wire Wire Line
	5600 3060 5600 3280
Connection ~ 3295 3030
Connection ~ 3295 3250
Wire Wire Line
	3295 3250 3295 3480
Connection ~ 3945 2930
Connection ~ 5600 3060
Connection ~ 5600 3280
Wire Wire Line
	5600 3280 5600 3510
Connection ~ 6250 2960
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 2 1 5F90D3A4
P 3655 4630
AR Path="/5F88C158/5F90D3A4" Ref="U?"  Part="1" 
AR Path="/5E933887/5F90D3A4" Ref="U?"  Part="1" 
AR Path="/5F8E1429/5F90D3A4" Ref="U10"  Part="2" 
F 0 "U10" H 3710 4770 50  0000 L CNN
F 1 "MCP6002" H 3655 4530 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 3655 4630 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 3655 4630 50  0001 C CNN
	2    3655 4630
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F90D3AB
P 3555 4980
AR Path="/5F88C158/5F90D3AB" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D3AB" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D3AB" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 3555 4730 50  0001 C CNN
F 1 "GND" H 3690 4925 50  0000 C CNN
F 2 "" H 3555 4980 50  0001 C CNN
F 3 "" H 3555 4980 50  0001 C CNN
	1    3555 4980
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F90D3B1
P 3205 4730
AR Path="/5F88C158/5F90D3B1" Ref="R?"  Part="1" 
AR Path="/5E933887/5F90D3B1" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F90D3B1" Ref="R68"  Part="1" 
F 0 "R68" V 3290 4545 50  0000 C CNN
F 1 "100K" V 3110 4650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3205 4730 50  0001 C CNN
F 3 "" H 3205 4730 50  0001 C CNN
	1    3205 4730
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F90D3B8
P 3605 5180
AR Path="/5F88C158/5F90D3B8" Ref="R?"  Part="1" 
AR Path="/5E933887/5F90D3B8" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F90D3B8" Ref="R73"  Part="1" 
F 0 "R73" V 3525 5310 50  0000 C CNN
F 1 "66.5K" V 3655 5375 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3605 5180 50  0001 C CNN
F 3 "" H 3605 5180 50  0001 C CNN
	1    3605 5180
	0    1    1    0   
$EndComp
Wire Wire Line
	3555 4330 3555 4280
Wire Wire Line
	3305 4730 3355 4730
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F90D3C1
P 3305 4530
AR Path="/5F88C158/5F90D3C1" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D3C1" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D3C1" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 3305 4280 50  0001 C CNN
F 1 "GND" H 3310 4357 50  0000 C CNN
F 2 "" H 3305 4530 50  0001 C CNN
F 3 "" H 3305 4530 50  0001 C CNN
	1    3305 4530
	1    0    0    -1  
$EndComp
Wire Wire Line
	3305 4530 3355 4530
Wire Wire Line
	3555 4980 3555 4930
Wire Wire Line
	3305 5180 3505 5180
Wire Wire Line
	3705 5180 3955 5180
Wire Wire Line
	3955 5180 3955 4630
Connection ~ 3305 5180
Wire Wire Line
	3005 4730 3105 4730
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F90D3CE
P 3605 5380
AR Path="/5F88C158/5F90D3CE" Ref="C?"  Part="1" 
AR Path="/5E933887/5F90D3CE" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F90D3CE" Ref="C33"  Part="1" 
F 0 "C33" V 3660 5500 50  0000 C CNN
F 1 "1nF" V 3720 5385 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 3605 5380 50  0001 C CNN
F 3 "" H 3605 5380 50  0001 C CNN
	1    3605 5380
	0    1    1    0   
$EndComp
Wire Wire Line
	3305 5180 3305 5380
Wire Wire Line
	3305 5380 3505 5380
Wire Wire Line
	3705 5380 3955 5380
Wire Wire Line
	3955 5380 3955 5180
Connection ~ 3955 5180
$Comp
L Device:R_POT nsrspeed?
U 1 1 5F90D3DA
P 2635 4485
AR Path="/5F88C158/5F90D3DA" Ref="nsrspeed?"  Part="1" 
AR Path="/5E933887/5F90D3DA" Ref="nsrspeed?"  Part="1" 
AR Path="/5F8E1429/5F90D3DA" Ref="rsrspeed4"  Part="1" 
F 0 "rsrspeed4" H 2565 4531 50  0000 R CNN
F 1 "10K" H 2565 4440 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 2635 4485 50  0001 C CNN
F 3 "~" H 2635 4485 50  0001 C CNN
	1    2635 4485
	1    0    0    -1  
$EndComp
Wire Wire Line
	2635 4280 2635 4335
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F90D3E2
P 2635 4675
AR Path="/5F88C158/5F90D3E2" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D3E2" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D3E2" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 2635 4425 50  0001 C CNN
F 1 "GND" H 2640 4502 50  0000 C CNN
F 2 "" H 2635 4675 50  0001 C CNN
F 3 "" H 2635 4675 50  0001 C CNN
	1    2635 4675
	1    0    0    -1  
$EndComp
Wire Wire Line
	2785 4950 2785 4485
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F90D3E9
P 3205 4950
AR Path="/5F88C158/5F90D3E9" Ref="R?"  Part="1" 
AR Path="/5E933887/5F90D3E9" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F90D3E9" Ref="R69"  Part="1" 
F 0 "R69" V 3285 4965 50  0000 C CNN
F 1 "200K" V 3100 4950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3205 4950 50  0001 C CNN
F 3 "" H 3205 4950 50  0001 C CNN
	1    3205 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	2785 4950 3105 4950
Wire Wire Line
	2635 4635 2635 4675
Text GLabel 2635 4280 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 5F90D3F3
P 3555 4280
AR Path="/5F88C158/5F90D3F3" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D3F3" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D3F3" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 3555 4130 50  0001 C CNN
F 1 "+3.3V" H 3570 4453 50  0000 C CNN
F 2 "" H 3555 4280 50  0001 C CNN
F 3 "" H 3555 4280 50  0001 C CNN
	1    3555 4280
	1    0    0    -1  
$EndComp
Text GLabel 3005 4730 1    79   Input ~ 0
RSPEED_IN
Wire Wire Line
	3955 4630 4145 4630
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 2 1 5F90D3FC
P 5960 4660
AR Path="/5F88C158/5F90D3FC" Ref="U?"  Part="2" 
AR Path="/5E933887/5F90D3FC" Ref="U?"  Part="2" 
AR Path="/5F8E1429/5F90D3FC" Ref="U12"  Part="2" 
F 0 "U12" H 6015 4800 50  0000 L CNN
F 1 "MCP6002" H 5960 4560 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5960 4660 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5960 4660 50  0001 C CNN
	2    5960 4660
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F90D403
P 5860 5010
AR Path="/5F88C158/5F90D403" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D403" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D403" Ref="#PWR0131"  Part="1" 
F 0 "#PWR0131" H 5860 4760 50  0001 C CNN
F 1 "GND" H 5995 4955 50  0000 C CNN
F 2 "" H 5860 5010 50  0001 C CNN
F 3 "" H 5860 5010 50  0001 C CNN
	1    5860 5010
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F90D409
P 5510 4760
AR Path="/5F88C158/5F90D409" Ref="R?"  Part="1" 
AR Path="/5E933887/5F90D409" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F90D409" Ref="R80"  Part="1" 
F 0 "R80" V 5560 4620 50  0000 C CNN
F 1 "100K" V 5415 4680 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5510 4760 50  0001 C CNN
F 3 "" H 5510 4760 50  0001 C CNN
	1    5510 4760
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F90D410
P 5910 5210
AR Path="/5F88C158/5F90D410" Ref="R?"  Part="1" 
AR Path="/5E933887/5F90D410" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F90D410" Ref="R85"  Part="1" 
F 0 "R85" V 5830 5340 50  0000 C CNN
F 1 "66.5K" V 5960 5405 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5910 5210 50  0001 C CNN
F 3 "" H 5910 5210 50  0001 C CNN
	1    5910 5210
	0    1    1    0   
$EndComp
Wire Wire Line
	5860 4360 5860 4310
Wire Wire Line
	5610 4760 5660 4760
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F90D419
P 5610 4560
AR Path="/5F88C158/5F90D419" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D419" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D419" Ref="#PWR0123"  Part="1" 
F 0 "#PWR0123" H 5610 4310 50  0001 C CNN
F 1 "GND" H 5615 4387 50  0000 C CNN
F 2 "" H 5610 4560 50  0001 C CNN
F 3 "" H 5610 4560 50  0001 C CNN
	1    5610 4560
	1    0    0    -1  
$EndComp
Wire Wire Line
	5610 4560 5660 4560
Wire Wire Line
	5860 5010 5860 4960
Wire Wire Line
	5610 5210 5810 5210
Wire Wire Line
	6010 5210 6260 5210
Wire Wire Line
	6260 5210 6260 4660
Connection ~ 5610 5210
Wire Wire Line
	5310 4760 5410 4760
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F90D426
P 5910 5410
AR Path="/5F88C158/5F90D426" Ref="C?"  Part="1" 
AR Path="/5E933887/5F90D426" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F90D426" Ref="C37"  Part="1" 
F 0 "C37" V 5965 5530 50  0000 C CNN
F 1 "1nF" V 6025 5415 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 5910 5410 50  0001 C CNN
F 3 "" H 5910 5410 50  0001 C CNN
	1    5910 5410
	0    1    1    0   
$EndComp
Wire Wire Line
	5610 5210 5610 5410
Wire Wire Line
	5610 5410 5810 5410
Wire Wire Line
	6010 5410 6260 5410
Wire Wire Line
	6260 5410 6260 5210
Connection ~ 6260 5210
$Comp
L Device:R_POT nlen?
U 1 1 5F90D432
P 4940 4515
AR Path="/5F88C158/5F90D432" Ref="nlen?"  Part="1" 
AR Path="/5E933887/5F90D432" Ref="nlen?"  Part="1" 
AR Path="/5F8E1429/5F90D432" Ref="rlen4"  Part="1" 
F 0 "rlen4" H 4870 4561 50  0000 R CNN
F 1 "10K" H 4870 4470 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 4940 4515 50  0001 C CNN
F 3 "~" H 4940 4515 50  0001 C CNN
	1    4940 4515
	1    0    0    -1  
$EndComp
Wire Wire Line
	4940 4310 4940 4365
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F90D43A
P 4940 4705
AR Path="/5F88C158/5F90D43A" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D43A" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D43A" Ref="#PWR0119"  Part="1" 
F 0 "#PWR0119" H 4940 4455 50  0001 C CNN
F 1 "GND" H 4945 4532 50  0000 C CNN
F 2 "" H 4940 4705 50  0001 C CNN
F 3 "" H 4940 4705 50  0001 C CNN
	1    4940 4705
	1    0    0    -1  
$EndComp
Wire Wire Line
	5090 4980 5090 4515
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F90D441
P 5510 4980
AR Path="/5F88C158/5F90D441" Ref="R?"  Part="1" 
AR Path="/5E933887/5F90D441" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F90D441" Ref="R81"  Part="1" 
F 0 "R81" V 5585 4975 50  0000 C CNN
F 1 "200K" V 5405 4980 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5510 4980 50  0001 C CNN
F 3 "" H 5510 4980 50  0001 C CNN
	1    5510 4980
	0    1    1    0   
$EndComp
Wire Wire Line
	5090 4980 5410 4980
Wire Wire Line
	4940 4665 4940 4705
Text GLabel 4940 4310 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 5F90D44B
P 5860 4310
AR Path="/5F88C158/5F90D44B" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D44B" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D44B" Ref="#PWR0130"  Part="1" 
F 0 "#PWR0130" H 5860 4160 50  0001 C CNN
F 1 "+3.3V" H 5875 4483 50  0000 C CNN
F 2 "" H 5860 4310 50  0001 C CNN
F 3 "" H 5860 4310 50  0001 C CNN
	1    5860 4310
	1    0    0    -1  
$EndComp
Text GLabel 5310 4760 1    79   Input ~ 0
RLEN_IN
Wire Wire Line
	6260 4660 6450 4660
Wire Wire Line
	3305 4730 3305 4950
Wire Wire Line
	5610 4760 5610 4980
Connection ~ 3305 4730
Connection ~ 3305 4950
Wire Wire Line
	3305 4950 3305 5180
Connection ~ 3955 4630
Connection ~ 5610 4760
Connection ~ 5610 4980
Wire Wire Line
	5610 4980 5610 5210
Connection ~ 6260 4660
Wire Wire Line
	7035 4605 7035 4645
Wire Wire Line
	7185 4920 7505 4920
Wire Wire Line
	7185 4920 7185 4455
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F90D471
P 7035 4645
AR Path="/5F88C158/5F90D471" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F90D471" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F90D471" Ref="#PWR0135"  Part="1" 
F 0 "#PWR0135" H 7035 4395 50  0001 C CNN
F 1 "GND" H 7040 4472 50  0000 C CNN
F 2 "" H 7035 4645 50  0001 C CNN
F 3 "" H 7035 4645 50  0001 C CNN
	1    7035 4645
	1    0    0    -1  
$EndComp
Wire Wire Line
	7035 4250 7035 4305
$Comp
L Device:R_POT nmode?
U 1 1 5F90D478
P 7035 4455
AR Path="/5F88C158/5F90D478" Ref="nmode?"  Part="1" 
AR Path="/5E933887/5F90D478" Ref="nmode?"  Part="1" 
AR Path="/5F8E1429/5F90D478" Ref="rmode4"  Part="1" 
F 0 "rmode4" H 6965 4501 50  0000 R CNN
F 1 "10K" H 6965 4410 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 7035 4455 50  0001 C CNN
F 3 "~" H 7035 4455 50  0001 C CNN
	1    7035 4455
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 2 1 5F914D11
P 3640 6300
AR Path="/5F88C158/5F914D11" Ref="U?"  Part="1" 
AR Path="/5E933887/5F914D11" Ref="U?"  Part="1" 
AR Path="/5F8E1429/5F914D11" Ref="U9"  Part="2" 
F 0 "U9" H 3695 6440 50  0000 L CNN
F 1 "MCP6002" H 3640 6200 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 3640 6300 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 3640 6300 50  0001 C CNN
	2    3640 6300
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F914D18
P 3540 6650
AR Path="/5F88C158/5F914D18" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914D18" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914D18" Ref="#PWR0111"  Part="1" 
F 0 "#PWR0111" H 3540 6400 50  0001 C CNN
F 1 "GND" H 3675 6595 50  0000 C CNN
F 2 "" H 3540 6650 50  0001 C CNN
F 3 "" H 3540 6650 50  0001 C CNN
	1    3540 6650
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F914D1E
P 3190 6400
AR Path="/5F88C158/5F914D1E" Ref="R?"  Part="1" 
AR Path="/5E933887/5F914D1E" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F914D1E" Ref="R64"  Part="1" 
F 0 "R64" V 3275 6215 50  0000 C CNN
F 1 "100K" V 3095 6320 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3190 6400 50  0001 C CNN
F 3 "" H 3190 6400 50  0001 C CNN
	1    3190 6400
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F914D25
P 3590 6850
AR Path="/5F88C158/5F914D25" Ref="R?"  Part="1" 
AR Path="/5E933887/5F914D25" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F914D25" Ref="R71"  Part="1" 
F 0 "R71" V 3510 6980 50  0000 C CNN
F 1 "66.5K" V 3640 7045 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3590 6850 50  0001 C CNN
F 3 "" H 3590 6850 50  0001 C CNN
	1    3590 6850
	0    1    1    0   
$EndComp
Wire Wire Line
	3540 6000 3540 5950
Wire Wire Line
	3290 6400 3340 6400
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F914D2E
P 3290 6200
AR Path="/5F88C158/5F914D2E" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914D2E" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914D2E" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 3290 5950 50  0001 C CNN
F 1 "GND" H 3295 6027 50  0000 C CNN
F 2 "" H 3290 6200 50  0001 C CNN
F 3 "" H 3290 6200 50  0001 C CNN
	1    3290 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3290 6200 3340 6200
Wire Wire Line
	3540 6650 3540 6600
Wire Wire Line
	3290 6850 3490 6850
Wire Wire Line
	3690 6850 3940 6850
Wire Wire Line
	3940 6850 3940 6300
Connection ~ 3290 6850
Wire Wire Line
	2990 6400 3090 6400
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F914D3B
P 3590 7050
AR Path="/5F88C158/5F914D3B" Ref="C?"  Part="1" 
AR Path="/5E933887/5F914D3B" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F914D3B" Ref="C31"  Part="1" 
F 0 "C31" V 3645 7170 50  0000 C CNN
F 1 "1nF" V 3705 7055 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 3590 7050 50  0001 C CNN
F 3 "" H 3590 7050 50  0001 C CNN
	1    3590 7050
	0    1    1    0   
$EndComp
Wire Wire Line
	3290 6850 3290 7050
Wire Wire Line
	3290 7050 3490 7050
Wire Wire Line
	3690 7050 3940 7050
Wire Wire Line
	3940 7050 3940 6850
Connection ~ 3940 6850
$Comp
L Device:R_POT nsrspeed?
U 1 1 5F914D47
P 2620 6155
AR Path="/5F88C158/5F914D47" Ref="nsrspeed?"  Part="1" 
AR Path="/5E933887/5F914D47" Ref="nsrspeed?"  Part="1" 
AR Path="/5F8E1429/5F914D47" Ref="csrspeed2"  Part="1" 
F 0 "csrspeed2" H 2550 6201 50  0000 R CNN
F 1 "10K" H 2550 6110 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 2620 6155 50  0001 C CNN
F 3 "~" H 2620 6155 50  0001 C CNN
	1    2620 6155
	1    0    0    -1  
$EndComp
Wire Wire Line
	2620 5950 2620 6005
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F914D4F
P 2620 6345
AR Path="/5F88C158/5F914D4F" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914D4F" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914D4F" Ref="#PWR0101"  Part="1" 
F 0 "#PWR0101" H 2620 6095 50  0001 C CNN
F 1 "GND" H 2625 6172 50  0000 C CNN
F 2 "" H 2620 6345 50  0001 C CNN
F 3 "" H 2620 6345 50  0001 C CNN
	1    2620 6345
	1    0    0    -1  
$EndComp
Wire Wire Line
	2770 6620 2770 6155
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F914D56
P 3190 6620
AR Path="/5F88C158/5F914D56" Ref="R?"  Part="1" 
AR Path="/5E933887/5F914D56" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F914D56" Ref="R65"  Part="1" 
F 0 "R65" V 3270 6635 50  0000 C CNN
F 1 "200K" V 3085 6620 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3190 6620 50  0001 C CNN
F 3 "" H 3190 6620 50  0001 C CNN
	1    3190 6620
	0    1    1    0   
$EndComp
Wire Wire Line
	2770 6620 3090 6620
Wire Wire Line
	2620 6305 2620 6345
Text GLabel 2620 5950 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 5F914D60
P 3540 5950
AR Path="/5F88C158/5F914D60" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914D60" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914D60" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 3540 5800 50  0001 C CNN
F 1 "+3.3V" H 3555 6123 50  0000 C CNN
F 2 "" H 3540 5950 50  0001 C CNN
F 3 "" H 3540 5950 50  0001 C CNN
	1    3540 5950
	1    0    0    -1  
$EndComp
Text GLabel 2990 6400 1    79   Input ~ 0
CSPEED_IN
Wire Wire Line
	3940 6300 4130 6300
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 2 1 5F914D69
P 5945 6330
AR Path="/5F88C158/5F914D69" Ref="U?"  Part="2" 
AR Path="/5E933887/5F914D69" Ref="U?"  Part="2" 
AR Path="/5F8E1429/5F914D69" Ref="U11"  Part="2" 
F 0 "U11" H 6000 6470 50  0000 L CNN
F 1 "MCP6002" H 5945 6230 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5945 6330 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5945 6330 50  0001 C CNN
	2    5945 6330
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F914D70
P 5845 6680
AR Path="/5F88C158/5F914D70" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914D70" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914D70" Ref="#PWR0127"  Part="1" 
F 0 "#PWR0127" H 5845 6430 50  0001 C CNN
F 1 "GND" H 5980 6625 50  0000 C CNN
F 2 "" H 5845 6680 50  0001 C CNN
F 3 "" H 5845 6680 50  0001 C CNN
	1    5845 6680
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F914D76
P 5495 6430
AR Path="/5F88C158/5F914D76" Ref="R?"  Part="1" 
AR Path="/5E933887/5F914D76" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F914D76" Ref="R76"  Part="1" 
F 0 "R76" V 5545 6290 50  0000 C CNN
F 1 "100K" V 5400 6350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5495 6430 50  0001 C CNN
F 3 "" H 5495 6430 50  0001 C CNN
	1    5495 6430
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F914D7D
P 5895 6880
AR Path="/5F88C158/5F914D7D" Ref="R?"  Part="1" 
AR Path="/5E933887/5F914D7D" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F914D7D" Ref="R83"  Part="1" 
F 0 "R83" V 5815 7010 50  0000 C CNN
F 1 "66.5K" V 5945 7075 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5895 6880 50  0001 C CNN
F 3 "" H 5895 6880 50  0001 C CNN
	1    5895 6880
	0    1    1    0   
$EndComp
Wire Wire Line
	5845 6030 5845 5980
Wire Wire Line
	5595 6430 5645 6430
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F914D86
P 5595 6230
AR Path="/5F88C158/5F914D86" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914D86" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914D86" Ref="#PWR0121"  Part="1" 
F 0 "#PWR0121" H 5595 5980 50  0001 C CNN
F 1 "GND" H 5600 6057 50  0000 C CNN
F 2 "" H 5595 6230 50  0001 C CNN
F 3 "" H 5595 6230 50  0001 C CNN
	1    5595 6230
	1    0    0    -1  
$EndComp
Wire Wire Line
	5595 6230 5645 6230
Wire Wire Line
	5845 6680 5845 6630
Wire Wire Line
	5595 6880 5795 6880
Wire Wire Line
	5995 6880 6245 6880
Wire Wire Line
	6245 6880 6245 6330
Connection ~ 5595 6880
Wire Wire Line
	5295 6430 5395 6430
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F914D93
P 5895 7080
AR Path="/5F88C158/5F914D93" Ref="C?"  Part="1" 
AR Path="/5E933887/5F914D93" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F914D93" Ref="C35"  Part="1" 
F 0 "C35" V 5950 7200 50  0000 C CNN
F 1 "1nF" V 6010 7085 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 5895 7080 50  0001 C CNN
F 3 "" H 5895 7080 50  0001 C CNN
	1    5895 7080
	0    1    1    0   
$EndComp
Wire Wire Line
	5595 6880 5595 7080
Wire Wire Line
	5595 7080 5795 7080
Wire Wire Line
	5995 7080 6245 7080
Wire Wire Line
	6245 7080 6245 6880
Connection ~ 6245 6880
$Comp
L Device:R_POT nlen?
U 1 1 5F914D9F
P 4925 6185
AR Path="/5F88C158/5F914D9F" Ref="nlen?"  Part="1" 
AR Path="/5E933887/5F914D9F" Ref="nlen?"  Part="1" 
AR Path="/5F8E1429/5F914D9F" Ref="clen2"  Part="1" 
F 0 "clen2" H 4855 6231 50  0000 R CNN
F 1 "10K" H 4855 6140 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 4925 6185 50  0001 C CNN
F 3 "~" H 4925 6185 50  0001 C CNN
	1    4925 6185
	1    0    0    -1  
$EndComp
Wire Wire Line
	4925 5980 4925 6035
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F914DA7
P 4925 6375
AR Path="/5F88C158/5F914DA7" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914DA7" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914DA7" Ref="#PWR0117"  Part="1" 
F 0 "#PWR0117" H 4925 6125 50  0001 C CNN
F 1 "GND" H 4930 6202 50  0000 C CNN
F 2 "" H 4925 6375 50  0001 C CNN
F 3 "" H 4925 6375 50  0001 C CNN
	1    4925 6375
	1    0    0    -1  
$EndComp
Wire Wire Line
	5075 6650 5075 6185
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F914DAE
P 5495 6650
AR Path="/5F88C158/5F914DAE" Ref="R?"  Part="1" 
AR Path="/5E933887/5F914DAE" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F914DAE" Ref="R77"  Part="1" 
F 0 "R77" V 5570 6645 50  0000 C CNN
F 1 "200K" V 5390 6650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5495 6650 50  0001 C CNN
F 3 "" H 5495 6650 50  0001 C CNN
	1    5495 6650
	0    1    1    0   
$EndComp
Wire Wire Line
	5075 6650 5395 6650
Wire Wire Line
	4925 6335 4925 6375
Text GLabel 4925 5980 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 5F914DB8
P 5845 5980
AR Path="/5F88C158/5F914DB8" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914DB8" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914DB8" Ref="#PWR0126"  Part="1" 
F 0 "#PWR0126" H 5845 5830 50  0001 C CNN
F 1 "+3.3V" H 5860 6153 50  0000 C CNN
F 2 "" H 5845 5980 50  0001 C CNN
F 3 "" H 5845 5980 50  0001 C CNN
	1    5845 5980
	1    0    0    -1  
$EndComp
Text GLabel 5295 6430 1    79   Input ~ 0
CLEN_IN
Wire Wire Line
	6245 6330 6435 6330
Wire Wire Line
	3290 6400 3290 6620
Wire Wire Line
	5595 6430 5595 6650
Connection ~ 3290 6400
Connection ~ 3290 6620
Wire Wire Line
	3290 6620 3290 6850
Connection ~ 3940 6300
Connection ~ 5595 6430
Connection ~ 5595 6650
Wire Wire Line
	5595 6650 5595 6880
Connection ~ 6245 6330
Wire Wire Line
	7020 6275 7020 6315
Wire Wire Line
	7170 6590 7490 6590
Wire Wire Line
	7170 6590 7170 6125
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F914DDE
P 7020 6315
AR Path="/5F88C158/5F914DDE" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F914DDE" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F914DDE" Ref="#PWR0133"  Part="1" 
F 0 "#PWR0133" H 7020 6065 50  0001 C CNN
F 1 "GND" H 7025 6142 50  0000 C CNN
F 2 "" H 7020 6315 50  0001 C CNN
F 3 "" H 7020 6315 50  0001 C CNN
	1    7020 6315
	1    0    0    -1  
$EndComp
Wire Wire Line
	7020 5920 7020 5975
$Comp
L Device:R_POT nmode?
U 1 1 5F914DE5
P 7020 6125
AR Path="/5F88C158/5F914DE5" Ref="nmode?"  Part="1" 
AR Path="/5E933887/5F914DE5" Ref="nmode?"  Part="1" 
AR Path="/5F8E1429/5F914DE5" Ref="cmode2"  Part="1" 
F 0 "cmode2" H 6950 6171 50  0000 R CNN
F 1 "10K" H 6950 6080 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 7020 6125 50  0001 C CNN
F 3 "~" H 7020 6125 50  0001 C CNN
	1    7020 6125
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F9305BF
P 1520 2230
AR Path="/5F88C158/5F9305BF" Ref="C?"  Part="1" 
AR Path="/5E933887/5F9305BF" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F9305BF" Ref="C43"  Part="1" 
F 0 "C43" H 1428 2184 50  0000 R CNN
F 1 "100N" H 1428 2275 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 1520 2230 50  0001 C CNN
F 3 "" H 1520 2230 50  0001 C CNN
	1    1520 2230
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F9305C6
P 1520 2380
AR Path="/5F88C158/5F9305C6" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F9305C6" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F9305C6" Ref="#PWR0151"  Part="1" 
F 0 "#PWR0151" H 1520 2130 50  0001 C CNN
F 1 "GND" H 1525 2207 50  0000 C CNN
F 2 "" H 1520 2380 50  0001 C CNN
F 3 "" H 1520 2380 50  0001 C CNN
	1    1520 2380
	1    0    0    -1  
$EndComp
Wire Wire Line
	1520 2330 1520 2380
Wire Wire Line
	1520 2080 1520 2130
$Comp
L power:+3.3V #PWR?
U 1 1 5F9305CE
P 1520 2080
AR Path="/5F88C158/5F9305CE" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F9305CE" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F9305CE" Ref="#PWR0150"  Part="1" 
F 0 "#PWR0150" H 1520 1930 50  0001 C CNN
F 1 "+3.3V" H 1535 2253 50  0000 C CNN
F 2 "" H 1520 2080 50  0001 C CNN
F 3 "" H 1520 2080 50  0001 C CNN
	1    1520 2080
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 5F9305D4
P 950 2230
AR Path="/5F88C158/5F9305D4" Ref="C?"  Part="1" 
AR Path="/5E933887/5F9305D4" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F9305D4" Ref="C42"  Part="1" 
F 0 "C42" H 858 2184 50  0000 R CNN
F 1 "100N" H 858 2275 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 950 2230 50  0001 C CNN
F 3 "" H 950 2230 50  0001 C CNN
	1    950  2230
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F9305DB
P 950 2380
AR Path="/5F88C158/5F9305DB" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F9305DB" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F9305DB" Ref="#PWR0149"  Part="1" 
F 0 "#PWR0149" H 950 2130 50  0001 C CNN
F 1 "GND" H 955 2207 50  0000 C CNN
F 2 "" H 950 2380 50  0001 C CNN
F 3 "" H 950 2380 50  0001 C CNN
	1    950  2380
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  2330 950  2380
Wire Wire Line
	950  2080 950  2130
$Comp
L power:+3.3V #PWR?
U 1 1 5F9305E3
P 950 2080
AR Path="/5F88C158/5F9305E3" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F9305E3" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F9305E3" Ref="#PWR0148"  Part="1" 
F 0 "#PWR0148" H 950 1930 50  0001 C CNN
F 1 "+3.3V" H 965 2253 50  0000 C CNN
F 2 "" H 950 2080 50  0001 C CNN
F 3 "" H 950 2080 50  0001 C CNN
	1    950  2080
	1    0    0    -1  
$EndComp
Text GLabel 4035 1150 2    50   Input ~ 0
ADC0
Text GLabel 6340 1180 2    50   Input ~ 0
ADC1
Text GLabel 7075 1440 2    50   Input ~ 0
ADC2
Text GLabel 4135 2930 2    50   Input ~ 0
ADC3
Text GLabel 6440 2960 2    50   Input ~ 0
ADC4
Text GLabel 7495 3220 2    50   Input ~ 0
ADC5
Text GLabel 7505 4920 2    50   Input ~ 0
ADC8
Text GLabel 7490 6590 2    50   Input ~ 0
ADC11
Text GLabel 6450 4660 2    50   Input ~ 0
ADC7
Text GLabel 6435 6330 2    50   Input ~ 0
ADC10
Text GLabel 4145 4630 2    50   Input ~ 0
ADC6
Text GLabel 4130 6300 2    50   Input ~ 0
ADC9
$Comp
L allcolours-rescue:D_Zener_Small-device-allcolours-rescue D?
U 1 1 5F9B20FA
P 1055 3665
AR Path="/5AD5ACBB/5F9B20FA" Ref="D?"  Part="1" 
AR Path="/5F9B20FA" Ref="D?"  Part="1" 
AR Path="/5F96598A/5F9B20FA" Ref="D?"  Part="1" 
AR Path="/5F8E1429/5F9B20FA" Ref="D9"  Part="1" 
F 0 "D9" V 1101 3597 50  0000 R CNN
F 1 "LM4040" V 1010 4030 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" V 1055 3665 50  0001 C CNN
F 3 "https://en.wikipedia.org/wiki/Zener_diode" V 1055 3665 50  0001 C CNN
	1    1055 3665
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 5F9B2101
P 1055 3415
AR Path="/5AD5ACBB/5F9B2101" Ref="R?"  Part="1" 
AR Path="/5F9B2101" Ref="R?"  Part="1" 
AR Path="/5F96598A/5F9B2101" Ref="R?"  Part="1" 
AR Path="/5F8E1429/5F9B2101" Ref="R98"  Part="1" 
F 0 "R98" V 859 3415 50  0000 C CNN
F 1 "470R" V 950 3415 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1055 3415 50  0001 C CNN
F 3 "" H 1055 3415 50  0001 C CNN
	1    1055 3415
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C?
U 1 1 5F9B2108
P 1305 3665
AR Path="/5AD5ACBB/5F9B2108" Ref="C?"  Part="1" 
AR Path="/5F9B2108" Ref="C?"  Part="1" 
AR Path="/5F96598A/5F9B2108" Ref="C?"  Part="1" 
AR Path="/5F8E1429/5F9B2108" Ref="C38"  Part="1" 
F 0 "C38" V 1053 3665 50  0000 C CNN
F 1 "100N" V 1144 3665 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 1343 3515 50  0001 C CNN
F 3 "" H 1305 3665 50  0001 C CNN
	1    1305 3665
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:-12VA-power-allcolours-rescue #PWR?
U 1 1 5F9B210F
P 1055 3265
AR Path="/5AD5ACBB/5F9B210F" Ref="#PWR?"  Part="1" 
AR Path="/5F9B210F" Ref="#PWR?"  Part="1" 
AR Path="/5F96598A/5F9B210F" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F9B210F" Ref="#PWR0153"  Part="1" 
F 0 "#PWR0153" H 1055 3115 50  0001 C CNN
F 1 "-12VA" H 1070 3438 50  0000 C CNN
F 2 "" H 1055 3265 50  0001 C CNN
F 3 "" H 1055 3265 50  0001 C CNN
	1    1055 3265
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F9B2115
P 1055 3815
AR Path="/5AD5ACBB/5F9B2115" Ref="#PWR?"  Part="1" 
AR Path="/5F9B2115" Ref="#PWR?"  Part="1" 
AR Path="/5F96598A/5F9B2115" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F9B2115" Ref="#PWR0154"  Part="1" 
F 0 "#PWR0154" H 1055 3565 50  0001 C CNN
F 1 "GND" H 1060 3642 50  0000 C CNN
F 2 "" H 1055 3815 50  0001 C CNN
F 3 "" H 1055 3815 50  0001 C CNN
	1    1055 3815
	1    0    0    -1  
$EndComp
Wire Wire Line
	1055 3315 1055 3265
Wire Wire Line
	1055 3565 1055 3515
Wire Wire Line
	1055 3515 1305 3515
Connection ~ 1055 3515
Wire Wire Line
	1055 3765 1055 3815
Wire Wire Line
	1055 3815 1305 3815
Connection ~ 1055 3815
Text GLabel 1330 3515 2    60   Input ~ 0
AREF-10
Wire Wire Line
	1305 3515 1330 3515
Connection ~ 1305 3515
$Comp
L Device:R_POT nmode?
U 1 1 5F909D2C
P 7025 2755
AR Path="/5F88C158/5F909D2C" Ref="nmode?"  Part="1" 
AR Path="/5E933887/5F909D2C" Ref="nmode?"  Part="1" 
AR Path="/5F8E1429/5F909D2C" Ref="lmode3"  Part="1" 
F 0 "lmode3" H 6955 2801 50  0000 R CNN
F 1 "10K" H 6955 2710 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 7025 2755 50  0001 C CNN
F 3 "~" H 7025 2755 50  0001 C CNN
	1    7025 2755
	1    0    0    -1  
$EndComp
Wire Wire Line
	7025 2550 7025 2605
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F909D25
P 7025 2945
AR Path="/5F88C158/5F909D25" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F909D25" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F909D25" Ref="#PWR0134"  Part="1" 
F 0 "#PWR0134" H 7025 2695 50  0001 C CNN
F 1 "GND" H 7030 2772 50  0000 C CNN
F 2 "" H 7025 2945 50  0001 C CNN
F 3 "" H 7025 2945 50  0001 C CNN
	1    7025 2945
	1    0    0    -1  
$EndComp
Wire Wire Line
	7175 3220 7175 2755
Wire Wire Line
	7175 3220 7495 3220
Wire Wire Line
	7025 2905 7025 2945
$Comp
L Device:R_POT nmode?
U 1 1 5F8F15B1
P 6925 975
AR Path="/5F88C158/5F8F15B1" Ref="nmode?"  Part="1" 
AR Path="/5E933887/5F8F15B1" Ref="nmode?"  Part="1" 
AR Path="/5F8E1429/5F8F15B1" Ref="nmode1"  Part="1" 
F 0 "nmode1" H 6855 1021 50  0000 R CNN
F 1 "10K" H 6855 930 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 6925 975 50  0001 C CNN
F 3 "~" H 6925 975 50  0001 C CNN
	1    6925 975 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6925 770  6925 825 
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5F8F15B9
P 6925 1165
AR Path="/5F88C158/5F8F15B9" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5F8F15B9" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5F8F15B9" Ref="#PWR0132"  Part="1" 
F 0 "#PWR0132" H 6925 915 50  0001 C CNN
F 1 "GND" H 6930 992 50  0000 C CNN
F 2 "" H 6925 1165 50  0001 C CNN
F 3 "" H 6925 1165 50  0001 C CNN
	1    6925 1165
	1    0    0    -1  
$EndComp
Wire Wire Line
	7075 1440 7075 975 
Wire Wire Line
	6925 1125 6925 1165
$Comp
L power:+3.3V #PWR?
U 1 1 5FA8551C
P 7025 2550
AR Path="/5F88C158/5FA8551C" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5FA8551C" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5FA8551C" Ref="#PWR0155"  Part="1" 
F 0 "#PWR0155" H 7025 2400 50  0001 C CNN
F 1 "+3.3V" H 7040 2723 50  0000 C CNN
F 2 "" H 7025 2550 50  0001 C CNN
F 3 "" H 7025 2550 50  0001 C CNN
	1    7025 2550
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FA85F86
P 6925 770
AR Path="/5F88C158/5FA85F86" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5FA85F86" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5FA85F86" Ref="#PWR0156"  Part="1" 
F 0 "#PWR0156" H 6925 620 50  0001 C CNN
F 1 "+3.3V" H 6940 943 50  0000 C CNN
F 2 "" H 6925 770 50  0001 C CNN
F 3 "" H 6925 770 50  0001 C CNN
	1    6925 770 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FA86007
P 7035 4250
AR Path="/5F88C158/5FA86007" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5FA86007" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5FA86007" Ref="#PWR0157"  Part="1" 
F 0 "#PWR0157" H 7035 4100 50  0001 C CNN
F 1 "+3.3V" H 7050 4423 50  0000 C CNN
F 2 "" H 7035 4250 50  0001 C CNN
F 3 "" H 7035 4250 50  0001 C CNN
	1    7035 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FA87C03
P 7020 5920
AR Path="/5F88C158/5FA87C03" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/5FA87C03" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/5FA87C03" Ref="#PWR0158"  Part="1" 
F 0 "#PWR0158" H 7020 5770 50  0001 C CNN
F 1 "+3.3V" H 7035 6093 50  0000 C CNN
F 2 "" H 7020 5920 50  0001 C CNN
F 3 "" H 7020 5920 50  0001 C CNN
	1    7020 5920
	1    0    0    -1  
$EndComp
$EndSCHEMATC
