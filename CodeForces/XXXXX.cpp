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

vi arr;
ll n, x;

bool is_pos( int m )
{
	for (int i = m; i < n; ++i)
		if ( (arr[ i ] - arr[ i-m ] + x) % x != 0) 
			return true;
	return false;
}

ll u_b( ll i, ll j )
{
	if( arr.back() % x != 0)
		return n;
	/*

	ll m;
	while( j-i > 1 )
	{
		m = i + (j-i)/2;
		if ( is_pos( m ) )
			i = m;
		else
			j = m;
	}*/
	int m = n-1;
	while( !is_pos(m) )
		--m;

	return m;
}

bool all_multiples()
{
	for (int i = 0; i < n; ++i)
		if( arr[ i ] % x != 0 )
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	ll t, ans;
	
	cin >> t;
	while( t-- )
	{
		cin >> n >> x;
		arr.resize(n);

		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		if ( all_multiples() )
			ans = -1;
		else
		{
			for (int i = 1; i < n; ++i)
			{
				arr[ i ] += arr[ i-1 ];
				arr[ i ] %= x;
			}

			ans = u_b(0, n);
		}
		cout << ans << endl;
	}

	return 0;
}
