#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
	char *t=a;
	a=b;
	b=t;
}

int i,j;
void ksp(char s[], char *key, int keyleng)
{
	for(i=0;i<256;i++)
		s[i]=i;
	j=0;	
	for(i=0;i<256;i++)
	{
		j = (j + s[i] + key[(i % keyleng)]) % 256;
        swap(&s[i], &s[j]);
	}
}

void prga(char s[], char *stream, int length)
{
	i=0,j=0;int k=0;

	while(length--)
	{
		i = (i+1) % 256;
        j = (j+s[i]) % 256;
        swap(&s[i], &s[j]);
        stream[k++] = s[(s[i]+s[j]) % 256];
	}
}

int main()
{
	char s[256];
	char *text = (char *) malloc(256);
	char *key = (char *) malloc(256);
	char *stream = (char *) malloc(256);
	char *enc = (char *) malloc(256);
	char *dec = (char *) malloc(256);

	int p;
	printf("Enter Plain Text : ");       
    scanf("%s",text);
    printf("Enter your KEY : ");
    scanf("%s",key);
	

	ksp(s,key,strlen(key));
	prga(s,stream,strlen(key));

	printf("\nThe Encrypted Text : ");
	for(p=0;p<strlen(text);p++)
	{
		enc[p] = stream[p] ^ text[p];
	}
	printf("%s\n",enc);        

	printf("\nThe Decrypted Text : ");
	for(p=0;p<strlen(text);p++)
	{
		dec[p] = stream[p] ^ enc[p];
	}
	printf("%s\n",dec);        

	return 0;
}