EESchema Schematic File Version 4
LIBS:touch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L 4xxx:4013 U?
U 1 1 5E97CC51
P 2775 1175
AR Path="/5C0A69D0/5E97CC51" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E97CC51" Ref="U2"  Part="1" 
AR Path="/5E97CC51" Ref="U2"  Part="1" 
F 0 "U2" H 2775 1653 50  0000 C CNN
F 1 "4013" H 2775 1562 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2775 1175 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 2775 1175 50  0001 C CNN
	1    2775 1175
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E97CC58
P 2775 1525
AR Path="/5BAC374C/5E97CC58" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E97CC58" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E97CC58" Ref="#PWR08"  Part="1" 
AR Path="/5E97CC58" Ref="#PWR08"  Part="1" 
F 0 "#PWR08" H 2775 1275 50  0001 C CNN
F 1 "GND" H 2775 1375 50  0000 C CNN
F 2 "" H 2775 1525 50  0000 C CNN
F 3 "" H 2775 1525 50  0000 C CNN
	1    2775 1525
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5E97CC5E
P 3250 1075
AR Path="/5C0A69D0/5E97CC5E" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E97CC5E" Ref="R14"  Part="1" 
AR Path="/5E97CC5E" Ref="R14"  Part="1" 
F 0 "R14" H 3309 1121 50  0000 L CNN
F 1 "1K" H 3309 1030 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3250 1075 50  0001 C CNN
F 3 "~" H 3250 1075 50  0001 C CNN
	1    3250 1075
	0    1    1    0   
$EndComp
$Comp
L 4xxx:4013 U?
U 3 1 5E97CC65
P 8075 2675
AR Path="/5C0A69D0/5E97CC65" Ref="U?"  Part="3" 
AR Path="/5E97CA7E/5E97CC65" Ref="U9"  Part="3" 
AR Path="/5E97CC65" Ref="U9"  Part="3" 
F 0 "U9" H 8305 2721 50  0000 L CNN
F 1 "4013" H 8305 2630 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8075 2675 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 8075 2675 50  0001 C CNN
	3    8075 2675
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E97CC72
P 8075 3125
AR Path="/5BAC374C/5E97CC72" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E97CC72" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E97CC72" Ref="#PWR042"  Part="1" 
AR Path="/5E97CC72" Ref="#PWR042"  Part="1" 
F 0 "#PWR042" H 8075 2875 50  0001 C CNN
F 1 "GND" H 8075 2975 50  0000 C CNN
F 2 "" H 8075 3125 50  0000 C CNN
F 3 "" H 8075 3125 50  0000 C CNN
	1    8075 3125
	1    0    0    -1  
$EndComp
Wire Wire Line
	3075 1075 3150 1075
Wire Wire Line
	3075 1275 3250 1275
Wire Wire Line
	3250 1275 3250 825 
Wire Wire Line
	2300 825  2300 1075
Wire Wire Line
	2300 1075 2475 1075
Wire Wire Line
	2300 825  3250 825 
Wire Wire Line
	2775 1475 2775 1500
Wire Wire Line
	2450 875  2450 1500
Connection ~ 2775 1500
Wire Wire Line
	2775 1500 2775 1525
Wire Wire Line
	2450 875  2775 875 
Wire Wire Line
	8075 2225 8075 2275
Wire Wire Line
	8075 3075 8075 3125
Wire Wire Line
	2200 1175 2475 1175
Wire Wire Line
	2450 1500 2775 1500
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E97CC8F
P 8025 1875
AR Path="/5BAC374C/5E97CC8F" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E97CC8F" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E97CC8F" Ref="#PWR038"  Part="1" 
AR Path="/5E97CC8F" Ref="#PWR038"  Part="1" 
F 0 "#PWR038" H 8025 1625 50  0001 C CNN
F 1 "GND" H 8025 1725 50  0000 C CNN
F 2 "" H 8025 1875 50  0000 C CNN
F 3 "" H 8025 1875 50  0000 C CNN
	1    8025 1875
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5E97CC95
P 1300 825
AR Path="/5C0A69D0/5E97CC95" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E97CC95" Ref="R2"  Part="1" 
AR Path="/5E97CC95" Ref="R2"  Part="1" 
F 0 "R2" H 1359 871 50  0000 L CNN
F 1 "1M" H 1359 780 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1300 825 50  0001 C CNN
F 3 "~" H 1300 825 50  0001 C CNN
	1    1300 825 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 675  1300 725 
Wire Wire Line
	1300 925  1300 975 
Wire Wire Line
	1300 975  1325 975 
Wire Wire Line
	8025 775  8025 825 
Wire Wire Line
	8025 1825 8025 1875
Wire Wire Line
	2200 975  2200 1175
$Comp
L 4xxx:40106 U?
U 1 1 5E97CCA5
P 1625 975
AR Path="/5C0A69D0/5E97CCA5" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E97CCA5" Ref="U1"  Part="1" 
AR Path="/5E97CCA5" Ref="U1"  Part="1" 
F 0 "U1" H 1625 1292 50  0000 C CNN
F 1 "40106" H 1625 1201 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1625 975 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1625 975 50  0001 C CNN
	1    1625 975 
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 7 1 5E97CCB8
P 8025 1325
AR Path="/5C0A69D0/5E97CCB8" Ref="U?"  Part="7" 
AR Path="/5E97CA7E/5E97CCB8" Ref="U7"  Part="7" 
AR Path="/5E97CCB8" Ref="U7"  Part="7" 
F 0 "U7" H 8255 1371 50  0000 L CNN
F 1 "40106" H 8255 1280 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8025 1325 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 8025 1325 50  0001 C CNN
	7    8025 1325
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U5
U 1 1 5E97D77A
P 3550 1375
F 0 "U5" H 3550 1203 50  0000 C CNN
F 1 "4066" H 3550 1112 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3550 1375 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 3550 1375 50  0001 C CNN
	1    3550 1375
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1075 3550 1075
$Comp
L Device:R_Small R?
U 1 1 5E97DD93
P 2100 975
AR Path="/5C0A69D0/5E97DD93" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E97DD93" Ref="R8"  Part="1" 
AR Path="/5E97DD93" Ref="R8"  Part="1" 
F 0 "R8" H 2159 1021 50  0000 L CNN
F 1 "1K" H 2159 930 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2100 975 50  0001 C CNN
F 3 "~" H 2100 975 50  0001 C CNN
	1    2100 975 
	0    1    1    0   
$EndComp
Wire Wire Line
	2000 975  1925 975 
$Comp
L 4xxx:4013 U?
U 2 1 5E97F9D7
P 2750 2400
AR Path="/5C0A69D0/5E97F9D7" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E97F9D7" Ref="U2"  Part="2" 
AR Path="/5E97F9D7" Ref="U2"  Part="2" 
F 0 "U2" H 2750 2878 50  0000 C CNN
F 1 "4013" H 2750 2787 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2750 2400 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 2750 2400 50  0001 C CNN
	2    2750 2400
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E97F9DE
P 2750 2750
AR Path="/5BAC374C/5E97F9DE" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E97F9DE" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E97F9DE" Ref="#PWR07"  Part="1" 
AR Path="/5E97F9DE" Ref="#PWR07"  Part="1" 
F 0 "#PWR07" H 2750 2500 50  0001 C CNN
F 1 "GND" H 2750 2600 50  0000 C CNN
F 2 "" H 2750 2750 50  0000 C CNN
F 3 "" H 2750 2750 50  0000 C CNN
	1    2750 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5E97F9E4
P 3225 2300
AR Path="/5C0A69D0/5E97F9E4" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E97F9E4" Ref="R13"  Part="1" 
AR Path="/5E97F9E4" Ref="R13"  Part="1" 
F 0 "R13" H 3284 2346 50  0000 L CNN
F 1 "1K" H 3284 2255 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3225 2300 50  0001 C CNN
F 3 "~" H 3225 2300 50  0001 C CNN
	1    3225 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	3050 2300 3125 2300
Wire Wire Line
	3050 2500 3225 2500
Wire Wire Line
	3225 2500 3225 2050
Wire Wire Line
	2275 2050 2275 2300
Wire Wire Line
	2275 2300 2450 2300
Wire Wire Line
	2275 2050 3225 2050
Wire Wire Line
	2750 2700 2750 2725
Wire Wire Line
	2425 2100 2425 2725
Connection ~ 2750 2725
Wire Wire Line
	2750 2725 2750 2750
Wire Wire Line
	2425 2100 2750 2100
Wire Wire Line
	2175 2400 2450 2400
Wire Wire Line
	2425 2725 2750 2725
$Comp
L Device:R_Small R?
U 1 1 5E97FA00
P 1275 2050
AR Path="/5C0A69D0/5E97FA00" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E97FA00" Ref="R1"  Part="1" 
AR Path="/5E97FA00" Ref="R1"  Part="1" 
F 0 "R1" H 1334 2096 50  0000 L CNN
F 1 "1M" H 1334 2005 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1275 2050 50  0001 C CNN
F 3 "~" H 1275 2050 50  0001 C CNN
	1    1275 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1275 1900 1275 1950
Wire Wire Line
	1275 2150 1275 2200
Connection ~ 1275 2200
Wire Wire Line
	1275 2200 1300 2200
Wire Wire Line
	2175 2200 2175 2400
$Comp
L 4xxx:40106 U?
U 2 1 5E97FA0C
P 1600 2200
AR Path="/5C0A69D0/5E97FA0C" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E97FA0C" Ref="U1"  Part="2" 
AR Path="/5E97FA0C" Ref="U1"  Part="2" 
F 0 "U1" H 1600 2517 50  0000 C CNN
F 1 "40106" H 1600 2426 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1600 2200 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1600 2200 50  0001 C CNN
	2    1600 2200
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U5
U 2 1 5E97FA19
P 3525 2600
F 0 "U5" H 3525 2428 50  0000 C CNN
F 1 "4066" H 3525 2337 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3525 2600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 3525 2600 50  0001 C CNN
	2    3525 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3325 2300 3525 2300
$Comp
L Device:R_Small R?
U 1 1 5E97FA21
P 2075 2200
AR Path="/5C0A69D0/5E97FA21" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E97FA21" Ref="R7"  Part="1" 
AR Path="/5E97FA21" Ref="R7"  Part="1" 
F 0 "R7" H 2134 2246 50  0000 L CNN
F 1 "1K" H 2134 2155 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2075 2200 50  0001 C CNN
F 3 "~" H 2075 2200 50  0001 C CNN
	1    2075 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	1975 2200 1900 2200
$Comp
L 4xxx:4013 U?
U 1 1 5E9805F2
P 2800 3600
AR Path="/5C0A69D0/5E9805F2" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E9805F2" Ref="U3"  Part="1" 
AR Path="/5E9805F2" Ref="U3"  Part="1" 
F 0 "U3" H 2800 4078 50  0000 C CNN
F 1 "4013" H 2800 3987 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2800 3600 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 2800 3600 50  0001 C CNN
	1    2800 3600
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E9805F9
P 2800 3950
AR Path="/5BAC374C/5E9805F9" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E9805F9" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E9805F9" Ref="#PWR09"  Part="1" 
AR Path="/5E9805F9" Ref="#PWR09"  Part="1" 
F 0 "#PWR09" H 2800 3700 50  0001 C CNN
F 1 "GND" H 2800 3800 50  0000 C CNN
F 2 "" H 2800 3950 50  0000 C CNN
F 3 "" H 2800 3950 50  0000 C CNN
	1    2800 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5E9805FF
P 3275 3500
AR Path="/5C0A69D0/5E9805FF" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E9805FF" Ref="R15"  Part="1" 
AR Path="/5E9805FF" Ref="R15"  Part="1" 
F 0 "R15" H 3334 3546 50  0000 L CNN
F 1 "1K" H 3334 3455 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3275 3500 50  0001 C CNN
F 3 "~" H 3275 3500 50  0001 C CNN
	1    3275 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 3500 3175 3500
Wire Wire Line
	3100 3700 3275 3700
Wire Wire Line
	3275 3700 3275 3250
Wire Wire Line
	2325 3250 2325 3500
Wire Wire Line
	2325 3500 2500 3500
Wire Wire Line
	2325 3250 3275 3250
Wire Wire Line
	2800 3900 2800 3925
Wire Wire Line
	2475 3300 2475 3925
Connection ~ 2800 3925
Wire Wire Line
	2800 3925 2800 3950
Wire Wire Line
	2475 3300 2800 3300
Wire Wire Line
	2225 3600 2500 3600
Wire Wire Line
	2475 3925 2800 3925
$Comp
L Device:R_Small R?
U 1 1 5E98061B
P 1325 3250
AR Path="/5C0A69D0/5E98061B" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E98061B" Ref="R3"  Part="1" 
AR Path="/5E98061B" Ref="R3"  Part="1" 
F 0 "R3" H 1384 3296 50  0000 L CNN
F 1 "1M" H 1384 3205 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1325 3250 50  0001 C CNN
F 3 "~" H 1325 3250 50  0001 C CNN
	1    1325 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1325 3100 1325 3150
Wire Wire Line
	1325 3350 1325 3400
Connection ~ 1325 3400
Wire Wire Line
	1325 3400 1350 3400
Wire Wire Line
	2225 3400 2225 3600
$Comp
L 4xxx:40106 U?
U 3 1 5E980627
P 1650 3400
AR Path="/5C0A69D0/5E980627" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E980627" Ref="U1"  Part="3" 
AR Path="/5E980627" Ref="U1"  Part="3" 
F 0 "U1" H 1650 3717 50  0000 C CNN
F 1 "40106" H 1650 3626 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1650 3400 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1650 3400 50  0001 C CNN
	3    1650 3400
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U5
U 3 1 5E980634
P 3575 3800
F 0 "U5" H 3575 3628 50  0000 C CNN
F 1 "4066" H 3575 3537 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3575 3800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 3575 3800 50  0001 C CNN
	3    3575 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3375 3500 3575 3500
$Comp
L Device:R_Small R?
U 1 1 5E98063C
P 2125 3400
AR Path="/5C0A69D0/5E98063C" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E98063C" Ref="R9"  Part="1" 
AR Path="/5E98063C" Ref="R9"  Part="1" 
F 0 "R9" H 2184 3446 50  0000 L CNN
F 1 "1K" H 2184 3355 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2125 3400 50  0001 C CNN
F 3 "~" H 2125 3400 50  0001 C CNN
	1    2125 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	2025 3400 1950 3400
$Comp
L 4xxx:4013 U?
U 2 1 5E981A14
P 2800 4775
AR Path="/5C0A69D0/5E981A14" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E981A14" Ref="U3"  Part="2" 
AR Path="/5E981A14" Ref="U3"  Part="2" 
F 0 "U3" H 2800 5253 50  0000 C CNN
F 1 "4013" H 2800 5162 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2800 4775 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 2800 4775 50  0001 C CNN
	2    2800 4775
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E981A1B
P 2800 5125
AR Path="/5BAC374C/5E981A1B" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E981A1B" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E981A1B" Ref="#PWR010"  Part="1" 
AR Path="/5E981A1B" Ref="#PWR010"  Part="1" 
F 0 "#PWR010" H 2800 4875 50  0001 C CNN
F 1 "GND" H 2800 4975 50  0000 C CNN
F 2 "" H 2800 5125 50  0000 C CNN
F 3 "" H 2800 5125 50  0000 C CNN
	1    2800 5125
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5E981A21
P 3275 4675
AR Path="/5C0A69D0/5E981A21" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E981A21" Ref="R16"  Part="1" 
AR Path="/5E981A21" Ref="R16"  Part="1" 
F 0 "R16" H 3334 4721 50  0000 L CNN
F 1 "1K" H 3334 4630 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3275 4675 50  0001 C CNN
F 3 "~" H 3275 4675 50  0001 C CNN
	1    3275 4675
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 4675 3175 4675
Wire Wire Line
	3100 4875 3275 4875
Wire Wire Line
	3275 4875 3275 4425
Wire Wire Line
	2325 4425 2325 4675
Wire Wire Line
	2325 4675 2500 4675
Wire Wire Line
	2325 4425 3275 4425
Wire Wire Line
	2800 5075 2800 5100
Wire Wire Line
	2475 4475 2475 5100
Connection ~ 2800 5100
Wire Wire Line
	2800 5100 2800 5125
Wire Wire Line
	2475 4475 2800 4475
Wire Wire Line
	2225 4775 2500 4775
Wire Wire Line
	2475 5100 2800 5100
$Comp
L Device:R_Small R?
U 1 1 5E981A3D
P 1325 4425
AR Path="/5C0A69D0/5E981A3D" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E981A3D" Ref="R4"  Part="1" 
AR Path="/5E981A3D" Ref="R4"  Part="1" 
F 0 "R4" H 1384 4471 50  0000 L CNN
F 1 "1M" H 1384 4380 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1325 4425 50  0001 C CNN
F 3 "~" H 1325 4425 50  0001 C CNN
	1    1325 4425
	1    0    0    -1  
$EndComp
Wire Wire Line
	1325 4275 1325 4325
Wire Wire Line
	1325 4525 1325 4575
Wire Wire Line
	1325 4575 1350 4575
Wire Wire Line
	2225 4575 2225 4775
$Comp
L 4xxx:40106 U?
U 4 1 5E981A49
P 1650 4575
AR Path="/5C0A69D0/5E981A49" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E981A49" Ref="U1"  Part="4" 
AR Path="/5E981A49" Ref="U1"  Part="4" 
F 0 "U1" H 1650 4892 50  0000 C CNN
F 1 "40106" H 1650 4801 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1650 4575 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1650 4575 50  0001 C CNN
	4    1650 4575
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U5
U 4 1 5E981A56
P 3575 4975
F 0 "U5" H 3575 4803 50  0000 C CNN
F 1 "4066" H 3575 4712 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3575 4975 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 3575 4975 50  0001 C CNN
	4    3575 4975
	1    0    0    -1  
$EndComp
Wire Wire Line
	3375 4675 3575 4675
$Comp
L Device:R_Small R?
U 1 1 5E981A5E
P 2125 4575
AR Path="/5C0A69D0/5E981A5E" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E981A5E" Ref="R10"  Part="1" 
AR Path="/5E981A5E" Ref="R10"  Part="1" 
F 0 "R10" H 2184 4621 50  0000 L CNN
F 1 "1K" H 2184 4530 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2125 4575 50  0001 C CNN
F 3 "~" H 2125 4575 50  0001 C CNN
	1    2125 4575
	0    1    1    0   
$EndComp
Wire Wire Line
	2025 4575 1950 4575
$Comp
L 4xxx:4013 U?
U 1 1 5E983B16
P 2825 5925
AR Path="/5C0A69D0/5E983B16" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E983B16" Ref="U4"  Part="1" 
AR Path="/5E983B16" Ref="U4"  Part="1" 
F 0 "U4" H 2825 6403 50  0000 C CNN
F 1 "4013" H 2825 6312 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2825 5925 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 2825 5925 50  0001 C CNN
	1    2825 5925
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E983B1D
P 2825 6275
AR Path="/5BAC374C/5E983B1D" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E983B1D" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E983B1D" Ref="#PWR011"  Part="1" 
AR Path="/5E983B1D" Ref="#PWR011"  Part="1" 
F 0 "#PWR011" H 2825 6025 50  0001 C CNN
F 1 "GND" H 2825 6125 50  0000 C CNN
F 2 "" H 2825 6275 50  0000 C CNN
F 3 "" H 2825 6275 50  0000 C CNN
	1    2825 6275
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5E983B23
P 3300 5825
AR Path="/5C0A69D0/5E983B23" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E983B23" Ref="R17"  Part="1" 
AR Path="/5E983B23" Ref="R17"  Part="1" 
F 0 "R17" H 3359 5871 50  0000 L CNN
F 1 "1K" H 3359 5780 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3300 5825 50  0001 C CNN
F 3 "~" H 3300 5825 50  0001 C CNN
	1    3300 5825
	0    1    1    0   
$EndComp
Wire Wire Line
	3125 5825 3200 5825
Wire Wire Line
	3125 6025 3300 6025
Wire Wire Line
	3300 6025 3300 5575
Wire Wire Line
	2350 5575 2350 5825
Wire Wire Line
	2350 5825 2525 5825
Wire Wire Line
	2350 5575 3300 5575
Wire Wire Line
	2825 6225 2825 6250
Wire Wire Line
	2500 5625 2500 6250
Connection ~ 2825 6250
Wire Wire Line
	2825 6250 2825 6275
Wire Wire Line
	2500 5625 2825 5625
Wire Wire Line
	2250 5925 2525 5925
Wire Wire Line
	2500 6250 2825 6250
$Comp
L Device:R_Small R?
U 1 1 5E983B3F
P 1350 5575
AR Path="/5C0A69D0/5E983B3F" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E983B3F" Ref="R5"  Part="1" 
AR Path="/5E983B3F" Ref="R5"  Part="1" 
F 0 "R5" H 1409 5621 50  0000 L CNN
F 1 "1M" H 1409 5530 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1350 5575 50  0001 C CNN
F 3 "~" H 1350 5575 50  0001 C CNN
	1    1350 5575
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 5425 1350 5475
Wire Wire Line
	1350 5675 1350 5725
Wire Wire Line
	1350 5725 1375 5725
Wire Wire Line
	2250 5725 2250 5925
$Comp
L 4xxx:40106 U?
U 5 1 5E983B4B
P 1675 5725
AR Path="/5C0A69D0/5E983B4B" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E983B4B" Ref="U1"  Part="5" 
AR Path="/5E983B4B" Ref="U1"  Part="5" 
F 0 "U1" H 1675 6042 50  0000 C CNN
F 1 "40106" H 1675 5951 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1675 5725 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1675 5725 50  0001 C CNN
	5    1675 5725
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U6
U 1 1 5E983B58
P 3600 6125
F 0 "U6" H 3600 5953 50  0000 C CNN
F 1 "4066" H 3600 5862 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3600 6125 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 3600 6125 50  0001 C CNN
	1    3600 6125
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 5825 3600 5825
$Comp
L Device:R_Small R?
U 1 1 5E983B60
P 2150 5725
AR Path="/5C0A69D0/5E983B60" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E983B60" Ref="R11"  Part="1" 
AR Path="/5E983B60" Ref="R11"  Part="1" 
F 0 "R11" H 2209 5771 50  0000 L CNN
F 1 "1K" H 2209 5680 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2150 5725 50  0001 C CNN
F 3 "~" H 2150 5725 50  0001 C CNN
	1    2150 5725
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 5725 1975 5725
$Comp
L 4xxx:4013 U?
U 2 1 5E9875ED
P 2825 7100
AR Path="/5C0A69D0/5E9875ED" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E9875ED" Ref="U4"  Part="2" 
AR Path="/5E9875ED" Ref="U4"  Part="2" 
F 0 "U4" H 2825 7578 50  0000 C CNN
F 1 "4013" H 2825 7487 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2825 7100 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 2825 7100 50  0001 C CNN
	2    2825 7100
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E9875F4
P 2825 7450
AR Path="/5BAC374C/5E9875F4" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E9875F4" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E9875F4" Ref="#PWR012"  Part="1" 
AR Path="/5E9875F4" Ref="#PWR012"  Part="1" 
F 0 "#PWR012" H 2825 7200 50  0001 C CNN
F 1 "GND" H 2825 7300 50  0000 C CNN
F 2 "" H 2825 7450 50  0000 C CNN
F 3 "" H 2825 7450 50  0000 C CNN
	1    2825 7450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5E9875FA
P 3300 7000
AR Path="/5C0A69D0/5E9875FA" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E9875FA" Ref="R18"  Part="1" 
AR Path="/5E9875FA" Ref="R18"  Part="1" 
F 0 "R18" H 3359 7046 50  0000 L CNN
F 1 "1K" H 3359 6955 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3300 7000 50  0001 C CNN
F 3 "~" H 3300 7000 50  0001 C CNN
	1    3300 7000
	0    1    1    0   
$EndComp
Wire Wire Line
	3125 7000 3200 7000
Wire Wire Line
	3125 7200 3300 7200
Wire Wire Line
	3300 7200 3300 6750
Wire Wire Line
	2350 6750 2350 7000
Wire Wire Line
	2350 7000 2525 7000
Wire Wire Line
	2350 6750 3300 6750
Wire Wire Line
	2825 7400 2825 7425
Wire Wire Line
	2500 6800 2500 7425
Connection ~ 2825 7425
Wire Wire Line
	2825 7425 2825 7450
Wire Wire Line
	2500 6800 2825 6800
Wire Wire Line
	2250 7100 2525 7100
Wire Wire Line
	2500 7425 2825 7425
$Comp
L Device:R_Small R?
U 1 1 5E987616
P 1350 6750
AR Path="/5C0A69D0/5E987616" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E987616" Ref="R6"  Part="1" 
AR Path="/5E987616" Ref="R6"  Part="1" 
F 0 "R6" H 1409 6796 50  0000 L CNN
F 1 "1M" H 1409 6705 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1350 6750 50  0001 C CNN
F 3 "~" H 1350 6750 50  0001 C CNN
	1    1350 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 6600 1350 6650
Wire Wire Line
	1350 6850 1350 6900
Wire Wire Line
	1350 6900 1375 6900
Wire Wire Line
	2250 6900 2250 7100
$Comp
L 4xxx:40106 U?
U 6 1 5E987622
P 1675 6900
AR Path="/5C0A69D0/5E987622" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5E987622" Ref="U1"  Part="6" 
AR Path="/5E987622" Ref="U1"  Part="6" 
F 0 "U1" H 1675 7217 50  0000 C CNN
F 1 "40106" H 1675 7126 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1675 6900 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 1675 6900 50  0001 C CNN
	6    1675 6900
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U6
U 2 1 5E98762F
P 3600 7300
F 0 "U6" H 3600 7128 50  0000 C CNN
F 1 "4066" H 3600 7037 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3600 7300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 3600 7300 50  0001 C CNN
	2    3600 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 7000 3600 7000
$Comp
L Device:R_Small R?
U 1 1 5E987637
P 2150 6900
AR Path="/5C0A69D0/5E987637" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5E987637" Ref="R12"  Part="1" 
AR Path="/5E987637" Ref="R12"  Part="1" 
F 0 "R12" H 2209 6946 50  0000 L CNN
F 1 "1K" H 2209 6855 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2150 6900 50  0001 C CNN
F 3 "~" H 2150 6900 50  0001 C CNN
	1    2150 6900
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 6900 1975 6900
$Comp
L power:+9V #PWR037
U 1 1 5E998279
P 8025 775
F 0 "#PWR037" H 8025 625 50  0001 C CNN
F 1 "+9V" H 8040 948 50  0000 C CNN
F 2 "" H 8025 775 50  0001 C CNN
F 3 "" H 8025 775 50  0001 C CNN
	1    8025 775 
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR041
U 1 1 5E9983BF
P 8075 2225
F 0 "#PWR041" H 8075 2075 50  0001 C CNN
F 1 "+9V" H 8090 2398 50  0000 C CNN
F 2 "" H 8075 2225 50  0001 C CNN
F 3 "" H 8075 2225 50  0001 C CNN
	1    8075 2225
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4013 U?
U 3 1 5E998566
P 8750 2675
AR Path="/5C0A69D0/5E998566" Ref="U?"  Part="3" 
AR Path="/5E97CA7E/5E998566" Ref="U8"  Part="3" 
AR Path="/5E998566" Ref="U8"  Part="3" 
F 0 "U8" H 8980 2721 50  0000 L CNN
F 1 "4013" H 8980 2630 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8750 2675 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 8750 2675 50  0001 C CNN
	3    8750 2675
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E99856D
P 8750 3125
AR Path="/5BAC374C/5E99856D" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E99856D" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E99856D" Ref="#PWR040"  Part="1" 
AR Path="/5E99856D" Ref="#PWR040"  Part="1" 
F 0 "#PWR040" H 8750 2875 50  0001 C CNN
F 1 "GND" H 8750 2975 50  0000 C CNN
F 2 "" H 8750 3125 50  0000 C CNN
F 3 "" H 8750 3125 50  0000 C CNN
	1    8750 3125
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2225 8750 2275
Wire Wire Line
	8750 3075 8750 3125
$Comp
L power:+9V #PWR039
U 1 1 5E998575
P 8750 2225
F 0 "#PWR039" H 8750 2075 50  0001 C CNN
F 1 "+9V" H 8765 2398 50  0000 C CNN
F 2 "" H 8750 2225 50  0001 C CNN
F 3 "" H 8750 2225 50  0001 C CNN
	1    8750 2225
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4013 U?
U 3 1 5E99C6CD
P 8750 3975
AR Path="/5C0A69D0/5E99C6CD" Ref="U?"  Part="3" 
AR Path="/5E97CA7E/5E99C6CD" Ref="U10"  Part="3" 
AR Path="/5E99C6CD" Ref="U10"  Part="3" 
F 0 "U10" H 8980 4021 50  0000 L CNN
F 1 "4013" H 8980 3930 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8750 3975 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 8750 3975 50  0001 C CNN
	3    8750 3975
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5E99C6D4
P 8750 4425
AR Path="/5BAC374C/5E99C6D4" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5E99C6D4" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5E99C6D4" Ref="#PWR044"  Part="1" 
AR Path="/5E99C6D4" Ref="#PWR044"  Part="1" 
F 0 "#PWR044" H 8750 4175 50  0001 C CNN
F 1 "GND" H 8750 4275 50  0000 C CNN
F 2 "" H 8750 4425 50  0000 C CNN
F 3 "" H 8750 4425 50  0000 C CNN
	1    8750 4425
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 3525 8750 3575
Wire Wire Line
	8750 4375 8750 4425
$Comp
L power:+9V #PWR043
U 1 1 5E99C6DC
P 8750 3525
F 0 "#PWR043" H 8750 3375 50  0001 C CNN
F 1 "+9V" H 8765 3698 50  0000 C CNN
F 2 "" H 8750 3525 50  0001 C CNN
F 3 "" H 8750 3525 50  0001 C CNN
	1    8750 3525
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U11
U 5 1 5E9A4C6F
P 8525 5475
F 0 "U11" H 8755 5521 50  0000 L CNN
F 1 "4066" H 8755 5430 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8525 5475 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 8525 5475 50  0001 C CNN
	5    8525 5475
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR047
U 1 1 5E9A4C76
P 8525 4900
F 0 "#PWR047" H 8525 4750 50  0001 C CNN
F 1 "+9V" H 8540 5073 50  0000 C CNN
F 2 "" H 8525 4900 50  0001 C CNN
F 3 "" H 8525 4900 50  0001 C CNN
	1    8525 4900
	1    0    0    -1  
$EndComp
$Comp
L power:-9V #PWR048
U 1 1 5E9A4C7C
P 8525 6075
F 0 "#PWR048" H 8525 5950 50  0001 C CNN
F 1 "-9V" H 8540 6248 50  0000 C CNN
F 2 "" H 8525 6075 50  0001 C CNN
F 3 "" H 8525 6075 50  0001 C CNN
	1    8525 6075
	-1   0    0    1   
$EndComp
Wire Wire Line
	8525 4900 8525 4975
Wire Wire Line
	8525 5975 8525 6075
$Comp
L 4xxx:4013 U?
U 1 1 5EA023B7
P 5725 1200
AR Path="/5C0A69D0/5EA023B7" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA023B7" Ref="U8"  Part="1" 
AR Path="/5EA023B7" Ref="U8"  Part="1" 
F 0 "U8" H 5725 1678 50  0000 C CNN
F 1 "4013" H 5725 1587 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5725 1200 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 5725 1200 50  0001 C CNN
	1    5725 1200
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA023BE
P 5725 1550
AR Path="/5BAC374C/5EA023BE" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA023BE" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA023BE" Ref="#PWR020"  Part="1" 
AR Path="/5EA023BE" Ref="#PWR020"  Part="1" 
F 0 "#PWR020" H 5725 1300 50  0001 C CNN
F 1 "GND" H 5725 1400 50  0000 C CNN
F 2 "" H 5725 1550 50  0000 C CNN
F 3 "" H 5725 1550 50  0000 C CNN
	1    5725 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EA023C4
P 6200 1100
AR Path="/5C0A69D0/5EA023C4" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA023C4" Ref="R32"  Part="1" 
AR Path="/5EA023C4" Ref="R32"  Part="1" 
F 0 "R32" H 6259 1146 50  0000 L CNN
F 1 "1K" H 6259 1055 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6200 1100 50  0001 C CNN
F 3 "~" H 6200 1100 50  0001 C CNN
	1    6200 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	6025 1100 6100 1100
Wire Wire Line
	6025 1300 6200 1300
Wire Wire Line
	6200 1300 6200 850 
Wire Wire Line
	5250 850  5250 1100
Wire Wire Line
	5250 1100 5425 1100
Wire Wire Line
	5250 850  6200 850 
Wire Wire Line
	5725 1500 5725 1525
Wire Wire Line
	5400 900  5400 1525
Connection ~ 5725 1525
Wire Wire Line
	5725 1525 5725 1550
Wire Wire Line
	5400 900  5725 900 
Wire Wire Line
	5150 1200 5425 1200
Wire Wire Line
	5400 1525 5725 1525
$Comp
L Device:R_Small R?
U 1 1 5EA023E0
P 4250 850
AR Path="/5C0A69D0/5EA023E0" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA023E0" Ref="R20"  Part="1" 
AR Path="/5EA023E0" Ref="R20"  Part="1" 
F 0 "R20" H 4309 896 50  0000 L CNN
F 1 "1M" H 4309 805 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4250 850 50  0001 C CNN
F 3 "~" H 4250 850 50  0001 C CNN
	1    4250 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 700  4250 750 
Wire Wire Line
	4250 950  4250 1000
Wire Wire Line
	4250 1000 4275 1000
Wire Wire Line
	5150 1000 5150 1200
$Comp
L 4xxx:40106 U?
U 1 1 5EA023EC
P 4575 1000
AR Path="/5C0A69D0/5EA023EC" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA023EC" Ref="U7"  Part="1" 
AR Path="/5EA023EC" Ref="U7"  Part="1" 
F 0 "U7" H 4575 1317 50  0000 C CNN
F 1 "40106" H 4575 1226 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4575 1000 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4575 1000 50  0001 C CNN
	1    4575 1000
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U6
U 3 1 5EA023F9
P 6500 1400
F 0 "U6" H 6500 1228 50  0000 C CNN
F 1 "4066" H 6500 1137 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6500 1400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 6500 1400 50  0001 C CNN
	3    6500 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1100 6500 1100
$Comp
L Device:R_Small R?
U 1 1 5EA02401
P 5050 1000
AR Path="/5C0A69D0/5EA02401" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA02401" Ref="R26"  Part="1" 
AR Path="/5EA02401" Ref="R26"  Part="1" 
F 0 "R26" H 5109 1046 50  0000 L CNN
F 1 "1K" H 5109 955 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5050 1000 50  0001 C CNN
F 3 "~" H 5050 1000 50  0001 C CNN
	1    5050 1000
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 1000 4875 1000
$Comp
L 4xxx:4013 U?
U 2 1 5EA02409
P 5700 2425
AR Path="/5C0A69D0/5EA02409" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA02409" Ref="U8"  Part="2" 
AR Path="/5EA02409" Ref="U8"  Part="2" 
F 0 "U8" H 5700 2903 50  0000 C CNN
F 1 "4013" H 5700 2812 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5700 2425 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 5700 2425 50  0001 C CNN
	2    5700 2425
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA02410
P 5700 2775
AR Path="/5BAC374C/5EA02410" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA02410" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA02410" Ref="#PWR019"  Part="1" 
AR Path="/5EA02410" Ref="#PWR019"  Part="1" 
F 0 "#PWR019" H 5700 2525 50  0001 C CNN
F 1 "GND" H 5700 2625 50  0000 C CNN
F 2 "" H 5700 2775 50  0000 C CNN
F 3 "" H 5700 2775 50  0000 C CNN
	1    5700 2775
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EA02416
P 6175 2325
AR Path="/5C0A69D0/5EA02416" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA02416" Ref="R31"  Part="1" 
AR Path="/5EA02416" Ref="R31"  Part="1" 
F 0 "R31" H 6234 2371 50  0000 L CNN
F 1 "1K" H 6234 2280 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6175 2325 50  0001 C CNN
F 3 "~" H 6175 2325 50  0001 C CNN
	1    6175 2325
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 2325 6075 2325
Wire Wire Line
	6000 2525 6175 2525
Wire Wire Line
	6175 2525 6175 2075
Wire Wire Line
	5225 2075 5225 2325
Wire Wire Line
	5225 2325 5400 2325
Wire Wire Line
	5225 2075 6175 2075
Wire Wire Line
	5700 2725 5700 2750
Wire Wire Line
	5375 2125 5375 2750
Connection ~ 5700 2750
Wire Wire Line
	5700 2750 5700 2775
Wire Wire Line
	5375 2125 5700 2125
Wire Wire Line
	5125 2425 5400 2425
Wire Wire Line
	5375 2750 5700 2750
$Comp
L Device:R_Small R?
U 1 1 5EA02432
P 4225 2075
AR Path="/5C0A69D0/5EA02432" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA02432" Ref="R19"  Part="1" 
AR Path="/5EA02432" Ref="R19"  Part="1" 
F 0 "R19" H 4284 2121 50  0000 L CNN
F 1 "1M" H 4284 2030 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4225 2075 50  0001 C CNN
F 3 "~" H 4225 2075 50  0001 C CNN
	1    4225 2075
	1    0    0    -1  
$EndComp
Wire Wire Line
	4225 1925 4225 1975
Wire Wire Line
	4225 2175 4225 2225
Wire Wire Line
	4225 2225 4250 2225
Wire Wire Line
	5125 2225 5125 2425
$Comp
L 4xxx:40106 U?
U 2 1 5EA0243E
P 4550 2225
AR Path="/5C0A69D0/5EA0243E" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA0243E" Ref="U7"  Part="2" 
AR Path="/5EA0243E" Ref="U7"  Part="2" 
F 0 "U7" H 4550 2542 50  0000 C CNN
F 1 "40106" H 4550 2451 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4550 2225 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4550 2225 50  0001 C CNN
	2    4550 2225
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U6
U 4 1 5EA0244B
P 6475 2625
F 0 "U6" H 6475 2453 50  0000 C CNN
F 1 "4066" H 6475 2362 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6475 2625 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 6475 2625 50  0001 C CNN
	4    6475 2625
	1    0    0    -1  
$EndComp
Wire Wire Line
	6275 2325 6475 2325
$Comp
L Device:R_Small R?
U 1 1 5EA02453
P 5025 2225
AR Path="/5C0A69D0/5EA02453" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA02453" Ref="R25"  Part="1" 
AR Path="/5EA02453" Ref="R25"  Part="1" 
F 0 "R25" H 5084 2271 50  0000 L CNN
F 1 "1K" H 5084 2180 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5025 2225 50  0001 C CNN
F 3 "~" H 5025 2225 50  0001 C CNN
	1    5025 2225
	0    1    1    0   
$EndComp
Wire Wire Line
	4925 2225 4850 2225
$Comp
L 4xxx:4013 U?
U 1 1 5EA0245B
P 5750 3625
AR Path="/5C0A69D0/5EA0245B" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA0245B" Ref="U9"  Part="1" 
AR Path="/5EA0245B" Ref="U9"  Part="1" 
F 0 "U9" H 5750 4103 50  0000 C CNN
F 1 "4013" H 5750 4012 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5750 3625 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 5750 3625 50  0001 C CNN
	1    5750 3625
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA02462
P 5750 3975
AR Path="/5BAC374C/5EA02462" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA02462" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA02462" Ref="#PWR021"  Part="1" 
AR Path="/5EA02462" Ref="#PWR021"  Part="1" 
F 0 "#PWR021" H 5750 3725 50  0001 C CNN
F 1 "GND" H 5750 3825 50  0000 C CNN
F 2 "" H 5750 3975 50  0000 C CNN
F 3 "" H 5750 3975 50  0000 C CNN
	1    5750 3975
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EA02468
P 6225 3525
AR Path="/5C0A69D0/5EA02468" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA02468" Ref="R33"  Part="1" 
AR Path="/5EA02468" Ref="R33"  Part="1" 
F 0 "R33" H 6284 3571 50  0000 L CNN
F 1 "1K" H 6284 3480 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6225 3525 50  0001 C CNN
F 3 "~" H 6225 3525 50  0001 C CNN
	1    6225 3525
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 3525 6125 3525
Wire Wire Line
	6050 3725 6225 3725
Wire Wire Line
	6225 3725 6225 3275
Wire Wire Line
	5275 3275 5275 3525
Wire Wire Line
	5275 3525 5450 3525
Wire Wire Line
	5275 3275 6225 3275
Wire Wire Line
	5750 3925 5750 3950
Wire Wire Line
	5425 3325 5425 3950
Connection ~ 5750 3950
Wire Wire Line
	5750 3950 5750 3975
Wire Wire Line
	5425 3325 5750 3325
Wire Wire Line
	5175 3625 5450 3625
Wire Wire Line
	5425 3950 5750 3950
$Comp
L Device:R_Small R?
U 1 1 5EA02484
P 4275 3275
AR Path="/5C0A69D0/5EA02484" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA02484" Ref="R21"  Part="1" 
AR Path="/5EA02484" Ref="R21"  Part="1" 
F 0 "R21" H 4334 3321 50  0000 L CNN
F 1 "1M" H 4334 3230 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4275 3275 50  0001 C CNN
F 3 "~" H 4275 3275 50  0001 C CNN
	1    4275 3275
	1    0    0    -1  
$EndComp
Wire Wire Line
	4275 3125 4275 3175
Wire Wire Line
	4275 3375 4275 3425
Wire Wire Line
	4275 3425 4300 3425
Wire Wire Line
	5175 3425 5175 3625
$Comp
L 4xxx:40106 U?
U 3 1 5EA02490
P 4600 3425
AR Path="/5C0A69D0/5EA02490" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA02490" Ref="U7"  Part="3" 
AR Path="/5EA02490" Ref="U7"  Part="3" 
F 0 "U7" H 4600 3742 50  0000 C CNN
F 1 "40106" H 4600 3651 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4600 3425 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4600 3425 50  0001 C CNN
	3    4600 3425
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U11
U 1 1 5EA0249D
P 6525 3825
F 0 "U11" H 6525 3653 50  0000 C CNN
F 1 "4066" H 6525 3562 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6525 3825 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 6525 3825 50  0001 C CNN
	1    6525 3825
	1    0    0    -1  
$EndComp
Wire Wire Line
	6325 3525 6525 3525
$Comp
L Device:R_Small R?
U 1 1 5EA024A5
P 5075 3425
AR Path="/5C0A69D0/5EA024A5" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA024A5" Ref="R27"  Part="1" 
AR Path="/5EA024A5" Ref="R27"  Part="1" 
F 0 "R27" H 5134 3471 50  0000 L CNN
F 1 "1K" H 5134 3380 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5075 3425 50  0001 C CNN
F 3 "~" H 5075 3425 50  0001 C CNN
	1    5075 3425
	0    1    1    0   
$EndComp
Wire Wire Line
	4975 3425 4900 3425
$Comp
L 4xxx:4013 U?
U 2 1 5EA024AD
P 5750 4800
AR Path="/5C0A69D0/5EA024AD" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA024AD" Ref="U9"  Part="2" 
AR Path="/5EA024AD" Ref="U9"  Part="2" 
F 0 "U9" H 5750 5278 50  0000 C CNN
F 1 "4013" H 5750 5187 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5750 4800 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 5750 4800 50  0001 C CNN
	2    5750 4800
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA024B4
P 5750 5150
AR Path="/5BAC374C/5EA024B4" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA024B4" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA024B4" Ref="#PWR022"  Part="1" 
AR Path="/5EA024B4" Ref="#PWR022"  Part="1" 
F 0 "#PWR022" H 5750 4900 50  0001 C CNN
F 1 "GND" H 5750 5000 50  0000 C CNN
F 2 "" H 5750 5150 50  0000 C CNN
F 3 "" H 5750 5150 50  0000 C CNN
	1    5750 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EA024BA
P 6225 4700
AR Path="/5C0A69D0/5EA024BA" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA024BA" Ref="R34"  Part="1" 
AR Path="/5EA024BA" Ref="R34"  Part="1" 
F 0 "R34" H 6284 4746 50  0000 L CNN
F 1 "1K" H 6284 4655 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6225 4700 50  0001 C CNN
F 3 "~" H 6225 4700 50  0001 C CNN
	1    6225 4700
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 4700 6125 4700
Wire Wire Line
	6050 4900 6225 4900
Wire Wire Line
	6225 4900 6225 4450
Wire Wire Line
	5275 4450 5275 4700
Wire Wire Line
	5275 4700 5450 4700
Wire Wire Line
	5275 4450 6225 4450
Wire Wire Line
	5750 5100 5750 5125
Wire Wire Line
	5425 4500 5425 5125
Connection ~ 5750 5125
Wire Wire Line
	5750 5125 5750 5150
Wire Wire Line
	5425 4500 5750 4500
Wire Wire Line
	5175 4800 5450 4800
Wire Wire Line
	5425 5125 5750 5125
$Comp
L Device:R_Small R?
U 1 1 5EA024D6
P 4275 4450
AR Path="/5C0A69D0/5EA024D6" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA024D6" Ref="R22"  Part="1" 
AR Path="/5EA024D6" Ref="R22"  Part="1" 
F 0 "R22" H 4334 4496 50  0000 L CNN
F 1 "1M" H 4334 4405 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4275 4450 50  0001 C CNN
F 3 "~" H 4275 4450 50  0001 C CNN
	1    4275 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4275 4300 4275 4350
Wire Wire Line
	4275 4550 4275 4600
Wire Wire Line
	4275 4600 4300 4600
Wire Wire Line
	5175 4600 5175 4800
$Comp
L 4xxx:40106 U?
U 4 1 5EA024E2
P 4600 4600
AR Path="/5C0A69D0/5EA024E2" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA024E2" Ref="U7"  Part="4" 
AR Path="/5EA024E2" Ref="U7"  Part="4" 
F 0 "U7" H 4600 4917 50  0000 C CNN
F 1 "40106" H 4600 4826 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4600 4600 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4600 4600 50  0001 C CNN
	4    4600 4600
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U11
U 2 1 5EA024EF
P 6525 5000
F 0 "U11" H 6525 4828 50  0000 C CNN
F 1 "4066" H 6525 4737 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6525 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 6525 5000 50  0001 C CNN
	2    6525 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6325 4700 6525 4700
$Comp
L Device:R_Small R?
U 1 1 5EA024F7
P 5075 4600
AR Path="/5C0A69D0/5EA024F7" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA024F7" Ref="R28"  Part="1" 
AR Path="/5EA024F7" Ref="R28"  Part="1" 
F 0 "R28" H 5134 4646 50  0000 L CNN
F 1 "1K" H 5134 4555 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5075 4600 50  0001 C CNN
F 3 "~" H 5075 4600 50  0001 C CNN
	1    5075 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	4975 4600 4900 4600
$Comp
L 4xxx:4013 U?
U 1 1 5EA024FF
P 5775 5950
AR Path="/5C0A69D0/5EA024FF" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA024FF" Ref="U10"  Part="1" 
AR Path="/5EA024FF" Ref="U10"  Part="1" 
F 0 "U10" H 5775 6428 50  0000 C CNN
F 1 "4013" H 5775 6337 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5775 5950 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 5775 5950 50  0001 C CNN
	1    5775 5950
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA02506
P 5775 6300
AR Path="/5BAC374C/5EA02506" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA02506" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA02506" Ref="#PWR023"  Part="1" 
AR Path="/5EA02506" Ref="#PWR023"  Part="1" 
F 0 "#PWR023" H 5775 6050 50  0001 C CNN
F 1 "GND" H 5775 6150 50  0000 C CNN
F 2 "" H 5775 6300 50  0000 C CNN
F 3 "" H 5775 6300 50  0000 C CNN
	1    5775 6300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EA0250C
P 6250 5850
AR Path="/5C0A69D0/5EA0250C" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA0250C" Ref="R35"  Part="1" 
AR Path="/5EA0250C" Ref="R35"  Part="1" 
F 0 "R35" H 6309 5896 50  0000 L CNN
F 1 "1K" H 6309 5805 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6250 5850 50  0001 C CNN
F 3 "~" H 6250 5850 50  0001 C CNN
	1    6250 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	6075 5850 6150 5850
Wire Wire Line
	6075 6050 6250 6050
Wire Wire Line
	6250 6050 6250 5600
Wire Wire Line
	5300 5600 5300 5850
Wire Wire Line
	5300 5850 5475 5850
Wire Wire Line
	5300 5600 6250 5600
Wire Wire Line
	5775 6250 5775 6275
Wire Wire Line
	5450 5650 5450 6275
Connection ~ 5775 6275
Wire Wire Line
	5775 6275 5775 6300
Wire Wire Line
	5450 5650 5775 5650
Wire Wire Line
	5200 5950 5475 5950
Wire Wire Line
	5450 6275 5775 6275
$Comp
L Device:R_Small R?
U 1 1 5EA02528
P 4300 5600
AR Path="/5C0A69D0/5EA02528" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA02528" Ref="R23"  Part="1" 
AR Path="/5EA02528" Ref="R23"  Part="1" 
F 0 "R23" H 4359 5646 50  0000 L CNN
F 1 "1M" H 4359 5555 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4300 5600 50  0001 C CNN
F 3 "~" H 4300 5600 50  0001 C CNN
	1    4300 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5450 4300 5500
Wire Wire Line
	4300 5700 4300 5750
Wire Wire Line
	4300 5750 4325 5750
Wire Wire Line
	5200 5750 5200 5950
$Comp
L 4xxx:40106 U?
U 5 1 5EA02534
P 4625 5750
AR Path="/5C0A69D0/5EA02534" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA02534" Ref="U7"  Part="5" 
AR Path="/5EA02534" Ref="U7"  Part="5" 
F 0 "U7" H 4625 6067 50  0000 C CNN
F 1 "40106" H 4625 5976 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4625 5750 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4625 5750 50  0001 C CNN
	5    4625 5750
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U11
U 3 1 5EA02541
P 6550 6150
F 0 "U11" H 6550 5978 50  0000 C CNN
F 1 "4066" H 6550 5887 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6550 6150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 6550 6150 50  0001 C CNN
	3    6550 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5850 6550 5850
$Comp
L Device:R_Small R?
U 1 1 5EA02549
P 5100 5750
AR Path="/5C0A69D0/5EA02549" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA02549" Ref="R29"  Part="1" 
AR Path="/5EA02549" Ref="R29"  Part="1" 
F 0 "R29" H 5159 5796 50  0000 L CNN
F 1 "1K" H 5159 5705 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5100 5750 50  0001 C CNN
F 3 "~" H 5100 5750 50  0001 C CNN
	1    5100 5750
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 5750 4925 5750
$Comp
L 4xxx:4013 U?
U 2 1 5EA02551
P 5775 7125
AR Path="/5C0A69D0/5EA02551" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA02551" Ref="U10"  Part="2" 
AR Path="/5EA02551" Ref="U10"  Part="2" 
F 0 "U10" H 5775 7603 50  0000 C CNN
F 1 "4013" H 5775 7512 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5775 7125 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 5775 7125 50  0001 C CNN
	2    5775 7125
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA02558
P 5775 7475
AR Path="/5BAC374C/5EA02558" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA02558" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA02558" Ref="#PWR024"  Part="1" 
AR Path="/5EA02558" Ref="#PWR024"  Part="1" 
F 0 "#PWR024" H 5775 7225 50  0001 C CNN
F 1 "GND" H 5775 7325 50  0000 C CNN
F 2 "" H 5775 7475 50  0000 C CNN
F 3 "" H 5775 7475 50  0000 C CNN
	1    5775 7475
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EA0255E
P 6250 7025
AR Path="/5C0A69D0/5EA0255E" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA0255E" Ref="R36"  Part="1" 
AR Path="/5EA0255E" Ref="R36"  Part="1" 
F 0 "R36" H 6309 7071 50  0000 L CNN
F 1 "1K" H 6309 6980 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6250 7025 50  0001 C CNN
F 3 "~" H 6250 7025 50  0001 C CNN
	1    6250 7025
	0    1    1    0   
$EndComp
Wire Wire Line
	6075 7025 6150 7025
Wire Wire Line
	6075 7225 6250 7225
Wire Wire Line
	6250 7225 6250 6775
Wire Wire Line
	5300 6775 5300 7025
Wire Wire Line
	5300 7025 5475 7025
Wire Wire Line
	5300 6775 6250 6775
Wire Wire Line
	5775 7425 5775 7450
Wire Wire Line
	5450 6825 5450 7450
Connection ~ 5775 7450
Wire Wire Line
	5775 7450 5775 7475
Wire Wire Line
	5450 6825 5775 6825
Wire Wire Line
	5200 7125 5475 7125
Wire Wire Line
	5450 7450 5775 7450
$Comp
L Device:R_Small R?
U 1 1 5EA0257A
P 4300 6775
AR Path="/5C0A69D0/5EA0257A" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA0257A" Ref="R24"  Part="1" 
AR Path="/5EA0257A" Ref="R24"  Part="1" 
F 0 "R24" H 4359 6821 50  0000 L CNN
F 1 "1M" H 4359 6730 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4300 6775 50  0001 C CNN
F 3 "~" H 4300 6775 50  0001 C CNN
	1    4300 6775
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 6625 4300 6675
Wire Wire Line
	4300 6875 4300 6925
Wire Wire Line
	4300 6925 4325 6925
Wire Wire Line
	5200 6925 5200 7125
$Comp
L 4xxx:40106 U?
U 6 1 5EA02586
P 4625 6925
AR Path="/5C0A69D0/5EA02586" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5EA02586" Ref="U7"  Part="6" 
AR Path="/5EA02586" Ref="U7"  Part="6" 
F 0 "U7" H 4625 7242 50  0000 C CNN
F 1 "40106" H 4625 7151 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4625 6925 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4625 6925 50  0001 C CNN
	6    4625 6925
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U11
U 4 1 5EA02593
P 6550 7325
F 0 "U11" H 6550 7153 50  0000 C CNN
F 1 "4066" H 6550 7062 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6550 7325 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 6550 7325 50  0001 C CNN
	4    6550 7325
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 7025 6550 7025
$Comp
L Device:R_Small R?
U 1 1 5EA0259B
P 5100 6925
AR Path="/5C0A69D0/5EA0259B" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5EA0259B" Ref="R30"  Part="1" 
AR Path="/5EA0259B" Ref="R30"  Part="1" 
F 0 "R30" H 5159 6971 50  0000 L CNN
F 1 "1K" H 5159 6880 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5100 6925 50  0001 C CNN
F 3 "~" H 5100 6925 50  0001 C CNN
	1    5100 6925
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 6925 4925 6925
$Comp
L 4xxx:4013 U?
U 3 1 5EA0FF65
P 7400 2675
AR Path="/5C0A69D0/5EA0FF65" Ref="U?"  Part="3" 
AR Path="/5E97CA7E/5EA0FF65" Ref="U3"  Part="3" 
AR Path="/5EA0FF65" Ref="U3"  Part="3" 
F 0 "U3" H 7630 2721 50  0000 L CNN
F 1 "4013" H 7630 2630 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 7400 2675 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 7400 2675 50  0001 C CNN
	3    7400 2675
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA0FF6C
P 7400 3125
AR Path="/5BAC374C/5EA0FF6C" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA0FF6C" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA0FF6C" Ref="#PWR030"  Part="1" 
AR Path="/5EA0FF6C" Ref="#PWR030"  Part="1" 
F 0 "#PWR030" H 7400 2875 50  0001 C CNN
F 1 "GND" H 7400 2975 50  0000 C CNN
F 2 "" H 7400 3125 50  0000 C CNN
F 3 "" H 7400 3125 50  0000 C CNN
	1    7400 3125
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2225 7400 2275
Wire Wire Line
	7400 3075 7400 3125
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA0FF74
P 7400 1850
AR Path="/5BAC374C/5EA0FF74" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA0FF74" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA0FF74" Ref="#PWR026"  Part="1" 
AR Path="/5EA0FF74" Ref="#PWR026"  Part="1" 
F 0 "#PWR026" H 7400 1600 50  0001 C CNN
F 1 "GND" H 7400 1700 50  0000 C CNN
F 2 "" H 7400 1850 50  0000 C CNN
F 3 "" H 7400 1850 50  0000 C CNN
	1    7400 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 750  7400 800 
Wire Wire Line
	7400 1800 7400 1850
$Comp
L 4xxx:40106 U?
U 7 1 5EA0FF7C
P 7400 1300
AR Path="/5C0A69D0/5EA0FF7C" Ref="U?"  Part="7" 
AR Path="/5E97CA7E/5EA0FF7C" Ref="U1"  Part="7" 
AR Path="/5EA0FF7C" Ref="U1"  Part="7" 
F 0 "U1" H 7630 1346 50  0000 L CNN
F 1 "40106" H 7630 1255 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 7400 1300 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 7400 1300 50  0001 C CNN
	7    7400 1300
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U5
U 5 1 5EA0FF83
P 7300 5450
F 0 "U5" H 7530 5496 50  0000 L CNN
F 1 "4066" H 7530 5405 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 7300 5450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 7300 5450 50  0001 C CNN
	5    7300 5450
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR033
U 1 1 5EA0FF8A
P 7300 4875
F 0 "#PWR033" H 7300 4725 50  0001 C CNN
F 1 "+9V" H 7315 5048 50  0000 C CNN
F 2 "" H 7300 4875 50  0001 C CNN
F 3 "" H 7300 4875 50  0001 C CNN
	1    7300 4875
	1    0    0    -1  
$EndComp
$Comp
L power:-9V #PWR034
U 1 1 5EA0FF90
P 7300 6050
F 0 "#PWR034" H 7300 5925 50  0001 C CNN
F 1 "-9V" H 7315 6223 50  0000 C CNN
F 2 "" H 7300 6050 50  0001 C CNN
F 3 "" H 7300 6050 50  0001 C CNN
	1    7300 6050
	-1   0    0    1   
$EndComp
Wire Wire Line
	7300 4875 7300 4950
Wire Wire Line
	7300 5950 7300 6050
$Comp
L power:+9V #PWR025
U 1 1 5EA0FF98
P 7400 750
F 0 "#PWR025" H 7400 600 50  0001 C CNN
F 1 "+9V" H 7415 923 50  0000 C CNN
F 2 "" H 7400 750 50  0001 C CNN
F 3 "" H 7400 750 50  0001 C CNN
	1    7400 750 
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR029
U 1 1 5EA0FF9E
P 7400 2225
F 0 "#PWR029" H 7400 2075 50  0001 C CNN
F 1 "+9V" H 7415 2398 50  0000 C CNN
F 2 "" H 7400 2225 50  0001 C CNN
F 3 "" H 7400 2225 50  0001 C CNN
	1    7400 2225
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4013 U?
U 3 1 5EA0FFA4
P 7375 4000
AR Path="/5C0A69D0/5EA0FFA4" Ref="U?"  Part="3" 
AR Path="/5E97CA7E/5EA0FFA4" Ref="U2"  Part="3" 
AR Path="/5EA0FFA4" Ref="U2"  Part="3" 
F 0 "U2" H 7605 4046 50  0000 L CNN
F 1 "4013" H 7605 3955 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 7375 4000 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 7375 4000 50  0001 C CNN
	3    7375 4000
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA0FFAB
P 7375 4450
AR Path="/5BAC374C/5EA0FFAB" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA0FFAB" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA0FFAB" Ref="#PWR028"  Part="1" 
AR Path="/5EA0FFAB" Ref="#PWR028"  Part="1" 
F 0 "#PWR028" H 7375 4200 50  0001 C CNN
F 1 "GND" H 7375 4300 50  0000 C CNN
F 2 "" H 7375 4450 50  0000 C CNN
F 3 "" H 7375 4450 50  0000 C CNN
	1    7375 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7375 3550 7375 3600
Wire Wire Line
	7375 4400 7375 4450
$Comp
L power:+9V #PWR027
U 1 1 5EA0FFB3
P 7375 3550
F 0 "#PWR027" H 7375 3400 50  0001 C CNN
F 1 "+9V" H 7390 3723 50  0000 C CNN
F 2 "" H 7375 3550 50  0001 C CNN
F 3 "" H 7375 3550 50  0001 C CNN
	1    7375 3550
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4013 U?
U 3 1 5EA0FFB9
P 8100 4000
AR Path="/5C0A69D0/5EA0FFB9" Ref="U?"  Part="3" 
AR Path="/5E97CA7E/5EA0FFB9" Ref="U4"  Part="3" 
AR Path="/5EA0FFB9" Ref="U4"  Part="3" 
F 0 "U4" H 8330 4046 50  0000 L CNN
F 1 "4013" H 8330 3955 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8100 4000 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/MC14013B-D.PDF" H 8100 4000 50  0001 C CNN
	3    8100 4000
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA0FFC0
P 8100 4450
AR Path="/5BAC374C/5EA0FFC0" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA0FFC0" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA0FFC0" Ref="#PWR032"  Part="1" 
AR Path="/5EA0FFC0" Ref="#PWR032"  Part="1" 
F 0 "#PWR032" H 8100 4200 50  0001 C CNN
F 1 "GND" H 8100 4300 50  0000 C CNN
F 2 "" H 8100 4450 50  0000 C CNN
F 3 "" H 8100 4450 50  0000 C CNN
	1    8100 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3550 8100 3600
Wire Wire Line
	8100 4400 8100 4450
$Comp
L power:+9V #PWR031
U 1 1 5EA0FFC8
P 8100 3550
F 0 "#PWR031" H 8100 3400 50  0001 C CNN
F 1 "+9V" H 8115 3723 50  0000 C CNN
F 2 "" H 8100 3550 50  0001 C CNN
F 3 "" H 8100 3550 50  0001 C CNN
	1    8100 3550
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U6
U 5 1 5EA0FFCE
P 7900 5450
F 0 "U6" H 8130 5496 50  0000 L CNN
F 1 "4066" H 8130 5405 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 7900 5450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 7900 5450 50  0001 C CNN
	5    7900 5450
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR035
U 1 1 5EA0FFD5
P 7900 4875
F 0 "#PWR035" H 7900 4725 50  0001 C CNN
F 1 "+9V" H 7915 5048 50  0000 C CNN
F 2 "" H 7900 4875 50  0001 C CNN
F 3 "" H 7900 4875 50  0001 C CNN
	1    7900 4875
	1    0    0    -1  
$EndComp
$Comp
L power:-9V #PWR036
U 1 1 5EA0FFDB
P 7900 6050
F 0 "#PWR036" H 7900 5925 50  0001 C CNN
F 1 "-9V" H 7915 6223 50  0000 C CNN
F 2 "" H 7900 6050 50  0001 C CNN
F 3 "" H 7900 6050 50  0001 C CNN
	1    7900 6050
	-1   0    0    1   
$EndComp
Wire Wire Line
	7900 4875 7900 4950
Wire Wire Line
	7900 5950 7900 6050
Wire Wire Line
	3250 1375 3250 1550
Text Label 3250 1550 0    50   ~ 0
S1
Wire Wire Line
	3850 1375 3850 1525
Text Label 3850 1525 0    50   ~ 0
SS1
Wire Wire Line
	3225 2600 3225 2800
Text Label 3225 2800 0    50   ~ 0
S2
Wire Wire Line
	3825 2600 3825 2800
Text Label 3825 2800 0    50   ~ 0
SS2
Wire Wire Line
	3275 3800 3275 3950
Text Label 3275 3950 0    50   ~ 0
S3
Wire Wire Line
	3875 3800 3875 3925
Text Label 3875 3925 0    50   ~ 0
SS3
Wire Wire Line
	3275 4975 3275 5100
Text Label 3275 5100 0    50   ~ 0
S4
Wire Wire Line
	3875 4975 3875 5100
Text Label 3875 5100 0    50   ~ 0
SS4
Wire Wire Line
	3300 6125 3300 6225
Text Label 3300 6225 0    50   ~ 0
S5
Wire Wire Line
	3900 6125 3900 6225
Text Label 3900 6225 0    50   ~ 0
SS5
Wire Wire Line
	3300 7300 3300 7450
Text Label 3300 7450 0    50   ~ 0
S6
Wire Wire Line
	3900 7300 3900 7425
Text Label 3900 7425 0    50   ~ 0
SS6
Wire Wire Line
	6200 1400 6200 1500
Text Label 6200 1500 0    50   ~ 0
S7
Wire Wire Line
	6800 1400 6800 1500
Text Label 6800 1500 0    50   ~ 0
SS7
Wire Wire Line
	6175 2625 6175 2725
Text Label 6175 2725 0    50   ~ 0
S8
Wire Wire Line
	6775 2625 6775 2725
Text Label 6775 2725 0    50   ~ 0
SS8
Wire Wire Line
	6225 3825 6225 3975
Text Label 6225 3975 0    50   ~ 0
S9
Wire Wire Line
	6825 3825 6825 3975
Text Label 6825 3975 0    50   ~ 0
SS9
Wire Wire Line
	6225 5000 6225 5150
Text Label 6225 5150 0    50   ~ 0
S10
Wire Wire Line
	6825 5000 6825 5125
Text Label 6825 5125 0    50   ~ 0
SS10
Wire Wire Line
	6250 6150 6250 6275
Text Label 6250 6275 0    50   ~ 0
S11
Wire Wire Line
	6850 6150 6850 6250
Text Label 6850 6250 0    50   ~ 0
SS11
Wire Wire Line
	6250 7325 6250 7525
Text Label 6250 7525 0    50   ~ 0
S12
Wire Wire Line
	6850 7325 6850 7500
Text Label 6850 7500 0    50   ~ 0
SS12
Wire Wire Line
	11725 2725 11525 2725
Text Label 11525 2725 0    50   ~ 0
S1
Wire Wire Line
	11725 2625 11525 2625
Text Label 11525 2625 0    50   ~ 0
SS1
Wire Wire Line
	11725 2525 11525 2525
Text Label 11525 2525 0    50   ~ 0
S2
Text Label 11525 2425 0    50   ~ 0
SS2
Wire Wire Line
	11525 2425 11725 2425
Wire Wire Line
	11725 2325 11525 2325
Text Label 11525 2325 0    50   ~ 0
S3
Wire Wire Line
	11725 2225 11525 2225
Text Label 11525 2225 0    50   ~ 0
SS3
Wire Wire Line
	11725 2125 11525 2125
Text Label 11525 2125 0    50   ~ 0
S4
Wire Wire Line
	11725 2025 11525 2025
Text Label 11525 2025 0    50   ~ 0
SS4
Wire Wire Line
	11725 1925 11550 1925
Text Label 11550 1925 0    50   ~ 0
S5
Wire Wire Line
	11725 1825 11550 1825
Text Label 11550 1825 0    50   ~ 0
SS5
Wire Wire Line
	11725 1725 11550 1725
Text Label 11550 1725 0    50   ~ 0
S6
Wire Wire Line
	11725 1625 11550 1625
Text Label 11550 1625 0    50   ~ 0
SS6
Wire Wire Line
	11725 1525 11550 1525
Text Label 11550 1525 0    50   ~ 0
S7
Wire Wire Line
	11725 1425 11550 1425
Text Label 11550 1425 0    50   ~ 0
SS7
Wire Wire Line
	11725 1325 11550 1325
Text Label 11550 1325 0    50   ~ 0
S8
Wire Wire Line
	11725 1225 11550 1225
Text Label 11550 1225 0    50   ~ 0
SS8
Wire Wire Line
	11725 1125 11550 1125
Text Label 11550 1125 0    50   ~ 0
S9
Wire Wire Line
	11725 1025 11575 1025
Text Label 11575 1025 0    50   ~ 0
SS9
Wire Wire Line
	11725 925  11550 925 
Text Label 11550 925  0    50   ~ 0
S10
Wire Wire Line
	11725 825  11550 825 
Text Label 11550 825  0    50   ~ 0
SS10
Wire Wire Line
	11725 725  11575 725 
Text Label 11575 725  0    50   ~ 0
S11
Wire Wire Line
	11725 625  11575 625 
Text Label 11575 625  0    50   ~ 0
SS11
Wire Wire Line
	11725 525  11550 525 
Text Label 11550 525  0    50   ~ 0
S12
Wire Wire Line
	11725 425  11550 425 
Text Label 11550 425  0    50   ~ 0
SS12
$Comp
L Connector:Conn_01x04_Male J13
U 1 1 5ED7B369
P 11925 625
F 0 "J13" H 11898 505 50  0000 R CNN
F 1 "Conn_01x04_Male" H 11898 596 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 11925 625 50  0001 C CNN
F 3 "~" H 11925 625 50  0001 C CNN
	1    11925 625 
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Male J14
U 1 1 5ED7B522
P 11925 1025
F 0 "J14" H 11898 905 50  0000 R CNN
F 1 "Conn_01x04_Male" H 11898 996 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 11925 1025 50  0001 C CNN
F 3 "~" H 11925 1025 50  0001 C CNN
	1    11925 1025
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Male J15
U 1 1 5ED7B6D8
P 11925 1425
F 0 "J15" H 11898 1305 50  0000 R CNN
F 1 "Conn_01x04_Male" H 11898 1396 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 11925 1425 50  0001 C CNN
F 3 "~" H 11925 1425 50  0001 C CNN
	1    11925 1425
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Male J16
U 1 1 5ED7B7C6
P 11925 1825
F 0 "J16" H 11898 1705 50  0000 R CNN
F 1 "Conn_01x04_Male" H 11898 1796 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 11925 1825 50  0001 C CNN
F 3 "~" H 11925 1825 50  0001 C CNN
	1    11925 1825
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Male J17
U 1 1 5EDF71B6
P 11925 2225
F 0 "J17" H 11898 2105 50  0000 R CNN
F 1 "Conn_01x04_Male" H 11898 2196 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 11925 2225 50  0001 C CNN
F 3 "~" H 11925 2225 50  0001 C CNN
	1    11925 2225
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Male J18
U 1 1 5EDF72EE
P 11925 2625
F 0 "J18" H 11898 2505 50  0000 R CNN
F 1 "Conn_01x04_Male" H 11898 2596 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 11925 2625 50  0001 C CNN
F 3 "~" H 11925 2625 50  0001 C CNN
	1    11925 2625
	-1   0    0    1   
$EndComp
$Comp
L power:+9V #PWR0101
U 1 1 5E9BBEB9
P 1350 5425
F 0 "#PWR0101" H 1350 5275 50  0001 C CNN
F 1 "+9V" H 1365 5598 50  0000 C CNN
F 2 "" H 1350 5425 50  0001 C CNN
F 3 "" H 1350 5425 50  0001 C CNN
	1    1350 5425
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0102
U 1 1 5E9BBFF3
P 1325 4275
F 0 "#PWR0102" H 1325 4125 50  0001 C CNN
F 1 "+9V" H 1340 4448 50  0000 C CNN
F 2 "" H 1325 4275 50  0001 C CNN
F 3 "" H 1325 4275 50  0001 C CNN
	1    1325 4275
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0103
U 1 1 5E9BC0C8
P 4275 4300
F 0 "#PWR0103" H 4275 4150 50  0001 C CNN
F 1 "+9V" H 4290 4473 50  0000 C CNN
F 2 "" H 4275 4300 50  0001 C CNN
F 3 "" H 4275 4300 50  0001 C CNN
	1    4275 4300
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0104
U 1 1 5E9BC19D
P 4300 5450
F 0 "#PWR0104" H 4300 5300 50  0001 C CNN
F 1 "+9V" H 4315 5623 50  0000 C CNN
F 2 "" H 4300 5450 50  0001 C CNN
F 3 "" H 4300 5450 50  0001 C CNN
	1    4300 5450
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0105
U 1 1 5E9BC272
P 4300 6625
F 0 "#PWR0105" H 4300 6475 50  0001 C CNN
F 1 "+9V" H 4315 6798 50  0000 C CNN
F 2 "" H 4300 6625 50  0001 C CNN
F 3 "" H 4300 6625 50  0001 C CNN
	1    4300 6625
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0106
U 1 1 5E9BC347
P 1350 6600
F 0 "#PWR0106" H 1350 6450 50  0001 C CNN
F 1 "+9V" H 1365 6773 50  0000 C CNN
F 2 "" H 1350 6600 50  0001 C CNN
F 3 "" H 1350 6600 50  0001 C CNN
	1    1350 6600
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0107
U 1 1 5E9BF0B1
P 4275 3125
F 0 "#PWR0107" H 4275 2975 50  0001 C CNN
F 1 "+9V" H 4290 3298 50  0000 C CNN
F 2 "" H 4275 3125 50  0001 C CNN
F 3 "" H 4275 3125 50  0001 C CNN
	1    4275 3125
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0108
U 1 1 5E9BF186
P 4225 1925
F 0 "#PWR0108" H 4225 1775 50  0001 C CNN
F 1 "+9V" H 4240 2098 50  0000 C CNN
F 2 "" H 4225 1925 50  0001 C CNN
F 3 "" H 4225 1925 50  0001 C CNN
	1    4225 1925
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0109
U 1 1 5E9BF25B
P 1275 1900
F 0 "#PWR0109" H 1275 1750 50  0001 C CNN
F 1 "+9V" H 1290 2073 50  0000 C CNN
F 2 "" H 1275 1900 50  0001 C CNN
F 3 "" H 1275 1900 50  0001 C CNN
	1    1275 1900
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0110
U 1 1 5E9BF330
P 1325 3100
F 0 "#PWR0110" H 1325 2950 50  0001 C CNN
F 1 "+9V" H 1340 3273 50  0000 C CNN
F 2 "" H 1325 3100 50  0001 C CNN
F 3 "" H 1325 3100 50  0001 C CNN
	1    1325 3100
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0111
U 1 1 5E9BF405
P 4250 700
F 0 "#PWR0111" H 4250 550 50  0001 C CNN
F 1 "+9V" H 4265 873 50  0000 C CNN
F 2 "" H 4250 700 50  0001 C CNN
F 3 "" H 4250 700 50  0001 C CNN
	1    4250 700 
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0112
U 1 1 5E9BF996
P 1300 675
F 0 "#PWR0112" H 1300 525 50  0001 C CNN
F 1 "+9V" H 1315 848 50  0000 C CNN
F 2 "" H 1300 675 50  0001 C CNN
F 3 "" H 1300 675 50  0001 C CNN
	1    1300 675 
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM7809_TO220 U12
U 1 1 5E9C054C
P 9850 6425
F 0 "U12" H 9850 6667 50  0000 C CNN
F 1 "LM7809_TO220" H 9850 6576 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 9850 6650 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 9850 6375 50  0001 C CNN
	1    9850 6425
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM7909_TO220 U13
U 1 1 5E9C079C
P 10750 6400
F 0 "U13" H 10750 6158 50  0000 C CNN
F 1 "LM7909_TO220" H 10750 6249 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 10750 6200 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7905.pdf" H 10750 6400 50  0001 C CNN
	1    10750 6400
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J20
U 1 1 5E9C12B5
P 10750 1925
F 0 "J20" H 10800 2342 50  0000 C CNN
F 1 "Conn_02x05_Odd_Even" H 10800 2251 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05_Pitch2.54mm" H 10750 1925 50  0001 C CNN
F 3 "~" H 10750 1925 50  0001 C CNN
	1    10750 1925
	1    0    0    -1  
$EndComp
Text Notes 5425 -425 0    118  ~ 0
add decoupling!
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA27286
P 9850 6775
AR Path="/5BAC374C/5EA27286" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA27286" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA27286" Ref="#PWR?"  Part="1" 
AR Path="/5EA27286" Ref="#PWR0113"  Part="1" 
F 0 "#PWR0113" H 9850 6525 50  0001 C CNN
F 1 "GND" H 9850 6625 50  0000 C CNN
F 2 "" H 9850 6775 50  0000 C CNN
F 3 "" H 9850 6775 50  0000 C CNN
	1    9850 6775
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA27361
P 10750 6775
AR Path="/5BAC374C/5EA27361" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA27361" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA27361" Ref="#PWR?"  Part="1" 
AR Path="/5EA27361" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 10750 6525 50  0001 C CNN
F 1 "GND" H 10750 6625 50  0000 C CNN
F 2 "" H 10750 6775 50  0000 C CNN
F 3 "" H 10750 6775 50  0000 C CNN
	1    10750 6775
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J19
U 1 1 5EA27516
P 10250 5350
F 0 "J19" H 10356 5628 50  0000 C CNN
F 1 "Conn_01x03_Male" H 10356 5537 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 10250 5350 50  0001 C CNN
F 3 "~" H 10250 5350 50  0001 C CNN
	1    10250 5350
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA2761A
P 11175 1875
AR Path="/5BAC374C/5EA2761A" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA2761A" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA2761A" Ref="#PWR?"  Part="1" 
AR Path="/5EA2761A" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 11175 1625 50  0001 C CNN
F 1 "GND" H 11175 1725 50  0000 C CNN
F 2 "" H 11175 1875 50  0000 C CNN
F 3 "" H 11175 1875 50  0000 C CNN
	1    11175 1875
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0116
U 1 1 5EA276F7
P 10225 6425
F 0 "#PWR0116" H 10225 6275 50  0001 C CNN
F 1 "+9V" H 10240 6598 50  0000 C CNN
F 2 "" H 10225 6425 50  0001 C CNN
F 3 "" H 10225 6425 50  0001 C CNN
	1    10225 6425
	1    0    0    -1  
$EndComp
$Comp
L power:-9V #PWR0117
U 1 1 5EA277D4
P 10450 6450
F 0 "#PWR0117" H 10450 6325 50  0001 C CNN
F 1 "-9V" H 10465 6623 50  0000 C CNN
F 2 "" H 10450 6450 50  0001 C CNN
F 3 "" H 10450 6450 50  0001 C CNN
	1    10450 6450
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR0118
U 1 1 5EA27A65
P 10450 1725
F 0 "#PWR0118" H 10450 1575 50  0001 C CNN
F 1 "+12V" H 10465 1898 50  0000 C CNN
F 2 "" H 10450 1725 50  0001 C CNN
F 3 "" H 10450 1725 50  0001 C CNN
	1    10450 1725
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0119
U 1 1 5EA27C01
P 10450 2125
F 0 "#PWR0119" H 10450 2225 50  0001 C CNN
F 1 "-12V" H 10465 2298 50  0000 C CNN
F 2 "" H 10450 2125 50  0001 C CNN
F 3 "" H 10450 2125 50  0001 C CNN
	1    10450 2125
	-1   0    0    1   
$EndComp
$Comp
L power:-12V #PWR0120
U 1 1 5EA27DB7
P 11050 6450
F 0 "#PWR0120" H 11050 6550 50  0001 C CNN
F 1 "-12V" H 11065 6623 50  0000 C CNN
F 2 "" H 11050 6450 50  0001 C CNN
F 3 "" H 11050 6450 50  0001 C CNN
	1    11050 6450
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR0121
U 1 1 5EA27E94
P 9450 6425
F 0 "#PWR0121" H 9450 6275 50  0001 C CNN
F 1 "+12V" H 9465 6598 50  0000 C CNN
F 2 "" H 9450 6425 50  0001 C CNN
F 3 "" H 9450 6425 50  0001 C CNN
	1    9450 6425
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0122
U 1 1 5EA27F71
P 10850 5250
F 0 "#PWR0122" H 10850 5100 50  0001 C CNN
F 1 "+9V" H 10865 5423 50  0000 C CNN
F 2 "" H 10850 5250 50  0001 C CNN
F 3 "" H 10850 5250 50  0001 C CNN
	1    10850 5250
	1    0    0    -1  
$EndComp
$Comp
L power:-9V #PWR0123
U 1 1 5EA2804E
P 10850 5450
F 0 "#PWR0123" H 10850 5325 50  0001 C CNN
F 1 "-9V" H 10865 5623 50  0000 C CNN
F 2 "" H 10850 5450 50  0001 C CNN
F 3 "" H 10850 5450 50  0001 C CNN
	1    10850 5450
	-1   0    0    1   
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EA2812B
P 10625 5350
AR Path="/5BAC374C/5EA2812B" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EA2812B" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EA2812B" Ref="#PWR?"  Part="1" 
AR Path="/5EA2812B" Ref="#PWR0124"  Part="1" 
F 0 "#PWR0124" H 10625 5100 50  0001 C CNN
F 1 "GND" H 10625 5200 50  0000 C CNN
F 2 "" H 10625 5350 50  0000 C CNN
F 3 "" H 10625 5350 50  0000 C CNN
	1    10625 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 1725 10500 1725
Wire Wire Line
	11050 1725 11050 1650
Wire Wire Line
	11050 1650 10500 1650
Wire Wire Line
	10500 1650 10500 1725
Connection ~ 10500 1725
Wire Wire Line
	10500 1725 10550 1725
Wire Wire Line
	10550 1825 10550 1925
Wire Wire Line
	10550 1925 10550 2025
Connection ~ 10550 1925
Wire Wire Line
	11050 1825 11050 1925
Wire Wire Line
	11050 1925 11050 2025
Connection ~ 11050 1925
Wire Wire Line
	11050 1925 10550 1925
Wire Wire Line
	11050 1825 11175 1825
Wire Wire Line
	11175 1825 11175 1875
Connection ~ 11050 1825
Wire Wire Line
	10450 2125 10525 2125
Wire Wire Line
	10525 2125 10525 2225
Wire Wire Line
	10525 2225 11050 2225
Wire Wire Line
	11050 2225 11050 2125
Connection ~ 10525 2125
Wire Wire Line
	10525 2125 10550 2125
Wire Wire Line
	9450 6425 9550 6425
Wire Wire Line
	10150 6425 10225 6425
Wire Wire Line
	9850 6725 9850 6775
Wire Wire Line
	10450 6400 10450 6450
Wire Wire Line
	11050 6400 11050 6450
Wire Wire Line
	10750 6700 10750 6775
Wire Wire Line
	10450 5350 10625 5350
Wire Wire Line
	10450 5250 10850 5250
Wire Wire Line
	10450 5450 10850 5450
$Comp
L Device:C_Small C2
U 1 1 5EBCD0B3
P 8575 1275
F 0 "C2" H 8667 1321 50  0000 L CNN
F 1 "100nF" H 8667 1230 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8575 1275 50  0001 C CNN
F 3 "~" H 8575 1275 50  0001 C CNN
	1    8575 1275
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EBFE295
P 8575 1425
AR Path="/5BAC374C/5EBFE295" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EBFE295" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EBFE295" Ref="#PWR?"  Part="1" 
AR Path="/5EBFE295" Ref="#PWR0125"  Part="1" 
F 0 "#PWR0125" H 8575 1175 50  0001 C CNN
F 1 "GND" H 8575 1275 50  0000 C CNN
F 2 "" H 8575 1425 50  0000 C CNN
F 3 "" H 8575 1425 50  0000 C CNN
	1    8575 1425
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0126
U 1 1 5EBFF2C9
P 8575 1125
F 0 "#PWR0126" H 8575 975 50  0001 C CNN
F 1 "+9V" H 8590 1298 50  0000 C CNN
F 2 "" H 8575 1125 50  0001 C CNN
F 3 "" H 8575 1125 50  0001 C CNN
	1    8575 1125
	1    0    0    -1  
$EndComp
Wire Wire Line
	8575 1125 8575 1175
Wire Wire Line
	8575 1375 8575 1425
$Comp
L Device:C_Small C4
U 1 1 5EC2E6BC
P 8925 1275
F 0 "C4" H 9017 1321 50  0000 L CNN
F 1 "100nF" H 9017 1230 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8925 1275 50  0001 C CNN
F 3 "~" H 8925 1275 50  0001 C CNN
	1    8925 1275
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EC2E6C3
P 8925 1425
AR Path="/5BAC374C/5EC2E6C3" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EC2E6C3" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EC2E6C3" Ref="#PWR?"  Part="1" 
AR Path="/5EC2E6C3" Ref="#PWR0127"  Part="1" 
F 0 "#PWR0127" H 8925 1175 50  0001 C CNN
F 1 "GND" H 8925 1275 50  0000 C CNN
F 2 "" H 8925 1425 50  0000 C CNN
F 3 "" H 8925 1425 50  0000 C CNN
	1    8925 1425
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0128
U 1 1 5EC2E6C9
P 8925 1125
F 0 "#PWR0128" H 8925 975 50  0001 C CNN
F 1 "+9V" H 8940 1298 50  0000 C CNN
F 2 "" H 8925 1125 50  0001 C CNN
F 3 "" H 8925 1125 50  0001 C CNN
	1    8925 1125
	1    0    0    -1  
$EndComp
Wire Wire Line
	8925 1125 8925 1175
Wire Wire Line
	8925 1375 8925 1425
$Comp
L Device:C_Small C9
U 1 1 5EC5F682
P 9300 2650
F 0 "C9" H 9392 2696 50  0000 L CNN
F 1 "100nF" H 9392 2605 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9300 2650 50  0001 C CNN
F 3 "~" H 9300 2650 50  0001 C CNN
	1    9300 2650
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EC5F689
P 9300 2800
AR Path="/5BAC374C/5EC5F689" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EC5F689" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EC5F689" Ref="#PWR?"  Part="1" 
AR Path="/5EC5F689" Ref="#PWR0129"  Part="1" 
F 0 "#PWR0129" H 9300 2550 50  0001 C CNN
F 1 "GND" H 9300 2650 50  0000 C CNN
F 2 "" H 9300 2800 50  0000 C CNN
F 3 "" H 9300 2800 50  0000 C CNN
	1    9300 2800
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0130
U 1 1 5EC5F68F
P 9300 2500
F 0 "#PWR0130" H 9300 2350 50  0001 C CNN
F 1 "+9V" H 9315 2673 50  0000 C CNN
F 2 "" H 9300 2500 50  0001 C CNN
F 3 "" H 9300 2500 50  0001 C CNN
	1    9300 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 2500 9300 2550
Wire Wire Line
	9300 2750 9300 2800
$Comp
L Device:C_Small C15
U 1 1 5EC5F697
P 9650 2650
F 0 "C15" H 9742 2696 50  0000 L CNN
F 1 "100nF" H 9742 2605 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9650 2650 50  0001 C CNN
F 3 "~" H 9650 2650 50  0001 C CNN
	1    9650 2650
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EC5F69E
P 9650 2800
AR Path="/5BAC374C/5EC5F69E" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EC5F69E" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EC5F69E" Ref="#PWR?"  Part="1" 
AR Path="/5EC5F69E" Ref="#PWR0131"  Part="1" 
F 0 "#PWR0131" H 9650 2550 50  0001 C CNN
F 1 "GND" H 9650 2650 50  0000 C CNN
F 2 "" H 9650 2800 50  0000 C CNN
F 3 "" H 9650 2800 50  0000 C CNN
	1    9650 2800
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0132
U 1 1 5EC5F6A4
P 9650 2500
F 0 "#PWR0132" H 9650 2350 50  0001 C CNN
F 1 "+9V" H 9665 2673 50  0000 C CNN
F 2 "" H 9650 2500 50  0001 C CNN
F 3 "" H 9650 2500 50  0001 C CNN
	1    9650 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 2500 9650 2550
Wire Wire Line
	9650 2750 9650 2800
$Comp
L Device:C_Small C17
U 1 1 5EC77CD2
P 9900 2650
F 0 "C17" H 9992 2696 50  0000 L CNN
F 1 "100nF" H 9992 2605 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9900 2650 50  0001 C CNN
F 3 "~" H 9900 2650 50  0001 C CNN
	1    9900 2650
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5EC77CD9
P 9900 2800
AR Path="/5BAC374C/5EC77CD9" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5EC77CD9" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5EC77CD9" Ref="#PWR?"  Part="1" 
AR Path="/5EC77CD9" Ref="#PWR0133"  Part="1" 
F 0 "#PWR0133" H 9900 2550 50  0001 C CNN
F 1 "GND" H 9900 2650 50  0000 C CNN
F 2 "" H 9900 2800 50  0000 C CNN
F 3 "" H 9900 2800 50  0000 C CNN
	1    9900 2800
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0134
U 1 1 5EC77CDF
P 9900 2500
F 0 "#PWR0134" H 9900 2350 50  0001 C CNN
F 1 "+9V" H 9915 2673 50  0000 C CNN
F 2 "" H 9900 2500 50  0001 C CNN
F 3 "" H 9900 2500 50  0001 C CNN
	1    9900 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 2500 9900 2550
Wire Wire Line
	9900 2750 9900 2800
$Comp
L Device:C_Small C10
U 1 1 5ECAC0D0
P 9300 3950
F 0 "C10" H 9392 3996 50  0000 L CNN
F 1 "100nF" H 9392 3905 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9300 3950 50  0001 C CNN
F 3 "~" H 9300 3950 50  0001 C CNN
	1    9300 3950
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ECAC0D7
P 9300 4100
AR Path="/5BAC374C/5ECAC0D7" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ECAC0D7" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ECAC0D7" Ref="#PWR?"  Part="1" 
AR Path="/5ECAC0D7" Ref="#PWR0135"  Part="1" 
F 0 "#PWR0135" H 9300 3850 50  0001 C CNN
F 1 "GND" H 9300 3950 50  0000 C CNN
F 2 "" H 9300 4100 50  0000 C CNN
F 3 "" H 9300 4100 50  0000 C CNN
	1    9300 4100
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0136
U 1 1 5ECAC0DD
P 9300 3800
F 0 "#PWR0136" H 9300 3650 50  0001 C CNN
F 1 "+9V" H 9315 3973 50  0000 C CNN
F 2 "" H 9300 3800 50  0001 C CNN
F 3 "" H 9300 3800 50  0001 C CNN
	1    9300 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 3800 9300 3850
Wire Wire Line
	9300 4050 9300 4100
$Comp
L Device:C_Small C16
U 1 1 5ECAC0E5
P 9650 3950
F 0 "C16" H 9742 3996 50  0000 L CNN
F 1 "100nF" H 9742 3905 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9650 3950 50  0001 C CNN
F 3 "~" H 9650 3950 50  0001 C CNN
	1    9650 3950
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ECAC0EC
P 9650 4100
AR Path="/5BAC374C/5ECAC0EC" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ECAC0EC" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ECAC0EC" Ref="#PWR?"  Part="1" 
AR Path="/5ECAC0EC" Ref="#PWR0137"  Part="1" 
F 0 "#PWR0137" H 9650 3850 50  0001 C CNN
F 1 "GND" H 9650 3950 50  0000 C CNN
F 2 "" H 9650 4100 50  0000 C CNN
F 3 "" H 9650 4100 50  0000 C CNN
	1    9650 4100
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0138
U 1 1 5ECAC0F2
P 9650 3800
F 0 "#PWR0138" H 9650 3650 50  0001 C CNN
F 1 "+9V" H 9665 3973 50  0000 C CNN
F 2 "" H 9650 3800 50  0001 C CNN
F 3 "" H 9650 3800 50  0001 C CNN
	1    9650 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 3800 9650 3850
Wire Wire Line
	9650 4050 9650 4100
$Comp
L Device:C_Small C18
U 1 1 5ECAC0FA
P 9900 3950
F 0 "C18" H 9992 3996 50  0000 L CNN
F 1 "100nF" H 9992 3905 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9900 3950 50  0001 C CNN
F 3 "~" H 9900 3950 50  0001 C CNN
	1    9900 3950
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ECAC101
P 9900 4100
AR Path="/5BAC374C/5ECAC101" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ECAC101" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ECAC101" Ref="#PWR?"  Part="1" 
AR Path="/5ECAC101" Ref="#PWR0139"  Part="1" 
F 0 "#PWR0139" H 9900 3850 50  0001 C CNN
F 1 "GND" H 9900 3950 50  0000 C CNN
F 2 "" H 9900 4100 50  0000 C CNN
F 3 "" H 9900 4100 50  0000 C CNN
	1    9900 4100
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0140
U 1 1 5ECAC107
P 9900 3800
F 0 "#PWR0140" H 9900 3650 50  0001 C CNN
F 1 "+9V" H 9915 3973 50  0000 C CNN
F 2 "" H 9900 3800 50  0001 C CNN
F 3 "" H 9900 3800 50  0001 C CNN
	1    9900 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 3800 9900 3850
Wire Wire Line
	9900 4050 9900 4100
$Comp
L Device:C_Small C6
U 1 1 5ECC588D
P 9025 4925
F 0 "C6" H 9117 4971 50  0000 L CNN
F 1 "100nF" H 9117 4880 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9025 4925 50  0001 C CNN
F 3 "~" H 9025 4925 50  0001 C CNN
	1    9025 4925
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ECC5894
P 9025 5075
AR Path="/5BAC374C/5ECC5894" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ECC5894" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ECC5894" Ref="#PWR?"  Part="1" 
AR Path="/5ECC5894" Ref="#PWR0141"  Part="1" 
F 0 "#PWR0141" H 9025 4825 50  0001 C CNN
F 1 "GND" H 9025 4925 50  0000 C CNN
F 2 "" H 9025 5075 50  0000 C CNN
F 3 "" H 9025 5075 50  0000 C CNN
	1    9025 5075
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0142
U 1 1 5ECC589A
P 9025 4775
F 0 "#PWR0142" H 9025 4625 50  0001 C CNN
F 1 "+9V" H 9040 4948 50  0000 C CNN
F 2 "" H 9025 4775 50  0001 C CNN
F 3 "" H 9025 4775 50  0001 C CNN
	1    9025 4775
	1    0    0    -1  
$EndComp
Wire Wire Line
	9025 4775 9025 4825
Wire Wire Line
	9025 5025 9025 5075
$Comp
L Device:C_Small C12
U 1 1 5ECC58A2
P 9375 4925
F 0 "C12" H 9467 4971 50  0000 L CNN
F 1 "100nF" H 9467 4880 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9375 4925 50  0001 C CNN
F 3 "~" H 9375 4925 50  0001 C CNN
	1    9375 4925
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ECC58A9
P 9375 5075
AR Path="/5BAC374C/5ECC58A9" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ECC58A9" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ECC58A9" Ref="#PWR?"  Part="1" 
AR Path="/5ECC58A9" Ref="#PWR0143"  Part="1" 
F 0 "#PWR0143" H 9375 4825 50  0001 C CNN
F 1 "GND" H 9375 4925 50  0000 C CNN
F 2 "" H 9375 5075 50  0000 C CNN
F 3 "" H 9375 5075 50  0000 C CNN
	1    9375 5075
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0144
U 1 1 5ECC58AF
P 9375 4775
F 0 "#PWR0144" H 9375 4625 50  0001 C CNN
F 1 "+9V" H 9390 4948 50  0000 C CNN
F 2 "" H 9375 4775 50  0001 C CNN
F 3 "" H 9375 4775 50  0001 C CNN
	1    9375 4775
	1    0    0    -1  
$EndComp
Wire Wire Line
	9375 4775 9375 4825
Wire Wire Line
	9375 5025 9375 5075
$Comp
L Device:C_Small C14
U 1 1 5ECC58B7
P 9625 4925
F 0 "C14" H 9717 4971 50  0000 L CNN
F 1 "100nF" H 9717 4880 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9625 4925 50  0001 C CNN
F 3 "~" H 9625 4925 50  0001 C CNN
	1    9625 4925
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ECC58BE
P 9625 5075
AR Path="/5BAC374C/5ECC58BE" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ECC58BE" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ECC58BE" Ref="#PWR?"  Part="1" 
AR Path="/5ECC58BE" Ref="#PWR0145"  Part="1" 
F 0 "#PWR0145" H 9625 4825 50  0001 C CNN
F 1 "GND" H 9625 4925 50  0000 C CNN
F 2 "" H 9625 5075 50  0000 C CNN
F 3 "" H 9625 5075 50  0000 C CNN
	1    9625 5075
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0146
U 1 1 5ECC58C4
P 9625 4775
F 0 "#PWR0146" H 9625 4625 50  0001 C CNN
F 1 "+9V" H 9640 4948 50  0000 C CNN
F 2 "" H 9625 4775 50  0001 C CNN
F 3 "" H 9625 4775 50  0001 C CNN
	1    9625 4775
	1    0    0    -1  
$EndComp
Wire Wire Line
	9625 4775 9625 4825
Wire Wire Line
	9625 5025 9625 5075
$Comp
L Device:C_Small C7
U 1 1 5ECDFF02
P 9100 5750
F 0 "C7" H 9192 5796 50  0000 L CNN
F 1 "100nF" H 9192 5705 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9100 5750 50  0001 C CNN
F 3 "~" H 9100 5750 50  0001 C CNN
	1    9100 5750
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ECDFF09
P 9100 5900
AR Path="/5BAC374C/5ECDFF09" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ECDFF09" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ECDFF09" Ref="#PWR?"  Part="1" 
AR Path="/5ECDFF09" Ref="#PWR0147"  Part="1" 
F 0 "#PWR0147" H 9100 5650 50  0001 C CNN
F 1 "GND" H 9100 5750 50  0000 C CNN
F 2 "" H 9100 5900 50  0000 C CNN
F 3 "" H 9100 5900 50  0000 C CNN
	1    9100 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 5850 9100 5900
$Comp
L power:-9V #PWR0148
U 1 1 5ECFA8A7
P 9100 5525
F 0 "#PWR0148" H 9100 5400 50  0001 C CNN
F 1 "-9V" H 9115 5698 50  0000 C CNN
F 2 "" H 9100 5525 50  0001 C CNN
F 3 "" H 9100 5525 50  0001 C CNN
	1    9100 5525
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 5525 9100 5650
$Comp
L Device:C_Small C11
U 1 1 5ED157A3
P 9325 5750
F 0 "C11" H 9417 5796 50  0000 L CNN
F 1 "100nF" H 9417 5705 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9325 5750 50  0001 C CNN
F 3 "~" H 9325 5750 50  0001 C CNN
	1    9325 5750
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ED157AA
P 9325 5900
AR Path="/5BAC374C/5ED157AA" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ED157AA" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ED157AA" Ref="#PWR?"  Part="1" 
AR Path="/5ED157AA" Ref="#PWR0149"  Part="1" 
F 0 "#PWR0149" H 9325 5650 50  0001 C CNN
F 1 "GND" H 9325 5750 50  0000 C CNN
F 2 "" H 9325 5900 50  0000 C CNN
F 3 "" H 9325 5900 50  0000 C CNN
	1    9325 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9325 5850 9325 5900
$Comp
L power:-9V #PWR0150
U 1 1 5ED157B1
P 9325 5525
F 0 "#PWR0150" H 9325 5400 50  0001 C CNN
F 1 "-9V" H 9340 5698 50  0000 C CNN
F 2 "" H 9325 5525 50  0001 C CNN
F 3 "" H 9325 5525 50  0001 C CNN
	1    9325 5525
	1    0    0    -1  
$EndComp
Wire Wire Line
	9325 5525 9325 5650
$Comp
L Device:C_Small C13
U 1 1 5ED305B7
P 9525 5750
F 0 "C13" H 9617 5796 50  0000 L CNN
F 1 "100nF" H 9617 5705 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9525 5750 50  0001 C CNN
F 3 "~" H 9525 5750 50  0001 C CNN
	1    9525 5750
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ED305BE
P 9525 5900
AR Path="/5BAC374C/5ED305BE" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ED305BE" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ED305BE" Ref="#PWR?"  Part="1" 
AR Path="/5ED305BE" Ref="#PWR0151"  Part="1" 
F 0 "#PWR0151" H 9525 5650 50  0001 C CNN
F 1 "GND" H 9525 5750 50  0000 C CNN
F 2 "" H 9525 5900 50  0000 C CNN
F 3 "" H 9525 5900 50  0000 C CNN
	1    9525 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9525 5850 9525 5900
$Comp
L power:-9V #PWR0152
U 1 1 5ED305C5
P 9525 5525
F 0 "#PWR0152" H 9525 5400 50  0001 C CNN
F 1 "-9V" H 9540 5698 50  0000 C CNN
F 2 "" H 9525 5525 50  0001 C CNN
F 3 "" H 9525 5525 50  0001 C CNN
	1    9525 5525
	1    0    0    -1  
$EndComp
Wire Wire Line
	9525 5525 9525 5650
$Comp
L Device:CP_Small C3
U 1 1 5ED4BF53
P 8575 6675
F 0 "C3" H 8663 6721 50  0000 L CNN
F 1 "10uF" H 8663 6630 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D4.0mm_P1.50mm" H 8575 6675 50  0001 C CNN
F 3 "~" H 8575 6675 50  0001 C CNN
	1    8575 6675
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ED4C0BB
P 8575 6825
AR Path="/5BAC374C/5ED4C0BB" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ED4C0BB" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ED4C0BB" Ref="#PWR?"  Part="1" 
AR Path="/5ED4C0BB" Ref="#PWR0153"  Part="1" 
F 0 "#PWR0153" H 8575 6575 50  0001 C CNN
F 1 "GND" H 8575 6675 50  0000 C CNN
F 2 "" H 8575 6825 50  0000 C CNN
F 3 "" H 8575 6825 50  0000 C CNN
	1    8575 6825
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C5
U 1 1 5ED4C4EE
P 8925 6675
F 0 "C5" H 8837 6629 50  0000 R CNN
F 1 "10uF" H 8837 6720 50  0000 R CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D4.0mm_P1.50mm" H 8925 6675 50  0001 C CNN
F 3 "~" H 8925 6675 50  0001 C CNN
	1    8925 6675
	-1   0    0    1   
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ED4C4F5
P 8925 6825
AR Path="/5BAC374C/5ED4C4F5" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ED4C4F5" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ED4C4F5" Ref="#PWR?"  Part="1" 
AR Path="/5ED4C4F5" Ref="#PWR0154"  Part="1" 
F 0 "#PWR0154" H 8925 6575 50  0001 C CNN
F 1 "GND" H 8925 6675 50  0000 C CNN
F 2 "" H 8925 6825 50  0000 C CNN
F 3 "" H 8925 6825 50  0000 C CNN
	1    8925 6825
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C8
U 1 1 5ED677E2
P 9250 6675
F 0 "C8" H 9162 6629 50  0000 R CNN
F 1 "10uF" H 9162 6720 50  0000 R CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D4.0mm_P1.50mm" H 9250 6675 50  0001 C CNN
F 3 "~" H 9250 6675 50  0001 C CNN
	1    9250 6675
	-1   0    0    1   
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ED677E9
P 9250 6825
AR Path="/5BAC374C/5ED677E9" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ED677E9" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ED677E9" Ref="#PWR?"  Part="1" 
AR Path="/5ED677E9" Ref="#PWR0155"  Part="1" 
F 0 "#PWR0155" H 9250 6575 50  0001 C CNN
F 1 "GND" H 9250 6675 50  0000 C CNN
F 2 "" H 9250 6825 50  0000 C CNN
F 3 "" H 9250 6825 50  0000 C CNN
	1    9250 6825
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C1
U 1 1 5ED82AE8
P 8325 6675
F 0 "C1" H 8413 6721 50  0000 L CNN
F 1 "10uF" H 8413 6630 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D4.0mm_P1.50mm" H 8325 6675 50  0001 C CNN
F 3 "~" H 8325 6675 50  0001 C CNN
	1    8325 6675
	1    0    0    -1  
$EndComp
$Comp
L touch-rescue:GND-power-allcolours_analogue-rescue #PWR?
U 1 1 5ED82AEF
P 8325 6825
AR Path="/5BAC374C/5ED82AEF" Ref="#PWR?"  Part="1" 
AR Path="/5C0A69D0/5ED82AEF" Ref="#PWR?"  Part="1" 
AR Path="/5E97CA7E/5ED82AEF" Ref="#PWR?"  Part="1" 
AR Path="/5ED82AEF" Ref="#PWR0156"  Part="1" 
F 0 "#PWR0156" H 8325 6575 50  0001 C CNN
F 1 "GND" H 8325 6675 50  0000 C CNN
F 2 "" H 8325 6825 50  0000 C CNN
F 3 "" H 8325 6825 50  0000 C CNN
	1    8325 6825
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0157
U 1 1 5ED9DDBA
P 8325 6500
F 0 "#PWR0157" H 8325 6350 50  0001 C CNN
F 1 "+12V" H 8340 6673 50  0000 C CNN
F 2 "" H 8325 6500 50  0001 C CNN
F 3 "" H 8325 6500 50  0001 C CNN
	1    8325 6500
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0158
U 1 1 5ED9DEBB
P 8575 6500
F 0 "#PWR0158" H 8575 6350 50  0001 C CNN
F 1 "+9V" H 8590 6673 50  0000 C CNN
F 2 "" H 8575 6500 50  0001 C CNN
F 3 "" H 8575 6500 50  0001 C CNN
	1    8575 6500
	1    0    0    -1  
$EndComp
$Comp
L power:-9V #PWR0159
U 1 1 5ED9DFBC
P 8925 6500
F 0 "#PWR0159" H 8925 6375 50  0001 C CNN
F 1 "-9V" H 8940 6673 50  0000 C CNN
F 2 "" H 8925 6500 50  0001 C CNN
F 3 "" H 8925 6500 50  0001 C CNN
	1    8925 6500
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0160
U 1 1 5ED9E2B6
P 9250 6475
F 0 "#PWR0160" H 9250 6575 50  0001 C CNN
F 1 "-12V" H 9265 6648 50  0000 C CNN
F 2 "" H 9250 6475 50  0001 C CNN
F 3 "" H 9250 6475 50  0001 C CNN
	1    9250 6475
	1    0    0    -1  
$EndComp
Wire Wire Line
	8325 6775 8325 6825
Wire Wire Line
	8575 6775 8575 6825
Wire Wire Line
	8925 6775 8925 6825
Wire Wire Line
	9250 6775 9250 6825
Wire Wire Line
	9250 6475 9250 6575
Wire Wire Line
	8925 6500 8925 6575
Wire Wire Line
	8575 6500 8575 6575
Wire Wire Line
	8325 6500 8325 6575
$Comp
L Connector:Conn_01x03_Male J1
U 1 1 5EA01BD0
P 550 1075
F 0 "J1" H 656 1353 50  0000 C CNN
F 1 "Conn_01x03_Male" H 656 1262 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 550 1075 50  0001 C CNN
F 3 "~" H 550 1075 50  0001 C CNN
	1    550  1075
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  975  1300 975 
Connection ~ 1300 975 
Wire Wire Line
	1100 2200 1275 2200
$Comp
L Connector:Conn_01x03_Male J2
U 1 1 5EAEDBAB
P 625 4675
F 0 "J2" H 731 4953 50  0000 C CNN
F 1 "Conn_01x03_Male" H 731 4862 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 625 4675 50  0001 C CNN
F 3 "~" H 625 4675 50  0001 C CNN
	1    625  4675
	1    0    0    -1  
$EndComp
Wire Wire Line
	825  4575 1325 4575
Connection ~ 1325 4575
Wire Wire Line
	825  4675 1175 4675
Wire Wire Line
	1175 4675 1175 5725
Wire Wire Line
	1175 5725 1350 5725
Connection ~ 1350 5725
Wire Wire Line
	825  4775 1050 4775
Wire Wire Line
	1050 4775 1050 6900
Wire Wire Line
	1050 6900 1350 6900
Connection ~ 1350 6900
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5EB4BE44
P 3725 1100
F 0 "J3" H 3831 1378 50  0000 C CNN
F 1 "Conn_01x03_Male" H 3831 1287 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 3725 1100 50  0001 C CNN
F 3 "~" H 3725 1100 50  0001 C CNN
	1    3725 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3925 1000 4250 1000
Connection ~ 4250 1000
Wire Wire Line
	3925 1100 4100 1100
Wire Wire Line
	4100 1100 4100 2225
Wire Wire Line
	4100 2225 4225 2225
Connection ~ 4225 2225
Wire Wire Line
	3925 1200 4025 1200
Wire Wire Line
	4025 1200 4025 3425
Wire Wire Line
	4025 3425 4275 3425
Connection ~ 4275 3425
$Comp
L Connector:Conn_01x03_Male J4
U 1 1 5EBAC6B8
P 3725 4700
F 0 "J4" H 3831 4978 50  0000 C CNN
F 1 "Conn_01x03_Male" H 3831 4887 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 3725 4700 50  0001 C CNN
F 3 "~" H 3725 4700 50  0001 C CNN
	1    3725 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3925 4600 4275 4600
Connection ~ 4275 4600
Wire Wire Line
	3925 4700 4125 4700
Wire Wire Line
	4125 4700 4125 5750
Wire Wire Line
	4125 5750 4300 5750
Connection ~ 4300 5750
Wire Wire Line
	4300 6925 4025 6925
Wire Wire Line
	4025 6925 4025 4800
Wire Wire Line
	4025 4800 3925 4800
Connection ~ 4300 6925
Wire Wire Line
	750  1075 1100 1075
Wire Wire Line
	1100 1075 1100 2200
Wire Wire Line
	750  1175 975  1175
Wire Wire Line
	975  1175 975  3400
Wire Wire Line
	975  3400 1325 3400
$EndSCHEMATC
