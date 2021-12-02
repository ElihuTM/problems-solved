#include <bits/stdc++.h>
#define maxn 300007

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll muv( vi a, vi b )
{
	ll n = a.size(), ans = 0;

	for (int i = 0; i < n; ++i)
	{
		if ( a[ i ] > 0 )
			ans += a[ i ];
		
		a[ (i+1)%n ] -= b[ i ];
	}

	return ans;
}

ll fun( vi a, vi b, ll ans)
{
	ll ant = ans, n = a.size();

	for ( int i = n-1; i > 0; --i)
	{
		ant -= a[ (i+1)%n ];
		ant -= max( (ll)0, a[ i ] - b[ (i+n-1)%n ] );

		ant += a[ i ];
		ant += max( (ll)0, a[ (i+1)%n ] - b[ i ] );

		ans = min( ans, ant );
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t, n, k;
	vi a;
	vi b;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		a = vi( n );
		b = vi( n );

		for (int i = 0; i < n; ++i)
			cin >> a[ i ] >> b[ i ];

		ll ans = muv( a, b );
		ans = fun( a, b, ans );

		cout << ans << '\n';
	}
	return 0;
}	
	