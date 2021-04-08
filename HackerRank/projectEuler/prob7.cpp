#include <bits/stdc++.h>
#define maxn 1000000

using namespace std;
typedef long long ll;

bitset < maxn > criba;
vector < ll > p;

void llena()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = false;

	p.push_back( 2 );
	for( int i = 4; i < maxn; i += 2 )
		criba[ i ] = false;

	for( ll i = 3; i < maxn; i += 2 )
		if( criba[ i ] )
		{
			p.push_back( i );
			for( ll j = i*i; j < maxn; j += i )
				criba[ j ] = false;
		}
}

int main()
{
	int t, x;
	llena();

	cin >> t;
	
	while( t-- )
	{
		cin >> x;
		cout << p[ x-1 ] << '\n';
	}
	return 0;
}
