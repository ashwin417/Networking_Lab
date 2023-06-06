#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <unistd.h>


#define WINDOW_SIZE 4

#define MAX_SEQ_NUM 8

#define PORT 8080


typedef struct {

    int seq_num;

    bool acked;

    char data[20];

} packet;


int main() {

    int sock = 0, valread;

    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};

    packet window[WINDOW_SIZE];

    int base = 0;

    int next_seq_num = 0;

    int expected_seq_num = 0;

    int i;


    // Initialize the window

    for (i = 0; i < WINDOW_SIZE; i++) {

        window[i].seq_num = -1;

        window[i].acked = false;

        memset(window[i].data, 0, sizeof(window[i].data));

    }


    // Create socket file descriptor

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

        printf("\n Socket creation error \n");

        return -1;

    }


    memset(&serv_addr, '0', sizeof(serv_addr));


    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(PORT);


    // Convert IPv4 and IPv6 addresses from text to binary form

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {

        printf("\nInvalid address/ Address not supported \n");

        return -1;

    }


    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {

        printf("\nConnection Failed \n");

        return -1;

    }


    // Simulate sending packets

    while (expected_seq_num < MAX_SEQ_NUM) {

        // Send packets up to the window size

        while (next_seq_num < base + WINDOW_SIZE && next_seq_num < MAX_SEQ_NUM) {

            window[next_seq_num % WINDOW_SIZE].seq_num = next_seq_num;

            sprintf(window[next_seq_num % WINDOW_SIZE].data, "Packet %d", next_seq_num);

            printf("Sending packet %d: %s\n", next_seq_num, window[next_seq_num % WINDOW_SIZE].data);

            send(sock, window[next_seq_num % WINDOW_SIZE].data, strlen(window[next_seq_num % WINDOW_SIZE].data), 0);

            next_seq_num++;

        }


        // Simulate receiving ACKs

        valread = read(sock, buffer, 1024);

        if (valread > 0) {

            int ack_num = atoi(buffer);

            printf("Received ACK for packet %d\n", ack_num);

            window[ack_num % WINDOW_SIZE].acked = true;

            sprintf(buffer, "%d", ack_num);

            send(sock, buffer, strlen(buffer), 0);

        }


        // Slide the window

        while (window[base % WINDOW_SIZE].acked) {

            printf("Removing packet %d from window\n", base);

            window[base % WINDOW_SIZE].seq_num = -1;

            window[base % WINDOW_SIZE].acked = false;

            memset(window[base % WINDOW_SIZE].data, 0, sizeof(window[base % WINDOW_SIZE].data));

            base++;

            expected_seq_num++;

        }

    }


    printf("All packets sent and acknowledged\n");


    return 0;

}
