#ifndef TTL_MANUAL_SEND_H
#define TTL_MANUAL_SEND_H

void motorSIOSend();
void uartTX(unsigned char d);

void SIO_Manual_SetFrase(unsigned char *msg);


#endif