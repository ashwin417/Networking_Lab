#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define OUTPUT_RATE 1       // Packets per second

int main() {
    int BUCKET_CAPACITY;
    printf("Enter the bucket capacity:");
    scanf("%d",&BUCKET_CAPACITY);
    int bucket_size = 0;  // Current bucket size

    while (true) {
        // Generate incoming packets randomly
        int incoming_packets = rand() % 5;

        printf("Incoming packets: %d\n", incoming_packets);

        // Add incoming packets to the bucket
        bucket_size += incoming_packets;

        // Check if the bucket is overflowing
        if (bucket_size > BUCKET_CAPACITY) {
            printf("Bucket overflow! Dropping packets: %d\n", bucket_size - BUCKET_CAPACITY);
            bucket_size = BUCKET_CAPACITY;  // Reset bucket size to maximum capacity
        }

        // Process outgoing packets
        if (bucket_size > 0) {

            printf("Outgoing packets: %d\n", OUTPUT_RATE);

            // Subtract outgoing packets from the bucket
            bucket_size -= OUTPUT_RATE;
        }

        sleep(1);  // Wait for 1 second
    }

    return 0;
}
