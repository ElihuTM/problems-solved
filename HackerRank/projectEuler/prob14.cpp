#include <bits/stdc++.h>
#define maxn 5000005

using namespace std;
typedef long long ll;

int memo[ maxn ];
int ans[ maxn ];

int dp( ll n )
{
	if( n < maxn && ~memo[ n ] )
		return memo[ n ];

	if( n > maxn )
	{
		int cont = 0;

		while( n > maxn )
		{
			if( n&1 )
				n = 3*n + 1;
			else
				n >>= 1;

			++cont;
		}

		return cont + dp( n );
	}

	if( n&1 )
		memo[ n ]= 1 + dp( 3*n + 1 );
	else
		memo[ n ] = 1 + dp( n/2 );

	return memo[ n ];
}

int main()
{
	memset( memo, -1, sizeof memo );
	memo[ 1 ] = 1;	
	ans[ 1 ] = 1;

	for( int i = 2; i < maxn; ++i )
	{
		ans[ i ] = i;
		dp( i );
		
		if( memo[ ans[ i-1 ] ] > memo[ i ] )
			ans[ i ] = ans[ i-1 ];
	}	

	int t, x;
	cin >> t;
	
	while( t-- )
	{
		cin >> x;
		cout << ans[ x ] << '\n';
	}

	return 0;
}
