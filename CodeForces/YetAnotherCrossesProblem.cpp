#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector< vc > vvc;

int main()
{
	int q, n, m;
	vvc mat;
	vi row;
	vi col;

	cin >> q;
	while( q-- )
	{
		cin >> n >>  m;
		
		row = vi( n, 0 );
		col = vi( m, 0 );
		mat = vvc( n );
		for( int i = 0; i < n; ++i )
		{
			mat[ i ] = vc( m );
			for( int j = 0; j < m; ++j )
			{
				cin >> mat[ i ][ j ];
				if( mat[ i ][ j ] == '.' )
				{
					++row[ i ];
					++col[ j ];
				}
			}
		}

		int ans = n*m;
		for( int i= 0; i < n; ++i )
			for( int j = 0; j < m; ++j )
				ans = min( ans, row[ i ] + col[ j ] - (mat[ i ][ j ] == '.') );

		cout << ans << '\n';
	}
	return 0;
}
