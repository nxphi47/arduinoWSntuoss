/*
TUT 1 - blinking
*/

// declare variable
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
