#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi lista;
vi memo;
vi ans;
vi a;

int dp( int u , int father )
{
	memo[ u ] = a[ u ];
	for ( auto v: lista[ u ] )
		if ( v != father )
			memo[ u ] += max( 0, dp( v, u ) );

	return memo[ u ];
}

void dp2( int u, int father )
{
	ans[ u ] = memo[ u ];

	for (auto v: lista[ u ] )
		if ( v != father )
		{
			memo[ u ] -= max( 0, memo[ v ] );
			memo[ v ] += max( 0, memo[ u ] );
			dp2( v, u );
			memo[ v ] -= max( 0, memo[ u ] );
			memo[ u ] += max( 0, memo[ v ] );
		}
}
int main()
{
	int n, u, v;
	cin >> n;

	memo = ans = a = vi( n );
	lista = vvi( n );

	for (int i = 0; i < n; ++i)
	{
		cin >> a[ i ];
		a[ i ] = ( a[ i ] == 0 ? -1 : 1 );
	}

	for (int i = 0; i < n-1; ++i)
	{
		cin >> u >> v; --u; --v;
		lista[ u ].push_back( v );
		lista[ v ].push_back( u );
	}

	dp( 0, -1 );
	dp2( 0, -1 );

	for (int i = 0; i < n; ++i)
		cout << ans[ i ] << ' ';
	cout << endl;
	return 0;
}