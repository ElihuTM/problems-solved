#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
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
	
	vi sum, set;
	ll t, n, k;
	string cad;

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		sum = vi(n+k+5, 0 );
		set = vi(n+k+5, 0 );

		cin >> cad;
		for (int i = n-1; i >= 0 ; --i)
		{
			sum[ i ] = sum[ i+1 ] + (cad[ i ] == '1' );
			set[ i ] = (cad[ i ] == '0');
			set[ i ] += sum[ i+1 ] - sum[ i+k ];
			set[ i ] += min( sum[ i+k ], set[ i+k ] );
		}

		/*
		for (int i = 0; i < n; ++i)
			cout << ' ' << sum[ i ];
		cout << endl;


		for (int i = 0; i < n; ++i)
			cout << ' ' << set[ i ];
		cout << endl;
		*/
		
		ll ans = min( sum[ 0 ], set[ 0 ] );
		ll cont = 0;
		for (int i = 1; i <= n; ++i)
		{
			cont += ( cad[ i-1 ] == '1' );
			ans = min( ans, min(sum[ i ], set[ i ]) + cont );
		}

		cout << ans << endl;
	}

	return 0;
}
