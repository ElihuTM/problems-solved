#include <bits/stdc++.h>
#define maxn 3003
#define lim 10000000

using namespace std;
typedef long long ll;

ll g[ lim ];
int mat[ maxn ][ maxn ];

int main()
{
	int n, m, a, b, x, y, z;
	cin >> n >> m >> a >> b;
	cin >> g[ 0 ] >> x >> y >> z;

	for( int i=1; i < lim; ++i )
		g[ i ] = (g[ i-1 ] * x + y) % z;
	
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++ j )
			mat[ i-1 ][ j-1 ] = g[ (i-1)*m+j-1 ];
	
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < m; ++ j )
			cout << mat[ i ][ j ] << " ";
		cout << endl;
	}
	return 0;
}
