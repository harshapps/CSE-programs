#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <string.h>
#include <arpa/inet.h>
#define SERV_PORT 9877
#define SA struct sockaddr
#define LISTENQ 100
str_echo(int sockfd)
{
	int n;
	char buf[BUFSIZ];
	
	while( (n= read(sockfd,buf,BUFSIZ)) >0)
	{
		write(sockfd,buf,n);
	}
}
int main()
{
	int listenfd, connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in servaddr,cliaddr;
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	bind(listenfd,(SA*) &servaddr,sizeof(servaddr));
	listen(listenfd,LISTENQ);

	for( ; ;)
	{
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd,(SA*) &cliaddr, &clilen);
		if( (childpid = fork()) ==0){ /* child process */
			close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		close(connfd); 		/* parent closes connected socket */
	}

	return 0;
}
