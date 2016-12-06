#------------NTUOSS Arduino Workshop--------------
Created by: Xuan Phi Nguyen
This Workshop is aimed at the basic about the arduino board
with some simple tutorial exercises
#I/ Installation:

1 - with a real arduino board we download the Arduino IDE with some extensions:
----------------------------------
[link arduino IDE](www.goole.com)

[Visual Micro](www.google.com) extensions with Visual studio

[xcode](apple.com) on macos

[plaformio](plaformio)

2 - with 123circuit.io
-------------------------------------
this website used to simulate the program of the arduino operation
with many electrical components that act as real

#II/ About the Arduino
Electronic board to control electrical components.

Controlled with many pins with different functionality

* 13 digital pins (pin 9.., is PWM - pulse width modulation).
* 4 analog pin.

Communication port: I2C, serial bus, software serial library

System specification: 	
* CPU:
* RAM:

Use with raspberry pi via I2C

About digital and analog

#III/ tutorial - to be conducted on 123circuit.io

0 - basic syntax
###Known about C/C++, it is exactly the same, except for the lack of library
	#include <lcd>

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

------------------------------
1 - Blinking
------------------------------
plug in the LED to pin 13 (remember to put the anode - longer) and cathode to the ground.

load the program, and see what happen? is this a good way to do it???.

try to plug the led in series with a resistor (xxx Ohm) and try again??.

explain why?.

Try to modify the delay and see the effect?

2 - dimming and flashing with button
----------------------------------
put the LED to pin 9
3 - work with servo
----------------------------------
4 - light sensor
----------------------------------
5 - LCD (optional)
----------------------------------
Finale challenge - build a automatic gantry
----------------------------------
you gonna build a auto gantry which can detect a car comming, open the gantry
and close when the car pass by
