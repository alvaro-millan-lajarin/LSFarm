#ifndef COMMANDS_H_
#define COMMANDS_H_

unsigned char* getCommand();
unsigned char* getData();
void motorRecieveCommand();
unsigned char getCmdReady();
void resetCommand();

#endif