
const int RedLed = 9;
const int GreenLed = 10;

// int brightness = 0;
void setup() {
  pinMode (RedLed, OUTPUT);
  pinMode (GreenLed, OUTPUT);
}

void loop() {

  for(int i = 0; i < 10; i++){
    digitalWrite(RedLed, HIGH);

    // Управление яркостью;
    // brightness = i % 256;
    // analogWrite(RedLed, brightness);
    

    delay(500);
    digitalWrite(RedLed, LOW);
    delay(200);
  }

  // digitalWrite(RedLed, LOW);
  // delay(10000);

  for (int j = 0; j < 10; j++) {
    digitalWrite(GreenLed, HIGH);
    delay(500);
    digitalWrite(GreenLed, LOW);
    delay(200);
  }
  // digitalWrite(GreenLed, LOW);
  // delay(10000);
}
