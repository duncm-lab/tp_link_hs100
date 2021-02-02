#include "header/includes.h"
#include "header/defs.h"
#include "header/functions.h"

void help(void){
    FILE *fl = fopen("help.txt", "r");
    fseek(fl, 0, SEEK_END);
    int fsize = ftell(fl);
    rewind(fl);

    char buf[fsize];
    memset(buf, '\0', sizeof(char) * fsize);
    fread(&buf, 1, fsize, fl);
    fprintf(stdout, "%s\n", buf);
}

int main(int argc, char *argv[]){

    if (strcmp(argv[1], "help") == 0){
        help();
        exit(EXIT_SUCCESS);
    }


    if (argc < 3){
        fprintf(stderr, "Missing arguments\n");
        exit(EXIT_FAILURE);
    }


    int status;

    // create and encrypt command to be sent to device
    SA_IN dv = device(DEVICE_PORT, argv[1]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    handle_error("socket", sock);

    // create a connection to the device
    status = connect(sock, (SA*) &dv, (socklen_t) sizeof(dv));
    handle_error("send: connect", status);


    response_t r;
    r.sock = sock;
    pthread_t thread;

    status = pthread_create(&thread, NULL,
                            listen_response,
                            &r);

    handle_error("pthread_create", status);

    device_send(sock, argv[2], dv, true);

    status = pthread_join(thread, NULL);
    handle_error("pthread_join", status);

    char buf[r.len];

    decrypt(r.response, buf);
    printf("%s\n", buf);


    close(sock);

    return 0;
}
