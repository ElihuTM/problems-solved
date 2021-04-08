#include <bits/stdc++.h>
#define maxn 105
#define ff first
#define ss second

using namespace std;

int mat[ maxn ][ maxn ];
int row[ maxn ];
int col[ maxn ];

int main()
{
	int r,c;

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		cin >> row[ i ];
	
	for (int i = 0; i < c; ++i)
		cin >> col[ i ];

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j )
			mat[ i ][ j ] = min( row[ i ], col[ j ] );
	
	for( int i = 0; i < r; ++i )
	{
		int maxi = -1;
		for (int j = 0; j < c; ++j)
			maxi = max( maxi, mat[ i ][ j ] );

		if( row[ i ] != maxi )
		{
			cout << "impossible\n";
			return 0;
		}
	}

	for( int j = 0; j < c; ++j )
	{
		int maxi = -1;
		for (int i = 0; i < r; ++i)
			maxi = max( maxi, mat[ i ][ j ] );

		if( col[ j ] != maxi )
		{
			cout << "impossible\n";
			return 0;
		}
	}

	cout << "possible\n";
	return 0;
}