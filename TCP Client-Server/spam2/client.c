#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#define PORT 8080

#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    int sock = 0, valread;

    struct sockaddr_in serv_addr;

    char buffer[MAX_BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

        printf("\n Socket creation error \n");

        return -1;

    }

    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {

        printf("\nInvalid address/ Address not supported \n");

        return -1;

    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {

        printf("\nConnection Failed \n");

        return -1;

    }

    printf("Enter an integer to calculate its factorial (enter 0 to stop): ");

    while (fgets(buffer, MAX_BUFFER_SIZE, stdin)) {

        int num = atoi(buffer);

        if (num == 0) {

	printf("Connection terminated!!!");
	        write(sock, buffer, strlen(buffer));
            break;

        }

        write(sock, buffer, strlen(buffer));

        valread = read(sock, buffer, MAX_BUFFER_SIZE);

        buffer[valread] = '\0';

        printf("%s", buffer);

        printf("Enter an integer to calculate its factorial (enter 0 to stop): ");

    }

    close(sock);

    return 0;

}

