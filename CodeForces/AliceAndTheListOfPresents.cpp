#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long fast_pow( long long x, long long exp )
{
	long long ans = 1;
	while( exp )
	{
		if( exp & 1 )
		{
			ans = ( ans * x ) % mod;
		}

		x = ( x * x ) % mod;
		exp >>= 1;
	}
	return ans;
}

int main()
{
	long long n, m;
	cin >> n >> m;

	long long ans = (fast_pow( 2, m ) + mod - 1 ) % mod;
	
	cout << fast_pow( ans, n ) << '\n';
	return 0;
}
