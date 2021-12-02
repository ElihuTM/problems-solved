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

bitset <maxn> visited;
vi treasure;
vvi lista;
vi path;

bool dfs( int u , int b ) {

	visited[ u ] = true;
	if( u == b )
		return true;

	for (int i = 0; i < lista[ u ].size(); ++i) {
		int v = lista[ u ][ i ];

		if( !visited[ v ] ) {
			if ( dfs( v, b ) ){
				path.push_back( v );
				return true;
			}
		} 
	}

	return false;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n, q, a, b, op;

	cin >> n;
	lista.resize( n+1 );
	treasure.resize( n+1 );

	for (int i = 1; i <= n; ++i)
		cin >> treasure[ i ];

	for (int i = 0; i < n-1; ++i) {
		cin >> a >> b;
		lista[ a ].push_back( b );
		lista[ b ].push_back( a );
	}
	
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> op >> a >> b;
		if( op == 2 )
			treasure[ a ] = b;
		else {
			visited.reset();
			path.clear();
			dfs( a, b );

			map < int, int > best;
			path.push_back( a );

			pii ans( 0, 0);
			for (int i = 0; i < path.size(); ++i)
				best[ treasure[ path[ i ] ] ]++;

			for ( auto c: best )
				if( c.ss > ans.ss )
					ans = c;
			/*
			cout << "una query" << endl;
			for (int i = 0; i < path.size(); ++i)
				cout << path[ i ] << " " << treasure[ path[ i ] ] << endl;
			cout << ans.ff << " " << ans.ss << endl;
			*/
			if( ans.ss > path.size() / 2 )
				cout << ans.ff << endl;
			else
				cout << -1 << endl;	
		}

	}
	return 0;
}