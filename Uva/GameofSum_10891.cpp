#include <bits/stdc++.h>
#define maxn 101
#define inf -99999999

using namespace std;
typedef long long ll;

ll arr[ maxn ];
ll memo[ maxn ][ maxn ];
bool vis[ maxn ][ maxn ];

ll dp( int l, int r )
{
	if( l > r )
		return 0;

	if( l == r )
		return arr[ l ];
	
	if( l == r-1 )
		return max( arr[ l ] + arr[ r ], max( arr[ l ] - arr[ r ], arr[ r ] - arr[ l ] ) );
	
	if( vis[ l ][ r ] )
		return memo[ l ][ r ];
	
	vis[ l ][ r ] = true;
	
	ll ans = arr[ l ] - dp( l+1, r ), cont = 0, aux;
	for( int i = l; i <= r; ++i )
	{
		cont += arr[ i ];
		aux = cont - dp( i+1, r );
		ans = max( ans, aux );
	}
	
	cont = 0;
	for( int i = r; i >= l; --i )
	{
		cont += arr[ i ];
		aux = cont - dp( l, i-1 );
		ans = max( ans, aux );
	}

	return memo[ l ][ r ] = ans;
}

int main()
{
	int n;

	cin >> n;
	while( n )
	{
		memset( vis, 0, sizeof vis );
		for( int i = 0; i< n; ++i )
			cin >> arr[ i ];

		cout << dp( 0, n-1 ) << '\n';
		cin >> n;
	}

	return 0;
}
