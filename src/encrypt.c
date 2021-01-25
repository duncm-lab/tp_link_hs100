#include "header/includes.h"
#include "header/defs.h"

char* encrypt(char *raw){
    /* apply encryption function to string
     *
     * @param[raw] - unencrypted string
     * @return[char*] - encrypted string
     */

    int key = KEY;
    int len = sizeof(char) * strlen(raw);
    char *msg = malloc(len);


    for (int i = 0; raw[i] != '\0'; i++){
        char p = raw[i];
        key ^= p;
        msg[i] = key;
    }
    return msg;
}
