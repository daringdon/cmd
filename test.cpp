#include <stdio.h>
#include <unistd.h>
#include "cmd_main.h"

int main()
{
    cmd_init();
    printf("welcome to cmd!\n");
    while(1)
    {
        sleep(1);
    }
    return 0;
}
