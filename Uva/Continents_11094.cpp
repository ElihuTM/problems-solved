#include <bits/stdc++.h>
#define maxn 21

using namespace std;

int n, m;
string mat[ maxn ];
int mvx[ ] = { 1, -1, 0, 0 };
int mvy[ ] = { 0, 0, 1, -1 };
char tierra;

inline bool is_pos( int x )
{
	return ( x >= 0 && x < n );
}

int ab( int x )
{
	if( x == m )
		return 0;

	if( x == -1 )
		return m-1;

	return x;
}

int f_f( int x, int y )
{
	mat[ x ][ y ] = tierra - 1;
	int ans = 1;

	for( int i = 0; i < 4; ++i )
	{
		int xx = x + mvx[ i ];
		int yy = ab( y + mvy[ i ] );

		if( is_pos( xx ) && mat[ xx ][ yy ] == tierra )
			ans += f_f( xx, yy );
	}

	return ans;
}

int main()
{
	int ans, x, y;
	while( cin >> n >> m )
	{
		ans = 0;
		for( int i = 0; i < n; ++i )
			cin >> mat[ i ];
		
		cin >> x >> y;
		tierra =  mat[ x ][ y ];

		f_f( x, y );

		for( int i = 0; i < n; ++i )
			for( int j = 0; j < m; ++j )
				if( mat[ i ][ j ] == tierra )
					ans = max( ans, f_f( i, j ) );

		cout << ans << '\n';
	}
	return 0;
}
