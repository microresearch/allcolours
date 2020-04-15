EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 11
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1225 575  1900 850 
U 5BAC374C
F0 "Sheet5BAC374B" 60
F1 "ouroboros.sch" 60
$EndSheet
Text Notes 1525 1025 0    197  ~ 0
ouroboros\n
Text Notes 600  250  0    118  ~ 0
core of EARTH/OSC/NOISE\n- surrounded by mandalas of transistor, SR (in?) and out, and switched cap filter (clock in 4051, 4024)
$Sheet
S 900  5075 2250 600 
U 5BD09509
F0 "pulses and trans" 118
F1 "misc_trans.sch" 118
$EndSheet
$Sheet
S 1225 1825 1750 600 
U 5BD2D603
F0 "noiseandosc" 118
F1 "noiseandosc.sch" 118
$EndSheet
Text Notes 1875 2175 0    118  ~ 0
noise\n
Text Notes 1600 5425 0    118  ~ 0
pulses and trans\n
$Sheet
S 1025 2875 2200 600 
U 5BD3A596
F0 "shift register" 118
F1 "shiftreg.sch" 118
$EndSheet
Text Notes 1625 3225 0    118  ~ 0
shift reg\n
$Sheet
S 1075 3925 2100 500 
U 5BD3C927
F0 "switchedfilter" 118
F1 "switchedfilter.sch" 118
$EndSheet
Text Notes 1725 4225 0    118  ~ 0
filter\n
$Comp
L Amplifier_Operational:TL071 U1
U 1 1 5BD701E6
P 5425 4200
F 0 "U1" H 5766 4246 50  0000 L CNN
F 1 "TL071" H 5766 4155 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 5475 4250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5575 4350 50  0001 C CNN
	1    5425 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5BD701ED
P 4925 4300
F 0 "R1" V 5121 4300 50  0000 C CNN
F 1 "10K" V 5030 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4925 4300 50  0001 C CNN
F 3 "~" H 4925 4300 50  0001 C CNN
	1    4925 4300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R3
U 1 1 5BD701F4
P 5950 4200
F 0 "R3" V 5754 4200 50  0000 C CNN
F 1 "330R" V 5845 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5950 4200 50  0001 C CNN
F 3 "~" H 5950 4200 50  0001 C CNN
	1    5950 4200
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R2
U 1 1 5BD701FB
P 5450 5025
F 0 "R2" V 5254 5025 50  0000 C CNN
F 1 "10K" V 5345 5025 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5450 5025 50  0001 C CNN
F 3 "~" H 5450 5025 50  0001 C CNN
	1    5450 5025
	0    1    1    0   
$EndComp
$Comp
L power:-12V #PWR04
U 1 1 5BD70202
P 5325 4575
F 0 "#PWR04" H 5325 4675 50  0001 C CNN
F 1 "-12V" H 5340 4748 50  0000 C CNN
F 2 "" H 5325 4575 50  0001 C CNN
F 3 "" H 5325 4575 50  0001 C CNN
	1    5325 4575
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR03
U 1 1 5BD70208
P 5325 3850
F 0 "#PWR03" H 5325 3700 50  0001 C CNN
F 1 "+12V" H 5340 4023 50  0000 C CNN
F 2 "" H 5325 3850 50  0001 C CNN
F 3 "" H 5325 3850 50  0001 C CNN
	1    5325 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5325 3850 5325 3900
Wire Wire Line
	5325 4500 5325 4575
Wire Wire Line
	5025 4300 5125 4300
Wire Wire Line
	5050 4100 5125 4100
Wire Wire Line
	5725 4200 5800 4200
Connection ~ 5025 4300
$Comp
L power:GND #PWR02
U 1 1 5BD70220
P 4875 3950
F 0 "#PWR02" H 4875 3700 50  0001 C CNN
F 1 "GND" H 4880 3777 50  0000 C CNN
F 2 "" H 4875 3950 50  0001 C CNN
F 3 "" H 4875 3950 50  0001 C CNN
	1    4875 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 4100 5050 3950
Wire Wire Line
	5050 3950 4875 3950
Wire Wire Line
	5025 5025 5350 5025
Wire Wire Line
	5025 4300 5025 5025
Wire Wire Line
	4675 4300 4825 4300
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J2
U 1 1 5BD714DB
P 4275 4300
F 0 "J2" H 4195 4075 50  0000 C CNN
F 1 "MAIN OUT" H 4195 4166 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 4275 4300 50  0001 C CNN
F 3 "" H 4275 4300 50  0001 C CNN
	1    4275 4300
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:AUDIO-JACKERTHENVAR-erthenvar M2
U 1 1 5BD72004
P 6750 4400
F 0 "M2" H 6423 4362 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR-erthenvar" H 6750 4400 45  0001 L BNN
F 2 "erthenvar:ERTHENVAR-JACK" H 6780 4550 20  0001 C CNN
F 3 "" H 6750 4400 60  0001 C CNN
	1    6750 4400
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR05
U 1 1 5BD7215D
P 6425 4650
F 0 "#PWR05" H 6425 4400 50  0001 C CNN
F 1 "GND-power" H 6430 4477 50  0000 C CNN
F 2 "" H 6425 4650 50  0001 C CNN
F 3 "" H 6425 4650 50  0001 C CNN
	1    6425 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6425 4650 6425 4500
Wire Wire Line
	6425 4500 6450 4500
Text Notes 5800 3975 0    197  ~ 0
MAIN OUT
Text Notes 5125 1175 0    197  ~ 0
MAIN IN
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J1
U 1 1 5BD75EC5
P 7525 1525
F 0 "J1" H 7604 1567 50  0000 L CNN
F 1 "MAIN IN" H 7604 1476 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Square-SMD-Pad_Small" H 7525 1525 50  0001 C CNN
F 3 "" H 7525 1525 50  0001 C CNN
	1    7525 1525
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:AUDIO-JACKERTHENVAR-erthenvar M1
U 1 1 5BD75FEA
P 5375 1725
F 0 "M1" H 5381 1944 45  0000 C CNN
F 1 "AUDIO-JACKERTHENVAR-erthenvar" H 5375 1725 45  0001 L BNN
F 2 "erthenvar:ERTHENVAR-JACK" H 5405 1875 20  0001 C CNN
F 3 "" H 5375 1725 60  0001 C CNN
	1    5375 1725
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR01
U 1 1 5BD760AE
P 5800 1450
F 0 "#PWR01" H 5800 1200 50  0001 C CNN
F 1 "GND-power" H 5805 1277 50  0000 C CNN
F 2 "" H 5800 1450 50  0001 C CNN
F 3 "" H 5800 1450 50  0001 C CNN
	1    5800 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5675 1625 5675 1450
Wire Wire Line
	5675 1450 5800 1450
Wire Wire Line
	6050 4200 6450 4200
Wire Wire Line
	5550 5025 5800 5025
Wire Wire Line
	5800 5025 5800 4200
Connection ~ 5800 4200
Wire Wire Line
	5800 4200 5850 4200
$Comp
L allcolours_analogue-rescue:CP1_Small-device C2
U 1 1 5BD03889
P 4575 4300
F 0 "C2" H 4585 4370 50  0000 L CNN
F 1 "10u" H 4585 4220 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 4575 4300 50  0001 C CNN
F 3 "" H 4575 4300 50  0000 C CNN
	1    4575 4300
	0    -1   -1   0   
$EndComp
$Sheet
S 825  6225 2375 500 
U 5BD863C8
F0 "comparator" 60
F1 "comparator.sch" 60
$EndSheet
Text Notes 1500 6500 0    157  ~ 0
comp
$Comp
L allcolours_analogue-rescue:CP1_Small-device C1
U 1 1 5BD3569E
P 6075 1625
F 0 "C1" H 6085 1695 50  0000 L CNN
F 1 "10u" H 6085 1545 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 6075 1625 50  0001 C CNN
F 3 "" H 6075 1625 50  0000 C CNN
	1    6075 1625
	0    1    1    0   
$EndComp
Wire Wire Line
	5675 1925 5975 1925
Wire Wire Line
	5975 1925 5975 1625
Wire Wire Line
	6175 1625 6300 1625
$Sheet
S 1025 7050 1750 475 
U 5C04EB62
F0 "revealed comparator" 60
F1 "revealed.sch" 60
$EndSheet
Text Notes 1700 7475 0    157  ~ 0
revealed
$Sheet
S 3550 7025 1800 325 
U 5C0A69D0
F0 "sketching" 60
F1 "sketches.sch" 60
$EndSheet
Text Notes 4075 7275 0    118  ~ 0
sketches
$Comp
L Amplifier_Operational:TL071 U6
U 1 1 5C0972A8
P 6900 1525
F 0 "U6" H 7241 1571 50  0000 L CNN
F 1 "TL071" H 7241 1480 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 6950 1575 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 7050 1675 50  0001 C CNN
	1    6900 1525
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R12
U 1 1 5C0972AF
P 6400 1625
F 0 "R12" V 6596 1625 50  0000 C CNN
F 1 "10K" V 6505 1625 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6400 1625 50  0001 C CNN
F 3 "~" H 6400 1625 50  0001 C CNN
	1    6400 1625
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R17
U 1 1 5C0972BD
P 6925 2350
F 0 "R17" V 6729 2350 50  0000 C CNN
F 1 "10K" V 6820 2350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6925 2350 50  0001 C CNN
F 3 "~" H 6925 2350 50  0001 C CNN
	1    6925 2350
	0    1    1    0   
$EndComp
$Comp
L power:-12V #PWR014
U 1 1 5C0972C4
P 6800 1900
F 0 "#PWR014" H 6800 2000 50  0001 C CNN
F 1 "-12V" H 6815 2073 50  0000 C CNN
F 2 "" H 6800 1900 50  0001 C CNN
F 3 "" H 6800 1900 50  0001 C CNN
	1    6800 1900
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR010
U 1 1 5C0972CA
P 6800 1175
F 0 "#PWR010" H 6800 1025 50  0001 C CNN
F 1 "+12V" H 6815 1348 50  0000 C CNN
F 2 "" H 6800 1175 50  0001 C CNN
F 3 "" H 6800 1175 50  0001 C CNN
	1    6800 1175
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1175 6800 1225
Wire Wire Line
	6800 1825 6800 1900
Wire Wire Line
	6500 1625 6600 1625
Wire Wire Line
	6525 1425 6600 1425
Wire Wire Line
	7200 1525 7275 1525
Connection ~ 6500 1625
$Comp
L power:GND #PWR07
U 1 1 5C0972D6
P 6350 1275
F 0 "#PWR07" H 6350 1025 50  0001 C CNN
F 1 "GND" H 6355 1102 50  0000 C CNN
F 2 "" H 6350 1275 50  0001 C CNN
F 3 "" H 6350 1275 50  0001 C CNN
	1    6350 1275
	1    0    0    -1  
$EndComp
Wire Wire Line
	6525 1425 6525 1275
Wire Wire Line
	6525 1275 6350 1275
Wire Wire Line
	6500 2350 6825 2350
Wire Wire Line
	6500 1625 6500 2350
Wire Wire Line
	7025 2350 7275 2350
Wire Wire Line
	7275 2350 7275 1525
Connection ~ 7275 1525
Wire Wire Line
	7275 1525 7325 1525
$Sheet
S 8400 5375 1600 525 
U 5C3A9A19
F0 "eurorack_power" 60
F1 "eurorack_power.sch" 60
$EndSheet
Text Notes 6725 3225 0    157  ~ 0
check all transistor pins
$Sheet
S 8075 3950 2175 450 
U 5E97CA7E
F0 "flipflop" 60
F1 "flipflopagain.sch" 60
$EndSheet
$EndSCHEMATC
