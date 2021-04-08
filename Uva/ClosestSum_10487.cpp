#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int arr[ maxn ];

inline int dif( int a, int b )
{
	return abs( a-b );
}

int main()
{
	int n, m, it = 0, aux, ans;

	cin >> n;
	while( n )
	{
		cout << "Case " << ++it << ":\n";
		for( int i = 0; i < n; ++i )
			cin >> arr[ i ];

		cin >> m;
		for( int k = 0; k < m; ++k)
		{
			cin >> aux;
			ans = 99999999;
			for( int i = 0; i < n; ++i )
				for( int j = i+1; j < n; ++j )
					if( dif( aux, arr[ i ]+arr[ j ] ) <= dif( aux, ans ) )
						ans = arr[ i ] + arr[ j ];

			cout << "Closest sum to " << aux << " is " << ans << ".\n";
		}

		cin >> n;
	}
	return 0;
}
