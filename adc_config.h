#ifndef ADC_CONFIG_H
#define	ADC_CONFIG_H

#include <xc.h>
#include "dspic_cristal.h"

void ADC_Init(void);
uint16_t canal_ADC(uint8_t canal);

#endif	/* ADC_CONFIG_H */
