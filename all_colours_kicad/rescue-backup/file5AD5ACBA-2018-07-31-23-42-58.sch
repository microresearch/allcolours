EESchema Schematic File Version 2
LIBS:allcolours-rescue
LIBS:power
LIBS:device
LIBS:linear
LIBS:regul
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:all_colours
LIBS:erthenvar
LIBS:MAX7490
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L ATMEGA168A-AU U?
U 1 1 5AD5C1D5
P 3200 2500
F 0 "U?" H 3250 3867 50  0000 C CNN
F 1 "ATMEGA168A-AU" H 3250 3776 50  0000 C CNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 3200 2500 50  0001 C CIN
F 3 "" H 3200 2500 50  0001 C CNN
	1    3200 2500
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y?
U 1 1 5AD5C1D8
P 4400 2050
F 0 "Y?" V 4354 2181 50  0000 L CNN
F 1 "16 MHz" V 4400 2000 50  0000 L CNN
F 2 "Crystals:Crystal_SMD_HC49-SD_HandSoldering" H 4400 2050 50  0001 C CNN
F 3 "" H 4400 2050 50  0001 C CNN
	1    4400 2050
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5AD5C1D9
P 4750 1900
F 0 "C?" V 4498 1900 50  0000 C CNN
F 1 "22pf" V 4589 1900 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4788 1750 50  0001 C CNN
F 3 "" H 4750 1900 50  0001 C CNN
	1    4750 1900
	0    1    1    0   
$EndComp
$Comp
L R_Small R?
U 1 1 5AD5C1DC
P 4450 2850
F 0 "R?" V 4254 2850 50  0000 C CNN
F 1 "10K" V 4345 2850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 4450 2850 50  0001 C CNN
F 3 "" H 4450 2850 50  0001 C CNN
	1    4450 2850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5AD5C1DD
P 5200 1800
F 0 "#PWR?" H 5200 1550 50  0001 C CNN
F 1 "GND" H 5200 1800 50  0000 C CNN
F 2 "" H 5200 1800 50  0001 C CNN
F 3 "" H 5200 1800 50  0001 C CNN
	1    5200 1800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5AD5C1DE
P 4700 2800
F 0 "#PWR?" H 4700 2650 50  0001 C CNN
F 1 "+5V" H 4715 2973 50  0000 C CNN
F 2 "" H 4700 2800 50  0001 C CNN
F 3 "" H 4700 2800 50  0001 C CNN
	1    4700 2800
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5AD5C1DF
P 4750 2200
F 0 "C?" V 4498 2200 50  0000 C CNN
F 1 "22pf" V 4589 2200 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4788 2050 50  0001 C CNN
F 3 "" H 4750 2200 50  0001 C CNN
	1    4750 2200
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR?
U 1 1 5AD5C1E2
P 1900 1400
F 0 "#PWR?" H 1900 1250 50  0001 C CNN
F 1 "+5V" H 1915 1573 50  0000 C CNN
F 2 "" H 1900 1400 50  0001 C CNN
F 3 "" H 1900 1400 50  0001 C CNN
	1    1900 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5AD5C1E3
P 1900 3650
F 0 "#PWR?" H 1900 3400 50  0001 C CNN
F 1 "GND" H 1905 3477 50  0000 C CNN
F 2 "" H 1900 3650 50  0001 C CNN
F 3 "" H 1900 3650 50  0001 C CNN
	1    1900 3650
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5AD5C1E4
P 2000 1900
F 0 "C?" V 1748 1900 50  0000 C CNN
F 1 "100N" V 1839 1900 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2038 1750 50  0001 C CNN
F 3 "" H 2000 1900 50  0001 C CNN
	1    2000 1900
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 5AD5C1E5
P 1800 1650
F 0 "C?" V 1548 1650 50  0000 C CNN
F 1 "100N" V 1639 1650 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1838 1500 50  0001 C CNN
F 3 "" H 1800 1650 50  0001 C CNN
	1    1800 1650
	-1   0    0    1   
$EndComp
Text Label 4400 2450 0    60   ~ 0
ADC1
Text Label 4650 2350 0    60   ~ 0
ADC0
$Comp
L CONN_01X06 J?
U 1 1 5AD5C290
P 5500 2150
F 0 "J?" H 5578 2191 50  0000 L CNN
F 1 "PROGRAM" H 5578 2100 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 5500 2150 50  0001 C CNN
F 3 "" H 5500 2150 50  0001 C CNN
	1    5500 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5AD5C291
P 5000 2300
F 0 "#PWR?" H 5000 2050 50  0001 C CNN
F 1 "GND" H 5000 2300 50  0000 C CNN
F 2 "" H 5000 2300 50  0001 C CNN
F 3 "" H 5000 2300 50  0001 C CNN
	1    5000 2300
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5AD5C292
P 2250 2300
F 0 "C?" V 1998 2300 50  0000 C CNN
F 1 "100N" V 2089 2300 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2288 2150 50  0001 C CNN
F 3 "" H 2250 2300 50  0001 C CNN
	1    2250 2300
	-1   0    0    1   
$EndComp
Text Notes 1650 2600 0    60   ~ 0
added aref cap
Text Label 4300 2550 0    60   ~ 0
ADC2
$Comp
L +5V #PWR?
U 1 1 5AD5C297
P 5200 2550
F 0 "#PWR?" H 5200 2400 50  0001 C CNN
F 1 "+5V" H 5215 2723 50  0000 C CNN
F 2 "" H 5200 2550 50  0001 C CNN
F 3 "" H 5200 2550 50  0001 C CNN
	1    5200 2550
	1    0    0    -1  
$EndComp
Text Notes 5250 2750 0    60   ~ 0
- added +5v on programming connection
Wire Wire Line
	4200 2000 4250 2000
Wire Wire Line
	4250 2000 4250 1950
Wire Wire Line
	4250 1950 4350 1950
Wire Wire Line
	4350 1950 4350 1900
Wire Wire Line
	4350 1900 4600 1900
Wire Wire Line
	4200 2100 4250 2100
Wire Wire Line
	4250 2100 4250 2200
Wire Wire Line
	4250 2200 4600 2200
Connection ~ 4400 1900
Connection ~ 4400 2200
Wire Wire Line
	4900 2200 4900 1900
Wire Wire Line
	4200 2850 4350 2850
Wire Wire Line
	4550 2850 4700 2850
Wire Wire Line
	4700 2850 4700 2800
Connection ~ 2150 1400
Wire Wire Line
	1500 1700 2300 1700
Connection ~ 2150 1500
Connection ~ 2150 1700
Wire Wire Line
	1900 2350 1900 3650
Wire Wire Line
	1900 3500 2300 3500
Wire Wire Line
	1900 3600 2300 3600
Connection ~ 1900 3600
Wire Wire Line
	2100 3600 2100 3700
Wire Wire Line
	2100 3700 2300 3700
Connection ~ 2100 3600
Wire Wire Line
	4200 1900 4200 1850
Wire Wire Line
	5300 2100 5100 2100
Wire Wire Line
	5100 2100 5100 1800
Wire Wire Line
	5100 1800 4200 1800
Wire Wire Line
	4950 2200 5300 2200
Wire Wire Line
	2000 1750 2000 1700
Connection ~ 1900 3500
Wire Wire Line
	2000 2350 2000 2050
Connection ~ 2000 2350
Wire Wire Line
	1800 1800 1800 2350
Connection ~ 1900 2350
Wire Wire Line
	4200 2350 4400 2350
Wire Wire Line
	4400 2350 4400 2450
Wire Wire Line
	4200 2250 4650 2250
Wire Wire Line
	4650 2250 4650 2350
Wire Wire Line
	4950 2200 4950 1750
Wire Wire Line
	4950 1750 4350 1750
Wire Wire Line
	4350 1750 4350 1700
Connection ~ 4350 1700
Wire Wire Line
	1500 1400 2300 1400
Wire Wire Line
	1800 2350 2000 2350
Wire Wire Line
	1800 1500 2300 1500
Connection ~ 4300 2850
Wire Wire Line
	5300 2000 5000 2000
Wire Wire Line
	5000 2000 5000 1850
Wire Wire Line
	5000 1850 4200 1850
Wire Wire Line
	5300 1900 5300 1750
Wire Wire Line
	5300 1750 5200 1750
Wire Wire Line
	5200 1750 5200 1800
Wire Wire Line
	4900 2050 5000 2050
Wire Wire Line
	5000 2050 5000 2300
Connection ~ 4900 2050
Wire Wire Line
	2300 2000 2250 2000
Wire Wire Line
	2250 2000 2250 2150
Wire Wire Line
	1900 2450 2250 2450
Connection ~ 1900 2450
Wire Wire Line
	4200 2450 4300 2450
Wire Wire Line
	4300 2450 4300 2550
Wire Wire Line
	5300 2300 5100 2300
Wire Wire Line
	5100 2300 5100 3050
Wire Wire Line
	5100 3050 4300 3050
Wire Wire Line
	4300 3050 4300 2850
Wire Wire Line
	5200 2550 5300 2550
Wire Wire Line
	5300 2550 5300 2400
$Comp
L L L?
U 1 1 5AD5DF93
P 1500 1550
F 0 "L?" H 1553 1596 50  0000 L CNN
F 1 "L" H 1553 1505 50  0000 L CNN
F 2 "" H 1500 1550 50  0001 C CNN
F 3 "" H 1500 1550 50  0001 C CNN
	1    1500 1550
	1    0    0    -1  
$EndComp
Connection ~ 1900 1400
Connection ~ 2000 1700
Wire Wire Line
	4350 1700 4200 1700
Wire Wire Line
	4200 1500 4400 1500
Text Label 4400 1500 0    60   ~ 0
PWM_OUT
Text Notes 4850 1500 0    60   ~ 0
buffer out?
Text Notes 4800 3600 0    118  ~ 0
TODO: pulse input, 16 pulse outs
$EndSCHEMATC