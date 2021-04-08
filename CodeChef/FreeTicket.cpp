#include <bits/stdc++.h>
#define maxn 300
#define inf 100000000

using namespace std;

int floyd[ maxn ][ maxn ];

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	memset( floyd, -1, sizeof floyd );
	int n, m, a, b, c;

	cin >> n >> m;

	for( int i = 0; i < n; ++i )
		for( int j = 0; j < n; ++j )
			if( i == j )
				floyd[ i ][ j ] = 0;
			else
				floyd[ i ][ j ] = inf;

	for( int i = 0; i < m; ++i )
	{
		cin >> a >> b >> c; --a; --b;
			floyd[ a ][ b ] = min( floyd[ a ][ b ], c );

		floyd[ b ][ a ] = floyd[ a ][ b ];
	}

	for( int k = 0; k < n; ++k )
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < n; ++j)
			{
				int min = floyd[ i ][ k ] + floyd[ k ][ j ];
				if( min < floyd[ i ][ j ] )
					floyd[ i ][ j ] = min;
			}

	int ans = 0;
	for( int i = 0; i < n; ++i )
		for( int j = i+1; j < n; ++j )
			if( floyd[ i ][ j ] < inf )
				ans = max( ans, floyd[ i ][ j ] );

	cout << ans << '\n';
	return 0;
}
