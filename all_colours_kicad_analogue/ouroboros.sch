EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 8
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
L allcolours_analogue-rescue:Q_NPN_BEC-device Q2
U 1 1 5BB5DC70
P 1575 2825
F 0 "Q2" H 1766 2871 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1766 2780 50  0000 L CNN
F 2 "" H 1775 2925 50  0001 C CNN
F 3 "" H 1575 2825 50  0001 C CNN
	1    1575 2825
	1    0    0    -1  
$EndComp
Text Notes 4000 300  0    197  ~ 0
mmbt or 2n2222\n
Text Notes 6375 3250 0    276  ~ 0
closed ouroboros
Text Notes 5925 5775 0    236  ~ 0
open/broken ouroboros
Text Notes 6025 2575 0    60   ~ 0
revealed traces as pads
Wire Wire Line
	5650 4000 5650 3950
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J13
U 1 1 5BD50AE0
P 5650 4200
F 0 "J13" V 5523 4280 50  0000 L CNN
F 1 "p" V 5614 4280 50  0000 L CNN
F 2 "" H 5650 4200 50  0001 C CNN
F 3 "" H 5650 4200 50  0001 C CNN
	1    5650 4200
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J14
U 1 1 5BD50ADA
P 5650 4325
F 0 "J14" V 5616 4237 50  0000 R CNN
F 1 "p" V 5525 4237 50  0000 R CNN
F 2 "" H 5650 4325 50  0001 C CNN
F 3 "" H 5650 4325 50  0001 C CNN
	1    5650 4325
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR026
U 1 1 5BD50AD4
P 5650 3950
F 0 "#PWR026" H 5650 3800 50  0001 C CNN
F 1 "+12V" H 5650 4090 50  0000 C CNN
F 2 "" H 5650 3950 50  0000 C CNN
F 3 "" H 5650 3950 50  0000 C CNN
	1    5650 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4065 4850 4015
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J11
U 1 1 5BD44115
P 4850 4265
F 0 "J11" V 4723 4345 50  0000 L CNN
F 1 "p" V 4814 4345 50  0000 L CNN
F 2 "" H 4850 4265 50  0001 C CNN
F 3 "" H 4850 4265 50  0001 C CNN
	1    4850 4265
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J12
U 1 1 5BD4410F
P 4850 4390
F 0 "J12" V 4816 4302 50  0000 R CNN
F 1 "p" V 4725 4302 50  0000 R CNN
F 2 "" H 4850 4390 50  0001 C CNN
F 3 "" H 4850 4390 50  0001 C CNN
	1    4850 4390
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR022
U 1 1 5BD44109
P 4850 4015
F 0 "#PWR022" H 4850 3865 50  0001 C CNN
F 1 "+12V" H 4850 4155 50  0000 C CNN
F 2 "" H 4850 4015 50  0000 C CNN
F 3 "" H 4850 4015 50  0000 C CNN
	1    4850 4015
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4395 4100 4345
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J9
U 1 1 5BD41C5A
P 4100 4595
F 0 "J9" V 3973 4675 50  0000 L CNN
F 1 "p" V 4064 4675 50  0000 L CNN
F 2 "" H 4100 4595 50  0001 C CNN
F 3 "" H 4100 4595 50  0001 C CNN
	1    4100 4595
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR018
U 1 1 5BD41C4E
P 4100 4345
F 0 "#PWR018" H 4100 4195 50  0001 C CNN
F 1 "+12V" H 4100 4485 50  0000 C CNN
F 2 "" H 4100 4345 50  0000 C CNN
F 3 "" H 4100 4345 50  0000 C CNN
	1    4100 4345
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4650 3300 4600
$Comp
L allcolours_analogue-rescue:+12V-power #PWR014
U 1 1 5BD3F892
P 3300 4600
F 0 "#PWR014" H 3300 4450 50  0001 C CNN
F 1 "+12V" H 3300 4740 50  0000 C CNN
F 2 "" H 3300 4600 50  0000 C CNN
F 3 "" H 3300 4600 50  0000 C CNN
	1    3300 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4850 2400 4800
$Comp
L allcolours_analogue-rescue:+12V-power #PWR010
U 1 1 5BD38180
P 2400 4800
F 0 "#PWR010" H 2400 4650 50  0001 C CNN
F 1 "+12V" H 2400 4940 50  0000 C CNN
F 2 "" H 2400 4800 50  0000 C CNN
F 3 "" H 2400 4800 50  0000 C CNN
	1    2400 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4525 5750 4525
Connection ~ 5650 4525
$Comp
L allcolours_analogue-rescue:D-device D11
U 1 1 5BD2E5F2
P 5650 4675
F 0 "D11" H 5650 4575 50  0000 C CNN
F 1 "1n4148" H 5650 4825 50  0000 C CNN
F 2 "" H 5650 4675 50  0001 C CNN
F 3 "" H 5650 4675 50  0001 C CNN
	1    5650 4675
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J10
U 1 1 5BD41C54
P 4100 4720
F 0 "J10" V 4066 4632 50  0000 R CNN
F 1 "p" V 3975 4632 50  0000 R CNN
F 2 "" H 4100 4720 50  0001 C CNN
F 3 "" H 4100 4720 50  0001 C CNN
	1    4100 4720
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J7
U 1 1 5BD3F89E
P 3300 4850
F 0 "J7" V 3173 4930 50  0000 L CNN
F 1 "p" V 3264 4930 50  0000 L CNN
F 2 "" H 3300 4850 50  0001 C CNN
F 3 "" H 3300 4850 50  0001 C CNN
	1    3300 4850
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J8
U 1 1 5BD3F898
P 3300 4975
F 0 "J8" V 3266 4887 50  0000 R CNN
F 1 "p" V 3175 4887 50  0000 R CNN
F 2 "" H 3300 4975 50  0001 C CNN
F 3 "" H 3300 4975 50  0001 C CNN
	1    3300 4975
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J5
U 1 1 5BD3818C
P 2400 5050
F 0 "J5" V 2273 5130 50  0000 L CNN
F 1 "p" V 2364 5130 50  0000 L CNN
F 2 "" H 2400 5050 50  0001 C CNN
F 3 "" H 2400 5050 50  0001 C CNN
	1    2400 5050
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J6
U 1 1 5BD38186
P 2400 5175
F 0 "J6" V 2366 5087 50  0000 R CNN
F 1 "p" V 2275 5087 50  0000 R CNN
F 2 "" H 2400 5175 50  0001 C CNN
F 3 "" H 2400 5175 50  0001 C CNN
	1    2400 5175
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 5100 1500 5050
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J3
U 1 1 5BD35D81
P 1500 5300
F 0 "J3" V 1373 5380 50  0000 L CNN
F 1 "p" V 1464 5380 50  0000 L CNN
F 2 "" H 1500 5300 50  0001 C CNN
F 3 "" H 1500 5300 50  0001 C CNN
	1    1500 5300
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J4
U 1 1 5BD35AE5
P 1500 5425
F 0 "J4" V 1466 5337 50  0000 R CNN
F 1 "p" V 1375 5337 50  0000 R CNN
F 2 "" H 1500 5425 50  0001 C CNN
F 3 "" H 1500 5425 50  0001 C CNN
	1    1500 5425
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 6975 5750 4525
Wire Wire Line
	5300 5075 5350 5075
Wire Wire Line
	5300 4875 5300 5075
Wire Wire Line
	4500 5225 4500 5275
Wire Wire Line
	4600 5225 4500 5225
Wire Wire Line
	4600 5025 4600 5225
Wire Wire Line
	3750 5175 3750 5525
Wire Wire Line
	3300 5175 3450 5175
Wire Wire Line
	2900 5775 3000 5775
Wire Wire Line
	2900 5475 2900 5775
Wire Wire Line
	2000 5975 2100 5975
Wire Wire Line
	2000 5675 2000 5975
Wire Wire Line
	1500 5675 1700 5675
Wire Wire Line
	850  6975 850  6225
Wire Wire Line
	1150 6225 1200 6225
Wire Wire Line
	1500 5625 1500 5675
Wire Wire Line
	1500 5975 1500 6025
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q1
U 1 1 5BD2E64D
P 1400 6225
F 0 "Q1" H 1591 6271 50  0000 L CNN
F 1 "Q_NPN_BEC" H 1591 6180 50  0000 L CNN
F 2 "" H 1600 6325 50  0001 C CNN
F 3 "" H 1400 6225 50  0001 C CNN
	1    1400 6225
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR06
U 1 1 5BD2E647
P 1500 5050
F 0 "#PWR06" H 1500 4900 50  0001 C CNN
F 1 "+12V" H 1500 5190 50  0000 C CNN
F 2 "" H 1500 5050 50  0000 C CNN
F 3 "" H 1500 5050 50  0000 C CNN
	1    1500 5050
	1    0    0    -1  
$EndComp
Connection ~ 1500 5675
$Comp
L allcolours_analogue-rescue:D-device D1
U 1 1 5BD2E641
P 1500 5825
F 0 "D1" H 1500 5725 50  0000 C CNN
F 1 "1n4148" H 1500 5975 50  0000 C CNN
F 2 "" H 1500 5825 50  0001 C CNN
F 3 "" H 1500 5825 50  0001 C CNN
	1    1500 5825
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR07
U 1 1 5BD2E635
P 1500 6475
F 0 "#PWR07" H 1500 6225 50  0001 C CNN
F 1 "GND" H 1500 6325 50  0000 C CNN
F 2 "" H 1500 6475 50  0000 C CNN
F 3 "" H 1500 6475 50  0000 C CNN
	1    1500 6475
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C3
U 1 1 5BD2E62F
P 1000 6225
F 0 "C3" H 1025 6325 50  0000 L CNN
F 1 "1N" H 1025 6125 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1038 6075 50  0001 C CNN
F 3 "" H 1000 6225 50  0000 C CNN
	1    1000 6225
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4500 5275 4550 5275
Wire Wire Line
	4850 5025 4850 5075
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q9
U 1 1 5BD2E625
P 4750 5275
F 0 "Q9" H 4941 5321 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4941 5230 50  0000 L CNN
F 2 "" H 4950 5375 50  0001 C CNN
F 3 "" H 4750 5275 50  0001 C CNN
	1    4750 5275
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D9
U 1 1 5BD2E619
P 4850 4875
F 0 "D9" H 4850 4775 50  0000 C CNN
F 1 "1n4148" H 4850 5025 50  0000 C CNN
F 2 "" H 4850 4875 50  0001 C CNN
F 3 "" H 4850 4875 50  0001 C CNN
	1    4850 4875
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR023
U 1 1 5BD2E60D
P 4850 5525
F 0 "#PWR023" H 4850 5275 50  0001 C CNN
F 1 "GND" H 4850 5375 50  0000 C CNN
F 2 "" H 4850 5525 50  0000 C CNN
F 3 "" H 4850 5525 50  0000 C CNN
	1    4850 5525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C11
U 1 1 5BD2E607
P 4450 5025
F 0 "C11" H 4475 5125 50  0000 L CNN
F 1 "1N" H 4475 4925 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4488 4875 50  0001 C CNN
F 3 "" H 4450 5025 50  0000 C CNN
	1    4450 5025
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5650 4825 5650 4875
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q11
U 1 1 5BD2E5FE
P 5550 5075
F 0 "Q11" H 5741 5121 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5741 5030 50  0000 L CNN
F 2 "" H 5750 5175 50  0001 C CNN
F 3 "" H 5550 5075 50  0001 C CNN
	1    5550 5075
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR027
U 1 1 5BD2E5E6
P 5650 5325
F 0 "#PWR027" H 5650 5075 50  0001 C CNN
F 1 "GND" H 5650 5175 50  0000 C CNN
F 2 "" H 5650 5325 50  0000 C CNN
F 3 "" H 5650 5325 50  0000 C CNN
	1    5650 5325
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 5525 3800 5525
Wire Wire Line
	4100 5275 4100 5325
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q7
U 1 1 5BD2E5D6
P 4000 5525
F 0 "Q7" H 4191 5571 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4191 5480 50  0000 L CNN
F 2 "" H 4200 5625 50  0001 C CNN
F 3 "" H 4000 5525 50  0001 C CNN
	1    4000 5525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D7
U 1 1 5BD2E5CA
P 4100 5125
F 0 "D7" H 4100 5025 50  0000 C CNN
F 1 "1n4148" H 4100 5275 50  0000 C CNN
F 2 "" H 4100 5125 50  0001 C CNN
F 3 "" H 4100 5125 50  0001 C CNN
	1    4100 5125
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR019
U 1 1 5BD2E5BE
P 4100 5775
F 0 "#PWR019" H 4100 5525 50  0001 C CNN
F 1 "GND" H 4100 5625 50  0000 C CNN
F 2 "" H 4100 5775 50  0000 C CNN
F 3 "" H 4100 5775 50  0000 C CNN
	1    4100 5775
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C9
U 1 1 5BD2E5B8
P 3600 5175
F 0 "C9" H 3625 5275 50  0000 L CNN
F 1 "1N" H 3625 5075 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3638 5025 50  0001 C CNN
F 3 "" H 3600 5175 50  0000 C CNN
	1    3600 5175
	0    -1   -1   0   
$EndComp
Connection ~ 3300 5175
Wire Wire Line
	3300 5175 3300 5225
Wire Wire Line
	3300 5525 3300 5575
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q5
U 1 1 5BD2E5AF
P 3200 5775
F 0 "Q5" H 3391 5821 50  0000 L CNN
F 1 "Q_NPN_BEC" H 3391 5730 50  0000 L CNN
F 2 "" H 3400 5875 50  0001 C CNN
F 3 "" H 3200 5775 50  0001 C CNN
	1    3200 5775
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D5
U 1 1 5BD2E5A3
P 3300 5375
F 0 "D5" H 3300 5275 50  0000 C CNN
F 1 "1n4148" H 3300 5525 50  0000 C CNN
F 2 "" H 3300 5375 50  0001 C CNN
F 3 "" H 3300 5375 50  0001 C CNN
	1    3300 5375
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR015
U 1 1 5BD2E597
P 3300 6025
F 0 "#PWR015" H 3300 5775 50  0001 C CNN
F 1 "GND" H 3300 5875 50  0000 C CNN
F 2 "" H 3300 6025 50  0000 C CNN
F 3 "" H 3300 6025 50  0000 C CNN
	1    3300 6025
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C7
U 1 1 5BD2E591
P 2750 5475
F 0 "C7" H 2775 5575 50  0000 L CNN
F 1 "1N" H 2775 5375 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2788 5325 50  0001 C CNN
F 3 "" H 2750 5475 50  0000 C CNN
	1    2750 5475
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2400 5375 2400 5400
Wire Wire Line
	2400 5725 2400 5775
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q3
U 1 1 5BD2E588
P 2300 5975
F 0 "Q3" H 2491 6021 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2491 5930 50  0000 L CNN
F 2 "" H 2500 6075 50  0001 C CNN
F 3 "" H 2300 5975 50  0001 C CNN
	1    2300 5975
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D3
U 1 1 5BD2E57C
P 2400 5575
F 0 "D3" H 2400 5475 50  0000 C CNN
F 1 "1n4148" H 2400 5725 50  0000 C CNN
F 2 "" H 2400 5575 50  0001 C CNN
F 3 "" H 2400 5575 50  0001 C CNN
	1    2400 5575
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR011
U 1 1 5BD2E570
P 2400 6275
F 0 "#PWR011" H 2400 6025 50  0001 C CNN
F 1 "GND" H 2400 6125 50  0000 C CNN
F 2 "" H 2400 6275 50  0000 C CNN
F 3 "" H 2400 6275 50  0000 C CNN
	1    2400 6275
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C5
U 1 1 5BD2E56A
P 1850 5675
F 0 "C5" H 1875 5775 50  0000 L CNN
F 1 "1N" H 1875 5575 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1888 5525 50  0001 C CNN
F 3 "" H 1850 5675 50  0000 C CNN
	1    1850 5675
	0    -1   -1   0   
$EndComp
Text Notes 1450 925  0    197  ~ 0
0-12V ins
Wire Wire Line
	5925 3575 5925 1125
Wire Wire Line
	5825 1125 5925 1125
Wire Wire Line
	5475 1675 5525 1675
Wire Wire Line
	5475 1475 5475 1675
Wire Wire Line
	4675 1825 4675 1875
Wire Wire Line
	4775 1825 4675 1825
Wire Wire Line
	4775 1625 4775 1825
Wire Wire Line
	3925 1775 3925 2125
Wire Wire Line
	3475 1775 3625 1775
Wire Wire Line
	3075 2375 3175 2375
Wire Wire Line
	3075 2075 3075 2375
Wire Wire Line
	2175 2575 2275 2575
Wire Wire Line
	2175 2275 2175 2575
Wire Wire Line
	1675 2275 1875 2275
Wire Wire Line
	1025 3575 1025 2825
Wire Wire Line
	1325 2825 1375 2825
Wire Wire Line
	1675 2225 1675 2275
Wire Wire Line
	1675 2575 1675 2625
Wire Wire Line
	1675 1875 1675 1925
$Comp
L allcolours_analogue-rescue:+12V-power #PWR08
U 1 1 5BB5DC6A
P 1675 1875
F 0 "#PWR08" H 1675 1725 50  0001 C CNN
F 1 "+12V" H 1675 2015 50  0000 C CNN
F 2 "" H 1675 1875 50  0000 C CNN
F 3 "" H 1675 1875 50  0000 C CNN
	1    1675 1875
	1    0    0    -1  
$EndComp
Connection ~ 1675 2275
$Comp
L allcolours_analogue-rescue:D-device D2
U 1 1 5BB5DC63
P 1675 2425
F 0 "D2" H 1675 2325 50  0000 C CNN
F 1 "1n4148" H 1675 2575 50  0000 C CNN
F 2 "" H 1675 2425 50  0001 C CNN
F 3 "" H 1675 2425 50  0001 C CNN
	1    1675 2425
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R4
U 1 1 5BB5DC5C
P 1675 2075
F 0 "R4" V 1755 2075 50  0000 C CNN
F 1 "33K" V 1675 2075 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1605 2075 50  0001 C CNN
F 3 "" H 1675 2075 50  0000 C CNN
	1    1675 2075
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR09
U 1 1 5BB5DC56
P 1675 3075
F 0 "#PWR09" H 1675 2825 50  0001 C CNN
F 1 "GND" H 1675 2925 50  0000 C CNN
F 2 "" H 1675 3075 50  0000 C CNN
F 3 "" H 1675 3075 50  0000 C CNN
	1    1675 3075
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C4
U 1 1 5BB5DC4F
P 1175 2825
F 0 "C4" H 1200 2925 50  0000 L CNN
F 1 "1N" H 1200 2725 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1213 2675 50  0001 C CNN
F 3 "" H 1175 2825 50  0000 C CNN
	1    1175 2825
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4675 1875 4725 1875
Wire Wire Line
	5025 1275 5025 1300
Wire Wire Line
	5025 1625 5025 1675
Wire Wire Line
	5025 925  5025 975 
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q10
U 1 1 5BB5D7F0
P 4925 1875
F 0 "Q10" H 5116 1921 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5116 1830 50  0000 L CNN
F 2 "" H 5125 1975 50  0001 C CNN
F 3 "" H 4925 1875 50  0001 C CNN
	1    4925 1875
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR024
U 1 1 5BB5D7EA
P 5025 925
F 0 "#PWR024" H 5025 775 50  0001 C CNN
F 1 "+12V" H 5025 1065 50  0000 C CNN
F 2 "" H 5025 925 50  0000 C CNN
F 3 "" H 5025 925 50  0000 C CNN
	1    5025 925 
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D10
U 1 1 5BB5D7E3
P 5025 1475
F 0 "D10" H 5025 1375 50  0000 C CNN
F 1 "1n4148" H 5025 1625 50  0000 C CNN
F 2 "" H 5025 1475 50  0001 C CNN
F 3 "" H 5025 1475 50  0001 C CNN
	1    5025 1475
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R8
U 1 1 5BB5D7DC
P 5025 1125
F 0 "R8" V 5105 1125 50  0000 C CNN
F 1 "33K" V 5025 1125 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4955 1125 50  0001 C CNN
F 3 "" H 5025 1125 50  0000 C CNN
	1    5025 1125
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR025
U 1 1 5BB5D7D6
P 5025 2125
F 0 "#PWR025" H 5025 1875 50  0001 C CNN
F 1 "GND" H 5025 1975 50  0000 C CNN
F 2 "" H 5025 2125 50  0000 C CNN
F 3 "" H 5025 2125 50  0000 C CNN
	1    5025 2125
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C16
U 1 1 5BB5D7CF
P 4625 1625
F 0 "C16" H 4650 1725 50  0000 L CNN
F 1 "1N" H 4650 1525 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4663 1475 50  0001 C CNN
F 3 "" H 4625 1625 50  0000 C CNN
	1    4625 1625
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5825 1075 5825 1125
Wire Wire Line
	5825 1425 5825 1475
Wire Wire Line
	5825 725  5825 775 
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q12
U 1 1 5BB5D4E8
P 5725 1675
F 0 "Q12" H 5916 1721 50  0000 L CNN
F 1 "Q_NPN_BEC" H 5916 1630 50  0000 L CNN
F 2 "" H 5925 1775 50  0001 C CNN
F 3 "" H 5725 1675 50  0001 C CNN
	1    5725 1675
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR028
U 1 1 5BB5D4E2
P 5825 725
F 0 "#PWR028" H 5825 575 50  0001 C CNN
F 1 "+12V" H 5825 865 50  0000 C CNN
F 2 "" H 5825 725 50  0000 C CNN
F 3 "" H 5825 725 50  0000 C CNN
	1    5825 725 
	1    0    0    -1  
$EndComp
Connection ~ 5825 1125
$Comp
L allcolours_analogue-rescue:D-device D12
U 1 1 5BB5D4DB
P 5825 1275
F 0 "D12" H 5825 1175 50  0000 C CNN
F 1 "1n4148" H 5825 1425 50  0000 C CNN
F 2 "" H 5825 1275 50  0001 C CNN
F 3 "" H 5825 1275 50  0001 C CNN
	1    5825 1275
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R9
U 1 1 5BB5D4D4
P 5825 925
F 0 "R9" V 5905 925 50  0000 C CNN
F 1 "33K" V 5825 925 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5755 925 50  0001 C CNN
F 3 "" H 5825 925 50  0000 C CNN
	1    5825 925 
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR029
U 1 1 5BB5D4CE
P 5825 1925
F 0 "#PWR029" H 5825 1675 50  0001 C CNN
F 1 "GND" H 5825 1775 50  0000 C CNN
F 2 "" H 5825 1925 50  0000 C CNN
F 3 "" H 5825 1925 50  0000 C CNN
	1    5825 1925
	1    0    0    -1  
$EndComp
Wire Wire Line
	3925 2125 3975 2125
Wire Wire Line
	4275 1525 4275 1550
Wire Wire Line
	4275 1875 4275 1925
Wire Wire Line
	4275 1175 4275 1225
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q8
U 1 1 5BB5D112
P 4175 2125
F 0 "Q8" H 4366 2171 50  0000 L CNN
F 1 "Q_NPN_BEC" H 4366 2080 50  0000 L CNN
F 2 "" H 4375 2225 50  0001 C CNN
F 3 "" H 4175 2125 50  0001 C CNN
	1    4175 2125
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR020
U 1 1 5BB5D10C
P 4275 1175
F 0 "#PWR020" H 4275 1025 50  0001 C CNN
F 1 "+12V" H 4275 1315 50  0000 C CNN
F 2 "" H 4275 1175 50  0000 C CNN
F 3 "" H 4275 1175 50  0000 C CNN
	1    4275 1175
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D8
U 1 1 5BB5D105
P 4275 1725
F 0 "D8" H 4275 1625 50  0000 C CNN
F 1 "1n4148" H 4275 1875 50  0000 C CNN
F 2 "" H 4275 1725 50  0001 C CNN
F 3 "" H 4275 1725 50  0001 C CNN
	1    4275 1725
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R7
U 1 1 5BB5D0FE
P 4275 1375
F 0 "R7" V 4355 1375 50  0000 C CNN
F 1 "33K" V 4275 1375 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4205 1375 50  0001 C CNN
F 3 "" H 4275 1375 50  0000 C CNN
	1    4275 1375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR021
U 1 1 5BB5D0F8
P 4275 2375
F 0 "#PWR021" H 4275 2125 50  0001 C CNN
F 1 "GND" H 4275 2225 50  0000 C CNN
F 2 "" H 4275 2375 50  0000 C CNN
F 3 "" H 4275 2375 50  0000 C CNN
	1    4275 2375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C10
U 1 1 5BB5D0F1
P 3775 1775
F 0 "C10" H 3800 1875 50  0000 L CNN
F 1 "1N" H 3800 1675 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3813 1625 50  0001 C CNN
F 3 "" H 3775 1775 50  0000 C CNN
	1    3775 1775
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3475 1775 3475 1825
Wire Wire Line
	3475 2125 3475 2175
Wire Wire Line
	3475 1425 3475 1475
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q6
U 1 1 5BB5CF3F
P 3375 2375
F 0 "Q6" H 3566 2421 50  0000 L CNN
F 1 "Q_NPN_BEC" H 3566 2330 50  0000 L CNN
F 2 "" H 3575 2475 50  0001 C CNN
F 3 "" H 3375 2375 50  0001 C CNN
	1    3375 2375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR016
U 1 1 5BB5CF39
P 3475 1425
F 0 "#PWR016" H 3475 1275 50  0001 C CNN
F 1 "+12V" H 3475 1565 50  0000 C CNN
F 2 "" H 3475 1425 50  0000 C CNN
F 3 "" H 3475 1425 50  0000 C CNN
	1    3475 1425
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D6
U 1 1 5BB5CF33
P 3475 1975
F 0 "D6" H 3475 1875 50  0000 C CNN
F 1 "1n4148" H 3475 2125 50  0000 C CNN
F 2 "" H 3475 1975 50  0001 C CNN
F 3 "" H 3475 1975 50  0001 C CNN
	1    3475 1975
	0    -1   -1   0   
$EndComp
Connection ~ 3475 1775
$Comp
L allcolours_analogue-rescue:R-device R6
U 1 1 5BB5CF2D
P 3475 1625
F 0 "R6" V 3555 1625 50  0000 C CNN
F 1 "33K" V 3475 1625 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3405 1625 50  0001 C CNN
F 3 "" H 3475 1625 50  0000 C CNN
	1    3475 1625
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR017
U 1 1 5BB5CF27
P 3475 2625
F 0 "#PWR017" H 3475 2375 50  0001 C CNN
F 1 "GND" H 3475 2475 50  0000 C CNN
F 2 "" H 3475 2625 50  0000 C CNN
F 3 "" H 3475 2625 50  0000 C CNN
	1    3475 2625
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C8
U 1 1 5BB5CF21
P 2925 2075
F 0 "C8" H 2950 2175 50  0000 L CNN
F 1 "1N" H 2950 1975 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2963 1925 50  0001 C CNN
F 3 "" H 2925 2075 50  0000 C CNN
	1    2925 2075
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2575 1975 2575 1995
Wire Wire Line
	2575 2325 2575 2375
Wire Wire Line
	2575 1625 2575 1675
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q4
U 1 1 5BB3D775
P 2475 2575
F 0 "Q4" H 2666 2621 50  0000 L CNN
F 1 "Q_NPN_BEC" H 2666 2530 50  0000 L CNN
F 2 "" H 2675 2675 50  0001 C CNN
F 3 "" H 2475 2575 50  0001 C CNN
	1    2475 2575
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR012
U 1 1 5BAC465C
P 2575 1625
F 0 "#PWR012" H 2575 1475 50  0001 C CNN
F 1 "+12V" H 2575 1765 50  0000 C CNN
F 2 "" H 2575 1625 50  0000 C CNN
F 3 "" H 2575 1625 50  0000 C CNN
	1    2575 1625
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:D-device D4
U 1 1 5BAC4640
P 2575 2175
F 0 "D4" H 2575 2075 50  0000 C CNN
F 1 "1n4148" H 2575 2325 50  0000 C CNN
F 2 "" H 2575 2175 50  0001 C CNN
F 3 "" H 2575 2175 50  0001 C CNN
	1    2575 2175
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:R-device R5
U 1 1 5BAC4639
P 2575 1825
F 0 "R5" V 2655 1825 50  0000 C CNN
F 1 "33K" V 2575 1825 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2505 1825 50  0001 C CNN
F 3 "" H 2575 1825 50  0000 C CNN
	1    2575 1825
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR013
U 1 1 5BAC462C
P 2575 2825
F 0 "#PWR013" H 2575 2575 50  0001 C CNN
F 1 "GND" H 2575 2675 50  0000 C CNN
F 2 "" H 2575 2825 50  0000 C CNN
F 3 "" H 2575 2825 50  0000 C CNN
	1    2575 2825
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C6
U 1 1 5BAC4611
P 2025 2275
F 0 "C6" H 2050 2375 50  0000 L CNN
F 1 "1N" H 2050 2175 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2063 2125 50  0001 C CNN
F 3 "" H 2025 2275 50  0000 C CNN
	1    2025 2275
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1025 3575 5925 3575
Wire Wire Line
	1675 3075 1675 3025
Wire Wire Line
	2575 2775 2575 2825
Wire Wire Line
	3475 2575 3475 2625
Wire Wire Line
	4275 2325 4275 2375
Wire Wire Line
	5025 2075 5025 2125
Wire Wire Line
	5825 1875 5825 1925
Wire Wire Line
	2575 1995 2775 1995
Wire Wire Line
	2775 1995 2775 2075
Connection ~ 2575 1995
Wire Wire Line
	2575 1995 2575 2025
Wire Wire Line
	4275 1550 4475 1550
Wire Wire Line
	4475 1550 4475 1625
Connection ~ 4275 1550
Wire Wire Line
	4275 1550 4275 1575
$Comp
L allcolours_analogue-rescue:C-device C18
U 1 1 5BB5D4C7
P 5325 1475
F 0 "C18" H 5350 1575 50  0000 L CNN
F 1 "1N" H 5350 1375 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5363 1325 50  0001 C CNN
F 3 "" H 5325 1475 50  0000 C CNN
	1    5325 1475
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5175 1300 5025 1300
Wire Wire Line
	5175 1300 5175 1475
Connection ~ 5025 1300
Wire Wire Line
	5025 1300 5025 1325
Wire Wire Line
	850  6975 5750 6975
Wire Wire Line
	1500 6425 1500 6475
Wire Wire Line
	3300 5975 3300 6025
Wire Wire Line
	4100 5725 4100 5775
Wire Wire Line
	4850 5475 4850 5525
Wire Wire Line
	5650 5275 5650 5325
Wire Wire Line
	2400 5400 2600 5400
Wire Wire Line
	2600 5400 2600 5475
Connection ~ 2400 5400
Wire Wire Line
	2400 5400 2400 5425
Wire Wire Line
	4100 4920 4100 4950
Wire Wire Line
	4100 4950 4300 4950
Wire Wire Line
	4300 4950 4300 5025
Connection ~ 4100 4950
Wire Wire Line
	4100 4950 4100 4975
Wire Wire Line
	4850 4590 4850 4680
$Comp
L allcolours_analogue-rescue:C-device C17
U 1 1 5BD2E5E0
P 5150 4875
F 0 "C17" H 5175 4975 50  0000 L CNN
F 1 "1N" H 5175 4775 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5188 4725 50  0001 C CNN
F 3 "" H 5150 4875 50  0000 C CNN
	1    5150 4875
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4850 4680 5000 4680
Wire Wire Line
	5000 4680 5000 4875
Connection ~ 4850 4680
Wire Wire Line
	4850 4680 4850 4725
Wire Wire Line
	2400 6175 2400 6275
$EndSCHEMATC
