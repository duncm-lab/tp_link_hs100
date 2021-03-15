#include "header/defs.h"

char * create_message(char *raw, bool enc){
    // create a message to send and optionally encrypt
    int len = strlen(raw);
    char *msg = malloc(sizeof(char) * len);
    memset(msg, '\0', len);

    if (enc == true){
        msg = msg_encrypt(raw);
    } else {
        for (int i = 0; raw[i] != '\0'; i++){
            unsigned int p = raw[i];
            msg[i] = p;
        }
    }

    return msg;
}

int device_send(int sock, char *cmd,  bool enc){
    /* @brief           connect to and send a command to a remove device
     * @param[sock]     established socket
     * @param[dv]       socket struct for device
     * @param[enc]      use encryption or not
     * @param[char*]    response from device
     */

    int status;

    // create and encrypt command to be sent to device
    char *command = cmd;
    char *msg = create_message(command, enc);
    int msg_len = strlen(msg);

    int out_len = ((sizeof(char) * msg_len)
            + (sizeof(char) * OFFSET));

    char msg_out[out_len];
    memset(msg_out, '\0', out_len);

    // prepend size information to message TODO make this a seperate function
    for (int i = 0; i < out_len; i++) {
        if (i < OFFSET -1){
            msg_out[i] = '\0';
        } if (i == OFFSET -1) {
            msg_out[i] = msg_len;
        } else if (i > OFFSET -1){
            msg_out[i] = msg[i-OFFSET];
        }
    }



    // send data to device
    status = send(sock, msg_out, out_len, 0);
    HANDLE_ERROR("send", status);
    printf("Data sent: %d\n", status);

    return 0;
}
