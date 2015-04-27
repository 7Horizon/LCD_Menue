/*
 * LCD_Display.c
 *
 * Created: 19.01.2015 18:05:24
 *  Author: Jan
 */ 


#include <avr/io.h>
#include "Display.h"
#include "Definitions.h"

void drawDisplay();
void switchInit();
int countBits(byte Byte);
void checkInput();

byte keyCounter;
byte pressedSwitch;
byte switchValue;
struct status Displaystatus;

int main(void)
{
	switchInit();
	lcd_init();
	cur_off();
	blink_off();

	
	Displaystatus.level = 0;
	Displaystatus.mode = 0;
	Displaystatus.X = 0;
	Displaystatus.Y = 0;
	
    while(1)
    {
        checkInput();
    }
}

void drawDisplay()
{
	switch(Displaystatus.level){
		
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
	switchValue = 0;
	
	if(countBits(SWITCH) == 1){
				
		if(keyCounter == 0){
			pressedSwitch = SWITCH;
		}
		else{
			if((keyCounter == 5) || ((keyCounter % 10 == 0)&&(keyCounter > 29))){
				switchValue = pressedSwitch;
			}
		}
					
		keyCounter++;
	}
	else{
		if(keyCounter > 5){
			keyCounter = 0;
		}
	}	
}

void switchInit()
{
	SWITCH_D = 0x00;	
}

int countBits(byte Byte)
{
	int carryCount = 0;
	
	while(Byte > 0)
	{
		carryCount += Byte % 2;
		Byte /= 2;
	}
	
	return(carryCount);
}