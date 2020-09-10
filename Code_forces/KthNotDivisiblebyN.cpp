#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 10000000007
#define mod(x) (((x%md) + md) % md)
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

ll _lower_bound( ll i, ll j, ll n, ll value )
{
	ll m;
	while ( j-i > 1 )
	{
		m = i + (j-i)/2;

		if(  m - m / n == value )
			return (m % n == 0 ? m - 1: m );

		if ( m - m / n > value)
			j = m;
		else
			i = m;
	}
	return i;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t, n, k;
	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		ll ans = _lower_bound( 0, maxn, n, k );

		cout << ans << endl;
	}

	return 0;
}
