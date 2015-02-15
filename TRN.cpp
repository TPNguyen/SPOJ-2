#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m = 0, n = 0;
	int *matrix;

	scanf("%d %d", &m, &n);
	matrix = (int*) calloc(m*n, sizeof(int));

	for (int i=0; i<m*n; ++i)
	{
		scanf("%d", &matrix[i]);
	}

	for (int i=0; i<n; ++i)
	{
		for (int k=0; k<m; ++k)
		{
			printf("%d ", matrix[i+k*n]);
		}
		printf("\n");
	}

	free(matrix);

	return 0;
}


//int main()
//{
//	int m = 0, n = 0;
//	int matrix[4000];
//
//	scanf("%d %d", &m, &n);
//
//	for (int i=0; i<m*n; ++i)
//	{
//		scanf("%d", &matrix[i]);
//	}
//
//	for (int i=0; i<n; ++i)
//	{
//		for (int k=0; k<m; ++k)
//		{
//			printf("%d ", matrix[i+k*n]);
//		}
//		printf("\n");
//	}
//	return 0;
//}