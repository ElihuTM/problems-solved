#include <bits/stdc++.h>
#define maxn 30
#define inf 999999999
#define forn(i) for( int i = 0; i < 30 ; ++i )

using namespace std;

int you[ maxn ][ maxn ];
int old[ maxn ][ maxn ];

int main()
{
	int n, c;
	char t, d, x, y;

	cin >> n;
	while( n )
	{
		forn(i)
			forn(j)
				if( i == j )
				{
					you[ i ][ j ] = 0;
					old[ i ][ j ] = 0;
				}
				else
				{
					you[ i ][ j ] = inf;
					old[ i ][ j ] = inf;
				}
		
		while( n-- )
		{
			cin >> t >> d >> x >> y >> c; 
			if( x == y ) continue;

			if( t == 'Y' )
			{
				you[ x-'A' ][ y-'A' ] = c;

				if( d == 'B' )
					you[ y-'A' ][ x-'A' ] = c;
			}
			else
			{
				old[ x-'A' ][ y-'A' ] = c;

				if( d == 'B' )
					old[ y-'A' ][ x-'A' ] = c;
			}
		}

		forn(k)
			forn(i)
				forn(j)
				{
					you[ i ][ j ] = min( you[ i ][ j ], you[ i ][ k ] + you[ k ][ j ] );
					old[ i ][ j ] = min( old[ i ][ j ], old[ i ][ k ] + old[ k ][ j ] );
				}

		cin >> x >> y;
		
		int ans = inf;
		forn(i)
			ans = min( ans, you[ x-'A' ][ i ] + old[ y-'A'][ i ] );
		
		if( ans < inf )
		{
			cout << ans;
			forn(i)
				if( you[ x-'A' ][ i ] + old[ y-'A' ][ i ] == ans )
					printf(" %c", i+'A' );
		}
		else
			cout << "You will never meet.";
		cout << '\n';

		cin >> n;
	}
	return 0;
}
