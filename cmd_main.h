#ifndef CMD_MAIN_H
#define CMD_MAIN_H

#include <string>

typedef struct
{
    char* cmd; 
    int (*fun)(char**);
    char* help_str;
}cmd_type_S;

int cmd_init();
int cmd_execute(std::string command, std::string &response);

#endif  /*CMD_MAIN_H*/
