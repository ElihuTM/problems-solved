#include <bits/stdc++.h>
#define maxn 1004

using namespace std;
typedef pair <int,int>	pii;

int memo[ maxn ];
vector< pii > lista[ maxn ];

int dp( int nodo )
{
	if( ~memo[ nodo ] )
		return memo[ nodo ];

	int ans = 0;
	int len = lista[ nodo ].size();
	for( int  i = 0; i < len; ++i )
	{
		int v = lista[ nodo ][ i ].first;
		int d = lista[ nodo ][ i ].second;

		ans = max( ans, dp( v )+d );
	}

	return memo[ nodo ] = ans;
}

int main()
{
	int n, m, a, b, c;
	memset( memo, -1, sizeof memo );

	cin >> n >> m;

	for( int i = 0; i < m; ++i )
	{
		cin >> a >> b >> c;
		lista[ a-1 ].push_back( make_pair( b-1, c ) );
	}

	int ans = 0;
	for( int i = 0; i < n; ++i)
		ans = max( ans, dp( i ) );

	cout << ans << '\n';
	return 0;
}
