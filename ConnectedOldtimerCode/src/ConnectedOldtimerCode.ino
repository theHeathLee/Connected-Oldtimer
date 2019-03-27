
int led1 = D0; 
int led2 = D7; 
SYSTEM_THREAD(ENABLED);
#include "Serial4/Serial4.h"
#include "Serial5/Serial5.h"
#include "../lib/TinyGPS++/src/TinyGPS++.h"


TinyGPSPlus gps;
static const uint32_t GPSBaud = 9600;
double speed =0;

void setup() {

  Serial.begin(9600); //usb debugging
  Serial4.begin(9600); // uart for nextion
  Serial5.begin(GPSBaud); // uart for GPS
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.print("started");

}


void loop() {


while (Serial5.available() > 0)
    if (gps.encode(Serial5.read()))
      displayInfo();


  // To blink the LED, first we'll turn it on...


  // We'll leave it on for 1 second...
  delay(500);
  speed = gps.speed.kmph();
  Serial.print(speed);
  // Then we'll turn it off...
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  Serial4.printf("n0.val=66");
  Serial4.print(speed);
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);
  // Wait 1 second...
  delay(500);
  //Serial.printlnf("printooooboi");

  // And repeat!
}




//gps info 

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
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());

    //Serial.print("Speed= ");

    
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}



