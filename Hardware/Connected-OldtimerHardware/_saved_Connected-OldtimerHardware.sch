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
Text GLabel 1500 1050 0    50   Input ~ 0
5VDC
Text GLabel 1500 1250 0    50   Input ~ 0
TX
Text GLabel 1500 1350 0    50   Input ~ 0
RX
Text GLabel 1500 1550 0    50   Input ~ 0
DAC
Text GLabel 1500 1450 0    50   Input ~ 0
Shock_Signal
Text GLabel 4150 2550 0    50   Input ~ 0
5VDC
Text GLabel 4150 2850 0    50   Input ~ 0
FRAM_SCL
Text GLabel 4150 2950 0    50   Input ~ 0
FRAM_SDA
Text GLabel 4100 4950 0    50   Input ~ 0
3V3
Text GLabel 4100 4750 0    50   Input ~ 0
GPS_RX
Text GLabel 4100 4650 0    50   Input ~ 0
GPS_TX
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 5D676AB8
P 9750 1650
F 0 "J1" H 9830 1642 50  0000 L CNN
F 1 "CAN_Bus_Connector" H 9830 1551 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B04B-XH-A_1x04_P2.50mm_Vertical" H 9750 1650 50  0001 C CNN
F 3 "~" H 9750 1650 50  0001 C CNN
	1    9750 1650
	1    0    0    -1  
$EndComp
Text GLabel 8750 1300 0    50   Input ~ 0
5VDC
Text GLabel 9550 1750 0    50   Input ~ 0
CAN_H
Text GLabel 9550 1850 0    50   Input ~ 0
CAN_L
Text GLabel 7100 5200 0    50   Input ~ 0
3V3
Text GLabel 7100 5400 0    50   Input ~ 0
Shock_Signal
$Comp
L Connected-OldtimerHardware-rescue:CANTranceiverModule-HeathsComponents U3
U 1 1 5D6CF6EA
P 4950 1300
F 0 "U3" H 4977 1446 50  0000 L CNN
F 1 "CANTranceiverModule" H 4977 1355 50  0000 L CNN
F 2 "heathsfootprints:CAN_Tranceiver_Module" H 4950 1300 50  0001 C CNN
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
F 2 "Particle:electron" H 2250 1650 50  0001 C CNN
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
Text GLabel 2950 2050 2    50   Input ~ 0
FRAM_SCL
Text GLabel 2950 2150 2    50   Input ~ 0
FRAM_SDA
Text GLabel 2950 2450 2    50   Input ~ 0
Nextion_RX
Text GLabel 2950 2550 2    50   Input ~ 0
Nextion_TX
Text GLabel 2950 2650 2    50   Input ~ 0
GPS_RX
Text GLabel 2950 2750 2    50   Input ~ 0
GPS_TX
$Comp
L Connected-OldtimerHardware-rescue:AdafruitFRAM-HeathsComponents U4
U 1 1 5D6D08AC
P 4600 2800
F 0 "U4" H 5078 2746 50  0000 L CNN
F 1 "AdafruitFRAM" H 5078 2655 50  0000 L CNN
F 2 "heathsfootprints:Adafruit_I2C_FRAM" H 4600 2800 50  0001 C CNN
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
F 2 "heathsfootprints:AdafruitUltimateGPS" H 4750 4700 50  0001 C CNN
F 3 "" H 4750 4700 50  0001 C CNN
	1    4750 4700
	1    0    0    -1  
$EndComp
$Comp
L Connected-OldtimerHardware-rescue:MotionSensor-HeathsComponents U6
U 1 1 5D6D1163
P 7500 5300
F 0 "U6" H 7577 5346 50  0000 L CNN
F 1 "MotionSensor" H 7577 5255 50  0000 L CNN
F 2 "heathsfootprints:ShockSensor" H 7500 5300 50  0001 C CNN
F 3 "" H 7500 5300 50  0001 C CNN
	1    7500 5300
	1    0    0    -1  
$EndComp
$Comp
L Connected-OldtimerHardware-rescue:TSR_2-2450-DCDC U2
U 1 1 5D6D21AF
P 1850 4300
F 0 "U2" H 1905 4767 50  0000 C CNN
F 1 "TSR_2-2450" H 1905 4676 50  0000 C CNN
F 2 "heathsfootprints:heathsTRS_2_2450" H 1850 4300 50  0001 L BNN
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
Text GLabel 2900 5250 2    50   Input ~ 0
5VDC
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5D6D26A0
P 9750 2300
F 0 "J2" H 9829 2342 50  0000 L CNN
F 1 "MainConnector" H 9829 2251 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B03B-XH-A_1x03_P2.50mm_Vertical" H 9750 2300 50  0001 C CNN
F 3 "~" H 9750 2300 50  0001 C CNN
	1    9750 2300
	1    0    0    -1  
$EndComp
Text GLabel 9550 2200 0    50   Input ~ 0
12VIN
Text GLabel 9550 2300 0    50   Input ~ 0
IGN
Text GLabel 9550 2700 0    50   Input ~ 0
5VDC
Text GLabel 9550 2900 0    50   Input ~ 0
Nextion_TX
Text GLabel 9550 3000 0    50   Input ~ 0
Nextion_RX
$Comp
L Connected-OldtimerHardware-rescue:SFH618A-2-Optothingo U7
U 1 1 5D6D2FE4
P 3500 6300
F 0 "U7" H 3500 6670 50  0000 C CNN
F 1 "SFH618A-2" H 3500 6579 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm_Socket" H 3500 6300 50  0001 L BNN
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
L pspice:DIODE D1
U 1 1 5D6D3695
P 2300 6800
F 0 "D1" V 2346 6672 50  0000 R CNN
F 1 "DIODE" V 2255 6672 50  0000 R CNN
F 2 "Diode_THT:D_A-405_P10.16mm_Horizontal" H 2300 6800 50  0001 C CNN
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
L power:GND #PWR0101
U 1 1 5D6D3822
P 2900 7250
F 0 "#PWR0101" H 2900 7000 50  0001 C CNN
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
L Device:R_US R2
U 1 1 5D6D76D5
P 4250 6050
F 0 "R2" H 4318 6096 50  0000 L CNN
F 1 "10K" H 4318 6005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4290 6040 50  0001 C CNN
F 3 "~" H 4250 6050 50  0001 C CNN
	1    4250 6050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N3906 Q1
U 1 1 5D6DA052
P 5000 6200
F 0 "Q1" H 5190 6246 50  0000 L CNN
F 1 "2N3906" H 5190 6155 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 5200 6125 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3906.pdf" H 5000 6200 50  0001 L CNN
	1    5000 6200
	1    0    0    -1  
$EndComp
Text GLabel 5100 6400 3    50   Input ~ 0
3V3
$Comp
L Device:R_US R4
U 1 1 5D6DD806
P 5650 6000
F 0 "R4" V 5445 6000 50  0000 C CNN
F 1 "10K" V 5536 6000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5690 5990 50  0001 C CNN
F 3 "~" H 5650 6000 50  0001 C CNN
	1    5650 6000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5D6DF4C3
P 5950 6100
F 0 "#PWR0102" H 5950 5850 50  0001 C CNN
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
L Device:R_US R3
U 1 1 5D6E30DE
P 4650 6200
F 0 "R3" V 4445 6200 50  0000 C CNN
F 1 "47K" V 4536 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4690 6190 50  0001 C CNN
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
L power:GND #PWR0103
U 1 1 5D6E5F9A
P 4100 6700
F 0 "#PWR0103" H 4100 6450 50  0001 C CNN
F 1 "GND" H 4105 6527 50  0000 C CNN
F 2 "" H 4100 6700 50  0001 C CNN
F 3 "" H 4100 6700 50  0001 C CNN
	1    4100 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 6400 4100 6700
$Comp
L Device:R_US R1
U 1 1 5D6E71F5
P 2000 6200
F 0 "R1" V 1795 6200 50  0000 C CNN
F 1 "7.5K" V 1886 6200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2040 6190 50  0001 C CNN
F 3 "~" H 2000 6200 50  0001 C CNN
	1    2000 6200
	0    1    1    0   
$EndComp
Wire Wire Line
	2300 6200 2900 6200
Connection ~ 2300 6200
Wire Wire Line
	1850 6200 1350 6200
$Comp
L Connector_Generic:Conn_01x05 J3
U 1 1 5D6E0A2B
P 9750 2900
F 0 "J3" H 9830 2942 50  0000 L CNN
F 1 "NextionConnector" H 9830 2851 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B05B-XH-A_1x05_P2.50mm_Vertical" H 9750 2900 50  0001 C CNN
F 3 "~" H 9750 2900 50  0001 C CNN
	1    9750 2900
	1    0    0    -1  
$EndComp
Text GLabel 4150 850  0    50   Input ~ 0
5VDC
$Comp
L power:GND #PWR0104
U 1 1 5D6E3912
P 3700 1150
F 0 "#PWR0104" H 3700 900 50  0001 C CNN
F 1 "GND" H 3705 977 50  0000 C CNN
F 2 "" H 3700 1150 50  0001 C CNN
F 3 "" H 3700 1150 50  0001 C CNN
	1    3700 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 950  3700 950 
Wire Wire Line
	3700 950  3700 1150
Text GLabel 4150 1250 0    50   Input ~ 0
CAN_H
Text GLabel 4150 1350 0    50   Input ~ 0
CAN_L
Text GLabel 4150 1050 0    50   Input ~ 0
CAN_TX
Text GLabel 4150 1150 0    50   Input ~ 0
CAN_RX
Text GLabel 2950 2350 2    50   Input ~ 0
CAN_TX
Text GLabel 2950 2250 2    50   Input ~ 0
CAN_RX
$Comp
L power:GND #PWR0105
U 1 1 5D6E4235
P 3550 2800
F 0 "#PWR0105" H 3550 2550 50  0001 C CNN
F 1 "GND" H 3555 2627 50  0000 C CNN
F 2 "" H 3550 2800 50  0001 C CNN
F 3 "" H 3550 2800 50  0001 C CNN
	1    3550 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2650 3550 2800
$Comp
L power:GND #PWR0106
U 1 1 5D6E45EA
P 3650 5000
F 0 "#PWR0106" H 3650 4750 50  0001 C CNN
F 1 "GND" H 3655 4827 50  0000 C CNN
F 2 "" H 3650 5000 50  0001 C CNN
F 3 "" H 3650 5000 50  0001 C CNN
	1    3650 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4850 3650 4850
Wire Wire Line
	3650 4850 3650 5000
$Comp
L power:GND #PWR0107
U 1 1 5D6E50E1
P 9000 1700
F 0 "#PWR0107" H 9000 1450 50  0001 C CNN
F 1 "GND" H 9005 1527 50  0000 C CNN
F 2 "" H 9000 1700 50  0001 C CNN
F 3 "" H 9000 1700 50  0001 C CNN
	1    9000 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5D6E5123
P 8900 2900
F 0 "#PWR0108" H 8900 2650 50  0001 C CNN
F 1 "GND" H 8905 2727 50  0000 C CNN
F 2 "" H 8900 2900 50  0001 C CNN
F 3 "" H 8900 2900 50  0001 C CNN
	1    8900 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5D6E51A5
P 6350 5550
F 0 "#PWR0109" H 6350 5300 50  0001 C CNN
F 1 "GND" H 6355 5377 50  0000 C CNN
F 2 "" H 6350 5550 50  0001 C CNN
F 3 "" H 6350 5550 50  0001 C CNN
	1    6350 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5300 6350 5550
Wire Wire Line
	9550 2800 8900 2800
Wire Wire Line
	8900 2800 8900 2900
Wire Wire Line
	9550 1650 9000 1650
Wire Wire Line
	9000 1650 9000 1700
$Comp
L power:GND #PWR0110
U 1 1 5D6E5CD7
P 9000 2450
F 0 "#PWR0110" H 9000 2200 50  0001 C CNN
F 1 "GND" H 9005 2277 50  0000 C CNN
F 2 "" H 9000 2450 50  0001 C CNN
F 3 "" H 9000 2450 50  0001 C CNN
	1    9000 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 2400 9000 2400
Wire Wire Line
	9000 2400 9000 2450
$Comp
L power:GND #PWR0111
U 1 1 5D6E6529
P 3000 4400
F 0 "#PWR0111" H 3000 4150 50  0001 C CNN
F 1 "GND" H 3005 4227 50  0000 C CNN
F 2 "" H 3000 4400 50  0001 C CNN
F 3 "" H 3000 4400 50  0001 C CNN
	1    3000 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 4300 3000 4400
$Comp
L power:GND #PWR0112
U 1 1 5D6E6E4F
P 700 1250
F 0 "#PWR0112" H 700 1000 50  0001 C CNN
F 1 "GND" H 705 1077 50  0000 C CNN
F 2 "" H 700 1250 50  0001 C CNN
F 3 "" H 700 1250 50  0001 C CNN
	1    700  1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  1150 700  1250
$Comp
L Device:Polyfuse F2
U 1 1 5D6EB140
P 9150 1300
F 0 "F2" V 8925 1300 50  0000 C CNN
F 1 "Polyfuse 1000mA" V 9016 1300 50  0000 C CNN
F 2 "Fuse:Fuse_Littelfuse-LVR200" H 9200 1100 50  0001 L CNN
F 3 "~" H 9150 1300 50  0001 C CNN
	1    9150 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	9000 1300 8800 1300
Wire Wire Line
	9550 1550 9450 1550
Wire Wire Line
	9450 1550 9450 1300
Wire Wire Line
	9450 1300 9300 1300
Wire Wire Line
	2150 4300 3000 4300
$Comp
L Device:Polyfuse F1
U 1 1 5D6ED997
P 2550 5100
F 0 "F1" H 2638 5146 50  0000 L CNN
F 1 "Polyfuse 2000mA" H 2638 5055 50  0000 L CNN
F 2 "Fuse:Fuse_Littelfuse-LVR200" H 2600 4900 50  0001 L CNN
F 3 "~" H 2550 5100 50  0001 C CNN
	1    2550 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 5250 2550 5250
Wire Wire Line
	6350 5300 7100 5300
Wire Wire Line
	3550 2650 4150 2650
$Comp
L Device:Polyfuse F3
U 1 1 5D6F203B
P 9150 950
F 0 "F3" V 8925 950 50  0000 C CNN
F 1 "Polyfuse SMD 1000mA" V 9016 950 50  0000 C CNN
F 2 "Capacitor_SMD:C_1210_3225Metric_Pad1.42x2.65mm_HandSolder" H 9200 750 50  0001 L CNN
F 3 "~" H 9150 950 50  0001 C CNN
	1    9150 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	8800 950  8800 1300
Wire Wire Line
	8800 950  9000 950 
Connection ~ 8800 1300
Wire Wire Line
	8800 1300 8750 1300
Wire Wire Line
	9300 950  9450 950 
Wire Wire Line
	9450 950  9450 1300
Connection ~ 9450 1300
$Comp
L Device:Polyfuse F4
U 1 1 5D6F5FCB
P 1700 5100
F 0 "F4" H 1788 5146 50  0000 L CNN
F 1 "Polyfuse SMD 2000mA" H 1788 5055 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric_Pad1.42x2.65mm_HandSolder" H 1750 4900 50  0001 L CNN
F 3 "~" H 1700 5100 50  0001 C CNN
	1    1700 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4950 1700 4850
Wire Wire Line
	2150 4500 2550 4500
Wire Wire Line
	2550 4500 2550 4850
Wire Wire Line
	1700 4850 2550 4850
Connection ~ 2550 4850
Wire Wire Line
	2550 4850 2550 4950
Wire Wire Line
	2550 5250 1700 5250
Connection ~ 2550 5250
$Comp
L power:GND #PWR0113
U 1 1 5D70C303
P 9400 3850
F 0 "#PWR0113" H 9400 3600 50  0001 C CNN
F 1 "GND" H 9405 3677 50  0000 C CNN
F 2 "" H 9400 3850 50  0001 C CNN
F 3 "" H 9400 3850 50  0001 C CNN
	1    9400 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 3850 9400 3700
Wire Wire Line
	9400 3700 9550 3700
Text GLabel 9550 3400 0    50   Input ~ 0
AUX_1
Text GLabel 9550 3500 0    50   Input ~ 0
AUX_2
Text GLabel 9550 3600 0    50   Input ~ 0
AUX_3
Text GLabel 1500 2450 0    50   Input ~ 0
AUX_1
Text GLabel 1500 2550 0    50   Input ~ 0
AUX_2
Wire Wire Line
	700  1150 1500 1150
Text GLabel 1500 1850 0    50   Input ~ 0
AUX_3
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 5D717741
P 9750 3500
F 0 "J4" H 9830 3492 50  0000 L CNN
F 1 "Conn_01x04" H 9830 3401 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B04B-XH-A_1x04_P2.50mm_Vertical" H 9750 3500 50  0001 C CNN
F 3 "~" H 9750 3500 50  0001 C CNN
	1    9750 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R5
U 1 1 5D71C6B4
P 6800 2400
F 0 "R5" H 6868 2446 50  0000 L CNN
F 1 "31K" H 6868 2355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6840 2390 50  0001 C CNN
F 3 "~" H 6800 2400 50  0001 C CNN
	1    6800 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R6
U 1 1 5D71C7CD
P 6800 2850
F 0 "R6" H 6868 2896 50  0000 L CNN
F 1 "4.7K" H 6868 2805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6840 2840 50  0001 C CNN
F 3 "~" H 6800 2850 50  0001 C CNN
	1    6800 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5D71D559
P 7250 2850
F 0 "C1" H 7365 2896 50  0000 L CNN
F 1 "1uF" H 7365 2805 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 7288 2700 50  0001 C CNN
F 3 "~" H 7250 2850 50  0001 C CNN
	1    7250 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3000 7250 3150
Wire Wire Line
	7250 3150 7000 3150
Wire Wire Line
	6800 3150 6800 3000
Wire Wire Line
	6800 2700 6800 2600
Wire Wire Line
	7250 2700 7250 2600
Wire Wire Line
	7250 2600 6800 2600
Connection ~ 6800 2600
Wire Wire Line
	6800 2600 6800 2550
Text GLabel 6600 2250 0    50   Input ~ 0
12VIN
Wire Wire Line
	6600 2250 6800 2250
$Comp
L power:GND #PWR0114
U 1 1 5D721D4A
P 7000 3150
F 0 "#PWR0114" H 7000 2900 50  0001 C CNN
F 1 "GND" H 7005 2977 50  0000 C CNN
F 2 "" H 7000 3150 50  0001 C CNN
F 3 "" H 7000 3150 50  0001 C CNN
	1    7000 3150
	1    0    0    -1  
$EndComp
Connection ~ 7000 3150
Wire Wire Line
	7000 3150 6800 3150
Text GLabel 7700 2600 2    50   Input ~ 0
VMON
Wire Wire Line
	7700 2600 7650 2600
Connection ~ 7250 2600
Text GLabel 1500 2350 0    50   Input ~ 0
VMON
$Comp
L Device:D_Zener D2
U 1 1 5D723441
P 7650 2850
F 0 "D2" V 7604 2929 50  0000 L CNN
F 1 "D_Zener" V 7695 2929 50  0000 L CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 7650 2850 50  0001 C CNN
F 3 "~" H 7650 2850 50  0001 C CNN
	1    7650 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 2700 7650 2600
Connection ~ 7650 2600
Wire Wire Line
	7650 2600 7250 2600
Wire Wire Line
	7650 3000 7650 3150
Wire Wire Line
	7650 3150 7250 3150
Connection ~ 7250 3150
$EndSCHEMATC
