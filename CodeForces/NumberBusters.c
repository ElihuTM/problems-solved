#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, w, x, c, cont = 0, dist;
	scanf("%d %d %d %d %d", &a, &b, &w, &x, &c );

	while( c > a )
	{
		if( b < x ) {
			++cont;
			--a;
			--c;
			b += w-x;
		} else if( b == x ) {
			++cont;
			b -= x;
			--c;
		} else {
			dist = (int)ceil( (float)((float)(b-x)/(float)(x)) );
			b -= dist*x;
			c -= dist;
			cont += dist;
			a--;
			b += w;
		}
	}

	printf("%d\n", cont);
	return 0;
}