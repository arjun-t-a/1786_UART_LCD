#include"my_lib.h"

void lcd_data( unsigned char *ptr)
{
	while( *ptr)
	{
		lcd_display(*ptr);
		ptr++;
	}
}
