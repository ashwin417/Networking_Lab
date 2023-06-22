#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 80
#define port 8888

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    char buff[MAX];
    int k;
    socklen_t len;
    int sock_desc, temp_sock_desc;
    struct sockaddr_in server, client;
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_desc == -1) {
        printf("Error in Socket Creation!!!");
        return 1; // Exit with an error code
    } else {
        printf("Socket successfully created!\n");
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    k = bind(sock_desc, (struct sockaddr*) &server, sizeof(server));

    if (k == -1) {
        printf("Error in binding...\n");
        return 1; // Exit with an error code
    } else {
        printf("Binded Successfully\n");
    }

    k = listen(sock_desc, 5);

    if (k == -1) {
        printf("Error in listening\n");
        return 1; // Exit with an error code
    }

    len = sizeof(client);
    temp_sock_desc = accept(sock_desc, (struct sockaddr*) &client, &len);

    if (temp_sock_desc == -1) {
        printf("Error in Temporary socket creation!\n");
        return 1; // Exit with an error code
    }

    for (;;) {
        bzero(buff, MAX);
        read(temp_sock_desc, buff, sizeof(buff));
        if (strncmp(buff, "exit", 4) == 0) {
            printf("Exiting\n");
            break;
        }

        int n = atoi(buff);
        int fact = factorial(n);

        bzero(buff, MAX);
        printf("Factorial of the number sent from the client is: %d\n", fact);
        sprintf(buff, "%d", fact);
        write(temp_sock_desc, buff, sizeof(buff));
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server exits\n");
            break;
        }
    }

    close(temp_sock_desc);
    close(sock_desc);

    return 0;
}


/* #include<netinet/in.h> 		//Contains definitions of IP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include <unistd.h>
#define MAX 80
#define port 8080
int main()
{
	char buff[MAX];
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
	else 
		printf("Socket successfully created!");
	bzero(&server,sizeof(server));		//erases the data
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = htons(port);
	
	k = bind(sock_desc,(struct sockaddr*) &server, sizeof(server));
	
	if(k==-1)
	{
		printf("Error in binding...\n");
	}
	else
		printf("Binded Successfully\n");
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
		printf("\nError in Temporary socket creation!\n");
	}
	
	/*k = recv(temp_sock_desc,buf,100,0);
	
	if(k==-1)
	{
		printf("Error in recieving");
	}
	int x;
	for(;;)
	{
		bzero(buff,MAX);
		read(temp_sock_desc,buff,sizeof(buff));
		if(strncmp(buff,"exit",4)==0)
		{
			#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 80
#define port 8080

int main() {
    char buff[MAX];
    int k;
    socklen_t len;
    int sock_desc, temp_sock_desc;
    struct sockaddr_in server, client;
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_desc == -1) {
        printf("Error in Socket Creation!!!");
        return 1; // Exit with an error code
    } else {
        printf("Socket successfully created!\n");
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    k = bind(sock_desc, (struct sockaddr*) &server, sizeof(server));

    if (k == -1) {
        printf("Error in binding...\n");
        return 1; // Exit with an error code
    } else {
        printf("Binded Successfully\n");
    }

    k = listen(sock_desc, 5);

    if (k == -1) {
        printf("Error in listening\n");
        return 1; // Exit with an error code
    }

    len = sizeof(client);
    temp_sock_desc = accept(sock_desc, (struct sockaddr*) &client, &len);

    if (temp_sock_desc == -1) {
        printf("Error in Temporary socket creation!\n");
        return 1; // Exit with an error code
    }

    for (;;) {
        bzero(buff, MAX);
        read(temp_sock_desc, buff, sizeof(buff));
        if (strncmp(buff, "exit", 4) == 0) {
            printf("Exiting\n");
            break;
        }

        int n = atoi(buff);
        int i, fact = 1;
        for (i = 1; i <= n; i++) {
            fact = fact * i;
        }

        bzero(buff, MAX);
        printf("Factorial of the number sent from the client is: %d\n", fact);
        sprintf(buff, "Factorial of the number sent from the client is: %d", fact);
        write(temp_sock_desc, buff, sizeof(buff));
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server exits\n");
            break;
        }
    }

    close(temp_sock_desc);
    close(sock_desc);

    return 0;
}
printf("Exitting");
			break;
		}
		//printf("\nFrom client:%s\t To Client:",buff);
		x=0;
		
		//while(buff[x++]=getchar()!='\n');
		int n = atoi(buff);
		int i,fact=1;
		  for(i=1;i<=n;i++){    
	      			fact=fact*i;    
	  		}  
		bzero(buff,MAX);
		printf("\nFactorial of the number sent from client is: %d", fact);
		sprintf(buff,"\nFactorial of the number sent from client is: %d",fact);
		//itoa(sizeof(buff),buff);
		write(temp_sock_desc,buff,sizeof(buff));
		if(strncmp("exit",buff,4)==0)
		{
		printf("\nServer exits\n");
		break;
		}
	}
	close(temp_sock_desc);
		
	
	return 0;
	

} */

/*void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  
         n = -n;          
     i = 0;
     do {       
         s[i++] = n % 10 + '0';   
     } while ((n /= 10) > 0);     
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}  
void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}  
*/
