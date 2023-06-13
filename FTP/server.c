#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, read_size;
    struct sockaddr_in server, client;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    listen(server_socket, 3);

    printf("FTP server listening on port %d...\n", PORT);

    // Accept and handle incoming connections
    while (1) {
        // Accept connection
        int client_address_size = sizeof(struct sockaddr_in);
        client_socket = accept(server_socket, (struct sockaddr*)&client, (socklen_t*)&client_address_size);
        if (client_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connected to client: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Receive file from client
        FILE* file = fopen("received_file.txt", "w");
        if (!file) {
            perror("File opening failed");
            exit(EXIT_FAILURE);
        }

        while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
            fwrite(buffer, sizeof(char), read_size, file);
        }

        fclose(file);
        printf("File received and saved as 'received_file.txt'\n");

        // Close the connection
        close(client_socket);
    }

    close(server_socket);
    return 0;
}


/* Output 

[ashu@ArchAsh FTP]$ ./s
FTP server listening on port 8080...
Connected to client: 127.0.0.1:56606
File received and saved as 'received_file.txt'

recieved.txt
    hello world
*/
