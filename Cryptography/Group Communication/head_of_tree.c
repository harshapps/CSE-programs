#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<arpa/inet.h>
//#include <pthread.h>
//#include<sys/sem.h>
//#include<sys/ipc.h>
//#include<sys/shm.h>
#include<sys/select.h>
//#include<signal.h>
#include<fcntl.h>
#include<sys/stat.h>
//#include<poll.h>

int find_log(int n)
{
   int value = 2,i;
   for(i=1;i<n;i++)
  {
      if(value>n) return (i-1);
      value=value*2;
  }
}

int main(int argc, char* argv[])
{
int i,nsfd[10];
int sfd1,ssfd,clilen1,clilen;
struct hostent *server;
  struct sockaddr_in serv_addr,serv_addr1,cli_addr1,cli_addr;

  int socketfd=socket(AF_INET, SOCK_STREAM, 0);
    perror("socket:\n");
   
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
   if(atoi(argv[1])==1)  serv_addr.sin_port = htons(1233);
   else if(atoi(argv[1])==2)  serv_addr.sin_port = htons(1234);

  bind(socketfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr));
    perror("bind:\n");
    
    listen(socketfd,10);



  if(atoi(argv[1]) == 1)
  {


    ssfd=socket(AF_INET, SOCK_STREAM, 0);
    perror("socket:\n");
   
    serv_addr1.sin_family=AF_INET;
    serv_addr1.sin_addr.s_addr = INADDR_ANY;
    serv_addr1.sin_port = htons(2348);
  
    bind(ssfd, (struct sockaddr *) &serv_addr1,sizeof(serv_addr1));
    perror("bind:\n");
    
    listen(ssfd,10);

    sfd1=accept(ssfd, (struct sockaddr *) &cli_addr1, &clilen1);    
           perror("accept:\n");

//create socket for tree to tree commuunication in t1


  }

else if(atoi(argv[1]) ==2)
 {
//socket
 sfd1=socket(AF_INET, SOCK_STREAM, 0);
    perror("socket:\n");
  server = gethostbyname("localhost");
    perror("gethostbyname:\n");
   
    memset((char *) &serv_addr,0, sizeof(serv_addr));
    
    serv_addr1.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr1.sin_addr.s_addr,server->h_length);
    serv_addr1.sin_port = htons(2348);
  
//connect  
    connect(sfd1,(struct sockaddr *) &serv_addr1,sizeof(serv_addr1)); 
    perror("connect:\n");
   



//create socket for tree to tree communication in t2


}
int cnt=0;
int arr[50];    
fd_set rfds;
char gno[10],cno[10],buffer[256],tag[256];
while(1)
{

    FD_ZERO(&rfds);
        int max=socketfd;
   FD_SET(socketfd,&rfds);
   FD_SET(sfd1,&rfds);
   if(max<sfd1) max=sfd1;

   for(i=0;i<cnt;i++)
   {
     FD_SET(nsfd[i],&rfds);
     if(nsfd[i]>max) max=nsfd[i];
   }

   int n=select(max+1,&rfds,NULL,NULL,NULL);

if(n>0)
{
   if(FD_ISSET(socketfd,&rfds))
   {
     nsfd[cnt]=accept(socketfd, (struct sockaddr *) &cli_addr, &clilen);    
           perror("accept:\n");
     sleep(3);
     read(nsfd[cnt],buffer,strlen(buffer));
    /* printf("buffer when accepting %s\n",buffer);
     arr[cnt]=atoi(buffer);
*/
     printf("connection established by client %d to server %d\n",cnt,atoi(argv[1]));

    memset(buffer,'\0',255);
    cnt++;      
    
   }
   else if(FD_ISSET(sfd1,&rfds))
   {
    printf("reading from other server\n");
     sleep(1);
     read(sfd1,cno,strlen(cno));
     sleep(1);
     read(sfd1,gno,strlen(gno));
     sleep(1);
     read(sfd1,buffer,strlen(buffer));
     sleep(1);
     read(sfd1,tag,strlen(tag));
     
     for(i=0;i<cnt;i++)
     {   if(arr[i]==atoi(cno)) break; }

     if(strcmp(tag,"encrypted")==0)
     {
          printf("msg has to b decrypted\n");
     }
     write(nsfd[i],buffer,strlen(buffer));
 
   }
   else
   {

      for(i=0;i<cnt;i++)
      {
         if(FD_ISSET(nsfd[i],&rfds))
         {
            printf("reading frm client %d\n",i);
            sleep(1);
            read(nsfd[i],gno,10);
            printf("group of sender %s\n",gno);
            sleep(1);
            read(nsfd[i],cno,10);
            printf("cno of sender %s\n",cno);
            sleep(1);
            read(nsfd[i],buffer,255);
            printf("msg %s\n",buffer);
             //decide and send to head of tree
            if(atoi(gno)==atoi(argv[1]))
            {
                 printf("msg to be sent in same group\n");
 
                 int j;
		 for(j=0;j<cnt;j++)
                 {
                    if(j+1==atoi(cno)) break;
                 }
                 write(nsfd[j],buffer,strlen(buffer));
             }
            else
            {
                   
                   strcpy(tag,"plain");
                   if( find_log(arr[i])!=find_log(atoi(cno)))
                   {
                  //msg has to b sent to the other server after encryption
                      //encrypt buffer
                       strcpy(tag,"encrypted");
                   }
                   write(sfd1,gno,strlen(gno));
                   write(sfd1,cno,strlen(cno));
                   write(sfd1,buffer,strlen(buffer));
                   write(sfd1,tag,strlen(tag));
           }
        } 
     }
  }
}
sleep(5);
}
  return 0;
}
