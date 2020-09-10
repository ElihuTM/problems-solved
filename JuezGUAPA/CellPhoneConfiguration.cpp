#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 999999929
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
			ans = (ans * x ) % mod;

		x = ( x * x ) % mod;
		exp >>= 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	ll t, k;

	cin >> t;
	while( t-- )
	{
		cin >> k;
		ll ans = 90;

		if( k == 1 )
			cout << 10 << endl;
		else if( k == 2 )
			cout << 90 << endl;
		else
			cout << ( ans * fast_pow( 8, k-2 ) ) % mod << endl;
	}
	return 0;
}
