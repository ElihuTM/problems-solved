#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main()
{
	int n;
	ll tot = 0;
	
	cin >> n;
	vi arr( n );
	vi memo( n );

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ];
		tot += arr[ i ];
	}

	if ( n == 1 )
	{
		cout << "0 0\n";
		return 0;
	}

	if( n == 2 )
	{
		cout << tot << ' ' << min(arr[ 0 ], arr[ 1 ] ) << '\n';
		return 0;
	}

	if ( n == 3 )
	{
	
		cout << 2*tot << ' ' << arr[ 0 ]+arr[ 2 ] << '\n';
		return 0;
	}

	if ( n == 4)
	{
		ll ans1 = arr[ 0 ] + arr[ 2 ] + 2*ar[ 3 ];
		ll ans2 = 2*arr[ 0 ] + arr[ 2 ] + ar[ 3 ];
		cout << 2*tot << ' ' << min( ans1, ans2 ) << '\n';
		return 0;
	}

	memo[ n-1 ] = 0;
	memo[ n-2 ] = arr[ n-1 ];
	memo[ n-3 ] = min( 2*arr[ n-1 ]+arr[ n-2 ], arr[ n-3 ]+arr[ n-1 ]);

	for (int i = n-4; i > 0 ; --i)
		memo[ i ] = min( arr[ i+1 ]+memo[ i+2 ], arr[ i ]+memo[ i+1 ] );

	ll ans1 = arr[ 0 ] + memo[ 1 ];
	ll ans2 = 2*arr[ 0 ]

	cout << 2*tot << ' ' << min( ans1, ans2 ) << '\n';
	return 0;
}