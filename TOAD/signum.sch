EESchema Schematic File Version 4
LIBS:filter-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 875  715  0    79   ~ 0
NLC style SIGNUM - 2 variants maybe
$Comp
L Amplifier_Operational:TL074 U?
U 1 1 5F871EA3
P 1965 2790
AR Path="/5ED966D6/5F871EA3" Ref="U?"  Part="1" 
AR Path="/5F86F8BD/5F871EA3" Ref="U?"  Part="1" 
F 0 "U?" H 1965 3157 50  0000 C CNN
F 1 "TL074" H 1965 3066 50  0000 C CNN
F 2 "" H 1915 2890 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2015 2990 50  0001 C CNN
	1    1965 2790
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 2 1 5F871EAA
P 1960 3360
AR Path="/5ED966D6/5F871EAA" Ref="U?"  Part="2" 
AR Path="/5F86F8BD/5F871EAA" Ref="U?"  Part="2" 
F 0 "U?" H 1960 3727 50  0000 C CNN
F 1 "TL074" H 1960 3636 50  0000 C CNN
F 2 "" H 1910 3460 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2010 3560 50  0001 C CNN
	2    1960 3360
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 3 1 5F871EB1
P 3610 1395
F 0 "U?" H 3610 1762 50  0000 C CNN
F 1 "TL074" H 3610 1671 50  0000 C CNN
F 2 "" H 3560 1495 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3660 1595 50  0001 C CNN
	3    3610 1395
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 4 1 5F871EB8
P 4500 1295
F 0 "U?" H 4500 1662 50  0000 C CNN
F 1 "TL074" H 4500 1571 50  0000 C CNN
F 2 "" H 4450 1395 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4550 1495 50  0001 C CNN
	4    4500 1295
	1    0    0    -1  
$EndComp
Wire Wire Line
	1665 2890 1595 2890
Wire Wire Line
	1595 2890 1595 2900
Wire Wire Line
	1595 3260 1660 3260
Wire Wire Line
	1490 2690 1490 3460
Wire Wire Line
	1490 3460 1595 3460
Wire Wire Line
	1490 2690 1665 2690
$Comp
L Device:R_Small R?
U 1 1 5F871ECC
P 1390 3460
AR Path="/5ED966D6/5F871ECC" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F871ECC" Ref="R?"  Part="1" 
F 0 "R?" V 1495 3430 50  0000 C CNN
F 1 "10k" V 1590 3470 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1390 3460 50  0001 C CNN
F 3 "~" H 1390 3460 50  0001 C CNN
	1    1390 3460
	0    1    1    0   
$EndComp
Connection ~ 1490 3460
$Comp
L Device:R_Small R?
U 1 1 5F871ED4
P 1595 3560
F 0 "R?" V 1700 3530 50  0000 C CNN
F 1 "100k" V 1520 3555 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1595 3560 50  0001 C CNN
F 3 "~" H 1595 3560 50  0001 C CNN
	1    1595 3560
	-1   0    0    1   
$EndComp
Connection ~ 1595 3460
Wire Wire Line
	1595 3460 1660 3460
$Comp
L power:GND #PWR?
U 1 1 5F871EDD
P 1595 3695
AR Path="/5ED966D6/5F871EDD" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F871EDD" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1595 3445 50  0001 C CNN
F 1 "GND" H 1600 3522 50  0000 C CNN
F 2 "" H 1595 3695 50  0001 C CNN
F 3 "" H 1595 3695 50  0001 C CNN
	1    1595 3695
	1    0    0    -1  
$EndComp
Wire Wire Line
	1595 3660 1595 3695
Wire Wire Line
	1290 3460 1225 3460
$Comp
L power:GND #PWR?
U 1 1 5F871EE5
P 1400 2900
F 0 "#PWR?" H 1400 2650 50  0001 C CNN
F 1 "GND" H 1405 2727 50  0000 C CNN
F 2 "" H 1400 2900 50  0001 C CNN
F 3 "" H 1400 2900 50  0001 C CNN
	1    1400 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 2900 1595 2900
Connection ~ 1595 2900
Wire Wire Line
	1595 2900 1595 3260
$Comp
L Device:R_Small R?
U 1 1 5F871EEE
P 1895 1350
F 0 "R?" V 1975 1345 50  0000 C CNN
F 1 "10k" V 1810 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1895 1350 50  0001 C CNN
F 3 "~" H 1895 1350 50  0001 C CNN
	1    1895 1350
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F871EF5
P 1895 1495
F 0 "R?" V 2000 1465 50  0000 C CNN
F 1 "10k" V 1925 1330 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1895 1495 50  0001 C CNN
F 3 "~" H 1895 1495 50  0001 C CNN
	1    1895 1495
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5F871EFC
P 2845 1350
F 0 "D?" H 2845 1566 50  0000 C CNN
F 1 "1N4148" H 2845 1475 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2845 1175 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2845 1350 50  0001 C CNN
	1    2845 1350
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5F871F03
P 2845 1495
F 0 "D?" H 2835 1685 50  0000 C CNN
F 1 "1N4148" H 2840 1610 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2845 1320 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2845 1495 50  0001 C CNN
	1    2845 1495
	-1   0    0    1   
$EndComp
Wire Wire Line
	1795 1350 1795 1415
Wire Wire Line
	1795 1415 1565 1415
Connection ~ 1795 1415
Wire Wire Line
	1795 1415 1795 1495
Text GLabel 1565 1415 0    50   Input ~ 0
IN1_1
Wire Wire Line
	2995 1350 2995 1495
$Comp
L Diode:1N4148 D?
U 1 1 5F871F10
P 2140 2130
F 0 "D?" V 2265 2255 50  0000 R CNN
F 1 "1N4148" V 2050 2595 50  0000 R CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2140 1955 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2140 2130 50  0001 C CNN
	1    2140 2130
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1995 1350 2445 1350
Wire Wire Line
	1995 1495 2140 1495
$Comp
L Diode:1N4148 D?
U 1 1 5F871F19
P 2020 2130
F 0 "D?" V 1890 2300 50  0000 R CNN
F 1 "1N4148" V 2005 2085 50  0000 R CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2020 1955 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2020 2130 50  0001 C CNN
	1    2020 2130
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F871F20
P 1895 1745
AR Path="/5ED966D6/5F871F20" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F871F20" Ref="R?"  Part="1" 
F 0 "R?" V 1975 1740 50  0000 C CNN
F 1 "10k" V 1810 1745 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1895 1745 50  0001 C CNN
F 3 "~" H 1895 1745 50  0001 C CNN
	1    1895 1745
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F871F27
P 1895 1890
F 0 "R?" V 2000 1860 50  0000 C CNN
F 1 "10k" V 1925 1725 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1895 1890 50  0001 C CNN
F 3 "~" H 1895 1890 50  0001 C CNN
	1    1895 1890
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5F871F2E
P 2845 1745
F 0 "D?" H 2845 1961 50  0000 C CNN
F 1 "1N4148" H 3090 1810 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2845 1570 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2845 1745 50  0001 C CNN
	1    2845 1745
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5F871F35
P 2845 1890
F 0 "D?" H 2835 2080 50  0000 C CNN
F 1 "1N4148" H 2840 2005 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2845 1715 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2845 1890 50  0001 C CNN
	1    2845 1890
	-1   0    0    1   
$EndComp
Wire Wire Line
	1795 1745 1795 1810
Wire Wire Line
	1795 1810 1565 1810
Connection ~ 1795 1810
Wire Wire Line
	1795 1810 1795 1890
Text GLabel 1565 1810 0    50   Input ~ 0
IN2_1
Wire Wire Line
	2995 1745 2995 1890
Wire Wire Line
	1995 1745 2020 1745
Wire Wire Line
	1995 1890 2565 1890
$Comp
L Diode:1N4148 D?
U 1 1 5F871F44
P 2565 2130
F 0 "D?" V 2690 2255 50  0000 R CNN
F 1 "1N4148" V 2475 2595 50  0000 R CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2565 1955 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2565 2130 50  0001 C CNN
	1    2565 2130
	0    -1   -1   0   
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5F871F4B
P 2445 2130
F 0 "D?" V 2315 2300 50  0000 R CNN
F 1 "1N4148" V 2430 2085 50  0000 R CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2445 1955 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2445 2130 50  0001 C CNN
	1    2445 2130
	0    1    1    0   
$EndComp
Wire Wire Line
	2020 1980 2020 1745
Connection ~ 2020 1745
Wire Wire Line
	2020 1745 2695 1745
Wire Wire Line
	2140 1980 2140 1495
Connection ~ 2140 1495
Wire Wire Line
	2140 1495 2695 1495
Wire Wire Line
	2445 1980 2445 1350
Connection ~ 2445 1350
Wire Wire Line
	2445 1350 2695 1350
Wire Wire Line
	2565 1980 2565 1890
Connection ~ 2565 1890
Wire Wire Line
	2565 1890 2695 1890
Wire Wire Line
	2995 1495 2995 1745
Connection ~ 2995 1495
Connection ~ 2995 1745
Wire Wire Line
	2020 2280 2080 2280
Wire Wire Line
	2445 2280 2510 2280
Wire Wire Line
	2080 2280 2080 2655
Wire Wire Line
	2080 2655 2265 2655
Wire Wire Line
	2265 2655 2265 2790
Connection ~ 2080 2280
Wire Wire Line
	2080 2280 2140 2280
Wire Wire Line
	2255 3360 2260 3360
Wire Wire Line
	2510 3360 2510 2280
Connection ~ 2260 3360
Wire Wire Line
	2260 3360 2510 3360
Connection ~ 2510 2280
Wire Wire Line
	2510 2280 2565 2280
Text GLabel 1225 3460 0    50   Input ~ 0
SW_1
$Comp
L Device:R_Small R?
U 1 1 5F871F6F
P 3160 1495
F 0 "R?" V 3240 1490 50  0000 C CNN
F 1 "10k" V 3075 1495 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3160 1495 50  0001 C CNN
F 3 "~" H 3160 1495 50  0001 C CNN
	1    3160 1495
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F871F76
P 3580 1705
F 0 "R?" V 3660 1700 50  0000 C CNN
F 1 "22k" V 3495 1705 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3580 1705 50  0001 C CNN
F 3 "~" H 3580 1705 50  0001 C CNN
	1    3580 1705
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F871F7D
P 4060 1395
F 0 "R?" V 4140 1390 50  0000 C CNN
F 1 "100k" V 3975 1395 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4060 1395 50  0001 C CNN
F 3 "~" H 4060 1395 50  0001 C CNN
	1    4060 1395
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F871F84
P 4480 1625
F 0 "R?" V 4560 1620 50  0000 C CNN
F 1 "100k" V 4395 1625 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4480 1625 50  0001 C CNN
F 3 "~" H 4480 1625 50  0001 C CNN
	1    4480 1625
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F871F8B
P 4940 1295
F 0 "R?" V 5020 1290 50  0000 C CNN
F 1 "1k" V 4855 1295 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4940 1295 50  0001 C CNN
F 3 "~" H 4940 1295 50  0001 C CNN
	1    4940 1295
	0    1    1    0   
$EndComp
Wire Wire Line
	2995 1495 3060 1495
Wire Wire Line
	3260 1495 3290 1495
$Comp
L power:GND #PWR?
U 1 1 5F871F94
P 3275 1295
F 0 "#PWR?" H 3275 1045 50  0001 C CNN
F 1 "GND" H 3295 1200 50  0000 C CNN
F 2 "" H 3275 1295 50  0001 C CNN
F 3 "" H 3275 1295 50  0001 C CNN
	1    3275 1295
	1    0    0    -1  
$EndComp
Wire Wire Line
	3275 1295 3310 1295
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5F871F9B
P 8330 2040
AR Path="/5ED966D6/5F871F9B" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/5F871F9B" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F871F9B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8330 1890 50  0001 C CNN
F 1 "+12V-power" H 8195 2210 50  0000 C CNN
F 2 "" H 8330 2040 50  0001 C CNN
F 3 "" H 8330 2040 50  0001 C CNN
	1    8330 2040
	1    0    0    -1  
$EndComp
Wire Wire Line
	3910 1395 3935 1395
$Comp
L power:GND #PWR?
U 1 1 5F871FA2
P 4165 1195
F 0 "#PWR?" H 4165 945 50  0001 C CNN
F 1 "GND" H 4185 1100 50  0000 C CNN
F 2 "" H 4165 1195 50  0001 C CNN
F 3 "" H 4165 1195 50  0001 C CNN
	1    4165 1195
	1    0    0    -1  
$EndComp
Wire Wire Line
	4165 1195 4200 1195
Wire Wire Line
	3290 1495 3290 1705
Wire Wire Line
	3290 1705 3480 1705
Connection ~ 3290 1495
Wire Wire Line
	3290 1495 3310 1495
Wire Wire Line
	3680 1705 3935 1705
Wire Wire Line
	3935 1705 3935 1395
Connection ~ 3935 1395
Wire Wire Line
	3935 1395 3960 1395
Wire Wire Line
	4160 1395 4200 1395
Wire Wire Line
	4180 1405 4180 1625
Wire Wire Line
	4180 1625 4380 1625
Wire Wire Line
	4580 1625 4800 1625
Wire Wire Line
	4800 1625 4800 1295
Wire Wire Line
	4800 1295 4840 1295
Connection ~ 4800 1295
Wire Wire Line
	5040 1295 5125 1295
Text GLabel 5125 1295 2    50   Input ~ 0
SIGOUT_1
$Comp
L allcolours_analogue-rescue:-12V-power #PWR?
U 1 1 5F873D7D
P 8330 2735
F 0 "#PWR?" H 8330 2835 50  0001 C CNN
F 1 "-12V-power" H 8345 2908 50  0000 C CNN
F 2 "" H 8330 2735 50  0001 C CNN
F 3 "" H 8330 2735 50  0001 C CNN
	1    8330 2735
	-1   0    0    1   
$EndComp
Wire Wire Line
	8330 2675 8330 2735
Text Notes 1100 1075 0    50   ~ 0
1] Positive and negative set switch at 0v
Text Notes 1195 4240 0    50   ~ 0
2] 12v and gnd version so switch is halfway -but need different principle
$Comp
L 4xxx:4066 U?
U 1 1 5F874E5F
P 3320 5390
F 0 "U?" V 3470 5670 50  0000 R CNN
F 1 "4066" V 3205 5735 50  0000 R CNN
F 2 "" H 3320 5390 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 3320 5390 50  0001 C CNN
	1    3320 5390
	0    -1   -1   0   
$EndComp
$Comp
L 4xxx:4066 U?
U 2 1 5F874EED
P 3485 5960
F 0 "U?" V 3531 5833 50  0000 R CNN
F 1 "4066" V 3440 5833 50  0000 R CNN
F 2 "" H 3485 5960 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 3485 5960 50  0001 C CNN
	2    3485 5960
	0    -1   -1   0   
$EndComp
$Comp
L 4xxx:4066 U?
U 5 1 5F8750B0
P 1045 5475
F 0 "U?" H 1275 5521 50  0000 L CNN
F 1 "4066" H 1275 5430 50  0000 L CNN
F 2 "" H 1045 5475 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 1045 5475 50  0001 C CNN
	5    1045 5475
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F875226
P 1045 6025
AR Path="/5ED966D6/5F875226" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F875226" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1045 5775 50  0001 C CNN
F 1 "GND" H 1050 5852 50  0000 C CNN
F 2 "" H 1045 6025 50  0001 C CNN
F 3 "" H 1045 6025 50  0001 C CNN
	1    1045 6025
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5F8752EE
P 1045 4910
AR Path="/5ED966D6/5F8752EE" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/5F8752EE" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F8752EE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1045 4760 50  0001 C CNN
F 1 "+12V-power" H 910 5080 50  0000 C CNN
F 2 "" H 1045 4910 50  0001 C CNN
F 3 "" H 1045 4910 50  0001 C CNN
	1    1045 4910
	1    0    0    -1  
$EndComp
Wire Wire Line
	1045 4910 1045 4975
Wire Wire Line
	1045 5975 1045 6025
Text Notes 7000 6480 0    50   ~ 0
invertor
$Comp
L Amplifier_Operational:TL074 U?
U 2 1 5F87BB42
P 2655 5960
F 0 "U?" H 2655 6327 50  0000 C CNN
F 1 "TL074" H 2655 6236 50  0000 C CNN
F 2 "" H 2605 6060 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2705 6160 50  0001 C CNN
	2    2655 5960
	1    0    0    -1  
$EndComp
Wire Wire Line
	2360 5490 2290 5490
Wire Wire Line
	2290 5490 2290 5500
Wire Wire Line
	2290 5860 2355 5860
Wire Wire Line
	2185 5290 2185 6060
Wire Wire Line
	2185 6060 2290 6060
Wire Wire Line
	2185 5290 2360 5290
$Comp
L Device:R_Small R?
U 1 1 5F87BB4F
P 2085 6060
AR Path="/5ED966D6/5F87BB4F" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F87BB4F" Ref="R?"  Part="1" 
F 0 "R?" V 2190 6030 50  0000 C CNN
F 1 "10k" V 2285 6070 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2085 6060 50  0001 C CNN
F 3 "~" H 2085 6060 50  0001 C CNN
	1    2085 6060
	0    1    1    0   
$EndComp
Connection ~ 2185 6060
$Comp
L Device:R_Small R?
U 1 1 5F87BB57
P 2290 6160
F 0 "R?" V 2395 6130 50  0000 C CNN
F 1 "100k" V 2215 6155 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2290 6160 50  0001 C CNN
F 3 "~" H 2290 6160 50  0001 C CNN
	1    2290 6160
	-1   0    0    1   
$EndComp
Connection ~ 2290 6060
Wire Wire Line
	2290 6060 2355 6060
$Comp
L power:GND #PWR?
U 1 1 5F87BB60
P 2290 6295
AR Path="/5ED966D6/5F87BB60" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F87BB60" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2290 6045 50  0001 C CNN
F 1 "GND" H 2295 6122 50  0000 C CNN
F 2 "" H 2290 6295 50  0001 C CNN
F 3 "" H 2290 6295 50  0001 C CNN
	1    2290 6295
	1    0    0    -1  
$EndComp
Wire Wire Line
	2290 6260 2290 6295
Wire Wire Line
	1985 6060 1920 6060
$Comp
L power:GND #PWR?
U 1 1 5F87BB68
P 1860 5500
AR Path="/5ED966D6/5F87BB68" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F87BB68" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1860 5250 50  0001 C CNN
F 1 "GND" H 1865 5327 50  0000 C CNN
F 2 "" H 1860 5500 50  0001 C CNN
F 3 "" H 1860 5500 50  0001 C CNN
	1    1860 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2095 5500 2290 5500
Connection ~ 2290 5500
Wire Wire Line
	2290 5500 2290 5860
Text GLabel 1920 6060 0    50   Input ~ 0
SW_2
$Comp
L Amplifier_Operational:TL074 U?
U 1 1 5F87BB3B
P 2660 5390
AR Path="/5ED966D6/5F87BB3B" Ref="U?"  Part="1" 
AR Path="/5F86F8BD/5F87BB3B" Ref="U?"  Part="1" 
F 0 "U?" H 2660 5757 50  0000 C CNN
F 1 "TL074" H 2660 5666 50  0000 C CNN
F 2 "" H 2610 5490 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2710 5590 50  0001 C CNN
	1    2660 5390
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F87E3F8
P 1995 5500
AR Path="/5ED966D6/5F87E3F8" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F87E3F8" Ref="R?"  Part="1" 
F 0 "R?" V 2075 5495 50  0000 C CNN
F 1 "10k" V 1910 5500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1995 5500 50  0001 C CNN
F 3 "~" H 1995 5500 50  0001 C CNN
	1    1995 5500
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F87E6DA
P 1995 5335
AR Path="/5ED966D6/5F87E6DA" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F87E6DA" Ref="R?"  Part="1" 
F 0 "R?" V 2075 5330 50  0000 C CNN
F 1 "10k" V 1910 5335 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1995 5335 50  0001 C CNN
F 3 "~" H 1995 5335 50  0001 C CNN
	1    1995 5335
	0    1    1    0   
$EndComp
Wire Wire Line
	2095 5335 2095 5500
Connection ~ 2095 5500
Wire Wire Line
	1860 5500 1895 5500
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5F88165E
P 1855 5335
AR Path="/5ED966D6/5F88165E" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/5F88165E" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F88165E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1855 5185 50  0001 C CNN
F 1 "+12V-power" H 1720 5505 50  0000 C CNN
F 2 "" H 1855 5335 50  0001 C CNN
F 3 "" H 1855 5335 50  0001 C CNN
	1    1855 5335
	1    0    0    -1  
$EndComp
Wire Wire Line
	1855 5335 1895 5335
Wire Wire Line
	2960 5390 3020 5390
Wire Wire Line
	2955 5960 3185 5960
Text GLabel 3290 5690 0    50   Input ~ 0
IN1_2
Wire Wire Line
	3290 5690 3320 5690
Text GLabel 3460 6260 0    50   Input ~ 0
IN2_2
Wire Wire Line
	3460 6260 3485 6260
Wire Wire Line
	3320 5090 3485 5090
Wire Wire Line
	3485 5090 3485 5660
$Comp
L Device:R_Small R?
U 1 1 5F8983A6
P 3740 5090
AR Path="/5ED966D6/5F8983A6" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F8983A6" Ref="R?"  Part="1" 
F 0 "R?" V 3810 5095 50  0000 C CNN
F 1 "1k" V 3655 5090 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3740 5090 50  0001 C CNN
F 3 "~" H 3740 5090 50  0001 C CNN
	1    3740 5090
	0    1    1    0   
$EndComp
Text GLabel 3865 5090 2    50   Input ~ 0
SIGOUT_2
Wire Wire Line
	3840 5090 3865 5090
$Comp
L Amplifier_Operational:TL074 U?
U 5 1 5F89B198
P 4565 6235
F 0 "U?" H 4523 6281 50  0000 L CNN
F 1 "TL074" H 4523 6190 50  0000 L CNN
F 2 "" H 4515 6335 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4615 6435 50  0001 C CNN
	5    4565 6235
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5F89B19F
P 4465 5900
AR Path="/5ED966D6/5F89B19F" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/5F89B19F" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F89B19F" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4465 5750 50  0001 C CNN
F 1 "+12V-power" H 4330 6070 50  0000 C CNN
F 2 "" H 4465 5900 50  0001 C CNN
F 3 "" H 4465 5900 50  0001 C CNN
	1    4465 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4465 6535 4465 6595
$Comp
L power:GND #PWR?
U 1 1 5F89D003
P 4465 6595
AR Path="/5ED966D6/5F89D003" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F89D003" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4465 6345 50  0001 C CNN
F 1 "GND" H 4470 6422 50  0000 C CNN
F 2 "" H 4465 6595 50  0001 C CNN
F 3 "" H 4465 6595 50  0001 C CNN
	1    4465 6595
	1    0    0    -1  
$EndComp
Text Notes 6610 1780 0    50   ~ 0
3] but we need to switch x using x between x and -x - for +- version
Text Notes 6810 4180 0    50   ~ 0
4] but we need to switch x using x between x and -x fopr middle version
$Comp
L power:GND #PWR?
U 1 1 5F89FE35
P 7015 2250
AR Path="/5ED966D6/5F89FE35" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F89FE35" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7015 2000 50  0001 C CNN
F 1 "GND" H 6875 2215 50  0000 C CNN
F 2 "" H 7015 2250 50  0001 C CNN
F 3 "" H 7015 2250 50  0001 C CNN
	1    7015 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7015 2250 7055 2250
$Comp
L Device:R_Small R?
U 1 1 5F8A1E25
P 7360 2635
AR Path="/5ED966D6/5F8A1E25" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F8A1E25" Ref="R?"  Part="1" 
F 0 "R?" V 7465 2605 50  0000 C CNN
F 1 "10k" V 7560 2645 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7360 2635 50  0001 C CNN
F 3 "~" H 7360 2635 50  0001 C CNN
	1    7360 2635
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F8A2054
P 6920 2450
AR Path="/5ED966D6/5F8A2054" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F8A2054" Ref="R?"  Part="1" 
F 0 "R?" V 7025 2420 50  0000 C CNN
F 1 "10k" V 7120 2460 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6920 2450 50  0001 C CNN
F 3 "~" H 6920 2450 50  0001 C CNN
	1    6920 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	6725 2450 6820 2450
Wire Wire Line
	7035 2450 7035 2635
Wire Wire Line
	7035 2635 7260 2635
Wire Wire Line
	7460 2635 7655 2635
Wire Wire Line
	7655 2635 7655 2350
Wire Wire Line
	7655 2350 7715 2350
Text GLabel 7715 2350 2    50   Input ~ 0
-X_1
Text GLabel 6725 2450 0    50   Input ~ 0
X_1
$Comp
L Amplifier_Operational:TL072 U?
U 1 1 5F8B20DC
P 7355 2350
F 0 "U?" H 7355 2717 50  0000 C CNN
F 1 "TL072" H 7355 2626 50  0000 C CNN
F 2 "" H 7355 2350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 7355 2350 50  0001 C CNN
	1    7355 2350
	1    0    0    -1  
$EndComp
Connection ~ 7655 2350
Wire Wire Line
	7020 2450 7035 2450
Connection ~ 7035 2450
Wire Wire Line
	7035 2450 7055 2450
$Comp
L Amplifier_Operational:TL072 U?
U 3 1 5F8B5214
P 8430 2375
F 0 "U?" H 8388 2421 50  0000 L CNN
F 1 "TL072" H 8388 2330 50  0000 L CNN
F 2 "" H 8430 2375 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 8430 2375 50  0001 C CNN
	3    8430 2375
	1    0    0    -1  
$EndComp
Wire Wire Line
	8330 2040 8330 2075
$Comp
L Amplifier_Operational:TL074 U?
U 5 1 5F8B77F3
P 3380 2980
F 0 "U?" H 3338 3026 50  0000 L CNN
F 1 "TL074" H 3338 2935 50  0000 L CNN
F 2 "" H 3330 3080 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3430 3180 50  0001 C CNN
	5    3380 2980
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5F8B77FA
P 3280 2645
AR Path="/5ED966D6/5F8B77FA" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/5F8B77FA" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F8B77FA" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3280 2495 50  0001 C CNN
F 1 "+12V-power" H 3145 2815 50  0000 C CNN
F 2 "" H 3280 2645 50  0001 C CNN
F 3 "" H 3280 2645 50  0001 C CNN
	1    3280 2645
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:-12V-power #PWR?
U 1 1 5F8B7800
P 3280 3340
F 0 "#PWR?" H 3280 3440 50  0001 C CNN
F 1 "-12V-power" H 3295 3513 50  0000 C CNN
F 2 "" H 3280 3340 50  0001 C CNN
F 3 "" H 3280 3340 50  0001 C CNN
	1    3280 3340
	-1   0    0    1   
$EndComp
Wire Wire Line
	3280 3280 3280 3340
Wire Wire Line
	3280 2645 3280 2680
$Comp
L Device:R_Small R?
U 1 1 5F8BCCBF
P 7340 5300
AR Path="/5ED966D6/5F8BCCBF" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F8BCCBF" Ref="R?"  Part="1" 
F 0 "R?" V 7445 5270 50  0000 C CNN
F 1 "10k" V 7540 5310 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7340 5300 50  0001 C CNN
F 3 "~" H 7340 5300 50  0001 C CNN
	1    7340 5300
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F8BCCC6
P 6900 5115
AR Path="/5ED966D6/5F8BCCC6" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F8BCCC6" Ref="R?"  Part="1" 
F 0 "R?" V 7005 5085 50  0000 C CNN
F 1 "10k" V 7100 5125 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6900 5115 50  0001 C CNN
F 3 "~" H 6900 5115 50  0001 C CNN
	1    6900 5115
	0    1    1    0   
$EndComp
Wire Wire Line
	6705 5115 6800 5115
Wire Wire Line
	7015 5115 7015 5300
Wire Wire Line
	7015 5300 7240 5300
Wire Wire Line
	7440 5300 7635 5300
Wire Wire Line
	7635 5300 7635 5015
Wire Wire Line
	7635 5015 7695 5015
Text GLabel 7695 5015 2    50   Input ~ 0
-X_2
Text GLabel 6705 5115 0    50   Input ~ 0
X_2
$Comp
L Amplifier_Operational:TL074 U?
U 3 1 5F8BF869
P 7335 5015
F 0 "U?" H 7335 5382 50  0000 C CNN
F 1 "TL074" H 7335 5291 50  0000 C CNN
F 2 "" H 7285 5115 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 7385 5215 50  0001 C CNN
	3    7335 5015
	1    0    0    -1  
$EndComp
Connection ~ 7635 5015
Wire Wire Line
	7000 5115 7015 5115
Connection ~ 7015 5115
Wire Wire Line
	7015 5115 7035 5115
$Comp
L power:GND #PWR?
U 1 1 5F8C5E13
P 6565 4915
AR Path="/5ED966D6/5F8C5E13" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F8C5E13" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6565 4665 50  0001 C CNN
F 1 "GND" H 6415 4885 50  0000 C CNN
F 2 "" H 6565 4915 50  0001 C CNN
F 3 "" H 6565 4915 50  0001 C CNN
	1    6565 4915
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F8C5E1A
P 6700 4915
AR Path="/5ED966D6/5F8C5E1A" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F8C5E1A" Ref="R?"  Part="1" 
F 0 "R?" V 6780 4910 50  0000 C CNN
F 1 "10k" V 6615 4915 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6700 4915 50  0001 C CNN
F 3 "~" H 6700 4915 50  0001 C CNN
	1    6700 4915
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F8C5E21
P 6700 4750
AR Path="/5ED966D6/5F8C5E21" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F8C5E21" Ref="R?"  Part="1" 
F 0 "R?" V 6780 4745 50  0000 C CNN
F 1 "10k" V 6615 4750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6700 4750 50  0001 C CNN
F 3 "~" H 6700 4750 50  0001 C CNN
	1    6700 4750
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 4750 6800 4915
Connection ~ 6800 4915
Wire Wire Line
	6565 4915 6600 4915
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5F8C5E2B
P 6560 4750
AR Path="/5ED966D6/5F8C5E2B" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/5F8C5E2B" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F8C5E2B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6560 4600 50  0001 C CNN
F 1 "+12V-power" H 6425 4920 50  0000 C CNN
F 2 "" H 6560 4750 50  0001 C CNN
F 3 "" H 6560 4750 50  0001 C CNN
	1    6560 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6560 4750 6600 4750
Wire Wire Line
	6800 4915 7035 4915
$Comp
L Device:R_Small R?
U 1 1 5F8CC40D
P 3580 5190
AR Path="/5ED966D6/5F8CC40D" Ref="R?"  Part="1" 
AR Path="/5F86F8BD/5F8CC40D" Ref="R?"  Part="1" 
F 0 "R?" V 3650 5115 50  0000 C CNN
F 1 "10k" V 3770 5105 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3580 5190 50  0001 C CNN
F 3 "~" H 3580 5190 50  0001 C CNN
	1    3580 5190
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F8CC73A
P 3580 5320
AR Path="/5ED966D6/5F8CC73A" Ref="#PWR?"  Part="1" 
AR Path="/5F86F8BD/5F8CC73A" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3580 5070 50  0001 C CNN
F 1 "GND" H 3585 5147 50  0000 C CNN
F 2 "" H 3580 5320 50  0001 C CNN
F 3 "" H 3580 5320 50  0001 C CNN
	1    3580 5320
	1    0    0    -1  
$EndComp
Wire Wire Line
	3485 5090 3580 5090
Connection ~ 3485 5090
Wire Wire Line
	3580 5090 3640 5090
Connection ~ 3580 5090
Wire Wire Line
	3580 5290 3580 5320
$EndSCHEMATC