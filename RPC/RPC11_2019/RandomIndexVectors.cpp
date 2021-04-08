#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll _abs( ll n )
{
	return n < 0 ? -n : n;
}

void suma( vi a, vi b )
{
	vi ans;
	vi mult;

	int l = a.size();
	int r = b.size();

	int i = 0, j = 0;

	while( i < l && j < r )
	{
		if( _abs( a[ i ] ) < _abs( b[ j ] ) )
		{
			ans.push_back( a[ i ] );
			++i;
		}
		else if( _abs( a[ i ] ) > _abs( b[ j ] ) )
		{
			ans.push_back( b[ j ] );
			++j;
		}
		else
		{
			mult.push_back( a[ i ] == b[ j ] ? _abs( a[ i ]) : -_abs( a[ i ] ) );
			if( a[ i ] == b[ j ] )
				ans.push_back( a[ i ] );
			++i;
			++j;
		}
	}
	
	while( i < l )
	{
		ans.push_back( a[ i ] );
		++i;
	}

	while( j < r )
	{
		ans.push_back( b[ j ] );
		++j;
	}

	l = ans.size();
	cout << l;
	for( int i = 0; i < l; ++i )
		cout << " " << ans[ i ];
	cout << '\n';
	
	l = mult.size();
	cout << l;
	for( int i = 0; i < l; ++i )
		cout << " " << mult[ i ];
	cout << '\n';
}

int u_p( vi a, int i, int j, ll value )
{
	int m;

	if( value >= a.back() )
		return a.size();

	while( j-i > 1 )
	{
		m = i + (j-i)/2;
		if( _abs(a[ m ]) > value )
			j = m;
		else
			i = m;
	}

	return j;
}

void imp( vi a, ll k, ll n )
{
	int len = a.size();
	int i = u_p( a, -1, len-1, k );
	//cout << "up = " << i << endl;
	cout << len;
	while( i < len )
	{
		int sig = a[ i ] < 0 ? -1 : 1;
		cout << " " << (_abs(a[ i ]) - k)*sig;
		++i;
	}

	i = 0;
	while( _abs(a[i]) <= k )
	{
		int sig = a[ i ] < 0 ? -1 : 1;
		cout << " " << (_abs(a[ i ])+n-k)*sig;
		++i;
	}
	cout << '\n';
}

int main()
{
	ll n,k,_a,c;
	cin >> n >> k;
	
	cin >> _a;
	vi a( _a );

	for( int i =0; i < _a; ++i )
		cin >> a[ i ];

	cin >> _a;
	vi b( _a );

	for( int i = 0; i < _a; ++i )
		cin >> b[ i ];
	
	suma( a, b );
	imp( a, k, n);
	imp( b, k, n);
	return 0;
}
