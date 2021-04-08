#include <bits/stdc++.h>
#define maxn 101

using namespace std;

string mat[ maxn ];
int n;
int mvx[ ] = { 1, -1, 0, 0 };
int mvy[ ] = { 0, 0, 1, -1 };

bool is_pos( int x, int y )
{
	if( x < 0 || x >= n )
		return false;
	
	if( y < 0 || y >= n )
		return false;

	return true;
}

int f_f( int x, int y )
{
	mat[ x ][ y ] = '.';

	for( int i = 0; i < 4; ++i )
	{
		int xx = x + mvx[ i ];
		int yy = y + mvy[ i ];

		if( is_pos( xx , yy ) && (mat[ xx ][ yy ] == 'x' || mat[ xx ][ yy ] == '@' ) )
			f_f( xx, yy );
	}

	return 1;
}

int main()
{
	int casos, ans;

	cin >> casos;
	for( int qw = 1; qw <= casos; ++qw )
	{
		ans = 0;
		cin >> n;

		for( int i = 0; i < n; ++i )
			cin >> mat[ i ];

		for( int i = 0; i < n; ++i )
			for( int j = 0; j < n; ++j )
				if( mat[ i ][ j ] == 'x' )
					ans += f_f( i, j );

		cout << "Case " << qw << ": " << ans << '\n';
	}
	return 0;
}
