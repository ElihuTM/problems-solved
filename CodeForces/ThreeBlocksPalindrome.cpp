#include <bits/stdc++.h>
#define ff first
#define ss second
#define maxn 201

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi acumulada;
vvi apariciones;

int findans( int a, int b )
{
	if ( b < a )
		return -1;

	int ans = 0;
	for (int i = 0; i < maxn; ++i)
		ans = max( ans, acumulada[ i ][ b ] - acumulada[ i ][ a-1 ] );

	return ans;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t, n, a, b;

	cin >> t;
	while( t-- )
	{
		cin >> n;

		acumulada = vvi( maxn, vi( n,0 ) );
		apariciones = vvi( maxn );

		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			acumulada[ a ][ i ] = 1;
			apariciones[ a ].push_back( i );
		}

		for (int i = 0; i < maxn; ++i)
			for (int j = 1; j < n; ++j)
				acumulada[ i ][ j ] += acumulada[ i ][ j-1 ];

		int ans = 0, len;
		for (int i = 0; i < maxn; ++i)
			ans = max( ans, acumulada[ i ][ n-1 ] );

		for (int i = 0; i < maxn; ++i)
		{
			len = apariciones[ i ].size();
			for (int j = 0; j < len/2; ++j)
			{
				a = apariciones[ i ][ j ] + 1;
				b = apariciones[ i ][ len-j-1 ] - 1;
				ans = max(ans, 2*(j+1) + findans( a, b ) );
			}
		}

		cout << ans << '\n';
	}

	return 0;
}	