SYSTEM_THREAD(ENABLED);
#include "Serial4/Serial4.h"
#include "Serial5/Serial5.h"
#include "../lib/TinyGPS++/src/TinyGPS++.h"
#include "../lib/MB85RC256V-FRAM-RK/src/MB85RC256V-FRAM-RK.h"

uint8_t nextionSpeed = 69;
uint8_t fuelLevel = 0;
uint16_t motorTemperature = 0;
uint16_t motorRPM = 0;
uint32_t odometerValue = 0;
int demoConnectivityValue = 69;
static const uint32_t GPSBaud = 9600;
unsigned long currentTime = millis();
unsigned long start = 0;
unsigned long ledStart = 0;
unsigned long canSendStart = 0;
unsigned long GpsGetStart = 0;
unsigned long displayUpdateStart = 0;
unsigned long storeToFRAMStart = 0;
unsigned long updateDisplayStart = 0;
unsigned long canSendRate = 1000;
double speed =0;
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
  readFromFRAM();
  Timer timer.start;
  
}

Timer timer(1000, canSend);
void loop() {
timer.start();

// statusLED();
// canReceive();
//canSend();
Timer timer(1000, canSend, false);
//timer.start();
// getGpsInfo(),
// updateDisplay();
// storeToFRAM();

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

  // if (currentTime - canSendStart >= canSendRate) {
  //   can.transmit(messageOut);
  //   canSendStart = currentTime;
  // }

  // do
  // {
    // can.transmit(messageOut);
    // canSendStart = millis();
  // } while (millis() - canSendStart == canSendRate);
  Serial.print("fuck you");

}  



void statusLED(){
  
  if (currentTime >= ledStart + 1000 ) {
    digitalWrite(led, !digitalRead(led));
    ledStart = currentTime;
  }
}  

void getGpsInfo() {
  unsigned long gpsDelay = 200;
  do
  {
    /* code */
    if (gps.location.isValid()) {
      speed = gps.speed.kmph();
      Serial.println(speed);
      speed = speed + 0.5 - (speed<0);
    }
    else {
      //Serial.println("speed invalid");
    }
    } while (millis() - GpsGetStart < gpsDelay);
} 

void updateDisplay() {
  unsigned long displayUpdateDelay = 100;
  do
  {
    nextionSpeed = (uint8_t)speed; // converts double from gps to unsigned byte for the nextion
  // sends data to display
  Serial4.printf("n0.val=");
  Serial4.print(nextionSpeed);

  // next 3 writes must be made for the Nextion to accept the update
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);
  //Serial.println("nextion send");
  } while (millis() - updateDisplayStart < displayUpdateDelay);
  
  
}

//run at startup
void readFromFRAM () {
  fram.get(0, odometerValue);
  fram.get(1, fuelLevel);
}


// stores data to FRAM chip every 5 seconds
void storeToFRAM (){

  unsigned long framRate = 5000;
  
  do
  {
    //fram.writeData(0, (uint8_t *)&odometerValue, sizeof(odometerValue));
    fram.put(0, odometerValue);
    fram.put(1, fuelLevel);
    Serial.print (" odometer:  ");
    Serial.println(odometerValue);
    Serial.print (" fuel:  ");
    Serial.print(fuelLevel);
    storeToFRAMStart = currentTime;
  } while (currentTime - storeToFRAMStart >= framRate);
}
