#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> /* basic system data types */
#include <sys/socket.h> /* basic socket definition */
#include <sys/time.h>  /* time value for select() */
#include <netinet/in.h> /* sockaddr_in and other internet defn */
#include <string.h>
#include <arpa/inet.h>
#define SA struct sockaddr
#define SERV_PORT 9877
void str_cli(FILE *fp, int sockfd)
{
	char sendline[BUFSIZ], recvline[BUFSIZ];
	
	while(fgets(sendline,BUFSIZ,fp) != NULL){
		write(sockfd,sendline,sizeof(sendline));
	
		read(sockfd,recvline,BUFSIZ);
		fputs(recvline,stdout);
	}
}
int main(int argc, char **argv)
{
	int sockfd,n;
	char recvline[BUFSIZ+1];
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET,SOCK_STREAM,0); /* create an Internet (AF_INET) stream( SOCK_STREAM) socket */
	memset(&servaddr,0,sizeof(servaddr)) ; /*set entire struct to 0 */
	servaddr.sin_family = AF_INET ;
	servaddr.sin_port = htons(SERV_PORT); /* daytime server */
	
	if( inet_pton(AF_INET,argv[1],&servaddr.sin_addr) <=0)	
		printf(" inet_pton error for %s",argv[1]);						; /* set IP address to the value specified by argv[1] */
	
	if( connect(sockfd,(SA*)&servaddr,sizeof(servaddr)) <0)
		printf("connect error");

	str_cli(stdin,sockfd); 
	return 0;
}
