#include <bits/stdc++.h>
#define maxn ( 1 << 17)

using namespace std;
typedef long double ld;

struct point
{
	int x, y;
	ld dist ( point &p )
	{
		int x2 = ( x - p.x )*( x - p.x );
		int y2 = ( y - p.y )*( y - p.y );

		return sqrt( x2 + y2 );
	}
};

inline point m_p( int x, int y )
{
	point aux;
	aux.x = x;
	aux.y = y;

	return aux;
}

typedef vector< point > vp;

vp arr;
int OK, n;
ld memo[ maxn ];

inline int LSOne( int n )
{
	return n & (-n);
}

int pos( int n )
{
	int it = 0;
	while( n )
	{
		n >>= 1;
		++it;
	}

	return it-1;
}

void imp( int n )
{
	while( n )
	{
		cout << (n&1);
		n >>= 1;
	}
	cout << endl;
}

ld dp( int estados )
{
	if( estados == OK )
		return 0;
	
	if( memo[ estados ] >= 0 )
		return memo[ estados ];
	
	int copia = (~estados) & OK;	
	int sec, fi = LSOne( copia );
	copia -= fi;
	
	ld aux, ans = 9999999999999;
	while( copia )
	{
		sec = LSOne( copia );
		aux = arr[ pos( fi ) ].dist( arr[ pos( sec ) ] ) + dp( estados | fi | sec );
		
		copia -= sec;
		ans = ( ans < aux ? ans : aux );
	}

	return memo[ estados ] = ans;
}

int main()
{
	int x, y, it = 1;
	string aux;
	
	cin >> n;
	while( n )
	{
		n <<= 1;
		for( int i = 0; i < maxn; ++i )
			memo[ i ] = -1;

		arr.resize( n );	
		for( int i = 0; i < n; ++i )
		{
			cin >> aux >> x >> y;
			arr[ i ] = m_p( x, y );
		}
		OK = ( 1 << n ) - 1;
		
		printf( "Case %d: %.2llf\n", it++, dp( 0 ) );
		cin >> n;
	}
	return 0;
}
