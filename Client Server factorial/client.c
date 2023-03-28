#include<stdio.h>
#include<netinet/in.h> 		//Contains definitions of IP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#define MAX 80
#define port 8080

int main()
{
	int k; 
	int sock_desc;
	char buff[100];
	int n;
	struct sockaddr_in server,client;
	sock_desc = socket(AF_INET,SOCK_STREAM,0);//AF_INET to provide interprocess communication between process that run on same system or different systems
	
	if(sock_desc == -1)
	{
		printf("Error in Socket Creation!!!");
	}
	
	client.sin_family = AF_INET;		//sin_family contains address family and is AF_INET when TCP/UDP is used
	client.sin_addr.s_addr = INADDR_ANY;	//sin.addr contains IP Address
	client.sin_port = htons(port);
	
	bzero(&server,sizeof(server));		//erases the data
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(port);
	
	k = connect(sock_desc,(struct sockaddr*) &client, sizeof(client));
	
	if(k == -1)
	{
		printf("Error in connecting to server...");
	}
	else
		printf("Connected to server...");
	
	
	for(;;)
	{
		bzero(buff,sizeof(buff));		//erases the data
		printf("\nEnter the data to be sent : ");
		int n=0;
		while((buff[n++]=getchar())!='\n');
		write(sock_desc,buff,sizeof(buff));
		if(strncmp("exit",buff,4)==0)
		{
		printf("\nclient exits\n");
		break;
		}
		bzero(buff,sizeof(buff));	
		read(sock_desc,buff,sizeof(buff));
		if(strncmp("exit",buff,4)==0)
		{
		printf("\nClient exits\n");
		break;
		}
		printf("\nFrom server:%s\n",buff);
	}
	close(sock_desc);
	return 0;
	
	
}
