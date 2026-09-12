#ifndef CONFIGURACIONPLL_H
#define	CONFIGURACIONPLL_H

// Formula:
// Fosc=Finput(M/(N1*N2))
#include <xc.h>
#include <stdint.h>

void ConfiguracionPLL(uint8_t N1,uint16_t M,unsigned char N2);
#endif	/* CONFIGURACIONPLL_H */