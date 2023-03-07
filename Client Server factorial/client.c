#include<stdio.h>
#include<netinet/in.h> 		//Contains definitions of IP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
int main()
{
	int k; 
	int sock_desc;
	char buf[100];
	struct sockaddr_in client;
	sock_desc = socket(AF_INET,SOCK_STREAM,0);//AF_INET to provide interprocess communication between process that run on same system or different systems
	
	if(sock_desc == -1)
	{
		printf("Error in Socket Creation!!!");
	}
	
	client.sin_family = AF_INET;		//sin_family contains address family and is AF_INET when TCP/UDP is used
	client.sin_addr.s_addr = INADDR_ANY;	//sin.addr contains IP Address
	client.sin_port = 3003;
	
	k = connect(sock_desc,(struct sockaddr*) &client, sizeof(client));
	
	if(k == -1)
	{
		printf("Error in connecting to server...");
	}
	
	printf("Enter the data to be sent : ");
	fgets(buf,100,stdin);
	
	k = send(sock_desc,buf,100,0);
	
	if(k == -1)
	{
		printf("Error in sending data to the server...");
	}
	//printf("Data Sent!!!");
	close(sock_desc);
	return 0;
	
	
}
