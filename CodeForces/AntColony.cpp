#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
#define md(x) (((x%mod) + mod) % mod)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define l(p) (p<<1)
#define r(p) ((p<<1)+1)
#define mid(i,j) ((i+j)>>1)
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

struct node
{
	int gcd;
	int min_value;
	int reps;

	node() {
		gcd = min_value = reps = 0;
	}

	node( int a, int b, int c ) : gcd( a ), min_value( b ), reps( c ) {}
};

struct segment
{
	vector< node > arbol;
	int length;
	vi arr;

	segment ( vi &a )
	{
		length = a.size();
		arr = a;
		arbol.resize( 6*length );
	}

	void build( int p, int i, int j )
	{
		if( i == j )
		{
			arbol[ p ] = node( arr[ i ], arr[ i ], 1 );
			return;
		}

		build( l(p),  i, mid(i,j) );
		build( r(p), mid(i,j)+1, j);

		node izq = arbol[ l( p ) ];
		node der = arbol[ r( p ) ];

		arbol[ p ].min_value = min( izq.min_value, der.min_value );
		arbol[ p ].gcd = __gcd( izq.gcd, der.gcd );

		if( izq.min_value == der.min_value )
			arbol[ p ].reps = izq.reps + der.reps;
		else if( arbol[ p ].min_value == izq.min_value )
			arbol[ p ].reps = izq.reps;
		else
			arbol[ p ].reps = der.reps;
	}

	void build() {
		build( 1, 0, length-1 );
	}

	node query( int p, int i, int j, int a, int b ){

		if( a > j || b < i )
			return node( 1, -2, 0 );

		if( a <= i && j <= b )
			return arbol[ p ];

		node izq = query( l(p), i, mid( i,j ), a, b );
		node der = query( r(p), mid( i,j )+1, j, a, b );

		if( izq.min_value == -2 || der.min_value == -2 )
			return (izq.min_value == -2 ? der : izq);

		node aux;
		aux.min_value = min( izq.min_value, der.min_value );
		aux.gcd = __gcd( izq.gcd, der.gcd );

		if( izq.min_value == der.min_value )
			aux.reps = izq.reps + der.reps;
		else if( aux.min_value == izq.min_value )
			aux.reps = izq.reps;
		else
			aux.reps = der.reps;

		return aux;
	}

	int query( int a, int b ) {
		node aux = query( 1, 0, length-1, a, b );

		if( aux.gcd % aux.min_value == 0)
			return ( b - a - aux.reps + 1);
		else
			return ( b - a + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n, a, b;
	cin >> n;

	vi arr( n );
	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	segment tree( arr );
	tree.build();

	int q;
	cin >> q;

	while( q-- )
	{
		cin >> a >> b;
		cout << tree.query( a-1, b-1 ) << endl;
	}
	return 0;
}