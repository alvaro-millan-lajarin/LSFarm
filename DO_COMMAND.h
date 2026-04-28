#ifndef _PARSE_COMMAND_H_
#define _PARSE_COMMAND_H_

typedef enum {
    CMD_NONE,
    CMD_INIT,
    CMD_GET_ANIMALS,
    CMD_GET_PRODUCTS,
    CMD_CONSUME,
    CMD_RESET,
    CMD_START_REBELLION,
    CMD_STOP_REBELLION,
    CMD_SLEEP,
    CMD_UNKNOWN
} cmd_t;
void motorParseCommand();


#endif