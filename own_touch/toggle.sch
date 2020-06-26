EESchema Schematic File Version 4
LIBS:touch-cache
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
L Connector_Generic:Conn_01x04 J13
U 1 1 5EF3AC50
P 6600 3315
F 0 "J13" H 6680 3307 50  0000 L CNN
F 1 "Conn_01x04" H 6680 3216 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 6600 3315 50  0001 C CNN
F 3 "~" H 6600 3315 50  0001 C CNN
	1    6600 3315
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3215 6290 3215
Text GLabel 6290 3215 0    50   Input ~ 0
OUTT1
Text GLabel 6300 3315 0    50   Input ~ 0
OUTT2
Wire Wire Line
	6300 3315 6400 3315
Wire Wire Line
	6400 3415 6290 3415
Text GLabel 6290 3415 0    50   Input ~ 0
OUTT3
Text GLabel 6300 3515 0    50   Input ~ 0
OUTT4
Wire Wire Line
	6300 3515 6400 3515
Text Notes 5315 200  0    79   ~ 0
add bypass caps by hand
$Comp
L Connector_Generic:Conn_01x04 J14
U 1 1 5F37C317
P 7790 3315
F 0 "J14" H 7870 3307 50  0000 L CNN
F 1 "Conn_01x04" H 7870 3216 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 7790 3315 50  0001 C CNN
F 3 "~" H 7790 3315 50  0001 C CNN
	1    7790 3315
	1    0    0    -1  
$EndComp
Wire Wire Line
	7590 3215 7480 3215
Text GLabel 7480 3215 0    50   Input ~ 0
OUTT1
Text GLabel 7490 3315 0    50   Input ~ 0
OUTT2
Wire Wire Line
	7490 3315 7590 3315
Wire Wire Line
	7590 3415 7480 3415
Text GLabel 7480 3415 0    50   Input ~ 0
OUTT3
Text GLabel 7490 3515 0    50   Input ~ 0
OUTT4
Wire Wire Line
	7490 3515 7590 3515
Text Notes 6395 3745 0    79   ~ 0
For panel and circuits
$EndSCHEMATC
