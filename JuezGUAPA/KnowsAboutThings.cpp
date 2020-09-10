#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 986424689
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	int t;
	ll a, n;

	cin >> t;
	while( t-- )
	{
		cin >> a >> n;
		vi exp( n+1 );

		exp[ 0 ] = 1;
		for (int i = 1; i <= n; ++i)
			exp[ i ] = md( a*exp[ i-1 ] );

		ll ans = 0;
		for (int i = 0; i <= n; ++i)
			ans = md( ans + md(i*exp[ i ] ) );

		cout << ans << endl;
	}
	return 0;
}
