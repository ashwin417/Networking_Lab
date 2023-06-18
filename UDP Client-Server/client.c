#include<stdio.h> 
#include<string.h> 
#include<sys/socket.h> 
#include<stdlib.h> 
#include<netdb.h> 
int main(int argc,char *argv[]) 
{ 
 struct sockaddr_in server,client; 
 if(argc!=3) 
 printf("Input format not correct\n"); 
 int sockfd = socket(AF_INET,SOCK_DGRAM,0); 
 int k; 
 if(sockfd==-1) 
 printf("Error in socket()\n"); 
 server.sin_family=AF_INET; 
 server.sin_addr.s_addr=INADDR_ANY; 
 server.sin_port = htons(atoi(argv[2])); 
 socklen_t server_len = sizeof(server); 
 socklen_t client_len = sizeof(client); 
 char buffer[100]; 
 for(;;) 
 { 
 printf("\nEnter a message to be sent to server:"); 
 fgets(buffer,100,stdin); 
 if(strncmp("exit",buffer,4)==0||strncmp("Exit",buffer,4)==0) 
 { 
 k = sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*) &server,sizeof(server)); 
 if(k<0) 
 printf("Error in exit request"); 
 printf("Exit Request Sent\nExiting"); 
 break; 
 } 
 else 
 { 
 k = sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*) &server,sizeof(server)); 
 if(k<0) 
 printf("\nError in sendto"); 
 k = recvfrom(sockfd,buffer,100,0,(struct sockaddr *) &client,&client_len); 
 if(k<0) 
 printf("\nError in recvfrom()"); 
 printf("Message from Server:%s\n",buffer); 
 } 
 } 
 return 0; 
} 
