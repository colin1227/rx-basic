#define rxPin 10
#define txPin 11
#define light 7
#include <SoftwareSerial.h>

SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

char receivedChar;
boolean newData = false;

void setup() {
 pinMode(light, OUTPUT);
 Serial.begin(9600);
 mySerial.begin(9600);

 while(!Serial && !mySerial){}
 Serial.println("<Arduino is ready>");
}

void loop() {
 digitalWrite(light, LOW);
 recvOneChar();
 showNewData();
}

void recvOneChar() {
 if (mySerial.available() > 0) {
 receivedChar = mySerial.read();
 newData = true;
 }
}

void showNewData() {
 if (newData == true) {
 digitalWrite(light, HIGH);
 delay(500);
 Serial.print("This just in ... ");
 Serial.println(receivedChar, DEC);
 newData = false;
 }
}
