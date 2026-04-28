#ifndef EEPROM_H_
#define EEPROM_H_

// Layout EEPROM:
// Animal i empieza en: i * 6
// Byte 0: tipus
// Byte 1: dia ultimo sleep
// Byte 2: mes ultimo sleep
// Byte 3: hora ultimo sleep
// Byte 4: min ultimo sleep
// Byte 5: seg ultimo sleep

#define ANIMAL_SIZE 6
#define EEPROM_ADDR(i) ((i) * ANIMAL_SIZE)

typedef struct {
    unsigned char tipus;  // COW, PIG, HORSE, CHICKEN
    unsigned char dia;
    unsigned char mes;
    unsigned char hora;
    unsigned char min;
    unsigned char seg;
} AnimalEEPROM;

unsigned char EEPROM_IsBusy();
void EEPROM_WriteAnimal(unsigned char index, unsigned char tipus);

void EEPROM_WriteAnimalSleep(unsigned char index);

AnimalEEPROM EEPROM_ReadAnimal(unsigned char index);


unsigned char EEPROM_GetEstat(AnimalEEPROM a, unsigned char diaAct, unsigned char mesAct,
                              unsigned char horaAct, unsigned char minAct, unsigned char segAct);

//unsigned char getAnimalNumero(unsigned char i);

void motorEEprom(void);

#endif