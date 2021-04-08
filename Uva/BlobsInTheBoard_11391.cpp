#include <bits/stdc++.h>
#define maxn ( 1 << 16 ) 

using namespace std;

int row, col;
int memo[ maxn ];
int mvx2[ ] = { 0, -2, -2, -2, 0, 2, 2, 2};
int mvx1[ ] = { 0, -1, -1, -1, 0, 1, 1, 1};
int mvy2[ ] = { 2, 2, 0, -2, -2, -2, 0, 2};
int mvy1[ ] = { 1, 1, 0, -1, -1, -1, 0, 1};

inline int LSOne( int n )
{
	return n & (-n);
}

inline int bit( int x, int y )
{
	return ( 1 << (col*x + y) );
}

inline bool there_is( int x, int y, int est )
{
	return est & bit( x, y );
}

bool is_pos( int x, int y, int est )
{
	if( x < 0 || x >= row )
		return false;

	if( y < 0 || y >= col )
		return false;
	
	if( there_is( x, y, est ) )
		return false;
	
	return true;
}

int dp( int est )
{
	if( est - LSOne( est) == 0 )
		return 1;
	
	if( ~memo[ est ] )
		return memo[ est ];
	
	int ans = 0;
	for( int i = 0; i < row*col; ++i )
	{
		if( est & (1 << i) )
		{
			int _x = i/col;
			int _y = i%col;

			for( int i = 0; i < 8; ++i )
			{
				int x = _x + mvx2[ i ];
				int xx = _x + mvx1[ i ];
				
				int y = _y + mvy2[ i ];
				int yy = _y + mvy1[ i ];

				if( is_pos( x, y, est ) && there_is( xx, yy, est ) )
					ans += dp( ( est | bit(x,y) ) - ( bit( _x, _y ) | bit( xx, yy) ) );
			}
		}
	}
	return memo[ est ] = ans;
}

int main()
{
	int t, conf, n, x, y;

	cin >> t;
	for( int cases = 1; cases <= t; ++cases )
	{
		conf = 0;
		memset( memo, -1, sizeof memo );

		cin >> row >> col >> n;
		for( int i = 0; i < n; ++i )
		{
			cin >> x >> y; --x; --y;
			conf |= bit( x, y );
		}
		cout << "Case " << cases << ": " << dp( conf ) << '\n';
	}
	return 0;
}
