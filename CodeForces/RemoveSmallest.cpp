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

bool is_possible( vi &arr ) {
	for (int i = 0; i < arr.size()-1; ++i) {
		if( arr[ i+1 ] - arr[ i ] > 1 )
			return false;
	}
	return true;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int t, n;

	cin >> t;
	while( t-- ) {
		cin >> n;

		vi arr( n );
		for (int i = 0; i < n; ++i) {
			cin >> arr[ i ];
		}

		sort( all(arr) );

		if ( is_possible( arr ) )
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}

	return 0;
}