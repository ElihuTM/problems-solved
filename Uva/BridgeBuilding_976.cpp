#include <bits/stdc++.h>
#define maxn 1005
#define maxi(a,b) (a==-1?b:max(a,b)) 
#define mini(a,b) (a==-1?b:min(a,b))
#define m_p(a,b) make_pair(a,b)
#define ff first
#define ss second

using namespace std;
typedef pair< int, int> pii;

int n, m, bridges, space;
int top[ maxn ];
int bottom[ maxn ];
int memo[ maxn ][ 101 ];
int mx[] = { 0, -1, 0, 1};
int my[] = { 1 ,0, -1, 0};
bool visit[ maxn ][ maxn ];
string mat[ maxn ];

bool is_pos( int x, int y )
{
	if( x < 0 || x >= n )
		return false;
	
	if( y < 0 || y >= m )
		return false;
	
	if( visit[ x ][ y ] || mat[ x ][ y ] != '#' )
		return false;
	
	return true;
}

void bfs( pii nodo, bool is_top )
{
	queue< pii > q;
	q.push( nodo );

	while( !q.empty() )
	{
		pii fron = q.front(); q.pop();

		for( int i = 0; i < 4; ++i )
		{
			pii aux( fron.ff + mx[ i ], fron.ss + my[ i ] ); 
			if( is_pos( aux.ff, aux.ss ) )
			{
				if( is_top )
					top[ aux.ss ] = maxi(top[ aux.ss ], aux.ff);
				else
					bottom[ aux.ss ] = mini(bottom[ aux.ss ], aux.ff);

				visit[ aux.ff ][ aux.ss ] = true;
				q.push( aux );
			}
		}
	}
}

int dp( int pos, int bri )
{
	if( bri == 0 )
		return 0;

	if( pos >= m )
		return bri ? 99999999 : 0 ;
	
	if( ~memo[ pos ][ bri ] )
		return memo[ pos ][ bri ];
	
	int dif = bottom[ pos ] - top[ pos ] - 1;
	return memo[ pos ][ bri ] = min( dp( pos+1, bri ), dif + dp( pos+space+1, bri-1 ) ) ;
}

int main()
{
	while( cin >> n >> m )
	{
		cin >> bridges >> space;
		
		memset( memo, -1, sizeof memo );
		memset( top, -1, sizeof top );
		memset( bottom, -1, sizeof bottom );
		memset( visit, 0, sizeof visit );

		for( int i = 0; i < n; ++i )
			cin >> mat[ i ];

		bfs( m_p(0,0), 1 );
		bfs( m_p(n-1,0), 0 );
		
		cout << dp( 0, bridges ) << '\n';
	}
	return 0;
}
