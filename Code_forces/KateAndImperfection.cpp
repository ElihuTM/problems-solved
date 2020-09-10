#include <bits/stdc++.h>
#define maxn 500005

using namespace std;
typedef long long ll;

int criba[ maxn ];

void llenar()
{
	criba[ 0 ] = 1;
	for (int i = 1; i < maxn; ++i)
		criba[ i ] = i;

	for ( ll i = 2; i < maxn; ++i)
		if( i == criba[ i ] )
			for ( ll j = i*i; j < maxn; j += i)
				if ( i < criba[ j ])
					criba[ j ] = i;
}

int main()
{
	ll n;
	llenar();

	cin >> n;
	map<ll,ll> reps;

	for ( ll i = 2; i <= n; ++i)
		reps[ i/criba[ i ] ]++;

	for ( auto c: reps )
		for (int i = 0; i < c.second; ++i)
			cout << c.first << ' ';
	cout << endl;
	return 0;
}	