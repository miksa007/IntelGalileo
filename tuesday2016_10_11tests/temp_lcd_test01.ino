//miksa007
//date 11.10.2016

#include <LiquidCrystal.h>
//this is keypad shield configuration
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int sensorPin=1;//tmp36 sensor

void setup() {
  //init - compare lcd setup and int(use the same pins)
  lcd.init(1,8,255,9,4,5,6,7,0,0,0,0);
 // set up the LCD's number of columns and rows: 
 lcd.begin(16, 2);
 // Print a message to the LCD.
 lcd.print("hello, world!");
}
void loop() {
  int reading=analogRead(sensorPin);
  float voltage =reading*5.0;
  voltage/=1024.0;
  float temperatureC=(voltage-0.5)*100;
 // set the cursor to column 0, line 1
 // (note: line 1 is the second row, since counting begins with 0):
 lcd.setCursor(0, 1);
 // print the number of seconds since reset:
 //lcd.print(millis()/1000);
 lcd.print(temperatureC);
 lcd.setCursor(6, 1);
 lcd.print("Astetta");
}
