#include <Servo.h>

// create Servo object
Servo servo;

int servoPin = 9;
int buttonPin = 13;
int potentialPin = A0;
int lightPin = A1;
int val;
bool isPotential = true;

void setup() {
    pinMode(buttonPin, INPUT);
    servo.attach(servoPin);
}

void loop() {
    val = getAnalogInput();
    servo.write(val);
    delay(20); // delay to avoid sudden voltage change which cause unpreditability
    if (digitalRead(buttonPin) == HIGH)  {
        isPotential = !isPotential;
    }


}

int getAnalogInput() {
    if (isPotential){
        return map(analogRead(potentialPin), 0, 1023, 0, 180); // map input value to 180 degree
    }
    else {
        return map(analogRead(lightPin), 0, 1023, 0, 180); // map input value to 180 degree

    }
}