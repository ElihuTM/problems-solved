#include <bits/stdc++.h>

using namespace std;

vector <long long> arr;

int main()
{
	int t, n;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		arr.resize( n );

		for( int i=0; i<n; ++i )
			cin >> arr[ i ];
	
		long long ans = 0;
		for( int i=0; i<n; i+=2 )
			ans += arr[ i ];

		long long maxsum1 = 0;
		long long cont = 0;

		for( int i = 1; i<n; i+=2 )
		{
			cont += arr[ i ] - arr[ i-1 ];
			maxsum1 = max( maxsum1, cont );

			if( cont < 0 )
				cont = 0;
		}

		long long maxsum2 = 0;
		cont = 0;
		for( int i=1; i<n-1; i+=2 )
		{
			cont += arr[ i ] - arr[ i+1 ];
			maxsum2 = max( maxsum2, cont );

			if( cont < 0 )
				cont = 0;
		}

		cout << ans + max( maxsum1, maxsum2 ) << '\n';
	}
	return 0;
}
