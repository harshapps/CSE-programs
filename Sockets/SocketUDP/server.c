#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h> 

int main()
{
	int sockfd, newsockfd, retval;
	struct sockaddr_in ser_addr, new_addr;
	char buffer[256];
	socklen_t addrlen;

	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(sockfd==-1)
		printf("\nError creating socket!");
	printf("\nSocket Created!");

	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = INADDR_ANY;
	ser_addr.sin_port = htons(7000);

	if(bind(sockfd, (struct sockaddr*)&ser_addr, sizeof(ser_addr))<0)
	{
		perror("Bind Failed.Error");
	}
	printf("\nBind done!");

	//addrlen = sizeof(ser_addr);

	printf("\nWaiting for client to send a message!");
	retval = recvfrom(sockfd, buffer, 255, 0 , (struct sockaddr*) &new_addr, &addrlen);
	if (retval!=-1)
	{
		printf("\nRecieved data: %s",buffer);
	}
	else
	{
		printf("\nError recieving data!");
	}

	close(sockfd);
	return 0;
}
