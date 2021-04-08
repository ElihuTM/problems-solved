#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int memo[ maxn ][ maxn ];
string cad;

int dp( int i, int j )
{
	if( j < i )	return 0;
	if( i == j ) return 1;
	if( i == j-1 ) return(cad[ i ] == cad[ j ] ? 2 : 1);

	if( ~memo[ i ][ j ] )
		return memo[ i ][ j ];
	
	int ans = 0;
	if( cad[ i ] == cad[ j ] )
		ans = 2 + dp( i+1, j-1 );
	
	ans = max( ans, dp( i+1, j ) );
	ans = max( ans, dp( i, j-1 ) );

	return memo[ i ][ j ] = ans;
}

int main()
{
	int n;

	cin >> n;
	getline(cin, cad );

	while( n-- )
	{
		getline(cin, cad );

		memset( memo, -1, sizeof memo );
		cout << dp( 0, cad.size()-1 ) << '\n';
	}
	return 0;
}
