#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector <ll> arr[ 10 ];

int main()
{
	int t;
	ll n, m;

	cin >> t;

	for( int i = 1; i < 10; ++i )
	{
		arr[ i ].push_back( i );
		while( (arr[ i ].back() + i ) % 10 != i )
			arr[ i ].push_back( (arr[ i ].back() + i ) % 10 );

		for( int j = 1; j < arr[ i ].size(); ++j )
			arr[ i ][ j ] += arr[ i ][ j-1 ];
	}

	/*
	for( int i=1; i < 10; ++i )
	{
		cout << arr[ i ].back() << endl;
		
		for( auto c: arr[ i ] )
			cout << " " << c;
		cout << endl;
		
	}*/
	
	
	while( t-- )
	{
		cin >> n >> m;

		if( m%10 == 0 )
			cout << 0 << '\n';
		else
		{
			ll divs = n/m;
			
			m %= 10;
			ll ans = (divs / arr[ m ].size()) * arr[ m ].back();
			
			if( divs%arr[ m ].size() != 0 )
				ans += arr[ m ][ (divs%arr[ m ].size())-1 ];

			cout << ans << '\n';
		}
	}
}
