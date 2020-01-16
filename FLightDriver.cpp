/*
 * PRJ1-IKT5
 *
 * Created: 08/11/2019 11.18.27
 * Author : Marius Hambro Bovbjerg & Magnus Gj�ttrup
 */ 

#include "FLightDriver.h"

#include <stdio.h>
#include <avr/io.h>

void fLightInit(void){
	DDRG = 0xFF; 
}

void fLightOn(void){
	PORTG = 0b00000101; //ben 39 og 41
}
void fLightOff(void){
	PORTG = 0b00000000;
}