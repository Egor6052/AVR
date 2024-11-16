#include <TM1637Display.h>

const int GreenLed1 = 11;
const int YellowLed1 = 5;
const int RedLed1 = 12;

const int LedLeft = 6;
const int LedRight = 7;

const int Button = 4;            // Кнопка включения
const int ButtonLeft = 3;        // Кнопка влево
const int ButtonRight = 2;       // Кнопка вправо

const int EmergencySignal = 8;   // Экстренное выключение

const int Buzzer = 13;           // Сигнализация
const int Engine_IN1 = 9;        // Пин IN1 подключен к пину 9
const int Engine_IN2 = 10;       // Пин IN2 подключен к пину 10

bool buttonState = HIGH;
bool lastButtonState = HIGH;
bool motorState = false;         // Состояние мотора (включен или выключен)
bool LeftState = false;       // Состояние лампочки LedLeft
bool RightState = false;      // Состояние лампочки LedRight

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
bool systemActive = false;      // Флаг, указывающий, активна ли система
bool systemButtonPressed = false; // Флаг, указывающий, была ли нажата кнопка включения

TM1637Display display(1, 0);    // Инициализация дисплея с пинами CLK и DIO

void setup() {
  pinMode(Engine_IN1, OUTPUT);
  pinMode(Engine_IN2, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(GreenLed1, OUTPUT);
  pinMode(YellowLed1, OUTPUT);
  pinMode(RedLed1, OUTPUT);
  pinMode(LedLeft, OUTPUT);
  pinMode(LedRight, OUTPUT);
  pinMode(Button, INPUT_PULLUP);
  pinMode(ButtonLeft, INPUT_PULLUP);
  pinMode(ButtonRight, INPUT_PULLUP);
  pinMode(EmergencySignal, INPUT);
  
  display.setBrightness(0x0a);
}

void loop() {
  int emergencySignal = digitalRead(EmergencySignal);

  if (emergencySignal == HIGH) {
    NormalMode();
  } else {
    EmergencyMode();
  }
}

void NormalMode() {
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

        lastDebounceTime = millis();

        if (systemActive) {
          systemActive = false; // Если система активна, повторное нажатие отключает её
        } else {
          systemActive = true;  // Если система неактивна, первое нажатие включает её
        }
      }
    }
  }

  lastButtonState = reading;

  if (systemActive) {            // Проверяем, активна ли система перед обработкой кнопок
    digitalWrite(YellowLed1, HIGH);
    digitalWrite(GreenLed1, LOW);
    ButtonLeftMode();
    ButtonRightMode();
  } else {
    
    digitalWrite(LedLeft, LOW);
    digitalWrite(LedRight, LOW);
    digitalWrite(Engine_IN1, LOW);
    digitalWrite(Engine_IN2, LOW);
    digitalWrite(YellowLed1, LOW);
    digitalWrite(GreenLed1, HIGH);
  }
}


void ButtonLeftMode() {
  if (digitalRead(ButtonLeft) == LOW && (millis() - lastDebounceTime > debounceDelay)) {
    tone(Buzzer, 1000);
    delay(1000);
    noTone(Buzzer);

    LeftState = !LeftState;
    motorState = !motorState;

    if (LeftState) {
      if (RightState = HIGH) {
        RightState = !RightState;
      }
      
      if (motorState) {
        digitalWrite(Engine_IN1, LOW);
        digitalWrite(Engine_IN2, HIGH);
      } else {
        digitalWrite(Engine_IN1, LOW);
        digitalWrite(Engine_IN2, LOW);
      }
      digitalWrite(LedLeft, HIGH);
      digitalWrite(LedRight, LOW);
      digitalWrite(YellowLed1, HIGH);
      digitalWrite(GreenLed1, LOW);
    } else {
     
      digitalWrite(LedLeft, LOW);
      digitalWrite(YellowLed1, LOW);
      digitalWrite(GreenLed1, HIGH);
    }

    lastDebounceTime = millis();
  }
}

void ButtonRightMode() {
  if (digitalRead(ButtonRight) == LOW && (millis() - lastDebounceTime > debounceDelay)) {
    tone(Buzzer, 1000);
    delay(1000);
    noTone(Buzzer);

    RightState = !RightState;
    motorState = !motorState;

    if (RightState) {
      if (LeftState = HIGH) {
        LeftState = !LeftState;
      }

      if (motorState) {
        digitalWrite(Engine_IN1, HIGH);
        digitalWrite(Engine_IN2, LOW);
      } else {
        digitalWrite(Engine_IN1, LOW);
        digitalWrite(Engine_IN2, LOW);
      }
      
      digitalWrite(LedRight, HIGH);
      digitalWrite(LedLeft, LOW);
      digitalWrite(YellowLed1, HIGH);
      digitalWrite(GreenLed1, LOW);
    } else {
      
      digitalWrite(LedRight, LOW);
      digitalWrite(YellowLed1, LOW);
      digitalWrite(GreenLed1, HIGH);
    }
    digitalWrite(LedRight, RightState ? HIGH : LOW);

    lastDebounceTime = millis();
  }
}

void EmergencyMode() {
 digitalWrite(RedLed1, HIGH);
 digitalWrite(YellowLed1, LOW);
 digitalWrite(GreenLed1, LOW);

for (int i = 0; i < 3; i++) {
  tone(Buzzer, 600);
  delay(100);
  noTone(Buzzer);
  delay(100);
}
delay(1000);

  motorState = false;
}
