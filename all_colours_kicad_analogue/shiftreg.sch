EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 9
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
L 4xxx_IEEE:4015 U7
U 1 1 5BC8EBAC
P 4850 2150
F 0 "U7" H 4550 2525 50  0000 C CNN
F 1 "4015" H 4550 2450 50  0000 C CNN
F 2 "SMD_Packages:SO-16-N" H 4850 2150 60  0001 C CNN
F 3 "" H 4850 2150 60  0001 C CNN
	1    4850 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2000 4150 2000
Text Label 4150 2000 0    60   ~ 0
CLOCK
$Comp
L power:GND #PWR090
U 1 1 5BCE011A
P 4850 2475
F 0 "#PWR090" H 4850 2225 50  0001 C CNN
F 1 "GND" H 4855 2302 50  0000 C CNN
F 2 "" H 4850 2475 50  0001 C CNN
F 3 "" H 4850 2475 50  0001 C CNN
	1    4850 2475
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2400 4850 2475
$Comp
L allcolours_analogue-rescue:+12V-power #PWR089
U 1 1 5BCE01B6
P 4850 1850
F 0 "#PWR089" H 4850 1700 50  0001 C CNN
F 1 "+12V-power" H 4865 2023 50  0000 C CNN
F 2 "" H 4850 1850 50  0001 C CNN
F 3 "" H 4850 1850 50  0001 C CNN
	1    4850 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 1900 4850 1850
$Comp
L Device:C_Small C37
U 1 1 5BCE0223
P 3310 3000
F 0 "C37" H 3402 3046 50  0000 L CNN
F 1 "100N" H 3402 2955 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3310 3000 50  0001 C CNN
F 3 "~" H 3310 3000 50  0001 C CNN
	1    3310 3000
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR095
U 1 1 5BCE0273
P 3310 2850
F 0 "#PWR095" H 3310 2700 50  0001 C CNN
F 1 "+12V-power" H 3325 3023 50  0000 C CNN
F 2 "" H 3310 2850 50  0001 C CNN
F 3 "" H 3310 2850 50  0001 C CNN
	1    3310 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR096
U 1 1 5BCE0282
P 3310 3150
F 0 "#PWR096" H 3310 2900 50  0001 C CNN
F 1 "GND" H 3315 2977 50  0000 C CNN
F 2 "" H 3310 3150 50  0001 C CNN
F 3 "" H 3310 3150 50  0001 C CNN
	1    3310 3150
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R50
U 1 1 5BCE0372
P 5450 2400
F 0 "R50" H 5509 2446 50  0000 L CNN
F 1 "10K" H 5509 2355 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5450 2400 50  0001 C CNN
F 3 "" H 5450 2400 50  0001 C CNN
	1    5450 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C38
U 1 1 5BCE03FF
P 5450 2650
F 0 "C38" H 5542 2696 50  0000 L CNN
F 1 "1N" H 5542 2605 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5450 2650 50  0001 C CNN
F 3 "~" H 5450 2650 50  0001 C CNN
	1    5450 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR097
U 1 1 5BCE04B5
P 5450 2800
F 0 "#PWR097" H 5450 2550 50  0001 C CNN
F 1 "GND" H 5455 2627 50  0000 C CNN
F 2 "" H 5450 2800 50  0001 C CNN
F 3 "" H 5450 2800 50  0001 C CNN
	1    5450 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2300 5450 2300
Wire Wire Line
	5450 2550 5450 2525
Wire Wire Line
	5450 2800 5450 2750
Wire Wire Line
	5400 2000 5500 2000
Wire Wire Line
	5400 2100 5500 2100
Wire Wire Line
	5400 2200 5500 2200
Wire Wire Line
	5450 2300 5500 2300
Connection ~ 5450 2300
$Comp
L power:GND #PWR083
U 1 1 5BCE1696
P 4250 2300
F 0 "#PWR083" H 4250 2050 50  0001 C CNN
F 1 "GND" H 4255 2127 50  0000 C CNN
F 2 "" H 4250 2300 50  0001 C CNN
F 3 "" H 4250 2300 50  0001 C CNN
	1    4250 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4225 2150 4300 2150
Wire Wire Line
	4250 2300 4300 2300
Wire Wire Line
	3310 2900 3310 2850
Wire Wire Line
	3310 3150 3310 3100
$Comp
L 4xxx_IEEE:4015 U7
U 2 1 5BCE34F1
P 4850 3425
F 0 "U7" H 4550 3800 50  0000 C CNN
F 1 "4015" H 4550 3725 50  0000 C CNN
F 2 "SMD_Packages:SO-16-N" H 4850 3425 60  0001 C CNN
F 3 "" H 4850 3425 60  0001 C CNN
	2    4850 3425
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3275 4150 3275
Text Label 4150 3275 0    60   ~ 0
CLOCK
$Comp
L power:GND #PWR092
U 1 1 5BCE34F9
P 4850 3750
F 0 "#PWR092" H 4850 3500 50  0001 C CNN
F 1 "GND" H 4855 3577 50  0000 C CNN
F 2 "" H 4850 3750 50  0001 C CNN
F 3 "" H 4850 3750 50  0001 C CNN
	1    4850 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3675 4850 3750
$Comp
L allcolours_analogue-rescue:+12V-power #PWR091
U 1 1 5BCE3500
P 4850 3125
F 0 "#PWR091" H 4850 2975 50  0001 C CNN
F 1 "+12V-power" H 4865 3298 50  0000 C CNN
F 2 "" H 4850 3125 50  0001 C CNN
F 3 "" H 4850 3125 50  0001 C CNN
	1    4850 3125
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3175 4850 3125
$Comp
L allcolours_analogue-rescue:R_Small-device R51
U 1 1 5BCE3507
P 5450 3675
F 0 "R51" H 5509 3721 50  0000 L CNN
F 1 "10K" H 5509 3630 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 5450 3675 50  0001 C CNN
F 3 "" H 5450 3675 50  0001 C CNN
	1    5450 3675
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C39
U 1 1 5BCE350D
P 5450 3925
F 0 "C39" H 5542 3971 50  0000 L CNN
F 1 "1N" H 5542 3880 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5450 3925 50  0001 C CNN
F 3 "~" H 5450 3925 50  0001 C CNN
	1    5450 3925
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR098
U 1 1 5BCE3513
P 5450 4075
F 0 "#PWR098" H 5450 3825 50  0001 C CNN
F 1 "GND" H 5455 3902 50  0000 C CNN
F 2 "" H 5450 4075 50  0001 C CNN
F 3 "" H 5450 4075 50  0001 C CNN
	1    5450 4075
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3575 5450 3575
Wire Wire Line
	5450 3825 5450 3775
Wire Wire Line
	5450 4075 5450 4025
Wire Wire Line
	5400 3275 5500 3275
Wire Wire Line
	5400 3375 5500 3375
Wire Wire Line
	5400 3475 5500 3475
Wire Wire Line
	5450 3575 5500 3575
Connection ~ 5450 3575
$Comp
L power:GND #PWR084
U 1 1 5BCE353F
P 4250 3575
F 0 "#PWR084" H 4250 3325 50  0001 C CNN
F 1 "GND" H 4255 3402 50  0000 C CNN
F 2 "" H 4250 3575 50  0001 C CNN
F 3 "" H 4250 3575 50  0001 C CNN
	1    4250 3575
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3575 4300 3575
Wire Wire Line
	4250 2675 5150 2675
Wire Wire Line
	5150 2675 5150 2525
Wire Wire Line
	5150 2525 5450 2525
Wire Wire Line
	4250 2675 4250 3425
Connection ~ 4250 3425
Wire Wire Line
	4250 3425 4300 3425
Connection ~ 5450 2525
Wire Wire Line
	5450 2525 5450 2500
Wire Wire Line
	4050 3975 5200 3975
Wire Wire Line
	5200 3975 5200 3825
Wire Wire Line
	5200 3825 5450 3825
Connection ~ 5450 3825
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C00E6CA
P 7020 1170
AR Path="/5AD5ACBB/5C00E6CA" Ref="Q?"  Part="1" 
AR Path="/5C00E6CA" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C00E6CA" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C00E6CA" Ref="Q29"  Part="1" 
F 0 "Q29" H 7211 1216 50  0000 L CNN
F 1 "MMBT3904" H 6670 1020 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7220 1270 50  0001 C CNN
F 3 "" H 7020 1170 50  0001 C CNN
	1    7020 1170
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C00E6E7
P 7120 1820
AR Path="/5AD5ACBB/5C00E6E7" Ref="#PWR?"  Part="1" 
AR Path="/5C00E6E7" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C00E6E7" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C00E6E7" Ref="#PWR0100"  Part="1" 
F 0 "#PWR0100" H 7120 1570 50  0001 C CNN
F 1 "GND" H 7125 1647 50  0000 C CNN
F 2 "" H 7120 1820 50  0001 C CNN
F 3 "" H 7120 1820 50  0001 C CNN
	1    7120 1820
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C00E6F3
P 7120 870
AR Path="/5AD5ACBB/5C00E6F3" Ref="#PWR?"  Part="1" 
AR Path="/5C00E6F3" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C00E6F3" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C00E6F3" Ref="#PWR099"  Part="1" 
F 0 "#PWR099" H 7120 720 50  0001 C CNN
F 1 "+12V" H 7135 1043 50  0000 C CNN
F 2 "" H 7120 870 50  0001 C CNN
F 3 "" H 7120 870 50  0001 C CNN
	1    7120 870 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6770 1170 6820 1170
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C00E702
P 7320 1470
AR Path="/5AD5ACBB/5C00E702" Ref="J?"  Part="1" 
AR Path="/5C00E702" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C00E702" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C00E702" Ref="J38"  Part="1" 
F 0 "J38" H 7400 1512 50  0000 L CNN
F 1 "SROUT1" H 7400 1421 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 7320 1470 50  0001 C CNN
F 3 "~" H 7320 1470 50  0001 C CNN
	1    7320 1470
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C010A38
P 7120 1670
AR Path="/5AD5ACBB/5C010A38" Ref="R?"  Part="1" 
AR Path="/5C010A38" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C010A38" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C010A38" Ref="R52"  Part="1" 
F 0 "R52" V 6924 1670 50  0000 C CNN
F 1 "3K3" V 7015 1670 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7120 1670 50  0001 C CNN
F 3 "" H 7120 1670 50  0001 C CNN
	1    7120 1670
	1    0    0    1   
$EndComp
Wire Wire Line
	7120 870  7120 970 
Wire Wire Line
	7120 1770 7120 1820
Text Notes 7265 180  0    197  ~ 0
output buffer x16\n
Wire Wire Line
	7120 1370 7120 1470
Wire Wire Line
	7120 1470 7120 1570
Connection ~ 7120 1470
Wire Wire Line
	4100 3425 4250 3425
Text GLabel 4225 2150 0    60   Input ~ 0
SR1
Text GLabel 4100 3425 0    60   Input ~ 0
SR2
Wire Wire Line
	4835 1500 5095 1500
Text Label 5095 1500 0    60   ~ 0
CLOCK
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C06CA40
P 4635 1500
AR Path="/5AD5ACBB/5C06CA40" Ref="J?"  Part="1" 
AR Path="/5C06CA40" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C06CA40" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C06CA40" Ref="J13"  Part="1" 
F 0 "J13" H 4715 1542 50  0000 L CNN
F 1 "CLOCK IN" H 4715 1451 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4635 1500 50  0001 C CNN
F 3 "~" H 4635 1500 50  0001 C CNN
	1    4635 1500
	-1   0    0    1   
$EndComp
Text Label 5500 2000 0    60   ~ 0
SR1
Text Label 5500 2100 0    60   ~ 0
SR2
Text Label 5500 2200 0    60   ~ 0
SR3
Text Label 5500 2300 0    60   ~ 0
SR4
Text Label 5500 3275 0    60   ~ 0
SR5
Text Label 5500 3375 0    60   ~ 0
SR6
Text Label 5500 3475 0    60   ~ 0
SR7
Text Label 5500 3575 0    60   ~ 0
SR8
Text Label 6770 1170 1    60   ~ 0
SR1
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C079D54
P 8110 1170
AR Path="/5AD5ACBB/5C079D54" Ref="Q?"  Part="1" 
AR Path="/5C079D54" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C079D54" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C079D54" Ref="Q7"  Part="1" 
F 0 "Q7" H 8301 1216 50  0000 L CNN
F 1 "MMBT3904" H 7760 1020 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 8310 1270 50  0001 C CNN
F 3 "" H 8110 1170 50  0001 C CNN
	1    8110 1170
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C079D5A
P 8210 1820
AR Path="/5AD5ACBB/5C079D5A" Ref="#PWR?"  Part="1" 
AR Path="/5C079D5A" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C079D5A" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C079D5A" Ref="#PWR0148"  Part="1" 
F 0 "#PWR0148" H 8210 1570 50  0001 C CNN
F 1 "GND" H 8215 1647 50  0000 C CNN
F 2 "" H 8210 1820 50  0001 C CNN
F 3 "" H 8210 1820 50  0001 C CNN
	1    8210 1820
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C079D60
P 8210 870
AR Path="/5AD5ACBB/5C079D60" Ref="#PWR?"  Part="1" 
AR Path="/5C079D60" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C079D60" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C079D60" Ref="#PWR0149"  Part="1" 
F 0 "#PWR0149" H 8210 720 50  0001 C CNN
F 1 "+12V" H 8225 1043 50  0000 C CNN
F 2 "" H 8210 870 50  0001 C CNN
F 3 "" H 8210 870 50  0001 C CNN
	1    8210 870 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7860 1170 7910 1170
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C079D67
P 8410 1470
AR Path="/5AD5ACBB/5C079D67" Ref="J?"  Part="1" 
AR Path="/5C079D67" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C079D67" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C079D67" Ref="J24"  Part="1" 
F 0 "J24" H 8490 1512 50  0000 L CNN
F 1 "SROUT2" H 8490 1421 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 8410 1470 50  0001 C CNN
F 3 "~" H 8410 1470 50  0001 C CNN
	1    8410 1470
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C079D6D
P 8210 1670
AR Path="/5AD5ACBB/5C079D6D" Ref="R?"  Part="1" 
AR Path="/5C079D6D" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C079D6D" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C079D6D" Ref="R13"  Part="1" 
F 0 "R13" V 8014 1670 50  0000 C CNN
F 1 "3K3" V 8105 1670 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 8210 1670 50  0001 C CNN
F 3 "" H 8210 1670 50  0001 C CNN
	1    8210 1670
	1    0    0    1   
$EndComp
Wire Wire Line
	8210 870  8210 970 
Wire Wire Line
	8210 1770 8210 1820
Wire Wire Line
	8210 1370 8210 1470
Wire Wire Line
	8210 1470 8210 1570
Connection ~ 8210 1470
Text Label 7860 1170 1    60   ~ 0
SR2
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C07BD36
P 9195 1180
AR Path="/5AD5ACBB/5C07BD36" Ref="Q?"  Part="1" 
AR Path="/5C07BD36" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C07BD36" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C07BD36" Ref="Q14"  Part="1" 
F 0 "Q14" H 9386 1226 50  0000 L CNN
F 1 "MMBT3904" H 8845 1030 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 9395 1280 50  0001 C CNN
F 3 "" H 9195 1180 50  0001 C CNN
	1    9195 1180
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C07BD3C
P 9295 1830
AR Path="/5AD5ACBB/5C07BD3C" Ref="#PWR?"  Part="1" 
AR Path="/5C07BD3C" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C07BD3C" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C07BD3C" Ref="#PWR0150"  Part="1" 
F 0 "#PWR0150" H 9295 1580 50  0001 C CNN
F 1 "GND" H 9300 1657 50  0000 C CNN
F 2 "" H 9295 1830 50  0001 C CNN
F 3 "" H 9295 1830 50  0001 C CNN
	1    9295 1830
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C07BD42
P 9295 880
AR Path="/5AD5ACBB/5C07BD42" Ref="#PWR?"  Part="1" 
AR Path="/5C07BD42" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C07BD42" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C07BD42" Ref="#PWR0151"  Part="1" 
F 0 "#PWR0151" H 9295 730 50  0001 C CNN
F 1 "+12V" H 9310 1053 50  0000 C CNN
F 2 "" H 9295 880 50  0001 C CNN
F 3 "" H 9295 880 50  0001 C CNN
	1    9295 880 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8945 1180 8995 1180
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C07BD49
P 9495 1480
AR Path="/5AD5ACBB/5C07BD49" Ref="J?"  Part="1" 
AR Path="/5C07BD49" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C07BD49" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C07BD49" Ref="J28"  Part="1" 
F 0 "J28" H 9575 1522 50  0000 L CNN
F 1 "SROUT3" H 9575 1431 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 9495 1480 50  0001 C CNN
F 3 "~" H 9495 1480 50  0001 C CNN
	1    9495 1480
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C07BD4F
P 9295 1680
AR Path="/5AD5ACBB/5C07BD4F" Ref="R?"  Part="1" 
AR Path="/5C07BD4F" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C07BD4F" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C07BD4F" Ref="R19"  Part="1" 
F 0 "R19" V 9099 1680 50  0000 C CNN
F 1 "3K3" V 9190 1680 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 9295 1680 50  0001 C CNN
F 3 "" H 9295 1680 50  0001 C CNN
	1    9295 1680
	1    0    0    1   
$EndComp
Wire Wire Line
	9295 880  9295 980 
Wire Wire Line
	9295 1780 9295 1830
Wire Wire Line
	9295 1380 9295 1480
Wire Wire Line
	9295 1480 9295 1580
Connection ~ 9295 1480
Text Label 8945 1180 1    60   ~ 0
SR3
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C07BD5B
P 10285 1180
AR Path="/5AD5ACBB/5C07BD5B" Ref="Q?"  Part="1" 
AR Path="/5C07BD5B" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C07BD5B" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C07BD5B" Ref="Q40"  Part="1" 
F 0 "Q40" H 10476 1226 50  0000 L CNN
F 1 "MMBT3904" H 9935 1030 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 10485 1280 50  0001 C CNN
F 3 "" H 10285 1180 50  0001 C CNN
	1    10285 1180
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C07BD61
P 10385 1830
AR Path="/5AD5ACBB/5C07BD61" Ref="#PWR?"  Part="1" 
AR Path="/5C07BD61" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C07BD61" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C07BD61" Ref="#PWR0152"  Part="1" 
F 0 "#PWR0152" H 10385 1580 50  0001 C CNN
F 1 "GND" H 10390 1657 50  0000 C CNN
F 2 "" H 10385 1830 50  0001 C CNN
F 3 "" H 10385 1830 50  0001 C CNN
	1    10385 1830
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C07BD67
P 10385 880
AR Path="/5AD5ACBB/5C07BD67" Ref="#PWR?"  Part="1" 
AR Path="/5C07BD67" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C07BD67" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C07BD67" Ref="#PWR0153"  Part="1" 
F 0 "#PWR0153" H 10385 730 50  0001 C CNN
F 1 "+12V" H 10400 1053 50  0000 C CNN
F 2 "" H 10385 880 50  0001 C CNN
F 3 "" H 10385 880 50  0001 C CNN
	1    10385 880 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10035 1180 10085 1180
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C07BD6E
P 10585 1480
AR Path="/5AD5ACBB/5C07BD6E" Ref="J?"  Part="1" 
AR Path="/5C07BD6E" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C07BD6E" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C07BD6E" Ref="J32"  Part="1" 
F 0 "J32" H 10665 1522 50  0000 L CNN
F 1 "SROUT4" H 10665 1431 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 10585 1480 50  0001 C CNN
F 3 "~" H 10585 1480 50  0001 C CNN
	1    10585 1480
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C07BD74
P 10385 1680
AR Path="/5AD5ACBB/5C07BD74" Ref="R?"  Part="1" 
AR Path="/5C07BD74" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C07BD74" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C07BD74" Ref="R23"  Part="1" 
F 0 "R23" V 10189 1680 50  0000 C CNN
F 1 "3K3" V 10280 1680 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 10385 1680 50  0001 C CNN
F 3 "" H 10385 1680 50  0001 C CNN
	1    10385 1680
	1    0    0    1   
$EndComp
Wire Wire Line
	10385 880  10385 980 
Wire Wire Line
	10385 1780 10385 1830
Wire Wire Line
	10385 1380 10385 1480
Wire Wire Line
	10385 1480 10385 1580
Connection ~ 10385 1480
Text Label 10035 1180 1    60   ~ 0
SR4
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C080698
P 7020 2635
AR Path="/5AD5ACBB/5C080698" Ref="Q?"  Part="1" 
AR Path="/5C080698" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C080698" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C080698" Ref="Q1"  Part="1" 
F 0 "Q1" H 7211 2681 50  0000 L CNN
F 1 "MMBT3904" H 6670 2485 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7220 2735 50  0001 C CNN
F 3 "" H 7020 2635 50  0001 C CNN
	1    7020 2635
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C08069E
P 7120 3285
AR Path="/5AD5ACBB/5C08069E" Ref="#PWR?"  Part="1" 
AR Path="/5C08069E" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C08069E" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C08069E" Ref="#PWR0154"  Part="1" 
F 0 "#PWR0154" H 7120 3035 50  0001 C CNN
F 1 "GND" H 7125 3112 50  0000 C CNN
F 2 "" H 7120 3285 50  0001 C CNN
F 3 "" H 7120 3285 50  0001 C CNN
	1    7120 3285
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C0806A4
P 7120 2335
AR Path="/5AD5ACBB/5C0806A4" Ref="#PWR?"  Part="1" 
AR Path="/5C0806A4" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C0806A4" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C0806A4" Ref="#PWR0155"  Part="1" 
F 0 "#PWR0155" H 7120 2185 50  0001 C CNN
F 1 "+12V" H 7135 2508 50  0000 C CNN
F 2 "" H 7120 2335 50  0001 C CNN
F 3 "" H 7120 2335 50  0001 C CNN
	1    7120 2335
	1    0    0    -1  
$EndComp
Wire Wire Line
	6770 2635 6820 2635
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C0806AB
P 7320 2935
AR Path="/5AD5ACBB/5C0806AB" Ref="J?"  Part="1" 
AR Path="/5C0806AB" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C0806AB" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C0806AB" Ref="J14"  Part="1" 
F 0 "J14" H 7400 2977 50  0000 L CNN
F 1 "SROUT5" H 7400 2886 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 7320 2935 50  0001 C CNN
F 3 "~" H 7320 2935 50  0001 C CNN
	1    7320 2935
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C0806B1
P 7120 3135
AR Path="/5AD5ACBB/5C0806B1" Ref="R?"  Part="1" 
AR Path="/5C0806B1" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C0806B1" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C0806B1" Ref="R10"  Part="1" 
F 0 "R10" V 6924 3135 50  0000 C CNN
F 1 "3K3" V 7015 3135 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7120 3135 50  0001 C CNN
F 3 "" H 7120 3135 50  0001 C CNN
	1    7120 3135
	1    0    0    1   
$EndComp
Wire Wire Line
	7120 2335 7120 2435
Wire Wire Line
	7120 3235 7120 3285
Wire Wire Line
	7120 2835 7120 2935
Wire Wire Line
	7120 2935 7120 3035
Connection ~ 7120 2935
Text Label 6770 2635 1    60   ~ 0
SR5
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0806BD
P 8110 2635
AR Path="/5AD5ACBB/5C0806BD" Ref="Q?"  Part="1" 
AR Path="/5C0806BD" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C0806BD" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C0806BD" Ref="Q9"  Part="1" 
F 0 "Q9" H 8301 2681 50  0000 L CNN
F 1 "MMBT3904" H 7760 2485 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 8310 2735 50  0001 C CNN
F 3 "" H 8110 2635 50  0001 C CNN
	1    8110 2635
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C0806C3
P 8210 3285
AR Path="/5AD5ACBB/5C0806C3" Ref="#PWR?"  Part="1" 
AR Path="/5C0806C3" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C0806C3" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C0806C3" Ref="#PWR0156"  Part="1" 
F 0 "#PWR0156" H 8210 3035 50  0001 C CNN
F 1 "GND" H 8215 3112 50  0000 C CNN
F 2 "" H 8210 3285 50  0001 C CNN
F 3 "" H 8210 3285 50  0001 C CNN
	1    8210 3285
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C0806C9
P 8210 2335
AR Path="/5AD5ACBB/5C0806C9" Ref="#PWR?"  Part="1" 
AR Path="/5C0806C9" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C0806C9" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C0806C9" Ref="#PWR0157"  Part="1" 
F 0 "#PWR0157" H 8210 2185 50  0001 C CNN
F 1 "+12V" H 8225 2508 50  0000 C CNN
F 2 "" H 8210 2335 50  0001 C CNN
F 3 "" H 8210 2335 50  0001 C CNN
	1    8210 2335
	1    0    0    -1  
$EndComp
Wire Wire Line
	7860 2635 7910 2635
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C0806D0
P 8410 2935
AR Path="/5AD5ACBB/5C0806D0" Ref="J?"  Part="1" 
AR Path="/5C0806D0" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C0806D0" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C0806D0" Ref="J25"  Part="1" 
F 0 "J25" H 8490 2977 50  0000 L CNN
F 1 "SROUT6" H 8490 2886 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 8410 2935 50  0001 C CNN
F 3 "~" H 8410 2935 50  0001 C CNN
	1    8410 2935
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C0806D6
P 8210 3135
AR Path="/5AD5ACBB/5C0806D6" Ref="R?"  Part="1" 
AR Path="/5C0806D6" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C0806D6" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C0806D6" Ref="R16"  Part="1" 
F 0 "R16" V 8014 3135 50  0000 C CNN
F 1 "3K3" V 8105 3135 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 8210 3135 50  0001 C CNN
F 3 "" H 8210 3135 50  0001 C CNN
	1    8210 3135
	1    0    0    1   
$EndComp
Wire Wire Line
	8210 2335 8210 2435
Wire Wire Line
	8210 3235 8210 3285
Wire Wire Line
	8210 2835 8210 2935
Wire Wire Line
	8210 2935 8210 3035
Connection ~ 8210 2935
Text Label 7860 2635 1    60   ~ 0
SR6
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0806E2
P 9195 2645
AR Path="/5AD5ACBB/5C0806E2" Ref="Q?"  Part="1" 
AR Path="/5C0806E2" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C0806E2" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C0806E2" Ref="Q16"  Part="1" 
F 0 "Q16" H 9386 2691 50  0000 L CNN
F 1 "MMBT3904" H 8845 2495 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 9395 2745 50  0001 C CNN
F 3 "" H 9195 2645 50  0001 C CNN
	1    9195 2645
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C0806E8
P 9295 3295
AR Path="/5AD5ACBB/5C0806E8" Ref="#PWR?"  Part="1" 
AR Path="/5C0806E8" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C0806E8" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C0806E8" Ref="#PWR0158"  Part="1" 
F 0 "#PWR0158" H 9295 3045 50  0001 C CNN
F 1 "GND" H 9300 3122 50  0000 C CNN
F 2 "" H 9295 3295 50  0001 C CNN
F 3 "" H 9295 3295 50  0001 C CNN
	1    9295 3295
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C0806EE
P 9295 2345
AR Path="/5AD5ACBB/5C0806EE" Ref="#PWR?"  Part="1" 
AR Path="/5C0806EE" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C0806EE" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C0806EE" Ref="#PWR0159"  Part="1" 
F 0 "#PWR0159" H 9295 2195 50  0001 C CNN
F 1 "+12V" H 9310 2518 50  0000 C CNN
F 2 "" H 9295 2345 50  0001 C CNN
F 3 "" H 9295 2345 50  0001 C CNN
	1    9295 2345
	1    0    0    -1  
$EndComp
Wire Wire Line
	8945 2645 8995 2645
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C0806F5
P 9495 2945
AR Path="/5AD5ACBB/5C0806F5" Ref="J?"  Part="1" 
AR Path="/5C0806F5" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C0806F5" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C0806F5" Ref="J29"  Part="1" 
F 0 "J29" H 9575 2987 50  0000 L CNN
F 1 "SROUT7" H 9575 2896 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 9495 2945 50  0001 C CNN
F 3 "~" H 9495 2945 50  0001 C CNN
	1    9495 2945
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C0806FB
P 9295 3145
AR Path="/5AD5ACBB/5C0806FB" Ref="R?"  Part="1" 
AR Path="/5C0806FB" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C0806FB" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C0806FB" Ref="R20"  Part="1" 
F 0 "R20" V 9099 3145 50  0000 C CNN
F 1 "3K3" V 9190 3145 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 9295 3145 50  0001 C CNN
F 3 "" H 9295 3145 50  0001 C CNN
	1    9295 3145
	1    0    0    1   
$EndComp
Wire Wire Line
	9295 2345 9295 2445
Wire Wire Line
	9295 3245 9295 3295
Wire Wire Line
	9295 2845 9295 2945
Wire Wire Line
	9295 2945 9295 3045
Connection ~ 9295 2945
Text Label 8945 2645 1    60   ~ 0
SR7
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C080707
P 10285 2645
AR Path="/5AD5ACBB/5C080707" Ref="Q?"  Part="1" 
AR Path="/5C080707" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C080707" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C080707" Ref="Q41"  Part="1" 
F 0 "Q41" H 10476 2691 50  0000 L CNN
F 1 "MMBT3904" H 9935 2495 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 10485 2745 50  0001 C CNN
F 3 "" H 10285 2645 50  0001 C CNN
	1    10285 2645
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C08070D
P 10385 3295
AR Path="/5AD5ACBB/5C08070D" Ref="#PWR?"  Part="1" 
AR Path="/5C08070D" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C08070D" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C08070D" Ref="#PWR0160"  Part="1" 
F 0 "#PWR0160" H 10385 3045 50  0001 C CNN
F 1 "GND" H 10390 3122 50  0000 C CNN
F 2 "" H 10385 3295 50  0001 C CNN
F 3 "" H 10385 3295 50  0001 C CNN
	1    10385 3295
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C080713
P 10385 2345
AR Path="/5AD5ACBB/5C080713" Ref="#PWR?"  Part="1" 
AR Path="/5C080713" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C080713" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C080713" Ref="#PWR0161"  Part="1" 
F 0 "#PWR0161" H 10385 2195 50  0001 C CNN
F 1 "+12V" H 10400 2518 50  0000 C CNN
F 2 "" H 10385 2345 50  0001 C CNN
F 3 "" H 10385 2345 50  0001 C CNN
	1    10385 2345
	1    0    0    -1  
$EndComp
Wire Wire Line
	10035 2645 10085 2645
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C08071A
P 10585 2945
AR Path="/5AD5ACBB/5C08071A" Ref="J?"  Part="1" 
AR Path="/5C08071A" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C08071A" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C08071A" Ref="J33"  Part="1" 
F 0 "J33" H 10665 2987 50  0000 L CNN
F 1 "SROUT8" H 10665 2896 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 10585 2945 50  0001 C CNN
F 3 "~" H 10585 2945 50  0001 C CNN
	1    10585 2945
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C080720
P 10385 3145
AR Path="/5AD5ACBB/5C080720" Ref="R?"  Part="1" 
AR Path="/5C080720" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C080720" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C080720" Ref="R24"  Part="1" 
F 0 "R24" V 10189 3145 50  0000 C CNN
F 1 "3K3" V 10280 3145 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 10385 3145 50  0001 C CNN
F 3 "" H 10385 3145 50  0001 C CNN
	1    10385 3145
	1    0    0    1   
$EndComp
Wire Wire Line
	10385 2345 10385 2445
Wire Wire Line
	10385 3245 10385 3295
Wire Wire Line
	10385 2845 10385 2945
Wire Wire Line
	10385 2945 10385 3045
Connection ~ 10385 2945
Text Label 10035 2645 1    60   ~ 0
SR8
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C0849AE
P 7030 4160
AR Path="/5AD5ACBB/5C0849AE" Ref="Q?"  Part="1" 
AR Path="/5C0849AE" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C0849AE" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C0849AE" Ref="Q3"  Part="1" 
F 0 "Q3" H 7221 4206 50  0000 L CNN
F 1 "MMBT3904" H 6680 4010 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7230 4260 50  0001 C CNN
F 3 "" H 7030 4160 50  0001 C CNN
	1    7030 4160
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C0849B4
P 7130 4810
AR Path="/5AD5ACBB/5C0849B4" Ref="#PWR?"  Part="1" 
AR Path="/5C0849B4" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C0849B4" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C0849B4" Ref="#PWR0162"  Part="1" 
F 0 "#PWR0162" H 7130 4560 50  0001 C CNN
F 1 "GND" H 7135 4637 50  0000 C CNN
F 2 "" H 7130 4810 50  0001 C CNN
F 3 "" H 7130 4810 50  0001 C CNN
	1    7130 4810
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C0849BA
P 7130 3860
AR Path="/5AD5ACBB/5C0849BA" Ref="#PWR?"  Part="1" 
AR Path="/5C0849BA" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C0849BA" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C0849BA" Ref="#PWR0163"  Part="1" 
F 0 "#PWR0163" H 7130 3710 50  0001 C CNN
F 1 "+12V" H 7145 4033 50  0000 C CNN
F 2 "" H 7130 3860 50  0001 C CNN
F 3 "" H 7130 3860 50  0001 C CNN
	1    7130 3860
	1    0    0    -1  
$EndComp
Wire Wire Line
	6780 4160 6830 4160
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C0849C1
P 7330 4460
AR Path="/5AD5ACBB/5C0849C1" Ref="J?"  Part="1" 
AR Path="/5C0849C1" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C0849C1" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C0849C1" Ref="J22"  Part="1" 
F 0 "J22" H 7410 4502 50  0000 L CNN
F 1 "SROUT9" H 7410 4411 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 7330 4460 50  0001 C CNN
F 3 "~" H 7330 4460 50  0001 C CNN
	1    7330 4460
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C0849C7
P 7130 4660
AR Path="/5AD5ACBB/5C0849C7" Ref="R?"  Part="1" 
AR Path="/5C0849C7" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C0849C7" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C0849C7" Ref="R11"  Part="1" 
F 0 "R11" V 6934 4660 50  0000 C CNN
F 1 "3K3" V 7025 4660 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7130 4660 50  0001 C CNN
F 3 "" H 7130 4660 50  0001 C CNN
	1    7130 4660
	1    0    0    1   
$EndComp
Wire Wire Line
	7130 3860 7130 3960
Wire Wire Line
	7130 4760 7130 4810
Wire Wire Line
	7130 4360 7130 4460
Wire Wire Line
	7130 4460 7130 4560
Connection ~ 7130 4460
Text Label 6780 4160 1    60   ~ 0
SR9
Text Label 4050 3975 0    60   ~ 0
SR9
$EndSCHEMATC
