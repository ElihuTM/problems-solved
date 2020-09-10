#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 2004
#define md(x) (((x%mod) + mod) % mod)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

int n, k;
ll memo[ maxn ][ maxn ];

ll dp( int num, int pos )
{
	if( ~memo[ num ][ pos ] )
		return memo[ num ][ pos ];
	
	if( pos == 1 )
		return 1;

	int lim = sqrt( num );
	ll ans = 0;
	for (int i = 1; i <= lim ; ++i)
		if( num % i == 0 )
		{
			ans = md( ans + dp( i, pos-1 ) );
			ans = md( ans + dp( num/i, pos-1 ) );
		}

	if( lim*lim == num )
		ans = md( ans - dp( lim, pos-1 ));

	return memo[ num ][ pos ] = ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	memset( memo, -1, sizeof(memo));
	cin >> n >> k;

	ll ans = 0;
	for( int i = 1; i <= n; ++i )
	{
		//cout << dp( i, k ) << endl;
		ans = md( ans + dp( i, k ) );
	}

	cout << ans << endl;

	return 0;
}