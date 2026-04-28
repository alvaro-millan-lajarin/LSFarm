// josepmaria.ribes@salle.url.edu (si hi trobeu alguna errada, si us plau envieu-me un correu :-)
// Arbeca, bressol de l'oliva arbequina
// Mar�, any del Senyor de 2023



#include <xc.h>
#include "TIMER2.h"


#define T0CON_CONFIG 0x88
        // 208us, FOsc a 40MHz.
#define TI_NUMTIMERS 19              

// VARIABLES GLOBALS DEL TAD
struct Timer {
	unsigned long TicsInicials;
	unsigned char Busy;
} static Timers[TI_NUMTIMERS];

static volatile unsigned long Tics=0;

void RSI_Timer0 () {
    // Pre: IMPORTANT! Funci� que ha der ser cridada des de la RSI, en en cas que TMR0IF==1.
    TMR0=TIMER_RELOAD;
    TMR0IF=0;
    Tics++;    
}

void TI_Init () {
	for (unsigned char counter=0; counter<TI_NUMTIMERS; counter++) {
		Timers[counter].Busy=TI_FALS;
	}
	T0CON=T0CON_CONFIG;
    TMR0=TIMER_RELOAD;
	INTCONbits.TMR0IF = 0;
	INTCONbits.TMR0IE = 1;
    
}

unsigned char TI_NewTimer(unsigned char *TimerHandle) {
	unsigned char Comptador=0;
	while (Timers[Comptador].Busy==TI_CERT) {
		if (++Comptador == TI_NUMTIMERS) return (TI_FALS);
	}
	Timers[Comptador].Busy=TI_CERT;
	*TimerHandle=Comptador;
    return (TI_CERT);
}

void TI_ResetTics (unsigned char TimerHandle) {
	di(); Timers[TimerHandle].TicsInicials=Tics; ei();
}


unsigned long TI_GetTics (unsigned char TimerHandle) {
    di(); unsigned long CopiaTicsActual=Tics; ei();
	return (CopiaTicsActual-(Timers[TimerHandle].TicsInicials));
}
