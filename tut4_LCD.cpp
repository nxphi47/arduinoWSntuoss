// This TUT show the light intensity on the LCD

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
    lcd.setCursor(i, j);
    lcd.print(str);
}

