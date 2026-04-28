#ifndef FARM_H_
#define FARM_H_

#define TIMER_HANDLE_COW 0
#define TIMER_HANDLE_PIG 1
#define TIMER_HANDLE_HORSE 2
#define TIMER_HANDLE_CHICKEN 3

typedef enum {
    COW,
    PIG,
    HORSE,
    CHICKEN
} TipusAnimal;


unsigned char* getFarmName();
void DO_SetAnimalTime(unsigned char tipus, unsigned int time);


void DO_SetFarmName(unsigned char *field);


unsigned char tempsFarmsOk();
void setTempsFarmsOk();
void setStartFarm();

unsigned char getNumTotalAnimals();
void resetFarm();
void motorFarm();

unsigned char getFarmNameReady(void);

#endif