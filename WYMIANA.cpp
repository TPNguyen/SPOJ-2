#include<stdio.h>

int main()
{
	int x, y;
	scanf("%d %d",&x,&y);

	// reszta programu napisana przez Ciebie; ten komentarz można usunąć
	x += y; // x + y
	y += x; // y + x + y
	x -= y; // -y
	x = -x; // y
	y = y - 2 * x; // x

	printf("%d %d",x,y);
	return 0;
}
