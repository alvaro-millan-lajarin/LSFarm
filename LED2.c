
#include <xc.h>
#include "LED2.h"
#include "TIMER2.h"

#define TIMER_HANDLE_HEARTBEAT  15

#define PWM_PERIOD   100 
#define FADE_STEPS   200  

unsigned char heartBeat = 1;

void stopHeartBeat(){
    heartBeat = 0;
}
void startHeartBeat(){
    heartBeat = 1;
}

void motorHeartBeat() {
    static unsigned char estat     = 0;
    static unsigned char duty      = 0;
    static unsigned char pwm_tick  = 0; 
    
    if(!heartBeat){
        LATAbits.LATA4 = 0;
        return;
    }

    pwm_tick++;

    if (pwm_tick <= duty) {
        LATAbits.LATA4 = 1;
    } else {
        LATAbits.LATA4 = 0;
    }

    if (pwm_tick >= PWM_PERIOD) {
        pwm_tick = 0;

        switch (estat) {
            case 0:            
                if (duty < FADE_STEPS) {
                    duty++;
                } else {
                    estat = 1;  
                }
                break;

            case 1:       
                if (duty > 0) {
                    duty--;
                } else {
                    estat = 0; 
                }
                break;
        }
    }
}