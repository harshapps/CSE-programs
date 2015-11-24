#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main()
{
	int sockfd, retval;
	struct sockaddr_in ser_addr;
	//char buffer[data];
	char data[256];
	socklen_t addrlen;

	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(sockfd==-1)
		printf("\nError creating socket!");
	printf("\nSocket Created!");

	//printf("\nEnter data: ");
	read(0,data,255);

	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ser_addr.sin_port = htons(7000);

	
	

	retval = sendto(sockfd, data, strlen(data), 0 , (struct sockaddr*) &ser_addr, sizeof(struct sockaddr_in));
	if (retval!=-1)
	{
		printf("Successfully sent data %d): %s\n", retval, data);
	}
	else
	{
		printf("sendto() failed [%s]\n", strerror(errno));
	}

	close(sockfd);
	return 0;
}