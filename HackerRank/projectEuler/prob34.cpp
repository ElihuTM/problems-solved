#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fact[ 10 ];

bool is_courius( int n )
{
	ll ans = 0, copia  = n;
	while( copia )
	{
		ans = (ans + fact[ copia % 10 ] ) % n;
		copia /= 10;
	}

	return ans == 0;
}

int main()
{
	int  n;
	ll ans = 0;

	fact[ 0 ] = 1;
	for( int i = 1; i < 10; ++i )
		fact[ i ] = i*fact[ i-1 ];

	cin >> n;
	for( int i = 10; i < n; ++i )
		if( is_courius( i ) )
			ans += i;

	cout << ans << '\n';
	return 0;
}
