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

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int t, n;
	ll min_a, min_b;
	vi a, b;
	
	cin >> t;
	while( t-- ) {
		cin >> n;
		ll cont = 0;
		min_a = min_b = mod;

		a.resize( n );
		b.resize( n );
		
		for (int i = 0; i < n; ++i) {
			cin >> a[ i ];
			min_a = min( min_a, a[ i ] );
		}

		for (int i = 0; i < n; ++i) {
			cin >> b[ i ];
			min_b = min( min_b, b[ i ] );
		}

		for (int i = 0; i < n; ++i)
		{
			int min_dif = min( b[ i ] - min_b, a[ i ] - min_a );
			b[ i ] -= min_dif;
			a[ i ] -= min_dif;
			cont += min_dif;

			if ( a[ i ] > min_a ) {
				cont += a[ i ] - min_a;
			}

			if( b[ i ] > min_b )
				cont += b[ i ] - min_b;
		}

		cout << cont << endl;
	}

	return 0;
}