#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);

void setup() {
 lcd.begin(16,2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("SECURITY SYSTEM");
  lcd.setCursor(0,1);
  lcd.print("OF RESTRICTED AREA");
  delay(100);
}

void loop() {
  int sensor_byte = Serial.read();;
  if(sensor_byte == 10) {
    lcd.clear ();
    Serial.print("PIRSENSOR :");
    Serial.println(sensor_byte);
    lcd.setCursor(0,1);
    lcd.print("SECURITY BREAK");
    delay(50);
  }

  else if(sensor_byte == 20) {
    lcd.clear();
    Serial.print("PIRSENSOR :");
    Serial.println(sensor_byte);
    lcd.setCursor(0,1);
    lcd.print("SYSTEM SECURED");
    delay(50);
  }
}
