#include <bits/stdc++.h>
#define right(p) (p<<1)+1 
#define left(p) (p<<1)
#define endl '\n'

using namespace std;
typedef vector<int> vii;

vector< vii > Lista;
vii first_visit;
vii toposort;
vii depth;
vii arbol;
vii padre;
vii dist;
int n;

void _dfs( int nodo, int prof )
{
	if( first_visit[ nodo ] == -1)
		first_visit[ nodo ] = toposort.size();

	toposort.push_back( nodo );
	depth.push_back( prof );

	int len = Lista[ nodo ].size();
	for (int i = 0; i < len; ++i)
	{
		int v = Lista[ nodo ][ i ];

		if ( dist[ v ] == -1 )
		{
			dist[ v ] = dist[ nodo ]+1;
			padre[ v ] = nodo;
			_dfs( v, prof+1 );

			toposort.push_back( nodo );
			depth.push_back( prof );
		}
	}
}

void build_segment( int p, int i, int j )
{
	if ( i == j )
	{
		arbol[ p ] = toposort[ i ];
		return;
	}

	int middle = (i+j)>>1;
	build_segment( left( p ) , i, middle);
	build_segment( right( p ) , middle+1, j);

	if ( dist[ arbol[ left( p ) ] ] < dist[ arbol[ right( p ) ] ] )
		arbol[ p ] = arbol[ left( p ) ];
	else
		arbol[ p ] = arbol[ right( p ) ];
}

void build_LCA()
{
	first_visit = vii( n, -1 );
	padre = vii( n, -1 );
	dist = vii( n, -1 );
	toposort.clear();
	depth.clear();

	dist[ 0 ] = 0;
	_dfs( 0, 0 );

	arbol = vii( 4*toposort.size() );
	build_segment( 1, 0, toposort.size()-1 );
}

int query( int p, int i, int j, int a, int b )
{
	if ( i > b || j < a )
		return -1;

	if ( i >= a && j <= b )
		return arbol[ p ];

	int middle = (i+j)>>1;
	int l = query( left( p ), i, middle, a, b );
	int r = query( right( p ), middle+1, j, a, b );

	if ( l == -1 )
		return r;

	if ( r == -1 )
		return l;

	if ( dist[ l ] < dist[ r ] )
		return l;
	return r;
}

int LCA( int a, int b )
{
	int l = min( first_visit[ a ], first_visit[ b ] );
	int r = max( first_visit[ a ], first_visit[ b ] );

	return query( 1, 0, toposort.size()-1, l, r );
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int a, b, querys, lca, d1, d2, ans, root, it ;
	cin >> n;
	while( n )
	{
		Lista = vector< vii >( n );

		for (int i = 0; i < n-1; ++i)
		{
			cin >> a >> b; --a; --b;
			Lista[ a ].push_back( b );
			Lista[ b ].push_back( a );
		}

		build_LCA();

		cin >> querys;
		while( querys-- )
		{
			cin >> a >> b; --a; --b;
			lca = LCA( a, b ); 

			d1 = dist[ b ] - dist[ lca ];
			d2 = dist[ a ] - dist[ lca ];
			it = (d1+d2)/2;

			if ( (d1+d2)&1 )
			{
				if ( d1 > d2 )
					root = b;
				else
					root = a;

				while( it-- )
					root = padre[ root ];


				cout << "The fleas jump forever between " << min(root,padre[ root ])+1 << " and " << max(root,padre[ root ])+1 << ".\n";

			}
			else
			{
				if ( d1 > d2 )
					root = b;
				else
					root = a;

				while( it-- )
					root = padre[ root ];

				cout << "The fleas meet at " << root+1 << ".\n";

			}

			//cout << LCA( a, b ) << endl;
		}

		cin >> n;
	}
	return 0;
}