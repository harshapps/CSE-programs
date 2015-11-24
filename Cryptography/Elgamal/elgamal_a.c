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
	struct sockaddr_in serv_addr,cli_addr;
	socklen_t cli_len=sizeof(struct sockaddr_in);
	int port_no=8888;
    /**
        Create tcp socket using given parameters
    */
	if((sfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	perror("\n socket ");
	else printf("\n socket created successfully");

	bzero(&serv_addr,sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
    /**
        Bind created socket to an interface
    */
	if(bind(sfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))==-1)
	perror("\n bind : ");
	else printf("\n bind successful ");

    /**
        Listen for incoming connection
    */
	listen(sfd,10);

	int nsfd;
	/**
        Accept connection if any one requested over this port and ip address
	*/
	if((nsfd = accept(sfd , (struct sockaddr *)&cli_addr , &cli_len))==-1)
	perror("\n accept ");
	else printf("\n accept successful");
	
	char buf[256];
	printf("\nEnter text: ");
	
	read(0,buf,255);
	write(nsfd,buf,255);

	/*	Generator Starts here	*/

	mpz_t q1,q2,q3,p,t,t1,limit,y1,y2,y3,t2,t4,g;
	mpz_inits(q1,q2,q3,p,t,t1,limit,y1,y2,y3,t2,t4,g,NULL);
	mpz_set_ui(t,1);
	mpz_set_ui(t1,100);
	int k;

	gmp_randstate_t state;
	gmp_randinit_mt(state);

	mpz_set_ui(q1,2);
	while(k!=2)
	{
		mpz_urandomm(q2,state,t1);
		mpz_nextprime(q2,q2);

		mpz_urandomm(q3,state,t1);
		mpz_nextprime(q3,q3);		

		mpz_mul(p,q1,q2);
		mpz_mul(p,p,q3);
		mpz_add(p,p,t);

		k=mpz_probab_prime_p(p,100);
	}

	gmp_printf("\nThe value of p: %Zd \n",p);
	mpz_set_ui(limit,20);

	mpz_urandomm(g,state,limit);
	mpz_sub(t2,p,t);

	k=1;
	while(k==1)
	{
		mpz_divexact(y1,t2,q1);
		mpz_divexact(y2,t2,q2);
		mpz_divexact(y3,t2,q3);

		mpz_powm(t4,g,y1,p);
		if(mpz_cmp(t4,t)==0)
		{
			mpz_urandomm(g,state,t1);
			continue;
		}

		mpz_powm(t4,g,y2,p);
		if(mpz_cmp(t4,t)!=1)
		{
			mpz_urandomm(g,state,t1);
			continue;
		}

		mpz_powm(t4,g,y3,p);
		if(mpz_cmp(t4,t)!=1)
		{
			mpz_urandomm(g,state,t1);
			continue;
		}
		k=0;
	}
	gmp_printf("\nThe value of g: %Zd \n",g);

	//sending p to B
	mpz_get_str(buf,10,p);
	write(nsfd,buf,255);
	//sending g to B
	mpz_get_str(buf,10,g);
	write(nsfd,buf,255);

	mpz_t xa,ya,yb,ky;
	mpz_inits(xa,ya,yb,ky,NULL);

	mpz_urandomm(xa,state,t1);
	mpz_powm(ya,g,xa,p);

	printf("\nSending ya to B");
	//sending ya to B
	mpz_get_str(buf,10,ya);
	write(nsfd,buf,255);	

	//recving c1 and c2
	read(sfd,buf,255);
	mpz_set_str(c1,buf,10);
	gmp_printf("\nThe value of c1 passed: %Zd",c1);
	
	read(sfd,buf,255);
	mpz_set_str(c2,buf,10);
	gmp_printf("\nThe value of c2 passed: %Zd",c2);
	

	return 0;
}