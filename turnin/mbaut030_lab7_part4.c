/* Author: Maverick Bautista
 * Lab Section: 023
 * Assignment: Lab 7  Exercise 4
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: https://youtu.be/Pp09E5pYilg
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//min w/hand is 51
//max w/o hand is 113, in a previous video, max was 113, having 95 is troublesome when min
//is 51, so I will link a previous video of exercise 2 I did as reference.
void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

//Calculations
//(113-51)/8 = 7.75

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	unsigned short MAX = 0x64; //0x5F is 95 in decimal was from exercise 2 demo
				   //0x64 is 113 in decimal and was from a previous recording
	ADC_init();
    /* Insert your solution below */
    while (1) {
	unsigned short x = ADC;
	if(x >= 0x33) { //33
		PORTB = 0x01;
	}
	if(x > 0x3B) {
		PORTB = 0x03;
	}
	if(x > 0x43) {
                PORTB = 0x07;
        }
	if(x > 0x4B) {
                PORTB = 0x0F;
        }
	if(x > 0x53) {
                PORTB = 0x1F;
        }
	if(x > 0x5B) {
                PORTB = 0x3F;
        }
	if(x > 0x63) {
                PORTB = 0x7F;
        }
	if(x >= 0x6B) {
                PORTB = 0xFF;
        }

    }
    return 1;
}
