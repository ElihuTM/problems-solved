#include <bits/stdc++.h>
#define maxn 2003

using namespace std;
typedef map <int, int> mii;

int n;
int arr[ maxn ];

bool is_pos( int m, mii x, int y )
{
	for( int i = 0; i < m; ++i )
	{
		--x[ arr[ i ] ];
		if( x[ arr[ i ] ] >= 1 )
			--y;
	}

	if( y == 0 ) return true;

	for( int i = m; i < n; ++i )
	{
		--x[ arr[ i ] ];
		if( x[ arr[ i ] ] >= 1 )
			--y;

		++x[ arr[ i-m ] ];
		if( x[ arr[ i-m ] ] > 1 )
			++y;

		if( y == 0 ) return true; 
	}

	return false;
}

int l_b( int l, int r, mii reps, int x )
{
	int m;

	while( r-l > 1 )
	{
		m = l + (r-l)/2;
		if( is_pos( m, reps, x ) )
			r = m;
		else
			l = m;
	}

	return r;
}

int main()
{
	int r = 0;
	mii reps;
	cin >> n;
	
	for( int i = 0; i < n; ++i )
	{
		cin >> arr[ i ];
		++reps[ arr[ i ] ];
		if( reps[ arr[ i ] ] > 1 )
			++r;
	}
	if( r == 0 )
		cout << "0\n";
	else
		cout << l_b( 0, n-1, reps, r ) << '\n';

	return 0;
}
