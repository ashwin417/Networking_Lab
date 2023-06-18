#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>

int main(int argc,char *argv[])
{
	struct sockaddr_in server,client;
	if(argc!=2)
		printf("Input format not correct");
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	int f=0;
	if(sockfd==-1)
		printf("Error in socket()");
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));
	if(bind(sockfd,(struct sockaddr*) &server,sizeof(server))<0)
		printf("Error in bind()\n");
	char buffer[100]; int c;
	socklen_t server_len = sizeof(server);
	for(;;)
	{
		int k = recvfrom(sockfd,buffer,100,0,(struct sockaddr *) &server,&server_len);
		buffer[k]='\0';
		if(k<0)
			printf("Error in recvfrom()");
		if(atoi(buffer)==11111)
		{
			printf("Received exit request from client!\nExiting!!!");
			break;
		}
		else
		{
			//memset(buffer, 0, sizeof(buffer));
			printf("\nMessage from Client:%s",buffer);
			
			c = atoi(buffer);
			printf("Number is %d",c);
			if (c == 0 || c == 1)
    			f = 1;
			for(int i=2;i<=c/2;i++)
			{
				if(c%i==0){
					f=1;
					break;
				}	
			}
			if(f==0)
				strcpy(buffer,"The number is prime");
			else
				{
				strcpy(buffer,"The number is not prime");
				}
			
			k = sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*) &server,sizeof(server));
			if(k<0)
				printf("Error in sendto()");
		}
	}
	return 0;
}
