#include <bits/stdc++.h>
#define maxn 103

using namespace std;

int mon[ maxn ];
int eve[ maxn ];

int main()
{
	int n, d, r;
	while( 1  )
	{
		cin >> n >> d >> r;

		if( !n && !d && !r )
			break;

		for( int i = 0; i < n; ++i )
			cin >> mon[ i ];

		for( int i = 0; i < n; ++i )
			cin >> eve[ i ];

		sort( mon, mon + n );
		sort( eve, eve + n );

		long long ans = 0;
		for( int i = 0; i < n; ++i )
			if( mon[ i ] + eve[ n-i-1 ] > d )
				ans += (mon[ i ] + eve[ n-i-1 ] - d ) * r;

		cout << ans << '\n';
	}
	return 0;
}
