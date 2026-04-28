#ifndef LcTLCD_H
#define LcTLCD_H

#include <xc.h>

// ---- Hardware ----
#define SetD4_D7Sortida()    (TRISDbits.TRISD4 = TRISDbits.TRISD5 = TRISDbits.TRISD6 = TRISDbits.TRISD7 = 0)
#define SetD4_D7Entrada()    (TRISDbits.TRISD4 = TRISDbits.TRISD5 = TRISDbits.TRISD6 = TRISDbits.TRISD7 = 1)
#define SetControlsSortida() (TRISDbits.TRISD3 = TRISDbits.TRISD2 = TRISDbits.TRISD1 = 0)
#define SetD4(On)            (LATDbits.LATD4 = (On))
#define SetD5(On)            (LATDbits.LATD5 = (On))
#define SetD6(On)            (LATDbits.LATD6 = (On))
#define SetD7(On)            (LATDbits.LATD7 = (On))
#define GetBusyFlag()        (PORTDbits.RD7)
#define RSUp()               (LATDbits.LATD1 = 1)
#define RSDown()             (LATDbits.LATD1 = 0)
#define RWUp()               (LATDbits.LATD2 = 1)
#define RWDown()             (LATDbits.LATD2 = 0)
#define EnableUp()           (LATDbits.LATD3 = 1)
#define EnableDown()         (LATDbits.LATD3 = 0)

// ---- Constantes LCD ----
#define FUNCTION_SET    0x20
#define DISPLAY_CONTROL 0x08
#define DISPLAY_ON      0x04
#define CURSOR_ON       0x02
#define DISPLAY_CLEAR   0x01
#define SET_DDRAM       0x80

// 3000 como unsigned int: evita comparaciones de 32 bits
#define TICS_3S         ((unsigned int)14423)

// ---- Tipo notificacion ----
typedef struct {
    char          tipo;    // 'A' = Animal, otro = Producte
    unsigned char nombre;  // 0-3
    unsigned char num;     // 0-19
} Notificacio;

// ---- API publica ----
void LcInit(char rows, char columns);
void LcEnd(void);
void LcClear(void);
void LcGotoXY(char Column, char Row);
void LcPutChar(char c);

// ---- Motor ----
void addMsgToQueue(Notificacio n);
void MotorLCD(void);
void LcResetMotor(void);

void newGameFunc();

#endif