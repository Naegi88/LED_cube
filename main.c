#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>


void led(char x, char y, char z);
void acer(char a);
void all(char e);
void linez(char y, char x);
void linex(char y, char x);
void liney(char z, char x);
void rundlauf(long w);
void lift(long y);
void cube(char s)
{
	long op = 0;
	long x;
	
	switch(s)
	{
		case 1:	x = 20000;
			break;
			
		case 2:	x = 4500;
			break;
			
		case 3:	x = 2000;
			break;
			
		case 4:	x = 1100;
			break;
			
		case 5:	x = 700;
			break;
			
			
	}
	
	for(op = -40000; op < x; op++)
		{
			led(5,3,3);
		}
		
	for(op = -5000; op < x; op++)
		{
			led(5,3,3);
			led(4,2,3);
			led(4,4,3);
			led(4,3,4);
			led(4,3,2);
			led(4,3,3);
		}
		
	for(op = -500; op < x; op++)
		{
			led(5,3,3);
			
			led(4,2,3);
			led(4,4,3);
			led(4,3,4);
			led(4,3,2);
			led(4,3,3);
			
			led(3,1,3);
			led(3,2,3);
			led(3,3,3);
			led(3,4,3);
			led(3,5,3);
			led(3,3,1);
			led(3,3,2);
			led(3,3,4);
			led(3,3,5);
			led(3,2,4);
			led(3,2,2);
			led(3,4,4);
			led(3,4,2);
		}
		
	for(op = -400; op < x; op++)
		{
			led(5,3,3);
			
			led(4,2,3);
			led(4,4,3);
			led(4,3,4);
			led(4,3,2);
			led(4,3,3);
			
			led(3,1,3);
			led(3,2,3);
			led(3,3,3);
			led(3,4,3);
			led(3,5,3);
			led(3,3,1);
			led(3,3,2);
			led(3,3,4);
			led(3,3,5);
			led(3,2,4);
			led(3,2,2);
			led(3,4,4);
			led(3,4,2);
			
			led(2,2,3);
			led(2,4,3);
			led(2,3,4);
			led(2,3,2);
			led(2,3,3);
		}
		
			for(op = 0; op < x; op++)
		{
			led(5,3,3);
			
			led(4,2,3);
			led(4,4,3);
			led(4,3,4);
			led(4,3,2);
			led(4,3,3);
			
			led(3,1,3);
			led(3,2,3);
			led(3,3,3);
			led(3,4,3);
			led(3,5,3);
			led(3,3,1);
			led(3,3,2);
			led(3,3,4);
			led(3,3,5);
			led(3,2,4);
			led(3,2,2);
			led(3,4,4);
			led(3,4,2);
			
			led(2,2,3);
			led(2,4,3);
			led(2,3,4);
			led(2,3,2);
			led(2,3,3);
			
			led(1,3,3);
		}
	

}



int main(void)
{
		while(1)
		{
			cube(5);
		}
	
	return 0;
}//end of main

void led(char y, char x, char z)
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
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD0);
										PORTC &= ~(1<<PD7);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD1);
										PORTC &= ~(1<<PD7);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD2);
										PORTC &= ~(1<<PD7);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD7);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD7);
											
										PORTA |= (1<<PD4);
										PORTC &= ~(1<<PD7);
									break;
							}
						break;
					
					case 2:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD0);
										PORTC &= ~(1<<PD6);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD1);
										PORTC &= ~(1<<PD6);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD2);
										PORTC &= ~(1<<PD6);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD6);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD6);
											
										PORTA |= (1<<PD4);
										PORTC &= ~(1<<PD6);
									break;
							}
						break;
					
					case 3:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD0);
										PORTC &= ~(1<<PD3);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD1);
										PORTC &= ~(1<<PD3);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD2);
										PORTC &= ~(1<<PD3);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD3);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD3);
											
										PORTA |= (1<<PD4);
										PORTC &= ~(1<<PD3);
									break;
							}
						break;
					
					case 4:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD0);
										PORTC &= ~(1<<PD4);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD1);
										PORTC &= ~(1<<PD4);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD2);
										PORTC &= ~(1<<PD4);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD4);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD4);
											
										PORTA |= (1<<PD4);
										PORTC &= ~(1<<PD4);
									break;
							}
						break;
					
					case 5:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD0);
										PORTC &= ~(1<<PD5);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD1);
										PORTC &= ~(1<<PD5);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD2);
										PORTC &= ~(1<<PD5);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD3);
										PORTC &= ~(1<<PD5);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRC |= (1<<PD5);
											
										PORTA |= (1<<PD4);
										PORTC &= ~(1<<PD5);
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
					
					case 2:	switch(z)
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
					
					case 3:	switch(z)
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
					
					case 4:	switch(z)
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
					
					case 5:	switch(z)
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
				}
			break;
		
		case 5:	switch(x)
				{	
				case 1:	switch(z)	
							{
								case 1:	DDRA |= (1<<PD0);
										DDRB |= (1<<PD4);
											
										PORTA |= (1<<PD0);
										PORTB &= ~(1<<PD4);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRB |= (1<<PD4);
											
										PORTA |= (1<<PD1);
										PORTB &= ~(1<<PD4);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRB |= (1<<PD4);
											
										PORTA |= (1<<PD2);
										PORTB &= ~(1<<PD4);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRB |= (1<<PD4);
											
										PORTA |= (1<<PD3);
										PORTB &= ~(1<<PD4);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRB |= (1<<PD4);
											
										PORTA |= (1<<PD4);
										PORTB &= ~(1<<PD4);
									break;
							}
						break;
					
					case 2:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRB |= (1<<PD3);
											
										PORTA |= (1<<PD0);
										PORTB &= ~(1<<PD3);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRB |= (1<<PD3);
											
										PORTA |= (1<<PD1);
										PORTB &= ~(1<<PD3);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRB |= (1<<PD3);
											
										PORTA |= (1<<PD2);
										PORTB &= ~(1<<PD3);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRB |= (1<<PD3);
											
										PORTA |= (1<<PD3);
										PORTB &= ~(1<<PD3);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRB |= (1<<PD3);
											
										PORTA |= (1<<PD4);
										PORTB &= ~(1<<PD3);
									break;
							}
						break;
					
					case 3:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRB |= (1<<PD2);
											
										PORTA |= (1<<PD0);
										PORTB &= ~(1<<PD2);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRB |= (1<<PD2);
											
										PORTA |= (1<<PD1);
										PORTB &= ~(1<<PD2);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRB |= (1<<PD2);
											
										PORTA |= (1<<PD2);
										PORTB &= ~(1<<PD2);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRB |= (1<<PD2);
											
										PORTA |= (1<<PD3);
										PORTB &= ~(1<<PD2);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRB |= (1<<PD2);
											
										PORTA |= (1<<PD4);
										PORTB &= ~(1<<PD2);
									break;
							}
						break;
					
					case 4:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRB |= (1<<PD1);
											
										PORTA |= (1<<PD0);
										PORTB &= ~(1<<PD1);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRB |= (1<<PD1);
											
										PORTA |= (1<<PD1);
										PORTB &= ~(1<<PD1);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRB |= (1<<PD1);
											
										PORTA |= (1<<PD2);
										PORTB &= ~(1<<PD1);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRB |= (1<<PD1);
											
										PORTA |= (1<<PD3);
										PORTB &= ~(1<<PD1);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRB |= (1<<PD1);
											
										PORTA |= (1<<PD4);
										PORTB &= ~(1<<PD1);
									break;
							}
						break;
					
					case 5:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRB |= (1<<PD0);
											
										PORTA |= (1<<PD0);
										PORTB &= ~(1<<PD0);
									break;
								
								case 2:	DDRA |= (1<<PD1);
										DDRB |= (1<<PD0);
											
										PORTA |= (1<<PD1);
										PORTB &= ~(1<<PD0);
									break;
								
								case 3:	DDRA |= (1<<PD2);
										DDRB |= (1<<PD0);
											
										PORTA |= (1<<PD2);
										PORTB &= ~(1<<PD0);
									break;
								
								case 4:	DDRA |= (1<<PD3);
										DDRB |= (1<<PD0);
											
										PORTA |= (1<<PD3);
										PORTB &= ~(1<<PD0);
									break;
								
								case 5:	DDRA |= (1<<PD4);
										DDRB |= (1<<PD0);
											
										PORTA |= (1<<PD4);
										PORTB &= ~(1<<PD0);
									break;
							}
						break;
				}
			break;
	}
}
void acer(char a)
{

	DDRA = 0x00;
	DDRB = 0x00; 
	DDRC = 0x00;
	DDRD = 0x00;
	
	switch(a)
	{
		case 1:	DDRA = 0xFF;
				DDRD = 0xFF;
				
				PORTA = 0xFF;
				PORTD = 0x00;
			break;
			
		case 2:	DDRA = 0xFF;
				DDRD = 0xFF;
				
				PORTA = 0x00;
				PORTD = 0xFF;
			break;
			
		case 3:	DDRA = 0xFF;
				DDRC = 0xFF;
				
				PORTA = 0xFF;
				PORTC = 0x00;
			break;
			
		case 4:	DDRA = 0xFF;
				DDRC = 0xFF;
				
				PORTA = 0x00;
				PORTC = 0xFF;
			break;
			
		case 5: DDRA = 0xFF;
				DDRB = 0xFF;
				
				PORTA = 0xFF;
				PORTB = 0x00;
			break;
	}		
	
}



void all(char e)
{

	DDRA = 0x00;
	DDRB = 0x00; 
	DDRC = 0x00;
	DDRD = 0x00;
	
	switch(e)
	{
		case 1:	acer(1);
				acer(2);
				acer(3);
				acer(4);
				acer(5);
			break;
	}
}

void linez(char y, char x)
{	
	switch(y)
	{
		case 1:	switch(x)
				{
					case 1:	led(1,1,1);
							led(1,1,2);
							led(1,1,3);
							led(1,1,4);
							led(1,1,5);
							
						break;
					
					case 2:	led(1,2,1);
							led(1,2,2);
							led(1,2,3);
							led(1,2,4);
							led(1,2,5);
						break;
					
					case 3:	led(1,3,1);
							led(1,3,2);
							led(1,3,3);
							led(1,3,4);
							led(1,3,5);
						break;
					
					case 4:	led(1,4,1);
							led(1,4,2);
							led(1,4,3);
							led(1,4,4);
							led(1,4,5);
						break;
					
					case 5:	led(1,5,1);
							led(1,5,2);
							led(1,5,3);
							led(1,5,4);
							led(1,5,5);
						break;
						
				}
				
			break;
		
		case 2:	switch(x)
				{
					case 1:	led(2,1,1);
							led(2,1,2);
							led(2,1,3);
							led(2,1,4);
							led(2,1,5);
						break;
					
					case 2:	led(2,2,1);
							led(2,2,2);
							led(2,2,3);
							led(2,2,4);
							led(2,2,5);
						break;
					
					case 3:	led(2,3,1);
							led(2,3,2);
							led(2,3,3);
							led(2,3,4);
							led(2,3,5);
						break;
					
					case 4:	led(2,4,1);
							led(2,4,2);
							led(2,4,3);
							led(2,4,4);
							led(2,4,5);
						break;
					
					case 5:	led(2,5,1);
							led(2,5,2);
							led(2,5,3);
							led(2,5,4);
							led(2,5,5);
						break;
						
				}
				
			break;
		
		case 3:	switch(x)
				{
					case 1:	led(3,1,1);
							led(3,1,2);
							led(3,1,3);
							led(3,1,4);
							led(3,1,5);
						break;
					
					case 2:	led(3,2,1);
							led(3,2,2);
							led(3,2,3);
							led(3,2,4);
							led(3,2,5);
						break;
					
					case 3:	led(3,3,1);
							led(3,3,2);
							led(3,3,3);
							led(3,3,4);
							led(3,3,5);
						break;
					
					case 4:	led(3,4,1);
							led(3,4,2);
							led(3,4,3);
							led(3,4,4);
							led(3,4,5);
						break;
					
					case 5:	led(3,5,1);
							led(3,5,2);
							led(3,5,3);
							led(3,5,4);
							led(3,5,5);
						break;
						
				}
				
			break;
		
		case 4:	switch(x)
				{
					case 1:	led(4,1,1);
							led(4,1,2);
							led(4,1,3);
							led(4,1,4);
							led(4,1,5);
						break;
					
					case 2:	led(4,2,1);
							led(4,2,2);
							led(4,2,3);
							led(4,2,4);
							led(4,2,5);
						break;
					
					case 3:	led(4,3,1);
							led(4,3,2);
							led(4,3,3);
							led(4,3,4);
							led(4,3,5);
						break;
					
					case 4:	led(4,4,1);
							led(4,4,2);
							led(4,4,3);
							led(4,4,4);
							led(4,4,5);
						break;
					
					case 5:	led(4,5,1);
							led(4,5,2);
							led(4,5,3);
							led(4,5,4);
							led(4,5,5);
						break;
						
				}
				
			break;
		
		case 5:	switch(x)
				{
					case 1:	led(5,1,1);
							led(5,1,2);
							led(5,1,3);
							led(5,1,4);
							led(5,1,5);
						break;
					
					case 2:	led(5,2,1);
							led(5,2,2);
							led(5,2,3);
							led(5,2,4);
							led(5,2,5);
						break;
					
					case 3:	led(5,3,1);
							led(5,3,2);
							led(5,3,3);
							led(5,3,4);
							led(5,3,5);
						break;
					
					case 4:	led(5,4,1);
							led(5,4,2);
							led(5,4,3);
							led(5,4,4);
							led(5,4,5);
						break;
					
					case 5:	led(5,5,1);
							led(5,5,2);
							led(5,5,3);
							led(5,5,4);
							led(5,5,5);
						break;
						
				}
				
			break;
					
	}
}

void linex(char y, char x)
{	

	DDRA = 0x00;
	DDRB = 0x00; 
	DDRC = 0x00;
	DDRD = 0x00;
	
	switch(y)
	{
		case 1:	switch(x)
				{
					case 1:	DDRA = 0xFF;
							DDRD = 0xFF;
							
							PORTA = 0x01;
							PORTD = 0x00;
							
						break;
					
					case 2:	DDRA = 0xFF;
							DDRD = 0xFF;
							
							PORTA = 0x02;
							PORTD = 0x00;
							
						break;
					
					case 3:	DDRA = 0xFF;
							DDRD = 0xFF;
							
							PORTA = 0x04;
							PORTD = 0x00;
							
						break;
					
					case 4:	DDRA = 0xFF;
							DDRD = 0xFF;
							
							PORTA = 0x08;
							PORTD = 0x00;
							
						break;
					
					case 5:	DDRA = 0xFF;
							DDRD = 0xFF;
							
							PORTA = 0x10;
							PORTD = 0x00;
							
						break;
						
				}
				
			break;
		
		case 2:	switch(x)
				{
					case 1:	led(2,1,1);
							led(2,2,1);
							led(2,3,1);
							led(2,4,1);
							led(2,5,1);
							
						break;
					
					case 2:	led(2,1,2);
							led(2,2,2);
							led(2,3,2);
							led(2,4,2);
							led(2,5,2);
							
						break;
					
					case 3:	led(2,1,3);
							led(2,2,3);
							led(2,3,3);
							led(2,4,3);
							led(2,5,3);
							
						break;
					
					case 4:	led(2,1,4);
							led(2,2,4);
							led(2,3,4);
							led(2,4,4);
							led(2,5,4);
							
						break;
					
					case 5:	led(2,1,5);
							led(2,2,5);
							led(2,3,5);
							led(2,4,5);
							led(2,5,5);
							
						break;
						
				}
				
			break;
		
		case 3:	switch(x)
				{
					case 1:	DDRA = 0xFF;
							DDRC = 0xFF;
							
							PORTA = 0x01;
							PORTC = 0x00;
							
						break;
					
					case 2:	DDRA = 0xFF;
							DDRC = 0xFF;
							
							PORTA = 0x02;
							PORTC = 0x00;
							
						break;
					
					case 3:	DDRA = 0xFF;
							DDRC = 0xFF;
							
							PORTA = 0x04;
							PORTC = 0x00;
							
						break;
					
					case 4:	DDRA = 0xFF;
							DDRC = 0xFF;
							
							PORTA = 0x08;
							PORTC = 0x00;
							
						break;
					
					case 5:	DDRA = 0xFF;
							DDRC = 0xFF;
							
							PORTA = 0x10;
							PORTC = 0x00;
							
						break;
						
				}
				
			break;
		
		case 4:	switch(x)
				{
					case 1:	led(4,1,1);
							led(4,2,1);
							led(4,3,1);
							led(4,4,1);
							led(4,5,1);
						break;
					
					case 2:	led(4,1,2);
							led(4,2,2);
							led(4,3,2);
							led(4,4,2);
							led(4,5,2);
						break;
					
					case 3:	led(4,1,3);
							led(4,2,3);
							led(4,3,3);
							led(4,4,3);
							led(4,5,3);
						break;
					
					case 4:	led(4,1,4);
							led(4,2,4);
							led(4,3,4);
							led(4,4,4);
							led(4,5,4);
						break;
					
					case 5:	led(4,1,5);
							led(4,2,5);
							led(4,3,5);
							led(4,4,5);
							led(4,5,5);
						break;
						
				}
				
			break;
		
		case 5:	switch(x)
				{
					case 1:	DDRA = 0xFF;
							DDRB = 0xFF;
							
							PORTA = 0x01;
							PORTB = 0x00;
							
						break;
					
					case 2:	DDRA = 0xFF;
							DDRB = 0xFF;
							
							PORTA = 0x02;
							PORTB = 0x00;
							
						break;
					
					case 3:	DDRA = 0xFF;
							DDRB = 0xFF;
							
							PORTA = 0x04;
							PORTB = 0x00;
							
						break;
					
					case 4:	DDRA = 0xFF;
							DDRB = 0xFF;
							
							PORTA = 0x08;
							PORTB = 0x00;
							
						break;
					
					case 5:	DDRA = 0xFF;
							DDRB = 0xFF;
							
							PORTA = 0x10;
							PORTB = 0x00;
							
						break;
						
				}
				
			break;
					
	}
 }

void liney(char z, char x)
{	
	switch(z)
	{
		case 1:	switch(x)
				{
					case 1:	led(1,1,1);
							led(2,1,1);
							led(3,1,1);
							led(4,1,1);
							led(5,1,1);
							
						break;
					
					case 2:	led(1,2,1);
							led(2,2,1);
							led(3,2,1);
							led(4,2,1);
							led(5,2,1);
						break;
					
					case 3:	led(1,3,1);
							led(2,3,1);
							led(3,3,1);
							led(4,3,1);
							led(5,3,1);
						break;
					
					case 4:	led(1,4,1);
							led(2,4,1);
							led(3,4,1);
							led(4,4,1);
							led(5,4,1);
						break;
					
					case 5:	led(1,5,1);
							led(2,5,1);
							led(3,5,1);
							led(4,5,1);
							led(5,5,1);
						break;
						
				}
				
			break;
		
		case 2:	switch(x)
				{
					case 1:	led(1,1,2);
							led(2,1,2);
							led(3,1,2);
							led(4,1,2);
							led(5,1,2);
						break;
					
					case 2:	led(1,2,2);
							led(2,2,2);
							led(3,2,2);
							led(4,2,2);
							led(5,2,2);
						break;
					
					case 3:	led(1,3,2);
							led(2,3,2);
							led(3,3,2);
							led(4,3,2);
							led(5,3,2);
						break;
					
					case 4:	led(1,4,2);
							led(2,4,2);
							led(3,4,2);
							led(4,4,2);
							led(5,4,2);
						break;
					
					case 5:	led(1,5,2);
							led(2,5,2);
							led(3,5,2);
							led(4,5,2);
							led(5,5,2);
						break;
						
				}
				
			break;
		
		case 3:	switch(x)
				{
					case 1:	led(1,1,3);
							led(2,1,3);
							led(3,1,3);
							led(4,1,3);
							led(5,1,3);
						break;
					
					case 2:	led(1,2,3);
							led(2,2,3);
							led(3,2,3);
							led(4,2,3);
							led(5,2,3);
						break;
					
					case 3:	led(1,3,3);
							led(2,3,3);
							led(3,3,3);
							led(4,3,3);
							led(5,3,3);
						break;
					
					case 4:	led(1,4,3);
							led(2,4,3);
							led(3,4,3);
							led(4,4,3);
							led(5,4,3);
						break;
					
					case 5:	led(1,5,3);
							led(2,5,3);
							led(3,5,3);
							led(4,5,3);
							led(5,5,3);
						break;
						
				}
				
			break;
		
		case 4:	switch(x)
				{
					case 1:	led(1,1,4);
							led(2,1,4);
							led(3,1,4);
							led(4,1,4);
							led(5,1,4);
						break;
					
					case 2:	led(1,2,4);
							led(2,2,4);
							led(3,2,4);
							led(4,2,4);
							led(5,2,4);
						break;
					
					case 3:	led(1,3,4);
							led(2,3,4);
							led(3,3,4);
							led(4,3,4);
							led(5,3,4);
						break;
					
					case 4:	led(1,4,4);
							led(2,4,4);
							led(3,4,4);
							led(4,4,4);
							led(5,4,4);
						break;
					
					case 5:	led(1,5,4);
							led(2,5,4);
							led(3,5,4);
							led(4,5,4);
							led(5,5,4);
						break;
						
				}
				
			break;
		
		case 5:	switch(x)
				{
					case 1:	led(1,1,5);
							led(2,1,5);
							led(3,1,5);
							led(4,1,5);
							led(5,1,5);
						break;
					
					case 2:	led(1,2,5);
							led(2,2,5);
							led(3,2,5);
							led(4,2,5);
							led(5,2,5);
						break;
					
					case 3:	led(1,3,5);
							led(2,3,5);
							led(3,3,5);
							led(4,3,5);
							led(5,3,5);
						break;
					
					case 4:	led(1,4,5);
							led(2,4,5);
							led(3,4,5);
							led(4,4,5);
							led(5,4,5);
						break;
					
					case 5:	led(1,5,5);
							led(2,5,5);
							led(3,5,5);
							led(4,5,5);
							led(5,5,5);
						break;
					
				}
				
			break;
					
	}
}
void rundlauf(long w)
{
	long op = 0;
	long q;
	switch(w)
	{
		case 1:	q = 8000;
			break;
			
		case 2:	q = 4500;
			break;
			
		case 3:	q = 2000;
			break;
			
		case 4:	q = 1100;
			break;
			
		case 5:	q = 700;
			break;
			
			
	}
	
	for(op = 0; op < q; op++)
	{
		liney(1,1);
	}			
	
	for(op = 0; op < q; op++)
	{			
		liney(1,2);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(1,3);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(1,4);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(1,5);
	}			
	
	for(op = 0; op < q; op++)
	{			
		liney(2,5);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(3,5);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(4,5);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(5,5);
	}			
	
	for(op = 0; op < q; op++)
	{			
		liney(5,4);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(5,3);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(5,2);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(5,1);
	}			
	
	for(op = 0; op < q; op++)
	{			
		liney(4,1);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(3,1);
	}
	
	for(op = 0; op < q; op++)
	{
		liney(2,1);
	}
}
void lift(long y)
{
	long op = 0;
	long x;
	
	switch(y)
	{
		case 1:	x = 150000;
		
				for(op = 0; op < x; op++)
				{
					acer(1);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(2);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(3);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(4);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(5);
				}
			break;
		
		case 2:	x = 75000;
		
				for(op = 0; op < x; op++)
				{
					acer(1);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(2);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(3);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(4);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(5);
				}
			break;
		
		case 3:	x = 45000;
		
				for(op = 0; op < x; op++)
				{
					acer(1);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(2);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(3);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(4);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(5);
				}
			break;
		
		case 4:	x = 32000;
		
				for(op = 0; op < x; op++)
				{
					acer(1);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(2);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(3);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(4);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(5);
				}
			break;
		
		case 5:	x = 20000;
		
				for(op = 0; op < x; op++)
				{
					acer(1);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(2);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(3);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(4);
				}
	
				for(op = 0; op < x; op++)
				{
					acer(5);
				}
			break;
	}


	
}