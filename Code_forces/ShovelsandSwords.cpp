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

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t, n, m;
	cin >> t;
	while( t-- )
	{
		cin >> n >> m;

		if( n > m )
			swap( n, m );

		ll ans = 0;

		ans += min( m-n, n );
		n -= ans;
		m -= 2*ans;

		ll aux = min(n,m) / 3 * 2;
		n -= (aux / 2) * 3;
		m -= (aux / 2) * 3;

		ans += aux;
		if( n > m )
			swap( n, m );

		while( n >= 1 && m >=2 )
		{
			ans++;

			n--;
			m-=2;

			if ( n > m )
				swap( n, m );
		}
		
		cout << ans << endl;

	}

	return 0;
}
