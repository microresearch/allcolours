EESchema Schematic File Version 4
LIBS:touch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2645 1120 0    118  ~ 0
Each out is mix with other input pad (no buffer, no res)
$Comp
L Amplifier_Operational:TL074 U10
U 1 1 5F0CCDFB
P 2855 2085
F 0 "U10" H 2855 2452 50  0000 C CNN
F 1 "TL074" H 2855 2361 50  0000 C CNN
F 2 "" H 2805 2185 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2905 2285 50  0001 C CNN
	1    2855 2085
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U12
U 5 1 5F0CCE41
P 4635 1955
F 0 "U12" H 4593 2001 50  0000 L CNN
F 1 "TL074" H 4593 1910 50  0000 L CNN
F 2 "" H 4585 2055 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4685 2155 50  0001 C CNN
	5    4635 1955
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR070
U 1 1 5F0CCF1C
P 2500 1985
F 0 "#PWR070" H 2500 1735 50  0001 C CNN
F 1 "GND" H 2505 1812 50  0000 C CNN
F 2 "" H 2500 1985 50  0001 C CNN
F 3 "" H 2500 1985 50  0001 C CNN
	1    2500 1985
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R27
U 1 1 5F0CCF9C
P 2390 2185
F 0 "R27" V 2194 2185 50  0000 C CNN
F 1 "10K" V 2285 2185 50  0000 C CNN
F 2 "" H 2390 2185 50  0001 C CNN
F 3 "~" H 2390 2185 50  0001 C CNN
	1    2390 2185
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R28
U 1 1 5F0CCFFF
P 2865 2350
F 0 "R28" V 2669 2350 50  0000 C CNN
F 1 "10K" V 2760 2350 50  0000 C CNN
F 2 "" H 2865 2350 50  0001 C CNN
F 3 "~" H 2865 2350 50  0001 C CNN
	1    2865 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	2500 1985 2555 1985
Wire Wire Line
	2490 2185 2520 2185
Wire Wire Line
	2290 2185 2255 2185
Wire Wire Line
	2520 2185 2520 2350
Wire Wire Line
	2520 2350 2765 2350
Connection ~ 2520 2185
Wire Wire Line
	2520 2185 2555 2185
Wire Wire Line
	2965 2350 3155 2350
Wire Wire Line
	3155 2350 3155 2085
Text GLabel 2255 2185 0    50   Input ~ 0
OUT1TOMIX
Wire Wire Line
	3155 2085 3225 2085
Connection ~ 3155 2085
Text GLabel 3225 2085 2    63   Input ~ 0
OUT1
Wire Wire Line
	2520 2350 2325 2350
Connection ~ 2520 2350
Text GLabel 2325 2350 0    59   Input ~ 0
PADOUT1
$EndSCHEMATC
