SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(AUTOMATIC);
#include "Serial4/Serial4.h"
#include "Serial5/Serial5.h"
#include "../lib/TinyGPS++/src/TinyGPS++.h"
#include "../lib/MB85RC256V-FRAM-RK/src/MB85RC256V-FRAM-RK.h"
#include "../lib/ITEADLIB_Nextion\src/ITEADLIB_Nextion.h"
//#include "../lib/ITEADLIB_Nextion\src\ITEADLIB_Nextion\Nextion.h"
#include <math.h>

#define earthRadiusKm 6371.0 // for use in haversine calculation 

uint8_t nextionSpeed = 255, nextionSpeedOld = 254, gpsNotValid = 1, gpsNotValidOld = 0;
uint8_t fuelLevel, FuelFlow, fuelUsed, litersper100km, vacuum, vacuumefficiency = 0;
uint8_t fuelLevelold, FuelFlowold, fuelUsedold, litersper100kmold, vacuumold, vacuumefficiencyold, motorTemperatureold = 0;
uint8_t motorTemperature = 10;
uint8_t oilPressure, oilPressureOld = 0;
uint8_t setSpeedKmh = 1;
uint16_t motorRPM, motorRPMold = 0;
int demoConnectivityValue = 64;
static const uint32_t GPSBaud = 9600;
unsigned long Heartbeat_200mS_Start = millis();
unsigned long Heartbeat_1000mS_Start = millis();
unsigned long Heartbeat_2000mS_Start = millis();
unsigned long Heartbeat_10mS_Start = millis();
double locationX1, locationX2, locationY1, locationY2, latestDistanceTraveled, odometerValue, odometerValueOld, pbBatteryVoltage;
double tripValue = 55, tripValueOld;
int led = D7;
int activateLock = B2;
int activateUnlock = B3;
int pbBatVoltPin = A0;
int pwerDisplayEnable = B4;
int ignitionSignal = D2;
int GPSEnable = B5;
int pwr5VoltEnable = A1;
int shockSense = WKP;
int countdownToDeepSleep = 0;

//Nextion Object Defs
USARTSerial& nexSerial = Serial4;
NexButton b0 = NexButton(1, 2, "b0");
NexTouch *nex_listen_list[] = 
{
    &b0,
    NULL
};

//todo change to defien 
double batCalibrationMultiplier = 12.8151; //calculated excel todo c
double batCalibrationOffset = -9.9; // calculated excel

TinyGPSPlus gps;
CANChannel can(CAN_C4_C5);

//FRAM Stuff
MB85RC256V fram(Wire, 0);



void setup() {

  //particle variables
  Particle.variable("dummyValue", demoConnectivityValue);
  Particle.variable("PosLat", locationY2);
  Particle.variable("PosLon", locationX2);
  Particle.variable("PBBatVolt", pbBatteryVoltage);

  //particle functions
  Particle.function("LockDrs", lockDoors);
  Particle.function("UnlockDrs", UnlockDoors);
  Particle.function("deepSleep", cloudActivateDeepSleep);
  Particle.function("activate5v", activate5Volts);
  
  
  can.begin(250000); // initialize can at 250 kbs 
  Serial.begin(9600); //usb debugging
  Serial1.blockOnOverrun(true);
  Serial5.begin(GPSBaud); // uart for GPS
  Serial1.begin(GPSBaud); // 
  pinMode(led, OUTPUT);
  pinMode(activateLock, OUTPUT);
  pinMode(activateUnlock, OUTPUT);
  pinMode(pwerDisplayEnable, OUTPUT);
  pinMode(GPSEnable, OUTPUT);
  pinMode(pwr5VoltEnable, OUTPUT);
  pinMode(ignitionSignal, INPUT);
  pinMode(shockSense, INPUT);
  Serial.println("contoroller running");

  digitalWrite(GPSEnable, HIGH);
  //System.sleep(SLEEP_MODE_DEEP);
  

  //FRAM Setup stuff
  fram.begin();
  readFromFRAM(); // pulls FRAM values for last odo, fuel, and gps into memory

  //Nextion
  nexInit(250000);
  
  b0.attachPop(b0PopCallback, &b0);

}


void loop() {

if (millis() >= Heartbeat_200mS_Start + 200) {

    //all funtions to be run every 200mS
    //canSend();
    getGpsInfo();
    updateDisplay();
    //canReceive(); 
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
   pbBatteryVoltage = double((analogRead(pbBatVoltPin)*batCalibrationMultiplier)/1000)+batCalibrationOffset;
   //Serial.println(pbBatteryVoltage);

  Heartbeat_2000mS_Start = millis();
}

if (millis() >= Heartbeat_10mS_Start + 10) {
  ignitionSignalCheck();
  Heartbeat_10mS_Start = millis();
}

//funtions being executed as fast as possible
//tripResetCheck(); bug: this is causing a big delay
//shockSensorCheck();
canReceive(); 
nexLoop(nex_listen_list);




}

void canReceive(){
  
  CANMessage message;
  can.receive(message);
  switch (message.id)
  {
  case 0x100:
    motorTemperature = message.data[0];
    oilPressure = message.data[1];
    break;
  case 0x200:
    motorRPM =  message.data[0]| message.data[1]<<8;
    break;
  case 0x300:
    fuelLevel = message.data[0];
    break;
  case 0xB600:
    //maybe add some sensors 
    break;
  case 0xB601:
    //motorRPM = message.data[0] << 8 | message.data[1];
   // fuelLevel = message.data[7];
    break;
  case 0x400:
    FuelFlow = message.data[0];
    fuelUsed = message.data[1];
    litersper100km = message.data[2];
    fuelLevel = message.data[3];
    vacuum = message.data[4];
    vacuumefficiency = message.data[5];
    break;
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
      gpsNotValid = 0;
    }
    else {
      gpsNotValid = 1;
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
        tripValue = tripValue + latestDistanceTraveled;
      }
    }
}

void updateDisplay() {


  // sends data to display
  if (nextionSpeed != nextionSpeedOld)
  {
    nexSerial.printf("SpeedKmh.val=");
    nexSerial.print(nextionSpeed);
    // next 3 writes must be made for the Nextion to accept the update
    nextionTerminatMessage();
  }
  nextionSpeedOld = nextionSpeed;
  //speed simulator
  /*
  nextionSpeed++;
  if (nextionSpeed == 255)
  {
    nextionSpeed = 1;
  }
  */

  //set gps symbol

  if (gpsNotValid != gpsNotValidOld)
  {
    nexSerial.printf("NoGPSBool.val=");
    nexSerial.print(gpsNotValid);
    nextionTerminatMessage();
  }
  gpsNotValidOld = gpsNotValid;


  // updates odometer value
  if (odometerValue == odometerValueOld)
  {
    nexSerial.printf("n1.val=");
    nexSerial.print((uint32_t)((odometerValue + 0.5 - (odometerValue<0)) * 0.621371192 ));
    nextionTerminatMessage();
  }
  odometerValueOld = odometerValue;


  //updates temperature value
  if (motorTemperature != motorTemperatureold)
  {
    nexSerial.printf("n2.val=");
    nexSerial.print(motorTemperature);
    nextionTerminatMessage();
  }
  motorTemperatureold = motorTemperature;
  //Serial.print(motorTemperature);

  //updates RPM value
  if (motorRPM != motorRPMold)
  {
    nexSerial.printf("va0.val=");
    nexSerial.print(motorRPM);
    nextionTerminatMessage();
  }
  motorRPMold = motorRPM;
  //Serial.println(motorRPM);

  //updates trip value
  if (tripValue != tripValueOld)
  {
    nexSerial.printf("n3.val=");
    nexSerial.print((uint32_t)((tripValue + 0.5 - (tripValue<0)) * 0.621371192 ));
    nextionTerminatMessage(); 
  }
  tripValueOld = tripValue;

  //nexSerial.printf("n4.val=");
  //nexSerial.print(Time.hour());
  nextionTerminatMessage(); 
  nexSerial.printf("n5.val=");
  nexSerial.print(Time.minute());
  nextionTerminatMessage(); 

  nexSerial.printf("n7.val=");
  nexSerial.print(pbBatteryVoltage);
  nextionTerminatMessage(); 
  nexSerial.printf("n6.val=");
  nexSerial.print(pbBatteryVoltage);
  nextionTerminatMessage(); 

  //update oil pressure
  if (oilPressure != oilPressureOld)
  {
    //nexSerial.printf("OilPressure.val=");
    nexSerial.printf("n4.val=");
    nexSerial.print(oilPressure);
    nextionTerminatMessage(); 
  }
  oilPressureOld = oilPressure;
}

//run at startup
void readFromFRAM () {
  fram.get(0, odometerValue);// 8 bytes
  fram.get(8, fuelLevel);// 1 byte
  fram.get(9, locationX2);// 8 bytes
  fram.get(17, locationY2);// 8 bytes
  fram.get(25, tripValue);// 8 bytes
}


// stores data to FRAM chip every 5 seconds
void storeToFRAM (){

  //fram.writeData(0, (uint8_t *)&odometerValue, sizeof(odometerValue));
  fram.put(0, odometerValue);// 8 bytes
  fram.put(8, fuelLevel);// 1 byte
  fram.put(9, locationX2);// 8 bytes
  fram.put(17, locationY2);// 8 bytes
  fram.put(25, tripValue);// 8 bytes

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


void nextionTerminatMessage(){
  nexSerial.write(0xff);
  nexSerial.write(0xff);
  nexSerial.write(0xff);
}

int lockDoors(String args){
  digitalWrite(activateLock, LOW);
  digitalWrite(activateUnlock, HIGH);
  Serial.println("door lock command received");
  return 1;
}

int UnlockDoors(String args){
  digitalWrite(activateUnlock, LOW);
  digitalWrite(activateLock, HIGH);
  Serial.println("door unlock command received");
  return 1;
}

void startDeepSleep(void){
  SystemSleepConfiguration config;
  config.mode(SystemSleepMode::HIBERNATE)
        // wake up on shake sensor
        .gpio(WKP, RISING)
        // duration every 12 hours
        .duration(43200s);
  SystemSleepResult result = System.sleep(config);
}

void ignitionSignalCheck(){
  Serial.print("ignition signal: ");
  Serial.print(digitalRead(ignitionSignal));
  //print the value of the wkp pi
  Serial.print("    WKP: ");
  Serial.println(digitalRead(WKP));
  if (digitalRead(ignitionSignal) == HIGH){
    digitalWrite(pwerDisplayEnable, HIGH);
    digitalWrite(pwr5VoltEnable, HIGH);
    countdownToDeepSleep = 0;
  }
  else
  {
    digitalWrite(pwerDisplayEnable, LOW);
    digitalWrite(pwr5VoltEnable, LOW);
    countdownToDeepSleep++; 
    Serial.println(countdownToDeepSleep);
    // go to deep sleep after 5 minutes of no ignition signal
    if (countdownToDeepSleep > 1000){
      countdownToDeepSleep = 0;
      startDeepSleep();
    }  
  }
}

int cloudActivateDeepSleep(String args){
  startDeepSleep();
  return 1;
}



int activate5Volts(String args){
  Serial.println(args);
  digitalWrite(pwr5VoltEnable, atoi(args));
  Serial.println(digitalRead(pwr5VoltEnable));
  return atoi(args);
}


void b0PopCallback(void *ptr)
{
  tripValue = 0;
}
