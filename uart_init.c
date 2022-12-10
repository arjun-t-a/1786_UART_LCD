#include"my_lib.h"

void uart_init(unsigned int BdRate)
{
	unsigned char uartClk,pClk,regValue
	LPC_PINCON->PINSEL0 &= ~(0x0f0);   			// Reseting Tx and Rx pins to default (0000);
	LPC_PINCON->PINSEL0 |= 0x050;						// Change pin to Tx & Rx functions (0101);
	LPC_UART0->FCR = 0x07;  								// FIFO enable , Reset Tx and Rx
	LPC_UART0->LCR = 0x83;	// Select 8 bit, DLAB
	
	/* Get the PCLK from PCLKSEL0 register 7-6 bits */
	/* Bit6,Bit7 contains the Uart Clock(ie.UART_PCLK) information.
     Calculation of the UART_PCLK and the actual Peripheral Clock(PCLK)*/
	
	uartClk = (LPC_SC->PCLKSEL0 >> 6) & 0x03;
	
	switch(uartClk)
	{
		case 0x00:
			pClk = SystemCoreClock/4;
			break;
		case 0x01:
			pClk = SystemCoreClock;
			break;
		case 0x02:
			pClk = SystemCoreClock/2;
			break;
		case 0x03:
			pClk = SystemCoreClock/8;
			break;
	}
	
	/* Calculate the DLM,DLL vaues for required baudrate from PCLK */
	
	regValue = (pClk / (16 * BdRate));
	
	/* Updtae the DLM,DLL with the calculated values */
	
	LPC_UART0->DLL = regValue & 0xFF;
	LPC_UART0->DLM = (regValue >> 0x08) & 0xFF;
	
	LPC_UART0->LCR = 0x03;									// Clearing DLAB;
}
