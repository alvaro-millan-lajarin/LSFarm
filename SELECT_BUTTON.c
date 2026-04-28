/*
 * File:   SELECT_BUTTON.c
 * Author: alvar
 *
 * Created on 16 de marzo de 2026, 17:41
 */


#include <xc.h>
#include "SIO2.h"
#include "SELECT_BUTTON.h"
#include "TIMER2.h"

#define TIMER_HANDLER_16MS 12
#define MS_REBOTS 77

void motorButton(){
    
    static unsigned char estat = 0;
    switch (estat){
        case 0:
            if(PORTBbits.RB0 == 0){
                estat = 1;
                TI_ResetTics(TIMER_HANDLER_16MS);
            }
                
        break;
        case 1:
            if (TI_GetTics(TIMER_HANDLER_16MS) >= MS_REBOTS)
                estat = (PORTBbits.RB0 == 0) ? 2 : 0;
            break;
        case 2:
            if(PORTBbits.RB0 != 0){
                buttonPressed();
                TI_ResetTics(TIMER_HANDLER_16MS);
                estat = 1;
            }
            break;
    }
    
}

void buttonPressed(){ 
    SIO_SendSimple(SEND_SELECT);
    

}
