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
Text GLabel 2350 1700 0    50   Input ~ 0
VIN
Text GLabel 2350 1800 0    50   Input ~ 0
GND
Text GLabel 2350 1900 0    50   Input ~ 0
TX
Text GLabel 2350 2000 0    50   Input ~ 0
RX
Text GLabel 2350 2100 0    50   Input ~ 0
WKP
Text GLabel 2350 2200 0    50   Input ~ 0
DAC
Text GLabel 2350 2300 0    50   Input ~ 0
A5
Text GLabel 2350 2400 0    50   Input ~ 0
A4
Text GLabel 2350 2500 0    50   Input ~ 0
A3
Text GLabel 2350 2600 0    50   Input ~ 0
A2
Text GLabel 2350 2700 0    50   Input ~ 0
A1
Text GLabel 2350 2800 0    50   Input ~ 0
A0
Text GLabel 2350 2900 0    50   Input ~ 0
B5
Text GLabel 2350 3000 0    50   Input ~ 0
B4
Text GLabel 2350 3100 0    50   Input ~ 0
B3
Text GLabel 2350 3200 0    50   Input ~ 0
B2
Text GLabel 2350 3300 0    50   Input ~ 0
B1
Text GLabel 2350 3400 0    50   Input ~ 0
B0
Text GLabel 5000 3200 0    50   Input ~ 0
VIN
Text GLabel 5000 3300 0    50   Input ~ 0
GND
Text GLabel 5000 3500 0    50   Input ~ 0
D1
Text GLabel 5000 3600 0    50   Input ~ 0
D0
Text GLabel 4950 5600 0    50   Input ~ 0
VIN
Text GLabel 4950 5500 0    50   Input ~ 0
GND
Text GLabel 4950 5400 0    50   Input ~ 0
C1
Text GLabel 4950 5300 0    50   Input ~ 0
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
Text GLabel 7800 3150 0    50   Input ~ 0
3V3
Text GLabel 7800 3250 0    50   Input ~ 0
GND
Text GLabel 7800 3350 0    50   Input ~ 0
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
$Comp
L HeathsComponents:ParticleElectron U?
U 1 1 5D6D05D3
P 3100 2300
F 0 "U?" H 3075 3165 50  0000 C CNN
F 1 "ParticleElectron" H 3075 3074 50  0000 C CNN
F 2 "" H 3100 2300 50  0001 C CNN
F 3 "" H 3100 2300 50  0001 C CNN
	1    3100 2300
	1    0    0    -1  
$EndComp
Text GLabel 3800 1700 2    50   Input ~ 0
3V3
Text GLabel 3800 1800 2    50   Input ~ 0
RESET
Text GLabel 3800 1900 2    50   Input ~ 0
VBAT
Text GLabel 3800 2000 2    50   Input ~ 0
GND
Text GLabel 3800 2100 2    50   Input ~ 0
D7
Text GLabel 3800 2200 2    50   Input ~ 0
D6
Text GLabel 3800 2300 2    50   Input ~ 0
D5
Text GLabel 3800 2400 2    50   Input ~ 0
D4
Text GLabel 3800 2500 2    50   Input ~ 0
D3
Text GLabel 3800 2600 2    50   Input ~ 0
D2
Text GLabel 3800 2700 2    50   Input ~ 0
D1
Text GLabel 3800 2800 2    50   Input ~ 0
D0
Text GLabel 3800 2900 2    50   Input ~ 0
C5
Text GLabel 3800 3000 2    50   Input ~ 0
C4
Text GLabel 3800 3100 2    50   Input ~ 0
C3
Text GLabel 3800 3200 2    50   Input ~ 0
C2
Text GLabel 3800 3300 2    50   Input ~ 0
C1
Text GLabel 3800 3400 2    50   Input ~ 0
C0
$Comp
L HeathsComponents:AdafruitFRAM U?
U 1 1 5D6D08AC
P 5450 3450
F 0 "U?" H 5928 3396 50  0000 L CNN
F 1 "AdafruitFRAM" H 5928 3305 50  0000 L CNN
F 2 "" H 5450 3450 50  0001 C CNN
F 3 "" H 5450 3450 50  0001 C CNN
	1    5450 3450
	1    0    0    -1  
$EndComp
$Comp
L HeathsComponents:AdafruitUltimateGPS U?
U 1 1 5D6D0C95
P 5600 5350
F 0 "U?" H 5977 5421 50  0000 L CNN
F 1 "AdafruitUltimateGPS" H 5977 5330 50  0000 L CNN
F 2 "" H 5600 5350 50  0001 C CNN
F 3 "" H 5600 5350 50  0001 C CNN
	1    5600 5350
	1    0    0    -1  
$EndComp
$Comp
L HeathsComponents:MotionSensor U?
U 1 1 5D6D1163
P 8200 3250
F 0 "U?" H 8277 3296 50  0000 L CNN
F 1 "MotionSensor" H 8277 3205 50  0000 L CNN
F 2 "" H 8200 3250 50  0001 C CNN
F 3 "" H 8200 3250 50  0001 C CNN
	1    8200 3250
	1    0    0    -1  
$EndComp
$Comp
L DCDC:TSR_2-2450 U?
U 1 1 5D6D21AF
P 2700 4950
F 0 "U?" H 2755 5417 50  0000 C CNN
F 1 "TSR_2-2450" H 2755 5326 50  0000 C CNN
F 2 "SIP750W46P254L1400H1010Q3" H 2700 4950 50  0001 L BNN
F 3 "SIP-3 Tracopower" H 2700 4950 50  0001 L BNN
F 4 "TSR 2-2450" H 2700 4950 50  0001 L BNN "Field4"
F 5 "Unavailable" H 2700 4950 50  0001 L BNN "Field5"
F 6 "Traco Power" H 2700 4950 50  0001 L BNN "Field6"
F 7 "None" H 2700 4950 50  0001 L BNN "Field7"
F 8 "DC-DC Point of Load _POL_ Converter PCB mount; Input 6.5-36Vdc; Output 5Vdc at 2A; SIP Through hole package" H 2700 4950 50  0001 L BNN "Field8"
	1    2700 4950
	1    0    0    -1  
$EndComp
Text GLabel 3000 4750 2    50   Input ~ 0
12VIN
Text GLabel 3000 4950 2    50   Input ~ 0
GND
Text GLabel 3000 5150 2    50   Input ~ 0
VIN
$EndSCHEMATC
