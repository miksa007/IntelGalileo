//miksa007
//13.10.2016
#include <LiquidCrystal.h>
#include <Ethernet.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
EthernetClient client;

void setup() {
lcd.init(1,8,255,9,4,5,6,7,0,0,0,0);
lcd.begin(16, 2);
lcd.clear();
//this doesnt work anymore
//but serial printing works
system("telnetd -l /bin/sh");
lcd.setCursor(0, 1);
  lcd.print("IP:");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    lcd.print(Ethernet.localIP()[thisByte], DEC);
    lcd.print(".");
  }
  Serial.println();
}

void loop() {
  system("ifconfig > /dev/ttyGS0");
  sleep(10);
}

 


