EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 9
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
L Device:CP_Small C5
U 1 1 5C058E17
P 3530 1680
F 0 "C5" V 3430 1680 50  0000 C CNN
F 1 "47u" V 3664 1680 50  0000 C CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 3530 1680 50  0001 C CNN
F 3 "~" H 3530 1680 50  0001 C CNN
	1    3530 1680
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R90
U 1 1 5C05ED84
P 3700 1580
F 0 "R90" H 3759 1626 50  0000 L CNN
F 1 "150K" H 3759 1535 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 3700 1580 50  0001 C CNN
F 3 "~" H 3700 1580 50  0001 C CNN
	1    3700 1580
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C08549D
P 5090 1580
AR Path="/5BAC374C/5C08549D" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C08549D" Ref="Q46"  Part="1" 
F 0 "Q46" H 5281 1626 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5281 1535 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 5290 1680 50  0001 C CNN
F 3 "" H 5090 1580 50  0001 C CNN
	1    5090 1580
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0876D9
P 1435 1605
AR Path="/5BAC374C/5C0876D9" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C0876D9" Ref="Q44"  Part="1" 
F 0 "Q44" H 1626 1651 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1626 1560 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1635 1705 50  0001 C CNN
F 3 "" H 1435 1605 50  0001 C CNN
	1    1435 1605
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C0879AF
P 1535 1055
AR Path="/5BAC374C/5C0879AF" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C0879AF" Ref="#PWR0191"  Part="1" 
F 0 "#PWR0191" H 1535 905 50  0001 C CNN
F 1 "+12V" H 1535 1195 50  0000 C CNN
F 2 "" H 1535 1055 50  0000 C CNN
F 3 "" H 1535 1055 50  0000 C CNN
	1    1535 1055
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C087C36
P 1535 1880
AR Path="/5BAC374C/5C087C36" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C087C36" Ref="#PWR0194"  Part="1" 
F 0 "#PWR0194" H 1535 1630 50  0001 C CNN
F 1 "GND" H 1535 1730 50  0000 C CNN
F 2 "" H 1535 1880 50  0000 C CNN
F 3 "" H 1535 1880 50  0000 C CNN
	1    1535 1880
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C087D10
P 4450 3140
AR Path="/5BAC374C/5C087D10" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C087D10" Ref="#PWR0196"  Part="1" 
F 0 "#PWR0196" H 4450 2890 50  0001 C CNN
F 1 "GND" H 4450 2990 50  0000 C CNN
F 2 "" H 4450 3140 50  0000 C CNN
F 3 "" H 4450 3140 50  0000 C CNN
	1    4450 3140
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J52
U 1 1 5C08867C
P 3190 1680
F 0 "J52" V 3063 1760 50  0000 L CNN
F 1 "p" V 3154 1760 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3190 1680 50  0001 C CNN
F 3 "" H 3190 1680 50  0001 C CNN
	1    3190 1680
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J46
U 1 1 5C088A1A
P 960 1605
F 0 "J46" V 833 1685 50  0000 L CNN
F 1 "p" V 924 1685 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 960 1605 50  0001 C CNN
F 3 "" H 960 1605 50  0001 C CNN
	1    960  1605
	-1   0    0    1   
$EndComp
Wire Wire Line
	1160 1605 1235 1605
Wire Wire Line
	1535 1805 1535 1880
Text Notes 7275 925  0    197  ~ 0
synthi noise source
Wire Wire Line
	1535 1380 1710 1380
Connection ~ 1535 1380
Wire Wire Line
	1535 1380 1535 1405
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0AA7C9
P 7625 2625
AR Path="/5BAC374C/5C0AA7C9" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C0AA7C9" Ref="Q52"  Part="1" 
F 0 "Q52" H 7816 2671 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7816 2580 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7825 2725 50  0001 C CNN
F 3 "" H 7625 2625 50  0001 C CNN
	1    7625 2625
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0AA920
P 8000 2275
AR Path="/5BAC374C/5C0AA920" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C0AA920" Ref="Q53"  Part="1" 
F 0 "Q53" H 8191 2321 50  0000 L CNN
F 1 "Q_NPN_BEC" H 8191 2230 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 8200 2375 50  0001 C CNN
F 3 "" H 8000 2275 50  0001 C CNN
	1    8000 2275
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_PNP_BEC Q54
U 1 1 5C0B90FA
P 8100 1725
F 0 "Q54" H 8291 1679 50  0000 L CNN
F 1 "Q_PNP_BEC" H 8291 1770 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 8300 1825 50  0001 C CNN
F 3 "~" H 8100 1725 50  0001 C CNN
	1    8100 1725
	1    0    0    1   
$EndComp
Text Notes 1290 925  0    197  ~ 0
noise switch x2
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q55
U 1 1 5C0C5673
P 8300 3575
F 0 "Q55" H 8491 3621 50  0000 L CNN
F 1 "Q_NPN_BEC" H 8491 3530 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 8500 3675 50  0001 C CNN
F 3 "" H 8300 3575 50  0001 C CNN
	1    8300 3575
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR0197
U 1 1 5C0C57DC
P 8200 1425
F 0 "#PWR0197" H 8200 1275 50  0001 C CNN
F 1 "+12V" H 8200 1565 50  0000 C CNN
F 2 "" H 8200 1425 50  0000 C CNN
F 3 "" H 8200 1425 50  0000 C CNN
	1    8200 1425
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R94
U 1 1 5C0C59F8
P 7900 1550
F 0 "R94" H 7959 1596 50  0000 L CNN
F 1 "47K" H 7959 1505 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 7900 1550 50  0001 C CNN
F 3 "~" H 7900 1550 50  0001 C CNN
	1    7900 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R95
U 1 1 5C0C5BBA
P 7900 1900
F 0 "R95" H 7959 1946 50  0000 L CNN
F 1 "2K7" H 7959 1855 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 7900 1900 50  0001 C CNN
F 3 "~" H 7900 1900 50  0001 C CNN
	1    7900 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R98
U 1 1 5C0C81DC
P 8400 2275
F 0 "R98" V 8204 2275 50  0000 C CNN
F 1 "470K" V 8295 2275 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 8400 2275 50  0001 C CNN
F 3 "~" H 8400 2275 50  0001 C CNN
	1    8400 2275
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR0198
U 1 1 5C0CA99A
P 7625 2900
F 0 "#PWR0198" H 7625 2650 50  0001 C CNN
F 1 "GND" H 7625 2750 50  0000 C CNN
F 2 "" H 7625 2900 50  0000 C CNN
F 3 "" H 7625 2900 50  0000 C CNN
	1    7625 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R99
U 1 1 5C0CAA41
P 8500 1975
F 0 "R99" H 8559 2021 50  0000 L CNN
F 1 "330R" H 8559 1930 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 8500 1975 50  0001 C CNN
F 3 "~" H 8500 1975 50  0001 C CNN
	1    8500 1975
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R100
U 1 1 5C0CAB42
P 8500 2500
F 0 "R100" H 8559 2546 50  0000 L CNN
F 1 "1K" H 8559 2455 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 8500 2500 50  0001 C CNN
F 3 "~" H 8500 2500 50  0001 C CNN
	1    8500 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C11
U 1 1 5C0CACC9
P 8250 2525
F 0 "C11" H 8338 2571 50  0000 L CNN
F 1 "22uF" H 8338 2480 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 8250 2525 50  0001 C CNN
F 3 "~" H 8250 2525 50  0001 C CNN
	1    8250 2525
	1    0    0    -1  
$EndComp
$Comp
L Device:RTRIM R97
U 1 1 5C0CB048
P 8250 2850
F 0 "R97" H 8378 2896 50  0000 L CNN
F 1 "RTRIM" H 8378 2805 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 8180 2850 50  0001 C CNN
F 3 "~" H 8250 2850 50  0001 C CNN
	1    8250 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7625 2825 7625 2900
Wire Wire Line
	7900 2475 7900 2525
Wire Wire Line
	7900 2525 7825 2525
Wire Wire Line
	8200 2275 8250 2275
Wire Wire Line
	8250 2425 8250 2275
Connection ~ 8250 2275
Wire Wire Line
	8250 2275 8300 2275
Wire Wire Line
	8250 2700 8250 2625
$Comp
L allcolours_analogue-rescue:GND-power #PWR0199
U 1 1 5C0D71CB
P 8250 3050
F 0 "#PWR0199" H 8250 2800 50  0001 C CNN
F 1 "GND" H 8250 2900 50  0000 C CNN
F 2 "" H 8250 3050 50  0000 C CNN
F 3 "" H 8250 3050 50  0000 C CNN
	1    8250 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3000 8250 3050
Wire Wire Line
	7900 2000 7900 2075
Wire Wire Line
	7900 1650 7900 1725
Wire Wire Line
	7900 1725 7900 1800
Connection ~ 7900 1725
Wire Wire Line
	8200 1425 8200 1450
Wire Wire Line
	7900 1450 8200 1450
Connection ~ 8200 1450
Wire Wire Line
	8200 1450 8200 1525
Wire Wire Line
	8200 1450 8500 1450
Wire Wire Line
	8500 1450 8500 1875
Wire Wire Line
	8500 2275 8500 2075
$Comp
L Device:R_Small R96
U 1 1 5C0EE152
P 8100 3425
F 0 "R96" H 8159 3471 50  0000 L CNN
F 1 "1K" H 8159 3380 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 8100 3425 50  0001 C CNN
F 3 "~" H 8100 3425 50  0001 C CNN
	1    8100 3425
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1925 8200 2100
Wire Wire Line
	8200 2100 8100 2100
Wire Wire Line
	8100 2100 8100 3325
Wire Wire Line
	8100 3525 8100 3575
Wire Wire Line
	8500 2275 8500 2400
Connection ~ 8500 2275
Wire Wire Line
	8400 3375 8400 3325
Wire Wire Line
	8400 2700 8500 2700
Wire Wire Line
	8500 2700 8500 2600
$Comp
L allcolours_analogue-rescue:C-device C12
U 1 1 5C1017E0
P 8250 3325
F 0 "C12" H 8275 3425 50  0000 L CNN
F 1 "330pF" H 8275 3225 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8288 3175 50  0001 C CNN
F 3 "" H 8250 3325 50  0000 C CNN
	1    8250 3325
	0    -1   -1   0   
$EndComp
Connection ~ 8100 3325
Connection ~ 8400 3325
Wire Wire Line
	8400 3325 8400 2700
$Comp
L power:-12V #PWR0200
U 1 1 5C102AF1
P 8400 3850
F 0 "#PWR0200" H 8400 3950 50  0001 C CNN
F 1 "-12V" H 8415 4023 50  0000 C CNN
F 2 "" H 8400 3850 50  0001 C CNN
F 3 "" H 8400 3850 50  0001 C CNN
	1    8400 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	8400 3775 8400 3850
Wire Wire Line
	8400 3325 8500 3325
$Comp
L Device:CP_Small C13
U 1 1 5C109C9A
P 8600 3325
F 0 "C13" V 8825 3325 50  0000 C CNN
F 1 "22uF" V 8734 3325 50  0000 C CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 8600 3325 50  0001 C CNN
F 3 "~" H 8600 3325 50  0001 C CNN
	1    8600 3325
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1B6B14
P 4350 1225
AR Path="/5BAC374C/5C1B6B14" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1B6B14" Ref="#PWR0193"  Part="1" 
F 0 "#PWR0193" H 4350 1075 50  0001 C CNN
F 1 "+12V" H 4350 1365 50  0000 C CNN
F 2 "" H 4350 1225 50  0000 C CNN
F 3 "" H 4350 1225 50  0000 C CNN
	1    4350 1225
	1    0    0    -1  
$EndComp
Text Label 1710 1380 0    197  ~ 0
SW1
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1BA1B2
P 3950 1430
AR Path="/5BAC374C/5C1BA1B2" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1BA1B2" Ref="#PWR0190"  Part="1" 
F 0 "#PWR0190" H 3950 1180 50  0001 C CNN
F 1 "GND" H 3950 1280 50  0000 C CNN
F 2 "" H 3950 1430 50  0000 C CNN
F 3 "" H 3950 1430 50  0000 C CNN
	1    3950 1430
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R93
U 1 1 5C1BA322
P 3760 1980
F 0 "R93" H 3819 2026 50  0000 L CNN
F 1 "47K" H 3810 2105 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 3760 1980 50  0001 C CNN
F 3 "~" H 3760 1980 50  0001 C CNN
	1    3760 1980
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1BA718
P 3690 2080
AR Path="/5BAC374C/5C1BA718" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1BA718" Ref="#PWR072"  Part="1" 
F 0 "#PWR072" H 3690 1930 50  0001 C CNN
F 1 "+12V" H 3690 2220 50  0000 C CNN
F 2 "" H 3690 2080 50  0000 C CNN
F 3 "" H 3690 2080 50  0000 C CNN
	1    3690 2080
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1580 3850 1430
Wire Wire Line
	3850 1430 3950 1430
Wire Wire Line
	4850 1580 4890 1580
Wire Wire Line
	4850 1880 5190 1880
Wire Wire Line
	5190 1880 5190 1780
Wire Wire Line
	4850 2180 5310 2180
Wire Wire Line
	5310 2180 5310 1330
Wire Wire Line
	5310 1330 5190 1330
Wire Wire Line
	5190 1330 5190 1380
Wire Wire Line
	3630 1680 3700 1680
Wire Wire Line
	3700 1680 3850 1680
Connection ~ 3700 1680
Wire Wire Line
	3390 1680 3430 1680
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J69
U 1 1 5C1C4241
P 3500 1880
F 0 "J69" V 3373 1960 50  0000 L CNN
F 1 "p" V 3464 1960 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3500 1880 50  0001 C CNN
F 3 "" H 3500 1880 50  0001 C CNN
	1    3500 1880
	-1   0    0    1   
$EndComp
Wire Wire Line
	3690 2080 3760 2080
Wire Wire Line
	3700 1880 3760 1880
Connection ~ 3760 1880
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1C8F90
P 3850 2010
AR Path="/5BAC374C/5C1C8F90" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1C8F90" Ref="#PWR0188"  Part="1" 
F 0 "#PWR0188" H 3850 1760 50  0001 C CNN
F 1 "GND" H 3850 1860 50  0000 C CNN
F 2 "" H 3850 2010 50  0000 C CNN
F 3 "" H 3850 2010 50  0000 C CNN
	1    3850 2010
	1    0    0    -1  
$EndComp
Wire Wire Line
	3760 1880 3850 1880
Connection ~ 3760 2080
Wire Wire Line
	3760 2080 3770 2080
Wire Wire Line
	3850 1980 3850 2010
Wire Wire Line
	3700 1480 3060 1480
Wire Wire Line
	3060 1480 3060 2280
Wire Wire Line
	3060 2280 3510 2280
$Comp
L Device:R_Small R89
U 1 1 5C1CECFE
P 3510 2380
F 0 "R89" H 3569 2426 50  0000 L CNN
F 1 "10K" H 3569 2335 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 3510 2380 50  0001 C CNN
F 3 "~" H 3510 2380 50  0001 C CNN
	1    3510 2380
	-1   0    0    1   
$EndComp
Connection ~ 3510 2280
Wire Wire Line
	3510 2280 3850 2280
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1D0298
P 3620 2480
AR Path="/5BAC374C/5C1D0298" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1D0298" Ref="#PWR062"  Part="1" 
F 0 "#PWR062" H 3620 2330 50  0001 C CNN
F 1 "+12V" H 3620 2620 50  0000 C CNN
F 2 "" H 3620 2480 50  0000 C CNN
F 3 "" H 3620 2480 50  0000 C CNN
	1    3620 2480
	1    0    0    -1  
$EndComp
Wire Wire Line
	3510 2480 3620 2480
$Comp
L Device:CP_Small C7
U 1 1 5C1D15E1
P 2960 2280
F 0 "C7" V 2860 2280 50  0000 C CNN
F 1 "10u" V 3110 2180 50  0000 C CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 2960 2280 50  0001 C CNN
F 3 "~" H 2960 2280 50  0001 C CNN
	1    2960 2280
	0    1    1    0   
$EndComp
Connection ~ 3060 2280
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J66
U 1 1 5C1D1C93
P 2660 2280
F 0 "J66" V 2533 2360 50  0000 L CNN
F 1 "p" V 2624 2360 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2660 2280 50  0001 C CNN
F 3 "" H 2660 2280 50  0001 C CNN
	1    2660 2280
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C1D2BE0
P 1420 2820
AR Path="/5BAC374C/5C1D2BE0" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C1D2BE0" Ref="Q50"  Part="1" 
F 0 "Q50" H 1611 2866 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1611 2775 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1620 2920 50  0001 C CNN
F 3 "" H 1420 2820 50  0001 C CNN
	1    1420 2820
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1D2BE6
P 1520 2260
AR Path="/5BAC374C/5C1D2BE6" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1D2BE6" Ref="#PWR045"  Part="1" 
F 0 "#PWR045" H 1520 2110 50  0001 C CNN
F 1 "+12V" H 1520 2400 50  0000 C CNN
F 2 "" H 1520 2260 50  0000 C CNN
F 3 "" H 1520 2260 50  0000 C CNN
	1    1520 2260
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1D2BEC
P 1520 3095
AR Path="/5BAC374C/5C1D2BEC" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1D2BEC" Ref="#PWR046"  Part="1" 
F 0 "#PWR046" H 1520 2845 50  0001 C CNN
F 1 "GND" H 1520 2945 50  0000 C CNN
F 2 "" H 1520 3095 50  0000 C CNN
F 3 "" H 1520 3095 50  0000 C CNN
	1    1520 3095
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J64
U 1 1 5C1D2BF2
P 945 2820
F 0 "J64" V 818 2900 50  0000 L CNN
F 1 "p" V 909 2900 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 945 2820 50  0001 C CNN
F 3 "" H 945 2820 50  0001 C CNN
	1    945  2820
	-1   0    0    1   
$EndComp
Wire Wire Line
	1145 2820 1220 2820
Wire Wire Line
	1520 3020 1520 3095
Wire Wire Line
	1520 2595 1695 2595
Connection ~ 1520 2595
Wire Wire Line
	1520 2595 1520 2620
Text Label 1695 2595 0    197  ~ 0
SW2
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C1D3E15
P 1405 3985
AR Path="/5BAC374C/5C1D3E15" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C1D3E15" Ref="Q47"  Part="1" 
F 0 "Q47" H 1596 4031 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1596 3940 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1605 4085 50  0001 C CNN
F 3 "" H 1405 3985 50  0001 C CNN
	1    1405 3985
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1D3E1B
P 1505 3450
AR Path="/5BAC374C/5C1D3E1B" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1D3E1B" Ref="#PWR038"  Part="1" 
F 0 "#PWR038" H 1505 3300 50  0001 C CNN
F 1 "+12V" H 1510 3515 50  0000 C CNN
F 2 "" H 1505 3450 50  0000 C CNN
F 3 "" H 1505 3450 50  0000 C CNN
	1    1505 3450
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1D3E21
P 1505 4260
AR Path="/5BAC374C/5C1D3E21" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1D3E21" Ref="#PWR039"  Part="1" 
F 0 "#PWR039" H 1505 4010 50  0001 C CNN
F 1 "GND" H 1505 4110 50  0000 C CNN
F 2 "" H 1505 4260 50  0000 C CNN
F 3 "" H 1505 4260 50  0000 C CNN
	1    1505 4260
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J48
U 1 1 5C1D3E27
P 930 3985
F 0 "J48" V 803 4065 50  0000 L CNN
F 1 "p" V 894 4065 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 930 3985 50  0001 C CNN
F 3 "" H 930 3985 50  0001 C CNN
	1    930  3985
	-1   0    0    1   
$EndComp
Wire Wire Line
	1130 3985 1205 3985
Wire Wire Line
	1505 4185 1505 4260
Wire Wire Line
	1505 3760 1680 3760
Connection ~ 1505 3760
Wire Wire Line
	1505 3760 1505 3785
Text Label 1680 3760 0    197  ~ 0
SW3
Wire Wire Line
	3850 2580 3720 2580
Text Label 3720 2580 2    79   ~ 0
SW1
Wire Wire Line
	3850 2680 3720 2680
Wire Wire Line
	3850 2780 3710 2780
Text Label 3720 2680 2    79   ~ 0
SW2
Text Label 3710 2780 2    79   ~ 0
SW3
Wire Wire Line
	4350 3080 4450 3080
Wire Wire Line
	4450 3140 4450 3080
$Comp
L 4xxx:4053 U17
U 1 1 5C1B4730
P 4350 2180
F 0 "U17" H 4410 2385 50  0000 C CNN
F 1 "4053" H 4410 2535 50  0000 C CNN
F 2 "SMD_Packages:SO-16-N" H 4350 2180 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4051bms-52bms-53bms.pdf" H 4350 2180 50  0001 C CNN
	1    4350 2180
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1DFAA9
P 3770 2430
AR Path="/5BAC374C/5C1DFAA9" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1DFAA9" Ref="#PWR078"  Part="1" 
F 0 "#PWR078" H 3770 2180 50  0001 C CNN
F 1 "GND" H 3770 2280 50  0000 C CNN
F 2 "" H 3770 2430 50  0000 C CNN
F 3 "" H 3770 2430 50  0000 C CNN
	1    3770 2430
	1    0    0    -1  
$EndComp
Wire Wire Line
	3770 2430 3850 2430
Wire Wire Line
	3850 2430 3850 2480
$Comp
L Device:CP_Small C9
U 1 1 5C1E2A86
P 3510 4770
F 0 "C9" V 3410 4770 50  0000 C CNN
F 1 "47u" V 3644 4770 50  0000 C CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 3510 4770 50  0001 C CNN
F 3 "~" H 3510 4770 50  0001 C CNN
	1    3510 4770
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R91
U 1 1 5C1E2A8D
P 3680 4670
F 0 "R91" H 3739 4716 50  0000 L CNN
F 1 "150K" H 3739 4625 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 3680 4670 50  0001 C CNN
F 3 "~" H 3680 4670 50  0001 C CNN
	1    3680 4670
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C1E2A94
P 5070 4670
AR Path="/5BAC374C/5C1E2A94" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C1E2A94" Ref="Q51"  Part="1" 
F 0 "Q51" H 5261 4716 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5261 4625 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 5270 4770 50  0001 C CNN
F 3 "" H 5070 4670 50  0001 C CNN
	1    5070 4670
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C1E2A9B
P 1430 5205
AR Path="/5BAC374C/5C1E2A9B" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C1E2A9B" Ref="Q48"  Part="1" 
F 0 "Q48" H 1621 5251 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1621 5160 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1630 5305 50  0001 C CNN
F 3 "" H 1430 5205 50  0001 C CNN
	1    1430 5205
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1E2AA2
P 1530 4645
AR Path="/5BAC374C/5C1E2AA2" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2AA2" Ref="#PWR040"  Part="1" 
F 0 "#PWR040" H 1530 4495 50  0001 C CNN
F 1 "+12V" H 1530 4785 50  0000 C CNN
F 2 "" H 1530 4645 50  0000 C CNN
F 3 "" H 1530 4645 50  0000 C CNN
	1    1530 4645
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1E2AA8
P 1530 5480
AR Path="/5BAC374C/5C1E2AA8" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2AA8" Ref="#PWR041"  Part="1" 
F 0 "#PWR041" H 1530 5230 50  0001 C CNN
F 1 "GND" H 1530 5330 50  0000 C CNN
F 2 "" H 1530 5480 50  0000 C CNN
F 3 "" H 1530 5480 50  0000 C CNN
	1    1530 5480
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1E2AAE
P 4430 6230
AR Path="/5BAC374C/5C1E2AAE" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2AAE" Ref="#PWR0195"  Part="1" 
F 0 "#PWR0195" H 4430 5980 50  0001 C CNN
F 1 "GND" H 4430 6080 50  0000 C CNN
F 2 "" H 4430 6230 50  0000 C CNN
F 3 "" H 4430 6230 50  0000 C CNN
	1    4430 6230
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J67
U 1 1 5C1E2AB4
P 3170 4770
F 0 "J67" V 3043 4850 50  0000 L CNN
F 1 "p" V 3134 4850 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3170 4770 50  0001 C CNN
F 3 "" H 3170 4770 50  0001 C CNN
	1    3170 4770
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J53
U 1 1 5C1E2ABB
P 955 5205
F 0 "J53" V 828 5285 50  0000 L CNN
F 1 "p" V 919 5285 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 955 5205 50  0001 C CNN
F 3 "" H 955 5205 50  0001 C CNN
	1    955  5205
	-1   0    0    1   
$EndComp
Wire Wire Line
	1155 5205 1230 5205
Wire Wire Line
	1530 5405 1530 5480
Wire Wire Line
	1530 4980 1705 4980
Connection ~ 1530 4980
Wire Wire Line
	1530 4980 1530 5005
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1E2AC8
P 4330 4330
AR Path="/5BAC374C/5C1E2AC8" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2AC8" Ref="#PWR0192"  Part="1" 
F 0 "#PWR0192" H 4330 4180 50  0001 C CNN
F 1 "+12V" H 4330 4470 50  0000 C CNN
F 2 "" H 4330 4330 50  0000 C CNN
F 3 "" H 4330 4330 50  0000 C CNN
	1    4330 4330
	1    0    0    -1  
$EndComp
Text Label 1705 4980 0    197  ~ 0
SW4
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1E2ACF
P 3930 4520
AR Path="/5BAC374C/5C1E2ACF" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2ACF" Ref="#PWR0189"  Part="1" 
F 0 "#PWR0189" H 3930 4270 50  0001 C CNN
F 1 "GND" H 3930 4370 50  0000 C CNN
F 2 "" H 3930 4520 50  0000 C CNN
F 3 "" H 3930 4520 50  0000 C CNN
	1    3930 4520
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R92
U 1 1 5C1E2AD5
P 3740 5070
F 0 "R92" H 3799 5116 50  0000 L CNN
F 1 "47K" H 3790 5195 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 3740 5070 50  0001 C CNN
F 3 "~" H 3740 5070 50  0001 C CNN
	1    3740 5070
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1E2ADC
P 3670 5170
AR Path="/5BAC374C/5C1E2ADC" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2ADC" Ref="#PWR070"  Part="1" 
F 0 "#PWR070" H 3670 5020 50  0001 C CNN
F 1 "+12V" H 3670 5310 50  0000 C CNN
F 2 "" H 3670 5170 50  0000 C CNN
F 3 "" H 3670 5170 50  0000 C CNN
	1    3670 5170
	1    0    0    -1  
$EndComp
Wire Wire Line
	3830 4670 3830 4520
Wire Wire Line
	3830 4520 3930 4520
Wire Wire Line
	4830 4670 4870 4670
Wire Wire Line
	4830 4970 5170 4970
Wire Wire Line
	5170 4970 5170 4870
Wire Wire Line
	4830 5270 5290 5270
Wire Wire Line
	5290 5270 5290 4420
Wire Wire Line
	5290 4420 5170 4420
Wire Wire Line
	5170 4420 5170 4470
Wire Wire Line
	3610 4770 3680 4770
Wire Wire Line
	3680 4770 3830 4770
Connection ~ 3680 4770
Wire Wire Line
	3370 4770 3410 4770
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J68
U 1 1 5C1E2AEF
P 3480 4970
F 0 "J68" V 3353 5050 50  0000 L CNN
F 1 "p" V 3444 5050 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3480 4970 50  0001 C CNN
F 3 "" H 3480 4970 50  0001 C CNN
	1    3480 4970
	-1   0    0    1   
$EndComp
Wire Wire Line
	3670 5170 3740 5170
Wire Wire Line
	3680 4970 3740 4970
Connection ~ 3740 4970
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1E2AF9
P 3830 5100
AR Path="/5BAC374C/5C1E2AF9" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2AF9" Ref="#PWR0187"  Part="1" 
F 0 "#PWR0187" H 3830 4850 50  0001 C CNN
F 1 "GND" H 3830 4950 50  0000 C CNN
F 2 "" H 3830 5100 50  0000 C CNN
F 3 "" H 3830 5100 50  0000 C CNN
	1    3830 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3740 4970 3830 4970
Connection ~ 3740 5170
Wire Wire Line
	3740 5170 3750 5170
Wire Wire Line
	3830 5070 3830 5100
Wire Wire Line
	3680 4570 3040 4570
Wire Wire Line
	3040 4570 3040 5370
Wire Wire Line
	3040 5370 3490 5370
$Comp
L Device:R_Small R88
U 1 1 5C1E2B06
P 3490 5470
F 0 "R88" H 3549 5516 50  0000 L CNN
F 1 "10K" H 3549 5425 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 3490 5470 50  0001 C CNN
F 3 "~" H 3490 5470 50  0001 C CNN
	1    3490 5470
	-1   0    0    1   
$EndComp
Connection ~ 3490 5370
Wire Wire Line
	3490 5370 3830 5370
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1E2B0F
P 3600 5570
AR Path="/5BAC374C/5C1E2B0F" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2B0F" Ref="#PWR055"  Part="1" 
F 0 "#PWR055" H 3600 5420 50  0001 C CNN
F 1 "+12V" H 3600 5710 50  0000 C CNN
F 2 "" H 3600 5570 50  0000 C CNN
F 3 "" H 3600 5570 50  0000 C CNN
	1    3600 5570
	1    0    0    -1  
$EndComp
Wire Wire Line
	3490 5570 3600 5570
$Comp
L Device:CP_Small C3
U 1 1 5C1E2B16
P 2940 5370
F 0 "C3" V 2840 5370 50  0000 C CNN
F 1 "10u" V 3090 5270 50  0000 C CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 2940 5370 50  0001 C CNN
F 3 "~" H 2940 5370 50  0001 C CNN
	1    2940 5370
	0    1    1    0   
$EndComp
Connection ~ 3040 5370
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J65
U 1 1 5C1E2B1E
P 2640 5370
F 0 "J65" V 2513 5450 50  0000 L CNN
F 1 "p" V 2604 5450 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2640 5370 50  0001 C CNN
F 3 "" H 2640 5370 50  0001 C CNN
	1    2640 5370
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C1E2B25
P 1405 6435
AR Path="/5BAC374C/5C1E2B25" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C1E2B25" Ref="Q49"  Part="1" 
F 0 "Q49" H 1596 6481 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1596 6390 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1605 6535 50  0001 C CNN
F 3 "" H 1405 6435 50  0001 C CNN
	1    1405 6435
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1E2B2C
P 1505 5900
AR Path="/5BAC374C/5C1E2B2C" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2B2C" Ref="#PWR042"  Part="1" 
F 0 "#PWR042" H 1505 5750 50  0001 C CNN
F 1 "+12V" H 1505 6040 50  0000 C CNN
F 2 "" H 1505 5900 50  0000 C CNN
F 3 "" H 1505 5900 50  0000 C CNN
	1    1505 5900
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1E2B32
P 1505 6710
AR Path="/5BAC374C/5C1E2B32" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2B32" Ref="#PWR044"  Part="1" 
F 0 "#PWR044" H 1505 6460 50  0001 C CNN
F 1 "GND" H 1505 6560 50  0000 C CNN
F 2 "" H 1505 6710 50  0000 C CNN
F 3 "" H 1505 6710 50  0000 C CNN
	1    1505 6710
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J54
U 1 1 5C1E2B38
P 930 6435
F 0 "J54" V 803 6515 50  0000 L CNN
F 1 "p" V 894 6515 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 930 6435 50  0001 C CNN
F 3 "" H 930 6435 50  0001 C CNN
	1    930  6435
	-1   0    0    1   
$EndComp
Wire Wire Line
	1130 6435 1205 6435
Wire Wire Line
	1505 6635 1505 6710
Wire Wire Line
	1505 6210 1680 6210
Connection ~ 1505 6210
Wire Wire Line
	1505 6210 1505 6235
Text Label 1680 6210 0    197  ~ 0
SW5
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C1E2B46
P 2710 7030
AR Path="/5BAC374C/5C1E2B46" Ref="Q?"  Part="1" 
AR Path="/5C0A69D0/5C1E2B46" Ref="Q45"  Part="1" 
F 0 "Q45" H 2901 7076 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2901 6985 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2910 7130 50  0001 C CNN
F 3 "" H 2710 7030 50  0001 C CNN
	1    2710 7030
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C1E2B4D
P 2810 6515
AR Path="/5BAC374C/5C1E2B4D" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2B4D" Ref="#PWR033"  Part="1" 
F 0 "#PWR033" H 2810 6365 50  0001 C CNN
F 1 "+12V" H 2835 6695 50  0000 C CNN
F 2 "" H 2810 6515 50  0000 C CNN
F 3 "" H 2810 6515 50  0000 C CNN
	1    2810 6515
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1E2B53
P 2810 7305
AR Path="/5BAC374C/5C1E2B53" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2B53" Ref="#PWR037"  Part="1" 
F 0 "#PWR037" H 2810 7055 50  0001 C CNN
F 1 "GND" H 2810 7155 50  0000 C CNN
F 2 "" H 2810 7305 50  0000 C CNN
F 3 "" H 2810 7305 50  0000 C CNN
	1    2810 7305
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J47
U 1 1 5C1E2B59
P 2235 7030
F 0 "J47" V 2108 7110 50  0000 L CNN
F 1 "p" V 2199 7110 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2235 7030 50  0001 C CNN
F 3 "" H 2235 7030 50  0001 C CNN
	1    2235 7030
	-1   0    0    1   
$EndComp
Wire Wire Line
	2435 7030 2510 7030
Wire Wire Line
	2810 6755 2810 6805
Wire Wire Line
	2810 7230 2810 7305
Wire Wire Line
	2810 6805 2985 6805
Connection ~ 2810 6805
Wire Wire Line
	2810 6805 2810 6830
Text Label 2985 6805 0    197  ~ 0
SW6
Wire Wire Line
	3830 5670 3700 5670
Text Label 3700 5670 2    79   ~ 0
SW4
Wire Wire Line
	3830 5770 3700 5770
Wire Wire Line
	3830 5870 3690 5870
Text Label 3700 5770 2    79   ~ 0
SW5
Text Label 3690 5870 2    79   ~ 0
SW6
Wire Wire Line
	4330 6170 4430 6170
Wire Wire Line
	4430 6230 4430 6170
$Comp
L 4xxx:4053 U9
U 1 1 5C1E2B6F
P 4330 5270
F 0 "U9" H 4390 5475 50  0000 C CNN
F 1 "4053" H 4390 5625 50  0000 C CNN
F 2 "SMD_Packages:SO-16-N" H 4330 5270 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4051bms-52bms-53bms.pdf" H 4330 5270 50  0001 C CNN
	1    4330 5270
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C1E2B76
P 3750 5520
AR Path="/5BAC374C/5C1E2B76" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5C1E2B76" Ref="#PWR076"  Part="1" 
F 0 "#PWR076" H 3750 5270 50  0001 C CNN
F 1 "GND" H 3750 5370 50  0000 C CNN
F 2 "" H 3750 5520 50  0000 C CNN
F 3 "" H 3750 5520 50  0000 C CNN
	1    3750 5520
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 5520 3830 5520
Wire Wire Line
	3830 5520 3830 5570
Wire Wire Line
	4330 4330 4330 4370
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J70
U 1 1 5C0BFD51
P 8940 3325
F 0 "J70" V 8813 3405 50  0000 L CNN
F 1 "snoise_out" V 8904 3405 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 8940 3325 50  0001 C CNN
F 3 "" H 8940 3325 50  0001 C CNN
	1    8940 3325
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 3325 8740 3325
Wire Wire Line
	4350 1225 4350 1280
$Comp
L Device:R_Small R42
U 1 1 5C0C5F3E
P 1535 1200
F 0 "R42" H 1594 1246 50  0000 L CNN
F 1 "1K" H 1594 1155 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 1535 1200 50  0001 C CNN
F 3 "~" H 1535 1200 50  0001 C CNN
	1    1535 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1535 1055 1535 1100
Wire Wire Line
	1535 1300 1535 1380
$Comp
L Device:R_Small R21
U 1 1 5C0CF103
P 1505 6030
F 0 "R21" H 1564 6076 50  0000 L CNN
F 1 "1K" H 1564 5985 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 1505 6030 50  0001 C CNN
F 3 "~" H 1505 6030 50  0001 C CNN
	1    1505 6030
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R18
U 1 1 5C0D8F47
P 1505 3590
F 0 "R18" H 1564 3636 50  0000 L CNN
F 1 "1K" H 1564 3545 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 1505 3590 50  0001 C CNN
F 3 "~" H 1505 3590 50  0001 C CNN
	1    1505 3590
	1    0    0    -1  
$EndComp
Wire Wire Line
	1520 2260 1520 2305
Wire Wire Line
	1520 2505 1520 2595
$Comp
L Device:R_Small R22
U 1 1 5C0EB1A7
P 1520 2405
F 0 "R22" H 1579 2451 50  0000 L CNN
F 1 "1K" H 1579 2360 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 1520 2405 50  0001 C CNN
F 3 "~" H 1520 2405 50  0001 C CNN
	1    1520 2405
	1    0    0    -1  
$EndComp
Wire Wire Line
	1505 3450 1505 3490
$Comp
L Device:R_Small R40
U 1 1 5C0F58DE
P 1530 4795
F 0 "R40" H 1589 4841 50  0000 L CNN
F 1 "1K" H 1589 4750 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 1530 4795 50  0001 C CNN
F 3 "~" H 1530 4795 50  0001 C CNN
	1    1530 4795
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R48
U 1 1 5C0FA994
P 2810 6655
F 0 "R48" H 2869 6701 50  0000 L CNN
F 1 "1K" H 2869 6610 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2810 6655 50  0001 C CNN
F 3 "~" H 2810 6655 50  0001 C CNN
	1    2810 6655
	1    0    0    -1  
$EndComp
Wire Wire Line
	1505 3690 1505 3760
Wire Wire Line
	1530 4645 1530 4695
Wire Wire Line
	1530 4895 1530 4980
Wire Wire Line
	1505 5900 1505 5930
Wire Wire Line
	1505 6130 1505 6210
Wire Wire Line
	2810 6515 2810 6555
$EndSCHEMATC
