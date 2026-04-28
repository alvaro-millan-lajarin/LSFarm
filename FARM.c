/*
 * File:   FARM.c
 * Author: alvar
 *
 * Created on 16 de marzo de 2026, 19:17
 */

#include <xc.h>
#include "FARM.h"
#include "TIMER2.h"
#include "DATA_TIME.h"
#include "EEPROM.h"
#include "TTL_MANUAL_SEND.h"
#include "LcTLCD.h"

static unsigned char numAnimals = 0;

static unsigned char nameFarm[20] = "";
static unsigned char *farmNameSrc = NULL;
static unsigned char startSetFarmName = 0;

static unsigned int animalTimes[4] = {0, 0, 0, 0};

static unsigned char tempsFarmReady = 0;
static unsigned char gameStart = 0;

static unsigned char numPorTipo[4] = {0, 0, 0, 0};

unsigned char getFarmNameReady(void)     { return !startSetFarmName; }
unsigned char* getFarmName()             { return nameFarm; }
unsigned char getNumTotalAnimals()       { return numAnimals; }

void resetFarm() {
    numAnimals = 0;
    numPorTipo[0] = numPorTipo[1] = numPorTipo[2] = numPorTipo[3] = 0;
    gameStart = 0;
    tempsFarmReady = 0;
    startSetFarmName = 0;
}

void setStartFarm()    { gameStart = 1; }
unsigned char tempsFarmsOk() { return tempsFarmReady; }
void setTempsFarmsOk() { tempsFarmReady = 1; }

void DO_SetFarmName(unsigned char *field) {
    farmNameSrc = field;
    startSetFarmName = 1;
}

void DO_SetAnimalTime(unsigned char tipus, unsigned int time) { animalTimes[tipus] = time; }

void crearAnimal(unsigned char tipus) {
    if (numAnimals >= 24) return;
    unsigned char r = 0, s;
    for (s = 0; s < 4; s++)
        if (s != tipus && numPorTipo[s] < 3)
            r += (unsigned char)(3 - numPorTipo[s]);
    if ((unsigned char)(numAnimals + r) >= 24) return;
    EEPROM_WriteAnimal(numAnimals, tipus);
    numPorTipo[tipus]++;
    numAnimals++;
    Notificacio n;
    n.tipo   = 'A';
    n.nombre = tipus;
    n.num    = numPorTipo[tipus];
    addMsgToQueue(n);
}

void motorFarm() {
    static unsigned char estat = 0;
    static unsigned char i = 0;

    switch (estat) {

        case 0: {

            static unsigned char t = 0;
            if (startSetFarmName) {
                i = 0;
                estat++;
                break;
            }
            if (gameStart && !EEPROM_IsBusy() &&
                (unsigned int)(TI_GetTics(t) >> 3) >= animalTimes[t]) {
                crearAnimal(t);
                TI_ResetTics(t);
            }
            t = (t + 1) & 3;
            break;
        }

        case 1:
            if (farmNameSrc[i] != '\0' && i < 19) {
                nameFarm[i] = farmNameSrc[i];
                i++;
            } else {
                estat ++;
            }
            break;

        case 2:
            nameFarm[i] = '\0';
            i = 0;
            startSetFarmName = 0;
            estat = 0;
            break;

        default:
            break;
    }
}