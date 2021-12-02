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

ll lcm( ll a, ll b ) {
	return a * ( b / __gcd( a, b ) );
}

bool solve( ll l, ll r ) {
	ll lim = min( l+100, r );

	for (int i = l; i <= lim; ++i)
		for (int j = i+1; j <= lim; ++j)
			if( lcm( i, j ) <= r ) {
				cout <<  i << " " << j << endl;
				return true;
			}

	return false;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int t;
	ll l,
		r;

	cin >> t;

	while( t-- ) {
		cin >> l >> r;

		if( 2*l > r )
			cout << "-1 -1" << endl;
		else
			cout << l << " " << 2*l << endl;

	}

	return 0;
}