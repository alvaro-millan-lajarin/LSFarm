/*
 * File:   TTL_MANUAL.c
 * Author: alvar
 *
 * Created on 18 de marzo de 2026, 13:46
 */


#include <xc.h>
#include "TTL_MANUAL_RECIEVE.h"
#include "TIMER2.h"

#define IDLE  0
#define START 1
#define DATA  2
#define STOP  3
#define RX_PIN PORTCbits.RC1


static unsigned char rx_dato = 0;
static unsigned char newChar = 0;
unsigned char ok_recive = 1;

unsigned char getCharSioManual(){
    return rx_dato;
}

unsigned char charRecivedSioManual(){
    if(newChar == 1){
        newChar = 0;
        return 1;
    }else{
        return 0;
    }  
}
unsigned char HanPasado416us(){ return((unsigned int)TI_GetTics(5) >= 2); }
unsigned char HanPasado624us(){ return((unsigned int)TI_GetTics(6) >= 3); }




void motorSIORecieve(){

 static unsigned char estado = IDLE;
 
 static unsigned char bit_pos = 0;

    switch(estado){

        case IDLE:

            if (RX_PIN == 0 && ok_recive) {
                ok_recive = 0;
                estado = START;
                TI_ResetTics(6);    
            }
            

        break;
        case START:

            if (HanPasado624us()) {

                    estado = DATA;
                    rx_dato = 0;
                    bit_pos = 0;
                    rx_dato |= (RX_PIN << bit_pos);
                    bit_pos++;
                    TI_ResetTics(5);

            }

        break;


        case DATA:

            if (HanPasado416us()) {

                rx_dato |= (RX_PIN << bit_pos);

                bit_pos++;
                TI_ResetTics(5);

                if (bit_pos == 8){
                    estado = STOP;
                }
            }

        break;


        case STOP:

            if (HanPasado416us()) {
                    newChar = 1;
                    ok_recive = 1;
                    bit_pos = 0;
                    estado = IDLE;
                    
            }

        break;
    }
}
