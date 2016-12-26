/*
TUT 2 - fading and flashing
*/

// declare variable
int pin = 9; // a PWN pin
int buttonPin = 13; // change 2 mode dimming and flash
int potentialPin = A0; // the potentiometer will track how fast it change
bool buttonState = false; // false is dimming state, true is blinking state
bool isLedHigh = false;
bool currentState = false;
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
	// read the button pin
	if (digitalRead(buttonPin) == HIGH && !currentState) {
	    buttonState = !buttonState;
	    currentState = true;
	}
	else if (digitalRead(buttonPin) == LOW && currentState) {
	    currentState = false;
	}
	speed = map(analogRead(potentialPin), 0, 1023, 0, 1000);

	if (count >=255) {
		count = 0;
	}
	count+=5;
	// change the code for the LED to gradually increase light intensity
	if (buttonState) {
	    if (count == 255) {
	        digitalWrite(pin, isLedHigh?HIGH:LOW);
	        isLedHigh = !isLedHigh;
	    }
	}
	else {
	    analogWrite(pin, count);
	}
	delay(speed / 255 * 5);
}
