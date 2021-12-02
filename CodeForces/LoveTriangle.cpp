#include <bits/stdc++.h>

using namespace std;
typedef vector< int > vi;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, b, c;

	cin >> n;
	vi arr( n, -1 );

	for( int i = 0; i < n; ++i )
		cin >> arr[ i ];

	for( int i = 0; i < n; ++i )
	{
		b = arr[ i ] - 1;
		c = arr[ b ] - 1;
		
		if( arr[ c ] - 1 == i )
		{
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}
