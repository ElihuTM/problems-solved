#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef pair<int,int> pii;

int n, m, l, u, r, d;

map <pii,ld> memo;

ld dp( int x, int y )
{
	if ( x >= l && x <= r && y >= u && y <= d )
		return 0.0;

	if ( x > r || y > d )
		return 1.0;

	pii coord( x, y );
	if ( memo.find( coord ) != memo.end() )
		return memo[ coord ];

	ld ans = 0;
	int div = 0;

	if ( x < n )
	{
		ans += dp( x+1, y );
		++div;
	}

	if ( y < m )
	{
		ans += dp( x, y+1 );
		++div;
	}

	return memo[ coord ] = (ans / div);
}

int main()
{
	int t;

	scanf("%d",&t);
	for (int c = 1; c <= t; ++c)
	{
		scanf("%d%d%d%d%d%d",&n, &m, &l, &u, &r, &d );

		memo.clear();
		
		for (int x = 1; x <= n; ++x)
		{
			for (int y = 1; y <= m; ++y)
				if ( x >= l && x <= r && y >= u && y <= d )
					printf("xxxxxx ");
				else
					printf("%.4llf ", dp(x,y) );

			printf("\n");
		}

		printf("Case #%d: %.7llf\n", c, dp( 1, 1 ) );
	}

	return 0;
}