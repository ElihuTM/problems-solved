#include <bits/stdc++.h>

using namespace std;
typedef vector < vector <int> > vvi;
typedef vector <string> vs;

vvi memo;
vs mat;



int main()
{
	int n, m;
	
	cin >> n >> m;
	
	memo = vvi(n+1);
	mat = vs(n+1);
	
	for( int i = 0; i < n; ++i )
	{
		memo[ i ].resize( m+1, 0 );
		cin >> mat[ i ];
		mat[ i ].push_back('#');
	}
	
	int ans = 0;
	for( int i  =0; i < m+1; ++i )
		mat[ n ].push_back( '#' );
	
	ans = 2;
	memo[ n-1 ][ m-1 ] = 1;
	for( int i = n-1; i >= 0; --i )
		for( int j = m-1; j >= 0; --j)
		{	
			int cont = 0;
			if( mat[ i+1 ][ j ] != '#' && memo[ i+1 ][ j ] != 0 )
			{
				++cont;
				memo[ i ][ j ] += memo[ i+1 ][ j ];
			}

			if( mat[ i ][ j+1 ] != '#' && memo[ i ][ j+1 ] != 0 )
			{
				++cont;
				memo[ i ][ j ] += memo[ i ][ j+1 ];
			}

			if( ans != 1 && cont == 2 )
				ans = 1;
		}
	if( memo[ 0 ][ 0 ] == 0)
		cout << "0\n";
	else
		cout << ans << endl;

	return 0;
}
