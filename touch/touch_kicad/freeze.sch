EESchema Schematic File Version 4
LIBS:touch-cache
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
Text Notes 1550 865  0    118  ~ 0
add 4066 for touch input (freeze x10 and rec, play, push, pop = x14 which is 3x 4066)
$Comp
L Device:R_Small R?
U 1 1 5F118A01
P 1835 1640
AR Path="/5C0A69D0/5F118A01" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A01" Ref="R?"  Part="1" 
AR Path="/5F118A01" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A01" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A01" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A01" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A01" Ref="R29"  Part="1" 
F 0 "R29" H 1894 1686 50  0000 L CNN
F 1 "1M" H 1894 1595 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1835 1640 50  0001 C CNN
F 3 "~" H 1835 1640 50  0001 C CNN
	1    1835 1640
	1    0    0    -1  
$EndComp
Wire Wire Line
	1835 1490 1835 1540
Wire Wire Line
	1835 1740 1835 1790
Wire Wire Line
	1835 1790 1860 1790
$Comp
L 4xxx:40106 U?
U 1 1 5F118A0B
P 2160 1790
AR Path="/5C0A69D0/5F118A0B" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5F118A0B" Ref="U?"  Part="1" 
AR Path="/5F118A0B" Ref="U?"  Part="1" 
AR Path="/5EF10D95/5F118A0B" Ref="U?"  Part="1" 
AR Path="/5EBFD180/5F118A0B" Ref="U?"  Part="1" 
AR Path="/5F0C4BC3/5F118A0B" Ref="U?"  Part="1" 
AR Path="/5F0CAD2E/5F118A0B" Ref="U13"  Part="1" 
F 0 "U13" H 2160 2107 50  0000 C CNN
F 1 "40106" H 2160 2016 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2160 1790 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2160 1790 50  0001 C CNN
	1    2160 1790
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118A12
P 2635 1790
AR Path="/5C0A69D0/5F118A12" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A12" Ref="R?"  Part="1" 
AR Path="/5F118A12" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A12" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A12" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A12" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A12" Ref="R35"  Part="1" 
F 0 "R35" H 2694 1836 50  0000 L CNN
F 1 "1K" H 2694 1745 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2635 1790 50  0001 C CNN
F 3 "~" H 2635 1790 50  0001 C CNN
	1    2635 1790
	0    1    1    0   
$EndComp
Wire Wire Line
	2535 1790 2460 1790
Wire Wire Line
	2735 1790 2775 1790
Wire Wire Line
	1835 1790 1735 1790
Connection ~ 1835 1790
Text GLabel 1735 1790 0    79   Input ~ 0
F1
Text GLabel 2775 1790 2    79   Input ~ 0
FR1
$Comp
L power:+3.3V #PWR071
U 1 1 5F118A1F
P 1835 1490
F 0 "#PWR071" H 1835 1340 50  0001 C CNN
F 1 "+3.3V" H 1850 1663 50  0000 C CNN
F 2 "" H 1835 1490 50  0001 C CNN
F 3 "" H 1835 1490 50  0001 C CNN
	1    1835 1490
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118A25
P 1860 2270
AR Path="/5C0A69D0/5F118A25" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A25" Ref="R?"  Part="1" 
AR Path="/5F118A25" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A25" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A25" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A25" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A25" Ref="R30"  Part="1" 
F 0 "R30" H 1919 2316 50  0000 L CNN
F 1 "1M" H 1919 2225 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1860 2270 50  0001 C CNN
F 3 "~" H 1860 2270 50  0001 C CNN
	1    1860 2270
	1    0    0    -1  
$EndComp
Wire Wire Line
	1860 2120 1860 2170
Wire Wire Line
	1860 2370 1860 2420
Wire Wire Line
	1860 2420 1885 2420
$Comp
L Device:R_Small R?
U 1 1 5F118A2F
P 2660 2420
AR Path="/5C0A69D0/5F118A2F" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A2F" Ref="R?"  Part="1" 
AR Path="/5F118A2F" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A2F" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A2F" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A2F" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A2F" Ref="R36"  Part="1" 
F 0 "R36" H 2719 2466 50  0000 L CNN
F 1 "1K" H 2719 2375 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2660 2420 50  0001 C CNN
F 3 "~" H 2660 2420 50  0001 C CNN
	1    2660 2420
	0    1    1    0   
$EndComp
Wire Wire Line
	2560 2420 2485 2420
Wire Wire Line
	2760 2420 2800 2420
Wire Wire Line
	1860 2420 1760 2420
Connection ~ 1860 2420
Text GLabel 1760 2420 0    79   Input ~ 0
F2
Text GLabel 2800 2420 2    79   Input ~ 0
FR2
$Comp
L power:+3.3V #PWR072
U 1 1 5F118A3C
P 1860 2120
F 0 "#PWR072" H 1860 1970 50  0001 C CNN
F 1 "+3.3V" H 1875 2293 50  0000 C CNN
F 2 "" H 1860 2120 50  0001 C CNN
F 3 "" H 1860 2120 50  0001 C CNN
	1    1860 2120
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118A42
P 1880 3115
AR Path="/5C0A69D0/5F118A42" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A42" Ref="R?"  Part="1" 
AR Path="/5F118A42" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A42" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A42" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A42" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A42" Ref="R31"  Part="1" 
F 0 "R31" H 1939 3161 50  0000 L CNN
F 1 "1M" H 1939 3070 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1880 3115 50  0001 C CNN
F 3 "~" H 1880 3115 50  0001 C CNN
	1    1880 3115
	1    0    0    -1  
$EndComp
Wire Wire Line
	1880 2965 1880 3015
Wire Wire Line
	1880 3215 1880 3265
Wire Wire Line
	1880 3265 1905 3265
$Comp
L Device:R_Small R?
U 1 1 5F118A4C
P 2680 3265
AR Path="/5C0A69D0/5F118A4C" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A4C" Ref="R?"  Part="1" 
AR Path="/5F118A4C" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A4C" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A4C" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A4C" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A4C" Ref="R37"  Part="1" 
F 0 "R37" H 2739 3311 50  0000 L CNN
F 1 "1K" H 2739 3220 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2680 3265 50  0001 C CNN
F 3 "~" H 2680 3265 50  0001 C CNN
	1    2680 3265
	0    1    1    0   
$EndComp
Wire Wire Line
	2580 3265 2505 3265
Wire Wire Line
	2780 3265 2820 3265
Wire Wire Line
	1880 3265 1780 3265
Connection ~ 1880 3265
Text GLabel 1780 3265 0    79   Input ~ 0
F3
Text GLabel 2820 3265 2    79   Input ~ 0
FR3
$Comp
L power:+3.3V #PWR073
U 1 1 5F118A59
P 1880 2965
F 0 "#PWR073" H 1880 2815 50  0001 C CNN
F 1 "+3.3V" H 1895 3138 50  0000 C CNN
F 2 "" H 1880 2965 50  0001 C CNN
F 3 "" H 1880 2965 50  0001 C CNN
	1    1880 2965
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118A5F
P 1905 3745
AR Path="/5C0A69D0/5F118A5F" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A5F" Ref="R?"  Part="1" 
AR Path="/5F118A5F" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A5F" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A5F" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A5F" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A5F" Ref="R32"  Part="1" 
F 0 "R32" H 1964 3791 50  0000 L CNN
F 1 "1M" H 1964 3700 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1905 3745 50  0001 C CNN
F 3 "~" H 1905 3745 50  0001 C CNN
	1    1905 3745
	1    0    0    -1  
$EndComp
Wire Wire Line
	1905 3595 1905 3645
Wire Wire Line
	1905 3845 1905 3895
Wire Wire Line
	1905 3895 1930 3895
$Comp
L Device:R_Small R?
U 1 1 5F118A69
P 2705 3895
AR Path="/5C0A69D0/5F118A69" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A69" Ref="R?"  Part="1" 
AR Path="/5F118A69" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A69" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A69" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A69" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A69" Ref="R38"  Part="1" 
F 0 "R38" H 2764 3941 50  0000 L CNN
F 1 "1K" H 2764 3850 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2705 3895 50  0001 C CNN
F 3 "~" H 2705 3895 50  0001 C CNN
	1    2705 3895
	0    1    1    0   
$EndComp
Wire Wire Line
	2605 3895 2530 3895
Wire Wire Line
	2805 3895 2845 3895
Wire Wire Line
	1905 3895 1805 3895
Connection ~ 1905 3895
Text GLabel 1805 3895 0    79   Input ~ 0
F4
Text GLabel 2845 3895 2    79   Input ~ 0
FR4
$Comp
L power:+3.3V #PWR074
U 1 1 5F118A76
P 1905 3595
F 0 "#PWR074" H 1905 3445 50  0001 C CNN
F 1 "+3.3V" H 1920 3768 50  0000 C CNN
F 2 "" H 1905 3595 50  0001 C CNN
F 3 "" H 1905 3595 50  0001 C CNN
	1    1905 3595
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118A7C
P 3505 1620
AR Path="/5C0A69D0/5F118A7C" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A7C" Ref="R?"  Part="1" 
AR Path="/5F118A7C" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A7C" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A7C" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A7C" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A7C" Ref="R41"  Part="1" 
F 0 "R41" H 3564 1666 50  0000 L CNN
F 1 "1M" H 3564 1575 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3505 1620 50  0001 C CNN
F 3 "~" H 3505 1620 50  0001 C CNN
	1    3505 1620
	1    0    0    -1  
$EndComp
Wire Wire Line
	3505 1470 3505 1520
Wire Wire Line
	3505 1720 3505 1770
Wire Wire Line
	3505 1770 3530 1770
$Comp
L Device:R_Small R?
U 1 1 5F118A86
P 4305 1770
AR Path="/5C0A69D0/5F118A86" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A86" Ref="R?"  Part="1" 
AR Path="/5F118A86" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A86" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A86" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A86" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A86" Ref="R47"  Part="1" 
F 0 "R47" H 4364 1816 50  0000 L CNN
F 1 "1K" H 4364 1725 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4305 1770 50  0001 C CNN
F 3 "~" H 4305 1770 50  0001 C CNN
	1    4305 1770
	0    1    1    0   
$EndComp
Wire Wire Line
	4205 1770 4130 1770
Wire Wire Line
	4405 1770 4445 1770
Wire Wire Line
	3505 1770 3405 1770
Connection ~ 3505 1770
Text GLabel 3405 1770 0    79   Input ~ 0
F5
Text GLabel 4445 1770 2    79   Input ~ 0
FR5
$Comp
L power:+3.3V #PWR077
U 1 1 5F118A93
P 3505 1470
F 0 "#PWR077" H 3505 1320 50  0001 C CNN
F 1 "+3.3V" H 3520 1643 50  0000 C CNN
F 2 "" H 3505 1470 50  0001 C CNN
F 3 "" H 3505 1470 50  0001 C CNN
	1    3505 1470
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118A99
P 3530 2250
AR Path="/5C0A69D0/5F118A99" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118A99" Ref="R?"  Part="1" 
AR Path="/5F118A99" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118A99" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118A99" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118A99" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118A99" Ref="R42"  Part="1" 
F 0 "R42" H 3589 2296 50  0000 L CNN
F 1 "1M" H 3589 2205 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3530 2250 50  0001 C CNN
F 3 "~" H 3530 2250 50  0001 C CNN
	1    3530 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3530 2100 3530 2150
Wire Wire Line
	3530 2350 3530 2400
Wire Wire Line
	3530 2400 3555 2400
$Comp
L Device:R_Small R?
U 1 1 5F118AA3
P 4330 2400
AR Path="/5C0A69D0/5F118AA3" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118AA3" Ref="R?"  Part="1" 
AR Path="/5F118AA3" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118AA3" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118AA3" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118AA3" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118AA3" Ref="R48"  Part="1" 
F 0 "R48" H 4389 2446 50  0000 L CNN
F 1 "1K" H 4389 2355 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4330 2400 50  0001 C CNN
F 3 "~" H 4330 2400 50  0001 C CNN
	1    4330 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	4230 2400 4155 2400
Wire Wire Line
	4430 2400 4470 2400
Wire Wire Line
	3530 2400 3430 2400
Connection ~ 3530 2400
Text GLabel 3430 2400 0    79   Input ~ 0
F6
Text GLabel 4470 2400 2    79   Input ~ 0
FR6
$Comp
L power:+3.3V #PWR078
U 1 1 5F118AB0
P 3530 2100
F 0 "#PWR078" H 3530 1950 50  0001 C CNN
F 1 "+3.3V" H 3545 2273 50  0000 C CNN
F 2 "" H 3530 2100 50  0001 C CNN
F 3 "" H 3530 2100 50  0001 C CNN
	1    3530 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118AB6
P 3550 3095
AR Path="/5C0A69D0/5F118AB6" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118AB6" Ref="R?"  Part="1" 
AR Path="/5F118AB6" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118AB6" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118AB6" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118AB6" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118AB6" Ref="R43"  Part="1" 
F 0 "R43" H 3609 3141 50  0000 L CNN
F 1 "1M" H 3609 3050 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3550 3095 50  0001 C CNN
F 3 "~" H 3550 3095 50  0001 C CNN
	1    3550 3095
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2945 3550 2995
Wire Wire Line
	3550 3195 3550 3245
Wire Wire Line
	3550 3245 3575 3245
$Comp
L Device:R_Small R?
U 1 1 5F118AC0
P 4350 3245
AR Path="/5C0A69D0/5F118AC0" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118AC0" Ref="R?"  Part="1" 
AR Path="/5F118AC0" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118AC0" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118AC0" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118AC0" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118AC0" Ref="R49"  Part="1" 
F 0 "R49" H 4409 3291 50  0000 L CNN
F 1 "1K" H 4409 3200 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4350 3245 50  0001 C CNN
F 3 "~" H 4350 3245 50  0001 C CNN
	1    4350 3245
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 3245 4175 3245
Wire Wire Line
	4450 3245 4490 3245
Wire Wire Line
	3550 3245 3450 3245
Connection ~ 3550 3245
Text GLabel 3450 3245 0    79   Input ~ 0
F7
Text GLabel 4490 3245 2    79   Input ~ 0
FR7
$Comp
L power:+3.3V #PWR079
U 1 1 5F118ACD
P 3550 2945
F 0 "#PWR079" H 3550 2795 50  0001 C CNN
F 1 "+3.3V" H 3565 3118 50  0000 C CNN
F 2 "" H 3550 2945 50  0001 C CNN
F 3 "" H 3550 2945 50  0001 C CNN
	1    3550 2945
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118AD3
P 3575 3725
AR Path="/5C0A69D0/5F118AD3" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118AD3" Ref="R?"  Part="1" 
AR Path="/5F118AD3" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118AD3" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118AD3" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118AD3" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118AD3" Ref="R44"  Part="1" 
F 0 "R44" H 3634 3771 50  0000 L CNN
F 1 "1M" H 3634 3680 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3575 3725 50  0001 C CNN
F 3 "~" H 3575 3725 50  0001 C CNN
	1    3575 3725
	1    0    0    -1  
$EndComp
Wire Wire Line
	3575 3575 3575 3625
Wire Wire Line
	3575 3825 3575 3875
Wire Wire Line
	3575 3875 3600 3875
$Comp
L Device:R_Small R?
U 1 1 5F118ADD
P 4375 3875
AR Path="/5C0A69D0/5F118ADD" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118ADD" Ref="R?"  Part="1" 
AR Path="/5F118ADD" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118ADD" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118ADD" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118ADD" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118ADD" Ref="R50"  Part="1" 
F 0 "R50" H 4434 3921 50  0000 L CNN
F 1 "1K" H 4434 3830 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4375 3875 50  0001 C CNN
F 3 "~" H 4375 3875 50  0001 C CNN
	1    4375 3875
	0    1    1    0   
$EndComp
Wire Wire Line
	4275 3875 4200 3875
Wire Wire Line
	4475 3875 4515 3875
Wire Wire Line
	3575 3875 3475 3875
Connection ~ 3575 3875
Text GLabel 3475 3875 0    79   Input ~ 0
F8
Text GLabel 4515 3875 2    79   Input ~ 0
FR8
$Comp
L power:+3.3V #PWR080
U 1 1 5F118AEA
P 3575 3575
F 0 "#PWR080" H 3575 3425 50  0001 C CNN
F 1 "+3.3V" H 3590 3748 50  0000 C CNN
F 2 "" H 3575 3575 50  0001 C CNN
F 3 "" H 3575 3575 50  0001 C CNN
	1    3575 3575
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 1 1 5F118AF0
P 3830 1770
AR Path="/5C0A69D0/5F118AF0" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5F118AF0" Ref="U?"  Part="1" 
AR Path="/5F118AF0" Ref="U?"  Part="1" 
AR Path="/5EF10D95/5F118AF0" Ref="U?"  Part="1" 
AR Path="/5EBFD180/5F118AF0" Ref="U?"  Part="1" 
AR Path="/5F0C4BC3/5F118AF0" Ref="U?"  Part="1" 
AR Path="/5F0CAD2E/5F118AF0" Ref="U14"  Part="1" 
F 0 "U14" H 3830 2087 50  0000 C CNN
F 1 "40106" H 3830 1996 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3830 1770 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 3830 1770 50  0001 C CNN
	1    3830 1770
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 2 1 5F118AF7
P 2185 2420
F 0 "U13" H 2185 2737 50  0000 C CNN
F 1 "40106" H 2185 2646 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2185 2420 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2185 2420 50  0001 C CNN
	2    2185 2420
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U14
U 2 1 5F118AFE
P 3855 2400
F 0 "U14" H 3855 2717 50  0000 C CNN
F 1 "40106" H 3855 2626 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3855 2400 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 3855 2400 50  0001 C CNN
	2    3855 2400
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U14
U 3 1 5F118B05
P 3875 3245
F 0 "U14" H 3875 3562 50  0000 C CNN
F 1 "40106" H 3875 3471 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3875 3245 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 3875 3245 50  0001 C CNN
	3    3875 3245
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U14
U 4 1 5F118B0C
P 3900 3875
F 0 "U14" H 3900 4192 50  0000 C CNN
F 1 "40106" H 3900 4101 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3900 3875 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 3900 3875 50  0001 C CNN
	4    3900 3875
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 4 1 5F118B13
P 2230 3895
F 0 "U13" H 2230 4212 50  0000 C CNN
F 1 "40106" H 2230 4121 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2230 3895 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2230 3895 50  0001 C CNN
	4    2230 3895
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 3 1 5F118B1A
P 2205 3265
F 0 "U13" H 2205 3582 50  0000 C CNN
F 1 "40106" H 2205 3491 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2205 3265 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2205 3265 50  0001 C CNN
	3    2205 3265
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U14
U 5 1 5F118B21
P 4065 4960
F 0 "U14" H 4065 5277 50  0000 C CNN
F 1 "40106" H 4065 5186 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4065 4960 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4065 4960 50  0001 C CNN
	5    4065 4960
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 5 1 5F118B28
P 2395 4980
F 0 "U13" H 2395 5297 50  0000 C CNN
F 1 "40106" H 2395 5206 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2395 4980 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2395 4980 50  0001 C CNN
	5    2395 4980
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118B2F
P 2070 4830
AR Path="/5C0A69D0/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118B2F" Ref="R33"  Part="1" 
F 0 "R33" H 2129 4876 50  0000 L CNN
F 1 "1M" H 2129 4785 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2070 4830 50  0001 C CNN
F 3 "~" H 2070 4830 50  0001 C CNN
	1    2070 4830
	1    0    0    -1  
$EndComp
Wire Wire Line
	2070 4680 2070 4730
Wire Wire Line
	2070 4930 2070 4980
Wire Wire Line
	2070 4980 2095 4980
$Comp
L Device:R_Small R?
U 1 1 5F118B39
P 2870 4980
AR Path="/5C0A69D0/5F118B39" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118B39" Ref="R?"  Part="1" 
AR Path="/5F118B39" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118B39" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118B39" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118B39" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118B39" Ref="R39"  Part="1" 
F 0 "R39" H 2929 5026 50  0000 L CNN
F 1 "1K" H 2929 4935 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2870 4980 50  0001 C CNN
F 3 "~" H 2870 4980 50  0001 C CNN
	1    2870 4980
	0    1    1    0   
$EndComp
Wire Wire Line
	2770 4980 2695 4980
Wire Wire Line
	2970 4980 3010 4980
Wire Wire Line
	2070 4980 1970 4980
Connection ~ 2070 4980
Text GLabel 1970 4980 0    79   Input ~ 0
R1
Text GLabel 3010 4980 2    79   Input ~ 0
rec
$Comp
L power:+3.3V #PWR075
U 1 1 5F118B46
P 2070 4680
F 0 "#PWR075" H 2070 4530 50  0001 C CNN
F 1 "+3.3V" H 2085 4853 50  0000 C CNN
F 2 "" H 2070 4680 50  0001 C CNN
F 3 "" H 2070 4680 50  0001 C CNN
	1    2070 4680
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118B4C
P 3740 4810
AR Path="/5C0A69D0/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118B4C" Ref="R45"  Part="1" 
F 0 "R45" H 3799 4856 50  0000 L CNN
F 1 "1M" H 3799 4765 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3740 4810 50  0001 C CNN
F 3 "~" H 3740 4810 50  0001 C CNN
	1    3740 4810
	1    0    0    -1  
$EndComp
Wire Wire Line
	3740 4660 3740 4710
Wire Wire Line
	3740 4910 3740 4960
Wire Wire Line
	3740 4960 3765 4960
$Comp
L Device:R_Small R?
U 1 1 5F118B56
P 4540 4960
AR Path="/5C0A69D0/5F118B56" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118B56" Ref="R?"  Part="1" 
AR Path="/5F118B56" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118B56" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118B56" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118B56" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118B56" Ref="R51"  Part="1" 
F 0 "R51" H 4599 5006 50  0000 L CNN
F 1 "1K" H 4599 4915 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4540 4960 50  0001 C CNN
F 3 "~" H 4540 4960 50  0001 C CNN
	1    4540 4960
	0    1    1    0   
$EndComp
Wire Wire Line
	4440 4960 4365 4960
Wire Wire Line
	4640 4960 4680 4960
Wire Wire Line
	3740 4960 3640 4960
Connection ~ 3740 4960
Text GLabel 3640 4960 0    79   Input ~ 0
R2
Text GLabel 4680 4960 2    79   Input ~ 0
play
$Comp
L power:+3.3V #PWR081
U 1 1 5F118B63
P 3740 4660
F 0 "#PWR081" H 3740 4510 50  0001 C CNN
F 1 "+3.3V" H 3755 4833 50  0000 C CNN
F 2 "" H 3740 4660 50  0001 C CNN
F 3 "" H 3740 4660 50  0001 C CNN
	1    3740 4660
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 7 1 5F24A7EC
P 8610 2010
F 0 "U13" H 8840 2056 50  0000 L CNN
F 1 "40106" H 8840 1965 50  0000 L CNN
F 2 "" H 8610 2010 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 8610 2010 50  0001 C CNN
	7    8610 2010
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U14
U 7 1 5F24A902
P 9340 2010
F 0 "U14" H 9570 2056 50  0000 L CNN
F 1 "40106" H 9570 1965 50  0000 L CNN
F 2 "" H 9340 2010 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 9340 2010 50  0001 C CNN
	7    9340 2010
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U15
U 7 1 5F24AB96
P 10045 1980
F 0 "U15" H 10275 2026 50  0000 L CNN
F 1 "40106" H 10275 1935 50  0000 L CNN
F 2 "" H 10045 1980 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 10045 1980 50  0001 C CNN
	7    10045 1980
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR088
U 1 1 5F2AA4E5
P 8610 2570
F 0 "#PWR088" H 8610 2320 50  0001 C CNN
F 1 "GND" H 8615 2397 50  0000 C CNN
F 2 "" H 8610 2570 50  0001 C CNN
F 3 "" H 8610 2570 50  0001 C CNN
	1    8610 2570
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR090
U 1 1 5F2AA5BD
P 9340 2575
F 0 "#PWR090" H 9340 2325 50  0001 C CNN
F 1 "GND" H 9345 2402 50  0000 C CNN
F 2 "" H 9340 2575 50  0001 C CNN
F 3 "" H 9340 2575 50  0001 C CNN
	1    9340 2575
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR092
U 1 1 5F2AA60A
P 10045 2555
F 0 "#PWR092" H 10045 2305 50  0001 C CNN
F 1 "GND" H 10050 2382 50  0000 C CNN
F 2 "" H 10045 2555 50  0001 C CNN
F 3 "" H 10045 2555 50  0001 C CNN
	1    10045 2555
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR087
U 1 1 5F2AA7A1
P 8610 1465
F 0 "#PWR087" H 8610 1315 50  0001 C CNN
F 1 "+3.3V" H 8625 1638 50  0000 C CNN
F 2 "" H 8610 1465 50  0001 C CNN
F 3 "" H 8610 1465 50  0001 C CNN
	1    8610 1465
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR089
U 1 1 5F2AA8B4
P 9340 1460
F 0 "#PWR089" H 9340 1310 50  0001 C CNN
F 1 "+3.3V" H 9355 1633 50  0000 C CNN
F 2 "" H 9340 1460 50  0001 C CNN
F 3 "" H 9340 1460 50  0001 C CNN
	1    9340 1460
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR091
U 1 1 5F2AABB6
P 10045 1440
F 0 "#PWR091" H 10045 1290 50  0001 C CNN
F 1 "+3.3V" H 10060 1613 50  0000 C CNN
F 2 "" H 10045 1440 50  0001 C CNN
F 3 "" H 10045 1440 50  0001 C CNN
	1    10045 1440
	1    0    0    -1  
$EndComp
Wire Wire Line
	10045 1440 10045 1480
Wire Wire Line
	9340 1460 9340 1510
Wire Wire Line
	8610 1465 8610 1510
Wire Wire Line
	8610 2510 8610 2570
Wire Wire Line
	9340 2510 9340 2575
Wire Wire Line
	10045 2480 10045 2555
Text Notes 10495 1750 0    79   ~ 0
caps
$Comp
L Device:R_Small R?
U 1 1 5F2B5AFF
P 5485 1550
AR Path="/5C0A69D0/5F2B5AFF" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2B5AFF" Ref="R?"  Part="1" 
AR Path="/5F2B5AFF" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2B5AFF" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2B5AFF" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5AFF" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5AFF" Ref="R53"  Part="1" 
F 0 "R53" H 5544 1596 50  0000 L CNN
F 1 "1M" H 5544 1505 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5485 1550 50  0001 C CNN
F 3 "~" H 5485 1550 50  0001 C CNN
	1    5485 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5485 1400 5485 1450
Wire Wire Line
	5485 1650 5485 1700
Wire Wire Line
	5485 1700 5510 1700
$Comp
L 4xxx:40106 U?
U 1 1 5F2B5B09
P 5810 1700
AR Path="/5C0A69D0/5F2B5B09" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5F2B5B09" Ref="U?"  Part="1" 
AR Path="/5F2B5B09" Ref="U?"  Part="1" 
AR Path="/5EF10D95/5F2B5B09" Ref="U?"  Part="1" 
AR Path="/5EBFD180/5F2B5B09" Ref="U?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5B09" Ref="U?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5B09" Ref="U15"  Part="1" 
F 0 "U15" H 5810 2017 50  0000 C CNN
F 1 "40106" H 5810 1926 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5810 1700 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 5810 1700 50  0001 C CNN
	1    5810 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F2B5B10
P 6285 1700
AR Path="/5C0A69D0/5F2B5B10" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2B5B10" Ref="R?"  Part="1" 
AR Path="/5F2B5B10" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2B5B10" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2B5B10" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5B10" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5B10" Ref="R57"  Part="1" 
F 0 "R57" H 6344 1746 50  0000 L CNN
F 1 "1K" H 6344 1655 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6285 1700 50  0001 C CNN
F 3 "~" H 6285 1700 50  0001 C CNN
	1    6285 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	6185 1700 6110 1700
Wire Wire Line
	6385 1700 6425 1700
Wire Wire Line
	5485 1700 5385 1700
Connection ~ 5485 1700
Text GLabel 5385 1700 0    79   Input ~ 0
F9
Text GLabel 6425 1700 2    79   Input ~ 0
FR9
$Comp
L power:+3.3V #PWR083
U 1 1 5F2B5B1D
P 5485 1400
F 0 "#PWR083" H 5485 1250 50  0001 C CNN
F 1 "+3.3V" H 5500 1573 50  0000 C CNN
F 2 "" H 5485 1400 50  0001 C CNN
F 3 "" H 5485 1400 50  0001 C CNN
	1    5485 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F2B5B23
P 5510 2180
AR Path="/5C0A69D0/5F2B5B23" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2B5B23" Ref="R?"  Part="1" 
AR Path="/5F2B5B23" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2B5B23" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2B5B23" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5B23" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5B23" Ref="R54"  Part="1" 
F 0 "R54" H 5569 2226 50  0000 L CNN
F 1 "1M" H 5569 2135 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5510 2180 50  0001 C CNN
F 3 "~" H 5510 2180 50  0001 C CNN
	1    5510 2180
	1    0    0    -1  
$EndComp
Wire Wire Line
	5510 2030 5510 2080
Wire Wire Line
	5510 2280 5510 2330
Wire Wire Line
	5510 2330 5535 2330
$Comp
L Device:R_Small R?
U 1 1 5F2B5B2D
P 6310 2330
AR Path="/5C0A69D0/5F2B5B2D" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2B5B2D" Ref="R?"  Part="1" 
AR Path="/5F2B5B2D" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2B5B2D" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2B5B2D" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5B2D" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5B2D" Ref="R58"  Part="1" 
F 0 "R58" H 6369 2376 50  0000 L CNN
F 1 "1K" H 6369 2285 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6310 2330 50  0001 C CNN
F 3 "~" H 6310 2330 50  0001 C CNN
	1    6310 2330
	0    1    1    0   
$EndComp
Wire Wire Line
	6210 2330 6135 2330
Wire Wire Line
	6410 2330 6450 2330
Wire Wire Line
	5510 2330 5410 2330
Connection ~ 5510 2330
Text GLabel 5410 2330 0    79   Input ~ 0
F10
Text GLabel 6450 2330 2    79   Input ~ 0
FR10
$Comp
L power:+3.3V #PWR084
U 1 1 5F2B5B3A
P 5510 2030
F 0 "#PWR084" H 5510 1880 50  0001 C CNN
F 1 "+3.3V" H 5525 2203 50  0000 C CNN
F 2 "" H 5510 2030 50  0001 C CNN
F 3 "" H 5510 2030 50  0001 C CNN
	1    5510 2030
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F2B5B40
P 5530 3025
AR Path="/5C0A69D0/5F2B5B40" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2B5B40" Ref="R?"  Part="1" 
AR Path="/5F2B5B40" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2B5B40" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2B5B40" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5B40" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5B40" Ref="R55"  Part="1" 
F 0 "R55" H 5589 3071 50  0000 L CNN
F 1 "1M" H 5589 2980 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5530 3025 50  0001 C CNN
F 3 "~" H 5530 3025 50  0001 C CNN
	1    5530 3025
	1    0    0    -1  
$EndComp
Wire Wire Line
	5530 2875 5530 2925
Wire Wire Line
	5530 3125 5530 3175
Wire Wire Line
	5530 3175 5555 3175
$Comp
L Device:R_Small R?
U 1 1 5F2B5B4A
P 6330 3175
AR Path="/5C0A69D0/5F2B5B4A" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2B5B4A" Ref="R?"  Part="1" 
AR Path="/5F2B5B4A" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2B5B4A" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2B5B4A" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5B4A" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5B4A" Ref="R59"  Part="1" 
F 0 "R59" H 6389 3221 50  0000 L CNN
F 1 "1K" H 6389 3130 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6330 3175 50  0001 C CNN
F 3 "~" H 6330 3175 50  0001 C CNN
	1    6330 3175
	0    1    1    0   
$EndComp
Wire Wire Line
	6230 3175 6155 3175
Wire Wire Line
	6430 3175 6470 3175
Wire Wire Line
	5530 3175 5430 3175
Connection ~ 5530 3175
Text GLabel 5430 3175 0    79   Input ~ 0
F11
Text GLabel 6470 3175 2    79   Input ~ 0
FR11
$Comp
L power:+3.3V #PWR085
U 1 1 5F2B5B57
P 5530 2875
F 0 "#PWR085" H 5530 2725 50  0001 C CNN
F 1 "+3.3V" H 5545 3048 50  0000 C CNN
F 2 "" H 5530 2875 50  0001 C CNN
F 3 "" H 5530 2875 50  0001 C CNN
	1    5530 2875
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F2B5B5D
P 5555 3655
AR Path="/5C0A69D0/5F2B5B5D" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2B5B5D" Ref="R?"  Part="1" 
AR Path="/5F2B5B5D" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2B5B5D" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2B5B5D" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5B5D" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5B5D" Ref="R56"  Part="1" 
F 0 "R56" H 5614 3701 50  0000 L CNN
F 1 "1M" H 5614 3610 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5555 3655 50  0001 C CNN
F 3 "~" H 5555 3655 50  0001 C CNN
	1    5555 3655
	1    0    0    -1  
$EndComp
Wire Wire Line
	5555 3505 5555 3555
Wire Wire Line
	5555 3755 5555 3805
Wire Wire Line
	5555 3805 5580 3805
$Comp
L Device:R_Small R?
U 1 1 5F2B5B67
P 6355 3805
AR Path="/5C0A69D0/5F2B5B67" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2B5B67" Ref="R?"  Part="1" 
AR Path="/5F2B5B67" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2B5B67" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2B5B67" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2B5B67" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2B5B67" Ref="R60"  Part="1" 
F 0 "R60" H 6414 3851 50  0000 L CNN
F 1 "1K" H 6414 3760 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6355 3805 50  0001 C CNN
F 3 "~" H 6355 3805 50  0001 C CNN
	1    6355 3805
	0    1    1    0   
$EndComp
Wire Wire Line
	6255 3805 6180 3805
Wire Wire Line
	6455 3805 6495 3805
Wire Wire Line
	5555 3805 5455 3805
Connection ~ 5555 3805
Text GLabel 5455 3805 0    79   Input ~ 0
F12
Text GLabel 6495 3805 2    79   Input ~ 0
FR12
$Comp
L power:+3.3V #PWR086
U 1 1 5F2B5B74
P 5555 3505
F 0 "#PWR086" H 5555 3355 50  0001 C CNN
F 1 "+3.3V" H 5570 3678 50  0000 C CNN
F 2 "" H 5555 3505 50  0001 C CNN
F 3 "" H 5555 3505 50  0001 C CNN
	1    5555 3505
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U15
U 2 1 5F2B5B7D
P 5835 2330
F 0 "U15" H 5835 2647 50  0000 C CNN
F 1 "40106" H 5835 2556 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5835 2330 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 5835 2330 50  0001 C CNN
	2    5835 2330
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U15
U 4 1 5F2B5B84
P 5880 3805
F 0 "U15" H 5880 4122 50  0000 C CNN
F 1 "40106" H 5880 4031 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5880 3805 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 5880 3805 50  0001 C CNN
	4    5880 3805
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U15
U 3 1 5F2B5B8B
P 5855 3175
F 0 "U15" H 5855 3492 50  0000 C CNN
F 1 "40106" H 5855 3401 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5855 3175 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 5855 3175 50  0001 C CNN
	3    5855 3175
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F2C3CA6
P 2075 5610
AR Path="/5C0A69D0/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2C3CA6" Ref="R34"  Part="1" 
F 0 "R34" H 2134 5656 50  0000 L CNN
F 1 "1M" H 2134 5565 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2075 5610 50  0001 C CNN
F 3 "~" H 2075 5610 50  0001 C CNN
	1    2075 5610
	1    0    0    -1  
$EndComp
Wire Wire Line
	2075 5460 2075 5510
Wire Wire Line
	2075 5710 2075 5760
Wire Wire Line
	2075 5760 2100 5760
$Comp
L Device:R_Small R?
U 1 1 5F2C3CB0
P 2875 5760
AR Path="/5C0A69D0/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2C3CB0" Ref="R40"  Part="1" 
F 0 "R40" H 2934 5806 50  0000 L CNN
F 1 "1K" H 2934 5715 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2875 5760 50  0001 C CNN
F 3 "~" H 2875 5760 50  0001 C CNN
	1    2875 5760
	0    1    1    0   
$EndComp
Wire Wire Line
	2775 5760 2705 5760
Wire Wire Line
	2975 5760 3015 5760
Wire Wire Line
	2075 5760 1975 5760
Connection ~ 2075 5760
Text GLabel 1975 5760 0    79   Input ~ 0
R1
Text GLabel 3015 5760 2    79   Input ~ 0
push
$Comp
L power:+3.3V #PWR076
U 1 1 5F2C3CBD
P 2075 5460
F 0 "#PWR076" H 2075 5310 50  0001 C CNN
F 1 "+3.3V" H 2090 5633 50  0000 C CNN
F 2 "" H 2075 5460 50  0001 C CNN
F 3 "" H 2075 5460 50  0001 C CNN
	1    2075 5460
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F2C3CC3
P 3745 5590
AR Path="/5C0A69D0/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2C3CC3" Ref="R46"  Part="1" 
F 0 "R46" H 3804 5636 50  0000 L CNN
F 1 "1M" H 3804 5545 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3745 5590 50  0001 C CNN
F 3 "~" H 3745 5590 50  0001 C CNN
	1    3745 5590
	1    0    0    -1  
$EndComp
Wire Wire Line
	3745 5440 3745 5490
Wire Wire Line
	3745 5690 3745 5740
Wire Wire Line
	3745 5740 3770 5740
$Comp
L Device:R_Small R?
U 1 1 5F2C3CCD
P 4545 5740
AR Path="/5C0A69D0/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2C3CCD" Ref="R52"  Part="1" 
F 0 "R52" H 4604 5786 50  0000 L CNN
F 1 "1K" H 4604 5695 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4545 5740 50  0001 C CNN
F 3 "~" H 4545 5740 50  0001 C CNN
	1    4545 5740
	0    1    1    0   
$EndComp
Wire Wire Line
	4445 5740 4370 5740
Wire Wire Line
	4645 5740 4685 5740
Wire Wire Line
	3745 5740 3645 5740
Connection ~ 3745 5740
Text GLabel 3645 5740 0    79   Input ~ 0
R2
Text GLabel 4685 5740 2    79   Input ~ 0
pop
$Comp
L power:+3.3V #PWR082
U 1 1 5F2C3CDA
P 3745 5440
F 0 "#PWR082" H 3745 5290 50  0001 C CNN
F 1 "+3.3V" H 3760 5613 50  0000 C CNN
F 2 "" H 3745 5440 50  0001 C CNN
F 3 "" H 3745 5440 50  0001 C CNN
	1    3745 5440
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 6 1 5F2C8FE2
P 2405 5760
F 0 "U13" H 2405 6077 50  0000 C CNN
F 1 "40106" H 2405 5986 50  0000 C CNN
F 2 "" H 2405 5760 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2405 5760 50  0001 C CNN
	6    2405 5760
	1    0    0    -1  
$EndComp
Connection ~ 2705 5760
Wire Wire Line
	2705 5760 2700 5760
$Comp
L 4xxx:40106 U14
U 6 1 5F2C927C
P 4070 5740
F 0 "U14" H 4070 6057 50  0000 C CNN
F 1 "40106" H 4070 5966 50  0000 C CNN
F 2 "" H 4070 5740 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4070 5740 50  0001 C CNN
	6    4070 5740
	1    0    0    -1  
$EndComp
$EndSCHEMATC
