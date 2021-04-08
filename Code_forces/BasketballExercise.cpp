#include <bits/stdc++.h>
#define maxn 100007

using namespace std;
typedef long long ll;

ll arr[ 2 ][ maxn ];
ll memo[ 2 ][ maxn ];
ll ans[ maxn ];

int main()
{
	int n;
	memset( memo, 0, sizeof memo );
	memset( ans, 0, sizeof ans );

	cin >> n;
	for( int i = 0; i < n; ++i )
		cin >> arr[ 0 ][ i ];
	for( int i = 0; i < n; ++i )
		cin >> arr[ 1 ][ i ];
	
	memo[ 0 ][ n-1 ] = arr[ 0 ][ n-1 ];
	memo[ 1 ][ n-1 ] = arr[ 1 ][ n-1 ];
	ans[ n-1 ] = max( memo[ 0 ][ n-1 ], memo[ 1 ][ n-1 ] );

	for( int i = n-1; i >= 0; --i )
	{
		memo[ 0 ][ i ] = max( arr[ 0 ][ i ] + memo[ 1 ][ i+1 ], arr[ 0 ][ i ] + ans[ i+2 ] );
		memo[ 1 ][ i ] = max( arr[ 1 ][ i ] + memo[ 0 ][ i+1 ], arr[ 1 ][ i ] + ans[ i+2 ] );
		ans[ i ] = max( memo[ 0 ][ i ], memo[ 1 ][ i ] );
	}

	cout << ans[ 0 ] << '\n';
	return 0;
}
