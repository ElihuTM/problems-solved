#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 998244353
#define maxn 100005
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

ll fast_pow( ll n, ll exp )
{	
	ll ans = 1;
	while( exp )
	{
		if( exp&1 )
			ans = mod( ans * n );

		exp >>= 1;
		n = mod( n*n );
	}
	
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	

	ll n, k;

	cin >> n >> k;

	ll ans = 0;
	for (int i = 1; i < n; ++i)
		ans = mod( ans + fast_pow( k, (i+1)/2 ));

	ans = mod( ans + mod(n*fast_pow( k, (n+1)/2)) );
	cout << ans << endl;
	return 0;
}
