![alt tag](https://github.com/theHeathLee/Connected-Oldtimer/blob/master/Photos/banner.png?raw=true "Connected oldtimer banner")

# Connected-Oldtimer

The aim of this project to modernize my old Volkswagen T2 by adding sensors everywhere and make it part of the internet of things. This project is not vehicle specific and can be implimented in any pre OBD vehicle.

The goal here is first to make remote monitoring possible. Motion sensing for anti theft will be implemented as the vehicle does a lot of sitting. (my bicycle has x4 the ammount of kms per year on it as the bus). Additionaly the ability to remotely view levels (battery charge, fuel level etc..)

Alongside remote monitoring I have implmented an HMI using a 3.5" Display that fits in the dash area originally inteded for the RPM guage. This display shows the instantanious data such as speed, RPM, and Temperature.

A low speed CAN network is set up throughout the vehicle to easily add extra sensors.


Disclaimer: Still in the __developement phase__. V1 hardware has been created and software is still in heavy developement.

### Software used:
- Visual Studio Code w/ [Particle Workbench Extentsion](https://marketplace.visualstudio.com/items?itemName=particle.particle-vscode-pack)🤘
- Particle [Cloud](https://www.particle.io/device-cloud/) 
- [BusMaster](http://rbei-etas.github.io/busmaster/)

### Things implemented:

- 3G Connectivity and vehicle to [cloud](https://www.particle.io/device-cloud/) data transfer   
- Gps velocity and location tracking and display  
- CAN Bus 
- Motor Temperature 
- Movement Sensor 
- 3D Printed Display mount ([Thingiverse](https://www.thingiverse.com/thing:4713912))

### To be implemented:

- Motor RPM
- Fuel Level
- Fuel Flow
- daylight sensor
- Fine Dust Report (for [Open Data Project](https://luftdaten.info/))

### Parts List:

- [Particle Electron](https://www.particle.io/cellular/)
- [Nextion 3.5" Display](https://www.itead.cc/nextion-nx4832t035.html)
- [Adafruit Ultimage GPS](https://www.adafruit.com/product/746)
- [Adafruit I2C FRAM](https://www.adafruit.com/product/1895)
- [Piezoelectric Sensor](https://www.digikey.de/product-detail/de/murata-electronics/7BB-20-6L0/490-7712-ND/4358152?utm_adgroup=Buzzer+Elements%2C+Piezo+Benders&mkwid=sdpYcvxN4&pcrid=340842080350&pkw=&pmt=&pdv=c&productid=4358152&slid=&gclid=CjwKCAjwq-TmBRBdEiwAaO1en7SKzERGe0ExhqXDZEztK8s2fRCffiLP5_EfisI5quuC8e3fuQmO5BoC3RUQAvD_BwE)
- [CAN Bus Tranceiver Module (TJA1051)](https://www.nxp.com/products/analog/interfaces/in-vehicle-network/can-transceiver-and-controllers/high-speed-can-transceiver:TJA1051)
- [K-Type Thermocouple amplifier](https://www.ebay.de/itm/DC-5V-MAX6675-Module-K-Type-Thermocouple-Temperature-Sensor-M6-for-Arduino/172165516851?hash=item2815dd4e33:g:~eMAAOSw0QFXDRCH)
- [CAN Bus Cable](https://www.conrad.de/de/p/busleitung-unitronic-bus-2-x-2-x-0-22-mm-violett-lapp-2170261-meterware-604030.html
)
- [Fuel Flow Meter](https://www.conrad.com/p/bt-bio-tech-fch-m-pom-lc-ad-6-mm-low-flow-flowmeter-non-corrosive-liquids-water-diesel-oil-150392?searchTerm=150392&searchType=suggest&searchSuggest=product)

# Hardware

[BOM Viewer](https://htmlpreview.github.io/?https://github.com/theHeathLee/Connected-Oldtimer/blob/master/Hardware/Connected-OldtimerHardware/bom/ibom.html)

### Schematic

<img src="https://github.com/theHeathLee/Connected-Oldtimer/blob/master/Photos/COSchematic.PNG" width="880">


### PCB

![](https://github.com/theHeathLee/Connected-Oldtimer/blob/master/Photos/PCBRenderV1.PNG?raw=true "pcb")


<img src="https://github.com/theHeathLee/Connected-Oldtimer/blob/master/Photos/PCBA.jpg" width="880">

<img src="https://github.com/theHeathLee/Connected-Oldtimer/blob/master/Photos/basicguage.jpg" width="880">







Art Credits:
[Freepik](https://www.flaticon.com/authors/freepik)

## CAN Matrix

| Value       | ID        |DLC   | Byte Pos.|
| ------------- |:-----:|----:|   --:|
| Temp (C)     | 0x100 | 8 |0 |
| RPM     | 0x200 | 8 |0, 1|
| Fuel Level    | 0x300 | 8 |0 |
| Fuel Flow    | 0x400 | 8 |0 |

## Nextion Component Values


| Component  | Value        |
| ------------- |:-----:|
Speed (Kmh) | n0
Odometer (Km) | n1
Trip Counter (Km) | n3
CHT (C) | n2
RPM | va0

# References

## GPS

### NMEA Simulation
[SatGen](https://www.labsat.co.uk/index.php/de/free-gps-nmea-simulator-software) Windows software form LabSat used for playing NMEA files over virtual coms

[NMEAGen](https://nmeagen.org/) browser application for generating custom NMEA files

To create a GPS simulation, first create an NMEA file in NMEAGen. after generating a .nmea file, change the file extension to .txt. The file can now be played in the Serial Output tab of SatGen.

Any USB to TTL coverter can be connected to ports C0 & C1 (Serial5) of the Electron.
