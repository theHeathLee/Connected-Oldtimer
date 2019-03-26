#include "application.h"
#line 1 "/Users/heath/Documents/workspace/Connected-Oldtimer/ConnectedOldtimerCode/src/ConnectedOldtimerCode.ino"

void setup();
void loop();
#line 2 "/Users/heath/Documents/workspace/Connected-Oldtimer/ConnectedOldtimerCode/src/ConnectedOldtimerCode.ino"
int led1 = D0; 
int led2 = D7; 
SYSTEM_THREAD(ENABLED);
#include "Serial4/Serial4.h"
#include "../lib/TinyGPS++/src/TinyGPS++.h"


void setup() {

  Serial.begin(9600);
  Serial4.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}


void loop() {
  // To blink the LED, first we'll turn it on...
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  Serial4.print("n0.val=67");
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);

  // We'll leave it on for 1 second...
  delay(500);

  // Then we'll turn it off...
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  Serial4.printf("n0.val=66");
  Serial4.write(0xff);
  Serial4.write(0xff);
  Serial4.write(0xff);
  // Wait 1 second...
  delay(500);
  //Serial.printlnf("printooooboi");

  // And repeat!
}
