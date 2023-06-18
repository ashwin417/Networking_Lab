#### TO Run

### Open the terminal
### Compile the server file using
            gcc server.c -o server 
            ./server

### Open another TAB using "CTRL + Shift + T" or Open another window in terminal and go to folder where the code files are located
### Compile the Client code using 
            gcc client.c -o client
             ./client"
##### Enter the message in prompt to be sent to server and click enter. 
##### Go to Server tab in terminal and server will have recieved the message.
      
##### In case of Output not correct
    1. Close the terminal and re compile and run the program. 

### OUTPUT

##### Server.c 

        Message from Client: Hello server! 
        Enter data to send to client: Welcome client! 
        Message from Client: How are you? 
        Enter data to send to client: I'm doing well, thank you! 
        Message from Client: What is the current time? 
        Enter data to send to client: The current time is 10:30 AM. 
        Message from Client: exit 
        Received exit request from client! 
        Exiting!!! 

##### Client.c 

        Enter a message to be sent to server: Hello server! 
        Message from Server: Welcome client! 
        Enter a message to be sent to server: How are you? 
        Message from Server: I'm doing well, thank you! 
        Enter a message to be sent to server: What is the current time? 
        Message from Server: The current time is 10:30 AM. 
        Enter a message to be sent to server: exit 
        Exit Request Sent 
        Exiting        


### Code Explanation


    Server Code:
        1. The server code begins by including the necessary header files.
        2. It creates a socket using the `socket()` function, specifying the address family `AF_INET` and socket type `SOCK_DGRAM` for UDP.
        3. The server sets up the server address structure (`server.sin_family`, `server.sin_addr.s_addr`, and `server.sin_port`).
        4. It binds the socket to the server address using the `bind()` function.
        5. The server then enters an infinite loop to receive and process messages from the client.
        6. It receives a message from the client using the `recvfrom()` function.
        7. If the received message is "exit" or "Exit", the server sends a response indicating the exit request and breaks out of the loop.
        8. Otherwise, it prints the received message and prompts for a response to send back to the client.
        9. The server uses the `sendto()` function to send the response message to the client.

    Client Code:
        1. Similar to the server code, the client code includes the necessary header files.
        2. It creates a socket using the `socket()` function, specifying the address family `AF_INET` and socket type `SOCK_DGRAM`.
        3. The client sets up the server address structure (`server.sin_family`, `server.sin_addr.s_addr`, and `server.sin_port`) using the command-line arguments provided.
        4. The client enters a loop to send and receive messages with the server.
        5. It prompts the user to enter a message to be sent to the server.
        6. If the entered message is "exit" or "Exit", the client sends an exit request to the server and breaks out of the loop.
        7. Otherwise, it sends the message to the server using the `sendto()` function.
        8. The client receives a response from the server using the `recvfrom()` function.
        9. It prints the received message from the server.

    Overall, this code establishes a connection between a client and a server using UDP. The server listens for incoming messages, responds to them, and handles exit requests. The client can send messages to the server and receive responses. The communication is achieved through the use of sockets and the `sendto()` and `recvfrom()` functions.


### Algorithm

    Server: 
        1. Create a socket using the socket() function with the domain set to AF_INET and the type set to SOCK_DGRAM. 
        2. Initialize the server address structure with the appropriate values: 
                a. Set the family to AF_INET. 
                b. Set the IP address to INADDR_ANY. 
                c. Set the port number by converting the command line argument to an integer and using htons() to convert it to 
                network byte order. 
        3. Bind the socket to the server address using the bind() function. 
        4. Enter a loop to continuously receive messages from the client: 
                a. Use the recvfrom() function to receive a message from the client and store it in a buffer. 
                b. Check if an exit request was received. If so, break out of the loop. 
                c. Otherwise, process the received message as desired. 
                d. Use the sendto() function to send a response to the client if needed. 
        5. Close the socket and terminate the program. 
    Client: 
        1. Create a socket using the socket() function with the domain set to AF_INET and the type set to SOCK_DGRAM. 
        2. Initialize the server address structure with the appropriate values: 
                a. Set the family to AF_INET. 
                b. Set the IP address to the server's IP address. 
                c. Set the port number by converting the command line argument to an integer and using htons() to convert it to 
                network byte order. 
        3. Create a buffer to store messages. 
        4. Enter a loop to continuously send messages to the server: 
                a. Prompt the user to enter a message to send. 
                b. Read the message from the user and store it in the buffer. 
                c. Check if an exit request was entered. If so, send the request to the server and break out of the loop. 
                d. Otherwise, use the sendto() function to send the message to the server. 
                e. Use the recvfrom() function to receive a response from the server if needed. 
                f. Process and display the response as desired. 
        5. Close the socket and terminate the program.