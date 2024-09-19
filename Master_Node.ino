#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  String data = "go slow !";
  BTSerial.println(data); // Send data with newline
  Serial.println(data);  // Print data to Serial Monitor
  delay(1000);           // Delay for 1 second
}


