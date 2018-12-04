EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 1725 1025 0    157  ~ 0
revealed op amp comparator 
Text Notes 1800 1275 0    79   ~ 0
MMBT3906 is BEC
$Comp
L Device:Q_PNP_BEC Q32
U 1 1 5C04F8CC
P 2025 2450
F 0 "Q32" H 2216 2404 50  0000 L CNN
F 1 "Q_PNP_BEC" H 2216 2495 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2225 2550 50  0001 C CNN
F 3 "~" H 2025 2450 50  0001 C CNN
	1    2025 2450
	-1   0    0    1   
$EndComp
$Comp
L Device:Q_PNP_BEC Q35
U 1 1 5C0504D8
P 2525 2450
F 0 "Q35" H 2716 2404 50  0000 L CNN
F 1 "Q_PNP_BEC" H 2716 2495 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2725 2550 50  0001 C CNN
F 3 "~" H 2525 2450 50  0001 C CNN
	1    2525 2450
	1    0    0    1   
$EndComp
$Comp
L Device:Q_PNP_BEC Q39
U 1 1 5C05061C
P 4450 2450
F 0 "Q39" H 4641 2404 50  0000 L CNN
F 1 "Q_PNP_BEC" H 4641 2495 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4650 2550 50  0001 C CNN
F 3 "~" H 4450 2450 50  0001 C CNN
	1    4450 2450
	1    0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C051724
P 1925 1975
AR Path="/5C051724" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C051724" Ref="R?"  Part="1" 
AR Path="/5C04EB62/5C051724" Ref="R80"  Part="1" 
F 0 "R80" V 2005 1975 50  0000 C CNN
F 1 "4K7" V 1925 1975 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1855 1975 50  0001 C CNN
F 3 "" H 1925 1975 50  0000 C CNN
	1    1925 1975
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C05194B
P 2375 3750
AR Path="/5C05194B" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C05194B" Ref="Q?"  Part="1" 
AR Path="/5C04EB62/5C05194B" Ref="Q34"  Part="1" 
F 0 "Q34" H 2566 3796 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2566 3705 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2575 3850 50  0001 C CNN
F 3 "" H 2375 3750 50  0001 C CNN
	1    2375 3750
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0519C3
P 4275 3250
AR Path="/5C0519C3" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C0519C3" Ref="Q?"  Part="1" 
AR Path="/5C04EB62/5C0519C3" Ref="Q38"  Part="1" 
F 0 "Q38" H 4466 3296 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4466 3205 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4475 3350 50  0001 C CNN
F 3 "" H 4275 3250 50  0001 C CNN
	1    4275 3250
	-1   0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C051B76
P 3200 4125
AR Path="/5C051B76" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C051B76" Ref="R?"  Part="1" 
AR Path="/5C04EB62/5C051B76" Ref="R81"  Part="1" 
F 0 "R81" V 3280 4125 50  0000 C CNN
F 1 "10K" V 3200 4125 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3130 4125 50  0001 C CNN
F 3 "" H 3200 4125 50  0000 C CNN
	1    3200 4125
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C051DE4
P 3200 4400
AR Path="/5C051DE4" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C051DE4" Ref="#PWR?"  Part="1" 
AR Path="/5C04EB62/5C051DE4" Ref="#PWR0145"  Part="1" 
F 0 "#PWR0145" H 3200 4150 50  0001 C CNN
F 1 "GND" H 3200 4250 50  0000 C CNN
F 2 "" H 3200 4400 50  0000 C CNN
F 3 "" H 3200 4400 50  0000 C CNN
	1    3200 4400
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C051E03
P 3825 2775
AR Path="/5C051E03" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C051E03" Ref="#PWR?"  Part="1" 
AR Path="/5C04EB62/5C051E03" Ref="#PWR0146"  Part="1" 
F 0 "#PWR0146" H 3825 2525 50  0001 C CNN
F 1 "GND" H 3825 2625 50  0000 C CNN
F 2 "" H 3825 2775 50  0000 C CNN
F 3 "" H 3825 2775 50  0000 C CNN
	1    3825 2775
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C051EF3
P 3250 1975
AR Path="/5C051EF3" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C051EF3" Ref="R?"  Part="1" 
AR Path="/5C04EB62/5C051EF3" Ref="R82"  Part="1" 
F 0 "R82" V 3330 1975 50  0000 C CNN
F 1 "820R" V 3250 1975 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3180 1975 50  0001 C CNN
F 3 "" H 3250 1975 50  0000 C CNN
	1    3250 1975
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5C051F6B
P 4550 1975
AR Path="/5C051F6B" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C051F6B" Ref="R?"  Part="1" 
AR Path="/5C04EB62/5C051F6B" Ref="R83"  Part="1" 
F 0 "R83" V 4630 1975 50  0000 C CNN
F 1 "4K7" V 4550 1975 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4480 1975 50  0001 C CNN
F 3 "" H 4550 1975 50  0000 C CNN
	1    4550 1975
	1    0    0    -1  
$EndComp
Wire Wire Line
	1925 1825 2425 1825
Wire Wire Line
	3250 1825 4550 1825
Connection ~ 3250 1825
$Comp
L allcolours_analogue-rescue:+12V-power #PWR0144
U 1 1 5C05207B
P 2425 1825
F 0 "#PWR0144" H 2425 1675 50  0001 C CNN
F 1 "+12V-power" H 2440 1998 50  0000 C CNN
F 2 "" H 2425 1825 50  0001 C CNN
F 3 "" H 2425 1825 50  0001 C CNN
	1    2425 1825
	1    0    0    -1  
$EndComp
Connection ~ 2425 1825
Wire Wire Line
	2425 1825 3250 1825
Wire Wire Line
	3250 2125 3250 2250
Wire Wire Line
	3250 2250 3825 2250
Wire Wire Line
	3825 2650 3825 2775
Wire Wire Line
	1925 2125 1925 2250
Wire Wire Line
	2275 2650 1925 2650
Wire Wire Line
	2275 2450 2275 2650
Wire Wire Line
	2225 2450 2275 2450
Wire Wire Line
	2325 2450 2275 2450
Connection ~ 2275 2450
$Comp
L Device:Q_PNP_BEC Q36
U 1 1 5C050616
P 3925 2450
F 0 "Q36" H 4116 2404 50  0000 L CNN
F 1 "Q_PNP_BEC" H 4116 2495 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4125 2550 50  0001 C CNN
F 3 "~" H 3925 2450 50  0001 C CNN
	1    3925 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	4125 2450 4175 2450
Wire Wire Line
	4175 3050 4175 3025
Connection ~ 4175 2450
Wire Wire Line
	4175 2450 4250 2450
Wire Wire Line
	4175 2675 4550 2675
Wire Wire Line
	4550 2675 4550 2650
Connection ~ 4175 2675
Wire Wire Line
	4175 2675 4175 2450
Wire Wire Line
	2275 2650 2275 3000
Connection ~ 2275 2650
Wire Wire Line
	2625 2250 3250 2250
Connection ~ 3250 2250
Wire Wire Line
	2625 2950 4575 2950
Wire Wire Line
	2275 3000 2475 3000
Wire Wire Line
	2475 3000 2475 3550
Connection ~ 2275 3000
Wire Wire Line
	2275 3000 2275 3050
Wire Wire Line
	2275 3575 2175 3575
Wire Wire Line
	2175 3575 2175 3750
Wire Wire Line
	2275 3450 2275 3575
Wire Wire Line
	2475 3950 3200 3950
Wire Wire Line
	3200 3950 3200 3975
Wire Wire Line
	3200 3950 4025 3950
Wire Wire Line
	4025 3950 4025 3875
Connection ~ 3200 3950
Wire Wire Line
	1975 3250 1700 3250
Wire Wire Line
	4475 3250 4700 3250
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C056851
P 2175 3250
AR Path="/5C056851" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C056851" Ref="Q?"  Part="1" 
AR Path="/5C04EB62/5C056851" Ref="Q33"  Part="1" 
F 0 "Q33" H 2366 3296 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2366 3205 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2375 3350 50  0001 C CNN
F 3 "" H 2175 3250 50  0001 C CNN
	1    2175 3250
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0568AB
P 4125 3675
AR Path="/5C0568AB" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C0568AB" Ref="Q?"  Part="1" 
AR Path="/5C04EB62/5C0568AB" Ref="Q37"  Part="1" 
F 0 "Q37" H 4316 3721 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4316 3630 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4325 3775 50  0001 C CNN
F 3 "" H 4125 3675 50  0001 C CNN
	1    4125 3675
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3200 4275 3200 4400
Wire Wire Line
	4175 3450 4325 3450
Wire Wire Line
	4325 3450 4325 3675
Wire Wire Line
	4025 3475 4025 3025
Wire Wire Line
	4025 3025 4175 3025
Connection ~ 4175 3025
Wire Wire Line
	4175 3025 4175 2675
Wire Wire Line
	4550 2125 4550 2250
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C0129EF
P 4900 3250
AR Path="/5C0129EF" Ref="J?"  Part="1" 
AR Path="/5C04EB62/5C0129EF" Ref="J51"  Part="1" 
F 0 "J51" H 4765 3170 50  0000 C CNN
F 1 "opcompin2" H 5190 3260 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4900 3250 50  0001 C CNN
F 3 "" H 4900 3250 50  0001 C CNN
	1    4900 3250
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C013D6B
P 4775 2950
AR Path="/5C013D6B" Ref="J?"  Part="1" 
AR Path="/5C04EB62/5C013D6B" Ref="J50"  Part="1" 
F 0 "J50" H 4660 2865 50  0000 C CNN
F 1 "opcompout" H 5060 2955 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4775 2950 50  0001 C CNN
F 3 "" H 4775 2950 50  0001 C CNN
	1    4775 2950
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C013DDB
P 1500 3250
AR Path="/5C013DDB" Ref="J?"  Part="1" 
AR Path="/5C04EB62/5C013DDB" Ref="J49"  Part="1" 
F 0 "J49" H 1420 3025 50  0000 C CNN
F 1 "opcompin1" H 1420 3116 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 1500 3250 50  0001 C CNN
F 3 "" H 1500 3250 50  0001 C CNN
	1    1500 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	2625 2650 2625 2950
$EndSCHEMATC
