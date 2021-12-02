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
	
	int t, n, x;
	cin >> t;

	while( t-- ) {
		cin >> n;

		vi arr( n+1, 0 );
		vi last( n+1, -1 );

		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			arr[ x ]++;
		}

		sort( arr.rbegin(), arr.rend() );
		ll min_dist = mod, pos = 0, cont = n;

		while( cont ) {

			//for (int i = 0; i < n; ++i)
			//	cout << arr[ i ] << " ";
			//cout << endl;


			for (int i = 0; i < n; ++i)
			{
				if( arr[ i ] == 0 )
					break;

				if( last[ i ] != -1 ) {
					min_dist = min( min_dist, pos-last[ i ]-1 );
					//cout << last[ i ] << " " << pos << endl;
				}

				arr[ i ]--;
				last[ i ] = pos;
				++pos;
				--cont;
			}
		}

		cout << min_dist << endl;
	}

	return 0;
}