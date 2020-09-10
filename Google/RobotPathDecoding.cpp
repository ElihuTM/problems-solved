#include <bits/stdc++.h>
#define mod 1000000000
#define MOD( x ) (((x % mod ) + mod ) % mod )

using namespace std;
typedef long long ll;

struct muv
{
	ll N; ll S;
	ll W; ll E;

	muv() : N( 0 ), S( 0 ), W( 0 ), E( 0 ) { }
	muv( ll n, ll s, ll e, ll w )
	{
		N = MOD( n ); S = MOD( s );
		E = MOD( e ); W = MOD( w );
	}

	void add( char X )
	{
		switch( X )
		{
			case( 'N' ): N++; MOD( N ); break;
			case( 'S' ): S++; MOD( S ); break;
			case( 'E' ): E++; MOD( E ); break;
			case( 'W' ): W++; MOD( W ); break;
		}
	}

	void act()
	{
		N = MOD( N );
		S = MOD( S );
		E = MOD( E );
		W = MOD( W );
	}

	muv operator * ( ll x ) {
		return muv( N*x, S*x, E*x, W*x );
	}

	void operator += ( muv p ){
		N = MOD( N + p.N );
		S = MOD( S + p.S );
		E = MOD( E + p.E );
		W = MOD( W + p.W );
	}

	void imp()
	{
		cout << "-------------------\n";
		cout << "N: " << N << '\n';
		cout << "S: " << S << '\n';
		cout << "E: " << E << '\n';
		cout << "W: " << W << '\n';	
		cout << "-------------------\n";
	}
};

string cad;

bool is_cord( char x )
{
	if ( x == 'N' || x == 'S' )
		return true;

	if ( x == 'E' || x == 'W' )
		return true;

	return false;
}

muv comp( int &pos )
{
	muv current;
	while( pos < cad.size() )
	{
		if ( cad[ pos ] == ')')
		{
			++pos;
			current.act();
			return current;
		}

		if ( is_cord( cad[ pos ] ) )
		{
			//cout << cad[ pos ];
			current.add( cad[ pos ] );
			++pos;
		}
		else
		{
			int x = cad[ pos ] - '0';
			pos += 2;
			current += (comp( pos ) * x);
			current.act();
		}
	}

	current.act();
	return current;
}

int main()
{
	int t;

	cin >> t;
	for (int c = 1; c <= t; ++c)
	{
		cin >> cad;

		int pos = 0;
		muv mover = comp( pos );

		//mover.imp();

		ll x = 0, y = 0;
		x = MOD( x + mover.E );
		x = MOD( x - mover.W );
		y = MOD( y - mover.N );
		y = MOD( y + mover.S );

		cout << "Case #" << c << ": " << x+1 << ' ' << y+1 << '\n';
	}
	return 0;
}