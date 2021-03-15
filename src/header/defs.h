#ifndef DEFS_H
#define DEFS_H value

 /* messages are prepended with 4 bytes for message size
  * information */


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <ctype.h>

#define OFFSET 4
#define BUFFER 2048
#define PORT_SEP ":"


#define KEY 171 //tp-link hs100 encryption key
#define SA_IN struct sockaddr_in
#define SA struct sockaddr
#define HANDLE_ERROR(func, status){ \
    if (status == -1){ \
        perror(func); \
        exit(EXIT_FAILURE); \
    } \
}

typedef struct _command {
    char *command;
    int len;
    bool enc; //call encrypt function if true
} command_t;

typedef struct _message {
    int *msg;
    int len;
} message_t;

// struct for pthread listen_response
typedef struct _response {
    int sock;
    int len;
    char *response;
} response_t;


typedef struct _listener {
    int sock;
    struct sockaddr_in dst;
} listener_t;

// encryption functions
char* msg_encrypt(char *raw);
char* msg_decrypt(char *msg);


// messaging functions
char * create_message(char *raw, bool enc);
int device_send(int sock, char *cmd, bool enc);
void* listen_response(void* arg);


// socket functions
int new_socket(void);
struct sockaddr_in device(int port, char *ip);

// command functions
char * read_cmd_file(void);
char * get_command(char *cmd);

#endif /* ifndef DEFS_H */
