#include"my_lib.h"

unsigned char uart_rx(void)
{
	while( !(LPC_UART0->LSR & 0x01));					// Waiting for Reciver Data Ready  bit to be 1
	return(LPC_UART0->RBR);										
}
