#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <sys/socket.h>

#include <netinet/in.h>

#define PORT 8080

#define MAX_BUFFER_SIZE 1024

int factorial(int n) {

    if (n == 0) {

        return 1;

    } else {

        return n * factorial(n - 1);

    }

}

int main(int argc, char const *argv[]) {

    int server_fd, new_socket;

    struct sockaddr_in address;

    int addrlen = sizeof(address);

    char buffer[MAX_BUFFER_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {

        perror("socket failed");

        exit(EXIT_FAILURE);

    }

    address.sin_family = AF_INET;

    address.sin_addr.s_addr = INADDR_ANY;

    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {

        perror("bind failed");

        exit(EXIT_FAILURE);

    }

    if (listen(server_fd, 3) < 0) {

        perror("listen failed");

        exit(EXIT_FAILURE);

    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {

            perror("accept failed");

            exit(EXIT_FAILURE);

        }

        printf("New client connected\n");

        while (1) {

            int n = read(new_socket, buffer, MAX_BUFFER_SIZE);

            if (n <= 0) {

                break;

            }

            buffer[n] = '\0';

            int num = atoi(buffer);

            if (num == 0) {
		printf("Connection Terminated");
                break;
                exit(0);

            }
		printf("Number recieved from client is %d",num);
            int result = factorial(num);
            printf("The factorial of number from client is : %d\nSending to Client\n", result);

            sprintf(buffer, "Factorial of %d is %d\n", num, result);

            write(new_socket, buffer, strlen(buffer));

        }

        printf("Client disconnected\n");

        close(new_socket);

    }

    return 0;

}

