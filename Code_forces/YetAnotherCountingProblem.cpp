#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll mcm( ll a, ll b ){
	return a * ( b / __gcd( a, b ) );
}

int main()
{
	vi arr;
	ll t, a, b, l, r, n, ans, q;

	cin >> t;
	while( t-- )
	{
		cin >> a >> b >> q;

		ans = 0;
		n = mcm(a,b);
		arr = vi( n, 0 );

		for (int i = 1; i < n; ++i)
		{
			arr[ i ] = ((i%a)%b) != ((i%b)%a);
			arr[ i ] += arr[ i-1 ];
		}

		while( q-- )
		{
			cin >> l >> r;
			ans = 0;

			if ( r-l+1 < n && (r%n) >= (l%n) )
			{
				ll izq = ((l%n) == 0 ? 0 : arr[ (l%n)-1 ] );
				cout << arr[ r%n ] - izq;

				if ( q )
					cout << ' ';
				continue;
			}

			if ( l%n != 0 )
			{
				ans += arr.back() - arr[ (l%n)-1 ];
				//cout << endl << arr.back() - arr[ (l%n)-1 ] << endl;
				l += n - (l%n); 

			}

			if ( r%n != n-1 )
			{
				ans += arr[ r%n ];
				//cout << arr[ r%n ] << endl;
				r -= ((r%n)+1);

			}

			if ( l < r )
				ans += ((r-l+1)/n) * arr.back();
			
			cout << ans;

			if ( q )
				cout << ' ';
		}
		cout << endl;
	}
	return 0;
}