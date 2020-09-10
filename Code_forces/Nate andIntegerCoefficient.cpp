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

struct mat
{
	ll a, b, c, d;

	mat () { a = d = 1; b = d = 0; }
	mat ( ll x, ll y, ll z, ll w ){
		a = x; b = y;
		c = z; w = d;
	}

	mat operator * ( const mat &p ) const {
		mat ans;
		ans.a = md( md(a*p.a) + md(b*p.c) );
		ans.b = md( md(a*p.b) + md(b*p.d) );
		ans.c = md( md(c*p.a) + md(d*p.c) );
		ans.d = md( md(c*p.b) + md(d*p.d) );
		return ans;
	}
};

mat fast_pow( mat x, ll exp ) {
	mat ans;

	while( exp ) {
		if( exp&1 )
			ans = ans * x;

		x = x * x;
		exp >>= 1;
	}

	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int t;
	ll a, n;
	cin >> t;

	while( t-- ) {
		cin >> a >> n;
		n = ( n < 0 ? -n : n );

		if( n == 0 ) {
			cout << 2 << endl;
			continue;
		}

		ll a1 = md( a );
		ll a2 = md( a1*a1 - 2 );

		mat ans = fast_pow( mat( a, -1, 1, 0 ), n-2 );
		cout << md( md( ans.a*a2 ) + md( ans.b*a1 ) ) << endl;
	}

	return 0;
}