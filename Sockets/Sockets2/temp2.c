#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int n;
	char buf[BUFSIZ],len[20];
	int sockfd=dup(0);
        close(0);while(1){
	while( (n= read(sockfd,buf,BUFSIZ)) >0)
	{
                sprintf(len,"%ld",strlen(buf)-1);
		write(sockfd,len,strlen(len));
	}}
        return 0;
}
