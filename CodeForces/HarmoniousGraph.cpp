#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

int padre[ maxn ];
int mayor[ maxn ];

int padrote( int n ) {
	return n == padre[ n ] ? n : padre[ n ] = padrote( padre[ n ] );
}

bool union_find( int a, int b )
{
	a = padrote( a );
	b = padrote( b );

	if ( a == b ) return false;

	if ( rand()&1 )
	{
		padre[ b ] = a;
		mayor[ a ] = max( mayor[ a ], mayor[ b ] ); 
	}
	else
	{
		padre[ a ] = b;
		mayor[ b ] = max( mayor[ a ], mayor[ b ] ); 
	}

	return true;
}

int main()
{
	int n, m, a, b;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		padre[ i ] = mayor[ i ] = i;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		union_find( a-1, b-1 );
	}

	for (int i = 0; i < n; ++i)
		padre[ i ] = padrote( i );

	int pos = 0;
	long long ans = 0;
	while( pos < n )
	{
		int may = mayor[ padre[ pos ] ];
		int may2 = may;
		
		set<int> dif;
		while( pos <= may2 )
		{
			may2 = max( may2, mayor[ padre[ pos ] ] );

			dif.insert( padre[ pos ] );
			++pos;
		}
		ans += dif.size()-1;
	}
	cout << ans << '\n';
	return 0;	
}