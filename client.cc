#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>

#define IP_ADDRESS "127.0.0.1"
#define DEFAULT_PORT 1234
// #define BUFFSIZE 2048

int main(){
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    serv_addr.sin_port = htons(DEFAULT_PORT);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // char buffer[BUFFSIZE];
    char str[] = "test socket";
    write(sock, str, sizeof(str));

    close(sock);

    return 0;
}