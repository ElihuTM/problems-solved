#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

bool is_the_ans( ll x, vi &arr )
{
	int i = 0, j = arr.size()-1;
	while( i <= j )
	{
		if ( arr[ i ]*arr[ j ] != x)
			return false;
		++i;
		--j;
	}

	return true;
}

bool have_n_divisors( ll x, ll n )
{
	ll raiz = sqrt( x );
	int cont = 0;

	for ( ll i = 2; i <= raiz; ++i)
	{
		if ( x%i == 0 )
		{
			if ( i*i == x)
				++cont;
			else
				cont += 2;
		}

		if ( cont > n )
			return false;
	}

	return cont == n;
}

int main()
{
	int t, n;
	vi arr;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		arr = vi( n );

		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];
		sort( arr.begin(), arr.end() );
	
		ll ans = arr[ 0 ]*arr[ n-1 ];		
		if ( is_the_ans( ans, arr ) && have_n_divisors( ans, n ) )
			cout << ans << '\n';
		else
			cout << "-1\n";
		
	}
	return 0;
}