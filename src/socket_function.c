#include "header/defs.h"

int new_socket(void){
    // create and return a new socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    HANDLE_ERROR("socket", sock);
    return sock;
}

struct sockaddr_in device(int port, char *ip){
    // create and return a socket structure
    SA_IN dev;
    memset(&dev, '\0', sizeof(dev));
    dev.sin_family = AF_INET;
    dev.sin_port = htons(port);
    memset(dev.sin_zero, 0, sizeof(char) * 8);
//    dev.sin_addr.s_addr = inet_addr(ip);
    int set_ip = inet_pton(AF_INET, ip, &(dev.sin_addr.s_addr));
    HANDLE_ERROR("inet_pton", set_ip);
    return dev;
}
