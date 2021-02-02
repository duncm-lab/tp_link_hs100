#include "header/includes.h"
#include "header/defs.h"
#include "header/functions.h"

void* listen_response(void* arg){
    // listen for responses from device

    response_t *r = (response_t*) arg;
    int *x = &r->sock;
    int sock = *x;
    handle_error("listener socket", sock);


    // receive data from device
    char response_msg[BUFFER];
    size_t rsize = sizeof(char) * BUFFER;
    int response_size = read(r->sock, &response_msg, rsize);
    handle_error("read", response_size);
    printf("Data received: %d\n", response_size);

    r->response = malloc(sizeof(char) * response_size);
    for (int i = OFFSET; response_msg[i] != '\0'; i++) {
        r->response[i-OFFSET] = response_msg[i];
    }
    r->len = strlen(r->response);
    return NULL;
}
