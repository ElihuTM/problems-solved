#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

ll f( ll n )
{
	int len = sqrt( n );
	for (int i = 2; i <= len; ++i)
		if( n%i == 0 )
			return i;

	return n;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t, n, k, min_div;
	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		min_div = f(n); --k;
		n += min_div;
		n += 2*k;

		cout << n << endl;

	}

	return 0;
}
