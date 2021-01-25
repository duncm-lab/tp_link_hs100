#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "header/settings.h"
#include "header/socket_functions.h"


int main(void){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    handle_error("socket", sock);
    struct sockaddr_in v_plug, v_host;
    v_plug = device(9999, PLUGIP);
    v_host = device(HOST_PORT, HOSTIP);

    int b = bind(sock, (struct sockaddr*) &v_host, sizeof(v_host));
    handle_error("bind", b);

    int lstn = listen(sock, 5);
    handle_error("listen", lstn);
    int slen = sizeof(v_plug);
    int acc = accept(sock, (struct sockaddr*) &v_plug, (socklen_t*) &slen);
    handle_error("accept", acc);


}
