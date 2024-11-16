const int Led3 = 3;
const int Led4 = 4;
const int Led5 = 5;
const int Led6 = 6;
const int Led7 = 7;
const int Led8 = 8;
const int Led9 = 9;
const int Led10 = 10;
const int Led11 = 11;
const int Led12 = 12;
const int Led13 = 13;


void setup() {
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);
  pinMode(Led8, OUTPUT);
  pinMode(Led9, OUTPUT);
  pinMode(Led10, OUTPUT);
  pinMode(Led11, OUTPUT);
  pinMode(Led12, OUTPUT);
  pinMode(Led13, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    if (i == 0) { zero(); }
    else if (i == 1) { one(); }
    else if (i == 2) { two(); }
    else if (i == 3) { three(); }
    else if (i == 4) { four(); }
    else if (i == 5) { five(); }
    else if (i == 6) { six(); }
    else if (i == 7) { seven(); }
    else if (i == 8) { eight(); }
    else if (i == 9) { nine(); }

    delay(500);
  }
}
// 6 - точка
// 7 - право низ
// 8 - середина
// 3 - право верх
// 9 - вторая и третяя
// 10 - верх
// 5 - низ
// 4 - лево низ
// 11 - лево верх
// 12 - вервая и третяя цифра
// 13 - первая и вторая


void nine(){
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led10, LOW);
  digitalWrite(Led11, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led5, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led4, HIGH);
  digitalWrite(Led8, HIGH);
};

void eight(){
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led10, LOW);
  digitalWrite(Led11, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led5, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led4, HIGH);
  digitalWrite(Led8, HIGH);
};

void seven(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led11, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led7, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led10, HIGH);
};

void six(){
  digitalWrite(Led3, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led13, LOW);
  digitalWrite(Led12, LOW);

  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led4, HIGH);
};

void five(){
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
};

void four(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led10, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led3, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led11, HIGH);
};

void three(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led11, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led3, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led10, HIGH);
};

void two(){
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led11, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led10, HIGH);
};

void one(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led10, LOW);
  digitalWrite(Led11, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led7, HIGH);
  digitalWrite(Led3, HIGH);

};


void zero(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led12, LOW);
  digitalWrite(Led13, LOW);

  digitalWrite(Led5, HIGH); 
  digitalWrite(Led7, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led4, HIGH);
};
