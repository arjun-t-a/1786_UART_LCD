#include"my_lib.h"

void uart_tx(unsigned char ch)
{
	while( !(LPC_UART0->LSR & (1 << 5)));						//waiting for the Transmitter Holding Register Empty (THRE) to be set to indicate transmission completed.
	LPC_UART0->THR = ch;
}
