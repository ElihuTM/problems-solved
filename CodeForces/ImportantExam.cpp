#include <bits/stdc++.h>
#define maxn 1007

using namespace std;
typedef long long ll;

int main()
{
	ll arr[ maxn ][ 26 ];
	ll maxi[ maxn ];

	int n, m, aux;
	ll ans = 0;
	char c;

	cin >> n >> m;
	memset( arr, 0, sizeof arr );
	memset( maxi, 0,  sizeof maxi );

	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < m; ++j)
		{
			cin >> c;
			++arr[ j ][ c - 'A' ];

			if( arr[ j ][ c - 'A'] > maxi[ j ] )
				maxi[ j ] = arr[ j ][ c -'A' ]; 
		}
	}

	for( int i = 0; i < m; ++i )
	{
		cin >> aux;
		ans += ( aux * maxi[ i ] );
	}

	cout << ans << '\n';
	return 0;
}
