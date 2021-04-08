#include <bits/stdc++.h>
#define maxn 1000002

using namespace std;
typedef long long ll;

bitset <maxn> criba;
ll ans[ maxn ];

void llena()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = 0;

	for( int i = 4; i < maxn; i+= 2)
		criba[ i ] = false;

	for( ll i = 3; i < maxn; i+= 2 )
		if( criba[ i ] )
			for( ll j = i*i; j < maxn; j += i )
				criba[ j ] = false;
}

int main()
{
	llena();

	int t, n;
	cin >> t;
	
	ans[ 0 ] = 0;
	for( int i = 1; i < maxn; ++i )
	{
		ans[ i ] = ans[ i-1 ];
		if( criba[ i ] )
			ans[ i ] += i;
	}

	while( t-- )
	{
		cin >> n;
		cout << ans[ n ] << '\n';
	}

	return 0;
}
