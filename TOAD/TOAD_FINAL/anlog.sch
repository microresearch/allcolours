EESchema Schematic File Version 4
LIBS:toad2-cache
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
Text Notes 6720 2300 0    118  ~ 0
2x multipliers\n
$Comp
L toad2-rescue:AD633JR-eec U15
U 1 1 6073FD6A
P 3795 2765
F 0 "U15" H 4295 3030 50  0000 C CNN
F 1 "AD633JN" H 4295 2939 50  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 3795 3165 50  0001 L CNN
F 3 "http://www.analog.com/media/en/technical-documentation/data-sheets/AD633.pdf" H 3795 3265 50  0001 L CNN
F 4 "Manufacturer URL" H 3795 3365 50  0001 L CNN "Component Link 1 Description"
F 5 "http://www.analog.com/en/index.html" H 3795 3465 50  0001 L CNN "Component Link 1 URL"
F 6 "Package Specification" H 3795 3565 50  0001 L CNN "Component Link 3 Description"
F 7 "http://www.analog.com/static/imported-files/packages/PKG_PDF/PDIP(N)/N_8.pdf" H 3795 3665 50  0001 L CNN "Component Link 3 URL"
F 8 "Rev. K" H 3795 3765 50  0001 L CNN "Datasheet Version"
F 9 "Through Hole" H 3795 3865 50  0001 L CNN "Mounting Technology"
F 10 "2" H 3795 3965 50  0001 L CNN "Number of Channels"
F 11 "8-Pin Plastic Dual In-Line Package, Body 9.59 x 6.6 mm, Pitch 2.54 mm" H 3795 4065 50  0001 L CNN "Package Description"
F 12 "07/2006" H 3795 4165 50  0001 L CNN "Package Version"
F 13 "Tube" H 3795 4265 50  0001 L CNN "Packing"
F 14 "20 V/us" H 3795 4365 50  0001 L CNN "Slew Rate"
F 15 "6 mA" H 3795 4465 50  0001 L CNN "Supply Current Max"
F 16 "70 degC" H 3795 4565 50  0001 L CNN "Temperature Max"
F 17 "0 degC" H 3795 4665 50  0001 L CNN "Temperature Min"
F 18 "IC" H 3795 4765 50  0001 L CNN "category"
F 19 "82579f909b82c26c" H 3795 4865 50  0001 L CNN "library id"
F 20 "Analog Devices" H 3795 4965 50  0001 L CNN "manufacturer"
F 21 "MS-001" H 3795 5065 50  0001 L CNN "package"
F 22 "D70804D2-C31E-4A78-88FF-EDD09AD4FF7C" H 3795 5165 50  0001 L CNN "vault revision"
F 23 "yes" H 3795 5265 50  0001 L CNN "imported"
	1    3795 2765
	1    0    0    -1  
$EndComp
Wire Wire Line
	3895 2865 3765 2865
Wire Wire Line
	3765 3165 3895 3165
$Comp
L power:GND #PWR0144
U 1 1 60A86C7F
P 3765 3165
F 0 "#PWR0144" H 3765 2915 50  0001 C CNN
F 1 "GND" H 3770 2992 50  0000 C CNN
F 2 "" H 3765 3165 50  0001 C CNN
F 3 "" H 3765 3165 50  0001 C CNN
	1    3765 3165
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0150
U 1 1 60A86CAF
P 4745 3065
F 0 "#PWR0150" H 4745 2815 50  0001 C CNN
F 1 "GND" H 4750 2892 50  0000 C CNN
F 2 "" H 4745 3065 50  0001 C CNN
F 3 "" H 4745 3065 50  0001 C CNN
	1    4745 3065
	1    0    0    -1  
$EndComp
Wire Wire Line
	4695 3065 4745 3065
$Comp
L toad2-rescue:+12V-power-allcolours_analogue-rescue #PWR?
U 1 1 60A87F70
P 3395 3365
AR Path="/5ED966D6/60A87F70" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/60A87F70" Ref="#PWR?"  Part="1" 
AR Path="/60663957/60A87F70" Ref="#PWR?"  Part="1" 
AR Path="/60663E79/60A87F70" Ref="#PWR0137"  Part="1" 
F 0 "#PWR0137" H 3395 3215 50  0001 C CNN
F 1 "+12V-power" H 3410 3538 50  0000 C CNN
F 2 "" H 3395 3365 50  0001 C CNN
F 3 "" H 3395 3365 50  0001 C CNN
	1    3395 3365
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60A88021
P 3545 3465
AR Path="/5EC7DA76/60A88021" Ref="C?"  Part="1" 
AR Path="/5ED966D6/60A88021" Ref="C?"  Part="1" 
AR Path="/60663957/60A88021" Ref="C?"  Part="1" 
AR Path="/60663E79/60A88021" Ref="C57"  Part="1" 
F 0 "C57" H 3637 3511 50  0000 L CNN
F 1 "100N" H 3637 3420 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3545 3465 50  0001 C CNN
F 3 "~" H 3545 3465 50  0001 C CNN
	1    3545 3465
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 60A880E1
P 4870 3365
AR Path="/5ED966D6/60A880E1" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/60A880E1" Ref="#PWR?"  Part="1" 
AR Path="/60663957/60A880E1" Ref="#PWR?"  Part="1" 
AR Path="/60663E79/60A880E1" Ref="#PWR0155"  Part="1" 
F 0 "#PWR0155" H 4870 3465 50  0001 C CNN
F 1 "-12V" H 4885 3538 50  0000 C CNN
F 2 "" H 4870 3365 50  0001 C CNN
F 3 "" H 4870 3365 50  0001 C CNN
	1    4870 3365
	-1   0    0    1   
$EndComp
Wire Wire Line
	3895 3365 3545 3365
Connection ~ 3545 3365
Wire Wire Line
	3545 3365 3395 3365
$Comp
L power:GND #PWR0140
U 1 1 60A882F1
P 3545 3600
F 0 "#PWR0140" H 3545 3350 50  0001 C CNN
F 1 "GND" H 3550 3427 50  0000 C CNN
F 2 "" H 3545 3600 50  0001 C CNN
F 3 "" H 3545 3600 50  0001 C CNN
	1    3545 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3545 3565 3545 3600
Wire Wire Line
	4695 3365 4740 3365
$Comp
L Device:C_Small C?
U 1 1 60A88831
P 4740 3485
AR Path="/5EC7DA76/60A88831" Ref="C?"  Part="1" 
AR Path="/5ED966D6/60A88831" Ref="C?"  Part="1" 
AR Path="/60663957/60A88831" Ref="C?"  Part="1" 
AR Path="/60663E79/60A88831" Ref="C60"  Part="1" 
F 0 "C60" H 4832 3531 50  0000 L CNN
F 1 "100N" H 4455 3365 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4740 3485 50  0001 C CNN
F 3 "~" H 4740 3485 50  0001 C CNN
	1    4740 3485
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0149
U 1 1 60A88838
P 4740 3620
F 0 "#PWR0149" H 4740 3370 50  0001 C CNN
F 1 "GND" H 4745 3447 50  0000 C CNN
F 2 "" H 4740 3620 50  0001 C CNN
F 3 "" H 4740 3620 50  0001 C CNN
	1    4740 3620
	1    0    0    -1  
$EndComp
Wire Wire Line
	4740 3585 4740 3620
Wire Wire Line
	4740 3365 4740 3385
Connection ~ 4740 3365
Wire Wire Line
	4740 3365 4870 3365
$Comp
L power:GND #PWR0143
U 1 1 60A89747
P 3765 2865
F 0 "#PWR0143" H 3765 2615 50  0001 C CNN
F 1 "GND" H 3770 2692 50  0000 C CNN
F 2 "" H 3765 2865 50  0001 C CNN
F 3 "" H 3765 2865 50  0001 C CNN
	1    3765 2865
	1    0    0    -1  
$EndComp
Wire Wire Line
	3895 3065 3635 3065
$Comp
L toad2-rescue:AD633JR-eec U17
U 1 1 60A8A762
P 5930 2805
F 0 "U17" H 6430 3070 50  0000 C CNN
F 1 "AD633JN" H 6430 2979 50  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 5930 3205 50  0001 L CNN
F 3 "http://www.analog.com/media/en/technical-documentation/data-sheets/AD633.pdf" H 5930 3305 50  0001 L CNN
F 4 "Manufacturer URL" H 5930 3405 50  0001 L CNN "Component Link 1 Description"
F 5 "http://www.analog.com/en/index.html" H 5930 3505 50  0001 L CNN "Component Link 1 URL"
F 6 "Package Specification" H 5930 3605 50  0001 L CNN "Component Link 3 Description"
F 7 "http://www.analog.com/static/imported-files/packages/PKG_PDF/PDIP(N)/N_8.pdf" H 5930 3705 50  0001 L CNN "Component Link 3 URL"
F 8 "Rev. K" H 5930 3805 50  0001 L CNN "Datasheet Version"
F 9 "Through Hole" H 5930 3905 50  0001 L CNN "Mounting Technology"
F 10 "2" H 5930 4005 50  0001 L CNN "Number of Channels"
F 11 "8-Pin Plastic Dual In-Line Package, Body 9.59 x 6.6 mm, Pitch 2.54 mm" H 5930 4105 50  0001 L CNN "Package Description"
F 12 "07/2006" H 5930 4205 50  0001 L CNN "Package Version"
F 13 "Tube" H 5930 4305 50  0001 L CNN "Packing"
F 14 "20 V/us" H 5930 4405 50  0001 L CNN "Slew Rate"
F 15 "6 mA" H 5930 4505 50  0001 L CNN "Supply Current Max"
F 16 "70 degC" H 5930 4605 50  0001 L CNN "Temperature Max"
F 17 "0 degC" H 5930 4705 50  0001 L CNN "Temperature Min"
F 18 "IC" H 5930 4805 50  0001 L CNN "category"
F 19 "82579f909b82c26c" H 5930 4905 50  0001 L CNN "library id"
F 20 "Analog Devices" H 5930 5005 50  0001 L CNN "manufacturer"
F 21 "MS-001" H 5930 5105 50  0001 L CNN "package"
F 22 "D70804D2-C31E-4A78-88FF-EDD09AD4FF7C" H 5930 5205 50  0001 L CNN "vault revision"
F 23 "yes" H 5930 5305 50  0001 L CNN "imported"
	1    5930 2805
	1    0    0    -1  
$EndComp
Wire Wire Line
	6030 2905 5900 2905
Wire Wire Line
	5900 3205 6030 3205
$Comp
L power:GND #PWR0148
U 1 1 60A8A76B
P 5900 3205
F 0 "#PWR0148" H 5900 2955 50  0001 C CNN
F 1 "GND" H 5895 3060 50  0000 C CNN
F 2 "" H 5900 3205 50  0001 C CNN
F 3 "" H 5900 3205 50  0001 C CNN
	1    5900 3205
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0154
U 1 1 60A8A771
P 6880 3105
F 0 "#PWR0154" H 6880 2855 50  0001 C CNN
F 1 "GND" H 6885 2932 50  0000 C CNN
F 2 "" H 6880 3105 50  0001 C CNN
F 3 "" H 6880 3105 50  0001 C CNN
	1    6880 3105
	1    0    0    -1  
$EndComp
Wire Wire Line
	6830 3105 6880 3105
$Comp
L toad2-rescue:+12V-power-allcolours_analogue-rescue #PWR?
U 1 1 60A8A778
P 5530 3405
AR Path="/5ED966D6/60A8A778" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/60A8A778" Ref="#PWR?"  Part="1" 
AR Path="/60663957/60A8A778" Ref="#PWR?"  Part="1" 
AR Path="/60663E79/60A8A778" Ref="#PWR0139"  Part="1" 
F 0 "#PWR0139" H 5530 3255 50  0001 C CNN
F 1 "+12V-power" H 5545 3578 50  0000 C CNN
F 2 "" H 5530 3405 50  0001 C CNN
F 3 "" H 5530 3405 50  0001 C CNN
	1    5530 3405
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60A8A77E
P 5680 3505
AR Path="/5EC7DA76/60A8A77E" Ref="C?"  Part="1" 
AR Path="/5ED966D6/60A8A77E" Ref="C?"  Part="1" 
AR Path="/60663957/60A8A77E" Ref="C?"  Part="1" 
AR Path="/60663E79/60A8A77E" Ref="C59"  Part="1" 
F 0 "C59" H 5772 3551 50  0000 L CNN
F 1 "100N" H 5772 3460 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5680 3505 50  0001 C CNN
F 3 "~" H 5680 3505 50  0001 C CNN
	1    5680 3505
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 60A8A785
P 7005 3405
AR Path="/5ED966D6/60A8A785" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/60A8A785" Ref="#PWR?"  Part="1" 
AR Path="/60663957/60A8A785" Ref="#PWR?"  Part="1" 
AR Path="/60663E79/60A8A785" Ref="#PWR0157"  Part="1" 
F 0 "#PWR0157" H 7005 3505 50  0001 C CNN
F 1 "-12V" H 7020 3578 50  0000 C CNN
F 2 "" H 7005 3405 50  0001 C CNN
F 3 "" H 7005 3405 50  0001 C CNN
	1    7005 3405
	-1   0    0    1   
$EndComp
Wire Wire Line
	6030 3405 5680 3405
Connection ~ 5680 3405
Wire Wire Line
	5680 3405 5530 3405
$Comp
L power:GND #PWR0142
U 1 1 60A8A78E
P 5680 3640
F 0 "#PWR0142" H 5680 3390 50  0001 C CNN
F 1 "GND" H 5685 3467 50  0000 C CNN
F 2 "" H 5680 3640 50  0001 C CNN
F 3 "" H 5680 3640 50  0001 C CNN
	1    5680 3640
	1    0    0    -1  
$EndComp
Wire Wire Line
	5680 3605 5680 3640
Wire Wire Line
	6830 3405 6875 3405
$Comp
L Device:C_Small C?
U 1 1 60A8A796
P 6875 3525
AR Path="/5EC7DA76/60A8A796" Ref="C?"  Part="1" 
AR Path="/5ED966D6/60A8A796" Ref="C?"  Part="1" 
AR Path="/60663957/60A8A796" Ref="C?"  Part="1" 
AR Path="/60663E79/60A8A796" Ref="C62"  Part="1" 
F 0 "C62" H 6675 3380 50  0000 L CNN
F 1 "100N" H 6975 3350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6875 3525 50  0001 C CNN
F 3 "~" H 6875 3525 50  0001 C CNN
	1    6875 3525
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0153
U 1 1 60A8A79D
P 6875 3660
F 0 "#PWR0153" H 6875 3410 50  0001 C CNN
F 1 "GND" H 6880 3487 50  0000 C CNN
F 2 "" H 6875 3660 50  0001 C CNN
F 3 "" H 6875 3660 50  0001 C CNN
	1    6875 3660
	1    0    0    -1  
$EndComp
Wire Wire Line
	6875 3625 6875 3660
Wire Wire Line
	6875 3405 6875 3425
Connection ~ 6875 3405
Wire Wire Line
	6875 3405 7005 3405
$Comp
L power:GND #PWR0147
U 1 1 60A8A7A9
P 5900 2905
F 0 "#PWR0147" H 5900 2655 50  0001 C CNN
F 1 "GND" H 5780 2865 50  0000 C CNN
F 2 "" H 5900 2905 50  0001 C CNN
F 3 "" H 5900 2905 50  0001 C CNN
	1    5900 2905
	1    0    0    -1  
$EndComp
Wire Wire Line
	6030 3105 5770 3105
Wire Wire Line
	6830 2805 6895 2805
$Comp
L toad2-rescue:+12V-power-allcolours_analogue-rescue #PWR?
U 1 1 60AA7393
P 2880 2230
AR Path="/5ED966D6/60AA7393" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/60AA7393" Ref="#PWR?"  Part="1" 
AR Path="/60663957/60AA7393" Ref="#PWR?"  Part="1" 
AR Path="/60663E79/60AA7393" Ref="#PWR0164"  Part="1" 
F 0 "#PWR0164" H 2880 2080 50  0001 C CNN
F 1 "+12V-power" H 2895 2403 50  0000 C CNN
F 2 "" H 2880 2230 50  0001 C CNN
F 3 "" H 2880 2230 50  0001 C CNN
	1    2880 2230
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR?
U 1 1 60AA73B8
P 3180 2100
AR Path="/5ED966D6/60AA73B8" Ref="#PWR?"  Part="1" 
AR Path="/5EC7DA76/60AA73B8" Ref="#PWR?"  Part="1" 
AR Path="/60663957/60AA73B8" Ref="#PWR?"  Part="1" 
AR Path="/60663E79/60AA73B8" Ref="#PWR0166"  Part="1" 
F 0 "#PWR0166" H 3180 2200 50  0001 C CNN
F 1 "-12V" H 3195 2273 50  0000 C CNN
F 2 "" H 3180 2100 50  0001 C CNN
F 3 "" H 3180 2100 50  0001 C CNN
	1    3180 2100
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60AA7411
P 2880 2365
AR Path="/5EC7DA76/60AA7411" Ref="C?"  Part="1" 
AR Path="/5ED966D6/60AA7411" Ref="C?"  Part="1" 
AR Path="/60663957/60AA7411" Ref="C?"  Part="1" 
AR Path="/60663E79/60AA7411" Ref="C63"  Part="1" 
F 0 "C63" H 2972 2411 50  0000 L CNN
F 1 "100N" H 2972 2320 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2880 2365 50  0001 C CNN
F 3 "~" H 2880 2365 50  0001 C CNN
	1    2880 2365
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60AA760F
P 3270 2205
AR Path="/5EC7DA76/60AA760F" Ref="C?"  Part="1" 
AR Path="/5ED966D6/60AA760F" Ref="C?"  Part="1" 
AR Path="/60663957/60AA760F" Ref="C?"  Part="1" 
AR Path="/60663E79/60AA760F" Ref="C64"  Part="1" 
F 0 "C64" H 3362 2251 50  0000 L CNN
F 1 "100N" H 3362 2160 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3270 2205 50  0001 C CNN
F 3 "~" H 3270 2205 50  0001 C CNN
	1    3270 2205
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0165
U 1 1 60AA76E5
P 2880 2500
F 0 "#PWR0165" H 2880 2250 50  0001 C CNN
F 1 "GND" H 2885 2327 50  0000 C CNN
F 2 "" H 2880 2500 50  0001 C CNN
F 3 "" H 2880 2500 50  0001 C CNN
	1    2880 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0167
U 1 1 60AA7768
P 3270 2335
F 0 "#PWR0167" H 3270 2085 50  0001 C CNN
F 1 "GND" H 3275 2162 50  0000 C CNN
F 2 "" H 3270 2335 50  0001 C CNN
F 3 "" H 3270 2335 50  0001 C CNN
	1    3270 2335
	1    0    0    -1  
$EndComp
Wire Wire Line
	2880 2230 2880 2265
Wire Wire Line
	2880 2465 2880 2500
Wire Wire Line
	3270 2305 3270 2335
Wire Wire Line
	3180 2100 3270 2100
Wire Wire Line
	3270 2100 3270 2105
Text Notes 3550 2355 0    79   ~ 0
fixed for smd version! AD633JR
Wire Wire Line
	3635 2765 3635 2905
Wire Wire Line
	3635 2765 3895 2765
Wire Wire Line
	3635 2905 3485 2905
Connection ~ 3635 2905
Wire Wire Line
	3635 2905 3635 3065
Text GLabel 3485 2905 0    79   Input ~ 0
B3
Wire Wire Line
	4695 2765 5770 2765
Wire Wire Line
	5770 2805 5770 2765
Wire Wire Line
	5770 2805 6030 2805
Text GLabel 5770 3105 0    79   Input ~ 0
B2
Text GLabel 6895 2805 2    79   Input ~ 0
OUTX2
$EndSCHEMATC
