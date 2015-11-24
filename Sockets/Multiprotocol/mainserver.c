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
# define MAX_CLIENTS 10

int main()
{
	int csockfd, lsockfd, newsockfd, client_arr[25], client_arrlen=0, max_fds;
	socklen_t clientlength, addrlen;
	struct sockaddr_in cserv_addr, lserv_addr, cli_addr;
	char buffer[256];
	int n,nfds, retval;
	fd_set read_fds;

	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 0;

	//Connetion oriented
	csockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(csockfd < 0)
	{
		printf("\nError opening socket");
	}
	printf("\nConnetion oriented Socket created!");

	//Connetion less
	lsockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(lsockfd < 0)
	{
		printf("\nError opening socket");
	}
	printf("\nConnetion less Socket created!");

	//Connetion oriented
	bzero((char *)&cserv_addr, sizeof(cserv_addr));
	cserv_addr.sin_family = AF_INET;
	cserv_addr.sin_addr.s_addr = INADDR_ANY;
	cserv_addr.sin_port = htons(6889);

	//Connetion less
	bzero((char *)&lserv_addr, sizeof(lserv_addr));
	lserv_addr.sin_family = AF_INET;
	lserv_addr.sin_addr.s_addr = INADDR_ANY;
	lserv_addr.sin_port = htons(7889);
		
	if(bind(csockfd, (struct sockaddr *) &cserv_addr, sizeof(cserv_addr)) < 0)
	{
		close(csockfd); //closing the socket if already in use
		perror("Bind failed.Error");
		return 1;
	}
 	printf("\nDone with binding of Connection oriented!");

 	if(bind(lsockfd, (struct sockaddr *) &lserv_addr, sizeof(lserv_addr)) < 0)
	{
		close(lsockfd); //closing the socket if already in use
		perror("Bind failed.Error");
		return 1;
	}
 	printf("\nDone with binding of Connection less!");

	listen(csockfd,MAX_CLIENTS);

	clientlength = sizeof(cli_addr);

	max_fds = csockfd;
	client_arr[client_arrlen++] = csockfd;
	printf("\nWhatsup!");
	FD_SET(csockfd, &read_fds);

	while(1)
	{
		FD_ZERO(&read_fds);
		int p;
		for(p=0;p<client_arrlen;p++)
			FD_SET(client_arr[p], &read_fds);
		FD_SET(max_fds, &read_fds);
		FD_SET(lsockfd, &read_fds);

		nfds = select(max_fds+1, &read_fds, NULL, NULL, &tv);
		if(nfds!=0)
		{
			if(nfds==-1)
			{	
				printf("\nSelect Error!");
			}
			if(FD_ISSET(csockfd, &read_fds))
			{
				newsockfd = accept(csockfd, (struct sockaddr *) &cli_addr, &clientlength);
				int h = fork();
				if(h>0)
				{
					close(newsockfd);
				}
				else
				{
					dup2(newsockfd,0);
					execl("client","hurray",(char *)0);
				}
				/*
				client_arr[client_arrlen] = accept(sockfd, (struct sockaddr *) &cli_addr, &clientlength);
				printf("\nClient connection accepted!");	

				FD_SET(client_arr[client_arrlen], &read_fds);

				if(client_arr[client_arrlen] > max_fds)
					max_fds = client_arr[client_arrlen];
					client_arrlen++;
					*/
			}

			/*
			int i,j;
			for(i=1;i<client_arrlen;i++)			
				if(FD_ISSET(client_arr[i], &read_fds))
				{
					newsockfd = client_arr[i]; break;
				}

			int k = recv(client_arr[i], buffer, 255, 0);
			if(k>0)
			{
				for(j=1;j<client_arrlen;j++)
				{
					if(j!=i)
					{
						write(client_arr[j], buffer, strlen(buffer));
					}
				}
			}
			if(k==0)
			{
				printf("Client disconnected!\n");
				exit(1);
			}
			*/
			if (FD_ISSET(lsockfd, &read_fds))
			{
				printf("\nWaiting for client to send a message!");
				retval = recvfrom(lsockfd, buffer, 255, 0 , (struct sockaddr*) &lserv_addr, &addrlen);
				if (retval!=-1)
				{
					printf("\nRecieved data: %s",buffer);
				}
				else
				{
					printf("\nError recieving data!");
				}
			}
		}
	}
	close(csockfd);
	close(lsockfd);
	close(newsockfd);
	return 0;
}