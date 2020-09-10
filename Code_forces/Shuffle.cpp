#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
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

struct intervalo
{
	ll l, r;

	intervalo( ll a, ll b ): l(a), r(b) {}

	void merge( ll a, ll b )
	{
		if ( a > r || b < l )
			return;

		r = max( b, r );
		l = min( l, a );
	}

	ll size(){
		return (r-l+1);
	}
};

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t, n, x, m, a, b;
	cin >> t;

	while( t-- )
	{
		cin >> n >> x >> m;
		intervalo ans(x,x);

		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			ans.merge( a, b );
		}

		cout << ans.size() << endl;
	}

	return 0;
}
