#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>


int main()
{
	if (int i=1)
		if (scanf("%d", &i))
			if (int k=1)
				if (scanf("%d", &k))
					if (!printf("%d", i+k ))
					{}
}