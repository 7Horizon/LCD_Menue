/*
 * LCD_Display.c
 *
 * Created: 19.01.2015 18:05:24
 *  Author: Jan
 */ 


#include <avr/io.h>
#include "Display.h"
#include "Definitions.h"

void drawDisplay(struct status *Displaystatus);

/* Function Decleration */
void draw_lcd();
void change_level();
void get_function();

int main(void)
{
	lcd_init();
	cur_off();
	blink_off();
	draw_lcd();

	struct status Displaystatus;
	Displaystatus.level = 0;
	Displaystatus.mode = 0;
	Displaystatus.X = 0;
	Displaystatus.Y = 0;
	
    while(1)
    {
        //TODO:: Please write your application code 	
		drawDisplay(&Displaystatus);
    }
}

<<<<<<< HEAD
void drawDisplay(struct status *Displaystatus)
{
	switch(Displaystatus->level){
		
		case 0:
			sendString(0, 2, ":");
			sendString(0, 5, ":");
			sendString(1, 6, ".");
			sendString(1, 9, ".");
			sendString(1, 14, "W");
		break;
	}
	
}

void checkInput()
{
	
}
=======
void get_taster()
{
	//Read port
	//Wait for bouncing off
}

void get_function()
{
	
	
}

void change_level()
{
	
}

void draw_lcd()
{
	
}
>>>>>>> origin/master
