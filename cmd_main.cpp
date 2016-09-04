#include <iostream>
#include <vector>
#include <pthread.h>
#include <string>
#include <string.h>
#include "cmd_main.h"
#include "telnet_srv.h"

using namespace std;

int display_version(char ** str)
{
    strcpy(*str, "version 1.0\n");
    cout << "version 1.0" <<endl;
}
vector<cmd_type_S> g_cmd_list;

int cmd_execute(string command, string &response)
{
    int ret = 0;
    size_t len = g_cmd_list.size();
    for (size_t i = 0; i < len; i++)
    {
        if (command == g_cmd_list[i].cmd)
        {
            char str[256];
            char* p_str = str;
            ret = g_cmd_list[i].fun((char **)&(p_str));
            response = str;
            return ret;
        }
    }
    return 1;
}
int telnet_server_init()
{
    int ret = 0;
    pthread_t thread_id;
    ret = pthread_create(&thread_id, NULL, telnet_srv_init, NULL);
    return ret;
}
int cmd_register()
{
    cmd_type_S cmd;
    cmd.cmd = "display version";
    cmd.fun = display_version;
    cmd.help_str = "version";
    g_cmd_list.push_back(cmd);
    return 0;
}

int cmd_init()
{
    telnet_server_init();
    cmd_register();
    return 0;
}
