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

	cin >> t;
	while( t-- ) {
		cin >> n;

		string ans;

		for (int i = 0; i < (n+3)/4; ++i)
			ans.push_back( '8' );

		for (int i = n-ans.size()-1; i>= 0; --i)
			ans.push_back( '9' );

		for (int i = ans.size()-1; i >= 0 ; --i)
			cout << ans[ i ];
		cout << endl;
	}

	return 0;
}