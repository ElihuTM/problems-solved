#include <bits/stdc++.h>
#define maxn 2017

using namespace std;

short memo[ maxn ][ maxn ];
short necesita[ maxn ][ 10 ];
short number[ 10 ];
short arr[ maxn ];

string ans;
int n;

inline short decode( string cad )
{
	int ans = 0;
	for (int i = 0; i < cad.size(); ++i)
		ans = ans*2 + cad[ i ] - '0';
	
	return ans;
}

inline short f_necesita( int a, int b )
{
	short ans = 0;

	while( a || b )
	{
		if( b&1 )
		{
			if ( !(a&1) )
				++ans;
		}
		else
		{
			if ( a&1 )
				return -1;
		}

		a >>= 1;
		b >>= 1;
	}

	return ans;
}

bool dp( int pos, int k )
{
	if ( pos == n )
	{
		if ( k == 0 )
		{
			cout << ans << '\n';
			return true;
		}

		return false;
	}

	if( k < 0 )
		return false;

	if ( ~memo[ pos ][ k ] )
		return memo[ pos ][ k ];

	short nec;
	for (int i = 9; i >= 0; --i)
	{
		nec = necesita[ pos ][ i ];
		if ( nec == -1 )
			continue;

		ans[ pos ] = '0' + i ;
		if ( dp( pos+1, k-nec ) )
			return memo[ pos ][ k ] = true;
	}

	return memo[ pos ][ k ] = false; 
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int k;
	string cad;

	number[ 0 ] = decode( "1110111" );
	number[ 1 ] = decode( "0010010" );
	number[ 2 ] = decode( "1011101" );
	number[ 3 ] = decode( "1011011" );
	number[ 4 ] = decode( "0111010" );
	number[ 5 ] = decode( "1101011" );
	number[ 6 ] = decode( "1101111" );
	number[ 7 ] = decode( "1010010" );
	number[ 8 ] = decode( "1111111" );
	number[ 9 ] = decode( "1111011" );
	memset( memo, -1, sizeof( memo ) );

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> cad;
		arr[ i ] = decode( cad );
		ans.push_back( '9' );
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 10; ++j)
			necesita[ i ][ j ] = f_necesita( arr[ i ], number[ j ] );

	if ( !dp( 0, k ) ) 
		cout << "-1\n";

	return 0;
}