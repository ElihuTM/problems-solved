#include <bits/stdc++.h>
#define maxn 1003
#define ff first
#define ss second

using namespace std;
typedef pair <int,int> pii;

bitset <maxn> bomb[ maxn ];
int mvx[ ] = { 0, -1, 0, 1};
int mvy[ ] = { 1, 0, -1, 0};
int dist[ maxn ][ maxn ]; 
int n,m;

inline bool is_pos( int x, int y )
{
	if ( x < 0 || x >= n )
		return false;

	if ( y < 0 || y >= m)
		return false;

	if ( ~dist[ x ][ y ] )
		return false;
	
	if ( bomb[ x ][ y ] )
		return false;
	
	return true;
}

void bfs( int x, int y )
{
	queue< pii > q;
	memset( dist, -1, sizeof dist);
	dist[ x ][ y ] = 0; q.push( pii(x,y) );

	while( !q.empty() )
	{
		int x = q.front().ff, y = q.front().ss; q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int xx = x + mvx[ i ];
			int yy = y + mvy[ i ];

			if ( is_pos(xx,yy) )
			{
				dist[ xx ][ yy ] = dist[ x ][ y ] + 1;
				q.push( pii(xx,yy) );
			}
		}
	}
}

int main()
{
	int r, row, cant, col;

	cin >> n >> m;
	while( n || m )
	{
		for (int i = 0; i < n; ++i)
			bomb[ i ].reset();

		cin >> r;
		while( r-- )
		{
			cin >> row >> cant;
			for (int i = 0; i < cant; ++i)
			{
				cin >> col;
				bomb[ row ][ col ] = true;
			}
		}
		cin  >> row >> col;
		bfs( row, col );

		cin >> row >> col;
		cout << dist[ row ][ col ] << '\n';

		cin >> n >> m;
	}
	return 0;
}