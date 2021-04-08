#include <bits/stdc++.h>
#define maxn 20005	

using namespace std;

long long heads[ maxn ];
long long knights[ maxn ];

int main()
{
	int n, m;
	while( 1 )
	{
		cin >> n >> m;

		if( !n && !m )
			break;

		for (int i = 0; i < n; ++i)
			cin >> heads[ i ];

		for (int i = 0; i < m; ++i)
			cin >> knights[ i ];

		sort( heads, heads + n );
		sort( knights, knights + m );

		int i, cont = 0, pos = 0;
		long long ans = 0;

		for ( i = 0; i < n; ++i)
		{
			while( pos < m && knights[ pos ] < heads[ i ] ) ++pos;

			if( pos == m )
				break;

			++cont;
			ans += knights[ pos++ ];
		}

		if( cont != n )
			cout << "Loowater is doomed!\n";
		else
			cout << ans << '\n';
	}
	return 0;
}