#include <bits/stdc++.h>
#define maxn 105
#define inf 999999999

using namespace std;
typedef double db;

int floyd[ maxn ][ maxn ];

int main()
{	
	set <int> dic;
	int a, b, it = 0;

	scanf("%d %d", &a, &b );
	while( a || b )
	{
		dic.clear();
		for( int i = 0; i < maxn; ++i )
			for( int j = 0; j < maxn; ++j )
				if( i == j )
					floyd[ i ][ j ] = 0;
				else
					floyd[ i ][ j ] = inf;
		
		while( a || b )
		{
			dic.insert( a );
			dic.insert( b );

			floyd[ a ][ b ] = 1;
			scanf("%d %d", &a, &b );
		}

		for( int k = 0; k < maxn; ++k )
			for( int i = 0; i < maxn; ++i )
				for( int j = 0; j < maxn; ++j )
					floyd[ i ][ j ] = min( floyd[ i ][ j ], floyd[ i ][ k ] + floyd[ k ][ j ] );
		
		int sum = 0;
		for( int i = 0; i < maxn; ++i )
			for( int j = 0; j < maxn; ++j )
				if( floyd[ i ][ j ] < inf )
					sum += floyd[ i ][ j ];

		printf("Case %d: average length between pages = %.3lf clicks\n", ++it, (db)sum / (db)(dic.size()*(dic.size()-1)) );
		scanf("%d %d", &a, &b );
	}
	return 0;
}
