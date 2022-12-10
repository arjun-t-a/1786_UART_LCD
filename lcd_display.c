#include"my_lib.h"

void lcd_display(unsigned char data)
{
	LPC_GPIO0->FIOPIN = data<<15;
	LPC_GPIO0->FIOSET |= RS;
	LPC_GPIO0->FIOSET |= EN;
	delay();
	LPC_GPIO0->FIOCLR |= EN;
	delay();
}
