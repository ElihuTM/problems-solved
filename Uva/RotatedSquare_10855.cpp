#include <bits/stdc++.h>
#define mod 1000000007
#define b 31

using namespace std;
typedef long long ll;
typedef vector <ll> vi;
typedef vector <string> vs;

int main()
{
	int n, m;
	vs gran;
	vs peq;
	vi ans;
	vector< vi > acum;

	cin >> n >> m;
	while( n || m )
	{
		gran.resize( n );
		peq.resize( m );
		ans.resize( m, 0 );
		acum.resize( n );

		for( int i = 0; i < n; ++i )
			cin >> gran[ i ];

		for( int i = 0; i < m; ++i )
			cin >> peq[ i ];
		
		for( int i=0; i < m; ++i )
			for( int j = 0; j < m; ++j )
				ans[ i ] = ((ans[ i ] * b) + peq[ i ][ j ] - 'A') % mod;
	
		for( int i = 0; i < n; ++i )
		{
			acum[ n ].resize( n, 0 );
			for( int j = 0; j < n; ++j )
			{
				acum[ i ][ j ] 
			}
		}
		cin >> n >> m;
	}
	return 0;
}
