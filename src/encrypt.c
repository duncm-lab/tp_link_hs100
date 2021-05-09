#include "header/defs.h"


/*
 * Code taken from https://github.com/softScheck/tplink-smartplug/blob/master/tplink_smartplug.py
 */

char* msg_encrypt(char *raw){
    /* @brief           apply encryption to a message being sent to the plug
     * @param[raw]      unencrypted string
     * @param[char*]    encrypted string
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

char * msg_decrypt(char *msg){
    /* @brief       Decrypt the message returned from the plug
     * @param[*msg] Message returned from plug
     * @param[*buf] location to write the decrypted string to
     */
    int key = KEY;

    int msglen = strlen(msg);

    char *buf = malloc(sizeof(char) * msglen);


    for (int i = 0; i < msglen; i++) {
        int p = msg[i];
        int q = key ^ p;
        key ^= p;
        key = p;
        buf[i] = q;
    }
    return buf;

}
