#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
const int sensor = 7;
int sensor_state = 0;

void setup() {
 lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  lcd.setCursor(0,0);
  lcd.print("SECURITY SYSTEM");
  lcd.setCursor(0,1);
  lcd.print("OF RESTRICTED AREA");
  delay(100);
}

void loop() {
sensor_state = digitalRead(sensor);
  if(sensor_state == HIGH) {
    lcd.clear();
    int sensor_byte=10;
    Serial.write(sensor_byte);
    lcd.setCursor(0,1);
    lcd.print("SECURITY BREAK");
    delay(50);
  }

  else {
    lcd.clear ();
    int sensor_byte=20;
    Serial.write(sensor_byte);
    lcd.setCursor(0,1);
    lcd.print("SECURITY SECURED");
    delay(50);
  }
}
