#include <stdio.h>
#include <gmp.h>

void gcd(mpz_t a,mpz_t b)
{
	mpz_t tmp,tmp2,rm,xm,ym,r0,x0,y0,xi,yi,qi,ri,zr,gcdres;
	mpz_inits(rm,r0,xm,ym,x0,y0,xi,yi,qi,ri,tmp,tmp2,NULL);
	mpz_init(gcdres);
	mpz_init(zr);
	mpz_set(rm,a);
	mpz_set(r0,b);
	mpz_set_ui(zr,0);
	mpz_set_ui(xm,1);
	mpz_set_ui(ym,0);
	mpz_set_ui(x0,0);
	mpz_set_ui(y0,1);

	mpz_mod(ri,rm,r0);
	mpz_div(qi,rm,r0);
	while(mpz_cmp(ri,zr)!=0)
	{
		mpz_mul(tmp,qi,x0);
		mpz_sub(xi,xm,tmp);
		mpz_mul(tmp,qi,y0);
		mpz_sub(yi,ym,tmp);
		
		mpz_set(rm,r0);
		mpz_set(r0,ri);
		mpz_set(xm,x0);
		mpz_set(x0,xi);
		mpz_set(ym,y0);
		mpz_set(y0,yi);

		mpz_mod(ri,rm,r0);
		mpz_div(qi,rm,r0);
	}

	mpz_mul(tmp,a,xi);
	mpz_mul(tmp2,b,yi);
	mpz_add(gcdres,tmp,tmp2);
	gmp_printf("\n a%Zd *x %Zd + b %Zd *y %Zd\n", a,xi,b,yi);
	gmp_printf("\nGCD is %Zd\n", gcdres);
}

int main()
{
	mpz_t a,b,zr;
	mpz_init(zr);
	mpz_set_ui(zr,0);
	mpz_init(a);
	mpz_init(b);
	gmp_printf("Enter value of A\n");	
	gmp_scanf("%Zd",&a);	
	gmp_printf("Enter value of B\n");
	gmp_scanf("%Zd",&b);
	if(mpz_cmp(a,zr)==0)
		gmp_printf("\nGCD is %Zd",b);
	if(mpz_cmp(b,zr)==0)
		gmp_printf("\nGCD is %Zd",a);

	else
		gcd(a,b);

	return 0;
}