#include <bits/stdc++.h>
#define maxn 10000005
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef map<int, int> mii;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int criba[ maxn ];

void llenar()
{
	for (int i = 0; i < maxn; ++i)
		criba[ i ] = i;

	criba[ 0 ] = 1;
	for (int i = 4; i < maxn; i+=2 )
		criba[ i ] = 2;

	ll lim = sqrt( maxn );
	for (ll i = 3; i <= lim; i+=2 )
		if ( criba[ i ] == i )
			for ( ll j=i*i; j < maxn; j+=i )
				if( criba[ j ] == j )
					criba[ j ] = i;
}

void add_to_map( mii &m, int a )
{
	while( a > 1 )
	{
		m[ criba[ a ] ]++;
		a /= criba[ a ];
	}
}

vii get_factors( int n )
{
	vii ans;
	pii aux( criba[ n ], 0 );

	while( n>1 )
	{
		if ( criba[ n ] == aux.ff )
			aux.ss++;
		else
		{
			ans.push_back( aux );
			aux = make_pair( criba[ n ], 1 );
		}

		n /= criba[ n ];
	}
	ans.push_back( aux );

	return ans;
}

int f_p( int e, int x )
{
	int ans = 1;
	while( x )
	{
		if( x&1 )
			ans *= e;

		e *= e;
		x >>= 1;
	}
	return ans;
}

void fun( vi &a, mii &gcd, mii &mp )
{
	map<int, int>::iterator it;
	ll ans;
	vector<pii> v;

	for( auto c: gcd )
		mp[ c.ff ] -= c.ss;

	for (int i = 0; i < a.size(); ++i)
	{
		ans = 1;
		v = get_factors( a[ i ] );
		for (int i = 0; i < v.size(); ++i)
		{
			if ( mp[ v[ i ].ff ] >= v[ i ].ss )
			{
				ans *= f_p( v[ i ].ff, v[ i ].ss );
				mp[ v[ i ].ff ] -= v[ i ].ss;
			}
			else
			{
				ans *= f_p( v[ i ].ff, mp[ v[ i ].ff ] );
				mp[ v[ i ].ff ] = 0;
			}
		}

		cout << ans;
		if ( i < a.size()-1 )
			cout << " ";
	}
	cout << '\n';
}

int main()
{
	llenar();
	mii up;
	mii down;
	mii gcd;

	int n, m;

	cin >> n >> m;
	vi a( n );
	vi b( m );

	for (int i = 0; i < n; ++i)
	{
		cin >> a[ i ];
		add_to_map( up, a[ i ] );
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> b[ i ];
		add_to_map( down, b[ i ] );
	}

	for( auto c : up )
	{
		gcd[ c.ff ] = min( c.ss, down[ c.ff ] );
		if ( gcd[ c.ff ] == 0)	gcd.erase( c.ff );
	}

	for( auto c : down )
	{
		gcd[ c.ff ] = min( c.ss, up[ c.ff ] );
		if ( gcd[ c.ff ] == 0)	gcd.erase( c.ff );
	}

	cout << n << " " << m << '\n';
	
	fun( a, gcd, up );
	fun( b, gcd, down );
	return 0;
}