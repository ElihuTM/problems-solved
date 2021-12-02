#include <iostream>
#define maxn 100

using namespace std;

char *cad[ 2 ];

int main()
{
	int n, k, t;
	scanf("%d", &t);

	cad[ 0 ] = "Bob";
	cad[ 1 ] = "Alice";
	
	while( t-- )
	{
		scanf("%d%d", &n, &k );

		if ( k%3 != 0 || n < k)
			printf( "%s\n", cad[ ((n%3) != 0) ] );
		else if ( n == k )
			printf("%s\n", cad[ 1 ] );
		else
		{
			n = (n-k+3)%(k+1);

			if ( n < 4)
				printf("%s\n", cad[ (n != 0) ] );
			else
			{
				 n -= 4;
				 printf("%s\n", cad[ ((n%3) != 0) ] );
			}
		}
	}	
	return 0;
}