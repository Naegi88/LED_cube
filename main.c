#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

void led(char x, char y, char z);


int main(void)
{
		while(1)
		{
			led(1,1,1);
			led(2,1,2);
			led(3,2,3);
			led(4,1,4);
			led(5,1,5);
			led(1,1,5);
			led(2,1,4);
			led(4,1,2);
			led(5,1,1);
		}
	
	return 0;
}//end of main

void led(char x, char y, char z)
{	

	DDRA = 0x00;
	DDRB = 0x00; 
	DDRC = 0x00;
	DDRD = 0x00;
	
	
	switch(y)
	{
		case 1:	switch(x)
				{
					case 1:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD3);
											
										PORTA |= (1<<PD0);
										PORTD &= ~(1<<PD3);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD3);
											
										PORTA |= (1<<PD1);
										PORTD &= ~(1<<PD3);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD3);
											
										PORTA |= (1<<PD2);
										PORTD &= ~(1<<PD3);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD3);
											
										PORTA |= (1<<PD3);
										PORTD &= ~(1<<PD3);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD3);
											
										PORTA |= (1<<PD4);
										PORTD &= ~(1<<PD3);
									break;
							}
						break;
					
					case 2:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD4);
											
										PORTA |= (1<<PD0);
										PORTD &= ~(1<<PD4);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD4);
											
										PORTA |= (1<<PD1);
										PORTD &= ~(1<<PD4);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD4);
											
										PORTA |= (1<<PD2);
										PORTD &= ~(1<<PD4);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD4);
											
										PORTA |= (1<<PD3);
										PORTD &= ~(1<<PD4);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD4);
											
										PORTA |= (1<<PD4);
										PORTD &= ~(1<<PD4);
									break;
							}
						break;
					
					case 3:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD5);
											
										PORTA |= (1<<PD0);
										PORTD &= ~(1<<PD5);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD5);
											
										PORTA |= (1<<PD1);
										PORTD &= ~(1<<PD5);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD5);
											
										PORTA |= (1<<PD2);
										PORTD &= ~(1<<PD5);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD5);
											
										PORTA |= (1<<PD3);
										PORTD &= ~(1<<PD5);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD5);
											
										PORTA |= (1<<PD4);
										PORTD &= ~(1<<PD5);
									break;
							}
						break;
					
					case 4:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD6);
											
										PORTA |= (1<<PD0);
										PORTD &= ~(1<<PD6);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD6);
											
										PORTA |= (1<<PD1);
										PORTD &= ~(1<<PD6);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD6);
											
										PORTA |= (1<<PD2);
										PORTD &= ~(1<<PD6);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD6);
											
										PORTA |= (1<<PD3);
										PORTD &= ~(1<<PD6);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD6);
											
										PORTA |= (1<<PD4);
										PORTD &= ~(1<<PD6);
									break;
							}
						break;
					
					case 5:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD7);
											
										PORTA |= (1<<PD0);
										PORTD &= ~(1<<PD7);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD7);
											
										PORTA |= (1<<PD1);
										PORTD &= ~(1<<PD7);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD7);
											
										PORTA |= (1<<PD2);
										PORTD &= ~(1<<PD7);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD7);
											
										PORTA |= (1<<PD3);
										PORTD &= ~(1<<PD7);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD7);
											
										PORTA |= (1<<PD4);
										PORTD &= ~(1<<PD7);
									break;
							}
						break;
				}
			break;
		
		case 2:	switch(x)
				{
					case 1:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD3);
											
										PORTA &= ~(1<<PD0);
										PORTD |= (1<<PD3);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD3);
											
										PORTA &= ~(1<<PD1);
										PORTD |= (1<<PD3);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD3);
											
										PORTA &= ~(1<<PD2);
										PORTD |= (1<<PD3);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD3);
											
										PORTA &= ~(1<<PD3);
										PORTD |= (1<<PD3);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD3);
											
										PORTA &= ~(1<<PD4);
										PORTD |= (1<<PD3);
									break;
							}
						break;
					
					case 2:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD4);
											
										PORTA &= ~(1<<PD0);
										PORTD |= (1<<PD4);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD4);
											
										PORTA &= ~(1<<PD1);
										PORTD |= (1<<PD4);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD4);
											
										PORTA &= ~(1<<PD2);
										PORTD |= (1<<PD4);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD4);
											
										PORTA &= ~(1<<PD3);
										PORTD |= (1<<PD4);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD4);
											
										PORTA &= ~(1<<PD4);
										PORTD |= (1<<PD4);
									break;
							}
						break;
					
					case 3:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD5);
											
										PORTA &= ~(1<<PD0);
										PORTD |= (1<<PD5);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD5);
											
										PORTA &= ~(1<<PD1);
										PORTD |= (1<<PD5);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD5);
											
										PORTA &= ~(1<<PD2);
										PORTD |= (1<<PD5);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD5);
											
										PORTA &= ~(1<<PD3);
										PORTD |= (1<<PD5);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD5);
											
										PORTA &= ~(1<<PD4);
										PORTD |= (1<<PD5);
									break;
							}
						break;
					
					case 4:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD6);
											
										PORTA &= ~(1<<PD0);
										PORTD |= (1<<PD6);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD6);
											
										PORTA &= ~(1<<PD1);
										PORTD |= (1<<PD6);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD6);
											
										PORTA &= ~(1<<PD2);
										PORTD |= (1<<PD6);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD6);
											
										PORTA &= ~(1<<PD3);
										PORTD |= (1<<PD6);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD6);
											
										PORTA &= ~(1<<PD4);
										PORTD |= (1<<PD6);
									break;
							}
						break;
					
					case 5:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD7);
											
										PORTA &= ~(1<<PD0);
										PORTD |= (1<<PD7);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRD |= (1<<PD7);
											
										PORTA &= ~(1<<PD1);
										PORTD |= (1<<PD7);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRD |= (1<<PD7);
											
										PORTA &= ~(1<<PD2);
										PORTD |= (1<<PD7);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRD |= (1<<PD7);
											
										PORTA &= ~(1<<PD3);
										PORTD |= (1<<PD7);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRD |= (1<<PD7);
											
										PORTA &= ~(1<<PD4);
										PORTD |= (1<<PD7);
									break;
							}
						break;
				}
			break;
		
		case 3:	switch(x)
				{
					case 1:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
							}
						break;
					
					case 2:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
							}
						break;
					
					case 3:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
							}
						break;
					
					case 4:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
							}
						break;
					
					case 5:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD0);
									break;
							}
						break;
				}
			break;
		
		case 4:	switch(x)
				{
					case 1:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD3);
											
										PORTA &= ~(1<<PD0);
										PORTC |= (1<<PD3);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD3);
											
										PORTA &= ~(1<<PD1);
										PORTC |= (1<<PD3);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD3);
											
										PORTA &= ~(1<<PD2);
										PORTC |= (1<<PD3);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD3);
											
										PORTA &= ~(1<<PD3);
										PORTC |= (1<<PD3);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD3);
											
										PORTA &= ~(1<<PD4);
										PORTC |= (1<<PD3);
									break;
							}
						break;
					
					case 2:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD4);
											
										PORTA &= ~(1<<PD0);
										PORTC |= (1<<PD4);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD4);
											
										PORTA &= ~(1<<PD1);
										PORTC |= (1<<PD4);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD4);
											
										PORTA &= ~(1<<PD2);
										PORTC |= (1<<PD4);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD4);
											
										PORTA &= ~(1<<PD3);
										PORTC |= (1<<PD4);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD4);
											
										PORTA &= ~(1<<PD4);
										PORTC |= (1<<PD4);
									break;
							}
						break;
					
					case 3:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD5);
											
										PORTA &= ~(1<<PD0);
										PORTC |= (1<<PD5);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD5);
											
										PORTA &= ~(1<<PD1);
										PORTC |= (1<<PD5);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD5);
											
										PORTA &= ~(1<<PD2);
										PORTC |= (1<<PD5);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD5);
											
										PORTA &= ~(1<<PD3);
										PORTC |= (1<<PD5);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD5);
											
										PORTA &= ~(1<<PD4);
										PORTC |= (1<<PD5);
									break;
							}
						break;
					
					case 4:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD6);
											
										PORTA &= ~(1<<PD0);
										PORTC |= (1<<PD6);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD6);
											
										PORTA &= ~(1<<PD1);
										PORTC |= (1<<PD6);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD6);
											
										PORTA &= ~(1<<PD2);
										PORTC |= (1<<PD6);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD6);
											
										PORTA &= ~(1<<PD3);
										PORTC |= (1<<PD6);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD6);
											
										PORTA &= ~(1<<PD4);
										PORTC |= (1<<PD6);
									break;
							}
						break;
					
					case 5:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD7);
											
										PORTA &= ~(1<<PD0);
										PORTC |= (1<<PD7);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD7);
											
										PORTA &= ~(1<<PD1);
										PORTC |= (1<<PD7);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD7);
											
										PORTA &= ~(1<<PD2);
										PORTC |= (1<<PD7);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD7);
											
										PORTA &= ~(1<<PD3);
										PORTC |= (1<<PD7);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD7);
											
										PORTA &= ~(1<<PD4);
										PORTC |= (1<<PD7);
									break;
							}
						break;
				}
			break;
		
		case 5:	
			break;
	}
}