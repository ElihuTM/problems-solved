#include <bits/stdc++.h>
#define maxn 2005
#define ab(x) (x>=0?x:0)

using namespace std;

int memo[ maxn ][ maxn ];
int maxi[ maxn ];

int main()
{
	int cases, t, h, f, a, pos;
	cin >> cases;

	while( cases-- )
	{
		cin >> t >> h >> f;
		memset( memo, 0, sizeof memo );
		memset( maxi, 0, sizeof maxi );

		for( int i = 0; i < t; ++i )
		{
			cin >> a;
			for( int j = 0; j < a; ++j )
			{
				cin >> pos;
				++memo[ pos ][ i ];
			}
		}

		for( int i = 0; i <= h; ++i )
		{	
			int aux = 0; 
			for( int j = 0; j < t; ++j )
			{
				memo[ i ][ j ] += max( memo[ ab(i-1) ][ j ], maxi[ ab(i-f) ] );
				if( memo[ i ][ j ] > aux )
					aux = memo[ i ][ j ];
			}
			maxi[ i ] = aux;
		}

		cout << maxi[ h ] << '\n';
	}

	cin >> t;
	return 0;
}
