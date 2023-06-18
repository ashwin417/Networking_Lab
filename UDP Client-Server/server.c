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
 if(sockfd==-1) 
 printf("Error in socket()"); 
 server.sin_family=AF_INET; 
 server.sin_addr.s_addr=INADDR_ANY; 
 server.sin_port = htons(atoi(argv[1])); 
 if(bind(sockfd,(struct sockaddr*) &server,sizeof(server))<0) 
 printf("Error in bind()\n"); 
 char buffer[100]; 
 socklen_t server_len = sizeof(server); 
 for(;;) 
 { 
 int k = recvfrom(sockfd,buffer,100,0,(struct sockaddr *) &server,&server_len); 
 if(k<0) 
 printf("Error in recvfrom()"); 
 if(strncmp("exit",buffer,4)==0||strncmp("Exit",buffer,4)==0) 
 { 
 printf("Received exit request from client!\nExiting!!!"); 
 break; 
 } 
 else 
 { 
 printf("\nMessage from Client:%s",buffer); 
 printf("Enter data to send to client:"); 
 fgets(buffer,100,stdin); 
 printf("\n"); 
 k = sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*) &server,sizeof(server)); 
 if(k<0) 
 printf("Error in sendto()"); 
 } 
 } 
 return 0; 
} 