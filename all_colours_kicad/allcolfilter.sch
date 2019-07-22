EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
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
L allcolours-rescue:D_Zener_Small-device-allcolours-rescue D5
U 1 1 5B6E5322
P 4010 2510
F 0 "D5" V 3964 2578 50  0000 L CNN
F 1 "5819" V 3910 2610 50  0000 L CNN
F 2 "Diodes_SMD:D_SOD-123" V 4010 2510 50  0001 C CNN
F 3 "" V 4010 2510 50  0001 C CNN
	1    4010 2510
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:D_Zener_Small-device-allcolours-rescue D4
U 1 1 5B6E5329
P 4010 2260
F 0 "D4" V 3964 2328 50  0000 L CNN
F 1 "BAT85/1n5819" V 4055 2328 50  0000 L CNN
F 2 "Diodes_SMD:D_SOD-123" V 4010 2260 50  0001 C CNN
F 3 "" V 4010 2260 50  0001 C CNN
	1    4010 2260
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0101
U 1 1 5B6E5330
P 4010 2660
F 0 "#PWR0101" H 4010 2410 50  0001 C CNN
F 1 "GND" H 4010 2510 50  0000 C CNN
F 2 "" H 4010 2660 50  0000 C CNN
F 3 "" H 4010 2660 50  0000 C CNN
	1    4010 2660
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:MAX7490-MAX7490 U8
U 1 1 5B6E5336
P 2810 2010
F 0 "U8" H 2810 2725 50  0000 C CNN
F 1 "MAX7490-check width" H 2810 2634 50  0000 C CNN
F 2 "Housings_SSOP:QSOP-16_3.9x4.9mm_Pitch0.635mm" H 2810 2010 50  0001 C CNN
F 3 "DOCUMENTATION" H 2810 2010 50  0001 C CNN
	1    2810 2010
	1    0    0    -1  
$EndComp
Wire Wire Line
	2060 2710 2060 2410
Wire Wire Line
	3560 2260 3610 2260
Wire Wire Line
	3610 2260 3610 2710
Wire Wire Line
	3610 2710 2060 2710
Wire Wire Line
	4010 2410 4010 2360
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR0100
U 1 1 5B6E5344
P 4010 2110
F 0 "#PWR0100" H 4010 1960 50  0001 C CNN
F 1 "+5V" H 4110 2160 50  0000 C CNN
F 2 "" H 4010 2110 50  0001 C CNN
F 3 "" H 4010 2110 50  0001 C CNN
	1    4010 2110
	1    0    0    -1  
$EndComp
Wire Wire Line
	4010 2660 4010 2610
Wire Wire Line
	4010 2160 4010 2110
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR095
U 1 1 5B6E534D
P 1860 2410
F 0 "#PWR095" H 1860 2260 50  0001 C CNN
F 1 "+5V" H 1875 2583 50  0000 C CNN
F 2 "" H 1860 2410 50  0001 C CNN
F 3 "" H 1860 2410 50  0001 C CNN
	1    1860 2410
	1    0    0    -1  
$EndComp
Wire Wire Line
	1860 2410 1910 2410
Connection ~ 2060 2410
Wire Wire Line
	2060 2410 2060 2360
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR096
U 1 1 5B6E5356
P 2010 2260
F 0 "#PWR096" H 2010 2010 50  0001 C CNN
F 1 "GND" H 2010 2310 50  0000 C CNN
F 2 "" H 2010 2260 50  0000 C CNN
F 3 "" H 2010 2260 50  0000 C CNN
	1    2010 2260
	1    0    0    -1  
$EndComp
Wire Wire Line
	2010 2260 2060 2260
Wire Wire Line
	1910 2410 1910 2160
Wire Wire Line
	1910 2160 2060 2160
Connection ~ 1910 2410
Wire Wire Line
	1910 2410 2060 2410
$Comp
L allcolours-rescue:C-device-allcolours-rescue C38
U 1 1 5B6E5361
P 3760 2310
F 0 "C38" H 3785 2410 50  0000 L CNN
F 1 "100N" H 3785 2210 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3798 2160 50  0001 C CNN
F 3 "" H 3760 2310 50  0000 C CNN
	1    3760 2310
	-1   0    0    1   
$EndComp
Wire Wire Line
	3560 2160 3710 2160
Wire Wire Line
	3760 2460 3760 2610
Wire Wire Line
	3760 2610 4010 2610
Connection ~ 4010 2610
Text Notes 2060 1010 0    60   ~ 0
BANDPASS + 2x these - check!\n
Text Notes 5840 990  0    118  ~ 0
inputs x1 for both filters
$Comp
L allcolours-rescue:TL072-linear-allcolours-rescue U?
U 2 1 5B6FD0C0
P 6165 1595
AR Path="/5B6FD0C0" Ref="U?"  Part="2" 
AR Path="/5B6C330C/5B6FD0C0" Ref="U11"  Part="2" 
F 0 "U11" H 6506 1641 50  0000 L CNN
F 1 "TL072" H 6506 1550 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 6165 1595 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6165 1595 50  0001 C CNN
	2    6165 1595
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR?
U 1 1 5B6FD0C7
P 6065 1245
AR Path="/5B6FD0C7" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B6FD0C7" Ref="#PWR087"  Part="1" 
F 0 "#PWR087" H 6065 1095 50  0001 C CNN
F 1 "+12V" H 6065 1385 50  0000 C CNN
F 2 "" H 6065 1245 50  0000 C CNN
F 3 "" H 6065 1245 50  0000 C CNN
	1    6065 1245
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power-allcolours-rescue #PWR?
U 1 1 5B6FD0CD
P 6065 1945
AR Path="/5B6FD0CD" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B6FD0CD" Ref="#PWR088"  Part="1" 
F 0 "#PWR088" H 6065 1795 50  0001 C CNN
F 1 "-12VA" H 6065 2085 50  0000 C CNN
F 2 "" H 6065 1945 50  0000 C CNN
F 3 "" H 6065 1945 50  0000 C CNN
	1    6065 1945
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B6FD0D3
P 5565 1695
AR Path="/5B6FD0D3" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B6FD0D3" Ref="R47"  Part="1" 
F 0 "R47" V 5645 1695 50  0000 C CNN
F 1 "10K" V 5565 1695 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5495 1695 50  0001 C CNN
F 3 "" H 5565 1695 50  0000 C CNN
	1    5565 1695
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B6FD0DA
P 6065 2145
AR Path="/5B6FD0DA" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B6FD0DA" Ref="R48"  Part="1" 
F 0 "R48" V 6145 2145 50  0000 C CNN
F 1 "4.7K" V 6065 2145 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5995 2145 50  0001 C CNN
F 3 "" H 6065 2145 50  0000 C CNN
	1    6065 2145
	0    1    1    0   
$EndComp
Wire Wire Line
	5715 1695 5815 1695
Wire Wire Line
	5915 2145 5915 1995
Wire Wire Line
	5915 1995 5815 1995
Wire Wire Line
	5815 1995 5815 1695
Connection ~ 5815 1695
Wire Wire Line
	5815 1695 5865 1695
Wire Wire Line
	6215 2145 6465 2145
Wire Wire Line
	6465 2145 6465 1595
$Comp
L allcolours-rescue:CP1_Small-device-allcolours-rescue C?
U 1 1 5B6FD0E9
P 6665 1595
AR Path="/5B6FD0E9" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B6FD0E9" Ref="C35"  Part="1" 
F 0 "C35" H 6675 1665 50  0000 L CNN
F 1 "10u" H 6675 1515 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 6665 1595 50  0001 C CNN
F 3 "" H 6665 1595 50  0000 C CNN
	1    6665 1595
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6465 1595 6565 1595
Connection ~ 6465 1595
Wire Wire Line
	6065 1295 6065 1245
Wire Wire Line
	6065 1945 6065 1895
$Comp
L allcolours-rescue:CP1_Small-device-allcolours-rescue C?
U 1 1 5B705C47
P 5140 3910
AR Path="/5B705C47" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B705C47" Ref="C39"  Part="1" 
F 0 "C39" H 5150 3980 50  0000 L CNN
F 1 "10u" H 5150 3830 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 5140 3910 50  0001 C CNN
F 3 "" H 5140 3910 50  0000 C CNN
	1    5140 3910
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B705C4E
P 5440 3910
AR Path="/5B705C4E" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B705C4E" Ref="R58"  Part="1" 
F 0 "R58" V 5520 3910 50  0000 C CNN
F 1 "4.7K" V 5440 3910 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5370 3910 50  0001 C CNN
F 3 "" H 5440 3910 50  0000 C CNN
	1    5440 3910
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B705C55
P 5290 4210
AR Path="/5B705C55" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B705C55" Ref="R57"  Part="1" 
F 0 "R57" V 5370 4210 50  0000 C CNN
F 1 "?K" V 5290 4210 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5220 4210 50  0001 C CNN
F 3 "" H 5290 4210 50  0000 C CNN
	1    5290 4210
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B705C5C
P 5990 3260
AR Path="/5B705C5C" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B705C5C" Ref="R61"  Part="1" 
F 0 "R61" V 6070 3260 50  0000 C CNN
F 1 "10K" V 5990 3260 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5920 3260 50  0001 C CNN
F 3 "" H 5990 3260 50  0000 C CNN
	1    5990 3260
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C?
U 1 1 5B705C63
P 5990 3410
AR Path="/5B705C63" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5B705C63" Ref="C41"  Part="1" 
F 0 "C41" H 6015 3510 50  0000 L CNN
F 1 "18p" H 6015 3310 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6028 3260 50  0001 C CNN
F 3 "" H 5990 3410 50  0000 C CNN
	1    5990 3410
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5B705C6A
P 5290 4410
AR Path="/5B705C6A" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B705C6A" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 5290 4160 50  0001 C CNN
F 1 "GND" H 5290 4260 50  0000 C CNN
F 2 "" H 5290 4410 50  0000 C CNN
F 3 "" H 5290 4410 50  0000 C CNN
	1    5290 4410
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 5B705C70
P 5590 3710
AR Path="/5B705C70" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B705C70" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 5590 3460 50  0001 C CNN
F 1 "GND" H 5590 3560 50  0000 C CNN
F 2 "" H 5590 3710 50  0000 C CNN
F 3 "" H 5590 3710 50  0000 C CNN
	1    5590 3710
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:-12VA-power-allcolours-rescue #PWR?
U 1 1 5B705C77
P 5890 4210
AR Path="/5B705C77" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B705C77" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 5890 4060 50  0001 C CNN
F 1 "-12VA" H 5890 4350 50  0000 C CNN
F 2 "" H 5890 4210 50  0000 C CNN
F 3 "" H 5890 4210 50  0000 C CNN
	1    5890 4210
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:+12V-power-allcolours-rescue #PWR?
U 1 1 5B705C7D
P 5840 3160
AR Path="/5B705C7D" Ref="#PWR?"  Part="1" 
AR Path="/5B6C330C/5B705C7D" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 5840 3010 50  0001 C CNN
F 1 "+12V" H 5840 3300 50  0000 C CNN
F 2 "" H 5840 3160 50  0000 C CNN
F 3 "" H 5840 3160 50  0000 C CNN
	1    5840 3160
	1    0    0    -1  
$EndComp
Wire Wire Line
	5240 3910 5290 3910
Wire Wire Line
	5290 3910 5290 4060
Wire Wire Line
	5290 4410 5290 4360
Wire Wire Line
	5640 3260 5640 3410
Wire Wire Line
	5640 3410 5840 3410
Wire Wire Line
	5640 3260 5840 3260
Connection ~ 5640 3410
Wire Wire Line
	6140 3260 6140 3410
Wire Wire Line
	6140 3410 6290 3410
Wire Wire Line
	6290 3410 6290 3810
Wire Wire Line
	5890 4110 5890 4210
Wire Wire Line
	5890 3510 5840 3510
Wire Wire Line
	5590 3710 5640 3710
Text Notes 5140 4260 0    60   ~ 0
?
Wire Wire Line
	5640 3410 5640 3710
Connection ~ 5290 3910
Connection ~ 6140 3410
$Comp
L allcolours-rescue:TL072-linear-allcolours-rescue U?
U 1 1 5B705C9B
P 5990 3810
AR Path="/5B705C9B" Ref="U?"  Part="2" 
AR Path="/5B6C330C/5B705C9B" Ref="U13"  Part="1" 
F 0 "U13" H 6331 3856 50  0000 L CNN
F 1 "TL072" H 6331 3765 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 5990 3810 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5990 3810 50  0001 C CNN
	1    5990 3810
	1    0    0    -1  
$EndComp
Connection ~ 5640 3710
Wire Wire Line
	5640 3710 5690 3710
Connection ~ 6290 3810
Wire Wire Line
	5590 3910 5690 3910
Wire Wire Line
	6765 1595 6965 1595
Text Label 6965 1595 0    79   ~ 0
7490_IN_LOW
Wire Wire Line
	5415 1695 5265 1695
Wire Wire Line
	3560 2060 3710 2060
Wire Wire Line
	3710 2060 3710 2160
Connection ~ 3710 2160
Wire Wire Line
	3710 2160 3760 2160
Wire Wire Line
	3760 2160 3810 2160
Connection ~ 3760 2160
Text Label 3810 2160 0    60   ~ 0
COM
Wire Wire Line
	2060 2060 1910 2060
Text Label 1910 2060 0    60   ~ 0
COM
Wire Wire Line
	3560 2360 3660 2360
Wire Wire Line
	3660 2360 3660 2810
Connection ~ 3660 2360
Wire Wire Line
	3660 2360 4010 2360
Text Label 3660 2810 0    60   ~ 0
CLOCK
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7D3CA7
P 1810 1960
AR Path="/5B7D3CA7" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D3CA7" Ref="R52"  Part="1" 
F 0 "R52" V 1890 1960 50  0000 C CNN
F 1 "200K" V 1810 1960 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1740 1960 50  0001 C CNN
F 3 "" H 1810 1960 50  0000 C CNN
	1    1810 1960
	0    1    1    0   
$EndComp
Wire Wire Line
	1960 1960 2060 1960
Wire Wire Line
	1660 1960 1510 1960
Text Label 1510 1960 2    60   ~ 0
7490_IN_LOW
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7D5D40
P 2810 1160
AR Path="/5B7D5D40" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D5D40" Ref="R53"  Part="1" 
F 0 "R53" V 2890 1160 50  0000 C CNN
F 1 "200K" V 2810 1160 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2740 1160 50  0001 C CNN
F 3 "" H 2810 1160 50  0000 C CNN
	1    2810 1160
	0    1    1    0   
$EndComp
Wire Wire Line
	1960 1860 1960 1510
Wire Wire Line
	1960 1160 2660 1160
Wire Wire Line
	2960 1160 3760 1160
Wire Wire Line
	3760 1160 3760 1960
Wire Wire Line
	3760 1960 3560 1960
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7D8C95
P 1810 1660
AR Path="/5B7D8C95" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7D8C95" Ref="R51"  Part="1" 
F 0 "R51" V 1890 1660 50  0000 C CNN
F 1 "10K" V 1810 1660 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1740 1660 50  0001 C CNN
F 3 "" H 1810 1660 50  0000 C CNN
	1    1810 1660
	-1   0    0    1   
$EndComp
Wire Wire Line
	1960 1860 2060 1860
Wire Wire Line
	1810 1510 1960 1510
Connection ~ 1960 1510
Wire Wire Line
	1960 1510 1960 1160
Wire Wire Line
	1810 1810 1910 1810
Wire Wire Line
	1910 1810 1910 1910
Wire Wire Line
	1910 1910 1960 1910
Wire Wire Line
	1960 1910 1960 1960
Connection ~ 1960 1960
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7DE33A
P 1660 1660
AR Path="/5B7DE33A" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7DE33A" Ref="R50"  Part="1" 
F 0 "R50" V 1740 1660 50  0000 C CNN
F 1 "200K" V 1660 1660 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1590 1660 50  0001 C CNN
F 3 "" H 1660 1660 50  0000 C CNN
	1    1660 1660
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7DE3BC
P 1510 1660
AR Path="/5B7DE3BC" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7DE3BC" Ref="R49"  Part="1" 
F 0 "R49" V 1590 1660 50  0000 C CNN
F 1 "10K" V 1510 1660 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1440 1660 50  0001 C CNN
F 3 "" H 1510 1660 50  0000 C CNN
	1    1510 1660
	-1   0    0    1   
$EndComp
Wire Wire Line
	5040 3910 4840 3910
Text Label 4840 3910 2    60   ~ 0
7490_HP
Wire Wire Line
	3560 1860 3810 1860
Text Label 3910 1860 0    60   ~ 0
7490_HP
Wire Wire Line
	2060 1660 2060 1410
Wire Wire Line
	2060 1410 1660 1410
Wire Wire Line
	1660 1410 1660 1510
Wire Wire Line
	2060 1760 2010 1760
Wire Wire Line
	2010 1760 2010 1310
Wire Wire Line
	2010 1310 1510 1310
Wire Wire Line
	1510 1310 1510 1510
Wire Wire Line
	1510 1810 1660 1810
Wire Wire Line
	1660 1810 1810 1810
Connection ~ 1660 1810
Connection ~ 1810 1810
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7EAA51
P 3910 1610
AR Path="/5B7EAA51" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAA51" Ref="R54"  Part="1" 
F 0 "R54" V 3990 1610 50  0000 C CNN
F 1 "10K" V 3910 1610 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3840 1610 50  0001 C CNN
F 3 "" H 3910 1610 50  0000 C CNN
	1    3910 1610
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7EAB16
P 4060 1610
AR Path="/5B7EAB16" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAB16" Ref="R55"  Part="1" 
F 0 "R55" V 4140 1610 50  0000 C CNN
F 1 "200K" V 4060 1610 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3990 1610 50  0001 C CNN
F 3 "" H 4060 1610 50  0000 C CNN
	1    4060 1610
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5B7EAB84
P 4210 1610
AR Path="/5B7EAB84" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5B7EAB84" Ref="R56"  Part="1" 
F 0 "R56" V 4290 1610 50  0000 C CNN
F 1 "10K" V 4210 1610 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4140 1610 50  0001 C CNN
F 3 "" H 4210 1610 50  0000 C CNN
	1    4210 1610
	-1   0    0    1   
$EndComp
Wire Wire Line
	3910 1760 4060 1760
Wire Wire Line
	4210 1760 4060 1760
Connection ~ 4060 1760
Wire Wire Line
	3760 1960 3910 1960
Wire Wire Line
	3910 1960 3910 1910
Wire Wire Line
	3910 1910 4060 1910
Wire Wire Line
	4060 1910 4060 1760
Connection ~ 3760 1960
Wire Wire Line
	3810 1860 3810 1460
Wire Wire Line
	3810 1460 3910 1460
Connection ~ 3810 1860
Wire Wire Line
	3810 1860 3910 1860
Wire Wire Line
	3560 1760 3710 1760
Wire Wire Line
	3710 1760 3710 1410
Wire Wire Line
	3710 1410 4060 1410
Wire Wire Line
	4060 1410 4060 1460
Wire Wire Line
	4210 1460 4210 1360
Wire Wire Line
	4210 1360 3610 1360
Wire Wire Line
	3610 1360 3610 1660
Wire Wire Line
	3610 1660 3560 1660
Text Notes 2360 3060 0    60   ~ 0
7400 for low pass
$Comp
L allcolours-rescue:maxim_7400-all_colours U10
U 1 1 5B827130
P 2860 3560
F 0 "U10" H 2810 3707 60  0000 C CNN
F 1 "maxim_7400" H 2810 3601 60  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 2860 3560 60  0001 C CNN
F 3 "" H 2860 3560 60  0001 C CNN
	1    2860 3560
	1    0    0    -1  
$EndComp
Text Label 3660 3660 0    60   ~ 0
CLOCK
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR097
U 1 1 5B82ACD0
P 2060 3860
F 0 "#PWR097" H 2060 3610 50  0001 C CNN
F 1 "GND" H 2060 3710 50  0000 C CNN
F 2 "" H 2060 3860 50  0000 C CNN
F 3 "" H 2060 3860 50  0000 C CNN
	1    2060 3860
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR098
U 1 1 5B82AD0B
P 2110 4210
F 0 "#PWR098" H 2110 4060 50  0001 C CNN
F 1 "+5V" H 2125 4383 50  0000 C CNN
F 2 "" H 2110 4210 50  0001 C CNN
F 3 "" H 2110 4210 50  0001 C CNN
	1    2110 4210
	1    0    0    -1  
$EndComp
Wire Wire Line
	2410 3960 2410 4210
Wire Wire Line
	3510 3760 3510 4210
Wire Wire Line
	2110 4210 2410 4210
Connection ~ 2410 4210
Wire Wire Line
	2410 4210 3510 4210
Wire Wire Line
	2160 3760 2160 3660
Wire Wire Line
	2160 3660 1860 3660
Text Label 1860 3660 2    60   ~ 0
7490_IN_LOW
$Comp
L allcolours-rescue:C-device-allcolours-rescue C36
U 1 1 5B836AA8
P 1610 4060
F 0 "C36" H 1635 4160 50  0000 L CNN
F 1 "100N" H 1635 3960 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1648 3910 50  0001 C CNN
F 3 "" H 1610 4060 50  0000 C CNN
	1    1610 4060
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR094
U 1 1 5B83A4B5
P 1610 4260
F 0 "#PWR094" H 1610 4010 50  0001 C CNN
F 1 "GND" H 1610 4110 50  0000 C CNN
F 2 "" H 1610 4260 50  0000 C CNN
F 3 "" H 1610 4260 50  0000 C CNN
	1    1610 4260
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR093
U 1 1 5B83A4F2
P 1610 3860
F 0 "#PWR093" H 1610 3710 50  0001 C CNN
F 1 "+5V" H 1625 4033 50  0000 C CNN
F 2 "" H 1610 3860 50  0001 C CNN
F 3 "" H 1610 3860 50  0001 C CNN
	1    1610 3860
	1    0    0    -1  
$EndComp
Wire Wire Line
	1610 3860 1610 3910
Wire Wire Line
	1610 4210 1610 4260
$Comp
L allcolours-rescue:C-device-allcolours-rescue C33
U 1 1 5B841AB5
P 1160 4060
F 0 "C33" H 1185 4160 50  0000 L CNN
F 1 "100N" H 1185 3960 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1198 3910 50  0001 C CNN
F 3 "" H 1160 4060 50  0000 C CNN
	1    1160 4060
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR090
U 1 1 5B841ABB
P 1160 4260
F 0 "#PWR090" H 1160 4010 50  0001 C CNN
F 1 "GND" H 1160 4110 50  0000 C CNN
F 2 "" H 1160 4260 50  0000 C CNN
F 3 "" H 1160 4260 50  0000 C CNN
	1    1160 4260
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR089
U 1 1 5B841AC1
P 1160 3860
F 0 "#PWR089" H 1160 3710 50  0001 C CNN
F 1 "+5V" H 1175 4033 50  0000 C CNN
F 2 "" H 1160 3860 50  0001 C CNN
F 3 "" H 1160 3860 50  0001 C CNN
	1    1160 3860
	1    0    0    -1  
$EndComp
Wire Wire Line
	1160 3860 1160 3910
Wire Wire Line
	1160 4210 1160 4260
$Comp
L allcolours-rescue:C-device-allcolours-rescue C34
U 1 1 5B845936
P 1410 2560
F 0 "C34" H 1435 2660 50  0000 L CNN
F 1 "100N" H 1435 2460 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1448 2410 50  0001 C CNN
F 3 "" H 1410 2560 50  0000 C CNN
	1    1410 2560
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR092
U 1 1 5B84593C
P 1410 2760
F 0 "#PWR092" H 1410 2510 50  0001 C CNN
F 1 "GND" H 1410 2610 50  0000 C CNN
F 2 "" H 1410 2760 50  0000 C CNN
F 3 "" H 1410 2760 50  0000 C CNN
	1    1410 2760
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR091
U 1 1 5B845942
P 1410 2360
F 0 "#PWR091" H 1410 2210 50  0001 C CNN
F 1 "+5V" H 1425 2533 50  0000 C CNN
F 2 "" H 1410 2360 50  0001 C CNN
F 3 "" H 1410 2360 50  0001 C CNN
	1    1410 2360
	1    0    0    -1  
$EndComp
Wire Wire Line
	1410 2360 1410 2410
Wire Wire Line
	1410 2710 1410 2760
$Comp
L allcolours-rescue:C-device-allcolours-rescue C32
U 1 1 5B84594A
P 960 2560
F 0 "C32" H 985 2660 50  0000 L CNN
F 1 "100N" H 985 2460 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 998 2410 50  0001 C CNN
F 3 "" H 960 2560 50  0000 C CNN
	1    960  2560
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR086
U 1 1 5B845950
P 960 2760
F 0 "#PWR086" H 960 2510 50  0001 C CNN
F 1 "GND" H 960 2610 50  0000 C CNN
F 2 "" H 960 2760 50  0000 C CNN
F 3 "" H 960 2760 50  0000 C CNN
	1    960  2760
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:+5V-power-allcolours-rescue #PWR085
U 1 1 5B845956
P 960 2360
F 0 "#PWR085" H 960 2210 50  0001 C CNN
F 1 "+5V" H 975 2533 50  0000 C CNN
F 2 "" H 960 2360 50  0001 C CNN
F 3 "" H 960 2360 50  0001 C CNN
	1    960  2360
	1    0    0    -1  
$EndComp
Wire Wire Line
	960  2360 960  2410
Wire Wire Line
	960  2710 960  2760
$Comp
L allcolours-rescue:C-device-allcolours-rescue C37
U 1 1 5B84A5AB
P 2210 3210
F 0 "C37" H 2235 3310 50  0000 L CNN
F 1 "100N" H 2235 3110 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2248 3060 50  0001 C CNN
F 3 "" H 2210 3210 50  0000 C CNN
	1    2210 3210
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR099
U 1 1 5B84A6E3
P 2210 3410
F 0 "#PWR099" H 2210 3160 50  0001 C CNN
F 1 "GND" H 2210 3260 50  0000 C CNN
F 2 "" H 2210 3410 50  0000 C CNN
F 3 "" H 2210 3410 50  0000 C CNN
	1    2210 3410
	1    0    0    -1  
$EndComp
Wire Wire Line
	2410 3660 2410 3360
Wire Wire Line
	2410 3060 2210 3060
Wire Wire Line
	2210 3360 2210 3410
Wire Wire Line
	3260 3860 3260 3360
Wire Wire Line
	3260 3360 2410 3360
Connection ~ 2410 3360
Wire Wire Line
	2410 3360 2410 3060
Text Label 3660 3960 0    60   ~ 0
7400_LP
Text Label 5265 1695 2    60   ~ 0
FILTER_IN
Wire Wire Line
	2410 3660 2610 3660
Wire Wire Line
	2160 3760 2610 3760
Wire Wire Line
	2060 3860 2610 3860
Wire Wire Line
	2410 3960 2610 3960
Wire Wire Line
	2960 3960 3660 3960
Wire Wire Line
	2960 3860 3260 3860
Wire Wire Line
	2960 3760 3510 3760
Wire Wire Line
	2960 3660 3660 3660
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0134
U 1 1 5C09F49B
P 5740 1520
F 0 "#PWR0134" H 5740 1270 50  0001 C CNN
F 1 "GND" H 5740 1370 50  0000 C CNN
F 2 "" H 5740 1520 50  0000 C CNN
F 3 "" H 5740 1520 50  0000 C CNN
	1    5740 1520
	1    0    0    -1  
$EndComp
Wire Wire Line
	5865 1495 5740 1495
Wire Wire Line
	5740 1495 5740 1520
Wire Wire Line
	5840 3160 5840 3260
Text Label 7505 3695 0    60   ~ 0
7490_OUT
Connection ~ 4010 2360
Connection ~ 5840 3260
Wire Wire Line
	5840 3260 5840 3410
Connection ~ 5840 3410
Wire Wire Line
	5840 3410 5840 3510
Wire Wire Line
	6290 3810 6790 3810
Text Notes 5425 2825 0    118  ~ 0
filter outs x2
$Comp
L allcolours-rescue:CP1_Small-device-allcolours-rescue C?
U 1 1 5D412D70
P 6930 3965
AR Path="/5D412D70" Ref="C?"  Part="1" 
AR Path="/5B6C330C/5D412D70" Ref="C?"  Part="1" 
F 0 "C?" H 6940 4035 50  0000 L CNN
F 1 "10u" H 6940 3885 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 6930 3965 50  0001 C CNN
F 3 "" H 6930 3965 50  0000 C CNN
	1    6930 3965
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:R-device-allcolours-rescue R?
U 1 1 5D412E97
P 7310 3960
AR Path="/5D412E97" Ref="R?"  Part="1" 
AR Path="/5B6C330C/5D412E97" Ref="R?"  Part="1" 
F 0 "R?" V 7390 3960 50  0000 C CNN
F 1 "10K" V 7310 3960 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7240 3960 50  0001 C CNN
F 3 "" H 7310 3960 50  0000 C CNN
	1    7310 3960
	0    1    1    0   
$EndComp
$EndSCHEMATC
