#ifndef SIO2_H
#define SIO2_H




#define SIO_MAX_MSG   2
#define MAX_STR_LEN   35   // buffer temporal para generar mensaje

typedef enum {
    SEND_NONE = 0,
    SEND_DATA_ANIMAL,
    SEND_DATA_PRODUCTS,
    SEND_SELECT,
    SEND_RIGHT,       
    SEND_FINISH,
    SEND_UP,
    SEND_DOWN,
    SEND_LEFT,
    SEND_SLEEP_SUCCESSFUL,
    SEND_SLEEP_UNSUCCESSFUL        
    
} send_t;

// Struct para la cola de mensajes
typedef struct {
    send_t tipo;
    unsigned char animalTipus;  // 0=COW,1=PIG,2=HORSE,3=CHICKEN
    unsigned char animalNum;
    unsigned char animalEstat;  // 0=AWAKE, 1=SLEEP
    unsigned char prodLlet;
    unsigned char prodPernil;
    unsigned char prodOus;
    unsigned char prodPinzell;
} msg_t;

void SIO_SendSelect();
void SIO_SendDataAnimal(unsigned char tipus, unsigned char num, unsigned char estat);
void SIO_SendDataProducts(unsigned char llet, unsigned char pernil, unsigned char ous, unsigned char pinzell);
void SIO_SendSimple(send_t tipo);
unsigned char SIO_IsBusy(void);




void SIO_Init(void);
// Post: Configuraci� de la UART en mode ass�ncron, 9600 bauds, suposant fOsc=10MHz., precondicio per la resta de funcions

void SIO_InterrupcioRX (void) ;
// Pre: Es crida des de la RSI PIR1bits.RCIF==1 i PIE1bits.RCIE==1.
// Post: Processa la interrupci� a la RX d'un char.

unsigned char SIO_RXAvail(void);
//Post: Retorna el nombre de car�cters disponibles a la cua de RX.

unsigned char SIO_GetChar(void);
// Pre: SIO_CharAvail() ha retornat CERT.
// Post: Fa lectura destructiva del car�cter rebut.

void SIO_End (void);
// Post: Destructor del TAD. No fa res, realment...




//transmisio

void SIO_InterrupcioTX (void) ;
// Pre: Es crida des de la RSI PIR1bits.TXIF==1 i PIE1bits.TXIE==1.
// Post: Processa la interrupci� a la TX d'un char.

unsigned char SIO_TXAvail(void);
//Post: Retorna el nombre de car�cters disponibles a la cua de TX. 0 si no hi ha espai, i fins a MAX_TX si est� buida.

void SIO_PutChar (unsigned char Valor);
// Pre: SIO_TXAvail() ha retornat CERT.
// Post: Posa un nou car�cter a enviament.

void motorSIO();



// Pre: SIO_TXAvail() ha retornat >= strlen (LaFrase).
// Post: Posa la frase a la cua d'enviament.

void MotorSIO();

unsigned char SIO_SetMsg(msg_t *m);

unsigned char SIO_HasSpace();
unsigned char nextHead(unsigned char h);



#endif