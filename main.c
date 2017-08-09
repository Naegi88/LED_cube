#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>





int main(void)
{

	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	PORTA = 0xFF;
	PORTB = 0xFF;
	PORTC = 0xFF;
	PORTD = 0xFF;
	
		while(1)
		{
			PORTD &= ~(1<<PD3);
		}
	
	return 0;
}//end of main