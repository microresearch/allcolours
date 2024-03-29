EESchema Schematic File Version 5
EELAYER 36 0
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
Comment5 ""
Comment6 ""
Comment7 ""
Comment8 ""
Comment9 ""
$EndDescr
Text Notes 865  1540 0    118  ~ 24
touch for own panels and touch for eurorack - fork to 2 versions only in IOjacks.sch\n\n\nNOW we revert to only 4! (6 is too many) sets of connections/voltages!
Text Notes 895  6375 0    118  ~ 0
\nNotes: that frozen levels are saved to a stack and can be popped off the stack, various over-rides...
Text Notes 6085 4805 0    118  ~ 24
       C- feedback out from jack\n       |\nA---VCA---B [B is also mix from B pad]\n       |\n       0-adc voltage for A->B VCA\n       |\n       o-freeze\n       |\n       O-adc voltage for insert\n       |\n       o-freeze\n\n\n
$Sheet
S 2695 2535 1710 330 
U 5EED4BC5
F0 "IOjacks" 79
F1 "IOjacks.sch" 79
$EndSheet
$Sheet
S 745  3560 1740 410 
U 5EBFD180
F0 "euro_touch" 118
F1 "euro_touch.sch" 118
$EndSheet
$Sheet
S 2655 4290 1780 470 
U 5F0CAD2E
F0 "freeze" 79
F1 "freeze.sch" 79
$EndSheet
$Sheet
S 715  4320 1710 520 
U 5EEBC3AA
F0 "micro" 79
F1 "micro.sch" 79
$EndSheet
$Sheet
S 2715 3575 1925 395 
U 5EED47D5
F0 "mixetc" 79
F1 "mixetc.sch" 79
$EndSheet
$Sheet
S 725  5170 1720 480 
U 5F99750E
F0 "panel_connector" 50
F1 "panel_connector.sch" 50
$EndSheet
$Sheet
S 805  2540 1725 345 
U 5EBFD178
F0 "power" 118
F1 "euro_power.sch" 118
$EndSheet
$EndSCHEMATC
