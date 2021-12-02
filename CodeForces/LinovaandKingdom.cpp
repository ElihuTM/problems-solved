#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi lista;
vpii dist;
vi hijos;

void bfs( int root, int n )
{
	queue <int> q;
	dist = vpii( n+1 );

	for (int i = 0; i < n+1; ++i)
		dist[ i ] = pii( -1, i );
	
	dist[ root ].ff = 0;
	q.push( root );

	while( !q.empty() )
	{
		int u = q.front(); q.pop();
		for (int i = 0; i < lista[ u ].size(); ++i)
		{
			int v = lista[ u ][ i ];
			if ( dist[ v ].ff == -1)
			{
				dist[ v ].ff = dist[ u ].ff + 1;
				q.push( v );
			}
		}
	}
}

int dfs( int u, int f )
{
	for (int i = 0; i < lista[ u ].size(); ++i)
	{
		int v = lista[ u ][ i ];
		if ( v != f )
			hijos[ u ] += dfs( v, u );
	}
	
	return hijos[ u ] + 1;
}

bool f( pii a, pii b )
{
	if ( a.ff - hijos[ a.ss] > b.ff - hijos[ b.ss ])
		return true;

	if ( a.ff - hijos[ a.ss] == b.ff - hijos[ b.ss ] && hijos[a.ss] < hijos[ b.ss ] )

	return false;
}

int main()
{
	int n, k, a, b;
	cin >> n >> k;

	lista = vvi( n+1 );
	hijos = vi( n+1, 0 );

	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b;
		lista[ a ].push_back( b );
		lista[ b ].push_back( a );
	}

	bfs( 1, n );
	dfs( 1, -1 );

	sort( dist.begin(), dist.end(), f );

	long long ans = 0;
	int lvl = dist[ 0 ].ff; 

	for (int i = 0; i < k; ++i)
		ans += dist[ i ].ff - hijos[ dist[ i ].ss ];

	cout << ans << '\n';
	return 0;
}	
	