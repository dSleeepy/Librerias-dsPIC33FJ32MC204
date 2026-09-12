#ifndef CONFIGURACIONUART_H
#define	CONFIGURACIONUART_H

void Uart_Init(uint32_t baudrate);
void Uart_Tx_Char(char dato);
void Uart_Tx_String(char *str);
char Uart_Rx_Char(void);
void Uart_Rx_String(char *buffer, uint8_t maxlen);
int write(int handle, void *buffer, unsigned int len);

#endif	/* CONFIGURACIONUART_H */

