### To Run 
#### Server 
      gcc server.c -o server
      ./server 

#### Client
      gcc client.c -o client
      ./client  

### First Run server.c in a tab in the terminal and then run the client.c in another tab.

#### OUTPUT

##### [ashu@ArchAsh FTP]$ ./server
     
      FTP server listening on port 8080...
      Connected to client: 127.0.0.1:56606
      File received and saved as 'received_file.txt'


##### recieved.txt
          
          hello world


##### [ashu@ArchAsh FTP]$ ./client
      
      Connected to FTP server at 127.0.0.1:8080
      File sent successfully

##### file_to_send.txt
       
        hello world


### Algorithm :
      Server Algorithm: 
            1. Create a socket using socket() function. 
            2. Initialize the server address structure (struct sockaddr_in) with the server's IP address, port number, and address 
            family. 
            3. Bind the socket to the server address using bind() function. 
            4. Listen for incoming connections using listen() function. 
            5. Print a message indicating that the server is listening on the specified port. 
            6. Enter a continuous loop to accept incoming client connections: 
                  a. Accept a client connection using accept() function, which returns a new socket descriptor for the client. 
                  b. Print the client's IP address and port number. 
            c. Open the file in write mode to save the received data. 
            d. Enter a loop to receive data from the client: 
                  i. Receive data from the client using recv() function. 
                  ii. Write the received data to the file using fwrite() function. 
            e. Close the file. 
            f. Print a message indicating that the file has been received and saved. 
            g. Close the client socket. 
            7. Close the server socket. 
           
        Client Algorithm: 
            
            1. Create a socket using socket() function. 
            2. Initialize the server address structure (struct sockaddr_in) with the server's IP address, port number, and 
            address family. 
            3. Connect to the server using connect() function. 
            4. Print a message indicating a successful connection to the server. 
            5. Open the file to be sent in read mode. 
            6. Enter a loop to read and send data from the file: 
                  a. Read data from the file using fread() function. 
                  b. Send the data to the server using send() function. 
            7. Close the file. 
            8. Print a message indicating that the file has been sent successfully. 
            9. Close the client socket

### Code Explanation: