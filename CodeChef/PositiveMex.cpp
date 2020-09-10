#include <bits/stdc++.h>
#define mod( x )(((x % md ) + md ) % md )
#define md 998244353
#define maxn 100005

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main()
{
	vi pow2( maxn );
	int t, n, a;
	vi arr;

	pow2[ 0 ] = 1;
	for (int i = 1; i < maxn; ++i)
		pow2[ i ] = mod( pow2[ i-1] * 2 );

	cin >> t;
	while( t-- )
	{
		cin >> n;

		arr = vi( maxn, 0 );
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			if( a < maxn )
				arr[ a ]++;
		}

		ll exp = 1;
		ll acum = 0;
		ll ans = 0;
		ll aux;

		for (int i = 1; i < maxn; ++i)
		{
			aux = mod( pow2[ n-acum-arr[ i ] ] * exp );
			aux = mod( aux*i );
			ans = mod( ans + aux );

			acum += arr[ i ];
			exp = mod(exp * mod( pow2[ arr[ i ] ]-1 ) );

			if ( arr[ i ] == 0)
				break;
		}

		cout << mod( ans ) << '\n';
	}

}