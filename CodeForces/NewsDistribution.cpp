#include <bits/stdc++.h>
#define maxn 500005

using namespace std;

int tam[ maxn ];
int padre[ maxn ];

int padrote( int nodo )
{
	if( nodo == padre[ nodo ] )
		return nodo;

	return padre[ nodo ] = padrote( padre[ nodo ] );
}

bool union_find( int a, int b )
{
	int c = padrote( a );
	int d = padrote( b );

	if( d == c ) return false;

	if( rand()&1 )
	{
		padre[ c ] = d;
		tam[ d ] += tam[ c ];
	}
	else
	{
		padre[ d ] = c;
		tam[ c ] += tam[ d ];
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	
	int n, q, a, b, t;
	cin >> n >> q;
	
	for( int i = 0; i <= n; ++i )
	{
		padre[ i ] = i;
		tam[ i ] = 1;
	}

	while( q-- )
	{
		cin >> t;

		if( t>0 )
			cin >> a;

		for( int i = 1; i < t; ++i)
		{
			cin >> b;
			union_find( a, b );
		}
	}

	for( int i = 1; i <= n; ++i )
	{
		a = padrote( i );
		cout << tam[ a ];

		if( i < n )
			cout << ' ';
	}
	cout << '\n';

	return 0;
}
