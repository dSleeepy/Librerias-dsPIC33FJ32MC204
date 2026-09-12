#include <xc.h>
#include "ConfiguracionTimer.h"

//FOMRULA TIMER
// PRX=((FCY*Tiempo)/Preescaler)-1
// Tiempo=((Preescaler*PRX)/FCY)+1

void Timer1_Init_Temp(void){
    T1CONbits.TON=0;
    T1CONbits.TGATE=0;
    T1CONbits.TCKPS=0b00; // preescaler
    T1CONbits.TCS=0;
    IEC0bits.T1IE=1;
    IFS0bits.T1IF=0;
    IPC0bits.T1IP=0b011; // prioridad
    PR1=15999; // momento en que llega al desbordamiento
    TMR1=0; // en que valor empieza
    T1CONbits.TON=1;
}
void Timer2_Init_Temp(void){
    T2CONbits.TON=0;
    T2CONbits.TGATE=0;
    T2CONbits.TCKPS=0b11; // preescaler
    T2CONbits.T32=0; // 16 bits
    T2CONbits.TCS=0;
    IEC0bits.T2IE=1;
    IFS0bits.T2IF=0;
    IPC1bits.T2IP=0b100; // prioridad
    PR2=31249; // momento en que llega al desbordamiento
    TMR2=0; // en que valor empieza
    T2CONbits.TON=1;
}
void Timer3_Init_Temp(void){
    T3CONbits.TON=0;
    T3CONbits.TGATE=0;
    T3CONbits.TCKPS=0b11; // preescaler
    T3CONbits.TCS=0;
    IEC0bits.T3IE=1;
    IFS0bits.T3IF=0;
    IPC2bits.T3IP=0b010; // prioridad
    PR3=62499; // momento en que llega al desbordamiento
    TMR3=0; // en que valor empieza
    T3CONbits.TON=1;
}
void Timer1_Init_Cont(void){
    T1CONbits.TON=0;
    T1CONbits.TSYNC=1;
    T1CONbits.TCKPS=0b00;
    T1CONbits.TCS=1;
    TRISAbits.TRISA4=1; // Pin T1CK
    IEC0bits.T1IE=1;
    IFS0bits.T1IF=0;
    IPC0bits.T1IP=0b011; // prioridad
    PR1=4;
    TMR1=0; // en que valor empieza
    T1CONbits.TON=1;
    
}
void Timer2_Init_Cont(void){
    T2CONbits.TON=0;
    T2CONbits.TCS=1;
    T2CONbits.TCKPS=0b00;
    TRISCbits.TRISC8=1;
    RPINR3bits.T2CKR=0b11000;
    IEC0bits.T2IE=1;
    IFS0bits.T2IF=0;
    IPC1bits.T2IP=0b100;
    PR2=7;
    TMR2=0;
    T2CONbits.TON=1;
}
void Timer3_Init_Cont(void){
    T3CONbits.TON=0;
    T3CONbits.TCKPS=0b00;
    T3CONbits.TCS=1;
    TRISCbits.TRISC9=1;
    RPINR3bits.T3CKR=0b11001;
    IEC0bits.T3IE=1;
    IFS0bits.T3IF=0;
    IPC2bits.T3IP=0b010;
    PR3=10;
    TMR3=0;
    T3CONbits.TON=1;
}
void Timer32bits_Init(void){
    T2CONbits.TON=0;
    T2CONbits.TGATE=0;
    T2CONbits.TCKPS=0b01; // preescaler
    T2CONbits.T32=1; // 32 bits
    T2CONbits.TCS=0;
    IEC0bits.T3IE=1;
    IFS0bits.T3IF=0;
    IPC2bits.T3IP=0b111; // prioridad
    PR2=0x0000; // momento en que llega al desbordamiento Min Significativo
    PR3=0xFFFF; // momento en que llega al desbordamiento Max Significativo
    TMR2=0x0000; // en que valor empieza Min Significativo
    TMR3=0x0000; // en que valor empieza Max Significativo
    T2CONbits.TON=1;
}

// void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
// void __attribute__((__interrupt__, auto_psv)) _T2Interrupt(void)
// void __attribute__((__interrupt__, auto_psv)) _T3Interrupt(void)