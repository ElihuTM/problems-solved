#include <bits/stdc++.h>
#define maxn 20

using namespace std;

int mat[ maxn ][ maxn ];

int main()
{
	for( int i = 0; i < maxn; ++i )
		for( int j = 0; j < maxn; ++j )
			cin >> mat[ i ][ j ];

	int aux, ans = 0;
	for( int i = 0; i < maxn; ++i )
		for( int j = 0; j < maxn-3; ++j )
		{
			aux = mat[ i ][ j ]*mat[ i ][ j+1 ]*mat[ i ][ j+2 ]*mat[ i ][ j+3 ]; 
			ans = max( ans, aux );
		}

	for( int i = 0; i < maxn-3; ++i )
		for( int j = 0; j < maxn; ++j )
		{
			aux = mat[ i ][ j ]*mat[ i+1 ][ j ]*mat[ i+2 ][ j ]*mat[ i+3 ][ j ]; 
			ans = max( ans, aux );
		}

	for( int i = 0; i < maxn-3; ++i )
		for( int j = 3; j < maxn; ++j )
		{
			aux = mat[ i ][ j ]*mat[ i+1 ][ j-1 ]*mat[ i+2 ][ j-2 ]*mat[ i+3 ][ j-3 ]; 
			ans = max( ans, aux );
		}

	for( int i = 0; i < maxn-3; ++i )
		for( int j = 0; j < maxn-3; ++j )
		{
			aux = mat[ i ][ j ]*mat[ i+1 ][ j+1 ]*mat[ i+2 ][ j+2 ]*mat[ i+3 ][ j+3 ]; 
			ans = max( ans, aux );
		}

	cout << ans << '\n';
	return 0;
}
