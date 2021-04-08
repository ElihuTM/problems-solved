#include <bits/stdc++.h>
#define maxn 200

using namespace std;

int arr[ maxn ][ maxn ];

int main()
{
	int t, n;
	cin >> t;

	while( t-- )
	{
		cin >> n;
		for( int i = 0; i < n; ++i )
			for( int j = 0; j <= i; ++j )
				cin >> arr[ i ][ j ];

		for( int i = n-2; i >= 0; --i )
			for( int j = 0; j <= i; ++j )
				arr[ i ][ j ] += max( arr[ i+1 ][ j ], arr[ i+1 ][ j+1 ] );

		cout << arr[ 0 ][ 0 ] << '\n';
	}
	return 0;
}
