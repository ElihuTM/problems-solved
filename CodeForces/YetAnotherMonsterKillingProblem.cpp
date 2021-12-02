#include <bits/stdc++.h>
#define ff first
#define ss second
#define l(p) (p<<1)
#define r(p) ((p<<1)+1)
#define mid(i,j) ((i+j)>>1)
#define maxn 100000

using namespace std;
typedef pair <int,int> pii;
typedef vector<int> vi;

struct Segment
{
	vi arbol;
	vi arr;

	Segment( vector<pii> v )
	{
		arbol = vi( 6*v.size() );
		arr = vi( v.size() );

		for (int i = 0; i < v.size(); ++i)
			arr[ i ] = v[ i ].ss;
	}

	void _build( int p, int i, int j )
	{
		if ( i == j )
		{
			arbol[ p ] = arr[ i ];
			return;
		}

		_build( l(p), i, mid(i,j) );
		_build( r(p), mid(i,j)+1, j );
		arbol[ p ] = max( arbol[ l(p) ], arbol[ r(p) ] );
	}

	int _query( int p, int i, int j, int a, int b )
	{
		if( a <= i && b >= j )
			return arbol[ p ];

		if( a > j || b < i )
			return -1;

		int izq = _query( l(p), i, mid(i,j), a, b );
		int der = _query( r(p), mid(i,j)+1, j, a, b );

		return max( izq, der );
	}

	void build() {
		_build( 1, 0, arr.size()-1 );
	}

	int query( int a, int b ) {
		return _query( 1, 0, arr.size()-1, a, b );
	}
};

vi mons;
vector<pii> hero;

int l_b( int i, int j, int value )
{
	int m;

	while( j-i > 1 )
	{
		m = i + (j-i)/2;
		if ( hero[ m ].ff >= value )
			j = m;
		else
			i = m;
	}
	return j;
}

int main()
{
	int t, m, n, pos, maxi;

	cin >> t;
	while( t-- )
	{
		cin >> m; mons.resize( m );
		for (int i = 0; i < m; ++i)
			cin >> mons[ i ];

		cin >> n; hero.resize( n );
		for (int i = 0; i < n; ++i)
			cin >> hero[ i ].ff >> hero[ i ].ss;

		sort( hero.begin(), hero.end() );
		Segment seg( hero ); seg.build();

		bool is_pos = true;
		for (int i = 0; i < m; ++i)
			if( mons[ i ] > hero.back().ff )
			{
				is_pos = false;
				break;
			}

		if ( !is_pos )
			cout << "-1\n";
		else
		{
			int day = 1, ans = 0, value = 0;
			for (int i = 0; i < m; ++i)
			{
				value = max( value, mons[ i ] );

				pos = l_b( -1, hero.size()-1, value );
				//cout << "low " << pos << endl;
				maxi = seg.query( pos, hero.size()-1 );
				//cout << "maxi  " << maxi << endl;
				
				if ( maxi >= day )
				{
					++day;
				}
				else
				{
					++ans; --i;
					value = 0;
					day = 1;
				}
			}
			cout << ans+1 << '\n';
		}
	}
	return 0;	
}