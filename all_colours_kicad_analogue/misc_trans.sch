EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 8
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
Text Notes 2900 1350 0    60   ~ 0
envelope\n
Text Notes 7750 3200 0    197  ~ 0
logic xor
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD11FA8
P 8775 4450
AR Path="/5BD11FA8" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD11FA8" Ref="Q?"  Part="1" 
F 0 "Q?" H 8966 4496 50  0000 L CNN
F 1 "Q_NPN_BEC" H 8966 4405 50  0000 L CNN
F 2 "" H 8975 4550 50  0001 C CNN
F 3 "" H 8775 4450 50  0001 C CNN
	1    8775 4450
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD11FAE
P 8775 5025
AR Path="/5BD11FAE" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD11FAE" Ref="Q?"  Part="1" 
F 0 "Q?" H 8966 5071 50  0000 L CNN
F 1 "Q_NPN_BEC" H 8966 4980 50  0000 L CNN
F 2 "" H 8975 5125 50  0001 C CNN
F 3 "" H 8775 5025 50  0001 C CNN
	1    8775 5025
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD12CDF
P 8425 4450
AR Path="/5AD5ACBB/5BD12CDF" Ref="R?"  Part="1" 
AR Path="/5BD12CDF" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD12CDF" Ref="R?"  Part="1" 
F 0 "R?" V 8229 4450 50  0000 C CNN
F 1 "10K" V 8320 4450 50  0000 C CNN
F 2 "" H 8425 4450 50  0001 C CNN
F 3 "" H 8425 4450 50  0001 C CNN
	1    8425 4450
	0    1    -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD12DB7
P 8425 5025
AR Path="/5AD5ACBB/5BD12DB7" Ref="R?"  Part="1" 
AR Path="/5BD12DB7" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD12DB7" Ref="R?"  Part="1" 
F 0 "R?" V 8229 5025 50  0000 C CNN
F 1 "10K" V 8320 5025 50  0000 C CNN
F 2 "" H 8425 5025 50  0001 C CNN
F 3 "" H 8425 5025 50  0001 C CNN
	1    8425 5025
	0    1    -1   0   
$EndComp
Wire Wire Line
	8525 4450 8575 4450
Wire Wire Line
	8525 5025 8575 5025
Wire Wire Line
	8875 4650 8875 4825
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD14C85
P 8875 4125
AR Path="/5AD5ACBB/5BD14C85" Ref="#PWR?"  Part="1" 
AR Path="/5BD14C85" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD14C85" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8875 3975 50  0001 C CNN
F 1 "+12V" H 8890 4298 50  0000 C CNN
F 2 "" H 8875 4125 50  0001 C CNN
F 3 "" H 8875 4125 50  0001 C CNN
	1    8875 4125
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD14CD5
P 8875 5550
AR Path="/5AD5ACBB/5BD14CD5" Ref="#PWR?"  Part="1" 
AR Path="/5BD14CD5" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD14CD5" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8875 5300 50  0001 C CNN
F 1 "GND" H 8880 5377 50  0000 C CNN
F 2 "" H 8875 5550 50  0001 C CNN
F 3 "" H 8875 5550 50  0001 C CNN
	1    8875 5550
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD15856
P 7425 5400
AR Path="/5BD15856" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD15856" Ref="Q?"  Part="1" 
F 0 "Q?" H 7616 5446 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7616 5355 50  0000 L CNN
F 2 "" H 7625 5500 50  0001 C CNN
F 3 "" H 7425 5400 50  0001 C CNN
	1    7425 5400
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD1585C
P 7425 5975
AR Path="/5BD1585C" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD1585C" Ref="Q?"  Part="1" 
F 0 "Q?" H 7616 6021 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7616 5930 50  0000 L CNN
F 2 "" H 7625 6075 50  0001 C CNN
F 3 "" H 7425 5975 50  0001 C CNN
	1    7425 5975
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD15862
P 7075 5400
AR Path="/5AD5ACBB/5BD15862" Ref="R?"  Part="1" 
AR Path="/5BD15862" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD15862" Ref="R?"  Part="1" 
F 0 "R?" V 6879 5400 50  0000 C CNN
F 1 "10K" V 6970 5400 50  0000 C CNN
F 2 "" H 7075 5400 50  0001 C CNN
F 3 "" H 7075 5400 50  0001 C CNN
	1    7075 5400
	0    1    -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD15868
P 7075 5975
AR Path="/5AD5ACBB/5BD15868" Ref="R?"  Part="1" 
AR Path="/5BD15868" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD15868" Ref="R?"  Part="1" 
F 0 "R?" V 6879 5975 50  0000 C CNN
F 1 "10K" V 6970 5975 50  0000 C CNN
F 2 "" H 7075 5975 50  0001 C CNN
F 3 "" H 7075 5975 50  0001 C CNN
	1    7075 5975
	0    1    -1   0   
$EndComp
Wire Wire Line
	7175 5400 7225 5400
Wire Wire Line
	7175 5975 7225 5975
Wire Wire Line
	7525 5600 7525 5775
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD15871
P 7525 4900
AR Path="/5AD5ACBB/5BD15871" Ref="#PWR?"  Part="1" 
AR Path="/5BD15871" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD15871" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7525 4750 50  0001 C CNN
F 1 "+12V" H 7650 4950 50  0000 C CNN
F 2 "" H 7525 4900 50  0001 C CNN
F 3 "" H 7525 4900 50  0001 C CNN
	1    7525 4900
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD160A5
P 7400 3425
AR Path="/5BD160A5" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD160A5" Ref="Q?"  Part="1" 
F 0 "Q?" H 7591 3471 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7591 3380 50  0000 L CNN
F 2 "" H 7600 3525 50  0001 C CNN
F 3 "" H 7400 3425 50  0001 C CNN
	1    7400 3425
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD160AB
P 7400 4000
AR Path="/5BD160AB" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD160AB" Ref="Q?"  Part="1" 
F 0 "Q?" H 7591 4046 50  0000 L CNN
F 1 "Q_NPN_BEC" H 7591 3955 50  0000 L CNN
F 2 "" H 7600 4100 50  0001 C CNN
F 3 "" H 7400 4000 50  0001 C CNN
	1    7400 4000
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD160B1
P 7050 3425
AR Path="/5AD5ACBB/5BD160B1" Ref="R?"  Part="1" 
AR Path="/5BD160B1" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD160B1" Ref="R?"  Part="1" 
F 0 "R?" V 6854 3425 50  0000 C CNN
F 1 "10K" V 6945 3425 50  0000 C CNN
F 2 "" H 7050 3425 50  0001 C CNN
F 3 "" H 7050 3425 50  0001 C CNN
	1    7050 3425
	0    1    -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD160B7
P 7050 4000
AR Path="/5AD5ACBB/5BD160B7" Ref="R?"  Part="1" 
AR Path="/5BD160B7" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD160B7" Ref="R?"  Part="1" 
F 0 "R?" V 6854 4000 50  0000 C CNN
F 1 "10K" V 6945 4000 50  0000 C CNN
F 2 "" H 7050 4000 50  0001 C CNN
F 3 "" H 7050 4000 50  0001 C CNN
	1    7050 4000
	0    1    -1   0   
$EndComp
Wire Wire Line
	7150 3425 7200 3425
Wire Wire Line
	7150 4000 7200 4000
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD160C0
P 7500 3100
AR Path="/5AD5ACBB/5BD160C0" Ref="#PWR?"  Part="1" 
AR Path="/5BD160C0" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD160C0" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7500 2950 50  0001 C CNN
F 1 "+12V" H 7515 3273 50  0000 C CNN
F 2 "" H 7500 3100 50  0001 C CNN
F 3 "" H 7500 3100 50  0001 C CNN
	1    7500 3100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD17170
P 7500 4375
AR Path="/5AD5ACBB/5BD17170" Ref="R?"  Part="1" 
AR Path="/5BD17170" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD17170" Ref="R?"  Part="1" 
F 0 "R?" V 7304 4375 50  0000 C CNN
F 1 "1K" V 7395 4375 50  0000 C CNN
F 2 "" H 7500 4375 50  0001 C CNN
F 3 "" H 7500 4375 50  0001 C CNN
	1    7500 4375
	1    0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD17339
P 7525 6275
AR Path="/5AD5ACBB/5BD17339" Ref="#PWR?"  Part="1" 
AR Path="/5BD17339" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD17339" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7525 6025 50  0001 C CNN
F 1 "GND" H 7530 6102 50  0000 C CNN
F 2 "" H 7525 6275 50  0001 C CNN
F 3 "" H 7525 6275 50  0001 C CNN
	1    7525 6275
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD17384
P 7500 4525
AR Path="/5AD5ACBB/5BD17384" Ref="#PWR?"  Part="1" 
AR Path="/5BD17384" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD17384" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7500 4275 50  0001 C CNN
F 1 "GND" H 7505 4352 50  0000 C CNN
F 2 "" H 7500 4525 50  0001 C CNN
F 3 "" H 7500 4525 50  0001 C CNN
	1    7500 4525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD173EF
P 8875 5375
AR Path="/5AD5ACBB/5BD173EF" Ref="R?"  Part="1" 
AR Path="/5BD173EF" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD173EF" Ref="R?"  Part="1" 
F 0 "R?" V 8679 5375 50  0000 C CNN
F 1 "1K" V 8770 5375 50  0000 C CNN
F 2 "" H 8875 5375 50  0001 C CNN
F 3 "" H 8875 5375 50  0001 C CNN
	1    8875 5375
	1    0    0    1   
$EndComp
Wire Wire Line
	8875 5225 8875 5275
Wire Wire Line
	8875 5475 8875 5550
Wire Wire Line
	7500 4200 7500 4225
Wire Wire Line
	7500 4475 7500 4525
Wire Wire Line
	7525 6175 7525 6275
Wire Wire Line
	8875 4125 8875 4250
Wire Wire Line
	7500 3100 7500 3225
Wire Wire Line
	7500 4225 8075 4225
Wire Wire Line
	8325 4225 8325 4450
Connection ~ 7500 4225
Wire Wire Line
	7500 4225 7500 4275
Wire Wire Line
	7525 3175 7675 3175
Wire Wire Line
	7675 3175 7675 3800
Wire Wire Line
	7675 3800 7500 3800
Wire Wire Line
	7500 3625 8075 3625
Wire Wire Line
	8075 3625 8075 4225
Connection ~ 8075 4225
Wire Wire Line
	8075 4225 8325 4225
Wire Wire Line
	6950 4000 6775 4000
Wire Wire Line
	6775 4000 6775 5975
Wire Wire Line
	6775 5975 6975 5975
Wire Wire Line
	6925 3425 6925 5400
Wire Wire Line
	6925 5400 6975 5400
Wire Wire Line
	6925 3425 6950 3425
Wire Wire Line
	6925 5400 6500 5400
Connection ~ 6925 5400
Wire Wire Line
	6775 5975 6500 5975
Connection ~ 6775 5975
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD25B50
P 7525 5050
AR Path="/5AD5ACBB/5BD25B50" Ref="R?"  Part="1" 
AR Path="/5BD25B50" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD25B50" Ref="R?"  Part="1" 
F 0 "R?" V 7329 5050 50  0000 C CNN
F 1 "1K" V 7420 5050 50  0000 C CNN
F 2 "" H 7525 5050 50  0001 C CNN
F 3 "" H 7525 5050 50  0001 C CNN
	1    7525 5050
	1    0    0    1   
$EndComp
Wire Wire Line
	7525 4900 7525 4950
Wire Wire Line
	7525 5150 7525 5175
Wire Wire Line
	7525 5175 8325 5175
Wire Wire Line
	8325 5175 8325 5025
Connection ~ 7525 5175
Wire Wire Line
	7525 5175 7525 5200
Wire Wire Line
	8875 5275 9150 5275
Connection ~ 8875 5275
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BD2B236
P 9350 5275
AR Path="/5AD5ACBB/5BD2B236" Ref="J?"  Part="1" 
AR Path="/5BD2B236" Ref="J?"  Part="1" 
AR Path="/5BD09509/5BD2B236" Ref="J?"  Part="1" 
F 0 "J?" H 9270 5050 50  0000 C CNN
F 1 "XOR OUT" H 9270 5141 50  0000 C CNN
F 2 "" H 9350 5275 50  0001 C CNN
F 3 "~" H 9350 5275 50  0001 C CNN
	1    9350 5275
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BD2B3EA
P 6300 5400
AR Path="/5AD5ACBB/5BD2B3EA" Ref="J?"  Part="1" 
AR Path="/5BD2B3EA" Ref="J?"  Part="1" 
AR Path="/5BD09509/5BD2B3EA" Ref="J?"  Part="1" 
F 0 "J?" H 6220 5175 50  0000 C CNN
F 1 "XOR IN" H 6220 5266 50  0000 C CNN
F 2 "" H 6300 5400 50  0001 C CNN
F 3 "~" H 6300 5400 50  0001 C CNN
	1    6300 5400
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BD2B4A8
P 6300 5975
AR Path="/5AD5ACBB/5BD2B4A8" Ref="J?"  Part="1" 
AR Path="/5BD2B4A8" Ref="J?"  Part="1" 
AR Path="/5BD09509/5BD2B4A8" Ref="J?"  Part="1" 
F 0 "J?" H 6220 5750 50  0000 C CNN
F 1 "XOR IN" H 6220 5841 50  0000 C CNN
F 2 "" H 6300 5975 50  0001 C CNN
F 3 "~" H 6300 5975 50  0001 C CNN
	1    6300 5975
	-1   0    0    1   
$EndComp
Text Notes 3925 4200 0    118  ~ 0
or 5 trans xor
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD2E16D
P 1825 4375
AR Path="/5BD2E16D" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD2E16D" Ref="Q?"  Part="1" 
F 0 "Q?" H 2016 4421 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2016 4330 50  0000 L CNN
F 2 "" H 2025 4475 50  0001 C CNN
F 3 "" H 1825 4375 50  0001 C CNN
	1    1825 4375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD2E173
P 1475 4375
AR Path="/5AD5ACBB/5BD2E173" Ref="R?"  Part="1" 
AR Path="/5BD2E173" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD2E173" Ref="R?"  Part="1" 
F 0 "R?" V 1279 4375 50  0000 C CNN
F 1 "10K" V 1370 4375 50  0000 C CNN
F 2 "" H 1475 4375 50  0001 C CNN
F 3 "" H 1475 4375 50  0001 C CNN
	1    1475 4375
	0    1    -1   0   
$EndComp
Wire Wire Line
	1575 4375 1625 4375
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD2E17B
P 1925 3875
AR Path="/5AD5ACBB/5BD2E17B" Ref="#PWR?"  Part="1" 
AR Path="/5BD2E17B" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD2E17B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1925 3725 50  0001 C CNN
F 1 "+12V" H 2050 3925 50  0000 C CNN
F 2 "" H 1925 3875 50  0001 C CNN
F 3 "" H 1925 3875 50  0001 C CNN
	1    1925 3875
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD2E185
P 1925 4025
AR Path="/5AD5ACBB/5BD2E185" Ref="R?"  Part="1" 
AR Path="/5BD2E185" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD2E185" Ref="R?"  Part="1" 
F 0 "R?" V 1729 4025 50  0000 C CNN
F 1 "1K" V 1820 4025 50  0000 C CNN
F 2 "" H 1925 4025 50  0001 C CNN
F 3 "" H 1925 4025 50  0001 C CNN
	1    1925 4025
	1    0    0    1   
$EndComp
Wire Wire Line
	1925 3875 1925 3925
Wire Wire Line
	1925 4125 1925 4150
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD31B8F
P 1825 5550
AR Path="/5BD31B8F" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD31B8F" Ref="Q?"  Part="1" 
F 0 "Q?" H 2016 5596 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2016 5505 50  0000 L CNN
F 2 "" H 2025 5650 50  0001 C CNN
F 3 "" H 1825 5550 50  0001 C CNN
	1    1825 5550
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD31B95
P 1475 5550
AR Path="/5AD5ACBB/5BD31B95" Ref="R?"  Part="1" 
AR Path="/5BD31B95" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD31B95" Ref="R?"  Part="1" 
F 0 "R?" V 1279 5550 50  0000 C CNN
F 1 "10K" V 1370 5550 50  0000 C CNN
F 2 "" H 1475 5550 50  0001 C CNN
F 3 "" H 1475 5550 50  0001 C CNN
	1    1475 5550
	0    1    -1   0   
$EndComp
Wire Wire Line
	1575 5550 1625 5550
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD31B9D
P 1925 5050
AR Path="/5AD5ACBB/5BD31B9D" Ref="#PWR?"  Part="1" 
AR Path="/5BD31B9D" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD31B9D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1925 4900 50  0001 C CNN
F 1 "+12V" H 2050 5100 50  0000 C CNN
F 2 "" H 1925 5050 50  0001 C CNN
F 3 "" H 1925 5050 50  0001 C CNN
	1    1925 5050
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD31BA3
P 1925 5200
AR Path="/5AD5ACBB/5BD31BA3" Ref="R?"  Part="1" 
AR Path="/5BD31BA3" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD31BA3" Ref="R?"  Part="1" 
F 0 "R?" V 1729 5200 50  0000 C CNN
F 1 "1K" V 1820 5200 50  0000 C CNN
F 2 "" H 1925 5200 50  0001 C CNN
F 3 "" H 1925 5200 50  0001 C CNN
	1    1925 5200
	1    0    0    1   
$EndComp
Wire Wire Line
	1925 5050 1925 5100
Wire Wire Line
	1925 5300 1925 5325
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD33FED
P 3025 4450
AR Path="/5BD33FED" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD33FED" Ref="Q?"  Part="1" 
F 0 "Q?" H 3216 4496 50  0000 L CNN
F 1 "Q_NPN_BEC" H 3216 4405 50  0000 L CNN
F 2 "" H 3225 4550 50  0001 C CNN
F 3 "" H 3025 4450 50  0001 C CNN
	1    3025 4450
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD33FF3
P 2675 4450
AR Path="/5AD5ACBB/5BD33FF3" Ref="R?"  Part="1" 
AR Path="/5BD33FF3" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD33FF3" Ref="R?"  Part="1" 
F 0 "R?" V 2479 4450 50  0000 C CNN
F 1 "10K" V 2570 4450 50  0000 C CNN
F 2 "" H 2675 4450 50  0001 C CNN
F 3 "" H 2675 4450 50  0001 C CNN
	1    2675 4450
	0    1    -1   0   
$EndComp
Wire Wire Line
	2775 4450 2825 4450
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD33FFB
P 3125 3950
AR Path="/5AD5ACBB/5BD33FFB" Ref="#PWR?"  Part="1" 
AR Path="/5BD33FFB" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD33FFB" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3125 3800 50  0001 C CNN
F 1 "+12V" H 3250 4000 50  0000 C CNN
F 2 "" H 3125 3950 50  0001 C CNN
F 3 "" H 3125 3950 50  0001 C CNN
	1    3125 3950
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD34001
P 3125 4100
AR Path="/5AD5ACBB/5BD34001" Ref="R?"  Part="1" 
AR Path="/5BD34001" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD34001" Ref="R?"  Part="1" 
F 0 "R?" V 2929 4100 50  0000 C CNN
F 1 "1K" V 3020 4100 50  0000 C CNN
F 2 "" H 3125 4100 50  0001 C CNN
F 3 "" H 3125 4100 50  0001 C CNN
	1    3125 4100
	1    0    0    1   
$EndComp
Wire Wire Line
	3125 3950 3125 4000
Wire Wire Line
	3125 4200 3125 4225
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD3A6A5
P 2675 4650
AR Path="/5AD5ACBB/5BD3A6A5" Ref="R?"  Part="1" 
AR Path="/5BD3A6A5" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD3A6A5" Ref="R?"  Part="1" 
F 0 "R?" V 2479 4650 50  0000 C CNN
F 1 "10K" V 2570 4650 50  0000 C CNN
F 2 "" H 2675 4650 50  0001 C CNN
F 3 "" H 2675 4650 50  0001 C CNN
	1    2675 4650
	0    1    -1   0   
$EndComp
Wire Wire Line
	2825 4450 2825 4650
Wire Wire Line
	2825 4650 2775 4650
Connection ~ 2825 4450
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD3CCD1
P 4050 5250
AR Path="/5BD3CCD1" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD3CCD1" Ref="Q?"  Part="1" 
F 0 "Q?" H 4241 5296 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4241 5205 50  0000 L CNN
F 2 "" H 4250 5350 50  0001 C CNN
F 3 "" H 4050 5250 50  0001 C CNN
	1    4050 5250
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD3CCD7
P 3700 5250
AR Path="/5AD5ACBB/5BD3CCD7" Ref="R?"  Part="1" 
AR Path="/5BD3CCD7" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD3CCD7" Ref="R?"  Part="1" 
F 0 "R?" V 3504 5250 50  0000 C CNN
F 1 "10K" V 3595 5250 50  0000 C CNN
F 2 "" H 3700 5250 50  0001 C CNN
F 3 "" H 3700 5250 50  0001 C CNN
	1    3700 5250
	0    1    -1   0   
$EndComp
Wire Wire Line
	3800 5250 3850 5250
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD3CCDF
P 4150 4750
AR Path="/5AD5ACBB/5BD3CCDF" Ref="#PWR?"  Part="1" 
AR Path="/5BD3CCDF" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD3CCDF" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4150 4600 50  0001 C CNN
F 1 "+12V" H 4275 4800 50  0000 C CNN
F 2 "" H 4150 4750 50  0001 C CNN
F 3 "" H 4150 4750 50  0001 C CNN
	1    4150 4750
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD3CCE5
P 4150 4900
AR Path="/5AD5ACBB/5BD3CCE5" Ref="R?"  Part="1" 
AR Path="/5BD3CCE5" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD3CCE5" Ref="R?"  Part="1" 
F 0 "R?" V 3954 4900 50  0000 C CNN
F 1 "1K" V 4045 4900 50  0000 C CNN
F 2 "" H 4150 4900 50  0001 C CNN
F 3 "" H 4150 4900 50  0001 C CNN
	1    4150 4900
	1    0    0    1   
$EndComp
Wire Wire Line
	4150 4750 4150 4800
Wire Wire Line
	4150 5000 4150 5050
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD3CCED
P 3700 5450
AR Path="/5AD5ACBB/5BD3CCED" Ref="R?"  Part="1" 
AR Path="/5BD3CCED" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD3CCED" Ref="R?"  Part="1" 
F 0 "R?" V 3504 5450 50  0000 C CNN
F 1 "10K" V 3595 5450 50  0000 C CNN
F 2 "" H 3700 5450 50  0001 C CNN
F 3 "" H 3700 5450 50  0001 C CNN
	1    3700 5450
	0    1    -1   0   
$EndComp
Wire Wire Line
	3850 5250 3850 5450
Wire Wire Line
	3850 5450 3800 5450
Connection ~ 3850 5250
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5BD3F89F
P 3000 5925
AR Path="/5BD3F89F" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5BD3F89F" Ref="Q?"  Part="1" 
F 0 "Q?" H 3191 5971 50  0000 L CNN
F 1 "Q_NPN_BEC" H 3191 5880 50  0000 L CNN
F 2 "" H 3200 6025 50  0001 C CNN
F 3 "" H 3000 5925 50  0001 C CNN
	1    3000 5925
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD3F8A5
P 2650 5925
AR Path="/5AD5ACBB/5BD3F8A5" Ref="R?"  Part="1" 
AR Path="/5BD3F8A5" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD3F8A5" Ref="R?"  Part="1" 
F 0 "R?" V 2454 5925 50  0000 C CNN
F 1 "10K" V 2545 5925 50  0000 C CNN
F 2 "" H 2650 5925 50  0001 C CNN
F 3 "" H 2650 5925 50  0001 C CNN
	1    2650 5925
	0    1    -1   0   
$EndComp
Wire Wire Line
	2750 5925 2800 5925
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BD3F8AD
P 3100 5425
AR Path="/5AD5ACBB/5BD3F8AD" Ref="#PWR?"  Part="1" 
AR Path="/5BD3F8AD" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD3F8AD" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3100 5275 50  0001 C CNN
F 1 "+12V" H 3225 5475 50  0000 C CNN
F 2 "" H 3100 5425 50  0001 C CNN
F 3 "" H 3100 5425 50  0001 C CNN
	1    3100 5425
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD3F8B3
P 3100 5575
AR Path="/5AD5ACBB/5BD3F8B3" Ref="R?"  Part="1" 
AR Path="/5BD3F8B3" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD3F8B3" Ref="R?"  Part="1" 
F 0 "R?" V 2904 5575 50  0000 C CNN
F 1 "1K" V 2995 5575 50  0000 C CNN
F 2 "" H 3100 5575 50  0001 C CNN
F 3 "" H 3100 5575 50  0001 C CNN
	1    3100 5575
	1    0    0    1   
$EndComp
Wire Wire Line
	3100 5425 3100 5475
Wire Wire Line
	3100 5675 3100 5725
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BD3F8BB
P 2650 6125
AR Path="/5AD5ACBB/5BD3F8BB" Ref="R?"  Part="1" 
AR Path="/5BD3F8BB" Ref="R?"  Part="1" 
AR Path="/5BD09509/5BD3F8BB" Ref="R?"  Part="1" 
F 0 "R?" V 2454 6125 50  0000 C CNN
F 1 "10K" V 2545 6125 50  0000 C CNN
F 2 "" H 2650 6125 50  0001 C CNN
F 3 "" H 2650 6125 50  0001 C CNN
	1    2650 6125
	0    1    -1   0   
$EndComp
Wire Wire Line
	2800 5925 2800 6125
Wire Wire Line
	2800 6125 2750 6125
Connection ~ 2800 5925
Wire Wire Line
	1375 4375 1325 4375
Wire Wire Line
	1375 5550 1225 5550
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD498B2
P 1925 4675
AR Path="/5AD5ACBB/5BD498B2" Ref="#PWR?"  Part="1" 
AR Path="/5BD498B2" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD498B2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1925 4425 50  0001 C CNN
F 1 "GND" H 1930 4502 50  0000 C CNN
F 2 "" H 1925 4675 50  0001 C CNN
F 3 "" H 1925 4675 50  0001 C CNN
	1    1925 4675
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD4992B
P 1925 5850
AR Path="/5AD5ACBB/5BD4992B" Ref="#PWR?"  Part="1" 
AR Path="/5BD4992B" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD4992B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1925 5600 50  0001 C CNN
F 1 "GND" H 1930 5677 50  0000 C CNN
F 2 "" H 1925 5850 50  0001 C CNN
F 3 "" H 1925 5850 50  0001 C CNN
	1    1925 5850
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD499A4
P 3125 4725
AR Path="/5AD5ACBB/5BD499A4" Ref="#PWR?"  Part="1" 
AR Path="/5BD499A4" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD499A4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3125 4475 50  0001 C CNN
F 1 "GND" H 3130 4552 50  0000 C CNN
F 2 "" H 3125 4725 50  0001 C CNN
F 3 "" H 3125 4725 50  0001 C CNN
	1    3125 4725
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD49A1D
P 3100 6200
AR Path="/5AD5ACBB/5BD49A1D" Ref="#PWR?"  Part="1" 
AR Path="/5BD49A1D" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD49A1D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3100 5950 50  0001 C CNN
F 1 "GND" H 3105 6027 50  0000 C CNN
F 2 "" H 3100 6200 50  0001 C CNN
F 3 "" H 3100 6200 50  0001 C CNN
	1    3100 6200
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5BD49A96
P 4150 5525
AR Path="/5AD5ACBB/5BD49A96" Ref="#PWR?"  Part="1" 
AR Path="/5BD49A96" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5BD49A96" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4150 5275 50  0001 C CNN
F 1 "GND" H 4155 5352 50  0000 C CNN
F 2 "" H 4150 5525 50  0001 C CNN
F 3 "" H 4150 5525 50  0001 C CNN
	1    4150 5525
	1    0    0    -1  
$EndComp
Wire Wire Line
	1925 4575 1925 4675
Wire Wire Line
	3125 4650 3125 4725
Wire Wire Line
	4150 5450 4150 5525
Wire Wire Line
	1925 5750 1925 5850
Wire Wire Line
	3100 6125 3100 6200
Wire Wire Line
	1225 5550 1225 6125
Wire Wire Line
	1225 6125 2550 6125
Connection ~ 1225 5550
Wire Wire Line
	1225 5550 975  5550
Wire Wire Line
	1325 4375 1325 6000
Wire Wire Line
	1325 6000 2550 6000
Wire Wire Line
	2550 6000 2550 5925
Connection ~ 1325 4375
Wire Wire Line
	1325 4375 875  4375
Wire Wire Line
	1925 4150 2575 4150
Wire Wire Line
	2575 4150 2575 4450
Connection ~ 1925 4150
Wire Wire Line
	1925 4150 1925 4175
Wire Wire Line
	1925 5325 2575 5325
Wire Wire Line
	2575 5325 2575 4650
Connection ~ 1925 5325
Wire Wire Line
	1925 5325 1925 5350
Wire Wire Line
	3125 4225 3600 4225
Wire Wire Line
	3600 4225 3600 5250
Connection ~ 3125 4225
Wire Wire Line
	3125 4225 3125 4250
Wire Wire Line
	3100 5725 3600 5725
Wire Wire Line
	3600 5725 3600 5450
Connection ~ 3100 5725
Wire Wire Line
	4150 5050 4625 5050
Connection ~ 4150 5050
Text Notes 4725 925  0    236  ~ 47
all +12V 0V - no mid, no bias\n
$EndSCHEMATC
