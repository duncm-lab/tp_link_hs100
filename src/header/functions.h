#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// encryption functions
char* encrypt(char *raw);
char decrypt(char *msg);


// messaging functions
char * create_message(char *raw, bool enc);
int device_send(int sock, char *cmd, SA_IN dv, bool enc);
void* listen_response(void* arg);


//socket functions
int new_socket(void);
struct sockaddr_in device(int port, char *ip);

#endif /* ifndef FUNCTIONS_H */
