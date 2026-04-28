/*
 * File:   DATA_TIME.c
 * Author: alvar
 *
 * Created on 16 de marzo de 2026, 18:00
 */


#include <xc.h>
#include "DATA_TIME.h"
#include "SIO2.h"
#include "TIMER2.h"
#include "TTL_MANUAL_RECIEVE.h"
#include "TTL_MANUAL_SEND.h"

static unsigned char dia = 0;
static unsigned char mes = 0;
static unsigned char hora = 0;
static unsigned char min = 0;
static unsigned char seg = 0;

unsigned char DATE_TIME[15] = "";

#define TIMER_HANDLE_SEGUNDO 4
#define TICKS_PER_SEC 4808

const unsigned char DATE_ERROR[] = "\r\nERROR\r\n";
const unsigned char DATE_TIME_OK[] = "\r\nOK\r\n";


unsigned char dateTimeReady = 0;

unsigned char DT_GetDia() {
    return dia;
}

unsigned char DT_GetMes() {
    return mes;
}

unsigned char DT_GetHora() {
    return hora;
}

unsigned char DT_GetMin() {
    return min;
}

unsigned char DT_GetSeg() {
    return seg;
}

void incrementarTiempo() {
    seg++;
    if (seg > 59) {
        seg = 0;
        min++;
        if (min > 59) {
            min = 0;
            hora++;
            if (hora > 23) {
                hora = 0;
                dia++;
                
                if (dia > 31) {
                    dia = 1;
                    mes++;
                    if (mes > 12) {
                        mes = 1;
                    }
                }
            }
        }
    }
}


unsigned char dateTimeOk(){
    return dateTimeReady;

}
void resetDataTime(){
    dateTimeReady = 0;
}

void motorDataTime() {
    
    if ((unsigned int)TI_GetTics(TIMER_HANDLE_SEGUNDO) >= (unsigned int)TICKS_PER_SEC) {
        TI_ResetTics(TIMER_HANDLE_SEGUNDO);
        incrementarTiempo();
    }

 
    if (!charRecivedSioManual()) return;
    unsigned char c = getCharSioManual();

    static unsigned char i = 0;

    if (c != '\r') {
        DATE_TIME[i++] = c;
        uartTX(c);
        return;
    }

    if (i < 14) {
        SIO_Manual_SetFrase(DATE_ERROR);
        i = 0;
        return;
    }

    DATE_TIME[i] = '\0';
    dia  = (DATE_TIME[0]-'0')*10 + (DATE_TIME[1]-'0');
    mes  = (DATE_TIME[3]-'0')*10 + (DATE_TIME[4]-'0');
    hora = (DATE_TIME[6]-'0')*10 + (DATE_TIME[7]-'0');
    min  = (DATE_TIME[9]-'0')*10 + (DATE_TIME[10]-'0');
    seg  = (DATE_TIME[12]-'0')*10 + (DATE_TIME[13]-'0');
    i = 0;

    if (mes < 1 || mes > 12 || dia < 1 || dia > 31 ||
        hora > 23 || min > 59 || seg > 59 ||
        DATE_TIME[2] != '/' || DATE_TIME[5] != ' ' ||
        DATE_TIME[8] != ':' || DATE_TIME[11] != ':') {
        SIO_Manual_SetFrase(DATE_ERROR);
    } else {
        SIO_Manual_SetFrase(DATE_TIME_OK);
        dateTimeReady = 1;
    }
}
