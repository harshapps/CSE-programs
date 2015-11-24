#include <stdlib.h>
#include <pthread.h>
#include "udsheader.cpp"
#define PATH "/tmp/tmp1.str"

using namespace std;

void clientproc(FILE *fp,int sfd)
{
    char sendline[1024],recvline[1024];

    while(fgets(sendline,1024,fp)!=NULL)
    {
        send(sfd,sendline,strlen(sendline),0);

        if(recv(sfd,recvline,1024,0)==0)
            cout<<"clientproc: premature termination of server\n";
        fputs(recvline,stdout);
        bzero(recvline,sizeof(recvline));
        cout<<"\n";
    }
}

int main()
{
    int sfd;
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(5521);

    if((sfd = socket(AF_INET , SOCK_STREAM , 0))<0){
        printf("Could not create socket");
        return 0;
    }
    cout<<"Socket created\n";
     
    connect(sfd,(struct sockaddr *)&server,sizeof(server));
    /*
    cout<<"Enter the service required...\n"; //asssume it to be 2 lol
    int j;cin>>j;
    char c[1];
    c[0]=j+'0';
    cout<<c[0];
    send(sfd,c,1,0);
    */
    clientproc(stdin,sfd);

    exit(0);
}