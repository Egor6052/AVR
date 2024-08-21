Компілюємо:

avr-gcc -mmcu=atmega8 -DF_CPU=16000000UL -Os -o led.o led.c

	тут: 
	led.o - файл, який ми отримаємо;
	led.c - файл, який ми написали;

Додаємо в hex:

avr-objcopy -O ihex -R .eeprom led.o led.hex

	тут: 
	led.o - файл, який ми отримали;
	led.c - файл, який ми хочемо створити для прошивки;

Прошиваємо контролер:

avrdude -c usbasp -p m8 -U flash:w:led.hex

	Де: 
	m8 - тип контролера (Atmega8);
	led.hex - файл з кодом;