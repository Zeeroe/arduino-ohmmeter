#include <LiquidCrystal.h> // include the lcd library code

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int VpPin = A0;

float Vin = 5;
float Vout;
float Rknown = 3900;
float Runkown;

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2); // set up the LCD's number of columns and rows:
}

void loop() {
    lcd.clear();
    Vout = analogRead(VpPin) * (Vin / 1023);
    lcd.setCursor(0, 1);
    lcd.print("Vout = ");
    lcd.print(Vout);

    if (Vout != 0) {
        Runkown = (Vin * Rknown) / Vout - Rknown;
        lcd.setCursor(0, 0);
        lcd.print("R = ");
        lcd.print(Runkown);
    }

    else {
        lcd.setCursor(0, 0);
        lcd.print("R = ");
        lcd.print("inf");
    }

    delay(250);
}
