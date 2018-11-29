EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
L allcolours-rescue:C-device-allcolours-rescue C46
U 1 1 5BAC4611
P 2050 2475
F 0 "C46" H 2075 2575 50  0000 L CNN
F 1 "1N" H 2075 2375 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2088 2325 50  0001 C CNN
F 3 "" H 2050 2475 50  0000 C CNN
	1    2050 2475
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0117
U 1 1 5BAC462C
P 2600 3025
F 0 "#PWR0117" H 2600 2775 50  0001 C CNN
F 1 "GND" H 2600 2875 50  0000 C CNN
F 2 "" H 2600 3025 50  0000 C CNN
F 3 "" H 2600 3025 50  0000 C CNN
	1    2600 3025
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R64
U 1 1 5BAC4639
P 2600 2025
F 0 "R64" V 2680 2025 50  0000 C CNN
F 1 "33K" V 2600 2025 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2530 2025 50  0001 C CNN
F 3 "" H 2600 2025 50  0000 C CNN
	1    2600 2025
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device-allcolours-rescue D8
U 1 1 5BAC4640
P 2600 2375
F 0 "D8" H 2600 2275 50  0000 C CNN
F 1 "1n4148" H 2600 2525 50  0000 C CNN
F 2 "" H 2600 2375 50  0001 C CNN
F 3 "" H 2600 2375 50  0001 C CNN
	1    2600 2375
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR0116
U 1 1 5BAC465C
P 2600 1825
F 0 "#PWR0116" H 2600 1675 50  0001 C CNN
F 1 "+12V" H 2600 1965 50  0000 C CNN
F 2 "" H 2600 1825 50  0000 C CNN
F 3 "" H 2600 1825 50  0000 C CNN
	1    2600 1825
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q9
U 1 1 5BB3D775
P 2500 2775
F 0 "Q9" H 2691 2821 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2691 2730 50  0000 L CNN
F 2 "" H 2700 2875 50  0001 C CNN
F 3 "" H 2500 2775 50  0001 C CNN
	1    2500 2775
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1825 2600 1875
Wire Wire Line
	2600 2525 2600 2575
Wire Wire Line
	2600 2175 2600 2225
$Comp
L allcolours-rescue:C-device-allcolours-rescue C47
U 1 1 5BB5CF21
P 2950 2275
F 0 "C47" H 2975 2375 50  0000 L CNN
F 1 "1N" H 2975 2175 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2988 2125 50  0001 C CNN
F 3 "" H 2950 2275 50  0000 C CNN
	1    2950 2275
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0119
U 1 1 5BB5CF27
P 3500 2825
F 0 "#PWR0119" H 3500 2575 50  0001 C CNN
F 1 "GND" H 3500 2675 50  0000 C CNN
F 2 "" H 3500 2825 50  0000 C CNN
F 3 "" H 3500 2825 50  0000 C CNN
	1    3500 2825
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R65
U 1 1 5BB5CF2D
P 3500 1825
F 0 "R65" V 3580 1825 50  0000 C CNN
F 1 "33K" V 3500 1825 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3430 1825 50  0001 C CNN
F 3 "" H 3500 1825 50  0000 C CNN
	1    3500 1825
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device-allcolours-rescue D9
U 1 1 5BB5CF33
P 3500 2175
F 0 "D9" H 3500 2075 50  0000 C CNN
F 1 "1n4148" H 3500 2325 50  0000 C CNN
F 2 "" H 3500 2175 50  0001 C CNN
F 3 "" H 3500 2175 50  0001 C CNN
	1    3500 2175
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR0118
U 1 1 5BB5CF39
P 3500 1625
F 0 "#PWR0118" H 3500 1475 50  0001 C CNN
F 1 "+12V" H 3500 1765 50  0000 C CNN
F 2 "" H 3500 1625 50  0000 C CNN
F 3 "" H 3500 1625 50  0000 C CNN
	1    3500 1625
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q10
U 1 1 5BB5CF3F
P 3400 2575
F 0 "Q10" H 3591 2621 50  0000 L CNN
F 1 "Q_NPN_BEC" H 3591 2530 50  0000 L CNN
F 2 "" H 3600 2675 50  0001 C CNN
F 3 "" H 3400 2575 50  0001 C CNN
	1    3400 2575
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1625 3500 1675
Wire Wire Line
	3500 2325 3500 2375
Wire Wire Line
	3500 1975 3500 2025
$Comp
L allcolours-rescue:C-device-allcolours-rescue C48
U 1 1 5BB5D0F1
P 3800 1975
F 0 "C48" H 3825 2075 50  0000 L CNN
F 1 "1N" H 3825 1875 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3838 1825 50  0001 C CNN
F 3 "" H 3800 1975 50  0000 C CNN
	1    3800 1975
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0121
U 1 1 5BB5D0F8
P 4300 2575
F 0 "#PWR0121" H 4300 2325 50  0001 C CNN
F 1 "GND" H 4300 2425 50  0000 C CNN
F 2 "" H 4300 2575 50  0000 C CNN
F 3 "" H 4300 2575 50  0000 C CNN
	1    4300 2575
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R66
U 1 1 5BB5D0FE
P 4300 1575
F 0 "R66" V 4380 1575 50  0000 C CNN
F 1 "33K" V 4300 1575 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4230 1575 50  0001 C CNN
F 3 "" H 4300 1575 50  0000 C CNN
	1    4300 1575
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device-allcolours-rescue D10
U 1 1 5BB5D105
P 4300 1925
F 0 "D10" H 4300 1825 50  0000 C CNN
F 1 "1n4148" H 4300 2075 50  0000 C CNN
F 2 "" H 4300 1925 50  0001 C CNN
F 3 "" H 4300 1925 50  0001 C CNN
	1    4300 1925
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR0120
U 1 1 5BB5D10C
P 4300 1375
F 0 "#PWR0120" H 4300 1225 50  0001 C CNN
F 1 "+12V" H 4300 1515 50  0000 C CNN
F 2 "" H 4300 1375 50  0000 C CNN
F 3 "" H 4300 1375 50  0000 C CNN
	1    4300 1375
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q11
U 1 1 5BB5D112
P 4200 2325
F 0 "Q11" H 4391 2371 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4391 2280 50  0000 L CNN
F 2 "" H 4400 2425 50  0001 C CNN
F 3 "" H 4200 2325 50  0001 C CNN
	1    4200 2325
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 1375 4300 1425
Wire Wire Line
	4300 2075 4300 2125
Wire Wire Line
	4300 1725 4300 1775
Wire Wire Line
	3950 2325 4000 2325
$Comp
L allcolours-rescue:C-device-allcolours-rescue C51
U 1 1 5BB5D2A3
P 6100 1325
F 0 "C51" H 6125 1425 50  0000 L CNN
F 1 "1N" H 6125 1225 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6138 1175 50  0001 C CNN
F 3 "" H 6100 1325 50  0000 C CNN
	1    6100 1325
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0127
U 1 1 5BB5D2AA
P 6700 1925
F 0 "#PWR0127" H 6700 1675 50  0001 C CNN
F 1 "GND" H 6700 1775 50  0000 C CNN
F 2 "" H 6700 1925 50  0000 C CNN
F 3 "" H 6700 1925 50  0000 C CNN
	1    6700 1925
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R69
U 1 1 5BB5D2B0
P 6700 925
F 0 "R69" V 6780 925 50  0000 C CNN
F 1 "33K" V 6700 925 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6630 925 50  0001 C CNN
F 3 "" H 6700 925 50  0000 C CNN
	1    6700 925 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device-allcolours-rescue D13
U 1 1 5BB5D2B7
P 6700 1275
F 0 "D13" H 6700 1175 50  0000 C CNN
F 1 "1n4148" H 6700 1425 50  0000 C CNN
F 2 "" H 6700 1275 50  0001 C CNN
F 3 "" H 6700 1275 50  0001 C CNN
	1    6700 1275
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR0126
U 1 1 5BB5D2BE
P 6700 725
F 0 "#PWR0126" H 6700 575 50  0001 C CNN
F 1 "+12V" H 6700 865 50  0000 C CNN
F 2 "" H 6700 725 50  0000 C CNN
F 3 "" H 6700 725 50  0000 C CNN
	1    6700 725 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q14
U 1 1 5BB5D2C4
P 6600 1675
F 0 "Q14" H 6791 1721 50  0000 L CNN
F 1 "Q_NPN_BEC" H 6791 1630 50  0000 L CNN
F 2 "" H 6800 1775 50  0001 C CNN
F 3 "" H 6600 1675 50  0001 C CNN
	1    6600 1675
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 725  6700 775 
Wire Wire Line
	6700 1425 6700 1475
Wire Wire Line
	6700 1075 6700 1125
$Comp
L allcolours-rescue:C-device-allcolours-rescue C50
U 1 1 5BB5D4C7
P 5350 1675
F 0 "C50" H 5375 1775 50  0000 L CNN
F 1 "1N" H 5375 1575 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5388 1525 50  0001 C CNN
F 3 "" H 5350 1675 50  0000 C CNN
	1    5350 1675
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0125
U 1 1 5BB5D4CE
P 5850 2125
F 0 "#PWR0125" H 5850 1875 50  0001 C CNN
F 1 "GND" H 5850 1975 50  0000 C CNN
F 2 "" H 5850 2125 50  0000 C CNN
F 3 "" H 5850 2125 50  0000 C CNN
	1    5850 2125
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R68
U 1 1 5BB5D4D4
P 5850 1125
F 0 "R68" V 5930 1125 50  0000 C CNN
F 1 "33K" V 5850 1125 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5780 1125 50  0001 C CNN
F 3 "" H 5850 1125 50  0000 C CNN
	1    5850 1125
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device-allcolours-rescue D12
U 1 1 5BB5D4DB
P 5850 1475
F 0 "D12" H 5850 1375 50  0000 C CNN
F 1 "1n4148" H 5850 1625 50  0000 C CNN
F 2 "" H 5850 1475 50  0001 C CNN
F 3 "" H 5850 1475 50  0001 C CNN
	1    5850 1475
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR0124
U 1 1 5BB5D4E2
P 5850 925
F 0 "#PWR0124" H 5850 775 50  0001 C CNN
F 1 "+12V" H 5850 1065 50  0000 C CNN
F 2 "" H 5850 925 50  0000 C CNN
F 3 "" H 5850 925 50  0000 C CNN
	1    5850 925 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q13
U 1 1 5BB5D4E8
P 5750 1875
F 0 "Q13" H 5941 1921 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5941 1830 50  0000 L CNN
F 2 "" H 5950 1975 50  0001 C CNN
F 3 "" H 5750 1875 50  0001 C CNN
	1    5750 1875
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 925  5850 975 
Wire Wire Line
	5850 1625 5850 1675
Wire Wire Line
	5850 1275 5850 1325
$Comp
L allcolours-rescue:C-device-allcolours-rescue C49
U 1 1 5BB5D7CF
P 4650 1825
F 0 "C49" H 4675 1925 50  0000 L CNN
F 1 "1N" H 4675 1725 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4688 1675 50  0001 C CNN
F 3 "" H 4650 1825 50  0000 C CNN
	1    4650 1825
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0123
U 1 1 5BB5D7D6
P 5050 2325
F 0 "#PWR0123" H 5050 2075 50  0001 C CNN
F 1 "GND" H 5050 2175 50  0000 C CNN
F 2 "" H 5050 2325 50  0000 C CNN
F 3 "" H 5050 2325 50  0000 C CNN
	1    5050 2325
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R67
U 1 1 5BB5D7DC
P 5050 1325
F 0 "R67" V 5130 1325 50  0000 C CNN
F 1 "33K" V 5050 1325 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4980 1325 50  0001 C CNN
F 3 "" H 5050 1325 50  0000 C CNN
	1    5050 1325
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device-allcolours-rescue D11
U 1 1 5BB5D7E3
P 5050 1675
F 0 "D11" H 5050 1575 50  0000 C CNN
F 1 "1n4148" H 5050 1825 50  0000 C CNN
F 2 "" H 5050 1675 50  0001 C CNN
F 3 "" H 5050 1675 50  0001 C CNN
	1    5050 1675
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR0122
U 1 1 5BB5D7EA
P 5050 1125
F 0 "#PWR0122" H 5050 975 50  0001 C CNN
F 1 "+12V" H 5050 1265 50  0000 C CNN
F 2 "" H 5050 1125 50  0000 C CNN
F 3 "" H 5050 1125 50  0000 C CNN
	1    5050 1125
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q12
U 1 1 5BB5D7F0
P 4950 2075
F 0 "Q12" H 5141 2121 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5141 2030 50  0000 L CNN
F 2 "" H 5150 2175 50  0001 C CNN
F 3 "" H 4950 2075 50  0001 C CNN
	1    4950 2075
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 1125 5050 1175
Wire Wire Line
	5050 1825 5050 1875
Wire Wire Line
	5050 1475 5050 1525
Wire Wire Line
	4700 2075 4750 2075
$Comp
L allcolours-rescue:C-device-allcolours-rescue C45
U 1 1 5BB5DC4F
P 1200 3025
F 0 "C45" H 1225 3125 50  0000 L CNN
F 1 "1N" H 1225 2925 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1238 2875 50  0001 C CNN
F 3 "" H 1200 3025 50  0000 C CNN
	1    1200 3025
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0115
U 1 1 5BB5DC56
P 1700 3275
F 0 "#PWR0115" H 1700 3025 50  0001 C CNN
F 1 "GND" H 1700 3125 50  0000 C CNN
F 2 "" H 1700 3275 50  0000 C CNN
F 3 "" H 1700 3275 50  0000 C CNN
	1    1700 3275
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R63
U 1 1 5BB5DC5C
P 1700 2275
F 0 "R63" V 1780 2275 50  0000 C CNN
F 1 "33K" V 1700 2275 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1630 2275 50  0001 C CNN
F 3 "" H 1700 2275 50  0000 C CNN
	1    1700 2275
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:D-device-allcolours-rescue D7
U 1 1 5BB5DC63
P 1700 2625
F 0 "D7" H 1700 2525 50  0000 C CNN
F 1 "1n4148" H 1700 2775 50  0000 C CNN
F 2 "" H 1700 2625 50  0001 C CNN
F 3 "" H 1700 2625 50  0001 C CNN
	1    1700 2625
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR0114
U 1 1 5BB5DC6A
P 1700 2075
F 0 "#PWR0114" H 1700 1925 50  0001 C CNN
F 1 "+12V" H 1700 2215 50  0000 C CNN
F 2 "" H 1700 2075 50  0000 C CNN
F 3 "" H 1700 2075 50  0000 C CNN
	1    1700 2075
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q8
U 1 1 5BB5DC70
P 1600 3025
F 0 "Q8" H 1791 3071 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1791 2980 50  0000 L CNN
F 2 "" H 1800 3125 50  0001 C CNN
F 3 "" H 1600 3025 50  0001 C CNN
	1    1600 3025
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 2075 1700 2125
Wire Wire Line
	1700 2775 1700 2825
Wire Wire Line
	1700 2425 1700 2475
Wire Wire Line
	1350 3025 1400 3025
Wire Wire Line
	7600 3775 1050 3775
Wire Wire Line
	1050 3775 1050 3025
Text Notes 7725 6875 0    157  ~ 0
mmbt or 2n2222\n
Wire Wire Line
	1700 2475 1850 2475
Connection ~ 1700 2475
Wire Wire Line
	2200 2475 2200 2775
Wire Wire Line
	2200 2775 2300 2775
Wire Wire Line
	3100 2275 3100 2575
Wire Wire Line
	3100 2575 3200 2575
Wire Wire Line
	3500 1975 3625 1975
Connection ~ 3500 1975
Wire Wire Line
	3950 1975 3950 2325
Wire Wire Line
	4800 1825 4800 2025
Wire Wire Line
	4800 2025 4700 2025
Wire Wire Line
	4700 2025 4700 2075
Wire Wire Line
	5500 1675 5500 1875
Wire Wire Line
	5500 1875 5550 1875
Wire Wire Line
	6700 1125 7000 1125
Wire Wire Line
	7600 1125 7600 3775
Connection ~ 6700 1125
Wire Wire Line
	5850 1325 5950 1325
Connection ~ 5850 1325
Wire Wire Line
	6250 1325 6250 1675
Wire Wire Line
	6250 1675 6400 1675
Wire Wire Line
	1700 3225 1700 3275
Wire Wire Line
	2600 2975 2600 3025
Wire Wire Line
	3500 2775 3500 2825
Wire Wire Line
	4300 2525 4300 2575
Wire Wire Line
	5050 2275 5050 2325
Wire Wire Line
	5850 2075 5850 2125
Wire Wire Line
	6700 1875 6700 1925
Wire Wire Line
	4300 1775 4475 1775
Wire Wire Line
	4500 1775 4500 1825
Connection ~ 4300 1775
Wire Wire Line
	2600 2225 2750 2225
Wire Wire Line
	2800 2225 2800 2275
Connection ~ 2600 2225
Wire Wire Line
	5050 1475 5200 1475
Wire Wire Line
	5200 1475 5200 1675
Connection ~ 5050 1475
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C087E53
P 1850 2275
AR Path="/5C087E53" Ref="J?"  Part="1" 
AR Path="/5BAC374C/5C087E53" Ref="J?"  Part="1" 
F 0 "J?" H 1930 2317 50  0000 L CNN
F 1 "ouro" H 1930 2226 50  0000 L CNN
F 2 "" H 1850 2275 50  0001 C CNN
F 3 "~" H 1850 2275 50  0001 C CNN
	1    1850 2275
	0    -1   -1   0   
$EndComp
Connection ~ 1850 2475
Wire Wire Line
	1850 2475 1900 2475
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C08EE14
P 2750 2025
AR Path="/5C08EE14" Ref="J?"  Part="1" 
AR Path="/5BAC374C/5C08EE14" Ref="J?"  Part="1" 
F 0 "J?" H 2830 2067 50  0000 L CNN
F 1 "ouro" H 2830 1976 50  0000 L CNN
F 2 "" H 2750 2025 50  0001 C CNN
F 3 "~" H 2750 2025 50  0001 C CNN
	1    2750 2025
	0    -1   -1   0   
$EndComp
Connection ~ 2750 2225
Wire Wire Line
	2750 2225 2800 2225
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C08EEAE
P 3625 1775
AR Path="/5C08EEAE" Ref="J?"  Part="1" 
AR Path="/5BAC374C/5C08EEAE" Ref="J?"  Part="1" 
F 0 "J?" H 3705 1817 50  0000 L CNN
F 1 "ouro" H 3705 1726 50  0000 L CNN
F 2 "" H 3625 1775 50  0001 C CNN
F 3 "~" H 3625 1775 50  0001 C CNN
	1    3625 1775
	0    -1   -1   0   
$EndComp
Connection ~ 3625 1975
Wire Wire Line
	3625 1975 3650 1975
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C08EF46
P 4475 1575
AR Path="/5C08EF46" Ref="J?"  Part="1" 
AR Path="/5BAC374C/5C08EF46" Ref="J?"  Part="1" 
F 0 "J?" H 4555 1617 50  0000 L CNN
F 1 "ouro" H 4555 1526 50  0000 L CNN
F 2 "" H 4475 1575 50  0001 C CNN
F 3 "~" H 4475 1575 50  0001 C CNN
	1    4475 1575
	0    -1   -1   0   
$EndComp
Connection ~ 4475 1775
Wire Wire Line
	4475 1775 4500 1775
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C08F708
P 5200 1275
AR Path="/5C08F708" Ref="J?"  Part="1" 
AR Path="/5BAC374C/5C08F708" Ref="J?"  Part="1" 
F 0 "J?" H 5280 1317 50  0000 L CNN
F 1 "ouro" H 5280 1226 50  0000 L CNN
F 2 "" H 5200 1275 50  0001 C CNN
F 3 "~" H 5200 1275 50  0001 C CNN
	1    5200 1275
	0    -1   -1   0   
$EndComp
Connection ~ 5200 1475
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C0902B4
P 5950 1125
AR Path="/5C0902B4" Ref="J?"  Part="1" 
AR Path="/5BAC374C/5C0902B4" Ref="J?"  Part="1" 
F 0 "J?" H 6030 1167 50  0000 L CNN
F 1 "ouro" H 6030 1076 50  0000 L CNN
F 2 "" H 5950 1125 50  0001 C CNN
F 3 "~" H 5950 1125 50  0001 C CNN
	1    5950 1125
	0    -1   -1   0   
$EndComp
Connection ~ 5950 1325
$Comp
L allcolours-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C090338
P 7000 925
AR Path="/5C090338" Ref="J?"  Part="1" 
AR Path="/5BAC374C/5C090338" Ref="J?"  Part="1" 
F 0 "J?" H 7080 967 50  0000 L CNN
F 1 "ouro" H 7080 876 50  0000 L CNN
F 2 "" H 7000 925 50  0001 C CNN
F 3 "~" H 7000 925 50  0001 C CNN
	1    7000 925 
	0    -1   -1   0   
$EndComp
Connection ~ 7000 1125
Wire Wire Line
	7000 1125 7600 1125
$EndSCHEMATC
