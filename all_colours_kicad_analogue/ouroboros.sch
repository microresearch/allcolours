EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 9
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
L allcolours_analogue-rescue:Q_NPN_BEC-device Q2
U 1 1 5BB5DC70
P 1575 2825
F 0 "Q2" H 1766 2871 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1766 2780 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1775 2925 50  0001 C CNN
F 3 "" H 1575 2825 50  0001 C CNN
	1    1575 2825
	1    0    0    -1  
$EndComp
Text Notes 4000 300  0    197  ~ 0
mmbt or 2n2222\n
Text Notes 6375 3250 0    276  ~ 0
closed ouroboros
Text Notes 6025 2575 0    60   ~ 0
revealed traces as pads
Text Notes 1450 925  0    197  ~ 0
0-12V ins
Wire Wire Line
	5925 3575 5925 1125
Wire Wire Line
	5825 1125 5925 1125
Wire Wire Line
	5475 1675 5525 1675
Wire Wire Line
	5475 1475 5475 1675
Wire Wire Line
	4675 1825 4675 1875
Wire Wire Line
	4775 1825 4675 1825
Wire Wire Line
	4775 1625 4775 1825
Wire Wire Line
	3925 1775 3925 2125
Wire Wire Line
	3475 1775 3600 1775
Wire Wire Line
	3075 2375 3175 2375
Wire Wire Line
	3075 2075 3075 2375
Wire Wire Line
	2175 2575 2275 2575
Wire Wire Line
	2175 2275 2175 2575
Wire Wire Line
	1675 2275 1850 2275
Wire Wire Line
	1025 3575 1025 2825
Wire Wire Line
	1325 2825 1375 2825
Wire Wire Line
	1675 2225 1675 2275
Wire Wire Line
	1675 2575 1675 2625
Wire Wire Line
	1675 1875 1675 1925
$Comp
L allcolours_analogue-rescue:+12V-power #PWR08
U 1 1 5BB5DC6A
P 1675 1875
F 0 "#PWR08" H 1675 1725 50  0001 C CNN
F 1 "+12V" H 1675 2015 50  0000 C CNN
F 2 "" H 1675 1875 50  0000 C CNN
F 3 "" H 1675 1875 50  0000 C CNN
	1    1675 1875
	1    0    0    -1  
$EndComp
Connection ~ 1675 2275
$Comp
L allcolours_analogue-rescue:D-device D2
U 1 1 5BB5DC63
P 1675 2425
F 0 "D2" H 1675 2325 50  0000 C CNN
F 1 "1n4148" H 1675 2575 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 1675 2425 50  0001 C CNN
F 3 "" H 1675 2425 50  0001 C CNN
	1    1675 2425
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R4
U 1 1 5BB5DC5C
P 1675 2075
F 0 "R4" V 1755 2075 50  0000 C CNN
F 1 "33K" V 1675 2075 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1605 2075 50  0001 C CNN
F 3 "" H 1675 2075 50  0000 C CNN
	1    1675 2075
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR09
U 1 1 5BB5DC56
P 1675 3075
F 0 "#PWR09" H 1675 2825 50  0001 C CNN
F 1 "GND" H 1675 2925 50  0000 C CNN
F 2 "" H 1675 3075 50  0000 C CNN
F 3 "" H 1675 3075 50  0000 C CNN
	1    1675 3075
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C4
U 1 1 5BB5DC4F
P 1175 2825
F 0 "C4" H 1200 2925 50  0000 L CNN
F 1 "1N" H 1200 2725 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1213 2675 50  0001 C CNN
F 3 "" H 1175 2825 50  0000 C CNN
	1    1175 2825
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4675 1875 4725 1875
Wire Wire Line
	5025 1275 5025 1300
Wire Wire Line
	5025 1625 5025 1675
Wire Wire Line
	5025 925  5025 975 
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q10
U 1 1 5BB5D7F0
P 4925 1875
F 0 "Q10" H 5116 1921 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5116 1830 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 5125 1975 50  0001 C CNN
F 3 "" H 4925 1875 50  0001 C CNN
	1    4925 1875
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR024
U 1 1 5BB5D7EA
P 5025 925
F 0 "#PWR024" H 5025 775 50  0001 C CNN
F 1 "+12V" H 5025 1065 50  0000 C CNN
F 2 "" H 5025 925 50  0000 C CNN
F 3 "" H 5025 925 50  0000 C CNN
	1    5025 925 
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D10
U 1 1 5BB5D7E3
P 5025 1475
F 0 "D10" H 5025 1375 50  0000 C CNN
F 1 "1n4148" H 5025 1625 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 5025 1475 50  0001 C CNN
F 3 "" H 5025 1475 50  0001 C CNN
	1    5025 1475
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R8
U 1 1 5BB5D7DC
P 5025 1125
F 0 "R8" V 5105 1125 50  0000 C CNN
F 1 "33K" V 5025 1125 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4955 1125 50  0001 C CNN
F 3 "" H 5025 1125 50  0000 C CNN
	1    5025 1125
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR025
U 1 1 5BB5D7D6
P 5025 2125
F 0 "#PWR025" H 5025 1875 50  0001 C CNN
F 1 "GND" H 5025 1975 50  0000 C CNN
F 2 "" H 5025 2125 50  0000 C CNN
F 3 "" H 5025 2125 50  0000 C CNN
	1    5025 2125
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C16
U 1 1 5BB5D7CF
P 4625 1625
F 0 "C16" H 4650 1725 50  0000 L CNN
F 1 "1N" H 4650 1525 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4663 1475 50  0001 C CNN
F 3 "" H 4625 1625 50  0000 C CNN
	1    4625 1625
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5825 1075 5825 1125
Wire Wire Line
	5825 1425 5825 1475
Wire Wire Line
	5825 725  5825 775 
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q12
U 1 1 5BB5D4E8
P 5725 1675
F 0 "Q12" H 5916 1721 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5916 1630 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 5925 1775 50  0001 C CNN
F 3 "" H 5725 1675 50  0001 C CNN
	1    5725 1675
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR028
U 1 1 5BB5D4E2
P 5825 725
F 0 "#PWR028" H 5825 575 50  0001 C CNN
F 1 "+12V" H 5825 865 50  0000 C CNN
F 2 "" H 5825 725 50  0000 C CNN
F 3 "" H 5825 725 50  0000 C CNN
	1    5825 725 
	1    0    0    -1  
$EndComp
Connection ~ 5825 1125
$Comp
L allcolours_analogue-rescue:D-device D12
U 1 1 5BB5D4DB
P 5825 1275
F 0 "D12" H 5825 1175 50  0000 C CNN
F 1 "1n4148" H 5825 1425 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 5825 1275 50  0001 C CNN
F 3 "" H 5825 1275 50  0001 C CNN
	1    5825 1275
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R9
U 1 1 5BB5D4D4
P 5825 925
F 0 "R9" V 5905 925 50  0000 C CNN
F 1 "33K" V 5825 925 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5755 925 50  0001 C CNN
F 3 "" H 5825 925 50  0000 C CNN
	1    5825 925 
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR029
U 1 1 5BB5D4CE
P 5825 1925
F 0 "#PWR029" H 5825 1675 50  0001 C CNN
F 1 "GND" H 5825 1775 50  0000 C CNN
F 2 "" H 5825 1925 50  0000 C CNN
F 3 "" H 5825 1925 50  0000 C CNN
	1    5825 1925
	1    0    0    -1  
$EndComp
Wire Wire Line
	3925 2125 3975 2125
Wire Wire Line
	4275 1525 4275 1550
Wire Wire Line
	4275 1875 4275 1925
Wire Wire Line
	4275 1175 4275 1225
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q8
U 1 1 5BB5D112
P 4175 2125
F 0 "Q8" H 4366 2171 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4366 2080 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4375 2225 50  0001 C CNN
F 3 "" H 4175 2125 50  0001 C CNN
	1    4175 2125
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR020
U 1 1 5BB5D10C
P 4275 1175
F 0 "#PWR020" H 4275 1025 50  0001 C CNN
F 1 "+12V" H 4275 1315 50  0000 C CNN
F 2 "" H 4275 1175 50  0000 C CNN
F 3 "" H 4275 1175 50  0000 C CNN
	1    4275 1175
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D8
U 1 1 5BB5D105
P 4275 1725
F 0 "D8" H 4275 1625 50  0000 C CNN
F 1 "1n4148" H 4275 1875 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 4275 1725 50  0001 C CNN
F 3 "" H 4275 1725 50  0001 C CNN
	1    4275 1725
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R7
U 1 1 5BB5D0FE
P 4275 1375
F 0 "R7" V 4355 1375 50  0000 C CNN
F 1 "33K" V 4275 1375 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4205 1375 50  0001 C CNN
F 3 "" H 4275 1375 50  0000 C CNN
	1    4275 1375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR021
U 1 1 5BB5D0F8
P 4275 2375
F 0 "#PWR021" H 4275 2125 50  0001 C CNN
F 1 "GND" H 4275 2225 50  0000 C CNN
F 2 "" H 4275 2375 50  0000 C CNN
F 3 "" H 4275 2375 50  0000 C CNN
	1    4275 2375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C10
U 1 1 5BB5D0F1
P 3775 1775
F 0 "C10" H 3800 1875 50  0000 L CNN
F 1 "1N" H 3800 1675 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3813 1625 50  0001 C CNN
F 3 "" H 3775 1775 50  0000 C CNN
	1    3775 1775
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3475 1775 3475 1825
Wire Wire Line
	3475 2125 3475 2175
Wire Wire Line
	3475 1425 3475 1475
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q6
U 1 1 5BB5CF3F
P 3375 2375
F 0 "Q6" H 3566 2421 50  0000 L CNN
F 1 "Q_NPN_BEC" H 3566 2330 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3575 2475 50  0001 C CNN
F 3 "" H 3375 2375 50  0001 C CNN
	1    3375 2375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR016
U 1 1 5BB5CF39
P 3475 1425
F 0 "#PWR016" H 3475 1275 50  0001 C CNN
F 1 "+12V" H 3475 1565 50  0000 C CNN
F 2 "" H 3475 1425 50  0000 C CNN
F 3 "" H 3475 1425 50  0000 C CNN
	1    3475 1425
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D6
U 1 1 5BB5CF33
P 3475 1975
F 0 "D6" H 3475 1875 50  0000 C CNN
F 1 "1n4148" H 3475 2125 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 3475 1975 50  0001 C CNN
F 3 "" H 3475 1975 50  0001 C CNN
	1    3475 1975
	0    -1   -1   0   
$EndComp
Connection ~ 3475 1775
$Comp
L allcolours_analogue-rescue:R-device R6
U 1 1 5BB5CF2D
P 3475 1625
F 0 "R6" V 3555 1625 50  0000 C CNN
F 1 "33K" V 3475 1625 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3405 1625 50  0001 C CNN
F 3 "" H 3475 1625 50  0000 C CNN
	1    3475 1625
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR017
U 1 1 5BB5CF27
P 3475 2625
F 0 "#PWR017" H 3475 2375 50  0001 C CNN
F 1 "GND" H 3475 2475 50  0000 C CNN
F 2 "" H 3475 2625 50  0000 C CNN
F 3 "" H 3475 2625 50  0000 C CNN
	1    3475 2625
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C8
U 1 1 5BB5CF21
P 2925 2075
F 0 "C8" H 2950 2175 50  0000 L CNN
F 1 "1N" H 2950 1975 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2963 1925 50  0001 C CNN
F 3 "" H 2925 2075 50  0000 C CNN
	1    2925 2075
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2575 1975 2575 1995
Wire Wire Line
	2575 2325 2575 2375
Wire Wire Line
	2575 1625 2575 1675
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q4
U 1 1 5BB3D775
P 2475 2575
F 0 "Q4" H 2666 2621 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2666 2530 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2675 2675 50  0001 C CNN
F 3 "" H 2475 2575 50  0001 C CNN
	1    2475 2575
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR012
U 1 1 5BAC465C
P 2575 1625
F 0 "#PWR012" H 2575 1475 50  0001 C CNN
F 1 "+12V" H 2575 1765 50  0000 C CNN
F 2 "" H 2575 1625 50  0000 C CNN
F 3 "" H 2575 1625 50  0000 C CNN
	1    2575 1625
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D4
U 1 1 5BAC4640
P 2575 2175
F 0 "D4" H 2575 2075 50  0000 C CNN
F 1 "1n4148" H 2575 2325 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 2575 2175 50  0001 C CNN
F 3 "" H 2575 2175 50  0001 C CNN
	1    2575 2175
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R5
U 1 1 5BAC4639
P 2575 1825
F 0 "R5" V 2655 1825 50  0000 C CNN
F 1 "33K" V 2575 1825 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2505 1825 50  0001 C CNN
F 3 "" H 2575 1825 50  0000 C CNN
	1    2575 1825
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR013
U 1 1 5BAC462C
P 2575 2825
F 0 "#PWR013" H 2575 2575 50  0001 C CNN
F 1 "GND" H 2575 2675 50  0000 C CNN
F 2 "" H 2575 2825 50  0000 C CNN
F 3 "" H 2575 2825 50  0000 C CNN
	1    2575 2825
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C6
U 1 1 5BAC4611
P 2025 2275
F 0 "C6" H 2050 2375 50  0000 L CNN
F 1 "1N" H 2050 2175 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2063 2125 50  0001 C CNN
F 3 "" H 2025 2275 50  0000 C CNN
	1    2025 2275
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1025 3575 5925 3575
Wire Wire Line
	1675 3075 1675 3025
Wire Wire Line
	2575 2775 2575 2825
Wire Wire Line
	3475 2575 3475 2625
Wire Wire Line
	4275 2325 4275 2375
Wire Wire Line
	5025 2075 5025 2125
Wire Wire Line
	5825 1875 5825 1925
Wire Wire Line
	2575 1995 2775 1995
Wire Wire Line
	2775 1995 2775 2000
Connection ~ 2575 1995
Wire Wire Line
	2575 1995 2575 2025
Wire Wire Line
	4275 1550 4425 1550
Wire Wire Line
	4475 1550 4475 1625
Connection ~ 4275 1550
Wire Wire Line
	4275 1550 4275 1575
$Comp
L allcolours_analogue-rescue:C-device C18
U 1 1 5BB5D4C7
P 5325 1475
F 0 "C18" H 5350 1575 50  0000 L CNN
F 1 "1N" H 5350 1375 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5363 1325 50  0001 C CNN
F 3 "" H 5325 1475 50  0000 C CNN
	1    5325 1475
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5175 1300 5025 1300
Wire Wire Line
	5175 1300 5175 1475
Connection ~ 5025 1300
Wire Wire Line
	5025 1300 5025 1325
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J3
U 1 1 5C01A3F3
P 1850 2075
F 0 "J3" V 1816 1987 50  0000 R CNN
F 1 "our" V 1725 1987 50  0000 R CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1850 2075 50  0001 C CNN
F 3 "" H 1850 2075 50  0001 C CNN
	1    1850 2075
	0    -1   -1   0   
$EndComp
Connection ~ 1850 2275
Wire Wire Line
	1850 2275 1875 2275
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J4
U 1 1 5C01D0D1
P 2775 1800
F 0 "J4" V 2741 1712 50  0000 R CNN
F 1 "our" V 2650 1712 50  0000 R CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 2775 1800 50  0001 C CNN
F 3 "" H 2775 1800 50  0001 C CNN
	1    2775 1800
	0    -1   -1   0   
$EndComp
Connection ~ 2775 2000
Wire Wire Line
	2775 2000 2775 2075
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J5
U 1 1 5C01D153
P 3600 1575
F 0 "J5" V 3566 1487 50  0000 R CNN
F 1 "our" V 3475 1487 50  0000 R CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 3600 1575 50  0001 C CNN
F 3 "" H 3600 1575 50  0001 C CNN
	1    3600 1575
	0    -1   -1   0   
$EndComp
Connection ~ 3600 1775
Wire Wire Line
	3600 1775 3625 1775
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J6
U 1 1 5C01D5DC
P 4425 1350
F 0 "J6" V 4391 1262 50  0000 R CNN
F 1 "our" V 4300 1262 50  0000 R CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4425 1350 50  0001 C CNN
F 3 "" H 4425 1350 50  0001 C CNN
	1    4425 1350
	0    -1   -1   0   
$EndComp
Connection ~ 4425 1550
Wire Wire Line
	4425 1550 4475 1550
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J8
U 1 1 5C01D658
P 5925 925
F 0 "J8" V 5891 837 50  0000 R CNN
F 1 "our" V 5800 837 50  0000 R CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5925 925 50  0001 C CNN
F 3 "" H 5925 925 50  0001 C CNN
	1    5925 925 
	0    -1   -1   0   
$EndComp
Connection ~ 5925 1125
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J7
U 1 1 5C01E0C5
P 5175 1100
F 0 "J7" V 5141 1012 50  0000 R CNN
F 1 "our" V 5050 1012 50  0000 R CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 5175 1100 50  0001 C CNN
F 3 "" H 5175 1100 50  0001 C CNN
	1    5175 1100
	0    -1   -1   0   
$EndComp
Connection ~ 5175 1300
Text Notes 4350 3475 0    197  ~ 0
bias?
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5C2585AF
P 1400 4100
F 0 "C?" H 1425 4200 50  0000 L CNN
F 1 "1N" H 1425 4000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1438 3950 50  0001 C CNN
F 3 "" H 1400 4100 50  0000 C CNN
	1    1400 4100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C25863A
P 1400 4300
F 0 "#PWR?" H 1400 4050 50  0001 C CNN
F 1 "GND" H 1400 4150 50  0000 C CNN
F 2 "" H 1400 4300 50  0000 C CNN
F 3 "" H 1400 4300 50  0000 C CNN
	1    1400 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 4250 1400 4300
Text Notes 1575 4250 0    197  ~ 0
delay for ouroboros\n
$EndSCHEMATC
