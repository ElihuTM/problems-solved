#include <bits/stdc++.h>
#define l(p) p<<1
#define r(p) ((p<<1)+1)
#define mid(i,j) ((i+j)>>1)

using namespace std;
typedef vector <int> vi;

vi arr;
vi arbol;
vi cambios;

void propagar( int p, int i, int j )
{
	if( cambios[ p ] != -1)
	{
		if( cambios[ p ] > arbol[ p ] )
			arbol[ p ] = cambios[ p ];

		if( i != j )
		{
			if( cambios[ l(p) ] == -1 || cambios[ p ] > cambios[ l(p)] )
				cambios[ l(p) ] = cambios[ p ];

			if( cambios[ r(p) ] == -1 || cambios[ p ] > cambios[ r(p)] )
				cambios[ r(p) ] = cambios[ p ];
		}
	}

	cambios[ p ] = -1;
}

void build( int p, int i, int j )
{
	if( i == j )
	{
		arbol[ p ] = arr[ i ];
		return ;
	}

	build( l(p), i, mid(i,j) );
	build( r(p), mid(i,j)+1, j);

	arbol[ p ] = min( arbol[ l(p) ], arbol[ r(p) ] );
}

void up1( int p, int i, int j, int a, int value )
{
	propagar( p, i, j );

	if( i > a || j < a )
		return;
	
	if( i == a && j == a )
	{
		arbol[ p ] = value;
		return;
	}
	up1( l(p), i, mid(i,j), a, value );
	up1( r(p), mid(i,j)+1, j, a, value );

	arbol[ p ] = min( arbol[ l(p) ], arbol[ r(p) ] );
}

void prin( int p, int i, int j, int ul )
{
	propagar( p, i, j );

	if( i == j )
	{
		cout << arbol[ p ];
		if( i != ul )
			cout << " ";
		return;
	}

	prin( l(p), i, mid(i,j), ul );
	prin( r(p), mid(i,j)+1, j, ul);
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, q, op, p,x;
	cin >> n;
	
	arr = vi( n );
	arbol = vi( 6*n );
	cambios = vi( 6*n, -1 );

	for( int i = 0; i < n; ++i )
		cin >> arr[ i ];

	build( 1, 0, n-1 );

	cin >> q;
	while( q-- )
	{
		cin >> op;
		if( op == 1)
		{
			cin >> p >> x;
			up1( 1, 0, n-1, p-1, x);
		}
		else
		{
			cin >> x;
			if( x > arbol[ 1 ] )
			{
				arbol[ 1 ] = x;
				cambios[ 1 ] = x;
			}
		}
	}

	prin( 1, 0, n-1, n-1 );
	return 0;
}
