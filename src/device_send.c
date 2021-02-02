#include "header/includes.h"
#include "header/defs.h"
#include "header/functions.h"

char * create_message(char *raw, bool enc){
    // create a message to send and optionally encrypt
    int len = strlen(raw);
    char *msg = malloc(sizeof(char) * len);
    memset(msg, '\0', len);

    if (enc == true){
        msg = encrypt(raw);
    } else {
        for (int i = 0; raw[i] != '\0'; i++){
            unsigned int p = raw[i];
            msg[i] = p;
        }
    }

    return msg;
}

int device_send(int sock, char *cmd, SA_IN dv, bool enc){
    /* connect to and send a command to a remove device
     * @param[sock] established socket
     * @param[dv] socket struct for device
     * @param[enc] use encryption or not
     *
     * @return[char*] response from device
     */

    int status;

    // create and encrypt command to be sent to device
    char *command = select_command(cmd);
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
    handle_error("send", status);
    printf("Data sent: %d\n", status);


    return 0;
}
