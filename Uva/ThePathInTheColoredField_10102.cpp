#include <bits/stdc++.h>
#define m_p(a,b) make_pair(a,b)
#define ff first
#define ss second

using namespace std;
typedef vector < vector <int> > vvi;
typedef pair <int, int> pii;

vector< string >arr;
int mvx[] = { 0, 0, 1, -1 };
int mvy[] = { 1, -1, 0, 0 };
int n;

inline bool is_pos( int x, int y )
{
	if( x < 0 || x >= n )
		return false;
	
	if( y < 0 || y >= n )
		return false;

	return true;
}

int bfs( int x, int y )
{
	vvi dist( n );
	for( int i = 0; i < n; ++i )
		dist[ i ].resize( n , -1 );
	dist[ x ][ y ] = 0;
	
	queue < pii > q;
	q.push( m_p(x,y) );

	while( !q.empty() )
	{
		pii front = q.front(); q.pop();
		for( int i = 0; i < 4; ++i )
		{
			x = front.ff + mvx[ i ];
			y = front.ss + mvy[ i ]; 

			if( is_pos( x, y ) && dist[ x ][ y ] == -1 )
			{
				dist[ x ][ y ] = dist[ front.ff ][ front.ss ] + 1;

				if( arr[ x ][ y ] == '3' )
					return dist[ x ][ y ];
				else
					q.push( m_p(x,y) );
			}
		}
	}

	return 0;
}

int main()
{
	int ans, aux;

	while( cin >> n )
	{
		arr.resize( n );
		for( int i = 0; i < n; ++i )
			cin >> arr[ i ];

		ans = 0;
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < n; ++j )
				if( arr[ i ][ j ] == '1' )
				{
					aux = bfs( i, j );
					if( aux > ans )
						ans = aux;
				}
		cout << ans << '\n';
	}
	return 0;
}
