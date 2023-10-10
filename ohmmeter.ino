// Arduino Pin → LCD Pin
// 7→RS, 8→E, 9→D4, 10→D5, 11→D6, 12→D7

#include <LiquidCrystal.h>        // include the lcd library code

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);   // initialize the library with the numbers of the interface pins
int VpPin = A0;

float Vin = 5;    // Arduino 5V regulated power supply
float Vout;
float Rknown = 3900;    // resistance of our known resistor
float Runkown;

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows
}

void loop() {
  lcd.clear();
  Vout =  analogRead(VpPin) * (Vin / 1023);    // analog reading of Vout * (ratio of Vin in volts to Vin as analog signal)
  lcd.setCursor(0, 1);    // column 0, row 1
  lcd.print("Vout = ");
  lcd.print(Vout);
  
  Runkown = (Vin * Rknown) / Vout - Rknown;    // from voltage divider formula
  lcd.setCursor(0,0);
  lcd.print("R = ");
  lcd.print(Runkown);

  delay(250);
}
