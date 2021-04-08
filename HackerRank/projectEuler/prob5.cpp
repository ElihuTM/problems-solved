#include <bits/stdc++.h>
#define maxn 42

using namespace std;
typedef long long ll;

ll ans[ maxn ];

ll gcd( ll a, ll b ) { return b == 0 ? a : gcd( b, a%b ); }

int main()
{
	ans[ 1 ] = 1;
	for( int i = 2; i < maxn; ++i )
		ans[ i ] = (ans[ i-1 ] / gcd( ans[ i-1 ], i ) ) * i;

	int t, n;
	cin >> t;

	while( t-- )
	{
		cin >> n;
		cout << ans[ n ] << '\n';
	}

	return 0;
}
