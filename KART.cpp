//#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	unsigned t = 0;

    scanf("%ud", &t);

	while (t--)
	{
        unsigned n = 0;
        scanf("%ud", &n);

        unsigned number_of_zeros = 0;
        unsigned divisor = 5;
        unsigned increment = 0;
        while (increment = n / divisor)
        {
            number_of_zeros += increment;
            divisor *= 5;
        }

        printf("%d\n", number_of_zeros);
	}

	return 0;
}
