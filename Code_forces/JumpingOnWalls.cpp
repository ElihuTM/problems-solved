#include <bits/stdc++.h>
#define ff first
#define ss second
#define m_p(a,b) make_pair(a,b)
#define maxn 200005

using namespace std;
typedef pair <int,int> pii;

bitset< maxn > wall[ 2 ];
int dist[ 2 ][ maxn ];
int n, k;

inline bool is_pos( int w, int d ) {
	if( d < 0 || wall[ w ][ d ] ) return false;
	return true;
}

inline bool conv ( int w1, int d1, int w2, int d2 )
{
	if( dist[ w2 ][ d2 ] == -1 && dist[ w1 ][ d1 ] + 1 <= d2 )
		return true;

	if( dist[ w2 ][ d2 ] != -1 && dist[ w1 ][ d1 ] + 1 < dist[ w2 ][ d2 ] )
		return true;

	return false;
}

bool bfs( int w, int d )
{
	memset( dist, -1, sizeof dist );
	queue < pii > q;
	
	dist[ w ][ d ] = 0;
	q.push( m_p(w,d) );

	while( !q.empty() )
	{
		w = q.front().ff; d = q.front().ss; q.pop();
		
		if( d >= n ) return true;

		if( is_pos( 1-w, d+k ) && conv( w, d, 1-w, d+k )
		{
			dist[ 1-w ][ d+k ] = dist[ w ][ d ] + 1;
			q.push( m_p(1-w,d+k) );
		}

		if( is_pos( w, d+1 ) && conv( w, d, w, d+1 ) )
		{
			dist[ w ][ d+1 ] = dist[ w ][ d ] + 1;
			q.push( m_p(w,d+1) );
		}

		if( is_pos( w, d-1 ) &&  conv( w, d, w, d-1 ) )
		{
			dist[ w ][ d-1 ] = dist[ w ][ d ] + 1;
			q.push( m_p(w,d-1) );
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	char a;
	wall[ 0 ].reset();
	wall[ 1 ].reset();

	cin >> n >> k;
	for( int i = 0; i < 2; ++i )
		for( int j = 0; j < n; ++j )
		{
			cin >> a;
			if( a == '-' )
				wall[ i ][ j ] = 0;
			else
				wall[ i ][ j ] = 1;
		}
	
	if( bfs( 0, 0 ) )
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
