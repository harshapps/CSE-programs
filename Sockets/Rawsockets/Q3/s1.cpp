#include "udsheader.cpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <pthread.h>
#define PATH "/tmp/tmp1.str"
#define SOURCE "127.0.0.2"
#define DEST "127.0.0.1"
using namespace std;

//for raw sockets
int s;
struct sockaddr_in daddr,saddr;
char packet[50];

ssize_t n;
char buf[1024];
int pfid1;
int *pf1,usfd;

void *cablerecv(void *ptr)
{
    while(1)
     {      
        recv(s, (char *)&packet, sizeof(packet), 0);
        perror("packet receive :");
        
        printf("\nmessage got is - %s",packet+sizeof(struct iphdr));
        
        printf("\nenter packet - ");
        scanf("%s",packet);
        
        send(s, (char *)packet, sizeof(packet), 0);
        perror("packet send :");
            
    }
    exit(EXIT_SUCCESS);
}

void *receive(void *ptr)
{   
    int fd;
    char c,d[25];
    read_fd(usfd, &c, 1, &fd);
    cout<<"\nRecieved an fd!";

    while(true)
    {
    	cout<"\nHarsha";
        n=recv(fd,buf,sizeof(buf),0);
        if(n>0)
        {
        	cout<<"\nbuf: "<<buf;
            send(fd,buf,n,0);
            bzero(buf,sizeof(buf));
        }
        else if(n==0)
        {
            *pf1=0;
        }
    }
}

int main()
{
    pfid1 = shmget(103,4,IPC_CREAT|0666);
    pf1 =  (int *)shmat(pfid1,NULL,0);

	int usfd;
    struct sockaddr_un server;
    if((usfd = socket(AF_LOCAL , SOCK_STREAM , 0))<0){
        printf("Could not create socket");
        return 0;
   	}
    cout<<"Socket created\n";
     
    bzero(&server,sizeof(server));
    server.sun_family = AF_LOCAL;
    strcpy(server.sun_path,PATH);

    cout<<"Binding to path "<<PATH<<endl;
    connect(usfd,(struct sockaddr *)&server,sizeof(server));
    cout<<"Connected to the co-ordinator server\n\n";
    
    /*Raw socket to connect to the cable*/
    s = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    perror("socket ");

    /*
    int zero=0;
    const int *val=&zero;

    setsockopt(s, IPPROTO_IP, IP_HDRINCL, val, sizeof(zero));
    perror("setsockopt() ");*/
    
    daddr.sin_family = AF_INET;
    daddr.sin_port = 0; /* not needed in SOCK_RAW */
    memset(daddr.sin_zero, 0, sizeof(daddr.sin_zero));
    inet_pton(AF_INET, DEST, (struct in_addr *)&daddr.sin_addr.s_addr);
    
    memset(packet, '\0', sizeof(packet));   /* payload will be all As */
    
    saddr.sin_family = AF_INET;
    saddr.sin_port = 0; /* not needed in SOCK_RAW */
    memset(saddr.sin_zero, 0, sizeof(saddr.sin_zero));
    inet_pton(AF_INET, SOURCE, (struct in_addr *)&saddr.sin_addr.s_addr);
    
    bind(s,(struct sockaddr*)&saddr,sizeof(saddr));
    perror("\nbind ");
    
    connect(s,(struct sockaddr*)&daddr,sizeof(daddr));
    perror("\nconnect ");


    pthread_t station, cable;
    pthread_create(&station, NULL, receive, NULL);
    pthread_create(&cable, NULL, cablerecv, NULL);
    pthread_join(station,NULL);

	return 0;
}