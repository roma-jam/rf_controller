EESchema Schematic File Version 2
LIBS:adc_kl
LIBS:Antennas_kl
LIBS:Atmel_kl
LIBS:Audio_kl
LIBS:Connectors_kl
LIBS:display_kl
LIBS:ESDProtection
LIBS:Interface_kl
LIBS:lpc_rl
LIBS:memory
LIBS:modules
LIBS:pcb_details
LIBS:power
LIBS:Power_kl
LIBS:RF ICs
LIBS:Sensors
LIBS:Switches
LIBS:Tittar_kl
LIBS:Transformers
LIBS:Transistors_kl
LIBS:st_kl
LIBS:rf_controller-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L CONN_8 XL4
U 1 1 5BC99905
P 1300 4700
F 0 "XL4" V 1250 4700 50  0000 C CNN
F 1 "CONN_8" V 1350 4700 50  0000 C CNN
F 2 "Display:84x48_LCD_Module" H 1300 4700 60  0001 C CNN
F 3 "" H 1300 4700 60  0000 C CNN
	1    1300 4700
	-1   0    0    -1  
$EndComp
$Comp
L ST_SWD XL5
U 1 1 5BC999EE
P 1400 3600
F 0 "XL5" H 1250 3900 60  0000 C CNN
F 1 "ST_SWD" H 1600 3900 60  0000 C CNN
F 2 "Connectors:PLS-4" H 1400 3600 60  0001 C CNN
F 3 "" H 1400 3600 60  0000 C CNN
	1    1400 3600
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 XL3
U 1 1 5BC99A41
P 1300 2600
F 0 "XL3" V 1250 2600 40  0000 C CNN
F 1 "CONN_2" V 1350 2600 40  0000 C CNN
F 2 "Connectors:PLS-2" H 1300 2600 60  0001 C CNN
F 3 "" H 1300 2600 60  0000 C CNN
	1    1300 2600
	-1   0    0    1   
$EndComp
$Comp
L CONN_2 XL1
U 1 1 5BC99B08
P 900 6350
F 0 "XL1" V 850 6350 40  0000 C CNN
F 1 "CONN_2" V 950 6350 40  0000 C CNN
F 2 "Connectors:PLS-2" H 900 6350 60  0001 C CNN
F 3 "" H 900 6350 60  0000 C CNN
	1    900  6350
	-1   0    0    1   
$EndComp
$Comp
L SWITCH SW1
U 1 1 5BC99BF1
P 1550 6250
F 0 "SW1" H 1300 6500 60  0000 C CNN
F 1 "SWITCH" H 1650 6500 60  0000 C CNN
F 2 "BtnsSwitches:SW_SS-1P2T" H 1550 6250 60  0001 C CNN
F 3 "" H 1550 6250 60  0000 C CNN
	1    1550 6250
	-1   0    0    -1  
$EndComp
NoConn ~ 1300 6150
$Comp
L C C1
U 1 1 5BC99C9D
P 2100 6600
F 0 "C1" H 2000 6500 50  0000 L CNN
F 1 "0.1u" H 2000 6700 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 2200 6450 28  0000 C BNN
F 3 "" H 2100 6600 60  0000 C CNN
	1    2100 6600
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5BC99CC0
P 2400 6600
F 0 "C2" H 2300 6500 50  0000 L CNN
F 1 "10u" H 2300 6700 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 2500 6450 28  0000 C BNN
F 3 "" H 2400 6600 60  0000 C CNN
	1    2400 6600
	1    0    0    -1  
$EndComp
$Comp
L L L1
U 1 1 5BC99DBF
P 2750 6250
F 0 "L1" V 2650 6110 40  0000 C CNN
F 1 "22uH" V 2650 6250 40  0000 C CNN
F 2 "Inductors:CD_type_6.0X5.5" V 2810 6260 40  0001 C CNN
F 3 "" H 2750 6250 60  0000 C CNN
	1    2750 6250
	0    1    1    0   
$EndComp
$Comp
L NCP1400 DA1
U 1 1 5BC99E02
P 3600 6350
F 0 "DA1" H 3400 6600 60  0000 C CNN
F 1 "NCP1400" H 3800 6600 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5_HandSoldering" H 3600 6350 60  0001 C CNN
F 3 "" H 3600 6350 60  0000 C CNN
	1    3600 6350
	1    0    0    -1  
$EndComp
$Comp
L D_Shottky D1
U 1 1 5BC99E6F
P 3600 5900
F 0 "D1" H 3600 6000 40  0000 C CNN
F 1 "MBR052" H 3600 5800 40  0000 C CNN
F 2 "Diodes:SOD323" H 3600 5900 60  0001 C CNN
F 3 "" H 3600 5900 60  0000 C CNN
	1    3600 5900
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR01
U 1 1 5BC99FFD
P 4650 6250
F 0 "#PWR01" H 4650 6210 30  0001 C CNN
F 1 "+3.3V" H 4730 6280 30  0000 C CNN
F 2 "" H 4650 6250 60  0000 C CNN
F 3 "" H 4650 6250 60  0000 C CNN
	1    4650 6250
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 5BC9A027
P 4300 6550
F 0 "C8" H 4200 6450 50  0000 L CNN
F 1 "0.1u" H 4200 6650 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 4400 6400 28  0000 C BNN
F 3 "" H 4300 6550 60  0000 C CNN
	1    4300 6550
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 5BC9A072
P 4550 6550
F 0 "C9" H 4450 6450 50  0000 L CNN
F 1 "10u" H 4450 6650 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 4650 6400 28  0000 C BNN
F 3 "" H 4550 6550 60  0000 C CNN
	1    4550 6550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5BC9A233
P 1550 7000
F 0 "#PWR02" H 1640 6980 30  0001 C CNN
F 1 "GND" H 1550 6920 30  0001 C CNN
F 2 "" H 1550 7000 60  0000 C CNN
F 3 "" H 1550 7000 60  0000 C CNN
	1    1550 7000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5BC9A261
P 2100 7000
F 0 "#PWR03" H 2190 6980 30  0001 C CNN
F 1 "GND" H 2100 6920 30  0001 C CNN
F 2 "" H 2100 7000 60  0000 C CNN
F 3 "" H 2100 7000 60  0000 C CNN
	1    2100 7000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5BC9A2B8
P 3050 7000
F 0 "#PWR04" H 3140 6980 30  0001 C CNN
F 1 "GND" H 3050 6920 30  0001 C CNN
F 2 "" H 3050 7000 60  0000 C CNN
F 3 "" H 3050 7000 60  0000 C CNN
	1    3050 7000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5BC9A368
P 2400 7000
F 0 "#PWR05" H 2490 6980 30  0001 C CNN
F 1 "GND" H 2400 6920 30  0001 C CNN
F 2 "" H 2400 7000 60  0000 C CNN
F 3 "" H 2400 7000 60  0000 C CNN
	1    2400 7000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5BC9A3A3
P 4300 6950
F 0 "#PWR06" H 4390 6930 30  0001 C CNN
F 1 "GND" H 4300 6870 30  0001 C CNN
F 2 "" H 4300 6950 60  0000 C CNN
F 3 "" H 4300 6950 60  0000 C CNN
	1    4300 6950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5BC9A3D1
P 4550 6950
F 0 "#PWR07" H 4640 6930 30  0001 C CNN
F 1 "GND" H 4550 6870 30  0001 C CNN
F 2 "" H 4550 6950 60  0000 C CNN
F 3 "" H 4550 6950 60  0000 C CNN
	1    4550 6950
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR08
U 1 1 5BC9A589
P 2100 5950
F 0 "#PWR08" H 2100 5910 30  0001 C CNN
F 1 "+BATT" H 2180 5980 30  0000 C CNN
F 2 "" H 2100 5950 60  0000 C CNN
F 3 "" H 2100 5950 60  0000 C CNN
	1    2100 5950
	0    -1   -1   0   
$EndComp
Text Label 1850 2500 0    60   ~ 0
DBG_TX
$Comp
L GND #PWR09
U 1 1 5BC9A984
P 1850 2800
F 0 "#PWR09" H 1940 2780 30  0001 C CNN
F 1 "GND" H 1850 2720 30  0001 C CNN
F 2 "" H 1850 2800 60  0000 C CNN
F 3 "" H 1850 2800 60  0000 C CNN
	1    1850 2800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 5BC9AC7D
P 1850 4000
F 0 "#PWR010" H 1940 3980 30  0001 C CNN
F 1 "GND" H 1850 3920 30  0001 C CNN
F 2 "" H 1850 4000 60  0000 C CNN
F 3 "" H 1850 4000 60  0000 C CNN
	1    1850 4000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR011
U 1 1 5BC9AEAA
P 1850 3650
F 0 "#PWR011" H 1850 3610 30  0001 C CNN
F 1 "+3.3V" H 1930 3680 30  0000 C CNN
F 2 "" H 1850 3650 60  0000 C CNN
F 3 "" H 1850 3650 60  0000 C CNN
	1    1850 3650
	1    0    0    -1  
$EndComp
Text Label 1850 3550 0    60   ~ 0
SWDIO
Text Label 1850 3450 0    60   ~ 0
SWCLK
$Comp
L GND #PWR012
U 1 1 5BC9B403
P 1850 5300
F 0 "#PWR012" H 1940 5280 30  0001 C CNN
F 1 "GND" H 1850 5220 30  0001 C CNN
F 2 "" H 1850 5300 60  0000 C CNN
F 3 "" H 1850 5300 60  0000 C CNN
	1    1850 5300
	1    0    0    -1  
$EndComp
Text Label 1850 4350 0    60   ~ 0
LCD_RESET
Text Label 1850 4450 0    60   ~ 0
LCD_CE
Text Label 1850 4550 0    60   ~ 0
LCD_DC
Text Label 1850 4650 0    60   ~ 0
LCD_DIN
Text Label 1850 4750 0    60   ~ 0
LCD_CLK
Text Label 1850 4950 0    60   ~ 0
LCD_BCKLT
$Comp
L +3.3V #PWR013
U 1 1 5BC9B5FA
P 1850 4850
F 0 "#PWR013" H 1850 4810 30  0001 C CNN
F 1 "+3.3V" H 1930 4880 30  0000 C CNN
F 2 "" H 1850 4850 60  0000 C CNN
F 3 "" H 1850 4850 60  0000 C CNN
	1    1850 4850
	1    0    0    -1  
$EndComp
Text Label 7300 2150 0    60   ~ 0
CC1101_CS
Text Label 7300 2250 0    60   ~ 0
CC1101_CLK
Text Label 7300 2350 0    60   ~ 0
CC1101_MISO
Text Label 7300 2450 0    60   ~ 0
CC1101_MOSI
Text Label 7300 2050 0    60   ~ 0
CC1101_GDO0
Text Label 7300 1950 0    60   ~ 0
CC1101_GDO2
Text Label 7300 1850 0    60   ~ 0
BAT_MEASURE
$Comp
L +BATT #PWR014
U 1 1 5BC9C586
P 5550 5550
F 0 "#PWR014" H 5550 5510 30  0001 C CNN
F 1 "+BATT" H 5630 5580 30  0000 C CNN
F 2 "" H 5550 5550 60  0000 C CNN
F 3 "" H 5550 5550 60  0000 C CNN
	1    5550 5550
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 5BC9C6AB
P 5550 5900
F 0 "R2" V 5630 5750 50  0000 C CNN
F 1 "10k" V 5550 5900 50  0000 C CNN
F 2 "Capacitors:CAP_0603" V 5630 6000 28  0000 C CNN
F 3 "" H 5550 5900 60  0000 C CNN
	1    5550 5900
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5BC9C6DE
P 5550 6600
F 0 "R3" V 5630 6450 50  0000 C CNN
F 1 "10k" V 5550 6600 50  0000 C CNN
F 2 "Capacitors:CAP_0603" V 5630 6700 28  0000 C CNN
F 3 "" H 5550 6600 60  0000 C CNN
	1    5550 6600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5BC9C86C
P 5550 7000
F 0 "#PWR015" H 5640 6980 30  0001 C CNN
F 1 "GND" H 5550 6920 30  0001 C CNN
F 2 "" H 5550 7000 60  0000 C CNN
F 3 "" H 5550 7000 60  0000 C CNN
	1    5550 7000
	1    0    0    -1  
$EndComp
Text Label 5900 6250 0    60   ~ 0
BAT_MEASURE
Text Label 3900 2250 2    60   ~ 0
LCD_BCKLT
Text Label 3900 2350 2    60   ~ 0
LCD_RESET
Text Label 3900 2450 2    60   ~ 0
LCD_CE
Text Label 3900 2550 2    60   ~ 0
LCD_CLK
Text Label 3800 1750 2    60   ~ 0
RST
$Comp
L BUTTON SW2
U 1 1 5BC9D8CB
P 9250 3250
F 0 "SW2" H 9050 3400 50  0000 C CNN
F 1 "BUTTON" H 9350 3400 50  0000 C CNN
F 2 "BtnsSwitches:PUSH_THRHOLE_3-1825910-5" H 9250 3250 60  0001 C CNN
F 3 "" H 9250 3250 60  0000 C CNN
	1    9250 3250
	1    0    0    -1  
$EndComp
$Comp
L BUTTON SW3
U 1 1 5BC9D9CA
P 9250 3550
F 0 "SW3" H 9050 3700 50  0000 C CNN
F 1 "BUTTON" H 9350 3700 50  0000 C CNN
F 2 "BtnsSwitches:PUSH_THRHOLE_3-1825910-5" H 9250 3550 60  0001 C CNN
F 3 "" H 9250 3550 60  0000 C CNN
	1    9250 3550
	1    0    0    -1  
$EndComp
$Comp
L BUTTON SW4
U 1 1 5BC9DA11
P 9250 3850
F 0 "SW4" H 9050 4000 50  0000 C CNN
F 1 "BUTTON" H 9350 4000 50  0000 C CNN
F 2 "BtnsSwitches:PUSH_THRHOLE_3-1825910-5" H 9250 3850 60  0001 C CNN
F 3 "" H 9250 3850 60  0000 C CNN
	1    9250 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5BC9DCCA
P 9800 4250
F 0 "#PWR016" H 9890 4230 30  0001 C CNN
F 1 "GND" H 9800 4170 30  0001 C CNN
F 2 "" H 9800 4250 60  0000 C CNN
F 3 "" H 9800 4250 60  0000 C CNN
	1    9800 4250
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 XL6
U 1 1 5BC9DF42
P 7850 3850
F 0 "XL6" V 7800 3850 40  0000 C CNN
F 1 "CONN_3" V 7900 3850 40  0000 C CNN
F 2 "Connectors:PLS-3" H 7850 3850 60  0001 C CNN
F 3 "" H 7850 3850 60  0000 C CNN
	1    7850 3850
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 5BC9E2E8
P 9250 4100
F 0 "C11" H 9150 4000 50  0000 L CNN
F 1 "0.1u" H 9150 4200 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 9350 3950 28  0000 C BNN
F 3 "" H 9250 4100 60  0000 C CNN
	1    9250 4100
	0    1    1    0   
$EndComp
Text Label 8700 3250 2    60   ~ 0
BUTTON1
Text Label 8700 3550 2    60   ~ 0
BUTTON2
Text Label 8300 3750 0    60   ~ 0
BUTTON3
Text Label 8300 3950 0    60   ~ 0
RST
$Comp
L R R1
U 1 1 5BC9F5DD
P 3950 1450
F 0 "R1" V 4030 1300 50  0000 C CNN
F 1 "10k" V 3950 1450 50  0000 C CNN
F 2 "Capacitors:CAP_0603" V 4030 1550 28  0000 C CNN
F 3 "" H 3950 1450 60  0000 C CNN
	1    3950 1450
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR017
U 1 1 5BC9FB0D
P 3950 1100
F 0 "#PWR017" H 3950 1060 30  0001 C CNN
F 1 "+3.3V" H 4030 1130 30  0000 C CNN
F 2 "" H 3950 1100 60  0000 C CNN
F 3 "" H 3950 1100 60  0000 C CNN
	1    3950 1100
	0    -1   -1   0   
$EndComp
Text Label 7300 3050 0    60   ~ 0
SWDIO
Text Label 7300 3150 0    60   ~ 0
SWCLK
$Comp
L CONN_8 XL2
U 1 1 5BCA0BF1
P 1250 1500
F 0 "XL2" V 1200 1500 50  0000 C CNN
F 1 "CONN_8" V 1300 1500 50  0000 C CNN
F 2 "Installation:CC1101_MODULE" H 1250 1500 60  0001 C CNN
F 3 "" H 1250 1500 60  0000 C CNN
	1    1250 1500
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR018
U 1 1 5BCA1349
P 1850 2050
F 0 "#PWR018" H 1940 2030 30  0001 C CNN
F 1 "GND" H 1850 1970 30  0001 C CNN
F 2 "" H 1850 2050 60  0000 C CNN
F 3 "" H 1850 2050 60  0000 C CNN
	1    1850 2050
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR019
U 1 1 5BCA14A8
P 1850 1750
F 0 "#PWR019" H 1850 1710 30  0001 C CNN
F 1 "+3.3V" H 1930 1780 30  0000 C CNN
F 2 "" H 1850 1750 60  0000 C CNN
F 3 "" H 1850 1750 60  0000 C CNN
	1    1850 1750
	1    0    0    -1  
$EndComp
Text Label 1850 1650 0    60   ~ 0
CC1101_MOSI
Text Label 1850 1550 0    60   ~ 0
CC1101_CLK
Text Label 1850 1450 0    60   ~ 0
CC1101_MISO
Text Label 1850 1350 0    60   ~ 0
CC1101_GDO2
Text Label 1850 1250 0    60   ~ 0
CC1101_GDO0
Text Label 1850 1150 0    60   ~ 0
CC1101_CS
Text Label 7300 2650 0    60   ~ 0
DBG_TX
Text Label 10750 1800 0    60   ~ 0
BUTTON0
Text Label 8850 1800 2    60   ~ 0
ENCODER_CH1
Text Label 8850 2000 2    60   ~ 0
ENCODER_CH2
$Comp
L +3.3V #PWR020
U 1 1 5BCA2CBE
P 9000 1000
F 0 "#PWR020" H 9000 960 30  0001 C CNN
F 1 "+3.3V" H 9080 1030 30  0000 C CNN
F 2 "" H 9000 1000 60  0000 C CNN
F 3 "" H 9000 1000 60  0000 C CNN
	1    9000 1000
	0    -1   -1   0   
$EndComp
$Comp
L C C12
U 1 1 5BCA2F71
P 9500 2400
F 0 "C12" H 9400 2300 50  0000 L CNN
F 1 "1u" H 9400 2500 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 9600 2250 28  0000 C BNN
F 3 "" H 9500 2400 60  0000 C CNN
	1    9500 2400
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5BCA39CF
P 9000 2400
F 0 "C10" H 8900 2300 50  0000 L CNN
F 1 "1u" H 8900 2500 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 9100 2250 28  0000 C BNN
F 3 "" H 9000 2400 60  0000 C CNN
	1    9000 2400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 5BCA3B23
P 9000 2700
F 0 "#PWR021" H 9090 2680 30  0001 C CNN
F 1 "GND" H 9000 2620 30  0001 C CNN
F 2 "" H 9000 2700 60  0000 C CNN
F 3 "" H 9000 2700 60  0000 C CNN
	1    9000 2700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR022
U 1 1 5BCA3B67
P 9500 2700
F 0 "#PWR022" H 9590 2680 30  0001 C CNN
F 1 "GND" H 9500 2620 30  0001 C CNN
F 2 "" H 9500 2700 60  0000 C CNN
F 3 "" H 9500 2700 60  0000 C CNN
	1    9500 2700
	1    0    0    -1  
$EndComp
Text Label 7300 2750 0    60   ~ 0
BUTTON1
Text Label 7300 2850 0    60   ~ 0
BUTTON2
Text Label 7300 2950 0    60   ~ 0
BUTTON3
Wire Wire Line
	1300 6250 1100 6250
Wire Wire Line
	2100 5950 2100 6400
Wire Wire Line
	1900 6250 2550 6250
Wire Wire Line
	2400 6250 2400 6400
Connection ~ 2100 6250
Wire Wire Line
	2100 6800 2100 7000
Wire Wire Line
	2400 6800 2400 7000
Wire Wire Line
	1100 6450 1550 6450
Wire Wire Line
	1550 6450 1550 7000
Connection ~ 2400 6250
Wire Wire Line
	2950 6250 3150 6250
Wire Wire Line
	3050 6250 3050 5900
Wire Wire Line
	3050 5900 3400 5900
Connection ~ 3050 6250
Wire Wire Line
	3800 5900 4200 5900
Wire Wire Line
	4200 5900 4200 6350
Wire Wire Line
	4000 6250 4650 6250
Wire Wire Line
	4200 6350 4000 6350
Connection ~ 4200 6250
Wire Wire Line
	3150 6450 3050 6450
Wire Wire Line
	3050 6450 3050 7000
Wire Wire Line
	4550 6350 4550 6250
Connection ~ 4550 6250
Wire Wire Line
	4300 6350 4300 6250
Connection ~ 4300 6250
Wire Wire Line
	4300 6750 4300 6950
Wire Wire Line
	4550 6750 4550 6950
Wire Wire Line
	1500 2500 1850 2500
Wire Wire Line
	1500 2700 1850 2700
Wire Wire Line
	1850 2700 1850 2800
Wire Wire Line
	1750 3450 1850 3450
Wire Wire Line
	1750 3550 1850 3550
Wire Wire Line
	1750 3650 1850 3650
Wire Wire Line
	1750 3750 1850 3750
Wire Wire Line
	1850 3750 1850 4000
Wire Wire Line
	1500 4350 1850 4350
Wire Wire Line
	1500 4450 1850 4450
Wire Wire Line
	1500 4550 1850 4550
Wire Wire Line
	1500 4650 1850 4650
Wire Wire Line
	1500 4850 1850 4850
Wire Wire Line
	1500 4950 1850 4950
Wire Wire Line
	1500 5050 1850 5050
Wire Wire Line
	1850 5050 1850 5300
Wire Wire Line
	1500 4750 1850 4750
Wire Wire Line
	7050 2150 7300 2150
Wire Wire Line
	7050 2250 7300 2250
Wire Wire Line
	7300 2350 7050 2350
Wire Wire Line
	7050 2450 7300 2450
Wire Wire Line
	7300 1950 7050 1950
Wire Wire Line
	7300 2050 7050 2050
Wire Wire Line
	7300 1850 7050 1850
Wire Wire Line
	5550 6150 5550 6350
Wire Wire Line
	5550 5650 5550 5550
Wire Wire Line
	5550 6250 5900 6250
Connection ~ 5550 6250
Wire Wire Line
	5550 6850 5550 7000
Wire Wire Line
	4150 2250 3900 2250
Wire Wire Line
	4150 2350 3900 2350
Wire Wire Line
	4150 2450 3900 2450
Wire Wire Line
	4150 2550 3900 2550
Wire Wire Line
	4150 2650 3900 2650
Wire Wire Line
	3900 2750 4150 2750
Wire Wire Line
	3800 1750 4150 1750
Wire Wire Line
	9550 3250 9800 3250
Wire Wire Line
	9800 3250 9800 4250
Wire Wire Line
	9550 3550 9800 3550
Connection ~ 9800 3550
Wire Wire Line
	9550 3850 9800 3850
Connection ~ 9800 3850
Wire Wire Line
	8050 3850 8950 3850
Wire Wire Line
	8850 3850 8850 4100
Connection ~ 8850 3850
Wire Wire Line
	8850 4100 9050 4100
Wire Wire Line
	9800 4100 9450 4100
Connection ~ 9800 4100
Wire Wire Line
	8950 3250 8700 3250
Wire Wire Line
	8950 3550 8700 3550
Wire Wire Line
	8050 3950 8300 3950
Wire Wire Line
	8050 3750 8300 3750
Wire Wire Line
	3950 1700 3950 1750
Connection ~ 3950 1750
Wire Wire Line
	3950 1200 3950 1100
Wire Wire Line
	7050 3050 7300 3050
Wire Wire Line
	7050 3150 7300 3150
Wire Wire Line
	1450 1850 1850 1850
Wire Wire Line
	1850 1850 1850 2050
Wire Wire Line
	1450 1750 1850 1750
Wire Wire Line
	1450 1650 1850 1650
Wire Wire Line
	1850 1550 1450 1550
Wire Wire Line
	1450 1450 1850 1450
Wire Wire Line
	1450 1350 1850 1350
Wire Wire Line
	1450 1250 1850 1250
Wire Wire Line
	1450 1150 1850 1150
Wire Wire Line
	3900 2850 4150 2850
Wire Wire Line
	9500 1650 9500 2200
Wire Wire Line
	8850 1800 9650 1800
Wire Wire Line
	9000 1650 9000 2200
Connection ~ 9000 1800
Wire Wire Line
	9000 2600 9000 2700
Wire Wire Line
	9500 2600 9500 2700
Wire Wire Line
	7300 2650 7050 2650
Wire Wire Line
	7300 2850 7050 2850
Wire Wire Line
	7050 2750 7300 2750
Text Label 3900 2950 2    60   ~ 0
LCD_DIN
Text Label 3900 2850 2    60   ~ 0
LCD_DC
Wire Wire Line
	3900 2950 4150 2950
Text Label 3900 2650 2    60   ~ 0
ENCODER_CH1
Text Label 3900 2750 2    60   ~ 0
ENCODER_CH2
NoConn ~ 7050 3250
NoConn ~ 7050 3450
NoConn ~ 7050 3550
NoConn ~ 4150 3050
Wire Wire Line
	2800 3250 4150 3250
$Comp
L C C7
U 1 1 5BCA640A
P 3900 3850
F 0 "C7" H 3800 3750 50  0000 L CNN
F 1 "0.1u" H 3800 3950 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 4000 3700 28  0000 C BNN
F 3 "" H 3900 3850 60  0000 C CNN
	1    3900 3850
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 5BCA6457
P 3650 3850
F 0 "C6" H 3550 3750 50  0000 L CNN
F 1 "1u" H 3550 3950 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 3750 3700 28  0000 C BNN
F 3 "" H 3650 3850 60  0000 C CNN
	1    3650 3850
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 5BCA64A2
P 3400 3850
F 0 "C5" H 3300 3750 50  0000 L CNN
F 1 "0.1u" H 3300 3950 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 3500 3700 28  0000 C BNN
F 3 "" H 3400 3850 60  0000 C CNN
	1    3400 3850
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5BCA64FF
P 3150 3850
F 0 "C4" H 3050 3750 50  0000 L CNN
F 1 "0.1u" H 3050 3950 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 3250 3700 28  0000 C BNN
F 3 "" H 3150 3850 60  0000 C CNN
	1    3150 3850
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5BCA6554
P 2900 3850
F 0 "C3" H 2800 3750 50  0000 L CNN
F 1 "4u7" H 2800 3950 50  0000 L CNN
F 2 "Capacitors:CAP_0603" V 3000 3700 28  0000 C BNN
F 3 "" H 2900 3850 60  0000 C CNN
	1    2900 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3550 3900 3650
Wire Wire Line
	3600 3550 4150 3550
Wire Wire Line
	3650 3650 3650 3550
Connection ~ 3900 3550
Connection ~ 3650 3550
Wire Wire Line
	3400 3650 3400 3350
Wire Wire Line
	3350 3350 4150 3350
Connection ~ 3400 3350
Wire Wire Line
	3150 3650 3150 3250
Connection ~ 3150 3250
Wire Wire Line
	2900 3650 2900 3250
Connection ~ 2900 3250
Wire Wire Line
	2900 4050 2900 4200
Wire Wire Line
	3900 4200 3900 4050
Wire Wire Line
	3650 4050 3650 4200
Wire Wire Line
	3400 4050 3400 4200
Wire Wire Line
	3150 4050 3150 4200
Wire Wire Line
	5250 3850 5250 4200
Wire Wire Line
	5500 3850 5500 4200
$Comp
L GND #PWR023
U 1 1 5BCA721E
P 5500 4200
F 0 "#PWR023" H 5590 4180 30  0001 C CNN
F 1 "GND" H 5500 4120 30  0001 C CNN
F 2 "" H 5500 4200 60  0000 C CNN
F 3 "" H 5500 4200 60  0000 C CNN
	1    5500 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 5BCA726C
P 5250 4200
F 0 "#PWR024" H 5340 4180 30  0001 C CNN
F 1 "GND" H 5250 4120 30  0001 C CNN
F 2 "" H 5250 4200 60  0000 C CNN
F 3 "" H 5250 4200 60  0000 C CNN
	1    5250 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 5BCA73A2
P 3900 4200
F 0 "#PWR025" H 3990 4180 30  0001 C CNN
F 1 "GND" H 3900 4120 30  0001 C CNN
F 2 "" H 3900 4200 60  0000 C CNN
F 3 "" H 3900 4200 60  0000 C CNN
	1    3900 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR026
U 1 1 5BCA73F0
P 3650 4200
F 0 "#PWR026" H 3740 4180 30  0001 C CNN
F 1 "GND" H 3650 4120 30  0001 C CNN
F 2 "" H 3650 4200 60  0000 C CNN
F 3 "" H 3650 4200 60  0000 C CNN
	1    3650 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 5BCA743E
P 3400 4200
F 0 "#PWR027" H 3490 4180 30  0001 C CNN
F 1 "GND" H 3400 4120 30  0001 C CNN
F 2 "" H 3400 4200 60  0000 C CNN
F 3 "" H 3400 4200 60  0000 C CNN
	1    3400 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 5BCA765C
P 3150 4200
F 0 "#PWR028" H 3240 4180 30  0001 C CNN
F 1 "GND" H 3150 4120 30  0001 C CNN
F 2 "" H 3150 4200 60  0000 C CNN
F 3 "" H 3150 4200 60  0000 C CNN
	1    3150 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 5BCA76AA
P 2900 4200
F 0 "#PWR029" H 2990 4180 30  0001 C CNN
F 1 "GND" H 2900 4120 30  0001 C CNN
F 2 "" H 2900 4200 60  0000 C CNN
F 3 "" H 2900 4200 60  0000 C CNN
	1    2900 4200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR030
U 1 1 5BCA79B0
P 2800 3250
F 0 "#PWR030" H 2800 3210 30  0001 C CNN
F 1 "+3.3V" H 2880 3280 30  0000 C CNN
F 2 "" H 2800 3250 60  0000 C CNN
F 3 "" H 2800 3250 60  0000 C CNN
	1    2800 3250
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR031
U 1 1 5BCA79FE
P 3350 3350
F 0 "#PWR031" H 3350 3310 30  0001 C CNN
F 1 "+3.3V" H 3430 3380 30  0000 C CNN
F 2 "" H 3350 3350 60  0000 C CNN
F 3 "" H 3350 3350 60  0000 C CNN
	1    3350 3350
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR032
U 1 1 5BCA7A4C
P 3600 3550
F 0 "#PWR032" H 3600 3510 30  0001 C CNN
F 1 "+3.3V" H 3680 3580 30  0000 C CNN
F 2 "" H 3600 3550 60  0000 C CNN
F 3 "" H 3600 3550 60  0000 C CNN
	1    3600 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	7050 2950 7300 2950
Text Label 7300 1750 0    60   ~ 0
BUTTON0
Wire Wire Line
	7300 1750 7050 1750
$Comp
L STM32F050K4_6 DD1
U 1 1 5BC9989C
P 5400 2950
F 0 "DD1" H 4650 4300 60  0000 C CNN
F 1 "STM32F050K4_6" H 5300 4300 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-32-1EP_5x5mm_Pitch0.5mm" H 5400 2950 60  0001 C CNN
F 3 "" H 5400 2950 60  0000 C CNN
	1    5400 2950
	1    0    0    -1  
$EndComp
NoConn ~ 7050 2550
$Comp
L GND #PWR033
U 1 1 5BCAB9EF
P 9250 2700
F 0 "#PWR033" H 9340 2680 30  0001 C CNN
F 1 "GND" H 9250 2620 30  0001 C CNN
F 2 "" H 9250 2700 60  0000 C CNN
F 3 "" H 9250 2700 60  0000 C CNN
	1    9250 2700
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5BCABE0A
P 9000 1400
F 0 "R4" V 9080 1250 50  0000 C CNN
F 1 "10k" V 9000 1400 50  0000 C CNN
F 2 "Capacitors:CAP_0603" V 9080 1500 28  0000 C CNN
F 3 "" H 9000 1400 60  0000 C CNN
	1    9000 1400
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5BCABE6B
P 9500 1400
F 0 "R5" V 9580 1250 50  0000 C CNN
F 1 "10k" V 9500 1400 50  0000 C CNN
F 2 "Capacitors:CAP_0603" V 9580 1500 28  0000 C CNN
F 3 "" H 9500 1400 60  0000 C CNN
	1    9500 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 1000 9000 1150
Wire Wire Line
	9000 1050 9500 1050
Wire Wire Line
	9500 1050 9500 1150
Connection ~ 9000 1050
$Comp
L ENC_E11X U1
U 1 1 5BCACFE1
P 10050 1900
F 0 "U1" H 10300 2250 60  0000 C CNN
F 1 "ENC_E11X" H 10000 2250 60  0000 C CNN
F 2 "BtnsSwitches:ENC_E11X" H 10050 1900 60  0001 C CNN
F 3 "" H 10050 1900 60  0000 C CNN
	1    10050 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10750 1800 10450 1800
Wire Wire Line
	10450 2000 10750 2000
Wire Wire Line
	10750 2000 10750 2250
$Comp
L GND #PWR034
U 1 1 5BCAD76F
P 10750 2250
F 0 "#PWR034" H 10840 2230 30  0001 C CNN
F 1 "GND" H 10750 2170 30  0001 C CNN
F 2 "" H 10750 2250 60  0000 C CNN
F 3 "" H 10750 2250 60  0000 C CNN
	1    10750 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 1900 9250 1900
Wire Wire Line
	9250 1900 9250 2700
Wire Wire Line
	8850 2000 9650 2000
Connection ~ 9500 2000
$EndSCHEMATC
