#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>

int main(int argc, char* argv[])
{
	struct sockaddr_in server,client;
	if(argc != 3)
		printf("Input format is not correct!!!\n");
	int sock_fd = socket(AF_INET,SOCK_DGRAM,0);
	if( sock_fd == -1)
		printf("Error in socket()");
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[2]));
	char buffer[100];
	printf("Enter the data to be sent to server : ");
	fgets(buffer,100,stdin);
	if(sendto(sock_fd, buffer,sizeof(buffer),0,(struct sockaddr*) &server, sizeof(server))<0)
		{ printf("Error in sendto!!!\n"); }
	return 0;
}
