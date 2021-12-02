#include <bits/stdc++.h>
#define mid(i,j) ((i+j)>>1)
#define r(p) ((p<<1)+1)
#define l(p) (p<<1)

using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

struct segment
{
	vi arbol;
	vi cambios;
	int len;

	segment( int n )
	{
		arbol = vi( 6*n, 0 );
		cambios = vi( 6*n, 0 );
		len = n-1;
	}

	void propagar( int p, int i, int j )
	{
		if ( i != j )
		{
			cambios[ l(p) ] += cambios[ p ];
			cambios[ r(p) ] += cambios[ p ];
		}

		arbol[ p ] += cambios[ p ];
		cambios[ p ] = 0;
	}

	void update( int p, int i, int j, int a, int b, int value )
	{
		propagar( p, i, j );

		if( i > b || j < a )
			return;

		if( i >= a && j <= b )
		{
			cambios[ p ] += value;
			propagar( p, i, j );
			return;
		}

		update( l(p), i, mid(i,j), a, b, value );
		update( r(p), mid(i,j) + 1, j, a, b, value );

		arbol[ p ] = min( arbol[ l(p) ], arbol[ r(p) ] );
	}

	void update( int a, int b, int value ) {
		update( 1, 0, len, a, b, value );
	}

	bool decrease( int k )
	{
		update( 0, k, -1 );

		if ( arbol[ 1 ] < 0 )
		{
			update( 0, k, 1);
			return false;
		}

		return true;
	}
};

int main( )
{
	int n; 

	cin >> n;
	vi arr( n+1 );
	vi q( n+1 );
	vi pos( n+1 );

	for( int i = 0; i < n ; ++i )
	{
		cin >> arr[ i ];
		pos[ arr[ i ] ] = i;
	}

	for( int i = 0 ; i < n; ++i )
	{
		cin >> q[ i ];
		q[ i ]--;
	}

	segment tree( n );
	int ans = n, i = 0 ;

	while( i < n )
	{
		while( tree.decrease( pos[ ans ] ) )
			--ans;

		cout << ans << ' ';
		tree.update( 0, q[ i++ ], 1 );
	}
	cout << '\n';
	return 0;
}