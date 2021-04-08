#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

struct ari
{
	int a, b, c;

	bool operator < ( const ari &p )const
	{
		return c < p.c;
	}
};

int padre[ maxn ];

int padrote( int n )
{
	return n == padre[ n ] ? n : padre[ n ] = padrote( padre[ n ] );
}

bool union_find( int a, int b )
{
	int c = padrote( a ), d = padrote( b );

	if ( c == d ) return false;

	if ( rand()&1)
		padre[ c ] = d;
	else
		padre[ d ] = c;

	return true;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, m;
	vector<ari> aristas;
	cin >> n >> m;

	while( n || m )
	{
		long long sum = 0;

		aristas.resize( m );
		for (int i = 0; i < n; ++i)
			padre[ i ] = i;

		for (int i = 0; i < m; ++i)
		{
			cin >> aristas[ i ].a >> aristas[ i ].b >> aristas[ i ].c;
			sum += aristas[ i ].c;
		}

		sort( aristas.begin(), aristas.end() );

		int len = 0, it = 0;
		long long MST = 0;

		while( len < n-1 )
		{
			if ( union_find(aristas[ it ].a, aristas[ it ].b ) )
			{
				MST += aristas[ it ].c;
				++len;
			}

			++it;
		}
		cout << sum - MST << '\n';

		cin >> n >> m;
	}
}