#include <bits/stdc++.h>
#define endl '\n'
#define forn(i,n) for( int i = 0; i < n; ++i )
#define maxn 103
#define inf 999999999

using namespace std;

int floyd[ maxn ][ maxn ];

int main()
{
	int t, n, m, a, b;
	cin >> t;

	forn(qw,t)
	{
		cin >> n >> m;
		forn(i,n)
			forn(j,n)
				if( i == j )
					floyd[ i ][ j ] = 0;
				else
					floyd[ i ][ j ] = inf;

		forn(i,m)
		{
			cin >> a >> b;
			if( a != b )
			{
				floyd[ a ][ b ] = 1;
				floyd[ b ][ a ] = 1;
			}
		}

		forn(k,n)
			forn(i,n)
				forn(j,n)
					floyd[ i ][ j ] = min( floyd[ i ][ j ], floyd[ i ][ k ] + floyd[ k ][ j ] );

		cin >> a >> b;
		int ans = 0;
		forn(i,n)
			ans = max( ans, floyd[ a ][ i ]+floyd[ i ][ b ] );

		cout << "Case " << qw+1 << ": " << ans << endl;
	}
	return 0;
}
