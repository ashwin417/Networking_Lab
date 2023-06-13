#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int socket_desc;
    struct sockaddr_in server;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP server at %s:%d\n", SERVER_IP, PORT);

    // Send file to server
    FILE* file = fopen("file_to_send.txt", "r");
    if (!file) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    while (!feof(file)) {
        size_t read_size = fread(buffer, sizeof(char), sizeof(buffer), file);
        if (send(socket_desc, buffer, read_size, 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    printf("File sent successfully\n");

    // Close the connection
    close(socket_desc);
    return 0;
}


/*
output:

[ashu@ArchAsh FTP]$ ./c
Connected to FTP server at 127.0.0.1:8080
File sent successfully

file_to_send.txt
        hello world
*/


