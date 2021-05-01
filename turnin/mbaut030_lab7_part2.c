/* Author: Maverick Bautista
 * Lab Section: 023
 * Assignment: Lab 7  Exercise 2
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: https://youtu.be/TZFoOqrGjMc
 *  Previous Exercise 2: https://youtu.be/ltT5z-elXlY
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//Correction to video, max is when its just exposed to light, no flashlight or hand
//min w/hand
//max w/o hand
void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char tmpB = 0x00;
	unsigned char tmpD = 0x00;
	ADC_init();
    /* Insert your solution below */
    while (1) {
	unsigned short x = ADC;
	tmpB = (char)x;
	tmpD = (char)(x >> 8);

	PORTB = tmpB;
	PORTD = tmpD;
    }
    return 1;
}
