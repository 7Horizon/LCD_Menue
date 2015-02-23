/*
 * LCD_Display.c
 *
 * Created: 19.01.2015 18:05:24
 *  Author: Jan
 */ 


#include <avr/io.h>
#include "Display.h"

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

	sendString(5,1,"Hallo Greppi");
	
    while(1)
    {
        //TODO:: Please write your application code 	
		
    }
}

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
