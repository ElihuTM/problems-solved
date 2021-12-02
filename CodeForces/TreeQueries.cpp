#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;

set <int> nodes;
vvi lista;
vi padre;
vi dist;
int n;

void bfs( int root )
{
	int u, v;
	queue<int> q;
	dist = vi( n+1 );
	
	dist[ root ] = 0;
	q.push( root );

	while( !q.empty() )
	{
		u = q.front(); q.pop();
		for ( int i = 0; i < lista[ u ].size(); ++i)
		{
			v = lista[ u ][ i ];
			dist[ v ] = 1 + dist[ u ];			
			q.push( v );
		}
	}
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t, a, b, leaf, k;
	cin >> n >> t;

	lista = vvi( n+1 );
	padre = vi( n+1 );
	padre[ 1 ] = padre[ 0 ] = -1;

	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b;
		lista[ a ].push_back( b );
		padre[ b ] = a;
	}

	bfs( 1 );

	while( t-- )
	{
		nodes.clear();
		cin >> k;
		
		cin >> leaf;
		nodes.insert( leaf );
		for (int i = 1; i < k; ++i)
		{
			cin >> a;
			if ( dist[ a ] > dist[ leaf ] )
				leaf = a;
			nodes.insert( a );
		}

		while( u != -1 )
		{
			for ( int i = 0; i < lista[ u ].size(); ++i)
				nodes.erase( lista[ u ][ i ] );
			u = padre[ u ];
		}
		nodes.erase( 1 );

		if ( is_pos( leaf ) )
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
	return 0;
}