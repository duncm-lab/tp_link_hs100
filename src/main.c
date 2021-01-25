#include "header/includes.h"
#include "header/defs.h"
#include "header/functions.h"


int main(int argc, char *argv[]){

    if (argc < 2){
        fprintf(stderr, "Missing command\n");
        exit(EXIT_FAILURE);
    }

    int status;

    // create and encrypt command to be sent to device
    SA_IN dv = device(DEVICE_PORT, DEVICE_IP);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    handle_error("socket", sock);

    // create a connection to the device
    status = connect(sock, (SA*) &dv, (socklen_t) sizeof(dv));
    handle_error("send: connect", status);


    response_t r;
    response_t *rptr;
    rptr = &r;
    rptr->sock = sock;
    pthread_t thread;

    status = pthread_create(&thread, NULL, listen_response, rptr);
    handle_error("pthread_create", status);

    device_send(sock, argv[1], dv, true);

    status = pthread_join(thread, NULL);
    handle_error("pthread_join", status);

    printf("%s\n", r.response);

    close(sock);

    return 0;
}
