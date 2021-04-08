#include <bits/stdc++.h>
#define maxn 200005

using namespace std;
typedef long long ll;

struct nd
{
	ll rel, jiren, otr;

	bool operator < ( const nd &p ) const
	{ return rel > p.rel; }
};

nd m_n( ll a, ll b, ll c ) {
	nd aux; aux.rel = a; aux.jiren = b; aux.otr = c;
	return aux;
}

ll mat[ 3 ][ maxn ];
nd ans[ maxn ];

int main()
{
	ll n, k, x;
	ll minimo = 0;

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		minimo += x;
	}

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mat[ i ][ j ];

	for (int i = 0; i < n; ++i)
	{
		ll maxi = max( mat[ 1 ][ i ], mat[ 2 ][ i ] );
		ans[ i ] = m_n( mat[ 0 ][ i ]-maxi, mat[ 0 ][ i ], maxi );
	}

	sort( ans, ans+n );

	ll acum = 0;
	for (int i = 0; i < k; ++i)
		acum += ans[ i ].jiren;

	for (int i = k; i < n; ++i)
		acum += ans[ i ].otr;

	if ( acum < minimo )
		cout << "Don't do it, buddy\n";
	else
		cout << acum << '\n';

	return 0;
}