#include <Servo.h>
Servo myservo;
int ledPin = 13;
int sensorValue = 0;
int x=0;
int buttonPin = 2;
boolean currentState= LOW;
boolean lastState=LOW;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT);
 myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly
 myservo.write(0);
 currentState=lastState;
 int sensorValue = analogRead(A1);
 Serial.println(sensorValue);
 if (sensorValue>400){
  while ((currentState==lastState)&&(sensorValue>400)){
    digitalWrite(ledPin, HIGH);
    delay(30);
    digitalWrite(ledPin, LOW);
    delay(30);
    currentState=digitalRead(buttonPin);
    Serial.println(sensorValue);
    sensorValue=analogRead(A1);
   }
  if (currentState != lastState){
  myservo.write(90);
  sensorValue=analogRead(A1);
  while (sensorValue>400){
    sensorValue=analogRead(A1);
    Serial.println(sensorValue);
    digitalWrite(ledPin, HIGH);
    delay(30);
    digitalWrite(ledPin, LOW);
    delay(30);
  }
  delay(500);
  myservo.write(0);
  }
 }
}
