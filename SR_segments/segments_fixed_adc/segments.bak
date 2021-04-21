EESchema Schematic File Version 4
LIBS:segments-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title "SEGMENTS"
Date "2020-12-28"
Rev "002"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2375 185  0    79   ~ 0
incoming ADC chaned to digital/onboard 19/4/2021\nDAC is digital for different weighting schemes
Text Notes 6678 2951 0    79   ~ 0
buffer out - revised for +-5v (tides) - fixed 24/2
$Comp
L power:-12V #PWR040
U 1 1 5E8BB6AF
P 7465 2460
F 0 "#PWR040" H 7465 2560 50  0001 C CNN
F 1 "-12V" H 7600 2530 50  0000 C CNN
F 2 "" H 7465 2460 50  0001 C CNN
F 3 "" H 7465 2460 50  0001 C CNN
	1    7465 2460
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR039
U 1 1 5E8BB6B5
P 7465 1680
F 0 "#PWR039" H 7465 1530 50  0001 C CNN
F 1 "+12V" H 7465 1830 50  0000 C CNN
F 2 "" H 7465 1680 50  0001 C CNN
F 3 "" H 7465 1680 50  0001 C CNN
	1    7465 1680
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C10
U 1 1 5E8C7ADC
P 9300 1210
F 0 "C10" H 9392 1256 50  0000 L CNN
F 1 "100nF" H 9392 1165 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 9300 1210 50  0001 C CNN
F 3 "~" H 9300 1210 50  0001 C CNN
	1    9300 1210
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C11
U 1 1 5E8C7AE2
P 9825 1210
F 0 "C11" H 9917 1256 50  0000 L CNN
F 1 "100nF" H 9917 1165 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 9825 1210 50  0001 C CNN
F 3 "~" H 9825 1210 50  0001 C CNN
	1    9825 1210
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR047
U 1 1 5E8C7AE8
P 9300 1060
F 0 "#PWR047" H 9300 910 50  0001 C CNN
F 1 "+12V" H 9300 1210 50  0000 C CNN
F 2 "" H 9300 1060 50  0001 C CNN
F 3 "" H 9300 1060 50  0001 C CNN
	1    9300 1060
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR049
U 1 1 5E8C7AEE
P 9825 1060
F 0 "#PWR049" H 9825 1160 50  0001 C CNN
F 1 "-12V" H 9700 1135 50  0000 C CNN
F 2 "" H 9825 1060 50  0001 C CNN
F 3 "" H 9825 1060 50  0001 C CNN
	1    9825 1060
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR050
U 1 1 5E8C7AF4
P 9825 1360
F 0 "#PWR050" H 9825 1110 50  0001 C CNN
F 1 "GND" H 9950 1285 50  0000 C CNN
F 2 "" H 9825 1360 50  0001 C CNN
F 3 "" H 9825 1360 50  0001 C CNN
	1    9825 1360
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR048
U 1 1 5E8C7AFA
P 9300 1360
F 0 "#PWR048" H 9300 1110 50  0001 C CNN
F 1 "GND" H 9425 1285 50  0000 C CNN
F 2 "" H 9300 1360 50  0001 C CNN
F 3 "" H 9300 1360 50  0001 C CNN
	1    9300 1360
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 1060 9300 1110
Wire Wire Line
	9825 1060 9825 1110
Wire Wire Line
	9825 1310 9825 1360
Wire Wire Line
	9300 1310 9300 1360
$Comp
L Device:R_Small R34
U 1 1 5E9181B8
P 7615 2390
F 0 "R34" V 7830 2405 50  0000 C CNN
F 1 "68K" V 7730 2400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7615 2390 50  0001 C CNN
F 3 "~" H 7615 2390 50  0001 C CNN
	1    7615 2390
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR037
U 1 1 5E92DEBC
P 6980 1940
F 0 "#PWR037" H 6980 1690 50  0001 C CNN
F 1 "GND" H 7105 1865 50  0000 C CNN
F 2 "" H 6980 1940 50  0001 C CNN
F 3 "" H 6980 1940 50  0001 C CNN
	1    6980 1940
	1    0    0    -1  
$EndComp
Wire Wire Line
	7190 1915 7265 1915
Wire Wire Line
	7140 2390 7515 2390
Wire Wire Line
	7140 2115 7140 2390
Text GLabel 8150 2015 2    79   Input ~ 0
DAC_OUT
$Sheet
S 8985 3435 1800 375 
U 5E8871AA
F0 "power" 79
F1 "power.sch" 50
$EndSheet
$Sheet
S 9130 5470 1575 275 
U 5E8972E3
F0 "pulses_etc" 79
F1 "pulsesetc.sch" 79
$EndSheet
$Sheet
S 9055 4155 1575 250 
U 5E9336F6
F0 "IO" 118
F1 "inout.sch" 118
$EndSheet
$Sheet
S 9090 4760 1875 375 
U 5E933887
F0 "micro" 118
F1 "micro.sch" 118
$EndSheet
$Comp
L Device:R_Small R33
U 1 1 5F8B8D27
P 7010 2115
F 0 "R33" H 7069 2161 50  0000 L CNN
F 1 "20K" H 7069 2070 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 7010 2115 50  0001 C CNN
F 3 "~" H 7010 2115 50  0001 C CNN
	1    7010 2115
	0    1    1    0   
$EndComp
Wire Wire Line
	7110 2115 7140 2115
Wire Wire Line
	6910 2115 6860 2115
Text GLabel 6860 2115 0    50   Input ~ 0
DAC_MC_OUT
$Sheet
S 9115 6020 2090 305 
U 5F8E1429
F0 "CVs" 79
F1 "CV.sch" 79
$EndSheet
Connection ~ 7140 2115
$Comp
L Device:R_Small R37
U 1 1 5FECDD21
P 8040 2015
F 0 "R37" H 7840 2010 50  0000 L CNN
F 1 "1K" H 8099 1970 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 8040 2015 50  0001 C CNN
F 3 "~" H 8040 2015 50  0001 C CNN
	1    8040 2015
	0    1    1    0   
$EndComp
Wire Wire Line
	8140 2015 8140 2390
Wire Wire Line
	7715 2390 8140 2390
$Comp
L Device:C_Small C7
U 1 1 5FED4BC6
P 7625 2720
F 0 "C7" H 7717 2766 50  0000 L CNN
F 1 "47pF" V 7700 2830 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 7625 2720 50  0001 C CNN
F 3 "~" H 7625 2720 50  0001 C CNN
	1    7625 2720
	0    1    1    0   
$EndComp
Wire Wire Line
	8140 2015 8150 2015
Connection ~ 8140 2015
$Comp
L Device:R_Small R36
U 1 1 5FEEB582
P 6980 1800
F 0 "R36" V 7195 1815 50  0000 C CNN
F 1 "100K" V 7095 1810 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6980 1800 50  0001 C CNN
F 3 "~" H 6980 1800 50  0001 C CNN
	1    6980 1800
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R35
U 1 1 5FEF2936
P 6980 1560
F 0 "R35" V 7195 1575 50  0000 C CNN
F 1 "130K" V 7095 1570 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6980 1560 50  0001 C CNN
F 3 "~" H 6980 1560 50  0001 C CNN
	1    6980 1560
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3VA #PWR0156
U 1 1 5FF17F4A
P 6980 1415
F 0 "#PWR0156" H 6980 1265 50  0001 C CNN
F 1 "+3.3VA" H 6995 1588 50  0000 C CNN
F 2 "" H 6980 1415 50  0001 C CNN
F 3 "" H 6980 1415 50  0001 C CNN
	1    6980 1415
	1    0    0    -1  
$EndComp
Wire Wire Line
	6980 1660 6980 1680
Wire Wire Line
	6980 1680 7105 1680
Wire Wire Line
	7190 1680 7190 1915
Connection ~ 6980 1680
Wire Wire Line
	6980 1680 6980 1700
Wire Wire Line
	6980 1900 6980 1920
Wire Wire Line
	6980 1415 6980 1460
$Comp
L Device:CP_Small C?
U 1 1 5FEB04BE
P 7105 1800
AR Path="/5E8871AA/5FEB04BE" Ref="C?"  Part="1" 
AR Path="/5FEB04BE" Ref="C40"  Part="1" 
F 0 "C40" H 7193 1846 50  0000 L CNN
F 1 "1uF" H 7190 1955 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 7105 1800 50  0001 C CNN
F 3 "~" H 7105 1800 50  0001 C CNN
	1    7105 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7105 1680 7105 1700
Connection ~ 7105 1680
Wire Wire Line
	7105 1680 7190 1680
Wire Wire Line
	6980 1920 7105 1920
Wire Wire Line
	7105 1920 7105 1900
Connection ~ 6980 1920
Wire Wire Line
	6980 1920 6980 1940
Text Notes 2360 -295 0    79   ~ 0
Revised for new buffer DAC out, ADCref jack and analog power 28/12/2020\nChanged normings so is only one PWM norm 4/1/2020
Text Notes 6909 865  0    118  ~ 0
all pots reversed on pcb
Wire Wire Line
	7140 2115 7265 2115
$Comp
L Amplifier_Operational:TL071 U4
U 1 1 603957CA
P 7565 2015
F 0 "U4" H 7906 2061 50  0000 L CNN
F 1 "TL071/TLV172" H 7515 2415 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 7615 2065 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 7715 2165 50  0001 C CNN
	1    7565 2015
	1    0    0    -1  
$EndComp
Wire Wire Line
	7865 2015 7895 2015
Wire Wire Line
	7140 2390 7140 2720
Wire Wire Line
	7140 2720 7525 2720
Connection ~ 7140 2390
Wire Wire Line
	7725 2720 7895 2720
Wire Wire Line
	7895 2720 7895 2015
Connection ~ 7895 2015
Wire Wire Line
	7895 2015 7940 2015
Wire Wire Line
	7465 2315 7465 2460
Wire Wire Line
	7465 1680 7465 1715
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U?
U 1 1 608113A6
P 2820 1720
AR Path="/5F88C158/608113A6" Ref="U?"  Part="1" 
AR Path="/5E933887/608113A6" Ref="U?"  Part="1" 
AR Path="/5F8E1429/608113A6" Ref="U?"  Part="1" 
AR Path="/608113A6" Ref="U1"  Part="1" 
F 0 "U1" H 2875 1860 50  0000 L CNN
F 1 "MCP6002" H 2820 1620 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 2820 1720 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 2820 1720 50  0001 C CNN
	1    2820 1720
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 608113AD
P 2720 2070
AR Path="/5F88C158/608113AD" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/608113AD" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/608113AD" Ref="#PWR?"  Part="1" 
AR Path="/608113AD" Ref="#PWR03"  Part="1" 
F 0 "#PWR03" H 2720 1820 50  0001 C CNN
F 1 "GND" H 2855 2015 50  0000 C CNN
F 2 "" H 2720 2070 50  0001 C CNN
F 3 "" H 2720 2070 50  0001 C CNN
	1    2720 2070
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 608113B3
P 2370 1820
AR Path="/5F88C158/608113B3" Ref="R?"  Part="1" 
AR Path="/5E933887/608113B3" Ref="R?"  Part="1" 
AR Path="/5F8E1429/608113B3" Ref="R?"  Part="1" 
AR Path="/608113B3" Ref="R1"  Part="1" 
F 0 "R1" V 2455 1635 50  0000 C CNN
F 1 "100K" V 2275 1740 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2370 1820 50  0001 C CNN
F 3 "" H 2370 1820 50  0001 C CNN
	1    2370 1820
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 608113BA
P 2770 2270
AR Path="/5F88C158/608113BA" Ref="R?"  Part="1" 
AR Path="/5E933887/608113BA" Ref="R?"  Part="1" 
AR Path="/5F8E1429/608113BA" Ref="R?"  Part="1" 
AR Path="/608113BA" Ref="R3"  Part="1" 
F 0 "R3" V 2690 2400 50  0000 C CNN
F 1 "33K" V 2820 2465 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2770 2270 50  0001 C CNN
F 3 "" H 2770 2270 50  0001 C CNN
	1    2770 2270
	0    1    1    0   
$EndComp
Wire Wire Line
	2720 1420 2720 1370
Wire Wire Line
	2470 1820 2520 1820
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR?
U 1 1 608113C3
P 2470 1620
AR Path="/5F88C158/608113C3" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/608113C3" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/608113C3" Ref="#PWR?"  Part="1" 
AR Path="/608113C3" Ref="#PWR01"  Part="1" 
F 0 "#PWR01" H 2470 1370 50  0001 C CNN
F 1 "GND" H 2475 1447 50  0000 C CNN
F 2 "" H 2470 1620 50  0001 C CNN
F 3 "" H 2470 1620 50  0001 C CNN
	1    2470 1620
	1    0    0    -1  
$EndComp
Wire Wire Line
	2470 1620 2520 1620
Wire Wire Line
	2720 2070 2720 2020
Wire Wire Line
	2470 2270 2670 2270
Wire Wire Line
	2870 2270 3120 2270
Wire Wire Line
	3120 2270 3120 1720
Connection ~ 2470 2270
Wire Wire Line
	2170 1820 2270 1820
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C?
U 1 1 608113D0
P 2770 2470
AR Path="/5F88C158/608113D0" Ref="C?"  Part="1" 
AR Path="/5E933887/608113D0" Ref="C?"  Part="1" 
AR Path="/5F8E1429/608113D0" Ref="C?"  Part="1" 
AR Path="/608113D0" Ref="C1"  Part="1" 
F 0 "C1" V 2825 2590 50  0000 C CNN
F 1 "10pF" V 2885 2475 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 2770 2470 50  0001 C CNN
F 3 "" H 2770 2470 50  0001 C CNN
	1    2770 2470
	0    1    1    0   
$EndComp
Wire Wire Line
	2470 2270 2470 2470
Wire Wire Line
	2470 2470 2670 2470
Wire Wire Line
	2870 2470 3120 2470
Wire Wire Line
	3120 2470 3120 2270
Connection ~ 3120 2270
Wire Wire Line
	1950 2040 1950 1575
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R?
U 1 1 608113EB
P 2370 2040
AR Path="/5F88C158/608113EB" Ref="R?"  Part="1" 
AR Path="/5E933887/608113EB" Ref="R?"  Part="1" 
AR Path="/5F8E1429/608113EB" Ref="R?"  Part="1" 
AR Path="/608113EB" Ref="R2"  Part="1" 
F 0 "R2" V 2450 2055 50  0000 C CNN
F 1 "200K" V 2265 2040 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2370 2040 50  0001 C CNN
F 3 "" H 2370 2040 50  0001 C CNN
	1    2370 2040
	0    1    1    0   
$EndComp
Wire Wire Line
	1950 2040 2270 2040
Text GLabel 1950 1575 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR?
U 1 1 608113F5
P 2720 1370
AR Path="/5F88C158/608113F5" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/608113F5" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/608113F5" Ref="#PWR?"  Part="1" 
AR Path="/608113F5" Ref="#PWR02"  Part="1" 
F 0 "#PWR02" H 2720 1220 50  0001 C CNN
F 1 "+3.3V" H 2735 1543 50  0000 C CNN
F 2 "" H 2720 1370 50  0001 C CNN
F 3 "" H 2720 1370 50  0001 C CNN
	1    2720 1370
	1    0    0    -1  
$EndComp
Text GLabel 2170 1820 1    79   Input ~ 0
ADC_IN
Wire Wire Line
	3120 1720 3310 1720
Wire Wire Line
	2470 1820 2470 2040
Connection ~ 2470 1820
Connection ~ 2470 2040
Wire Wire Line
	2470 2040 2470 2270
Connection ~ 3120 1720
Text GLabel 3310 1720 2    50   Input ~ 0
ADC12
$Comp
L Device:C_Small C2
U 1 1 608AB381
P 3435 2340
F 0 "C2" H 3527 2386 50  0000 L CNN
F 1 "100nF" H 3527 2295 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3435 2340 50  0001 C CNN
F 3 "~" H 3435 2340 50  0001 C CNN
	1    3435 2340
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 608AB38E
P 3435 2490
F 0 "#PWR05" H 3435 2240 50  0001 C CNN
F 1 "GND" H 3560 2415 50  0000 C CNN
F 2 "" H 3435 2490 50  0001 C CNN
F 3 "" H 3435 2490 50  0001 C CNN
	1    3435 2490
	1    0    0    -1  
$EndComp
Wire Wire Line
	3435 2190 3435 2240
Wire Wire Line
	3435 2440 3435 2490
$Comp
L power:+3.3V #PWR?
U 1 1 608AC0D4
P 3435 2190
AR Path="/5F88C158/608AC0D4" Ref="#PWR?"  Part="1" 
AR Path="/5E933887/608AC0D4" Ref="#PWR?"  Part="1" 
AR Path="/5F8E1429/608AC0D4" Ref="#PWR?"  Part="1" 
AR Path="/608AC0D4" Ref="#PWR04"  Part="1" 
F 0 "#PWR04" H 3435 2040 50  0001 C CNN
F 1 "+3.3V" H 3450 2363 50  0000 C CNN
F 2 "" H 3435 2190 50  0001 C CNN
F 3 "" H 3435 2190 50  0001 C CNN
	1    3435 2190
	1    0    0    -1  
$EndComp
$EndSCHEMATC
