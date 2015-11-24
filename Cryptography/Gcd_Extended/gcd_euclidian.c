#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void gcd(mpz_t a,mpz_t b)
{
	if(mpz_cmp(a,b)!=0)
	{

		if(mpz_cmp(a,b)>0)
		{
			mpz_sub(a,a,b);
			gcd(a,b);
		}
		else if(mpz_cmp(a,b)<0)
		{
			mpz_sub(b,b,a);
			gcd(a,b);
		}
	}
	else
	gmp_printf("gcd is :%Zd\n",a);
}
int main()
{
	mpz_t a,b;
	mpz_init(a);
	mpz_init(b);
	gmp_printf("Enter value of A\n");	
	gmp_scanf("%Zd",&a);	
	gmp_printf("Enter value of B\n");
	gmp_scanf("%Zd",&b);
	gcd(a,b);

return 0;

}
