#include"my_lib.h"

void uart_init(void)
{
	LPC_PINCON->PINSEL0 &= ~(0x0f0);   			// Reseting Tx and Rx pins to default (0000);
	LPC_PINCON->PINSEL0 |= 0x050;						// Change pin to Tx & Rx functions (0101);
	LPC_UART0->FCR = 0x07;  								// FIFO enable , Reset Tx and Rx
	LPC_UART0->LCR = 0x83;									// Select 8 bit, DLAB
	LPC_UART0->DLL = 0xA2;									// Setting fot 9600 baud rate for 25Mhz PCLK
	LPC_UART0->DLM = 0x00;									// Setting for 9600 baud rate for 25Mhz PCLK
	LPC_UART0->LCR = 0x03;									// Clearing DLAB;
}
