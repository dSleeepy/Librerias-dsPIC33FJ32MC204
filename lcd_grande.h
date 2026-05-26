#ifndef LCD_GRANDE_H
#define LCD_GRANDE_H
#include <xc.h>
#include "dspic_cristal.h"

//==================== DATOS ====================
#define D4 LATAbits.LATA7
#define D5 LATAbits.LATA8
#define D6 LATAbits.LATA9
#define D7 LATAbits.LATA10
//==================== CONTROL ====================
#define EN1 LATAbits.LATA0
#define EN2 LATAbits.LATA1
#define RS  LATAbits.LATA4
//==================== DIRECCION ====================
#define D4_DIR TRISAbits.TRISA7
#define D5_DIR TRISAbits.TRISA8
#define D6_DIR TRISAbits.TRISA9
#define D7_DIR TRISAbits.TRISA10
#define EN1_DIR TRISAbits.TRISA0
#define EN2_DIR TRISAbits.TRISA1
#define RS_DIR  TRISAbits.TRISA4
//==================== FUNCIONES ====================
void Lcd_Init(void);
void Lcd_Clear(void);
void Lcd_Set_Cursor(unsigned char fila,unsigned char col);
void Lcd_Write_Char(char data);
void Lcd_Write_String(const char *dato);
#endif
