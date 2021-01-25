#ifndef OBJECTS_H
#define OBJECTS_H

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
    char *response;
} response_t;


typedef struct _listener {
    int sock;
    struct sockaddr_in dst;
} listener_t;

#endif /* ifndef OBJECTS_H */
