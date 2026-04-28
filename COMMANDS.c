/*
 * File:   COMMANDS.c
 * Author: alvar
 *
 * Created on 17 de marzo de 2026, 10:01
 */


#include <xc.h>
#include "COMMANDS.h"
#include "SIO2.h"


unsigned char COMMAND[23] = "";      
unsigned char *DATA = COMMAND;        //para reutilizar memoria

unsigned char cmd_ready = 0;

unsigned char getCmdReady(){

    return cmd_ready;
}
unsigned char* getData(){
    return DATA;
}
unsigned char* getCommand(){
    return COMMAND;
}
void resetCommand(){
    COMMAND[0] = '\0';
    DATA = COMMAND;
    cmd_ready = 0;
}


void motorRecieveCommand() {
    
    static unsigned char estat = 0;
    static unsigned char c = 0;
    static unsigned char i = 0;
    
    
    switch(estat){

        case 0:
            if (SIO_RXAvail()){
                c = SIO_GetChar();
                estat ++;
                
            }
            break;
        case 1:
            if(c == '\n'){
                estat++;
                COMMAND[i] = '\0';                
                i = 0;                      
            }else{
                COMMAND[i] = c;
                i++;     
                estat--;
            }
            break;
        case 2:
            if(COMMAND[i] != '\0' && COMMAND[i] != ':'){
                i++;                
            }else{
                estat++;
            }
            break;
        case 3:
            if (COMMAND[i] == ':') {
                COMMAND[i] = '\0';  
                i++;   
            } 
            DATA = &COMMAND[i]; 
            estat++;
            
            break;
        case 4:
            i = 0;
            estat = 0;
            cmd_ready = 1;
 
            break;
        
        default:

            break;
    }
}
