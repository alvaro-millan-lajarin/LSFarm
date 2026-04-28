#ifndef _ADC2_H_
#define _ADC2_H_

void AD_Init(char quinCanal);
//Pre: quinCanal est� entre 0 i 12.
//Post: Prepara el microcontrolador per a que adquireixi del canal 
//      quinCanal.

void AD_IniciaConversio(void);
//Pre: -
//Post: D�na l?ordre al microcontrolador per a que executi la conversi�.

char AD_HiHaMostra(void);
//Pre: - 
//Post: Retorna 1 si s?ha acabat d?adquirir una mostra, 0 altrament

unsigned int AD_GetMostra(void);
//Pre: AD_HiHaMostra()
//Post: Retorna el valor de l?�ltima mostra capturada

void motorADC(void);

void sleepReset();
unsigned char getSleep();

#endif