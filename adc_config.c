#include "adc_config.h"

void ADC_Init(void){
    AD1CON1bits.ADON=0;
    AD1CON1bits.AD12B=1;
    AD1CON1bits.FORM=0b00;
    AD1CON1bits.SSRC=0b000;
    AD1CON1bits.ASAM=0;
    AD1CON1bits.SAMP=0;
    AD1CON2bits.VCFG=0b000;
    AD1CON2bits.CHPS=0b00;
    AD1CON2bits.CSCNA=0;
    AD1CON3bits.ADRC=0;
    AD1CON3bits.ADCS=15;
    AD1CSSL=0;
    AD1CHS0bits.CH0NA=0;
    AD1CON1bits.ADON=1;
}
uint16_t canal_ADC(uint8_t canal){
    uint32_t timeout=0;
    AD1CHS0bits.CH0SA=canal;
    AD1CON1bits.SAMP=1;
    __delay_us(20);
    AD1CON1bits.SAMP=0;
    while(AD1CON1bits.DONE==0){
        timeout++;
        if(timeout>50000){
            return 9999;
        }
    }
    return ADCBUF0;
}
// modo 10 bits
// valor minimo 76ns>TAD
// tiempo de conversion 12*TAD
// modo 12 bits
// valor minimo 117,6ns>TAD
// tiempo de conversion 14*TAD
