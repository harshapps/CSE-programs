#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include "udsheader.cpp"

using namespace std;

int pfid1,pfid2,pfid3;
int *pf1,*pf2,*pf3;

int main()
{
	char path[][25]={"/tmp/tmp1.str","/tmp/tmp2.str","/tmp/tmp3.str"};
	int portno[3]={5521,5522,5523};
	int sfd[3], maxfds,i;
	char cc, c[1];
	struct sockaddr_in server, client;
	socklen_t clientlength;

	pfid1 = shmget(103,4,IPC_CREAT|0666);
    pf1 =  (int *)shmat(pfid1,NULL,0);

    pfid2 = shmget(104,4,IPC_CREAT|0666);
    pf2 =  (int *)shmat(pfid2,NULL,0);

    pfid3 = shmget(105,4,IPC_CREAT|0666);
    pf3 =  (int *)shmat(pfid3,NULL,0);
    *pf1=*pf2=*pf3=0;

    for(i=0;i<3;i++)
    {
    	if((sfd[i]=socket(AF_INET,SOCK_STREAM,0))<0)
	    {
      		close(sfd[i]);
      		perror("socket...");
      		exit(EXIT_FAILURE);
    	}

    	server.sin_family=AF_INET;
    	server.sin_addr.s_addr=inet_addr("127.0.0.1");
    	server.sin_port=htons(portno[i]);

    	if(bind(sfd[i],(struct sockaddr *)&server,sizeof(server))<0)
    	{
      		close(sfd[i]);
      		perror("bind..\n");
      		exit(EXIT_FAILURE);
    	}
    	listen(sfd[i],3);
    }
	
	//make sockets to connect to resource-servers
    struct sockaddr_un unixserver;
    int unsfd[3],usfd;
    for(int i=0;i<3;i++)
    {

        if((usfd = socket(AF_LOCAL , SOCK_STREAM , 0))<0)
        {
            printf("Could not create socket");
            return 0;
        }
        cout<<"Socket created for"<<i<<endl;
        

        bzero(&unixserver,sizeof(unixserver));
        unixserver.sun_family = AF_LOCAL;
        
        unlink(path[i]);
        
        cout<<"Binding to path "<<path[i]<<endl;
        fflush(stdout);
        strcpy(unixserver.sun_path,path[i]);

        if(bind(usfd,(struct sockaddr *)&unixserver,sizeof(unixserver))<0){
            cout<<"\nBIND FAILED";
            return 0;
        }

        listen(usfd,3);
        unsfd[i]=accept(usfd,NULL,NULL);
    }
    cout<<"\nALL RESOURCES UP AND RUNNING!\n";

	clientlength = sizeof(client);
	fd_set readfds;

	struct timeval tv;
	tv.tv_sec=5;
	tv.tv_usec=0;

	while(1)
	{
		FD_ZERO(&readfds);
		for(i=0;i<3;i++)
			FD_SET(sfd[i],&readfds);
		maxfds=sfd[0];

		for(i=0;i<3;i++)
		{
			if(sfd[i]>maxfds)
				maxfds=sfd[i];
		}

		select(maxfds+1,&readfds,NULL,NULL,&tv);
		for(i=0;i<3;i++)
		{
			if(FD_ISSET(sfd[0],&readfds))
			{
				int nsfd = accept(sfd[0], (struct sockaddr*) &client, &clientlength);
				if(*pf1==0)
				{
					*pf1=1;
					cout<<"\nPlatform 1 empty!";
					write_fd(unsfd[0], &cc, 1, nsfd);
				}
				else
				{
					cout<<"\nFull!";
				}
			}
			if(FD_ISSET(sfd[1],&readfds))
			{
				int nsfd = accept(sfd[1], (struct sockaddr*) &client, &clientlength);
				if(*pf2==0)
				{
					*pf2=1;
					cout<<"\nPlatform 2 empty!";
					write_fd(unsfd[1], &cc, 1, nsfd);
				}
				else
				{
					cout<<"\nFull!";
				}
			}
			if(FD_ISSET(sfd[2],&readfds))
			{
				int nsfd = accept(sfd[2], (struct sockaddr*) &client, &clientlength);
				if(*pf3==0)
				{
					*pf3=1;
					cout<<"\nPlatform 3 empty!";
					write_fd(unsfd[2], &cc, 1, nsfd);
				}
				else
				{
					cout<<"\nFull!";
				}
			}
		}
		//int nsfd = accept(sfd, NULL, NULL);

		/*
		recv(nsfd, &c, sizeof(c), 0);
		int servno = c[0]-'0';
		cout<<"\nClient requested resourse: "<<servno;
		write_fd(unsfd[servno] ,&cc, 1, nsfd);
		*/
	}
	for (int i = 0; i < 3; ++i)
		close(sfd[i]);
	return 0;
}