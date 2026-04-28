/*
 * File:   game.c
 * Author: alvar
 *
 * Created on 16 de marzo de 2026, 16:47
 */


#include <xc.h>
#include "game.h"
#include "DATA_TIME.h"
#include "FARM.h"
#include "PRODUCTS.h"
#include "TIMER2.h"
#include "PRODUCTS.h"

unsigned char start = 0;
static unsigned char estat = 0;

unsigned char startGameOk(){
    return start;
}
void resetGame(){
    start = 0;
    estat = 0;
}
void motorGame() {
    
    
    switch (estat){
        case 0:
            
            if (dateTimeOk() && tempsFarmsOk()){
                estat++;
                start = 1;
                //LATAbits.LATA4 = 1;
            }
            break;
        case 1:
            setStartFarm();
            setStartProducts();
            TI_ResetTics(TIMER_HANDLE_COW);
            TI_ResetTics(TIMER_HANDLE_PIG);
            TI_ResetTics(TIMER_HANDLE_HORSE);
            TI_ResetTics(TIMER_HANDLE_CHICKEN);
            
            TI_ResetTics(TIMER_HANDLE_COW_PRODUCT);
            TI_ResetTics(TIMER_HANDLE_PIG_PRODUCT);
            TI_ResetTics(TIMER_HANDLE_HORSE_PRODUCT);
            TI_ResetTics(TIMER_HANDLE_CHICKEN_PRODUCT);
            estat++;
            break;
        case 2:
            break;
        default:
            break;
    
    
    
    }
}
