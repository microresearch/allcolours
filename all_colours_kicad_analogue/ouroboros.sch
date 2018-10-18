EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 6
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
L allcolours_analogue-rescue:C-device C?
U 1 1 5BAC4611
P 2900 4500
F 0 "C?" H 2925 4600 50  0000 L CNN
F 1 "1N" H 2925 4400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2938 4350 50  0001 C CNN
F 3 "" H 2900 4500 50  0000 C CNN
	1    2900 4500
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BAC462C
P 3450 5050
F 0 "#PWR?" H 3450 4800 50  0001 C CNN
F 1 "GND" H 3450 4900 50  0000 C CNN
F 2 "" H 3450 5050 50  0000 C CNN
F 3 "" H 3450 5050 50  0000 C CNN
	1    3450 5050
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BAC4639
P 3450 4050
F 0 "R?" V 3530 4050 50  0000 C CNN
F 1 "33K" V 3450 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3380 4050 50  0001 C CNN
F 3 "" H 3450 4050 50  0000 C CNN
	1    3450 4050
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BAC4640
P 3450 4400
F 0 "D?" H 3450 4300 50  0000 C CNN
F 1 "1n4148" H 3450 4550 50  0000 C CNN
F 2 "" H 3450 4400 50  0001 C CNN
F 3 "" H 3450 4400 50  0001 C CNN
	1    3450 4400
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BAC465C
P 3450 3850
F 0 "#PWR?" H 3450 3700 50  0001 C CNN
F 1 "+12V" H 3450 3990 50  0000 C CNN
F 2 "" H 3450 3850 50  0000 C CNN
F 3 "" H 3450 3850 50  0000 C CNN
	1    3450 3850
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BB3D775
P 3350 4800
F 0 "Q?" H 3541 4846 50  0000 L CNN
F 1 "Q_NPN_BEC" H 3541 4755 50  0000 L CNN
F 2 "" H 3550 4900 50  0001 C CNN
F 3 "" H 3350 4800 50  0001 C CNN
	1    3350 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3850 3450 3900
Wire Wire Line
	3450 4550 3450 4600
Wire Wire Line
	3450 4200 3450 4250
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BB5CF21
P 3800 4300
F 0 "C?" H 3825 4400 50  0000 L CNN
F 1 "1N" H 3825 4200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3838 4150 50  0001 C CNN
F 3 "" H 3800 4300 50  0000 C CNN
	1    3800 4300
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BB5CF27
P 4350 4850
F 0 "#PWR?" H 4350 4600 50  0001 C CNN
F 1 "GND" H 4350 4700 50  0000 C CNN
F 2 "" H 4350 4850 50  0000 C CNN
F 3 "" H 4350 4850 50  0000 C CNN
	1    4350 4850
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BB5CF2D
P 4350 3850
F 0 "R?" V 4430 3850 50  0000 C CNN
F 1 "33K" V 4350 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4280 3850 50  0001 C CNN
F 3 "" H 4350 3850 50  0000 C CNN
	1    4350 3850
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BB5CF33
P 4350 4200
F 0 "D?" H 4350 4100 50  0000 C CNN
F 1 "1n4148" H 4350 4350 50  0000 C CNN
F 2 "" H 4350 4200 50  0001 C CNN
F 3 "" H 4350 4200 50  0001 C CNN
	1    4350 4200
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BB5CF39
P 4350 3650
F 0 "#PWR?" H 4350 3500 50  0001 C CNN
F 1 "+12V" H 4350 3790 50  0000 C CNN
F 2 "" H 4350 3650 50  0000 C CNN
F 3 "" H 4350 3650 50  0000 C CNN
	1    4350 3650
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BB5CF3F
P 4250 4600
F 0 "Q?" H 4441 4646 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4441 4555 50  0000 L CNN
F 2 "" H 4450 4700 50  0001 C CNN
F 3 "" H 4250 4600 50  0001 C CNN
	1    4250 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3650 4350 3700
Wire Wire Line
	4350 4350 4350 4400
Wire Wire Line
	4350 4000 4350 4050
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BB5D0F1
P 4650 4000
F 0 "C?" H 4675 4100 50  0000 L CNN
F 1 "1N" H 4675 3900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4688 3850 50  0001 C CNN
F 3 "" H 4650 4000 50  0000 C CNN
	1    4650 4000
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BB5D0F8
P 5150 4600
F 0 "#PWR?" H 5150 4350 50  0001 C CNN
F 1 "GND" H 5150 4450 50  0000 C CNN
F 2 "" H 5150 4600 50  0000 C CNN
F 3 "" H 5150 4600 50  0000 C CNN
	1    5150 4600
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BB5D0FE
P 5150 3600
F 0 "R?" V 5230 3600 50  0000 C CNN
F 1 "33K" V 5150 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5080 3600 50  0001 C CNN
F 3 "" H 5150 3600 50  0000 C CNN
	1    5150 3600
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BB5D105
P 5150 3950
F 0 "D?" H 5150 3850 50  0000 C CNN
F 1 "1n4148" H 5150 4100 50  0000 C CNN
F 2 "" H 5150 3950 50  0001 C CNN
F 3 "" H 5150 3950 50  0001 C CNN
	1    5150 3950
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BB5D10C
P 5150 3400
F 0 "#PWR?" H 5150 3250 50  0001 C CNN
F 1 "+12V" H 5150 3540 50  0000 C CNN
F 2 "" H 5150 3400 50  0000 C CNN
F 3 "" H 5150 3400 50  0000 C CNN
	1    5150 3400
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BB5D112
P 5050 4350
F 0 "Q?" H 5241 4396 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5241 4305 50  0000 L CNN
F 2 "" H 5250 4450 50  0001 C CNN
F 3 "" H 5050 4350 50  0001 C CNN
	1    5050 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3400 5150 3450
Wire Wire Line
	5150 4100 5150 4150
Wire Wire Line
	5150 3750 5150 3800
Wire Wire Line
	4800 4350 4850 4350
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BB5D2A3
P 6950 3350
F 0 "C?" H 6975 3450 50  0000 L CNN
F 1 "1N" H 6975 3250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6988 3200 50  0001 C CNN
F 3 "" H 6950 3350 50  0000 C CNN
	1    6950 3350
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BB5D2AA
P 7550 3950
F 0 "#PWR?" H 7550 3700 50  0001 C CNN
F 1 "GND" H 7550 3800 50  0000 C CNN
F 2 "" H 7550 3950 50  0000 C CNN
F 3 "" H 7550 3950 50  0000 C CNN
	1    7550 3950
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BB5D2B0
P 7550 2950
F 0 "R?" V 7630 2950 50  0000 C CNN
F 1 "33K" V 7550 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7480 2950 50  0001 C CNN
F 3 "" H 7550 2950 50  0000 C CNN
	1    7550 2950
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BB5D2B7
P 7550 3300
F 0 "D?" H 7550 3200 50  0000 C CNN
F 1 "1n4148" H 7550 3450 50  0000 C CNN
F 2 "" H 7550 3300 50  0001 C CNN
F 3 "" H 7550 3300 50  0001 C CNN
	1    7550 3300
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BB5D2BE
P 7550 2750
F 0 "#PWR?" H 7550 2600 50  0001 C CNN
F 1 "+12V" H 7550 2890 50  0000 C CNN
F 2 "" H 7550 2750 50  0000 C CNN
F 3 "" H 7550 2750 50  0000 C CNN
	1    7550 2750
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BB5D2C4
P 7450 3700
F 0 "Q?" H 7641 3746 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7641 3655 50  0000 L CNN
F 2 "" H 7650 3800 50  0001 C CNN
F 3 "" H 7450 3700 50  0001 C CNN
	1    7450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 2750 7550 2800
Wire Wire Line
	7550 3450 7550 3500
Wire Wire Line
	7550 3100 7550 3150
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BB5D4C7
P 6200 3700
F 0 "C?" H 6225 3800 50  0000 L CNN
F 1 "1N" H 6225 3600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6238 3550 50  0001 C CNN
F 3 "" H 6200 3700 50  0000 C CNN
	1    6200 3700
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BB5D4CE
P 6700 4150
F 0 "#PWR?" H 6700 3900 50  0001 C CNN
F 1 "GND" H 6700 4000 50  0000 C CNN
F 2 "" H 6700 4150 50  0000 C CNN
F 3 "" H 6700 4150 50  0000 C CNN
	1    6700 4150
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BB5D4D4
P 6700 3150
F 0 "R?" V 6780 3150 50  0000 C CNN
F 1 "33K" V 6700 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6630 3150 50  0001 C CNN
F 3 "" H 6700 3150 50  0000 C CNN
	1    6700 3150
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BB5D4DB
P 6700 3500
F 0 "D?" H 6700 3400 50  0000 C CNN
F 1 "1n4148" H 6700 3650 50  0000 C CNN
F 2 "" H 6700 3500 50  0001 C CNN
F 3 "" H 6700 3500 50  0001 C CNN
	1    6700 3500
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BB5D4E2
P 6700 2950
F 0 "#PWR?" H 6700 2800 50  0001 C CNN
F 1 "+12V" H 6700 3090 50  0000 C CNN
F 2 "" H 6700 2950 50  0000 C CNN
F 3 "" H 6700 2950 50  0000 C CNN
	1    6700 2950
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BB5D4E8
P 6600 3900
F 0 "Q?" H 6791 3946 50  0000 L CNN
F 1 "Q_NPN_BEC" H 6791 3855 50  0000 L CNN
F 2 "" H 6800 4000 50  0001 C CNN
F 3 "" H 6600 3900 50  0001 C CNN
	1    6600 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2950 6700 3000
Wire Wire Line
	6700 3650 6700 3700
Wire Wire Line
	6700 3300 6700 3350
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BB5D7CF
P 5500 3850
F 0 "C?" H 5525 3950 50  0000 L CNN
F 1 "1N" H 5525 3750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5538 3700 50  0001 C CNN
F 3 "" H 5500 3850 50  0000 C CNN
	1    5500 3850
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BB5D7D6
P 5900 4350
F 0 "#PWR?" H 5900 4100 50  0001 C CNN
F 1 "GND" H 5900 4200 50  0000 C CNN
F 2 "" H 5900 4350 50  0000 C CNN
F 3 "" H 5900 4350 50  0000 C CNN
	1    5900 4350
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BB5D7DC
P 5900 3350
F 0 "R?" V 5980 3350 50  0000 C CNN
F 1 "33K" V 5900 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5830 3350 50  0001 C CNN
F 3 "" H 5900 3350 50  0000 C CNN
	1    5900 3350
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BB5D7E3
P 5900 3700
F 0 "D?" H 5900 3600 50  0000 C CNN
F 1 "1n4148" H 5900 3850 50  0000 C CNN
F 2 "" H 5900 3700 50  0001 C CNN
F 3 "" H 5900 3700 50  0001 C CNN
	1    5900 3700
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BB5D7EA
P 5900 3150
F 0 "#PWR?" H 5900 3000 50  0001 C CNN
F 1 "+12V" H 5900 3290 50  0000 C CNN
F 2 "" H 5900 3150 50  0000 C CNN
F 3 "" H 5900 3150 50  0000 C CNN
	1    5900 3150
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BB5D7F0
P 5800 4100
F 0 "Q?" H 5991 4146 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5991 4055 50  0000 L CNN
F 2 "" H 6000 4200 50  0001 C CNN
F 3 "" H 5800 4100 50  0001 C CNN
	1    5800 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3150 5900 3200
Wire Wire Line
	5900 3850 5900 3900
Wire Wire Line
	5900 3500 5900 3550
Wire Wire Line
	5550 4100 5600 4100
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BB5DC4F
P 2050 5050
F 0 "C?" H 2075 5150 50  0000 L CNN
F 1 "1N" H 2075 4950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2088 4900 50  0001 C CNN
F 3 "" H 2050 5050 50  0000 C CNN
	1    2050 5050
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BB5DC56
P 2550 5300
F 0 "#PWR?" H 2550 5050 50  0001 C CNN
F 1 "GND" H 2550 5150 50  0000 C CNN
F 2 "" H 2550 5300 50  0000 C CNN
F 3 "" H 2550 5300 50  0000 C CNN
	1    2550 5300
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BB5DC5C
P 2550 4300
F 0 "R?" V 2630 4300 50  0000 C CNN
F 1 "33K" V 2550 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2480 4300 50  0001 C CNN
F 3 "" H 2550 4300 50  0000 C CNN
	1    2550 4300
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BB5DC63
P 2550 4650
F 0 "D?" H 2550 4550 50  0000 C CNN
F 1 "1n4148" H 2550 4800 50  0000 C CNN
F 2 "" H 2550 4650 50  0001 C CNN
F 3 "" H 2550 4650 50  0001 C CNN
	1    2550 4650
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BB5DC6A
P 2550 4100
F 0 "#PWR?" H 2550 3950 50  0001 C CNN
F 1 "+12V" H 2550 4240 50  0000 C CNN
F 2 "" H 2550 4100 50  0000 C CNN
F 3 "" H 2550 4100 50  0000 C CNN
	1    2550 4100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BB5DC70
P 2450 5050
F 0 "Q?" H 2641 5096 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2641 5005 50  0000 L CNN
F 2 "" H 2650 5150 50  0001 C CNN
F 3 "" H 2450 5050 50  0001 C CNN
	1    2450 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 4100 2550 4150
Wire Wire Line
	2550 4800 2550 4850
Wire Wire Line
	2550 4450 2550 4500
Wire Wire Line
	2200 5050 2250 5050
Wire Wire Line
	8450 5800 1900 5800
Wire Wire Line
	1900 5800 1900 5050
Text Notes 4850 2300 0    60   ~ 0
mmbt or 2n2222\n
Wire Wire Line
	2550 4500 2750 4500
Connection ~ 2550 4500
Wire Wire Line
	3050 4500 3050 4800
Wire Wire Line
	3050 4800 3150 4800
Wire Wire Line
	3450 4300 3650 4300
Wire Wire Line
	3950 4300 3950 4600
Wire Wire Line
	3950 4600 4050 4600
Wire Wire Line
	4350 4000 4500 4000
Connection ~ 4350 4000
Wire Wire Line
	4800 4000 4800 4350
Wire Wire Line
	5150 3850 5350 3850
Wire Wire Line
	5650 3850 5650 4050
Wire Wire Line
	5650 4050 5550 4050
Wire Wire Line
	5550 4050 5550 4100
Wire Wire Line
	5900 3600 6050 3600
Wire Wire Line
	6050 3600 6050 3700
Wire Wire Line
	6350 3700 6350 3900
Wire Wire Line
	6350 3900 6400 3900
Wire Wire Line
	7550 3150 8450 3150
Wire Wire Line
	8450 3150 8450 5800
Connection ~ 7550 3150
Wire Wire Line
	6700 3350 6800 3350
Connection ~ 6700 3350
Wire Wire Line
	7100 3350 7100 3700
Wire Wire Line
	7100 3700 7250 3700
$EndSCHEMATC
