#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
int main()
{
	int n;
	char buf[BUFSIZ];
	int sockfd=dup(0);
        close(0);while(1){
	while( (n= recv(sockfd,buf,BUFSIZ,0)) >0)
	{
		send(sockfd,buf,n,0);
	}}
        return 0;
}
