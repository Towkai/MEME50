/** echo a letter. */
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define BUFFER_SIZE 256

int main(void) {
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;

    /** Create a socket for the client. */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /** Name the socket, as agree with the server. */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9734;
    len = sizeof(address);

    /** Now connect our socket to the server's socket */
    result = connect(sockfd, (struct sockaddr*)&address, len);
    if (result == -1) {
        perror("oops: client2");
        exit(1);
    };

    char* exit_key = "__exit";
    printf("sockfd: %d, Enter '%s' to exit: \n", sockfd, exit_key);
    while (1) {
        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);
        if (strncmp(input, exit_key, strlen(exit_key)) == 0) {
            break;
        }
        /** We can now read/write via sockfd */    
        write(sockfd, input, strlen(input)-1);
        read(sockfd, input, strlen(input)-1);
    }
    
    close(sockfd);
    exit(0);
}