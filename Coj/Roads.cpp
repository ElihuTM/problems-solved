#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#define maxn 10007

using namespace std;
typedef pair<int,int> pii;

vector<int> entrada[ maxn ];
vector<int> salida[ maxn ];
vector<int> Lista[ maxn ];
int contador, componentes;
bool visited[ maxn ];
map<int, int> SCC;
vector<int> Stack;
int padre[ maxn ];
int low[ maxn ];
int num[ maxn ];

void tarjan( int nodo )
{
	visited[ nodo ] = true;
	low[ nodo ] = num[ nodo ] = contador++;
	Stack.push_back( nodo );

	for ( auto v: Lista[ nodo ] )
	{
		if ( num[ v ] == -1)
			tarjan( v );
		if ( visited[ v ] )
			low[ nodo ] = min(low[ nodo ], low[ v ]);
	}

	if ( low[ nodo ] == num[ nodo ] )
	{
		while( 1 )
		{
			int ult = Stack.back();
			padre[ ult ] = nodo;
			visited[ ult ] = 0;
			Stack.pop_back();

			if ( nodo == ult )
				break;
		}
		SCC[ nodo ] = componentes++;
	}
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int nodos, aristas, a, b;
	cin >> nodos >> aristas;

	componentes = contador = 0;
	memset( visited, 0 , sizeof visited);
	memset( padre, -1, sizeof padre );
	memset( num, -1, sizeof num );
	memset( low, 0 , sizeof low );

	for (int i = 0; i < aristas; ++i)
	{
		cin >> a >> b;
		Lista[ a-1 ].push_back( b-1 );
	}

	for (int i = 0; i < nodos; ++i)
		if ( num[ i ] == -1 )
			tarjan( i );

	set< pii > aris;
	for ( int i = 0; i < nodos; i++)
		for ( auto c: Lista[ i ])
			if ( padre[ i ] != padre[ c ] )
				aris.insert( make_pair(SCC[ padre[ i ] ], SCC[ padre[ c ] ] ) );

	for (auto c: aris)
	{	
		salida[ c.first ].push_back( c.second );
		entrada[ c.second ].push_back( c.first );
	}

	int roots = 0, hojas = 0;
	for (int i = 0; i < componentes; ++i)
	{
		if ( salida[ i ].empty() )
			hojas++;
		if ( entrada[ i ].empty() )
			roots++;
	}

	if ( componentes == 1 )
		cout << 0 << endl;
	else
		cout<< max( roots, hojas ) << endl;
	return 0;
}