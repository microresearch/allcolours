EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
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
L allcolours-rescue:C-device-allcolours-rescue C3
U 1 1 5AD5C1E4
P 8015 2680
F 0 "C3" H 7945 2555 50  0000 C CNN
F 1 "100N" V 7870 2945 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 8053 2530 50  0001 C CNN
F 3 "" H 8015 2680 50  0001 C CNN
	1    8015 2680
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q2
U 1 1 5B6A4D24
P 1575 1190
F 0 "Q2" H 1766 1236 50  0000 L CNN
F 1 "MMBT3904" H 1225 1040 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1775 1290 50  0001 C CNN
F 3 "" H 1575 1190 50  0001 C CNN
	1    1575 1190
	1    0    0    -1  
$EndComp
Text Notes 250  230  0    118  ~ 0
pulses out x5 (2xLF 3xHF)\ninverted = 10v out - invert in software
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R9
U 1 1 5B6A6373
P 1225 1190
F 0 "R9" V 1029 1190 50  0000 C CNN
F 1 "10K" V 1120 1190 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1225 1190 50  0001 C CNN
F 3 "" H 1225 1190 50  0001 C CNN
	1    1225 1190
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R10
U 1 1 5B6A6444
P 1675 840
F 0 "R10" H 1895 740 50  0000 R CNN
F 1 "1K" H 1870 820 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 1675 840 50  0001 C CNN
F 3 "" H 1675 840 50  0001 C CNN
	1    1675 840 
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR017
U 1 1 5B6A65ED
P 1675 1440
F 0 "#PWR017" H 1675 1190 50  0001 C CNN
F 1 "GND" H 1680 1267 50  0000 C CNN
F 2 "" H 1675 1440 50  0001 C CNN
F 3 "" H 1675 1440 50  0001 C CNN
	1    1675 1440
	1    0    0    -1  
$EndComp
Wire Wire Line
	1325 1190 1375 1190
Wire Wire Line
	1675 740  1675 690 
Wire Wire Line
	1675 1440 1675 1390
Text Notes 840  2260 0    118  ~ 0
pulses in - 4x - 2x LF 2x HF inc. 1each clock in\ninverted
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q4
U 1 1 5B703499
P 1650 3125
F 0 "Q4" H 1841 3171 50  0000 L CNN
F 1 "MMBT3904" H 1870 2975 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1850 3225 50  0001 C CNN
F 3 "" H 1650 3125 50  0001 C CNN
	1    1650 3125
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R17
U 1 1 5B7034FD
P 1310 3125
F 0 "R17" V 1114 3125 50  0000 C CNN
F 1 "100K" V 1205 3125 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1310 3125 50  0001 C CNN
F 3 "" H 1310 3125 50  0001 C CNN
	1    1310 3125
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R22
U 1 1 5B703589
P 1750 2775
F 0 "R22" H 1691 2729 50  0000 R CNN
F 1 "10K" H 1691 2820 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 1750 2775 50  0001 C CNN
F 3 "" H 1750 2775 50  0001 C CNN
	1    1750 2775
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR058
U 1 1 5B705850
P 1750 3375
F 0 "#PWR058" H 1750 3125 50  0001 C CNN
F 1 "GND" H 1755 3202 50  0000 C CNN
F 2 "" H 1750 3375 50  0001 C CNN
F 3 "" H 1750 3375 50  0001 C CNN
	1    1750 3375
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2925 1750 2875
Wire Wire Line
	1750 2675 1750 2625
Wire Wire Line
	1750 3375 1750 3325
Wire Wire Line
	1750 2925 2000 2925
Connection ~ 1750 2925
Text Label 2000 2925 1    60   ~ 0
pulself1_in
Text Notes 75   5810 0    118  ~ 0
CV IN  x4 =speedl, speedh, model, modeh=just_pots
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U7
U 1 1 5B77CFF8
P 2205 6585
F 0 "U7" H 2260 6725 50  0000 L CNN
F 1 "MCP6002" H 2205 6485 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 2205 6585 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 2205 6585 50  0001 C CNN
	1    2205 6585
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR066
U 1 1 5B77CFFE
P 2105 6935
F 0 "#PWR066" H 2105 6685 50  0001 C CNN
F 1 "GND" H 2240 6880 50  0000 C CNN
F 2 "" H 2105 6935 50  0001 C CNN
F 3 "" H 2105 6935 50  0001 C CNN
	1    2105 6935
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R38
U 1 1 5B77D00A
P 1755 6685
F 0 "R38" V 1840 6500 50  0000 C CNN
F 1 "100K" V 1660 6605 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1755 6685 50  0001 C CNN
F 3 "" H 1755 6685 50  0001 C CNN
	1    1755 6685
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R39
U 1 1 5B77D010
P 2155 7135
F 0 "R39" V 2075 7265 50  0000 C CNN
F 1 "66.5K" V 2205 7330 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2155 7135 50  0001 C CNN
F 3 "" H 2155 7135 50  0001 C CNN
	1    2155 7135
	0    1    1    0   
$EndComp
Wire Wire Line
	2105 6285 2105 6235
Wire Wire Line
	1855 6685 1905 6685
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR064
U 1 1 5B77D02A
P 1855 6485
F 0 "#PWR064" H 1855 6235 50  0001 C CNN
F 1 "GND" H 1860 6312 50  0000 C CNN
F 2 "" H 1855 6485 50  0001 C CNN
F 3 "" H 1855 6485 50  0001 C CNN
	1    1855 6485
	1    0    0    -1  
$EndComp
Wire Wire Line
	1855 6485 1905 6485
Wire Wire Line
	2105 6935 2105 6885
Wire Wire Line
	1855 7135 2055 7135
Connection ~ 1855 6685
Wire Wire Line
	2255 7135 2505 7135
Wire Wire Line
	2505 7135 2505 6585
Connection ~ 1855 7135
Wire Wire Line
	1555 6685 1655 6685
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C27
U 1 1 5B77D048
P 2155 7335
F 0 "C27" V 2210 7455 50  0000 C CNN
F 1 "1nF" V 2270 7340 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 2155 7335 50  0001 C CNN
F 3 "" H 2155 7335 50  0001 C CNN
	1    2155 7335
	0    1    1    0   
$EndComp
Wire Wire Line
	1855 7135 1855 7335
Wire Wire Line
	1855 7335 2055 7335
Wire Wire Line
	2255 7335 2505 7335
Wire Wire Line
	2505 7335 2505 7135
Connection ~ 2505 7135
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C28
U 1 1 5B77D053
P 2985 7145
F 0 "C28" H 2893 7099 50  0000 R CNN
F 1 "100N" H 2893 7190 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 2985 7145 50  0001 C CNN
F 3 "" H 2985 7145 50  0001 C CNN
	1    2985 7145
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR069
U 1 1 5B77D05F
P 2985 7295
F 0 "#PWR069" H 2985 7045 50  0001 C CNN
F 1 "GND" H 2990 7122 50  0000 C CNN
F 2 "" H 2985 7295 50  0001 C CNN
F 3 "" H 2985 7295 50  0001 C CNN
	1    2985 7295
	1    0    0    -1  
$EndComp
Wire Wire Line
	2985 7245 2985 7295
Wire Wire Line
	2985 6995 2985 7045
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR084
U 1 1 5B74B1A0
P 8015 2930
F 0 "#PWR084" H 8015 2680 50  0001 C CNN
F 1 "GND" H 8015 2930 50  0000 C CNN
F 2 "" H 8015 2930 50  0001 C CNN
F 3 "" H 8015 2930 50  0001 C CNN
	1    8015 2930
	1    0    0    -1  
$EndComp
Wire Wire Line
	8015 2830 8015 2870
Wire Wire Line
	8015 2530 8015 2495
$Comp
L allcolours-rescue:C-device-allcolours-rescue C30
U 1 1 5C4F3990
P 7820 2680
F 0 "C30" H 7835 2435 50  0000 C CNN
F 1 "100N" V 7659 2680 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 7858 2530 50  0001 C CNN
F 3 "" H 7820 2680 50  0001 C CNN
	1    7820 2680
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C31
U 1 1 5C4F3ABC
P 8235 2670
F 0 "C31" H 8195 2395 50  0000 C CNN
F 1 "100N" V 8074 2670 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 8273 2520 50  0001 C CNN
F 3 "" H 8235 2670 50  0001 C CNN
	1    8235 2670
	-1   0    0    1   
$EndComp
Wire Wire Line
	7820 2530 7975 2530
Wire Wire Line
	7975 2530 7975 2495
Wire Wire Line
	7975 2495 8015 2495
Connection ~ 8015 2495
Wire Wire Line
	8015 2495 8015 2380
Wire Wire Line
	8015 2495 8235 2495
Wire Wire Line
	8235 2495 8235 2520
Wire Wire Line
	7820 2830 7945 2830
Wire Wire Line
	7945 2830 7945 2870
Wire Wire Line
	7945 2870 8015 2870
Connection ~ 8015 2870
Wire Wire Line
	8015 2870 8015 2930
Wire Wire Line
	8015 2870 8235 2870
Wire Wire Line
	8235 2870 8235 2820
Text Notes 3925 4200 0    157  ~ 0
PWM out hf\n
$Comp
L Device:R_POT speedlf1
U 1 1 5D2C66BC
P 1185 6440
F 0 "speedlf1" H 1115 6486 50  0000 R CNN
F 1 "10K" H 1115 6395 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 1185 6440 50  0001 C CNN
F 3 "~" H 1185 6440 50  0001 C CNN
	1    1185 6440
	1    0    0    -1  
$EndComp
Wire Wire Line
	1185 6235 1185 6290
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0136
U 1 1 5D2CAEA0
P 1185 6630
F 0 "#PWR0136" H 1185 6380 50  0001 C CNN
F 1 "GND" H 1190 6457 50  0000 C CNN
F 2 "" H 1185 6630 50  0001 C CNN
F 3 "" H 1185 6630 50  0001 C CNN
	1    1185 6630
	1    0    0    -1  
$EndComp
Wire Wire Line
	1335 6905 1335 6440
Wire Wire Line
	1855 6905 1855 7135
Wire Wire Line
	1855 6685 1855 6905
Connection ~ 1855 6905
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R85
U 1 1 5D2CADCC
P 1755 6905
F 0 "R85" V 1835 6920 50  0000 C CNN
F 1 "200K" V 1650 6905 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1755 6905 50  0001 C CNN
F 3 "" H 1755 6905 50  0001 C CNN
	1    1755 6905
	0    1    1    0   
$EndComp
Wire Wire Line
	1335 6905 1655 6905
Wire Wire Line
	1185 6590 1185 6630
Text Notes 940  7730 0    157  ~ 0
0-5v in
Text GLabel 1185 6235 0    60   Input ~ 0
AREF-10
Text Notes 1075 3940 0    157  ~ 0
PWM out lf 
Text GLabel 4660 4775 2    79   Input ~ 0
PWMHF_OUT
Text GLabel 1970 4505 2    79   Input ~ 0
PWMLF_OUT
$Comp
L MCU_ST_STM32F1:STM32F103CBTx U16
U 1 1 5D418906
P 10065 2290
F 0 "U16" H 10040 1170 50  0000 C CNN
F 1 "STM32F103CBTx" H 10025 2070 50  0000 C CNN
F 2 "Housings_QFP:LQFP-48_7x7mm_Pitch0.5mm" H 9465 890 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00161566.pdf" H 10065 2290 50  0001 C CNN
	1    10065 2290
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0151
U 1 1 5D422865
P 10110 730
F 0 "#PWR0151" H 10110 580 50  0001 C CNN
F 1 "+3.3V" H 10125 903 50  0000 C CNN
F 2 "" H 10110 730 50  0001 C CNN
F 3 "" H 10110 730 50  0001 C CNN
	1    10110 730 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0152
U 1 1 5D4229B5
P 1750 2625
F 0 "#PWR0152" H 1750 2475 50  0001 C CNN
F 1 "+3.3V" H 1765 2798 50  0000 C CNN
F 2 "" H 1750 2625 50  0001 C CNN
F 3 "" H 1750 2625 50  0001 C CNN
	1    1750 2625
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0153
U 1 1 5D42DE94
P 2105 6235
F 0 "#PWR0153" H 2105 6085 50  0001 C CNN
F 1 "+3.3V" H 2120 6408 50  0000 C CNN
F 2 "" H 2105 6235 50  0001 C CNN
F 3 "" H 2105 6235 50  0001 C CNN
	1    2105 6235
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0154
U 1 1 5D431538
P 2985 6995
F 0 "#PWR0154" H 2985 6845 50  0001 C CNN
F 1 "+3.3V" H 3000 7168 50  0000 C CNN
F 2 "" H 2985 6995 50  0001 C CNN
F 3 "" H 2985 6995 50  0001 C CNN
	1    2985 6995
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0155
U 1 1 5D439F1F
P 8015 2380
F 0 "#PWR0155" H 8015 2230 50  0001 C CNN
F 1 "+3.3V" H 8030 2553 50  0000 C CNN
F 2 "" H 8015 2380 50  0001 C CNN
F 3 "" H 8015 2380 50  0001 C CNN
	1    8015 2380
	1    0    0    -1  
$EndComp
Wire Wire Line
	9965 790  10065 790 
Wire Wire Line
	10065 790  10110 790 
Connection ~ 10065 790 
Wire Wire Line
	10110 730  10110 735 
Connection ~ 10110 790 
Wire Wire Line
	10110 790  10165 790 
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0156
U 1 1 5D42E890
P 10015 3870
F 0 "#PWR0156" H 10015 3620 50  0001 C CNN
F 1 "GND" H 9865 3875 50  0000 C CNN
F 2 "" H 10015 3870 50  0001 C CNN
F 3 "" H 10015 3870 50  0001 C CNN
	1    10015 3870
	1    0    0    -1  
$EndComp
Wire Wire Line
	9865 3790 9965 3790
Wire Wire Line
	9965 3790 10015 3790
Connection ~ 9965 3790
Wire Wire Line
	10065 3790 10165 3790
Connection ~ 10065 3790
Wire Wire Line
	10015 3870 10015 3790
Connection ~ 10015 3790
Wire Wire Line
	10015 3790 10065 3790
Wire Wire Line
	9365 990  9310 990 
Text Label 9270 990  2    60   ~ 0
RESET
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0157
U 1 1 5D463130
P 9310 1190
F 0 "#PWR0157" H 9310 940 50  0001 C CNN
F 1 "GND" H 9190 1190 50  0000 C CNN
F 2 "" H 9310 1190 50  0001 C CNN
F 3 "" H 9310 1190 50  0001 C CNN
	1    9310 1190
	1    0    0    -1  
$EndComp
Wire Wire Line
	9310 1190 9365 1190
$Comp
L allcolours-rescue:C-device-allcolours-rescue C57
U 1 1 5D46CD1C
P 7600 2680
F 0 "C57" H 7615 2435 50  0000 C CNN
F 1 "100N" V 7439 2680 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 7638 2530 50  0001 C CNN
F 3 "" H 7600 2680 50  0001 C CNN
	1    7600 2680
	-1   0    0    1   
$EndComp
Wire Wire Line
	7600 2830 7820 2830
Connection ~ 7820 2830
Wire Wire Line
	7600 2530 7820 2530
Connection ~ 7820 2530
Wire Wire Line
	10665 3390 10760 3390
Wire Wire Line
	10665 3490 10760 3490
Text Label 10760 3390 0    60   ~ 0
SWDIO
Text Label 10760 3490 0    60   ~ 0
SWCLK
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5D4CEDC0
P 8155 845
F 0 "J1" H 8182 821 50  0000 L CNN
F 1 "PROG" H 8182 730 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 8155 845 50  0001 C CNN
F 3 "~" H 8155 845 50  0001 C CNN
	1    8155 845 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0158
U 1 1 5D4CF080
P 7810 945
F 0 "#PWR0158" H 7810 695 50  0001 C CNN
F 1 "GND" H 7660 950 50  0000 C CNN
F 2 "" H 7810 945 50  0001 C CNN
F 3 "" H 7810 945 50  0001 C CNN
	1    7810 945 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0159
U 1 1 5D4CF9BB
P 7905 745
F 0 "#PWR0159" H 7905 595 50  0001 C CNN
F 1 "+3.3V" H 7920 918 50  0000 C CNN
F 2 "" H 7905 745 50  0001 C CNN
F 3 "" H 7905 745 50  0001 C CNN
	1    7905 745 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7955 845  7880 845 
Text Label 7880 845  2    60   ~ 0
SWCLK
Wire Wire Line
	7905 745  7955 745 
Wire Wire Line
	7810 945  7955 945 
Wire Wire Line
	7955 1045 7865 1045
Wire Wire Line
	7865 1045 7865 1100
Text Label 7865 1100 2    60   ~ 0
SWDIO
$Comp
L pspice:INDUCTOR L2
U 1 1 5D515AA9
P 10455 735
F 0 "L2" H 10455 950 50  0000 C CNN
F 1 "INDUCTOR" H 10455 859 50  0000 C CNN
F 2 "Inductors_SMD:L_0805" H 10455 735 50  0001 C CNN
F 3 "~" H 10455 735 50  0001 C CNN
	1    10455 735 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10265 790  10705 790 
Wire Wire Line
	10705 790  10705 735 
Wire Wire Line
	10205 735  10110 735 
Connection ~ 10110 735 
Wire Wire Line
	10110 735  10110 790 
$Comp
L Device:Crystal Y2
U 1 1 5D52A7A4
P 8905 1455
F 0 "Y2" V 8859 1586 50  0000 L CNN
F 1 "8 MHz" V 8950 1586 50  0000 L CNN
F 2 "Crystals:Crystal_SMD_HC49-SD" H 8905 1455 50  0001 C CNN
F 3 "~" H 8905 1455 50  0001 C CNN
	1    8905 1455
	0    1    1    0   
$EndComp
Wire Wire Line
	9195 1390 9365 1390
Wire Wire Line
	8905 1605 9295 1605
Wire Wire Line
	9295 1605 9295 1490
Wire Wire Line
	9295 1490 9365 1490
$Comp
L allcolours-rescue:C-device-allcolours-rescue C60
U 1 1 5D5407EC
P 8730 1305
F 0 "C60" V 8880 1305 50  0000 C CNN
F 1 "18P" V 8569 1305 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 8768 1155 50  0001 C CNN
F 3 "" H 8730 1305 50  0001 C CNN
	1    8730 1305
	0    -1   -1   0   
$EndComp
$Comp
L allcolours-rescue:C-device-allcolours-rescue C59
U 1 1 5D555E70
P 8725 1605
F 0 "C59" V 8660 1720 50  0000 C CNN
F 1 "18P" V 8570 1695 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 8763 1455 50  0001 C CNN
F 3 "" H 8725 1605 50  0001 C CNN
	1    8725 1605
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8905 1305 9195 1305
Wire Wire Line
	9195 1305 9195 1390
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0160
U 1 1 5D560AF7
P 8515 1420
F 0 "#PWR0160" H 8515 1170 50  0001 C CNN
F 1 "GND" H 8395 1420 50  0000 C CNN
F 2 "" H 8515 1420 50  0001 C CNN
F 3 "" H 8515 1420 50  0001 C CNN
	1    8515 1420
	1    0    0    -1  
$EndComp
Wire Wire Line
	8880 1305 8905 1305
Connection ~ 8905 1305
Wire Wire Line
	8875 1605 8905 1605
Connection ~ 8905 1605
Wire Wire Line
	8580 1305 8575 1305
Wire Wire Line
	8575 1305 8575 1420
Wire Wire Line
	8515 1420 8575 1420
Connection ~ 8575 1420
Wire Wire Line
	8575 1420 8575 1605
Wire Wire Line
	9865 790  9965 790 
Connection ~ 9965 790 
Text GLabel 1955 970  2    60   Input ~ 0
PULSELF1_OUT
Text Label 1085 1190 2    60   ~ 0
pulself1_out
Wire Wire Line
	1085 1190 1125 1190
Wire Wire Line
	1675 940  1675 970 
Text GLabel 1180 3125 0    60   Input ~ 0
PULSELF1_IN
Text Label 1205 4735 1    60   ~ 0
pwmlf_out
Text Label 3880 5000 1    60   ~ 0
pwmhf_out
Connection ~ 1675 970 
Wire Wire Line
	1675 970  1675 990 
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q7
U 1 1 5D7EE282
P 2920 1250
F 0 "Q7" H 3111 1296 50  0000 L CNN
F 1 "MMBT3904" H 2570 1100 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3120 1350 50  0001 C CNN
F 3 "" H 2920 1250 50  0001 C CNN
	1    2920 1250
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R72
U 1 1 5D7EE289
P 2570 1250
F 0 "R72" V 2374 1250 50  0000 C CNN
F 1 "10K" V 2465 1250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2570 1250 50  0001 C CNN
F 3 "" H 2570 1250 50  0001 C CNN
	1    2570 1250
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R74
U 1 1 5D7EE290
P 3020 900
F 0 "R74" H 3285 820 50  0000 R CNN
F 1 "1K" H 3270 900 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 3020 900 50  0001 C CNN
F 3 "" H 3020 900 50  0001 C CNN
	1    3020 900 
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR029
U 1 1 5D7EE297
P 3020 1500
F 0 "#PWR029" H 3020 1250 50  0001 C CNN
F 1 "GND" H 3025 1327 50  0000 C CNN
F 2 "" H 3020 1500 50  0001 C CNN
F 3 "" H 3020 1500 50  0001 C CNN
	1    3020 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2670 1250 2720 1250
Wire Wire Line
	3020 800  3020 750 
Wire Wire Line
	3020 1500 3020 1450
Text GLabel 3300 1030 2    60   Input ~ 0
PULSELF2_OUT
Text Label 2430 1250 2    60   ~ 0
pulself2_out
Wire Wire Line
	2430 1250 2470 1250
Wire Wire Line
	3020 1000 3020 1030
Connection ~ 3020 1030
Wire Wire Line
	3020 1030 3020 1050
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q10
U 1 1 5D7FBE7E
P 4305 1235
F 0 "Q10" H 4496 1281 50  0000 L CNN
F 1 "MMBT3904" H 3955 1085 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4505 1335 50  0001 C CNN
F 3 "" H 4305 1235 50  0001 C CNN
	1    4305 1235
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R80
U 1 1 5D7FBE85
P 3955 1235
F 0 "R80" V 3850 1390 50  0000 C CNN
F 1 "10K" V 3850 1235 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3955 1235 50  0001 C CNN
F 3 "" H 3955 1235 50  0001 C CNN
	1    3955 1235
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R82
U 1 1 5D7FBE8C
P 4405 885
F 0 "R82" H 4715 825 50  0000 R CNN
F 1 "1K" H 4660 920 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 4405 885 50  0001 C CNN
F 3 "" H 4405 885 50  0001 C CNN
	1    4405 885 
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR033
U 1 1 5D7FBE93
P 4405 1485
F 0 "#PWR033" H 4405 1235 50  0001 C CNN
F 1 "GND" H 4410 1312 50  0000 C CNN
F 2 "" H 4405 1485 50  0001 C CNN
F 3 "" H 4405 1485 50  0001 C CNN
	1    4405 1485
	1    0    0    -1  
$EndComp
Wire Wire Line
	4055 1235 4105 1235
Wire Wire Line
	4405 785  4405 735 
Wire Wire Line
	4405 1485 4405 1435
Text GLabel 4685 1015 2    60   Input ~ 0
PULSEHF1_OUT
Text Label 3815 1235 2    60   ~ 0
pulsehf1_out
Wire Wire Line
	3815 1235 3855 1235
Wire Wire Line
	4405 985  4405 1015
Connection ~ 4405 1015
Wire Wire Line
	4405 1015 4405 1035
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q12
U 1 1 5D80A920
P 5650 1280
F 0 "Q12" H 5841 1326 50  0000 L CNN
F 1 "MMBT3904" H 5300 1130 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 5850 1380 50  0001 C CNN
F 3 "" H 5650 1280 50  0001 C CNN
	1    5650 1280
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R87
U 1 1 5D80A927
P 5300 1280
F 0 "R87" V 5195 1470 50  0000 C CNN
F 1 "10K" V 5195 1280 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5300 1280 50  0001 C CNN
F 3 "" H 5300 1280 50  0001 C CNN
	1    5300 1280
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R89
U 1 1 5D80A92E
P 5750 930
F 0 "R89" H 5950 870 50  0000 R CNN
F 1 "1K" H 5945 985 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 5750 930 50  0001 C CNN
F 3 "" H 5750 930 50  0001 C CNN
	1    5750 930 
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR037
U 1 1 5D80A935
P 5750 1530
F 0 "#PWR037" H 5750 1280 50  0001 C CNN
F 1 "GND" H 5755 1357 50  0000 C CNN
F 2 "" H 5750 1530 50  0001 C CNN
F 3 "" H 5750 1530 50  0001 C CNN
	1    5750 1530
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 1280 5450 1280
Wire Wire Line
	5750 830  5750 780 
Wire Wire Line
	5750 1530 5750 1480
Text GLabel 6030 1060 2    60   Input ~ 0
PULSEHF2_OUT
Text Label 5160 1280 2    60   ~ 0
pulsehf2_out
Wire Wire Line
	5160 1280 5200 1280
Wire Wire Line
	5750 1030 5750 1060
Connection ~ 5750 1060
Wire Wire Line
	5750 1060 5750 1080
Wire Wire Line
	1410 3125 1435 3125
Wire Wire Line
	1180 3125 1210 3125
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q9
U 1 1 5D86E162
P 3130 3110
F 0 "Q9" H 3321 3156 50  0000 L CNN
F 1 "MMBT3904" H 3275 2960 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3330 3210 50  0001 C CNN
F 3 "" H 3130 3110 50  0001 C CNN
	1    3130 3110
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R73
U 1 1 5D86E169
P 2790 3110
F 0 "R73" V 2594 3110 50  0000 C CNN
F 1 "100K" V 2685 3110 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2790 3110 50  0001 C CNN
F 3 "" H 2790 3110 50  0001 C CNN
	1    2790 3110
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R75
U 1 1 5D86E170
P 3230 2760
F 0 "R75" H 3415 2765 50  0000 R CNN
F 1 "10K" H 3171 2805 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 3230 2760 50  0001 C CNN
F 3 "" H 3230 2760 50  0001 C CNN
	1    3230 2760
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR031
U 1 1 5D86E177
P 3230 3360
F 0 "#PWR031" H 3230 3110 50  0001 C CNN
F 1 "GND" H 3235 3187 50  0000 C CNN
F 2 "" H 3230 3360 50  0001 C CNN
F 3 "" H 3230 3360 50  0001 C CNN
	1    3230 3360
	1    0    0    -1  
$EndComp
Wire Wire Line
	3230 2910 3230 2860
Wire Wire Line
	3230 2660 3230 2610
Wire Wire Line
	3230 3360 3230 3310
Wire Wire Line
	3230 2910 3480 2910
Connection ~ 3230 2910
Text Label 3480 2910 1    60   ~ 0
pulselfclk_in
$Comp
L power:+3.3V #PWR030
U 1 1 5D86E183
P 3230 2610
F 0 "#PWR030" H 3230 2460 50  0001 C CNN
F 1 "+3.3V" H 3245 2783 50  0000 C CNN
F 2 "" H 3230 2610 50  0001 C CNN
F 3 "" H 3230 2610 50  0001 C CNN
	1    3230 2610
	1    0    0    -1  
$EndComp
Text GLabel 2660 3110 0    60   Input ~ 0
PULSELFCLK_IN
Wire Wire Line
	2890 3110 2910 3110
Wire Wire Line
	2660 3110 2690 3110
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q11
U 1 1 5D87F76B
P 4560 3085
F 0 "Q11" H 4735 3020 50  0000 L CNN
F 1 "MMBT3904" H 4795 2940 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4760 3185 50  0001 C CNN
F 3 "" H 4560 3085 50  0001 C CNN
	1    4560 3085
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R81
U 1 1 5D87F772
P 4220 3085
F 0 "R81" V 4024 3085 50  0000 C CNN
F 1 "100K" V 4115 3085 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4220 3085 50  0001 C CNN
F 3 "" H 4220 3085 50  0001 C CNN
	1    4220 3085
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R84
U 1 1 5D87F779
P 4660 2735
F 0 "R84" H 4875 2740 50  0000 R CNN
F 1 "10K" H 4601 2780 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 4660 2735 50  0001 C CNN
F 3 "" H 4660 2735 50  0001 C CNN
	1    4660 2735
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR035
U 1 1 5D87F780
P 4660 3335
F 0 "#PWR035" H 4660 3085 50  0001 C CNN
F 1 "GND" H 4665 3162 50  0000 C CNN
F 2 "" H 4660 3335 50  0001 C CNN
F 3 "" H 4660 3335 50  0001 C CNN
	1    4660 3335
	1    0    0    -1  
$EndComp
Wire Wire Line
	4660 2885 4660 2835
Wire Wire Line
	4660 2635 4660 2585
Wire Wire Line
	4660 3335 4660 3285
Wire Wire Line
	4660 2885 4910 2885
Connection ~ 4660 2885
Text Label 4910 2885 1    60   ~ 0
pulsehf1_in
$Comp
L power:+3.3V #PWR034
U 1 1 5D87F78C
P 4660 2585
F 0 "#PWR034" H 4660 2435 50  0001 C CNN
F 1 "+3.3V" H 4675 2758 50  0000 C CNN
F 2 "" H 4660 2585 50  0001 C CNN
F 3 "" H 4660 2585 50  0001 C CNN
	1    4660 2585
	1    0    0    -1  
$EndComp
Text GLabel 4090 3085 0    60   Input ~ 0
PULSEHF1_IN
Wire Wire Line
	4320 3085 4340 3085
Wire Wire Line
	4090 3085 4120 3085
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q13
U 1 1 5D891B73
P 5990 3045
F 0 "Q13" H 6181 3091 50  0000 L CNN
F 1 "MMBT3904" H 6195 2960 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 6190 3145 50  0001 C CNN
F 3 "" H 5990 3045 50  0001 C CNN
	1    5990 3045
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R88
U 1 1 5D891B7A
P 5650 3045
F 0 "R88" V 5454 3045 50  0000 C CNN
F 1 "100K" V 5545 3045 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5650 3045 50  0001 C CNN
F 3 "" H 5650 3045 50  0001 C CNN
	1    5650 3045
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R90
U 1 1 5D891B81
P 6090 2695
F 0 "R90" H 6031 2649 50  0000 R CNN
F 1 "10K" H 6031 2740 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 6090 2695 50  0001 C CNN
F 3 "" H 6090 2695 50  0001 C CNN
	1    6090 2695
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR039
U 1 1 5D891B88
P 6090 3295
F 0 "#PWR039" H 6090 3045 50  0001 C CNN
F 1 "GND" H 6095 3122 50  0000 C CNN
F 2 "" H 6090 3295 50  0001 C CNN
F 3 "" H 6090 3295 50  0001 C CNN
	1    6090 3295
	1    0    0    -1  
$EndComp
Wire Wire Line
	6090 2845 6090 2795
Wire Wire Line
	6090 2595 6090 2545
Wire Wire Line
	6090 3295 6090 3245
Wire Wire Line
	6090 2845 6340 2845
Connection ~ 6090 2845
Text Label 6340 2845 1    60   ~ 0
pulsehfclk_in
$Comp
L power:+3.3V #PWR038
U 1 1 5D891B94
P 6090 2545
F 0 "#PWR038" H 6090 2395 50  0001 C CNN
F 1 "+3.3V" H 6105 2718 50  0000 C CNN
F 2 "" H 6090 2545 50  0001 C CNN
F 3 "" H 6090 2545 50  0001 C CNN
	1    6090 2545
	1    0    0    -1  
$EndComp
Text GLabel 5520 3045 0    60   Input ~ 0
PULSEHFCLK_IN
Wire Wire Line
	5750 3045 5770 3045
Wire Wire Line
	5520 3045 5550 3045
Text GLabel 1555 6685 1    79   Input ~ 0
SPEEDLF_IN
Wire Wire Line
	2505 6585 2695 6585
Connection ~ 2505 6585
Text Label 2695 6585 1    60   ~ 0
speedlf
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U7
U 2 1 5D95A424
P 5190 6670
F 0 "U7" H 5245 6810 50  0000 L CNN
F 1 "MCP6002" H 5190 6570 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 5190 6670 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5190 6670 50  0001 C CNN
	2    5190 6670
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR052
U 1 1 5D95A42B
P 5090 7020
F 0 "#PWR052" H 5090 6770 50  0001 C CNN
F 1 "GND" H 5225 6965 50  0000 C CNN
F 2 "" H 5090 7020 50  0001 C CNN
F 3 "" H 5090 7020 50  0001 C CNN
	1    5090 7020
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R93
U 1 1 5D95A431
P 4740 6770
F 0 "R93" V 4790 6630 50  0000 C CNN
F 1 "100K" V 4645 6690 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4740 6770 50  0001 C CNN
F 3 "" H 4740 6770 50  0001 C CNN
	1    4740 6770
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R95
U 1 1 5D95A438
P 5140 7220
F 0 "R95" V 5060 7350 50  0000 C CNN
F 1 "66.5K" V 5190 7415 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5140 7220 50  0001 C CNN
F 3 "" H 5140 7220 50  0001 C CNN
	1    5140 7220
	0    1    1    0   
$EndComp
Wire Wire Line
	5090 6370 5090 6320
Wire Wire Line
	4840 6770 4890 6770
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR050
U 1 1 5D95A441
P 4840 6570
F 0 "#PWR050" H 4840 6320 50  0001 C CNN
F 1 "GND" H 4845 6397 50  0000 C CNN
F 2 "" H 4840 6570 50  0001 C CNN
F 3 "" H 4840 6570 50  0001 C CNN
	1    4840 6570
	1    0    0    -1  
$EndComp
Wire Wire Line
	4840 6570 4890 6570
Wire Wire Line
	5090 7020 5090 6970
Wire Wire Line
	4840 7220 5040 7220
Connection ~ 4840 6770
Wire Wire Line
	5240 7220 5490 7220
Wire Wire Line
	5490 7220 5490 6670
Connection ~ 4840 7220
Wire Wire Line
	4540 6770 4640 6770
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C58
U 1 1 5D95A44F
P 5140 7420
F 0 "C58" V 5195 7540 50  0000 C CNN
F 1 "1nF" V 5255 7425 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 5140 7420 50  0001 C CNN
F 3 "" H 5140 7420 50  0001 C CNN
	1    5140 7420
	0    1    1    0   
$EndComp
Wire Wire Line
	4840 7220 4840 7420
Wire Wire Line
	4840 7420 5040 7420
Wire Wire Line
	5240 7420 5490 7420
Wire Wire Line
	5490 7420 5490 7220
Connection ~ 5490 7220
$Comp
L Device:R_POT speedhf1
U 1 1 5D95A45B
P 4170 6525
F 0 "speedhf1" H 4100 6571 50  0000 R CNN
F 1 "10K" H 4100 6480 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 4170 6525 50  0001 C CNN
F 3 "~" H 4170 6525 50  0001 C CNN
	1    4170 6525
	1    0    0    -1  
$EndComp
Wire Wire Line
	4170 6320 4170 6375
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR048
U 1 1 5D95A463
P 4170 6715
F 0 "#PWR048" H 4170 6465 50  0001 C CNN
F 1 "GND" H 4175 6542 50  0000 C CNN
F 2 "" H 4170 6715 50  0001 C CNN
F 3 "" H 4170 6715 50  0001 C CNN
	1    4170 6715
	1    0    0    -1  
$EndComp
Wire Wire Line
	4320 6990 4320 6525
Wire Wire Line
	4840 6990 4840 7220
Wire Wire Line
	4840 6770 4840 6990
Connection ~ 4840 6990
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R94
U 1 1 5D95A46D
P 4740 6990
F 0 "R94" V 4815 6985 50  0000 C CNN
F 1 "200K" V 4635 6990 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4740 6990 50  0001 C CNN
F 3 "" H 4740 6990 50  0001 C CNN
	1    4740 6990
	0    1    1    0   
$EndComp
Wire Wire Line
	4320 6990 4640 6990
Wire Wire Line
	4170 6675 4170 6715
Text GLabel 4170 6320 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR051
U 1 1 5D95A477
P 5090 6320
F 0 "#PWR051" H 5090 6170 50  0001 C CNN
F 1 "+3.3V" H 5105 6493 50  0000 C CNN
F 2 "" H 5090 6320 50  0001 C CNN
F 3 "" H 5090 6320 50  0001 C CNN
	1    5090 6320
	1    0    0    -1  
$EndComp
Text GLabel 4540 6770 1    79   Input ~ 0
SPEEDHF_IN
Wire Wire Line
	5490 6670 5680 6670
Connection ~ 5490 6670
Text Label 5680 6670 1    60   ~ 0
speedhf
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U17
U 2 1 5D971703
P 7505 5050
F 0 "U17" H 7560 5190 50  0000 L CNN
F 1 "MCP6002" H 7505 4950 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 7505 5050 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 7505 5050 50  0001 C CNN
	2    7505 5050
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR062
U 1 1 5D97170A
P 7405 5400
F 0 "#PWR062" H 7405 5150 50  0001 C CNN
F 1 "GND" H 7540 5345 50  0000 C CNN
F 2 "" H 7405 5400 50  0001 C CNN
F 3 "" H 7405 5400 50  0001 C CNN
	1    7405 5400
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R99
U 1 1 5D971717
P 7455 5600
F 0 "R99" V 7375 5730 50  0000 C CNN
F 1 "66.5K" V 7505 5795 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7455 5600 50  0001 C CNN
F 3 "" H 7455 5600 50  0001 C CNN
	1    7455 5600
	0    1    1    0   
$EndComp
Wire Wire Line
	7405 4750 7405 4700
Wire Wire Line
	7155 5150 7205 5150
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR057
U 1 1 5D971720
P 7155 4950
F 0 "#PWR057" H 7155 4700 50  0001 C CNN
F 1 "GND" H 7160 4777 50  0000 C CNN
F 2 "" H 7155 4950 50  0001 C CNN
F 3 "" H 7155 4950 50  0001 C CNN
	1    7155 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7155 4950 7205 4950
Wire Wire Line
	7405 5400 7405 5350
Wire Wire Line
	7155 5600 7355 5600
Wire Wire Line
	7555 5600 7805 5600
Wire Wire Line
	7805 5600 7805 5050
Connection ~ 7155 5600
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C62
U 1 1 5D97172E
P 7455 5800
F 0 "C62" V 7510 5920 50  0000 C CNN
F 1 "1nF" V 7570 5805 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 7455 5800 50  0001 C CNN
F 3 "" H 7455 5800 50  0001 C CNN
	1    7455 5800
	0    1    1    0   
$EndComp
Wire Wire Line
	7155 5600 7155 5800
Wire Wire Line
	7155 5800 7355 5800
Wire Wire Line
	7555 5800 7805 5800
Wire Wire Line
	7805 5800 7805 5600
Connection ~ 7805 5600
$Comp
L Device:R_POT modelf1
U 1 1 5D97173A
P 6485 4905
F 0 "modelf1" H 6415 4951 50  0000 R CNN
F 1 "10K" H 6415 4860 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 6485 4905 50  0001 C CNN
F 3 "~" H 6485 4905 50  0001 C CNN
	1    6485 4905
	1    0    0    -1  
$EndComp
Wire Wire Line
	6485 4700 6485 4755
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR054
U 1 1 5D971742
P 6485 5095
F 0 "#PWR054" H 6485 4845 50  0001 C CNN
F 1 "GND" H 6490 4922 50  0000 C CNN
F 2 "" H 6485 5095 50  0001 C CNN
F 3 "" H 6485 5095 50  0001 C CNN
	1    6485 5095
	1    0    0    -1  
$EndComp
Wire Wire Line
	6635 5370 6635 4905
Wire Wire Line
	7155 5370 7155 5600
Wire Wire Line
	7155 5150 7155 5370
Connection ~ 7155 5370
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R97
U 1 1 5D97174C
P 7055 5370
F 0 "R97" V 6859 5370 50  0000 C CNN
F 1 "200K" V 6950 5370 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7055 5370 50  0001 C CNN
F 3 "" H 7055 5370 50  0001 C CNN
	1    7055 5370
	0    1    1    0   
$EndComp
Wire Wire Line
	6635 5370 6955 5370
Wire Wire Line
	6485 5055 6485 5095
Text GLabel 6485 4700 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR061
U 1 1 5D971756
P 7405 4700
F 0 "#PWR061" H 7405 4550 50  0001 C CNN
F 1 "+3.3V" H 7420 4873 50  0000 C CNN
F 2 "" H 7405 4700 50  0001 C CNN
F 3 "" H 7405 4700 50  0001 C CNN
	1    7405 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7805 5050 7995 5050
Connection ~ 7805 5050
Text Label 7995 5050 1    60   ~ 0
modelf
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U17
U 1 1 5D9EB535
P 10000 5050
F 0 "U17" H 10055 5190 50  0000 L CNN
F 1 "MCP6002" H 10000 4950 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 10000 5050 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 10000 5050 50  0001 C CNN
	1    10000 5050
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR060
U 1 1 5D9EB53C
P 9900 5400
F 0 "#PWR060" H 9900 5150 50  0001 C CNN
F 1 "GND" H 10035 5345 50  0000 C CNN
F 2 "" H 9900 5400 50  0001 C CNN
F 3 "" H 9900 5400 50  0001 C CNN
	1    9900 5400
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R98
U 1 1 5D9EB542
P 9950 5600
F 0 "R98" V 9870 5730 50  0000 C CNN
F 1 "66.5K" V 10000 5795 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 9950 5600 50  0001 C CNN
F 3 "" H 9950 5600 50  0001 C CNN
	1    9950 5600
	0    1    1    0   
$EndComp
Wire Wire Line
	9900 4750 9900 4700
Wire Wire Line
	9650 5150 9700 5150
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR056
U 1 1 5D9EB54B
P 9650 4950
F 0 "#PWR056" H 9650 4700 50  0001 C CNN
F 1 "GND" H 9655 4777 50  0000 C CNN
F 2 "" H 9650 4950 50  0001 C CNN
F 3 "" H 9650 4950 50  0001 C CNN
	1    9650 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 4950 9700 4950
Wire Wire Line
	9900 5400 9900 5350
Wire Wire Line
	9650 5600 9850 5600
Wire Wire Line
	10050 5600 10300 5600
Wire Wire Line
	10300 5600 10300 5050
Connection ~ 9650 5600
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C61
U 1 1 5D9EB557
P 9950 5800
F 0 "C61" V 10005 5920 50  0000 C CNN
F 1 "1nF" V 10065 5805 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 9950 5800 50  0001 C CNN
F 3 "" H 9950 5800 50  0001 C CNN
	1    9950 5800
	0    1    1    0   
$EndComp
Wire Wire Line
	9650 5600 9650 5800
Wire Wire Line
	9650 5800 9850 5800
Wire Wire Line
	10050 5800 10300 5800
Wire Wire Line
	10300 5800 10300 5600
Connection ~ 10300 5600
$Comp
L Device:R_POT modehf1
U 1 1 5D9EB563
P 8980 4905
F 0 "modehf1" H 8910 4951 50  0000 R CNN
F 1 "10K" H 8910 4860 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 8980 4905 50  0001 C CNN
F 3 "~" H 8980 4905 50  0001 C CNN
	1    8980 4905
	1    0    0    -1  
$EndComp
Wire Wire Line
	8980 4700 8980 4755
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR053
U 1 1 5D9EB56B
P 8980 5095
F 0 "#PWR053" H 8980 4845 50  0001 C CNN
F 1 "GND" H 8985 4922 50  0000 C CNN
F 2 "" H 8980 5095 50  0001 C CNN
F 3 "" H 8980 5095 50  0001 C CNN
	1    8980 5095
	1    0    0    -1  
$EndComp
Wire Wire Line
	9130 5370 9130 4905
Wire Wire Line
	9650 5370 9650 5600
Wire Wire Line
	9650 5150 9650 5370
Connection ~ 9650 5370
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R96
U 1 1 5D9EB575
P 9550 5370
F 0 "R96" V 9354 5370 50  0000 C CNN
F 1 "200K" V 9445 5370 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 9550 5370 50  0001 C CNN
F 3 "" H 9550 5370 50  0001 C CNN
	1    9550 5370
	0    1    1    0   
$EndComp
Wire Wire Line
	9130 5370 9450 5370
Wire Wire Line
	8980 5055 8980 5095
Text GLabel 8980 4700 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR059
U 1 1 5D9EB57F
P 9900 4700
F 0 "#PWR059" H 9900 4550 50  0001 C CNN
F 1 "+3.3V" H 9915 4873 50  0000 C CNN
F 2 "" H 9900 4700 50  0001 C CNN
F 3 "" H 9900 4700 50  0001 C CNN
	1    9900 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 5050 10490 5050
Connection ~ 10300 5050
Text Label 10490 5050 1    60   ~ 0
modehf
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R13
U 1 1 5DBA2734
P 1345 4735
F 0 "R13" V 1149 4735 50  0000 C CNN
F 1 "10K" V 1240 4735 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1345 4735 50  0001 C CNN
F 3 "" H 1345 4735 50  0001 C CNN
	1    1345 4735
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R16
U 1 1 5DBA273B
P 1795 4385
F 0 "R16" H 2050 4340 50  0000 R CNN
F 1 "4K7" H 2035 4425 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 1795 4385 50  0001 C CNN
F 3 "" H 1795 4385 50  0001 C CNN
	1    1795 4385
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0138
U 1 1 5DBA2742
P 1795 4985
F 0 "#PWR0138" H 1795 4735 50  0001 C CNN
F 1 "GND" H 1800 4812 50  0000 C CNN
F 2 "" H 1795 4985 50  0001 C CNN
F 3 "" H 1795 4985 50  0001 C CNN
	1    1795 4985
	1    0    0    -1  
$EndComp
Wire Wire Line
	1445 4735 1495 4735
Wire Wire Line
	1795 4285 1795 4235
Wire Wire Line
	1795 4985 1795 4935
Wire Wire Line
	1205 4735 1245 4735
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q24
U 1 1 5DBAFC24
P 4370 5000
F 0 "Q24" H 4235 5150 50  0000 L CNN
F 1 "MMBT3904" H 4020 4850 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4570 5100 50  0001 C CNN
F 3 "" H 4370 5000 50  0001 C CNN
	1    4370 5000
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R15
U 1 1 5DBAFC2B
P 4020 5000
F 0 "R15" V 3824 5000 50  0000 C CNN
F 1 "10K" V 3915 5000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4020 5000 50  0001 C CNN
F 3 "" H 4020 5000 50  0001 C CNN
	1    4020 5000
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R18
U 1 1 5DBAFC32
P 4470 4650
F 0 "R18" H 4660 4710 50  0000 R CNN
F 1 "4K7" H 4665 4645 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 4470 4650 50  0001 C CNN
F 3 "" H 4470 4650 50  0001 C CNN
	1    4470 4650
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0140
U 1 1 5DBAFC39
P 4470 5250
F 0 "#PWR0140" H 4470 5000 50  0001 C CNN
F 1 "GND" H 4475 5077 50  0000 C CNN
F 2 "" H 4470 5250 50  0001 C CNN
F 3 "" H 4470 5250 50  0001 C CNN
	1    4470 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4120 5000 4170 5000
Wire Wire Line
	4470 4550 4470 4500
Wire Wire Line
	4470 5250 4470 5200
Wire Wire Line
	3880 5000 3920 5000
Text Label 10735 2190 0    60   ~ 0
modelf
Text Label 10730 2090 0    60   ~ 0
modehf
Text Label 10730 2290 0    60   ~ 0
speedhf
Text Label 10730 2390 0    60   ~ 0
speedlf
Text Label 9325 2490 2    60   ~ 0
pwmlf_out
Wire Wire Line
	9325 2490 9365 2490
Text Label 10705 2890 0    60   ~ 0
pwmhf_out
Wire Wire Line
	10665 2890 10705 2890
Wire Wire Line
	10730 2090 10665 2090
Wire Wire Line
	10735 2190 10665 2190
Wire Wire Line
	10730 2290 10665 2290
Wire Wire Line
	10665 2390 10730 2390
Text Label 9315 2590 2    60   ~ 0
pulselfclk_in
Wire Wire Line
	9315 2590 9365 2590
Text Label 9310 2690 2    60   ~ 0
pulself1_in
Wire Wire Line
	9310 2690 9365 2690
Text Label 9325 3390 2    60   ~ 0
pulself1_out
Wire Wire Line
	9325 3390 9365 3390
Text Label 9320 3490 2    60   ~ 0
pulself2_out
Wire Wire Line
	9320 3490 9365 3490
Text Label 9310 2790 2    60   ~ 0
pulsehfclk_in
Wire Wire Line
	9310 2790 9365 2790
Text Label 9315 3090 2    60   ~ 0
pulsehf1_in
Text Label 9335 1790 2    60   ~ 0
pulsehf2_out
Text Label 9340 1690 2    60   ~ 0
pulsehf1_out
Wire Wire Line
	9340 1690 9365 1690
Wire Wire Line
	9335 1790 9365 1790
$Comp
L power:+3.3V #PWR0142
U 1 1 5DD7AA32
P 9310 750
F 0 "#PWR0142" H 9310 600 50  0001 C CNN
F 1 "+3.3V" H 9325 923 50  0000 C CNN
F 2 "" H 9310 750 50  0001 C CNN
F 3 "" H 9310 750 50  0001 C CNN
	1    9310 750 
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R67
U 1 1 5DD7AC11
P 9310 890
F 0 "R67" H 9251 844 50  0000 R CNN
F 1 "10K" H 9251 935 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 9310 890 50  0001 C CNN
F 3 "" H 9310 890 50  0001 C CNN
	1    9310 890 
	-1   0    0    1   
$EndComp
Connection ~ 9310 990 
Wire Wire Line
	9310 790  9310 750 
$Comp
L allcolours-rescue:C-device-allcolours-rescue C2
U 1 1 5DD8BC28
P 9075 1040
F 0 "C2" V 9195 795 50  0000 C CNN
F 1 "100N" V 9230 960 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 9113 890 50  0001 C CNN
F 3 "" H 9075 1040 50  0001 C CNN
	1    9075 1040
	-1   0    0    1   
$EndComp
Wire Wire Line
	9310 1190 9075 1190
Connection ~ 9310 1190
Wire Wire Line
	9075 890  9235 890 
Wire Wire Line
	9235 890  9235 990 
Wire Wire Line
	9235 990  9310 990 
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R79
U 1 1 5D734406
P 1435 3305
F 0 "R79" V 1239 3305 50  0000 C CNN
F 1 "1M" V 1330 3305 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1435 3305 50  0001 C CNN
F 3 "" H 1435 3305 50  0001 C CNN
	1    1435 3305
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR041
U 1 1 5D7345E9
P 1435 3440
F 0 "#PWR041" H 1435 3190 50  0001 C CNN
F 1 "GND" H 1440 3267 50  0000 C CNN
F 2 "" H 1435 3440 50  0001 C CNN
F 3 "" H 1435 3440 50  0001 C CNN
	1    1435 3440
	1    0    0    -1  
$EndComp
Wire Wire Line
	1435 3405 1435 3440
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R91
U 1 1 5D741D88
P 2910 3230
F 0 "R91" V 2714 3230 50  0000 C CNN
F 1 "1M" V 2805 3230 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 2910 3230 50  0001 C CNN
F 3 "" H 2910 3230 50  0001 C CNN
	1    2910 3230
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR042
U 1 1 5D741D8F
P 2910 3380
F 0 "#PWR042" H 2910 3130 50  0001 C CNN
F 1 "GND" H 2915 3207 50  0000 C CNN
F 2 "" H 2910 3380 50  0001 C CNN
F 3 "" H 2910 3380 50  0001 C CNN
	1    2910 3380
	1    0    0    -1  
$EndComp
Wire Wire Line
	2910 3330 2910 3380
Wire Wire Line
	1435 3125 1435 3205
Connection ~ 1435 3125
Wire Wire Line
	1435 3125 1450 3125
Wire Wire Line
	2910 3110 2910 3130
Connection ~ 2910 3110
Wire Wire Line
	2910 3110 2930 3110
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R104
U 1 1 5D7BAF03
P 4340 3220
F 0 "R104" V 4160 3315 50  0000 C CNN
F 1 "1M" V 4235 3220 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4340 3220 50  0001 C CNN
F 3 "" H 4340 3220 50  0001 C CNN
	1    4340 3220
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR046
U 1 1 5D7BAF0A
P 4340 3355
F 0 "#PWR046" H 4340 3105 50  0001 C CNN
F 1 "GND" H 4345 3182 50  0000 C CNN
F 2 "" H 4340 3355 50  0001 C CNN
F 3 "" H 4340 3355 50  0001 C CNN
	1    4340 3355
	1    0    0    -1  
$EndComp
Wire Wire Line
	4340 3320 4340 3355
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R107
U 1 1 5D7C9266
P 5770 3175
F 0 "R107" V 5595 3270 50  0000 C CNN
F 1 "1M" V 5665 3175 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5770 3175 50  0001 C CNN
F 3 "" H 5770 3175 50  0001 C CNN
	1    5770 3175
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR049
U 1 1 5D7C926D
P 5770 3310
F 0 "#PWR049" H 5770 3060 50  0001 C CNN
F 1 "GND" H 5775 3137 50  0000 C CNN
F 2 "" H 5770 3310 50  0001 C CNN
F 3 "" H 5770 3310 50  0001 C CNN
	1    5770 3310
	1    0    0    -1  
$EndComp
Wire Wire Line
	5770 3275 5770 3310
Wire Wire Line
	5770 3045 5770 3075
Connection ~ 5770 3045
Wire Wire Line
	5770 3045 5790 3045
Wire Wire Line
	4340 3085 4340 3120
Connection ~ 4340 3085
Wire Wire Line
	4340 3085 4360 3085
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R106
U 1 1 5D8F3DD6
P 4600 4875
F 0 "R106" V 4430 5005 50  0000 C CNN
F 1 "3K3" V 4495 4875 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4600 4875 50  0001 C CNN
F 3 "" H 4600 4875 50  0001 C CNN
	1    4600 4875
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R86
U 1 1 5D903335
P 1910 4605
F 0 "R86" V 1710 4710 50  0000 C CNN
F 1 "3K3" V 1805 4605 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1910 4605 50  0001 C CNN
F 3 "" H 1910 4605 50  0001 C CNN
	1    1910 4605
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R83
U 1 1 5D913C1C
P 1810 1070
F 0 "R83" V 1614 1070 50  0000 C CNN
F 1 "1K" V 1705 1070 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1810 1070 50  0001 C CNN
F 3 "" H 1810 1070 50  0001 C CNN
	1    1810 1070
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R92
U 1 1 5D914056
P 3165 1130
F 0 "R92" V 2969 1130 50  0000 C CNN
F 1 "1K" V 3060 1130 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3165 1130 50  0001 C CNN
F 3 "" H 3165 1130 50  0001 C CNN
	1    3165 1130
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R105
U 1 1 5D914150
P 4550 1115
F 0 "R105" V 4354 1115 50  0000 C CNN
F 1 "1K" V 4445 1115 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4550 1115 50  0001 C CNN
F 3 "" H 4550 1115 50  0001 C CNN
	1    4550 1115
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R108
U 1 1 5D914244
P 5860 1160
F 0 "R108" V 5664 1160 50  0000 C CNN
F 1 "1K" V 5755 1160 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5860 1160 50  0001 C CNN
F 3 "" H 5860 1160 50  0001 C CNN
F 4 "TEST" H 5860 1160 50  0001 C CNN "Manufacturer"
	1    5860 1160
	-1   0    0    1   
$EndComp
Wire Wire Line
	7330 2565 7330 2530
Connection ~ 7600 2530
Wire Wire Line
	7330 2530 7600 2530
$Comp
L Device:CP1_Small C54
U 1 1 5D488603
P 7330 2665
F 0 "C54" H 7325 2885 50  0000 L CNN
F 1 "10u" H 7421 2620 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 7330 2665 50  0001 C CNN
F 3 "~" H 7330 2665 50  0001 C CNN
F 4 "" H 7330 2665 50  0000 C CNN "Description"
	1    7330 2665
	1    0    0    -1  
$EndComp
Wire Wire Line
	7330 2765 7330 2830
Connection ~ 7600 2830
Wire Wire Line
	7330 2830 7600 2830
Text Notes 7070 3275 0    71   ~ 0
10u and 100n vdda/vssa \nrest per each vdd
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C21
U 1 1 5D578993
P 10715 5115
F 0 "C21" H 10623 5069 50  0000 R CNN
F 1 "100N" H 10623 5160 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 10715 5115 50  0001 C CNN
F 3 "" H 10715 5115 50  0001 C CNN
	1    10715 5115
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR072
U 1 1 5D57899A
P 10715 5265
F 0 "#PWR072" H 10715 5015 50  0001 C CNN
F 1 "GND" H 10720 5092 50  0000 C CNN
F 2 "" H 10715 5265 50  0001 C CNN
F 3 "" H 10715 5265 50  0001 C CNN
	1    10715 5265
	1    0    0    -1  
$EndComp
Wire Wire Line
	10715 5215 10715 5265
Wire Wire Line
	10715 4965 10715 5015
$Comp
L power:+3.3V #PWR071
U 1 1 5D5789A2
P 10715 4965
F 0 "#PWR071" H 10715 4815 50  0001 C CNN
F 1 "+3.3V" H 10730 5138 50  0000 C CNN
F 2 "" H 10715 4965 50  0001 C CNN
F 3 "" H 10715 4965 50  0001 C CNN
	1    10715 4965
	1    0    0    -1  
$EndComp
Wire Wire Line
	1795 4485 1795 4505
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q23
U 1 1 5DBA272D
P 1695 4735
F 0 "Q23" H 1615 4900 50  0000 L CNN
F 1 "MMBT3904" H 1345 4585 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1895 4835 50  0001 C CNN
F 3 "" H 1695 4735 50  0001 C CNN
	1    1695 4735
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0114
U 1 1 5D6A341F
P 1910 4740
F 0 "#PWR0114" H 1910 4490 50  0001 C CNN
F 1 "GND" H 1915 4567 50  0000 C CNN
F 2 "" H 1910 4740 50  0001 C CNN
F 3 "" H 1910 4740 50  0001 C CNN
	1    1910 4740
	1    0    0    -1  
$EndComp
Wire Wire Line
	1795 4505 1910 4505
Connection ~ 1795 4505
Wire Wire Line
	1795 4505 1795 4535
Wire Wire Line
	1910 4505 1970 4505
Connection ~ 1910 4505
Wire Wire Line
	1910 4705 1910 4740
Wire Wire Line
	4470 4750 4470 4775
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0115
U 1 1 5D6DF621
P 4600 5010
F 0 "#PWR0115" H 4600 4760 50  0001 C CNN
F 1 "GND" H 4605 4837 50  0000 C CNN
F 2 "" H 4600 5010 50  0001 C CNN
F 3 "" H 4600 5010 50  0001 C CNN
	1    4600 5010
	1    0    0    -1  
$EndComp
Wire Wire Line
	4470 4775 4600 4775
Connection ~ 4470 4775
Wire Wire Line
	4470 4775 4470 4800
Wire Wire Line
	4600 4775 4660 4775
Connection ~ 4600 4775
Wire Wire Line
	4600 4975 4600 5010
Wire Wire Line
	9315 3090 9365 3090
$Comp
L power:+12V #PWR0139
U 1 1 5E1F7C75
P 1675 690
F 0 "#PWR0139" H 1675 540 50  0001 C CNN
F 1 "+12V" H 1690 863 50  0000 C CNN
F 2 "" H 1675 690 50  0001 C CNN
F 3 "" H 1675 690 50  0001 C CNN
	1    1675 690 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0141
U 1 1 5E1F7F46
P 3020 750
F 0 "#PWR0141" H 3020 600 50  0001 C CNN
F 1 "+12V" H 3035 923 50  0000 C CNN
F 2 "" H 3020 750 50  0001 C CNN
F 3 "" H 3020 750 50  0001 C CNN
	1    3020 750 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0150
U 1 1 5E1F7FEB
P 4405 735
F 0 "#PWR0150" H 4405 585 50  0001 C CNN
F 1 "+12V" H 4420 908 50  0000 C CNN
F 2 "" H 4405 735 50  0001 C CNN
F 3 "" H 4405 735 50  0001 C CNN
	1    4405 735 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0167
U 1 1 5E1F812A
P 5750 780
F 0 "#PWR0167" H 5750 630 50  0001 C CNN
F 1 "+12V" H 5765 953 50  0000 C CNN
F 2 "" H 5750 780 50  0001 C CNN
F 3 "" H 5750 780 50  0001 C CNN
	1    5750 780 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0168
U 1 1 5E1F8352
P 1795 4235
F 0 "#PWR0168" H 1795 4085 50  0001 C CNN
F 1 "+12V" H 1810 4408 50  0000 C CNN
F 2 "" H 1795 4235 50  0001 C CNN
F 3 "" H 1795 4235 50  0001 C CNN
	1    1795 4235
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0169
U 1 1 5E1F8837
P 4470 4500
F 0 "#PWR0169" H 4470 4350 50  0001 C CNN
F 1 "+12V" H 4485 4673 50  0000 C CNN
F 2 "" H 4470 4500 50  0001 C CNN
F 3 "" H 4470 4500 50  0001 C CNN
	1    4470 4500
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR019
U 1 1 5E2930F7
P 1810 1210
F 0 "#PWR019" H 1810 960 50  0001 C CNN
F 1 "GND" H 1815 1037 50  0000 C CNN
F 2 "" H 1810 1210 50  0001 C CNN
F 3 "" H 1810 1210 50  0001 C CNN
	1    1810 1210
	1    0    0    -1  
$EndComp
Wire Wire Line
	1675 970  1810 970 
Wire Wire Line
	1810 970  1955 970 
Connection ~ 1810 970 
Wire Wire Line
	1810 1170 1810 1210
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR023
U 1 1 5E2D2B1C
P 4550 1250
F 0 "#PWR023" H 4550 1000 50  0001 C CNN
F 1 "GND" H 4555 1077 50  0000 C CNN
F 2 "" H 4550 1250 50  0001 C CNN
F 3 "" H 4550 1250 50  0001 C CNN
	1    4550 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4405 1015 4550 1015
Wire Wire Line
	4550 1015 4685 1015
Connection ~ 4550 1015
Wire Wire Line
	4550 1215 4550 1250
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR026
U 1 1 5E3037BB
P 5860 1295
F 0 "#PWR026" H 5860 1045 50  0001 C CNN
F 1 "GND" H 5865 1122 50  0000 C CNN
F 2 "" H 5860 1295 50  0001 C CNN
F 3 "" H 5860 1295 50  0001 C CNN
	1    5860 1295
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 1060 5860 1060
Wire Wire Line
	5860 1060 6030 1060
Connection ~ 5860 1060
Wire Wire Line
	5860 1260 5860 1295
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR021
U 1 1 5E334B2E
P 3165 1270
F 0 "#PWR021" H 3165 1020 50  0001 C CNN
F 1 "GND" H 3170 1097 50  0000 C CNN
F 2 "" H 3165 1270 50  0001 C CNN
F 3 "" H 3165 1270 50  0001 C CNN
	1    3165 1270
	1    0    0    -1  
$EndComp
Wire Wire Line
	3020 1030 3165 1030
Wire Wire Line
	3165 1030 3300 1030
Connection ~ 3165 1030
Wire Wire Line
	3165 1230 3165 1270
Text Notes -905 3400 0    79   ~ 0
Leave as optional 1M pull downs
$EndSCHEMATC
