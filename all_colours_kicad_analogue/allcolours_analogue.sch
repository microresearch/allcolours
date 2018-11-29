EESchema Schematic File Version 4
LIBS:allcolours_analogue-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 8
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
L allcolours_analogue-rescue:7805-allcolours-rescue U9
U 1 1 5968B83B
P 10200 1200
F 0 "U9" H 10350 1004 50  0000 C CNN
F 1 "7805" H 10200 1400 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 10200 1200 50  0001 C CNN
F 3 "" H 10200 1200 50  0000 C CNN
	1    10200 1200
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR041
U 1 1 5968B92C
P 9600 1100
F 0 "#PWR041" H 9600 950 50  0001 C CNN
F 1 "+12V" H 9600 1240 50  0000 C CNN
F 2 "" H 9600 1100 50  0000 C CNN
F 3 "" H 9600 1100 50  0000 C CNN
	1    9600 1100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR045
U 1 1 5968B9D9
P 10200 1550
F 0 "#PWR045" H 10200 1300 50  0001 C CNN
F 1 "GND" H 10200 1400 50  0000 C CNN
F 2 "" H 10200 1550 50  0000 C CNN
F 3 "" H 10200 1550 50  0000 C CNN
	1    10200 1550
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C12
U 1 1 5968BE3D
P 9800 1300
F 0 "C12" H 9825 1400 50  0000 L CNN
F 1 "100N" H 9825 1200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 9838 1150 50  0001 C CNN
F 3 "" H 9800 1300 50  0000 C CNN
	1    9800 1300
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:CP1_Small-device C13
U 1 1 5968BF2C
P 9800 1600
F 0 "C13" H 9810 1670 50  0000 L CNN
F 1 "10u" H 9810 1520 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 9800 1600 50  0001 C CNN
F 3 "" H 9800 1600 50  0000 C CNN
	1    9800 1600
	0    -1   -1   0   
$EndComp
$Comp
L allcolours_analogue-rescue:C-device C15
U 1 1 5968C026
P 10650 1300
F 0 "C15" H 10675 1400 50  0000 L CNN
F 1 "100N" H 10675 1200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 10688 1150 50  0001 C CNN
F 3 "" H 10650 1300 50  0000 C CNN
	1    10650 1300
	0    1    1    0   
$EndComp
$Comp
L allcolours_analogue-rescue:CP1_Small-device C14
U 1 1 5968C101
P 10450 1500
F 0 "C14" H 10460 1570 50  0000 L CNN
F 1 "10u" H 10460 1420 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 10450 1500 50  0001 C CNN
F 3 "" H 10450 1500 50  0000 C CNN
	1    10450 1500
	0    1    1    0   
$EndComp
Text Notes 8550 1000 0    60   ~ 0
euro_conn
$Comp
L allcolours_analogue-rescue:CONN_02X05-allcolours-rescue P4
U 1 1 596B8735
P 8750 1350
F 0 "P4" H 8750 1650 50  0000 C CNN
F 1 "CONN_02X05" H 8750 1050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05_Pitch2.54mm" H 8750 150 50  0001 C CNN
F 3 "" H 8750 150 50  0000 C CNN
	1    8750 1350
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:+12V-power #PWR043
U 1 1 596B9C7E
P 8350 1100
F 0 "#PWR043" H 8350 950 50  0001 C CNN
F 1 "+12V" H 8350 1240 50  0000 C CNN
F 2 "" H 8350 1100 50  0000 C CNN
F 3 "" H 8350 1100 50  0000 C CNN
	1    8350 1100
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:-12VA-power #PWR044
U 1 1 596BB6E9
P 8400 1600
F 0 "#PWR044" H 8400 1450 50  0001 C CNN
F 1 "-12VA" H 8400 1740 50  0000 C CNN
F 2 "" H 8400 1600 50  0000 C CNN
F 3 "" H 8400 1600 50  0000 C CNN
	1    8400 1600
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR047
U 1 1 596A64CD
P 9200 1350
F 0 "#PWR047" H 9200 1100 50  0001 C CNN
F 1 "GND" H 9200 1200 50  0000 C CNN
F 2 "" H 9200 1350 50  0000 C CNN
F 3 "" H 9200 1350 50  0000 C CNN
	1    9200 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 1150 9650 1150
Wire Wire Line
	9600 1150 9600 1100
Wire Wire Line
	10200 1450 10200 1500
Wire Wire Line
	10600 1150 10800 1150
Wire Wire Line
	9650 1150 9650 1300
Connection ~ 9650 1150
Wire Wire Line
	9650 1600 9700 1600
Connection ~ 9650 1300
Wire Wire Line
	9950 1600 9900 1600
Wire Wire Line
	9950 1300 9950 1500
Wire Wire Line
	9950 1500 10200 1500
Connection ~ 10200 1500
Connection ~ 9950 1500
Wire Wire Line
	10300 1500 10300 1300
Wire Wire Line
	10300 1300 10500 1300
Connection ~ 10300 1500
Wire Wire Line
	10800 1500 10550 1500
Wire Wire Line
	10800 1150 10800 1300
Connection ~ 10800 1300
Wire Wire Line
	8500 1250 8500 1350
Connection ~ 8500 1350
Wire Wire Line
	8500 1350 9000 1350
Wire Wire Line
	9000 1250 9000 1350
Connection ~ 9000 1350
Wire Wire Line
	8500 1150 9000 1150
Wire Wire Line
	8400 1550 8500 1550
Wire Wire Line
	8350 1100 8500 1100
Wire Wire Line
	8500 1100 8500 1150
Wire Wire Line
	8400 1600 8400 1550
Connection ~ 8500 1550
Wire Wire Line
	9650 1150 9750 1150
Wire Wire Line
	9650 1300 9650 1600
Wire Wire Line
	10200 1500 10200 1550
Wire Wire Line
	10200 1500 10300 1500
Wire Wire Line
	9950 1500 9950 1600
Wire Wire Line
	10300 1500 10350 1500
Wire Wire Line
	10800 1300 10800 1500
Wire Wire Line
	8500 1350 8500 1450
Wire Wire Line
	9000 1350 9150 1350
Wire Wire Line
	9000 1350 9000 1450
Wire Wire Line
	8500 1550 9000 1550
$Comp
L allcolours_analogue-rescue:PWR_FLAG-power #FLG02
U 1 1 5B6F6A22
P 9750 1000
F 0 "#FLG02" H 9750 1075 50  0001 C CNN
F 1 "PWR_FLAG" H 9750 1174 50  0000 C CNN
F 2 "" H 9750 1000 50  0001 C CNN
F 3 "" H 9750 1000 50  0001 C CNN
	1    9750 1000
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:PWR_FLAG-power #FLG01
U 1 1 5B6F6BB5
P 9150 1200
F 0 "#FLG01" H 9150 1275 50  0001 C CNN
F 1 "PWR_FLAG" H 9150 1374 50  0000 C CNN
F 2 "" H 9150 1200 50  0001 C CNN
F 3 "" H 9150 1200 50  0001 C CNN
	1    9150 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 1350 9150 1200
Connection ~ 9150 1350
Wire Wire Line
	9150 1350 9200 1350
Wire Wire Line
	9750 1150 9750 1000
Connection ~ 9750 1150
Wire Wire Line
	9750 1150 9800 1150
$Comp
L allcolours_analogue-rescue:+5V-power #PWR062
U 1 1 5B726638
P 10900 1100
F 0 "#PWR062" H 10900 950 50  0001 C CNN
F 1 "+5V" H 10915 1273 50  0000 C CNN
F 2 "" H 10900 1100 50  0001 C CNN
F 3 "" H 10900 1100 50  0001 C CNN
	1    10900 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10800 1150 10900 1150
Wire Wire Line
	10900 1150 10900 1100
Connection ~ 10800 1150
Connection ~ 8500 1150
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
P 9150 3150
F 0 "U1" H 9491 3196 50  0000 L CNN
F 1 "TL071" H 9491 3105 50  0000 L CNN
F 2 "" H 9200 3200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9300 3300 50  0001 C CNN
	1    9150 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5BD701ED
P 8650 3250
F 0 "R1" V 8846 3250 50  0000 C CNN
F 1 "10K" V 8755 3250 50  0000 C CNN
F 2 "" H 8650 3250 50  0001 C CNN
F 3 "~" H 8650 3250 50  0001 C CNN
	1    8650 3250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R3
U 1 1 5BD701F4
P 9675 3150
F 0 "R3" V 9479 3150 50  0000 C CNN
F 1 "330R" V 9570 3150 50  0000 C CNN
F 2 "" H 9675 3150 50  0001 C CNN
F 3 "~" H 9675 3150 50  0001 C CNN
	1    9675 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R2
U 1 1 5BD701FB
P 9175 3975
F 0 "R2" V 8979 3975 50  0000 C CNN
F 1 "10K" V 9070 3975 50  0000 C CNN
F 2 "" H 9175 3975 50  0001 C CNN
F 3 "~" H 9175 3975 50  0001 C CNN
	1    9175 3975
	0    1    1    0   
$EndComp
$Comp
L power:-12V #PWR04
U 1 1 5BD70202
P 9050 3525
F 0 "#PWR04" H 9050 3625 50  0001 C CNN
F 1 "-12V" H 9065 3698 50  0000 C CNN
F 2 "" H 9050 3525 50  0001 C CNN
F 3 "" H 9050 3525 50  0001 C CNN
	1    9050 3525
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR03
U 1 1 5BD70208
P 9050 2800
F 0 "#PWR03" H 9050 2650 50  0001 C CNN
F 1 "+12V" H 9065 2973 50  0000 C CNN
F 2 "" H 9050 2800 50  0001 C CNN
F 3 "" H 9050 2800 50  0001 C CNN
	1    9050 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 2800 9050 2850
Wire Wire Line
	9050 3450 9050 3525
Wire Wire Line
	8750 3250 8850 3250
Wire Wire Line
	8775 3050 8850 3050
Wire Wire Line
	9450 3150 9525 3150
Connection ~ 8750 3250
$Comp
L power:GND #PWR02
U 1 1 5BD70220
P 8600 2900
F 0 "#PWR02" H 8600 2650 50  0001 C CNN
F 1 "GND" H 8605 2727 50  0000 C CNN
F 2 "" H 8600 2900 50  0001 C CNN
F 3 "" H 8600 2900 50  0001 C CNN
	1    8600 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8775 3050 8775 2900
Wire Wire Line
	8775 2900 8600 2900
Wire Wire Line
	8750 3975 9075 3975
Wire Wire Line
	8750 3250 8750 3975
Wire Wire Line
	8400 3250 8550 3250
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J2
U 1 1 5BD714DB
P 8000 3250
F 0 "J2" H 7920 3025 50  0000 C CNN
F 1 "MAIN OUT" H 7920 3116 50  0000 C CNN
F 2 "" H 8000 3250 50  0001 C CNN
F 3 "" H 8000 3250 50  0001 C CNN
	1    8000 3250
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:AUDIO-JACKERTHENVAR-erthenvar M2
U 1 1 5BD72004
P 10475 3350
F 0 "M2" H 10148 3312 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR-erthenvar" H 10475 3350 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 10505 3500 20  0001 C CNN
F 3 "" H 10475 3350 60  0001 C CNN
	1    10475 3350
	-1   0    0    1   
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR05
U 1 1 5BD7215D
P 10150 3600
F 0 "#PWR05" H 10150 3350 50  0001 C CNN
F 1 "GND-power" H 10155 3427 50  0000 C CNN
F 2 "" H 10150 3600 50  0001 C CNN
F 3 "" H 10150 3600 50  0001 C CNN
	1    10150 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 3600 10150 3450
Wire Wire Line
	10150 3450 10175 3450
Text Notes 9525 2925 0    197  ~ 0
MAIN OUT
Text Notes 5125 2700 0    197  ~ 0
MAIN IN
$Comp
L allcolours_analogue-rescue:Conn_01x01-Connector-allcolours-rescue J1
U 1 1 5BD75EC5
P 6500 3150
F 0 "J1" H 6579 3192 50  0000 L CNN
F 1 "MAIN IN" H 6579 3101 50  0000 L CNN
F 2 "" H 6500 3150 50  0001 C CNN
F 3 "" H 6500 3150 50  0001 C CNN
	1    6500 3150
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:AUDIO-JACKERTHENVAR-erthenvar M1
U 1 1 5BD75FEA
P 5375 3250
F 0 "M1" H 5381 3469 45  0000 C CNN
F 1 "AUDIO-JACKERTHENVAR-erthenvar" H 5375 3250 45  0001 L BNN
F 2 "erthenvar_ERTHENVAR-JACK" H 5405 3400 20  0001 C CNN
F 3 "" H 5375 3250 60  0001 C CNN
	1    5375 3250
	1    0    0    -1  
$EndComp
$Comp
L allcolours_analogue-rescue:GND-power #PWR01
U 1 1 5BD760AE
P 5800 2975
F 0 "#PWR01" H 5800 2725 50  0001 C CNN
F 1 "GND-power" H 5805 2802 50  0000 C CNN
F 2 "" H 5800 2975 50  0001 C CNN
F 3 "" H 5800 2975 50  0001 C CNN
	1    5800 2975
	1    0    0    -1  
$EndComp
Wire Wire Line
	5675 3150 5675 2975
Wire Wire Line
	5675 2975 5800 2975
Wire Wire Line
	9775 3150 10175 3150
Wire Wire Line
	9275 3975 9525 3975
Wire Wire Line
	9525 3975 9525 3150
Connection ~ 9525 3150
Wire Wire Line
	9525 3150 9575 3150
$Comp
L allcolours_analogue-rescue:CP1_Small-device C2
U 1 1 5BD03889
P 8300 3250
F 0 "C2" H 8310 3320 50  0000 L CNN
F 1 "10u" H 8310 3170 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 8300 3250 50  0001 C CNN
F 3 "" H 8300 3250 50  0000 C CNN
	1    8300 3250
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
P 6075 3150
F 0 "C1" H 6085 3220 50  0000 L CNN
F 1 "10u" H 6085 3070 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 6075 3150 50  0001 C CNN
F 3 "" H 6075 3150 50  0000 C CNN
	1    6075 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	5675 3450 5975 3450
Wire Wire Line
	5975 3450 5975 3150
Wire Wire Line
	6175 3150 6300 3150
Text Notes 6225 3400 0    60   ~ 0
or buffer?
$Sheet
S 1025 7050 1750 475 
U 5C04EB62
F0 "revealed comparator" 60
F1 "revealed.sch" 60
$EndSheet
Text Notes 1700 7475 0    157  ~ 0
revealed
$EndSCHEMATC
