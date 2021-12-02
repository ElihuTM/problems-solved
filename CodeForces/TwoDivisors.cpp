#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 10000005
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

vi ans[ 2 ];
int criba[ maxn ];

void llenar()
{
	for (int i = 0; i < maxn; ++i)
		criba[ i ] = i;
	criba[ 0 ] = 1;

	ll lim = sqrt(maxn);
	for ( int i = 4; i < maxn; i+=2 )
		criba[ i ] = 2;

	for (ll i = 3; i < maxn; i+=2)
		if ( criba[ i ] == i )
			for (ll j = i*i; j < maxn; j+=i )
				if (criba[ j ] > i )
					criba[ j ] = i;
}

void calc( ll n, ll pos )
{
	ll cop = n;
	set<int> p;

	while( cop != 1 )
	{
		p.insert( criba[ cop ] );
		cop /= criba[ cop ];
	}

	if ( p.size() == 1 )
	{
		ans[ 0 ][ pos ] = ans[ 1 ][ pos ] = -1;
		return;
	}

	vector< ll > aux;
	for ( auto c: p )
		aux.p_b( c );

	for (int i = 0; i<aux.size(); ++i)
	{
		for( int j=0; j<aux.size(); ++j )
		{
			ll p1 = aux[ i ];
			ll p2 = aux[ j ];

			if ( __gcd(p1 + p2, n) == 1 )
			{
				ans[ 0 ][ pos ] = p1;
				ans[ 1 ][ pos ] = p2;
				return;
			}
		}
	}

	ans[ 0 ][ pos ] = ans[ 1 ][ pos ] = -1;
}
int main()
{
	llenar();
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, a;

	cin >> n;
	ans[ 0 ].resize( n );
	ans[ 1 ].resize( n );

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		calc( a, i );
	}

	cout << ans[ 0 ][ 0 ];
	for (int i = 1; i < n; ++i)
		cout << ' ' << ans[ 0 ][ i ];
	cout << endl;

	cout << ans[ 1 ][ 0 ];
	for (int i = 1; i < n; ++i)
		cout << ' ' << ans[ 1 ][ i ];
	cout << endl;
	return 0;
}
