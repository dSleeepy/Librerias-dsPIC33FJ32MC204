#include "lcd_grande.h"

static unsigned char lcd_actual;
static void Lcd_Port(char data){
    D4=(data>>0)&1;
    D5=(data>>1)&1;
    D6=(data>>2)&1;
    D7=(data>>3)&1;
}
static void Lcd_Enable(unsigned char lcd){
    if(lcd==1){
        EN1=1;
    }else{
        EN2=1;
    }
    __delay_us(40);
    EN1=0;
    EN2=0;
}
static void Lcd_Send(char data,unsigned char rs,unsigned char lcd){
    RS=rs;
    Lcd_Port(data>>4);  // PARTE ALTA
    Lcd_Enable(lcd);
    Lcd_Port(data&0x0F);  // PARTE BAJA
    Lcd_Enable(lcd);
    __delay_us(40);
}
void Lcd_Init(void){
    D4_DIR=0;
    D5_DIR=0;
    D6_DIR=0;
    D7_DIR=0;
    EN1_DIR=0;
    EN2_DIR=0;
    RS_DIR=0;
    EN1=0;
    EN2=0;
    RS=0;
    __delay_ms(20);
    // CONTROLADOR 1
    Lcd_Send(0x33,0,1);
    Lcd_Send(0x32,0,1);
    Lcd_Send(0x28,0,1);
    Lcd_Send(0x0C,0,1);
    Lcd_Send(0x06,0,1);
    Lcd_Send(0x01,0,1);
    __delay_ms(5);
    // CONTROLADOR 2
    Lcd_Send(0x33,0,2);
    Lcd_Send(0x32,0,2);
    Lcd_Send(0x28,0,2);
    Lcd_Send(0x0C,0,2);
    Lcd_Send(0x06,0,2);
    Lcd_Send(0x01,0,2);
    __delay_ms(5);
}
void Lcd_Clear(void){
    Lcd_Send(0x01,0,1);
    Lcd_Send(0x01,0,2);
    __delay_ms(5);
}
void Lcd_Set_Cursor(unsigned char fila,unsigned char col){
    unsigned char pos;
    switch(fila){
        case 1:
            lcd_actual=1;
            pos=0x80+(col-1);
            break;
        case 2:
            lcd_actual=1;
            pos=0xC0+(col-1);
            break;
        case 3:
            lcd_actual=2;
            pos=0x80+(col-1);
            break;
        case 4:
            lcd_actual=2;
            pos=0xC0+(col-1);
            break;
        default:
            return;
    }
    Lcd_Send(pos,0,lcd_actual);
}
void Lcd_Write_Char(char data){
    Lcd_Send(data,1,lcd_actual);
}
void Lcd_Write_String(const char *dato){
    while(*dato){
        Lcd_Write_Char(*dato++);
    }
}
