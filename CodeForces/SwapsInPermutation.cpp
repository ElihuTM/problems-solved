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

bitset <maxn> visited;
vi positions;
vvi lista;
vi nums;
vi arr;
vi ans;

void bfs( int root )
{
	nums.clear();
	positions.clear();
	queue <int> q;

	q.push( root );
	nums.push_back( arr[ root ] );
	positions.push_back( root );
	visited[ root ] = true;

	while( !q.empty() )
	{
		root = q.front(); q.pop();

		for (int i = 0; i < lista[ root ].size(); ++i)
		{
			int v = lista[ root ][ i ];
			if( !visited[ v ] )
			{
				visited[ v ] = true;
				positions.push_back( v );
				nums.push_back( arr[ v ] );
				q.push( v );
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n, m, a, b;

	cin >> n >> m;
	lista.resize( n );
	arr.resize( n );
	ans.resize( n );
	visited.reset();

	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b; --a; --b;
		lista[ a ].push_back( b );
		lista[ b ].push_back( a );
	}

	for (int i = 0; i < n; ++i)
	{
		if( !visited[ i ] )
		{
			bfs( i );
			sort( nums.rbegin(), nums.rend() );
			sort( all(positions) );

			for (int i = 0; i < nums.size(); ++i)
			{
				int position = positions[ i ];
				int num = nums[ i ];

				ans[ position ] = num;
			}
		}
	}

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[ i ] << " ";
	cout << endl;
	return 0;
}