#include "header/defs.h"


char * read_cmd_file(void){
    /* @brief read the contents of the "commands" file
     * @param[cmdfile]  char array of "commands" file contents
     */
    int status;
    FILE *fl = fopen("commands", "r");
    fseek(fl, 0, SEEK_END);
    int len = ftell(fl) -1;
    char *cmdfile = malloc(sizeof(char) * len);
    rewind(fl);
    status = fread(cmdfile, 1, len, fl);
    HANDLE_ERROR("fread", status);
    return cmdfile;
}

char * get_command(char *cmd){
    /*  Lookup and return the command in the char array of "commands" file
     *  @param[*cmd]        Key to look for
     *  @param[*command]    JSON command from file
     */
    char *line = malloc(sizeof(char));
    char *k = strstr(read_cmd_file(), cmd);
    int idx = 0;

    do {
        line[idx] = k[idx];
        ++idx;
        line = realloc(line, sizeof(char) * idx +1);
    } while (k[idx] != ';');
    strtok(line, " ");
    char *command = strtok(NULL, " ");
    return command;
}
