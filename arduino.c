/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo topservo;
Servo botservo;
Servo boxservo;

// twelve servo objects can be created on most boards

const int ledIn = 2;
int topL = 130; // tested to 135
int topR = 95; // tested to 95
int topmid = 115; // 115
int botUp = 130; // tested to 120
int botDn = 100; // tested to 80
int botmid = 100; // 100

int boxUp = 100; // tested to 100
int boxDn = 15; // tested to 15

int toppos = topmid;
int botpos = botmid;
int boxpos = 0;

int incoming_state = 0;

void setup() {
  // for interfacing with Pi0
  Serial.begin(9600);

  pinMode(ledIn, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  topservo.attach(9);
  botservo.attach(10);
  boxservo.attach(11);

  topservo.write(topmid);
  botservo.write(botmid);
  boxservo.write(boxDn);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {  //Looking for incoming data
    incoming_state = Serial.read();  //Reading the data
  }

  // runs code based on whether it sees a happy or a sad face
  if (incoming_state == '1') {sadStuff();}
  else if (incoming_state == '2') {happyStuff();}
  
  delay(1000);
  
}

// runs when the bot sees a happy face :)
void happyStuff() {
  
}

// runs when the bot sees a sad face :'((
void sadStuff() {
  
}