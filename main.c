#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void led(char x, char y, char z);			//LED einzeln anzünden
void acer(char a);							//ganze flachebe leuchten
void all(char e);							//Alle leuchten
void linez(char y, char x);					//Linie in der z achse leuchtet
void linex(char y, char x);					//Linie in der x achse leuchtet
void liney(char z, char x);					//Linie in der y achse leuchtet
void rundlauf(long w);						//rundlauf der y achse ausen
void lift(long y);							//fläch erheben
void cube(char s);							//würffel im würffel
void return1(char z);						//fläche zurück zihen
void downstep(char z);						//Y türmen
void abbau(char z);							//Y abbauen 
void spring(void);				

#ifndef F_CPU
#define F_CPU    20000000
#endif		
			

#define IRQS_PER_SECOND    1000						// Fuer optimale Genauigkeit muss
													// IRQS_PER_SECOND ein Teiler von F_CPU sein
													// und IRQS_PER_SECOND ein Vielfaches von 100.
													// Ausserdem muss gelten F_CPU / IRQS_PER_SECOND <= 65536
													// 500 µs //

#define IRQS_PER_10MS     (IRQS_PER_SECOND / 1000)	// Anzahl IRQs pro 10 Millisekunden

// Gültigkeitsprüfung.
// Bei ungeeigneten Werten gibt es einen Compilerfehler
#if (F_CPU/IRQS_PER_SECOND > 65536) || (IRQS_PER_10MS < 1) || (IRQS_PER_10MS > 255)
#   error Diese Werte fuer F_CPU und IRQS_PER_SECOND
#   error sind ausserhalb des gueltigen Bereichs!
#endif

uint8_t ms, ms10, ms100, sec ;
char t;

ISR(TIMER1_COMPA_vect)
{
  static uint8_t interrupt_num_10ms;				// zaehlvariable deklarieren
      
    if (++interrupt_num_10ms == IRQS_PER_10MS)    	// interrupt_num_10ms erhöhen und mit Maximalwert vergleichen
    {
        interrupt_num_10ms = 0;						// interrupt_num_10ms zurücksetzen
		ms++;										// jede millisekund
		
    }
	
	if(ms==10)										// Alle 10ms
	{
		ms = 0;
		ms10++;
	}
	
	if(ms10==10)									//Alle 100ms
	{
		ms10 = 0;
		ms100++;
		t++;

	}
	
	
	if(ms100==10)									//Alle sec
	{
		ms100 = 0;
		sec++;
		
	}
	
	if(sec==100)									//Alle 100sec
	{
		
	}
	
}//End of ISR


int main(void)
{

	ms = 0;
	ms10 = 0;
	ms100 = 0;				//deklarieren
	sec = 0;
	t = 0;
		
TCCR1A = 0;					// Timer1: keine PWM

    // Timer1 ist Zähler: Clear Timer on Compare Match (CTC, Mode #4)
    // Timer1 läuft mit vollem MCU-Takt: Prescale = 1
#if defined (CTC1) && !defined (WGM12)
   TCCR1B = (1 << CTC1)  | (1 << CS10);
#elif !defined (CTC1) && defined (WGM12)
   TCCR1B = (1 << WGM12) | (1 << CS10);
#else
#error Keine Ahnung!
#endif

    // OutputCompare für gewünschte Timer1 Frequenz
    // TCNT1 zählt immer 0...OCR1A, 0...OCR1A, ... 
    // Beim überlauf OCR1A -> OCR1A+1 wird TCNT1=0 gesetzt und im nächsten
    // MCU-Takt eine IRQ erzeugt.
    OCR1A = (unsigned short) ((unsigned long) F_CPU / IRQS_PER_SECOND-1);

    // OutputCompareA-Interrupt für Timer1 aktivieren
#if defined (TIMSK1)
    TIMSK1 |= (1 << OCIE1A);
#elif defined (TIMSK)
    TIMSK  |= (1 << OCIE1A);
#else
#error Keine Ahnung!
#endif
	sei();
	
	while(1)
	{
		char u = 0;
			
			lift(3);
			return1(1);	
			downstep(1);
			
			
		for(u = 0; u < 3; u++)
			{
				rundlauf(2);
			}
			
			abbau(1);		
			t = 0;
			spring();
			cube(2);
			
	}//end of while
	return 0;
}//end of main

void led(char y, char x, char z)
{	

	DDRA = 0x00;
	DDRB = 0x00; 
	DDRC = 0x00;
	DDRD = 0x00;			//Alle auf eingang

	switch(y)
{
		case 1:	switch(x)
				{
					case 1:	switch(z)
							{
								case 1:	DDRA |= (1<<PD0);
										DDRD |= (1<<PD3);		//diese pins auf ausgang setzten
											
										PORTA |= (1<<PD0);		//dieser PIN auf VCC
										PORTD &= ~(1<<PD3);	//dieser PIN auf ground
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
	DDRD = 0x00;			//Alle auf eingangsetzten
	
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
		
	for(op = -400; op < x; op++)
		{
			
			
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
	for(op = -500; op < x; op++)
		{
			
			
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
		
	for(op = -5000; op < x; op++)
		{
			
			led(2,2,3);
			led(2,4,3);
			led(2,3,4);
			led(2,3,2);
			led(2,3,3);
			
			led(1,3,3);
		}
		
	for(op = -40000; op < x; op++)
		{
			led(1,3,3);
		}

}
void return1(char z)
{	
	long op = 0;
	long x = 30000;
	
	
	
	for(op = -70000; op < x; op++)
		{
			acer(5);
		}
		
	for(op = 27000; op < x; op++)
		{
			led(5,1,1);
			led(5,1,2);
			led(5,1,3);
			led(5,1,4);
			led(5,2,1);
			led(5,2,2);
			led(5,2,3);
			led(5,2,4);
			led(5,3,1);
			led(5,3,2);
			led(5,3,3);
			led(5,3,4);
			led(5,4,1);
			led(5,4,2);
			led(5,4,3);
			led(5,4,4);
		}
		
	for(op = 25000; op < x; op++)
		{
			led(5,1,1);
			led(5,1,2);
			led(5,1,3);
			led(5,2,1);
			led(5,2,2);
			led(5,2,3);
			led(5,3,1);
			led(5,3,2);
			led(5,3,3);
	
		
			
			
		}
		
	for(op = 11000; op < x; op++)
		{
			led(5,1,1);
			led(5,1,2);
			led(5,2,1);
			led(5,2,2);
		}
		
	for(op = -70000; op < x; op++)
		{
			led(5,1,1);
		}

}
void downstep(char z)
{
	long op = 0;
	long x = 16000;
	
	for(op = 0; op < x; op++)
		{
			led(5,1,1);
		}
		
	for(op = 0; op < x; op++)
		{
			led(5,1,1);
			led(4,1,1);
		}
	
	for(op = 0; op < x; op++)
		{
			led(5,1,1);
			led(4,1,1);
			led(3,1,1);
		}
		
	for(op = 0; op < x; op++)
		{
			led(5,1,1);
			led(4,1,1);
			led(3,1,1);
			led(2,1,1);
		}
		
	for(op = 0; op < x; op++)
		{
			liney(1,1);
		}
}
void abbau(char z)
{
	long op = 0;
	long x = 16000;
	
	for(op = 0; op < x; op++)
		{
			liney(1,1);
		}
		
	for(op = 0; op < x; op++)
		{
			led(4,1,1);
			led(3,1,1);
			led(2,1,1);
			led(1,1,1);
		}
	
	for(op = 0; op < x; op++)
		{
			led(3,1,1);
			led(2,1,1);
			led(1,1,1);
		}
		
	for(op = 0; op < x; op++)
		{
			led(2,1,1);
			led(1,1,1);
		}
		
	for(op = -20000; op < x; op++)
		{
			led(1,1,1);
		}
}
void spring(void)
{
	int x = 1;

	{while(t<x)		//Fläche 1
	{
		led(1,1,1);
	}
	x++;
	
	while(t<x)
	{
		led(1,2,1);
	}
	x++;
	
	while(t<x)
	{
		led(1,3,1);
	}
	x++;
	
	while(t<x)
	{
		led(1,4,1);
	}
	x++;
	
	while(t<x)
	{
		led(1,5,1);
	}
	x++;
	
	while(t<x)
	{
		led(1,5,2);
	}
	x++;
	
	while(t<x)
	{
		led(1,5,3);
	}
	x++;
	
	while(t<x)
	{
		led(1,5,4);
	}
	x++;
	
	while(t<x)
	{
		led(1,5,5);
	}
	x++;
	
	while(t<x)
	{
		led(1,4,5);
	}
	x++;
	
	while(t<x)
	{
		led(1,3,5);
	}
	x++;
	
	while(t<x)
	{
		led(1,2,5);
	}
	x++;
	
	while(t<x)
	{
		led(1,1,5);
	}
	x++;
	
	while(t<x)
	{
		led(1,1,4);
	}
	x++;
	
	while(t<x)
	{
		led(1,1,3);
	}
	x++;
	
	while(t<x)
	{
		led(1,1,2);
	}
	x++;
	}
	
	
	
	{while(t<x)		//Fläche 2
	{
		led(2,1,1);
	}
	x++;
	
	while(t<x)
	{
		led(2,2,1);
	}
	x++;
	
	while(t<x)
	{
		led(2,3,1);
	}
	x++;
	
	while(t<x)
	{
		led(2,4,1);
	}
	x++;
	
	while(t<x)
	{
		led(2,5,1);
	}
	x++;
	
	while(t<x)
	{
		led(2,5,2);
	}
	x++;
	
	while(t<x)
	{
		led(2,5,3);
	}
	x++;
	
	while(t<x)
	{
		led(2,5,4);
	}
	x++;
	
	while(t<x)
	{
		led(2,5,5);
	}
	x++;
	
	while(t<x)
	{
		led(2,4,5);
	}
	x++;
	
	while(t<x)
	{
		led(2,3,5);
	}
	x++;
	
	while(t<x)
	{
		led(2,2,5);
	}
	x++;
	
	while(t<x)
	{
		led(2,1,5);
	}
	x++;
	
	while(t<x)
	{
		led(2,1,4);
	}
	x++;
	
	while(t<x)
	{
		led(2,1,3);
	}
	x++;
	
	while(t<x)
	{
		led(2,1,2);
	}
	x++;
	}
			
				
	{while(t<x)		//Fläche 3
	{
		led(3,1,1);
	}
	x++;
	
	while(t<x)
	{
		led(3,2,1);
	}
	x++;
	
	while(t<x)
	{
		led(3,3,1);
	}
	x++;
	
	while(t<x)
	{
		led(3,4,1);
	}
	x++;
	
	while(t<x)
	{
		led(3,5,1);
	}
	x++;
	
	while(t<x)
	{
		led(3,5,2);
	}
	x++;
	
	while(t<x)
	{
		led(3,5,3);
	}
	x++;
	
	while(t<x)
	{
		led(3,5,4);
	}
	x++;
	
	while(t<x)
	{
		led(3,5,5);
	}
	x++;
	
	while(t<x)
	{
		led(3,4,5);
	}
	x++;
	
	while(t<x)
	{
		led(3,3,5);
	}
	x++;
	
	while(t<x)
	{
		led(3,2,5);
	}
	x++;
	
	while(t<x)
	{
		led(3,1,5);
	}
	x++;
	
	while(t<x)
	{
		led(3,1,4);
	}x++;
	
	while(t<x)
	{
		led(3,1,3);
	}
	x++;
	
	while(t<x)
	{
		led(3,1,2);
	}
	x++;
	}

	{while(t<x)		//Fläche 4
	{
		led(4,1,1);
	}
	x++;
	
	while(t<x)
	{
		led(4,2,1);
	}
	x++;
	
	while(t<x)
	{
		led(4,3,1);
	}
	x++;
	
	while(t<x)
	{
		led(4,4,1);
	}
	x++;
	
	while(t<x)
	{
		led(4,5,1);
	}
	x++;
	
	while(t<x)
	{
		led(4,5,2);
	}
	x++;
	
	while(t<x)
	{
		led(4,5,3);
	}
	x++;
	
	while(t<x)
	{
		led(4,5,4);
	}
	x++;
	
	while(t<x)
	{
		led(4,5,5);
	}
	x++;
	
	while(t<x)
	{
		led(4,4,5);
	}
	x++;
	
	while(t<x)
	{
		led(4,3,5);
	}
	x++;
	
	while(t<x)
	{
		led(4,2,5);
	}
	x++;
	
	while(t<x)
	{
		led(4,1,5);
	}
	x++;
	
	while(t<x)
	{
		led(4,1,4);
	}
	x++;
	
	while(t<x)
	{
		led(4,1,3);
	}
	x++;
	
	while(t<x)
	{
		led(4,1,2);
	}
	x++;
	}

	{while(t<x)		//Fläche 5
	{
		led(5,1,1);
	}
	x++;
	
	while(t<x)
	{
		led(5,2,1);
	}
	x++;
	
	while(t<x)
	{
		led(5,3,1);
	}
	x++;
	
	while(t<x)
	{
		led(5,4,1);
	}
	x++;
	
	while(t<x)
	{
		led(5,5,1);
	}
	x++;
	
	while(t<x)
	{
		led(5,5,2);
	}
	x++;
	
	while(t<x)
	{
		led(5,5,3);
	}
	x++;
	
	while(t<x)
	{
		led(5,5,4);
	}
	x++;
	
	while(t<x)
	{
		led(5,5,5);
	}
	x++;
	
	while(t<x)
	{
		led(5,4,5);
	}
	x++;
	
	while(t<x)
	{
		led(5,3,5);
	}
	x++;
	
	while(t<x)
	{
		led(5,2,5);
	}
	x++;
	
	while(t<x)
	{
		led(5,1,5);
	}
	x++;
	
	while(t<x)
	{
		led(5,1,4);
	}
	x++;
	
	while(t<x)
	{
		led(5,1,3);
	}
	x++;
	
	while(t<x)
	{
		led(5,1,2);
	}
	x++;
	}

	{while(t<x)		//Fläche 5 o
	{
		led(5,2,2);
	}
	x++;
	
	while(t<x)
	{
		led(5,3,2);
	}
	x++;
	
	while(t<x)
	{
		led(5,4,2);
	}
	x++;
	
	while(t<x)
	{
		led(5,4,3);
	}
	x++;
	
	while(t<x)
	{
		led(5,4,4);
	}
	x++;
	
	while(t<x)
	{
		led(5,3,4);
	}
	x++;
	
	while(t<x)
	{
		led(5,2,4);
	}
	x++;
	
	while(t<x)
	{
		led(5,2,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 4 o
	{
		led(4,2,2);
	}
	x++;
	
	while(t<x)
	{
		led(4,3,2);
	}
	x++;
	
	while(t<x)
	{
		led(4,4,2);
	}
	x++;
	
	while(t<x)
	{
		led(4,4,3);
	}
	x++;
	
	while(t<x)
	{
		led(4,4,4);
	}
	x++;
	
	while(t<x)
	{
		led(4,3,4);
	}
	x++;
	
	while(t<x)
	{
		led(4,2,4);
	}
	x++;
	
	while(t<x)
	{
		led(4,2,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 3 o
	{
		led(3,2,2);
	}
	x++;
	
	while(t<x)
	{
		led(3,3,2);
	}
	x++;
	
	while(t<x)
	{
		led(3,4,2);
	}
	x++;
	
	while(t<x)
	{
		led(3,4,3);
	}
	x++;
	
	while(t<x)
	{
		led(3,4,4);
	}
	x++;
	
	while(t<x)
	{
		led(3,3,4);
	}
	x++;
	
	while(t<x)
	{
		led(3,2,4);
	}
	x++;
	
	while(t<x)
	{
		led(3,2,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 2 o
	{
		led(2,2,2);
	}
	x++;
	
	while(t<x)
	{
		led(2,3,2);
	}
	x++;
	
	while(t<x)
	{
		led(2,4,2);
	}
	x++;
	
	while(t<x)
	{
		led(2,4,3);
	}
	x++;
	
	while(t<x)
	{
		led(2,4,4);
	}
	x++;
	
	while(t<x)
	{
		led(2,3,4);
	}
	x++;
	
	while(t<x)
	{
		led(2,2,4);
	}
	x++;
	
	while(t<x)
	{
		led(2,2,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 1 o
	{
		led(1,2,2);
	}
	x++;
	
	while(t<x)
	{
		led(1,3,2);
	}
	x++;
	
	while(t<x)
	{
		led(1,4,2);
	}
	x++;
	
	while(t<x)
	{
		led(1,4,3);
	}
	x++;
	
	while(t<x)
	{
		led(1,4,4);
	}
	x++;
	
	while(t<x)
	{
		led(1,3,4);
	}
	x++;
	
	while(t<x)
	{
		led(1,2,4);
	}
	x++;
	
	while(t<x)
	{
		led(1,2,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 1 i
	{
		led(1,3,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 2 i
	{
		led(2,3,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 3 i
	{
		led(3,3,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 4 i
	{
		led(4,3,3);
	}
	x++;
	}
	
	{while(t<x)		//Fläche 5 i
	{
		led(5,3,3);
	}
	x++;
	}
	
}