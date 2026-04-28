#include <xc.h>
#include "LcTLCD.h"
#include "TIMER2.h"
#include "DATA_TIME.h"
#include "FARM.h"
#include "game.h"

static unsigned char lcdTimer = 17;
static unsigned char motorTimer = 18;
static unsigned char lcdResetReq = 0;

void LcResetMotor(void) { lcdResetReq = 1; }

#define QUEUE_CAP  4
#define QUEUE_MASK 0x03

static Notificacio   Queue[QUEUE_CAP];
static unsigned char q_size = 0;
static unsigned char head   = 0;
static unsigned char tail   = 0;

#define QueueIsEmpty() (q_size == 0)
#define QueueIsFull()  (q_size >= QUEUE_CAP)
#define CantaIR(ir)  cantaByte((ir), 0)
#define CantaData(d) cantaByte((d),  1)

void addMsgToQueue(Notificacio n) {
    if (QueueIsFull()) return;
    Queue[tail] = n;
    tail = (tail + 1) & QUEUE_MASK;
    q_size++;
}

static Notificacio pop(void) {
    Notificacio n = Queue[head];
    head = (head + 1) & QUEUE_MASK;
    q_size--;
    return n;
}

// --- Strings en ROM ---
static const char s0[] = "Nou Animal";
static const char s1[] = "Nou Producte";
static const char s2[] = "Vaca";
static const char s3[] = "Gallina";
static const char s4[] = "Porc";
static const char s5[] = "Cavall";
static const char s6[] = "Llet";
static const char s7[] = "Ou";
static const char s8[] = "Pernil";
static const char s9[] = "Pinzell";
// 1D flat table: [0-3]=animals, [4-7]=products (same order as tipus 0-3)
static const char * const NOMS_FLAT[8] = {s2, s4, s5, s3, s6, s8, s9, s7};


static void cantaNibble(unsigned char c) {
    LATD = (LATD & 0x0F) | (c << 4);  
}


static void esperaMs(unsigned int ms) {
    TI_ResetTics(lcdTimer);
    while ((unsigned int)TI_GetTics(lcdTimer) < ms);
}


static void cantaByte(unsigned char val, unsigned char rs) {
    SetD4_D7Sortida();
    if (rs) RSUp(); else RSDown();
    RWDown();
    EnableUp();
    cantaNibble(val >> 4);
    EnableDown();
    EnableUp();
    cantaNibble(val & 0x0F);
    EnableDown();
    SetD4_D7Entrada();
}


void LcInit(char rows, char columns) {
    SetControlsSortida();
    esperaMs(192);
    SetD4_D7Sortida(); RSDown(); RWDown();
    EnableUp(); cantaNibble(0x03); EnableDown(); esperaMs(24);
    EnableUp(); cantaNibble(0x03); EnableDown(); esperaMs(5);
    EnableUp(); cantaNibble(0x03); EnableDown(); esperaMs(5);
    EnableUp(); cantaNibble(0x02); EnableDown(); esperaMs(5);
    CantaIR(0x28);
    CantaIR(0x08);
    CantaIR(0x01);
    esperaMs(8);
    CantaIR(0x06);
    CantaIR(0x0C);
    
}



void LcClear(void) {
    CantaIR(0x01);
}

void LcGotoXY(char Column, char Row) {
    CantaIR(0x80 | (Column + (Row ? 0x40 : 0)));
}

void LcPutChar(char c) {
    CantaData(c);
}


void MotorLCD(void) {
    static unsigned char state      = 11;
    static unsigned char next_state = 0;
    static Notificacio   current;
    static const char   *str        = 0;
    static unsigned char index      = 0;
    static char          num_buf[7];
    static unsigned char idleShown  = 0;
    static unsigned char lcd_delay  = 0;

    if (lcdResetReq) { lcdResetReq = 0; state = 11; }
    switch (state) {
        case 0:
            if (!idleShown && startGameOk()) {
                idleShown  = 1;
                str        = (const char*)getFarmName();
                index      = 0;
                LcClear();
                TI_ResetTics(lcdTimer);
                lcd_delay  = 8;
                next_state = 9;
                state      = 8;
            }
            if (!QueueIsEmpty()) { idleShown = 0; state = 2; }
            break;

        case 1: {
            // Fecha DD/MM/2026: index=0 hace LcGotoXY, index=1..10 escribe chars
            if ((unsigned int)TI_GetTics(lcdTimer) < 2) break;
            TI_ResetTics(lcdTimer);
            if (index == 0) { LcGotoXY(0, 1); index = 1; break; }
            unsigned char pos = index - 1;
            unsigned char d = DT_GetDia(), m = DT_GetMes();
            unsigned char d0=0,d1=d,m0=0,m1=m,c;
            if(d1>=20){d0=2;d1=(unsigned char)(d1-20);}
            else if(d1>=10){d0=1;d1=(unsigned char)(d1-10);}
            if(m1>=10){m0=1;m1=(unsigned char)(m1-10);}
            switch(pos){
                case 0:c='0'+d0;break; case 1:c='0'+d1;break; case 2:c='/';break;
                case 3:c='0'+m0;break; case 4:c='0'+m1;break; case 5:c='/';break;
                case 6:c='2';break;    case 7:c='0';break;    case 8:c='2';break;
                default:c='6';break;
            }
            LcPutChar(c);
            if (++index > 10) { index = 0; state = 0; }
            break;
        }

        case 2:
            current = pop();
            LcClear();
            TI_ResetTics(lcdTimer);
            lcd_delay  = 8;
            next_state = 10;
            state      = 8;
            break;

        case 3:
            if ((unsigned int)TI_GetTics(lcdTimer) < 2) break;
            TI_ResetTics(lcdTimer);
            LcGotoXY(0, 1);
            {
                unsigned char idx = current.nombre;
                if (idx > 3) idx = 3;
                if (current.tipo != 'A') idx = (unsigned char)(idx + 4);
                str = NOMS_FLAT[idx];
            }
            index      = 0;
            next_state = 4;
            state      = 6;
            break;

        case 4: {
            unsigned char n=current.num,i=0,h=0;
            num_buf[i++]=':'; num_buf[i++]=' ';
            if(n>=200){h=2;n=(unsigned char)(n-200);}
            else if(n>=100){h=1;n=(unsigned char)(n-100);}
            if(h) num_buf[i++]='0'+h;
            if(h||n>=10){unsigned char t=0;
                while(n>=10){t++;n=(unsigned char)(n-10);}
                num_buf[i++]='0'+t;}
            num_buf[i++]='0'+n; num_buf[i]='\0';
            str=num_buf; index=0; next_state=5; state=6;
            break;
        }

        case 5:
            TI_ResetTics(motorTimer);
            state = 7;
            break;

        case 6:
            if ((unsigned int)TI_GetTics(lcdTimer) < 2) break;
            if (str[index] == '\0') { index = 0; state = next_state; break; }
            TI_ResetTics(lcdTimer);
            LcPutChar(str[index++]);
            break;

        case 7:
            if ((unsigned int)TI_GetTics(motorTimer) >= TICS_3S) {
                idleShown = 0; state = 0;
            }
            break;

        // --- estados de espera/goto post-clear ---
        case 8:
            if ((unsigned int)TI_GetTics(lcdTimer) >= lcd_delay)
                state = next_state;
            break;

        case 9:  // goto(0,0) + enviar nombre granja -> state 1
            TI_ResetTics(lcdTimer);
            LcGotoXY(0, 0);
            next_state = 1;
            state      = 6;
            break;

        case 10:  // goto(0,0) + enviar cabecera notificacion -> state 3
            TI_ResetTics(lcdTimer);
            LcGotoXY(0, 0);
            str        = (current.tipo == 'A') ? s0 : s1;
            index      = 0;
            next_state = 3;
            state      = 6;
            break;

        case 11:  // clear inicial al arrancar
            head = tail = q_size = 0; 
            LcClear();
            TI_ResetTics(lcdTimer);
            lcd_delay  = 8;
            next_state = 0;
            state      = 8;
            break;
    }
}