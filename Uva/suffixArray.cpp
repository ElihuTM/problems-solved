///Suffix en complejidad O(nlog^2n)

#include <bits/stdc++.h>
#define maxn 1007

using namespace std;

char T[ maxn ]; ////Cadena que procesaremos
int sa[ maxn ]; ////Suffix Array
int ra[ maxn ]; 
int c[ maxn ];
int n;

void countingSort( int k )
{
	int i, sum, maxi = max( 300, n );
	memset( c, 0, sizeof c );
	for (int i = 0; i < n; ++i)
		c[ i + k < n ? ra[ i+k ] : 0 ]++;

	for (int i = sum = 0; i < maxi; ++i)
	{
		int t = c[ i ];
		c[ i ] = sum;
		sum += t;
	}

	for (int i = 0; i < n; ++i)
	{
		
	}
}

int main()
{

	return 0;
}