const int RedLed1 = 8;
const int RedLed2 = 9;
const int RedLed3 = 10;
const int RedLed4 = 11;
const int RedLed5 = 12;
const int RedLed6 = 13;
const int Button = 3;

void setup() {
  for (int i = RedLed1; i <= RedLed6; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(Button, INPUT_PULLUP);
}

void loop() {
  for (int i = RedLed1; i <= RedLed6; i++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(100);

    if (i == RedLed4 && digitalRead(Button) == LOW) {
      for (int j = 0; j < 10; j++) {
        digitalWrite(RedLed4, HIGH);
        delay(100);
        digitalWrite(RedLed4, LOW);
        delay(100);
      }
    }
  }
}
