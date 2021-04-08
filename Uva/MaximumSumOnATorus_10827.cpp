#include <bits/stdc++.h>
#define maxn 200

using namespace std;

int arr[ maxn ][ maxn ];
int n;

int main()
{
	int t;
	cin >> t;

	while( t-- )
	{
		cin >> n;
		for( int i = 1; i <= n; ++i )
			for( int j = 1; j <= n; ++j )
			{
				cin >> arr[ i ][ j ];
				arr[ i+n ][ j ] = arr[ i ][ j+n ] = arr[ i+n ][ j+n ] = arr[ i ][ j ];
			}
		for( int i = 1; i <= 2*n; ++i )
			for( int j = 1; j <= 2*n; ++j )
				arr[ i ][ j ] += arr[ i-1 ][ j ] + arr[ i ][ j-1 ] - arr[ i-1 ][ j-1 ];

		int aux, ans = -1000000;
		for( int i = 1; i <= n; ++i )
			for( int j = 1; j <= n; ++j )
				for( int k = 0; k < n; ++k )
					for( int l = 0; l < n; ++l )
					{
						aux = arr[ i+k ][ j+l ] - arr[ i+k ][ j-1 ] - arr[ i-1 ][ j+l ] + arr[ i-1 ][ j-1 ];
						ans = max( ans, aux );
					}

		cout << ans << '\n';
	}
	return 0;
}
