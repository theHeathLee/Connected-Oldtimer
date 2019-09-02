EESchema Schematic File Version 4
LIBS:Connected-OldtimerHardware-cache
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
Text GLabel 1500 1050 0    50   Input ~ 0
VIN
Text GLabel 1500 1150 0    50   Input ~ 0
GND
Text GLabel 1500 1250 0    50   Input ~ 0
TX
Text GLabel 1500 1350 0    50   Input ~ 0
RX
Text GLabel 1500 1450 0    50   Input ~ 0
WKP
Text GLabel 1500 1550 0    50   Input ~ 0
DAC
Text GLabel 1500 1650 0    50   Input ~ 0
A5
Text GLabel 1500 1750 0    50   Input ~ 0
A4
Text GLabel 1500 1850 0    50   Input ~ 0
A3
Text GLabel 1500 1950 0    50   Input ~ 0
A2
Text GLabel 1500 2050 0    50   Input ~ 0
A1
Text GLabel 1500 2150 0    50   Input ~ 0
A0
Text GLabel 1500 2250 0    50   Input ~ 0
B5
Text GLabel 1500 2350 0    50   Input ~ 0
B4
Text GLabel 1500 2450 0    50   Input ~ 0
B3
Text GLabel 1500 2550 0    50   Input ~ 0
B2
Text GLabel 1500 2650 0    50   Input ~ 0
B1
Text GLabel 1500 2750 0    50   Input ~ 0
B0
Text GLabel 4150 2550 0    50   Input ~ 0
VIN
Text GLabel 4150 2650 0    50   Input ~ 0
GND
Text GLabel 4150 2850 0    50   Input ~ 0
D1
Text GLabel 4150 2950 0    50   Input ~ 0
D0
Text GLabel 4100 4950 0    50   Input ~ 0
VIN
Text GLabel 4100 4850 0    50   Input ~ 0
GND
Text GLabel 4100 4750 0    50   Input ~ 0
C1
Text GLabel 4100 4650 0    50   Input ~ 0
C0
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 5D676AB8
P 7050 1100
F 0 "J1" H 7130 1092 50  0000 L CNN
F 1 "CAN_Bus_Connector" H 7130 1001 50  0000 L CNN
F 2 "" H 7050 1100 50  0001 C CNN
F 3 "~" H 7050 1100 50  0001 C CNN
	1    7050 1100
	1    0    0    -1  
$EndComp
Text GLabel 6850 1000 0    50   Input ~ 0
VIN
Text GLabel 6850 1100 0    50   Input ~ 0
GND
Text GLabel 6850 1200 0    50   Input ~ 0
CAN_H
Text GLabel 6850 1300 0    50   Input ~ 0
CAN_L
Text GLabel 6900 3100 0    50   Input ~ 0
3V3
Text GLabel 6900 3200 0    50   Input ~ 0
GND
Text GLabel 6900 3300 0    50   Input ~ 0
A0
$Comp
L Connected-OldtimerHardware-rescue:CANTranceiverModule-HeathsComponents U3
U 1 1 5D6CF6EA
P 4950 1300
F 0 "U3" H 4977 1446 50  0000 L CNN
F 1 "CANTranceiverModule" H 4977 1355 50  0000 L CNN
F 2 "" H 4950 1300 50  0001 C CNN
F 3 "" H 4950 1300 50  0001 C CNN
	1    4950 1300
	1    0    0    -1  
$EndComp
$Comp
L Connected-OldtimerHardware-rescue:ParticleElectron-HeathsComponents U1
U 1 1 5D6D05D3
P 2250 1650
F 0 "U1" H 2225 2515 50  0000 C CNN
F 1 "ParticleElectron" H 2225 2424 50  0000 C CNN
F 2 "" H 2250 1650 50  0001 C CNN
F 3 "" H 2250 1650 50  0001 C CNN
	1    2250 1650
	1    0    0    -1  
$EndComp
Text GLabel 2950 1050 2    50   Input ~ 0
3V3
Text GLabel 2950 1150 2    50   Input ~ 0
RESET
Text GLabel 2950 1250 2    50   Input ~ 0
VBAT
Text GLabel 2950 1350 2    50   Input ~ 0
GND
Text GLabel 2950 1450 2    50   Input ~ 0
D7
Text GLabel 2950 1550 2    50   Input ~ 0
D6
Text GLabel 2950 1650 2    50   Input ~ 0
D5
Text GLabel 2950 1750 2    50   Input ~ 0
D4
Text GLabel 2950 1850 2    50   Input ~ 0
D3
Text GLabel 2950 1950 2    50   Input ~ 0
D2
Text GLabel 2950 2050 2    50   Input ~ 0
D1
Text GLabel 2950 2150 2    50   Input ~ 0
D0
Text GLabel 2950 2250 2    50   Input ~ 0
C5
Text GLabel 2950 2350 2    50   Input ~ 0
C4
Text GLabel 2950 2450 2    50   Input ~ 0
C3
Text GLabel 2950 2550 2    50   Input ~ 0
C2
Text GLabel 2950 2650 2    50   Input ~ 0
C1
Text GLabel 2950 2750 2    50   Input ~ 0
C0
$Comp
L Connected-OldtimerHardware-rescue:AdafruitFRAM-HeathsComponents U4
U 1 1 5D6D08AC
P 4600 2800
F 0 "U4" H 5078 2746 50  0000 L CNN
F 1 "AdafruitFRAM" H 5078 2655 50  0000 L CNN
F 2 "" H 4600 2800 50  0001 C CNN
F 3 "" H 4600 2800 50  0001 C CNN
	1    4600 2800
	1    0    0    -1  
$EndComp
$Comp
L Connected-OldtimerHardware-rescue:AdafruitUltimateGPS-HeathsComponents U5
U 1 1 5D6D0C95
P 4750 4700
F 0 "U5" H 5127 4771 50  0000 L CNN
F 1 "AdafruitUltimateGPS" H 5127 4680 50  0000 L CNN
F 2 "" H 4750 4700 50  0001 C CNN
F 3 "" H 4750 4700 50  0001 C CNN
	1    4750 4700
	1    0    0    -1  
$EndComp
$Comp
L Connected-OldtimerHardware-rescue:MotionSensor-HeathsComponents U6
U 1 1 5D6D1163
P 7300 3200
F 0 "U6" H 7377 3246 50  0000 L CNN
F 1 "MotionSensor" H 7377 3155 50  0000 L CNN
F 2 "" H 7300 3200 50  0001 C CNN
F 3 "" H 7300 3200 50  0001 C CNN
	1    7300 3200
	1    0    0    -1  
$EndComp
$Comp
L Connected-OldtimerHardware-rescue:TSR_2-2450-DCDC U2
U 1 1 5D6D21AF
P 1850 4300
F 0 "U2" H 1905 4767 50  0000 C CNN
F 1 "TSR_2-2450" H 1905 4676 50  0000 C CNN
F 2 "SIP750W46P254L1400H1010Q3" H 1850 4300 50  0001 L BNN
F 3 "SIP-3 Tracopower" H 1850 4300 50  0001 L BNN
F 4 "TSR 2-2450" H 1850 4300 50  0001 L BNN "Field4"
F 5 "Unavailable" H 1850 4300 50  0001 L BNN "Field5"
F 6 "Traco Power" H 1850 4300 50  0001 L BNN "Field6"
F 7 "None" H 1850 4300 50  0001 L BNN "Field7"
F 8 "DC-DC Point of Load _POL_ Converter PCB mount; Input 6.5-36Vdc; Output 5Vdc at 2A; SIP Through hole package" H 1850 4300 50  0001 L BNN "Field8"
	1    1850 4300
	1    0    0    -1  
$EndComp
Text GLabel 2150 4100 2    50   Input ~ 0
12VIN
Text GLabel 2150 4300 2    50   Input ~ 0
GND
Text GLabel 2150 4500 2    50   Input ~ 0
VIN
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5D6D26A0
P 7050 1750
F 0 "J2" H 7129 1792 50  0000 L CNN
F 1 "MainConnector" H 7129 1701 50  0000 L CNN
F 2 "" H 7050 1750 50  0001 C CNN
F 3 "~" H 7050 1750 50  0001 C CNN
	1    7050 1750
	1    0    0    -1  
$EndComp
Text GLabel 6850 1650 0    50   Input ~ 0
12VIN
Text GLabel 6850 1750 0    50   Input ~ 0
IGN
Text GLabel 6850 1850 0    50   Input ~ 0
GND
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 5D6D2C3C
P 7050 2250
F 0 "J3" H 7130 2242 50  0000 L CNN
F 1 "NextionConnector" H 7130 2151 50  0000 L CNN
F 2 "" H 7050 2250 50  0001 C CNN
F 3 "~" H 7050 2250 50  0001 C CNN
	1    7050 2250
	1    0    0    -1  
$EndComp
Text GLabel 6850 2150 0    50   Input ~ 0
VIN
Text GLabel 6850 2250 0    50   Input ~ 0
GND
Text GLabel 6850 2350 0    50   Input ~ 0
Nextion_TX
Text GLabel 6850 2450 0    50   Input ~ 0
Nextion_RX
$Comp
L Connected-OldtimerHardware-rescue:SFH618A-2-Optothingo U?
U 1 1 5D6D2FE4
P 3500 6300
F 0 "U?" H 3500 6670 50  0000 C CNN
F 1 "SFH618A-2" H 3500 6579 50  0000 C CNN
F 2 "DIP762W50P254L458H480Q4" H 3500 6300 50  0001 L BNN
F 3 "DIP-4 Vishay" H 3500 6300 50  0001 L BNN
F 4 "SFH618A-2" H 3500 6300 50  0001 L BNN "Field4"
F 5 "Unavailable" H 3500 6300 50  0001 L BNN "Field5"
F 6 "Vishay Semiconductor" H 3500 6300 50  0001 L BNN "Field6"
F 7 "None" H 3500 6300 50  0001 L BNN "Field7"
F 8 "SFH618A Series Single Channel 55 V 5300 Vrms Phototransistor Optocoupler - DIP-4" H 3500 6300 50  0001 L BNN "Field8"
	1    3500 6300
	1    0    0    -1  
$EndComp
$Comp
L pspice:DIODE D?
U 1 1 5D6D3695
P 2300 6800
F 0 "D?" V 2346 6672 50  0000 R CNN
F 1 "DIODE" V 2255 6672 50  0000 R CNN
F 2 "" H 2300 6800 50  0001 C CNN
F 3 "~" H 2300 6800 50  0001 C CNN
	1    2300 6800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2300 6600 2300 6200
Wire Wire Line
	2900 6400 2900 7200
Wire Wire Line
	2900 7200 2300 7200
Wire Wire Line
	2300 7200 2300 7000
$Comp
L power:GND #PWR?
U 1 1 5D6D3822
P 2900 7250
F 0 "#PWR?" H 2900 7000 50  0001 C CNN
F 1 "GND" H 2905 7077 50  0000 C CNN
F 2 "" H 2900 7250 50  0001 C CNN
F 3 "" H 2900 7250 50  0001 C CNN
	1    2900 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 7200 2900 7200
Connection ~ 2900 7200
Wire Wire Line
	2900 7250 2900 7200
Text GLabel 1350 6200 0    50   Input ~ 0
IGN
Wire Wire Line
	2300 6200 2150 6200
$Comp
L Device:R_US R?
U 1 1 5D6D76D5
P 4250 6050
F 0 "R?" H 4318 6096 50  0000 L CNN
F 1 "10K" H 4318 6005 50  0000 L CNN
F 2 "" V 4290 6040 50  0001 C CNN
F 3 "~" H 4250 6050 50  0001 C CNN
	1    4250 6050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N3906 Q?
U 1 1 5D6DA052
P 5000 6200
F 0 "Q?" H 5190 6246 50  0000 L CNN
F 1 "2N3906" H 5190 6155 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 5200 6125 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3906.pdf" H 5000 6200 50  0001 L CNN
	1    5000 6200
	1    0    0    -1  
$EndComp
Text GLabel 5100 6400 3    50   Input ~ 0
3V3
$Comp
L Device:R_US R?
U 1 1 5D6DD806
P 5650 6000
F 0 "R?" V 5445 6000 50  0000 C CNN
F 1 "10K" V 5536 6000 50  0000 C CNN
F 2 "" V 5690 5990 50  0001 C CNN
F 3 "~" H 5650 6000 50  0001 C CNN
	1    5650 6000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D6DF4C3
P 5950 6100
F 0 "#PWR?" H 5950 5850 50  0001 C CNN
F 1 "GND" H 5955 5927 50  0000 C CNN
F 2 "" H 5950 6100 50  0001 C CNN
F 3 "" H 5950 6100 50  0001 C CNN
	1    5950 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 6200 4250 6200
Connection ~ 4250 6200
Wire Wire Line
	5100 6000 5500 6000
Wire Wire Line
	5800 6000 5950 6000
Wire Wire Line
	5950 6000 5950 6100
$Comp
L Device:R_US R?
U 1 1 5D6E30DE
P 4650 6200
F 0 "R?" V 4445 6200 50  0000 C CNN
F 1 "47K" V 4536 6200 50  0000 C CNN
F 2 "" V 4690 6190 50  0001 C CNN
F 3 "~" H 4650 6200 50  0001 C CNN
	1    4650 6200
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 6200 4500 6200
Text GLabel 4250 5750 1    50   Input ~ 0
3V3
Wire Wire Line
	4250 5750 4250 5900
Text GLabel 5100 5800 1    50   Input ~ 0
IGNSignal
Wire Wire Line
	5100 5800 5100 6000
Connection ~ 5100 6000
$Comp
L power:GND #PWR?
U 1 1 5D6E5F9A
P 4100 6700
F 0 "#PWR?" H 4100 6450 50  0001 C CNN
F 1 "GND" H 4105 6527 50  0000 C CNN
F 2 "" H 4100 6700 50  0001 C CNN
F 3 "" H 4100 6700 50  0001 C CNN
	1    4100 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 6400 4100 6700
$Comp
L Device:R_US R?
U 1 1 5D6E71F5
P 2000 6200
F 0 "R?" V 1795 6200 50  0000 C CNN
F 1 "7.5K" V 1886 6200 50  0000 C CNN
F 2 "" V 2040 6190 50  0001 C CNN
F 3 "~" H 2000 6200 50  0001 C CNN
	1    2000 6200
	0    1    1    0   
$EndComp
Wire Wire Line
	2300 6200 2900 6200
Connection ~ 2300 6200
Wire Wire Line
	1850 6200 1350 6200
$EndSCHEMATC
