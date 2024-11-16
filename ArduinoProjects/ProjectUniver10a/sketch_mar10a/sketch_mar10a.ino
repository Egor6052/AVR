const int GreenLed1 = 8;
const int YellowLed1 = 11;
const int RedLed1 = 9;
const int Button = 3;     // Кнопка включения

const int EmergencySignal = 4; // Экстренное выключение

const int Buzzer = 10;    // Сигнализация
const int Engine_IN1 = 5; // Пин IN1 подключен к пину 5
const int Engine_IN2 = 6; // Пин IN2 подключен к пину 6

bool buttonState = HIGH;
bool lastButtonState = HIGH;

bool motorState = false; // Состояние мотора (включен или выключен)
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // Время для отскакивающего сигнала 5мкСек;

void setup() {
  pinMode(Engine_IN1, OUTPUT);
  pinMode(Engine_IN2, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(GreenLed1, OUTPUT);
  pinMode(YellowLed1, OUTPUT);
  pinMode(RedLed1, OUTPUT);
  pinMode(Button, INPUT_PULLUP);
  pinMode(EmergencySignal, INPUT);
}

void loop() {
  int emergencySignal = digitalRead(EmergencySignal);

  if(emergencySignal == HIGH) {
    NormalMode();
  } else {
    EmergencyMode();
  }
}

void NormalMode(){
  // Нормальная работа
  digitalWrite(RedLed1, LOW);  // Включаем красный индикатор

  int reading = digitalRead(Button);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) { 
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        tone(Buzzer, 1000);
        delay(1000);
        noTone(Buzzer);

        // Переключаем состояние мотора
        motorState = !motorState;

        // Включаем или выключаем мотор в зависимости от его текущего состояния
        if (motorState) {
          // Включаем мотор
          digitalWrite(Engine_IN1, HIGH);
          digitalWrite(Engine_IN2, LOW);
          digitalWrite(YellowLed1, HIGH);
          digitalWrite(GreenLed1, LOW);
        } else {
          digitalWrite(GreenLed1, HIGH);
          digitalWrite(YellowLed1, LOW);
          // Выключаем мотор
          digitalWrite(Engine_IN1, LOW);
          digitalWrite(Engine_IN2, LOW);
        }
      }
    }
  }
  lastButtonState = reading;

}

void EmergencyMode(){
  // Экстренное выключение;
  digitalWrite(RedLed1, HIGH);  // Включаем красный индикатор
  tone(Buzzer, 700);           // Включаем сигнализацыю
  delay(1000);
  noTone(Buzzer);
  delay(2000);
  motorState = false;           // Выключаем подачу на мотор
  digitalWrite(GreenLed1, LOW);  // Выключаем остальные фонарики, какие бы ни были
  digitalWrite(YellowLed1, LOW);
}
