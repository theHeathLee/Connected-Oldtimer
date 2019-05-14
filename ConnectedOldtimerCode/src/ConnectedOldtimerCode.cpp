#include "application.h"
#line 1 "c:/workspace/Connected-Oldtimer/ConnectedOldtimerCode/src/ConnectedOldtimerCode.ino"


void setup();
void loop();
void canReceive();
void canSend();
void statusLED();
#line 3 "c:/workspace/Connected-Oldtimer/ConnectedOldtimerCode/src/ConnectedOldtimerCode.ino"
int led = D7; 
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

unsigned long start = millis();

void setup() {
  Particle.variable("dummyValue", demoConnectivityValue);
  can.begin(250000); // pick the baud rate for your network
  //accept one message. If no filter added by user then accept all messages
  //can.addFilter(0x100, 0x7FF);

  Serial.begin(9600); //usb debugging
  Serial4.begin(9600); // uart for nextion c2 & c3
  Serial1.blockOnOverrun(true);
  Serial5.begin(GPSBaud); // uart for GPS
  Serial1.begin(GPSBaud); // 
  pinMode(led, OUTPUT);
}


void loop() {

canReceive();
canSend();
statusLED();

  if (gps.location.isValid()) {
    speed = gps.speed.kmph();
    Serial.println(speed);
    speed = speed + 0.5 - (speed<0);
    nextionSpeed = (uint8_t)speed;
  }
  else {
    nextionSpeed = 10; // we know that gps is not valid/
    Serial.println("speed invalid");
  }
  

  Serial4.printf("n0.val=");
  Serial4.print(nextionSpeed);
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial.println("nextion send");
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



void statusLED(){
  unsigned long ledDelay1 = 500;
  unsigned long ledDelay2 = 1000;
  do 
  {
    do
    {
     digitalWrite(led, HIGH);
    } while (millis() - start < ledDelay1);
    digitalWrite(led, LOW);
  } while (millis() - start < ledDelay2);
}  