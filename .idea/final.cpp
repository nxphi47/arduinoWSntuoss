//* Let's build a automatic gantry that can detect a car comming - Use Photoresistor
//* Make it open the gantry if the use push some button - Use servo
//* Close the gantry 2s after the car pass
//* Bonus: use LCD to display price

#include <Servo.h>
#include <LiquidCrystal.h>

// initialize some variable
Servo gantryServo;
LiquidCrystal lcd(7,    8,    9,   10,  11,  12); //(RS, Enable, DB4, DB5, DB6, DB7)

int lightPin = A0;
int servoPin = 9;
int buttonPin = 13;

bool isCar = false;
bool isPaid = false;

void setup() {
    gantryServo.attach(servoPin);
    lcd.begin(16,2);
    pinMode(buttonPin, INPUT);
}

void loop() {
    /* your code goes here */

    // read the LIGHT sensor

    // if there is a car there, display some message

    // if user pay (or press the button), show some message and open the gantry

    // if the car just go out, close the gantry

}

class Gantry {
public:
    Gantry();
    int readSensor();
    void showMessage();
    void pay();
private:


}