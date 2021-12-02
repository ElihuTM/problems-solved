#include <bits/stdc++.h>
#define ff first
#define ss second
#define inf 1000000007
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
	
	int t, n;
	vi arr;

	cin >> t;
	while( t-- ) {
		cin >> n;

		arr.resize( n );
		for (int i = 0; i < n; ++i) {
			cin >> arr[ i ];
		}

		ll maximum = 0,
			minimum = inf,
			difference = 0,
			middle_point,
			new_difference;

		for (int i = 0; i < n-1; ++i) {
			if( arr[ i ] != -1 ) {
				if( arr[ i+1 ] == -1 ) {
					maximum = max( maximum, arr[ i ] );
					minimum = min( minimum, arr[ i ] );
				}
				else {
					difference = max( difference, abs( arr[ i ] - arr[ i+1 ] ));
				}
			}
			else {
				if( arr[ i+1 ] != -1 ) {
					maximum = max( maximum, arr[ i+1 ] );
					minimum = min( minimum, arr[ i+1 ] );
				}
			}
		}

		middle_point = (maximum + minimum) >> 1;
		new_difference = max( maximum - middle_point, middle_point - minimum );
	
		cout << max( difference, new_difference ) << " " << middle_point << endl;
	}

	return 0;
}