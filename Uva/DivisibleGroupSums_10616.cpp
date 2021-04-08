#include <bits/stdc++.h>
#define maxn 203
#define modu 23
#define inf -999999999

using namespace std;

int memo[ maxn ][ modu ][ 13 ];
int arr[ maxn ];
int n,q, d, m;

int dp( int pos, int mod, int rest )
{
	if( rest < 0 )
		return 0;
	
	if( pos == n )
		return rest == 0 && mod == 0 ? 1 : 0;
	
	if( ~memo[ pos ][ mod ][ rest ] )
		return memo[ pos ][ mod ][ rest ];
	
	int ans = 0;
	ans += dp( pos+1, mod, rest );
	ans += dp( pos+1, (((mod + arr[ pos ]) % d ) + d ) % d, rest -1 );
	
	return memo[ pos ][ mod ][ rest ] = ans;
}

int main()
{
	int it = 0;
	while( 1 )
	{
		cin >> n >> q;
		if( !n && !q )
			break;

		for( int i = 0; i < n; ++i )
			cin >> arr[ i ];

		cout << "SET " << ++it << ":\n";
		for( int i = 1; i <= q; ++i )
		{
			memset( memo, -1, sizeof memo );
			cin >> d >> m;
			cout << "QUERY " << i << ": " << dp( 0, 0, m ) << '\n';
		}
	}
	return 0;
}
