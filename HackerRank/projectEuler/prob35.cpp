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

bool is_rot( int n, int pot )
{
	int dig;
	for( int i = 0; i < 6; ++i )
	{
		dig = n%10;
		n = (n/10) + (dig*pot);

		if( !criba[ n ] )
			return false;
	}

	return true;
}

int main()
{
	int n,pot;
	ll ans = 0;
	llena();

	cin >> n;
	pot = 1;
	for( int i = 0; i < n; ++i )
	{
		if( i == pot*10 ) pot *= 10;
		if( criba[ i ] && is_rot( i, pot ) )
			ans += i;
	}

	cout << ans << '\n';
	return 0;
}
