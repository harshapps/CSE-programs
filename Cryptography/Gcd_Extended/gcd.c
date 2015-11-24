#include<stdlib.h>
#include<stdio.h>
#include<gmp.h>

void gcd(mpz_t res, mpz_t a, mpz_t b)
{
	mpz_t c,d;
	mpz_init(c);
	mpz_init(d);
	while(mpz_cmp(a,d)>0)
	{
		//printf("\nIm here!");
		mpz_set(c,a);
		mpz_mod(a,b,a);
		gmp_printf("a: %Zd \n",a);
		mpz_set(b,c);
	}
	mpz_set(res,b);
}

int main()
{
	mpz_t r,n1,n2,res;
	mpz_init(r);
	mpz_init_set_str(n1,"123456",0);
	mpz_init_set_str(n2,"12345678",0);
	gcd(r,n1,n2);	
	gmp_printf("Ans: %Zd \n",r);
	return 0;
}
