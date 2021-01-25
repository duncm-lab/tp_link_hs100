#ifndef DEFS_H
#define DEFS_H value

#define BUFFER 2048
 /* messages are prepended with 4 bytes for message size
  * information */

#define OFFSET 4

#define DEVICE_PORT 9999 //tp-link hs100 port
#define DEVICE_IP "192.168.1.237"

#define HOST_PORT 9002
#define HOSTIP "127.0.0.1"

#define KEY 171 //tp-link hs100 encryption key
#define SA_IN struct sockaddr_in
#define SA struct sockaddr
#define handle_error(func, status){ \
    if (status == -1){ \
        perror(func); \
        exit(EXIT_FAILURE); \
    } \
}

#endif /* ifndef DEFS_H */
