#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <pthread.h>

char gno1[10],cno1[10],buffer[256],tag[256],gno,cno;
int sockfd;

void* read_server()
{ 
  while(1)
  {
 //   read(sockfd,tag,255);
            sleep(1);
  read(sockfd,buffer,255);
// if(strcmp(tag,"encrypted")==0)
 //  {
      //decrypt  the received msg
 //   printf("encrypted message recieved:%s\n",buffer);
 //  }
    printf("message recieved by %d group, %d client is %s\n",gno,cno,buffer);
    memset(buffer,'\0',255); 
  }
}
void* write_server()
{ 
  while(1)
  {

 printf("enter the group number of destination\n");
  read(1,gno1,10);
  printf("enter the client number of destinantion\n");
  read(1,cno1,10);
  
  printf("enter msg to be sent\n");
  read(1,buffer,255);

    write(sockfd,gno1,strlen(gno1));
    write(sockfd,cno1,strlen(cno1));
    write(sockfd,buffer,strlen(buffer));
  
    memset(gno1,'\0',255); 
    memset(cno1,'\0',255); 
    memset(buffer,'\0',255); 
  }
}

int main(int argc, char* argv[])
{

    struct sockaddr_in serv_addr;
    struct hostent *server;

  
     gno=atoi(argv[1]);
   printf("%d\n",gno);
   cno=atoi(argv[2]);
   printf("%d\n",cno);

    int portno ;
   if(gno==1) portno = 1233;
    else if(gno==2) portno= 1234;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    perror("socket:\n");
    
    server = gethostbyname("localhost");
    perror("gethostbyname:\n");
   
    memset((char *) &serv_addr,0, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    
    connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)); 
    perror("connect:\n");
/*
printf("msg sent while connecting %s\n",argv[2]);
   write(sockfd,argv[2],strlen(argv[2]));
*/


 pthread_t rd,wt;
    pthread_create(&rd,NULL,read_server,NULL);
	pthread_create(&wt,NULL,write_server,NULL);
	pthread_join(rd,NULL);
    pthread_join(wt,NULL);


return 0;
   
}
