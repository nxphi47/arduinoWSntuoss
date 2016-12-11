// include the LCD's library
#include <LiquidCrystal.h>
//#include <string.h>
#define TIME 60000
#define START 1000
// initialize library with the numbers of the interface pins:
//               (RS, Enable, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(7,  8,      9,   10,  11,  12);

class MovingStr{
public:
    MovingStr(String A,int speed);//speed from 10ms to 500ms
    void print();
    void setArray(String A);
    void setSpeed(int i);
private:
    String str;
    String moving;
    int speed;
};

MovingStr::MovingStr(String A,int speed)
{
    setArray(A);
    setSpeed(speed);
}

void MovingStr::print()
{
    moving=str;
    int duration=TIME + millis();
    while(duration> millis()){
      lcd.setCursor(0,0);
      lcd.print("See below.");
      lcd.setCursor(0, 1);
      lcd.print(moving);
      char c=moving.charAt(0);
      moving.remove(0,1);
      moving+=c;
      delay(speed);
      lcd.clear();
    }
}

void MovingStr::setArray(String A)
{
    str=A;
}

void MovingStr::setSpeed(int i)
{
    speed=i;
}

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // light registor:
  pinMode(A1, INPUT);
  // print a message to the LCD, the default position is upper left (column 0, row 0)
  lcd.print("See below");
}

void loop() {
  // set cursor to beginning of second row (column 0, line 1)
  lcd.setCursor(0, 1);
  int speed=50;
  // print the number of milliseconds since starting the simulation:
  String str="Phi is so powerful."; // a delay is necessary to run the simulation at full speed.
  MovingStr move(str,speed);
  move.print();
}