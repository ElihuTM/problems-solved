#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;
typedef long long ll;

bitset <maxn> criba;

void llena()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = false;

	for( int i = 4; i < maxn; i+=2 )
		criba[ i ] = false;

	for( ll i = 3; i < maxn; i+=2 )
		if( criba[ i ] )
			for( ll j = i*i; j < maxn; j+=i )
				criba[ j ] = false;
}

bool is_truncatable( int n, int pot )
{
	int cop0 = n;

	while( n )
	{
		if( !criba[ n ] )
			return false;

		n = n - pot*(n/pot);
		pot /= 10;
	}
	n = cop0;

	while( n )
	{
		if( !criba[ n ] )
			return false;

		n /= 10;
	}

	return true;
}

int main()
{
	int n, pot = 10;
	ll ans = 0;
	llena();

	cin >> n;
	for( int i = 10; i < n; ++i )
	{
		if( i == 10*pot ) pot *= 10;
		if( is_truncatable( i, pot ) )
			ans += i;
	}

	cout << ans << '\n';
	return 0;
}
