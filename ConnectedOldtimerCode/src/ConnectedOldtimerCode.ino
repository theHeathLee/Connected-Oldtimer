SYSTEM_THREAD(ENABLED);
#include "Serial4/Serial4.h"
#include "Serial5/Serial5.h"
#include "../lib/TinyGPS++/src/TinyGPS++.h"
#include "../lib/MB85RC256V-FRAM-RK/src/MB85RC256V-FRAM-RK.h"
#include <math.h>

#define earthRadiusKm 6371.0 // for use in haversine calculation 

uint8_t nextionSpeed = 69;
uint8_t fuelLevel = 0;
uint8_t motorTemperature = 10;
uint16_t motorRPM = 0;
int demoConnectivityValue = 64;
static const uint32_t GPSBaud = 9600;
unsigned long Heartbeat_200mS_Start = millis();
unsigned long Heartbeat_1000mS_Start = millis();
unsigned long Heartbeat_2000mS_Start = millis();
double locationX1, locationX2, locationY1, locationY2, latestDistanceTraveled, odometerValue;
int led = D7;



TinyGPSPlus gps;
CANChannel can(CAN_C4_C5);

//FRAM Stuff
MB85RC256V fram(Wire, 0);



void setup() {
  Particle.variable("dummyValue", demoConnectivityValue);
  Particle.variable("Location Latitude", locationY1);
  Particle.variable("location Longitude", locationX2);
  can.begin(250000); // initialize can at 250 kbs 
  Serial.begin(9600); //usb debugging
  Serial4.begin(9600); // uart for nextion c2 & c3
  Serial1.blockOnOverrun(true);
  Serial5.begin(GPSBaud); // uart for GPS
  Serial1.begin(GPSBaud); // 
  pinMode(led, OUTPUT);

  Serial.println("contoroller running");

  //FRAM Setup stuff
  fram.begin();
  readFromFRAM(); // pulls FRAM values for last odo, fuel, and gps into memory
}


void loop() {


if (millis() >= Heartbeat_200mS_Start + 200) {

    //all funtions to be run every 200mS
    canReceive();
    canSend();
    updateDisplay();

    Heartbeat_200mS_Start = millis(); //reset timer
  }

if (millis() >= Heartbeat_1000mS_Start + 1000) {

    //all funtions to be run every second
    statusLED();
    storeToFRAM(); //Todo - comment this back in when there is a change compare
    //serialLogger();
    
    Heartbeat_1000mS_Start = millis(); //reset timer
  }

if (millis() >= Heartbeat_2000mS_Start + 2000) {

   updateOdometer(); 

  Heartbeat_2000mS_Start = millis();
}

//funtions being executed as fast as possible
//getGpsInfo();
//canReceive(); // put this back in heartbeat if possible



}

void canReceive(){
  
  CANMessage message;
  can.receive(message);
  switch (message.id)
  {
  case 0x100:
    motorTemperature = message.data[0];
    break;
  case 0x200:
    motorRPM = message.data[0];
  case 0x300:
    fuelLevel = message.data[0];
  default:
    break;
  }

  
}  

void canSend(){

  CANMessage messageOut;
  messageOut.id = 0x555;
  messageOut.len = 3;
  messageOut.data[0] = 0xC0;
  messageOut.data[1] = 0xff;
  messageOut.data[2] = 0xEE;
  can.transmit(messageOut); //actually transmits the message 

}  



void statusLED(){
  
    digitalWrite(led, !digitalRead(led));
}  

void getGpsInfo() {
    while (Serial5.available())
      gps.encode(Serial5.read());

    
    //read speed directly 
    if (gps.location.isValid()) {
      nextionSpeed = (uint8_t) ( gps.speed.kmph() + 0.5 - (gps.speed.kmph()<0) ); // gets speed, rounds it and converts to an integer
    }
    else {
      Serial.println("GPS Location invalid");
    }

} 

void updateOdometer() {

    // calculate dynamic distance traveled
    if (gps.location.isValid()) { //use this instead of isValid to avoid calculation redundancy
      locationX1 = locationX2; 
      locationX2 = gps.location.lng(); 
      locationY1 = locationY2; 
      locationY2 = gps.location.lat(); 


      latestDistanceTraveled =  distanceEarth( locationY1, locationX1, locationY2 ,locationX2 );
      
      // filter out impossible  distances but but allow no signal events like tunnels
      if (latestDistanceTraveled < 20.0 && (gps.speed.kmph() > 1.0)) {
        odometerValue = odometerValue + latestDistanceTraveled;
      }
      Serial.print ("Speed = ");
      Serial.print (gps.speed.kmph());
      Serial.print ("  x1 = ");
      Serial.print (locationX1);
      Serial.print (" x2 = ");
      Serial.print (locationX2, 6);
      Serial.print ("   y1 = ");
      Serial.print (locationY1);
      Serial.print (" y2 = ");
      Serial.print (locationY2, 6);
      Serial.print ("   Latest Distance=");
      Serial.print (latestDistanceTraveled, 6);
      Serial.print ("   Odometer=");
      Serial.print (odometerValue, 6);
      Serial.print ("  GPS accuracy=");
      Serial.print (gps.hdop.value());
      Serial.println();
    }
}

void updateDisplay() {


  // sends data to display
  Serial4.printf("n0.val=");
  Serial4.print(nextionSpeed);
  // next 3 writes must be made for the Nextion to accept the update
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);

  // updates odometer value
  Serial4.printf("n1.val=");
  Serial4.print((uint32_t)((odometerValue + 0.5 - (odometerValue<0)) * 0.621371192 ));
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);

  //updates temperature value
  Serial4.printf("n2.val=");
  Serial4.print(motorTemperature);
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial.print(motorTemperature);

}

//run at startup
void readFromFRAM () {
  fram.get(0, odometerValue);// 4 bytes
  fram.get(8, fuelLevel);// 1 byte
  fram.get(9, locationX2);// 8 bytes
  fram.get(17, locationY2);// 8 bytes
}


// stores data to FRAM chip every 5 seconds
void storeToFRAM (){

    //fram.writeData(0, (uint8_t *)&odometerValue, sizeof(odometerValue));
    fram.put(0, odometerValue);// 4 bytes
    fram.put(8, fuelLevel);// 1 byte
    fram.put(9, locationX2);// 8 bytes
    fram.put(17, locationY2);// 8 bytes

}

void serialLogger (){
  Serial.print (" odometer:  ");
  Serial.println(odometerValue);
  Serial.print (" fuel:  ");
  Serial.print(fuelLevel);
  Serial.print(" NextionSpeed= ");
  Serial.print(nextionSpeed);
}

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

double deg2rad(double deg) {
  return (deg * 3.1415926536 / 180);
}
