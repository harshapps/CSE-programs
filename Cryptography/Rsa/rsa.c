#include <stdio.h>
#include <gmp.h>

int main()
{
	mpz_t t,e,p,q,n,C,M,Qn,sp,sq,tmp,d;
	char ip[200];
	mpz_inits(t,e,p,q,n,C,Qn,sp,sq,tmp,d,M,NULL);

	/*
	gmp_printf("\nEnter p: ");
	gmp_scanf("%Zd",&p);
	gmp_printf("\nEnter q: ");
	gmp_scanf("%Zd",&q);
	*/

	gmp_randstate_t state;
	gmp_randinit_default(state);

	mpz_urandomb(p,state,512);
	mpz_nextprime(p,p);

	mpz_urandomb(q,state,512);
	mpz_nextprime(q,q);

	mpz_mul(n,p,q);
	gmp_printf("\nValue of n: %Zd",n);

	mpz_set_ui(tmp,1);
	//mpz_set_ui(e,2);
	mpz_sub(sp,p,tmp);
	mpz_sub(sq,q,tmp);
	mpz_mul(Qn,sp,sq);
	gmp_printf("\nValue of Q(n): %Zd",Qn);	

	mpz_urandomb(e,state,512);
    mpz_gcd(t,e,Qn);
    while(mpz_cmp(tmp,t)!=0)
    {
    	mpz_add(e,e,tmp);
    	mpz_gcd(t,e,Qn);
    }
	gmp_printf("\nValue of e: %Zd",e);	

	/*
	mpz_sub(t,Qn,tmp);  //sp = Qn-1;
 	mpz_mul(sp,e,t);    //sq = e*(Qn-1);
	mpz_mod(sq,sp,Qn);

	while(mpz_cmp(tmp,sq)!=-1)
	{
		mpz_sub(t,Qn,tmp);  //sp = Qn-1;
 		mpz_mul(sp,e,t);    //sq = e*(Qn-1);
		mpz_mod(sq,sp,Qn);
	}
	
	mpz_set(d,t);
	*/
	mpz_invert(d,e,Qn);
	gmp_printf("\nValue of d: %Zd",d);	

	char msg[256];
	gmp_printf("\nEnter the message: ");
	//gmp_scanf("%Zd",&M);
	fgets(msg,256,stdin);
	mpz_set_str(M,msg,62);


	mpz_powm(C,M,e,n);
	gmp_printf("\nCipher Text: %Zd",C);
	mpz_powm(M,C,d,n);
	char dmsg[256];
	mpz_get_str(dmsg,62,M);                                     
	gmp_printf("\nDecrypted Text: %s\n",dmsg);

	return 0;
}
