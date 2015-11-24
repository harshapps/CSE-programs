#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SOURCE "127.0.0.2"
#define DEST "127.0.0.1"


int main(void)
{

	int s,a[]={1,2,3},i;
	struct sockaddr_in daddr,saddr;
	char packet[50];

	s = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	perror("socket ");

	int zero=0;
	const int *val=&zero;

	setsockopt(s, IPPROTO_IP, IP_HDRINCL, val, sizeof(zero));
	perror("setsockopt() ");
	
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
	
	while(1)
	{		
		int n = recv(s, (char *)&packet, sizeof(packet), 0);
		//perror("packet receive :");
		if(n>0)
		{
			printf("\nReceived from Judge: - %s",packet+sizeof(struct iphdr));

			char buffer[50];
			int i;
			for(i=0;i<(n-sizeof(struct iphdr));i++)
			{
				buffer[i]=packet[sizeof(struct iphdr) + i];
			}
			int servno = atoi(buffer);	

			int count=0;
			for(i = 0; i < 3; ++i)
			{
				if(a[i]==servno)
				{
					a[i]=0;
					break;
				}
			}
			for(i=0;i<3;i++)
			{
				if(a[i]==0)
					count++;
			}
			printf("\nCount: %d\n",count);
			if(count==3)
			{
				strcpy(packet,"I'm done! - 1");
				send(s, (char *)packet, sizeof(packet), 0);
				perror("packet send :");
				printf("I'm done!!\n");
				break;
			}
		//printf("\nenter packet - ");
		//scanf("%s",packet);
			send(s, (char *)packet, sizeof(packet), 0);
			perror("packet send :");
		}
		//int servno=packet[0]-'0';
        //cout<<"Received from Judge: "<<servno<<endl;
	}
	exit(EXIT_SUCCESS);
}
