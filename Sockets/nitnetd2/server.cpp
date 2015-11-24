#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <string.h>
#include <arpa/inet.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<pthread.h>
#include<iostream>
#include<vector>
#include<sys/select.h>
#include<signal.h>
#define SERV_PORT 9890
#define SA struct sockaddr
#define LISTENQ 100
#define noofprocesses 3
#define noofthreads 3
using namespace std;
int s1pids[25];int s1count=0;int s2count=0;int s5pid;int s5count,nsfd;
void *s2function(void* ptr)
{
  int connfd=*(int *)(ptr);
  while(1)
  {
    char buf[30];
    int n=recv(connfd,buf,30,0);
    if(n==0){s2count--;break;}
    send(connfd,buf,n,0);
  } 
}
void sigchildhandler(int signo)
{
  int status;
  int pid=waitpid(-1,&status,WNOHANG);
  cout<<"gdf1\n";
  int flag=0;
  for(int i=0;i<s1count;i++)
  if(pid==s1pids[i])
  {
     s1count--;cout<<"gdf2\n";
     for(int j=i;j<s1count;j++)s1pids[i]=s1pids[i+1];
     return;
  }
  if(pid==s5pid){s5pid=0;s5count=0;}
  return;
}
int main()
{
  signal(SIGCHLD,sigchildhandler);
  int sockfds[5];int portno[5]={6880,6881,6882,6883,6884};
  struct sockaddr_in servaddr;
  struct sockaddr_in cliaddr;
  socklen_t clilen;
  clilen = sizeof(cliaddr);	
  for(int i=0;i<5;i++)
  {
    if(i==2 || i==4)
    {
       bzero(&servaddr,sizeof(servaddr));	
       servaddr.sin_family = AF_INET;
       servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
       sockfds[i]= socket(AF_INET,SOCK_DGRAM,0);
       servaddr.sin_port=htons(portno[i]);
       bind(sockfds[i],(SA*) &servaddr,sizeof(servaddr));
    }
    else
    {
       bzero(&servaddr,sizeof(servaddr));	
       servaddr.sin_family = AF_INET;
       servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
       sockfds[i]= socket(AF_INET,SOCK_STREAM,0);
       servaddr.sin_port=htons(portno[i]);
       bind(sockfds[i],(SA*) &servaddr,sizeof(servaddr));
       listen(sockfds[i],LISTENQ);
    }
  }
  fd_set rfds;
  struct timeval selecttime;
  selecttime.tv_sec=0;
  selecttime.tv_usec=60;
  int maxfd=0;
  for(int i=0;i<5;i++)if(sockfds[i]>maxfd)maxfd=sockfds[i];
  for(;;)
  {
    l1:
    FD_ZERO(&rfds);
    for(int i=0;i<5;i++)FD_SET(sockfds[i],&rfds);
    select(maxfd+1,&rfds,NULL,NULL,&selecttime);
    if(FD_ISSET(sockfds[1],&rfds))
    {
      if(s2count<15)
      {
         nsfd=accept(sockfds[1],(SA*) &cliaddr, &clilen);
         s2count++;
         pthread_t t;
         pthread_create(&t,NULL,&s2function,&nsfd);
         pthread_join(t,NULL);
      }
    }
    if(FD_ISSET(sockfds[0],&rfds))
    {
       if(s1count<25)
       {
          int f=fork();
          nsfd=accept(sockfds[0],(SA*) &cliaddr, &clilen);
          if(f==0)
          {
              for(int i=0;i<5;i++)close(sockfds[i]);
              dup2(nsfd,0);
              dup2(nsfd,1);
              dup2(nsfd,2);
              execl("./s1proc.out","dhd",(char*)0);
          }
          else
          {
             close(nsfd);
             s1pids[s1count++]=f;
             goto l1;
          }
       }
    }
  }
  return 0;
}
