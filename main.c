#include"my_lib.h"

int main()
{
	unsigned char a[]= "Hello world\n", ch;
	int i;
	SystemInit();
	uart_init();
	lcd_init();
	for( i=0; i<11; i++)
	{
		uart_tx(a[i]);
	}
	while(1)
	{
		ch = uart_rx();
		uart_tx(ch);
		lcd_display(ch);
	}
}
