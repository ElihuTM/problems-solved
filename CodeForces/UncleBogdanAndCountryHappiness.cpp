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

vvi lista;
vi lives;
vi happiness;
vi cont;
vpii people;
int n, m;

void build( int u, int father = -1 ) {

	int ans = 1;
	for (int i = 0; i < lista[ u ].size(); ++i) {
		int v = lista[ u ][ i ];
		if ( v != father )
			ans += build( v, u );
	}

	return cont[ i ] = ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int t, a, b;

	cin >> t;
	while( t-- ) {
		cin >> n >> m;
		
		lista.resize( n );
		lives.resize( n );
		happiness.resize( n );
		cont.resize( n );
		people.resize( n );
		
		for (int i = 0; i < n; ++i) {
			cin >> lives[ i ];
		}

		for (int i = 0; i < n; ++i) {
			cin >> happiness[ i ];
		}

		for (int i = 0; i < n-1; ++i) {
			cin >> a >> b; --a; --b;
			lista[ a ].push_back( b );
			lista[ b ].push_back( a );
		}

		build( 0 );
		if ( dfs( 0 ) )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}