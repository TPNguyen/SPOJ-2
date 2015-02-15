#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverse(char a[])
{
	char b[1002] = {0};

	for (int i=0; i<strlen(a); ++i)
		b[i]=a[strlen(a)-i-1];
	
	return b;
}

int main()
{
	char a[1001] = {0};
	char b[1001] = {0};
	char c[1002] = {0};
	
	int t;
	scanf("%d", &t);

	for (int k=0; k<t; ++k)
	{
		scanf("%s %s", a, b);
		char carry = 0;

		for (int i=0; i<strlen(a)+1 || i<strlen(b)+1; ++i)
		{
			c[i] = ((i<strlen(a))?a[strlen(a)-i-1]:'0') + ((i<strlen(b))?b[strlen(b)-i-1]:'0') - '0' + carry;
			if (c[i]-'0' > 9)
			{
				carry  = 1;
				c[i] = c[i] - 10;
			}
			else
				carry = 0;
		}
		if (c[strlen(c)-1]=='0')
			c[strlen(c)-1]=0;

		char d[1002]={0};
		strcpy(d,reverse(c));
		printf("%s\n", d);

	}

	//char a[1000] = "10";

	//printf("a: \"%s\"\n",a);
	//printf("sizeof(a): %d\n", sizeof(a));
	//printf("strlen(a): %d\n", strlen(a));
	//for (int i=0; i<=strlen(a); ++i)
	//{
	//	printf("a[%d]: %d\n", i, (int) a[i]);
	//}

	/*char duza_liczba[1001];

	scanf("%s", duza_liczba);
	printf("%s\n", duza_liczba);

	int dlugosc = strlen(duza_liczba);

	int mala_liczba = 0;

	for (int i=dlugosc-1, k = 0; i>=0; --i)
	{
		mala_liczba+=(duza_liczba[i]-'0')*k;
		if (k)
			k*=10;
		else
			k=10;
	}

	printf("Liczbowo: %d", mala_liczba);
	*/
	return 0;
}