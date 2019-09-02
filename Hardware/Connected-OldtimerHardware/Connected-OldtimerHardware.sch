EESchema Schematic File Version 4
LIBS:Connected-OldtimerHardware-cache
EELAYER 26 0
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
L Connector_Generic:Conn_02x18_Counter_Clockwise J1
U 1 1 5D662EEF
P 2700 2850
F 0 "J1" H 2750 3867 50  0000 C CNN
F 1 "Particle_Electron" H 2750 3776 50  0000 C CNN
F 2 "Particle:electron" H 2700 2850 50  0001 C CNN
F 3 "~" H 2700 2850 50  0001 C CNN
	1    2700 2850
	1    0    0    -1  
$EndComp
Text GLabel 2500 2050 0    50   Input ~ 0
VIN
Text GLabel 2500 2150 0    50   Input ~ 0
GND
Text GLabel 2500 2250 0    50   Input ~ 0
TX
Text GLabel 2500 2350 0    50   Input ~ 0
RX
Text GLabel 2500 2450 0    50   Input ~ 0
WKP
Text GLabel 2500 2550 0    50   Input ~ 0
DAC
Text GLabel 2500 2650 0    50   Input ~ 0
A5
Text GLabel 2500 2750 0    50   Input ~ 0
A4
Text GLabel 2500 2850 0    50   Input ~ 0
A3
Text GLabel 2500 2950 0    50   Input ~ 0
A2
Text GLabel 2500 3050 0    50   Input ~ 0
A1
Text GLabel 2500 3150 0    50   Input ~ 0
A0
Text GLabel 2500 3250 0    50   Input ~ 0
B5
Text GLabel 2500 3350 0    50   Input ~ 0
B4
Text GLabel 2500 3450 0    50   Input ~ 0
B3
Text GLabel 2500 3550 0    50   Input ~ 0
B2
Text GLabel 2500 3650 0    50   Input ~ 0
B1
Text GLabel 2500 3750 0    50   Input ~ 0
B0
Text GLabel 3000 3750 2    50   Input ~ 0
C0
Text GLabel 3000 3650 2    50   Input ~ 0
C1
Text GLabel 3000 3550 2    50   Input ~ 0
C2
Text GLabel 3000 3450 2    50   Input ~ 0
C3
Text GLabel 3000 3350 2    50   Input ~ 0
C4
Text GLabel 3000 3250 2    50   Input ~ 0
C5
Text GLabel 3000 3150 2    50   Input ~ 0
D0
Text GLabel 3000 3050 2    50   Input ~ 0
D1
Text GLabel 3000 2950 2    50   Input ~ 0
D2
Text GLabel 3000 2850 2    50   Input ~ 0
D3
Text GLabel 3000 2750 2    50   Input ~ 0
D4
Text GLabel 3000 2650 2    50   Input ~ 0
D5
Text GLabel 3000 2550 2    50   Input ~ 0
D6
Text GLabel 3000 2450 2    50   Input ~ 0
D7
Text GLabel 3000 2350 2    50   Input ~ 0
GND
Text GLabel 3000 2250 2    50   Input ~ 0
VBAT
Text GLabel 3000 2150 2    50   Input ~ 0
RESET
Text GLabel 3000 2050 2    50   Input ~ 0
3V3
$Comp
L Connector_Generic:Conn_01x08 J3
U 1 1 5D6737BE
P 5500 3450
F 0 "J3" H 5580 3442 50  0000 L CNN
F 1 "FRAM" H 5580 3351 50  0000 L CNN
F 2 "" H 5500 3450 50  0001 C CNN
F 3 "~" H 5500 3450 50  0001 C CNN
	1    5500 3450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x09 J4
U 1 1 5D673A38
P 5500 5100
F 0 "J4" H 5580 5142 50  0000 L CNN
F 1 "GPS_Module" H 5580 5051 50  0000 L CNN
F 2 "" H 5500 5100 50  0001 C CNN
F 3 "~" H 5500 5100 50  0001 C CNN
	1    5500 5100
	1    0    0    -1  
$EndComp
Text GLabel 5300 3150 0    50   Input ~ 0
VIN
Text GLabel 5300 3250 0    50   Input ~ 0
GND
Text GLabel 5300 3450 0    50   Input ~ 0
D1
Text GLabel 5300 3550 0    50   Input ~ 0
D0
Text GLabel 5300 5400 0    50   Input ~ 0
VIN
Text GLabel 5300 5300 0    50   Input ~ 0
GND
Text GLabel 5300 5200 0    50   Input ~ 0
C1
Text GLabel 5300 5100 0    50   Input ~ 0
C0
$Comp
L Connector_Generic:Conn_01x04 J5
U 1 1 5D676AB8
P 7900 1750
F 0 "J5" H 7980 1742 50  0000 L CNN
F 1 "CAN_Bus_Connector" H 7980 1651 50  0000 L CNN
F 2 "" H 7900 1750 50  0001 C CNN
F 3 "~" H 7900 1750 50  0001 C CNN
	1    7900 1750
	1    0    0    -1  
$EndComp
Text GLabel 7700 1650 0    50   Input ~ 0
VIN
Text GLabel 7700 1750 0    50   Input ~ 0
GND
Text GLabel 7700 1850 0    50   Input ~ 0
CAN_H
Text GLabel 7700 1950 0    50   Input ~ 0
CAN_L
$Comp
L Connector_Generic:Conn_01x03 J6
U 1 1 5D67913E
P 7900 2750
F 0 "J6" H 7980 2792 50  0000 L CNN
F 1 "Motion_Sensor" H 7980 2701 50  0000 L CNN
F 2 "" H 7900 2750 50  0001 C CNN
F 3 "~" H 7900 2750 50  0001 C CNN
	1    7900 2750
	1    0    0    -1  
$EndComp
Text GLabel 7700 2650 0    50   Input ~ 0
3V3
Text GLabel 7700 2750 0    50   Input ~ 0
GND
Text GLabel 7700 2850 0    50   Input ~ 0
A0
$Comp
L HeathsComponents:CANTranceiverModule U?
U 1 1 5D6CF6EA
P 5800 1950
F 0 "U?" H 5827 2096 50  0000 L CNN
F 1 "CANTranceiverModule" H 5827 2005 50  0000 L CNN
F 2 "" H 5800 1950 50  0001 C CNN
F 3 "" H 5800 1950 50  0001 C CNN
	1    5800 1950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
