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
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
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
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
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
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Simulate sending packets
    while (expected_seq_num < MAX_SEQ_NUM) {
        // Send packets up to the window size
        while (next_seq_num < base + WINDOW_SIZE && next_seq_num < MAX_SEQ_NUM) {
            window[next_seq_num % WINDOW_SIZE].seq_num = next_seq_num;
            sprintf(window[next_seq_num % WINDOW_SIZE].data, "Packet %d", next_seq_num);
            printf("Sending packet %d: %s\n", next_seq_num, window[next_seq_num % WINDOW_SIZE].data);
            send(new_socket, window[next_seq_num % WINDOW_SIZE].data, strlen(window[next_seq_num % WINDOW_SIZE].data), 0);
            next_seq_num++;
        }

        // Simulate receiving ACKs
        valread = read(new_socket, buffer, 1024);
        if (valread > 0) {
            int ack_num = atoi(buffer);
            printf("Received ACK for packet %d\n", ack_num);
            window[ack_num % WINDOW_SIZE].acked = true;
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
