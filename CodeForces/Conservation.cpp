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
bitset <maxn> room;
queue <int> front[ 2 ];

int topological_sort( bool current, vi padres )
{
	while( !front[ 0 ].empty() )	front[ 0 ].pop();
	while( !front[ 1 ].empty() )	front[ 1 ].pop();
	int n = padres.size();

	for (int i = 0; i < n; ++i)
		if( padres[ i ] == 0 )
			front[ room[ i ] ].push( i );

	ll ans = 0;
	while( !front[ 1 ].empty() or !front[ 0 ].empty() )
	{
		while( !front[ current ].empty() )
		{
			int u = front[ current ].front(); front[ current ].pop();
			for (int i = 0; i < lista[ u ].size(); ++i)
			{
				int v = lista[ u ][ i ];
				--padres[ v ];

				if( padres[ v ] == 0 )
					front[ room[ v ] ].push( v );
			}
		}

		++ans;
		current = 1 - current;
	}

	return ans-1;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int t, input;
	int n, m, a, b;
	cin >> t;

	while( t-- )
	{
		cin >> n >> m;
		
		lista = vvi( n );
		vi padres( n, 0 );

		for (int i = 0; i < n; ++i)
		{
			cin >> input;
			room[ i ] = (input == 1);
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			lista[ a-1 ].push_back( b-1 );
			padres[ b-1 ]++;
		}

		int ans1 = topological_sort( 1, padres );
		int ans2 = topological_sort( 0, padres );
	
		cout << min( ans1, ans2 ) << endl;
	}

	return 0;
}