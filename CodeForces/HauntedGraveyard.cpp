#include <bits/stdc++.h>
#define x first
#define y second
#define inf 1000000007
#define maxn 35
#define md(x) (((x%mod) + mod) % mod)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

struct hole
{
	int x, y;
	ll value;

	hole ( ) : x( -1 ), y( -1 ), value( 0 ) { }
	hole ( int a, int b, ll c ) : x( a ), y( b ), value( c ) { } 
};

bool is_gravestone[ maxn ][ maxn ];
hole holes[ maxn ][ maxn ];
ll dist [ maxn ][ maxn ];
int n, m;

int mvx[ ] = {1, -1, 0};
int mvy[ ] = {0, -1, 1};

bool is_possible( int x, int y ){
	if( x < 0 or x >= n ) return false;
	if( y < 0 or y >= m ) return false;
	if( is_gravestone[ x ][ y ] ) return false;

	return true;
}

bool bellman_ford( pii root ) {

	dist[ root.x ][ root.y ] = 0;
	for (int i = 0; i < n; ++i)	{
		for (int j = 0; j < m; ++j) {
			for (int x = 0; x < n; ++x)	{
				for (int y = 0; y < m; ++y) {
					if( is_gravestone[ x ][ y ] ) continue;

					if( holes[ x ][ y ].x != -1 ) {
						int xx = holes[ x ][ y ].x;
						int yy = holes[ x ][ y ].y;
						ll value = holes[ x ][ y ].value;

						if( dist[ x ][ y ] < inf )
							dist[ xx ][ yy ] = min( dist[ xx ][ yy ], dist[ x ][ y ] + value );
					}
					else {
						for (int i = 0; i < 3; ++i) {
							int xx = x + mvx[ i ];
							int yy = y + mvy[ i ];

							if ( is_possible( xx, yy ) and dist[ x ][ y ] < inf )
								dist[ xx ][ yy ] = min( dist[ xx ][ yy ], dist[ x ][ y ] + 1);
						}	
					}
					
				}
			}
		}
	}

	for (int x = 0; x < n; ++x){
		for (int y = 0; y < m; ++y) {
			if( is_gravestone[ x ][ y ] ) continue;

			if( holes[ x ][ y ].x != -1 ) {
				int xx = holes[ x ][ y ].x;
				int yy = holes[ x ][ y ].y;
				ll value = holes[ x ][ y ].value;

				if ( dist[ x ][ y ] < inf and dist[ xx ][ yy ] > dist[ x ][ y ] + value )
					return false;
			}
			else {
				for (int i = 0; i < 3; ++i) {
					int xx = x + mvx[ i ];
					int yy = y + mvy[ i ];

					if ( is_possible( xx, yy ) and dist[ x ][ y ] < inf and dist[ xx ][ yy ] > dist[ x ][ y ] + 1 )
						return false;
				}	
			}
		}
	}

	return true;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int g, e, x, y, x2, y2, value;
	cin >> n >> m;

	while( n && m ) {
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				is_gravestone[ i ][ j ] = false;
				holes[ i ][ j ] = hole( );
				dist[ i ][ j ] = inf;
			}
		}

		cin >> g;
		while ( g-- ) {
			cin >> x >> y;
			is_gravestone[ x ][ y ] = true;
		}

		cin >> e;
		while ( e-- ) {
			cin >> x >> y >> x2 >> y2 >> value;
			holes[ x ][ y ] = hole( x2, y2, value );
		}

		bool finished = bellman_ford( pii( 0, 0 ) );
		
		/*
		cout << "-----------------" << endl;
		cout << n << " " << m << endl;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << dist[ i ][ j ] << " ";
			}
			cout << endl;
		}

		cout << "-----------------" << endl;
		*/

		if ( !finished )
			cout << "Never" << endl;
		else if( dist[ n-1 ][ m-1 ] < inf )
			cout << dist[ n-1 ][ m-1 ] << endl;
		else
			cout << "Impossible" << endl;

		cin >> n >> m;
	}
	return 0;
}