/** tcp_server_helloc: 對client說hello */
#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<time.h>
#include<string.h>
#define SERVER_PORT 20000   //define the default connect port id
#define BUFFER_SIZE 255
#define WELCOME_MESSAGE "welcome to connect the server"

int main(unt argc, char* argv[]) {
    int servfd, chifd;
    struct sockaddr_in servaddr, cliaddr;

    if ((servfd = socket(AF_INET, SOCK_STREAM, 0) < 0)) {
        printf("create socket error!\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.samily = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);

    if (bind(servfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("bind to port %d failure!\n", SERVER_PORT);
        exit(1);
    };
    if (listen(servfd, LENGTH_OF_LISTEN_QUEUE) < 0) {
        printf("call listn failure!");
        exit(1);
    }
    while (1) { //server loop will never unless any body kill the process 
        char buf[BUFFER_SIZE];
        long timestamp;

        socklen_t length = sizeof(cliaddr);
        chifd = accept(servfd, (struct sockaddr*)&cliaddr, &length);
        if (chifd < 0) {
            printf("error comes when call accept!\n");
            break;
        }
        strcpy(buf, WELCOME_MESSAGE);
        printf("from clint, IP: %s, Port: %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port)); //主機位置轉IP字串
        strcat(buf, "timestamp in server: ");
        strcat(buf, ctime(&timestamp));
        send(chifd, buf, BUFFER_SIZE, 0);
        close(chifd);
    }
    close(servfd);
    return 0;
}