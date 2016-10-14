##------------NTUOSS Arduino Workshop--------------
Created by: Xuan Phi Nguyen
This Workshop is aimed at the basic about the arduino board
with some simple tutorial exercises
--------------------------------------------------
##I/ Installation:
there are several way to install
#1 - with a real arduino board we download the Arduino IDE with some extensions:
	[link arduino IDE](www.goole.com)
	[Visual Micro](www.google.com) extensions with Visual studio
	[xcode](apple.com) on macos
	[plaformio](plaformio)
#2 - with 123circuit.io
this website used to simulate the program of the arduino operation
with many electrical components that act as real
---------------------------------------------
#II/ About the arduino
Electronic board to control electrical components.

Controlled with

* 13 digital pins (pin 9.., is PWM - pulse width modulation).
* 4 analog pin.

Communication port: I2C, serial bus, software serial library

System specification: 	
* CPU:
* RAM:

Use with raspberry pi via I2C

##III/ tutorial - to be conducted on 123circuit.io

#0 - basic syntax

#1 - Blinking
	plug in the LED to pin 13 (remember to put the anode - longer) and cathode to the ground.

	load the program, and see what happen? is this a good way to do it???.

	try to plug the led in series with a resistor (xxx Ohm) and try again??.

	explain why?.

	Try to modify the delay and see the effect?

#2 - dimming and flashing with button
	put the LED to pin 9
#3 - work with servo
#4 - light sensor
#5 - LCD (optional)

#Finale challenge - build a automatic gantry
	you gonna build a auto gantry which can detect a car comming, open the gantry
	and close when the car pass by
