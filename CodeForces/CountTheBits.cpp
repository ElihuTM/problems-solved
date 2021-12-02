#include <bits/stdc++.h>
#define mod 1000000009

using namespace std;
typedef long long ll;

ll pot_2[ 130 ];
ll memo[ 130 ][ 1005 ];
int n, k;

ll dp( int pos, int m )
{
	if( pos == n )
		return m == 0;
	
	//if( ~memo[ pos ][ m ] )
	//	return memo[ pos ][ m ];

	ll op1 = dp( pos+1, ( m + pot_2[ pos ] ) % k );
	ll op2 = dp( pos+1, m );

	ll ans = 0;
	if( op1 != 0 )
		ans += 1+op1;

	if( op2 != 0 )
		ans += op2;

	return memo[ pos ][ m ] = (ans%mod);
}

int main()
{
	pot_2[ 0 ] = 1;
	memset( memo, -1, sizeof( memo ) );

    cin >> k >> n;     for( int i = 0; i < 130; ++i )         pot_2[ i ] =
(pot_2[ i-1 ]*2) % k;     cout << dp( 0, 0 ) << '\n';     return 0; }
