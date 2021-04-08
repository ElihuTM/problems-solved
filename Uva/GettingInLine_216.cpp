#include <bits/stdc++.h>
#define ff first
#define ss second
#define maxn 8

using namespace std;
typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long double db;

pii coord[ maxn ];
db dist[ maxn ][ maxn ];
vi path;

inline db dt( pii a, pii b )
{
	return sqrt( (db)(a.ff-b.ff)*(a.ff-b.ff) + (db)(a.ss-b.ss)*(a.ss-b.ss) );
}

int main()
{
	int n;

	scanf("%d",&n);
	while( n )
	{
		path = vi( n );
		for( int i = 0; i < n; ++i )
			path[ i ] = i;

		for( int i = 0; i < n; ++i )
			scanf( "%d %d", &coord[ i ].ff, &coord[ i ].ss);
		
		for( int i=0; i < n; ++i )
			for( int j = 0; j < n; ++j )
			{
				dist[ i ][ j ] = dt( coord[ i ], coord[ j ] );
			}
		db ans = 999999;
		vi cam;
		do
		{
			db aux = 0;
			for( int i = 1; i < n; ++i )
				aux += dist[ path[ i-1 ] ][ path[ i ] ];

			if( aux < ans )
			{
				ans = aux;
				cam = path;
			}
		}while( next_permutation( path.begin(), path.end() ) );
		
		for( int i = 1; i < n; ++i )
		{
			int x1 = coord[ cam[ i-1 ] ].ff;
			int y1 = coord[ cam[ i-1 ] ].ss;
			int x2 = coord[ cam[ i ] ].ff;
			int y2 = coord[ cam[ i ] ].ss;
			db d = dt(coord[ cam[ i-1 ] ], coord[ cam[ i ] ] );
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %llf feet.\n", x1, y1, x2, y2, d);
		}
		printf("\n%llf\n", ans );

		scanf("%d",&n);
	}
}
