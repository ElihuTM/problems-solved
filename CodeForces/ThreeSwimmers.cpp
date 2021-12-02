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

ll getValue (ll p, ll x) {
	return (p % x == 0 ? 0 : x - (p % x));
}

ll getAnswer(ll p, ll a, ll b, ll c) {
	ll ans = getValue(p, a);
	ans = min(ans, getValue(p, b));
	ans = min(ans, getValue(p, c));

	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int t;
	ll p, a, b, c;
	cin >> t;
	while(t--) {
		cin >> p >> a >> b >> c;
		cout << getAnswer(p,a,b,c) << endl;
	}

	return 0;
}
