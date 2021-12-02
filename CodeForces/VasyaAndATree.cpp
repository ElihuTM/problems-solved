#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 300005
#define md(x) (((x%mod) + mod) % mod)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'
#define l(p) (p<<1)
#define r(p) ((p<<1)+1)
#define mid(i,j) ((i+j)>>1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

vvi lista;
vi euler_tour;
vi first_appear;
vi last_appear;
vi dist;

struct segment
{
	int length;
	vi arr;
	vector<pii> cambios;

	segment( int n )
	{
		length = n;
		arr.resize( n );
		cambios.resize( 6*n );
	}

	void propagar( int p, int i, int j )
	{
		if ( cambios[ p ])
		{
			/* code */
		}
	}

	void update( int p, int i, int j, int a, int b, pii value )
	{
		propagar( p, i, j );
		
		if( a > j || b < i )
			return;

		if( a <= i && j <= b )
		{
			cambios[ p ] = value;
			propagar( p, i, j );
			return;
		}

		update( l(p),   i, mid(i,j), a, b, value );
		update( r(p), mid(i,j)+1, j, a, b, value );
	}

	void update( int a, int b, pii value ) {
		update( 1, 0, length-1, a, b, value );
	}
};

void build_euler_tour( int u, int father, int deep )
{
	euler_tour.push_back( u );
	dist.push_back( deep );

	for (int i = 0; i < lista[ u ].size(); ++i)
	{
		int v = lista[ u ][ i ];
		if( v != father )
		{
			build_euler_tour( v, u, deep+1 );
			euler_tour.push_back( u );
			dist.push_back( deep );
		}
	}
}

fill_appears(){
	for (int i = 0; i < euler_tour.size(); ++i) {
		int u = euler_tour[ i ];
		if( first_appear[ u ] == -1 )
			first_appear[ u ] = i;
		last_appear[ u ] = i;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n, a, b;

	cin >> n;
	lista.resize( n+1 );
	first_appear.resize( n+1, -1 );
	last_appear.resize( n+1 );

	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b;
		lista[ a ].push_back( b );
		lista[ b ].push_back( a );
	}

	build_euler_tour( 1, 0, 1 );
	fill_appears();
	
	int querys;
	cin >> querys;
	while( querys-- )
	{
		cin
	}
	for ( auto c: euler_tour)
		cout << " " << c;
	cout << endl;

	for( auto c: dist )
		cout << " " << c;
	cout << endl;
	
	for (int i = 0; i < n+1; ++i)
	{
		cout << " " << first_appear[ i ];
	}
	cout << endl;
	for (int i = 0; i < n+1; ++i)
	{
		cout << " " << last_appear[ i ];
	}

	return 0;
}