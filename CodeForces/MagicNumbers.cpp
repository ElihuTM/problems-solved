#include <bits/stdc++.h>
#define maxn 2001
#define mod 1000000007

using namespace std;

long long memo[ maxn ][ maxn ][ 2 ];
long long pot[ maxn ];
long long m,d;
string a,b;

long long dp( long long pos, long long res, long long is_lim )
{
	if ( pos == a.size() )
		return res == 0;
	
	if ( ~memo[ pos ][ res ][ is_lim ] )
		return memo[ pos ][ res ][ is_lim ];

	long long ans = 0;
	if ( pos&1 )
	{
		if ( is_lim == 1 )
		{
			if( d > a[ pos ] - '0' )
				ans = 0;
			else
				ans = dp( pos+1, (res + (d*pot[ pos ]) % m) % m, d == a[ pos ] - '0' );
		}
		else
			ans = dp( pos+1, (res + (d*pot[ pos ]) % m) % m, 0 );
	}
	else
	{
		if ( is_lim == 1)
		{
			for (int i = 0; i <= a[ pos ] - '0'; ++i)
				if ( i != d )
				{
					ans += dp( pos+1, (res + (i*pot[ pos ]) % m) % m, i == a[ pos ] - '0' );
					ans %= mod;
				}
		}
		else
		{
			for (int i = 0; i < 10; ++i)
				if ( i != d )
				{
					ans += dp( pos+1, (res + (i*pot[ pos ]) % m) % m, 0 );
					ans %= mod;
				}
		}
	}

	return memo[ pos ][ res ][ is_lim ] = ans;
}

bool ismagic( string c )
{
	long long ans = 0;
	for (int i = 0; i < c.size(); ++i)
	{
		if ( ((i&1) && c[ i ]-'0' != d) || (!(i&1) && c[ i ]-'0' == d ))
			return false;

		ans = (ans*10) + c[ i ] - '0';
		ans %= m;
	}

	return ans % m == 0;
}

int main()
{
	memset( memo, -1, sizeof memo );
	cin >> m >> d;
	cin >> b;
	cin >> a;

	long long ans = 0;
	long long ans2 = 0;
	pot[ a.size()-1 ] = 1;
	for (int i = a.size()-2; i >= 0; --i)
			pot[ i ] = (pot[ i+1 ]*10) % m;

	for (int i = 1; i <= a[ 0 ]-'0'; ++i)
		if( i != d )
			ans = ( ans + dp( 1, (i*pot[ 0 ]) % m, i == a[ 0 ] - '0' )) % mod;

	a = b;
	memset( memo, -1, sizeof memo );
	for (int i = 1; i <= a[ 0 ]-'0'; ++i)
		if( i != d )
			ans2 = ( ans2 + dp( 1, (i*pot[ 0 ]) % m, i == a[ 0 ] - '0' )) % mod;


	cout << (ans-ans2+mod+ismagic(a))%mod << '\n';
	return 0;
}