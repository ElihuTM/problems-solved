#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x, y;

	cin >> n >> x >> y;
	vector< int > arr( n );
	for( int i = 0; i < n; ++i )
		cin >> arr[ i ];
	
	for( int i = 0; i < n; ++i )
	{
		bool is_min = true;
		for( int j = 1; j <= x; ++j )
		{
			if( i-j < 0 )
				break;

			if( arr[ i-j ] <= arr[ i ] )
			{
				is_min = false;
				break;
			}
		}

		for( int j = 1; j <= y; ++j )
		{
			if( i+j >= n )
				break;

			if( arr[ i+j ] <= arr[ i ] )
			{
				is_min = false;
				break;
			}
		}

		if( is_min )
		{
			cout << i+1 << '\n';
			return 0;
		}
	}
	return 0;
}
