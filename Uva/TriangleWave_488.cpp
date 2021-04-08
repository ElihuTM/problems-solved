#include <bits/stdc++.h>

using namespace std;

void print( int n )
{
	for( int i = 0; i < n; ++i )
		cout << n;
	cout << '\n';
}

int main()
{
	int t, n, m;
	cin >> t;

	while( t-- )
	{
		cin >> n >> m;
		for( int i = 0; i < m; ++i )
		{
			for( int j = 1; j <= n; ++j )
				print( j );
			
			for( int j = n-1; j >= 1; --j )
				print( j );

			if( i < m-1 || t )
				cout << '\n';
		}
	}
	return 0;
}
