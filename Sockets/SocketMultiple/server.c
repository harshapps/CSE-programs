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
	int sockfd, newsockfd, client_arr[25], client_arrlen=0, max_fds;
	socklen_t clientlength;
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[256];
	int n,nfds;
	fd_set read_fds;

	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		printf("\nError opening socket");
	}
	printf("\nSocket created!");

	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(8889);

	
	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		close(sockfd); //closing the socket if already in use
		perror("Bind failed.Error");
		return 1;
	}
 	printf("\nDone with binding!");

	listen(sockfd,MAX_CLIENTS);

	clientlength = sizeof(cli_addr);

	max_fds = sockfd;
	client_arr[client_arrlen++] = sockfd;
	printf("\nWhatsup!");
	//FD_SET(sockfd, &read_fds);

	while(1)
	{
		FD_ZERO(&read_fds);
		int p;
		for(p=0;p<client_arrlen;p++)
			FD_SET(client_arr[p], &read_fds);

		nfds = select(max_fds+1, &read_fds, NULL, NULL, &tv);
		if(nfds!=0)
		{
			if(nfds==-1)
			{	
				printf("\nSelect Error!");
			}
			if(FD_ISSET(sockfd, &read_fds))
			{
				client_arr[client_arrlen] = accept(sockfd, (struct sockaddr *) &cli_addr, &clientlength);
				printf("\nClient connection accepted!");	

				FD_SET(client_arr[client_arrlen], &read_fds);

				if(client_arr[client_arrlen] > max_fds)
					max_fds = client_arr[client_arrlen];
					client_arrlen++;
			}

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
		}
	}
	close(sockfd);
	close(newsockfd);
	return 0;
}