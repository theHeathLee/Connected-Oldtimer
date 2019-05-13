#include "application.h"
#line 1 "c:/workspace/Connected-Oldtimer/ConnectedOldtimerCode/src/ConnectedOldtimerCode.ino"

void setup();
void loop();
void displayInfo();
void canReceive();
void canSend();
static void smartDelay(unsigned long ms);
#line 2 "c:/workspace/Connected-Oldtimer/ConnectedOldtimerCode/src/ConnectedOldtimerCode.ino"
int led1 = D0; 
int led2 = D7; 
SYSTEM_THREAD(ENABLED);
//SYSTEM_MODE(SEMI_AUTOMATIC);
#include "Serial4/Serial4.h"
#include "Serial5/Serial5.h"
#include "../lib/TinyGPS++/src/TinyGPS++.h"
//#include "Serial1/Serial1.h"


TinyGPSPlus gps;
static const uint32_t GPSBaud = 9600;
double speed =0;
uint8_t nextionSpeed = 69;
CANChannel can(CAN_D1_D2);
uint16_t motorTemperature = 0;
uint16_t motorRPM = 0;
uint8_t fuelLevel = 0;
int demoConnectivityValue = 69;

void setup() {

  Particle.variable("dummyValue", demoConnectivityValue);
  can.begin(250000); // pick the baud rate for your network
    // accept one message. If no filter added by user then accept all messages
  //can.addFilter(0x100, 0x7FF);

  Serial.begin(9600); //usb debugging
  Serial4.begin(9600); // uart for nextion c2 & c3
  Serial1.blockOnOverrun(true);
  Serial5.begin(GPSBaud); // uart for GPS
  Serial1.begin(GPSBaud); // 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  //Serial.print("started");

}


void loop() {

canReceive();
canSend();

// while (Serial5.available() > 0)
//     if (gps.encode(Serial5.read()))
//       displayInfo();
smartDelay(500);

  // To blink the LED, first we'll turn it on...
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);

  // We'll leave it on for 1 second...
  //collect speed

  if (gps.location.isValid()) {
    speed = gps.speed.kmph();
    //speed = 102.4;
    Serial.println(speed);
    speed = speed + 0.5 - (speed<0);
    nextionSpeed = (uint8_t)speed;
  }
  else {
    nextionSpeed = 10; // we know that gps is not valid/
    Serial.println("speed invalid");
  }
  
  //Serial.println("counting");
  //speed = gps.speed.kmph();
  //Serial.print(speed);
  // Then we'll turn it off...
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  Serial4.printf("n0.val=");
  Serial4.print(nextionSpeed);
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial.println("nextion send");
  // Wait 1 second...
  //delay(500);
  //Serial.printlnf("printooooboi");

  // And repeat!
}




//gps info for debugging

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    // if (gps.time.hour() < 10) Serial.print(F("0"));
    // Serial.print(gps.time.hour());
    // Serial.print(F(":"));
    // if (gps.time.minute() < 10) Serial.print(F("0"));
    // Serial.print(gps.time.minute());
    // Serial.print(F(":"));
    // if (gps.time.second() < 10) Serial.print(F("0"));
    // Serial.print(gps.time.second());
    // Serial.print(F("."));
    // if (gps.time.centisecond() < 10) Serial.print(F("0"));
    // Serial.print(gps.time.centisecond());

    //Serial.print("Speed= ");

    
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}


void canReceive(){
  
  CANMessage message;

  while(can.receive(message)) {
    if (message.id == 0x100) {
      digitalWrite(motorTemperature, !message.data[0]);
    }
    if (message.id == 0x200) {
      digitalWrite(motorRPM, !message.data[0]);
    }
    if (message.id == 0x300) {
      digitalWrite(fuelLevel, !message.data[0]);
    }
  }
}  

void canSend(){
  CANMessage messageOut;

  messageOut.id = 0x200;
  messageOut.len = 1;
  messageOut.data[0] = 0xff;

  can.transmit(messageOut);

  delay(100);
}  


static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (Serial5.available())
      gps.encode(Serial5.read());
      //displayInfo();
  } while (millis() - start < ms);
}
