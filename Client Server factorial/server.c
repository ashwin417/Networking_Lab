
#include<netinet/in.h> 		//Contains definitions of IP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include <unistd.h>
int main()
{
	char buf[100];
	int k;
	socklen_t len;
	int sock_desc, temp_sock_desc;
	struct sockaddr_in server,client;
	sock_desc = socket(AF_INET,SOCK_STREAM,0);
	//printf("Starting...");
	if(sock_desc == -1)
	{
		printf("Error in Socket Creation!!!");
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	
	server.sin_port = 3003;
	client.sin_family = AF_INET;
	
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = 3003;
	
	k = bind(sock_desc,(struct sockaddr*) &server, sizeof(server));
	
	if(k==-1)
	{
		printf("Error in binding...");
	}
	//printf("binded");
	k=listen(sock_desc,5);
	
	if(k==-1)
	{
	printf("Error in listening");
	}
	
	len = sizeof(client);
	temp_sock_desc = accept(sock_desc, (struct sockaddr*) &client,&len);
	
	if(temp_sock_desc == -1)
	{
		printf("Error in Temporary socket creation!");
	}
	
	k = recv(temp_sock_desc,buf,100,0);
	
	if(k==-1)
	{
		printf("Error in recieving");
	}
	
	
	int n = atoi(buf);
	int i,fact=1;
	  for(i=1;i<=n;i++){    
      			fact=fact*i;    
  		}  
	
	printf("Factorial of the number sent from client is: %d", fact);
	close(temp_sock_desc);
		
	
	return 0;
	

}
