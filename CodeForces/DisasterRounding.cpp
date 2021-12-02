#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
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
 
ll fast_pow( ll n, ll exp ) {
	ll ans = 1;
	while( exp ) {
		if( exp&1 )
			ans = md( ans * n );

		n = md( n*n );
		exp >>= 1;
	}

	return ans;
}

int main()
{	
	ll n, raiz;
	const ll tres = fast_pow( 3, mod-2 );

	scanf("%lld", &n );
	
	raiz = llround( sqrtl( n ) );
	ll ans = md( md( md(raiz) * md(raiz+1) ) * md( 2*raiz + 1 ) ); 
	ans = md( ans * tres );

	ll middle_point = raiz*raiz + ((raiz+1)*(raiz+1) - raiz*raiz)/2;
	ans = md( ans - md(md(middle_point-n) * raiz) );
	cout << ans << endl;
 
	return 0;
}