/*
TUT 2 - fading and flashing
*/

// declare variable
int pin = 9; // a PWN pin
int count = 0;

// setup function to be run once
void setup(){
	pinMode(pin, OUTPUT);
}

// loop function to be executed repeated after setup
void loop() {
	// you execution code goes herer
	if (count >=255) {
		count = 0;
		/* code */
	}
	digitalWrite(pin, count);
	delay(100);
}
