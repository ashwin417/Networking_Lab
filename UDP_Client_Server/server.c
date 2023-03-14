#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>

int main(int argc, char* argv[])
{
	struct sockaddr_in server,client;
	if(argc != 2)
		printf("Input format is not correct!!!\n");
	int sock_fd = socket(AF_INET,SOCK_DGRAM,0);
	if( sock_fd == -1)
		printf("Error in socket()");
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));

	if(bind(sock_fd,(struct sockaddr*) &server, sizeof(server))<0)
		printf("Error in bind()!!!");
	char buffer[100];	
	socklen_t server_len = sizeof(server);
	printf("Server waiting...\n");
	if(recvfrom(sock_fd,buffer,100,0,(struct sockaddr*) &server,&server_len)<0)
		printf("Error in recvfrom()!");
	printf("Server got a datagram : %s",buffer);
	return 0;
}
