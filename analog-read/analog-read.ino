void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(A0); //read value from A0
  float voltage = sensorValue * (3.3 / 1023.0); //convert to voltage
  
  Serial.print("Value=");
  Serial.print(sensorValue);
  Serial.print(" Voltage=");
  Serial.println(voltage);

  delay(100);
}
