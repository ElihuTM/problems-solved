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
	
	int n;
	cin >> n;

	vpii arr( n );
	for (int i = 0; i < n; ++i)
		cin >> arr[ i ].ss >> arr[ i ].ff;
	
	sort( arr.rbegin(), arr.rend() );
	ll b = 1, ans = 0, pos = 0;

	while ( b > 0 and pos < n ) {
		--b;
		ans += arr[ pos ].ss;
		b += arr[ pos ].ff;
		++pos;
	}

	cout << ans << endl;
	return 0;
}