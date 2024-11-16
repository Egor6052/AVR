#include <stDHT.h>
DHT sens(DHT11, 2); // Предполагаем, что датчик подключен к пину 2

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, ButtonDown = 6, ButtonUp = 7, ButtonOk = 8, ButtonX = 9;
bool lastButtonState = HIGH;
int arrowPosition = 0; // Переменная для отслеживания текущей позиции стрелки
int menuPage = 1; // Переменная для отслеживания текущей страницы меню
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  // для температуры;
  Serial.begin(57600);
  pinMode(10, INPUT);
  digitalWrite(10, HIGH);

  // для генерации рандомных чисел;
  randomSeed(analogRead(0));

  pinMode(ButtonDown, INPUT_PULLUP);
  pinMode(ButtonUp, INPUT_PULLUP);
  pinMode(ButtonOk, INPUT_PULLUP);
  pinMode(ButtonX, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(1, 0);
  lcd.print("Start Micro PC");

  lcd.setCursor(0, 1);
  lcd.print("[");
  lcd.setCursor(15, 1);
  lcd.print("]");

  for(int j = 1; j <= 14; j++){
    lcd.setCursor(j, 1);
    lcd.print("*");
    delay(50);
  }

  delay(500);
  lcd.clear();
}

void loop() {
// Для температуры и влажности;

  int temperature = sens.readTemperature();
  int humidity = sens.readHumidity();

  delay(2000);

  lcd.clear();

  // lcd.setCursor(10, 0);
  // lcd.print("20:45");

  // Отображение меню на текущей странице
  if (menuPage == 1) {
    lcd.setCursor(2, 0);
    lcd.print("Temp. ");
    lcd.print(temperature);
    lcd.print(" C");

    lcd.setCursor(2, 1);
    lcd.print("Moisture  ");
    lcd.print(humidity);
    lcd.print(" %");
  } else if (menuPage == 2) {
     lcd.setCursor(2, 0);
    lcd.print("Game");
    lcd.setCursor(2, 1);
    lcd.print("setings");
  }

// Кнопка вниз
  int CursorDown = digitalRead(ButtonDown);
  if (CursorDown != lastButtonState && CursorDown == LOW) {
    arrowPosition = (arrowPosition + 1) % 2;
    if (arrowPosition == 0) {
      if (menuPage == 1) {
        menuPage = 2;
      }
    }
  }
  lastButtonState = CursorDown;


  // Кнопка вверх
  int CursorUp = digitalRead(ButtonUp);
  if (CursorUp != lastButtonState && CursorUp == LOW) {
    arrowPosition = (arrowPosition - 1 + 2) % 2;
    if (arrowPosition == 1) {
      if (menuPage == 2) {
        menuPage = 1;
      }
    }
  }
  lastButtonState = CursorUp;

  // Кнопка "ОК"
  int CursorOk = digitalRead(ButtonOk);
  
  if (CursorOk != lastButtonState) {
    if (CursorOk == LOW) {
      // обработка страниц
      if (menuPage == 1) {
        // обработка строк
        if(arrowPosition == 0){
          // menu1();
        }
        if(arrowPosition == 1){
          // menu2();
        }
        // обработка страниц
      } else if (menuPage == 2) {
        // обработка строк
        if(arrowPosition == 0){
          menu3();
        }
        if(arrowPosition == 1){
          menu4();
        }
      }
    }
  }
  lastButtonState = CursorOk;

  // Отображение стрелки в зависимости от текущей позиции
  lcd.setCursor(0, arrowPosition);
  lcd.print("->");
  // lcd.setCursor(14, arrowPosition);
  // lcd.print("<-");

  delay(200);
}


// void menu1() {
// lcd.clear();
//   while (true) {
//   lcd.setCursor(2, 0);
//   lcd.print("Temperature");
//   lcd.setCursor(3, 1);
//   lcd.print("Menu 1");

//   // Кнопка выхода;
//     if(digitalRead(ButtonX) == LOW){
//       break;
//     }
//   }
//   delay(1000);
// }




// void menu2() {
// lcd.clear();
//   while (true) {
//   lcd.setCursor(2, 0);
//   lcd.print("Moisture");
//   lcd.setCursor(3, 1);
//   lcd.print("Menu 2");

//   // Кнопка выхода;
//     if(digitalRead(ButtonX) == LOW){
//       break;
//     }
//   }
//   delay(1000);
// }





void menu3(){
 lcd.clear();

  for(int i = 0; i < 15; i++){
    lcd.setCursor(0, 0);
    lcd.print("Avoid Obstacles!");

    lcd.setCursor(i, 1);
    lcd.print("->");

    if(i%2 == 0){
      lcd.setCursor(i-3, 1);
      lcd.print("-");
    }

    delay(100);
    lcd.clear();
  }
  
  int arrowPosition = 0; // стрелка
  int obstaclePosition = 15; // препятствие
  int bulletPosition = -1; // снаряд
  int score = 0;
  int bombPositionX = -1; // начальная позиция бомбы по горизонтали

  bool arrowHit = false; // Флаг для отслеживания попадания стрелки в препятствие
  bool bulletHit = false; // Флаг для отслеживания попадания снаряда в препятствие


  // Генерация случайной вертикальной позиции препятствия (0 или 1)
  int rand = random(0, 2);

  while (true) {
    lcd.clear();

    // Отображение стрелки
    lcd.setCursor(0, arrowPosition);
    lcd.print("->");

    // Отображение препятствия
    lcd.setCursor(obstaclePosition, rand);
    lcd.print("*");

    // Отображение снаряда, если он активен
    if (bulletPosition != -1) {
      lcd.setCursor(bulletPosition, arrowPosition);
      lcd.print("-");
    }

    // Отображение счета
    lcd.setCursor(12, 0);
    lcd.print("Score:");
    lcd.setCursor(12, 1);
    lcd.print(score);

    // Обновление позиции стрелки
    int CursorDown = digitalRead(ButtonDown);
    if (CursorDown != lastButtonState && CursorDown == LOW) {
      if (arrowPosition < 1) {
        arrowPosition++;
      }
    }
    lastButtonState = CursorDown;

    int CursorUp = digitalRead(ButtonUp);
    if (CursorUp != lastButtonState && CursorUp == LOW) {
      if (arrowPosition > 0) {
        arrowPosition--;
      }
    }
    lastButtonState = CursorUp;

    // Проверка на пересечение стрелки с препятствием
    if (arrowPosition == rand && obstaclePosition == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Game Over!");
      lcd.setCursor(0, 1);
      lcd.print("Score:");
      lcd.print(score);
      delay(2000);
      break;
    }

    // Проверка попадания снаряда в препятствие
    if (!bulletHit && bulletPosition == obstaclePosition && arrowPosition == rand){
      // Снаряд попал в препятствие, удалить препятствие и увеличить счет
      obstaclePosition = 15; // Установить позицию препятствия за пределы экрана
      score++;
      bulletPosition = -1; // Сбросить позицию снаряда
      bulletHit = true; // Установить флаг попадания снаряда

    }

    // Перемещение препятствия
    obstaclePosition--;

    // Увеличение счета при успешном избегании препятствия
    if (obstaclePosition == -1) {
      score++;
      obstaclePosition = 15; // Перемещаем препятствие обратно вправо после прохождения
      // Сгенерировать новую случайную вертикальную позицию препятствия
      rand = random(0, 2);
    }

    // Обработка нажатия кнопки "ОК" для запуска снаряда
    if (digitalRead(ButtonOk) == LOW) {
      if (bulletPosition == -1) { // Если снаряд не активен, активируем его
        bulletPosition = 0;
      }
    }    
    
    // Перемещение снаряда, если он активен
    if (bulletPosition != -1) {
      bulletPosition++;
      // Если снаряд достиг правого края экрана, сбросить его позицию
      if (bulletPosition >= 16) {
        bulletPosition = -1;
      }
    }

    // Проверка попадания стрелки в препятствие
    if (!arrowHit && arrowPosition == rand && obstaclePosition == 0) {
      arrowHit = true; // Установить флаг попадания стрелки
    }


    // Кнопка выхода;
    if(digitalRead(ButtonX) == LOW){
      break;
    }


    delay(200);
  }
}

void menu4() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Settings");
  delay(500);

  while (true) {
    // Отображение меню на текущей странице
    if (menuPage == 1) {
      lcd.setCursor(2, 0);
      lcd.print("Time");
      lcd.setCursor(2, 1);
      lcd.print("Menu 2");
    } else if (menuPage == 2) {
      lcd.setCursor(2, 0);
      lcd.print("Menu 3");
      lcd.setCursor(2, 1);
      lcd.print("Menu 4");
    }

    // Кнопка вниз
    int CursorDown = digitalRead(ButtonDown);
    if (CursorDown != lastButtonState && CursorDown == LOW) {
      arrowPosition = (arrowPosition + 1) % 2;
      if (arrowPosition == 0) {
        if (menuPage == 1) {
          menuPage = 2;
        }
      }
    }
    lastButtonState = CursorDown;

    // Кнопка вверх
    int CursorUp = digitalRead(ButtonUp);
    if (CursorUp != lastButtonState && CursorUp == LOW) {
      arrowPosition = (arrowPosition - 1 + 2) % 2;
      if (arrowPosition == 1) {
        if (menuPage == 2) {
          menuPage = 1;
        }
      }
    }
    lastButtonState = CursorUp;

    // Кнопка "ОК"
    int CursorOk = digitalRead(ButtonOk);
    if (CursorOk != lastButtonState && CursorOk == LOW) {
      // обработка страниц и строк
      if (menuPage == 1) {
        if (arrowPosition == 0) {
          // menu1();
        } else if (arrowPosition == 1) {
          // menu2();
        }
      } else if (menuPage == 2) {
        if (arrowPosition == 0) {
          // menu3();
        } else if (arrowPosition == 1) {
          // menu4();
        }
      }
    }
    lastButtonState = CursorOk;

    // Отображение стрелки в зависимости от текущей позиции
    lcd.clear();
    lcd.setCursor(0, arrowPosition);
    lcd.print("->");

    // Кнопка выхода;
    if (digitalRead(ButtonX) == LOW) {
      break;
    }

    delay(100);
  }
}