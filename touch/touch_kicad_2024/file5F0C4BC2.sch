EESchema Schematic File Version 4
LIBS:touch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 1230 -210 0    79   ~ 0
Notes: \n\nWe will use DAC from STM32F466 and multiplex this to sample/hold with 4051. 3 address lines for all, and enable line for each one.\n\n4051 powered by 3.3v and sample/hold amp after is either follower (for 13700) or amped 1k/1k!
$Comp
L 4xxx:4051 U?
U 1 1 5EEBC02A
P 1470 1640
F 0 "U?" H 1570 1875 50  0000 L CNN
F 1 "4051" H 1525 1655 50  0000 L CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 1470 1640 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4051bms-52bms-53bms.pdf" H 1470 1640 50  0001 C CNN
	1    1470 1640
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EEBC0E6
P 1470 2615
F 0 "#PWR?" H 1470 2365 50  0001 C CNN
F 1 "GND" H 1475 2442 50  0000 C CNN
F 2 "" H 1470 2615 50  0001 C CNN
F 3 "" H 1470 2615 50  0001 C CNN
	1    1470 2615
	1    0    0    -1  
$EndComp
Wire Wire Line
	1470 2540 1570 2540
Wire Wire Line
	1470 2540 1470 2615
Connection ~ 1470 2540
$Comp
L power:+3.3V #PWR?
U 1 1 5F0C50E5
P 1470 710
F 0 "#PWR?" H 1470 560 50  0001 C CNN
F 1 "+3.3V" H 1485 883 50  0000 C CNN
F 2 "" H 1470 710 50  0001 C CNN
F 3 "" H 1470 710 50  0001 C CNN
	1    1470 710 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1470 710  1470 740 
Wire Wire Line
	1970 1040 2095 1040
Wire Wire Line
	970  1940 855  1940
Wire Wire Line
	970  2040 850  2040
Wire Wire Line
	970  2140 845  2140
Wire Wire Line
	970  2240 840  2240
Wire Wire Line
	970  1040 905  1040
Wire Wire Line
	970  1140 910  1140
Wire Wire Line
	970  1240 910  1240
Wire Wire Line
	970  1340 905  1340
Wire Wire Line
	970  1440 900  1440
Wire Wire Line
	970  1540 895  1540
Wire Wire Line
	970  1640 890  1640
Wire Wire Line
	970  1740 890  1740
Text GLabel 855  1940 0    50   Input ~ 0
EN_LOW
Text GLabel 850  2040 0    50   Input ~ 0
SEL1
Text GLabel 845  2140 0    50   Input ~ 0
SEL2
Text GLabel 840  2240 0    50   Input ~ 0
SEL3
Text GLabel 910  1240 0    50   Input ~ 0
DAC1
Text GLabel 910  1140 0    50   Input ~ 0
DAC2
Text GLabel 905  1040 0    50   Input ~ 0
DAC3
Text GLabel 905  1340 0    50   Input ~ 0
DAC4
Text GLabel 900  1440 0    50   Input ~ 0
DAC5
Text GLabel 895  1540 0    50   Input ~ 0
DAC6
Text GLabel 890  1640 0    50   Input ~ 0
DAC7
Text GLabel 890  1740 0    50   Input ~ 0
DAC8
$Comp
L Amplifier_Operational:TL074 U?
U 1 1 5F0C50E6
P 1865 3565
F 0 "U?" H 1865 3932 50  0000 C CNN
F 1 "TL074" H 1865 3841 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1815 3665 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 1915 3765 50  0001 C CNN
	1    1865 3565
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 2 1 5F0C50E7
P 3165 3575
F 0 "U?" H 3165 3942 50  0000 C CNN
F 1 "TL074" H 3165 3851 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3115 3675 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3215 3775 50  0001 C CNN
	2    3165 3575
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 3 1 5F0C50E8
P 1865 4150
F 0 "U?" H 1865 4517 50  0000 C CNN
F 1 "TL074" H 1865 4426 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1815 4250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 1915 4350 50  0001 C CNN
	3    1865 4150
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 4 1 5F0C50E9
P 3165 4120
F 0 "U?" H 3165 4487 50  0000 C CNN
F 1 "TL074" H 3165 4396 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 3115 4220 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3215 4320 50  0001 C CNN
	4    3165 4120
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 5 1 5F0C50EA
P 875 3775
F 0 "U?" H 833 3821 50  0000 L CNN
F 1 "TL074" H 833 3730 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 825 3875 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 925 3975 50  0001 C CNN
	5    875  3775
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F0C50EB
P 1390 3565
F 0 "C?" H 1482 3611 50  0000 L CNN
F 1 "47nF" H 1482 3520 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L13.0mm_W4.0mm_P10.00mm_FKS3_FKP3_MKS4" H 1390 3565 50  0001 C CNN
F 3 "~" H 1390 3565 50  0001 C CNN
	1    1390 3565
	1    0    0    -1  
$EndComp
Wire Wire Line
	2865 3675 2865 3890
Wire Wire Line
	2865 3890 3465 3890
Wire Wire Line
	3465 3890 3465 3575
Wire Wire Line
	2865 4220 2865 4405
Wire Wire Line
	2865 4405 3465 4405
Wire Wire Line
	3465 4405 3465 4120
Wire Wire Line
	1565 4250 1565 4410
Wire Wire Line
	1565 4410 2165 4410
Wire Wire Line
	2165 4410 2165 4150
Wire Wire Line
	1565 3665 1565 3830
Wire Wire Line
	1565 3830 2165 3830
Wire Wire Line
	2165 3830 2165 3565
$Comp
L power:GND #PWR?
U 1 1 5F0C50EC
P 1390 3700
F 0 "#PWR?" H 1390 3450 50  0001 C CNN
F 1 "GND" H 1395 3527 50  0000 C CNN
F 2 "" H 1390 3700 50  0001 C CNN
F 3 "" H 1390 3700 50  0001 C CNN
	1    1390 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1390 3665 1390 3700
Wire Wire Line
	1390 3465 1565 3465
$Comp
L Device:C_Small C?
U 1 1 5EEBFC5B
P 1390 4150
F 0 "C?" H 1482 4196 50  0000 L CNN
F 1 "47nF" H 1482 4105 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L13.0mm_W4.0mm_P10.00mm_FKS3_FKP3_MKS4" H 1390 4150 50  0001 C CNN
F 3 "~" H 1390 4150 50  0001 C CNN
	1    1390 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EEBFC62
P 1390 4285
F 0 "#PWR?" H 1390 4035 50  0001 C CNN
F 1 "GND" H 1395 4112 50  0000 C CNN
F 2 "" H 1390 4285 50  0001 C CNN
F 3 "" H 1390 4285 50  0001 C CNN
	1    1390 4285
	1    0    0    -1  
$EndComp
Wire Wire Line
	1390 4250 1390 4285
Wire Wire Line
	1390 4050 1565 4050
$Comp
L Device:C_Small C?
U 1 1 5EEC01CB
P 2690 3575
F 0 "C?" H 2782 3621 50  0000 L CNN
F 1 "47nF" H 2782 3530 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L13.0mm_W4.0mm_P10.00mm_FKS3_FKP3_MKS4" H 2690 3575 50  0001 C CNN
F 3 "~" H 2690 3575 50  0001 C CNN
	1    2690 3575
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C50F0
P 2690 3710
F 0 "#PWR?" H 2690 3460 50  0001 C CNN
F 1 "GND" H 2695 3537 50  0000 C CNN
F 2 "" H 2690 3710 50  0001 C CNN
F 3 "" H 2690 3710 50  0001 C CNN
	1    2690 3710
	1    0    0    -1  
$EndComp
Wire Wire Line
	2690 3675 2690 3710
Wire Wire Line
	2690 3475 2865 3475
$Comp
L Device:C_Small C?
U 1 1 5F0C50F1
P 2690 4120
F 0 "C?" H 2782 4166 50  0000 L CNN
F 1 "47nF" H 2782 4075 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L13.0mm_W4.0mm_P10.00mm_FKS3_FKP3_MKS4" H 2690 4120 50  0001 C CNN
F 3 "~" H 2690 4120 50  0001 C CNN
	1    2690 4120
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EEC074F
P 2690 4255
F 0 "#PWR?" H 2690 4005 50  0001 C CNN
F 1 "GND" H 2695 4082 50  0000 C CNN
F 2 "" H 2690 4255 50  0001 C CNN
F 3 "" H 2690 4255 50  0001 C CNN
	1    2690 4255
	1    0    0    -1  
$EndComp
Wire Wire Line
	2690 4220 2690 4255
Wire Wire Line
	2690 4020 2865 4020
Wire Wire Line
	1390 3465 1295 3465
Connection ~ 1390 3465
Wire Wire Line
	1390 4050 1280 4050
Connection ~ 1390 4050
Wire Wire Line
	2690 3475 2635 3475
Connection ~ 2690 3475
Wire Wire Line
	2690 4020 2625 4020
Connection ~ 2690 4020
Text GLabel 1295 3465 0    50   Input ~ 0
DAC1
Text GLabel 2635 3475 0    50   Input ~ 0
DAC2
Text GLabel 1280 4050 0    50   Input ~ 0
DAC3
Text GLabel 2625 4020 0    50   Input ~ 0
DAC4
Wire Wire Line
	2165 3565 2220 3565
Connection ~ 2165 3565
Wire Wire Line
	2165 4150 2210 4150
Connection ~ 2165 4150
Wire Wire Line
	3465 4120 3520 4120
Connection ~ 3465 4120
Wire Wire Line
	3465 3575 3535 3575
Connection ~ 3465 3575
Text Label 2220 3565 0    50   ~ 0
o1
Text Label 2210 4150 0    50   ~ 0
o3
Text Label 3535 3575 0    50   ~ 0
o2
Text Label 3520 4120 0    50   ~ 0
o4
$Comp
L power:+12V #PWR?
U 1 1 5EEC59BE
P 775 3435
F 0 "#PWR?" H 775 3285 50  0001 C CNN
F 1 "+12V" H 790 3608 50  0000 C CNN
F 2 "" H 775 3435 50  0001 C CNN
F 3 "" H 775 3435 50  0001 C CNN
	1    775  3435
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 5EEC5A2D
P 775 4125
F 0 "#PWR?" H 775 4225 50  0001 C CNN
F 1 "-12V" H 790 4298 50  0000 C CNN
F 2 "" H 775 4125 50  0001 C CNN
F 3 "" H 775 4125 50  0001 C CNN
	1    775  4125
	-1   0    0    1   
$EndComp
Wire Wire Line
	775  4075 775  4125
Wire Wire Line
	775  3435 775  3475
$Comp
L Amplifier_Operational:LM13700 U?
U 2 1 5EEC943A
P 3735 1445
F 0 "U?" H 3635 1793 50  0000 C CNN
F 1 "LM13700" H 3635 1702 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 3435 1470 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 3435 1470 50  0001 C CNN
	2    3735 1445
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U?
U 3 1 5EEC9589
P 10000 1200
F 0 "U?" H 10000 1567 50  0000 C CNN
F 1 "LM13700" H 10000 1476 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 9700 1225 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 9700 1225 50  0001 C CNN
	3    10000 1200
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U?
U 4 1 5EEC968B
P 3700 905
F 0 "U?" H 3600 1253 50  0000 C CNN
F 1 "LM13700" H 3600 1162 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 3400 930 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 3400 930 50  0001 C CNN
	4    3700 905 
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U?
U 5 1 5EEC97D4
P 5100 1150
F 0 "U?" H 5058 1196 50  0000 L CNN
F 1 "LM13700" H 5058 1105 50  0000 L CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 4800 1175 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 4800 1175 50  0001 C CNN
	5    5100 1150
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 5EECA5A2
P 5000 1495
F 0 "#PWR?" H 5000 1595 50  0001 C CNN
F 1 "-12V" H 5015 1668 50  0000 C CNN
F 2 "" H 5000 1495 50  0001 C CNN
F 3 "" H 5000 1495 50  0001 C CNN
	1    5000 1495
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5EECA634
P 5000 815
F 0 "#PWR?" H 5000 665 50  0001 C CNN
F 1 "+12V" H 5015 988 50  0000 C CNN
F 2 "" H 5000 815 50  0001 C CNN
F 3 "" H 5000 815 50  0001 C CNN
	1    5000 815 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 815  5000 850 
Wire Wire Line
	5000 1450 5000 1495
Wire Wire Line
	3405 1445 3435 1445
Wire Wire Line
	3365 905  3400 905 
Text Notes 6935 585  0    79   ~ 0
current sources from o1 etc
$Comp
L Amplifier_Operational:TL074 U?
U 1 1 5F0C50FB
P 8105 745
F 0 "U?" H 8140 995 50  0000 C CNN
F 1 "TL074" H 8140 910 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8055 845 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 8155 945 50  0001 C CNN
	1    8105 745 
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 2 1 5F0C50FC
P 8095 2020
F 0 "U?" H 8095 2387 50  0000 C CNN
F 1 "TL074" H 8095 2296 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8045 2120 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 8145 2220 50  0001 C CNN
	2    8095 2020
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 3 1 5EECFD5B
P 10625 3735
F 0 "U?" H 10625 4102 50  0000 C CNN
F 1 "TL074" H 10625 4011 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 10575 3835 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 10675 3935 50  0001 C CNN
	3    10625 3735
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 4 1 5EECFDE3
P 10595 5040
F 0 "U?" H 10595 5407 50  0000 C CNN
F 1 "TL074" H 10595 5316 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 10545 5140 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 10645 5240 50  0001 C CNN
	4    10595 5040
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 5 1 5F0C50FF
P 4165 1145
F 0 "U?" H 4123 1191 50  0000 L CNN
F 1 "TL074" H 4123 1100 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4115 1245 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4215 1345 50  0001 C CNN
	5    4165 1145
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5F0C5100
P 4065 805
F 0 "#PWR?" H 4065 655 50  0001 C CNN
F 1 "+12V" H 4080 978 50  0000 C CNN
F 2 "" H 4065 805 50  0001 C CNN
F 3 "" H 4065 805 50  0001 C CNN
	1    4065 805 
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 5EECFFB5
P 4065 1495
F 0 "#PWR?" H 4065 1595 50  0001 C CNN
F 1 "-12V" H 4080 1668 50  0000 C CNN
F 2 "" H 4065 1495 50  0001 C CNN
F 3 "" H 4065 1495 50  0001 C CNN
	1    4065 1495
	-1   0    0    1   
$EndComp
Wire Wire Line
	4065 1445 4065 1495
Wire Wire Line
	4065 805  4065 845 
$Comp
L Amplifier_Operational:TL074 U?
U 1 1 5EED0EE0
P 10635 1100
F 0 "U?" H 10635 1467 50  0000 C CNN
F 1 "TL074" H 10635 1376 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 10585 1200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 10685 1300 50  0001 C CNN
	1    10635 1100
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 2 1 5EED0EE7
P 10625 2375
F 0 "U?" H 10625 2742 50  0000 C CNN
F 1 "TL074" H 10625 2651 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 10575 2475 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 10675 2575 50  0001 C CNN
	2    10625 2375
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 3 1 5EED0EEE
P 8095 3380
F 0 "U?" H 8095 3747 50  0000 C CNN
F 1 "TL074" H 8095 3656 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8045 3480 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 8145 3580 50  0001 C CNN
	3    8095 3380
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 4 1 5EED0EF5
P 8065 4685
F 0 "U?" H 8065 5052 50  0000 C CNN
F 1 "TL074" H 8065 4961 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 8015 4785 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 8115 4885 50  0001 C CNN
	4    8065 4685
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 5 1 5EED0EFC
P 4485 1120
F 0 "U?" H 4443 1166 50  0000 L CNN
F 1 "TL074" H 4443 1075 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4435 1220 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4535 1320 50  0001 C CNN
	5    4485 1120
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5EED0F03
P 4385 780
F 0 "#PWR?" H 4385 630 50  0001 C CNN
F 1 "+12V" H 4400 953 50  0000 C CNN
F 2 "" H 4385 780 50  0001 C CNN
F 3 "" H 4385 780 50  0001 C CNN
	1    4385 780 
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 5EED0F09
P 4385 1470
F 0 "#PWR?" H 4385 1570 50  0001 C CNN
F 1 "-12V" H 4400 1643 50  0000 C CNN
F 2 "" H 4385 1470 50  0001 C CNN
F 3 "" H 4385 1470 50  0001 C CNN
	1    4385 1470
	-1   0    0    1   
$EndComp
Wire Wire Line
	4385 1420 4385 1470
Wire Wire Line
	4385 780  4385 820 
$Comp
L Device:Q_PNP_BEC Q?
U 1 1 5F0C5109
P 8645 745
F 0 "Q?" H 8836 791 50  0000 L CNN
F 1 "Q_PNP_BEC" H 8836 700 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 8845 845 50  0001 C CNN
F 3 "~" H 8645 745 50  0001 C CNN
	1    8645 745 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F0C510A
P 8095 1145
F 0 "C?" V 8324 1145 50  0000 C CNN
F 1 "10N" V 8233 1145 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8095 1145 50  0001 C CNN
F 3 "~" H 8095 1145 50  0001 C CNN
	1    8095 1145
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C510B
P 8095 1450
F 0 "R?" V 7899 1450 50  0000 C CNN
F 1 "2.2K" V 7990 1450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 8095 1450 50  0001 C CNN
F 3 "~" H 8095 1450 50  0001 C CNN
	1    8095 1450
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C510C
P 7665 845
F 0 "R?" V 7469 845 50  0000 C CNN
F 1 "18K?" V 7560 845 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 7665 845 50  0001 C CNN
F 3 "~" H 7665 845 50  0001 C CNN
	1    7665 845 
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EEDAD15
P 10640 1555
F 0 "R?" V 10444 1555 50  0000 C CNN
F 1 "10K?" V 10535 1555 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 10640 1555 50  0001 C CNN
F 3 "~" H 10640 1555 50  0001 C CNN
	1    10640 1555
	0    1    1    0   
$EndComp
Wire Wire Line
	7765 845  7785 845 
Wire Wire Line
	7565 845  7535 845 
$Comp
L power:GND #PWR?
U 1 1 5EEDF812
P 7760 645
F 0 "#PWR?" H 7760 395 50  0001 C CNN
F 1 "GND" H 7765 472 50  0000 C CNN
F 2 "" H 7760 645 50  0001 C CNN
F 3 "" H 7760 645 50  0001 C CNN
	1    7760 645 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7760 645  7805 645 
Wire Wire Line
	7785 845  7785 1145
Wire Wire Line
	7785 1145 7995 1145
Connection ~ 7785 845 
Wire Wire Line
	7785 845  7805 845 
Wire Wire Line
	7785 1145 7785 1450
Wire Wire Line
	7785 1450 7995 1450
Connection ~ 7785 1145
Wire Wire Line
	8405 745  8425 745 
Wire Wire Line
	8425 745  8425 1145
Wire Wire Line
	8425 1145 8195 1145
Connection ~ 8425 745 
Wire Wire Line
	8425 745  8445 745 
Wire Wire Line
	8745 1450 8745 945 
Wire Wire Line
	8745 545  8745 465 
Text Label 8745 465  0    79   ~ 0
c1
$Comp
L Device:CP_Small C?
U 1 1 5EF06200
P 9305 1100
F 0 "C?" V 9530 1100 50  0000 C CNN
F 1 "4.7U" V 9439 1100 50  0000 C CNN
F 2 "Capacitors_THT:CP_Radial_D4.0mm_P1.50mm" H 9305 1100 50  0001 C CNN
F 3 "~" H 9305 1100 50  0001 C CNN
	1    9305 1100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C5110
P 9560 1100
F 0 "R?" V 9756 1100 50  0000 C CNN
F 1 "10K" V 9665 1100 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9560 1100 50  0001 C CNN
F 3 "~" H 9560 1100 50  0001 C CNN
	1    9560 1100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C5111
P 9650 1300
F 0 "#PWR?" H 9650 1050 50  0001 C CNN
F 1 "GND" H 9655 1127 50  0000 C CNN
F 2 "" H 9650 1300 50  0001 C CNN
F 3 "" H 9650 1300 50  0001 C CNN
	1    9650 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C5112
P 9435 1330
F 0 "#PWR?" H 9435 1080 50  0001 C CNN
F 1 "GND" H 9440 1157 50  0000 C CNN
F 2 "" H 9435 1330 50  0001 C CNN
F 3 "" H 9435 1330 50  0001 C CNN
	1    9435 1330
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF06B25
P 9435 1200
F 0 "R?" H 9376 1154 50  0000 R CNN
F 1 "220R" H 9620 1240 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9435 1200 50  0001 C CNN
F 3 "~" H 9435 1200 50  0001 C CNN
	1    9435 1200
	-1   0    0    1   
$EndComp
Wire Wire Line
	9660 1100 9700 1100
Wire Wire Line
	9405 1100 9435 1100
Wire Wire Line
	9435 1100 9460 1100
Connection ~ 9435 1100
Wire Wire Line
	9435 1300 9435 1330
Text GLabel 9170 1100 0    50   Input ~ 0
IN1
Wire Wire Line
	10300 1300 10300 1355
Text Label 10300 1355 0    50   ~ 0
c1
Wire Wire Line
	9650 1300 9700 1300
Wire Wire Line
	10300 1200 10325 1200
$Comp
L Device:C_Small C?
U 1 1 5F0C5114
P 10645 1690
F 0 "C?" V 10400 1685 50  0000 C CNN
F 1 "100P" V 10515 1695 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 10645 1690 50  0001 C CNN
F 3 "~" H 10645 1690 50  0001 C CNN
	1    10645 1690
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF151BD
P 10280 1000
F 0 "#PWR?" H 10280 750 50  0001 C CNN
F 1 "GND" H 10285 827 50  0000 C CNN
F 2 "" H 10280 1000 50  0001 C CNN
F 3 "" H 10280 1000 50  0001 C CNN
	1    10280 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10280 1000 10335 1000
Wire Wire Line
	10325 1200 10325 1555
Wire Wire Line
	10325 1555 10540 1555
Connection ~ 10325 1200
Wire Wire Line
	10325 1200 10335 1200
Wire Wire Line
	10745 1690 10935 1690
Wire Wire Line
	10325 1690 10545 1690
Wire Wire Line
	10325 1555 10325 1690
Connection ~ 10325 1555
Wire Wire Line
	10935 1100 10935 1555
Wire Wire Line
	10740 1555 10935 1555
Connection ~ 10935 1555
Wire Wire Line
	10935 1555 10935 1690
Text GLabel 10935 1100 2    50   Input ~ 0
OUT1
Text Notes 6010 85   0    79   ~ 0
+decouple caps
Text Notes 9690 535  0    79   ~ 0
VCA!
Text Notes 2005 3060 0    79   ~ 0
sample and hold
$Comp
L Amplifier_Operational:TL074 U?
U 1 1 5EF3F026
P 1535 5450
F 0 "U?" H 1535 5817 50  0000 C CNN
F 1 "TL074" H 1535 5726 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1485 5550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 1585 5650 50  0001 C CNN
	1    1535 5450
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 2 1 5EF3F02D
P 2910 5380
F 0 "U?" H 2910 5747 50  0000 C CNN
F 1 "TL074" H 2910 5656 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2860 5480 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2960 5580 50  0001 C CNN
	2    2910 5380
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 3 1 5EF3F034
P 1535 6795
F 0 "U?" H 1535 7162 50  0000 C CNN
F 1 "TL074" H 1535 7071 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 1485 6895 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 1585 6995 50  0001 C CNN
	3    1535 6795
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 4 1 5F0C5119
P 2910 6685
F 0 "U?" H 2910 7052 50  0000 C CNN
F 1 "TL074" H 2910 6961 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2860 6785 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2960 6885 50  0001 C CNN
	4    2910 6685
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL074 U?
U 5 1 5F0C511A
P 700 5735
F 0 "U?" H 658 5781 50  0000 L CNN
F 1 "TL074" H 658 5690 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 650 5835 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 750 5935 50  0001 C CNN
	5    700  5735
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5EF3F049
P 1060 5450
F 0 "C?" H 1152 5496 50  0000 L CNN
F 1 "47nF" H 1152 5405 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L13.0mm_W4.0mm_P10.00mm_FKS3_FKP3_MKS4" H 1060 5450 50  0001 C CNN
F 3 "~" H 1060 5450 50  0001 C CNN
	1    1060 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2610 5480 2610 5695
Wire Wire Line
	3210 5695 3210 5380
Wire Wire Line
	2610 6785 2610 6970
Wire Wire Line
	3210 6970 3210 6685
Wire Wire Line
	1235 6895 1235 7055
Wire Wire Line
	1235 5550 1235 5715
Wire Wire Line
	1835 5715 1835 5450
$Comp
L power:GND #PWR?
U 1 1 5EF3F05C
P 1060 5585
F 0 "#PWR?" H 1060 5335 50  0001 C CNN
F 1 "GND" H 1065 5412 50  0000 C CNN
F 2 "" H 1060 5585 50  0001 C CNN
F 3 "" H 1060 5585 50  0001 C CNN
	1    1060 5585
	1    0    0    -1  
$EndComp
Wire Wire Line
	1060 5550 1060 5585
Wire Wire Line
	1060 5350 1235 5350
$Comp
L Device:C_Small C?
U 1 1 5F0C511D
P 1060 6795
F 0 "C?" H 1152 6841 50  0000 L CNN
F 1 "47nF" H 1152 6750 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L13.0mm_W4.0mm_P10.00mm_FKS3_FKP3_MKS4" H 1060 6795 50  0001 C CNN
F 3 "~" H 1060 6795 50  0001 C CNN
	1    1060 6795
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C511E
P 1060 6930
F 0 "#PWR?" H 1060 6680 50  0001 C CNN
F 1 "GND" H 1065 6757 50  0000 C CNN
F 2 "" H 1060 6930 50  0001 C CNN
F 3 "" H 1060 6930 50  0001 C CNN
	1    1060 6930
	1    0    0    -1  
$EndComp
Wire Wire Line
	1060 6895 1060 6930
Wire Wire Line
	1060 6695 1235 6695
$Comp
L Device:C_Small C?
U 1 1 5F0C511F
P 2435 5380
F 0 "C?" H 2527 5426 50  0000 L CNN
F 1 "47nF" H 2527 5335 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L13.0mm_W4.0mm_P10.00mm_FKS3_FKP3_MKS4" H 2435 5380 50  0001 C CNN
F 3 "~" H 2435 5380 50  0001 C CNN
	1    2435 5380
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C5120
P 2435 5515
F 0 "#PWR?" H 2435 5265 50  0001 C CNN
F 1 "GND" H 2440 5342 50  0000 C CNN
F 2 "" H 2435 5515 50  0001 C CNN
F 3 "" H 2435 5515 50  0001 C CNN
	1    2435 5515
	1    0    0    -1  
$EndComp
Wire Wire Line
	2435 5480 2435 5515
Wire Wire Line
	2435 5280 2610 5280
$Comp
L Device:C_Small C?
U 1 1 5F0C5121
P 2435 6685
F 0 "C?" H 2527 6731 50  0000 L CNN
F 1 "47nF" H 2527 6640 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L13.0mm_W4.0mm_P10.00mm_FKS3_FKP3_MKS4" H 2435 6685 50  0001 C CNN
F 3 "~" H 2435 6685 50  0001 C CNN
	1    2435 6685
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C5122
P 2435 6820
F 0 "#PWR?" H 2435 6570 50  0001 C CNN
F 1 "GND" H 2440 6647 50  0000 C CNN
F 2 "" H 2435 6820 50  0001 C CNN
F 3 "" H 2435 6820 50  0001 C CNN
	1    2435 6820
	1    0    0    -1  
$EndComp
Wire Wire Line
	2435 6785 2435 6820
Wire Wire Line
	2435 6585 2610 6585
Wire Wire Line
	1060 5350 965  5350
Connection ~ 1060 5350
Wire Wire Line
	1060 6695 950  6695
Connection ~ 1060 6695
Wire Wire Line
	2435 5280 2380 5280
Connection ~ 2435 5280
Wire Wire Line
	2435 6585 2370 6585
Connection ~ 2435 6585
Text GLabel 965  5350 0    50   Input ~ 0
DAC5
Text GLabel 2380 5280 0    50   Input ~ 0
DAC6
Text GLabel 950  6695 0    50   Input ~ 0
DAC7
Text GLabel 2370 6585 0    50   Input ~ 0
DAC8
Wire Wire Line
	1835 5450 1890 5450
Connection ~ 1835 5450
Wire Wire Line
	1835 6795 1880 6795
Connection ~ 1835 6795
Wire Wire Line
	3210 6685 3265 6685
Connection ~ 3210 6685
Wire Wire Line
	3210 5380 3280 5380
Connection ~ 3210 5380
$Comp
L power:+12V #PWR?
U 1 1 5EF3F0A9
P 600 5395
F 0 "#PWR?" H 600 5245 50  0001 C CNN
F 1 "+12V" H 615 5568 50  0000 C CNN
F 2 "" H 600 5395 50  0001 C CNN
F 3 "" H 600 5395 50  0001 C CNN
	1    600  5395
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 5EF3F0AF
P 600 6085
F 0 "#PWR?" H 600 6185 50  0001 C CNN
F 1 "-12V" H 615 6258 50  0000 C CNN
F 2 "" H 600 6085 50  0001 C CNN
F 3 "" H 600 6085 50  0001 C CNN
	1    600  6085
	-1   0    0    1   
$EndComp
Wire Wire Line
	600  6035 600  6085
Wire Wire Line
	600  5395 600  5435
Wire Wire Line
	9170 1100 9205 1100
Text Label 7535 845  2    79   ~ 0
o1
Text GLabel 2095 1040 2    79   Input ~ 0
DAC
$Comp
L Device:Q_PNP_BEC Q?
U 1 1 5EF61522
P 8635 2020
F 0 "Q?" H 8826 2066 50  0000 L CNN
F 1 "Q_PNP_BEC" H 8826 1975 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 8835 2120 50  0001 C CNN
F 3 "~" H 8635 2020 50  0001 C CNN
	1    8635 2020
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5EF61529
P 8085 2420
F 0 "C?" V 8314 2420 50  0000 C CNN
F 1 "10N" V 8223 2420 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8085 2420 50  0001 C CNN
F 3 "~" H 8085 2420 50  0001 C CNN
	1    8085 2420
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C5127
P 8085 2725
F 0 "R?" V 7889 2725 50  0000 C CNN
F 1 "2.2K" V 7980 2725 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 8085 2725 50  0001 C CNN
F 3 "~" H 8085 2725 50  0001 C CNN
	1    8085 2725
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF61537
P 7655 2120
F 0 "R?" V 7459 2120 50  0000 C CNN
F 1 "18K?" V 7550 2120 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 7655 2120 50  0001 C CNN
F 3 "~" H 7655 2120 50  0001 C CNN
	1    7655 2120
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C5129
P 10630 2830
F 0 "R?" V 10434 2830 50  0000 C CNN
F 1 "10K?" V 10525 2830 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 10630 2830 50  0001 C CNN
F 3 "~" H 10630 2830 50  0001 C CNN
	1    10630 2830
	0    1    1    0   
$EndComp
Wire Wire Line
	7555 2120 7525 2120
$Comp
L power:GND #PWR?
U 1 1 5F0C512A
P 7750 1920
F 0 "#PWR?" H 7750 1670 50  0001 C CNN
F 1 "GND" H 7755 1747 50  0000 C CNN
F 2 "" H 7750 1920 50  0001 C CNN
F 3 "" H 7750 1920 50  0001 C CNN
	1    7750 1920
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 1920 7795 1920
Wire Wire Line
	7775 2120 7775 2420
Wire Wire Line
	7775 2420 7985 2420
Wire Wire Line
	7775 2420 7775 2725
Wire Wire Line
	7775 2725 7985 2725
Connection ~ 7775 2420
Wire Wire Line
	8415 2020 8415 2420
Wire Wire Line
	8415 2420 8185 2420
Wire Wire Line
	8735 2725 8735 2220
Wire Wire Line
	8735 1820 8735 1740
Text Label 8735 1740 0    79   ~ 0
c2
$Comp
L Device:CP_Small C?
U 1 1 5F0C512B
P 9295 2375
F 0 "C?" V 9520 2375 50  0000 C CNN
F 1 "4.7U" V 9429 2375 50  0000 C CNN
F 2 "Capacitors_THT:CP_Radial_D4.0mm_P1.50mm" H 9295 2375 50  0001 C CNN
F 3 "~" H 9295 2375 50  0001 C CNN
	1    9295 2375
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C512C
P 9550 2375
F 0 "R?" V 9746 2375 50  0000 C CNN
F 1 "10K" V 9655 2375 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9550 2375 50  0001 C CNN
F 3 "~" H 9550 2375 50  0001 C CNN
	1    9550 2375
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C512D
P 9640 2575
F 0 "#PWR?" H 9640 2325 50  0001 C CNN
F 1 "GND" H 9645 2402 50  0000 C CNN
F 2 "" H 9640 2575 50  0001 C CNN
F 3 "" H 9640 2575 50  0001 C CNN
	1    9640 2575
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C512E
P 9425 2605
F 0 "#PWR?" H 9425 2355 50  0001 C CNN
F 1 "GND" H 9430 2432 50  0000 C CNN
F 2 "" H 9425 2605 50  0001 C CNN
F 3 "" H 9425 2605 50  0001 C CNN
	1    9425 2605
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF6157C
P 9425 2475
F 0 "R?" H 9366 2429 50  0000 R CNN
F 1 "220R" H 9610 2515 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9425 2475 50  0001 C CNN
F 3 "~" H 9425 2475 50  0001 C CNN
	1    9425 2475
	-1   0    0    1   
$EndComp
Wire Wire Line
	9650 2375 9690 2375
Wire Wire Line
	9395 2375 9425 2375
Wire Wire Line
	9425 2375 9450 2375
Connection ~ 9425 2375
Wire Wire Line
	9425 2575 9425 2605
Text GLabel 9160 2375 0    50   Input ~ 0
IN2
Wire Wire Line
	10290 2575 10290 2630
Text Label 10290 2630 0    50   ~ 0
c2
Wire Wire Line
	9640 2575 9690 2575
$Comp
L Device:C_Small C?
U 1 1 5F0C5130
P 10635 2965
F 0 "C?" V 10390 2960 50  0000 C CNN
F 1 "100P" V 10505 2970 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 10635 2965 50  0001 C CNN
F 3 "~" H 10635 2965 50  0001 C CNN
	1    10635 2965
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C5131
P 10270 2275
F 0 "#PWR?" H 10270 2025 50  0001 C CNN
F 1 "GND" H 10275 2102 50  0000 C CNN
F 2 "" H 10270 2275 50  0001 C CNN
F 3 "" H 10270 2275 50  0001 C CNN
	1    10270 2275
	1    0    0    -1  
$EndComp
Wire Wire Line
	10270 2275 10325 2275
Wire Wire Line
	10315 2475 10315 2830
Wire Wire Line
	10315 2830 10530 2830
Wire Wire Line
	10735 2965 10925 2965
Wire Wire Line
	10315 2965 10535 2965
Wire Wire Line
	10315 2830 10315 2965
Connection ~ 10315 2830
Wire Wire Line
	10925 2375 10925 2830
Wire Wire Line
	10730 2830 10925 2830
Connection ~ 10925 2830
Wire Wire Line
	10925 2830 10925 2965
Text GLabel 10925 2375 2    50   Input ~ 0
OUT2
Wire Wire Line
	9160 2375 9195 2375
Text Label 7525 2120 2    79   ~ 0
o2
$Comp
L Device:Q_PNP_BEC Q?
U 1 1 5F0C5132
P 8635 3380
F 0 "Q?" H 8826 3426 50  0000 L CNN
F 1 "Q_PNP_BEC" H 8826 3335 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 8835 3480 50  0001 C CNN
F 3 "~" H 8635 3380 50  0001 C CNN
	1    8635 3380
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F0C5133
P 8085 3780
F 0 "C?" V 8314 3780 50  0000 C CNN
F 1 "10N" V 8223 3780 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8085 3780 50  0001 C CNN
F 3 "~" H 8085 3780 50  0001 C CNN
	1    8085 3780
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C5134
P 8085 4085
F 0 "R?" V 7889 4085 50  0000 C CNN
F 1 "2.2K" V 7980 4085 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 8085 4085 50  0001 C CNN
F 3 "~" H 8085 4085 50  0001 C CNN
	1    8085 4085
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C5135
P 7655 3480
F 0 "R?" V 7459 3480 50  0000 C CNN
F 1 "18K?" V 7550 3480 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 7655 3480 50  0001 C CNN
F 3 "~" H 7655 3480 50  0001 C CNN
	1    7655 3480
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F0C5136
P 10630 4190
F 0 "R?" V 10434 4190 50  0000 C CNN
F 1 "10K?" V 10525 4190 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 10630 4190 50  0001 C CNN
F 3 "~" H 10630 4190 50  0001 C CNN
	1    10630 4190
	0    1    1    0   
$EndComp
Wire Wire Line
	7555 3480 7525 3480
$Comp
L power:GND #PWR?
U 1 1 5F0C5137
P 7750 3280
F 0 "#PWR?" H 7750 3030 50  0001 C CNN
F 1 "GND" H 7755 3107 50  0000 C CNN
F 2 "" H 7750 3280 50  0001 C CNN
F 3 "" H 7750 3280 50  0001 C CNN
	1    7750 3280
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 3280 7795 3280
Wire Wire Line
	7775 3480 7775 3780
Wire Wire Line
	7775 3780 7985 3780
Wire Wire Line
	7775 3780 7775 4085
Wire Wire Line
	7775 4085 7985 4085
Connection ~ 7775 3780
Wire Wire Line
	8415 3380 8415 3780
Wire Wire Line
	8415 3780 8185 3780
Wire Wire Line
	8735 4085 8735 3580
Wire Wire Line
	8735 3180 8735 3100
Text Label 8735 3100 0    79   ~ 0
c3
$Comp
L Device:CP_Small C?
U 1 1 5F0C5138
P 9295 3735
F 0 "C?" V 9520 3735 50  0000 C CNN
F 1 "4.7U" V 9429 3735 50  0000 C CNN
F 2 "Capacitors_THT:CP_Radial_D4.0mm_P1.50mm" H 9295 3735 50  0001 C CNN
F 3 "~" H 9295 3735 50  0001 C CNN
	1    9295 3735
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF6829D
P 9550 3735
F 0 "R?" V 9746 3735 50  0000 C CNN
F 1 "10K" V 9655 3735 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9550 3735 50  0001 C CNN
F 3 "~" H 9550 3735 50  0001 C CNN
	1    9550 3735
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF682A4
P 9640 3935
F 0 "#PWR?" H 9640 3685 50  0001 C CNN
F 1 "GND" H 9645 3762 50  0000 C CNN
F 2 "" H 9640 3935 50  0001 C CNN
F 3 "" H 9640 3935 50  0001 C CNN
	1    9640 3935
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C513B
P 9425 3965
F 0 "#PWR?" H 9425 3715 50  0001 C CNN
F 1 "GND" H 9430 3792 50  0000 C CNN
F 2 "" H 9425 3965 50  0001 C CNN
F 3 "" H 9425 3965 50  0001 C CNN
	1    9425 3965
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF682B0
P 9425 3835
F 0 "R?" H 9366 3789 50  0000 R CNN
F 1 "220R" H 9610 3875 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9425 3835 50  0001 C CNN
F 3 "~" H 9425 3835 50  0001 C CNN
	1    9425 3835
	-1   0    0    1   
$EndComp
Wire Wire Line
	9650 3735 9690 3735
Wire Wire Line
	9395 3735 9425 3735
Wire Wire Line
	9425 3735 9450 3735
Connection ~ 9425 3735
Wire Wire Line
	9425 3935 9425 3965
Text GLabel 9160 3735 0    50   Input ~ 0
IN3
Wire Wire Line
	10290 3935 10290 3990
Text Label 10290 3990 0    50   ~ 0
c3
Wire Wire Line
	9640 3935 9690 3935
$Comp
L Device:C_Small C?
U 1 1 5EF682C1
P 10635 4325
F 0 "C?" V 10390 4320 50  0000 C CNN
F 1 "100P" V 10505 4330 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 10635 4325 50  0001 C CNN
F 3 "~" H 10635 4325 50  0001 C CNN
	1    10635 4325
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF682C8
P 10270 3635
F 0 "#PWR?" H 10270 3385 50  0001 C CNN
F 1 "GND" H 10275 3462 50  0000 C CNN
F 2 "" H 10270 3635 50  0001 C CNN
F 3 "" H 10270 3635 50  0001 C CNN
	1    10270 3635
	1    0    0    -1  
$EndComp
Wire Wire Line
	10270 3635 10325 3635
Wire Wire Line
	10315 3835 10315 4190
Wire Wire Line
	10315 4190 10530 4190
Wire Wire Line
	10735 4325 10925 4325
Wire Wire Line
	10315 4325 10535 4325
Wire Wire Line
	10315 4190 10315 4325
Connection ~ 10315 4190
Wire Wire Line
	10925 3735 10925 4190
Wire Wire Line
	10730 4190 10925 4190
Connection ~ 10925 4190
Wire Wire Line
	10925 4190 10925 4325
Text GLabel 10925 3735 2    50   Input ~ 0
OUT3
Wire Wire Line
	9160 3735 9195 3735
Text Label 7525 3480 2    79   ~ 0
o3
$Comp
L Device:Q_PNP_BEC Q?
U 1 1 5EF70FDB
P 8605 4685
F 0 "Q?" H 8796 4731 50  0000 L CNN
F 1 "Q_PNP_BEC" H 8796 4640 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 8805 4785 50  0001 C CNN
F 3 "~" H 8605 4685 50  0001 C CNN
	1    8605 4685
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5EF70FE2
P 8055 5085
F 0 "C?" V 8284 5085 50  0000 C CNN
F 1 "10N" V 8193 5085 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8055 5085 50  0001 C CNN
F 3 "~" H 8055 5085 50  0001 C CNN
	1    8055 5085
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF70FE9
P 8055 5390
F 0 "R?" V 7859 5390 50  0000 C CNN
F 1 "2.2K" V 7950 5390 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 8055 5390 50  0001 C CNN
F 3 "~" H 8055 5390 50  0001 C CNN
	1    8055 5390
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF70FF0
P 7625 4785
F 0 "R?" V 7429 4785 50  0000 C CNN
F 1 "18K?" V 7520 4785 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 7625 4785 50  0001 C CNN
F 3 "~" H 7625 4785 50  0001 C CNN
	1    7625 4785
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF70FF7
P 10600 5495
F 0 "R?" V 10404 5495 50  0000 C CNN
F 1 "10K?" V 10495 5495 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 10600 5495 50  0001 C CNN
F 3 "~" H 10600 5495 50  0001 C CNN
	1    10600 5495
	0    1    1    0   
$EndComp
Wire Wire Line
	7525 4785 7495 4785
$Comp
L power:GND #PWR?
U 1 1 5EF71000
P 7720 4585
F 0 "#PWR?" H 7720 4335 50  0001 C CNN
F 1 "GND" H 7725 4412 50  0000 C CNN
F 2 "" H 7720 4585 50  0001 C CNN
F 3 "" H 7720 4585 50  0001 C CNN
	1    7720 4585
	1    0    0    -1  
$EndComp
Wire Wire Line
	7720 4585 7765 4585
Wire Wire Line
	7745 4785 7745 5085
Wire Wire Line
	7745 5085 7955 5085
Wire Wire Line
	7745 5085 7745 5390
Wire Wire Line
	7745 5390 7955 5390
Connection ~ 7745 5085
Wire Wire Line
	8385 4685 8385 5085
Wire Wire Line
	8385 5085 8155 5085
Wire Wire Line
	8705 5390 8705 4885
Wire Wire Line
	8705 4485 8705 4405
Text Label 8705 4405 0    79   ~ 0
c4
$Comp
L Device:CP_Small C?
U 1 1 5EF7101B
P 9265 5040
F 0 "C?" V 9490 5040 50  0000 C CNN
F 1 "4.7U" V 9399 5040 50  0000 C CNN
F 2 "Capacitors_THT:CP_Radial_D4.0mm_P1.50mm" H 9265 5040 50  0001 C CNN
F 3 "~" H 9265 5040 50  0001 C CNN
	1    9265 5040
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF71022
P 9520 5040
F 0 "R?" V 9716 5040 50  0000 C CNN
F 1 "10K" V 9625 5040 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9520 5040 50  0001 C CNN
F 3 "~" H 9520 5040 50  0001 C CNN
	1    9520 5040
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0C5147
P 9610 5240
F 0 "#PWR?" H 9610 4990 50  0001 C CNN
F 1 "GND" H 9615 5067 50  0000 C CNN
F 2 "" H 9610 5240 50  0001 C CNN
F 3 "" H 9610 5240 50  0001 C CNN
	1    9610 5240
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF7102F
P 9395 5270
F 0 "#PWR?" H 9395 5020 50  0001 C CNN
F 1 "GND" H 9400 5097 50  0000 C CNN
F 2 "" H 9395 5270 50  0001 C CNN
F 3 "" H 9395 5270 50  0001 C CNN
	1    9395 5270
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EF71035
P 9395 5140
F 0 "R?" H 9336 5094 50  0000 R CNN
F 1 "220R" H 9580 5180 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9395 5140 50  0001 C CNN
F 3 "~" H 9395 5140 50  0001 C CNN
	1    9395 5140
	-1   0    0    1   
$EndComp
Wire Wire Line
	9620 5040 9660 5040
Wire Wire Line
	9365 5040 9395 5040
Wire Wire Line
	9395 5040 9420 5040
Connection ~ 9395 5040
Wire Wire Line
	9395 5240 9395 5270
Text GLabel 9130 5040 0    50   Input ~ 0
IN4
Wire Wire Line
	10260 5240 10260 5295
Text Label 10260 5295 0    50   ~ 0
c4
Wire Wire Line
	9610 5240 9660 5240
$Comp
L Device:C_Small C?
U 1 1 5EF71046
P 10605 5630
F 0 "C?" V 10360 5625 50  0000 C CNN
F 1 "100P" V 10475 5635 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 10605 5630 50  0001 C CNN
F 3 "~" H 10605 5630 50  0001 C CNN
	1    10605 5630
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF7104D
P 10240 4940
F 0 "#PWR?" H 10240 4690 50  0001 C CNN
F 1 "GND" H 10245 4767 50  0000 C CNN
F 2 "" H 10240 4940 50  0001 C CNN
F 3 "" H 10240 4940 50  0001 C CNN
	1    10240 4940
	1    0    0    -1  
$EndComp
Wire Wire Line
	10240 4940 10295 4940
Wire Wire Line
	10285 5140 10285 5495
Wire Wire Line
	10285 5495 10500 5495
Wire Wire Line
	10705 5630 10895 5630
Wire Wire Line
	10285 5630 10505 5630
Wire Wire Line
	10285 5495 10285 5630
Connection ~ 10285 5495
Wire Wire Line
	10895 5040 10895 5495
Wire Wire Line
	10700 5495 10895 5495
Connection ~ 10895 5495
Wire Wire Line
	10895 5495 10895 5630
Text GLabel 10895 5040 2    50   Input ~ 0
OUT4
Wire Wire Line
	9130 5040 9165 5040
Text Label 7495 4785 2    79   ~ 0
o4
Wire Wire Line
	7775 2120 7795 2120
Wire Wire Line
	7755 2120 7775 2120
Connection ~ 7775 2120
Wire Wire Line
	8415 2020 8435 2020
Wire Wire Line
	8395 2020 8415 2020
Connection ~ 8415 2020
Wire Wire Line
	8395 3380 8415 3380
Wire Wire Line
	8365 4685 8385 4685
Wire Wire Line
	7725 4785 7745 4785
Wire Wire Line
	10290 2475 10315 2475
Wire Wire Line
	10290 3835 10315 3835
Wire Wire Line
	10260 5140 10285 5140
$Comp
L Amplifier_Operational:LM13700 U?
U 1 1 5EFACFC0
P 9990 2475
F 0 "U?" H 9990 2842 50  0000 C CNN
F 1 "LM13700" H 9990 2751 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 9690 2500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 9690 2500 50  0001 C CNN
	1    9990 2475
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U?
U 1 1 5F0C514D
P 9990 3835
F 0 "U?" H 9990 4202 50  0000 C CNN
F 1 "LM13700" H 9990 4111 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 9690 3860 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 9690 3860 50  0001 C CNN
	1    9990 3835
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U?
U 3 1 5F0C514E
P 9960 5140
F 0 "U?" H 9960 5507 50  0000 C CNN
F 1 "LM13700" H 9960 5416 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 9660 5165 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 9660 5165 50  0001 C CNN
	3    9960 5140
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U?
U 2 1 5EFBE547
P 2855 860
F 0 "U?" H 2755 1208 50  0000 C CNN
F 1 "LM13700" H 2755 1117 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 2555 885 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 2555 885 50  0001 C CNN
	2    2855 860 
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U?
U 4 1 5EFBE80F
P 2890 1605
F 0 "U?" H 2790 1953 50  0000 C CNN
F 1 "LM13700" H 2790 1862 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 2590 1630 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 2590 1630 50  0001 C CNN
	4    2890 1605
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U?
U 5 1 5F0C5151
P 5575 1140
F 0 "U?" H 5533 1186 50  0000 L CNN
F 1 "LM13700" H 5533 1095 50  0000 L CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 5275 1165 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 5275 1165 50  0001 C CNN
	5    5575 1140
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5F0C5152
P 5475 790
F 0 "#PWR?" H 5475 640 50  0001 C CNN
F 1 "+12V" H 5490 963 50  0000 C CNN
F 2 "" H 5475 790 50  0001 C CNN
F 3 "" H 5475 790 50  0001 C CNN
	1    5475 790 
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 5F0C5153
P 5475 1490
F 0 "#PWR?" H 5475 1590 50  0001 C CNN
F 1 "-12V" H 5490 1663 50  0000 C CNN
F 2 "" H 5475 1490 50  0001 C CNN
F 3 "" H 5475 1490 50  0001 C CNN
	1    5475 1490
	-1   0    0    1   
$EndComp
Wire Wire Line
	5475 790  5475 840 
Wire Wire Line
	5475 1440 5475 1490
Wire Wire Line
	7755 3480 7775 3480
Connection ~ 7775 3480
Wire Wire Line
	7775 3480 7795 3480
Connection ~ 8415 3380
Wire Wire Line
	8415 3380 8435 3380
Connection ~ 8385 4685
Wire Wire Line
	8385 4685 8405 4685
Connection ~ 7745 4785
Wire Wire Line
	7745 4785 7765 4785
Connection ~ 10285 5140
Wire Wire Line
	10285 5140 10295 5140
Connection ~ 10315 3835
Wire Wire Line
	10315 3835 10325 3835
Connection ~ 10315 2475
Wire Wire Line
	10315 2475 10325 2475
Text Notes 2215 205  0    79   ~ 0
4x VCA, 4x voltage = 8 total per board with edge conn
Text Notes 1280 4935 0    79   ~ 0
sample and hold - amped x2 - tested
Wire Wire Line
	2555 860  2555 905 
Wire Wire Line
	2590 1605 2590 1650
$Comp
L power:GND #PWR?
U 1 1 5EF7791D
P 3365 905
F 0 "#PWR?" H 3365 655 50  0001 C CNN
F 1 "GND" H 3370 732 50  0000 C CNN
F 2 "" H 3365 905 50  0001 C CNN
F 3 "" H 3365 905 50  0001 C CNN
	1    3365 905 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF77AA6
P 3405 1445
F 0 "#PWR?" H 3405 1195 50  0001 C CNN
F 1 "GND" H 3410 1272 50  0000 C CNN
F 2 "" H 3405 1445 50  0001 C CNN
F 3 "" H 3405 1445 50  0001 C CNN
	1    3405 1445
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF78CE3
P 2555 905
F 0 "#PWR?" H 2555 655 50  0001 C CNN
F 1 "GND" H 2560 732 50  0000 C CNN
F 2 "" H 2555 905 50  0001 C CNN
F 3 "" H 2555 905 50  0001 C CNN
	1    2555 905 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF79F09
P 2590 1650
F 0 "#PWR?" H 2590 1400 50  0001 C CNN
F 1 "GND" H 2595 1477 50  0000 C CNN
F 2 "" H 2590 1650 50  0001 C CNN
F 3 "" H 2590 1650 50  0001 C CNN
	1    2590 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFAF0FE
P 1460 5715
F 0 "R?" V 1264 5715 50  0000 C CNN
F 1 "1K" V 1355 5715 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1460 5715 50  0001 C CNN
F 3 "~" H 1460 5715 50  0001 C CNN
	1    1460 5715
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFAF22D
P 2760 5695
F 0 "R?" V 2564 5695 50  0000 C CNN
F 1 "1K" V 2655 5695 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2760 5695 50  0001 C CNN
F 3 "~" H 2760 5695 50  0001 C CNN
	1    2760 5695
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFAF66B
P 1395 7055
F 0 "R?" V 1199 7055 50  0000 C CNN
F 1 "1K" V 1290 7055 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1395 7055 50  0001 C CNN
F 3 "~" H 1395 7055 50  0001 C CNN
	1    1395 7055
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFAFB20
P 2765 6970
F 0 "R?" V 2569 6970 50  0000 C CNN
F 1 "1K" V 2660 6970 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2765 6970 50  0001 C CNN
F 3 "~" H 2765 6970 50  0001 C CNN
	1    2765 6970
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFB0B8B
P 1235 5815
F 0 "R?" H 1176 5769 50  0000 R CNN
F 1 "1K" H 1176 5860 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1235 5815 50  0001 C CNN
F 3 "~" H 1235 5815 50  0001 C CNN
	1    1235 5815
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFB0D1E
P 2610 5795
F 0 "R?" H 2551 5749 50  0000 R CNN
F 1 "1K" H 2551 5840 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2610 5795 50  0001 C CNN
F 3 "~" H 2610 5795 50  0001 C CNN
	1    2610 5795
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EFB1E0F
P 1235 5950
F 0 "#PWR?" H 1235 5700 50  0001 C CNN
F 1 "GND" H 1240 5777 50  0000 C CNN
F 2 "" H 1235 5950 50  0001 C CNN
F 3 "" H 1235 5950 50  0001 C CNN
	1    1235 5950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EFB1F0D
P 2610 5930
F 0 "#PWR?" H 2610 5680 50  0001 C CNN
F 1 "GND" H 2615 5757 50  0000 C CNN
F 2 "" H 2610 5930 50  0001 C CNN
F 3 "" H 2610 5930 50  0001 C CNN
	1    2610 5930
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EFB1FBA
P 2610 7200
F 0 "#PWR?" H 2610 6950 50  0001 C CNN
F 1 "GND" H 2615 7027 50  0000 C CNN
F 2 "" H 2610 7200 50  0001 C CNN
F 3 "" H 2610 7200 50  0001 C CNN
	1    2610 7200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFB222E
P 1235 7155
F 0 "R?" H 1176 7109 50  0000 R CNN
F 1 "1K" H 1176 7200 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1235 7155 50  0001 C CNN
F 3 "~" H 1235 7155 50  0001 C CNN
	1    1235 7155
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5EFB2444
P 2610 7070
F 0 "R?" H 2551 7024 50  0000 R CNN
F 1 "1K" H 2551 7115 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2610 7070 50  0001 C CNN
F 3 "~" H 2610 7070 50  0001 C CNN
	1    2610 7070
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EFB2E1F
P 1235 7285
F 0 "#PWR?" H 1235 7035 50  0001 C CNN
F 1 "GND" H 1240 7112 50  0000 C CNN
F 2 "" H 1235 7285 50  0001 C CNN
F 3 "" H 1235 7285 50  0001 C CNN
	1    1235 7285
	1    0    0    -1  
$EndComp
Wire Wire Line
	1235 7055 1295 7055
Connection ~ 1235 7055
Wire Wire Line
	1835 6795 1835 7055
Wire Wire Line
	1235 7255 1235 7285
Wire Wire Line
	2610 6970 2665 6970
Connection ~ 2610 6970
Wire Wire Line
	2865 6970 3210 6970
Wire Wire Line
	2610 7170 2610 7200
Wire Wire Line
	2860 5695 3210 5695
Wire Wire Line
	2660 5695 2610 5695
Connection ~ 2610 5695
Wire Wire Line
	2610 5895 2610 5930
Wire Wire Line
	1235 5715 1360 5715
Connection ~ 1235 5715
Wire Wire Line
	1560 5715 1835 5715
Wire Wire Line
	1495 7055 1835 7055
Text GLabel 2130 5450 2    39   Input ~ 0
V1
Text GLabel 2125 6795 2    39   Input ~ 0
V2
Text GLabel 3495 6685 2    39   Input ~ 0
V3
Text GLabel 3510 5380 2    39   Input ~ 0
V4
$Comp
L Device:R_Small R?
U 1 1 5F38E27F
P 1990 5450
F 0 "R?" V 1794 5450 50  0000 C CNN
F 1 "1K" V 1885 5450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1990 5450 50  0001 C CNN
F 3 "~" H 1990 5450 50  0001 C CNN
	1    1990 5450
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F38E4D2
P 3380 5380
F 0 "R?" V 3184 5380 50  0000 C CNN
F 1 "1K" V 3275 5380 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3380 5380 50  0001 C CNN
F 3 "~" H 3380 5380 50  0001 C CNN
	1    3380 5380
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F38E644
P 1980 6795
F 0 "R?" V 1784 6795 50  0000 C CNN
F 1 "1K" V 1875 6795 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1980 6795 50  0001 C CNN
F 3 "~" H 1980 6795 50  0001 C CNN
	1    1980 6795
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F38ECAE
P 3365 6685
F 0 "R?" V 3169 6685 50  0000 C CNN
F 1 "1K" V 3260 6685 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3365 6685 50  0001 C CNN
F 3 "~" H 3365 6685 50  0001 C CNN
	1    3365 6685
	0    1    1    0   
$EndComp
Wire Wire Line
	3465 6685 3495 6685
Wire Wire Line
	2080 6795 2125 6795
Wire Wire Line
	2090 5450 2130 5450
Wire Wire Line
	3480 5380 3510 5380
Text Notes 3935 2285 0    79   ~ 0
40106 for freeze buttons x8 digital ins +2 rec/play
Wire Wire Line
	5955 685  5955 735 
Wire Wire Line
	5955 1735 5955 1785
$Comp
L 4xxx:40106 U?
U 7 1 5F534D9A
P 5955 1235
AR Path="/5C0A69D0/5F534D9A" Ref="U?"  Part="7" 
AR Path="/5E97CA7E/5F534D9A" Ref="U?"  Part="7" 
AR Path="/5F534D9A" Ref="U?"  Part="7" 
AR Path="/5EF10D95/5F534D9A" Ref="U?"  Part="7" 
AR Path="/5EBFD180/5F534D9A" Ref="U?"  Part="7" 
AR Path="/5F0C4BC3/5F534D9A" Ref="U?"  Part="7" 
F 0 "U?" H 6185 1281 50  0000 L CNN
F 1 "40106" H 6185 1190 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 5955 1235 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 5955 1235 50  0001 C CNN
	7    5955 1235
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F534DB6
P 5955 1785
AR Path="/5EF10D95/5F534DB6" Ref="#PWR?"  Part="1" 
AR Path="/5EBFD180/5F534DB6" Ref="#PWR?"  Part="1" 
AR Path="/5F0C4BC3/5F534DB6" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5955 1535 50  0001 C CNN
F 1 "GND" H 5960 1612 50  0000 C CNN
F 2 "" H 5955 1785 50  0001 C CNN
F 3 "" H 5955 1785 50  0001 C CNN
	1    5955 1785
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F54AB3D
P 4235 2845
AR Path="/5C0A69D0/5F54AB3D" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F54AB3D" Ref="R?"  Part="1" 
AR Path="/5F54AB3D" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F54AB3D" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F54AB3D" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F54AB3D" Ref="R?"  Part="1" 
F 0 "R?" H 4294 2891 50  0000 L CNN
F 1 "1M" H 4294 2800 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4235 2845 50  0001 C CNN
F 3 "~" H 4235 2845 50  0001 C CNN
	1    4235 2845
	1    0    0    -1  
$EndComp
Wire Wire Line
	4235 2695 4235 2745
Wire Wire Line
	4235 2945 4235 2995
Wire Wire Line
	4235 2995 4260 2995
$Comp
L 4xxx:40106 U?
U 1 1 5F54AB48
P 4560 2995
AR Path="/5C0A69D0/5F54AB48" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5F54AB48" Ref="U?"  Part="1" 
AR Path="/5F54AB48" Ref="U?"  Part="1" 
AR Path="/5EF10D95/5F54AB48" Ref="U?"  Part="1" 
AR Path="/5EBFD180/5F54AB48" Ref="U?"  Part="1" 
AR Path="/5F0C4BC3/5F54AB48" Ref="U?"  Part="1" 
F 0 "U?" H 4560 3312 50  0000 C CNN
F 1 "40106" H 4560 3221 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4560 2995 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4560 2995 50  0001 C CNN
	1    4560 2995
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F54AB4F
P 5035 2995
AR Path="/5C0A69D0/5F54AB4F" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F54AB4F" Ref="R?"  Part="1" 
AR Path="/5F54AB4F" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F54AB4F" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F54AB4F" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F54AB4F" Ref="R?"  Part="1" 
F 0 "R?" H 5094 3041 50  0000 L CNN
F 1 "1K" H 5094 2950 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5035 2995 50  0001 C CNN
F 3 "~" H 5035 2995 50  0001 C CNN
	1    5035 2995
	0    1    1    0   
$EndComp
Wire Wire Line
	4935 2995 4860 2995
Wire Wire Line
	5135 2995 5175 2995
Wire Wire Line
	4235 2995 4135 2995
Connection ~ 4235 2995
Text GLabel 4135 2995 0    79   Input ~ 0
F1
Text GLabel 5175 2995 2    79   Input ~ 0
D1
$Comp
L power:+3.3V #PWR?
U 1 1 5F6098D7
P 5955 685
F 0 "#PWR?" H 5955 535 50  0001 C CNN
F 1 "+3.3V" H 5970 858 50  0000 C CNN
F 2 "" H 5955 685 50  0001 C CNN
F 3 "" H 5955 685 50  0001 C CNN
	1    5955 685 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5F60A0CB
P 4235 2695
F 0 "#PWR?" H 4235 2545 50  0001 C CNN
F 1 "+3.3V" H 4250 2868 50  0000 C CNN
F 2 "" H 4235 2695 50  0001 C CNN
F 3 "" H 4235 2695 50  0001 C CNN
	1    4235 2695
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F60C449
P 4260 3475
AR Path="/5C0A69D0/5F60C449" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F60C449" Ref="R?"  Part="1" 
AR Path="/5F60C449" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F60C449" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F60C449" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F60C449" Ref="R?"  Part="1" 
F 0 "R?" H 4319 3521 50  0000 L CNN
F 1 "1M" H 4319 3430 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4260 3475 50  0001 C CNN
F 3 "~" H 4260 3475 50  0001 C CNN
	1    4260 3475
	1    0    0    -1  
$EndComp
Wire Wire Line
	4260 3325 4260 3375
Wire Wire Line
	4260 3575 4260 3625
Wire Wire Line
	4260 3625 4285 3625
$Comp
L Device:R_Small R?
U 1 1 5F60C45A
P 5060 3625
AR Path="/5C0A69D0/5F60C45A" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F60C45A" Ref="R?"  Part="1" 
AR Path="/5F60C45A" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F60C45A" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F60C45A" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F60C45A" Ref="R?"  Part="1" 
F 0 "R?" H 5119 3671 50  0000 L CNN
F 1 "1K" H 5119 3580 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5060 3625 50  0001 C CNN
F 3 "~" H 5060 3625 50  0001 C CNN
	1    5060 3625
	0    1    1    0   
$EndComp
Wire Wire Line
	4960 3625 4885 3625
Wire Wire Line
	5160 3625 5200 3625
Wire Wire Line
	4260 3625 4160 3625
Connection ~ 4260 3625
Text GLabel 4160 3625 0    79   Input ~ 0
F2
Text GLabel 5200 3625 2    79   Input ~ 0
D2
$Comp
L power:+3.3V #PWR?
U 1 1 5F60C467
P 4260 3325
F 0 "#PWR?" H 4260 3175 50  0001 C CNN
F 1 "+3.3V" H 4275 3498 50  0000 C CNN
F 2 "" H 4260 3325 50  0001 C CNN
F 3 "" H 4260 3325 50  0001 C CNN
	1    4260 3325
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F61DAD1
P 4235 4100
AR Path="/5C0A69D0/5F61DAD1" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F61DAD1" Ref="R?"  Part="1" 
AR Path="/5F61DAD1" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F61DAD1" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F61DAD1" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F61DAD1" Ref="R?"  Part="1" 
F 0 "R?" H 4294 4146 50  0000 L CNN
F 1 "1M" H 4294 4055 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4235 4100 50  0001 C CNN
F 3 "~" H 4235 4100 50  0001 C CNN
	1    4235 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4235 3950 4235 4000
Wire Wire Line
	4235 4200 4235 4250
Wire Wire Line
	4235 4250 4260 4250
$Comp
L Device:R_Small R?
U 1 1 5F61DAE2
P 5035 4250
AR Path="/5C0A69D0/5F61DAE2" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F61DAE2" Ref="R?"  Part="1" 
AR Path="/5F61DAE2" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F61DAE2" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F61DAE2" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F61DAE2" Ref="R?"  Part="1" 
F 0 "R?" H 5094 4296 50  0000 L CNN
F 1 "1K" H 5094 4205 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5035 4250 50  0001 C CNN
F 3 "~" H 5035 4250 50  0001 C CNN
	1    5035 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	4935 4250 4860 4250
Wire Wire Line
	5135 4250 5175 4250
Wire Wire Line
	4235 4250 4135 4250
Connection ~ 4235 4250
Text GLabel 4135 4250 0    79   Input ~ 0
F3
Text GLabel 5175 4250 2    79   Input ~ 0
D3
$Comp
L power:+3.3V #PWR?
U 1 1 5F61DAEF
P 4235 3950
F 0 "#PWR?" H 4235 3800 50  0001 C CNN
F 1 "+3.3V" H 4250 4123 50  0000 C CNN
F 2 "" H 4235 3950 50  0001 C CNN
F 3 "" H 4235 3950 50  0001 C CNN
	1    4235 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F61DAF5
P 4260 4730
AR Path="/5C0A69D0/5F61DAF5" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F61DAF5" Ref="R?"  Part="1" 
AR Path="/5F61DAF5" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F61DAF5" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F61DAF5" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F61DAF5" Ref="R?"  Part="1" 
F 0 "R?" H 4319 4776 50  0000 L CNN
F 1 "1M" H 4319 4685 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4260 4730 50  0001 C CNN
F 3 "~" H 4260 4730 50  0001 C CNN
	1    4260 4730
	1    0    0    -1  
$EndComp
Wire Wire Line
	4260 4580 4260 4630
Wire Wire Line
	4260 4830 4260 4880
Wire Wire Line
	4260 4880 4285 4880
$Comp
L Device:R_Small R?
U 1 1 5F61DB06
P 5060 4880
AR Path="/5C0A69D0/5F61DB06" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F61DB06" Ref="R?"  Part="1" 
AR Path="/5F61DB06" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F61DB06" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F61DB06" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F61DB06" Ref="R?"  Part="1" 
F 0 "R?" H 5119 4926 50  0000 L CNN
F 1 "1K" H 5119 4835 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5060 4880 50  0001 C CNN
F 3 "~" H 5060 4880 50  0001 C CNN
	1    5060 4880
	0    1    1    0   
$EndComp
Wire Wire Line
	4960 4880 4885 4880
Wire Wire Line
	5160 4880 5200 4880
Wire Wire Line
	4260 4880 4160 4880
Connection ~ 4260 4880
Text GLabel 4160 4880 0    79   Input ~ 0
F4
Text GLabel 5200 4880 2    79   Input ~ 0
D4
$Comp
L power:+3.3V #PWR?
U 1 1 5F61DB13
P 4260 4580
F 0 "#PWR?" H 4260 4430 50  0001 C CNN
F 1 "+3.3V" H 4275 4753 50  0000 C CNN
F 2 "" H 4260 4580 50  0001 C CNN
F 3 "" H 4260 4580 50  0001 C CNN
	1    4260 4580
	1    0    0    -1  
$EndComp
Wire Wire Line
	6760 680  6760 730 
Wire Wire Line
	6760 1730 6760 1780
$Comp
L 4xxx:40106 U?
U 7 1 5F675B92
P 6760 1230
AR Path="/5C0A69D0/5F675B92" Ref="U?"  Part="7" 
AR Path="/5E97CA7E/5F675B92" Ref="U?"  Part="7" 
AR Path="/5F675B92" Ref="U?"  Part="7" 
AR Path="/5EF10D95/5F675B92" Ref="U?"  Part="7" 
AR Path="/5EBFD180/5F675B92" Ref="U?"  Part="7" 
AR Path="/5F0C4BC3/5F675B92" Ref="U?"  Part="7" 
F 0 "U?" H 6990 1276 50  0000 L CNN
F 1 "40106" H 6990 1185 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6760 1230 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 6760 1230 50  0001 C CNN
	7    6760 1230
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F675BA2
P 6760 1780
AR Path="/5EF10D95/5F675BA2" Ref="#PWR?"  Part="1" 
AR Path="/5EBFD180/5F675BA2" Ref="#PWR?"  Part="1" 
AR Path="/5F0C4BC3/5F675BA2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6760 1530 50  0001 C CNN
F 1 "GND" H 6765 1607 50  0000 C CNN
F 2 "" H 6760 1780 50  0001 C CNN
F 3 "" H 6760 1780 50  0001 C CNN
	1    6760 1780
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5F675BAE
P 6760 680
F 0 "#PWR?" H 6760 530 50  0001 C CNN
F 1 "+3.3V" H 6775 853 50  0000 C CNN
F 2 "" H 6760 680 50  0001 C CNN
F 3 "" H 6760 680 50  0001 C CNN
	1    6760 680 
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F6B1AA0
P 5905 2825
AR Path="/5C0A69D0/5F6B1AA0" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6B1AA0" Ref="R?"  Part="1" 
AR Path="/5F6B1AA0" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6B1AA0" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6B1AA0" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1AA0" Ref="R?"  Part="1" 
F 0 "R?" H 5964 2871 50  0000 L CNN
F 1 "1M" H 5964 2780 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5905 2825 50  0001 C CNN
F 3 "~" H 5905 2825 50  0001 C CNN
	1    5905 2825
	1    0    0    -1  
$EndComp
Wire Wire Line
	5905 2675 5905 2725
Wire Wire Line
	5905 2925 5905 2975
Wire Wire Line
	5905 2975 5930 2975
$Comp
L Device:R_Small R?
U 1 1 5F6B1AB1
P 6705 2975
AR Path="/5C0A69D0/5F6B1AB1" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6B1AB1" Ref="R?"  Part="1" 
AR Path="/5F6B1AB1" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6B1AB1" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6B1AB1" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1AB1" Ref="R?"  Part="1" 
F 0 "R?" H 6764 3021 50  0000 L CNN
F 1 "1K" H 6764 2930 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6705 2975 50  0001 C CNN
F 3 "~" H 6705 2975 50  0001 C CNN
	1    6705 2975
	0    1    1    0   
$EndComp
Wire Wire Line
	6605 2975 6530 2975
Wire Wire Line
	6805 2975 6845 2975
Wire Wire Line
	5905 2975 5805 2975
Connection ~ 5905 2975
Text GLabel 5805 2975 0    79   Input ~ 0
F5
Text GLabel 6845 2975 2    79   Input ~ 0
D5
$Comp
L power:+3.3V #PWR?
U 1 1 5F6B1ABE
P 5905 2675
F 0 "#PWR?" H 5905 2525 50  0001 C CNN
F 1 "+3.3V" H 5920 2848 50  0000 C CNN
F 2 "" H 5905 2675 50  0001 C CNN
F 3 "" H 5905 2675 50  0001 C CNN
	1    5905 2675
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F6B1AC4
P 5930 3455
AR Path="/5C0A69D0/5F6B1AC4" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6B1AC4" Ref="R?"  Part="1" 
AR Path="/5F6B1AC4" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6B1AC4" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6B1AC4" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1AC4" Ref="R?"  Part="1" 
F 0 "R?" H 5989 3501 50  0000 L CNN
F 1 "1M" H 5989 3410 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5930 3455 50  0001 C CNN
F 3 "~" H 5930 3455 50  0001 C CNN
	1    5930 3455
	1    0    0    -1  
$EndComp
Wire Wire Line
	5930 3305 5930 3355
Wire Wire Line
	5930 3555 5930 3605
Wire Wire Line
	5930 3605 5955 3605
$Comp
L Device:R_Small R?
U 1 1 5F6B1AD5
P 6730 3605
AR Path="/5C0A69D0/5F6B1AD5" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6B1AD5" Ref="R?"  Part="1" 
AR Path="/5F6B1AD5" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6B1AD5" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6B1AD5" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1AD5" Ref="R?"  Part="1" 
F 0 "R?" H 6789 3651 50  0000 L CNN
F 1 "1K" H 6789 3560 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6730 3605 50  0001 C CNN
F 3 "~" H 6730 3605 50  0001 C CNN
	1    6730 3605
	0    1    1    0   
$EndComp
Wire Wire Line
	6630 3605 6555 3605
Wire Wire Line
	6830 3605 6870 3605
Wire Wire Line
	5930 3605 5830 3605
Connection ~ 5930 3605
Text GLabel 5830 3605 0    79   Input ~ 0
F6
Text GLabel 6870 3605 2    79   Input ~ 0
D6
$Comp
L power:+3.3V #PWR?
U 1 1 5F6B1AE2
P 5930 3305
F 0 "#PWR?" H 5930 3155 50  0001 C CNN
F 1 "+3.3V" H 5945 3478 50  0000 C CNN
F 2 "" H 5930 3305 50  0001 C CNN
F 3 "" H 5930 3305 50  0001 C CNN
	1    5930 3305
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F6B1AE8
P 5905 4080
AR Path="/5C0A69D0/5F6B1AE8" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6B1AE8" Ref="R?"  Part="1" 
AR Path="/5F6B1AE8" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6B1AE8" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6B1AE8" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1AE8" Ref="R?"  Part="1" 
F 0 "R?" H 5964 4126 50  0000 L CNN
F 1 "1M" H 5964 4035 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5905 4080 50  0001 C CNN
F 3 "~" H 5905 4080 50  0001 C CNN
	1    5905 4080
	1    0    0    -1  
$EndComp
Wire Wire Line
	5905 3930 5905 3980
Wire Wire Line
	5905 4180 5905 4230
Wire Wire Line
	5905 4230 5930 4230
$Comp
L Device:R_Small R?
U 1 1 5F6B1AF9
P 6705 4230
AR Path="/5C0A69D0/5F6B1AF9" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6B1AF9" Ref="R?"  Part="1" 
AR Path="/5F6B1AF9" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6B1AF9" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6B1AF9" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1AF9" Ref="R?"  Part="1" 
F 0 "R?" H 6764 4276 50  0000 L CNN
F 1 "1K" H 6764 4185 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6705 4230 50  0001 C CNN
F 3 "~" H 6705 4230 50  0001 C CNN
	1    6705 4230
	0    1    1    0   
$EndComp
Wire Wire Line
	6605 4230 6530 4230
Wire Wire Line
	6805 4230 6845 4230
Wire Wire Line
	5905 4230 5805 4230
Connection ~ 5905 4230
Text GLabel 5805 4230 0    79   Input ~ 0
F7
Text GLabel 6845 4230 2    79   Input ~ 0
D7
$Comp
L power:+3.3V #PWR?
U 1 1 5F6B1B06
P 5905 3930
F 0 "#PWR?" H 5905 3780 50  0001 C CNN
F 1 "+3.3V" H 5920 4103 50  0000 C CNN
F 2 "" H 5905 3930 50  0001 C CNN
F 3 "" H 5905 3930 50  0001 C CNN
	1    5905 3930
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F6B1B0C
P 5930 4710
AR Path="/5C0A69D0/5F6B1B0C" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6B1B0C" Ref="R?"  Part="1" 
AR Path="/5F6B1B0C" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6B1B0C" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6B1B0C" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1B0C" Ref="R?"  Part="1" 
F 0 "R?" H 5989 4756 50  0000 L CNN
F 1 "1M" H 5989 4665 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5930 4710 50  0001 C CNN
F 3 "~" H 5930 4710 50  0001 C CNN
	1    5930 4710
	1    0    0    -1  
$EndComp
Wire Wire Line
	5930 4560 5930 4610
Wire Wire Line
	5930 4810 5930 4860
Wire Wire Line
	5930 4860 5955 4860
$Comp
L Device:R_Small R?
U 1 1 5F6B1B1D
P 6730 4860
AR Path="/5C0A69D0/5F6B1B1D" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6B1B1D" Ref="R?"  Part="1" 
AR Path="/5F6B1B1D" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6B1B1D" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6B1B1D" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1B1D" Ref="R?"  Part="1" 
F 0 "R?" H 6789 4906 50  0000 L CNN
F 1 "1K" H 6789 4815 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6730 4860 50  0001 C CNN
F 3 "~" H 6730 4860 50  0001 C CNN
	1    6730 4860
	0    1    1    0   
$EndComp
Wire Wire Line
	6630 4860 6555 4860
Wire Wire Line
	6830 4860 6870 4860
Wire Wire Line
	5930 4860 5830 4860
Connection ~ 5930 4860
Text GLabel 5830 4860 0    79   Input ~ 0
F8
Text GLabel 6870 4860 2    79   Input ~ 0
D8
$Comp
L power:+3.3V #PWR?
U 1 1 5F6B1B2A
P 5930 4560
F 0 "#PWR?" H 5930 4410 50  0001 C CNN
F 1 "+3.3V" H 5945 4733 50  0000 C CNN
F 2 "" H 5930 4560 50  0001 C CNN
F 3 "" H 5930 4560 50  0001 C CNN
	1    5930 4560
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 1 1 5F6B1B16
P 6230 2975
AR Path="/5C0A69D0/5F6B1B16" Ref="U?"  Part="1" 
AR Path="/5E97CA7E/5F6B1B16" Ref="U?"  Part="1" 
AR Path="/5F6B1B16" Ref="U?"  Part="1" 
AR Path="/5EF10D95/5F6B1B16" Ref="U?"  Part="1" 
AR Path="/5EBFD180/5F6B1B16" Ref="U?"  Part="1" 
AR Path="/5F0C4BC3/5F6B1B16" Ref="U?"  Part="1" 
F 0 "U?" H 6230 3292 50  0000 C CNN
F 1 "40106" H 6230 3201 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6230 2975 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 6230 2975 50  0001 C CNN
	1    6230 2975
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 2 1 5F6CE9F3
P 4585 3625
F 0 "U?" H 4585 3942 50  0000 C CNN
F 1 "40106" H 4585 3851 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4585 3625 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4585 3625 50  0001 C CNN
	2    4585 3625
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 2 1 5F6CECF7
P 6255 3605
F 0 "U?" H 6255 3922 50  0000 C CNN
F 1 "40106" H 6255 3831 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6255 3605 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 6255 3605 50  0001 C CNN
	2    6255 3605
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 3 1 5F6CF0D7
P 6230 4230
F 0 "U?" H 6230 4547 50  0000 C CNN
F 1 "40106" H 6230 4456 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6230 4230 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 6230 4230 50  0001 C CNN
	3    6230 4230
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 4 1 5F6CF37E
P 6255 4860
F 0 "U?" H 6255 5177 50  0000 C CNN
F 1 "40106" H 6255 5086 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6255 4860 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 6255 4860 50  0001 C CNN
	4    6255 4860
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 4 1 5F6CF65D
P 4585 4880
F 0 "U?" H 4585 5197 50  0000 C CNN
F 1 "40106" H 4585 5106 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4585 4880 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4585 4880 50  0001 C CNN
	4    4585 4880
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 3 1 5F6CFA7A
P 4560 4250
F 0 "U?" H 4560 4567 50  0000 C CNN
F 1 "40106" H 4560 4476 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4560 4250 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4560 4250 50  0001 C CNN
	3    4560 4250
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 5 1 5F6E8B25
P 6300 5605
F 0 "U?" H 6300 5922 50  0000 C CNN
F 1 "40106" H 6300 5831 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 6300 5605 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 6300 5605 50  0001 C CNN
	5    6300 5605
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:40106 U?
U 5 1 5F6E8CC7
P 4630 5625
F 0 "U?" H 4630 5942 50  0000 C CNN
F 1 "40106" H 4630 5851 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 4630 5625 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/HEF40106B.pdf" H 4630 5625 50  0001 C CNN
	5    4630 5625
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F6E91D8
P 4305 5475
AR Path="/5C0A69D0/5F6E91D8" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6E91D8" Ref="R?"  Part="1" 
AR Path="/5F6E91D8" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6E91D8" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6E91D8" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6E91D8" Ref="R?"  Part="1" 
F 0 "R?" H 4364 5521 50  0000 L CNN
F 1 "1M" H 4364 5430 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4305 5475 50  0001 C CNN
F 3 "~" H 4305 5475 50  0001 C CNN
	1    4305 5475
	1    0    0    -1  
$EndComp
Wire Wire Line
	4305 5325 4305 5375
Wire Wire Line
	4305 5575 4305 5625
Wire Wire Line
	4305 5625 4330 5625
$Comp
L Device:R_Small R?
U 1 1 5F6E91E2
P 5105 5625
AR Path="/5C0A69D0/5F6E91E2" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6E91E2" Ref="R?"  Part="1" 
AR Path="/5F6E91E2" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6E91E2" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6E91E2" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6E91E2" Ref="R?"  Part="1" 
F 0 "R?" H 5164 5671 50  0000 L CNN
F 1 "1K" H 5164 5580 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5105 5625 50  0001 C CNN
F 3 "~" H 5105 5625 50  0001 C CNN
	1    5105 5625
	0    1    1    0   
$EndComp
Wire Wire Line
	5005 5625 4930 5625
Wire Wire Line
	5205 5625 5245 5625
Wire Wire Line
	4305 5625 4205 5625
Connection ~ 4305 5625
Text GLabel 4205 5625 0    79   Input ~ 0
R1
Text GLabel 5245 5625 2    79   Input ~ 0
D9
$Comp
L power:+3.3V #PWR?
U 1 1 5F6E91EF
P 4305 5325
F 0 "#PWR?" H 4305 5175 50  0001 C CNN
F 1 "+3.3V" H 4320 5498 50  0000 C CNN
F 2 "" H 4305 5325 50  0001 C CNN
F 3 "" H 4305 5325 50  0001 C CNN
	1    4305 5325
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5F6E91F5
P 5975 5455
AR Path="/5C0A69D0/5F6E91F5" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6E91F5" Ref="R?"  Part="1" 
AR Path="/5F6E91F5" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6E91F5" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6E91F5" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6E91F5" Ref="R?"  Part="1" 
F 0 "R?" H 6034 5501 50  0000 L CNN
F 1 "1M" H 6034 5410 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 5975 5455 50  0001 C CNN
F 3 "~" H 5975 5455 50  0001 C CNN
	1    5975 5455
	1    0    0    -1  
$EndComp
Wire Wire Line
	5975 5305 5975 5355
Wire Wire Line
	5975 5555 5975 5605
Wire Wire Line
	5975 5605 6000 5605
$Comp
L Device:R_Small R?
U 1 1 5F6E91FF
P 6775 5605
AR Path="/5C0A69D0/5F6E91FF" Ref="R?"  Part="1" 
AR Path="/5E97CA7E/5F6E91FF" Ref="R?"  Part="1" 
AR Path="/5F6E91FF" Ref="R?"  Part="1" 
AR Path="/5EF10D95/5F6E91FF" Ref="R?"  Part="1" 
AR Path="/5EBFD180/5F6E91FF" Ref="R?"  Part="1" 
AR Path="/5F0C4BC3/5F6E91FF" Ref="R?"  Part="1" 
F 0 "R?" H 6834 5651 50  0000 L CNN
F 1 "1K" H 6834 5560 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6775 5605 50  0001 C CNN
F 3 "~" H 6775 5605 50  0001 C CNN
	1    6775 5605
	0    1    1    0   
$EndComp
Wire Wire Line
	6675 5605 6600 5605
Wire Wire Line
	6875 5605 6915 5605
Wire Wire Line
	5975 5605 5875 5605
Connection ~ 5975 5605
Text GLabel 5875 5605 0    79   Input ~ 0
R2
Text GLabel 6915 5605 2    79   Input ~ 0
D10
$Comp
L power:+3.3V #PWR?
U 1 1 5F6E920C
P 5975 5305
F 0 "#PWR?" H 5975 5155 50  0001 C CNN
F 1 "+3.3V" H 5990 5478 50  0000 C CNN
F 2 "" H 5975 5305 50  0001 C CNN
F 3 "" H 5975 5305 50  0001 C CNN
	1    5975 5305
	1    0    0    -1  
$EndComp
Wire Wire Line
	1235 5915 1235 5950
Wire Wire Line
	8195 1450 8745 1450
Wire Wire Line
	8185 2725 8735 2725
Wire Wire Line
	8185 4085 8735 4085
Wire Wire Line
	8155 5390 8705 5390
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 5EFE2A6D
P 3185 7255
F 0 "J?" H 3265 7247 50  0000 L CNN
F 1 "Conn_01x04" H 3265 7156 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 3185 7255 50  0001 C CNN
F 3 "~" H 3185 7255 50  0001 C CNN
	1    3185 7255
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 5F0451B1
P 9620 5965
F 0 "J?" H 9700 5957 50  0000 L CNN
F 1 "Conn_01x04" H 9700 5866 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 9620 5965 50  0001 C CNN
F 3 "~" H 9620 5965 50  0001 C CNN
	1    9620 5965
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5F05E126
P 4480 6440
F 0 "J?" H 4560 6482 50  0000 L CNN
F 1 "Conn_01x05" H 4560 6391 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 4480 6440 50  0001 C CNN
F 3 "~" H 4480 6440 50  0001 C CNN
	1    4480 6440
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5F05E39E
P 6310 6385
F 0 "J?" H 6390 6427 50  0000 L CNN
F 1 "Conn_01x05" H 6390 6336 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 6310 6385 50  0001 C CNN
F 3 "~" H 6310 6385 50  0001 C CNN
	1    6310 6385
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5F05E502
P 4460 7155
F 0 "J?" H 4540 7197 50  0000 L CNN
F 1 "Conn_01x05" H 4540 7106 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 4460 7155 50  0001 C CNN
F 3 "~" H 4460 7155 50  0001 C CNN
	1    4460 7155
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5F05E68A
P 6310 7095
F 0 "J?" H 6390 7137 50  0000 L CNN
F 1 "Conn_01x05" H 6390 7046 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 6310 7095 50  0001 C CNN
F 3 "~" H 6310 7095 50  0001 C CNN
	1    6310 7095
	1    0    0    -1  
$EndComp
Wire Wire Line
	2340 2075 2270 2075
Wire Wire Line
	2340 2175 2270 2175
Wire Wire Line
	2340 2275 2265 2275
Wire Wire Line
	2340 2375 2265 2375
Text GLabel 2270 2075 0    50   Input ~ 0
EN_LOW
Text GLabel 2270 2175 0    50   Input ~ 0
SEL1
Text GLabel 2265 2275 0    50   Input ~ 0
SEL2
Text GLabel 2265 2375 0    50   Input ~ 0
SEL3
Wire Wire Line
	9420 5865 9315 5865
Wire Wire Line
	9420 5965 9325 5965
Text GLabel 9315 5865 0    50   Input ~ 0
IN1
Text GLabel 9325 5965 0    50   Input ~ 0
IN2
Wire Wire Line
	9420 6065 9315 6065
Wire Wire Line
	9420 6165 9325 6165
Text GLabel 9315 6065 0    50   Input ~ 0
IN3
Text GLabel 9325 6165 0    50   Input ~ 0
IN4
Text GLabel 4185 6240 0    39   Input ~ 0
F1
Wire Wire Line
	4185 6240 4280 6240
Text GLabel 4185 6340 0    39   Input ~ 0
F2
Wire Wire Line
	4185 6340 4280 6340
Text GLabel 4185 6440 0    39   Input ~ 0
F3
Wire Wire Line
	4185 6440 4280 6440
Text GLabel 4185 6540 0    39   Input ~ 0
F4
Wire Wire Line
	4185 6540 4280 6540
Text GLabel 6015 6185 0    39   Input ~ 0
F5
Wire Wire Line
	6015 6185 6110 6185
Text GLabel 6015 6285 0    39   Input ~ 0
F6
Wire Wire Line
	6015 6285 6110 6285
Text GLabel 6015 6385 0    39   Input ~ 0
F7
Wire Wire Line
	6015 6385 6110 6385
Text GLabel 6015 6485 0    39   Input ~ 0
F8
Wire Wire Line
	6015 6485 6110 6485
Text GLabel 4185 6640 0    39   Input ~ 0
R1
Wire Wire Line
	4185 6640 4280 6640
Text GLabel 6015 6585 0    39   Input ~ 0
R2
Wire Wire Line
	6015 6585 6110 6585
Text GLabel 4165 6955 0    39   Input ~ 0
D1
Wire Wire Line
	4165 6955 4260 6955
Text GLabel 4165 7055 0    39   Input ~ 0
D2
Wire Wire Line
	4165 7055 4260 7055
Text GLabel 4165 7155 0    39   Input ~ 0
D3
Wire Wire Line
	4165 7155 4260 7155
Text GLabel 4165 7255 0    39   Input ~ 0
D4
Wire Wire Line
	4165 7255 4260 7255
Text GLabel 6015 6895 0    39   Input ~ 0
D5
Wire Wire Line
	6015 6895 6110 6895
Text GLabel 6015 6995 0    39   Input ~ 0
D6
Wire Wire Line
	6015 6995 6110 6995
Text GLabel 6015 7095 0    39   Input ~ 0
D7
Wire Wire Line
	6015 7095 6110 7095
Text GLabel 6015 7195 0    39   Input ~ 0
D8
Wire Wire Line
	6015 7195 6110 7195
Text GLabel 4165 7355 0    39   Input ~ 0
D9
Text GLabel 6015 7295 0    39   Input ~ 0
D10
Wire Wire Line
	6015 7295 6110 7295
Wire Wire Line
	4165 7355 4260 7355
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 5F24F491
P 2540 2275
F 0 "J?" H 2620 2317 50  0000 L CNN
F 1 "Conn_01x05" H 2620 2226 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 2540 2275 50  0001 C CNN
F 3 "~" H 2540 2275 50  0001 C CNN
	1    2540 2275
	1    0    0    -1  
$EndComp
Wire Wire Line
	2985 7355 2910 7355
Wire Wire Line
	2985 7255 2910 7255
Wire Wire Line
	2985 7155 2905 7155
Text GLabel 2915 7455 0    39   Input ~ 0
V4
Text GLabel 2910 7355 0    39   Input ~ 0
V3
Text GLabel 2910 7255 0    39   Input ~ 0
V2
Text GLabel 2905 7155 0    39   Input ~ 0
V1
Wire Wire Line
	2985 7455 2915 7455
Text GLabel 2245 2475 0    39   Input ~ 0
DAC
Wire Wire Line
	2245 2475 2340 2475
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 5F3597E6
P 8710 5955
F 0 "J?" H 8790 5947 50  0000 L CNN
F 1 "Conn_01x04" H 8790 5856 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 8710 5955 50  0001 C CNN
F 3 "~" H 8710 5955 50  0001 C CNN
	1    8710 5955
	1    0    0    -1  
$EndComp
Wire Wire Line
	8510 5855 8405 5855
Wire Wire Line
	8510 5955 8415 5955
Text GLabel 8405 5855 0    50   Input ~ 0
IN1
Text GLabel 8415 5955 0    50   Input ~ 0
IN2
Wire Wire Line
	8510 6055 8405 6055
Wire Wire Line
	8510 6155 8415 6155
Text GLabel 8405 6055 0    50   Input ~ 0
IN3
Text GLabel 8415 6155 0    50   Input ~ 0
IN4
Text Notes 8285 6330 0    79   ~ 0
for panel and for circuit
Text Notes -265 840  0    50   ~ 0
swapped DAC1 and DAC3 for layout
$EndSCHEMATC
