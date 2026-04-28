#include <xc.h>
#include "SIO2.h"

#define SIO_MSG_MASK  (SIO_MAX_MSG - 1)

static msg_t cola[SIO_MAX_MSG];
static unsigned char head = 0;
static unsigned char tail = 0;
static msg_t *msgActual = 0;
static unsigned char si = 0;
static unsigned char subestado = 0;
static unsigned char estado = 0;
static unsigned char digits[3];  // [0]=centenas [1]=decenas [2]=unidades

// si: 0=init(calcula digitos), 1=centenas, 2=decenas, 3=unidades, 4=terminador
static unsigned char sendNum(unsigned char n, unsigned char nextSub, unsigned char terminator) {
    if (si == 0) {
        unsigned char u = n;
        digits[0] = 0; digits[1] = 0;
        if      (u >= 200) { digits[0] = 2; u -= 200; }
        else if (u >= 100) { digits[0] = 1; u -= 100; }
        while (u >= 10) { digits[1]++; u -= 10; }
        digits[2] = u;
        si = digits[0] ? 1 : digits[1] ? 2 : 3;
    }
    if (si == 1) { SIO_PutChar('0' + digits[0]); si = 2; return 1; }
    if (si == 2) { SIO_PutChar('0' + digits[1]); si = 3; return 1; }
    if (si == 3) { SIO_PutChar('0' + digits[2]); si = 4; return 1; }
    si = 0;
    if (terminator == '$') { SIO_PutChar('$'); }
    else { SIO_PutChar('\r'); SIO_PutChar('\n'); }
    subestado = nextSub;
    return 0;
}

static unsigned char sendStr(const char *str, unsigned char nextSub) {
    if (str[si]) { SIO_PutChar(str[si++]); return 1; }
    si = 0;
    subestado = nextSub;
    return 0;
}

// Indexado desde SEND_SELECT (valor 3), offset = tipo - SEND_SELECT
const char * const msgSimple[] = {
    "SE\r\n",
    "MR\r\n",
    "F\r\n",
    "MU\r\n",
    "MD\r\n",
    "ML\r\n",
    "SS\r\n",
    "SU\r\n"
};

const char animalStr[] = "VPCG";

void SIO_Init(void) {
    RCSTA  = 0x90;
    SPBRG  = 0x10;
    SPBRGH = 0x04;
    TXSTA  = 0x26;
    BAUDCONbits.BRG16 = 1;
}

unsigned char SIO_TXAvail(void) { return PIR1bits.TXIF; }
void SIO_PutChar(unsigned char c) { 
    TXREG = c; }

unsigned char nextHead(unsigned char h) { return (h + 1) & SIO_MSG_MASK; }

unsigned char SIO_HasSpace(void)  { return (nextHead(head) != tail); }

unsigned char SIO_SetMsg(msg_t *msg) {
    unsigned char nh = nextHead(head);
    if (nh == tail) return 0;
    cola[head] = *msg;
    head = nh;
    return 1;
}

void SIO_SendSimple(send_t tipo) {
    msg_t m = {0};
    m.tipo = tipo;
    SIO_SetMsg(&m);
}

void SIO_SendDataAnimal(unsigned char tipus, unsigned char num, unsigned char estat) {
    msg_t m = {0};
    m.tipo        = SEND_DATA_ANIMAL;
    m.animalTipus = tipus;
    m.animalNum   = num;
    m.animalEstat = estat;
    SIO_SetMsg(&m);
}

void SIO_SendDataProducts(unsigned char llet, unsigned char pernil,
                          unsigned char ous,  unsigned char pinzell) {
    msg_t m = {0};
    m.tipo        = SEND_DATA_PRODUCTS;
    m.prodLlet    = llet;
    m.prodPernil  = pernil;
    m.prodOus     = ous;
    m.prodPinzell = pinzell;
    SIO_SetMsg(&m);
}

void motorSIO(void) {
    if (!SIO_TXAvail()) return;

    if (estado == 0) {
        if (tail == head) return;
        msgActual = &cola[tail];
        tail      = nextHead(tail);
        si = subestado = 0;
        estado = 1;
        return;
    }

    send_t tipo = msgActual->tipo;

    if (tipo >= SEND_SELECT) {
        const char *s = msgSimple[tipo - SEND_SELECT];
        if (s[si]) { SIO_PutChar(s[si++]); return; }
        msgActual = 0; si = subestado = estado = 0;
        return;
    }

    if (tipo == SEND_DATA_ANIMAL) {
        switch (subestado) {
            case 0:
                if (sendStr("DA:", 1)) return;
                break;
            case 1: {
                unsigned char t = msgActual->animalTipus;
                SIO_PutChar(animalStr[t < 4 ? t : 0]);
                subestado = 2;
                return;
            }
            case 2:
                SIO_PutChar('$'); subestado = 3; return;
            case 3:
                if (sendNum(msgActual->animalNum, 4, '$')) return;
                break;
            case 4: {
                const char *s = (msgActual->animalEstat == 0) ? "A\r\n" : "S\r\n";
                if (sendStr(s, 0)) return;
                msgActual = 0; si = subestado = estado = 0;
                return;
            }
        }
        return;
    }

    if (tipo == SEND_DATA_PRODUCTS) {
        switch (subestado) {
            case 0:
                if (sendStr("DP:", 1)) return;
                break;
            case 1: if (sendNum(msgActual->prodLlet,    2, '$')) return; break;
            case 2: if (sendNum(msgActual->prodPernil,  3, '$')) return; break;
            case 3: if (sendNum(msgActual->prodOus,     4, '$')) return; break;
            case 4:
                if (sendNum(msgActual->prodPinzell, 0, '\n')) return;
                msgActual = 0; si = subestado = estado = 0;
                return;
        }
    }
}

unsigned char SIO_RXAvail(void) { return PIR1bits.RCIF; }
unsigned char SIO_GetChar(void)  { return RCREG; }