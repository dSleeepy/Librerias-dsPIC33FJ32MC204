#include "ConfiguracionPLL.h"

void ConfiguracionPLL(uint8_t N1,uint16_t M,unsigned char N2){
    if(N1<2||N1>33){
        return;
    }
    if(M<2||M>513){
        return;
    }
    if(N2!=2&&N2!=4&&N2!=8){
        return;
    }
    CLKDIVbits.PLLPRE=N1-2;
    PLLFBDbits.PLLDIV=M-2;
    if(N2==2){
        CLKDIVbits.PLLPOST=0;
    }else if(N2==4){
        CLKDIVbits.PLLPOST=1;
    }else{
        CLKDIVbits.PLLPOST=3;
    }
}