#include <bits/stdc++.h>
#define maxn 100003
#define endl '\n'

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;

vector<pii> lista[ maxn ];
vector< int > height;
vector< int > topo;

int arbol[ 8*maxn ];
bool visit[ maxn ];
int prim[ maxn ];
ll dist[ maxn ];
int n;

void _dfs( int nodo, int profundidad )
{
	visit[ nodo ] = true;

	if ( prim[ nodo ] == -1 )
		prim[ nodo ] = topo.size();

	topo.push_back( nodo );
	height.push_back( profundidad );

	int len = lista[ nodo ].size();
	pii v;
	for ( int i = 0; i < len ; ++i )
	{
		v = lista[ nodo ][ i ];
		if ( !visit[ v.first ] )
		{
			dist[ v.first ] = dist[ nodo ] + v.second;
			_dfs( v.first, profundidad+1 );
			topo.push_back( nodo );
			height.push_back( profundidad );
		}
	}
}

void _construir(int p, int i, int j )
{
	if ( i == j )
	{
		arbol[ p ] = topo[ i ];
		return;
	}

	_construir(p<<1, i, (i+j)>>1 );
	_construir((p<<1)+1,((i+j)>>1)+1, j );

	int a = prim[ arbol[ p<<1 ] ];
	int b = prim[ arbol[ (p<<1)+1 ] ];

	if ( height[ a ] < height[ b ] )
		arbol[ p ] = arbol[ p<<1 ];
	else
		arbol[ p ] = arbol[ (p<<1)+1 ];
	
	//cout << "intervalo " << i << " , " << j << " = " << arbol[ p ] << endl;
}

void construir()
{
	dist[ 0 ] = 0;
	_dfs( 0, 0 );
	_construir(1, 0, topo.size()-1 );
}

int query( int p, int i, int j, int a, int b )
{
	if ( i > b || j < a )
		return -1;

	if ( i >= a && j <= b )
		return arbol[ p ];

	int left = query( p<<1, i , (i+j)>>1, a, b );
	int right = query( (p<<1)+1, ((i+j)>>1)+1, j, a, b);

	if ( left == -1)
		return right;

	if ( right == -1)
		return left;

	if ( height[ prim[ left ] ] < height[ prim[ right ] ] )
		return left;
	return right;
}

ll LCA( int a, int b )
{
	int c = min( prim[ a ], prim[ b ] );
	int d = max( prim[ a ], prim[ b ] );

	int lca = query( 1, 0, topo.size()-1, c, d );
	//cout << "{ " << a << " , " << b <<"} : "<< lca << endl;
	return dist[ a ] - dist[ lca ] + dist[ b ] - dist[ lca ];
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int a, b, querys;

	cin >> n;
	while( n )
	{
		memset( visit, false, sizeof visit );
		memset( prim, -1, sizeof prim );
		memset(dist, 0, sizeof dist);
		height.clear();
		topo.clear();
		for (int i = 0; i <= n; ++i)
			lista[ i ]. clear();
		
		for (int i = 1; i < n; ++i)
		{
			cin >> a >> b;
			lista[ i ].emplace_back( a, b );
			lista[ a ].emplace_back( i, b );
		}

		construir();

		/*
		cout << "topo\n";
		for ( auto v: topo )
			cout << v << " ";
		cout << endl;

		cout << "height\n";
		for ( auto v: height)
			cout << v << " ";
		cout << endl;

		cout << "prim\n";
		for (int i = 0; i < n; ++i)
			cout << prim[ i ] << " ";
		
		cout << endl << endl;
		*/


		cin >> querys;

		while( querys-- )
		{
			cin >> a >> b;
			cout << LCA( a, b);
			if ( querys )
				cout << " ";
		}
		cout << endl;

		cin >> n;
	}
	return 0;
}