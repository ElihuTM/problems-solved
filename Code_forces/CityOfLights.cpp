#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 1000005
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

bitset <maxn> lights;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	lights.set();
	int n,
		k,
		controlling,
		ans = 0;
	
	cin >> n >> k;
	while( k-- ) {

		cin >> controlling;
		for (int i = controlling; i <= n; i+= controlling) {
			lights[ i ] = 1 - lights[ i ];
		}

		ans = max( ans, (int)(maxn-lights.count()) );
	}

	cout << ans << endl;

	return 0;
}