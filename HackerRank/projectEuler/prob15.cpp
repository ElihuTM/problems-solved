#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 1002

using namespace std;
typedef long long ll;

ll memo[ maxn ][ maxn ];

ll comb( int n, int k )
{
	if( n == 0 || k == 0 || k == n )
		return 1;
	
	if( ~memo[ n ][ k ] )
		return memo[ n ][ k ];
	
	return memo[ n ][ k ] = (comb( n-1,k ) + comb( n-1, k-1 ) ) % mod;
}

int main()
{
	memset( memo, -1, sizeof memo );
	int t, n, m;

	cin >> t;
	while( t-- )
	{
		cin >> n >> m;
		cout << comb( n+m, n ) << '\n';
	}
	return 0;
}
