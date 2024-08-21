#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

// Прототипи функцій
void motorAlways(void);
void motor5(void);
void motor10(void);
void motor20(void);
void motorTune1(void);
void motorTune2(void);
void motorTune3(void);

// Змінні стану
bool button1_state = false;
bool button2_state = false;
bool button3_state = false;
bool button4_state = false;

// Функція антідребізгу
uint8_t debounce(uint8_t pin) {
    if (!(PIND & (1 << pin))) {
        _delay_ms(10); // Затримка для подавлення дребезга контактів
        if (!(PIND & (1 << pin))) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    // Встановити PD1, PD2, PD4 і PD5 як входи з підтягуючими резисторами
    DDRD &= ~((1 << PD1) | (1 << PD2) | (1 << PD4) | (1 << PD5));
    PORTD |= (1 << PD1) | (1 << PD2) | (1 << PD4) | (1 << PD5);  // Увімкнути підтягуючі резистори

    // Встановити PB0 як вихід для мотора
    DDRB |= (1 << PB0);

    while (1) {
        // Перевірка стану кнопки PD1
        if (debounce(PD1)) {
            button1_state = !button1_state;
        } 
        // Перевірка стану кнопки PD2
        if (debounce(PD2)) {
            button2_state = !button2_state;
        }
        // Перевірка стану кнопки PD4
        if (debounce(PD4)) {
            button3_state = !button3_state;
        }
        // Перевірка стану кнопки PD5
        if (debounce(PD5)) {
            button4_state = !button4_state;
        }

        // Логіка активації функцій в залежності від комбінації кнопок
        if (button1_state && !button2_state && !button3_state && !button4_state) {
            motorAlways();
        } else if (!button1_state && button2_state && !button3_state && !button4_state) {
            motor5();
        } else if (!button1_state && !button2_state && button3_state && !button4_state) {
            motor10();
        } else if (!button1_state && !button2_state && !button3_state && button4_state) {
            motor20();
        } else if (!button1_state && !button2_state && button3_state && button4_state) {
            motorTune1();
        } else if (!button1_state && button2_state && button3_state && !button4_state){
            motorTune2();
        } else if (button1_state && button2_state && !button3_state && !button4_state){
            motorTune3();
        } 
        else {
            PORTB &= ~(1 << PB0); // Вимкнути мотор, якщо ніяка комбінація не активна
        }
    }
    return 0;
}

void motorAlways(void) {
    PORTB |= (1 << PB0);
    while(button1_state) {
        if (!debounce(PD1)) break;
    }
    PORTB &= ~(1 << PB0);
}

void motor5(void) {
    while (button2_state) {
        PORTB |= (1 << PB0);
        _delay_ms(5);
        PORTB &= ~(1 << PB0);
        _delay_ms(5);
        if (!debounce(PD2)) break;
    }
}

void motor10(void) {
    while (button3_state) {
        PORTB |= (1 << PB0);
        _delay_ms(10);
        PORTB &= ~(1 << PB0);
        _delay_ms(10);
        if (!debounce(PD4)) break;
    }
}

void motor20(void) {
    while (button4_state) {
        PORTB |= (1 << PB0);
        _delay_ms(20);
        PORTB &= ~(1 << PB0);
        _delay_ms(20);
        if (!debounce(PD5)) break;
    }
}

void motorTune1(void) {
    while (button3_state && button4_state) {

        for (int i = 0; i < 3; i++){
            PORTB |= (1 << PB0);
            _delay_ms(5);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

            PORTB |= (1 << PB0);
            _delay_ms(10);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);

        for (int i = 0; i < 3; i++){
            PORTB |= (1 << PB0);
            _delay_ms(5);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

            PORTB |= (1 << PB0);
            _delay_ms(10);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);

        for (int i = 0; i < 3; i++){
            PORTB |= (1 << PB0);
            _delay_ms(5);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(7);

        PORTB |= (1 << PB0);
        _delay_ms(10);
        PORTB &= ~(1 << PB0);
        _delay_ms(5);

        PORTB |= (1 << PB0);
        _delay_ms(15);
        PORTB &= ~(1 << PB0);
        _delay_ms(10);

    }
}

void motorTune2(void) {
    while (button2_state && button3_state) {
        for (int i = 0; i < 3; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(300);
            PORTB &= ~(1 << PB0);
            _delay_ms(10);
        }

        for (int i = 0; i < 3; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(100);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        for (int i = 0; i < 50; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(10);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(10);

        for (int i = 0; i < 50; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(5);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(10);
    }
}


void motorTune3(void) {
    while (button1_state && button2_state) {

        for (int i = 0; i < 50; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(5);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(10);

        for (int i = 0; i < 50; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(10);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(10);

        for (int i = 0; i < 30; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(20);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(10);

        for (int i = 0; i < 30; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(30);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(10);

        for (int i = 0; i < 20; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(40);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(10);

        for (int i = 0; i < 10; i++) {
            PORTB |= (1 << PB0);
            _delay_ms(50);
            PORTB &= ~(1 << PB0);
            _delay_ms(5);
        }

        PORTB &= ~(1 << PB0);
        _delay_ms(10);

    }
}
