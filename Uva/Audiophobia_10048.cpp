#include <bits/stdc++.h>
#define maxn 105
#define ff first
#define ss second
#define m_p(a,b) make_pair(a,b)

using namespace std;
typedef pair <int,int> pii;

struct st
{
	int a, b, c;
	bool operator < ( const st &p ) const {
		return c < p.c;
	}
};

st ari[ 1005 ];
int dist[ maxn ];
int padre[ maxn ];
vector < pii > lista[ maxn ];

int padrote( int n ) {
	return padre[ n ] == n ? n : padre[ n ] = padrote( padre[ n ] );
}

bool union_find( int a, int b ) {
	int c = padrote( a );
	int d = padrote( b );

	if( c == d ) return false;

	if( rand()&1 )
		padre[ c ] = d;
	else
		padre[ d ] = c;

	return true;
}

void limpia()
{
	for( int i = 0; i < maxn; ++i )
	{
		padre[ i ] = i;
		lista[ i ].clear();
	}
}

int dfs( int a, int b )
{
	memset( dist, -1, sizeof dist );
	queue < int > q;

	dist[ a ] = 0;
	q.push( a );

	while( !q.empty() )
	{
		int u = q.front(); q.pop();

		for( int i = 0; i < lista[ u ].size(); ++i )
		{
			int v = lista[ u ][ i ].ff, d = lista[ u ][ i ].ss; 

			if( dist[ v ] == -1 )
			{
				dist[ v ] = max( dist[ u ], d );
				q.push( v );
			}
		}
	}

	return dist[ b ];
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int c, s, q, a, b, ans, it = 1;
	
	cin >> c >> s >> q;
	while( c || s || q )
	{
		limpia();

		for( int i = 0; i < s; ++i )
			cin >> ari[ i ].a >> ari[ i ].b >> ari[ i ].c;

		sort( ari, ari + s );
		
		for( int i = 0; i < s; ++i )
			if( union_find( ari[ i ].a, ari[ i ].b ) )
			{
				lista[ ari[ i ].a ].push_back( m_p( ari[ i ].b, ari[ i ].c ) );
				lista[ ari[ i ].b ].push_back( m_p( ari[ i ].a, ari[ i ].c ) );
			}
		
		cout << "Case #" << it++ << '\n';
		for( int i = 0; i < q; ++i )
		{
			cin >> a >> b;
			//ans = -1;
			ans = dfs(a,b);
			if( ans == -1 )
				cout << "no path\n";
			else
				cout << ans << '\n';
		}
		cin >> c >> s >> q;

		if( c || s || q )
			cout << '\n';
	}
	return 0;
}
