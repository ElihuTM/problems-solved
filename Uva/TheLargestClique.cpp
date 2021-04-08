#include <bits/stdc++.h>
#define maxn 1003

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool visit[ maxn ];
int low[ maxn ];
int num[ maxn ];
int pre[ maxn ];
int peso[ maxn ];
int memo[ maxn ];
vi dag[ maxn ];
vi lista[ maxn ];
vi s;
int cont, SCC, n, m;

void limpia()
{
	memset( num, -1, sizeof num );
	memset( visit, 0, sizeof visit );
	memset( peso, 0, sizeof peso );
	memset( memo, -1, sizeof memo );

	for( int i = 0; i < n; ++i )
	{
		dag[ i ].clear();
		lista[ i ].clear();
	}
}

void tarjan( int u )
{
	num[ u ] = low[ u ] = cont++;
	s.push_back( u );
	visit[ u ] = true;
	
	int v, len = lista[ u ].size();
	for( int i = 0; i < len; ++i )
	{
		v = lista[ u ][ i ];
		if( num[ v ] == -1 )
			tarjan( v );

		if( visit[ v ] )
			low[ u ] = min( low[ u ], low[ v ] );
	}

	if( low[ u ] == num[ u ] )
	{
		while( 1 )
		{
			v = s.back(); s.pop_back(); visit[ v ] = false;
			pre[ v ] = SCC;
			++peso[ SCC ];

			if( u == v )
				break;
		}
		++SCC;
	}
}

void crea_DAG()
{
	cont = SCC = 0;
	for( int i = 0; i < n; ++i )
		if( num[ i ] == -1 )
			tarjan( i );
		
	vector< set< int > > precalc( n );
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < lista[ i ].size(); ++j )
		{
			int u = pre[ i ], v = pre[ lista[ i ][ j ] ]; 
			if( u != v )
				precalc[ u ].insert( v );
		}
	}
		
	for( int i = 0; i < SCC; ++i )
		for( auto c: precalc[ i ] )
			dag[ i ].push_back( c );
}

int dp( int u )
{
	if( ~memo[ u ] )
		return memo[ u ];

	int ans = 0;
	for( int i = 0; i < dag[ u ].size(); ++i )
	{
		int v = dag[ u ][ i ];
		ans = max( ans, dp( v ) );
	}

	return memo[ u ] = peso[ u ] + ans;
}

int main()
{
	int cases, a, b;

	cin >> cases;
	while( cases-- )
	{
		limpia();
		cin >> n >> m;
	
		for( int i = 0; i < m; ++i )
		{
			cin >> a >> b;
			lista[ a-1 ].push_back( b-1 );
		}
		
		crea_DAG();
		
		int ans = 0;
		for( int i = 0; i < SCC; ++i )
			ans = max( ans, dp( i ) );

		cout << ans << '\n';
	}

	return 0;
}
