/*
 * File:   main.c
 * Author: alvar
 *
 * Created on 16 de marzo de 2026, 16:04
 */


#include <xc.h>
#include "SIO2.h"
#include "ADC2.h"
#include "game.h"
#include "SELECT_BUTTON.h"
#include "TIMER2.h"
#include "DATA_TIME.h"
#include "DO_COMMAND.h"
#include "COMMANDS.h"
#include "TTL_MANUAL_RECIEVE.h"
#include "TTL_MANUAL_SEND.h"
#include "INITIALIZE.h"
#include "FARM.h"
#include "CREATE_STRING_TO_SEND.h"
#include "EEPROM.h"
#include "PRODUCTS.h"
#include "LcTLCD.h"
#include "LED2.h"

#pragma config OSC = HSPLL
#pragma config PBADEN = DIG
#pragma config MCLRE = ON
#pragma config DEBUG = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF
#pragma config LVP = OFF


void __interrupt (high_priority) MyRSI(void){
    if(TMR0IF == 1){
        RSI_Timer0(); 
    }   
}

void initInterrupts();
void initTimers();
void initPorts();

void main(void) {
    SIO_Init();
    AD_Init(0);
    initInterrupts();
    initTimers();
    initPorts();
    TI_Init ();
    LcInit(2, 16);
    TI_ResetTics(4);
    
    
    
    
    while(1){
        
        
        motorDataTime();
        motorSIO();
        motorADC();
        motorRecieveCommand();
        motorParseCommand();
        motorFarm();
        motorSIORecieve(); 
        motorSIOSend();
        motorGame();
        motorInitialize();
        motorProducts();
        motorEEprom();
        motorButton();
        motorHeartBeat();
        MotorLCD();
        

    }
    return;
}
void initInterrupts(){
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    RCONbits.IPEN = 0;
    INTCONbits.TMR0IE = 1;
    
    INTCON2bits.RBPU = 0;
    

}
void initTimers(){
    unsigned char ok = 0;
    unsigned char timer[19];
    
    for(unsigned char i = 0; i < 19; i++){
        timer[i] = i;
        ok = TI_NewTimer(&timer[i]);
    }

}
void initPorts(){

    TRISAbits.TRISA4 = 0;
    LATAbits.LATA4 = 0;
    
    
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC0 = 0;
    LATCbits.LATC0 = 1;
    
    
    TRISD = 0xFF;
    
    TRISAbits.TRISA3 = 0;
    LATAbits.LATA3 = 0;
    TRISAbits.TRISA2 = 1;
    
}