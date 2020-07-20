EESchema Schematic File Version 4
LIBS:touch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 940  1240 0    79   ~ 0
Own touch panel notes:\n- AtoB - connect with fingers (drop other connection), finger voltage(divider) into VCA/or LM13700 floating resistance for AtoB\n- Freeze/unfreeze that voltage/VCA \n
Text Notes 1770 3005 0    79   ~ 0
    C- feedback out conn    x4 aLLL\n    o-lock\nA-----B\n    0-adc\n    |\n    o-freeze\n    |\n    O-adc\n    |\n    o-freeze\n\n\n
Text Notes 7055 1900 0    79   ~ 0
touch panel also has outs but we don't need them here\nADC also goes straight there with dividers on panel\n
Text Notes 3255 715  0    79   ~ 0
REDO with STM and touch panel
Text Notes 2910 3270 0    79   ~ 16
Broken down to smaller conns for routing
$EndSCHEMATC
