#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Initialize the I2C LCD with the I2C address (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial BTSerial(10, 11); //  TX | RX 

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  lcd.begin(16,2); // Initialize LCD with correct parameters
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Slave Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (BTSerial.available()) {
    String data = BTSerial.readStringUntil('\n'); // Read until newline

    Serial.println("Received: " + data);

    // Print received data to LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Received:");
    lcd.setCursor(0, 1);
    lcd.print(data);

    delay(2000); // Display data for 2 seconds

    // Clear screen before next update
    lcd.clear();
  }
}
