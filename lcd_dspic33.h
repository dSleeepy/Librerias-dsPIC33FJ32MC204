#ifndef LCD_DSPIC_H
#define LCD_DSPIC_H

#include "dspic_cristal.h"
#include <stdint.h>
#include "xc.h"

// Datos
#define D4 LATAbits.LATA7
#define D5 LATAbits.LATA8
#define D6 LATAbits.LATA9
#define D7 LATAbits.LATA10
#define RS LATAbits.LATA0
#define EN LATAbits.LATA1

// Dirección
#define D4_DIR TRISAbits.TRISA7
#define D5_DIR TRISAbits.TRISA8
#define D6_DIR TRISAbits.TRISA9
#define D7_DIR TRISAbits.TRISA10
#define RS_DIR TRISAbits.TRISA0
#define EN_DIR TRISAbits.TRISA1

// FUNCIONES
void Lcd_Init(void);
void Lcd_Clear(void);
void Lcd_Set_Cursor(unsigned char fila, unsigned char col);
void Lcd_Write_Char(char data);
void Lcd_Write_String(const char *dato);

#endif
