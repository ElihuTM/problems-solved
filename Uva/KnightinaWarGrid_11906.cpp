#include <bits/stdc++.h>
#define maxn 103
#define inf -12
#define ff first
#define ss second
#define m_p(a,b) make_pair(a,b)

using namespace std;
typedef pair <int,int> pii;
typedef set <pii> spii;

int n, m, a, b;
int mat[ maxn ][ maxn ];

spii find_ways( int x, int y )
{
	spii ans;
	ans.insert( m_p(x+a,y+b) );
	ans.insert( m_p(x+a,y-b) );
	ans.insert( m_p(x-a,y+b) );
	ans.insert( m_p(x-a,y-b) );
	ans.insert( m_p(x+b,y+a) );
	ans.insert( m_p(x+b,y-a) );
	ans.insert( m_p(x-b,y+a) );
	ans.insert( m_p(x-b,y-a) );

	return ans;
}

bool is_pos( int x, int y )
{
	if( x < 0 || x >= n ) return false;

	if( y < 0 || y >= m ) return false;

	return mat[ x ][ y ] != inf;
}

void bfs( int x, int y )
{
	spii dic;
	queue< pii > q;
	q.push( m_p(x,y) );

	while( !q.empty() )
	{
		pii front = q.front(); q.pop();

		if( mat[ front.ff ][ front.ss ] != -1 ) continue;
		dic = find_ways( front.ff, front.ss );

		int cont = 0;
		for( auto c: dic )
			if( is_pos( c.ff, c.ss ) )
			{
				++cont;
				if( mat[ c.ff ][ c.ss ] == -1 )
					q.push( c );
			}
		mat[ front.ff ][ front.ss ] = cont;
	}
}

int main()
{
	int t, q, x, y;
	cin >> t;

	for( int it = 1; it <= t; ++it )
	{
		memset( mat, -1, sizeof mat );

		cin >> n >> m >> a >> b;
		cin >> q;
		for( int i = 0; i < q; ++i )
		{
			cin >> x >> y;
			mat[ x ][ y ] = inf;
		}
		
		bfs( 0, 0 );
		int par = 0, impar = 0;

		for( int i = 0; i < n; ++i )
			for( int j = 0; j < m; ++j )
				if( mat[ i ][ j ] >= 0 )
				{
					if( mat[ i ][ j ]&1 )
						++impar;
					else
						++par;
				}
		
		cout << "Case " << it << ": " << par << " " << impar << '\n';
	}
	return 0;
}
