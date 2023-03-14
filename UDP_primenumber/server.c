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
	int n = atoi(buffer);
	printf("Number Recieved from Client is %d to check if it prime or not!!!\n",n);
	int flag = 0,i;
	if(n==0 || n==1)
		flag = 1;
		
	for(i=2;i<=n/2;i++)
	{
		if(n%i == 0)
			flag = 1; break;
	}
	if(sendto(sock_fd, buffer,sizeof(buffer),0,(struct sockaddr*) &server, sizeof(server))<0)
		{ printf("Error in sendto!!!\n"); }

	return 0;
}
