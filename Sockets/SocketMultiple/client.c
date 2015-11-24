#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
# define MAX_CLIENTS 10

int main()
{
	int sockfd;
	struct sockaddr_in serv_addr;
	char buffer[256];
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		printf("\nError opening socket");
	}

	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(8889);

	connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	printf("Connected to server!\n");
	int h = fork();
	if(h>0)
	{
		while(1)
		{
			printf("\nEnter Message: ");
			bzero(buffer,256);
			fgets(buffer,255,stdin);
			n = write(sockfd, buffer, strlen(buffer));	
		}
		
	}
	else
	{
		while(1)
		{
			n = read(sockfd, buffer, 255);
			if(n<0)
			{
				printf("\nRead failed!");
				break;
			}
			printf("Message: %s",buffer);	
		}
		
	}
	close(sockfd);
	return 0;
}