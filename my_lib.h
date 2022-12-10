#include<lpc17xx.h>

#define LCD0 1<<15
#define LCD1 1<<16
#define LCD2 1<<17
#define LCD3 1<<18
#define LCD4 1<<19
#define LCD5 1<<20
#define LCD6 1<<21
#define LCD7 1<<22
#define RS 1<<10
#define EN 1<<11

#define LCD_ALL (LCD0|LCD1|LCD2|LCD3|LCD4|LCD5|LCD6|LCD7|RS|EN)

void lcd_init(void);
void lcd_cmd(unsigned char);
void delay(void);
void lcd_display(unsigned char);
void lcd_data( unsigned char * );

void uart_init(void);
void uart_tx(unsigned char);
unsigned char uart_rx(void);

