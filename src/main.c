#include "header/defs.h"

void help(void){
    int status;
    FILE *fl = fopen("help.txt", "r");
    fseek(fl, 0, SEEK_END);
    int fsize = ftell(fl);
    rewind(fl);

    char buf[fsize];
    memset(buf, 0, sizeof(char) * fsize);
    status = fread(&buf, 1, fsize-1, fl);
    HANDLE_ERROR("fread - help", status);
    printf("%s\n", buf);
}

int main(int argc, char *argv[]){
    /* -d device -c command
     * -h help
     */

    if (strcmp(argv[1], "-h") == 0){
        help();
        exit(EXIT_SUCCESS);
    }


    if (argc < 3){
        fprintf(stderr, "Missing arguments\n");
        exit(EXIT_FAILURE);
    }

    int opt = -1;
    char *port_cmd = NULL;
    int port = -1;
    char *host = NULL;
    char *command = NULL;
    int cmd_len;

    while ((opt = getopt(argc, argv, "d:c:h")) != -1){
        switch (opt){
            case 'd': // device:port
                host = strtok(optarg, PORT_SEP);
                port_cmd = strtok(NULL, PORT_SEP);
                break;
            case 'c': // command
                cmd_len = strlen(optarg);
                command = malloc(sizeof(char) * cmd_len);
                for (int i = 0; i < cmd_len; i++){
                    command[i] = toupper(optarg[i]);
                }
                break;
            case 'h':
                help();
                break;
            default:
                fprintf(stderr, "invalid option");
                exit(EXIT_FAILURE);

        }
    }

    if (host == NULL || port_cmd == NULL){
        fprintf(stderr, "Host and port must be provided\n");
        exit(EXIT_FAILURE);
    } else {
        port = atoi(port_cmd);
    }


    int status;

    // create and encrypt command to be sent to device
    SA_IN dv = device(port, host);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    HANDLE_ERROR("socket", sock);

    // create a connection to the device
    status = connect(sock, (SA*) &dv, (socklen_t) sizeof(dv));
    HANDLE_ERROR("send: connect", status);


    response_t r;
    r.sock = sock;
    pthread_t thread;

    status = pthread_create(&thread, NULL,
                            listen_response,
                            &r);

    HANDLE_ERROR("pthread_create", status);

    device_send(sock, get_command(command), true);

    status = pthread_join(thread, NULL);
    HANDLE_ERROR("pthread_join", status);


    char *response = decrypt(r.response);
    printf("%s\n", response);


    close(sock);

    return 0;
}
