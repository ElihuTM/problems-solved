#include <bits/stdc++.h>
#define ff first
#define ss second
#define l(p) (p<<1)
#define r(p) ((p<<1)+1)
#define mid(i,j) ((i+j)>>1)
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

pii nil(mod, mod);

struct segment
{
	vi a;
	vi b;
	int n;
	vpii cambios;

	segment( vi x, vi y )
	{
		n = x.size();
		a = x;
		b 	= y;
		cambios = vpii( 6*n, nil );
	}

	void propagar( int p, int i, int j)
	{
		if( cambios[ p ] == nil )
			return;

		if( i != j )
		{
			cambios[ l(p) ].ff = cambios[ p ].ff;
			cambios[ l(p) ].ss = mid( cambios[ p ].ff, cambios[ p ].ss );
			cambios[ r(p) ].ff = mid( cambios[ p ].ff, cambios[ p ].ss )+1;
			cambios[ r(p) ].ss = cambios[ p ].ss;
		}
		else
			b[ i ] = a[ cambios[ p ].ff ];

		cambios[ p ] = nil;
	}

	void update( int p, int i, int j, int l, int r, int ul, int ur )
	{
		propagar( p, i, j );

		if( l > j || r < i )
			return;

		if( l <= i && j <= r )
		{
			int auxl = i-l;
			int auxr = r-j;

			cambios[ p ] = make_pair( ul + auxl, ur - auxr );
			propagar( p, i, j );
			return;
		}

		update( l(p),   i, mid(i,j), l, r, ul, ur );
		update( r(p), mid(i,j)+1, j, l, r, ul, ur );
	}

	int query( int p, int i, int j, int x )
	{
		if( x > j || x < i )
			return 0;

		propagar( p, i, j );

		if( x == i && x == j )
			return b[ i ];

		int w = query( l(p), i, mid(i,j) ,  x);
		int q = query( r(p), mid(i,j)+1, j, x);
		return w + q;
	}

	void update( int y, int x, int k ) {
		update( 1, 0, n-1, x, x+k-1, y, y+k-1 );
	}

	int query( int x ) {
		return query( 1, 0, n-1, x );
	}
};

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n, q, op, x, y, k;
	cin >> n >> q;

	vi a( n );
	vi b( n );

	for (int i = 0; i < n; ++i)
		cin >> a[ i ];

	for (int i = 0; i < n; ++i)
		cin >> b[ i ];
	
	segment tree( a, b );

	while( q-- )
	{
		cin >> op;
		if( op == 1 ){
			cin >> x >> y >> k;
			tree.update( x-1, y-1, k );
		}
		else {
			cin >> x;
			cout << tree.query( x-1 ) << endl;
		}
	}
	return 0;
}