#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

struct point
{
	ld x;
	ld y;

	point() : x( 0 ), y( 0 ) { }
	point( ld a, ld b ) : x( a ), y( b ) { }

	ld dist( point p ) {
		ld xx = (x-p.x)*(x-p.x);
		ld yy = (y-p.y)*(y-p.y);

		return sqrt( xx + yy );
	}

	point rotate( ld angle ) {
		return point( x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle));
	}
};

typedef vector<point> vp;
typedef vector<vp> vvp;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ld pi = acos( -1 );
const ld grad = 2*pi;
vvp lista;
vvld memo;
vi arr;

int main()
{
	int n, q, x;

	cin >> n;
	memo = vvld( n );
	arr = vi( n );
	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	cin >> q;
	lista = vvp( 105 );

	
	/*
	cout << pi << '\n';
	
	point uno;
	uno =  point( 1,0 ).rotate( 0 );
	cout << uno.x << ' ' << uno.y << endl;

	uno =  point( 1,0 ).rotate( pi / 2 );
	cout << uno.x << ' ' << uno.y << endl;

	uno =  point( 1,0 ).rotate( pi );
	cout << uno.x << ' ' << uno.y << endl;

	uno =  point( 1,0 ).rotate( pi * 3.0/2.0 );
	cout << uno.x << ' ' << uno.y << endl;
	
	uno =  point( 1,0 ).rotate( pi * 288.0/180.0 );
	cout << uno.x << ' ' << uno.y << endl;

	cout << "salio\n";
	cout << q << endl;
	*/
	for (int i = 0; i < q; ++i)
	{
		cin >> x;
		lista[ x ].push_back( point(1,0).rotate( grad*i/q ) );
		//cout << i << ": " << lista[ x ].back().x << ' ' << lista[ x ].back().y << endl;
	}

	int b, a = arr.back();
	memo[ n-1 ] = vld( lista[ a ].size(), 0.0 );
	for (int i = n-2; i >= 0; --i)
	{
		a = arr[ i ], b = arr[ i+1 ];
		memo[ i ] = vld( lista[ a ].size(), -27.0 );

		for (int j = 0; j < lista[ a ].size(); ++j)
		{
			memo[ i ][ j ] = lista[ a ][ j ].dist( lista[ b ][ 0 ] ) + memo[ i+1 ][ 0 ];
			for (int k = 0; k < lista[ b ].size(); ++k)
			{
				ld dist = lista[ a ][ j ].dist( lista[ b ][ k ] ) + memo[ i+1 ][ k ];
				
				//cout << "point 1: " << lista[ a ][ j ].x << ' ' << lista[ a ][ j ].y << endl;
				//cout << "point 2: " << lista[ b ][ k ].x << ' ' << lista[ b ][ k ].y << endl;
				//cout << dist << endl;
				memo[ i ][ j ] = min( memo[ i ][ j ], dist );
			}
		}
	}

	//cout << "dist " << lista[ 2 ][ 0 ].dist( lista[ 3 ][ 0 ] ) << endl;

	a = arr[ 0 ];
	ld ans = memo [ 0 ][ 0 ];
	for (int i = 0; i < memo[ 0 ].size(); ++i)
		ans = min( ans, memo[ 0 ][ i ] );

	printf("%.8llf\n", ans+1.0);
	return 0;
}