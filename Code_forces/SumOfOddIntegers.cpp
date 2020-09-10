#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool is_pos( ll n, ll k )
{
	if ( (n%2) != (k%2) )
		return false;

	if ( k*k > n )
		return false;

	return true;
}

k(n+m)
nm+mm

int main()
{
	ll t, n ,k;

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		if ( is_pos( n,k ) )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
	