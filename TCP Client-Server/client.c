#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	char buf[100];
	int k;
	socklen_t len;
	int sock_desc,temp_sock_desc;
	struct sockaddr_in server,client;
	
	sock_desc=socket(AF_INET,SOCK_STREAM,0);
	
	if(sock_desc==-1)
		printf("Error in Socket creation\n");

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;

	server.sin_port=3003;
	client.sin_family=AF_INET;
	
	client.sin_addr.s_addr=INADDR_ANY;
	client.sin_port=3003;
	
	k=bind(sock_desc,(struct sockaddr*) &server,sizeof(server));
	
	if(k==-1)
		printf("Error in binding\n");
		
	k=listen(sock_desc,5);
	
	if(k==-1)
		printf("Error in listening\n");
		
	len=sizeof(client);
	temp_sock_desc=accept(sock_desc,(struct sockaddr*) &client,&len);
		
	if(temp_sock_desc==-1)
		printf("Error in temporary socket creation\n");
	for(;;)
	{
		bzero(buf,sizeof(buf));
		read(temp_sock_desc,buf,sizeof(buf));
		printf("\n[From Client]:%s",buf);
		if(strncmp("exit",buf,4)==0 || strncmp("Exit",buf,4)==0)
		{
			printf("Got Exit Request\nExiting!!!\n");
			exit(0);
		}
		printf("[To Client]:");
		fgets(buf,100,stdin);
		write(temp_sock_desc,buf,sizeof(buf));
	}
	return 0;
}
