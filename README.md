![alt tag](https://github.com/theHeathLee/Connected-Oldtimer/blob/master/Photos/banner.png?raw=true "G.A.R.Y. attached to test stand")

# Connected-Oldtimer

The aim of this project to modernize my old Volkswagen T2 by adding sensors everywhere and make it part of the internet of things. This project is not vehicle specific and can be implimented in any pre OBD vehicle.

The goal here is first to make remote monitoring possible. Motion sensing for anti theft will be implemented as the vehicle does a lot of sitting. (my bicycle has x4 the ammount of kms per year on it as the bus). Additionaly the able to remotely view levels (battery charge, fuel level etc..)

Alongside remote monitoring I have implmented an HMI using a 3.5" Display that fits in the dash area originally inteded for the RPM guage. This display shows the instantanious data such as speed, RPM, and Temperature.

A low speed CAN network is set up throughout the vehicle to easily add extra sensors.


Disclaimer: Still in the __beginning phase__. All hardware has been selected and unit tested.

### Software used:
- Visual Studio Code w/ [Particle Workbench Extentsion](https://marketplace.visualstudio.com/items?itemName=particle.particle-vscode-pack)🤘
- Particle [Cloud](https://www.particle.io/device-cloud/) 

### Things implemented:

- 3G Connectivity and vehicle to [cloud](https://www.particle.io/device-cloud/) data transfer   ![Progress](http://progressed.io/bar/100)
- Gps velocity and location tracking and display  ![Progress](http://progressed.io/bar/100)
- CAN Bus ![Progress](http://progressed.io/bar/100)
- Motor Temperature ![Progress](http://progressed.io/bar/80)
- Movement Sensor ![Progress](http://progressed.io/bar/25)
- 3D Printed Display mount ([Thingiverse](https://www.thingiverse.com/thing:2223484))![Progress](http://progressed.io/bar/80)

### To be implemented:

- Fine Dust Report (for [Open Data Project](https://luftdaten.info/))
- Motor RPM
- Fuel Level
- Fuel Flow
- daylight sensor

### Parts List:

- [Particle Electron](https://www.particle.io/cellular/)
- [Nextion 3.5" Display](https://www.itead.cc/nextion-nx4832t035.html)
- [Adafruit Ultimage GPS](https://www.adafruit.com/product/746)
- [Piezoelectric Sensor](https://www.digikey.de/product-detail/de/murata-electronics/7BB-20-6L0/490-7712-ND/4358152?utm_adgroup=Buzzer+Elements%2C+Piezo+Benders&mkwid=sdpYcvxN4&pcrid=340842080350&pkw=&pmt=&pdv=c&productid=4358152&slid=&gclid=CjwKCAjwq-TmBRBdEiwAaO1en7SKzERGe0ExhqXDZEztK8s2fRCffiLP5_EfisI5quuC8e3fuQmO5BoC3RUQAvD_BwE)
- [CAN Bus Tranceiver Module (TJA1051)](https://www.nxp.com/products/analog/interfaces/in-vehicle-network/can-transceiver-and-controllers/high-speed-can-transceiver:TJA1051)
- [K-Type Thermocouple amplifier](https://www.ebay.de/itm/DC-5V-MAX6675-Module-K-Type-Thermocouple-Temperature-Sensor-M6-for-Arduino/172165516851?hash=item2815dd4e33:g:~eMAAOSw0QFXDRCH)
- [CAN Bus Cable](https://www.conrad.de/de/p/busleitung-unitronic-bus-2-x-2-x-0-22-mm-violett-lapp-2170261-meterware-604030.html
)
- [Fuel Flow Meter](https://www.conrad.com/p/bt-bio-tech-fch-m-pom-lc-ad-6-mm-low-flow-flowmeter-non-corrosive-liquids-water-diesel-oil-150392?searchTerm=150392&searchType=suggest&searchSuggest=product)



