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
    Socket created successfully... 
    Socket binded successfully... 
    Server listening... 
    [From Client]: Hello server! 
    [To Client]: Welcome client! 
    [From Client]: How are you? 
    [To Client]: I'm doing well, thank you! 
    [From Client]: What is the current time? 
    [To Client]: The current time is 10:30 AM. 
    [From Client]: exit 
    Got Exit Request 
    Exiting!!!

##### Client.c 
    Socket Creation Successful 
    Connected to Server 
    [To Server]: Hello server! 
    [From Server]: Welcome client! 
    [To Server]: How are you? 
    [From Server]: I'm doing well, thank you! 
    [To Server]: What is the current time? 
    [From Server]: The current time is 10:30 AM. 
    [To Server]: exit 
    Exit Request Sent! 
    Exiting!!

### Algorithm
 
##### Server Side: 
    1. Create a socket using the socket() function. 
    2. Bind the socket to a specific IP address and port using the bind() function. 
    3. Start listening for incoming connections using the listen() function. 
    4. Accept a client connection using the accept() function. This will create a 
    temporary socket for communication. 
    5. Enter a loop to handle client requests: 
        a. Read data from the client using the read() function. 
        b. If the received message is "exit" or "Exit," exit the loop. 
        c. Print the received message from the client. 
        d. Prompt for a message to send to the client. 
    6. Send the message to the client using the write() function. 
    7. Close the temporary socket and the server socket. 

##### Client Side: 
    1. Create a socket using the socket() function. 
    2. Connect to the server using the connect() function, providing the server's IP address 
    and port. 
    3. Enter a loop for communication: 
        a. Prompt for a message to send to the server. 
        b. If the message is "exit" or "Exit," exit the loop. 
        c. Send the message to the server using the write() function. 
        d. Receive the server's response using the read() function. 
        e. Print the received message from the server. 
    4. Close the client socket.


### Code Explanation


    `server.c`:
        1. The server program starts by creating a socket using the `socket()` function and stores the socket descriptor in `sock_desc`. This socket will be used for communication with clients.
        2. The server sets up the server address structure (`server`) by specifying the IP address (`INADDR_ANY`) and the port number (3003) that the server will listen on.
        3. The `bind()` function is called to bind the socket to the server address. This step associates the socket with the specified IP address and port number.
        4. The `listen()` function is called to make the server start listening for incoming connections on the socket. The argument `5` specifies the maximum number of pending connections that can be queued for the server.
        5. The server enters a loop to accept client connections. In each iteration of the loop, the `accept()` function is called to accept a client connection. It creates a new temporary socket (`temp_sock_desc`) for communication with the client. The `client` parameter is used to store the client's address.
        6. Inside the loop, the server reads data from the client using the `read()` function and stores it in the `buf` buffer. The server then displays the received message using `printf()`.
        7. If the received message is "exit" or "Exit", the server checks the condition and, if true, exits the loop and terminates the program.
        8. Otherwise, if the received message is not an exit command, the server prompts the user to enter a message to send back to the client using `fgets()`. The message is stored in the `buf` buffer.
        9. The server then writes the message to the client using the `write()` function, sending it through the temporary socket (`temp_sock_desc`).

    `client.c`:
        1. The client program starts by creating a socket using the `socket()` function and stores the socket descriptor in `sock_desc`. This socket will be used for communication with the server.
        2. The client sets up the server address structure (`client`) by specifying the IP address (`INADDR_ANY`) and the port number (3003) to which it wants to connect.
        3. The `connect()` function is called to establish a connection to the server using the socket descriptor (`sock_desc`) and the server address structure (`client`).
        4. The client enters a loop to send messages to the server and receive responses.
        5. Inside the loop, the client prompts the user to enter a message to send to the server using `fgets()`. If the message is "exit" or "Exit", the client checks the condition and, if true, sends the message to the server using the `write()` function and exits the loop.
        6. Otherwise, if the message is not an exit command, the client writes the message to the server using the `write()` function, sending it through the socket.
        7. The client then reads the server's response using the `read()` function and stores it in the `buf` buffer. The response is the message sent back by the server.
        8. The client displays the received message using `printf()`.
        9. The client repeats this process until an exit command is given.
        10. Finally, the client closes the socket using the `close()` function to release the resources associated with the socket.

    In summary, the code establishes a basic client-server communication model using TCP/IP sockets. The server listens for client connections, receives messages from clients, and sends responses back. The client connects to the server, sends messages, and receives responses. This allows for simple message exchange between the client and server.