#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <stdbool.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int client_socket, n;

    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];

    // Create a UDP socket

    if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {

        perror("socket creation failed");

        exit(EXIT_FAILURE);

    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;

    server_addr.sin_port = htons(8080);

    server_addr.sin_addr.s_addr = INADDR_ANY;

    while (true) {

        printf("Enter an integer to check whether it's prime or not (or type 'stop' to exit): ");

        scanf("%s", buffer);

        // Check whether user typed 'stop'

        if (strcmp(buffer, "stop") == 0) {

            break;

        }

        // Send the integer to the server

        sendto(client_socket, buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *) &server_addr, sizeof(server_addr));

        // Receive the result from the server

        n = recvfrom(client_socket, buffer, BUFFER_SIZE, MSG_WAITALL, NULL, NULL);

        buffer[n] = '\0';

        printf("%s\n", buffer);

    }

    close(client_socket);

    return 0;

}
