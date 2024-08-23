#include<util/delay.h>

/*PORTC*/
#define DDRC *((volatile unsigned char *)0x27)
#define PORTC *((volatile unsigned char *) 0x28)
#define PINC *((volatile unsigned char *)0x26)
				/*PORTB*/
#define DDRB *((volatile unsigned char *)0x24)
#define PORTB *((volatile unsigned char *) 0x25)
#define PINB *((volatile unsigned char *)0x23)
				/*PORTD*/
#define DDRD *((volatile unsigned char *)0x2A)
#define PORTD *((volatile unsigned char *) 0x2B)
#define PIND *((volatile unsigned char*)0x29)

int main(void){

	DDRD &= (1<<4);

	DDRC |= 0x0F;
	PORTC = 0b00001001;

	DDRB = (DDRB|(1<<0)) | (DDRB|(1<<1));

	PORTB= (PORTB & ~(1<<0)) | (PORTB & ~(1<<1));


	while (1){
		unsigned char num = 9;
		// check if the push button is pressed or not
		if( PIND & (1<<4) )
		{
			while((PORTC & 0x0F) >= 0)
			{
			    PORTC = (num);
			    num--;
			    _delay_ms(500);
			    while ((PORTC & 0x0F) == 0){
			    		PORTB = 0b00000011;
			    		_delay_ms(3000);
			    		}
			}

		}

	}

}


