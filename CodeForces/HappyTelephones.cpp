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
	
	int n, m, x,
		start,
		end,
		interval_start,
		interval_end;
	
	vpii call;
	vpii interval;
	vi ans;

	cin >> n >> m;
	while( n && m ) {
		call.resize( n );
		interval.resize( m );
		ans.assign( m, 0 );

		for (int i = 0; i < n; ++i)
			cin >> x >> x >> call[ i ].ff >> call[ i ].ss;
		
		for (int i = 0; i < m; ++i)
			cin >> interval[ i ].ff >> interval[ i ].ss;

		for (int i = 0; i < n; ++i) {
			start = call[ i ].ff;
			end = call[ i ].ff + call[ i ].ss - 1;

			for (int j = 0; j < m; ++j) {
				interval_start = interval[ j ].ff;
				interval_end = interval[ j ].ff + interval[ j ].ss - 1;

				if( ( interval_start <= start and start <= interval_end ) or
					( interval_start <= end and end <= interval_end ) or
					( start <= interval_start and interval_start <= end ) or
					( start <= interval_end and interval_end <= end ) )
						++ans[ j ];
			}
		}

		for (int i = 0; i < m; ++i)
			cout << ans[ i ] << endl;

		cin >> n >> m;
	}

	return 0;
}