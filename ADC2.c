#include <xc.h>
#include "ADC2.h"
#include "SIO2.h"
#include "TIMER2.h"



#define TICKS_PER_MEDIO_SEC 2404
#define CANAL_LIGHT      2


static unsigned int lightValue = 0;
static unsigned char sleep = 0;

void sleepReset(){
    sleep = 0;
}
unsigned char getSleep(){
    return sleep;
}
void AD_Init(char quinCanal)
{
    TRISA =0xFF;   // pin como entrada

    ADCON1 = 0x0C;               
    ADCON2 = 0x91;               // justificaci�n derecha

    ADCON0 = (quinCanal << 2);   // seleccionar canal
    ADCON0bits.ADON = 1;         // encender ADC
}

void AD_IniciaConversio(void)
{
    ADCON0bits.GO = 1;     // Iniciar conversi�n
}

char AD_HiHaMostra(void)
{
    if(ADCON0bits.GO == 0)
        return 1;          
    else
        return 0;
}

unsigned int AD_GetMostra(void)
{
    return ((unsigned int)ADRESH << 8) | ADRESL;
}

void motorADC(void)
{
    static unsigned char estat = 0;
    static unsigned int valor;
    static unsigned char canal = 0; // 0=X , 1=Y
    static unsigned int joystickX = 0;
    static unsigned int joystickY = 0;
    static unsigned char blockLeft = 0;
    static unsigned char blockRight = 0;
    static unsigned char blockUp = 0;
    static unsigned char blockDown = 0;
    

    switch(estat)
    {
        case 0:
            ADCON0bits.CHS = canal;   // seleccionar canal
            AD_IniciaConversio();
            estat++;
            break;

        case 1:
            if(AD_HiHaMostra())
            {
                valor = AD_GetMostra();

                if(canal == 0){
                    joystickX = valor;
                }
                else if(canal == 1){
                    joystickY = valor;
                }else{
                    lightValue = valor;
                    estat = 3;
                    break;
                }

                canal++;
                estat++;
            }
            break;
        case 2:
            
            if((unsigned int)TI_GetTics(13) > (unsigned int)TICKS_PER_MEDIO_SEC){
                blockLeft = 0;
                blockRight = 0;
                blockUp = 0;
                blockDown = 0;
                
            }
            
            
            if(joystickX < 350 && !blockLeft){
                
                SIO_SendSimple(SEND_LEFT);

                blockLeft = 1;
                TI_ResetTics(13);
                
            }
            else if(joystickX > 700 && !blockRight){
                SIO_SendSimple(SEND_RIGHT);
                
                blockRight = 1;
                TI_ResetTics(13);
            }
            else if(joystickY < 350 && !blockUp){
                SIO_SendSimple(SEND_UP);
                
                blockUp = 1;
                TI_ResetTics(13);
            }
            else if(joystickY > 700 && !blockDown){
                SIO_SendSimple(SEND_DOWN);
            
                blockDown = 1;
                TI_ResetTics(13);
            }
            
            estat = 0;
            break;
        case 3:
            if(lightValue > 800){ 
                //LATAbits.LATA3 = 1;
                
            }else{
                sleep = 1;
                //LATAbits.LATA3 = 0;
            
            }
            canal = 0;
            estat = 0;
            break;
        default:
            break;
    }
}