#include "header/commands.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool compare(char *val, char *exp){
    int ret;
    if (strcmp(val, exp) == 0){
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}

char * new_command(char * comm){
    char *cmd;
    int len = strlen(comm);
    cmd = malloc(sizeof(char) * len);
    cmd = comm;
    return cmd;
}



char * select_command(char *comm){
    char *cmd;
    if (compare(comm,        "info")){
        cmd = new_command(INFO);
    } else if (compare(comm, "on")){
        cmd = new_command(ON);
    } else if (compare(comm, "off")){
        cmd = new_command(OFF);
    } else if (compare(comm, "ledoff")){
     cmd = new_command(LEDOFF);
    } else if (compare(comm, "ledon")){
     cmd = new_command(LEDON);
    } else if (compare(comm, "cloudinfo")){
     cmd = new_command(CLOUDINFO);
    } else if (compare(comm, "wlanscan")){
     cmd = new_command(WLANSCAN);
    } else if (compare(comm, "time")){
     cmd = new_command(TIME);
    } else if (compare(comm, "schedule")){
     cmd = new_command(SCHEDULE);
    } else if (compare(comm, "countdown")){
     cmd = new_command(COUNTDOWN);
    } else if (compare(comm, "antitheft")){
     cmd = new_command(ANTITHEFT);
    } else if (compare(comm, "reboot")){
     cmd = new_command(REBOOT);
    } else if (compare(comm, "reset")){
     cmd = new_command(RESET);
    } else if (compare(comm, "energy")){
     cmd = new_command(ENERGY);
    } else {
        fprintf(stderr, "Unknown command");
        exit(EXIT_FAILURE);
    }
    return cmd;
}
