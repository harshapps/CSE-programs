#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0;
	mpz_t a,i,t,q,res1,res2,res;
	mpz_init(a);mpz_init(t);mpz_init(q);mpz_init(i);
	mpz_init(res1);mpz_init(res2);mpz_init(res);
	//printf("Enter the Number :\n");
	mpz_set_si(a, 5653565);		// to randomly generate huge prime
	mpz_nextprime(a,a);		//
	gmp_printf("The value of a =  %Zd \n",a);
	//mpz_inp_str(a,stdin,10);
	mpz_set_si(i,2);	// i=2
	mpz_set_si(res,1);	//res = 1
	
	while(mpz_cmp_ui(a,1)!=0)	//while(a!=1)
	{
		mpz_mod(t,a,i);		// t = a%i
		if(mpz_cmp_ui(t,0)==0)	//if(t == 0)
		{
			count++;
			mpz_tdiv_q(a,a,i);	// a = a/i
		}
		else if(count>0)
		{
			mpz_pow_ui(res1,i,count);	// res1 = i^count
			mpz_pow_ui(res2,i,count-1);	// res2 = i^(count-1)
			mpz_sub(res1,res1,res2);	// res1 = res1-res2
			mpz_mul(res,res,res1);		// res = res*res1
			mpz_nextprime(i,i);		// get the next prime value
			count = 0;
		}
		else
		{
			mpz_nextprime(i,i);
		}
	}
	
	mpz_pow_ui(res1,i,count);
	mpz_pow_ui(res2,i,count-1);
	mpz_sub(res1,res1,res2);
	mpz_mul(res,res,res1);
	gmp_printf("The value is  %Zd \n",res);
}

