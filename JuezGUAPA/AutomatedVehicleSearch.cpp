#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int car[ maxn ];
int n, query, raiz;

int busq( int k )
{
	int pos = -1, it = 0;

	while( pos < n && car[ pos ] < k )
	{
		pos += raiz;
		++it;
	}

	if ( car[ pos ] == k)
		return it;

	pos -= raiz;
	++it;

	while( car[ pos ] < k )
	{
		++pos;
		++it;
	}

	return it;
}

int main()
{
	int q;
	set <int> bd;

	cin >> n >> query;
	raiz = floor( sqrt( n ) );

	for (int i = 0; i < n; ++i)
	{
		cin >> car[ i ];
		bd.insert( car[ i ] );
	}

	while( query-- )
	{
		cin >> q;

		if ( bd.find( q ) == bd.end() )
			cout << -1 << '\n';
		else
			cout << busq( q ) << '\n';
	}
	return 0;
}