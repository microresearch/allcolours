EESchema Schematic File Version 4
LIBS:allcolours-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
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
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M1-speedlfin1
U 1 1 5D55E8FD
P 1560 1280
F 0 "M1-speedlfin1" H 1233 1242 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1560 1280 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 1590 1430 20  0001 C CNN
F 3 "" H 1560 1280 60  0001 C CNN
	1    1560 1280
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0187
U 1 1 5D55E905
P 1160 1380
F 0 "#PWR0187" H 1160 1130 50  0001 C CNN
F 1 "GND" H 1160 1230 50  0000 C CNN
F 2 "" H 1160 1380 50  0000 C CNN
F 3 "" H 1160 1380 50  0000 C CNN
	1    1160 1380
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1160 1380 1260 1380
Wire Wire Line
	1160 1080 1260 1080
Text Notes 2215 815  0    150  ~ 30
INs
Text Notes 7950 840  0    150  ~ 30
OUTs
Text GLabel 1160 1080 0    60   Input ~ 0
SPEEDLF_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M9-speedhfin1
U 1 1 5D2438E5
P 3115 1240
F 0 "M9-speedhfin1" H 2788 1202 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 3115 1240 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3145 1390 20  0001 C CNN
F 3 "" H 3115 1240 60  0001 C CNN
	1    3115 1240
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0188
U 1 1 5D2438EC
P 2715 1340
F 0 "#PWR0188" H 2715 1090 50  0001 C CNN
F 1 "GND" H 2715 1190 50  0000 C CNN
F 2 "" H 2715 1340 50  0000 C CNN
F 3 "" H 2715 1340 50  0000 C CNN
	1    2715 1340
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2715 1340 2815 1340
Wire Wire Line
	2715 1040 2815 1040
Text GLabel 2715 1040 0    60   Input ~ 0
SPEEDHF_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M8-pulself1in1
U 1 1 5D243B9B
P 1730 2035
F 0 "M8-pulself1in1" H 1700 2270 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1730 2035 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 1760 2185 20  0001 C CNN
F 3 "" H 1730 2035 60  0001 C CNN
	1    1730 2035
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0189
U 1 1 5D243BA2
P 1330 2135
F 0 "#PWR0189" H 1330 1885 50  0001 C CNN
F 1 "GND" H 1330 1985 50  0000 C CNN
F 2 "" H 1330 2135 50  0000 C CNN
F 3 "" H 1330 2135 50  0000 C CNN
	1    1330 2135
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1330 2135 1430 2135
Wire Wire Line
	1330 1835 1430 1835
Text GLabel 1330 1835 0    60   Input ~ 0
PULSELF1_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M7-pulselfclkin1
U 1 1 5D243BAB
P 1720 2730
F 0 "M7-pulselfclkin1" H 1570 2960 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1720 2730 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 1750 2880 20  0001 C CNN
F 3 "" H 1720 2730 60  0001 C CNN
	1    1720 2730
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0190
U 1 1 5D243BB2
P 1320 2830
F 0 "#PWR0190" H 1320 2580 50  0001 C CNN
F 1 "GND" H 1320 2680 50  0000 C CNN
F 2 "" H 1320 2830 50  0000 C CNN
F 3 "" H 1320 2830 50  0000 C CNN
	1    1320 2830
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1320 2830 1420 2830
Wire Wire Line
	1320 2530 1420 2530
Text GLabel 1320 2530 0    60   Input ~ 0
PULSELFCLK_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M4-pulsehf1in1
U 1 1 5D243EA4
P 1700 3580
F 0 "M4-pulsehf1in1" H 1540 3805 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1700 3580 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 1730 3730 20  0001 C CNN
F 3 "" H 1700 3580 60  0001 C CNN
	1    1700 3580
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0191
U 1 1 5D243EAB
P 1300 3680
F 0 "#PWR0191" H 1300 3430 50  0001 C CNN
F 1 "GND" H 1300 3530 50  0000 C CNN
F 2 "" H 1300 3680 50  0000 C CNN
F 3 "" H 1300 3680 50  0000 C CNN
	1    1300 3680
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1300 3680 1400 3680
Wire Wire Line
	1300 3380 1400 3380
Text GLabel 1300 3380 0    60   Input ~ 0
PULSEHF1_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M3-pulsehfclkin1
U 1 1 5D243EB4
P 1690 4275
F 0 "M3-pulsehfclkin1" H 1360 4465 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1690 4275 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 1720 4425 20  0001 C CNN
F 3 "" H 1690 4275 60  0001 C CNN
	1    1690 4275
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0192
U 1 1 5D243EBB
P 1290 4375
F 0 "#PWR0192" H 1290 4125 50  0001 C CNN
F 1 "GND" H 1290 4225 50  0000 C CNN
F 2 "" H 1290 4375 50  0000 C CNN
F 3 "" H 1290 4375 50  0000 C CNN
	1    1290 4375
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1290 4375 1390 4375
Wire Wire Line
	1290 4075 1390 4075
Text GLabel 1290 4075 0    60   Input ~ 0
PULSEHFCLK_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M14-cmplf1in1
U 1 1 5D2445B7
P 3255 2045
F 0 "M14-cmplf1in1" H 3140 2235 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 3255 2045 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3285 2195 20  0001 C CNN
F 3 "" H 3255 2045 60  0001 C CNN
	1    3255 2045
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0193
U 1 1 5D2445BE
P 2855 2145
F 0 "#PWR0193" H 2855 1895 50  0001 C CNN
F 1 "GND" H 2855 1995 50  0000 C CNN
F 2 "" H 2855 2145 50  0000 C CNN
F 3 "" H 2855 2145 50  0000 C CNN
	1    2855 2145
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2855 2145 2955 2145
Wire Wire Line
	2855 1845 2955 1845
Text GLabel 2855 1845 0    60   Input ~ 0
COMPLF1_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M13-complf2in1
U 1 1 5D2445C7
P 3245 2740
F 0 "M13-complf2in1" H 2918 2702 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 3245 2740 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3275 2890 20  0001 C CNN
F 3 "" H 3245 2740 60  0001 C CNN
	1    3245 2740
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0194
U 1 1 5D2445CE
P 2845 2840
F 0 "#PWR0194" H 2845 2590 50  0001 C CNN
F 1 "GND" H 2845 2690 50  0000 C CNN
F 2 "" H 2845 2840 50  0000 C CNN
F 3 "" H 2845 2840 50  0000 C CNN
	1    2845 2840
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2845 2840 2945 2840
Wire Wire Line
	2845 2540 2945 2540
Text GLabel 2845 2540 0    60   Input ~ 0
COMPLF2_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M12-comphf1in1
U 1 1 5D2449E8
P 3240 3525
F 0 "M12-comphf1in1" H 2995 3690 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 3240 3525 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3270 3675 20  0001 C CNN
F 3 "" H 3240 3525 60  0001 C CNN
	1    3240 3525
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0195
U 1 1 5D2449EF
P 2840 3625
F 0 "#PWR0195" H 2840 3375 50  0001 C CNN
F 1 "GND" H 2840 3475 50  0000 C CNN
F 2 "" H 2840 3625 50  0000 C CNN
F 3 "" H 2840 3625 50  0000 C CNN
	1    2840 3625
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2840 3625 2940 3625
Wire Wire Line
	2840 3325 2940 3325
Text GLabel 2840 3325 0    60   Input ~ 0
COMPHF1_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M11-comphf2in1
U 1 1 5D2449F8
P 3230 4220
F 0 "M11-comphf2in1" H 2903 4182 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 3230 4220 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3260 4370 20  0001 C CNN
F 3 "" H 3230 4220 60  0001 C CNN
	1    3230 4220
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0196
U 1 1 5D2449FF
P 2830 4320
F 0 "#PWR0196" H 2830 4070 50  0001 C CNN
F 1 "GND" H 2830 4170 50  0000 C CNN
F 2 "" H 2830 4320 50  0000 C CNN
F 3 "" H 2830 4320 50  0000 C CNN
	1    2830 4320
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2830 4320 2930 4320
Wire Wire Line
	2830 4020 2930 4020
Text GLabel 2830 4020 0    60   Input ~ 0
COMPHF2_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M5-difffilaudinl1
U 1 1 5D2459B3
P 1715 4995
F 0 "M5-difffilaudinl1" H 1475 5170 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1715 4995 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 1745 5145 20  0001 C CNN
F 3 "" H 1715 4995 60  0001 C CNN
	1    1715 4995
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0197
U 1 1 5D2459BA
P 1315 5095
F 0 "#PWR0197" H 1315 4845 50  0001 C CNN
F 1 "GND" H 1315 4945 50  0000 C CNN
F 2 "" H 1315 5095 50  0000 C CNN
F 3 "" H 1315 5095 50  0000 C CNN
	1    1315 5095
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1315 5095 1415 5095
Wire Wire Line
	1315 4795 1415 4795
Text GLabel 1315 4795 0    60   Input ~ 0
DIFFFILAUD_INL
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M15-difffilaudinh1
U 1 1 5D2459C3
P 3255 4940
F 0 "M15-difffilaudinh1" H 2928 4902 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 3255 4940 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3285 5090 20  0001 C CNN
F 3 "" H 3255 4940 60  0001 C CNN
	1    3255 4940
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0198
U 1 1 5D2459CA
P 2855 5040
F 0 "#PWR0198" H 2855 4790 50  0001 C CNN
F 1 "GND" H 2855 4890 50  0000 C CNN
F 2 "" H 2855 5040 50  0000 C CNN
F 3 "" H 2855 5040 50  0000 C CNN
	1    2855 5040
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2855 5040 2955 5040
Wire Wire Line
	2855 4740 2955 4740
Text GLabel 2855 4740 0    60   Input ~ 0
DIFFFILAUD_INH
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M2-clkinl1
U 1 1 5D24A026
P 1670 5885
F 0 "M2-clkinl1" H 1330 6070 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1670 5885 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 1700 6035 20  0001 C CNN
F 3 "" H 1670 5885 60  0001 C CNN
	1    1670 5885
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0199
U 1 1 5D24A02D
P 1270 5985
F 0 "#PWR0199" H 1270 5735 50  0001 C CNN
F 1 "GND" H 1270 5835 50  0000 C CNN
F 2 "" H 1270 5985 50  0000 C CNN
F 3 "" H 1270 5985 50  0000 C CNN
	1    1270 5985
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1270 5985 1370 5985
Wire Wire Line
	1270 5685 1370 5685
Text GLabel 1270 5685 0    60   Input ~ 0
CLK_INL
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M10-clkinh1
U 1 1 5D24A036
P 3210 5830
F 0 "M10-clkinh1" H 2883 5792 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 3210 5830 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3240 5980 20  0001 C CNN
F 3 "" H 3210 5830 60  0001 C CNN
	1    3210 5830
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0200
U 1 1 5D24A03D
P 2810 5930
F 0 "#PWR0200" H 2810 5680 50  0001 C CNN
F 1 "GND" H 2810 5780 50  0000 C CNN
F 2 "" H 2810 5930 50  0000 C CNN
F 3 "" H 2810 5930 50  0000 C CNN
	1    2810 5930
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2810 5930 2910 5930
Wire Wire Line
	2810 5630 2910 5630
Text GLabel 2810 5630 0    60   Input ~ 0
CLK_INH
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M6-ourinl1
U 1 1 5D24AA21
P 1715 6615
F 0 "M6-ourinl1" H 1388 6577 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 1715 6615 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 1745 6765 20  0001 C CNN
F 3 "" H 1715 6615 60  0001 C CNN
	1    1715 6615
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0201
U 1 1 5D24AA28
P 1315 6715
F 0 "#PWR0201" H 1315 6465 50  0001 C CNN
F 1 "GND" H 1315 6565 50  0000 C CNN
F 2 "" H 1315 6715 50  0000 C CNN
F 3 "" H 1315 6715 50  0000 C CNN
	1    1315 6715
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1315 6715 1415 6715
Text GLabel 1320 6415 0    60   Input ~ 0
OUR_INL
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M16-ourinh1
U 1 1 5D24AA31
P 3255 6560
F 0 "M16-ourinh1" H 2928 6522 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 3255 6560 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3285 6710 20  0001 C CNN
F 3 "" H 3255 6560 60  0001 C CNN
	1    3255 6560
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0202
U 1 1 5D24AA38
P 2855 6660
F 0 "#PWR0202" H 2855 6410 50  0001 C CNN
F 1 "GND" H 2855 6510 50  0000 C CNN
F 2 "" H 2855 6660 50  0000 C CNN
F 3 "" H 2855 6660 50  0000 C CNN
	1    2855 6660
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2855 6660 2955 6660
Wire Wire Line
	2855 6360 2955 6360
Text GLabel 2855 6360 0    60   Input ~ 0
OUR_INH
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M20-complf1clkin1
U 1 1 5D24C1A1
P 4940 2035
F 0 "M20-complf1clkin1" H 4613 1997 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 4940 2035 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4970 2185 20  0001 C CNN
F 3 "" H 4940 2035 60  0001 C CNN
	1    4940 2035
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0203
U 1 1 5D24C1A8
P 4540 2135
F 0 "#PWR0203" H 4540 1885 50  0001 C CNN
F 1 "GND" H 4540 1985 50  0000 C CNN
F 2 "" H 4540 2135 50  0000 C CNN
F 3 "" H 4540 2135 50  0000 C CNN
	1    4540 2135
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4540 2135 4640 2135
Wire Wire Line
	4540 1835 4640 1835
Text GLabel 4540 1835 0    60   Input ~ 0
COMPLF1_CLK_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M19-complf2clkin1
U 1 1 5D24C1B1
P 4930 2730
F 0 "M19-complf2clkin1" H 4603 2692 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 4930 2730 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4960 2880 20  0001 C CNN
F 3 "" H 4930 2730 60  0001 C CNN
	1    4930 2730
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0204
U 1 1 5D24C1B8
P 4530 2830
F 0 "#PWR0204" H 4530 2580 50  0001 C CNN
F 1 "GND" H 4530 2680 50  0000 C CNN
F 2 "" H 4530 2830 50  0000 C CNN
F 3 "" H 4530 2830 50  0000 C CNN
	1    4530 2830
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4530 2830 4630 2830
Wire Wire Line
	4530 2530 4630 2530
Text GLabel 4530 2530 0    60   Input ~ 0
COMPLF2_CLK_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M18-comphf1clkin1
U 1 1 5D24C1C1
P 4925 3515
F 0 "M18-comphf1clkin1" H 4598 3477 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 4925 3515 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4955 3665 20  0001 C CNN
F 3 "" H 4925 3515 60  0001 C CNN
	1    4925 3515
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0205
U 1 1 5D24C1C8
P 4525 3615
F 0 "#PWR0205" H 4525 3365 50  0001 C CNN
F 1 "GND" H 4525 3465 50  0000 C CNN
F 2 "" H 4525 3615 50  0000 C CNN
F 3 "" H 4525 3615 50  0000 C CNN
	1    4525 3615
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4525 3615 4625 3615
Wire Wire Line
	4525 3315 4625 3315
Text GLabel 4525 3315 0    60   Input ~ 0
COMPHF1_CLK_IN
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M17-comphf2clkin1
U 1 1 5D24C1D1
P 4915 4210
F 0 "M17-comphf2clkin1" H 4588 4172 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 4915 4210 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4945 4360 20  0001 C CNN
F 3 "" H 4915 4210 60  0001 C CNN
	1    4915 4210
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0206
U 1 1 5D24C1D8
P 4515 4310
F 0 "#PWR0206" H 4515 4060 50  0001 C CNN
F 1 "GND" H 4515 4160 50  0000 C CNN
F 2 "" H 4515 4310 50  0000 C CNN
F 3 "" H 4515 4310 50  0000 C CNN
	1    4515 4310
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4515 4310 4615 4310
Wire Wire Line
	4515 4010 4615 4010
Text GLabel 4515 4010 0    60   Input ~ 0
COMPHF2_CLK_IN
Text Notes 5170 1080 0    118  ~ 0
x20
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M25-pulself1out1
U 1 1 5D250DF3
P 7300 1965
F 0 "M25-pulself1out1" H 6973 1927 45  0000 R CNN
F 1 "pulself1_out" H 7300 1965 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 7330 2115 20  0001 C CNN
F 3 "" H 7300 1965 60  0001 C CNN
	1    7300 1965
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0207
U 1 1 5D250DFA
P 6900 2065
F 0 "#PWR0207" H 6900 1815 50  0001 C CNN
F 1 "GND" H 6900 1915 50  0000 C CNN
F 2 "" H 6900 2065 50  0000 C CNN
F 3 "" H 6900 2065 50  0000 C CNN
	1    6900 2065
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6900 2065 7000 2065
Wire Wire Line
	6900 1765 7000 1765
Text GLabel 6900 1765 0    60   Input ~ 0
PULSELF1_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M30-pulself2out1
U 1 1 5D250E03
P 8825 1975
F 0 "M30-pulself2out1" H 8498 1937 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 8825 1975 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8855 2125 20  0001 C CNN
F 3 "" H 8825 1975 60  0001 C CNN
	1    8825 1975
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0208
U 1 1 5D250E0A
P 8425 2075
F 0 "#PWR0208" H 8425 1825 50  0001 C CNN
F 1 "GND" H 8425 1925 50  0000 C CNN
F 2 "" H 8425 2075 50  0000 C CNN
F 3 "" H 8425 2075 50  0000 C CNN
	1    8425 2075
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8425 2075 8525 2075
Wire Wire Line
	8425 1775 8525 1775
Text GLabel 8425 1775 0    60   Input ~ 0
PULSELF2_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M36-complfout1
U 1 1 5D250E13
P 10510 1965
F 0 "M36-complfout1" H 10183 1927 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 10510 1965 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 10540 2115 20  0001 C CNN
F 3 "" H 10510 1965 60  0001 C CNN
	1    10510 1965
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0209
U 1 1 5D250E1A
P 10110 2065
F 0 "#PWR0209" H 10110 1815 50  0001 C CNN
F 1 "GND" H 10110 1915 50  0000 C CNN
F 2 "" H 10110 2065 50  0000 C CNN
F 3 "" H 10110 2065 50  0000 C CNN
	1    10110 2065
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10110 2065 10210 2065
Wire Wire Line
	10110 1765 10210 1765
Text GLabel 10110 1765 0    60   Input ~ 0
COMPLF_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M26-pulsehf1out1
U 1 1 5D252177
P 7340 2735
F 0 "M26-pulsehf1out1" H 7013 2697 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 7340 2735 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 7370 2885 20  0001 C CNN
F 3 "" H 7340 2735 60  0001 C CNN
	1    7340 2735
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0210
U 1 1 5D25217E
P 6940 2835
F 0 "#PWR0210" H 6940 2585 50  0001 C CNN
F 1 "GND" H 6940 2685 50  0000 C CNN
F 2 "" H 6940 2835 50  0000 C CNN
F 3 "" H 6940 2835 50  0000 C CNN
	1    6940 2835
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6940 2835 7040 2835
Wire Wire Line
	6940 2535 7040 2535
Text GLabel 6940 2535 0    60   Input ~ 0
PULSEHF1_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M32-pulsehf2out1
U 1 1 5D252187
P 8865 2745
F 0 "M32-pulsehf2out1" H 8538 2707 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 8865 2745 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8895 2895 20  0001 C CNN
F 3 "" H 8865 2745 60  0001 C CNN
	1    8865 2745
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0211
U 1 1 5D25218E
P 8465 2845
F 0 "#PWR0211" H 8465 2595 50  0001 C CNN
F 1 "GND" H 8465 2695 50  0000 C CNN
F 2 "" H 8465 2845 50  0000 C CNN
F 3 "" H 8465 2845 50  0000 C CNN
	1    8465 2845
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8465 2845 8565 2845
Wire Wire Line
	8465 2545 8565 2545
Text GLabel 8465 2545 0    60   Input ~ 0
PULSEHF2_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M37-comphfout1
U 1 1 5D252197
P 10550 2735
F 0 "M37-comphfout1" H 10223 2697 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 10550 2735 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 10580 2885 20  0001 C CNN
F 3 "" H 10550 2735 60  0001 C CNN
	1    10550 2735
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0212
U 1 1 5D25219E
P 10150 2835
F 0 "#PWR0212" H 10150 2585 50  0001 C CNN
F 1 "GND" H 10150 2685 50  0000 C CNN
F 2 "" H 10150 2835 50  0000 C CNN
F 3 "" H 10150 2835 50  0000 C CNN
	1    10150 2835
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10150 2835 10250 2835
Wire Wire Line
	10150 2535 10250 2535
Text GLabel 10150 2535 0    60   Input ~ 0
COMPHF_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M27-filtlfout1
U 1 1 5D253D49
P 7355 3655
F 0 "M27-filtlfout1" H 7028 3617 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 7355 3655 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 7385 3805 20  0001 C CNN
F 3 "" H 7355 3655 60  0001 C CNN
	1    7355 3655
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0213
U 1 1 5D253D50
P 6955 3755
F 0 "#PWR0213" H 6955 3505 50  0001 C CNN
F 1 "GND" H 6955 3605 50  0000 C CNN
F 2 "" H 6955 3755 50  0000 C CNN
F 3 "" H 6955 3755 50  0000 C CNN
	1    6955 3755
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6955 3755 7055 3755
Wire Wire Line
	6955 3455 7055 3455
Text GLabel 6955 3455 0    60   Input ~ 0
FILTLF_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M33-filthfout1
U 1 1 5D253D59
P 8895 3600
F 0 "M33-filthfout1" H 8568 3562 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 8895 3600 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8925 3750 20  0001 C CNN
F 3 "" H 8895 3600 60  0001 C CNN
	1    8895 3600
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0214
U 1 1 5D253D60
P 8495 3700
F 0 "#PWR0214" H 8495 3450 50  0001 C CNN
F 1 "GND" H 8495 3550 50  0000 C CNN
F 2 "" H 8495 3700 50  0000 C CNN
F 3 "" H 8495 3700 50  0000 C CNN
	1    8495 3700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8495 3700 8595 3700
Wire Wire Line
	8495 3400 8595 3400
Text GLabel 8495 3400 0    60   Input ~ 0
FILTHF_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M24-ourlfout1
U 1 1 5D255F83
P 7290 4570
F 0 "M24-ourlfout1" H 6963 4532 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 7290 4570 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 7320 4720 20  0001 C CNN
F 3 "" H 7290 4570 60  0001 C CNN
	1    7290 4570
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0215
U 1 1 5D255F8A
P 6890 4670
F 0 "#PWR0215" H 6890 4420 50  0001 C CNN
F 1 "GND" H 6890 4520 50  0000 C CNN
F 2 "" H 6890 4670 50  0000 C CNN
F 3 "" H 6890 4670 50  0000 C CNN
	1    6890 4670
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6890 4670 6990 4670
Wire Wire Line
	6890 4370 6990 4370
Text GLabel 6890 4370 0    60   Input ~ 0
OURLF_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M31-ourhfout1
U 1 1 5D255F93
P 8830 4515
F 0 "M31-ourhfout1" H 8503 4477 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 8830 4515 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8860 4665 20  0001 C CNN
F 3 "" H 8830 4515 60  0001 C CNN
	1    8830 4515
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0216
U 1 1 5D255F9A
P 8430 4615
F 0 "#PWR0216" H 8430 4365 50  0001 C CNN
F 1 "GND" H 8430 4465 50  0000 C CNN
F 2 "" H 8430 4615 50  0000 C CNN
F 3 "" H 8430 4615 50  0000 C CNN
	1    8430 4615
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8430 4615 8530 4615
Wire Wire Line
	8430 4315 8530 4315
Text GLabel 8430 4315 0    60   Input ~ 0
OURHF_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M22-pwmlfout1
U 1 1 5D257DDC
P 7240 5305
F 0 "M22-pwmlfout1" H 6913 5267 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 7240 5305 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 7270 5455 20  0001 C CNN
F 3 "" H 7240 5305 60  0001 C CNN
	1    7240 5305
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0217
U 1 1 5D257DE3
P 6840 5405
F 0 "#PWR0217" H 6840 5155 50  0001 C CNN
F 1 "GND" H 6840 5255 50  0000 C CNN
F 2 "" H 6840 5405 50  0000 C CNN
F 3 "" H 6840 5405 50  0000 C CNN
	1    6840 5405
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6840 5405 6940 5405
Wire Wire Line
	6840 5105 6940 5105
Text GLabel 6840 5105 0    60   Input ~ 0
PWMLF_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M34-complfclkout1
U 1 1 5D257DFC
P 10450 5305
F 0 "M34-complfclkout1" H 10123 5267 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 10450 5305 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 10480 5455 20  0001 C CNN
F 3 "" H 10450 5305 60  0001 C CNN
	1    10450 5305
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0219
U 1 1 5D257E03
P 10050 5405
F 0 "#PWR0219" H 10050 5155 50  0001 C CNN
F 1 "GND" H 10050 5255 50  0000 C CNN
F 2 "" H 10050 5405 50  0000 C CNN
F 3 "" H 10050 5405 50  0000 C CNN
	1    10050 5405
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10050 5405 10150 5405
Wire Wire Line
	10050 5105 10150 5105
Text GLabel 10050 5105 0    60   Input ~ 0
COMPLFCLK_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M23-pwmhfout1
U 1 1 5D257E0C
P 7280 6075
F 0 "M23-pwmhfout1" H 6953 6037 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 7280 6075 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 7310 6225 20  0001 C CNN
F 3 "" H 7280 6075 60  0001 C CNN
	1    7280 6075
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0220
U 1 1 5D257E13
P 6880 6175
F 0 "#PWR0220" H 6880 5925 50  0001 C CNN
F 1 "GND" H 6880 6025 50  0000 C CNN
F 2 "" H 6880 6175 50  0000 C CNN
F 3 "" H 6880 6175 50  0000 C CNN
	1    6880 6175
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6880 6175 6980 6175
Wire Wire Line
	6880 5875 6980 5875
Text GLabel 6880 5875 0    60   Input ~ 0
PWMHF_OUT
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M35-comphfclkout1
U 1 1 5D257E2C
P 10490 6075
F 0 "M35-comphfclkout1" H 10163 6037 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 10490 6075 45  0001 L BNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 10520 6225 20  0001 C CNN
F 3 "" H 10490 6075 60  0001 C CNN
	1    10490 6075
	-1   0    0    1   
$EndComp
$Comp
L allcolours-rescue:GND-power-allcolours-rescue #PWR0222
U 1 1 5D257E33
P 10090 6175
F 0 "#PWR0222" H 10090 5925 50  0001 C CNN
F 1 "GND" H 10090 6025 50  0000 C CNN
F 2 "" H 10090 6175 50  0000 C CNN
F 3 "" H 10090 6175 50  0000 C CNN
	1    10090 6175
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10090 6175 10190 6175
Wire Wire Line
	10090 5875 10190 5875
Text GLabel 10090 5875 0    60   Input ~ 0
COMPHFCLK_OUT
Text Notes 8145 1135 0    118  ~ 0
x17
Text GLabel 4585 2035 0    60   Input ~ 0
PWMLF_OUT
Wire Wire Line
	1340 5885 1370 5885
Text GLabel 4585 3515 0    60   Input ~ 0
PWMHF_OUT
Wire Wire Line
	2870 5830 2910 5830
Text GLabel 1340 5885 0    60   Input ~ 0
COMPLFCLK_OUT
Text GLabel 2870 5830 0    60   Input ~ 0
COMPHFCLK_OUT
Wire Wire Line
	1380 4995 1415 4995
Wire Wire Line
	2915 4940 2955 4940
Wire Wire Line
	4585 3515 4625 3515
Wire Wire Line
	4585 2035 4640 2035
Text GLabel 2890 3525 0    60   Input ~ 0
NOISEHF_OUT
Wire Wire Line
	2890 3525 2940 3525
Text GLabel 2930 2045 0    60   Input ~ 0
NOISELF_OUT
Wire Wire Line
	2930 2045 2955 2045
Text GLabel 1380 4995 0    60   Input ~ 0
COMPLF_OUT
Text GLabel 2915 4940 0    60   Input ~ 0
COMPHF_OUT
Text Notes 2215 2755 0    118  ~ 0
no_NORM
Text Notes 3630 2970 0    118  ~ 0
no_NORM
Text Notes 2075 4240 0    118  ~ 0
no_NORM
Text Notes 3715 4350 0    118  ~ 0
no_NORM
Text Notes 425  1300 0    118  ~ 0
no_NORM
Text Notes 2080 1255 0    118  ~ 0
no_NORM
Wire Wire Line
	1380 2035 1430 2035
Text GLabel 1380 2035 0    60   Input ~ 0
COMPLF_OUT
Text GLabel 1345 3580 0    60   Input ~ 0
COMPHF_OUT
Wire Wire Line
	1345 3580 1400 3580
Text GLabel 1390 2730 0    60   Input ~ 0
COMPLFCLK_OUT
Wire Wire Line
	1390 2730 1420 2730
Text GLabel 1350 4275 0    60   Input ~ 0
COMPHFCLK_OUT
Wire Wire Line
	1350 4275 1390 4275
Wire Wire Line
	1320 6415 1415 6415
Text Notes 1095 7080 0    118  ~ 0
no_NORM
Text Notes 2510 6995 0    118  ~ 0
no_NORM
$EndSCHEMATC
