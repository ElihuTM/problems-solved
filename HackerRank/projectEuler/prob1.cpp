#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll t, n;
	cin >> t;

	while( t-- )
	{
		cin >> n;
		ll x3 =  n / 3 - ( n % 3 == 0 );
		ll x5 =  n / 5 - ( n % 5 == 0 );
		ll x15 = n / 15 - ( n % 15 == 0 );
		
		x3 = 3*((x3*(x3+1)) / 2 );
		x5 = 5*((x5*(x5+1)) / 2 );
		x15 = 15*((x15*(x15+1)) / 2 );
		
		cout << x3 + x5 - x15 << '\n';
	}
	return 0;
}
