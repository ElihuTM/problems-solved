#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> capacity;
vector <int> tam;
vector <int> padre;

void init()
{
	capacity.resize( n+1 );
	tam.resize( n );
	padre.resize( n+10 );

	for( int i=0; i<n; ++i )
	{
		padre[ i ] = i+1;
		tam[ i ] = 0;
	}
}

int padrote( int u )
{
	if( padre[ u ] == n )
		return n;

	if( capacity[ padre[ u ] ] == tam[ padre[ u ] ] )
		return padre[ u ] = padrote( padre[ u ] );
	return padre[ u ];
}

void give( int p, int x )
{
	if( p == n )
		return;

	if( tam[ p ] + x <= capacity[ p ] )
		tam[ p ] += x;
	else
	{
		int dif = capacity[ p ] - tam[ p ];
		tam[ p ] = capacity[ p ];
		
		give( padrote( p ), x-dif );
	}
}

int main()
{
	int op, x, y;
	cin >> n;
	init( );

	for( int i=0; i<n; ++i )
		cin >> capacity[ i ];

	cin >> m;
	while( m-- )
	{
		cin >> op;
		if( op == 1 )
		{
			cin >> x >> y;
			give( x-1, y );
		}
		else
		{ 
			cin >> x;
			cout << tam[ x-1 ] << '\n';
		}
	}

	return 0;
}
