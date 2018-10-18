EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
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
U 1 1 5BD18BA3
P 2050 2200
AR Path="/5BD18BA3" Ref="C?"  Part="1" 
AR Path="/5BD09509/5BD18BA3" Ref="C?"  Part="1" 
F 0 "C?" H 2075 2300 50  0000 L CNN
F 1 "1N" H 2075 2100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2088 2050 50  0001 C CNN
F 3 "" H 2050 2200 50  0000 C CNN
	1    2050 2200
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BD18BAA
P 2900 1950
AR Path="/5BD18BAA" Ref="C?"  Part="1" 
AR Path="/5BD09509/5BD18BAA" Ref="C?"  Part="1" 
F 0 "C?" H 2925 2050 50  0000 L CNN
F 1 "100N" H 2750 1850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2938 1800 50  0001 C CNN
F 3 "" H 2900 1950 50  0000 C CNN
	1    2900 1950
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C?
U 1 1 5BD18BB1
P 3100 1950
AR Path="/5BD18BB1" Ref="C?"  Part="1" 
AR Path="/5BD09509/5BD18BB1" Ref="C?"  Part="1" 
F 0 "C?" H 3125 2050 50  0000 L CNN
F 1 "100N" H 2850 1850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3138 1800 50  0001 C CNN
F 3 "" H 3100 1950 50  0000 C CNN
	1    3100 1950
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD18BB8
P 3000 2100
AR Path="/5BD18BB8" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD18BB8" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3000 1850 50  0001 C CNN
F 1 "GND" H 3000 1950 50  0000 C CNN
F 2 "" H 3000 2100 50  0000 C CNN
F 3 "" H 3000 2100 50  0000 C CNN
	1    3000 2100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD18BBE
P 2600 2450
AR Path="/5BD18BBE" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD18BBE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2600 2200 50  0001 C CNN
F 1 "GND" H 2600 2300 50  0000 C CNN
F 2 "" H 2600 2450 50  0000 C CNN
F 3 "" H 2600 2450 50  0000 C CNN
	1    2600 2450
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BD18BC4
P 2250 2050
AR Path="/5BD18BC4" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD18BC4" Ref="R?"  Part="1" 
F 0 "R?" V 2330 2050 50  0000 C CNN
F 1 "1M" V 2250 2050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2180 2050 50  0001 C CNN
F 3 "" H 2250 2050 50  0000 C CNN
	1    2250 2050
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R?
U 1 1 5BD18BCB
P 2600 1400
AR Path="/5BD18BCB" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD18BCB" Ref="R?"  Part="1" 
F 0 "R?" V 2680 1400 50  0000 C CNN
F 1 "33K" V 2600 1400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2530 1400 50  0001 C CNN
F 3 "" H 2600 1400 50  0000 C CNN
	1    2600 1400
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D?
U 1 1 5BD18BD2
P 2600 1800
AR Path="/5BD18BD2" Ref="D?"  Part="1" 
AR Path="/5BD09509/5BD18BD2" Ref="D?"  Part="1" 
F 0 "D?" H 2600 1700 50  0000 C CNN
F 1 "1n4148" H 2600 1950 50  0000 C CNN
F 2 "" H 2600 1800 50  0001 C CNN
F 3 "" H 2600 1800 50  0001 C CNN
	1    2600 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2600 1550 2600 1600
Wire Wire Line
	2600 1950 2600 2000
Wire Wire Line
	2200 2200 2250 2200
Wire Wire Line
	2300 2200 2250 2200
Connection ~ 2250 2200
Wire Wire Line
	1750 2200 1900 2200
Text Label 1750 2200 2    60   ~ 0
SIG_IN0
Wire Wire Line
	2600 1250 2350 1250
Text Label 2350 1250 2    60   ~ 0
ENV_IN0
Wire Wire Line
	2600 1600 3100 1600
Wire Wire Line
	3100 1600 3100 1800
Connection ~ 2600 1600
Wire Wire Line
	2600 1600 2600 1650
Wire Wire Line
	2600 1950 2750 1950
Wire Wire Line
	2750 1950 2750 1800
Wire Wire Line
	2750 1800 2900 1800
Connection ~ 2600 1950
Wire Wire Line
	2900 2100 3000 2100
Wire Wire Line
	3000 2100 3100 2100
Connection ~ 3000 2100
Wire Wire Line
	2600 2450 2600 2400
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD18BEE
P 2250 1800
AR Path="/5BD18BEE" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD18BEE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2250 1650 50  0001 C CNN
F 1 "+12V" H 2250 1940 50  0000 C CNN
F 2 "" H 2250 1800 50  0000 C CNN
F 3 "" H 2250 1800 50  0000 C CNN
	1    2250 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1900 2250 1800
Wire Wire Line
	3100 1600 3350 1600
Connection ~ 3100 1600
Text Label 3350 1600 0    60   ~ 0
ENV_OUT0
Text Notes 1400 1000 0    60   ~ 0
check mmbt3904 and 2n2222: 1-B, 2-E, 3-C-tip = BEC DONE!
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD18BF9
P 2500 2200
AR Path="/5BD18BF9" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD18BF9" Ref="Q?"  Part="1" 
F 0 "Q?" H 2691 2246 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2691 2155 50  0000 L CNN
F 2 "" H 2700 2300 50  0001 C CNN
F 3 "" H 2500 2200 50  0001 C CNN
	1    2500 2200
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD2CB6B
P 5400 1900
AR Path="/5AD5ACBB/5BD2CB6B" Ref="Q?"  Part="1" 
AR Path="/5BD2CB6B" Ref="Q?"  Part="1" 
F 0 "Q?" H 5591 1946 50  0000 L CNN
F 1 "MMBT3904" H 5050 1750 50  0000 L CNN
F 2 "" H 5600 2000 50  0001 C CNN
F 3 "" H 5400 1900 50  0001 C CNN
	1    5400 1900
	1    0    0    -1  
$EndComp
Text Notes 5800 1300 0    60   ~ 0
pulse out - only few with jacks
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD2CB73
P 5050 1900
AR Path="/5AD5ACBB/5BD2CB73" Ref="R?"  Part="1" 
AR Path="/5BD2CB73" Ref="R?"  Part="1" 
F 0 "R?" V 4854 1900 50  0000 C CNN
F 1 "10K" V 4945 1900 50  0000 C CNN
F 2 "" H 5050 1900 50  0001 C CNN
F 3 "" H 5050 1900 50  0001 C CNN
	1    5050 1900
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD2CB7A
P 5500 1550
AR Path="/5AD5ACBB/5BD2CB7A" Ref="R?"  Part="1" 
AR Path="/5BD2CB7A" Ref="R?"  Part="1" 
F 0 "R?" H 5441 1504 50  0000 R CNN
F 1 "47K" H 5441 1595 50  0000 R CNN
F 2 "" H 5500 1550 50  0001 C CNN
F 3 "" H 5500 1550 50  0001 C CNN
	1    5500 1550
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD2CB81
P 5650 1800
AR Path="/5AD5ACBB/5BD2CB81" Ref="R?"  Part="1" 
AR Path="/5BD2CB81" Ref="R?"  Part="1" 
F 0 "R?" H 5591 1754 50  0000 R CNN
F 1 "3.3K" H 5591 1845 50  0000 R CNN
F 2 "" H 5650 1800 50  0001 C CNN
F 3 "" H 5650 1800 50  0001 C CNN
	1    5650 1800
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD2CB88
P 5500 2150
AR Path="/5AD5ACBB/5BD2CB88" Ref="#PWR?"  Part="1" 
AR Path="/5BD2CB88" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5500 1900 50  0001 C CNN
F 1 "GND" H 5505 1977 50  0000 C CNN
F 2 "" H 5500 2150 50  0001 C CNN
F 3 "" H 5500 2150 50  0001 C CNN
	1    5500 2150
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD2CB8E
P 5650 1950
AR Path="/5AD5ACBB/5BD2CB8E" Ref="#PWR?"  Part="1" 
AR Path="/5BD2CB8E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5650 1700 50  0001 C CNN
F 1 "GND" H 5655 1777 50  0000 C CNN
F 2 "" H 5650 1950 50  0001 C CNN
F 3 "" H 5650 1950 50  0001 C CNN
	1    5650 1950
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD2CB94
P 5500 1400
AR Path="/5AD5ACBB/5BD2CB94" Ref="#PWR?"  Part="1" 
AR Path="/5BD2CB94" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5500 1250 50  0001 C CNN
F 1 "+12V" H 5515 1573 50  0000 C CNN
F 2 "" H 5500 1400 50  0001 C CNN
F 3 "" H 5500 1400 50  0001 C CNN
	1    5500 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 1900 5200 1900
Wire Wire Line
	5500 1700 5500 1650
Wire Wire Line
	5500 1450 5500 1400
Wire Wire Line
	5500 1700 5650 1700
Connection ~ 5500 1700
Wire Wire Line
	5500 2150 5500 2100
Wire Wire Line
	5650 1900 5650 1950
Wire Wire Line
	4950 1900 4800 1900
Text Label 4800 1900 2    60   ~ 0
P1_OUT
$Comp
L allcolours_analogue-rescue:AUDIO-JACKERTHENVAR-erthenvar M?
U 1 1 5BD2CBA3
P 6400 1900
AR Path="/5AD5ACBB/5BD2CBA3" Ref="M?"  Part="1" 
AR Path="/5BD2CBA3" Ref="M?"  Part="1" 
F 0 "M?" H 6073 1862 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 6400 1900 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 6430 2050 20  0001 C CNN
F 3 "" H 6400 1900 60  0001 C CNN
	1    6400 1900
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD2CBAA
P 6050 2000
AR Path="/5AD5ACBB/5BD2CBAA" Ref="#PWR?"  Part="1" 
AR Path="/5BD2CBAA" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6050 1750 50  0001 C CNN
F 1 "GND" H 6055 1827 50  0000 C CNN
F 2 "" H 6050 2000 50  0001 C CNN
F 3 "" H 6050 2000 50  0001 C CNN
	1    6050 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 2000 6100 2000
Wire Wire Line
	5650 1700 6000 1700
Connection ~ 5650 1700
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BD2CBB3
P 6400 1450
AR Path="/5AD5ACBB/5BD2CBB3" Ref="J?"  Part="1" 
AR Path="/5BD2CBB3" Ref="J?"  Part="1" 
F 0 "J?" H 6480 1492 50  0000 L CNN
F 1 "Conn_01x01" H 6480 1401 50  0000 L CNN
F 2 "" H 6400 1450 50  0001 C CNN
F 3 "~" H 6400 1450 50  0001 C CNN
	1    6400 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 1700 6000 1450
Wire Wire Line
	6000 1450 6200 1450
Connection ~ 6000 1700
Wire Wire Line
	6000 1700 6100 1700
Text Notes 7650 1250 0    60   ~ 0
pulse in - few with jacks - tested with finger
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD2CBBF
P 8700 2000
AR Path="/5AD5ACBB/5BD2CBBF" Ref="Q?"  Part="1" 
AR Path="/5BD2CBBF" Ref="Q?"  Part="1" 
F 0 "Q?" H 8891 2046 50  0000 L CNN
F 1 "MMBT3904" H 8350 1850 50  0000 L CNN
F 2 "" H 8900 2100 50  0001 C CNN
F 3 "" H 8700 2000 50  0001 C CNN
	1    8700 2000
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD2CBC6
P 8300 2000
AR Path="/5AD5ACBB/5BD2CBC6" Ref="R?"  Part="1" 
AR Path="/5BD2CBC6" Ref="R?"  Part="1" 
F 0 "R?" V 8104 2000 50  0000 C CNN
F 1 "100K" V 8195 2000 50  0000 C CNN
F 2 "" H 8300 2000 50  0001 C CNN
F 3 "" H 8300 2000 50  0001 C CNN
	1    8300 2000
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD2CBCD
P 8800 1650
AR Path="/5AD5ACBB/5BD2CBCD" Ref="R?"  Part="1" 
AR Path="/5BD2CBCD" Ref="R?"  Part="1" 
F 0 "R?" H 8741 1604 50  0000 R CNN
F 1 "10K" H 8741 1695 50  0000 R CNN
F 2 "" H 8800 1650 50  0001 C CNN
F 3 "" H 8800 1650 50  0001 C CNN
	1    8800 1650
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:AUDIO-JACKERTHENVAR-erthenvar M?
U 1 1 5BD2CBD4
P 7800 1800
AR Path="/5AD5ACBB/5BD2CBD4" Ref="M?"  Part="1" 
AR Path="/5BD2CBD4" Ref="M?"  Part="1" 
F 0 "M?" H 7473 1762 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 7800 1800 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 7830 1950 20  0001 C CNN
F 3 "" H 7800 1800 60  0001 C CNN
	1    7800 1800
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BD2CBDB
P 7900 2200
AR Path="/5AD5ACBB/5BD2CBDB" Ref="J?"  Part="1" 
AR Path="/5BD2CBDB" Ref="J?"  Part="1" 
F 0 "J?" H 7820 1975 50  0000 C CNN
F 1 "Conn_01x01" H 7820 2066 50  0000 C CNN
F 2 "" H 7900 2200 50  0001 C CNN
F 3 "~" H 7900 2200 50  0001 C CNN
	1    7900 2200
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:+5V-power #PWR?
U 1 1 5BD2CBE2
P 8800 1500
AR Path="/5AD5ACBB/5BD2CBE2" Ref="#PWR?"  Part="1" 
AR Path="/5BD2CBE2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8800 1350 50  0001 C CNN
F 1 "+5V" H 8815 1673 50  0000 C CNN
F 2 "" H 8800 1500 50  0001 C CNN
F 3 "" H 8800 1500 50  0001 C CNN
	1    8800 1500
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD2CBE8
P 8800 2250
AR Path="/5AD5ACBB/5BD2CBE8" Ref="#PWR?"  Part="1" 
AR Path="/5BD2CBE8" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8800 2000 50  0001 C CNN
F 1 "GND" H 8805 2077 50  0000 C CNN
F 2 "" H 8800 2250 50  0001 C CNN
F 3 "" H 8800 2250 50  0001 C CNN
	1    8800 2250
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD2CBEE
P 8250 1700
AR Path="/5AD5ACBB/5BD2CBEE" Ref="#PWR?"  Part="1" 
AR Path="/5BD2CBEE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8250 1450 50  0001 C CNN
F 1 "GND" H 8255 1527 50  0000 C CNN
F 2 "" H 8250 1700 50  0001 C CNN
F 3 "" H 8250 1700 50  0001 C CNN
	1    8250 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 1700 8250 1700
Wire Wire Line
	8100 2200 8100 2000
Wire Wire Line
	8200 2000 8100 2000
Connection ~ 8100 2000
Wire Wire Line
	8400 2000 8450 2000
Wire Wire Line
	8800 1800 8800 1750
Wire Wire Line
	8800 1550 8800 1500
Wire Wire Line
	8800 2250 8800 2200
Wire Wire Line
	8800 1800 9050 1800
Connection ~ 8800 1800
Text Label 9050 1800 0    60   ~ 0
PULSE_IN1
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD2CBFF
P 8450 2150
AR Path="/5AD5ACBB/5BD2CBFF" Ref="R?"  Part="1" 
AR Path="/5BD2CBFF" Ref="R?"  Part="1" 
F 0 "R?" H 8391 2104 50  0000 R CNN
F 1 "33K" H 8391 2195 50  0000 R CNN
F 2 "" H 8450 2150 50  0001 C CNN
F 3 "" H 8450 2150 50  0001 C CNN
	1    8450 2150
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD2CC06
P 8450 2300
AR Path="/5AD5ACBB/5BD2CC06" Ref="#PWR?"  Part="1" 
AR Path="/5BD2CC06" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8450 2050 50  0001 C CNN
F 1 "GND" H 8455 2127 50  0000 C CNN
F 2 "" H 8450 2300 50  0001 C CNN
F 3 "" H 8450 2300 50  0001 C CNN
	1    8450 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 2050 8450 2000
Connection ~ 8450 2000
Wire Wire Line
	8450 2000 8500 2000
Wire Wire Line
	8450 2300 8450 2250
$EndSCHEMATC
