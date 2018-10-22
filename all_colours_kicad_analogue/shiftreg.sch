EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
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
L 4xxx_IEEE:4015 U?
U 1 1 5BC8EBAC
P 4850 2150
F 0 "U?" H 4550 2525 50  0000 C CNN
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
L power:GND #PWR?
U 1 1 5BCE011A
P 4850 2475
F 0 "#PWR?" H 4850 2225 50  0001 C CNN
F 1 "GND" H 4855 2302 50  0000 C CNN
F 2 "" H 4850 2475 50  0001 C CNN
F 3 "" H 4850 2475 50  0001 C CNN
	1    4850 2475
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2400 4850 2475
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BCE01B6
P 4850 1850
F 0 "#PWR?" H 4850 1700 50  0001 C CNN
F 1 "+12V-power" H 4865 2023 50  0000 C CNN
F 2 "" H 4850 1850 50  0001 C CNN
F 3 "" H 4850 1850 50  0001 C CNN
	1    4850 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 1900 4850 1850
$Comp
L Device:C_Small C?
U 1 1 5BCE0223
P 5425 1600
F 0 "C?" H 5517 1646 50  0000 L CNN
F 1 "100N" H 5517 1555 50  0000 L CNN
F 2 "" H 5425 1600 50  0001 C CNN
F 3 "~" H 5425 1600 50  0001 C CNN
	1    5425 1600
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BCE0273
P 5425 1450
F 0 "#PWR?" H 5425 1300 50  0001 C CNN
F 1 "+12V-power" H 5440 1623 50  0000 C CNN
F 2 "" H 5425 1450 50  0001 C CNN
F 3 "" H 5425 1450 50  0001 C CNN
	1    5425 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE0282
P 5425 1750
F 0 "#PWR?" H 5425 1500 50  0001 C CNN
F 1 "GND" H 5430 1577 50  0000 C CNN
F 2 "" H 5425 1750 50  0001 C CNN
F 3 "" H 5425 1750 50  0001 C CNN
	1    5425 1750
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BCE0372
P 5450 2400
F 0 "R?" H 5509 2446 50  0000 L CNN
F 1 "10K" H 5509 2355 50  0000 L CNN
F 2 "" H 5450 2400 50  0001 C CNN
F 3 "" H 5450 2400 50  0001 C CNN
	1    5450 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5BCE03FF
P 5450 2650
F 0 "C?" H 5542 2696 50  0000 L CNN
F 1 "1N" H 5542 2605 50  0000 L CNN
F 2 "" H 5450 2650 50  0001 C CNN
F 3 "~" H 5450 2650 50  0001 C CNN
	1    5450 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE04B5
P 5450 2800
F 0 "#PWR?" H 5450 2550 50  0001 C CNN
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
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE0CAD
P 5700 2000
F 0 "J?" H 5780 2042 50  0000 L CNN
F 1 " " H 5780 1951 50  0000 L CNN
F 2 "" H 5700 2000 50  0001 C CNN
F 3 "" H 5700 2000 50  0001 C CNN
	1    5700 2000
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE0CFC
P 5700 2100
F 0 "J?" H 5780 2142 50  0000 L CNN
F 1 " " H 5780 2051 50  0000 L CNN
F 2 "" H 5700 2100 50  0001 C CNN
F 3 "" H 5700 2100 50  0001 C CNN
	1    5700 2100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE0D24
P 5700 2200
F 0 "J?" H 5780 2242 50  0000 L CNN
F 1 " " H 5780 2151 50  0000 L CNN
F 2 "" H 5700 2200 50  0001 C CNN
F 3 "" H 5700 2200 50  0001 C CNN
	1    5700 2200
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE0D46
P 5700 2300
F 0 "J?" H 5780 2342 50  0000 L CNN
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
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BCE1590
P 4125 2150
F 0 "R?" V 4225 2150 50  0000 C CNN
F 1 "1K" V 4020 2150 50  0000 C CNN
F 2 "" H 4125 2150 50  0001 C CNN
F 3 "" H 4125 2150 50  0001 C CNN
	1    4125 2150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE1696
P 4250 2300
F 0 "#PWR?" H 4250 2050 50  0001 C CNN
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
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE17C5
P 3775 2150
F 0 "J?" H 3775 2075 50  0000 C CNN
F 1 " " H 3695 2016 50  0000 C CNN
F 2 "" H 3775 2150 50  0001 C CNN
F 3 "" H 3775 2150 50  0001 C CNN
	1    3775 2150
	-1   0    0    1   
$EndComp
Wire Wire Line
	3975 2150 4025 2150
Wire Wire Line
	5425 1500 5425 1450
Wire Wire Line
	5425 1750 5425 1700
$Comp
L 4xxx_IEEE:4015 U?
U 2 1 5BCE34F1
P 4850 3425
F 0 "U?" H 4550 3800 50  0000 C CNN
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
L power:GND #PWR?
U 1 1 5BCE34F9
P 4850 3750
F 0 "#PWR?" H 4850 3500 50  0001 C CNN
F 1 "GND" H 4855 3577 50  0000 C CNN
F 2 "" H 4850 3750 50  0001 C CNN
F 3 "" H 4850 3750 50  0001 C CNN
	1    4850 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3675 4850 3750
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BCE3500
P 4850 3125
F 0 "#PWR?" H 4850 2975 50  0001 C CNN
F 1 "+12V-power" H 4865 3298 50  0000 C CNN
F 2 "" H 4850 3125 50  0001 C CNN
F 3 "" H 4850 3125 50  0001 C CNN
	1    4850 3125
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3175 4850 3125
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BCE3507
P 5450 3675
F 0 "R?" H 5509 3721 50  0000 L CNN
F 1 "10K" H 5509 3630 50  0000 L CNN
F 2 "" H 5450 3675 50  0001 C CNN
F 3 "" H 5450 3675 50  0001 C CNN
	1    5450 3675
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5BCE350D
P 5450 3925
F 0 "C?" H 5542 3971 50  0000 L CNN
F 1 "1N" H 5542 3880 50  0000 L CNN
F 2 "" H 5450 3925 50  0001 C CNN
F 3 "~" H 5450 3925 50  0001 C CNN
	1    5450 3925
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE3513
P 5450 4075
F 0 "#PWR?" H 5450 3825 50  0001 C CNN
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
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE351C
P 5700 3275
F 0 "J?" H 5780 3317 50  0000 L CNN
F 1 " " H 5780 3226 50  0000 L CNN
F 2 "" H 5700 3275 50  0001 C CNN
F 3 "" H 5700 3275 50  0001 C CNN
	1    5700 3275
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE3522
P 5700 3375
F 0 "J?" H 5780 3417 50  0000 L CNN
F 1 " " H 5780 3326 50  0000 L CNN
F 2 "" H 5700 3375 50  0001 C CNN
F 3 "" H 5700 3375 50  0001 C CNN
	1    5700 3375
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE3528
P 5700 3475
F 0 "J?" H 5780 3517 50  0000 L CNN
F 1 " " H 5780 3426 50  0000 L CNN
F 2 "" H 5700 3475 50  0001 C CNN
F 3 "" H 5700 3475 50  0001 C CNN
	1    5700 3475
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE352E
P 5700 3575
F 0 "J?" H 5780 3617 50  0000 L CNN
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
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BCE3539
P 4125 3425
F 0 "R?" V 4225 3425 50  0000 C CNN
F 1 "1K" V 4020 3425 50  0000 C CNN
F 2 "" H 4125 3425 50  0001 C CNN
F 3 "" H 4125 3425 50  0001 C CNN
	1    4125 3425
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE353F
P 4250 3575
F 0 "#PWR?" H 4250 3325 50  0001 C CNN
F 1 "GND" H 4255 3402 50  0000 C CNN
F 2 "" H 4250 3575 50  0001 C CNN
F 3 "" H 4250 3575 50  0001 C CNN
	1    4250 3575
	1    0    0    -1  
$EndComp
Wire Wire Line
	4225 3425 4250 3425
Wire Wire Line
	4250 3575 4300 3575
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE3547
P 3775 3425
F 0 "J?" H 3775 3350 50  0000 C CNN
F 1 " " H 3695 3291 50  0000 C CNN
F 2 "" H 3775 3425 50  0001 C CNN
F 3 "" H 3775 3425 50  0001 C CNN
	1    3775 3425
	-1   0    0    1   
$EndComp
Wire Wire Line
	3975 3425 4025 3425
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
L 4xxx_IEEE:4015 U?
U 1 1 5BCE5AB3
P 4775 4675
F 0 "U?" H 4475 5050 50  0000 C CNN
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
L power:GND #PWR?
U 1 1 5BCE5ABB
P 4775 5000
F 0 "#PWR?" H 4775 4750 50  0001 C CNN
F 1 "GND" H 4780 4827 50  0000 C CNN
F 2 "" H 4775 5000 50  0001 C CNN
F 3 "" H 4775 5000 50  0001 C CNN
	1    4775 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4775 4925 4775 5000
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BCE5AC2
P 4775 4375
F 0 "#PWR?" H 4775 4225 50  0001 C CNN
F 1 "+12V-power" H 4790 4548 50  0000 C CNN
F 2 "" H 4775 4375 50  0001 C CNN
F 3 "" H 4775 4375 50  0001 C CNN
	1    4775 4375
	1    0    0    -1  
$EndComp
Wire Wire Line
	4775 4425 4775 4375
$Comp
L Device:C_Small C?
U 1 1 5BCE5AC9
P 6575 5350
F 0 "C?" H 6667 5396 50  0000 L CNN
F 1 "100N" H 6667 5305 50  0000 L CNN
F 2 "" H 6575 5350 50  0001 C CNN
F 3 "~" H 6575 5350 50  0001 C CNN
	1    6575 5350
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BCE5ACF
P 6575 5200
F 0 "#PWR?" H 6575 5050 50  0001 C CNN
F 1 "+12V-power" H 6590 5373 50  0000 C CNN
F 2 "" H 6575 5200 50  0001 C CNN
F 3 "" H 6575 5200 50  0001 C CNN
	1    6575 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE5AD5
P 6575 5500
F 0 "#PWR?" H 6575 5250 50  0001 C CNN
F 1 "GND" H 6580 5327 50  0000 C CNN
F 2 "" H 6575 5500 50  0001 C CNN
F 3 "" H 6575 5500 50  0001 C CNN
	1    6575 5500
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BCE5ADB
P 5375 4925
F 0 "R?" H 5434 4971 50  0000 L CNN
F 1 "10K" H 5434 4880 50  0000 L CNN
F 2 "" H 5375 4925 50  0001 C CNN
F 3 "" H 5375 4925 50  0001 C CNN
	1    5375 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5BCE5AE1
P 5375 5175
F 0 "C?" H 5467 5221 50  0000 L CNN
F 1 "1N" H 5467 5130 50  0000 L CNN
F 2 "" H 5375 5175 50  0001 C CNN
F 3 "~" H 5375 5175 50  0001 C CNN
	1    5375 5175
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE5AE7
P 5375 5325
F 0 "#PWR?" H 5375 5075 50  0001 C CNN
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
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5AF0
P 5625 4525
F 0 "J?" H 5705 4567 50  0000 L CNN
F 1 " " H 5705 4476 50  0000 L CNN
F 2 "" H 5625 4525 50  0001 C CNN
F 3 "" H 5625 4525 50  0001 C CNN
	1    5625 4525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5AF6
P 5625 4625
F 0 "J?" H 5705 4667 50  0000 L CNN
F 1 " " H 5705 4576 50  0000 L CNN
F 2 "" H 5625 4625 50  0001 C CNN
F 3 "" H 5625 4625 50  0001 C CNN
	1    5625 4625
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5AFC
P 5625 4725
F 0 "J?" H 5705 4767 50  0000 L CNN
F 1 " " H 5705 4676 50  0000 L CNN
F 2 "" H 5625 4725 50  0001 C CNN
F 3 "" H 5625 4725 50  0001 C CNN
	1    5625 4725
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5B02
P 5625 4825
F 0 "J?" H 5705 4867 50  0000 L CNN
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
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BCE5B0D
P 4050 4675
F 0 "R?" V 4150 4675 50  0000 C CNN
F 1 "1K" V 3945 4675 50  0000 C CNN
F 2 "" H 4050 4675 50  0001 C CNN
F 3 "" H 4050 4675 50  0001 C CNN
	1    4050 4675
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE5B13
P 4175 4825
F 0 "#PWR?" H 4175 4575 50  0001 C CNN
F 1 "GND" H 4180 4652 50  0000 C CNN
F 2 "" H 4175 4825 50  0001 C CNN
F 3 "" H 4175 4825 50  0001 C CNN
	1    4175 4825
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 4675 4175 4675
Wire Wire Line
	4175 4825 4225 4825
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5B1B
P 3700 4675
F 0 "J?" H 3700 4600 50  0000 C CNN
F 1 " " H 3620 4541 50  0000 C CNN
F 2 "" H 3700 4675 50  0001 C CNN
F 3 "" H 3700 4675 50  0001 C CNN
	1    3700 4675
	-1   0    0    1   
$EndComp
Wire Wire Line
	3900 4675 3950 4675
Wire Wire Line
	6575 5250 6575 5200
Wire Wire Line
	6575 5500 6575 5450
$Comp
L 4xxx_IEEE:4015 U?
U 2 1 5BCE5B24
P 4775 5950
F 0 "U?" H 4475 6325 50  0000 C CNN
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
L power:GND #PWR?
U 1 1 5BCE5B2C
P 4775 6275
F 0 "#PWR?" H 4775 6025 50  0001 C CNN
F 1 "GND" H 4780 6102 50  0000 C CNN
F 2 "" H 4775 6275 50  0001 C CNN
F 3 "" H 4775 6275 50  0001 C CNN
	1    4775 6275
	1    0    0    -1  
$EndComp
Wire Wire Line
	4775 6200 4775 6275
$Comp
L allcolours_analogue-rescue:+12V-power #PWR?
U 1 1 5BCE5B33
P 4775 5650
F 0 "#PWR?" H 4775 5500 50  0001 C CNN
F 1 "+12V-power" H 4790 5823 50  0000 C CNN
F 2 "" H 4775 5650 50  0001 C CNN
F 3 "" H 4775 5650 50  0001 C CNN
	1    4775 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4775 5700 4775 5650
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5B4F
P 5625 5800
F 0 "J?" H 5705 5842 50  0000 L CNN
F 1 " " H 5705 5751 50  0000 L CNN
F 2 "" H 5625 5800 50  0001 C CNN
F 3 "" H 5625 5800 50  0001 C CNN
	1    5625 5800
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5B55
P 5625 5900
F 0 "J?" H 5705 5942 50  0000 L CNN
F 1 " " H 5705 5851 50  0000 L CNN
F 2 "" H 5625 5900 50  0001 C CNN
F 3 "" H 5625 5900 50  0001 C CNN
	1    5625 5900
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5B5B
P 5625 6000
F 0 "J?" H 5705 6042 50  0000 L CNN
F 1 " " H 5705 5951 50  0000 L CNN
F 2 "" H 5625 6000 50  0001 C CNN
F 3 "" H 5625 6000 50  0001 C CNN
	1    5625 6000
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5B61
P 5625 6100
F 0 "J?" H 5705 6142 50  0000 L CNN
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
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BCE5B6C
P 4050 5950
F 0 "R?" V 4150 5950 50  0000 C CNN
F 1 "1K" V 3945 5950 50  0000 C CNN
F 2 "" H 4050 5950 50  0001 C CNN
F 3 "" H 4050 5950 50  0001 C CNN
	1    4050 5950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCE5B72
P 4175 6100
F 0 "#PWR?" H 4175 5850 50  0001 C CNN
F 1 "GND" H 4180 5927 50  0000 C CNN
F 2 "" H 4175 6100 50  0001 C CNN
F 3 "" H 4175 6100 50  0001 C CNN
	1    4175 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 5950 4175 5950
Wire Wire Line
	4175 6100 4225 6100
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J?
U 1 1 5BCE5B7A
P 3700 5950
F 0 "J?" H 3700 5875 50  0000 C CNN
F 1 " " H 3620 5816 50  0000 C CNN
F 2 "" H 3700 5950 50  0001 C CNN
F 3 "" H 3700 5950 50  0001 C CNN
	1    3700 5950
	-1   0    0    1   
$EndComp
Wire Wire Line
	3900 5950 3950 5950
Wire Wire Line
	4175 5200 5075 5200
Wire Wire Line
	5075 5200 5075 5050
Wire Wire Line
	5075 5050 5375 5050
Wire Wire Line
	4175 5200 4175 5950
Connection ~ 4175 5950
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
Connection ~ 4175 4675
Wire Wire Line
	4175 4675 4225 4675
Connection ~ 5450 3825
Wire Wire Line
	5375 6600 5375 6550
Wire Wire Line
	5375 6350 5375 6300
$Comp
L power:GND #PWR?
U 1 1 5BCE5B46
P 5375 6600
F 0 "#PWR?" H 5375 6350 50  0001 C CNN
F 1 "GND" H 5380 6427 50  0000 C CNN
F 2 "" H 5375 6600 50  0001 C CNN
F 3 "" H 5375 6600 50  0001 C CNN
	1    5375 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5BCE5B40
P 5375 6450
F 0 "C?" H 5467 6496 50  0000 L CNN
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
L allcolours_analogue-rescue:R_Small-device R?
U 1 1 5BCE5B3A
P 5375 6200
F 0 "R?" H 5434 6246 50  0000 L CNN
F 1 "10K" H 5434 6155 50  0000 L CNN
F 2 "" H 5375 6200 50  0001 C CNN
F 3 "" H 5375 6200 50  0001 C CNN
	1    5375 6200
	1    0    0    -1  
$EndComp
Text Notes 1875 4175 0    60   ~ 0
comparator for clock in?!
$EndSCHEMATC
