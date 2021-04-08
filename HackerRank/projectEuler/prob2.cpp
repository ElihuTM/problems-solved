#include <bits/stdc++.h>
#define maxn 50000000010000001L

using namespace std;
typedef long long ll;

int main()
{
	int t;
	ll x;
	cin >> t;
	
	vector <ll> fib;
	fib.push_back( 2 );
	fib.push_back( 8 );
	
	while( fib.back() < maxn )
		fib.push_back( 4*fib.back() + fib[ fib.size()-2 ] );
	
	while( t-- )
	{
		ll ans = 0;
		cin >> x;
		for( int i = 0; fib[ i ] <= x; ++i )
			ans += fib[ i ];

		cout << ans << '\n';
	}
	return 0;
}
