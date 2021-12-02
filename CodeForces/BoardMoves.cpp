#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 500005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define sz(a) s.size()
#define endl '\n'
#define forn(i,n)  for ( int i = 0; i < n; ++i )

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	vi ans( maxn );
	ans[ 1 ] = 0;
	for ( ll i = 3; i < maxn; i+=2 )
	{
		ll lvl =  i/2;
		ans[ i ] = ((i*i) - ((i-2)*(i-2))) * lvl;
		ans[ i ] += ans[ i-2 ];
	}

	ll t, n;
	cin >> t;
	while( t-- )
	{
		cin >> n;
		cout << ans[ n ] << endl;
	}

	return 0;
}
