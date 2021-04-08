#include <bits/stdc++.h>
#define maxn 1003
#define mod 998244353

using namespace std;
typedef long long ll;

ll memo[ maxn ][ maxn ][ 4 ][ 4 ];
int mat[ maxn ][ maxn ];

bool _up[ 4 ][ 4 ];
bool _left[ 4 ][ 4 ];
int n, m;

int ante( int x, int y )
{
	if( x == 0 )
		return 0;
	
	return mat[ x-1 ][ y ];
}

bool ispos( int x, int y, int pos, int ant )
{
	if( x == 0 )
		return _left[ pos ][ ant ];
	
	if( y == 0 )
		return _up[ pos ][ ante(x,y) ];

	return _left[ pos ][ ant ] & _up[ pos ][ ante( x, y) ];
}


ll dp( int x, int y, int ant )
{
	if( x == n )
		return 1;

	if( y == m )
		return dp( x+1, 0, 0 );

	if( ~memo[ x ][ y ][ ant ][ ante( x, y ) ] )
		return memo[ x ][ y ][ ant ][ ante( x, y ) ];
	
	ll ans = 0;
	for( int i = 0; i < 4; ++i )
	{
		if( ispos( x, y, i, ant ) )
		{
			mat[ x ][ y ] = i;
			ans += dp( x, y+1, i );
			ans %= mod;
		}
	}

	return memo[ x ][ y ][ ant ][ ante(x,y) ] = ans;

}

int main()
{
	memset( memo, -1, sizeof memo );
	cin >> n >> m;
	
	for( int i = 0; i < 4; ++i )
		for( int j = 0; j < 4; ++j )
		{
			if( (i < 2 && j < 2) || (i > 1 && j > 1) )
				_up[ i ][ j ] = true;
			else
				_up[ i ][ j ] = false;

			_left [ i ][ j ] = false;				
		}

	_left [ 0 ][ 0 ] = true;				
	_left [ 0 ][ 3 ] = true;				
	_left [ 1 ][ 1 ] = true;				
	_left [ 1 ][ 2 ] = true;				
	_left [ 2 ][ 1 ] = true;				
	_left [ 2 ][ 2 ] = true;				
	_left [ 3 ][ 0 ] = true;				
	_left [ 3 ][ 3 ] = true;

	ll ans = 0;
	for( int i = 0; i < 4; ++i )
	{
		mat[ 0 ][ 0 ] = i;
		ans += dp( 0, 1, i );
		ans %= mod;
	}
	
	cout << ans << '\n';
	return 0;
}
