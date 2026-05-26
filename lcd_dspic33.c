#include "lcd_dspic33.h"

// Función interna para enviar 4 bits al LCD
static void Lcd_Port(char data)
{
    D4 = (data >> 0) & 0x01;
    D5 = (data >> 1) & 0x01;
    D6 = (data >> 2) & 0x01;
    D7 = (data >> 3) & 0x01;
}

// Función interna para enviar comandos
static void Lcd_Cmd(unsigned char cmd)
{
    RS = 0;            // RS=0 para comando
    Lcd_Port(cmd >> 4); // Parte alta
    EN = 1;
    __delay_us(40);
    EN = 0;

    Lcd_Port(cmd & 0x0F); // Parte baja
    EN = 1;
    __delay_us(40);
    EN = 0;
}

// Inicializa LCD
void Lcd_Init(void)
{
    RS_DIR = 0;
    EN_DIR = 0;
    D4_DIR = 0;
    D5_DIR = 0;
    D6_DIR = 0;
    D7_DIR = 0;

    __delay_ms(20);

    // Secuencia de inicialización 4 bits
    Lcd_Cmd(0x33);
    Lcd_Cmd(0x32);
    Lcd_Cmd(0x28); // 4 bits, 2 líneas, 5x8 dots
    Lcd_Cmd(0x0C); // Display ON, cursor OFF
    Lcd_Cmd(0x06); // Entry mode
    Lcd_Clear();
}

// Borra toda la pantalla
void Lcd_Clear(void)
{
    Lcd_Cmd(0x01);
    __delay_ms(2);
}

// Establece posición del cursor (fila: 1-4, col: 1-16)
void Lcd_Set_Cursor(unsigned char fila, unsigned char col)
{
    unsigned char temp;
    switch(fila)
    {
        case 1: temp = 0x80 + (col - 1); break;
        case 2: temp = 0xC0 + (col - 1); break;
        case 3: temp = 0x94 + (col - 1); break;
        case 4: temp = 0xD4 + (col - 1); break;
        default: temp = 0x80; break;
    }
    Lcd_Cmd(temp);
}

// Escribe un solo carácter
void Lcd_Write_Char(char data)
{
    RS = 1;             // RS=1 para dato
    Lcd_Port(data >> 4); // Parte alta
    EN = 1;
    __delay_us(40);
    EN = 0;

    Lcd_Port(data & 0x0F); // Parte baja
    EN = 1;
    __delay_us(40);
    EN = 0;
}

// Escribe cadena de caracteres
void Lcd_Write_String(const char *dato)
{
    while(*dato)
    {
        Lcd_Write_Char(*dato++);
    }
}
