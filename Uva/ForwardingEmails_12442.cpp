#include <bits/stdc++.h>
#define maxn 50005

using namespace std;
typedef vector <int> vi;

bitset <maxn> visit;
int low[ maxn ];
int num[ maxn ];
int pre[ maxn ];
int peso[ maxn ];
vi dag[ maxn ];
vi lista [ maxn ];
vi s;
int cont, SCC;
int memo[ maxn ];

void limpia( int n )
{
	for( int i = 0; i < maxn; ++i )
	{
		dag[ i ].clear();
		lista[ i ].clear();
	}

	visit.reset();
	memset( num, -1, sizeof num );
	memset( peso, 0, sizeof peso );
	memset( memo, -1, sizeof memo );
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

void create_DAG( int n )
{
	cont = SCC = 0;
	for( int i = 0; i < n; ++i )
		if( num[ i ] == -1 )
			tarjan( i );

	vector < set <int > > precalc( n );
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < lista[ i ].size(); ++j )
		{
			int u = pre[ i ], v = pre[ lista[ i ][ j ] ];
			if( u != v )
				precalc[ u ].insert( v );
		}
	
	for( int i = 0; i < SCC; ++i )
		for( auto c: precalc[ i ] )
			dag[ i ].push_back( c );
}

int dp( int u )
{
	if( ~memo[ u ] )
		return memo[ u ];
	
	int ans = peso[ u ];
	for( int i = 0; i < dag[ u ].size(); ++i )
	{
		int v = dag[ u ][ i ];
		ans += dp( v );
	}

	return memo[ u ] = ans;
}

int main()
{
	int casos, n, a, b, aux, ans, con;
	cin >> casos;

	for( int qw = 1; qw <= casos; ++qw )
	{
		cin >> n;

		limpia( n );
		for( int i = 0; i < n; ++i )
		{
			cin >> a >> b;
			lista[ a-1 ].push_back( b-1 );
		}

		create_DAG( n );
		
		/*
		cout << "---------------------------------\n";
		for( int i = 0; i < SCC; ++i )
		{
			cout << "apunta a " << dag[ i ].size() << " y contiene: " << peso[ i ];
			for( auto c: dag[ i ] )
				cout << " " << c;
			cout << endl;
		}*/

		con = 0;
		for( int i = 0; i < SCC; ++i )
		{
			//cout << i << " : " << dp( i ) << endl;
			if( dp( i ) > con )
			{
				con = dp( i );
				aux = i;
			}
		}

		for( int i = 0; i < n; ++i )
		{
			if( pre[ i ] == aux )
			{
				ans = i;
				break;
			}
		}
		//cout << i << " : " << pre[ i ] << '\n';

		cout << "Case " << qw << ": " << ans+1 << '\n';
	}
	return 0;
}
