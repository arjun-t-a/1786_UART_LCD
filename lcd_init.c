#include"my_lib.h"

void lcd_init(void)
{
	unsigned char cmd[] = { 0x38, 0x0f, 0x01, 0x80}, i;
	LPC_GPIO0->FIODIR |= LCD_ALL; 
	
	for( i=0; i<4; i++ )
	{
		lcd_cmd(cmd[i]);
	}
}	
