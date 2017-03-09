#NTUOSS Arduino Workshop
This Workshop is aimed at the basic about the arduino board
with some simple tutorial exercises
Created by: Xuan Phi Nguyen

##I/ Installation:

###with a real arduino board and Arduino IDE with some extensions:
[Arduino IDE](https://www.arduino.cc/en/Main/Software)

[Visual Micro](http://www.visualmicro.com/) extensions with Visual studio and Arduino IDE

[Platformio](http://platformio.org/) Extensions with Arduino IDE using ATOM text editor

###with https://circuits.io

this website used to simulate the program of the arduino operation
with many electrical components that act as real

##II/ About the Arduino
Electronic board to control electrical components.

Controlled with many pins with different functionality

* 13 digital pins (pin 9.., is PWM - pulse width modulation).
* 4 analog pin.

Communication port: I2C, serial bus, software serial library

System specification:
* MicroController:      ATmega328P
* Clock speed:			16 MHz (Veryyyy small)
* Operating Voltage:	5V
* Digital Pin:			14 (6 of which is PWM)
* Analog pin:			6
* RAM:					2KB (Veryyyy Small)
* Flash memory:		    32KB (Very small too)

Use with raspberry pi via I2C

About digital and analog

##III/ tutorial - to be conducted on 123circuit.io
###0 - basic syntax

Known about C/C++, it is exactly the same, except for the lack of library

```
int foo = 2;
int pin1 = 13;
int pin2 = 9;

void setup(){
    /*Run only once since the arduino reset!*/
    // setup pinMode for digital and analog pin
    pinMode(pin1, OUTPUT);
    pinMode(pint2, INPUT);
    pinMode(A0, OUTPUT);

    // Serial port to communicate with ardunino in real-time
    Serial.begin(9600);
};

void loop(){
    /*Run in loop all over again*/
    // set the pin1 to high
    digitalWrite(pin1, HIGH);
    // read the input at pint2
    digitalRead(pin1); // = 1
    // read the input of analog pin
    int x = analogRead(A0);

    Serial.println(x);
}

for (uint_8 i =0; i < 128; i++){

}
```

###1 - Blinking

```
// declare variable, connet LED to pin 13
int pin = 13;

// setup function to be run once
void setup(){
    pinMode(pin, OUTPUT);
}

// loop function to be executed repeated after setup
void loop() {
    // you execution code goes herer
    digitalWrite(pin, HIGH);	// turn it on
    delay(500);					// delay for 500milis
    digitalWrite(pin, LOW);
    delay(500);					// delay for 500milis

}
```

* load the program, and see what happen? is this a good way to do it???.

* try to plug the led in series with a resistor (xxx Ohm) and try again??.

* explain why?.

* Try to modify the delay and see the effect?

###2 - dimming and flashing with button
```
// Interchanging blinking mode or dimming mode with button
// change dimming/blinking speed by the potentiometer

// declare variable
int pin = 9; // a PWN pin, value taken for analogWrite() from 0 to 255 (0 -> 5V)
int buttonPin = 13; // change 2 mode dimming and flash
int potentialPin = A0; // the potentiometer will track how fast it change
bool buttonState = false; // false is dimming state, true is blinking state
bool isLedHigh = false;
bool currentState = false; // current state of the button
int count = 0;
int speed = 0;

// setup function to be run once
void setup(){
    pinMode(buttonPin, INPUT);
    pinMode(pin, OUTPUT);
}

// loop function to be executed repeated after setup
void loop() {
    // you execution code goes here
    // read the button digital pin
    if (digitalRead(buttonPin) == HIGH && !currentState) {
        // transition of currentState from LOW -> HIGH when press button
        buttonState = !buttonState;
        currentState = true;
    }
    else if (digitalRead(buttonPin) == LOW && currentState) {
        // transition of currentState from HIGH -> LOW when press button
        currentState = false;
    }
    // mapping value of (0 -> 1023) to (0 -> 1000);
    speed = map(analogRead(potentialPin), 0, 1023, 0, 1000);

    // return to value 0 when count exceed 255
    if (count >=255) {
        count = 0;
    }

    // increment by 5 each iteration
    count+=5;
    // change the code for the LED to gradually increase light intensity
    if (buttonState) {
        // True means it is digital input
        if (count == 255) {
            // change state of LED every time count reach 255
            digitalWrite(pin, isLedHigh?HIGH:LOW);
            isLedHigh = !isLedHigh;
        }
    }
    else {
        // gradually increase light intensity
        analogWrite(pin, count);
    }
    // for every cycle of 255, delay a amount defined by "speed" for each 5 incremental step
    delay(speed / 255 * 5);
}
```


###3 - Servo Controller with potentiometer and photoresistor

Servo use PWM pin to controller its motion, so we attach it to pin 5
```
#include <Servo.h>
// servo is a motor that remain it rotational position under a provided PWM value voltage
// control the direction of servo by potentiometer or light resistor
// create Servo object
Servo servo;

int servoPin = 9;
int buttonPin = 13;
int potentialPin = A0;
int lightPin = A1;
// angle value (0 -> 180) to set to the servo
int val;
bool isPotential = true;

// execute once
void setup() {
    pinMode(buttonPin, INPUT);
    servo.attach(servoPin);

    // analogPin does not need declaration
}


// repeatedly executed
void loop() {
    // do not try to instantiate variable in the loop
    // Since we have no garbage collection and will soon run out of memory
    // int val = getAnalogInput();

    val = getAnalogInput();
    servo.write(val); // receive input from 0 to 180
    delay(20); // delay to avoid sudden voltage change which cause unpreditability

    // isPotential will keep flipping if we keep pressing the button
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
```

###4 - LCD - 16bit

* Use LCD to display the photoresistor value.

```
// include the LCD's library
#include <LiquidCrystal.h>

// initialize LCD object with the numbers of the interface pins:
//               (RS, Enable, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(7,    8,    9,   10,  11,  12);

// light sensor
int lightPin = A0;

// main setup
void setup() {
    lcd.begin(16, 2); // init the LCD object to 16x2 size
    // by default, the cursor position is at (0,0)
    lcd.print("Light: ");
}

// the loop
void loop() {
    int val = analogRead(lightPin);
    print(String(val) + "    ", 12, 0);
    delay(20);

}

// Some LCD function
void print(String str, int i, int j) {
    // set the cursor at column i, row j
    lcd.setCursor(i, j);
    lcd.print(str);
}


```

###Finale challenge - build a automatic gantry
* Let's build a automatic gantry that can detect a car comming - Use Photoresistor
* Make it open the gantry if the use push some button - Use servo
* Close the gantry 2s after the car pass
* Bonus: use LCD to display price

