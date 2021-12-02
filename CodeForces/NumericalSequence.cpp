#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f_p( ll e, ll x )
{
	ll ans = 1;
	while( x )
	{
		if ( x&1)
			ans *= e;

		e *= e;
		x >>= 1;
	}
	return ans;
}

ll sum( ll a, ll b ) {
	return (b*(b+1)/2) - (a*(a-1)/2);
}

ll get_length( ll n )
{
	if( n < 10 ) return sum( 1, n );

	int d = to_string(n).size();
	ll l = n, r = n-8, ans = 0;

	for (int i = 1; i <= d; ++i)
	{
		ans += sum( r, l )*i;
		l = r-1;
		r = r-9*f_p(10,i);
		if ( r <= 0)
			r = 1;
	}
	return ans;
}

ll l_b( ll value )
{
	ll i = 1, j = 1000000000, m;
	while( j-i > 1 )
	{
		m = i + (j-i)/2;
		if ( sum(1,m) > value )
			j = m;
		else
			i = m;
	}
	return i;
}

int main()
{
	int t;
	ll k;

	cin >> t;
	while( t-- )
	{
		cin >> k;
		ll pos = l_b( k );
	}
	return 0;
}