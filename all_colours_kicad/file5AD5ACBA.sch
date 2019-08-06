EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
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
F 0 "C3" V 7763 2680 50  0000 C CNN
F 1 "100N" V 7854 2680 50  0000 C CNN
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
F 0 "R10" H 1616 794 50  0000 R CNN
F 1 "10K" H 1616 885 50  0000 R CNN
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
pulses in - 4x - 2x LF 2x HF inc. 1each clock in\ninverted (doesn't matter)
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q4
U 1 1 5B703499
P 1650 3125
F 0 "Q4" H 1841 3171 50  0000 L CNN
F 1 "MMBT3904" H 1300 2975 50  0000 L CNN
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
Text Notes 2990 5815 0    118  ~ 0
CV IN  x4 =speedl, speedh, model, modeh=just_pots
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U7
U 1 1 5B77CFF8
P 5120 6590
F 0 "U7" H 5175 6730 50  0000 L CNN
F 1 "MCP6002" H 5120 6490 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 5120 6590 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5120 6590 50  0001 C CNN
	1    5120 6590
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR066
U 1 1 5B77CFFE
P 5020 6940
F 0 "#PWR066" H 5020 6690 50  0001 C CNN
F 1 "GND" H 5155 6885 50  0000 C CNN
F 2 "" H 5020 6940 50  0001 C CNN
F 3 "" H 5020 6940 50  0001 C CNN
	1    5020 6940
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R38
U 1 1 5B77D00A
P 4670 6690
F 0 "R38" V 4474 6690 50  0000 C CNN
F 1 "100K" V 4575 6610 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4670 6690 50  0001 C CNN
F 3 "" H 4670 6690 50  0001 C CNN
	1    4670 6690
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R39
U 1 1 5B77D010
P 5070 7140
F 0 "R39" V 4990 7270 50  0000 C CNN
F 1 "66.5K" V 5120 7335 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5070 7140 50  0001 C CNN
F 3 "" H 5070 7140 50  0001 C CNN
	1    5070 7140
	0    1    1    0   
$EndComp
Wire Wire Line
	5020 6290 5020 6240
Wire Wire Line
	4770 6690 4820 6690
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR064
U 1 1 5B77D02A
P 4770 6490
F 0 "#PWR064" H 4770 6240 50  0001 C CNN
F 1 "GND" H 4775 6317 50  0000 C CNN
F 2 "" H 4770 6490 50  0001 C CNN
F 3 "" H 4770 6490 50  0001 C CNN
	1    4770 6490
	1    0    0    -1  
$EndComp
Wire Wire Line
	4770 6490 4820 6490
Wire Wire Line
	5020 6940 5020 6890
Wire Wire Line
	4770 7140 4970 7140
Connection ~ 4770 6690
Wire Wire Line
	5170 7140 5420 7140
Wire Wire Line
	5420 7140 5420 6590
Connection ~ 4770 7140
Wire Wire Line
	4470 6690 4570 6690
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C27
U 1 1 5B77D048
P 5070 7340
F 0 "C27" V 5125 7460 50  0000 C CNN
F 1 "1nF" V 5185 7345 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 5070 7340 50  0001 C CNN
F 3 "" H 5070 7340 50  0001 C CNN
	1    5070 7340
	0    1    1    0   
$EndComp
Wire Wire Line
	4770 7140 4770 7340
Wire Wire Line
	4770 7340 4970 7340
Wire Wire Line
	5170 7340 5420 7340
Wire Wire Line
	5420 7340 5420 7140
Connection ~ 5420 7140
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C28
U 1 1 5B77D053
P 5900 7150
F 0 "C28" H 5808 7104 50  0000 R CNN
F 1 "100nF" H 5808 7195 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805" H 5900 7150 50  0001 C CNN
F 3 "" H 5900 7150 50  0001 C CNN
	1    5900 7150
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR069
U 1 1 5B77D05F
P 5900 7300
F 0 "#PWR069" H 5900 7050 50  0001 C CNN
F 1 "GND" H 5905 7127 50  0000 C CNN
F 2 "" H 5900 7300 50  0001 C CNN
F 3 "" H 5900 7300 50  0001 C CNN
	1    5900 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 7250 5900 7300
Wire Wire Line
	5900 7000 5900 7050
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
F 0 "C30" V 7568 2680 50  0000 C CNN
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
F 0 "C31" V 7983 2670 50  0000 C CNN
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
Text Notes 1220 6110 0    157  ~ 0
PWM out hf\n
$Comp
L Device:R_POT speedlf1
U 1 1 5D2C66BC
P 4100 6445
F 0 "speedlf1" H 4030 6491 50  0000 R CNN
F 1 "10K" H 4030 6400 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 4100 6445 50  0001 C CNN
F 3 "~" H 4100 6445 50  0001 C CNN
	1    4100 6445
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 6240 4100 6295
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0136
U 1 1 5D2CAEA0
P 4100 6635
F 0 "#PWR0136" H 4100 6385 50  0001 C CNN
F 1 "GND" H 4105 6462 50  0000 C CNN
F 2 "" H 4100 6635 50  0001 C CNN
F 3 "" H 4100 6635 50  0001 C CNN
	1    4100 6635
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 6910 4250 6445
Wire Wire Line
	4770 6910 4770 7140
Wire Wire Line
	4770 6690 4770 6910
Connection ~ 4770 6910
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R85
U 1 1 5D2CADCC
P 4670 6910
F 0 "R85" V 4474 6910 50  0000 C CNN
F 1 "200K" V 4565 6910 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4670 6910 50  0001 C CNN
F 3 "" H 4670 6910 50  0001 C CNN
	1    4670 6910
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 6910 4570 6910
Wire Wire Line
	4100 6595 4100 6635
Text Notes 3855 7735 0    157  ~ 0
0-5v in
Text Notes 4110 3955 0    118  ~ 0
4 bit DAC - x1 with  buffer - lf only \n- hf is pulse again
Text GLabel 4100 6240 0    60   Input ~ 0
AREF-10
Text Notes 1055 4425 0    157  ~ 0
PWM out lf 
Text GLabel 1810 6690 2    79   Input ~ 0
PWMHF_OUT
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R76
U 1 1 5D2C97F0
P 3905 4670
F 0 "R76" V 3840 4685 50  0000 C CNN
F 1 "10K" V 3905 4665 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3905 4670 50  0001 C CNN
F 3 "" H 3905 4670 50  0001 C CNN
	1    3905 4670
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R77
U 1 1 5D2C9934
P 3905 4750
F 0 "R77" V 3965 4870 50  0000 C CNN
F 1 "22K" V 3910 4750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3905 4750 50  0001 C CNN
F 3 "" H 3905 4750 50  0001 C CNN
	1    3905 4750
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R78
U 1 1 5D2C99B0
P 3905 4830
F 0 "R78" V 3955 4950 50  0000 C CNN
F 1 "47K" V 3910 4830 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3905 4830 50  0001 C CNN
F 3 "" H 3905 4830 50  0001 C CNN
	1    3905 4830
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R79
U 1 1 5D2C9A86
P 3905 4915
F 0 "R79" V 3980 4935 50  0000 C CNN
F 1 "100K" V 3905 4915 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 3905 4915 50  0001 C CNN
F 3 "" H 3905 4915 50  0001 C CNN
	1    3905 4915
	0    1    1    0   
$EndComp
Wire Wire Line
	4005 4670 4005 4750
Wire Wire Line
	4005 4750 4005 4790
Connection ~ 4005 4750
Wire Wire Line
	4005 4830 4005 4915
Connection ~ 4005 4830
Wire Wire Line
	4005 4790 4130 4790
Connection ~ 4005 4790
Wire Wire Line
	4005 4790 4005 4830
$Comp
L Amplifier_Operational:TL082 U9
U 2 1 5D2E6C2C
P 4500 4690
F 0 "U9" H 4500 5057 50  0000 C CNN
F 1 "TL082" H 4500 4966 50  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 4500 4690 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 4500 4690 50  0001 C CNN
	2    4500 4690
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0137
U 1 1 5D2E6EFF
P 4145 4590
F 0 "#PWR0137" H 4145 4340 50  0001 C CNN
F 1 "GND" H 4145 4590 50  0000 C CNN
F 2 "" H 4145 4590 50  0001 C CNN
F 3 "" H 4145 4590 50  0001 C CNN
	1    4145 4590
	1    0    0    -1  
$EndComp
Wire Wire Line
	4145 4590 4200 4590
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R83
U 1 1 5D2EBE2D
P 4505 4930
F 0 "R83" V 4440 4945 50  0000 C CNN
F 1 "10K" V 4505 4925 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4505 4930 50  0001 C CNN
F 3 "" H 4505 4930 50  0001 C CNN
	1    4505 4930
	0    1    1    0   
$EndComp
Wire Wire Line
	4130 4790 4130 4930
Wire Wire Line
	4130 4930 4405 4930
Connection ~ 4130 4790
Wire Wire Line
	4130 4790 4200 4790
Wire Wire Line
	4605 4930 4800 4930
Wire Wire Line
	4800 4930 4800 4690
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R86
U 1 1 5D2F5E40
P 4925 4690
F 0 "R86" V 4729 4690 50  0000 C CNN
F 1 "1K" V 4820 4690 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 4925 4690 50  0001 C CNN
F 3 "" H 4925 4690 50  0001 C CNN
	1    4925 4690
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 4690 4825 4690
Connection ~ 4800 4690
Text GLabel 1810 5020 2    79   Input ~ 0
PWMLF_OUT
$Comp
L power:+10V #PWR0150
U 1 1 5D33EE6E
P 1675 690
F 0 "#PWR0150" H 1675 540 50  0001 C CNN
F 1 "+10V" H 1690 863 50  0000 C CNN
F 2 "" H 1675 690 50  0001 C CNN
F 3 "" H 1675 690 50  0001 C CNN
	1    1675 690 
	1    0    0    -1  
$EndComp
$Comp
L MCU_ST_STM32F1:STM32F103CBTx U16
U 1 1 5D418906
P 10065 2290
F 0 "U16" H 10040 1170 50  0000 C CNN
F 1 "STM32F103CBTx" H 10025 2070 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 9465 890 50  0001 R CNN
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
P 5020 6240
F 0 "#PWR0153" H 5020 6090 50  0001 C CNN
F 1 "+3.3V" H 5035 6413 50  0000 C CNN
F 2 "" H 5020 6240 50  0001 C CNN
F 3 "" H 5020 6240 50  0001 C CNN
	1    5020 6240
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0154
U 1 1 5D431538
P 5900 7000
F 0 "#PWR0154" H 5900 6850 50  0001 C CNN
F 1 "+3.3V" H 5915 7173 50  0000 C CNN
F 2 "" H 5900 7000 50  0001 C CNN
F 3 "" H 5900 7000 50  0001 C CNN
	1    5900 7000
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
F 0 "C57" V 7348 2680 50  0000 C CNN
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
$Comp
L Device:CP1_Small C54
U 1 1 5D488603
P 7330 2665
F 0 "C54" H 7421 2711 50  0000 L CNN
F 1 "4.7UF" H 7421 2620 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 7330 2665 50  0001 C CNN
F 3 "~" H 7330 2665 50  0001 C CNN
	1    7330 2665
	1    0    0    -1  
$EndComp
Wire Wire Line
	7330 2565 7330 2530
Wire Wire Line
	7330 2530 7600 2530
Connection ~ 7600 2530
Wire Wire Line
	7330 2765 7330 2830
Wire Wire Line
	7330 2830 7600 2830
Connection ~ 7600 2830
$Comp
L Device:CP1_Small C53
U 1 1 5D49B912
P 7140 2670
F 0 "C53" H 7231 2716 50  0000 L CNN
F 1 "1uF" H 7231 2625 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 7140 2670 50  0001 C CNN
F 3 "~" H 7140 2670 50  0001 C CNN
	1    7140 2670
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C52
U 1 1 5D49BA6E
P 6965 2670
F 0 "C52" H 7056 2716 50  0000 L CNN
F 1 "1uF" H 7056 2625 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 6965 2670 50  0001 C CNN
F 3 "~" H 6965 2670 50  0001 C CNN
	1    6965 2670
	1    0    0    -1  
$EndComp
Wire Wire Line
	6965 2570 7140 2570
Wire Wire Line
	7140 2570 7210 2570
Wire Wire Line
	7210 2570 7210 2530
Wire Wire Line
	7210 2530 7330 2530
Connection ~ 7140 2570
Connection ~ 7330 2530
Wire Wire Line
	6965 2770 7140 2770
Wire Wire Line
	7140 2770 7140 2830
Wire Wire Line
	7140 2830 7330 2830
Connection ~ 7140 2770
Connection ~ 7330 2830
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
Text GLabel 1720 970  2    60   Input ~ 0
PULSELF1_OUT
Text Label 1085 1190 2    60   ~ 0
pulself1_out
Wire Wire Line
	1085 1190 1125 1190
Wire Wire Line
	1675 940  1675 970 
Text GLabel 1180 3125 0    60   Input ~ 0
PULSELF1_IN
Text Label 1175 5240 1    60   ~ 0
pwmlf_out
Text Label 1175 6910 1    60   ~ 0
pwmhf_out
Text GLabel 5065 4690 2    79   Input ~ 0
DACLF_OUT
Wire Wire Line
	5025 4690 5065 4690
Text Label 3765 4670 2    39   ~ 0
dac0
Text Label 3765 4750 2    39   ~ 0
dac1
Text Label 3765 4830 2    39   ~ 0
dac2
Text Label 3760 4915 2    39   ~ 0
dac3
Wire Wire Line
	3765 4670 3805 4670
Wire Wire Line
	3765 4750 3805 4750
Wire Wire Line
	3765 4830 3805 4830
Wire Wire Line
	3760 4915 3805 4915
Wire Wire Line
	1675 970  1720 970 
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
F 0 "R74" H 2961 854 50  0000 R CNN
F 1 "10K" H 2961 945 50  0000 R CNN
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
$Comp
L power:+10V #PWR027
U 1 1 5D7EE2A0
P 3020 750
F 0 "#PWR027" H 3020 600 50  0001 C CNN
F 1 "+10V" H 3035 923 50  0000 C CNN
F 2 "" H 3020 750 50  0001 C CNN
F 3 "" H 3020 750 50  0001 C CNN
	1    3020 750 
	1    0    0    -1  
$EndComp
Text GLabel 3065 1030 2    60   Input ~ 0
PULSELF2_OUT
Text Label 2430 1250 2    60   ~ 0
pulself2_out
Wire Wire Line
	2430 1250 2470 1250
Wire Wire Line
	3020 1000 3020 1030
Wire Wire Line
	3020 1030 3065 1030
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
F 0 "R80" V 3759 1235 50  0000 C CNN
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
F 0 "R82" H 4346 839 50  0000 R CNN
F 1 "10K" H 4346 930 50  0000 R CNN
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
$Comp
L power:+10V #PWR032
U 1 1 5D7FBE9C
P 4405 735
F 0 "#PWR032" H 4405 585 50  0001 C CNN
F 1 "+10V" H 4420 908 50  0000 C CNN
F 2 "" H 4405 735 50  0001 C CNN
F 3 "" H 4405 735 50  0001 C CNN
	1    4405 735 
	1    0    0    -1  
$EndComp
Text GLabel 4450 1015 2    60   Input ~ 0
PULSEHF1_OUT
Text Label 3815 1235 2    60   ~ 0
pulsehf1_out
Wire Wire Line
	3815 1235 3855 1235
Wire Wire Line
	4405 985  4405 1015
Wire Wire Line
	4405 1015 4450 1015
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
F 0 "R87" V 5104 1280 50  0000 C CNN
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
F 0 "R89" H 5691 884 50  0000 R CNN
F 1 "10K" H 5691 975 50  0000 R CNN
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
$Comp
L power:+10V #PWR036
U 1 1 5D80A93E
P 5750 780
F 0 "#PWR036" H 5750 630 50  0001 C CNN
F 1 "+10V" H 5765 953 50  0000 C CNN
F 2 "" H 5750 780 50  0001 C CNN
F 3 "" H 5750 780 50  0001 C CNN
	1    5750 780 
	1    0    0    -1  
$EndComp
Text GLabel 5795 1060 2    60   Input ~ 0
PULSEHF2_OUT
Text Label 5160 1280 2    60   ~ 0
pulsehf2_out
Wire Wire Line
	5160 1280 5200 1280
Wire Wire Line
	5750 1030 5750 1060
Wire Wire Line
	5750 1060 5795 1060
Connection ~ 5750 1060
Wire Wire Line
	5750 1060 5750 1080
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q14
U 1 1 5D81A176
P 6995 1595
F 0 "Q14" H 7186 1641 50  0000 L CNN
F 1 "MMBT3904" H 6645 1445 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7195 1695 50  0001 C CNN
F 3 "" H 6995 1595 50  0001 C CNN
	1    6995 1595
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R91
U 1 1 5D81A17D
P 6645 1595
F 0 "R91" V 6449 1595 50  0000 C CNN
F 1 "10K" V 6540 1595 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 6645 1595 50  0001 C CNN
F 3 "" H 6645 1595 50  0001 C CNN
	1    6645 1595
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R92
U 1 1 5D81A184
P 7095 1245
F 0 "R92" H 7036 1199 50  0000 R CNN
F 1 "10K" H 7036 1290 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 7095 1245 50  0001 C CNN
F 3 "" H 7095 1245 50  0001 C CNN
	1    7095 1245
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR046
U 1 1 5D81A18B
P 7095 1845
F 0 "#PWR046" H 7095 1595 50  0001 C CNN
F 1 "GND" H 7100 1672 50  0000 C CNN
F 2 "" H 7095 1845 50  0001 C CNN
F 3 "" H 7095 1845 50  0001 C CNN
	1    7095 1845
	1    0    0    -1  
$EndComp
Wire Wire Line
	6745 1595 6795 1595
Wire Wire Line
	7095 1145 7095 1095
Wire Wire Line
	7095 1845 7095 1795
$Comp
L power:+10V #PWR042
U 1 1 5D81A194
P 7095 1095
F 0 "#PWR042" H 7095 945 50  0001 C CNN
F 1 "+10V" H 7110 1268 50  0000 C CNN
F 2 "" H 7095 1095 50  0001 C CNN
F 3 "" H 7095 1095 50  0001 C CNN
	1    7095 1095
	1    0    0    -1  
$EndComp
Text GLabel 7140 1375 2    60   Input ~ 0
PULSEHF3_OUT
Text Label 6505 1595 2    60   ~ 0
pulsehf3_out
Wire Wire Line
	6505 1595 6545 1595
Wire Wire Line
	7095 1345 7095 1375
Wire Wire Line
	7095 1375 7140 1375
Connection ~ 7095 1375
Wire Wire Line
	7095 1375 7095 1395
Wire Wire Line
	1410 3125 1450 3125
Wire Wire Line
	1180 3125 1210 3125
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q9
U 1 1 5D86E162
P 3130 3110
F 0 "Q9" H 3321 3156 50  0000 L CNN
F 1 "MMBT3904" H 2780 2960 50  0000 L CNN
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
F 0 "R75" H 3171 2714 50  0000 R CNN
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
	2890 3110 2930 3110
Wire Wire Line
	2660 3110 2690 3110
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q11
U 1 1 5D87F76B
P 4560 3085
F 0 "Q11" H 4751 3131 50  0000 L CNN
F 1 "MMBT3904" H 4210 2935 50  0000 L CNN
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
F 0 "R84" H 4601 2689 50  0000 R CNN
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
	4320 3085 4360 3085
Wire Wire Line
	4090 3085 4120 3085
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q13
U 1 1 5D891B73
P 5990 3045
F 0 "Q13" H 6181 3091 50  0000 L CNN
F 1 "MMBT3904" H 5640 2895 50  0000 L CNN
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
	5750 3045 5790 3045
Wire Wire Line
	5520 3045 5550 3045
Text GLabel 4470 6690 1    79   Input ~ 0
SPEEDLF_IN
Wire Wire Line
	5420 6590 5610 6590
Connection ~ 5420 6590
Text Label 5610 6590 1    60   ~ 0
speedlf
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U7
U 2 1 5D95A424
P 8180 4785
F 0 "U7" H 8235 4925 50  0000 L CNN
F 1 "MCP6002" H 8180 4685 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 8180 4785 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 8180 4785 50  0001 C CNN
	2    8180 4785
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR052
U 1 1 5D95A42B
P 8080 5135
F 0 "#PWR052" H 8080 4885 50  0001 C CNN
F 1 "GND" H 8215 5080 50  0000 C CNN
F 2 "" H 8080 5135 50  0001 C CNN
F 3 "" H 8080 5135 50  0001 C CNN
	1    8080 5135
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R93
U 1 1 5D95A431
P 7730 4885
F 0 "R93" V 7534 4885 50  0000 C CNN
F 1 "100K" V 7635 4805 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7730 4885 50  0001 C CNN
F 3 "" H 7730 4885 50  0001 C CNN
	1    7730 4885
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R95
U 1 1 5D95A438
P 8130 5335
F 0 "R95" V 8050 5465 50  0000 C CNN
F 1 "66.5K" V 8180 5530 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 8130 5335 50  0001 C CNN
F 3 "" H 8130 5335 50  0001 C CNN
	1    8130 5335
	0    1    1    0   
$EndComp
Wire Wire Line
	8080 4485 8080 4435
Wire Wire Line
	7830 4885 7880 4885
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR050
U 1 1 5D95A441
P 7830 4685
F 0 "#PWR050" H 7830 4435 50  0001 C CNN
F 1 "GND" H 7835 4512 50  0000 C CNN
F 2 "" H 7830 4685 50  0001 C CNN
F 3 "" H 7830 4685 50  0001 C CNN
	1    7830 4685
	1    0    0    -1  
$EndComp
Wire Wire Line
	7830 4685 7880 4685
Wire Wire Line
	8080 5135 8080 5085
Wire Wire Line
	7830 5335 8030 5335
Connection ~ 7830 4885
Wire Wire Line
	8230 5335 8480 5335
Wire Wire Line
	8480 5335 8480 4785
Connection ~ 7830 5335
Wire Wire Line
	7530 4885 7630 4885
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C58
U 1 1 5D95A44F
P 8130 5535
F 0 "C58" V 8185 5655 50  0000 C CNN
F 1 "1nF" V 8245 5540 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 8130 5535 50  0001 C CNN
F 3 "" H 8130 5535 50  0001 C CNN
	1    8130 5535
	0    1    1    0   
$EndComp
Wire Wire Line
	7830 5335 7830 5535
Wire Wire Line
	7830 5535 8030 5535
Wire Wire Line
	8230 5535 8480 5535
Wire Wire Line
	8480 5535 8480 5335
Connection ~ 8480 5335
$Comp
L Device:R_POT speedhf1
U 1 1 5D95A45B
P 7160 4640
F 0 "speedhf1" H 7090 4686 50  0000 R CNN
F 1 "10K" H 7090 4595 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 7160 4640 50  0001 C CNN
F 3 "~" H 7160 4640 50  0001 C CNN
	1    7160 4640
	1    0    0    -1  
$EndComp
Wire Wire Line
	7160 4435 7160 4490
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR048
U 1 1 5D95A463
P 7160 4830
F 0 "#PWR048" H 7160 4580 50  0001 C CNN
F 1 "GND" H 7165 4657 50  0000 C CNN
F 2 "" H 7160 4830 50  0001 C CNN
F 3 "" H 7160 4830 50  0001 C CNN
	1    7160 4830
	1    0    0    -1  
$EndComp
Wire Wire Line
	7310 5105 7310 4640
Wire Wire Line
	7830 5105 7830 5335
Wire Wire Line
	7830 4885 7830 5105
Connection ~ 7830 5105
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R94
U 1 1 5D95A46D
P 7730 5105
F 0 "R94" V 7534 5105 50  0000 C CNN
F 1 "200K" V 7625 5105 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 7730 5105 50  0001 C CNN
F 3 "" H 7730 5105 50  0001 C CNN
	1    7730 5105
	0    1    1    0   
$EndComp
Wire Wire Line
	7310 5105 7630 5105
Wire Wire Line
	7160 4790 7160 4830
Text GLabel 7160 4435 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR051
U 1 1 5D95A477
P 8080 4435
F 0 "#PWR051" H 8080 4285 50  0001 C CNN
F 1 "+3.3V" H 8095 4608 50  0000 C CNN
F 2 "" H 8080 4435 50  0001 C CNN
F 3 "" H 8080 4435 50  0001 C CNN
	1    8080 4435
	1    0    0    -1  
$EndComp
Text GLabel 7530 4885 1    79   Input ~ 0
SPEEDHF_IN
Wire Wire Line
	8480 4785 8670 4785
Connection ~ 8480 4785
Text Label 8670 4785 1    60   ~ 0
speedhf
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U17
U 2 1 5D971703
P 10350 4840
F 0 "U17" H 10405 4980 50  0000 L CNN
F 1 "MCP6002" H 10350 4740 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 10350 4840 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 10350 4840 50  0001 C CNN
	2    10350 4840
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR062
U 1 1 5D97170A
P 10250 5190
F 0 "#PWR062" H 10250 4940 50  0001 C CNN
F 1 "GND" H 10385 5135 50  0000 C CNN
F 2 "" H 10250 5190 50  0001 C CNN
F 3 "" H 10250 5190 50  0001 C CNN
	1    10250 5190
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R99
U 1 1 5D971717
P 10300 5390
F 0 "R99" V 10220 5520 50  0000 C CNN
F 1 "66.5K" V 10350 5585 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 10300 5390 50  0001 C CNN
F 3 "" H 10300 5390 50  0001 C CNN
	1    10300 5390
	0    1    1    0   
$EndComp
Wire Wire Line
	10250 4540 10250 4490
Wire Wire Line
	10000 4940 10050 4940
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR057
U 1 1 5D971720
P 10000 4740
F 0 "#PWR057" H 10000 4490 50  0001 C CNN
F 1 "GND" H 10005 4567 50  0000 C CNN
F 2 "" H 10000 4740 50  0001 C CNN
F 3 "" H 10000 4740 50  0001 C CNN
	1    10000 4740
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 4740 10050 4740
Wire Wire Line
	10250 5190 10250 5140
Wire Wire Line
	10000 5390 10200 5390
Wire Wire Line
	10400 5390 10650 5390
Wire Wire Line
	10650 5390 10650 4840
Connection ~ 10000 5390
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C62
U 1 1 5D97172E
P 10300 5590
F 0 "C62" V 10355 5710 50  0000 C CNN
F 1 "1nF" V 10415 5595 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 10300 5590 50  0001 C CNN
F 3 "" H 10300 5590 50  0001 C CNN
	1    10300 5590
	0    1    1    0   
$EndComp
Wire Wire Line
	10000 5390 10000 5590
Wire Wire Line
	10000 5590 10200 5590
Wire Wire Line
	10400 5590 10650 5590
Wire Wire Line
	10650 5590 10650 5390
Connection ~ 10650 5390
$Comp
L Device:R_POT modelf1
U 1 1 5D97173A
P 9330 4695
F 0 "modelf1" H 9260 4741 50  0000 R CNN
F 1 "10K" H 9260 4650 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 9330 4695 50  0001 C CNN
F 3 "~" H 9330 4695 50  0001 C CNN
	1    9330 4695
	1    0    0    -1  
$EndComp
Wire Wire Line
	9330 4490 9330 4545
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR054
U 1 1 5D971742
P 9330 4885
F 0 "#PWR054" H 9330 4635 50  0001 C CNN
F 1 "GND" H 9335 4712 50  0000 C CNN
F 2 "" H 9330 4885 50  0001 C CNN
F 3 "" H 9330 4885 50  0001 C CNN
	1    9330 4885
	1    0    0    -1  
$EndComp
Wire Wire Line
	9480 5160 9480 4695
Wire Wire Line
	10000 5160 10000 5390
Wire Wire Line
	10000 4940 10000 5160
Connection ~ 10000 5160
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R97
U 1 1 5D97174C
P 9900 5160
F 0 "R97" V 9704 5160 50  0000 C CNN
F 1 "200K" V 9795 5160 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 9900 5160 50  0001 C CNN
F 3 "" H 9900 5160 50  0001 C CNN
	1    9900 5160
	0    1    1    0   
$EndComp
Wire Wire Line
	9480 5160 9800 5160
Wire Wire Line
	9330 4845 9330 4885
Text GLabel 9330 4490 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR061
U 1 1 5D971756
P 10250 4490
F 0 "#PWR061" H 10250 4340 50  0001 C CNN
F 1 "+3.3V" H 10265 4663 50  0000 C CNN
F 2 "" H 10250 4490 50  0001 C CNN
F 3 "" H 10250 4490 50  0001 C CNN
	1    10250 4490
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 4840 10840 4840
Connection ~ 10650 4840
Text Label 10840 4840 1    60   ~ 0
modelf
$Comp
L allcolours-rescue:MCP6002-xSN-linear-allcolours-rescue U17
U 1 1 5D9EB535
P 10125 6230
F 0 "U17" H 10180 6370 50  0000 L CNN
F 1 "MCP6002" H 10125 6130 50  0000 L CNN
F 2 "SMD_Packages:SOIC-8-N" H 10125 6230 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 10125 6230 50  0001 C CNN
	1    10125 6230
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR060
U 1 1 5D9EB53C
P 10025 6580
F 0 "#PWR060" H 10025 6330 50  0001 C CNN
F 1 "GND" H 10160 6525 50  0000 C CNN
F 2 "" H 10025 6580 50  0001 C CNN
F 3 "" H 10025 6580 50  0001 C CNN
	1    10025 6580
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R98
U 1 1 5D9EB542
P 10075 6780
F 0 "R98" V 9995 6910 50  0000 C CNN
F 1 "66.5K" V 10125 6975 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 10075 6780 50  0001 C CNN
F 3 "" H 10075 6780 50  0001 C CNN
	1    10075 6780
	0    1    1    0   
$EndComp
Wire Wire Line
	10025 5930 10025 5880
Wire Wire Line
	9775 6330 9825 6330
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR056
U 1 1 5D9EB54B
P 9775 6130
F 0 "#PWR056" H 9775 5880 50  0001 C CNN
F 1 "GND" H 9780 5957 50  0000 C CNN
F 2 "" H 9775 6130 50  0001 C CNN
F 3 "" H 9775 6130 50  0001 C CNN
	1    9775 6130
	1    0    0    -1  
$EndComp
Wire Wire Line
	9775 6130 9825 6130
Wire Wire Line
	10025 6580 10025 6530
Wire Wire Line
	9775 6780 9975 6780
Wire Wire Line
	10175 6780 10425 6780
Wire Wire Line
	10425 6780 10425 6230
Connection ~ 9775 6780
$Comp
L allcolours-rescue:C_Small-device-allcolours-rescue C61
U 1 1 5D9EB557
P 10075 6980
F 0 "C61" V 10130 7100 50  0000 C CNN
F 1 "1nF" V 10190 6985 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805" H 10075 6980 50  0001 C CNN
F 3 "" H 10075 6980 50  0001 C CNN
	1    10075 6980
	0    1    1    0   
$EndComp
Wire Wire Line
	9775 6780 9775 6980
Wire Wire Line
	9775 6980 9975 6980
Wire Wire Line
	10175 6980 10425 6980
Wire Wire Line
	10425 6980 10425 6780
Connection ~ 10425 6780
$Comp
L Device:R_POT modehf1
U 1 1 5D9EB563
P 9105 6085
F 0 "modehf1" H 9035 6131 50  0000 R CNN
F 1 "10K" H 9035 6040 50  0000 R CNN
F 2 "new_kicad:Potentiometer_Alps-RK09" H 9105 6085 50  0001 C CNN
F 3 "~" H 9105 6085 50  0001 C CNN
	1    9105 6085
	1    0    0    -1  
$EndComp
Wire Wire Line
	9105 5880 9105 5935
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR053
U 1 1 5D9EB56B
P 9105 6275
F 0 "#PWR053" H 9105 6025 50  0001 C CNN
F 1 "GND" H 9110 6102 50  0000 C CNN
F 2 "" H 9105 6275 50  0001 C CNN
F 3 "" H 9105 6275 50  0001 C CNN
	1    9105 6275
	1    0    0    -1  
$EndComp
Wire Wire Line
	9255 6550 9255 6085
Wire Wire Line
	9775 6550 9775 6780
Wire Wire Line
	9775 6330 9775 6550
Connection ~ 9775 6550
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R96
U 1 1 5D9EB575
P 9675 6550
F 0 "R96" V 9479 6550 50  0000 C CNN
F 1 "200K" V 9570 6550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 9675 6550 50  0001 C CNN
F 3 "" H 9675 6550 50  0001 C CNN
	1    9675 6550
	0    1    1    0   
$EndComp
Wire Wire Line
	9255 6550 9575 6550
Wire Wire Line
	9105 6235 9105 6275
Text GLabel 9105 5880 0    60   Input ~ 0
AREF-10
$Comp
L power:+3.3V #PWR059
U 1 1 5D9EB57F
P 10025 5880
F 0 "#PWR059" H 10025 5730 50  0001 C CNN
F 1 "+3.3V" H 10040 6053 50  0000 C CNN
F 2 "" H 10025 5880 50  0001 C CNN
F 3 "" H 10025 5880 50  0001 C CNN
	1    10025 5880
	1    0    0    -1  
$EndComp
Wire Wire Line
	10425 6230 10615 6230
Connection ~ 10425 6230
Text Label 10615 6230 1    60   ~ 0
modehf
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q23
U 1 1 5DBA272D
P 1665 5240
F 0 "Q23" H 1856 5286 50  0000 L CNN
F 1 "MMBT3904" H 1315 5090 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1865 5340 50  0001 C CNN
F 3 "" H 1665 5240 50  0001 C CNN
	1    1665 5240
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R13
U 1 1 5DBA2734
P 1315 5240
F 0 "R13" V 1119 5240 50  0000 C CNN
F 1 "10K" V 1210 5240 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1315 5240 50  0001 C CNN
F 3 "" H 1315 5240 50  0001 C CNN
	1    1315 5240
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R16
U 1 1 5DBA273B
P 1765 4890
F 0 "R16" H 1706 4844 50  0000 R CNN
F 1 "10K" H 1706 4935 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 1765 4890 50  0001 C CNN
F 3 "" H 1765 4890 50  0001 C CNN
	1    1765 4890
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0138
U 1 1 5DBA2742
P 1765 5490
F 0 "#PWR0138" H 1765 5240 50  0001 C CNN
F 1 "GND" H 1770 5317 50  0000 C CNN
F 2 "" H 1765 5490 50  0001 C CNN
F 3 "" H 1765 5490 50  0001 C CNN
	1    1765 5490
	1    0    0    -1  
$EndComp
Wire Wire Line
	1415 5240 1465 5240
Wire Wire Line
	1765 4790 1765 4740
Wire Wire Line
	1765 5490 1765 5440
$Comp
L power:+10V #PWR0139
U 1 1 5DBA274B
P 1765 4740
F 0 "#PWR0139" H 1765 4590 50  0001 C CNN
F 1 "+10V" H 1780 4913 50  0000 C CNN
F 2 "" H 1765 4740 50  0001 C CNN
F 3 "" H 1765 4740 50  0001 C CNN
	1    1765 4740
	1    0    0    -1  
$EndComp
Wire Wire Line
	1175 5240 1215 5240
Wire Wire Line
	1765 4990 1765 5020
Wire Wire Line
	1765 5020 1810 5020
Connection ~ 1765 5020
Wire Wire Line
	1765 5020 1765 5040
$Comp
L allcolours-rescue:Q_NPN_BEC-device-allcolours-rescue Q24
U 1 1 5DBAFC24
P 1665 6910
F 0 "Q24" H 1856 6956 50  0000 L CNN
F 1 "MMBT3904" H 1315 6760 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1865 7010 50  0001 C CNN
F 3 "" H 1665 6910 50  0001 C CNN
	1    1665 6910
	1    0    0    -1  
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R15
U 1 1 5DBAFC2B
P 1315 6910
F 0 "R15" V 1119 6910 50  0000 C CNN
F 1 "10K" V 1210 6910 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 1315 6910 50  0001 C CNN
F 3 "" H 1315 6910 50  0001 C CNN
	1    1315 6910
	0    1    1    0   
$EndComp
$Comp
L allcolours-rescue:R_Small-device-allcolours-rescue R18
U 1 1 5DBAFC32
P 1765 6560
F 0 "R18" H 1706 6514 50  0000 R CNN
F 1 "10K" H 1706 6605 50  0000 R CNN
F 2 "Resistors_SMD:R_0805" H 1765 6560 50  0001 C CNN
F 3 "" H 1765 6560 50  0001 C CNN
	1    1765 6560
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0140
U 1 1 5DBAFC39
P 1765 7160
F 0 "#PWR0140" H 1765 6910 50  0001 C CNN
F 1 "GND" H 1770 6987 50  0000 C CNN
F 2 "" H 1765 7160 50  0001 C CNN
F 3 "" H 1765 7160 50  0001 C CNN
	1    1765 7160
	1    0    0    -1  
$EndComp
Wire Wire Line
	1415 6910 1465 6910
Wire Wire Line
	1765 6460 1765 6410
Wire Wire Line
	1765 7160 1765 7110
$Comp
L power:+10V #PWR0141
U 1 1 5DBAFC42
P 1765 6410
F 0 "#PWR0141" H 1765 6260 50  0001 C CNN
F 1 "+10V" H 1780 6583 50  0000 C CNN
F 2 "" H 1765 6410 50  0001 C CNN
F 3 "" H 1765 6410 50  0001 C CNN
	1    1765 6410
	1    0    0    -1  
$EndComp
Wire Wire Line
	1175 6910 1215 6910
Wire Wire Line
	1765 6660 1765 6690
Wire Wire Line
	1765 6690 1810 6690
Connection ~ 1765 6690
Wire Wire Line
	1765 6690 1765 6710
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
Text Label 9325 2990 2    39   ~ 0
dac0
Text Label 9325 3090 2    39   ~ 0
dac1
Text Label 9325 3190 2    39   ~ 0
dac2
Text Label 9320 3290 2    39   ~ 0
dac3
Wire Wire Line
	9325 2990 9365 2990
Wire Wire Line
	9325 3090 9365 3090
Wire Wire Line
	9325 3190 9365 3190
Wire Wire Line
	9320 3290 9365 3290
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
Text Label 9295 2890 2    60   ~ 0
pulsehf1_in
Wire Wire Line
	9295 2890 9365 2890
Text Label 9320 1890 2    60   ~ 0
pulsehf3_out
Text Label 9335 1790 2    60   ~ 0
pulsehf2_out
Text Label 9340 1690 2    60   ~ 0
pulsehf1_out
Wire Wire Line
	9340 1690 9365 1690
Wire Wire Line
	9335 1790 9365 1790
Wire Wire Line
	9320 1890 9365 1890
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
$EndSCHEMATC
