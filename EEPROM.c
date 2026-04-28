#include <xc.h>
#include "EEPROM.h"
#include "DATA_TIME.h"

#define EEPROM_QUEUE_SIZE 8
#define EEPROM_QUEUE_MASK 7
#define SLEEP_PERIOD_SEG 120  // 2 minutos

unsigned char writeAddr[EEPROM_QUEUE_SIZE];
unsigned char writeVal[EEPROM_QUEUE_SIZE];
unsigned char qHead = 0;
unsigned char qTail = 0;

unsigned char EEPROM_IsBusy(){
    return (qHead != qTail) || (EECON1bits.WR);
}

void eepromEnqueue(unsigned char addr, unsigned char val) {
    unsigned char next = (qHead + 1) & EEPROM_QUEUE_MASK;
    if (next == qTail) return;
    writeAddr[qHead] = addr;
    writeVal[qHead]  = val;
    qHead = next;
}

static void eepromWriteHMS(unsigned char base) {
    eepromEnqueue(base + 3, DT_GetHora());
    eepromEnqueue(base + 4, DT_GetMin());
    eepromEnqueue(base + 5, DT_GetSeg());
}

void EEPROM_WriteAnimal(unsigned char index, unsigned char tipus) {
    unsigned char base = EEPROM_ADDR(index);
    eepromEnqueue(base + 0, tipus);
    eepromEnqueue(base + 1, DT_GetDia());
    eepromEnqueue(base + 2, DT_GetMes());
    eepromWriteHMS(base);   // reutiliza el bloque com?n
}

void EEPROM_WriteAnimalSleep(unsigned char index) {
    unsigned char addr = EEPROM_ADDR(index);
    eepromEnqueue(addr + 1, DT_GetDia());
    eepromEnqueue(addr + 2, DT_GetMes());
    eepromWriteHMS(addr);
}

AnimalEEPROM EEPROM_ReadAnimal(unsigned char index) {
    AnimalEEPROM a;
    unsigned char base = EEPROM_ADDR(index);

    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS  = 0;

    EEADR = base + 0; EECON1bits.RD = 1; a.tipus = EEDATA;
    EEADR = base + 1; EECON1bits.RD = 1; a.dia   = EEDATA;
    EEADR = base + 2; EECON1bits.RD = 1; a.mes   = EEDATA;
    EEADR = base + 3; EECON1bits.RD = 1; a.hora  = EEDATA;
    EEADR = base + 4; EECON1bits.RD = 1; a.min   = EEDATA;
    EEADR = base + 5; EECON1bits.RD = 1; a.seg   = EEDATA;

    return a;
}

unsigned char EEPROM_GetEstat(AnimalEEPROM a, unsigned char diaAct, unsigned char mesAct,
                              unsigned char horaAct, unsigned char minAct, unsigned char segAct) {
    if (mesAct != a.mes) return 1;
    int diffMin;
    if (diaAct == a.dia) {
        diffMin = (int)(horaAct*60 + minAct) - (int)(a.hora*60 + a.min);
        if (diffMin < 0) diffMin += 1440;
    } else if (diaAct == (unsigned char)(a.dia + 1)) {
        diffMin = 1440 + (int)(horaAct*60 + minAct) - (int)(a.hora*60 + a.min);
    } else {
        return 1;
    }
    if (diffMin > 2) return 1;
    if (diffMin == 2) return (segAct >= a.seg) ? 1 : 0;
    return 0;
}

void motorEEprom(void) {
    static unsigned char estat = 0;
    switch (estat) {
        case 0:
            if (qTail != qHead) {
                EEADR            = writeAddr[qTail];
                EEDATA           = writeVal[qTail];
                EECON1bits.EEPGD = 0;
                EECON1bits.CFGS  = 0;
                EECON1bits.WREN  = 1;
                INTCONbits.GIE   = 0;
                EECON2 = 0x55;
                EECON2 = 0xAA;
                EECON1bits.WR    = 1;
                INTCONbits.GIE   = 1;
                estat = 1;
            }
            break;
        case 1:
            if (EECON1bits.WR == 0) {
                EECON1bits.WREN = 0;
                qTail = (qTail + 1) & EEPROM_QUEUE_MASK;
                estat = 0;
            }
            break;
    }
}

