#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 999999937
#define maxn 100005
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


ll fast_pow ( ll x, ll exp )
{
	ll ans = 1;
	while( exp )
	{
		if( exp & 1 )
			ans = ( ans * x ) % mod;

		x = ( x * x ) % mod;
		exp >>= 1;
	}
	return ans;
}


vi build_num( int a, int b, int &ap )
{
	map <int, int> cycle;
	map <int, int> aparicion;
	vi ans;

	int res = a, pos = 0;
	while( cycle.find( res ) == cycle.end() )
	{
		if( res*10 / b == 0 )
			ans.p_b( 7 );
		else
			ans.p_b( res*10 / b );

		aparicion[ res ] = pos++;
		cycle[ res ] = (res*10) % b;
		res = ( res * 10 ) % b;
	}

	ap = aparicion[ res ];
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	int t, a, b, ap;
	ll n;

	cin >> t;
	while( t-- )
	{
		cin >> a >> b >> n;
		a %= b;

		vi num = build_num( a, b, ap );
		ll ans = 1;

		if( n <= num.size() )
		{
			for (int i = 0; i < n; ++i)
				ans = md( ans * num[ i ] );
		}
		else
		{
			for( int i = 0; i < ap; ++i )
			{
				ans = md( ans * num[ i ] );
				--n;
			}
			
			ll len_cycle = num.size() - ap;
			ll val_cycle = 1;

			for (int i = ap; i < num.size(); ++i)
				val_cycle = md( val_cycle * num[ i ] );

			ans = md( ans * fast_pow( val_cycle, n / len_cycle ) );
			n %= len_cycle;

			for (int i = 0; i < n; ++i)
				ans = md( ans * num[ ap + i ] );
		}

		cout << ans << endl;
	}
	return 0;
}
