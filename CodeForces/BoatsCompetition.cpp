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
	
	int t, n;
	vi arr;

	cin >> t;
	while( t-- ) {
		cin >> n;
		arr.resize( n );

		for (int i = 0; i < n; ++i) {
			cin >> arr[ i ];
		}

		sort( all( arr ));

		int ans = 0;
		for (int i = 1; i <= 2*n; ++i)
		{
			int ini = 0, fin = n-1, cont = 0;

			while( ini < fin ) {
				if( arr[ ini ] + arr[ fin ] == i ) {
					++cont;
					++ini;
					--fin;
				}
				else if( arr[ ini ] + arr[ fin ] < i ) {
					++ini;
				}
				else {
					--fin;
				}
			}

			ans = max( cont, ans );
		}

		cout << ans << endl;
	}

	return 0;
}