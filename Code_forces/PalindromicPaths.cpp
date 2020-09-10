#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100
#define mod(x) (((x%md) + md) % md)
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

bool mat[ maxn ][ maxn ];
int dist[ maxn ][ maxn ];
int ans[ maxn ][ 2 ];
int muvx[ ] = {0,1};
int muvy[ ] = {1,0};
ll n,m;

bool is_pos( int x, int y )
{
	if ( x < 0 || x >= n )
		return false;

	if ( y < 0 || y >= m )
		return false;

	if ( dist[ x ][ y ] != -1 )
		return false;

	return true;
}

void bfs( int x, int y )
{
	queue<pii> q;
	memset( dist, -1, sizeof(dist) );
	memset( ans, 0, sizeof(ans) );

	dist[ 0 ][ 0 ] = 0;
	ans[ 0 ][ mat[ 0 ][ 0 ] ]++;

	q.push( pii(0,0) );
	while( !q.empty() )
	{
		x = q.front().ff;
		y = q.front().ss;
		q.pop();

		for (int i = 0; i < 2; ++i)
		{
			int xx = x + muvx[ i ];
			int yy = y + muvy[ i ];

			if ( is_pos(xx,yy) )
			{
				dist[ xx ][ yy ] = dist[ x ][ y ] + 1;
				ans[ dist[ xx ][ yy ] ][ mat[ xx ][ yy ] ]++;
				q.push( pii(xx,yy) );
			}
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t;
	cin >> t;
	while( t-- )
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> mat[ i ][ j ];

		bfs( 0, 0 );

		ll ansi = 0;
		ll l = 0, r = n+m-2;

		while( l < r )
		{
			ansi += min( ans[ l ][ 0 ] + ans[ r ][ 0 ], ans[ l ][ 1 ] + ans[ r ][ 1 ]);
			++l;
			--r;
		}

		cout << ansi << endl;
	}

	return 0;
}
