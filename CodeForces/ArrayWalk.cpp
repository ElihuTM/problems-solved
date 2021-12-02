#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
#define md(x) (((x%mod) + mod) % mod)
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
	
	vi arr;
	int n, k, z, t,
		lim;

	cin >> t;
	while( t-- ) {
		cin >> n >> k >> z;
		lim = min( n-1, k );
		arr.resize( n );

		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		pair <int, int> best_pair( 0, 0 );
		for (int i = 1; i <= lim; ++i)
			if ( arr[ i ] + arr[ i-1 ] > best_pair.ff )
				best_pair = make_pair( arr[ i ] + arr[ i-1 ], i );
			
		ll sum = arr[ 0 ], pos = best_pair.ss;

		for (int i = 1; i <= pos; ++i) {
			sum += arr[ i ];
			--k;
		}

		while( z > 0 and k > 1 ) {
			sum += arr[ pos ] + arr[ pos-1 ];
			--z;
			k -= 2;
		}

		if( z > 0 ) {
			if( k == 1 )
			{
				if( pos < n-1 )
					sum += max( arr[ pos-1 ], arr[ pos+1 ] );
				else
					sum += arr[ pos-1 ];	
			}
		}
		else {
			lim = min( pos+k, (ll)n-1 );
			for (int i = pos+1; i <= lim; ++i)
				sum += arr[ i ];
		}

		cout << sum << endl;
	}
	return 0;
}