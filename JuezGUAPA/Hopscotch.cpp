#include <bits/stdc++.h>
#define x first
#define y second
#define maxn 50
#define inf 99999999

using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector< vpii > vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int manhatan( pii a, pii b )
{
	return abs( a.x - b.x ) + abs( a.y - b.y );
}

int main()
{
	int n, k, x;

	cin >> n >> k;
	
	vvpii lista( k );
	vvi ans( k );

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> x; --x;
			lista[ x ].emplace_back( i, j );
			ans[ x ].push_back( 0 );
		}

	for (int i = 0; i < k; ++i)
		if ( lista[ i ].empty() )
		{
			cout << "-1\n";
			return 0;
		}

	for (int i = k-2; i >= 0; --i)
	{
		for (int j = 0; j < lista[ i ].size(); ++j)
		{	
			ans[ i ][ j ] = inf;
			for (int l = 0; l < lista[ i+1 ].size(); ++l)
				ans[ i ][ j ] = min( ans[ i ][ j ], ans[ i+1 ][ l ] + manhatan( lista[ i ][ j ], lista[ i+1 ][ l ] ) );
		}
	}

	int res = inf;
	for (int i = 0; i < ans[ 0 ].size(); ++i)
		res = min( res, ans[ 0 ][ i ] );

	cout << res << '\n';
	return 0;
}

//O(N^4)
/*
	1: A_(1,1)15, A_(1,2)23, A_(1,3)45
	2: A_(2,1)15 , A_(2,2)8
	3: A_(3,1)0 , A_(3,2)0, A_(3,3)0, A_(3,4)0, A_(3.5)0
*/
