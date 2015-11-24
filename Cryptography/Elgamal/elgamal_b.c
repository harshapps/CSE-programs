
#include <time.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/un.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <gmp.h>

int main()
{
	int sfd;
	struct sockaddr_in serv_addr;
	int port_no=8888;

	bzero(&serv_addr,sizeof(serv_addr));
    /**
        Create tcp socket using given parameters
    */
	if((sfd = socket(AF_INET , SOCK_STREAM , 0))==-1)
	perror("\n socket");
	else printf("\n socket created successfully\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
    /**
        Connect tcp socket using given parameters
    */
	if(connect(sfd , (struct sockaddr *)&serv_addr , sizeof(serv_addr))==-1)
	perror("\n connect : ");
	else printf("\nconnect succesful");

	char buf[256];
	read(sfd,buf,255);
	printf("\nText: %s",buf);

	mpz_t p,g;
	mpz_inits(p,g,NULL);

	read(sfd,buf,255);
	mpz_set_str(p,buf,10);
	gmp_printf("\nThe value of p passed: %Zd",p);

	read(sfd,buf,255);
	mpz_set_str(g,buf,10);
	gmp_printf("\nThe value of g passed: %Zd",g);


	mpz_t t,xb,yb,ya,ky,M,k_M,K,tmp;
	mpz_inits(t,xb,yb,ya,ky,M,k_M,K,tmp,NULL);
	mpz_set_ui(t,100);

	gmp_randstate_t state;
	gmp_randinit_mt(state);

	mpz_urandomm(xb,state,t);
	mpz_powm(yb,g,xb,p);

	//on recv of ya from A
	read(sfd,buf,255);
	mpz_set_str(ya,buf,10);
	gmp_printf("\nThe value of ya passed: %Zd",ya);
	//mpz_powm(ky,ya,xb,p);

	printf("\nEnter Message m:");
	gmp_scanf("%Zd",&M);

	mpz_urandomm(k_M,state,t);	

	mpz_powm(K,ya,k_M,p);

	mpz_powm(c1,g,k_M,p);

	mpz_mult(tmp,K,M);

	mpz_mod(c2,tmp,p);

	mpz_get_str(buf,10,c1);
	write(sfd,buf,255);
	mpz_get_str(buf,10,c2);
	write(sfd,buf,255);

	//gmp_printf("\nThe value of K : %Zd",ky);

	printf("\nSending yb to A\n");
	//sending ya to B
	mpz_get_str(buf,10,yb);
	write(sfd,buf,255);

	return 0;
}