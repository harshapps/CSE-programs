#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SOURCE "127.0.0.2"
#define DEST "127.0.0.3"

int main(void)
{

	int s;
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
	
	connect(s,(struct sockaddr*)&daddr,sizeof(daddr));
	perror("\nconnect ");
	
	while(1)
	 {
		printf("\nenter packet - ");
		scanf("%s",packet);
		
		send(s, (char *)packet, sizeof(packet), 0);
		perror("packet send :");
			
			
		recv(s, (char *)&packet, sizeof(packet), 0);
		perror("packet receive :");
			
		printf("\nmessage got is - %s",packet+sizeof(struct iphdr));
	}
	exit(EXIT_SUCCESS);
}
