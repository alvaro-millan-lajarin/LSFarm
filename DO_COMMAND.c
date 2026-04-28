#include <xc.h>
#include "DO_COMMAND.h"
#include "COMMANDS.h"
#include "INITIALIZE.h"
#include "FARM.h"

#include "SIO2.h"
#include "EEPROM.h"
#include "DATA_TIME.h"
#include "game.h"
#include "PRODUCTS.h"
#include "LED2.h"
#include "TIMER2.h"
#include "ADC2.h"
#include "LcTLCD.h"

#define TICKS_PER_5_SEC 24040

static unsigned char i            = 0;
static unsigned char totalAnimals  = 0;
static unsigned char animalCounts[4] = {0,0,0,0};

// CMD_SLEEP state machine: 0=init, 1=wait5s, 2=scan EEPROM
static unsigned char sleep_state = 0;
static unsigned char sleep_j     = 0;
static unsigned char sleep_count = 0;
static unsigned char sleep_tipus = 0;
static unsigned char sleep_num   = 0;
void DO_Reset(){
    resetDataTime();
    resetFarm();
    resetProducts();
    resetGame();
    
    LcResetMotor();
    resetCommand();
}
cmd_t handle_GetAnimals(void) {
    if (i == 0) {
        totalAnimals = getNumTotalAnimals();
        animalCounts[0] = animalCounts[1] = animalCounts[2] = animalCounts[3] = 0;
    }
    if (totalAnimals == 0)            { resetCommand(); return CMD_NONE; }
    if (!SIO_HasSpace() || EEPROM_IsBusy()) return CMD_GET_ANIMALS;
    if (i == totalAnimals) {
        SIO_SendSimple(SEND_FINISH);
        resetCommand();
        i = 0;
        return CMD_NONE;
    }
    AnimalEEPROM an = EEPROM_ReadAnimal(i);
    unsigned char estat = EEPROM_GetEstat(an, DT_GetDia(), DT_GetMes(), DT_GetHora(), DT_GetMin(), DT_GetSeg());
    unsigned char numero = animalCounts[an.tipus];
    animalCounts[an.tipus]++;
    SIO_SendDataAnimal(an.tipus, numero, estat);
    i++;
    return CMD_GET_ANIMALS;
}
void motorParseCommand(){
    if (!getCmdReady()) return;
    unsigned char* c = getCommand();
    cmd_t cmd;
    switch (c[0]) {
        case 'I': cmd = CMD_INIT;            break;
        case 'P': cmd = CMD_GET_PRODUCTS;    break;
        case 'A': cmd = CMD_GET_ANIMALS;     break;
        case 'R': cmd = CMD_RESET;           break;
        case 'C': cmd = CMD_CONSUME;         break;
        case 'E': cmd = CMD_SLEEP;           break;
        case 'L': cmd = CMD_START_REBELLION; break;
        case 'S': cmd = CMD_STOP_REBELLION;  break;
        default:  cmd = CMD_UNKNOWN;         break;
    }
    

    switch (cmd) {
        case CMD_INIT: 
            DO_Initialize(); 

            break;
        case CMD_GET_ANIMALS: 
            cmd = handle_GetAnimals();
            
            break;
        case CMD_GET_PRODUCTS:    
            SIO_SendDataProducts(getNumLlet(), getNumPernil(), getNumHuevos(), getNumPinzells());
            
            cmd = CMD_NONE;
                  
            break;
        case CMD_CONSUME:   
            consume(getData()[0] - '0');
            cmd = CMD_NONE;
            
            
            break;
        case CMD_RESET:
            
            DO_Reset();   
            cmd = CMD_NONE; 
            break;
        case CMD_START_REBELLION: 
            stopHeartBeat(); 
            startRebelion();
            
            cmd = CMD_NONE;    
            break;
        case CMD_STOP_REBELLION: 
            startHeartBeat();
            stopRebelion();
            
            cmd = CMD_NONE; 
            break;
        case CMD_SLEEP:
            switch (sleep_state) {
                case 0: {  // primer tick: parsear datos e iniciar espera
                    unsigned char *d = getData();
                    if      (d[0]=='V')                sleep_tipus = 0;
                    else if (d[0]=='P' && d[1]=='O')   sleep_tipus = 1;
                    else if (d[0]=='C')                sleep_tipus = 2;
                    else if (d[0]=='G')                sleep_tipus = 3;
                    else { cmd = CMD_NONE; break; }
                    unsigned char k = 0;
                    while (d[k] != '$' && d[k] != '\0') k++;
                    sleep_num = d[k+1] - '0';
                    TI_ResetTics(16);
                    sleepReset();
                    sleep_state = 1;
                    break;
                }
                case 1:  // esperar 5 segundos
                    if ((unsigned int)TI_GetTics(16) > (unsigned int)TICKS_PER_5_SEC) {
                        if (!getSleep()) {
                            SIO_SendSimple(SEND_SLEEP_UNSUCCESSFUL);
                            sleepReset();
                            sleep_state = 0;
                            cmd = CMD_NONE;
                        } else {
                            sleep_j = 0; sleep_count = 0;
                            sleep_state = 2;
                        }
                    }
                    break;
                case 2:  // buscar animal en EEPROM: un animal por tick
                    if (EEPROM_IsBusy()) break;
                    if (sleep_j >= getNumTotalAnimals()) {
                        SIO_SendSimple(SEND_SLEEP_UNSUCCESSFUL);
                        sleepReset(); sleep_state = 0; cmd = CMD_NONE; break;
                    }
                    {
                        AnimalEEPROM an = EEPROM_ReadAnimal(sleep_j);
                        if (an.tipus == sleep_tipus) {
                            if (sleep_count == sleep_num) {
                                EEPROM_WriteAnimalSleep(sleep_j);
                                SIO_SendSimple(SEND_SLEEP_SUCCESSFUL);
                                sleepReset(); sleep_state = 0; cmd = CMD_NONE; break;
                            }
                            sleep_count++;
                        }
                        sleep_j++;
                    }
                    break;
            }
            break;
        
        default:                                         
            break;
            
            
            
        
    }
    if(cmd == CMD_NONE){
        resetCommand();
    }
    
}

