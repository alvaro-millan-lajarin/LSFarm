#ifndef PRODUCTS_H_
#define PRODUCTS_H_

#define TIMER_HANDLE_COW_PRODUCT 8
#define TIMER_HANDLE_PIG_PRODUCT 9
#define TIMER_HANDLE_HORSE_PRODUCT 10
#define TIMER_HANDLE_CHICKEN_PRODUCT 11

void setStartProducts();
unsigned char getNumLlet(void);
unsigned char getNumPernil(void);
unsigned char getNumPinzells(void);
unsigned char getNumHuevos(void);
void motorProducts();
void resetProducts();
void stopRebelion();
void startRebelion();
void consume(unsigned char tipo);


#endif