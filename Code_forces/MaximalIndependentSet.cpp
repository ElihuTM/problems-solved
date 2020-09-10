#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > lista;
vector <int> color;
int n, m, ans;

void bfs( int u )
{
	queue <int> q;
	q.push( u );

	while( !q.empty( ) )
	{
		u = q.front(); q.pop();
		if( color[ u ] == 1 ) continue;
		
		color[ u ] = 1;
		for( int i=0; i<lista[ u ].size(); ++i )
		{
			int v = lista[ u ][ i ];
			if( color[ v ] == 1 )
				color[ u ] = 0;
			else if( color [ v ] == -1 )
				q.push( v );
		}
	}
}

int main()
{
	int a, b;
	cin >> n >> m;
	
	lista.assign( n, vector <int>() );
	color.assign( n, -1 );
	for( int i=0; i<m; ++i )
	{
		cin >> a >> b; a--; b--;
		lista[ a ].push_back( b );
		lista[ b ].push_back( a );
	}


	for( int i=0; i<n; ++i )
		if( color[ i ] == -1 )
			bfs( i );
	ans = 0;
	for( int i=0; i<n; ++i )
		if( color[ i ] == 1 )
			++ans;

	cout << ans << '\n';
	for( int i=0; i<n; ++i )
	{
		cout << color[ i ];
		if( i<n-1 )
			cout << ' ';
		else
			cout << '\n';
	}
	return 0;
}
