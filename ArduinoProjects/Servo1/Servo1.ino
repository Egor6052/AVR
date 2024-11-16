#include <Servo.h>

Servo myservo;

void setup() {
 myservo.attach(9);
}

void loop() {


// поворот на 0 градусов
 myservo.write(0);
 delay(1000);

// поворот на 90 градусов
 myservo.write(90);
 delay(1000);

 // поворот на 180 градусов
 myservo.write(180);
 delay(1000);
}
