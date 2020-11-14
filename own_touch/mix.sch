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
L Connector_Generic:Conn_01x04 J13
U 1 1 5EF3AC50
P 5040 3123
F 0 "J13" H 5120 3115 50  0000 L CNN
F 1 "Conn_01x04" H 5120 3024 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 5040 3123 50  0001 C CNN
F 3 "~" H 5040 3123 50  0001 C CNN
	1    5040 3123
	1    0    0    -1  
$EndComp
Wire Wire Line
	4840 3023 4730 3023
Text GLabel 4730 3023 0    50   Input ~ 0
OUTT1
Text GLabel 4740 3123 0    50   Input ~ 0
OUTT2
Wire Wire Line
	4740 3123 4840 3123
Wire Wire Line
	4840 3223 4730 3223
Text GLabel 4730 3223 0    50   Input ~ 0
OUTT3
Text GLabel 4740 3323 0    50   Input ~ 0
OUTT4
Wire Wire Line
	4740 3323 4840 3323
Text Notes 2850 750  0    79   ~ 0
add bypass caps by hand
$Comp
L Connector_Generic:Conn_01x04 J14
U 1 1 5F37C317
P 6230 3123
F 0 "J14" H 6310 3115 50  0000 L CNN
F 1 "Conn_01x04" H 6310 3024 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 6230 3123 50  0001 C CNN
F 3 "~" H 6230 3123 50  0001 C CNN
	1    6230 3123
	1    0    0    -1  
$EndComp
Wire Wire Line
	6030 3023 5920 3023
Text GLabel 5920 3023 0    50   Input ~ 0
OUTTT1
Text GLabel 5930 3123 0    50   Input ~ 0
OUTTT2
Wire Wire Line
	5930 3123 6030 3123
Wire Wire Line
	6030 3223 5920 3223
Text GLabel 5920 3223 0    50   Input ~ 0
OUTTT3
Text GLabel 5930 3323 0    50   Input ~ 0
OUTTT4
Wire Wire Line
	5930 3323 6030 3323
Text Notes 4700 3543 0    79   ~ 0
For panel and circuits
$Comp
L Amplifier_Operational:TL074 U?
U 3 1 5EF9C83B
P 3505 4065
AR Path="/5EBFD180/5EF9C83B" Ref="U?"  Part="3" 
AR Path="/5EF10D95/5EF9C83B" Ref="U10"  Part="3" 
F 0 "U10" H 3505 4432 50  0000 C CNN
F 1 "TL074" H 3505 4341 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3455 4165 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3555 4265 50  0001 C CNN
	3    3505 4065
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 4 1 5EF9C842
P 3475 5370
AR Path="/5EBFD180/5EF9C842" Ref="U?"  Part="4" 
AR Path="/5EF10D95/5EF9C842" Ref="U10"  Part="4" 
F 0 "U10" H 3475 5737 50  0000 C CNN
F 1 "TL074" H 3475 5646 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3425 5470 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3525 5570 50  0001 C CNN
	4    3475 5370
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 1 1 5EF9C849
P 3515 1430
AR Path="/5EBFD180/5EF9C849" Ref="U?"  Part="1" 
AR Path="/5EF10D95/5EF9C849" Ref="U10"  Part="1" 
F 0 "U10" H 3515 1797 50  0000 C CNN
F 1 "TL074" H 3515 1706 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3465 1530 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3565 1630 50  0001 C CNN
	1    3515 1430
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 2 1 5EF9C850
P 3505 2705
AR Path="/5EBFD180/5EF9C850" Ref="U?"  Part="2" 
AR Path="/5EF10D95/5EF9C850" Ref="U10"  Part="2" 
F 0 "U10" H 3505 3072 50  0000 C CNN
F 1 "TL074" H 3505 2981 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3455 2805 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3555 2905 50  0001 C CNN
	2    3505 2705
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF9C857
P 3520 1885
AR Path="/5EBFD180/5EF9C857" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF9C857" Ref="R56"  Part="1" 
F 0 "R56" V 3324 1885 50  0000 C CNN
F 1 "10K" V 3415 1885 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3520 1885 50  0001 C CNN
F 3 "~" H 3520 1885 50  0001 C CNN
	1    3520 1885
	0    1    1    0   
$EndComp
Wire Wire Line
	3180 1630 3180 1685
Text Label 3180 1685 0    50   ~ 0
c1
$Comp
L power:GND #PWR?
U 1 1 5EF9C868
P 3160 1330
AR Path="/5EBFD180/5EF9C868" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EF9C868" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 3160 1080 50  0001 C CNN
F 1 "GND" H 3165 1157 50  0000 C CNN
F 2 "" H 3160 1330 50  0001 C CNN
F 3 "" H 3160 1330 50  0001 C CNN
	1    3160 1330
	1    0    0    -1  
$EndComp
Wire Wire Line
	3160 1330 3215 1330
Wire Wire Line
	3205 1530 3205 1885
Wire Wire Line
	3205 1885 3420 1885
Connection ~ 3205 1530
Wire Wire Line
	3205 1530 3215 1530
Wire Wire Line
	3815 1430 3815 1885
Wire Wire Line
	3620 1885 3815 1885
Text GLabel 2830 1530 0    50   Input ~ 0
OUT1
$Comp
L Device:R_Small R?
U 1 1 5EF9C87C
P 3510 3160
AR Path="/5EBFD180/5EF9C87C" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF9C87C" Ref="R54"  Part="1" 
F 0 "R54" V 3314 3160 50  0000 C CNN
F 1 "10K" V 3405 3160 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3510 3160 50  0001 C CNN
F 3 "~" H 3510 3160 50  0001 C CNN
	1    3510 3160
	0    1    1    0   
$EndComp
Wire Wire Line
	3170 2905 3170 2960
Text Label 3170 2960 0    50   ~ 0
c2
$Comp
L power:GND #PWR?
U 1 1 5EF9C88C
P 3150 2605
AR Path="/5EBFD180/5EF9C88C" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EF9C88C" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 3150 2355 50  0001 C CNN
F 1 "GND" H 3155 2432 50  0000 C CNN
F 2 "" H 3150 2605 50  0001 C CNN
F 3 "" H 3150 2605 50  0001 C CNN
	1    3150 2605
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2605 3205 2605
Wire Wire Line
	3195 2805 3195 3160
Wire Wire Line
	3195 3160 3410 3160
Wire Wire Line
	3805 2705 3805 3160
Wire Wire Line
	3610 3160 3805 3160
Text GLabel 2835 2805 0    50   Input ~ 0
OUT2
$Comp
L Device:R_Small R?
U 1 1 5EF9C89E
P 3510 4520
AR Path="/5EBFD180/5EF9C89E" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF9C89E" Ref="R55"  Part="1" 
F 0 "R55" V 3314 4520 50  0000 C CNN
F 1 "10K" V 3405 4520 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3510 4520 50  0001 C CNN
F 3 "~" H 3510 4520 50  0001 C CNN
	1    3510 4520
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF9C8AE
P 3150 3965
AR Path="/5EBFD180/5EF9C8AE" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EF9C8AE" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 3150 3715 50  0001 C CNN
F 1 "GND" H 3155 3792 50  0000 C CNN
F 2 "" H 3150 3965 50  0001 C CNN
F 3 "" H 3150 3965 50  0001 C CNN
	1    3150 3965
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 3965 3205 3965
Wire Wire Line
	3195 4165 3195 4520
Wire Wire Line
	3195 4520 3410 4520
Wire Wire Line
	3805 4065 3805 4520
Wire Wire Line
	3610 4520 3805 4520
Text GLabel 2855 4165 0    50   Input ~ 0
OUT3
$Comp
L Device:R_Small R?
U 1 1 5EF9C8C0
P 3480 5825
AR Path="/5EBFD180/5EF9C8C0" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EF9C8C0" Ref="R53"  Part="1" 
F 0 "R53" V 3284 5825 50  0000 C CNN
F 1 "10K" V 3375 5825 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3480 5825 50  0001 C CNN
F 3 "~" H 3480 5825 50  0001 C CNN
	1    3480 5825
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF9C8CF
P 3120 5270
AR Path="/5EBFD180/5EF9C8CF" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EF9C8CF" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 3120 5020 50  0001 C CNN
F 1 "GND" H 3125 5097 50  0000 C CNN
F 2 "" H 3120 5270 50  0001 C CNN
F 3 "" H 3120 5270 50  0001 C CNN
	1    3120 5270
	1    0    0    -1  
$EndComp
Wire Wire Line
	3120 5270 3175 5270
Wire Wire Line
	3165 5470 3165 5825
Wire Wire Line
	3165 5825 3380 5825
Wire Wire Line
	3775 5370 3775 5825
Wire Wire Line
	3580 5825 3775 5825
Text GLabel 2865 5470 0    50   Input ~ 0
OUT4
Connection ~ 3165 5470
Wire Wire Line
	3165 5470 3175 5470
Connection ~ 3195 4165
Wire Wire Line
	3195 4165 3205 4165
Connection ~ 3195 2805
Wire Wire Line
	3195 2805 3205 2805
$Comp
L Device:R_Small R?
U 1 1 5EFA2287
P 3010 1530
AR Path="/5EBFD180/5EFA2287" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EFA2287" Ref="R50"  Part="1" 
F 0 "R50" V 2814 1530 50  0000 C CNN
F 1 "10K" V 2905 1530 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3010 1530 50  0001 C CNN
F 3 "~" H 3010 1530 50  0001 C CNN
	1    3010 1530
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFA2343
P 2990 2805
AR Path="/5EBFD180/5EFA2343" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EFA2343" Ref="R49"  Part="1" 
F 0 "R49" V 2794 2805 50  0000 C CNN
F 1 "10K" V 2885 2805 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2990 2805 50  0001 C CNN
F 3 "~" H 2990 2805 50  0001 C CNN
	1    2990 2805
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFA2533
P 3030 4165
AR Path="/5EBFD180/5EFA2533" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EFA2533" Ref="R52"  Part="1" 
F 0 "R52" V 2834 4165 50  0000 C CNN
F 1 "10K" V 2925 4165 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3030 4165 50  0001 C CNN
F 3 "~" H 3030 4165 50  0001 C CNN
	1    3030 4165
	0    1    1    0   
$EndComp
Wire Wire Line
	3130 4165 3195 4165
$Comp
L Device:R_Small R?
U 1 1 5EFA3B84
P 3015 5470
AR Path="/5EBFD180/5EFA3B84" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5EFA3B84" Ref="R51"  Part="1" 
F 0 "R51" V 2819 5470 50  0000 C CNN
F 1 "10K" V 2910 5470 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3015 5470 50  0001 C CNN
F 3 "~" H 3015 5470 50  0001 C CNN
	1    3015 5470
	0    1    1    0   
$EndComp
Wire Wire Line
	3115 5470 3165 5470
Wire Wire Line
	2915 5470 2865 5470
Wire Wire Line
	2930 4165 2855 4165
Wire Wire Line
	3090 2805 3195 2805
Wire Wire Line
	2890 2805 2835 2805
Wire Wire Line
	3110 1530 3205 1530
Wire Wire Line
	2910 1530 2830 1530
Wire Wire Line
	3205 1885 3095 1885
Text GLabel 3095 1885 0    50   Input ~ 0
OUTT1
Text GLabel 3095 3160 0    50   Input ~ 0
OUTT2
Wire Wire Line
	3095 3160 3195 3160
Wire Wire Line
	3195 4520 3085 4520
Text GLabel 3085 4520 0    50   Input ~ 0
OUTT3
Text GLabel 3070 5825 0    50   Input ~ 0
OUTT4
Wire Wire Line
	3070 5825 3165 5825
Connection ~ 3195 3160
Connection ~ 3195 4520
Connection ~ 3165 5825
Wire Wire Line
	3165 5825 3170 5825
Text GLabel 3815 1885 2    50   Input ~ 0
OUTTT1
Text GLabel 3805 3160 2    50   Input ~ 0
OUTTT2
Text GLabel 3805 4515 2    50   Input ~ 0
OUTTT3
Text GLabel 3775 5820 2    50   Input ~ 0
OUTTT4
$Comp
L Amplifier_Operational:TL074 U?
U 5 1 5EFB9BA8
P 4840 1840
AR Path="/5EBFD180/5EFB9BA8" Ref="U?"  Part="5" 
AR Path="/5EF10D95/5EFB9BA8" Ref="U10"  Part="5" 
F 0 "U10" H 4798 1886 50  0000 L CNN
F 1 "TL074" H 4798 1795 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4790 1940 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4890 2040 50  0001 C CNN
	5    4840 1840
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5EFB9BAF
P 4740 1500
AR Path="/5EBFD180/5EFB9BAF" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EFB9BAF" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 4740 1350 50  0001 C CNN
F 1 "+12V" H 4755 1673 50  0000 C CNN
F 2 "" H 4740 1500 50  0001 C CNN
F 3 "" H 4740 1500 50  0001 C CNN
	1    4740 1500
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 5EFB9BB5
P 4740 2190
AR Path="/5EBFD180/5EFB9BB5" Ref="#PWR?"  Part="1" 
AR Path="/5EF10D95/5EFB9BB5" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 4740 2290 50  0001 C CNN
F 1 "-12V" H 4755 2363 50  0000 C CNN
F 2 "" H 4740 2190 50  0001 C CNN
F 3 "" H 4740 2190 50  0001 C CNN
	1    4740 2190
	-1   0    0    1   
$EndComp
Wire Wire Line
	4740 2140 4740 2190
Wire Wire Line
	4740 1500 4740 1540
$EndSCHEMATC
