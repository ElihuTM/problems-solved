#include <bits/stdc++.h>

using namespace std;
typedef vector <int > vi;

int main()
{
	int n, k, media;
	cin >> n >> k;

	vi arr( n );
	for( int i = 0; i < n; ++i )
		cin >> arr[ i ];

	sort( arr.begin(), arr.end() );

	int it = n/2;
	int mid = n/2;
	media = arr[ it ];
	
	while( k && it < n-1 )
	{
		while( it < n && arr[ it ] == media ) ++it;
		if( it == n ) --it;
		
		if( (it-mid) * ( arr[ it ] - media) <= k )
		{
			k -= (it-mid) * ( arr[ it ] - media);
			media = arr[ it ];
		}
		else
		{
			media += k / ( it-mid );
			k = 0;
		}
	}
	
	media += k / ( n-mid );

	cout << media << '\n';
	return 0;
}
