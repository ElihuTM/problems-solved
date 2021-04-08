#include <bits/stdc++.h>
#define maxm 40005
#define maxn 105
#define inf -99999999
#define forn(i,n) for(int i=0;i<n;++i)
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

int memo[ maxm ][ maxn ][ 2 ];
pii arr[ maxn ];
int n, m;

int dp( int mon, int pos, int take )
{
	if( mon > m + 200 ) return inf;
	
	if( pos == n )
		return mon > m ? inf : 0;
	
	if( ~memo[ mon ][ pos ][ take ] )
		return memo[ mon ][ pos ][ take ];
	
	int ans2, ans = dp( mon, pos+1, take );
	
	if( take == 0 && mon <= 2000 && mon + arr[ pos ].ff > 2000 )
		ans2 = dp( mon + arr[ pos ].ff - 200, pos + 1, 1 ) + arr[ pos ].ss;
	else	
		ans2 = dp( mon + arr[ pos ].ff, pos + 1, take ) + arr[ pos ].ss;
	
	return memo[ mon ][ pos ][ take ] = max( ans, ans2 );
}

int main()
{
	while( cin >> m >> n )
	{
		memset( memo, -1, sizeof memo );
		forn(i,n)
			cin >> arr[ i ].ff >> arr[ i ].ss;

		cout << dp( 0, 0, 0 ) << '\n';
	}
	return 0;
}
