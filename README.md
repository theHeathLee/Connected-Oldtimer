# Connected-Oldtimer

This is a project to modernize my old Volkswagen T2 by adding sensors everywhere and make it part of the internet of things. This project is not vehicle specific and can be implimented in any pre OBD vehicle.

The goal here is first to make remote monitoring possible. Motion sensing for anti theft will be implemented as the vehicle does a lot of sitting. (my bicycle has x4 the ammount of kms per year on it as the bus). Additionaly the able to remotely view levels (battery charge, fuel level etc..)

A low speed CAN network is set up throughout the vehicle to easily add extra sensors.

Disclaimer: Still in beginning phase

### Things implemented:

- 3G Connectivity and Vehicle to [cloud](https://www.particle.io/device-cloud/) data transfer
- Gps velocity and location tracking and desplay
- CAN Bus
- Motor Temperature
- Movement Sensor

### To be implemented:

- Fine Dust Report (for [Open Data Project](https://luftdaten.info/)
- Motor RPM
- Fuel Level

### Parts List:

- [Particle Electron](https://www.particle.io/cellular/)
- [Adafruit Ultimage GPS](https://www.adafruit.com/product/746)
- [Piezoelectric Sensor](https://www.digikey.de/product-detail/de/murata-electronics/7BB-20-6L0/490-7712-ND/4358152?utm_adgroup=Buzzer+Elements%2C+Piezo+Benders&mkwid=sdpYcvxN4&pcrid=340842080350&pkw=&pmt=&pdv=c&productid=4358152&slid=&gclid=CjwKCAjwq-TmBRBdEiwAaO1en7SKzERGe0ExhqXDZEztK8s2fRCffiLP5_EfisI5quuC8e3fuQmO5BoC3RUQAvD_BwE)
- [CAN Bus Tranceiver Module (TJA1051)](https://www.nxp.com/products/analog/interfaces/in-vehicle-network/can-transceiver-and-controllers/high-speed-can-transceiver:TJA1051)
- [K-Type Thermocouple amplifier](https://www.ebay.de/itm/DC-5V-MAX6675-Module-K-Type-Thermocouple-Temperature-Sensor-M6-for-Arduino/172165516851?hash=item2815dd4e33:g:~eMAAOSw0QFXDRCH)
- [Fuel Flow Meter](https://www.conrad.com/p/bt-bio-tech-fch-m-pom-lc-ad-6-mm-low-flow-flowmeter-non-corrosive-liquids-water-diesel-oil-150392?searchTerm=150392&searchType=suggest&searchSuggest=product)



