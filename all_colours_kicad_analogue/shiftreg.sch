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
F 2 "" H 4850 2150 60  0001 C CNN
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
P 5425 1600
F 0 "C37" H 5517 1646 50  0000 L CNN
F 1 "100N" H 5517 1555 50  0000 L CNN
F 2 "" H 5425 1600 50  0001 C CNN
F 3 "~" H 5425 1600 50  0001 C CNN
	1    5425 1600
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR095
U 1 1 5BCE0273
P 5425 1450
F 0 "#PWR095" H 5425 1300 50  0001 C CNN
F 1 "+12V-power" H 5440 1623 50  0000 C CNN
F 2 "" H 5425 1450 50  0001 C CNN
F 3 "" H 5425 1450 50  0001 C CNN
	1    5425 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR096
U 1 1 5BCE0282
P 5425 1750
F 0 "#PWR096" H 5425 1500 50  0001 C CNN
F 1 "GND" H 5430 1577 50  0000 C CNN
F 2 "" H 5425 1750 50  0001 C CNN
F 3 "" H 5425 1750 50  0001 C CNN
	1    5425 1750
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R50
U 1 1 5BCE0372
P 5450 2400
F 0 "R50" H 5509 2446 50  0000 L CNN
F 1 "10K" H 5509 2355 50  0000 L CNN
F 2 "" H 5450 2400 50  0001 C CNN
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
F 2 "" H 5450 2650 50  0001 C CNN
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
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J30
U 1 1 5BCE0CAD
P 5700 2000
F 0 "J30" H 5780 2042 50  0000 L CNN
F 1 " " H 5780 1951 50  0000 L CNN
F 2 "" H 5700 2000 50  0001 C CNN
F 3 "" H 5700 2000 50  0001 C CNN
	1    5700 2000
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J31
U 1 1 5BCE0CFC
P 5700 2100
F 0 "J31" H 5780 2142 50  0000 L CNN
F 1 " " H 5780 2051 50  0000 L CNN
F 2 "" H 5700 2100 50  0001 C CNN
F 3 "" H 5700 2100 50  0001 C CNN
	1    5700 2100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J32
U 1 1 5BCE0D24
P 5700 2200
F 0 "J32" H 5780 2242 50  0000 L CNN
F 1 " " H 5780 2151 50  0000 L CNN
F 2 "" H 5700 2200 50  0001 C CNN
F 3 "" H 5700 2200 50  0001 C CNN
	1    5700 2200
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J33
U 1 1 5BCE0D46
P 5700 2300
F 0 "J33" H 5780 2342 50  0000 L CNN
F 1 " " H 5780 2251 50  0000 L CNN
F 2 "" H 5700 2300 50  0001 C CNN
F 3 "" H 5700 2300 50  0001 C CNN
	1    5700 2300
	1    0    0    -1  
$EndComp
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
	5425 1500 5425 1450
Wire Wire Line
	5425 1750 5425 1700
$Comp
L 4xxx_IEEE:4015 U7
U 2 1 5BCE34F1
P 4850 3425
F 0 "U7" H 4550 3800 50  0000 C CNN
F 1 "4015" H 4550 3725 50  0000 C CNN
F 2 "" H 4850 3425 60  0001 C CNN
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
F 2 "" H 5450 3675 50  0001 C CNN
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
F 2 "" H 5450 3925 50  0001 C CNN
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
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J34
U 1 1 5BCE351C
P 5700 3275
F 0 "J34" H 5780 3317 50  0000 L CNN
F 1 " " H 5780 3226 50  0000 L CNN
F 2 "" H 5700 3275 50  0001 C CNN
F 3 "" H 5700 3275 50  0001 C CNN
	1    5700 3275
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J35
U 1 1 5BCE3522
P 5700 3375
F 0 "J35" H 5780 3417 50  0000 L CNN
F 1 " " H 5780 3326 50  0000 L CNN
F 2 "" H 5700 3375 50  0001 C CNN
F 3 "" H 5700 3375 50  0001 C CNN
	1    5700 3375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J36
U 1 1 5BCE3528
P 5700 3475
F 0 "J36" H 5780 3517 50  0000 L CNN
F 1 " " H 5780 3426 50  0000 L CNN
F 2 "" H 5700 3475 50  0001 C CNN
F 3 "" H 5700 3475 50  0001 C CNN
	1    5700 3475
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J37
U 1 1 5BCE352E
P 5700 3575
F 0 "J37" H 5780 3617 50  0000 L CNN
F 1 " " H 5780 3526 50  0000 L CNN
F 2 "" H 5700 3575 50  0001 C CNN
F 3 "" H 5700 3575 50  0001 C CNN
	1    5700 3575
	1    0    0    -1  
$EndComp
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
$Comp
L 4xxx_IEEE:4015 U6
U 1 1 5BCE5AB3
P 4775 4675
F 0 "U6" H 4475 5050 50  0000 C CNN
F 1 "4015" H 4475 4975 50  0000 C CNN
F 2 "" H 4775 4675 60  0001 C CNN
F 3 "" H 4775 4675 60  0001 C CNN
	1    4775 4675
	1    0    0    -1  
$EndComp
Wire Wire Line
	4225 4525 4075 4525
Text Label 4075 4525 0    60   ~ 0
CLOCK
$Comp
L power:GND #PWR086
U 1 1 5BCE5ABB
P 4775 5000
F 0 "#PWR086" H 4775 4750 50  0001 C CNN
F 1 "GND" H 4780 4827 50  0000 C CNN
F 2 "" H 4775 5000 50  0001 C CNN
F 3 "" H 4775 5000 50  0001 C CNN
	1    4775 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4775 4925 4775 5000
$Comp
L allcolours_analogue-rescue:+12V-power #PWR085
U 1 1 5BCE5AC2
P 4775 4375
F 0 "#PWR085" H 4775 4225 50  0001 C CNN
F 1 "+12V-power" H 4790 4548 50  0000 C CNN
F 2 "" H 4775 4375 50  0001 C CNN
F 3 "" H 4775 4375 50  0001 C CNN
	1    4775 4375
	1    0    0    -1  
$EndComp
Wire Wire Line
	4775 4425 4775 4375
$Comp
L Device:C_Small C34
U 1 1 5BCE5AC9
P 1575 7100
F 0 "C34" H 1667 7146 50  0000 L CNN
F 1 "100N" H 1667 7055 50  0000 L CNN
F 2 "" H 1575 7100 50  0001 C CNN
F 3 "~" H 1575 7100 50  0001 C CNN
	1    1575 7100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR079
U 1 1 5BCE5ACF
P 1575 6950
F 0 "#PWR079" H 1575 6800 50  0001 C CNN
F 1 "+12V-power" H 1590 7123 50  0000 C CNN
F 2 "" H 1575 6950 50  0001 C CNN
F 3 "" H 1575 6950 50  0001 C CNN
	1    1575 6950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR080
U 1 1 5BCE5AD5
P 1575 7250
F 0 "#PWR080" H 1575 7000 50  0001 C CNN
F 1 "GND" H 1580 7077 50  0000 C CNN
F 2 "" H 1575 7250 50  0001 C CNN
F 3 "" H 1575 7250 50  0001 C CNN
	1    1575 7250
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R48
U 1 1 5BCE5ADB
P 5375 4925
F 0 "R48" H 5434 4971 50  0000 L CNN
F 1 "10K" H 5434 4880 50  0000 L CNN
F 2 "" H 5375 4925 50  0001 C CNN
F 3 "" H 5375 4925 50  0001 C CNN
	1    5375 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C35
U 1 1 5BCE5AE1
P 5375 5175
F 0 "C35" H 5467 5221 50  0000 L CNN
F 1 "1N" H 5467 5130 50  0000 L CNN
F 2 "" H 5375 5175 50  0001 C CNN
F 3 "~" H 5375 5175 50  0001 C CNN
	1    5375 5175
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR093
U 1 1 5BCE5AE7
P 5375 5325
F 0 "#PWR093" H 5375 5075 50  0001 C CNN
F 1 "GND" H 5380 5152 50  0000 C CNN
F 2 "" H 5375 5325 50  0001 C CNN
F 3 "" H 5375 5325 50  0001 C CNN
	1    5375 5325
	1    0    0    -1  
$EndComp
Wire Wire Line
	5325 4825 5375 4825
Wire Wire Line
	5375 5075 5375 5050
Wire Wire Line
	5375 5325 5375 5275
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J22
U 1 1 5BCE5AF0
P 5625 4525
F 0 "J22" H 5705 4567 50  0000 L CNN
F 1 " " H 5705 4476 50  0000 L CNN
F 2 "" H 5625 4525 50  0001 C CNN
F 3 "" H 5625 4525 50  0001 C CNN
	1    5625 4525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J23
U 1 1 5BCE5AF6
P 5625 4625
F 0 "J23" H 5705 4667 50  0000 L CNN
F 1 " " H 5705 4576 50  0000 L CNN
F 2 "" H 5625 4625 50  0001 C CNN
F 3 "" H 5625 4625 50  0001 C CNN
	1    5625 4625
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J24
U 1 1 5BCE5AFC
P 5625 4725
F 0 "J24" H 5705 4767 50  0000 L CNN
F 1 " " H 5705 4676 50  0000 L CNN
F 2 "" H 5625 4725 50  0001 C CNN
F 3 "" H 5625 4725 50  0001 C CNN
	1    5625 4725
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J25
U 1 1 5BCE5B02
P 5625 4825
F 0 "J25" H 5705 4867 50  0000 L CNN
F 1 " " H 5705 4776 50  0000 L CNN
F 2 "" H 5625 4825 50  0001 C CNN
F 3 "" H 5625 4825 50  0001 C CNN
	1    5625 4825
	1    0    0    -1  
$EndComp
Wire Wire Line
	5325 4525 5425 4525
Wire Wire Line
	5325 4625 5425 4625
Wire Wire Line
	5325 4725 5425 4725
Wire Wire Line
	5375 4825 5425 4825
Connection ~ 5375 4825
$Comp
L power:GND #PWR081
U 1 1 5BCE5B13
P 4175 4825
F 0 "#PWR081" H 4175 4575 50  0001 C CNN
F 1 "GND" H 4180 4652 50  0000 C CNN
F 2 "" H 4175 4825 50  0001 C CNN
F 3 "" H 4175 4825 50  0001 C CNN
	1    4175 4825
	1    0    0    -1  
$EndComp
Wire Wire Line
	4175 4825 4225 4825
Wire Wire Line
	1575 7000 1575 6950
Wire Wire Line
	1575 7250 1575 7200
$Comp
L 4xxx_IEEE:4015 U6
U 2 1 5BCE5B24
P 4775 5950
F 0 "U6" H 4475 6325 50  0000 C CNN
F 1 "4015" H 4475 6250 50  0000 C CNN
F 2 "" H 4775 5950 60  0001 C CNN
F 3 "" H 4775 5950 60  0001 C CNN
	2    4775 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4225 5800 4075 5800
Text Label 4075 5800 0    60   ~ 0
CLOCK
$Comp
L power:GND #PWR088
U 1 1 5BCE5B2C
P 4775 6275
F 0 "#PWR088" H 4775 6025 50  0001 C CNN
F 1 "GND" H 4780 6102 50  0000 C CNN
F 2 "" H 4775 6275 50  0001 C CNN
F 3 "" H 4775 6275 50  0001 C CNN
	1    4775 6275
	1    0    0    -1  
$EndComp
Wire Wire Line
	4775 6200 4775 6275
$Comp
L allcolours_analogue-rescue:+12V-power #PWR087
U 1 1 5BCE5B33
P 4775 5650
F 0 "#PWR087" H 4775 5500 50  0001 C CNN
F 1 "+12V-power" H 4790 5823 50  0000 C CNN
F 2 "" H 4775 5650 50  0001 C CNN
F 3 "" H 4775 5650 50  0001 C CNN
	1    4775 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4775 5700 4775 5650
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J26
U 1 1 5BCE5B4F
P 5625 5800
F 0 "J26" H 5705 5842 50  0000 L CNN
F 1 " " H 5705 5751 50  0000 L CNN
F 2 "" H 5625 5800 50  0001 C CNN
F 3 "" H 5625 5800 50  0001 C CNN
	1    5625 5800
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J27
U 1 1 5BCE5B55
P 5625 5900
F 0 "J27" H 5705 5942 50  0000 L CNN
F 1 " " H 5705 5851 50  0000 L CNN
F 2 "" H 5625 5900 50  0001 C CNN
F 3 "" H 5625 5900 50  0001 C CNN
	1    5625 5900
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J28
U 1 1 5BCE5B5B
P 5625 6000
F 0 "J28" H 5705 6042 50  0000 L CNN
F 1 " " H 5705 5951 50  0000 L CNN
F 2 "" H 5625 6000 50  0001 C CNN
F 3 "" H 5625 6000 50  0001 C CNN
	1    5625 6000
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J29
U 1 1 5BCE5B61
P 5625 6100
F 0 "J29" H 5705 6142 50  0000 L CNN
F 1 " " H 5705 6051 50  0000 L CNN
F 2 "" H 5625 6100 50  0001 C CNN
F 3 "" H 5625 6100 50  0001 C CNN
	1    5625 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5325 5800 5425 5800
Wire Wire Line
	5325 5900 5425 5900
Wire Wire Line
	5325 6000 5425 6000
$Comp
L power:GND #PWR082
U 1 1 5BCE5B72
P 4175 6100
F 0 "#PWR082" H 4175 5850 50  0001 C CNN
F 1 "GND" H 4180 5927 50  0000 C CNN
F 2 "" H 4175 6100 50  0001 C CNN
F 3 "" H 4175 6100 50  0001 C CNN
	1    4175 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4175 6100 4225 6100
Wire Wire Line
	4175 5200 5075 5200
Wire Wire Line
	5075 5200 5075 5050
Wire Wire Line
	5075 5050 5375 5050
Wire Wire Line
	4175 5200 4175 5950
Wire Wire Line
	4175 5950 4225 5950
Connection ~ 5375 5050
Wire Wire Line
	5375 5050 5375 5025
Wire Wire Line
	4175 4675 4175 4600
Wire Wire Line
	4175 4600 4050 4600
Wire Wire Line
	4050 4600 4050 3975
Wire Wire Line
	4050 3975 5200 3975
Wire Wire Line
	5200 3975 5200 3825
Wire Wire Line
	5200 3825 5450 3825
Connection ~ 5450 3825
Wire Wire Line
	5375 6600 5375 6550
Wire Wire Line
	5375 6350 5375 6300
$Comp
L power:GND #PWR094
U 1 1 5BCE5B46
P 5375 6600
F 0 "#PWR094" H 5375 6350 50  0001 C CNN
F 1 "GND" H 5380 6427 50  0000 C CNN
F 2 "" H 5375 6600 50  0001 C CNN
F 3 "" H 5375 6600 50  0001 C CNN
	1    5375 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C36
U 1 1 5BCE5B40
P 5375 6450
F 0 "C36" H 5467 6496 50  0000 L CNN
F 1 "1N" H 5467 6405 50  0000 L CNN
F 2 "" H 5375 6450 50  0001 C CNN
F 3 "~" H 5375 6450 50  0001 C CNN
	1    5375 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5375 6100 5425 6100
Wire Wire Line
	5325 6100 5375 6100
Connection ~ 5375 6100
$Comp
L allcolours_analogue-rescue:R_Small-device R49
U 1 1 5BCE5B3A
P 5375 6200
F 0 "R49" H 5434 6246 50  0000 L CNN
F 1 "10K" H 5434 6155 50  0000 L CNN
F 2 "" H 5375 6200 50  0001 C CNN
F 3 "" H 5375 6200 50  0001 C CNN
	1    5375 6200
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Q_NPN_BEC-device Q?
U 1 1 5C00E6CA
P 7425 1075
AR Path="/5AD5ACBB/5C00E6CA" Ref="Q?"  Part="1" 
AR Path="/5C00E6CA" Ref="Q?"  Part="1" 
AR Path="/5BD09509/5C00E6CA" Ref="Q?"  Part="1" 
AR Path="/5BD3A596/5C00E6CA" Ref="Q29"  Part="1" 
F 0 "Q29" H 7616 1121 50  0000 L CNN
F 1 "MMBT3904" H 7075 925 50  0000 L CNN
F 2 "" H 7625 1175 50  0001 C CNN
F 3 "" H 7425 1075 50  0001 C CNN
	1    7425 1075
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR?
U 1 1 5C00E6E7
P 7525 1725
AR Path="/5AD5ACBB/5C00E6E7" Ref="#PWR?"  Part="1" 
AR Path="/5C00E6E7" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C00E6E7" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C00E6E7" Ref="#PWR0100"  Part="1" 
F 0 "#PWR0100" H 7525 1475 50  0001 C CNN
F 1 "GND" H 7530 1552 50  0000 C CNN
F 2 "" H 7525 1725 50  0001 C CNN
F 3 "" H 7525 1725 50  0001 C CNN
	1    7525 1725
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5C00E6F3
P 7525 775
AR Path="/5AD5ACBB/5C00E6F3" Ref="#PWR?"  Part="1" 
AR Path="/5C00E6F3" Ref="#PWR?"  Part="1" 
AR Path="/5BD09509/5C00E6F3" Ref="#PWR?"  Part="1" 
AR Path="/5BD3A596/5C00E6F3" Ref="#PWR099"  Part="1" 
F 0 "#PWR099" H 7525 625 50  0001 C CNN
F 1 "+12V" H 7540 948 50  0000 C CNN
F 2 "" H 7525 775 50  0001 C CNN
F 3 "" H 7525 775 50  0001 C CNN
	1    7525 775 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7175 1075 7225 1075
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5C00E702
P 7725 1375
AR Path="/5AD5ACBB/5C00E702" Ref="J?"  Part="1" 
AR Path="/5C00E702" Ref="J?"  Part="1" 
AR Path="/5BD09509/5C00E702" Ref="J?"  Part="1" 
AR Path="/5BD3A596/5C00E702" Ref="J38"  Part="1" 
F 0 "J38" H 7805 1417 50  0000 L CNN
F 1 "PULSE OUT" H 7805 1326 50  0000 L CNN
F 2 "" H 7725 1375 50  0001 C CNN
F 3 "~" H 7725 1375 50  0001 C CNN
	1    7725 1375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5C010A38
P 7525 1575
AR Path="/5AD5ACBB/5C010A38" Ref="R?"  Part="1" 
AR Path="/5C010A38" Ref="R?"  Part="1" 
AR Path="/5BD09509/5C010A38" Ref="R?"  Part="1" 
AR Path="/5BD3A596/5C010A38" Ref="R52"  Part="1" 
F 0 "R52" V 7329 1575 50  0000 C CNN
F 1 "3K3" V 7420 1575 50  0000 C CNN
F 2 "" H 7525 1575 50  0001 C CNN
F 3 "" H 7525 1575 50  0001 C CNN
	1    7525 1575
	1    0    0    1   
$EndComp
Wire Wire Line
	7525 775  7525 875 
Wire Wire Line
	7525 1675 7525 1725
Text Notes 8315 910  0    197  ~ 0
output buffer x16\n
Wire Wire Line
	7525 1275 7525 1375
Wire Wire Line
	7525 1375 7525 1475
Connection ~ 7525 1375
Text Label 4225 2150 2    60   ~ 0
IN_1
Wire Wire Line
	4100 3425 4250 3425
Text Label 4100 3425 2    60   ~ 0
IN_2
Text Label 3875 4675 2    60   ~ 0
IN_3
Wire Wire Line
	3875 4675 4175 4675
Wire Wire Line
	4175 4675 4225 4675
Connection ~ 4175 4675
Wire Wire Line
	4175 5950 4075 5950
Connection ~ 4175 5950
Text Label 4075 5950 2    60   ~ 0
IN_4
Text Notes 1755 1080 0    197  ~ 0
each in with comparator or?
$EndSCHEMATC