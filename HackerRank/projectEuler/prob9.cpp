#include <bits/stdc++.h>
#define maxi(a,b) (a>b?a:b)

using namespace std;

int main()
{
	int t, n, ans;
	
	cin >> t;
	while( t-- )
	{
		cin >> n;
		if( n == 1 )
			cout << "-1\n";
		else
		{
			ans = -1;
			for( int a = 1; a <= n/3+1; ++a )
			{
				double b = (double)(n*n - 2*n*a) / (double)(2*(n-a));
				if( floor( b ) == b )
				{
					int c = n - a - b;
					if( a*a + b*b == c*c && a < b && b < c )
						ans = maxi( ans, a*b*c );
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
