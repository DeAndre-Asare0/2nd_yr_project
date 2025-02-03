#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
#include "PogoEngine.h"
#include "Sprites.h"



N5110 lcd;
Gamepad pad;
PogoEngine pogo;
Sprites title;

struct UserInput
{
	Direction d;
	float mag;
};

void init();
void welcome();
void render();


int main()
{
	int fps = 6;
	init();
	welcome();
	wait(1.0f / fps);

	while (1)
	{
		pogo.read_input(pad);
		pogo.update(lcd,pad);
		render();
		wait(1.0f / fps);
	}

}

void init()
{
	lcd.init();
	pad.init();
	pogo.init(6, 22, 1, 0);
}

void render()
{
	lcd.clear();
	pogo.draw(lcd);
	lcd.refresh();
}


void welcome() {
	int* _title_screen;
	_title_screen = title.get_title_screen();

	lcd.drawSprite(0, 0, 22, 84,(int*)_title_screen);
	lcd.printString("  Press Start ", 0, 4);
	lcd.refresh();

	// wait flashing LEDs until start button is pressed 
	while (pad.start_pressed() == false) {
		lcd.setContrast(pad.read_pot1());
		pad.leds_on();
		wait(0.1);
		pad.leds_off();
		wait(0.1);
	}

}
