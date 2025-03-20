/** echo a letter. */
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(void) {
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address, client_address;

    /** Create an unnameed socket for the server. */
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /** Name the socket. */
    server_address.sin_family = AF_INFT;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9734;
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct  socketaddr*)&server_address, server_len);
    
    /** Create a connection queue and wait for clients. */
    listen(server_sockfd, 5);
    while (1)
    {
        char ch;
        printf("server waiting\n");
    }
    
    /** Accept a connection. */
    client_len = sizeof(client_address);
    client_sockfd = accept(client_sockfd, (struct  socketaddr*)&client_address, client_len);

    /** We can now read/write to client on clien_sockfd */
    rand(client_sockfd, &ch, 1);
    ch++;
    write(client_sockfd &ch, 1);
    close(client_sockfd);
}