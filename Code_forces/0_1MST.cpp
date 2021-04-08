#include <bits/stdc++.h>
#define maxn 100005

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;

set <int> padres;
vvi lista;
vi padre;

int padrote( int u )
{
	return padre[ u ] == u ? u : padre[ u ] = padrote( padre[ u ] );
}

bool union_find( int a, int b )
{
	a = padrote( a );
	b = padrote( b );
	
	if( a == b ) return false;

	padre[ b ] = a;
	return true;
}

int main()
{
	int n, m, a, b;

	cin >> n >> m;

	lista = vvi( n );
	padre = vi( n );
	for( int i = 0; i < n; ++i )
	{
		padre[ i ] = i;
		padres.insert( i );
	}

	for(int i = 0; i < m; ++i)
	{
		cin >> a >> b; --a; --b;
		if( b < a ) swap( a, b );

		lista[ a ].push_back( b );
	}
	
	set<int>::iterator it = padres.begin(); ++it;
	set<int>::iterator aux, next;

	for( int i = 0; i < n; ++i )
	{
		sort( lista[ i ].begin(), lista[ i ].end() );
		
		int pos = 0;
		next = it; ++next;
		while( next != padres.end() && pos < lista[ i ].size() )
		{
			if( lista[ i ] != *next )
			{	
				aux = next; ++next;
				padres.erase( aux );
			}
		}
	}

	return 0;
}
