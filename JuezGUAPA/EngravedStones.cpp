#include <bits/stdc++.h>
#define mod1 1000000007
#define mod2 1000000003
#define b1 103
#define b2 101
#define ff first
#define ss second
#define forn(i,n) for(int i=0;i<n;++i)
#define maxn 100005

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;

int arr[ 2 ][ maxn ];
ll b1a[ maxn ];
ll b2a[ maxn ];
int n;

bool is_pos( int k )
{
	set <pii> dic;

	pii aux( 0 ,0 );
	forn( i, k )
	{
		aux.ff = (((aux.ff * b1) % mod1) + arr[ 0 ][ i ] ) % mod1;
		aux.ss = (((aux.ss * b2) % mod2) + arr[ 0 ][ i ] ) % mod2;
	}

	dic.insert( aux );
	for( int i = k; i < n; ++i )
	{
		aux.ff = (aux.ff - ((arr[ 0 ][ i-k ]*b1a[ k-1 ] ) % mod1 ) + mod1) % mod1;
		aux.ss = (aux.ss - ((arr[ 0 ][ i-k ]*b2a[ k-1 ] ) % mod2 ) + mod2) % mod2;
		aux.ff = (((aux.ff * b1) % mod1) + arr[ 0 ][ i ] ) % mod1;
		aux.ss = (((aux.ss * b2) % mod2) + arr[ 0 ][ i ] ) % mod2;
		dic.insert( aux );
	}
	
	aux = make_pair( 0, 0 );
	forn(i, k)
	{
		aux.ff = (((aux.ff * b1) % mod1) + arr[ 1 ][ i ] ) % mod1;
		aux.ss = (((aux.ss * b2) % mod2) + arr[ 1 ][ i ] ) % mod2;
	}

	if( dic.find( aux ) != dic.end() )
		return true;
	
	for( int i = k; i < n; ++i )
	{
		aux.ff = (aux.ff - ((arr[ 1 ][ i-k ]*b1a[ k-1 ] ) % mod1 )+ mod1) % mod1;
		aux.ss = (aux.ss - ((arr[ 1 ][ i-k ]*b2a[ k-1 ] ) % mod2 )+ mod2) % mod2;
		aux.ff = (((aux.ff * b1) % mod1) + arr[ 1 ][ i ] ) % mod1;
		aux.ss = (((aux.ss * b2) % mod2) + arr[ 1 ][ i ] ) % mod2;

		if( dic.find( aux ) != dic.end() )
			return true;
	}
	return false;
}

int l_w( int i, int j )
{
	int m;
	while( j-i > 1 )
	{
		m = i + (j-i)/2;

		if( !is_pos( m ) )
		{
			//cout << "with " << m << " is not possible\n";
			j = m;
		}
		else
		{
			//cout << "with " << m << " is possible\n";
			i = m;
		}
	}

	return i;
}

int main()
{
	b1a[ 0 ] = b2a[ 0 ] = 1;
	for( int i = 1; i < maxn; ++i )
	{
		b1a[ i ] = (b1a[ i-1 ] * b1 ) % mod1;
		b2a[ i ] = (b2a[ i-1 ] * b2 ) % mod2;
	}
	cin >> n;

	forn( i, 2 )
		forn( j, n )
			cin >> arr[ i ][ j ];

	cout << l_w( 1, n+1 ) << endl;

	return 0;
}
