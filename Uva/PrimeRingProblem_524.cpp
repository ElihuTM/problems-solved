#include <bits/stdc++.h>
#define maxn 40

using namespace std;

bitset < maxn > criba;
vector < int > p;
vector < int > ans;
int n;

void c_s( int pos, int mask )
{
	if( pos == n)
	{
		if( criba[ ans.back() + 1 ] )
		{
			cout << ans[ 0 ];
			for( int i = 1; i < ans.size(); ++i )
				cout << " " << ans[ i ];
			cout << '\n';
		}
		return;
	}

	int x;
	for( int i = 0; i < p.size(); ++i )
	{
		x = p[ i ] - ans.back();
		if( x > 0 && x <= n && !(mask&(1<<x)) )
		{
			ans.push_back( x );
			c_s( pos+1, mask|(1<<x) );
			ans.pop_back();
		}
	}
}

int main()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = false;
	for( int i = 2; i < maxn; ++i )
		if( criba[ i ] )
		{
			p.push_back( i );
			for( int j = i*i; j < maxn; j+=i )
				criba[ j ] = false;
		}

	int it = 0;
	ans.push_back( 1 );
	
	cin >> n;
	cout << "Case " << ++it << ":\n";
	c_s( 1, 2 );

	while( cin >> n )
	{
		cout << '\n';
		cout << "Case " << ++it << ":\n";
		c_s( 1, 2 );
	}
	return 0;
}
