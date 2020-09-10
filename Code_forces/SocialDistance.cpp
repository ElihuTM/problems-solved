#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'

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
	
	ll t, n, k;
	string cad;
	vi ant;

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		cin >> cad;
		ant.assign( n, -1 );

		if( cad[ 0 ] == '1' )
			ant[ 0 ] = 0;

		for (int i = 1; i < n; ++i)
			if ( cad[ i ] == '1')
				ant[ i ] = i;
			else
				ant[ i ] = ant[ i-1 ];

		int ans = 0, i = n-1;
		while( i >= 0 )
		{
			if ( cad[ i ] == '1' )
				i -= k+1;
			else if ( ant[ i ] < i-k or ant[ i ] == -1 )
			{
				cout << i << " " << ant[ i ] << endl;
				++ans;
				i -= k+1;
			}
			else
				i = ant[ i ];
		}

		reverse( cad.begin(), cad.end() );
		ant.assign( n, -1 );

		if( cad[ 0 ] == '1' )
			ant[ 0 ] == 0;

		for (int i = 1; i < n; ++i)
			if ( cad[ i ] == '1')
				ant[ i ] = i;
			else
				ant[ i ] = ant[ i-1 ];

		int ans1 = 0;
		i = n-1;
		while( i >= 0 )
		{
			if ( cad[ i ] == '1' )
				i -= k+1;
			else if ( ant[ i ] < i-k or ant[ i ] == -1 )
			{
				++ans1;
				i -= k+1;
			}
			else
				i = ant[ i ];
		}

		cout << ans << " " << ans1 << endl;
		cout << max(ans, ans1) << endl;
	}

	return 0;
}