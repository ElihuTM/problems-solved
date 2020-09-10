#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define all(x) x.begin(),x.end()
#define p_b(a) push_back(a)
#define sz(a) s.size()
#define endl '\n'
#define forn(i,n)  for ( int i = 0; i < n; ++i )

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t, n k;
	vi a, b;

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		ll ans = 0;
		a = vi( n );
		b = vi( n );

		for (int i = 0; i < n; ++i)
		{
			cin >> a[ i ];
			ans += a[ i ];
		}

		for (int i = 0; i < n; ++i)
			cin >> b[ i ];

		sort( all(a) );
		sort( all(b) );

		int i = n-1;
		int j = 0;

		while( k-- )
		{
			if ( b[ i ] <= a[ j ] )
				break;

			ans -= a[ j ];
			ans += b[ i ];

			--i;
			++j;
		}

		cout << ans << endl;
	}

	return 0;
}
