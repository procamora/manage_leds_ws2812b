EESchema Schematic File Version 4
EELAYER 30 0
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
L Device:CP C3
U 1 1 5F9723EC
P 1750 2600
F 0 "C3" H 1868 2646 50  0000 L CNN
F 1 "1000uF" H 1868 2555 50  0000 L CNN
F 2 "" H 1788 2450 50  0001 C CNN
F 3 "~" H 1750 2600 50  0001 C CNN
	1    1750 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5F972BAE
P 3550 3600
F 0 "R3" V 3757 3600 50  0000 C CNN
F 1 "470" V 3666 3600 50  0000 C CNN
F 2 "" V 3480 3600 50  0001 C CNN
F 3 "~" H 3550 3600 50  0001 C CNN
	1    3550 3600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5F97329F
P 5900 4850
F 0 "#PWR0101" H 5900 4600 50  0001 C CNN
F 1 "GND" H 5905 4677 50  0000 C CNN
F 2 "" H 5900 4850 50  0001 C CNN
F 3 "" H 5900 4850 50  0001 C CNN
	1    5900 4850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5F977EEA
P 1250 2600
F 0 "J1" H 1330 2642 50  0000 L CNN
F 1 "Conn_01x03" H 1330 2551 50  0000 L CNN
F 2 "" H 1250 2600 50  0001 C CNN
F 3 "~" H 1250 2600 50  0001 C CNN
	1    1250 2600
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5F979168
P 3800 2150
F 0 "SW1" H 3800 2435 50  0000 C CNN
F 1 "SW_Push" H 3800 2344 50  0000 C CNN
F 2 "" H 3800 2350 50  0001 C CNN
F 3 "~" H 3800 2350 50  0001 C CNN
	1    3800 2150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5F97A82C
P 3850 1300
F 0 "SW2" H 3850 1585 50  0000 C CNN
F 1 "SW_Push" H 3850 1494 50  0000 C CNN
F 2 "" H 3850 1500 50  0001 C CNN
F 3 "~" H 3850 1500 50  0001 C CNN
	1    3850 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5F97ABC9
P 3300 2250
F 0 "R2" V 3507 2250 50  0000 C CNN
F 1 "10k" V 3416 2250 50  0000 C CNN
F 2 "" V 3230 2250 50  0001 C CNN
F 3 "~" H 3300 2250 50  0001 C CNN
	1    3300 2250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5F97AF17
P 3300 1400
F 0 "R1" V 3507 1400 50  0000 C CNN
F 1 "10k" V 3416 1400 50  0000 C CNN
F 2 "" V 3230 1400 50  0001 C CNN
F 3 "~" H 3300 1400 50  0001 C CNN
	1    3300 1400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5F97E30D
P 3050 1400
F 0 "#PWR0102" H 3050 1150 50  0001 C CNN
F 1 "GND" H 3055 1227 50  0000 C CNN
F 2 "" H 3050 1400 50  0001 C CNN
F 3 "" H 3050 1400 50  0001 C CNN
	1    3050 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5F97EE1A
P 3050 2250
F 0 "#PWR0103" H 3050 2000 50  0001 C CNN
F 1 "GND" H 3055 2077 50  0000 C CNN
F 2 "" H 3050 2250 50  0001 C CNN
F 3 "" H 3050 2250 50  0001 C CNN
	1    3050 2250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5F980989
P 8500 2500
F 0 "J2" H 8580 2492 50  0000 L CNN
F 1 "Conn_01x02" H 8580 2401 50  0000 L CNN
F 2 "" H 8500 2500 50  0001 C CNN
F 3 "~" H 8500 2500 50  0001 C CNN
	1    8500 2500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5F981A53
P 8700 2500
F 0 "#PWR0104" H 8700 2250 50  0001 C CNN
F 1 "GND" H 8705 2327 50  0000 C CNN
F 2 "" H 8700 2500 50  0001 C CNN
F 3 "" H 8700 2500 50  0001 C CNN
	1    8700 2500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5F9823B0
P 8700 2400
F 0 "#PWR0105" H 8700 2250 50  0001 C CNN
F 1 "+5V" H 8715 2573 50  0000 C CNN
F 2 "" H 8700 2400 50  0001 C CNN
F 3 "" H 8700 2400 50  0001 C CNN
	1    8700 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5F984437
P 5900 2300
F 0 "#PWR0106" H 5900 2150 50  0001 C CNN
F 1 "+5V" H 5915 2473 50  0000 C CNN
F 2 "" H 5900 2300 50  0001 C CNN
F 3 "" H 5900 2300 50  0001 C CNN
	1    5900 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2300 5900 2600
NoConn ~ 6500 3000
NoConn ~ 6100 2600
NoConn ~ 6500 3200
NoConn ~ 6500 3400
NoConn ~ 6500 3600
NoConn ~ 6500 3700
NoConn ~ 6500 3800
NoConn ~ 6500 3900
NoConn ~ 6500 4000
NoConn ~ 6500 4100
NoConn ~ 6500 4300
NoConn ~ 6500 4400
NoConn ~ 5500 3000
NoConn ~ 5500 3100
Wire Wire Line
	3150 1400 3050 1400
Wire Wire Line
	3050 2250 3150 2250
Wire Wire Line
	3450 1400 3550 1400
$Comp
L Device:CP C2
U 1 1 5F98DCBC
P 3800 2350
F 0 "C2" V 3545 2350 50  0000 C CNN
F 1 "1uF" V 3636 2350 50  0000 C CNN
F 2 "" H 3838 2200 50  0001 C CNN
F 3 "~" H 3800 2350 50  0001 C CNN
	1    3800 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	3550 1300 3550 1400
Wire Wire Line
	3550 1500 3700 1500
Wire Wire Line
	3550 1300 3650 1300
Wire Wire Line
	4050 1300 4150 1300
Wire Wire Line
	3650 2350 3550 2350
Wire Wire Line
	4000 2150 4100 2150
Wire Wire Line
	4100 2350 3950 2350
Connection ~ 3550 1400
Wire Wire Line
	3550 1400 3550 1500
Wire Wire Line
	3550 2350 3550 2250
Wire Wire Line
	3550 2150 3600 2150
Wire Wire Line
	3450 2250 3550 2250
Connection ~ 3550 2250
Wire Wire Line
	3550 2250 3550 2150
$Comp
L Device:CP C1
U 1 1 5F98E49E
P 3850 1500
F 0 "C1" V 3595 1500 50  0000 C CNN
F 1 "1uF" V 3686 1500 50  0000 C CNN
F 2 "" H 3888 1350 50  0001 C CNN
F 3 "~" H 3850 1500 50  0001 C CNN
	1    3850 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	4150 1500 4000 1500
$Comp
L power:GND #PWR0107
U 1 1 5F99570E
P 1450 2850
F 0 "#PWR0107" H 1450 2600 50  0001 C CNN
F 1 "GND" H 1455 2677 50  0000 C CNN
F 2 "" H 1450 2850 50  0001 C CNN
F 3 "" H 1450 2850 50  0001 C CNN
	1    1450 2850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 5F996025
P 1450 2350
F 0 "#PWR0108" H 1450 2200 50  0001 C CNN
F 1 "+5V" H 1465 2523 50  0000 C CNN
F 2 "" H 1450 2350 50  0001 C CNN
F 3 "" H 1450 2350 50  0001 C CNN
	1    1450 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2150 4100 2350
Wire Wire Line
	4150 1300 4150 1500
Wire Wire Line
	3550 2350 3550 3300
Wire Wire Line
	3550 3300 5500 3300
Connection ~ 3550 2350
Wire Wire Line
	3550 1500 3550 1750
Wire Wire Line
	3550 1750 4700 1750
Wire Wire Line
	4700 3200 5500 3200
Wire Wire Line
	4700 1750 4700 3200
Connection ~ 3550 1500
$Comp
L power:+5V #PWR0109
U 1 1 5F9AFD38
P 4100 2150
F 0 "#PWR0109" H 4100 2000 50  0001 C CNN
F 1 "+5V" H 4115 2323 50  0000 C CNN
F 2 "" H 4100 2150 50  0001 C CNN
F 3 "" H 4100 2150 50  0001 C CNN
	1    4100 2150
	1    0    0    -1  
$EndComp
Connection ~ 4100 2150
$Comp
L power:+5V #PWR0110
U 1 1 5F9B0545
P 4150 1300
F 0 "#PWR0110" H 4150 1150 50  0001 C CNN
F 1 "+5V" H 4165 1473 50  0000 C CNN
F 2 "" H 4150 1300 50  0001 C CNN
F 3 "" H 4150 1300 50  0001 C CNN
	1    4150 1300
	1    0    0    -1  
$EndComp
Connection ~ 4150 1300
Wire Wire Line
	1450 2350 1450 2450
Wire Wire Line
	1450 2700 1450 2750
Connection ~ 1450 2450
Wire Wire Line
	1450 2450 1450 2500
Wire Wire Line
	1750 2750 1450 2750
Connection ~ 1450 2750
Wire Wire Line
	1450 2750 1450 2850
Wire Wire Line
	1450 2450 1750 2450
Text Label 4300 1750 0    50   ~ 0
b_colour
Text Label 4150 3300 0    50   ~ 0
b_mode
Wire Wire Line
	1450 2600 1600 2600
Wire Wire Line
	5500 3600 3700 3600
Wire Wire Line
	3400 3600 1600 3600
Wire Wire Line
	1600 3600 1600 2600
$Comp
L Device:R_POT RV1
U 1 1 5F9BC66D
P 4100 4300
F 0 "RV1" H 4031 4346 50  0000 R CNN
F 1 "R_POT" H 4031 4255 50  0000 R CNN
F 2 "" H 4100 4300 50  0001 C CNN
F 3 "~" H 4100 4300 50  0001 C CNN
	1    4100 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5F9BD1F6
P 4100 4600
F 0 "#PWR0111" H 4100 4350 50  0001 C CNN
F 1 "GND" H 4105 4427 50  0000 C CNN
F 2 "" H 4100 4600 50  0001 C CNN
F 3 "" H 4100 4600 50  0001 C CNN
	1    4100 4600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0112
U 1 1 5F9BD9EB
P 4100 4000
F 0 "#PWR0112" H 4100 3850 50  0001 C CNN
F 1 "+5V" H 4115 4173 50  0000 C CNN
F 2 "" H 4100 4000 50  0001 C CNN
F 3 "" H 4100 4000 50  0001 C CNN
	1    4100 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4000 4100 4150
Wire Wire Line
	4100 4450 4100 4600
Wire Wire Line
	5900 4850 5900 4700
$Comp
L MCU_Module:Arduino_UNO_R3 A1
U 1 1 5F96DF4F
P 6000 3600
F 0 "A1" H 6000 4781 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 6000 4690 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 6000 3600 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 6000 3600 50  0001 C CNN
	1    6000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 4300 5500 4300
NoConn ~ 6000 4700
NoConn ~ 6100 4700
NoConn ~ 5500 3400
NoConn ~ 5500 3500
NoConn ~ 5500 3700
NoConn ~ 5500 3800
NoConn ~ 5500 3900
NoConn ~ 5500 4000
NoConn ~ 5500 4100
NoConn ~ 5500 4200
NoConn ~ 6200 2600
$EndSCHEMATC
