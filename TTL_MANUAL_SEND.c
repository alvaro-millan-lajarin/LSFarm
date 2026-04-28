/*
 * File:   TTL_MANUAL_SEND.c
 * Author: alvar
 *
 * Created on 19 de marzo de 2026, 15:26
 */


#include <xc.h>
#include "TTL_MANUAL_SEND.h"
#include "TIMER2.h"
#include "TTL_MANUAL_RECIEVE.h"


#define TX_PIN PORTCbits.RC0
#define SIO_MAX_MSG  8
#define SIO_MSG_MASK 7




#define IDLE     0
#define DATA     1
#define STOP     2
#define STR_SEND 3

unsigned char estado = 0;
unsigned char dato;
unsigned char ok_transmit = 1;

static const unsigned char *cola[SIO_MAX_MSG];
static unsigned char head = 0;
static unsigned char tail = 0;

static const unsigned char *frase_actual = 0;
static unsigned char index = 0;

void uartTX(unsigned char d){
    static unsigned char tmp[2];
    tmp[0] = d;
    tmp[1] = '\0';
    SIO_Manual_SetFrase(tmp);
}


unsigned char HanPasado208usTX(){
    return((unsigned int)TI_GetTics(7) >= 2);
}
void SIO_Manual_SetFrase(unsigned char *msg) {
    unsigned char next = (head + 1) & SIO_MSG_MASK;
    
    if(next == tail){
        return;
    }
    
    cola[head] = msg;
    head = next;
    
}
void motorSIOSend(){
    static unsigned char bit_pos = 0;
    switch(estado){
        case IDLE:
            if(tail != head){
                frase_actual = cola[tail];
                tail = (tail + 1) & SIO_MSG_MASK;
                index = 0;
                estado = STR_SEND;
            }
        break;

        case STR_SEND:
            if(frase_actual[index] == '\0'){
                frase_actual = 0;
                estado = IDLE;
            } else if(ok_transmit && HanPasado208usTX()){
                ok_transmit = 0;
                dato = frase_actual[index];
                index++;
                TX_PIN = 0;         
                bit_pos = 0;
                TI_ResetTics(7);
                estado = DATA;
            }
        break;

        case DATA:
            if(HanPasado208usTX()){
                TX_PIN = (dato >> bit_pos) & 1;
                TI_ResetTics(7);
                bit_pos++;
                if(bit_pos == 8) estado = STOP;
            }
        break;

        case STOP:
            if(HanPasado208usTX()){
                
                TX_PIN = 1;        
                bit_pos = 0;
                ok_transmit = 1;
                TI_ResetTics(7);
                estado = STR_SEND;  
            }
        break;
    }
}

