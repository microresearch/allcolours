EESchema Schematic File Version 4
LIBS:touch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 8
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
F 2 "Resistors_SMD:R_0805" H 1835 1640 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 2160 1790 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 2635 1790 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 1860 2270 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 2660 2420 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 1880 3115 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 2680 3265 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 1905 3745 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 2705 3895 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 3505 1620 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 4305 1770 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 3530 2250 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 4330 2400 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 3550 3095 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 4350 3245 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 3575 3725 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" H 4375 3875 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 3830 1770 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 2185 2420 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 3855 2400 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 3875 3245 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 3900 3875 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 2230 3895 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 2205 3265 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2205 3265 50  0001 C CNN
	3    2205 3265
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U14
U 5 1 5F118B21
P 4545 4930
F 0 "U14" H 4545 5247 50  0000 C CNN
F 1 "40106" H 4545 5156 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 4545 4930 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4545 4930 50  0001 C CNN
	5    4545 4930
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 5 1 5F118B28
P 2260 4935
F 0 "U13" H 2260 5252 50  0000 C CNN
F 1 "40106" H 2260 5161 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 2260 4935 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2260 4935 50  0001 C CNN
	5    2260 4935
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118B2F
P 1935 4785
AR Path="/5C0A69D0/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118B2F" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118B2F" Ref="R33"  Part="1" 
F 0 "R33" H 1994 4831 50  0000 L CNN
F 1 "1M" H 1994 4740 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 1935 4785 50  0001 C CNN
F 3 "~" H 1935 4785 50  0001 C CNN
	1    1935 4785
	1    0    0    -1  
$EndComp
Wire Wire Line
	1935 4635 1935 4685
Wire Wire Line
	1935 4885 1935 4935
Wire Wire Line
	1935 4935 1960 4935
$Comp
L Device:R_Small R?
U 1 1 5F118B39
P 2735 4935
AR Path="/5C0A69D0/5F118B39" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118B39" Ref="R?"  Part="1" 
AR Path="/5F118B39" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118B39" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118B39" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118B39" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118B39" Ref="R39"  Part="1" 
F 0 "R39" H 2794 4981 50  0000 L CNN
F 1 "1K" H 2794 4890 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2735 4935 50  0001 C CNN
F 3 "~" H 2735 4935 50  0001 C CNN
	1    2735 4935
	0    1    1    0   
$EndComp
Wire Wire Line
	2635 4935 2560 4935
Wire Wire Line
	2835 4935 2875 4935
Wire Wire Line
	1935 4935 1835 4935
Connection ~ 1935 4935
Text GLabel 1835 4935 0    79   Input ~ 0
Frec
Text GLabel 2875 4935 2    79   Input ~ 0
rec
$Comp
L power:+3.3V #PWR075
U 1 1 5F118B46
P 1935 4635
F 0 "#PWR075" H 1935 4485 50  0001 C CNN
F 1 "+3.3V" H 1950 4808 50  0000 C CNN
F 2 "" H 1935 4635 50  0001 C CNN
F 3 "" H 1935 4635 50  0001 C CNN
	1    1935 4635
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F118B4C
P 4220 4780
AR Path="/5C0A69D0/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118B4C" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118B4C" Ref="R45"  Part="1" 
F 0 "R45" H 4279 4826 50  0000 L CNN
F 1 "1M" H 4279 4735 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 4220 4780 50  0001 C CNN
F 3 "~" H 4220 4780 50  0001 C CNN
	1    4220 4780
	1    0    0    -1  
$EndComp
Wire Wire Line
	4220 4630 4220 4680
Wire Wire Line
	4220 4880 4220 4930
Wire Wire Line
	4220 4930 4245 4930
$Comp
L Device:R_Small R?
U 1 1 5F118B56
P 5020 4930
AR Path="/5C0A69D0/5F118B56" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F118B56" Ref="R?"  Part="1" 
AR Path="/5F118B56" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F118B56" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F118B56" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F118B56" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F118B56" Ref="R51"  Part="1" 
F 0 "R51" H 5079 4976 50  0000 L CNN
F 1 "1K" H 5079 4885 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5020 4930 50  0001 C CNN
F 3 "~" H 5020 4930 50  0001 C CNN
	1    5020 4930
	0    1    1    0   
$EndComp
Wire Wire Line
	4920 4930 4845 4930
Wire Wire Line
	5120 4930 5160 4930
Wire Wire Line
	4220 4930 4120 4930
Connection ~ 4220 4930
Text GLabel 4120 4930 0    79   Input ~ 0
Fplay
Text GLabel 5160 4930 2    79   Input ~ 0
play
$Comp
L power:+3.3V #PWR081
U 1 1 5F118B63
P 4220 4630
F 0 "#PWR081" H 4220 4480 50  0001 C CNN
F 1 "+3.3V" H 4235 4803 50  0000 C CNN
F 2 "" H 4220 4630 50  0001 C CNN
F 3 "" H 4220 4630 50  0001 C CNN
	1    4220 4630
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 7 1 5F24A7EC
P 8610 2010
F 0 "U13" H 8840 2056 50  0000 L CNN
F 1 "40106" H 8840 1965 50  0000 L CNN
F 2 "SMD_Packages:SOIC-14_N" H 8610 2010 50  0001 C CNN
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
F 2 "SMD_Packages:SOIC-14_N" H 9340 2010 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 9340 2010 50  0001 C CNN
	7    9340 2010
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
Wire Wire Line
	9340 1460 9340 1510
Wire Wire Line
	8610 1465 8610 1510
Wire Wire Line
	8610 2510 8610 2570
Wire Wire Line
	9340 2510 9340 2575
$Comp
L Device:R_Small R?
U 1 1 5F2C3CA6
P 2240 5590
AR Path="/5C0A69D0/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2C3CA6" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2C3CA6" Ref="R34"  Part="1" 
F 0 "R34" H 2299 5636 50  0000 L CNN
F 1 "1M" H 2299 5545 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 2240 5590 50  0001 C CNN
F 3 "~" H 2240 5590 50  0001 C CNN
	1    2240 5590
	1    0    0    -1  
$EndComp
Wire Wire Line
	2240 5440 2240 5490
Wire Wire Line
	2240 5690 2240 5740
$Comp
L Device:R_Small R?
U 1 1 5F2C3CB0
P 3040 5740
AR Path="/5C0A69D0/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2C3CB0" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2C3CB0" Ref="R40"  Part="1" 
F 0 "R40" H 3099 5786 50  0000 L CNN
F 1 "1K" H 3099 5695 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 3040 5740 50  0001 C CNN
F 3 "~" H 3040 5740 50  0001 C CNN
	1    3040 5740
	0    1    1    0   
$EndComp
Wire Wire Line
	2940 5740 2870 5740
Wire Wire Line
	3140 5740 3180 5740
Wire Wire Line
	2240 5740 2140 5740
Connection ~ 2240 5740
Text GLabel 2140 5740 0    79   Input ~ 0
Fpush
Text GLabel 3180 5740 2    79   Input ~ 0
push
$Comp
L power:+3.3V #PWR076
U 1 1 5F2C3CBD
P 2240 5440
F 0 "#PWR076" H 2240 5290 50  0001 C CNN
F 1 "+3.3V" H 2255 5613 50  0000 C CNN
F 2 "" H 2240 5440 50  0001 C CNN
F 3 "" H 2240 5440 50  0001 C CNN
	1    2240 5440
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F2C3CC3
P 4225 5560
AR Path="/5C0A69D0/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2C3CC3" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2C3CC3" Ref="R46"  Part="1" 
F 0 "R46" H 4284 5606 50  0000 L CNN
F 1 "1M" H 4284 5515 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 4225 5560 50  0001 C CNN
F 3 "~" H 4225 5560 50  0001 C CNN
	1    4225 5560
	1    0    0    -1  
$EndComp
Wire Wire Line
	4225 5410 4225 5460
Wire Wire Line
	4225 5660 4225 5710
Wire Wire Line
	4225 5710 4250 5710
$Comp
L Device:R_Small R?
U 1 1 5F2C3CCD
P 5025 5710
AR Path="/5C0A69D0/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F2C3CCD" Ref="R?"  Part="1" 
AR Path="/5F0CAD2E/5F2C3CCD" Ref="R52"  Part="1" 
F 0 "R52" H 5084 5756 50  0000 L CNN
F 1 "1K" H 5084 5665 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5025 5710 50  0001 C CNN
F 3 "~" H 5025 5710 50  0001 C CNN
	1    5025 5710
	0    1    1    0   
$EndComp
Wire Wire Line
	4925 5710 4850 5710
Wire Wire Line
	5125 5710 5165 5710
Wire Wire Line
	4225 5710 4125 5710
Connection ~ 4225 5710
Text GLabel 4125 5710 0    79   Input ~ 0
Fpop
Text GLabel 5165 5710 2    79   Input ~ 0
pop
$Comp
L power:+3.3V #PWR082
U 1 1 5F2C3CDA
P 4225 5410
F 0 "#PWR082" H 4225 5260 50  0001 C CNN
F 1 "+3.3V" H 4240 5583 50  0000 C CNN
F 2 "" H 4225 5410 50  0001 C CNN
F 3 "" H 4225 5410 50  0001 C CNN
	1    4225 5410
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U13
U 6 1 5F2C8FE2
P 2570 5740
F 0 "U13" H 2570 6057 50  0000 C CNN
F 1 "40106" H 2570 5966 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 2570 5740 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 2570 5740 50  0001 C CNN
	6    2570 5740
	1    0    0    -1  
$EndComp
Connection ~ 2870 5740
Wire Wire Line
	2870 5740 2865 5740
$Comp
L 4xxx:40106 U14
U 6 1 5F2C927C
P 4550 5710
F 0 "U14" H 4550 6027 50  0000 C CNN
F 1 "40106" H 4550 5936 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 4550 5710 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4550 5710 50  0001 C CNN
	6    4550 5710
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F38F66E
P 8655 3585
AR Path="/5EBFD180/5F38F66E" Ref="C?"  Part="1" 
AR Path="/5F0CAD2E/5F38F66E" Ref="C65"  Part="1" 
F 0 "C65" H 8747 3631 50  0000 L CNN
F 1 "100nF" H 8747 3540 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8655 3585 50  0001 C CNN
F 3 "~" H 8655 3585 50  0001 C CNN
	1    8655 3585
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F38F675
P 8655 3725
AR Path="/5EBFD180/5F38F675" Ref="#PWR?"  Part="1" 
AR Path="/5F0CAD2E/5F38F675" Ref="#PWR0173"  Part="1" 
F 0 "#PWR0173" H 8655 3475 50  0001 C CNN
F 1 "GND" H 8660 3552 50  0000 C CNN
F 2 "" H 8655 3725 50  0001 C CNN
F 3 "" H 8655 3725 50  0001 C CNN
	1    8655 3725
	1    0    0    -1  
$EndComp
Wire Wire Line
	8655 3445 8655 3485
Wire Wire Line
	8655 3685 8655 3725
$Comp
L power:+3.3V #PWR0174
U 1 1 5F394C33
P 8655 3445
F 0 "#PWR0174" H 8655 3295 50  0001 C CNN
F 1 "+3.3V" H 8670 3618 50  0000 C CNN
F 2 "" H 8655 3445 50  0001 C CNN
F 3 "" H 8655 3445 50  0001 C CNN
	1    8655 3445
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F394F21
P 9335 3545
AR Path="/5EBFD180/5F394F21" Ref="C?"  Part="1" 
AR Path="/5F0CAD2E/5F394F21" Ref="C66"  Part="1" 
F 0 "C66" H 9427 3591 50  0000 L CNN
F 1 "100nF" H 9427 3500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 9335 3545 50  0001 C CNN
F 3 "~" H 9335 3545 50  0001 C CNN
	1    9335 3545
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F394F28
P 9335 3685
AR Path="/5EBFD180/5F394F28" Ref="#PWR?"  Part="1" 
AR Path="/5F0CAD2E/5F394F28" Ref="#PWR0175"  Part="1" 
F 0 "#PWR0175" H 9335 3435 50  0001 C CNN
F 1 "GND" H 9340 3512 50  0000 C CNN
F 2 "" H 9335 3685 50  0001 C CNN
F 3 "" H 9335 3685 50  0001 C CNN
	1    9335 3685
	1    0    0    -1  
$EndComp
Wire Wire Line
	9335 3405 9335 3445
Wire Wire Line
	9335 3645 9335 3685
$Comp
L power:+3.3V #PWR0176
U 1 1 5F394F30
P 9335 3405
F 0 "#PWR0176" H 9335 3255 50  0001 C CNN
F 1 "+3.3V" H 9350 3578 50  0000 C CNN
F 2 "" H 9335 3405 50  0001 C CNN
F 3 "" H 9335 3405 50  0001 C CNN
	1    9335 3405
	1    0    0    -1  
$EndComp
Wire Wire Line
	2240 5740 2270 5740
$EndSCHEMATC