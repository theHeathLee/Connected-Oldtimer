/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "c:/workspace/Connected-Oldtimer/ConnectedOldtimerCode/src/ConnectedOldtimerCode.ino"
void setup();
void loop();
void canReceive();
void canSend();
void statusLED();
void getGpsInfo();
void updateOdometer();
void updateDisplay();
void readFromFRAM ();
void storeToFRAM ();
void serialLogger ();
#line 1 "c:/workspace/Connected-Oldtimer/ConnectedOldtimerCode/src/ConnectedOldtimerCode.ino"
SYSTEM_THREAD(ENABLED);
#include "Serial4/Serial4.h"
#include "Serial5/Serial5.h"
#include "../lib/TinyGPS++/src/TinyGPS++.h"
#include "../lib/MB85RC256V-FRAM-RK/src/MB85RC256V-FRAM-RK.h"
#include <math.h>

uint8_t nextionSpeed = 69;
uint8_t fuelLevel = 0;
uint16_t motorTemperature = 0;
uint16_t motorRPM = 0;
uint32_t odometerValue = 0;
int demoConnectivityValue = 64;
static const uint32_t GPSBaud = 9600;
unsigned long Heartbeat_200mS_Start = millis();
unsigned long Heartbeat_1000mS_Start = millis();
unsigned long Heartbeat_2000mS_Start = millis();
double speed =0;
double locationX1, locationX2, locationY1, locationY2, locationZ1, locationZ2, latestDistanceTraveled, deltaX, deltaY, deltaZ, combinedXs, combinedYs;
double xDisBuffer, yDisBuffer = .00001;
//double sampleLocationsX[9], sampleLocationsY[9], sampleLocationsZ[9]; delete me maybe
int led = D7; 


TinyGPSPlus gps;
CANChannel can(CAN_C4_C5);

//FRAM Stuff
MB85RC256V fram(Wire, 0);



void setup() {
  Particle.variable("dummyValue", demoConnectivityValue);
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
getGpsInfo();



}

void canReceive(){
  
  CANMessage message;

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
      speed = gps.speed.kmph(); // assigns speed to a double in Kmph
      speed = speed + 0.5 - (speed<0);// rounds speed up/down correctly
      nextionSpeed = (uint8_t)speed; // converts double from gps to unsigned byte for the nextion
    }
    else {
      Serial.println("speed invalid");
    }

} 

void updateOdometer() {

    // calculate dynamic distance traveled
    if (gps.location.isUpdated()) { //use this instead of isValid to avoid calculation redundancy

    //calculate rEarth - radius of the earth at sea level and H - the offset of earths radius above sea level
    double rEarth, H;
    rEarth = sqrt(pow(6356.7523*sin(gps.location.lat()),2) + pow(6378.137*cos(gps.location.lat()),2) );
    H = rEarth + gps.altitude.kilometers();


    //collect 10 location samples, saves them to an array and averages them when full
    combinedXs = 0;
    for (int i = 0; i<=9; i++ ) {
      combinedXs = combinedXs + (H * gps.location.lng() * cos(gps.location.lat()) ) ; // ads 10 samples of GPS Latitude
    }
    locationX1 = locationX2; // previous X2 is shifted to x1
    locationX2 = combinedXs/10; // as soon as sample reached 10, the average is taken and added passed to locationX1
    if ( abs(locationX2 - locationX1) >= xDisBuffer || abs(locationX2 - locationX1) < 1) { // if the distance is big enout to pass filter val, then delta is updated, or smaller than an impossible number
      deltaX = abs(locationX2 - locationX1);
    }
      
    combinedYs = 0;  
    for (int i = 0; i<=9; i++ ) {
      combinedYs = combinedYs + ( H * gps.location.lat() ); // ads 10 samples of GPA Latitude
    }  
    locationY1 = locationY2; // previous X2 is shifted to x1
    locationY2 = combinedYs/10; // as soon as sample reached 10, the average is taken and added passed to locationX1
    if ( abs(locationY2 - locationY1) >= yDisBuffer || abs(locationY2 - locationY1) < 1) { // if the distance is big enout to pass filter val, then delta is updated
      deltaY = abs(locationY2 - locationY1);
    }


    Serial.print ("Speed = ");
    Serial.print (nextionSpeed);
    Serial.print ("x1 = ");
    Serial.print (locationX1);
    Serial.print (" x2 = ");
    Serial.print (locationX2);
    Serial.print ("   Real-X ");
    Serial.print (gps.location.lat(), 6);
    


    Serial.print ("      y1 = ");
    Serial.print (locationY1);
    Serial.print (" y2 = ");
    Serial.print (locationY2);
    Serial.print ("   Real-Y ");
    Serial.print (gps.location.lng(), 6);
    Serial.print ("      Latest Distance  = ");
    Serial.print (latestDistanceTraveled);
    Serial.print ("      Odometer = ");
    Serial.print (odometerValue);
    



    Serial.println();



    //calculates actual distance (non spherical) to be added to odometer valure
    latestDistanceTraveled = sqrt(deltaX*deltaX)+(deltaY*deltaY); //pythagorians theorum to calculate actual distance
    odometerValue = odometerValue + (uint32_t)latestDistanceTraveled;// adds new distance to odometer value after converting from doublt 
    //odometerValue = 0;// comment in to reset odometer
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
  Serial4.print(odometerValue);
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);


  
  
}

//run at startup
void readFromFRAM () {
  fram.get(0, odometerValue);// 4 bytes
  fram.get(4, fuelLevel);// 1 byte
  fram.get(5, locationX2);// 8 bytes
  fram.get(13, locationY2);// 8 bytes
}


// stores data to FRAM chip every 5 seconds
void storeToFRAM (){

    //fram.writeData(0, (uint8_t *)&odometerValue, sizeof(odometerValue));
    fram.put(0, odometerValue);// 4 bytes
    fram.put(4, fuelLevel);// 1 byte
    fram.put(5, locationX2);// 8 bytes
    fram.put(13, locationY2);// 8 bytes

}

void serialLogger (){
  Serial.print (" odometer:  ");
  Serial.println(odometerValue);
  Serial.print (" fuel:  ");
  Serial.print(fuelLevel);
  Serial.print(" Speed= ");
  Serial.print(speed);
  Serial.print(" NextionSpeed= ");
  Serial.print(nextionSpeed);

}