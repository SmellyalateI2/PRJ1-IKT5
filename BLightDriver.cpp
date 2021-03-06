/*
 * PRJ1-IKT5
 *
 * Created: 08/11/2019 11.18.27
 * Author : Marius Hambro Bovbjerg & Magnus Gj�ttrup
 */ 

#include "BLightDriver.h"
#include <stdio.h>
#include <avr/io.h>

void bLightInit(void){
	DDRC = 0xFF;
	TCCR3A = (0<<COM3A1)|(1<<COM3A0)|(0<<WGM31)|(1<<WGM30); // Set compare mode for OCR1A
	TCCR3B = (0<<WGM33)|(0<<WGM32)|(1<<CS32)|(0<<CS31)|(0<<CS30); // Set Mode 1, PWM Phase correct 8-bit & 256 prescaler
	TIMSK3 = 0b00000010;
	OCR3A = 0;
}

void bLightToggle(void){
	
	PINC |= 0b00000101; // ben 35 og 37
	
}

void bLightStrength(int Brightness){

	int dutyCycle = 0;
	
	if (Brightness > 254) {
		dutyCycle = 254;
	}
	else if (Brightness <= 0) {
		dutyCycle = 1;
	}
	else {
		dutyCycle = Brightness;
	}

	OCR3A = dutyCycle;
}