/*
 * File:   PRODUCTS.c
 * Author: alvar
 *
 * Created on 16 de marzo de 2026, 22:09
 */


#include <xc.h>
#include "PRODUCTS.h"
#include "TIMER2.h"
#include "EEPROM.h"
#include "DATA_TIME.h"
#include "FARM.h"
#include "LcTLCD.h"

#define TIMER_HANDLE_COW_PRODUCT 8
#define TIMER_HANDLE_PIG_PRODUCT 9
#define TIMER_HANDLE_HORSE_PRODUCT 10
#define TIMER_HANDLE_CHICKEN_PRODUCT 11


static unsigned char estat = 0;
const unsigned int tiempos[4] = { 28247, 18631, 13823, 7813 };

const unsigned char handles[4] = {
    TIMER_HANDLE_COW_PRODUCT,
    TIMER_HANDLE_PIG_PRODUCT,
    TIMER_HANDLE_HORSE_PRODUCT,
    TIMER_HANDLE_CHICKEN_PRODUCT
};

static unsigned char gameStart = 0;
static unsigned char productos[4] = {0}; // COW, PIG, HORSE, CHICKEN
static unsigned char rebelion = 0;
static unsigned char consumePending = 0;  
static unsigned char consumeTipo = 0;

unsigned char getNumLlet()    { 
    return productos[0];    
}
unsigned char getNumPernil()  { 
    return productos[1];  
}
unsigned char getNumPinzells(){ 
    return productos[2]; 
}
unsigned char getNumHuevos()  { 
    return productos[3];  
}
void setStartProducts(){
    gameStart = 1;
}
void resetProducts(){
    for(unsigned char i = 0; i < 4; i++){
        productos[i] = 0;
    }
    gameStart = 0;
    estat = 0;
}
void stopRebelion(){
    rebelion = 0; 
}
void startRebelion(){
    rebelion = 1; 
}
void consume(unsigned char tipo){
    consumeTipo = tipo;
    consumePending = 1;
}
void motorProducts() {
    
    static unsigned char i = 0;
    static unsigned char tipusActual = 0; // COW=0, PIG=1, HORSE=2, CHICKEN=3

    switch (estat) {
        case 0:
            if (!gameStart) break;
            if(consumePending){
                estat = 2;
                break;
            }

            for (unsigned char t = 0; t < 4; t++) {
                if ((unsigned int)(TI_GetTics(handles[t]) >> 3) >= tiempos[t]) {
                    TI_ResetTics(handles[t]);
                    tipusActual = t;
                    i = 0;
                    estat++;
                    break;
                }
            }
            break;

        case 1:
            if (i < getNumTotalAnimals()) {
                
                AnimalEEPROM a = EEPROM_ReadAnimal(i);
                
                if (a.tipus == tipusActual) {
                    
                    unsigned char awake = !EEPROM_GetEstat(a, DT_GetDia(), DT_GetMes(), DT_GetHora(), DT_GetMin(), DT_GetSeg());  // GetEstat devuelve 1=SLEEP, 0=AWAKE
                    
                    if (awake && !rebelion) {
                        productos[tipusActual]++;
                        Notificacio n;
                        n.tipo   = 'P';
                        n.nombre = tipusActual;
                        n.num    = productos[tipusActual];
                        addMsgToQueue(n);
                    }
                }
                i++;
              
            } else {
                estat--; 
            }
            break;
        case 2:
            switch (consumeTipo) {
                case 0:  // 1 chicken product
                    if (productos[3] > 0) productos[3]--;
                    break;
                case 1:  // 1 chicken + 1 pig
                    if (productos[3] > 0) productos[3]--;
                    if (productos[1] > 0) productos[1]--;
                    break;
                case 2:  // 2 cow
                    if (productos[0] >= 2) productos[0] -= 2;
                    else productos[0] = 0;
                    break;
                case 3:  // 2 horse
                    if (productos[2] >= 2) productos[2] -= 2;
                    else productos[2] = 0;
                    break;
            }
            consumePending = 0;
            estat = 0;
            
            break;
    }
}

