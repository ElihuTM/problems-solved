#include <bits/stdc++.h>
#define maxn 3000000

using namespace std;
typedef long long ll;

bitset <maxn> criba;
vector <ll> p;

void llena()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = false;

	for( int i = 4; i < maxn; i += 2 )
		criba[ i ] = false;
	
	p.push_back( 2 );
	for( ll i = 3; i < maxn; i += 2 )
		if( criba[ i ] )
		{
			for( ll j = i*i; j < maxn; j += i )
				criba[ j ] = false;
			p.push_back( i );
		}
}

ll max_factor( ll n )
{
	ll pp = 2, cont = 0, ans = 0;

	while( pp*pp <= n )
	{
		if( n % pp == 0 )
			ans = pp;

		while( n % pp == 0 )
			n /= pp;

		pp = p[ ++cont ];
	}

	if( n != 1 )
		ans = n;

	return ans;
}

int main()
{
	llena();

	int t;
	ll x;

	cin >> t;
	while( t-- )
	{
		cin >> x;
		cout << max_factor( x ) << '\n';
	}
	return 0;
}
