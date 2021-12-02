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
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t, n;
	string cad;
	vi contador;
	cin >> t;

	while( t-- ) {
		cin >> cad;
		contador.assign( 10, 0 );
		n = cad.size();

		for (int i = 0; i < n; ++i)
			contador[ cad[ i ] - '0' ]++;

		ll max_reps = 0;
		for (int i = 0; i < 10; ++i) {
		//	cout << " contador " << contador[ i ]<< endl;
			max_reps = max( max_reps, contador[ i ] );
		}

		ll ans = max_reps;
		//cout << "ans: " << ans << endl;

		for (int i = 0; i < 10; ++i)
			for (int j = i+1; j < 10; ++j)
			{
				if( contador[ i ] == 0 or contador[ j ] == 0 ) continue;
				string new_cad;
				for (int k = 0; k < n; ++k ){
					if( cad[ k ] - '0' == i or cad[ k ] - '0' == j ) {
						if( new_cad.empty() or new_cad.back() != cad[ k ] )
							new_cad.push_back( cad[ k ] );
					}
				}

				//cout << new_cad << endl;
				if( new_cad.size()&1 )
					new_cad.pop_back();

				ans = max( ans, (ll)new_cad.size() );
			}

		cout << n - ans << endl;
	}
	return 0;
}