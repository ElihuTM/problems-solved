#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int arr[ maxn ];
int n, k;

bool is_pos( int m )
{
	int cont = 0, sum = 0;
	int ini = 0;
	for( int i = 0; i < n; ++i )
	{
		if( arr[ i ] - arr[ ini ] > m )
		{
			++cont;
			ini = i;
		}
	}
	++cont;

	return cont <= k;
}

int l_b( int i, int j )
{
	int m;
	while( j-i > 1 )
	{
		m = i + (j-i) / 2;

		if( is_pos( m ) )
			j = m;
		else
			i = m;
	}
	return j;
}

int main()
{
	int t;

	scanf("%d", &t);
	while( t-- )
	{
		scanf("%d %d", &k, &n);
		
		for( int i = 0; i < n; ++i )
			cin >> arr[ i ];
		
		if( k >= n )
			printf("0.0\n");
		else
		{
			sort( arr, arr + n );
			printf("%.1f\n", (double)l_b( 0, 1000005 )/2.0 );
		}
	}
	return 0;
}
