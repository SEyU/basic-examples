void setup() {
    pinMode(5, OUTPUT); //GPIO5 (D1) 
}

void loop() {
    
    for (int i = 0; i < 1023; i++) 
    {
      analogWrite(5, i); //PWM using analogWrite
      delay(1);
    }

    delay(500);

}

