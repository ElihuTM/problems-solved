#include <bits/stdc++.h>
#define maxn 102
#define mod 100000000

using namespace std;

int memo[ maxn+maxn ][ maxn ][ maxn ][ 10 ][ 2 ];
int n1, n2, k1, k2;

int dp( int pos, int f, int h, int q, int op )
{
	if ( q < 0 || f < 0 || h < 0 )
		return 0;

	if ( pos == n1+n2 )
		return 1;

	if( ~memo[ pos ][ f ][ h ][ q ][ op ] )
		return memo[ pos ][ f ][ h ][ q ][ op ];

	int ans, ans2;
	if( op == 0)
	{
		ans  = dp( pos+1, f-1, h, q-1, 0 );
		ans2 = dp( pos+1, f, h-1, k2-1, 1 );
	}
	else
	{
		ans  = dp( pos+1, f, h-1, q-1, 1 );
		ans2 = dp( pos+1, f-1, h, k1-1, 0 );
	}

	return memo[ pos ][ f ][ h ][ q ][ op ] = (ans + ans2)% mod;
}

int main()
{
	memset( memo, -1, sizeof memo );
	cin >> n1 >> n2 >> k1 >> k2;
	int ans = dp( 1, n1-1, n2, k1-1, 0 );
	ans = ans + dp( 1, n1, n2-1, k2-1, 1 );

	cout << ans % mod << '\n';
}