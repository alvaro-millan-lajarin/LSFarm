/*
 * File:   INITIALIZE.c
 * Author: alvar
 *
 * Created on 17 de marzo de 2026, 17:50
 */


#include <xc.h>
#include "INITIALIZE.h"
#include "FARM.h"
#include "COMMANDS.h"


unsigned char startInitialize = 0;

void DO_Initialize(){
    startInitialize = 1;
    
}


void motorInitialize() {
    static unsigned char estat = 0;
    static unsigned char field_num = 0;
    static unsigned char i = 0;
    static unsigned char result = 0;
    unsigned char *data = getData();

    switch(estat) {
        case 0:
            if (startInitialize) { i = field_num = result = 0; estat = 1; }
            break;

        case 1: {
            unsigned char c = data[i];
            if (c == '$') {
                if (field_num == 0) {
                    data[i] = '\0';
                    DO_SetFarmName(data);
                    field_num = 1;
                    i++;
                    estat = 7;
                } else {
                    estat = 5;
                }
            } else if (c == '\r') {
                estat = 5;
            } else {
                if (field_num > 0)
                    result = result * 10 + (c - '0');
                i++;
            }
            break;
        }

        case 5: {
            unsigned int r = (unsigned int)result;
            unsigned int scaled = (r << 9) + (r << 6) + (r << 4) + (r << 3) + r;
            DO_SetAnimalTime(field_num - 1, scaled);
            if (field_num == 4) { estat = 6; return; }
            field_num++;
            result = 0;
            i++;
            estat = 1;
            break;
        }

        case 6:
            setTempsFarmsOk();
            startInitialize = 0;
            field_num = i = result = 0;
            estat = 0;
            resetCommand();
            break;

        case 7:
            if (getFarmNameReady()) { result = 0; estat = 1; }
            break;
    }
}