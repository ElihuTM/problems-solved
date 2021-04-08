#include <bits/stdc++.h>
#define maxn 100000004
#define inf 1e9

using namespace std;
typedef long long ll;

int x, c, e;
int memo[ maxn ];

int dp( int n )
{
	if( n == 0 ) return 0;
	if( n < 0 ) return inf;
	if( ~memo[ n ] ) return memo[ n ];

	return memo[ n ] = min( n, min( dp(n-c), dp(n-e)) );
}

int main()
{
	memset( memo, -1, sizeof memo );
	cin >> x >> c >> e;
	e*= 5;
	
	cout << dp(x) << '\n';
	return 0;
}
