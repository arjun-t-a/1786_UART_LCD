#include"my_lib.h"

void lcd_cmd(unsigned char cmd)
{
	LPC_GPIO0->FIOPIN = cmd<<15;
	LPC_GPIO0->FIOCLR |= RS;
	LPC_GPIO0->FIOSET |= EN;
	delay();
	LPC_GPIO0->FIOCLR |= EN;
	delay();
}
