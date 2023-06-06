#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
	printf("Socket created successfully...\n");

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;

	server.sin_port=3003;
	client.sin_family=AF_INET;
	
	client.sin_addr.s_addr=INADDR_ANY;
	client.sin_port=3003;
	
	k=bind(sock_desc,(struct sockaddr*) &server,sizeof(server));
	
	if(k==-1)
		printf("Error in binding\n");
	printf("Socket binded successfully...\n");
		
	k=listen(sock_desc,5);
	
	if(k==-1)
		printf("Error in listening\n");
	printf("Server listening...\n");
		
	len=sizeof(client);
	temp_sock_desc=accept(sock_desc,(struct sockaddr*) &client,&len);
		
	if(temp_sock_desc==-1)
		printf("Error in temporary socket creation\n");
	printf("Server accepted client\n\n");
	k = recv(temp_sock_desc,buf,100,0);
	int nof = atoi(buf);
	for(int i=0;i<nof;i++)
	{	if(i%2==0){
			k=recv(temp_sock_desc,buf,100,0);
			printf("Frame received from Client:Frame [0]\n");
			sleep(1);
		}
		else
		{
			k=recv(temp_sock_desc,buf,100,0);
			printf("Frame received from Client:Frame [1]\n");
			sleep(1);
		}
		printf("Acknowledgement for Frame [%d]\n",(i%2==0)?1:0);
		k=send(temp_sock_desc,buf,100,0);
		printf("\n");
	}
	return 0;
}
