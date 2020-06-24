EESchema Schematic File Version 4
LIBS:touch-cache
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
$Comp
L 4xxx:4066 U15
U 2 1 5E97FA19
P 5255 3520
F 0 "U15" H 5255 3348 50  0000 C CNN
F 1 "4066" H 5255 3257 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5255 3520 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 5255 3520 50  0001 C CNN
	2    5255 3520
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U15
U 3 1 5E980634
P 5215 5050
F 0 "U15" H 5215 4878 50  0000 C CNN
F 1 "4066" H 5215 4787 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5215 5050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 5215 5050 50  0001 C CNN
	3    5215 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6795 685  6795 735 
Wire Wire Line
	6795 1735 6795 1785
$Comp
L power:+9V #PWR080
U 1 1 5EA0FF98
P 6795 685
F 0 "#PWR080" H 6795 535 50  0001 C CNN
F 1 "+9V" H 6810 858 50  0000 C CNN
F 2 "" H 6795 685 50  0001 C CNN
F 3 "" H 6795 685 50  0001 C CNN
	1    6795 685 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5080 1965 5080 2140
Wire Wire Line
	5680 1965 5680 2115
Wire Wire Line
	4955 3520 4955 3720
Wire Wire Line
	5555 3520 5555 3720
Wire Wire Line
	4915 5050 4915 5200
Wire Wire Line
	5515 5050 5515 5175
Wire Wire Line
	4970 6495 4970 6620
$Comp
L Regulator_Linear:LM7809_TO220 U11
U 1 1 5E9C054C
P 9380 970
F 0 "U11" H 9380 1212 50  0000 C CNN
F 1 "LM7809_TO220" H 9380 1121 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 9380 1195 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 9380 920 50  0001 C CNN
	1    9380 970 
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM7909_TO220 U14
U 1 1 5E9C079C
P 10280 945
F 0 "U14" H 10280 703 50  0000 C CNN
F 1 "LM7909_TO220" H 10280 794 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 10280 745 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7905.pdf" H 10280 945 50  0001 C CNN
	1    10280 945 
	-1   0    0    1   
$EndComp
$Comp
L power:+9V #PWR072
U 1 1 5EA276F7
P 9755 970
F 0 "#PWR072" H 9755 820 50  0001 C CNN
F 1 "+9V" H 9770 1143 50  0000 C CNN
F 2 "" H 9755 970 50  0001 C CNN
F 3 "" H 9755 970 50  0001 C CNN
	1    9755 970 
	1    0    0    -1  
$EndComp
$Comp
L power:-9V #PWR073
U 1 1 5EA277D4
P 9980 995
F 0 "#PWR073" H 9980 870 50  0001 C CNN
F 1 "-9V" H 9995 1168 50  0000 C CNN
F 2 "" H 9980 995 50  0001 C CNN
F 3 "" H 9980 995 50  0001 C CNN
	1    9980 995 
	-1   0    0    1   
$EndComp
$Comp
L power:-12V #PWR079
U 1 1 5EA27DB7
P 10580 995
F 0 "#PWR079" H 10580 1095 50  0001 C CNN
F 1 "-12V" H 10595 1168 50  0000 C CNN
F 2 "" H 10580 995 50  0001 C CNN
F 3 "" H 10580 995 50  0001 C CNN
	1    10580 995 
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR070
U 1 1 5EA27E94
P 8980 970
F 0 "#PWR070" H 8980 820 50  0001 C CNN
F 1 "+12V" H 8995 1143 50  0000 C CNN
F 2 "" H 8980 970 50  0001 C CNN
F 3 "" H 8980 970 50  0001 C CNN
	1    8980 970 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8980 970  9080 970 
Wire Wire Line
	9680 970  9755 970 
Wire Wire Line
	9380 1270 9380 1320
Wire Wire Line
	9980 945  9980 995 
Wire Wire Line
	10580 945  10580 995 
Wire Wire Line
	10280 1245 10280 1320
Wire Wire Line
	5570 6495 5570 6620
$Comp
L 4xxx:4066 U15
U 4 1 5E981A56
P 5270 6495
F 0 "U15" H 5270 6323 50  0000 C CNN
F 1 "4066" H 5270 6232 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5270 6495 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 5270 6495 50  0001 C CNN
	4    5270 6495
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR071
U 1 1 5F34370B
P 9380 1320
F 0 "#PWR071" H 9380 1070 50  0001 C CNN
F 1 "GND" H 9385 1147 50  0000 C CNN
F 2 "" H 9380 1320 50  0001 C CNN
F 3 "" H 9380 1320 50  0001 C CNN
	1    9380 1320
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR078
U 1 1 5F3437D6
P 10280 1320
F 0 "#PWR078" H 10280 1070 50  0001 C CNN
F 1 "GND" H 10285 1147 50  0000 C CNN
F 2 "" H 10280 1320 50  0001 C CNN
F 3 "" H 10280 1320 50  0001 C CNN
	1    10280 1320
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR081
U 1 1 5F34C32F
P 6795 1785
F 0 "#PWR081" H 6795 1535 50  0001 C CNN
F 1 "GND" H 6800 1612 50  0000 C CNN
F 2 "" H 6795 1785 50  0001 C CNN
F 3 "" H 6795 1785 50  0001 C CNN
	1    6795 1785
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U15
U 5 1 5F34D2EE
P 8935 2580
F 0 "U15" H 9165 2626 50  0000 L CNN
F 1 "4066" H 9165 2535 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8935 2580 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 8935 2580 50  0001 C CNN
	5    8935 2580
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR092
U 1 1 5F3533A8
P 8935 2045
F 0 "#PWR092" H 8935 1895 50  0001 C CNN
F 1 "+9V" H 8950 2218 50  0000 C CNN
F 2 "" H 8935 2045 50  0001 C CNN
F 3 "" H 8935 2045 50  0001 C CNN
	1    8935 2045
	1    0    0    -1  
$EndComp
$Comp
L power:-9V #PWR093
U 1 1 5F36257B
P 8935 3120
F 0 "#PWR093" H 8935 2995 50  0001 C CNN
F 1 "-9V" H 8950 3293 50  0000 C CNN
F 2 "" H 8935 3120 50  0001 C CNN
F 3 "" H 8935 3120 50  0001 C CNN
	1    8935 3120
	-1   0    0    1   
$EndComp
Wire Wire Line
	8935 3080 8935 3120
Wire Wire Line
	8935 2045 8935 2080
Text GLabel 5080 2140 0    79   Input ~ 0
OUT1
Text GLabel 5680 2115 2    79   Input ~ 0
OUTT1
Text GLabel 4955 3720 0    79   Input ~ 0
OUT2
Text GLabel 5555 3720 2    79   Input ~ 0
OUTT2
Text GLabel 5515 5175 2    79   Input ~ 0
OUTT3
Text GLabel 4915 5200 0    79   Input ~ 0
OUT3
Text GLabel 5570 6620 2    79   Input ~ 0
OUTT4
Text GLabel 4970 6620 0    79   Input ~ 0
OUT4
$Comp
L 4xxx:4066 U15
U 1 1 5E97D77A
P 5380 1965
F 0 "U15" H 5380 1793 50  0000 C CNN
F 1 "4066" H 5380 1702 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5380 1965 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 5380 1965 50  0001 C CNN
	1    5380 1965
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF4550C
P 1275 1470
AR Path="/5C0A69D0/5EF4550C" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF4550C" Ref="R?"  Part="1" 
AR Path="/5EF4550C" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF4550C" Ref="R49"  Part="1" 
AR Path="/5EBFD180/5EF4550C" Ref="R?"  Part="1" 
F 0 "R49" H 1334 1516 50  0000 L CNN
F 1 "1M" H 1334 1425 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1275 1470 50  0001 C CNN
F 3 "~" H 1275 1470 50  0001 C CNN
	1    1275 1470
	1    0    0    -1  
$EndComp
Wire Wire Line
	1275 1320 1275 1370
Wire Wire Line
	1275 1570 1275 1620
Wire Wire Line
	1275 1620 1300 1620
$Comp
L 4xxx:40106 U?
U 1 1 5EF45516
P 1600 1620
AR Path="/5C0A69D0/5EF45516" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EF45516" Ref="U?"  Part="1" 
AR Path="/5EF45516" Ref="U?"  Part="1" 
AR Path="/5EF10D95/5EF45516" Ref="U12"  Part="1" 
AR Path="/5EBFD180/5EF45516" Ref="U?"  Part="1" 
F 0 "U12" H 1600 1937 50  0000 C CNN
F 1 "40106" H 1600 1846 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1600 1620 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1600 1620 50  0001 C CNN
	1    1600 1620
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF4551D
P 2075 1620
AR Path="/5C0A69D0/5EF4551D" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF4551D" Ref="R?"  Part="1" 
AR Path="/5EF4551D" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF4551D" Ref="R53"  Part="1" 
AR Path="/5EBFD180/5EF4551D" Ref="R?"  Part="1" 
F 0 "R53" H 2134 1666 50  0000 L CNN
F 1 "1K" H 2134 1575 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2075 1620 50  0001 C CNN
F 3 "~" H 2075 1620 50  0001 C CNN
	1    2075 1620
	0    1    1    0   
$EndComp
Wire Wire Line
	1975 1620 1900 1620
Wire Wire Line
	2175 1620 2215 1620
Wire Wire Line
	1275 1620 1175 1620
Connection ~ 1275 1620
Text GLabel 1175 1620 0    79   Input ~ 0
TG1
Text GLabel 2215 1620 2    79   Input ~ 0
D11
$Comp
L power:+3.3V #PWR?
U 1 1 5EF4552A
P 1275 1320
AR Path="/5EBFD180/5EF4552A" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EF4552A" Ref="#PWR066"  Part="1" 
F 0 "#PWR066" H 1275 1170 50  0001 C CNN
F 1 "+3.3V" H 1290 1493 50  0000 C CNN
F 2 "" H 1275 1320 50  0001 C CNN
F 3 "" H 1275 1320 50  0001 C CNN
	1    1275 1320
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF45530
P 1300 2100
AR Path="/5C0A69D0/5EF45530" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF45530" Ref="R?"  Part="1" 
AR Path="/5EF45530" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF45530" Ref="R51"  Part="1" 
AR Path="/5EBFD180/5EF45530" Ref="R?"  Part="1" 
F 0 "R51" H 1359 2146 50  0000 L CNN
F 1 "1M" H 1359 2055 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1300 2100 50  0001 C CNN
F 3 "~" H 1300 2100 50  0001 C CNN
	1    1300 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1950 1300 2000
Wire Wire Line
	1300 2200 1300 2250
Wire Wire Line
	1300 2250 1325 2250
$Comp
L Device:R_Small R?
U 1 1 5EF4553A
P 2100 2250
AR Path="/5C0A69D0/5EF4553A" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF4553A" Ref="R?"  Part="1" 
AR Path="/5EF4553A" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF4553A" Ref="R55"  Part="1" 
AR Path="/5EBFD180/5EF4553A" Ref="R?"  Part="1" 
F 0 "R55" H 2159 2296 50  0000 L CNN
F 1 "1K" H 2159 2205 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2100 2250 50  0001 C CNN
F 3 "~" H 2100 2250 50  0001 C CNN
	1    2100 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	2000 2250 1925 2250
Wire Wire Line
	2200 2250 2240 2250
Wire Wire Line
	1300 2250 1200 2250
Connection ~ 1300 2250
Text GLabel 1200 2250 0    79   Input ~ 0
TG2
Text GLabel 2240 2250 2    79   Input ~ 0
D12
$Comp
L power:+3.3V #PWR?
U 1 1 5EF45547
P 1300 1950
AR Path="/5EBFD180/5EF45547" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EF45547" Ref="#PWR068"  Part="1" 
F 0 "#PWR068" H 1300 1800 50  0001 C CNN
F 1 "+3.3V" H 1315 2123 50  0000 C CNN
F 2 "" H 1300 1950 50  0001 C CNN
F 3 "" H 1300 1950 50  0001 C CNN
	1    1300 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF4554D
P 1275 2725
AR Path="/5C0A69D0/5EF4554D" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF4554D" Ref="R?"  Part="1" 
AR Path="/5EF4554D" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF4554D" Ref="R50"  Part="1" 
AR Path="/5EBFD180/5EF4554D" Ref="R?"  Part="1" 
F 0 "R50" H 1334 2771 50  0000 L CNN
F 1 "1M" H 1334 2680 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1275 2725 50  0001 C CNN
F 3 "~" H 1275 2725 50  0001 C CNN
	1    1275 2725
	1    0    0    -1  
$EndComp
Wire Wire Line
	1275 2575 1275 2625
Wire Wire Line
	1275 2825 1275 2875
Wire Wire Line
	1275 2875 1300 2875
$Comp
L Device:R_Small R?
U 1 1 5EF45557
P 2075 2875
AR Path="/5C0A69D0/5EF45557" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF45557" Ref="R?"  Part="1" 
AR Path="/5EF45557" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF45557" Ref="R54"  Part="1" 
AR Path="/5EBFD180/5EF45557" Ref="R?"  Part="1" 
F 0 "R54" H 2134 2921 50  0000 L CNN
F 1 "1K" H 2134 2830 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2075 2875 50  0001 C CNN
F 3 "~" H 2075 2875 50  0001 C CNN
	1    2075 2875
	0    1    1    0   
$EndComp
Wire Wire Line
	1975 2875 1900 2875
Wire Wire Line
	2175 2875 2215 2875
Wire Wire Line
	1275 2875 1175 2875
Connection ~ 1275 2875
Text GLabel 1175 2875 0    79   Input ~ 0
TG3
Text GLabel 2215 2875 2    79   Input ~ 0
D13
$Comp
L power:+3.3V #PWR?
U 1 1 5EF45564
P 1275 2575
AR Path="/5EBFD180/5EF45564" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EF45564" Ref="#PWR067"  Part="1" 
F 0 "#PWR067" H 1275 2425 50  0001 C CNN
F 1 "+3.3V" H 1290 2748 50  0000 C CNN
F 2 "" H 1275 2575 50  0001 C CNN
F 3 "" H 1275 2575 50  0001 C CNN
	1    1275 2575
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF4556A
P 1300 3355
AR Path="/5C0A69D0/5EF4556A" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF4556A" Ref="R?"  Part="1" 
AR Path="/5EF4556A" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF4556A" Ref="R52"  Part="1" 
AR Path="/5EBFD180/5EF4556A" Ref="R?"  Part="1" 
F 0 "R52" H 1359 3401 50  0000 L CNN
F 1 "1M" H 1359 3310 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1300 3355 50  0001 C CNN
F 3 "~" H 1300 3355 50  0001 C CNN
	1    1300 3355
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 3205 1300 3255
Wire Wire Line
	1300 3455 1300 3505
Wire Wire Line
	1300 3505 1325 3505
$Comp
L Device:R_Small R?
U 1 1 5EF45574
P 2100 3505
AR Path="/5C0A69D0/5EF45574" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF45574" Ref="R?"  Part="1" 
AR Path="/5EF45574" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF45574" Ref="R56"  Part="1" 
AR Path="/5EBFD180/5EF45574" Ref="R?"  Part="1" 
F 0 "R56" H 2159 3551 50  0000 L CNN
F 1 "1K" H 2159 3460 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2100 3505 50  0001 C CNN
F 3 "~" H 2100 3505 50  0001 C CNN
	1    2100 3505
	0    1    1    0   
$EndComp
Wire Wire Line
	2000 3505 1925 3505
Wire Wire Line
	2200 3505 2240 3505
Wire Wire Line
	1300 3505 1200 3505
Connection ~ 1300 3505
Text GLabel 1200 3505 0    79   Input ~ 0
TG4
Text GLabel 2240 3505 2    79   Input ~ 0
D14
$Comp
L power:+3.3V #PWR?
U 1 1 5EF45581
P 1300 3205
AR Path="/5EBFD180/5EF45581" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EF45581" Ref="#PWR069"  Part="1" 
F 0 "#PWR069" H 1300 3055 50  0001 C CNN
F 1 "+3.3V" H 1315 3378 50  0000 C CNN
F 2 "" H 1300 3205 50  0001 C CNN
F 3 "" H 1300 3205 50  0001 C CNN
	1    1300 3205
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 2 1 5EF4558B
P 1625 2250
AR Path="/5EBFD180/5EF4558B" Ref="U?"  Part="2" 
AR Path="/5EF10D95/5EF4558B" Ref="U12"  Part="2" 
F 0 "U12" H 1625 2567 50  0000 C CNN
F 1 "40106" H 1625 2476 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1625 2250 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1625 2250 50  0001 C CNN
	2    1625 2250
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 4 1 5EF45592
P 1625 3505
AR Path="/5EBFD180/5EF45592" Ref="U?"  Part="4" 
AR Path="/5EF10D95/5EF45592" Ref="U12"  Part="4" 
F 0 "U12" H 1625 3822 50  0000 C CNN
F 1 "40106" H 1625 3731 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1625 3505 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1625 3505 50  0001 C CNN
	4    1625 3505
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 3 1 5EF45599
P 1600 2875
AR Path="/5EBFD180/5EF45599" Ref="U?"  Part="3" 
AR Path="/5EF10D95/5EF45599" Ref="U12"  Part="3" 
F 0 "U12" H 1600 3192 50  0000 C CNN
F 1 "40106" H 1600 3101 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1600 2875 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1600 2875 50  0001 C CNN
	3    1600 2875
	1    0    0    -1  
$EndComp
Text Notes 1265 990  0    79   ~ 0
now digital for toggles - tested\n
$Comp
L Transistor_BJT:2N3904 Q8
U 1 1 5EF8FED5
P 4775 1735
F 0 "Q8" H 4966 1781 50  0000 L CNN
F 1 "2N3904" H 4966 1690 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4975 1660 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4775 1735 50  0001 L CNN
	1    4775 1735
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR085
U 1 1 5EF902DB
P 4875 1965
F 0 "#PWR085" H 4875 1715 50  0001 C CNN
F 1 "GND" H 4880 1792 50  0000 C CNN
F 2 "" H 4875 1965 50  0001 C CNN
F 3 "" H 4875 1965 50  0001 C CNN
	1    4875 1965
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR084
U 1 1 5EF90316
P 4875 1260
F 0 "#PWR084" H 4875 1110 50  0001 C CNN
F 1 "+9V" H 4890 1433 50  0000 C CNN
F 2 "" H 4875 1260 50  0001 C CNN
F 3 "" H 4875 1260 50  0001 C CNN
	1    4875 1260
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF90381
P 4875 1395
AR Path="/5C0A69D0/5EF90381" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF90381" Ref="R?"  Part="1" 
AR Path="/5EF90381" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF90381" Ref="R68"  Part="1" 
AR Path="/5EBFD180/5EF90381" Ref="R?"  Part="1" 
F 0 "R68" H 4934 1441 50  0000 L CNN
F 1 "10K" H 4934 1350 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4875 1395 50  0001 C CNN
F 3 "~" H 4875 1395 50  0001 C CNN
	1    4875 1395
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF9066D
P 4430 1735
AR Path="/5C0A69D0/5EF9066D" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF9066D" Ref="R?"  Part="1" 
AR Path="/5EF9066D" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF9066D" Ref="R60"  Part="1" 
AR Path="/5EBFD180/5EF9066D" Ref="R?"  Part="1" 
F 0 "R60" H 4489 1781 50  0000 L CNN
F 1 "10K" H 4489 1690 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4430 1735 50  0001 C CNN
F 3 "~" H 4430 1735 50  0001 C CNN
	1    4430 1735
	0    1    1    0   
$EndComp
Wire Wire Line
	4875 1495 4875 1515
Wire Wire Line
	4875 1260 4875 1295
Wire Wire Line
	4530 1735 4575 1735
Wire Wire Line
	4330 1735 4270 1735
Text GLabel 4270 1735 0    50   Input ~ 0
TGG1
Wire Wire Line
	4875 1935 4875 1965
$Comp
L Transistor_BJT:2N3904 Q7
U 1 1 5EF98CBA
P 4735 3310
F 0 "Q7" H 4926 3356 50  0000 L CNN
F 1 "2N3904" H 4926 3265 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4935 3235 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4735 3310 50  0001 L CNN
	1    4735 3310
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR083
U 1 1 5EF98CC1
P 4835 3540
F 0 "#PWR083" H 4835 3290 50  0001 C CNN
F 1 "GND" H 4840 3367 50  0000 C CNN
F 2 "" H 4835 3540 50  0001 C CNN
F 3 "" H 4835 3540 50  0001 C CNN
	1    4835 3540
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR082
U 1 1 5EF98CC7
P 4835 2835
F 0 "#PWR082" H 4835 2685 50  0001 C CNN
F 1 "+9V" H 4850 3008 50  0000 C CNN
F 2 "" H 4835 2835 50  0001 C CNN
F 3 "" H 4835 2835 50  0001 C CNN
	1    4835 2835
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF98CCD
P 4835 2970
AR Path="/5C0A69D0/5EF98CCD" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF98CCD" Ref="R?"  Part="1" 
AR Path="/5EF98CCD" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF98CCD" Ref="R67"  Part="1" 
AR Path="/5EBFD180/5EF98CCD" Ref="R?"  Part="1" 
F 0 "R67" H 4894 3016 50  0000 L CNN
F 1 "10K" H 4894 2925 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4835 2970 50  0001 C CNN
F 3 "~" H 4835 2970 50  0001 C CNN
	1    4835 2970
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF98CD4
P 4390 3310
AR Path="/5C0A69D0/5EF98CD4" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EF98CD4" Ref="R?"  Part="1" 
AR Path="/5EF98CD4" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF98CD4" Ref="R59"  Part="1" 
AR Path="/5EBFD180/5EF98CD4" Ref="R?"  Part="1" 
F 0 "R59" H 4449 3356 50  0000 L CNN
F 1 "10K" H 4449 3265 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4390 3310 50  0001 C CNN
F 3 "~" H 4390 3310 50  0001 C CNN
	1    4390 3310
	0    1    1    0   
$EndComp
Wire Wire Line
	4835 3070 4835 3095
Wire Wire Line
	4835 2835 4835 2870
Wire Wire Line
	4490 3310 4535 3310
Wire Wire Line
	4290 3310 4230 3310
Text GLabel 4230 3310 0    50   Input ~ 0
TGG2
Wire Wire Line
	4835 3510 4835 3540
Wire Wire Line
	4875 1515 5380 1515
Wire Wire Line
	5380 1515 5380 1665
Connection ~ 4875 1515
Wire Wire Line
	4875 1515 4875 1535
Wire Wire Line
	4835 3095 5255 3095
Wire Wire Line
	5255 3095 5255 3220
Connection ~ 4835 3095
Wire Wire Line
	4835 3095 4835 3110
$Comp
L Transistor_BJT:2N3904 Q6
U 1 1 5EFADFC7
P 4720 4775
F 0 "Q6" H 4911 4821 50  0000 L CNN
F 1 "2N3904" H 4911 4730 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4920 4700 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4720 4775 50  0001 L CNN
	1    4720 4775
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR077
U 1 1 5EFADFCE
P 4820 5005
F 0 "#PWR077" H 4820 4755 50  0001 C CNN
F 1 "GND" H 4825 4832 50  0000 C CNN
F 2 "" H 4820 5005 50  0001 C CNN
F 3 "" H 4820 5005 50  0001 C CNN
	1    4820 5005
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR076
U 1 1 5EFADFD4
P 4820 4300
F 0 "#PWR076" H 4820 4150 50  0001 C CNN
F 1 "+9V" H 4835 4473 50  0000 C CNN
F 2 "" H 4820 4300 50  0001 C CNN
F 3 "" H 4820 4300 50  0001 C CNN
	1    4820 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFADFDA
P 4820 4435
AR Path="/5C0A69D0/5EFADFDA" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EFADFDA" Ref="R?"  Part="1" 
AR Path="/5EFADFDA" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EFADFDA" Ref="R66"  Part="1" 
AR Path="/5EBFD180/5EFADFDA" Ref="R?"  Part="1" 
F 0 "R66" H 4879 4481 50  0000 L CNN
F 1 "10K" H 4879 4390 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4820 4435 50  0001 C CNN
F 3 "~" H 4820 4435 50  0001 C CNN
	1    4820 4435
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFADFE1
P 4375 4775
AR Path="/5C0A69D0/5EFADFE1" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EFADFE1" Ref="R?"  Part="1" 
AR Path="/5EFADFE1" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EFADFE1" Ref="R58"  Part="1" 
AR Path="/5EBFD180/5EFADFE1" Ref="R?"  Part="1" 
F 0 "R58" H 4434 4821 50  0000 L CNN
F 1 "10K" H 4434 4730 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4375 4775 50  0001 C CNN
F 3 "~" H 4375 4775 50  0001 C CNN
	1    4375 4775
	0    1    1    0   
$EndComp
Wire Wire Line
	4820 4535 4820 4550
Wire Wire Line
	4820 4300 4820 4335
Wire Wire Line
	4475 4775 4520 4775
Wire Wire Line
	4275 4775 4215 4775
Text GLabel 4215 4775 0    50   Input ~ 0
TGG3
Wire Wire Line
	4820 4975 4820 5005
Wire Wire Line
	4820 4550 5215 4550
Wire Wire Line
	5215 4550 5215 4750
Connection ~ 4820 4550
Wire Wire Line
	4820 4550 4820 4575
$Comp
L Transistor_BJT:2N3904 Q5
U 1 1 5EFB1345
P 4705 6140
F 0 "Q5" H 4896 6186 50  0000 L CNN
F 1 "2N3904" H 4896 6095 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4905 6065 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4705 6140 50  0001 L CNN
	1    4705 6140
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR075
U 1 1 5EFB134C
P 4805 6370
F 0 "#PWR075" H 4805 6120 50  0001 C CNN
F 1 "GND" H 4810 6197 50  0000 C CNN
F 2 "" H 4805 6370 50  0001 C CNN
F 3 "" H 4805 6370 50  0001 C CNN
	1    4805 6370
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR074
U 1 1 5EFB1352
P 4805 5665
F 0 "#PWR074" H 4805 5515 50  0001 C CNN
F 1 "+9V" H 4820 5838 50  0000 C CNN
F 2 "" H 4805 5665 50  0001 C CNN
F 3 "" H 4805 5665 50  0001 C CNN
	1    4805 5665
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFB1358
P 4805 5800
AR Path="/5C0A69D0/5EFB1358" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EFB1358" Ref="R?"  Part="1" 
AR Path="/5EFB1358" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EFB1358" Ref="R65"  Part="1" 
AR Path="/5EBFD180/5EFB1358" Ref="R?"  Part="1" 
F 0 "R65" H 4864 5846 50  0000 L CNN
F 1 "10K" H 4864 5755 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4805 5800 50  0001 C CNN
F 3 "~" H 4805 5800 50  0001 C CNN
	1    4805 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFB135F
P 4360 6140
AR Path="/5C0A69D0/5EFB135F" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EFB135F" Ref="R?"  Part="1" 
AR Path="/5EFB135F" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EFB135F" Ref="R57"  Part="1" 
AR Path="/5EBFD180/5EFB135F" Ref="R?"  Part="1" 
F 0 "R57" H 4419 6186 50  0000 L CNN
F 1 "10K" H 4419 6095 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4360 6140 50  0001 C CNN
F 3 "~" H 4360 6140 50  0001 C CNN
	1    4360 6140
	0    1    1    0   
$EndComp
Wire Wire Line
	4805 5900 4805 5925
Wire Wire Line
	4805 5665 4805 5700
Wire Wire Line
	4460 6140 4505 6140
Wire Wire Line
	4260 6140 4200 6140
Text GLabel 4200 6140 0    50   Input ~ 0
TGG4
Wire Wire Line
	4805 6340 4805 6370
Wire Wire Line
	4805 5925 5270 5925
Wire Wire Line
	5270 5925 5270 6195
Connection ~ 4805 5925
Wire Wire Line
	4805 5925 4805 5940
$Comp
L 4xxx:40106 U12
U 7 1 5EFD4662
P 6795 1235
F 0 "U12" H 7025 1281 50  0000 L CNN
F 1 "40106" H 7025 1190 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6795 1235 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 6795 1235 50  0001 C CNN
	7    6795 1235
	1    0    0    -1  
$EndComp
Text Notes 4950 935  0    79   ~ 0
test!
$Comp
L Connector_Generic:Conn_01x04 J10
U 1 1 5EF3A980
P 1245 4175
F 0 "J10" H 1325 4167 50  0000 L CNN
F 1 "Conn_01x04" H 1325 4076 50  0000 L CNN
F 2 "" H 1245 4175 50  0001 C CNN
F 3 "~" H 1245 4175 50  0001 C CNN
	1    1245 4175
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J11
U 1 1 5EF3AA7A
P 2420 4160
F 0 "J11" H 2500 4152 50  0000 L CNN
F 1 "Conn_01x04" H 2500 4061 50  0000 L CNN
F 2 "" H 2420 4160 50  0001 C CNN
F 3 "~" H 2420 4160 50  0001 C CNN
	1    2420 4160
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J12
U 1 1 5EF3AB20
P 6585 2755
F 0 "J12" H 6665 2747 50  0000 L CNN
F 1 "Conn_01x04" H 6665 2656 50  0000 L CNN
F 2 "" H 6585 2755 50  0001 C CNN
F 3 "~" H 6585 2755 50  0001 C CNN
	1    6585 2755
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J13
U 1 1 5EF3AC50
P 6600 3315
F 0 "J13" H 6680 3307 50  0000 L CNN
F 1 "Conn_01x04" H 6680 3216 50  0000 L CNN
F 2 "" H 6600 3315 50  0001 C CNN
F 3 "~" H 6600 3315 50  0001 C CNN
	1    6600 3315
	1    0    0    -1  
$EndComp
Text GLabel 1005 4075 0    39   Input ~ 0
TG1
Text GLabel 1005 4175 0    39   Input ~ 0
TG2
Text GLabel 1005 4275 0    39   Input ~ 0
TG3
Wire Wire Line
	1005 4075 1045 4075
Wire Wire Line
	1005 4175 1045 4175
Wire Wire Line
	1005 4275 1045 4275
Text GLabel 1005 4375 0    39   Input ~ 0
TG4
Wire Wire Line
	1005 4375 1045 4375
Text GLabel 6345 2655 0    39   Input ~ 0
TGG1
Text GLabel 6345 2755 0    39   Input ~ 0
TGG2
Text GLabel 6345 2855 0    39   Input ~ 0
TGG3
Wire Wire Line
	6345 2655 6385 2655
Wire Wire Line
	6345 2755 6385 2755
Wire Wire Line
	6345 2855 6385 2855
Text GLabel 6345 2955 0    39   Input ~ 0
TGG4
Wire Wire Line
	6345 2955 6385 2955
Text GLabel 2125 4060 0    39   Input ~ 0
D11
Wire Wire Line
	2125 4060 2220 4060
Text GLabel 2125 4160 0    39   Input ~ 0
D12
Wire Wire Line
	2125 4160 2220 4160
Text GLabel 2125 4260 0    39   Input ~ 0
D13
Text GLabel 2125 4360 0    39   Input ~ 0
D14
Wire Wire Line
	2125 4360 2220 4360
Wire Wire Line
	2125 4260 2220 4260
Wire Wire Line
	6400 3215 6290 3215
Text GLabel 6290 3215 0    50   Input ~ 0
OUTT1
Text GLabel 6300 3315 0    50   Input ~ 0
OUTT2
Wire Wire Line
	6300 3315 6400 3315
Wire Wire Line
	6400 3415 6290 3415
Text GLabel 6290 3415 0    50   Input ~ 0
OUTT3
Text GLabel 6300 3515 0    50   Input ~ 0
OUTT4
Wire Wire Line
	6300 3515 6400 3515
Text Notes 4635 2315 0    50   ~ 0
from 13700
Text Notes 5315 200  0    79   ~ 0
add bypass caps by hand
$Comp
L Connector_Generic:Conn_01x04 J14
U 1 1 5F37C317
P 7790 3315
F 0 "J14" H 7870 3307 50  0000 L CNN
F 1 "Conn_01x04" H 7870 3216 50  0000 L CNN
F 2 "" H 7790 3315 50  0001 C CNN
F 3 "~" H 7790 3315 50  0001 C CNN
	1    7790 3315
	1    0    0    -1  
$EndComp
Wire Wire Line
	7590 3215 7480 3215
Text GLabel 7480 3215 0    50   Input ~ 0
OUTT1
Text GLabel 7490 3315 0    50   Input ~ 0
OUTT2
Wire Wire Line
	7490 3315 7590 3315
Wire Wire Line
	7590 3415 7480 3415
Text GLabel 7480 3415 0    50   Input ~ 0
OUTT3
Text GLabel 7490 3515 0    50   Input ~ 0
OUTT4
Wire Wire Line
	7490 3515 7590 3515
Text Notes 6395 3745 0    79   ~ 0
For panel and circuits
$EndSCHEMATC
