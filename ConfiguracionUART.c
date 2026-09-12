#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ConfiguracionUART.h"
#include "ConfiguracionBits.h"

void Uart_Init(uint32_t baudrate) {
    TRISBbits.TRISB0=0;
    TRISBbits.TRISB1=1;
    RPOR0bits.RP0R=0b00011;  // TX
    RPINR18bits.U1RXR=0b00001; // RX
    U1MODEbits.UARTEN=0;
    U1MODEbits.BRGH=0;
    U1MODEbits.PDSEL=0b00;
    U1MODEbits.STSEL=0;
    U1BRG=(uint16_t)((FCY/16UL/baudrate)-1);
    U1MODEbits.UARTEN=1;
    U1STAbits.UTXEN=1;
}
void Uart_Tx_Char(char dato){
    while(U1STAbits.UTXBF);
    U1TXREG=dato;
}
void Uart_Tx_String(char *str){
    char *ptr;
    ptr=str;
    while(*ptr){
        Uart_Tx_Char(*ptr++);
    }
}
int write(int handle, void *buffer, unsigned int len){
    int i;
    switch(handle){
        case 0: // handle 0 correspone a stdout
        case 1: // handle 1 correspone a stdint
        case 2: // handle 2 correspone a stderr
        default:
            for(i=0; i<len; i++){
                Uart_Tx_Char(*(char*)buffer++);
            }
    }
    return(len);
}
char Uart_Rx_Char(void){
    while(!U1STAbits.URXDA);
    return U1RXREG;
}
void Uart_Rx_String(char *buffer, uint8_t maxlen){
    uint8_t i=0;
    char c;
    while(i<maxlen-1) {
        c=Uart_Rx_Char();
        if(c=='\n'||c=='\r'){
            break;
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}
